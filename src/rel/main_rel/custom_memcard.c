#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/custom_memcard.h"

extern u32 lbl_801A6410;
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char* format, ...);
extern void fn_1_46B4(u32 arg0, void* arg1, u8* arg2, s32 arg3);
extern void fn_80008BA8(void*, void*, s32);
extern u32 lbl_1_bss_8CA6C[1605];
extern void fn_1_1324C4(void *arg0);
extern void fn_1_132774(void *arg0);

extern u32 lbl_801A6410;
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char* format, ...);
extern void fn_80008BA8(void*, void*, s32);
extern void fn_1_46B4(u32 arg0, void* arg1, u8* arg2, s32 arg3);

/* fzgx:begin fn_1_1312F0 */
// Reset the memcard state after reporting an unavailable card.

void fn_1_1312F0(void) {
    u8* state = (u8*)&lbl_1_bss_8CA40;
    void* memcard;

    if (fn_1_B7C00() == 0) {
        if (fn_1_B7CD4() == 0) {
            OSReport((const char*)lbl_1_data_40EF8, fn_1_B7C5C());
        }

        memcard = *(void**)(state + 0x18);
        *(s32*)(state + 0x00) = -1;
        *(s32*)(state + 0x08) = -1;
        *(s32*)(state + 0x0c) = 0;
        if (memcard != 0) {
            fn_1_46B4(lbl_801A6410, memcard, lbl_1_data_40EA4, 0x136);
            *(void**)(state + 0x18) = 0;
        }
    }
}
/* fzgx:end fn_1_1312F0 */

/* fzgx:begin fn_1_131390 noprologue */
#include "types.h"
#include "dolphin/os/OSTime.h"

typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0x14];
} MemcardRequest;

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 pad_0C[4];
    u32 unk_10;
    u8 pad_14[4];
    u32 unk_18;
} MemcardState;

extern MemcardState lbl_1_bss_8CA40;
extern u32 lbl_801A6410;
extern u8 lbl_1_data_40EA4[0x54];
extern u8 lbl_1_data_40F0C[0x22];

extern void OSPanic(const char* arg0, s32 arg1, const char* arg2, ...);
extern u32 fn_1_4630(u32 arg0, u32 arg1, u8* arg2, u32 arg3);
extern void fn_80008BEC(void* dst, s32 value, u32 size);
extern void fn_1_AA6D8(s32 arg0, u8 arg1, void* arg2);

void fn_1_131390(void) {
    MemcardState* state = &lbl_1_bss_8CA40;
    OSCalendarTime cal;
    MemcardRequest request;
    u8* buf;

    if (state->unk_10 == 0) {
        OSPanic((const char*)lbl_1_data_40EA4, 0x147, (const char*)lbl_1_data_40F0C);
        state->unk_00 = -1;
        state->unk_08 = -1;
        state->unk_10 = 0;
    } else if (state->unk_08 == -1) {
        state->unk_00 = -1;
    } else {
        buf = (u8*)fn_1_4630(lbl_801A6410, 0x20700, lbl_1_data_40EA4, 0x154);
        state->unk_18 = (u32)buf;
        fn_80008BEC(buf, 0, 0x20700);
        OSTicksToCalendarTime(OSGetTime(), &cal);
        fn_80008BEC(&request, 0, 0x24);
        request.unk_4 = 0x104;
        request.unk_0 = 3;
        request.unk_C = state->unk_18;
        request.unk_8 = 0;
        fn_1_AA6D8(2, state->unk_08, &request);
        state->unk_04 = 5;
    }
}
/* fzgx:end fn_1_131390 */

/* fzgx:begin fn_1_1314A4 */
// Reset the card state and release the card after an unavailable-card report.
void fn_1_1314A4(void) {
    u8* state = (u8*)&lbl_1_bss_8CA40;
    void* card;

    if (fn_1_B7C00() == 0) {
        if (fn_1_B7CD4() == 0) {
            OSReport((const char*)lbl_1_data_40EF8, fn_1_B7C5C());
        }

        fn_80008BA8(*(void**)(state + 0x10),
                    *(void**)(state + 0x18),
                    0x20700);

        card = *(void**)(state + 0x18);
        *(s32*)(state + 0x00) = -1;
        *(s32*)(state + 0x08) = -1;
        *(void**)(state + 0x10) = 0;

        if (card != 0) {
            fn_1_46B4(lbl_801A6410, card, lbl_1_data_40EA4, 0x188);
            *(void**)(state + 0x18) = 0;
        }
    }
}
/* fzgx:end fn_1_1314A4 */

/* fzgx:begin fn_1_131558 noprologue */
#include "types.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 pad_0C[8];
    u32 unk_14;
    u8 pad_18[0x128];
    u8 unk_140[0x1800];
} CustomMemcardState;

extern CustomMemcardState lbl_1_bss_8CA40;
extern u8 lbl_1_data_40EA4[84];
extern char lbl_1_data_40F30[34];

extern void OSPanic(const char* arg0, s32 arg1, const char* arg2, ...);
extern void fn_80008BEC(void* dst, s32 value, u32 size);
extern void fn_1_AA6D8(s32 arg0, u8 arg1, void* arg2);

void fn_1_131558(void) {
    CustomMemcardState* state = &lbl_1_bss_8CA40;
    u8 request[0x24];

    if (state->unk_14 == 0) {
        OSPanic((const char*)lbl_1_data_40EA4, 0x197, (const char*)lbl_1_data_40F30);
        state->unk_00 = -1;
        state->unk_08 = -1;
    } else if (state->unk_08 == -1) {
        state->unk_00 = -1;
    } else {
        fn_80008BEC(state->unk_140, 0, 0x1800);
        fn_80008BEC(request, 0, 0x24);
        request[0] = 3;
        *(void**)((u8*)request + 0x0C) = state->unk_140;
        fn_1_AA6D8(4, (u8)state->unk_08, request);
        state->unk_04 = 7;
    }
}
/* fzgx:end fn_1_131558 */

/* fzgx:begin fn_1_131620 */
extern u32 lbl_801A6410;
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char* format, ...);
extern void fn_1_46B4(u32 arg0, void* arg1, u8* arg2, s32 arg3);
extern void fn_80008BA8(void*, void*, s32);
extern u32 lbl_1_bss_8CA6C[1605];
extern void fn_1_1324C4(void *arg0);
extern void fn_1_132774(void *arg0);

extern u32 lbl_801A6410;
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char* format, ...);
extern void fn_80008BA8(void*, void*, s32);
extern void fn_1_46B4(u32 arg0, void* arg1, u8* arg2, s32 arg3);

extern u32 lbl_801A6410;
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char*, ...);
extern void fn_1_46B4(u32, void*, u8*, s32);

