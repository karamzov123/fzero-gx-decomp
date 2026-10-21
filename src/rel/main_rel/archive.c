#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/archive.h"

extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);
extern void fn_1_12A350(void *arg0, s32 arg1);
extern s32 fn_8006A480(void *arg0, void *arg1, void *arg2);
extern s32 fn_8006A998(void *arg0);
extern void fn_8006A9AC(void *arg0);
extern void fn_1_12AC28(void *arg0, s32 arg1, s32 arg2);
extern void fn_1_12ADC8(void *arg0, void *arg1, s32 arg2, s32 arg3);
extern void fn_1_12BB18(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void fn_1_8D168(void *arg);
extern void fn_1_14DB48(void *arg0, void *arg1, u32 arg2);
extern void fn_1_14DBCC(void *arg);
extern u32 fn_1_95120(void *arg);
extern const struct Table lbl_1_rodata_8230;
extern u32 lbl_801A66A0;
extern void fn_1_7B2E8(u8 value);
extern void fn_1_13C1A0(void);
extern void *fn_1_3F8C(void *table, void (*callback)(void), void *arg1, void *arg2);
extern void fn_1_426C(s32 value);
extern void fn_1_7B4C0(void);
extern void fn_1_C2454(void);
extern s32 fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);

extern s32 lbl_1_bss_897A4;
extern void *lbl_801A6410;
extern void fn_1_46B4(void *arg0, void *arg1, unsigned char *arg2, s32 arg3);
extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);

extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);
extern s32 lbl_1_bss_8CA44[10];

extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);
extern void fn_1_435C();
extern s32 fn_1_45730(void *arg0, void *arg1);
extern s32 fn_1_45B2C(void *arg0);
extern void *fn_1_45D0(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_458A0(void *arg0, void *arg1, u32 arg2, u32 arg3);
extern void fn_1_45850(void *arg0);
extern void fn_8006A9B4(void *arg0, void *arg1);
extern void fn_80006E10(void *arg0);
extern u32 fn_1_12DAEC(u32, u32, u32, void *, u32, u32, u32);
extern u32 fn_1_12C524(u32);
extern void fn_1_12C000(void *arg, s16 count);
extern void fn_1_8CED0(void *arg, u16 a, u16 b);
extern void fn_1_8D0A4(void *arg);
extern s16 fn_1_12C930(s16 arg);
extern u8 lbl_1_data_20D1C[180];
extern u8 lbl_1_bss_8B4EC[128];
extern void fn_80083DB0(void *arg0, char *arg1);
extern void strcat(void *arg0, void *arg1);
extern s32 fn_1_F89E4(u8 value);

/* fzgx:begin fn_1_12A2D0 */
extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);

// Store the selected entry when it is valid; otherwise report an invalid entry.
void fn_1_12A2D0(s32 value) {
    Obj_1_bss_897AC *entry;

    entry = (Obj_1_bss_897AC *)((u8 *)&lbl_1_bss_897AC + value * 0x6c);
    if ((s32)entry->unk_0 == 1) {
        lbl_1_bss_897A0 = value;
    } else {
        extern void OSPanic(char *arg0, s32 arg1, ...);

        OSPanic((char *)lbl_1_data_40608, 0x5d, lbl_1_data_40614);
    }
}
/* fzgx:end fn_1_12A2D0 */

/* fzgx:begin fn_1_12A32C */
void fn_1_12A32C(void *arg0) {
    fn_1_12A350(arg0, 0);
}
/* fzgx:end fn_1_12A32C */

/* fzgx:begin fn_1_12A350 noprologue */
#include "rel/main_rel/archive.h"

extern int fn_1_45730(void *, void *);
extern void *fn_1_12A4B0(void *, u32, u32);
extern s32 fn_8006A3DC(void *, void *);
extern void OSPanic(const char *, int, const char *, ...);
extern size_t strlen(const char *);
extern s32 strncmp(const char *, const char *, size_t);

#pragma opt_dead_assignments off
u32 fn_1_12A350(char *name, u32 arg1)
{
    int i;
    char *d = (char *)&lbl_1_data_40600;
    u8 *base = (u8 *)&lbl_1_bss_897AC;
    u8 buf[0x60];

    for (i = 0; i < 64; i++) {
        if (*(s32 *)(base + i * 0x6c) == 0) {
            lbl_1_bss_897A0 = i;
            goto found; /* skip panic when a free slot exists */
        }
    }
    OSPanic(d + 8, 0x7f, d + 0x38);
found:
    if (fn_1_45730(name, buf) == 1) {
        int len = strlen(name);
        u32 flag;
        if (len >= 3 && strncmp(&name[len - 3], d + 0x58, 3) == 0) {
            flag = 1;
        } else {
            flag = 0;
        }
        if (fn_8006A3DC(fn_1_12A4B0(buf, flag, arg1), (u8 *)&lbl_1_bss_897AC + lbl_1_bss_897A0 * 0x6c + 0x4c) == 0) {
            OSPanic(d + 8, 0x94, d + 0x5c);
        }
    } else {
        OSPanic(d + 8, 0x97, d + 0x84);
    }
    {
        u32 *s = &lbl_1_bss_897A0;
        u32 slot = *s;
        *(u32 *)((u8 *)&lbl_1_bss_897AC + slot * 0x6c) = 1;
        return slot;
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_12A350 */

/* fzgx:begin fn_1_12A4B0 */
extern void *lbl_801A6410;

typedef struct ArchiveEntry {
    u8 pad[0x68];
    u32 data;
} ArchiveEntry;



#pragma opt_propagation on
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s32 fzgx_obj_lbl_1_bss_897A0;
u32 fzgx_obj_lbl_1_bss_897A4;
u32 lbl_1_bss_897A8;
u8 fzgx_obj_lbl_1_bss_897AC[1];
u8 lbl_1_bss_897AC__fzgx_offset_1;
u16 lbl_1_bss_897AC__fzgx_offset_2;
u32 lbl_1_bss_897AC__fzgx_offset_4[1732];
u32 lbl_1_bss_897AC__fzgx_offset_1B14[8];
u32 fzgx_obj_lbl_1_bss_8B2E0[48];
u32 fzgx_obj_lbl_1_bss_8B3A0[83];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_897A0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_897A4;
    s = *(u8 *)&lbl_1_bss_897A8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_897AC;
    s = *(u8 *)&lbl_1_bss_897AC__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_897AC__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_897AC__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_897AC__fzgx_offset_1B14;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8B2E0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8B3A0;
}
#pragma section code_type ".text"

#pragma opt_common_subs off
u32 fn_1_12A4B0(void *arg0, s32 arg1, s32 arg2) {
    extern s32 fn_1_458A0(void *arg0, void *arg1, u32 arg2, u32 arg3);
    extern void *fn_1_45D0(void *arg0, u32 arg1, void *arg2, u32 arg3);
    extern void fn_1_46B4(void *arg0, void *arg1, u8 *arg2, s32 arg3);
    extern s32 fn_1_45850(void *arg0);
    extern void *fn_1_45B2C(void *arg0);
    extern void fn_1_12FD4(void *arg0, u32 arg1);
    extern void DCFlushRange(void *arg0, u32 arg1);
    extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);

    s32 tmp2;
    u8 *strings;
    ArchiveEntry * e_2;
    u32 size;
    void *hp;
    ArchiveEntry *e;
    u8 *slot;
    u32 tmp;
    void * lab_t0;

    
    strings = (u8 *)&lbl_1_data_40600;

    if (arg1 != 0) {
        u32 aligned;

        if (fn_1_458A0(arg0, (void *)lbl_1_bss_897AC__fzgx_offset_1B14, 0x20, 0) < 0) {
            OSPanic(strings + 8, 0xB9, strings + 0xA8);
        }
        /* The archive header stores two little-endian 32-bit words. */
        hp = (void *)&lbl_1_bss_897AC__fzgx_offset_1B14[0];
        (void)__lwbrx((void *)hp, 0);
        size = __lwbrx((void *)hp, 4);
        aligned = (size + 0x1F) & ~0x1F;
        if (arg2 != 0) {
            tmp = (u32)fn_1_45D0(lbl_801A6410, aligned, strings + 8, 0xC1);
            tmp2 = (u32)fn_1_45D0(lbl_801A6410, aligned, strings + 8, 0xC2);
            e = (ArchiveEntry *)((u8 *)&fzgx_obj_lbl_1_bss_897AC);
            e += fzgx_obj_lbl_1_bss_897A0;
            *(u32 *)((u8 *)e + 0x68) = tmp2;
            fn_1_46B4(lbl_801A6410, (void *)tmp, strings + 8, 0xC3);
        } else {
            tmp = (u32)fn_1_45D0(lbl_801A6410, aligned, strings + 8, 0xC5);
            e = (ArchiveEntry *)((u8 *)&fzgx_obj_lbl_1_bss_897AC);
            e += fzgx_obj_lbl_1_bss_897A0;
            *(u32 *)((u8 *)e + 0x68) = tmp;
        }
        if (fn_1_45850(arg0) == 0) {
            OSPanic(strings + 8, 0xD2, strings + 0xD0);
            return 0;
        }
        slot = (u8 *)((u32)((u8 *)&fzgx_obj_lbl_1_bss_897AC[0]) + 0x68);
        fn_1_12FD4(arg0, *(u32 *)((u8 *)slot + fzgx_obj_lbl_1_bss_897A0 * 0x6C));
        lab_t0 = (void *)(*(u32 *)((u8 *)slot + fzgx_obj_lbl_1_bss_897A0 * 0x6C));
        DCFlushRange(lab_t0, aligned);
    } else {
        u32 aligned;

        aligned = ((u32)fn_1_45B2C(arg0) + 0x1F) & ~0x1F;
        tmp = (u32)fn_1_45D0(lbl_801A6410, (aligned + 0x1F) & ~0x1F, strings + 8, 0xF2);
        e = (ArchiveEntry *)((u8 *)&fzgx_obj_lbl_1_bss_897AC);
        e += fzgx_obj_lbl_1_bss_897A0;
        *(u32 *)((u8 *)e + 0x68) = tmp;
        if (fn_1_458A0(arg0, (void *)(*(u32 *)((u8 *)e + 0x68)), aligned, 0) < 0) {
            OSPanic(strings + 8, 0xF5, strings + 0xF8);
        }
        fn_1_45850(arg0);
    }

    e_2 = (ArchiveEntry *)((u8 *)&fzgx_obj_lbl_1_bss_897AC);
    e_2 += fzgx_obj_lbl_1_bss_897A0;
    return *(u32 *)((u8 *)e_2 + 0x68);
}
#pragma opt_common_subs reset

#pragma opt_propagation reset
/* fzgx:end fn_1_12A4B0 */

/* fzgx:begin fn_1_12A6D8 */
s32 fn_1_12A6D8(void *arg0) {
    u8 local[0x10];
    if (fn_8006A480((u8 *)&lbl_1_bss_897AC + lbl_1_bss_897A0 * 0x6c + 0x4c, arg0, local) != 0) {
        return fn_8006A998(local);
    }
    return 0;
}
/* fzgx:end fn_1_12A6D8 */

/* fzgx:begin fn_1_12A734 noprologue */
typedef signed long s32;


typedef unsigned char u8;


typedef unsigned long u32;


extern char lbl_1_data_40608[0xA];


extern char lbl_1_data_40720[0x30];


extern void OSPanic(char *arg0, s32 arg1, ...);


extern void *lbl_801A6410;


extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);


extern void *lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void OSPanic(char *arg0, s32 arg1, ...);
typedef struct fzgx_elem_lbl_1_bss_897AC {
s32 state;
u8 pad_4[0x64];
u32 handle;
} fzgx_elem_lbl_1_bss_897AC;


