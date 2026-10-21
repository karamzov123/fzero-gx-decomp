#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_lig.h"

extern void fn_80008BA8(void *arg0, void *arg1, int arg2);
extern u32 lbl_1_rodata_6490[4];
extern u32 lbl_801A63D0;
extern u32 fn_1_76504(s32, void *, s32);
extern void fn_1_7269C(u32, s32, u32);
extern void fn_1_5948(s32 index);
extern void fn_1_D8388(void *obj);
extern void fn_1_627C(s32 index);
extern void *fn_1_9D260(Obj_1_data_2A7E0 *data);
extern void fn_1_D7B7C(Obj_1_data_2A7E0_At3C *obj);
extern void fn_1_9AD88(void);
extern void *memset(void *dst, int value, u32 size);
extern void fn_1_D7EF4(void *, u32);
extern f32 lbl_1_rodata_6594[];
extern f32 lbl_1_rodata_6524[];
extern void lbl_8006DCA4(void);
extern s32 fn_1_54E34(void *obj, f32 value);
extern void *fn_1_54448(s32 value);
extern void *fn_1_548AC(s32 value);
extern void fn_1_D8878(void);
extern void fn_1_5489C(void *obj, void *arg);
extern void fn_1_D83E4(Obj_1_data_2A7E0_At3C *obj, s32 index);
extern void fn_1_D7A10(Obj_1_data_2A7E0_At3C *obj);
extern void fn_1_D8D58(Obj_1_data_2A7E0_At3C *obj, Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_D9D8C(Obj_1_bss_7AD78 *obj, u32 arg, s32 index);
extern void fn_1_DA3A0(Obj_1_bss_7AD78 *obj);
extern void fn_1_E87FC(void);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern struct fn_1_D66F8_lbl_801A66A0 lbl_801A66A0;
extern u32 lbl_1_rodata_6358;
extern void fn_1_4404(void);
extern u32 fn_1_DA6A8(void *, u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_446C(void);
extern void fn_1_76BF8(void);
extern void fn_1_72648(void);

/* fzgx:begin fn_1_D5C70 */
extern int fn_1_58C4(void);

typedef struct {
    u32 unk0;
    void *data;
    u32 unk8;
    u32 flags;
    u8 rest[0xac - 0x10];
} Elem;

#define IDX (*(s32 *)(p - 0x1820))
#define FLAG(idx) (((Elem *)(p - 0x1820))[idx].flags)
#define DATA(idx) (((Elem *)(p - 0x1820))[idx].data)
#define SB0 (*(s16 *)(p - 0x1888))
#define SB1 (*(s16 *)(p - 0x1886))

s32 fn_1_D5C70(u32 arg0, u32 *arg1) {
    u8 *p;
    u8 *scan;

    p = (u8 *)lbl_1_data_2A7E0.unk_3C + 0x10000;

    switch (arg0) {
    case 0:
        FLAG(IDX) |= 0x40000000;
        FLAG(IDX) |= 0x10000000;
        DATA(IDX) = arg1;
        IDX = IDX + 1;
        if (IDX >= 32) {
            OSPanic((const char *)lbl_1_data_3DBE8, 0x577, (const char *)lbl_1_data_3DBF4);
        }
        break;
    case 1:
        FLAG(IDX) |= 0x40000000;
        FLAG(IDX) |= 0x20000000;
        DATA(IDX) = arg1;
        IDX = IDX + 1;
        if (IDX >= 32) {
            OSPanic((const char *)lbl_1_data_3DBE8, 0x57e, (const char *)lbl_1_data_3DBF4);
        }
        break;
    case 2:
        FLAG(IDX) |= 0x40000000;
        FLAG(IDX) |= 0x10000000;
        FLAG(IDX) |= 0x08000000;
        DATA(IDX) = arg1;
        IDX = IDX + 1;
        if (IDX >= 32) {
            OSPanic((const char *)lbl_1_data_3DBE8, 0x586, (const char *)lbl_1_data_3DBF4);
        }
        break;
    case 3:
        FLAG(IDX) |= 0x40000000;
        FLAG(IDX) |= 0x20000000;
        FLAG(IDX) |= 0x08000000;
        DATA(IDX) = arg1;
        IDX = IDX + 1;
        if (IDX >= 32) {
            OSPanic((const char *)lbl_1_data_3DBE8, 0x58e, (const char *)lbl_1_data_3DBF4);
        }
        break;
    case 5:
        *arg1 |= 0x01000000;
        break;
    case 6:
        if (fn_1_58C4() <= 2) {
            *arg1 |= 0x02000000;
            SB0 = 0x1b;
            SB1 = 0x28;
        } else {
            *arg1 &= ~0x02000000;
        }
        break;
    case 7:
    case 8:
    case 9:
        if (fn_1_58C4() <= 2) {
            *arg1 |= 0x02000000;
            SB0 = 0x18;
            SB1 = 0x18;
        } else {
            *arg1 &= ~0x02000000;
        }
        break;
    case 10:
        scan = (u8 *)lbl_1_bss_3BE0->unk_54;
        *(s32 *)(p - 0x29c) = 0;
        while (scan != (u8 *)arg1) {
            scan += 0x40;
            *(s32 *)(p - 0x29c) = *(s32 *)(p - 0x29c) + 1;
        }
        *arg1 |= 0x80000000;
        break;
    default:
        break;
    }
    return 1;
}
/* fzgx:end fn_1_D5C70 */

/* fzgx:begin fn_1_D6680 */
// fn_1_D6680: returns a constant.
int fn_1_D6680(void) {
    return 0;
}
/* fzgx:end fn_1_D6680 */

/* fzgx:begin fn_1_D6688 */
// fn_1_D6688: returns a constant.
int fn_1_D6688(void) {
    return 1;
}
/* fzgx:end fn_1_D6688 */

/* fzgx:begin fn_1_D6690 */
// fn_1_D6690: returns a constant.
int fn_1_D6690(void) {
    return 0;
}
/* fzgx:end fn_1_D6690 */

/* fzgx:begin fn_1_D6698 */
// fn_1_D6698: returns a constant.
int fn_1_D6698(void) {
    return 0;
}
/* fzgx:end fn_1_D6698 */

/* fzgx:begin fn_1_D66A0 */
// fn_1_D66A0: returns a constant.
int fn_1_D66A0(void) {
    return 0;
}
/* fzgx:end fn_1_D66A0 */

/* fzgx:begin fn_1_D66A8 */
// fn_1_D66A8: returns a constant.
int fn_1_D66A8(void) {
    return 0;
}
/* fzgx:end fn_1_D66A8 */

/* fzgx:begin fn_1_D66B0 */
// fn_1_D66B0: returns a constant.
int fn_1_D66B0(void) {
    return 0;
}
/* fzgx:end fn_1_D66B0 */

/* fzgx:begin fn_1_D66B8 */
// fn_1_D66B8: empty in retail (single blr).
void fn_1_D66B8(void) {
}
/* fzgx:end fn_1_D66B8 */

/* fzgx:begin fn_1_D66BC */
int fn_1_D66BC(void *unused, void *arg)
{
    fn_80008BA8(arg, lbl_1_data_3DC38, 0x10);
    return 1;
}
/* fzgx:end fn_1_D66BC */

/* fzgx:begin fn_1_D66F4 */
// fn_1_D66F4: empty in retail (single blr).
void fn_1_D66F4(void) {
}
/* fzgx:end fn_1_D66F4 */

/* fzgx:begin fn_1_D66F8 */
struct fn_1_D66F8_Arg1 {
    u8 unk_0;
};
struct fn_1_D66F8_Arg2 {
    u8 unk_0;
};
struct fn_1_D66F8_lbl_801A66A0 {
    u32 unk_0;
};

void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2) {
    u32 sp8;

    sp8 = *(u32 *)((u8 *)(&lbl_1_rodata_6358) + 0);
    (*(u8 *)((u8 *)(arg1) + 0)) = *(u8 *)((u8 *)(((u8 *)(&sp8) + arg0)) + 0);
    (*(s8 *)((u8 *)(arg2) + 0)) = ((u32) lbl_801A66A0.unk_0 / (u32) ((arg0 + 1) * 0x1E)) & 3;
}
/* fzgx:end fn_1_D66F8 */

/* fzgx:begin fn_1_D6740 */
// fn_1_D6740: returns a constant.
int fn_1_D6740(void) {
    return 1;
}
/* fzgx:end fn_1_D6740 */

/* fzgx:begin fn_1_D720C */
void fn_1_D720C(void) {
    u32 local[4];
    u32 result;

    local[0] = lbl_1_rodata_6490[0];
    local[1] = lbl_1_rodata_6490[1];
    local[2] = lbl_1_rodata_6490[2];
    local[3] = lbl_1_rodata_6490[3];
    result = fn_1_76504(0x1d, local, 0);
    fn_1_7269C(result, 0, lbl_801A63D0);
}
/* fzgx:end fn_1_D720C */

/* fzgx:begin fn_1_D7274 noprologue */
#include "rel/main_rel/bg_lig.h"

extern s32 fn_1_58C4(void);
extern void fn_1_9A508(void);
extern f32 lbl_1_rodata_64A0[33];
extern void fn_1_D79E4(Obj_1_data_2A7E0_At3C *);
extern u8 fn_1_5300(void);
extern void fn_1_77B80(u32);
extern void fn_1_76BF8(void);
extern void fn_1_72648(void);
extern void fn_1_D8CA8(Obj_1_data_2A7E0_At3C *);
extern void fn_1_4404(void);
extern void fn_1_DA6A8(void *, u32);
extern void fn_1_D9224(void *, u32);
extern void fn_1_446C(void);
extern void fn_1_D9D8C(void *, u32, s32);
extern void fn_1_DA3A0(void *);
extern void fn_80008BEC(void *, u32, u32);

#pragma opt_dead_assignments off
#pragma opt_pointer_analysis on
void fn_1_D7274(void) {
    Obj_1_data_2A7E0_At3C *obj;
    Obj_1_bss_7AD78 *state;
    Obj_1_bss_7AD78 *state2;
    s32 i;
    s32 mode;

    mode = fn_1_58C4();
    obj = lbl_1_data_2A7E0.unk_3C;
    obj->unk_6D4 = 0;
    fn_1_9A508();
    obj->unk_6C0 = (0.0f);
    fn_1_D79E4(obj);

    if (obj->unk_6CC != 0
        && (mode == 1 || (mode == 2 && fn_1_5300() == 1))) {
        fn_1_77B80(obj->unk_6CC);
    } else {
        fn_1_76BF8();
        fn_1_72648();
    }

    fn_1_D8CA8(obj);
    fn_1_4404();

    if (lbl_1_bss_7AD78.unk_14 != 0) {
        fn_1_DA6A8(&lbl_1_bss_7AD78, obj->unk_1C58);
        fn_80008BEC(&lbl_1_bss_7AD78, 0, 0x20);
    }

    if (lbl_1_bss_7AD78.unk_34 != 0) {
        state = &lbl_1_bss_7AD78;
        state2 = (Obj_1_bss_7AD78 *)((u8 *)state + 0x20);
        fn_1_DA6A8(state2, obj->unk_1C5C);
        fn_80008BEC(state2, 0, 0x20);
    }

    if (obj->unk_1C58 != 0) {
        fn_80008BEC(&lbl_1_bss_7AD78, 0, 0x20);
        fn_1_D9224(&lbl_1_bss_7AD78, obj->unk_1C58);
    }

    if (obj->unk_1C5C) {
        state2 = (Obj_1_bss_7AD78 *)((u8 *)&lbl_1_bss_7AD78 + 0x20);
        fn_80008BEC(state2, 0, 0x20);
        fn_1_D9224(state2, obj->unk_1C5C);
    }

    fn_1_446C();
    state = &lbl_1_bss_7AD78;
    state2 = (Obj_1_bss_7AD78 *)((u8 *)state + 0x20);
    for (i = 0; i < 0x78; i++) {
        if (obj->unk_1C58 != 0) {
            fn_1_D9D8C(state, obj->unk_1C58, 0);
            fn_1_DA3A0((&lbl_1_bss_7AD78));
        }
        if (obj->unk_1C5C != 0) {
            fn_1_D9D8C(state2, obj->unk_1C5C, 1);
            fn_1_DA3A0(state2);
        }
    }
}
#pragma opt_pointer_analysis reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_D7274 */

/* fzgx:begin fn_1_D744C */
extern void fn_80008BA8(void *arg0, void *arg1, int arg2);
extern u32 lbl_1_rodata_6490[4];
extern u32 lbl_801A63D0;
extern u32 fn_1_76504(s32, void *, s32);
extern void fn_1_7269C(u32, s32, u32);
extern void fn_1_5948(s32 index);
extern void fn_1_D8388(void *obj);
extern void fn_1_627C(s32 index);
extern void *fn_1_9D260(Obj_1_data_2A7E0 *data);
extern void fn_1_D7B7C(Obj_1_data_2A7E0_At3C *obj);
extern void fn_1_9AD88(void);
extern void *memset(void *dst, int value, u32 size);
extern void fn_1_D7EF4(void *, u32);
extern f32 lbl_1_rodata_6594[];


extern void lbl_8006DCA4(void);
extern s32 fn_1_54E34(void *obj, f32 value);
extern void *fn_1_54448(s32 value);
extern void *fn_1_548AC(s32 value);
extern void fn_1_D8878(void);
extern void fn_1_5489C(void *obj, void *arg);

extern s32 fn_1_58C4(void);
extern void fn_1_5948(s32 index);
extern void fn_1_D8388();
extern void fn_1_627C(s32 index);

// Initializes each available background-light entry.
void fn_1_D744C(void) {
    Obj_1_data_2A7E0_At3C *obj;
    s32 count;
    s32 i;

    obj = lbl_1_data_2A7E0.unk_3C;
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_D8388(obj, i);
        fn_1_627C(i);
    }
}
/* fzgx:end fn_1_D744C */

