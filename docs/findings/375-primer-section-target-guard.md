# Finding 375: reject requested functions in the primer section

## Outcome

Fixed a scoring/diagnostic hazard in tools/fzgx/oracle.py. `_diff` now inspects
the requested candidate symbol before any ignored-primer processing and returns
an explicit error if that function is in `.fzgxpool`. It still permits ordinary
`.text` functions whose objects contain separate primer/data helpers. No game
function was newly matched or submitted in this pass.

No repository tests were added (AGENTS rule). The red/green check uses actual
MWCC objects in scratch, not mocked disassembly; its source and reproduction
probe are retained in:

    state/repairs/manual-aur-assert-and-primer-section-guard-20261017.json

## Reproduction and root cause

The evidence-led fourth attempt on fn_1_15176C tested the assertion record at
lbl_1_data_463C8. Its decoded 64 bytes have no relocations and contain:

    0x00: bg_aur.c                   (12-byte field)
    0x0c: SPOT LIGHT OVER!           (20-byte field)
    0x20: ELEV STOP OVER! in bg_aur.c (32-byte field)

The saved reconstruction fabricated a 16-byte prefix and then referred to
`text+0x10`. The verified native record removes that fiction, but ordinary
char-array and struct views still leave 25 genuine rows /228 aligned; they
are not exact C matches.

A local native definition in `.fzgxpool` required registering the section.
`#pragma section code_type ".fzgxpool"` also moved the requested function into
the primer section. Before the fix, `_diff` returned:

    ok=True, percent=0.0, differing_rows=1

The displayed adjusted near-match was invalid. Primer equivalence/filtering
must not be applied to the function whose code is being judged.

Independently compiled two source variants with oracle.compile_source under
GC/1.3.2: the same requested function in `.fzgxpool` and in `.text`, both with
the separate 64-byte assertion object. Read their ELF symbol sections and
extracted the named function words, not section-wide bytes. Both contain
IDENTICAL 226-word function bodies; retail has225 words. SHA-256 of the common
candidate function bytes:

    0c1fc5b4682dc8e1a64f35bef34f99f31059c273d9fb441e7948b7219705e347

The proper `.text` variant reports27 differing rows. The apparent one-row
result was therefore not a source improvement and must not be saved/promoted
as a near-exact frontier.

## Minimal guard and real red/green

Central `_diff` handling covers carved and uncarved candidate paths. Read the
ELF symbol and check its owning section; reject only the requested symbol in
`.fzgxpool`, with a message to restore its code section. An unreadable candidate
object fails explicitly instead of allowing inspection to be skipped. No
matcher tolerances, relocation equivalences, signatures, compiler flags, or
acceptance thresholds were changed.

- RED: the scratch probe asserted a rejected primer target. Before the edit it
  failed with `ok=True`, percent0, one differing row (exit1).
- GREEN: the exact same compiled fixture now returns `ok=False` with
  `target function main_rel:fn_1_15176C is in the .fzgxpool primer section;
  restore its code section before checking` (probe exit0).
- POSITIVE CONTROL: the byte-identical `.text` function remains a normal
  nonmatch, `ok=True`, 27 differing rows. Its object still contains a separate
  `.fzgxpool` object: legitimate primers are not rejected indiscriminately.
- EXISTING EXACT CONTROLS: fn_3_0, fn_1_10D2F0, fn_10_1B2F4 each rechecked
  at100.0%, zero differing rows. The latter exercises real pool binding.

## Integration verification

- Existing unittest suite: all11 tests pass.
- Incremental Ninja relink through oracle.build_lock/oracle.relink: exit0,
  rebuilt/relinked affected modules, final CHECK says16 files OK.
- Linker emits section-ignored warnings for data/rodata/bss/primer sections;
  these were not silently represented as a warning-free build. Hash gate passes.
- Project C lint:0 findings. Python syntax check and git diff --check pass.
- No new repository test file, inline asm, binary blobs, compiler pins, module
  layout changes, game-source submission, or startup/fleet changes.

fn_1_15176C is released and blocked for evidence-led triage at attempt4; its
preferred native-record source is portable, with no authored credit claimed.
The invalid primer-layout source is retained ONLY as a rejected oracle
regression reproduction, not as a candidate to dispatch. The state/blocked.md
row names the real residual and the next required base/scheduling witness.

OpenCode was notified of the one-file tool edit scope before editing; its game
matches and shared branch were preserved. No subagents were spawned, and no
independent model review is claimed. No push was performed.
