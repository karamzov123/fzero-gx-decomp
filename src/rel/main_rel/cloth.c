#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/cloth.h"

extern void fn_1_105744(void);
extern void fn_1_106DB4(void);
extern void fn_1_9D0EC(u32, u32, void*, void*);
extern void fn_1_103AA8(void);
extern u32 lbl_1_bss_85288[2];
extern void fn_1_103AD4(void);
extern void fn_1_105768(void);
extern void fn_1_9E5B8(void *);
extern struct fn_1_10240C_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern u32 fn_80008BA8(u32, u32, u32);

/* fzgx:begin fn_1_101AE8 noprologue */
#include "types.h"

struct fn_1_101AE8_lbl_1_bss_85250 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[0x4];
    u32 unk_18;
    u8 pad_1C[0x4];
    u32 unk_20;
};
struct fn_1_101AE8_lbl_801A6410 {
    u32 unk_0;
};

extern struct fn_1_101AE8_lbl_1_bss_85250 lbl_1_bss_85250;
extern struct fn_1_101AE8_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_435C(u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 lbl_1_data_3F17C;
extern void fn_1_41A8(void);
extern void fn_800711A8(void *);
extern void fn_80071718(void *);

void fn_1_101AE8(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    struct fn_1_101AE8_lbl_1_bss_85250 *p_lbl_1_bss_85250;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v7;
    u32 t6, t7;
    p_lbl_1_bss_85250 = (struct fn_1_101AE8_lbl_1_bss_85250 *)&lbl_1_bss_85250;
    fn_1_435C(arg0);
    fn_1_41A8();
    fn_1_435C(arg1);
    fn_1_41A8();
    v0 = p_lbl_1_bss_85250->unk_C;
    if (v0 != 0) {
    fn_80071718((void *)v0);
    p_lbl_1_bss_85250->unk_C = 0;
    }
    v1 = p_lbl_1_bss_85250->unk_10;
    if (v1 != 0) {
    fn_800711A8((void *)v1);
    p_lbl_1_bss_85250->unk_10 = 0;
    }
    v2 = p_lbl_1_bss_85250->unk_18;
    v5 = arg3;
    if (v2 != 0) {
    v5 = (u32)&lbl_801A6410;
    v3 = (u32)&lbl_1_data_3F17C;
    v4 = *(u32 *)((u8 *)v5 + 0);
    v5 = 257;
    t6 = fn_1_46B4(v4, v2, (u32)v3, v5);
    v4 = t6;
    p_lbl_1_bss_85250->unk_18 = 0;
    }
    v6 = p_lbl_1_bss_85250->unk_20;
    v7 = v4;
    if (v6 != 0) {
    v7 = lbl_801A6410.unk_0;
    t7 = fn_1_46B4(v7, v6, (u32)&lbl_1_data_3F17C, 258);
    v7 = t7;
    p_lbl_1_bss_85250->unk_20 = 0;
    }
}
/* fzgx:end fn_1_101AE8 */

/* fzgx:begin fn_1_101BC4 */
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "dolphin/gx.h"

/* begin game/main_rel/cloth_types.h (fork-deltawave784/windows-and-types@8c8d7cc3) */
#ifndef GAME_MAIN_REL_CLOTH_TYPES_H
#define GAME_MAIN_REL_CLOTH_TYPES_H

// Types (and the externs that name them) of cloth.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


struct fn_1_10240C_lbl_801A6410 {
    u32 unk_0;
};

extern struct fn_1_10240C_lbl_801A6410 lbl_801A6410;

#endif  // GAME_MAIN_REL_CLOTH_TYPES_H

/* end game/main_rel/cloth_types.h */

struct fn_1_101BC4_Copy12 { u32 a[3]; };

struct fn_1_101BC4_lbl_1_rodata_77F8 {
    u8 pad_0[0x38];
    struct fn_1_101BC4_Copy12 unk_38;
    u8 pad_44[4];
    const f64 unk_48;
    const f32 unk_50, unk_54, unk_58;
    u8 pad_5C[4];
    const f64 unk_60, unk_68;
    const f32 unk_70;
    u8 pad_74[4];
    const f64 unk_78, unk_80;
    const f64 unk_88;
    const f32 unk_90, unk_94, unk_98;
};

typedef struct Point1024C4 {
    u8 pad[0x10];
    f32 v[3];
} Point1024C4;

struct fn_1_101BC4_Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};

struct Sig_fn_80077B64_fn_80077B64_Arg0 {
    u8 pad_0[4]; u32 unk_4;
};

extern const struct fn_1_101BC4_lbl_1_rodata_77F8 lbl_1_rodata_77F8;
extern f32 fn_1_1024C4(const Point1024C4 *a, const Point1024C4 *b);
extern f64 __fabs(f64);
extern s32 fn_80077B14(struct fn_1_101BC4_Sig_fn_80077B14_fn_80077B14_Arg0 *);
extern void *fn_80077B64(struct Sig_fn_80077B64_fn_80077B64_Arg0 *);
extern u32 fn_1_4630();
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern void fn_1_10240C(u32 arg0, u32 arg1, s32 arg2);
extern void fn_80008BEC(void *dest, int value, u32 size);

typedef struct Sig_fn_1_1024C4_Point1024C4 {
    u8 pad[0x10]; f32 v[3];
} Sig_fn_1_1024C4_Point1024C4;

/* Preserve the ordered accesses of the chained vector copies. */
static inline void fn_1_101BC4_copy12(volatile struct fn_1_101BC4_Copy12 *dst, const volatile struct fn_1_101BC4_Copy12 *src) {
    *dst = *src;
}

