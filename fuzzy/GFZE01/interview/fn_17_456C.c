/* Non-matching: best partial attempt (97.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Sig_fn_80071268_fn_80071268_Entry { void *unk_0; void *unk_4; };
struct Sig_fn_80071268_fn_80071268_Arg0 { s32 count; u8 pad_4[4]; struct Sig_fn_80071268_fn_80071268_Entry *entries; };
typedef struct { f32 x, y, z; } Position;
struct InterviewState456C {
    u8 pad_0[0x88]; s32 unk_88; u32 unk_8C; u8 pad_90[0x54];
    struct Sig_fn_80071268_fn_80071268_Arg0 *unk_E4[1];
};
struct InterviewObject456C { u8 pad_0[0xA0]; s16 unk_A0; u8 pad_A2[6]; Position unk_A8; };
typedef struct InterviewGlobals { s32 frame; u8 pad_4[8]; s16 unk_C; u8 pad_E[0x66]; } InterviewGlobals;
struct VecWords { u32 x, y, z; };

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_17_bss_0;
u8 fzgx_obj_lbl_17_bss_1;
u8 fzgx_obj_lbl_17_bss_2;
u8 fzgx_obj_lbl_17_bss_3;
u8 fzgx_obj_lbl_17_bss_3__b1;
u8 fzgx_obj_lbl_17_bss_3__b2;
u8 fzgx_obj_lbl_17_bss_3__b3;
u8 fzgx_obj_lbl_17_bss_3__b4;
u8 fzgx_obj_lbl_17_bss_3__b5;
u8 fzgx_obj_lbl_17_bss_3__b6;
u8 fzgx_obj_lbl_17_bss_3__b7;
u8 fzgx_obj_lbl_17_bss_3__b8;
u32 fzgx_obj_lbl_17_bss_C;
u32 fzgx_obj_lbl_17_bss_10;
u32 fzgx_obj_lbl_17_bss_14;
u32 fzgx_obj_lbl_17_bss_18;
u32 lbl_17_bss_18__fzgx_offset_4;
u32 fzgx_obj_lbl_17_bss_20;
u32 fzgx_obj_lbl_17_bss_24[4];
u32 fzgx_obj_lbl_17_bss_34[8];
u32 fzgx_obj_lbl_17_bss_54;
u32 fzgx_obj_lbl_17_bss_58;
u16 lbl_17_bss_58__fzgx_offset_4;
u16 lbl_17_bss_58__fzgx_offset_6;
InterviewGlobals fzgx_obj_lbl_17_bss_60;
s16 lbl_17_bss_60__fzgx_offset_74;
s16 fzgx_obj_lbl_17_bss_D6;
struct InterviewState456C *fzgx_obj_lbl_17_bss_D8[2];
u32 lbl_17_bss_D8__fzgx_offset_8[6];
u8 lbl_17_bss_D8__fzgx_offset_20;
u8 lbl_17_bss_D8__fzgx_offset_21;
u8 fzgx_obj_lbl_17_bss_FA;
u8 lbl_17_bss_FA__fzgx_offset_1;
s16 lbl_17_bss_FA__fzgx_offset_2;
s16 lbl_17_bss_FA__fzgx_offset_4;
u8 lbl_17_bss_FA__fzgx_offset_6;
u8 lbl_17_bss_FA__fzgx_offset_7;
u8 lbl_17_bss_FA__fzgx_offset_8;
u8 lbl_17_bss_FA__fzgx_offset_9;
u32 lbl_17_bss_FA__fzgx_offset_A[10];
u32 lbl_17_bss_FA__fzgx_offset_32;
u32 lbl_17_bss_FA__fzgx_offset_36;
u32 lbl_17_bss_FA__fzgx_offset_3A;
u32 lbl_17_bss_FA__fzgx_offset_3E;
u32 lbl_17_bss_FA__fzgx_offset_42;
u32 lbl_17_bss_FA__fzgx_offset_46;
u32 lbl_17_bss_FA__fzgx_offset_4A;
u32 lbl_17_bss_FA__fzgx_offset_4E;
u32 fzgx_obj_lbl_17_bss_14C;
u32 fzgx_obj_lbl_17_bss_150;
u32 lbl_17_bss_150__fzgx_offset_4[3];
u32 fzgx_obj_lbl_17_bss_160[3];
s16 lbl_17_bss_160__fzgx_offset_C;
s16 lbl_17_bss_160__fzgx_offset_E;
u32 fzgx_obj_lbl_17_bss_170[10];
struct InterviewObject456C *fzgx_obj_lbl_17_bss_198;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_17_bss_0;
    s = fzgx_obj_lbl_17_bss_1;
    s = fzgx_obj_lbl_17_bss_2;
    s = fzgx_obj_lbl_17_bss_3;
    s = fzgx_obj_lbl_17_bss_3__b1;
    s = fzgx_obj_lbl_17_bss_3__b2;
    s = fzgx_obj_lbl_17_bss_3__b3;
    s = fzgx_obj_lbl_17_bss_3__b4;
    s = fzgx_obj_lbl_17_bss_3__b5;
    s = fzgx_obj_lbl_17_bss_3__b6;
    s = fzgx_obj_lbl_17_bss_3__b7;
    s = fzgx_obj_lbl_17_bss_3__b8;
    s = fzgx_obj_lbl_17_bss_C;
    s = fzgx_obj_lbl_17_bss_10;
    s = fzgx_obj_lbl_17_bss_14;
    s = fzgx_obj_lbl_17_bss_18;
    s = lbl_17_bss_18__fzgx_offset_4;
    s = fzgx_obj_lbl_17_bss_20;
    s = fzgx_obj_lbl_17_bss_24[0];
    s = fzgx_obj_lbl_17_bss_34[0];
    s = fzgx_obj_lbl_17_bss_54;
    s = fzgx_obj_lbl_17_bss_58;
    s = lbl_17_bss_58__fzgx_offset_4;
    s = lbl_17_bss_58__fzgx_offset_6;
    s = *(u32 *)&fzgx_obj_lbl_17_bss_60;
    s = lbl_17_bss_60__fzgx_offset_74;
    s = fzgx_obj_lbl_17_bss_D6;
    s = *(u32 *)&fzgx_obj_lbl_17_bss_D8;
    s = lbl_17_bss_D8__fzgx_offset_8[0];
    s = lbl_17_bss_D8__fzgx_offset_20;
    s = lbl_17_bss_D8__fzgx_offset_21;
    s = fzgx_obj_lbl_17_bss_FA;
    s = lbl_17_bss_FA__fzgx_offset_1;
    s = lbl_17_bss_FA__fzgx_offset_2;
    s = lbl_17_bss_FA__fzgx_offset_4;
    s = lbl_17_bss_FA__fzgx_offset_6;
    s = lbl_17_bss_FA__fzgx_offset_7;
    s = lbl_17_bss_FA__fzgx_offset_8;
    s = lbl_17_bss_FA__fzgx_offset_9;
    s = lbl_17_bss_FA__fzgx_offset_A[0];
    s = lbl_17_bss_FA__fzgx_offset_32;
    s = lbl_17_bss_FA__fzgx_offset_36;
    s = lbl_17_bss_FA__fzgx_offset_3A;
    s = lbl_17_bss_FA__fzgx_offset_3E;
    s = lbl_17_bss_FA__fzgx_offset_42;
    s = lbl_17_bss_FA__fzgx_offset_46;
    s = lbl_17_bss_FA__fzgx_offset_4A;
    s = lbl_17_bss_FA__fzgx_offset_4E;
    s = fzgx_obj_lbl_17_bss_14C;
    s = fzgx_obj_lbl_17_bss_150;
    s = lbl_17_bss_150__fzgx_offset_4[0];
    s = fzgx_obj_lbl_17_bss_160[0];
    s = lbl_17_bss_160__fzgx_offset_C;
    s = lbl_17_bss_160__fzgx_offset_E;
    s = fzgx_obj_lbl_17_bss_170[0];
    s = *(u32 *)&fzgx_obj_lbl_17_bss_198;
}
#pragma section code_type ".text"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[26] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xC1200000, 0x3F800000, 0x41F00000, 0x00000000, 0x3DCCCCCD, 0x47AFC800, 0x00FF00FF, 0x808080FF, 0xFFFFFFFF, 0x80808000, 0x3F000000, 0x3E4CCCCD, 0x82FF0000, 0xFF780000, 0x00000000, 0x3F947AE1, 0x47AE147B, 0x3FB99999, 0x9999999A, 0x43300000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table3[85] = {0xFFFFFF00, 0x00000000, 0x00000000, 0x00000000, 0x3FF00000, 0x00000000, 0x40240000, 0x00000000, 0x3FECCCCC, 0xCCCCCCCD, 0x3A1D4952, 0x40000000, 0x43A00000, 0x434D0000, 0x40A00000, 0x00000000, 0x3FE99999, 0x9999999A, 0x437A0000, 0x43340000, 0x41200000, 0x43480000, 0x42400000, 0x42480000, 0x42960000, 0x00000000, 0x00000000, 0x43480000, 0x3F19999A, 0x000000FF, 0x404040FF, 0x404088FF, 0xAAAAAAFF, 0xFF0000FF, 0xBF000000, 0x00000000, 0xBFE1EB85, 0x1EB851EC, 0x00000000, 0x00000000, 0xBC23D70A, 0x3C23D70A, 0x43700000, 0x44228000, 0xC3480000, 0x395C3372, 0x00000000, 0x00000000, 0xBC23D70A, 0x00000000, 0x00000000, 0xBC23D70A, 0x3F889374, 0xBC6A7EFA, 0x3F8EB851, 0xEB851EB8, 0xBC23D70A, 0x00000000, 0x3F8A9FBE, 0x76C8B439, 0x3F10E885, 0x9C8C9321, 0x47000000, 0x47800000, 0x44CA8000, 0x45800000, 0x44610000, 0x44160000, 0x432E0000, 0x42B40000, 0x42FA0000, 0x3749539C, 0x3A83126F, 0x42C80000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40400000, 0x46FFFE00, 0x3F666666, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern u8 lbl_17_data_640A0[];
extern void *fn_80071268(struct Sig_fn_80071268_fn_80071268_Arg0 *, void *);
extern void lbl_8006D9D8(Position *);
extern void fn_80072558(void);
extern void **fn_1_5448C(void *);
extern s32 fn_1_548EC(void **);
extern void fn_1_556B8(void *);
extern void fn_1_92530(void *);

#pragma opt_loop_invariants off
#pragma opt_dead_assignments on
#pragma opt_lifetimes off
#pragma opt_strength_reduction off
void fn_17_456C(void) {
    s32 mode;
    InterviewGlobals *globals;
    struct InterviewState456C *state;
    state = fzgx_obj_lbl_17_bss_D8[0];
    globals = &fzgx_obj_lbl_17_bss_60;
    mode = state->unk_88;
    if (!((mode == 8 && globals->unk_C == 15) || (mode == 7 && globals->unk_C == 8) ||
        (mode == 35 && globals->unk_C == 7))) {
        return;
    }
    {
        if (mode == 7) {
            void *obj = fn_80071268(state->unk_E4[state->unk_8C], lbl_17_data_640A0);
            if (obj) {
                s32 i;
                for (i = 0; i < 30; i++) {
                    s16 row = i / 10;
                    Position copy;
                    Position pos = {0.0f, 0.16f, 0.0f};
                    pos.x = 1.5f - (f32)(0.3f * (f32)(i - row * 10));
                    pos.z = -0.15f + (f32)(0.3f * (f32)row);
                    copy = pos;
                    lbl_8006D9D8(&copy);
                    fn_80072558();
                    fn_1_548EC(fn_1_5448C((u8 *)obj + 8));
                    fn_1_556B8(obj);
                }
            }
        } else if (0x400000 & fzgx_obj_lbl_17_bss_58) {
            struct InterviewObject456C *obj = fzgx_obj_lbl_17_bss_198;
            if (mode == 8) {
                s16 i;
                obj->unk_A0 = -32768;
                for (i = 0; i < 144; i++) {
                    s16 row = i / 18;
                    Position pos = {0.0f, -1.8f, 0.0f};
                    pos.x = 7.200000286102295f - (f32)(0.8f * (f32)(i - row * 18));
                    pos.z = -21.0f - (f32)(0.8f * (f32)row);
                    obj->unk_A8 = pos;
                    fn_1_92530(obj);
                }
                {
                    Position last = {0.0f, -0.32f, -24.0f};
                    obj->unk_A8 = last;
                }
                fn_1_92530(obj);
            } else if (globals->frame > 250) {
                fn_1_92530(obj);
            }
        }
    }
}
