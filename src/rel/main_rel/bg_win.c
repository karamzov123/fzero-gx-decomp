#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_win.h"

extern u32 lbl_1_bss_8FD60[2];
extern int fn_1_15BCDC(void *);
extern void fn_1_4060(void);

extern u32 lbl_1_bss_8FE80[8];

extern void *fn_1_435C(void *);
extern void fn_1_15E220(u8 *value);
extern void fn_1_3F8C(void *, void *, u8 *, s32);
extern u32 lbl_1_bss_8FEA0;
extern u8 lbl_1_bss_8FE7C;
extern u32 strlen(const char *str);
extern s32 fn_8006FC1C(const char *a, const char *b);
extern void fn_1_15E1E8(u8 *value);

/* fzgx:begin fn_1_15B70C */
typedef struct { u32 x; u32 y; u32 z; } fn_1_15B70C_Vec3;
typedef struct {
    u8 pad_0[0x04];
    fn_1_15B70C_Vec3 grp[5];
    u8 pad_40[0x0C];
    u32 *ptr_4C;
    u32 *ptr_50;
    u32 *ptr_54;
    u32 *ptr_58;
    u8 cnt_5C;
    u8 cnt_5D;
    u8 cnt_5E;
    u8 pad_5F;
    u32 *ptr_60[5];
    u32 *ptr_74[20];
    u32 *ptr_C4[20];
} fn_1_15B70C_Obj;
typedef struct {
    u8 pad_0[0x0C];
    fn_1_15B70C_Vec3 vec;
    u8 pad_18[0x24];
    u32 unk_3C;
} fn_1_15B70C_Entry;
extern void OSPanic(const char *file, int line, const char *expr, ...);

#pragma opt_strength_reduction off
#pragma opt_propagation off
#pragma opt_loop_invariants off
s32 fn_1_15B70C(s32 kind, fn_1_15B70C_Entry *entry) {
    fn_1_15B70C_Obj *obj;

    obj = (fn_1_15B70C_Obj *)lbl_1_data_2A7E0.unk_3C;
    switch (kind) {
    case 0:
        obj->grp[0] = entry->vec;
        break;
    case 1:
        obj->grp[1] = entry->vec;
        break;
    case 2:
        entry->unk_3C = 0;
        obj->grp[2] = entry->vec;
        obj->ptr_4C = (u32 *)entry;
        if (obj->cnt_5D < 20) {
            obj->ptr_74[obj->cnt_5D] = (u32 *)entry;
        }
        obj->cnt_5D++;
        break;
    case 3:
        entry->unk_3C = 0;
        obj->grp[3] = entry->vec;
        obj->ptr_50 = (u32 *)entry;
        if (obj->cnt_5D < 20) {
            obj->ptr_74[obj->cnt_5D] = (u32 *)entry;
        }
        obj->cnt_5D++;
        break;
    case 4:
        entry->unk_3C = 0;
        obj->grp[4] = entry->vec;
        obj->ptr_54 = (u32 *)entry;
        if (obj->cnt_5D < 20) {
            obj->ptr_74[obj->cnt_5D] = (u32 *)entry;
        }
        obj->cnt_5D++;
        break;
    case 5:
        entry->unk_3C = 0;
        obj->ptr_58 = (u32 *)entry;
        if (obj->cnt_5D < 20) {
            obj->ptr_74[obj->cnt_5D] = (u32 *)entry;
        }
        obj->cnt_5D++;
        break;
    case 6:
        if (obj->cnt_5C < 5) {
            obj->ptr_60[obj->cnt_5C] = (u32 *)entry;
        }
        obj->cnt_5C++;
    case 7:
        if (obj->cnt_5D < 20) {
            obj->ptr_74[obj->cnt_5D] = (u32 *)entry;
        }
        obj->cnt_5D++;
        break;
    case 8:
    case 9:
    case 10:
        if (obj->cnt_5E < 20) {
            obj->ptr_C4[obj->cnt_5E] = (u32 *)entry;
        }
        obj->cnt_5E++;
        break;
    default:
        break;
    }
    if (obj->cnt_5E >= 20) {
        OSPanic("bg_win.c\000\000\000", 0x163, "win gr over");
    }
    if (obj->cnt_5D >= 20) {
        OSPanic("bg_win.c\000\000\000", 0x164, "win bg over");
    }
    return 1;
}
#pragma opt_loop_invariants reset
#pragma opt_propagation reset
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_15B70C */

/* fzgx:begin fn_1_15B970 */
typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
} WinObject;

static inline u32 swap32(u32 value) {
    u32 temp;

    temp = value;
    return __lwbrx(&temp, 0);
}

void fn_1_15B970(WinObject *obj) {
    u32 offset;
    u32 count;

    lbl_1_bss_8F8D0.unk_0 = (u32)obj;
    if (obj != 0) {
        obj->unk_8 = swap32(obj->unk_8);
        obj->unk_C = swap32(obj->unk_C);
        obj->unk_10 = swap32(obj->unk_10);
        obj->unk_14 = swap32(obj->unk_14);
        obj->unk_18 = swap32(obj->unk_18);

        count = 0;
        offset = 0;
        while (count < obj->unk_8) {
            u32 *a = (u32 *)((u8 *)obj + obj->unk_C + offset);
            u32 *b = (u32 *)((u8 *)obj + obj->unk_10 + offset);

            a[1] = swap32(a[1]);
            a[0] = swap32(a[0]);
            b[1] = swap32(b[1]);
            b[0] = swap32(b[0]);

            offset += 8;
            count++;
        }
    }
}
/* fzgx:end fn_1_15B970 */

/* fzgx:begin fn_1_15BA78 */
#include "types.h"

typedef struct {
    u8 pad_00[0x08];
    u32 count;
    u32 entries_offset;
    u32 results_offset;
} StringTable;