void fn_1_101BC4(u32 arg0) {
    const struct fn_1_101BC4_lbl_1_rodata_77F8 *p_lbl_1_rodata_77F8;
    Obj_1_bss_85250 *p_lbl_1_bss_85250;
    struct { u32 value; } v0;
    u32 v4;
    u32 v2;
    f64 v3;
    f64 v5;
    u32 v6;
    struct { u32 value; } v1;
    u32 v6_2;
#define v1 v1.value
    u32 v7;
    u32 v8;
    s32 v9;
    u32 v11;
    s32 v14;
    u32 v12;
    u32 v13;
    u32 v10;
    f32 v15;
    f32 v16;
    u32 v17;
    u32 v18;
    u32 v19;
    u32 v20;
    u32 v21;
    u32 v22;
    u32 v23;
    u8 v24;
    u32 v26;
    u32 v27;
    f32 v28;
    f64 v29;
    f32 v30;
    f32 v31;
    u32 v33;
    u32 v35;
    u32 v37;
    u32 v39;
    f64 v40;
    u32 v41;
    u32 v44;
    f32 v46;
    f32 v45;
    u32 v47;
    u32 v48;
    u32 v49;
    f32 v50;
    u32 v51;
    u32 v52;
    f32 v53;
    u32 v54;
    u32 v55;
    u32 v59;
    u32 v60;
    u32 v61;
    f32 v62;
    u32 v63;
    u32 v64;
    f32 dz, dy, dx;
    p_lbl_1_rodata_77F8 = &lbl_1_rodata_77F8;
    p_lbl_1_bss_85250 = &lbl_1_bss_85250;
    if (arg0 != 0) {
        v7 = (u32)p_lbl_1_bss_85250->unk_18;
        if (v7 != 0) {
            fn_1_46B4(*(u32 *)&lbl_801A6410, v7, &lbl_1_data_3F17C, 281);
            p_lbl_1_bss_85250->unk_18 = 0;
        }
        v8 = (u32)p_lbl_1_bss_85250->unk_20;
        if (v8 != 0) {
            fn_1_46B4(*(u32 *)&lbl_801A6410, v8, &lbl_1_data_3F17C, 282);
            p_lbl_1_bss_85250->unk_20 = 0;
        }
        v1 = (u32)fn_80077B64((struct Sig_fn_80077B64_fn_80077B64_Arg0 *)arg0);
        v2 = fn_80077B14((struct fn_1_101BC4_Sig_fn_80077B14_fn_80077B14_Arg0 *)arg0);
        p_lbl_1_bss_85250->unk_18 = (Obj_1_bss_85250_At18 *)
            fn_1_4630(*(u32 *)&lbl_801A6410, *(u32 *)v1 * 68, &lbl_1_data_3F17C, 287);
        v3 = p_lbl_1_rodata_77F8->unk_48;
        v4 = 0;
        p_lbl_1_bss_85250->unk_1C = 0;
        while (v4 < *(u32 *)v1) {
            v10 = (u32)p_lbl_1_bss_85250->unk_18;
            v0.value = p_lbl_1_bss_85250->unk_1C;
            v14 = -1;
            v13 = v10;
            for (v12 = 0; v12 < v0.value; v12++, v13 += 68) {
                dx = *(f32 *)(v13 + 16);
                dy = *(f32 *)(v13 + 20);
                dz = *(f32 *)(v13 + 24);
                dx -= *(f32 *)v2;
                dy -= *(f32 *)(v2 + 4);
                dz -= *(f32 *)(v2 + 8);
                dx *= dx;
                dx = dy * dy + dx;
                dx = dz * dz + dx;
                if (dx < v3) {
                    v14 = v12;
                    break;
                }
            }
            if ((v14 + 0x10000U) != 65535) {
                v17 = v10 + v14 * 68;
                v0.value = ((Obj_1_bss_85250_At18 *)v17)->unk_2 << 1;
                *(u16 *)(v17 + v0.value + 4) = v4;
                ((Obj_1_bss_85250_At18 *)((u8 *)p_lbl_1_bss_85250->unk_18 + v14 * 68))->unk_2++;
            } else {
                v20 = v0.value * 68;
                v6 = v10 + v20;
                fn_1_101BC4_copy12((struct fn_1_101BC4_Copy12 *)(v6 + 40), (struct fn_1_101BC4_Copy12 *)v2);
                fn_1_101BC4_copy12((struct fn_1_101BC4_Copy12 *)(v6 + 28), (struct fn_1_101BC4_Copy12 *)(v6 + 40));
                fn_1_101BC4_copy12((struct fn_1_101BC4_Copy12 *)(v6 + 16), (struct fn_1_101BC4_Copy12 *)(v6 + 28));
                fn_1_101BC4_copy12((struct fn_1_101BC4_Copy12 *)(v6 + 52), &p_lbl_1_rodata_77F8->unk_38);
                ((Obj_1_bss_85250_At18 *)v6)->unk_0 = *(u8 *)(v2 + 53);
                ((Obj_1_bss_85250_At18 *)v6)->unk_2 = 1;
                fn_80008BEC((void *)(v6 + 4), 255, 10);
                ((Obj_1_bss_85250_At18 *)v6)->unk_4 = v4;
                ((Obj_1_bss_85250_At18 *)v6)->unk_40 = p_lbl_1_rodata_77F8->unk_50;
                p_lbl_1_bss_85250->unk_1C++;
            }
            v4++;
            v2 += 64;
        }
        v26 = (u32)p_lbl_1_bss_85250->unk_18;
        v27 = 0;
        while (v27 < p_lbl_1_bss_85250->unk_1C) {
            if ((((Obj_1_bss_85250_At18 *)v26)->unk_0 & 1) != 0) {
                ((Obj_1_bss_85250_At18 *)v26)->unk_0 = 1;
                v28 = p_lbl_1_rodata_77F8->unk_54;
                ((Obj_1_bss_85250_At18 *)v26)->unk_1 = 0;
                ((Obj_1_bss_85250_At18 *)v26)->unk_40 = v28;
            } else if (*(f32 *)(v26 + 16) > p_lbl_1_rodata_77F8->unk_58) {
                v29 = p_lbl_1_rodata_77F8->unk_60;
                ((Obj_1_bss_85250_At18 *)v26)->unk_1 = 1;
                v5 = ((Obj_1_bss_85250_At18 *)v26)->unk_18;
                if (v5 > v29 || v5 < p_lbl_1_rodata_77F8->unk_68) {
                    v28 = p_lbl_1_rodata_77F8->unk_54;
                    ((Obj_1_bss_85250_At18 *)v26)->unk_0 = 1;
                    ((Obj_1_bss_85250_At18 *)v26)->unk_40 = v28;
                }
                if (((Obj_1_bss_85250_At18 *)v26)->unk_14 > p_lbl_1_rodata_77F8->unk_70) {
                    v5 = __fabs(((Obj_1_bss_85250_At18 *)v26)->unk_18);
                    if (v5 > p_lbl_1_rodata_77F8->unk_78 && v5 < p_lbl_1_rodata_77F8->unk_80) {
                        v28 = p_lbl_1_rodata_77F8->unk_54;
                        ((Obj_1_bss_85250_At18 *)v26)->unk_0 = 1;
                        ((Obj_1_bss_85250_At18 *)v26)->unk_40 = v28;
                    }
                }
            } else if (((Obj_1_bss_85250_At18 *)v26)->unk_14 > p_lbl_1_rodata_77F8->unk_70) {
                ((Obj_1_bss_85250_At18 *)v26)->unk_1 = 2;
            } else if (((Obj_1_bss_85250_At18 *)v26)->unk_18 > p_lbl_1_rodata_77F8->unk_54) {
                ((Obj_1_bss_85250_At18 *)v26)->unk_1 = 3;
            } else {
                ((Obj_1_bss_85250_At18 *)v26)->unk_1 = 4;
            }
            v27++;
            v26 += 68;
        }
        v2 = 0;
        v33 = (u32)p_lbl_1_bss_85250->unk_18;
        while (v2 < p_lbl_1_bss_85250->unk_1C) {
            v12 = v2 + 1;
            v1 = (u32)p_lbl_1_bss_85250->unk_18 + v2 * 68 + 68;
            while (v12 < p_lbl_1_bss_85250->unk_1C) {
                if (((Obj_1_bss_85250_At18 *)v33)->unk_1 > ((Obj_1_bss_85250_At18 *)v1)->unk_1)
                    fn_1_10240C(v33, v1, 68);
                v12++;
                v1 += 68;
            }
            v2++;
            v33 += 68;
        }
        v2 = 0;
        v1 = (u32)p_lbl_1_bss_85250->unk_18;
        while (v2 < p_lbl_1_bss_85250->unk_1C) {
            v35 = (u32)p_lbl_1_bss_85250->unk_18 + v2 * 68 + 68;
            v6 = v2 + 1;
            while (v6 < p_lbl_1_bss_85250->unk_1C) {
                if (((Obj_1_bss_85250_At18 *)v1)->unk_1 == ((Obj_1_bss_85250_At18 *)v35)->unk_1 &&
                    ((Obj_1_bss_85250_At18 *)v1)->unk_14 > ((Obj_1_bss_85250_At18 *)v35)->unk_14)
                    fn_1_10240C(v1, v35, 68);
                v6++;
                v35 += 68;
            }
            v2++;
            v1 += 68;
        }
        v2 = 0;
        v1 = (u32)p_lbl_1_bss_85250->unk_18;
        v3 = p_lbl_1_rodata_77F8->unk_88;
        while (v2 < p_lbl_1_bss_85250->unk_1C) {
            v37 = (u32)p_lbl_1_bss_85250->unk_18 + v2 * 68 + 68;
            v6 = v2 + 1;
            while (v6 < p_lbl_1_bss_85250->unk_1C) {
                if (((Obj_1_bss_85250_At18 *)v1)->unk_1 == ((Obj_1_bss_85250_At18 *)v37)->unk_1 &&
                    __fabs((f32)(((Obj_1_bss_85250_At18 *)v1)->unk_14 - ((Obj_1_bss_85250_At18 *)v37)->unk_14)) < v3 &&
                    ((Obj_1_bss_85250_At18 *)v1)->unk_18 > ((Obj_1_bss_85250_At18 *)v37)->unk_18)
                    fn_1_10240C(v1, v37, 68);
                v6++;
                v37 += 68;
            }
            v2++;
            v1 += 68;
        }
        v2 = 0;
        v1 = (u32)p_lbl_1_bss_85250->unk_18;
        while (v2 < p_lbl_1_bss_85250->unk_1C) {
            v39 = (u32)p_lbl_1_bss_85250->unk_18 + v2 * 68 + 68;
            v6 = v2 + 1;
            while (v6 < p_lbl_1_bss_85250->unk_1C) {
                if (((Obj_1_bss_85250_At18 *)v1)->unk_1 == ((Obj_1_bss_85250_At18 *)v39)->unk_1) {
                    v40 = p_lbl_1_rodata_77F8->unk_88;
                    if (__fabs((f32)(((Obj_1_bss_85250_At18 *)v1)->unk_14 - ((Obj_1_bss_85250_At18 *)v39)->unk_14)) < v40 &&
                        __fabs((f32)(((Obj_1_bss_85250_At18 *)v1)->unk_18 - ((Obj_1_bss_85250_At18 *)v39)->unk_18)) < v40 &&
                        *(f32 *)(v1 + 16) > *(f32 *)(v39 + 16))
                        fn_1_10240C(v1, v39, 68);
                }
                v6++;
                v39 += 68;
            }
            v2++;
            v1 += 68;
        }
        v41 = p_lbl_1_bss_85250->unk_1C;
        p_lbl_1_bss_85250->unk_28 = 0;
        v44 = (u32)p_lbl_1_bss_85250->unk_18;
        p_lbl_1_bss_85250->unk_2C = 0;
        for (v11 = 0; v11 < v41 - 1; v11++) {
            if (((Obj_1_bss_85250_At18 *)v44)->unk_1 == 1 && ((Obj_1_bss_85250_At18 *)v44)->unk_45 == 1) {
                v45 = ((Obj_1_bss_85250_At18 *)v44)->unk_14;
                v46 = ((Obj_1_bss_85250_At18 *)v44)->unk_58;
                v5 = p_lbl_1_rodata_77F8->unk_88;
                if (__fabs((f32)(v45 - v46)) < v5) {
                    if (__fabs(v45) < v5 && __fabs(v46) < v5)
                        p_lbl_1_bss_85250->unk_28++;
                    p_lbl_1_bss_85250->unk_2C++;
                }
            }
            v44 += 68;
        }
        v47 = p_lbl_1_bss_85250->unk_28;
        v48 = p_lbl_1_bss_85250->unk_2C / v47 - 1;
        p_lbl_1_bss_85250->unk_2C = v48;
        v49 = v47 * (v48 + 1) + v48 * (v47 + 1);
        p_lbl_1_bss_85250->unk_24 = v49;
        p_lbl_1_bss_85250->unk_20 = (Obj_1_bss_85250_At20 *)
            fn_1_4630(*(u32 *)&lbl_801A6410, v49 * 24, &lbl_1_data_3F17C, 433);
        v2 = 0;
        v4 = (u32)p_lbl_1_bss_85250->unk_18;
        v6_2 = 0;
        while (v2 < p_lbl_1_bss_85250->unk_1C - 1) {
            if (((Obj_1_bss_85250_At18 *)v4)->unk_1 == 1 && ((Obj_1_bss_85250_At18 *)v4)->unk_45 == 1) {
                v50 = ((Obj_1_bss_85250_At18 *)v4)->unk_14;
                if (__fabs((f32)(v50 - ((Obj_1_bss_85250_At18 *)v4)->unk_58)) < p_lbl_1_rodata_77F8->unk_88) {
                    v51 = v4 + 68;
                    *(u32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24) = v4;
                    *(u32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24 + 4) = v51;
                    v15 = fn_1_1024C4( (const Point1024C4 *)((const Sig_fn_1_1024C4_Point1024C4 *)v4), (const Point1024C4 *)((const Sig_fn_1_1024C4_Point1024C4 *)v51));
                    v0.value = (u32)p_lbl_1_bss_85250->unk_20;
                    v53 = p_lbl_1_rodata_77F8->unk_90;
                    *(f32 *)(v0.value + v6_2 * 24 + 8) = v15;
                    v16 = p_lbl_1_rodata_77F8->unk_94;
                    v52 = (u32)p_lbl_1_bss_85250->unk_20;
                    v28 = p_lbl_1_rodata_77F8->unk_98;
                    *(f32 *)(v52 + v6_2 * 24 + 12) = v53;
                    *(f32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24 + 16) = v16;
                    *(f32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24 + 20) = v28;
                    v6_2++;
                }
            }
            v2++;
            v4 += 68;
        }
        v2 = 0;
        v4 = (u32)p_lbl_1_bss_85250->unk_18;
        v3 = p_lbl_1_rodata_77F8->unk_88;
        while (v2 < p_lbl_1_bss_85250->unk_1C) {
            v60 = v2 + 1;
            v59 = (u32)p_lbl_1_bss_85250->unk_18 + v2 * 68 + 68;
            for (; v60 < p_lbl_1_bss_85250->unk_1C; v60++, v59 += 68) {
                if (((Obj_1_bss_85250_At18 *)v4)->unk_1 == 1 && ((Obj_1_bss_85250_At18 *)v59)->unk_1 == 1 &&
                    __fabs((f32)(((Obj_1_bss_85250_At18 *)v4)->unk_18 - ((Obj_1_bss_85250_At18 *)v59)->unk_18)) < v3) {
                    *(u32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24) = v4;
                    *(u32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24 + 4) = v59;
                    v15 = fn_1_1024C4( (const Point1024C4 *)((const Sig_fn_1_1024C4_Point1024C4 *)v4), (const Point1024C4 *)((const Sig_fn_1_1024C4_Point1024C4 *)v59));
                    v0.value = (u32)p_lbl_1_bss_85250->unk_20;
                    v62 = p_lbl_1_rodata_77F8->unk_90;
                    *(f32 *)(v0.value + v6_2 * 24 + 8) = v15;
                    v16 = p_lbl_1_rodata_77F8->unk_94;
                    v52 = (u32)p_lbl_1_bss_85250->unk_20;
                    v28 = p_lbl_1_rodata_77F8->unk_98;
                    *(f32 *)(v52 + v6_2 * 24 + 12) = v62;
                    *(f32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24 + 16) = v16;
                    *(f32 *)((u32)p_lbl_1_bss_85250->unk_20 + v6_2 * 24 + 20) = v28;
                    v6_2++;
                    break;
                }
            }
            v2++;
            v4 += 68;
        }
    }
}
/* fzgx:end fn_1_101BC4 */

