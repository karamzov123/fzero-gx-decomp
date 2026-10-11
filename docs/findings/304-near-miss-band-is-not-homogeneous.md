# The >=98% near-miss band is not homogeneous: classification and where to aim

## Compiler-aware continuation (2026-10-11)

The historical 228-body audit below used one universal `GC/1.3.2` pin. A fresh
recheck of all 228 saved bodies tested `GC/1.3.2`, `GC/1.2.5n`, `GC/1.2.5`,
`GC/1.3`, `GC/2.0`, and the oracle's default candidate selection. This is a
bounded settings comparison, not proof of each retail translation unit's compiler.
Sources were frozen before dispatch; no ledger claims or accepted source were
changed by the audit. Structured `stuck.analyse(...).diffs` exclude proven accepted
rows rather than parsing display markers.

All original 26 one-row functions remain one-row with a tested pin. The new
minimum-row distribution is **27 / 36 / 78 / 77 / 10** for 1 / 2 / 3–8 / 9–32 /
33+ rows. There are **63** bodies within two rows, and **zero** exact oracle
matches. `fn_12_4D14` is the additional one-row function: `GC/1.3.2` with
`-use_lmw_stmw on` reduces five rows to one (`addi r28,r31,0` versus `mr r28,r31`).

Ten bodies improve over the fresh plain-1.3.2 baseline:

| function | plain 1.3.2 rows | selected rows | measured setting |
| --- | ---: | ---: | --- |
| fn_800288C4 | 48 | 2 | GC/1.2.5n |
| fn_80038944 | 21 | 11 | GC/1.2.5n |
| fn_8003A3D4 | 45 | 5 | GC/1.2.5n |
| fn_80020FA4 | 98 | 11 | GC/1.2.5n |
| fn_80022BF4 | 52 | 8 | GC/1.2.5n |
| fn_8008EBF8 | 17 | 2 | GC/1.2.5n |
| fn_12_D88 | 29 | 16 | GC/1.3.2, -use_lmw_stmw on |
| fn_12_25748 | 11 | 6 | GC/1.3.2, -use_lmw_stmw on |
| fn_12_22008 | 14 | 6 | GC/1.3.2, -use_lmw_stmw on |
| fn_12_4D14 | 5 | 1 | GC/1.3.2, -use_lmw_stmw on |

The selected portable sources and compiler pins are preserved in
`state/repairs/compiler-aware-304-20261011.json.gz`; its summary records the
settings sweep, complete denominator, structured row distribution and source
hashes. The old printed-row histogram below is historical and should not be
mixed with these structured row counts. A lower row count is diagnostic progress,
not an accepted function or a verified delivery.

### Pinned Hermes ultra retry

`pinned-onerow-hermes-ultra-20261011` requested the same five surgical targets
with explicit `GC/1.3.2` pins (and `-O4` for `fn_8008983C`), Hermes through Nous,
`stepfun/step-5-preview:free`, ultra effort, four concurrent sessions, sixteen
checks and the existing 240-second compiler-progress idle guard. Prompt receipts
confirmed the supplied compiler pin. Four sessions ended `timeout+released`,
zero matched, one was unstarted after the failed first wave. Three used only
the host's initial check; `fn_8008983C` made one model-issued `patch_unit` check
before becoming compiler-idle. All four retained their inherited best scores;
no new best or accepted function was delivered. Batch exit was 1, and the verifier
reported zero verified and zero rejected. This is fresh stall evidence for ultra,
not evidence of compiler-pin loss and not permission to silently lower the effort.

## Historical universally pinned audit

Audit of every unmatched function at best_percent >= 98.0 whose body is present locally
(228 functions, fleet-held symbols excluded), re-checked with
`oracle.check(source=<saved body>, mw_version='GC/1.3.2')`.

## Headline: the oracle-bug class is now empty

**0 of 228** remaining candidates have byte-identical instruction words with a non-empty
defect set. Before finding 303 there were 3 (`fn_1_9DB04`, `fn_1_15EC40`, `fn_8_2124`).
That class is exhausted, not merely reduced. Any *new* near-miss claiming to be
"relocation-only" or "no source-owned differing rows" is therefore a fresh defect worth
investigating on its own terms, not a recurrence.

## Distribution

| differing rows | functions |
| ---: | ---: |
| 1 | 26 |
| 2 | 34 |
| 3-8 | 74 |
| 9-32 | 87 |
| 33+ | 7 |

60 of 228 (26%) sit within 2 instruction rows of a match.

## The 26 one-row functions, by actual cause

