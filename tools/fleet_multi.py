#!/usr/bin/env python3
"""Four real providers, one ledger, explicit model policy, independent backoff."""
from __future__ import annotations
import fcntl
import hashlib
import json
import os
import re
from pathlib import Path
import signal
import subprocess
import sys
import time
from datetime import datetime, timedelta
from fleet import (ROOT, CACHE, META, atomic, load, pid_alive, activity_state, provider_error_text,
                   cooldown, context_id, db_rows, telemetry, verified_progress,
                   record_gate, run_gate, stop_runner, tail_bytes, active_runner_pids)

POLICY = {
    'claude': {'harness':'claude','model':'claude-sonnet-5-5','effort':'high','display':'Sonnet 5.5 High'},
    'gpt': {'harness':'codex','model':'gpt-6-luna','effort':'high','display':'6-Luna High'},
    'agy': {'harness':'agy','model':'gemini-3.8-flash-high','effort':'high','display':'Gemini 3.8 High'},
    # DISABLED 2026-10-05, and the pin is deliberately left on the withdrawn model.
    # OpenRouter withdrew `stealth/space-bunny-alpha` from its catalogue, so every session
    # failed in about a second with a 404 "No endpoints found" -- 271 sessions in a day and
    # zero matches, against the best conversion rate of any family (4.0% on the day it was
    # healthy). Repinning to a free model that answers would have been worse than useless:
    # the substitutes that still respond (nemotron-120b, inkling, laguna) are not
    # decompilation-capable, and a matcher that cannot hold a register allocation in its head
    # burns checks without moving a function toward a match. The lane stays configured and
    # disabled until the real model returns or a stronger one is found; `permanent_fault`
    # parks it at PERMANENT_RETRY if it is ever switched back on while still withdrawn.
    'cline': {'harness':'cline','model':'stealth/space-bunny-alpha','effort':'high','display':'Space Bunny Alpha High'},
}
# The four opencode work slots are configured here but run the hermes transport (see the
# POLICY loop below). The Eww tile controls the group; the global FLEET_CAP and
# OPEN_CODE_ACTIVE_CAP limit concurrent execution to four.
PAID = ('claude', 'gpt', 'agy')
SURGE = ('oc1', 'oc2', 'oc3', 'oc4')
OPEN_CODE_ACTIVE_CAP = 4
SURGE_DELAY = 600      # retained for the disabled automatic-surge policy
SURGE_RETIRE = 1800
UNAVAILABLE = ('rate-limited', 'error', 'unavailable')
FLEET_CAP = 6         # owner-directed mix: 3 OpenCode + 2 Codex + 1 AGY

def resource_snapshot():
    """Linux host headroom; no model credentials or unrelated process data."""
    memory=dict(line.split(':',1) for line in Path('/proc/meminfo').read_text().splitlines())
    disk=os.statvfs(ROOT)
    temperatures=[]
    for sensor in Path('/sys/class/thermal').glob('thermal_zone*/temp'):
        try:
            temperatures.append(int(sensor.read_text()) / 1000)
        except (OSError, ValueError):
            pass
    batteries=[];ac=[]
    for supply in Path('/sys/class/power_supply').glob('*'):
        try:
            kind=(supply/'type').read_text().strip()
            if kind=='Battery':batteries.append(int((supply/'capacity').read_text()))
            elif kind in ('Mains','USB','USB_C'):ac.append((supply/'online').read_text().strip()=='1')
        except (OSError, ValueError):
            pass
    return dict(available_bytes=int(memory['MemAvailable'].split()[0])*1024,
                free_bytes=disk.f_bavail*disk.f_frsize,free_inodes=disk.f_favail,
                temperature_c=max(temperatures,default=0),
                battery_percent=min(batteries,default=100),on_ac=any(ac) if ac else not batteries)

def launch_hold(active, parallel, stats=None):
    """Hold admission under pressure; running bound tools drain normally."""
    if parallel < 1 or active + parallel > FLEET_CAP:
        return f'Global session cap {FLEET_CAP}: {active} active, {parallel} requested.'
    try:
        stats=resource_snapshot() if stats is None else stats
        if stats['available_bytes'] < 2 << 30:return 'Host memory reserve below 2 GiB; holding new batches.'
        if stats['free_bytes'] < 8 << 30:return 'Host disk reserve below 8 GiB; holding new batches.'
        if stats['free_inodes'] < 100000:return 'Host inode reserve below 100000; holding new batches.'
        if stats['temperature_c'] >= 90:return 'Host temperature at least 90 C; holding new batches.'
        if not stats['on_ac'] and stats['battery_percent'] <= 25:return 'Host battery at most 25% off AC; holding new batches.'
    except (OSError, KeyError, ValueError) as error:
        return f'Cannot verify host resource headroom: {error}'
    return ''

# Faults that no amount of retrying can clear. OpenRouter withdrew
# `stealth/space-bunny-alpha` from its catalogue, and every cline session then failed
# with a 404 "No endpoints found" inside one second -- 271 sessions a day, 0 matches,
# against the family's best conversion rate. Classified as a plain `error` it retried
# every RETRY_DELAY for the life of the daemon, so the fleet reported "cline: error,
# retrying" forever instead of naming the cause. Retiring the family until an operator
# repins a model is the only honest response: the model id is gone from the provider,
# not throttled, and no backoff schedule can bring it back.
PERMANENT_FAULT = ('no endpoints found', 'model not found', 'unknown model',
                   'model is not available', 'no providers found', 'freetiererror',
                   'free tier can only be used from within opencode')
PERMANENT_RETRY = 24 * 3600  # do not relaunch known-doomed sessions overnight

# Waves of work per batch. One batch at a time per family (see the `family in jobs` check at
# the launch site), so batch size -- not `parallel` -- is what sets a single-batch family's
# throughput. 2 waves matches the previous behaviour; 4 keeps a family's slots busy through a
# long session instead of idling between short batches.
BATCH_WAVES = 4

# Provider fallback (2026-10-03). A quota failure used to mean the family simply idled,
# which wasted the slot. FLEET.md's "quota failure remains quota failure, not permission to
# choose a different model" is a *no-silent-fallback* rule: the swap below is explicit,
# operator-directed, reported in the tile, and reversible. While a family's own model is
# healthy it runs unchanged; only a measured rate-limit switches it.
FALLBACK = {
    # agy authenticates to Gemini by default. On quota exhaustion it keeps the agy transport
    # (its own login, guard, and six bound MCP tools are already correct and verified) and
    # only swaps the model, so the fallback inherits everything that makes agy safe.
    'agy': {'model': 'claude-opus-5-5', 'effort': 'high', 'display': 'Opus 5.5 High (agy fallback)',
            'band': (1024, 1 << 30)},
}

# A fallback is a response to a measured quota wall, not a permanent reassignment. The dwell
# is bounded so a family cannot stay on a substitute model forever just because every batch
# it ran while substituted failed to finish cleanly. Half an hour is long enough to cover a
# real quota window and short enough that a recovered provider is back on its own model
# within one batch of the recovery.
FALLBACK_TTL = 1800

# Upper bound on any provider-reported retry delay. The longest genuine message observed is
# "Resets in 2h44m22s"; three hours covers it with margin while making it impossible for a
# single mis-parse to park a lane for days.
RETRY_MAX = 3 * 3600
for _n in SURGE:
    # OpenCode CLI with Space Bunny Free (operator-directed 2026-10-10).
    #
    # These lanes previously ran the hermes transport on Step5 Free: the opencode
    # free tier answers the restricted matcher agent with 403 FreeTierError
    # ("can only be used from within Opencode") when the client is NOT the
    # official opencode build, so a non-official client could not serve the free
    # models. The official client at ~/.opencode/bin/opencode (1.18.35) does serve
    # them, and `opencode/space-bunny-free` is in its catalogue, so the lanes now
    # run the real opencode harness on the free model. fleet_clients pins the
    # official binary (OPENCODE_CANDIDATES), launches with --pure, and confines
    # the agent to the six fzgx MCP tools; the 452 historical opencode-harness
    # attempts on this model produced 85 verified matches, so the lane has a real
    # conversion record -- unlike the Step5 transport it replaced.
    #
    # Variant is `high` (operator-directed 2026-10-10, moved up from `medium`).
    #
    # Why not the model's cap is the binding constraint: space-bunny-free advertises
    # limit.context=1048576, limit.input=524288, limit.output=524288, and the
    # variants are reasoningEffort levels (low/medium/high/xhigh) -- raising the
    # variant does NOT raise the output cap, it raises how many of those tokens the
    # model spends thinking. The measured failure was a per-step ceiling, not the
    # 524K output limit: one hard symbol at xhigh logged total=61664, output=10,
    # reasoning=31990, step_finish reason "length" -- it spent its whole per-step
    # budget on reasoning and emitted no tool call. So xhigh is a trap on hard
    # symbols (more reasoning headroom = more room to spiral), while `high` measured
    # stable on the full 58KB matcher prompt (3/3 completed, output 59-7738, no
    # length cap). `high` is the ceiling that still emits output reliably.
    # Current owner override (2026-10-11): replace OpenCode with Hermes Step5
    # ultra. Historical transport/effort measurements above are not this pin.
    # Keep the six-tool guard and compiler-progress timeout; never fall back.
    POLICY[_n] = {'harness':'hermes','model':'stepfun/step-5-preview:free','effort':'ultra',
                  'display':f'Step 5 Preview Free Ultra (Hermes #{_n[-1]})','managed':False}
    META[_n] = (f'OpenCode #{_n[-1]}', chr(0xF0A9B))
del _n
CONTROL = CACHE / 'control-v3.json'
MODEL_POLICY = CACHE / 'model-policy.json'
STATE = CACHE / 'status-v3.json'
RUNTIME = CACHE / 'runtime-v3.json'
HISTORY = CACHE / 'scheduled-v3.json'
STOP = False

def defaults():
    # OpenCode slots are operator-controlled and start disabled; automatic surge
    # remains off unless the owner explicitly changes that separate policy.
    return {family:{'enabled':family not in SURGE,'parallel':1} for family in POLICY}


def in_fallback(family):
    """True when `family` is currently serving its fallback model.

    Dwell lives in runtime-v3.json, so a daemon restart cannot silently drop a family back
    onto a model that was just measured out of quota -- that is the same reason the surge
    timer is persisted.

    The dwell is still bounded. `fb` is only popped when a batch finishes cleanly, so a
    family whose every batch rate-limits or crashes while serving the fallback never clears
    it: agy sat pinned to `claude-opus-5-5` for 11.8h across ~30 failed batches, serving a
    model it was never asked to use, long after Gemini recovered. Unattended, that is
    indistinguishable from being switched off. So the primary is re-probed once the dwell
    passes `FALLBACK_TTL`; if the quota is genuinely still gone the normal rate-limit path
    re-arms the fallback and the cycle continues.
    """
    if family not in FALLBACK:
        return False
    entry = _fallback_state().get(family)
    if not entry:
        return False
    since = entry.get('since') or 0
    retry_at = entry.get('retry_at') or 0
    # A provider that names its own reset time decides when we come back; the TTL is only
    # the bound for a provider that gave none.
    horizon = retry_at or (since + FALLBACK_TTL)
    if horizon and time.time() > horizon:
        return False
    return True


def _fallback_state():
    try:
        return json.loads(RUNTIME.read_text()).get('fallback') or {}
    except (OSError, ValueError):
        return {}


def effective(family):
    """The policy actually used for this batch: base model, or the fallback when in quota."""
    p = dict(POLICY[family])
    if in_fallback(family):
        p.update(FALLBACK[family])
    return p


