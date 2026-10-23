"""Lossless cold retention for closed fixup sessions; no age-only deletion.

Hot per closed session: the report's per-symbol best rows (scored C), every
matched/link-rejected candidate's object chunk (link evidence), and the files
other session metadata references (diagnostics, compile logs of hot chunks).
Historical scored candidates — the bulk of every search session — move into
byte-verified cold bundles before their original files are removed; --restore
brings one member or a whole session back (their content-addressed identities
regenerate from body text when an Engine run replays them). Reports/cache/captures
are never rewritten. Stable external flock leases exclude active Engine writers
and collectors. Incomplete or malformed metadata is a hard skip. --dry-run is
the default; --apply is explicit.
"""
from __future__ import annotations
import argparse
import contextlib
import fcntl
import hashlib
import io
import json
import os
from pathlib import Path, PurePosixPath
import re
import tarfile
import time
from typing import Any, Iterator

STATE_DIR = Path(os.environ.get('FZGX_STATE', Path(__file__).resolve().parents[2]/'.fzgx'))
HEX = re.compile(r'^[0-9a-f]{24}$')

def acquire(session: Path, blocking: bool = True) -> int | None:
    session = session.resolve()
    locks = session.parent/'.fixup-leases'
    locks.mkdir(parents=True, exist_ok=True)
    if locks.is_symlink():
        raise ValueError('symlink lease directory')
    path = locks/(hashlib.sha256(str(session).encode()).hexdigest()+'.lock')
    fd = os.open(path, os.O_CREAT|os.O_RDWR|os.O_CLOEXEC, 0o600)
    try:
        fcntl.flock(fd, fcntl.LOCK_EX|(0 if blocking else fcntl.LOCK_NB))
    except BlockingIOError:
        os.close(fd)
        return None
    return fd

def release(fd):
    if fd is not None:
        # Closing, rather than explicit LOCK_UN, preserves leases inherited by live compiler children.
        os.close(fd)

def headroom(path) -> dict[str, Any]:
    d=os.statvfs(path)
    return dict(free_bytes=d.f_bavail*d.f_frsize, free_inodes=d.f_favail,
                used_inode_percent=round(100*(1-d.f_favail/d.f_files),2) if d.f_files else None,
                used_block_percent=round(100*(1-d.f_bavail/d.f_blocks),2) if d.f_blocks else None)

def guard(path):
    h=headroom(path)
    if h['free_bytes']<8<<30 or h['free_inodes']<100000:
        raise RuntimeError('Fixup disk/inode reserve exhausted; refuse new generation')

def digest(path):
    h=hashlib.sha256()
    with path.open('rb') as f:
        for b in iter(lambda:f.read(1<<20),b''):h.update(b)
    return h.hexdigest()

def cookie(path):
    s=path.stat(follow_symlinks=False)
    return [s.st_dev,s.st_ino,s.st_size,s.st_mtime_ns]

def _references(data) -> Iterator[str]:
    if isinstance(data,dict):
        for v in data.values():yield from _references(v)
    elif isinstance(data,list):
        for v in data:yield from _references(v)
    elif isinstance(data,str):yield data

def _has_candidate(session: Path) -> bool:
    sources = session / 'sources'
    if sources.is_dir() and not sources.is_symlink():
        c_count = 0
        try:
            with os.scandir(sources) as es:
                for e in es:
                    if e.name.endswith('.c') and HEX.fullmatch(e.name[:-2]):
                        c_count += 1
                        if c_count > 1:
                            return True
        except OSError:
            pass
    objects = session / 'objects'
    if objects.is_dir() and not objects.is_symlink():
        try:
            with os.scandir(objects) as es:
                for e in es:
                    if e.is_dir(follow_symlinks=False):
                        with os.scandir(e.path) as sub_es:
                            for sub_e in sub_es:
                                if HEX.fullmatch(sub_e.name) and sub_e.is_dir(follow_symlinks=False):
                                    return True
        except OSError:
            pass
    return False

