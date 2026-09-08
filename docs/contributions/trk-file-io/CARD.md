# TRK checked file I/O — isolated verification

Targets: `TRKWriteFileChecked` (0x8008DC10) and `TRKReadFileChecked`
(0x8008DCCC), 188 retail bytes each. Both remain in
`src/dolphin/metrotrk/main.c`. The only configuration change is the
per-object `mw_version="GC/1.3"` override for that file. Other compiler
pins, flags, matching status, splits, symbol names and global storage are unchanged.

## Provenance by changed function

Both routines are reference-assisted reconstructions of the F-Zero GX retail
code, using [Mario Party 4's MetroTRK implementation](https://github.com/mariopartyrd/marioparty4/blob/147b165a83187ac9e6cfdc3bf52f2e73437b1ffd/src/TRK_MINNOW_DOLPHIN/mslsupp.c)
at revision `147b165a83187ac9e6cfdc3bf52f2e73437b1ffd`:

- `TRKWriteFileChecked`: provenance:
  `mariopartyrd/marioparty4:src/TRK_MINNOW_DOLPHIN/mslsupp.c:25`
  (`__TRK_write_console`), plus `__write_file` at line 46 and
  `__access_file` at line 82.
- `TRKReadFileChecked`: provenance:
  `mariopartyrd/marioparty4:src/TRK_MINNOW_DOLPHIN/mslsupp.c:13`
  (`__read_console`), plus `__read_file` at line 37 and
  `__access_file` at line 82.
- Also consulted at that revision: `include/PowerPC_EABI_Support/MetroTRK/trk.h`
  for ABI context, and `src/MSL_C.PPCEABI.bare.H/uart_console_io.c` for writer
  caller context during the initial reconstruction.

The F-Zero implementations flatten the reference's helper chain. They were
subsequently adapted to this repository's callback/callee types and verified
against retail bytes and relocations. The reference was consulted before the
initial implementations were written, not merely during this contribution's
review. This is not a claim of independent clean-room authorship. No reference
license file was identified; attribution does not establish a license grant.

- `AMC_IsStub_Game`: receiver assembly retained verbatim; return type corrected
  to unsigned byte from its `lbz r3` body. No new decompilation credit.
- `TRK_IsInputPending`: receiver assembly retained verbatim, matching `int(void)`
  declaration/definition for the word load consumed by `cmpwi r3,0`.
  No new decompilation credit; globals/storage unchanged.
- `fn_8008CB20`: receiver `twi 31,r0,0; blr` trap veneer retained as typed
  assembly, avoiding a non-void C fall-through and preserving r3's trap result.
  No new decompilation credit.

## ABI

The existing C writer caller is `fn_80085814` in `msl_80083E84.c`:
`int(unsigned int, char*, unsigned int*, unsigned int)`. Both wrappers use that
receiver-compatible word/pointer ABI, not the donor's `u32`/`size_t` typedefs.
The retail reader uses buffer in r4 and count pointer in r5 and does not read
incoming r3/r6. No named reader caller occurs in receiver source; its unused
handle/context parameter types are the writer-compatible interface, not a
claim that the machine code distinguishes unsigned words from pointer values.
The trap uses `(unsigned int command, unsigned int handle,
unsigned int* count, char* buffer)` and returns `unsigned int`. Local count and
callee pointer types agree exactly. Commands/fixed handles are D0/1 and D1/0;
both guards precede count access, count is copied back even on errors, and the
low status byte maps 0/2/other to 0/2/1.

## Verification and remaining upstream blocker

Refreshed public main: `9af7e15af23b0dcfbce890532f984f5eb555edfd`.

- Fresh configured builds of all three affected objects match the complete
  baseline allocated sections/layout, functions, symbol records and canonical
  relocations. Both C wrappers equal all 188 retail bytes and all 3 relocations.
  Equality is normalized ELF equality, not a claim of raw object-file equality.
- GC/1.2.5n previously emitted 192-byte wrappers; GC/1.3 matches the full owner,
  not just these two functions. Generated command comparisons confirm that only
  the owner's compiler executable changes; supporting objects retain their pins.
- Fresh baseline and candidate `ninja all_source build/GFZE01/main.dol` attempts
  both fail at unrelated `EXIBios.c:1092`, stale `lbl_801A6840`. No unrelated fix
  is bundled, and no current-main full-link success is claimed.
- Supplementary full-link validation uses clean last-good
  `675f69f289b338df4a7098fedcf89a73de23d113`. The three baseline sources are
  byte-identical across bases; baseline-to-baseline and candidate-to-candidate
  compiler commands are identical. The older configuration retains its own
  unrelated settings and receives only the same owner override for candidate
  builds. All three objects also match their corresponding current-base objects.
- On that last-good base, baseline, candidate and both restorations actually
  pass `ninja all_source build/GFZE01/main.dol`; each DOL has retail SHA1
  `421c88106697d3275a3fc26fb7a01bf6d816b271`.
- Separate C-source mutations change writer D0 to D2 and reader D1 to D3.
  Each compiles and links, changes only its target function (same size and
  relocations), changes exactly one linked DOL byte, and fails the retail hash
  check. Each is restored and rebuilt before the next test; final sources and
  the submitted `configure.py` are SHA256-bound in the completion receipt.
- Public unit suites pass 8/8 on current baseline/candidate and supplementary
  baseline/candidate/final. Linked-PPC emulation passes 3,168 cases per baseline,
  candidate and each restored DOL; both retained source-mutant DOLs are rejected.
  Debugger boundaries are mocked. This is not hardware or in-game testing.

The subsequent attribution correction changes only two single-line source
comments, preserving every other source byte and all line positions. A separate
`provenance/comment-only-equivalence.json` receipt binds the corrected source
to the source used for the build/mutation proof; the original receipts remain
unchanged. No function bodies or compiler settings changed.

Private receipts, commands, final source copies, objects and all six DOLs are
outside the repository in `fzero-trk-io/evidence/authorized/`: `completion.json`,
`current-object-verification.json`, `*-compile-commands.json`, full build/test
logs and `linked-emulator-verification.json`. Earlier blocked diagnostics are
historical, not the final configured build. Do not publish binaries/game assets.
