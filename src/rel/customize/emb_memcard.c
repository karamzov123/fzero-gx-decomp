#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/emb_memcard.h"


extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;
extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_C1394(u32 *arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, u32 arg3);
extern u32 lbl_3_rodata_288[60];
extern void lbl_8006DCA4(void);
extern void lbl_8006E1D8(struct Vec3 *, f32, f32, f32);
extern void fn_1_7BCCC(struct Vec3 *);
extern void fn_80035680(struct GXLightObj *, f32, f32, f32);
extern void fn_80035690(struct GXLightObj *, f32, f32, f32);
extern void fn_80035420(struct GXLightObj *, f32, int);
extern void fn_800356AC(struct GXLightObj *, u32 *);
extern void GXInitLightDistAttn(struct GXLightObj *, f32, f32, int);
extern void fn_1_7BB80(struct GXLightObj *, int);
extern void fn_1_7BD6C(int);
extern void fn_80074CF4(f32, f32, f32);

/* fzgx:begin fn_3_C328 noprologue */
#include "types.h"

extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;
extern char lbl_3_data_1A30[14];
extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_C1394(u32 *arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, u32 arg3);

void fn_3_C328(void) {
    u32 *state;

    if (!fn_1_B7C00()) {
        state = lbl_3_bss_7ED58;
        fn_1_C1394(state);
        if (state[2] != 0) {
            fn_1_46B4(lbl_801A6410, state[2], lbl_3_data_1A30, 0x154);
            state[2] = 0;
            state[3] = 0;
        }
        lbl_3_data_1A18 = 0;
    }
}
/* fzgx:end fn_3_C328 */

