/* Non-matching: best partial attempt (40.79% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

struct fn_1_11B4E4_Copy64 { u32 a[16]; };
struct fn_1_11B4E4_Record { u8 bytes[0x44]; };
struct fn_1_11B4E4_SortSlot { u32 a[16]; u32 pad; };

extern f32 lbl_1_rodata_7B1C;
extern f32 lbl_1_rodata_7B20;
extern f64 lbl_1_rodata_7B08;
extern u32 fn_1_10846C(u32);
extern void fn_1_128884(void *, void *, int);
extern u32 fn_1_4630(u32, u32, u32, u32);
extern f32 fn_1_1289BC(const void *, const void *);

void fn_1_11B4E4(u32 arg0, f32 arg1, u32 arg2) {
    u32 i, j, k;
    u8 *base;
    struct fn_1_11B4E4_Record *records;
    struct fn_1_11B4E4_Copy64 first;
    struct fn_1_11B4E4_SortSlot left[8];
    struct fn_1_11B4E4_SortSlot right[8];
    u32 count;
    u32 groups;
    u32 maxindex;
    u32 *table;
    u32 offset;
    f32 value;
    f32 numerator;
    f32 denominator;
    u32 index;
    u32 total;
    struct fn_1_11B4E4_Record *p;
    struct fn_1_11B4E4_Record *q;

    if (arg0 == 0) return;
    fn_1_10846C(arg0);
    count = *(u32 *)(arg0 + 0x18);
    records = (struct fn_1_11B4E4_Record *)*(u32 *)(arg0 + 0x24);
    for (i = 0; i < count; i++) {
        p = records + i;
        if ((p->bytes[0] & 1) != 0) {
            *(f32 *)(p->bytes + 0x40) = lbl_1_rodata_7B1C;
            p->bytes[0] = 0;
        } else {
            *(f32 *)(p->bytes + 0x40) = lbl_1_rodata_7B20;
            p->bytes[0] = 1;
        }
    }
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            p = records + i;
            q = records + j;
            if (*(f32 *)(p->bytes + 0x10) > *(f32 *)(q->bytes + 0x10))
                fn_1_128884(p, q, 0x44);
        }
    }
    groups = count >> 3;
    for (i = 0; i < groups; i++) {
        base = (u8 *)records + i * 0x220;
        for (j = 0; j < 8; j++) {
            for (k = j + 1; k < 8; k++) {
                p = (struct fn_1_11B4E4_Record *)(base + j * 0x44);
                q = (struct fn_1_11B4E4_Record *)(base + k * 0x44);
                if (*(f32 *)(p->bytes + 0x14) < *(f32 *)(q->bytes + 0x14))
                    fn_1_128884(p, q, 0x44);
            }
        }
        first = *(struct fn_1_11B4E4_Copy64 *)base;
        for (j = 0; j < 8; j++) {
            p = (struct fn_1_11B4E4_Record *)(base + (j + 1) * 0x44);
            if (*(f32 *)(p->bytes + 0x18) > lbl_1_rodata_7B20) {
                left[j].a[0] = *(u32 *)(p->bytes + 0);
                __builtin_memcpy(left[j].a, p->bytes, 64);
            } else {
                __builtin_memcpy(right[7 - j].a, p->bytes, 64);
            }
        }
        for (j = 0; j < 8; j++) {
            /* source and outputs each retain the retail 0x44 stride */
            __builtin_memcpy((u8 *)base + j * 0x44, &left[0], 64);
            value = *(f32 *)((u8 *)base + j * 0x44 + 0x40);
            if (i == groups - 1) {
                *(f32 *)((u8 *)base + j * 0x44 + 0x40) = lbl_1_rodata_7B20;
            } else {
                *(f32 *)((u8 *)base + j * 0x44 + 0x40) = value;
            }
        }
    }
    *(u32 *)(arg0 + 0x1c) = 0x60;
    table = (u32 *)fn_1_4630(*(u32 *)0x801A6410, 0x60 * 0xC, (u32)&lbl_1_data_40530, 0x1e57);
    *(u32 *)(arg0 + 0x28) = (u32)table;
    total = 0;
    index = 0;
    offset = 0;
    records = (struct fn_1_11B4E4_Record *)*(u32 *)(arg0 + 0x24);
    for (i = 0; i < groups - 1; i++) {
        p = (struct fn_1_11B4E4_Record *)((u8 *)records + i * 0x220);
        for (j = 0; j < 7; j++) {
            *(u32 *)((u8 *)table + offset) = (u32)p;
            *(u32 *)((u8 *)table + offset + 4) = (u32)(p + 1);
            value = fn_1_1289BC((void *)p, (void *)(p + 1));
            *(f32 *)((u8 *)table + offset + 8) = value;
            offset += 12;
            index++;
            p++;
        }
        *(u32 *)((u8 *)table + offset) = (u32)((u8 *)records + i * 0x220 + 0x1dc);
        *(u32 *)((u8 *)table + offset + 4) = (u32)((u8 *)records + i * 0x220);
        value = fn_1_1289BC((void *)((u8 *)records + i * 0x220 + 0x1dc), (void *)((u8 *)records + i * 0x220));
        *(f32 *)((u8 *)table + offset + 8) = value;
        offset += 12;
        total++;
    }
    for (i = 0; i < groups - 1; i++) {
        p = (struct fn_1_11B4E4_Record *)((u8 *)records + i * 0x220);
        q = (struct fn_1_11B4E4_Record *)((u8 *)records + (i + 1) * 0x220);
        for (j = 0; j < 8; j++) {
            *(u32 *)((u8 *)table + offset) = (u32)p;
            *(u32 *)((u8 *)table + offset + 4) = (u32)q;
            value = fn_1_1289BC((void *)p, (void *)q);
            *(f32 *)((u8 *)table + offset + 8) = value;
            offset += 12;
            p++;
            q++;
        }
    }
}
