#!/bin/sh
# run every consolidator (apply) until the unit count stops falling
cd /home/armandofm/projects/fzgx || exit 1
count() { python3 -c "import json;print(len(json.load(open('config/GFZE01/units.json'))))"; }
prev=$(count)
for round in 1 2 3 4 5; do
  timeout 1500 python3 tools/consolidate/apply_unpooled_all_v3.py 2>&1 | grep -E "^Applied|VERIFIED" | tail -1
  for s in apply_reloc_derived_multi_primer apply_multisection_rels apply_reloc_derived_dol_mm apply_multisection_dol_mm; do
    timeout 1500 python3 tools/consolidate/$s.py --apply 2>&1 | grep -E "^Applied|VERIFIED" | tail -1
  done
  now=$(count); echo "round $round: $prev -> $now units"
  [ "$now" = "$prev" ] && break; prev=$now
done