#pragma opt_common_subs off
char *fn_1_15BA78(char *name) {
    struct { StringTable * value; } table;
    u32 index;
    struct { u32 value; } entry_offset;
    struct { u32 value; } name_length;

    { StringTable * __reg_value_table = (*(StringTable * *)&lbl_1_bss_8F8D0); table.value = __reg_value_table; }
    if (table.value == 0) {
        return name;
    }

    name_length.value = strlen(name);
    index = 0;
    entry_offset.value = 0;
    while (index < table.value->count) {
        u8 *entry = ((((entry_offset.value)) + ((((u8 *)table.value)) + ((table.value->entries_offset)))));
        if (name_length.value == *(u32 *)entry &&
            fn_8006FC1C((char *)table.value + *(u32 *)(entry + 4), name) != 0) {
            u32 result_offset = *(u32 *)((u8 *)table.value + table.value->results_offset + index * 8 + 4);
            return (char *)table.value + result_offset;
        }
        entry_offset.value += 8;
        index++;
    }
    return name;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_15BA78 */

/* fzgx:begin fn_1_15BB34 pool noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_win.h"

extern void fn_80008BEC(void *, int, u32);

typedef struct {
    u8 pad_000[0x480];
    u32 unk_480;
    u16 unk_484;
    u16 unk_486;
} WinInitState;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_8F8E0;
u8 lbl_1_bss_8F8E0_fill_8F8E1;
u16 lbl_1_bss_8F8E0_fill_8F8E2;
u32 lbl_1_bss_8F8E0_fill_8F8E4[7];
u8 lbl_1_bss_8F8E0_20;
u8 lbl_1_bss_8F8E0_fill_8F901;
u16 lbl_1_bss_8F8E0_fill_8F902;
u32 lbl_1_bss_8F8E0_fill_8F904[31];
u8 lbl_1_bss_8F980;
u8 lbl_1_bss_8F980_fill_8F981;
u16 lbl_1_bss_8F980_fill_8F982;
u32 lbl_1_bss_8F980_fill_8F984[7];
u8 lbl_1_bss_8F9A0;
u8 lbl_1_bss_8F9A0_fill_8F9A1;
u16 lbl_1_bss_8F9A0_fill_8F9A2;
u32 lbl_1_bss_8F9A0_fill_8F9A4[239];
u32 lbl_1_bss_8FD60;
u16 lbl_1_bss_8FD60_4;
u16 lbl_1_bss_8FD60_6;
u32 fzgx_obj_lbl_1_bss_8FD68[16];
u32 fzgx_obj_lbl_1_bss_8FDA8[53];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8F8E0;
    s = *(u8 *)&lbl_1_bss_8F8E0_fill_8F8E1;
    s = *(u8 *)&lbl_1_bss_8F8E0_fill_8F8E2;
    s = *(u8 *)&lbl_1_bss_8F8E0_fill_8F8E4;
    s = *(u8 *)&lbl_1_bss_8F8E0_20;
    s = *(u8 *)&lbl_1_bss_8F8E0_fill_8F901;
    s = *(u8 *)&lbl_1_bss_8F8E0_fill_8F902;
    s = *(u8 *)&lbl_1_bss_8F8E0_fill_8F904;
    s = *(u8 *)&lbl_1_bss_8F980;
    s = *(u8 *)&lbl_1_bss_8F980_fill_8F981;
    s = *(u8 *)&lbl_1_bss_8F980_fill_8F982;
    s = *(u8 *)&lbl_1_bss_8F980_fill_8F984;
    s = *(u8 *)&lbl_1_bss_8F9A0;
    s = *(u8 *)&lbl_1_bss_8F9A0_fill_8F9A1;
    s = *(u8 *)&lbl_1_bss_8F9A0_fill_8F9A2;
    s = *(u8 *)&lbl_1_bss_8F9A0_fill_8F9A4;
    s = *(u8 *)&lbl_1_bss_8FD60;
    s = *(u8 *)&lbl_1_bss_8FD60_4;
    s = *(u8 *)&lbl_1_bss_8FD60_6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8FD68;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8FDA8;
}
#pragma section code_type ".text"

void fn_1_15BB34(void *value) {
    
    u16 unk_484;
    u16 unk_486;

    fn_80008BEC((u8 *)&fzgx_obj_lbl_1_bss_8F8E0, 0, 0x20);
    fn_80008BEC((u8 *)&lbl_1_bss_8F8E0_20, 0, 0x20);
    fn_80008BEC((u8 *)&lbl_1_bss_8F980, 0, 0x20);
    fn_80008BEC((u8 *)&lbl_1_bss_8F9A0, 0, 0x3c0);

    unk_484 = 0xffff;
    unk_486 = 0;
    lbl_1_bss_8FD60 = (u32)value;
    lbl_1_bss_8FD60_4 = unk_484;
    lbl_1_bss_8FD60_6 = unk_486;
}
/* fzgx:end fn_1_15BB34 */

/* fzgx:begin fn_1_15BE38 */
typedef struct {
    u32 count;
    void **items;
} ItemList;

u32 fn_1_15BE38(void) {
    u32 offset;
    u32 index;

    offset = 0;
    index = 0;
    while (index < (*(ItemList **)&lbl_1_bss_8FD60)->count) {
        if (fn_1_15BCDC((*(ItemList **)&lbl_1_bss_8FD60)->items[offset >> 2]) != 0) {
            return index & 0xffff;
        }
        offset += 4;
        index++;
    }
    return 0xffff;
}
/* fzgx:end fn_1_15BE38 */

/* fzgx:begin fn_1_15BEBC */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
} Entry;

