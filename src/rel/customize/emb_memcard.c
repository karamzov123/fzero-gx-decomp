#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/emb_memcard.h"


extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;
extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_C1394(u32 *arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, u32 arg3);
extern u32 lbl_3_rodata_288[60];
extern void lbl_8006DCA4(void);
extern void lbl_8006E1D8(struct Vec3 *, f32, f32, f32);
extern void fn_1_7BCCC(struct Vec3 *);
extern void fn_80035680(struct GXLightObj *, f32, f32, f32);
extern void fn_80035690(struct GXLightObj *, f32, f32, f32);
extern void fn_80035420(struct GXLightObj *, f32, int);
extern void fn_800356AC(struct GXLightObj *, u32 *);
extern void GXInitLightDistAttn(struct GXLightObj *, f32, f32, int);
extern void fn_1_7BB80(struct GXLightObj *, int);
extern void fn_1_7BD6C(int);
extern void fn_80074CF4(f32, f32, f32);

/* fzgx:begin fn_3_C328 noprologue */
#include "types.h"

extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;
extern char lbl_3_data_1A30[14];
extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_C1394(u32 *arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, u32 arg3);

void fn_3_C328(void) {
    u32 *state;

    if (!fn_1_B7C00()) {
        state = lbl_3_bss_7ED58;
        fn_1_C1394(state);
        if (state[2] != 0) {
            fn_1_46B4(lbl_801A6410, state[2], lbl_3_data_1A30, 0x154);
            state[2] = 0;
            state[3] = 0;
        }
        lbl_3_data_1A18 = 0;
    }
}
/* fzgx:end fn_3_C328 */

/* fzgx:begin fn_3_E5D4 pool noprologue */
#include "types.h"

extern f32 lbl_3_rodata_378[84];
extern u8 lbl_3_bss_7EE40[33216];

typedef struct CustomizeSlot {
    u8 pad[5];
    u8 field5;
    u8 tail[0x81c0 - 6];
} CustomizeSlot;

typedef struct CustomizeHead {
    u8 pad_1c[0x1c];
    s16 unk_1c;
    u8 pad_1e[0x28];
    u8 unk_46;
    u8 pad_47[0x21];
} CustomizeHead;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
CustomizeSlot *fzgx_obj_lbl_3_bss_7EDC0;
u32 lbl_3_bss_7EDC0__fzgx_offset_4;
u32 lbl_3_bss_7EDC0__fzgx_offset_8;
u32 lbl_3_bss_7EDC0__fzgx_offset_C;
u32 lbl_3_bss_7EDC0__fzgx_offset_10;
u32 lbl_3_bss_7EDC0__fzgx_offset_14;
CustomizeHead lbl_3_bss_7EDC0__fzgx_offset_18;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = (u32)fzgx_obj_lbl_3_bss_7EDC0;
    s = lbl_3_bss_7EDC0__fzgx_offset_4;
    s = lbl_3_bss_7EDC0__fzgx_offset_8;
    s = lbl_3_bss_7EDC0__fzgx_offset_C;
    s = lbl_3_bss_7EDC0__fzgx_offset_10;
    s = lbl_3_bss_7EDC0__fzgx_offset_14;
    s = lbl_3_bss_7EDC0__fzgx_offset_18.unk_46;
}
#pragma section code_type ".text"

extern void fn_1_870BC(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, f32 arg5);
extern s16 fn_3_F948(void *arg0);
extern void fn_1_87238(u32 arg0, u32 arg1, f32 arg2);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);
extern void fn_1_151BDC(void *arg0);
extern u32 fn_1_14E2DC(u32 arg0, u32 arg1, f32 arg2);