def band_for(family):
    """Size band for `family`, which the fallback may widen (agy takes the large band)."""
    if in_fallback(family):
        return FALLBACK[family].get('band')
    return FAMILY_BANDS.get(family)

def model_dispatch_hold(policy):
    """Owner policy gates daemon work, not explicit standalone bounded tests."""
    if not isinstance(policy, dict) or policy.get('mode') not in ('fleet', 'test-only'):
        return 'Invalid model dispatch policy; refusing standing model work.'
    if policy['mode'] == 'test-only':
        return 'Owner requested test-only models; standing fleet and surge are paused.'
    return ''


def configuration():
    # Backfill families missing from an older control file, so adding a
    # provider never breaks status, the bar, or a running daemon.
    #
    # Drop retired/unknown families from older control files so stale state
    # cannot keep an unconfigured worker consuming capacity.
    stored=load(CONTROL,{})
    stored={k:v for k,v in stored.items() if k in POLICY}
    return {family:dict(stored.get(family) or defaults()[family]) for family in POLICY}

SESSION_TIMEOUT = 1800   # hang bound only; 16 checks / 5 stale checks end real work
IDLE_TIMEOUT = 900       # no log event from any session of the batch

def budget_limits(family, parallel, count):
    # No token guards: a session is already bounded by its check, stale-check
    # and turn limits, and provider quota rejections have their own cooldown.
    # Cumulative input counts re-read (cached) context every turn, so the old
    # 256k guard killed productive Claude sessions as "crashes" at 7 checks.
    # Only runaway log growth still stops a batch.
    unlimited=float('inf')
    return dict(input=unlimited,output=unlimited,batch_input=unlimited,batch_output=unlimited,
                log_bytes=64*1024*1024*parallel,guard_each=False,usage_wait=unlimited)

def seed_batch_symbols(symbols, records=None):
    """Separate closed pinned batches before reservations/history are recorded."""
    records = load(ROOT/'state/fleet/priority-seeds.json', {}) if records is None else records
    def seeded(symbol):
        row = records.get(symbol, {})
        return bool(row.get('source') or (row.get('path') and Path(row['path']).is_file()))
    return [s for s in symbols if seeded(s) == seeded(symbols[0])] if symbols else []


def admitted_seed_tokens():
    """One admission per proven source/pin/prologue, independent of HEAD churn."""
    tokens = {}
    for symbol, record in load(ROOT/'state/fleet/priority-seeds.json', {}).items():
        task = record.get('task', {})
        if task.get('queue_kind') != 'registered-measured-cohort':
            continue
        body = record.get('source')
        if not isinstance(body, str) or hashlib.sha256(body.encode()).hexdigest() != record.get('sha256'):
            continue
        evidence = {k: record.get(k) for k in ('sha256', 'mw', 'flags')}
        evidence['prologue'] = task.get('prologue_sha256')
        tokens[symbol] = hashlib.sha256(json.dumps(evidence, sort_keys=True).encode()).hexdigest()
    return tokens


def command(family,batch,symbols,parallel):
    if seed_batch_symbols(symbols) != symbols:
        raise ValueError('Mixed pinned and ordinary symbols must be separated before dispatch')
    p = effective(family)
    seeds=ROOT/'state/fleet/priority-seeds.json'
    # A seed manifest is a closed batch input: every assigned symbol must have
    # a complete source record, or ordinary functions fail claim with
    # "seeded batch has no candidate". Priority-only entries without source
    # bodies are task metadata, not compilable seeds.
    use_seeds = False
    records = {}
    if seeds.exists():
        try:
            records=json.loads(seeds.read_text())
            use_seeds = bool(symbols) and all(
                isinstance(records.get(s),dict) and isinstance(records[s].get('source'),str)
                and records[s].get('sha256') for s in symbols)
        except (OSError, ValueError):
            use_seeds = False
    if not use_seeds and any(isinstance(records.get(s), dict) and
                             (records[s].get('source') or records[s].get('path')) for s in symbols):
        raise ValueError('Incomplete compiler seed record; refusing unpinned dispatch')
    return [str(ROOT / '.venv/bin/python'), str(ROOT / 'tools/orchestrate.py'),
        *(['--seeds',str(seeds)] if use_seeds else []),
        '--harness',p['harness'],'--model',p['model'],'--effort',p['effort'],
        '--parallel',str(parallel),'--tool-parallel','1','--timeout',str(SESSION_TIMEOUT),
        '--max-checks','16','--max-stale','5','--max-attempts','999',
        '--verify-interval','60','--no-trivial','--batch',batch,'--symbols',*symbols]

# Conversion by attempt ordinal over the whole ledger: 32.5% on the first attempt,
# 42.0% on the second, then 20.6% / 22.8% / 29.1% / 10.3% for the third through
# sixth. The second pass is the productive one; everything past it is close to noise
# and each one costs a full session. The saved-body search still gets its own path
# (unsearched_near_misses), so a capped near-miss is not lost, only stopped from
# consuming a model session for a third re-derivation.
ATTEMPT_CAP = 2

# Carve-on-cap: when a family selects nothing, carve a few capped symbols into landable units.
#
# 1186 unmatched functions have no `splits.txt` range, so a body for one cannot be linked from C
# (docs/findings/279) -- and 2941 fleet attempts on them produced 0 matches against 410 on
# covered symbols (docs/findings/298). The bodies are already in the archive at ~99.6%; what is
# missing is the split range. `fzgx carve` supplies it with no lease, no model and no fleet slot,
# so an idle tick is not out of work, it is out of *landable* work.
#
# Bounded so a continuously-idle fleet cannot churn configure.py/ninja: at most CARVE_PER_TICK
# symbols per CARVE_INTERVAL, and only ones already past the attempt cap, so nothing is carved
# that has not had a real attempt.
CARVE_PER_TICK = 3
CARVE_INTERVAL = 600

# One-word tier: functions this fleet has already spent attempts on and whose only remaining
# defect is a single instruction word.
#
# `ATTEMPT_CAP` retires a function after two real attempts, which is right for functions whose
# bodies are wrong -- more attempts re-derive the same wrong source. It is wrong for a function
# that is one instruction away, because the next attempt is not a re-derivation, it is one edit.
# Measured 2026-10-04 over the >=99% band: 24 functions sit at <=2 differing words (seven at
# exactly 1), and **all 24 are past ATTEMPT_CAP and therefore unreachable** by choose(). The
# fleet was spending its whole budget on virgin 1-2 KB work at a measured 12.1% conversion while
# 24 functions sat one word from a match.
#
# `sweep` cannot reach them either: the deterministic engine measured 0 matches from 40,208
# candidates across this band (docs/findings/282), and finding 285 shows why -- the residue is
# one operand, and which operand is a per-function question. A model session with the word
# diff is the right owner, which is exactly what ATTEMPT_CAP was preventing.
#
# The list is data, not a guess: `fzgx shapecensus --words` regenerates it, and it is kept in
# state/ so a reviewer can see the measurement rather than trust the constant. `retry=`
# already bypasses the cap, so these ride the existing mechanism -- no new dispatch path.
#
# Re-measure before trusting this: the tier is empty once the tier is closed, and the file is
# regenerated by `fzgx shapecensus --words --json > state/one_word_tier.json`.
ONE_WORD_TIER = ROOT / "state" / "one_word_tier.json"
ONE_WORD_RESERVE = 4          # slots per batch held for this tier while it is non-empty

# Share of a batch given to the 80-95% mid band. Bounded rather than a strict precedence
# because both extremes of that choice were measured and both are wrong: ranking the mid band
# above virgin took virgin to 0 of 12 picks, and ranking virgin above it (the previous rule)
# took the mid band to 0. 25% keeps the largest proven source -- virgin, 872 conversions --
# holding the majority of every batch while giving the band that had no owner at all a
# guaranteed share.
MID_BAND_SHARE = 0.25

# Share of a batch for the one-word tier. Bounded rather than "all of them": the tier is 18
# functions and letting it lead unbounded took 7 of every 12 slots and left none for virgin
# work, which is the largest proven source of matches (872 conversions). It still leads, because
# each entry is one edit away from done, but it drains instead of crowding the queue out.
TIER_SHARE = 0.33

# Families that share the tier, in a fixed order. The rotation below needs a stable index so
# every active family lands on a different subset.
TIER_FAMILIES = ("agy", "cline", "gpt", "oc1", "oc2", "oc3", "oc4")


def one_word_tier(family=None):
    """Symbols whose next attempt is a single edit, from the measured snapshot.

    Read fresh each call: the tier drains as functions match, and a cached copy would keep
    handing out work that is already done. A missing or stale file yields an empty set, which
    is the safe direction -- the fleet then behaves exactly as it did before this existed.

    `family` rotates the result so the five families cover disjoint slices instead of all
    proposing the same head of the list. Measured before the rotation existed: five families
    picking six each proposed `fn_10_A90C` five times over -- 30 slots, about 8 distinct
    functions, and the rest of the tier untouched. The claim is atomic so the losers move on,
    but a refused claim is a wasted slot, and the tier is the scarcest work in the project.
    Ordering is by differing words so the rotation is stable and spreads the cheapest first.
    """
    try:
        data = json.loads(ONE_WORD_TIER.read_text())
    except (OSError, ValueError):
        return set()
    rows = data if isinstance(data, list) else data.get("functions", [])
    out = {row["symbol"] for row in rows
           # differing <= 2 AND a body that still diverges: a relocation-only defect reads as
           # 0 words, so a 0/0 entry means "no defect measured", not "one edit away".
           if row.get("symbol") and 0 < row.get("differing", 99) <= 2}
    if not family or len(out) < 2:
        return out
    try:
        offset = TIER_FAMILIES.index(family) * ONE_WORD_RESERVE
    except ValueError:
        return out
    ranked = sorted(out, key=lambda s: (next((r.get("differing", 99) for r in rows
                                             if r.get("symbol") == s), 99), s))
    offset %= len(ranked)
    return set(ranked[offset:] + ranked[:offset])

# The bands below are the only thing that decides where a family looks, and they were sized when
# the small-function pools were fresh. Measured 2026-10-04 against the real backlog:
#
#   band        backlog   virgin   attempted
#   <=256          198        4        194      <- exhausted
#   257-512        283        0        283      <- exhausted
#   513-1K         514        0        514      <- exhausted
#   1-2K           399      339         60      <- where the untouched work is
#   >2K            214      206          8      <- ditto
#
# The allocation below preserves the measured Cline 1-2 KB band and reflects the
# owner's current request: four Step 5 Free (hermes) slots with all four
# active concurrently. The replicas share the broad virgin-work supply; atomic claims
# and per-family history prevent duplicate ownership.
#
# A band is a supply statement, not a yield statement: it says where the untouched work is, and
# the widening path in choose() covers a band that runs dry. Re-measure with the size-band table
# above before changing one.
FAMILY_BANDS = {
    # The whole virgin supply sits in two bands: 330 functions at 1-2 KB and 206 above 2 KB.
    # Nothing below 1 KB is untouched (0 virgin at <=256, 257-512 and 513-1K), so any family
    # banded there is structurally starved and will fall through to re-deriving near-misses.
    # Bands below therefore partition the two live pools rather than repeat the old mistake.
    #
    # cline: the 1-2 KB pool, the largest and the one with measured conversion (12.1%, 55/454).
    # Its old band was (257,512), which held 283 functions and 0 virgin.
    'cline':  (1024, 2048),
    # Four pinned Step 5 Free lanes share the current virgin-work pool. Claims
    # remain function-atomic and the one-word rotation keeps their cheap repairs distinct.
    'oc1':    (1024, 1 << 30),
    'oc2':    (1024, 1 << 30),
    'oc3':    (1024, 1 << 30),
    'oc4':    (1024, 1 << 30),
    'gpt':    (1024, 1 << 30),
    # agy is a single-slot family, so contention costs it proportionally more than a
    # parallel=6 family, and it had no band at all (band_for returned None, so no size filter
    # applied and it drew from the entire backlog -- 4 of 6 targets overlapping cline/oc4/gpt,
    # and the four phantom symbols at the head of its queue). It takes 512-2048, the widest
    # slice in which it can lead on supply instead of trailing into a pool cline is draining.
    #
    # Overlapping bands are expected and not a bug. Measured: with these bands agy, cline, oc4
    # and gpt propose the *same* four symbols, because FAMILY_LOCKOUT only demotes a symbol
    # among functions this fleet has already run and all four are reaching virgin work for the
    # first time. FAMILY_LOCKOUT does NOT separate them, and an earlier draft of this comment
    # claimed it did -- corrected after measuring it. What actually prevents two families
    # working one symbol is the atomic claim in api.claim: the loser is refused, and the
    # backlog is wide enough that the next tick fills the slot. Verified live: 10 concurrent
    # claims, no symbol held twice.
    'agy':    (512, 2048),
}