/* fzgx:begin fn_1_D74C4 */
// Initializes background-light data and installs the completion callback.
void fn_1_D74C4(void) {
    Obj_1_bss_7AD78 *tmp;
    Obj_1_data_2A7E0_At3C *obj;
    Obj_1_data_2A7E0_At3C *arg;
    s32 count;
    s32 i;

    obj = lbl_1_data_2A7E0.unk_3C;
    arg = (Obj_1_data_2A7E0_At3C *)fn_1_9D260(&lbl_1_data_2A7E0);
    fn_1_9AD54();
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_D83E4(obj, i);
        fn_1_627C(i);
    }

    fn_1_D7A10(obj);
    fn_1_D8D58(obj, arg);
    if (obj->unk_1C58 != 0) {
        fn_1_D9D8C(&lbl_1_bss_7AD78, obj->unk_1C58, 0);
        fn_1_DA3A0(&lbl_1_bss_7AD78);
    }
    if (obj->unk_1C5C != 0) {
        tmp = (Obj_1_bss_7AD78 *)((u8 *)&lbl_1_bss_7AD78 + 0x20);
        fn_1_D9D8C(tmp, obj->unk_1C5C, 1);
        fn_1_DA3A0(tmp);
    }
    lbl_1_data_2A7E0.unk_2C = (u32)fn_1_E87FC;
}
/* fzgx:end fn_1_D74C4 */

