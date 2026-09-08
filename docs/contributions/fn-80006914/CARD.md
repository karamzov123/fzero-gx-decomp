# fn_80006914

## Scope and provenance

This contribution converts the 8-byte SDA21 setter `fn_80006914` in
`src/main.c` from inline assembly to natural C. It stores the incoming 32-bit
value in the verified `.sbss` object `lbl_801A66E0`, preserving the original
`stw r3,-0x7CE0(r13); blr` behavior.

## Verification

- Retail symbol: `0x80006914`, size `0x08`.
- Target function: 100.0% exact.
- Full DOL SHA-1 gate and progress generation pass.
- Repository tests pass.
