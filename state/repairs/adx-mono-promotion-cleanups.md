# ADX mono-path identity and propagation cleanups

## Accepted changes

### fn_8004F26C

Removed the marked `compiler_diff_keep` identity helper. Both signed-short input
coefficients are promoted into ordinary integer arithmetic locals (`c1` then
`c0`), and the RNG multiplier uses an integer arithmetic local. The increment is
assigned directly from its original signed-short parameter. All actual sample
calculations use the promoted coefficient values; the ABI parameter types and
existing entry-block dead readers are unchanged.

This removes one primary device warning. The six remaining warnings still mark
the propagation setting, register-only parameter, stack-parameter copies, escaped
addresses, dead entry readers and prediction's dead arm. In particular, this
change does not remove or disguise the zero-conditioned arm or its pragma.

### fn_8004F55C

Removed the previously unmarked global `#pragma opt_propagation off`. The packed
input byte is dead after decoding the first sample and computing the low-nibble
index, so its variable can hold the nibble-table result for the second sample.
The RNG increment uses an integer arithmetic local initialized from the original
signed-short input parameter. No extra operation, barrier, identity helper or
compiler setting was introduced.

The three existing marked mechanisms remain: dead-assignment setting, entry copy
and artificial gain declaration scope, and stack-address comparison. This is not
a fully device-free function. The gain is still declared in the original outer
scope; moving it inside the block loop did not match and was not installed.

## Provenance

Both units retain stock `GC/1.3.2` (2.4.2 build 81), per-unit
`-use_lmw_stmw on`, and their existing DOL base flags. The bundle's `info.txt`
distinguishes this compiler from the separately patched `GC/1.3.2r` variant.
Compiler SHA-256:
`7cbae0a5bd81e07d7fa8975bbc4e969b5dea265cc29c5ee6bae0453a6e25f225`.

| Source | Before SHA-256 | Accepted SHA-256 | Retail words |
| --- | --- | --- | ---: |
| `src/dol/fn_8004F26C.c` | `4cf4d480807b6a66f3771dc5cf8156b24dc14f540941e89972c9b47136faf5a1` | `324eacc3a5a6f234e6313653a6a1caa87cd79ef7046cd9081ba805c39bb6bd34` | 188 |
| `src/dol/fn_8004F55C.c` | `23cc9610bb40c5c853ab94331cfef858cab3678048e1d329c334e9712bcf74cd` | `e05a045b8f4f08050f206f872fe9e08ed8686b164fba822f3d6e0005f400e6dc` | 85 |

Incoming types, signed values, parameter order, initialized data, relocations and
compiler executable were preserved. The new integer arithmetic locals do not
widen the ABI or introduce 64-bit operations. This work uses the existing
reconstruction and independently tested source transformations; no external
contributor code, cached donor candidate or repair recipe was imported.

## Negative measurements retained as stopping evidence

On `fn_8004F26C`, additionally removing the propagation directive and fake
prediction arm can leave six positional instruction-word differences when the
real decoded-sample accumulator is reused for the next prediction. Other simple
arithmetic forms leave three words only while retaining the directive. Neither
is accepted. The six-word variant is not a completely device-free function: its
existing entry devices remain. Reordering all four inner-loop declarations,
separating real products, trying the shared predictor helper and using coherent
signed-32-bit local-type groups did not close that residual.

Deleting the coefficient's dead reader also leaves a four-word exchange between
the table-address and division-constant setup registers. Lookup/mix helpers and
an ordinary table pointer did not repair it. Removing subsets of the existing
dead readers likewise found no exact nonempty deletion. No synthetic use,
replacement assembly or new pragma was added to force these remaining cases.

On `fn_8004F55C`, the accepted change preserves the alias-induced entry-load
schedule while simplifying the arithmetic's source shape. The previous fully
natural frontier still has its three-word stack-load movement; that frontier is
not installed. Do not repeat the same default declaration/type sweeps without a
new value-flow or compiler hypothesis.

## Verification and reproduction

```
uv run tools/manual.py try fn_8004F26C src/dol --glob fn_8004F26C.c \
  --mw GC/1.3.2 --flags='-use_lmw_stmw on' -v
uv run tools/manual.py try fn_8004F55C src/dol --glob fn_8004F55C.c \
  --mw GC/1.3.2 --flags='-use_lmw_stmw on' -v
python3 configure.py --version GFZE01
uv run ninja
uv run tools/fzgx.py lint
```

Both complete-function oracle checks reported `100.000 MATCH rows=0`. The real
DOL/REL rebuild reported `16 files OK`; lint reported `0 finding(s)`. The existing
uninitialized `off` warning in the unchanged `fn_8006AF94` compilation and the
existing unknown-section linker warnings were also emitted; no warning-free
compiler claim is made. No unit tests were added.

The source/header inventory changes from 33 to 32 primary
`WARNING: compiler-diff device` markers, with two `WARNING: device` references
across the same 12 files. The additional removed pragma was unmarked, so marker
counts alone would miss that cleanup. Both functions remain partially
device-backed; no newly exact function or fully natural-C function is claimed.