/* fzgx:begin fn_1_D75CC */
#include "types.h"

typedef struct {
    u8 data[0xac];
} Sig_fn_1_D8D08_fn_1_D8D08_LigEntry;

typedef struct {
    u8 pad[0x6d4];
    s32 count;
    Sig_fn_1_D8D08_fn_1_D8D08_LigEntry entries[1];
} Sig_fn_1_D8D08_LigContainer;

struct fn_1_D75CC_lbl_1_data_2A7E0 {
    u8 pad_0[0x3C];
    u32 unk_3C;
};

extern void fn_1_D8D08(Sig_fn_1_D8D08_LigContainer *);

void fn_1_D75CC(void) {
    u32 *temp_r31;
    u32 temp_r30;
    u32 temp_r4;
    u32 temp_r4_2;

    temp_r30 = (*(struct fn_1_D75CC_lbl_1_data_2A7E0 *)&lbl_1_data_2A7E0).unk_3C;
    fn_1_4404();
    temp_r4 = *(u32 *)((u8 *)(temp_r30) + 7256);
    if (temp_r4 != 0) {
        fn_1_DA6A8((void *)(&(*(u32 *)&lbl_1_bss_7AD78)), temp_r4);
        fn_80008BEC((void *)(&(*(u32 *)&lbl_1_bss_7AD78)), 0, 0x20U);
        (*(u32 *)((u8 *)(temp_r30) + 7256)) = 0U;
    }
    temp_r4_2 = *(u32 *)((u8 *)(temp_r30) + 7260);
    if (temp_r4_2 != 0) {
        temp_r31 = (u32 *)((u8 *)(&(*(u32 *)&lbl_1_bss_7AD78)) + 0x20);
        fn_1_DA6A8((void *)(temp_r31), temp_r4_2);
        fn_80008BEC((void *)(temp_r31), 0, 0x20U);
        (*(u32 *)((u8 *)(temp_r30) + 7260)) = 0U;
    }
    fn_1_446C();
    fn_1_76BF8();
    fn_1_72648();
    fn_1_D8D08((Sig_fn_1_D8D08_LigContainer *)((Sig_fn_1_D8D08_LigContainer *)(temp_r30)));
}
/* fzgx:end fn_1_D75CC */

