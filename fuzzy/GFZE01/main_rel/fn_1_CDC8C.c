/* Non-matching: best partial attempt (99.15% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#pragma fp_contract off
#include "types.h"
#include "font.h"

typedef struct {
    s32 *unk_0;
    f32 *unk_4;
    u8 *unk_8;
    u8 *unk_C;
    u32 unk_10;
    u32 unk_14;
} HudSource;

extern HudSource lbl_1_bss_84;
extern u32 lbl_1_data_3D544[];
extern const FontDrawPacket lbl_1_rodata_26F8;
extern const u32 lbl_1_rodata_5F20;
extern const u32 lbl_1_rodata_5F24;
extern const u32 lbl_1_rodata_5F28;

extern void fn_1_CF5B0(s32);
extern s32 fn_1_5910(void);
extern u32 fn_1_58C4(void);
extern void fn_1_52070(u32);
extern void fn_1_52088(void);
extern s16 fn_1_E5430(s16);
extern s16 fn_1_E5568(s16);

extern const f32 lbl_1_rodata_5C7C;
extern const f32 lbl_1_rodata_5C80;
extern const f32 lbl_1_rodata_5CCC;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5D04;
extern const f32 lbl_1_rodata_5D18;
extern const f32 lbl_1_rodata_5D90;
extern const f32 lbl_1_rodata_5DBC;
extern const f32 lbl_1_rodata_5DC8;
extern const f32 lbl_1_rodata_5DCC;
extern const f32 lbl_1_rodata_5E24;
extern const f32 lbl_1_rodata_5E90;
extern const f32 lbl_1_rodata_5E94;
extern const f32 lbl_1_rodata_5F2C;
extern const f32 lbl_1_rodata_5F30;
extern const f32 lbl_1_rodata_5F34;
extern const f32 lbl_1_rodata_5F38;
extern const f32 lbl_1_rodata_5F3C;
extern const f32 lbl_1_rodata_5F40;
extern const f32 lbl_1_rodata_5F44;
extern const f32 lbl_1_rodata_5F48;
extern const f32 lbl_1_rodata_5F4C;
extern const f32 lbl_1_rodata_5F50;
extern const f32 lbl_1_rodata_5F54;
extern const f32 lbl_1_rodata_5F58;
extern const f32 lbl_1_rodata_5F5C;
extern const f32 lbl_1_rodata_5F60;
extern const f32 lbl_1_rodata_5F64;
extern const f32 lbl_1_rodata_5F68;
extern const f32 lbl_1_rodata_5F6C;
extern const f32 lbl_1_rodata_5F70;
extern const f32 lbl_1_rodata_5F74;
extern const f32 lbl_1_rodata_5F78;
extern const f32 lbl_1_rodata_5F7C;
extern const f32 lbl_1_rodata_5F80;
extern const f32 lbl_1_rodata_5F84;
extern const f32 lbl_1_rodata_5F88;
extern const f32 lbl_1_rodata_5F8C;
extern const f32 lbl_1_rodata_5F90;
extern const f32 lbl_1_rodata_5F94;
extern const f32 lbl_1_rodata_5F98;
extern const f32 lbl_1_rodata_5F9C;
extern const f32 lbl_1_rodata_5FA0;
extern const f32 lbl_1_rodata_5FA4;
extern const f32 lbl_1_rodata_5FA8;
extern const f32 lbl_1_rodata_5FAC;
extern const f32 lbl_1_rodata_5FB0;
extern const f32 lbl_1_rodata_5FB4;

static inline f32 blink_scale(s32 n) {
    if (n > 15) {
        return lbl_1_rodata_5CFC;
    }
    return (f32)n / lbl_1_rodata_5D04;
}
static inline f32 blink_scale_b(s32 n, f32 scale) {
    if (n > 15) {
        return scale;
    }
    return (f32)n / lbl_1_rodata_5D04;
}

#define DIG cur
#define CURSET cur = d2;

#define CNT c
#define LV j

#define YV y
#define YDEC 
#define p3_s s
void fn_1_CDC8C(void) {
    FontDrawPacket p1;
    FontDrawPacket p2;
    FontDrawPacket p3;
    s8 a;
    s8 d;
    s32 d2;
    s8 cur;
    f32 x0;
    f32 y0;
    f32 s;
    s32 n;
    s32 m;
    s32 i;
    f32 scale;
    f32 y;
    f32 v;
    s32 j;
    s32 c;
    f32 yy;
    f32 fx;
    f32 t;

    n = 0;
    if (lbl_1_bss_84.unk_0 != NULL) {
        n = *lbl_1_bss_84.unk_0;
    }
    fn_1_CF5B0(n);

    if ((lbl_1_data_3D544[fn_1_5910()] >> 14) & 1) {
        if (fn_1_58C4() == 1) {
            fn_1_52070(0xA0);
        }
        p1 = lbl_1_rodata_26F8;
        p1.image = 0xBA0D;
        p1.x = lbl_1_rodata_5F2C;
        p1.y = lbl_1_rodata_5D18;
        fn_1_4F734(&p1);

        a = fn_1_E5430(1);
        d = a - fn_1_E5568(1);
        scale = lbl_1_rodata_5CFC;
        d2 = d;
        if (lbl_1_bss_84.unk_0 != NULL) {
            n = *lbl_1_bss_84.unk_0;
            if (n > 0) {
                d2 = d - 1;
                scale = blink_scale_b(n, scale);
            }
        }
        CURSET
        p1 = lbl_1_rodata_26F8;
        p1.image = 0xBA1D;
        CURSET
        fn_1_51678(&p1, p1.image, (s8)(DIG / 10) * 18, 0, 18, 24);
        p1.x = lbl_1_rodata_5F30;
        p1.y = lbl_1_rodata_5F34;
        p1.flags = 9;
        if ((s8)(DIG / 10) != (s8)(d / 10)) {
            p1.scale_y = scale;
            p1.alpha = scale;
        }
        fn_1_4F734(&p1);

        p1 = lbl_1_rodata_26F8;
        p1.image = 0xBA1D;
        fn_1_51678(&p1, p1.image, (s8)(DIG % 10) * 18, 0, 18, 24);
        p1.x = lbl_1_rodata_5F38;
        p1.y = lbl_1_rodata_5F34;
        p1.flags = 9;
        if ((s8)(DIG % 10) != (s8)(d % 10)) {
            p1.scale_y = scale;
            p1.alpha = scale;
        }
        fn_1_4F734(&p1);

        p1 = lbl_1_rodata_26F8;
        p1.image = 0xBA1D;
        fn_1_51678(&p1, p1.image, (s8)(a / 10) * 18, 0, 18, 24);
        p1.x = lbl_1_rodata_5F3C;
        p1.y = lbl_1_rodata_5F34;
        p1.flags = 9;
        *(u32 *)p1.color = lbl_1_rodata_5F20;
        fn_1_4F734(&p1);

        p1 = lbl_1_rodata_26F8;
        p1.image = 0xBA1D;
        fn_1_51678(&p1, p1.image, (s8)(a % 10) * 18, 0, 18, 24);
        p1.x = lbl_1_rodata_5F40;
        p1.y = lbl_1_rodata_5F34;
        p1.flags = 9;
        *(u32 *)p1.color = lbl_1_rodata_5F24;
        fn_1_4F734(&p1);

        p1 = lbl_1_rodata_26F8;
        p1.image = 0xBA1E;
        p1.x = lbl_1_rodata_5F44;
        p1.y = lbl_1_rodata_5F48;
        *(u32 *)p1.color = lbl_1_rodata_5F28;
        fn_1_4F734(&p1);
        fn_1_52088();
    }

    if ((lbl_1_data_3D544[fn_1_5910()] >> 13) & 1) {
        n = 0;
        m = 800;
        if (fn_1_58C4() == 1) {
            fn_1_52070(0);
        }
        if (lbl_1_bss_84.unk_4 != NULL) {
            n = *lbl_1_bss_84.unk_4;
        }
        if (lbl_1_bss_84.unk_10 != 0) {
            m = lbl_1_bss_84.unk_10;
        }

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA10;
        p2.x = lbl_1_rodata_5CCC;
        p2.y = lbl_1_rodata_5F4C;
        p2.z -= lbl_1_rodata_5DC8;
        fn_1_4F734(&p2);

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA14;
        p2.x = lbl_1_rodata_5D18;
        p2.y = lbl_1_rodata_5DBC;
        p2.z -= lbl_1_rodata_5F50;
        fn_1_4F734(&p2);

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA0F;
        p2.x = lbl_1_rodata_5F54;
        p2.y = lbl_1_rodata_5F58;
        p2.z -= lbl_1_rodata_5F5C;
        fn_1_4F734(&p2);

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA20;
        p2.x = lbl_1_rodata_5F54;
        p2.y = lbl_1_rodata_5F58;
        p2.z -= lbl_1_rodata_5F60;
        p2.scale_y = lbl_1_rodata_5F64;
        fn_1_4F734(&p2);

        YV = lbl_1_rodata_5F68 - (lbl_1_rodata_5F6C * (f32)(n - m)) / lbl_1_rodata_5F70;
        if (YV < lbl_1_rodata_5F74) {
            YV = lbl_1_rodata_5F74;
        } else if (YV > lbl_1_rodata_5F68) {
            YV = lbl_1_rodata_5F68;
        }

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA02;
        p2.x = lbl_1_rodata_5F78;
        p2.y = YV - lbl_1_rodata_5E94;
        fn_1_4F734(&p2);

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA02;
        p2.x = lbl_1_rodata_5F7C;
        p2.y = YV - lbl_1_rodata_5E94;
        p2.rotation_z = -0x8000;
        p2.flags = 15;
        fn_1_4F734(&p2);

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA1B;
        p2.x = lbl_1_rodata_5CCC;
        p2.y = YV;
        p2.z -= lbl_1_rodata_5F80;
        fn_1_4F734(&p2);

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA07;
        p2.x = lbl_1_rodata_5F84;
        p2.y = YV - lbl_1_rodata_5DCC;
        fn_1_4F734(&p2);

        YDEC
        for (i = 0; (i < 5 && n > 0) || (i == 0 && n <= 0); i++) {
            p2 = lbl_1_rodata_26F8;
            p2.image = 0xBA04;
            fn_1_51678(&p2, p2.image, (s8)(n % 10) * 20, 0, 20, 20);
            p2.x = lbl_1_rodata_5F88 - lbl_1_rodata_5F8C * (f32)i;
            p2.y = YV - lbl_1_rodata_5C7C;
            fn_1_4F734(&p2);
            n /= 10;
        }

        for (i = 0; i < 3 && m > 0; i++) {
            p2 = lbl_1_rodata_26F8;
            p2.image = 0xBA05;
            fn_1_51678(&p2, p2.image, (s8)(m % 10) * 12, 0, 12, 12);
            p2.x = lbl_1_rodata_5F90 - lbl_1_rodata_5C80 * (f32)i;
            p2.y = lbl_1_rodata_5F94;
            p2.scale_y = lbl_1_rodata_5F98;
            fn_1_4F734(&p2);
            m /= 10;
        }

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA00;
        p2.x = lbl_1_rodata_5F9C;
        p2.y = lbl_1_rodata_5FA0;
        fn_1_4F734(&p2);
        fn_1_52088();
    }

    if ((lbl_1_data_3D544[fn_1_5910()] >> 12) & 1) {
        v = lbl_1_rodata_5D90;
        if (fn_1_58C4() == 1) {
            fn_1_52070(0xA0);
        }
        if (lbl_1_bss_84.unk_C != NULL && lbl_1_bss_84.unk_8 != NULL) {
            v = *(f32 *)(lbl_1_bss_84.unk_8 + 0xFC) * (f32)lbl_1_bss_84.unk_C[4]
                - *(f32 *)(lbl_1_bss_84.unk_8 + 0xF8);
        }
        x0 = lbl_1_rodata_5FA4;
        y0 = lbl_1_rodata_5D18;
        s = lbl_1_rodata_5CFC;
        if (v < lbl_1_rodata_5E24) {
            x0 = lbl_1_rodata_5FA8;
            y0 = lbl_1_rodata_5FAC;
            s = lbl_1_rodata_5F98;
        }
        CNT = v;

        p3 = lbl_1_rodata_26F8;
        p3.image = 0xBA13;
        p3.x = x0;
        p3.y = y0;
        p3.scale_x *= s;
        p3.scale_y *= s;
        fn_1_4F734(&p3);

        p3 = lbl_1_rodata_26F8;
        p3.image = 0xBA08;
        p3.x = x0 + lbl_1_rodata_5FB0 * s;
        p3.y = y0 + lbl_1_rodata_5E90 * s;
        p3.scale_x *= s;
        p3.scale_y *= s;
        fn_1_4F734(&p3);

        for (LV = 0; (LV < 5 && CNT > 0) || (LV == 0 && CNT <= 0); LV++) {
            p3 = lbl_1_rodata_26F8;
            p3.image = 0xBA04;
            fn_1_51678(&p3, p3.image, (s8)(CNT % 10) * 20, 0, 20, 20);
            p3.y = y0;
            t = (lbl_1_rodata_5FB4 - lbl_1_rodata_5F78 * (f32)LV);
            p3.x = x0 + t * s;
            p3.scale_x *= s;
            p3.scale_y *= s;
            fn_1_4F734(&p3);
            CNT /= 10;
        }
        fn_1_52088();
    }
}