/* fzgx:begin fn_3_CE94 noprologue */
#include "types.h"
#include "font.h"
#include "rel/customize/emb_memcard.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 50.0f;
    s = 500.0f;
    s = 31.200000762939453f;
    s = 312.0f;
    s = 68.0f;
    s = 20.0f;
    s = 96.0f;
    s = 1.3600000143051147f;
    s = 161.0f;
    s = 1.015625f;
    s = 129.0f;
    s = 15.0f;
    s = 10.0f;
    s = 0.0f;
    s = 86.0f;
    s = 0.5f;
    s = 139.0f;
    s = 75.0f;
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table2[1] = {0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table3[1] = {0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table4[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 185.0f;
    s = 180.0f;
    s = 276.0f;
    s = 116.0f;
    s = 7.0f;
    s = 205.0f;
    s = 11.399999618530273f;
    s = 40.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 80.0f;
    s = 274.0f;
    s = 0.5833333134651184f;
    s = 0.5416666865348816f;
    s = 0.4583333432674408f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

struct fn_3_CE94_lbl_3_bss_7EE40_0_E8288 {
    u8 pad_0[0x24];
    u32 unk_24;
    u8 pad_28[0x2038];
};
struct fn_3_CE94_Copy88 { u32 a[22]; };
struct fn_3_CE94_CardSlot { u8 pad_0[5]; u8 unk_5; u8 pad_6[2]; u8 unk_8; u8 pad_9[0x81C0 - 9]; };
struct fn_3_CE94_lbl_3_rodata_288 {
    f32 unk_0; f32 unk_4; f32 unk_8; f32 unk_C;
    u8 pad_10[4]; f32 unk_14; u8 pad_18[0x14]; f32 unk_2C;
    f32 unk_30; f32 unk_34; u8 pad_38[4]; f32 unk_3C;
    u8 pad_40[8]; f64 unk_48;
    u32 unk_50; u32 unk_54; u32 unk_58;
    f32 unk_5C; f32 unk_60; f32 unk_64; f32 unk_68;
    f32 unk_6C; f32 unk_70; f32 unk_74; f32 unk_78;
    f32 unk_7C; f32 unk_80; f32 unk_84; f32 unk_88;
    f32 unk_8C; f32 unk_90; f32 unk_94; f64 unk_98;
};
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_A5DC4(void);
extern struct fn_3_CE94_lbl_3_rodata_288 lbl_3_rodata_288;
extern u32 lbl_1_rodata_26F8;
extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern f32 lbl_8006D188(u32);
extern void fn_1_50164(f32, f32, f32, f32, void *);
extern void fn_1_49410(void);
extern void fn_1_49514(u32 *);
extern void fn_1_495C8(u8);
extern void fn_1_4954C(f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern char *fn_1_14EA74(s16, char *, s16);
extern u32 lbl_801A66A0;
extern s32 lbl_801A66B4;


extern u8 fn_3_10260__fzgx_offset_0[];
extern u8 fn_3_104C4__fzgx_offset_0[];
extern u8 fn_3_106FC__fzgx_offset_0[];
extern u8 fn_3_10B68__fzgx_offset_0[];
extern u8 fn_3_10CB8__fzgx_offset_0[];
extern u8 fn_3_113AC__fzgx_offset_0[];
extern u8 fn_3_1180C__fzgx_offset_0[];
extern u8 fn_3_118BC__fzgx_offset_0[];
extern u8 fn_3_F984__fzgx_offset_0[];
extern u8 fn_3_FD30__fzgx_offset_0[];
extern u8 lbl_3_data_1A44__fzgx_offset_0[];
extern u8 lbl_3_data_1A6C__fzgx_offset_0[];
extern u8 lbl_3_data_1A70__fzgx_offset_0[];
extern u8 lbl_3_data_1ACC__fzgx_offset_0[];
extern u8 lbl_3_data_1B24__fzgx_offset_0[];
extern u8 lbl_3_data_1BB4__fzgx_offset_0[];
extern u8 lbl_3_data_1C04__fzgx_offset_0[];
extern u8 lbl_3_data_1C64__fzgx_offset_0[];
extern u8 lbl_3_data_1C70__fzgx_offset_0[];
extern u8 lbl_3_data_1C98__fzgx_offset_0[];
extern u8 lbl_3_data_1CA8__fzgx_offset_0[];
extern u8 lbl_3_data_1CD4__fzgx_offset_0[];
extern u8 lbl_3_data_1CE4__fzgx_offset_0[];
extern u8 lbl_3_data_1D10__fzgx_offset_0[];
extern u8 lbl_3_data_1D24__fzgx_offset_0[];
extern u8 lbl_3_data_1D5C__fzgx_offset_0[];
extern u8 lbl_3_data_1D74__fzgx_offset_0[];
extern u8 lbl_3_data_1DAC__fzgx_offset_0[];
extern u8 lbl_3_data_1DC4__fzgx_offset_0[];
extern u8 lbl_3_data_1DFC__fzgx_offset_0[];
extern u8 lbl_3_data_1E14__fzgx_offset_0[];
extern u8 lbl_3_data_1E50__fzgx_offset_0[];
extern u8 lbl_3_data_1E68__fzgx_offset_0[];
extern u8 lbl_3_data_1EA4__fzgx_offset_0[];
extern u8 lbl_3_data_1EA8__fzgx_offset_0[];
extern u8 lbl_3_data_1EB0__fzgx_offset_0[];
extern u8 lbl_3_data_1EB4__fzgx_offset_0[];
extern u8 lbl_3_data_2DCC__fzgx_offset_0[];
extern u8 lbl_3_data_2DE0__fzgx_offset_0[];
extern u8 lbl_3_data_2DFC__fzgx_offset_0[];
extern u8 lbl_3_data_2E24__fzgx_offset_0[];
extern u8 lbl_3_data_2E54__fzgx_offset_0[];
extern u8 lbl_3_data_2E64__fzgx_offset_0[];
extern u8 lbl_3_data_2E80__fzgx_offset_0[];
extern u8 lbl_3_data_2E90__fzgx_offset_0[];
extern u8 lbl_3_data_2EAC__fzgx_offset_0[];
extern u8 lbl_3_data_2EC0__fzgx_offset_0[];
extern u8 lbl_3_data_2EE0__fzgx_offset_0[];
extern u8 lbl_3_data_2EF4__fzgx_offset_0[];
extern u8 lbl_3_data_2F04__fzgx_offset_0[];
extern u8 lbl_3_data_2F20__fzgx_offset_0[];
extern u8 lbl_3_data_2F3C__fzgx_offset_0[];
extern u8 lbl_3_data_2F50__fzgx_offset_0[];
extern u8 lbl_3_data_2F64__fzgx_offset_0[];
extern u8 lbl_3_data_3068__fzgx_offset_0[];
extern u8 lbl_3_data_307C__fzgx_offset_0[];
extern u8 lbl_3_data_309C__fzgx_offset_0[];
extern u8 lbl_3_data_30AC__fzgx_offset_0[];
extern u8 lbl_3_data_30C8__fzgx_offset_0[];
extern u8 lbl_3_data_30D4__fzgx_offset_0[];
extern u8 lbl_3_data_30E0__fzgx_offset_0[];
extern u8 lbl_3_data_30EC__fzgx_offset_0[];
extern u8 lbl_3_data_30FC__fzgx_offset_0[];
extern u8 lbl_3_data_3120__fzgx_offset_0[];
extern u8 lbl_3_data_315C__fzgx_offset_0[];
extern u8 lbl_3_data_3168__fzgx_offset_0[];
extern u8 lbl_3_data_3174__fzgx_offset_0[];
extern u8 lbl_3_data_3180__fzgx_offset_0[];
u16 lbl_3_data_1A40 = 0xFFFF;
static union { u32 w[143]; u8 v[0x23C]; } fzgx_pool_init_fzgx_data_4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x53617669, 0x6E672063, 0x75727265, 0x6E742063, 0x68616E67, 0x65732E0A, 0x20497320, 0x74686973,
    0x204F4B3F, 0x20000000, 0x0, 0x8CBB5B82, 0xB082F15D, 0x8DDD5B82, 0xB482A25D, 0x82CC95CF,
    0x5B82D682, 0xF15D8D58, 0x5B82B182, 0xA45D82F0, 0x835A815B, 0x837582B5, 0x82DC82B7, 0x81420A82,  /* fzgx-allow: A1 retail data bytes */
    0xE682EB82, 0xB582A282, 0xC582B782, 0xA93F0000, (u32)lbl_3_data_1A44__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A70__fzgx_offset_0, 0x50617374, 0x6564206F, 0x626A6563, 0x74732068, 0x61766520, 0x6368616E,
    0x6765642E, 0xA205072, 0x65706172, 0x696E6720, 0x746F2073, 0x61766520, 0x616E6420, 0x72657475,
    0x726E2074, 0x6F207468, 0x65204761, 0x72616765, 0x2E0A4973, 0x20746869, 0x73204F4B, 0x3F200000,
    0x935C5B82, 0xCD5D82E8, 0x95745B82, 0xC25D82AF, 0x82AA95CF, 0x5B82D682, 0xF15D8D58, 0x5B82B182,
    0xA45D82B3, 0x82EA82C4, 0x82A282DC, 0x82B78142, 0xA835A81, 0x5B837582, 0xB582C491, 0x4F5B82DC,
    0x82A65D82, 0xCC89E65B, 0x82AA5D96, 0xCA5B82DF, 0x82F15D82, 0xC996DF5B, 0x82E082C7, 0x5D82E882,
    0xDC82B781, 0x420A82E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x3F000000, (u32)lbl_3_data_1ACC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1B24__fzgx_offset_0, 0x52657475, 0x726E696E, 0x6720746F, 0x20746865,
    0x20707265, 0x76696F75, 0x73207363, 0x7265656E, 0xA207769, 0x74686F75, 0x74207361, 0x76696E67,
    0x20637572, 0x72656E74, 0x20636861, 0x6E676573, 0x2E0A2049, 0x73207468, 0x6973204F, 0x4B3F2000,
    0x835A815B, 0x837582B9, 0x82B882C9, 0x914F5B82, 0xDC82A65D, 0x82CC89E6, 0x5B82AA5D, 0x96CA5B82,
    0xDF82F15D, 0x82C996DF, 0x5B82E082, 0xC75D82E8, 0x82DC82B7, 0x81420A82, 0xE682EB82, 0xB582A282,  /* fzgx-allow: A1 retail data bytes */
    0xC582B782, 0xA93F0000, (u32)lbl_3_data_1BB4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1C04__fzgx_offset_0,
    0x426F6479, 0x20506172, 0x74730000, 0x837B8366, 0x83428370, 0x815B8363, 0x0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_240 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1C64__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1C70__fzgx_offset_0
}};
static union { u32 w[9]; u8 v[0x24]; } fzgx_pool_init_fzgx_data_258 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x436F636B, 0x70697420, 0x50617274, 0x73000000, 0x8352834E, 0x83728362, 0x83678370, 0x815B8363,  /* fzgx-allow: A1 retail data bytes */
    0x0
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_27C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1C98__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1CA8__fzgx_offset_0
}};
static union { u32 w[9]; u8 v[0x24]; } fzgx_pool_init_fzgx_data_294 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x426F6F73, 0x74657220, 0x50617274, 0x73000000, 0x8375815B, 0x8358835E, 0x815B8370, 0x815B8363,  /* fzgx-allow: A1 retail data bytes */
    0x0
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_2B8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1CD4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1CE4__fzgx_offset_0
}};
static union { u32 w[13]; u8 v[0x34]; } fzgx_pool_init_fzgx_data_2D0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x46697265, 0x20537469, 0x6E677261, 0x7920426F, 0x64790000, 0x83748340, 0x83438341, 0x83588365,
    0x83428393, 0x834F838C, 0x834382CC, 0x837B8366, 0x83420000
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_304 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1D10__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1D24__fzgx_offset_0
}};
static union { u32 w[14]; u8 v[0x38]; } fzgx_pool_init_fzgx_data_31C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x46697265, 0x20537469, 0x6E677261, 0x79205061, 0x72747320, 0x31000000, 0x83748340, 0x83438341,
    0x83588365, 0x83428393, 0x834F838C, 0x834382CC, 0x8370815B, 0x83630000
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_354 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1D5C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1D74__fzgx_offset_0
}};
static union { u32 w[14]; u8 v[0x38]; } fzgx_pool_init_fzgx_data_36C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x5261696E, 0x626F7720, 0x50686F65, 0x6E697820, 0x426F6479, 0x0, 0x838C8343, 0x8393837B,
    0x815B8374, 0x8346836A, 0x8362834E, 0x835882CC, 0x837B8366, 0x83420000  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_3A4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1DAC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1DC4__fzgx_offset_0
}};
static union { u32 w[15]; u8 v[0x3c]; } fzgx_pool_init_fzgx_data_3BC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x5261696E, 0x626F7720, 0x50686F65, 0x6E697820, 0x50617274, 0x73203100, 0x838C8343, 0x8393837B,
    0x815B8374, 0x8346836A, 0x8362834E, 0x835882CC, 0x8370815B, 0x83638250, 0x0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_3F8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1DFC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1E14__fzgx_offset_0
}};
static union { u32 w[15]; u8 v[0x3c]; } fzgx_pool_init_fzgx_data_410 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x5261696E, 0x626F7720, 0x50686F65, 0x6E697820, 0x50617274, 0x73203200, 0x838C8343, 0x8393837B,
    0x815B8374, 0x8346836A, 0x8362834E, 0x835882CC, 0x8370815B, 0x83638251, 0x0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_44C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1E50__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1E68__fzgx_offset_0
}};
static union { u32 w[1282]; u8 v[0x1408]; } fzgx_pool_init_fzgx_data_464 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F0000, 0x82A282A2, 0x82A60000, 0x59455300, 0x82CD82A2, 0x0, (u32)lbl_3_data_1EA4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1EA8__fzgx_offset_0, (u32)lbl_3_data_1EB0__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1EB4__fzgx_offset_0, 0x3F000000, 0x3ECCCCCD, 0xC0200000, 0xBF800000, 0xC0400000, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40600000, 0x3F19999A, 0x3ECCCCCD, 0xBFCCCCCD, 0xBF4CCCCD, 0xC02CCCCD, 0x3FCCCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x4019999A, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x402CCCCD, 0x3F000000, 0x3ED70A3D, 0xBFE66666, 0xBF4CCCCD, 0xC0400000, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x40400000, 0x3F000000, 0x3E800000, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x40400000, 0x3F19999A, 0x3ED70A3D, 0xC0200000, 0xBF4CCCCD, 0xC0266666, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40266666, 0x3F266666, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40266666, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x40266666, 0x3F000000, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40266666, 0x3F000000, 0x3F000000, 0xC0000000, 0xBF4CCCCD, 0xC0333333, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x40333333, 0x3F19999A, 0x3ECCCCCD, 0xC0000000, 0xBF4CCCCD, 0xC0333333, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x40333333, 0x3F000000, 0x3EE66666, 0xC0000000, 0xBF4CCCCD, 0xC00CCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40333333, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x40200000, 0x404CCCCD, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FE66666, 0x40333333, 0x3F19999A, 0x3EB33333, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FE66666, 0x40333333, 0x3F19999A, 0x3EB33333, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x40333333, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x402CCCCD, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x40400000, 0x3F000000, 0x3EC28F5C, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x40133333, 0x40400000, 0x3F266666, 0x3EF5C28F, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x40400000, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x40400000, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40400000, 0x3F000000, 0x3E0F5C29, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FE66666, 0x40400000, 0x3F19999A, 0x3F000000, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x4019999A, 0x40400000, 0x3F000000, 0x3E4CCCCD, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40400000, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x402CCCCD, 0x3F000000, 0x3EB33333, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x402CCCCD, 0x3F000000, 0x3EB33333, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x402CCCCD, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x40400000, 0x3F19999A, 0x3E99999A, 0xC0133333, 0xBF4CCCCD, 0xC0533333, 0x40133333,  /* fzgx-allow: A1 retail data bytes */
    0x40333333, 0x40400000, 0x3F19999A, 0x3E99999A, 0xC0133333, 0xBF4CCCCD, 0xC0400000, 0x40133333,  /* fzgx-allow: A1 retail data bytes */
    0x40133333, 0x40400000, 0x3F000000, 0x3E19999A, 0xC0133333, 0xBF4CCCCD, 0xC0200000, 0x4019999A,  /* fzgx-allow: A1 retail data bytes */
    0x40133333, 0x40333333, 0x3F19999A, 0x3E4CCCCD, 0xBFF33333, 0xBF4CCCCD, 0xC0200000, 0x3FF33333,  /* fzgx-allow: A1 retail data bytes */
    0x40333333, 0x40533333, 0x3ECCCCCD, 0x3E19999A, 0xC0200000, 0xBF4CCCCD, 0xC039999A, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0x40133333, 0x40533333, 0x3F000000, 0x3E4CCCCD, 0xC0200000, 0xBF4CCCCD, 0xC039999A, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0x40133333, 0x40533333, 0x3F000000, 0x3E19999A, 0xBFCCCCCD, 0xBF4CCCCD, 0xBFE66666, 0x3FCCCCCD,
    0x3FE66666, 0x40000000, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC0200000, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40200000, 0x3F000000, 0x3EB33333, 0xC0000000, 0xBF4CCCCD, 0xC0133333, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x4019999A, 0x3F000000, 0x3F000000, 0xC0000000, 0xBF4CCCCD, 0xC0400000, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x404CCCCD, 0x3F000000, 0x3ECCCCCD, 0xC0000000, 0xBF4CCCCD, 0xC039999A, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40200000, 0x40333333, 0x3F266666, 0x3E99999A, 0xC0200000, 0xBF4CCCCD, 0xC0400000, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x40333333, 0x3F000000, 0x3F000000, 0xBF4CCCCD, 0xBF800000, 0xC0000000, 0x3FF33333,  /* fzgx-allow: A1 retail data bytes */
    0x3F4CCCCD, 0x3F800000, 0x3F000000, 0x3F000000, 0xBFF33333, 0xBF800000, 0xC0000000, 0x3F4CCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3F4CCCCD, 0x3F800000, 0x3F000000, 0x3F000000, 0xBF000000, 0xBF4CCCCD, 0xBFE66666, 0x3F000000,
    0x3FE66666, 0x3F666666, 0x3F000000, 0x3EAE147B, 0xC0133333, 0xBF333333, 0xC0000000, 0x40133333,  /* fzgx-allow: A1 retail data bytes */
    0x3FF33333, 0x3FC00000, 0x3F000000, 0x3ECCCCCD, 0xC0266666, 0xBF333333, 0xBFC00000, 0x40266666,  /* fzgx-allow: A1 retail data bytes */
    0x3FA66666, 0x40133333, 0x3F000000, 0x3F000000, 0xC0133333, 0xBF800000, 0xC0133333, 0x40133333,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40133333, 0x3F000000, 0x3F000000, 0xBFB33333, 0xBF800000, 0xC0133333, 0x3FB33333,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x40266666, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC0000000, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x3F99999A, 0x40266666, 0x3F000000, 0x3E99999A, 0xC0200000, 0xBF666666, 0xC00CCCCD, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0x3FE66666, 0x40000000, 0x3F000000, 0x3E99999A, 0xC0066666, 0xBF8CCCCD, 0xBFB33333, 0x40066666,  /* fzgx-allow: A1 retail data bytes */
    0x40066666, 0x40200000, 0x3EE66666, 0x3F000000, 0xC0133333, 0xBF800000, 0xC0200000, 0x40133333,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40200000, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC0133333, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x402CCCCD, 0x3F000000, 0x3E4CCCCD, 0xC0333333, 0xBF000000, 0xBFE66666, 0x40266666,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x3FE66666, 0x3F000000, 0x3DCCCCCD, 0xC0333333, 0xBF4CCCCD, 0xBFD9999A, 0x40333333,  /* fzgx-allow: A1 retail data bytes */
    0x3FD9999A, 0x40133333, 0x3F000000, 0x3E800000, 0xC0000000, 0xBF4CCCCD, 0xC0200000, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x40200000, 0x3F000000, 0x3E4CCCCD, 0xC0000000, 0xBF4CCCCD, 0xBFE66666, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FE66666, 0x40133333, 0x3F000000, 0x3E800000, 0xC0200000, 0xBF333333, 0xC0133333, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40333333, 0x3F000000, 0x3E800000, 0xC019999A, 0xBF666666, 0xC0333333, 0x4019999A,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x40333333, 0x3F000000, 0x3E4CCCCD, 0xBFC00000, 0xBF99999A, 0xC019999A, 0x3FC00000,  /* fzgx-allow: A1 retail data bytes */
    0x40200000, 0x4019999A, 0x3F000000, 0x3E4CCCCD, 0xBFF33333, 0xBF333333, 0xC0000000, 0x3FF33333,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x40800000, 0x3F000000, 0x3E4CCCCD, 0xC0066666, 0xBF333333, 0xC0000000, 0x40066666,  /* fzgx-allow: A1 retail data bytes */
    0x3FE66666, 0x40400000, 0x3F000000, 0x3DCCCCCD, 0xBFD9999A, 0xBF000000, 0xC019999A, 0x3FD9999A,  /* fzgx-allow: A1 retail data bytes */
    0x40200000, 0x40400000, 0x3F000000, 0x3EB851EC, 0xC0000000, 0xBF4CCCCD, 0xBFC00000, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x3FF33333, 0x40333333, 0x3F000000, 0x3E19999A, 0xC0000000, 0xBF4CCCCD, 0xC0200000, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x3FF33333, 0x400CCCCD, 0x3F000000, 0x3E4CCCCD, 0xC019999A, 0xBF666666, 0xC019999A, 0x4019999A,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x4019999A, 0x3F000000, 0x3E4CCCCD, 0xC00CCCCD, 0xBF800000, 0xBFE66666, 0x400CCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x402CCCCD, 0x3F000000, 0x3E19999A, 0xC0466666, 0xBF333333, 0xC00CCCCD, 0x40466666,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x4079999A, 0x3F000000, 0x3E99999A, 0xC0466666, 0xBF19999A, 0xC0000000, 0x40466666,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40266666, 0x3F000000, 0x3ECCCCCD, 0xBFA66666, 0xBF333333, 0xBFB33333, 0x3FA66666,
    0x3FC00000, 0x3FB33333, 0x3F4CCCCD, 0x3C23D70A, 0xBFA66666, 0xBF333333, 0xBFC00000, 0x3FA66666,
    0x3FA66666, 0x3FC00000, 0x3F000000, 0x3F000000, 0xBFB33333, 0xBF666666, 0xC0000000, 0x3FB33333,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x40200000, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF800000, 0xBFC00000, 0x3FB33333,
    0x3FC00000, 0x3FC00000, 0x3F000000, 0x3E99999A, 0xBFC00000, 0xBF4CCCCD, 0xBFC00000, 0x3FC00000,
    0x3FCCCCCD, 0x3FC00000, 0x3F000000, 0x3E99999A, 0xBFA66666, 0xBECCCCCD, 0xBFC00000, 0x3FA66666,
    0x3FA66666, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xC0066666, 0xBF4CCCCD, 0xBFA66666, 0x40066666,  /* fzgx-allow: A1 retail data bytes */
    0x3F8CCCCD, 0x3FC00000, 0x3F19999A, 0x3ECCCCCD, 0xBFC00000, 0xBF800000, 0xBFCCCCCD, 0x3FC00000,
    0x3FC00000, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xC02CCCCD, 0xBF666666, 0xBFE66666, 0x402CCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xC0000000, 0xBF4CCCCD, 0xBFCCCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x3FCCCCCD, 0x3F000000, 0x3DCCCCCD, 0xC0000000, 0xBF4CCCCD, 0xBFCCCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x400CCCCD, 0x3F000000, 0x3E800000, 0xC019999A, 0xBF4CCCCD, 0xBFCCCCCD, 0x4019999A,  /* fzgx-allow: A1 retail data bytes */
    0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3EE66666, 0xBFD9999A, 0xBF666666, 0xBFD9999A, 0x3FD9999A,
    0x3FCCCCCD, 0x40400000, 0x3F000000, 0x3E800000, 0xBFD9999A, 0xBF666666, 0xBFCCCCCD, 0x3FCCCCCD,
    0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3E800000, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333,
    0x3FB33333, 0x40000000, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333,
    0x3F99999A, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333,
    0x3F99999A, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFF33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FF33333,
    0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xBFD9999A, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FD9999A,
    0x3FB33333, 0x3FF33333, 0x3F000000, 0x3E800000, 0xBFF33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FF33333,
    0x3FCCCCCD, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333,
    0x3FC00000, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333,
    0x40000000, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333,
    0x3FD9999A, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xBFCCCCCD, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FCCCCCD,
    0x3FD9999A, 0x3FCCCCCD, 0x3F000000, 0x3EAE147B, 0xBFC00000, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FC00000,
    0x3FD9999A, 0x3FCCCCCD, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF333333, 0xBFC00000, 0x3FE66666,
    0x3F4CCCCD, 0x3F666666, 0x3F000000, 0x3EE66666, 0xBFA66666, 0xBF800000, 0xBF4CCCCD, 0x3FA66666,
    0x3F99999A, 0x3F4CCCCD, 0x3F000000, 0x3EE66666, 0xBFB33333, 0xBF800000, 0xBFCCCCCD, 0x3FB33333,
    0x3FC00000, 0x3F333333, 0x3F000000, 0x3E99999A, 0xBFB33333, 0xBFC00000, 0xBFCCCCCD, 0x3FB33333,
    0x3FC00000, 0x3F19999A, 0x3F000000, 0x3ECCCCCD, 0xBF99999A, 0xBF666666, 0xBFC00000, 0x3F99999A,
    0x3FC00000, 0x3F666666, 0x3F000000, 0x3E99999A, 0xBFA66666, 0xBF8CCCCD, 0xBFB33333, 0x3FA66666,
    0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xBFC00000, 0xBF4CCCCD, 0xBFA66666, 0x3FC00000,
    0x3F8CCCCD, 0x3FC00000, 0x3F19999A, 0x3ECCCCCD, 0xBFB33333, 0xBFA66666, 0xC019999A, 0x3FB33333,  /* fzgx-allow: A1 retail data bytes */
    0x3FA66666, 0x3F800000, 0x3F000000, 0x3E4CCCCD, 0xBFCCCCCD, 0xBFB33333, 0xBF4CCCCD, 0x3FCCCCCD,
    0x3FCCCCCD, 0x3FC00000, 0x3F000000, 0x3E4CCCCD, 0xBFD9999A, 0xBF99999A, 0xBF99999A, 0x3FD9999A,
    0x3F99999A, 0x3F4CCCCD, 0x3F000000, 0x3DCCCCCD, 0xC0066666, 0xBF4CCCCD, 0xC0000000, 0x40066666,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x3F4CCCCD, 0x3F000000, 0x3E800000, 0xBFE66666, 0xBF8CCCCD, 0xBFE66666, 0x3FE66666,
    0x3FE66666, 0x3F666666, 0x3F000000, 0x3E99999A, 0xBFF33333, 0xBF8CCCCD, 0xBFD9999A, 0x3FF33333,
    0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3EE66666, 0xC00CCCCD, 0xBFA66666, 0xBFE66666, 0x400CCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3F8CCCCD, 0x3F333333, 0x3F000000, 0x3E4CCCCD, 0xBF99999A, 0xBF4CCCCD, 0xC0200000, 0x3F99999A,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x3F666666, 0x3F000000, 0x3E4CCCCD, 0xC00CCCCD, 0xBF99999A, 0xC0000000, 0x400CCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3F800000, 0x3F4CCCCD, 0x3F000000, 0x3E4CCCCD, 0xC00CCCCD, 0xBF99999A, 0xBFCCCCCD, 0x400CCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xC00CCCCD, 0xBF99999A, 0xBFCCCCCD, 0x400CCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xBFCCCCCD, 0xBFC00000, 0xC0000000, 0x3FCCCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E800000, 0xBFCCCCCD, 0xBF8CCCCD, 0xBFF33333, 0x3FCCCCCD,
    0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF8CCCCD, 0xBFC00000, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x3FB33333, 0x3F4CCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFC00000, 0xBF99999A, 0xBFC00000, 0x3FC00000,
    0x40066666, 0x3F4CCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFCCCCCD, 0xBFB33333, 0xBFC00000, 0x3FCCCCCD,
    0x3FA66666, 0x3F4CCCCD, 0x3F000000, 0x3E19999A, 0xBFF33333, 0xBF99999A, 0xC0000000, 0x3FF33333,  /* fzgx-allow: A1 retail data bytes */
    0x3F99999A, 0x3F800000, 0x3F000000, 0x3EAE147B, 0xBFF33333, 0xBF800000, 0xBFD9999A, 0x3FF33333,
    0x3F800000, 0x3F333333, 0x4C6F6164, 0x696E6720, 0x456D626C, 0x656D2E2E, 0x2E000000, 0x83478393,
    0x8375838C, 0x838082F0, 0x838D815B, 0x83689286, 0x82C582B7, 0x81420000, 0x53656C65, 0x63742061,  /* fzgx-allow: A1 retail data bytes */
    0x20506C61, 0x63652074, 0x6F205265, 0x67697374, 0x65722074, 0x68652045, 0x6D626C65, 0x6D2E2000,
    0x83478393, 0x8375838C, 0x838082F0, 0x936F985E, 0x82B782E9, 0x8FEA8F8A, 0x82F09149, 0x91F082B5,
    0x82C482AD, 0x82BE82B3, 0x82A28142, 0x0, 0x52656D6F, 0x76652045, 0x6D626C65, 0x6D3F0000,
    0x83478393, 0x8375838C, 0x838082F0, 0x82CD82AA, 0x82B582DC, 0x82B782A9, 0x81480000, 0x53656C65,  /* fzgx-allow: A1 retail data bytes */
    0x63742050, 0x61727473, 0x2E200000, 0x8370815B, 0x836382F0, 0x914991F0, 0x82B582C4, 0x82AD82BE,
    0x82B382A2, 0x81420000, 0x53656C65, 0x63742061, 0x6E20456D, 0x626C656D, 0x2E200000, 0x83478393,  /* fzgx-allow: A1 retail data bytes */
    0x8375838C, 0x838082F0, 0x914991F0, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x8FE38F91,  /* fzgx-allow: A1 retail data bytes */
    0x82AB8A6D, 0x94469286, 0x82C582B7, 0x81420000, 0x4170706C, 0x7920456D, 0x626C656D, 0x2E200000,  /* fzgx-allow: A1 retail data bytes */
    0x83478393, 0x8375838C, 0x838082F0, 0x935C82E8, 0x957482AF, 0x82DC82B7, 0x81420000, 0x436F6D70,  /* fzgx-allow: A1 retail data bytes */
    0x6C657469, 0x6E672070, 0x726F6365, 0x7373696E, 0x672E2E2E, 0x0, 0x8F4997B9, 0x8F88979D,
    0x928682C5, 0x82B78142, 0x0, 0x436F6E66, 0x69726D69, 0x6E672073, 0x6176652E, 0x2E2E0000,
    0x835A815B, 0x83758A6D, 0x94469286, 0x82C582B7, 0x81420000, (u32)lbl_3_data_2DCC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2DE0__fzgx_offset_0, (u32)lbl_3_data_2DFC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_2E24__fzgx_offset_0, (u32)lbl_3_data_2E54__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2E64__fzgx_offset_0, (u32)lbl_3_data_2E80__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2E90__fzgx_offset_0, (u32)lbl_3_data_2EAC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2EC0__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_2EE0__fzgx_offset_0, (u32)lbl_3_data_2EF4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2F04__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2F20__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2F3C__fzgx_offset_0, (u32)lbl_3_data_2F50__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_2F64__fzgx_offset_0, 0x83AD2052, 0x6F746174, 0x65204D61, 0x6368696E, 0x65000000, 0x83AD208E, 0xD45B82AD,
    0x82E982DC, 0x5D82CC89, 0xF15B82A9, 0x82A25D93, 0x5D5B82C4, 0x82F15D00, 0x83A6204D, 0x6F766520,
    0x43616D65, 0x72610000, 0x83A62083, 0x4A838183, 0x8982CC88, 0xDA5B82A2, 0x5D93AE5B, 0x82C782A4,
    0x5D000000, 0x83A183AF, 0x205A6F6F, 0x6D000000, 0x83A183AF, 0x20835981, 0x5B838000, 0x83A42050,
    0x72657669, 0x65770000, 0x83A42083, 0x76838C83, 0x72838581, 0x5B000000, 0x83B283B4, 0x20496E63,
    0x72656173, 0x652F5265, 0x64756365, 0x20456D62, 0x6C656D20, 0x53697A65, 0x0, 0x83B283B4,
    0x20834783, 0x93837583, 0x8C838082, 0xCC8A675B, 0x82A982AD, 0x5D91E55B, 0x82BE82A2, 0x5D81458F,
    0x6B5B82B5, 0x82E382AD, 0x205D8FAC, 0x5B2082B5, 0x82E582A4, 0x5D000000, 0x839F2050, 0x61737465,
    0x0, 0x839F2093, 0x5C5B82CD, 0x5D82E900, 0x839F2050, 0x65656C20, 0x6F666600, 0x839F2082,
    0xCD82AA82, 0xB7000000, (u32)lbl_3_data_3068__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_307C__fzgx_offset_0,
    (u32)lbl_3_data_309C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_30AC__fzgx_offset_0, (u32)lbl_3_data_30C8__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_30D4__fzgx_offset_0, (u32)lbl_3_data_30E0__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_30EC__fzgx_offset_0, (u32)lbl_3_data_30FC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_3120__fzgx_offset_0,
    (u32)lbl_3_data_315C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_3168__fzgx_offset_0, (u32)lbl_3_data_3174__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_3180__fzgx_offset_0, 0x0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_F984__fzgx_offset_0, 0x1,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_FD30__fzgx_offset_0, 0x2, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_104C4__fzgx_offset_0, 0x3, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_10260__fzgx_offset_0,
    0x4, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_106FC__fzgx_offset_0, 0x5, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_10B68__fzgx_offset_0, 0x6, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)fn_3_10CB8__fzgx_offset_0, 0x7, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_118BC__fzgx_offset_0, 0x8, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_1180C__fzgx_offset_0, 0x9,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_113AC__fzgx_offset_0
}};
static union { u32 w[1]; char v[4]; } fzgx_pool_init_fzgx_format = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25730A00
}};
#define fzgx_data_4 fzgx_pool_init_fzgx_data_4.v
#define fzgx_text_240 fzgx_pool_init_fzgx_text_240.v
#define fzgx_data_258 fzgx_pool_init_fzgx_data_258.v
#define fzgx_text_27C fzgx_pool_init_fzgx_text_27C.v
#define fzgx_data_294 fzgx_pool_init_fzgx_data_294.v
#define fzgx_text_2B8 fzgx_pool_init_fzgx_text_2B8.v
#define fzgx_data_2D0 fzgx_pool_init_fzgx_data_2D0.v
#define fzgx_text_304 fzgx_pool_init_fzgx_text_304.v
#define fzgx_data_31C fzgx_pool_init_fzgx_data_31C.v
#define fzgx_text_354 fzgx_pool_init_fzgx_text_354.v
#define fzgx_data_36C fzgx_pool_init_fzgx_data_36C.v
#define fzgx_text_3A4 fzgx_pool_init_fzgx_text_3A4.v
#define fzgx_data_3BC fzgx_pool_init_fzgx_data_3BC.v
#define fzgx_text_3F8 fzgx_pool_init_fzgx_text_3F8.v
#define fzgx_data_410 fzgx_pool_init_fzgx_data_410.v
#define fzgx_text_44C fzgx_pool_init_fzgx_text_44C.v
#define fzgx_data_464 fzgx_pool_init_fzgx_data_464.v
#define fzgx_format fzgx_pool_init_fzgx_format.v
#pragma opt_pointer_analysis off
static inline const char **text_array(u32 p) { return (const char **)p; }
static inline const char *text_format(u32 p) { return (const char *)p; }
static inline Obj_3_bss_7EDC0_At0 *card_slot(u32 offset) { return (Obj_3_bss_7EDC0_At0 *)((u8 *)lbl_3_bss_7EDC0.unk_0 + offset); }
static inline Obj_3_bss_7EE40 *editor_slot(u32 offset) { return (Obj_3_bss_7EE40 *)((u8 *)&lbl_3_bss_7EE40 + offset); }
#pragma opt_pointer_analysis on
static inline s32 clamp_menu(s32 n) { return n < 0 ? 0 : n > 10 ? 10 : n; }
static inline u8 fn_3_CE94_array_read(u8 *array, s32 index) { return array[index]; }
#pragma opt_lifetimes off
void fn_3_CE94(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    s16 v3;
    struct { u32 value; } data_base;
    struct fn_3_CE94_lbl_3_rodata_288 *p_lbl_3_rodata_288;
    Obj_3_bss_7EDD8 *p_lbl_3_bss_7EDD8;
    s16 v0;
    s32 v1;
    s32 v2;
    f32 v4;
    u32 v5;
    f64 v6;
    f32 v7;
    f32 v8;
    f32 v9;
    u32 v10;
    f32 v11;
    f64 v12;
    f32 v13;
    u32 v14;
    f64 v15;
    FontDrawPacket loc_14;
    char buffer[256];
    u32 color0, color1, color2;

    struct { s32 value; } x0;
    s32 y0, y1, y2;
    s32 x1;
    u8 *slot;
    s32 t0;
    s32 x2;
    s16 dy0, dy1;
    data_base.value = (u32)&lbl_3_data_1A40;
    t0 = fn_1_A5DC4();
    v0 = arg3;
    if ((s8)t0 != 0) {
        v1 = lbl_3_bss_7EDD8.unk_24 - 5;
        v0 = (f32)(50.0f * (f32)clamp_menu(v1)) - 500.0f;
    } else {
        v2 = lbl_3_bss_7EDD8.unk_24 - 5;
        v0 = (f32)(31.2f * (f32)clamp_menu(v2)) - 312.0f;
    }
    loc_14 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v5 = 0x8918;
    v6 = 4503601774854144.0;
    loc_14.image = v5;
    v7 = (f32)(s32)(v0 + 38);
    loc_14.x = v7;
    loc_14.y = 185.0f;
    loc_14.z = 15.0f;
    loc_14.flags = 5;
    fn_1_4F734(&loc_14);
    loc_14 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v8 = 7.0f;
    v9 = (f32)(s32)(v0 + 30);
    loc_14.image = 12;
    loc_14.x = v9;
    loc_14.y = 180.0f;
    loc_14.z = 20.0f;
    loc_14.flags = 5;
    fn_1_50190(&loc_14, 276.0f, 116.0f, v8, v8, v8, v8);
    loc_14 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v10 = v0 + 32;
    v12 = 4503601774854144.0;
    loc_14.image = 0x8921;
    v13 = (f32)(s32)v10;
    loc_14.x = v13;
    loc_14.y = 205.0f;
    loc_14.z = 15.0f;
    fn_1_51678(&loc_14, 12, 7, 22, 2, 2);
    loc_14.flags = 5;
    loc_14.scale_x = 11.4f;
    fn_1_4F734(&loc_14);
    p_lbl_3_bss_7EDD8 = (Obj_3_bss_7EDD8 *)&lbl_3_bss_7EDD8;
    if (card_slot(p_lbl_3_bss_7EDD8->unk_46 * 0x81C0)->unk_8 > 1) {
        if (*(u32 *)((u8 *)&lbl_3_bss_7EE40.unk_24 + p_lbl_3_bss_7EDD8->unk_15 * 0x2060) & 0x80000000 ||
            (p_lbl_3_bss_7EDD8->unk_C & 0x18000000)) {
            loc_14 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            v14 = 0x891E;
            v15 = 4503601774854144.0;
            loc_14.image = v14;
            loc_14.x = (f32)(s32)v10;
            loc_14.y = (f32)(lbl_3_bss_7EDD8.unk_1C * 25 + 214);
            loc_14.z = 15.0f;
            *(f32 *)((u8 *)&loc_14 + 0x2C) = 0.5f;
            if ((__rlwnm(lbl_3_bss_7EDD8.unk_C, 32 - (28), 31, 31))) {
                loc_14.color[0] = (40.0f + (f32)(40.0f * lbl_8006D188((s32)((f32)(65536.0f * (f32)(lbl_801A66A0 % 60)) / 60.0f))));
                loc_14.color[1] = (80.0f + (f32)(80.0f * lbl_8006D188((s32)((f32)(65536.0f * (f32)(lbl_801A66A0 % 60)) / 60.0f))));
                loc_14.color[2] = (80.0f + (f32)(80.0f * lbl_8006D188((s32)((f32)(65536.0f * (f32)(lbl_801A66A0 % 60)) / 60.0f))));
                loc_14.flags = 5;
            } else {
                loc_14.color[0] = 80;
                loc_14.color[1] = 160;
                loc_14.color[2] = 160;
                loc_14.flags = 5;
            }
            fn_1_50164(274.0f, 20.0f, 0.0f, 0.0f, &loc_14);
        }
    }
    fn_1_49410();
    color0 = fzgx_pool_table2[0];
    fn_1_49514(&color0);
    fn_1_495C8(0);
    fn_1_4954C(10.0f);
    if (*(&lbl_3_bss_7EDC0.unk_0->unk_5 + p_lbl_3_bss_7EDD8->unk_46 * 0x81C0) >= 41) {
        if (lbl_801A66B4 != 5) {
            dy0 = -2;
            fn_1_49590(0.5f);
            fn_1_495B0(0x80000000);
            fn_1_4955C(0.5833333134651184f, 0.5833333134651184f);
        } else {
            dy0 = 0;
            fn_1_4955C(0.5f, 0.5f);
        }
        x0.value = v0 + 40;
        y0 = dy0;
        fn_1_496FC((f32)x0.value, (f32)(y0 + 219));
        fn_1_4AE0C(fzgx_format, fzgx_text_240[lbl_801A66B4]);
        fn_1_496FC((f32)x0.value, (f32)(y0 + 244));
        fn_1_4AE0C(fzgx_format, fzgx_text_27C[lbl_801A66B4]);
        fn_1_496FC((f32)x0.value, (f32)(y0 + 269));
        fn_1_4AE0C(fzgx_format, fzgx_text_2B8[lbl_801A66B4]);
        if (lbl_801A66B4 != 5) fn_1_4955C(0.5416666865348816f, 0.5416666865348816f);
        else fn_1_4955C(0.4583333432674408f, 0.4583333432674408f);
        fn_1_14EA74(*((u8 *)&lbl_3_bss_7EE40 + 0x81A4), buffer, (s16)lbl_801A66B4);
        x1 = v0 + 158;
        fn_1_496FC((f32)x1, (f32)(y0 + 220));
        fn_1_4AE0C(fzgx_format, buffer);
        fn_1_496FC((f32)x1, (f32)(y0 + 245));
        fn_1_14EA74(*((u8 *)&lbl_3_bss_7EE40 + 0x81AC), buffer, (s16)lbl_801A66B4);
        fn_1_4AE0C(fzgx_format, buffer);
        fn_1_496FC((f32)x1, (f32)(y0 + 270));
        fn_1_14EA74(*((u8 *)&lbl_3_bss_7EE40 + 0x81B4), buffer, (s16)lbl_801A66B4);
        fn_1_4AE0C(fzgx_format, buffer);
    } else {
        if (lbl_801A66B4 != 5) {
            dy1 = -2;
            fn_1_49590(0.5f);
            fn_1_495B0(0x80000000);
            fn_1_4955C(0.5833333134651184f, 0.5833333134651184f);
        } else {
            dy1 = 0;
            fn_1_4955C(0.5f, 0.5f);
        }
        if (lbl_3_bss_7EE40.unk_8 >= 2) {
            color1 = fzgx_pool_table3[0];
            fn_1_49514(&color1);
            slot = (u8 *)&lbl_3_bss_7EE40 + 0x10000;
            if (fn_3_CE94_array_read(slot, -0x7E60) == 4) {
                x2 = v0 + 40;
                y1 = dy1;
                fn_1_496FC((f32)x2, (f32)(y1 + 219));
                fn_1_4AE0C(fzgx_format, fzgx_text_304[lbl_801A66B4]);
                fn_1_496FC((f32)x2, (f32)(y1 + 244));
                fn_1_4AE0C(fzgx_format, fzgx_text_354[lbl_801A66B4]);
            }
            if (fn_3_CE94_array_read(slot, -0x7E60) == 40) {
                y2 = dy1;
                x1 = v0 + 40;
                fn_1_496FC((f32)x1, (f32)(y2 + 219));
                fn_1_4AE0C(fzgx_format, fzgx_text_3A4[lbl_801A66B4]);
                fn_1_496FC((f32)x1, (f32)(y2 + 244));
                fn_1_4AE0C(fzgx_format, fzgx_text_3F8[lbl_801A66B4]);
                fn_1_496FC((f32)x1, (f32)(y2 + 269));
                fn_1_4AE0C(fzgx_format, fzgx_text_44C[lbl_801A66B4]);
            }
        }
    }
    color2 = fzgx_pool_table4[0];
    fn_1_49514(&color2);
}
#pragma opt_lifetimes reset
/* fzgx:end fn_3_CE94 */

