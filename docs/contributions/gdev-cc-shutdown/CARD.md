# gdev_cc_shutdown

## Scope and provenance

This contribution converts the zero-return `gdev_cc_shutdown` stub in
`src/dolphin/metrotrk/gdev.c` from an asm-defined leaf to natural C. No gdev
state or neighboring MetroTRK routines are changed.

## Verification

- Retail symbol: `0x8008E638`, size `0x08`.
- Complete gdev unit: 10/10 functions exact.
- Full DOL SHA-1 gate and progress generation pass.
- Repository tests pass.