void fn_1_15BEBC(u16 mask, Obj_1_bss_8F8E0 *state) {
    Entry *p;
    u32 max;
    u32 sel;
    u32 cnt;
    Entry *first;
    u32 i;

    p = (Entry *)&lbl_1_bss_8F8E0;
    max = 0;
    sel = 0;
    cnt = 0;
    first = 0;
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            if (first == 0) {
                first = p;
            }
            if (p->unk_4 == 0) {
                cnt++;
            } else {
                if (sel == 0) {
                    sel = p->unk_4;
                } else if (sel != p->unk_4) {
                    sel = 0x8000;
                    break;
                }
                if (max < p->unk_1) {
                    max = p->unk_1;
                }
            }
        }
        p++;
    }

    if (sel != 0x8000) {
        if (sel == 0) {
            state->pad_3[0] = 0;
        } else if (cnt != 0) {
            u32 cur = state->pad_3[0];
            if (cur < 10) {
                sel = 0;
            } else {
                sel = 0x8000;
            }
            if (cur == 0) {
                state->pad_3[0] = 1;
            } else {
                state->pad_3[0] = cur + ((cur - 0x78) >> 31);
            }
        } else if (max < 10) {
            state->pad_3[0] = 0;
        } else {
            if (state->unk_4 == 0x8000) {
                sel = 0x8000;
            }
            if (state->pad_3[0] != 0) {
                u32 v = state->pad_3[0];
                state->pad_3[0] = v + ((v - 0x78) >> 31);
            }
        }
    }

    if (sel != state->unk_4) {
        state->unk_6 = state->unk_4;
        state->unk_4 = sel;
        state->unk_1 = 0;
        state->unk_2 = 0;
    } else {
        u32 t = state->unk_1;
        state->unk_1 = t + 1;
        t = state->unk_2;
        state->unk_2 = t + 1;
    }
}
/* fzgx:end fn_1_15BEBC */

/* fzgx:begin fn_1_15C0AC */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
} WinEntry;

#pragma opt_loop_invariants off
void fn_1_15C0AC(void) {
    u8 *in;
    struct { WinEntry * value; } out;
    u16 a;
    u16 b;
    u32 i;

    { WinEntry * __reg_value_out = (WinEntry *)&lbl_1_bss_8F8E0; out.value = __reg_value_out; }
    in = (u8 *)&lbl_1_bss_9F8;
    for (i = 0; i < 4; i++) {
        a = 0;
        b = 0;
        if (((1) & ((*(volatile u16 *)(in + 8) >> 4)))) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 1;
        }
        if ((*(volatile u16 *)(in + 8) >> 10) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 2;
        }
        if ((*(volatile u16 *)(in + 8) >> 11) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 4;
        }
        if (*(volatile u16 *)(in + 8) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 8;
        }
        if ((*(volatile u16 *)(in + 8) >> 1) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x10;
        }
        if ((*(volatile u16 *)(in + 8) >> 8) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x20;
        }
        if ((*(volatile u16 *)(in + 10) >> 7) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x100;
        }
        if ((*(volatile u16 *)(in + 10) >> 6) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x200;
        }
        if ((*(volatile u16 *)(in + 10) >> 4) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x400;
        }
        if ((*(volatile u16 *)(in + 10) >> 5) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x800;
        }
        if ((*(volatile u16 *)(in + 8) >> 6) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x40;
        }
        if ((*(volatile u16 *)(in + 8) >> 5) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            a |= 0x80;
        }
        if ((*(volatile u16 *)(in + 0) >> 4) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 1;
        }
        if ((*(volatile u16 *)(in + 0) >> 10) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 2;
        }
        if ((*(volatile u16 *)(in + 0) >> 11) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 4;
        }
        if (*(volatile u16 *)(in + 0) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 8;
        }
        if ((*(volatile u16 *)(in + 0) >> 1) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x10;
        }
        if ((*(volatile u16 *)(in + 0) >> 8) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x20;
        }
        if ((*(volatile u16 *)(in + 2) >> 7) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x100;
        }
        if ((*(volatile u16 *)(in + 2) >> 6) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x200;
        }
        if ((*(volatile u16 *)(in + 2) >> 4) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x400;
        }
        if ((*(volatile u16 *)(in + 2) >> 5) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x800;
        }
        if ((*(volatile u16 *)(in + 0) >> 6) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x40;
        }
        if ((*(volatile u16 *)(in + 0) >> 5) & 1) {  /* fzgx-allow: S2 memory-mapped register */
            b |= 0x80;
        }
        if ((a ^ b) != 0 && ((a & out.value->unk_4) == 0 || out.value->unk_1 >= 0xa)) {
            a = 0;
        }
        if (a != 0) {
            out.value->unk_0 = out.value->unk_2;
            out.value->unk_2 = 0;
            out.value->unk_1 = 0;
        } else {
            u8 t = out.value->unk_2;
            out.value->unk_2 = t + (((u32)t - 0x78) >> 31);
            if (b != 0) {
                u8 t2 = out.value->unk_1;
                out.value->unk_1 = t2 + (((u32)t2 - 0x78) >> 31);
            } else {
                out.value->unk_1 = 0;
            }
        }
        {
            u16 t3 = out.value->unk_4;
            if (t3 != b) {
                out.value->unk_6 = t3;
                out.value->unk_4 = b;
            }
        }
        out.value++;
        in += 0x14;
    } while (--i);
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_15C0AC */

/* fzgx:begin fn_1_15C35C */
s32 fn_1_15C35C(s32 a, s32 b, s32 c, s32 d) {
    return a * b - c + d;
}
/* fzgx:end fn_1_15C35C */

/* fzgx:begin fn_1_15C36C */
extern s32 fn_1_5910(void);
extern void fn_80038F10(f32 *values);
extern void fn_1_15EFEC(s32 index);
extern void fn_1_15DFD4(s32 index, u32 mask);
extern s32 fn_1_485A8(s32 value);
extern void fn_1_49410(void);
extern void fn_1_49728(s32 value);
extern void fn_1_1420A4(void);