/* fzgx:begin fn_1_10240C */
struct fn_1_10240C_lbl_801A6410 {
    u32 unk_0;
};

void fn_1_10240C(u32 arg0, u32 arg1, s32 arg2) {
    u32 t0;
    t0 = fn_1_45D0(lbl_801A6410.unk_0, arg2, &lbl_1_data_3F17C, 561);
    fn_80008BA8(t0, arg0, arg2);
    fn_80008BA8(arg0, arg1, arg2);
    fn_80008BA8(arg1, t0, arg2);
    fn_1_46B4(lbl_801A6410.unk_0, t0, &lbl_1_data_3F17C, 565);
}
/* fzgx:end fn_1_10240C */

/* fzgx:begin fn_1_1024C4 */
typedef struct Point1024C4 {
    u8 pad[0x10];
    f32 v[3];
} Point1024C4;

f32 fn_1_1024C4(const Point1024C4 *a, const Point1024C4 *b) {
    f32 dz = a->v[2] - b->v[2];
    f32 dy = a->v[1] - b->v[1];
    f32 dx = a->v[0] - b->v[0];
    f32 result = dx * dx;
    result += dy * dy;
    result += dz * dz;
    return result;
}
/* fzgx:end fn_1_1024C4 */

/* fzgx:begin fn_1_1024F8 */
struct Obj1024F8 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

struct Slot8 {
    struct Obj1024F8 *ptr;
    u32 pad_4;
};

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} W3_1024F8;

typedef struct {
    W3_1024F8 v;
    u8 pad[0x34];
} Dst1024F8;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u16 unk_4[6];
    W3_1024F8 pos;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    W3_1024F8 vel;
    u8 pad_34[0x10];
} Node1024F8;

typedef struct {
    u8 pad_0[0x10];
    f32 x;
    f32 y;
    f32 z;
} NodeF1024F8;

extern f64 lbl_1_rodata_7898;
extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(u32);
extern s32 fn_80077B14(struct Obj1024F8 *);

#define ARR ((Node1024F8 *)p->unk_18)
#define N (&ARR[i])
#define B ((u8 *)N)
#define NF ((NodeF1024F8 *)B)

