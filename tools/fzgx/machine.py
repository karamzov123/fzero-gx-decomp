"""PowerPC/CodeWarrior decompilation with owned type context and the existing oracle."""
from __future__ import annotations

import io
import json
import re
import subprocess
from contextlib import contextmanager, redirect_stdout, redirect_stderr

from .project import ROOT, STATE_DIR
from .sdkimport import declarations, masked
from .signatures import recovered, propagate, split_params


_worker_project = None


def generate_batch(rows):
    """Keep the backend's mutable IR adapters isolated in worker processes."""
    from .project import Project
    from . import lift
    global _worker_project
    if _worker_project is None:
        _worker_project = Project()
    p, result = _worker_project, []
    for symbol, module, size in rows:
        name = symbol.split(':')[-1]
        variants, error = [], ''
        try:
            draft = lift.lift_total(p, module, name, max_ins=max(1200, size // 4))
            for descending in (False, True):
                text, error = generate(p, module, name, draft=draft, descending=descending)
                if text and text not in variants:
                    variants.append(text)
                elif error:
                    break
        except Exception as exc:
            error = str(exc)
        result.append((symbol, size, variants, error))
    return result


def _expand(text, name, emit):
    """Expand balanced generated expressions, including nested field accesses."""
    while match := re.search(r'\b' + name + r'\(', text):
        start = match.end()
        depth, end = 1, start
        while end < len(text) and depth:
            depth += (text[end] == '(') - (text[end] == ')')
            end += 1
        if depth:
            raise ValueError(f'unclosed {name}')
        replacement = emit(split_params(text[start:end - 1]))
        text = text[:match.start()] + replacement + text[end:]
    return text


def structure_loops(text):
    """A single back edge to a guarded block is a while loop, not a C goto header."""
    while True:
        code = masked(text)
        changed = False
        for match in re.finditer(r'(?m)^(\w+):\s*\n([ \t]*)if\s*\(', code):
            label, indent = match[1], match[2]
            if len(re.findall(r'\bgoto\s+' + label + r'\s*;', code)) != 1:
                continue
            start, depth = match.end(), 1
            end = start
            while end < len(code) and depth:
                depth += (code[end] == '(') - (code[end] == ')')
                end += 1
            opening = re.match(r'\s*\{', code[end:])
            if not opening:
                continue
            body_start = end + opening.end()
            closing, depth = body_start, 1
            while closing < len(code) and depth:
                depth += (code[closing] == '{') - (code[closing] == '}')
                closing += 1
            tail = re.search(r'\bgoto\s+' + label + r'\s*;\s*$', code[body_start:closing - 1])
            if not tail or re.match(r'\s*else\b', code[closing:]):
                continue
            text = (text[:match.start()] + indent + 'while (' + text[start:end]
                    + text[end:body_start] + text[body_start:body_start + tail.start()]
                    + indent + '}' + text[closing:])
            changed = True
            break
        if not changed:
            return text


@contextmanager
def _mwcc_formatting(signatures, stack, copy_sites, copy_sizes, float_calls, absolute_refs):
    """Retain machine-width accesses when inference cannot name a compatible C field."""
    from m2c import translate as ir
    from m2c import evaluate
    from m2c.arch_ppc import PpcArch
    from .oracle import abs_symbols
    absolute_names = {address: name for name, address in abs_symbols().items()}
    saved = {cls: cls.format for cls in (ir.StructAccess, ir.Cast, ir.FuncCall, ir.BinaryOp, ir.ArrayAccess, ir.AddressOf)}
    assignment = ir.format_assignment
    original_deref = evaluate.deref
    original_call = ir.NodeState.make_function_call
    original_abi = PpcArch.function_abi
    original_switch = ir.SwitchControl.from_expr
    original_return = PpcArch.function_return
    original_stack_var = ir.StackInfo.get_stack_var

    def stack_var(self, location, *, store):
        for base, (_, length, _) in stack.items():
            if base <= location < base + length:
                root = original_stack_var(self, base, store=False)
                if isinstance(root, ir.LocalVar):
                    self.add_local_var(root)
                    if location == base:
                        return root
                    return ir.StructAccess(ir.AddressOf(root, root.type.reference()), location - base,
                                           1, None, self, ir.Type.any_field())
        result = original_stack_var(self, location, store=store)
        # A callee can initialize a local through an escaped stack pointer. Such
        # locals have reads without an explicit store in the caller's IR.
        if isinstance(result, ir.LocalVar) and not self.in_callee_save_reg_region(location):
            self.add_local_var(result)
        return result

    def function_return(expr):
        result = original_return(expr)
        if expr.type.is_int() and expr.type.get_size_bytes() == 8:
            result[ir.Register('r3')] = ir.as_u32(ir.BinaryOp.u64(ir.as_u64(expr), '>>', ir.Literal(32)))
        return result

    def switch(expr, num_cases):
        result = original_switch(expr, num_cases)
        value = ir.early_unwrap(expr)
        while isinstance(value, ir.Cast):
            value = ir.early_unwrap(value.expr)
        if result.jump_table is None and isinstance(value, ir.ArrayAccess):
            pointer = ir.early_unwrap(value.ptr)
            table = ir.early_unwrap(pointer.expr) if isinstance(pointer, ir.AddressOf) else pointer
            if isinstance(table, ir.GlobalSymbol) and table.asm_data_entry and table.asm_data_entry.is_jtbl:
                return ir.SwitchControl(value.index, num_cases, table, 0)
        return result

    def make_call(self, target, outputs):
        line = self.regs.current_instr_ref().instruction.meta.lineno
        def pair(hi, lo):
            return ir.BinaryOp.u64(ir.BinaryOp.u64(ir.as_u64(ir.as_u32(hi)), '<<', ir.Literal(32)),
                                   '|', ir.as_u64(ir.as_u32(lo)))

        def abi(signature, likely, *, for_call):
            if for_call and signature.is_variadic and float_calls.get(line) is False:
                likely = {r: used for r, used in likely.items() if not r.register_name.startswith('f')}
            if for_call and signature.params_known and any(p.type.is_int() and p.type.get_size_bytes() == 8 for p in signature.params):
                slots, gpr, fpr, offset = [], 3, 1, 0
                for i, param in enumerate(signature.params):
                    typ, reg, stack_offset = param.type.decay(), None, None
                    wide = typ.is_int() and typ.get_size_bytes() == 8
                    if typ.is_float() and fpr <= 8:
                        reg = ir.Register(f'f{fpr}'); fpr += 1
                    elif not typ.is_float():
                        if wide:
                            gpr += (gpr % 2 == 0)
                        if gpr + int(wide) <= 10:
                            reg = ir.Register(f'r{gpr}')
                            if wide:
                                reg, stack_offset = None, -(i + 1) * 8
                                self.subroutine_args[stack_offset] = pair(self.regs[ir.Register(f'r{gpr}')],
                                                                         self.regs[ir.Register(f'r{gpr + 1}')])
                            gpr += 2 if wide else 1
                    if reg is None and stack_offset is None:
                        size = typ.get_size_bytes() or 4
                        offset = (offset + min(size, 8) - 1) // min(size, 8) * min(size, 8)
                        stack_offset, offset = offset, offset + size
                        if wide and stack_offset in self.subroutine_args and stack_offset + 4 in self.subroutine_args:
                            self.subroutine_args[stack_offset] = pair(self.subroutine_args[stack_offset],
                                                                     self.subroutine_args.pop(stack_offset + 4))
                    slots.append(ir.AbiArgSlot(ir.ArgLoc(stack_offset, i, reg), typ, name=param.name))
                possible = original_abi(signature, likely, for_call=for_call).possible_slots
                possible = [slot for slot in possible if int(slot.loc.reg.register_name[1:]) >=
                            (fpr if slot.loc.reg.register_name.startswith('f') else gpr)]
                return ir.Abi(slots, possible)
            return original_abi(signature, likely, for_call=for_call)
        PpcArch.function_abi = staticmethod(abi)
        try:
            return original_call(self, target, outputs)
        finally:
            PpcArch.function_abi = staticmethod(original_abi)

    def deref(arg, regs, info, *, size, store=False):
        if isinstance(arg, ir.AddressMode) and info.is_stack_reg(arg.base):
            for base, (typ, length, name) in stack.items():
                if base <= arg.offset and arg.offset + size <= base + length:
                    root = info.get_stack_var(base, store=False)
                    if isinstance(root, ir.LocalVar):
                        info.add_local_var(root)
                        return ir.StructAccess(ir.AddressOf(root, root.type.reference()), arg.offset - base,
                                               size, None, info, ir.Type.any_field())
        return original_deref(arg, regs, info, size=size, store=store)

    def stack_offset(expr):
        expr = ir.late_unwrap(expr)
        if isinstance(expr, ir.Cast):
            return stack_offset(expr.expr)
        if isinstance(expr, ir.AddressOf) and isinstance(expr.expr, ir.LocalVar):
            return expr.expr.value
        if isinstance(expr, ir.BinaryOp) and expr.op in ('+', '-'):
            base = stack_offset(expr.left)
            right = ir.late_unwrap(expr.right)
            if base is not None and isinstance(right, ir.Literal):
                return base + right.value * (1 if expr.op == '+' else -1)
        return None

    def access(self, fmt):
        path = self.late_field_path()
        _, field_type, _ = self.struct_var.type.get_deref_field(self.offset, target_size=self.target_size)
        incompatible = (field_type.is_pointer_or_array() != self.type.is_pointer_or_array()
                        or field_type.is_float() != self.type.is_float()
                        or field_type.get_size_bytes() != self.type.get_size_bytes())
        if path is None or path == [0] or incompatible:
            return f'(*({ir.Type.ptr(self.type).format(fmt)})((u8 *)({self.struct_var.format(fmt)}) + {self.offset}))'
        return saved[ir.StructAccess](self, fmt)

    def cast(self, fmt):
        source = self.expr.type
        expr = ir.late_unwrap(self.expr)
        if self.type.is_pointer() and isinstance(expr, ir.Literal) and expr.value in absolute_names:
            name = absolute_names[expr.value]
            absolute_refs.add(name)
            return f'({self.type.format(fmt)})({name})'
        if source.is_struct() and not self.type.is_struct() and isinstance(expr, (ir.StructAccess, ir.ArrayAccess, ir.LocalVar, ir.GlobalSymbol)):
            return f'(*({self.type.format(fmt)} *)&({expr.format(fmt)}))'
        if self.reinterpret and source.is_float() != self.type.is_float():
            if isinstance(expr, (ir.GlobalSymbol, ir.StructAccess, ir.ArrayAccess, ir.LocalVar)):
                return f'(*({self.type.format(fmt)} *)&({expr.format(fmt)}))'
        if source.is_pointer_or_array() != self.type.is_pointer_or_array() and not source.is_float() and not self.type.is_float():
            return f'(({self.type.format(fmt)})({self.expr.format(fmt)}))'
        return saved[ir.Cast](self, fmt)

    def call(self, fmt):
        target = ir.late_unwrap(self.function)
        sig = target.type.get_function_pointer_signature()
        original = target
        while isinstance(original, ir.Cast):
            original = ir.late_unwrap(original.expr)
        known = signatures.get(original.c_symbol_name) if isinstance(original, ir.GlobalSymbol) else None
        known = known or signatures.get(target.format(fmt))
        # A direct, constant-length memset proves backing storage even when
        # individual fields (or an interior matrix pointer) have no inferred
        # aggregate type. copy_context bounds the range by the retail frame.
        # stack_offset deliberately rejects masks/alignment expressions: their
        # pointee extent is still unknown and must pass the escaped-local guard.
        callee = ir.late_unwrap(original.expr) if isinstance(original, ir.AddressOf) else original
        if isinstance(callee, ir.GlobalSymbol) and callee.c_symbol_name == 'memset' and len(self.args) == 3:
            offset, size = stack_offset(self.args[0]), ir.late_unwrap(self.args[2])
            while isinstance(size, ir.Cast) and size.type.is_int() and (size.type.get_size_bytes() or 0) >= 4:
                size = ir.late_unwrap(size.expr)
            if offset is not None and offset >= 8 and isinstance(size, ir.Literal) and size.value > 0:
                copy_sites[offset] = max(copy_sites.get(offset, 0), size.value)
        if target.format(fmt) == 'M2C_STRUCT_COPY' and len(self.args) == 3:
            offset, size = stack_offset(self.args[0]), ir.late_unwrap(self.args[2])
            if isinstance(size, ir.Literal) and size.value > 0 and size.value % 4 == 0:
                copy_sizes.add(size.value)
                if offset is not None:
                    copy_sites[offset] = max(copy_sites.get(offset, 0), size.value)
            if offset in stack and isinstance(size, ir.Literal) and size.value == stack[offset][1]:
                typ, _, name = stack[offset]
                return f'{name} = *(const {typ} *)({self.args[1].format(fmt)})'
            if isinstance(size, ir.Literal) and size.value in copy_sizes:
                typ = f'struct FzgxCopy_{size.value}'
                return f'*({typ} *)({self.args[0].format(fmt)}) = *(const {typ} *)({self.args[1].format(fmt)})'
        if sig and sig.params is not None:
            args = []
            for i, arg in enumerate(self.args):
                text = ir.format_expr(arg, fmt)
                typ = known.args[i] if known and known.args is not None and i < len(known.args) else None
                if typ and '*' in typ:
                    text = f'({typ})({text})'
                elif i < len(sig.params) and sig.params[i].type.is_pointer():
                    text = f'({sig.params[i].type.format(fmt)})({text})'
                elif i < len(sig.params) and not sig.params[i].type.is_struct():
                    text = f'({sig.params[i].type.format(fmt)})({text})'
                args.append(text)
            return f'{target.format(fmt)}({", ".join(args)})'
        return saved[ir.FuncCall](self, fmt)

    def binary(self, fmt):
        left, right = ir.late_unwrap(self.left), ir.late_unwrap(self.right)
        lp, rp = left.type.is_pointer_or_array(), right.type.is_pointer_or_array()
        # Scaled C indexing is represented by ArrayAccess. Remaining address
        # arithmetic in this IR retains the instruction's byte displacement.
        if self.op in ('+', '-') and (lp or rp):
            l, r = self.left.format(fmt), self.right.format(fmt)
            if lp and not rp:
                value = f'((u8 *)({l}) {self.op} {r})'
                return value if self.type.is_pointer_or_array() else f'(({self.type.format(fmt)})({value}))'
            if rp and not lp and self.op == '+':
                value = f'({l} + (u8 *)({r}))'
                return value if self.type.is_pointer_or_array() else f'(({self.type.format(fmt)})({value}))'
            return f'((s32)({l}) {self.op} (s32)({r}))'
        return saved[ir.BinaryOp](self, fmt)

    def array(self, fmt):
        target = self.ptr.type.get_pointer_target()
        if target is None:
            # An address held in an integer register still needs a pointer cast
            # at its memory use; C cannot index the integer expression itself.
            return f'(({ir.Type.ptr(self.type).format(fmt)})({self.ptr.format(fmt)}))[{ir.format_expr(self.index, fmt)}]'
        if target and target.format(fmt) != self.type.format(fmt):
            size = target.get_size_bytes()
            if size:
                return f'(*({ir.Type.ptr(self.type).format(fmt)})((u8 *)({self.ptr.format(fmt)}) + ({self.index.format(fmt)}) * {size}))'
        return f'({self.ptr.format(fmt)})[{ir.format_expr(self.index, fmt)}]'

    def address(self, fmt):
        if isinstance(self.expr, ir.StructAccess):
            return f'(({self.type.format(fmt)})((u8 *)({self.expr.struct_var.format(fmt)}) + {self.expr.offset}))'
        return saved[ir.AddressOf](self, fmt)

    def assign(lhs, rhs, fmt):
        if lhs.type.is_pointer() or (rhs.type.is_pointer_or_array() and not lhs.type.is_pointer_or_array()):
            return f'{lhs.format(fmt)} = ({lhs.type.format(fmt)})({ir.format_expr(rhs, fmt)});'
        return assignment(lhs, rhs, fmt)

    ir.StructAccess.format, ir.Cast.format, ir.FuncCall.format = access, cast, call
    ir.BinaryOp.format, ir.ArrayAccess.format = binary, array
    ir.AddressOf.format = address
    ir.format_assignment = assign
    evaluate.deref = deref
    ir.NodeState.make_function_call = make_call
    ir.SwitchControl.from_expr = staticmethod(switch)
    PpcArch.function_return = staticmethod(function_return)
    ir.StackInfo.get_stack_var = stack_var
    try:
        yield
    finally:
        for cls, method in saved.items():
            cls.format = method
        ir.format_assignment = assignment
        evaluate.deref = original_deref
        ir.NodeState.make_function_call = original_call
        ir.SwitchControl.from_expr = staticmethod(original_switch)
        PpcArch.function_return = staticmethod(original_return)
        ir.StackInfo.get_stack_var = original_stack_var


def stack_context(p, fn, draft):
    """Transport aggregate stack objects already constrained by recovered call signatures."""
    index = recovered(p)
    frame = re.search(r'\bstwu r1, -(0x[0-9a-f]+|\d+)\(r1\)', '\n'.join(fn.asm))
    if not frame:
        return '', {}
    size = int(frame[1], 0)
    stack = {}
    for match in re.finditer(r'^\s+([\w ]+) loc_([0-9A-F]+);$', draft or '', re.M):
        typ, offset = match[1].strip(), int(match[2], 16)
        layout = index.layout(typ + ' *')
        if layout and layout[1] > 8 and offset + layout[1] <= size:
            stack[offset] = (typ, layout[1], f'loc_{offset:X}')
    if not stack:
        return '', {}
    cursor, fields = 0, []
    for offset, (typ, length, name) in sorted(stack.items()):
        if offset < cursor:
            return '', {}
        if offset > cursor:
            fields.append(f'char unk_{cursor:X}[{offset - cursor}];')
        fields.append(f'{typ} {name};')
        cursor = offset + length
    if cursor < size:
        fields.append(f'char unk_{cursor:X}[{size - cursor}];')
    return f'struct _m2c_stack_{fn.symbol.name} {{ ' + ' '.join(fields) + ' };\n', stack


def copy_context(fn, stack, copies):
    """Give copied stack ranges real object extents before m2c creates their local variables."""
    frame = re.search(r'\bstwu r1, -(0x[0-9a-f]+|\d+)\(r1\)', '\n'.join(fn.asm))
    size = int(frame[1], 0) if frame else 0
    regions = [(offset, offset + length) for offset, length in copies.items()
               if 0 <= offset and offset + length <= size]
    regions += [(offset, offset + value[1]) for offset, value in stack.items()]
    merged = []
    for lo, hi in sorted(regions):
        if merged and lo < merged[-1][1]:
            merged[-1] = (merged[-1][0], max(hi, merged[-1][1]))
        else:
            merged.append((lo, hi))
    result, declarations, fields, cursor = {}, [], [], 0
    for lo, hi in merged:
        if lo in stack and stack[lo][1] == hi - lo:
            typ, length, name = stack[lo]
        else:
            length, name = hi - lo, f'loc_{lo:X}'
            typ = f'struct FzgxCopy_{length}'
            fields_type = f'u32 words[{length // 4}];' if length % 4 == 0 else f'u8 bytes[{length}];'
            declarations.append(f'{typ} {{ {fields_type} }};')
        result[lo] = (typ, length, name)
        if lo > cursor:
            fields.append(f'char unk_{cursor:X}[{lo - cursor}];')
        fields.append(f'{typ} {name};')
        cursor = hi
    if cursor < size:
        fields.append(f'char unk_{cursor:X}[{size - cursor}];')
    declaration = f'struct _m2c_stack_{fn.symbol.name} {{ ' + ' '.join(fields) + ' };\n'
    return declaration, result, list(dict.fromkeys(declarations))


def packed_stack(fn):
    """Word locals whose bytes are accessed separately need one shared storage object."""
    accesses, escapes = [], set()
    for line in fn.asm:
        match = re.search(r'\b(lbz|lha|lhz|lwz|stb|sth|stw) r\d+, (0x[0-9a-f]+|\d+)\(r1\)', line)
        if match:
            size = 1 if match[1] in ('lbz', 'stb') else 2 if match[1] in ('lha', 'lhz', 'sth') else 4
            accesses.append((int(match[2], 0), size))
        match = re.search(r'\baddi r(?:[3-9]|10), r1, (0x[0-9a-f]+|\d+)', line)
        if match:
            escapes.add(int(match[1], 0))
    words = {offset for offset, size in accesses if size == 4} | escapes
    return {base: 4 for base in words if base >= 8 and base % 4 == 0
            and any(base <= offset and offset + size <= base + 4 and size < 4 for offset, size in accesses)}


def context(p, module, name, draft):
    index = recovered(p)
    source = None
    scope = list(p.function_asm(module))
    tus = p.module_config_dir(module) / 'tus.json'
    if tus.exists():
        tu = next((t for t in json.loads(tus.read_text())['tus'] if name in t['functions']), None)
        if tu:
            source = p.module_src_prefix(module) + '/' + tu['file']
            scope = tu['functions']
        else:
            mapped = {n for t in json.loads(tus.read_text())['tus'] for n in t['functions']}
            scope = [n for n in scope if n not in mapped]
    index = propagate(index, module, scope)
    fn = p.function_asm(module)[name]
    called = [m[1] for line in fn.asm if (m := re.search(r'\bbl (\w+)', line))
              and not re.match(r'_(save|rest)', m[1])]
    signatures = {n: sig for n in dict.fromkeys([name] + called)
                  if (sig := index.get(module, n, source))
                  and (n != name or sig.defined or sig.origin.startswith('include/'))}
    parts = ['#include "types.h"'] + index.preamble(signatures.values())
    present = {re.sub(r'\s+', '', text) for text in parts}
    present.update(re.sub(r'\s+', '', piece.text) for piece in declarations('\n'.join(parts)))
    # The existing layout recovery supplies globals, not its guessed call arities.
    for piece in declarations(draft or ''):
        if piece.kind == 'type' or (piece.kind == 'object' and piece.text.lstrip().startswith('extern ')):
            normalized = re.sub(r'\s+', '', piece.text)
            if normalized not in present:
                parts.append(piece.text)
                present.add(normalized)
    parts += [sig.declaration(n) for n, sig in signatures.items()]
    return '\n'.join(parts) + '\n', signatures


def assembly(p, fn):
    """Supply switch destinations from retail data, retaining their function-relative labels."""
    from .evidence import jump_tables
    tables, labels = [], {}
    for name, targets in jump_tables(p, fn).items():
        for address in targets:
            labels[address] = f'.L_{address:08X}'
        tables.append(name + ':\n' + '\n'.join(f'.4byte {labels[a]}' for a in targets))
    lines = ['.section .text', '.global ' + fn.symbol.name, fn.symbol.name + ':']
    emitted = {line[:-1] for line in fn.asm if line.endswith(':')}
    for index, line in enumerate(fn.asm):
        match = re.match(r'^([0-9A-Fa-f]+): (.*)', line)
        if match:
            address, line = int(match[1], 16), match[2]
            if address in labels and labels[address] not in emitted:
                lines.append(labels[address] + ':')
            if line.startswith(('cror ', 'crand ', 'crxor ', 'crnor ', 'crandc ', 'crorc ')):
                line = re.sub(r'\b(lt|gt|eq|so)\b', lambda m: str(('lt', 'gt', 'eq', 'so').index(m[1])), line)
            if line.startswith('mfcr '):
                register, mask, complete = line.split()[1], 0, False
                for later in fn.asm[index + 1:]:
                    instruction = re.match(r'^[0-9A-Fa-f]+: (\S+)(?: (.*))?', later)
                    if not instruction:
                        break
                    op = instruction[1].rstrip('.')
                    operands = (instruction[2] or '').split(', ')
                    if op.startswith('b'):
                        complete = op in ('bl', 'bctrl') and int(register[1:]) <= 12
                        break
                    if any(re.search(r'\b' + register + r'\b', operand) for operand in operands[1:]):
                        if op == 'srwi' and operands[1] == register:
                            mask |= (0xFFFFFFFF << int(operands[2], 0)) & 0xFFFFFFFF
                        elif op == 'extrwi' and operands[1] == register:
                            length, start = int(operands[2], 0), int(operands[3], 0)
                            mask |= ((1 << length) - 1) << (32 - start - length)
                        else:
                            break
                    if operands[0] == register:
                        complete = not op.startswith(('st', 'cmp', 'mt', 'rlwimi'))
                        break
                if complete and mask:
                    line = f'mfcr.bits {register}, 0x{mask:08X}'
        lines.append(line)
    if tables:
        lines += ['.section .rodata', *tables]
    return '\n'.join(lines) + '\n'


def generate(p, module, name, draft=None, descending=False):
    from m2c.main import parse_flags, run
    from . import lift
    from .ppc_lowering import lowering

    fn = p.function_asm(module).get(name)
    if fn is None:
        return None, 'no disassembly'
    if draft is None:
        draft = lift.lift_total(p, module, name, max_ins=max(1200, fn.symbol.size // 4))
    root = STATE_DIR / 'machine' / module / name
    root.mkdir(parents=True, exist_ok=True)
    asm = assembly(p, fn)
    frame_saves = set()
    for before, after in zip(fn.asm[:100], fn.asm[1:101]):
        save = re.search(r'\bstfd (f(?:1[4-9]|2\d|3[01])), (0x[0-9a-f]+|\d+)\(r1\)', before)
        paired = re.search(r'\bpsq_st (f\d+), (0x[0-9a-f]+|\d+)\(r1\), 0, qr0', after)
        if save and paired and save[1] == paired[1] and int(save[2], 0) + 8 == int(paired[2], 0):
            frame_saves.add(('$' + save[1], '$r1', int(paired[2], 0)))
    float_calls, enabled = {}, None
    for i, line in enumerate(asm.splitlines(), 1):
        if re.fullmatch(r'cr(?:set|clr) (?:6|cr1eq)', line):
            enabled = line.startswith('crset')
        elif re.match(r'bl\s', line):
            if enabled is not None:
                float_calls[i] = enabled
            enabled = None
        elif line.endswith(':') or re.match(r'b\w*\s', line):
            enabled = None
    (root / 'input.s').write_text(asm)
    preamble, signatures = context(p, module, name, draft)
    stack_declaration, stack = stack_context(p, fn, draft)
    packed = packed_stack(fn)
    copy_types = []
    if packed:
        stack_declaration, stack, copy_types = copy_context(fn, stack, packed)
    flags = ['-t', 'ppc-mwcc-c', '--valid-syntax', '--context', str(root / 'context.i'), str(root / 'input.s')]
    if descending:
        flags.append('--descending-regs')
    copy_sites, copy_sizes, absolute_refs = {}, set(), set()
    for attempt in range(2):
        (root / 'context.c').write_text(preamble + '\n'.join(copy_types) + '\n' + stack_declaration)
        cpp = subprocess.run(['cc', '-E', '-P', '-I', str(ROOT / 'include'), str(root / 'context.c')],
                             capture_output=True, text=True, timeout=30)
        if cpp.returncode:
            return None, cpp.stderr[-2000:]
        (root / 'context.i').write_text(cpp.stdout)
        output, errors = io.StringIO(), io.StringIO()
        with redirect_stdout(output), redirect_stderr(errors), lowering(frame_saves), _mwcc_formatting(signatures, stack, copy_sites, copy_sizes, float_calls, absolute_refs):
            code = run(parse_flags(flags))
        text = output.getvalue()
        missing = {off: size for off, size in copy_sites.items()
                   if not any(base <= off and off + size <= base + value[1] for base, value in stack.items())}
        if not missing or attempt:
            break
        stack_declaration, stack, new_types = copy_context(fn, stack, copy_sites)
        copy_types = list(dict.fromkeys(copy_types + new_types))
    copy_types += [f'struct FzgxCopy_{size} {{ u32 words[{size // 4}]; }};' for size in sorted(copy_sizes)
                   if not any(f'struct FzgxCopy_{size} ' in decl for decl in copy_types)]
    (root / ('descending.raw.c' if descending else 'raw.c')).write_text(text)
    if code or 'Error while' in text:
        return None, text[-2000:] + errors.getvalue()[-1000:]
    # A placeholder scalar is not proof of the extent of an escaped stack
    # object. In sample:_prolog, &sp47 is aligned down and memset writes 50
    # bytes; accepting it as a four-byte local would create an overflowing C
    # candidate. Preserve raw.c for analysis, but require recovered storage.
    unknown_stack = set(re.findall(r'\bM2C_UNK(?:8|16|32|64)?\s+(sp[0-9A-Fa-f]+)\s*;', text))
    escaped_stack = set(re.findall(r'&\s*(sp[0-9A-Fa-f]+)\b', text))
    unproven = sorted(unknown_stack & escaped_stack)
    if unproven:
        return None, 'unproven escaped stack object extent: ' + ', '.join(unproven)
    text = _expand(text, 'M2C_FIELD', lambda a: f'(*({a[1]})((u8 *)({a[0]}) + ({a[2]})))')
    text = re.sub(r'\bM2C_UNK(8|16|32|64)?\b', lambda m: 's' + (m[1] or '32'), text)
    text = re.sub(r'\bCLZ\(', '__cntlzw(', text)
    # An incoming saved register on an otherwise uninitialized phi arm is the
    # original C local's indeterminate value, not an external data symbol.
    text = re.sub(r'(?m)^\s*var_([rf]\d+) = saved_reg_\1;\n', '\n', text)
    text = _expand(text, 'MULTU_HI', lambda a: f'((u32)(((u64)(u32)({a[0]}) * (u64)(u32)({a[1]})) >> 32))')
    text = _expand(text, 'MULT_HI', lambda a: f'((s32)(((s64)(s32)({a[0]}) * (s64)(s32)({a[1]})) >> 32))')
    from .oracle import abs_symbols
    absolute_names = {address: name for name, address in abs_symbols().items()}
    def bind_absolute(match):
        name = absolute_names.get(int(match[2], 16))
        if name is None:
            return match[0]
        absolute_refs.add(name)
        return match[1] + f'({name})'
    text = re.sub(r'(\([\w\s]+\*\s*\))\s*(0x[0-9A-Fa-f]+)\b', bind_absolute, text)
    # The upstream compatibility header makes unhandled instructions no-ops and
    # bitwise casts numeric conversions. Such output is a draft, never a candidate.
    unresolved = sorted(set(re.findall(r'\b(?:M2C_\w+|GLUE_F64|MULTU?_HI|DMULTU?_HI)\b', text)))
    if unresolved:
        return None, 'unresolved: ' + ', '.join(unresolved)
    text = structure_loops(text)
    text = re.sub(r'\bgoto\s+(\w+);', r'goto \1; /* Preserves the retail branch. */', text)
    if fn.symbol.section == '.init':
        text = re.sub(r'(?m)^(\w[\w *]*\b' + re.escape(name) + r'\([^;]+\)\s*\{)',
                      r'__declspec(section ".init") \1', text)
    absolute_declarations = [f'extern u8 {name}[];' for name in sorted(absolute_refs)]
    result = preamble + '\n' + '\n'.join(copy_types + absolute_declarations) + '\n' + text
    candidate = root / ('descending.c' if descending else 'candidate.c')
    candidate.write_text(result)
    from .lint import lint_file
    findings = lint_file(candidate)
    if findings:
        return None, '; '.join(f'{rule}:{line} {reason}' for rule, line, reason in findings)
    return result, ''
