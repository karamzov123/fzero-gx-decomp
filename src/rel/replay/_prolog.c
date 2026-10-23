#include "types.h"
#include "rel/replay/globals.h"

extern u32 fn_1_D0790(void);
extern u32 lbl_13_bss_38;
extern int fn_13_A40(void);
extern s32 fn_13_A48(void);
extern s16 lbl_1_bss_962;
extern struct fn_13_B08_lbl_13_data_18 lbl_13_data_18;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 lbl_1_bss_26C60;
extern void fn_13_3FC(void);
extern u32 fn_1_3F038(void);
extern u32 lbl_13_bss_40;
extern u8 lbl_13_bss_3C;
extern u32 lbl_1_bss_7167C;
extern u32 lbl_1_bss_71680;
extern u32 lbl_1_bss_71684;
extern u16 lbl_1_bss_96A;
extern void fn_13_AFC(void);
extern void fn_13_B00(void);
extern void fn_13_B08(void);
extern void fn_1_A8F78(void);

/* fzgx:begin fn_13_0 noprologue */
#include "types.h"

struct fn_13_0_Entry {
    u8 unk_0; u8 unk_1; u8 unk_2; u8 unk_3; u8 unk_4; u8 unk_5;
    u8 unk_6[5]; u8 unk_B;
};
struct fn_13_0_Bss {
    u32 unk_0; s32 unk_4; struct fn_13_0_Entry unk_8[1];
};
struct fn_13_0_Slot { u8 unk_0; u8 unk_1; u8 unk_2; u8 unk_3; u8 unk_4; };
struct fn_13_0_Ghost { u8 unk_0[4]; u8 unk_4[0x81BC]; };
struct fn_13_0_lbl_1_bss_8B3A0 { u8 pad_0[0x8]; u16 unk_8; };
struct fn_13_0_lbl_1_bss_7EFD8 {
    u8 pad_0[0x8]; u32 unk_8; u8 pad_C[0x2C]; u8 unk_38[4]; u8 unk_3C[4];
};
extern struct fn_13_0_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern struct fn_13_0_lbl_1_bss_7EFD8 lbl_1_bss_7EFD8;
extern u32 lbl_801A63C0;
extern u32 lbl_801A63D0;
extern struct fn_13_0_Slot lbl_1_bss_26B80[];
extern u32 fn_1_F453C(u32, u32 *, u32);
extern struct fn_13_0_Ghost *fn_1_36AD0(void);
extern void fn_1_F47A0(u32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_1_12F10C(struct fn_13_0_Ghost *);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_3EF8C(int);
extern void fn_1_3ED8C(int, u8, int, u8, int, u8, int);
extern void fn_1_3EB78(int, u8 *, u8 *, int);
extern void fn_1_3EC88(int, void *);
extern void fn_1_3EFF0(void *, int);
extern void fn_1_3FCB0(s32);
extern void fn_1_3FCD4(s32);
extern void fn_13_A6C(void *);
u32 fzgx_obj_lbl_13_bss_0;
u32 lbl_13_bss_4;
u32 lbl_13_bss_4__fzgx_offset_4;
u8 lbl_13_bss_4__fzgx_offset_8;
u16 lbl_13_bss_4__fzgx_offset_A;
u32 lbl_13_bss_4__fzgx_offset_C[10];
u32 lbl_13_bss_38;
u8 lbl_13_bss_3C;
u8 fzgx_pool_lbl_13_bss_0_gap_3D;
u16 fzgx_pool_lbl_13_bss_0_gap_3D_fill_3E;
u32 lbl_13_bss_40[3];
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    /* volatile keeps the synthetic storage objects so the compiler cannot elide them */
    volatile u8 s;
    s = *(u8 *)&fzgx_obj_lbl_13_bss_0;
    s = *(u8 *)&lbl_13_bss_4;
    s = *(u8 *)&lbl_13_bss_4__fzgx_offset_4;
    s = *(u8 *)&lbl_13_bss_4__fzgx_offset_8;
    s = *(u8 *)&lbl_13_bss_4__fzgx_offset_A;
    s = *(u8 *)&lbl_13_bss_4__fzgx_offset_C;
    s = *(u8 *)&lbl_13_bss_38;
    s = *(u8 *)&lbl_13_bss_3C;
    s = *(u8 *)&fzgx_pool_lbl_13_bss_0_gap_3D;
    s = *(u8 *)&fzgx_pool_lbl_13_bss_0_gap_3D_fill_3E;
    s = *(u8 *)&lbl_13_bss_40;
}
#pragma section code_type ".text"
static inline u8 * fn_13_0_read_pointer(struct fn_13_0_lbl_1_bss_7EFD8 * owner) { return owner->unk_3C; }
#pragma opt_lifetimes off
#pragma opt_dead_assignments off
void fn_13_0(void) {
    u8 fzgx_value;
    u8 idx;
    u32 count;
    u32 i;
    int n;
    u32 t2;
    u8 unk22;
    u8 flag;
    u8 ver;
    int k;
    u32 j;
    struct { u8 value; } b;
    u8 locC[4];
    u8 loc8[4];
    struct fn_13_0_Entry *e;
    u32 t0;
    lbl_13_bss_4 = 0;
    fzgx_obj_lbl_13_bss_0 = lbl_801A63D0;
    fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 8);
    ver = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 7);
    t2 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 6);
    fn_1_F47A0(fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 32));
    t0 = fzgx_obj_lbl_13_bss_0;
    lbl_801A63C0 = fn_1_F453C(t0, &lbl_13_bss_4, 32);
    count = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 5);
    lbl_1_bss_8B3A0.unk_8 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 3);
    fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 2);
    flag = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 1);
    unk22 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 7);
    n = 0;
    for (i = 0; i < count; i++) {
        (*((((i)) + ((lbl_1_bss_26B80))))).unk_0 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 1);
        (*((lbl_1_bss_26B80) + (i))).unk_1 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 6);
        if (ver >= 3) {
            (*((lbl_1_bss_26B80) + (i))).unk_4 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 5);
        }
        if (ver >= 2) {
            (*((lbl_1_bss_26B80) + (i))).unk_3 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 7);
        }
        if ((*((lbl_1_bss_26B80) + (i))).unk_0 != 0) {
            (*((lbl_1_bss_26B80) + (i))).unk_2 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 2);
            if (ver < 2) {
                (*((((i)) + ((lbl_1_bss_26B80))))).unk_3 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 7);
            }
            idx = (u8)n;
            locC[idx] = (*((lbl_1_bss_26B80) + (i))).unk_1;
            loc8[idx] = (*((lbl_1_bss_26B80) + (i))).unk_2;
            if ((u8)fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 1) != 0) {
                for (j = 0; j < 0x81C0; j++) {
                    b.value = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 8);
                    ((u8 *)&fn_1_36AD0()[i])[j] = b.value;
                }
                t0 = (u32)fn_1_36AD0()[i].unk_4;
                fn_80008BA8(&((struct fn_13_0_Entry *)((u8 *)&lbl_13_bss_4__fzgx_offset_4))[idx], (void *)t0, 0xC);
                fn_1_12F10C(fn_1_36AD0());
            } else {
                e = &((struct fn_13_0_Entry *)((u8 *)&lbl_13_bss_4__fzgx_offset_4))[idx];
                fzgx_value = (*((lbl_1_bss_26B80) + (i))).unk_1;
                e->unk_1 = fzgx_value;
                e->unk_2 = 1 << (*((lbl_1_bss_26B80) + (i))).unk_2;
                e->unk_B = (*((lbl_1_bss_26B80) + (i))).unk_3;
                e->unk_4 = 0;
                e->unk_3 = 0;
                e->unk_5 = 0;
                e->unk_0 = 0;
                fn_80008BEC(((struct fn_13_0_Entry *)((u8 *)&lbl_13_bss_4__fzgx_offset_4))[i].unk_6, 0x41, 5);
            }
            n++;
        } else {
            (*((lbl_1_bss_26B80) + (i))).unk_2 = 0;
            (*((lbl_1_bss_26B80) + (i))).unk_3 = 0;
        }
    }
    if (ver >= 4) {
        for (k = 0; k < (u8)n; k++) {
            fn_13_0_read_pointer(&lbl_1_bss_7EFD8)[k] = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 1);
        }
    }
    for (k = 0; k < (u8)n; k++) {
        lbl_1_bss_7EFD8.unk_38[k] = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 2) + 1;
    }
    if (ver >= 5) {
        lbl_1_bss_7EFD8.unk_8 = fn_1_F453C(fzgx_obj_lbl_13_bss_0, &lbl_13_bss_4, 20);
    }
    fn_1_3EF8C(6);
    fn_1_3ED8C(0, unk22, 1, (u8)t2, 10, (u8)count, 0);
    fn_1_3EB78(n, locC, loc8, 0);
    fn_1_3EC88(n, (u8 *)&lbl_13_bss_4__fzgx_offset_4);
    fn_1_3EFF0(fn_13_A6C, 1);
    if (flag != 0) {
        fn_1_3FCB0(0x20000);
    } else {
        fn_1_3FCD4(0x20000);
    }
    fn_1_3FCB0(0x800000);
}
#pragma opt_dead_assignments reset
#pragma opt_lifetimes reset
/* fzgx:end fn_13_0 */

