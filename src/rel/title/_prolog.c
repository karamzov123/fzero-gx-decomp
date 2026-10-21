#include "types.h"
#include "rel/title/globals.h"
extern u32 fn_1_D0790(void);
extern u8 lbl_8_bss_230;
extern struct fn_8_784_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern struct fn_8_784_lbl_8_bss_22C lbl_8_bss_22C;
extern u32 fn_1_5370(u32, u32);
extern u32 fn_1_A1588(u32, u32);
extern u32 lbl_8_bss_228;
extern void fn_8_4D8(void);
extern int fn_8_6FC(void);
extern void fn_8_704(void);
extern s32 fn_8_754(void);

/* fzgx:begin fn_8_4D8 noprologue */
#include "types.h"
#include "rel/title/globals.h"

struct fn_8_784_lbl_8_bss_22C {
    u32 unk_0;
};

struct fn_8_784_lbl_1_bss_6EAD0 {
    u32 unk_0;
};
extern u32 lbl_8_bss_228;
extern struct fn_8_784_lbl_8_bss_22C lbl_8_bss_22C;
extern f32 lbl_8_rodata_0[];
extern u8 lbl_1_bss_9C8[];
extern u8 lbl_1_bss_9F8[];
extern u8 lbl_1_bss_8B3A0[];
extern void fn_1_49410(void);
extern void fn_1_495C8(u8 value);
extern void fn_1_495FC(void);
extern void fn_1_4954C(f32 value);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4A0D8(const char *);
extern void fn_1_49614(void);
extern u8 fn_8_1304__fzgx_offset_0[];
extern u8 fn_8_1344__fzgx_offset_0[];
extern u8 fn_8_1394__fzgx_offset_0[];
extern u8 fn_8_1C08__fzgx_offset_0[];
extern u8 fn_8_1C0C__fzgx_offset_0[];
extern u8 fn_8_1C10__fzgx_offset_0[];
extern u8 fn_8_1C14__fzgx_offset_0[];
extern u8 fn_8_1C18__fzgx_offset_0[];
extern u8 fn_8_1C90__fzgx_offset_0[];
extern u8 fn_8_1F64__fzgx_offset_0[];
extern u8 fn_8_1F74__fzgx_offset_0[];
extern u8 fn_8_1FB0__fzgx_offset_0[];
extern u8 fn_8_2120__fzgx_offset_0[];
extern u8 fn_8_25F8__fzgx_offset_0[];
extern u8 fn_8_2660__fzgx_offset_0[];
extern u8 fn_8_4E8C__fzgx_offset_0[];
extern u8 fn_8_4E90__fzgx_offset_0[];
extern u8 fn_8_4F64__fzgx_offset_0[];
extern u8 fn_8_516C__fzgx_offset_0[];
extern u8 fn_8_520C__fzgx_offset_0[];
extern u8 fn_8_5210__fzgx_offset_0[];
extern u8 fn_8_5214__fzgx_offset_0[];
extern u8 fn_8_5218__fzgx_offset_0[];
extern u8 fn_8_530C__fzgx_offset_0[];
extern u8 fn_8_5514__fzgx_offset_0[];
extern u8 fn_8_55CC__fzgx_offset_0[];
extern u8 fn_8_5608__fzgx_offset_0[];
extern u8 fn_8_5810__fzgx_offset_0[];
extern u8 fn_8_5B44__fzgx_offset_0[];
extern u8 fn_8_5C4C__fzgx_offset_0[];
extern u8 fn_8_5C50__fzgx_offset_0[];
extern u8 fn_8_BD8__fzgx_offset_0[];
extern u8 fn_8_BDC__fzgx_offset_0[];
extern u8 fn_8_BE0__fzgx_offset_0[];
extern u8 fn_8_BE4__fzgx_offset_0[];
extern u8 fn_8_EC4__fzgx_offset_0[];
extern u8 lbl_8_data_0__fzgx_offset_0[];
extern u8 lbl_8_data_108__fzgx_offset_0[];
extern u8 lbl_8_data_10__fzgx_offset_0[];
extern u8 lbl_8_data_118__fzgx_offset_0[];
extern u8 lbl_8_data_120__fzgx_offset_0[];
extern u8 lbl_8_data_12C__fzgx_offset_0[];
extern u8 lbl_8_data_134__fzgx_offset_0[];
extern u8 lbl_8_data_140__fzgx_offset_0[];
extern u8 lbl_8_data_150__fzgx_offset_0[];
extern u8 lbl_8_data_15C__fzgx_offset_0[];
extern u8 lbl_8_data_168__fzgx_offset_0[];
extern u8 lbl_8_data_170__fzgx_offset_0[];
extern u8 lbl_8_data_184__fzgx_offset_0[];
extern u8 lbl_8_data_194__fzgx_offset_0[];
extern u8 lbl_8_data_1A4__fzgx_offset_0[];
extern u8 lbl_8_data_1B0__fzgx_offset_0[];
extern u8 lbl_8_data_1BC__fzgx_offset_0[];
extern u8 lbl_8_data_1CC__fzgx_offset_0[];
extern u8 lbl_8_data_1C__fzgx_offset_0[];
extern u8 lbl_8_data_1D4__fzgx_offset_0[];
extern u8 lbl_8_data_1E0__fzgx_offset_0[];
extern u8 lbl_8_data_1E8__fzgx_offset_0[];
extern u8 lbl_8_data_1F0__fzgx_offset_0[];
extern u8 lbl_8_data_1F8__fzgx_offset_0[];
extern u8 lbl_8_data_28__fzgx_offset_0[];
extern u8 lbl_8_data_2B4__fzgx_offset_0[];
extern u8 lbl_8_data_2BC__fzgx_offset_0[];
extern u8 lbl_8_data_2C4__fzgx_offset_0[];
extern u8 lbl_8_data_2CC__fzgx_offset_0[];
extern u8 lbl_8_data_2D4__fzgx_offset_0[];
extern u8 lbl_8_data_2DC__fzgx_offset_0[];
extern u8 lbl_8_data_2E4__fzgx_offset_0[];
extern u8 lbl_8_data_2EC__fzgx_offset_0[];
extern u8 lbl_8_data_2F8__fzgx_offset_0[];
extern u8 lbl_8_data_300__fzgx_offset_0[];
extern u8 lbl_8_data_308__fzgx_offset_0[];
extern u8 lbl_8_data_310__fzgx_offset_0[];
extern u8 lbl_8_data_34__fzgx_offset_0[];
extern u8 lbl_8_data_3C__fzgx_offset_0[];
extern u8 lbl_8_data_44__fzgx_offset_0[];
extern u8 lbl_8_data_4C__fzgx_offset_0[];
extern u8 lbl_8_data_4__fzgx_offset_0[];
extern u8 lbl_8_data_54__fzgx_offset_0[];
extern u8 lbl_8_data_60__fzgx_offset_0[];
extern u8 lbl_8_data_70__fzgx_offset_0[];
extern u8 lbl_8_data_80__fzgx_offset_0[];
extern u8 lbl_8_data_88__fzgx_offset_0[];
extern u8 lbl_8_data_90__fzgx_offset_0[];
extern u8 lbl_8_data_9C__fzgx_offset_0[];
extern u8 lbl_8_data_A8__fzgx_offset_0[];
extern u8 lbl_8_data_B8__fzgx_offset_0[];
extern u8 lbl_8_data_C0__fzgx_offset_0[];
extern u8 lbl_8_data_CC__fzgx_offset_0[];
extern u8 lbl_8_data_D8__fzgx_offset_0[];
extern u8 lbl_8_data_E8__fzgx_offset_0[];
extern u8 lbl_8_data_F0__fzgx_offset_0[];
extern u8 lbl_8_data_FC__fzgx_offset_0[];
extern void fn_1_D0790(void);
extern u8 lbl_8_bss_230;
extern struct fn_8_784_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern s8 fn_1_5370(s8 arg0, s16 arg1);
extern u32 fn_1_A1588(u32, u32);
extern int fn_8_4D8(u32 *obj);
extern int fn_8_6FC(void);
extern void fn_8_704(void);
extern s32 fn_8_754(void);