void fn_1_1024F8(void) {
    Obj_1_bss_85250 *p = (Obj_1_bss_85250 *)&lbl_1_bss_85250;
    struct Slot8 *tab;
    struct Obj1024F8 *obj;
    Dst1024F8 *out;
    u32 i;
    u32 j;
    f64 t;

    tab = (struct Slot8 *)p->unk_10->unk_8;
    obj = tab[p->unk_4].ptr;
    if (obj == 0) {
        return;
    }
    out = (Dst1024F8 *)fn_80077B14(obj);
    if (obj->unk_4 & 0x10) {
        for (i = 0; i < p->unk_1C; i++) {
            Node1024F8 *n = (Node1024F8 *)B;
            n->pos = n->vel;
            for (j = 0; j < N->unk_2; j++) {
                out[N->unk_4[j]].v = N->pos;
            }
        }
    }
    for (i = 0; i < p->unk_1C; i++) {
        if (N->unk_1 == 1 && (N->unk_0 & 1) == 0) {
            t = lbl_1_rodata_7898 * lbl_8006D188((s16)((lbl_801A66A0 + i * i) << 8));
            NF->x += t;
            t = lbl_1_rodata_7898 * lbl_8006D188((s16)(((lbl_801A66A0 + i * i + i) << 7) + 0x4000));
            NF->y += t;
            t = lbl_1_rodata_7898 * lbl_8006D188((s16)((lbl_801A66A0 + i * i * i) << 9));
            NF->z += t;
            for (j = 0; j < N->unk_2; j++) {
                out[N->unk_4[j]].v = N->pos;
            }
        }
    }
}
/* fzgx:end fn_1_1024F8 */

/* fzgx:begin fn_1_102750 */
typedef struct {
    f32 x, y, z;
} fn_1_102750_Vec;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u16 unk_4[6];
    fn_1_102750_Vec unk_10;
    fn_1_102750_Vec unk_1C;
    fn_1_102750_Vec unk_28;
    fn_1_102750_Vec unk_34;
    f32 unk_40;
} fn_1_102750_Node;

typedef struct {
    fn_1_102750_Node *unk_0;
    fn_1_102750_Node *unk_4;
    f32 unk_8;
    u8 pad_C[0xC];
} fn_1_102750_Edge;

typedef struct {
    fn_1_102750_Vec unk_0;
    u8 pad_C[0x34];
} fn_1_102750_Vertex;

typedef struct {
    u8 pad_0[0x8];
    struct Sig_fn_80077B14_fn_80077B14_Arg0 **unk_8;
} fn_1_102750_Table;

