# PR22 source recovery and compiler cohorts

Source: https://github.com/rayanht/fzgx/pull/22 (pabloski2300), pinned to
`ced1e6b523600e5b2f7fab6f78b571eedc172c85`.

Thirty previously undelivered functions (19,572 executable bytes) were selectively
compiled and accepted through the existing source/object/link verifier. The
integration commits are `d3ca97ce`, `fc787c86`, and `a4b900e5`. Their verifier gates
passed all sixteen target hashes. No upstream manifest, split tree, headers, or
PR tooling was wholesale copied/executed.

`state/repairs/pr22-verified-cohorts.json` records each target's module, compiler,
flags, upstream source identity, original and accepted source SHA-256, matching
ownership paths, and verified commit. It is an evidence registry, not a scheduler
or blanket profile override. The existing per-function unit configuration and
fixup import metadata hold the active compiler settings.

## What unlocked the extra seven bodies

Three exact instruction matches emitted additional static helper bodies. The
existing natural-C inline-helper transformation removed those emitted copies;
source acceptance and final link verification were still required.

Four declaration-blocked bodies became exact with bounded, current-declaration
normalization: signed scalar access to the customize control word; an aggregate
FontDrawPacket view of the existing readonly packet object; removal of a duplicate
matrix prototype; and explicit retail-stride player/first-byte flag views without
redefining or claiming shared BSS. Existing shared declarations/ownership and the
operator's source/tooling/control edits were preserved. This does not globally
establish all provisional placeholder types as correct.

## Residuals, not delivered gains

- `fn_1_112F40`: declaration normalization permits compilation, but the measured
  candidate is 91.48936170212765%, with twenty differing instruction words. Do not
  promote the upstream matching assertion or run unchanged one-word retries.
- `fn_1_135D7C` and `fn_1_136174`: multiple shared prototype/ABI conflicts remain,
  including pointer-return functions, setter parameters, and the float/string
  argument order of `fn_1_4CF3C`. The former also conflicts with its own opaque
  declaration. Correct these as a consumer/callee cohort with existing-call-site
  and sixteen-target regression evidence, not isolated guessed prototypes.
- `fn_80036AC4`: blocked; a stale verified flag does not establish delivery when
  matched_commit and matching source are absent. No retry or promotion was made.

Compiler diagnostic inputs used `-maxerrors 100` only to expose the complete
conflict set in scratch. Integration used the original recorded compiler flags;
diagnostic-only flags were not installed.

## Reuse rules

Keep module-qualified identity and exact source provenance. Freshly compile and
check source/object acceptance, preserve shared pool/BSS ownership, then require
link verification and all sixteen hashes. Never infer ABI or library-family
settings from a successful anonymous function alone. In particular, ARC unsigned
char, GC/1.3.2 library, GC/2.6 conversion, and GC/1.3.2r REL settings are demonstrated
for the listed functions, not for every nearby address.

The separate missing-registration investigation must distinguish a valid TU
registration (a virtual per-function source path backed by an existing tagged TU)
from an actually absent definition. A source-file existence check alone cannot
justify deleting registrations or crediting recovered code.
