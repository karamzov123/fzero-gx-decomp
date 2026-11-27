#include "types.h"

typedef struct Sig_fn_12_48C4_MovieEntry {
 s32 active; u8 unk04[0x38]; f32 unk3c; f32 unk40;
} Sig_fn_12_48C4_MovieEntry;

typedef struct MovieInner {
    u32 unk0;
    u32 unk4;
    u32 pad8[3];
    u32 unk14;
} MovieInner;
extern u32 lbl_12_bss_C;
extern u32 lbl_12_bss_10[300];
extern void fn_12_48A0(u32 *value);
extern void fn_12_354C(void *arg);
extern u8 lbl_12_rodata_448[160];
extern Sig_fn_12_48C4_MovieEntry *fn_12_48C4(void);
extern void *fn_12_3570(void *);
extern void *memset(void *, int, u32);
extern s32 lbl_12_bss_8;
extern void fn_12_4934(void);
extern void fn_12_35EC(void);
extern void fn_12_49F8(void);
extern void fn_12_3D624(MovieInner *);
extern void fn_12_4A18(void);
extern void fn_12_4938(void);
extern void fn_12_35F0(void);

/* fzgx:begin fn_12_307C */
/* --- rel/movie_module/fn_12_307C.c --- */

u32 fn_12_307C(void) {
    return lbl_12_bss_C;
}
/* fzgx:end fn_12_307C */

/* fzgx:begin fn_12_308C */
/* --- rel/movie_module/fn_12_308C.c --- */

u32 fn_12_308C(void) {
    return lbl_12_bss_10[5];
}
/* fzgx:end fn_12_308C */

/* fzgx:begin fn_12_309C */
/* --- rel/movie_module/fn_12_309C.c --- */
typedef void (*Fn12Callback)(u32, u32);

void fn_12_309C(u32 a, u32 b, u32 c) {
    Fn12Callback callback;
    u32 count;
    u32 value;

    callback = (Fn12Callback)lbl_12_bss_10[2];
    count = lbl_12_bss_10[4];
    value = lbl_12_bss_10[3];
    lbl_12_bss_10[4] = count + 1;
    if (callback != 0) {
        callback(value, c);
    }
}
/* fzgx:end fn_12_309C */

/* fzgx:begin fn_12_30E8 */
/* --- rel/movie_module/fn_12_30E8.c --- */

typedef struct MovieModule {
    u32 field_00;
    u8 pad_04[0x1c];
    void *field_20;
    u8 pad_24[8];
    void *field_2c;
} MovieModule;

void fn_12_30E8(MovieModule *movie) {
    if (movie != 0) {
        void *arg0 = movie->field_20;
        void *arg1 = movie->field_2c;

        movie->field_00 = 0;
        fn_12_48A0( (u32 *)(void *)(arg0));
        fn_12_354C(arg1);
        lbl_12_bss_10[0]--;
    }
}
/* fzgx:end fn_12_30E8 */

/* fzgx:begin fn_12_3148 */
/* --- rel/movie_module/fn_12_3148.c --- */
/* --- rel/movie_module/fn_12_3148.c --- */
typedef struct MovieModule_u1 {
 u32 field_00;
 u32 field_04, field_08, field_0c;
 u8 pad_10[0x10];
 void *field_20;
 u32 field_24, field_28;
 void *field_2c;
 u32 field_30, field_34;
 /* Volatile preserves the retail reload after each address-field store. */
 volatile u32 field_38, field_3c, field_40, field_44;
 u8 pad_48[8];
 u32 field_50;
 s32 field_54;
 u8 pad_58[8];
 s32 field_60;
 u8 pad_64[0x2c];
} MovieModule_u1;
static inline void report(u8 *text) {
 Fn12Callback callback;
 u32 count;
 u32 value;
 callback = (Fn12Callback)lbl_12_bss_10[2];
 count = lbl_12_bss_10[4];
 value = lbl_12_bss_10[3];
 lbl_12_bss_10[4] = count + 1;
 if (callback != 0) callback(value, (u32)text);
}
static inline void destroy(MovieModule_u1 *movie) {
 if (movie != 0) {
 void *arg0 = movie->field_20;
 void *arg1 = movie->field_2c;
 movie->field_00 = 0;
 fn_12_48A0(arg0);
 fn_12_354C(arg1);
 lbl_12_bss_10[0]--;
 }
}
static inline MovieModule_u1 *find_slot(void) {
 MovieModule_u1 *v1 = (MovieModule_u1 *)((u8 *)lbl_12_bss_10 + 24);
 s32 v0;
 for (v0 = 0; v0 < (s32)lbl_12_bss_10[1]; v0++) {
 if ((s32)v1->field_00 == 0) return v1;
 v1++;
 }
 return 0;
}
MovieModule_u1 *fn_12_3148(u32 arg0, s32 arg1) {
 u8 *p_lbl_12_rodata_448 = lbl_12_rodata_448;
 MovieModule_u1 *v1 = find_slot();
 void *v2;
 if (v1 == 0) return v1;
 switch (arg1 >= 0x301f) {
 default:
 report(p_lbl_12_rodata_448 + 0x34);
 return 0;
 case 1:
 break;
 }
 memset(v1, 0, 0x90);
 v1->field_04 = 0;
 v1->field_08 = 0;
 v1->field_0c = 0;
 v1->field_24 = 1;
 v1->field_28 = 0;
 v1->field_34 = 0;
 v1->field_38 = (arg0 + 31) & ~31;
 v1->field_3c = v1->field_38 + 0x400;
 v1->field_40 = v1->field_3c + 0x400;
 v1->field_44 = v1->field_40 + 0x400;
 v1->field_50 = arg0;
 v1->field_54 = arg1;
 v1->field_60 = -1;
 v1->field_00 = 1;
 v2 = fn_12_48C4();
 if (v2 == 0) {
 report(p_lbl_12_rodata_448 + 0x60);
 destroy(v1);
 return 0;
 }
 v1->field_20 = v2;
 v2 = fn_12_3570(v2);
 if (v2 == 0) {
 report(p_lbl_12_rodata_448 + 0x80);
 destroy(v1);
 return 0;
 }
 v1->field_2c = v2;
 lbl_12_bss_10[0]++;
 return v1;
}
/* fzgx:end fn_12_3148 */

