# Native sentinel landing and tested partial frontiers

## Scope and collaboration

Manual inline gpt-6.1-sol work in the shared canonical checkout. No delegated agents,
no fleet/service changes, no branch switches, no push, and no changes to OpenCode's
ranking symbols or its worktree. Claims were acquired and released one at a time.
The main-rel degree-29 Claude handoff was read and left untouched.

## Exact landing

`fn_12_2CD8C`: commit `9aedf599d3e844ade85730252b3ffcdd644e8658`.
The previous synthetic-return/helper candidate stalled at 88.23529%. A native void
check of the real readonly table's sentinel at word 73 produces an exact match
with GC/1.3.2; GC/1.2.5n scores 57.235294%. The table declaration retains its real
102-word ownership. There are no carrier structs, assembly anchors, fake sections,
volatile scheduling dependencies, or fabricated extents.

`fzgx submit` queued the unit; `fzgx verify` accepted it with `link_state=verified`.
An independent lock-protected Ninja/checksum run printed `16 files OK`.
`fzgx lint` printed `0 finding(s)`.
The host sentinel fixture separately exercises both intact and corrupted sentinel
values and checks the exact callback error `0xFF000201`. This fixture verifies the
branch behavior, not PowerPC ABI/code generation; those are covered by object/link
verification.

## Preferred native partials: NOT exact matches

The accompanying `.native.c` files are evidence/continuation inputs, not linked
production units. Do not submit them without a fresh claim, compiler selection,
object match, and all sixteen link/hash checks.

| Symbol | Native result | Remaining evidence |
| --- | --- | --- |
| fn_8006BC50 | 94.92308%, GC/1.3.2 with -O3; previous ledger best 79.92308% | 2/13 rows: native zero initialization is `li r4,0; li r5,0; li r0,64`, retail is `li r4,0; li r0,64; mr r5,r4` |
| fn_8006B470 | 99.20339%, GC/1.3.2 | 7/59 rows: output/entry-offset register homes and increment schedule; semantics repaired without claiming a score gain |
| fn_12_2E1A0 | 99.3%, GC/1.3.2 | 3/30 rows: correction shift destination, minute product destination, reversed inputs to their sum |
| fn_12_29524 | 97.3%, GC/1.3.2 | 34/226 rows, native pointer/helper web allocation; correct instruction count |
| fn_12_247BC | 97.5%, GC/1.3.2 | 21/70 rows, safe unsigned tag assembly with signed compares; a prior native scalar arrangement reached 97.8% |

### Semantic repairs worth retaining

- The saved fn_8006B470 work copy (NOT the tracked canonical stub) exchanged the
  input-entry and output-record strides. Restore entry stride `0x1248` and output
  stride 10. The native replacement gives the entry its full real extent,
  removes the allocator-only destination struct, unused ABI parameters, and dead
  `(void)entry` web marker. It reproduces the old score while fixing behavior.
- The historical near-match for fn_12_247BC read `lab_v_2` before initialization
  and used a one-field tag carrier. The native parser caches the real first two
  bytes for the overlapping second tag and initializes every value. Unsigned tag
  shifts avoid signed-shift overflow on arbitrary input bytes. Do not restore the
  inadmissible 97.9% archive just because its score is larger.
- The fn_12_29524 archive used carrier structs and addressed bytes beyond a
  standalone header local. The native version has two real six-byte boundary
  buffers and a four-byte header whose split copy stays inside that object.
- fn_12_2E1A0 now expresses the timecode calculation with real scalar arithmetic,
  without a one-field minute-product carrier. Preserve signed division by ten.
  The bounded compiler-version sweep hit the no-improvement guard after probing
  GC/1.2.5n, so do NOT trust a retained active version without explicitly choosing
  GC/1.3.2 for this native body.
- fn_8006BC50 stops at a genuine `li` versus `mr` rematerialization frontier.
  Do not create a fake zero dependency or carrier to force the copy instruction.

Other bounded investigations were released without code credit:
fn_12_8B4C (native six-channel initializer; address folding vs loop artifacts),
fn_8004EFA8 (eleven-argument dispatch; early stack-short loads), fn_3_177AC
(native RGB snapshot; helper added copies/frame instead of closing the schedule),
fn_8006BC1C (native initializer remains 77.15385% under both usual compilers),
and ownership-only fn_8005BDD4 (the old overlay crosses separately owned BSS
symbols; no new compiler probes or fabricated wide extern).

An additional real-source compiler sweep of fn_8006BC50 gave 94.92308% for
GC/1.3 and GC/1.3.2r, and 76.07692% for GC/1.2.5 and GC/1.1p1. Four initial
`missing_in_base` probes were invalid because claiming an uncarved function did
not install the candidate body; the source was explicitly written before the
valid measurements. Do not use those initial zeroes as compiler-quality data.