def plan(session,max_files,min_age):
    report=session/'report.json';cache_path=session/'cache.json'
    if not report.is_file() or report.is_symlink():raise ValueError('missing regular report')
    if not cache_path.is_file() or cache_path.is_symlink():raise ValueError('missing regular cache')
    if time.time()-report.stat().st_mtime<min_age:return None
    if not _has_candidate(session):return []
    data=json.loads(report.read_text());cache=json.loads(cache_path.read_text())
    if not isinstance(data,dict) or not isinstance(data.get('records'),list) or not isinstance(cache,dict):
        raise ValueError('unsupported report/cache format')
    kept_sources=set();hot_chunks=set()
    # 2026-10-16 policy change: historical scored candidates are cold candidates —
    # the hot scored C is the report's per-symbol best rows plus matched/link-rejected
    # records. Nothing reads an old session source: cache rows carry scores, not
    # bodies, and fixup.py record() rewrites the content-addressed .c of any identical
    # body it regenerates, so cold storage loses no engine-reachable material
    # (--restore returns any member byte-verified). Matched/link-rejected rows keep
    # their complete object chunks (link provenance).
    for ident,row in cache.items():
        if not re.fullmatch('[0-9a-f]{64}',ident) or not isinstance(row,dict):
            raise ValueError('malformed cache identity')
        if row.get('matched') or row.get('link_rejected'):
            obj=Path(row.get('object',''))
            if obj.is_absolute() and obj.is_relative_to(session/'objects'):hot_chunks.add(obj.parent)
    best=data.get('best')
    if not isinstance(best,dict):raise ValueError('unsupported report format: best')
    for row in best.values():
        if not isinstance(row,dict):continue
        src=row.get('source')
        if isinstance(src,str) and Path(src).suffix=='.c':
            src_path=Path(src)
            if not src_path.is_absolute():raise ValueError('relative hot source path')
            if src_path.is_relative_to(session/'sources'):kept_sources.add(src_path.stem)
    # Preserve all metadata-referenced sources and complete current object chunks,
    # including ancestors, compile.log, .sym.o and same-chunk siblings.
    # report.json is excluded: its records span the whole run history (the heavy
    # set); its hot needs are exactly the best rows kept above.
    for meta in session.glob('*.json'):
        if meta.is_symlink():raise ValueError('symlink metadata')
        if meta.name=='report.json':continue
        obj=json.loads(meta.read_text())
        for value in _references(obj):
            try:p=Path(value)
            except (ValueError,TypeError):continue
            if not p.is_absolute():continue
            if p.is_relative_to(session/'sources'):kept_sources.add(p.stem)
            if p.is_relative_to(session/'objects') and p.suffix=='.o':
                # cache.json alone does not make a nonactionable object hot.
                if meta!=cache_path:hot_chunks.add(p.parent)
    files=[]
    sources=session/'sources'
    if sources.is_dir() and not sources.is_symlink():
        with os.scandir(sources) as es:
            for e in es:
                p=Path(e.path)
                if p.suffix=='.c' and HEX.fullmatch(p.stem) and p.stem not in kept_sources and e.is_file(follow_symlinks=False):
                    files.append(p)
                    if len(files)>=max_files:return files
    objects=session/'objects'
    if objects.is_dir() and not objects.is_symlink():
        for group in objects.iterdir():
            if group.is_symlink() or not group.is_dir():continue
            for chunk in group.iterdir():
                if chunk in hot_chunks or chunk.is_symlink() or not chunk.is_dir() or not HEX.fullmatch(chunk.name):continue
                for p in chunk.iterdir():
                    if p.is_file() and not p.is_symlink() and (p.suffix=='.o' or p.name=='compile.log'):
                        files.append(p)
                        if len(files)>=max_files:return files
    return files

def _safe_name(name):
    p=PurePosixPath(name)
    if p.is_absolute() or '..' in p.parts or '\\' in name or not p.parts:
        raise ValueError('unsafe archive member')
    return p