/* lbl_1_bss_85250 seen from here: node records of 0x44 bytes at unk_18, edges of 0x18 bytes at unk_20 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    fn_1_102750_Table *unk_10;
    u32 unk_14;
    fn_1_102750_Node *unk_18;
    u32 unk_1C;
    fn_1_102750_Edge *unk_20;
    u32 unk_24;
} fn_1_102750_State;

typedef struct {
    u8 pad_0[0x10];
    fn_1_102750_Vec unk_10;
} fn_1_102750_Camera;

struct Sig_fn_80077B14_fn_80077B14_Arg0;
extern fn_1_102750_Vertex *fn_80077B14(struct Sig_fn_80077B14_fn_80077B14_Arg0 *);
extern fn_1_102750_Camera *camera_get_state_object(void);
extern f32 lbl_8006D118(f32, f32 *);
extern f32 lbl_8006D0B4(f32);

/* retail .rodata 0x77F8-0x789F ahead of this function's constants, so they land at their retail offsets; the
 * function reuses the literal 1.0f (0x7888) */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_rodata_77F8[36] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFF0000FF, 0x00FF00FF, 0xFF0000FF, 0x00FF00FF, 0x41A00000, 0x42480000, 0x3F000000, 0x3F7FF972, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3E7AD7F2, 0x9ABCAF48, 0xBF800000, 0x00000000, 0x4187999A, 0x00000000, 0x3FFF3333, 0x33333333, 0xBFFF3333, 0x33333333, 0x3FC00000, 0x00000000, 0x3FE00000, 0x00000000, 0x3FE33333, 0x33333333, 0x3F1A36E2, 0xE0000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_77F8(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_77F8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_7888(void) { volatile f32 s; s = 1.0f; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_788C[5] = {0x3F8CCCCD, 0x3F733333, 0x00000000, 0x3F847AE1, 0x47AE147B};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_788C(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_788C; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

/* Cloth test mode 1 ("buranburan (dangling) mode" in the mode-name table), run by fn_1_10161C's switch on unk_14:
 * moves the nodes of kind 1 with bit 0 clear by their y velocity, which drops 0.0027 a step, pulls together the
 * two nodes of each edge whose squared length passes unk_8, pushes nodes out to 0.55 from the camera, stores each
 * node's displacement this step in unk_34 and copies the positions into the model's vertices */
void fn_1_102750(void) {
    fn_1_102750_State *st = (fn_1_102750_State *)&lbl_1_bss_85250;
    struct Sig_fn_80077B14_fn_80077B14_Arg0 *model;
    fn_1_102750_Vertex *out;
    fn_1_102750_Camera *cam;
    fn_1_102750_Edge *e;
    u32 i;
    u32 j;
    fn_1_102750_Node *n;

    model = st->unk_10->unk_8[st->unk_4 * 2];
    if (model == NULL) {
        return;
    }
    out = fn_80077B14(model);
    for (i = 0, n = st->unk_18; i < st->unk_1C; i++, n++) {
        if (n->unk_1 == 1 && (n->unk_0 & 1) == 0) {
            n->unk_1C = n->unk_10;
            n->unk_10.y += n->unk_34.y - 0.0013611111376020642;
            if (n->unk_10.y < 0.01f) {
                n->unk_10.y = 0.01f;
            }
            n->unk_34.y -= 0.0027222223579883575f;
        }
    }
    for (i = 0, e = st->unk_20; i < st->unk_24; i++, e++) {
        fn_1_102750_Node *a;
        fn_1_102750_Node *b;
        fn_1_102750_Vec delta;
        f32 len;
        fn_1_102750_Vec *dp = &delta;
        f32 y, z, x;
        f32 d;
        a = e->unk_0;
        b = e->unk_4;
        x = a->unk_10.x - b->unk_10.x;
        y = a->unk_10.y - b->unk_10.y;
        z = a->unk_10.z - b->unk_10.z;
        dp->x = x;
        dp->y = y;
        dp->z = z;
        d = x * x;
        d += y * y;
        d += z * z;
        len = d;
        if (len - 0.0001f > e->unk_8) {
            f32 inv, r, s, k, wa, wb;
            inv = lbl_8006D118(len, &len);
            r = lbl_8006D0B4(e->unk_8);
            s = inv * (len - r);
            len = s;
            dp->x *= s;
            dp->y *= s;
            dp->z *= s;
            k = 1.0f / (a->unk_40 + b->unk_40);
            wa = a->unk_40 * k;
            wb = b->unk_40 * k;
            a->unk_10.x -= (f32)(dp->x * wa);
            a->unk_10.y -= (f32)(dp->y * wa);
            a->unk_10.z -= (f32)(dp->z * wa);
            b->unk_10.x += (f32)(dp->x * wb);
            b->unk_10.y += (f32)(dp->y * wb);
            b->unk_10.z += (f32)(dp->z * wb);
        }
    }
    cam = camera_get_state_object();
    for (i = 0, e = st->unk_20; i < st->unk_24; i++, e++) {
        fn_1_102750_Node *a;
        fn_1_102750_Node *b;
        fn_1_102750_Vec v;
        f32 x, y, z, d;
        f32 da, db;
        s32 near;
        a = e->unk_0;
        b = e->unk_4;
        near = 0;
        z = a->unk_10.z - cam->unk_10.z;
        y = a->unk_10.y - cam->unk_10.y;
        x = a->unk_10.x - cam->unk_10.x;
        d = x * x;
        d += y * y;
        d += z * z;
        da = lbl_8006D0B4(d);
        z = b->unk_10.z - cam->unk_10.z;
        /* a compound subtraction here: it gives retail's float registers for this distance */
        y = b->unk_10.y;
        y -= cam->unk_10.y;
        x = b->unk_10.x - cam->unk_10.x;
        d = x * x;
        d += y * y;
        d += z * z;
        db = lbl_8006D0B4(d);
        if (da < 0.55f || db < 0.55f) {
            near = 1;
        }
        if (near) {
            da = 0.55f / da;
            db = 0.55f / db;
            if ((a->unk_0 & 1) == 0 && da > 1.0f) {
                v.x = a->unk_10.x - cam->unk_10.x;
                v.y = a->unk_10.y - cam->unk_10.y;
                v.z = a->unk_10.z - cam->unk_10.z;
                v.x *= da;
                v.y *= da;
                v.z *= da;
                a->unk_10.x = v.x + cam->unk_10.x;
                a->unk_10.y = v.y + cam->unk_10.y;
                a->unk_10.z = v.z + cam->unk_10.z;
            }
            if ((b->unk_0 & 1) == 0 && db > 1.0f) {
                v.x = b->unk_10.x - cam->unk_10.x;
                v.y = b->unk_10.y - cam->unk_10.y;
                v.z = b->unk_10.z - cam->unk_10.z;
                v.x *= db;
                v.y *= db;
                v.z *= db;
                b->unk_10.x = v.x + cam->unk_10.x;
                b->unk_10.y = v.y + cam->unk_10.y;
                b->unk_10.z = v.z + cam->unk_10.z;
            }
        }
    }
    for (i = 0, n = st->unk_18; i < st->unk_1C; i++, n++) {
        n->unk_34.x = n->unk_10.x - n->unk_1C.x;
        n->unk_34.y = n->unk_10.y - n->unk_1C.y;
        n->unk_34.z = n->unk_10.z - n->unk_1C.z;
    }
    for (i = 0, n = st->unk_18; i < st->unk_1C; i++, n++) {
        if (n->unk_1 == 1 && (n->unk_0 & 1) == 0) {
            for (j = 0; j < n->unk_2; j++) {
                out[n->unk_4[j]].unk_0 = n->unk_10;
            }
        }
    }
}
/* fzgx:end fn_1_102750 */

/* fzgx:begin fn_1_102C08 */
typedef struct {
    f32 x, y, z;
} fn_1_102C08_Vec;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u16 unk_4[6];
    fn_1_102C08_Vec unk_10;
    fn_1_102C08_Vec unk_1C;
    fn_1_102C08_Vec unk_28;
    fn_1_102C08_Vec unk_34;
    f32 unk_40;
} fn_1_102C08_Node;

typedef struct {
    fn_1_102C08_Node *unk_0;
    fn_1_102C08_Node *unk_4;
    f32 unk_8;
    u8 pad_C[0xC];
} fn_1_102C08_Edge;

typedef struct {
    fn_1_102C08_Vec unk_0;
    u8 pad_C[0x34];
} fn_1_102C08_Vertex;

typedef struct {
    u8 pad_0[0x8];
    struct Sig_fn_80077B14_fn_80077B14_Arg0 **unk_8;
} fn_1_102C08_Table;

/* lbl_1_bss_85250 seen from here: node records of 0x44 bytes at unk_18, edges of 0x18 bytes at unk_20 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    fn_1_102C08_Table *unk_10;
    u32 unk_14;
    fn_1_102C08_Node *unk_18;
    u32 unk_1C;
    fn_1_102C08_Edge *unk_20;
    u32 unk_24;
} fn_1_102C08_State;

struct Sig_fn_80077B14_fn_80077B14_Arg0;
extern fn_1_102C08_Vertex *fn_80077B14(struct Sig_fn_80077B14_fn_80077B14_Arg0 *);
extern f32 lbl_8006D118(f32, f32 *);
extern f32 lbl_8006D0B4(f32);

extern f32 lbl_1_bss_BF0[32];
extern void lbl_8006D758(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1B0(fn_1_102C08_Vec *, fn_1_102C08_Vec *);

/* retail .rodata 0x77F8-0x78B7 ahead of this function's constants, so they land at their retail offsets; the
 * function reuses the literals 0.0f (0x784C) and 1.0f (0x7888) and fn_1_102750's constants (0x78A0-0x78B4) */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_rodata_77F8[21] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFF0000FF, 0x00FF00FF, 0xFF0000FF, 0x00FF00FF, 0x41A00000, 0x42480000, 0x3F000000, 0x3F7FF972, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3E7AD7F2, 0x9ABCAF48, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_77F8(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_77F8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_784C(void) { volatile f32 s; s = 0.0f; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_7850[14] = {0x4187999A, 0x00000000, 0x3FFF3333, 0x33333333, 0xBFFF3333, 0x33333333, 0x3FC00000, 0x00000000, 0x3FE00000, 0x00000000, 0x3FE33333, 0x33333333, 0x3F1A36E2, 0xE0000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_7850(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_7850; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_7888(void) { volatile f32 s; s = 1.0f; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_788C[5] = {0x3F8CCCCD, 0x3F733333, 0x00000000, 0x3F847AE1, 0x47AE147B};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_788C(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_788C; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_78A0(void) { volatile f64 d; volatile f32 s; d = 0.0013611111376020642; s = 0.01f; s = 0.0027222223579883575f; s = 0.0001f; s = 0.55f; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

/* Cloth test mode 2 ("guruguru (spinning) mode (PAD1)" in the mode-name table), run by fn_1_10161C's switch on
 * unk_14: builds a matrix that turns by port 1's axis values (lbl_1_bss_BF0 port 1, values 2 and 3) between the
 * calls with (16.4, 0.75, 0) and (-16.4, -0.75, 0), steps the nodes of kind 1 with bit 0 clear as mode 1 does,
 * places every other node at its unk_28 point through that matrix, applies the edges, stores each node's
 * displacement this step in unk_34 and copies all positions into the model's vertices */
void fn_1_102C08(void) {
    fn_1_102C08_State *st = (fn_1_102C08_State *)&lbl_1_bss_85250;
    struct Sig_fn_80077B14_fn_80077B14_Arg0 *model;
    fn_1_102C08_Vertex *out;
    fn_1_102C08_Edge *e;
    u32 i;
    u32 j;
    fn_1_102C08_Node *n;
    f32 mtx[3][4];

    lbl_8006D758();
    lbl_8006E0B4(16.4f, 0.75f, 0.0f);
    mathutil_mtxA_rotate_y(32768.0f * lbl_1_bss_BF0[10]);
    mathutil_mtxA_rotate_z(32768.0f * lbl_1_bss_BF0[11]);
    lbl_8006E0B4(-16.4f, -0.75f, 0.0f);
    lbl_8006DB74(mtx);
    model = st->unk_10->unk_8[st->unk_4 * 2];
    if (model == NULL) {
        return;
    }
    out = fn_80077B14(model);
    for (i = 0, n = st->unk_18; i < st->unk_1C; i++, n++) {
        if (n->unk_1 == 1 && (n->unk_0 & 1) == 0) {
            n->unk_1C = n->unk_10;
            n->unk_10.y += n->unk_34.y - 0.0013611111376020642;
            if (n->unk_10.y < 0.01f) {
                n->unk_10.y = 0.01f;
            }
            n->unk_34.y -= 0.0027222223579883575f;
        }
    }
    for (i = 0, n = st->unk_18; i < st->unk_1C; i++, n++) {
        if (n->unk_1 != 1 || (n->unk_0 & 1) != 0) {
            lbl_8006D758();
            lbl_8006DFC4(mtx);
            lbl_8006E1B0(&n->unk_28, &n->unk_10);
        }
    }
    for (i = 0, e = st->unk_20; i < st->unk_24; i++, e++) {
        fn_1_102C08_Node *a;
        fn_1_102C08_Node *b;
        fn_1_102C08_Vec delta;
        f32 len;
        fn_1_102C08_Vec *dp = &delta;
        f32 y, z, x;
        f32 d;
        a = e->unk_0;
        b = e->unk_4;
        x = a->unk_10.x - b->unk_10.x;
        y = a->unk_10.y - b->unk_10.y;
        z = a->unk_10.z - b->unk_10.z;
        dp->x = x;
        dp->y = y;
        dp->z = z;
        d = x * x;
        d += y * y;
        d += z * z;
        len = d;
        if (len - 0.0001f > e->unk_8) {
            f32 inv, r, s, k, wa, wb;
            inv = lbl_8006D118(len, &len);
            r = lbl_8006D0B4(e->unk_8);
            s = inv * (len - r);
            len = s;
            dp->x *= s;
            dp->y *= s;
            dp->z *= s;
            k = 1.0f / (a->unk_40 + b->unk_40);
            wa = a->unk_40 * k;
            wb = b->unk_40 * k;
            a->unk_10.x -= (f32)(dp->x * wa);
            a->unk_10.y -= (f32)(dp->y * wa);
            a->unk_10.z -= (f32)(dp->z * wa);
            b->unk_10.x += (f32)(dp->x * wb);
            b->unk_10.y += (f32)(dp->y * wb);
            b->unk_10.z += (f32)(dp->z * wb);
        }
    }
    for (i = 0, n = st->unk_18; i < st->unk_1C; i++, n++) {
        n->unk_34.x = n->unk_10.x - n->unk_1C.x;
        n->unk_34.y = n->unk_10.y - n->unk_1C.y;
        n->unk_34.z = n->unk_10.z - n->unk_1C.z;
    }
    for (i = 0, n = st->unk_18; i < st->unk_1C; i++, n++) {
        for (j = 0; j < n->unk_2; j++) {
            out[n->unk_4[j]].unk_0 = n->unk_10;
        }
    }
}
/* fzgx:end fn_1_102C08 */

/* fzgx:begin fn_1_102FD0 */
// Initialize the cloth subsystem and reset its shared state.
void fn_1_102FD0(void) {
    fn_1_105744();
    fn_1_9D0EC(lbl_1_bss_3BE0->unk_54, lbl_1_bss_3BE0->unk_48,
               lbl_1_data_3F244, fn_1_106DB4);
    fn_1_103AA8();
    lbl_1_bss_85288[0] = -1;
    lbl_1_bss_85288[1] = -1;
}
/* fzgx:end fn_1_102FD0 */

/* fzgx:begin fn_1_10302C */
// fn_1_10302C: empty in retail (single blr).
void fn_1_10302C(void) {
}
/* fzgx:end fn_1_10302C */

/* fzgx:begin fn_1_103030 */
void fn_1_103030(void) {
    fn_1_103AD4();
    fn_1_105768();
}
/* fzgx:end fn_1_103030 */

/* fzgx:begin fn_1_103054 */
// fn_1_103054: empty in retail (single blr).
void fn_1_103054(void) {
}
/* fzgx:end fn_1_103054 */

/* fzgx:begin fn_1_103058 */
// Runs the cloth update unless the global state is one of the inactive modes.
void fn_1_103058(void) {
    s16 state = *(s16 *)(void *)&lbl_1_bss_960;

    if (state != 10 && state != 14) {
        fn_1_10576C();
    }
}
/* fzgx:end fn_1_103058 */

/* fzgx:begin fn_1_103090 */
typedef struct ClothState {
    u8 _pad68[0x68];
    void *field_68;
    u8 _pad6c[8];
    void *field_74;
    void *field_78;
    u8 field_7c;
} ClothState;

void fn_1_103090(ClothState *self) {
    self->field_74 = self->field_68;
    self->field_78 = &self->field_7c;
}
/* fzgx:end fn_1_103090 */

/* fzgx:begin fn_1_1030A4 */
typedef struct Cloth {
    u8 pad_00[0x68];
    s32 field_68;
    u8 field_6c[4];
    u8 field_70[1];
} Cloth;

void fn_1_1030A4(Cloth *self) {
    if (self->field_68 != 0) {
        fn_1_9E5B8(&self->field_70);
    }
}
/* fzgx:end fn_1_1030A4 */

/* fzgx:begin fn_1_1030D4 */
#include "fpscr.h"

typedef struct fn_1_1030D4_Anim {
    f32 start;
    f32 end;
    u8 pad_8[0x6C];
    u32 keys_x;
    u32 count_x;
    u8 pad_7C[0x10];
    u32 keys_y;
    u32 count_y;
    u8 pad_94[0x10];
    u32 keys_z;
    u32 count_z;
} fn_1_1030D4_Anim;

typedef struct fn_1_1030D4_Obj {
    u8 pad_0[0x18];
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u16 flags;
    u8 pad_20[0x10];
    fn_1_1030D4_Anim *anim;
} fn_1_1030D4_Obj;

typedef struct fn_1_1030D4_Arg {
    fn_1_1030D4_Obj *obj;
    u32 pad_4;
    u32 flags;
} fn_1_1030D4_Arg;

extern const f32 lbl_1_rodata_78D0;
extern const f32 lbl_1_rodata_78D4;
extern f32 fn_1_9E14C(u32, u32, f32);

void fn_1_1030D4(fn_1_1030D4_Arg *arg) {
    fn_1_1030D4_Obj *obj;
    fn_1_1030D4_Anim *anim;
    f32 t;
    f32 len;

    if (!((arg->flags >> 30) & 1)) {
        return;
    }
    obj = arg->obj;
    anim = obj->anim;
    if (obj == 0) {
        return;
    }
    if (anim == 0) {
        return;
    }
    t = lbl_1_data_2A7E0.unk_1C - anim->start;
    len = anim->end - anim->start;
    if (obj->flags & 1) {
        if (t > len) {
            t = len;
        }
    } else {
        t -= (f32)(len * (f32)fpscr_floor(t / len));
    }
    t += anim->start;
    t /= lbl_1_rodata_78D0;
    if (anim->count_x != 0) {
        obj->rot_x = lbl_1_rodata_78D4 * fn_1_9E14C(anim->keys_x, anim->count_x, t);
    }
    if (anim->count_y != 0) {
        obj->rot_y = lbl_1_rodata_78D4 * fn_1_9E14C(anim->keys_y, anim->count_y, t);
    }
    if (anim->count_z != 0) {
        obj->rot_z = lbl_1_rodata_78D4 * fn_1_9E14C(anim->keys_z, anim->count_z, t);
    }
}
/* fzgx:end fn_1_1030D4 */

/* fzgx:begin fn_1_1050D0 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "rel/main_rel/cloth.h"

/* begin dolphin/gx.h (deltawave784/fzgx, CC0) */
#ifndef DOLPHIN_GX_H
#define DOLPHIN_GX_H


/* The GX write-gather pipe: one memory-mapped port at GX_FIFO_BASE (dolphin/hw_regs.h), written through
   the member whose width the command needs. Declared as an MWCC absolute object: every store is
   emitted in order, addressed by literal (`lis rX, 0xCC01; stb rY, -0x8000(rX)`) with no
   relocation, and the named object cannot alias the `gx` context, which keeps retail's schedule.
   Proven by GXSetViewportJitter (fn_80038DE8) and GXSetFog (fn_800377F8). */
typedef union PPCWGPipe {
    u8 u8;
    u16 u16;
    u32 u32;
    s8 s8;
    s16 s16;
    s32 s32;
    f32 f32;
    f64 f64;
} PPCWGPipe;
typedef PPCWGPipe WGPipe;

volatile PPCWGPipe GXWGFifo : GX_FIFO_BASE; /* volatile: hardware port */

#define GX_WRITE_U8(v) (GXWGFifo.u8 = (u8)(v))
#define GX_WRITE_U16(v) (GXWGFifo.u16 = (u16)(v))
#define GX_WRITE_U32(v) (GXWGFifo.u32 = (u32)(v))
#define GX_WRITE_F32(v) (GXWGFifo.f32 = (f32)(v))

/* BP (raster) register write: command byte 0x61 followed by the register word. */
#define GX_WRITE_RAS_REG(value)  \
    do {                         \
        GXWGFifo.u8 = 0x61;      \
        GXWGFifo.u32 = (value);  \
    } while (0)

/* XF register write: command byte 0x10, then (count - 1) << 16 | address, then the data words. */
#define GX_WRITE_XF_REG_HDR(addr, count) \
    do {                                  \
        GXWGFifo.u8 = 0x10;               \
        GXWGFifo.u32 = (((count) - 1) << 16) | (addr); \
    } while (0)

#endif

/* end dolphin/gx.h */

typedef struct { f32 x, y, z; } Vec;

struct fn_1_1050D0_lbl_1_rodata_78D0 {
    u8 pad_0[0x4];
    f32 unk_4;
    u8 pad_8[0x8];
    f32 unk_10;
    u8 pad_14[0x4];
    f32 unk_18;
    u8 pad_1C[0x8];
    f32 unk_24;
    u8 pad_28[0xE4];
    f32 unk_10C;
};
extern struct fn_1_1050D0_lbl_1_rodata_78D0 lbl_1_rodata_78D0;
extern s32 fn_1_58C4(void);
extern s32 fn_1_5910(void);
extern u16 lbl_1_bss_85298[272];
extern u32 lbl_801A66A0;
extern void *lbl_801A6D00;
extern u32 camera_get_status(void);
extern u32 fn_1_7BEAC(u32);
extern u32 fn_1_F2F34(void);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DCA4(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E0A4(void *);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void fn_1_556B8(void *);
extern void fn_1_56000(u8, u8, u8);
extern void fn_1_560F0(s32, void *);
extern void fn_8003462C(u32, u32, u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072EDC(s32, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80074918(u8, s32, u8);
extern void fn_80077BBC(s32);
extern void lbl_8006D758(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E15C(f32, f32, f32);
#define __WGPIPE GXWGFifo.f32

void fn_1_1050D0(void) {
    struct fn_1_1050D0_lbl_1_rodata_78D0 *p_lbl_1_rodata_78D0 = &lbl_1_rodata_78D0;
    Vec *p_lbl_1_data_3F2EC;
    Obj_1_data_3F28C *p_lbl_1_data_3F28C;
    Obj_1_bss_38460 *p_lbl_1_bss_38460;
    u8 *state;
    s32 v3;
    s32 v19;
    s32 i;
    Vec loc[4];
    Obj_1_data_3F2EC *v4, *v5, *v6, *v9;

    state = (u8 *)lbl_1_bss_85298 + fn_1_5910() * 136;
    v3 = 0;
    if (state[127] == 0 && (s16)camera_get_status() == 1) {
    switch ((s32)fn_1_F2F34()) {
    case 0:
    if ((u32)fn_1_58C4() == 4) v3 = 1;
    fn_1_7BEAC(0);
    lbl_8006DCA4();
    lbl_8006E0A4(state);
    mathutil_mtxA_rotate_y(*(s16 *)(state + 128));
    lbl_8006DFC4(state + 72);
    fn_80072558();
    fn_800724C8();
    fn_8007245C(512);
    fn_80073678(1);
    fn_800734A8(0, 255, 255, 255);
    fn_80072EDC(0, 4);
    fn_800728A8(1, 0, 1, 0);
    fn_80074918(1, 7, 1);
    fn_80072864(1);
    for (i = 0; i < 6; i++) {
        p_lbl_1_data_3F28C = (Obj_1_data_3F28C *)((u8 *)&lbl_1_data_3F28C + i * 16);
        p_lbl_1_data_3F2EC = (Vec *)&lbl_1_data_3F2EC.unk_0;
        loc[0] = p_lbl_1_data_3F2EC[p_lbl_1_data_3F28C->unk_0];
        loc[1] = p_lbl_1_data_3F2EC[p_lbl_1_data_3F28C->unk_1];
        loc[2] = p_lbl_1_data_3F2EC[p_lbl_1_data_3F28C->unk_2];
        loc[3] = p_lbl_1_data_3F2EC[p_lbl_1_data_3F28C->unk_3];
        fn_8003462C(128, 0, 4);
        __WGPIPE = loc[0].x;
        __WGPIPE = loc[0].y;
        __WGPIPE = loc[0].z;
        __WGPIPE = loc[1].x;
        __WGPIPE = loc[1].y;
        __WGPIPE = loc[1].z;
        __WGPIPE = loc[2].x;
        __WGPIPE = loc[2].y;
        __WGPIPE = loc[2].z;
        __WGPIPE = loc[3].x;
        __WGPIPE = loc[3].y;
        __WGPIPE = loc[3].z;
    }
    fn_80072864(0);
    fn_1_56000(1, 1, 1);
    p_lbl_1_bss_38460 = &lbl_1_bss_38460;
    v19 = 0;
    goto loop_test; /* Test the pass limit before the first iteration. */
    do {
        lbl_8006DCA4();
        lbl_8006E0A4(state);
        mathutil_mtxA_rotate_y(*(s16 *)(state + 128));
        lbl_8006DFC4(state + 72);
        if (v19 == 1) {
            lbl_8006E15C(p_lbl_1_rodata_78D0->unk_24, p_lbl_1_rodata_78D0->unk_10, p_lbl_1_rodata_78D0->unk_10);
            fn_80077BBC(1);
        }
        lbl_8006DAEC();
        if (v19 != 2) {
            if (v3 == 0 || v19 != 0) {
                lbl_8006DBE4();
                mathutil_mtxA_rotate_x((s16)(((lbl_801A66A0 % 300) << 16) / 300));
                if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
                fn_80072558();
                fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 8));
            }
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s16)(-((lbl_801A66A0 % 300) << 16) / 300));
            if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 16));
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s16)(-((lbl_801A66A0 % 100) << 16) / 100));
            if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 24));
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s16)(((lbl_801A66A0 % 60) << 16) / 60));
            if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 32));
            lbl_8006DBE4();
            if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 40));
        }
        if (v19 == 0) {
            lbl_8006D758();
            fn_1_560F0(0, lbl_801A6D00);
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s32)(p_lbl_1_rodata_78D0->unk_4 * *(f32 *)(state + 120)));
            if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 48));
        } else if (v19 == 2) {
            lbl_8006D758();
            fn_1_560F0(0, lbl_801A6D00);
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s32)(p_lbl_1_rodata_78D0->unk_4 * *(f32 *)(state + 120)));
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 144));
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s32)(p_lbl_1_rodata_78D0->unk_4 * *(f32 *)(state + 120)));
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 56));
        } else if (v19 == 1) {
            lbl_8006D7F4(p_lbl_1_rodata_78D0->unk_10, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            lbl_8006E15C(p_lbl_1_rodata_78D0->unk_24, p_lbl_1_rodata_78D0->unk_10, p_lbl_1_rodata_78D0->unk_10);
            fn_1_560F0(0, lbl_801A6D00);
            lbl_8006DBE4();
            mathutil_mtxA_rotate_x((s32)(p_lbl_1_rodata_78D0->unk_4 * *(f32 *)(state + 120)));
            if (v3) lbl_8006E0B4(p_lbl_1_rodata_78D0->unk_10C, p_lbl_1_rodata_78D0->unk_18, p_lbl_1_rodata_78D0->unk_18);
            fn_80072558();
            fn_1_556B8((void *)*(u32 *)(p_lbl_1_bss_38460->unk_8->unk_8 + 48));
        }
        lbl_8006DB30();
        if (v19 == 1) fn_80077BBC(0);
        v19++;
loop_test:
        i = 2;
        if (v3 != 0) i = 1;
    } while (v19 <= i);
    fn_1_56000(1, 3, 1);
    }
    }
}
/* fzgx:end fn_1_1050D0 */

