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
extern void fn_1_1574E0();
extern void fn_8006B7B4();
extern void fn_8006B870(void);

extern void fn_1_1568C4(void *entry);

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_1569E8(void *entry);
extern void fn_1_12EF80(s16 value, s16 *out_0, s16 *out_1);
extern s32 fn_1_156218(u32 arg, void *out0, void *out1, void *out2);
extern u32 lbl_1_bss_8F3FC[9];

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

/* fzgx:begin fn_1_1555B0 */
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
    fn_1_12EF80(value, &index_0, &index_1);
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

/* fzgx:begin fn_1_1556B4 */
extern void fn_1_12EF80(s16 value, s16 *out_0, s16 *out_1);
extern void fn_1_3EF14(void *);
extern char *strncpy(char *, const char *, size_t);
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
char lbl_1_bss_8F3E4__fzgx_offset_4[0x11];
u8 lbl_1_bss_8F3E4__fzgx_offset_15;
u16 lbl_1_bss_8F3E4__fzgx_offset_16;
u32 lbl_1_bss_8F3FC[9];
u8 lbl_1_bss_8F420[8];

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
    s = lbl_1_bss_8F3E4__fzgx_offset_15;
    s = *(u8 *)&lbl_1_bss_8F3E4__fzgx_offset_16;
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
    fn_1_12EF80(value, &index_0, &index_1);
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

    if (fzgx_obj_lbl_1_bss_8EF20 == 0) {
        return;
    }

    fn_1_1555B0_local(lbl_1_bss_8EF20__fzgx_offset_40);

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