/* fzgx:begin fn_13_3FC */
#include "rel/main_rel/globals.h"
#include "rel/replay/replay_mode.h"

extern u32 lbl_13_bss_4;
extern u32 fn_1_F453C(u32 stream, u32 *pos, u32 bits);
extern void fn_1_3EF14(void *header);
extern void fn_1_F4794(u16 count);
extern void fn_80008BA8(void *dst, void *src, u32 size);

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} ReplayVec;

typedef struct {
    u32 a : 15;
    u32 c : 3;
    u32 d : 5;
    u32 e : 5;
    u32 pad0 : 4;
    u32 b : 15;
    u32 f : 5;
    u32 g : 5;
    u32 h : 5;
    u32 pad1 : 2;
    ReplayVec pos[4];
    ReplayVec rot[4];
    ReplayVec v68;
    ReplayVec v74;
} ReplayEntry;

typedef struct {
    u8 pad0[0xA0];
    u16 count;
    u16 padA2;
    u8 rec[(0xFEF0 - 0xA4) / 7][7];
    u16 numEntries;
    u8 padF2[0x5A];
    ReplayEntry entries[1];
} ReplayData;

static inline u32 replay_read(u32 bits) {
    u32 *pos = &lbl_13_bss_4;
    return fn_1_F453C(lbl_13_bss_0, pos, bits);
}

