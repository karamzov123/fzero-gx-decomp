#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ranking.h"

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_451C(void);
extern void fn_1_A1340(void);
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_96A;
extern void fn_1_A1360(void);
extern void fn_1_A1364(void);
extern u8 lbl_1_bss_8F420[8];
extern f32 lbl_1_rodata_D8C8[18];
extern void fn_80008BEC(void *dst, int value, int size);
extern void fn_1_1568C4(void *);
extern void fn_80008BA8(void *, void *, int);
extern void fn_1_1574E0(Obj_1_bss_8F428 *entry, u32 value);
extern void fn_8006B7B4(void *);
extern void fn_8006B870(void);
extern void fn_1_157950(void);
extern void fn_1_157FC8(void);
extern u32 fn_1_157920(void);
extern void fn_1_4060(void);
extern u32 lbl_1_bss_8F57C[3];
extern void fn_1_9AD88(void);
extern void fn_1_1594AC(int index, int flag);
extern void OSReport(const char *format, ...);
extern void fn_1_465D0(void *object, int value);
extern void fn_1_9AD54(void);

extern void fn_1_1568C4(void *entry);

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_1569E8(void *entry);
extern void fn_1_12EF80(s16 value, s16 *out_0, s16 *out_1);
extern s32 fn_1_156218(u32 arg, void *out0, void *out1, void *out2);
extern u32 lbl_1_bss_8F3FC[9];
extern void fn_1_159804(int index, Obj_1_data_4C810 *entry);
extern void fn_1_4811C(s16 value);
extern void fn_1_48004(s16 value, u32 arg);
extern u32 lbl_1_rodata_DAF8[16];
extern void fn_1_9A508(void);

/* fzgx:begin fn_1_1554D0 */
// Rebuild the ranking object when the previous one has been consumed.
void fn_1_1554D0(void) {
    Obj_1_bss_8EF20_At0 *obj = lbl_1_bss_8EF20.unk_0;

    if (obj != 0) {
        fn_1_46B4(lbl_801A6410[0], obj, lbl_1_data_49B08, 0xD50);
        lbl_1_bss_8EF20.unk_0 = 0;
    }

    if (lbl_1_bss_8EF20.unk_0 == 0) {
        lbl_1_bss_8EF20.unk_0 =
            fn_1_4630(lbl_801A6410[0], 0x230, lbl_1_data_49B08, 0xD55);
    }
}
/* fzgx:end fn_1_1554D0 */

/* fzgx:begin fn_1_15555C */
void fn_1_15555C(void) {
    Obj_1_bss_8EF20_At0 *obj = lbl_1_bss_8EF20.unk_0;
    if (obj != 0) {
        fn_1_46B4(lbl_801A6410[0], obj, lbl_1_data_49B08, 0xD63);
        lbl_1_bss_8EF20.unk_0 = 0;
    }
}
/* fzgx:end fn_1_15555C */

/* fzgx:begin fn_1_1555B0 noprologue */
#include "types.h"
#include "rel/main_rel/ranking.h"

extern void fn_1_12EF80(s16 value, s16 *out_0, s16 *out_1);
extern void fn_80008BA8(void *arg0, void *arg1, u32 size);
extern void fn_80008BEC(void *dst, u32 value, u32 size);

s32 fn_1_1555B0(s32 value) {
    u32 state = (u32)&lbl_1_bss_8EF20;
    s16 index_0;
    s16 index_1;
    u32 table;
    u32 i;
    s32 j;
    u8 *dst;

    if (*(u32 *)state == 0) {
        return 0;
    }

    *(u32 *)(state + 0x40) = value;
    fn_1_12EF80((s16)value, &index_0, &index_1);
    table = (u32)&lbl_1_bss_7F0C0 + (index_1 + index_0 * 6) * 0x180;

    for (i = 0; i < 10; i++) {
        fn_80008BA8((void *)(*(u32 *)state + i * 0x38), (void *)(table + i * 0x20 + 0xf8), 0x20);
    }

    fn_80008BEC((void *)(state + 0x48), 0, 0x230);
    dst = (u8 *)state + 0x48;

    for (j = 0; j < 10; j++, dst += 0x38) {
        fn_80008BA8(dst, (void *)(*(u32 *)state + j * 0x38), 0x38);
    }

    return 1;
}
/* fzgx:end fn_1_1555B0 */

/* fzgx:begin fn_1_1556B4 noprologue */
#include "types.h"
#include "rel/main_rel/ranking.h"

extern void fn_1_12EF80(s16 value, s16 *out_0, s16 *out_1);
extern void fn_1_3EF14(void *);
extern void fn_80008BA8(void *arg0, void *arg1, u32 size);
extern void fn_80008BEC(void *dst, u32 value, u32 size);
extern s16 *strncpy(char *, const char *, size_t);
extern size_t strlen(const char *);

typedef struct {
    u32 unk_0;
    u32 unk_4;
    char name[0x10];
    u16 unk_18;
    u8 unk_1A;
    u8 unk_1B;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
    u8 unk_20;
    u8 pad_21[7];
    f64 pad_28;
    u8 flag;
    u8 pad_31[7];
} RankEntry;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    char name[0x10];
    u16 unk_18;
    u8 unk_1A;
    u8 unk_1B;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
    u8 unk_20;
    u8 pad_21[0x17];
} RankRecord;

typedef struct {
    u32 flags;
    u8 pad_4[0x1440];
    RankRecord e;
    u8 pad_147C[0x3C];
} RankBuf;


/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
RankEntry *fzgx_obj_lbl_1_bss_8EF20;
u32 lbl_1_bss_8EF20__fzgx_offset_4[15];
u32 lbl_1_bss_8EF20__fzgx_offset_40;
u32 lbl_1_bss_8EF20__fzgx_offset_44;
RankEntry fzgx_obj_lbl_1_bss_8EF68[10];
u8 lbl_1_bss_8EF68__fzgx_offset_230[0x248];
u32 fzgx_obj_lbl_1_bss_8F3E0;
s32 lbl_1_bss_8F3E4__fzgx_offset_0;
u8 lbl_1_bss_8F3E4__fzgx_offset_4[0x14];
u32 lbl_1_bss_8F3FC[9];
u32 lbl_1_bss_8F420[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8EF20;
    s = *(u8 *)&lbl_1_bss_8EF20__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_8EF20__fzgx_offset_40;
    s = *(u8 *)&lbl_1_bss_8EF20__fzgx_offset_44;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8EF68;
    s = *(u8 *)&lbl_1_bss_8EF68__fzgx_offset_230;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8F3E0;
    s = *(u8 *)&lbl_1_bss_8F3E4__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_8F3E4__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_8F3FC;
    s = *(u8 *)&lbl_1_bss_8F420;
}
#pragma section code_type ".text"

/* fn_1_1555B0, inlined into its caller */
static inline s32 fn_1_1555B0_local(s32 value) {
    s16 index_0;
    s16 index_1;
    u32 table;
    u32 i;
    s32 j;

    if (fzgx_obj_lbl_1_bss_8EF20 == 0) {
        return 0;
    }

    lbl_1_bss_8EF20__fzgx_offset_40 = value;
    fn_1_12EF80((s16)value, &index_0, &index_1);
    table = (u32)&lbl_1_bss_7F0C0 + (index_1 + index_0 * 6) * 0x180;

    for (i = 0; i < 10; i++) {
        fn_80008BA8((void *)((u32)fzgx_obj_lbl_1_bss_8EF20 + i * 0x38), (void *)(table + i * 0x20 + 0xf8), 0x20);
    }

    fn_80008BEC(fzgx_obj_lbl_1_bss_8EF68, 0, 0x230);
    for (j = 0; j < 10; j++) {
        fn_80008BA8(&fzgx_obj_lbl_1_bss_8EF68[j], (void *)((u32)fzgx_obj_lbl_1_bss_8EF20 + j * 0x38), 0x38);
    }

    return 112;
}

static inline s32 clamp10(s32 n) {
    return n < 0 ? 0 : (n > 10 ? 10 : n);
}

#pragma opt_dead_assignments off
#pragma opt_loop_invariants off
static inline void fn_1_1556B4_loop10(s32 count, u8 arg0, RankEntry *dst) {
    s32 i;
        for (i = clamp10(count); i < 10; i++) {
            dst[i].unk_0 = 0x0633B3E7;
            dst[i].unk_4 = 0x0633B3E7;
            strncpy(dst[i].name, (char *)lbl_1_data_49B14, strlen((char *)lbl_1_data_49B14));
            dst[i].unk_18 = 0;
            if (arg0 == 0x29) {
                dst[i].unk_1A = 0x29;
            } else if (arg0 == 0x2A) {
                dst[i].unk_1A = 6;
            } else {
                dst[i].unk_1A = arg0;
            }
            dst[i].unk_1B = dst[i].unk_1A;
            dst[i].unk_1C = 0x32;
            dst[i].unk_1D = 0;
            dst[i].unk_1E = 0;
            dst[i].unk_1F = 0;
            dst[i].unk_20 = 0xFF;
        }
}

#pragma opt_common_subs off
void fn_1_1556B4(u8 arg0, u8 arg1) {
    RankEntry t;
    RankEntry tmp[10];
    RankBuf buf;
    u8 arg0_local = arg0;
    s32 i;
    RankEntry *e;
    s32 count;
    s32 front;
    s32 back;
    u32 x;
    RankEntry *list;
    u32 y;
    s32 j;
    const char * lab_t1;

    if (fzgx_obj_lbl_1_bss_8EF20 == 0) {
        return;
    }

    fn_1_1555B0_local((s32)lbl_1_bss_8EF20__fzgx_offset_40);

    e = fzgx_obj_lbl_1_bss_8EF20;
    count = 0;
    for (i = 0; i < 10; i++, e++) {
        if (arg0_local == 0x2A && e->unk_0 != 0) {
            e->flag = 1;
            count++;
        } else {
            e->flag = 0;
        }
    }

    if (arg0_local != 0x2A) {
        e = fzgx_obj_lbl_1_bss_8EF20;
        count = 0;
        for (i = 0; i < 10; i++, e++) {
            if (arg0_local == 0x29) {
                if (e->unk_1A > 0x29) {
                    e->flag = 1;
                    count++;
                }
            } else if (e->unk_1A == arg0_local && e->unk_0 != 0) {
                e->flag = 1;
                count++;
            }
        }
    }

    e = fzgx_obj_lbl_1_bss_8EF20;
    front = 0;
    back = 9;
    for (i = 0; i < 10; i++, e++) {
        if (e->flag == 1) {
            tmp[front] = *e;
            front++;
        } else {
            tmp[back] = *e;
            back--;
        }
    }
    fn_80008BA8(fzgx_obj_lbl_1_bss_8EF20, tmp, 0x230);

    list = fzgx_obj_lbl_1_bss_8EF20;
    switch (arg1) {
    case 0:
    default:
        {
            s32 i;
            s32 j;

            for (i = 0; i < count - 1; i++) {
                for (j = i + 1; j < count; j++) {
                    x = list[i].unk_0;
                    y = list[j].unk_0;
                    if (x > y || (x == 0 && y != 0)) {
                        t = list[i];
                        list[i] = list[j];
                        list[j] = t;
                    }
                }
            }
        }
        break;
    case 1:
        {
            s32 i;
            s32 j;

            for (i = 0; i < count - 1; i++) {
                for (j = i + 1; j < count; j++) {
                    x = list[i].unk_18;
                    y = list[j].unk_18;
                    if (x < y || (x == 0 && y != 0)) {
                        t = list[i];
                        list[i] = list[j];
                        list[j] = t;
                    }
                }
            }
        }
        break;
    case 2:
        {
            s32 i;
            s32 j;

            for (i = 0; i < count - 1; i++) {
                for (j = i + 1; j < count; j++) {
                    x = list[i].unk_4;
                    y = list[j].unk_4;
                    if (x > y || (x == 0 && y != 0)) {
                        t = list[i];
                        list[i] = list[j];
                        list[j] = t;
                    }
                }
            }
        }
        break;
    }

    fn_80008BEC(fzgx_obj_lbl_1_bss_8EF68, 0, 0x230);
    {
        RankEntry *list;
        for (i = 0; i < clamp10(count); i++) {
            list = fzgx_obj_lbl_1_bss_8EF20;
            fzgx_obj_lbl_1_bss_8EF68[i].unk_0 = list[i].unk_0;
            fzgx_obj_lbl_1_bss_8EF68[i].unk_4 = list[i].unk_4;
            fzgx_obj_lbl_1_bss_8EF68[i].unk_18 = list[i].unk_18;
            fzgx_obj_lbl_1_bss_8EF68[i].unk_1A = list[i].unk_1A;
            fzgx_obj_lbl_1_bss_8EF68[i].unk_1B = list[i].unk_1B;
            fzgx_obj_lbl_1_bss_8EF68[i].unk_1C = list[i].unk_1C;
            fzgx_obj_lbl_1_bss_8EF68[i].unk_1D = list[i].unk_1D;
            fzgx_obj_lbl_1_bss_8EF68[i].unk_1E = list[i].unk_1E;
            fzgx_obj_lbl_1_bss_8EF68[i].unk_1F = list[i].unk_1F;
            fzgx_obj_lbl_1_bss_8EF68[i].unk_20 = list[i].unk_20;
            strncpy(fzgx_obj_lbl_1_bss_8EF68[i].name, list[i].name, 0x10);
        }

        fn_1_1556B4_loop10(count, arg0_local, fzgx_obj_lbl_1_bss_8EF68);
    }

    fzgx_obj_lbl_1_bss_8F3E0 = 0;
    lbl_1_bss_8F3E4__fzgx_offset_0 = -1;
    fn_1_3EF14(&buf);
    if (buf.flags & 0x1000) {
        e = fzgx_obj_lbl_1_bss_8EF20;
        for (i = 9; i >= 0; i--) {
            if (buf.e.unk_0 == e[i].unk_0 && buf.e.unk_18 == e[i].unk_18 && buf.e.unk_1A == e[i].unk_1A
                && buf.e.unk_1B == e[i].unk_1B && buf.e.unk_1C == e[i].unk_1C && buf.e.unk_1D == e[i].unk_1D
                && buf.e.unk_1E == e[i].unk_1E && buf.e.unk_1F == e[i].unk_1F) {
                lbl_1_bss_8F3E4__fzgx_offset_0 = i;
                fzgx_obj_lbl_1_bss_8F3E0 = 1;
                break;
            }
        }
    }
}
#pragma opt_loop_invariants reset

#pragma opt_dead_assignments reset


#pragma opt_common_subs reset
/* fzgx:end fn_1_1556B4 */

/* fzgx:begin fn_1_155F7C */
u32 fn_1_155F7C(void) {
    return lbl_1_bss_8F3E0;
}
/* fzgx:end fn_1_155F7C */

/* fzgx:begin fn_1_155F8C */
u32 fn_1_155F8C(void) {
    return lbl_1_bss_8F3E4.unk_0;
}
/* fzgx:end fn_1_155F8C */

/* fzgx:begin fn_1_155F9C */
void fn_1_155F9C(u32 value) {
    lbl_1_bss_8F3E0 = value;
}
/* fzgx:end fn_1_155F9C */

/* fzgx:begin fn_1_155FA8 */
void fn_1_155FA8(u32 value) {
    lbl_1_bss_8F3E4.unk_0 = value;
}
/* fzgx:end fn_1_155FA8 */

/* fzgx:begin fn_1_155FB4 noprologue */
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;
typedef double f64;

typedef unsigned long size_t;

/* lbl_1_bss_8EF20: .bss size 0x48, 5 refs from ranking.c */
typedef struct {
f32 unk_0; /* 12 loads, 6 stores */
u32 unk_4; /* 2 loads, 0 stores */
f64 unk_8; /* 8 loads, 6 stores */
f64 unk_10; /* 8 loads, 6 stores */
u16 unk_18; /* 10 loads, 6 stores */
u8 unk_1A; /* 2 loads, 0 stores */
u8 pad_1B[0x5];
f64 unk_20; /* 8 loads, 6 stores */
f64 unk_28; /* 8 loads, 6 stores */
f64 unk_30; /* 9 loads, 10 stores */
u32 unk_38; /* 2 loads, 0 stores */
u8 pad_3C[0x16];
u8 unk_52; /* 2 loads, 0 stores */
u8 pad_53[0x15];
u8 unk_68; /* 0 loads, 4 stores */
u8 pad_69[0x7];
u32 unk_70; /* 1 loads, 0 stores */
u8 pad_74[0x2C];
u8 unk_A0; /* 0 loads, 2 stores */
u8 pad_A1[0x7];
u32 unk_A8; /* 1 loads, 0 stores */
u8 pad_AC[0x2C];
u8 unk_D8; /* 0 loads, 2 stores */
u8 pad_D9[0x7];
u32 unk_E0; /* 1 loads, 0 stores */
u8 pad_E4[0x2C];
u8 unk_110; /* 0 loads, 2 stores */
} Obj_1_bss_8EF20_At0;
typedef struct {
Obj_1_bss_8EF20_At0 *unk_0; /* 17 loads, 3 stores */
u8 pad_4[0x3C];
u32 unk_40; /* 1 loads, 2 stores */
u8 pad_44[0x4];
} Obj_1_bss_8EF20;