/* fzgx:begin fn_1_10688C noprologue */
#include "types.h"

extern s32 fn_1_465D0(char *, s32);
extern s32 fn_1_467F4(void);
extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern u32 fn_1_46C70(char *);
extern s32 fn_1_45730(char *, void *);
extern u32 fn_1_45B2C(void *);
extern u32 fn_1_45B68(void *);
extern void fn_1_45850(void *);
extern u32 fn_1_45D0(u32, u32, char *, s32);
extern u32 fn_1_4630(u32, u32, char *, s32);
extern int sprintf(char *, const char *, ...);
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern u32 lbl_801A6410;
extern u32 lbl_1_bss_38460[21];

/* local views of the two models this function reads from the common model list (lbl_1_bss_38460[2]): a texture
 * count at 0x18 and 0x20-byte texture records from 0x40, each with a GXTexObj pointer at 0x8 and a flag at 0xD */
typedef struct {
    u8 pad_0[0x8];
    void *unk_8;
    u8 pad_C;
    u8 unk_D;
    u8 pad_E[0x12];
} fn_1_10688C_Tex;

typedef struct {
    u8 pad_0[0x18];
    u16 unk_18;
    u8 pad_1A[0x26];
    fn_1_10688C_Tex unk_40[1];
} fn_1_10688C_Model;

