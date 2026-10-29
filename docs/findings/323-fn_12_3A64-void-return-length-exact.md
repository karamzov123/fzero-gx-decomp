# `fn_12_3A64`: the missing return value, and a length-exact residual

`fn_12_3A64` (movie_module, 852 B / 213 words) had 13 attempts and a stored best
of 99.5%. It is one source fact away from being a pure colouring problem.

## The fact: retail's function returns nothing

Retail's epilogue is a bare frame teardown, with no conversion and no
materialisation into `r3`:

```
0340  lmw  r26, 0x48(r1)
0344  lwz  r0, 0x64(r1)
0348  mtlr r0
034c  addi r1, r1, 0x60
0350  blr
```

At that point `r3` still holds the `0x4330` integer-to-double bias constant
loaded at `0288  lis r3, 0x4330`. A function whose return value were `s8`,
`u8`, `s32` or `u32` would have to put its result in `r3` first, so this is not
a narrow return type: the body has no `return` statement.

The saved body declared `s8 fn_12_3A64(...)` and ended with
`return (u32)far_z;`, which emitted `extsb r3, r29` — an **extra instruction**
(214 words against retail's 213) that shifted the last five rows.

Two measurements separate the two possibilities rather than guessing:

| Body | Words | `r3` at the epilogue |
| --- | ---: | --- |
| `s8` + `return (u32)far_z;` (saved best) | 214 | `extsb r3, r29` |
| `u32` + `return far_z;` | 214 | `mr r3, r29` |
| `void`, no return | **213** | untouched |

Both narrow-return spellings materialise a result; only the `void` body matches
retail's length. So the return is genuinely absent and `sfxzmv_MakeCnvZTbl`'s
last call is the final statement.

## What is left: a two-register offset, not a length problem

The `void` body compiles to 213 words with retail's frame (`0x60`),
`stmw/lmw r26, 0x48(r1)`, and 20 differing rows that are **all register
numbers**:

```
0010  RETAIL mr r28, r5   | OURS mr r29, r5      <- table
0018  RETAIL mr r27, r3   | OURS mr r28, r3      <- object
001c  RETAIL mr r26, r4   | OURS mr r26, r4      <- index (agrees)
```

`index` already agrees, so this is not a uniform band shift: `object` and
`table` are each one callee-saved register high, while `index` and the six
saved registers (`r26..r31`) are unchanged. Retail keeps `table` in `r28`
*and* re-materialises it as `addi r31, r5, 0` for the table-relative
arguments; we coalesce those onto the same register.

## Search result

The deterministic engine on this seed (`--rounds 3 --beam 4
--max-candidates 2500`) evaluated **3,497** candidates across its declaration,
carrier, operand, inline and pragma families. No exact object; the residual
stayed at the same 20-row colour permutation. That matches the recorded floor
for the `movie_module` clone family, so the next lever is not more spellings:
it is the same `object`/`table` split retail makes at `0x24`, i.e. forcing
`table` to remain separately addressable while the object pointer settles one
register lower.

The length-exact body is saved at
`.fzgx/attempts/fn_12_3A64.voidret.<ts>.c` so this is resumable.