#pragma opt_dead_assignments off
void fn_1_15C36C(void) {
    s32 index;
    u8 mask;
    u8 flags;
    s32 hit;
    s32 off;
    f32 values[4];
    f32 *output;

    index = fn_1_5910();
    mask = 1 << index;
    if ((lbl_1_bss_3C30.unk_0 & 0x00000800) != 0) {
        return;
    }

    fn_80038F10(values);
    *((f32 *)&lbl_1_bss_8FD68 + ((4) * (index))) = (*((0) + (values)));
    output = (f32 *)&lbl_1_bss_8FD68;
    *(output + ((4) * (index)) + 1) = (*((1) + (values)));
    *(output + ((4) * (index)) + 2) = (*((2) + (values)));
    *(output + ((4) * (index)) + 3) = (*((3) + (values)));

    flags = lbl_1_bss_26B1E.unk_0 |
            lbl_1_bss_26B19 |
            lbl_1_bss_26B1A |
            lbl_1_bss_26B18;
    hit = flags & mask;

    if (hit != 0) {
        ((u32 *)&lbl_1_data_3D544)[index] &= 0x3c2;
    }

    if (hit == 0) {
        Obj_1_bss_8FDA8 *state = (Obj_1_bss_8FDA8 *)((u8 *)&lbl_1_bss_8FDA8 + index * 0x34);

        if ((state->unk_0 & 0x4) == 0) {
            fn_1_15EFEC(index);
        }
    }

    if ((lbl_1_bss_3C30.unk_0 & 0x8) != 0) {
        return;
    }

    if (hit != 0) {
        fn_1_15DFD4(index, mask);
    }

    if ((lbl_1_bss_3C30.unk_0 & 0x1000) == 0) {
        return;
    }
    if (fn_1_485A8(0x97) == 0) {
        return;
    }
    if (((u16 *)&lbl_1_bss_50EC)[index] != 0) {
        return;
    }

    fn_1_49410();
    fn_1_49728(1);
    fn_1_1420A4();
    fn_1_49728(0);
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_15C36C */

/* fzgx:begin fn_1_15C5A4 noprologue */
#include "types.h"

extern f32 lbl_1_rodata_DD58;
extern f64 lbl_1_rodata_DD60;
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_80074188(u32, u32, u32, u32);
extern u32 lbl_1_bss_8FD68;

#pragma opt_common_subs off
#pragma opt_dead_assignments off
f32 fn_1_15C5A4(void * arg0, void * arg1) {
    s32 v0;
    u32 v1;
    s32 v2;
    f32 v3;
    f32 v4;
    f32 v5;
    v0 = (s32)(f32)(*(f32 *)((u8 *)arg0 + 84) / lbl_1_rodata_DD58);
    v1 = (v0 << 4);
    fn_80074188(__cvt_fp2unsigned(*(f32 *)((u8 *)&lbl_1_bss_8FD68 + v1)),
        __cvt_fp2unsigned(*(f32 *)((u8 *)&lbl_1_bss_8FD68 + v1 + 4)),
        __cvt_fp2unsigned(*(f32 *)((u8 *)&lbl_1_bss_8FD68 + v1 + 8)),
        __cvt_fp2unsigned(*(f32 *)((u8 *)&lbl_1_bss_8FD68 + v1 + 12)));
    v2 = (v0 * (0xF0000 + 16960));
    v3 = *(f32 *)((u8 *)arg0 + 84);
    v4 = *(f32 *)((u8 *)arg1 + 0);
    *(f32 *)((u8 *)arg1 + 0) = (f32)(v4 + (f32)(v3 - (f32)(s32)v2));
    v5 = *(f32 *)((u8 *)arg1 + 12);
    *(f32 *)((u8 *)arg1 + 12) = (f32)(v5 + (f32)(v3 - (f32)(s32)v2));
    return v5;
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_15C5A4 */

/* fzgx:begin fn_1_15DD7C */
#include "font.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1000000.0f;
    s = 0.0f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 240.0f;
    s = 1.0f;
    s = 0.800000011920929f;
    s = 464.0f;
    s = 5.0f;
    s = 0.699999988079071f;
    s = 255.0f;
    s = 3.299999952316284f;
    s = 20.0f;
    s = 0.5f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 42.0f;
    s = 30.0f;
    s = 16384.0f;
    s = 32768.0f;
    s = 0.0010000000474974513f;
    s = 3.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table6[24] = {0x00000000, 0x00000000, 0x0000004B, 0x00000064, 0x0000004C, 0x00000000, 0x00000023, 0x00000064, 0x00000098, 0x00000000, 0x0000004B, 0x00000064, 0x0000004C, 0x00000000, 0x00000023, 0x00000064, 0x000000E4, 0x00000000, 0x0000004B, 0x00000064, 0x00000130, 0x00000000, 0x0000004B, 0x00000064};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 120.0f;
    s = 10.0f;
    s = 2.0f;
    s = -10.0f;
    s = 0.25f;
    s = 100.0f;
    s = 60.0f;
}
#pragma section code_type ".text"

typedef struct {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    u32 unk_30;
    u32 unk_34[9];
} WinPacket;

extern WinPacket lbl_1_rodata_26F8;
extern u32 fn_1_58C4(void);
extern f32 fn_1_519FC(f32);
extern f32 fn_1_51AC0(f32);

void fn_1_15DD7C(int arg0) {
    WinPacket s;

    s = lbl_1_rodata_26F8;

    if (lbl_1_bss_3C30.unk_0 & 0x8000) {
        return;
    }

    s.unk_4 = 320.0f;
    s.unk_8 = 240.0f;
    s.unk_0 = 37931;
    s.unk_30 = 10;

    if (fn_1_58C4() > 1 || lbl_1_bss_3C30.unk_13F6 == 0) {
        if (240.0f < (f32)arg0) {
            s.unk_2C = ((f32)arg0 - 240.0f) / 60.0f * 2.0f;
            if (s.unk_2C > 1.0f) {
                s.unk_2C = 1.0f;
            }
            s.unk_2C = 1.0f - s.unk_2C;
        } else {
            s.unk_2C = 1.0f;
        }
    } else {
        if (240.0f < (f32)arg0) {
            f32 u = ((f32)arg0 - 240.0f) / 60.0f;
            if (u > 1.0f) {
                u = 1.0f;
            }
            s.unk_2C = 1.0f - u;
        } else if ((f32)arg0 < 60.0f) {
            s.unk_2C = (f32)arg0 / 60.0f;
        } else {
            s.unk_2C = 1.0f;
        }
    }

    s.unk_14 = 1.0f;
    s.unk_10 = 1.0f;
    s.unk_4 = fn_1_519FC(s.unk_4);
    s.unk_8 = fn_1_51AC0(s.unk_8);
    s.unk_C = 2.0f;
    s.unk_10 = s.unk_10 * (fn_1_58C4() == 1 ? 1.0f : 0.8f);
    s.unk_14 = s.unk_14 * (fn_1_58C4() == 1 ? 1.0f : 0.8f);
    fn_1_4F734((FontDrawPacket *)&s);
}
/* fzgx:end fn_1_15DD7C */

/* fzgx:begin fn_1_15DFD4 noprologue */
#include "types.h"

extern f32 lbl_1_rodata_DD6C[11];
extern f32 lbl_1_rodata_DE50[39];
extern void fn_1_496FC(f32, f32);
extern void fn_1_49410(void);
extern void fn_1_49728(int);
extern void fn_1_495FC(void);
extern void fn_1_495C8(int);
extern void fn_1_15DD7C(u16);
extern void fn_1_15C6C0(s32, s32);
extern void fn_1_49614(void);
extern void fn_1_A4C9C(int, u8);

extern u8 lbl_1_bss_26B18;
extern u8 lbl_1_bss_26B1A;
extern u8 lbl_1_bss_26B19;
extern u8 lbl_1_bss_26B1E;
extern u32 lbl_1_bss_3C30;

typedef struct {
    u8 pad_0[0xB];
    u8 unk_B;
    u8 pad_C[0x28];
} BgWin38;

extern BgWin38 lbl_1_bss_8FDA8[];
extern u16 lbl_1_bss_50EC[];

void fn_1_15DFD4(int index, int flags) {
    int state;

    flags &= 0xff;
    if (lbl_1_bss_26B18 & flags) {
        state = 4;
    } else if (lbl_1_bss_26B1A & flags) {
        state = 2;
    } else if (lbl_1_bss_26B19 & flags) {
        state = 1;
    } else if (lbl_1_bss_26B1E & flags) {
        state = 3;
    } else {
        return;
    }

    if (lbl_1_bss_3C30 & 0x1000) {
        lbl_1_bss_8FDA8[index].unk_B = 0;
    } else {
        lbl_1_bss_8FDA8[index].unk_B = 1;
    }

    fn_1_496FC(lbl_1_rodata_DD6C[0], lbl_1_rodata_DE50[0]);
    fn_1_49410();
    fn_1_49728(1);
    fn_1_495FC();
    fn_1_495C8(9);

    switch (state) {
    case 1: {
        u16 v = lbl_1_bss_50EC[index];
        if (lbl_1_bss_8FDA8[index].unk_B != 0) {
            fn_1_15DD7C(v);
        }
        break;
    }
    case 2: {
        u16 v = lbl_1_bss_50EC[index];
        if (lbl_1_bss_8FDA8[index].unk_B != 0) {
            fn_1_15DD7C(v);
        }
        break;
    }
    case 3:
        fn_1_15C6C0(lbl_1_bss_50EC[index], index);
        break;
    case 4: {
        u16 v = lbl_1_bss_50EC[index];
        if (lbl_1_bss_8FDA8[index].unk_B != 0) {
            fn_1_15DD7C(v);
        }
        break;
    }
    }

    fn_1_49614();
    fn_1_49728(0);
    fn_1_A4C9C(index, state);
}
/* fzgx:end fn_1_15DFD4 */

/* fzgx:begin fn_1_15E1D0 noprologue */
#include "types.h"

struct fn_1_15E1D0_lbl_1_bss_8FDA8_0_E52 {
    u8 pad_0[0x30];
    f32 unk_30;
};
struct fn_1_15E1D0_lbl_1_bss_8FDA8 {
    struct fn_1_15E1D0_lbl_1_bss_8FDA8_0_E52 unk_0[1];
};

extern struct fn_1_15E1D0_lbl_1_bss_8FDA8 lbl_1_bss_8FDA8;

f32 fn_1_15E1D0(u32 arg0) {
    return lbl_1_bss_8FDA8.unk_0[arg0].unk_30;
}
/* fzgx:end fn_1_15E1D0 */

/* fzgx:begin fn_1_15E1E8 */
void fn_1_15E1E8(u8 *value) {
    u8 state = *value;

    if (state == 0) {
        fn_1_4060();
    } else {
        *value = state - 1;
    }
}
/* fzgx:end fn_1_15E1E8 */

/* fzgx:begin fn_1_15E220 */
void fn_1_15E220(u8 *value) {
    u8 state = *value;

    if (state == 0) {
        fn_1_4060();
    } else if (state != 0xff) {
        *value = state - 1;
    }
}
/* fzgx:end fn_1_15E220 */

/* fzgx:begin fn_1_15E260 */
// Marks the indexed background-window entry as active.
void fn_1_15E260(s32 index) {
    (&lbl_1_bss_8FDA8.unk_0)[index * 0x34] |= 4;
}
/* fzgx:end fn_1_15E260 */

/* fzgx:begin fn_1_15E330 */
extern void *fn_1_435C(void *arg);
extern void fn_1_3F8C(void *arg0, void *arg1, u8 *arg2, s32 arg3);

void fn_1_15E330(s32 index, u32 value, void *arg) {
    if (lbl_1_bss_3C30.unk_13F4 - (&lbl_1_bss_8FDA8.unk_8)[index * 0x34] < 4) {
        void *result;

        (&lbl_1_bss_8FDA8.unk_0)[index * 0x34] |= 8;
        (&lbl_1_bss_8FDA8.unk_C)[index * 13] = value;
        result = fn_1_435C(arg);
        fn_1_3F8C(lbl_1_data_4C980, fn_1_15E1E8,
                  &(&lbl_1_bss_8FDA8.unk_9)[index * 0x34], 13);
        (&lbl_1_bss_8FDA8.unk_9)[index * 0x34] = 0x3c;
        fn_1_435C(result);
    }
}
/* fzgx:end fn_1_15E330 */

/* fzgx:begin fn_1_15E3E0 */
// Records the selected window index and updates its value when the index is valid.
void fn_1_15E3E0(s32 index, u32 value) {
    s32 slot = (lbl_1_bss_3C30.unk_13F4 - 1) % 4;

    lbl_1_bss_8FE80[slot] = index;
    if (index != -1) {
        (&lbl_1_bss_8FDA8.unk_C)[index * 13] = value;
    }
}
/* fzgx:end fn_1_15E3E0 */

/* fzgx:begin fn_1_15E434 */
void fn_1_15E434(u32 value) {
    lbl_1_bss_8FE7C = 1;
    lbl_1_bss_8FEA0 = value;
}
/* fzgx:end fn_1_15E434 */

/* fzgx:begin fn_1_15E540 */
// Initializes a background-window entry once, then marks it ready for reuse.
void fn_1_15E540(s32 index, void *arg) {
    if (!((&lbl_1_bss_8FDA8.unk_0)[index * 0x34] & 1)) {
        void *value = fn_1_435C(arg);

        fn_1_3F8C(lbl_1_data_4C994, fn_1_15E220,
                  &lbl_1_bss_8FDA8.unk_1 + index * 0x34, 13);
        (&lbl_1_bss_8FDA8.unk_1)[index * 0x34] = 0xff;
        fn_1_435C(value);
        (&lbl_1_bss_8FDA8.unk_0)[index * 0x34] |= 1;
    }
}
/* fzgx:end fn_1_15E540 */

/* fzgx:begin fn_1_15E5E4 */
extern void *fn_1_435C(void *);
extern void fn_1_15E220(u8 *value);
extern void fn_1_3F8C(void *, void *, u8 *, s32);

// Initializes a background-window entry once, then marks it ready for reuse.
void fn_1_15E5E4(s32 index, void *arg) {
    Obj_1_bss_8FDA8 *obj;
    s32 offset = index * 0x34;

    obj = (Obj_1_bss_8FDA8 *)((u8 *)&lbl_1_bss_8FDA8 + offset);

    if (!(obj->unk_0 & 2)) {
        void *value = fn_1_435C(arg);

        fn_1_3F8C(lbl_1_data_4C994, fn_1_15E220, &obj->unk_2, 13);
        (&lbl_1_bss_8FDA8.unk_2)[offset] = 0xff;
        fn_1_435C(value);
        obj->unk_0 |= 2;
    }
}
/* fzgx:end fn_1_15E5E4 */

/* fzgx:begin fn_1_15E688 */
extern void *fn_1_435C(void *arg);
extern void fn_1_3F8C(void *arg0, void *arg1, u8 *arg2, s32 arg3);

void fn_1_15E688(s32 index, u32 value, u8 state, void *arg) {
    void *obj;
    Obj_1_bss_8FDA8 *entry;

    obj = fn_1_435C(arg);
    fn_1_3F8C(lbl_1_data_4C980, fn_1_15E1E8,
              &(&lbl_1_bss_8FDA8.unk_0)[index * 0x34] + 3, 13);
    (&lbl_1_bss_8FDA8.unk_0)[index * 0x34 + 3] = 0x5a;
    fn_1_435C(obj);
    entry = (Obj_1_bss_8FDA8 *)((u8 *)&lbl_1_bss_8FDA8 + index * 0x34);
    ((u32 *)&entry->unk_10)[(state - 1) % 8] = value;
    entry->unk_4 = value;
    entry->unk_8 = state;
}
/* fzgx:end fn_1_15E688 */

/* fzgx:begin fn_1_15E764 */
extern void *fn_1_435C(void *);
extern void fn_1_15E220(u8 *value);
extern void fn_1_3F8C(void *, void *, u8 *, s32);

// Initializes the entry's 13-byte block, then marks it ready for reuse.
void fn_1_15E764(s32 index, void *arg) {
    void *value = fn_1_435C(arg);

    fn_1_3F8C(lbl_1_data_4C994, fn_1_15E220,
              &lbl_1_bss_8FDA8.unk_A + index * 0x34, 13);
    (&lbl_1_bss_8FDA8.unk_A)[index * 0x34] = 0xff;
    fn_1_435C(value);
    (&lbl_1_bss_8FDA8.unk_A)[index * 0x34] = 0xff;
}
/* fzgx:end fn_1_15E764 */

/* fzgx:begin fn_1_15EC40 pool */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1000000.0f;
    s = 0.0f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 240.0f;
    s = 1.0f;
    s = 0.800000011920929f;
    s = 464.0f;
    s = 5.0f;
    s = 0.699999988079071f;
    s = 255.0f;
    s = 3.299999952316284f;
    s = 20.0f;
    s = 0.5f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 42.0f;
    s = 30.0f;
    s = 16384.0f;
    s = 32768.0f;
    s = 0.0010000000474974513f;
    s = 3.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table6[24] = {0x00000000, 0x00000000, 0x0000004B, 0x00000064, 0x0000004C, 0x00000000, 0x00000023, 0x00000064, 0x00000098, 0x00000000, 0x0000004B, 0x00000064, 0x0000004C, 0x00000000, 0x00000023, 0x00000064, 0x000000E4, 0x00000000, 0x0000004B, 0x00000064, 0x00000130, 0x00000000, 0x0000004B, 0x00000064};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 120.0f;
    s = 10.0f;
    s = 2.0f;
    s = -10.0f;
    s = 0.25f;
    s = 100.0f;
    s = 60.0f;
    s = 5120.0f;
    s = 1.5f;
    s = 208.0f;
    s = 0.8999999761581421f;
    s = 50.0f;
    s = 370.0f;
    s = 128.0f;
    s = 150.0f;
    s = 0.125f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table10[20] = {0x0000000F, 0x00000007, 0x0000000D, 0x00000005, 0x00000000, 0x00000000, 0x3F000000, 0x3F000000, 0x00000000, 0x3F000000, 0x3F000000, 0x3F800000, 0x3F000000, 0x00000000, 0x3F800000, 0x3F000000, 0x3F000000, 0x3F000000, 0x3F800000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 40.0f;
    s = 350.0f;
    s = 1.399999976158142f;
    s = 90.0f;
    s = 15.0f;
    s = 300.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table13[1] = {0xE60000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table14[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8849999904632568f;
    s = 315.0f;
    s = 250.0f;
}
#pragma section code_type ".text"

struct fn_1_15EC40_Arg0 {
    u8 unk_0;
    u8 pad_1[7];
    u8 unk_8;
    u8 unk_9;
    u8 pad_A[2];
    u32 unk_C;
};
struct fn_1_15EC40_lbl_1_rodata_DD58 {
    u8 pad_0[8];
    f64 unk_8;
    u8 pad_10[12];
    f32 unk_1C;
    f32 unk_20;
    u8 pad_24[24];
    f32 unk_3C;
    u8 pad_40[172];
    f32 unk_EC;
    u8 pad_F0[24];
    f64 unk_108;
    u8 pad_110[96];
    f32 unk_170;
    u8 pad_174[4];
    u32 unk_178;
    u32 unk_17C;
    u32 unk_180;
    f32 unk_184;
    f32 unk_188;
    f32 unk_18C;
};
const u8 lbl_1_rodata_DD58[4] = {0x49,0x74,0x24,0x00};
const f64 lbl_1_rodata_DD60 = 4503601774854144.0;
const u8 lbl_1_rodata_DD60__fzgx_offset_8[4] = {0xFF,0xFF,0xFF,0x00};
const u8 lbl_1_rodata_DD6C[8] = {0x43,0xA0,0x00,0x00,0x43,0x70,0x00,0x00};
const f32 lbl_1_rodata_DD6C__fzgx_offset_8 = 1.0f;
const f32 lbl_1_rodata_DD6C__fzgx_offset_C = 0.800000012f;
const u8 lbl_1_rodata_DD6C__fzgx_offset_10[24] = {0x43,0xE8,0x00,0x00,0x40,0xA0,0x00,0x00,0x3F,0x33,0x33,0x33,0x43,0x7F,0x00,0x00,0x40,0x53,0x33,0x33,0x41,0xA0,0x00,0x00};
const f32 lbl_1_rodata_DD6C__fzgx_offset_28 = 0.5f;
const u8 lbl_1_rodata_DD98[172] = {0x00,0x00,0x00,0x00,0x44,0x48,0x00,0x00,0x42,0x28,0x00,0x00,0x41,0xF0,0x00,0x00,0x46,0x80,0x00,0x00,0x47,0x00,0x00,0x00,0x3A,0x83,0x12,0x6F,0x40,0x40,0x00,0x00,0x41,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4B,0x00,0x00,0x00,0x64,0x00,0x00,0x00,0x4C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x23,0x00,0x00,0x00,0x64,0x00,0x00,0x00,0x98,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4B,0x00,0x00,0x00,0x64,0x00,0x00,0x00,0x4C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x23,0x00,0x00,0x00,0x64,0x00,0x00,0x00,0xE4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4B,0x00,0x00,0x00,0x64,0x00,0x00,0x01,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4B,0x00,0x00,0x00,0x64,0x42,0xF0,0x00,0x00,0x41,0x20,0x00,0x00,0x40,0x00,0x00,0x00,0xC1,0x20,0x00,0x00,0x3E,0x80,0x00,0x00,0x42,0xC8,0x00,0x00,0x42,0x70,0x00,0x00,0x45,0xA0,0x00,0x00,0x3F,0xC0,0x00,0x00,0x43,0x50,0x00,0x00};
const f32 lbl_1_rodata_DD98__fzgx_offset_AC = 0.899999976f;
const u8 lbl_1_rodata_DD98__fzgx_offset_B0[8] = {0x42,0x48,0x00,0x00,0x43,0xB9,0x00,0x00};
const u8 lbl_1_rodata_DE50[16] = {0x43,0x00,0x00,0x00,0x43,0x16,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
const f64 lbl_1_rodata_DE50__fzgx_offset_10 = 4503599627370496.0;
const u8 lbl_1_rodata_DE50__fzgx_offset_18[96] = {0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x0D,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x3F,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x3F,0x80,0x00,0x00,0x42,0x20,0x00,0x00,0x43,0xAF,0x00,0x00,0x3F,0xB3,0x33,0x33,0x42,0xB4,0x00,0x00};
const f32 lbl_1_rodata_DE50__fzgx_offset_78 = 15.0f;
const u8 lbl_1_rodata_DE50__fzgx_offset_7C[4] = {0x43,0x96,0x00,0x00};
const f32 lbl_1_rodata_DE50__fzgx_offset_8C = 0.88499999f;
const f32 lbl_1_rodata_DE50__fzgx_offset_90 = 315.0f;
const f32 lbl_1_rodata_DE50__fzgx_offset_94 = 250.0f;
const u8 lbl_1_rodata_DE50__fzgx_offset_98[4] = {0x3C,0x23,0xD7,0x0A};
extern f32 fn_1_519FC(f32);
extern f32 fn_1_51AC0(f32);
extern u32 fn_1_58C4(void);
extern void fn_1_494DC(s16);
extern void fn_1_49514(u32 *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);

static inline u32 time_milliseconds(u32 a) {
    struct { u32 value; } minutes;
    u32 seconds = (a >> 12) & 0xFF;
    u32 milliseconds = a & 0xFFF;
    minutes.value = (a >> 20) & 0xFF;
    minutes.value *= 60;
    minutes.value = seconds + minutes.value;
    minutes.value *= 1000;
    return milliseconds + minutes.value;
}
static inline u32 time_difference(u32 a, u32 b) {
    u32 am = (a >> 20) & 0xFF;
    u32 bm = (b >> 20) & 0xFF;
    u32 as = (a >> 12) & 0xFF;
    u32 bs = (b >> 12) & 0xFF;
    u32 ax = a & 0xFFF;
    u32 bx = b & 0xFFF;
    u32 av;
    u32 bv;
    u32 diff;
    am *= 60;
    bm *= 60;
    am = as + am;
    bm = bs + bm;
    am *= 1000;
    bm *= 1000;
    av = ax + am;
    bv = bx + bm;
    diff = av - bv;
    if (bv > av) diff = bv - av;
    return ((diff / 60000) << 20) | (((diff / 1000) % 60) << 12) | (diff % 1000);
}
static inline f32 fn_1_15EC40_operand(f32 left, f32 right) { left *= right; return left; }
extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("%c%02d<%02d=%03d");
}
#pragma section code_type ".text"

void fn_1_15EC40(struct fn_1_15EC40_Arg0 *arg0) {
    s32 positive;
    struct fn_1_15EC40_lbl_1_rodata_DD58 *p_lbl_1_rodata_DD58;
    u32 tmp_fn_1_58C4;
    u8 v0;
    f32 v3;
    u32 v12;
    u32 v9;
    f32 v2;
    s32 v7;
    u32 v6;
    u32 v29;
    f32 v30;
    f32 v31;
    struct { f32 value; } v32;
    u32 loc_10;
    u32 loc_C;
    u32 loc_8;
    v0 = arg0->unk_9;
    
    positive = 1;
    if (v0 > 45) {
        v2 = (f32)(s32)(60 - v0) / lbl_1_rodata_DE50__fzgx_offset_78;
        v3 = lbl_1_rodata_DD6C__fzgx_offset_28 * v2;
    } else if (v0 < 15) {
        v2 = (f32)(u32)v0 / lbl_1_rodata_DE50__fzgx_offset_78;
        v3 = lbl_1_rodata_DD6C__fzgx_offset_28 * v2;
    } else {
        v3 = lbl_1_rodata_DD6C__fzgx_offset_28;
        v2 = lbl_1_rodata_DD6C__fzgx_offset_8;
    }
    if (arg0->unk_0 & 8) {
        v7 = (arg0->unk_8 - 1) % 4;
        v9 = (&lbl_1_bss_3C30.unk_13B4)[v7];
        if (!v9 || !(v12 = arg0->unk_C)) return;
        v6 = time_difference(v9, v12);
        if (v9 < v12) positive = 0;
    } else {
        v7 = (lbl_1_bss_3C30.unk_13F5 - 1) % 4;
        v9 = (&lbl_1_bss_3C30.unk_13B4)[v7];
        v12 = (&lbl_1_bss_3C30.unk_13D4)[v7];
        if (!v9 || !v12) return;
        v6 = time_difference(v9, v12);
        if (v9 > v12) positive = 0;
    }
    if (positive) {
        loc_10 = fzgx_pool_table12[0];
        fn_1_49514(&loc_10);
        v29 = 59;
    } else {
        loc_C = fzgx_pool_table13[0];
        fn_1_49514(&loc_C);
        v29 = 58;
    }
    fn_1_494DC(10);
    fn_1_495B0(0x80000000);
    fn_1_495A0(v3);
    tmp_fn_1_58C4 = fn_1_58C4();
    if (tmp_fn_1_58C4 == 1) v30 = lbl_1_rodata_DD6C__fzgx_offset_8;
    else v30 = lbl_1_rodata_DD6C__fzgx_offset_C;
    tmp_fn_1_58C4 = fn_1_58C4();
    if (tmp_fn_1_58C4 == 1) v31 = lbl_1_rodata_DD6C__fzgx_offset_8;
    else v31 = lbl_1_rodata_DD6C__fzgx_offset_C;
    fn_1_4955C(fn_1_15EC40_operand((lbl_1_rodata_DE50__fzgx_offset_8C * v2), (v31)), lbl_1_rodata_DD98__fzgx_offset_AC * v30);
    v32.value = fn_1_51AC0(lbl_1_rodata_DE50__fzgx_offset_94);
    fn_1_496FC(fn_1_519FC(lbl_1_rodata_DE50__fzgx_offset_90), v32.value);
    fn_1_4AE0C((const char *)"%c%02d<%02d=%03d", v29 & 0xFF, (v6 >> 20) & 0xFF, (v6 >> 12) & 0xFF, v6 & 0xFFF);
    loc_8 = fzgx_pool_table14[0];
    fn_1_49514(&loc_8);
}
/* fzgx:end fn_1_15EC40 */

/* fzgx:begin fn_1_15F618 */
void *fn_1_15F618(s32 index) {
    return (u8 *)&lbl_1_bss_8FDA8 + index * 0x34;
}
/* fzgx:end fn_1_15F618 */
