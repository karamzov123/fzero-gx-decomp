# GC codegen blockers: symbol+const folding, load-with-update fusion, colour ties

Date: 2026-10-26. Manual session; no function landed. Measurements are
compiler-backed (word-exact comparison against the retail objects) and were
repeated across every compiler in `build/compilers/GC` (1.0, 1.1, 1.1p1, 1.2.5,
1.2.5n, 1.3, 1.3.2, 1.3.2r, 2.0, 2.0p1, 2.5, 2.6, 2.7, 3.0a3 … 3.0a5.2) with
the module flags unchanged.

## 1. `symbol + const` is always folded into displacements

`fn_1_15E27C` (main_rel, 45 instructions) reads only `lbl_1_bss_8FD68`, but
retail materialises the entry pointer in a register:

```
addi r4, r4, lbl_1_bss_8FD68@l     ; base
li   r0, 0
addi r5, r4, 0x40                  ; base + 0x40 as a value
lfs  f0, lbl_1_rodata_DD98@l(r3)
stb  r0, 0(r5) ...
```

Every source form tried produces the same two-instruction addressing instead
(`addi r3, r4, @l` with `0x40` folded into every displacement, 44 words):

- `Entry *e = &blk.entries[0]` / `blk.entries` / `&blk.b[0x40]`
- `(Entry *)((u8 *)&blk + 0x40)`, `(char *)`, `(u32 *)&blk + 0x10`, `(u32)&blk + 0x40`
- `Hdr *h = &blk; e = (Entry *)(h + 1)` and `(Entry *)&((Hdr *)&blk)[1]`
- pointer compound assignment (`p = (u8 *)&blk; p += 0x40;`), `p = &p[0x40]`
- array decay (`u8 lbl_1_bss_8FD68[]`), `void *` and `u32` intermediates
- `static inline` fill helper (4 calls, `-inline auto`), `do/while` macro
- `#pragma opt_*` / `peephole` / `scheduling` on and off; `-O0 … -O4,p`

`-schedule off` does reproduce the earlier `lis r4` / `lis r3` order but not the
`0x40` materialisation. Conclusion: the 45th word cannot be produced from C for
this body, so the retail source must have used an access form that is not
expressible in the recovered structs — treat this as a compile-shape blocker,
not a near-match to keep grinding.

## 2. Symbol load at displacement 0 fuses into `lwzu`

`fn_1_707C` (48 words) is one word off in the one-word tier, and the word is a
struct-offset error in the saved body: retail loads `obj` at 0, `entries` at 4,
`flags` at 8, while the saved body puts `obj` at 0xC. Fixing the layout
(`Obj *obj; Entry *entries; Flag *flags;`) is semantically right but drops the
function to 47 words, because the symbol's `@l` addi and the offset-0 load are
fused by every GC version:

```
retail:  addi r4, r4, lbl_1_bss_F68@l ; lwz r7, 0(r4)
ours:    lwzu r7, lbl_1_bss_F68@l(r4)      ; reloc moves onto the lwzu
```

The fused form is correct and one instruction shorter, and it does not depend on
`peephole`, `opt_lifetimes`, `opt_propagation`, `-schedule`, the opt level, or a
member-access versus raw-cast spelling (`head->obj`, `*(Obj **)&sym`,
`*(Obj **)(u32)&sym`, `void *`/`u32` base). Any function whose first access after
the base `addi` is at displacement 0 therefore cannot byte-match a retail body
that keeps the addi — the saved 48-word body only matches because it reads the
wrong field.

## 3. Residual ties are colour/schedule ties, not source shapes

Word-exact scores of the best saved bodies (standalone compile):

| symbol | words | diff | remaining difference |
|---|---|---|---|
| `fn_1_14BD94` | 39 | 2 | `stw r5,0x20(r31)` and `lbz r3,0(r3)` swapped |
| `fn_1_4B6D4` | 45 | 2 | retail hoists `lis r6` above `stwu`, ours does not |
| `fn_1_4EC74` | 78 | 3 | retail hoists `lwz r0,0x30(r3)` above `stw r31`/`mr r31,r3` |
| `fn_12_7870` | 20 | 6 | identical instruction sequence, `r0`/`r4` colours swapped |
| `fn_800288C4` | 63 | 2 | `subf r5,r7,r3` vs `subf r0,r7,r3` |

For `fn_1_14BD94` all 8 orderings of the four statements that produce the two
swapped instructions compile to the same words, and
`fzgx fixup fn_1_14BD94 --rounds 4 --beam 8 --limit 60` (1,798 variants) found no
exact match. For `fn_12_7870` 24 combinations of load order, store order,
declaration order, associativity and pragmas leave the allocation unchanged.
These classes need the allocator-evidence engine (`fzgx fixup --capture` /
`--captures`), which was not exercised here; `lldb` is available on this host.
