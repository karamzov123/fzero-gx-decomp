# Source-quality cleanup and BC310 return evidence

## Two historical markers removed without losing exactness

After the whole-project audit, two small marked source files were tested under
their recorded GC/1.3.2 unit settings, with baseline controls:

- fn_80080518, 168 bytes: removed `(void) b` with the allocator-liveness marker.
  The backward-copy algorithm, declarations and compiler settings are unchanged.
- title:fn_8_704, 80 bytes: removed the unused fn_8_704_lbl_8_bss_0 type containing
  lab_pad. That type's identifier occurred only in its own declaration; the actual
  lbl_8_bss_0 declaration, offset-bearing views and function body are unchanged.

Both baseline and clean standalone objects match retail at 100.0% raw and
adjusted. The configured fleet was drained before editing source; no claims
remained. A fresh Ninja rebuild recompiled DOL/title units, relinked both outputs,
and regenerated the REL set. All sixteen executable hashes pass afterward.
The existing eleven tests and ordinary lint also pass.

The real source-hygiene audit drops from eighteen marked source files to sixteen.
This addresses two known markers; it is not a blanket semantic certification of
all source or an assertion that every other wrapper/type in these functions is
necessary. These are 248 bytes of already-matched code cleaned up, not 248 newly
decompiled bytes or new module closure. No replacement no-op, larger local array,
register-forcing variable or guessed object layout was added.

## BC310 warning traced rather than initialized away

The 9,832-byte fn_1_BC310 saved draft declares v98, uses it later as a loop/index
variable and returns it on five paths. Three early return paths occur before its
first assignment. MWCC reports the variable as uninitialized.

The retail epilogue does not materialize v98 as a return result. Four direct call
sites were found across main_rel, customize and option. Their recovered C uses
statement calls; three existing declarations are void, while option carries a
u32 declaration. The retail call-site windows and function assembly are archived.
This evidence motivates a void-return hypothesis, not a universal ABI proof:
a caller ignoring a result alone does not establish that the callee returns void.

A single isolated experiment changed the draft's return type from u32 to void
and replaced all five `return (u32)v98` statements with plain returns. It did not
initialize v98 or alter its loop uses.

Stock GC/1.3.2 results:

- Baseline: raw 83.03173%, adjusted 53.8%, 1,202 differing rows; warning present.
- Void-return probe: raw 82.87876%, adjusted 52.65%, 1,232 differing rows; warning
  absent.

The warning is explained as part of an unsupported return/dataflow reconstruction,
not evidence of a known constant initializer. The experiment worsens the emitted
match and is diagnostic-only. Neither global declarations nor the source seed were
changed from this hypothesis, and this large body was not dispatched as a near-miss.
Further work requires control-flow and variable-web reconstruction; a cleaner
warning log is not a matching-source result.

## Provenance and boundaries

state/repairs/source-quality-continuation-20261011.json.gz preserves the four
actual caller windows, retail function assembly, both large-function C/compiler
verdicts, both exact source cleanups with before/after hashes and the sixteen-file
remaining hygiene audit. Candidate admissibility and already-matched versus new
bytes are explicit. The original operator files remain protected. The two-slot
Codex high policy and parked Hermes ultra policy are unchanged; restore the
standing service only after the clean-source full build/hash gate.