typedef struct {
    s16 wait;
    s16 cmd;
} TitleStep;

typedef struct {
    u8 pad_0[0x3d8];
    TitleStep steps[2];
    char text1[12];     /* 0x3e0 */
    char text2[20];     /* 0x3ec */
    char text3[16];     /* 0x400 */
    char text4[12];     /* 0x410 */
    char text5[12];     /* 0x41c */
} TitleData;


#pragma opt_propagation off
static u32 fzgx_pool_data_lbl_8_data_0[246] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156,
    0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x0, 0x54455354,
    0x0, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000,
    0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000,
    0x554E4C49, 0x4E4B0000, 0x434F494E, 0x0, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C,
    0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000,
    0x454E5452, 0x595F4F4B, 0x0, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348,
    0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552,
    0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500,
    0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000,
    0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x0, 0x4C494E4B,
    0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152,
    0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x0, 0x4C494E4B, 0x44454C49, 0x56455259,
    0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552,
    0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900,
    0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x0, 0x50415553, 0x45000000, 0x4552524F, 0x52000000,
    (u32)lbl_8_data_0__fzgx_offset_0, (u32)lbl_8_data_4__fzgx_offset_0, (u32)lbl_8_data_10__fzgx_offset_0, (u32)lbl_8_data_1C__fzgx_offset_0, (u32)lbl_8_data_28__fzgx_offset_0, (u32)lbl_8_data_34__fzgx_offset_0, (u32)lbl_8_data_3C__fzgx_offset_0, (u32)lbl_8_data_44__fzgx_offset_0,
    (u32)lbl_8_data_4C__fzgx_offset_0, (u32)lbl_8_data_54__fzgx_offset_0, (u32)lbl_8_data_60__fzgx_offset_0, (u32)lbl_8_data_70__fzgx_offset_0, (u32)lbl_8_data_80__fzgx_offset_0, (u32)lbl_8_data_88__fzgx_offset_0, (u32)lbl_8_data_90__fzgx_offset_0, (u32)lbl_8_data_9C__fzgx_offset_0,
    (u32)lbl_8_data_A8__fzgx_offset_0, (u32)lbl_8_data_B8__fzgx_offset_0, (u32)lbl_8_data_C0__fzgx_offset_0, (u32)lbl_8_data_CC__fzgx_offset_0, (u32)lbl_8_data_D8__fzgx_offset_0, (u32)lbl_8_data_E8__fzgx_offset_0, (u32)lbl_8_data_F0__fzgx_offset_0, (u32)lbl_8_data_FC__fzgx_offset_0,
    (u32)lbl_8_data_108__fzgx_offset_0, (u32)lbl_8_data_118__fzgx_offset_0, (u32)lbl_8_data_120__fzgx_offset_0, (u32)lbl_8_data_12C__fzgx_offset_0, (u32)lbl_8_data_134__fzgx_offset_0, (u32)lbl_8_data_140__fzgx_offset_0, (u32)lbl_8_data_150__fzgx_offset_0, (u32)lbl_8_data_15C__fzgx_offset_0,
    (u32)lbl_8_data_168__fzgx_offset_0, (u32)lbl_8_data_170__fzgx_offset_0, (u32)lbl_8_data_184__fzgx_offset_0, (u32)lbl_8_data_194__fzgx_offset_0, (u32)lbl_8_data_1A4__fzgx_offset_0, (u32)lbl_8_data_1B0__fzgx_offset_0, (u32)lbl_8_data_1BC__fzgx_offset_0, (u32)lbl_8_data_1CC__fzgx_offset_0,
    (u32)lbl_8_data_1D4__fzgx_offset_0, (u32)lbl_8_data_1E0__fzgx_offset_0, (u32)lbl_8_data_1E8__fzgx_offset_0, (u32)lbl_8_data_1F0__fzgx_offset_0, (u32)lbl_8_data_1F8__fzgx_offset_0, 0x70726F67, 0x0, 0x6D656D63,
    0x61726400, 0x7469746C, 0x65000000, 0x64656D6F, 0x0, 0x6D656E75, 0x0, 0x6C6F676F,
    0x0, 0x7761726E, 0x696E6700, 0x6F706572, 0x6174696F, 0x6E000000, 0x72617469, 0x6E670000,
    0x63617264, 0x0, 0x72616E6B, 0x696E6700, 0x6D6F7669, 0x65000000, (u32)lbl_8_data_2B4__fzgx_offset_0, (u32)fn_8_1F74__fzgx_offset_0,
    (u32)fn_8_1FB0__fzgx_offset_0, (u32)fn_8_2120__fzgx_offset_0, (u32)lbl_8_data_2BC__fzgx_offset_0, (u32)fn_8_25F8__fzgx_offset_0, (u32)fn_8_2660__fzgx_offset_0, (u32)fn_8_4E8C__fzgx_offset_0, (u32)lbl_8_data_2C4__fzgx_offset_0, (u32)fn_8_1C18__fzgx_offset_0,
    (u32)fn_8_1C90__fzgx_offset_0, (u32)fn_8_1F64__fzgx_offset_0, (u32)lbl_8_data_2CC__fzgx_offset_0, (u32)fn_8_1344__fzgx_offset_0, (u32)fn_8_1394__fzgx_offset_0, (u32)fn_8_1C08__fzgx_offset_0, (u32)lbl_8_data_2D4__fzgx_offset_0, (u32)fn_8_1C0C__fzgx_offset_0,
    (u32)fn_8_1C10__fzgx_offset_0, (u32)fn_8_1C14__fzgx_offset_0, (u32)lbl_8_data_2DC__fzgx_offset_0, (u32)fn_8_BE4__fzgx_offset_0, (u32)fn_8_EC4__fzgx_offset_0, (u32)fn_8_1304__fzgx_offset_0, (u32)lbl_8_data_2E4__fzgx_offset_0, (u32)fn_8_BD8__fzgx_offset_0,
    (u32)fn_8_BDC__fzgx_offset_0, (u32)fn_8_BE0__fzgx_offset_0, (u32)lbl_8_data_2EC__fzgx_offset_0, (u32)fn_8_4E90__fzgx_offset_0, (u32)fn_8_4F64__fzgx_offset_0, (u32)fn_8_516C__fzgx_offset_0, (u32)lbl_8_data_2F8__fzgx_offset_0, (u32)fn_8_520C__fzgx_offset_0,
    (u32)fn_8_5210__fzgx_offset_0, (u32)fn_8_5214__fzgx_offset_0, (u32)lbl_8_data_300__fzgx_offset_0, (u32)fn_8_5218__fzgx_offset_0, (u32)fn_8_530C__fzgx_offset_0, (u32)fn_8_5514__fzgx_offset_0, (u32)lbl_8_data_308__fzgx_offset_0, (u32)fn_8_55CC__fzgx_offset_0,
    (u32)fn_8_5608__fzgx_offset_0, (u32)fn_8_5810__fzgx_offset_0, (u32)lbl_8_data_310__fzgx_offset_0, (u32)fn_8_5B44__fzgx_offset_0, (u32)fn_8_5C4C__fzgx_offset_0, (u32)fn_8_5C50__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_8_data_0_3D8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x2B200000, 0x12C0006
};
static u32 fzgx_pool_data_lbl_8_data_0_3E0[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E494E54, 0x454E444F, 0x0
};
static u32 fzgx_pool_data_lbl_8_data_0_3EC[5] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x414D5553, 0x454D454E, 0x54205649, 0x53494F4E, 0x0
};
static u32 fzgx_pool_data_lbl_8_data_0_400[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x462D5A45, 0x524F2066, 0x6F722047, 0x43000000
};
static u32 fzgx_pool_data_lbl_8_data_0_410[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x57454C43, 0x4F4D4520, 0x544F0000
};
static u32 fzgx_pool_data_lbl_8_data_0_41C[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4F564552, 0x20323030, 0x306B6D2F, 0x6820574F, 0x524C4421, 0x0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_8_data_0(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_8_data_0;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_0_3D8;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_0_3E0;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_0_3EC;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_0_400;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_0_410;
    s = *(u8 *)fzgx_pool_data_lbl_8_data_0_41C;
}
#pragma section code_type ".text"

int fn_8_4D8(u32 *obj) {
    
    f32 *pool = (f32 *)lbl_8_rodata_0;
#define steps ((s16 *)fzgx_pool_data_lbl_8_data_0_3D8)  /* {wait, cmd} pairs */
    s16 *cmds;
    s16 cmd;

    if ((*((s32 *)&lbl_8_bss_228)) != 0) {
        (*((s32 *)&lbl_8_bss_228))--;
    } else {
        (*((s32 *)&lbl_8_bss_22C))++;
        (*((s32 *)&lbl_8_bss_228)) = steps[(*((s32 *)&lbl_8_bss_22C)) * 2];
    }

    cmds = &steps[1];
    cmd = cmds[(*((s32 *)&lbl_8_bss_22C)) * 2];
    if (cmd == 6) {
        *obj &= ~4;
        return 2;
    }
    if (cmd == 0) {
        *obj &= ~4;
    } else {
        *obj |= 4;
        fn_1_49410();
        fn_1_495C8(9);
        fn_1_495FC();
        fn_1_4954C(pool[14]);
        switch (cmds[(*((s32 *)&lbl_8_bss_22C)) * 2]) {
        case 1:
            fn_1_496FC(pool[0], pool[7]);
            fn_1_4A0D8(((char *)(((u8 *)fzgx_pool_data_lbl_8_data_0_3E0))));
            break;
        case 2:
            fn_1_496FC(pool[0], pool[15]);
            fn_1_4A0D8(((char *)(((u8 *)fzgx_pool_data_lbl_8_data_0_3EC))));
            break;
        case 3:
            fn_1_496FC(pool[0], pool[16]);
            fn_1_4A0D8(((char *)(((u8 *)fzgx_pool_data_lbl_8_data_0_400))));
            break;
        case 4:
            fn_1_496FC(pool[0], pool[7]);
            fn_1_4A0D8(((char *)(((u8 *)fzgx_pool_data_lbl_8_data_0_3E0))));
            fn_1_496FC(pool[0], pool[16]);
            fn_1_4A0D8(((char *)(((u8 *)fzgx_pool_data_lbl_8_data_0_400))));
            fn_1_496FC(pool[0], pool[15]);
            fn_1_4A0D8(((char *)(((u8 *)fzgx_pool_data_lbl_8_data_0_3EC))));
            break;
        case 5:
            fn_1_496FC(pool[0], pool[17]);
            fn_1_4A0D8(((char *)(((u8 *)fzgx_pool_data_lbl_8_data_0_410))));
            fn_1_496FC(pool[0], pool[16]);
            fn_1_4A0D8(((char *)(((u8 *)fzgx_pool_data_lbl_8_data_0_41C))));
            break;
        }
        fn_1_49614();
    }

    {
        u8 *a = lbl_1_bss_9C8;
        u8 *b = lbl_1_bss_9F8;
        u8 zero = 0;

        if ((s8)a[0xa] == 0 && (*(u16 *)(b + 8) & 0x1000)) {
            lbl_1_bss_8B3A0[0x9e] = zero;
        }
    }
    return 0;
}
/* fzgx:end fn_8_4D8 */

/* fzgx:begin fn_8_6FC */
// fn_8_6FC: returns a constant.
int fn_8_6FC(void) {
    return 0;
}
/* fzgx:end fn_8_6FC */

/* fzgx:begin fn_8_754 */
s32 fn_8_754(void) {
    lbl_8_bss_230 = 0;
    fn_1_D0790();
    return 0;
}
/* fzgx:end fn_8_754 */

/* fzgx:begin fn_8_784 */
struct fn_8_784_lbl_8_bss_22C {
    u32 unk_0;
};
struct fn_8_784_lbl_1_bss_6EAD0 {
    u32 unk_0;
};

void fn_8_784(u32 arg0) {
    *(u32 *)((u8 *)arg0 + 168) = (u32)fn_8_4D8;
    *(u32 *)((u8 *)arg0 + 196) = (u32)fn_8_704;
    *(u32 *)((u8 *)arg0 + 204) = (u32)fn_8_6FC;
    *(u32 *)((u8 *)arg0 + 172) = (u32)fn_8_754;
    lbl_8_bss_228 = 0;
    lbl_8_bss_22C.unk_0 = -1;
    fn_1_5370(1, 0);
    *(u32 *)((u8 *)arg0 + 0) = ((*(u32 *)((u8 *)arg0 + 0) | 0x8200000) | 33033);
    fn_1_A1588(*(u32 *)((u8 *)lbl_1_bss_6EAD0.unk_0 + 0), 1);
}
/* fzgx:end fn_8_784 */