static inline f32 replay_read_f32(void) {
    u32 raw;
    f32 value;
    raw = replay_read(32);
    fn_80008BA8(&value, &raw, 4);
    return value;
}

#define REPLAY ((ReplayData *)lbl_1_bss_7EFD8.unk_40)

void fn_13_3FC(void) {
    u8 header[0x14B8];
    s32 i;
    s32 j;

    fn_1_3EF14(header);
    REPLAY->numEntries = replay_read(8);
    lbl_1_bss_7EFD8.unk_18 = header[8];
    for (i = 0; i < REPLAY->numEntries; i++) {
        REPLAY->entries[i].a = replay_read(14);
        REPLAY->entries[i].b = replay_read(14);
        REPLAY->entries[i].c = replay_read(4);
        REPLAY->entries[i].d = replay_read(5);
        REPLAY->entries[i].e = replay_read(5);
        REPLAY->entries[i].f = replay_read(5);
        REPLAY->entries[i].g = replay_read(5);
        REPLAY->entries[i].h = replay_read(5);
        for (j = 0; j < lbl_1_bss_7EFD8.unk_18; j++) {
            REPLAY->entries[i].pos[j].x = replay_read_f32();
            REPLAY->entries[i].pos[j].y = replay_read_f32();
            REPLAY->entries[i].pos[j].z = replay_read_f32();
            REPLAY->entries[i].rot[j].x = replay_read_f32();
            REPLAY->entries[i].rot[j].y = replay_read_f32();
            REPLAY->entries[i].rot[j].z = replay_read_f32();
        }
        REPLAY->entries[i].v68.x = replay_read_f32();
        REPLAY->entries[i].v68.y = replay_read_f32();
        REPLAY->entries[i].v68.z = replay_read_f32();
        REPLAY->entries[i].v74.x = replay_read_f32();
        REPLAY->entries[i].v74.y = replay_read_f32();
        REPLAY->entries[i].v74.z = replay_read_f32();
    }
    REPLAY->count = replay_read(14);
    for (i = 0; i <= REPLAY->count; i++) {
        REPLAY->rec[i][0] = replay_read(8);
        REPLAY->rec[i][3] = replay_read(8);
        REPLAY->rec[i][4] = replay_read(7);
        REPLAY->rec[i][5] = replay_read(7);
        REPLAY->rec[i][6] = replay_read(8);
        REPLAY->rec[i][1] = replay_read(8);
        REPLAY->rec[i][2] = replay_read(8);
    }
    fn_1_F4794(REPLAY->count);
    REPLAY->count = 0;
}
/* fzgx:end fn_13_3FC */