/* fzgx:begin fn_3_E5D4 noprologue */
#include "types.h"

extern f32 lbl_3_rodata_378[84];
extern u8 lbl_3_bss_7EE40[33216];

typedef struct CustomizeSlot {
    u8 pad[5];
    u8 field5;
    u8 tail[0x81c0 - 6];
} CustomizeSlot;

typedef struct CustomizeHead {
    u8 pad_1c[0x1c];
    s16 unk_1c;
    u8 pad_1e[0x28];
    u8 unk_46;
    u8 pad_47[0x21];
} CustomizeHead;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
CustomizeSlot *fzgx_obj_lbl_3_bss_7EDC0;
u32 lbl_3_bss_7EDC0__fzgx_offset_4;
u32 lbl_3_bss_7EDC0__fzgx_offset_8;
u32 lbl_3_bss_7EDCC__fzgx_offset_0;
u32 lbl_3_bss_7EDCC__fzgx_offset_4;
u32 lbl_3_bss_7EDCC__fzgx_offset_8;
CustomizeHead lbl_3_bss_7EDD8__fzgx_offset_0;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = (u32)fzgx_obj_lbl_3_bss_7EDC0;
    s = lbl_3_bss_7EDC0__fzgx_offset_4;
    s = lbl_3_bss_7EDC0__fzgx_offset_8;
    s = lbl_3_bss_7EDCC__fzgx_offset_0;
    s = lbl_3_bss_7EDCC__fzgx_offset_4;
    s = lbl_3_bss_7EDCC__fzgx_offset_8;
    s = lbl_3_bss_7EDD8__fzgx_offset_0.unk_46;
}
#pragma section code_type ".text"

