#include "types.h"


/* --- rel/movie_module/fn_12_3148.c --- */
typedef struct Sig_fn_12_48C4_MovieEntry {
 s32 active; u8 unk04[0x38]; f32 unk3c; f32 unk40;
} Sig_fn_12_48C4_MovieEntry;
typedef struct MovieModule {
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
} MovieModule;
extern u32 lbl_12_bss_10[300];
extern u8 lbl_12_rodata_448[160];
extern Sig_fn_12_48C4_MovieEntry *fn_12_48C4(void);
extern void *fn_12_3570(void *);
extern void fn_12_48A0(void *);
extern void fn_12_354C(void *);
extern void *memset(void *, int, u32);
typedef void (*Fn12Callback)(u32, u32);
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
static inline void destroy(MovieModule *movie) {
 if (movie != 0) {
 void *arg0 = movie->field_20;
 void *arg1 = movie->field_2c;
 movie->field_00 = 0;
 fn_12_48A0(arg0);
 fn_12_354C(arg1);
 lbl_12_bss_10[0]--;
 }
}
static inline MovieModule *find_slot(void) {
 MovieModule *v1 = (MovieModule *)((u8 *)lbl_12_bss_10 + 24);
 s32 v0;
 for (v0 = 0; v0 < (s32)lbl_12_bss_10[1]; v0++) {
 if ((s32)v1->field_00 == 0) return v1;
 v1++;
 }
 return 0;
}
MovieModule *fn_12_3148(u32 arg0, s32 arg1) {
 u8 *p_lbl_12_rodata_448 = lbl_12_rodata_448;
 MovieModule *v1 = find_slot();
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

/* --- rel/movie_module/fn_12_33BC.c --- */
void fn_12_33BC(u32 a, u32 b) {
    lbl_12_bss_10[2] = a;
    lbl_12_bss_10[3] = b;
}

/* --- rel/movie_module/fn_12_33D0.c --- */
extern s32 lbl_12_bss_8;
extern void fn_12_4934(void);
extern void fn_12_35EC(void);
extern void fn_12_49F8(void);

void fn_12_33D0(void) {
    if (lbl_12_bss_8 > 0) {
        fn_12_4934();
        fn_12_35EC();
        fn_12_49F8();
        lbl_12_bss_8--;
    }
}
