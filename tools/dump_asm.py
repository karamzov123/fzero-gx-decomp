#!/usr/bin/env python3
"""Robust PPC disassembly dump for MWCC transcription (supersedes inline scripts).

Handles capstone gaps documented in findings/15-17:
- fcmpu/fcmpo (opcode 63 XO 0/32) undecodable -> manual decode
- psq_l/psq_lu/psq_st/psq_stu (opcodes 56/57/60/61) decoded as modern VSX
  names (xsaddsp...) by capstone -> post-processed to Gekko mnemonics
- CR-logic ops printed with symbolic cr0eq-style operands that mwcceppc
  rejects -> numeric form

Usage: dump_asm.py <start_hex> <length_hex> [outfile]
Output lines: ADDRESS  WORD_HEX  MNEMONIC\tOPERANDS
"""
import re, sys, struct
from capstone import Cs, CS_ARCH_PPC, CS_MODE_32, CS_MODE_BIG_ENDIAN

DOL = 'orig/GFZE01/sys/main.dol'
d = open(DOL, 'rb').read()
offs = struct.unpack(">18I", d[:0x48])
addrs = struct.unpack(">18I", d[0x48:0x90])
sizes = struct.unpack(">18I", d[0x90:0xD8])

def rd(va, n):
    for i in range(18):
        if sizes[i] and addrs[i] <= va < addrs[i] + sizes[i]:
            fo = offs[i] + va - addrs[i]
            return d[fo:fo+n]
    raise SystemExit(f"vaddr {va:#x} not in DOL")

md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN)
CRXO = {33: 'crnor', 129: 'crnand', 193: 'crxor', 257: 'crand',
        289: 'crset?', 449: 'cror', 1: 'crandc?'}

def ps_form(W, mnm):
    frS = (W >> 21) & 31
    rA = (W >> 16) & 31
    Wb = (W >> 15) & 1
    i = (W >> 12) & 7
    dv = W & 0xFFF
    if dv & 0x800: dv -= 0x1000
    dd = '0x%x' % dv if dv >= 0 else '-0x%x' % -dv
    return f"{mnm}\tf{frS}, {dd}(r{rA}), {Wb}, {i}"

start = int(sys.argv[1], 16)
length = int(sys.argv[2], 16)
out = []
undec = []
for va in range(start, start + length, 4):
    w = rd(va, 4)
    W = int.from_bytes(w, 'big')
    ins = list(md.disasm(w, va))
    if ins:
        mn, ops = ins[0].mnemonic, ins[0].op_str
        if mn.startswith('xs') or mn.startswith('xv'):
            # opcode 60 = psq_st family misdecoded as modern VSX
            op = W >> 26
            if op == 60:
                out.append(f"{va:08x}  {w.hex()}  {ps_form(W, 'psq_st')}"); continue
        if re.search(r'cr\d(lt|gt|eq|so)', ops):
            bt = (W >> 21) & 31; ba = (W >> 16) & 31; bb = (W >> 11) & 31
            xo = (W >> 1) & 1023
            mnm = CRXO.get(xo, f'crXO{xo}')
            out.append(f"{va:08x}  {w.hex()}  {mnm}\t{bt}, {ba}, {bb}"); continue
        out.append(f"{va:08x}  {w.hex()}  {mn}\t{ops}")
    else:
        op = W >> 26; xo = (W >> 1) & 0x3ff
        if op == 63 and xo == 32:
            out.append(f"{va:08x}  {w.hex()}  fcmpo\tcr{(W>>23)&7}, f{(W>>16)&31}, f{(W>>11)&31}"); continue
        if op == 63 and xo == 0:
            out.append(f"{va:08x}  {w.hex()}  fcmpu\tcr{(W>>23)&7}, f{(W>>16)&31}, f{(W>>11)&31}"); continue
        if op == 56:
            out.append(f"{va:08x}  {w.hex()}  {ps_form(W, 'psq_l')}"); continue
        if op == 57:
            out.append(f"{va:08x}  {w.hex()}  {ps_form(W, 'psq_lu')}"); continue
        if op == 60:
            out.append(f"{va:08x}  {w.hex()}  {ps_form(W, 'psq_st')}"); continue
        if op == 61:
            out.append(f"{va:08x}  {w.hex()}  {ps_form(W, 'psq_stu')}"); continue
        undec.append((hex(va), w.hex()))
        out.append(f"{va:08x}  {w.hex()}  UNDEC\t-")
if len(sys.argv) > 3:
    open(sys.argv[3], 'w').write('\n'.join(out) + '\n')
else:
    print('\n'.join(out))
if undec:
    print("UNDECODABLE:", undec, file=sys.stderr)