extern void fn_1_870BC(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, f32 arg5);
extern s16 fn_3_F948(void *arg0);
extern void fn_1_87238(u32 arg0, u32 arg1, f32 arg2);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);
extern void fn_1_151BDC(void *arg0);
extern u32 fn_1_14E2DC(u32 arg0, u32 arg1, f32 arg2);

void fn_3_E5D4(void) {
    u8 work[0x440] __attribute__((aligned(32)));

    if (fzgx_obj_lbl_3_bss_7EDC0[lbl_3_bss_7EDD8__fzgx_offset_0.unk_46].field5 < 0x29) {
        fn_1_870BC(lbl_3_bss_7EDCC__fzgx_offset_0, 0, lbl_3_bss_7EDCC__fzgx_offset_0, 0, 1, ((0)[lbl_3_rodata_378]));
        if (fn_3_F948(lbl_3_bss_7EE40 + 0x20) && lbl_3_bss_7EDD8__fzgx_offset_0.unk_1c == 0) {
            fn_1_87238(lbl_3_bss_7EDCC__fzgx_offset_0, 0, lbl_3_rodata_378[0]);
        }
    } else {
        fn_80008BEC(work, 0, 0x440);
        *(u32 *)(work + 0x390) |= 0x4000000;
        *(u32 *)(work + 0x3a0) = lbl_3_bss_7EDC0__fzgx_offset_8;
        *(u32 *)(work + 0x3a4) = lbl_3_bss_7EDCC__fzgx_offset_4;
        *(u16 *)(work + 0x3ba) = 0;
        fn_1_151BDC(lbl_3_bss_7EE40);
        fn_1_14E2DC(lbl_3_bss_7EDC0__fzgx_offset_8, 0, lbl_3_rodata_378[0]);
    }
}
/* fzgx:end fn_3_E5D4 */