typedef struct {
    u8 pad_00[0x24];
    u32 unk_24;
    u32 unk_28;
    void* unk_2C;
} MemcardEntry;
typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 pad_0C[8];
    void** unk_14;
    u8 pad_18[0x128];
    MemcardEntry unk_140[128];
} MemcardState;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s32 fzgx_obj_lbl_1_bss_8CA40;
u32 lbl_1_bss_8CA44__fzgx_offset_0;
s32 lbl_1_bss_8CA44__fzgx_offset_4;
u32 lbl_1_bss_8CA44__fzgx_offset_8[2];
void**lbl_1_bss_8CA44__fzgx_offset_10;
u32 lbl_1_bss_8CA44__fzgx_offset_14[5];
u32 lbl_1_bss_8CA6C__fzgx_offset_0[69];
MemcardEntry lbl_1_bss_8CA6C__fzgx_offset_114[128];
u8 fzgx_obj_lbl_1_bss_8E380;
u8 fzgx_pool_lbl_1_bss_8CA40_gap_8E381;
u16 fzgx_pool_lbl_1_bss_8CA40_gap_8E381_fill_8E382;
u32 fzgx_obj_lbl_1_bss_8E384[17];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8CA40;
    s = *(u8 *)&lbl_1_bss_8CA44__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_8CA44__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_8CA44__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_8CA44__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_8CA44__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_8CA6C__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_8CA6C__fzgx_offset_114;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E380;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8CA40_gap_8E381;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8CA40_gap_8E381_fill_8E382;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E384;
}
#pragma section code_type ".text"

void fn_1_131620(void) {
    
    struct { u32 value; } i;
    MemcardEntry* entry;
    u32 lab_t1;
    if (fn_1_B7C00() == 0) {
        if (fn_1_B7CD4() == 0) {
            lab_t1 = fn_1_B7C5C();
            OSReport((const char*)lbl_1_data_40EF8, lab_t1);
            entry = lbl_1_bss_8CA6C__fzgx_offset_114;
            for (i.value = 0; i.value < 128; i.value++) {
                if (entry[i.value].unk_24 != 0) {
                    fn_1_46B4(lbl_801A6410, entry[i.value].unk_2C, lbl_1_data_40EA4, 0x1c9);
                }
            }
            fzgx_obj_lbl_1_bss_8CA40 = -1;
        } else {
            entry = lbl_1_bss_8CA6C__fzgx_offset_114;
            for (i.value = 0; i.value < 128; i.value++, entry++) {
                if (entry->unk_24 != 0) {
                    lbl_1_bss_8CA44__fzgx_offset_10[i.value] = entry->unk_2C;
                } else {
                    lbl_1_bss_8CA44__fzgx_offset_10[i.value] = 0;
                }
            }
            fzgx_obj_lbl_1_bss_8CA40 = -1;
            lbl_1_bss_8CA44__fzgx_offset_4 = -1;
        }
    }
}
/* fzgx:end fn_1_131620 */

/* fzgx:begin fn_1_1317B4 */
u32 fn_1_1317B4(void) {
    return lbl_1_bss_8CA6C[0];
}
/* fzgx:end fn_1_1317B4 */

/* fzgx:begin fn_1_1317C4 */
extern u32 lbl_801A6410;


extern u32 fn_1_4630(u32 arg0, u32 arg1, u8 *arg2, u32 arg3);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);
extern s32 fn_1_B7E98(s32 arg0);
extern void fn_1_AA6D8(s32 arg0, s32 arg1, void *arg2);

typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[0x14];
} MemcardRequest;

void fn_1_1317C4(void) {
    MemcardRequest request;

    lbl_1_bss_8E384.unk_0 = fn_1_4630(
        lbl_801A6410, 0x20700, (*(u8 (*)[84])&lbl_1_data_40EA4), 0x1f3);

    fn_80008BEC(&request, 0, 0x24);
    request.unk_4 = 4;
    request.unk_4 |= 0x4000;
    request.unk_4 |= 0x2000;
    request.unk_0 = 3;
    request.unk_C = lbl_1_bss_8E384.unk_0;
    request.unk_8 = 0;

    if (fn_1_B7E98(0) != 0) {
        fn_1_AA6D8(2, 0, &request);
    } else if (fn_1_B7E98(1) != 0) {
        fn_1_AA6D8(2, 1, &request);
    } else {
        fn_1_AA6D8(2, 0, &request);
    }

    lbl_1_bss_8E380 = 1;
}
/* fzgx:end fn_1_1317C4 */

/* fzgx:begin fn_1_1318B8 */
u8 fn_1_1318B8(void) {
    return lbl_1_bss_8E380 != 0;
}
/* fzgx:end fn_1_1318B8 */

/* fzgx:begin fn_1_1318D4 */
// Completes the pending memory-card operation and clears its active flag.
s32 fn_1_1318D4(void) {
    s32 error;

    if (lbl_1_bss_8E380 == 0) {
        return 0;
    }

    if (fn_1_B7C00() != 0) {
        return 1;
    }

    if (fn_1_B7CD4() == 0) {
        error = fn_1_B7C5C();
        OSReport((const char*)lbl_1_data_40EF8, error);
    }

    if (lbl_1_bss_8E384.unk_0 != 0) {
        fn_1_46B4(lbl_801A6410, (void*)lbl_1_bss_8E384.unk_0,
                   lbl_1_data_40EA4, 0x22b);
        lbl_1_bss_8E384.unk_0 = 0;
    }

    lbl_1_bss_8E380 = 0;
    return 1;
}
/* fzgx:end fn_1_1318D4 */

/* fzgx:begin fn_1_13198C */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u8 pad_0[0x98];
    u8 unk_98;
    u8 pad_99[0xF];
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    u8 pad_B4[0x4E0 - 0xB4];
} EntryObj;

extern void OSReport(const char *, ...);
extern void fn_8006F038(Vec3 *, Vec3 *, s16);
extern void lbl_8006DCDC(void);
extern void fn_1_F7870(u32);
extern u32 lbl_1_rodata_8610[3];
extern const f32 lbl_1_rodata_861C;
extern void lbl_8006D7DC(void *);
extern u32 lbl_8006DB74(void *);
extern u32 lbl_8006DFE8(void *);
extern void fn_1_8E728(void *, u8);
extern void fn_1_13C134(void);
extern void fn_1_9250C(void *);
extern void fn_1_13C16C(void);
extern s32 fn_1_12CB04(s16);

#pragma opt_common_subexpressions off
#pragma opt_lifetimes off
#pragma opt_loop_invariants on
#pragma opt_dead_assignments off
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_13198C(s16 idx, void *a1, void *a2, EntryObj *a3, EntryObj *a4, s32 mode) {
    f32 fzgx_value;
    u8 buf[60];
    u32 mask[3];
    struct { s16 value; } id;
    u32 off;
    s16 e;
    EntryObj *cur;
    s16 v;
    EntryObj *p;
    s16 i;
    Vec3 * lab_t0;

    id.value = idx;
    off = id.value * 0x20;
    e = *(s16 *)(((u8 *)&lbl_1_bss_8B3A0) + off + 0xE);
    if (lbl_1_bss_8B3A0.unk_94 & 0x80000000u) {
        return;
    }

    if (e == -1) {
        return;
    }

    cur = (EntryObj *)((u8 *)a3 + id.value * 0x4E0);
    if (0 == cur) {
        OSReport((const char *)&lbl_1_data_41928);
        return;
    }

    lab_t0 = (Vec3 *)a1;
    fn_8006F038(lab_t0, (Vec3 *)a2, 0);
    lbl_8006DCDC();
    fn_1_F7870((u32)&lbl_1_data_1E5C0);

    mask[0] = (*((((lbl_1_rodata_8610)) + ((0)))));
    mask[1] = (*((((lbl_1_rodata_8610)) + ((1)))));
    mask[2] = (*((((lbl_1_rodata_8610)) + ((2)))));
    lbl_8006D7DC(mask);
    lbl_8006DB74(buf);

    for (v = 0; v < 8; v++) {
        if (*(u8 *)(((off) + ((0x14) + ((u8 *)&lbl_1_bss_8B3A0)))) & (1 << v)) {
            break;
        }
    }
    v = v % 4;

    lbl_8006DFE8(buf);

    cur->unk_A8 = lbl_1_rodata_861C;
    fzgx_value = lbl_1_rodata_861C;
    cur->unk_AC = fzgx_value;
    cur->unk_B0 = lbl_1_rodata_861C;
    fn_1_8E728(cur, (u8)v);
    if (1 == mode) {
        fn_1_13C134();
    }
    fn_1_9250C(cur);
    if (1 == mode) {
        fn_1_13C16C();
    }

    p = (EntryObj *)((u8 *)a4 + id.value * 0x9C0);
    for (i = 0; i < (s16)fn_1_12CB04(e); i++) {
        if (p != 0) {
            p->unk_A8 = lbl_1_rodata_861C;
            p->unk_AC = lbl_1_rodata_861C;
            p->unk_B0 = lbl_1_rodata_861C;
            if (p->unk_98 != v) {
                fn_1_8E728(p, (u8)v);
            }
            if (1 == mode) {
                fn_1_13C134();
            }
            fn_1_9250C(p);
            if (1 == mode) {
                fn_1_13C16C();
            }
        }
        p = ((1) + (p));
    }
}
#pragma opt_propagation reset