| class | count | nature |
| --- | ---: | --- |
| retail `mr rD, rS`, ours `li rD, 0x0` | 7 | genuine register-allocation tie-break (finding 301's class) |
| mnemonic differs | 7 | struct/type reconstruction, NOT allocation |
| offset and/or base register wrong | 5 | struct-offset error |
| operand order | 1 | source expression order |

### The mnemonic class is the actionable one

    fn_80043798   retail extrwi r9, r10, 8, 16   ours srawi r9, r10, 8
    fn_800446E4   retail extrwi r9, r10, 8, 16   ours srawi r9, r10, 8
    fn_1_135D7C   retail mr    r4, r3           ours extsb r4, r3
    movie:_prolog retail sth   r11, 0x0(r10)    ours stw   r11, 0x0(r10)
    fn_8008983C   retail addi  r3, r31, 0x0     ours mr    r3, r31

`extrwi` vs `srawi` is unsigned vs signed extraction: the C is producing the wrong
field type, so two functions share one root cause. `sth` vs `stw` is a 16-bit vs 32-bit
store, i.e. a `u16` field typed as `u32`. `mr r4, r3` vs `extsb r4, r3` means retail does
not sign-extend, so the source value is already 32-bit. These are **type-reconstruction**
defects, not allocator floors — a single correct type change plausibly closes several at
once.

### The offset class

    fn_17_7728   retail lwz r6, 0x14(r7)    ours lwz r6, 0x74(r4)
    fn_1_2D038   retail lbz r0, 0x5(r3)     ours lbz r0, 0x35(r31)
    fn_12_331A8  retail stw r3, 0x4(r7)     ours stw r3, 0x0(r5)
    fn_80067DE4  retail addi r3, r31, 0x0   ours addi r3, r31, 0x4

Wrong base register *and* wrong offset means the wrong struct is being indexed, not a
within-struct offset typo. `fzgx structmap` is the right tool. `fn_80067DE4` differs only
in the immediate on the same base, i.e. an array-vs-scalar or index-vs-pointer
discrepancy.

## Correction recorded after a seeded batch was actually run

A batch of five of these was dispatched to the free model (space-bunny-free). It did not
close any of them, and the reason is worth recording because it is a property of the
class, not of the model:

    fn_8008983C  98.6%   held; the single predicted row (addi r3,r31,0x0 vs mr r3,r31) is the
                      only defect, confirmed exactly as classified
    fn_1_135D7C  99.6%   held, but a prologue conflict blocked submission
    movie:_prolog 99.5% held
    fn_80043798  19.4%   REGRESSED from 99.7%
    fn_800446E4  20.9%   REGRESSED from 99.7%

Two consequences:

1. **These one-row cases are not safe free-model targets.** A model asked to "improve the
   match" on a 99.7% function will rewrite the whole body rather than make the one
   surgical type change, and a wholesale rewrite destroys the near-miss. The ledger keeps
   the best attempt so nothing was lost here, but the attempt budget is spent for nothing.
   Aim one-row near-misses at a high-effort lane, or hand them the exact instruction pair
   to fix.

2. **Compiler selection dominates the apparent residual, and this is the real lesson.**
   `fn_80043798` under `GC/1.3.2` has **1** differing row (99.75%). Under the tool's
   default compiler resolution the same body has **128** differing rows (78.04%), and
   `fn_8008983C` goes from 1 row (98.57%) to 24 (67.21%). The unit records
   `mw_version: null`, so nothing in the manifest says which build retail used — the
   99.7% figures exist only because the audit pinned `GC/1.3.2` explicitly. The residual
   row is real under that pin, but a worker that lets the tool choose the compiler sees a
   catastrophically wrong body and will rewrite it. That is very likely what happened to
   `fn_80043798`/`fn_800446E4`.

   So before aiming any near-miss at a model, pin the compiler that reproduces the
   near-miss and hand it over, or the model will "fix" a body that was already correct.

   Confirmed in the batch logs: the worker's own checks for `fn_8008983C` ran under
   `GC/1.2.5` and `GC/2.0`, neither of which is the `GC/1.3.2` build the 99.6% figure
   depends on. The model was optimising against a body that looked 24 rows wrong.

3. `fn_8008983C` carries `extra_cflags: ['-O4']`, consistent with it compiling under
   `GC/2.0 -O4`. Per-function compiler assignment matters when classifying: a residual
   measured under the wrong build is not a residual.

### The genuine tie-break class (7)

    fn_12_72F4  retail mr r30, r25   ours mr r30, r27
    fn_1_4270C  retail mr r30, r29   ours li r30, 0x0
    fn_12_21C00 retail mr r29, r31   ours li r29, 0x0
    fn_1_1384C  retail mr r27, r30   ours li r27, 0x0
    fn_80077BD4 retail mr r30, r31   ours li r30, 0x0
    fn_12_2F730 retail mr r31, r0    ours li r31, 0x0
    fn_12_2F7AC retail mr r31, r6    ours li r31, 0x0

This is the only subset where "beyond the current automated tooling" is a defensible
claim. Note it is 7 functions, not 68.

## What this means for the residual

The "68 near-miss functions" figure conflates at least four distinct causes. Roughly a
third of the one-row set is a type or struct reconstruction error that ordinary
decompilation reasoning closes; roughly a quarter is a genuine allocator tie-break. Aim
the fleet at the mnemonic and offset classes first — they are real C work with a known
root cause, and one type fix can land several functions.