fzgx_elem_lbl_1_bss_897AC fzgx_obj_lbl_1_bss_897AC[0x40];
void fn_1_12A734(s32 idx) {
if (fzgx_obj_lbl_1_bss_897AC[idx].state == 1) {
fn_1_46B4(*(u32 *)&lbl_801A6410, fzgx_obj_lbl_1_bss_897AC[idx].handle, (const char *)lbl_1_data_40608, 0x145);
fzgx_obj_lbl_1_bss_897AC[idx].state = 0;
} else {
OSPanic((char *)lbl_1_data_40608, 0x149, (char *)lbl_1_data_40720);
}
}
/* fzgx:end fn_1_12A734 */

/* fzgx:begin fn_1_12A7C4 pool noprologue */
#include "types.h"
#include "rel/main_rel/archive.h"

typedef struct {
    s32 count;
    s32 loaded;
    u32 unk_8;
    u8 entries[1];
} ArchiveState;

extern s32 fn_8006A480(void *arg0, void *arg1, void *arg2);
extern void *fn_8006A998(void *arg0);
extern s32 fn_1_45730(void *arg0, void *arg1);
extern s32 fn_1_45B2C(void *arg0);
extern void fn_1_458A0(void *arg0, void *arg1, u32 arg2, u32 arg3);
extern void fn_1_45850(void *arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);

#pragma opt_propagation on
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s32 fzgx_obj_lbl_1_bss_897A0;
s32 lbl_1_bss_897A4;
u32 lbl_1_bss_897A8;
u8 fzgx_obj_lbl_1_bss_897AC[1];
u8 lbl_1_bss_897AC_fill_897AD;
u16 lbl_1_bss_897AC_fill_897AE;
u32 lbl_1_bss_897AC_fill_897B0[1740];
u32 fzgx_obj_lbl_1_bss_8B2E0[48];
u32 fzgx_obj_lbl_1_bss_8B3A0[83];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_897A0;
    s = *(u8 *)&lbl_1_bss_897A4;
    s = *(u8 *)&lbl_1_bss_897A8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_897AC;
    s = *(u8 *)&lbl_1_bss_897AC_fill_897AD;
    s = *(u8 *)&lbl_1_bss_897AC_fill_897AE;
    s = *(u8 *)&lbl_1_bss_897AC_fill_897B0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8B2E0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8B3A0;
}
#pragma section code_type ".text"

