# fn_1_118D90 last-loop latch: emission cycle, start rotation, and the color/pair coupling

- Unit: `rel/main_rel` (`src/rel/main_rel/accessory.c`), symbol `fn_1_118D90` (1344 B /
  336 words), nonmatching.
- Status: unmatched. Best body archived at
  `.fzgx/attempts/fn_1_118D90.1792292741.c` (+ `.json`):
  sha256 `03452e268aaa1db23643a18961581450d7dc614cf695196b57fa6baf354934b9`,
  **objdiff `match_percent` 99.872025**, word score 98.511905 (5/336 wrong words:
  idx `[6, 7, 304, 307, 309]`).
- The archived body is the best saved frontier for this function: prior saved
  attempts were hermes 2x 99.72024, pin-scan 99.54, codex 99.54, cline 99.43.

## The five residual words

```
w6   retail lis  r4, 0            ours lis  r3, 0
w7   retail addi r31, r4, @l      ours addi r31, r3, @l
w304 retail addi r26, r26, 3      ours addi r31, r31, 0x44    (j_2 vs e)
w307 retail addi r31, r31, 0x44   ours addi r30, r30, 0x24    (e vs shadow)
w309 retail addi r30, r30, 0x24   ours addi r26, r26, 3       (shadow vs j_2)
```

(w308 agrees: `addi r29, r29, 0x88`, g.) The body of the loop, the two `fn_1_1289BC`
call triples and the whole rest of the function are byte-exact in this body.

## Retail facts (rows from `orig/GFZE01/.../main_rel.o`, disassembled)

Preamble `w261..266`: `li r28,0` (i); `mr r30,r28` (shadow init **= a copy of i**);
`li r26,0` (j_2); `lwz r27,0x24(r25)` (base); `mr r31,r27` (e = base); `mr r29,r27`
(g = base). Latch `w301..310`:

| w | instruction | role |
|---|---|---|
| 301 | `addi r28,r28,1` | i |
| 304 | `addi r26,r26,3` | j_2 |
| 305 | `cmplwi r28,4` | loop test |
| 306 | `stfsx f1,r3,r0` | last triple-C store |
| 307 | `addi r31,r31,0x44` | e |
| 308 | `addi r29,r29,0x88` | g |
| 309 | `addi r30,r30,0x24` | shadow |
| 310 | `blt` | back edge |

So retail emits the latch in role order `[i, j_2, e, g, sh]` and its colors are
`e=r31, sh=r30, g=r29` (e gets the highest saved color, shadow the middle, g the
lowest).

## Emission model (measured over ~60 variants, 10 offline batches)

The latch increments materialise as:

1. `i` is written by the loop canonicalisation: when `i++` is a latch statement it
   is emitted **first**, taking top priority over its textual position (all 24 tail
   permutations agree); when `i++` sits in the condition it is emitted at its
   evaluation point (last, adjacent to the compare).
2. The remaining increments are a contiguous **cyclic rotation** of an invariant
   cycle `C = (j_2, e, <pair>)`, where `<pair>` is the trio's forward definition
   order in the body:
   - `(sh, g)` when `g = base + i*2` is defined *after* the first `i*36` use (the
     "M1" geometry; `e = base + i; store(+0); g = ...; store(+4); ...`),
   - `(g, sh)` when it is defined *before* (the "old" geometry).
3. The rotation start of `C` after `i`:

| condition in source | emitted order | batches |
|---|---|---|
| `i++` preceded by `j_2 += 3` in the tail | `[i, e, <pair>, j_2]` (start at element 2) | batch4/8 full 24-perm sweeps |
| `i++` before `j_2 += 3` in the tail | `[i, <pair>, j_2, e]` (start at element 3) | same sweeps |
| `i` absent from the tail (post-inc in the condition) | `[j_2, e, <pair>, i]` (start at element 1; i last) | G1 |
| `i` pre-inc in the condition | `[i, e, <pair>, j_2]` (same as row 1) | G2 |

4. Cross-checks on matched code:
   - the second (matched) loop has source tail `i++; k += 12; e++;` and emits
     `[i, e, k]` — i first, the byte-offset variable (`k`, like `j_2`) pushed last;
   - the five earlier matched loops in this function emit their increments in
     exact source order (`[i++, p += 0x44]` -> `w25/w26`;
     `[fzgx_loop_off_1601.value += 0x44; i++; e++;]` -> `w54..56`), i.e. no
     rotation exists there because those tails contain no `i`-vs-`j` ambiguity.

## Color model (measured; this is the blocker)

