/* Non-matching: best partial attempt (95.57% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/title/title.h"
typedef struct TitleState {
    u8 pad[544];
    s16 unk_224;
    u8 pad226[0x238-0x226];
    void *unk_238;
    u8 pad23c[2];
    u16 unk_23E;
    u8 unk_240;
    u8 unk_241;
} TitleState;
typedef struct Entry { s32 id; u8 color; u8 pad; u16 y; } Entry;
typedef struct Font { s32 id; f32 x,y,z; u8 pad10[0x2c-0x10]; f32 alpha; u32 color; u8 pad34[0x58-0x34]; } Font;
typedef struct Pool { u8 pad[0x48]; Entry entries[8]; u32 color; } Pool;
extern f32 lbl_8_rodata_0[];
extern const Font lbl_1_rodata_26F8;
extern u8 lbl_801A66BA;
extern s16 lbl_1_bss_96A;
typedef struct Other { u8 pad[0x15]; s8 mode; } Other;
extern Other lbl_1_bss_58;
extern void fn_1_52070(u32);
extern void fn_80005E0C(void);
extern void fn_1_A1360(void);
extern void fn_80007AB4(void *);
extern s32 fn_1_4E724(Font *);
extern int fn_1_4C10(void);
extern void fn_1_52088(void);
extern void fn_1_3EF8C(u8);
extern void fn_1_3ED8C(u32,u32,u32,u32,u32,u32,u32);
extern void fn_1_3EB78(u32,u32,u32,u32);
extern void fn_8_784(u32);
extern void fn_1_3EFF0(void (*)(u32),u8);
extern void fn_8006CE1C(f32);
extern void fn_1_3EF08(u8);
extern void fn_1_4A00(s32,u8,void *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_8_bss_0;
u8 lbl_8_bss_0_gap_1;
u8 fzgx_obj_lbl_8_bss_2;
u8 lbl_8_bss_0_gap_3;
u32 lbl_8_bss_4[2];
u32 lbl_8_bss_C[5];
u32 lbl_8_bss_20[129];
s16 lbl_8_bss_224;
u16 lbl_8_bss_0_gap_226;
u32 lbl_8_bss_228;
u32 lbl_8_bss_22C;
u8 lbl_8_bss_230;
u8 lbl_8_bss_0_gap_231;
u16 lbl_8_bss_0_gap_231_fill_232;
u32 fzgx_obj_lbl_8_bss_234;
void *fzgx_obj_lbl_8_bss_238;
u8 lbl_8_bss_238_fill_23C;
u8 fzgx_obj_lbl_8_bss_23D;
u16 lbl_8_bss_0_gap_23E;
u8 lbl_8_bss_0_gap_23E_2;
u8 lbl_8_bss_241;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_8_bss_0;
    s = *(u8 *)&lbl_8_bss_0_gap_1;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2;
    s = *(u8 *)&lbl_8_bss_0_gap_3;
    s = *(u8 *)&lbl_8_bss_4;
    s = *(u8 *)&lbl_8_bss_C;
    s = *(u8 *)&lbl_8_bss_20;
    s = *(u8 *)&lbl_8_bss_224;
    s = *(u8 *)&lbl_8_bss_0_gap_226;
    s = *(u8 *)&lbl_8_bss_228;
    s = *(u8 *)&lbl_8_bss_22C;
    s = *(u8 *)&lbl_8_bss_230;
    s = *(u8 *)&lbl_8_bss_0_gap_231;
    s = *(u8 *)&lbl_8_bss_0_gap_231_fill_232;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_234;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_238;
    s = *(u8 *)&lbl_8_bss_238_fill_23C;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_23D;
    s = *(u8 *)&lbl_8_bss_0_gap_23E;
    s = *(u8 *)&lbl_8_bss_0_gap_23E_2;
    s = *(u8 *)&lbl_8_bss_241;
}
#pragma section code_type ".text"

static inline Entry *fn_8_EC4_array_read(Entry *array) { return array; }
#pragma opt_propagation off
void fn_8_EC4(void) {
    
    Pool *pool = (Pool *)lbl_8_rodata_0;
    u32 color;
    Font font;
    Font * lab_t0;
    u32 lab_t0_;
    fn_1_52070(0x140);
    fn_80005E0C();
    fn_80005E0C();
    if (lbl_8_bss_0_gap_23E) lbl_8_bss_0_gap_23E--;
    fn_1_A1360();
    color = pool->color;
    fn_80007AB4(&color);
    if (fn_8_EC4_array_read(pool->entries)[lbl_8_bss_0_gap_23E_2 * 2].id != -2) {
        font = lbl_1_rodata_26F8;
        font.x = 320.0f;
        font.z = 3.0f;
        if (lbl_8_bss_0_gap_23E > 30) font.alpha = 1.0f;
        else font.alpha = (f32)lbl_8_bss_0_gap_23E / 30.0f;
        font.id = fn_8_EC4_array_read(pool->entries)[lbl_8_bss_0_gap_23E_2 * 2].id;
        font.color = fn_8_EC4_array_read(pool->entries)[lbl_8_bss_0_gap_23E_2 * 2].color;
        font.y = (f32)fn_8_EC4_array_read(pool->entries)[lbl_8_bss_0_gap_23E_2 * 2].y;
        fn_1_4E724(&font);
        if (fn_8_EC4_array_read(pool->entries)[lbl_8_bss_0_gap_23E_2 * 2 + 1].id != -1) {
            font.id = ((lbl_8_bss_0_gap_23E_2 * 2 + 1)[pool->entries]).id;
            font.color = fn_8_EC4_array_read(pool->entries)[lbl_8_bss_0_gap_23E_2 * 2 + 1].color;
            font.y = (f32)(*((lbl_8_bss_0_gap_23E_2 * 2 + 1) + (pool->entries))).y;
            fn_1_4E724(&font);
        }
    }
    if (lbl_8_bss_241) {
        if (fn_1_4C10()) { fn_1_52088(); return; }
        if (lbl_801A66BA) {
            lbl_1_bss_96A = 0x99;
            lbl_801A66BA = 0;
        } else {
            switch (lbl_1_bss_58.mode) {
            case 1: case 3: lbl_1_bss_96A = 0xa4; break;
            case 0: case 2: default: lbl_1_bss_96A = 0x9c; break;
            }
            lbl_1_bss_58.mode = (lbl_1_bss_58.mode + 1) & 3;
            if (lbl_1_bss_96A == 0x9c) {
                fn_1_3EF8C(6);
                fn_1_3ED8C(0,3,1,(u8)lbl_8_bss_224,10,30,0);
                lab_t0_ = 0;
                fn_1_3EB78(lab_t0_, 0, 0, 0);
                fn_1_3EFF0(fn_8_784,1);
                fn_8006CE1C(1.0f);
                fn_1_3EF08(1);
            }
        }
        fn_1_52088();
        return;
    }
    if (lbl_8_bss_0_gap_23E > 30) { fn_1_52088(); return; }
    if (fn_8_EC4_array_read(pool->entries)[lbl_8_bss_0_gap_23E_2 * 2 + 2].id == -1) {
        void *ptr;
        if (fn_1_4C10()) { fn_1_52088(); return; }
        fn_1_4A00(0,15,(fzgx_obj_lbl_8_bss_238));
        lbl_8_bss_241 = 1;
        fn_1_52088();
        return;
    }
    font = lbl_1_rodata_26F8;
    font.z = 2.0f;
    font.x = 320.0f;
    font.alpha = (f32)(30 - lbl_8_bss_0_gap_23E) / 30.0f;
    font.id = fn_8_EC4_array_read(pool->entries)[lbl_8_bss_0_gap_23E_2 * 2 + 2].id;
    font.color = fn_8_EC4_array_read(pool->entries)[lbl_8_bss_0_gap_23E_2 * 2 + 2].color;
    font.y = (f32)fn_8_EC4_array_read(pool->entries)[lbl_8_bss_0_gap_23E_2 * 2 + 2].y;
    fn_1_4E724((&font));
    if (fn_8_EC4_array_read(pool->entries)[lbl_8_bss_0_gap_23E_2 * 2 + 3].id != -1) {
        font.id = ((lbl_8_bss_0_gap_23E_2 * 2 + 3)[pool->entries]).id;
        font.color = fn_8_EC4_array_read(pool->entries)[lbl_8_bss_0_gap_23E_2 * 2 + 3].color;
        font.y = (f32)(*((pool->entries) + (lbl_8_bss_0_gap_23E_2 * 2 + 3))).y;
        fn_1_4E724(&font);
    }
    if (!lbl_8_bss_0_gap_23E) {
        lbl_8_bss_0_gap_23E = 0x118;
        lbl_8_bss_0_gap_23E_2++;
    }
    fn_1_52088();
}
#pragma opt_propagation reset