/* fzgx:begin fn_3_F044 */
#include "font.h"

extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;
extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_C1394(u32 *arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, u32 arg3);
extern u32 lbl_3_rodata_288[60];
extern void lbl_8006DCA4(void);
extern void lbl_8006E1D8(struct Vec3 *, f32, f32, f32);
extern void fn_1_7BCCC(struct Vec3 *);
extern void fn_80035680(struct GXLightObj *, f32, f32, f32);
extern void fn_80035690(struct GXLightObj *, f32, f32, f32);
extern void fn_80035420(struct GXLightObj *, f32, int);
extern void fn_800356AC(struct GXLightObj *, u32 *);
extern void GXInitLightDistAttn(struct GXLightObj *, f32, f32, int);
extern void fn_1_7BB80(struct GXLightObj *, int);
extern void fn_1_7BD6C(int);
extern void fn_80074CF4(f32, f32, f32);


struct fn_3_F044_Copy88 { u32 a[22]; };
struct fn_3_F044_Packet {
    u32 id;
    f32 x, y, z;
    f32 sx, sy;
    u8 pad_18[0x18];
    u32 flags;
    u8 pad_34[0x24];
};
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_3_rodata_288[60];
extern u8 lbl_3_bss_87040[33216];
extern s32 lbl_801A66B4;
extern u32 fn_1_50A90(void *, u32, u32, u32, u32);
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_4FC50(void *, u32, u16, u16, void *);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern u32 fn_1_4AEC0(u32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
#define F(off) ((off) == 0x14 ? 20.0f : (off) == 0x3c ? 0.5f : (off) == 0xf8 ? 360.0f : (off) == 0xfc ? 30.0f : (off) == 0x108 ? 0.90625f : (off) == 0x110 ? 0.9375f : (off) == 0x188 ? 354.0f : (off) == 0x18c ? 310.0f : (off) == 0x190 ? 365.0f : (off) == 0x194 ? 143.0f : (off) == 0x198 ? 19.2999f : (off) == 0x19c ? 0.01f : (off) == 0x1a0 ? 0.75f : (off) == 0x1a4 ? 351.0f : (off) == 0x1a8 ? 387.0f : (off) == 0x1ac ? 0.6f : (off) == 0x1b0 ? 0.7f : (off) == 0x1b4 ? 348.0f : 384.0f)
#define COPY() (*(struct fn_3_F044_Copy88 *)&packet = *(struct fn_3_F044_Copy88 *)&lbl_1_rodata_26F8)
struct fn_3_F044_TextEntry {
    const char *t0;
    u8 pad4[20]; const char *t0x18;
    u8 pad1c[20]; const char *t0x30;
    u8 pad34[20]; const char *t0x48;
    u8 pad4c[20]; const char *t0x60;
    u8 pad64[20]; const char *t0x78;
    u8 pad7c[20]; const char *t0x90;
};
#define TEXT(off) ((const char *)(&lbl_3_data_318C.unk_0)[lbl_801A66B4 + (off) / 4])
static inline Obj_3_bss_7EE40 *fn_3_F044_slot(u32 index) {
    u32 slot;
    slot = (u32)&lbl_3_bss_7EE40;
    slot += index * 0x2060;
    return (Obj_3_bss_7EE40 *)slot;
}
#define SLOT() fn_3_F044_slot(lbl_3_bss_7EDD8.unk_15)

#pragma section code_type ".fzgxpool"
void fzgx_fn_3_F044_pool0(volatile f32 *f, volatile f64 *d) { /* volatile: sinks keep the retail literal-pool order */
    f[0] = 50.0f; f[1] = 500.0f; f[2] = 31.2f; f[3] = 312.0f;
    f[4] = 68.0f; f[5] = 20.0f; f[6] = 96.0f; f[7] = 1.36f;
    f[8] = 161.0f; f[9] = 1.015625f; f[10] = 129.0f; f[11] = 15.0f;
    f[12] = 10.0f; f[13] = 0.0f; f[14] = 86.0f; f[15] = 0.5f;
    f[16] = 139.0f; f[17] = 75.0f; d[0] = 4503601774854144.0;
}
#pragma section code_type ".text"
const u32 fzgx_pool_table_50[3] = {0xffff0000, 0xffff0000, 0xffffff00};
/* Volatile sinks preserve the shared retail literal-pool order. */
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_1(volatile f32 *f, volatile f64 *d) { /* volatile: sinks keep the retail literal-pool order */
    f[0] = 185.000000f;
    f[1] = 180.000000f;
    f[2] = 276.000000f;
    f[3] = 116.000000f;
    f[4] = 7.00000000f;
    f[5] = 205.000000f;
    f[6] = 11.3999996f;
    f[7] = 40.0000000f;
    f[8] = 65536.0000f;
    f[9] = 60.0000000f;
    f[10] = 80.0000000f;
    f[11] = 274.000000f;
    f[12] = 0.583333313f;
    f[13] = 0.541666687f;
    f[14] = 0.458333343f;
}
#pragma section code_type ".text"
/* Volatile sinks preserve the shared retail literal-pool order. */
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_2(volatile f32 *f, volatile f64 *d) { /* volatile: sinks keep the retail literal-pool order */
    d[0] = 4503599627370496.0;
    f[2] = 320.000000f;
    f[3] = 240.000000f;
    f[4] = 5.00000000f;
    f[5] = 6.09999990f;
    f[6] = 0.800000012f;
    f[7] = 228.000000f;
    f[8] = 252.000000f;
    f[9] = 0.100000001f;
    f[10] = -30.0000000f;
    f[11] = 750.000000f;
    f[12] = 48.0000000f;
    f[13] = 660.000000f;
    f[14] = 44.0000000f;
    f[15] = 24.0000000f;
    f[16] = 302.000000f;
    f[17] = 70.0000000f;
    f[18] = 330.000000f;
    f[19] = 1.26999998f;
    f[20] = 390.000000f;
    f[21] = 308.000000f;
    f[22] = 1.00000000f;
    f[23] = 368.000000f;
    f[24] = 360.000000f;
    f[25] = 30.0000000f;
    f[26] = 0.400000006f;
    f[27] = 32768.0000f;
    f[28] = 0.906250000f;
    f[29] = 0.921875000f;
    f[30] = 0.937500000f;
}
#pragma section code_type ".text"
const u32 fzgx_pool_table_114[25] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40a00000, 0xc1700000, 0x0, 0x40200000, 0xc1700000, 0x0, 0x40a00000, 0xc1700000, 0x0, 0x40200000, 0xc1700000, 0x0, 0x0, 0x0, 0x40a00000, 0xc1700000, 0x0, 0x40200000, 0xc1700000};  /* fzgx-allow: A1 retail pool bytes */
/* Volatile sinks preserve the shared retail literal-pool order. */
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_3(volatile f32 *f, volatile f64 *d) { /* volatile: sinks keep the retail literal-pool order */
    f[0] = 55.0000000f;
    f[1] = 90000.0000f;
    f[2] = 95.0000000f;
    f[3] = 17.0000000f;
    f[4] = 354.000000f;
    f[5] = 310.000000f;
    f[6] = 365.000000f;
    f[7] = 143.000000f;
    f[8] = 19.2999001f;
    f[9] = 0.00999999978f;
    f[10] = 0.750000000f;
    f[11] = 351.000000f;
    f[12] = 387.000000f;
    f[13] = 0.600000024f;
    f[14] = 0.699999988f;
    f[15] = 348.000000f;
    f[16] = 384.000000f;
}
#pragma section code_type ".text"
#pragma opt_pointer_analysis on
void fn_3_F044(void) {
    u8 *p_lbl_3_rodata_288;
    s16 v0;
    s32 v1;
    s32 v3;
    s16 v2;
    u32 v4;
    struct fn_3_F044_Packet packet;
    p_lbl_3_rodata_288 = (u8 *)&lbl_3_rodata_288;
    v0 = lbl_3_bss_7EDD8.unk_24;
    if (v0 < -15) {
        v1 = -15;
    } else {
        v1 = v0 > 0 ? 0 : v0;
    }
    v2 = (s16)(-(v1 * 62 + 930));
    COPY();
    v3 = v2 + 82;
    packet.id = 0x8927;
    packet.x = v3;
    packet.y = F(0x188);
    packet.z = F(0xfc);
    packet.flags = 10;
    fn_1_50A90(&packet, 7, 0, 104, 104);
    v4 = lbl_3_bss_7EDD8.unk_3C;
    if (v4 < 3) {
        COPY();
        if (v4 == 0) packet.id = 0x891c;
        else if (v4 == 1) packet.id = 0x891d;
        else if (v4 == 2) packet.id = 0x891b;
        packet.x = v2 + 38;
        packet.y = F(0x18c);
        packet.z = F(0x14);
        packet.flags = 5;
        fn_1_4F734((FontDrawPacket *)&packet);
    }
    if (lbl_3_bss_7EDD8.unk_C & 0x03000000) {
        COPY();
        packet.x = v3;
        packet.y = F(0xf8);
        packet.z = F(0x14);
        packet.flags = 10;
        packet.sx = F(0x108);
        packet.sy = F(0x110);
        fn_1_4FC50(&packet, 5, 64, 64, lbl_3_bss_87040 + lbl_3_bss_7EDD8.unk_15 * 0x2060 + 0x80);
    }
    COPY();
    packet.id = 12;
    packet.x = v2 + 375;
    packet.y = F(0x190);
    packet.z = F(0xfc);
    packet.flags = 10;
    fn_1_50A90(&packet, 7, 7, 468, 74);
    COPY();
    packet.id = 12;
    packet.x = F(0x194) + (f32)v2;
    packet.y = F(0x190);
    packet.z = F(0x14);
    fn_1_51678((FontDrawPacket *)&packet, 12, 7, 22, 2, 2);
    packet.sx = F(0x198);
    packet.flags = 5;
    fn_1_4F734((FontDrawPacket *)&packet);
    if (lbl_801A66B4 == 5) {
        fn_1_4AEC0(1);
        fn_1_4954C(F(0x19c));
        fn_1_495C8(8);
        fn_1_495B0(0x80000000);
        fn_1_49590(F(0x3c));
        fn_1_4955C(F(0x1a0), F(0x1a0));
        fn_1_496FC(v2 + 178, F(0x1a4));
        fn_1_4A0D8(TEXT(0));
        fn_1_496FC(v2 + 312, F(0x1a4));
        fn_1_4A0D8(TEXT(0x18));
        fn_1_496FC(v2 + 492, F(0x1a8));
        fn_1_4A0D8(TEXT(0x30));
        fn_1_496FC(v2 + 362, F(0x1a8));
        fn_1_4A0D8(TEXT(0x48));
        fn_1_496FC(v2 + 158, F(0x1a8));
        fn_1_4955C(F(0x1ac), F(0x1b0));
        fn_1_4A0D8(TEXT(0x60));
        fn_1_496FC(v2 + 481, F(0x1a4));
        fn_1_4955C(F(0x1a0), F(0x1a0));
        if (SLOT()->unk_24 & 0x80000000)
            fn_1_4A0D8(TEXT(0x90));
        else
            fn_1_4A0D8(TEXT(0x78));
        fn_1_4AEC0(0);
    } else {
        fn_1_4954C(F(0x19c));
        fn_1_495C8(8);
        fn_1_495B0(0x80000000);
        fn_1_49590(F(0x3c));
        fn_1_4955C(F(0x1ac), F(0x1ac));
        fn_1_496FC(v2 + 163, F(0x1b4));
        fn_1_4A0D8(TEXT(0));
        fn_1_496FC(v2 + 340, F(0x1b4));
        fn_1_4A0D8(TEXT(0x18));
        fn_1_496FC(v2 + 521, F(0x1b8));
        fn_1_4A0D8(TEXT(0x30));
        fn_1_496FC(v2 + 432, F(0x1b8));
        fn_1_4A0D8(TEXT(0x48));
        fn_1_496FC(v2 + 150, F(0x1b8));
        fn_1_4A0D8(TEXT(0x60));
        fn_1_496FC(v2 + 500, F(0x1b4));
        if (SLOT()->unk_24 & 0x80000000)
            fn_1_4A0D8(TEXT(0x90));
        else
            fn_1_4A0D8(TEXT(0x78));
    }
}
/* fzgx:end fn_3_F044 */

