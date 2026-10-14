/* Non-matching: best partial attempt (89.76% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8  pad_0[0x1FA0];
    s32 unk_1FA0;
    u8  pad_1FA4[0x42];
    u16 unk_1FE6;
    u16 unk_1FE8;
    u8  pad_1FEA[2];
    s32 unk_1FEC;
    u8  pad_1FF0[4];
    s32 unk_1FF4;
    f32 unk_1FF8;
    u8  pad_1FFC[4];
    u32 unk_2000[14];
    s32 unk_2038;
    u8  pad_203C[8];
    u32 unk_2044;
} Mgr;

typedef struct {
    u8 pad_0[0x20];
    u8 unk_20;
    u8 pad_21[0x14E3];
    s8 unk_1504;
} Bss;

typedef struct {
    u8  pad_0[4];
    f32 unk_4;
    u8  pad_8[0x1EC];
    u32 unk_1F4;
    u32 unk_1F8;
    u32 unk_1FC;
    u32 unk_200;
    u32 unk_204;
    u32 unk_208;
    u32 unk_20C;
    f32 unk_210;
} Rod;

typedef struct {
    u8  pad_0[8];
    u16 unk_8;
    u16 unk_A;
    u8  pad_C[4];
    u16 unk_10;
    u16 unk_12;
} Ent;

extern Bss lbl_1_bss_3C00;
extern Rod lbl_1_rodata_BD8;
extern Ent lbl_1_bss_9F8[];
extern u32 lbl_1_data_62EC;
extern u32 lbl_1_data_62F4[0x2D];
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_1_2C7C4(u8 *, const u8 *, int);
extern void fn_1_A2DC4(u32);
extern s32 fn_1_2EE3C(void);

void fn_1_2FAA0(void) {
    Mgr *m = (Mgr *)((u8 *)&lbl_1_bss_3C00 + 0x20000);
    Bss *b = &lbl_1_bss_3C00;
    Rod *ro = &lbl_1_rodata_BD8;
    s32 res;
    s32 i;
    s32 flag = 0;
    u16 e;
    u16 f;
    u8 *w;
    u32 bit;
    u8 *dst;
    u32 v4;
    u32 v3;
    u32 v2;
    u32 v1;
    u32 v0;
    s32 same;

    m->unk_1FEC = -2;
    m->unk_2044 = 1;
    if (m->unk_1FE6 == 0) {
        OSPanic((const char *)&lbl_1_data_62EC, 0xBA7, (const char *)&lbl_1_data_62F4);
    }
    if (m->unk_1FA0 == 0) {
        if (m->unk_1FF4 != 0) {
            res = 0;
            e = lbl_1_bss_9F8[b->unk_20].unk_10;
            f = lbl_1_bss_9F8[b->unk_20].unk_12;
            if ((e & 1) || (f & 1)) {
                if (m->unk_2038 == 1) {
                    fn_1_A2DC4(0xA9011300);
                }
                m->unk_2038 = 0;
            } else if (((e >> 1) & 1) || ((f >> 1) & 1)) {
                if (m->unk_2038 == 0) {
                    fn_1_A2DC4(0xA9011300);
                }
                m->unk_2038 = 1;
            }
            f = lbl_1_bss_9F8[b->unk_20].unk_8;
            if ((f >> 8) & 1) {
                if (m->unk_2038 == 0) {
                    res = 1;
                    m->unk_1FEC = 1 << b->unk_1504;
                    fn_1_A2DC4(0xA9011100);
                } else {
                    m->unk_1FF4 = 0;
                    fn_1_A2DC4(0xA9011000);
                }
            } else if (((f >> 9) & 1) || ((f >> 12) & 1)) {
                m->unk_1FF4 = 0;
                fn_1_A2DC4(0xA9011000);
            }
            flag = res;
        } else {
            flag = fn_1_2EE3C();
        }
    }
    w = (u8 *)&m->unk_2000[0];
    for (i = 0; i < 14; i++) {
        bit = 1 << i;
        if (m->unk_1FE6 & bit) {
            if (b->unk_1504 == i) {
                *(u32 *)w = ro->unk_1F4;
            } else {
                v4 = *(u32 *)w;
                v3 = ro->unk_1F8;
                same = 1;
                if (*(u8 *)&v4 != *(u8 *)&v3) {
                    same = 0;
                } else if (*((u8 *)&v4 + 1) != *((u8 *)&v3 + 1)) {
                    same = 0;
                } else if (*((u8 *)&v4 + 2) != *((u8 *)&v3 + 2)) {
                    same = 0;
                }
                if (same) {
                    w[2] = 10;
                } else if (m->unk_1FE8 & bit) {
                    v2 = ro->unk_1FC;
                    fn_1_2C7C4(w, (const u8 *)&v2, 20);
                } else {
                    v1 = ro->unk_200;
                    fn_1_2C7C4(w, (const u8 *)&v1, 20);
                }
            }
        }
        w += 4;
    }
    if (m->unk_1FF4 != 0) {
        if (m->unk_2038 != 0) {
            m->unk_2000[11] = ro->unk_204;
            dst = (u8 *)&m->unk_2000[10];
        } else {
            m->unk_2000[10] = ro->unk_208;
            dst = (u8 *)&m->unk_2000[11];
        }
        v0 = ro->unk_20C;
        fn_1_2C7C4(dst, (const u8 *)&v0, 20);
    }
    if (ro->unk_4 == m->unk_1FF8) {
        m->unk_1FF8 = ro->unk_210;
    }
    if (flag != 0) {
        b->unk_1504 = -1;
    }
}
