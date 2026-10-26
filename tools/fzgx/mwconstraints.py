"""Conservative target constraints for captured allocator graphs.

A physical-register map is only a fixed-graph hypothesis: reused registers can
represent unrelated webs. Conflicts require PCode/web alignment, not a broader
permutation search. This module never marks or accepts a function as matched.
"""
import re

from capstone import Cs, CS_ARCH_PPC, CS_MODE_32, CS_MODE_BIG_ENDIAN

from . import mwgraph, fixup_source

REG = re.compile(r'\b[rf]\d+\b')
COMMUTE = {'add', 'add.', 'and', 'and.', 'or', 'or.', 'xor', 'xor.',
           'mullw', 'mullw.', 'fadd', 'fadds', 'fmul', 'fmuls'}


class _Insn:
    """Minimal capstone-compatible row for instructions capstone cannot decode."""
    __slots__ = ('mnemonic', 'op_str')

    def __init__(self, mnemonic, op_str):
        self.mnemonic, self.op_str = mnemonic, op_str


def _recover_undecoded(word):
    """Decode row shapes capstone 5.0.7 is missing, with register operands.

    fcmpo (opcode 63, extended opcode 32) is not in the pinned capstone, yet MWCC
    emits it for every ordered FP compare, so a single fcmpo row silently blocked
    the whole projection pipeline as `unsupported-instruction` (fn_1_156C08,
    finding 361, misread there as a `lis`/`addi` magic pair). fcmpu (extended
    opcode 0) decodes; `none` means genuinely unknown.
    """
    if word >> 26 == 63 and (word >> 1) & 0x3FF == 32:
        return _Insn('fcmpo.' if word & 1 else 'fcmpo',
                     'cr%d, f%d, f%d' % ((word >> 23) & 7, (word >> 16) & 31, (word >> 11) & 31))
    # Gekko paired-single quantized load/store (primary 56/57/60/61). Capstone decodes
    # none of them, so the first `psq_l` of every vector body ended the projection as
    # `unsupported-instruction` before any register could be bound (fn_1_1FDB0 row 3).
    # Only the memory form matters here: it names both the FPR and the base GPR.
    opcode = word >> 26
    if opcode in (56, 57, 60, 61):
        rt, ra, qr = (word >> 21) & 31, (word >> 16) & 31, (word >> 12) & 7
        disp = word & 0xFFFF
        if disp & 0x8000:
            disp -= 0x10000
        if opcode in (56, 60):
            return _Insn('psq_l' if opcode == 56 else 'psq_st',
                         'f%d, %d(r%d), %d, qr%d' % (rt, disp, ra, (word >> 15) & 1, qr))
        return _Insn('psq_lu' if opcode == 57 else 'psq_stu',
                     'f%d, %d(r%d), qr%d' % (rt, disp, ra, qr))
    if opcode == 4:
        return _paired_single(word)
    return None


# Gekko paired-single arithmetic (primary opcode 4, A-form: frD in 21-25, frA in 16-20,
# frC in 11-15, frB in 6-10, extended opcode in 1-5). Capstone has no paired-single
# decoder and reports several of these words as unrelated Altivec operations
# (`ps_sub` -> `vmsumshm`), which silently dropped every paired-single register from the
# constraint set. `fields` lists the operand positions the form actually uses, in the
# order they are emitted; a field that the form leaves as a structural constant is not
# emitted, because binding it would claim two unrelated webs share a register.
_PS_FORMS = {
    8:  ('ps_mr', 'DC'),
    10: ('ps_sum0', 'DACB'),
    11: ('ps_sum1', 'DACB'),
    12: ('ps_muls0', 'DAB'),
    13: ('ps_muls1', 'DAB'),
    14: ('ps_madds0', 'DACB'),
    15: ('ps_madds1', 'DACB'),
    18: ('ps_div', 'DAC'),
    20: ('ps_sub', 'DAC'),
    21: ('ps_add', 'DAC'),
    23: ('ps_sel', 'DACB'),
    24: ('ps_res', 'DAB'),
    25: ('ps_mul', 'DAB'),
    26: ('ps_rsqrte', 'DAB'),
    29: ('ps_madd', 'DACB'),
    30: ('ps_msub', 'DACB'),
    31: ('ps_nmadd', 'DACB'),
}
_PS_MERGE = {16: 'ps_merge00', 18: 'ps_merge10', 19: 'ps_merge11'}