The trio webs get virtual registers in **forward definition order** (first def ->
highest vr): M1 body `e=71, sh=70, g=69`; old body `e=71, g=70, sh=69`. The stock
simplify order visits them `71 -> 70 -> 69` (capture `simplify_order` positions
1..3 are exactly `[71, 70, 69]` in both faces) and colors descend `r31, r30, r29`
— cross-checked on the second loop (`k=39 -> r28`, `e=51 -> r26`, `i=57 -> r24`
via later saved-color claims).

* Retail colors require the **M1** vrs: `v(e) > v(sh) > v(g)`.
* Retail's emitted pair `(e, g, sh)` at `w307..309` requires the **old** geometry:
  the shadow's increment placed *after* g's, which is exactly what the old
  def-order produces.

Every reachable source shape couples both: the shadow's latch position and its web
vr both derive from the same def/use geometry (`g = base + i*2` vs the first
`i*36`). ~60 variants over 10 batches never decouple them.

## Exhausted levers (all offline, no claims)

- **batch4** (M1, all 24 tail permutations): exactly 2 families, best 5 diffs
  (`Q_bacd`, perm `bacd`).
- **batch6/8** (old geometry, all 24 permutations): all 14 diffs; colors flip to
  `g=r30 / sh=r29` (wrong) and the pair becomes `(g, sh)`.
- **batch7** G1 (`while (i++ < 4)`, tail `[j_2, e, g]`): `[j_2, e, sh, g]` + i last
  — the right start, but i is last and the form runs 5 iterations (semantically
  infeasible; rejected on fidelity). G2 (`while (++i < 4)`) collapses to family 2.
- **batch9** U1..U8 (`i += 1`, `++i`, `j_2 = j_2 + 3`, `g = &g[2]`, comma-attached
  tails, inline `(u32)(base + i)`): all exactly 5 diffs, identical rows.
- **batch10**: O1 (old body + G1 structure): 17 diffs `[j,e,g,sh]`+i last, wrong
  colors; O2 (old body + pre-inc): 14 diffs; M2 (while-form, increments last in
  body): 6 diffs `[sh, g, j, e]`+i last; M3 (`j_2` moved into the condition via
  comma): 6 diffs, same; G4/G5/G6 (`g = base + i + i`, split `g = base + i; g += i`)
  collapse the whole-function allocation (197..199 diffs, `or. r23/r24`).
- **batch5** X1..X8 (declared shadow variable route): 18..27 diffs.
- **batch11** (entry `lis` probes): E1/E2 `u32 arg = arg0;` after the pool
  declaration (with and without the raw-parameter test) and E5/E6 with family-1
  tails — all still emit `lis r3` at 5..6 diffs; the front-end coalesces the
  explicit copy back into the entry homing copy `mr vr32<-vr3` at pcode idx0, so
  the raw parameter web dies before the lis.
- **Declared/mid-block shadow, statement-splitting, for-loops, comma chains,
  pre/post increments**: no gain (see batches 4..11 in `/tmp/opencode/p118/`).

## The `lis r4` mechanism (matches the checkpoint analysis)

Our entry pcode: `idx0 mr vr32<-vr3` (homing copy, line -1), `idx1 lis vr89`,
`idx2 cmpli vr32`, `idx3 addi vr90<-vr89`, `idx4 bt`; the lis temp gets physical
r3. Retail needs physical r3 to be **live across the lis temp's pcode range
`[idx1..idx3]`** (some web holding r3 there); with the param copy at idx0 nothing
does. All copy-position spellings probed so far (source-level copy before/after
the pool declaration, test on the copy or on the raw parameter) coalesce to the
same entry copy and keep `lis r3`.

## Stopping statement

Per the orchestrator contract (repeat batches need a measured shared cause and an
explicit stopping condition): batches 7..11 measured the shared cause — the latch
start/pair geometry and the trio vrs both derive from the same `base + i*2` vs
first-`i*36` def/use positions — with **zero closure gain** (best unchanged at 5
words over ~60 additional variants). Search stopped; the frontier body above is
the archived start for any future capture/constraint-based session.

## Artifacts

- best body: `/tmp/opencode/p118/var/Q_bacd.c` == archived attempt
  `.fzgx/attempts/fn_1_118D90.1792292741.{c,json}`.
- allocator captures: `/tmp/opencode/capout118/fn_1_118D90.json` (baseline/old),
  `/tmp/opencode/capout118b/fn_1_118D90.json` (M1 vr swap),
  `/tmp/opencode/capout118q/fn_1_118D90.json` (Q_bacd).
- variant objects: `/tmp/opencode/p118/varobj4` (M1 24 perms), `varobj8` (old 24),
  `varobj9..11` (spelling/probe batches); scripts `/tmp/opencode/p118/batch4..11.py`.
- archive/repro command: `.venv/bin/python /tmp/opencode/p118/archive_q.py`
  (copies the body to `.fzgx/attempts/` and records the local objdiff percent;
  offline, no ledger use).