/* fzgx:begin fn_1_D7688 */
extern void fn_1_D8784(Obj_1_data_2A7E0_At3C *obj);
extern void fn_1_D8EEC(Obj_1_data_2A7E0_At3C *obj, void *value);

void fn_1_D7688(void) {
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;
    void *value = fn_1_9D260(&lbl_1_data_2A7E0);
    fn_1_D8784(obj);
    fn_1_D7B7C(obj);
    fn_1_D8EEC(obj, value);
    fn_1_9AD88();
}
/* fzgx:end fn_1_D7688 */

/* fzgx:begin fn_1_D76EC */
// fn_1_D76EC: empty in retail (single blr).
void fn_1_D76EC(void) {
}
/* fzgx:end fn_1_D76EC */

/* fzgx:begin fn_1_D76F0 */
// Copies a three-component float vector into the indexed light buffer entry.
void fn_1_D76F0(const f32 *src, s16 index) {
    f32 *dst = (f32 *)lbl_1_data_2A7E0.unk_3C;

    dst[index * 3] = src[0];
    dst += index * 3;
    dst[1] = src[1];
    dst[2] = src[2];
}
/* fzgx:end fn_1_D76F0 */

/* fzgx:begin fn_1_D7724 */
typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec3Bits;

// Copies the indexed three-word light entry to the caller-provided buffer.
void fn_1_D7724(Vec3Bits *dst, s16 index) {
    u32 *base = (u32 *)lbl_1_data_2A7E0.unk_3C;
    Vec3Bits *src = (Vec3Bits *)(base + index * 3);

    *dst = *src;
}
/* fzgx:end fn_1_D7724 */

/* fzgx:begin fn_1_D79E4 */
void fn_1_D79E4(void *obj) {
    memset((u8 *)obj + 0x30, 0, 0x3c0);
}
/* fzgx:end fn_1_D79E4 */

/* fzgx:begin fn_1_D7A10 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[4] = {0x00000000, 0x0280012C, 0x00000000, 0x00000001};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 100.0f;
    s = 3.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.7;
    d = 0.3;
    s = 32767.0f;
    s = 235.0f;
    s = 80.0f;
    s = 30.0f;
    d = 512.0;
    d = 0.5;
    d = 300.0;
    d = 17.0;
    s = 3276.800048828125f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.98;
    s = 0.07999999821186066f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.99;
    d = 0.02;
    s = 400.0f;
    s = 0.7071067690849304f;
}
#pragma section code_type ".text"

typedef struct {
	u8 pad0[0x30];
	f32 f30;
	f32 f34;
	f32 f38;
	f32 f3c;
	f32 f40;
	f32 f44;
	f32 f48;
	f32 f4c;
	f32 f50;
	f32 f54;
	s16 s58;
	s16 s5a;
	s16 s5c;
} LigSeg;

static inline f64 fn_1_D7A10_operand(f64 right, f64 left) { return left * right; }
#pragma opt_common_subs off
static inline f64 fn_1_D7A10_operand_(f64 right, f64 left) { return left * right; }
static inline f64 fn_1_D7A10_operand__(f64 right, f64 left) { return left * right; }
static inline f64 fn_1_D7A10_operand___(f64 right, f64 left) { return left * right; }
void fn_1_D7A10(LigSeg *obj) {
	s32 i;

	for (i = 0; i < 0x14; i++) {
		if (obj->s5c > 0) {
			f64 t;

			obj->f3c = (f32)(fn_1_D7A10_operand((0.98), (obj->f3c)));
			obj->f40 = (f32)(fn_1_D7A10_operand__((0.98), (obj->f40)));
			obj->f44 = (f32)(fn_1_D7A10_operand___((0.98), (obj->f44)));
			obj->f40 = obj->f40 - 0.08f;
			obj->f30 = obj->f30 + obj->f3c;
			obj->f34 = obj->f34 + obj->f40;
			obj->f38 = obj->f38 + obj->f44;
			obj->s58 = obj->s58 + obj->s5a;
			obj->s5a = (s16)(fn_1_D7A10_operand_((0.99), (obj->s5a)));
			t = 0.02 * (400.0f - obj->f54);
			obj->f54 = obj->f54 + t;
			if (obj->s5c < 0x50) {
				f32 t = obj->s5c / 80.0f;

				obj->f48 = obj->f48 * t;
				obj->f4c = obj->f4c * t;
				obj->f50 = obj->f50 * t;
			}
			if (obj->s5c > 0) {
				obj->s5c = obj->s5c - 1;
			}
		}
		obj = (LigSeg *)((u8 *)obj + 0x30);
	}
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_D7A10 */