void fn_3_E5D4(void) {
    u8 work[0x440] __attribute__((aligned(32)));

    if (fzgx_obj_lbl_3_bss_7EDC0[lbl_3_bss_7EDC0__fzgx_offset_18.unk_46].field5 < 0x29) {
        fn_1_870BC(lbl_3_bss_7EDC0__fzgx_offset_C, 0, lbl_3_bss_7EDC0__fzgx_offset_C, 0, 1, ((0)[lbl_3_rodata_378]));
        if (fn_3_F948(lbl_3_bss_7EE40 + 0x20) && lbl_3_bss_7EDC0__fzgx_offset_18.unk_1c == 0) {
            fn_1_87238(lbl_3_bss_7EDC0__fzgx_offset_C, 0, lbl_3_rodata_378[0]);
        }
    } else {
        fn_80008BEC(work, 0, 0x440);
        *(u32 *)(work + 0x390) |= 0x4000000;
        *(u32 *)(work + 0x3a0) = lbl_3_bss_7EDC0__fzgx_offset_8;
        *(u32 *)(work + 0x3a4) = lbl_3_bss_7EDC0__fzgx_offset_10;
        *(u16 *)(work + 0x3ba) = 0;
        fn_1_151BDC(lbl_3_bss_7EE40);
        fn_1_14E2DC(lbl_3_bss_7EDC0__fzgx_offset_8, 0, lbl_3_rodata_378[0]);
    }
}
/* fzgx:end fn_3_E5D4 */

/* fzgx:begin fn_3_F878 */
struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct GXLightObj {
    u32 dummy[16];
};

struct CustomizeData {
    u8 pad34[0x34];
    f32 value34;
    u8 pad1ac[0x174];
    f32 value1ac;
    u8 pad1bc[0xc];
    u32 value1bc;
    f32 value1c0;
};

void fn_3_F878(void) {
    struct GXLightObj second;
    struct Vec3 first;
    u32 value;
    f32 scale;
    struct CustomizeData *data;

    data = (struct CustomizeData *)lbl_3_rodata_288;
    lbl_8006DCA4();
    scale = data->value1c0;
    lbl_8006E1D8(&first, scale, scale, scale);
    fn_1_7BCCC(&first);
    fn_80035680(&second, first.x, first.y, first.z);
    fn_80035690(&second, first.x, first.y, first.z);
    fn_80035420(&second, data->value34, 0);
    value = data->value1bc;
    fn_800356AC(&second, &value);
    GXInitLightDistAttn(&second, data->value34, data->value34, 0);
    fn_1_7BB80(&second, 1);
    fn_1_7BD6C(1);
    scale = data->value1ac;
    fn_80074CF4(scale, scale, scale);
}
/* fzgx:end fn_3_F878 */

/* fzgx:begin fn_3_F948 */
typedef struct MemCardSlot {
    u32 unk0;
    u32 flags;
    u8 pad[0x2058];
} MemCardSlot;

s16 fn_3_F948(MemCardSlot *slot) {
    s16 i;
    s16 count = 0;
    i = 0;

    while (i < 4) {
        if (slot->flags & (1u << 31)) {
            count++;
        }
        slot++;
        i++;
    }
    return count;
}
/* fzgx:end fn_3_F948 */

/* fzgx:begin fn_3_11FD0 */
u32 fn_3_11FD0(u32 index, u32 value) {
    return ((u32 *)(lbl_3_data_2F78 + (__cntlzw(value) * 24)))[index];
}
/* fzgx:end fn_3_11FD0 */

/* fzgx:begin fn_3_12910 noprologue */
#include "types.h"

struct fn_3_12910_tbl_ent {
    u8 pad_0[0x8];
    u32 unk_8;
};
struct fn_3_12910_glb {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[0xE];
    s16 unk_22;
    s16 unk_24;
};

extern u8 lbl_3_bss_7EDD8[52];
extern u8 lbl_3_data_3234[168];