def _paired_single(word):
    """One opcode-4 row with its real mnemonic and used operand fields."""
    xo = (word >> 1) & 0x1F
    if xo == 16:
        name = _PS_MERGE.get((word >> 6) & 0x1F, 'ps_merge%02d' % ((word >> 6) & 0x1F))
        fields = 'DAC'
    else:
        name, fields = _PS_FORMS.get(xo, ('ps_xo%02d' % xo, 'DACB'))
    value = {'D': (word >> 21) & 31, 'A': (word >> 16) & 31,
             'C': (word >> 11) & 31, 'B': (word >> 6) & 31}
    return _Insn(name, ', '.join('f%d' % value[f] for f in fields))


def _consistent_hard_map(hard):
    """Injective name map satisfying every *hard* (non-commutative) binding, or None.

    `hard` maps one of our register names to the retail names it was bound to at a
    non-commutative operand position. Such a binding is order-fixed, so a solution must
    satisfy all of them at once: exactly one retail name per our-name, used at most once.
    Solved as bipartite matching, deterministically (candidates visited in sorted order).

    None means the two objects are not related by any register permutation: our register
    naming genuinely does not correspond to retail's. Given instruction shapes already match,
    that is not a naming artefact to be aligned away -- it means the two objects assign
    registers differently because the *values* differ (one value live across a span retail
    splits into several, or the reverse). None is the conservative answer; claiming a map
    that no row actually satisfies would send someone to align two different programs.
    """
    if any(len(v) != 1 for v in hard.values()):
        return None
    forced = {k: next(iter(v)) for k, v in hard.items()}
    if len(set(forced.values())) != len(forced):
        return None
    return forced


def target_mapping(target, ours):
    md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN)
    md.skipdata = True
    def decode(words):
        rows = list(md.disasm(b''.join(w.to_bytes(4, 'big') for w in words), 0))
        if len(rows) == len(words):
            # Paired-single rows are replaced whether or not capstone produced a row for
            # them: its Altivec decode is a different instruction with different registers.
            rows = [(_recover_undecoded(w) or row)
                    if row.mnemonic == '.byte' or w >> 26 in (4, 56, 57, 60, 61) else row
                    for row, w in zip(rows, words)]
        return rows
    if not target or not ours or len(target) != len(ours):
        return {'status': 'instruction-shape'}
    t, o = decode(target), decode(ours)
    if len(t) != len(target) or len(o) != len(ours):
        return {'status': 'unsupported-instruction'}
    domains, alternatives, incompatible, hard = {}, [], [], {}
    def bind(left, right, commutative=False):
        for a, b in zip(left, right):
            domains.setdefault(a, set()).add(b)
            if not commutative:
                hard.setdefault(a, set()).add(b)
    for row, (a, b) in enumerate(zip(t, o)):
        # Capstone lacks Gekko paired-single save/restore instructions. Decode
        # their opcode and base register directly; other unknowns stay unknown.
        if a.mnemonic == '.byte' or b.mnemonic == '.byte':
            if all(w >> 26 in (56, 60) and (w >> 16) & 31 == 1 for w in (target[row], ours[row])):
                continue
            return {'status': 'unsupported-instruction', 'rows': [row]}
        # Prologue saves describe used-register ranges, not virtual values.
        if '(r1)' in a.op_str + b.op_str or a.mnemonic in ('stmw', 'lmw'):
            continue
        if a.mnemonic != b.mnemonic or REG.sub('R', a.op_str) != REG.sub('R', b.op_str):
            incompatible.append(row)
            continue
        left, right = REG.findall(b.op_str), REG.findall(a.op_str)
        if len(left) != len(right):
            incompatible.append(row)
        elif a.mnemonic in COMMUTE and len(left) == 3:
            bind(left[:1], right[:1])
            alternatives.append((row, left[1:], right[1:]))
        else:
            bind(left, right)
    conflicts = {r: sorted(v) for r, v in domains.items() if len(v) != 1}
    if conflicts or incompatible:
        # A flat register-name map cannot express register *reuse*: one name in our object can
        # cover several distinct value webs in retail. Say which of the two very different
        # problems this is, because they need opposite responses:
        #
        #   commutative-only  every hard (order-fixed) binding agrees and is injective; the
        #                     only disagreement is operand order on commutative instructions.
        #                     The objects are then related by a register permutation and
        #                     building web alignment would be worth doing.
        #   structural        the hard bindings themselves disagree, so no register permutation
        #                     relates the two objects. Instruction shapes already match, so the
        #                     difference is in the *values*: a value live across a span retail
        #                     splits, or the reverse. The conflict is evidence of a source defect
        #                     to fix first -- aligning the webs would mean aligning two different
        #                     programs.
        #
        # Neither is guessed: the label is earned only by a map that satisfies every hard row.
        rename = _consistent_hard_map(hard)
        return {'status': 'needs-web-alignment', 'rows': incompatible, 'conflicts': conflicts,
                # A rename satisfying the compatible rows is not a complete
                # operand-order witness when other rows change opcode/immediates
                # or instruction position. Keep those source/selection defects
                # out of the commutative-only allocator class.
                'subkind': 'instruction-shape' if incompatible else
                           'commutative-only' if rename else 'structural',
                'hard_conflicts': {k: sorted(v) for k, v in hard.items() if len(v) != 1},
                'consistent_rename': rename if not incompatible else None}
    mapping = {r: next(iter(v)) for r, v in domains.items()}
    pending = alternatives[:]
    swaps = []
    while pending:
        changed, rest = False, []
        for row, left, right in pending:
            valid = [(swapped, candidate) for swapped, candidate in ((False, right), (True, right[::-1]))
                     if all(a not in mapping or mapping[a] == b for a, b in zip(left, candidate))
                     and (left[0] != left[1] or candidate[0] == candidate[1])]
            if not valid:
                return {'status': 'needs-web-alignment', 'rows': [row]}
            if len(valid) == 2 and right[0] != right[1]:
                rest.append((row, left, right))
                continue
            swapped, candidate = valid[0]
            mapping.update(zip(left, candidate))
            if swapped:
                swaps.append(row)
            changed = True
        if not changed:
            return {'status': 'ambiguous-operand-order', 'rows': [v[0] for v in rest]}
        pending = rest
    return {'status': 'fixed-graph-hypothesis', 'mapping': mapping,
            'operand_order_rows': sorted(swaps)}