/* fzgx:begin fn_3_F878 */
struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct GXLightObj {
    u32 dummy[16];
};

struct CustomizeData {
    u8 pad34[0x34];
    f32 value34;
    u8 pad1ac[0x174];
    f32 value1ac;
    u8 pad1bc[0xc];
    u32 value1bc;
    f32 value1c0;
};

void fn_3_F878(void) {
    struct GXLightObj second;
    struct Vec3 first;
    u32 value;
    f32 scale;
    struct CustomizeData *data;

    data = (struct CustomizeData *)lbl_3_rodata_288;
    lbl_8006DCA4();
    scale = data->value1c0;
    lbl_8006E1D8(&first, scale, scale, scale);
    fn_1_7BCCC(&first);
    fn_80035680(&second, first.x, first.y, first.z);
    fn_80035690(&second, first.x, first.y, first.z);
    fn_80035420(&second, data->value34, 0);
    value = data->value1bc;
    fn_800356AC(&second, &value);
    GXInitLightDistAttn(&second, data->value34, data->value34, 0);
    fn_1_7BB80(&second, 1);
    fn_1_7BD6C(1);
    scale = data->value1ac;
    fn_80074CF4(scale, scale, scale);
}
/* fzgx:end fn_3_F878 */

/* fzgx:begin fn_3_F948 */
typedef struct MemCardSlot {
    u32 unk0;
    u32 flags;
    u8 pad[0x2058];
} MemCardSlot;

