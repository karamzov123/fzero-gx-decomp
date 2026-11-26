#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"

typedef struct FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams;

typedef struct fn_1_4EB74_FontObject {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject;

typedef struct fn_1_54668_node {
    struct fn_1_54668_node *next;
    void *data;
} fn_1_54668_node;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct fn_1_547F8_node {
    struct fn_1_547F8_node *next;
    void (*callback)(struct fn_1_547F8_node *);
} fn_1_547F8_node;

typedef struct fn_1_563E4_FontState {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState;

typedef struct State {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State;

typedef struct Config {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config;

typedef struct ImageInfo {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo;

typedef struct Images {
    u32 unk_0;
    ImageInfo *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images;

typedef struct Resource {
    s32 loaded;
    u8 unk_4[0x1c];
    Images *images;
    u32 unk_24;
} Resource;

struct fn_1_530C8_lbl_1_rodata_282C {
    f32 unk_0;
};

struct FzgxCopy_88 { u32 words[22]; };
extern void *lbl_801A6D00;
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void OSReport(const char *format, ...);
extern f32 fn_1_4B1D4(s32 mode, u8 *text);
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_FD0[];
extern u8 *lbl_801A66CC;
extern void fn_1_4E500(void);
extern void fn_1_48D80(void *value);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(FontParams *arg);
extern s32 fn_1_4B16C(s32 value);
extern void mathutil_mtxA_rotate_z(s16 arg0);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern const f32 lbl_1_rodata_10D4;
extern void fn_1_4955C(f32 value1, f32 value2);
extern f32 lbl_1_rodata_10C0[5];
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern f32 lbl_1_rodata_26B8[16];
extern void fn_1_4D10C(void *data, f32 scale, f32 value);
extern void fn_1_4D2AC(void *data, f32 scale, f32 value);
extern f32 lbl_1_rodata_26F8[22];
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern f32 fn_1_51B84(f32 value);
extern f32 fn_1_51BFC(f32 value);

/* fzgx:begin fn_1_487EC noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bitmap.h"

extern s32 lbl_801A6410;
extern u32 lbl_801A66B4;
extern u8 lbl_1_bss_3E000[32];
extern u32 lbl_1_bss_3E020;
extern u8 lbl_1_bss_3E024[52];
extern char lbl_1_data_1A364[4];
extern char lbl_1_data_1A3AC[5];
extern u8 lbl_1_data_19098[0x2F0];
extern u8 lbl_1_data_19FC4[0x2F0];
extern f32 lbl_1_rodata_10C0[5];
extern f32 lbl_1_bss_3E05C;

extern void OSPanic(const void *, ...);
extern void fn_1_465D0(char *, s32);
extern int fn_1_45D0();
extern int fn_80008F88(int, int);
extern void fn_8006FDEC(void);
extern void fn_80009064(u32 value);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, s32 arg3);
extern void fn_1_4DDC0(void);
extern void fn_1_4F724(void);
extern void strcpy(void *arg0, void *arg1);
extern s32 fn_1_45730(void *, void *);
extern size_t strlen(const char *);
extern s32 strncmp(const char *, const char *, size_t);
extern u32 OSGetArenaHi(void);
extern void OSSetArenaHi(u32);
extern u32 OSAllocFromArenaLo(u32, u32);
extern u32 OSAllocFromArenaHi(u32, u32);
extern s32 fn_1_45B2C(void *);
extern s32 fn_1_458A0(void *, void *, u32, u32);
extern s32 fn_1_45850(void *);
extern u32 fn_1_12860(u32, u32);
extern u32 fn_1_12F78(void *, u32);
extern void DCFlushRange(void *, u32);

typedef enum { GX_TF_I4, GX_TF_I8, GX_TF_IA4, GX_TF_IA8, GX_TF_RGB565, GX_TF_RGB5A3, GX_TF_RGBA8, GX_TF_CMPR=14 } GXTexFmt;
typedef struct { u32 dummy[8]; } GXTexObj;
typedef enum { GX_CLAMP, GX_REPEAT, GX_MIRROR, GX_MAX_TEXWRAPMODE } GXTexWrapMode;
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, GXTexFmt, GXTexWrapMode, GXTexWrapMode, u8);
extern void GXInvalidateTexAll(void);

s32 fn_1_47AD4(BitmapResource *arg0, s32 arg1, s32 arg2, s32 arg3);
void fn_1_48214(s32 index, s32 enabled);
void fn_1_48418(int index);
void fn_1_484CC(s32 index);
void *fn_1_48730(u32 value);
void fn_1_4877C(void);

extern int fn_1_48A0C(int ch, int idx, Obj_1_data_1AEA8 *font, int noLoad);

typedef struct {
    s32 unk_0;
    u8 pad_4[0x28];
    u16 *unk_2C;
    s16 *unk_30;
    f32 unk_34;
} BitmapGroup;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3E058;
f32 fzgx_obj_lbl_1_bss_3E05C;
u32 fzgx_obj_lbl_1_bss_3E060[0x56B];
s32 lbl_1_bss_3F60C__fzgx_offset_0[0x56B];
s32 lbl_1_bss_3F60C__fzgx_offset_15AC;
s32 fzgx_obj_lbl_1_bss_40BBC[0x2C];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3E058;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3E05C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3E060;
    s = *(u8 *)&lbl_1_bss_3F60C__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_3F60C__fzgx_offset_15AC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_40BBC;
}
#pragma section code_type ".text"

static inline void reset_bitmap_groups(s32 zero, BitmapGroup **group, u16 **p) {
    s32 j;
    s32 *count;
    s32 k;

    lbl_1_bss_3F60C__fzgx_offset_15AC = zero;
    count = fzgx_obj_lbl_1_bss_40BBC;
    for (j = zero; j < 0x2C; count++, j++, (*group)++) {
        *count = zero;
        if ((*group)->unk_0 == -1) {
            *p = (*group)->unk_2C;
            k = 0;
            while (**p != 0) {
                *(s16 *)((u8 *)(*group)->unk_30 + k) = -1;
                (*p)++;
                k += 2;
                (*count)++;
            }
        }
    }
}

void fn_1_487EC(void) {
    s32 *count;
    s32 j;
    BitmapGroup *group;
    s32 i;
    BitmapGroup *target;
    s32 n;
    u16 key;
    u16 *q;
    u16 *p;
    s32 k;

    for (i = 0; i < 0x56B; i++) {
        fzgx_obj_lbl_1_bss_3E060[i] = 0;
        lbl_1_bss_3F60C__fzgx_offset_0[i] = -1;
    }

    /* count the entries of every terminator-marked group and reset their slots */
    group = (BitmapGroup *)&lbl_1_data_1AEA8;
    reset_bitmap_groups(0, &group, &p);

    target = (BitmapGroup *)&lbl_1_data_1AEA8 + 42;
    for (i = 0; i < 0x56B; i++) {
        key = ((u16 *)&lbl_1_data_1A3B8)[i];
        n = 0;
        q = target->unk_2C;
        while (*q != 0) {
            if (*q == key && fn_1_48A0C(n, 0x2A, (Obj_1_data_1AEA8 *)target, 1) != 0) {
                lbl_1_bss_3F60C__fzgx_offset_15AC++;
                break;
            }
            n++;
            q++;
        }
    }
}
/* fzgx:end fn_1_487EC */

/* fzgx:begin fn_1_48A0C noprologue */
extern s32 lbl_801A6410;
extern u32 lbl_1_bss_3E060[1387];
extern u32 lbl_1_bss_3F60C[1388];
extern u8 lbl_1_bss_40C6C[44384];


extern u32 OSAllocFromArenaLo(u32, u32);
extern u32 fn_1_4BA24(u8, int, void *);

// Allocate (or share) the glyph texture for character `ch` of font slot `idx`.
// Returns 1 when a new texture was created, 0 otherwise.
extern u8 lbl_1_bss_4BB9C__fzgx_offset_0[];
extern u8 lbl_1_bss_4BBA0__fzgx_offset_0[];
extern u8 lbl_1_data_1A3B8__fzgx_offset_0[];
extern u8 lbl_1_data_1AE90__fzgx_offset_0[];
extern u8 lbl_1_data_1AE94__fzgx_offset_0[];
extern u8 lbl_1_data_1AE9C__fzgx_offset_0[];
extern u8 lbl_1_data_1B848__fzgx_offset_0[];
extern u8 lbl_1_data_1B860__fzgx_offset_0[];
extern u8 lbl_1_data_1B878__fzgx_offset_0[];
extern u8 lbl_1_data_1B888__fzgx_offset_0[];
extern u8 lbl_1_data_1B898__fzgx_offset_0[];
extern u8 lbl_1_data_1B8A8__fzgx_offset_0[];
extern u8 lbl_1_data_1B8B8__fzgx_offset_0[];
extern u8 lbl_1_data_1B8CC__fzgx_offset_0[];
extern u8 lbl_1_data_1B8E0__fzgx_offset_0[];
extern u8 lbl_1_data_1B8F4__fzgx_offset_0[];
extern u8 lbl_1_data_1B908__fzgx_offset_0[];
extern u8 lbl_1_data_1B920__fzgx_offset_0[];
extern u8 lbl_1_data_1B934__fzgx_offset_0[];
extern u8 lbl_1_data_1B948__fzgx_offset_0[];
extern u8 lbl_1_data_1B95C__fzgx_offset_0[];
extern u8 lbl_1_data_1B974__fzgx_offset_0[];
extern u8 lbl_1_data_1B988__fzgx_offset_0[];
extern u8 lbl_1_data_1B99C__fzgx_offset_0[];
extern u8 lbl_1_data_1B9B0__fzgx_offset_0[];
extern u8 lbl_1_data_1B9C0__fzgx_offset_0[];
extern u8 lbl_1_data_1B9D8__fzgx_offset_0[];
extern u8 lbl_1_data_1B9EC__fzgx_offset_0[];
extern u8 lbl_1_data_1BA00__fzgx_offset_0[];
extern u8 lbl_1_data_1BA14__fzgx_offset_0[];
extern u8 lbl_1_data_1BA28__fzgx_offset_0[];
extern u8 lbl_1_data_1BA3C__fzgx_offset_0[];
extern u8 lbl_1_data_1BA4C__fzgx_offset_0[];
extern u8 lbl_1_data_1BA60__fzgx_offset_0[];
extern u8 lbl_1_data_1BA74__fzgx_offset_0[];
extern u8 lbl_1_data_1BA8C__fzgx_offset_0[];
extern u8 lbl_1_data_1BAA4__fzgx_offset_0[];
extern u8 lbl_1_data_1BABC__fzgx_offset_0[];
extern u8 lbl_1_data_1BAD0__fzgx_offset_0[];
extern u8 lbl_1_data_1BAE8__fzgx_offset_0[];
extern u8 lbl_1_data_1BAFC__fzgx_offset_0[];
extern u8 lbl_1_data_1BB10__fzgx_offset_0[];
extern u8 lbl_1_data_1BB28__fzgx_offset_0[];
extern u8 lbl_1_data_1BB3C__fzgx_offset_0[];
extern u8 lbl_1_data_1BB50__fzgx_offset_0[];
extern u8 lbl_1_data_1BB68__fzgx_offset_0[];
extern u8 lbl_1_data_1BB7C__fzgx_offset_0[];
extern u8 lbl_1_data_1BB90__fzgx_offset_0[];
extern u8 lbl_1_data_1BBA0__fzgx_offset_0[];
extern u8 lbl_1_data_1BBB0__fzgx_offset_0[];
extern u8 lbl_1_data_1BC74__fzgx_offset_0[];
extern u8 lbl_1_data_1BC80__fzgx_offset_0[];
extern u8 lbl_1_data_1BC88__fzgx_offset_0[];
extern u8 lbl_1_data_1BC90__fzgx_offset_0[];
extern u8 lbl_1_data_1BC98__fzgx_offset_0[];
extern u8 lbl_1_data_1BCA4__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_1A3B8[700] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x81408141, 0x81428143, 0x81448145, 0x81468147, 0x81488149, 0x814A814B, 0x814C814D, 0x814F8151,  /* fzgx-allow: A1 retail data bytes */
    0x8158815B, 0x815E815F, 0x81608162, 0x81638165, 0x81668167, 0x81688169, 0x816A816D, 0x816E816F,  /* fzgx-allow: A1 retail data bytes */
    0x81708171, 0x81728175, 0x81768177, 0x8178817B, 0x817C817E, 0x81818183, 0x8184818F, 0x81908193,  /* fzgx-allow: A1 retail data bytes */
    0x81948195, 0x81968197, 0x819A81A0, 0x81A381E7, 0x81E881F4, 0x824F8250, 0x82518252, 0x82538254,
    0x82558256, 0x82578258, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B,
    0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x82818282,
    0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292,
    0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x829F82A0, 0x82A182A2, 0x82A382A4, 0x82A582A6,
    0x82A782A8, 0x82A982AA, 0x82AB82AC, 0x82AD82AE, 0x82AF82B0, 0x82B182B2, 0x82B382B4, 0x82B582B6,
    0x82B782B8, 0x82B982BA, 0x82BB82BC, 0x82BD82BE, 0x82BF82C0, 0x82C182C2, 0x82C382C4, 0x82C582C6,
    0x82C782C8, 0x82C982CA, 0x82CB82CC, 0x82CD82CE, 0x82CF82D0, 0x82D182D2, 0x82D382D4, 0x82D582D6,
    0x82D782D8, 0x82D982DA, 0x82DB82DC, 0x82DD82DE, 0x82DF82E0, 0x82E182E2, 0x82E382E4, 0x82E582E6,
    0x82E782E8, 0x82E982EA, 0x82EB82EC, 0x82ED82EE, 0x82EF82F0, 0x82F18340, 0x83418342, 0x83438344,
    0x83458346, 0x83478348, 0x8349834A, 0x834B834C, 0x834D834E, 0x834F8350, 0x83518352, 0x83538354,
    0x83558356, 0x83578358, 0x8359835A, 0x835B835C, 0x835D835E, 0x835F8360, 0x83618362, 0x83638364,
    0x83658366, 0x83678368, 0x8369836A, 0x836B836C, 0x836D836E, 0x836F8370, 0x83718372, 0x83738374,
    0x83758376, 0x83778378, 0x8379837A, 0x837B837C, 0x837D837E, 0x83808381, 0x83828383, 0x83848385,
    0x83868387, 0x83888389, 0x838A838B, 0x838C838D, 0x838E838F, 0x83908391, 0x83928393, 0x83948395,
    0x8396839F, 0x83A083A1, 0x83A483A6, 0x83AD83AF, 0x83B083B2, 0x83B483B5, 0x83BF83D0, 0x88A488AB,
    0x88AC88B3, 0x88B588B6, 0x88C088C3, 0x88C888CA, 0x88CB88CC, 0x88CD88CF, 0x88D388D5, 0x88D988DA,
    0x88DB88E1, 0x88E388E6, 0x88E788EA, 0x88F388F5, 0x88F688F8, 0x88F98940, 0x89418945, 0x8946894A,
    0x895C895E, 0x89638965, 0x89668968, 0x89698970, 0x897A897E, 0x89808983, 0x89848985, 0x89878989,
    0x898A898E, 0x898F8993, 0x899C899E, 0x899F89A1, 0x89A389A4, 0x89AD89AE, 0x89AF89B1, 0x89B489B7,
    0x89B889B9, 0x89BA89BB, 0x89BC89BD, 0x89BF89C1, 0x89C289C5, 0x89C689C8, 0x89C989CA, 0x89CC89CD,
    0x89D289D4, 0x89D789D8, 0x89DC89DD, 0x89DF89E4, 0x89E589E6, 0x89EE89EF, 0x89F089F1, 0x89F389F5,
    0x89F689F7, 0x89F989FC, 0x8A428A43, 0x8A448A45, 0x8A4A8A4D, 0x8A4F8A51, 0x8A588A65, 0x8A678A69,
    0x8A6C8A6D, 0x8A6F8A70, 0x8A778A79, 0x8A7A8A7C, 0x8A848A87, 0x8A888AA3, 0x8AA88AA9, 0x8AAA8AAC,
    0x8AAE8AAF, 0x8AB18AB4, 0x8AB58AB7, 0x8ABB8ABD, 0x8AC28AC7, 0x8AC88ACD, 0x8ACF8AD3, 0x8AD48AD6,
    0x8AD78AD9, 0x8ADB8ADC, 0x8AE28AE6, 0x8AE78AE8, 0x8AE98AEB, 0x8AEC8AED, 0x8AEE8AEF, 0x8AF08AF1,
    0x8AF38AF6, 0x8AFA8AFC, 0x8B408B41, 0x8B438B49, 0x8B4B8B4C, 0x8B4D8B4E, 0x8B518B53, 0x8B568B5A,
    0x8B5E8B60, 0x8B638B6C, 0x8B718B74, 0x8B788B79, 0x8B7B8B7D, 0x8B7E8B81, 0x8B858B86, 0x8B898B8B,
    0x8B8C8B8E, 0x8B908B91, 0x8B938B96, 0x8B978B9F, 0x8BA38BA4, 0x8BA58BA6, 0x8BAD8BAF, 0x8BB08BB3,
    0x8BB58BB6, 0x8BB98BBB, 0x8BBD8BBE, 0x8BBF8BC1, 0x8BC38BC6, 0x8BC78BC8, 0x8BC98BCF, 0x8BD88BD9,
    0x8BDE8BDF, 0x8BE08BE2, 0x8BE38BE5, 0x8BE68BEA, 0x8BEC8BEF, 0x8BF08BF2, 0x8BF38BF4, 0x8BF68BFC,
    0x8C4A8C4D, 0x8C4E8C50, 0x8C518C52, 0x8C578C59, 0x8C5A8C5E, 0x8C5F8C60, 0x8C628C68, 0x8C698C6E,
    0x8C6F8C70, 0x8C768C78, 0x8C798C7C, 0x8C7D8C82, 0x8C838C86, 0x8C878C88, 0x8C8B8C8C, 0x8C8D8C8F,
    0x8C928C95, 0x8C968C99, 0x8C9A8CA0, 0x8CA48CA8, 0x8CA98CAB, 0x8CAD8CAF, 0x8CB08CB1, 0x8CB38CB4,
    0x8CB58CB6, 0x8CB88CB9, 0x8CBB8CBE, 0x8CC08CC2, 0x8CC38CC4, 0x8CC58CC7, 0x8CC88CCB, 0x8CCC8CD6,
    0x8CD98CDD, 0x8CE28CE3, 0x8CE58CEB, 0x8CF08CF3, 0x8CF58CF6, 0x8CF78CF8, 0x8CFB8CFC, 0x8D448D48,
    0x8D498D4B, 0x8D4C8D4E, 0x8D528D55, 0x8D588D5A, 0x8D5C8D62, 0x8D6C8D72, 0x8D738D75, 0x8D778D7E,
    0x8D808D82, 0x8D868D87, 0x8D8B8D8F, 0x8D908D91, 0x8D938D95, 0x8D968D9C, 0x8D9E8DA0, 0x8DA18DA2,
    0x8DA58DA6, 0x8DAA8DB0, 0x8DB68DB7, 0x8DB88DC3, 0x8DC48DC5, 0x8DC88DCB, 0x8DCE8DCF, 0x8DD08DD3,
    0x8DD58DD7, 0x8DDA8DDB, 0x8DDD8DDE, 0x8DDF8DE0, 0x8DEC8DED, 0x8E408E42, 0x8E458E4F, 0x8E518E52,
    0x8E598E5A, 0x8E5D8E5E, 0x8E638E64, 0x8E678E68, 0x8E698E6A, 0x8E6C8E6D, 0x8E6E8E70, 0x8E718E74,
    0x8E758E76, 0x8E778E78, 0x8E7B8E7E, 0x8E808E84, 0x8E8A8E8B, 0x8E8E8E91, 0x8E958E96, 0x8E978E99,
    0x8E9A8E9D, 0x8E9E8E9F, 0x8EA18EA6, 0x8EA98EAB, 0x8EAE8EAF, 0x8EB88EBA, 0x8EBF8EC0, 0x8ECA8ECB,
    0x8ECC8ECD, 0x8ED08ED2, 0x8ED38ED4, 0x8ED78EDF, 0x8EE18EE3, 0x8EE58EE6, 0x8EE78EE8, 0x8EEA8EEB,
    0x8EED8EEF, 0x8EF18EF3, 0x8EF58EF6, 0x8EFB8EFC, 0x8F438F45, 0x8F478F49, 0x8F4B8F50, 0x8F518F57,
    0x8F5A8F5B, 0x8F5C8F5D, 0x8F5F8F61, 0x8F628F63, 0x8F648F68, 0x8F6A8F6B, 0x8F6E8F6F, 0x8F708F74,
    0x8F758F80, 0x8F848F87, 0x8F888F89, 0x8F8A8F8F, 0x8F918F94, 0x8F958F97, 0x8F988F9C, 0x8F9D8F9E,
    0x8F9F8FA4, 0x8FA78FAA, 0x8FAB8FAC, 0x8FAD8FB2, 0x8FB38FB8, 0x8FBB8FC1, 0x8FC48FC6, 0x8FC88FCC,
    0x8FCD8FCE, 0x8FD08FD5, 0x8FD88FDA, 0x8FDC8FE1, 0x8FE38FE4, 0x8FE68FE8, 0x8FEA8FED, 0x8FEE8FF3,
    0x8FFC9041, 0x90449045, 0x90469047, 0x9048904A, 0x904B904D, 0x90539054, 0x90559056, 0x905B905E,
    0x905F9065, 0x90679069, 0x906C906E, 0x9073907D, 0x90849085, 0x90879088, 0x908B908C, 0x9094909D,
    0x90A290A3, 0x90A690A7, 0x90A890AA, 0x90AB90AC, 0x90AD90AE, 0x90AF90B3, 0x90B690B7, 0x90B890BA,
    0x90BB90C0, 0x90C290C3, 0x90C890C9, 0x90CC90CD, 0x90CE90CF, 0x90D190D4, 0x90D590D8, 0x90DA90DC,
    0x90DD90E0, 0x90E190E2, 0x90E690E7, 0x90E890E9, 0x90EA90ED, 0x90F290F3, 0x90F490F5, 0x90F990FC,
    0x91449149, 0x914F9150, 0x91529153, 0x915E915F, 0x91619163, 0x91669167, 0x9168916E, 0x91729177,
    0x917A917B, 0x917D9180, 0x91819188, 0x918A918D, 0x91909193, 0x91959196, 0x91979198, 0x919C919D,
    0x91A091A2, 0x91A491A5, 0x91A691A7, 0x91A991AA, 0x91AB91AC, 0x91AE91AF, 0x91B091B1, 0x91B691B8,
    0x91B991BC, 0x91BD91C5, 0x91CA91CC, 0x91CE91D2, 0x91D491D6, 0x91D891DC, 0x91DD91DE, 0x91DF91E0,
    0x91E391E4, 0x91E591E6, 0x91E891EC, 0x91F091F5, 0x92409242, 0x92449245, 0x924E9250, 0x92539254,
    0x92559261, 0x92629263, 0x92659266, 0x9269926A, 0x926B926D, 0x926E9270, 0x92759276, 0x927A9281,
    0x92859286, 0x92879288, 0x9289928D, 0x92989299, 0x92A192A3, 0x92A692A7, 0x92AD92AE, 0x92B292B4,
    0x92B792B8, 0x92BC92C0, 0x92C792C9, 0x92CA92CD, 0x92D792E1, 0x92E892E9, 0x92EA92ED, 0x92EF92F6,
    0x93409347, 0x9349934B, 0x93539354, 0x93569357, 0x93589359, 0x935C935D, 0x935F9360, 0x9364936E,
    0x936F9371, 0x93729373, 0x93779378, 0x937A937C, 0x93809381, 0x938B9390, 0x93969399, 0x939A939D,
    0x939E93A5, 0x93A693AA, 0x93AC93AD, 0x93AE93AF, 0x93B093B7, 0x93B993BA, 0x93BE93BF, 0x93C193C6,
    0x93C793CB, 0x93CD93DD, 0x93DF93E0, 0x93E493EE, 0x93EF93F1, 0x93F793FA, 0x93FC9440, 0x94439445,
    0x9446944D, 0x944E944F, 0x94529459, 0x945C945D, 0x94659468, 0x946A9470, 0x94729473, 0x94749477,
    0x9479947A, 0x947B947C, 0x94839484, 0x948E9492, 0x9497949A, 0x94A094AD, 0x94AF94B1, 0x94B294B4,
    0x94BA94BB, 0x94BC94BD, 0x94C494C5, 0x94C694CC, 0x94D494DA, 0x94DB94DE, 0x94DF94E2, 0x94E394E4,
    0x94E594E6, 0x94E994ED, 0x94EF94F0, 0x94F194F2, 0x94F594F6, 0x94FC9543, 0x954B9550, 0x95579559,
    0x955C955D, 0x95619562, 0x9569956E, 0x95719573, 0x95749576, 0x95779578, 0x957A957B, 0x957C9581,
    0x95829583, 0x95849589, 0x958B9590, 0x95919594, 0x95959597, 0x959C959D, 0x959E95A0, 0x95A195A5,
    0x95A895AA, 0x95B195B6, 0x95B795BA, 0x95BD95BF, 0x95C095C2, 0x95C795CA, 0x95CF95D0, 0x95D495D9,
    0x95DB95DF, 0x95E095E2, 0x95E595E6, 0x95EF95F1, 0x95F395F6, 0x95F895F9, 0x95FA95FB, 0x9640964A,
    0x964B964D, 0x964F9652, 0x96539656, 0x96579659, 0x965C965D, 0x965F9660, 0x96669668, 0x966C966E,
    0x9676967A, 0x967B9681, 0x96829683, 0x96849687, 0x96889695, 0x9696969C, 0x969D969E, 0x969F96A1,
    0x96A296A3, 0x96A796AD, 0x96AF96B0, 0x96B196B2, 0x96B396B6, 0x96BC96BD, 0x96BE96C5, 0x96CA96CD,
    0x96D296D7, 0x96D896D9, 0x96DA96DF, 0x96E296E5, 0x96E996EC, 0x96F096F1, 0x96F396F4, 0x96FC9741,
    0x97449745, 0x9746974C, 0x97529754, 0x97569759, 0x975C975D, 0x975E975F, 0x97619763, 0x9765976C,
    0x97709774, 0x97769778, 0x977A977B, 0x977D977E, 0x97819783, 0x9788978A, 0x978B978D, 0x978E9791,
    0x97979798, 0x979D97A0, 0x97A397A5, 0x97A697A7, 0x97AC97AF, 0x97B397B7, 0x97B997BC, 0x97BF97C3,
    0x97C797CA, 0x97CC97CD, 0x97CE97D6, 0x97DC97DE, 0x97DF97E1, 0x97E297E7, 0x97ED97EE, 0x97F097F1,
    0x97F397F6, 0x97FB9841, 0x98439849, 0x984A9851, 0x98549856, 0x9859985E, 0x985F9861, 0x98629863,
    0x98659866, 0x98729C66, 0x9C729D7C, 0xE0A3E0F8, 0xE3A9E690, 0xE8A60000, 0x0, 0x4E554C4C,
    0x0, 0x6173635F, 0x32347832, 0x34000000
};
static u32 fzgx_pool_data_lbl_1_data_1AEA8[616] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x201, 0x1C180000, 0x30, 0x3A, 0xB010000, 0x3DBA2E8C, 0x3F800000, 0x3B54C77B,
    0x3D2AAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x205, 0x1C180000,
    0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3BEA0EA1, 0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0xF, 0x8100000, 0x20, 0x7A,
    0x10060000, 0x3D800000, 0x3E000000, 0x3C000000, 0x3C000000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0xE, 0xC0C0000, 0x0, 0x7F, 0x10080000, 0x3D800000,
    0x3E000000, 0x3BAAAAAB, 0x3C2AAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x7, 0xC0E0000, 0x41, 0x5A, 0x8040000, 0x3E000000, 0x3E800000, 0x3C2AAAAB,
    0x3C924925, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x8, 0x12120000,
    0x20, 0x73, 0xC070000, 0x3DAAAAAB, 0x3E100000, 0x3B97B426, 0x3C000000, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x8, 0x12120000, 0x20, 0x73,
    0xC070000, 0x3DAAAAAB, 0x3E100000, 0x3B97B426, 0x3C000000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x3, 0xC100000, 0x20, 0x7A, 0xC080000, 0x3DAAAAAB,
    0x3E000000, 0x3BE38E39, 0x3C000000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x4, 0x18180000, 0x20, 0x7A, 0xC080000, 0x3DAAAAAB, 0x3E000000, 0x3B638E39,
    0x3BAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x890E, 0x80A0000,
    0x41, 0x5A, 0x8040000, 0x3E000000, 0x3E800000, 0x3C800000, 0x3CCCCCCD, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x944E, 0x18200000, 0x30, 0x3D,
    0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3C088889, 0x3C2AAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9452, 0x18180000, 0x31, 0x36, 0x3020000, 0x3EAAAAAB,
    0x3F000000, 0x3C638E39, 0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x9427, 0x2C380000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3B94F209,
    0x3C124925, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9428, 0x10140000,
    0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3C4CCCCD, 0x3CCCCCCD, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9433, 0x14140000, 0x30, 0x3D,
    0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3C23D70A, 0x3C888889, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x942C, 0x18200000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD,
    0x3F000000, 0x3C088889, 0x3C800000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x942E, 0x3C340000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3B5A740E,
    0x3C1D89D9, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x943D, 0x48400000,
    0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3B360B61, 0x3C000000, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9703, 0x10140000, 0x30, 0x3B,
    0xC010000, 0x3DAAAAAB, 0x3F800000, 0x3BAAAAAB, 0x3D4CCCCD, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9731, 0x18200000, 0x30, 0x3D, 0x5030000, 0x3E4CCCCD,
    0x3EAAAAAB, 0x3C088889, 0x3C2AAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x9733, 0x18180000, 0x31, 0x36, 0x3020000, 0x3EAAAAAB, 0x3F000000, 0x3C638E39,
    0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x971A, 0x12140000,
    0x2C, 0x5A, 0xC040000, 0x3DAAAAAB, 0x3E800000, 0x3B97B426, 0x3C4CCCCD, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x971B, 0xC0C0000, 0x2C, 0x5A,
    0xC040000, 0x3DAAAAAB, 0x3E800000, 0x3BE38E39, 0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x972D, 0x20240000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD,
    0x3F000000, 0x3BCCCCCD, 0x3C638E39, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x972E, 0x282C0000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3BA3D70A,
    0x3C3A2E8C, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9811, 0x20180000,
    0x30, 0x3C, 0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3BCCCCCD, 0x3C638E39, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9902, 0x80C0000, 0x30, 0x39,
    0xA010000, 0x3DCCCCCD, 0x3F800000, 0x3C4CCCCD, 0x3DAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9905, 0xA100000, 0x30, 0x39, 0xA010000, 0x3DB6DB6E,
    0x3F800000, 0x3C124925, 0x3D800000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x9906, 0xC1A0000, 0x2C, 0x5A, 0xC040000, 0x3DAAAAAB, 0x3E800000, 0x3BE38E39,
    0x3C1D89D9, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x990A, 0x18200000,
    0x41, 0x5A, 0xA030000, 0x3DCCCCCD, 0x3EAAAAAB, 0x3B888889, 0x3C2AAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x990B, 0xC100000, 0x41, 0x5A,
    0xA040000, 0x3DCCCCCD, 0x3E800000, 0x3C088889, 0x3C800000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x990D, 0x80C0000, 0x30, 0x39, 0xA010000, 0x3DCCCCCD,
    0x3F800000, 0x3C4CCCCD, 0x3DAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x9725, 0x14140000, 0x30, 0x3D, 0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3C23D70A,
    0x3C888889, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9A1E, 0x10100000,
    0x41, 0x5A, 0x8040000, 0x3E000000, 0x3E800000, 0x3C000000, 0x3C800000, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9A26, 0x10100000, 0x30, 0x39,
    0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3C4CCCCD, 0x3D000000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9A07, 0xC1A0000, 0x2C, 0x5A, 0xC040000, 0x3DAAAAAB,
    0x3E800000, 0x3BE38E39, 0x3C1D89D9, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x9E29, 0x18100000, 0x30, 0x3C, 0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3C088889,
    0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9E22, 0x28340000,
    0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3BA3D70A, 0x3C1D89D9, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9E27, 0x38440000, 0x30, 0x39,
    0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3B6A0EA1, 0x3BF0F0F1, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9F0A, 0x20180000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD,
    0x3F000000, 0x3BCCCCCD, 0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0xBB02, 0x30240000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3B888889,
    0x3C638E39, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0xBB04, 0x20180000,
    0x30, 0x3C, 0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3BCCCCCD, 0x3C638E39, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0xFFFFFFFF, 0x18180000, 0x0, 0x0,
    0x1010000, 0x3F800000, 0x3F800000, 0x3D2AAAAB, 0x3D2AAAAB, (u32)lbl_1_data_1AE9C__fzgx_offset_0, 0x1200000, (u32)lbl_1_data_1A3B8__fzgx_offset_0,
    (u32)lbl_1_bss_4BBA0__fzgx_offset_0, 0x3F800000, 0x9603, 0x18200000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD,
    0x3F000000, 0x3C088889, 0x3C800000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000
};
static u32 fzgx_pool_data_lbl_1_data_1B848[288] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x464F4E54, 0x5F414456, 0x41435F43, 0x52454449, 0x545F4E55, 0x4D000000, 0x464F4E54, 0x5F414456,
    0x41435F53, 0x54415254, 0x5F4E554D, 0x0, 0x464F4E54, 0x5F415343, 0x5F387831, 0x36000000,
    0x464F4E54, 0x5F415343, 0x5F313278, 0x31320000, 0x464F4E54, 0x5F415343, 0x5F313478, 0x31360000,
    0x464F4E54, 0x5F415343, 0x5F313878, 0x31380000, 0x464F4E54, 0x5F415343, 0x5F313878, 0x31385F54,
    0x494D4500, 0x464F4E54, 0x5F415343, 0x5F53454C, 0x5F313278, 0x31360000, 0x464F4E54, 0x5F415343,
    0x5F53454C, 0x5F323478, 0x32340000, 0x464F4E54, 0x5F474152, 0x5F415343, 0x5F387831, 0x30000000,
    0x464F4E54, 0x5F524143, 0x5F415343, 0x5F54494D, 0x455F4E55, 0x4D000000, 0x464F4E54, 0x5F524143,
    0x5F464143, 0x455F4E55, 0x4D000000, 0x464F4E54, 0x5F524143, 0x5F52414E, 0x4B5F4E55, 0x4D000000,
    0x464F4E54, 0x5F524143, 0x5F52414E, 0x4B5F4E55, 0x4D5F5300, 0x464F4E54, 0x5F524143, 0x5F56535F,
    0x52414E4B, 0x5F4E554D, 0x0, 0x464F4E54, 0x5F524143, 0x5F535045, 0x45445F4E, 0x554D0000,
    0x464F4E54, 0x5F524143, 0x5F54494D, 0x455F4143, 0x0, 0x464F4E54, 0x5F524143, 0x5F54494D,
    0x455F4143, 0x5F530000, 0x464F4E54, 0x5F524553, 0x5F415343, 0x0, 0x464F4E54, 0x5F524553,
    0x5F415343, 0x5F54494D, 0x455F4E55, 0x4D000000, 0x464F4E54, 0x5F524553, 0x5F464143, 0x455F4E55,
    0x4D000000, 0x464F4E54, 0x5F524553, 0x5F4E414D, 0x455F4153, 0x43000000, 0x464F4E54, 0x5F524553,
    0x5F4E414D, 0x455F4153, 0x435F5300, 0x464F4E54, 0x5F524553, 0x5F54494D, 0x455F4E55, 0x4D000000,
    0x464F4E54, 0x5F524553, 0x5F54494D, 0x455F4E55, 0x4D5F5300, 0x464F4E54, 0x5F524553, 0x41435F4E,
    0x554D0000, 0x464F4E54, 0x5F524553, 0x47435F41, 0x53435F53, 0x53000000, 0x464F4E54, 0x5F524553,
    0x47435F41, 0x53435F59, 0x0, 0x464F4E54, 0x5F524553, 0x47435F43, 0x5553544F, 0x4D5F464F,
    0x4E540000, 0x464F4E54, 0x5F524553, 0x47435F50, 0x4C415445, 0x5F415343, 0x0, 0x464F4E54,
    0x5F524553, 0x47435F50, 0x4C415445, 0x5F415343, 0x5F530000, 0x464F4E54, 0x5F524553, 0x47435F56,
    0x5F415343, 0x0, 0x464F4E54, 0x5F524553, 0x5F56535F, 0x52414E4B, 0x5F4E554D, 0x0,
    0x464F4E54, 0x5F53454C, 0x5F4E414D, 0x455F4153, 0x43000000, 0x464F4E54, 0x5F53454C, 0x5F574549,
    0x4748545F, 0x4E554D00, 0x464F4E54, 0x5F53454C, 0x5F435553, 0x544F4D5F, 0x464F4E54, 0x0,
    0x464F4E54, 0x5F53454C, 0x41435F44, 0x4154415F, 0x4E554D00, 0x464F4E54, 0x5F53454C, 0x41435F54,
    0x494D455F, 0x4E554D00, 0x464F4E54, 0x5F53454C, 0x41435F54, 0x494D455F, 0x4E554D5F, 0x53000000,
    0x464F4E54, 0x5F53454C, 0x41465F43, 0x4F494E5F, 0x4E554D00, 0x464F4E54, 0x5F564945, 0x575F4C41,
    0x505F4E55, 0x4D000000, 0x464F4E54, 0x5F564945, 0x575F4E55, 0x4D000000, 0x464F4E54, 0x5F415343,
    0x5F323478, 0x32340000, 0x464F4E54, 0x5F524550, 0x5F535045, 0x45445F4E, 0x554D0000, (u32)lbl_1_data_1B848__fzgx_offset_0,
    (u32)lbl_1_data_1B860__fzgx_offset_0, (u32)lbl_1_data_1B878__fzgx_offset_0, (u32)lbl_1_data_1B888__fzgx_offset_0, (u32)lbl_1_data_1B898__fzgx_offset_0, (u32)lbl_1_data_1B8A8__fzgx_offset_0, (u32)lbl_1_data_1B8B8__fzgx_offset_0, (u32)lbl_1_data_1B8CC__fzgx_offset_0, (u32)lbl_1_data_1B8E0__fzgx_offset_0,
    (u32)lbl_1_data_1B8F4__fzgx_offset_0, (u32)lbl_1_data_1B908__fzgx_offset_0, (u32)lbl_1_data_1B920__fzgx_offset_0, (u32)lbl_1_data_1B934__fzgx_offset_0, (u32)lbl_1_data_1B948__fzgx_offset_0, (u32)lbl_1_data_1B95C__fzgx_offset_0, (u32)lbl_1_data_1B974__fzgx_offset_0, (u32)lbl_1_data_1B988__fzgx_offset_0,
    (u32)lbl_1_data_1B99C__fzgx_offset_0, (u32)lbl_1_data_1B9B0__fzgx_offset_0, (u32)lbl_1_data_1B9C0__fzgx_offset_0, (u32)lbl_1_data_1B9D8__fzgx_offset_0, (u32)lbl_1_data_1B9EC__fzgx_offset_0, (u32)lbl_1_data_1BA00__fzgx_offset_0, (u32)lbl_1_data_1BA14__fzgx_offset_0, (u32)lbl_1_data_1BA28__fzgx_offset_0,
    (u32)lbl_1_data_1BA3C__fzgx_offset_0, (u32)lbl_1_data_1BA4C__fzgx_offset_0, (u32)lbl_1_data_1BA60__fzgx_offset_0, (u32)lbl_1_data_1BA74__fzgx_offset_0, (u32)lbl_1_data_1BA8C__fzgx_offset_0, (u32)lbl_1_data_1BAA4__fzgx_offset_0, (u32)lbl_1_data_1BABC__fzgx_offset_0, (u32)lbl_1_data_1BAD0__fzgx_offset_0,
    (u32)lbl_1_data_1BAE8__fzgx_offset_0, (u32)lbl_1_data_1BAFC__fzgx_offset_0, (u32)lbl_1_data_1BB10__fzgx_offset_0, (u32)lbl_1_data_1BB28__fzgx_offset_0, (u32)lbl_1_data_1BB3C__fzgx_offset_0, (u32)lbl_1_data_1BB50__fzgx_offset_0, (u32)lbl_1_data_1BB68__fzgx_offset_0, (u32)lbl_1_data_1BB7C__fzgx_offset_0,
    (u32)lbl_1_data_1BB90__fzgx_offset_0, (u32)lbl_1_data_1BBA0__fzgx_offset_0, (u32)lbl_1_data_1BBB0__fzgx_offset_0, 0x4F524947, 0x494E414C, 0x0, 0x52454755, 0x4C415200,
    0x424F4C44, 0x0, 0x4954414C, 0x49430000, 0x424F4C44, 0x20495441, 0x4C494300, 0x54454741,
    0x4B490000, (u32)lbl_1_data_1BC74__fzgx_offset_0, (u32)lbl_1_data_1BC80__fzgx_offset_0, (u32)lbl_1_data_1BC88__fzgx_offset_0, (u32)lbl_1_data_1BC90__fzgx_offset_0, (u32)lbl_1_data_1BC98__fzgx_offset_0, (u32)lbl_1_data_1BCA4__fzgx_offset_0, 0x1
};
static u32 fzgx_pool_data_lbl_1_data_1BCC8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x666F6E74, 0x2E630000
};
static u32 fzgx_pool_data_lbl_1_data_1A3B8_1918[45] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x63616E6E, 0x6F74204F, 0x53416C6C, 0x6F632061, 0x7420666F, 0x6E745F74, 0x6573745F, 0x696E6974,
    0xA000000, 0x30313233, 0x34353637, 0x38394142, 0x43444546, 0x4748494A, 0x4B4C4D4E, 0x4F505152,
    0x53545556, 0x5758595A, 0x61626364, 0x65666768, 0x696A6B6C, 0x6D6E6F70, 0x71727374, 0x75767778,
    0x797A2122, 0x23242526, 0x2728292A, 0x2B2C2D2E, 0x2F3A3B3C, 0x3D3E3F40, 0x5B5C5D5E, 0x5F607B7C,
    0x7D7E0000, 0x54455853, 0x70725075, 0x745F5375, 0x62203A20, 0x4E6F2072, 0x65676973, 0x74726174,
    0x696F6E20, 0x6F662043, 0x414C4C5F, 0x4241434B, 0x2E0A0000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_1A3B8(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1A3B8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1AEA8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1B848;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1BCC8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1A3B8_1918;
}
#pragma section code_type ".text"

int fn_1_48A0C(int ch, int idx, Obj_1_data_1AEA8 *font, int noLoad) {
    // Retail addresses the font table and its strings off one base register
    // (the TU's data section); the one-member wrapper keeps the address CSE'd.
    s16 *slots;
    u8 *table;
    int tex;
    int i;
    u16 code;
    int fmt;

    
    slots = (s16 *)font->unk_30;
    if (slots[ch] != -1) {
        return 0;
    }
    table = ((u8 *)fzgx_pool_data_lbl_1_data_1AEA8);
    for (i = 1; i < 44; i++) {
        Obj_1_data_1AEA8 *other = (Obj_1_data_1AEA8 *)(table + i * 0x38);
        if (i != idx && (s32)other->unk_0 == -1 && ((s16 *)other->unk_30)[ch] != -1) {
            slots[ch] = ((s16 *)other->unk_30)[ch];
            return 0;
        }
    }

    tex = -1;
    for (i = 0; i < 0x56B; i++) {
        if (lbl_1_bss_3E060[i] == 0) {
            tex = i;
            break;
        }
    }
    if (tex == -1) {
        return 0;
    }

    if (noLoad) {
        lbl_1_bss_3E060[tex] = OSAllocFromArenaLo(*(u16 *)((u8 *)font + 0x28), 0x20);
    } else {
        lbl_1_bss_3E060[tex] = fn_1_45D0(lbl_801A6410, *(u16 *)((u8 *)font + 0x28),
                                         (const char *)(((u8 *)fzgx_pool_data_lbl_1_data_1BCC8)), 0x14E);
    }
    if (lbl_1_bss_3E060[tex] == 0) {
        OSPanic((const char *)(((u8 *)fzgx_pool_data_lbl_1_data_1BCC8)), 0x150, (const char *)(((u8 *)fzgx_pool_data_lbl_1_data_1A3B8_1918)));
    }
    fn_1_4BA24(idx, ch, (void *)lbl_1_bss_3E060[tex]);

    fmt = 0;
    code = ((u16 *)font->unk_2C)[ch];
    if ((code >= 0x839F && code <= 0x83BE) || code == 0x8452) {
        fmt = 0xE;
    }
    GXInitTexObj((GXTexObj *)(&lbl_1_bss_40C6C[tex * 0x20]), (void *)lbl_1_bss_3E060[tex], font->unk_4, font->unk_5, (GXTexFmt)(fmt), (GXTexWrapMode)(0), (GXTexWrapMode)(0), 0);
    ((s16 *)font->unk_30)[ch] = tex;
    if (noLoad) {
        lbl_1_bss_3F60C[tex] = -1;
    } else {
        lbl_1_bss_3F60C[tex] = lbl_801A6410;
    }
    return 1;
}
/* fzgx:end fn_1_48A0C */

/* fzgx:begin fn_1_48C28 */
extern u8 lbl_1_bss_3E060[];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, void *, int);

