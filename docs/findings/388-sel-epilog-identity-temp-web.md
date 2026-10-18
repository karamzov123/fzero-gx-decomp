# 388 - sel:_epilog: an optimizer-folded identity gives the loaded value an anonymous temp web

Symbol: `sel:_epilog` (sel, 556 B, 139 words). Landed byte-exact: commit
`406595bf` (verify fast path 10.6 s, `16 files OK`). Before this pass: 10
attempts, best 99.64029 - which was an engine artifact of masked flag
constants; the semantically true plain body sat at 97.84 and the
register-work order (`base; mgr; state; f`) at 95.68.

## The residual, exactly

Target rows 0-12 and rows 12-16 (`retail | ours`, s3 statement order):

```
 3  lis  r5, lbl_10_bss_0@ha      |  lis  r4, lbl_10_bss_0@ha     *
 9  addi r29, r5, lbl_10_bss_0@l  |  addi r29, r4, ...            *
11  lwz  r4, 0x94(r31)            |  lwz  r5, 0x94(r31)           *
12  rlwinm r3, r4, 0, 28, 26      |  rlwinm r3, r5, ...           *
13  clrrwi. r0, r4, 31            |  clrrwi. r0, r5, ...          *
15  rlwinm r3, r4, 0, 28, 25      |  rlwinm r3, r5, ...           *
```

Retail: `A@ha` (state materialisation) = `r3`, `f` (the loaded flag word) =
`r4`, `B@ha` (base materialisation) = `r5`, state = `r31`, base = `r29`,
mgr = `r30`. Our s3 body already had `A@ha` = `r3`, state/base/mgr right and
instruction order identical - the whole residual was the `f` / `B@ha` pair
swap. The other order (`state; f; base; mgr`) gets `f` = `r4` right but pays
for it by swapping the two `@ha` pairs instead.

## The allocator model this needed (capture-verified)

- Locals occupy slots `32..32+n-1` in reverse textual declaration order
  (a block-local declared last gets the *lowest* slot). Each statement then
  consumes a fresh 2-temp pair in statement order; the symbol materialisations
  use their pair (`lis` t, `addi` t'), plain assignments leave theirs unused.
- Simplify/coloring is the captured order: spill candidates first, then
  descending vreg. **A named local always colors after every statement temp**
  - for s3's order `f` is vr33 and `B@ha` vr38, so `f` colors after `B@ha`,
  is blocked by its `r4`, and lands `r5`.
- The replay-verified witness: `f`'s web must be one of the s3 statement-pair
  temps between the two materialisations, `{39..41}` or above `A@ha`,
  `{44,45}`. Then masks -> `r3`/`r0`, `f` -> `r4`, `A@ha` -> `r3`, `B@ha`
  blocked on `{r0, r3, r4, r31}` -> `r5` - retail exactly.

So the source had to give the loaded value an **anonymous temporary web**
while the assignment target stayed the named local `f`.

## What did not move it (measured, all flat 95.68 or no change)

Every spelling that assigns the load to a named local writes the local's vreg
directly. Dead-identity operators (`& 0xFFFFFFFF`, `+ 0`, `| 0`, `^ 0`,
`>> 0`, `* 1`, `- 0`, `~(~v)`, `-(-v)`, `v & v`, `v | v`, `v - (v - v)`,
`v ^ (v ^ v)`, `v + (v - v)`, `v | (v & ~v)` at the *front end*), assignment
inside the store (`*(...) = (f = load) & mask`), qualifiers
(`volatile`/`const`/`register`), comma forms, one-field-struct carriers (the
plain carrier scalarises back; the block-copy carrier moves the value to the
*last-declared* slot - the wrong direction), redundant self-stores
(`*(...) = *(...)`, `|= 0`, `&= -1`; the optimizer removes the extra store but
keeps the local), empty-if/CSE pairs, `switch`/`do-while` conditions,
inline-helper wrappers, and a GC/1.3 - 2.7 compiler sweep (all builds
identical for this function). `fzgx fixup --captures` could not help either:
the capture status is `needs-web-alignment` (our `r4` covers two retail roles)
and the carrier/declaration families stay gated.

## The mechanism that worked

```c
f = *(u32 *)(state + 0x94) & (*(u32 *)(state + 0x94) | ~*(u32 *)(state + 0x94));
```

`v & (v | ~v)` is exactly `v` for every `u32`. The front end cannot fold it
(it would need `a | ~a = -1`, which it does not apply), so the three reads
stay *operands* of the expression and the loaded value lands in this
statement's anonymous temporary. MWCC's optimizer then knows
`a | ~a = -1` and `a & -1 = a`, folds the whole expression to a copy of the
loaded value, and the coalescer keeps the **temporary** (the same survivor
direction as the `lis`/`addi` materialisations, where the named local dies).
The temporary's number is the statement pair - fourth statement in the s3
order -> vr44/45 - so it colors `r4` between `A@ha` (`r3`) and `B@ha` (`r5`).
139/139 words, 0 differing rows.

Measured siblings of the same idea: `f = v & (v | ~v);` is 100.00;
`v & v`, `v | v`, `v ^ (v ^ v)`, `v - (v - v)`, `v | (v & ~v)`,
`v + (v - v)` all fold at the front end back into the plain assignment
(95.68, no change). The distinguishing property is exactly
*front-end-invisible / optimizer-visible*.

Semantics are exact (not a mask hack like the old 99.64 body): the emitted
object contains a single `lwz`, identical to retail.

## Commands that landed it

```
fzgx claim sel:_epilog --agent ... --max-attempts 12
fzgx write-unit sel:_epilog --file <body>.c   # auto-check: 100.0% MATCH
fzgx submit sel:_epilog --agent ...
fzgx verify                                    # fast path, commit 406595bf
```

## Generalization

When a capture reports `needs-web-alignment` / `web-hypothesis` *because a
value has to live in an anonymous temp web*, and carriers / declaration
orders cannot reach it (they can only move values **down** the local
stratum), an optimizer-visible/front-end-invisible identity in the assigning
expression is a source-realizable lever: it re-homes exactly that value's web
and emits the same instructions. Candidates: `v & (v | ~v)`, and any other
identity the front end does not simplify but `-O4` value numbering does.
