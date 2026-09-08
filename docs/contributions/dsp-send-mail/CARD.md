# DSPSendMailToDSP

## Scope and provenance

This contribution converts `DSPSendMailToDSP` in `src/dolphin/dsp/DSP.c`
from inline assembly to natural C. The existing volatile `__DSPRegs` mapping
at `0xCC005000` is preserved.

| Function | Retail address | Bytes | Provenance |
| --- | --- | ---: | --- |
| `DSPSendMailToDSP` | `0x80028CF8` | 20 | `dolsdk2001:src/dsp/dsp.c:34` and GFZE01 retail disassembly |

The implementation writes the high and low 16-bit halves of the 32-bit mail
word to DSP mail registers `0xCC005000` and `0xCC005002`. Under the pinned
MWCC GC/1.2.5n toolchain it emits the retail `lis/srwi/sth/sth/blr` sequence.

## Verification

- `DSPSendMailToDSP`: 100.0% fuzzy match, 20 bytes.
- Complete DSP unit: 100.0% fuzzy match; all 16 functions exact.
- Full DOL checksum gate: `build/GFZE01/main.dol: OK`.
- Progress generation completed successfully.
- Public tests: 11 passed.
