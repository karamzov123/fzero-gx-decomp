#!/bin/sh
# full pre-commit gate: three region builds + lint; prints one line per step
cd /home/armandofm/projects/fzgx || exit 1
for v in GFZP01 GFZJ01 GFZE01; do
  python3 configure.py --version $v >/dev/null || { echo "$v configure FAILED"; exit 1; }
  out=$(ninja build/$v/ok 2>&1); rc=$?
  echo "$v: rc=$rc stamp=$(stat -c %y build/$v/ok | cut -c12-19)"
  [ $rc -eq 0 ] || { echo "$out" | grep -E "FAILED|Error|error|mismatch|sha1" | head -20; exit 1; }
done
uv run tools/fzgx.py lint 2>&1 | tail -2
