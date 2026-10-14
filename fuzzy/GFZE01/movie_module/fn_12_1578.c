/* Non-matching: best partial attempt (78.02% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_12_rodata_60[];

typedef struct MovieModuleObj {
    u8 pad_0[4];
    s32 field_4;
    s32 field_8;
    u8 pad_C[0x20];
    void *field_2C;
    s32 field_34;
    u8 *field_38;
} MovieModuleObj;

typedef struct MovieParam {
    u8 pad_0[4];
    s32 field_4;
    s32 field_8;
    u8 pad_C[0x38];
    s32 field_44;
    s32 field_48;
    void *field_4C;
} MovieParam;

typedef struct ColorParam {
    s32 field_0;
    s32 field_4;
    s32 field_8;
} ColorParam;

typedef struct DrawParam {
    void *field_0;
    s32 field_4;
    s32 field_8;
    s32 field_C;
} DrawParam;

extern s32 fn_12_748(MovieModuleObj *);
extern void fn_12_309C(u32, u32, u32);
extern void fn_12_3D730(ColorParam *, DrawParam *);
extern u32 fn_12_3D740(u32);
extern void fn_12_3D73C(ColorParam *, DrawParam *, u8 *);
extern void fn_12_3D734(ColorParam *, DrawParam *, u8 *);
extern s32 fn_12_34DC(void *);
extern void fn_12_3508(void *, void *, u8 *);
extern void fn_12_34E4(void *, void *, u8 *);

/* Types 0x21 and 0x101 render at half width; the rest at full width. */
#define HALF_BY_TYPE(out) \
    switch (obj->field_4) { \
    case 0x21: \
    case 0x101: \
        (out) = 1; \
        break; \
    case 0x11: \
    case 0x31: \
    case 0x41: \
    case 0x1001: \
    case 0xF1: \
        (out) = 0; \
        break; \
    default: \
        fn_12_309C(0, 0, (u32)lbl_12_rodata_60); \
        (out) = 0; \
        break; \
    }

#define DRAW_WIDTH \
    ((obj->field_8 == 0) ? (par->field_8 * 4) : obj->field_8)