/* fzgx:begin fn_12_33BC */
/* --- rel/movie_module/fn_12_33BC.c --- */
void fn_12_33BC(u32 a, u32 b) {
    lbl_12_bss_10[2] = a;
    lbl_12_bss_10[3] = b;
}
/* fzgx:end fn_12_33BC */

/* fzgx:begin fn_12_33D0 */
/* --- rel/movie_module/fn_12_33D0.c --- */

void fn_12_33D0(void) {
    if (lbl_12_bss_8 > 0) {
        fn_12_4934();
        fn_12_35EC();
        fn_12_49F8();
        lbl_12_bss_8--;
    }
}
/* fzgx:end fn_12_33D0 */

/* fzgx:begin fn_12_341C noprologue */
#include "types.h"

typedef struct MovieInner {
    u32 unk0;
    u32 unk4;
    u32 pad8[3];
    u32 unk14;
} MovieInner;

typedef struct MovieBss {
    s32 count;
    u32 unk4;
    MovieInner inner;
    u8 pad[0x4a8 - sizeof(MovieInner)];
    const void *unk4B0;
} MovieBss;

extern u8 lbl_12_rodata_448[160];
extern void fn_12_3D624(MovieInner *);
extern void fn_12_4A18(void);
extern void fn_12_4938(void);
extern void fn_12_35F0(void);
extern void *memset(void *, int, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s32 lbl_12_bss_8;
u32 lbl_12_bss_C;
MovieInner lbl_12_bss_10;
u32 lbl_12_bss_10__fzgx_offset_18[292];
const void *lbl_12_bss_10__fzgx_offset_4A8;
u32 lbl_12_bss_10__fzgx_offset_4AC;
u32 lbl_12_bss_4C0[42];
u32 lbl_12_bss_568[140];
u32 lbl_12_bss_798[258];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_12_bss_8;
    s = *(u8 *)&lbl_12_bss_C;
    s = *(u8 *)&lbl_12_bss_10;
    s = *(u8 *)&lbl_12_bss_10__fzgx_offset_18;
    s = *(u8 *)&lbl_12_bss_10__fzgx_offset_4A8;
    s = *(u8 *)&lbl_12_bss_10__fzgx_offset_4AC;
    s = *(u8 *)&lbl_12_bss_4C0;
    s = *(u8 *)&lbl_12_bss_568;
    s = *(u8 *)&lbl_12_bss_798;
}
#pragma section code_type ".text"

void fn_12_341C(void) {
    
    if (lbl_12_bss_8 < 1) {
        lbl_12_bss_10__fzgx_offset_4A8 = lbl_12_rodata_448;
        memset(&lbl_12_bss_10, 0, 0x4a8);
        lbl_12_bss_10.unk4 = 8;
        lbl_12_bss_10.unk14 = 1;
        fn_12_3D624(&lbl_12_bss_10);
        fn_12_4A18();
        fn_12_4938();
        fn_12_35F0();
        lbl_12_bss_C = 0;
        lbl_12_bss_8++;
    }
}
/* fzgx:end fn_12_341C */
