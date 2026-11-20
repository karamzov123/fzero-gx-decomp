# TU consolidation tools

Deterministic passes that merge adjacent matched units into larger compile units and retire
`noprologue` blocks. Each candidate is accepted only when the compiled object is unchanged
(per-function `.text` bytes and relocations, or the whole unit's section bytes, relocations and
defined symbols); the full gate (`gate.sh`: three region builds + `fzgx lint`) still decides.
Run from the repository root; dry-run first.

| script | what it does |
|---|---|
| `consolidate_all.sh` | runs every merger below with `--apply` until the unit count stops falling |
| `apply_unpooled_all_v3.py [--dry-run]` | merges adjacent unpooled `.text`-only runs (REL, dol/, movie_module/) |
| `apply_reloc_derived_multi_primer.py [--dry-run]` | pooled REL merges; pool maps re-derived from relocations |
| `apply_reloc_derived_dol_mm.py [--dry-run]` | the same for dol/ and movie_module/ |
| `apply_multisection_rels.py`, `apply_multisection_dol_mm.py` | merges whose `.data/.rodata/.bss` must also be contiguous |
| `nopro_retire.py [--fix] [--apply] [TU...]` | drops `noprologue` when the prologue-deduped block leaves the unit's object identical; `--fix` reconciles duplicate/retyped declarations (`declfix.py`, cast views disabled) |
| `devprobe.py` | removes each pragma device's pragma and reports whether the unit's object is unchanged |
| `gate.sh` | GFZP01/GFZJ01/GFZE01 builds + lint |

Helpers: `apply_pooled_all.py` (ELF/relocation parsing), `apply_smart_dol_mm.py` (C file merge
with struct-tag renaming), `apply_dol_and_mm.py`, `apply_nopro_smart.py` (prologue-aware block
cleaning), `objsig.py` (order-independent object signature).

Measured limits (2026-11-20): with merges at a fixed point, the remaining `noprologue` blocks
disagree with their prologue on real types. Cast views (`(*(T *)&sym)`) would retire ~50 more
but were rejected as less natural than the self-contained block. All 36 pragma-device sites
change the object when the pragma is removed.