/* fzgx:begin fn_1_D7B7C noprologue */
#include "types.h"

extern f32 lbl_1_rodata_6524[];

typedef struct {
    u8 pad0[0x24];
    f32 value;
    u8 pad28[0x4];
    s16 count;
    u8 pad2e[0x2];
} LigEntry;

typedef struct {
    u8 pad0[0x4];
    void (*callback)(void);
    LigEntry *entry;
} LigEvent;

extern void lbl_8006DCA4(void);


extern s32 fn_1_54E34(LigEntry *entry, f32 value);
extern void *fn_1_5448C(LigEntry *entry);
extern LigEvent *fn_1_548AC(s32 size);
extern void fn_1_D7C44(void);
extern void fn_1_5489C(void *data, void *event);

void fn_1_D7B7C(LigEntry *base) {
    void *data;
    LigEntry *entry;
    s32 i;
    LigEvent *event;

    lbl_8006DCA4();

    for (i = 0; i < 0x14; i++) {
        entry = base + i + 1;
        if (entry->count > 0 &&
            fn_1_54E34(entry, (*(f32 (*)[28])&lbl_1_rodata_6524)[0] * entry->value)) {
            data = fn_1_5448C(entry);
            event = fn_1_548AC(0xc);
            if (event != 0) {
                event->callback = fn_1_D7C44;
                event->entry = entry;
                fn_1_5489C(data, event);
            }
        }
    }
}
/* fzgx:end fn_1_D7B7C */

/* fzgx:begin fn_1_D7C44 */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[4] = {0x00000000, 0x0280012C, 0x00000000, 0x00000001};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 100.0f;
    s = 3.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.7;
    d = 0.3;
    s = 32767.0f;
    s = 235.0f;
    s = 80.0f;
    s = 30.0f;
    d = 512.0;
    d = 0.5;
    d = 300.0;
    d = 17.0;
    s = 3276.800048828125f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.98;
    s = 0.07999999821186066f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.99;
    d = 0.02;
    s = 400.0f;
    s = 0.7071067690849304f;
    s = 1.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

typedef struct {
	f32 unk_0;
	f32 unk_4;
	u8 pad_8[0x30];
	u32 unk_38;
	u8 unk_3c;
	u8 unk_3d;
	u8 unk_3e;
	u8 unk_3f;
} LigObj;

typedef struct {
	u8 pad_0[0x18];
	f32 unk_18;
	f32 unk_1c;
	f32 unk_20;
	f32 unk_24;
	s16 unk_28;
} LigSrc;

typedef struct {
	u8 pad_0[8];
	LigSrc *unk_8;
} LigEvt;