def verify_archive(path) -> dict[str, Any]:
    seen={};manifest=None
    with tarfile.open(path,'r:gz') as tf:
        for member in tf:
            _safe_name(member.name)
            if not member.isfile() or member.name in seen:raise ValueError('nonregular/duplicate archive member')
            f=tf.extractfile(member)
            if f is None:raise ValueError('missing regular archive payload')
            if member.name=='.manifest.json':manifest=json.load(f);seen[member.name]=None;continue
            h=hashlib.sha256();n=0
            for b in iter(lambda:f.read(1<<20),b''):h.update(b);n+=len(b)
            seen[member.name]=(h.hexdigest(),n)
    if not manifest or manifest.get('format')!='fzgx-fixup-cold-v1':raise ValueError('missing retention manifest')
    expected={r['path']:(r['sha256'],r['cookie'][2]) for r in manifest['members']}
    if len(expected)!=len(manifest['members']) or {k:v for k,v in seen.items() if k!='.manifest.json'}!=expected:
        raise ValueError('archive content/hash mismatch')
    return dict(files=len(expected),manifest=manifest,sha256=digest(path))

def compact(session,archive_root,dry_run=True,min_age=86400,max_files=20000) -> dict[str, Any]:
    result=dict(session=str(session),status='skipped',candidate_files=0,deleted_files=0,deleted_bytes=0)
    if session.is_symlink():return dict(result,status='unproven',reason='symlink session')
    session=session.resolve();fd=acquire(session,blocking=False)
    if fd is None:return dict(result,status='busy')
    try:
        try:files=plan(session,max_files,min_age)
        except (OSError,ValueError,TypeError,KeyError) as e:return dict(result,status='unproven',reason=str(e))
        if files is None:return dict(result,status='recent')
        result['candidate_files']=len(files)
        if not files:return dict(result,status='retained')
        if dry_run:return dict(result,status='dry-run')
        archive_root=archive_root.resolve();archive_root.mkdir(parents=True,exist_ok=True)
        space=headroom(archive_root)
        # Cold retention must still work below the generation reserve. Bound the
        # worst-case tar/gzip payload and leave a separate 256 MiB write reserve.
        required=sum(p.stat().st_size for p in files)
        required=(required*102+99)//100+len(files)*4096
        if required>space['free_bytes']-(256<<20) or space['free_inodes']<3:
            return dict(result,status='pressure',reason='insufficient temporary archive reserve')
        tmp=archive_root/('partial-'+str(time.time_ns())+'.tar.gz')
        members=[]
        with tarfile.open(tmp,'w:gz',compresslevel=3,dereference=True) as tf:
            for p in files:
                before=cookie(p);sha=digest(p);tf.add(p,arcname=str(p.relative_to(session)),recursive=False)
                if p.is_symlink() or cookie(p)!=before:raise ValueError('source changed while archiving; originals retained')
                members.append(dict(path=str(p.relative_to(session)),sha256=sha,cookie=before,blocks=p.stat().st_blocks))
            manifest=dict(format='fzgx-fixup-cold-v1',session=str(session),created=time.time(),members=members)
            b=json.dumps(manifest).encode();info=tarfile.TarInfo('.manifest.json');info.size=len(b);tf.addfile(info,io.BytesIO(b))
        with tmp.open('rb') as f:os.fsync(f.fileno())
        checked=verify_archive(tmp)
        final=archive_root/(checked['sha256']+'.tar.gz')
        tmp.replace(final)
        dfd=os.open(archive_root,os.O_RDONLY|os.O_DIRECTORY)
        try:os.fsync(dfd)
        finally:os.close(dfd)
        result.update(archive=str(final),archive_sha256=checked['sha256'],verified_files=checked['files'])
        parents=set()
        for r in members:
            p=session/r['path']
            if p.is_symlink() or not p.exists() or cookie(p)!=r['cookie'] or digest(p)!=r['sha256']:
                result['changed_files']=result.get('changed_files',0)+1;continue
            p.unlink();result['deleted_files']+=1;result['deleted_bytes']+=r['blocks']*512
            if p.is_relative_to(session/'objects'):parents.add(p.parent)
        for p in sorted(parents,key=lambda p:len(p.parts),reverse=True):
            with contextlib.suppress(OSError):p.rmdir()
        return dict(result,status='archived')
    except (OSError, ValueError, RuntimeError, tarfile.TarError) as error:
        return dict(result,status='blocked',reason=str(error))
    finally:release(fd)