void fn_1_48C28(int index) {
    u32 offset;
    u16 *scan;
    Obj_1_data_1AEA8 *entry;
    int i;

    entry = (Obj_1_data_1AEA8 *)((u8 *)&lbl_1_data_1AEA8 + index * 0x38);
    if ((s32)entry->unk_0 != -1) {
        return;
    }

    scan = (u16 *)entry->unk_2C;
    offset = 0;
    while (*scan) {
        int found = 0;
        int id = *(s16 *)(entry->unk_30 + offset);
        if (id != -1 && ((s32 *)lbl_1_bss_3F60C)[id] != -1) {
            for (i = 1; i != 0x2c; i++) {
                Obj_1_data_1AEA8 *other =
                    (Obj_1_data_1AEA8 *)((u8 *)&lbl_1_data_1AEA8 + i * 0x38);
                if (i == index) {
                    continue;
                }
                if ((s32)other->unk_0 == -1 &&
                    *(s16 *)((u8 *)offset + other->unk_30) != -1) {
                    found = 1;
                    break;
                }
            }
            if (found != 0) {
                *(s16 *)((u8 *)entry->unk_30 + offset) = -1;
            } else {
                fn_1_46B4(lbl_801A6410, ((s32 *)lbl_1_bss_3E060)[id],
                          lbl_1_data_1BCC8, 0x217);
                id = *(s16 *)(entry->unk_30 + offset);
                ((s32 *)lbl_1_bss_3E060)[id] = 0;
                *(s16 *)((u8 *)entry->unk_30 + offset) = -1;
            }
        }
        offset += 2;
        scan = scan + 1;
    }
}
/* fzgx:end fn_1_48C28 */

/* fzgx:begin fn_1_48D80 noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car_test.h"
#include "rel/main_rel/font.h"

/* begin game/main_rel/car_test_types.h (fork-deltawave784/windows-and-types@f88123fa) */
#ifndef GAME_MAIN_REL_CAR_TEST_TYPES_H
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn183D28Vec3;

extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);

#endif  // GAME_MAIN_REL_CAR_TEST_TYPES_H

/* end game/main_rel/car_test_types.h */

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_1_48D80_Color;

typedef struct fn_1_48D80_Sprite {
    u32 id;
    f32 x;
    f32 y;
    f32 z;
    f32 scaleX;
    f32 scaleY;
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;
    s16 rot;
    u8 pad_2A[2];
    f32 alpha;
    u32 flags;
    f32 offsetX;
    fn_1_48D80_Color color;
    fn_1_48D80_Color addColor;
    u8 pad_40[0x10];
    void (*draw)(struct fn_1_48D80_Sprite *, Fn183D28Vec3 *);
} fn_1_48D80_Sprite;

typedef struct {
    u8 pad_0[4];
    u8 width;
    u8 height;
    u8 pad_6[0x32];
} fn_1_48D80_TexInfo;

extern u8 lbl_1_bss_4BB9C__fzgx_offset_0[];

extern u8 lbl_1_bss_4BBA0__fzgx_offset_0[];

extern u8 lbl_1_data_1A3B8__fzgx_offset_0[];

extern u8 lbl_1_data_1AE90__fzgx_offset_0[];

extern u8 lbl_1_data_1AE94__fzgx_offset_0[];

extern u8 lbl_1_data_1AE9C__fzgx_offset_0[];

extern u8 lbl_1_data_1B848__fzgx_offset_0[];

extern u8 lbl_1_data_1B860__fzgx_offset_0[];

extern u8 lbl_1_data_1B878__fzgx_offset_0[];

extern u8 lbl_1_data_1B888__fzgx_offset_0[];

extern u8 lbl_1_data_1B898__fzgx_offset_0[];

extern u8 lbl_1_data_1B8A8__fzgx_offset_0[];

extern u8 lbl_1_data_1B8B8__fzgx_offset_0[];

extern u8 lbl_1_data_1B8CC__fzgx_offset_0[];

extern u8 lbl_1_data_1B8E0__fzgx_offset_0[];

extern u8 lbl_1_data_1B8F4__fzgx_offset_0[];

extern u8 lbl_1_data_1B908__fzgx_offset_0[];

extern u8 lbl_1_data_1B920__fzgx_offset_0[];

extern u8 lbl_1_data_1B934__fzgx_offset_0[];

extern u8 lbl_1_data_1B948__fzgx_offset_0[];

extern u8 lbl_1_data_1B95C__fzgx_offset_0[];

extern u8 lbl_1_data_1B974__fzgx_offset_0[];

extern u8 lbl_1_data_1B988__fzgx_offset_0[];

extern u8 lbl_1_data_1B99C__fzgx_offset_0[];

extern u8 lbl_1_data_1B9B0__fzgx_offset_0[];

extern u8 lbl_1_data_1B9C0__fzgx_offset_0[];

extern u8 lbl_1_data_1B9D8__fzgx_offset_0[];

extern u8 lbl_1_data_1B9EC__fzgx_offset_0[];

extern u8 lbl_1_data_1BA00__fzgx_offset_0[];

extern u8 lbl_1_data_1BA14__fzgx_offset_0[];

extern u8 lbl_1_data_1BA28__fzgx_offset_0[];

extern u8 lbl_1_data_1BA3C__fzgx_offset_0[];

extern u8 lbl_1_data_1BA4C__fzgx_offset_0[];

extern u8 lbl_1_data_1BA60__fzgx_offset_0[];

extern u8 lbl_1_data_1BA74__fzgx_offset_0[];

extern u8 lbl_1_data_1BA8C__fzgx_offset_0[];

extern u8 lbl_1_data_1BAA4__fzgx_offset_0[];

extern u8 lbl_1_data_1BABC__fzgx_offset_0[];

extern u8 lbl_1_data_1BAD0__fzgx_offset_0[];

extern u8 lbl_1_data_1BAE8__fzgx_offset_0[];

extern u8 lbl_1_data_1BAFC__fzgx_offset_0[];

extern u8 lbl_1_data_1BB10__fzgx_offset_0[];

extern u8 lbl_1_data_1BB28__fzgx_offset_0[];

extern u8 lbl_1_data_1BB3C__fzgx_offset_0[];

extern u8 lbl_1_data_1BB50__fzgx_offset_0[];

extern u8 lbl_1_data_1BB68__fzgx_offset_0[];

extern u8 lbl_1_data_1BB7C__fzgx_offset_0[];

extern u8 lbl_1_data_1BB90__fzgx_offset_0[];

extern u8 lbl_1_data_1BBA0__fzgx_offset_0[];

extern u8 lbl_1_data_1BBB0__fzgx_offset_0[];

extern u8 lbl_1_data_1BC74__fzgx_offset_0[];

extern u8 lbl_1_data_1BC80__fzgx_offset_0[];

extern u8 lbl_1_data_1BC88__fzgx_offset_0[];

extern u8 lbl_1_data_1BC90__fzgx_offset_0[];

extern u8 lbl_1_data_1BC98__fzgx_offset_0[];

extern u8 lbl_1_data_1BCA4__fzgx_offset_0[];

extern u16 fn_1_A5D88(void);

extern u16 fn_1_A5DB0(void);

extern void fn_1_492F0(fn_1_48D80_Sprite *, Fn183D28Vec3 *);

extern s32 fn_1_A6F1C(void);

extern void fn_800371F8(u32, fn_1_48D80_Color);

extern void fn_80074188(u32, u32, u32, u32);

extern u8 lbl_1_bss_40C6C[];

extern void mathutil_mtxA_rotate_z(s16);

extern void OSPanic(const char *, int, const char *, ...);

extern void fn_1_4E0F4(void);

extern void fn_1_4E638(s32);

extern void fn_8003462C(u32, u32, u32);

extern void fn_80073778(void *, s32);

extern void lbl_8006D7F4(f32, f32, f32);

extern void lbl_8006E0B4(f32, f32, f32);

extern void lbl_8006E15C(f32, f32, f32);

