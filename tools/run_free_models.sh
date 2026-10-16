#!/usr/bin/env bash
# Batch driver for free-model decompilation test (all his free families).
set -u
cd "$(dirname "$0")/.."
export FZGX_MAX_MODEL_INPUT_TOKENS=128000
export FZGX_MAX_MODEL_OUTPUT_TOKENS=16000

echo "=== models to test ==="
python3 tools/test_batch.py \
  --symbols "fn_3_1ADA4 fn_3_1AEE4 fn_3_1B008" \
  --models \
  "nous:solar-pro4:free" \
  "nous:poolside/laguna-s-2.1:free" \
  "nous:meituan/longcat-2.0:free" \
  "nous:poolside/laguna-xs-2.1:free" \
  "opencode-free:muse-spark-1.2-contributor-free" \
  "opencode-free:nemotron-3.5-lightning-free" \
  "openrouter:thinkingmachines/inkling:free"
echo "=== batch done ==="