void fn_12_1578(MovieModuleObj *obj, MovieParam *par, void *arg2) {
    s32 flag;
    s32 v;

    switch (obj->field_4) {
    case 0x11:
        if (fn_12_748(obj) != 1) {
            ColorParam cp;
            DrawParam dp;
            s32 h;
            cp.field_0 = par->field_4;
            cp.field_4 = par->field_44;
            cp.field_8 = par->field_48;
            dp.field_0 = arg2;
            dp.field_4 = par->field_44;
            HALF_BY_TYPE(h)
            dp.field_8 = h ? (par->field_48 / 2) : par->field_48;
            dp.field_C = DRAW_WIDTH;
            fn_12_3D730(&cp, &dp);
        } else {
            ColorParam cp;
            DrawParam dp;
            s32 h;
            v = obj->field_34;
            flag = 1;
            if (v == 0x64) {
                flag = 0;
            } else if (v == 0x15) {
                flag = 0;
            }
            if (flag) {
                obj->field_34 = 0x15;
                fn_12_3D740((u32)obj->field_38);
            }
            cp.field_0 = par->field_4;
            cp.field_4 = par->field_44;
            cp.field_8 = par->field_48;
            dp.field_0 = arg2;
            dp.field_4 = par->field_44;
            HALF_BY_TYPE(h)
            dp.field_8 = h ? (par->field_48 / 2) : par->field_48;
            dp.field_C = DRAW_WIDTH;
            fn_12_3D73C(&cp, &dp, obj->field_38);
        }
        break;
    case 0x1001:
        {
            ColorParam cp;
            DrawParam dp;
            s32 h;
            v = obj->field_34;
            flag = 1;
            if (v == 0x64) {
                flag = 0;
            } else if (v == 0x15) {
                flag = 0;
            }
            if (flag) {
                obj->field_34 = 0x15;
                fn_12_3D740((u32)obj->field_38);
            }
            cp.field_0 = par->field_4;
            cp.field_4 = par->field_44;
            cp.field_8 = par->field_48;
            dp.field_0 = arg2;
            dp.field_4 = par->field_44;
            HALF_BY_TYPE(h)
            dp.field_8 = h ? (par->field_48 / 2) : par->field_48;
            dp.field_C = DRAW_WIDTH;
            fn_12_3D73C(&cp, &dp, obj->field_38);
        }
        break;
    case 0x31:
        {
            ColorParam cp;
            DrawParam dp;
            s32 h;
            v = obj->field_34;
            flag = 1;
            if (v == 0x64) {
                flag = 0;
            } else if (v == 2) {
                if (fn_12_34DC(obj->field_2C) != 1) {
                    flag = 0;
                }
            }
            if (flag) {
                obj->field_34 = 2;
                fn_12_3508(obj->field_2C, par->field_4C, obj->field_38);
            }
            cp.field_0 = par->field_4;
            cp.field_4 = par->field_44;
            cp.field_8 = par->field_48;
            dp.field_0 = arg2;
            dp.field_4 = par->field_44;
            HALF_BY_TYPE(h)
            dp.field_8 = h ? (par->field_48 / 2) : par->field_48;
            dp.field_C = DRAW_WIDTH;
            fn_12_3D73C(&cp, &dp, obj->field_38);
        }
        break;
    case 0x41:
        {
            ColorParam cp;
            DrawParam dp;
            s32 h;
            v = obj->field_34;
            flag = 1;
            if (v == 0x64) {
                flag = 0;
            } else if (v == 3) {
                flag = 0;
            }
            if (flag) {
                obj->field_34 = 3;
                fn_12_34E4(obj->field_2C, par->field_4C, obj->field_38);
            }
            cp.field_0 = par->field_4;
            cp.field_4 = par->field_44;
            cp.field_8 = par->field_48;
            dp.field_0 = arg2;
            dp.field_4 = par->field_44;
            HALF_BY_TYPE(h)
            dp.field_8 = h ? (par->field_48 / 2) : par->field_48;
            dp.field_C = DRAW_WIDTH;
            fn_12_3D73C(&cp, &dp, obj->field_38);
        }
        break;
    case 0x21:
        v = obj->field_34;
        flag = 1;
        if (v == 0x64) {
            flag = 0;
        } else if (v == 1) {
            flag = 0;
        }
        if (flag) {
            u8 *p = obj->field_38;
            s32 i;
            obj->field_34 = 1;
            for (i = 0; i < 0x10; i++) {
                p[i] = 0;
            }
            for (i = 0x10; i < 0xEC; i += 8) {
                s32 j;
                for (j = 0; j < 8; j++) {
                    p[i + j] = (u8)((f64)(i + j - 0x10) * 1.164f);
                }
            }
            for (i = 0xEC; i < 0x100; i++) {
                p[i] = 0xFF;
            }
        }
        {
            ColorParam cp;
            DrawParam dp;
            cp.field_0 = par->field_4;
            cp.field_4 = par->field_44;
            cp.field_8 = par->field_48;
            dp.field_0 = arg2;
            dp.field_4 = par->field_44;
            dp.field_8 = par->field_48 / 2;
            dp.field_C = DRAW_WIDTH;
            fn_12_3D730(&cp, &dp);
        }
        {
            ColorParam cp;
            DrawParam dp;
            cp.field_0 = par->field_4;
            cp.field_4 = par->field_44;
            cp.field_8 = par->field_48;
            dp.field_0 = arg2;
            dp.field_4 = par->field_44;
            dp.field_8 = par->field_48;
            dp.field_C = DRAW_WIDTH;
            fn_12_3D734(&cp, &dp, obj->field_38);
        }
        break;
    case 0xF1:
    case 0x101:
    default:
        fn_12_309C((u32)obj, (u32)par, (u32)(lbl_12_rodata_60 + 0x380));
        break;
    }
}
