# PPCMfmsr

## Scope and provenance

This contribution converts `PPCMfmsr` in `src/dolphin/os/OSPPC.c` from an
asm-defined function to a natural-C wrapper. The privileged `mfmsr` instruction
remains inline assembly because it cannot be expressed in portable C.

## Verification

- Retail symbol: `0x80009FBC`, size `0x08`.
- OSPPC unit: 27/27 functions exact, 320/320 code bytes matched.
- Full DOL SHA-1 gate and progress generation pass.
- Repository tests pass.