extern void fn_1_3EF14(void *);
extern char *strncpy(char *, const char *, size_t);
typedef struct {
u32 unk_0;
u8 pad_4[0x1440];
u32 unk_1444;
u8 pad_1448[0x14];
u16 unk_145C;
u8 unk_145E;
u8 unk_145F;
u8 unk_1460;
u8 unk_1461;
u8 unk_1462;
u8 unk_1463;
u8 pad_1464[0x5C];
} Rec_155FB4;
typedef struct {
u32 unk_0;
u8 pad_4[0x14];
u16 unk_18;
u8 unk_1A;
u8 pad_1B[5];
u8 pad_20[0x18];
} Entry_155FB4;
/* the record fields compared after the loop-invariant id are re-read every pass */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Entry_155FB4 *fzgx_obj_lbl_1_bss_8EF20;
u32 lbl_1_bss_8EF20__fzgx_offset_4[17];
u8 fzgx_obj_lbl_1_bss_8EF68;
u8 lbl_1_bss_8EF68__fzgx_offset_1;
u16 lbl_1_bss_8EF68__fzgx_offset_2;
u32 lbl_1_bss_8EF68__fzgx_offset_4[285];
u32 fzgx_obj_lbl_1_bss_8F3E0;
u32 lbl_1_bss_8F3E4__fzgx_offset_0;
char lbl_1_bss_8F3E4__fzgx_offset_4[0x11];
u8 lbl_1_bss_8F3E4__fzgx_offset_15;
u16 lbl_1_bss_8F3E4__fzgx_offset_16;
u32 lbl_1_bss_8F3FC[9];
u32 lbl_1_bss_8F420[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8EF20;
    s = *(u8 *)&lbl_1_bss_8EF20__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8EF68;
    s = *(u8 *)&lbl_1_bss_8EF68__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_8EF68__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_8EF68__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8F3E0;
    s = *(u8 *)&lbl_1_bss_8F3E4__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_8F3E4__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_8F3E4__fzgx_offset_15;
    s = *(u8 *)&lbl_1_bss_8F3E4__fzgx_offset_16;
    s = *(u8 *)&lbl_1_bss_8F3FC;
    s = *(u8 *)&lbl_1_bss_8F420;
}
#pragma section code_type ".text"

