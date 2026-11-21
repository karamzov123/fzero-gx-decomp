#!/bin/sh
# Reclaim disk space from regenerable caches and old search history.
#
#   sh tools/clean_caches.sh                 # dry run: show what would go and how big it is
#   sh tools/clean_caches.sh --apply         # delete the regenerable caches (tier 1)
#   sh tools/clean_caches.sh --apply --history
#                                            # also archive old search history to .fzgx/archive
#                                            # (zstd) and delete the originals (tier 2)
#
# Never removes build/ or .fzgx/ themselves, the ledger (.fzgx/ledger.db), orig/, or any
# worktree with uncommitted tracked changes. Run from the repository root while no batch,
# fleet or build is running.
set -eu
cd "$(dirname "$0")/.."
[ -f configure.py ] && [ -d .fzgx ] || { echo "run from the fzgx repository"; exit 1; }
APPLY=0; HISTORY=0
for a in "$@"; do
  case "$a" in --apply) APPLY=1 ;; --history) HISTORY=1 ;; *) echo "unknown option $a"; exit 1 ;; esac
done
if pgrep -f "orchestrate.py|fleet_multi|fleet.py daemon|steer_prune|fzgx.py (verify|fixup|sweep)" >/dev/null 2>&1; then
  echo "a batch or verifier is running; stop it first"; exit 1
fi
size() { du -xsh "$@" 2>/dev/null | awk '{s=s" "$1"\t"$2"\n"} END {printf "%s", s}'; }
say() { printf '%s\n' "$*"; }

say "== tier 1: regenerable caches"
say "-- compiled donor-signature cache (rebuilt on demand by sourcealign)"
size .fzgx/signatures
say "-- compiler outputs (*.o) of scratch C under .fzgx (rebuilt by the next check)"
find .fzgx -path .fzgx/archive -prune -o -type f -name '*.o' -printf '%s\n' 2>/dev/null \
  | awk '{s+=$1} END {printf "%.1f GB in .o files\n", s/1e9}'
say "-- build/ of preserved worktrees (rebuilt by configure + ninja there)"
for w in .worktrees/*/; do [ -d "$w/build" ] && size "$w/build"; done
STALE=""
for w in .worktrees/*/; do
  [ -d "$w" ] || continue
  if ! git worktree list --porcelain | grep -qx "worktree $(realpath "$w" | sed 's#/$##')"; then
    STALE="$STALE $w"
  fi
done
if [ -n "$STALE" ]; then
  say "-- stale worktree copies (no git metadata; archived in .fzgx/archive/stale-worktree-copies-*.tar.zst)"
  # shellcheck disable=SC2086
  size $STALE
fi

if [ "$APPLY" = 1 ]; then
  if [ -n "$STALE" ]; then
    ls .fzgx/archive/stale-worktree-copies-*.tar.zst >/dev/null 2>&1 || { echo "stale copies are not archived; stop"; exit 1; }
  fi
  find .fzgx/signatures -type f \( -name '*.pickle' -o -name '*.lock' \) -delete
  find .fzgx -path .fzgx/archive -prune -o -type f -name '*.o' -print0 | xargs -0 -r rm -f
  for w in .worktrees/*/; do [ -d "$w/build" ] && rm -rf "$w/build"; done
  # shellcheck disable=SC2086
  [ -n "$STALE" ] && rm -rf $STALE
  git worktree prune
  say "tier 1 done"
fi

HIST=".fzgx/fixup .fzgx/harvest .fzgx/analysis .fzgx/sweep-2310 .fzgx/buffy-sweep .fzgx/buffy-3ED8C \
      .fzgx/hermes-semantic-cohort .fzgx/hermes-rel-entrypoint-layout .fzgx/hermes-large-3B24-repair \
      .fzgx/hermes-frontier-refresh .fzgx/solo-fifth-independent-state .fzgx/solo-seventh-state \
      .fzgx/continue-near-fresh .fzgx/donordraft"
say "== tier 2: old search history (repair candidates, reports, harvest runs; all functions match)"
for d in $HIST; do [ -d "$d" ] && size "$d"; done
say "-- kept: .fzgx/fixup-archives (portable repair archives, already gzip), work/, attempts/, checks/, ledger"
if [ "$APPLY" = 1 ] && [ "$HISTORY" = 1 ]; then
  mkdir -p .fzgx/archive
  for d in $HIST; do
    [ -d "$d" ] || continue
    out=".fzgx/archive/$(basename "$d").tar.zst"
    say "archiving $d -> $out"
    tar -I 'zstd -6 -T0' -cf "$out.tmp" "$d"
    n_src=$(find "$d" -type f | wc -l); n_arc=$(tar -I zstd -tf "$out.tmp" | grep -vc '/$')
    [ "$n_src" = "$n_arc" ] || { echo "archive of $d is incomplete ($n_arc of $n_src files); kept"; rm -f "$out.tmp"; continue; }
    mv "$out.tmp" "$out" && rm -rf "$d"
  done
  say "tier 2 done; restore any directory with: tar -I zstd -xf .fzgx/archive/NAME.tar.zst"
fi
[ "$APPLY" = 1 ] || say "(dry run; pass --apply to delete)"
df -h . | tail -1
