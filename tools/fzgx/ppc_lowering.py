"""Repository-owned PowerPC lowering missing from the pinned backend."""
from contextlib import contextmanager
from dataclasses import replace


@contextmanager
def lowering(frame_saves=()):
    from m2c import translate as ir
    from m2c.arch_ppc import PpcArch

    original = PpcArch.parse.__func__
    original_patterns = PpcArch.ir_patterns
    from m2c.evaluate import handle_loadx, make_storex

    def reverse_bytes(value, width):
        # Logical shifts and byte masks preserve zero-extension for lhbrx.
        # Use ordinary unsigned C operations, not no-op compatibility macros.
        value = ir.as_u32(value)
        result = ir.Literal(0, type=ir.Type.u32())
        for offset in range(0, width, 8):
            byte = ir.BinaryOp.uint(value, '>>', ir.Literal(offset))
            byte = ir.BinaryOp.uint(byte, '&', ir.Literal(255))
            byte = ir.BinaryOp.uint(byte, '<<', ir.Literal(width - 8 - offset))
            result = ir.BinaryOp.uint(result, '|', byte)
        return result

    def store_reversed_word(operands):
        store = make_storex(operands, type=ir.Type.u32())
        return replace(store, source=reverse_bytes(store.source, 32))

    carry = ir.Register('carry')
    extended = {'adde', 'addme', 'addze', 'subfe', 'subfme', 'subfze'}
    arithmetic = extended | {'addc', 'addic', 'subfc', 'subfic'}

    def parse(cls, mnemonic, args, meta):
        if mnemonic in ('stwbrx', 'lhbrx'):
            # Reuse ordinary indexed memory dependency/width classification;
            # the pinned backend's width parser does not recognize the br suffix.
            ordinary = 'stwx' if mnemonic == 'stwbrx' else 'lhzx'
            instruction = original(cls, ordinary, args, meta)
            def evaluate_reversed(state, operands):
                if mnemonic == 'stwbrx':
                    state.store_memory(store_reversed_word(operands), operands.reg_ref(0))
                else:
                    value = handle_loadx(operands, type=ir.Type.u16())
                    state.set_reg(operands.reg_ref(0), reverse_bytes(value, 16))
            return replace(instruction, mnemonic=mnemonic, eval_fn=evaluate_reversed)
        if mnemonic == 'mfcr.bits' or mnemonic in ('cror', 'crand', 'crxor', 'crnor', 'crandc', 'crorc'):
            from m2c.instruction import Instruction
            def bit(index):
                return ir.Register(f'cr{index // 4}_' + ('lt', 'gt', 'eq', 'so')[index % 4])
            if mnemonic == 'mfcr.bits':
                selected = [(bit(i), 31 - i) for i in range(32) if args[1].value & (1 << (31 - i))]
                inputs, outputs = [r for r, _ in selected], [args[0]]
                def evaluate_cr(state, operands):
                    value = ir.Literal(0, type=ir.Type.u32())
                    for reg, shift in selected:
                        value = ir.BinaryOp.uint(value, '|', ir.BinaryOp.uint(state.regs[reg], '<<', ir.Literal(shift)))
                    state.set_reg(args[0], value)
            else:
                destination, left, right = [bit(arg.value) for arg in args]
                inputs, outputs = list(dict.fromkeys((left, right))), [destination]
                def evaluate_cr(state, operands):
                    a, b = state.regs[left], state.regs[right]
                    if mnemonic in ('crandc', 'crorc'):
                        b = ir.UnaryOp('!', b, type=ir.Type.s32())
                    op = '&' if mnemonic.startswith('crand') else '^' if mnemonic == 'crxor' else '|'
                    value = ir.BinaryOp.uint(a, op, b)
                    if mnemonic == 'crnor':
                        value = ir.UnaryOp('!', value, type=ir.Type.s32())
                    state.set_reg(destination, value)
            return Instruction(mnemonic, args, meta, inputs, [], outputs, evaluate_cr)
        if mnemonic.endswith('.carry.fictive'):
            base = mnemonic.replace('.carry.fictive', '.fictive')
            instruction = original(cls, base, args, meta)
            def comparison(state, operands):
                if base == 'cmpnez.fictive':
                    ca = ir.BinaryOp.icmp(operands.reg(1), '!=', ir.Literal(0))
                elif base == 'cmple.fictive':
                    ca = ir.BinaryOp.icmp(ir.as_type(operands.reg(2), ir.Type.s32(), False), '<', ir.Literal(0))
                else:
                    ca = ir.Literal(0)
                instruction.eval_fn(state, operands)
                state.set_reg(carry, ca)
            return replace(instruction, mnemonic=mnemonic, outputs=instruction.outputs + [carry], eval_fn=comparison)
        instruction = original(cls, mnemonic, args, meta)
        if mnemonic == 'psq_st':
            address = args[1]
            offset = address.addend_as_literal()
            if (str(args[0]), str(address.base), offset) not in frame_saves:
                def unsupported_store(state, operands):
                    state.write_statement(ir.ExprStmt(ir.ErrorExpr('paired-single data store is not lowered')))
                return replace(instruction, eval_fn=unsupported_store)
        op = mnemonic.rstrip('.')
        if op not in arithmetic | {'sraw', 'srawi'}:
            return instruction
        inputs = list(instruction.inputs)
        outputs = list(instruction.outputs)
        if carry not in outputs:
            outputs.append(carry)
        if op in extended and carry not in inputs:
            inputs.append(carry)

        def evaluate(state, operands):
            left = ir.as_u32(operands.reg(1))
            if op in ('sraw', 'srawi'):
                amount = operands.reg(2) if op == 'sraw' else operands.full_imm(2)
                if op == 'sraw':
                    amount = ir.BinaryOp.uint(amount, '&', ir.Literal(63))
                # XER_CA records whether a negative operand lost any nonzero bits.
                mask = ir.BinaryOp.u64(ir.BinaryOp.u64(ir.Literal(1), '<<', amount), '-', ir.Literal(1))
                lost = ir.BinaryOp.u64(ir.as_u64(left), '&', mask)
                value = ir.BinaryOp.icmp(ir.as_type(left, ir.Type.s32(), False), '<', ir.Literal(0))
                value = ir.BinaryOp(value, '&&', ir.BinaryOp.icmp(lost, '!=', ir.Literal(0)), type=ir.Type.s32())
                instruction.eval_fn(state, operands)
                state.set_reg(carry, value)
                return
            if op in ('addic', 'subfic'):
                right = ir.as_u32(operands.s16_imm(2))
            elif op.endswith('ze'):
                right = ir.Literal(0)
            elif op.endswith('me'):
                right = ir.Literal(0xFFFFFFFF, type=ir.Type.u32())
            else:
                right = ir.as_u32(operands.reg(2))
            incoming = state.regs[carry] if op in extended else ir.Literal(int(op.startswith('sub')))
            if op.startswith('sub'):
                left = ir.UnaryOp('~', left, type=ir.Type.u32())
            total = ir.BinaryOp.u64(ir.as_u64(left), '+', ir.as_u64(right))
            total = ir.BinaryOp.u64(total, '+', ir.as_u64(incoming))
            # Both outputs depend on the pre-instruction operands, including XER_CA.
            ca = ir.as_u32(ir.BinaryOp.u64(total, '>>', ir.Literal(32)))
            value = state.set_reg(operands.reg_ref(0), ir.as_u32(total))
            state.set_reg(carry, ca)
            if mnemonic.endswith('.'):
                for name, comparison in (('eq', '=='), ('lt', '<'), ('gt', '>')):
                    state.set_reg(ir.Register('cr0_' + name),
                                  ir.BinaryOp.icmp(ir.as_type(value, ir.Type.s32(), False), comparison, ir.Literal(0)))
                state.set_reg(ir.Register('cr0_so'), ir.ErrorExpr('XER_SO is not recovered'))

        return replace(instruction, inputs=inputs, outputs=outputs, eval_fn=evaluate)

    PpcArch.parse = classmethod(parse)
    PpcArch.ir_patterns = [type('Carry' + type(pattern).__name__, (type(pattern),),
                               {'replacement': pattern.replacement.replace('.fictive', '.carry.fictive')})()
                          if pattern.parts[-1].split()[0].rstrip('.') in arithmetic else pattern
                          for pattern in original_patterns]
    try:
        yield
    finally:
        PpcArch.parse = classmethod(original)
        PpcArch.ir_patterns = original_patterns