static u32 fzgx_pool_data_lbl_1_data_1A3B8[700] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x81408141, 0x81428143, 0x81448145, 0x81468147, 0x81488149, 0x814A814B, 0x814C814D, 0x814F8151,  /* fzgx-allow: A1 retail data bytes */
    0x8158815B, 0x815E815F, 0x81608162, 0x81638165, 0x81668167, 0x81688169, 0x816A816D, 0x816E816F,  /* fzgx-allow: A1 retail data bytes */
    0x81708171, 0x81728175, 0x81768177, 0x8178817B, 0x817C817E, 0x81818183, 0x8184818F, 0x81908193,  /* fzgx-allow: A1 retail data bytes */
    0x81948195, 0x81968197, 0x819A81A0, 0x81A381E7, 0x81E881F4, 0x824F8250, 0x82518252, 0x82538254,
    0x82558256, 0x82578258, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B,
    0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x82818282,
    0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292,
    0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x829F82A0, 0x82A182A2, 0x82A382A4, 0x82A582A6,
    0x82A782A8, 0x82A982AA, 0x82AB82AC, 0x82AD82AE, 0x82AF82B0, 0x82B182B2, 0x82B382B4, 0x82B582B6,
    0x82B782B8, 0x82B982BA, 0x82BB82BC, 0x82BD82BE, 0x82BF82C0, 0x82C182C2, 0x82C382C4, 0x82C582C6,
    0x82C782C8, 0x82C982CA, 0x82CB82CC, 0x82CD82CE, 0x82CF82D0, 0x82D182D2, 0x82D382D4, 0x82D582D6,
    0x82D782D8, 0x82D982DA, 0x82DB82DC, 0x82DD82DE, 0x82DF82E0, 0x82E182E2, 0x82E382E4, 0x82E582E6,
    0x82E782E8, 0x82E982EA, 0x82EB82EC, 0x82ED82EE, 0x82EF82F0, 0x82F18340, 0x83418342, 0x83438344,
    0x83458346, 0x83478348, 0x8349834A, 0x834B834C, 0x834D834E, 0x834F8350, 0x83518352, 0x83538354,
    0x83558356, 0x83578358, 0x8359835A, 0x835B835C, 0x835D835E, 0x835F8360, 0x83618362, 0x83638364,
    0x83658366, 0x83678368, 0x8369836A, 0x836B836C, 0x836D836E, 0x836F8370, 0x83718372, 0x83738374,
    0x83758376, 0x83778378, 0x8379837A, 0x837B837C, 0x837D837E, 0x83808381, 0x83828383, 0x83848385,
    0x83868387, 0x83888389, 0x838A838B, 0x838C838D, 0x838E838F, 0x83908391, 0x83928393, 0x83948395,
    0x8396839F, 0x83A083A1, 0x83A483A6, 0x83AD83AF, 0x83B083B2, 0x83B483B5, 0x83BF83D0, 0x88A488AB,
    0x88AC88B3, 0x88B588B6, 0x88C088C3, 0x88C888CA, 0x88CB88CC, 0x88CD88CF, 0x88D388D5, 0x88D988DA,
    0x88DB88E1, 0x88E388E6, 0x88E788EA, 0x88F388F5, 0x88F688F8, 0x88F98940, 0x89418945, 0x8946894A,
    0x895C895E, 0x89638965, 0x89668968, 0x89698970, 0x897A897E, 0x89808983, 0x89848985, 0x89878989,
    0x898A898E, 0x898F8993, 0x899C899E, 0x899F89A1, 0x89A389A4, 0x89AD89AE, 0x89AF89B1, 0x89B489B7,
    0x89B889B9, 0x89BA89BB, 0x89BC89BD, 0x89BF89C1, 0x89C289C5, 0x89C689C8, 0x89C989CA, 0x89CC89CD,
    0x89D289D4, 0x89D789D8, 0x89DC89DD, 0x89DF89E4, 0x89E589E6, 0x89EE89EF, 0x89F089F1, 0x89F389F5,
    0x89F689F7, 0x89F989FC, 0x8A428A43, 0x8A448A45, 0x8A4A8A4D, 0x8A4F8A51, 0x8A588A65, 0x8A678A69,
    0x8A6C8A6D, 0x8A6F8A70, 0x8A778A79, 0x8A7A8A7C, 0x8A848A87, 0x8A888AA3, 0x8AA88AA9, 0x8AAA8AAC,
    0x8AAE8AAF, 0x8AB18AB4, 0x8AB58AB7, 0x8ABB8ABD, 0x8AC28AC7, 0x8AC88ACD, 0x8ACF8AD3, 0x8AD48AD6,
    0x8AD78AD9, 0x8ADB8ADC, 0x8AE28AE6, 0x8AE78AE8, 0x8AE98AEB, 0x8AEC8AED, 0x8AEE8AEF, 0x8AF08AF1,
    0x8AF38AF6, 0x8AFA8AFC, 0x8B408B41, 0x8B438B49, 0x8B4B8B4C, 0x8B4D8B4E, 0x8B518B53, 0x8B568B5A,
    0x8B5E8B60, 0x8B638B6C, 0x8B718B74, 0x8B788B79, 0x8B7B8B7D, 0x8B7E8B81, 0x8B858B86, 0x8B898B8B,
    0x8B8C8B8E, 0x8B908B91, 0x8B938B96, 0x8B978B9F, 0x8BA38BA4, 0x8BA58BA6, 0x8BAD8BAF, 0x8BB08BB3,
    0x8BB58BB6, 0x8BB98BBB, 0x8BBD8BBE, 0x8BBF8BC1, 0x8BC38BC6, 0x8BC78BC8, 0x8BC98BCF, 0x8BD88BD9,
    0x8BDE8BDF, 0x8BE08BE2, 0x8BE38BE5, 0x8BE68BEA, 0x8BEC8BEF, 0x8BF08BF2, 0x8BF38BF4, 0x8BF68BFC,
    0x8C4A8C4D, 0x8C4E8C50, 0x8C518C52, 0x8C578C59, 0x8C5A8C5E, 0x8C5F8C60, 0x8C628C68, 0x8C698C6E,
    0x8C6F8C70, 0x8C768C78, 0x8C798C7C, 0x8C7D8C82, 0x8C838C86, 0x8C878C88, 0x8C8B8C8C, 0x8C8D8C8F,
    0x8C928C95, 0x8C968C99, 0x8C9A8CA0, 0x8CA48CA8, 0x8CA98CAB, 0x8CAD8CAF, 0x8CB08CB1, 0x8CB38CB4,
    0x8CB58CB6, 0x8CB88CB9, 0x8CBB8CBE, 0x8CC08CC2, 0x8CC38CC4, 0x8CC58CC7, 0x8CC88CCB, 0x8CCC8CD6,
    0x8CD98CDD, 0x8CE28CE3, 0x8CE58CEB, 0x8CF08CF3, 0x8CF58CF6, 0x8CF78CF8, 0x8CFB8CFC, 0x8D448D48,
    0x8D498D4B, 0x8D4C8D4E, 0x8D528D55, 0x8D588D5A, 0x8D5C8D62, 0x8D6C8D72, 0x8D738D75, 0x8D778D7E,
    0x8D808D82, 0x8D868D87, 0x8D8B8D8F, 0x8D908D91, 0x8D938D95, 0x8D968D9C, 0x8D9E8DA0, 0x8DA18DA2,
    0x8DA58DA6, 0x8DAA8DB0, 0x8DB68DB7, 0x8DB88DC3, 0x8DC48DC5, 0x8DC88DCB, 0x8DCE8DCF, 0x8DD08DD3,
    0x8DD58DD7, 0x8DDA8DDB, 0x8DDD8DDE, 0x8DDF8DE0, 0x8DEC8DED, 0x8E408E42, 0x8E458E4F, 0x8E518E52,
    0x8E598E5A, 0x8E5D8E5E, 0x8E638E64, 0x8E678E68, 0x8E698E6A, 0x8E6C8E6D, 0x8E6E8E70, 0x8E718E74,
    0x8E758E76, 0x8E778E78, 0x8E7B8E7E, 0x8E808E84, 0x8E8A8E8B, 0x8E8E8E91, 0x8E958E96, 0x8E978E99,
    0x8E9A8E9D, 0x8E9E8E9F, 0x8EA18EA6, 0x8EA98EAB, 0x8EAE8EAF, 0x8EB88EBA, 0x8EBF8EC0, 0x8ECA8ECB,
    0x8ECC8ECD, 0x8ED08ED2, 0x8ED38ED4, 0x8ED78EDF, 0x8EE18EE3, 0x8EE58EE6, 0x8EE78EE8, 0x8EEA8EEB,
    0x8EED8EEF, 0x8EF18EF3, 0x8EF58EF6, 0x8EFB8EFC, 0x8F438F45, 0x8F478F49, 0x8F4B8F50, 0x8F518F57,
    0x8F5A8F5B, 0x8F5C8F5D, 0x8F5F8F61, 0x8F628F63, 0x8F648F68, 0x8F6A8F6B, 0x8F6E8F6F, 0x8F708F74,
    0x8F758F80, 0x8F848F87, 0x8F888F89, 0x8F8A8F8F, 0x8F918F94, 0x8F958F97, 0x8F988F9C, 0x8F9D8F9E,
    0x8F9F8FA4, 0x8FA78FAA, 0x8FAB8FAC, 0x8FAD8FB2, 0x8FB38FB8, 0x8FBB8FC1, 0x8FC48FC6, 0x8FC88FCC,
    0x8FCD8FCE, 0x8FD08FD5, 0x8FD88FDA, 0x8FDC8FE1, 0x8FE38FE4, 0x8FE68FE8, 0x8FEA8FED, 0x8FEE8FF3,
    0x8FFC9041, 0x90449045, 0x90469047, 0x9048904A, 0x904B904D, 0x90539054, 0x90559056, 0x905B905E,
    0x905F9065, 0x90679069, 0x906C906E, 0x9073907D, 0x90849085, 0x90879088, 0x908B908C, 0x9094909D,
    0x90A290A3, 0x90A690A7, 0x90A890AA, 0x90AB90AC, 0x90AD90AE, 0x90AF90B3, 0x90B690B7, 0x90B890BA,
    0x90BB90C0, 0x90C290C3, 0x90C890C9, 0x90CC90CD, 0x90CE90CF, 0x90D190D4, 0x90D590D8, 0x90DA90DC,
    0x90DD90E0, 0x90E190E2, 0x90E690E7, 0x90E890E9, 0x90EA90ED, 0x90F290F3, 0x90F490F5, 0x90F990FC,
    0x91449149, 0x914F9150, 0x91529153, 0x915E915F, 0x91619163, 0x91669167, 0x9168916E, 0x91729177,
    0x917A917B, 0x917D9180, 0x91819188, 0x918A918D, 0x91909193, 0x91959196, 0x91979198, 0x919C919D,
    0x91A091A2, 0x91A491A5, 0x91A691A7, 0x91A991AA, 0x91AB91AC, 0x91AE91AF, 0x91B091B1, 0x91B691B8,
    0x91B991BC, 0x91BD91C5, 0x91CA91CC, 0x91CE91D2, 0x91D491D6, 0x91D891DC, 0x91DD91DE, 0x91DF91E0,
    0x91E391E4, 0x91E591E6, 0x91E891EC, 0x91F091F5, 0x92409242, 0x92449245, 0x924E9250, 0x92539254,
    0x92559261, 0x92629263, 0x92659266, 0x9269926A, 0x926B926D, 0x926E9270, 0x92759276, 0x927A9281,
    0x92859286, 0x92879288, 0x9289928D, 0x92989299, 0x92A192A3, 0x92A692A7, 0x92AD92AE, 0x92B292B4,
    0x92B792B8, 0x92BC92C0, 0x92C792C9, 0x92CA92CD, 0x92D792E1, 0x92E892E9, 0x92EA92ED, 0x92EF92F6,
    0x93409347, 0x9349934B, 0x93539354, 0x93569357, 0x93589359, 0x935C935D, 0x935F9360, 0x9364936E,
    0x936F9371, 0x93729373, 0x93779378, 0x937A937C, 0x93809381, 0x938B9390, 0x93969399, 0x939A939D,
    0x939E93A5, 0x93A693AA, 0x93AC93AD, 0x93AE93AF, 0x93B093B7, 0x93B993BA, 0x93BE93BF, 0x93C193C6,
    0x93C793CB, 0x93CD93DD, 0x93DF93E0, 0x93E493EE, 0x93EF93F1, 0x93F793FA, 0x93FC9440, 0x94439445,
    0x9446944D, 0x944E944F, 0x94529459, 0x945C945D, 0x94659468, 0x946A9470, 0x94729473, 0x94749477,
    0x9479947A, 0x947B947C, 0x94839484, 0x948E9492, 0x9497949A, 0x94A094AD, 0x94AF94B1, 0x94B294B4,
    0x94BA94BB, 0x94BC94BD, 0x94C494C5, 0x94C694CC, 0x94D494DA, 0x94DB94DE, 0x94DF94E2, 0x94E394E4,
    0x94E594E6, 0x94E994ED, 0x94EF94F0, 0x94F194F2, 0x94F594F6, 0x94FC9543, 0x954B9550, 0x95579559,
    0x955C955D, 0x95619562, 0x9569956E, 0x95719573, 0x95749576, 0x95779578, 0x957A957B, 0x957C9581,
    0x95829583, 0x95849589, 0x958B9590, 0x95919594, 0x95959597, 0x959C959D, 0x959E95A0, 0x95A195A5,
    0x95A895AA, 0x95B195B6, 0x95B795BA, 0x95BD95BF, 0x95C095C2, 0x95C795CA, 0x95CF95D0, 0x95D495D9,
    0x95DB95DF, 0x95E095E2, 0x95E595E6, 0x95EF95F1, 0x95F395F6, 0x95F895F9, 0x95FA95FB, 0x9640964A,
    0x964B964D, 0x964F9652, 0x96539656, 0x96579659, 0x965C965D, 0x965F9660, 0x96669668, 0x966C966E,
    0x9676967A, 0x967B9681, 0x96829683, 0x96849687, 0x96889695, 0x9696969C, 0x969D969E, 0x969F96A1,
    0x96A296A3, 0x96A796AD, 0x96AF96B0, 0x96B196B2, 0x96B396B6, 0x96BC96BD, 0x96BE96C5, 0x96CA96CD,
    0x96D296D7, 0x96D896D9, 0x96DA96DF, 0x96E296E5, 0x96E996EC, 0x96F096F1, 0x96F396F4, 0x96FC9741,
    0x97449745, 0x9746974C, 0x97529754, 0x97569759, 0x975C975D, 0x975E975F, 0x97619763, 0x9765976C,
    0x97709774, 0x97769778, 0x977A977B, 0x977D977E, 0x97819783, 0x9788978A, 0x978B978D, 0x978E9791,
    0x97979798, 0x979D97A0, 0x97A397A5, 0x97A697A7, 0x97AC97AF, 0x97B397B7, 0x97B997BC, 0x97BF97C3,
    0x97C797CA, 0x97CC97CD, 0x97CE97D6, 0x97DC97DE, 0x97DF97E1, 0x97E297E7, 0x97ED97EE, 0x97F097F1,
    0x97F397F6, 0x97FB9841, 0x98439849, 0x984A9851, 0x98549856, 0x9859985E, 0x985F9861, 0x98629863,
    0x98659866, 0x98729C66, 0x9C729D7C, 0xE0A3E0F8, 0xE3A9E690, 0xE8A60000, 0x0, 0x4E554C4C,
    0x0, 0x6173635F, 0x32347832, 0x34000000
};
static u32 fzgx_pool_data_lbl_1_data_1AEA8[616] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x201, 0x1C180000, 0x30, 0x3A, 0xB010000, 0x3DBA2E8C, 0x3F800000, 0x3B54C77B,
    0x3D2AAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x205, 0x1C180000,
    0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3BEA0EA1, 0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0xF, 0x8100000, 0x20, 0x7A,
    0x10060000, 0x3D800000, 0x3E000000, 0x3C000000, 0x3C000000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0xE, 0xC0C0000, 0x0, 0x7F, 0x10080000, 0x3D800000,
    0x3E000000, 0x3BAAAAAB, 0x3C2AAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x7, 0xC0E0000, 0x41, 0x5A, 0x8040000, 0x3E000000, 0x3E800000, 0x3C2AAAAB,
    0x3C924925, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x8, 0x12120000,
    0x20, 0x73, 0xC070000, 0x3DAAAAAB, 0x3E100000, 0x3B97B426, 0x3C000000, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x8, 0x12120000, 0x20, 0x73,
    0xC070000, 0x3DAAAAAB, 0x3E100000, 0x3B97B426, 0x3C000000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x3, 0xC100000, 0x20, 0x7A, 0xC080000, 0x3DAAAAAB,
    0x3E000000, 0x3BE38E39, 0x3C000000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x4, 0x18180000, 0x20, 0x7A, 0xC080000, 0x3DAAAAAB, 0x3E000000, 0x3B638E39,
    0x3BAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x890E, 0x80A0000,
    0x41, 0x5A, 0x8040000, 0x3E000000, 0x3E800000, 0x3C800000, 0x3CCCCCCD, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x944E, 0x18200000, 0x30, 0x3D,
    0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3C088889, 0x3C2AAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9452, 0x18180000, 0x31, 0x36, 0x3020000, 0x3EAAAAAB,
    0x3F000000, 0x3C638E39, 0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x9427, 0x2C380000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3B94F209,
    0x3C124925, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9428, 0x10140000,
    0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3C4CCCCD, 0x3CCCCCCD, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9433, 0x14140000, 0x30, 0x3D,
    0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3C23D70A, 0x3C888889, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x942C, 0x18200000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD,
    0x3F000000, 0x3C088889, 0x3C800000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x942E, 0x3C340000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3B5A740E,
    0x3C1D89D9, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x943D, 0x48400000,
    0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3B360B61, 0x3C000000, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9703, 0x10140000, 0x30, 0x3B,
    0xC010000, 0x3DAAAAAB, 0x3F800000, 0x3BAAAAAB, 0x3D4CCCCD, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9731, 0x18200000, 0x30, 0x3D, 0x5030000, 0x3E4CCCCD,
    0x3EAAAAAB, 0x3C088889, 0x3C2AAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x9733, 0x18180000, 0x31, 0x36, 0x3020000, 0x3EAAAAAB, 0x3F000000, 0x3C638E39,
    0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x971A, 0x12140000,
    0x2C, 0x5A, 0xC040000, 0x3DAAAAAB, 0x3E800000, 0x3B97B426, 0x3C4CCCCD, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x971B, 0xC0C0000, 0x2C, 0x5A,
    0xC040000, 0x3DAAAAAB, 0x3E800000, 0x3BE38E39, 0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x972D, 0x20240000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD,
    0x3F000000, 0x3BCCCCCD, 0x3C638E39, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x972E, 0x282C0000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3BA3D70A,
    0x3C3A2E8C, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9811, 0x20180000,
    0x30, 0x3C, 0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3BCCCCCD, 0x3C638E39, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9902, 0x80C0000, 0x30, 0x39,
    0xA010000, 0x3DCCCCCD, 0x3F800000, 0x3C4CCCCD, 0x3DAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9905, 0xA100000, 0x30, 0x39, 0xA010000, 0x3DB6DB6E,
    0x3F800000, 0x3C124925, 0x3D800000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x9906, 0xC1A0000, 0x2C, 0x5A, 0xC040000, 0x3DAAAAAB, 0x3E800000, 0x3BE38E39,
    0x3C1D89D9, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x990A, 0x18200000,
    0x41, 0x5A, 0xA030000, 0x3DCCCCCD, 0x3EAAAAAB, 0x3B888889, 0x3C2AAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x990B, 0xC100000, 0x41, 0x5A,
    0xA040000, 0x3DCCCCCD, 0x3E800000, 0x3C088889, 0x3C800000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x990D, 0x80C0000, 0x30, 0x39, 0xA010000, 0x3DCCCCCD,
    0x3F800000, 0x3C4CCCCD, 0x3DAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x9725, 0x14140000, 0x30, 0x3D, 0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3C23D70A,
    0x3C888889, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9A1E, 0x10100000,
    0x41, 0x5A, 0x8040000, 0x3E000000, 0x3E800000, 0x3C000000, 0x3C800000, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9A26, 0x10100000, 0x30, 0x39,
    0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3C4CCCCD, 0x3D000000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9A07, 0xC1A0000, 0x2C, 0x5A, 0xC040000, 0x3DAAAAAB,
    0x3E800000, 0x3BE38E39, 0x3C1D89D9, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0x9E29, 0x18100000, 0x30, 0x3C, 0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3C088889,
    0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9E22, 0x28340000,
    0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3BA3D70A, 0x3C1D89D9, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9E27, 0x38440000, 0x30, 0x39,
    0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3B6A0EA1, 0x3BF0F0F1, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0,
    (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0x9F0A, 0x20180000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD,
    0x3F000000, 0x3BCCCCCD, 0x3CAAAAAB, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000,
    0xBB02, 0x30240000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD, 0x3F000000, 0x3B888889,
    0x3C638E39, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0xBB04, 0x20180000,
    0x30, 0x3C, 0x5030000, 0x3E4CCCCD, 0x3EAAAAAB, 0x3BCCCCCD, 0x3C638E39, (u32)lbl_1_data_1AE94__fzgx_offset_0,
    0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000, 0xFFFFFFFF, 0x18180000, 0x0, 0x0,
    0x1010000, 0x3F800000, 0x3F800000, 0x3D2AAAAB, 0x3D2AAAAB, (u32)lbl_1_data_1AE9C__fzgx_offset_0, 0x1200000, (u32)lbl_1_data_1A3B8__fzgx_offset_0,
    (u32)lbl_1_bss_4BBA0__fzgx_offset_0, 0x3F800000, 0x9603, 0x18200000, 0x30, 0x39, 0x5020000, 0x3E4CCCCD,
    0x3F000000, 0x3C088889, 0x3C800000, (u32)lbl_1_data_1AE94__fzgx_offset_0, 0x0, (u32)lbl_1_data_1AE90__fzgx_offset_0, (u32)lbl_1_bss_4BB9C__fzgx_offset_0, 0x3F800000
};
static u32 fzgx_pool_data_lbl_1_data_1B848[288] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x464F4E54, 0x5F414456, 0x41435F43, 0x52454449, 0x545F4E55, 0x4D000000, 0x464F4E54, 0x5F414456,
    0x41435F53, 0x54415254, 0x5F4E554D, 0x0, 0x464F4E54, 0x5F415343, 0x5F387831, 0x36000000,
    0x464F4E54, 0x5F415343, 0x5F313278, 0x31320000, 0x464F4E54, 0x5F415343, 0x5F313478, 0x31360000,
    0x464F4E54, 0x5F415343, 0x5F313878, 0x31380000, 0x464F4E54, 0x5F415343, 0x5F313878, 0x31385F54,
    0x494D4500, 0x464F4E54, 0x5F415343, 0x5F53454C, 0x5F313278, 0x31360000, 0x464F4E54, 0x5F415343,
    0x5F53454C, 0x5F323478, 0x32340000, 0x464F4E54, 0x5F474152, 0x5F415343, 0x5F387831, 0x30000000,
    0x464F4E54, 0x5F524143, 0x5F415343, 0x5F54494D, 0x455F4E55, 0x4D000000, 0x464F4E54, 0x5F524143,
    0x5F464143, 0x455F4E55, 0x4D000000, 0x464F4E54, 0x5F524143, 0x5F52414E, 0x4B5F4E55, 0x4D000000,
    0x464F4E54, 0x5F524143, 0x5F52414E, 0x4B5F4E55, 0x4D5F5300, 0x464F4E54, 0x5F524143, 0x5F56535F,
    0x52414E4B, 0x5F4E554D, 0x0, 0x464F4E54, 0x5F524143, 0x5F535045, 0x45445F4E, 0x554D0000,
    0x464F4E54, 0x5F524143, 0x5F54494D, 0x455F4143, 0x0, 0x464F4E54, 0x5F524143, 0x5F54494D,
    0x455F4143, 0x5F530000, 0x464F4E54, 0x5F524553, 0x5F415343, 0x0, 0x464F4E54, 0x5F524553,
    0x5F415343, 0x5F54494D, 0x455F4E55, 0x4D000000, 0x464F4E54, 0x5F524553, 0x5F464143, 0x455F4E55,
    0x4D000000, 0x464F4E54, 0x5F524553, 0x5F4E414D, 0x455F4153, 0x43000000, 0x464F4E54, 0x5F524553,
    0x5F4E414D, 0x455F4153, 0x435F5300, 0x464F4E54, 0x5F524553, 0x5F54494D, 0x455F4E55, 0x4D000000,
    0x464F4E54, 0x5F524553, 0x5F54494D, 0x455F4E55, 0x4D5F5300, 0x464F4E54, 0x5F524553, 0x41435F4E,
    0x554D0000, 0x464F4E54, 0x5F524553, 0x47435F41, 0x53435F53, 0x53000000, 0x464F4E54, 0x5F524553,
    0x47435F41, 0x53435F59, 0x0, 0x464F4E54, 0x5F524553, 0x47435F43, 0x5553544F, 0x4D5F464F,
    0x4E540000, 0x464F4E54, 0x5F524553, 0x47435F50, 0x4C415445, 0x5F415343, 0x0, 0x464F4E54,
    0x5F524553, 0x47435F50, 0x4C415445, 0x5F415343, 0x5F530000, 0x464F4E54, 0x5F524553, 0x47435F56,
    0x5F415343, 0x0, 0x464F4E54, 0x5F524553, 0x5F56535F, 0x52414E4B, 0x5F4E554D, 0x0,
    0x464F4E54, 0x5F53454C, 0x5F4E414D, 0x455F4153, 0x43000000, 0x464F4E54, 0x5F53454C, 0x5F574549,
    0x4748545F, 0x4E554D00, 0x464F4E54, 0x5F53454C, 0x5F435553, 0x544F4D5F, 0x464F4E54, 0x0,
    0x464F4E54, 0x5F53454C, 0x41435F44, 0x4154415F, 0x4E554D00, 0x464F4E54, 0x5F53454C, 0x41435F54,
    0x494D455F, 0x4E554D00, 0x464F4E54, 0x5F53454C, 0x41435F54, 0x494D455F, 0x4E554D5F, 0x53000000,
    0x464F4E54, 0x5F53454C, 0x41465F43, 0x4F494E5F, 0x4E554D00, 0x464F4E54, 0x5F564945, 0x575F4C41,
    0x505F4E55, 0x4D000000, 0x464F4E54, 0x5F564945, 0x575F4E55, 0x4D000000, 0x464F4E54, 0x5F415343,
    0x5F323478, 0x32340000, 0x464F4E54, 0x5F524550, 0x5F535045, 0x45445F4E, 0x554D0000, (u32)lbl_1_data_1B848__fzgx_offset_0,
    (u32)lbl_1_data_1B860__fzgx_offset_0, (u32)lbl_1_data_1B878__fzgx_offset_0, (u32)lbl_1_data_1B888__fzgx_offset_0, (u32)lbl_1_data_1B898__fzgx_offset_0, (u32)lbl_1_data_1B8A8__fzgx_offset_0, (u32)lbl_1_data_1B8B8__fzgx_offset_0, (u32)lbl_1_data_1B8CC__fzgx_offset_0, (u32)lbl_1_data_1B8E0__fzgx_offset_0,
    (u32)lbl_1_data_1B8F4__fzgx_offset_0, (u32)lbl_1_data_1B908__fzgx_offset_0, (u32)lbl_1_data_1B920__fzgx_offset_0, (u32)lbl_1_data_1B934__fzgx_offset_0, (u32)lbl_1_data_1B948__fzgx_offset_0, (u32)lbl_1_data_1B95C__fzgx_offset_0, (u32)lbl_1_data_1B974__fzgx_offset_0, (u32)lbl_1_data_1B988__fzgx_offset_0,
    (u32)lbl_1_data_1B99C__fzgx_offset_0, (u32)lbl_1_data_1B9B0__fzgx_offset_0, (u32)lbl_1_data_1B9C0__fzgx_offset_0, (u32)lbl_1_data_1B9D8__fzgx_offset_0, (u32)lbl_1_data_1B9EC__fzgx_offset_0, (u32)lbl_1_data_1BA00__fzgx_offset_0, (u32)lbl_1_data_1BA14__fzgx_offset_0, (u32)lbl_1_data_1BA28__fzgx_offset_0,
    (u32)lbl_1_data_1BA3C__fzgx_offset_0, (u32)lbl_1_data_1BA4C__fzgx_offset_0, (u32)lbl_1_data_1BA60__fzgx_offset_0, (u32)lbl_1_data_1BA74__fzgx_offset_0, (u32)lbl_1_data_1BA8C__fzgx_offset_0, (u32)lbl_1_data_1BAA4__fzgx_offset_0, (u32)lbl_1_data_1BABC__fzgx_offset_0, (u32)lbl_1_data_1BAD0__fzgx_offset_0,
    (u32)lbl_1_data_1BAE8__fzgx_offset_0, (u32)lbl_1_data_1BAFC__fzgx_offset_0, (u32)lbl_1_data_1BB10__fzgx_offset_0, (u32)lbl_1_data_1BB28__fzgx_offset_0, (u32)lbl_1_data_1BB3C__fzgx_offset_0, (u32)lbl_1_data_1BB50__fzgx_offset_0, (u32)lbl_1_data_1BB68__fzgx_offset_0, (u32)lbl_1_data_1BB7C__fzgx_offset_0,
    (u32)lbl_1_data_1BB90__fzgx_offset_0, (u32)lbl_1_data_1BBA0__fzgx_offset_0, (u32)lbl_1_data_1BBB0__fzgx_offset_0, 0x4F524947, 0x494E414C, 0x0, 0x52454755, 0x4C415200,
    0x424F4C44, 0x0, 0x4954414C, 0x49430000, 0x424F4C44, 0x20495441, 0x4C494300, 0x54454741,
    0x4B490000, (u32)lbl_1_data_1BC74__fzgx_offset_0, (u32)lbl_1_data_1BC80__fzgx_offset_0, (u32)lbl_1_data_1BC88__fzgx_offset_0, (u32)lbl_1_data_1BC90__fzgx_offset_0, (u32)lbl_1_data_1BC98__fzgx_offset_0, (u32)lbl_1_data_1BCA4__fzgx_offset_0, 0x1
};
static u32 fzgx_pool_data_lbl_1_data_1BCC8[35] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x666F6E74, 0x2E630000, 0x63616E6E, 0x6F74204F, 0x53416C6C, 0x6F632061, 0x7420666F, 0x6E745F74,
    0x6573745F, 0x696E6974, 0xA000000, 0x30313233, 0x34353637, 0x38394142, 0x43444546, 0x4748494A,
    0x4B4C4D4E, 0x4F505152, 0x53545556, 0x5758595A, 0x61626364, 0x65666768, 0x696A6B6C, 0x6D6E6F70,
    0x71727374, 0x75767778, 0x797A2122, 0x23242526, 0x2728292A, 0x2B2C2D2E, 0x2F3A3B3C, 0x3D3E3F40,
    0x5B5C5D5E, 0x5F607B7C, 0x7D7E0000
};
static u32 fzgx_pool_data_lbl_1_data_1A3B8_199C[12] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x54455853, 0x70725075, 0x745F5375, 0x62203A20, 0x4E6F2072, 0x65676973, 0x74726174, 0x696F6E20,
    0x6F662043, 0x414C4C5F, 0x4241434B, 0x2E0A0000
};

#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_1A3B8(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1A3B8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1AEA8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1B848;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1BCC8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_1A3B8_199C;
}
#pragma section code_type ".text"

static const unsigned long fzgx_pool_table1[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.0f;
}
static const unsigned long fzgx_pool_table3[7] = {0xBF800000, 0x3F800000, 0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000};
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5999999046325684f;
}
static const unsigned long fzgx_pool_table5[7] = {0x00000000, 0x40266666, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.600000023841858f;
}
static const unsigned long fzgx_pool_table7[1] = {0xBF800000};
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.5999999046325684f;
}
static const unsigned long fzgx_pool_table9[5] = {0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000};
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.399999976158142f;
    s = 3.700000047683716f;
    s = 1.2999999523162842f;
}
static const unsigned long fzgx_pool_table11[2] = {0x00000000, 0x3FCCCCCD};
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = -0.8999999761581421f;
    s = -0.800000011920929f;
}
#define MTXA ((f32 (*)[4])LC_BASE)
/* GX write-gather pipe: every store is a FIFO write */
#define GX_FIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)

#pragma opt_lifetimes off
void fn_1_48D80(fn_1_48D80_Sprite *sprite) {
    /* the font data block also holds the texture table and the assert strings */
    Fn183D28Vec3 *p2;
    Fn183D28Vec3 *p3;
    Fn183D28Vec3 *p1;
    u32 texId;
    u32 mode = sprite->flags;
    Fn183D28Vec3 v3;
    Fn183D28Vec3 v2;
    Fn183D28Vec3 v1;
    Fn183D28Vec3 v0;
    static const Fn183D28Vec3 initialV0 = {0.0f, 0.0f, 0.0f};
    static const Fn183D28Vec3 initialV1 = {0.0f, 0.0f, 0.0f};
    static const Fn183D28Vec3 initialV2 = {0.0f, 0.0f, 0.0f};
    static const Fn183D28Vec3 initialV3 = {0.0f, 0.0f, 0.0f};
    fn_1_48D80_Color addColor;
    fn_1_48D80_Color color;
    u32 id;
    u32 flags;
    f32 x;
    f32 y;
    f32 z;
    f32 width;
    f32 height;
    f32 u0;
    f32 u1;
    f32 t0;
    f32 t1;
    f32 m2;
    f32 m1;
    f32 m0;
    f64 half;
    f32 offset;

    v0 = initialV0;
    v1 = initialV1;
    v2 = initialV2;
    v3 = initialV3;
    p1 = &v1;
    p2 = &v2;
    p3 = &v3;
    fn_1_4E638(mode & 0x40000);
    id = sprite->id;
    z = -sprite->z;
{
    fn_1_48D80_TexInfo *tex;
    tex = (fn_1_48D80_TexInfo *)(((u8 *)fzgx_pool_data_lbl_1_data_1AEA8)) + ((id >> 16) & 0xFF);
    texId = id & 0xFFFF;
    x = sprite->x;
    width = tex->width;
    y = sprite->y;
    height = tex->height;
}

    switch (sprite->flags & 3) {
    case 1:
    default:
        v3.x = width;
        v2.x = 0.0f;
        v0.x = 0.0f;
        v1.x = width;
        break;
    case 2:
        half = 0.5;
        v0.x = v2.x = -width * half;
        v1.x = v3.x = width * half;
        break;
    case 3:
        v3.x = 0.0f;
        v2.x = -width;
        v0.x = -width;
        v1.x = 0.0f;
        break;
    }

    switch ((sprite->flags >> 2) & 3) {
    case 1:
    default:
        v3.y = height;
        v1.y = 0.0f;
        v0.y = 0.0f;
        v2.y = height;
        break;
    case 2:
        half = 0.5;
        v0.y = v1.y = -height * half;
        v2.y = v3.y = height * half;
        break;
    case 3:
        v3.y = 0.0f;
        v1.y = -height;
        v0.y = -height;
        v2.y = 0.0f;
        break;
    }

    if ((sprite->flags & 0x8000000) && (fn_1_A6F1C() == 1 || fn_1_A6F1C() == 2)) {
        lbl_8006D7F4(sprite->offsetX, 0.0f, 0.0f);
        lbl_8006E15C(0.75f, 1.0f, 1.0f);
        {
            offset = -sprite->offsetX;
            m2 = MTXA[2][0];
            m1 = MTXA[1][0];
            m0 = MTXA[0][0];
            m0 = MTXA[0][3] + m0 * offset;
            m1 = MTXA[1][3] + m1 * offset;
            m2 = MTXA[2][3] + m2 * offset;
            MTXA[0][3] = m0;
            MTXA[1][3] = m1;
            MTXA[2][3] = m2;
        }
        lbl_8006E0B4(x, y, 0.0f);
    } else {
        lbl_8006D7F4(x, y, 0.0f);
    }
    mathutil_mtxA_rotate_z(-sprite->rot);
    lbl_8006E15C(sprite->scaleX, sprite->scaleY, 1.0f);
    lbl_8006E1B0(&v0, &v0);
    lbl_8006E1B0(p1, p1);
    lbl_8006E1B0(p2, p2);
    lbl_8006E1B0(p3, p3);
    fn_1_492F0(sprite, &v0);
    fn_80073778(lbl_1_bss_40C6C + texId * 32, 0);

    if (sprite->flags & 0x10000000) {
        color.r = sprite->color.r;
        color.g = sprite->color.g;
        color.b = sprite->color.b;
        color.a = 255.0f * sprite->alpha;
        fn_800371F8(1, color);
        fn_800371F8(2, sprite->addColor);
    } else {
        color.r = 0;
        color.g = 0;
        color.b = 0;
        color.a = 255.0f * sprite->alpha;
        addColor.r = sprite->color.r + sprite->addColor.r;
        addColor.g = sprite->color.g + sprite->addColor.g;
        addColor.b = sprite->color.b + sprite->addColor.b;
        addColor.a = 0;
        fn_800371F8(1, color);
        fn_800371F8(2, addColor);
    }

    u0 = sprite->u0;
    u1 = sprite->u1;
    t0 = sprite->v0;
    t1 = sprite->v1;
    if (sprite->flags & 0x4000000) {
        if (sprite->draw != NULL) {
            sprite->draw(sprite, &v0);
        } else {
            OSPanic((char *)((u8 *)fzgx_pool_data_lbl_1_data_1BCC8), 740, (char *)((u8 *)fzgx_pool_data_lbl_1_data_1A3B8_199C));
        }
    }

    fn_8003462C(0x80, 7, 4);
    /* Keep the initial coordinate and flag snapshot ordered with FIFO submission. */
    {
        f32 firstX = *(volatile f32 *)&v0.x; /* ordered submission snapshot */
        flags = *(volatile u32 *)&sprite->flags; /* ordered submission snapshot */
        GX_FIFO_F32 = firstX;
    }
    GX_FIFO_F32 = v0.y;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = u0;
    GX_FIFO_F32 = t0;
    GX_FIFO_F32 = v1.x;
    GX_FIFO_F32 = v1.y;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = u1;
    GX_FIFO_F32 = t0;
    GX_FIFO_F32 = v3.x;
    GX_FIFO_F32 = v3.y;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = u1;
    GX_FIFO_F32 = t1;
    GX_FIFO_F32 = v2.x;
    GX_FIFO_F32 = v2.y;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = u0;
    GX_FIFO_F32 = t1;

    if (flags & 0x4000000) {
        fn_1_4E0F4();
        fn_80074188(0, 0, fn_1_A5D88(), fn_1_A5DB0());
    }
}
/* fzgx:end fn_1_48D80 */

/* fzgx:begin fn_1_492F0 noprologue */
#include "dolphin/types.h"

const f32 lbl_1_rodata_FD0[60] = {
    0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,
    0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,
    -1.0f,-1.0f,1.0f,-1.0f,-1.0f,1.0f,1.0f,1.0f,
    2.6f,0.0f,2.6f,0.0f,0.0f,0.0f,0.0f,0.0f,
    1.6f,-1.0f,3.6f,-1.0f,-1.0f,1.0f,1.0f,1.0f,
    -1.4f,3.7f,1.3f,0.0f,1.6f,0.5f,-0.9f,-0.8f,
    0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,
    0.0f,0.0f,0.0f,0.0f
};
const f32 lbl_1_rodata_10C0[2] = {0.0f, 0.0f};
typedef struct ShapeParams {
    u32 flags;
    u8 pad[12];
    f32 width;
    f32 height;
} ShapeParams;

#pragma push
#pragma section code_type ".fzgxpool"
void fzgx_fn_1_492F0_pool_primer(f64 *p, f32 *q)
{
    p[0] = 0.5;
    q[0] = 0.75f;
    q[1] = 1.0f;
}
#pragma pop

