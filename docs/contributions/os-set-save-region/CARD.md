# OSSetSaveRegion

## Scope and provenance

This contribution removes the remaining inline-assembly body from
`OSSetSaveRegion` in `src/dolphin/os/OSReboot.c`. The function remains a
register-preserving two-store API; only the C expression of the stores changes.

##...[truncated]