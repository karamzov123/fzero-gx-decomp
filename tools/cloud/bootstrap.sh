#!/usr/bin/env bash
# Prepare a Claude cloud session (Anthropic-hosted VM) to build, check and verify.
#
# The session must have two repositories attached: this one and the private
# karamzov123/fzgx-build, which holds orig/GFZE01 and the `toolchain-*` release.
# The VM's GitHub proxy serves only attached repositories and its network
# allowlist omits files.decomp.dev, so configure.py cannot download its tools;
# they come from that private release instead. Idempotent; safe to rerun.
set -euo pipefail

TOOLCHAIN_TAG=toolchain-20261021
TOOLCHAIN_SHA=493a509950e9b575711dfa9fc6b5b04228cbee6c0e212e9d2f00992de142f474

repo=$(git -C "$(dirname "$0")" rev-parse --show-toplevel)
build_repo=${FZGX_BUILD_REPO:-$(dirname "$repo")/fzgx-build}
cd "$repo"

if [ ! -f "$build_repo/orig/GFZE01/sys/main.dol" ]; then
    echo "bootstrap: $build_repo/orig/GFZE01 missing; attach karamzov123/fzgx-build to the session" >&2
    exit 1
fi
mkdir -p orig/GFZE01
cp -rn "$build_repo/orig/GFZE01/." orig/GFZE01/

if [ ! -x build/tools/dtk ] || [ ! -d build/compilers/GC ]; then
    tmp=$(mktemp -d)
    gh release download "$TOOLCHAIN_TAG" -R karamzov123/fzgx-build -p fzgx-toolchain.tar.zst -D "$tmp"
    echo "$TOOLCHAIN_SHA  $tmp/fzgx-toolchain.tar.zst" | sha256sum -c -
    mkdir -p build
    tar -C build --zstd -xf "$tmp/fzgx-toolchain.tar.zst"
    rm -f "$tmp/fzgx-toolchain.tar.zst"
fi

uv sync -q
python3 configure.py --version GFZE01 \
    --compilers build/compilers --binutils build/binutils \
    --dtk build/tools/dtk --objdiff build/tools/objdiff-cli --wrapper build/tools/wibo
ninja build/GFZE01/ok
uv run tools/fzgx.py sync
uv run tools/fzgx.py restore
echo "bootstrap: ready ($(nproc) CPUs); all 16 target hashes pass"