/* the retail TU's .data objects this function uses, at their retail offsets, so MWCC addresses them and this
 * function's strings off one section base */
u8 fzgx_obj_lbl_1_data_3F188[0xC] = "OVERTAKE";
u8 fzgx_pool_gap_3F194[0xF0] = {1};
u32 fzgx_obj_lbl_1_data_3F284[2] = {1};
u8 fzgx_pool_gap_3F28C[0xC0] = {1};
char fzgx_obj_lbl_1_data_3F34C[0xC] = "bg_common.c";
u8 fzgx_pool_gap_3F358[0x24] = {1};

/* the retail TU's .bss objects from lbl_1_bss_85280, addressed off one section base */
u32 fzgx_obj_lbl_1_bss_85280;
u32 lbl_1_bss_85280__fzgx_offset_4;
u8 fzgx_pool_gap_85288[0x230];
u32 fzgx_obj_lbl_1_bss_854B8[4];
s32 lbl_1_bss_854B8__fzgx_offset_10;
u32 lbl_1_bss_854B8__fzgx_offset_14[210];
u8 fzgx_pool_gap_85814[0x20];
u32 lbl_1_bss_854B8__fzgx_offset_37C[210];
u32 lbl_1_bss_854B8__fzgx_offset_6C4;
u32 lbl_1_bss_854B8__fzgx_offset_6C8;
u32 lbl_1_bss_854B8__fzgx_offset_6CC;
u8 lbl_1_bss_854B8__fzgx_offset_6D0;
u8 lbl_1_bss_854B8__fzgx_offset_6D1;
u8 fzgx_pool_gap_85B8A;
u8 fzgx_pool_gap_85B8B;
u32 lbl_1_bss_854B8__fzgx_offset_6D4[3];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_85280;
    s = lbl_1_bss_85280__fzgx_offset_4;
    s = fzgx_pool_gap_85288[0];
    s = fzgx_obj_lbl_1_bss_854B8[0];
    s = lbl_1_bss_854B8__fzgx_offset_10;
    s = lbl_1_bss_854B8__fzgx_offset_14[0];
    s = fzgx_pool_gap_85814[0];
    s = lbl_1_bss_854B8__fzgx_offset_37C[0];
    s = lbl_1_bss_854B8__fzgx_offset_6C4;
    s = lbl_1_bss_854B8__fzgx_offset_6C8;
    s = lbl_1_bss_854B8__fzgx_offset_6CC;
    s = lbl_1_bss_854B8__fzgx_offset_6D0;
    s = lbl_1_bss_854B8__fzgx_offset_6D1;
    s = fzgx_pool_gap_85B8A;
    s = fzgx_pool_gap_85B8B;
    s = lbl_1_bss_854B8__fzgx_offset_6D4[0];
}
__declspec(section ".fzgxpool") static void fzgx_data_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_data_3F188[0];
    s = fzgx_pool_gap_3F194[0];
    s = fzgx_obj_lbl_1_data_3F284[0];
    s = fzgx_pool_gap_3F28C[0];
    s = fzgx_obj_lbl_1_data_3F34C[0];
    s = fzgx_pool_gap_3F358[0];
}
#pragma section code_type ".text"

