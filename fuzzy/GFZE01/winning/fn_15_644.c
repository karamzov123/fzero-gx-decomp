/* Non-matching: best partial attempt (94.51% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_15_644_Entry {
    u8 pad_0[4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[2];
};

struct fn_15_644_World {
    struct fn_15_644_Entry unk_0[9];
    u8 pad_48[0x14A];
    u8 unk_192;
    u8 pad_193;
    u8 unk_194[16];
};

struct fn_15_644_lbl_15_bss_0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u32 unk_14;
    u8 pad_18[8];
    u8 unk_20;
    u8 pad_21[0xB];
    struct fn_15_644_World *unk_2C;
    s32 unk_30;
    u8 pad_34[4];
    s16 unk_38;
};

struct fn_15_644_lbl_1_bss_9F8 {
    u8 pad_0[0x10];
    u16 unk_10;
    u16 unk_12;
};

struct fn_15_644_lbl_1_bss_D58 {
    u8 pad_0[8];
    u16 unk_8;
};

struct fn_15_644_lbl_1_bss_525C {
    u8 pad_0[0x191];
    u8 unk_191;
};

extern struct fn_15_644_lbl_15_bss_0 lbl_15_bss_0;
extern struct fn_15_644_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern struct fn_15_644_lbl_1_bss_D58 lbl_1_bss_D58;
extern struct fn_15_644_lbl_1_bss_525C lbl_1_bss_525C;
extern u32 lbl_1_data_20B14[];
extern u8 lbl_15_data_0[];
extern u16 lbl_1_bss_968;
extern u16 lbl_1_bss_96A;
extern s16 lbl_1_bss_962;

extern void fn_1_A8EB0(int, int);
extern void fn_1_A8F40(u8);
extern void fn_1_A8E78(int);
extern void fn_1_A8DD4(const char *, ...);
extern s16 fn_1_12C930(s16);
extern u8 fn_1_12C710(int);
extern void *fn_1_7F49C(s16, s16, void *);
extern u8 fn_1_B7C00(void);
extern void fn_1_4A00(s32, u8, void *);

#pragma opt_loop_invariants off
static inline struct fn_15_644_Entry * fn_15_644_read_pointer(struct fn_15_644_World * owner) { return owner->unk_0; }
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_15_644(void) {
    u16 buf[18];
    s16 i;
    s16 v1;
    s16 v0;
    struct fn_15_644_World *w;
    u8 *data = (u8 *)&lbl_15_data_0;
    struct { struct fn_15_644_lbl_15_bss_0 *value; } p;
    p.value = (struct fn_15_644_lbl_15_bss_0 *)&lbl_15_bss_0;

    if (p.value->unk_14 & 0x20000000) {
        w = p.value->unk_2C;
        if (((lbl_1_bss_9F8.unk_10 >> 3) & 1) || ((lbl_1_bss_9F8.unk_12 >> 3) & 1)) {
            v0 = -1;
        } else if (((lbl_1_bss_9F8.unk_10 >> 2) & 1) || ((lbl_1_bss_9F8.unk_12 >> 2) & 1)) {
            v0 = 1;
        } else {
            v0 = 0;
        }

        p.value->unk_30 = (p.value->unk_30 + v0 + 9) % 9;

        if ((lbl_1_bss_9F8.unk_10 & 1) || (lbl_1_bss_9F8.unk_12 & 1)) {
            v1 = -1;
        } else if (((lbl_1_bss_9F8.unk_10 >> 1) & 1) || ((lbl_1_bss_9F8.unk_12 >> 1) & 1)) {
            v1 = 1;
        } else {
            v1 = 0;
        }

        if (v1 != 0) {
            if (p.value->unk_30 >= 0 && p.value->unk_30 < 4) {
                fn_15_644_read_pointer(w)[p.value->unk_30].unk_4 = (((41) + ((fn_15_644_read_pointer(w)[p.value->unk_30].unk_4) + (v1)))) % 41;
                fn_15_644_read_pointer(w)[p.value->unk_30].unk_5 = fn_15_644_read_pointer(w)[p.value->unk_30].unk_4;
            } else {
                switch (p.value->unk_30 - 4) {
                case 0:
                    p.value->unk_14 ^= 0x80000000;
                    break;
                case 2:
                    w->unk_192 += v1;
                    if (w->unk_192 == 0) {
                        w->unk_192 = 4;
                    }
                    if (w->unk_192 > 4) {
                        w->unk_192 = 1;
                    }
                    break;
                }
            }
        }

        {
            struct fn_15_644_Entry *e = (struct fn_15_644_Entry *)p.value->unk_2C;
            fn_1_A8EB0(10, 19);
            fn_1_A8F40(255);
            fn_1_A8E78((int)(data + 0xB0));
            for (i = 0; i < 4; i++) {
                s16 c;
                u32 t;
                if (i == p.value->unk_30) {
                    fn_1_A8F40(51);
                } else {
                    fn_1_A8F40(255);
                }
                fn_1_A8DD4((const char *)(data + 0xD0), i, (c = e->unk_4));
                t = lbl_1_data_20B14[fn_1_12C930(c)];
                fn_1_7F49C(fn_1_12C710(c), 0, buf);
                fn_1_A8DD4((const char *)(data + 0xE4), t, buf);
                e++;
            }
        }

        for (; i < 9; i++) {
            if (i == p.value->unk_30) {
                fn_1_A8F40(51);
            } else {
                fn_1_A8F40(255);
            }
            switch (i - 4) {
            case 0:
                if (p.value->unk_14 & 0x80000000) {
                    fn_1_A8E78((int)(data + 0xF0));
                } else {
                    fn_1_A8E78((int)(data + 0xFC));
                }
                break;
            case 1:
                fn_1_A8E78((int)(data + 0x108));
                break;
            case 2:
                fn_1_A8DD4((const char *)(data + 0x120), p.value->unk_2C->unk_192);
                break;
            case 3:
                fn_1_A8E78((int)(data + 0x134));
                break;
            case 4:
                fn_1_A8E78((int)(data + 0x144));
                break;
            }
        }

        fn_1_A8F40(255);

        if (((lbl_1_bss_D58.unk_8 >> 8) & 1) && !fn_1_B7C00()) {
            u32 m = p.value->unk_14 & 0xFFFFFF01;
            s16 j;
            lbl_1_bss_525C.unk_191 = 0;
            p.value->unk_14 = m;
            switch (p.value->unk_30 - 4) {
            case 1:
                p.value->unk_14 = ((9) | (m));
                lbl_1_bss_525C.unk_191 |= 1;
                lbl_1_bss_96A = 0xB8;
                p.value->unk_20 = 1;
                break;
            case 2:
                p.value->unk_14 = ((0x81) | (m));
                lbl_1_bss_525C.unk_191 |= 2;
                p.value->unk_38 = p.value->unk_2C->unk_192;
                lbl_1_bss_96A = 0xB8;
                p.value->unk_20 = 1;
                for (j = 0; j < p.value->unk_38; j++) {
                    p.value->unk_2C->unk_194[j] = j;
                }
                break;
            case 3:
                p.value->unk_14 = ((5) | (m));
                lbl_1_bss_96A = 0xB8;
                p.value->unk_20 = 1;
                break;
            case 4:
                p.value->unk_14 = ((3) | (m));
                lbl_1_bss_525C.unk_191 |= 1;
                lbl_1_bss_96A = 0xB8;
                break;
                p.value->unk_20 = 0;
            default:
                p.value->unk_20 = 1;
                p.value->unk_14 &= ~1;
                break;
            }
            if ((p.value->unk_14 & 0x78) == 0) {
                fn_1_4A00(1, 30, (void *)p.value->unk_10);
            } else {
                fn_1_4A00(0, 0, (void *)p.value->unk_10);
            }
            lbl_1_bss_96A = 0xB8;
        }

        if (((lbl_1_bss_D58.unk_8 >> 12) & 1) && !fn_1_B7C00() && p.value->unk_20 &&
            (p.value->unk_14 & 0x20000000) && lbl_1_bss_962 == 183) {
            lbl_1_bss_968 = 10;
        }
    }
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset

#pragma opt_loop_invariants reset
