# GFZE01 source-debt census

Run `python tools/fzgx.py devicecensus` for the live summary, or add `--json` for every source location, owner and input fingerprint. The command is read-only: it does not compile, change claims, or update the ledger.

## Measured checkpoint

The latest source fingerprint and complete compressed inventory are retained in `state/repairs/device-census-primers-20261116.json.gz`; `state/repairs/mota-shared-layout-20261116.json` records the source change and validation. The earlier warning/review-only inventory remains in `state/repairs/device-census-20261116.json.gz` with its original evidence manifest. Each inventory records its base commit and explicitly notes modified source/configuration; the source-tree digest identifies the measured contents independently of that base.

| Category | Spots | Files | Owner functions |
| --- | ---: | ---: | ---: |
| Explicit device-warning comments | 37 | 12 | 13 |
| ADX dead-write macro uses | 7 | 1 | 1 |
| Synthetic `.fzgxpool` primer function definitions | 10,630 | 145 | 958 |
| Optimization-setting directives (excluding reset/push/pop) | 945 | 273 | 695 |
| Anonymous one-field `value` scalar-carrier shapes | 272 | 97 | 179 |
| Other `fzgx_` function definitions requiring review | 4 | 4 | 4 |
| `volatile` tokens | 15,470 | 389 | 1,235 |

The explicit-warning and ADX-use owner-function union is **13**, not 14. One shared-header warning has no single function owner. Warnings are spots, not distinct devices: several comments can describe the same device and one comment can describe several. The directive, carrier-shape and volatile rows are **review queues, not confirmed device totals**. Hardware volatility, SDK implementation requirements and legitimate aggregate types must not be counted as defects without review.

Including the confirmed synthetic layout-primer owners raises the distinct known-scaffolding owner-function union to **967**. There are 72 primer definitions in shared/unassigned scope, beyond the 958 mapped primer owners. Primer counts are physical definitions, including repeated source copies; they are not 10,630 distinct original data objects or instructions executed by retail. Four synthetic-name helpers outside `.fzgxpool` stay review-only. An independent balanced-parenthesis scan and separate section/attribute classifier agree with every one of the 10,634 synthetic definitions, including function-pointer parameters.

The current configured retail-function denominator is 7,351: 7,159 C-form, 186 standalone-assembly, five reviewed original-assembly, and one mixed function. These categories describe source form, not natural-C completion. Original assembly is legitimate when evidenced; the 192 outside-pure-C forms are not automatically C-conversion debt. Raw ledger totals can also retain retired entries, so they are not the source-form denominator.

## Scope and limitations

The scanner visits physical `src` and `include` C/C++/assembly files once, excluding generated build copies. It recognizes warning markers only inside comments and review tokens only outside comments/strings. Function ownership comes from matching configured units and physical TU block boundaries; shared helpers, primers and headers can affect additional consumers that this inventory does not infer. Public symbols are module-qualified. Every finding carries its path and source line; the JSON includes source/configuration fingerprints and unresolved owners.

This is a reproducible marked-debt lower bound and a review queue, **not a certified count of all remaining compiler devices, type/data recovery work, or device-free functions**. An unmarked function is not certified natural.

## Cleanup evidence

The first census-guided pass froze the 32 smallest single-function carrier owners. All 32 installed controls matched; none of the 66 removal-only or combined carrier/pragma probes matched. They are retained in `state/repairs/small-carrier-removals-20261116.sources.json.gz`, not installed.

A subsequent computation-based probe removed the carrier in `movie_module:fn_12_38680`: a real inline resource-offset computation performs the lookup and mode adjustment, rather than using an aggregate to steer allocation. It preserves the null guard, base-call ordering and unsigned arithmetic, emits no extra helper, and matches the retail object and relocations. The rounded-quotient alternatives for `main:fn_80059C0C` still differ by four aligned words and remain unaccepted.

All 103 probe bodies were reconstructed and recompiled using the shared repair archive replay. Their source-SHA sets, match verdicts and aligned-word error counts agree with the original measurements. The accepted source also passes lint and all 16 linked retail hashes. Removing one carrier reduces that review row from 274 to 273; it does not reduce the warning count and is not credited as project-wide natural-source completion.

The next recovery shares four constructor-evidenced layouts (`MotaSignal`, `MotaEntry`, `MotaTrack`, `MotaList`) between `fn_1_41518` and `fn_1_41C18`. The name binder now uses an ordinary typed indexed loop with no offset carrier or manually maintained byte stride. Both functions still match retail objects and relocations. Real MWCC-emitted layout data verifies four sizes and seven relevant offsets; the list remains only the observed 0x50-byte prefix of its 0x60-byte allocation, without inventing the tail. All eight source probes replay with identical hashes, verdicts and aligned errors, and all 16 linked hashes plus lint pass. This removes one more carrier, leaving 272 in the review queue; unrelated constructor devices are not credited as removed.
