#!/usr/bin/env python3
"""Amusement Vision LZSS (.lz) used by F-Zero GX and Super Monkey Ball.

This is the FF7-style LZSS (4 KiB ring buffer, 3..18 byte matches) with an
8-byte header of two little-endian u32s: compressed payload size (excluding
the header) and uncompressed size. The decoder mirrors the retail routine in
fze.sample.rel (ring buffer starts at index 0xFEE, first 0xFEE bytes zeroed,
flag byte bit set = literal, clear = 2-byte back-reference whose 12-bit
offset is an absolute ring index).

Decompression is byte-exact by construction. Compression is the classic
binary-tree LZSS encoder (Haruhiko Okumura, 1989, public domain) with a
zero-filled ring instead of spaces: N=4096, F=18, THRESHOLD=2, r=N-F. That is
the encoder the retail files were produced with: on GFZE01 it reproduces
enemy_line/line__.bin's compressed main.rel byte for byte. tools/prepare_orig.py
checks this, and tools/build_disc.py relies on it.
"""

from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path

RING = 0x1000
RING_START = 0xFEE
MIN_MATCH = 3
MAX_MATCH = 18


def decompress(data: bytes) -> bytes:
    comp_size, uncomp_size = struct.unpack_from("<II", data, 0)
    end = comp_size + 8
    if len(data) < end:
        raise ValueError(f"truncated: header says {end} bytes, have {len(data)}")
    ring = bytearray(RING)
    pos = RING_START
    out = bytearray()
    src = 8
    flags = 0
    while True:
        flags >>= 1
        if not flags & 0x100:
            if src >= end:
                break
            flags = data[src] | 0xFF00
            src += 1
        if flags & 1:
            if src >= end:
                break
            b = data[src]
            src += 1
            out.append(b)
            ring[pos] = b
            pos = (pos + 1) & 0xFFF
        else:
            if src + 1 >= end:
                break
            b0, b1 = data[src], data[src + 1]
            src += 2
            off = b0 | ((b1 << 4) & 0xF00)
            n = (b1 & 0xF) + MIN_MATCH
            for k in range(n):
                b = ring[(off + k) & 0xFFF]
                out.append(b)
                ring[pos] = b
                pos = (pos + 1) & 0xFFF
    if len(out) != uncomp_size:
        raise ValueError(f"size mismatch: header {uncomp_size}, decoded {len(out)}")
    return bytes(out)


def compress(data: bytes) -> bytes:
    """Okumura binary-tree LZSS, byte-exact with the retail encoder."""
    n_ring, f, threshold, nil = RING, MAX_MATCH, MIN_MATCH - 1, RING
    lson = [nil] * (n_ring + 1)
    rson = [nil] * (n_ring + 257)
    dad = [nil] * (n_ring + 1)
    text = bytearray(n_ring + f - 1)
    match_len = match_pos = 0

    def insert(r: int) -> None:
        nonlocal match_len, match_pos
        cmp = 1
        p = n_ring + 1 + text[r]
        rson[r] = lson[r] = nil
        match_len = 0
        while True:
            if cmp >= 0:
                if rson[p] != nil:
                    p = rson[p]
                else:
                    rson[p] = r
                    dad[r] = p
                    return
            else:
                if lson[p] != nil:
                    p = lson[p]
                else:
                    lson[p] = r
                    dad[r] = p
                    return
            i = 1
            while i < f:
                cmp = text[r + i] - text[p + i]
                if cmp:
                    break
                i += 1
            if i > match_len:
                match_pos, match_len = p, i
                if i >= f:
                    break
        dad[r], lson[r], rson[r] = dad[p], lson[p], rson[p]
        dad[lson[p]] = dad[rson[p]] = r
        if rson[dad[p]] == p:
            rson[dad[p]] = r
        else:
            lson[dad[p]] = r
        dad[p] = nil

    def delete(p: int) -> None:
        if dad[p] == nil:
            return
        if rson[p] == nil:
            q = lson[p]
        elif lson[p] == nil:
            q = rson[p]
        else:
            q = lson[p]
            if rson[q] != nil:
                while rson[q] != nil:
                    q = rson[q]
                rson[dad[q]] = lson[q]
                dad[lson[q]] = dad[q]
                lson[q] = lson[p]
                dad[lson[p]] = q
            rson[q] = rson[p]
            dad[rson[p]] = q
        dad[q] = dad[p]
        if rson[dad[p]] == p:
            rson[dad[p]] = q
        else:
            lson[dad[p]] = q
        dad[p] = nil

    out = bytearray(8)
    code = bytearray(17)
    ptr, mask = 1, 1
    s, r = 0, n_ring - f  # r == RING_START; text[0:r] stays zero
    src, n = 0, len(data)
    length = 0
    while length < f and src < n:
        text[r + length] = data[src]
        src += 1
        length += 1
    if length:
        for i in range(1, f + 1):
            insert(r - i)
        insert(r)
    while length > 0:
        if match_len > length:
            match_len = length
        if match_len <= threshold:
            match_len = 1
            code[0] |= mask
            code[ptr] = text[r]
            ptr += 1
        else:
            code[ptr] = match_pos & 0xFF
            code[ptr + 1] = ((match_pos >> 4) & 0xF0) | (match_len - (threshold + 1))
            ptr += 2
        mask = (mask << 1) & 0xFF
        if not mask:
            out += code[:ptr]
            code[0] = 0
            ptr, mask = 1, 1
        last = match_len
        i = 0
        while i < last and src < n:
            delete(s)
            text[s] = data[src]
            if s < f - 1:
                text[s + n_ring] = data[src]
            src += 1
            s = (s + 1) & (n_ring - 1)
            r = (r + 1) & (n_ring - 1)
            insert(r)
            i += 1
        while i < last:
            i += 1
            delete(s)
            s = (s + 1) & (n_ring - 1)
            r = (r + 1) & (n_ring - 1)
            length -= 1
            if length:
                insert(r)
    if ptr > 1:
        out += code[:ptr]
    struct.pack_into("<II", out, 0, len(out) - 8, n)
    return bytes(out)


def main(argv: list[str] | None = None) -> int:
    p = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    p.add_argument("mode", choices=["d", "c"], help="d=decompress, c=compress")
    p.add_argument("input", type=Path)
    p.add_argument("output", type=Path)
    a = p.parse_args(argv)
    data = a.input.read_bytes()
    a.output.write_bytes(decompress(data) if a.mode == "d" else compress(data))
    return 0


if __name__ == "__main__":
    sys.exit(main())