extern void *memset(void *dst, int value, u32 size);
extern void lbl_8006DCA4(void);
extern void lbl_8006E1B0(void *a, void *b);
extern void lbl_8006D7DC(void *a);
extern void lbl_8006DB74(void *a);
extern void mathutil_mtxA_rotate_z(u32 a);
extern void fn_1_9EDE8(LigObj *);
extern void fn_80074788(u32);
extern void fn_80072864(u32);
extern void fn_80073778(void *, s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073C6C(s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80074918(u8, s32, u8);
extern u32 fn_800720B0(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void lbl_8006D758(void);

/* Retail emits this conversion inline at each of its three call sites: fn_1_D7C44's
   172 instructions contain no call to a scaling helper, and the symbol does not exist in
   symbols.txt. A plain `static` would emit it out of line and add 28 bytes of .text,
   which is what failed the 16-target link. Matches fn_1_D7C44_array_read below. */
static inline u8 scale_to_byte(f32 value, f32 scale) {
	return (u8)(value * scale);
}

static inline u32 fn_1_D7C44_array_read(s32 index, u32 *array) { return array[index]; }
#pragma opt_lifetimes off
void fn_1_D7C44(LigEvt *arg0) {
	LigObj obj;
	u32 stackbuf[3];
	LigSrc *src;
	u32 *unk;
	u32 handle;

	src = arg0->unk_8;
	unk = *(u32 **)((u8 *)lbl_1_bss_38458->unk_8 + 0x170);
	lbl_8006DCA4();
	lbl_8006E1B0(src, stackbuf);
	lbl_8006D7DC(stackbuf);
	mathutil_mtxA_rotate_z(src->unk_28);
	memset(&obj, 0, 0x40);
	lbl_8006DB74((u8 *)&obj + 8);
	obj.unk_0 = 0.70710677f * src->unk_24;
	obj.unk_3c = scale_to_byte((f32)(u8)src->unk_18, 1.0f);
	obj.unk_3d = scale_to_byte((f32)(u8)src->unk_1c, 1.0f);
	obj.unk_3e = scale_to_byte((f32)(u8)src->unk_20, 1.0f);
	obj.unk_3f = 0xFF;
	obj.unk_38 |= 2;
	obj.unk_4 = 2.0 * obj.unk_0;
	handle = fn_1_D7C44_array_read(9, unk);
	fn_80074788(0);
	fn_80072864(1);
	fn_80073778((void *)handle, 0);
	fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
	fn_800734A8(0, 0, 0, 0xff);
	fn_80072AB0(0, 0, 0);
	fn_800735C8(0, 0xc);
	fn_80073620(0, 0x1c);
	fn_80073C6C(0);
	fn_80072C24(0, 0xf, 0xe, 8, 0xf);
	fn_80072D64(0, 0, 0, 0, 1, 0);
	fn_80072CC4(0, 7, 6, 4, 7);
	fn_80072E20(0, 0, 0, 0, 1, 0);
	fn_80073678(1);
	fn_80074660(1);
	fn_80074918(1, 7, 0);
	fn_800720B0(0);
	fn_800728A8(1, 3, 1, 7);
	fn_80074918(1, 3, 0);
	lbl_8006D758();
	fn_1_9EDE8(&obj);
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_D7C44 */

/* fzgx:begin fn_1_D8388 */
extern u32 fn_1_58C4(void);

// Initializes each lighting entry while the lighting system is available.
void fn_1_D8388(void *obj) {
    u8 *entry = (u8 *)obj;
    s32 i;

    if (fn_1_58C4() < 2) {
        i = 0;
        do {
            fn_1_D7EF4(entry + 0x3f0, 0);
            i++;
            entry += 0x30;
        } while (i < 0xf);
    }
}
/* fzgx:end fn_1_D8388 */

/* fzgx:begin fn_1_D8784 */
typedef void (*LigCallback)(void);

typedef struct {
    u32 unk_00;
    LigCallback callback;
    void *data;
} LigCallbackObject;

typedef struct {
    u8 pad_000[0x3f0];
    u8 callback_data[0x24];
    f32 scale;
} fn_1_D8784_LigEntry;

typedef struct {
    u8 pad_000[0x6c0];
    f32 threshold;
} fn_1_D8784_LigObject;

extern u32 fn_1_58C4(fn_1_D8784_LigObject *obj);

// Queues callbacks for eligible lig entries.
void fn_1_D8784(fn_1_D8784_LigObject *obj) {
    void *callback_data;
    void *owner;
    u8 i;
    f32 factor;
    fn_1_D8784_LigEntry *entry;

    if (fn_1_58C4(obj) >= 2) {
        return;
    }
    if (obj->threshold < lbl_1_rodata_6594[0]) {
        return;
    }

    factor = lbl_1_rodata_6524[0];
    i = 0;
    for (; i < 0xf; i++) {
        lbl_8006DCA4();
        entry = (fn_1_D8784_LigEntry *)((u8 *)obj + (i * 0x30));
        callback_data = entry->callback_data;
        if (fn_1_54E34(callback_data, factor * entry->scale) != 0) {
            owner = fn_1_54448(0);
            {
                LigCallbackObject *callback = (LigCallbackObject *)fn_1_548AC(0xc);
                if (callback != 0) {
                    callback->callback = fn_1_D8878;
                    callback->data = callback_data;
                    fn_1_5489C(owner, callback);
                }
            }
        }
    }
}
/* fzgx:end fn_1_D8784 */

/* fzgx:begin fn_1_D8878 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[4] = {0x00000000, 0x0280012C, 0x00000000, 0x00000001};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 100.0f;
    s = 3.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.7;
    d = 0.3;
    s = 32767.0f;
    s = 235.0f;
    s = 80.0f;
    s = 30.0f;
    d = 512.0;
    d = 0.5;
    d = 300.0;
    d = 17.0;
    s = 3276.800048828125f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.98;
    s = 0.07999999821186066f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.99;
    d = 0.02;
    s = 400.0f;
    s = 0.7071067690849304f;
    s = 1.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table11[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = 0.5f;
    s = 10.0f;
    s = 5.0f;
    s = 0.6000000238418579f;
    s = 170.0f;
    s = 120.0f;
    s = 32.0f;
    s = 90.0f;
    s = 0.4000000059604645f;
    s = 768.0f;
}
static const u32 fzgx_pool_table13[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.05;
    s = 2.5f;
    s = 0.10000000149011612f;
    s = 50.0f;
    s = 20.0f;
    s = 70.0f;
    s = 33.0f;
    s = 15.0f;
    s = 0.6499999761581421f;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} LigVec;

typedef f32 LigMtx[3][4];

typedef struct {
    LigVec pos;      /* 0x00 */
    u8 pad_C[0xC];
    f32 r;           /* 0x18 */
    f32 g;           /* 0x1C */
    f32 b;           /* 0x20 */
    f32 size;        /* 0x24 */
    s16 angle;       /* 0x28 */
    u8 pad_2A[0x2];
    s16 fade;        /* 0x2C */
} LigSource;

typedef struct {
    u8 pad_0[0x8];
    LigSource *source;
} LigObject;

typedef struct {
    f32 width;       /* 0x00 */
    f32 height;      /* 0x04 */
    LigMtx mtx;      /* 0x08 */
    u32 flags;       /* 0x38 */
    u8 color[4];     /* 0x3C */
} LigPacket;

extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DCA4(void);
extern void lbl_8006E1B0(LigVec *, LigVec *);
extern void lbl_8006D7DC(LigVec *);
extern void mathutil_mtxA_rotate_z(s16);
extern int fn_1_58C4(void);
extern void fn_1_681C(u8, LigVec *);
extern void lbl_8006DB74(LigMtx);
extern void lbl_8006D758(void);
extern void fn_1_9EDE8(LigPacket *);
extern void *memset(void *, int, u32);
extern void fn_80074788(s32);
extern void fn_80072864(s32);
extern void fn_80073778(void *, s32);
extern void fn_800745A4(s32, s32, s32, s32, s32, s32);
extern void fn_800734A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073C6C(s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, s32, s32);
extern void fn_80073678(s32);
extern void fn_80074660(s32);
extern void fn_80074918(s32, s32, s32);
extern void fn_800720B0(s32);
extern void fn_800728A8(s32, s32, s32, s32);

#define LIG_MIN(a, b) ((a) < (b) ? (a) : (b))
#define LIG_CLAMP01(x) ((x) < 0.0f ? 0.0f : ((x) > 1.0f ? 1.0f : (x)))

/* squared distance between two points, accumulated into len
 * (the first distance accumulates straight into the caller's variable) */
#define LIG_LEN2(len, a, b)      \
    do {                         \
        f32 x;                   \
        f32 z;                   \
        f32 y;                   \
        x = (a)->x;              \
        y = (a)->y;              \
        z = (a)->z;              \
        x -= (b)->x;             \
        y -= (b)->y;             \
        z -= (b)->z;             \
        (len) = x * x;           \
        (len) += y * y;          \
        (len) += z * z;          \
    } while (0)

/* distance between two points */
static inline f32 lig_dist(LigVec *a, LigVec *b) {
    f32 x = a->x;
    f32 y = a->y;
    f32 z = a->z;
    f32 len;

    x -= b->x;
    y -= b->y;
    z -= b->z;
    len = x * x;
    len += y * y;
    len += z * z;
    return lbl_8006D0B4(len);
}

/* src arrives as the owning object; its light source entry sits at +8 */
void fn_1_D8878(LigSource *src) {
    LigPacket packet;
    LigVec tmp;
    LigVec cam;
    void *scene;
    int count;
    u32 i;
    void *view;
    Obj_1_data_2A7E0_At3C *env;
    f32 dist;
    f32 size;
    f32 bright;
    f32 scale;
    f32 strength;
    s16 fade;

    env = lbl_1_data_2A7E0.unk_3C;
    scene = *(void **)((u8 *)lbl_1_bss_38458->unk_8 + 0x170);
    src = ((LigObject *)src)->source;

    lbl_8006DCA4();
    lbl_8006E1B0(&src->pos, &tmp);
    lbl_8006D7DC(&tmp);
    mathutil_mtxA_rotate_z(src->angle);

    count = fn_1_58C4();
    fn_1_681C(0, &cam);
    LIG_LEN2(dist, &src->pos, &cam);
    dist = lbl_8006D0B4(dist);
    for (i = 1; i < count; i++) {
        fn_1_681C(i, &cam);
        dist = LIG_MIN(dist, lig_dist(&src->pos, &cam));
    }

    if (dist < 20.0f) {
        dist = dist / 20.0f;
    } else {
        dist = 1.0f;
    }

    fade = src->fade;
    if (fade > 0) {
        dist *= 1.0f - (f32)fade / 15.0f;
    }

    memset(&packet, 0, sizeof(packet));
    lbl_8006DB74(packet.mtx);

    size = src->size;
    scale = LIG_CLAMP01(dist);
    bright = env->unk_6C0;
    packet.width = 0.70710677f * size;
    packet.color[0] = (u8)(bright * ((f32)(u8)src->r * scale));
    packet.color[1] = (u8)(bright * ((f32)(u8)src->g * scale));
    packet.color[2] = (u8)(bright * ((f32)(u8)src->b * scale));
    packet.color[3] = 0xFF;

    if (scale * bright < 0.1f) {
        return;
    }

    packet.flags |= 2;
    packet.height = 2.0 * packet.width;
    view = *(void **)((u8 *)scene + 0x24);
    fn_80074788(0);
    fn_80072864(1);
    fn_80073778(view, 0);
    fn_800745A4(0, 1, 4, 0x3C, 0, 0x7D);
    fn_800734A8(0, 0, 0, 0xFF);
    fn_80072AB0(0, 0, 0);
    fn_800735C8(0, 0xC);
    fn_80073620(0, 0x1C);
    fn_80073C6C(0);
    fn_80072C24(0, 0xF, 0xE, 8, 0xF);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 6, 4, 7);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80074918(1, 7, 0);
    fn_800720B0(0);
    fn_800728A8(1, 3, 1, 7);
    lbl_8006D758();
    fn_1_9EDE8(&packet);
}
/* fzgx:end fn_1_D8878 */

/* fzgx:begin fn_1_D8CA8 */
typedef struct {
    u8 pad_00[0x68];
    u32 field_68;
    u8 pad_6c[0x40];
} fn_1_D8CA8_LigEntry;

typedef struct {
    u8 pad_00[0x6d4];
    s32 count;
    fn_1_D8CA8_LigEntry entries[1];
} fn_1_D8CA8_LigObject;

extern void fn_1_103090(fn_1_D8CA8_LigEntry *entry);

void fn_1_D8CA8(fn_1_D8CA8_LigObject *obj) {
    s32 count = obj->count;
    fn_1_D8CA8_LigEntry *entry = obj->entries;

    while (count > 0) {
        entry->field_68 = 1;
        fn_1_103090(entry);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_D8CA8 */

/* fzgx:begin fn_1_D8D08 */
typedef struct {
    u8 data[0xac];
} fn_1_D8D08_LigEntry;

typedef struct {
    u8 pad[0x6d4];
    s32 count;
    fn_1_D8D08_LigEntry entries[1];
} LigContainer;

extern void fn_1_1030A4(fn_1_D8D08_LigEntry *entry);

void fn_1_D8D08(LigContainer *container) {
    s32 count = container->count;
    fn_1_D8D08_LigEntry *entry = container->entries;

    while (count > 0) {
        fn_1_1030A4(entry);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_D8D08 */

/* fzgx:begin fn_1_D8D58 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[4] = {0x00000000, 0x0280012C, 0x00000000, 0x00000001};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 100.0f;
    s = 3.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.7;
    d = 0.3;
    s = 32767.0f;
    s = 235.0f;
    s = 80.0f;
    s = 30.0f;
    d = 512.0;
    d = 0.5;
    d = 300.0;
    d = 17.0;
    s = 3276.800048828125f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.98;
    s = 0.07999999821186066f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.99;
    d = 0.02;
    s = 400.0f;
    s = 0.7071067690849304f;
    s = 1.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table11[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = 0.5f;
    s = 10.0f;
    s = 5.0f;
    s = 0.6000000238418579f;
    s = 170.0f;
    s = 120.0f;
    s = 32.0f;
    s = 90.0f;
    s = 0.4000000059604645f;
    s = 768.0f;
}
static const u32 fzgx_pool_table13[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.05;
    s = 2.5f;
    s = 0.10000000149011612f;
    s = 50.0f;
    s = 20.0f;
    s = 70.0f;
    s = 33.0f;
    s = 15.0f;
    s = 0.6499999761581421f;
    s = 0.75f;
    s = 182.04444885253906f;
}
#pragma section code_type ".text"

typedef struct {
    u8 pad_000[0x2c];
    f32 x;
    f32 y;
    f32 z;
    u8 pad_038[0x74];
} LigEntry;

typedef struct {
    u8 pad_000[0x6d4];
    s32 count;
    LigEntry entries[1];
} LigObject;

extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(s32 value);
extern void fn_1_1030D4(LigEntry *entry, void *arg);

void fn_1_D8D58(LigObject *obj, void *arg) {
    s32 count = obj->count;
    LigEntry *entry = obj->entries;

    while (count > 0) {
        u32 flags = *(u32 *)((u8 *)entry + 8);

        if ((flags >> 28) & 1) {
            f32 x = 0.65f;
            f32 y = 0.75f;
            entry->x = x;
            entry->y = y;
            entry->z = 1.0f;
        } else if ((flags >> 29) & 1) {
            f32 x = 1.0f;
            f32 y = 0.0f;
            entry->x = x;
            entry->y = y;
            entry->z = y;
        } else {
            entry->x = __fabs(lbl_8006D188(
                (s32)((f32)lbl_801A66A0 * 182.04444885253906f)));
            entry->y = __fabs(lbl_8006D188(
                (s32)((f32)lbl_801A66A0 * 182.04444885253906f * 0.5)));
            entry->z = __fabs(lbl_8006D188(
                (s32)((f32)lbl_801A66A0 * 182.04444885253906f * 2.0)));
        }

        fn_1_1030D4(entry, arg);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_D8D58 */

/* fzgx:begin fn_1_D8EEC */
typedef struct {
    u8 unk_0[0xac];
} fn_1_D8EEC_LigEntry;

typedef struct {
    u8 unk_0[0x6d4];
    s32 unk_6d4;
    fn_1_D8EEC_LigEntry unk_6d8[1];
} fn_1_D8EEC_LigObject;

extern void fn_1_103264(fn_1_D8EEC_LigEntry *entry, void *arg);

// Applies the operation to each entry in the object.
void fn_1_D8EEC(fn_1_D8EEC_LigObject *obj, void *arg) {
    s32 count = obj->unk_6d4;
    fn_1_D8EEC_LigEntry *entry = obj->unk_6d8;

    while (count > 0) {
        fn_1_103264(entry, arg);
        count--;
        entry++;
    }
}
/* fzgx:end fn_1_D8EEC */

/* fzgx:begin fn_1_D8F4C */
typedef struct {
    u8 pad_0[0x24];
    u32 unk_24;
} FnInputData;

typedef struct {
    FnInputData *unk_0;
} FnInput;

u32 fn_1_D8F4C(s32 index, FnInput *input) {
    FnInputData *data = input->unk_0;
    Obj_1_data_2A7E0_At3C *state = lbl_1_data_2A7E0.unk_3C;
    u32 value = data->unk_24;

    switch (index) {
    case 0:
        state->unk_6CC = value;
        break;
    case 1:
        state->unk_6D0 = value;
        break;
    case 2:
        if (state->unk_1C58 == 0) {
            state->unk_1C58 = (u32)data;
        }
        break;
    case 3:
        if (state->unk_1C5C == 0) {
            state->unk_1C5C = (u32)data;
        }
        break;
    }

    return 1;
}
/* fzgx:end fn_1_D8F4C */
