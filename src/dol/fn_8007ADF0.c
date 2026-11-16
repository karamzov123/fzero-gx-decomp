#include "types.h"

#pragma opt_propagation off
void fn_8007ADF0(u32 arg0, u32 arg1) {
    u32 total;
    u32 next;
    u32 size;
    u32 previous;
    u32 size_2;
    u32 current;
    u32 off;
    u32 end;
    u32 block;
    block = arg0 + 0x10;
    *(u32 *)(arg0 + 0xc) = arg1 | 3;
    *(u32 *)(arg0 + arg1 - 8) = *(u32 *)(arg0 + 0xc);
    *(u32 *)(arg0 + 0x14) = arg0 | 1;
    *(u32 *)(arg0 + 0x10) = arg1 - 0x18;
    end = ((arg1) + (block));
    *(u32 *)(end - 0x1c) = arg1 - 0x18;
    *(u32 *)(arg0 + 8) = arg1 - 0x18;
    *(u32 *)(arg0 + (*(u32 *)(arg0 + 0xc) & ~7) - 4) = 0;
    size = *(u32 *)(0x10 + arg0) & ~7;
    *(u32 *)(arg0 + 0x10) &= ~2;
{
    u32 end_2;
    end_2 = block + size;
    *(u32 *)end_2 &= ~4;
    *(u32 *)(end_2 - 4) = size;
}
    off = (*(u32 *)(arg0 + 0xc) & ~7) - 4;
    if (*(u32 *)(arg0 + off) != 0) {
        *(u32 *)(block + 8) = *(u32 *)(*(u32 *)(arg0 + off) + 8);
        *(u32 *)(*(u32 *)(block + 8) + 0xc) = block;
        *(u32 *)(block + 0xc) = *(u32 *)(arg0 + off);
        *(u32 *)(*(u32 *)(arg0 + off) + 8) = block;
        *(u32 *)(arg0 + off) = block;
        current = *(u32 *)(arg0 + off);
        if (!(*(u32 *)current & 4)) {
            size_2 = *(u32 *)(current - 4);
            if (size_2 & 2) {
                previous = current;
            } else {
                previous = current - size_2;
                *(u32 *)previous &= 7;
                *(u32 *)previous |= (size_2 + (*(u32 *)current & ~7)) & ~7;
                if (!(*(u32 *)previous & 2)) {
                    total = size_2 + (*(u32 *)current & ~7);
                    *(u32 *)(previous + total - 4) = total;
                }
                {
                    u32 head = *(u32 *)(arg0 + off);
                    if (head == current) {
                        *(u32 *)(arg0 + off) = *(u32 *)(*(u32 *)(arg0 + off) + 0xc);
                    }
                }
                *(u32 *)(*(u32 *)(current + 0xc) + 8) = *(u32 *)(current + 8);
                *(u32 *)(*(u32 *)(*(u32 *)(current + 0xc) + 8) + 0xc) = *(u32 *)(current + 0xc);
            }
        } else {
            previous = current;
        }
        *(u32 *)(arg0 + off) = previous;
        current = *(u32 *)(arg0 + off);
        size_2 = *(u32 *)current & ~7;
        size = current + size_2;
        next = size;
        if (!(*(u32 *)next & 2)) {
            total = size_2 + (*(u32 *)next & ~7);
            *(u32 *)current &= 7;
            *(u32 *)current |= total & ~7;
            if (!(*(u32 *)current & 2)) {
                *(u32 *)(current + total - 4) = total;
            }
            if (!(*(u32 *)current & 2)) {
                *(u32 *)(current + total) &= ~4;
            } else {
                *(u32 *)(current + total) |= 4;
            }
            {
                u32 head = *(u32 *)(arg0 + off);
                if (head == next) {
                    *(u32 *)(arg0 + off) = *(u32 *)(*(u32 *)(arg0 + off) + 0xc);
                }
            }
            {
                u32 head = *(u32 *)(arg0 + off);
                if (head == next) {
                    *(u32 *)(arg0 + off) = 0;
                }
            }
            *(u32 *)(*(u32 *)(next + 0xc) + 8) = *(u32 *)(next + 8);
            *(u32 *)(*(u32 *)(next + 8) + 0xc) = *(u32 *)(next + 0xc);
        }
    } else {
        *(u32 *)(arg0 + off) = block;
        *(u32 *)(block + 8) = block;
        *(u32 *)(block + 0xc) = block;
    }
    {
        u32 head = *(u32 *)(arg0 + off);
        u32 maximum = *(u32 *)(arg0 + 8);
        u32 available = *(u32 *)head & ~7;
        if (maximum < available) {
            *(u32 *)(arg0 + 8) = available;
        }
    }
}
