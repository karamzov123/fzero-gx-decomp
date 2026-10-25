#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_common.h"

extern f32 lbl_1_rodata_78E8[19];
extern void fn_1_103B00();
extern f32 lbl_1_rodata_7934[11];
extern void fn_1_9E5B8(void *);
extern void *fn_1_54448(s32 arg0);
extern void fn_1_103FCC(void);
extern void fn_1_10688C(void);
extern void fn_1_106B68(void);
extern s32 fn_1_5910(void);
extern f32 lbl_1_rodata_7960[43];
extern f32 lbl_1_rodata_7A40[2];
extern s32 fn_1_58C4(void);
extern void lbl_8006DCA4(void);
extern void fn_1_57714(s32 arg0);
extern void fn_1_57720(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_1_57CD0(s32 arg0, void *arg1);
extern u8 lbl_1_bss_86EC4;
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_1088B8(void *arg);
extern void lbl_8006DBAC(void *arg);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void fn_1_107F74(void *arg0, int arg1);
extern u32 lbl_801A6410;
extern u32 lbl_1_data_3F284[2];
extern s32 OSIsThreadTerminated(void *arg0);
extern void OSCancelThread(void *arg0);
extern void fn_1_46B4(s32 arg0, s32 arg1, u8 *arg2, s32 arg3);
extern void fn_1_469BC(void);
extern void fn_1_466B0(s32 arg0, s32 arg1);
extern u32 lbl_1_bss_85288[2];

/* fzgx:begin fn_1_103264 noprologue */
#include "types.h"
#include "psvec.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_lig.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"
#include "types.h"
#include "rel/main_rel/bg_common.h"

#ifndef GAME_MAIN_REL_BG_LIG_TYPES_H
#define GAME_MAIN_REL_BG_LIG_TYPES_H

typedef struct {
    u8 unk_0[0xac];
} fn_1_D8EEC_LigEntry;

extern void fn_1_103264(fn_1_D8EEC_LigEntry *entry, void *arg);

#endif  // GAME_MAIN_REL_BG_LIG_TYPES_H
#ifndef GAME_MAIN_REL_CAMERA_TYPES_H
#define GAME_MAIN_REL_CAMERA_TYPES_H

#ifndef GAME_VEC3_H
#define GAME_VEC3_H

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;
#endif  // GAME_VEC3_H

typedef struct {
    u8 data[0x10];
} CamEntry;

extern void lbl_8006D9D8(CamEntry *);

#endif  // GAME_MAIN_REL_CAMERA_TYPES_H

/* end game/main_rel/camera_types.h */
/* game/vec3.h: inlined above */

#pragma fp_contract on

typedef struct Sig_fn_1_9E598_Node Sig_fn_1_9E598_Node;
struct Sig_fn_1_9E598_Node { Sig_fn_1_9E598_Node *next; };
struct fn_1_103264_lbl_1_rodata_78D0 {
    u8 pad_0[0x10];
    f32 unk_10, unk_14, unk_18, unk_1C, unk_20, unk_24, unk_28, unk_2C;
    f32 unk_30, unk_34, unk_38, unk_3C, unk_40, unk_44, unk_48, unk_4C;
    f32 unk_50, unk_54, unk_58, unk_5C, unk_60;
};
extern struct fn_1_103264_lbl_1_rodata_78D0 lbl_1_rodata_78D0;
extern f32 lbl_8006D0B4(f32);
extern s32 fn_1_54E34(void *, f32);
extern s32 fn_1_9E514(f32);
extern u32 fn_1_9E29C(u32, u32, u32);
extern void lbl_8006D7B0(void);
extern void lbl_8006DFC4(void *);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_1_557C4(void *);
extern void fn_1_56000(u8, u8, u8);
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_1_56298(f32, f32, f32, f32);
extern void fn_1_9E598(Sig_fn_1_9E598_Node *);
extern void fn_80038BFC(f32 *);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E14C(f32);
extern void lbl_8006E1F0(Vec3f *, f32, f32, f32);

#pragma opt_common_subs off
static inline f32 fn_1_103264_operand(f32 right, f32 left) { return left * right; }
static inline f32 fn_1_103264_operand_(f32 right, f32 left) { return left * right; }
void fn_1_103264(fn_1_D8EEC_LigEntry *arg0, void *arg1) {
    f32 fzgx_live;
    struct fn_1_103264_lbl_1_rodata_78D0 *p_lbl_1_rodata_78D0;
    u32 v0, v1, v2, v3;
    f32 v27, v25, v22, v21, v73, v4, v23, v6, v30, v20, v7, v5, v28, v29;
    f32 v11, v10, v12, v31, v14, v16;
    s32 v17;
    s16 v24, v33, v26;
    f32 v32, v34, v35, v36, v37, v38, v39;
    u32 v40, v41, v43;
    f32 v45, v44, v42;
    Vec3f *v48;
    s32 v47;
    f32 v61, v62, v63, v64, v65, v67, v68, v69, v71, v72, v74, v75, v76;
    u32 v66, v70;
    f32 loc_48[12];
    f32 loc_2C[7];
    Vec3f loc_20;
    Vec3f loc_14;
    Vec3f loc_8;
    s32 i;
    p_lbl_1_rodata_78D0 = &lbl_1_rodata_78D0;
    v2 = *(u32 *)((u8 *)arg0 + 0);
    v3 = *(u32 *)((u8 *)lbl_1_bss_38458->unk_8 + 160);
    loc_14 = *(Vec3f *)((u8 *)arg0 + 44);
    if (((*(u32 *)((u8 *)arg0 + 8) >> 30) & 1) != 0) {
        v4 = *(f32 *)((u8 *)v2 + 32);
        v5 = p_lbl_1_rodata_78D0->unk_10 / v4;
        v6 = *(f32 *)((u8 *)v2 + 40);
        v7 = p_lbl_1_rodata_78D0->unk_10 / *(f32 *)((u8 *)v3 + 20);
        lbl_8006D9D8((CamEntry *)(v2 + 12));
        mathutil_mtxA_rotate_z(*(s16 *)((u8 *)v2 + 28));
        mathutil_mtxA_rotate_y(*(s16 *)((u8 *)v2 + 26));
        mathutil_mtxA_rotate_x(*(s16 *)((u8 *)v2 + 24));
    } else {
        v4 = *(f32 *)((u8 *)arg0 + 24);
        v5 = p_lbl_1_rodata_78D0->unk_10 / v4;
        v6 = *(f32 *)((u8 *)arg0 + 32);
        v7 = p_lbl_1_rodata_78D0->unk_10 / *(f32 *)((u8 *)v3 + 20);
        lbl_8006D9D8((CamEntry *)((u8 *)arg0 + 12));
        mathutil_mtxA_rotate_z(*(s16 *)((u8 *)arg0 + 40));
        mathutil_mtxA_rotate_y(*(s16 *)((u8 *)arg0 + 38));
        mathutil_mtxA_rotate_x(*(s16 *)((u8 *)arg0 + 36));
    }
    v10 = p_lbl_1_rodata_78D0->unk_14 * v4;
    v11 = p_lbl_1_rodata_78D0->unk_18;
    loc_8.y = v11;
    loc_8.x = v10;
    loc_8.z = v11;
    if (fn_1_54E34(&loc_8, v10 + (f32)(p_lbl_1_rodata_78D0->unk_1C * v6)) == 0) {
        v14 = *(f32 *)((u8 *)arg0 + 108);
        *(f32 *)((u8 *)arg0 + 108) = v14 + (f32)(p_lbl_1_rodata_78D0->unk_20 * (f32)(p_lbl_1_rodata_78D0->unk_24 - v14));
    } else {
        v12 = p_lbl_1_rodata_78D0->unk_18;
        lbl_8006E1F0(&loc_20, p_lbl_1_rodata_78D0->unk_10, v12, v12);
        psvec_set(&loc_8, *(f32 *)(0xE0000000 + 44), *(f32 *)(0xE0000000 + 28), *(f32 *)(0xE0000000 + 12));
        v16 = loc_8.z;
        if (v16 < p_lbl_1_rodata_78D0->unk_18) {
            v17 = (s32)((f32)((f32)(p_lbl_1_rodata_78D0->unk_28 * loc_8.x) + (f32)(p_lbl_1_rodata_78D0->unk_2C * loc_8.y)) / v16);
        } else {
            v17 = 0;
        }
        fn_1_56000(1, 3, 0);
        v12 = p_lbl_1_rodata_78D0->unk_18;
        fn_1_56298(v12, v12, v12, v12);
        if (((*(u32 *)((u8 *)arg0 + 8) >> 27) & 1) == 0) {
            v12 = loc_20.z;
            if (v12 < p_lbl_1_rodata_78D0->unk_18) {
                v20 = p_lbl_1_rodata_78D0->unk_10 + v12;
            } else {
                v20 = p_lbl_1_rodata_78D0->unk_10;
            }
            fn_1_5621C(loc_14.x * v20, (v21 = loc_14.y) * (v34 = v20), (v22 = loc_14.z) * (v35 = v20), v20);
            v23 = p_lbl_1_rodata_78D0->unk_18;
            v24 = (s16)v17;
            v25 = p_lbl_1_rodata_78D0->unk_10;
            v26 = 0;
            v27 = p_lbl_1_rodata_78D0->unk_30;
            v28 = p_lbl_1_rodata_78D0->unk_38;
            for (; v23 < v4; v23 = v23 + (f32)(v28 * v30)) {
                v29 = v23 * v5;
                v30 = v6 * (f32)(v25 + (f32)(v27 * v29));
                if (fn_1_54E34((void *)(v3 + 8), v30) != 0) {
                    v33 = (s16)(v24 + (s32)(p_lbl_1_rodata_78D0->unk_34 * v29));
                    v32 = p_lbl_1_rodata_78D0->unk_10 - v29;
                    if (v32 < p_lbl_1_rodata_78D0->unk_10) {
                        v34 = v32 * v20;
                        fn_1_5621C(loc_14.x * v34, v21 * v34, v22 * v34, v34);
                    }
                    lbl_8006DAEC();
                    v35 = p_lbl_1_rodata_78D0->unk_18;
                    lbl_8006E0B4(v23, v35, v35);
                    lbl_8006D7B0();
                    mathutil_mtxA_rotate_z(v33);
                    lbl_8006E14C(v30 * v7);
                    fn_1_557C4((void *)v3);
                    lbl_8006DB30();
                    v26++;
                    if (v26 > 100) {
                        OSPanic((const char *)lbl_1_data_3F34C, 505, (const char *)lbl_1_data_3F358);
                    }
                }
            }
        }
        v28 = p_lbl_1_rodata_78D0->unk_3C * v6;
        if (fn_1_54E34((void *)(v3 + 8), v28) != 0) {
            v37 = p_lbl_1_rodata_78D0->unk_10 + loc_20.z;
            v38 = p_lbl_1_rodata_78D0->unk_20 + (f32)(p_lbl_1_rodata_78D0->unk_40 * v37);
            fn_1_5621C(loc_14.x * v38, loc_14.y * v38, loc_14.z * v38, v38);
            lbl_8006DAEC();
            lbl_8006D7B0();
            mathutil_mtxA_rotate_z((s16)((s16)v17 << 1));
            lbl_8006E14C(v28 * v7);
            fn_1_557C4((void *)v3);
            lbl_8006DB30();
        }
        if (*(s32 *)((u8 *)arg0 + 104) == 0 || loc_8.z > -(v28 = v28 + v23)) {
            *(f32 *)((u8 *)arg0 + 108) = p_lbl_1_rodata_78D0->unk_10;
        } else {
            fn_80038BFC(loc_2C);
            v40 = fn_1_9E514(loc_8.z + v28);
            v43 = *(u32 *)((u8 *)arg0 + 120);
            v42 = p_lbl_1_rodata_78D0->unk_18;
            for (i = 0; i < *(s32 *)((u8 *)arg0 + 104); i++) {
                if (*(u32 *)((u8 *)v43 + 4) > v40) {
                    v42 = v42 + p_lbl_1_rodata_78D0->unk_10;
                }
                v43 += 12;
            }
            if (*(f32 *)((u32)p_lbl_1_rodata_78D0 + 0x18) == v42) {
                v42 = p_lbl_1_rodata_78D0->unk_44;
            }
            v45 = *(f32 *)((u8 *)arg0 + 108);
            *(f32 *)((u8 *)arg0 + 108) = v45 + (f32)(p_lbl_1_rodata_78D0->unk_38 * (f32)(v42 - v45));
            v47 = *(s32 *)((u8 *)arg0 + 104);
            v48 = (Vec3f *)((u32)arg0 + 56);
            for (; v47 > 0; v47--) {
                *v48++ = loc_8;
            }
            fn_1_9E29C(*(u32 *)((u8 *)arg0 + 104), (u32)((u8 *)arg0 + 56), *(u32 *)((u8 *)arg0 + 120));
            fn_1_9E598((Sig_fn_1_9E598_Node *)((u8 *)arg0 + 112));
        }
        if (*(f32 *)((u8 *)arg0 + 108) > p_lbl_1_rodata_78D0->unk_18) {
            if (loc_20.z > p_lbl_1_rodata_78D0->unk_48) {
                v62 = p_lbl_1_rodata_78D0->unk_4C;
                v63 = loc_20.z - p_lbl_1_rodata_78D0->unk_48;
                v5 = v62 * v63;
                v65 = p_lbl_1_rodata_78D0->unk_40;
                v2 = *(u32 *)((u8 *)lbl_1_bss_38458->unk_8 + 184);
                v28 = v65 * (f32)(v6 * (f32)(p_lbl_1_rodata_78D0->unk_10 + (f32)(p_lbl_1_rodata_78D0->unk_50 * v5)));
                if (fn_1_54E34((void *)(v2 + 8), v28) != 0) {
                    lbl_8006DAEC();
                    v68 = v5 * *(f32 *)((u8 *)arg0 + 108);
                    fn_1_5621C(loc_14.x * v68, loc_14.y * v68, loc_14.z * v68, v68);
                    lbl_8006D7B0();
                    lbl_8006DB74(loc_48);
                    lbl_8006D758();
                    v61 = fn_1_103264_operand_((loc_8.x), (loc_8.x));
                    v61 = __fmadds(loc_8.y, loc_8.y, v61);
                    v61 = __fmadds(loc_8.z, loc_8.z, v61);
                    v61 = lbl_8006D0B4(v61);
                    lbl_8006E14C(p_lbl_1_rodata_78D0->unk_10 / v61);
                    lbl_8006DFC4(loc_48);
                    lbl_8006E14C(v28 * v7);
                    fn_1_557C4((void *)v2);
                    lbl_8006DB30();
                }
            }
            v2 = *(u32 *)((u8 *)lbl_1_bss_38458->unk_8 + 160);
            if (loc_20.z > p_lbl_1_rodata_78D0->unk_54) {
                v71 = loc_20.z - p_lbl_1_rodata_78D0->unk_54;
                v72 = p_lbl_1_rodata_78D0->unk_10;
                v73 = v72 / *(f32 *)((u8 *)v2 + 20);
                v5 = p_lbl_1_rodata_78D0->unk_58 * v71;
                fzgx_live = p_lbl_1_rodata_78D0->unk_5C;
                v28 = fzgx_live * (f32)(v6 * (f32)(v72 + (f32)(p_lbl_1_rodata_78D0->unk_60 * v5)));
                if (fn_1_54E34((void *)(v2 + 8), v28) != 0) {
                    lbl_8006DAEC();
                    v76 = fn_1_103264_operand(*(f32 *)((u8 *)arg0 + 108), (f32)(p_lbl_1_rodata_78D0->unk_14 * v5));
                    fn_1_5621C(loc_14.x * v76, loc_14.y * v76, loc_14.z * v76, v76);
                    lbl_8006D7B0();
                    mathutil_mtxA_rotate_z((s16)(-v17));
                    lbl_8006DB74(loc_48);
                    lbl_8006D758();
                    v61 = fn_1_103264_operand((loc_8.x), (loc_8.x));
                    v61 = __fmadds(loc_8.y, loc_8.y, v61);
                    v61 = __fmadds(loc_8.z, loc_8.z, v61);
                    v61 = lbl_8006D0B4(v61);
                    lbl_8006E14C(p_lbl_1_rodata_78D0->unk_10 / v61);
                    lbl_8006DFC4(loc_48);
                    lbl_8006E14C(v28 * v73);
                    fn_1_557C4((void *)v2);
                    lbl_8006DB30();
                }
            }
        }
        v12 = p_lbl_1_rodata_78D0->unk_10;
        fn_1_5621C(v12, v12, v12, v12);
        v12 = p_lbl_1_rodata_78D0->unk_18;
        fn_1_56298(v12, v12, v12, v12);
        fn_1_56000(1, 3, 1);
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_103264 */

/* fzgx:begin fn_1_103AA8 */
// Initializes the background-common state and its update callback.
void fn_1_103AA8(void) {
    lbl_1_bss_85290 = lbl_1_rodata_78E8[0];
    lbl_1_data_2A7E0.unk_34 = (u32)fn_1_103B00;
}
/* fzgx:end fn_1_103AA8 */

/* fzgx:begin fn_1_103AD4 */
void fn_1_103AD4(void) {
    f32 current = lbl_1_bss_85290;

    if (current > lbl_1_rodata_78E8[0]) {
        lbl_1_bss_85290 = current - lbl_1_rodata_7934[0];
    }
}
/* fzgx:end fn_1_103AD4 */

/* fzgx:begin fn_1_103B00 */
extern f32 lbl_1_rodata_78E8[19];
extern void fn_1_103B00();
extern f32 lbl_1_rodata_7934[11];
extern void fn_1_9E5B8(void *);
extern void *fn_1_54448(s32 arg0);
extern void fn_1_103FCC(void);
extern void fn_1_10688C(void);
extern void fn_1_106B68(void);
extern s32 fn_1_5910(void);
extern f32 lbl_1_rodata_7960[43];
extern f32 lbl_1_rodata_7A40[2];
extern s32 fn_1_58C4(void);
extern void lbl_8006DCA4(void);
extern void fn_1_57714(s32 arg0);
extern void fn_1_57720(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_1_57CD0(s32 arg0, void *arg1);
extern u8 lbl_1_bss_86EC4;
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_1088B8(void *arg);
extern void lbl_8006DBAC(void *arg);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void fn_1_107F74(void *arg0, int arg1);
extern u32 lbl_801A6410;
extern u32 lbl_1_data_3F284[2];
extern s32 OSIsThreadTerminated(void *arg0);
extern void OSCancelThread(void *arg0);
extern void fn_1_46B4(s32 arg0, s32 arg1, u8 *arg2, s32 arg3);
extern void fn_1_469BC(void);
extern void fn_1_466B0(s32 arg0, s32 arg1);
extern u32 lbl_1_bss_85288[2];


extern u32 fn_1_584AC(void);
extern void fn_80073778(void *, s32);
extern void fn_80073A58(int, void *, s8);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800738E0(s32, s32, s32);
extern void fn_800739E0(s32, s32, s32);
extern void fn_80073D60(s32, s32, s32, s32, s32);

typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
} BgTexState;

typedef struct {
    u8 pad_0[0xC];
    BgTexState state;
} BgTexObj;

#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[1] = {0x42700000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 182.04444885253906f;
    d = 4503601774854144.0;
    s = 1.0f;
    s = 0.5f;
    s = 0.0f;
    s = 5.0f;
    s = 0.20000000298023224f;
    s = -1.0f;
    s = 32768.0f;
    s = 16384.0f;
    s = 2.0f;
    s = 98304.0f;
    s = 0.25f;
    s = 3.0f;
    s = 0.4000000059604645f;
    s = -0.10000000149011612f;
    s = 0.6000000238418579f;
    s = 2.5f;
    s = 20.0f;
    s = 0.8500000238418579f;
    s = 6.666666507720947f;
    s = 1.5f;
    s = 30.0f;
    s = 0.009999999776482582f;
    d = 0.0;
    d = 3.0;
    s = 32767.0f;
}
static const unsigned long fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))