The initial local `python -m unittest discover -s tests -v` command passed its
11 discovered tests. After the attempt-isolation fix described below, the same
command passed all 15 discovered tests, including four new SQLite regressions.
This is a tool-test subset, not a claim that every repository test or oracle
fixture was run.

## Claim-isolation fix and provenance repair

Checkpoint review found that the stale attempt `24937` for fn_12_2E1A0 had remained
open after its function claim was no longer active. Both `bump_checks` and `finish`
update open attempts by symbol, so the new attempt's nine checks and release
metadata were also written into the old attempt. The old check count became 20
instead of its checkpointed 11; the new attempt is `24978`.

Commit `5f10837a` fixes the root lifecycle boundary: after a new claim passes both
live-owner and attempt-cap checks, it atomically seals any older open attempt
rows as expired before inserting the new one. Original scores, counters, costs,
and provenance are not rewritten. The same timestamp ends the old attempt and
starts the replacement. A real SQLite expiry/reclaim regression was observed
failing (`2 != 1` checks) before the fix and passing after it. Additional tests
cover live-owner rejection, attempt-cap rejection, and shadow-claim history/status.
No fleet, service, dispatcher, or OpenCode-source changes were made.

The already affected historical row was repaired separately and narrowly. Its
original metrics/provenance were recovered from the committed pre-session
checkpoint, after asserting the old count equaled its original count plus the
new attempt's nine checks, and that both rows had received identical release
metadata. Only row 24937 was restored to 11 checks, 98.833336% best, unknown model,
and expired at the newer claim's start. Row 24978 was read back unchanged with
nine checks, 99.333336% best and its actual gpt-6.1-sol attribution. SQLite
`quick_check` returned `ok`. A complete pre-repair database recovery copy was
retained in scratch. The exact sentinel attempt's previously omitted harness and
model were also explicitly attributed to Hermes/gpt-6.1-sol; no scores or costs
were synthesized.

## Executed semantic fixtures

`test_stream_snapshot.c`:

- Fixed-width host types; retail entry stride, field offsets, and 10-byte output
  extent are compile-time assertions.
- Null destination plus every one of the 256 four-entry/two-flag configurations.
- Checks cleanup count/subobject address, post-cleanup flags/status, all output
  bytes, and before/after guards under ASan and UBSan.
- A scratch negative control swaps the two strides. It emits UBSan misaligned
  entry accesses and fails the byte assertion with exit 134. The original fixture
  then passes again. This is behavior evidence, not PowerPC register proof.

`test_clear_slots_wasm.c`:

- Compiles and executes the exact native clear-slot source on wasm32, enforcing
  four-byte pointers and `u32`, and the real `0x1F4` slot-object extent.
- 64 single-populated-slot cases, all-populated, and all-empty: 66 cases total.
- All slots clear and prefix/before/after guards remain intact.

`test_sentinel.c`:

- Compiles the landed canonical source with a fixed-width host shim.
- Both sentinel states passed with ASan/UBSan; the bad value calls the reporting
  function exactly once with null context and error `0xFF000201`.

Reproduction from repository root (binaries belong in active scratch):

```sh
SCRATCH="$TMPDIR"
FIX=docs/findings/native-sentinel-frontiers

gcc -std=c11 -O1 -g -Wno-unknown-pragmas -Wno-pointer-to-int-cast \
  -fsanitize=address,undefined -fno-omit-frame-pointer -I include \
  "$FIX/test_stream_snapshot.c" -o "$SCRATCH/fzgx-stream-fixture"
"$SCRATCH/fzgx-stream-fixture"

clang --target=wasm32 -std=c11 -O2 -fno-builtin -nostdlib \
  -Wno-unknown-pragmas -I include -Wl,--no-entry -Wl,--export=run_suite \
  "$FIX/test_clear_slots_wasm.c" -o "$SCRATCH/fzgx-clear-slots.wasm"
node -e 'const fs=require("fs"); WebAssembly.instantiate(fs.readFileSync(process.argv[1]),{}).then(({instance})=>{const n=instance.exports.run_suite(); if(n!==66) throw Error("fixture failed: "+n); console.log("PASS: "+n+" wasm32 cases");}).catch(e=>{console.error(e);process.exit(1)})' "$SCRATCH/fzgx-clear-slots.wasm"

for MODE in GOOD BAD; do
  EXTRA=""
  if [ "$MODE" = BAD ]; then EXTRA=-DBAD_SENTINEL; fi
  gcc -std=c11 -O1 -g $EXTRA -fsanitize=address,undefined \
    -fno-omit-frame-pointer -I include "$FIX/test_sentinel.c" \
    -o "$SCRATCH/fzgx-sentinel-$MODE"
  "$SCRATCH/fzgx-sentinel-$MODE"
done
```

The repository language server uses the freestanding GameCube include environment;
its missing host `stdint.h` diagnostics for these host-only fixtures are not the
result of running these GCC/wasm32 commands. Both real toolchains were exercised.
