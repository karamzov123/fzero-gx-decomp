/* Non-matching: best partial attempt (59.51% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "dolphin/os.h"
#include "rel/main_rel/effect.h"

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Sig_fn_1_862D4_Triple;

typedef struct {
    f32 x, y, z;
} Vec3;

struct fn_1_59EE4_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x4];
    u32 unk_10;
    u8 pad_14[0x4];
    s16 unk_18;
    u8 pad_1A[0x2];
    Vec3 unk_1C;
    u8 pad_28[0x14];
    Vec3 unk_3C;
    u8 pad_48[0x28];
    Vec3 unk_70;
    u8 pad_7C[0x18];
    Vec3 unk_94;
    u8 pad_A0[0xC];
    s16 unk_AC;
    u8 pad_AE[0x6];
    f32 unk_B4;
};

typedef struct {
    u8 pad_0[0xD4];
    Vec3 unk_D4;
} EffectManager;

typedef struct {
    Vec3 pos;
    u32 color;
} Vertex;

typedef struct {
    Vec3 pos;
    f32 unk_C;
    u16 unk_10;
    u16 unk_12;
    u8 color[4];
} EffectParticle;

struct EffectData {
    u8 pad_0[0xF90];
    u32 seed;
    u8 pad_F94[0x1C];
    f32 curve_x[10];
    f32 curve_y[10];
    f32 curve_z[10];
};

extern void * fn_1_868C0(s8);
extern void * fn_1_86254(s16);
extern u32 fn_1_6EC0(u8);
extern s16 camera_get_entry_field_0xa4(u32);
extern void fn_1_862D4(s16, Sig_fn_1_862D4_Triple *);
extern f32 lbl_8006D0B4(f32);
extern u32 lbl_8006DCA4(void);
extern s32 fn_1_54E34(void *, f32);
extern u32 lbl_8006D5F0(void *, void *, f32);
extern f32 fn_1_9E14C(u32, void *, f32);
extern s32 fn_1_581AC(u16, u16, void *);
extern f32 fn_1_A71AC(void);
extern void lbl_8006E1B0(void *, void *);
extern f32 fn_1_8652C(s16);
extern s32 fn_1_9F9A4(void *);

extern EffectManager *lbl_801A66CC;

static inline f32 rand_float(struct EffectData *data) {
    data->seed = data->seed * 1103515245 + 12345;
    return (f32)((data->seed >> 16) & 0x7FFF) / 32767.0f;
}

void fn_1_59EE4(struct fn_1_59EE4_Arg0 *arg0, f32 arg1) {
    void *temp;
    s8 val;
    f32 len;
    f32 f25;
    struct EffectData *data;
    f32 f27;
    union {
        u32 word;
        u8 bytes[4];
    } color;
    f32 f19;
    s32 i;
    Vertex *v;
    u32 count;
    f32 f0;
    f32 f28;
    f32 f20;
    s32 k;
    f32 f2;
    f32 f3;
    f32 f1;
    f32 clamp_val;
    f32 loc_24[2];
    Vec3 unused;
    Vec3 pt;
    Vec3 prev;
    Vec3 loc_50;
    Vec3 loc_5c;
    Sig_fn_1_862D4_Triple loc_68;
    EffectParticle loc_74;
    Vec3 loc_8c[2];
    Vertex loc_A4[12];
    f64 rnd_scale;

    if (*(s16 *)((u8 *)fn_1_868C0((s8)arg0->unk_18) + 0x3BA) >= 5) {
        temp = fn_1_86254(arg0->unk_18);
        val = *(s8 *)((u8 *)temp + 0x475);
        if (val == -1 || fn_1_6EC0((u8)val) == 0 || camera_get_entry_field_0xa4(*(u8 *)((u8 *)temp + 0x475)) != 0) {
            return;
        }
    }

    fn_1_862D4(arg0->unk_18, &loc_68);
    *(Sig_fn_1_862D4_Triple *)&loc_8c[1] = loc_68;
    loc_8c[0] = arg0->unk_3C;
    psvec_sub(&loc_8c[1], &loc_8c[0], &loc_5c);
    loc_50 = loc_5c;
    len = lbl_8006D0B4(loc_5c.x * loc_5c.x + loc_5c.y * loc_5c.y + loc_5c.z * loc_5c.z);
    f25 = len;
    if (len > 1.5f) {
        f25 = len - 1.5f;
        psvec_scale(&loc_50, (len - 1.5f) / len, &loc_50);
    }
    psvec_scale_add(&loc_8c[0], &loc_50, 0.5f, &loc_50);
    lbl_8006DCA4();
    if (!fn_1_54E34(&loc_50, f25 * 0.5f)) {
        return;
    }

    psvec_scale(&loc_5c, 1.5f / len, &lbl_801A66CC->unk_D4);
    psvec_sub(&loc_8c[1], &lbl_801A66CC->unk_D4, &loc_8c[1]);

    f27 = 0.45f * arg0->unk_B4 * arg0->unk_B4;
    if (f27 > 1.0f) {
        f27 = 255.0f;
    } else {
        f27 *= 255.0f;
    }
    psvec_scale(&arg0->unk_1C, f27, &lbl_801A66CC->unk_D4);

    color.bytes[0] = OSf32tou8(lbl_801A66CC->unk_D4.x);
    color.bytes[1] = OSf32tou8(lbl_801A66CC->unk_D4.y);
    color.bytes[2] = OSf32tou8(lbl_801A66CC->unk_D4.z);
    color.bytes[3] = 0xFF;

    f19 = -2.0f * arg0->unk_B4;
    psvec_sub(&arg0->unk_94, &loc_68, &lbl_801A66CC->unk_D4);
    lbl_8006D5F0(&lbl_801A66CC->unk_D4, &lbl_801A66CC->unk_D4, 1.0f + arg0->unk_B4);

    data = (struct EffectData *)lbl_1_data_1C698;

    data->curve_x[2] = loc_8c[1].x;
    data->curve_x[3] = lbl_801A66CC->unk_D4.x;
    data->curve_x[4] = lbl_801A66CC->unk_D4.x;
    data->curve_x[7] = loc_8c[0].x;
    data->curve_x[8] = f19 * arg0->unk_70.x;
    data->curve_x[9] = f19 * arg0->unk_70.x;

    data->curve_y[2] = loc_8c[1].y;
    data->curve_y[3] = lbl_801A66CC->unk_D4.y;
    data->curve_y[4] = lbl_801A66CC->unk_D4.y;
    data->curve_y[7] = loc_8c[0].y;
    data->curve_y[8] = f19 * arg0->unk_70.y;
    data->curve_y[9] = f19 * arg0->unk_70.y;

    data->curve_z[2] = loc_8c[1].z;
    data->curve_z[3] = lbl_801A66CC->unk_D4.z;
    data->curve_z[4] = lbl_801A66CC->unk_D4.z;
    data->curve_z[7] = loc_8c[0].z;
    data->curve_z[8] = f19 * arg0->unk_70.z;
    data->curve_z[9] = f19 * arg0->unk_70.z;

    unused = loc_8c[1];
    prev = loc_8c[1];
    loc_A4[0].pos = loc_8c[1];
    loc_A4[0].color = color.word;
    v = &loc_A4[1];

    for (i = 5; i > 0; i--) {
        f32 t = 1.0f - (f32)(i + 1) * 0.0833333358f;
        pt.x = fn_1_9E14C(2, data->curve_x, t);
        pt.y = fn_1_9E14C(2, data->curve_y, t);
        pt.z = fn_1_9E14C(2, data->curve_z, t);

        v[1].pos.x = pt.x + (rand_float(data) - 0.5f) * 0.25f;
        v[1].pos.y = pt.y + (rand_float(data) - 0.5f) * 0.25f;
        v[1].pos.z = pt.z + (rand_float(data) - 0.5f) * 0.25f;
        v[1].color = color.word;

        psvec_add(&pt, &prev, &lbl_801A66CC->unk_D4);
        psvec_scale(&lbl_801A66CC->unk_D4, 0.5f, &lbl_801A66CC->unk_D4);
        prev = pt;

        v[0].pos.x = lbl_801A66CC->unk_D4.x + (rand_float(data) - 0.5f) * 0.15f;
        v[0].pos.y = lbl_801A66CC->unk_D4.y + (rand_float(data) - 0.5f) * 0.15f;
        v[0].pos.z = lbl_801A66CC->unk_D4.z + (rand_float(data) - 0.5f) * 0.15f;
        v[0].color = color.word;

        v += 2;
    }

    v[0].pos = loc_8c[0];
    v[0].color = color.word;

    count = arg0->unk_10 * 2 + 5;
    if (count > arg0->unk_AC) {
        count = arg0->unk_AC;
    }
    fn_1_581AC((u16)count, 12, loc_A4);

    f19 = 0.25f * arg0->unk_B4;
    f0 = (0.125f + 0.5f * f19) * (1.0f + rand_float(data));
    f28 = 255.0f * f0;
    psvec_scale(&arg0->unk_1C, f28, &lbl_801A66CC->unk_D4);

    loc_74.unk_12 = 0;
    loc_74.color[0] = OSf32tou8(lbl_801A66CC->unk_D4.x);
    loc_74.color[1] = OSf32tou8(lbl_801A66CC->unk_D4.y);
    loc_74.color[2] = OSf32tou8(lbl_801A66CC->unk_D4.z);
    loc_74.color[3] = 0xFF;

    f20 = fn_1_A71AC();
    lbl_8006E1B0(&loc_8c[0], &lbl_801A66CC->unk_D4);

    f0 = -0.4f * lbl_801A66CC->unk_D4.z * f20;
    f2 = 0.2f;
    if (f0 >= 0.2f) {
        f2 = 1.5f;
        if (f0 <= 1.5f) {
            f2 = f0;
        }
    }
    loc_24[0] = f19 * f2;

    lbl_8006E1B0(&loc_8c[1], &lbl_801A66CC->unk_D4);

    f0 = -0.3f * lbl_801A66CC->unk_D4.z * f20;
    f2 = 0.2f;
    if (f0 >= 0.2f) {
        f2 = 1.5f;
        if (f0 <= 1.5f) {
            f2 = f0;
        }
    }
    loc_24[1] = f19 * f2;

    for (k = 0; k <= 1; k++) {
        if (k == 1 && (arg0->unk_8 & 0x10000)) {
            return;
        }
        if (!fn_1_54E34(&loc_8c[k], loc_24[k])) {
            continue;
        }
        if (arg0->unk_8 & 0x10000) {
            f1 = fn_1_8652C(arg0->unk_18);
            f2 = (k == 0) ? 0.2f : 0.5f;
            clamp_val = f1 / 250.0f + f2;
            f3 = 1.0f;
            if (clamp_val >= 1.0f) {
                clamp_val = f1 / 250.0f + ((k == 0) ? 0.2f : 0.5f);
                f3 = 2.0f;
                if (clamp_val <= 2.0f) {
                    f3 = f1 / 250.0f + ((k == 0) ? 0.2f : 0.5f);
                }
            }
            rnd_scale = 0.4 * (f64)rand_float(data);
            rnd_scale = 0.6 + rnd_scale;
            f0 = (f32)((f3 * loc_24[k]) * rnd_scale);
        } else {
            f0 = loc_24[k];
        }
        loc_74.pos = loc_8c[k];
        loc_74.unk_C = f0;
        loc_74.unk_10 = 0;
        fn_1_9F9A4(&loc_74);
    }
}