#pragma fp_contract off
void fn_1_492F0(ShapeParams *arg, f32 out[4][3])
{
    f32 width = 1.0f + arg->width;
    f32 height = 1.0f + arg->height;
    s32 index = (s8)(arg->flags >> 24);
    if (index) {
        const f32 *row = &lbl_1_rodata_FD0[index * 8];
        out[0][0] += 0.5 * row[0] * width;
        out[0][1] += 0.5 * row[1] * height;
        out[1][0] += 0.5 * row[2] * width;
        out[1][1] += 0.5 * row[3] * height;
        out[2][0] += 0.5 * row[4] * width;
        out[2][1] += 0.5 * row[5] * height;
        out[3][0] += 0.5 * row[6] * width;
        out[3][1] += 0.5 * row[7] * height;
    }
}
/* fzgx:end fn_1_492F0 */

/* fzgx:begin fn_1_49410 */
struct fn_1_49410_lbl_1_rodata_FD0 {
    u8 pad_0[0xF0];
    f32 unk_F0;
    u8 pad_F4[0xC];
    f32 unk_100;
    f32 unk_104;
    u8 pad_108[0x10];
    u32 unk_118;
    u32 unk_11C;
    f32 unk_120;
};
struct fn_1_49410_lbl_1_bss_4B9CC {
    u8 pad_0[0xC];
    u16 unk_C;
    u16 unk_E;
    u32 unk_10;
    u32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u32 unk_2C;
    u16 unk_30;
    u16 unk_32;
    u16 unk_34;
    u8 unk_36;
    u8 unk_37;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    u8 unk_44;
    u8 unk_45;
    u8 unk_46;
    u8 unk_47;
    u16 unk_48;
    u16 unk_4A;
    u16 unk_4C;
    u16 unk_4E;
    f32 unk_50;
    u32 unk_54;
    u32 unk_58;
};





void fn_1_49410(void) {
    f32 fzgx_live;
    struct fn_1_49410_lbl_1_rodata_FD0 *q = &(*(struct fn_1_49410_lbl_1_rodata_FD0 *)&lbl_1_rodata_FD0);

    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_C = 42;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_10 = q->unk_118;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_14 = q->unk_11C;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_E = 0;
    fzgx_live = q->unk_120;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_18 = fzgx_live;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_1C = q->unk_104;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_20 = q->unk_104;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_24 = q->unk_104;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_28 = q->unk_104;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_2C = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_36 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_30 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_32 = 2;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_34 = 2;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_38 = q->unk_100;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_37 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_3C = q->unk_F0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_40 = q->unk_F0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_44 = 1;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_45 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_54 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_50 = q->unk_F0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_46 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_47 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_48 = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_4A = 0;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_4C = 640;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_4E = 480;
    (*(struct fn_1_49410_lbl_1_bss_4B9CC *)&lbl_1_bss_4B9CC).unk_58 = 5;
}
/* fzgx:end fn_1_49410 */

/* fzgx:begin fn_1_494CC */
void fn_1_494CC(u8 value) {
    lbl_1_bss_4B9CC.unk_44 = value;
}
/* fzgx:end fn_1_494CC */

/* fzgx:begin fn_1_494DC */
void fn_1_494DC(s16 index) {
    lbl_1_bss_4B9CC.unk_C = index;
    fn_1_4955C(lbl_1_rodata_10D4, lbl_1_rodata_10D4);
}
/* fzgx:end fn_1_494DC */

/* fzgx:begin fn_1_49514 */
void fn_1_49514(u32 *value) {
    lbl_1_bss_4B9CC.unk_10 = *value;
}
/* fzgx:end fn_1_49514 */

/* fzgx:begin fn_1_49528 */
void fn_1_49528(u32 *value) {
    lbl_1_bss_4B9CC.unk_14 = *value;
}
/* fzgx:end fn_1_49528 */

/* fzgx:begin fn_1_4953C */
void fn_1_4953C(s16 value) {
    lbl_1_bss_4B9CC.unk_E = value;
}
/* fzgx:end fn_1_4953C */

/* fzgx:begin fn_1_4954C */
void fn_1_4954C(f32 value) {
    lbl_1_bss_4B9CC.unk_18 = value;
}
/* fzgx:end fn_1_4954C */

/* fzgx:begin fn_1_4955C */
void fn_1_4955C(f32 value1, f32 value2) {
    s16 index = lbl_1_bss_4B9CC.unk_C;
    Obj_1_data_1AEA8 *font = (Obj_1_data_1AEA8 *)((u8 *)&lbl_1_data_1AEA8 + index * 0x38);
    f32 scale = font->unk_34;

    // Scale both font dimensions using the active font's metrics.
    lbl_1_bss_4B9CC.unk_1C = value1 * scale;
    lbl_1_bss_4B9CC.unk_20 = value2 * scale;
}
/* fzgx:end fn_1_4955C */

/* fzgx:begin fn_1_49590 */
void fn_1_49590(f32 value) {
    lbl_1_bss_4B9CC.unk_24 = value;
}
/* fzgx:end fn_1_49590 */

/* fzgx:begin fn_1_495A0 */
void fn_1_495A0(f32 value) {
    lbl_1_bss_4B9CC.unk_28 = value;
}
/* fzgx:end fn_1_495A0 */

/* fzgx:begin fn_1_495B0 */
void fn_1_495B0(u32 value) {
    lbl_1_bss_4B9CC.unk_2C |= value;
}
/* fzgx:end fn_1_495B0 */

/* fzgx:begin fn_1_495C8 */
void fn_1_495C8(u8 value) {
    // Update the current font state flag.
    lbl_1_bss_4B9CC.unk_36 = value;
}
/* fzgx:end fn_1_495C8 */

/* fzgx:begin fn_1_495D8 */
void fn_1_495D8(u16 value1, u16 value2, f32 value3) {
    lbl_1_bss_4B9CC.unk_32 = value1;
    lbl_1_bss_4B9CC.unk_2C |= 0x40000000;
    lbl_1_bss_4B9CC.unk_34 = value2;
    lbl_1_bss_4B9CC.unk_38 = value3;
}
/* fzgx:end fn_1_495D8 */

/* fzgx:begin fn_1_495FC */
void fn_1_495FC(void) {
    lbl_1_bss_4B9CC.unk_2C |= 0x40000000;
}
/* fzgx:end fn_1_495FC */

/* fzgx:begin fn_1_49614 */
void fn_1_49614(void) {
    lbl_1_bss_4B9CC.unk_2C &= 0xBFFFFFFF;
}
/* fzgx:end fn_1_49614 */

/* fzgx:begin fn_1_4962C */
void fn_1_4962C(void) {
    lbl_1_bss_4B9CC.unk_2C |= 0x20000000;
}
/* fzgx:end fn_1_4962C */

/* fzgx:begin fn_1_49644 */
void fn_1_49644(void) {
    lbl_1_bss_4B9CC.unk_2C &= 0xDFFFFFFF;
}
/* fzgx:end fn_1_49644 */

/* fzgx:begin fn_1_4965C */
void fn_1_4965C(u8 value) {
    lbl_1_bss_4B9CC.unk_37 = value;
}
/* fzgx:end fn_1_4965C */

/* fzgx:begin fn_1_4966C */
void fn_1_4966C(f32 value1, f32 value2) {
    // Store the two font scale values used by the renderer.
    lbl_1_bss_4B9CC.unk_3C = value1;
    lbl_1_bss_4B9CC.unk_40 = value2;
}
/* fzgx:end fn_1_4966C */

/* fzgx:begin fn_1_49680 */
// Scale the active font entry's byte dimensions into the shared bounds.
void fn_1_49680(f32 value1, f32 value2) {
    Obj_1_data_1AEA8 *entry;
    s16 index;
    f32 result1;
    f32 result2;

    index = lbl_1_bss_4B9CC.unk_C;
    entry = (Obj_1_data_1AEA8 *)((u8 *)&lbl_1_data_1AEA8 + index * 0x38);
    result1 = entry->unk_34 * (value1 * entry->unk_4);
    result2 = entry->unk_34 * (value2 * entry->unk_5);
    lbl_1_bss_4B9CC.unk_4 = result1;
    lbl_1_bss_4B9CC.unk_0 = result1;
    lbl_1_bss_4B9CC.unk_8 = result2;
}
/* fzgx:end fn_1_49680 */

/* fzgx:begin fn_1_496FC */
 // Store the two font coordinates in the shared state.
void fn_1_496FC(f32 value1, f32 value2) {
    lbl_1_bss_4B9CC.unk_4 = value1;
    lbl_1_bss_4B9CC.unk_0 = value1;
    lbl_1_bss_4B9CC.unk_8 = value2;
}
/* fzgx:end fn_1_496FC */

/* fzgx:begin fn_1_49714 */
void fn_1_49714(f32 value1, f32 value2, f32 value3) {
    lbl_1_bss_4B9CC.unk_0 = value3;
    lbl_1_bss_4B9CC.unk_4 = value1;
    lbl_1_bss_4B9CC.unk_8 = value2;
}
/* fzgx:end fn_1_49714 */

/* fzgx:begin fn_1_49728 */
void fn_1_49728(u8 value) {
    lbl_1_bss_4B9CC.unk_45 = value;
}
/* fzgx:end fn_1_49728 */

/* fzgx:begin fn_1_49738 */
 // Store the supplied value in the font state used by subsequent rendering.
void fn_1_49738(u32 value) {
    lbl_1_bss_4B9CC.unk_54 = value;
}
/* fzgx:end fn_1_49738 */

/* fzgx:begin fn_1_49748 */
void fn_1_49748(f32 value) {
    lbl_1_bss_4B9CC.unk_50 = value;
}
/* fzgx:end fn_1_49748 */

/* fzgx:begin fn_1_49758 */
void fn_1_49758(u8 value) {
    lbl_1_bss_4B9CC.unk_46 = value;
}
/* fzgx:end fn_1_49758 */

/* fzgx:begin fn_1_49768 */
void fn_1_49768(u8 value) {
    lbl_1_bss_4B9CC.unk_47 = value;
}
/* fzgx:end fn_1_49768 */

/* fzgx:begin fn_1_49778 */
void fn_1_49778(s16 value1, s16 value2, s16 value3, s16 value4) {
    lbl_1_bss_4B9CC.unk_48 = value1;
    lbl_1_bss_4B9CC.unk_4A = value2;
    lbl_1_bss_4B9CC.unk_4C = value3;
    lbl_1_bss_4B9CC.unk_4E = value4;
}
/* fzgx:end fn_1_49778 */

/* fzgx:begin fn_1_49794 */
u8 lbl_1_data_1BCC8[0xBC] = {
    0x66U, 0x6FU, 0x6EU, 0x74U, 0x2EU, 0x63U, 0x00U, 0x00U, 0x63U, 0x61U, 0x6EU, 0x6EU, 0x6FU, 0x74U, 0x20U, 0x4FU, 0x53U, 0x41U, 0x6CU, 0x6CU, 0x6FU, 0x63U, 0x20U, 0x61U, 0x74U, 0x20U, 0x66U, 0x6FU, 0x6EU, 0x74U, 0x5FU, 0x74U, 0x65U, 0x73U, 0x74U, 0x5FU, 0x69U, 0x6EU, 0x69U, 0x74U, 0x0AU, 0x00U, 0x00U, 0x00U, 0x30U, 0x31U, 0x32U, 0x33U, 0x34U, 0x35U, 0x36U, 0x37U, 0x38U, 0x39U, 0x41U, 0x42U, 0x43U, 0x44U, 0x45U, 0x46U, 0x47U, 0x48U, 0x49U, 0x4AU, 0x4BU, 0x4CU, 0x4DU, 0x4EU, 0x4FU, 0x50U, 0x51U, 0x52U, 0x53U, 0x54U, 0x55U, 0x56U, 0x57U, 0x58U, 0x59U, 0x5AU, 0x61U, 0x62U, 0x63U, 0x64U, 0x65U, 0x66U, 0x67U, 0x68U, 0x69U, 0x6AU, 0x6BU, 0x6CU, 0x6DU, 0x6EU, 0x6FU, 0x70U, 0x71U, 0x72U, 0x73U, 0x74U, 0x75U, 0x76U, 0x77U, 0x78U, 0x79U, 0x7AU, 0x21U, 0x22U, 0x23U, 0x24U, 0x25U, 0x26U, 0x27U, 0x28U, 0x29U, 0x2AU, 0x2BU, 0x2CU, 0x2DU, 0x2EU, 0x2FU, 0x3AU, 0x3BU, 0x3CU, 0x3DU, 0x3EU, 0x3FU, 0x40U, 0x5BU, 0x5CU, 0x5DU, 0x5EU, 0x5FU, 0x60U, 0x7BU, 0x7CU, 0x7DU, 0x7EU, 0x00U, 0x00U, 0x54U, 0x45U, 0x58U, 0x53U, 0x70U, 0x72U, 0x50U, 0x75U, 0x74U, 0x5FU, 0x53U, 0x75U, 0x62U, 0x20U, 0x3AU, 0x20U, 0x4EU, 0x6FU, 0x20U, 0x72U, 0x65U, 0x67U, 0x69U, 0x73U, 0x74U, 0x72U, 0x61U, 0x74U, 0x69U, 0x6FU, 0x6EU, 0x20U, 0x6FU, 0x66U, 0x20U, 0x43U, 0x41U, 0x4CU, 0x4CU, 0x5FU, 0x42U, 0x41U, 0x43U, 0x4BU, 0x2EU, 0x0AU, 0x00U, 0x00U
};

u32 fn_1_49794(u32 c) {
    if ((u16)c >= 'A' && (u16)c <= 'Z') {
        return c + 0x821F;
    }
    if ((u16)c >= 'a' && (u16)c <= 'z') {
        return c + 0x8220;
    }
    if ((u16)c >= '0' && (u16)c <= '9') {
        return c + 0x821F;
    }

    switch ((u8)c) {
    case '!':
        return 0x8149;
    case '"':
        return 0x8168;
    case '#':
        return 0x8194;
    case '$':
        return 0x8190;
    case '%':
        return 0x8193;
    case '&':
        return 0x8195;
    case '\'':
        return 0x8166;
    case '(':
        return 0x8169;
    case ')':
        return 0x816A;
    case '*':
        return 0x8196;
    case '+':
        return 0x817B;
    case ',':
        return 0x8143;
    case '-':
        return 0x817C;
    case '.':
        return 0x8144;
    case '/':
        return 0x815E;
    case ':':
        return 0x8146;
    case ';':
        return 0x8147;
    case '<':
        return 0x8171;
    case '=':
        return 0x8181;
    case '>':
        return 0x8172;
    case '?':
        return 0x8148;
    case '@':
        return 0x8197;
    case '[':
        if ((s32)lbl_1_bss_3E058 == 0) {
            return 0x816D;
        }
        break;
    case '\\':
        return 0x815F;
    case ']':
        if ((s32)lbl_1_bss_3E058 == 0) {
            return 0x816E;
        }
        break;
    case '^':
        return 0x814F;
    case '_':
        return 0x8151;
    case '`':
        return 0x8165;
    case '{':
        return 0x816F;
    case '|':
        return 0x8162;
    case '}':
        return 0x8170;
    case '~':
        return 0x8160;
    }

    return c;
}
/* fzgx:end fn_1_49794 */

/* fzgx:begin fn_1_499BC */
u16 fn_1_499BC(const u8 *value) {
    u16 result;
    s32 i;
    s32 shift;
    const u8 *p;

    if (value[0] != 'c') {
        return value[0];
    }
    if (value[1] != '0') {
        return value[0];
    }
    p = value + 2;
    if (value[2] != 'x') {
        return value[0];
    }
    result = 0;
    shift = 12;
    for (i = 0; i < 4; i++) {
        switch (p[i + 1]) {
        case '0':
            break;
        case '1':
            result |= 1 << shift;
            break;
        case '2':
            result |= 2 << shift;
            break;
        case '3':
            result |= 3 << shift;
            break;
        case '4':
            result |= 4 << shift;
            break;
        case '5':
            result |= 5 << shift;
            break;
        case '6':
            result |= 6 << shift;
            break;
        case '7':
            result |= 7 << shift;
            break;
        case '8':
            result |= 8 << shift;
            break;
        case '9':
            result |= 9 << shift;
            break;
        case 'a':
            result |= 10 << shift;
            break;
        case 'b':
            result |= 11 << shift;
            break;
        case 'c':
            result |= 12 << shift;
            break;
        case 'd':
            result |= 13 << shift;
            break;
        case 'e':
            result |= 14 << shift;
            break;
        case 'f':
            result |= 15 << shift;
            break;
        default:
            break;
        }
        shift -= 4;
    }
    return result;
}
/* fzgx:end fn_1_499BC */

/* fzgx:begin fn_1_49B70 */
typedef struct {
    u8 pad_0[0x10];
    u32 unk_10;
    u32 unk_14;
    u8 pad_18[0x10];
    f32 unk_28;
} UnkArg1;

extern f32 lbl_1_rodata_10D8;
extern f64 lbl_1_rodata_10E0[3];

s32 fn_1_49B70(u8 *arg0, UnkArg1 *arg1) {
    /* volatile: retail reloads the accumulator from the frame in every case arm */
    volatile u32 flags;
    u32 c1;
    s32 i;
    s32 shift;
    s32 mode;
    u8 *p;
    s32 n;
    s32 ret;

    flags = 0;
    if (arg0[0] != 0x2F) {
        return 0;
    }
    c1 = arg0[1];
    if (c1 == 0x62 || c1 == 0x6F) {
        mode = (((0x62 - c1) | (c1 - 0x62)) >> 31);
        p = arg0 + 2;
        if (arg0[2] != 0x63) {
            return 0;
        }
        if (p[7] != 0x2F) {
            return 0;
        }
        n = 3;
        shift = 0x1C;
        ret = 9;
    } else if (c1 == 0x74) {
        p = arg0 + 2;
        if (arg0[2] != 0x72) {
            return 0;
        }
        if (p[3] != 0x2F) {
            return 0;
        }
        mode = 2;
        n = 1;
        shift = 4;
        ret = 5;
    } else {
        return 0;
    }
    for (i = 0; i < n * 2; i++, shift -= 4) {
        switch (p[i + 1]) {
        case 0x30:
            break;
        case 0x31:
            flags |= 1 << shift;
            break;
        case 0x32:
            flags |= 2 << shift;
            break;
        case 0x33:
            flags |= 3 << shift;
            break;
        case 0x34:
            flags |= 4 << shift;
            break;
        case 0x35:
            flags |= 5 << shift;
            break;
        case 0x36:
            flags |= 6 << shift;
            break;
        case 0x37:
            flags |= 7 << shift;
            break;
        case 0x38:
            flags |= 8 << shift;
            break;
        case 0x39:
            flags |= 9 << shift;
            break;
        case 0x61:
            flags |= 0xA << shift;
            break;
        case 0x41:
            flags |= 0xA << shift;
            break;
        case 0x62:
            flags |= 0xB << shift;
            break;
        case 0x42:
            flags |= 0xB << shift;
            break;
        case 0x63:
            flags |= 0xC << shift;
            break;
        case 0x43:
            flags |= 0xC << shift;
            break;
        case 0x64:
            flags |= 0xD << shift;
            break;
        case 0x44:
            flags |= 0xD << shift;
            break;
        case 0x65:
            flags |= 0xE << shift;
            break;
        case 0x45:
            flags |= 0xE << shift;
            break;
        case 0x66:
            flags |= 0xF << shift;
            break;
        case 0x46:
            flags |= 0xF << shift;
            break;
        }
    }
    switch (mode) {
    case 0:
        if (arg1 != NULL) {
            arg1->unk_10 = flags;
        }
        break;
    case 1:
        if (arg1 != NULL) {
            arg1->unk_14 = flags;
        }
        break;
    case 2:
        if (arg1 != NULL) {
            arg1->unk_28 = flags / lbl_1_rodata_10D8;
        }
        break;
    }
    return ret;
}

char lbl_1_data_1C0B4[2] = " ";
/* fzgx:end fn_1_49B70 */

/* fzgx:begin fn_1_49F08 */
typedef struct FontCharEntry {
    const u8 *unk_0;
    s8 unk_4;
    s8 unk_5;
} FontCharEntry;

/* font.c's .rodata from its start, in retail bytes: MWCC addresses this function's literal (0x10E0) and its character
 * tables off one section base, so the unit defines everything up to the last table; the tables' string pointers
 * (relocations in retail) read as 0 */
