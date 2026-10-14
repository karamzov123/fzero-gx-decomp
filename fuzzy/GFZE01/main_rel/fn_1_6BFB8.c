/* Non-matching: best partial attempt (53.70% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect.h"
#include "rel/main_rel/effect_car.h"

extern f32 lbl_8006D0B4(f32);
extern s32 fn_1_66B8(void *, f32);
extern u32 fn_1_864E8(s16);
extern void *fn_1_868C0(s8);
extern u8 fn_1_5910(void);
extern u32 fn_1_6EC0(u8);
extern u8 fn_1_58C4(void);
extern void fn_1_681C(u8, f32 *);
extern u32 fn_1_584AC(void);
extern f32 fn_1_8652C(s16);
extern s16 camera_get_entry_field_0xa4(u8);
extern s16 fn_1_59078(void *);
extern s16 fn_1_58F50(const void *);
extern void lbl_8006DC6C(void *);
extern u32 fn_8006E2B0(void *, f32 *);
extern u8 *memset(u8 *, int, u32);

typedef struct Obj_6C84C_Target {
    u8 pad_0[0xC];
    s16 unk_C;
    u8 pad_E[0x2];
    s32 unk_10;
    u8 pad_14[0x4];
    s16 unk_18;
    s16 unk_1A;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[0x4];
    u32 unk_34;
    u8 pad_38[0x10];
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    u8 pad_54[0x34];
    f32 unk_88;
    f32 unk_8C;
    u8 pad_90[0x4];
    f32 unk_94;
    f32 unk_98;
    f32 unk_9C;
    u8 pad_A0[0x12];
    s16 unk_B2;
    f32 unk_B4;
    u8 pad_B8[0x30];
} Obj_6C84C_Target;

typedef struct CarUnk38 {
    u8 pad_0[0x6];
    s16 unk_6;
    u8 pad_8[0x74];
    f32 x;
    f32 y;
    f32 z;
    u8 pad_88[0x3ED];
    u8 unk_475;
} CarUnk38;

typedef struct EffectCar {
    u8 pad_0[0x18];
    s16 unk_18;
    u8 pad_1A[0x1E];
    CarUnk38 *unk_38;
    u8 pad_3C[0xC];
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    u8 pad_54[0x58];
    s16 unk_AC;
    u8 pad_AE[0xA];
    u8 pad_B8[0x4];
} EffectCar;

#define RAND_FLOAT() ((f32)(u16)fn_1_584AC() / 32767.0f)
#define CALC_DIST() lbl_8006D0B4((car38->x - loc_8[0]) * (car38->x - loc_8[0]) + (car38->y - loc_8[1]) * (car38->y - loc_8[1]) + (car38->z - loc_8[2]) * (car38->z - loc_8[2]))

void fn_1_6BFB8(EffectCar *car) {
    u32 flags;
    CarUnk38 *car38;
    s32 count;
    s32 i;
    Obj_6C84C_Target obj;
    f32 loc_14[3];
    f32 loc_8[3];
    f32 min_dist;
    f32 jitter;
    f32 val;
    f32 scale;

    flags = fn_1_864E8(car->unk_18);
    fn_1_868C0((s8)car->unk_18);
    car38 = car->unk_38;
    if (fn_1_66B8(&car->pad_3C, 4.0f) == 0) {
        return;
    }

    if (fn_1_6EC0(fn_1_5910()) != 0) {
        count = fn_1_58C4();
        fn_1_681C(0, loc_8);
        min_dist = CALC_DIST();
        for (i = 1; i < count; i++) {
            fn_1_681C(i, loc_8);
            if (min_dist >= CALC_DIST()) {
                min_dist = CALC_DIST();
            }
        }
        if (min_dist > 100.0f) {
            return;
        }
    }

    memset((u8 *)&obj, 0, sizeof(obj));
    obj.unk_18 = car->unk_18;
    obj.unk_C = 12;
    obj.unk_1A = 0xFFFF;
    obj.unk_34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 0xD0);
    jitter = 0.1f * lbl_8006D0B4((f32)(obj.unk_48 * obj.unk_48) + obj.unk_4C * obj.unk_4C + obj.unk_50 * obj.unk_50);

    obj.unk_48 = car->unk_48 + jitter * (RAND_FLOAT() - 0.5f);
    obj.unk_4C = car->unk_4C + jitter * (RAND_FLOAT() - 0.5f);
    obj.unk_50 = car->unk_50 + jitter * (RAND_FLOAT() - 0.5f);
    lbl_8006DC6C(&car->pad_B8);
    fn_8006E2B0(&obj.unk_48, loc_14);

    loc_14[0] = loc_14[0] * -0.3;
    loc_14[1] = loc_14[1] * -0.3;
    loc_14[2] = loc_14[2] * -1.0;

    *(u32 *)&obj.unk_48 = *(u32 *)&loc_14[0];
    *(u32 *)&obj.unk_4C = *(u32 *)&loc_14[1];
    *(u32 *)&obj.unk_50 = *(u32 *)&loc_14[2];

    val = fn_1_8652C(car->unk_18);
    scale = 0.3f + 0.2f * RAND_FLOAT();

    switch (car38->unk_6) {
    case 2:
    case 10:
    case 23:
    case 28:
    case 35:
    case 36:
    case 38:
        obj.unk_1C = 0.9f * scale;
        obj.unk_20 = 0.8f * scale;
        obj.unk_24 = 0.5f * scale;
        break;
    case 0:
    case 4:
    case 7:
    case 19:
    case 20:
    case 24:
    case 37:
    case 40:
        obj.unk_1C = 0.9f * scale;
        obj.unk_20 = 0.6f * scale;
        obj.unk_24 = 0.5f * scale;
        break;
    case 5:
    case 14:
    case 16:
    case 17:
    case 26:
    case 39:
        obj.unk_1C = 0.5f * scale;
        obj.unk_20 = 0.9f * scale;
        obj.unk_24 = 0.5f * scale;
        break;
    case 3:
    case 6:
    case 11:
    case 12:
    case 13:
    case 18:
    case 27:
    case 31:
    case 32:
        obj.unk_1C = 0.4f * scale;
        obj.unk_20 = 0.4f * scale;
        obj.unk_24 = 0.9f * scale;
        break;
    case 8:
    case 21:
    case 22:
    case 25:
    case 29:
    case 30:
    case 33:
        obj.unk_1C = 0.5f * scale;
        obj.unk_20 = 0.4f * scale;
        obj.unk_24 = 0.5f * scale;
        break;
    default:
        obj.unk_1C = 0.9f * scale;
        obj.unk_20 = 0.9f * scale;
        obj.unk_24 = 0.9f * scale;
        break;
    }

    if ((flags & 0x40) != 0 && obj.unk_50 > 0.0f && __fabs(obj.unk_4C) < 0.8) {
        car->unk_AC = 15;
        obj.unk_B2 = 0;
        if ((s8)car38->unk_475 != -1 && fn_1_6EC0(car38->unk_475) != 0) {
            if (camera_get_entry_field_0xa4(car38->unk_475) == 0) {
                return;
            }
        }
        obj.unk_94 = 0.0f;
        obj.unk_98 = 0.2f;
        obj.unk_9C = -obj.unk_50;
        obj.unk_10 = (s32)(20.0f + 10.0f * RAND_FLOAT());
        obj.unk_2C = 5.0f + RAND_FLOAT();
        obj.unk_28 = (f32)(30.0 + 3.0 * RAND_FLOAT());
        obj.unk_88 = 0.001f * RAND_FLOAT();
        obj.unk_B4 = 1.0f;
        obj.unk_8C = 0.001f + 0.002f * RAND_FLOAT();
        fn_1_59078(&obj);
    }

    if (car->unk_AC > 0) {
        car->unk_AC--;
        count = 0;
    } else {
        count = 1;
    }

    obj.unk_B2 = 1;
    min_dist = val / 10000.0f;
    scale = val / 3000.0f;

    for (i = 0; (u8)count != 0; count--) {
        obj.unk_10 = (s32)(10.0f + 10.0f * RAND_FLOAT());
        obj.unk_34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 0x70);
        obj.unk_94 = 1.9f * (RAND_FLOAT() - 0.5f);
        obj.unk_98 = 0.8f + 0.4f * RAND_FLOAT();
        obj.unk_9C = 0.3f * (RAND_FLOAT() - 0.5f);
        if ((s8)car38->unk_475 != -1 && fn_1_6EC0(car38->unk_475) != 0 && camera_get_entry_field_0xa4(car38->unk_475) == 0) {
            if (obj.unk_94 > 0.0f) {
                obj.unk_94 += 1.0f;
            } else {
                obj.unk_94 -= 1.0f;
            }
            obj.unk_98 += 0.5f;
            obj.unk_9C -= 5.0f;
        }
        obj.unk_2C = 0.001f + min_dist * RAND_FLOAT();
        obj.unk_28 = 0.01f + scale * RAND_FLOAT();
        obj.unk_88 = 0.05f * RAND_FLOAT();
        obj.unk_B4 = 0.5f;
        obj.unk_8C = 0.05f + 0.05f * RAND_FLOAT();
        fn_1_58F50(&obj);
    }
}
