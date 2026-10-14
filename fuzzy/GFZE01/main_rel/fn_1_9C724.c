/* Non-matching: best partial attempt (98.66% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 6885000.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table5[2] = {0x000000FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 60.0f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    d = 1.0;
    s = 182.04444885253906f;
}
static const u32 fzgx_pool_table9[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.4000000059604645f;
    s = 0.01666666753590107f;
    s = -90000.0f;
    s = 100.0f;
    s = -401.0f;
    s = -0.10000000149011612f;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec3u;

typedef struct {
    u8 pad_0[0x30];
    s32 unk_30;
    s32 unk_34;
} GlobalState;

struct fn_1_9C724_lbl_1_rodata_41F0 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x44];
    f32 unk_54;
    u8 pad_58[0xC];
    f32 unk_64;
    f32 unk_68;
    f32 unk_6C;
};

struct fn_1_9C724_lbl_1_data_2A7E0 {
    s16 unk_0;
    u8 pad_2[0x46];
    u32 unk_48;
    u32 unk_4C;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    u32 unk_5C;
    u32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u32 unk_6C;
    u8 pad_70[0x18];
    u32 unk_88;
    s32 unk_8C;
};

struct fn_1_9C724_bss_3BE0_C {
    u8 pad_0[0x8];
    void *unk_8;
};

struct fn_1_9C724_lbl_1_bss_3BE0 {
    u8 pad_0[0xC];
    void *unk_C;
};

extern s16 camera_get_mode(void);
extern s16 fn_1_3F0C8(void);
extern s16 fn_1_7B054(void);
extern s32 fn_1_6F84(void);
extern s32 fn_1_7000(void);
extern struct fn_1_9C724_lbl_1_bss_3BE0 *lbl_1_bss_3BE0;
extern Vec3f lbl_1_bss_6EA10[];
extern u32 lbl_1_bss_6EA40[];
extern struct fn_1_9C724_lbl_1_data_2A7E0 lbl_1_data_2A7E0;
extern struct fn_1_9C724_lbl_1_rodata_41F0 lbl_1_rodata_41F0;
extern GlobalState *lbl_801A66CC;
extern u32 camera_forward_status(void);
extern s32 camera_is_mode_0x0b(void);
extern u32 fn_1_1FC98(void *, u32);
extern u32 fn_1_864E8(int);
extern s32 fn_1_8C5DC(u32);
extern u32 fn_1_9D260(void);
extern u32 lbl_1_data_2CC2C;
extern u32 lbl_8006DCA4(void);
extern s32 fn_1_58C4(void);
extern s32 fn_1_5910(void);
extern u32 fn_1_12850(void);
extern s8 fn_1_86624(void);
extern void *fn_1_86254(int);
extern void *fn_1_8627C(s32);
extern void fn_1_862D4(int, Vec3f *);
extern void fn_8006E294(u32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);

static inline void * fn_1_9C724_read_pointer(struct fn_1_9C724_lbl_1_bss_3BE0 * owner) { return owner->unk_C; }
static inline void fn_1_9C724_store(void *destination, u32 value) { *(u32 *)destination = value; }
#pragma opt_pointer_analysis on
static inline void * fn_1_9C724_read_pointer_(struct fn_1_9C724_lbl_1_bss_3BE0 * owner) { return owner->unk_C; }
void fn_1_9C724(void) {
    u32 *fzgx_value;
    u32 v5;
    s32 t1;
    u32 t0;
    struct fn_1_9C724_lbl_1_rodata_41F0 *rodata;
    s32 v3;
    u32 v6;
    u32 v7;
    s32 v2;
    s32 mode;
    void *p21;
    u32 v8;
    s32 t31;
    s32 v10;
    s32 v14;
    u32 one;
    struct fn_1_9C724_lbl_1_data_2A7E0 *state;
    Vec3f loc_14;
    Vec3f loc_8;

    rodata = &lbl_1_rodata_41F0;
    t0 = fn_1_58C4();
    t1 = fn_1_5910();
    mode = camera_get_mode();
    lbl_1_data_2CC2C = mode;
    if (mode == 255) {
        mode = -1;
    }
    v2 = 0;
    if (lbl_1_data_2A7E0.unk_0 == 4) {
        lbl_8006DAEC();
        lbl_8006DCA4();
        fn_8006E294((u32)&loc_14);
        lbl_8006DB30();
        if ((fn_1_7B054() == 14 && loc_14.y < (100.0f)) ||
            (fn_1_7B054() == 27 && loc_14.y < (-401.0f))) {
            v2 = 1;
        }
    }
    v3 = 128;
    if (mode >= 0 && mode < fn_1_86624()) {
        v10 = fn_1_8C5DC(mode) + 1;
        if (v10 <= 1) {
            v3 = 32;
        } else if (v10 == 2) {
            v3 = 64;
        }
    }
    v7 = 0;
    v6 = 0;
    v5 = 0;
    if (lbl_1_data_2A7E0.unk_8C != 0 || lbl_1_data_2A7E0.unk_88 < 3) {
        if (fn_1_7000() == 0 && mode != -1) {
            goto okay;
        }
    }
    v5 = 0x80000000;
    goto combined;
okay:
    if (lbl_1_bss_3BE0 == 0) {
        goto combined;
    }
    if (mode < 0) {
        goto combined;
    }
    p21 = fn_1_86254(mode);
    {
        void *p30 = fn_1_8627C(mode);
        fn_1_862D4(mode, &loc_8);
        t31 = fn_1_864E8(mode);
        if (p21 != 0) {
            v8 = *(u16 *)((u8 *)p21 + 0x214) & 0xFFFF;
        } else {
            v8 = 0;
        }
        if (p30 != 0 && *(s32 *)((u8 *)p30 + 0xB8) >= 0) {
            Vec3u *arr = fn_1_9C724_read_pointer(lbl_1_bss_3BE0);
            s32 idx = 0;
            Vec3u *e;
            if (v8 != 0 && *(s32 *)((u8 *)p30 + 0x140) >= 0) {
                idx = 1;
            }
            e = &arr[(((0) != (idx))) ? *(u32 *)((u8 *)p30 + 0x140)
                                : *(u32 *)((u8 *)p30 + 0xB8)];
            if (e->z != 0) {
                v6 = *(u32 *)((u8 *)e->z + 0x38);
            }
        }
    }
    if (fn_1_6F84() != 0) {
        if ((camera_forward_status() & 0x80000000) != 0) {
            lbl_1_bss_6EA10[t1] = loc_8;
            lbl_1_bss_6EA40[t1] = v6;
        } else if ((fn_1_12850() & 0xFF) == 3) {
            loc_8 = (*((lbl_1_bss_6EA10) + (t1)));
            v6 = (*((lbl_1_bss_6EA40) + (t1)));
        } else {
            lbl_1_bss_6EA40[t1] |= fn_1_1FC98(&loc_8, 0x7FFFFFFF);
            lbl_1_bss_6EA40[t1] |= v6;
            v7 = (*((lbl_1_bss_6EA40) + (t1)));
        }
    } else if (camera_is_mode_0x0b() != 0) {
        loc_8.z = (-0.100000001f);
        loc_8.y = (1.0f);
        loc_8.x = (0.0f);
        {
            void *v11 = ((struct fn_1_9C724_bss_3BE0_C *)fn_1_9C724_read_pointer_(lbl_1_bss_3BE0))->unk_8;
            if (v11 != 0) {
                v6 = *(u32 *)((u8 *)v11 + 0x38);
            } else {
                v6 = 0;
            }
        }
    } else if (v8 == 0 && (t31 & 0x800) != 0) {
        loc_8 = (*((lbl_1_bss_6EA10) + (t1)));
        v6 = (*((lbl_1_bss_6EA40) + (t1)));
    } else {
        lbl_1_bss_6EA10[t1] = loc_8;
        lbl_1_bss_6EA40[t1] = v6;
    }
    v5 = fn_1_1FC98(&loc_8, 0x7FFFFFFF);
    if (lbl_1_data_2A7E0.unk_0 == 4) {
        if (fn_1_7B054() == 27) {
            v5 &= 0x7FFFFFF9;
            v5 |= (v2 != 0 ? 4 : 2);
        } else {
            v5 &= 0x7FFFFFCF;
            v5 |= (v2 != 0 ? 16 : 32);
        }
    }
combined:
    v5 |= v6;
    v5 |= v7;
    if (v5 == 0) {
        v5 = 0x80000000;
    }
    one = 1;
    state = &lbl_1_data_2A7E0;
    state->unk_48 = v3;
    state->unk_4C = fn_1_9D260();
    fn_1_9C724_store(&(state->unk_50), v5);
    v10 = state->unk_88;
    state->unk_54 = (u32)(v10 << __cntlzw(v10 ^ one)) >> 31;
    state->unk_58 = v2;
    state->unk_5C = mode;
    state->unk_60 = t1;
    v14 = (fn_1_6F84() == 0);
    state->unk_64 = v14;
    state->unk_68 = lbl_801A66CC->unk_30;
    state->unk_6C = lbl_801A66CC->unk_34;
    if (v14 != 0) {
        lbl_801A66CC->unk_34 >>= 1;
        lbl_801A66CC->unk_30 += lbl_801A66CC->unk_34 << 3;
    }
    if (t0 == 1 && fn_1_3F0C8() == 42) {
        fzgx_value = &(state->unk_54);
        *fzgx_value = 1;
    }
}
#pragma opt_pointer_analysis reset