#pragma opt_common_subs reset

#pragma opt_dead_assignments reset

#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset

#pragma opt_common_subexpressions reset
/* fzgx:end fn_1_13198C */

/* fzgx:begin fn_1_131B90 */
typedef struct Obj Obj;

struct Obj {
    s16 index;
    u8 pad_2[2];
    u32 field_4;
    u32 field_8;
    u8 pad_c[0x2c];
    u32 field_38;
    u32 field_3c;
    u32 field_40;
    u32 field_44;
    u32 field_48;
    u32 field_4c;
    u32 field_50[1];
};

extern void fn_1_13198C(s16, u32*, u32*, u32, u32, u32);

#pragma opt_propagation off
s32 fn_1_131B90(Obj* obj) {
    u32 local_a[3];
    u32 local_b[3];
    u32 a0;
    u32 a1;
    u32 b0;
    u32 b1;
    s16 index;

    a1 = obj->field_44;
    a0 = obj->field_48;
    local_b[0] = a1;
    local_b[1] = a0;
    local_b[2] = obj->field_4c;
    b1 = obj->field_38;
    b0 = obj->field_3c;
    local_a[0] = b1;
    local_a[1] = b0;
    local_a[2] = obj->field_40;
    index = obj->index;
    fn_1_13198C(index, local_a, local_b, obj->field_4, obj->field_8,
                obj->field_50[index]);
    return 0;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_131B90 */

/* fzgx:begin fn_1_131C08 noprologue */
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"
#include "psvec.h"

/* begin rel/main_rel/custom_memcard.h (fork-deltawave784/windows-and-types@4b722344) */
#ifndef REL_MAIN_REL_CUSTOM_MEMCARD_H
#define REL_MAIN_REL_CUSTOM_MEMCARD_H

/* begin rel/main_rel/globals.h (fork-deltawave784/windows-and-types@4b722344) */
#ifndef REL_MAIN_REL_GLOBALS_H
#define REL_MAIN_REL_GLOBALS_H


// Generated by `fzgx headers --module main_rel`: layouts recovered from every access in the
// module's disassembly (matched or not). Field names are offsets until the librarian names them;
// offsets and widths are facts, names are not. Regenerate rather than hand-edit padding.

// lbl_1_bss_960: .bss size 0x2, referenced by 110 functions, shape {'object': 231}
extern u16 lbl_1_bss_960;

// lbl_1_bss_8B3A0: .bss size 0x14C, referenced by 87 functions, shape {'object': 253}
// object reached through lbl_1_bss_8B3A0.unk_A4
typedef struct {
    u8 pad_0[0x19];
    u8 unk_19;  // 1 loads, 0 stores
} Obj_1_bss_8B3A0_AtA4;
typedef struct {
    s16 unk_0;  // 12 loads, 2 stores
    u8 pad_2[0x2];
    s16 unk_4;  // 13 loads, 0 stores
    u8 pad_6[0x2];
    s16 unk_8;  // 7 loads, 2 stores
    u8 pad_A[0x4];
    s16 unk_E;  // 24 loads, 0 stores
    u8 pad_10[0x4];
    u8 unk_14;  // 7 loads, 2 stores
    u8 pad_15[0x19];
    s16 unk_2E;  // 1 loads, 0 stores
    u8 pad_30[0x5C];
    s16 unk_8C;  // 2 loads, 0 stores
    u8 pad_8E[0x2];
    s16 unk_90;  // 15 loads, 0 stores
    s16 unk_92;  // 1 loads, 0 stores
    u32 unk_94;  // 60 loads, 3 stores
    u8 pad_98[0x6];
    u8 unk_9E;  // 7 loads, 0 stores
    u8 unk_9F;  // 8 loads, 3 stores
    u8 pad_A0[0x4];
    Obj_1_bss_8B3A0_AtA4 *unk_A4;  // 4 loads, 0 stores
    u8 pad_A8[0x8];
    s16 unk_B0;  // 1 loads, 1 stores
    s16 unk_B2;  // 1 loads, 1 stores
    u8 pad_B4[0xC];
    s16 unk_C0;  // 2 loads, 4 stores
    s16 unk_C2;  // 2 loads, 4 stores
    u8 pad_C4[0xC];
    s16 unk_D0;  // 1 loads, 2 stores
    s16 unk_D2;  // 1 loads, 2 stores
    u8 pad_D4[0xC];
    u32 unk_E0;  // 0 loads, 2 stores
    u32 unk_E4;  // 0 loads, 1 stores
    u32 unk_E8;  // 0 loads, 1 stores
    u32 unk_EC;  // 0 loads, 1 stores
    u32 unk_F0;  // 2 loads, 2 stores
    u32 unk_F4;  // 0 loads, 1 stores
    u32 unk_F8;  // 0 loads, 1 stores
    u32 unk_FC;  // 0 loads, 1 stores
    u32 unk_100;  // 2 loads, 2 stores
    u32 unk_104;  // 0 loads, 1 stores
    u32 unk_108;  // 0 loads, 1 stores
    u32 unk_10C;  // 0 loads, 1 stores
    u32 unk_110;  // 2 loads, 2 stores
    u32 unk_114;  // 0 loads, 1 stores
    u32 unk_118;  // 0 loads, 1 stores
    u32 unk_11C;  // 0 loads, 1 stores
    u32 unk_120;  // 0 loads, 2 stores
    u32 unk_124;  // 1 loads, 2 stores
    u8 unk_128;  // 0 loads, 1 stores
    u8 unk_129;  // 1 loads, 2 stores
    u8 pad_12A[0x2];
    s16 unk_12C;  // 4 loads, 0 stores
    s16 unk_12E;  // 1 loads, 0 stores
    s16 unk_130;  // 1 loads, 0 stores
    s16 unk_132;  // 1 loads, 0 stores
    s16 unk_134;  // 1 loads, 0 stores
    s16 unk_136;  // 1 loads, 0 stores
    s16 unk_138;  // 1 loads, 0 stores
    s16 unk_13A;  // 1 loads, 0 stores
    s16 unk_13C;  // 1 loads, 0 stores
    u8 pad_13E[0x2];
    u32 unk_140;  // 3 loads, 0 stores
    u8 pad_144[0x2];
    s16 unk_146;  // 4 loads, 0 stores
    s16 unk_148;  // 2 loads, 0 stores
    u8 pad_14A[0x2];
} Obj_1_bss_8B3A0;
extern Obj_1_bss_8B3A0 lbl_1_bss_8B3A0;

#endif  // REL_MAIN_REL_GLOBALS_H

// lbl_1_data_1E5C0: .data size 0x34, 2 refs from custom_memcard.c
#ifndef FZGX_TYPES_LBL_1_DATA_1E5C0
#define FZGX_TYPES_LBL_1_DATA_1E5C0
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u32 unk_0;  // 1 loads, 0 stores
    u32 unk_4;  // 1 loads, 0 stores
    u32 unk_8;  // 1 loads, 0 stores
    u32 unk_C;  // 1 loads, 0 stores
    u32 unk_10;  // 1 loads, 0 stores
    u32 unk_14;  // 1 loads, 0 stores
    u32 unk_18;  // 1 loads, 0 stores
    u32 unk_1C;  // 1 loads, 0 stores
    u32 unk_20;  // 1 loads, 0 stores
    u32 unk_24;  // 1 loads, 0 stores
    u32 unk_28;  // 1 loads, 0 stores
    u32 unk_2C;  // 1 loads, 0 stores
    u32 unk_30;  // 1 loads, 0 stores
} Obj_1_data_1E5C0;
#endif
extern Obj_1_data_1E5C0 lbl_1_data_1E5C0;  // typedefs.json decl override

