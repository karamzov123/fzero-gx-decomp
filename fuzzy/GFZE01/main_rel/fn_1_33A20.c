/* Non-matching: best partial attempt (41.61% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern f32 lbl_1_rodata_BDC[2];
extern f32 lbl_1_rodata_BE4[9];
extern u8 lbl_1_bss_3C00[];
extern u8 lbl_1_data_5730[];
extern u32 lbl_1_bss_6EAB4;
extern s16 lbl_1_bss_960;
extern s32 lbl_1_data_1A2B4[];
extern u8 lbl_1_bss_8B3A0[];

extern void fn_1_156754(s32);
extern void fn_1_2FAA0(void);
extern void fn_1_2DE00(s32);
extern void fn_1_3F2A0(void);
extern void fn_1_4A00(s32, s32, void *);
extern void fn_1_469BC(void);
extern void fn_1_8DBA4(s32);
extern void fn_1_4DE04(void);
extern int fn_1_8623C(void);
extern u8 *fn_1_86900(s8);
extern u8 *fn_1_868C0(s8);
extern s16 fn_1_12C930(s8);
extern void fn_1_4811C(s32);
extern void fn_1_48004(s32, s32);
extern void fn_1_3F8D0(void);
extern void *fn_1_435C(void *);
extern void fn_1_30D84(void);
extern void fn_1_3129C(void);
extern void fn_1_30824(void);
extern s32 fn_1_3F8C(void *, void *, s32, s32);
extern u8 *fn_1_86254(u8);
extern void fn_1_EB080(s32);
extern void fn_1_D3474(void);
extern void fn_1_F3BC0(void);
extern void fn_1_154CC4(s32);
extern void fn_1_F2EFC(void);
extern void fn_1_A0D20(void);
extern void fn_80008BA8(void *, void *, u32);

#define P30 (*(u32 *)(p + 0x30))
#define Q(T, o) (*(T *)(q + (o)))
#define PP(T, o) (*(T *)(p + (o)))

#define SOUND_BLOCK() \
    do { \
        if (lbl_1_bss_960 != 10 && lbl_1_bss_960 != 12) { \
            u8 *obj = fn_1_86900(fn_1_8623C()); \
            if (obj == 0) { \
                obj = fn_1_868C0(0); \
            } \
            fn_1_4811C(lbl_1_data_1A2B4[fn_1_12C930(obj[0x328])]); \
            fn_1_4811C(0x97); \
            fn_1_4811C(0x99); \
            fn_1_48004(0x94, 1); \
        } \
    } while (0)

#define PICK_LOOPS() \
    do { \
        s32 k; \
        for (k = 13; k > 0; k--) { \
            if (in & (1 << k)) { \
                PP(u8, 0x1504) = k; \
                return; \
            } \
        } \
        for (k = 0; k < 14; k++) { \
            if (Q(u16, 0x1fe6) & (1 << k)) { \
                PP(u8, 0x1504) = k; \
                return; \
            } \
        } \
    } while (0)

#define COPY_LOOP(n) \
    do { \
        s32 i; \
        if (PP(s16, 0x2a) <= 41) { \
            for (i = 0; i < n; i++) { \
                u8 idx = g[i * 0xa0 + 0x157]; \
                (p + 0x165c)[idx * 8 + 4] = g[i * 0xa0 + 0x154]; \
                (p + 0x165c)[idx * 8 + 6] = p[0x163c + i]; \
                (p + 0x165c)[0x194 + idx] = i; \
            } \
        } else { \
            for (i = 0; i < n; i++) { \
                u8 idx = g[i * 0xa0 + 0xdc]; \
                (p + 0x165c)[idx * 8 + 4] = g[i * 0xa0 + 0x154]; \
                (p + 0x165c)[idx * 8 + 6] = p[0x163c + i]; \
                (p + 0x165c)[0x194 + idx] = i; \
            } \
        } \
        (p + 0x165c)[0x191] |= 2; \
        (p + 0x165c)[0x192] = n; \
        (p + 0x165c)[0x190] = g[7]; \
        P30 |= 0x400000; \
        PP(s16, 0x17f4) = 14; \
    } while (0)

void fn_1_33A20(void) {
    u8 *p = (u8 *)lbl_1_bss_3C00;
    u8 *q = p + 0x20000;
    u8 *d = (u8 *)lbl_1_data_5730;
    u8 flag;
    s32 in;

    if (Q(f32, 0x1ff8) > lbl_1_rodata_BDC[0]) {
        s32 i;
        for (i = 0; i < 4; i++) {
            fn_1_156754(i);
        }
    }
    fn_1_2FAA0();
    flag = Q(u8, 0x1fea);
    if (flag != 0) {
        return;
    }
    if (!(P30 & 0x800)) {
        Q(u32, 0x2f50) = 1;
    }
    in = -2;
    if (flag == 0) {
        in = Q(s32, 0x1fec);
    }
    if (in == -2) {
        return;
    }
    P30 &= ~2;
    switch (in) {
    case 2:
        if (Q(s32, 0x1fa0) == 0) {
            u8 *g;
            fn_1_2DE00(1);
            g = p + 0x30;
            g[7] = 14;
            if (Q(s32, 0x1fa0) == 0) {
                PP(s16, 0x17f4) = 14;
                if (g[5] == 0) {
                    s32 j;
                    for (j = 0; j < g[8]; j++) {
                        if (*(u32 *)(g + 0x1480 + j * 4) != 0) {
                            if (!(P30 & 0x400000)) {
                                u8 n;
                                fn_1_3F2A0();
                                n = g[8];
                                COPY_LOOP(n);
                            }
                            break;
                        }
                    }
                }
                fn_1_4A00(0, 30, PP(void *, 0x1500));
                Q(s32, 0x1fa0) = 1;
                lbl_1_bss_6EAB4 |= 0x2c;
                if (g[5] == 0) {
                    d[0x454] = 1;
                }
                fn_1_469BC();
                fn_1_8DBA4(0);
            }
        }
        break;
    case 4:
        if (Q(s32, 0x1fa0) == 0) {
            void *h;
            u8 *g;
            s32 i;
            Q(s32, 0x1fa0) = 1;
            fn_1_4A00(0, 30, PP(void *, 0x1500));
            Q(s32, 0x2278) = 0;
            lbl_1_bss_6EAB4 |= 0x2c;
            fn_1_4DE04();
            SOUND_BLOCK();
            fn_1_3F8D0();
            Q(s32, 0x226c) = 1;
            Q(s32, 0x228c) = 60;
            h = fn_1_435C(PP(void *, 0x1500));
            fn_1_3F8C(d + 0xcb0, (void *)fn_1_30D84, 0, 2);
            fn_1_435C(h);
            g = p + 0x30;
            for (i = 0; i < g[9]; i++) {
                g[i * 0xa0 + 0x157] = g[i * 0xa0 + 0xdc];
            }
        }
        break;
    case 8:
        if (Q(s32, 0x1fa0) == 0) {
            void *h;
            Q(s32, 0x1fa0) = 1;
            fn_1_4A00(0, 30, PP(void *, 0x1500));
            Q(s32, 0x2278) = 0;
            lbl_1_bss_6EAB4 |= 0x2c;
            fn_1_4DE04();
            SOUND_BLOCK();
            fn_1_3F8D0();
            Q(s32, 0x228c) = 60;
            h = fn_1_435C(PP(void *, 0x1500));
            fn_1_3F8C(d + 0xcc0, (void *)fn_1_3129C, 0, 2);
            fn_1_435C(h);
        }
        break;
    case 0x10:
        Q(u8, 0x2f54) = 1;
        in = Q(s32, 0x1fec);
        if (in != -2) {
            P30 |= 2;
            PICK_LOOPS();
        }
        break;
    case 0x20:
        if (Q(s32, 0x1fa0) == 0) {
            void *h;
            Q(s32, 0x1fa0) = 1;
            fn_1_4A00(0, 30, PP(void *, 0x1500));
            Q(s32, 0x2278) = 0;
            lbl_1_bss_6EAB4 |= 0x2c;
            fn_1_4DE04();
            SOUND_BLOCK();
            fn_1_3F8D0();
            Q(s32, 0x2270) = 1;
            Q(s32, 0x228c) = 60;
            h = fn_1_435C(PP(void *, 0x1500));
            fn_1_3F8C(d + 0xca4, (void *)fn_1_30824, 0, 2);
            fn_1_435C(h);
        }
        break;
    case 0x40:
        if (Q(s32, 0x1fa0) == 0) {
            u8 *g;
            PP(s16, 0x17f4) = 1;
            *(u32 *)(lbl_1_bss_8B3A0 + 0x94) |= 0x20;
            fn_1_4A00(0, 30, PP(void *, 0x1500));
            g = p + 0x30;
            Q(s32, 0x1fa0) = 1;
            lbl_1_bss_6EAB4 |= 0x2c;
            if (g[5] == 0) {
                d[0x454] = 0;
            }
            fn_1_8DBA4(0);
        }
        break;
    case 0x80:
        if (Q(s32, 0x1fa0) == 0) {
            void *h;
            Q(s32, 0x1fa0) = 1;
            fn_1_4A00(0, 30, PP(void *, 0x1500));
            Q(s32, 0x2278) = 1;
            lbl_1_bss_6EAB4 |= 0x2c;
            fn_1_4DE04();
            SOUND_BLOCK();
            fn_1_3F8D0();
            Q(s32, 0x228c) = 60;
            h = fn_1_435C(PP(void *, 0x1500));
            fn_1_3F8C(d + 0xcc0, (void *)fn_1_3129C, 1, 2);
            fn_1_435C(h);
        }
        break;
    case 0x100:
        fn_1_F3BC0();
        fn_1_154CC4(0);
        in = Q(s32, 0x1fec);
        if (in != -2) {
            P30 |= 2;
            PICK_LOOPS();
        }
        break;
    case 0x200:
        fn_1_EB080(0xb);
        in = Q(s32, 0x1fec);
        if (in != -2) {
            P30 |= 2;
            PICK_LOOPS();
        }
        break;
    case 0x400:
        Q(u32, 0x2f58) = 1;
        break;
    case 0x800: {
        u8 *g = p + 0x30;
        u8 i;
        for (i = 0; i < g[8]; i++) {
            u8 *obj = fn_1_86254(i);
            s32 idx = (s8)obj[0x475];
            if (idx != -1) {
                if (Q(f32, 0x2704 + idx * 4) < lbl_1_rodata_BE4[0]) {
                    u8 t;
                    fn_80008BA8(q + 0x2714 + idx * 0x1fc, *(void **)(obj + 0x49c), 0x1fc);
                    Q(f32, 0x2704 + (s8)obj[0x475] * 4) = *(f32 *)(obj + 0xd8);
                    t = obj[0x482];
                    if (t > 30) {
                        Q(u8, 0x2f04 + (s8)obj[0x475]) = 30;
                    } else {
                        Q(u8, 0x2f04 + (s8)obj[0x475]) = t;
                    }
                }
            }
        }
        Q(u8, 0x2f1e) |= 1;
        PP(u8, 0x14f4) |= 1;
        PP(s16, 0x14e8) = 42;
        PP(s16, 0x14ec) = 0;
        P30 |= 0x1000;
        PP(u32, 0x14f8) = 0;
        PP(s16, 0x14fc) = 0;
        fn_1_EB080(4);
        break;
    }
    case 0x1000:
        fn_1_D3474();
        break;
    case 0x2000:
        if (Q(s32, 0x1fa0) == 0) {
            u8 *g = p + 0x30;
            PP(s16, 0x17f4) = g[7];
            if (g[5] == 0) {
                s32 j;
                for (j = 0; j < g[8]; j++) {
                    if (*(u32 *)(g + 0x1480 + j * 4) != 0) {
                        if (!(P30 & 0x400000)) {
                            u8 n;
                            fn_1_3F2A0();
                            n = g[8];
                            COPY_LOOP(n);
                        }
                        break;
                    }
                }
            }
            fn_1_4A00(0, 30, PP(void *, 0x1500));
            Q(s32, 0x1fa0) = 1;
            lbl_1_bss_6EAB4 |= 0x2c;
            if (g[5] == 0) {
                d[0x454] = 1;
            }
            fn_1_469BC();
            fn_1_8DBA4(0);
        }
        break;
    case 1:
    case 3:
    default: {
        u32 t = P30;
        if ((t & 0x800000) && !(t & 0x1000)) {
            fn_1_F2EFC();
        }
        PP(u32, 0x14f8) = 0;
        fn_1_A0D20();
        break;
    }
    }
}