void fn_1_10688C(void) {
    char name[0x80];
    u8 info[0x5C];
    fn_1_10688C_Model *models[2];
    s32 j;
    u32 *set;
    fn_1_10688C_Model *model;
    s16 k;
    s16 i;
    fn_1_10688C_Tex *tex;
    u32 size;

    fn_1_465D0("jpeg/compo.arc", 3);
    while (fn_1_467F4() != 0) {
        fn_1_451E4();
        fn_1_D3214();
    }
    lbl_1_bss_854B8__fzgx_offset_6C4 = fn_1_46C70("jpeg/compo.arc");
    lbl_1_bss_854B8__fzgx_offset_6C8 = 0;
    for (i = 0; i < 210; i++) {
        sprintf(name, "jpeg/compo/compo%03d.jpg", i + 1);
        if (fn_1_45730(name, info) == 0) {
            OSReport("file '%s' ", name);
            OSPanic(fzgx_obj_lbl_1_data_3F34C, 0x83A, "is not in ARAM");
        }
        lbl_1_bss_854B8__fzgx_offset_14[i] = fn_1_45B2C(info);
        lbl_1_bss_854B8__fzgx_offset_37C[i] = fn_1_45B68(info);
        fn_1_45850(info);
        if (lbl_1_bss_854B8__fzgx_offset_6C8 < lbl_1_bss_854B8__fzgx_offset_14[i]) {
            lbl_1_bss_854B8__fzgx_offset_6C8 = lbl_1_bss_854B8__fzgx_offset_14[i];
        }
    }
    if (lbl_1_bss_85280__fzgx_offset_4 != 0) {
        OSReport("already allocated jpeg_decode_ram!\n");
    } else {
        lbl_1_bss_85280__fzgx_offset_4 =
            fn_1_45D0(lbl_801A6410, lbl_1_bss_854B8__fzgx_offset_6C8, fzgx_obj_lbl_1_data_3F34C, 0x847);
    }
    size = GXGetTexBufferSize(0x80, 0x80, 6, 0, 0);
    lbl_1_bss_854B8__fzgx_offset_6CC = size;
    if (fzgx_obj_lbl_1_data_3F284[0] != 0 || fzgx_obj_lbl_1_data_3F284[1] != 0 || fzgx_obj_lbl_1_bss_85280 != 0) {
        OSReport("already allocated jpeg_buff!\n");
    } else {
        fzgx_obj_lbl_1_data_3F284[0] = fn_1_4630(lbl_801A6410, size, fzgx_obj_lbl_1_data_3F34C, 0x84F);
        fzgx_obj_lbl_1_data_3F284[1] =
            fn_1_4630(lbl_801A6410, lbl_1_bss_854B8__fzgx_offset_6CC, fzgx_obj_lbl_1_data_3F34C, 0x850);
        fzgx_obj_lbl_1_bss_85280 = fn_1_4630(lbl_801A6410, 0x4000, fzgx_obj_lbl_1_data_3F34C, 0x851);
    }
    lbl_1_bss_854B8__fzgx_offset_6D0 = 0;
    lbl_1_bss_854B8__fzgx_offset_6D1 = 0;
    lbl_1_bss_854B8__fzgx_offset_10 = 1;
    set = *(u32 **)(lbl_1_bss_38460[2] + 8);
    models[0] = (fn_1_10688C_Model *)set[0x30 / 4];
    models[1] = (fn_1_10688C_Model *)set[0x38 / 4];
    for (j = 0; j < 2; j++) {
        model = models[j];
        tex = model->unk_40;
        for (k = 0; k < model->unk_18; k++) {
            if (tex->unk_D == 1) {
                lbl_1_bss_854B8__fzgx_offset_6D4[lbl_1_bss_854B8__fzgx_offset_6D1++] = (u32)tex->unk_8;
                GXInitTexObj(tex->unk_8, (void *)fzgx_obj_lbl_1_data_3F284[lbl_1_bss_854B8__fzgx_offset_6D0], 0x80,
                             0x80, 6, 0, 0, 0);
            }
            tex++;
        }
    }
}
/* fzgx:end fn_1_10688C */

/* fzgx:begin fn_1_106CAC */
extern s32 fn_1_151AF0(void *arg0, int arg1, void *arg2, void *arg3, void *arg4, void *arg5);

s32 fn_1_106CAC(void) {
    Obj_1_bss_85280 *base = &lbl_1_bss_85280;

    if (*(s32 *)((u8 *)base + 0x248) == 2) {
        return 0;
    }

    fn_1_151AF0((void *)base->unk_4, 0, (void *)((u32 *)&lbl_1_data_3F284)[*(u8 *)((u8 *)base + 0x908)], 0, 0, (void *)base->unk_0);
    *(u8 *)((u8 *)base + 0x908) = 1 - *(u8 *)((u8 *)base + 0x908);
    *(s32 *)((u8 *)base + 0x248) = 1;
    return 0;
}
/* fzgx:end fn_1_106CAC */
