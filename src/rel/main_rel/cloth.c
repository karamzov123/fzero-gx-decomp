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