/* fzgx:begin fn_13_A40 */
// fn_13_A40: returns a constant.
int fn_13_A40(void) {
    return 0;
}
/* fzgx:end fn_13_A40 */

/* fzgx:begin fn_13_A48 */
s32 fn_13_A48(void) {
    fn_1_D0790();
    return 0;
}
/* fzgx:end fn_13_A48 */

/* fzgx:begin fn_13_A6C */
struct fn_13_A6C_Arg0 {
    u8 pad_0[0xAC];
    u32 unk_AC;
    u8 pad_B0[0x1C];
    u32 unk_CC;
};

void fn_13_A6C(struct fn_13_A6C_Arg0 *arg0) {
    arg0->unk_CC = (u32)fn_13_A40;
    arg0->unk_AC = (u32)fn_13_A48;
    lbl_13_bss_38 = 0;
}
/* fzgx:end fn_13_A6C */

/* fzgx:begin _prolog */
void _prolog(void) {
    lbl_1_bss_7167C = (u32)fn_13_AFC;
    lbl_1_bss_71680 = (u32)fn_13_B00;
    lbl_1_bss_71684 = (u32)fn_13_B08;
    lbl_1_bss_96A = 0xA7;
    fn_1_A8F78();
    lbl_13_bss_3C = 0;
}
/* fzgx:end _prolog */

/* fzgx:begin fn_13_AFC */
// fn_13_AFC: empty in retail (single blr).
void fn_13_AFC(void) {
}
/* fzgx:end fn_13_AFC */

/* fzgx:begin fn_13_B00 */
// fn_13_B00: empty in retail (single blr).
void fn_13_B00(void) {
}
/* fzgx:end fn_13_B00 */

/* fzgx:begin _epilog */
// _epilog: empty in retail (single blr).
void _epilog(void) {
}
/* fzgx:end _epilog */

/* fzgx:begin fn_13_B08 */
typedef u32 (*fn_13_B08_Fn0)(void);
struct fn_13_B08_lbl_13_data_18_0_E16 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};
struct fn_13_B08_lbl_13_data_18 {
    struct fn_13_B08_lbl_13_data_18_0_E16 unk_0[1];
};

void fn_13_B08(void) {
    s32 index;
    struct fn_13_B08_lbl_13_data_18_0_E16 *p;
    index = lbl_1_bss_962;
    index -= 167;
    p = &lbl_13_data_18.unk_0[0];
    p += index;
    lbl_1_bss_71688 = p->unk_8;
    lbl_1_bss_7168C = p->unk_C;
    ((fn_13_B08_Fn0)p->unk_4)();
}
/* fzgx:end fn_13_B08 */

/* fzgx:begin fn_13_B64 */
void fn_13_B64(void) {
    lbl_1_bss_26C60 = (u32)fn_13_3FC;
}
/* fzgx:end fn_13_B64 */

/* fzgx:begin fn_13_B78 */
// fn_13_B78: empty in retail (single blr).
void fn_13_B78(void) {
}
/* fzgx:end fn_13_B78 */

/* fzgx:begin fn_13_B7C */
struct fn_13_B7C_lbl_13_bss_3C {
    u8 unk_0;
};

void fn_13_B7C(void) {
    u32 t0;
    t0 = fn_1_3F038();
    if ((s32)t0 != 0) {
    (*(struct fn_13_B7C_lbl_13_bss_3C *)&lbl_13_bss_3C).unk_0 = 1;
    lbl_1_bss_96A = 169;
    lbl_13_bss_40 = 167;
    }
}
/* fzgx:end fn_13_B7C */