# A family will not re-attempt a symbol another family already has in hand, and will
# not re-attempt its own either until the virgin pool is exhausted. Without this a
# symbol that reached 99.8% keeps being reissued and re-derived identically.
FAMILY_LOCKOUT = True

_attempts_cache = {'at': 0.0, 'mine': {}}

def local_attempts():
    """Attempts this fleet made that actually reached a model.

    The restored upstream history (DeepSeek, effort-none and Luna batches of September)
    left 464 small functions at 90%+ past the cap with their saved C on another
    machine; those attempts say nothing about this fleet's models and tools, so
    they do not count toward its cap.

    A provider refused for quota, credits or transport reasons also produces an
    ended attempt, but one with no checks and no tokens: no evidence and no work,
    while still consuming a slot against ATTEMPT_CAP and retiring the function
    from selection. 139 such rows existed when this was measured (58 of them
    codex; the rest agy/claude/cline/opencode), and about 27 functions were
    sitting at ATTEMPT_CAP on nothing but those rows. Both numbers move while the
    fleet runs. An attempt only counts if it ran a check, spent tokens, or matched.

    Memoised for one tick: the daemon calls this twice per family per tick (once
    in choose, once in unsearched_near_misses) and always got the same 300-entry
    dict back, so eight families rebuilt it sixteen times to answer one question.
    Callers only read the result.
    """
    now = time.time()
    if now - _attempts_cache['at'] > 3.0:
        _attempts_cache['mine'] = {r['symbol']:r['n'] for r in db_rows(
            "SELECT symbol,count(*) n FROM attempts WHERE agent LIKE 'fleet-v2-%' AND ended IS NOT NULL "
            "AND (COALESCE(checks,0)>0 OR COALESCE(tokens_in,0)>0 "
            "OR outcome IN ('matched','matched-pool','shadow-matched')) GROUP BY symbol")}
        _attempts_cache['at'] = now
    return _attempts_cache['mine']

def unsearched_near_misses(rows):
    """Functions past the attempt cap whose best saved body the current search engine
    has never run on. Each gets one more pass: the claim searches that body first (a
    match costs no model request), otherwise one model attempt continues from the
    searched body. Its release marks the body, which ends the eligibility."""
    from fzgx import api
    mine=local_attempts()
    wanted={r['symbol'] for r in rows if r['status']=='unmatched' and mine.get(r['symbol'],0)>=ATTEMPT_CAP
            and (r.get('best',r.get('best_percent',0)) or 0)>=90
            and size_allowed(r['size'], r.get('best',r.get('best_percent',0)))}
    if not wanted:
        return set()
    engine=api._engine_id();best={}
    # Filter on symbol in SQL. The predicate was applied in Python, after the query
    # had already fetched all 12k attempt rows, and then stat()ed every saved body
    # and read a marker JSON per candidate - about 1000 filesystem syscalls, every
    # tick, for 60 answers.
    names=sorted(wanted)
    found=[]
    for i in range(0,len(names),400):   # stay well under SQLITE_MAX_VARIABLE_NUMBER
        chunk=names[i:i+400]
        found += db_rows(
            'SELECT symbol,best_body_path,'
            'MAX(COALESCE(final_percent,0),COALESCE(best_in_attempt,0)) score,id '
            'FROM attempts WHERE ended IS NOT NULL AND best_body_path IS NOT NULL '
            f"AND symbol IN ({','.join('?' * len(chunk))}) "
            'ORDER BY symbol, score DESC, id DESC', chunk)
    # Highest score then highest id, exactly as the Python chase used to pick.
    # A bare GROUP BY would not do: the two-argument MAX is scalar, not an
    # aggregate, so best_body_path came from an arbitrary row and usually
    # resolved to a restored upstream body that does not exist on this machine.
    for a in found:
        if a['symbol'] in best:
            continue
        # Restored upstream history names bodies that are not on this machine.
        if Path(a['best_body_path']).exists():
            best[a['symbol']]=(a['score'],a['id'],a['best_body_path'])
    out=set()
    for symbol,(_,_,path) in best.items():
        marker=load(Path(path+'.searched.json'),{})
        if marker.get('engine')!=engine or marker.get('budget_s',0)<api.SEARCH_S:
            out.add(symbol)
    return out

SIZE_GATE = 2048
NEAR_MISS_PCT = 95.0
# Fraction of the batch that may go to work past SIZE_GATE, to measure whether the gate is
# still earning its keep rather than assuming it either way. 0 disables the probe.
#
# The gate was raised from 1024 to 2048 on the evidence that "2-4KB is 0/10 and >4KB is
# 0/14". Re-measured over the whole fleet history that evidence is **8 functions, not 24**:
# only 8 above-2KB functions were ever first-touched (4 virgin, 4 near-miss), and none
# converted. That is too thin a sample to close 206 functions and 674,472 B -- **38% of all
# outstanding bytes** -- and it was self-sealing: the gate blocks exactly the functions needed to
# grow the sample.
#
# The real cost was never measured and is concrete. oc1's band is (2048, inf), so:
#
#     oc1 band inventory      214 functions
#     of those servable         8
#
# oc1 could not reach 206 virgin functions in its only band and had 0 virgin reachable. The
# fleet was not being protected from bad work above 2KB; one family was idle.
#
# Rather than move the gate on an 8-sample argument in either direction, the gate stands and a
# quarter of each batch is allowed past it as a **measured probe**. If those conversions land,
# the gate was wrong and should be raised. If they do not, the probe is the evidence the
# original claim never had. Either way the question gets answered with data instead of inherited
# numbers, and the probe is one constant to revert.
OVERSIZE_PROBE = 0.25
# A saved body that already diffs at this closeness is worth more per compile than
# a cold small function, so the size gate widens for it instead of excluding it
# outright.
#
# The gate was 1024B and was starving the fleet. Of the 610 functions this fleet had
# never actually attempted, 598 were blocked by it and only 12 were servable, so the
# "fresh work first" ordering in choose() had almost nothing fresh to order and the
# fleet fell through to whatever was left in base -- which is why the backlog looked
# exhausted. Measured over three days of fleet attempts, the 1-2KB band converts at
# 10.3% (6/58), which is indistinguishable from the 11.4% (370/3232) of the band the
# gate was written to protect. Beyond 2KB the evidence does not support opening it:
# 2-4KB is 0/10 and >4KB is 0/14. So the gate moves to 2048, where the data says yes,
# and stops there.
#
# The 1024B gate is a throughput heuristic, not a correctness rule: 51 near-misses
# above it (fn_1_FD3A8 at 99.49%, fn_10_107D4 at 98.19%) had a local body ready and
# were never scheduled.
def size_allowed(size, best):
    return size<=SIZE_GATE or (best or 0)>=NEAR_MISS_PCT

_linkfail_cache = {'at': 0.0, 'symbols': frozenset()}

_uncovered_cache = {'at': 0.0, 'symbols': frozenset()}

# Same shapes tools/fzgx/splitgaps.py parses, so the fleet and the diagnostic tool cannot
# disagree about what "covered" means.
SYM_RE = re.compile(r'^(\w+) = \.(?:text|init):(0x[0-9A-Fa-f]+);\s*//\s*type:function size:(0x[0-9A-Fa-f]+)')
RANGE_RE = re.compile(r'start:(0x[0-9A-Fa-f]+)\s+end:(0x[0-9A-Fa-f]+)')

def uncovered_symbols():
    """Unmatched functions lacking registration or executable split coverage.

    A split range is a hard prerequisite for a body to land at all: without one,
    carving a unit duplicates the function in the module and the byte count stops
    matching retail (docs/findings/279). The per-object oracle still reports ~100%
    for the body, because it diffs one object against retail and never sees the
    module, so a model session can produce a perfect body for a symbol that cannot
    be linked from C.

    `link_failed()` cannot catch this class: a symbol with no split range never
    reaches a link test, so it never records `link-mismatch` and is never retired.

    Measured over every fleet attempt in the ledger (docs/findings/298):

        uncoverable  1186 symbols  2941 attempts    0 matched
        landable      724 symbols  1690 attempts  410 matched

    71% of the most-attempted symbols were uncoverable. `fzgx carve` closes the gap
    deterministically -- it needs no lease, no model and no fleet -- so these are not
    dead work, they are unscheduled work. They sort behind covered symbols rather
    than being dropped, which keeps virgin/mid/tier pools intact while stopping the
    fleet from spending its best slots re-deriving bodies that cannot land.
    """
    now = time.time()
    if now - _uncovered_cache['at'] > 30.0:
        # Split entries name source paths, the ledger names symbols, and neither is a
        # reliable key on its own: a split can cover a `.text` range without naming the
        # symbol, and units.json lists symbols with no split. The authority is address
        # coverage -- symbols.txt gives (symbol -> addr, size) and splits.txt gives the
        # ranges already claimed -- which is exactly how tools/fzgx/splitgaps.py answers
        # the same question. Matching on names instead answers "nothing is covered" for
        # every function whose split lives under a different basename.
        covered = {}
        # The DOL module keeps its symbols.txt/splits.txt at config/GFZE01/ top level;
        # every REL module has its own config/GFZE01/<module>/ pair. Both layouts must be
        # read or the whole main module reports as uncovered.
        #
        # Keyed by module for the same reason `units` is: `_prolog` and `_epilog` exist in
        # every module, so a flat set would mark `customize:_prolog` covered on the strength
        # of `movie_module:_prolog`, and the filter would silently skip real gaps.
        sources = [(ROOT / 'config' / 'GFZE01' / 'symbols.txt',
                    ROOT / 'config' / 'GFZE01' / 'splits.txt', 'main')]
        sources += [(d / 'symbols.txt', d / 'splits.txt', d.name)
                    for d in sorted((ROOT / 'config' / 'GFZE01').glob('*/'))]
        for sym_txt, split_txt, mod in sources:
            if not sym_txt.exists() or not split_txt.exists():
                continue
            ranges = []
            cur_ok = False
            for line in split_txt.read_text(errors='replace').splitlines():
                s = line.strip()
                if s.startswith('rel/') or s.startswith('dol/'):
                    cur_ok = True
                    continue
                if cur_ok and ('.text' in s or '.init' in s):
                    m = RANGE_RE.search(s)
                    if m:
                        ranges.append((int(m.group(1), 16), int(m.group(2), 16)))
            if not ranges:
                continue
            hit = set()
            for line in sym_txt.read_text(errors='replace').splitlines():
                m = SYM_RE.match(line.strip())
                if not m:
                    continue
                addr, size = int(m.group(2), 16), int(m.group(3), 16)
                if any(s <= addr and addr + size <= e for s, e in ranges):
                    hit.add(m.group(1))
            if hit:
                covered.setdefault(mod, set()).update(hit)
        try:
            rows = json.loads((ROOT / 'config' / 'GFZE01' / 'units.json').read_text())
        except (OSError, ValueError):
            rows = []
        # Keyed by module: `_prolog` and `_epilog` exist in every module, so a flat
        # symbol set would make `sel:_prolog` look covered because `customize:_prolog`
        # is registered. Symbol -> module is what disambiguates them.
        from fzgx.project import Project
        try:
            proj = Project()
        except Exception:
            proj = None
        module_of = {}

        def resolve(sym):
            if proj is None:
                return sym.split(':', 1)[1] if ':' in sym else sym
            try:
                r = proj.resolve(sym)
                return r.name if r is not None else (sym.split(':', 1)[1] if ':' in sym else sym)
            except Exception:
                return sym.split(':', 1)[1] if ':' in sym else sym

        units = {}
        for row in rows:
            mod, src = row.get('module'), (row.get('source') or '')
            stem = src.rsplit('/', 1)[-1]
            if stem.endswith('.c'):
                stem = stem[:-2]
            names = set(row.get('symbols') or ())
            names.add(stem)
            units.setdefault(mod, set()).update(names)

        # symbol -> module, from the same resolver the rest of the fleet trusts. A bare
        # ledger symbol resolves unambiguously; a module-qualified one is taken literally.
        unmatched_rows = db_rows("SELECT symbol FROM functions WHERE status='unmatched'")
        for r in unmatched_rows:
            sym = r['symbol']
            if ':' in sym:
                module_of[sym] = sym.split(':', 1)[0]
                continue
            if proj is None:
                continue
            try:
                res = proj.resolve(sym)
            except Exception:
                res = None
            if res is not None:
                module_of[sym] = res.module

        _uncovered_cache['symbols'] = frozenset(
            r['symbol'] for r in unmatched_rows
            if resolve(r['symbol']) not in covered.get(module_of.get(r['symbol']), set())
            or resolve(r['symbol']) not in units.get(module_of.get(r['symbol']), set()))
        _uncovered_cache['at'] = now
    return _uncovered_cache['symbols']