#pragma opt_dead_assignments off
void fn_3_12910(void) {
    struct fn_3_12910_glb *p;
    struct fn_3_12910_tbl_ent *t;
    u32 f;
    u32 idx;

    t = (struct fn_3_12910_tbl_ent *)lbl_3_data_3234;
    p = (struct fn_3_12910_glb *)lbl_3_bss_7EDD8;
    idx = __cntlzw(p->unk_C);
    ((void (*)(void))(*(u32 *)((u8 *)lbl_3_data_3234 + idx * 12 + 8)))();

    f = p->unk_C;
    if (!(f & 0x80000000)) {
        if (f & 0x2000000) {
            s32 v = ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 - 1;

            ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 = (v < -15) ? -15 : ((v > 30) ? 30 : v);
        } else if (f & 0x1000000) {
            if (((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_10 & 0x2000000) {
                s32 v = ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 + 1;

                ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 = (v < -15) ? -15 : ((v > 0) ? 0 : v);
            } else {
                s32 v = ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 - 1;

                ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 = (v < 0) ? 0 : ((v > 30) ? 30 : v);
            }
        } else if (f & 0x400000) {
            s32 v = ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 - 1;

            ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 = (v < 0) ? 0 : ((v > 30) ? 30 : v);
        } else if (!(f & 0x800000)) {
            s32 v = ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 + 1;

            ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 = (v < -15) ? -15 : ((v > 30) ? 30 : v);
        }

        f = p->unk_C;
        if (f & 0x40000000) {
            s32 v = ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_22 - 1;

            ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_22 = (v < 0) ? 0 : ((v > 10) ? 10 : v);
        } else if (f & 0x20000000) {
            s32 v = ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_22 + 1;

            ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_22 = (v < 0) ? 0 : ((v > 10) ? 10 : v);
        }
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_3_12910 */

/* fzgx:begin fn_3_12E4C */
typedef struct { u32 x; u32 y; u32 z; } Vec3;
typedef struct { u32 unused0; u32 unused1; Vec3 first; Vec3 second; } Data;
typedef struct { u8 pad_000[0x508]; Vec3 first; Vec3 second; } SpecialData;
typedef struct {
    u8 pad_000[0x328];
    s8 state;
    u8 pad_329[0x67];
    u32 flags;
    u8 pad_394[0xc];
    s16 *indices;
} Customize;

#pragma opt_strength_reduction off
#pragma opt_common_subs off
void fn_3_12E4C(Customize *self, u8 index, Vec3 *first, Vec3 *second) {
    Data *data;
    SpecialData *special;
    u8 state;

    if (self->flags & 0x04000000) {
        data = (Data *)(*(u8 (*)[2400])&lbl_3_data_246C);
        data = (Data *)((u8 *)data +
                        ((u8)((self->indices)[(u32)index * 0x1b0]) << 5));
        *first = data->first;
        *second = data->second;
        return;
    }

    state = self->state;
    if (state == 4) {
        if (index != 0) {
            data = (Data *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + 0x560);
            *first = data->first;
            *second = data->second;
            return;
        }
        data = (Data *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + ((u8)state << 5));
        *first = data->first;
        *second = data->second;
        return;
    }

    if ((u8)state == 0x28) {
        special = (SpecialData *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + ((u8)index << 5));
        *first = special->first;
        *second = special->second;
        return;
    }

    data = (Data *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + ((u8)state << 5));
    *first = data->first;
    *second = data->second;
}
#pragma opt_common_subs reset

#pragma opt_strength_reduction reset
/* fzgx:end fn_3_12E4C */

/* fzgx:begin fn_3_12FD4 */
struct fn_3_12FD4_Arg3 {
    f32 unk_0;
};
struct fn_3_12FD4_Arg4 {
    f32 unk_0;
};

struct fn_3_12FD4_Record {
    f32 x;
    f32 y;
    u8 pad[24];
};

void fn_3_12FD4(u32 arg0, u32 arg1, u32 arg2, struct fn_3_12FD4_Arg3 *arg3, struct fn_3_12FD4_Arg4 *arg4) {
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    if (__rlwnm(arg0, 6, 31, 31)) {
        v1 = ((arg2 & 0xFF) << 5);
        arg3->unk_0 = *(f32 *)((u8 *)&lbl_3_data_246C + v1);
        arg4->unk_0 = *(f32 *)((u32)&lbl_3_data_246C + v1 + 4);
        return;
    }
    v2 = (arg2 & 0xFF);
    v3 = arg2;
    if (v2 == 4) {
        v3 = 43;
    } else {
        if (v2 == 40) {
            v3 = ((arg1 + 40) & 0xFF);
        }
    }
    v4 = ((v3 & 0xFF) << 5);
    arg3->unk_0 = *(f32 *)((u8 *)&lbl_3_data_1EEC + v4);
    arg4->unk_0 = *(f32 *)((u32)&lbl_3_data_1EEC + v4 + 4);
    return;
}
/* fzgx:end fn_3_12FD4 */