static const u32 fzgx_pool_rodata_FD0[(0x10E0 - 0xFD0) / 4] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBF800000, 0xBF800000, 0x3F800000, 0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x40266666, 0x00000000, 0x40266666, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3FCCCCCD, 0xBF800000, 0x40666666, 0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000, 0xBFB33333, 0x406CCCCD, 0x3FA66666, 0x00000000, 0x3FCCCCCD, 0x3F000000, 0xBF666666, 0xBF4CCCCD, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3FE00000, 0x00000000, 0x3F400000, 0x3F800000, 0x437F0000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_10E0(void) {
    volatile f64 d;  /* fzgx-allow: S2 pool primer sink */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_rodata_10E8[(0x1100 - 0x10E8) / 4] = {0xFFFFFFFF, 0x00000000, 0x3D4CCCCD, 0x00000000, 0x43300000, 0x80000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1100[(0x1320 - 0x1100) / 4] = {0x00000000, 0x000D0000, 0x00000000, 0x070D0000, 0x00000000, 0x010B0000, 0x00000000, 0x010C0000, 0x00000000, 0x02070000, 0x00000000, 0x02070000, 0x00000000, 0x08090000, 0x00000000, 0x08090000, 0x00000000, 0x10080000, 0x00000000, 0x01080000, 0x00000000, 0x0D0B0000, 0x00000000, 0x010B0000, 0x00000000, 0x010A0000, 0x00000000, 0x0C0A0000, 0x00000000, 0x060E0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x070B0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x09070000, 0x00000000, 0x060A0000, 0x00000000, 0x060F0000, 0x00000000, 0x09070000, 0x00000000, 0x03140000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x070B0000, 0x00000000, 0x050E0000, 0x00000000, 0x070B0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x02150000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04110000, 0x00000000, 0x05100000, 0x00000000, 0x04110000, 0x00000000, 0x04120000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04110000, 0x00000000, 0x04110000, 0x00000000, 0x09070000, 0x00000000, 0x050C0000, 0x00000000, 0x05110000, 0x00000000, 0x060E0000, 0x00000000, 0x02140000, 0x00000000, 0x04110000, 0x00000000, 0x04120000, 0x00000000, 0x05100000, 0x00000000, 0x04120000, 0x00000000, 0x05100000, 0x00000000, 0x060F0000, 0x00000000, 0x060E0000, 0x00000000, 0x04110000, 0x00000000, 0x05110000, 0x00000000, 0x01170000, 0x00000000, 0x03120000, 0x00000000, 0x04110000, 0x00000000, 0x04100000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1320[(0x1398 - 0x1320) / 4] = {0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00090000, 0x00000000, 0x000D0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1398[(0x1410 - 0x1398) / 4] = {0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00090000, 0x00000000, 0x000D0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1410[(0x14E8 - 0x1410) / 4] = {0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x04080000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_14E8[(0x15C0 - 0x14E8) / 4] = {0x00000000, 0x00190000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00120000, 0x00000000, 0x00110000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x000B0000, 0x00000000, 0x000F0000, 0x00000000, 0x00180000, 0x00000000, 0x00110000, 0x00000000, 0x001D0000, 0x00000000, 0x00150000, 0x00000000, 0x00170000, 0x00000000, 0x00150000, 0x00000000, 0x00170000, 0x00000000, 0x00160000, 0x00000000, 0x00180000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00190000, 0x00000000, 0x001F0000, 0x00000000, 0x00180000, 0x00000000, 0x00170000, 0x00000000, 0x00130000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_15C0[(0x1698 - 0x15C0) / 4] = {0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x000B0000, 0x00000000, 0x00080000, 0x00000000, 0x000D0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000F0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1698[(0x1700 - 0x1698) / 4] = {0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00080000, 0x00000000, 0x000E0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1700[(0x1888 - 0x1700) / 4] = {0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x00060000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000F0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000F0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x00050000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1888[(0x1A08 - 0x1888) / 4] = {0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00050000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1A08[(0x1A78 - 0x1A08) / 4] = {0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0xFD070000, 0x00000000, 0xFD050000, 0x00000000, 0xFD090000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1A78[(0x1AE8 - 0x1A78) / 4] = {0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0xFE050000, 0x00000000, 0xFE030000, 0x00000000, 0xFE060000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1AE8[(0x1B58 - 0x1AE8) / 4] = {0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0xFD0C0000, 0x00000000, 0xFD080000, 0x00000000, 0xFD0A0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1B58[(0x1E38 - 0x1B58) / 4] = {0x00000000, 0x000C0000, 0x00000000, 0x00020000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000A0000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00040000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x00020000, 0x00000000, 0x00060000, 0x00000000, 0x00020000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00020000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00040000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x000C0000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x000A0000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1E38[(0x2118 - 0x1E38) / 4] = {0x00000000, 0x000C0000, 0x00000000, 0x0A040000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x04100000, 0x00000000, 0x00060000, 0x00000000, 0x08080000, 0x00000000, 0x08080000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x09060000, 0x00000000, 0x050E0000, 0x00000000, 0x0A040000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x070A0000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x0A040000, 0x00000000, 0x0A040000, 0x00000000, 0x09060000, 0x00000000, 0x09060000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x070A0000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x050E0000, 0x00000000, 0x03120000, 0x00000000, 0x050E0000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x02140000, 0x00000000, 0x08080000, 0x00000000, 0x070A0000, 0x00000000, 0x03120000, 0x00000000, 0x08080000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x060E0000, 0x00000000, 0x060C0000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x02140000, 0x00000000, 0x050E0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_2118[(0x23C0 - 0x2118) / 4] = {0x00000000, 0x00120000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x010F0000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x000E0000, 0x00000000, 0x05080000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x020E0000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_23C0[(0x2668 - 0x23C0) / 4] = {0x00000000, 0x00120000, 0x00000000, 0x07040000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x010F0000, 0x00000000, 0x06080000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x000E0000, 0x00000000, 0x05080000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x07040000, 0x00000000, 0x07040000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x020E0000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x07040000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static void fzgx_pool_keep(void) {
    const u32 *volatile cp;  /* fzgx-allow: S2 pool primer sink */
    cp = fzgx_pool_rodata_FD0;
    cp = fzgx_pool_rodata_10E8;
}
#pragma section code_type ".text"

#define CHAR_TABLE(addr) ((const FontCharEntry *)fzgx_pool_rodata_##addr)

/* The advance of character c: the font's width byte (+0x4), scaled by state +0x24 for a space; when state +0x2C has
 * bit 31 set, the entry for c in the character table of font id state +0xC, as (unk_4 << 16) | unk_5.
 * GC/2.5 with __restrict: retail loads font +0x4 before the LR save, which 1.3.2 never does. */
char lbl_1_data_1C300[2] = "\"";

u32 fn_1_49F08(u16 c, Obj_1_bss_4B9CC *state, Obj_1_data_1AEA8 *__restrict font) {
    const FontCharEntry *entry;
    u32 adv;
    s32 found;
    const u8 *str;
    u8 b;

    adv = font->unk_4;
    if (c == ' ') {
        return adv * state->unk_24;
    }
    if (!(state->unk_2C & 0x80000000)) {
        return adv;
    }
    entry = NULL;
    found = 0;
    switch (state->unk_C) {
    case 5: entry = CHAR_TABLE(2118); break;
    case 6: entry = CHAR_TABLE(23C0); break;
    case 42: entry = CHAR_TABLE(1100); break;
    case 7: entry = CHAR_TABLE(1B58); break;
    case 8: entry = CHAR_TABLE(1E38); break;
    case 33: entry = CHAR_TABLE(1410); break;
    case 10: entry = CHAR_TABLE(1320); break;
    case 29: entry = CHAR_TABLE(14E8); break;
    case 30: entry = CHAR_TABLE(15C0); break;
    case 18: entry = CHAR_TABLE(1698); break;
    case 21: entry = CHAR_TABLE(1700); break;
    case 22: entry = CHAR_TABLE(1888); break;
    case 19: entry = CHAR_TABLE(1398); break;
    case 25: entry = CHAR_TABLE(1A08); break;
    case 41: entry = CHAR_TABLE(1AE8); break;
    case 36: entry = CHAR_TABLE(1A78); break;
    }
    if (entry != NULL) {
        if (c > 0x80) {
            /* a two-byte character: match both bytes */
            for (; entry->unk_5 != 0; entry++) {
                str = entry->unk_0;
                if (str[0] >= 0x80 && c == (u16)((str[0] << 8) | str[1])) {
                    found = 1;
                    break;
                }
            }
        } else {
            for (; entry->unk_5 != 0; entry++) {
                b = entry->unk_0[0];
                if (b <= 0x80 && b == c) {
                    found = 1;
                    break;
                }
            }
        }
        if (found) {
            adv = (entry->unk_4 << 16) | entry->unk_5;
        }
    }
    return adv;
}

u8 lbl_1_data_1C39C[0x164] = {
    0x41U, 0x52U, 0x41U, 0x4DU, 0x20U, 0x46U, 0x4FU, 0x4EU, 0x54U, 0x20U, 0x53U, 0x45U, 0x41U, 0x52U, 0x43U, 0x48U,
    0x20U, 0x45U, 0x52U, 0x52U, 0x4FU, 0x52U, 0x20U, 0x61U, 0x74U, 0x20U, 0x67U, 0x65U, 0x74U, 0x5FU, 0x74U, 0x65U,
    0x78U, 0x5FU, 0x69U, 0x64U, 0x20U, 0x5BU, 0x63U, 0x68U, 0x3AU, 0x25U, 0x64U, 0x5DU, 0x0AU, 0x00U, 0x00U, 0x00U,
    0x2EU, 0x2FU, 0x66U, 0x6FU, 0x6EU, 0x74U, 0x2FU, 0x66U, 0x6EU, 0x74U, 0x5FU, 0x61U, 0x73U, 0x63U, 0x5FU, 0x32U,
    0x34U, 0x78U, 0x32U, 0x34U, 0x2EU, 0x62U, 0x69U, 0x6EU, 0x00U, 0x00U, 0x00U, 0x00U, 0x64U, 0x76U, 0x64U, 0x6FU,
    0x70U, 0x65U, 0x6EU, 0x20U, 0x65U, 0x72U, 0x72U, 0x20U, 0x25U, 0x73U, 0x0AU, 0x00U, 0x53U, 0x74U, 0x6FU, 0x70U,
    0x70U, 0x65U, 0x64U, 0x2EU, 0x2EU, 0x2EU, 0x0AU, 0x00U, 0x54U, 0x79U, 0x70U, 0x65U, 0x20U, 0x3DU, 0x20U, 0x25U,
    0x64U, 0x20U, 0x28U, 0x4DU, 0x61U, 0x78U, 0x20U, 0x25U, 0x64U, 0x29U, 0x0AU, 0x00U, 0x46U, 0x6FU, 0x6EU, 0x74U,
    0x20U, 0x54U, 0x79U, 0x70U, 0x65U, 0x20U, 0x45U, 0x72U, 0x72U, 0x6FU, 0x72U, 0x00U, 0x22U, 0x25U, 0x73U, 0x22U,
    0x20U, 0x25U, 0x31U, 0x32U, 0x73U, 0x20U, 0x25U, 0x64U, 0x2FU, 0x25U, 0x64U, 0x0AU, 0x00U, 0x00U, 0x00U, 0x00U,
    0x22U, 0x25U, 0x73U, 0x22U, 0x0AU, 0x00U, 0x00U, 0x00U, 0x0AU, 0x00U, 0x00U, 0x00U, 0x4CU, 0x52U, 0x3AU, 0x66U,
    0x6FU, 0x6EU, 0x74U, 0x20U, 0x73U, 0x65U, 0x6CU, 0x65U, 0x63U, 0x74U, 0x0AU, 0x00U, 0x44U, 0x55U, 0x3AU, 0x70U,
    0x61U, 0x67U, 0x65U, 0x20U, 0x6EU, 0x65U, 0x78U, 0x74U, 0x2FU, 0x70U, 0x72U, 0x65U, 0x76U, 0x0AU, 0x00U, 0x00U,
    0x33U, 0x44U, 0x3AU, 0x63U, 0x68U, 0x61U, 0x72U, 0x61U, 0x63U, 0x74U, 0x6FU, 0x72U, 0x20U, 0x73U, 0x65U, 0x6CU,
    0x65U, 0x63U, 0x74U, 0x0AU, 0x00U, 0x00U, 0x00U, 0x00U, 0x58U, 0x20U, 0x3AU, 0x66U, 0x69U, 0x78U, 0x65U, 0x64U,
    0x2FU, 0x70U, 0x72U, 0x6FU, 0x70U, 0x6FU, 0x72U, 0x74U, 0x69U, 0x6FU, 0x6EU, 0x61U, 0x6CU, 0x0AU, 0x00U, 0x00U,
    0x59U, 0x20U, 0x3AU, 0x73U, 0x74U, 0x79U, 0x6CU, 0x65U, 0x20U, 0x63U, 0x68U, 0x61U, 0x6EU, 0x67U, 0x65U, 0x0AU,
    0x00U, 0x00U, 0x00U, 0x00U, 0x25U, 0x58U, 0x0AU, 0x00U, 0x69U, 0x73U, 0x20U, 0x6EU, 0x6FU, 0x20U, 0x6CU, 0x6FU,
    0x61U, 0x64U, 0x2EU, 0x0AU, 0x00U, 0x00U, 0x00U, 0x00U, 0x61U, 0x72U, 0x61U, 0x6DU, 0x3AU, 0x25U, 0x64U, 0x0AU,
    0x00U, 0x00U, 0x00U, 0x00U, 0x0AU, 0x70U, 0x61U, 0x67U, 0x65U, 0x3AU, 0x25U, 0x64U, 0x2FU, 0x25U, 0x64U, 0x0AU,
    0x00U, 0x00U, 0x00U, 0x00U, 0x25U, 0x58U, 0x00U, 0x00U, 0x81U, 0x76U, 0x00U, 0x00U, 0x25U, 0x73U, 0x00U, 0x00U,
    0x49U, 0x74U, 0x27U, 0x73U, 0x20U, 0x46U, 0x6FU, 0x6EU, 0x74U, 0x0AU, 0x54U, 0x65U, 0x73U, 0x74U, 0x2EU, 0x00U,
    0x00U, 0x00U, 0x00U, 0x00U
};
/* fzgx:end fn_1_49F08 */

/* fzgx:begin fn_1_4A0D8 noprologue */
#include "types.h"

typedef struct FontColor {
    u8 r, g, b, a;
} FontColor;

/* one entry of the font table lbl_1_data_1AEA8 (0x38 bytes) */
typedef struct FontInfo {
    s32 image;
    u8 width;
    u8 height;
    u8 pad_6[2];
    s32 first;
    s32 last;
    s8 columns;
    u8 unk_11;
    u8 pad_12[2];
    f32 cell_w;
    f32 cell_h;
    u8 pad_1C[0x10];
    u16 *kana;
    s16 *kana_image;
    f32 scale;
} FontInfo;

/* the text state lbl_1_bss_4B9CC (0x5C bytes) */
typedef struct FontState {
    f32 home_x;
    f32 x;
    f32 y;
    s16 font;
    s16 rotation;
    FontColor color;
    FontColor color_add;
    f32 z;
    f32 scale_x;
    f32 scale_y;
    f32 space_scale;
    f32 alpha;
    u32 flags;
    s16 width;
    s16 shadow_x;
    s16 shadow_y;
    u8 align;
    s8 page;
    f32 shadow_alpha;
    f32 spacing;
    f32 line_spacing;
    u8 unk_44;
    u8 unk_45;
    u8 unk_46;
    u8 unk_47;
    s16 unk_48;
    s16 unk_4A;
    s16 unk_4C;
    s16 unk_4E;
    f32 unk_50;
    u32 unk_54;
    u32 unk_58;
} FontState;

typedef struct FontPacket {
    s32 image;
    f32 x, y, z;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 rotation_z, rotation_y;
    f32 alpha;
    u32 flags;
    f32 depth;
    FontColor color, color_add;
    u32 format;
    u16 width, height;
    void *pixels;
    void *secondary;
    u32 vertex_callback;
    f32 unk_54;
} FontPacket;

typedef struct FontToggle {
    s32 enabled;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
} FontToggle;

extern void fn_80008BEC(void *dst, int value, u32 size);
extern void fn_80008BA8(void *dst, const void *src, u32 size);
extern f32 fn_1_4B090(const u8 *s);
extern f32 fn_1_4B040(const u8 *s);
extern s32 fn_1_4B1A0(const u8 *s);
extern s32 fn_1_49B70(const u8 *s, FontState *state);
extern u32 fn_1_49794(u32 c);
extern void fn_1_4B6D4(FontPacket *pkt, FontState *state, FontInfo *font, f32 advance);
extern void fn_1_4B788(FontPacket *pkt, FontState *state, FontInfo *font, f32 advance);
extern void fn_1_4AC20(FontPacket *pkt);

extern u8 lbl_1_data_1AEA8[];
extern s32 lbl_1_data_1BCC4;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s32 fzgx_obj_lbl_1_bss_3E058;
f32 fzgx_obj_lbl_1_bss_3E05C;
u32 fzgx_obj_lbl_1_bss_3E060[0x56B];
u32 fzgx_obj_lbl_1_bss_3F60C[0x56C];
u32 fzgx_obj_lbl_1_bss_40BBC[0x2C];
u8 fzgx_obj_lbl_1_bss_40C6C[0xAD60];
FontState fzgx_obj_lbl_1_bss_4B9CC;
s32 fzgx_obj_lbl_1_bss_4BA28[2];
FontToggle fzgx_obj_lbl_1_bss_4BA30;
FontToggle fzgx_obj_lbl_1_bss_4BA44;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3E058;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3E05C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3E060;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3F60C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_40BBC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_40C6C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_4B9CC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_4BA28;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_4BA30;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_4BA44;
}
#pragma section code_type ".text"

static const u32 fzgx_pool_rodata_FD0[(0x10C0 - 0xFD0) / 4] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBF800000, 0xBF800000, 0x3F800000, 0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x40266666, 0x00000000, 0x40266666, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3FCCCCCD, 0xBF800000, 0x40666666, 0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000, 0xBFB33333, 0x406CCCCD, 0x3FA66666, 0x00000000, 0x3FCCCCCD, 0x3F000000, 0xBF666666, 0xBF4CCCCD, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_10C0(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
    volatile f64 d;
    s = 0.0f;
    d = 0.5;
    s = 0.75f;
    s = 1.0f;
    s = 255.0f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_10E0(void) {
    volatile f64 d;  /* fzgx-allow: S2 pool primer sink */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_rodata_10E8[2] = {0xFFFFFFFF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_10F0(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
    volatile f64 d;
    s = 0.05f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_rodata_1100[(0x1320 - 0x1100) / 4] = {0x00000000, 0x000D0000, 0x00000000, 0x070D0000, 0x00000000, 0x010B0000, 0x00000000, 0x010C0000, 0x00000000, 0x02070000, 0x00000000, 0x02070000, 0x00000000, 0x08090000, 0x00000000, 0x08090000, 0x00000000, 0x10080000, 0x00000000, 0x01080000, 0x00000000, 0x0D0B0000, 0x00000000, 0x010B0000, 0x00000000, 0x010A0000, 0x00000000, 0x0C0A0000, 0x00000000, 0x060E0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x070B0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x09070000, 0x00000000, 0x060A0000, 0x00000000, 0x060F0000, 0x00000000, 0x09070000, 0x00000000, 0x03140000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x070B0000, 0x00000000, 0x050E0000, 0x00000000, 0x070B0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x02150000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04110000, 0x00000000, 0x05100000, 0x00000000, 0x04110000, 0x00000000, 0x04120000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04110000, 0x00000000, 0x04110000, 0x00000000, 0x09070000, 0x00000000, 0x050C0000, 0x00000000, 0x05110000, 0x00000000, 0x060E0000, 0x00000000, 0x02140000, 0x00000000, 0x04110000, 0x00000000, 0x04120000, 0x00000000, 0x05100000, 0x00000000, 0x04120000, 0x00000000, 0x05100000, 0x00000000, 0x060F0000, 0x00000000, 0x060E0000, 0x00000000, 0x04110000, 0x00000000, 0x05110000, 0x00000000, 0x01170000, 0x00000000, 0x03120000, 0x00000000, 0x04110000, 0x00000000, 0x04100000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1320[(0x1398 - 0x1320) / 4] = {0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00090000, 0x00000000, 0x000D0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1398[(0x1410 - 0x1398) / 4] = {0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00090000, 0x00000000, 0x000D0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1410[(0x14E8 - 0x1410) / 4] = {0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x04080000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_14E8[(0x15C0 - 0x14E8) / 4] = {0x00000000, 0x00190000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00120000, 0x00000000, 0x00110000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x000B0000, 0x00000000, 0x000F0000, 0x00000000, 0x00180000, 0x00000000, 0x00110000, 0x00000000, 0x001D0000, 0x00000000, 0x00150000, 0x00000000, 0x00170000, 0x00000000, 0x00150000, 0x00000000, 0x00170000, 0x00000000, 0x00160000, 0x00000000, 0x00180000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00190000, 0x00000000, 0x001F0000, 0x00000000, 0x00180000, 0x00000000, 0x00170000, 0x00000000, 0x00130000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_15C0[(0x1698 - 0x15C0) / 4] = {0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x000B0000, 0x00000000, 0x00080000, 0x00000000, 0x000D0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000F0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1698[(0x1700 - 0x1698) / 4] = {0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00080000, 0x00000000, 0x000E0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1700[(0x1888 - 0x1700) / 4] = {0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x00060000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000F0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000F0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x00050000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1888[(0x1A08 - 0x1888) / 4] = {0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00050000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1A08[(0x1A78 - 0x1A08) / 4] = {0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0xFD070000, 0x00000000, 0xFD050000, 0x00000000, 0xFD090000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1A78[(0x1AE8 - 0x1A78) / 4] = {0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0xFE050000, 0x00000000, 0xFE030000, 0x00000000, 0xFE060000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1AE8[(0x1B58 - 0x1AE8) / 4] = {0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0xFD0C0000, 0x00000000, 0xFD080000, 0x00000000, 0xFD0A0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1B58[(0x1E38 - 0x1B58) / 4] = {0x00000000, 0x000C0000, 0x00000000, 0x00020000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000A0000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00040000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x00020000, 0x00000000, 0x00060000, 0x00000000, 0x00020000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00020000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00040000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x000C0000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x000A0000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1E38[(0x2118 - 0x1E38) / 4] = {0x00000000, 0x000C0000, 0x00000000, 0x0A040000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x04100000, 0x00000000, 0x00060000, 0x00000000, 0x08080000, 0x00000000, 0x08080000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x09060000, 0x00000000, 0x050E0000, 0x00000000, 0x0A040000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x070A0000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x0A040000, 0x00000000, 0x0A040000, 0x00000000, 0x09060000, 0x00000000, 0x09060000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x070A0000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x050E0000, 0x00000000, 0x03120000, 0x00000000, 0x050E0000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x02140000, 0x00000000, 0x08080000, 0x00000000, 0x070A0000, 0x00000000, 0x03120000, 0x00000000, 0x08080000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x060E0000, 0x00000000, 0x060C0000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x02140000, 0x00000000, 0x050E0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_2118[(0x23C0 - 0x2118) / 4] = {0x00000000, 0x00120000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x010F0000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x000E0000, 0x00000000, 0x05080000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x020E0000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_23C0[(0x2668 - 0x23C0) / 4] = {0x00000000, 0x00120000, 0x00000000, 0x07040000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x010F0000, 0x00000000, 0x06080000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x000E0000, 0x00000000, 0x05080000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x07040000, 0x00000000, 0x07040000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x020E0000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x07040000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static void fzgx_pool_keep(void) {
    const u32 *volatile cp;  /* fzgx-allow: S2 pool primer sink */
    cp = fzgx_pool_rodata_FD0;
    cp = fzgx_pool_rodata_10E8;
}
#pragma section code_type ".text"
static const FontColor fzgx_shadow_color = {0, 0, 0, 0};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_266C(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 0.5f;
    s = 0.01f;
    s = 0.02f;
}
#pragma section code_type ".text"

static inline void fzgx_set_scale(f32 value1, f32 value2) {
    FontInfo *font = (FontInfo *)lbl_1_data_1AEA8 + fzgx_obj_lbl_1_bss_4B9CC.font;

    fzgx_obj_lbl_1_bss_4B9CC.scale_x = value1 * font->scale;
    fzgx_obj_lbl_1_bss_4B9CC.scale_y = value2 * font->scale;
}

#pragma fp_contract off
void fn_1_4A0D8(const u8 *s) {
    FontPacket pkt;
    FontState saved;
    char buf[32];
    FontState *state;
    FontInfo *font;
    s32 first;
    FontState *state2;
    u16 *p;
    f32 width;
    f32 spacing;
    f32 lastX;
    f32 lastY;
    f32 x;
    f32 y;
    f32 offset;
    f32 advance;
    f32 u;
    f32 v;
    u32 c;
    u16 ch;
    u32 adv;
    u8 len;
    s16 count;
    s32 idx;
    s32 row;
    s32 col;
    s32 n;
    FontInfo *fs;

    p = NULL;
    if (s == NULL && fzgx_obj_lbl_1_bss_4BA28[0] == 0) {
        fzgx_obj_lbl_1_bss_4BA28[0] = 1;
        return;
    }
    state = &fzgx_obj_lbl_1_bss_4B9CC;
    font = (FontInfo *)lbl_1_data_1AEA8 + state->font;
    fn_80008BEC(&pkt, 0, sizeof(pkt));
    state2 = &fzgx_obj_lbl_1_bss_4B9CC;
    pkt.image = font->image;
    pkt.z = state->z;
    pkt.alpha = state->alpha;
    pkt.rotation_z = state->rotation;
    pkt.color = state->color;
    pkt.color_add = state->color_add;
    pkt.flags = state->unk_58 | (state->flags & ~0xF);
    if (pkt.image == -1) {
        pkt.flags |= 0x400000;
    }
    first = 1;
    switch (state->align & 0x18) {
    case 0:
        break;
    case 8:
        state->y -= fn_1_4B090(s) / 2.0f;
        break;
    case 0x10:
        state->y -= fn_1_4B090(s);
        break;
    }

    for (; *s != 0; s++) {
        if (state->flags & 0x10000) {
            pkt.z += 0.01f;
        }
        if (first) {
            first = 0;
            width = fn_1_4B040(s);
            count = fn_1_4B1A0(s);
            if ((state->align & 4) && state->width > width) {
                spacing = (state->width - width) / (count - 1);
            } else {
                spacing = 0.0f;
            }
        }
        ch = *s;
        c = ch;
        if ((state->flags & 0x20000000) && (u16)c >= 'a' && (u16)c <= 'z') {
            c = ch - 0x20;
        }
        if ((u16)c < 0x80) {
            if ((pkt.flags & 0x400000) && (u16)c != '\n' && (u16)c != ' ' &&
                (fzgx_obj_lbl_1_bss_3E058 == 0 || ((u16)c != '[' && (u16)c != ']'))) {
                c = fn_1_499BC(s);
                if ((u16)c >= 0x80) {
                    s += 6;
                } else {
                    if ((u16)c == '/' && (s8)(n = fn_1_49B70(s, state)) != 0) {
                        s += (s8)n;
                        pkt.color = state->color;
                        pkt.color_add = state->color_add;
                        continue;
                    }
                    c = fn_1_49794(c);
                }
            }
            if ((u16)c < 0x80) {
                if ((u16)c == '/' && (s8)(n = fn_1_49B70(s, state)) != 0) {
                    s += (s8)n;
                    pkt.color = state->color;
                    pkt.color_add = state->color_add;
                    continue;
                }
                adv = fn_1_49F08(c, state, font);
                if ((u16)c == '\n') {
                    first = 1;
                    state->x = state->home_x;
                    state->y += state->line_spacing + font->height * state->scale_y;
                    continue;
                }
                if ((u16)c == ' ') {
                    state->x += state->spacing + (s32)(adv & 0xFFFF) * state->scale_x;
                    continue;
                }
                if (fzgx_obj_lbl_1_bss_3E058 != 0 && (u16)c == '[') {
                    len = 0;
                    do {
                        s++;
                        c = fn_1_499BC(s);
                        if ((u16)c >= 0x80) {
                            fn_80008BA8(&buf[len], s, 2);
                            s++;
                            len += 2;
                        } else if ((u16)c != ']') {
                            buf[len++] = *s;
                        }
                    } while ((u16)c != ']');
                    buf[len] = 0;
                    if (lbl_1_data_1BCC4 != 0) {
                        fn_80008BA8(&saved, state, sizeof(saved));
                        fs = (FontInfo *)lbl_1_data_1AEA8 + saved.font;
                        state2->z = saved.z - 0.01f;
                        fzgx_obj_lbl_1_bss_4B9CC.spacing = 0.0f;
                        fzgx_obj_lbl_1_bss_4B9CC.line_spacing = 0.0f;
                        fzgx_obj_lbl_1_bss_4B9CC.x = lastX;
                        fzgx_obj_lbl_1_bss_4B9CC.home_x = lastX;
                        fzgx_obj_lbl_1_bss_4B9CC.align = 0x11;
                        fzgx_obj_lbl_1_bss_4B9CC.space_scale = 1.0f;
                        fzgx_obj_lbl_1_bss_4B9CC.y = lastY - 1.0f + fzgx_obj_lbl_1_bss_3E05C;
                        fzgx_set_scale(0.5f * saved.scale_x / fs->scale, 0.5f * saved.scale_y / fs->scale);
                        fzgx_obj_lbl_1_bss_3E058 = 0;
                        fn_1_4A0D8((const u8 *)buf);
                        fzgx_obj_lbl_1_bss_3E058 = 1;
                        fn_80008BA8(state, &saved, sizeof(saved));
                    }
                    continue;
                }
                if ((u16)c < font->first || (u16)c > font->last) {
                    state->x += state->spacing + (s32)(adv & 0xFFFF) * state->scale_x;
                    continue;
                }
            } else {
                u16 *q;
                s32 i;

                pkt.image = -2;
                q = font->kana;
                for (i = 0; *q != 0; i++, q++) {
                    if (*q == (u16)c) {
                        adv = fn_1_49F08(c, state, font);
                        pkt.image = font->kana_image[i];
                        if (pkt.image != -1) {
                            c = 0;
                        }
                        break;
                    }
                }
                p = q;
            }
        } else {
            u16 *q;
            s32 i;

            c = (((u16)c << 8) | *++s) & 0xFFFF;
            if (c == 0x8140) {
                adv = fn_1_49F08(c, state, font);
                state->x += state->spacing + (s32)(adv & 0xFFFF) * state->scale_x;
                continue;
            }
            pkt.image = -2;
            q = font->kana;
            for (i = 0; *q != 0; i++, q++) {
                if (*q == c) {
                    adv = fn_1_49F08(c, state, font);
                    pkt.image = font->kana_image[i];
                    if (pkt.image != -1) {
                        c = 0;
                    }
                    break;
                }
            }
            p = q;
        }

        if (pkt.image < 0) {
            /* no glyph drawn: the ruby anchor stays on the previous glyph.
             * Retail keeps an empty arm here (bge +8; b); carrying the anchor through x/y
             * reproduces it. The carry changes no value. */
            x = lastX;
            y = lastY;
        } else {
            if (pkt.flags & 0x400000) {
                pkt.image &= 0xFFFF;
                pkt.image |= (state->font & 0xFF) << 16;
                pkt.image |= state->page << 24;
            }
            idx = (u16)c - font->first;
            row = idx / font->columns;
            col = idx % font->columns;
            if ((state->align & 3) == 2) {
                pkt.x = state->x - width;
            } else if ((state->align & 3) == 1) {
                pkt.x = state->x - width / 2.0f;
            } else {
                pkt.x = state->x;
            }
            pkt.y = state->y;
            y = state->y;
            offset = (s16)(adv >> 16) * state->scale_x;
            advance = (s32)(adv & 0xFFFF);
            pkt.x -= offset;
            x = pkt.x + 0.5f * (state->scale_x * (s32)(adv & 0xFFFF));
            u = font->cell_w * col;
            v = font->cell_h * row;
            pkt.u0 = u;
            pkt.v0 = v;
            pkt.u1 = u + font->cell_w;
            pkt.v1 = v + font->cell_h;
            pkt.scale_x = state->scale_x * font->cell_w;
            pkt.scale_y = state->scale_y * font->cell_h;
            if (state->unk_54 != 0) {
                pkt.vertex_callback = state->unk_54;
                pkt.unk_54 = state->unk_50;
                pkt.flags |= 0x4000000;
            }
            if (fzgx_obj_lbl_1_bss_4BA30.enabled != 0) {
                pkt.x += offset;
                fn_1_4B6D4(&pkt, state, font, advance);
                pkt.x -= offset;
            }
            if (fzgx_obj_lbl_1_bss_4BA44.enabled != 0) {
                pkt.x += offset;
                fn_1_4B788(&pkt, state, font, advance);
                pkt.x -= offset;
            }
            if (p != NULL && *p >= 0x839F && *p <= 0x83B8) {
                pkt.flags |= 0x10000000;
            } else {
                pkt.flags &= ~0x10000000;
            }
            if ((pkt.flags & 0x400000) && (state->flags & 0x40000000)) {
                pkt.x += state->shadow_x;
                pkt.y += state->shadow_y;
                pkt.z += 0.02f;
                pkt.alpha = state->alpha * state->shadow_alpha;
                pkt.color = fzgx_shadow_color;
                fn_1_4AC20(&pkt);
                pkt.x -= state->shadow_x;
                pkt.y -= state->shadow_y;
                pkt.z -= 0.02f;
                pkt.alpha = state->alpha;
                pkt.color = state->color;
            }
            fn_1_4AC20(&pkt);
        }
        lastX = x;
        lastY = y;
        state->x += spacing + (state->spacing + (s32)(adv & 0xFFFF) * state->scale_x);
    }

    switch (state->align & 0x18) {
    case 0:
        break;
    case 8:
        state->y += fn_1_4B090(s) / 2.0f;
        break;
    case 0x10:
        state->y += fn_1_4B090(s);
        break;
    }
}
#pragma fp_contract reset
/* fzgx:end fn_1_4A0D8 */

/* fzgx:begin fn_1_4AC20 */
typedef struct {
    u32 unk_0;
    f32 x;
    f32 y;
    u8 pad_C[4];
    f32 z;
    f32 w;
    u8 pad_20[0x18];
    u32 flag;
    u8 tail[0x24];
} fn_1_4AC20_FontData;

void fn_1_4AC20(fn_1_4AC20_FontData *value) {
    fn_1_4AC20_FontData local = *value;
    int x_ok;
    int y_ok;

    if (lbl_1_bss_4B9CC.unk_45 != 0) {
        local.x = fn_1_519FC(local.x);
        local.y = fn_1_51AC0(local.y);
        local.z = fn_1_51B84(local.z);
        local.w = fn_1_51BFC(local.w);
    }

    if (lbl_1_bss_4B9CC.unk_47 != 0) {
        x_ok = (local.x > (lbl_1_bss_4B9CC.unk_48 + lbl_1_bss_4B9CC.unk_4C))
                   ? 0
                   : ((local.x < lbl_1_bss_4B9CC.unk_48) ? 0 : 1);
        if (x_ok == 0 ||
            (y_ok = (local.y > (lbl_1_bss_4B9CC.unk_4A + lbl_1_bss_4B9CC.unk_4E))
                        ? 0
                        : ((local.y < lbl_1_bss_4B9CC.unk_4A) ? 0 : 1)) == 0) {
            return;
        }
    }

    if (lbl_1_bss_4B9CC.unk_44 != 0) {
        fn_1_4F734( (FontDrawPacket *)(&local));
    } else if ((local.flag & 0x400000) != 0) {
        if (lbl_1_bss_4B9CC.unk_46 == 0) {
            fn_1_4E500();
        }
        fn_1_48D80(&local);
        if (lbl_1_bss_4B9CC.unk_46 == 0) {
            fn_1_4E6F4();
        }
    } else {
        fn_1_4E724( (FontParams *)(&local));
    }
}
/* fzgx:end fn_1_4AC20 */

/* fzgx:begin fn_1_4AE0C */
void fn_1_4AE0C(const char* format, ...) {
    char buffer[512];
    __va_list args;
    __builtin_va_info(&args);
    fn_8008077C( (u32)(buffer), (u32)(format), (u32)(args));
    fn_1_4A0D8(buffer);
}
/* fzgx:end fn_1_4AE0C */

/* fzgx:begin fn_1_4AEB4 */
void fn_1_4AEB4(f32 value) {
    lbl_1_bss_3E05C = value;
}
/* fzgx:end fn_1_4AEB4 */

/* fzgx:begin fn_1_4AEC0 */
u32 fn_1_4AEC0(u32 value) {
    u32 previous = lbl_1_bss_3E058;

    lbl_1_bss_3E05C = lbl_1_rodata_10C0[0];
    lbl_1_bss_3E058 = value;

    return previous;
}
/* fzgx:end fn_1_4AEC0 */

/* fzgx:begin fn_1_4AEE8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bitmap.h"

extern void fn_1_48214(int index, int enabled);
extern void fn_1_4DDC0(void);
extern void fn_1_4F724(void);
extern s32 lbl_801A6410;
extern void OSPanic(const unsigned char *, ...);
extern int fn_1_45D0(int, int, const unsigned char *, int);
extern int fn_80008F88(int, int);
extern void fn_8006FDEC(void);
extern void fn_80009064(u32 value);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, s32 arg3);
extern void *fn_1_48730(u32 value);
extern void fn_1_47AD4(BitmapResource *obj, u8 value, int arg2, int arg3);
extern f32 lbl_1_rodata_10C0[5];
extern f32 lbl_1_bss_3E05C;

extern void *fn_1_48730(u32 value);

u32 fn_1_4AEE8(u32 value) {
    u32 previous = lbl_1_data_1BCC4;

    lbl_1_bss_3E05C = lbl_1_rodata_10C0[0];
    lbl_1_data_1BCC4 = value;

    return previous;
}
/* fzgx:end fn_1_4AEE8 */

/* fzgx:begin fn_1_4AF10 */
struct fn_1_4AF10_lbl_1_bss_3E058 {
    u32 unk_0;
};






void fn_1_4AF10(u32 arg0) {
    u32 v0;
    v0 = (*(struct fn_1_4AF10_lbl_1_bss_3E058 *)&lbl_1_bss_3E058).unk_0;
    lbl_1_bss_3E05C = (0.0f);
    (*(struct fn_1_4AF10_lbl_1_bss_3E058 *)&lbl_1_bss_3E058).unk_0 = 1;
    fn_1_4A0D8((const char *)arg0);
    (*(struct fn_1_4AF10_lbl_1_bss_3E058 *)&lbl_1_bss_3E058).unk_0 = v0;
}
/* fzgx:end fn_1_4AF10 */

/* fzgx:begin fn_1_4AF64 */
typedef struct {
    u32 gpr_offset;
    void *overflow_arg_area;
    void *reg_save_area;
} va_list;



void fn_1_4AF64(const char *format, ...) {
    va_list args;
    char buffer[512];
    u32 previous = lbl_1_bss_3E058;

    __builtin_va_info(&args);
    fn_8008077C( (u32)(buffer), (u32)(format), (u32)(va_list *)(&args));

    lbl_1_bss_3E058 = 1;
    lbl_1_bss_3E05C = lbl_1_rodata_10C0[0];
    fn_1_4A0D8(buffer);
    lbl_1_bss_3E058 = previous;
}
/* fzgx:end fn_1_4AF64 */

/* fzgx:begin fn_1_4B040 */
void fn_1_4B040(s32 value) {
    fn_1_4B1D4(0, (u8 *)value);
}
/* fzgx:end fn_1_4B040 */

/* fzgx:begin fn_1_4B068 */
void fn_1_4B068(s32 value) {
    fn_1_4B1D4(1, (u8 *)value);
}
/* fzgx:end fn_1_4B068 */

/* fzgx:begin fn_1_4B090 */
typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 pad_6[0x2e];
    f32 unk_34;
} FontEntry_38;

f32 fn_1_4B090(s32 value) {
    s32 count;
    s32 index;
    FontEntry_38 *entry;
    f32 a;
    f32 b;

    index = lbl_1_bss_4B9CC.unk_C;
    entry = (FontEntry_38 *)((u8 *)&lbl_1_data_1AEA8 + index * 0x38);
    count = fn_1_4B16C(value);
    if (count - 1 > 0) {
        count = fn_1_4B16C(value) - 1;
    } else {
        count = 0;
    }
    a = lbl_1_bss_4B9CC.unk_20 *
        (entry->unk_34 * (entry->unk_5 * fn_1_4B16C(value)));
    b = lbl_1_bss_4B9CC.unk_40 * count;
    return a + b;
}
/* fzgx:end fn_1_4B090 */

/* fzgx:begin fn_1_4B16C */
s32 fn_1_4B16C(s32 value) {
    return fn_1_4B1D4(2, (u8 *)value);
}
/* fzgx:end fn_1_4B16C */

/* fzgx:begin fn_1_4B1A0 */
s32 fn_1_4B1A0(s32 value) {
    return fn_1_4B1D4(3, (u8 *)value);
}
/* fzgx:end fn_1_4B1A0 */

/* fzgx:begin fn_1_4B1D4 */
typedef struct FontEntry_4B1D4 {
    s32 unk_0;
    u8 pad_4[0x30];
    f32 unk_34;
} FontEntry_4B1D4;

extern s32 lbl_1_bss_4BA28[2];

f32 fn_1_4B1D4(s32 mode, u8 *str) {
    Obj_1_bss_4B9CC * p;
    s32 i;
    Obj_1_bss_4B9CC *state;
    FontEntry_4B1D4 *font;
    f32 width;
    f32 maxWidth;
    s32 adv;
    s32 count;
    s32 maxCount;
    s32 doWidth;
    s32 doCount;
    s32 doLines;
    s32 doMax;
    s32 newline;
    u8 *s;
    s32 lines;
    u8 *cp;
    u32 c;
    u16 ch;
    s32 n;

    s = str;
    p = &lbl_1_bss_4B9CC;
    maxWidth = 0.0f;
    width = -p->unk_3C;
    adv = 0;
    count = 0;
    maxCount = 0;
    lines = 1;
    doWidth = 0;
    doCount = 0;
    doLines = 0;
    doMax = 0;
    newline = 0;

    if (s == NULL && lbl_1_bss_4BA28[0] == 0) {
        lbl_1_bss_4BA28[0] = 1;
        return maxWidth;
    }

    switch (mode) {
    case 0:
        doWidth = 1;
        break;
    case 1:
        doWidth = 1;
        doMax = 1;
        break;
    case 2:
        doLines = 1;
        break;
    case 3:
        doCount = 1;
        break;
    case 4:
        doCount = 1;
        doMax = 1;
        break;
    }

    i = 0;
    font = (FontEntry_4B1D4 *)((u8 *)&lbl_1_data_1AEA8 + lbl_1_bss_4B9CC.unk_C * 0x38);
    /* `goto next` is the loop's continue: it skips the width accumulation */
    while ((ch = *(cp = s + i)) != 0) {
        state = &lbl_1_bss_4B9CC;
        c = ch;
        if ((state->unk_2C & 0x20000000) && (u16)c >= 'a' && (u16)c <= 'z') {
            c = ch - 0x20;
        }
        if (newline) {
            newline = 0;
            lines++;
        }
        if (doWidth) {
            adv = fn_1_49F08(c, state, font) & 0xFFFF;
        }
        if ((u16)c < 0x80) {
            if (font->unk_0 == -1) {
                c = fn_1_499BC(cp);
                if ((u16)c >= 0x80) {
                    i += 6;
                } else {
                    if ((u16)c == '/' && (s8)(n = fn_1_49B70(cp, 0)) != 0) {
                        i += (s8)n;
                        /* Skip glyph accumulation for this control sequence. */
                        goto next;
                    }
                    c = fn_1_49794(c);
                }
                if ((s32)lbl_1_bss_3E058 != 0 && (u16)c == '[') {
                    while (s[i] != ']') {
                        i++;
                    }
                    /* Skip glyph accumulation for this control sequence. */
                    goto next;
                }
                if ((u16)c == '\n') {
                    if (doLines) {
                        newline = 1;
                    } else {
                        if (!doMax) {
                            break;
                        }
                        if (doWidth) {
                            maxWidth = (maxWidth > width) ? maxWidth : width;
                            width = -p->unk_3C;
                        } else if (doCount) {
                            maxCount = (maxCount > count) ? maxCount : count;
                            count = 0;
                        }
                        /* Skip glyph accumulation for this control sequence. */
                        goto next;
                    }
                }
                if (doWidth) {
                    adv = fn_1_49F08(c, state, font) & 0xFFFF;
                }
            } else {
                if ((u16)c == '/' && (s8)(n = fn_1_49B70(cp, 0)) != 0) {
                    i += (s8)n;
                    /* Skip glyph accumulation for this control sequence. */
                    goto next;
                }
                if ((s32)lbl_1_bss_3E058 != 0 && (u16)c == '[') {
                    while (s[i] != ']') {
                        i++;
                    }
                    /* Skip glyph accumulation for this control sequence. */
                    goto next;
                }
                if ((u16)c == '\n') {
                    if (doLines || !doMax) {
                        break;
                    }
                    if (doWidth) {
                        maxWidth = (maxWidth > width) ? maxWidth : width;
                        width = -p->unk_3C;
                    } else if (doCount) {
                        maxCount = (maxCount > count) ? maxCount : count;
                        count = 0;
                    }
                    /* Skip glyph accumulation for this control sequence. */
                    goto next;
                }
            }
        } else {
            i++;
            c = (u16)(((u16)c << 8) | s[i]);
            if (doWidth) {
                adv = fn_1_49F08(c, state, font) & 0xFFFF;
            }
        }
        if (doWidth) {
            width += p->unk_3C + (f32)(state->unk_1C * (adv * font->unk_34));
        } else if (doCount) {
            count++;
        }
    next:
        i++;
    }

    if (doMax) {
        if (doWidth) {
            maxWidth = (maxWidth > width) ? maxWidth : width;
        } else if (doCount) {
            maxCount = (maxCount > count) ? maxCount : count;
        }
    }

    switch (mode) {
    case 0:
        return width;
    case 1:
        return maxWidth;
    case 2:
        return lines;
    case 3:
        return count;
    case 4:
        return maxCount;
    default:
        return -1.0f;
    }
}
/* fzgx:end fn_1_4B1D4 */

/* fzgx:begin fn_1_4B83C */
void fn_1_4B83C(void *arg0, void *arg1, u32 arg2, const char *arg3) {
    u32 length;
    s32 converted;

    length = strlen(arg3);
    converted = fn_1_4B1D4(3, (u8 *)(arg2 + length));
    sprintf(arg0, arg1, length + converted);
}
/* fzgx:end fn_1_4B83C */

/* fzgx:begin fn_1_4B8BC */
void fn_1_4B8BC(void) {
    lbl_1_bss_4BA58 = 0;
}
/* fzgx:end fn_1_4B8BC */

/* fzgx:begin fn_1_4B8CC */
void fn_1_4B8CC(void) {
    lbl_1_bss_4BA5C = 0;
}
/* fzgx:end fn_1_4B8CC */

/* fzgx:begin fn_1_4B8DC */
extern void fn_1_4B8BC(void);
extern u32 OSGetArenaHi(void);
extern s32 fn_80006B70(void *, void *);
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);

typedef struct {
    u32 unk_0;
    u8 pad_4[0x48];
} MsgData;

extern u32 fn_80006DE8(MsgData *);
extern u32 OSAllocFromArenaHi(u32, u32);
extern u32 fn_80006D1C(MsgData *, void *, u32, u32);
extern u32 fn_8002071C(void);
extern u32 ARGetDMAStatus(void);
extern u32 fn_800206FC(u32);
extern void DCFlushRange(void *, u32);

typedef void (*ARQCallback)(u32);

typedef struct {
    void *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    ARQCallback callback;
} ARQRequest;

extern void ARQPostRequest(ARQRequest *, u32, u32, u32, void *, u32, u32, ARQCallback);
extern void OSSetArenaHi(u32);

void fn_1_4B8DC(void)
{
    u8 *base = (u8 *)&lbl_1_data_1A3B8;
    u32 size;
    void *src = base + 0x2014;
    MsgData msg;
    u32 arenaHi;
    void *p;
    u32 q;
    s32 flag;
    s32 tmp_call2;

    arenaHi = OSGetArenaHi();

    tmp_call2 = fn_80006B70(src, &msg);
    if (tmp_call2 == 0) {
        OSReport((const char *)base + 0x2030, src);
        OSPanic((const char *)base + 0x1910, 0xA77,
            (const char *)base + 0x2040);
    }

    size = (fn_80006DE8(&msg) + 0x1F) & ~0x1F;
    p = (void *)OSAllocFromArenaHi(size, 0x20);
    fn_80006D1C(&msg, p, size, 0);
    flag = 1;
    (void) flag;  /* fzgx: keeps the web at its definition */
    q = fn_8002071C();

    while (ARGetDMAStatus() != 0) {
    }

    fn_800206FC(size);
    lbl_1_bss_4BA58 = 1;
    DCFlushRange(p, size);
    ARQPostRequest((ARQRequest *)&lbl_1_bss_4BA60[0], 1, 0, 1, p, 0xF96000,
        size, (ARQCallback)fn_1_4B8BC);

    /* the AR completion flag is polled in place; the load must not be hoisted */
    while (flag == 1 && *(volatile s32 *)&lbl_1_bss_4BA58 != 0) {
    }

    fn_800206FC(q);
    OSSetArenaHi(arenaHi);
}
/* fzgx:end fn_1_4B8DC */

/* fzgx:begin fn_1_4BA24 */
extern u8 lbl_1_bss_4BA80[0xB0];
extern void fn_1_4B8CC(void);
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
extern u32 fn_8002071C(void);
extern u32 fn_800206FC(u32);
extern u32 ARGetDMAStatus(void);
extern void DCInvalidateRange(void *, u32);

typedef void (*ARQCallback)(u32);

typedef struct {
    void *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    ARQCallback callback;
} ARQRequest;

extern void ARQPostRequest(ARQRequest *, u32, u32, u32, void *, void *, u32, ARQCallback);

typedef struct {
    u8 pad_0[0x28];
    u16 unk_28;
    u8 pad_2A[0xE];
} Entry;


#pragma opt_common_subs off
#pragma opt_dead_assignments off
static inline Entry *fn_1_4BA24_array_read(Entry *array) { return array; }
void fn_1_4BA24(u32 arg0, s32 arg1, void *arg2)
{
    u32 saved;
    u8 *base = (u8 *)&lbl_1_data_1A3B8;
    Entry *tbl;
    u32 dest;
    u16 len;

    if ((arg0 & 0xFF) >= 0x2C) {
        OSReport((const char *)base + 0x204C, arg0 & 0xFF, 0x2C);
        OSPanic((const char *)base + 0x1910, 0xAB4, (const char *)base + 0x2060);
    }

    tbl = (Entry *)(base + 0xAF0);
    len = fn_1_4BA24_array_read(tbl)[arg0 & 0xFF].unk_28;
    dest = ((u32 *)&lbl_1_bss_4BA80)[arg0 & 0xFF] + 0xF96000 + len * arg1;

    saved = fn_8002071C();
    fn_800206FC(0x20);

    lbl_1_bss_4BA5C = 1;

    while (ARGetDMAStatus() != 0) {
    }

    DCInvalidateRange(arg2, len);
    ARQPostRequest((ARQRequest *)&lbl_1_bss_4BA60[0], 1, 1, 1, (void *)dest, arg2,
        len, (ARQCallback)fn_1_4B8CC);

    /* the AR completion flag is polled in place; the load must not be hoisted */
    while (*(volatile s32 *)&lbl_1_bss_4BA5C != 0) {
    }

    fn_800206FC(saved);
}

#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_4BA24 */

/* fzgx:begin fn_1_4BB5C */
/* one 0x38-byte record of the lbl_1_data_1AEA8 font table */
typedef struct FontEntry {
    s32 unk_0;
    u8 pad_4[0x28];
    u16 *unk_2C;
    s16 *unk_30;
    u8 pad_34[0x4];
} FontEntry;

extern s32 fn_1_48A0C(s32, s32, FontEntry *, s32);
extern void fn_1_47F74(s32);

/* for every font with unk_0 == -1: clear each character slot whose lbl_1_bss_3F60C entry is not -1,
 * and count the font's characters into lbl_1_bss_40BBC */
static inline void reset_font_slots(FontEntry *table) {
    s32 i;
    s32 ch;
    FontEntry *font;
    u16 *code;
    s32 *count = (s32 *)&lbl_1_bss_40BBC;

    for (i = 0, font = table; i < 44; i++, font++) {
        count[i] = 0;
        if (font->unk_0 == -1) {
            for (ch = 0, code = font->unk_2C; *code != 0; ch++, code++) {
                s16 slot = font->unk_30[ch];
                if (slot != -1 && ((s32 *)lbl_1_bss_3F60C)[slot] != -1) {
                    font->unk_30[ch] = -1;
                }
                count[i]++;
            }
        }
    }
}

/* the s8 is read through a pointer, as retail loads it straight into the index register */
static inline void load_font_chars(s8 *selected) {
    s32 index = *selected;
    s32 ch;
    u16 *code;
    FontEntry *font;

    font = &((FontEntry *)&lbl_1_data_1AEA8)[index];
    if (font->unk_0 == -1) {
        for (ch = 0, code = font->unk_2C; *code != 0; ch++, code++) {
            if (font->unk_30[ch] == -1) {
                fn_1_48A0C(ch, index, font, 0);
            }
        }
    }
}

void fn_1_4BB5C(void) {
    Obj_1_bss_4BB30 *state = &lbl_1_bss_4BB30;
    FontEntry *prev = &((FontEntry *)&lbl_1_data_1AEA8)[(s8)state->unk_0];

    state->unk_1 = 3;
    state->unk_0 = 3;
    state->unk_2 = 0;
    state->unk_3 = 0;
    state->unk_4 = 0;
    state->unk_8 = 0;
    reset_font_slots((FontEntry *)&lbl_1_data_1AEA8);
    if (prev->unk_0 == -1) {
        load_font_chars((s8 *)&state->unk_0);
    } else {
        fn_1_47F74((prev->unk_0 >> 8) & 0xFFFF);
    }
}
/* fzgx:end fn_1_4BB5C */

/* fzgx:begin fn_1_4BD48 */
// fn_1_4BD48: empty in retail (single blr).
void fn_1_4BD48(void) {
}
/* fzgx:end fn_1_4BD48 */

/* fzgx:begin fn_1_4BD4C */
typedef struct FontElement {
    s32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[0x2];
    u32 unk_8;
    s32 unk_C;
    s8 unk_10;
    s8 unk_11;
    u8 pad_12[0x2];
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x10];
    u16 *unk_2C;
    s16 *unk_30;
    f32 unk_34;
} FontElement;

typedef struct AppState {
    s8 unk_0;
    s8 unk_1;
    s8 unk_2;
    s8 unk_3;
    s8 unk_4;
    u8 pad_5[0x3];
    s32 unk_8;
} AppState;

extern u16 lbl_1_bss_D58[12];
extern u16 lbl_1_bss_96A;
extern void fn_1_48C28(int);
extern u32 fn_1_48A0C(s32, s8, void *, u32);
extern void fn_1_48140(u16);
extern void fn_1_47F74(u16);
extern u32 fn_1_4C16C(void);


void fn_1_4BD4C(u32 unused0, u32 unused1, u32 unused2) {
    u16 *p_d58;
    s32 page_size;
    FontElement *elem;
    s32 cols;
    s32 rows;
    struct {
        FontElement *elem2;
        u16 *p25;
        s32 i;
        s32 idx;
        s32 offset;
    } lp;
    s32 prev_unk_0;
    s32 prev_unk_4;
    s32 prev_unk_8;
    s32 count;
    s32 max_page;
    AppState *sp30;

    lp.elem2 = 0; lp.p25 = 0; lp.i = 0; lp.idx = 0; lp.offset = 0;
    sp30 = (AppState *)&lbl_1_bss_4BB30;
    if (((FontElement *)&lbl_1_data_1AEA8)[sp30->unk_0].unk_0 == -1) {
        cols = 16;
        rows = 8;
    } else {
        cols = ((FontElement *)&lbl_1_data_1AEA8)[sp30->unk_0].unk_10;
        rows = ((FontElement *)&lbl_1_data_1AEA8)[sp30->unk_0].unk_11;
    }

    prev_unk_0 = *(s8 *)&sp30->unk_0;
    p_d58 = lbl_1_bss_D58;

    if (((p_d58[8] >> 1) & 1) != 0) {
        if ((s8)++sp30->unk_0 > 43) {
            sp30->unk_0 = 0;
        }
    }
    if ((p_d58[8] & 1) != 0) {
        if ((s8)--sp30->unk_0 < 0) {
            sp30->unk_0 = 43;
        }
    }

    elem = &((FontElement *)&lbl_1_data_1AEA8)[sp30->unk_0];
    if (prev_unk_0 != sp30->unk_0) {
        sp30->unk_4 = 0;
        if (elem->unk_0 == -1) {
            fn_1_48C28(sp30->unk_1);
            lp.idx = sp30->unk_0;
            lp.elem2 = &((FontElement *)&lbl_1_data_1AEA8)[lp.idx];
            if (lp.elem2->unk_0 == -1) {
                for (lp.i = 0, lp.p25 = lp.elem2->unk_2C, lp.offset = 0; *lp.p25 != 0; lp.offset += 2, lp.i++, lp.p25++) {
                    if (*(s16 *)((u8 *)lp.elem2->unk_30 + lp.offset) == -1) fn_1_48A0C(lp.i, lp.idx, lp.elem2, 0);
                }
            }
        } else {
            fn_1_48140((((FontElement *)&lbl_1_data_1AEA8)[sp30->unk_1].unk_0 >> 8) & 0xFFFF);
            fn_1_47F74((elem->unk_0 >> 8) & 0xFFFF);
        }
        sp30->unk_1 = sp30->unk_0;
    }

    if (elem->unk_0 == -1) {
        page_size = cols * rows;
        prev_unk_4 = sp30->unk_4;
        max_page = ((s32 *)&lbl_1_bss_40BBC)[sp30->unk_0] / page_size;
        if (((p_d58[8] >> 2) & 1) != 0) {
            if ((s8)++sp30->unk_4 > max_page) {
                sp30->unk_4 = 0;
            }
        }
        if (((p_d58[8] >> 3) & 1) != 0) {
            if ((s8)--sp30->unk_4 < 0) {
                sp30->unk_4 = max_page;
            }
        }
        if (prev_unk_4 != sp30->unk_4) {
            if (sp30->unk_4 != sp30->unk_8 / page_size) {
                sp30->unk_8 = sp30->unk_4 * page_size;
            }
        }
    }

    prev_unk_8 = sp30->unk_8;
    if (elem->unk_0 == -1) {
        count = ((s32 *)&lbl_1_bss_40BBC)[sp30->unk_0];
    } else {
        count = elem->unk_C + 1;
    }

    if (((lbl_1_bss_D58[9] >> 5) & 1) != 0) {
        if (++sp30->unk_8 > count - 1) {
            sp30->unk_8 = 0;
        }
    }
    if (((lbl_1_bss_D58[9] >> 4) & 1) != 0) {
        if (--sp30->unk_8 < 0) {
            sp30->unk_8 = count - 1;
        }
    }
    if (((lbl_1_bss_D58[9] >> 6) & 1) != 0) {
        sp30->unk_8 += cols;
        if (sp30->unk_8 > count - 1) {
            sp30->unk_8 %= cols;
        }
    }
    if (((lbl_1_bss_D58[9] >> 7) & 1) != 0) {
        sp30->unk_8 -= cols;
        if (sp30->unk_8 < 0) {
            sp30->unk_8 = (sp30->unk_8 % cols) + ((count - 1) / cols + 1) * cols;
        }
        if (sp30->unk_8 > count - 1) {
            sp30->unk_8 -= cols;
        }
    }

    if (prev_unk_8 != sp30->unk_8) {
        if (sp30->unk_4 != sp30->unk_8 / (cols * rows)) {
            sp30->unk_4 = sp30->unk_8 / (cols * rows);
        }
    }

    if (elem->unk_0 == -1) {
        if (((lbl_1_bss_D58[4] >> 10) & 1) != 0) {
            sp30->unk_2 ^= 1;
        }
        if (((lbl_1_bss_D58[4] >> 11) & 1) != 0) {
            if ((s8)++sp30->unk_3 == 6) {
                sp30->unk_3 = 0;
            }
        }
    }

    if (((lbl_1_bss_D58[4] >> 12) & 1) != 0) {
        lbl_1_bss_96A = 52;
    }

    fn_1_4C16C();
}
/* fzgx:end fn_1_4BD4C */

/* fzgx:begin fn_1_4C16C noprologue */
#include "types.h"

typedef struct FontColor {
    u8 r, g, b, a;
} FontColor;

/* one entry of the font table (0x38 bytes) */
typedef struct FontInfo {
    s32 image;
    u8 width;
    u8 height;
    u8 pad_6[2];
    s32 first;
    s32 last;
    s8 columns;
    s8 rows;
    u8 pad_12[2];
    f32 cell_w;
    f32 cell_h;
    u8 pad_1C[0x10];
    u16 *kana;
    s16 *kana_image;
    f32 scale;
} FontInfo;

/* the text state lbl_1_bss_4B9CC (0x5C bytes) */
typedef struct FontState {
    f32 home_x;
    f32 x;
    f32 y;
    s16 font;
    s16 rotation;
    FontColor color;
    FontColor color_add;
    f32 z;
    f32 scale_x;
    f32 scale_y;
    f32 space_scale;
    f32 alpha;
    u32 flags;
    s16 width;
    s16 shadow_x;
    s16 shadow_y;
    u8 align;
    s8 page;
    f32 shadow_alpha;
    f32 spacing;
    f32 line_spacing;
    u8 unk_44;
    u8 unk_45;
    u8 unk_46;
    u8 unk_47;
    s16 unk_48;
    s16 unk_4A;
    s16 unk_4C;
    s16 unk_4E;
    f32 unk_50;
    u32 unk_54;
    u32 unk_58;
} FontState;

typedef struct FontPacket {
    s32 image;
    f32 x, y, z;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 rotation_z, rotation_y;
    f32 alpha;
    u32 flags;
    f32 depth;
    FontColor color, color_add;
    u32 format;
    u16 width, height;
    void *pixels;
    void *secondary;
    u32 vertex_callback;
    f32 unk_54;
} FontPacket;

typedef struct FontClip {
    s32 enabled;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
} FontClip;

/* the font test screen's selection (lbl_1_bss_4BB30) */
typedef struct FontViewer {
    s8 font;
    s8 prev_font;
    s8 bold;
    s8 style;
    s8 page;
    u8 pad_5[3];
    s32 cursor;
} FontViewer;

extern void fn_1_A8EB0(int, int);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8E78(const char *);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);
extern f32 fn_1_519FC(f32);
extern f32 fn_1_51AC0(f32);
extern f32 fn_1_51B84(f32);
extern f32 fn_1_51BFC(f32);
extern int fn_1_4F734(FontPacket *);
extern void fn_1_4E500(void);
extern void fn_1_48D80(void *);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(void *);

extern FontViewer lbl_1_bss_4BB30;
extern FontState lbl_1_bss_4B9CC;
extern FontClip lbl_1_bss_4BA30;
extern s32 lbl_1_bss_40BBC[44];


/* font.c's .data objects in retail order: the retail TU addresses them off one section base */
u16 fzgx_obj_lbl_1_data_1A3B8[0x56C] = {1};
u8 fzgx_data_gap_AD8[0xAF0 - 0xAD8] = {1};
FontInfo fzgx_obj_lbl_1_data_1AEA8[44] = {1};
u8 fzgx_data_gap_1490[0x180C - 0x1490] = {1};
const char *fzgx_font_names[44] = {0};
u8 fzgx_data_gap_18BC[0x18F4 - 0x18BC] = {1};
const char *fzgx_style_names[6] = {0};
u8 fzgx_data_gap_190C[0x1CFC - 0x190C] = {1};
char fzgx_obj_lbl_1_data_1C0B4[4] = " ";
u8 fzgx_data_gap_1D00[0x1D14 - 0x1D00] = {1};
char fzgx_obj_lbl_1_data_1C0CC[4] = "\x81\x45";
u8 fzgx_data_gap_1D18[0x2070 - 0x1D18] = {1};
#pragma section code_type ".fzgxpool"
static void fzgx_base_order_data(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: the TU references .data before its other sections */
    s = *(u8 *)&fzgx_obj_lbl_1_data_1A3B8;
    s = *(u8 *)&fzgx_obj_lbl_1_data_1AEA8;
    s = *(u8 *)&fzgx_font_names;
    s = *(u8 *)&fzgx_style_names;
    s = *(u8 *)&fzgx_obj_lbl_1_data_1C0B4;
    s = *(u8 *)&fzgx_obj_lbl_1_data_1C0CC;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_rodata_FD0[(0x10C0 - 0xFD0) / 4] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBF800000, 0xBF800000, 0x3F800000, 0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x40266666, 0x00000000, 0x40266666, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3FCCCCCD, 0xBF800000, 0x40666666, 0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000, 0xBFB33333, 0x406CCCCD, 0x3FA66666, 0x00000000, 0x3FCCCCCD, 0x3F000000, 0xBF666666, 0xBF4CCCCD, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_10C0(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
    volatile f64 d;
    s = 0.0f;
    d = 0.5;
    s = 0.75f;
    s = 1.0f;
    s = 255.0f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_10E0(void) {
    volatile f64 d;  /* fzgx-allow: S2 pool primer sink */
    d = 4503599627370496.0;
}
static const FontColor font_default_color = {0xFF, 0xFF, 0xFF, 0xFF};
static const FontColor font_default_color_add = {0x00, 0x00, 0x00, 0x00};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_10F0(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
    volatile f64 d;
    s = 0.05f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_rodata_1100[(0x1320 - 0x1100) / 4] = {0x00000000, 0x000D0000, 0x00000000, 0x070D0000, 0x00000000, 0x010B0000, 0x00000000, 0x010C0000, 0x00000000, 0x02070000, 0x00000000, 0x02070000, 0x00000000, 0x08090000, 0x00000000, 0x08090000, 0x00000000, 0x10080000, 0x00000000, 0x01080000, 0x00000000, 0x0D0B0000, 0x00000000, 0x010B0000, 0x00000000, 0x010A0000, 0x00000000, 0x0C0A0000, 0x00000000, 0x060E0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x070B0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x09070000, 0x00000000, 0x060A0000, 0x00000000, 0x060F0000, 0x00000000, 0x09070000, 0x00000000, 0x03140000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x070B0000, 0x00000000, 0x050E0000, 0x00000000, 0x070B0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x02150000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04110000, 0x00000000, 0x05100000, 0x00000000, 0x04110000, 0x00000000, 0x04120000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04110000, 0x00000000, 0x04110000, 0x00000000, 0x09070000, 0x00000000, 0x050C0000, 0x00000000, 0x05110000, 0x00000000, 0x060E0000, 0x00000000, 0x02140000, 0x00000000, 0x04110000, 0x00000000, 0x04120000, 0x00000000, 0x05100000, 0x00000000, 0x04120000, 0x00000000, 0x05100000, 0x00000000, 0x060F0000, 0x00000000, 0x060E0000, 0x00000000, 0x04110000, 0x00000000, 0x05110000, 0x00000000, 0x01170000, 0x00000000, 0x03120000, 0x00000000, 0x04110000, 0x00000000, 0x04100000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1320[(0x1398 - 0x1320) / 4] = {0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00090000, 0x00000000, 0x000D0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1398[(0x1410 - 0x1398) / 4] = {0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00090000, 0x00000000, 0x000D0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1410[(0x14E8 - 0x1410) / 4] = {0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x04080000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_14E8[(0x15C0 - 0x14E8) / 4] = {0x00000000, 0x00190000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00120000, 0x00000000, 0x00110000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x000B0000, 0x00000000, 0x000F0000, 0x00000000, 0x00180000, 0x00000000, 0x00110000, 0x00000000, 0x001D0000, 0x00000000, 0x00150000, 0x00000000, 0x00170000, 0x00000000, 0x00150000, 0x00000000, 0x00170000, 0x00000000, 0x00160000, 0x00000000, 0x00180000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00190000, 0x00000000, 0x001F0000, 0x00000000, 0x00180000, 0x00000000, 0x00170000, 0x00000000, 0x00130000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_15C0[(0x1698 - 0x15C0) / 4] = {0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x000B0000, 0x00000000, 0x00080000, 0x00000000, 0x000D0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000F0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1698[(0x1700 - 0x1698) / 4] = {0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00080000, 0x00000000, 0x000E0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1700[(0x1888 - 0x1700) / 4] = {0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x00060000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000F0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000F0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x00050000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1888[(0x1A08 - 0x1888) / 4] = {0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00050000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1A08[(0x1A78 - 0x1A08) / 4] = {0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0xFD070000, 0x00000000, 0xFD050000, 0x00000000, 0xFD090000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1A78[(0x1AE8 - 0x1A78) / 4] = {0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0xFE050000, 0x00000000, 0xFE030000, 0x00000000, 0xFE060000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1AE8[(0x1B58 - 0x1AE8) / 4] = {0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0xFD0C0000, 0x00000000, 0xFD080000, 0x00000000, 0xFD0A0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1B58[(0x1E38 - 0x1B58) / 4] = {0x00000000, 0x000C0000, 0x00000000, 0x00020000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000A0000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00040000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x00020000, 0x00000000, 0x00060000, 0x00000000, 0x00020000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00020000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00040000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x000C0000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x000A0000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_1E38[(0x2118 - 0x1E38) / 4] = {0x00000000, 0x000C0000, 0x00000000, 0x0A040000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x04100000, 0x00000000, 0x00060000, 0x00000000, 0x08080000, 0x00000000, 0x08080000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x09060000, 0x00000000, 0x050E0000, 0x00000000, 0x0A040000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x070A0000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x0A040000, 0x00000000, 0x0A040000, 0x00000000, 0x09060000, 0x00000000, 0x09060000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x070A0000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x050E0000, 0x00000000, 0x03120000, 0x00000000, 0x050E0000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x02140000, 0x00000000, 0x08080000, 0x00000000, 0x070A0000, 0x00000000, 0x03120000, 0x00000000, 0x08080000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x060E0000, 0x00000000, 0x060C0000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x02140000, 0x00000000, 0x050E0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_2118[(0x23C0 - 0x2118) / 4] = {0x00000000, 0x00120000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x010F0000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x000E0000, 0x00000000, 0x05080000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x020E0000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_rodata_23C0[(0x2668 - 0x23C0) / 4] = {0x00000000, 0x00120000, 0x00000000, 0x07040000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x010F0000, 0x00000000, 0x06080000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x000E0000, 0x00000000, 0x05080000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x07040000, 0x00000000, 0x07040000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x020E0000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x07040000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
static void fzgx_pool_keep(void) {
    const u32 *volatile cp;  /* fzgx-allow: S2 pool primer sink */
    cp = fzgx_pool_rodata_FD0;
}
#pragma section code_type ".text"
static const FontColor fzgx_shadow_color = {0, 0, 0, 0};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_266C(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 0.5f;
    s = 0.01f;
    s = 0.02f;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_2678(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = -1.0f;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_267C(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 640.0f;
    s = 480.0f;
}
#pragma section code_type ".text"

#define FONTS fzgx_obj_lbl_1_data_1AEA8

static inline void font_reset(void) {
    lbl_1_bss_4B9CC.font = 42;
    lbl_1_bss_4B9CC.color = font_default_color;
    lbl_1_bss_4B9CC.color_add = font_default_color_add;
    lbl_1_bss_4B9CC.rotation = 0;
    lbl_1_bss_4B9CC.z = 0.05f;
    lbl_1_bss_4B9CC.scale_x = 1.0f;
    lbl_1_bss_4B9CC.scale_y = 1.0f;
    lbl_1_bss_4B9CC.space_scale = 1.0f;
    lbl_1_bss_4B9CC.alpha = 1.0f;
    lbl_1_bss_4B9CC.flags = 0;
    lbl_1_bss_4B9CC.align = 0;
    lbl_1_bss_4B9CC.width = 0;
    lbl_1_bss_4B9CC.shadow_x = 2;
    lbl_1_bss_4B9CC.shadow_y = 2;
    lbl_1_bss_4B9CC.shadow_alpha = 0.75f;
    lbl_1_bss_4B9CC.page = 0;
    lbl_1_bss_4B9CC.spacing = 0.0f;
    lbl_1_bss_4B9CC.line_spacing = 0.0f;
    lbl_1_bss_4B9CC.unk_44 = 1;
    lbl_1_bss_4B9CC.unk_45 = 0;
    lbl_1_bss_4B9CC.unk_54 = 0;
    lbl_1_bss_4B9CC.unk_50 = 0.0f;
    lbl_1_bss_4B9CC.unk_46 = 0;
    lbl_1_bss_4B9CC.unk_47 = 0;
    lbl_1_bss_4B9CC.unk_48 = 0;
    lbl_1_bss_4B9CC.unk_4A = 0;
    lbl_1_bss_4B9CC.unk_4C = 640;
    lbl_1_bss_4B9CC.unk_4E = 480;
    lbl_1_bss_4B9CC.unk_58 = 5;
}

static inline void font_set_scale(f32 value1, f32 value2) {
    FontInfo *font = &FONTS[lbl_1_bss_4B9CC.font];

    lbl_1_bss_4B9CC.scale_x = value1 * font->scale;
    lbl_1_bss_4B9CC.scale_y = value2 * font->scale;
}

static inline void font_set_font(s16 index) {
    lbl_1_bss_4B9CC.font = index;
    font_set_scale(1.0f, 1.0f);
}

static inline void font_set_pos(f32 x, f32 y) {
    lbl_1_bss_4B9CC.x = x;
    lbl_1_bss_4B9CC.home_x = x;
    lbl_1_bss_4B9CC.y = y;
}

static inline void font_set_flags(u32 value) {
    lbl_1_bss_4B9CC.flags |= value;
}

static inline void font_set_page(s8 value) {
    lbl_1_bss_4B9CC.page = value;
}

static inline void font_set_color(const FontColor *color) {
    lbl_1_bss_4B9CC.color = *color;
}

static inline void font_set_color_add(const FontColor *color) {
    lbl_1_bss_4B9CC.color_add = *color;
}

static inline void font_clip_reset(void) {
    FontClip *clip = &lbl_1_bss_4BA30;

    clip->enabled = 1;
    clip->unk_4 = 640.0f;
    clip->unk_8 = 0.0f;
    clip->unk_C = 480.0f;
    clip->unk_10 = 0.0f;
}

static inline void font_draw_packet(FontPacket *value) {
    FontPacket local = *value;
    int x_ok;
    int y_ok;

    if (lbl_1_bss_4B9CC.unk_45 != 0) {
        local.x = fn_1_519FC(local.x);
        local.y = fn_1_51AC0(local.y);
        local.scale_x = fn_1_51B84(local.scale_x);
        local.scale_y = fn_1_51BFC(local.scale_y);
    }

    if (lbl_1_bss_4B9CC.unk_47 != 0) {
        x_ok = (local.x > (lbl_1_bss_4B9CC.unk_48 + lbl_1_bss_4B9CC.unk_4C))
                   ? 0
                   : ((local.x < lbl_1_bss_4B9CC.unk_48) ? 0 : 1);
        if (x_ok == 0 ||
            (y_ok = (local.y > (lbl_1_bss_4B9CC.unk_4A + lbl_1_bss_4B9CC.unk_4E))
                        ? 0
                        : ((local.y < lbl_1_bss_4B9CC.unk_4A) ? 0 : 1)) == 0) {
            return;
        }
    }

    if (lbl_1_bss_4B9CC.unk_44 != 0) {
        fn_1_4F734(&local);
    } else if ((local.flags & 0x400000) != 0) {
        if (lbl_1_bss_4B9CC.unk_46 == 0) {
            fn_1_4E500();
        }
        fn_1_48D80(&local);
        if (lbl_1_bss_4B9CC.unk_46 == 0) {
            fn_1_4E6F4();
        }
    } else {
        fn_1_4E724(&local);
    }
}

static inline void font_draw_glyph(s32 code) {
    FontPacket pkt;
    FontInfo *font = (FontInfo *)((u8 *)FONTS + lbl_1_bss_4B9CC.font * 0x38);
    s32 idx = code - font->first;
    s32 row = idx / font->columns;
    s32 col = idx % font->columns;
    f32 u;
    f32 v;

    pkt.image = font->image;
    pkt.x = lbl_1_bss_4B9CC.x;
    pkt.y = lbl_1_bss_4B9CC.y;
    pkt.z = lbl_1_bss_4B9CC.z;
    u = font->cell_w * col;
    v = font->cell_h * row;
    pkt.u0 = u;
    pkt.v0 = v;
    pkt.u1 = u + font->cell_w;
    pkt.v1 = v + font->cell_h;
    pkt.scale_x = lbl_1_bss_4B9CC.scale_x * font->cell_w;
    pkt.scale_y = lbl_1_bss_4B9CC.scale_y * font->cell_h;
    pkt.rotation_z = lbl_1_bss_4B9CC.rotation;
    pkt.alpha = lbl_1_bss_4B9CC.alpha;
    pkt.flags = lbl_1_bss_4B9CC.unk_58 | (lbl_1_bss_4B9CC.flags & ~0xF);
    pkt.color = lbl_1_bss_4B9CC.color;
    pkt.color_add = lbl_1_bss_4B9CC.color_add;
    if (lbl_1_bss_4B9CC.unk_54 != 0) {
        pkt.vertex_callback = lbl_1_bss_4B9CC.unk_54;
        pkt.flags |= 0x4000000;
    }
    font_draw_packet(&pkt);
}

#pragma fp_contract off
void fn_1_4C16C(void) {
    FontViewer *viewer = &lbl_1_bss_4BB30;
    s32 i;
    s32 j;
    s32 page_size;
    s32 rows;
    FontInfo *font;
    s32 cols;

    font = &FONTS[viewer->font];
    if (font->image == -1) {
        cols = 16;
        rows = 8;
    } else {
        cols = font->columns;
        rows = font->rows;
    }

    fn_1_A8EB0(1, 3);
    if (font->image == -1) {
        fn_1_A8DD4("\"%s\" %12s %d/%d\n", fzgx_font_names[viewer->font], fzgx_style_names[viewer->style], viewer->style, 5);
    } else {
        fn_1_A8DD4("\"%s\"\n", fzgx_font_names[viewer->font]);
    }
    fn_1_A8E78("\n");
    fn_1_A8E78("LR:font select\n");
    if (font->image == -1) {
        fn_1_A8E78("DU:page next/prev\n");
    }
    fn_1_A8E78("3D:charactor select\n");
    if (font->image == -1) {
        fn_1_A8E78("X :fixed/proportional\n");
        fn_1_A8E78("Y :style change\n");
    }

    font_reset();
    font_set_font(viewer->font);
    lbl_1_bss_4B9CC.home_x = lbl_1_bss_4B9CC.x = 320.0f - font->scale * (font->width * cols) / 2.0f;
    lbl_1_bss_4B9CC.y = 150.0f;
    if (viewer->bold) {
        font_set_flags(0x80000000);
    }
    font_set_page(viewer->style);

    if (font->image == -1) {
        char buf[3];
        u16 *p;

        page_size = cols * rows;
        buf[2] = 0;
        font_clip_reset();
        for (i = 0, p = font->kana; *p != 0; i++, p++) {
            if (i < viewer->page * page_size) {
                continue;
            }
            if (i >= viewer->page * page_size + page_size) {
                break;
            }
            buf[0] = *p >> 8;
            buf[1] = *p;
            {
                FontColor color = {0x80, 0x80, 0x80, 0x00};
                font_set_color(&color);
            }
            {
                FontColor color = {0xFF, 0xFF, 0xFF, 0x00};
                for (j = 0; j < 0x56B; j++) {
                    if (*p == fzgx_obj_lbl_1_data_1A3B8[j]) {
                        font_set_color(&color);
                    }
                }
            }
            if (viewer->cursor == i) {
                FontColor color = {0xFF, 0xFF, 0x00, 0x00};
                font_set_color(&color);
            }
            {
                if (font->kana_image[i] == -1) {
                    fn_1_4A0D8(fzgx_obj_lbl_1_data_1C0CC);
                    font_set_font(viewer->font);
                } else {
                    fn_1_4A0D8(buf);
                }
                if (i % cols == cols - 1) {
                    fn_1_4A0D8("\n");
                }
            }
            {
                FontColor color = {0xFF, 0xFF, 0xFF, 0x00};
                font_set_color(&color);
            }
        }
        lbl_1_bss_4BA30.enabled = 0;
        lbl_1_bss_4B9CC.flags &= ~0x80000000;
        if (font->kana_image[viewer->cursor] != -1) {
            buf[0] = (font->kana[viewer->cursor] >> 8) & 0xFF;
            buf[1] = font->kana[viewer->cursor];
            font_set_pos(12.0f, 150.0f);
            font_set_scale(2.0f, 2.0f);
            fn_1_4A0D8(buf);
        }
        font_set_font(3);
        font_set_pos(12.0f, (font->height * 2 + 162));
        font_set_scale(1.0f, 1.0f);
        fn_1_4AE0C("%X\n", font->kana[viewer->cursor]);
        if (font->kana_image[viewer->cursor] == -1) {
            fn_1_4A0D8("is no load.\n");
        } else {
            fn_1_4AE0C("aram:%d\n", font->kana_image[viewer->cursor]);
        }
        fn_1_4AE0C("\npage:%d/%d\n", viewer->page, lbl_1_bss_40BBC[viewer->font] / page_size);
    } else {
        char buf[2];

        buf[1] = 0;
        font_clip_reset();
        for (i = font->first, j = 0; i < font->last + 1; i++, j++) {
            if (viewer->cursor == i) {
                FontColor color = {0xFF, 0xFF, 0x00, 0x00};
                font_set_color(&color);
            }
            if (i == 0) {
                FontColor color = {0xFF, 0x00, 0x00, 0x00};
                font_set_color_add(&color);
                font_draw_glyph(0);
                fn_1_4A0D8(fzgx_obj_lbl_1_data_1C0B4);
            } else if (i == 10) {
                FontColor color = {0xFF, 0x00, 0x00, 0x00};
                font_set_color_add(&color);
                font_draw_glyph(10);
                fn_1_4A0D8(fzgx_obj_lbl_1_data_1C0B4);
            } else {
                buf[0] = i;
                fn_1_4A0D8(buf);
            }
            if (j % cols == cols - 1) {
                fn_1_4A0D8("\n");
            }
            {
                FontColor color = {0xFF, 0xFF, 0xFF, 0x00};
                FontColor color_add = {0x00, 0x00, 0x00, 0x00};
                font_set_color(&color);
                font_set_color_add(&color_add);
            }
        }
        lbl_1_bss_4BA30.enabled = 0;
        lbl_1_bss_4B9CC.flags &= ~0x80000000;
        buf[0] = viewer->cursor;
        font_set_pos(12.0f, 150.0f);
        font_set_scale(2.0f, 2.0f);
        fn_1_4A0D8(buf);
        font_set_font(3);
        font_set_pos(12.0f, (font->height * 2 + 162));
        font_set_scale(1.0f, 1.0f);
        fn_1_4AE0C("%X", viewer->cursor);
    }
}
#pragma fp_contract reset
/* fzgx:end fn_1_4C16C */

/* fzgx:begin fn_1_4CDE4 */
/* Convert the selected font entry's byte metrics to floating-point coordinates. */
void fn_1_4CDE4(f32 *x, f32 *y) {
    Obj_1_data_1AEA8 *entry;
    s16 index;

    index = lbl_1_bss_4B9CC.unk_C;
    entry = (Obj_1_data_1AEA8 *)((u8 *)&lbl_1_data_1AEA8 + index * 0x38);
    *x = (f32)(u32)entry->unk_4;
    *y = (f32)(u32)entry->unk_5;
}
/* fzgx:end fn_1_4CDE4 */

/* fzgx:begin fn_1_4CE48 */
void fn_1_4CE48(Obj_1_bss_4B9CC *obj, f32 limit) {
    f32 saved;
    f32 first;
    f32 adjusted;
    s32 count;

    saved = lbl_1_bss_4B9CC.unk_1C;
    first = fn_1_4B1D4(1, (u8 *)obj);
    count = fn_1_4B1D4(3, (u8 *)obj);
    count = count - 1;
    adjusted = lbl_1_bss_4B9CC.unk_3C * count;
    adjusted = first + adjusted;
    if (adjusted > limit) {
        lbl_1_bss_4B9CC.unk_1C =
            lbl_1_bss_4B9CC.unk_1C * (limit / adjusted);
    }
    fn_1_4A0D8( (const char*)(Obj_1_bss_4B9CC *)(obj));
    lbl_1_bss_4B9CC.unk_1C = saved;
}
/* fzgx:end fn_1_4CE48 */

/* fzgx:begin fn_1_4CF3C */
typedef struct {
    unsigned char Sig_parse_format_justification_options;
    unsigned char Sig_parse_format_sign_options;
    unsigned char precision_specified;
    unsigned char alternate_form;
    unsigned char Sig_parse_format_argument_options;
    unsigned char conversion_char;
    int field_width;
    int precision;
} Sig_parse_format_print_format;
typedef struct Sig_parse_format_MkVaListState {
    signed char gpr;
    signed char fpr;
    unsigned short reserved;
    char *input_arg_area;
    char *reg_save_area;
} Sig_parse_format___va_list[1];
typedef Sig_parse_format___va_list Sig_parse_format_va_list;


void fn_1_4CF3C(const char *format, f32 x, ...) {
    Obj_1_bss_4B9CC *p_lbl_1_bss_4B9CC;
    char buffer[512];
    Sig_parse_format_va_list list;
    f32 saved;
    f32 first;
    f32 adjusted;
    s32 count;

    __builtin_va_info(&list);

    fn_8008077C((u32)buffer, (u32)(format), (u32)((Sig_parse_format_va_list *)&list));

    p_lbl_1_bss_4B9CC = &lbl_1_bss_4B9CC;
    saved = p_lbl_1_bss_4B9CC->unk_1C;
    first = fn_1_4B1D4(1, (u8 *)buffer);
    count = fn_1_4B1D4(3, (u8 *)buffer);
    count = count - 1;
    adjusted = p_lbl_1_bss_4B9CC->unk_3C * count;
    adjusted = first + adjusted;
    if (adjusted > x) {
        p_lbl_1_bss_4B9CC->unk_1C = p_lbl_1_bss_4B9CC->unk_1C * (x / adjusted);
    }
    fn_1_4A0D8(buffer);
    p_lbl_1_bss_4B9CC->unk_1C = saved;
}
/* fzgx:end fn_1_4CF3C */

/* fzgx:begin fn_1_4D0A0 */
void fn_1_4D0A0(void) {
    Obj_1_bss_4BA30 *bss = &lbl_1_bss_4BA30;
    f32 *rodata = (f32 *)lbl_1_rodata_FD0;

    bss->unk_0 = 1;
    bss->unk_4 = rodata[0x16ac / 4];
    bss->unk_8 = rodata[0xf0 / 4];
    bss->unk_C = rodata[0x16b0 / 4];
    bss->unk_10 = rodata[0xf0 / 4];
}
/* fzgx:end fn_1_4D0A0 */

/* fzgx:begin fn_1_4D0D4 */
void fn_1_4D0D4(u32 *object, f32 value) {
    u32 data = *object;
    fn_1_4D10C(&data, lbl_1_rodata_26B8[0], value);
}
/* fzgx:end fn_1_4D0D4 */

/* fzgx:begin fn_1_4D10C */
typedef struct FontParams_fn_1_4D10C {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams_fn_1_4D10C;

typedef struct fn_1_4EB74_FontObject_fn_1_4D10C {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject_fn_1_4D10C;

typedef struct fn_1_54668_node_fn_1_4D10C {
    struct fn_1_54668_node_fn_1_4D10C *next;
    void *data;
} fn_1_54668_node_fn_1_4D10C;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_fn_1_4D10C;

typedef struct fn_1_547F8_node_fn_1_4D10C {
    struct fn_1_547F8_node_fn_1_4D10C *next;
    void (*callback)(struct fn_1_547F8_node_fn_1_4D10C *);
} fn_1_547F8_node_fn_1_4D10C;

typedef struct fn_1_563E4_FontState_fn_1_4D10C {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState_fn_1_4D10C;

typedef struct State_fn_1_4D10C {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State_fn_1_4D10C;

typedef struct Config_fn_1_4D10C {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config_fn_1_4D10C;

typedef struct ImageInfo_fn_1_4D10C {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo_fn_1_4D10C;

typedef struct Images_fn_1_4D10C {
    u32 unk_0;
    ImageInfo_fn_1_4D10C *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images_fn_1_4D10C;

typedef struct Resource_fn_1_4D10C {
    s32 loaded;
    u8 unk_4[0x1c];
    Images_fn_1_4D10C *images;
    u32 unk_24;
} Resource_fn_1_4D10C;

struct fn_1_530C8_lbl_1_rodata_282C_fn_1_4D10C {
    f32 unk_0;
};

struct FzgxCopy_88_fn_1_4D10C { u32 words[22]; };
extern void *lbl_801A6D00;
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void OSReport(const char *format, ...);
extern u8 *lbl_801A66CC;
extern void mathutil_mtxA_rotate_z(s16 arg0);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);


#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.0f;
}
static const unsigned long fzgx_pool_table3[1] = {0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
}
static const unsigned long fzgx_pool_table5[5] = {0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5999999046325684f;
    s = 0.0f;
}
static const unsigned long fzgx_pool_table7[6] = {0x40266666, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.600000023841858f;
}
static const unsigned long fzgx_pool_table9[1] = {0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.5999999046325684f;
}
static const unsigned long fzgx_pool_table11[5] = {0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.399999976158142f;
    s = 3.700000047683716f;
    s = 1.2999999523162842f;
}
static const unsigned long fzgx_pool_table13[3] = {0x00000000, 0x3FCCCCCD, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.8999999761581421f;
    s = -0.800000011920929f;
}
static const unsigned long fzgx_pool_table15[14] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const unsigned long *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.75f;
}
static const unsigned long fzgx_pool_table17[1] = {0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const unsigned long *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 255.0f;
}
static const unsigned long fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const unsigned long *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table21[2] = {0xFFFFFFFF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const unsigned long *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05000000074505806f;
}
static const unsigned long fzgx_pool_table23[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const unsigned long *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table25[1371] = {0x00000000, 0x000D0000, 0x00000000, 0x070D0000, 0x00000000, 0x010B0000, 0x00000000, 0x010C0000, 0x00000000, 0x02070000, 0x00000000, 0x02070000, 0x00000000, 0x08090000, 0x00000000, 0x08090000, 0x00000000, 0x10080000, 0x00000000, 0x01080000, 0x00000000, 0x0D0B0000, 0x00000000, 0x010B0000, 0x00000000, 0x010A0000, 0x00000000, 0x0C0A0000, 0x00000000, 0x060E0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x070B0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x09070000, 0x00000000, 0x060A0000, 0x00000000, 0x060F0000, 0x00000000, 0x09070000, 0x00000000, 0x03140000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x070B0000, 0x00000000, 0x050E0000, 0x00000000, 0x070B0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x02150000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04110000, 0x00000000, 0x05100000, 0x00000000, 0x04110000, 0x00000000, 0x04120000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04110000, 0x00000000, 0x04110000, 0x00000000, 0x09070000, 0x00000000, 0x050C0000, 0x00000000, 0x05110000, 0x00000000, 0x060E0000, 0x00000000, 0x02140000, 0x00000000, 0x04110000, 0x00000000, 0x04120000, 0x00000000, 0x05100000, 0x00000000, 0x04120000, 0x00000000, 0x05100000, 0x00000000, 0x060F0000, 0x00000000, 0x060E0000, 0x00000000, 0x04110000, 0x00000000, 0x05110000, 0x00000000, 0x01170000, 0x00000000, 0x03120000, 0x00000000, 0x04110000, 0x00000000, 0x04100000, 0x00000000, 0x00000000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00090000, 0x00000000, 0x000D0000, 0x00000000, 0x00000000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00090000, 0x00000000, 0x000D0000, 0x00000000, 0x00000000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x04080000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x00000000, 0x00000000, 0x00190000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00120000, 0x00000000, 0x00110000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x000B0000, 0x00000000, 0x000F0000, 0x00000000, 0x00180000, 0x00000000, 0x00110000, 0x00000000, 0x001D0000, 0x00000000, 0x00150000, 0x00000000, 0x00170000, 0x00000000, 0x00150000, 0x00000000, 0x00170000, 0x00000000, 0x00160000, 0x00000000, 0x00180000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00190000, 0x00000000, 0x001F0000, 0x00000000, 0x00180000, 0x00000000, 0x00170000, 0x00000000, 0x00130000, 0x00000000, 0x00000000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x000B0000, 0x00000000, 0x00080000, 0x00000000, 0x000D0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000F0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00000000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00080000, 0x00000000, 0x000E0000, 0x00000000, 0x00000000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x00060000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000F0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000F0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x00050000, 0x00000000, 0x00000000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00050000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00000000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0xFD070000, 0x00000000, 0xFD050000, 0x00000000, 0xFD090000, 0x00000000, 0x00000000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0xFE050000, 0x00000000, 0xFE030000, 0x00000000, 0xFE060000, 0x00000000, 0x00000000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0xFD0C0000, 0x00000000, 0xFD080000, 0x00000000, 0xFD0A0000, 0x00000000, 0x00000000, 0x00000000, 0x000C0000, 0x00000000, 0x00020000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000A0000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00040000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x00020000, 0x00000000, 0x00060000, 0x00000000, 0x00020000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00020000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00040000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x000C0000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x000A0000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00000000, 0x00000000, 0x000C0000, 0x00000000, 0x0A040000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x04100000, 0x00000000, 0x00060000, 0x00000000, 0x08080000, 0x00000000, 0x08080000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x09060000, 0x00000000, 0x050E0000, 0x00000000, 0x0A040000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x070A0000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x0A040000, 0x00000000, 0x0A040000, 0x00000000, 0x09060000, 0x00000000, 0x09060000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x070A0000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x050E0000, 0x00000000, 0x03120000, 0x00000000, 0x050E0000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x02140000, 0x00000000, 0x08080000, 0x00000000, 0x070A0000, 0x00000000, 0x03120000, 0x00000000, 0x08080000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x060E0000, 0x00000000, 0x060C0000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x02140000, 0x00000000, 0x050E0000, 0x00000000, 0x00000000, 0x00000000, 0x00120000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x010F0000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x000E0000, 0x00000000, 0x05080000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x020E0000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00000000, 0x00000000, 0x00120000, 0x00000000, 0x07040000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x010F0000, 0x00000000, 0x06080000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x000E0000, 0x00000000, 0x05080000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x07040000, 0x00000000, 0x07040000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x020E0000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x07040000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const unsigned long *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 0.009999999776482582f;
    s = 0.019999999552965164f;
}
static const unsigned long fzgx_pool_table27[1] = {0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const unsigned long *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 640.0f;
    s = 480.0f;
}
static const unsigned long fzgx_pool_table29[9] = {0x80808000, 0xFFFFFF00, 0xFFFF0000, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0xFF000000, 0xFFFFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const unsigned long *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 150.0f;
    s = 12.0f;
    s = 2.0f;
    s = 0.10000000149011612f;
}
static const unsigned long fzgx_pool_table31[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const unsigned long *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
}
#pragma section code_type ".text"

extern void fn_1_53B14(void *, f32, f32, f32, f32, f32);
extern int __abs(int);

void fn_1_4D10C(void *a, f32 p1, f32 p2) {
    s32 w, h, cx, cy;
    if ((s32)lbl_1_bss_4BA30.unk_0 != 0) {
        lbl_1_bss_4BA30.unk_0 = 0;
        if (640.0f == lbl_1_bss_4BA30.unk_4 && 0.0 == lbl_1_bss_4BA30.unk_8 && 480.0f == lbl_1_bss_4BA30.unk_C && 0.0 == lbl_1_bss_4BA30.unk_10) {
            return;
        }
        if (lbl_1_bss_4BA30.unk_C > lbl_1_bss_4BA30.unk_10) return;
        if (lbl_1_bss_4BA30.unk_4 > lbl_1_bss_4BA30.unk_8) return;
        {
            f32 left = lbl_1_bss_4BA30.unk_4;
            f32 right = lbl_1_bss_4BA30.unk_8;
            f32 bottom = lbl_1_bss_4BA30.unk_10;
            f32 top = lbl_1_bss_4BA30.unk_C;
            w = __abs((right - left));
            h = __abs((top - bottom));
            cx = ((left + right) / 2.0f);
            cy = ((top + bottom) / 2.0f);
        }
        fn_1_53B14(a, cx, cy, w + p2, h + p2, p1);
    }
}
/* fzgx:end fn_1_4D10C */

/* fzgx:begin fn_1_4D274 */
void fn_1_4D274(u32 *object, f32 value) {
    u32 data = *object;
    fn_1_4D2AC(&data, lbl_1_rodata_26B8[0], value);
}
/* fzgx:end fn_1_4D274 */

/* fzgx:begin fn_1_4D2AC noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern void fzgx_pool_sink_f32(f32);
extern void fzgx_pool_sink_f64(f64);
const u32 fzgx_pool_table_0[66] = {
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0xBF800000, 0xBF800000, 0x3F800000, 0xBF800000,
0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000,
0x40266666, 0x00000000, 0x40266666, 0x00000000,
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x3FCCCCCD, 0xBF800000, 0x40666666, 0xBF800000,
0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000,
0xBFB33333, 0x406CCCCD, 0x3FA66666, 0x00000000,
0x3FCCCCCD, 0x3F000000, 0xBF666666, 0xBF4CCCCD,
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0x3FE00000, 0x00000000,
0x3F400000, 0x3F800000, 
};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_108(void) { fzgx_pool_sink_f32(255.0f); }
#pragma section code_type ".text"
const u32 fzgx_pool_table_10c[1] = {
0x00000000, 
};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_110(void) { fzgx_pool_sink_f64(4503599627370496.0); }
#pragma section code_type ".text"
const u32 fzgx_pool_table_118[4] = {
0xFFFFFFFF, 0x00000000, 0x3D4CCCCD, 0x00000000,

};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_128(void) { fzgx_pool_sink_f64(4503601774854144.0); }
#pragma section code_type ".text"
const u32 fzgx_pool_table_130[1371] = {
0x00000000, 0x000D0000, 0x00000000, 0x070D0000,
0x00000000, 0x010B0000, 0x00000000, 0x010C0000,
0x00000000, 0x02070000, 0x00000000, 0x02070000,
0x00000000, 0x08090000, 0x00000000, 0x08090000,
0x00000000, 0x10080000, 0x00000000, 0x01080000,
0x00000000, 0x0D0B0000, 0x00000000, 0x010B0000,
0x00000000, 0x010A0000, 0x00000000, 0x0C0A0000,
0x00000000, 0x060E0000, 0x00000000, 0x050F0000,
0x00000000, 0x050F0000, 0x00000000, 0x050F0000,
0x00000000, 0x04100000, 0x00000000, 0x050F0000,
0x00000000, 0x070B0000, 0x00000000, 0x04100000,
0x00000000, 0x050F0000, 0x00000000, 0x09070000,
0x00000000, 0x060A0000, 0x00000000, 0x060F0000,
0x00000000, 0x09070000, 0x00000000, 0x03140000,
0x00000000, 0x050F0000, 0x00000000, 0x04100000,
0x00000000, 0x050F0000, 0x00000000, 0x04100000,
0x00000000, 0x070B0000, 0x00000000, 0x050E0000,
0x00000000, 0x070B0000, 0x00000000, 0x050F0000,
0x00000000, 0x050F0000, 0x00000000, 0x02150000,
0x00000000, 0x050F0000, 0x00000000, 0x050F0000,
0x00000000, 0x050F0000, 0x00000000, 0x04110000,
0x00000000, 0x05100000, 0x00000000, 0x04110000,
0x00000000, 0x04120000, 0x00000000, 0x050F0000,
0x00000000, 0x050F0000, 0x00000000, 0x04110000,
0x00000000, 0x04110000, 0x00000000, 0x09070000,
0x00000000, 0x050C0000, 0x00000000, 0x05110000,
0x00000000, 0x060E0000, 0x00000000, 0x02140000,
0x00000000, 0x04110000, 0x00000000, 0x04120000,
0x00000000, 0x05100000, 0x00000000, 0x04120000,
0x00000000, 0x05100000, 0x00000000, 0x060F0000,
0x00000000, 0x060E0000, 0x00000000, 0x04110000,
0x00000000, 0x05110000, 0x00000000, 0x01170000,
0x00000000, 0x03120000, 0x00000000, 0x04110000,
0x00000000, 0x04100000, 0x00000000, 0x00000000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00090000, 0x00000000, 0x000D0000,
0x00000000, 0x00000000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00160000,
0x00000000, 0x00160000, 0x00000000, 0x00090000,
0x00000000, 0x000D0000, 0x00000000, 0x00000000,
0x00000000, 0x010E0000, 0x00000000, 0x020C0000,
0x00000000, 0x020C0000, 0x00000000, 0x020C0000,
0x00000000, 0x020C0000, 0x00000000, 0x020C0000,
0x00000000, 0x020C0000, 0x00000000, 0x010E0000,
0x00000000, 0x04080000, 0x00000000, 0x020C0000,
0x00000000, 0x010E0000, 0x00000000, 0x020C0000,
0x00000000, 0x010E0000, 0x00000000, 0x010E0000,
0x00000000, 0x020C0000, 0x00000000, 0x020C0000,
0x00000000, 0x020C0000, 0x00000000, 0x020C0000,
0x00000000, 0x020C0000, 0x00000000, 0x020C0000,
0x00000000, 0x010E0000, 0x00000000, 0x010E0000,
0x00000000, 0x010E0000, 0x00000000, 0x010E0000,
0x00000000, 0x010E0000, 0x00000000, 0x020C0000,
0x00000000, 0x00000000, 0x00000000, 0x00190000,
0x00000000, 0x00170000, 0x00000000, 0x00170000,
0x00000000, 0x00170000, 0x00000000, 0x00120000,
0x00000000, 0x00110000, 0x00000000, 0x00170000,
0x00000000, 0x00170000, 0x00000000, 0x000B0000,
0x00000000, 0x000F0000, 0x00000000, 0x00180000,
0x00000000, 0x00110000, 0x00000000, 0x001D0000,
0x00000000, 0x00150000, 0x00000000, 0x00170000,
0x00000000, 0x00150000, 0x00000000, 0x00170000,
0x00000000, 0x00160000, 0x00000000, 0x00180000,
0x00000000, 0x00170000, 0x00000000, 0x00170000,
0x00000000, 0x00190000, 0x00000000, 0x001F0000,
0x00000000, 0x00180000, 0x00000000, 0x00170000,
0x00000000, 0x00130000, 0x00000000, 0x00000000,
0x00000000, 0x000B0000, 0x00000000, 0x000B0000,
0x00000000, 0x000B0000, 0x00000000, 0x000B0000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x000B0000, 0x00000000, 0x000B0000,
0x00000000, 0x00060000, 0x00000000, 0x00080000,
0x00000000, 0x000B0000, 0x00000000, 0x00080000,
0x00000000, 0x000D0000, 0x00000000, 0x000B0000,
0x00000000, 0x000B0000, 0x00000000, 0x000B0000,
0x00000000, 0x000B0000, 0x00000000, 0x000B0000,
0x00000000, 0x000B0000, 0x00000000, 0x000B0000,
0x00000000, 0x000B0000, 0x00000000, 0x000B0000,
0x00000000, 0x000F0000, 0x00000000, 0x000B0000,
0x00000000, 0x000B0000, 0x00000000, 0x00090000,
0x00000000, 0x00000000, 0x00000000, 0x00100000,
0x00000000, 0x00100000, 0x00000000, 0x00100000,
0x00000000, 0x00100000, 0x00000000, 0x00100000,
0x00000000, 0x00100000, 0x00000000, 0x00100000,
0x00000000, 0x00100000, 0x00000000, 0x00100000,
0x00000000, 0x00100000, 0x00000000, 0x00080000,
0x00000000, 0x000E0000, 0x00000000, 0x00000000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x00060000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000F0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x000F0000,
0x00000000, 0x000D0000, 0x00000000, 0x000D0000,
0x00000000, 0x000D0000, 0x00000000, 0x00050000,
0x00000000, 0x00000000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00050000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x000B0000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x000B0000, 0x00000000, 0x00090000,
0x00000000, 0x00090000, 0x00000000, 0x00090000,
0x00000000, 0x00000000, 0x00000000, 0x00190000,
0x00000000, 0x00190000, 0x00000000, 0x00190000,
0x00000000, 0x00190000, 0x00000000, 0x00190000,
0x00000000, 0x00190000, 0x00000000, 0x00190000,
0x00000000, 0x00190000, 0x00000000, 0x00190000,
0x00000000, 0x00190000, 0x00000000, 0xFD070000,
0x00000000, 0xFD050000, 0x00000000, 0xFD090000,
0x00000000, 0x00000000, 0x00000000, 0x00110000,
0x00000000, 0x00110000, 0x00000000, 0x00110000,
0x00000000, 0x00110000, 0x00000000, 0x00110000,
0x00000000, 0x00110000, 0x00000000, 0x00110000,
0x00000000, 0x00110000, 0x00000000, 0x00110000,
0x00000000, 0x00110000, 0x00000000, 0xFE050000,
0x00000000, 0xFE030000, 0x00000000, 0xFE060000,
0x00000000, 0x00000000, 0x00000000, 0x001A0000,
0x00000000, 0x001A0000, 0x00000000, 0x001A0000,
0x00000000, 0x001A0000, 0x00000000, 0x001A0000,
0x00000000, 0x001A0000, 0x00000000, 0x001A0000,
0x00000000, 0x001A0000, 0x00000000, 0x001A0000,
0x00000000, 0x001A0000, 0x00000000, 0xFD0C0000,
0x00000000, 0xFD080000, 0x00000000, 0xFD0A0000,
0x00000000, 0x00000000, 0x00000000, 0x000C0000,
0x00000000, 0x00020000, 0x00000000, 0x000C0000,
0x00000000, 0x000C0000, 0x00000000, 0x000C0000,
0x00000000, 0x000C0000, 0x00000000, 0x000A0000,
0x00000000, 0x00020000, 0x00000000, 0x00040000,
0x00000000, 0x00040000, 0x00000000, 0x000C0000,
0x00000000, 0x000C0000, 0x00000000, 0x00020000,
0x00000000, 0x00060000, 0x00000000, 0x00020000,
0x00000000, 0x00060000, 0x00000000, 0x00080000,
0x00000000, 0x00060000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00020000,
0x00000000, 0x00020000, 0x00000000, 0x00040000,
0x00000000, 0x00040000, 0x00000000, 0x00060000,
0x00000000, 0x00060000, 0x00000000, 0x000C0000,
0x00000000, 0x000A0000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00060000, 0x00000000, 0x00060000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00060000, 0x00000000, 0x00060000,
0x00000000, 0x00080000, 0x00000000, 0x00060000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x000A0000,
0x00000000, 0x000A0000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x000C0000, 0x00000000, 0x000C0000,
0x00000000, 0x000C0000, 0x00000000, 0x000C0000,
0x00000000, 0x000C0000, 0x00000000, 0x000C0000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00060000,
0x00000000, 0x00080000, 0x00000000, 0x00060000,
0x00000000, 0x00020000, 0x00000000, 0x00040000,
0x00000000, 0x00080000, 0x00000000, 0x00060000,
0x00000000, 0x000A0000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00060000,
0x00000000, 0x00060000, 0x00000000, 0x00060000,
0x00000000, 0x00060000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00080000,
0x00000000, 0x00080000, 0x00000000, 0x00060000,
0x00000000, 0x00000000, 0x00000000, 0x000C0000,
0x00000000, 0x0A040000, 0x00000000, 0x00180000,
0x00000000, 0x00180000, 0x00000000, 0x00180000,
0x00000000, 0x00180000, 0x00000000, 0x04100000,
0x00000000, 0x00060000, 0x00000000, 0x08080000,
0x00000000, 0x08080000, 0x00000000, 0x00180000,
0x00000000, 0x00180000, 0x00000000, 0x09060000,
0x00000000, 0x050E0000, 0x00000000, 0x0A040000,
0x00000000, 0x050E0000, 0x00000000, 0x04100000,
0x00000000, 0x070A0000, 0x00000000, 0x03120000,
0x00000000, 0x04100000, 0x00000000, 0x03120000,
0x00000000, 0x04100000, 0x00000000, 0x04100000,
0x00000000, 0x04100000, 0x00000000, 0x04100000,
0x00000000, 0x04100000, 0x00000000, 0x0A040000,
0x00000000, 0x0A040000, 0x00000000, 0x09060000,
0x00000000, 0x09060000, 0x00000000, 0x050E0000,
0x00000000, 0x04100000, 0x00000000, 0x04100000,
0x00000000, 0x01160000, 0x00000000, 0x02140000,
0x00000000, 0x03120000, 0x00000000, 0x02140000,
0x00000000, 0x03120000, 0x00000000, 0x03120000,
0x00000000, 0x02140000, 0x00000000, 0x01160000,
0x00000000, 0x070A0000, 0x00000000, 0x02140000,
0x00000000, 0x01160000, 0x00000000, 0x03120000,
0x00000000, 0x01160000, 0x00000000, 0x01160000,
0x00000000, 0x03120000, 0x00000000, 0x02140000,
0x00000000, 0x02140000, 0x00000000, 0x01160000,
0x00000000, 0x04100000, 0x00000000, 0x03120000,
0x00000000, 0x01160000, 0x00000000, 0x01160000,
0x00000000, 0x01160000, 0x00000000, 0x01160000,
0x00000000, 0x01160000, 0x00000000, 0x03120000,
0x00000000, 0x03120000, 0x00000000, 0x00180000,
0x00000000, 0x00180000, 0x00000000, 0x00180000,
0x00000000, 0x00180000, 0x00000000, 0x00180000,
0x00000000, 0x03120000, 0x00000000, 0x03120000,
0x00000000, 0x050E0000, 0x00000000, 0x03120000,
0x00000000, 0x050E0000, 0x00000000, 0x050E0000,
0x00000000, 0x04100000, 0x00000000, 0x02140000,
0x00000000, 0x08080000, 0x00000000, 0x070A0000,
0x00000000, 0x03120000, 0x00000000, 0x08080000,
0x00000000, 0x01160000, 0x00000000, 0x02140000,
0x00000000, 0x04100000, 0x00000000, 0x03120000,
0x00000000, 0x03120000, 0x00000000, 0x04100000,
0x00000000, 0x060E0000, 0x00000000, 0x060C0000,
0x00000000, 0x02140000, 0x00000000, 0x03120000,
0x00000000, 0x01160000, 0x00000000, 0x02140000,
0x00000000, 0x02140000, 0x00000000, 0x050E0000,
0x00000000, 0x00000000, 0x00000000, 0x00120000,
0x00000000, 0x06060000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x010F0000,
0x00000000, 0x06060000, 0x00000000, 0x06060000,
0x00000000, 0x06060000, 0x00000000, 0x00120000,
0x00000000, 0x030C0000, 0x00000000, 0x00120000,
0x00000000, 0x030C0000, 0x00000000, 0x000E0000,
0x00000000, 0x05080000, 0x00000000, 0x01100000,
0x00000000, 0x06060000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x06060000,
0x00000000, 0x06060000, 0x00000000, 0x06060000,
0x00000000, 0x06060000, 0x00000000, 0x020E0000,
0x00000000, 0x01100000, 0x00000000, 0x00120000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x06060000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x040A0000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x06060000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x040A0000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00000000,
0x00000000, 0x00120000, 0x00000000, 0x07040000,
0x00000000, 0x040A0000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x010F0000, 0x00000000, 0x06080000,
0x00000000, 0x06060000, 0x00000000, 0x06060000,
0x00000000, 0x00120000, 0x00000000, 0x030C0000,
0x00000000, 0x00120000, 0x00000000, 0x030C0000,
0x00000000, 0x000E0000, 0x00000000, 0x05080000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x07040000, 0x00000000, 0x07040000,
0x00000000, 0x06060000, 0x00000000, 0x06060000,
0x00000000, 0x020E0000, 0x00000000, 0x01100000,
0x00000000, 0x00120000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x06060000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x01100000,
0x00000000, 0x01100000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x040A0000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x07040000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x040A0000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00120000, 0x00000000, 0x00120000,
0x00000000, 0x00000000, 0x00000000, 
};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_169c(void) { fzgx_pool_sink_f32(0.5f); }
#pragma section code_type ".text"
const u32 fzgx_pool_table_16a0[3] = {
0x3C23D70A, 0x3CA3D70A, 0xBF800000, 
};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_16ac(void) { fzgx_pool_sink_f32(640.0f); }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_16b0(void) { fzgx_pool_sink_f32(480.0f); }
#pragma section code_type ".text"
const u32 fzgx_pool_table_16b4[15] = {
0x80808000, 0xFFFFFF00, 0xFFFF0000, 0xFFFFFF00,  /* fzgx-allow: A1 retail pool bytes */
0xFFFF0000, 0xFF000000, 0xFF000000, 0xFFFFFF00,
0x00000000, 0x43A00000, 0x43160000, 0x41400000,
0x40000000, 0x3DCCCCCD, 0x00000000, 
};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_16f0(void) { fzgx_pool_sink_f64(0.0); }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_16f8(void) { fzgx_pool_sink_f32(13.0f); }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_16fc(void) { fzgx_pool_sink_f32(26.0f); }
#pragma section code_type ".text"

typedef struct { u8 r, g, b, a; } Color;
typedef struct {
    u32 type;
    f32 x, y, z;
    u8 pad10[0x1c];
    f32 alpha;
    u32 mode;
    u32 unk34;
    Color color;
    u8 tail[0x1c];
} Draw;
extern const Draw lbl_1_rodata_26F8;
extern int __abs(int);
extern void fn_1_50164(f32, f32, f32, f32, void *);
void fn_1_4D2AC(Color arg0, f32 arg1, f32 arg2) {
    f32 left, bottom, top, right;
    s32 x, y;
    f32 alpha;
    u32 a;
    s32 width, height;
    Draw draw;
    if ((s32)lbl_1_bss_4BA30.unk_0 != 0) {
        lbl_1_bss_4BA30.unk_0 = 0;
        if (640.0f == (left = lbl_1_bss_4BA30.unk_4) && 0.0 == lbl_1_bss_4BA30.unk_8 &&
            480.0f == lbl_1_bss_4BA30.unk_C && 0.0 == lbl_1_bss_4BA30.unk_10) return;
        top = lbl_1_bss_4BA30.unk_C;
        bottom = lbl_1_bss_4BA30.unk_10;
        if (top > bottom) return;
        right = lbl_1_bss_4BA30.unk_8;
        if (left > right) return;
        width = __abs((right-left));
        height = __abs((top-bottom));
        draw = lbl_1_rodata_26F8;
        x = ((left+right)/2.0f);
        y = ((top+bottom)/2.0f);
        a = arg0.a;
        draw.type = 2;
        draw.x = x;
        draw.y = y;
        draw.z = arg1;
        alpha = a / 255.0f;
        draw.mode = 10;
        draw.color = arg0;
        draw.alpha = alpha;
        fn_1_50164(width+arg2, height+arg2, 13.0f, 26.0f, &draw);
    }
}
/* fzgx:end fn_1_4D2AC */

/* fzgx:begin fn_1_4D494 */
void fn_1_4D494(void) {
    Obj_1_bss_4BA44 *bss = &lbl_1_bss_4BA44;
    f32 *rodata = (f32 *)lbl_1_rodata_FD0;
    bss->unk_0 = 1;
    bss->unk_4 = rodata[0x16ac / 4];
    bss->unk_8 = rodata[0xf0 / 4];
    bss->unk_C = rodata[0x16b0 / 4];
    bss->unk_10 = rodata[0xf0 / 4];
}
/* fzgx:end fn_1_4D494 */

/* fzgx:begin fn_1_4D4C8 */
#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.0f;
}
static const unsigned long fzgx_pool_table3[1] = {0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
}
static const unsigned long fzgx_pool_table5[5] = {0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5999999046325684f;
    s = 0.0f;
}
static const unsigned long fzgx_pool_table7[6] = {0x40266666, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.600000023841858f;
}
static const unsigned long fzgx_pool_table9[1] = {0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.5999999046325684f;
}
static const unsigned long fzgx_pool_table11[5] = {0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.399999976158142f;
    s = 3.700000047683716f;
    s = 1.2999999523162842f;
}
static const unsigned long fzgx_pool_table13[3] = {0x00000000, 0x3FCCCCCD, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.8999999761581421f;
    s = -0.800000011920929f;
}
static const unsigned long fzgx_pool_table15[14] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const unsigned long *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.75f;
}
static const unsigned long fzgx_pool_table17[1] = {0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const unsigned long *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 255.0f;
}
static const unsigned long fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const unsigned long *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table21[2] = {0xFFFFFFFF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const unsigned long *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05000000074505806f;
}
static const unsigned long fzgx_pool_table23[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const unsigned long *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table25[1371] = {0x00000000, 0x000D0000, 0x00000000, 0x070D0000, 0x00000000, 0x010B0000, 0x00000000, 0x010C0000, 0x00000000, 0x02070000, 0x00000000, 0x02070000, 0x00000000, 0x08090000, 0x00000000, 0x08090000, 0x00000000, 0x10080000, 0x00000000, 0x01080000, 0x00000000, 0x0D0B0000, 0x00000000, 0x010B0000, 0x00000000, 0x010A0000, 0x00000000, 0x0C0A0000, 0x00000000, 0x060E0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x070B0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x09070000, 0x00000000, 0x060A0000, 0x00000000, 0x060F0000, 0x00000000, 0x09070000, 0x00000000, 0x03140000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x050F0000, 0x00000000, 0x04100000, 0x00000000, 0x070B0000, 0x00000000, 0x050E0000, 0x00000000, 0x070B0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x02150000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04110000, 0x00000000, 0x05100000, 0x00000000, 0x04110000, 0x00000000, 0x04120000, 0x00000000, 0x050F0000, 0x00000000, 0x050F0000, 0x00000000, 0x04110000, 0x00000000, 0x04110000, 0x00000000, 0x09070000, 0x00000000, 0x050C0000, 0x00000000, 0x05110000, 0x00000000, 0x060E0000, 0x00000000, 0x02140000, 0x00000000, 0x04110000, 0x00000000, 0x04120000, 0x00000000, 0x05100000, 0x00000000, 0x04120000, 0x00000000, 0x05100000, 0x00000000, 0x060F0000, 0x00000000, 0x060E0000, 0x00000000, 0x04110000, 0x00000000, 0x05110000, 0x00000000, 0x01170000, 0x00000000, 0x03120000, 0x00000000, 0x04110000, 0x00000000, 0x04100000, 0x00000000, 0x00000000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00090000, 0x00000000, 0x000D0000, 0x00000000, 0x00000000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00160000, 0x00000000, 0x00090000, 0x00000000, 0x000D0000, 0x00000000, 0x00000000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x04080000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x020C0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x010E0000, 0x00000000, 0x020C0000, 0x00000000, 0x00000000, 0x00000000, 0x00190000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00120000, 0x00000000, 0x00110000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x000B0000, 0x00000000, 0x000F0000, 0x00000000, 0x00180000, 0x00000000, 0x00110000, 0x00000000, 0x001D0000, 0x00000000, 0x00150000, 0x00000000, 0x00170000, 0x00000000, 0x00150000, 0x00000000, 0x00170000, 0x00000000, 0x00160000, 0x00000000, 0x00180000, 0x00000000, 0x00170000, 0x00000000, 0x00170000, 0x00000000, 0x00190000, 0x00000000, 0x001F0000, 0x00000000, 0x00180000, 0x00000000, 0x00170000, 0x00000000, 0x00130000, 0x00000000, 0x00000000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x000B0000, 0x00000000, 0x00080000, 0x00000000, 0x000D0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x000F0000, 0x00000000, 0x000B0000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00000000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00100000, 0x00000000, 0x00080000, 0x00000000, 0x000E0000, 0x00000000, 0x00000000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x00060000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000F0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000F0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x000D0000, 0x00000000, 0x00050000, 0x00000000, 0x00000000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00050000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x000B0000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00090000, 0x00000000, 0x00000000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0x00190000, 0x00000000, 0xFD070000, 0x00000000, 0xFD050000, 0x00000000, 0xFD090000, 0x00000000, 0x00000000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0x00110000, 0x00000000, 0xFE050000, 0x00000000, 0xFE030000, 0x00000000, 0xFE060000, 0x00000000, 0x00000000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0x001A0000, 0x00000000, 0xFD0C0000, 0x00000000, 0xFD080000, 0x00000000, 0xFD0A0000, 0x00000000, 0x00000000, 0x00000000, 0x000C0000, 0x00000000, 0x00020000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000A0000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00040000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x00020000, 0x00000000, 0x00060000, 0x00000000, 0x00020000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00020000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00040000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x000C0000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x000A0000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x000C0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00020000, 0x00000000, 0x00040000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x000A0000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00060000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00080000, 0x00000000, 0x00060000, 0x00000000, 0x00000000, 0x00000000, 0x000C0000, 0x00000000, 0x0A040000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x04100000, 0x00000000, 0x00060000, 0x00000000, 0x08080000, 0x00000000, 0x08080000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x09060000, 0x00000000, 0x050E0000, 0x00000000, 0x0A040000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x070A0000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x0A040000, 0x00000000, 0x0A040000, 0x00000000, 0x09060000, 0x00000000, 0x09060000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x04100000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x070A0000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x02140000, 0x00000000, 0x02140000, 0x00000000, 0x01160000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x01160000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x00180000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x050E0000, 0x00000000, 0x03120000, 0x00000000, 0x050E0000, 0x00000000, 0x050E0000, 0x00000000, 0x04100000, 0x00000000, 0x02140000, 0x00000000, 0x08080000, 0x00000000, 0x070A0000, 0x00000000, 0x03120000, 0x00000000, 0x08080000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x04100000, 0x00000000, 0x03120000, 0x00000000, 0x03120000, 0x00000000, 0x04100000, 0x00000000, 0x060E0000, 0x00000000, 0x060C0000, 0x00000000, 0x02140000, 0x00000000, 0x03120000, 0x00000000, 0x01160000, 0x00000000, 0x02140000, 0x00000000, 0x02140000, 0x00000000, 0x050E0000, 0x00000000, 0x00000000, 0x00000000, 0x00120000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x010F0000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x000E0000, 0x00000000, 0x05080000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x020E0000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00000000, 0x00000000, 0x00120000, 0x00000000, 0x07040000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x010F0000, 0x00000000, 0x06080000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x00120000, 0x00000000, 0x030C0000, 0x00000000, 0x000E0000, 0x00000000, 0x05080000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x07040000, 0x00000000, 0x07040000, 0x00000000, 0x06060000, 0x00000000, 0x06060000, 0x00000000, 0x020E0000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x06060000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x01100000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x07040000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x040A0000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00120000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const unsigned long *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 0.009999999776482582f;
    s = 0.019999999552965164f;
}
static const unsigned long fzgx_pool_table27[1] = {0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const unsigned long *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 640.0f;
    s = 480.0f;
}
static const unsigned long fzgx_pool_table29[9] = {0x80808000, 0xFFFFFF00, 0xFFFF0000, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0xFF000000, 0xFFFFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const unsigned long *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 150.0f;
    s = 12.0f;
    s = 2.0f;
    s = 0.10000000149011612f;
}
static const unsigned long fzgx_pool_table31[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const unsigned long *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    s = 13.0f;
    s = 26.0f;
    s = 0.1882352977991104f;
    s = 0.800000011920929f;
    s = 4.0f;
    s = 8.0f;
    s = 6.0f;
    s = 16.0f;
}
#pragma section code_type ".text"

typedef struct {
    u8 r, g, b, a;
} Color4_4D4C8;

typedef struct {
    s32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x1C];
    f32 unk_2C;
    s32 unk_30;
    u8 pad_34[0x4];
    Color4_4D4C8 unk_38;
    u8 pad_3C[0x1C];
} Sprite_4D4C8;

extern void fn_1_50164(f32, f32, f32, f32, Sprite_4D4C8 *);

void fn_1_4D4C8(Color4_4D4C8 *color, f32 z, f32 ofs) {
    Sprite_4D4C8 s;
    Color4_4D4C8 c;
    s32 w;
    s32 h;
    f32 y;
    f32 x;
    f32 left;
    f32 right;
    f32 bottom;
    f32 top;

    if ((s32)lbl_1_bss_4BA44.unk_0 == 0) {
        return;
    }
    lbl_1_bss_4BA44.unk_0 = 0;
    if (640.0f == lbl_1_bss_4BA44.unk_4 && 0.0 == lbl_1_bss_4BA44.unk_8 &&
        480.0f == lbl_1_bss_4BA44.unk_C && 0.0 == lbl_1_bss_4BA44.unk_10) {
        return;
    }
    left = lbl_1_bss_4BA44.unk_4;
    top = lbl_1_bss_4BA44.unk_C;
    bottom = lbl_1_bss_4BA44.unk_10;
    if (top > bottom) {
        return;
    }
    right = lbl_1_bss_4BA44.unk_8;
    if (left > right) {
        return;
    }
    c = *color;
    w = __abs((right - left));
    h = __abs((top - bottom));
    s = (*(Sprite_4D4C8 *)&lbl_1_rodata_26F8);
    s.unk_C = z;
    s.unk_0 = 18;
    s.unk_2C = 0.1882353f;
    s.unk_30 = 10;
    s.unk_38 = c;
    s.unk_4 = (s32)((left + right) / 2.0f);
    s.unk_8 = (s32)((top + bottom) / 2.0f);
    x = w + ofs;
    y = h + ofs;
    fn_1_50164(x, y, 2.0f, 2.0f, &s);
    s.unk_2C *= 0.8f;
    fn_1_50164(4.0f + x, 2.0f + y, 2.0f, 2.0f, &s);
    s.unk_2C *= 0.8f;
    fn_1_50164(8.0f + x, 4.0f + y, 2.0f, 2.0f, &s);
    s.unk_2C *= 0.8f;
    fn_1_50164(12.0f + x, 6.0f + y, 2.0f, 2.0f, &s);
    s.unk_2C *= 0.8f;
    fn_1_50164(16.0f + x, 8.0f + y, 2.0f, 2.0f, &s);
}
/* fzgx:end fn_1_4D4C8 */

/* fzgx:begin fn_1_4D784 noprologue */
#include "types.h"
#include "runtime/va_list.h"

extern u8 lbl_1_data_1A3B8[];
extern u8 lbl_8015B100[];
extern f32 fn_1_4B1D4(s32 mode, u8 *text);
extern s32 fn_8008077C(u8 *dst, const char *fmt, __va_list args);
extern s32 strncmp(const u8 *, const u8 *, u32);
extern u8 *strcpy(u8 *, const u8 *);
extern u32 strlen(const u8 *);

/* both characters are alphanumeric or one of - " ' ( ) */
static inline s32 fn_1_4D784_isJoined(u8 a, u8 b) {
    if (((lbl_8015B100[a] & 0xd0) || a == '-' || a == '"' || a == '\'' || a == '(' || a == ')') &&
        ((lbl_8015B100[b] & 0xd0) || b == '-' || b == '"' || b == '\'' || b == '(' || b == ')')) {
        return 1;
    }
    return 0;
}

static inline s32 fn_1_4D784_isAlnumPair(s32 a, s32 b) {
    if ((lbl_8015B100[a] & 0xd0) && (lbl_8015B100[b] & 0xd0)) {
        return 1;
    }
    return 0;
}

u8 *fn_1_4D784(s32 wordWrap, s32 hyphenate, s32 kinsoku, s32 width, u8 *out, const char *fmt, ...) {
    __va_list args;
    u8 line[0x200];
    u8 text[0x400];
    s16 i;
    u8 *q;
    s16 start;
    u8 *p;
    s16 len;
    s32 hyphen;
    s32 flag;
    u8 c;
    s16 count;
    u8 *strs = lbl_1_data_1A3B8;

    __builtin_va_info(&args);
    fn_8008077C(text, fmt, args);
    q = line;
    i = 0;
    while ((c = *(p = text + i)) != 0) {
        start = i;
        hyphen = 0;
        flag = 0;
        if (c < 0x80) {
            if (kinsoku == 1) {
                if (strncmp(p, strs + 0x1eb4, 1) == 0 || strncmp(p, strs + 0x1eac, 1) == 0) {
                    *q++ = text[i++];
                    flag = 1;
                }
            }
            len = 1;
            *q++ = text[i];
            if (hyphenate == 1 && i > 0) {
                if (fn_1_4D784_isAlnumPair(text[i - 1], text[i])) {
                    hyphen = 1;
                }
            }
        } else {
            if (kinsoku == 1) {
                if (strncmp(p, strs + 0x1d08, 2) == 0 || strncmp(p, strs + 0x1d04, 2) == 0 ||
                    strncmp(p, strs + 0x212c, 2) == 0) {
                    q[0] = text[i++];
                    flag = 1;
                    q[1] = text[i++];
                    q += 2;
                }
            }
            q[0] = text[i++];
            len = 2;
            q[1] = text[i];
            q += 2;
        }
        *q = 0;
        if (fn_1_4B1D4(1, line) > (s16)width) {
            q -= len;
            count = 0;
            if (wordWrap != 0) {
                while (fn_1_4D784_isJoined(q[-1], q[0])) {
                    q--;
                    count++;
                }
            }
            if (hyphen == 1) {
                *q++ = '-';
            }
            q[0] = '\n';
            q[1] = 0;
            strcpy(out, line);
            out += strlen(line);
            line[0] = 0;
            q = line;
            if (text[start] < 0x80) {
                while (count-- != 0) {
                    *q++ = text[start - count - 1];
                }
                if (flag == 1) {
                    start++;
                }
                c = text[start];
                if (!(lbl_8015B100[c] & 6)) {
                    *q++ = c;
                    start++;
                }
            } else {
                if (flag == 1) {
                    start += 2;
                }
                q[0] = text[start++];
                q[1] = text[start++];
                q += 2;
            }
            if (text[start] == 0) {
                *q = 0;
                break;
            }
        }
        i++;
    }
    strcpy(out, line);
    out += strlen(line);
    out[1] = 0;
    return out;
}
/* fzgx:end fn_1_4D784 */

/* fzgx:begin fn_1_4DC20 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"

typedef struct FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} FontParams;

typedef struct fn_1_4EB74_FontObject {
    u32 unk_0;
    u8 pad_4[0x2c];
    u32 unk_30;
} fn_1_4EB74_FontObject;

typedef struct fn_1_54668_node {
    struct fn_1_54668_node *next;
    void *data;
} fn_1_54668_node;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct fn_1_547F8_node {
    struct fn_1_547F8_node *next;
    void (*callback)(struct fn_1_547F8_node *);
} fn_1_547F8_node;

typedef struct fn_1_563E4_FontState {
    u8 pad_00[8];
    f32 scale;
    u8 pad_0C[6];
    u8 enabled;
    u8 color;
    u32 value;
    f32 x;
    f32 y;
    u8 pad_20[4];
    u32 state;
} fn_1_563E4_FontState;

typedef struct State {
    FontDrawPacket *current;
    s32 warned;
    u8 unk_8[0x2028];
    s32 override_enabled, override_value;
    u32 texture[8];
} State;

typedef struct Config {
    u32 capacity;
    FontDrawPacket *packets;
    u8 unk_8[0x44];
    char warning[1];
} Config;

typedef struct ImageInfo {
    u8 unk_0[8];
    u16 width, height;
    u32 unk_C;
} ImageInfo;

typedef struct Images {
    u32 unk_0;
    ImageInfo *info;
    u32 unk_8;
    u32 (*textures)[8];
} Images;

typedef struct Resource {
    s32 loaded;
    u8 unk_4[0x1c];
    Images *images;
    u32 unk_24;
} Resource;

struct fn_1_530C8_lbl_1_rodata_282C {
    f32 unk_0;
};

struct FzgxCopy_88 { u32 words[22]; };
extern void *lbl_801A6D00;
extern void fn_1_A71CC(void);
extern void fn_800724C8(void);
extern void lbl_8006D758(void);
extern void fn_80072558(void);
extern void fn_1_A722C(void);
extern void fn_8007245C(u32 value);
extern void fn_80074788(u32 arg0);
extern void fn_80074660(u32 arg0);
extern void fn_80073678(u32 arg0);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800720B0(int);
extern void fn_80072864(u32 arg0);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern f32 fn_1_519AC(u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void fn_80073778(void *obj, s32 index);
extern int fn_1_159588(int arg);
extern void OSReport(const char *format, ...);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern u8 *lbl_801A66CC;
extern void lbl_8006DB74(void *value);
extern void fn_1_4E500(void);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(FontParams *arg);
extern const f32 lbl_1_rodata_2750;
extern s32 fn_1_4EC74(FontParams *);
extern s32 fn_1_4EB74(fn_1_4EB74_FontObject *self);
extern f64 lbl_1_rodata_2778[2];
extern u16 fn_1_48690(u32 unused);
extern u16 fn_1_486C4(u32 value);
extern void fn_80038F10(f32* out);
extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern const f32 lbl_1_rodata_2770;
extern const f32 lbl_1_rodata_276C;
extern const f32 lbl_1_rodata_2754;
extern void lbl_8006D7F4(f32 arg0, f32 arg1, f32 arg2);
extern void lbl_8006E15C(f32 arg0, f32 arg1, f32 arg2);
extern void mathutil_mtxA_rotate_z(s16 arg0);
extern void lbl_8006DD7C(void);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern f32 lbl_8006D188(s16);
extern struct fn_1_530C8_lbl_1_rodata_282C lbl_1_rodata_282C;
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern s32 fn_1_3F164(void);
extern f32 lbl_1_rodata_26F8[22];
extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_1_50190(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
extern void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2);
extern u32 lbl_801A66B4;
extern s32 fn_1_A5DC4();
extern f32 lbl_1_rodata_2788[6];
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern f32 fn_1_51B84(f32 value);
extern f32 fn_1_51BFC(f32 value);
extern const f64 lbl_1_rodata_2758;

typedef struct {
    u32 words[23];
} FontStateCopy;

void fn_1_4DC20(void) {
    *(FontStateCopy *)&lbl_1_bss_4BB40 =
        *(FontStateCopy *)&lbl_1_bss_4B9CC;
    lbl_1_bss_4BB3C = 1;
}
/* fzgx:end fn_1_4DC20 */

/* fzgx:begin fn_1_4DC6C noprologue */
void fn_1_4DC6C(void) {
    lbl_1_bss_4B9CC = *(Obj_1_bss_4B9CC *)&lbl_1_bss_4BB40;
    lbl_1_bss_4BB3C = 0;
}
/* fzgx:end fn_1_4DC6C */

/* fzgx:begin fn_1_4DCB8 noprologue */
// Replaces the stored font state value and returns its previous value.
u32 fn_1_4DCB8(u32 value) {
    u32 old_value = lbl_1_bss_4B9CC.unk_58;
    lbl_1_bss_4B9CC.unk_58 = value;
    return old_value;
}
/* fzgx:end fn_1_4DCB8 */