_carve_budget_cache = {'at': 0.0, 'n': 0}

def carve_capped(rows, retry, statuses, family):
    """Carve a few uncovered symbols that have already burned their attempt cap.

    A family that selected nothing is usually not out of work -- it is out of *landable*
    work. Every uncovered symbol it passed over is a body the fleet already produced at
    ~99.6% and cannot link, and `fzgx carve` converts one into a landable unit with no
    lease, no model request and no fleet slot. Doing it here turns an idle tick into
    forward progress instead of a 30s sleep.

    Bounded to CARVE_PER_TICK per carve interval so a steady fleet cannot churn
    configure.py/ninja. Symbols are taken highest-best-first: those are the ones where a
    body is already sitting in the archive waiting for a split range.
    """
    now = time.time()
    if now - _carve_budget_cache['at'] < CARVE_INTERVAL:
        return
    unc = uncovered_symbols()
    if not unc:
        return
    mine = local_attempts()
    pool = [r for r in rows if r['status'] == 'unmatched'
            and r['symbol'] in unc
            and mine.get(r['symbol'], 0) >= ATTEMPT_CAP
            and (r.get('best', r.get('best_percent', 0)) or 0) >= 90
            and size_allowed(r['size'], r.get('best', r.get('best_percent', 0)))]
    pool.sort(key=lambda r: -(r.get('best', r.get('best_percent', 0)) or 0))
    pool = [r for r in pool if r['symbol'] not in set(retry)][:CARVE_PER_TICK]
    if not pool:
        return
    try:
        from fzgx import api
        from fzgx.project import Project
        res = api.carve_many(Project(), [r['symbol'] for r in pool])
    except Exception as exc:                      # never let a carve stall the daemon
        print(f'{family}: carve_capped skipped: {exc!r}', flush=True)
        _carve_budget_cache['at'] = now
        return
    done = [r['symbol'] for r in res if r.get('created')]
    _carve_budget_cache.update(at=now, n=len(done))
    if done:
        # A fresh split range changes what the next choose() can land, so the
        # per-tick row cache must not serve the pre-carve view.
        _uncovered_cache['at'] = 0.0
        print(f'{family}: carved {len(done)} capped symbol(s) into landable units: '
              f'{", ".join(done[:6])}', flush=True)

def link_failed():
    """Symbols whose last attempt matched the object and was rejected by the link.

    These need `fzgx why-link`, not another model session. The object oracle cannot
    see the link, so a matcher has no tool that shows why the bytes moved, and a new
    session re-derives the same body from a stub and fails identically - five functions
    sat at best_percent 100.0 and unmatched for exactly that reason. Sorted by -best
    these are otherwise the *first* targets chosen, so they consumed the highest-value
    slots in the fleet. Retired from model dispatch until the link difference is read.
    """
    now = time.time()
    if now - _linkfail_cache['at'] > 5.0:
        _linkfail_cache['symbols'] = frozenset(r['symbol'] for r in db_rows(
            "SELECT symbol FROM attempts a WHERE outcome='link-mismatch' AND id=("
            "SELECT MAX(b.id) FROM attempts b WHERE b.symbol=a.symbol)"))
        _linkfail_cache['at'] = now
    return _linkfail_cache['symbols']

def virgin_symbols(rows, mine):
    """Unmatched functions this fleet has never actually attempted.

    1,116 of the 1,759 unmatched functions had no real attempt, and the shared
    -best_percent sort never reached them: every one of them sorts below the saved
    near-misses, so as long as a 97% target existed anywhere the fleet would keep
    re-deriving that instead of touching fresh work. These are the cheapest wins
    available and the pool was going to waste.
    """
    return {r['symbol'] for r in rows
            if r['status']=='unmatched' and not mine.get(r['symbol'])}

_family_seen_cache = {'at': 0.0, 'families': {}}

def families_that_tried():
    """symbol -> set of fleet families that already made a real attempt on it.

    Same qualifying predicate as local_attempts, so a provider rejection that ran
    no check and spent no token does not mark a function as somebody's.
    """
    now=time.time()
    if now - _family_seen_cache['at'] > 3.0:
        _family_seen_cache['families']={}
        for r in db_rows("SELECT symbol,agent FROM attempts WHERE agent LIKE 'fleet-v2-%' "
                         "AND ended IS NOT NULL AND (COALESCE(checks,0)>0 "
                         "OR COALESCE(tokens_in,0)>0 OR outcome IN "
                         "('matched','matched-pool','shadow-matched'))"):
            agent=r['agent']
            # fleet-v2-<family>-<ns>-<harness>-<n>
            parts=agent.split('-')
            family=parts[2] if len(parts)>2 else ''
            if family not in POLICY:
                continue
            _family_seen_cache['families'].setdefault(r['symbol'],set()).add(family)
        _family_seen_cache['at']=now
    return _family_seen_cache['families']