s16 fn_3_F948(MemCardSlot *slot) {
    s16 i;
    s16 count = 0;
    i = 0;

    while (i < 4) {
        if (slot->flags & (1u << 31)) {
            count++;
        }
        slot++;
        i++;
    }
    return count;
}
/* fzgx:end fn_3_F948 */

/* fzgx:begin fn_3_11FD0 */
u32 fn_3_11FD0(u32 index, u32 value) {
    return ((u32 *)(lbl_3_data_2F78 + (__cntlzw(value) * 24)))[index];
}
/* fzgx:end fn_3_11FD0 */

/* fzgx:begin fn_3_12910 noprologue */
#include "types.h"

struct fn_3_12910_tbl_ent {
    u8 pad_0[0x8];
    u32 unk_8;
};
struct fn_3_12910_glb {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[0xE];
    s16 unk_22;
    s16 unk_24;
};

extern u8 lbl_3_bss_7EDD8[52];
extern u8 lbl_3_data_3234[168];

#pragma opt_dead_assignments off
void fn_3_12910(void) {
    struct fn_3_12910_glb *p;
    struct fn_3_12910_tbl_ent *t;
    u32 f;
    u32 idx;

    t = (struct fn_3_12910_tbl_ent *)lbl_3_data_3234;
    p = (struct fn_3_12910_glb *)lbl_3_bss_7EDD8;
    idx = __cntlzw(p->unk_C);
    ((void (*)(void))(*(u32 *)((u8 *)lbl_3_data_3234 + idx * 12 + 8)))();

    f = p->unk_C;
    if (!(f & 0x80000000)) {
        if (f & 0x2000000) {
            s32 v = ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 - 1;

            ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 = (v < -15) ? -15 : ((v > 30) ? 30 : v);
        } else if (f & 0x1000000) {
            if (((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_10 & 0x2000000) {
                s32 v = ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 + 1;

                ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 = (v < -15) ? -15 : ((v > 0) ? 0 : v);
            } else {
                s32 v = ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 - 1;

                ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 = (v < 0) ? 0 : ((v > 30) ? 30 : v);
            }
        } else if (f & 0x400000) {
            s32 v = ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 - 1;

            ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 = (v < 0) ? 0 : ((v > 30) ? 30 : v);
        } else if (!(f & 0x800000)) {
            s32 v = ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 + 1;

            ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_24 = (v < -15) ? -15 : ((v > 30) ? 30 : v);
        }

        f = p->unk_C;
        if (f & 0x40000000) {
            s32 v = ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_22 - 1;

            ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_22 = (v < 0) ? 0 : ((v > 10) ? 10 : v);
        } else if (f & 0x20000000) {
            s32 v = ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_22 + 1;

            ((struct fn_3_12910_glb *)lbl_3_bss_7EDD8)->unk_22 = (v < 0) ? 0 : ((v > 10) ? 10 : v);
        }
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_3_12910 */

/* fzgx:begin fn_3_12E4C */
typedef struct { u32 x; u32 y; u32 z; } Vec3;
typedef struct { u32 unused0; u32 unused1; Vec3 first; Vec3 second; } Data;
typedef struct { u8 pad_000[0x508]; Vec3 first; Vec3 second; } SpecialData;
typedef struct {
    u8 pad_000[0x328];
    s8 state;
    u8 pad_329[0x67];
    u32 flags;
    u8 pad_394[0xc];
    s16 *indices;
} Customize;

#pragma opt_strength_reduction off
#pragma opt_common_subs off
void fn_3_12E4C(Customize *self, u8 index, Vec3 *first, Vec3 *second) {
    Data *data;
    SpecialData *special;
    u8 state;

    if (self->flags & 0x04000000) {
        data = (Data *)(*(u8 (*)[2400])&lbl_3_data_246C);
        data = (Data *)((u8 *)data +
                        ((u8)((self->indices)[(u32)index * 0x1b0]) << 5));
        *first = data->first;
        *second = data->second;
        return;
    }

    state = self->state;
    if (state == 4) {
        if (index != 0) {
            data = (Data *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + 0x560);
            *first = data->first;
            *second = data->second;
            return;
        }
        data = (Data *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + ((u8)state << 5));
        *first = data->first;
        *second = data->second;
        return;
    }

    if ((u8)state == 0x28) {
        special = (SpecialData *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + ((u8)index << 5));
        *first = special->first;
        *second = special->second;
        return;
    }

    data = (Data *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + ((u8)state << 5));
    *first = data->first;
    *second = data->second;
}
#pragma opt_common_subs reset

#pragma opt_strength_reduction reset
/* fzgx:end fn_3_12E4C */

/* fzgx:begin fn_3_12FD4 */
struct fn_3_12FD4_Arg3 {
    f32 unk_0;
};
struct fn_3_12FD4_Arg4 {
    f32 unk_0;
};

struct fn_3_12FD4_Record {
    f32 x;
    f32 y;
    u8 pad[24];
};

void fn_3_12FD4(u32 arg0, u32 arg1, u32 arg2, struct fn_3_12FD4_Arg3 *arg3, struct fn_3_12FD4_Arg4 *arg4) {
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    if (__rlwnm(arg0, 6, 31, 31)) {
        v1 = ((arg2 & 0xFF) << 5);
        arg3->unk_0 = *(f32 *)((u8 *)&lbl_3_data_246C + v1);
        arg4->unk_0 = *(f32 *)((u32)&lbl_3_data_246C + v1 + 4);
        return;
    }
    v2 = (arg2 & 0xFF);
    v3 = arg2;
    if (v2 == 4) {
        v3 = 43;
    } else {
        if (v2 == 40) {
            v3 = ((arg1 + 40) & 0xFF);
        }
    }
    v4 = ((v3 & 0xFF) << 5);
    arg3->unk_0 = *(f32 *)((u8 *)&lbl_3_data_1EEC + v4);
    arg4->unk_0 = *(f32 *)((u32)&lbl_3_data_1EEC + v4 + 4);
    return;
}
/* fzgx:end fn_3_12FD4 */
