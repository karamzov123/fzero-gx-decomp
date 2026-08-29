import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parents[1] / 'tools'))
import natc_diff as d

def sym(ins, score=0, size=None):
    return {'name':'f','match_percent':score,'size':size or len(ins)*4,
            'instructions':[{'instruction': {'formatted': x}} for x in ins]}

def test_rich_classification_exposes_frame_and_registers():
    a=sym(['stwu r1,-0x30(r1)','mflr r0','stmw r27,0x14(r1)','bl foo','blr'])
    b=sym(['stwu r1,-0x20(r1)','mflr r0','stmw r28,0x14(r1)','bl foo','blr'])
    r=d.classify_symbol(a,b)
    assert r['schema_version']==1
    assert r['frame_size']['target']==0x30 and r['frame_size']['candidate']==0x20
    assert r['saved_registers']['target']==['r27','r28','r29','r30','r31']
    assert r['saved_registers']['candidate']==['r28','r29','r30','r31']
    assert r['primary_class'] in {'prologue','regalloc'}
    assert 'allowed_mutation_families' in r

def test_call_lifetime_and_displacement_delta():
    a=sym(['bl foo','mr r4,r3','lwz r3,4(r4)','blr'])
    b=sym(['bl foo','mr r4,r3','lwz r3,8(r4)','blr'])
    r=d.classify_symbol(a,b)
    assert r['call_targets']==['foo']
    assert r['call_return_lifetimes'][0]['instructions']==[1]
    assert r['displacement_deltas'] == [{'instruction':2,'target':4,'candidate':8,'delta':4}]

def test_tu_summary_reports_siblings_and_layout():
    x={'left': {'symbols':[sym(['blr'])]}, 'right': {'symbols':[sym(['blr']),sym(['blr'])]}}
    x['left']['symbols'][0]['name']='a'; x['right']['symbols'][0]['name']='a'; x['right']['symbols'][1]['name']='b'
    r=d.classify_tu(x)
    assert r['missing_in_target']==['b']
    assert r['exact_sibling_regressions']==[]

def test_real_objdiff_instruction_rows_are_not_silently_exact():
    target={'name':'f','match_percent':80,'size':8,
            'instruction_rows':[{'instruction':{'formatted':'li r3,1'}},
                                {'instruction':{'formatted':'blr'}}]}
    candidate={'name':'f','match_percent':50,'size':8,
               'instruction_rows':[{'instruction':{'formatted':'li r3,2'}},
                                   {'instruction':{'formatted':'blr'}}]}
    result=d.classify_symbol(target,candidate)
    assert result['first_divergence']==0
    assert result['primary_class']!='exact'
