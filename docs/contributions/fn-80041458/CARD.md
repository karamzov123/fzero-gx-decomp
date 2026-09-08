# fn_80041458

## Scope and provenance

This contribution converts `fn_80041458` in
`src/game/tail_800410A4.c` from an asm-defined pointer accessor to natural C.
The retail behavior is exactly `this + 0x58`; no neighboring game functions are
changed.

## Verification

- Retail symbol: `0x80041458`, size `0x08`.
- Owner-unit target: 100.0% fuzzy match, 8 bytes.
- Full `ninja` DOL SHA-1 gate: required before submission.
- Repository tests: `python3 -m unittest discover -s tests`.