def choose(rows, seen, context, count, reserved=(), retry=(), family=None, protected_modules=()):
    # Do not let autonomous commits absorb pre-existing operator source edits.
    rows=[r for r in rows if r['module'] not in protected_modules]
    claimed_units={(r['module'],r['unit']) for r in rows if r['status']=='claimed' and r.get('unit')}
    mine=local_attempts()
    virgin=virgin_symbols(rows,mine)
    linkfail=link_failed()
    # Coverage is an admission prerequisite, not a ranking hint. If covered
    # supply runs out, the caller's bounded carve path may register a measured
    # cohort; never fill paid slots with currently unlandable fallback work.
    uncovered=uncovered_symbols()
    rows=[r for r in rows if r['symbol'] not in uncovered]
    tried=families_that_tried() if FAMILY_LOCKOUT else {}
    tier=one_word_tier(family)
    # A near-miss score or an unsearched marker is ranking evidence, not a
    # reason to bypass the model-attempt cap. Save-only budget releases do not
    # run deep search, so `retry` otherwise reopens the same body every batch.
    # Only the explicit source/pin/prologue admissions below may cross the cap.
    eligible_retry=set()
    admissions = admitted_seed_tokens() if family == 'gpt' else {}
    fresh_admissions = {s for s, token in admissions.items()
                        if seen.get('admission:' + s) != token}
    # An explicit measured cohort gets one retry for its new, proven inputs;
    # a batch snapshot changing HEAD does not reopen the same admission.
    rows=[r for r in rows if r['symbol'] not in admissions or r['symbol'] in fresh_admissions]
    eligible_retry |= fresh_admissions
    base=[r for r in rows if r['status']=='unmatched' and (mine.get(r['symbol'],0)<ATTEMPT_CAP or r['symbol'] in eligible_retry)
          and r['symbol'] not in linkfail
          and size_allowed(r['size'], r.get('best',r.get('best_percent',0)))
          and seen.get(r['symbol'])!=context and r['symbol'] not in reserved
          and not (r.get('unit') and (r['module'],r['unit']) in claimed_units)]
    # Fresh work first, then the one-word tier, then saved near-misses, then smallest. Sorting
    # on -best_percent alone is what buried the virgin pool, and sorting on virgin alone is what
    # buried the tier: a one-word function is worth more than a cold 1-2 KB function regardless
    # of which pool it came from, and 12.1% measured conversion on virgin work does not outrank
    # an edit that closes the function.
    # The 80-95% band: unfinished work that no ordering rule could reach.
    #
    # Measured 2026-10-05: 384 functions sit between 80% and 95%, 149 of them admitted by
    # ATTEMPT_CAP, and **choose() selected 0 of them for every family**. Not because they were
    # ineligible -- `virgin` holds 523 unmatched functions and this band sorts behind all of
    # them, so with virgin-first ordering the queue never reaches it. Simulating the one-word
    # tier drained still gave 0/8, which rules out the tier as the cause and confirms the
    # virgin-first rule is. "Whatever is open" is therefore not true of this band: nothing in
    # the policy would ever pick it up.
    #
    # And it is not a dead shelf. Grouping every function the fleet has ever matched by its
    # best percent before the fleet first touched it:
    #
    #     <80%  872      95-99%  194
    #     80-95%  378     >=99%   64
    #
    # 378 functions have converted *from* this band, against 194 from the near-miss bands the
    # policy does prioritise. It is the second-largest proven source of matches and it had no
    # owner at all. The mid band gets slots ahead of virgin work without displacing the tier.
    mid_band={r['symbol'] for r in rows if r['status']=='unmatched'
              and 80 <= (r.get('best',r.get('best_percent',0)) or 0) < 95
              and mine.get(r['symbol'],0) < ATTEMPT_CAP}
    closure={r['symbol'] for r in rows if r['status']=='unmatched' and r['module'] in ('replay','car_colchg','sample')}
    order=lambda r:(0 if r['module']=='main_rel' else 1 if r['symbol'] in closure else 2,
                    0 if r['symbol'] in tier else 1 if r['symbol'] in mid_band else 2
                    if r['symbol'] in virgin else 3,
                    1 if r['symbol'] in uncovered else 0,
                    -(r.get('best',r.get('best_percent',0)) or 0),
                    mine.get(r['symbol'],0),r['size'],r['symbol'])
    band=band_for(family) if family else None
    eligible=sorted([r for r in base if band and band[0]<=(r['size'] or 0)<=band[1]],key=order)
    # The tier is lifted above the band. A family band exists so that families do not all grind
    # the same size shelf; it is a division of labour, not a quality gate, and it cannot be
    # allowed to hide a function that is one instruction from a match. Measured: all 18 tier
    # symbols pass size_allowed, but the band excluded 5 of them outright and demoted the rest,
    # which is what left cline and gpt at 0/6. Everything here is still gated by base -- attempt
    # cap via eligible_retry, link failures, in-flight units and the current-context guard.
    if tier or mid_band or closure or fresh_admissions:
        # Both pools are lifted above the band for the same reason, and the mid band's case is
        # the sharper one: 126 of its 149 eligible functions are under 1 KB, and every family
        # band starts at 1 KB or higher (cline 1024, agy 512, oc1 2048, oc4 257, gpt 1024), so
        # oc1's band excluded **all** of them and the others saw at most 23. A band is a
        # division of labour, not a quality gate -- it exists so families do not all grind the
        # same size shelf, which is a reason to share, not a reason to hide a pool with no
        # other route to a session. Everything is still gated by base: attempt cap, link
        # failures, in-flight units and the current-context guard.
        lifted=[r for r in base if r['symbol'] in tier or r['symbol'] in mid_band or r['symbol'] in closure or r['symbol'] in fresh_admissions]
        # Dedup by symbol, not by id(). `id()` identifies the dict object, and `lifted` and
        # `eligible` are built by two separate comprehensions over `base`, so the same row is a
        # different object in each and `id(r) not in seen_ids` is always true. That duplicated
        # every lifted row and, worse, left the later `inband` guard reading a list that no
        # longer matched what was being prepended.
        lifted_symbols={r['symbol'] for r in lifted}
        eligible=sorted(lifted,key=order)+[r for r in eligible if r['symbol'] not in lifted_symbols]
    if len(eligible)<count:
        # The band's own slice cannot fill the request. Widen to the rest of the
        # backlog rather than idle the slot: a starved family is worse than a band
        # that overlaps another family's for one batch.
        inband={r['symbol'] for r in eligible}
        eligible+=sorted([r for r in base if r['symbol'] not in inband],key=order)
    if family and FAMILY_LOCKOUT:
        # Prefer symbols this family has not run. Only fall back to its own history
        # if that leaves the request short, so a stuck family still makes progress.
        # Lockout is a division of labour against wasted re-derivation; it is not applied to the
        # tier, because a one-word function is one edit that every family answers the same way,
        # and the atomic claim in api.claim already stops two families holding one symbol. This
        # matters in practice: with lockout applied, cline/gpt/oc4/agy each scored 0/6 tier picks
        # because they had already run most tier symbols, while oc1 scored 3/6. The tier has to
        # be leading the list, not trailing it -- as `fresh + tierrows` it sat behind six virgin
        # functions and was never reached at all.
        keep=[r for r in eligible if r['symbol'] in tier or r['symbol'] in mid_band]
        rest=[r for r in eligible if family not in tried.get(r['symbol'],())
              and r['symbol'] not in tier and r['symbol'] not in mid_band]
        rest+=[r for r in eligible if r not in keep and r not in rest]
        eligible=keep+rest
    # Three pools, each with a bounded share of the batch, then virgin takes the remainder.
    #
    # This replaced a strict precedence, and both extremes were measured and are wrong. Ranking
    # the mid band above virgin took virgin to **0 of 12** picks, and virgin is the largest
    # proven source of matches (872 conversions). Ranking virgin above the mid band is what
    # starved it in the first place, at 0 picks.
    #
    # The caps are enforced by `_pick` below, at the point rows are actually taken, not by
    # reordering the list here. Slicing the list did not bind: the lockout block above has
    # already partitioned rows, so tier rows sit *after* the head and a sliced head left 9 of 12
    # picks in the tier with the cap nominally at 4.
    _used=set()
    _units=set(claimed_units)
    # Reserve two thirds for the largest backlog without widening any attempt,
    # size or pool cap. Unavailable primary supply spills back to other modules.
    primary_target=(2*count+2)//3
    primary_units={(r['module'],r.get('unit') or r['symbol']) for r in base if r['module']=='main_rel'}
    secondary_limit=count-min(primary_target,len(primary_units))
    secondary_used=0
    def _take(r, enforce_share=True):
        nonlocal secondary_used
        unit=(r['module'],r.get('unit') or r['symbol'])
        if r['symbol'] in _used or unit in _units or len(_used)>=count:
            return False
        if count>=4 and r['symbol'] in closure and _used & closure:
            return False
        if enforce_share and r['module']!='main_rel' and secondary_used>=secondary_limit:
            return False
        _used.add(r['symbol']); _units.add(unit)
        secondary_used+=r['module']!='main_rel'
        return True
    def _pick(pool, cap):
        out=[]
        for r in eligible:
            if len(out) >= cap: break
            if r['symbol'] in pool and _take(r):
                out.append(r['symbol'])
        return out
    n_tier=min(ONE_WORD_RESERVE, int(count * TIER_SHARE))
    n_mid=int(count * MID_BAND_SHARE)
    chosen=_pick(fresh_admissions, count)
    chosen+=_pick(closure, int(count>=4))
    chosen+=_pick(tier, n_tier)
    chosen+=_pick(mid_band, n_mid)
    # Oversize probe: a bounded slice of work past SIZE_GATE, which size_allowed otherwise blocks
    # (see OVERSIZE_PROBE). Drawn from the gated rows explicitly, so it can only ever be this
    # share -- it does not widen the gate for anything else, and a batch with no oversize work
    # simply does not fill this share from it.
    if OVERSIZE_PROBE:
        # `base` only holds size_allowed rows, so the gated ones are re-read from `rows`. They
        # are otherwise-ineligible (that is what the gate means) and are admitted here and
        # nowhere else, which is what makes this a probe rather than a gate change.
        gated=[r for r in rows if r['status']=='unmatched'
               and not size_allowed(r['size'], r.get('best',r.get('best_percent',0)))
               and r['symbol'] not in linkfail
               and mine.get(r['symbol'],0) < ATTEMPT_CAP
               and seen.get(r['symbol']) != context
               and r['symbol'] not in reserved
               and not (r.get('unit') and (r['module'],r['unit']) in claimed_units)]
        probe=int(count * OVERSIZE_PROBE)
        n_probe=0
        for r in sorted(gated,key=order):
            if n_probe >= probe or len(chosen) >= count: break
            if _take(r):
                chosen.append(r['symbol']); n_probe+=1
    # Only pools that were *filled to their cap* have their remaining rows withheld. A pool that
    # could not fill its share has nothing to withhold, so its leftover rows stay in the fallback
    # or the batch idles -- measured at 9 of 12 when every capped pool was withheld regardless of
    # how many rows it actually held.
    full=set()
    if count>=4 and _used & closure: full|=closure
    if n_tier and len([s for s in _used if s in tier])>=n_tier: full|=tier
    if n_mid and len([s for s in _used if s in mid_band])>=n_mid: full|=mid_band
    if OVERSIZE_PROBE and probe and n_probe>=probe: full|={r['symbol'] for r in gated}
    eligible=[r for r in eligible if r['symbol'] not in set(chosen) and r['symbol'] not in full]
    selected=list(chosen)
    while len(selected)<count:
        primary_count=len(selected)-secondary_used
        ordered=sorted(eligible,key=lambda r:(
            (r['module']!='main_rel') if primary_count<primary_target else (r['module']=='main_rel'),
            order(r)))
        row=next((r for r in ordered if _take(r)),None)
        if row is None:
            # A capped pool/shared unit can exhaust the nominal primary supply.
            # Fill from already eligible rows; never bypass the hard guards.
            row=next((r for r in ordered if _take(r,False)),None)
        if row is None:break
        selected.append(row['symbol'])
    return selected

def policy_context():
    digest=hashlib.sha256((context_id()+json.dumps(POLICY,sort_keys=True)).encode())
    for name in ('fleet_clients.py','fleet_cline.mjs','fleet_mcp.py','fleet_agy_guard.py','fleet_provider.py'):
        digest.update((ROOT/'tools'/name).read_bytes())
    return digest.hexdigest()

RESET_IN = re.compile(r'Resets in\s+(?:(\d+)h)?\s*(?:(\d+)m)?\s*(?:(\d+)s)?', re.I)
# Codex states the reset as "try again at Oct 2nd, 2026 1:08 AM" on one turn and
# as "try again at 1:08 AM" on the next; Claude as "resets 1am". The date is
# optional, so both forms resolve to the same wall clock.
RESET_AT = re.compile(r'try again at\s+(?:([A-Z][a-z]{2})\s+(\d{1,2})(?:st|nd|rd|th)?,?\s*(\d{4})?\s*)?'
                      r'(?:at\s*)?(\d{1,2}):(\d{2})\s*(am|pm)', re.I)
RESET_CLOCK = re.compile(r'resets?\s+(\d{1,2})(?::(\d{2}))?\s*(am|pm)', re.I)

def _seconds_until(hour, minute, meridiem):
    """Seconds until the next occurrence of a wall-clock time, in local time.

    Built from now() rather than strptime: a '%Y %I:%M %p' pattern has no day or
    month, so strptime silently defaults to January 1 and every reset lands in
    the distant past.
    """
    try:
        hour12 = int(hour) % 12 or 12
        when = datetime.now().replace(hour=hour12, minute=int(minute or 0),
                                      second=0, microsecond=0)
    except (TypeError, ValueError):
        return None
    if meridiem:
        if meridiem.lower() == 'pm' and hour12 != 12:
            when += timedelta(hours=12)
        elif meridiem.lower() == 'am' and hour12 == 12:
            when -= timedelta(hours=12)
    seconds = (when - datetime.now()).total_seconds()
    if seconds < -60:       # that time already passed today: mean tomorrow
        seconds += 86400
    return max(60, min(86400, seconds + 30))

def permanent_fault(text):
    """True when the provider says the pinned model itself is gone.

    Deliberately narrow: it matches only the catalogue-withdrawal wording, never a
    generic 404 or transport error, because retiring a family on a transient fault
    would take a working provider offline. The check reads the provider's error text
    rather than the harness exit code, since a withdrawn model exits exactly like any
    other failed session.
    """
    haystack=provider_error_text(text).lower()
    return any(marker in haystack for marker in PERMANENT_FAULT)

def retry_delay(text, failures):
    """Backoff that trusts the provider's own reset time when it gives one.

    Codex reports an absolute reset ("try again at Oct 2nd, 2026 1:08 AM"), Claude
    a wall clock ("resets 1am") or a relative one ("Resets in 1h 5m"). Guessing a
    flat half hour for the absolute forms meant retrying into a wall that had not
    lifted yet, which is how a usage limit turned into a crash loop.

    Whatever the provider says, the result is bounded by `RETRY_MAX`. A single lane
    parked for days is worse than one that retries early and fails: agy was observed
    holding a 147.3h backoff while every message in its own logs said the quota reset
    within 2h44m, so the parse was not the thing producing the number. A cap makes the
    damage bounded whatever the cause, and it is what a six-hour unattended run needs.
    """
    return min(RETRY_MAX, _retry_delay_uncapped(text, failures))


def _retry_delay_uncapped(text, failures):
    match = RESET_IN.search(text)
    if match and any(match.groups()):
        hours, minutes, seconds = (int(x or 0) for x in match.groups())
        return max(60, hours * 3600 + minutes * 60 + seconds + 5)
    match = RESET_AT.search(text)
    if match:
        month, day, year, hour, minute, meridiem = match.groups()
        if month:
            try:
                when = datetime.strptime(
                    f'{month} {day} {year or datetime.now().year} {int(hour) % 12 or 12}:{minute} {meridiem.upper()}',
                    '%b %d %Y %I:%M %p')
            except ValueError:
                pass
            else:
                # A reset already in the past means the window has passed; retry
                # soon rather than sitting out the full half hour.
                return max(60, min(86400, (when - datetime.now()).total_seconds() + 30))
        else:
            seconds = _seconds_until(hour, minute, meridiem)
            if seconds is not None:
                return seconds
    match = RESET_CLOCK.search(text)
    if match:
        seconds = _seconds_until(*match.groups())
        if seconds is not None:
            return seconds
    return cooldown(text, failures)