static inline Entry_155FB4 *fn_1_155FB4_array_read(Entry_155FB4 *array) { return array; }
#pragma opt_loop_invariants off
void fn_1_155FB4(char *arg) {
Rec_155FB4 rec;

Entry_155FB4 *a;
Entry_155FB4 *p;
s32 i;
    size_t lab_t2;
lab_t2 = 0x10;
strncpy(lbl_1_bss_8F3E4__fzgx_offset_4, arg, lab_t2);
lbl_1_bss_8F3E4__fzgx_offset_4[0x10] = 0;
fn_1_3EF14((void *)&rec);
if (rec.unk_0 & 0x1000) {
a = fzgx_obj_lbl_1_bss_8EF20;
for (i = 9; i >= 0; i--) {
/* record fields other than the loop-invariant id are re-read on every pass: retail reloads them inside the loop */
#define VRF(f) (((volatile Rec_155FB4 *)&rec)->f)
if (fn_1_155FB4_array_read(a)[i].unk_0 == rec.unk_1444 && a[i].unk_18 == VRF(unk_145C)
&& a[i].unk_1A == VRF(unk_145E) && a[i].pad_1B[0] == VRF(unk_145F)
&& a[i].pad_1B[1] == VRF(unk_1460) && a[i].pad_1B[2] == VRF(unk_1461)
&& a[i].pad_1B[3] == VRF(unk_1462) && a[i].pad_1B[4] == VRF(unk_1463) ) {
strncpy((char *)&a[i].pad_4[4], arg, 0x10);
break;
}
}
p = ((Entry_155FB4 *)((u8 *)&fzgx_obj_lbl_1_bss_8EF68)) ;
for (i = 9; i >= 0; i--) {
if (((Entry_155FB4 *)((u8 *)&fzgx_obj_lbl_1_bss_8EF68)) [i].unk_0 == rec.unk_1444 && ((Entry_155FB4 *)((u8 *)&fzgx_obj_lbl_1_bss_8EF68)) [i].unk_18 == VRF(unk_145C)
&& ((Entry_155FB4 *)((u8 *)&fzgx_obj_lbl_1_bss_8EF68)) [i].unk_1A == VRF(unk_145E)
&& ((Entry_155FB4 *)((u8 *)&fzgx_obj_lbl_1_bss_8EF68)) [i].pad_1B[0] == VRF(unk_145F)
&& ((Entry_155FB4 *)((u8 *)&fzgx_obj_lbl_1_bss_8EF68)) [i].pad_1B[1] == VRF(unk_1460)
&& ((Entry_155FB4 *)((u8 *)&fzgx_obj_lbl_1_bss_8EF68)) [i].pad_1B[2] == VRF(unk_1461)
&& ((Entry_155FB4 *)((u8 *)&fzgx_obj_lbl_1_bss_8EF68)) [i].pad_1B[3] == VRF(unk_1462)
&& ((Entry_155FB4 *)((u8 *)&fzgx_obj_lbl_1_bss_8EF68)) [i].pad_1B[4] == VRF(unk_1463) ) {
strncpy((char *)&((Entry_155FB4 *)((u8 *)&fzgx_obj_lbl_1_bss_8EF68)) [i].pad_4[4], arg, 0x10);
break;
}
}
}
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_155FB4 */

/* fzgx:begin fn_1_156198 */
u32 *fn_1_156198(u32 arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    struct { u32 a[14]; } loc_78;
    struct { u32 a[14]; } loc_40;
    struct { u32 a[14]; } loc_8;
    /* frame */
    u32 t0;
    t0 = fn_1_156218(arg0, (void *)&loc_78, (void *)&loc_40, (void *)&loc_8);
    v0 = t0;
    if ((s32)t0 == 0) {
        v0 = 0;
    } else {
        v1 = loc_78.a[2];
        v2 = loc_78.a[3];
        v3 = loc_78.a[4];
        v4 = loc_78.a[5];
        v5 = loc_78.a[6];
        v6 = loc_78.a[7];
        lbl_1_bss_8F3FC[0] = loc_78.a[0];
        lbl_1_bss_8F3FC[1] = loc_78.a[1];
        lbl_1_bss_8F3FC[2] = v1;
        lbl_1_bss_8F3FC[3] = v2;
        lbl_1_bss_8F3FC[4] = v3;
        lbl_1_bss_8F3FC[5] = v4;
        lbl_1_bss_8F3FC[6] = v5;
        lbl_1_bss_8F3FC[7] = v6;
        v0 = (u32)&lbl_1_bss_8F3FC;
    }
    return (u32 *)v0;
}
/* fzgx:end fn_1_156198 */

/* fzgx:begin fn_1_156218 noprologue */
#include "rel/main_rel/ranking.h"

extern void fn_1_12EF80(u32, void *, void *);

typedef struct {
    u32 words[8];
} RankingRecord;

typedef struct {
    u8 pad[0x18];
    u16 value;
} RankingValue;

s32 fn_1_156218(s16 id, RankingRecord *record, RankingValue *value, RankingRecord *extra)
{
    s16 row;
    s16 column;
    s32 index;
    s32 i;

    fn_1_12EF80(id, &row, &column);
    index = column + row * 6;
    for (i = 0; i < 10; i++) {
        if (*(u16 *)&((Obj_1_bss_7F0C0 *)((u8 *)&lbl_1_bss_7F0C0 + index * 0x180 + i * 0x20))->unk_110 != 0) {
            *record = *(RankingRecord *)((u8 *)&lbl_1_bss_7F0C0.unk_F8 + index * 0x180 + i * 0x20);
            *extra = *(RankingRecord *)((u8 *)&lbl_1_bss_7F0C0.unk_238 + index * 0x180);
            value->value = *(u16 *)((u8 *)&lbl_1_bss_7F0C0.unk_258 + index * 0x180);
            return 1;
        }
    }
    *record = *(RankingRecord *)((u8 *)&lbl_1_bss_7F0C0.unk_F8 + index * 0x180);
    *extra = *(RankingRecord *)((u8 *)&lbl_1_bss_7F0C0.unk_238 + index * 0x180);
    value->value = *(u16 *)((u8 *)&lbl_1_bss_7F0C0.unk_258 + index * 0x180);
    return 0;
}
/* fzgx:end fn_1_156218 */

/* fzgx:begin fn_1_1563E8 */
u16 fn_1_1563E8(u8 *data, s32 len) {
    u16 table[256];
    u32 i;
    u32 j;
    u16 crc;

    for (i = 0; i <= 0xff; i++) {
        crc = i;
        for (j = 0; j < 8; j++) {
            crc = (crc & 1) ? ((crc >> 1) ^ 0x8408) : (crc >> 1);
        }
        table[i] = crc;
    }

    crc = 0xFFFF;
    while (--len >= 0) {
        crc = (crc >> 8) ^ table[(crc & 0xff) ^ *data++];
    }

    return (crc ^ 0xFFFF) & 0xFFFF;
}
/* fzgx:end fn_1_1563E8 */

/* fzgx:begin fn_1_1564D0 */
void fn_1_1564D0(void) {
    fn_1_451C();
    fn_1_A1340();
    if (lbl_1_bss_962 != 0x7d) {
        lbl_1_bss_96A = 0x7d;
    }
}
/* fzgx:end fn_1_1564D0 */

/* fzgx:begin fn_1_156510 */
void fn_1_156510(void) {
    fn_1_A1360();
}
/* fzgx:end fn_1_156510 */

/* fzgx:begin fn_1_156530 */
// fn_1_156530: empty in retail (single blr).
void fn_1_156530(void) {
}
/* fzgx:end fn_1_156530 */

/* fzgx:begin fn_1_156534 */
void fn_1_156534(void) {
    fn_1_A1364();
}
/* fzgx:end fn_1_156534 */

/* fzgx:begin fn_1_156554 */
// fn_1_156554: empty in retail (single blr).
void fn_1_156554(void) {
}
/* fzgx:end fn_1_156554 */

/* fzgx:begin fn_1_156558 */
// fn_1_156558: empty in retail (single blr).
void fn_1_156558(void) {
}
/* fzgx:end fn_1_156558 */

/* fzgx:begin fn_1_15655C */
// fn_1_15655C: empty in retail (single blr).
void fn_1_15655C(void) {
}
/* fzgx:end fn_1_15655C */

/* fzgx:begin fn_1_156560 */
// fn_1_156560: empty in retail (single blr).
void fn_1_156560(void) {
}
/* fzgx:end fn_1_156560 */

/* fzgx:begin fn_1_156564 */
// fn_1_156564: empty in retail (single blr).
void fn_1_156564(void) {
}
/* fzgx:end fn_1_156564 */

/* fzgx:begin fn_1_156568 */
// fn_1_156568: empty in retail (single blr).
void fn_1_156568(void) {
}
/* fzgx:end fn_1_156568 */

/* fzgx:begin fn_1_15656C */
void fn_1_15656C(void) {
    lbl_1_bss_8F420[0] = 0;
}
/* fzgx:end fn_1_15656C */

/* fzgx:begin fn_1_15657C */
// fn_1_15657C: empty in retail (single blr).
void fn_1_15657C(void) {
}
/* fzgx:end fn_1_15657C */

/* fzgx:begin fn_1_156580 */
// fn_1_156580: empty in retail (single blr).
void fn_1_156580(void) {
}
/* fzgx:end fn_1_156580 */

/* fzgx:begin fn_1_156584 */
// fn_1_156584: empty in retail (single blr).
void fn_1_156584(void) {
}
/* fzgx:end fn_1_156584 */

/* fzgx:begin fn_1_156588 */
// fn_1_156588: empty in retail (single blr).
void fn_1_156588(void) {
}
/* fzgx:end fn_1_156588 */

/* fzgx:begin fn_1_15658C */
// fn_1_15658C: empty in retail (single blr).
void fn_1_15658C(void) {
}
/* fzgx:end fn_1_15658C */

/* fzgx:begin fn_1_156590 */
// fn_1_156590: empty in retail (single blr).
void fn_1_156590(void) {
}
/* fzgx:end fn_1_156590 */

/* fzgx:begin fn_1_156594 */
// fn_1_156594: empty in retail (single blr).
void fn_1_156594(void) {
}
/* fzgx:end fn_1_156594 */

/* fzgx:begin fn_1_156598 */
// fn_1_156598: empty in retail (single blr).
void fn_1_156598(void) {
}
/* fzgx:end fn_1_156598 */

/* fzgx:begin fn_1_15659C */
typedef struct {
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
    u32 unk_2C;
    u8 unk_30;
    u8 pad_31[3];
    f32 unk_34;
    u8 pad_38[0x1c];
    u32 unk_54;
    u32 unk_58;
    u32 unk_5C;
    u32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u32 unk_6C;
    u32 unk_70;
    u32 unk_74;
    u32 unk_78;
    u32 unk_7C;
    u8 unk_80;
    u8 pad_81[3];
    f32 unk_84;
    u8 pad_88[0x18];
} RankingEntry;

extern f32 lbl_1_rodata_D8C8[18];
extern void fn_80008BEC(void *dst, int value, int size);

// Clears both ranking entries to their default sentinel values.
void fn_1_15659C(void) {
    RankingEntry *obj;
    f32 value;
    int i;

    fn_80008BEC(&lbl_1_bss_8F428, 0, 0x140);
    obj = (RankingEntry *)&lbl_1_bss_8F428;
    value = lbl_1_rodata_D8C8[0];
    for (i = 0; i < 2; i++) {
        obj->unk_4 = -1;
        obj->unk_C = -1;
        obj->unk_10 = -1;
        obj->unk_14 = -1;
        obj->unk_1C = -1;
        obj->unk_20 = -1;
        obj->unk_18 = -1;
        obj->unk_8 = -1;
        obj->unk_24 = -1;
        obj->unk_28 = -1;
        obj->unk_2C = -1;
        obj->unk_34 = value;
        obj->unk_30 = 0;
        obj->unk_54 = -1;
        obj->unk_5C = -1;
        obj->unk_60 = -1;
        obj->unk_64 = -1;
        obj->unk_6C = -1;
        obj->unk_70 = -1;
        obj->unk_68 = -1;
        obj->unk_58 = -1;
        obj->unk_74 = -1;
        obj->unk_78 = -1;
        obj->unk_7C = -1;
        obj->unk_84 = value;
        obj->unk_80 = 0;
        obj++;
    }
}
/* fzgx:end fn_1_15659C */

/* fzgx:begin fn_1_15665C */
typedef Obj_1_bss_8F428 RankingEntry;

// Initializes one ranking entry and registers it with the ranking system.
void fn_1_15665C(void *owner, s32 index) {
    RankingEntry *entry;

    entry = (RankingEntry *)((u8 *)&lbl_1_bss_8F428 + index * 0x50);
    fn_80008BEC(entry, 0, 0x50);
    entry->unk_0 = 0;
    entry->unk_4 = (u32)owner;
    entry->unk_8 = -1;
    entry->unk_C = -1;
    entry->unk_10 = -1;
    entry->unk_14 = -1;
    entry->unk_1C = -1;
    entry->unk_20 = -1;
    entry->unk_18 = -1;
    entry->unk_24 = -1;
    entry->unk_28 = -1;
    entry->unk_2C = -1;
    entry->unk_34 = lbl_1_rodata_D8C8[0];
    fn_1_1568C4(entry);
}
/* fzgx:end fn_1_15665C */

/* fzgx:begin fn_1_1566F8 */
// Updates the indexed ranking entry's value through the shared ranking helper.
void fn_1_1566F8(s32 index, void *arg) {
    fn_80008BA8(&lbl_1_bss_8F428.unk_34 + index * 0x14, arg, 0x1c);
}
/* fzgx:end fn_1_1566F8 */

/* fzgx:begin fn_1_156730 */
// Clears the indexed ranking entry's status and score markers.
void fn_1_156730(s32 index) {
    u32 *entry = &lbl_1_bss_8F428.unk_0 + index * 0x14;

    entry[0] = 0;
    entry[1] = -1;
}
/* fzgx:end fn_1_156730 */

/* fzgx:begin fn_1_156754 */
// Processes the indexed ranking entry unless its status marks it as unused.
void fn_1_156754(s32 index) {
    u32 *entry = &lbl_1_bss_8F428.unk_0 + index * 0x14;

    if (entry[1] + 0x10000 != 0xffff) {
        fn_1_1569E8(entry);
        fn_1_1568C4(entry);
    }
}
/* fzgx:end fn_1_156754 */

/* fzgx:begin fn_1_1567A8 noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x2c];
    f32 unk_34;
    u8 pad_38[0x14];
    u8 unk_4c;
} Entry;

extern Entry lbl_1_bss_8F428;
extern f32 lbl_1_rodata_D8C8[18];
extern void fn_1_1569E8(Entry *);
extern void fn_1_1568C4(Entry *);
extern void fn_1_156B18(Entry *);
extern void fn_1_1569A0(Entry *);
extern void fn_1_156C08(Entry *);
extern void fn_1_156D9C(Entry *);
extern void fn_1_157070(Entry *);
extern void fn_1_156F54(Entry *);
extern void fn_1_157200(Entry *);
extern void fn_1_157358(Entry *);
extern void fn_1_1576B4(Entry *);
extern void fn_1_157598(Entry *);

void fn_1_1567A8(s32 index) {
    Entry *entry;
    u32 value;
    f32 field_value;

    entry = &lbl_1_bss_8F428 + index;
    value = entry->unk_4;
    if (entry->unk_4 + 0x10000 != 0xffff) {
        field_value = entry->unk_34;
        if (lbl_1_rodata_D8C8[0] == field_value) {
            if (entry->unk_4 + 0x10000 == 0xffff) {
                return;
            } else {
                fn_1_1569E8(entry);
                fn_1_1568C4(entry);
                return;
            }
        } else if (entry->unk_4c & 0x80) {
            fn_1_156B18(entry);
            fn_1_1568C4(entry);
        } else {
            fn_1_1569A0(entry);
            fn_1_156C08(entry);
            fn_1_156D9C(entry);
            fn_1_157070(entry);
            fn_1_156F54(entry);
            fn_1_157200(entry);
            fn_1_157358(entry);
        }
        fn_1_1576B4(entry);
        fn_1_157598(entry);
    }
}
/* fzgx:end fn_1_1567A8 */

/* fzgx:begin fn_1_156884 */
// Refreshes an entry when its ranking value is not the invalid sentinel.
void fn_1_156884(s32 index) {
    Obj_1_bss_8F428 *entry;
    u32 value;

    entry = (Obj_1_bss_8F428 *)((u8 *)&lbl_1_bss_8F428 + index * 0x50);
    value = entry->unk_4;
    if (value + 0x10000 != 0xffff) {
        fn_1_1574E0(entry, value);
    }
}
/* fzgx:end fn_1_156884 */

/* fzgx:begin fn_1_1568C4 noprologue */
#include "types.h"

typedef struct {
    u32 flags;
    u32 value;
    u32 key;
} fn_1_1568C4_RankingState;

typedef struct {
    u8 field8;
    u8 _pad9[3];
    s32 fieldC;
    s32 field10;
    u8 field14;
    u8 field15;
    u8 field16;
    u8 field17;
    u16 field18;
    u16 field1A;
    u8 _pad1C[0x14];
} fn_1_1568C4_RankingConfig;

extern s32 fn_8006B55C(u32, u32 *, fn_1_1568C4_RankingConfig *);
extern s32 fn_8006B628(u32, fn_1_1568C4_RankingConfig *);
extern s32 fn_8006B6F8(u32);

#pragma opt_propagation off
void fn_1_1568C4(fn_1_1568C4_RankingState *state) {
    u32 value;
    s32 success = 0;
    fn_1_1568C4_RankingConfig config;
    u32 key;

    key = 7;
    config.field8 = key;
    config.fieldC = -1;
    config.field10 = success;
    config.field14 = success;
    config.field15 = success;
    config.field17 = 0x55;
    config.field16 = 0x55;
    config.field1A = 0x55;
    config.field18 = 0x55;

    value = state->value;
    key = state->key;
    if (((0x10000) + (key)) == 0xffff) {
        if (fn_8006B55C(value, &state->key, &config) >= 0) {
            success = 1;
        }
    } else {
        if (fn_8006B628(key, &config) >= 0) {
            success = 1;
        }
    }

    if (success != 0 && (state->flags & 1) == 0 &&
        fn_8006B6F8(state->key) >= 0) {
        state->flags |= 1;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_1568C4 */

/* fzgx:begin fn_1_1569A0 */
typedef struct {
    u32 flags;
    u8 _pad04[4];
    void *data;
} fn_1_1569A0_State;

void fn_1_1569A0(fn_1_1569A0_State *state) {
    if (state->flags & 1) {
        fn_8006B7B4(state->data);
        state->flags &= ~1;
    }
}
/* fzgx:end fn_1_1569A0 */

/* fzgx:begin fn_1_1569E8 */
typedef struct {
    u32 flags;
    u8 _pad04[8];
    void *data0;
    void *data1;
    void *data2;
    s32 value;
    void *data3;
    void *data4;
    u8 _pad24[4];
    void *data5;
    void *data6;
} fn_1_1569E8_State;

/* Releases pending ranking resources and resets their status flags. */
void fn_1_1569E8(void *entry) {
    fn_1_1569E8_State *state = (fn_1_1569E8_State *)entry;

    if (state->flags & 4) {
        fn_8006B7B4(state->data1);
        state->flags &= ~4;
    }
    if (state->flags & 2) {
        fn_8006B7B4(state->data0);
        state->flags &= ~2;
    }
    if (state->flags & 8) {
        fn_8006B7B4(state->data2);
        state->flags &= ~8;
    }
    if (state->flags & 0x20) {
        fn_8006B7B4(state->data3);
        state->flags &= ~0x20;
    }
    if (state->flags & 0x40) {
        fn_8006B7B4(state->data4);
        state->flags &= ~0x40;
    }
    if ((u32)(state->value + 0x10000) != 0xffff) {
        fn_8006B870();
        state->value = -1;
    }
    state->flags &= ~0x10;
    if (state->flags & 0x80) {
        fn_8006B7B4(state->data5);
        state->flags &= ~0x80;
    }
    if (state->flags & 0x100) {
        fn_8006B7B4(state->data6);
        state->flags &= ~0x100;
    }
}
/* fzgx:end fn_1_1569E8 */

/* fzgx:begin fn_1_156B18 */
typedef struct {
    u32 flags;
    u8 _pad04[8];
    void *data0;
    void *data1;
    void *data2;
    s32 value;
    void *data3;
    void *data4;
} fn_1_156B18_State;

void fn_1_156B18(fn_1_156B18_State *state) {
    if (state->flags & 4) {
        fn_8006B7B4(state->data1);
        state->flags &= ~4;
    }
    if (state->flags & 2) {
        fn_8006B7B4(state->data0);
        state->flags &= ~2;
    }
    if (state->flags & 8) {
        fn_8006B7B4(state->data2);
        state->flags &= ~8;
    }
    if (state->flags & 32) {
        fn_8006B7B4(state->data3);
        state->flags &= ~32;
    }
    if (state->flags & 64) {
        fn_8006B7B4(state->data4);
        state->flags &= ~64;
    }
    if ((u32)(state->value + 0x10000) != 0xffff) {
        fn_8006B870();
        state->value = -1;
    }
    state->flags &= ~0x10;
}
/* fzgx:end fn_1_156B18 */

/* fzgx:begin fn_1_156C08 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f; s = -1.899999976158142f; s = 25.0f; s = -25.0f;
    s = 30.0f; s = 1.5f; s = 170.0f; s = 0.5f; s = 248.0f; s = 10.0f;
}
#pragma section code_type ".text"
typedef struct Sig_fn_8006B55C_Fn8006B55CFlags { u8 flag7:1; u8 flag6:1; u8 rest:6; } Sig_fn_8006B55C_Fn8006B55CFlags;
typedef struct Sig_fn_8006B55C_Fn8006B55CData {
    u8 flags_pad[4]; Sig_fn_8006B55C_Fn8006B55CFlags flags; u8 _pad0[3];
    u16 value; u8 _pad1[0x44]; u8 payload[1];
} Sig_fn_8006B55C_Fn8006B55CData;
extern f64 __fabs(f64);
extern s32 fn_8006B55C(Sig_fn_8006B55C_Fn8006B55CData *, u32 *, u8 *);
extern s32 fn_8006B628(u32, u8 *);
extern s32 fn_8006B6F8(u32);
extern f32 lbl_1_rodata_D8C8[18];
typedef struct {
    u32 flags; Sig_fn_8006B55C_Fn8006B55CData *data; u32 pad8; u32 handle;
    u8 pad10[0x28]; f32 value; f32 delta;
} Sig_fn_1_156C08_Entry;
#pragma opt_propagation off
#pragma opt_dead_assignments off
static inline f32 fn_1_156C08_read_pointer(Sig_fn_1_156C08_Entry *owner) { return owner->delta; }
void fn_1_156C08(Sig_fn_1_156C08_Entry *arg0) {
    f32 v1; f32 v3; s32 v13; s32 v13_2; f32 v7; s32 negative; u32 *ph;
    f32 *pool = lbl_1_rodata_D8C8;
    Sig_fn_8006B55C_Fn8006B55CData *data;
    u32 handle;
    struct { u8 a[36]; } loc_8;
    v1 = -1.899999976158142f;
    (void)v1; (void)v1;
    v1 = (f32)(v1 * fn_1_156C08_read_pointer(arg0));
    if (v1 > 25.0f) v1 = 25.0f;
    else if (v1 < -25.0f) v1 = -25.0f;
    v1 += arg0->value;
    negative = v1 < 0.0f;
    v7 = (f32)__fabs(v1);
    if (v7 > 30.0f) {
        v7 = (f32)(1.5f * (v7 - 30.0f)) + 30.0f;
        if (v7 > 170.0f) {
            v7 = (f32)(0.5f * (v7 - 170.0f)) + 170.0f;
            if (v7 > 248.0f) v7 = 248.0f;
        }
    }
    if (negative) v7 = -v7;
    v13 = 0;
    loc_8.a[0] = v13;
    *(u32 *)((u8 *)&loc_8 + 4) = -1;
    *(u32 *)((u8 *)&loc_8 + 8) = v13;
    *(u16 *)((u8 *)&loc_8 + 12) = (s32)v7;
    *(u16 *)((u8 *)&loc_8 + 14) = 90;
    *(u32 *)((u8 *)&loc_8 + 16) = v13;
    *(u32 *)((u8 *)&loc_8 + 20) = v13;
    loc_8.a[24] = v13;
    loc_8.a[25] = 190;
    handle = arg0->handle; data = arg0->data;
    if (handle == (u32)-1) {
        ph = &arg0->handle;
        if (fn_8006B55C(data, ph, (u8 *)&loc_8) < 0) {
        } else { v13 = 1; }
    } else {
        if (fn_8006B628(handle, (u8 *)&loc_8) < 0) {
        } else { v13 = 1; }
    }
    if (v13 != 0 && (arg0->flags & 2) == 0) {
        if (fn_8006B6F8(arg0->handle) >= 0) arg0->flags |= 2;
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_156C08 */

/* fzgx:begin fn_1_156D9C noprologue */
#include "dolphin/types.h"
#include "rel/main_rel/ranking.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.899999976158142f;
    s = 25.0f;
    s = -25.0f;
    s = 30.0f;
    s = 1.5f;
    s = 170.0f;
    s = 0.5f;
    s = 248.0f;
    s = 10.0f;
    s = 60.0f;
    s = 1.0f;
    s = 1000.0f;
    s = 0.10000000149011612f;
}
#pragma section code_type ".text"

typedef struct {
    s32 unk_00;
    u32 unk_04;
    u8 _pad_08[0x10];
    s32 unk_18;
    u8 _pad_1c[0x24];
    f32 unk_40;
    f32 unk_44;
    u8 _pad_48[4];
    u8 unk_4c;
    u8 unk_4d;
} RankSlot;

typedef struct {
    s8 unk_00;
    u8 _pad_01[3];
    u32 unk_04;
    u32 unk_08;
    u8 unk_0c;
    u8 _pad_0d;
    u16 unk_0e;
    s16 unk_10;
    s16 unk_12;
    u16 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s8 unk_20;
    s8 unk_21;
} RankEntry;

extern s32 fn_8006B55C(u32, void *, void *);
extern s32 fn_8006B628(u32, void *);
extern s32 fn_8006B6F8(u32);

#pragma opt_dead_assignments off
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_156D9C(RankSlot *slot)
{
    u32 digit;
    s32 idx;
    RankEntry entry;
    s32 ok = 0;
    u32 id;
    u32 data;

    if (slot->unk_4c & 1) {
        f32 v = 10.0f * slot->unk_44;
        if (v > 60.0f) {
            v = 60.0f;
        }
        idx = ((s32)v + 10) & 0xff;
    } else {
        f32 c = 1.0f - (slot->unk_40 / 1000.0f);
        f32 v;
        if (c < 0.1f) {
            c = 0.1f;
        }
        if ((v = 10.0f * slot->unk_44) > 60.0f) {
            v = 60.0f;
        }
        idx = (s32)((10.0f + v) * c);
    }

    digit = (u8)(*(u8 *)((u8 *)&lbl_1_data_49B20 + slot->unk_4d % 5));

    ok = 0;

    entry.unk_04 = -1;
    entry.unk_0e = 0x5a;
    entry.unk_08 = 0;
    entry.unk_0c = idx;
    entry.unk_10 = 0x3c;
    entry.unk_00 = digit;
    entry.unk_12 = 0;
    entry.unk_14 = 0;
    entry.unk_18 = 0;
    entry.unk_1c = 0;
    entry.unk_20 = 0;
    entry.unk_21 = 0;

    id = slot->unk_18;
    data = slot->unk_04;
    if (id + 0x10000 == 0xffff) {
        if (fn_8006B55C(data, &slot->unk_18, &entry) >= 0) {
            ok = 1;
        }
    } else {
        if (fn_8006B628(id, &entry) >= 0) {
            ok = 1;
        }
    }

    if (ok && !(slot->unk_00 & 0x10)) {
        if (fn_8006B6F8(slot->unk_18) >= 0) {
            slot->unk_00 |= 0x10;
        }
    }
}
#pragma opt_propagation reset

#pragma opt_common_subs reset

#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_156D9C */

/* fzgx:begin fn_1_156F54 */
typedef struct {
    u32 flags;
    u32 resource;
    u8 _pad08[0xc];
    u32 key;
    u8 _pad18[0x34];
    u8 status;
} RankingState;

typedef struct {
    u8 kind;
    u8 _pad01[3];
    u32 size;
    u32 value;
    u8 limit;
    u8 _pad0d;
    u16 span;
    u16 duration;
    u16 _pad12;
    u16 _pad14;
    u32 count;
    u32 rate;
    u8 _pad20;
    u8 _pad21;
} Request;

extern int fn_8006B55C(u32, u32 *, Request *);
extern int fn_8006B628(u32, Request *);
extern int fn_8006B6F8(u32);

static inline int OpenRequest(RankingState *state, Request *request) {
    int success = 0;
    u32 key = state->key;
    u32 resource = state->resource;

    if (key + 0x10000 == 0xffff) {
        if (fn_8006B55C(resource, &state->key, request) >= 0) {
            success = 1;
        }
    } else {
        if (fn_8006B628(key, request) >= 0) {
            success = 1;
        }
    }
    return success;
}

void fn_1_156F54(RankingState *state) {
    Request request;

    if (state->status & 8) {
        request.kind = 4;
        request.size = 0x17c;
        request.value = 0;
        request.limit = 0xa0;
        request.span = 0x5a;
        request.duration = 0x1e;
        request._pad12 = 0;
        request._pad14 = 0;
        request.count = 5;
        request.rate = 100;
        request._pad20 = 0;
        request._pad21 = 0;

        if (!(state->flags & 8)) {
            if (OpenRequest(state, &request) && !(state->flags & 8)) {
                if (fn_8006B6F8(state->key) >= 0) {
                    state->flags |= 8;
                }
            }
        } else {
            fn_8006B6F8(state->key);
        }
    }
}
/* fzgx:end fn_1_156F54 */

/* fzgx:begin fn_1_157070 */
extern f32 lbl_1_rodata_D8C8[18];
extern s32 fn_8006B55C(u32, void *, void *);
extern s32 fn_8006B628(u32, void *);
extern s32 fn_8006B6F8(u32);

typedef struct {
    u32 flags;
    u32 value04;
    u8 unk08[8];
    u32 handle10;
    u8 unk14[0x20];
    f32 value34;
    u8 unk38[0x10];
    f32 value48;
    u8 flags4c;
} State;

typedef struct {
    u8 unk0;
    u8 pad1[3];
    u32 unk4;
    u32 unk8;
    u8 unkc;
    u8 padd;
    u16 unke;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u8 pad16[2];
    u32 unk18;
    u32 unk1c;
    u8 unk20;
    u8 unk21;
} Request;

#pragma opt_common_subs off
static inline void fn_1_157070_store(u32 value, u32 *destination) { *destination = value; }
static inline f32 fn_1_157070_read_pointer(State * owner) { return owner->value34; }
#pragma opt_strength_reduction off
void fn_1_157070(State *state) {
    u8 *fzgx_value__;
    f32 fzgx_live;
    u8 fzgx_value_;
    u16 *fzgx_value;
    f32 *table = lbl_1_rodata_D8C8;
    u32 handle;
    struct { u32 value; } success;
    Request request;
    f32 amount;

    if (state->flags4c & 4) {
        fzgx_live = fn_1_157070_read_pointer(state);
        amount = -state->value48 / fzgx_live;
        amount = (amount - table[14]) / table[15];
        if (amount > table[11]) {
            amount = table[11];
        } else if (amount < table[0]) {
            amount = table[0];
        }

        success.value = 0;
        request.unk0 = 2;
        request.unk4 = (s32)(table[16] * amount) + 300;
        fn_1_157070_store(0, &(request.unk8));
        fzgx_value__ = &(request.unkc);
        *fzgx_value__ = (u8)((s32)(table[17] * amount) + 80);
        request.unke = 90;
        request.unk10 = 100;
        fzgx_value = &(request.unk12);
        *fzgx_value = 0;
        request.unk14 = 0;
        request.unk18 = 5;
        request.unk1c = 200;
        request.unk20 = 0;
        request.unk21 = 0;

        if (!(state->flags & 4)) {
            u32 h = state->handle10;
            u32 v = state->value04;

            if (h + 0x10000 == 0xffff) {
                if (fn_8006B55C(v, &state->handle10, &request) >= 0) {
                    success.value = 1;
                }
            } else {
                if (fn_8006B628(h, &request) >= 0) {
                    success.value = 1;
                }
            }
            if ((s32)success.value != 0 && !(state->flags & 4)) {
                if (fn_8006B6F8(state->handle10) >= 0) {
                    state->flags |= 4;
                }
            }
        } else {
            fn_8006B6F8(state->handle10);
        }
    }
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_157070 */

/* fzgx:begin fn_1_157200 */
extern const f32 lbl_1_rodata_D910;
extern f32 lbl_1_rodata_D914[3];

extern s32 fn_8006B55C(void *, u32 *, void *);
extern s32 fn_8006B628(u32, void *);
extern s32 fn_8006B6F8(u32);

typedef struct {
    u32 flags;
    void *arg04;
    u8 _pad08[0x14];
    u32 entry;
    u8 _pad20[0x18];
    f32 value;
    u8 _pad3c[0x10];
    u8 status;
} RankingState;

typedef struct {
    u8 kind;
    u8 _pad01[3];
    s32 value0c;
    s32 value10;
    u8 value14;
    u16 value16;
    u16 value18;
    u16 value1a;
    u16 value1c;
    s32 value20;
    s32 value24;
    u8 value28;
    u8 value29;
} RankingRequest;

static inline f32 fn_1_157200_array_read(f32 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments off
void fn_1_157200(RankingState *state) {
    if (state->status & 0x10) {
        s32 success = 0;
        RankingRequest request;

        request.kind = 5;
        request.value0c = 330;
        request.value10 = 0;
        request.value14 = 240;
        if (state->value > lbl_1_rodata_D910) {
            request.value16 = 90;
        } else if (state->value < fn_1_157200_array_read(lbl_1_rodata_D914, 0)) {
            request.value16 = 270;
        } else {
            request.value16 = success;
        }

        success = 0;
        request.value18 = 40;
        request.value1a = success;
        request.value1c = success;
        request.value20 = 2;
        request.value24 = 10;
        request.value28 = success;
        request.value29 = success;

        {
            u32 entry;
            void *arg04;
            if (!(state->flags & 0x20)) {
            entry = state->entry;
            arg04 = state->arg04;
            if ((entry + 0x10000) == 0xffff) {
                if (fn_8006B55C(arg04, &state->entry, &request) >= 0) {
                    success = 1;
                }
            } else if (fn_8006B628(entry, &request) >= 0) {
                success = 1;
            }
            if (success && !(state->flags & 0x20) &&
                fn_8006B6F8(state->entry) >= 0) {
                state->flags |= 0x20;
            }
        } else {
            fn_8006B6F8(state->entry);
        }
        }
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_157200 */

/* fzgx:begin fn_1_157358 */
extern f32 lbl_1_rodata_D8C8[18];
extern void fn_8006B7B4(void *);
extern s32 fn_8006B55C(void *, void *, void *);
extern s32 fn_8006B628(void *, void *);
extern s32 fn_8006B6F8(void *);

typedef struct {
    u32 flags;
    void *field04;
    u8 _pad08[0x18];
    void *data;
    u8 _pad24[0x0c];
    u8 value30;
    u8 _pad31[0x0f];
    f32 value40;
    u8 _pad44[8];
    u8 enabled4c;
} fn_1_157358_RankingState;

typedef struct {
    u8 type;
    u8 _pad01[3];
    s32 value04;
    s32 value08;
    u8 value0c;
    u8 _pad0d;
    s16 width;
    s16 height;
    s16 x;
    s16 y;
    s32 value18;
    s32 value1c;
    u8 value20;
    u8 value21;
} Packet;

#pragma opt_propagation off
#pragma opt_common_subs off
void fn_1_157358(fn_1_157358_RankingState *state) {
    f32 *table = lbl_1_rodata_D8C8;
    f32 value;
    Packet packet;
    s32 success;
    void *data;
    void *node;

    if (state->enabled4c & 0x20) {
        value = state->value40 / table[20];
        if (value > table[11]) {
            value = table[11];
        }
        value *= table[21];

        if (state->flags & 0x40) {
            u8 converted = (u8)(s32)value;
            if (converted == state->value30) {
                return;
            }
        }
        state->value30 = (u8)(s32)value;
    } else {
        if (!(state->flags & 0x40)) {
            return;
        }
        fn_8006B7B4(state->data);
        state->flags &= ~0x40;
        return;
    }

    success = 0;
    packet.type = 2;
    packet.value04 = -1;
    packet.value08 = success;
    packet.value0c = state->value30;
    packet.width = 0x5a;
    packet.height = 0x28;
    packet.x = success;
    packet.y = success;
    packet.value18 = success;
    packet.value1c = success;
    packet.value20 = success;
    packet.value21 = success;

    data = state->data;
    node = state->field04;
    if (data == (void *)-1) {
        if (fn_8006B55C(node, &state->data, &packet) >= 0) {
            success = 1;
        }
    } else {
        if (fn_8006B628(data, &packet) >= 0) {
            success = 1;
        }
    }
    if (success && !(state->flags & 0x40)) {
        if (fn_8006B6F8(state->data) >= 0) {
            state->flags |= 0x40;
        }
    }
}
#pragma opt_common_subs reset

#pragma opt_propagation reset
/* fzgx:end fn_1_157358 */

/* fzgx:begin fn_1_1574E0 noprologue */
#include "types.h"

extern void fn_8006B55C(void *, void *, void *);
extern void fn_8006B628(u32, void *);
extern void fn_8006B7B4(u32);
extern void fn_8006B6F8(u32);

typedef struct {
    u8 _pad00[4];
    void *owner;
    u8 _pad08[0x1c];
    u32 value;
} fn_1_1574E0_RankingState;

typedef struct {
    u8 type;
    u8 _pad01[3];
    u32 duration;
    u32 flags;
    u8 strength;
    u8 _pad0d;
    s16 angle;
    s16 value10;
    s16 value12;
    s16 value14;
    u32 value18;
    u32 value1c;
    u8 value20;
    u8 value21;
} fn_1_1574E0_RankingConfig;

void fn_1_1574E0(fn_1_1574E0_RankingState *state) {
    u32 value = state->value;

    if (value + 0x10000u == 0xffffu) {
        fn_1_1574E0_RankingConfig config;
        void *owner;

        config.type = 2;
        config.duration = 300;
        config.flags = 0;
        config.strength = 100;
        config.angle = 90;
        config.value10 = 15;
        config.value12 = 0;
        config.value14 = 0;
        config.value18 = 0;
        config.value1c = 0;
        config.value20 = 0;
        config.value21 = 0;

        owner = state->owner;
        if (value + 0x10000u == 0xffffu) {
            fn_8006B55C(owner, &state->value, &config);
        } else {
            fn_8006B628(value, &config);
        }
    } else {
        fn_8006B7B4(value);
    }

    fn_8006B6F8(state->value);
}
/* fzgx:end fn_1_1574E0 */

/* fzgx:begin fn_1_157598 */
extern s32 fn_8006B55C(void *, void *, void *);
extern s32 fn_8006B628(u32, void *);
extern s32 fn_8006B6F8(u32);

typedef struct {
    u32 flags;
    void *owner;
    u8 _pad08[0x20];
    u32 value;
    u8 _pad2c[0x20];
    u8 state;
} fn_1_157598_RankingState;

typedef struct {
    u8 type;
    u8 _pad01[3];
    u32 duration;
    u32 flags;
    u8 strength;
    u8 _pad0d;
    s16 angle;
    s16 value10;
    s16 value12;
    s16 value14;
    u32 value18;
    u32 value1c;
    u8 value20;
    u8 value21;
} fn_1_157598_RankingConfig;

#pragma opt_dead_assignments off
void fn_1_157598(fn_1_157598_RankingState *state) {
    s32 success;
    u32 value;
    void *owner;
    fn_1_157598_RankingConfig config;
    success = 0;

    if (!(state->state & 0x40)) {
        return;
    }

    success = 0;
    config.type = 4;
    config.duration = 700;
    config.flags = success;
    config.strength = 250;
    config.angle = 90;
    config.value10 = 100;
    config.value12 = success;
    config.value14 = success;
    config.value18 = 20;
    config.value1c = 200;
    config.value20 = success;
    config.value21 = success;

    if (!(((0x80) & (state->flags)))) {
        value = state->value;
        owner = state->owner;

        if (value + 0x10000u == 0xffffu) {
            if (fn_8006B55C(owner, &state->value, &config) >= 0) {
                success = 1;
            }
        } else {
            if (fn_8006B628(value, &config) >= 0) {
                success = 1;
            }
        }

        if (success) {
            if (!(((0x80) & (state->flags)))) {
                if (fn_8006B6F8(state->value) >= 0) {
                    state->flags |= 0x80;
                }
            }
        }
    } else {
        fn_8006B6F8(state->value);
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_157598 */

/* fzgx:begin fn_1_1576B4 */
extern s32 fn_8006B55C(u32, void *, void *);
extern s32 fn_8006B628(void *, void *);
extern s32 fn_8006B6F8(void *);

typedef struct {
    u8 field00;
    u8 _pad01[3];
    u32 field04;
    u32 field08;
    u8 field0c;
    u8 _pad0d[1];
    u16 field0e;
    u16 field10;
    u16 field12;
    u16 field14;
    u32 field18;
    u32 field1c;
    u8 field20;
    u8 field21;
} RankingConfig;

typedef struct {
    u32 flags;
    u32 field04;
    u8 _pad08[0x24];
    void *data;
    u8 _pad30[0x1c];
    u8 enabled;
} RankingState;

#pragma opt_propagation off
void fn_1_1576B4(RankingState *state) {
    RankingConfig config;
    u32 field04;
    void *data;
    s32 success;

    if (state->enabled & 2) {
        success = 0;
        config.field00 = 4;
        config.field04 = 0x258;
        config.field08 = success;
        config.field0c = 0xfa;
        config.field0e = 0x32;
        config.field10 = 0x96;
        config.field12 = success;
        config.field14 = success;
        config.field18 = 0x14;
        config.field1c = 0x64;
        config.field20 = success;
        config.field21 = success;

        if (!(((0x100) & (state->flags)))) {
            field04 = state->field04;
            data = state->data;
            if ((u32)data == 0xffffffffU) {
                if (fn_8006B55C(field04, &state->data, &config) >= 0) {
                    success = 1;
                }
            } else if (fn_8006B628(data, &config) >= 0) {
                success = 1;
            }

            if (success && !(((0x100) & (state->flags))) &&
                fn_8006B6F8(state->data) >= 0) {
                state->flags |= 0x100;
            }
        } else {
            fn_8006B6F8(state->data);
        }
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_1576B4 */

/* fzgx:begin fn_1_1577D0 noprologue */
#include "types.h"

extern f32 lbl_1_rodata_D920;
extern struct fn_1_1577D0_lbl_1_bss_8F568 lbl_1_bss_8F568;
extern u32 lbl_1_data_4C788;

struct fn_1_1577D0_lbl_1_bss_8F568 {
    u8 unk_0;
    u8 pad_1[0x3];
    f32 unk_4;
    f32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

f32 fn_1_1577D0(u32 arg0, u32 arg1, f32 arg2) {
    lbl_1_bss_8F568.unk_0 = arg0;
    lbl_1_bss_8F568.unk_4 = lbl_1_rodata_D920;
    lbl_1_bss_8F568.unk_8 = arg2;
    lbl_1_bss_8F568.unk_C = *(u32 *)((u8 *)&lbl_1_data_4C788 + ((s8)arg1 << 2));
    lbl_1_bss_8F568.unk_10 = 1;
    lbl_1_bss_8F568.unk_14 = 0;
    lbl_1_bss_8F568.unk_18 = 600;
    return arg2;
}
/* fzgx:end fn_1_1577D0 */

/* fzgx:begin fn_1_157820 noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x4];
    f32 unk_4;
    f32 unk_8;
    u8 pad_C[0x4];
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} Obj_1_bss_8F568;

typedef struct {
    u8 pad_0[0x9e];
    u8 unk_9e;
} Obj_1_bss_8B3A0;

typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0xa];
} Obj_1_bss_9F8;

extern Obj_1_bss_8F568 lbl_1_bss_8F568;
extern Obj_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern Obj_1_bss_9F8 lbl_1_bss_9F8[];
extern s32 fn_1_157920(void);
extern void fn_1_4060(void);

void fn_1_157820(void) {
    Obj_1_bss_8F568 *p;
    u8 index;

    p = &lbl_1_bss_8F568;

    if (p->unk_14 == 0) {
        p->unk_4 += p->unk_8;
    } else {
        if (p->unk_18 > 0) {
            p->unk_18 -= 1;
        }

        index = lbl_1_bss_8B3A0.unk_9e;
        if (((lbl_1_bss_9F8[index].unk_8 >> 8) & 1) ||
            p->unk_18 == 0) {
            p->unk_10 = 0;
        }
    }

    if (fn_1_157920() == 0) {
        fn_1_4060();
    }
}
/* fzgx:end fn_1_157820 */

/* fzgx:begin fn_1_1578C4 noprologue */
#include "types.h"

extern u32 fn_1_157920(void);
extern u32 fn_1_157950(void);
extern u32 fn_1_157FC8(void);
extern u32 fn_1_4060(void);
extern u8 lbl_1_bss_8F568;

void fn_1_1578C4(void) {
    s8 v0;
    u32 t2;
    v0 = (s8)lbl_1_bss_8F568;
    switch (v0) {
    case 0:
    fn_1_157950();
    break;
    case 1:
    fn_1_157FC8();
    }
    t2 = fn_1_157920();
    if ((s32)t2 == 0) {
    fn_1_4060();
    }
}
/* fzgx:end fn_1_1578C4 */

/* fzgx:begin fn_1_157920 */
// Return the current ranking value.
u32 fn_1_157920(void) {
    return lbl_1_bss_8F578;
}
/* fzgx:end fn_1_157920 */

/* fzgx:begin fn_1_157930 */
u32 fn_1_157930(void) {
    return lbl_1_bss_8F57C[0];
}
/* fzgx:end fn_1_157930 */

/* fzgx:begin fn_1_157940 */
void fn_1_157940(void) {
    lbl_1_bss_8F578 = 0;
}
/* fzgx:end fn_1_157940 */

/* fzgx:begin fn_1_157950 */
#include "font.h"

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_451C(void);
extern void fn_1_A1340(void);
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_96A;
extern void fn_1_A1360(void);
extern void fn_1_A1364(void);
extern u8 lbl_1_bss_8F420[8];
extern f32 lbl_1_rodata_D8C8[18];
extern void fn_80008BEC(void *dst, int value, int size);
extern void fn_1_1568C4(void *);
extern void fn_80008BA8(void *, void *, int);
extern void fn_1_1574E0(Obj_1_bss_8F428 *entry, u32 value);
extern void fn_8006B7B4(void *);
extern void fn_8006B870(void);
extern void fn_1_157950(void);
extern void fn_1_157FC8(void);
extern u32 fn_1_157920(void);
extern void fn_1_4060(void);
extern u32 lbl_1_bss_8F57C[3];
extern void fn_1_9AD88(void);
extern void fn_1_1594AC(int index, int flag);
extern void OSReport(const char *format, ...);
extern void fn_1_465D0(void *object, int value);
extern void fn_1_9AD54(void);

extern void fn_1_1568C4(void *entry);

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_1569E8(void *entry);
extern void fn_1_12EF80(s16 value, s16 *out_0, s16 *out_1);
extern s32 fn_1_156218(u32 arg, void *out0, void *out1, void *out2);
extern u32 lbl_1_bss_8F3FC[9];
extern void fn_1_159804(int index, Obj_1_data_4C810 *entry);
extern void fn_1_4811C(s16 value);
extern void fn_1_48004(s16 value, u32 arg);
extern u32 lbl_1_rodata_DAF8[16];
extern void fn_1_9A508(void);


struct fn_1_157950_Copy88 { u32 a[22]; };
struct fn_1_157950_lbl_1_rodata_D920 {
    f32 unk_0;
    f32 unk_4;
    u8 pad_8[0x28];
    f64 unk_30;
};
extern struct fn_1_157950_Copy88 lbl_1_rodata_26F8;
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
enum { FONT_DRAW_FLAGS = 3u << 30 };
extern void fn_1_5233C(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_495C8(int);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32,f32);
extern void fn_1_49514(u32*);
extern void fn_1_494DC(s16);
extern void fn_1_4965C(u8);
extern void fn_1_51678(FontDrawPacket*,u32,s16,s16,s16,s16);
extern int fn_1_4F734(FontDrawPacket*);
extern void fn_1_496FC(f32,f32);
extern void fn_1_495A0(f32);
extern void fn_1_4CF3C(const char*,f32,...);
extern void fn_1_4AE0C(const char*,...);

void fn_1_157950(void) {
    Obj_1_bss_8F568 *p_lbl_1_bss_8F568;
    f32 v0;
    Obj_1_bss_8F568_AtC *v1;
    f32 v3;
    f32 v2;
    Obj_1_bss_8F568_AtC *v4;
    f32 pos;
    f32 alpha;
    p_lbl_1_bss_8F568 = (Obj_1_bss_8F568*)&lbl_1_bss_8F568;
    v0 = p_lbl_1_bss_8F568->unk_4;
    v1 = p_lbl_1_bss_8F568->unk_C;
    v4 = v1;
    v3 = 0.0f;
    v2 = (f32)(v0 - (f32)(448.0f / p_lbl_1_bss_8F568->unk_8));
    while (*(s16 *)v4 != -2) {
        v3 += (f32)*(s16*)v4 / p_lbl_1_bss_8F568->unk_8;
        if (v3 >= v2 && v3 <= p_lbl_1_bss_8F568->unk_4) {
            pos = p_lbl_1_bss_8F568->unk_8 * (v3-v2);
            alpha = 1.0f;
            fn_1_49410();
            if (pos < v4->unk_E) alpha = pos / v4->unk_E;
            else if (pos > 448.0f-v4->unk_E) alpha = (448.0f-pos) / v4->unk_E;
            if (*(s32*)((u8*)p_lbl_1_bss_8F568+0x18) < 30)
                alpha = (f32)*(s32*)((u8*)p_lbl_1_bss_8F568+0x18) / 30.0f;
            switch (v4->unk_10) {
            case 0: {
                u32 color;
                fn_1_495B0(FONT_DRAW_FLAGS);
                fn_1_49738(fn_1_5233C);
                fn_1_49748(5.0f);
                fn_1_495C8((s8)v4->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C((f32)v4->unk_C/24.0f,(f32)v4->unk_E/24.0f);
                color = v4->unk_14; fn_1_49514(&color);
                break;
            }
            case 1: {
                u32 color;
                fn_1_494DC(5);
                fn_1_495B0(FONT_DRAW_FLAGS);
                fn_1_495C8((s8)v4->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C((f32)v4->unk_C/18.0f,(f32)v4->unk_E/18.0f);
                color = v4->unk_14; fn_1_49514(&color);
                break;
            }
            case 2: {
                u32 color;
                fn_1_495B0(FONT_DRAW_FLAGS);
                fn_1_49738(fn_1_5233C);
                fn_1_49748(3.0f);
                fn_1_495C8((s8)v4->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C((f32)v4->unk_C/24.0f,(f32)v4->unk_E/24.0f);
                color = v4->unk_14; fn_1_49514(&color);
                break;
            }
            case 6: {
                u32 color;
                fn_1_495B0(FONT_DRAW_FLAGS);
                fn_1_4965C(2);
                fn_1_49738(fn_1_5233C);
                fn_1_49748(1.0f);
                fn_1_495C8((s8)v4->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C((f32)v4->unk_C/24.0f,(f32)v4->unk_E/24.0f);
                color = v4->unk_14; fn_1_49514(&color);
                break;
            }
            case 3: {
                struct fn_1_157950_Copy88 packet = lbl_1_rodata_26F8;
                *(f32*)&packet.a[1] = v4->unk_4;
                *(f32*)&packet.a[2] = pos;
                *(f32*)&packet.a[3] = 0.1f;
                packet.a[12] = 5;
                packet.a[0] = 0x100;
                *(f32*)&packet.a[11] = alpha;
                fn_1_51678((FontDrawPacket*)&packet,0x100,0,0,120,16);
                fn_1_4F734((FontDrawPacket*)&packet);
                break;
            }
            case 4: {
                struct fn_1_157950_Copy88 packet = lbl_1_rodata_26F8;
                *(f32*)&packet.a[1] = v4->unk_4;
                *(f32*)&packet.a[2] = pos;
                *(f32*)&packet.a[3] = 0.1f;
                packet.a[12] = 5;
                packet.a[0] = 0x100;
                *(f32*)&packet.a[11] = alpha;
                fn_1_51678((FontDrawPacket*)&packet,0x100,0,18,248,16);
                fn_1_4F734((FontDrawPacket*)&packet);
                break;
            }
            case 5: {
                struct fn_1_157950_Copy88 packet = lbl_1_rodata_26F8;
                *(f32*)&packet.a[1] = v4->unk_4;
                *(f32*)&packet.a[2] = pos;
                *(f32*)&packet.a[3] = 0.1f;
                packet.a[12] = 5;
                packet.a[0] = 0x8700;
                *(f32*)&packet.a[11] = alpha;
                fn_1_4F734((FontDrawPacket*)&packet);
                break;
            }
            }
            fn_1_496FC((f32)v4->unk_4,pos);
            fn_1_495A0(alpha);
            if ((s32)v4->unk_10 != 6) fn_1_4CF3C((const char*)v4->unk_18,284.0f-v4->unk_4);
            else fn_1_4AE0C((const char*)v4->unk_18);
        }
        v4 = (Obj_1_bss_8F568_AtC*)((u8*)v4+0x1c);
    }
    if ((f32)v4->unk_2 < p_lbl_1_bss_8F568->unk_4)
        *(s32*)((u8*)p_lbl_1_bss_8F568+0x14) = 1;
}
/* fzgx:end fn_1_157950 */

/* fzgx:begin fn_1_157FC8 */
#include "font.h"

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_451C(void);
extern void fn_1_A1340(void);
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_96A;
extern void fn_1_A1360(void);
extern void fn_1_A1364(void);
extern u8 lbl_1_bss_8F420[8];
extern f32 lbl_1_rodata_D8C8[18];
extern void fn_80008BEC(void *dst, int value, int size);
extern void fn_1_1568C4(void *);
extern void fn_80008BA8(void *, void *, int);
extern void fn_1_1574E0(Obj_1_bss_8F428 *entry, u32 value);
extern void fn_8006B7B4(void *);
extern void fn_8006B870(void);
extern void fn_1_157950(void);
extern void fn_1_157FC8(void);
extern u32 fn_1_157920(void);
extern void fn_1_4060(void);
extern u32 lbl_1_bss_8F57C[3];
extern void fn_1_9AD88(void);
extern void fn_1_1594AC(int index, int flag);
extern void OSReport(const char *format, ...);
extern void fn_1_465D0(void *object, int value);
extern void fn_1_9AD54(void);

extern void fn_1_1568C4(void *entry);

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_1569E8(void *entry);
extern void fn_1_12EF80(s16 value, s16 *out_0, s16 *out_1);
extern s32 fn_1_156218(u32 arg, void *out0, void *out1, void *out2);
extern u32 lbl_1_bss_8F3FC[9];
extern void fn_1_159804(int index, Obj_1_data_4C810 *entry);
extern void fn_1_4811C(s16 value);
extern void fn_1_48004(s16 value, u32 arg);
extern u32 lbl_1_rodata_DAF8[16];
extern void fn_1_9A508(void);


struct fn_1_157FC8_Copy88 { u32 a[22]; };
extern struct fn_1_157FC8_Copy88 lbl_1_rodata_26F8;
extern void fn_1_49410(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495B0(u32);
#define FONT_DRAW_TEXT_FLAGS ((1U << 31) | (1U << 30))
extern void fn_1_5233C(void *, void *);
extern void fn_1_49738(void (*)(void *, void *));
extern void fn_1_49748(f32);
extern void fn_1_495C8(s8);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49514(u32 *);
extern void fn_1_494DC(s16);
extern void fn_1_4965C(u8);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_495A0(f32);
extern void fn_1_4A0D8(const char *);

#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_157FC8(f32 *p) {
    p[0] = 0.0f;
    p[1] = 448.0f;
    p[2] = 1.0f;
    p[3] = 30.0f;
    p[4] = 5.0f;
    p[5] = 0.5f;
    p[6] = 24.0f;
    p[7] = 18.0f;
    p[8] = 3.0f;
    p[9] = 0.1f;
    p[10] = 284.0f;
}
#pragma section code_type ".text"

void fn_1_157FC8(void) {
    Obj_1_bss_8F568 *p_lbl_1_bss_8F568;
    Obj_1_bss_8F568_AtC *v2;
    s32 v3;
    f32 v4;
    s16 x;
    s16 y;
    f32 alpha;
    s32 end;
    f32 elapsed;
    f32 remaining;
    p_lbl_1_bss_8F568 = (Obj_1_bss_8F568 *)&lbl_1_bss_8F568;
    v2 = p_lbl_1_bss_8F568->unk_C;
    while ((v3 = *(s16 *)v2->pad_0) != -2) {
        v4 = p_lbl_1_bss_8F568->unk_4;
        if ((f32)v3 <= v4 && (f32)(end = v3 + v2->unk_2) > v4) {
            x = v2->unk_4;
            y = v2->unk_6;
            alpha = 1.0f;
            elapsed = v4 - (f32)v3;
            if (elapsed <= 30.0f) {
                alpha = elapsed / 30.0f;
            }
            remaining = (f32)end - v4;
            if (remaining <= 30.0f && remaining >= 0.0f) {
                alpha = remaining / 30.0f;
            }
            do {
                fn_1_49410();
                switch (v2->unk_10) {
                case 0: {
                    u32 color;
                    fn_1_496FC((f32)x, (f32)y);
                    fn_1_495B0(FONT_DRAW_TEXT_FLAGS);
                    fn_1_49738(fn_1_5233C);
                    fn_1_49748(5.0f);
                    fn_1_495C8((s8)v2->unk_8);
                    fn_1_49590(0.5f);
                    fn_1_4955C((f32)v2->unk_C / 24.0f, (f32)v2->unk_E / 24.0f);
                    color = v2->unk_14;
                    fn_1_49514(&color);
                    break;
                }
                case 1: {
                    u32 color;
                    fn_1_494DC(5);
                    fn_1_496FC((f32)x, (f32)y);
                    fn_1_495B0(FONT_DRAW_TEXT_FLAGS);
                    fn_1_495C8((s8)v2->unk_8);
                    fn_1_49590(0.5f);
                    fn_1_4955C((f32)v2->unk_C / 18.0f, (f32)v2->unk_E / 18.0f);
                    color = v2->unk_14;
                    fn_1_49514(&color);
                    break;
                }
                case 2: {
                    u32 color;
                    fn_1_496FC((f32)x, (f32)y);
                    fn_1_495B0(FONT_DRAW_TEXT_FLAGS);
                    fn_1_49738(fn_1_5233C);
                    fn_1_49748(3.0f);
                    fn_1_495C8((s8)v2->unk_8);
                    fn_1_49590(0.5f);
                    fn_1_4955C((f32)v2->unk_C / 24.0f, (f32)v2->unk_E / 24.0f);
                    color = v2->unk_14;
                    fn_1_49514(&color);
                    break;
                }
                case 6: {
                    u32 color;
                    fn_1_496FC((f32)x, (f32)y);
                    fn_1_495B0(FONT_DRAW_TEXT_FLAGS);
                    fn_1_4965C(2);
                    fn_1_49738(fn_1_5233C);
                    fn_1_49748(1.0f);
                    fn_1_495C8((s8)v2->unk_8);
                    fn_1_49590(0.5f);
                    fn_1_4955C((f32)v2->unk_C / 24.0f, (f32)v2->unk_E / 24.0f);
                    color = v2->unk_14;
                    fn_1_49514(&color);
                    break;
                }
                case 3: {
                    struct fn_1_157FC8_Copy88 packet = lbl_1_rodata_26F8;
                    *(f32 *)&packet.a[1] = (f32)x;
                    *(f32 *)&packet.a[2] = (f32)y;
                    *(f32 *)&packet.a[3] = 0.1f;
                    packet.a[12] = 10;
                    packet.a[0] = 0x100;
                    *(f32 *)&packet.a[11] = alpha;
                    fn_1_51678((FontDrawPacket *)&packet, 0x100, 0, 0, 0x78, 0x10);
                    fn_1_4F734((FontDrawPacket *)&packet);
                    break;
                }
                case 4: {
                    struct fn_1_157FC8_Copy88 packet = lbl_1_rodata_26F8;
                    *(f32 *)&packet.a[1] = (f32)x;
                    *(f32 *)&packet.a[2] = (f32)y;
                    *(f32 *)&packet.a[3] = 0.1f;
                    packet.a[12] = 10;
                    packet.a[0] = 0x100;
                    *(f32 *)&packet.a[11] = alpha;
                    fn_1_51678((FontDrawPacket *)&packet, 0x100, 0, 0x12, 0xF8, 0x10);
                    fn_1_4F734((FontDrawPacket *)&packet);
                    break;
                }
                case 5: {
                    struct fn_1_157FC8_Copy88 packet = lbl_1_rodata_26F8;
                    *(f32 *)&packet.a[1] = (f32)x;
                    *(f32 *)&packet.a[2] = (f32)y;
                    *(f32 *)&packet.a[3] = 0.1f;
                    packet.a[12] = 10;
                    packet.a[0] = 0x8700;
                    *(f32 *)&packet.a[11] = alpha;
                    fn_1_4F734((FontDrawPacket *)&packet);
                    break;
                }
                }
                fn_1_495A0(alpha);
                fn_1_4A0D8((const char *)v2->unk_18);
                x += v2->unk_20;
                y += v2->unk_22;
                v2 = (Obj_1_bss_8F568_AtC *)((u8 *)v2 + 0x1C);
            } while (*(s16 *)v2->pad_0 == -1);
        } else {
            v2 = (Obj_1_bss_8F568_AtC *)((u8 *)v2 + 0x1C);
        }
    }
    if ((f32)v2->unk_2 < p_lbl_1_bss_8F568->unk_4) {
        *(u32 *)(p_lbl_1_bss_8F568 + 1) = 0;
    }
}
/* fzgx:end fn_1_157FC8 */

/* fzgx:begin fn_1_1586A8 */
// fn_1_1586A8: empty in retail (single blr).
void fn_1_1586A8(void) {
}
/* fzgx:end fn_1_1586A8 */

/* fzgx:begin fn_1_1586AC */
struct RankingResetVector { u32 a[3]; };
struct RankingResetRecord {
    u32 unk_0;
    u32 unk_4;
    struct RankingResetVector unk_8;
    struct RankingResetVector unk_14;
    u8 pad_20[0x1C];
};
extern u32 lbl_1_rodata_D978[3];
extern u32 lbl_1_rodata_D984[39];
extern void fn_1_9A508(void);

void fn_1_1586AC(void) {
    Obj_1_data_2A7E0_At3C *manager;
    s32 record_index;
    struct RankingResetRecord *record;
    s32 x;
    s32 y;
    s32 z;
    manager = lbl_1_data_2A7E0.unk_3C;
    manager->unk_0 = 0;
    /* The 400-record effect pool follows the 20-by-20-by-40 occupancy grid. */
    record = (struct RankingResetRecord *)((u8 *)manager + 0xFA0C);
    for (record_index = 0; record_index < 400; record_index++, record++) {
        record->unk_0 = 0;
        record->unk_8 = *(struct RankingResetVector *)lbl_1_rodata_D978;
        record->unk_14 = *(struct RankingResetVector *)lbl_1_rodata_D984;
    }
    /* Only the first 20 words of each 40-word grid row are reset by retail. */
    for (x = 0; x < 20; x++) {
        for (y = 0; y < 20; y++) {
            for (z = 0; z < 20; z++) {
                *(u32 *)((u8 *)manager + x * 3200 + y * 160 + z * 4 + 12) = 0;
            }
        }
    }
    fn_1_9A508();
}
/* fzgx:end fn_1_1586AC */

/* fzgx:begin fn_1_158980 */
// fn_1_158980: empty in retail (single blr).
void fn_1_158980(void) {
}
/* fzgx:end fn_1_158980 */

/* fzgx:begin fn_1_158984 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ranking.h"
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/ranking.h"

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_451C(void);
extern void fn_1_A1340(void);
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_96A;
extern void fn_1_A1360(void);
extern void fn_1_A1364(void);
extern u8 lbl_1_bss_8F420[8];
extern f32 lbl_1_rodata_D8C8[18];
extern void fn_80008BEC(void *dst, int value, int size);
extern void fn_1_1568C4(void *);
extern void fn_80008BA8(void *, void *, int);
extern void fn_1_1574E0(Obj_1_bss_8F428 *entry, u32 value);
extern void fn_8006B7B4(void *);
extern void fn_8006B870(void);
extern void fn_1_157950(void);
extern void fn_1_157FC8(void);
extern u32 fn_1_157920(void);
extern void fn_1_4060(void);
extern u32 lbl_1_bss_8F57C[3];
extern void fn_1_9AD88(void);
extern void fn_1_1594AC(int index, int flag);
extern void OSReport(const char *format, ...);
extern void fn_1_465D0(void *object, int value);
extern void fn_1_9AD54(void);

extern void fn_1_1568C4(void *entry);

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_1569E8(void *entry);
extern void fn_1_12EF80(s16 value, s16 *out_0, s16 *out_1);
extern s32 fn_1_156218(u32 arg, void *out0, void *out1, void *out2);
extern u32 lbl_1_bss_8F3FC[9];
extern void fn_1_159804(int index, Obj_1_data_4C810 *entry);
extern void fn_1_4811C(s16 value);
extern void fn_1_48004(s16 value, u32 arg);
extern u32 lbl_1_rodata_DAF8[16];
extern void fn_1_9A508(void);


struct fn_1_158984_Arg0 {
    u8 pad_0[0x118];
    u32 unk_118;
};
struct fn_1_158984_lbl_1_rodata_D958 {
    u8 pad_0[0x18];
    f64 unk_18;
    u8 pad_20[0x18];
    u32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f64 unk_58;
    f32 unk_60;
    f32 unk_64;
    f32 unk_68;
    u8 pad_6C[0x4];
    f64 unk_70;
};
typedef struct { f32 x, y, z; } RankingVector;
typedef struct {
    u32 flags;
    u8 pad_4[8];
    RankingVector position;
    s16 angle_x, angle_y, angle_z;
} RankingModel;
typedef struct {
    s32 active;
    s32 cooldown;
    RankingVector velocity;
    RankingVector spin;
    u8 pad_20[0x18];
    RankingModel *model;
} RankingSlot;
struct fn_1_158984_lbl_801A66A0 { u32 unk_0; };
typedef struct {
    u8 pad_0[0xD4];
    RankingVector vector;
} RankingScratch;

extern f32 lbl_8006D188(u32);
extern s16 camera_get_mode(void);
extern s32 fn_1_58C4(void);
extern struct fn_1_158984_lbl_1_rodata_D958 lbl_1_rodata_D958;
extern struct fn_1_158984_lbl_801A66A0 lbl_801A66A0;
extern RankingScratch *lbl_801A66CC;
extern u32 fn_1_5948(u32);
extern u32 fn_1_627C(u32);
extern void *fn_1_8627C(s32);
extern void fn_1_681C(u32, u32 *);
extern void fn_1_9AD54(void);
extern void fn_1_9A7A8(u32 *);

#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_head(f32 *f, f64 *d) {
    f[0] = 10.0f;
    f[1] = 100.0f;
    f[2] = 20.0f;
    f[3] = 1000.0f;
    f[4] = 2000.0f;
    f[5] = 0.0f;
    d[0] = 4503601774854144.0;
}
#pragma section code_type ".text"
const u32 fzgx_pool_table_20[6] = { 0, 0, 0, 0, 0, 0 };
const u32 fzgx_pool_table_38[1] = { 0x64646400 };
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_tail(f32 *f, f64 *d) {
    f[0] = 65536.0f;
    f[1] = 300.0f;
    f[2] = 600.0f;
    f[3] = 900.0f;
    f[4] = 256.0f;
    f[5] = 768.0f;
    f[6] = 1280.0f;
    d[0] = 0.01;
    f[7] = 800.0f;
    f[8] = 500.0f;
    f[9] = 40000.0f;
    d[1] = 4503599627370496.0;
}
#pragma section code_type ".text"

void fn_1_158984(void) {
    Obj_1_data_2A7E0_At3C *data;
    s32 count;
    s32 i;
    RankingSlot *slot;
    s32 j;
    RankingSlot *other;
    s32 collided;
    struct fn_1_158984_Arg0 *camera;
    s32 mode;
    f32 width_x, center_x, x;
    f32 width_y, center_y, y, upper_x, z;
    f32 wrap_width_y, wrap_center_y, wrap_y, wrap_upper_y;
    f32 wrap_width_z, wrap_center_z, wrap_z, wrap_upper_z;
    s32 inside_x, inside_y, inside_z;
    f32 dx, dy, dz;
    f64 damp;
    f32 spin_y, spin_z;
    u32 color;

    data = lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD54();
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        mode = (s16)camera_get_mode();
        if (mode >= 0) {
            camera = fn_1_8627C(mode);
            if (camera != 0) {
                data->unk_4 = camera->unk_118 + 1;
                break;
            }
        }
        fn_1_627C(i);
    }
    slot = (RankingSlot *)((u8 *)data + 0xFA0C);
    for (i = 0; i < (s32)data->unk_0; i++, slot++) {
        if ((s32)data->unk_4 == 2) {
            slot->spin.x = lbl_8006D188((s32)(65536.0f * (f32)(lbl_801A66A0.unk_0 % 300) / 300.0f));
            slot->spin.y = lbl_8006D188((s32)(65536.0f * (f32)(lbl_801A66A0.unk_0 % 600) / 600.0f));
            slot->spin.z = lbl_8006D188((s32)(65536.0f * (f32)(lbl_801A66A0.unk_0 % 900) / 900.0f));
            spin_y = 768.0f;
            spin_z = 1280.0f;
            slot->model->angle_x += (s32)(256.0f * slot->spin.x);
            slot->model->angle_y += (s32)(spin_y * slot->spin.y);
            slot->model->angle_z += (s32)(spin_z * slot->spin.z);
        } else {
            damp = 0.01;
            slot->model->angle_x = (s32)((f64)slot->model->angle_x + (f64)(damp * -slot->model->angle_x));
            slot->model->angle_y = (s32)((f64)slot->model->angle_y + (f64)(damp * -slot->model->angle_y));
            slot->model->angle_z = (s32)((f64)slot->model->angle_z + (f64)(damp * -slot->model->angle_z));
        }
        slot->model->flags &= 0xFEFFFFFF;
        if (slot->active != 0 && ((s32)data->unk_4 == 1 || (s32)data->unk_4 >= 3)) {
            if (slot->cooldown != 0) {
                slot->cooldown--;
            }
            psvec_add(&slot->model->position, &slot->velocity, &slot->model->position);
            fn_1_681C(0, (u32 *)&lbl_801A66CC->vector);
            width_x = 800.0f;
            x = slot->model->position.x;
            center_x = lbl_801A66CC->vector.x;
            upper_x = width_x + center_x;
            if (x > upper_x) inside_x = 0;
            else if (x < center_x - width_x) inside_x = 0;
            else inside_x = 1;
            if (inside_x) {
                width_y = 500.0f;
                y = slot->model->position.y;
                if (y > width_y + (center_y = lbl_801A66CC->vector.y)) inside_y = 0;
                else if (y < center_y - width_y) inside_y = 0;
                else inside_y = 1;
                if (inside_y) {
                    z = slot->model->position.z;
                    if (z > upper_x) inside_z = 0;
                    else if (z < lbl_801A66CC->vector.z - 800.0f) inside_z = 0;
                    else inside_z = 1;
                    /* All axes are inside the bounds; skip the wrapping block. */
                    if (inside_z) goto no_wrap;
                }
            }
            if (x > upper_x) slot->model->position.x = center_x - 800.0f;
            else if (x < center_x - 800.0f) slot->model->position.x = upper_x;
            wrap_width_y = 500.0f;
            wrap_y = slot->model->position.y;
            wrap_center_y = lbl_801A66CC->vector.y;
            wrap_upper_y = wrap_width_y + wrap_center_y;
            if (wrap_y > wrap_upper_y) slot->model->position.y = wrap_center_y - wrap_width_y;
            else if (wrap_y < wrap_center_y - wrap_width_y) slot->model->position.y = wrap_upper_y;
            wrap_width_z = 800.0f;
            wrap_z = slot->model->position.z;
            wrap_center_z = lbl_801A66CC->vector.z;
            wrap_upper_z = wrap_width_z + wrap_center_z;
            if (wrap_z > wrap_upper_z) slot->model->position.z = wrap_center_z - wrap_width_z;
            else if (wrap_z < wrap_center_z - wrap_width_z) slot->model->position.z = wrap_upper_z;
no_wrap:
            other = (RankingSlot *)(&data->unk_2724 + 0x34BA);
            collided = 0;
            for (j = 0; j < (s32)data->unk_0; j++, other++) {
                if (i != j && slot->cooldown == 0) {
                    RankingModel *model;
                    RankingModel *other_model;
                    f32 dz, dy, dx;
                    other_model = other->model;
                    model = slot->model;
                    dx = model->position.x;
                    dx -= other_model->position.x;
                    dy = model->position.y;
                    dy -= other_model->position.y;
                    dz = model->position.z;
                    dz -= other_model->position.z;
                    dx *= dx;
                    dx += dy * dy;
                    dx += dz * dz;
                    if (dx <= 40000.0f) {
                        lbl_801A66CC->vector = slot->velocity;
                        slot->velocity = other->velocity;
                        other->velocity = lbl_801A66CC->vector;
                        collided = 1;
                    }
                }
            }
            if (collided) {
                slot->active = 0;
                *(s32 *)((u8 *)data + data->unk_8 * 0x3C + 0xFA0C) = 1;
                *(s32 *)((u8 *)data + data->unk_8 * 0x3C + 0xFA10) = 60;
                data->unk_8++;
            }
        }
        if ((s32)data->unk_8 >= (s32)data->unk_0) data->unk_8 = 0;
    }
    color = fzgx_pool_table_38[0];
    fn_1_9A7A8(&color);
}
/* fzgx:end fn_1_158984 */

/* fzgx:begin fn_1_15903C */
// fn_1_15903C: empty in retail (single blr).
void fn_1_15903C(void) {
}
/* fzgx:end fn_1_15903C */

/* fzgx:begin fn_1_159040 */
void fn_1_159040(void) {
    fn_1_9AD88();
}
/* fzgx:end fn_1_159040 */

/* fzgx:begin fn_1_159060 */
// fn_1_159060: empty in retail (single blr).
void fn_1_159060(void) {
}
/* fzgx:end fn_1_159060 */

/* fzgx:begin fn_1_159064 */
// fn_1_159064: returns a constant.
int fn_1_159064(void) {
    return 0;
}
/* fzgx:end fn_1_159064 */

/* fzgx:begin fn_1_15906C */
struct RankingEffectObject {
    u8 pad_0[0xC];
    f32 x;
    f32 y;
    f32 z;
    u8 pad_18[0x24];
    u32 unk_3C;
};
struct RankingVector { f32 a[3]; };
struct RankingEffectRecord {
    s32 flag;
    s32 time;
    f32 x;
    f32 y;
    f32 z;
    u8 pad_14[12];
    struct RankingVector copy;
    s32 ix;
    s32 iy;
    s32 iz;
    struct RankingEffectObject *obj;
};
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10.0f;
    s = 100.0f;
    s = 20.0f;
    s = 1000.0f;
    s = 2000.0f;
    s = 0.0f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[7] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x64646400};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65536.0f;
    s = 300.0f;
    s = 600.0f;
    s = 900.0f;
    s = 256.0f;
    s = 768.0f;
    s = 1280.0f;
    d = 0.01;
    s = 800.0f;
    s = 500.0f;
    s = 40000.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
#pragma section code_type ".text"
/* Native initializer templates precede the random-magnitude literals in retail. */
static inline void clear_record_copy(struct RankingEffectRecord *record) {
    struct RankingVector initial = {{0,0,0}};
    record->copy = initial;
}
static inline void set_direction_x(struct RankingEffectRecord *record, f32 magnitude) {
    struct RankingVector vec = {{0,0,0}};
    vec.a[0] = magnitude;
    *(struct RankingVector *)&record->x = vec;
}
static inline void set_direction_y(struct RankingEffectRecord *record, f32 magnitude) {
    struct RankingVector vec = {{0,0,0}};
    vec.a[1] = magnitude;
    *(struct RankingVector *)&record->x = vec;
}
static inline void set_direction_z(struct RankingEffectRecord *record, f32 magnitude) {
    struct RankingVector vec = {{0,0,0}};
    vec.a[2] = magnitude;
    *(struct RankingVector *)&record->x = vec;
}
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
    d = 0.8;
    d = 0.2;
    s = 32767.0f;
    s = -1.0f;
}
#pragma section code_type ".text"



struct RankingRandomState { u32 unk_0; };
extern struct RankingRandomState lbl_801A63C0;
extern u32 lbl_1_rodata_D958[8];

static inline s32 random15(void) {
    u32 next_seed;
    next_seed = lbl_801A63C0.unk_0 * 0x676A4B6B + 0x33CB;
    lbl_801A63C0.unk_0 = next_seed;
    return (lbl_801A63C0.unk_0 >> 16) & 0x7FFF;
}
#pragma opt_strength_reduction off
s8 fn_1_15906C(u32 arg0, struct RankingEffectObject *arg1, f32 arg2) {
    f32 *z_component;
    s32 *grid_x;
    Obj_1_data_2A7E0_At3C *effects;
    struct RankingEffectRecord *record;
    f32 magnitude;
    s32 axis;
    struct RankingEffectObject *obj;
    effects = lbl_1_data_2A7E0.unk_3C;
    switch ((s32)arg0) {
    case 0:
        if (arg1 == 0) break;
        arg1->unk_3C = 0;
        record = (struct RankingEffectRecord *)((u8 *)effects + effects->unk_0 * 60 + 0xFA0C);
        record->obj = arg1;
        clear_record_copy(record);
        if ((s32)effects->unk_0 < 50) {
            record->flag = 1;
            record->time = 60;
        } else record->flag = 0;
        #pragma fp_contract off
        magnitude = (f32)(10.0 * (0.8 + (f64)((f32)random15() / 32767.0f) * 0.2));
        axis = random15() % 3;
        switch (axis) {
        case 0: {
            set_direction_x(record, magnitude);
            break;
        }
        case 1: {
            set_direction_y(record, magnitude);
            break;
        }
        case 2: {
            set_direction_z(record, magnitude);
            break;
        }
        }
        if (random15() % 2) {
            record->x *= -1.0f;
            record->y *= -1.0f;
            record->z *= -1.0f;
        }
        obj = record->obj;
        grid_x = &(record->ix);
        *grid_x = (s32)(10.0f + obj->x / 100.0f) < 0 ? 0 : (s32)(10.0f + obj->x / 100.0f) > 19 ? 19 : (s32)(10.0f + obj->x / 100.0f);
        record->iy = (s32)(10.0f + obj->y / 100.0f) < 0 ? 0 : (s32)(10.0f + obj->y / 100.0f) > 19 ? 19 : (s32)(10.0f + obj->y / 100.0f);
        record->iz = (s32)(20.0f + obj->z / 100.0f) < 0 ? 0 : (s32)(20.0f + obj->z / 100.0f) > 39 ? 39 : (s32)(20.0f + obj->z / 100.0f);
        {
            s32 ix = record->ix;
            s32 iy = record->iy;
            s32 iz = record->iz;
            obj = record->obj;
            obj->x = (f32)(100.0f * (f32)ix) - 1000.0f;
            obj->y = (f32)(100.0f * (f32)iy) - 1000.0f;
            z_component = &(obj->z);
            *z_component = (f32)(100.0f * (f32)iz) - 2000.0f;
        }
        /* The grid begins after the three-word effect-manager header. */
        {
            struct RankingGridRow { u32 cell[20][40]; };
            ((struct RankingGridRow *)((u8 *)effects + 12))[record->ix]
                .cell[record->iy][record->iz] = 1;
        }
        effects->unk_0++;
        effects->unk_8 = 50;
        break;
    default:
        break;
    }
    return 1;
}
#pragma opt_strength_reduction reset
#pragma fp_contract reset
/* fzgx:end fn_1_15906C */

/* fzgx:begin fn_1_159440 */
typedef struct {
    u8 pad_0[0x30];
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x4];
} fn_1_159440_RankingEntry;

// Preserve the current ranking entry before refreshing its state.
void fn_1_159440(int index, int flag) {
    fn_1_159440_RankingEntry *entry;

    entry = &((fn_1_159440_RankingEntry *)&lbl_1_data_4C810)[index];
    entry->unk_34 = entry->unk_30;
    fn_1_1594AC(index, flag);
}
/* fzgx:end fn_1_159440 */

/* fzgx:begin fn_1_159478 */
typedef struct {
    u8 pad[0x34];
    u32 unk_34;
    u8 tail[4];
} Entry159478;

void fn_1_159478(int index, int unused, int value) {
    ((Entry159478 *)&lbl_1_data_4C810)[index].unk_34 = value;
    fn_1_1594AC(index, unused);
}
/* fzgx:end fn_1_159478 */

/* fzgx:begin fn_1_1594AC */
void fn_1_1594AC(int index, int flag) {
    Obj_1_data_4C810 *entry;
    s16 value;
    int offset;

    // Activate the selected ranking entry and publish its referenced indices.
    entry = (Obj_1_data_4C810 *)((u8 *)&lbl_1_data_4C810 + index * 0x3c);
    if (entry->unk_2C >= 0x10) {
        OSReport((const char *)lbl_1_data_4C900);
    }

    if (flag != 0) {
        fn_1_465D0((void *)entry->unk_0, 6);
    } else {
        fn_1_465D0((void *)entry->unk_0, 5);
    }

    offset = 0;
    for (;;) {
        value = *(s16 *)((u8 *)entry->unk_4 + offset);
        if (value == -1) {
            break;
        }
        ((int *)lbl_1_bss_8F588)[value] = index;
        offset += 2;
    }

    fn_80008BEC((u8 *)entry + 8, 0, 0x20);
    entry->unk_28 = 1;
    entry->unk_2A = 0;
    entry->unk_38 = flag;
}
/* fzgx:end fn_1_1594AC */

/* fzgx:begin fn_1_159588 */
typedef struct {
    u8 pad_0[8];
    s16 values[16];
    s16 start;
    s16 end;
    u8 limit;
    u8 pad_2d[3];
    u32 unk_30;
    u32 value;
} RankEntryView;

int fn_1_159588(int arg) {
    s16 index;
    s16 count;
    int value;
    Obj_1_data_4C810 *entry;
    RankEntryView *view;
    s32 *table;

    index = (s16)((arg >> 8) & 0xffff);
    if (((s32 *)lbl_1_bss_8F588)[index] != 0) {
        entry = (Obj_1_data_4C810 *)((u8 *)&lbl_1_data_4C810 +
            ((s32 *)lbl_1_bss_8F588)[index] * 0x3c);
        view = (RankEntryView *)entry;
        count = view->start;
        count = view->end - count + 1;
        if (count < 0) {
            count = count + 0x10;
        }

        table = (s32 *)&lbl_1_data_FCD4;
        if (table[index * 10] != 0) {
            fn_1_159804(index, entry);
        } else {
            if (count >= view->limit) {
                fn_1_4811C(view->values[view->start]);
                value = view->start + 1;
                view->start = value > 0xf ? 0 : (value < 0 ? 0xf : value);
            }

            value = view->end + 1;
            view->end = value > 0xf ? 0 : (value < 0 ? 0xf : value);
            view->values[view->end] = index;
            fn_1_48004(view->values[view->end], view->value);
        }
    } else {
        return 0;
    }
    return 1;
}
/* fzgx:end fn_1_159588 */

/* fzgx:begin fn_1_1596DC noprologue */
#include "types.h"

typedef struct {
    u32 unk_0;
    u32 unk_4;
    s16 unk_8[16];
    s16 unk_28;
    s16 unk_2a;
    u8 unk_2c;
    u8 pad_2d[0xb];
    s32 unk_38;
} RankingEntry;

extern RankingEntry lbl_1_data_4C810[4];
extern u8 lbl_1_data_FCD4[];
extern int lbl_801A66B4;
extern int lbl_1_bss_8F588[];

extern void fn_1_4811C(s16 value);
extern s8 fn_1_46DC4(void *object);

void fn_1_1596DC(int index) {
    struct { int value; } offset;
    RankingEntry *entry;
    int i;
    int count;

    entry = &lbl_1_data_4C810[index];
    i = 0;
    while (entry->unk_2a + 1 != entry->unk_28 &&
           (entry->unk_2a != 0xf || entry->unk_28 != 0)) {
        fn_1_4811C(entry->unk_8[entry->unk_28]);
        entry->unk_28 = entry->unk_28 + 1 > 0xf ? 0
                      : (entry->unk_28 + 1 < 0 ? 0xf : entry->unk_28 + 1);
        if (++i > 0x10) {
            break;
        }
    }

    if (entry->unk_38 != 0) {
        offset.value = 0;
        count = 0;
        for (;;) {
            if (*(s16 *)((u8 *)entry->unk_4 + offset.value) == -1) {
                break;
            }
            if (fn_1_46DC4(*(void **)(lbl_1_data_FCD4 +
                                      *(s16 *)((u8 *)entry->unk_4 + offset.value) * 0x28 +
                                      lbl_801A66B4 * 4 + 4)) != 0) {
                lbl_1_bss_8F588[*(s16 *)((u8 *)entry->unk_4 + offset.value)] = count;
            }
            offset.value += 2;
        }
    }
}
/* fzgx:end fn_1_1596DC */

/* fzgx:begin fn_1_159804 noprologue */
#include "types.h"

typedef struct {
    u32 unk_0;
    u32 unk_4;
    s16 unk_8[16];
    s16 unk_28;
    s16 unk_2a;
    u8 unk_2c;
    u8 pad_2d[0xb];
    s32 unk_38;
} RankingEntry;

s16 fn_1_159804(s16 value, RankingEntry *entry) {
    s16 start = entry->unk_28;
    int count = 0;
    int found = 0;
    int next;
    s16 pos;

    while (entry->unk_2a + 1 != start && (entry->unk_2a != 15 || start != 0)) {
        next = start + 1;
        pos = next > 15 ? 0 : (next < 0 ? 15 : next);

        if (value == entry->unk_8[start]) {
            found = 1;
        }
        if (found) {
            entry->unk_8[start] = entry->unk_8[pos];
        }
        start = pos;

        count++;
        if (count > 16) {
            start = -1;
            break;
        }
    }

    entry->unk_8[entry->unk_2a] = value;
    return start;
}
/* fzgx:end fn_1_159804 */

/* fzgx:begin fn_1_1598C4 noprologue */
#include "types.h"

struct fn_1_1598C4_lbl_1_bss_8F878 {
    u8 pad_0[0x34];
    u32 unk_34;
    u8 pad_38[0x1];
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    u8 unk_3C;
    u8 unk_3D;
    u8 unk_3E;
};
extern f32 lbl_1_rodata_DAE8;
extern f64 lbl_1_rodata_DAF0;
extern struct fn_1_1598C4_lbl_1_bss_8F878 lbl_1_bss_8F878;
extern void fn_80008BA8(u32, u32, u32);
extern s16 fn_1_14F01C(s16);

void fn_1_1598C4(s32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u32 arg7, u64 arg8, u8 arg10) {
    s32 i;

    fn_80008BA8((u32)(&lbl_1_bss_8F878), arg7, 0x10U);

    for (i = 0; i < 0x10; i += 2) {
        if (*(u8 *)((u8 *)(&lbl_1_bss_8F878) + i) == 0) {
            s32 j;
            s32 t = i + 1;
            for (j = t; j < 0x10; j++) {
                *(u8 *)((u8 *)(&lbl_1_bss_8F878) + j) = 0;
            }
            break;
        }
    }

    lbl_1_bss_8F878.pad_38[0] = arg10;
    *(s32 *)((u8 *)(&lbl_1_bss_8F878) + 20) = (s32)arg8;
    *(s32 *)((u8 *)(&lbl_1_bss_8F878) + 16) = (s32)(arg8 >> 32);
    lbl_1_bss_8F878.unk_34 = arg0 & 0x3FFFF;
    lbl_1_bss_8F878.unk_39 = arg1;
    lbl_1_bss_8F878.unk_3D = arg6;
    lbl_1_bss_8F878.unk_3E = (u8)(s32)((*(f32 *)((u8 *)(&lbl_1_rodata_DAE8) + 0)) * (f32)arg5);

    if (arg1 >= 0x29U) {
        if ((s32)arg2 < fn_1_14F01C(0)) {
            lbl_1_bss_8F878.unk_3A = arg2;
        } else {
            lbl_1_bss_8F878.unk_3A = 0;
        }
        if ((s32)arg3 < fn_1_14F01C(1)) {
            lbl_1_bss_8F878.unk_3B = arg3;
        } else {
            lbl_1_bss_8F878.unk_3B = 0;
        }
        if ((s32)arg4 < fn_1_14F01C(2)) {
            lbl_1_bss_8F878.unk_3C = arg4;
            return;
        }
        lbl_1_bss_8F878.unk_3C = 0;
    }
}
/* fzgx:end fn_1_1598C4 */

/* fzgx:begin fn_1_159AE0 */
extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_451C(void);
extern void fn_1_A1340(void);
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_96A;
extern void fn_1_A1360(void);
extern void fn_1_A1364(void);
extern u8 lbl_1_bss_8F420[8];
extern f32 lbl_1_rodata_D8C8[18];
extern void fn_80008BEC(void *dst, int value, int size);
extern void fn_1_1568C4(void *);
extern void fn_80008BA8(void *, void *, int);
extern void fn_1_1574E0(Obj_1_bss_8F428 *entry, u32 value);
extern void fn_8006B7B4(void *);
extern void fn_8006B870(void);
extern void fn_1_157950(void);
extern void fn_1_157FC8(void);
extern u32 fn_1_157920(void);
extern void fn_1_4060(void);
extern u32 lbl_1_bss_8F57C[3];
extern void fn_1_9AD88(void);
extern void fn_1_1594AC(int index, int flag);
extern void OSReport(const char *format, ...);
extern void fn_1_465D0(void *object, int value);
extern void fn_1_9AD54(void);

extern void fn_1_1568C4(void *entry);

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_1569E8(void *entry);
extern void fn_1_12EF80(s16 value, s16 *out_0, s16 *out_1);
extern s32 fn_1_156218(u32 arg, void *out0, void *out1, void *out2);
extern u32 lbl_1_bss_8F3FC[9];
extern void fn_1_159804(int index, Obj_1_data_4C810 *entry);
extern void fn_1_4811C(s16 value);
extern void fn_1_48004(s16 value, u32 arg);
extern u32 lbl_1_rodata_DAF8[16];
extern void fn_1_9A508(void);

extern u32 lbl_801A63C0;
extern u8 fn_1_128E10(u8);

static inline void seed_rng(u32 seed) {
    lbl_801A63C0 = seed ^ 0xCAE87FB5;
}

static inline s32 next_rng(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

#define DIGIT(field, divisor) lbl_1_bss_8F878.field = (v0_2 / (divisor)) % 10 + '0'

void fn_1_159AE0(void) {
    u8 v0;
    u64 v35, v4, v66, v65;
    u8 v37;
    u32 v79, v83;
    s32 v84;
    u64 v0_2;

    if (lbl_1_bss_8F878.unk_38 != 0) {
        v0 = fn_1_128E10(lbl_1_bss_8F878.unk_39);
    } else {
        v0 = 0;
    }
    if (lbl_1_bss_8F878.unk_39 >= 41) {
        v4 = ((u64)lbl_1_bss_8F878.unk_10 << 32) | lbl_1_bss_8F878.unk_14;
        v35 = lbl_1_bss_8F878.unk_34 + ((u64)lbl_1_bss_8F878.unk_3A << 18) +
              ((u64)lbl_1_bss_8F878.unk_3B << 23) +
              ((u64)lbl_1_bss_8F878.unk_3C << 28) +
              ((u64)lbl_1_bss_8F878.unk_3E << 33);
        v66 = (v4 & 1023) + ((v4 >> 10) & 1023) + ((v4 >> 20) & 1023) +
              ((v4 >> 30) & 1023) + ((v4 >> 40) & 1023) +
              ((v4 >> 50) & 1023) + ((v4 >> 60) & 1023);
        for (v65 = 0; v65 < 16; v65++) {
            v37 = (&lbl_1_bss_8F878.unk_0)[v65];
            v66 += v37;
            v66 += v37 & (((v65 + 1) * 6505) & 1023);
        }
        v66 += lbl_1_bss_8F878.unk_3D * 19;
        v66 += (v35 & 4095) + ((v35 >> 12) & 4095) +
               ((v35 >> 24) & 4095) + ((v35 >> 36) & 4095);
        for (v65 = 0; v65 < 29; v65 += 3) {
            v66 += 1 << ((v35 >> v65) & 7);
        }
        v35 += (v66 & 4095) << 37;
        seed_rng(v35 & 255);
        v84 = next_rng();
        v0_2 = v35 + (((u64)v84 * 0x31AFD498DULL) & ~255ULL);
        DIGIT(unk_3F, 100000000000000ULL);
        DIGIT(unk_44, 10000000000000ULL);
        DIGIT(unk_49, 1000000000000ULL);
        lbl_1_bss_8F878.unk_42 = '-';
        DIGIT(unk_40, 100000000000ULL);
        DIGIT(unk_45, 10000000000ULL);
        DIGIT(unk_4A, 1000000000ULL);
        DIGIT(unk_4E, 100000000ULL);
        lbl_1_bss_8F878.unk_47 = '-';
        DIGIT(unk_41, 10000000ULL);
        DIGIT(unk_46, 1000000ULL);
        DIGIT(unk_4B, 100000ULL);
        DIGIT(unk_4F, 10000ULL);
        lbl_1_bss_8F878.unk_4C = '-';
        DIGIT(unk_43, 1000ULL);
        DIGIT(unk_48, 100ULL);
        DIGIT(unk_4D, 10ULL);
        lbl_1_bss_8F878.unk_50 = v0_2 % 10 + '0';
        lbl_1_bss_8F878.unk_51 = 0;
    } else if (v0 != 0) {
        v4 = lbl_1_bss_8F878.unk_10;
        v4 <<= 32;
        v4 |= lbl_1_bss_8F878.unk_14;
        v35 = lbl_1_bss_8F878.unk_34 + (v0 << 18) + (lbl_1_bss_8F878.unk_3E << 22);
        v66 = (v4 & 1023) + ((v4 >> 10) & 1023) + ((v4 >> 20) & 1023) +
              ((v4 >> 30) & 1023) + ((v4 >> 40) & 1023) +
              ((v4 >> 50) & 1023) + ((v4 >> 60) & 1023);
        for (v65 = 0; v65 < 16; v65++) {
            v37 = (&lbl_1_bss_8F878.unk_0)[v65];
            v66 += v37;
            v66 += v37 & (((v65 + 1) * 6505) & 1023);
        }
        v66 += lbl_1_bss_8F878.unk_3D * 19;
        v66 += (v35 & 1023) + ((v35 >> 10) & 1023) +
               ((v35 >> 20) & 1023) + ((v35 >> 30) & 1023);
        for (v65 = 0; v65 < 29; v65 += 3) {
            v66 += 1 << ((v35 >> v65) & 7);
        }
        v35 += (u64)((s32)v66 & 1023) << 26;
        seed_rng(v35 & 255);
        v84 = next_rng();
        v0_2 = v35 + (((u64)v84 * 0xE90EDULL) & ~255ULL);
        DIGIT(unk_3F, 10000000000ULL);
        DIGIT(unk_43, 1000000000ULL);
        DIGIT(unk_46, 100000000ULL);
        lbl_1_bss_8F878.unk_42 = '-';
        DIGIT(unk_40, 10000000ULL);
        DIGIT(unk_44, 1000000ULL);
        DIGIT(unk_48, 100000ULL);
        DIGIT(unk_4A, 10000ULL);
        lbl_1_bss_8F878.unk_47 = '-';
        DIGIT(unk_41, 1000ULL);
        DIGIT(unk_45, 100ULL);
        DIGIT(unk_49, 10ULL);
        lbl_1_bss_8F878.unk_4B = v0_2 % 10 + '0';
        lbl_1_bss_8F878.unk_4C = 0;
    } else {
        v4 = lbl_1_bss_8F878.unk_10;
        v4 <<= 32;
        v4 |= lbl_1_bss_8F878.unk_14;
        v35 = lbl_1_bss_8F878.unk_34 + (lbl_1_bss_8F878.unk_39 << 18) + (lbl_1_bss_8F878.unk_3E << 24);
        v66 = (v4 & 1023) + ((v4 >> 10) & 1023) + ((v4 >> 20) & 1023) +
              ((v4 >> 30) & 1023) + ((v4 >> 40) & 1023) +
              ((v4 >> 50) & 1023) + ((v4 >> 60) & 1023);
        for (v65 = 0; v65 < 16; v65++) {
            v37 = (&lbl_1_bss_8F878.unk_0)[v65];
            v66 += v37;
            v66 += v37 & (((v65 + 1) * 6505) & 1023);
        }
        v66 += lbl_1_bss_8F878.unk_3D * 19;
        v66 += (v35 & 2047) + ((v35 >> 11) & 2047) +
               ((v35 >> 22) & 2047) + ((v35 >> 33) & 2047) +
               ((v35 >> 44) & 2047) + ((v35 >> 55) & 2047);
        for (v65 = 0; v65 < 29; v65 += 3) {
            v66 += 1 << ((v35 >> v65) & 7);
        }
        v35 += (u64)((s32)v66 & 2047) << 28;
        seed_rng(v35 & 255);
        v84 = next_rng();
        v0_2 = v35 + (((u64)v84 * 0xD1A94AULL) & ~255ULL);
        DIGIT(unk_3F, 100000000000ULL);
        DIGIT(unk_42, 10000000000ULL);
        DIGIT(unk_46, 1000000000ULL);
        DIGIT(unk_4A, 100000000ULL);
        lbl_1_bss_8F878.unk_43 = '-';
        DIGIT(unk_40, 10000000ULL);
        DIGIT(unk_44, 1000000ULL);
        DIGIT(unk_47, 100000ULL);
        DIGIT(unk_4B, 10000ULL);
        lbl_1_bss_8F878.unk_48 = '-';
        DIGIT(unk_41, 1000ULL);
        DIGIT(unk_45, 100ULL);
        DIGIT(unk_49, 10ULL);
        lbl_1_bss_8F878.unk_4C = v0_2 % 10 + '0';
        lbl_1_bss_8F878.unk_4D = 0;
    }
}
/* fzgx:end fn_1_159AE0 */

/* fzgx:begin fn_1_15AC00 */
// Return the address of the ranking state byte at offset 0x3f.
u8 *fn_1_15AC00(void) {
    return &lbl_1_bss_8F878.unk_3F;
}
/* fzgx:end fn_1_15AC00 */

/* fzgx:begin fn_1_15AC10 */
extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_451C(void);
extern void fn_1_A1340(void);
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_96A;
extern void fn_1_A1360(void);
extern void fn_1_A1364(void);
extern u8 lbl_1_bss_8F420[8];
extern f32 lbl_1_rodata_D8C8[18];
extern void fn_80008BEC(void *dst, int value, int size);
extern void fn_1_1568C4(void *);
extern void fn_80008BA8(void *, void *, int);
extern void fn_1_1574E0(Obj_1_bss_8F428 *entry, u32 value);
extern void fn_8006B7B4(void *);
extern void fn_8006B870(void);
extern void fn_1_157950(void);
extern void fn_1_157FC8(void);
extern u32 fn_1_157920(void);
extern void fn_1_4060(void);
extern u32 lbl_1_bss_8F57C[3];
extern void fn_1_9AD88(void);
extern void fn_1_1594AC(int index, int flag);
extern void OSReport(const char *format, ...);
extern void fn_1_465D0(void *object, int value);
extern void fn_1_9AD54(void);

extern void fn_1_1568C4(void *entry);

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_1569E8(void *entry);
extern void fn_1_12EF80(s16 value, s16 *out_0, s16 *out_1);
extern s32 fn_1_156218(u32 arg, void *out0, void *out1, void *out2);
extern u32 lbl_1_bss_8F3FC[9];
extern void fn_1_159804(int index, Obj_1_data_4C810 *entry);
extern void fn_1_4811C(s16 value);
extern void fn_1_48004(s16 value, u32 arg);
extern u32 lbl_1_rodata_DAF8[16];
extern void fn_1_9A508(void);

extern u32 fn_1_B7FC8(void);
extern u32 fn_8003D4C0(void);
extern u8 lbl_1_bss_718E0[23016];
extern u32 lbl_801A63C0[];

static inline void set_seed(u32 value) {
    lbl_801A63C0[0] = value;
}
static inline s32 next_random(void) {
    lbl_801A63C0[0] = lbl_801A63C0[0] * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0[0] >> 16) & 0x7FFF;
}

static inline u64 make_value(void) {
    u32 t0 = fn_1_B7FC8();
    u8 v0 = lbl_1_bss_718E0[0x5523];
    u64 v1 = t0 & 0x3FFFFFFULL;
    v1 += (u64)(v0 & 0x3F) << 26;
    t0 = fn_8003D4C0();
    return (v1 << 32) + t0;
}

u64 fn_1_15AC10(void) {
    u64 v21;
    u64 v18;
    u64 v16;
    u64 v76;
    u64 v78;
    u32 v13;
    u32 v15;
    s32 v67, v69, v71;
    u8 *v82;
    u32 t0;
    u8 v0;
    v21 = make_value();
    v13 = ((u32)(((v21 >> 32) & 3) +
                      ((v21 & 0x2000ULL) >> 11) +
                      ((v21 & 0x100000ULL) >> 17)) & 0xFF) ^ 0xCAE87FB5;
    set_seed(v13);
    v16 = next_random();
    for (v18 = 0; v18 < 64; v18 += 1) {
        if (v18 != 13 && v18 != 20 && (v18 - 32) > 1) {
            u64 v29 = (v21 >> v18) & 1;
            u64 t4;
            v29 += (v16 % (v18 + 11)) & 1;
            t4 = 1ULL << v18;
            v21 &= ~t4;
            if (v29 & 1) {
                v21 |= t4;
            }
        }
    }
    lbl_1_bss_8F878.unk_18 = 0x30 + (v21 / 1ULL) % 10;
    lbl_1_bss_8F878.unk_19 = 0x30 + (v21 / 10ULL) % 10;
    lbl_1_bss_8F878.unk_1A = 0x30 + (v21 / 100ULL) % 10;
    lbl_1_bss_8F878.unk_1B = 0x30 + (v21 / 1000ULL) % 10;
    lbl_1_bss_8F878.unk_1C = 45;
    lbl_1_bss_8F878.unk_1D = 0x30 + (v21 / 10000ULL) % 10;
    lbl_1_bss_8F878.unk_1E = 0x30 + (v21 / 100000ULL) % 10;
    lbl_1_bss_8F878.unk_1F = 0x30 + (v21 / 1000000ULL) % 10;
    lbl_1_bss_8F878.unk_20 = 0x30 + (v21 / 10000000ULL) % 10;
    lbl_1_bss_8F878.unk_21 = 45;
    lbl_1_bss_8F878.unk_22 = 0x30 + (v21 / 100000000ULL) % 10;
    lbl_1_bss_8F878.unk_23 = 0x30 + (v21 / 1000000000ULL) % 10;
    lbl_1_bss_8F878.unk_24 = 0x30 + (v21 / 10000000000ULL) % 10;
    lbl_1_bss_8F878.unk_25 = 0x30 + (v21 / 100000000000ULL) % 10;
    lbl_1_bss_8F878.unk_26 = 45;
    lbl_1_bss_8F878.unk_27 = 0x30 + (v21 / 1000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_28 = 0x30 + (v21 / 10000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_29 = 0x30 + (v21 / 100000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_2A = 0x30 + (v21 / 1000000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_2B = 45;
    lbl_1_bss_8F878.unk_2C = 0x30 + (v21 / 10000000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_2D = 0x30 + (v21 / 100000000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_2E = 0x30 + (v21 / 1000000000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_2F = 0x30 + (v21 / 10000000000000000000ULL) % 10;
    set_seed((u32)(v21 % 1000) ^ 0xCAE87FB5);
    v67 = next_random();
    v69 = next_random();
    v71 = next_random();
    v76 = (u64)v71 * ((u64)v69 * (u64)v67);
    for (v18 = 5; v18 < 24; v18 += 1) {
        v82 = &lbl_1_bss_8F878.unk_18 + v18;
        if (*v82 != 45) {
            *v82 += v76 % 10;
            if (*v82 > 57) {
                *v82 -= 10;
            }
            v76 /= 10;
        }
    }
    lbl_1_bss_8F878.unk_30 = 0;
    return v21;
}
/* fzgx:end fn_1_15AC10 */

/* fzgx:begin fn_1_15B3E8 */
// Return the current ranking state byte.
u8 fn_1_15B3E8(void) {
    return lbl_1_bss_8F878.unk_3A;
}
/* fzgx:end fn_1_15B3E8 */

/* fzgx:begin fn_1_15B3F8 */
// Return the ranking state byte at offset 0x3b.
u8 fn_1_15B3F8(void) {
    return lbl_1_bss_8F878.unk_3B;
}
/* fzgx:end fn_1_15B3F8 */

/* fzgx:begin fn_1_15B408 */
// Returns the current ranking state.
u8 fn_1_15B408(void) {
    return lbl_1_bss_8F878.unk_3C;
}
/* fzgx:end fn_1_15B408 */

/* fzgx:begin fn_1_15B418 */
u8 *fn_1_15B418(void) {
    return &lbl_1_bss_8F878.unk_18;
}
/* fzgx:end fn_1_15B418 */

/* fzgx:begin fn_1_15B428 */
// fn_1_15B428: empty in retail (single blr).
void fn_1_15B428(void) {
}
/* fzgx:end fn_1_15B428 */

/* fzgx:begin fn_1_15B42C */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} Fn_1_15B42C_Chunk;

void fn_1_15B42C(void) {
    Fn_1_15B42C_Chunk *src = (Fn_1_15B42C_Chunk *)lbl_1_rodata_DAF8;
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;
    Fn_1_15B42C_Chunk *dst = (Fn_1_15B42C_Chunk *)&obj->unk_4;

    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    obj->unk_5D = 0;
    obj->unk_5E = 0;
    obj->unk_5C = 0;
    fn_1_9A508();
    obj->unk_0 = -1;
}
/* fzgx:end fn_1_15B42C */

/* fzgx:begin fn_1_15B4F8 */
// fn_1_15B4F8: empty in retail (single blr).
void fn_1_15B4F8(void) {
}
/* fzgx:end fn_1_15B4F8 */

/* fzgx:begin fn_1_15B4FC */
void fn_1_15B4FC(void) {
    fn_1_9AD54();
}
/* fzgx:end fn_1_15B4FC */

/* fzgx:begin fn_1_15B51C */
// fn_1_15B51C: empty in retail (single blr).
void fn_1_15B51C(void) {
}
/* fzgx:end fn_1_15B51C */

/* fzgx:begin fn_1_15B520 */
void fn_1_15B520(void) {
    fn_1_9AD88();
}
/* fzgx:end fn_1_15B520 */

/* fzgx:begin fn_1_15B540 */
// fn_1_15B540: empty in retail (single blr).
void fn_1_15B540(void) {
}
/* fzgx:end fn_1_15B540 */

/* fzgx:begin fn_1_15B544 */
typedef struct {
    u32 flags;
    u8 pad_04[0x3c];
} fn_1_15B544_RankingEntry;

// Set the high flag on each ranking entry managed by the singleton.
void fn_1_15B544(void) {
    s16 i;
    fn_1_15B544_RankingEntry *entry;

    i = 0;
    entry = (fn_1_15B544_RankingEntry *)lbl_1_bss_3BE0->unk_54;
    while (i < (s32)lbl_1_bss_3BE0->unk_48) {
        entry->flags |= 0x80000000u;
        i++;
        entry = (fn_1_15B544_RankingEntry *)((u8 *)entry + 0x40);
    }
}
/* fzgx:end fn_1_15B544 */

/* fzgx:begin fn_1_15B588 */
// Clears the high bit of each ranking entry flag.
void fn_1_15B588(void) {
    u8 *entry;
    s16 i;
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    entry = (u8 *)obj;
    i = 0;
    while (i < obj->unk_5E) {
        u32 *value = *(u32 **)(entry + 0xc4);

        entry += 4;
        i++;
        *value &= 0x7fffffff;
    }
}
/* fzgx:end fn_1_15B588 */

/* fzgx:begin fn_1_15B5CC */
void fn_1_15B5CC(void) {
    u8 *entry;
    s16 i;
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    entry = (u8 *)obj;
    i = 0;
    while (i < obj->unk_5D) {
        u32 *value = *(u32 **)(entry + 0x74);

        entry += 4;
        i++;
        *value &= 0x7fffffff;
    }
}
/* fzgx:end fn_1_15B5CC */

/* fzgx:begin fn_1_15B610 */
void fn_1_15B610(void) {
    u8 *entry;
    s16 i;
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    entry = (u8 *)obj;
    i = 0;
    while (i < *((u8 *)obj + 0x5d)) {
        u32 *value = *(u32 **)(entry + 0x74);

        entry += 4;
        i++;
        *value |= 0x80000000u;
    }
}
/* fzgx:end fn_1_15B610 */

/* fzgx:begin fn_1_15B654 */
void fn_1_15B654(void) {
    u8 *entry;
    s16 i;
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    entry = (u8 *)obj;
    i = 0;
    while (i < obj->unk_5C) {
        u32 *value = *(u32 **)(entry + 0x60);

        entry += 4;
        i++;
        *value |= 0x80000000u;
    }
}
/* fzgx:end fn_1_15B654 */

/* fzgx:begin fn_1_15B698 */
u32 fn_1_15B698(s32 kind, u32 *value) {
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    switch (kind) {
    case 3:
        obj->unk_114 = *value;
        break;
    case 1:
        obj->unk_120 = *value;
        break;
    case 2:
        obj->unk_124 = *value;
        break;
    case 4:
        obj->unk_118 = *value;
        break;
    case 0:
        obj->unk_11C = *value;
        break;
    default:
        break;
    }
    return 1;
}
/* fzgx:end fn_1_15B698 */
