import json, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parents[1] / 'tools'))
from natc_oracle import build_oracle
from natc_mutations import apply_mutation, MutationError
from natc_shape_index import ShapeIndex, extract_features
from natc_hypothesis_ledger import Ledger

def test_oracle_is_ranked_and_flags_contradiction():
 r=build_oracle(symbol='x', xref={'definitions':[{'provenance':'retail'},{'provenance':'other'}], 'accesses':[{'width':4,'signed':True},{'width':8,'signed':False}]})
 assert r['schema_version']==1 and r['contradictions']
 assert all('supporting_facts' in c and 'contradicting_facts' in c for c in r['candidates'])

def test_oracle_accepts_real_find_xrefs_shape():
 r=build_oracle(symbol='x', xref={
   'definition': {'object':'build/x.o','section':'.sbss','size':4,'bind':1},
   'alternate_defs': 2,
   'globals_referenced': [{'symbol':'g','types':['R_PPC_EMB_SDA21'],
                           'section':'.sbss','size':4,'bind':1}],
   'reloc_histogram': {'R_PPC_EMB_SDA21': 1},
 })
 assert r['authoritative_definitions'][0]['object']=='build/x.o'
 assert r['constraints']['relocation_kinds']==['R_PPC_EMB_SDA21']
 assert r['constraints']['writable'] is True

def test_mutation_exactly_one():
 assert apply_mutation('int x;','int x;','int','long')=='long x;'
 for src in ('int x; int y;','int y;'):
  try: apply_mutation(src,'x','int','long'); assert False
  except MutationError: pass

def test_shape_index_roundtrip(tmp_path):
 i=ShapeIndex(); ident=i.add(source_path='a.c',line=4,compiler={'id':'mwcc'},features=extract_features('stwu r1,-16(r1)\nbl foo'))
 p=tmp_path/'i.json'; i.dump(p); assert i.load(p).query({'frame_size':16})[0]['id']==ident

def test_ledger_deduplicates(tmp_path):
 l=Ledger(tmp_path/'x.sqlite'); kw=dict(unit='u',symbol='s',mutation_class='x',source_id='a',context_id='b')
 assert l.record('id',**kw) and not l.record('id',**kw); assert l.get('id')[0]=='id'; l.close()
