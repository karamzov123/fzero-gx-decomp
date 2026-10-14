/* Non-matching: best partial attempt (91.74% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/ranking.h"

extern void fn_1_12EF80(s16 value, s16 *out_0, s16 *out_1);
extern void fn_1_3EF14(void *);
extern void fn_80008BA8(void *arg0, void *arg1, u32 size);
extern void fn_80008BEC(void *dst, u32 value, u32 size);
extern s16 *strncpy(char *, const char *, size_t);
extern size_t strlen(const char *);

typedef struct {
    u32 unk_0;
    u32 unk_4;
    char name[0x10];
    u16 unk_18;
    u8 unk_1A;
    u8 unk_1B;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
    u8 unk_20;
    u8 pad_21[7];
    f64 pad_28;
    u8 flag;
    u8 pad_31[7];
} RankEntry;

typedef struct {
    u32 flags;
    u8 pad_4[0x1440];
    RankEntry e;
} RankBuf;

static s32 fn_1_1555B0_local(s32 value) {
    u32 state = (u32)&lbl_1_bss_8EF20;
    s16 index_0;
    s16 index_1;
    u32 table;
    u32 i;
    s32 j;
    u8 *dst;

    if (*(u32 *)state == 0) {
        return 0;
    }

    *(u32 *)(state + 0x40) = value;
    fn_1_12EF80((s16)value, &index_0, &index_1);
    table = (u32)&lbl_1_bss_7F0C0 + (index_1 + index_0 * 6) * 0x180;

    for (i = 0; i < 10; i++) {
        fn_80008BA8((void *)(*(u32 *)state + i * 0x38), (void *)(table + i * 0x20 + 0xf8), 0x20);
    }

    fn_80008BEC((void *)(state + 0x48), 0, 0x230);
    dst = (u8 *)state + 0x48;

    for (j = 0; j < 10; j++, dst += 0x38) {
        fn_80008BA8(dst, (void *)(*(u32 *)state + j * 0x38), 0x38);
    }

    return 112;
}

static inline s32 clamp10(s32 n) {
    if (n < 0) {
        return 0;
    }
    if (n > 10) {
        return 10;
    }
    return n;
}

#pragma opt_dead_assignments off
#pragma opt_loop_invariants off
void fn_1_1556B4(u8 arg0, u8 arg1) {
    RankEntry t;
    u8 *state = (u8 *)&lbl_1_bss_8EF20;
    RankEntry tmp[10];
    RankBuf buf;
    RankEntry *e;
    s32 count;
    s32 i;
    s32 j;
    s32 front;
    s32 back;
    const char * lab_t1;

    if (*(u32 *)state == 0) {
        return;
    }

    fn_1_1555B0_local(*(s32 *)(state + 0x40));

    e = *(RankEntry **)state;
    count = 0;
    for (i = 0; i < 10; i++) {
        if (arg0 == 0x2A && e[i].unk_0 != 0) {
            e[i].flag = 1;
            count++;
        } else {
            e[i].flag = 0;
        }
    }

    if (arg0 != 0x2A) {
        e = *(RankEntry **)state;
        count = 0;
        for (i = 0; i < 10; i++) {
            if (arg0 == 0x29) {
                if (e[i].unk_1A > 0x29) {
                    e[i].flag = 1;
                    count++;
                }
            } else if (e[i].unk_1A == arg0 && e[i].unk_0 != 0) {
                e[i].flag = 1;
                count++;
            }
        }
    }

    e = *(RankEntry **)state;
    front = 0;
    back = 9;
    for (i = 0; i < 10; i++) {
        if (e[i].flag == 1) {
            tmp[front] = e[i];
            front++;
        } else {
            tmp[back] = e[i];
            back--;
        }
    }
    fn_80008BA8(*(RankEntry **)state, tmp, 0x230);

    e = *(RankEntry **)state;
    switch (arg1) {
    case 0:
    default:
        for (i = 0; i < count - 1; i++) {
            for (j = i + 1; j < count; j++) {
                if (e[i].unk_0 > e[j].unk_0 || (e[i].unk_0 == 0 && e[j].unk_0 != 0)) {
                    t = e[i];
                    e[i] = e[j];
                    e[j] = t;
                }
            }
        }
        break;
    case 1:
        for (i = 0; i < count - 1; i++) {
            for (j = i + 1; j < count; j++) {
                if (e[i].unk_18 < e[j].unk_18 || (e[i].unk_18 == 0 && e[j].unk_18 != 0)) {
                    t = e[i];
                    e[i] = e[j];
                    e[j] = t;
                }
            }
        }
        break;
    case 2:
        for (i = 0; i < count - 1; i++) {
            for (j = i + 1; j < count; j++) {
                if (e[i].unk_4 > e[j].unk_4 || (e[i].unk_4 == 0 && e[j].unk_4 != 0)) {
                    t = e[i];
                    e[i] = e[j];
                    e[j] = t;
                }
            }
        }
        break;
    }

    fn_80008BEC(state + 0x48, 0, 0x230);
    {
        RankEntry *dst = (RankEntry *)(state + 0x48);
        for (i = 0; i < clamp10(count); i++) {
            RankEntry *src = &(*(RankEntry **)state)[i];
            dst[i].unk_0 = src->unk_0;
            dst[i].unk_4 = src->unk_4;
            dst[i].unk_18 = src->unk_18;
            dst[i].unk_1A = src->unk_1A;
            dst[i].unk_1B = src->unk_1B;
            dst[i].unk_1C = src->unk_1C;
            dst[i].unk_1D = src->unk_1D;
            dst[i].unk_1E = src->unk_1E;
            dst[i].unk_1F = src->unk_1F;
            dst[i].unk_20 = src->unk_20;
            lab_t1 = src->name;
            strncpy(dst[i].name, lab_t1, 0x10);
        }

        for (i = clamp10(count); i < 10; i++) {
            dst[i].unk_0 = 0x6339E7;
            dst[i].unk_4 = 0x6339E7;
            lab_t1 = (char *)lbl_1_data_49B14;
            strncpy(dst[i].name, lab_t1, strlen((char *)lbl_1_data_49B14));
            dst[i].unk_18 = 0;
            if (arg0 == 0x29) {
                dst[i].unk_1A = 0x29;
            } else if (arg0 == 0x2A) {
                dst[i].unk_1A = 6;
            } else {
                dst[i].unk_1A = arg0;
            }
            dst[i].unk_1B = dst[i].unk_1A;
            dst[i].unk_1C = 0x32;
            dst[i].unk_1D = 0;
            dst[i].unk_1E = 0;
            dst[i].unk_1F = 0;
            dst[i].unk_20 = 0xFF;
        }
    }

    *(u32 *)(state + 0x4C0) = 0;
    *(s32 *)(state + 0x4C4) = -1;
    fn_1_3EF14(&buf);
    if (buf.flags & 0x1000) {
        e = *(RankEntry **)state;
        for (i = 9; i >= 0; i--) {
            if (buf.e.unk_0 == e[i].unk_0 && buf.e.unk_18 == e[i].unk_18 && buf.e.unk_1A == e[i].unk_1A
                && buf.e.unk_1B == e[i].unk_1B && buf.e.unk_1C == e[i].unk_1C && buf.e.unk_1D == e[i].unk_1D
                && buf.e.unk_1E == e[i].unk_1E && buf.e.unk_1F == e[i].unk_1F) {
                *(s32 *)(state + 0x4C4) = i;
                *(u32 *)(state + 0x4C0) = 1;
                break;
            }
        }
    }
}
#pragma opt_loop_invariants reset

#pragma opt_dead_assignments reset