def gate_identity(context):
    digest=hashlib.sha256()
    for path in [ROOT / 'config/GFZE01/units.json',*sorted((ROOT/'config/GFZE01').glob('*/splits.txt'))]:
        if path.exists():
            digest.update(path.read_bytes())
    # HEAD alone misses dirty source, root splits and symbol bindings. Git's
    # binary diff is an exact content delta and avoids rereading every clean TU.
    inputs=['src','include','config/GFZE01','configure.py','tools/fzgx','tools/mwcc_pool.py']
    digest.update(subprocess.check_output(['git','diff','--binary','HEAD','--',*inputs],cwd=ROOT))
    # Accepted split ownership can reference an operator's untracked data TU.
    # Include those dependencies without staging or modifying any of them.
    untracked=subprocess.check_output(['git','ls-files','--others','--exclude-standard','-z','--',
                                       'src','include','config/GFZE01'],cwd=ROOT).split(b'\0')
    for name in sorted(n for n in untracked if n):
        path=ROOT / os.fsdecode(name)
        if path.is_file():
            digest.update(name+b'\0');digest.update(path.read_bytes())
    head=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip()
    return [head,context,digest.hexdigest()]

def gate_pass_is_current(runtime, identity):
    """Reuse only an exact successful identity, never an unchanged failed gate."""
    return (runtime.get('passed_gate') == identity
            and runtime.get('failed_gate') != identity)

def publish(families):
    total,last=verified_progress()
    atomic(STATE,dict(families=families,heartbeat=time.time(),supervisor_pid=os.getpid(),
                       total_verified=total,last_landing=last))

GLYPH = {'working':'●', 'starting':'◌', 'idle':'·', 'rate-limited':'⏳',
         'stalled':'◐', 'error':'✕', 'blocked':'⊘', 'off':'',
         # A retired family is not retrying and will not recover on its own, so it reads
         # as a stop, not a wait. Leaving it to fall through to '!' put a withdrawn model
         # in the same bucket as a crash.
         'unavailable':'⊗'}

def brief(text, limit=120):
    """One short human line from a provider failure blob.

    Provider failures arrive as raw JSON and stream text. That used to be dropped
    into the tooltip verbatim and cut at a flat 300 characters, so it ended
    mid-word ("4.7s\\nve") and buried the one fact that mattered. Classify the
    known failures first; fall back to the first line, cut on a word boundary.
    """
    t = ' '.join(str(text or '').split())
    if not t:
        return ''
    low = t.lower()
    # A diagnostic key alone is not a failure: respect its boolean value.
    if re.search(r'\bverify_ok["\']?\s*:\s*false\b', low):
        return 'hash verification failed - matches rejected'
    if re.search(r'\bover_budget["\']?\s*:\s*true\b', low):
        return 'token/output budget reached'
    known = (
        ('hash verification',     'hash verification failed - matches rejected'),
        ('rate limit',            'provider rate limit'),
        ('quota',                 'provider quota/credit rejection'),
        ('credit',                'provider quota/credit rejection'),
        ('billing',               'provider quota/credit rejection'),
        ('wrong-model',           'provider returned the wrong model'),
        ('interrupted',           'session interrupted by provider'),
        ('went stale',            'no log progress - sessions went stale'),
        ('stale',                 'no log progress - sessions went stale'),
        ('deadline',              'batch hit its time bound'),
        ('timeout',               'batch hit its time bound'),
        ('incomplete',            'batch ended incomplete'),
        ('crash',                 'session crashed'),
        ('transport',             'transport failure'),
        ('no provider',           'no provider returned a result'),
    )
    for needle, human in known:
        if needle in low:
            return human
    if len(t) <= limit:
        return t
    cut = t[:limit].rsplit(' ', 1)[0].rstrip(' ,;:-')
    return (cut or t[:limit]) + '...'

def dur(seconds):
    s = int(max(0, seconds))
    if s < 60:
        return f'{s}s'
    if s < 3600:
        return f'{s // 60}m'
    return f'{s // 3600}h{(s % 3600) // 60:02d}m'

def status():
    config=configuration();state=load(STATE,{})
    now=time.time()
    fresh=now-state.get('heartbeat',0)<30 and pid_alive(state.get('supervisor_pid'))
    result={}
    for family in POLICY:
        if family not in META:      # a provider added to POLICY before its tile
            continue
        name,icon = META[family]
        on=config[family]['enabled']
        data=state.get('families',{}).get(family,{})
        current=(data.get('status','starting') if fresh else 'error') if on else 'off'
        if not on:
            why='stopped by operator'
        elif fresh:
            why=brief(data.get('reason','')) or 'starting constrained provider transport'
        else:
            why='supervisor stopped or heartbeat is stale'
        active=data.get('active',0) if fresh and on else 0
        glyph=GLYPH.get(current,'!')

        # Fixed order, one fact per line: what it is, why, the numbers, what to do.
        lines=[f'{name}  {glyph} {current.upper()}', effective(family)['display'], '', f'Why: {why}']
        checks=data.get('checks') or 0
        done=data.get('completed') or 0
        verified=data.get('verified') or 0
        lines.append('')
        lines.append(f'{checks} checks · {done} done · {verified} verified')
        lines.append(f'Fleet: {state.get("total_verified",0)} verified · last {state.get("last_landing","none")}')
        if active:
            lines.append(f'Sessions: {active} active / {config[family]["parallel"]} allowed')
        failures=data.get('failures') or 0
        if data.get('retry_at',0)>now:
            lines.append(f'Retry in {dur(data["retry_at"]-now)}'
                         + (f' · {failures} failed batch{"es" if failures != 1 else ""}' if failures else ''))
        claims=data.get('claims') or []
        if claims:
            lines.append('')
            lines.append('Work: ' + ', '.join(
                f'{c["module"]}:{c["symbol"]} ({c.get("checks") or 0})' for c in claims[:3]))
            if len(claims) > 3:
                lines.append(f'  +{len(claims) - 3} more')
        if POLICY[family].get('managed'):
            lines.append('')
            lines.append(data.get('surge_reason') or
                         'Surge capacity is fleet-managed from paid-provider availability.')
        lines.append('')
        lines.append('Left: toggle | Right/up: +session | Down: -session | Middle: logs')
        result[family]=dict(on=on,status=current,count=active,icon=icon,name=name,
                           glyph=glyph,why=why,checks=checks,surge_reason=data.get('surge_reason',''),
                           label=icon+glyph+(str(active) if active else ''),
                           tooltip='\n'.join(lines))
    return result

MANAGED = 'Surge capacity is fleet-managed: it comes and goes with paid-provider availability, so it is not manually switchable. Use the paid tiles to change fleet size.'

def control(action,family):
    CACHE.mkdir(parents=True,exist_ok=True)
    if family == 'oc':
        with (CACHE/'control-v3.lock').open('w') as lock:
            fcntl.flock(lock,fcntl.LOCK_EX)
            config=configuration()
            active=[f for f in SURGE if config[f]['enabled']]
            base=sum(c['parallel'] for f,c in config.items() if f not in SURGE and c['enabled'])
            limit=min(OPEN_CODE_ACTIVE_CAP,max(0,FLEET_CAP-base))
            runtime=load(RUNTIME,{})
            families=runtime.get('families',{}) if isinstance(runtime,dict) else {}
            now=time.time()
            ready=[f for f in SURGE if (families.get(f,{}) or {}).get('retry_at',0)<=now]
            if action=='toggle':
                desired=0 if active else limit
            elif action=='scale-up':
                desired=len(active)+1
            elif action=='scale-down':
                desired=max(1,len(active)-1) if active else 0
            else:
                raise ValueError('Unknown OpenCode control action')
            if desired>limit:
                print(f'OpenCode limit is {limit} with current provider controls; global cap is {FLEET_CAP}.')
                return
            if desired>len(ready):
                print('OpenCode sessions are cooling down; refusing to clear provider backoff.')
                return
            enabled=set(ready[:desired])
            for lane in SURGE:
                config[lane]={'enabled':lane in enabled,'parallel':1}
            atomic(CONTROL,config)
            print(json.dumps(config))
        return
    if family not in POLICY:raise ValueError('Unknown provider')
    if POLICY[family].get('managed'):
        print(MANAGED);return
    with (CACHE/'control-v3.lock').open('w') as lock:
        fcntl.flock(lock,fcntl.LOCK_EX)
        config=configuration();value=config[family]
        if action=='toggle':value['enabled']=not value['enabled']
        elif action=='scale-up':
            desired=min(8 if family=='cline' else 4,value['parallel']+1)
            others=sum(c['parallel'] for k,c in config.items() if k!=family and c['enabled'])
            if others+desired>FLEET_CAP:
                print(f'Fleet concurrency cap is {FLEET_CAP}; no extra process launched.');return
            value['parallel']=desired;value['enabled']=True
        elif action=='scale-down':value['parallel']=max(1,value['parallel']-1)
        atomic(CONTROL,config);print(json.dumps(config))

def batch_outcomes(batch):
    """Terminal outcome of every attempt in a batch, straight from the ledger.

    This used to read ``<run dir>/results.json``. Nothing has ever written that
    name: the codex app-server writes ``results.jsonl`` and the bound harnesses
    write no results file at all, so the list was always empty and the
    crash/timeout/WRONG-MODEL check could never fire. A batch whose every session
    died was therefore treated as a clean batch that simply matched nothing, and
    relaunched three seconds later, forever. The ledger records the terminal
    outcome of every attempt regardless of transport.
    """
    return db_rows("SELECT symbol,outcome,checks FROM attempts "
                   "WHERE agent>=? AND agent<? AND ended IS NOT NULL",
                   (batch + '-', batch + '0'))

def paid_unavailable(statuses, config):
    """Paid providers that are not producing work.

    An operator-disabled provider counts. Parking a paid model is a statement
    about capacity, not evidence that it works, and free capacity is still
    wanted in that case. A provider that is merely idle, starting or blocked is
    not down: it is either finishing work or held by a real gate.
    """
    return [f for f in PAID
            if not config[f]['enabled'] or statuses.get(f, {}).get('status') in UNAVAILABLE]

def surge_want(statuses, config, clock):
    """Dwell-timed surge decision, returned with the observed down count.

    Unavailability is accumulated, not wall-clocked. A single five-minute
    outage followed by full health is one five-minute outage, not a ten-minute
    one, so it must not buy capacity; but a provider that keeps lapsing and
    re-limiting does starve the fleet, so its minutes count. Capacity is
    surrendered only after a long healthy stretch, and re-arming then requires
    fresh evidence.
    """
    now = time.time()
    down = paid_unavailable(statuses, config)
    live = len(down) >= 2
    if clock.get('down_since'):          # close out the open down interval
        clock['down_accum'] = clock.get('down_accum', 0) + (now - clock['down_since'])
        clock['down_since'] = 0
    if live:
        clock['down_since'] = now
    if clock.get('surge'):
        if live:
            clock['healthy_since'] = 0
            return down, True
        if not clock.get('healthy_since'):
            clock['healthy_since'] = now
        return down, now - clock['healthy_since'] < SURGE_RETIRE
    if live and clock.get('down_accum', 0) >= SURGE_DELAY:
        return down, True
    return down, False