def constrain(captures, mapping):
    reports = []
    for capture in captures:
        before, after = capture['before'], capture['after']
        if mwgraph.simplify(before) != before['simplify_order']:
            reports.append({'status': 'unsupported-simplify'})
            continue
        prefix = 'r' if before['register_class'] == 'gpr' else 'f'
        active = set(before['simplify_order'])
        desired = {n['virtual_register']: int(mapping.get(prefix + str(n['physical_register']),
                    prefix + str(n['physical_register']))[1:]) for n in after['nodes']
                   if n['virtual_register'] in active}
        if any(c < 0 for c in desired.values()):
            reports.append({'status': 'spill'})
            continue
        order = mwgraph.selection_order(before, desired)
        reports.append({'status': 'selection-witness' if order is not None else 'no-constructed-witness',
                        'register_class': before['register_class'], 'desired': desired, 'order': order})
    return reports


def declaration_projection(body, name, capture, witness):
    """Predict one declaration edit only if its fixed graph yields target colors.

    Frontend parameter positions and synthesized temporaries are immovable in
    this edit class. An arbitrary selection witness cannot reorder them in C.
    Initializers are excluded because moving them can change program behavior.
    """
    if witness['status'] != 'selection-witness':
        return None
    span = fixup_source._function_body_span(body, name)
    if span is None:
        return None
    locals_ = fixup_source._locals(body, span)
    if any(fixup_source._init_of(body[a:b]) for a, b, *_ in locals_):
        return None
    nodes = capture['before']['nodes']
    by_name = {}
    for n in nodes:
        if n.get('name'):
            by_name.setdefault(n['name'], []).append(n['virtual_register'])
    movable = [(i, by_name[n][0]) for i, (_, _, _, n, dims) in enumerate(locals_)
               if not dims and len(by_name.get(n, [])) == 1]
    if len(movable) < 2:
        return None
    # MWCC creates leading locals in reverse declaration order. Verify this
    # stratum before projecting any change into its virtual-register slots.
    if [v for _, v in movable] != sorted((v for _, v in movable), reverse=True):
        return None
    rank = {r: i for i, r in enumerate(witness['order'])}
    if any(v not in rank for _, v in movable):
        return None
    desired_order = sorted(movable, key=lambda item: rank[item[1]])
    slots = sorted((v for _, v in movable), reverse=True)
    ranks = {v: slot for (_, v), slot in zip(desired_order, slots)}
    before = capture['before']
    order = mwgraph.simplify(before, ranks)
    if order is None:
        return None
    colors = mwgraph.replay(before, order)
    if any(colors[r] != c for r, c in witness['desired'].items()):
        return None
    replacements = {i: locals_[j] for (i, _), (j, _) in zip(movable, desired_order)}
    text, cursor = [], 0
    for i, (a, b, *_) in enumerate(locals_):
        text.append(body[cursor:a])
        x, y, *_ = replacements.get(i, locals_[i])
        text.append(body[x:y])
        cursor = b
    text.append(body[cursor:])
    candidate = ''.join(text)
    return candidate if candidate != body else None