s32 fn_1_12A7C4(void *arg0, void *arg1, void *arg2) {
    u8 *entries;
    void *result;
    u8 work[12];
    u8 info[0x60];

    

    if (lbl_1_bss_897A4 != 0) {
        s32 count = fzgx_obj_lbl_1_bss_897A0;
        entries = fzgx_obj_lbl_1_bss_897AC;
        if (fn_8006A480(entries + count * 0x6C + 0x4C, arg0, work) != 0) {
            result = fn_8006A998(work);
        } else {
            result = 0;
        }
        if (result != 0) {
            fn_80008BA8((u32)arg1, (u32)result, (u32)arg2);
        } else {
            return 0;
        }
    } else {
        if (fn_1_45730(arg0, info) != 0) {
            s32 aligned;
            aligned = (fn_1_45B2C(info) + 0x1F) & ~0x1F;
            fn_1_458A0(info, arg1, aligned, 0);
            fn_1_45850(info);
        }
    }

    return 1;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_12A7C4 */

/* fzgx:begin fn_1_12A8A4 noprologue */
#include "types.h"
#include "rel/main_rel/archive.h"

extern u32 lbl_1_bss_897A0;
extern u32 lbl_801A6410;

typedef struct ArchiveState {
    s32 count;
    s32 loaded;
    u8 pad[4];
    u8 entries[1];
} ArchiveState;

extern s32 fn_8006A480(void *arg0, void *arg1, void *arg2);
extern void *fn_8006A998(void *arg0);
extern s32 fn_1_45730(void *arg0, void *arg1);
extern s32 fn_1_45B2C(void *arg0);
extern void *fn_1_45D0(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_458A0(void *arg0, void *arg1, u32 arg2, u32 arg3);
extern void fn_1_45850(void *arg0);
extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);

#pragma opt_propagation off
s32 fn_1_12A8A4(u32 arg0, void *arg1) {
    u8 *entries;
    s32 result;
    u8 work[12];
    u8 info[0x60];
    ArchiveState *state;

    state = (ArchiveState *)&lbl_1_bss_897A0;

    if (state->loaded != 0) {
        s32 count = state->count;
        entries = state->entries;
        if (fn_8006A480(entries + count * 0x6C + 0x4C,
                        (void *)arg0, work) != 0) {
            result = (s32)fn_8006A998(work);
        } else {
            result = 0;
        }
        *(void **)arg1 = (void *)result;
        if (*(void **)arg1 == 0) {
            return 0;
        }
    } else {
        if (fn_1_45730((void *)arg0, info) != 0) {
            s32 aligned;
            aligned = (fn_1_45B2C(info) + 0x1F) & ~0x1F;
            *(void **)arg1 = fn_1_45D0(lbl_801A6410, aligned,
                                       lbl_1_data_40608, 0x188);
            fn_1_458A0(info, *(void **)arg1, aligned, 0);
            fn_1_45850(info);
        } else {
            OSPanic(lbl_1_data_40608, 0x18C, lbl_1_data_40750);
        }
    }

    return 1;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_12A8A4 */

/* fzgx:begin fn_1_12A9BC noprologue */
#include "types.h"
#include "rel/main_rel/archive.h"

extern u32 lbl_1_bss_897A0;
extern u32 lbl_801A6410;

typedef struct ArchiveState {
    s32 count;
    s32 loaded;
    u8 pad[4];
    u8 entries[1];
} ArchiveState;

extern s32 fn_8006A480(void *arg0, void *arg1, void *arg2);
extern void *fn_8006A998(void *arg0);
extern s32 fn_1_45730(void *arg0, void *arg1);
extern s32 fn_1_45B2C(void *arg0);
extern void *fn_1_45D0(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_458A0(void *arg0, void *arg1, u32 arg2, u32 arg3);
extern void fn_1_45850(void *arg0);

#pragma opt_propagation off
s32 fn_1_12A9BC(void *arg0, void *arg1) {
    u8 *entries;
    s32 result;
    s32 ok = 1;
    u8 work[12];
    u8 info[0x50];
    ArchiveState *state;

    state = (ArchiveState *)&lbl_1_bss_897A0;

    if (state->loaded != 0) {
        s32 count = state->count;
        entries = state->entries;
        if (fn_8006A480(entries + count * 0x6C + 0x4C,
                        arg0, work) != 0) {
            result = (s32)fn_8006A998(work);
        } else {
            result = 0;
        }
        *(void **)arg1 = (void *)result;
        if (*(void **)arg1 == 0) {
            ok = 0;
        }
    } else {
        if (fn_1_45730(arg0, info) != 0) {
{
    s32 aligned;
            aligned = (fn_1_45B2C(info) + 0x1F) & ~0x1F;
            *(void **)arg1 = fn_1_45D0(lbl_801A6410, aligned,
                                       lbl_1_data_40608, 0x1AC);
            fn_1_458A0(info, *(void **)arg1, aligned, 0);
}
            fn_1_45850(info);
        } else {
            ok = 0;
        }
    }

    return ok;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_12A9BC */

/* fzgx:begin fn_1_12AAC8 */
void fn_1_12AAC8(void *arg0) {
    u8 local_8[0x18];
    u8 *obj;

    obj = (u8 *)&lbl_1_bss_897AC + lbl_1_bss_897A0 * 0x6C + 0x4C;
    if (fn_8006A480(obj, arg0, local_8) == 0) {
        OSPanic(lbl_1_data_40608, 0x1BE, lbl_1_data_4076C);
    }
    fn_8006A9AC(local_8);
}
/* fzgx:end fn_1_12AAC8 */

/* fzgx:begin fn_1_12AB38 */
struct fn_1_12AB38_state {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    u8 entries[1];
};

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
void fn_1_12AB38(void *arg0) {
    struct fn_1_12AB38_state *state =
        (struct fn_1_12AB38_state *)&lbl_1_bss_897A0;

    if (state->unk_4 != 0) {
        u8 *entry = state->entries;
        u32 index = state->unk_0;
        fn_8006A9B4(((0x4c) + ((index * 0x6c) + (entry))), arg0);
        if (state->unk_8 != 0) {
            fn_80006E10(arg0);
        }
    } else {
        fn_80006E10(arg0);
    }
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

#pragma opt_propagation reset
/* fzgx:end fn_1_12AB38 */

/* fzgx:begin fn_1_12ABB4 */
// Register the archive table only on its first use.
void fn_1_12ABB4(void *archive) {
    if (lbl_1_bss_897A4 == 0) {
        fn_1_46B4(lbl_801A6410, archive, lbl_1_data_40608, 0x1e0);
    }
}
/* fzgx:end fn_1_12ABB4 */

/* fzgx:begin fn_1_12AC00 */
void fn_1_12AC00(void *arg0) {
    fn_1_12AC28(arg0, 0, 0);
}
/* fzgx:end fn_1_12AC00 */

/* fzgx:begin fn_1_12AC28 noprologue */
#include "types.h"
#include "rel/main_rel/archive.h"

extern void *lbl_801A6410;

extern s32 fn_8006A480(void *entry, void *arg0, void *result);
extern void *fn_8006A998(void *result);
extern void *fn_8006A9AC(void *result);
extern void OSPanic(u8 *message, s32 line, u8 *file, ...);
extern void *fn_1_4630(void *arg0, void *arg1, void *arg2, s32 arg3);
extern void fn_80008BA8(void *arg0, void *arg1, void *arg2);
extern void *fn_1_D38A4(void *arg0, s32 arg1);
extern void *fn_1_D3884(void *arg0);

typedef struct ArchiveEntry {
    u8 field_0[0x4c];
    u8 data[0x20];
} ArchiveEntry;

typedef struct ArchiveState {
    s32 count;
    s32 ready;
    s32 fallback;
    ArchiveEntry entries[1];
} ArchiveState;

static inline ArchiveEntry *fn_1_12AC28_array_read(ArchiveEntry *array) { return array; }
#pragma opt_loop_invariants off
typedef struct lbl_1_bss_897AC_t {
    ArchiveEntry entries[1];
    u8 pad_6C[0x1ac8];
} lbl_1_bss_897AC_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s32 fzgx_obj_lbl_1_bss_897A0;
s32 lbl_1_bss_897A4;
s32 lbl_1_bss_897A8;
lbl_1_bss_897AC_t fzgx_obj_lbl_1_bss_897AC;
u32 fzgx_obj_lbl_1_bss_8B2E0[48];
u32 fzgx_obj_lbl_1_bss_8B3A0[83];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_897A0;
    s = *(u8 *)&lbl_1_bss_897A4;
    s = *(u8 *)&lbl_1_bss_897A8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_897AC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8B2E0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8B3A0;
}
#pragma section code_type ".text"

void *fn_1_12AC28(void *arg0, void **arg1, void **arg2) {
    void *ret;
    void *lookup;
    void *archive;
    u8 info1[12];
    u8 info2[12];

    
    if (lbl_1_bss_897A4 != 0) {
        if (fn_8006A480(fn_1_12AC28_array_read(fzgx_obj_lbl_1_bss_897AC.entries)[fzgx_obj_lbl_1_bss_897A0].data, arg0, info1) != 0) {
            lookup = fn_8006A998(info1);
        } else {
            lookup = 0;
        }
        archive = lookup;
        if (lookup != 0) {
            if (arg1 != 0 && arg2 != 0) {
                if (fn_8006A480(fn_1_12AC28_array_read(fzgx_obj_lbl_1_bss_897AC.entries)[fzgx_obj_lbl_1_bss_897A0].data, arg0, info2) == 0) {
                    OSPanic(lbl_1_data_40608, 0x1be, lbl_1_data_4076C);
                }
                *arg2 = fn_8006A9AC(info2);
                if (*arg2 != 0) {
                    *arg1 = fn_1_4630(lbl_801A6410, *arg2,
                        lbl_1_data_40608, 0x1fc);
                    fn_80008BA8(*arg1, lookup, *arg2);
                    archive = *arg1;
                }
                ret = fn_1_D38A4(archive, 0);
            } else {
                ret = fn_1_D38A4(lookup, 0);
            }
        } else if (lbl_1_bss_897A8 != 0) {
            ret = fn_1_D3884(arg0);
        } else {
            ret = 0;
        }
    } else {
        ret = fn_1_D3884(arg0);
    }
    return ret;
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_12AC28 */

/* fzgx:begin fn_1_12ADA0 */
void fn_1_12ADA0(void *arg0, void *arg1) {
    fn_1_12ADC8(arg0, arg1, 0, 0);
}
/* fzgx:end fn_1_12ADA0 */

/* fzgx:begin fn_1_12ADC8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/archive.h"

extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);
extern s32 fn_8006A480(void *arg0, void *arg1, void *arg2);
extern u32 fn_8006A998(void *arg0);
extern u32 fn_8006A9AC(void *arg0);
extern u32 fn_1_4630(u32 arg0, u32 arg1, u8 *arg2, u32 arg3);
extern s32 fn_1_D35B0(void *arg0, u32 arg1, void *arg2);
extern s32 fn_1_D358C(void *arg0, void *arg1);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u32 lbl_801A6410;

struct Obj_897AC {
    u8 pad_0[0x4C];
    u8 body[0x20];
};

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_897A0;
s32 fzgx_obj_lbl_1_bss_897A4;
s32 fzgx_obj_lbl_1_bss_897A8;
struct Obj_897AC fzgx_obj_lbl_1_bss_897AC[64];
u8 lbl_1_bss_897AC__fzgx_offset_1B00[0x34];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_897A0;
    s = fzgx_obj_lbl_1_bss_897A4;
    s = fzgx_obj_lbl_1_bss_897A8;
    s = fzgx_obj_lbl_1_bss_897AC[0].body[0];
    s = lbl_1_bss_897AC__fzgx_offset_1B00[0];
}
#pragma section code_type ".text"

s32 fn_1_12ADC8(void *arg0, void *arg1, void *arg2, void *arg3) {
    u32 loc_14[3];
    u32 loc_8[3];
    u32 v0;
    u32 v26;

    if (fzgx_obj_lbl_1_bss_897A4 != 0) {
        if (fn_8006A480(fzgx_obj_lbl_1_bss_897AC[fzgx_obj_lbl_1_bss_897A0].body, arg0, loc_14) != 0) {
            v0 = fn_8006A998(loc_14);
        } else {
            v0 = 0;
        }
        v26 = v0;
        if (v0 != 0) {
            if ((arg2 != 0) && (arg3 != 0)) {
                if (fn_8006A480(fzgx_obj_lbl_1_bss_897AC[fzgx_obj_lbl_1_bss_897A0].body, arg0, loc_8) == 0) {
                    OSPanic(lbl_1_data_40608, 0x1BE, lbl_1_data_4076C);
                }
                *(u32 *)arg3 = fn_8006A9AC(loc_8);
                if (*(u32 *)arg3 != 0) {
                    *(u32 *)arg2 = fn_1_4630(lbl_801A6410, *(u32 *)arg3, lbl_1_data_40608, 0x22A);
                    fn_80008BA8(*(u32 *)arg2, v0, *(u32 *)arg3);
                    v26 = *(u32 *)arg2;
                }
                return fn_1_D35B0((void *)v26, 0, arg1);
            }
            return fn_1_D35B0((void *)v0, 0, arg1);
        }
        if (fzgx_obj_lbl_1_bss_897A8 != 0) {
            return fn_1_D358C(arg0, arg1);
        }
        return 0;
    }
    return fn_1_D358C(arg0, arg1);
}
/* fzgx:end fn_1_12ADC8 */

/* fzgx:begin fn_1_12AF50 */
u32 fn_1_12AF50(u32 value) {
    u32 old_value = lbl_1_data_40600;
    lbl_1_data_40600 = value;
    return old_value;
}
/* fzgx:end fn_1_12AF50 */

/* fzgx:begin fn_1_12AF64 */
u32 fn_1_12AF64(void) {
    u32 value;

    value = lbl_1_data_40600;
    lbl_1_data_40600 = -1;
    return value;
}
/* fzgx:end fn_1_12AF64 */

/* fzgx:begin fn_1_12B120 noprologue */
#include "types.h"

typedef struct {
    u16 unk0;
    u32 unk4;
    u8 unk8;
    u8 pad9[3];
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
} Sig_fn_1_12C0EC_FnData;

struct fn_1_12B120_lbl_1_bss_8B3A0 {
    u8 pad_0[0x94];
    u32 unk_94;
    u8 pad_98[0x91];
    u8 unk_129;
};
struct fn_1_12B120_lbl_1_rodata_8178 {
    f64 unk_0;
};
extern f32 lbl_1_rodata_8170;
extern struct fn_1_12B120_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern struct fn_1_12B120_lbl_1_rodata_8178 lbl_1_rodata_8178;
extern u32 lbl_1_data_407BC;
extern u32 lbl_1_data_40A7C;
extern void fn_1_12C0EC(Sig_fn_1_12C0EC_FnData *);
extern u32 __cvt_fp2unsigned(f64);
extern u16 fn_1_A5D88(void);
extern void fn_1_12BF7C(void *, s16, u32, u32);
extern u32 fn_1_12C110(u32, u32, u32);
extern void * fn_1_12F118(void);
extern void fn_1_12C47C(void *, void *, s32);
extern u32 fn_1_12D404(u32, u32, u32, void *, u32, u32, void *, u32, u32, u32 *, u32);
extern void * fn_1_435C(void *);
extern s32 fn_1_3F8C(u32, u32, u8 *, void *);
extern void fn_1_12F1E8(s32);


extern s32 fn_1_132488;

void fn_1_12B120(u8 *arg0, void *arg1, void *arg2, s32 *arg3, void *arg4, s32 *arg5, s32 arg_sp0) {
    s32 sp10;
    u32 *spC;
    s32 sp8;
    s32 *var_r31;
    s16 var_r31_2;
    u32 temp_r24;
    void *var_r23;
    s32 var_r22;
    s16 var_r21;

    var_r31 = (s32 *)(arg3);
    var_r23 = (void *)(arg4);
    var_r21 = 0;
    var_r22 = 0;
    while (var_r21 < 4) {
        (*(s32 *)((u8 *)(var_r31) + 0)) = -1;
        (*(s32 *)((u8 *)(var_r23) + 0)) = -1;
        (*(s32 *)((u8 *)(var_r23) + 4)) = -1;
        fn_1_12C0EC((Sig_fn_1_12C0EC_FnData *)((*(s32 *)((u8 *)(arg0) + 28)) + var_r22));
        var_r31 = (s32 *)((u8 *)(var_r31) + 4);
        var_r23 = (void *)((u8 *)(var_r23) + 8);
        var_r22 += 0x1C;
        var_r21 += 1;
            }
    if (!(lbl_1_bss_8B3A0.unk_94 & 0x80000000)) {
        var_r31_2 = 4;
        if (lbl_1_bss_8B3A0.unk_94 & 0x20000000) {
            var_r31_2 = 1;
        } else if (lbl_1_bss_8B3A0.unk_94 & 0x40000) {
            var_r31_2 = 2;
        }
        if (lbl_1_bss_8B3A0.unk_94 & 0x40000000) {
            temp_r24 = (u32) ((*(f32 *)((u8 *)(&lbl_1_rodata_8170) + 0)) / (f32) var_r31_2);
            fn_1_12BF7C((void *)(*(void **)((u8 *)(arg0) + 32)), var_r31_2, (u32) ((s32) fn_1_A5D88() / var_r31_2), temp_r24);
            fn_1_12BF7C((void *)((u8 *)((*(void **)((u8 *)(arg0) + 32))) + 0x64), 3, (fn_1_A5D88() >> 2U) & 0x3FFF, 0x78U);
        } else if (var_r31_2 == 4) {
            fn_1_12BF7C((void *)(*(void **)((u8 *)(arg0) + 32)), var_r31_2, 0xA0U, 0x78U);
        } else if (var_r31_2 == 2) {
            fn_1_12BF7C((void *)(*(void **)((u8 *)(arg0) + 32)), var_r31_2, 0x1A0U, 0xC0U);
        } else {
            fn_1_12BF7C((void *)(*(void **)((u8 *)(arg0) + 32)), var_r31_2, 0x230U, 0x190U);
        }
        if (var_r31_2 == 4) {
            fn_1_12BF7C((void *)(*(void **)((u8 *)(arg0) + 36)), var_r31_2, 0xA0U, 0x8CU);
        } else if (var_r31_2 == 2) {
            fn_1_12BF7C((void *)(*(void **)((u8 *)(arg0) + 36)), var_r31_2, 0x1A0U, 0xC0U);
        } else {
            fn_1_12BF7C((void *)(*(void **)((u8 *)(arg0) + 36)), var_r31_2, 0x280U, 0x18CU);
        }
        fn_1_12C110(*(u32 *)((u8 *)(arg0) + 12), (u32) (*(s16 *)((u8 *)(arg0) + 22)), (u32) (*(s16 *)((u8 *)(arg0) + 20)));
        fn_1_12C47C((void *)(*(void **)((u8 *)(arg0) + 16)), (void *)(fn_1_12F118()), (s32) (*(s16 *)((u8 *)(arg0) + 20)));
        fn_1_12D404(*(u32 *)((u8 *)(arg0) + 4), *(u32 *)((u8 *)(arg0) + 8), *(u32 *)((u8 *)(arg0) + 24), (void *)(arg1), (u32)(arg3), (u32)(arg4), (void *)(*(void **)((u8 *)(arg0) + 40)), *(u32 *)((u8 *)(arg0) + 48), *(u32 *)((u8 *)(arg0) + 52), (u32 *)(&lbl_1_data_407BC), 3U);
    }
    fn_1_435C((void *)(arg2));
    (*(s32 *)((u8 *)(arg5) + 0)) = fn_1_3F8C((u32)(&lbl_1_data_40A7C), (u32)(&fn_1_132488), (u8 *)(arg0), (void *)(*(void **)((u8 *)(arg0) + 44)));
    fn_1_12F1E8(0x1E0);
    lbl_1_bss_8B3A0.unk_129 = 1;
}
/* fzgx:end fn_1_12B120 */

/* fzgx:begin fn_1_12B3BC */
typedef struct {
    u8 pad_0[0x4];
    void *unk_4;
    void *unk_8;
    u8 pad_C[0x10];
    void *unk_1C;
} FnObj;

void fn_1_12B3BC(FnObj *arg0, void *arg1, void *arg2, void *arg3,
                 void *arg4, void *arg5, void *arg6) {
    fn_1_12BB18(arg0->unk_4, arg0->unk_8, &lbl_1_bss_8B3A0,
                 arg0->unk_1C, arg6);
}
/* fzgx:end fn_1_12B3BC */

/* fzgx:begin fn_1_12B3F8 noprologue */
#include "types.h"

struct fn_1_12B3F8_Arg5 {
    u32 unk_0;
};
struct fn_1_12B3F8_lbl_1_bss_8B3A0 {
    u8 pad_0[0x94];
    u32 unk_94;
};
extern struct fn_1_12B3F8_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern void * fn_1_435C(void *);
extern void fn_1_426C(u32);
extern u32 fn_1_12DAEC(u32, u32, u32, void *, u32, u32, u32);
extern u32 fn_1_12C524(u32);
extern void fn_1_12C000(void *, s16);


void fn_1_12B3F8(void *arg0, void *arg1, void *arg2, u32 arg3, u32 arg4, s32 *arg5, s32 arg_sp0) {
    s16 var_r30;

    if ((s32) (*(s32 *)((u8 *)(arg5) + 0)) != -1) {
        fn_1_435C((void *)(arg2));
        fn_1_426C((u32) (*(s32 *)((u8 *)(arg5) + 0)));
        (*(s32 *)((u8 *)(arg5) + 0)) = -1;
    }
    if (!(lbl_1_bss_8B3A0.unk_94 & 0x80000000)) {
        var_r30 = 4;
        fn_1_12DAEC(*(u32 *)((u8 *)(arg0) + 4), *(u32 *)((u8 *)(arg0) + 8), *(u32 *)((u8 *)(arg0) + 24), (void *)(arg1), arg3, arg4, *(u32 *)((u8 *)(arg0) + 52));
        fn_1_12C524(*(u32 *)((u8 *)(arg0) + 12));
        if (lbl_1_bss_8B3A0.unk_94 & 0x20000000) {
            var_r30 = 1;
        } else if (lbl_1_bss_8B3A0.unk_94 & 0x40000) {
            var_r30 = 2;
        }
        if (lbl_1_bss_8B3A0.unk_94 & 0x40000000) {
            fn_1_12C000((void *)(*(void **)((u8 *)(arg0) + 36)), 4);
        } else {
            fn_1_12C000((void *)(*(void **)((u8 *)(arg0) + 36)), var_r30);
        }
        fn_1_12C000((void *)(*(void **)((u8 *)(arg0) + 32)), var_r30);
    }
}
/* fzgx:end fn_1_12B3F8 */

/* fzgx:begin fn_1_12B4EC */
typedef signed short s16;


typedef unsigned char u8;


typedef unsigned long u32;


struct Ent {
u8 b;
u8 pad[3];
u32 v[1];
};
struct Blk {
u8 pad[0x81A4];
struct Ent e[3];
u8 pad2[4];
};


extern u8* fn_1_36AD0(void);


extern u32 fn_1_151BE8(s16 arg0, s16 arg1);
void fn_1_12B4EC(s16 arg0, s16 arg1) {
struct Blk *p;
s16 i;
s16 j;
u8 k;
p = (struct Blk *)fn_1_36AD0() + arg0;
k = arg1 % 4;
for (i = 0; i < 3; i++) {
for (j = 0; j < 1; j++) {
p->e[i].v[j] = fn_1_151BE8(p->e[i].b, k + j);
}
}
}
/* fzgx:end fn_1_12B4EC */

/* fzgx:begin fn_1_12B5B4 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/archive.h"
#include "dolphin/types.h"
#include "rel/main_rel/archive.h"

extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);
extern void fn_1_12A350(void *arg0, s32 arg1);
extern s32 fn_8006A480(void *arg0, void *arg1, void *arg2);
extern s32 fn_8006A998(void *arg0);
extern void fn_8006A9AC(void *arg0);
extern void fn_1_12AC28(void *arg0, s32 arg1, s32 arg2);
extern void fn_1_12ADC8(void *arg0, void *arg1, s32 arg2, s32 arg3);
extern void fn_1_12BB18(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
extern void fn_1_8D168(void *arg);
extern void fn_1_14DB48(void *arg0, void *arg1, u32 arg2);
extern void fn_1_14DBCC(void *arg);
extern u32 fn_1_95120(void *arg);
extern const struct Table lbl_1_rodata_8230;
extern u32 lbl_801A66A0;
extern void fn_1_7B2E8(u8 value);
extern void fn_1_13C1A0(void);
extern void *fn_1_3F8C(void *table, void (*callback)(void), void *arg1, void *arg2);
extern void fn_1_426C(s32 value);
extern void fn_1_7B4C0(void);
extern void fn_1_C2454(void);
extern s32 fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);

extern s32 lbl_1_bss_897A4;
extern void *lbl_801A6410;
extern void fn_1_46B4(void *arg0, void *arg1, unsigned char *arg2, s32 arg3);
extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);

extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);
extern s32 lbl_1_bss_8CA44[10];

extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);
extern void fn_1_435C();
extern s32 fn_1_45730(void *arg0, void *arg1);
extern s32 fn_1_45B2C(void *arg0);
extern void *fn_1_45D0(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_458A0(void *arg0, void *arg1, u32 arg2, u32 arg3);
extern void fn_1_45850(void *arg0);
extern void fn_8006A9B4(void *arg0, void *arg1);
extern void fn_80006E10(void *arg0);
extern u32 fn_1_12DAEC(u32, u32, u32, void *, u32, u32, u32);
extern u32 fn_1_12C524(u32);
extern void fn_1_12C000(void *arg, s16 count);
extern void fn_1_8CED0(void *arg, u16 a, u16 b);
extern void fn_1_8D0A4(void *arg);
extern s16 fn_1_12C930(s16 arg);
extern u8 lbl_1_data_20D1C[180];
extern u8 lbl_1_bss_8B4EC[128];
extern void fn_80083DB0(void *arg0, char *arg1);
extern void strcat(void *arg0, void *arg1);
extern s32 fn_1_F89E4(u8 value);


extern u8* fn_1_36AD0(void);

typedef struct {
    u32 unk_0;
    u32 pad_4;
} Fn_1_12B5B4Entry;

typedef struct {
    u8 pad_0[0x81A8];
    Fn_1_12B5B4Entry unk_81A8[3];
} Fn_1_12B5B4Data;

#pragma opt_unroll_loops off
void fn_1_12B5B4(s16 arg0, s16 arg1)
{
    Fn_1_12B5B4Data* data = (Fn_1_12B5B4Data*)fn_1_36AD0() + arg0;
    s16 i = 0;
    while ((s16)i < 3) {
        data->unk_81A8[i].unk_0 =
            ((u32 (*)[4][3])&lbl_1_bss_8B2E0.unk_0)[arg0][(s16)(arg1 % 4)][i];
        i++;
    }
}
/* fzgx:end fn_1_12B5B4 */

/* fzgx:begin fn_1_12BF7C */
#include "types.h"

typedef struct {
    u8 pad[0x94];
    u32 unk94;
} GlobalState;

void fn_1_12BF7C(void *arg, s16 count, u32 a, u32 b) {
    u8 *p;
    s16 i;

    if (((*(GlobalState *)&lbl_1_bss_8B3A0).unk94 & 0x80000000) == 0) {
        p = (u8 *)arg;
        i = 0;
        while (i < count) {
            fn_1_8CED0(p, (u16)a, (u16)b);
            fn_1_8D0A4(p);
            p += 100;
            i++;
        }
    }
}
/* fzgx:end fn_1_12BF7C */

/* fzgx:begin fn_1_12C000 */
void fn_1_12C000(void *arg, s16 count) {
    u8 *p;
    s16 i;

    p = (u8 *)arg;
    i = 0;
    while (i < count) {
        fn_1_8D168(p);
        p += 100;
        i++;
    }
}
/* fzgx:end fn_1_12C000 */

/* fzgx:begin fn_1_12C060 */
typedef struct FnData FnData;

struct FnData {
    u16 unk0;
    u32 unk4;
    u8 unk8;
    u8 pad9[3];
    u8 (*unkC)(FnData *, u32);
    u32 unk10;
    s32 (*unk14)(FnData *, u32);
    u32 unk18;
};

s32 fn_1_12C060(FnData *arg) {
    if (arg->unk8 == 0) {
        return 0;
    }
    if (arg->unkC(arg, arg->unk10) == 1) {
        arg->unk8 = 0;
        arg->unk4 = 0;
        return arg->unk14(arg, arg->unk18);
    }
    arg->unk4++;
    return 0;
}
/* fzgx:end fn_1_12C060 */

/* fzgx:begin fn_1_12C0EC */
typedef struct {
    u16 unk0;
    u32 unk4;
    u8 unk8;
    u8 pad9[3];
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
} FnData;

void fn_1_12C0EC(FnData *arg) {
    arg->unk18 = 0;
    arg->unk14 = 0;
    arg->unk10 = 0;
    arg->unkC = 0;
    arg->unk8 = 0;
    arg->unk4 = 0;
    arg->unk0 = 0;
}
/* fzgx:end fn_1_12C0EC */

/* fzgx:begin fn_1_12C47C */
void fn_1_12C47C(void *arg0, void *arg1, s32 arg2) {
    void *entry;
    void *obj;
    u32 mask;
    s16 i;

    if ((lbl_1_bss_8B3A0.unk_94 & 0x02000000) != 0) {
        return;
    }
    entry = arg1;
    obj = arg0;
    i = 0;
    mask = 1 << arg2;
    while (i < 4) {
        if (((*(u32 *)entry & ((u32)1 << 31)) != 0) &&
            ((*(u32 *)entry & ((u32)1 << 30)) != 0)) {
            fn_1_14DB48(entry, obj, mask);
        }
        entry = (u8 *)entry + 0x81c0;
        obj = (u8 *)obj + 0xa20;
        i++;
    }
}
/* fzgx:end fn_1_12C47C */

/* fzgx:begin fn_1_12C524 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/archive.h"

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};
extern void fn_80071718(struct Sig_fn_80071718_fn_80071718_Arg0 *);

void fn_1_12C524(void *arg) {
    struct { s16 value; } j;
    u8 *q;
    u8 *p;
    s16 i;
    p = arg;
    i = 0;
    while (i < 41) {
        if (*(s8 *)(p + 0x328) >= 0 && *(s8 *)(p + 0x328) <= 40) {
            j.value = 0;
            q = p;
            while (j.value < 4) {
                if (*(s16 *)(p + 0x3b8) % 4 != j.value) {
                    if (*(struct Sig_fn_80071718_fn_80071718_Arg0 **)(q + 0x37c)) {
                        fn_80071718(*(struct Sig_fn_80071718_fn_80071718_Arg0 **)(q + 0x37c));
                        *(struct Sig_fn_80071718_fn_80071718_Arg0 **)(q + 0x37c) = 0;
                    }
                }
                q += 4;
                j.value++;
            }
        }
        p += 0x440;
        i++;
    }
}
/* fzgx:end fn_1_12C524 */

/* fzgx:begin fn_1_12C5E4 */
typedef struct {
    u8 pad0[0x328];
    s8 flag;
    u8 pad329[0x37c - 0x329];
    void *items[4];
    u8 pad38c[0x3b8 - 0x38c];
    s16 values[4];
    u8 pad3c0[0x440 - 0x3c0];
} FnData;

extern void fn_80071718(void *arg);
extern void fn_80008BEC(void *arg, s32 value, void *table);

#pragma opt_common_subs off
void fn_1_12C5E4(FnData *arg) {
    FnData *base;
    struct { s16 value; } outer;
    FnData *p;
    struct { s16 value; } inner;
    FnData *q;
    void *zero;
    s8 tmp_ra2;

    base = arg;
    outer.value = 0;
    p = base;
    zero = 0;
    while (outer.value < 0x29) {
        tmp_ra2 = p->flag;
        if ((s8)tmp_ra2 >= 0 && (s8)tmp_ra2 <= 0x28) {
            inner.value = 0;
            q = p;
            while (inner.value < 4) {
                if ((p->values[0] % 4) != inner.value && q->items[inner.value] != 0) {
                    fn_80071718(q->items[inner.value]);
                    q->items[inner.value] = zero;
                }
                inner.value++;
            }
        }
        p++;
        outer.value++;
    }
    fn_80008BEC(base, 0, (void *)((u32)0x10000 - 0x51C0));
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_12C5E4 */

/* fzgx:begin fn_1_12C6BC */
void fn_1_12C6BC(void *arg) {
    u8 *p;
    s16 i;

    p = (u8 *)arg;
    i = 0;
    while (i < 9) {
        fn_1_14DBCC(p);
        p += 0xa20;
        i++;
    }
}
/* fzgx:end fn_1_12C6BC */

/* fzgx:begin fn_1_12C710 */
s16 fn_1_12C710(int arg) {
    s16 i;

    switch (arg) {
    case 0x15:
    case 0x29:
        return 0x15;
    case 0x21:
    case 0x2a:
    case 0x2b:
        return 0x21;
    }

    i = 0;
    while (i < 0x29) {
        if (arg == fn_1_12C930(i)) {
            return i;
        }
        i++;
    }
    return -1;
}
/* fzgx:end fn_1_12C710 */

/* fzgx:begin fn_1_12C7B8 */
typedef struct {
    u8 pad0[5];
    u8 id;
    u8 pad6[0x819a];
    u8 value;
    u8 pad_a1[0x1f];
} fn_1_12C7B8_FnEntry;

extern fn_1_12C7B8_FnEntry *fn_1_12F118(void);
extern fn_1_12C7B8_FnEntry *fn_1_36AD0(void);

s16 fn_1_12C7B8(s16 arg) {
    fn_1_12C7B8_FnEntry *table;
    s16 i;

    if (arg < 0x29) {
        return arg;
    }

    table = fn_1_12F118();
    if (table == 0) {
        return 6;
    }

    if (table != fn_1_36AD0()) {
        for (i = 0; i < 9; i++) {
            if (table[i].id == arg) {
                return table[i].value;
            }
        }
    } else if (arg >= 0x32 && arg <= 0x35) {
        return table[arg - 0x32].value;
    } else if (arg >= 0x36 && arg <= 0x39) {
        return table[arg - 0x36].value;
    } else {
        for (i = 0; i < 4; i++) {
            if (table[i].id == arg) {
                return table[i].value;
            }
        }
    }

    return 6;
}
/* fzgx:end fn_1_12C7B8 */

/* fzgx:begin fn_1_12C930 */
typedef struct MappingTable {
    s32 values[41];
} MappingTable;
typedef struct Record {
    u8 pad0[5];
    u8 id;
    u8 pad6[0x819A];
    u8 mapping;
    u8 pad81A1[0x1F];
} Record;
extern MappingTable lbl_1_rodata_8180;
extern void *fn_1_12F118(void);
extern u8 *fn_1_36AD0(void);

s16 fn_1_12C930(s16 arg0) {
    MappingTable table = lbl_1_rodata_8180;
    Record *records;
    s16 index;
    if (arg0 < 0)
        return 1;
    if (arg0 < 41) {
        index = arg0;
    } else {
        records = fn_1_12F118();
        if (!records) {
            index = 6;
            goto done; /* Common table lookup. */
        }
        if (records != (Record *)fn_1_36AD0()) {
            s32 id = arg0;
            for (index = 0; index < 9; index++) {
                if (records[index].id == id) {
                    index = records[index].mapping;
                    goto done; /* Common table lookup. */
                }
            }
        } else {
            if (arg0 >= 50 && arg0 <= 53) {
                index = records[arg0 - 50].mapping;
                goto done; /* Common table lookup. */
            }
            if (arg0 >= 54 && arg0 <= 57) {
                index = records[arg0 - 54].mapping;
                goto done; /* Common table lookup. */
            }
            {
                s16 j;
                for (j = 0; j < 4; j++) {
                    if (records[j].id == arg0) {
                        index = records[j].mapping;
                        goto done; /* Common table lookup. */
                    }
                }
            }
        }
        index = 6;
    }
done:
    return table.values[index];
}
/* fzgx:end fn_1_12C930 */

/* fzgx:begin fn_1_12CB04 */
typedef struct {
    u8 pad0[5];
    u8 id;
    u8 pad6[0x819a];
    u8 value;
    u8 pad_a1[0x1f];
} fn_1_12CB04_FnEntry;

extern fn_1_12CB04_FnEntry *fn_1_12F118(void);
extern fn_1_12CB04_FnEntry *fn_1_36AD0(void);

static inline s16 fn_1_12CB04_inline(s16 arg) {
    fn_1_12CB04_FnEntry *table;
    s16 i;

    if (arg < 0x29) {
        return arg;
    }

    table = fn_1_12F118();
    if (table == 0) {
        return 6;
    }

    if (table != fn_1_36AD0()) {
        for (i = 0; i < 9; i++) {
            if (table[i].id == arg) {
                return table[i].value;
            }
        }
    } else if (arg >= 0x32 && arg <= 0x35) {
        return table[arg - 0x32].value;
    } else if (arg >= 0x36 && arg <= 0x39) {
        return table[arg - 0x36].value;
    } else {
        for (i = 0; i < 4; i++) {
            if (table[i].id == arg) {
                return table[i].value;
            }
        }
    }

    return 6;
}

s32 fn_1_12CB04(s16 arg) {
    switch (fn_1_12CB04_inline(arg)) {
    case 0x15:
        return 1;
    case 0x21:
        return 2;
    }

    return 0;
}
/* fzgx:end fn_1_12CB04 */

/* fzgx:begin fn_1_12CCB0 */
extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);

typedef struct {
    u8 pad0[5];
    u8 id;
    u8 pad6[0x819a];
    u8 value;
    u8 pad_a1[0x1f];
} fn_1_12CCB0_FnEntry;

extern fn_1_12CCB0_FnEntry *fn_1_12F118(void);
extern fn_1_12CCB0_FnEntry *fn_1_36AD0(void);

static inline s16 fn_1_12C7B8(s16 arg) {
    fn_1_12CCB0_FnEntry *table;
    s16 i;

    if (arg < 0x29) {
        return arg;
    }

    table = fn_1_12F118();
    if (table == 0) {
        return 6;
    }

    if (table != fn_1_36AD0()) {
        for (i = 0; i < 9; i++) {
            if (table[i].id == arg) {
                return table[i].value;
            }
        }
    } else if (arg >= 0x32 && arg <= 0x35) {
        return table[arg - 0x32].value;
    } else if (arg >= 0x36 && arg <= 0x39) {
        return table[arg - 0x36].value;
    } else {
        for (i = 0; i < 4; i++) {
            if (table[i].id == arg) {
                return table[i].value;
            }
        }
    }

    return 6;
}

s16 fn_1_12CCB0(s16 arg0, s16 arg1) {
    switch (fn_1_12C7B8(arg0)) {
    case 0x15:
        switch (arg1) {
        case 0:
            return 0x29;
        default:
            return -1;
        }
    case 0x21:
        switch (arg1) {
        case 0:
            return 0x2a;
        case 1:
            return 0x2b;
        }
        return -1;
    }
    return -1;
}
/* fzgx:end fn_1_12CCB0 */

/* fzgx:begin fn_1_12CEA8 */
extern void *fn_1_12F118(void);
extern u8 *fn_1_36AD0(void);
extern void fn_1_12D354(void *, void *, void *);
extern u32 fn_1_8F198(u32, u32, void *, u32);
typedef struct {
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
} Sig_fn_1_8F45C_Fn1_8F45C_Object;
extern void fn_1_8F45C(Sig_fn_1_8F45C_Fn1_8F45C_Object *, u32, void *, u32);

typedef struct {
    u8 pad_0[5];
    u8 id;
    u8 pad_6[0x819A];
    u8 kind;
    u8 pad_81a1[0x1f];
} Entry;

static inline u32 get_kind(u32 arg0) {
    Entry *base;
    s16 i;
    if ((s16)arg0 < 41)
        return arg0;
    base = fn_1_12F118();
    if (!base)
        return 6;
    if ((u8 *)base != fn_1_36AD0()) {
        for (i = 0; i < 9; i++) {
            if ((s16)arg0 == base[i].id)
                return base[i].kind;
        }
    } else {
        if ((s16)arg0 >= 50 && (s16)arg0 <= 53)
            return base[(s16)arg0 - 50].kind;
        if ((s16)arg0 >= 54 && (s16)arg0 <= 57)
            return base[(s16)arg0 - 54].kind;
        for (i = 0; i < 4; i++) {
            if ((s16)arg0 == base[i].id)
                return base[i].kind;
        }
    }
    return 6;
}

static inline s16 get_item(u32 arg0, s16 i) {
    switch ((s16)get_kind(arg0)) {
    case 21:
        switch (i) {
        case 0: return 41;
        default: return -1;
        }
    case 33:
        switch (i) {
        case 0: return 42;
        case 1: return 43;
        default: return -1;
        }
    default: return -1;
    }
}

static inline s16 get_count(u32 arg0) {
    switch ((s16)get_kind(arg0)) {
    case 21: return 1;
    case 33: return 2;
    default: return 0;
    }
}

#pragma opt_dead_assignments off
void fn_1_12CEA8(u32 arg0, u32 arg1, void *arg2, u32 arg3, s32 arg4) {
    u32 v9;
    u32 v1;
    u32 v2;
    s32 v3;
    s32 v4;
    s32 v5;
    u32 v6;
    u32 v7;
    u32 v8;
    s16 v0;
    s16 item;
    v0 = (s16)arg0;
    v1 = v0 - 50;
    v2 = 0x81c0;
    v3 = v1 * v2;
{
    s32 fzgx_loop_v5_2101;
    v4 = (v0 - 54) * v2;
    fzgx_loop_v5_2101 = 0;
    v6 = v2;
    v7 = arg1;
    v8 = 0;
    v9 = arg1;
    while ((s16)fzgx_loop_v5_2101 < get_count(arg0)) {
        item = get_item(arg0, (s16)fzgx_loop_v5_2101);
        if (item != -1) {
            if ((s32)arg4) {
                fn_1_12D354((void *)item, arg2, (void *)v9);
                fn_1_8F198(v9, item, arg2, arg3);
            } else {
                fn_1_8F45C((Sig_fn_1_8F45C_Fn1_8F45C_Object *)v9, item, arg2, arg3);
            }
        }
        v9 += 0x4e0;
        fzgx_loop_v5_2101++;
    }
    v5 = fzgx_loop_v5_2101;
}
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_12CEA8 */

/* fzgx:begin fn_1_12D254 */
#include "types.h"

#pragma opt_propagation off
u8 *fn_1_12D254(s32 arg0, s32 arg1) {
    char *base;
    void *value;

    base = (*(char (*)[9])&lbl_1_data_40798);
    value = ((void **)lbl_1_data_20D1C)[arg0];
    fn_80083DB0(lbl_1_bss_8B4EC, base + 0x324);
    strcat(lbl_1_bss_8B4EC, value);
    strcat(lbl_1_bss_8B4EC, base + 0x330);

    switch (arg1) {
    case 0x40000000:
        strcat(lbl_1_bss_8B4EC, base + 0x338);
        break;
    case 0x20000000:
        strcat(lbl_1_bss_8B4EC, base + 0x340);
        break;
    case 0x10000000:
        strcat(lbl_1_bss_8B4EC, base + 0x348);
        break;
    }

    strcat(lbl_1_bss_8B4EC, base + 0x350);
    return lbl_1_bss_8B4EC;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_12D254 */

/* fzgx:begin fn_1_12D354 */
// Registers an object in the first available archive slot and reports overflow.
void fn_1_12D354(void *arg0, void *arg1, void *arg2) {
    u8 *archive_data = lbl_1_data_40798;
    u32 slot;

    if (arg2 == 0) {
        OSPanic(archive_data + 0x358, 0x388, archive_data + 0x368);
    }

    for (slot = 0; slot < 12; slot++) {
        if ((&lbl_1_bss_8B56C.unk_0)[slot * 2] == 0) {
            (&lbl_1_bss_8B56C.unk_0)[slot * 2] = (u32)arg2;
            (&lbl_1_bss_8B56C.unk_0)[slot * 2 + 1] = 0;
            return;
        }
    }

    OSPanic(archive_data + 0x358, 0x394, archive_data + 0x390);
}
/* fzgx:end fn_1_12D354 */

/* fzgx:begin fn_1_12E0B8 noprologue */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef struct {
u8 pad_0[0x19];
u8 unk_19;
} Obj_1_bss_8B3A0_AtA4;
typedef struct {
s16 unk_0;
u8 pad_2[0x2];
s16 unk_4;
u8 pad_6[0x2];
s16 unk_8;
u8 pad_A[0x4];
s16 unk_E;
u8 pad_10[0x4];
u8 unk_14;
u8 pad_15[0x19];
s16 unk_2E;
u8 pad_30[0x5C];
s16 unk_8C;
u8 pad_8E[0x2];
s16 unk_90;
s16 unk_92;
u32 unk_94;
u8 pad_98[0x6];
u8 unk_9E;
u8 unk_9F;
u8 pad_A0[0x4];
Obj_1_bss_8B3A0_AtA4 *unk_A4;
u8 pad_A8[0x8];
s16 unk_B0;
s16 unk_B2;
u8 pad_B4[0xC];
s16 unk_C0;
s16 unk_C2;
u8 pad_C4[0xC];
s16 unk_D0;
s16 unk_D2;
u8 pad_D4[0xC];
u32 unk_E0;
u32 unk_E4;
u32 unk_E8;
u32 unk_EC;
u32 unk_F0;
u32 unk_F4;
u32 unk_F8;
u32 unk_FC;
u32 unk_100;
u32 unk_104;
u32 unk_108;
u32 unk_10C;
u32 unk_110;
u32 unk_114;
u32 unk_118;
u32 unk_11C;
u32 unk_120;
u32 unk_124;
u8 unk_128;
u8 unk_129;
u8 pad_12A[0x2];
s16 unk_12C;
s16 unk_12E;
s16 unk_130;
s16 unk_132;
s16 unk_134;
s16 unk_136;
s16 unk_138;
s16 unk_13A;
s16 unk_13C;
u8 pad_13E[0x2];
u32 unk_140;
u8 pad_144[0x2];
s16 unk_146;
s16 unk_148;
u8 pad_14A[0x2];
} Obj_1_bss_8B3A0;
extern Obj_1_bss_8B3A0 lbl_1_bss_8B3A0;


extern u8 lbl_1_data_40BA0[0x10];


typedef struct Sig_fn_1_41488_Fn41488Data {
u32 count;
char *strings;
} Sig_fn_1_41488_Fn41488Data;


typedef struct {
u8 pad_0[0x24];
Sig_fn_1_41488_Fn41488Data *strings;
} Fn12E0B8_Names;
typedef struct {
u8 pad_0[0x18];
u32 flags;
u8 pad_1C[0x148 - 0x1C];
u8 event[0x8];
Fn12E0B8_Names *names;
u8 pad_154[0x4E0 - 0x154];
} Fn12E0B8_Car;
typedef struct {
u8 pad_0[0x5];
u8 id;
u8 pad_6[0x81A0 - 0x6];
u8 kind;
u8 pad_81A1[0x81C0 - 0x81A1];
} Fn12E0B8_Entry;


extern int fn_1_41488(Sig_fn_1_41488_Fn41488Data *, const char *);
extern void fn_1_933D8(Fn12E0B8_Car *, void *, u16);


extern void * fn_1_12F118(void);
extern u8* fn_1_36AD0(void);
extern u32 fn_1_95120(void *arg);


static inline s16 fn_1_12E0B8_kind(s16 id) {
Fn12E0B8_Entry *entries;
s16 j;
if (id < 0x29) {
return id;
}
entries = (Fn12E0B8_Entry *)fn_1_12F118();
if (entries == ((void *)0) ) {
return 6;
}
if (entries != (Fn12E0B8_Entry *)fn_1_36AD0()) {
for (j = 0; j < 9; j++) {
if (id == entries[j].id) {
return entries[j].kind;
}
}
} else {
if (id >= 0x32 && id <= 0x35) {
return entries[id - 0x32].kind;
}
if (id >= 0x36 && id <= 0x39) {
return entries[id - 0x36].kind;
}
for (j = 0; j < 4; j++) {
if (id == entries[j].id) {
return entries[j].kind;
}
}
}
return 6;
}
static inline s16 fn_1_12E0B8_count(s16 id) {
switch (fn_1_12E0B8_kind(id)) {
case 0x15:
return 1;
case 0x21:
return 2;
default:
return 0;
}
}
static inline u32 fn_1_12E0B8_pick(s16 slot, Fn12E0B8_Car *car, const char **names, u32 index, Obj_1_bss_8B3A0 *mgr) {
u8 table8[8] = { 0, 0, 0, 1, 0, 0, 0, 2 };
u8 table3[3] = { 1, 0, 2 };
u32 cnt;
if ((u8)index == 1) {
index = fn_1_41488(car->names->strings, names[0]);
} else {
do {
if (mgr->unk_94 & 0x40000000) {
index = fn_1_41488(car->names->strings, names[table3[((u32 *)lbl_1_data_40BA0)[slot] % 3]]);
cnt = ((u32 *)lbl_1_data_40BA0)[slot] + 1;
((u32 *)lbl_1_data_40BA0)[slot] = (cnt > 3) ? 0 : cnt;
} else {
index = fn_1_41488(car->names->strings, names[table8[((u32 *)lbl_1_data_40BA0)[slot] % 8]]);
cnt = ((u32 *)lbl_1_data_40BA0)[slot] + 1;
((u32 *)lbl_1_data_40BA0)[slot] = (cnt > 8) ? 0 : cnt;
}
} while (index == 0xFFFFFFFF);
}
return index;
}
void fn_1_12E0B8(s16 slot, s16 id, Fn12E0B8_Car *car, Fn12E0B8_Car *others, s32 check, const char **names, u32 index) {
Obj_1_bss_8B3A0 *mgr;
s16 i;
if (id == -1 || car == ((void *)0) ) {
return;
}
mgr = &lbl_1_bss_8B3A0;
if (mgr->unk_94 & 0x80000000) {
return;
}
if (check == 1) {
if ((s32)fn_1_95120(car->event) == 0) {
return;
}
}
index = fn_1_12E0B8_pick(slot, car, names, index, mgr);
fn_1_933D8(car, car->event, index);
car->flags &= 0x7FFFFFFF;
for (i = 0; i < fn_1_12E0B8_count(id); i++) {
fn_1_933D8(&others[i], others[i].event, index);
others[i].flags &= 0x7FFFFFFF;
}
}
/* fzgx:end fn_1_12E0B8 */

/* fzgx:begin fn_1_12E424 */
// Reports whether the archive state is active, otherwise querying the supplied entry.
u8 fn_1_12E424(void *arg0, u8 *arg1) {
    if (lbl_1_bss_8B3A0.unk_94 & (1u << 31)) {
        return 1;
    }
    return (u8)fn_1_95120(arg1 + 0x148);
}
/* fzgx:end fn_1_12E424 */

/* fzgx:begin fn_1_12ECA8 */
extern void fn_1_934CC(void *arg0, void *arg1, void *arg2);
extern u8 lbl_1_bss_8B5CC[32];
extern void fn_1_12E424(void);
extern void fn_1_12E468(void);

typedef struct {
    u8 pad0[5];
    u8 id;
    u8 pad6[0x819a];
    u8 value;
    u8 pad_a1[0x1f];
} fn_1_12ECA8_FnEntry;

extern fn_1_12ECA8_FnEntry *fn_1_12F118(void);
extern fn_1_12ECA8_FnEntry *fn_1_36AD0(void);

#pragma opt_common_subs off
static inline s16 fn_1_12ECA8_lookup(s16 arg) {
    fn_1_12ECA8_FnEntry *table;
    s16 i;

    if (arg < 0x29) {
        return arg;
    }

    table = fn_1_12F118();
    if (table == 0) {
        return 6;
    }

    if (table != fn_1_36AD0()) {
        for (i = 0; i < 9; i++) {
            if (table[i].id == arg) {
                return table[i].value;
            }
        }
    } else if (arg >= 0x32 && arg <= 0x35) {
        return table[arg - 0x32].value;
    } else if (arg >= 0x36 && arg <= 0x39) {
        return table[arg - 0x36].value;
    } else {
        for (i = 0; i < 4; i++) {
            if (table[i].id == arg) {
                return table[i].value;
            }
        }
    }

    return 6;
}
#pragma opt_common_subs reset


static inline s16 fn_1_12ECA8_map(s16 arg) {
    switch (fn_1_12ECA8_lookup(arg)) {
    case 0x15:
        return 1;
    case 0x21:
        return 2;
    }

    return 0;
}

#pragma opt_common_subs on
void fn_1_12ECA8(s16 arg0, s16 arg1, void *arg2, void *arg3, void *arg4) {
    struct { void * value; } scan;
    s16 index;
    void *table;
    s16 count;
    void *p;
    s32 tmp_ra1;

    table = &lbl_1_data_40BB8;

    tmp_ra1 = lbl_1_bss_8B3A0.unk_94;

    if ((tmp_ra1 & 0x80000000) == 0) {
        fn_1_934CC(arg2, (u8 *)arg2 + 0x148, table);
        index = arg1;
        p = *(void **)((u8 *)arg2 + 0x150);
        *(u16 *)((u8 *)p + 0x40) |= 1;
        count = 0;
        { void * __reg_value_scan = arg3; scan.value = __reg_value_scan; }
        while (count < fn_1_12ECA8_map(index)) {
            fn_1_934CC(scan.value, (u8 *)scan.value + 0x148, table);
            p = *(void **)((u8 *)scan.value + 0x150);
            { void * __reg_value_scan = ((0x4e0) + ((u8 *)scan.value)); scan.value = __reg_value_scan; }
            count++;
            *(u16 *)((u8 *)p + 0x40) |= 1;
        }
    }

    p = (u8 *)lbl_1_bss_8B5CC + ((s32)(s16)arg0 << 3);
    *(void **)p = arg2;
    *(void **)((u8 *)p + 4) = arg3;
    *(void **)((u8 *)arg4 + 0xc) = (void *)fn_1_12E424;
    *(void **)((u8 *)arg4 + 0x10) = arg2;
    *(void **)((u8 *)arg4 + 0x14) = (void *)fn_1_12E468;
    *(void **)((u8 *)arg4 + 0x18) = p;
    *(u8 *)((u8 *)arg4 + 8) = 1;
    *(u32 *)((u8 *)arg4 + 4) = 0;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_12ECA8 */

/* fzgx:begin fn_1_12EF24 */
struct Table {
    s16 values[66];
};

s16 fn_1_12EF24(s16 row, s16 column) {
    struct Table table = lbl_1_rodata_8230;
    return *(s16 *)((u8 *)table.values + row * 12 + column * 2);
}
/* fzgx:end fn_1_12EF24 */

/* fzgx:begin fn_1_12F028 */
typedef struct {
    s16 values[6];
} Entry;

typedef struct {
    Entry entries[11];
} EntryTable;

extern EntryTable lbl_1_rodata_8338;

s16 fn_1_12F028(s16 value) {
    EntryTable table;
    s16 count;
    s16 i;

    table = lbl_1_rodata_8338;
    count = 0;
    if (value == 5) {
        i = 0;
        while (i < 6) {
            if (fn_1_F89E4((u8)i) != 0) {
                count++;
            }
            i++;
        }
    } else {
        i = 0;
        while (i < 6) {
            if (table.entries[value].values[i] != -1) {
                count++;
            }
            i++;
        }
    }
    return count;
}
/* fzgx:end fn_1_12F028 */

/* fzgx:begin fn_1_12F10C */
void fn_1_12F10C(u32 value) {
    lbl_1_bss_8B5EC = value;
}
/* fzgx:end fn_1_12F10C */

/* fzgx:begin fn_1_12F118 */
u32 fn_1_12F118(void) {
    return lbl_1_bss_8B5EC;
}
/* fzgx:end fn_1_12F118 */

/* fzgx:begin fn_1_12F128 */
// Stores the current global value in the indexed archive slot.
void fn_1_12F128(s16 index) {
    (&lbl_1_bss_8B3A0.unk_E0)[index] = lbl_801A66A0;
}
/* fzgx:end fn_1_12F128 */

/* fzgx:begin fn_1_12F150 */
// Store the timestamp and two values for one archive entry.
void fn_1_12F150(s16 index, u32 value_100, u32 value_110) {
    (&lbl_1_bss_8B3A0.unk_F0)[index] = lbl_801A66A0;
    (&lbl_1_bss_8B3A0.unk_100)[index] = value_100;
    (&lbl_1_bss_8B3A0.unk_110)[index] = value_110;
}
/* fzgx:end fn_1_12F150 */

/* fzgx:begin fn_1_12F17C */
void fn_1_12F17C(void) {
    lbl_1_bss_8B3A0.unk_120 = lbl_801A66A0;
}
/* fzgx:end fn_1_12F17C */

/* fzgx:begin fn_1_12F194 */
// Reset the archived state counters and values.
void fn_1_12F194(void) {
    lbl_1_bss_8B3A0.unk_120 = 0;
    lbl_1_bss_8B3A0.unk_F0 = 0;
    lbl_1_bss_8B3A0.unk_100 = 0;
    lbl_1_bss_8B3A0.unk_110 = 0;
    lbl_1_bss_8B3A0.unk_E0 = 0;
    lbl_1_bss_8B3A0.unk_F4 = 0;
    lbl_1_bss_8B3A0.unk_104 = 0;
    lbl_1_bss_8B3A0.unk_114 = 0;
    lbl_1_bss_8B3A0.unk_E4 = 0;
    lbl_1_bss_8B3A0.unk_F8 = 0;
    lbl_1_bss_8B3A0.unk_108 = 0;
    lbl_1_bss_8B3A0.unk_118 = 0;
    lbl_1_bss_8B3A0.unk_E8 = 0;
    lbl_1_bss_8B3A0.unk_FC = 0;
    lbl_1_bss_8B3A0.unk_10C = 0;
    lbl_1_bss_8B3A0.unk_11C = 0;
    lbl_1_bss_8B3A0.unk_EC = 0;
}
/* fzgx:end fn_1_12F194 */

/* fzgx:begin fn_1_12F1E8 */
typedef struct {
    u8 pad_0[0x94];
    u32 unk_94;
    u8 pad_98[0x8C];
    s32 unk_124;
    u8 unk_128;
} FnState;

void fn_1_12F1E8(s32 value) {
    if ((lbl_1_bss_8B3A0.unk_94 & 0x40000000) == 0) {
        return;
    }

    if (value == 0) {
        lbl_1_bss_8B3A0.unk_124 = -1;
    } else {
        lbl_1_bss_8B3A0.unk_124 = value;
    }
    lbl_1_bss_8B3A0.unk_128 = 0;
}
/* fzgx:end fn_1_12F1E8 */

/* fzgx:begin fn_1_12F228 */
u32 fn_1_12F228(void) {
    if ((lbl_1_bss_8B3A0.unk_94 & 0x40000000) == 0) {
        return 0;
    }
    return lbl_1_bss_8B3A0.unk_124 == -1;
}
/* fzgx:end fn_1_12F228 */

/* fzgx:begin fn_1_12F258 */
s32 fn_1_12F258(void) {
    s32 value = lbl_1_bss_8B3A0.unk_124;

    if ((lbl_1_bss_8B3A0.unk_94 & 0x40000000) == 0) {
        return -1;
    }
    if (value < 0) {
        return -1;
    }
    return value;
}
/* fzgx:end fn_1_12F258 */

/* fzgx:begin fn_1_12F28C */
void fn_1_12F28C(void *arg0, void **result, void *arg2, u8 *arg3) {
    fn_1_7B2E8(*arg3);
    fn_1_435C(arg0);
    *result = fn_1_3F8C(lbl_1_data_40BC0, fn_1_13C1A0, arg3, arg2);
}
/* fzgx:end fn_1_12F28C */

/* fzgx:begin fn_1_12F308 */
// fn_1_12F308: empty in retail (single blr).
void fn_1_12F308(void) {
}
/* fzgx:end fn_1_12F308 */

/* fzgx:begin fn_1_12F30C */
typedef struct Fn1_12F30CState {
    s32 value;
} Fn1_12F30CState;

extern void fn_1_435C(void *arg0, Fn1_12F30CState *state);

// Resets the active archive entry before advancing archive processing.
void fn_1_12F30C(void *arg0, Fn1_12F30CState *state) {
    if (state->value != -1) {
        fn_1_435C(arg0, state);
        fn_1_426C(state->value);
        state->value = -1;
    }
    fn_1_7B4C0();
}
/* fzgx:end fn_1_12F30C */

/* fzgx:begin fn_1_12F358 */
extern u8 lbl_1_data_2B0D4[112];
extern u8 fn_1_F8CF0(s32);
extern void fn_1_A2D84(u32);

struct fn_1_12F358_state {
    u8 pad_0[0x9E];
    u8 unk_9E;
    u8 tail_9F[0xAD];
};
struct fn_1_12F358_entry {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[0xA];
};


u32 fzgx_obj_lbl_1_bss_8B2E0[48];
struct fn_1_12F358_state fzgx_obj_lbl_1_bss_8B3A0;
u32 fzgx_obj_lbl_1_bss_8B4EC[32];
u32 fzgx_obj_lbl_1_bss_8B56C[24];
u32 fzgx_obj_lbl_1_bss_8B5CC[8];
u32 fzgx_obj_lbl_1_bss_8B5EC;
u8 fzgx_obj_lbl_1_bss_8B5F0;
u8 fzgx_obj_lbl_1_bss_8B5F1;
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void prime_native_selection_bss(void) {
    void *volatile sink; /* Native BSS object order for the measured shared section base. */
    sink = &fzgx_obj_lbl_1_bss_8B2E0;
    sink = &fzgx_obj_lbl_1_bss_8B3A0;
    sink = &fzgx_obj_lbl_1_bss_8B4EC;
    sink = &fzgx_obj_lbl_1_bss_8B56C;
    sink = &fzgx_obj_lbl_1_bss_8B5CC;
    sink = &fzgx_obj_lbl_1_bss_8B5EC;
    sink = &fzgx_obj_lbl_1_bss_8B5F0;
    sink = &fzgx_obj_lbl_1_bss_8B5F1;
}
#pragma section code_type ".text"
#pragma opt_propagation off
#pragma opt_strength_reduction off
static inline u32 fn_1_12F358_flags(struct fn_1_12F358_state *state) {
    struct fn_1_12F358_entry *inputs = (void *)&lbl_1_bss_9F8;
    u32 index = state->unk_9E;
    return (inputs[index].unk_8 >> 4) & 1;
}

#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_strength_reduction on
#pragma opt_common_subs off
void fn_1_12F358(u16 arg0) {
    u8 *selection_types;
    s32 v0;
    s32 lab_t0;
    v0 = (s16)arg0;
    selection_types = lbl_1_data_2B0D4;
    if ((selection_types[v0] == 1 || selection_types[v0] == 17) && fn_1_F8CF0(0)) {
        if (fn_1_12F358_flags(&fzgx_obj_lbl_1_bss_8B3A0)) {
            if ((fzgx_obj_lbl_1_bss_8B5F0 = (fzgx_obj_lbl_1_bss_8B5F0 != 1))) {
                lab_t0 = 0xA9010100;
                fn_1_A2D84(lab_t0);
            } else {
                lab_t0 = 0xA9010000;
                fn_1_A2D84(lab_t0);
            }
        }
    } else {
        fzgx_obj_lbl_1_bss_8B5F0 = 0;
    }
    if (selection_types[v0] == 4 && fn_1_F8CF0(1)) {
        if (fn_1_12F358_flags(&fzgx_obj_lbl_1_bss_8B3A0)) {
            if ((fzgx_obj_lbl_1_bss_8B5F1 = (fzgx_obj_lbl_1_bss_8B5F1 != 1))) {
                lab_t0 = 0xA9010100;
                fn_1_A2D84(lab_t0);
            } else {
                lab_t0 = 0xA9010000;
                fn_1_A2D84(lab_t0);
            }
        }
    } else {
        fzgx_obj_lbl_1_bss_8B5F1 = 0;
    }
    return;
}
#pragma opt_common_subs reset

#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_1_12F358 */

/* fzgx:begin fn_1_130B8C */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.0f;
    s = 0.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = 0.30000001192092896f;
    s = -0.41999998688697815f;
    s = 0.8399999737739563f;
    s = -0.22499999403953552f;
    s = 0.15000000596046448f;
    s = 0.3499999940395355f;
    s = 0.023148147389292717f;
    s = -0.10000000149011612f;
    s = 2.0f;
    s = 9.999999747378752e-06f;
    s = 10.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 50.0f;
    s = 3000.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.15000000596046448;
    s = 20.0f;
    s = 5.0f;
    s = 0.800000011920929f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
    s = 600.0f;
    s = 0.6000000238418579f;
    s = 1.2999999523162842f;
    s = -0.47999998927116394f;
    s = 0.47999998927116394f;
    s = 1.5f;
    s = 1.75f;
    s = 1.2000000476837158f;
    d = 1.3;
    s = 0.01666666753590107f;
    s = -0.125f;
    s = 0.125f;
    s = 0.10000000149011612f;
    s = 2.5f;
    s = -0.44999998807907104f;
    s = 0.44999998807907104f;
    s = 100.0f;
    s = -0.05000000074505806f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 500.0f;
    d = 10.0;
    s = -0.4000000059604645f;
    s = 0.4000000059604645f;
    s = 120.0f;
    s = 40.0f;
    d = 1000.0;
    s = -0.3799999952316284f;
    s = 0.7599999904632568f;
    d = 0.3499999940395355;
    s = 0.25f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0;
    d = 0.02;
    d = 1.0099999904632568;
    d = 1.0199999809265137;
    s = 1.0499999523162842f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0299999713897705;
    d = 50.0;
    d = 25.0;
    d = 1.100000023841858;
    d = 0.05;
    s = -2.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    d = 4503601774854144.0;
    s = -1.0f;
    s = 2048.0f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

struct fn_1_130B8C_p0 {
    u32 unk_0;
    f32 unk_4;
    u32 unk_8;
    u32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u32 unk_18;
    f32 unk_1C;
};

struct fn_1_130B8C_p1 {
    u8 unk_0[0x68];
    f32 unk_68;
    u8 unk_6C[0x98];
    u16 unk_104;
    u8 unk_106[2];
    f32 unk_108;
};

void fn_1_130B8C(struct fn_1_130B8C_p0 *p0, struct fn_1_130B8C_p1 *p1) {
    f32 v;
    struct { f32 value; } c;
    u16 t;

    p0->unk_14 = 10.0f * (p0->unk_1C - p1->unk_108 / p1->unk_68);
    v = p0->unk_14;
    if (v < -1.0f) {
        c.value = -1.0f;
    } else if (v > 1.0f) {
        c.value = 1.0f;
    } else {
        c.value = v;
    }
    p0->unk_14 = c.value;
    t = p1->unk_104;
    if (t <= 0x8000) {
        v = (f32)t / 2048.0f;
    } else if (t > 0x8000) {
        v = -(f32)(0x10000 - t) / 2048.0f;
    } else {
        v = 0.0f;
    }
    if ((p0->unk_0 >> 1) & 1) {
        p0->unk_4 = p0->unk_4 + (f32)(0.2f * (v - p0->unk_4));
    } else {
        p0->unk_4 = v;
    }
}
/* fzgx:end fn_1_130B8C */

/* fzgx:begin fn_1_130C84 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.0f;
    s = 0.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = 0.30000001192092896f;
    s = -0.41999998688697815f;
    s = 0.8399999737739563f;
    s = -0.22499999403953552f;
    s = 0.15000000596046448f;
    s = 0.3499999940395355f;
    s = 0.023148147389292717f;
    s = -0.10000000149011612f;
    s = 2.0f;
    s = 9.999999747378752e-06f;
    s = 10.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 50.0f;
    s = 3000.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.15000000596046448;
    s = 20.0f;
    s = 5.0f;
    s = 0.800000011920929f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
    s = 600.0f;
    s = 0.6000000238418579f;
    s = 1.2999999523162842f;
    s = -0.47999998927116394f;
    s = 0.47999998927116394f;
    s = 1.5f;
    s = 1.75f;
    s = 1.2000000476837158f;
    d = 1.3;
    s = 0.01666666753590107f;
    s = -0.125f;
    s = 0.125f;
    s = 0.10000000149011612f;
    s = 2.5f;
    s = -0.44999998807907104f;
    s = 0.44999998807907104f;
    s = 100.0f;
    s = -0.05000000074505806f;
    s = 800.0f;
    s = 0.949999988079071f;
    s = 500.0f;
    d = 10.0;
    s = -0.4000000059604645f;
    s = 0.4000000059604645f;
    s = 120.0f;
    s = 40.0f;
    d = 1000.0;
    s = -0.3799999952316284f;
    s = 0.7599999904632568f;
    d = 0.3499999940395355;
    s = 0.25f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0;
    d = 0.02;
    d = 1.0099999904632568;
    d = 1.0199999809265137;
    s = 1.0499999523162842f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0299999713897705;
    d = 50.0;
    d = 25.0;
    d = 1.100000023841858;
    d = 0.05;
    s = -2.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    d = 4503601774854144.0;
    s = -1.0f;
    s = 2048.0f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 4.0f;
    s = 3.0f;
    s = 0.5199999809265137f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"
struct State {
 u32 flags; f32 steering; u8 pad8[4]; f32 c; f32 d; f32 e; u8 pad18[4]; f32 offset; u8 pad20[0x12]; u8 mode;
};
struct Racer {
 u8 pad0[0x68]; f32 speed; u8 pad6c[0x18]; f32 scale; u8 pad88[0x70]; f32 pos; u8 padfc[8]; u16 angle; u8 pad106[2]; f32 velocity;
};
struct Object {
 u8 pad0[4]; s16 id; u8 pad6[0xd6]; f32 dc; u8 pade0[0x3a4]; struct State *state;
};
extern void *fn_1_8627C(s32);
#pragma opt_propagation on
void fn_1_130C84(struct Object *obj) {
    f32 fzgx_live_;
    f32 fzgx_live;
 struct Racer *racer;
 u16 raw;
 struct State *state;
 f32 offset;
 f32 angle;
 struct Racer *player;
 racer = fn_1_8627C(obj->id);
 player = fn_1_8627C(0);
 state = obj->state;
 state->offset = 0.0f;
 switch (state->mode) {
 case 0x22: offset = 0.0f; break;
 case 0x23: offset = 4.0f / racer->scale; break;
 case 0x24: { f32 value = 4.0f; offset = -value / racer->scale; } break;
 }
 state->offset += offset;
 state->d = 0.0f;
 state->c = 0.5f;
 obj->dc = 0.0f;
 switch (state->mode) {
 case 0x23:
 case 0x24:
 fzgx_live = player->pos - 3.0f - racer->pos;
 { f32 factor = 0.25f; state->c = fzgx_live * factor; }
 if (state->c > 0.52f) state->c = 0.52f;
 if (state->c < 0.45f) state->c = 0.45f;
 break;
 }
 if (state->c > 1.3) state->c = 1.3f;
 else if (state->c < 0.0f) {
 state->c = 0.0f;
 state->d = 100.0f * -state->c;
 }
 fzgx_live_ = racer->velocity;
 state->e = 10.0f * (state->offset - fzgx_live_ / racer->speed);
 state->e = state->e < -1.0f ? -1.0f : state->e > 1.0f ? 1.0f : state->e;
 raw = racer->angle;
 if (raw <= 0x8000) angle = (f32)raw / 2048.0f;
 else if (raw > 0x8000) angle = -(f32)(0x10000 - (s32)raw) / 2048.0f;
 else angle = 0.0f;
 if (((1) & ((state->flags >> 1)))) state->steering = state->steering + (f32)(0.2f * (angle - state->steering));
 else state->steering = angle;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_130C84 */

/* fzgx:begin fn_1_130EE8 noprologue */
#include "types.h"

struct fn_1_130EE8_lbl_1_bss_8CA40 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
};

extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern struct fn_1_130EE8_lbl_1_bss_8CA40 lbl_1_bss_8CA40;
extern u32 fn_1_435C(u32);
extern u32 lbl_1_data_40E7C;
extern u32 lbl_1_data_40E90;
extern void fn_1_130F98(void);
extern void fn_1_131000(void);

void fn_1_130EE8(u32 arg0, u32 arg1) {
    struct fn_1_130EE8_lbl_1_bss_8CA40 *p_lbl_1_bss_8CA40;
    u32 t1, t3;
    p_lbl_1_bss_8CA40 = (struct fn_1_130EE8_lbl_1_bss_8CA40 *)&lbl_1_bss_8CA40;
    p_lbl_1_bss_8CA40->unk_0 = -1;
    p_lbl_1_bss_8CA40->unk_4 = -1;
    p_lbl_1_bss_8CA40->unk_8 = -1;
    p_lbl_1_bss_8CA40->unk_C = 0;
    p_lbl_1_bss_8CA40->unk_10 = 0;
    p_lbl_1_bss_8CA40->unk_14 = 0;
    p_lbl_1_bss_8CA40->unk_18 = 0;
    p_lbl_1_bss_8CA40->unk_1C = arg0;
    p_lbl_1_bss_8CA40->unk_20 = arg1;
    fn_1_435C(arg0);
    t1 = fn_1_3F8C((u32)&lbl_1_data_40E7C, (u32)fn_1_130F98, 0, 8);
    p_lbl_1_bss_8CA40->unk_24 = t1;
    fn_1_435C(arg1);
    t3 = fn_1_3F8C((u32)&lbl_1_data_40E90, (u32)fn_1_131000, 0, 8);
    p_lbl_1_bss_8CA40->unk_28 = t3;
}
/* fzgx:end fn_1_130EE8 */

/* fzgx:begin fn_1_130F98 */
// Promote a pending archive operation, then invoke its selected handler.
void fn_1_130F98(void) {
    if (lbl_1_bss_8CA44[0] >= 0) {
        s32 pending_operation = lbl_1_bss_8CA44[0];

        lbl_1_bss_8CA44[0] = -1;
        lbl_1_bss_8CA40 = pending_operation;
    }

    {
        s32 operation = lbl_1_bss_8CA40;

        if (operation >= 0) {
            ((void (**)(void))lbl_1_data_40D50)[operation]();
        }
    }
}
/* fzgx:end fn_1_130F98 */

/* fzgx:begin fn_1_131000 */
// fn_1_131000: empty in retail (single blr).
void fn_1_131000(void) {
}
/* fzgx:end fn_1_131000 */

/* fzgx:begin fn_1_131004 */
struct Fn131004State {
    u8 pad_00[0x1C];
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
};

void fn_1_131004(void) {
    struct Fn131004State *state = (struct Fn131004State *)&lbl_1_bss_8CA40;

    fn_1_435C(state->unk_1C);
    fn_1_426C(state->unk_24);
    fn_1_435C(state->unk_20);
    fn_1_426C(state->unk_28);
}
/* fzgx:end fn_1_131004 */

/* fzgx:begin fn_1_131050 */
void fn_1_131050(u32 value, u32 state) {
    u32* data = &lbl_1_bss_8CA40;
    s32 previous;

    if (value == 0) {
        return;
    }

    previous = *(s32*)data;
    data[3] = value;
    data[2] = state;
    data[11] = state;

    if (previous == -1) {
        data[1] = 2;
    }
}
/* fzgx:end fn_1_131050 */

/* fzgx:begin fn_1_131084 */
#include "types.h"

struct fn_1_131084_lbl_1_bss_8CA40 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x4];
    u32 unk_10;
    u8 pad_14[0x18];
    u32 unk_2C;
};



void fn_1_131084(u32 arg0, u32 arg1) {
    struct fn_1_131084_lbl_1_bss_8CA40 *p_lbl_1_bss_8CA40;
    p_lbl_1_bss_8CA40 = (struct fn_1_131084_lbl_1_bss_8CA40 *)&(*(struct fn_1_131084_lbl_1_bss_8CA40 *)&lbl_1_bss_8CA40);
    if (arg0 == 0) { return; }
{
    u32 v0;
    v0 = p_lbl_1_bss_8CA40->unk_0;
    p_lbl_1_bss_8CA40->unk_10 = arg0;
    p_lbl_1_bss_8CA40->unk_8 = arg1;
    p_lbl_1_bss_8CA40->unk_2C = arg1;
    if ((s32)v0 != -1) { return; }
}
    p_lbl_1_bss_8CA40->unk_4 = 4;
}
/* fzgx:end fn_1_131084 */

/* fzgx:begin fn_1_1310B8 */
#include "types.h"

struct State {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x20];
    u32 unk_2C;
};



#pragma peephole off
void fn_1_1310B8(void) {
    struct State *state;
    u32 status;

    state = &(*(struct State *)&lbl_1_bss_8CA40);
    status = state->unk_0;
    if ((s32)status != -1) {
        return;
    }
    state->unk_4 = 0;
    state->unk_8 = 0;
    state->unk_2C = 0;
}
#pragma peephole reset
/* fzgx:end fn_1_1310B8 */

/* fzgx:begin fn_1_1310E0 */
s32 fn_1_1310E0(void) {
    return lbl_1_bss_8CA40 != -1;
}
/* fzgx:end fn_1_1310E0 */

/* fzgx:begin fn_1_1310FC */
void fn_1_1310FC(void) {
    u8* ptr = (u8*)&lbl_1_bss_8CA40;
    
    if (*(s32*)(ptr + 0x8) == -1) {
        *(u32*)(ptr + 0x0) = (u32)-1;
    } else {
        fn_1_C2454();
        *(u32*)(ptr + 0x4) = 1;
        *(u8*)(ptr + 0x30) = 0;
    }
}
/* fzgx:end fn_1_1310FC */

/* fzgx:begin fn_1_131154 */
void fn_1_131154(void) {
    if (fn_1_C24A4() == 0 && fn_1_B7C00() == 0) {
        lbl_1_bss_8CA40 = -1;
    }
}
/* fzgx:end fn_1_131154 */

/* fzgx:begin fn_1_131194 noprologue */
#include "types.h"
#include "dolphin/os/OSTime.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u32 unk_0C;
    u8 pad_10[8];
    u32 unk_18;
    u8 pad_1C[0x18];
    char unk_34[0x1C];
} MemcardState;

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
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
} CalTime;

extern MemcardState lbl_1_bss_8CA40;
extern u8 lbl_1_data_40D50[0x20];
extern u32 lbl_801A6410;

extern void OSPanic(const char *arg0, s32 arg1, const char *arg2, ...);
extern u32 fn_1_4630(u32 arg0, u32 arg1, u8 *arg2, u32 arg3);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80008BEC(void *dst, s32 value, u32 size);
extern void fn_1_AA6D8(s32 arg0, u8 arg1, void *arg2);
extern int sprintf(char *dst, const char *fmt, ...);

void fn_1_131194(void) {
    u8 *data = (u8 *)&lbl_1_data_40D50;
    MemcardState *state = (MemcardState *)&lbl_1_bss_8CA40;
    CalTime cal;
    MemcardRequest request;
    u32 buf;

    if (state->unk_0C == 0) {
        state->unk_00 = -1;
        state->unk_08 = -1;
        state->unk_0C = 0;
        OSPanic((const char *)(data + 0x154), 0xF5, (const char *)(data + 0x168));
    } else if (state->unk_08 == -1) {
        state->unk_00 = -1;
    } else {
        buf = (u32)fn_1_4630(lbl_801A6410, 0x20700, data + 0x154, 0xFF);
        state->unk_18 = buf;
        fn_80008BA8(buf, state->unk_0C, 0x20700);
        OSTicksToCalendarTime(OSGetTime(), (OSCalendarTime *)&cal);
        fn_80008BEC(&request, 0, 0x24);
        request.unk_4 = 0;
        request.unk_0 = 3;
        request.unk_C = state->unk_18;
        request.unk_8 = (u32)&state->unk_34[0];
        sprintf(&state->unk_34[0], (const char *)(data + 0x18C), cal.unk_14 % 100, cal.unk_10 + 1, cal.unk_0C, cal.unk_08, cal.unk_04);
        fn_1_AA6D8(0, (u8)state->unk_08, &request);
        state->unk_04 = 3;
    }
}
/* fzgx:end fn_1_131194 */