def apply_surge(statuses, config, clock):
    """Reconcile surge families with the decision. Returns a reason, or None.

    The transition is detected against the committed config, not against the
    dwell bookkeeping, so the file and the decision cannot disagree. Never
    raises the fleet above FLEET_CAP, and never quietly enables fewer than
    requested: a shortfall is reported, once, so the tile can state it.
    """
    owner_policy=load(MODEL_POLICY, {'mode': 'fleet'})
    if model_dispatch_hold(owner_policy) or owner_policy.get('automatic_surge') is False:
        return None
    down, want = surge_want(statuses, config, clock)
    want = bool(want)
    if want == any(config[f]['enabled'] for f in SURGE):
        return None
    # Deep enough copy: the nested per-family dicts are shared by a bare
    # dict(config), and mutating them in place would make the equality guard
    # below compare the object with itself and silently skip the write.
    committed = {f: dict(c) for f, c in config.items()}
    active = 0
    if want:
        base = sum(c['parallel'] for f, c in config.items() if f not in SURGE and c['enabled'])
        room = max(0, FLEET_CAP - base)
        for family in SURGE:
            if not committed[family]['enabled']:
                slots = committed[family]['parallel']
                if room < slots:
                    continue
                committed[family]['enabled'] = True
                room -= slots
        active = sum(1 for f in SURGE if committed[f]['enabled'])
        if not active:
            # Nothing may start under the cap. Say so once instead of failing
            # silently on every tick; re-checked as the paid fleet changes size.
            if clock.get('cap_note'):
                return None
            clock['cap_note'] = True
            return (f'{len(down)}/{len(PAID)} paid providers down; '
                    f'no surge room under fleet cap {FLEET_CAP}.')
    else:
        for family in SURGE:
            committed[family]['enabled'] = False
    if committed == config:
        return None
    clock['surge'] = want
    clock['cap_note'] = False
    atomic(CONTROL, committed)
    up = len(PAID) - len(down)
    if want:
        held = int(clock.get('down_accum', 0))
        note = '' if active == len(SURGE) else f' (fleet cap {FLEET_CAP} reached)'
        return (f'{len(down)}/{len(PAID)} paid providers down for {held}s cumulative; '
                f'surge capacity {active}/{len(SURGE)}{note}.')
    held = int(time.time() - clock.get('healthy_since', time.time()))
    clock['healthy_since'] = 0
    clock['down_accum'] = 0
    return (f'{up}/{len(PAID)} paid providers available for {held}s; surge capacity retired.')

def operator_protected_modules(paths):
    """Do not let source acceptance absorb dirty source or split ownership."""
    modules=set()
    for path in paths:
        parts=Path(path).parts
        if len(parts)>3 and parts[:2]==('src','rel'):
            modules.add(parts[2])
        elif len(parts)>2 and parts[:2]==('src','dol'):
            modules.add('main')
        elif len(parts)>=3 and parts[:2]==('config','GFZE01') and parts[-1]=='splits.txt':
            modules.add(parts[2] if len(parts)>3 else 'main')
    return modules


def operator_protected_symbols(rows, paths):
    """Protect untracked target TUs without blocking untouched data-only imports."""
    owned=set(paths)
    blocked=set()
    for row in rows:
        symbol=row['symbol']
        module=row['module']
        unit=row.get('unit')
        candidates={f'src/dol/{symbol}.c' if module=='main'
                    else f'src/rel/{module}/{symbol}.c'}
        if unit:
            candidates.add(str(Path('src')/unit))
            candidates.add(str(Path(unit)))
        if candidates & owned:
            blocked.add(symbol)
    return blocked