// lbl_1_bss_962: .bss size 0x2, 2 refs from custom_memcard.c
extern s16 lbl_1_bss_962;

#endif  // REL_MAIN_REL_CUSTOM_MEMCARD_H
#ifndef GAME_MAIN_REL_SHADOWMAP_TYPES_H
#define GAME_MAIN_REL_SHADOWMAP_TYPES_H
#ifndef REL_MAIN_REL_SHADOWMAP_H
#define REL_MAIN_REL_SHADOWMAP_H

#endif  // REL_MAIN_REL_SHADOWMAP_H

typedef struct fn_1_568F8_Data {
    u8 pad_0[0x38c];
    u8 light_mask;               // 0x38c
    u8 pad_38d[0x2b];
    s16 light_param;             // 0x3b8
} fn_1_568F8_Data;

extern void fn_1_870BC(fn_1_568F8_Data *, s8, fn_1_568F8_Data *, s32, u8, f32);

#endif  // GAME_MAIN_REL_SHADOWMAP_TYPES_H

/* end game/main_rel/shadowmap_types.h */

typedef struct Sig_fn_8006F038_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_8006F038_Vec3;

struct fn_1_131C08_lbl_1_bss_8B3A0_0_E32 {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[4];
    u8 unk_14;
    u8 pad_15[0xB];
};
struct fn_1_131C08_Arg0 {
    s16 unk_0;
    u8 pad_2[0xA];
    fn_1_568F8_Data *unk_C;
    void *unk_10;
    s16 unk_14;
    u8 pad_16[6];
    void *unk_1C;
    u8 pad_20[0x18];
    Sig_fn_8006F038_Vec3 unk_38;
    Sig_fn_8006F038_Vec3 unk_44;
    u32 unk_50[4];
    u8 pad_60[4];
    s16 unk_64;
};

typedef struct {
    u8 pad_0[0x320];
    s16 unk_320;
    u8 pad_322[0x6E];
    u32 unk_390;
    u8 pad_394[0x26];
    s16 unk_3BA;
} Sig_fn_1_FCFA4_CasTarget;
typedef struct {
    u8 unk_0[0x40F0];
    u32 unk_40F0;
    u8 pad_40F4[0xC];
} Sig_fn_1_FCFA4_CasEntry;
typedef struct Sig_fn_1_FCFA4_CasObj {
    Sig_fn_1_FCFA4_CasTarget *unk_0;
    u8 unk_4;
    u8 pad_5[7];
    u32 unk_C;
    u8 pad_10[0x10];
    Sig_fn_1_FCFA4_CasEntry entries[4];
    s32 (*unk_10420)(void);
    s32 (*unk_10424)(struct Sig_fn_1_FCFA4_CasObj *);
    u8 pad_10428[4];
    void (*unk_1042C)(struct Sig_fn_1_FCFA4_CasObj *, Sig_fn_1_FCFA4_CasEntry *);
} Sig_fn_1_FCFA4_CasObj;