void fn_1_103B00(BgTexObj *obj) {
    f32 mtx[2][3];
    BgTexState s;
    f32 scale;
    f32 v;

    s = obj->state;
    fn_80073778(*(void **)(*(u8 **)((u8 *)lbl_1_bss_38458->unk_8 + 0xd8) + 0x24), s.unk_C);

    scale = 2.0f * lbl_1_bss_85290;
    v = (f32)(((f32)(u16)fn_1_584AC() / 32767.0f - 0.5) * CLAMP(scale, 0.0, 3.0));
    mtx[0][0] = v;
    mtx[0][1] = 0.0f;
    mtx[0][2] = 0.0f;
    mtx[1][0] = 0.0f;
    mtx[1][1] = v;
    mtx[1][2] = 0.0f;
    fn_80073A58(s.unk_1C, mtx, 1);

    fn_800745A4(s.unk_4, 1, 4, 0x3c, 0, 0x7d);
    fn_800738E0(s.unk_10, s.unk_4, s.unk_C);
    fn_800739E0(s.unk_10, 0, 0);
    fn_80073D60(0, s.unk_10, 1, 0, s.unk_1C);

    s.unk_10++;
    s.unk_4++;
    s.unk_1C++;
    obj->state = s;
}
/* fzgx:end fn_1_103B00 */

/* fzgx:begin fn_1_103D28 */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x42700000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 182.04444885253906f;
    d = 4503601774854144.0;
    s = 1.0f;
    s = 0.5f;
    s = 0.0f;
    s = 5.0f;
    s = 0.20000000298023224f;
    s = -1.0f;
    s = 32768.0f;
    s = 16384.0f;
    s = 2.0f;
    s = 98304.0f;
    s = 0.25f;
    s = 3.0f;
    s = 0.4000000059604645f;
    s = -0.10000000149011612f;
    s = 0.6000000238418579f;
    s = 2.5f;
    s = 20.0f;
    s = 0.8500000238418579f;
    s = 6.666666507720947f;
    s = 1.5f;
    s = 30.0f;
    s = 0.009999999776482582f;
    d = 0.0;
    d = 3.0;
    s = 32767.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    d = 4503599627370496.0;
    s = 4.0f;
    s = 65536.0f;
    s = 0.30000001192092896f;
    s = 0.800000011920929f;
}
#pragma section code_type ".text"

extern void *memset(void *dst, int c, u32 n);
extern u32 __cvt_fp2unsigned(f32 x);
extern void lbl_8006D91C(s32 arg0);
extern void *lbl_8006E1F0(void *arg0, f32 arg1, f32 arg2, f32 arg3);

typedef struct Fn1_103D28_Item {
    s32 field0;
    f32 field4;
    f32 field8;
} Fn1_103D28_Item;

typedef struct Fn1_103D28_Group {
    u8 pad0[4];
    Fn1_103D28_Item item;
    u8 pad1[0xe0];
} Fn1_103D28_Group;

typedef struct Fn1_103D28_Buf {
    u8 pad0[0x50];
} Fn1_103D28_Buf;

typedef struct Fn1_103D28_Rec {
    s32 count;
    void *ptr;
    s32 self;
    u8 pad0[0xf0];
} Fn1_103D28_Rec;

typedef struct Fn1_103D28_S4 {
    u8 pad0[0x14];
    f32 value;
} Fn1_103D28_S4;

typedef struct Fn1_103D28_S3 {
    u8 pad0[8];
    Fn1_103D28_S4 *link;
} Fn1_103D28_S3;

typedef struct Fn1_103D28_S2 {
    u8 pad0[8];
    Fn1_103D28_S3 *link;
} Fn1_103D28_S2;

typedef struct Fn1_103D28_S1 {
    u8 pad0[8];
    Fn1_103D28_S2 *link;
} Fn1_103D28_S1;

typedef struct Fn1_103D28_S0 {
    Fn1_103D28_S1 *link;
} Fn1_103D28_S0;

typedef struct Fn1_103D28_Obj {
    Fn1_103D28_Group groups[4];
    u8 pad0[4];
    Fn1_103D28_Buf bufs[4];
    f32 f[4];
    f32 g[4];
    u8 pad1[0x3c4];
    Fn1_103D28_Rec recs[4];
} Fn1_103D28_Obj;

void fn_1_103D28(Fn1_103D28_Obj *arg0, f32 arg1, u32 arg2) {
    s32 j;
    Fn1_103D28_Item *entry;
    u32 value;
    u32 count;
    Fn1_103D28_S4 *node;
    s32 i;

    if (*(u32 *)arg0 != 0) {
        value = arg2 & 0xff;
        for (i = 0; i < 4; i++) {
            arg0->recs[i].count = (s32)arg0->g[i];
            arg0->recs[i].ptr = &arg0->recs[i].self;
            memset(&arg0->bufs[i], 0, __cvt_fp2unsigned(4.0f * arg0->g[i]));
            arg0->f[i] = arg1;
            count = (value < 0x14) ? value : 0x14;
            arg0->g[i] = (f32)(s32)count;
            entry = &arg0->groups[i].item;
            node = ((Fn1_103D28_S3 *)((Fn1_103D28_S2 *)((Fn1_103D28_S1 *)((Fn1_103D28_S0 *)arg0)->link)->link)->link)->link;
            j = (s32)arg0->g[i];
            while (j > 0) {
                lbl_8006D91C((s32)((4.0f * (f32)(s32)j) / arg0->g[i] * 65536.0f));
                lbl_8006E1F0(entry, 0.3f * node->value * ((f32)(s32)j / arg0->g[i]), 0.0f, 0.0f);
                j--;
                entry++;
            }
        }
    }
}
/* fzgx:end fn_1_103D28 */

/* fzgx:begin fn_1_103F10 */
void fn_1_103F10(void *arg) {
    int count;
    u8 *entry;

    entry = (u8 *)arg + 0x8e4;
    count = 4;
    do {
        fn_1_9E5B8(entry);
        count--;
        entry += 0xfc;
    } while (count > 0);
}
/* fzgx:end fn_1_103F10 */

/* fzgx:begin fn_1_103F58 */
typedef void (*Fn103FCC)(void);

typedef struct Fn1_103F58_Object {
    u8 pad0[4];
    Fn103FCC callback;
    void *context;
} Fn1_103F58_Object;

extern Fn1_103F58_Object *fn_1_548AC(s32 arg0);
extern void fn_1_5489C(void *arg0, Fn1_103F58_Object *arg1);

void fn_1_103F58(void *arg0) {
    void *value;
    Fn1_103F58_Object *object;

    if (*(u32 *)arg0 != 0) {
        value = fn_1_54448(0);
        object = fn_1_548AC(12);
        if (object != 0) {
            object->callback = fn_1_103FCC;
            object->context = arg0;
            fn_1_5489C(value, object);
        }
    }
}
/* fzgx:end fn_1_103F58 */

/* fzgx:begin fn_1_103FCC noprologue */
#include "types.h"
#include "psvec.h"

typedef struct Sig_fn_1_9E598_Node Sig_fn_1_9E598_Node;
struct Sig_fn_1_9E598_Node {
    Sig_fn_1_9E598_Node *next;
};

struct fn_1_103FCC_lbl_1_rodata_78D0 {
    u8 pad_0[0x8];
    f64 unk_8;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x4];
    f32 unk_20;
    u8 pad_24[0xC];
    f32 unk_30;
    u8 pad_34[0x10];
    f32 unk_44;
    u8 pad_48[0x48];
    f32 unk_90;
    u8 pad_94[0x8];
    f32 unk_9C;
    f32 unk_A0;
    f32 unk_A4;
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
};