class Job:
    def __init__(self,family,symbols,parallel,gate_passed):
        hold=model_dispatch_hold(load(MODEL_POLICY, {'mode': 'fleet'}))
        if hold:
            raise RuntimeError(hold)
        self.family,self.symbols,self.parallel=family,symbols,parallel
        self.limits=budget_limits(family,parallel,len(symbols))
        self.batch=f'fleet-v2-{family}-{time.time_ns()}'
        self.started=time.time()
        self.deadline=SESSION_TIMEOUT*(-(-len(symbols)//parallel))+600
        self.directory=ROOT/'.fzgx/runs'/self.batch
        record_gate(self.directory,gate_passed,self.started)
        (CACHE/'logs').mkdir(parents=True,exist_ok=True)
        self.logpath=CACHE/'logs'/f'{family}.log'
        self.log=self.logpath.open('a');self.offset=self.log.tell()
        self.log.write(f'\n--- {self.batch} {effective(family)["display"]}: {symbols} ---\n');self.log.flush()
        self.proc=subprocess.Popen(command(family,self.batch,symbols,parallel),cwd=ROOT,
            stdout=self.log,stderr=subprocess.STDOUT,stdin=subprocess.DEVNULL,
            env={**os.environ,'PYTHONUNBUFFERED':'1','FZGX_BOUND_TRANSPORT':'1',
                'FZGX_MAX_MODEL_INPUT_TOKENS':'0','FZGX_MAX_MODEL_OUTPUT_TOKENS':'0'})
    def close(self):
        stop_runner(self.proc);self.log.close()
    def text(self):
        return tail_bytes(self.logpath,start=self.offset)+'\n'+'\n'.join(tail_bytes(p,4000) for p in self.directory.glob('*.log'))

# The publisher (tools/fleet_integrator.py) gates and pushes local main to the
# fork, but it refuses to verify a moving HEAD: every fleet batch commits to main,
# so a gate started mid-fleet keeps hitting "HEAD/branch changed during snapshot
# gate" and nothing is ever published until the daemon is stopped by hand. Rather
# than stop the daemon to drain, tick the publisher from the loop itself: launch it
# in the background between batches, gated so only one runs at a time and never
# more than one attempt per PUBLISH_COOLDOWN. When HEAD is already verified it
# pushes immediately (no gate); when it is not, the background gate races the next
# batch, but the integrator's own HEAD-change check discards an invalidated receipt
# and the next tick retries -- so a quiet moment still drains to the fork without
# an operator stopping the fleet.
PUBLISH_COOLDOWN = 300
_publish_last = [0.0]
_publish_proc: list = [None]

def tick_publisher():
    """Best-effort background publish between batches. Never blocks, never raises."""
    try:
        if _publish_proc[0] is not None:
            if _publish_proc[0].poll() is None:
                return  # already running
            _publish_proc[0] = None
        now = time.time()
        if now - _publish_last[0] < PUBLISH_COOLDOWN:
            return
        _publish_last[0] = now
        _publish_proc[0] = subprocess.Popen(
            [sys.executable, str(ROOT / 'tools' / 'fleet_integrator.py'), 'once'],
            cwd=ROOT, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
            stdin=subprocess.DEVNULL, start_new_session=True)
    except Exception:
        pass

def run():
    global STOP
    CACHE.mkdir(parents=True,exist_ok=True)
    # One supervisor only. A second launch used to die with an unhandled
    # BlockingIOError traceback, which reads like a crash in whatever restarts this and
    # makes a healthy fleet look broken. Refuse cleanly instead, and say why.
    lock=(CACHE/'supervisor-v2.lock').open('w')
    try:
        fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    except OSError:
        print('A fleet supervisor already holds supervisor-v2.lock; not starting a second.',
              flush=True)
        return False
    signal.signal(signal.SIGTERM,lambda *_:set_stop());signal.signal(signal.SIGINT,lambda *_:set_stop())
    if not CONTROL.exists():atomic(CONTROL,defaults())
    from fzgx import api,oracle
    from fzgx.project import Project
    dirty=subprocess.run(['git','diff','HEAD','--name-only','--','src','config/GFZE01'],cwd=ROOT,
                         text=True,capture_output=True,check=True).stdout.splitlines()
    protected_modules=operator_protected_modules(dirty)
    untracked=subprocess.run(['git','ls-files','--others','--exclude-standard','--','src','config/GFZE01'],
                             cwd=ROOT,text=True,capture_output=True,check=True).stdout.splitlines()
    protected_modules.update(operator_protected_modules(path for path in untracked if path.startswith('config/')))
    protected_symbols=operator_protected_symbols(api.inventory(Project()),untracked)
    if protected_modules:
        print('Preserving operator source/split edits; no dispatch in: '+', '.join(sorted(protected_modules)),flush=True)
    jobs={};seen=load(HISTORY,{})
    runtime=load(RUNTIME,{'families':{},'failed_gate':None})
    clock=dict(runtime.get('surge_clock') or {})
    fb=dict(runtime.get('fallback') or {})
    statuses={family:runtime.get('families',{}).get(family,{'status':'starting','reason':'Preparing exact-model transport.'}) for family in POLICY}
    failures={family:statuses[family].get('failures',0) for family in POLICY}
    retries={family:statuses[family].get('retry_at',0) for family in POLICY}
    def persist():
        atomic(RUNTIME,dict(families=statuses,failed_gate=runtime.get('failed_gate'),
                            passed_gate=runtime.get('passed_gate'),surge_clock=clock,fallback=fb))
    try:
        while not STOP and active_runner_pids():
            publish({k:dict(status='blocked',reason='Waiting for previous host to drain.',active=0) for k in POLICY});time.sleep(3)
        if not STOP:
            p=Project()
            for claim in db_rows("SELECT symbol,claimed_by FROM functions WHERE status='claimed' AND substr(claimed_by,1,9)='fleet-v2-'"):
                r=api.release(p,claim['symbol'],'Four-provider recovery: preserve abandoned candidate',agent=claim['claimed_by'],save_only=True)
                if not r.get('ok'):raise RuntimeError('Claim recovery failed: '+json.dumps(r))
        while not STOP:
            config=configuration();now=time.time()
            policy_hold=model_dispatch_hold(load(MODEL_POLICY, {'mode': 'fleet'}))
            for family,job in list(jobs.items()):
                t=telemetry(job.batch,job.limits)
                previous=statuses.get(family,{})
                data=dict(t,batch=job.batch,active=len(t['claims']),status=activity_state(job.proc.poll() is None,len(t['claims']),t['last_event'],job.started,now),
                          surge_reason=previous.get('surge_reason',''),
                          reason='Live bounded provider; claims/checks from shared ledger, not inferred success.')
                stop_reason=None
                # A stop this supervisor asked for is not a provider fault. The
                # batch is SIGTERMed on purpose, so its nonzero exit and the
                # crash rows its sessions leave in the ledger are consequences of
                # our own signal, not of the provider failing. Scoring them as a
                # fault made every resize punish the tile it resized: cline was
                # launched at parallel 8, the control file said 2, the drain
                # aborted 8 sessions at 0% checks in ~8s each and drove failures
                # to 10 with a backoff, so the operator's own change silenced the
                # family. Both drains below are planned, and neither is evidence.
                planned_drain=False
                if policy_hold:
                    planned_drain=True;stop_reason=policy_hold
                elif not config[family]['enabled'] or config[family]['parallel']!=job.parallel:
                    planned_drain=True
                    stop_reason=('Surge capacity retired; draining current work.' if family in SURGE
                                 else 'Operator control changed; draining current work.')
                elif t['verify_ok'] is False:stop_reason='Hash verification failed; saving and holding producers.'
                elif t['over_budget']:stop_reason='Batch log size guard reached; saving best candidate.'
                elif now-max(t['last_event'],job.started)>IDLE_TIMEOUT or now-job.started>job.deadline:stop_reason='Activity/batch deadline; saving best candidate.'
                if stop_reason:
                    data['reason']=stop_reason;publish(dict(statuses,**{family:data}));job.close()
                if job.proc.poll() is not None:
                    job.close();t=telemetry(job.batch,job.limits)
                    text=job.text();rc=job.proc.returncode
                    rows=batch_outcomes(job.batch)
                    broken=rc!=0 or t['verify_ok'] is not True or any(str(r['outcome']).startswith(('crash','timeout','incomplete','WRONG-MODEL')) for r in rows)
                    rate=cooldown(text,0)==1800
                    if planned_drain:
                        # We asked for this stop, so it is neither a rate limit nor
                        # a fault: keep the provider's failure history untouched and
                        # go straight back to work on the next tick. Counting it
                        # would let an operator resize manufacture the backoff it
                        # then has to wait out, and would bury the real reason under
                        # a provider error the provider never reported.
                        delay=3;state='idle';reason=stop_reason
                    elif permanent_fault(text):
                        # The provider no longer offers the pinned model. Retrying cannot
                        # fix that, and a backoff that grows to RETRY_MAX still leaves the
                        # family launching doomed batches, so park it and say why. The
                        # reason carries the provider's own words so the operator can see
                        # which model id to repin without reading a run directory.
                        delay=PERMANENT_RETRY;state='unavailable'
                        reason=f'{POLICY[family]["model"]} is not served by {POLICY[family]["harness"]}: {provider_error_text(text).strip()[:240]}'
                        print(f'{family}: retired, {reason}',flush=True)
                        failures[family]=0
                    elif rate or broken:
                        failures[family]+=1;delay=retry_delay(text,failures[family]);state='rate-limited' if rate else 'error'
                        # A quota failure is the one condition that justifies serving the
                        # declared fallback. An `error` is not: a transport or tool failure
                        # says nothing about quota, and swapping the model on it would hide
                        # the real fault behind a different name.
                        if rate and family in FALLBACK and not fb.get(family):
                            fb[family]={'since':time.time(),'from':POLICY[family]['display'],
                                        'to':FALLBACK[family]['display'],
                                        # When the provider names its own reset time, that is the
                                        # honest expiry for this fallback, not FALLBACK_TTL. A fixed
                                        # short TTL re-probes into a quota wall that is still up:
                                        # agy said "Resets in 2h37m38s", was re-probed after 30
                                        # minutes, hit the same wall, and the second rate limit
                                        # extended the backoff again. Re-probe when the provider
                                        # says the quota is back.
                                        'retry_at':time.time()+retry_delay(text,failures[family])}
                            print(f'{family}: quota exhausted, serving {FALLBACK[family]["display"]}',flush=True)
                            # The quota just measured belongs to the model we are leaving, not
                            # to the one now serving this family. Sitting out its full
                            # rate-limit cooldown would idle the slot for up to 30 minutes for
                            # no reason, so retry promptly under the fallback.
                            delay=3;state='idle';reason=(f'{POLICY[family]["display"]} quota '
                                f'exhausted; serving {FALLBACK[family]["display"]}.')
                        # Report the provider's own words, not the last line of
                        # the stream: that is usually a tool-timing event, which
                        # told the operator nothing about why the batch stopped.
                        detail = provider_error_text(text).strip()
                        if not detail:
                            tail = text.strip().splitlines()
                            detail = tail[-1] if tail else 'Provider request failed.'
                        reason = detail[:300]
                    elif t['verified']:
                        failures[family]=0;delay=3;state='idle';reason='Batch complete with link-verified matches; selecting fresh work.'
                        fb.pop(family,None)
                    else:
                        # A clean batch without a match is not a provider failure.
                        failures[family]=0;delay=3;state='idle';reason='Batch saved best candidates without a match; selecting fresh work.'
                        fb.pop(family,None)
                    retries[family]=time.time()+delay
                    statuses[family]=dict(t,status=state,reason=stop_reason or reason,active=0,claims=[],failures=failures[family],retry_at=retries[family],batch=job.batch)
                    del jobs[family];persist()
                else:statuses[family]=data
            publish(statuses)
            # An expired fallback is dropped here, not merely ignored by `in_fallback`: the
            # rate-limit path re-arms with `not fb.get(family)`, so a stale-but-present
            # record would suppress the re-arm and leave the family probing the primary
            # while still reporting the substitute model. One re-probe per TTL, by design.
            for _fb_family in list(fb):
                _entry = fb[_fb_family] or {}
                _since = _entry.get('since') or 0
                _horizon = _entry.get('retry_at') or (_since + FALLBACK_TTL)
                if _since and time.time() > _horizon:
                    del fb[_fb_family]
                    statuses[_fb_family] = dict(
                        statuses.get(_fb_family, {}),
                        reason=f'Fallback dwell expired; re-probing {POLICY[_fb_family]["display"]}.')
                    print(f'{_fb_family}: fallback dwell expired, re-probing '
                          f'{POLICY[_fb_family]["display"]}', flush=True)
                    persist()
            # Drain local main to the fork between batches (background, cooldown-gated).
            # Fired every tick, not only when idle: with four lanes the fleet holds a
            # batch job continuously, so an `if not jobs` guard meant the publisher
            # never ran and commits piled up unpublished. The integrator is safe to
            # call mid-fleet -- it yields on a busy submit/build lock ("Project
            # submit/build lock is busy; yielding") and discards a receipt if HEAD
            # moved during its gate -- so a quiet compile window still drains to the
            # fork. tick_publisher no-ops within cooldown or while one is in flight.
            tick_publisher()
            # Surge capacity is decided from measured paid-provider state, after
            # this tick's telemetry and before anything is launched.
            note = apply_surge(statuses, config, clock)
            if note:
                for family in SURGE:
                    statuses[family]=dict(statuses[family], surge_reason=note)
                print('surge: ' + note, flush=True)
                persist()
                config = configuration()
            # The 16-target gate is a property of the tree, not of a family. Run it
            # only for a changed identity: with eight families, per-family gating held the
            # build lock and rebuilt eight times to learn the same answer. The
            # scheduling context is a function of the same tree, so it is computed
            # once here too rather than per family.
            context=policy_context()

            identity=gate_identity(context)
            gate_passed=True if gate_pass_is_current(runtime,identity) else None
            # The corpus and the near-miss pool are properties of the tree, not of a
            # family. Both were rebuilt per family: inventory() re-parses 1.7MB of
            # symbols.txt into 20k objects, and the near-miss sweep stat()s every
            # saved body in the ledger. Once per tick, before any rows are marked
            # reserved, also makes the pool independent of what is in flight.
            rows=api.inventory(Project())
            rows=[row for row in rows if row['symbol'] not in protected_symbols]
            near_miss=unsearched_near_misses(rows)
            for family in POLICY:
                if STOP:break
                cfg=config[family]
                if family in jobs:continue
                if not cfg['enabled']:
                    statuses[family]=dict(status='off',reason='Stopped by operator.',active=0,
                                          retry_at=retries[family]);continue
                if time.time()<retries[family]:continue
                if policy_hold:
                    statuses[family]=dict(status='blocked',reason=policy_hold,active=0);continue
                hold=launch_hold(sum(j.parallel for j in jobs.values()),cfg['parallel'])
                if hold:
                    statuses[family]=dict(status='blocked',reason=hold,active=0);continue
                if runtime.get('failed_gate')==identity or gate_passed is False:
                    statuses[family]=dict(status='blocked',reason='Unchanged failing 16-target gate. No repeated builds or model requests.',active=0);continue
                if gate_passed is None:
                    statuses[family]=dict(status='starting',reason='Checking real 16-target hash gate before assignment.',active=0);publish(statuses)
                    with oracle.build_lock('submit.lock',timeout_s=1800),oracle.build_lock():
                        if gate_identity(policy_context())!=identity:
                            statuses[family]=dict(status='starting',reason='Tree changed while waiting for gate ownership; refreshing next tick.',active=0)
                            continue
                        gate_passed=run_gate()
                        if gate_passed and gate_identity(policy_context())!=identity:
                            gate_passed=None
                            statuses[family]=dict(status='starting',reason='Tree changed during gate; not caching stale verification.',active=0)
                            continue
                    if not gate_passed:
                        runtime['passed_gate']=None
                        runtime['failed_gate']=identity
                        statuses[family]=dict(status='blocked',reason='Failed 16-target gate; holding dispatch for this tree identity.',active=0)
                        persist();continue
                    runtime['failed_gate']=None
                    runtime['passed_gate']=identity
                    persist()
                reserved={s for job in jobs.values() for s in job.symbols}
                # Reserve whole existing units too, including assignments whose
                # claim subprocess has not yet committed its SQLite transaction.
                index={r['symbol']:r for r in rows}
                reserved_units={(index[s]['module'],index[s]['unit']) for s in reserved if s in index and index[s].get('unit')}
                for row in rows:
                    if row.get('unit') and (row['module'],row['unit']) in reserved_units:row['status']='claimed'
                # Batch size is the throughput lever for a family that runs one batch at a time.
                # `if family in jobs: continue` means a family can never have two batches in
                # flight, so `parallel` alone does not set its rate: cline at parallel 6 was
                # assigned 12 symbols per batch and delivered 11 sessions/hour against a
                # 6.5% conversion -- the best rate of any family -- because 12 symbols is all
                # it could ever be working on. Measured inter-batch idle is 1% of wall time
                # (median gap 8 min), so the batches are not idling between runs; they are
                # simply small.
                #
                # A bigger batch does not raise concurrency, so it does not risk more parallel
                # sessions against one account than `parallel` already allows -- it just keeps
                # the same number of slots busy for longer. The deadline scales with it
                # (`SESSION_TIMEOUT * ceil(len(symbols)/parallel) + 600`), and the unit-reserve
                # logic below already handles a larger reservation.
                batch_size=max(cfg['parallel']*2, cfg['parallel']*BATCH_WAVES)
                symbols=choose(rows,seen,context,batch_size,reserved,near_miss,family,
                               protected_modules=protected_modules)
                symbols=seed_batch_symbols(symbols)
                if not symbols:
                    carve_capped(rows,near_miss,statuses,family)
                    statuses[family]=dict(status='idle',reason='No fresh eligible target below attempt cap; no blind retries.',active=0);retries[family]=time.time()+30;continue
                admission_tokens=admitted_seed_tokens()
                for symbol in symbols:
                    seen[symbol]=context
                    if symbol in admission_tokens:
                        seen['admission:'+symbol]=admission_tokens[symbol]
                atomic(HISTORY,seen)
                job=Job(family,symbols,cfg['parallel'],gate_passed);jobs[family]=job
                statuses[family]=dict(status='starting',reason=f'Preparing {len(symbols)} distinct assigned functions with {effective(family)["display"]}.',batch=job.batch,active=0,runner_pid=job.proc.pid)
                print(f'{family}: {job.batch}, {symbols}, {effective(family)["display"]}',flush=True)
                persist();publish(statuses)
            time.sleep(3)
    finally:
        for family,job in list(jobs.items()):job.close()
        publish({k:dict(status='off',active=0,reason='Supervisor stopped; bound tools drained.') for k in POLICY})

def set_stop():
    global STOP
    STOP=True

def main():
    args=sys.argv[1:];action=args[0] if args else 'status'
    if action=='status':print(json.dumps(status()))
    elif action=='daemon':run()
    elif action in ('toggle','scale-up','scale-down'):control(action,args[1])
    elif action=='scroll':control('scale-up' if args[2]=='up' else 'scale-down',args[1])
    elif action=='watch':
        family=args[1]
        if family not in POLICY:raise ValueError('Unknown provider')
        subprocess.run([str(Path.home()/'.config/eww/scripts/foot-popup.sh'),f'fzgx-{family}','950','650','tail','-F',str(CACHE/'logs'/f'{family}.log')],check=False)
    elif action=='reset-limits':print('All providers use their pinned models and automatic cooldown; no unsafe quota reset.')
    else:raise SystemExit('Unknown fleet command')

if __name__=='__main__':main()