extern int fn_1_D6698(void);
extern int fn_1_D66B0(void);
extern u32 lbl_801A66A0;
extern u8 lbl_1_bss_8E3C8[8];
extern s16 lbl_1_bss_96A;
extern void *lbl_801A6D00;
extern const f32 lbl_1_rodata_8620;
extern const f64 lbl_1_rodata_8628;
extern const f32 lbl_1_rodata_8630;
extern const f32 lbl_1_rodata_8634;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern void fn_1_D66F8(u8, u8 *, s8 *);
extern void fn_1_F7870(void *);
extern void fn_8006F038(Sig_fn_8006F038_Vec3 *, Sig_fn_8006F038_Vec3 *, s16);
extern void lbl_8006DCDC(void);
extern void lbl_8006D758(void);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void lbl_8006E14C(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DFE8(void *);
extern void fn_80072558(void);
extern void fn_1_13C134(void);
extern void fn_1_13C16C(void);
extern void fn_1_870BC(fn_1_568F8_Data *, s8, fn_1_568F8_Data *, s32, u8, f32);
extern void *fn_1_12F118(void);
extern u8 *fn_1_36AD0(void);
extern u8 fn_1_D66B8(u8);
extern void fn_1_151BDC(void *);
extern void fn_1_14E2DC(void *, s16, f32);
extern Sig_fn_1_FCFA4_CasObj *fn_1_13F8B0(u8);
extern Sig_fn_1_FCFA4_CasObj *fn_1_7F428(u32);
extern void fn_1_FCFA4(Sig_fn_1_FCFA4_CasObj *);
extern void fn_1_FD27C(Sig_fn_1_FCFA4_CasObj *, Sig_fn_1_FCFA4_CasEntry *);
extern void fn_1_FDD7C(Sig_fn_1_FCFA4_CasObj *, Sig_fn_1_FCFA4_CasEntry *);

#pragma fp_contract off
static inline void fn_1_131C08_update(u32 index, s32 active)
{
    if (active == 0) {
        ((u16 *)lbl_1_bss_8E3C8)[index] = (s32)(lbl_1_rodata_8620 * (f32)(lbl_801A66A0 % 360));
    } else {
        u16 *angles = (u16 *)lbl_1_bss_8E3C8;
        s32 angle = angles[index];
        if (angle < 0x7555) {
            angles[index] = (s32)((f64)(u32)angle + lbl_1_rodata_8628 * (lbl_1_rodata_8630 - (f32)(u32)angle));
        } else {
            angles[index] = (s32)((f64)(u32)angle + lbl_1_rodata_8628 * (lbl_1_rodata_8634 - (f32)(u32)angle));
        }
    }
}

s32 fn_1_131C08(struct fn_1_131C08_Arg0 *arg0, f32 arg1)
{
    Obj_1_bss_8B3A0 *p_lbl_1_bss_8B3A0;
    s16 v0;
    s16 v7;
    s32 v2;
    u8 v6;
    u32 v12;
    s32 v13;
    u8 loc_9;
    s8 loc_8;
    f32 matrix[3][4];
    fn_1_568F8_Data *model;
    u8 *pool;
    u8 *entry;
    s16 index;
    s16 selected;
    Sig_fn_1_FCFA4_CasObj *object;
    Sig_fn_1_FCFA4_CasTarget *target;
    u8 oldMode;
    u32 flags;
    u32 bit = 1;
    u8 bits;

    v0 = arg0->unk_0;
    v7 = ((struct fn_1_131C08_lbl_1_bss_8B3A0_0_E32 *)&lbl_1_bss_8B3A0)[v0].unk_E;
    v2 = arg0->unk_50[v0];
    v6 = 0;
    while (v6 < 8) {
        bits = ((struct fn_1_131C08_lbl_1_bss_8B3A0_0_E32 *)&lbl_1_bss_8B3A0)[v0].unk_14;
        if (bits & (bit << v6)) {
            break;
        }
        v6++;
    }
    p_lbl_1_bss_8B3A0 = (Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0;
    if ((p_lbl_1_bss_8B3A0->unk_94 & 0x40000000) && !(u8)fn_1_D6698()) {
        if (arg0->unk_64 != (u8)fn_1_D66B0()) {
            fn_1_D66F8((u8)arg0->unk_64, &loc_9, &loc_8);
            if ((s8)loc_9 != -1) {
                v6 = loc_8;
                v7 = (s8)loc_9;
            }
        }
    }
    if (p_lbl_1_bss_8B3A0->unk_94 & 0x80000000) return 0;
    if (v7 == -1) return 0;
    fn_8006F038(&arg0->unk_38, &arg0->unk_44, 0);
    lbl_8006DCDC();
    fn_1_F7870(&lbl_1_data_1E5C0);
    if ((p_lbl_1_bss_8B3A0->unk_94 & 0x40000000) && !(u8)fn_1_D6698()) {
        v12 = arg0->unk_64;
        v13 = 0;
        if (v12 == (u8)fn_1_D66B0()) {
            s16 active;
            if (*(s16 *)&lbl_1_bss_960 == 1) {
                s32 activeOffset = lbl_1_bss_962 * 0x94;
                u8 *activeData = (u8 *)lbl_1_bss_8B3A0.unk_A4;
                activeData += activeOffset;
                active = *(s16 *)(activeData - 0x7F4);
            } else {
                active = *(s16 *)arg0->unk_1C;
            }
            if (active) v13 = 1;
        }
        fn_1_131C08_update(v12, v13);
    } else {
        s16 active;
        v12 = v0;
        if (*(s16 *)&lbl_1_bss_960 == 1) {
            s32 activeOffset = lbl_1_bss_962 * 0x94;
            u8 *activeData = (u8 *)lbl_1_bss_8B3A0.unk_A4;
            u8 *activeAddress = activeData + activeOffset;
            activeAddress += v0 * 0x1C;
            active = *(s16 *)(activeAddress - 0x7F4);
        } else {
            active = *(s16 *)((u8 *)arg0->unk_1C + v0 * 0x1C);
        }
        fn_1_131C08_update(v12, active);
    }
    lbl_8006D758();
    mathutil_mtxA_rotate_x(0xEAAA);
    mathutil_mtxA_rotate_y((s16)((u16 *)lbl_1_bss_8E3C8)[v12]);
    lbl_8006E14C(lbl_1_rodata_8638);
    lbl_8006DB74((u8 *)lbl_801A6D00 + 0x60);
    lbl_8006DB74(matrix);
    if (v7 < 0x29) {
        model = (fn_1_568F8_Data *)((u8 *)arg0->unk_C + v7 * 0x440);
        if (!model) return 0;
        lbl_8006DFE8((u8 *)lbl_801A6D00 + 0x60);
        fn_80072558();
        if (v2 == 1) fn_1_13C134();
        fn_1_870BC(model, (s8)arg0->unk_14, model, 0, v6, lbl_1_rodata_863C);
        if (v2 == 1) fn_1_13C16C();
    } else if ((s16)lbl_1_bss_962 != 0x14 && (s16)lbl_1_bss_96A != 0x14) {
        index = v7 - 0x29;
        entry = fn_1_12F118();
        if (entry == fn_1_36AD0()) {
            if ((p_lbl_1_bss_8B3A0->unk_94 & 0x40000000)) {
                if ((u8)fn_1_D6698()) index = v0;
                else index = fn_1_D66B8((u8)arg0->unk_64);
            } else index = v0;
        }
        entry += index * 0x81C0;
        if (!(*(u32 *)entry & 0x80000000)) return 0;
        lbl_8006DFE8((u8 *)lbl_801A6D00 + 0x60);
        fn_80072558();
        if (*(u32 *)entry & 0x40000000) {
            fn_1_151BDC(entry);
            fn_1_14E2DC((u8 *)arg0->unk_10 + index * 0xA20, arg0->unk_14, lbl_1_rodata_863C);
        } else {
            model = (fn_1_568F8_Data *)((u8 *)arg0->unk_C + entry[0x81A0] * 0x440);
            fn_1_870BC(model, (s8)arg0->unk_14, model, 0, v6, lbl_1_rodata_863C);
        }
    }
    if ((s16)lbl_1_bss_962 != 0x14 && (s16)lbl_1_bss_96A != 0x14) {
        pool = fn_1_12F118();
        selected = v0;
        if (lbl_1_bss_962 == 0x10) {
            if (v7 < 0x29) return 0;
            v0 = v7 - 0x29;
            selected = v0;
        }
        if (!pool) return 0;
        entry = pool + v0 * 0x81C0;
        if (!(*(u32 *)entry & 0x80000000)) return 0;
        if (lbl_1_bss_962 == 0x10 || lbl_1_bss_962 == 0x12) {
            if (lbl_1_bss_962 == 0x10 && lbl_1_bss_8B3A0.unk_0 == 0) return 0;
            if (selected >= 8) return 0;
            if (entry[7] == 0) return 0;
            lbl_8006DFE8(matrix);
            fn_80072558();
            if (fn_1_13F8B0((u8)selected)) {
                fn_1_FCFA4(fn_1_13F8B0((u8)selected));
            }
        } else if (lbl_1_bss_962 == 0x24) {
            object = fn_1_7F428((u8)selected);
            if (!object) return 0;
            target = object->unk_0;
            if (selected >= 4) return 0;
            if (entry[7] == 0) return 0;
            if (!target) return 0;
            if (object) {
                oldMode = target->unk_3BA;
                flags = object->unk_C;
                lbl_8006DFE8(matrix);
                fn_80072558();
                if (lbl_1_bss_8B3A0.unk_0 == 0) {
                    target->unk_3BA = 1;
                } else {
                    target->unk_390 &= ~0x200000;
                    target->unk_3BA = 0;
                }
                object->unk_1042C = fn_1_FD27C;
                object->unk_C = 0x20000000;
                fn_1_FCFA4(object);
                object->unk_1042C = fn_1_FDD7C;
                object->unk_C = flags;
                target->unk_3BA = oldMode;
            }
        }
    }
    return 0;
}
/* fzgx:end fn_1_131C08 */

/* fzgx:begin fn_1_132488 */
void fn_1_132488(void *arg0) {
    if ((lbl_1_bss_8B3A0.unk_94 & 0x40000000) != 0) {
        fn_1_1324C4(arg0);
    } else {
        fn_1_132774(arg0);
    }
}
/* fzgx:end fn_1_132488 */

/* fzgx:begin fn_1_1324C4 */
struct fn_1_1324C4_f32 {
    f32 unk_0;
};

extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_8644;
extern const f32 lbl_1_rodata_864C;
extern const f32 lbl_1_rodata_8650;
extern const struct fn_1_1324C4_f32 lbl_1_rodata_8640;
extern const struct fn_1_1324C4_f32 lbl_1_rodata_8648;
extern s32 lbl_801A66B4;
extern int fn_1_8623C(void);
extern void fn_1_134AD4(void);
extern void fn_1_136174(s32, s32, s32, s32, s32, s32, s32, f32, f32);
extern void fn_1_1363F0(s32, s32, s32);
extern void fn_1_13DDB8(void);
extern void fn_1_13EA9C(void *);
extern void *fn_1_13F7F8(s32, s32);
extern void fn_1_132FB4(void);
extern void fn_1_133DBC(s32);
extern void fn_1_134A4C(void);
extern void fn_1_134EE4(s32, s32, s32, f32);
extern void fn_1_135894(s16, s16, s32, s32, s32, s32, s32, f32, f32);
extern void fn_1_1368A0(s32, s32, s32, f32, f32, f32, f32, f32);
extern void fn_1_13750C(s32, s32, s32, s32);
extern void fn_1_1380F0(void *);
extern void fn_1_139AEC(void *);
extern void fn_1_139D60(void *);
extern void fn_1_139F18(void *);
extern void fn_1_13A848(s32, s32, s32, s32, s32, f32, f32);
extern void fn_1_13A994(s32, s32, s32, s32, s32, s32, f32, f32);
extern void fn_1_13B328(u32, s32);
extern void fn_1_13D02C(void);
extern void fn_1_13DA0C(void);
extern void fn_1_13DC54(void);
extern void fn_1_13E054(s32, s32);
extern void fn_1_13EDDC(s32, s32, s32, s32, s32);
extern void fn_1_49410(void);

static inline s32 fn_1_1324C4_inl(s32 a) {
    if (lbl_801A66B4 == 5) {
        return 0;
    }
    if (a > 40) {
        return 4;
    }
    return 7;
}

static inline f32 fn_1_1324C4_read_pointer(const struct fn_1_1324C4_f32 * owner) { return owner->unk_0; }
#pragma opt_common_subs off
void fn_1_1324C4(void *arg0) {
    s32 v0;
    s16 v1;
    s16 v2;
    s32 t;
    s32 lab_t1;

    v0 = lbl_1_bss_8B3A0.unk_0 == 10;
    fn_1_13D02C();
    fn_1_49410();
    if ((lbl_1_bss_8B3A0.unk_94 & 0x80000000) == 0) {
        fn_1_139F18(arg0);
        fn_1_139D60(arg0);
        if (v0 == 0) {
            fn_1_139AEC(arg0);
        }
    }
    fn_1_133DBC(1);
    fn_1_134AD4();
    fn_1_13DA0C();
    fn_1_13DC54();
    fn_1_13DDB8();
    fn_1_134A4C();
    if (v0 != 0) {
        fn_1_13E054(24, 236);
    } else {
        fn_1_132FB4();
        fn_1_13EA9C(arg0);
    }
    if (lbl_1_bss_8B3A0.unk_A4->unk_19 != 0) {
        fn_1_1380F0(((void **)lbl_1_data_418D4)[lbl_801A66B4]);
    } else {
        fn_1_1380F0(fn_1_13F7F8(1, (s16)lbl_801A66B4));
    }
    fn_1_13B328(0x30800000, 0);
    v1 = fn_1_8623C();
    v2 = ((Obj_1_bss_8B3A0 *)((u8 *)&lbl_1_bss_8B3A0 + (lbl_1_bss_8B3A0.unk_9E << 5)))->unk_E;
    fn_1_134EE4(0, 1, 0, lbl_1_rodata_861C);
    fn_1_135894(213, 366 - (lbl_801A66B4 == 5 ? 0 : (v2 > 40 ? 4 : 7)), 6, v2, 0, v1, 0, lbl_1_rodata_863C, lbl_1_rodata_863C);
    {
        f32 h = lbl_1_rodata_85F0;
        fn_1_136174(213, 355, 1, v2, (s16)lbl_801A66B4, v1, 0, h, h);
    }
    lab_t1 = 385;
    fn_1_13EDDC(505, lab_t1, v2, v1, 0);
    fn_1_1363F0(v1, 0, 1);
    fn_1_1368A0(v2, v1, 0, fn_1_1324C4_read_pointer(&lbl_1_rodata_8640), lbl_1_rodata_8644, lbl_1_rodata_8648.unk_0, lbl_1_rodata_863C, lbl_1_rodata_863C);
    fn_1_13750C(23, 66, v2, v1);
    fn_1_13A848(442, 276, 1, v2, 0, lbl_1_rodata_864C, lbl_1_rodata_8650);
    {
        f32 h = lbl_1_rodata_85F0;
        fn_1_13A994(442, 296, 1, v2, (s16)lbl_801A66B4, 0, h, h);
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_1324C4 */

/* fzgx:begin fn_1_132774 */
#include "font.h"

extern u32 lbl_801A6410;
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char* format, ...);
extern void fn_1_46B4(u32 arg0, void* arg1, u8* arg2, s32 arg3);
extern void fn_80008BA8(void*, void*, s32);
extern u32 lbl_1_bss_8CA6C[1605];
extern void fn_1_1324C4(void *arg0);
extern void fn_1_132774(void *arg0);

extern u32 lbl_801A6410;
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char* format, ...);
extern void fn_80008BA8(void*, void*, s32);
extern void fn_1_46B4(u32 arg0, void* arg1, u8* arg2, s32 arg3);


extern u32 lbl_801A66B4;
extern const FontDrawPacket lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_8644;
extern const f32 lbl_1_rodata_864C;
extern const f32 lbl_1_rodata_8650;
extern const u32 lbl_1_rodata_8654;
extern const f32 lbl_1_rodata_8658;
typedef struct {
    f32 unk_0;
} F32Box;

extern const F32Box lbl_1_rodata_865C;
extern const F32Box lbl_1_rodata_8660;
extern const f32 lbl_1_rodata_8664;
extern const f32 lbl_1_rodata_8668;
extern const f32 lbl_1_rodata_866C;
extern const f32 lbl_1_rodata_8670;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_8678;
extern const f32 lbl_1_rodata_867C;
extern const f32 lbl_1_rodata_8680;
extern const f32 lbl_1_rodata_8684;
extern const f32 lbl_1_rodata_8688;
extern const f32 lbl_1_rodata_868C;
extern const f32 lbl_1_rodata_8690;

extern void fn_1_13D02C(void);
extern void fn_1_49410(void);
extern void fn_1_139F18(s16 *);
extern void fn_1_139D60(s16 *);
extern void fn_1_13A460(s16 *);
extern void fn_1_13A038(s16 *);
extern void fn_1_13A654(s16 *);
extern void fn_1_13A21C(s16 *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_133DBC(s32);
extern void fn_1_134AD4(void);
extern void fn_1_134A4C(void);
extern void *fn_1_13F7F8(s32, s32);
extern void fn_1_1380F0(void *);
extern void fn_1_13ABA8(u32);
extern void fn_1_134EE4(s32, s32, s32, f32);
extern void fn_1_135894(s32, s16, s32, s16, s32, s16, s32, f32, f32);
extern void fn_1_136174(s32, s32, s32, s16, s16, s16, s32, f32, f32);
extern void fn_1_1363F0(u8, s32, s32);
extern void fn_1_1368A0(s16, u8, s32, f32, f32, f32, f32, f32);
extern void fn_1_13750C(s32, s32, s16, s16);
extern void fn_1_13A848(s32, s32, s32, s16, s32, f32, f32);
extern void fn_1_13A994(s32, s32, s32, s16, s16, s32, f32, f32);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern void fn_1_1332FC(s32, s32, s32);
extern void fn_1_133748(s32, s32);
extern void fn_1_13354C(s32, s32, s32);
extern void fn_1_133968(void);
extern void fn_1_133A8C(void);
extern void fn_1_138A04(s32, s32, s32);
extern void fn_1_137548(s32, s32, s32, s32);
extern void fn_1_133BD8(void);
extern u8 fn_1_141F94(u8);
extern void fn_1_138E44(s32, s32, s32);
extern void fn_1_137584(s32, s32, s32, s32);
extern void fn_1_13923C(s32, s32);
extern void fn_1_13FB8C(s32, s32, s32, s32, s32, f32);
extern void fn_1_14083C(s32, s32, s32, s32, s32, f32, f32);

typedef struct {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x4];
    u8 unk_14;
    u8 pad_15[0xB];
} CardSlot;

typedef struct {
    u8 pad_0[0x14];
    s16 unk_14;
    u8 pad_16[0x7E];
} Rec94;

#pragma opt_common_subs off
void fn_1_132774(void *arg0) {
    Obj_1_bss_8B3A0 *work;
    s16 slot;
    s16 row;
    s16 index;
    s16 n;
    s16 i;
    u8 bit;
    s32 count;
    s32 sel;
    u8 pos;
    FontDrawPacket packet;
    s32 k;

    fn_1_13D02C();
    fn_1_49410();
    work = &lbl_1_bss_8B3A0;
    if (!(work->unk_94 & 0x80000000)) {
        if (work->unk_94 & 0x20000000) {
            *(s16 *)arg0 = work->unk_9E;
            fn_1_139F18(arg0);
            fn_1_139D60(arg0);
        } else if (work->unk_94 & 0x40000) {
            fn_1_13A460(arg0);
            fn_1_13A038(arg0);
        } else {
            fn_1_13A654(arg0);
            fn_1_13A21C(arg0);
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (((CardSlot *)work)[i].unk_E != -1) {
                u8 *mask = &((CardSlot *)work)[i].unk_14;
                for (bit = 0; bit < 8; bit++) {
                    if (*mask & (1 << bit)) {
                        break;
                    }
                }
                fn_1_496FC(lbl_1_rodata_8658, (f32)(i * 24 + 100));
                fn_1_4AE0C((const char *)lbl_1_data_41930, i + 1, bit);
            }
        }
    }

    fn_1_133DBC(1);
    fn_1_134AD4();
    fn_1_134A4C();
    fn_1_1380F0(fn_1_13F7F8(2, (s16)lbl_801A66B4));

    if (work->unk_94 & 0x20000000) {
        if (*(s16 *)&lbl_1_bss_960 == 2) {
            fn_1_13ABA8(0x88000000);
        } else if (*(s16 *)&lbl_1_bss_960 == 9) {
            fn_1_13ABA8(0x08000000);
        } else if (work->unk_94 & 0x02000000) {
            fn_1_13ABA8(0x28000000);
        } else {
            fn_1_13ABA8(0xA8000000);
        }
    }

    if (work->unk_94 & 0x20000000) {
        s16 card;

        sel = lbl_1_bss_8B3A0.unk_9E;
        index = sel;
        card = ((CardSlot *)&lbl_1_bss_8B3A0)[index].unk_E;
        fn_1_134EE4(0, 0, 0, lbl_1_rodata_861C);
        fn_1_135894(0xE7, 0x16E - ((s32)lbl_801A66B4 == 5 ? 0 : (card > 0x28 ? 4 : 7)), 6, card, 0, *(s16 *)arg0, 0, lbl_1_rodata_863C, lbl_1_rodata_863C);
        {
            f32 h = lbl_1_rodata_85F0;
            fn_1_136174(0xE7, 0x163, 1, card, lbl_801A66B4, *(s16 *)arg0, 0, h, h);
        }
        fn_1_1363F0(sel, 0, 0);
        fn_1_1368A0(card, sel, 0, lbl_1_rodata_865C.unk_0, lbl_1_rodata_8644, lbl_1_rodata_8660.unk_0, lbl_1_rodata_863C,
                    lbl_1_rodata_863C);
        fn_1_13750C(0x12, 0x3A, card, index);
        fn_1_13A848(0x1C0, 0x114, 1, card, 0, lbl_1_rodata_864C, lbl_1_rodata_8650);
        {
            f32 h = lbl_1_rodata_8664;
            fn_1_13A994(0x1C0, 0x128, 1, card, lbl_801A66B4, 0, h, h);
        }
    } else {
        packet = lbl_1_rodata_26F8;
        packet.image = 0x9D11;
        packet.x = lbl_1_rodata_8668;
        packet.y = lbl_1_rodata_866C;
        packet.z = lbl_1_rodata_8670;
        fn_1_4F734(&packet);
        packet.flags = 7;
        packet.x = lbl_1_rodata_8674 - packet.x;
        fn_1_4F734(&packet);

        packet = lbl_1_rodata_26F8;
        packet.image = 0x12;
        packet.x = lbl_1_rodata_8678;
        packet.y = lbl_1_rodata_867C;
        packet.scale_x *= lbl_1_rodata_8680 / (f32)fn_1_48690(packet.image);
        packet.scale_y *= lbl_1_rodata_8684 / (f32)fn_1_486C4(packet.image);
        packet.z = lbl_1_rodata_8688;
        *(u32 *)packet.color = lbl_1_rodata_8654;
        packet.alpha = lbl_1_rodata_85F0;
        fn_1_4F734(&packet);

        fn_1_1332FC(0xF, 0x38, 0);
        fn_1_1332FC(0x269, 0x38, 1);
        fn_1_133748(0x7E, 0xFD);
        fn_1_13354C(7, 0x42, 0);
        fn_1_13354C(0x279, 0x42, 1);
        fn_1_133968();

        if (work->unk_94 & 0x40000) {
            fn_1_133A8C();
            for (row = 0, n = 0; row < 4; row++) {
                s16 card = ((CardSlot *)&lbl_1_bss_8B3A0)[row].unk_E;
                if (card != -1) {
                    switch (n) {
                    case 0:
                        k = row;
                        fn_1_138A04(0xE, 0x41, k);
                        fn_1_137548(0x26, 0x7B, card, k);
                        break;
                    case 1:
                        k = row;
                        fn_1_138A04(0xE, 0x10A, k);
                        fn_1_137548(0x26, 0x144, card, k);
                        break;
                    }
                    n++;
                }
            }
        } else {
            fn_1_1332FC(0x13C, 0x38, 0);
            fn_1_133BD8();
            for (slot = 0; slot < 4; slot++) {
                s16 card = ((CardSlot *)&lbl_1_bss_8B3A0)[slot].unk_E;
                pos = fn_1_141F94(slot);
                if (card != -1) {
                    switch (pos) {
                    case 0:
                        k = slot;
                        fn_1_138E44(0xE, 0x41, k);
                        fn_1_137584(0x1E, 0x88, card, k);
                        break;
                    case 1:
                        k = slot;
                        fn_1_138E44(0x13A, 0x41, k);
                        fn_1_137584(0x14B, 0x88, card, k);
                        break;
                    case 2:
                        k = slot;
                        fn_1_138E44(0xE, 0x10A, k);
                        fn_1_137584(0x1E, 0x151, card, k);
                        break;
                    case 3:
                        k = slot;
                        fn_1_138E44(0x13A, 0x10A, k);
                        fn_1_137584(0x14B, 0x151, card, k);
                        break;
                    }
                }
            }
            for (pos = lbl_1_bss_8B3A0.unk_4; pos < 4; pos++) {
                fn_1_13923C((pos % 2) * 0x12D + 0x1E, (pos / 2) * 0xC9 + 0x88);
            }
        }
    }

    if (*(s16 *)&lbl_1_bss_960 != 2 && !(work->unk_94 & 0x02000000)) {
        s32 car;
        s16 time;
        s16 cur = lbl_1_bss_962;

        car = lbl_1_bss_8B3A0.unk_0;
        time = ((Rec94 *)((u8 *)lbl_1_bss_8B3A0.unk_A4 - 0x818))[cur].unk_14;
        count = 0x9E;
        if ((s16)car == 0) {
            if (lbl_1_bss_8B3A0.unk_4 == 4) {
                count = 0x7E;
            } else {
                count = 0xAB;
            }
        }
        if (time > 0 || (lbl_1_bss_8B3A0.unk_140 & 0x80000000)) {
            fn_1_13FB8C(0x140, 0xF0, 0x16D, count, car == 3, lbl_1_rodata_868C);
            fn_1_14083C(0x140, 0xF0, 0x16D, count, 10, lbl_1_rodata_8690, lbl_1_rodata_863C);
        }
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_132774 */

/* fzgx:begin fn_1_132FB4 */
#include "font.h"

extern u32 lbl_1_rodata_8694[4];
extern u32 lbl_1_rodata_86A4[4];
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_86B4;
extern const f32 lbl_1_rodata_86B8;
extern const f32 lbl_1_rodata_86BC;
extern const f32 lbl_1_rodata_86C0;
extern const f32 lbl_1_rodata_86C4;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_86CC;
extern const f32 lbl_1_rodata_86D0;
extern const f32 lbl_1_rodata_86D4;
extern f32 lbl_1_rodata_26F8[22];

extern u8 fn_1_D66B0(void);
extern u8 fn_1_D6740(u8);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern u32 fn_1_5158C(FontDrawPacket *, u32, u32, u32);
extern int fn_1_4F734(FontDrawPacket *);
extern char *strncpy(char *, const char *, size_t);
extern void fn_1_50164(f32, f32, f32, f32, void *);
extern void fn_1_49410(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495C8(s32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_4965C(s32);
extern void fn_1_495B0(s32);
extern void fn_1_4CE48(Obj_1_bss_4B9CC *, f32);

#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_132FB4(void) {
    FontDrawPacket packet;
    char buf[17];
    u32 tblA[4];
    u32 tblB[4];
    s32 var_r31;
    s32 var_r30;
    s32 var_r29;
    s32 var_r28;
    char *pbuf;
    f32 lab_t0;
    u32 var_r26;
    f32 lab_t1;

    var_r29 = 0;
    var_r28 = 0;
    var_r26 = 0;
    var_r31 = 0x18;
    var_r30 = 0x43;

    tblA[0] = lbl_1_rodata_8694[0];
    tblA[1] = lbl_1_rodata_8694[1];
    tblA[2] = lbl_1_rodata_8694[2];
    tblA[3] = lbl_1_rodata_8694[3];
    tblB[0] = lbl_1_rodata_86A4[0];
    tblB[1] = lbl_1_rodata_86A4[1];
    tblB[2] = lbl_1_rodata_86A4[2];
    tblB[3] = lbl_1_rodata_86A4[3];

    pbuf = buf;

    do {
        if (var_r29 == fn_1_D66B0()) {
            var_r28 += 1;
            var_r26 += 4;
        } else if (fn_1_D6740(var_r29) != 0) {
            fn_80008BEC(pbuf, 0, 0x11);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x10000 - 0x61EC;
            fn_1_51564(0, 0, 0x18, 0x14, 2, 2);
            fn_1_5158C(&packet, packet.image, (s16)(var_r28 % 2), (s16)(var_r28 / 2));
            packet.x = (f32)var_r31;
            packet.y = lbl_1_rodata_86B4;
            fn_1_4F734(&packet);
            strncpy(pbuf, (const char *)(*(u32 *)((u8 *)tblA + var_r26)), 0x10);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 12;
            *(u32 *)((u8 *)&packet + 0x30) = 5;
            packet.x = (f32)var_r31;
            packet.y = lbl_1_rodata_86B8;
            fn_1_50164(lbl_1_rodata_86BC, lbl_1_rodata_86C0, lbl_1_rodata_86C4, lbl_1_rodata_86C4, &packet);
            fn_1_49410();
            fn_1_496FC((f32)var_r30, lbl_1_rodata_86C8);
            fn_1_495C8(1);
            fn_1_4955C(lbl_1_rodata_86CC, lbl_1_rodata_86CC);
            fn_1_49590(lbl_1_rodata_85F0);
            fn_1_4965C(2);
            fn_1_495B0((0x3u << 30));
            fn_1_4CE48((Obj_1_bss_4B9CC *)pbuf, lbl_1_rodata_86D0);
            fn_1_49410();
            lab_t0 = (f32)var_r30;
            fn_1_496FC(lab_t0, lbl_1_rodata_8658);
            fn_1_495C8(1);
            fn_1_4955C(lbl_1_rodata_86D4, lbl_1_rodata_86D4);
            fn_1_49590(lbl_1_rodata_85F0);
            fn_1_4965C(2);
            fn_1_495B0((0x3u << 30));
            lab_t1 = lbl_1_rodata_86D0;
            fn_1_4CE48((Obj_1_bss_4B9CC *)(*(u32 *)((u8 *)tblB + var_r26)), lab_t1);
            var_r31 += 0x57;
            var_r30 += 0x57;
            var_r28 += 1;
            var_r26 += 4;
        }
        var_r29 += 1;
    } while (var_r29 < 4);
}
#pragma opt_propagation reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_132FB4 */

/* fzgx:begin fn_1_137364 */
// Writes the indexed three-byte value, or the fallback value when the index is out of range.
void fn_1_137364(s16 arg0, u8* arg1, u8* arg2, u8* arg3) {
    if (arg0 < 0x29) {
        u32* values = (u32*)&lbl_1_data_416B8;

        *arg1 = values[arg0 * 3];
        *arg2 = values[arg0 * 3 + 1];
        *arg3 = values[arg0 * 3 + 2];
    } else {
        *arg2 = 2;
        *arg1 = 2;
        *arg3 = 2;
    }
}
/* fzgx:end fn_1_137364 */

/* fzgx:begin fn_1_13F7F8 */
u32 fn_1_13F7F8(s16 arg0, s16 arg1) {
    return ((u32 (*)[6])&lbl_1_data_414D8)[arg0][arg1];
}
/* fzgx:end fn_1_13F7F8 */