extern f32 lbl_8006D0B4(f32);
extern s32 fn_1_5910(void);
extern s32 fn_1_9E514(f32);
extern const struct fn_1_103FCC_lbl_1_rodata_78D0 lbl_1_rodata_78D0;
extern u32 fn_1_9E29C(u32, u32, u32);
extern u32 lbl_8006D7B0(void);
extern u32 lbl_8006DFC4(void *);
extern u32 lbl_8006E0A4(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_1_556B8(void *);
extern void fn_1_56000(u8, u8, u8);
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_1_56298(f32, f32, f32, f32);
extern void fn_1_9E598(Sig_fn_1_9E598_Node *);
extern void fn_1_A714C(f32 *, f32 *, f32 *, f32 *);
extern void fn_80038BFC(f32 *);
extern void fn_80072558(void);
extern void fn_80072B7C(u32);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006E13C(void *);
extern void lbl_8006E14C(f32);

typedef struct Fn1_103FCC_Vec {
    f32 x, y, z;
} Fn1_103FCC_Vec;

#pragma section code_type ".fzgxpool"
static void fzgx_shared_pool_primer(void) {
    /* Volatile stores retain the shared single-precision literal-pool ordering. */
    volatile f32 f;
    /* Volatile stores retain the shared double-precision literal-pool ordering. */
    volatile f64 d;
    f = 60.0f;
    f = 182.04444885253906f;
    d = 4503601774854144.0;
    f = 1.0f;
    f = 0.5f;
    f = 0.0f;
    f = 5.0f;
    f = 0.20000000298023224f;
    f = -1.0f;
    f = 32768.0f;
    f = 16384.0f;
    f = 2.0f;
    f = 98304.0f;
    f = 0.25f;
    f = 3.0f;
    f = 0.4000000059604645f;
    f = -0.10000000149011612f;
    f = 0.6000000238418579f;
    f = 2.5f;
    f = 20.0f;
    f = 0.8500000238418579f;
    f = 6.666666507720947f;
    f = 1.5f;
    f = 30.0f;
    f = 0.009999999776482582f;
    d = 0.0;
    d = 3.0;
    f = 32767.0f;
    d = 0.5;
    d = 4503599627370496.0;
    f = 4.0f;
    f = 65536.0f;
    f = 0.30000001192092896f;
    f = 0.800000011920929f;
    f = 0.699999988079071f;
    f = 24576.0f;
    f = 8192.0f;
    f = 8.0f;
    f = 4096.0f;
}
#pragma section code_type ".text"

extern f32 __fmadds(f32, f32, f32);
#pragma fp_contract on
void fn_1_103FCC(void *arg0) {
    u32 v2;
    f32 v4;
    f32 v5;
    f32 v7;
    f32 v8;
    f32 v10;
    f32 v11;
    f32 v12;
    u32 v16;
    s32 v19;
    u32 v20;
    u32 v21;
    f32 v22;
    f32 v23;
    f32 v24;
    u32 v25;
    u32 v26;
    s32 v27;
    Fn1_103FCC_Vec *v28;
    Fn1_103FCC_Vec *v29;
    f32 v35;
    f32 v37;
    f32 v38;
    s32 v39;
    u32 v41;
    f32 v42;
    f32 v46;
    f32 v45;
    f32 v43;
    f32 v48;
    f32 v59;
    f32 v60;
    f32 v61;
    f32 v62;
    f32 v63;
    f32 v66;
    f32 v67;
    struct { u32 a[12]; } loc_40;
    struct { f32 a[7]; } loc_24;
    Fn1_103FCC_Vec loc_18;
    f32 loc_14;
    f32 loc_10;
    f32 loc_C;
    f32 loc_8;
    s32 t11;
    u32 v64;
    s32 v54;
    s32 v51;
    u32 v1;
    s32 v65;
    u32 v49;
    u32 v3;
    s32 v50;
    f32 v57;
    f32 v14;
    f32 v15;
    f32 v40;
    f32 v47;
    f32 v36;
    f32 v6;
    f32 v44;
    f32 *v18;
    s32 t0;
    u32 v0;
    u32 v13;

    t0 = fn_1_5910();
    fn_1_A714C(&loc_14, &loc_10, &loc_C, &loc_8);
    v0 = *(u32 *)((u8 *)arg0 + 8);
    v1 = *(u32 *)((u8 *)v0 + 0);
    v2 = *(u32 *)((u8 *)*(u32 *)((u8 *)v1 + 8) + 8);
    v3 = *(u32 *)((u8 *)v2 + 8);
    lbl_8006DCA4();
    lbl_8006E0A4(v1 + 12);
    mathutil_mtxA_rotate_z(*(s16 *)((u8 *)v1 + 28));
    mathutil_mtxA_rotate_y(*(s16 *)((u8 *)v1 + 26));
    mathutil_mtxA_rotate_x(*(s16 *)((u8 *)v1 + 24));
    lbl_8006E13C((void *)(v1 + 32));
    lbl_8006E0A4(v3 + 8);
    v4 = 0.0f;
    fn_1_56298(v4, v4, v4, v4);
    fn_80038BFC((f32 *)&loc_24);
    v5 = 1.0f;
    v6 = v5 / loc_24.a[3];
    v7 = *(f32 *)(0xE0000000 + 0x2C);
    psvec_set(&loc_18, v7, *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
    if (!(v7 >= -loc_C)) {
        v10 = v5 / v7;
        v11 = (f32)(loc_18.y * loc_24.a[3]);
        v12 = (f32)(v10 * (f32)(loc_18.x * loc_24.a[1]));
        v13 = v0 + t0 * 252 + 2276;
        v14 = loc_24.a[2] + v12;
        v15 = loc_24.a[4] + (f32)(v10 * v11);
        t11 = fn_1_9E514(v7 + *(f32 *)((u8 *)v3 + 20));
        v16 = *(u32 *)((u8 *)v13 + 8);
        v18 = (f32 *)(v0 + t0 * 80 + 964);
        v20 = (u32)v18;
        v21 = v16;
        for (v19 = (s32)((f32 *)((u8 *)v0 + 1300))[t0]; v19 > 0; v19--) {
            if (*(u32 *)((u8 *)v21 + 4) > (u32)t11) {
                v22 = *(f32 *)v20;
                v8 = 0.5f;
                *(f32 *)v20 = v22 + (f32)(v8 * (f32)(((f32 *)((u8 *)v0 + 1284))[t0] - v22));
            } else if (*(u8 *)((u8 *)v21 + 8) == 255) {
                v23 = *(f32 *)v20;
                v8 = 0.5f;
                *(f32 *)v20 = v23 + (f32)(v8 * (f32)(-0.1f - v23));
            } else {
                v24 = *(f32 *)v20;
                v8 = 0.5f;
                *(f32 *)v20 = v24 + (f32)(v8 * (f32)(-0.1f - v24));
            }
            v20 += 4;
            v21 += 12;
        }
        v25 = v0 + t0 * 240 + 1316;
        v26 = v0 + t0 * 240 + 4;
        v27 = (s32)((f32 *)((u8 *)v0 + 1300))[t0];
        v28 = (Fn1_103FCC_Vec *)v26;
        v29 = (Fn1_103FCC_Vec *)v25;
        for (v19 = v27; v19 > 0; v19--) {
            *v29 = loc_18;
            v29->x += v28->x;
            v29->y += v28->y;
            v28++;
            v29++;
        }
        fn_1_9E29C((s32)((f32 *)((u8 *)v0 + 1300))[t0], v25, *(u32 *)((u8 *)v13 + 8));
        fn_1_9E598((Sig_fn_1_9E598_Node *)v13);
        lbl_8006D7B0();
        lbl_8006DB74(&loc_40);
        v35 = 1.0f;
        v36 = -(v35 + loc_C) / loc_18.z;
        lbl_8006D758();
        lbl_8006E14C(v36);
        lbl_8006DFC4(&loc_40);
        v40 = 0.0f;
        v41 = (u32)v18;
        psvec_set(&loc_18, *(f32 *)(0xE0000000 + 44), *(f32 *)(0xE0000000 + 28), *(f32 *)(0xE0000000 + 12));
        lbl_8006DAEC();
        v38 = ((f32 *)((u8 *)v0 + 1300))[t0];
        v37 = v40;
        for (v39 = (s32)v38; v39 > 0; v39--) {
            v8 = *(f32 *)v41;
            if (v8 < v37) {
            } else {
                v40 += v8;
            }
            v41 += 4;
        }
        v38 = 2.0f / v38;
        v40 *= v38;
        v40 -= 0.8f;
        v46 = loc_18.z;
        v43 = loc_18.y;
        v42 = loc_18.x * loc_18.x;
        v42 = __fmadds(v43, v43, v42);
        v42 = __fmadds(v46, v46, v42);
        v42 = lbl_8006D0B4(v42);
        v43 = 1.0f;
        v44 = v40 * (-loc_18.z / v42);
        v45 = v44;
        if (v44 > v43) {
            v45 = v43;
        } else {
            v46 = 0.0f;
            if (v44 < v46) v45 = v46;
        }
        v47 = 1.0f - (f32)(0.7f * v45);
        fn_1_56000(1, 3, 0);
        v8 = 8192.0f;
        v48 = 24576.0f;
        v49 = *(u32 *)((u8 *)v0 + 3284);
        v50 = (s32)(v48 + (f32)(v8 * (f32)((f32)(0.7f * v14) + v15)));
        lbl_8006DAEC();
        v51 = (s32)((f32 *)((u8 *)v0 + 1300))[t0];
        v54 = v51 << 16;
        while (v51 > 0) {
            v57 = *(f32 *)v18;
            if (!(v57 <= 0.0f)) {
                lbl_8006DAEC();
                lbl_8006E0A4(v26);
                v59 = (f32)v54 / ((f32 *)((u8 *)v0 + 1300))[t0];
                mathutil_mtxA_rotate_z((s32)((f32)v50 + v59));
                v8 = v47 * (f32)(v57 * (f32)(8.0f / ((f32 *)((u8 *)v0 + 1300))[t0]));
                fn_1_5621C(v8, v8, v8, 1.0f);
                v60 = 0.2f;
                v61 = v60 * (f32)(1.0f + v57);
                v8 = (f32)(v6 * (f32)(v61 * -loc_18.z)) / (f32)(*(f32 *)((u8 *)v49 + 20) * v36);
                lbl_8006E14C(v8);
                fn_80072B7C(0);
                fn_80072558();
                fn_1_556B8((void *)v49);
                fn_80072B7C(1);
                lbl_8006DB30();
            }
            v54 -= 0x10000;
            v51--;
            v18++;
            v26 += 12;
        }
        lbl_8006DB30();
        v8 = 1.0f;
        fn_1_5621C(v8, v8, v8, v8);
        fn_1_56000(1, 3, 1);
        v8 = 0.5f * v15;
        v62 = 4096.0f;
        v63 = 24576.0f;
        v64 = *(u32 *)((u8 *)v0 + 3284);
        v65 = (s32)(v63 + (f32)(v62 * (f32)(v14 + v8)));
        if (v44 > 0.0f) {
            fn_1_56000(1, 3, 0);
            mathutil_mtxA_rotate_z((s16)v65);
            v66 = 1.0f;
            v8 = v44;
            if (v44 > v66) v8 = v66;
            fn_1_5621C(v8, v8, v8, 1.0f);
            v67 = 4.0f;
            v8 = v67 * -loc_18.z;
            v8 *= v6;
            v8 /= (f32)(*(f32 *)((u8 *)v64 + 20) * v36);
            lbl_8006E14C(v8);
            fn_80072B7C(0);
            fn_80072558();
            fn_1_556B8((void *)v64);
            fn_80072B7C(1);
            v8 = 1.0f;
            fn_1_5621C(v8, v8, v8, v8);
            fn_1_56000(1, 3, 1);
        }
        lbl_8006DB30();
    }
}
/* fzgx:end fn_1_103FCC */

/* fzgx:begin fn_1_104710 */
void fn_1_104710(void) {
    fn_1_10688C();
}
/* fzgx:end fn_1_104710 */

/* fzgx:begin fn_1_104730 */
extern f32 lbl_1_rodata_78E8[19];
extern void fn_1_103B00();
extern f32 lbl_1_rodata_7934[11];
extern void fn_1_9E5B8(void *);
extern void *fn_1_54448(s32 arg0);
extern void fn_1_103FCC(void);
extern void fn_1_10688C(void);
extern void fn_1_106B68(void);
extern s32 fn_1_5910(void);
extern f32 lbl_1_rodata_7960[43];
extern f32 lbl_1_rodata_7A40[2];
extern s32 fn_1_58C4(void);
extern void lbl_8006DCA4(void);
extern void fn_1_57714(s32 arg0);
extern void fn_1_57720(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_1_57CD0(s32 arg0, void *arg1);
extern u8 lbl_1_bss_86EC4;
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_1088B8(void *arg);
extern void lbl_8006DBAC(void *arg);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void fn_1_107F74(void *arg0, int arg1);
extern u32 lbl_801A6410;
extern u32 lbl_1_data_3F284[2];
extern s32 OSIsThreadTerminated(void *arg0);
extern void OSCancelThread(void *arg0);
extern void fn_1_46B4(s32 arg0, s32 arg1, u8 *arg2, s32 arg3);
extern void fn_1_469BC(void);
extern void fn_1_466B0(s32 arg0, s32 arg1);
extern u32 lbl_1_bss_85288[2];

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_1_104730_Vec;

typedef struct {
    fn_1_104730_Vec dir;
    fn_1_104730_Vec up;
} fn_1_104730_Basis;

typedef struct {
    u8 pad_0[0xC];
    fn_1_104730_Vec near_;
    fn_1_104730_Vec mid;
    fn_1_104730_Vec far_;
    fn_1_104730_Basis basis;
    u8 unk_48[0x40];
} fn_1_104730_Entry;

typedef struct {
    u8 pad_0[0x18];
    f32 zero;
    u8 pad_1C[0x9C];
    fn_1_104730_Vec default_pos;
    fn_1_104730_Basis default_basis;
    f32 near_dir;
    f32 mid_up;
    f32 mid_dir;
    f32 near_up;
    f32 far_dir;
    f32 far_up;
} fn_1_104730_Consts;

extern fn_1_104730_Consts lbl_1_rodata_78D0;
extern fn_1_104730_Entry lbl_1_bss_85298[];
extern s32 lbl_1_bss_85294;
extern f32 (*lbl_801A6D00)[4];

extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern s16 camera_get_mode(void);
extern void lbl_8006D784(void *);
extern void lbl_8006DAEC(void);
extern void fn_1_862D4(s32, fn_1_104730_Vec *);
extern void fn_1_8636C(s32, void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DB30(void);

#pragma opt_propagation off
void fn_1_104730(int index, int use_matrix) {
    fn_1_104730_Consts *c = &lbl_1_rodata_78D0;
    int id;
    fn_1_104730_Entry *entry;
    s32 mode;
    fn_1_104730_Vec pos;
    f32 a;
    f32 b;

    id = index;
    fn_1_5948(index);
    mode = camera_get_mode();
    entry = &lbl_1_bss_85298[index];
    if (mode == -1) {
        pos = c->default_pos;
        entry->basis = c->default_basis;
        lbl_8006D784(entry->unk_48);
    } else {
        lbl_8006DAEC();
        fn_1_862D4(mode, &pos);
        if (use_matrix != 0) {
            f32 zero;
            fn_1_8636C(mode, lbl_801A6D00);
            zero = c->zero;
            *(f32 *)(0xE0000000 + 0x0C) = zero;
            *(f32 *)(0xE0000000 + 0x1C) = zero;
            *(f32 *)(0xE0000000 + 0x2C) = zero;
            entry->basis.dir.x = -lbl_801A6D00[0][2];
            entry->basis.dir.y = -lbl_801A6D00[1][2];
            entry->basis.dir.z = -lbl_801A6D00[2][2];
            entry->basis.up.x = lbl_801A6D00[0][1];
            entry->basis.up.y = lbl_801A6D00[1][1];
            entry->basis.up.z = lbl_801A6D00[2][1];
            lbl_8006DB74(entry->unk_48);
        }
        lbl_8006DB30();
    }

    switch (lbl_1_bss_85294 % 2) {
    case 0:
        a = c->near_dir;
        b = c->mid_up;
        break;
    case 1:
    default:
        a = c->mid_dir;
        b = c->near_up;
        break;
    }

    entry->near_.x = pos.x + (f32)(entry->basis.dir.x * a) + (f32)(entry->basis.up.x * b);
    entry->near_.y = pos.y + (f32)(entry->basis.dir.y * a) + (f32)(entry->basis.up.y * b);
    entry->near_.z = pos.z + (f32)(entry->basis.dir.z * a) + (f32)(entry->basis.up.z * b);
    entry->mid.x = pos.x + (f32)(c->mid_dir * entry->basis.dir.x) + (f32)(c->mid_up * entry->basis.up.x);
    entry->mid.y = pos.y + (f32)(c->mid_dir * entry->basis.dir.y) + (f32)(c->mid_up * entry->basis.up.y);
    entry->mid.z = pos.z + (f32)(c->mid_dir * entry->basis.dir.z) + (f32)(c->mid_up * entry->basis.up.z);
    entry->far_.x = pos.x + (f32)(entry->basis.dir.x * c->far_dir) + (f32)(entry->basis.up.x * c->far_up);
    entry->far_.y = pos.y + (f32)(entry->basis.dir.y * c->far_dir) + (f32)(entry->basis.up.y * c->far_up);
    entry->far_.z = pos.z + (f32)(entry->basis.dir.z * c->far_dir) + (f32)(entry->basis.up.z * c->far_up);
    fn_1_627C(id);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_104730 */

/* fzgx:begin fn_1_1049E0 pool */
#ifndef GAME_MAIN_REL_BG_COMMON_TYPES_H
#define GAME_MAIN_REL_BG_COMMON_TYPES_H

#endif  // GAME_MAIN_REL_BG_COMMON_TYPES_H

extern s32 fn_1_58C4(void);
extern void lbl_8006DCA4(void);

/* begin dolphin/ar.h (deltawave784/windows-and-types@cf9407c75) */
#ifndef DOLPHIN_AR_H
#define DOLPHIN_AR_H

/* ARAM DMA request queue (ARQ), Dolphin SDK names. */

/* begin layout_check.h (deltawave784/windows-and-types@cf9407c75) */
#ifndef LAYOUT_CHECK_H
#define LAYOUT_CHECK_H

/* Compile-time layout checks for owned types. They declare array typedefs
 * only, so they emit no code or data under MWCC: a wrong size or offset is
 * a negative array bound and fails the compile. */
#define LAYOUT_CHECK_JOIN2(a, b) a##b
#define LAYOUT_CHECK_JOIN(a, b) LAYOUT_CHECK_JOIN2(a, b)
#define CHECK_SIZE(T, size) \
    typedef char LAYOUT_CHECK_JOIN(layout_size_, T)[(sizeof(T) == (size)) ? 1 : -1]
#define CHECK_OFFSET(T, field, offset) \
    typedef char LAYOUT_CHECK_JOIN(LAYOUT_CHECK_JOIN(layout_offset_, T), __LINE__) \
        [((unsigned long)&((T *)0)->field == (offset)) ? 1 : -1]

#endif

/* end layout_check.h */

typedef void (*ARQCallback)(u32 pointerToARQRequest);

typedef struct ARQRequest {
    struct ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    ARQCallback callback;
} ARQRequest;

CHECK_OFFSET(ARQRequest, dest, 0x14);
CHECK_SIZE(ARQRequest, 0x20);

#endif

/* end dolphin/ar.h */

struct fn_1_1049E0_lbl_801A63C0 { u32 unk_0; };
struct fn_1_1049E0_record {
    f32 pos[3];
    f32 start[3];
    f32 middle[3];
    f32 end[3];
    u8 pad_30[0x48];
    f32 unk_78;
    u16 unk_7C;
    u8 unk_7E;
    u8 unk_7F;
    s16 unk_80;
    s16 unk_82;
    s16 unk_84;
    s16 unk_86;
};
struct fn_1_1049E0_sub {
    u8 pad_0[0xC];
    s16 unk_C;
    u8 pad_E[0x2];
};
extern struct fn_1_1049E0_lbl_801A63C0 lbl_801A63C0;
extern s16 camera_get_mode(void);
extern s16 fn_1_3F0C8(void);
extern s32 fn_1_58C4(void);
extern s32 fn_1_6514(s32);
extern u32 fn_1_864E8(s32);
extern s32 fn_1_F2F34(void);
extern u8 lbl_1_bss_6F239;
extern void fn_1_104730(int, int);
extern void fn_1_5948(int);
extern void fn_1_627C(int);
extern void fn_1_A2D84(u32);
extern s32 fn_1_54E34(void *, f32);
extern void lbl_8006DCA4(void);
extern void fn_1_106D30(u32);
extern void DCInvalidateRange(void *, u32);
extern void ARQPostRequest(ARQRequest *, u32, u32, u32, u32, u32, u32, ARQCallback);

#pragma section code_type ".fzgxpool"
/* Primes the TU literal pool (lbl_1_rodata_78D0) in retail order. Conversion
   constants are pooled after a function's own literals, so each one closes
   its primer function. The pool section is created here, before the .bss
   objects below, which fixes the order of the two section-base registers. */
void fzgx_pool_fn_1_1049E0(f32 *o, s32 s) {
    o[0] = 60.0f;
    o[1] = 182.04445f;
    o[2] = (f32)s;
}

void fzgx_pool_fn_1_1049E0_b(f32 *o, f64 *d, u32 u) {
    o[3] = 1.0f;
    o[4] = 0.5f;
    o[5] = 0.0f;
    o[6] = 5.0f;
    o[7] = 0.2f;
    o[8] = -1.0f;
    o[9] = 32768.0f;
    o[10] = 16384.0f;
    o[11] = 2.0f;
    o[12] = 98304.0f;
    o[13] = 0.25f;
    o[14] = 3.0f;
    o[15] = 0.4f;
    o[16] = -0.1f;
    o[17] = 0.6f;
    o[18] = 2.5f;
    o[19] = 20.0f;
    o[20] = 0.85f;
    o[21] = 6.6666665f;
    o[22] = 1.5f;
    o[23] = 30.0f;
    o[24] = 0.01f;
    d[0] = 0.0;
    d[1] = 3.0;
    o[25] = 32767.0f;
    d[2] = 0.5;
    o[26] = (f32)u;
}

void fzgx_pool_fn_1_1049E0_c(f32 *o) {
    o[27] = 4.0f;
    o[28] = 65536.0f;
    o[29] = 0.3f;
    o[30] = 0.8f;
    o[31] = 0.7f;
    o[32] = 24576.0f;
    o[33] = 8192.0f;
    o[34] = 8.0f;
    o[35] = 4096.0f;
    o[36] = -20.0f;
}

/* An aggregate initializer is pooled when it is parsed, ahead of the
   function's literals. */
void fzgx_pool_fn_1_1049E0_d(f32 *o, int i) {
    f32 t[9] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f };
    o[37] = t[i];
    o[38] = 1040.0f;
    o[39] = 9.5f;
    o[40] = 40.0f;
    o[41] = 29.5f;
    o[42] = 140.0f;
    o[43] = 109.5f;
}
#pragma section code_type ".text"

/* The TU's .bss objects starting at lbl_1_bss_85280, in retail order. */
u32 fzgx_obj_lbl_1_bss_85280;
u32 fzgx_obj_lbl_1_bss_85284;
u32 fzgx_obj_lbl_1_bss_85288[2];
f32 fzgx_obj_lbl_1_bss_85290;
s32 fzgx_obj_lbl_1_bss_85294;
struct fn_1_1049E0_record fzgx_obj_lbl_1_bss_85298[4];
struct fn_1_1049E0_sub fzgx_obj_lbl_1_bss_854B8;
s32 fzgx_obj_lbl_1_bss_854C8;
u32 fzgx_obj_lbl_1_bss_854CC[210];
ARQRequest fzgx_obj_lbl_1_bss_85814;
u32 fzgx_obj_lbl_1_bss_85834[210];

#pragma section code_type ".fzgxpool"
/* Fixes the .bss emission order. */
void fzgx_bss_fn_1_1049E0(u32 *o) {
    o[0] = fzgx_obj_lbl_1_bss_85280;
    o[10] = fzgx_obj_lbl_1_bss_85284;
    o[1] = fzgx_obj_lbl_1_bss_85288[0];
    o[2] = *(u32 *)&fzgx_obj_lbl_1_bss_85290;
    o[3] = fzgx_obj_lbl_1_bss_85294;
    o[4] = fzgx_obj_lbl_1_bss_85298[0].unk_7C;
    o[5] = fzgx_obj_lbl_1_bss_854B8.unk_C;
    o[6] = fzgx_obj_lbl_1_bss_854C8;
    o[7] = fzgx_obj_lbl_1_bss_854CC[0];
    o[8] = fzgx_obj_lbl_1_bss_85814.length;
    o[9] = fzgx_obj_lbl_1_bss_85834[0];
}
#pragma section code_type ".text"

void fn_1_1049E0(void *arg0, f32 arg1) {
    s32 count;
    struct fn_1_1049E0_record *rec;
    struct { s32 value; } i;
    s32 count2;
    s32 j;
    u8 phase;
    s32 elapsed, span, rest;
    s16 t11;
    u16 frame;
    u16 now;

    frame = *(u16 *)arg0;
    fzgx_obj_lbl_1_bss_854B8.unk_C = frame;
    if (frame == 420) {
        u32 seed = lbl_801A63C0.unk_0 * 0x676A4B6B + 0x33CB;
        lbl_801A63C0.unk_0 = seed;
        fzgx_obj_lbl_1_bss_85294 = (seed >> 16) & 0x7FFF;
        count = fn_1_58C4();
        for (i.value = 0; i.value < count; i.value++) {
            rec = &fzgx_obj_lbl_1_bss_85298[i.value];
            if ((s16)fn_1_6514(i.value) == 1) {
                fn_1_104730(i.value, 1);
                fn_1_5948(i.value);
                switch (fzgx_obj_lbl_1_bss_85294 % 2) {
                case 0:
                    rec->unk_82 = 600;
                    rec->unk_84 = 0;
                    rec->unk_86 = 0;
                    break;
                case 1:
                default:
                    rec->unk_82 = 0;
                    rec->unk_84 = 0;
                    rec->unk_86 = 0;
                    break;
                }
                rec->unk_78 = -20.0f;
                { struct VecWords { u32 a, b, c; };
                  *(struct VecWords *)&rec->pos = *(struct VecWords *)&rec->start; }
                rec->unk_7F = 0;
                fn_1_627C(i.value);
            }
        }
    }
    count2 = fn_1_58C4();
    for (j = 0; j < count2; j++) {
        s32 bounds[5] = { 420, 360, 300, 40, 0 };
        rec = &fzgx_obj_lbl_1_bss_85298[j];
        if (rec->unk_7F == 0 && (s16)fn_1_6514(j) == 1 && fn_1_F2F34() == 0) {
            now = *(u16 *)arg0;
            for (phase = 0; phase < 5; phase++) {
                if (now > bounds[phase]) break;
            }
            fn_1_5948(j);
            if ((fn_1_864E8(camera_get_mode()) & 0x8000) == 0) {
                if ((lbl_1_bss_3C30.unk_0 & 0x100) != 0 && fn_1_3F0C8() == 40)
                    fn_1_104730(j, 1);
                else
                    fn_1_104730(j, 0);
            }
            fn_1_627C(j);
            span = bounds[phase - 1] - bounds[phase];
            elapsed = *(u16 *)arg0 - bounds[phase];
            rest = span - elapsed;
            switch (phase) {
            case 1:
                rec->pos[0] = ((f32)(rec->start[0] * (f32)elapsed) + (f32)(rec->middle[0] * (f32)rest)) / (f32)span;
                rec->pos[1] = ((f32)(rec->start[1] * (f32)elapsed) + (f32)(rec->middle[1] * (f32)rest)) / (f32)span;
                rec->pos[2] = ((f32)(rec->start[2] * (f32)elapsed) + (f32)(rec->middle[2] * (f32)rest)) / (f32)span;
                rec->unk_80 = rec->unk_82 * elapsed + (elapsed * (rec->unk_84 * elapsed)) / 2 + (elapsed * (elapsed * (rec->unk_86 * elapsed))) / 6;
                break;
            case 2:
                rec->pos[0] = rec->middle[0];
                rec->pos[1] = rec->middle[1];
                rec->pos[2] = rec->middle[2];
                rec->unk_78 = ((f32)(-20.0f * (f32)elapsed) + (f32)(15.0f * (f32)rest)) / (f32)span;
                if (lbl_1_bss_6F239 == 0) {
                    fn_1_A2D84(0xA9091800);
                    lbl_1_bss_6F239 = 1;
                }
                break;
            case 3:
                rec->pos[0] = rec->middle[0];
                rec->pos[1] = rec->middle[1];
                rec->pos[2] = rec->middle[2];
                break;
            case 4:
                rec->pos[0] = ((f32)(rec->middle[0] * (f32)elapsed) + (f32)(rec->end[0] * (f32)rest)) / (f32)span;
                rec->pos[1] = ((f32)(rec->middle[1] * (f32)elapsed) + (f32)(rec->end[1] * (f32)rest)) / (f32)span;
                rec->pos[2] = ((f32)(rec->middle[2] * (f32)elapsed) + (f32)(rec->end[2] * (f32)rest)) / (f32)span;
                rec->unk_80 = rec->unk_82 * rest + (rest * (rec->unk_84 * rest)) / 2 + (rest * (rest * (rec->unk_86 * rest))) / 6;
                fn_1_A2D84(0xA9091900);
                break;
            }
            now = *(u16 *)arg0;
            rec->unk_7E = now / 60;
            rec->unk_7C = now;
            if (phase == 4) {
                fn_1_5948(j);
                lbl_8006DCA4();
                if (fn_1_54E34(rec, 5.0f) == 0) rec->unk_7F = 1;
                fn_1_627C(j);
            }
        }
    }
    if (fzgx_obj_lbl_1_bss_854C8 == 1) {
        s16 index;
        void *dest = (void *)fzgx_obj_lbl_1_bss_85284;
        t11 = 178 - (fzgx_obj_lbl_1_bss_854B8.unk_C - 60) / 2;
        index = t11 < 0 ? 0 : t11 > 209 ? 209 : t11;
        DCInvalidateRange(dest, fzgx_obj_lbl_1_bss_854CC[index]);
        ARQPostRequest(&fzgx_obj_lbl_1_bss_85814, 0, 1, 1, fzgx_obj_lbl_1_bss_85834[index],
            fzgx_obj_lbl_1_bss_85284, fzgx_obj_lbl_1_bss_854CC[index], (ARQCallback)fn_1_106D30);
    }
}
/* fzgx:end fn_1_1049E0 */

/* fzgx:begin fn_1_105724 */
// fn_1_105724: simple wrapper function calling fn_1_106B68
void fn_1_105724(void) {
    fn_1_106B68();
}
/* fzgx:end fn_1_105724 */

/* fzgx:begin fn_1_105744 */
// Reset the shared background state to its initial sentinel and zero values.
void fn_1_105744(void) {
    lbl_1_bss_854B8.unk_C = -1;
    lbl_1_bss_854B8.unk_0 = 0;
    lbl_1_bss_854B8.unk_4 = 0;
    lbl_1_bss_854B8.unk_8 = 0;
}
/* fzgx:end fn_1_105744 */

/* fzgx:begin fn_1_105768 */
// fn_1_105768: empty in retail (single blr).
void fn_1_105768(void) {
}
/* fzgx:end fn_1_105768 */

/* fzgx:begin fn_1_10576C */
extern f32 lbl_1_rodata_78E8[19];
extern void fn_1_103B00();
extern f32 lbl_1_rodata_7934[11];
extern void fn_1_9E5B8(void *);
extern void *fn_1_54448(s32 arg0);
extern void fn_1_103FCC(void);
extern void fn_1_10688C(void);
extern void fn_1_106B68(void);
extern s32 fn_1_5910(void);
extern f32 lbl_1_rodata_7960[43];
extern f32 lbl_1_rodata_7A40[2];
extern s32 fn_1_58C4(void);
extern void lbl_8006DCA4(void);
extern void fn_1_57714(s32 arg0);
extern void fn_1_57720(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_1_57CD0(s32 arg0, void *arg1);
extern u8 lbl_1_bss_86EC4;
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_1088B8(void *arg);
extern void lbl_8006DBAC(void *arg);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void fn_1_107F74(void *arg0, int arg1);
extern u32 lbl_801A6410;
extern u32 lbl_1_data_3F284[2];
extern s32 OSIsThreadTerminated(void *arg0);
extern void OSCancelThread(void *arg0);
extern void fn_1_46B4(s32 arg0, s32 arg1, u8 *arg2, s32 arg3);
extern void fn_1_469BC(void);
extern void fn_1_466B0(s32 arg0, s32 arg1);
extern u32 lbl_1_bss_85288[2];

struct Table10576C { u32 a[10]; };
struct fn_1_10576C_lbl_1_rodata_78D0 {
    u8 pad_0[0x38];
    f32 unk_38;
    u8 pad_3C[0xD4];
    struct Table10576C table;
    f32 unk_138;
};
extern s16 camera_get_mode(void);
extern s16 fn_1_3F0C8(void);
extern s32 fn_1_58C4(void);
extern struct fn_1_10576C_lbl_1_rodata_78D0 lbl_1_rodata_78D0;
extern u32 fn_1_86244(void);
extern u32 lbl_1_bss_38460[21];
extern u8 fn_1_3F114(void);
extern void *fn_1_8627C(s32);

void fn_1_10576C(void) {
    Obj_1_bss_854B8_At8 *v22;
    struct fn_1_10576C_lbl_1_rodata_78D0 *p_lbl_1_rodata_78D0;
    Obj_1_bss_854B8 *p_lbl_1_bss_854B8;
    Obj_1_bss_854B8_At4 *v1;
    s32 v0;
    void *v7;
    u32 v8;
    u32 v9;
    s32 v5;
    u32 v10;
    s32 i;
    u32 v4;
    u32 v12;
    u32 v13;
    s32 v11;
    u32 v21;
    struct Table10576C loc_8;
    f32 v2;
    f32 v3;

    p_lbl_1_rodata_78D0 = (struct fn_1_10576C_lbl_1_rodata_78D0 *)&lbl_1_rodata_78D0;
    v0 = camera_get_mode();
    p_lbl_1_bss_854B8 = (Obj_1_bss_854B8 *)&lbl_1_bss_854B8;
    v1 = p_lbl_1_bss_854B8->unk_4;
    if (v1 != 0) {
        if (fn_1_3F0C8() == 39) {
            v2 = p_lbl_1_rodata_78D0->unk_138;
            *(f32 *)*(u32 *)((u8 *)v1->unk_34 + 4) = v2;
            *(f32 *)((u8 *)*(u32 *)((u8 *)v1->unk_34 + 4) + 4) = v2;
        } else {
            v3 = p_lbl_1_rodata_78D0->unk_38;
            *(f32 *)*(u32 *)((u8 *)v1->unk_34 + 4) = v3;
            *(f32 *)((u8 *)*(u32 *)((u8 *)v1->unk_34 + 4) + 4) = v3;
        }
    }
    if (fn_1_86244() != 0) {
        if (v0 == -1 || v0 < 0) v0 = 0;
        v7 = fn_1_8627C(v0);
        if (v7 != 0) {
            v1 = p_lbl_1_bss_854B8->unk_4;
            if (v1 != 0) {
                v8 = *(u32 *)((u8 *)*(u32 *)((u8 *)v1->unk_8 + 8) + 8);
                v9 = v8 + 64;
                if ((s32)fn_1_3F114() - 1 <= *(s32 *)((u8 *)v7 + 284) && fn_1_3F114() != 0)
                    v10 = *(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_38460[2] + 8) + 96);
                else
                    v10 = *(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_38460[2] + 8) + 88);
                v4 = *(u32 *)((u8 *)v10 + 36);
                i = 0;
                while (i < *(u16 *)((u8 *)v8 + 24)) {
                    if (*(u8 *)((u8 *)v9 + 13) == 1) *(u32 *)((u8 *)v9 + 8) = v4;
                    v9 += 32;
                    i++;
                }
            }
            v5 = lbl_1_bss_854B8.unk_0;
            if ((u32)v5 != 0) {
                v12 = *(u32 *)((u8 *)*(u32 *)((u8 *)*(u32 *)((u8 *)v5 + 8) + 8) + 8);
                v13 = v12 + 64;
                loc_8 = p_lbl_1_rodata_78D0->table;
                if (fn_1_3F114() >= 1) {
                    if ((s32)(fn_1_3F114() - *(s32 *)((u8 *)v7 + 284) - 1) < 0) v21 = 0;
                    else if ((u32)(fn_1_3F114() - *(s32 *)((u8 *)v7 + 284) - 1) > 9) v21 = 9;
                    else v21 = fn_1_3F114() - *(s32 *)((u8 *)v7 + 284) - 1;
                    v21 = loc_8.a[v21];
                } else v21 = loc_8.a[9];
                v10 = *(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_38460[2] + 8) + (v21 << 3));
                v10 = *(u32 *)((u8 *)v10 + 36);
                v11 = 0;
                while (v11 < *(u16 *)((u8 *)v12 + 24)) {
                    if (*(u8 *)((u8 *)v13 + 13) == 1) *(u32 *)((u8 *)v13 + 8) = v10;
                    v13 += 32;
                    v11++;
                }
            }
            v22 = lbl_1_bss_854B8.unk_8;
            if (v22 != 0 && (v22->unk_0 & 0x80000000) == 0) {
                if (*(s32 *)((u8 *)v7 + 284) == 0 || (u32)fn_1_58C4() != 1) v22->unk_0 |= 0x80000000;
                if (lbl_1_bss_854B8.unk_C <= 22) v22->unk_18 = 16384;
                else if (lbl_1_bss_854B8.unk_C <= 60) v22->unk_18 = ((60 - lbl_1_bss_854B8.unk_C) << 14) / 38;
                else v22->unk_18 = 0;
            }
        }
    }
}
/* fzgx:end fn_1_10576C */

/* fzgx:begin fn_1_105AB8 noprologue */
#include "types.h"

extern u32 fn_1_58C4(void);
extern u32 lbl_1_rodata_7A0C[1];
extern u32 lbl_1_rodata_7A10;
extern void fn_1_105BD8(u32, u32 *, u32 *, u32 *, u32 *);
extern void fn_1_105CC8(u8 *, u8 *, u32 *, u32 *, u32 *, u32 *, u32 *, u32 *);

typedef struct {
    u32 word[3];
} Work;

void fn_1_105AB8(u8 *base, s32 value) {
    u32 limit;
    s32 count;
    u8 *entry;
    u8 *other;
    s32 i;
    Work w1;
    Work w2;
    Work w3;
    Work w4;
    u32 pool;
    u32 arg;
    u32 high;

    fn_1_58C4();
    limit = 0x400 / fn_1_58C4();
    if (0x200 / fn_1_58C4() > limit) {
        limit = 0x400 / fn_1_58C4();
    } else {
        limit = 0x200 / fn_1_58C4();
    }

    *(u32 *)(base + 0xC000) = limit;
    *(u32 *)(base + 0xC004) = (*((0) + (lbl_1_rodata_7A0C)));
    *(u32 *)(base + 0xC008) = lbl_1_rodata_7A10;

    i = value * *(s32 *)(base + 0xC000);
    other = base + i * 32;
    entry = base + i * 16;
    while (i < (value + 1) * *(s32 *)(base + 0xC000)) {
        fn_1_105BD8(value, &w1.word[0], &w2.word[0], &w3.word[0], &w4.word[0]);
        arg = *(u32 *)(base + 0xC008);
        pool = *(u32 *)(base + 0xC004);
        fn_1_105CC8(entry, other + 0x4000, &pool, &arg, &w1.word[0],
                    &w2.word[0], &w3.word[0], &w4.word[0]);
        other += 0x20;
        entry += 0x10;
        i++;
    }
}
/* fzgx:end fn_1_105AB8 */

/* fzgx:begin fn_1_105BD8 noprologue */
#include "types.h"
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

extern void fn_1_681C(u8);
extern void fn_1_6914(u8, u32 *);
extern void fn_1_6990(u8, u32 *);
extern s32 camera_get_state(void);
extern f32 lbl_1_rodata_78E8[19];
extern f32 lbl_1_rodata_78E0[2];
extern f32 lbl_8006D668(u32 *);

#pragma opt_propagation off
#pragma opt_strength_reduction off
static inline f32 fn_1_105BD8_operand(f32 right, f32 left) { left *= right; return left; }
#pragma opt_common_subs off
void fn_1_105BD8(u32 id, u32 *a, u32 *b, u32 *c, u32 *d) {
    f64 one;
    fn_1_681C((u8)id);
    fn_1_6914((u8)id, c);
    fn_1_6990((u8)id, b);
    if ((s8)camera_get_state() == 9) {
        f32 zero = (*((lbl_1_rodata_78E8) + (0)));
        one = (*((lbl_1_rodata_78E0) + (0)));
        ((f32 *)b)[0] = zero;
        ((f32 *)b)[1] = one;
        ((f32 *)b)[2] = zero;
    }
    psvec_sub(c, a, c);
    lbl_8006D668(c);
    {
        f32 bz;
        f32 bx;
        f32 cz;
        f32 cy;
        f32 cx;
        f32 x;
        f32 y;
        f32 z;
        cy = ((Vec3 *)c)->y;
        bz = ((Vec3 *)b)->z;
        cz = ((Vec3 *)c)->z;
        bx = ((Vec3 *)b)->x;
        cx = ((Vec3 *)c)->x;
        x = (f32)(fn_1_105BD8_operand((bz), (cy))) - cz * ((Vec3 *)b)->y;
        y = (f32)(((cz) * (bx))) - cx * bz;
        z = (f32)(cx * ((Vec3 *)b)->y) - cy * bx;
        ((Vec3 *)d)->x = x;
        ((Vec3 *)d)->y = y;
        ((Vec3 *)d)->z = z;
    }
}
#pragma opt_common_subs reset

#pragma opt_strength_reduction reset

#pragma opt_propagation reset
/* fzgx:end fn_1_105BD8 */

/* fzgx:begin fn_1_1067A8 */
void fn_1_1067A8(void *arg0, f32 arg1, f32 arg2) {
    s32 result;
    s32 value;
    s32 count;
    s32 stride;
    u8 *base;
    f32 scale;
    f32 offset;

    scale = arg1;
    offset = arg2;
    result = fn_1_5910();

    value = (s32)(lbl_1_rodata_7960[0] * scale / offset + lbl_1_rodata_7A40[0]);
    count = fn_1_58C4();
    if (count <= 2) {
        lbl_8006DCA4();
        fn_1_57714(value);
        fn_1_57720(1, 4, 5, 0);
        base = (u8 *)arg0;
        stride = *(s32 *)(base + 0xC000);
        fn_1_57CD0((stride & 0x7FFF) << 1, base + (result * stride << 5) + 0x4000);
        fn_1_57714(6);
    }
}
/* fzgx:end fn_1_1067A8 */

/* fzgx:begin fn_1_106B68 */
void fn_1_106B68(void) {
    u32 *data;
    Obj_1_bss_85280 *base;
    s32 i;

    base = &lbl_1_bss_85280;
    *(s32 *)((u8 *)base + 0x248) = 2;
    if (OSIsThreadTerminated((u8 *)base + 0x918) == 0) {
        OSCancelThread((u8 *)base + 0x918);
    }

    data = lbl_1_data_3F284;
    fn_1_46B4(lbl_801A6410, data[1], (*(u8 (*)[12])&lbl_1_data_3F34C), 0x8a5);
    fn_1_46B4(lbl_801A6410, data[0], (*(u8 (*)[12])&lbl_1_data_3F34C), 0x8a6);

    data[1] = 0;
    data[0] = 0;
    fn_1_46B4(lbl_801A6410, base->unk_0, (*(u8 (*)[12])&lbl_1_data_3F34C), 0x8a9);

    base->unk_0 = 0;
    fn_1_46B4(lbl_801A6410, base->unk_4, (*(u8 (*)[12])&lbl_1_data_3F34C), 0x8ab);
    base->unk_4 = 0;
    fn_1_469BC();

    i = 0;
    data = (u32 *)((u8 *)base + 0x5b4);
    for (; i < 0xd2; i++) {
        fn_1_466B0(*data, 1);
        data++;
    }
    fn_1_466B0(*(s32 *)((u8 *)base + 0x8fc), 1);
}
/* fzgx:end fn_1_106B68 */

/* fzgx:begin fn_1_106DB4 */
s32 fn_1_106DB4(u32 arg0, u32 arg1) {
    volatile u32 *counter;  /* fzgx: count is re-read after each store in the retail loop */
    u8 *entry;

    switch (arg0) {
    case 0:
        *(u32 *)arg1 |= 0x08000000;
        break;
    case 1:
        lbl_1_bss_854B8.unk_0 = arg1;
        break;
    case 2:
        lbl_1_bss_854B8.unk_4 = (Obj_1_bss_854B8_At4 *)arg1;
        break;
    case 3:
        lbl_1_bss_854B8.unk_8 = (Obj_1_bss_854B8_At8 *)arg1;
        ((Obj_1_bss_3BE0_Target *)arg1)->unk_3C = 0;
        *(u32 *)arg1 &= 0x7FFFFFFF;
        break;
    case 4:
        counter = &lbl_1_bss_85288[0];
        entry = (u8 *)lbl_1_bss_3BE0->unk_54;
        *counter = 0;
        while ((u32)entry != arg1) {
            entry += 0x40;
            *counter = *counter + 1;
        }
        break;
    case 5:
        counter = &lbl_1_bss_85288[1];
        entry = (u8 *)lbl_1_bss_3BE0->unk_54;
        *counter = 0;
        while ((u32)entry != arg1) {
            entry += 0x40;
            *counter = *counter + 1;
        }
        break;
    case 6:
        break;
    }
    return 1;
}
/* fzgx:end fn_1_106DB4 */

/* fzgx:begin fn_1_106EA4 */
void fn_1_106EA4(f32 arg0) {
    lbl_1_bss_85290 = arg0;
}
/* fzgx:end fn_1_106EA4 */

/* fzgx:begin fn_1_1071C0 */
void fn_1_1071C0(void) {
    if (lbl_1_bss_86EC4 != 0) {
        lbl_1_bss_86EC4 = 0;
        lbl_1_bss_86EC0 = 0;
    }
}
/* fzgx:end fn_1_1071C0 */

/* fzgx:begin fn_1_10780C noprologue */
#include "types.h"
#include "psvec.h"

extern f32 lbl_8006D668(u32 *);
extern u16 lbl_1_bss_86ECC;
extern u32 fn_1_1071E8(u8 *, u32, void *, void *, void *);
extern u8 *fn_1_14F04(void);

void fn_1_10780C(void *arg0, void *arg1, u32 *arg2, void *arg3) {
    u8 *t0;
    struct { u32 a[3]; } loc_14;
    u32 loc_8[3];
    s32 v1;
    s32 v0;
    t0 = fn_1_14F04();
    v0 = lbl_1_bss_86ECC - 1;
    v0 = v0 < 0 ? 511 : v0;
    fn_1_1071E8(t0, v0, &loc_14, 0, 0);
    v1 = lbl_1_bss_86ECC + 1;
    fn_1_1071E8(t0, v1 < 512 ? v1 : 0, loc_8, 0, 0);
    psvec_sub(loc_8, &loc_14, arg2);
    lbl_8006D668(arg2);
    fn_1_1071E8(t0, lbl_1_bss_86ECC, arg0, arg1, arg3);
}
/* fzgx:end fn_1_10780C */

/* fzgx:begin fn_1_107900 */
void fn_1_107900(void) {
    fn_80008BEC(&lbl_1_bss_86ED0, 0, 0x1c70);
}
/* fzgx:end fn_1_107900 */

/* fzgx:begin fn_1_107930 */
extern f32 lbl_1_rodata_78E8[19];
extern void fn_1_103B00();
extern f32 lbl_1_rodata_7934[11];
extern void fn_1_9E5B8(void *);
extern void *fn_1_54448(s32 arg0);
extern void fn_1_103FCC(void);
extern void fn_1_10688C(void);
extern void fn_1_106B68(void);
extern s32 fn_1_5910(void);
extern f32 lbl_1_rodata_7960[43];
extern f32 lbl_1_rodata_7A40[2];
extern s32 fn_1_58C4(void);
extern void lbl_8006DCA4(void);
extern void fn_1_57714(s32 arg0);
extern void fn_1_57720(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_1_57CD0(s32 arg0, void *arg1);
extern u8 lbl_1_bss_86EC4;
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_1088B8(void *arg);
extern void lbl_8006DBAC(void *arg);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void fn_1_107F74(void *arg0, int arg1);
extern u32 lbl_801A6410;
extern u32 lbl_1_data_3F284[2];
extern s32 OSIsThreadTerminated(void *arg0);
extern void OSCancelThread(void *arg0);
extern void fn_1_46B4(s32 arg0, s32 arg1, u8 *arg2, s32 arg3);
extern void fn_1_469BC(void);
extern void fn_1_466B0(s32 arg0, s32 arg1);
extern u32 lbl_1_bss_85288[2];

typedef struct {
    u8 pad_0[0xc];
    u32 unk_c;
    u8 pad_10[0x58];
} Sig_fn_1_108870_fn_1_108870_AccessoryEntry;
typedef u32 (*fn_1_107930_Fn0)(u32);
struct fn_1_107930_lbl_1_data_3F510 {
    u8 pad_0[0x650];
    char unk_650[0x10];
    char unk_660[0x10];
    char unk_670[0x12c];
    const char *unk_79C[98];
    u32 unk_924[221];
    fn_1_107930_Fn0 unk_C98[196];
    u32 unk_FA8;
    const char *unk_FAC[19];
    u32 unk_FF8;
    u8 unk_FFC[8];
    char unk_1004[8];
};
typedef struct { void *unk_0; const char *unk_4; } fn_1_107930_Entry;
typedef struct { u32 unk_0; u32 unk_4; fn_1_107930_Entry *unk_8; } fn_1_107930_List;
typedef struct {
    u8 pad_0[0x88];
    s32 unk_88;
    s32 unk_8C;
    u8 pad_90[0x54];
    fn_1_107930_List *unk_E4[3];
} fn_1_107930_Object;
struct fn_1_107930_lbl_1_rodata_7AB8 { u32 unk_0, unk_4, unk_8; };
extern Sig_fn_1_108870_fn_1_108870_AccessoryEntry *fn_1_108870(void);
extern int fn_80083BCC(const char *, const char *);
extern int sprintf(char *, const char *, ...);
extern f32 lbl_1_rodata_7AB8[9];
extern u32 lbl_1_bss_88B40[3];
extern u8 *fn_80083970(u8 *, const u8 *);

#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_1_107930(fn_1_107930_Object *arg) {
    u8 *p_lbl_1_data_3F510;
    Obj_1_bss_8B3A0 *p_lbl_1_bss_8B3A0;
    u32 v17;
    u32 v8;
    fn_1_107930_List *v1;
    void *v19;
    const char **v16;
    void *v25;
    u32 *v15;
    const char **v12;
    fn_1_107930_Entry *v7;
    fn_1_107930_Object *arg0 = arg;
    u32 *v22;
    s32 v9;
    u32 v20;
    s32 v18;
    u32 v11;
    u32 v24;
    fn_1_107930_Entry *v23;
    s32 v5;
    u32 *v4;
    u32 v3;
    Sig_fn_1_108870_fn_1_108870_AccessoryEntry *v0;
    struct { u32 a[64]; } loc_8;

    p_lbl_1_data_3F510 = lbl_1_data_3F510;
    if (!arg0) return;
    if (arg0->unk_8C != 0 && (u32)(arg0->unk_8C - 1) > 1) return;
    v1 = arg0->unk_E4[arg0->unk_8C];
    if (!v1) return;
    {
        u32 v6 = *(u32 *)(p_lbl_1_data_3F510 + 0xFA8);
        v4 = (u32 *)(p_lbl_1_data_3F510 + 0x924);
        v5 = 1;
        for (v3 = 0; v3 < v6; v4++, v3++) {
            if (arg0->unk_88 == (s32)*v4) {
                v5 = 0;
                break;
            }
        }
    }
    if (v5) return;
    p_lbl_1_bss_8B3A0 = &lbl_1_bss_8B3A0;
    v7 = v1->unk_8;
    for (v8 = 0; v8 < v1->unk_0; v8++, v7++) {
        if (!v7) continue;
        if (!fn_80083970((u8 *)v7->unk_4, p_lbl_1_data_3F510 + 0xFFC)) continue;
        if (fn_80083BCC(v7->unk_4, (char *)(p_lbl_1_data_3F510 + 0x650)) == 0 &&
            *(s16 *)&lbl_1_bss_960 == 1 && p_lbl_1_bss_8B3A0->unk_4 == 4) continue;
        if (fn_80083BCC(v7->unk_4, (char *)(p_lbl_1_data_3F510 + 0x660)) == 0 &&
            *(s16 *)&lbl_1_bss_960 == 1 && p_lbl_1_bss_8B3A0->unk_4 == 4) continue;
        if (fn_80083BCC(v7->unk_4, (char *)(p_lbl_1_data_3F510 + 0x670)) == 0 &&
            *(s16 *)&lbl_1_bss_960 == 1 && p_lbl_1_bss_8B3A0->unk_4 == 4) continue;
        if (arg0->unk_8C == 2) {
            v25 = p_lbl_1_data_3F510 + 0xFAC;
            v9 = 0;
            for (v11 = 0; v11 < *(u32 *)(p_lbl_1_data_3F510 + 0xFF8); v25 = (u8 *)v25 + 4, v11++) {
                if (fn_80083BCC(v7->unk_4, *(const char **)v25) == 0) v9 = 1;
            }
        } else v9 = 1;
        if (!v9) continue;
        v25 = p_lbl_1_data_3F510 + 0x924;
        v19 = p_lbl_1_data_3F510 + 0x79C;
        v18 = 1;
        for (v17 = 0; v17 < *(u32 *)(p_lbl_1_data_3F510 + 0xFA8);
             v25 = (u8 *)v25 + 4, v19 = (u8 *)v19 + 4, v17++) {
            if (arg0->unk_88 == *(s32 *)v25 &&
                fn_80083BCC(v7->unk_4, *(const char **)v19) == 0) {
                v18 = 0;
                break;
            }
        }
        if (v18) continue;
        v19 = v7->unk_0;
        if (!v19) continue;
        v20 = v17 << 2;
        v16 = (const char **)(p_lbl_1_data_3F510 + 0x79C);
        {
            const char *v21 = *(const char **)((u8 *)v16 + v20);
            v25 = 0;
            sprintf((char *)&loc_8, (char *)(p_lbl_1_data_3F510 + 0x1004), v21);
        }
        v23 = v1->unk_8;
        v22 = (u32 *)(p_lbl_1_data_3F510 + 0x924);
        for (v24 = 0; v24 < v1->unk_0; v24++, v23++) {
            if (arg0->unk_88 == *(s32 *)((u8 *)v22 + v20) &&
                fn_80083BCC(v23->unk_4, (char *)&loc_8) == 0) {
                v25 = v23->unk_0;
                break;
            }
        }
        v0 = fn_1_108870();
        if (v0) {
            *(u32 *)((u8 *)v0 + 8) = v17;
            v0->unk_c = (u32)arg0;
            *(void **)((u8 *)v0 + 0x10) = v19;
            v0->pad_0[0] = 2;
            *(void **)((u8 *)v0 + 0x30) = v25;
            *(s32 *)((u8 *)v0 + 4) = arg0->unk_8C;
        }
        {
            fn_1_107930_Fn0 *v26 = (fn_1_107930_Fn0 *)(p_lbl_1_data_3F510 + 0xC98);
            v26[*(u32 *)((u8 *)v0 + 8)]((u32)v0);
        }
    }
    *(struct fn_1_107930_lbl_1_rodata_7AB8 *)lbl_1_bss_88B40 =
        *(struct fn_1_107930_lbl_1_rodata_7AB8 *)lbl_1_rodata_7AB8;
}
#pragma opt_lifetimes reset
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_107930 */

/* fzgx:begin fn_1_107C4C */
void fn_1_107C4C(void *arg) {
    if (arg != 0) {
        fn_1_1088B8(arg);
    }
}
/* fzgx:end fn_1_107C4C */

/* fzgx:begin fn_1_107C74 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_common.h"
#include "types.h"
#include "rel/main_rel/bg_common.h"

extern f32 lbl_1_rodata_78E8[19];
extern void fn_1_103B00();
extern f32 lbl_1_rodata_7934[11];
extern void fn_1_9E5B8(void *);
extern void *fn_1_54448(s32 arg0);
extern void fn_1_103FCC(void);
extern void fn_1_10688C(void);
extern void fn_1_106B68(void);
extern s32 fn_1_5910(void);
extern f32 lbl_1_rodata_7960[43];
extern f32 lbl_1_rodata_7A40[2];
extern s32 fn_1_58C4(void);
extern void lbl_8006DCA4(void);
extern void fn_1_57714(s32 arg0);
extern void fn_1_57720(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_1_57CD0(s32 arg0, void *arg1);
extern u8 lbl_1_bss_86EC4;
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_1088B8(void *arg);
extern void lbl_8006DBAC(void *arg);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void fn_1_107F74(void *arg0, int arg1);
extern u32 lbl_801A6410;
extern u32 lbl_1_data_3F284[2];
extern s32 OSIsThreadTerminated(void *arg0);
extern void OSCancelThread(void *arg0);
extern void fn_1_46B4(s32 arg0, s32 arg1, u8 *arg2, s32 arg3);
extern void fn_1_469BC(void);
extern void fn_1_466B0(s32 arg0, s32 arg1);
extern u32 lbl_1_bss_85288[2];


typedef struct {
    f32 x, y, z;
} BgVec;

typedef struct {
    u8 pad_0[0x48];
    f32 unk_48;
    f32 unk_4C;
} BgRange;

typedef struct {
    u8 pad_0[0x8];
    u8 *unk_8;
} BgModel;

typedef struct {
    u8 pad_0[0x8C];
    s32 unk_8C;
    s32 unk_90;
    u8 pad_94[0xBC];
    BgModel *unk_150;
} BgOwner;

typedef struct BgEntry BgEntry;
typedef void (*BgEntryFn)(BgEntry *);

struct BgEntry {
    u8 pad_0[0x8];
    u32 unk_8;
    BgOwner *unk_C;
    u8 pad_10[0x24];
    BgVec unk_34;
    u8 pad_40[0x28];
};

typedef struct {
    u8 pad_0[0xC];
    BgVec unk_C;
    f64 unk_18;
    f32 unk_20;
} BgPool;

typedef struct {
    u8 pad_0[0xAAC];
    u32 unk_AAC[0x62];
    u8 unk_C34[0x1EC];
    BgEntryFn unk_E20[1];
} BgData;

extern u32 lbl_1_bss_88B4C;
extern f64 __fabs(f64);
extern void fn_1_1088B8(void *arg);
extern void fn_1_107930(void *arg);
extern void fn_1_107E90(void *arg);
extern void lbl_8006DBAC(void *arg);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void lbl_8006DD14(void *arg0, void *arg1);

extern u8 fn_1_1091D4__fzgx_offset_0[];
extern u8 fn_1_10976C__fzgx_offset_0[];
extern u8 fn_1_10A43C__fzgx_offset_0[];
extern u8 fn_1_10A6A0__fzgx_offset_0[];
extern u8 fn_1_10A8D0__fzgx_offset_0[];
extern u8 fn_1_10AD18__fzgx_offset_0[];
extern u8 fn_1_10B344__fzgx_offset_0[];
extern u8 fn_1_10B5A8__fzgx_offset_0[];
extern u8 fn_1_10B7D8__fzgx_offset_0[];
extern u8 fn_1_10B800__fzgx_offset_0[];
extern u8 fn_1_10BA00__fzgx_offset_0[];
extern u8 fn_1_10BE3C__fzgx_offset_0[];
extern u8 fn_1_10C4E4__fzgx_offset_0[];
extern u8 fn_1_10C7B4__fzgx_offset_0[];
extern u8 fn_1_10C9B0__fzgx_offset_0[];
extern u8 fn_1_10CC38__fzgx_offset_0[];
extern u8 fn_1_10D2F0__fzgx_offset_0[];
extern u8 fn_1_10D7D4__fzgx_offset_0[];
extern u8 fn_1_10DDE4__fzgx_offset_0[];
extern u8 fn_1_10E3B4__fzgx_offset_0[];
extern u8 fn_1_110008__fzgx_offset_0[];
extern u8 fn_1_110478__fzgx_offset_0[];
extern u8 fn_1_111510__fzgx_offset_0[];
extern u8 fn_1_111980__fzgx_offset_0[];
extern u8 fn_1_112F40__fzgx_offset_0[];
extern u8 fn_1_1132E4__fzgx_offset_0[];
extern u8 fn_1_1137E4__fzgx_offset_0[];
extern u8 fn_1_113C58__fzgx_offset_0[];
extern u8 fn_1_1145C8__fzgx_offset_0[];
extern u8 fn_1_11492C__fzgx_offset_0[];
extern u8 fn_1_1154D0__fzgx_offset_0[];
extern u8 fn_1_115560__fzgx_offset_0[];
extern u8 fn_1_115B58__fzgx_offset_0[];
extern u8 fn_1_115BE8__fzgx_offset_0[];
extern u8 fn_1_1166EC__fzgx_offset_0[];
extern u8 fn_1_11677C__fzgx_offset_0[];
extern u8 fn_1_1171B8__fzgx_offset_0[];
extern u8 fn_1_117424__fzgx_offset_0[];
extern u8 fn_1_1177C4__fzgx_offset_0[];
extern u8 fn_1_117D5C__fzgx_offset_0[];
extern u8 fn_1_1185B4__fzgx_offset_0[];
extern u8 fn_1_1188CC__fzgx_offset_0[];
extern u8 fn_1_118D90__fzgx_offset_0[];
extern u8 fn_1_1192D0__fzgx_offset_0[];
extern u8 fn_1_11A158__fzgx_offset_0[];
extern u8 fn_1_11A774__fzgx_offset_0[];
extern u8 fn_1_11B4E4__fzgx_offset_0[];
extern u8 fn_1_11B958__fzgx_offset_0[];
extern u8 fn_1_11BFCC__fzgx_offset_0[];
extern u8 fn_1_11C440__fzgx_offset_0[];
extern u8 fn_1_11CAB4__fzgx_offset_0[];
extern u8 fn_1_11CD3C__fzgx_offset_0[];
extern u8 fn_1_11D1FC__fzgx_offset_0[];
extern u8 fn_1_11DE2C__fzgx_offset_0[];
extern u8 fn_1_11ED0C__fzgx_offset_0[];
extern u8 fn_1_11F250__fzgx_offset_0[];
extern u8 fn_1_1201E4__fzgx_offset_0[];
extern u8 fn_1_120804__fzgx_offset_0[];
extern u8 fn_1_122348__fzgx_offset_0[];
extern u8 fn_1_12277C__fzgx_offset_0[];
extern u8 fn_1_12295C__fzgx_offset_0[];
extern u8 fn_1_123050__fzgx_offset_0[];
extern u8 fn_1_1244F0__fzgx_offset_0[];
extern u8 fn_1_124AD4__fzgx_offset_0[];
extern u8 fn_1_1250D0__fzgx_offset_0[];
extern u8 fn_1_1256EC__fzgx_offset_0[];
extern u8 fn_1_125CE8__fzgx_offset_0[];
extern u8 fn_1_125DF0__fzgx_offset_0[];
extern u8 fn_1_1262A4__fzgx_offset_0[];
extern u8 fn_1_126774__fzgx_offset_0[];
extern u8 fn_1_126DE8__fzgx_offset_0[];
extern u8 fn_1_12744C__fzgx_offset_0[];
extern u8 fn_1_127FB8__fzgx_offset_0[];
extern u8 fn_1_128038__fzgx_offset_0[];
extern u8 lbl_1_data_3F578__fzgx_offset_0[];
extern u8 lbl_1_data_3F58C__fzgx_offset_0[];
extern u8 lbl_1_data_3F5A0__fzgx_offset_0[];
extern u8 lbl_1_data_3F5B4__fzgx_offset_0[];
extern u8 lbl_1_data_3F5C8__fzgx_offset_0[];
extern u8 lbl_1_data_3F5DC__fzgx_offset_0[];
extern u8 lbl_1_data_3F5F0__fzgx_offset_0[];
extern u8 lbl_1_data_3F604__fzgx_offset_0[];
extern u8 lbl_1_data_3F618__fzgx_offset_0[];
extern u8 lbl_1_data_3F630__fzgx_offset_0[];
extern u8 lbl_1_data_3F644__fzgx_offset_0[];
extern u8 lbl_1_data_3F658__fzgx_offset_0[];
extern u8 lbl_1_data_3F66C__fzgx_offset_0[];
extern u8 lbl_1_data_3F680__fzgx_offset_0[];
extern u8 lbl_1_data_3F694__fzgx_offset_0[];
extern u8 lbl_1_data_3F6A8__fzgx_offset_0[];
extern u8 lbl_1_data_3F6B8__fzgx_offset_0[];
extern u8 lbl_1_data_3F6C8__fzgx_offset_0[];
extern u8 lbl_1_data_3F6D8__fzgx_offset_0[];
extern u8 lbl_1_data_3F6E8__fzgx_offset_0[];
extern u8 lbl_1_data_3F6FC__fzgx_offset_0[];
extern u8 lbl_1_data_3F710__fzgx_offset_0[];
extern u8 lbl_1_data_3F724__fzgx_offset_0[];
extern u8 lbl_1_data_3F738__fzgx_offset_0[];
extern u8 lbl_1_data_3F748__fzgx_offset_0[];
extern u8 lbl_1_data_3F75C__fzgx_offset_0[];
extern u8 lbl_1_data_3F770__fzgx_offset_0[];
extern u8 lbl_1_data_3F780__fzgx_offset_0[];
extern u8 lbl_1_data_3F790__fzgx_offset_0[];
extern u8 lbl_1_data_3F7A0__fzgx_offset_0[];
extern u8 lbl_1_data_3F7B0__fzgx_offset_0[];
extern u8 lbl_1_data_3F7C0__fzgx_offset_0[];
extern u8 lbl_1_data_3F7D0__fzgx_offset_0[];
extern u8 lbl_1_data_3F7E4__fzgx_offset_0[];
extern u8 lbl_1_data_3F7F8__fzgx_offset_0[];
extern u8 lbl_1_data_3F80C__fzgx_offset_0[];
extern u8 lbl_1_data_3F820__fzgx_offset_0[];
extern u8 lbl_1_data_3F834__fzgx_offset_0[];
extern u8 lbl_1_data_3F848__fzgx_offset_0[];
extern u8 lbl_1_data_3F85C__fzgx_offset_0[];
extern u8 lbl_1_data_3F870__fzgx_offset_0[];
extern u8 lbl_1_data_3F884__fzgx_offset_0[];
extern u8 lbl_1_data_3F898__fzgx_offset_0[];
extern u8 lbl_1_data_3F8AC__fzgx_offset_0[];
extern u8 lbl_1_data_3F8C0__fzgx_offset_0[];
extern u8 lbl_1_data_3F8D4__fzgx_offset_0[];
extern u8 lbl_1_data_3F8E4__fzgx_offset_0[];
extern u8 lbl_1_data_3F8F4__fzgx_offset_0[];
extern u8 lbl_1_data_3F904__fzgx_offset_0[];
extern u8 lbl_1_data_3F918__fzgx_offset_0[];
extern u8 lbl_1_data_3F92C__fzgx_offset_0[];
extern u8 lbl_1_data_3F940__fzgx_offset_0[];
extern u8 lbl_1_data_3F954__fzgx_offset_0[];
extern u8 lbl_1_data_3F968__fzgx_offset_0[];
extern u8 lbl_1_data_3F97C__fzgx_offset_0[];
extern u8 lbl_1_data_3F990__fzgx_offset_0[];
extern u8 lbl_1_data_3F9A4__fzgx_offset_0[];
extern u8 lbl_1_data_3F9B8__fzgx_offset_0[];
extern u8 lbl_1_data_3F9CC__fzgx_offset_0[];
extern u8 lbl_1_data_3F9E0__fzgx_offset_0[];
extern u8 lbl_1_data_3F9F0__fzgx_offset_0[];
extern u8 lbl_1_data_3FA00__fzgx_offset_0[];
extern u8 lbl_1_data_3FA14__fzgx_offset_0[];
extern u8 lbl_1_data_3FA28__fzgx_offset_0[];
extern u8 lbl_1_data_3FA3C__fzgx_offset_0[];
extern u8 lbl_1_data_3FA50__fzgx_offset_0[];
extern u8 lbl_1_data_3FA64__fzgx_offset_0[];
extern u8 lbl_1_data_3FA78__fzgx_offset_0[];
extern u8 lbl_1_data_3FA88__fzgx_offset_0[];
extern u8 lbl_1_data_3FA98__fzgx_offset_0[];
extern u8 lbl_1_data_3FAAC__fzgx_offset_0[];
extern u8 lbl_1_data_3FAC0__fzgx_offset_0[];
extern u8 lbl_1_data_3FAD4__fzgx_offset_0[];
extern u8 lbl_1_data_3FAE4__fzgx_offset_0[];
extern u8 lbl_1_data_3FAF4__fzgx_offset_0[];
extern u8 lbl_1_data_3FB08__fzgx_offset_0[];
extern u8 lbl_1_data_3FB18__fzgx_offset_0[];
extern u8 lbl_1_data_3FB28__fzgx_offset_0[];
extern u8 lbl_1_data_3FB3C__fzgx_offset_0[];
extern u8 lbl_1_data_3FB50__fzgx_offset_0[];
extern u8 lbl_1_data_3FB60__fzgx_offset_0[];
extern u8 lbl_1_data_3FB70__fzgx_offset_0[];
extern u8 lbl_1_data_3FB80__fzgx_offset_0[];
extern u8 lbl_1_data_3FB90__fzgx_offset_0[];
extern u8 lbl_1_data_3FBA4__fzgx_offset_0[];
extern u8 lbl_1_data_3FBB8__fzgx_offset_0[];
extern u8 lbl_1_data_3FBCC__fzgx_offset_0[];
extern u8 lbl_1_data_3FBE0__fzgx_offset_0[];
extern u8 lbl_1_data_3FBF4__fzgx_offset_0[];
extern u8 lbl_1_data_3FC08__fzgx_offset_0[];
extern u8 lbl_1_data_3FC1C__fzgx_offset_0[];
extern u8 lbl_1_data_3FC30__fzgx_offset_0[];
extern u8 lbl_1_data_3FC44__fzgx_offset_0[];
extern u8 lbl_1_data_3FC58__fzgx_offset_0[];
extern u8 lbl_1_data_3FC68__fzgx_offset_0[];
extern u8 lbl_1_data_3FC78__fzgx_offset_0[];
extern u8 lbl_1_data_3FC88__fzgx_offset_0[];
extern u8 lbl_1_data_3FC98__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_3F510[683] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0, 0x40000000, 0xBF800000, 0xBFC00000, 0x878787FF, 0xFFFFFFFF,
    0x0, 0x0, 0x3F733333, 0x0, 0x42B40000, 0x0, 0x0, 0x0,
    0x40000000, 0xBF800000, 0x3FC00000, 0x878787FF, 0xFFFFFFFF, 0x0, 0x0, 0x3F733333,
    0x0, 0x42B40000, 0x474F5244, 0x4F4E5F4D, 0x4F4D4F5F, 0x525F7674, 0x78000000, 0x474F5244,
    0x4F4E5F4D, 0x4F4D4F5F, 0x4C5F7674, 0x78000000, 0x474F5244, 0x4F4E5F45, 0x52495F4F, 0x5F767478,
    0x0, 0x474F5244, 0x4F4E5F45, 0x52495F55, 0x5F767478, 0x0, 0x46414C43, 0x4F4E5F45,
    0x52495F4F, 0x5F767478, 0x0, 0x46414C43, 0x4F4E5F45, 0x52495F55, 0x5F767478, 0x0,
    0x46414C43, 0x4F4E5F46, 0x524F4E54, 0x5F4F5F76, 0x74780000, 0x46414C43, 0x4F4E5F46, 0x524F4E54,
    0x5F555F76, 0x74780000, 0x46414C43, 0x4F4E5F41, 0x43434553, 0x534F5259, 0x5F767478, 0x0,
    0x46414C43, 0x4F4E5F4B, 0x41544141, 0x54455F76, 0x74780000, 0x4A414D45, 0x535F4841, 0x49525F41,
    0x5F767478, 0x0, 0x4A414D45, 0x535F4841, 0x49525F42, 0x5F767478, 0x0, 0x4A414D45,
    0x535F4841, 0x49525F43, 0x5F767478, 0x0, 0x4A414D45, 0x535F4A41, 0x434B4554, 0x5F767478,
    0x0, 0x4A414D45, 0x535F4143, 0x43455353, 0x4F52595F, 0x76747800, 0x4152524F, 0x575F4D41,
    0x4E545F76, 0x74780000, 0x53484144, 0x4F575F4D, 0x414E545F, 0x76747800, 0x424F5353, 0x5F4D414E,
    0x545F7674, 0x78000000, 0x424F5353, 0x5F455249, 0x5F767478, 0x0, 0x47555354, 0x45525F4A,
    0x41434B45, 0x545F4F5F, 0x76747800, 0x47555354, 0x45525F45, 0x52495F4F, 0x5F767478, 0x0,
    0x47555354, 0x45525F45, 0x52495F55, 0x5F767478, 0x0, 0x53544557, 0x4152545F, 0x53434152,
    0x465F7674, 0x78000000, 0x474F4D41, 0x5F534341, 0x52465F76, 0x74780000, 0x474F4D41, 0x5F4B4F53,
    0x48495F52, 0x5F767478, 0x0, 0x474F4D41, 0x5F4B4F53, 0x48495F4C, 0x5F767478, 0x0,
    0x5348494F, 0x5F534341, 0x52465F76, 0x74780000, 0x5348494F, 0x5F4B4F53, 0x495F525F, 0x76747800,
    0x5348494F, 0x5F4B4F53, 0x495F4C5F, 0x76747800, 0x424C4F4F, 0x445F5343, 0x4152465F, 0x76747800,
    0x424C4F4F, 0x445F4552, 0x495F4F5F, 0x76747800, 0x424C4F4F, 0x445F4552, 0x495F555F, 0x76747800,
    0x424C4F4F, 0x445F4B41, 0x54414154, 0x455F325F, 0x76747800, 0x4A4F4459, 0x5F484149, 0x525F415F,
    0x555F7674, 0x78000000, 0x4A4F4459, 0x5F484149, 0x525F415F, 0x425F7674, 0x78000000, 0x4A4F4459,
    0x5F484149, 0x525F425F, 0x555F7674, 0x78000000, 0x4A4F4459, 0x5F484149, 0x525F425F, 0x425F7674,
    0x78000000, 0x4A4F4459, 0x5F484149, 0x525F435F, 0x555F7674, 0x78000000, 0x4A4F4459, 0x5F484149,
    0x525F435F, 0x425F7674, 0x78000000, 0x4A4F4459, 0x5F484149, 0x525F445F, 0x555F7674, 0x78000000,
    0x4A4F4459, 0x5F484149, 0x525F445F, 0x425F7674, 0x78000000, 0x4A4F4459, 0x5F484149, 0x525F455F,
    0x555F7674, 0x78000000, 0x4A4F4459, 0x5F484149, 0x525F455F, 0x425F7674, 0x78000000, 0x4A4F4459,
    0x5F484149, 0x525F465F, 0x555F7674, 0x78000000, 0x4A4F4459, 0x5F484149, 0x525F465F, 0x425F7674,
    0x78000000, 0x4A4F4459, 0x5F484149, 0x525F475F, 0x76747800, 0x4A4F4459, 0x5F484149, 0x525F485F,
    0x76747800, 0x4A4F4459, 0x5F484149, 0x525F495F, 0x76747800, 0x4A4F4459, 0x5F4B4154, 0x41415445,
    0x5F525F76, 0x74780000, 0x4A4F4459, 0x5F4B4154, 0x41415445, 0x5F4C5F76, 0x74780000, 0x4B415445,
    0x5F454152, 0x52494E47, 0x5F525F76, 0x74780000, 0x4B415445, 0x5F454152, 0x52494E47, 0x5F4C5F76,
    0x74780000, 0x4A41434B, 0x5F484149, 0x525F415F, 0x4C5F7674, 0x78000000, 0x4A41434B, 0x5F484149,
    0x525F415F, 0x525F7674, 0x78000000, 0x4A41434B, 0x5F484149, 0x525F425F, 0x4C5F7674, 0x78000000,
    0x4A41434B, 0x5F484149, 0x525F425F, 0x525F7674, 0x78000000, 0x4A41434B, 0x5F484149, 0x525F435F,
    0x4C5F7674, 0x78000000, 0x4A41434B, 0x5F484149, 0x525F435F, 0x525F7674, 0x78000000, 0x4A41434B,
    0x5F5F4841, 0x49525F4D, 0x49445F76, 0x74780000, 0x4541445F, 0x48494745, 0x5F525F76, 0x74780000,
    0x4541445F, 0x48494745, 0x5F4C5F76, 0x74780000, 0x4E45454C, 0x53454E5F, 0x4552495F, 0x4F5F7674,
    0x78000000, 0x4E45454C, 0x53454E5F, 0x4552495F, 0x555F7674, 0x78000000, 0x4E45454C, 0x53454E5F,
    0x4D4F4D4F, 0x5F525F76, 0x74780000, 0x4E45454C, 0x53454E5F, 0x4D4F4D4F, 0x5F4C5F76, 0x74780000,
    0x4E45454C, 0x53454E5F, 0x43414D45, 0x52415F76, 0x74780000, 0x4E45454C, 0x53454E5F, 0x4A41434B,
    0x45545F76, 0x74780000, 0x474F524F, 0x485F4552, 0x495F4F5F, 0x76747800, 0x474F524F, 0x485F4552,
    0x495F555F, 0x76747800, 0x474F524F, 0x485F4245, 0x4C545F52, 0x5F767478, 0x0, 0x474F524F,
    0x485F4245, 0x4C545F4C, 0x5F767478, 0x0, 0x474F524F, 0x485F4A41, 0x434B4554, 0x5F767478,
    0x0, 0x42414241, 0x5F4A4143, 0x4B45545F, 0x76747800, 0x4D52535F, 0x48414952, 0x5F525F76,
    0x74780000, 0x4D52535F, 0x48414952, 0x5F4D4944, 0x5F767478, 0x0, 0x4D52535F, 0x48414952,
    0x5F4C5F76, 0x74780000, 0x444F4E5F, 0x4D414E54, 0x5F767478, 0x0, 0x53484552, 0x4C4F4B5F,
    0x4D414E54, 0x5F555F76, 0x74780000, 0x53484552, 0x4C4F4B5F, 0x4D414E54, 0x5F4F5F76, 0x74780000,
    0x53504144, 0x455F4D41, 0x4E545F76, 0x74780000, 0x4441495F, 0x53434152, 0x465F7674, 0x78000000,
    0x53414E5F, 0x53434152, 0x465F7674, 0x78000000, 0x47454E5F, 0x53434152, 0x465F7674, 0x78000000,
    0x50524953, 0x49415F53, 0x43415246, 0x5F767478, 0x0, 0x504C4953, 0x49415F4D, 0x4F4D4F5F,
    0x525F7674, 0x78000000, 0x504C4953, 0x49415F4D, 0x4F4D4F5F, 0x4C5F7674, 0x78000000, 0x504C4953,
    0x49415F48, 0x4149525F, 0x525F7674, 0x78000000, 0x504C4953, 0x49415F48, 0x4149525F, 0x4C5F7674,
    0x78000000, 0x44414947, 0x4F524F48, 0x5F4A4143, 0x4B45545F, 0x76747800, 0x44414947, 0x4F524F48,
    0x5F42454C, 0x545F525F, 0x76747800, 0x44414947, 0x4F524F48, 0x5F42454C, 0x545F4C5F, 0x76747800,
    0x44494749, 0x424F595F, 0x4D4F4D4F, 0x5F525F76, 0x74780000, 0x44494749, 0x424F595F, 0x4D4F4D4F,
    0x5F4C5F76, 0x74780000, 0x4C494C59, 0x5F4A4143, 0x4B45545F, 0x76747800, 0x4C494C59, 0x5F455249,
    0x5F767478, 0x0, 0x504A5F53, 0x554E455F, 0x525F7674, 0x78000000, 0x504A5F53, 0x554E455F,
    0x4C5F7674, 0x78000000, 0x524F4745, 0x525F4A41, 0x434B4554, 0x5F767478, 0x0, (u32)lbl_1_data_3F578__fzgx_offset_0,
    (u32)lbl_1_data_3F58C__fzgx_offset_0, (u32)lbl_1_data_3F5A0__fzgx_offset_0, (u32)lbl_1_data_3F5B4__fzgx_offset_0, (u32)lbl_1_data_3F5C8__fzgx_offset_0, (u32)lbl_1_data_3F5DC__fzgx_offset_0, (u32)lbl_1_data_3F5F0__fzgx_offset_0, (u32)lbl_1_data_3F604__fzgx_offset_0, (u32)lbl_1_data_3F618__fzgx_offset_0,
    (u32)lbl_1_data_3F630__fzgx_offset_0, (u32)lbl_1_data_3F644__fzgx_offset_0, (u32)lbl_1_data_3F658__fzgx_offset_0, (u32)lbl_1_data_3F66C__fzgx_offset_0, (u32)lbl_1_data_3F680__fzgx_offset_0, (u32)lbl_1_data_3F694__fzgx_offset_0, (u32)lbl_1_data_3F6A8__fzgx_offset_0, (u32)lbl_1_data_3F6B8__fzgx_offset_0,
    (u32)lbl_1_data_3F6C8__fzgx_offset_0, (u32)lbl_1_data_3F6D8__fzgx_offset_0, (u32)lbl_1_data_3F6E8__fzgx_offset_0, (u32)lbl_1_data_3F6FC__fzgx_offset_0, (u32)lbl_1_data_3F710__fzgx_offset_0, (u32)lbl_1_data_3F724__fzgx_offset_0, (u32)lbl_1_data_3F738__fzgx_offset_0, (u32)lbl_1_data_3F748__fzgx_offset_0,
    (u32)lbl_1_data_3F75C__fzgx_offset_0, (u32)lbl_1_data_3F770__fzgx_offset_0, (u32)lbl_1_data_3F780__fzgx_offset_0, (u32)lbl_1_data_3F790__fzgx_offset_0, (u32)lbl_1_data_3F7A0__fzgx_offset_0, (u32)lbl_1_data_3F7B0__fzgx_offset_0, (u32)lbl_1_data_3F7C0__fzgx_offset_0, (u32)lbl_1_data_3F7D0__fzgx_offset_0,
    (u32)lbl_1_data_3F7E4__fzgx_offset_0, (u32)lbl_1_data_3F7F8__fzgx_offset_0, (u32)lbl_1_data_3F80C__fzgx_offset_0, (u32)lbl_1_data_3F820__fzgx_offset_0, (u32)lbl_1_data_3F834__fzgx_offset_0, (u32)lbl_1_data_3F848__fzgx_offset_0, (u32)lbl_1_data_3F85C__fzgx_offset_0, (u32)lbl_1_data_3F870__fzgx_offset_0,
    (u32)lbl_1_data_3F884__fzgx_offset_0, (u32)lbl_1_data_3F898__fzgx_offset_0, (u32)lbl_1_data_3F8AC__fzgx_offset_0, (u32)lbl_1_data_3F8C0__fzgx_offset_0, (u32)lbl_1_data_3F8D4__fzgx_offset_0, (u32)lbl_1_data_3F8E4__fzgx_offset_0, (u32)lbl_1_data_3F8F4__fzgx_offset_0, (u32)lbl_1_data_3F904__fzgx_offset_0,
    (u32)lbl_1_data_3F918__fzgx_offset_0, (u32)lbl_1_data_3F92C__fzgx_offset_0, (u32)lbl_1_data_3F940__fzgx_offset_0, (u32)lbl_1_data_3F954__fzgx_offset_0, (u32)lbl_1_data_3F968__fzgx_offset_0, (u32)lbl_1_data_3F97C__fzgx_offset_0, (u32)lbl_1_data_3F990__fzgx_offset_0, (u32)lbl_1_data_3F9A4__fzgx_offset_0,
    (u32)lbl_1_data_3F9B8__fzgx_offset_0, (u32)lbl_1_data_3F9CC__fzgx_offset_0, (u32)lbl_1_data_3F9E0__fzgx_offset_0, (u32)lbl_1_data_3F9F0__fzgx_offset_0, (u32)lbl_1_data_3FA00__fzgx_offset_0, (u32)lbl_1_data_3FA14__fzgx_offset_0, (u32)lbl_1_data_3FA28__fzgx_offset_0, (u32)lbl_1_data_3FA3C__fzgx_offset_0,
    (u32)lbl_1_data_3FA50__fzgx_offset_0, (u32)lbl_1_data_3FA64__fzgx_offset_0, (u32)lbl_1_data_3FA78__fzgx_offset_0, (u32)lbl_1_data_3FA88__fzgx_offset_0, (u32)lbl_1_data_3FA98__fzgx_offset_0, (u32)lbl_1_data_3FAAC__fzgx_offset_0, (u32)lbl_1_data_3FAC0__fzgx_offset_0, (u32)lbl_1_data_3FAD4__fzgx_offset_0,
    (u32)lbl_1_data_3FAE4__fzgx_offset_0, (u32)lbl_1_data_3FAF4__fzgx_offset_0, (u32)lbl_1_data_3FB08__fzgx_offset_0, (u32)lbl_1_data_3FB18__fzgx_offset_0, (u32)lbl_1_data_3FB28__fzgx_offset_0, (u32)lbl_1_data_3FB3C__fzgx_offset_0, (u32)lbl_1_data_3FB50__fzgx_offset_0, (u32)lbl_1_data_3FB60__fzgx_offset_0,
    (u32)lbl_1_data_3FB70__fzgx_offset_0, (u32)lbl_1_data_3FB80__fzgx_offset_0, (u32)lbl_1_data_3FB90__fzgx_offset_0, (u32)lbl_1_data_3FBA4__fzgx_offset_0, (u32)lbl_1_data_3FBB8__fzgx_offset_0, (u32)lbl_1_data_3FBCC__fzgx_offset_0, (u32)lbl_1_data_3FBE0__fzgx_offset_0, (u32)lbl_1_data_3FBF4__fzgx_offset_0,
    (u32)lbl_1_data_3FC08__fzgx_offset_0, (u32)lbl_1_data_3FC1C__fzgx_offset_0, (u32)lbl_1_data_3FC30__fzgx_offset_0, (u32)lbl_1_data_3FC44__fzgx_offset_0, (u32)lbl_1_data_3FC58__fzgx_offset_0, (u32)lbl_1_data_3FC68__fzgx_offset_0, (u32)lbl_1_data_3FC78__fzgx_offset_0, (u32)lbl_1_data_3FC88__fzgx_offset_0,
    (u32)lbl_1_data_3FC98__fzgx_offset_0, 0xF, 0xF, 0xF, 0xF, 0x6, 0x6, 0x6,
    0x6, 0x6, 0x6, 0x9, 0x9, 0x9, 0x9, 0x9,
    0x13, 0x1D, 0x1E, 0x1E, 0x10, 0x10, 0x10, 0x2,
    0x29, 0x29, 0x29, 0x15, 0x15, 0x15, 0x18, 0x18,
    0x18, 0x18, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1,
    0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1,
    0x1, 0x1, 0x1, 0xB, 0xB, 0xD, 0xD, 0xD,
    0xD, 0xD, 0xD, 0xD, 0x8, 0x8, 0x16, 0x16,
    0x16, 0x16, 0x16, 0x16, 0x4, 0x4, 0x4, 0x4,
    0x4, 0x3, 0x14, 0x14, 0x14, 0x1F, 0x28, 0x28,
    0x22, 0x21, 0x2A, 0x2B, 0x24, 0x24, 0x24, 0x24,
    0x24, 0x23, 0x23, 0x23, 0x20, 0x20, 0x25, 0x25,
    0x26, 0x26, 0x1B
};
static u32 fzgx_pool_data_lbl_1_data_3FFBC[98] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x12, 0x17, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1,
    0x10, 0xB, 0x5, 0x5, 0x5, 0x1, 0x10, 0x1,
    0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1,
    0x10, 0x10, 0x1, 0x10, 0x10, 0x1, 0x1, 0x1,
    0xB, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5,
    0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5,
    0xB, 0x6, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5,
    0x5, 0x5, 0x5, 0x5, 0x5, 0x1, 0x1, 0x12,
    0x17, 0x1, 0x1, 0x1, 0x1, 0x10, 0x10, 0x1,
    0x1, 0x5, 0x5, 0x5, 0x1, 0x1, 0x1, 0x10,
    0x1, 0x1, 0x1, 0x1, 0x12, 0x17, 0x5, 0x5,
    0x1, 0x10, 0x10, 0x12, 0x17, 0x1, 0x1, 0x13,
    0x18, 0x1
};
static u32 fzgx_pool_data_lbl_1_data_3F510_C34[123] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x10203, 0x10203, 0x4050001, 0x2030400, 0x100, 0x1020000, 0x1020001, 0x2000102,
    0x3000102, 0x3040506, 0x708090A, 0xB0C0D0E, 0xF100001, 0x10203, 0x4050600, 0x1000102,
    0x3040500, 0x1020304, 0x102, 0x100, 0x0, 0x1020304, 0x2030400, 0x1000100,
    0x1000000, (u32)fn_1_11BFCC__fzgx_offset_0, (u32)fn_1_11BFCC__fzgx_offset_0, (u32)fn_1_1091D4__fzgx_offset_0, (u32)fn_1_10A43C__fzgx_offset_0, (u32)fn_1_10A8D0__fzgx_offset_0, (u32)fn_1_10B344__fzgx_offset_0, (u32)fn_1_10BA00__fzgx_offset_0,
    (u32)fn_1_10C4E4__fzgx_offset_0, (u32)fn_1_10B7D8__fzgx_offset_0, (u32)fn_1_127FB8__fzgx_offset_0, (u32)fn_1_10C9B0__fzgx_offset_0, (u32)fn_1_10C9B0__fzgx_offset_0, (u32)fn_1_10C9B0__fzgx_offset_0, (u32)fn_1_10D2F0__fzgx_offset_0, (u32)fn_1_10B7D8__fzgx_offset_0,
    (u32)fn_1_10DDE4__fzgx_offset_0, (u32)fn_1_110008__fzgx_offset_0, (u32)fn_1_111510__fzgx_offset_0, (u32)fn_1_112F40__fzgx_offset_0, (u32)fn_1_1137E4__fzgx_offset_0, (u32)fn_1_10A8D0__fzgx_offset_0, (u32)fn_1_10B344__fzgx_offset_0, (u32)fn_1_1145C8__fzgx_offset_0,
    (u32)fn_1_1145C8__fzgx_offset_0, (u32)fn_1_118D90__fzgx_offset_0, (u32)fn_1_118D90__fzgx_offset_0, (u32)fn_1_1145C8__fzgx_offset_0, (u32)fn_1_118D90__fzgx_offset_0, (u32)fn_1_118D90__fzgx_offset_0, (u32)fn_1_1145C8__fzgx_offset_0, (u32)fn_1_10A8D0__fzgx_offset_0,
    (u32)fn_1_10B344__fzgx_offset_0, (u32)fn_1_127FB8__fzgx_offset_0, (u32)fn_1_115B58__fzgx_offset_0, (u32)fn_1_1166EC__fzgx_offset_0, (u32)fn_1_115B58__fzgx_offset_0, (u32)fn_1_1166EC__fzgx_offset_0, (u32)fn_1_115B58__fzgx_offset_0, (u32)fn_1_1166EC__fzgx_offset_0,
    (u32)fn_1_115B58__fzgx_offset_0, (u32)fn_1_1166EC__fzgx_offset_0, (u32)fn_1_115B58__fzgx_offset_0, (u32)fn_1_1166EC__fzgx_offset_0, (u32)fn_1_115B58__fzgx_offset_0, (u32)fn_1_1166EC__fzgx_offset_0, (u32)fn_1_115B58__fzgx_offset_0, (u32)fn_1_115B58__fzgx_offset_0,
    (u32)fn_1_115B58__fzgx_offset_0, (u32)fn_1_127FB8__fzgx_offset_0, (u32)fn_1_127FB8__fzgx_offset_0, (u32)fn_1_1154D0__fzgx_offset_0, (u32)fn_1_1154D0__fzgx_offset_0, (u32)fn_1_1171B8__fzgx_offset_0, (u32)fn_1_1171B8__fzgx_offset_0, (u32)fn_1_1171B8__fzgx_offset_0,
    (u32)fn_1_1171B8__fzgx_offset_0, (u32)fn_1_1171B8__fzgx_offset_0, (u32)fn_1_1171B8__fzgx_offset_0, (u32)fn_1_1171B8__fzgx_offset_0, (u32)fn_1_1185B4__fzgx_offset_0, (u32)fn_1_1185B4__fzgx_offset_0, (u32)fn_1_10A8D0__fzgx_offset_0, (u32)fn_1_10B344__fzgx_offset_0,
    (u32)fn_1_11B4E4__fzgx_offset_0, (u32)fn_1_11B4E4__fzgx_offset_0, (u32)fn_1_11D1FC__fzgx_offset_0, (u32)fn_1_126DE8__fzgx_offset_0, (u32)fn_1_10A8D0__fzgx_offset_0, (u32)fn_1_10B344__fzgx_offset_0, (u32)fn_1_1145C8__fzgx_offset_0, (u32)fn_1_1145C8__fzgx_offset_0,
    (u32)fn_1_126DE8__fzgx_offset_0, (u32)fn_1_11A158__fzgx_offset_0, (u32)fn_1_11CAB4__fzgx_offset_0, (u32)fn_1_11CAB4__fzgx_offset_0, (u32)fn_1_11CAB4__fzgx_offset_0, (u32)fn_1_11ED0C__fzgx_offset_0, (u32)fn_1_1201E4__fzgx_offset_0, (u32)fn_1_122348__fzgx_offset_0,
    (u32)fn_1_12295C__fzgx_offset_0, (u32)fn_1_1145C8__fzgx_offset_0, (u32)fn_1_1145C8__fzgx_offset_0, (u32)fn_1_1145C8__fzgx_offset_0, (u32)fn_1_1145C8__fzgx_offset_0, (u32)fn_1_11BFCC__fzgx_offset_0, (u32)fn_1_11BFCC__fzgx_offset_0, (u32)fn_1_1177C4__fzgx_offset_0,
    (u32)fn_1_1177C4__fzgx_offset_0, (u32)fn_1_1244F0__fzgx_offset_0, (u32)fn_1_1145C8__fzgx_offset_0, (u32)fn_1_1145C8__fzgx_offset_0, (u32)fn_1_1262A4__fzgx_offset_0, (u32)fn_1_1262A4__fzgx_offset_0, (u32)fn_1_1250D0__fzgx_offset_0, (u32)fn_1_125CE8__fzgx_offset_0,
    (u32)fn_1_11BFCC__fzgx_offset_0, (u32)fn_1_11BFCC__fzgx_offset_0, (u32)fn_1_126DE8__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_1_data_3F510_E20[128] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)fn_1_11C440__fzgx_offset_0, (u32)fn_1_11C440__fzgx_offset_0, (u32)fn_1_10976C__fzgx_offset_0, (u32)fn_1_10A6A0__fzgx_offset_0, (u32)fn_1_10AD18__fzgx_offset_0, (u32)fn_1_10B5A8__fzgx_offset_0, (u32)fn_1_10BE3C__fzgx_offset_0, (u32)fn_1_10C7B4__fzgx_offset_0,
    (u32)fn_1_10B800__fzgx_offset_0, (u32)fn_1_128038__fzgx_offset_0, (u32)fn_1_10CC38__fzgx_offset_0, (u32)fn_1_10CC38__fzgx_offset_0, (u32)fn_1_10CC38__fzgx_offset_0, (u32)fn_1_10D7D4__fzgx_offset_0, (u32)fn_1_10B800__fzgx_offset_0, (u32)fn_1_10E3B4__fzgx_offset_0,
    (u32)fn_1_110478__fzgx_offset_0, (u32)fn_1_111980__fzgx_offset_0, (u32)fn_1_1132E4__fzgx_offset_0, (u32)fn_1_113C58__fzgx_offset_0, (u32)fn_1_10AD18__fzgx_offset_0, (u32)fn_1_10B5A8__fzgx_offset_0, (u32)fn_1_11492C__fzgx_offset_0, (u32)fn_1_11492C__fzgx_offset_0,
    (u32)fn_1_1192D0__fzgx_offset_0, (u32)fn_1_1192D0__fzgx_offset_0, (u32)fn_1_11492C__fzgx_offset_0, (u32)fn_1_1192D0__fzgx_offset_0, (u32)fn_1_1192D0__fzgx_offset_0, (u32)fn_1_11492C__fzgx_offset_0, (u32)fn_1_10AD18__fzgx_offset_0, (u32)fn_1_10B5A8__fzgx_offset_0,
    (u32)fn_1_128038__fzgx_offset_0, (u32)fn_1_115BE8__fzgx_offset_0, (u32)fn_1_11677C__fzgx_offset_0, (u32)fn_1_115BE8__fzgx_offset_0, (u32)fn_1_11677C__fzgx_offset_0, (u32)fn_1_115BE8__fzgx_offset_0, (u32)fn_1_11677C__fzgx_offset_0, (u32)fn_1_115BE8__fzgx_offset_0,
    (u32)fn_1_11677C__fzgx_offset_0, (u32)fn_1_115BE8__fzgx_offset_0, (u32)fn_1_11677C__fzgx_offset_0, (u32)fn_1_115BE8__fzgx_offset_0, (u32)fn_1_11677C__fzgx_offset_0, (u32)fn_1_115BE8__fzgx_offset_0, (u32)fn_1_115BE8__fzgx_offset_0, (u32)fn_1_115BE8__fzgx_offset_0,
    (u32)fn_1_128038__fzgx_offset_0, (u32)fn_1_128038__fzgx_offset_0, (u32)fn_1_115560__fzgx_offset_0, (u32)fn_1_115560__fzgx_offset_0, (u32)fn_1_117424__fzgx_offset_0, (u32)fn_1_117424__fzgx_offset_0, (u32)fn_1_117424__fzgx_offset_0, (u32)fn_1_117424__fzgx_offset_0,
    (u32)fn_1_117424__fzgx_offset_0, (u32)fn_1_117424__fzgx_offset_0, (u32)fn_1_117424__fzgx_offset_0, (u32)fn_1_1188CC__fzgx_offset_0, (u32)fn_1_1188CC__fzgx_offset_0, (u32)fn_1_10AD18__fzgx_offset_0, (u32)fn_1_10B5A8__fzgx_offset_0, (u32)fn_1_11B958__fzgx_offset_0,
    (u32)fn_1_11B958__fzgx_offset_0, (u32)fn_1_11DE2C__fzgx_offset_0, (u32)fn_1_12744C__fzgx_offset_0, (u32)fn_1_10AD18__fzgx_offset_0, (u32)fn_1_10B5A8__fzgx_offset_0, (u32)fn_1_11492C__fzgx_offset_0, (u32)fn_1_11492C__fzgx_offset_0, (u32)fn_1_12744C__fzgx_offset_0,
    (u32)fn_1_11A774__fzgx_offset_0, (u32)fn_1_11CD3C__fzgx_offset_0, (u32)fn_1_11CD3C__fzgx_offset_0, (u32)fn_1_11CD3C__fzgx_offset_0, (u32)fn_1_11F250__fzgx_offset_0, (u32)fn_1_120804__fzgx_offset_0, (u32)fn_1_12277C__fzgx_offset_0, (u32)fn_1_123050__fzgx_offset_0,
    (u32)fn_1_11492C__fzgx_offset_0, (u32)fn_1_11492C__fzgx_offset_0, (u32)fn_1_11492C__fzgx_offset_0, (u32)fn_1_11492C__fzgx_offset_0, (u32)fn_1_11C440__fzgx_offset_0, (u32)fn_1_11C440__fzgx_offset_0, (u32)fn_1_117D5C__fzgx_offset_0, (u32)fn_1_117D5C__fzgx_offset_0,
    (u32)fn_1_124AD4__fzgx_offset_0, (u32)fn_1_11492C__fzgx_offset_0, (u32)fn_1_11492C__fzgx_offset_0, (u32)fn_1_126774__fzgx_offset_0, (u32)fn_1_126774__fzgx_offset_0, (u32)fn_1_1256EC__fzgx_offset_0, (u32)fn_1_125DF0__fzgx_offset_0, (u32)fn_1_11C440__fzgx_offset_0,
    (u32)fn_1_11C440__fzgx_offset_0, (u32)fn_1_12744C__fzgx_offset_0, 0x62, (u32)lbl_1_data_3F6E8__fzgx_offset_0, (u32)lbl_1_data_3F738__fzgx_offset_0, (u32)lbl_1_data_3F770__fzgx_offset_0, (u32)lbl_1_data_3F6B8__fzgx_offset_0, (u32)lbl_1_data_3FB60__fzgx_offset_0,
    (u32)lbl_1_data_3FB70__fzgx_offset_0, (u32)lbl_1_data_3FB80__fzgx_offset_0, (u32)lbl_1_data_3FB50__fzgx_offset_0, (u32)lbl_1_data_3F6C8__fzgx_offset_0, (u32)lbl_1_data_3FA98__fzgx_offset_0, (u32)lbl_1_data_3FAAC__fzgx_offset_0, (u32)lbl_1_data_3F7A0__fzgx_offset_0, (u32)lbl_1_data_3FB28__fzgx_offset_0,
    (u32)lbl_1_data_3FB3C__fzgx_offset_0, (u32)lbl_1_data_3FC08__fzgx_offset_0, (u32)lbl_1_data_3FC1C__fzgx_offset_0, (u32)lbl_1_data_3FB90__fzgx_offset_0, (u32)lbl_1_data_3F724__fzgx_offset_0, (u32)lbl_1_data_3F6A8__fzgx_offset_0, 0x13, 0x5F767478,
    0x0, 0x4E5F2573, 0x0, 0x53504144, 0x455F4D41, 0x4E540000, 0x5F4D414E, 0x54000000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_3F510(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3F510;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3FFBC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3F510_C34;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_3F510_E20;
}
#pragma section code_type ".text"

#pragma opt_common_subs off

static const u32 fzgx_pool_rodata_lbl_1_rodata_7AB8[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_7AB8_C[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_7AB8_18[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3E800000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_7AB8_20[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3C23D70A
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_rodata_7AB8(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_7AB8;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_7AB8_C;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_7AB8_18;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_7AB8_20;
}
#pragma section code_type ".text"

void fn_1_107C74(BgOwner *owner) {
    
    u32 j;
    struct { u32 value; } i;
    u32 k;
    BgEntry *entry;
    u8 *model;
    BgRange *range;
    BgVec b;
    BgVec a;
    f32 dz;
    f32 dy;
    f32 dx;
    f32 distance;

    if (owner == NULL) {
        return;
    }
    if (owner->unk_8C != owner->unk_90) {
        owner->unk_90 = owner->unk_8C;
        if (owner != NULL) {
            fn_1_1088B8(owner);
        }
        fn_1_107930(owner);
        return;
    }
    for (i.value = 0; i.value < 64; i.value++) {
        for (j = 0; j < 70; j++) {
            entry = &((BgEntry *)&lbl_1_bss_86ED0)[j];
            if (entry->unk_C == NULL || entry->unk_C != owner ||
                i.value != (((u8 *)(((u8 *)fzgx_pool_data_lbl_1_data_3F510_C34))))[entry->unk_8]) {
                continue;
            }
            model = entry->unk_C->unk_150->unk_8 + ((u32 *)(((u8 *)fzgx_pool_data_lbl_1_data_3FFBC)))[entry->unk_8] * 0x18C;
            lbl_1_bss_88B4C = 0;
            range = (BgRange *)owner->unk_150;
            if (__fabs(range->unk_4C - range->unk_48) <= (*(f64 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_7AB8_18)))) {
                a = (*(BgVec *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_7AB8_C)));
                b = (*(BgVec *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_7AB8_C)));
                lbl_8006DBAC(model + 0x88);
                lbl_8006E1B0(&b, &b);
                lbl_8006DBAC(&entry->unk_34);
                lbl_8006E1B0(&a, &a);
                dx = b.x - a.x;
                dy = b.y - a.y;
                dz = b.z - a.z;
                b.x = dx;
                b.y = dy;
                b.z = dz;
                distance = dx * dx;
                distance = dy * dy + distance;
                distance = dz * dz + distance;
                lbl_1_bss_88B4C = 1;
                if (distance > (*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_1_rodata_7AB8_20)))) {
                    fn_1_107E90(entry);
                    for (k = 0; k < 60; k++) {
                        (((BgEntryFn *)(((u8 *)fzgx_pool_data_lbl_1_data_3F510_E20))))[entry->unk_8](entry);
                    }
                }
                lbl_1_bss_88B4C = 0;
            }
            ((BgEntryFn *)(((u8 *)fzgx_pool_data_lbl_1_data_3F510_E20)))[entry->unk_8](entry);
            lbl_8006DD14(model + 0x88, &entry->unk_34);
            break;
        }
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_107C74 */

/* fzgx:begin fn_1_107E90 */
typedef struct {
    u8 unk_00[0x8];
    u32 unk_08;
    u8 *unk_0C;
    u8 unk_10[0x8];
    u32 unk_18;
    u8 unk_1C[0x8];
    u8 *unk_24;
} Fn107E90Context;

// Initialize each background entry selected by the context.
void fn_1_107E90(Fn107E90Context *context) {
    u32 i;
    u8 *entries;
    u8 *background;
    u8 *entry;
    u32 *background_indices;

    i = 0;
    entries = context->unk_24;
    background_indices = (u32 *)&lbl_1_data_3FFBC;
    background = *(u8 **)(*(u8 **)(context->unk_0C + 0x150) + 0x8);
    entry = background + background_indices[context->unk_08] * 0x18c;
    for (; i < context->unk_18; i++, entries += 0x44) {
        lbl_8006DBAC(entry + 0x88);
        lbl_8006E1B0(entries + 0x28, entries + 0x10);
    }
}
/* fzgx:end fn_1_107E90 */

/* fzgx:begin fn_1_107F2C */
void fn_1_107F2C(void *arg0) {
    fn_1_107F74(arg0, 0);
}
/* fzgx:end fn_1_107F2C */

/* fzgx:begin fn_1_107F50 */
void fn_1_107F50(void *arg0) {
    fn_1_107F74(arg0, 1);
}
/* fzgx:end fn_1_107F50 */

/* fzgx:begin fn_1_108BD0 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[4] = {0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table5[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1e-07;
}
#pragma section code_type ".text"

typedef struct {
    f32 x, y, z;
} Fn1108BD0_Vec;

typedef struct {
    u8 pad_0[0x14];
    f32 radius;
} Fn1108BD0_Shape;

typedef struct {
    Fn1108BD0_Shape *shape;
    const char *name;
} Fn1108BD0_Entry;

typedef struct {
    u32 count;
    u32 unk_4;
    Fn1108BD0_Entry *entries;
} Fn1108BD0_Table;

typedef struct {
    u8 pad_0[0x88];
    u8 mtx[0x18C - 0x88];
} Fn1108BD0_Joint;

typedef struct {
    u8 pad_0[0x8];
    Fn1108BD0_Joint *joints;
} Fn1108BD0_Skeleton;

typedef struct {
    u8 pad_0[0x8C];
    s32 table_index;
    u8 pad_90[0xE4 - 0x90];
    Fn1108BD0_Table *tables[(0x150 - 0xE4) / 4];
    Fn1108BD0_Skeleton *skeleton;
} Fn1108BD0_Model;

typedef struct {
    u8 flags;
    u8 pad_1[0xF];
    Fn1108BD0_Vec pos;
    u8 pad_1C[0x44 - 0x1C];
} Fn1108BD0_Part;

typedef struct {
    u8 pad_0[0x8];
    s32 name_index;
    Fn1108BD0_Model *model;
    u8 pad_10[0x8];
    u32 part_count;
    u8 pad_1C[0x8];
    Fn1108BD0_Part *parts;
} Fn1108BD0_Object;

extern const char *lbl_1_data_3FCAC[];
extern u32 fn_80083970(const char *, const char *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006D668(void *);
extern f32 lbl_8006D0B4(f32);

void fn_1_108BD0(Fn1108BD0_Object *object, s32 joint_index, f32 margin, f32 x, f32 y, f32 z) {
    s32 joint = joint_index;
    Fn1108BD0_Object *obj = object;
    u32 i;
    Fn1108BD0_Table *table;
    Fn1108BD0_Entry *entry;
    f32 radius;
    f32 dist;
    f32 dy;
    f32 dz;
    u32 n;
    Fn1108BD0_Part *part;

    table = obj->model->tables[obj->model->table_index];
    if (table == 0) {
        return;
    }
    entry = table->entries;
    for (i = 0; i < table->count; i++, entry++) {
        if (entry != 0 && fn_80083970(entry->name, lbl_1_data_3FCAC[obj->name_index]) != 0) {
            radius = 0.5f * entry->shape->radius;
            break;
        }
    }
    radius *= 0.25f;
    {
        Fn1108BD0_Vec pos;

        {
            Fn1108BD0_Joint *j = &obj->model->skeleton->joints[joint];
            pos.x = x;
            pos.y = y;
            pos.z = z;
            lbl_8006DBAC(j->mtx);
        }
        lbl_8006E1B0(&pos, &pos);
        {
        Fn1108BD0_Vec sum = {0.0f, 0.0f, 0.0f};
        n = 0;
        part = obj->parts;
        for (i = 0; i < obj->part_count; i++, part++) {
            if (!(part->flags & 1)) {
                n++;
                sum.x += part->pos.x;
                sum.y += part->pos.y;
                sum.z += part->pos.z;
            }
        }
        sum.x /= (f32)n;
        sum.y /= (f32)n;
        sum.z /= (f32)n;
        dz = sum.z - pos.z;
        dy = sum.y - pos.y;
        dist = sum.x - pos.x;
        dist *= dist;
        dist += dy * dy;
        dist += dz * dz;
        dist = lbl_8006D0B4(dist);
        if (radius + margin > dist) {
            margin = radius + margin - dist;
            sum.x -= pos.x;
            sum.y -= pos.y;
            sum.z -= pos.z;
            lbl_8006D668(&sum);
            sum.x *= margin;
            sum.y *= margin;
            sum.z *= margin;
            part = obj->parts;
            for (i = 0; i < obj->part_count; i++, part++) {
                if (!(part->flags & 1)) {
                    part->pos.x += sum.x;
                    part->pos.y += sum.y;
                    part->pos.z += sum.z;
                }
            }
        }
        }
    }
}
/* fzgx:end fn_1_108BD0 */

/* fzgx:begin fn_1_1185B4 */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table3[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1e-07;
}
static const u32 fzgx_pool_table5[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 0.25f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    d = 0.0013611111376020642;
    s = 0.0027222223579883575f;
    s = -1.0f;
    s = 0.0f;
    s = -2.0f;
    s = 2.0f;
    s = 1.1920928955078125e-07f;
    s = -1.0000001192092896f;
}
static const u32 fzgx_pool_table9[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.0013611111789941788f;
    s = -0.0027222223579883575f;
    s = 9.999999747378752e-05f;
    s = 1.0f;
    s = 0.00039999998989515007f;
    s = 0.02500000037252903f;
    s = 0.004224999807775021f;
    d = 0.0749999976158142;
    d = 0.3;
    s = -0.01899999938905239f;
    s = 0.05700000002980232f;
    s = 0.0009609999833628535f;
}
static const u32 fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04099999949336052;
    d = -1.0;
    s = 0.75f;
    s = -0.25f;
}
#pragma section code_type ".text"

typedef struct {
    u8 unk_0;
    u8 pad_1[0x13];
    f32 unk_14;
    u8 pad_18[0x28];
    f32 unk_40;
} Elem1185B4;

typedef struct {
    u8 pad_0[8];
    s32 unk_8;
    u8 pad_C[0xC];
    u32 unk_18;
    u8 pad_1C[8];
    Elem1185B4 *unk_24;
} Obj1185B4;

extern f32 fn_1_128AAC(s32, f32);
extern u32 fn_1_10846C(void *);
extern u8 *fn_80083970(u8 *, const u8 *);
extern void fn_1_128884(void *, void *, s32);

void fn_1_1185B4(Obj1185B4 *obj) {
    u32 i;
    Elem1185B4 *a;
    u32 j;
    Elem1185B4 *b;
    s32 flag;
    u32 n;
    u32 idx;

    if (obj != NULL) {
        flag = fn_80083970(((u8 **)lbl_1_data_3FCAC)[obj->unk_8], lbl_1_data_3F9E0) != 0;
        fn_1_10846C(obj);
        a = obj->unk_24;
        for (i = 0; i < obj->unk_18; i++, a++) {
            if (a->unk_0 & 1) {
                a->unk_40 = -1.0f;
                a->unk_0 = 0;
            } else {
                a->unk_40 = 0.0f;
                a->unk_0 = 1;
            }
        }
        i = 0;
        a = obj->unk_24;
        for (; i < obj->unk_18; i++, a++) {
            b = obj->unk_24 + i + 1;
            for (j = i + 1; j < obj->unk_18; j++, b++) {
                if (!(a->unk_0 & 1) && (b->unk_0 & 1)) {
                    fn_1_128884(a, b, 0x44);
                }
            }
        }
        i = 0;
        a = obj->unk_24;
        for (; i < obj->unk_18; i++, a++) {
            if (flag) {
                b = obj->unk_24 + i + 1;
                for (j = i + 1; j < obj->unk_18; j++, b++) {
                    if (a->unk_0 == b->unk_0 && a->unk_14 < b->unk_14) {
                        fn_1_128884(a, b, 0x44);
                    }
                }
            } else {
                b = obj->unk_24 + i + 1;
                for (j = i + 1; j < obj->unk_18; j++, b++) {
                    if (a->unk_0 == b->unk_0 && a->unk_14 > b->unk_14) {
                        fn_1_128884(a, b, 0x44);
                    }
                }
            }
        }
        n = (obj->unk_18 - 1) / 4;
        for (i = 0; i < n; i++) {
            for (j = 0; j < 4; j++) {
                idx = i * 4 + j;
                if (1.1920928955078125e-07f + obj->unk_24[idx].unk_40 < 0.0f) {
                    obj->unk_24[idx].unk_40 = -fn_1_128AAC(i, 2.0f);
                    obj->unk_24[idx].unk_40 /= fn_1_128AAC(n, 2.0f);
                    obj->unk_24[idx].unk_40 *= 0.75f;
                    obj->unk_24[idx].unk_40 -= 0.25f;
                }
            }
        }
        obj->unk_24[n * 4].unk_40 = -1.0f;
    }
}
/* fzgx:end fn_1_1185B4 */
