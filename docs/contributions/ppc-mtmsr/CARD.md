# PPCMtmsr

## Scope and provenance

This contribution converts `PPCMtmsr` in `src/dolphin/os/OSPPC.c` from an
asm-defined function to a natural-C wrapper. The privileged `mtmsr` instruction
remains in a minimal inline-asm statement because ordinary C cannot express an
MSR write.

## Verification

- Retail symbol: `0x80009FC4`, size `0x08`.
- Complete OSPPC unit: 100.0% exact.
- Full GFZE01 DOL SHA-1 gate: passed.
- `python3 -m unittest discover -s tests`: 11 tests passed.