/* fzgx:begin fn_1_155FB4 */
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
} Obj_1_bss_8EF20_At0_np_fn_1_155FB4;
typedef struct {
Obj_1_bss_8EF20_At0_np_fn_1_155FB4 *unk_0; /* 17 loads, 3 stores */
u8 pad_4[0x3C];
u32 unk_40; /* 1 loads, 2 stores */
u8 pad_44[0x4];
} Obj_1_bss_8EF20_np_fn_1_155FB4;

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
fn_1_3EF14(&rec);
if (rec.unk_0 & 0x1000) {
a = (Entry_155FB4 *)fzgx_obj_lbl_1_bss_8EF20;
for (i = 9; i >= 0; i--) {
/* record fields other than the loop-invariant id are re-read on every pass: retail reloads them inside the loop */
#define VRF(f) (((Rec_155FB4 *)&rec)->f)
if ((a)[i].unk_0 == rec.unk_1444 && a[i].unk_18 == VRF(unk_145C)
&& a[i].unk_1A == VRF(unk_145E) && a[i].pad_1B[0] == VRF(unk_145F)
&& a[i].pad_1B[1] == VRF(unk_1460) && a[i].pad_1B[2] == VRF(unk_1461)
&& a[i].pad_1B[3] == VRF(unk_1462) && a[i].pad_1B[4] == VRF(unk_1463) ) {
strncpy((char *)&a[i].pad_4[4], arg, 0x10);
break;
}
}
p = ((Entry_155FB4 *)(&fzgx_obj_lbl_1_bss_8EF68)) ;
for (i = 9; i >= 0; i--) {
if (((Entry_155FB4 *)(&fzgx_obj_lbl_1_bss_8EF68)) [i].unk_0 == rec.unk_1444 && ((Entry_155FB4 *)(&fzgx_obj_lbl_1_bss_8EF68)) [i].unk_18 == VRF(unk_145C)
&& ((Entry_155FB4 *)(&fzgx_obj_lbl_1_bss_8EF68)) [i].unk_1A == VRF(unk_145E)
&& ((Entry_155FB4 *)(&fzgx_obj_lbl_1_bss_8EF68)) [i].pad_1B[0] == VRF(unk_145F)
&& ((Entry_155FB4 *)(&fzgx_obj_lbl_1_bss_8EF68)) [i].pad_1B[1] == VRF(unk_1460)
&& ((Entry_155FB4 *)(&fzgx_obj_lbl_1_bss_8EF68)) [i].pad_1B[2] == VRF(unk_1461)
&& ((Entry_155FB4 *)(&fzgx_obj_lbl_1_bss_8EF68)) [i].pad_1B[3] == VRF(unk_1462)
&& ((Entry_155FB4 *)(&fzgx_obj_lbl_1_bss_8EF68)) [i].pad_1B[4] == VRF(unk_1463) ) {
strncpy((char *)&((Entry_155FB4 *)(&fzgx_obj_lbl_1_bss_8EF68)) [i].pad_4[4], arg, 0x10);
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
    t0 = fn_1_156218(arg0, &loc_78, &loc_40, &loc_8);
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

/* fzgx:begin fn_1_156218 */
typedef struct {
    u32 words[8];
} fn_1_156218_RankingRecord;

typedef struct {
    u8 pad[0x18];
    u16 value;
} fn_1_156218_RankingValue;

s32 fn_1_156218(u32 id, void *out0, void *out1, void *out2)
{
    fn_1_156218_RankingRecord *record = (fn_1_156218_RankingRecord *)out0;
    fn_1_156218_RankingValue *value = (fn_1_156218_RankingValue *)out1;
    fn_1_156218_RankingRecord *extra = (fn_1_156218_RankingRecord *)out2;
    s16 row;
    s16 column;
    s32 index;
    s32 i;

    fn_1_12EF80(id, &row, &column);
    index = column + row * 6;
    for (i = 0; i < 10; i++) {
        if (*(u16 *)&((Obj_1_bss_7F0C0 *)((u8 *)&lbl_1_bss_7F0C0 + index * 0x180 + i * 0x20))->unk_110 != 0) {
            *record = *(fn_1_156218_RankingRecord *)((u8 *)&lbl_1_bss_7F0C0.unk_F8 + index * 0x180 + i * 0x20);
            *extra = *(fn_1_156218_RankingRecord *)((u8 *)&lbl_1_bss_7F0C0.unk_238 + index * 0x180);
            value->value = *(u16 *)((u8 *)&lbl_1_bss_7F0C0.unk_258 + index * 0x180);
            return 1;
        }
    }
    *record = *(fn_1_156218_RankingRecord *)((u8 *)&lbl_1_bss_7F0C0.unk_F8 + index * 0x180);
    *extra = *(fn_1_156218_RankingRecord *)((u8 *)&lbl_1_bss_7F0C0.unk_238 + index * 0x180);
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
} fn_1_15659C_RankingEntry;

extern f32 lbl_1_rodata_D8C8[18];
extern void fn_80008BEC(void *dst, int value, int size);

// Clears both ranking entries to their default sentinel values.
void fn_1_15659C(void) {
    fn_1_15659C_RankingEntry *obj;
    f32 value;
    int i;

    fn_80008BEC(&lbl_1_bss_8F428, 0, 0x140);
    obj = (fn_1_15659C_RankingEntry *)&lbl_1_bss_8F428;
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

/* fzgx:begin fn_1_1567A8 */
extern void fn_1_1569A0(void *);
extern void fn_1_156B18(void *);

typedef struct {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x2c];
    f32 unk_34;
    u8 pad_38[0x14];
    u8 unk_4c;
} fn_1_1567A8_Entry;

extern void fn_1_156C08(void *);
extern void fn_1_156D9C(void *);
extern void fn_1_157070();
extern void fn_1_156F54();
extern void fn_1_157200();
extern void fn_1_157358();
extern void fn_1_1576B4();
extern void fn_1_157598();

void fn_1_1567A8(s32 index) {
    fn_1_1567A8_Entry *entry;
    u32 value;
    f32 field_value;

    entry = (fn_1_1567A8_Entry *)&lbl_1_bss_8F428 + index;
    value = entry->unk_4;
    if (entry->unk_4 + 0x10000 != 0xffff) {
        field_value = entry->unk_34;
        if (0.0f == field_value) {
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

/* fzgx:begin fn_1_1568C4 */
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

extern s32 fn_8006B55C();
extern s32 fn_8006B628();
extern s32 fn_8006B6F8();

#pragma opt_propagation off
void fn_1_1568C4(void *arg) {
    fn_1_1568C4_RankingState *state = (fn_1_1568C4_RankingState *)arg;
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
    if (((0x10000) + key) == 0xffff) {
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

void fn_1_1569A0(void *arg) {
    fn_1_1569A0_State *state = (fn_1_1569A0_State *)arg;
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

void fn_1_156B18(void *arg) {
    fn_1_156B18_State *state = (fn_1_156B18_State *)arg;
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
typedef struct Sig_fn_8006B55C_Fn8006B55CFlags { u8 flag7:1; u8 flag6:1; u8 rest:6; } Sig_fn_8006B55C_Fn8006B55CFlags;
typedef struct Sig_fn_8006B55C_Fn8006B55CData {
    u8 flags_pad[4]; Sig_fn_8006B55C_Fn8006B55CFlags flags; u8 _pad0[3];
    u16 value; u8 _pad1[0x44]; u8 payload[1];
} Sig_fn_8006B55C_Fn8006B55CData;
extern f64 __fabs(f64);
extern f32 lbl_1_rodata_D8C8[18];
typedef struct {
    u32 flags; Sig_fn_8006B55C_Fn8006B55CData *data; u32 pad8; u32 handle;
    u8 pad10[0x28]; f32 value; f32 delta;
} Sig_fn_1_156C08_Entry;
#pragma opt_propagation off
void fn_1_156C08(void *arg0_p) {
    Sig_fn_1_156C08_Entry *arg0 = (Sig_fn_1_156C08_Entry *)arg0_p;
    f32 v1; f32 v3; s32 v13; s32 v13_2; f32 v7; s32 negative; u32 *ph;
    f32 *pool = lbl_1_rodata_D8C8;
    Sig_fn_8006B55C_Fn8006B55CData *data;
    u32 handle;
    struct { u8 a[36]; } loc_8;
    v1 = -1.899999976158142f;
    (void)v1; (void)v1;
    v1 = (f32)(v1 * arg0->delta);
    if (v1 > 25.0f) v1 = 25.0f;
    else if (v1 < -25.0f) v1 = -25.0f;
    v1 += arg0->value;
    negative = v1 < 0.0f;
    v7 = __fabs(v1);
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
        if (fn_8006B55C((u32)data, ph, &loc_8) < 0) {
        } else { v13 = 1; }
    } else {
        if (fn_8006B628(handle, &loc_8) < 0) {
        } else { v13 = 1; }
    }
    if (v13 != 0 && (arg0->flags & 2) == 0) {
        if (fn_8006B6F8(arg0->handle) >= 0) arg0->flags |= 2;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_156C08 */

/* fzgx:begin fn_1_156D9C */
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
} RankEntry_D9C;


#pragma opt_dead_assignments off
void fn_1_156D9C(void *slot_p)
{
    RankSlot *slot = (RankSlot *)slot_p;
    u32 digit;
    s32 idx;
    RankEntry_D9C entry;
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
        idx = ((10.0f + v) * c);
    }

    digit = (u8)(*((u8 *)&lbl_1_data_49B20 + slot->unk_4d % 5));

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
        if (fn_8006B55C(data, (u32 *)&slot->unk_18, &entry) >= 0) {
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

extern s32 fn_8006B55C();
extern s32 fn_8006B628();
extern s32 fn_8006B6F8();

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
extern s32 fn_8006B55C();
extern s32 fn_8006B628();
extern s32 fn_8006B6F8();

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
} Request_7070;

#pragma opt_common_subs off
void fn_1_157070(State *state) {
    u8 *fzgx_value__;
    f32 fzgx_live;
    u16 *fzgx_value;
    f32 *table = lbl_1_rodata_D8C8;
    struct { u32 value; } success;
    Request_7070 request;
    f32 amount;

    if (state->flags4c & 4) {
        fzgx_live = state->value34;
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
        (request.unk8 = (0));
        fzgx_value__ = &request.unkc;
        *fzgx_value__ = (u8)((s32)(table[17] * amount) + 80);
        request.unke = 90;
        request.unk10 = 100;
        fzgx_value = &request.unk12;
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

#pragma opt_common_subs reset
/* fzgx:end fn_1_157070 */

/* fzgx:begin fn_1_157200 */
extern const f32 lbl_1_rodata_D910;
extern f32 lbl_1_rodata_D914[3];

extern s32 fn_8006B55C();
extern s32 fn_8006B628();
extern s32 fn_8006B6F8();

typedef struct {
    u32 flags;
    void *arg04;
    u8 _pad08[0x14];
    u32 entry;
    u8 _pad20[0x18];
    f32 value;
    u8 _pad3c[0x10];
    u8 status;
} RankingState_7200;

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

#pragma opt_dead_assignments off
void fn_1_157200(RankingState_7200 *state) {
    if (state->status & 0x10) {
        s32 success = 0;
        RankingRequest request;

        request.kind = 5;
        request.value0c = 330;
        request.value10 = 0;
        request.value14 = 240;
        if (state->value > lbl_1_rodata_D910) {
            request.value16 = 90;
        } else if (state->value < ((lbl_1_rodata_D914)[0])) {
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
extern void fn_8006B7B4();
extern s32 fn_8006B55C();
extern s32 fn_8006B628();
extern s32 fn_8006B6F8();

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
            u8 converted = value;
            if (converted == state->value30) {
                return;
            }
        }
        state->value30 = value;
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

/* fzgx:begin fn_1_1574E0 */
#include "types.h"

extern s32 fn_8006B55C();
extern s32 fn_8006B628();
extern void fn_8006B7B4();
extern s32 fn_8006B6F8();

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
extern s32 fn_8006B55C();
extern s32 fn_8006B628();
extern s32 fn_8006B6F8();

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

    if (!(((0x80) & state->flags))) {
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
            if (!(((0x80) & state->flags))) {
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
extern s32 fn_8006B55C();
extern s32 fn_8006B628();
extern s32 fn_8006B6F8();

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
} RankingConfig_76B4;

typedef struct {
    u32 flags;
    u32 field04;
    u8 _pad08[0x24];
    void *data;
    u8 _pad30[0x1c];
    u8 enabled;
} RankingState_76B4;

#pragma opt_propagation off
void fn_1_1576B4(RankingState_76B4 *state) {
    RankingConfig_76B4 config;
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

        if (!(((0x100) & state->flags))) {
            field04 = state->field04;
            data = state->data;
            if ((u32)data == 0xffffffffU) {
                if (fn_8006B55C(field04, &state->data, &config) >= 0) {
                    success = 1;
                }
            } else if (fn_8006B628(data, &config) >= 0) {
                success = 1;
            }

            if (success && !(((0x100) & state->flags)) &&
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