def restore(archive,session,member=None):
    checked=verify_archive(archive);session=session.resolve();m=checked['manifest']
    if m['session']!=str(session):raise ValueError('restore session identity mismatch')
    rows=[r for r in m['members'] if member is None or r['path']==member]
    if member is not None and not rows:raise ValueError('unknown restore member')
    fd=acquire(session,blocking=False)
    if fd is None:raise ValueError('session is busy')
    try:
        for r in rows:
            p=session/r['path']
            if p.is_symlink() or not p.parent.resolve().is_relative_to(session):raise ValueError('unsafe restore destination')
            if p.exists() and digest(p)!=r['sha256']:raise ValueError('changed evidence; refuse overwrite')
        missing=[r for r in rows if not (session/r['path']).exists()]
        guard(session)
        space=headroom(session)
        required=sum(((r['cookie'][2]+4095)//4096)*4096 for r in missing)
        if required>space['free_bytes']-(8<<30) or sum(len(PurePosixPath(r['path']).parts) for r in missing)>space['free_inodes']-100000:
            raise ValueError('restore would exhaust disk/inode reserve')
        wanted={r['path']:r for r in rows};restored=0
        with tarfile.open(archive,'r:gz') as tf:
            for item in tf:
                if item.name not in wanted:continue
                p=session/item.name
                if p.exists():continue
                p.parent.mkdir(parents=True,exist_ok=True)
                src=tf.extractfile(item)
                if src is None:raise ValueError('missing restore payload')
                with p.open('xb') as out,src:
                    while True:
                        b=src.read(1<<20)
                        if not b:break
                        out.write(b)
                if digest(p)!=wanted[item.name]['sha256']:raise ValueError('restored hash mismatch')
                restored+=1
        return restored
    finally:release(fd)

def main(argv=None):
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--root',type=Path,default=STATE_DIR/'fixup'/'sessions')
    ap.add_argument('--archives',type=Path,default=STATE_DIR/'fixup-archives')
    ap.add_argument('--apply',action='store_true');ap.add_argument('--dry-run',action='store_true')
    ap.add_argument('--min-age-hours',type=float,default=24)
    ap.add_argument('--max-files',type=int,default=20000);ap.add_argument('--max-sessions',type=int,default=2)
    ap.add_argument('--status',type=Path);ap.add_argument('--restore',type=Path)
    ap.add_argument('--session',type=Path);ap.add_argument('--member')
    args=ap.parse_args(argv)
    if args.restore:
        if not args.session:ap.error('--restore requires --session')
        print(json.dumps(dict(restored=restore(args.restore,args.session,args.member))));return 0
    if args.max_files<1 or args.max_sessions<1 or args.min_age_hours<0:ap.error('invalid retention bounds')
    before=headroom(STATE_DIR);results=[]
    if args.root.is_dir():
        def priority(p):
            has_cand = _has_candidate(p)
            sources=p/'sources'
            return (0 if has_cand else 1, -(sources.stat().st_size if sources.exists() else 0), (p/'report.json').stat().st_mtime if (p/'report.json').exists() else float('inf'))
        sessions=sorted((p for p in args.root.iterdir() if p.is_dir() and not p.name.startswith('.')),key=priority)
        acted=0
        for p in sessions:
            r=compact(p,args.archives,dry_run=not args.apply or args.dry_run,min_age=args.min_age_hours*3600,max_files=args.max_files)
            print(json.dumps(r),flush=True)
            if r['status'] not in ('recent','retained'):results.append(r)
            if r['candidate_files']:
                acted+=1
                if acted>=args.max_sessions:break
    after=headroom(STATE_DIR)
    pressure=after['free_bytes']<30<<30 or after['free_inodes']<1000000 or (after['used_inode_percent'] is not None and after['used_inode_percent']>=75)
    status=dict(timestamp=time.time(),status='pressure' if pressure else 'healthy',before=before,after=after,results=results,deleted_files=sum(r['deleted_files'] for r in results),deleted_bytes=sum(r['deleted_bytes'] for r in results))
    if args.status:
        args.status.parent.mkdir(parents=True,exist_ok=True);tmp=args.status.with_suffix('.tmp');tmp.write_text(json.dumps(status,indent=2));tmp.replace(args.status)
    print(json.dumps(status),flush=True);return 0

if __name__=='__main__':raise SystemExit(main())
