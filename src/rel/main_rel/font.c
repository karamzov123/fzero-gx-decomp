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
extern u32 fn_1_54298(void);
extern u32 fn_1_542A8(void);
extern f32 fn_1_542B8(void);
extern f32 fn_1_4B1D4(s32 mode, s32 value);
extern const f64 lbl_1_rodata_10F8;
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_FD0[];
extern u8 *lbl_801A66CC;
extern const f32 lbl_1_rodata_2870;
extern const f64 lbl_1_rodata_2878;
extern void lbl_8006E1B0();
extern f32 lbl_8006D0B4(f32 value);
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_55C48(void);
extern u16 fn_1_7BE94(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_1_56530(void);
extern void lbl_8006DB74(void *value);
extern void lbl_8006DD14(void *value, void *object);
extern void fn_1_4E500(void);
extern void fn_1_48D80(void *value);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(FontParams *arg);
extern s32 fn_1_4B16C(s32 value);
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
extern u32 fn_1_54320(void);
extern void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse);
extern void fn_1_547F8(fn_1_547F8_node *node);
extern u32 fn_1_5448C();
extern void fn_1_563E4(fn_1_563E4_FontState *font);
extern void fn_80074B40(u8 *arg0);
extern void fn_80077B04(f32 value);
extern void fn_80071ED4(u8 value, f32 x, f32 y);
extern void fn_80072014(u32 *value);
extern void fn_80074C74(u8 *arg0);
extern void fn_80077BBC(s32 arg0);
extern void fn_80037D40(u8 a, u8 b);
extern u32 fn_80074A7C();
extern u32 fn_80077BAC();
extern const f32 lbl_1_rodata_10D4;
extern void fn_1_4955C(f32 value1, f32 value2);
extern f32 lbl_1_rodata_10C0[5];
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern f32 lbl_1_rodata_26B8[16];
extern void fn_1_4D10C(void *data, f32 scale, f32 value);
extern void fn_1_4D2AC(void *data, f32 scale, f32 value);
extern s32 fn_1_3F164(void);
extern f32 lbl_1_rodata_26F8[22];
extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_1_50190(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
extern void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2);
extern void *fn_1_541A8(void *arg, s32 column);
extern u32 lbl_801A66B4;
extern void fn_1_9FA18(void);
extern void fn_1_58248(void);
extern void fn_1_54848(void);
extern void fn_800794F0(u8 *data, void *value, s32 size);
extern s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2);
extern void fn_1_55210(void *value);
extern const f32 lbl_1_rodata_28A8;
extern void fn_1_557C4(void *value);
extern void fn_1_556B8(void *value);
extern void fn_80077E7C(void *value);
extern void fn_80077F8C(void *value);
extern void fn_80074CF4();
extern void fn_800749B0(s32 arg0, void *arg1);
extern const f32 lbl_1_rodata_28AC;
extern u8 lbl_1_bss_6C7DC[100];
extern u8 *fn_1_565E8(void);
extern void fn_1_45730(void);
extern void fn_1_45B2C(void);
extern void fn_1_458A0(void);
extern void fn_1_45850(void);
extern void fn_1_565F4(void);
extern void fn_80070D60(void *);
extern s32 fn_1_A5DC4();
extern f32 lbl_1_rodata_2788[6];
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern f32 fn_1_51B84(f32 value);
extern f32 fn_1_51BFC(f32 value);
extern const f64 lbl_1_rodata_2758;
extern void lbl_8006D784(void *arg);
extern void fn_1_55D6C(void);

/* fzgx:begin fn_1_48C28 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern u8 lbl_1_bss_3F60C[];
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
        int id = *(s16 *)((u8 *)entry->unk_30 + offset);
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
                id = *(s16 *)((u8 *)entry->unk_30 + offset);
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
    register f32 m2;
    register f32 m1;
    register f32 m0;
    f64 half;
    register f32 offset;
    u32 screenH;

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
    result1 = entry->unk_34 * (value1 * (f32)entry->unk_4);
    result2 = entry->unk_34 * (value2 * (f32)entry->unk_5);
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
            result |= 1 << shift;
            break;
        case '1':
            result |= 2 << shift;
            break;
        case '2':
            result |= 3 << shift;
            break;
        case '3':
            result |= 4 << shift;
            break;
        case '4':
            result |= 5 << shift;
            break;
        case '5':
            result |= 6 << shift;
            break;
        case '6':
            result |= 7 << shift;
            break;
        case '7':
            result |= 8 << shift;
            break;
        case '8':
            result |= 9 << shift;
            break;
        case '9':
            result |= 10 << shift;
            break;
        case 'A':
        case 'a':
            result |= 11 << shift;
            break;
        case 'B':
        case 'b':
            result |= 12 << shift;
            break;
        case 'C':
        case 'c':
            result |= 13 << shift;
            break;
        case 'D':
        case 'd':
            result |= 14 << shift;
            break;
        case 'E':
        case 'e':
            result |= 15 << shift;
            break;
        case 'F':
        case 'f':
            break;
        default:
            break;
        }
        shift -= 4;
    }
    return result;
}
/* fzgx:end fn_1_499BC */

/* fzgx:begin fn_1_49B70 noprologue */
#include "types.h"

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
        mode = (s32)(((0x62 - c1) | (c1 - 0x62)) >> 31);
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
            arg1->unk_28 = (f32)flags / lbl_1_rodata_10D8;
        }
        break;
    }
    return ret;
}
/* fzgx:end fn_1_49B70 */

/* fzgx:begin fn_1_49F08 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"

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
u32 fn_1_49F08(u16 c, Obj_1_bss_4B9CC *state, Obj_1_data_1AEA8 *__restrict font) {
    const FontCharEntry *entry;
    u32 adv;
    s32 found;
    const u8 *str;
    u8 b;

    adv = font->unk_4;
    if (c == ' ') {
        return (f32)adv * state->unk_24;
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
            if ((state->align & 4) && (f32)state->width > width) {
                spacing = ((f32)state->width - width) / (f32)(count - 1);
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
                    state->y += state->line_spacing + (f32)font->height * state->scale_y;
                    continue;
                }
                if ((u16)c == ' ') {
                    state->x += state->spacing + (f32)(s32)(adv & 0xFFFF) * state->scale_x;
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
                    state->x += state->spacing + (f32)(s32)(adv & 0xFFFF) * state->scale_x;
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
                state->x += state->spacing + (f32)(s32)(adv & 0xFFFF) * state->scale_x;
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
            offset = (f32)(s16)(adv >> 16) * state->scale_x;
            advance = (f32)(s32)(adv & 0xFFFF);
            pkt.x -= offset;
            x = pkt.x + 0.5f * (state->scale_x * (f32)(s32)(adv & 0xFFFF));
            u = font->cell_w * (f32)col;
            v = font->cell_h * (f32)row;
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
                pkt.x += (f32)state->shadow_x;
                pkt.y += (f32)state->shadow_y;
                pkt.z += 0.02f;
                pkt.alpha = state->alpha * state->shadow_alpha;
                pkt.color = fzgx_shadow_color;
                fn_1_4AC20(&pkt);
                pkt.x -= (f32)state->shadow_x;
                pkt.y -= (f32)state->shadow_y;
                pkt.z -= 0.02f;
                pkt.alpha = state->alpha;
                pkt.color = state->color;
            }
            fn_1_4AC20(&pkt);
        }
        lastX = x;
        lastY = y;
        state->x += spacing + (state->spacing + (f32)(s32)(adv & 0xFFFF) * state->scale_x);
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
    int x_max;
    int x_ok;
    int y_max;
    int y_ok;

    if (lbl_1_bss_4B9CC.unk_45 != 0) {
        local.x = fn_1_519FC(local.x);
        local.y = fn_1_51AC0(local.y);
        local.z = fn_1_51B84(local.z);
        local.w = fn_1_51BFC(local.w);
    }

    if (lbl_1_bss_4B9CC.unk_47 != 0) {
        x_ok = (local.x > (f32)(lbl_1_bss_4B9CC.unk_48 + lbl_1_bss_4B9CC.unk_4C))
                   ? 0
                   : ((local.x < (f32)lbl_1_bss_4B9CC.unk_48) ? 0 : 1);
        if (x_ok == 0 ||
            (y_ok = (local.y > (f32)(lbl_1_bss_4B9CC.unk_4A + lbl_1_bss_4B9CC.unk_4E))
                        ? 0
                        : ((local.y < (f32)lbl_1_bss_4B9CC.unk_4A) ? 0 : 1)) == 0) {
            return;
        }
    }

    if (lbl_1_bss_4B9CC.unk_44 != 0) {
        fn_1_4F734( (FontDrawPacket *)(void *)(&local));
    } else if ((local.flag & 0x400000) != 0) {
        if (lbl_1_bss_4B9CC.unk_46 == 0) {
            fn_1_4E500();
        }
        fn_1_48D80(&local);
        if (lbl_1_bss_4B9CC.unk_46 == 0) {
            fn_1_4E6F4();
        }
    } else {
        fn_1_4E724( (FontParams *)(void *)(&local));
    }
}
/* fzgx:end fn_1_4AC20 */

/* fzgx:begin fn_1_4AE0C */
void fn_1_4AE0C(const char* format, ...) {
    char buffer[512];
    __va_list args;
    __builtin_va_info(&args);
    fn_8008077C( (u32)(char*)(buffer), (u32)(const char*)(format), (u32)(args));
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
extern void fn_1_47AD4(Obj_1_data_FCD4 *obj, u8 value, int arg2, int arg3);
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






#pragma opt_pointer_analysis off
void fn_1_4AF10(u32 arg0) {
    u32 v0;
    v0 = (*(struct fn_1_4AF10_lbl_1_bss_3E058 *)&lbl_1_bss_3E058).unk_0;
    lbl_1_bss_3E05C = (0.0f);
    (*(struct fn_1_4AF10_lbl_1_bss_3E058 *)&lbl_1_bss_3E058).unk_0 = 1;
    fn_1_4A0D8((const char *)arg0);
    (*(struct fn_1_4AF10_lbl_1_bss_3E058 *)&lbl_1_bss_3E058).unk_0 = v0;
}
#pragma opt_pointer_analysis reset
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
    fn_8008077C( (u32)(char *)(buffer), (u32)(const char *)(format), (u32)(va_list *)(&args));

    lbl_1_bss_3E058 = 1;
    lbl_1_bss_3E05C = lbl_1_rodata_10C0[0];
    fn_1_4A0D8(buffer);
    lbl_1_bss_3E058 = previous;
}
/* fzgx:end fn_1_4AF64 */

/* fzgx:begin fn_1_4B040 */
void fn_1_4B040(s32 value) {
    fn_1_4B1D4(0, value);
}
/* fzgx:end fn_1_4B040 */

/* fzgx:begin fn_1_4B068 */
void fn_1_4B068(s32 value) {
    fn_1_4B1D4(1, value);
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
        (entry->unk_34 * (f32)(entry->unk_5 * fn_1_4B16C(value)));
    b = lbl_1_bss_4B9CC.unk_40 * (f32)count;
    return a + b;
}
/* fzgx:end fn_1_4B090 */

/* fzgx:begin fn_1_4B16C */
s32 fn_1_4B16C(s32 value) {
    return (s32)fn_1_4B1D4(2, value);
}
/* fzgx:end fn_1_4B16C */

/* fzgx:begin fn_1_4B1A0 */
s32 fn_1_4B1A0(s32 value) {
    return (s32)fn_1_4B1D4(3, value);
}
/* fzgx:end fn_1_4B1A0 */

/* fzgx:begin fn_1_4B1D4 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

typedef struct FontEntry_4B1D4 {
    s32 unk_0;
    u8 pad_4[0x30];
    f32 unk_34;
} FontEntry_4B1D4;

extern s32 lbl_1_bss_4BA28[2];

f32 fn_1_4B1D4(s32 mode, u8 *str) {
    struct {
        Obj_1_bss_4B9CC *value;
    } p;
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
    p.value = &lbl_1_bss_4B9CC;
    maxWidth = 0.0f;
    width = -p.value->unk_3C;
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
                            width = -p.value->unk_3C;
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
                        width = -p.value->unk_3C;
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
            width += p.value->unk_3C + (f32)(state->unk_1C * ((f32)adv * font->unk_34));
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
        return (f32)lines;
    case 3:
        return (f32)count;
    case 4:
        return (f32)maxCount;
    default:
        return -1.0f;
    }
}
/* fzgx:end fn_1_4B1D4 */

/* fzgx:begin fn_1_4B83C */
void fn_1_4B83C(void *arg0, void *arg1, u32 arg2, const char *arg3) {
    u32 length;
    s32 converted;

    length = (u32)strlen(arg3);
    converted = (s32)fn_1_4B1D4(3, arg2 + length);
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

/* fzgx:begin fn_1_4B8DC noprologue */
#include "rel/main_rel/font.h"

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

/* fzgx:begin fn_1_4BA24 noprologue */
#include "rel/main_rel/font.h"

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

#pragma opt_cse off

#pragma opt_common_subs off
#pragma opt_dead_assignments off
static inline Entry *fn_1_4BA24_array_read(Entry *array) { return array; }
#pragma opt_strength_reduction off
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
#pragma opt_strength_reduction reset

#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_4BA24 */

/* fzgx:begin fn_1_4BB5C noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

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
        fn_1_47F74(((u32)prev->unk_0 >> 8) & 0xFFFF);
    }
}
/* fzgx:end fn_1_4BB5C */

/* fzgx:begin fn_1_4BD48 */
// fn_1_4BD48: empty in retail (single blr).
void fn_1_4BD48(void) {
}
/* fzgx:end fn_1_4BD48 */

/* fzgx:begin fn_1_4BD4C noprologue */
#include "rel/main_rel/font.h"

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
    s8 *fzgx_value;
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

    prev_unk_0 = *(s8 volatile *)&(sp30->unk_0) /* Retail reloads this field. */;
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
            fn_1_48140(((u32)((FontElement *)&lbl_1_data_1AEA8)[sp30->unk_1].unk_0 >> 8) & 0xFFFF);
            fn_1_47F74(((u32)elem->unk_0 >> 8) & 0xFFFF);
        }
        sp30->unk_1 = sp30->unk_0;
    }

    if (elem->unk_0 == -1) {
        page_size = cols * rows;
        prev_unk_4 = sp30->unk_4;
        max_page = ((s32 *)&lbl_1_bss_40BBC)[sp30->unk_0] / page_size;
        if (((p_d58[8] >> 2) & 1) != 0) {
            if ((s8)++(*(s8 volatile *)&(sp30->unk_4)) /* Retail reloads this field. */ > max_page) {
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
        x_ok = (local.x > (f32)(lbl_1_bss_4B9CC.unk_48 + lbl_1_bss_4B9CC.unk_4C))
                   ? 0
                   : ((local.x < (f32)lbl_1_bss_4B9CC.unk_48) ? 0 : 1);
        if (x_ok == 0 ||
            (y_ok = (local.y > (f32)(lbl_1_bss_4B9CC.unk_4A + lbl_1_bss_4B9CC.unk_4E))
                        ? 0
                        : ((local.y < (f32)lbl_1_bss_4B9CC.unk_4A) ? 0 : 1)) == 0) {
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
    u = font->cell_w * (f32)col;
    v = font->cell_h * (f32)row;
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
    lbl_1_bss_4B9CC.home_x = lbl_1_bss_4B9CC.x = 320.0f - font->scale * (f32)(font->width * cols) / 2.0f;
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
        font_set_pos(12.0f, (f32)(font->height * 2 + 162));
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
        font_set_pos(12.0f, (f32)(font->height * 2 + 162));
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
    first = fn_1_4B1D4(1, (s32)(Obj_1_bss_4B9CC *)(obj));
    count = (s32)fn_1_4B1D4(3, (s32)(Obj_1_bss_4B9CC *)(obj));
    count = count - 1;
    adjusted = lbl_1_bss_4B9CC.unk_3C * (f32)count;
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


#pragma opt_common_subs off
void fn_1_4CF3C(const char *format, f32 x, ...) {
    Obj_1_bss_4B9CC *p_lbl_1_bss_4B9CC;
    char buffer[512];
    Sig_parse_format_va_list list;
    f32 saved;
    f32 first;
    f32 adjusted;
    s32 count;

    __builtin_va_info(&list);

    fn_8008077C((u32)buffer, (u32)(const char *)(format), (u32)((Sig_parse_format_va_list *)&list));

    p_lbl_1_bss_4B9CC = &lbl_1_bss_4B9CC;
    saved = p_lbl_1_bss_4B9CC->unk_1C;
    first = fn_1_4B1D4(1, (u32)buffer);
    count = (s32)fn_1_4B1D4(3, (u32)buffer);
    count = count - 1;
    adjusted = p_lbl_1_bss_4B9CC->unk_3C * (f32)count;
    adjusted = first + adjusted;
    if (adjusted > x) {
        p_lbl_1_bss_4B9CC->unk_1C = p_lbl_1_bss_4B9CC->unk_1C * (x / adjusted);
    }
    fn_1_4A0D8((const char *)buffer);
    p_lbl_1_bss_4B9CC->unk_1C = saved;
}
#pragma opt_common_subs reset
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

/* fzgx:begin fn_1_4D10C noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"
#include "rel/main_rel/font.h"

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
extern u32 fn_1_54298(void);
extern u32 fn_1_542A8(void);
extern f32 fn_1_542B8(void);
extern f32 fn_1_4B1D4(s32 mode, s32 value);
extern const f64 lbl_1_rodata_10F8;
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_FD0[];
extern u8 *lbl_801A66CC;
extern const f32 lbl_1_rodata_2870;
extern const f64 lbl_1_rodata_2878;
extern void lbl_8006E1B0();
extern f32 lbl_8006D0B4(f32 value);
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_55C48(void);
extern u16 fn_1_7BE94(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_1_56530(void);
extern void lbl_8006DB74(void *value);
extern void lbl_8006DD14(void *value, void *object);
extern void fn_1_4E500(void);
extern void fn_1_48D80(void *value);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(FontParams *arg);
extern s32 fn_1_4B16C(s32 value);
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
extern u32 fn_1_54320(void);
extern void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse);
extern void fn_1_547F8(fn_1_547F8_node *node);
extern u32 fn_1_5448C();
extern void fn_1_563E4(fn_1_563E4_FontState *font);
extern void fn_80074B40(u8 *arg0);
extern void fn_80077B04(f32 value);
extern void fn_80071ED4(u8 value, f32 x, f32 y);
extern void fn_80072014(u32 *value);
extern void fn_80074C74(u8 *arg0);
extern void fn_80077BBC(s32 arg0);
extern void fn_80037D40(u8 a, u8 b);
extern u32 fn_80074A7C();
extern u32 fn_80077BAC();
extern const f32 lbl_1_rodata_10D4;
extern void fn_1_4955C(f32 value1, f32 value2);
extern f32 lbl_1_rodata_10C0[5];
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern f32 lbl_1_rodata_26B8[16];
extern void fn_1_4D10C(void *data, f32 scale, f32 value);
extern void fn_1_4D2AC(void *data, f32 scale, f32 value);
extern s32 fn_1_3F164(void);
extern f32 lbl_1_rodata_26F8[22];
extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_1_50190(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
extern void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2);
extern void *fn_1_541A8(void *arg, s32 column);
extern u32 lbl_801A66B4;
extern void fn_1_9FA18(void);
extern void fn_1_58248(void);
extern void fn_1_54848(void);
extern void fn_800794F0(u8 *data, void *value, s32 size);
extern s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2);
extern void fn_1_55210(void *value);
extern const f32 lbl_1_rodata_28A8;
extern void fn_1_557C4(void *value);
extern void fn_1_556B8(void *value);
extern void fn_80077E7C(void *value);
extern void fn_80077F8C(void *value);
extern void fn_80074CF4();
extern void fn_800749B0(s32 arg0, void *arg1);
extern const f32 lbl_1_rodata_28AC;
extern u8 lbl_1_bss_6C7DC[100];
extern u8 *fn_1_565E8(void);
extern void fn_1_45730(void);
extern void fn_1_45B2C(void);
extern void fn_1_458A0(void);
extern void fn_1_45850(void);
extern void fn_1_565F4(void);
extern void fn_80070D60(void *);
extern s32 fn_1_A5DC4();
extern f32 lbl_1_rodata_2788[6];
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern f32 fn_1_51B84(f32 value);
extern f32 fn_1_51BFC(f32 value);
extern const f64 lbl_1_rodata_2758;
extern void lbl_8006D784(void *arg);
extern void fn_1_55D6C(void);


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
            w = __abs((s32)(right - left));
            h = __abs((s32)(top - bottom));
            cx = (s32)((left + right) / 2.0f);
            cy = (s32)((top + bottom) / 2.0f);
        }
        fn_1_53B14(a, (f32)cx, (f32)cy, (f32)w + p2, (f32)h + p2, p1);
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
        width = __abs((s32)(right-left));
        height = __abs((s32)(top-bottom));
        draw = lbl_1_rodata_26F8;
        x = (s32)((left+right)/2.0f);
        y = (s32)((top+bottom)/2.0f);
        a = arg0.a;
        draw.type = 2;
        draw.x = x;
        draw.y = y;
        draw.z = arg1;
        alpha = (f32)a / 255.0f;
        draw.mode = 10;
        draw.color = arg0;
        draw.alpha = alpha;
        fn_1_50164((f32)width+arg2, (f32)height+arg2, 13.0f, 26.0f, &draw);
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

/* fzgx:begin fn_1_4D4C8 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

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

extern Sprite_4D4C8 lbl_1_rodata_26F8;
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
    w = __abs((s32)(right - left));
    h = __abs((s32)(top - bottom));
    s = lbl_1_rodata_26F8;
    s.unk_C = z;
    s.unk_0 = 18;
    s.unk_2C = 0.1882353f;
    s.unk_30 = 10;
    s.unk_38 = c;
    s.unk_4 = (s32)((left + right) / 2.0f);
    s.unk_8 = (s32)((top + bottom) / 2.0f);
    x = (f32)w + ofs;
    y = (f32)h + ofs;
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
extern u8 *fn_80083DB0(u8 *, const u8 *);
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
        if (fn_1_4B1D4(1, line) > (f32)(s16)width) {
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
            fn_80083DB0(out, line);
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
    fn_80083DB0(out, line);
    out += strlen(line);
    out[1] = 0;
    return out;
}
/* fzgx:end fn_1_4D784 */

/* fzgx:begin fn_1_4DC20 */
typedef struct {
    u32 words[23];
} FontStateCopy;

void fn_1_4DC20(void) {
    *(FontStateCopy *)&lbl_1_bss_4BB40 =
        *(FontStateCopy *)&lbl_1_bss_4B9CC;
    lbl_1_bss_4BB3C = 1;
}
/* fzgx:end fn_1_4DC20 */

/* fzgx:begin fn_1_4DC6C */
void fn_1_4DC6C(void) {
    lbl_1_bss_4B9CC = *(Obj_1_bss_4B9CC *)&lbl_1_bss_4BB40;
    lbl_1_bss_4BB3C = 0;
}
/* fzgx:end fn_1_4DC6C */

/* fzgx:begin fn_1_4DCB8 */
// Replaces the stored font state value and returns its previous value.
u32 fn_1_4DCB8(u32 value) {
    u32 old_value = lbl_1_bss_4B9CC.unk_58;
    lbl_1_bss_4B9CC.unk_58 = value;
    return old_value;
}
/* fzgx:end fn_1_4DCB8 */

/* fzgx:begin fn_1_4DCD0 */
// Returns the address of the font data embedded in the global object.
u8 *fn_1_4DCD0(void) {
    return (u8 *)&lbl_1_bss_4C688.unk_C;
}
/* fzgx:end fn_1_4DCD0 */

/* fzgx:begin fn_1_4DCE0 */
u8 *fn_1_4DCE0(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x10;
}
/* fzgx:end fn_1_4DCE0 */

/* fzgx:begin fn_1_4DCF0 */
u8 *fn_1_4DCF0(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x14;
}
/* fzgx:end fn_1_4DCF0 */

/* fzgx:begin fn_1_4DD00 */
u8 *fn_1_4DD00(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x18;
}
/* fzgx:end fn_1_4DD00 */

/* fzgx:begin fn_1_4DD10 */
u8 *fn_1_4DD10(void) {
    return &lbl_1_bss_4C688.pad_10[0xc];
}
/* fzgx:end fn_1_4DD10 */

/* fzgx:begin fn_1_4DD20 */
u8 *fn_1_4DD20(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x30;
}
/* fzgx:end fn_1_4DD20 */

/* fzgx:begin fn_1_4DD30 */
u8 *fn_1_4DD30(void) {
    return &lbl_1_bss_4C688.pad_4[0x30];
}
/* fzgx:end fn_1_4DD30 */

/* fzgx:begin fn_1_4DD40 */
u8 *fn_1_4DD40(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x40;
}
/* fzgx:end fn_1_4DD40 */

/* fzgx:begin fn_1_4DD50 */
u8 *fn_1_4DD50(void) {
    // Return the byte address used by the font data at offset 0x41.
    return &lbl_1_bss_4C688.pad_4[0x3d];
}
/* fzgx:end fn_1_4DD50 */

/* fzgx:begin fn_1_4DD60 */
u8 *fn_1_4DD60(void) {
    return &lbl_1_bss_4C688.pad_4[0x3e];
}
/* fzgx:end fn_1_4DD60 */

/* fzgx:begin fn_1_4DD70 */
u8 *fn_1_4DD70(void) {
    return (u8 *)&lbl_1_bss_4C688 + 0x44;
}
/* fzgx:end fn_1_4DD70 */

/* fzgx:begin fn_1_4DD80 */
u8 *fn_1_4DD80(void) {
    return &lbl_1_bss_4C688.pad_4[0x41];
}
/* fzgx:end fn_1_4DD80 */

/* fzgx:begin fn_1_4DD90 */
u8 *fn_1_4DD90(void) {
    return &lbl_1_bss_4C688.pad_4[0x42];
}
/* fzgx:end fn_1_4DD90 */

/* fzgx:begin fn_1_4DDA0 */
 // Return the byte address six bytes into the shared font state.
u8 *fn_1_4DDA0(void) {
    return &lbl_1_bss_4C688.pad_4[2];
}
/* fzgx:end fn_1_4DDA0 */

/* fzgx:begin fn_1_4DDB0 */
u8 *fn_1_4DDB0(void) {
    return &lbl_1_bss_4C688.pad_10[0x50];
}
/* fzgx:end fn_1_4DDB0 */

/* fzgx:begin fn_1_4DDC0 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

#pragma opt_unroll_loops off
void fn_1_4DDC0(void) {
    Obj_1_bss_4C688 *ptr;
    int count;
    ptr = &lbl_1_bss_4C688;
    for (count = 0; count < 64; count++) {
        ptr->unk_0 = 0;
        ptr = (Obj_1_bss_4C688 *)((u8 *)ptr + 0x80);
    }
}
/* fzgx:end fn_1_4DDC0 */

/* fzgx:begin fn_1_4DE04 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

u32 fn_1_4DE04(void) {
    Obj_1_bss_4C688 *p = &lbl_1_bss_4C688;
    s32 i;

    for (i = 0; i < 64; i++, p = (Obj_1_bss_4C688 *)((u8 *)p + 0x80)) {
        p->unk_0 = 0;
    }
    return (u32)p;
}
/* fzgx:end fn_1_4DE04 */

/* fzgx:begin fn_1_4DE44 */
// Dispatch callbacks for each active font entry.
void fn_1_4DE44(void) {
    int i;
    u32 *entry;

    if (fn_1_3F164() == 0) {
        entry = &lbl_1_bss_4C688.unk_0;
        for (i = 0; i < 0x40; i++, entry += 0x20) {
            if ((int)entry[0] != 0 && entry[0x1e] != 0) {
                ((void (*)(u32 *))entry[0x1e])(entry);
            }
        }
    }
}
/* fzgx:end fn_1_4DE44 */

/* fzgx:begin fn_1_4DEC0 */
typedef u32 (*fn_1_4DEC0_Fn0)(u32);
struct fn_1_4DEC0_Copy88 { u32 a[22]; };



void fn_1_4DEC0(void) {
    struct FzgxCopy_88 loc_8;
    s32 sp4;
    s32 (*temp_r12)(u32 *);
    s32 var_r31;
    u32 *var_r30;

    var_r31 = 0;
    var_r30 = (u32 *)(&(*(u32 *)&lbl_1_bss_4C688));
    do {
        if ((s32) (*(u32 *)((u8 *)(var_r30) + 0)) != 0) {
            temp_r12 = (s32 (*)(u32 *))(*(s32 (**)(u32 *))((u8 *)(var_r30) + 124));
            if (temp_r12 == NULL) {
                loc_8 = *(const struct FzgxCopy_88 *)((((s32)(((u8 *)(var_r30) + 4))) + 4));
                fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
            } else {
                temp_r12((u32 *)(var_r30));
            }
        }
        var_r31 += 1;
        var_r30 = (u32 *)((u8 *)(var_r30) + 0x80);
    } while (var_r31 < 0x40);
}
/* fzgx:end fn_1_4DEC0 */

/* fzgx:begin fn_1_4DF60 */
typedef struct {
    u32 values[22];
} InitData;

typedef struct {
    s32 unk_0;
    u8 pad[0x7c];
} Slot;

Slot *fn_1_4DF60(void) {
    int i;
    Slot *p;

    p = (Slot *)&lbl_1_bss_4C688;
    for (i = 0; i < 64; i++, p++) {
        if (p->unk_0 == 0) {
            break;
        }
    }

    if (p->unk_0 != 0) {
        return 0;
    }

    *(s32 *)((u8 *)p + 0) = 1;
    *(InitData *)((u8 *)p + 8) = *(InitData *)lbl_1_rodata_26F8;
    *(u16 *)((u8 *)p + 6) = 0;
    *(u32 *)((u8 *)p + 0x68) = 0;
    *(u32 *)((u8 *)p + 0x64) = 0;
    *(u32 *)((u8 *)p + 0x60) = 0;
    *(f32 *)((u8 *)p + 0x74) = lbl_1_rodata_2750;
    *(f32 *)((u8 *)p + 0x70) = lbl_1_rodata_2750;
    *(f32 *)((u8 *)p + 0x6c) = lbl_1_rodata_2750;
    *(u32 *)((u8 *)p + 0x7c) = 0;
    *(u32 *)((u8 *)p + 0x78) = 0;
    *(u8 *)((u8 *)p + 4) = 0;
    return p;
}
/* fzgx:end fn_1_4DF60 */

/* fzgx:begin fn_1_4E060 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

#pragma opt_unroll_loops off
void fn_1_4E060(void) {
    Obj_1_bss_4C688 *p;
    u32 count;
    u32 zero;

    p = &lbl_1_bss_4C688;
    zero = 0;
    for (count = 0; count < 64; count++) {
        p->unk_0 = zero;
        p = (Obj_1_bss_4C688 *)((u8 *)p + 0x80);
    }
}
/* fzgx:end fn_1_4E060 */

/* fzgx:begin fn_1_4E0A4 */
typedef struct FontMetric {
    f32 value;
    u8 pad[0x54];
} FontMetric;

int fn_1_4E0A4(u16 *left, u16 *right) {
    u16 left_index;
    FontMetric *metrics;
    u16 right_index;
    f32 left_value;
    f32 right_value;

    left_index = *left;
    metrics = (FontMetric *)(*(u32 *)&lbl_1_data_1C504 + 0xc);
    right_index = *right;

    left_value = metrics[left_index].value;
    right_value = metrics[right_index].value;
    if (left_value > right_value) {
        return -1;
    }
    if (left_value == right_value) {
        return 0;
    }
    return 1;
}
/* fzgx:end fn_1_4E0A4 */

/* fzgx:begin fn_1_4E0F4 */
void fn_1_4E0F4(void) {
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
    fn_800734A8(0, 0, 0, 0xff);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 0xf, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
}
/* fzgx:end fn_1_4E0F4 */

/* fzgx:begin fn_1_4E220 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

typedef enum {
    GX_TF_I4 = 0x0,
    GX_TF_I8 = 0x1,
    GX_TF_IA4 = 0x2,
    GX_TF_IA8 = 0x3,
    GX_TF_RGB565 = 0x4,
    GX_TF_RGB5A3 = 0x5,
    GX_TF_RGBA8 = 0x6,
    GX_TF_CMPR = 0xE,
    GX_CTF_R4 = 0x0 | 0x20,
    GX_CTF_RA4 = 0x2 | 0x20,
    GX_CTF_RA8 = 0x3 | 0x20,
    GX_CTF_YUVA8 = 0x6 | 0x20,
    GX_CTF_A8 = 0x7 | 0x20,
    GX_CTF_R8 = 0x8 | 0x20,
    GX_CTF_G8 = 0x9 | 0x20,
    GX_CTF_B8 = 0xA | 0x20,
    GX_CTF_RG8 = 0xB | 0x20,
    GX_CTF_GB8 = 0xC | 0x20,
    GX_TF_Z8 = 0x1 | 0x10,
    GX_TF_Z16 = 0x3 | 0x10,
    GX_TF_Z24X8 = 0x6 | 0x10,
    GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    GX_TF_A8 = GX_CTF_A8,
} GXTexFmt;

typedef struct {
    u32 dummy[8];
} GXTexObj;

typedef enum {
    GX_CLAMP,
    GX_REPEAT,
    GX_MIRROR,
    GX_MAX_TEXWRAPMODE,
} GXTexWrapMode;

typedef struct {
    f32 m[12];
} Mtx;

struct Arg0 {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    s16 unk_28;
    u8 pad_2A[0x6];
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
    s32 unk_40;
    u16 unk_44;
    u16 unk_46;
    u32 unk_48;
};

extern const f32 lbl_1_rodata_2750;
extern const f32 lbl_1_rodata_2754;
extern const f64 lbl_1_rodata_2758;
extern f32 fn_1_519AC(u32);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006DD7C(void);
extern void lbl_8006DB74(Mtx *);
extern void mathutil_mtxA_rotate_z(u32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern u16 GXLoadTexMtxImm(Mtx *, u32, u32);
extern u32 __cvt_fp2unsigned(f32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, GXTexFmt, GXTexWrapMode, GXTexWrapMode, u8);
extern void fn_800729B0(s32, s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073778(void *, s32);
extern void fn_80073C6C(s32);
extern GXTexObj lbl_1_bss_4E688;

static inline f32 fn_1_4E220_operand(f32 left, f32 right) { left *= right; return left; }
static inline void fn_1_4E220_call_GXInitTexObj(GXTexObj * a0, void * a1, u16 a2, u16 a3, GXTexFmt a4, GXTexWrapMode a5, GXTexWrapMode a6, u8 a7) { GXInitTexObj(a0, a1, a2, a3, a4, a5, a6, a7); }
static inline f32 fn_1_4E220_operand_(f32 right, f32 left) { return left * right; }
void fn_1_4E220(struct Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    f32 fzgx_live;
    Mtx loc_8;
    u32 v1;
    s32 v2;
    u32 v5;
    Obj_1_data_FCD4_At20 *v6;
    u32 v7;
    f32 scale;
    f32 f44;
    f32 f46;
    struct { f32 v; } prod;
    struct { f32 v; } total;
    s32 lab_t1;
    u32 lab_t2;
    Mtx * lab_t0;
    s32 lab_t3;
    u32 lab_t3_;

    lbl_8006D7F4(arg0->unk_4, arg0->unk_8, lbl_1_rodata_2750);
    fzgx_live = arg0->unk_14;
    lbl_8006E15C(arg0->unk_10, fzgx_live, lbl_1_rodata_2754);
    if (arg0->unk_28 != 0) {
        mathutil_mtxA_rotate_z(arg0->unk_28);
    }
    lbl_8006DD7C();
    lbl_8006DB74(&loc_8);
    v1 = arg2 & 0xFF;
    v2 = arg4 & 0xFF;
    fn_800745A4(v1, 1, 4, v2, 0, 125);
    lab_t2 = 1;
    lab_t0 = &loc_8;
    GXLoadTexMtxImm(lab_t0, v2, lab_t2);
    if (arg0->unk_30 & 0x800000) {
        scale = fn_1_519AC(arg0->unk_40);
        f44 = (f32)arg0->unk_44;
        f46 = (f32)arg0->unk_46;
        scale = f44 * scale;
        scale = f46 * scale;
        DCFlushRange((void *)arg0->unk_48, __cvt_fp2unsigned(scale));
        lab_t3_ = arg0->unk_46;
        fn_1_4E220_call_GXInitTexObj(&lbl_1_bss_4E688, (void *)arg0->unk_48, ((u16)(arg0->unk_44)), lab_t3_, (GXTexFmt)arg0->unk_40, GX_CLAMP, GX_CLAMP, 0);
        lab_t1 = arg3 & 0xFF;
        fn_80073778(&lbl_1_bss_4E688, lab_t1);
    } else {
        lab_t2 = arg0->unk_0;
        v5 = lab_t2;
        v6 = *(Obj_1_data_FCD4_At20 **)((((u32)&lbl_1_data_FCD4) + 0x20) + (((v5 >> 8) & 0xFFFF) * 0x28));
        if (!(lbl_1_rodata_2750 != arg0->unk_10 && lbl_1_rodata_2750 != arg0->unk_14 && v6 != 0)) {
            return;
        } else {
            fn_80073778((void *)(v6->unk_C + ((v5 & 0xFF) << 5)), arg3 & 0xFF);
        }
    }
    v7 = arg1 & 0xFF;
    fn_80073C6C(v7);
    fn_800734A8(v7, v1, arg3 & 0xFF, 255);
    if (((0) == (arg0->unk_40)) || ((((arg0->unk_40)) == ((1))))) {
        fn_80072C24(v7, 15, 15, 15, 0);
        fn_80072D64(v7, 0, 0, 0, 1, 0);
        fn_80072CC4(v7, 7, 0, 4, 7);
        lab_t3 = 0;
        fn_80072E20(v7, 0, 0, lab_t3, 1, 0);
    } else {
        fn_800729B0(2, 0, 0, 0, 0);
        fn_80072AB0(v7, 0, 2);
        fn_80072C24(v7, 8, 15, 0, 15);
        fn_80072D64(v7, 8, 0, 0, 1, 0);
        fn_80072CC4(v7, 4, 7, 0, 7);
        lab_t3 = 0;
        fn_80072E20(v7, 14, 0, lab_t3, 1, 0);
    }
}
/* fzgx:end fn_1_4E220 */

/* fzgx:begin fn_1_4E500 */
void fn_1_4E500(void) {
    fn_1_A71CC();
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
    fn_800734A8(0, 0, 0, 0xff);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 0xf, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
    lbl_8006D758();
    fn_80072558();
}
/* fzgx:end fn_1_4E500 */

/* fzgx:begin fn_1_4E638 */
void fn_1_4E638(s32 arg) {
    f32 *values;

    values = lbl_1_rodata_26F8;
    if (arg != 0) {
        C_MTXPerspective( (f32 *)(void *)((u8 *)lbl_801A6D00 + 0xc8),
                    values[26], fn_1_A6FE8(), values[27], values[28]);
        fn_800737E4((u8 *)lbl_801A6D00 + 0xc8, 0);
    } else {
        C_MTXOrtho((u8 *)lbl_801A6D00 + 0xc8,
                    values[22], values[29], values[22], values[30],
                    values[22], values[28]);
        fn_800737E4((u8 *)lbl_801A6D00 + 0xc8, 1);
    }
}
/* fzgx:end fn_1_4E638 */

/* fzgx:begin fn_1_4E6F4 */
void fn_1_4E6F4(void) {
    fn_1_A722C();
    fn_80074918(1, 3, 1);
}
/* fzgx:end fn_1_4E6F4 */

/* fzgx:begin fn_1_4E724 */
// Initialize the font system and return the selected font resource.
s32 fn_1_4E724(FontParams *arg) {
    FontParams local = *arg;
    s32 ret;

    fn_1_A71CC();
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
    fn_800734A8(0, 0, 0, 0xff);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 0xf, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
    lbl_8006D758();
    fn_80072558();

    if ((s32)lbl_1_bss_4E6A8 != 0) {
        local.unk_30 |= 0x08000000;
        local.unk_34 = (f32)(s32)lbl_1_bss_4E6AC;
    }

    ((u8 *)lbl_801A6D00)[0x197] = 0xff;

    if (local.unk_30 & 0x00800000) {
        ret = fn_1_4EC74(&local);
    } else {
        ret = fn_1_4EB74( (fn_1_4EB74_FontObject *)(FontParams *)(&local));
    }

    fn_1_A722C();
    fn_80074918(1, 3, 1);

    return ret;
}
/* fzgx:end fn_1_4E724 */

/* fzgx:begin fn_1_4E92C */
typedef struct Sig_fn_1_4EC74_FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} Sig_fn_1_4EC74_FontParams;

typedef struct Sig_fn_1_4EB74_FontParams {
    u8 unk_00[0x30];
    u32 unk_30;
    f32 unk_34;
    u8 unk_38[0x58 - 0x38];
} Sig_fn_1_4EB74_FontParams;

struct fn_1_4E92C_Copy88 { u32 a[22]; };
struct fn_1_4E92C_lbl_1_bss_4E6AC {
    s32 unk_0;
};
struct fn_1_4E92C_lbl_1_rodata_2778 {
    f64 unk_0;
};
struct fn_1_4E92C_lbl_801A6D00 {
    u32 unk_0;
};

s32 fn_1_4E92C(s32 arg0, u32 arg1, s16 arg2, s16 arg3, u32 arg4) {
    struct FzgxCopy_88 loc_60;
    struct FzgxCopy_88 loc_8;
    s32 sp4;
    s32 var_r31;

    loc_60 = *(const struct FzgxCopy_88 *)((arg0 - 4 + 4));
    loc_60.words[0x10] = arg1;
    loc_60.words[0xC] |= 0x800000;
    (*(s16 *)((u8 *)(&loc_60) + 68)) = arg2;
    (*(s16 *)((u8 *)(&loc_60) + 70)) = arg3;
    loc_60.words[0x12] = arg4;
    loc_8 = *(const struct FzgxCopy_88 *)((((s32)(&loc_8.words[0x15])) + 4));
    fn_1_A71CC();
    fn_800724C8();
    fn_8007245C((u32)(0x2200U));
    fn_80074788((u32)(0U));
    fn_80074660((u32)(1U));
    fn_80073678((u32)(1U));
    fn_80073898((u32)(0U));
    fn_80073C6C((s32)(0));
    fn_800745A4((u32)(0U), (s32)(1), (s32)(4), (u32)(0x3CU), (u32)(0U), (u32)(0x7DU));
    fn_800734A8((u32)(0U), (u32)(0U), (u32)(0U), (u32)(0xFFU));
    fn_80072AB0((s32)(0), (s32)(0), (s32)(0));
    fn_80072C24((s32)(0), (s32)(0xF), (s32)(2), (s32)(8), (s32)(4));
    fn_80072D64((u32)(0U), (u32)(0U), (u32)(0U), (u32)(0U), (u32)(1U), (u32)(0U));
    fn_80072CC4((u32)(0U), (u32)(7U), (u32)(1U), (u32)(4U), (u32)(2U));
    fn_80072E20((s32)(0), (s32)(0), (s32)(0), (s32)(0), (u8)(1U), (s32)(0));
    fn_80074918((u8)(1U), (s32)(7), (u8)(0U));
    fn_800728A8((s32)(1), (s32)(4), (s32)(5), (s32)(0));
    fn_800720B0((u32)(0U));
    fn_80072864((u32)(2U));
    lbl_8006D758();
    fn_80072558();
    if ((s32) (*(u32 *)((u8 *)(&lbl_1_bss_4E6A8) + 0)) != 0) {
        loc_8.words[0xC] |= 0x08000000;
        (*(f32 *)((u8 *)(&loc_8) + 52)) = (f32) (*((struct fn_1_4E92C_lbl_1_bss_4E6AC *)&lbl_1_bss_4E6AC)).unk_0;
    }
    (*(u8 *)((u8 *)((*((struct fn_1_4E92C_lbl_801A6D00 *)&lbl_801A6D00)).unk_0) + 407)) = 0xFF;
    if (loc_8.words[0xC] & 0x800000) {
        var_r31 = fn_1_4EC74( (FontParams *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)));
    } else {
        var_r31 = fn_1_4EB74( (fn_1_4EB74_FontObject *)((FontDrawPacket *)((FontDrawPacket *) &loc_8)));
    }
    fn_1_A722C();
    fn_80074918((u8)(1U), (s32)(3), (u8)(1U));
    return var_r31;
}
/* fzgx:end fn_1_4E92C */

/* fzgx:begin fn_1_4EB74 */
/* lbl_1_data_FCD4 is indexed as an array of 0x28-byte records; the header's
   Obj_1_data_FCD4 spans the whole blob, so index through this record view. */
typedef struct TableEntry {
    s32 unk_0;
    u32 unk_4;
    u8 pad_8[0x18];
    Obj_1_data_FCD4_At20 *unk_20;
    u32 unk_24;
} TableEntry;

s32 fn_1_4EB74(fn_1_4EB74_FontObject *self) {
    TableEntry *table;
    Obj_1_data_FCD4_At20 *data;
    u32 value;
    u32 index;
    u16 *row;
    f32 x;
    f32 y;

    if (self->unk_30 & 0x02000000) {
        return 0;
    }

    value = self->unk_0;
    fn_1_159588(value);
    value = self->unk_0;

    index = (value >> 8) & 0xffff;
    table = (TableEntry *)&lbl_1_data_FCD4;
    if (table[index].unk_0 == 0) {
        return 0;
    }

    data = table[index].unk_20;
    row = (u16 *)((u8 *)data->unk_4 + ((value & 0xff) << 4));
    x = (f32)(u32)row[4];
    y = (f32)(u32)row[5];
    fn_80073778((void *)((u8 *)data->unk_C + ((value & 0xff) << 5)), 0);
    fn_1_4EDAC( (FontDrawPacket*)(void *)(self), x, y);
    return 1;
}
/* fzgx:end fn_1_4EB74 */

/* fzgx:begin fn_1_4EC74 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"
#include "font.h"

extern f32 fn_1_519AC(u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void fn_80073778(void *, s32);

/* the const packet lets MWCC (GC/2.x) load packet->flags ahead of the r31 save, as retail does */
s32 fn_1_4EC74(const FontDrawPacket *packet) {
    if (packet->flags & 0x2000000) {
        return 0;
    }
    DCFlushRange(packet->pixels,
                 (u32)((f32)packet->height * ((f32)packet->width * fn_1_519AC(packet->format))));
    {
        u32 width = packet->width, height = packet->height;
        GXInitTexObj(lbl_1_bss_4E6B0, packet->pixels, width, height, packet->format, 0, 0, 0);
    }
    GXInitTexObjLOD(lbl_1_bss_4E6B0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
    fn_80073778(lbl_1_bss_4E6B0, 0);
    fn_1_4EDAC((FontDrawPacket *)packet, (f32)packet->width, (f32)packet->height);
    return 1;
}
/* fzgx:end fn_1_4EC74 */

/* fzgx:begin fn_1_4EDAC noprologue */
#include "types.h"
#include "font.h"
#include "types.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "psvec_fill.h"
#include "dolphin/gx.h"

struct fn_1_4EDAC_lbl_801A6D00 {
    u32 unk_0;
};

const u32 lbl_1_rodata_26F8[22] = {
0,0,0,0x3dcccccd,0x3f800000,0x3f800000,0,0,
0x3f800000,0x3f800000,0,0x3f800000,5,0,0xffffffff,0,0,0,0,0,0,0
};

#pragma section code_type ".fzgxpool"
static void fn_1_4EDAC_pool_primer(f32 *f, f64 *d) {
    f[0] = 0.0f;
    f[1] = 1.0f;
    d[0] = 4503599627370496.0;
    f[2] = 55.0f;
    f[3] = 0.1f;
    f[4] = 90000.0f;
    f[5] = 480.0f;
    f[6] = 640.0f;
    d[1] = 4503601774854144.0;
    d[2] = 0.5;
    f[7] = 0.75f;
    d[3] = 0.002405626;
    f[8] = 320.0f;
    f[9] = 240.0f;
    f[10] = 255.0f;
}
#pragma section code_type
extern struct fn_1_4EDAC_lbl_801A6D00 lbl_801A6D00;

typedef struct DrawVertex { f32 x, y, z; } DrawVertex;
typedef struct DrawColor { u8 r, g, b, a; } DrawColor;
typedef struct DrawFields {
    u32 id;
    f32 x, y, depth;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 angle_z, angle_y;
    f32 alpha;
    u32 flags;
    f32 pivot;
    DrawColor color, add_color;
    s32 format;
    u16 width, height;
    u32 image;
    FontDrawPacket *texture;
    void (*callback)(FontDrawPacket *, DrawVertex *);
} DrawFields;

extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(void *, f32, f32, f32, f32);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_80074660(u32);
extern void fn_80073678(u32);
extern void fn_1_4E220(FontDrawPacket *, u32, u32, u32, u32);
extern s32 fn_1_A6F1C(void);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_z(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void lbl_8006E1B0(void *, void *);
extern void fn_1_492F0(FontDrawPacket *, void *);
extern s32 fn_1_486F8(u32);
extern u32 fn_800371F8(u32, void *);
extern void fn_8003462C(u32, u32, u32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800724C8(void);
extern void fn_8007245C(u32);
extern void fn_80074788(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800728A8(s32, s32, s32, s32);
extern u32 fn_800720B0(u32);
extern void fn_80072864(u32);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 fn_80074188(u32, u32, u32, u32);

static inline void draw_vertex(DrawVertex *v, f32 u, f32 t) {
    f32 z = v->z;
    f32 y = v->y;
    f32 x = v->x;
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
    GXWGFifo.f32 = u;
    GXWGFifo.f32 = t;
}

static inline void draw_reset(void) {
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
    fn_800734A8(0, 0, 0, 0xff);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 15, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
}

static inline u32 draw_perspective(FontDrawPacket *packet) {
    u32 result = (packet->flags >> 18) & 1;
    return result;
}

static inline u8 draw_min255(s32 value) {
    u8 result = value < 255 ? value : 255;
    return result;
}

static inline void draw_rgb(DrawColor *color, u8 blue, u8 green, u8 red) {
    color->r = red;
    color->g = green;
    color->b = blue;
}

void fn_1_4EDAC(FontDrawPacket *arg0, f32 arg1, f32 arg2) {
    u32 v0;
    f32 v1;
    DrawVertex *v2;
    u8 perspective;
#define v3 perspective
    f32 y, depth, u0, u1, t0, t1;
    DrawColor add_color, color;
    u32 flags;
    DrawFields *packet = (DrawFields *)arg0;
    perspective = draw_perspective(arg0);
    v0 = lbl_801A6D00.unk_0;
    v1 = 0.0f;
    v2 = (DrawVertex *)(v0 + 152);
    psvec_fill4(v2, v1);
    if (v3) {
        C_MTXPerspective((void *)(lbl_801A6D00.unk_0 + 0xc8), 55.0f, fn_1_A6FE8(),
            0.1f, 90000.0f);
        fn_800737E4((void *)(lbl_801A6D00.unk_0 + 0xc8), 0);
    } else {
        C_MTXOrtho((void *)(lbl_801A6D00.unk_0 + 0xc8), v1, 480.0f,
            v1, 640.0f, v1, 90000.0f);
        fn_800737E4((void *)(lbl_801A6D00.unk_0 + 0xc8), 1);
    }
    flags = arg0->flags;
    *(u8 *)(lbl_801A6D00.unk_0 + 0x197) = v3;
    if ((flags & 0x1000000) && packet->texture) {
        fn_80074660(2);
        fn_80073678(2);
        fn_1_4E220(packet->texture, 1, 1, 1, 0x21);
    } else {
        fn_80073678(1);
    }
    v1 = packet->x;
    y = packet->y;
    depth = -packet->depth;
    u0 = packet->u0;
    u1 = packet->u1;
    t0 = packet->v0;
    t1 = packet->v1;
    switch (arg0->flags & 3) {
    case 0:
    case 1:
    default:
        v2[0].x = v2[2].x = 0.0f;
        v2[1].x = v2[3].x = arg1;
        break;
    case 2: {
        f32 right;
        f32 left;
        left = -arg1 / 2.0;
        right = arg1 / 2.0;
        v2[0].x = v2[2].x = left;
        v2[1].x = v2[3].x = right;
        break;
    }
    case 3: {
        f32 right;
        f32 left;
        left = -arg1;
        right = 0.0f;
        v2[0].x = v2[2].x = left;
        v2[1].x = v2[3].x = right;
        break;
    }
    }
    switch ((arg0->flags >> 2) & 3) {
    case 0:
    case 1:
    default:
        v2[0].y = v2[1].y = 0.0f;
        v2[2].y = v2[3].y = arg2;
        break;
    case 2: {
        f32 right;
        f32 left;
        left = -arg2 / 2.0;
        right = arg2 / 2.0;
        v2[0].y = v2[1].y = left;
        v2[2].y = v2[3].y = right;
        break;
    }
    case 3: {
        f32 right;
        f32 left;
        left = -arg2;
        right = 0.0f;
        v2[0].y = v2[1].y = left;
        v2[2].y = v2[3].y = right;
        break;
    }
    }
    if ((arg0->flags & 0x8000000) && (fn_1_A6F1C() == 1 || fn_1_A6F1C() == 2)) {
        lbl_8006D7F4(packet->pivot, 0.0f, 0.0f);
        lbl_8006E15C(0.75f, 1.0f, 1.0f);
        lbl_8006E0B4(v1 - packet->pivot, y, 0.0f);
    } else {
        lbl_8006D7F4(v1, y, 0.0f);
    }
    if (packet->angle_z)
        mathutil_mtxA_rotate_z((s16)-packet->angle_z);
    if (packet->angle_y)
        mathutil_mtxA_rotate_y((s16)-packet->angle_y);
    lbl_8006E15C(packet->scale_x, packet->scale_y, 1.0f);
    lbl_8006E1B0(&v2[0], &v2[0]);
    lbl_8006E1B0(&v2[1], &v2[1]);
    lbl_8006E1B0(&v2[2], &v2[2]);
    lbl_8006E1B0(&v2[3], &v2[3]);
    fn_1_492F0(arg0, v2);
    if (v3) {
        f32 scratch;
        f32 scale;
        f32 cy;
        f32 cx;
        f32 vx;
        scale = 0.002405626 * packet->depth;
        vx = v2[0].x;
        cx = 320.0f;
        cy = 240.0f;
        scratch = vx - cx;
        v2[0].x = scratch * scale;
        scratch = v2[0].y - cy;
        v2[0].y = -(scratch * scale);
        scratch = v2[1].x - cx;
        v2[1].x = scratch * scale;
        scratch = v2[1].y - cy;
        v2[1].y = -(scratch * scale);
        scratch = v2[2].x - cx;
        v2[2].x = scratch * scale;
        scratch = v2[2].y - cy;
        v2[2].y = -(scratch * scale);
        scratch = v2[3].x - cx;
        v2[3].x = scratch * scale;
        scratch = v2[3].y - cy;
        v2[3].y = -(scratch * scale);
    }
    if (arg0->flags & 0x80000) {
        u0 = packet->u1;
        u1 = packet->u0;
    }
    if (arg0->flags & 0x100000) {
        t0 = packet->v1;
        t1 = packet->v0;
    }
    if (!(arg0->flags & 0x800000) && !(arg0->flags & 0x10000000) &&
        (fn_1_486F8(packet->id) == 0 || fn_1_486F8(packet->id) == 1)) {
        u32 sum;
        color.r = 0;
        color.g = 0;
        color.b = 0;
        color.a = (s32)(255.0f * packet->alpha);
        sum = packet->color.r + packet->add_color.r;
        add_color.r = (s32)sum < 255 ? sum : 255;
        sum = packet->color.g + packet->add_color.g;
        add_color.g = (s32)sum < 255 ? sum : 255;
        sum = packet->color.b + packet->add_color.b;
        add_color.b = draw_min255(sum);
        add_color.a = 0;
        { DrawColor copy = color; fn_800371F8(1, &copy); }
        { DrawColor copy = add_color; fn_800371F8(2, &copy); }
    } else {
        u32 blue, red;
        s8 green;
        /* volatile: preserve the retail RGB channel read order. */
        red = *(volatile u8 *)&packet->color.r;
        /* volatile: preserve the retail RGB channel read order. */
        green = *(volatile u8 *)&packet->color.g;
        /* volatile: preserve the retail RGB channel read order. */
        blue = *(volatile u8 *)&packet->color.b;
        /* volatile: retain the retail red-before-green stack stores. */
        *(volatile u8 *)&color.r = red;
        /* volatile: retain the retail red-before-green stack stores. */
        *(volatile u8 *)&color.g = green;
        color.b = blue;
        color.a = (s32)(255.0f * packet->alpha);
        { DrawColor copy = color; fn_800371F8(1, &copy); }
        { DrawColor copy = packet->add_color; fn_800371F8(2, &copy); }
    }
    if ((arg0->flags & 0x4000000) && packet->callback)
        packet->callback(arg0, v2);
    if (!v3) {
        v2[0].z = v2[1].z = v2[2].z = v2[3].z = depth;
    }
    fn_8003462C(0x80, 7, 4);
    draw_vertex(&v2[0], u0, t0);
    draw_vertex(&v2[1], u1, t0);
    draw_vertex(&v2[3], u1, t1);
    draw_vertex(&v2[2], u0, t1);
    fn_80072AB0(1, 0, 0);
    if ((arg0->flags & 0x1000000) && packet->texture) {
        draw_reset();
        fn_80074660(1);
        fn_80072AB0(1, 0, 0);
    }
    if (arg0->flags & 0x4000000) {
        struct { u32 value; } height;
        draw_reset();
        height.value = (u16)fn_1_A5DB0();
        fn_80074188(0, 0, fn_1_A5D88(), height.value);
    }
}
/* fzgx:end fn_1_4EDAC */

/* fzgx:begin fn_1_4F724 */
extern Obj_1_bss_646D2 lbl_1_bss_4E6D0__fzgx_offset_16002;
// Clear the font state value before the next initialization.
void fn_1_4F724(void) {
    lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0 = 0;
}
/* fzgx:end fn_1_4F724 */

/* fzgx:begin fn_1_4F734 noprologue */
#include "types.h"
#include "font.h"

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
extern State lbl_1_bss_4C678;
extern Config lbl_1_data_1C500;
extern u16 lbl_1_bss_4E6D0__fzgx_offset_16002;
extern u8 *lbl_801A6D00;
extern Resource lbl_1_data_FCD4[];
extern void fn_1_A71CC(void), fn_800724C8(void), lbl_8006D758(void), fn_80072558(void),
    fn_1_A722C(void);
extern void fn_8007245C(u32), fn_80074788(u32), fn_80074660(u32), fn_80073678(u32),
    fn_80073898(u32), fn_80073C6C(u32), fn_800720B0(u32), fn_80072864(u32);
extern void fn_800745A4(u32, u32, u32, u32, u32, u32), fn_80072D64(u32, u32, u32, u32, u32, u32),
    fn_80072E20(u32, u32, u32, u32, u32, u32);
extern void fn_800734A8(u32, u32, u32, u32), fn_800728A8(u32, u32, u32, u32);
extern void fn_80072AB0(u32, u32, u32), fn_80074918(u32, u32, u32);
extern void fn_80072C24(u32, u32, u32, u32, u32), fn_80072CC4(u32, u32, u32, u32, u32);
extern f32 fn_1_519AC(u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void fn_80073778(void *, u32);
extern void fn_1_4EDAC(FontDrawPacket *, f32, f32);
extern void fn_1_159588(u32);
extern void OSReport(const char *, ...);
extern void *fn_80008BA8(void *, const void *, u32);
extern s32 fn_1_54298(void), fn_1_542A8(void);
extern f32 fn_1_542B8(void);
int fn_1_4F734(FontDrawPacket *input) {
    State *state = &lbl_1_bss_4C678;
    Config *config = &lbl_1_data_1C500;
    if (input->image >= 0xffff0000u)
        return 0;
    if (input->flags & 0x20000) {
        FontDrawPacket local = *input;
        int result;
        fn_1_A71CC();
        fn_800724C8();
        fn_8007245C(0x2200);
        fn_80074788(0);
        fn_80074660(1);
        fn_80073678(1);
        fn_80073898(0);
        fn_80073C6C(0);
        fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
        fn_800734A8(0, 0, 0, 0xff);
        fn_80072AB0(0, 0, 0);
        fn_80072C24(0, 0xf, 2, 8, 4);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 1, 4, 2);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        fn_80074918(1, 7, 0);
        fn_800728A8(1, 4, 5, 0);
        fn_800720B0(0);
        fn_80072864(2);
        lbl_8006D758();
        fn_80072558();
        if (state->override_enabled) {
            local.flags |= 0x08000000;
            local.depth = (f32)state->override_value;
        }
        lbl_801A6D00[0x197] = 0xff;
        if (local.flags & 0x800000) {
            if (local.flags & 0x2000000)
                result = 0;
            else {

                DCFlushRange(local.pixels, (u32)((f32)local.height *
                                                 ((f32)local.width * fn_1_519AC(local.format))));
                {
                    u32 width = local.width, height = local.height;
                    GXInitTexObj(state->texture, local.pixels, width, height, local.format, 0, 0, 0);
                }
                GXInitTexObjLOD(state->texture, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
                fn_80073778(state->texture, 0);
                fn_1_4EDAC(&local, (f32)local.width, (f32)local.height);
                result = 1;
            }
        } else {
            if (local.flags & 0x2000000)
                result = 0;
            else {
                Resource *resource;
                Resource *table;
                u32 id, index;
                fn_1_159588(local.image);
                table = lbl_1_data_FCD4;
                id = local.image;
                index = (id >> 8) & 0xffff;
                if (!table[index].loaded)
                    result = 0;
                else {
                    ImageInfo *info;
                    f32 height, width;
                    resource = table;
                    resource += index;
                    info = &resource->images->info[(u8)id];
                    width = (f32)info->width;
                    height = (f32)info->height;
                    fn_80073778(resource->images->textures[(u8)id], 0);
                    fn_1_4EDAC(&local, width, height);
                    result = 1;
                }
            }
        }
        fn_1_A722C();
        fn_80074918(1, 3, 1);
        return result;
    } else {
        u16 count = lbl_1_bss_4E6D0__fzgx_offset_16002;
        FontDrawPacket *dst;
        if (count >= config->capacity) {
            if (!state->warned) {
                OSReport(config->warning);
                state->warned = 1;
            }
            return 0;
        }
        dst = &config->packets[count];
        fn_80008BA8(dst, input, 0x58);
        dst->x += (f32)fn_1_54298();
        dst->y += (f32)fn_1_542A8();
        dst->alpha *= fn_1_542B8();
        if (state->override_enabled) {
            dst->flags |= 0x08000000;
            dst->depth = (f32)state->override_value;
        }
        lbl_1_bss_4E6D0__fzgx_offset_16002++;
        return 1;
    }
}
/* fzgx:end fn_1_4F734 */

/* fzgx:begin fn_1_4FC50 */
extern Obj_1_bss_646D2 lbl_1_bss_4E6D0__fzgx_offset_16002;
typedef struct {
    u32 unk_0;
} InputObject;

s32 fn_1_4FC50(InputObject *obj, u32 arg1, u16 arg2, u16 arg3, u32 arg4) {
    Obj_1_data_1C504_Target *entry;
    u16 index;

    if (obj->unk_0 >= 0xffff0000) {
        return 0;
    }
    index = lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0;
    if (index >= lbl_1_data_1C500) {
        return 0;
    }

    entry = (Obj_1_data_1C504_Target *)((u8 *)lbl_1_data_1C504 + index * 0x58);
    fn_80008BA8( (u32)(void *)(entry), (u32)(void *)(obj), 0x58);
    entry->unk_30 |= (u32)1 << 23;
    entry->unk_40 = arg1;
    entry->unk_44 = arg2;
    entry->unk_46 = arg3;
    entry->unk_48 = arg4;

    if ((s32)lbl_1_bss_4E6A8 != 0) {
        entry->unk_30 |= (u32)1 << 27;
        entry->unk_34 = (f32)(s32)lbl_1_bss_4E6AC;
    }

    lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0++;
    return 1;
}
/* fzgx:end fn_1_4FC50 */

/* fzgx:begin fn_1_4FD64 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"
extern Obj_1_bss_646D2 lbl_1_bss_4E6D0__fzgx_offset_16002;

typedef void FontDrawPacket;
extern u8 *lbl_801A66CC;
extern u8 *lbl_801A6D00;
extern const f64 lbl_1_rodata_2758;
extern f32 lbl_1_rodata_2750;
extern f32 fn_1_519AC(u32);
extern int fn_1_4E0A4(u16 *, u16 *);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_800720B0(u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, int, int, int, u8);
extern void GXInitTexObjLOD(void *, int, int, f32, f32, f32, u8, u8, int);
extern void fn_80073778(void *, s32);
extern void fn_1_4EDAC(FontDrawPacket *, f32, f32);
extern int fn_1_159588(int);
extern void fn_1_48D80(u32);
extern void fn_1_A71CC(void);
extern void fn_1_A722C(void);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072558(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_80074918(u8, s32, u8);
extern void lbl_8006D758(void);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
static inline void fn_1_4FD64_call_GXInitTexObj(u8 a7, int a6, int a5, int a4, u16 a3, s16 a2, void *a1, void *a0) {
    GXInitTexObj(a0, a1, a2, a3, a4, a5, a6, a7);
}
void fn_1_4FD64(f32 arg0) {
    u16 *a;
    s32 i;
    u32 lab_t4;
    u32 lab_t0;
    a = (u16 *)(lbl_801A66CC + 0x8B8);
    for (i = 0; i < lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0; i++) {
        a[i] = i;
    }
    qsort(a, lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0, 2, (int (*)(const void *, const void *))fn_1_4E0A4);
    fn_1_A71CC();
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3C, 0, 0x7D);
    lab_t0 = 0;
    fn_800734A8(lab_t0, 0, 0, 0xFF);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 0xF, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
    lbl_8006D758();
    fn_80072558();
    lbl_801A6D00[0x197] = 0xFF;
    for (i = 0; i < lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0; i++) {
        Obj_1_data_1C504_Target *e = (Obj_1_data_1C504_Target *)((u8 *)lbl_1_data_1C504 + a[i] * 0x58);
        u32 fl = *(volatile u32 *)&e->unk_30; // volatile: retail reads packet flags anew in each drawing path.
        if (fl & 0x2000000) continue;
        if (fl & 0x400000) {
            fn_1_48D80((u32)e);
        } else if (fl & 0x800000) {
            if (*(volatile u32 *)&e->unk_30 & 0x2000000) continue; // volatile: preserve retail's second flags load.
            {
                f32 sc = fn_1_519AC(e->unk_40);
                sc = (f32)e->unk_44 * sc;
                sc = (f32)e->unk_46 * sc;
                DCFlushRange((void *)e->unk_48, __cvt_fp2unsigned(sc));
                lab_t4 = e->unk_46;
                fn_1_4FD64_call_GXInitTexObj(0, 0, 0, e->unk_40, lab_t4, e->unk_44, (void *)e->unk_48, lbl_1_bss_4E6B0);
                GXInitTexObjLOD(lbl_1_bss_4E6B0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
                fn_80073778(lbl_1_bss_4E6B0, 0);
                fn_1_4EDAC((FontDrawPacket *)e, (f32)e->unk_44, (f32)e->unk_46);
            }
        } else {
            if (*(volatile u32 *)&e->unk_30 & 0x2000000) continue; // volatile: preserve retail's second flags load.
            {
                u32 pk;
                Obj_1_data_FCD4_At20 *q;
                u8 *p1;
                u8 *p2;
                f32 fh;
                f32 fw;
                Obj_1_data_FCD4 *o;
                fn_1_159588(e->unk_0);
                pk = e->unk_0;
                o = (Obj_1_data_FCD4 *)((u8 *)&lbl_1_data_FCD4 + (u16)(pk >> 8) * 0x28);
                if ((s32)o->unk_0 != 0) {
                    q = o->unk_20;
                    p1 = (u8 *)q->unk_4 + ((pk & 0xFF) << 4);
                    p2 = (u8 *)q->unk_C + ((pk & 0xFF) << 5);
                    fw = (f32)*(u16 *)(p1 + 8);
                    fh = (f32)*(u16 *)(p1 + 0xA);
                    fn_80073778(p2, 0);
                    fn_1_4EDAC((FontDrawPacket *)e, fw, fh);
                }
            }
        }
    }
    fn_1_A722C();
    fn_80074918(1, 3, 1);
    lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0 = 0;
}
/* fzgx:end fn_1_4FD64 */

/* fzgx:begin fn_1_50164 */
void fn_1_50164(f32 a, f32 b, f32 c, f32 d) {
    fn_1_50190(a, b, c, c, d, d);
}
/* fzgx:end fn_1_50164 */

/* fzgx:begin fn_1_50190 noprologue */
#include "types.h"
#include "font.h"

struct Pkt88 { u32 words[22]; };

extern const f32 lbl_1_rodata_2750;
extern const f32 lbl_1_rodata_27A4;
extern const f64 lbl_1_rodata_2758;
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

#pragma opt_common_subs off
static inline u32 *fn_1_50190_array_read(u32 *array) { return array; }
#pragma opt_lifetimes off
void fn_1_50190(void *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) {
    struct Pkt88 loc_8;
    s32 sp4;
    struct { f32 value; } temp_f31;
    f32 var_f30;
    f32 temp_f29;
    f32 temp_f28;
    f32 temp_f27;
    f32 temp_f26;
    f32 temp_f25;
    f32 temp_f28_2;
    f32 temp_f30_2;
    struct { f32 value; } half;
    f32 temp_f24;
    f32 temp_f23;
    f32 var_f22;
    f32 temp_f30;
    f32 conv_h;
    u32 temp_r4;
    u32 temp_r0;
    u32 temp_r0_2;

    temp_f23 = (f32) fn_1_48690((u32)(*(u32 *)((u8 *)(arg0) + 0)));
    temp_f24 = ((f32) fn_1_486C4((u32)(*(u32 *)((u8 *)(arg0) + 0))) - farg4) - farg5;
    temp_f25 = (temp_f23 - farg2) - farg3;
    temp_f26 = (farg0 - farg2) - farg3;
    temp_f23 = (farg1 - farg4) - farg5;
    if (farg0 <= lbl_1_rodata_2750 || farg1 <= lbl_1_rodata_2750 || temp_f25 <= lbl_1_rodata_2750 || temp_f24 <= lbl_1_rodata_2750 || temp_f26 <= lbl_1_rodata_2750 || temp_f23 <= lbl_1_rodata_2750 || farg2 < lbl_1_rodata_2750 || farg3 < lbl_1_rodata_2750 || farg4 < lbl_1_rodata_2750 || farg5 < lbl_1_rodata_2750) {
        return;
    }
    {
        temp_r4 = *(u32 *)((u8 *)(arg0) + 48);
        temp_r0 = temp_r4 & 3;
        switch (temp_r0) {
        case 1:
        default:
            var_f22 = *(f32 *)((u8 *)(arg0) + 4);
            break;
        case 2:
            half.value = farg0 * (*(f32 *)((u8 *)(&lbl_1_rodata_27A4) + 0));
            var_f22 = (*(f32 *)((u8 *)(arg0) + 4)) - half.value;
            break;
        case 3:
            var_f22 = (*(f32 *)((u8 *)(arg0) + 4)) - farg0;
            break;
        }
        temp_r0_2 = (temp_r4 >> 2U) & 3;
        switch (temp_r0_2) {
        case 1:
        default:
            var_f30 = *(f32 *)((u8 *)(arg0) + 8);
            break;
        case 2:
            half.value = farg1 * (*(f32 *)((u8 *)(&lbl_1_rodata_27A4) + 0));
            var_f30 = (*(f32 *)((u8 *)(arg0) + 8)) - half.value;
            break;
        case 3:
            var_f30 = (*(f32 *)((u8 *)(arg0) + 8)) - farg1;
            break;
        }
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)(0), (s16)(0), (s16)((s16) farg2), (s16)((s16) farg4));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = var_f22;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = var_f30;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) farg2), (s16)(0), (s16)((s16) temp_f25), (s16)((s16) farg4));
        temp_f29 = temp_f26;
        temp_f29 /= temp_f25;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = var_f30;
        temp_f31.value = var_f22 + farg2;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f31.value;
        (*(f32 *)((u8 *)(&loc_8) + 16)) *= temp_f29;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        temp_f27 = farg2;
        temp_f27 += temp_f25;
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) temp_f27), (s16)(0), (s16)((s16) farg3), (s16)((s16) farg4));
        temp_f26 = temp_f26 + temp_f31.value;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = var_f30;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f26;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)(0), (s16)((s16) farg4), (s16)((s16) farg2), (s16)((s16) temp_f24));
        temp_f28 = temp_f23 / temp_f24;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = var_f22;
        temp_f30 = var_f30 + farg4;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) farg2), (s16)((s16) farg4), (s16)((s16) temp_f25), (s16)((s16) temp_f24));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f31.value;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 16)) *= temp_f29;
        (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) temp_f27), (s16)((s16) farg4), (s16)((s16) farg3), (s16)((s16) temp_f24));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f26;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 20)) *= temp_f28;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        temp_f28_2 = farg4 + temp_f24;
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)(0), (s16)((s16) temp_f28_2), (s16)((s16) farg2), (s16)((s16) farg5));
        temp_f30_2 = temp_f23 + temp_f30;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = var_f22;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30_2;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) farg2), (s16)((s16) temp_f28_2), (s16)((s16) temp_f25), (s16)((s16) farg5));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f31.value;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30_2;
        (*(f32 *)((u8 *)(&loc_8) + 16)) *= temp_f29;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(struct Pkt88 *)(arg0);
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(*(u32 *)((u8 *)(arg0) + 0)), (s16)((s16) temp_f27), (s16)((s16) temp_f28_2), (s16)((s16) farg3), (s16)((s16) farg5));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = temp_f26;
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f30_2;
        fn_1_50190_array_read(loc_8.words)[0xC] &= 0xFFFFFFF0;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
    }
}
#pragma opt_lifetimes reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_50190 */

/* fzgx:begin fn_1_508C4 */
typedef struct fn_1_508C4_FontObject {
    u32 unk0;
    f32 start_x;
    f32 start_y;
    f32 pos_x;
    f32 scale_x;
    f32 scale_y;
    u8 data[0x40];
} fn_1_508C4_FontObject;


#pragma opt_dead_assignments off
#pragma opt_propagation off
void fn_1_508C4(fn_1_508C4_FontObject *obj, f32 dx, f32 dy) {
    fn_1_508C4_FontObject work;
    s32 x;
    s32 y;
    s32 x_start;
    s32 x_end;
    s32 y_end;
    s32 width;
    s32 height;
    s32 y_start;

    x_start = (s32)obj->start_x;
    x_end = (s32)(obj->start_x + dx);
    y_start = (s32)obj->start_y;
    y_end = (s32)(obj->start_y + dy);

    width = (s32)(obj->scale_x * (f32)fn_1_48690(obj->unk0));
    height = (s32)(obj->scale_y * (f32)fn_1_486C4(obj->unk0));

    for (y = y_start; y < y_end; y += height) {
        for (x = x_start; x < x_end; x += width) {
            s32 h;
            s32 w;

            work = *obj;
            h = y_end - y;
            h = h < height ? h : height;
            w = x_end - x;
            w = w < width ? w : width;
            fn_1_51678((FontDrawPacket *)&work, obj->unk0, 0, 0, (s16)w, (s16)h);
            work.start_x = (f32)x;
            work.start_y = (f32)y;
            fn_1_4F734((FontDrawPacket *)&work);
        }
    }
}
#pragma opt_propagation reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_508C4 */

/* fzgx:begin fn_1_50A90 noprologue */
#include "types.h"
#include "font.h"

struct fn_1_50A90_Copy88 { u32 a[22]; };
struct fn_1_50A90_lbl_1_rodata_2758 { f64 unk_0; };
struct fn_1_50A90_lbl_1_rodata_2778 { f64 unk_0; };

extern struct fn_1_50A90_lbl_1_rodata_2758 lbl_1_rodata_2758;
extern struct fn_1_50A90_lbl_1_rodata_2778 lbl_1_rodata_2778;
extern const f32 lbl_1_rodata_2750;
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

#define PF(o) (*(f32 *)((u8 *)&packet + (o)))
#define FLAGS (*(u32 *)((u8 *)&packet + 48))
#define COPY() (packet = *(struct fn_1_50A90_Copy88 *)arg0)
#define SETUP(a,b,c,d) fn_1_51678((FontDrawPacket *)&packet, *(u32 *)arg0, (s16)(a), (s16)(b), (s16)(c), (s16)(d))
#define DRAW() fn_1_4F734((FontDrawPacket *)&packet)

#pragma opt_lifetimes off
void fn_1_50A90(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 v6;
    u32 v4;
    s32 v0;
    u32 v1;
    u32 v3;
    u32 v2;
    u32 v5;
    f32 texRight;
    f32 rightX;
    f32 bottomY;
    f32 innerX;
    f32 innerY;
    f32 endTex;
    f32 v13;
    f32 ratioY;
    f32 endTexY;
    f32 v8;
    f64 v7;
    u32 v9;
    u32 v10;
    u32 v11;
    f64 v12;
    f32 v14;
    f32 v15;
    f32 v16;
    f32 v17;
    f32 v18;
    f32 y;
    f32 texBottom;
    f32 ratioX;
    f32 remainderY;
    f32 posX;
    f32 posRX;
    f32 posY;
    f32 posRY;
    s16 i;
    s16 count;
    struct fn_1_50A90_Copy88 packet;
    u16 t0;
    u16 t1;
    v0 = ((s32)((-arg1) & ~arg1) >> 31);
    v1 = (arg1 & v0);
    v2 = (v1 << 1);
    v3 = (arg2 & ((s32)((-arg2) & ~arg2) >> 31));
    v4 = v2;
    if ((s32)arg3 > (s32)v2) {
        v4 = arg3;
    }
    v5 = (v3 << 1);
    v6 = v5;
    if ((s32)arg4 > (s32)v5) {
        v6 = arg4;
    }
    t0 = fn_1_48690(*(u32 *)((u8 *)arg0 + 0));
    v7 = lbl_1_rodata_2758.unk_0;
    v8 = (f32)(u32)(t0 & 0xFFFF);
    t1 = fn_1_486C4(*(u32 *)((u8 *)arg0 + 0));
    v9 = (t1 & 0xFFFF);
    v10 = *(u32 *)((u8 *)arg0 + 48);
    v11 = (v10 & 0x3);
    v12 = lbl_1_rodata_2778.unk_0;
    v13 = (f32)(u32)v9;
    v14 = (f32)(v8 - (f32)(s32)v2);
    v15 = (f32)(v13 - (f32)(s32)v5);
    v16 = (f32)(s32)(v4 - v2);
    v17 = (f32)(s32)(v6 - v5);
    switch (v11) {
    case 1:
    default: v18 = *(f32 *)((u8 *)arg0 + 4); break;
    case 2: v18 = *(f32 *)((u8 *)arg0 + 4) - (f32)((s32)v4 / 2); break;
    case 3: v18 = *(f32 *)((u8 *)arg0 + 4) - (f32)(s32)v4; break;
    }
    switch ((v10 >> 2) & 3) {
    case 1:
    default: y = *(f32 *)((u8 *)arg0 + 8); break;
    case 2: y = *(f32 *)((u8 *)arg0 + 8) - (f32)((s32)v6 / 2); break;
    case 3: y = *(f32 *)((u8 *)arg0 + 8) - (f32)(s32)v6; break;
    }
    COPY();
    SETUP(0, 0, (s16)v1, (s16)v3);
    PF(4) = v18;
    PF(8) = y;
    FLAGS &= ~15;
    DRAW();

    COPY();
    texRight = v8 - (f32)(s32)v1;
    SETUP((s16)texRight, 0, (s16)v1, (s16)v3);
    innerX = v18 + (f32)(s32)v1;
    rightX = v16 + innerX;
    PF(4) = rightX;
    PF(8) = y;
    FLAGS &= ~15;
    DRAW();

    COPY();
    texBottom = v13 - (f32)(s32)v3;
    SETUP(0, (s16)texBottom, (s16)v1, (s16)v3);
    innerY = y + (f32)(s32)v3;
    bottomY = v17 + innerY;
    PF(4) = v18;
    PF(8) = bottomY;
    FLAGS &= ~15;
    DRAW();

    COPY();
    SETUP((s16)texRight, (s16)texBottom, (s16)v1, (s16)v3);
    PF(4) = rightX;
    PF(8) = bottomY;
    FLAGS &= ~15;
    DRAW();

    COPY();
    SETUP((s16)v1, (s16)v3, (s16)v14, (s16)v15);
    ratioX = v16 / v14;
    ratioY = v17 / v15;
    PF(4) = innerX;
    PF(8) = innerY;
    FLAGS &= ~15;
    PF(16) *= ratioX;
    PF(20) *= ratioY;
    DRAW();

    if (lbl_1_rodata_2750 != v16) {
        count = (s16)ratioX;
        i = 0;
        endTex = (f32)(s32)v3 + v15;
        while (i < count) {
            COPY();
            SETUP((s16)v1, 0, (s16)v14, (s16)v3);
            posX = innerX + (f32)((f32)i * v14);
            PF(4) = posX;
            PF(8) = y;
            FLAGS &= ~15;
            DRAW();
            COPY();
            SETUP((s16)v1, (s16)endTex, (s16)v14, (s16)v3);
            PF(4) = posX;
            PF(8) = bottomY;
            FLAGS &= ~15;
            DRAW();
            i++;
        }
        texRight = v16 - (f32)(v14 * (f32)count);
        COPY();
        SETUP((s16)v1, 0, (s16)texRight, (s16)v3);
        posRX = innerX + (f32)((f32)i * v14);
        PF(4) = posRX;
        PF(8) = y;
        FLAGS &= ~15;
        DRAW();
        COPY();
        SETUP((s16)v1, (s16)endTex, (s16)texRight, (s16)v3);
        PF(4) = posRX;
        PF(8) = bottomY;
        FLAGS &= ~15;
        DRAW();
    }
    if (lbl_1_rodata_2750 != v17) {
        s16 iY;
        s16 countY;
        countY = (s16)ratioY;
        iY = 0;
        endTexY = (f32)(s32)v1 + v14;
        while (iY < countY) {
            COPY();
            SETUP(0, (s16)v3, (s16)v1, (s16)v15);
            posY = innerY + (f32)((f32)iY * v15);
            PF(4) = v18;
            PF(8) = posY;
            FLAGS &= ~15;
            DRAW();
            COPY();
            SETUP((s16)endTexY, (s16)v3, (s16)v1, (s16)v15);
            PF(4) = rightX;
            PF(8) = posY;
            FLAGS &= ~15;
            DRAW();
            iY++;
        }
        remainderY = v17 - (f32)(v15 * (f32)countY);
        COPY();
        SETUP(0, (s16)v3, (s16)v1, (s16)remainderY);
        posRY = innerY + (f32)((f32)iY * v15);
        PF(4) = v18;
        PF(8) = posRY;
        FLAGS &= ~15;
        DRAW();
        COPY();
        SETUP((s16)endTexY, (s16)v3, (s16)v1, (s16)remainderY);
        PF(4) = rightX;
        PF(8) = posRY;
        FLAGS &= ~15;
        DRAW();
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_50A90 */

/* fzgx:begin fn_1_51564 */
// Update the six halfwords that define the active font state.
void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth) {
    ((u16 *)&lbl_1_bss_4C678)[0xC02e] = first;
    ((u16 *)&lbl_1_bss_4C678)[0xC02f] = second;
    ((u16 *)&lbl_1_bss_4C678)[0xC030] = third;
    ((u16 *)&lbl_1_bss_4C678)[0xC031] = fourth;
    ((u16 *)&lbl_1_bss_4C678)[0xC032] = fifth;
    ((u16 *)&lbl_1_bss_4C678)[0xC033] = sixth;
}
/* fzgx:end fn_1_51564 */

/* fzgx:begin fn_1_5158C noprologue */
#include "dolphin/types.h"
#include "rel/main_rel/font.h"

typedef struct FontDrawPacket FontDrawPacket;

extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);

static inline int in_range(int value, int lower, int upper)
{
    if (value > upper) {
        return 0;
    }
    return value >= lower;
}

static inline int clamp(int value, int lower, int upper)
{
    int result = value;
    if (value < lower) {
        result = lower;
    } else if (result > upper) {
        result = upper;
    }
    return result;
}

void fn_1_5158C(FontDrawPacket *packet, u32 color, s16 x, s16 y)
{
    s16 *state = (s16 *)((u8 *)&lbl_1_bss_4C678 + 0x20000);
    int max_x = state[-0x7f9c / 2] - 1;
    int max_y;
    int coordinate = x;
    if (!in_range(coordinate, 0, max_x)) {
        if (x < 0) {
            coordinate = 0;
        } else if (coordinate > max_x) {
            coordinate = max_x;
        }
        x = coordinate;
    }
    max_y = state[-0x7f9a / 2] - 1;
    coordinate = y;
    if (!in_range(coordinate, 0, max_y)) {
        if (y < 0) {
            coordinate = 0;
        } else if (coordinate > max_y) {
            coordinate = max_y;
        }
        y = coordinate;
    }
    fn_1_51678(packet, color, state[-0x7fa4 / 2] + x * state[-0x7fa0 / 2],
        state[-0x7fa2 / 2] + y * state[-0x7f9e / 2],
        state[-0x7fa0 / 2], state[-0x7f9e / 2]);
}
/* fzgx:end fn_1_5158C */

/* fzgx:begin fn_1_51678 */
void fn_1_51678(FontDrawPacket *p, u32 image, s16 x, s16 y, s16 width, s16 height) {
    f32 inv_height, inv_width;
    s32 texture_height, texture_width;
    p->image = image;
    texture_height = (s16)fn_1_486C4(image);
    texture_width = (s16)fn_1_48690(image);
    inv_width = 1.0f / texture_width;
    inv_height = 1.0f / texture_height;
    {
        f32 v, u, sy, sx;
        sx = (f32)width * inv_width;
        sy = (f32)height * inv_height;
        u = (f32)x * inv_width;
        v = (f32)y * inv_height;
        p->scale_x *= sx;
        p->scale_y *= sy;
        p->u0 = u;
        p->v0 = v;
    }
    p->u1 = inv_width * (f32)(x + width);
    p->v1 = inv_height * (f32)(y + height);
}
/* fzgx:end fn_1_51678 */

/* fzgx:begin fn_1_517EC */
void fn_1_517EC(FontDrawPacket *p, s16 x, s16 y, s16 width, s16 height, s16 texture_width, s16 texture_height) { f32 inv_height, inv_width;
    inv_width = 1.0f / texture_width;
    inv_height = 1.0f / texture_height;
    p->scale_x *= (f32)width * inv_width;
    p->scale_y *= (f32)height * inv_height;
    p->u0 = (f32)x * inv_width;
    p->v0 = (f32)y * inv_height;
    p->u1 = inv_width * (f32)(x + width);
    p->v1 = inv_height * (f32)(y + height);
}
/* fzgx:end fn_1_517EC */

/* fzgx:begin fn_1_51914 */
extern Obj_1_bss_646D2 lbl_1_bss_4E6D0__fzgx_offset_16002;
typedef struct {
    u32 words[22];
} fn_1_51914_state;


void fn_1_51914(const fn_1_51914_state *src) {
    fn_1_51914_state state = *src;

    lbl_1_bss_4C678 = (u32)lbl_1_data_1C504 +
        (u32)lbl_1_bss_4E6D0__fzgx_offset_16002.unk_0 * 0x58;
    state.words[12] |= 0x2000000;
    fn_1_4F734( (FontDrawPacket *)(void *)(&state));
}
/* fzgx:end fn_1_51914 */

/* fzgx:begin fn_1_51990 */
// Copy the font state value and enable the corresponding object flag.
void fn_1_51990(void *obj) {
    *(u32 *)((u8 *)obj + 0x4c) = lbl_1_bss_4C678;
    *(u32 *)((u8 *)obj + 0x30) |= 0x01000000;
}
/* fzgx:end fn_1_51990 */

/* fzgx:begin fn_1_519AC */
struct fn_1_519AC_lbl_1_rodata_26F8 {
    u8 pad_0[0x58];
    f32 unk_58;
    f32 unk_5C;
    u8 pad_60[0x4C];
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
};



f32 fn_1_519AC(u32 value) {
    struct fn_1_519AC_lbl_1_rodata_26F8 *base = &(*(struct fn_1_519AC_lbl_1_rodata_26F8 *)&lbl_1_rodata_26F8);

    switch (value) {
    case 0:
    case 14:
        return base->unk_AC;
    case 1:
    case 2:
    case 17:
        return base->unk_5C;
    case 3:
    case 4:
    case 5:
    case 19:
        return base->unk_B0;
    case 6:
    case 22:
        return base->unk_B4;
    default:
        return base->unk_58;
    }
}
/* fzgx:end fn_1_519AC */

/* fzgx:begin fn_1_519FC */
typedef struct {
    f32 width;
    u8 pad0[4];
    f32 height;
    u8 pad1[8];
} FontViewport;

f32 fn_1_519FC(f32 value) {
    FontViewport viewport;
    f32 width;
    f32 height;

    fn_80038F10( (f32*)(void *)(&viewport));

    width = viewport.width;
    height = viewport.height;

    return value * height / (f32)(u32)fn_1_A5D88()
         + lbl_1_rodata_2770 * width / (f32)(u32)fn_1_A5D88();
}
/* fzgx:end fn_1_519FC */

/* fzgx:begin fn_1_51AC0 */
typedef struct {
    u8 unk0[4];
    f32 value0;
    u8 unk10[4];
    f32 value1;
    u8 tail[8];
} FnData;

f32 fn_1_51AC0(f32 value) {
    f32 input = value;
    f32 value0;
    f32 value1;
    f32 part;
    f32 denom;
    f32 result;
    FnData data;
    u64 padding;

    fn_80038F10( (f32*)(void *)(&data));
    value0 = data.value0;
    value1 = data.value1;
    denom = (f32)((u32)fn_1_A5DB0() & 0xffff);
    part = lbl_1_rodata_276C * value0 / denom;
    denom = (f32)((u32)fn_1_A5DB0() & 0xffff);
    result = input * value1 / denom;
    return result + part;
}
/* fzgx:end fn_1_51AC0 */

/* fzgx:begin fn_1_51B84 */
typedef struct Fn151B84Tmp {
    u8 unk[8];
    f32 value;
    u8 rest[12];
} Fn151B84Tmp;

f32 fn_1_51B84(f32 value) {
    Fn151B84Tmp tmp;
    f32 factor;
    f32 input;
    input = value;
    fn_80038F10( (f32*)(void *)(&tmp));
    factor = tmp.value;
    return input * factor / (f32)fn_1_A5D88();
}
/* fzgx:end fn_1_51B84 */

/* fzgx:begin fn_1_51BFC */
typedef struct {
    u8 pad[0x0c];
    f32 value;
    u8 tail[8];
} Fn51BFCData;

f32 fn_1_51BFC(f32 value) {
    Fn51BFCData data;
    f32 factor;
    u32 count;

    fn_80038F10( (f32*)(void *)(&data));
    factor = data.value;
    return value * factor / (f32)((u32)fn_1_A5DB0() & 0xffff);
}
/* fzgx:end fn_1_51BFC */

/* fzgx:begin fn_1_51C74 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

typedef struct {
    Vec4 value;
    u32 pad[2];
} Temp;


typedef struct {
    u8 pad0[0xc];
    f32 x;
    f32 y;
    u8 pad1[4];
    f32 z;
    f32 w;
} fn_1_51C74_FontData;

void fn_1_51C74(fn_1_51C74_FontData *obj) {
    f32 a0;
    f32 fzgx_live;
    f32 fzgx_live_;
    f32 fzgx_live__;
    Temp t0;
    Temp t1;
    Temp t2;
    f32 a1;
    Temp t3;
    struct { f32 value; } x;
    f32 b1;
    f32 w;
    struct { f32 value; } b0;
    f32 fzgx_live___;
    f32 y;
    f32 b2;
    f32 a2;

    fzgx_live___ = obj->x;
    fzgx_live = fzgx_live___;
    x.value = fzgx_live;
    fn_80038F10( (f32*)(Vec4 *)(&t0.value));
    fzgx_live__ = t0.value.x;
    fzgx_live_ = fzgx_live__;
    a0 = fzgx_live_;
{
    f32 z;
    b0.value = t0.value.z;
    obj->x = ((((x.value)) * ((b0.value)))) / (f32)((u32)fn_1_A5D88() & 0xffff)
        + lbl_1_rodata_2770 * a0 / (f32)((u32)fn_1_A5D88() & 0xffff);

    y = obj->y;
    fn_80038F10( (f32*)(Vec4 *)(&t1.value));
    a1 = t1.value.y;
    b1 = t1.value.w;
    obj->y = ((y) * (b1)) / (f32)((u32)fn_1_A5DB0() & 0xffff)
        + lbl_1_rodata_276C * a1 / (f32)((u32)fn_1_A5DB0() & 0xffff);

    z = obj->z;
    fn_80038F10( (f32*)(Vec4 *)(&t2.value));
    a2 = t2.value.z;
    obj->z = z * a2 / (f32)((u32)fn_1_A5D88() & 0xffff);
}

    w = obj->w;
    fn_80038F10( (f32*)(Vec4 *)(&t3.value));
    b2 = t3.value.w;
    obj->w = w * b2 / (f32)((u32)fn_1_A5DB0() & 0xffff);
}



/* fzgx:end fn_1_51C74 */

/* fzgx:begin fn_1_51E60 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"
#include "types.h"
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
extern u32 fn_1_54298(void);
extern u32 fn_1_542A8(void);
extern f32 fn_1_542B8(void);
extern f32 fn_1_4B1D4(s32 mode, s32 value);
extern const f64 lbl_1_rodata_10F8;
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_FD0[];
extern u8 *lbl_801A66CC;
extern const f32 lbl_1_rodata_2870;
extern const f64 lbl_1_rodata_2878;
extern void lbl_8006E1B0();
extern f32 lbl_8006D0B4(f32 value);
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_55C48(void);
extern u16 fn_1_7BE94(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_1_56530(void);
extern void lbl_8006DB74(void *value);
extern void lbl_8006DD14(void *value, void *object);
extern void fn_1_4E500(void);
extern void fn_1_48D80(void *value);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(FontParams *arg);
extern s32 fn_1_4B16C(s32 value);
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
extern u32 fn_1_54320(void);
extern void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse);
extern void fn_1_547F8(fn_1_547F8_node *node);
extern u32 fn_1_5448C();
extern void fn_1_563E4(fn_1_563E4_FontState *font);
extern void fn_80074B40(u8 *arg0);
extern void fn_80077B04(f32 value);
extern void fn_80071ED4(u8 value, f32 x, f32 y);
extern void fn_80072014(u32 *value);
extern void fn_80074C74(u8 *arg0);
extern void fn_80077BBC(s32 arg0);
extern void fn_80037D40(u8 a, u8 b);
extern u32 fn_80074A7C();
extern u32 fn_80077BAC();
extern const f32 lbl_1_rodata_10D4;
extern void fn_1_4955C(f32 value1, f32 value2);
extern f32 lbl_1_rodata_10C0[5];
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern f32 lbl_1_rodata_26B8[16];
extern void fn_1_4D10C(void *data, f32 scale, f32 value);
extern void fn_1_4D2AC(void *data, f32 scale, f32 value);
extern s32 fn_1_3F164(void);
extern f32 lbl_1_rodata_26F8[22];
extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_1_50190(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
extern void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2);
extern void *fn_1_541A8(void *arg, s32 column);
extern u32 lbl_801A66B4;
extern void fn_1_9FA18(void);
extern void fn_1_58248(void);
extern void fn_1_54848(void);
extern void fn_800794F0(u8 *data, void *value, s32 size);
extern s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2);
extern void fn_1_55210(void *value);
extern const f32 lbl_1_rodata_28A8;
extern void fn_1_557C4(void *value);
extern void fn_1_556B8(void *value);
extern void fn_80077E7C(void *value);
extern void fn_80077F8C(void *value);
extern void fn_80074CF4();
extern void fn_800749B0(s32 arg0, void *arg1);
extern const f32 lbl_1_rodata_28AC;
extern u8 lbl_1_bss_6C7DC[100];
extern u8 *fn_1_565E8(void);
extern void fn_1_45730(void);
extern void fn_1_45B2C(void);
extern void fn_1_458A0(void);
extern void fn_1_45850(void);
extern void fn_1_565F4(void);
extern void fn_80070D60(void *);
extern s32 fn_1_A5DC4();
extern f32 lbl_1_rodata_2788[6];
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern f32 fn_1_51B84(f32 value);
extern f32 fn_1_51BFC(f32 value);
extern const f64 lbl_1_rodata_2758;
extern void lbl_8006D784(void *arg);
extern void fn_1_55D6C(void);


extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern void fn_80038F10(f32 *viewport);

static inline f32 fn_1_51E60_x(f32 x) {
    f32 viewport[6];
    f32 left;
    f32 width;

    fn_80038F10(viewport);
    left = viewport[0];
    width = viewport[2];
    return x * width / fn_1_A5D88() + 640.0f * left / fn_1_A5D88();
}

static inline f32 fn_1_51E60_y(f32 y) {
    f32 viewport[6];
    f32 top;
    f32 height;

    fn_80038F10(viewport);
    top = viewport[1];
    height = viewport[3];
    return y * height / fn_1_A5DB0() + 480.0f * top / fn_1_A5DB0();
}

static inline f32 fn_1_51E60_w(f32 w) {
    f32 viewport[6];
    f32 width;

    fn_80038F10(viewport);
    width = viewport[2];
    return w * width / fn_1_A5D88();
}

static inline f32 fn_1_51E60_h(f32 h) {
    f32 viewport[6];
    f32 height;

    fn_80038F10(viewport);
    height = viewport[3];
    return h * height / fn_1_A5DB0();
}

void fn_1_51E60(FontDrawPacket *src) {
    FontDrawPacket packet;

    packet = *src;
    packet.x = fn_1_51E60_x(packet.x);
    packet.y = fn_1_51E60_y(packet.y);
    packet.scale_x = fn_1_51E60_w(packet.scale_x);
    packet.scale_y = fn_1_51E60_h(packet.scale_y);
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_51E60 */

/* fzgx:begin fn_1_52070 */
void fn_1_52070(u32 value) {
    lbl_1_bss_4E6A8 = 1;
    lbl_1_bss_4E6AC = value;
}
/* fzgx:end fn_1_52070 */

/* fzgx:begin fn_1_52088 */
void fn_1_52088(void) {
    lbl_1_bss_4E6A8 = 0;
    lbl_1_bss_4E6AC = 0;
}
/* fzgx:end fn_1_52088 */

/* fzgx:begin fn_1_520A0 */
void fn_1_520A0(void) {
    u32 value_a;
    u32 value_b;

    value_a = lbl_1_bss_4E6A8;
    value_b = lbl_1_bss_4E6AC;
    lbl_1_bss_646E0 = value_a;
    lbl_1_bss_646E4 = value_b;
}
/* fzgx:end fn_1_520A0 */

/* fzgx:begin fn_1_520CC */
void fn_1_520CC(void) {
    u32 value_a;
    u32 value_b;

    value_a = lbl_1_bss_646E0;
    value_b = lbl_1_bss_646E4;
    lbl_1_bss_4E6A8 = value_a;
    lbl_1_bss_4E6AC = value_b;
}
/* fzgx:end fn_1_520CC */

/* fzgx:begin fn_1_520F8 */
f32 fn_1_520F8(s32 value) {
    s32 base;
    f32 scaled;

    if ((s8)fn_1_A5DC4(value) && (*(s32 *)&lbl_1_bss_4E6A8) != 0) {
        base = (*(s32 *)&lbl_1_bss_4E6AC);
        scaled = (f32)(value - base) * lbl_1_rodata_2788[0];
        return (f32)base + scaled;
    }
    return (f32)value;
}
/* fzgx:end fn_1_520F8 */

/* fzgx:begin fn_1_521B8 */
// Convert a font value to its scaled coordinate when the font system is active.
f32 fn_1_521B8(s32 value) {
    if ((s8)fn_1_A5DC4(value) && (s32)lbl_1_bss_4E6A8 != 0) {
        return lbl_1_rodata_2788[0] * (f32)value;
    }

    return (f32)value;
}
/* fzgx:end fn_1_521B8 */

/* fzgx:begin fn_1_52250 */
struct fn_1_52250_Arg0 {
    u8 pad_0[0x54];
    f32 unk_54;
};

struct fn_1_52250_Arg1 {
    f32 unk_0;
    u8 pad_4[0x8];
    f32 unk_C;
};

void fn_1_52250(struct fn_1_52250_Arg0 *arg0, struct fn_1_52250_Arg1 *arg1) {
    f32 addend;
    f32 current;

    current = arg1->unk_0;
    addend = arg0->unk_54;
    current = current + addend;
    arg1->unk_0 = current;
    current = arg1->unk_C;
    current = current + addend;
    arg1->unk_C = current;
}
/* fzgx:end fn_1_52250 */

/* fzgx:begin fn_1_52270 noprologue */
#include "types.h"
#include "font.h"

struct Color {
    u8 r, g, b, a;
};

extern void fn_800371F8(s32 id, struct Color color);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* __restrict lets MWCC load the packet fields before the LR save, as retail does */
void fn_1_52270(FontDrawPacket * __restrict packet) {
    struct Color add;
    struct Color color;

    color.r = packet->color[0];
    color.g = packet->color[1];
    color.b = packet->color[2];
    color.a = 255.0f * packet->alpha;
    add.r = packet->color_add[0];
    add.g = packet->color_add[1];
    add.b = packet->color_add[2];
    add.a = 0;
    fn_800371F8(1, color);
    fn_800371F8(2, add);
    fn_80072C24(0, 4, 2, 8, 15);
    fn_80072CC4(0, 7, 7, 7, 1);
}
/* fzgx:end fn_1_52270 */

/* fzgx:begin fn_1_5233C noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"
#include "sdk_addresses.h"
#include "types.h"

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
extern u32 fn_1_54298(void);
extern u32 fn_1_542A8(void);
extern f32 fn_1_542B8(void);
extern f32 fn_1_4B1D4(s32 mode, s32 value);
extern const f64 lbl_1_rodata_10F8;
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_FD0[];
extern u8 *lbl_801A66CC;
extern const f32 lbl_1_rodata_2870;
extern const f64 lbl_1_rodata_2878;
extern void lbl_8006E1B0();
extern f32 lbl_8006D0B4(f32 value);
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_55C48(void);
extern u16 fn_1_7BE94(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_1_56530(void);
extern void lbl_8006DB74(void *value);
extern void lbl_8006DD14(void *value, void *object);
extern void fn_1_4E500(void);
extern void fn_1_48D80(void *value);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(FontParams *arg);
extern s32 fn_1_4B16C(s32 value);
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
extern u32 fn_1_54320(void);
extern void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse);
extern void fn_1_547F8(fn_1_547F8_node *node);
extern u32 fn_1_5448C();
extern void fn_1_563E4(fn_1_563E4_FontState *font);
extern void fn_80074B40(u8 *arg0);
extern void fn_80077B04(f32 value);
extern void fn_80071ED4(u8 value, f32 x, f32 y);
extern void fn_80072014(u32 *value);
extern void fn_80074C74(u8 *arg0);
extern void fn_80077BBC(s32 arg0);
extern void fn_80037D40(u8 a, u8 b);
extern u32 fn_80074A7C();
extern u32 fn_80077BAC();
extern const f32 lbl_1_rodata_10D4;
extern void fn_1_4955C(f32 value1, f32 value2);
extern f32 lbl_1_rodata_10C0[5];
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern f32 lbl_1_rodata_26B8[16];
extern void fn_1_4D10C(void *data, f32 scale, f32 value);
extern void fn_1_4D2AC(void *data, f32 scale, f32 value);
extern s32 fn_1_3F164(void);
extern f32 lbl_1_rodata_26F8[22];
extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_1_50190(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
extern void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2);
extern void *fn_1_541A8(void *arg, s32 column);
extern u32 lbl_801A66B4;
extern void fn_1_9FA18(void);
extern void fn_1_58248(void);
extern void fn_1_54848(void);
extern void fn_800794F0(u8 *data, void *value, s32 size);
extern s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2);
extern void fn_1_55210(void *value);
extern const f32 lbl_1_rodata_28A8;
extern void fn_1_557C4(void *value);
extern void fn_1_556B8(void *value);
extern void fn_80077E7C(void *value);
extern void fn_80077F8C(void *value);
extern void fn_80074CF4();
extern void fn_800749B0(s32 arg0, void *arg1);
extern const f32 lbl_1_rodata_28AC;
extern u8 lbl_1_bss_6C7DC[100];
extern u8 *fn_1_565E8(void);
extern void fn_1_45730(void);
extern void fn_1_45B2C(void);
extern void fn_1_458A0(void);
extern void fn_1_45850(void);
extern void fn_1_565F4(void);
extern void fn_80070D60(void *);
extern s32 fn_1_A5DC4();
extern f32 lbl_1_rodata_2788[6];
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern f32 fn_1_51B84(f32 value);
extern f32 fn_1_51BFC(f32 value);
extern const f64 lbl_1_rodata_2758;
extern void lbl_8006D784(void *arg);
extern void fn_1_55D6C(void);


struct fn_1_5233C_Copy88 { u32 a[22]; };
struct ShadowEntry { u32 color; f32 x, y; };
struct ShadowTable { struct ShadowEntry e[9]; };
struct Color { u8 r,g,b,a; };
extern u32 lbl_1_rodata_27B0;
extern f32 lbl_1_rodata_2764[2];
extern u32 fn_800371F8(u32, void *);
extern void fn_8003462C(u32, u32, u32);
#define FIFO (*(volatile f32 *)FZGX_ADDR___GXFifo) /* GX write-gather FIFO */
static inline void pos(f32 x, f32 y, f32 z) { FIFO=x; FIFO=y; FIFO=z; }
static inline f32 xy(f32 x, f32 y, f32 bias) { FIFO=x; FIFO=y; return bias; }
#define VERT(X,Y,U,V) pos((X),(Y),z); FIFO=(U); FIFO=(V)
void fn_1_5233C(void *arg0, void *arg1) {
    struct ShadowTable table;
    struct fn_1_5233C_Copy88 copy;
    struct Color color;
    u32 c0;
    struct Color c1;
    struct ShadowEntry *entry;
    f32 dx,dy,z,v0,u1,u0,v1;
    f32 bias;
    f32 *p = (f32 *)arg1;
    table = *(struct ShadowTable *)&lbl_1_rodata_27B0;
    entry = &table.e[(u32)*(f32 *)((u8 *)arg0+0x54)];
    if (!(*(u32 *)((u8 *)arg0+0x30) & 0x10000000)) {
        copy = *(struct fn_1_5233C_Copy88 *)arg0;
        c0 = entry->color;
        dx = entry->x;
        dy = entry->y;
        fn_800371F8(2, &c0);
        fn_8003462C(0x80,7,16);
        xy(p[0],p[1]-dy,0.0f);
        z = -(0.1f+*(f32 *)((u8 *)&copy+0xc)); FIFO=z;
        u0=*(f32 *)((u8 *)&copy+0x18); FIFO=u0;
        v0=*(f32 *)((u8 *)&copy+0x1c); FIFO=v0;
        pos(p[3],p[4]-dy,z);
        u1=*(f32 *)((u8 *)&copy+0x20); FIFO=u1; FIFO=v0;
        pos(p[9],p[10]-dy,z); FIFO=u1;
        v1=*(f32 *)((u8 *)&copy+0x24); FIFO=v1;
        VERT(p[6],p[7]-dy,u0,v1);
        VERT(p[0],p[1]+dy,u0,v0);
        VERT(p[3],p[4]+dy,u1,v0);
        VERT(p[9],p[10]+dy,u1,v1);
        VERT(p[6],p[7]+dy,u0,v1);
        color.a=0;
        VERT(p[0]-dx,p[1],u0,v0);
        VERT(p[3]-dx,p[4],u1,v0);
        VERT(p[9]-dx,p[10],u1,v1);
        VERT(p[6]-dx,p[7],u0,v1);
        VERT(p[0]+dx,p[1],u0,v0);
        VERT(p[3]+dx,p[4],u1,v0);
        VERT(p[9]+dx,p[10],u1,v1);
        VERT(p[6]+dx,p[7],u0,v1);
        color.r=*((u8 *)&copy+0x38);
        color.g=*((u8 *)&copy+0x39);
        color.b=*((u8 *)&copy+0x3a);
        c1=color;
        fn_800371F8(2,&c1);
    }
}
/* fzgx:end fn_1_5233C */

/* fzgx:begin fn_1_52690 noprologue */
#include "types.h"
#include "font.h"

extern u8 lbl_1_bss_646E8[40];
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(void *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void fn_80073778(void *obj, s32 index);

/* __restrict lets MWCC load the packet fields before the LR save, as retail does */
void fn_1_52690(FontDrawPacket * __restrict packet) {
    u32 width = packet->width, height = packet->height;

    GXInitTexObj(lbl_1_bss_646E8, packet->pixels, width, height, packet->format, 0, 0, 0);
    GXInitTexObjLOD(lbl_1_bss_646E8, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0);
    fn_80073778(lbl_1_bss_646E8, 0);
}
/* fzgx:end fn_1_52690 */

/* fzgx:begin fn_1_52718 noprologue */
#include "types.h"
#include "font.h"

struct Color {
    u8 r, g, b, a;
};

extern void fn_800371F8(s32 id, struct Color color);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

/* __restrict lets MWCC load the packet fields before the LR save, as retail does */
void fn_1_52718(FontDrawPacket * __restrict packet) {
    struct Color color;

    color.r = packet->color[0];
    color.g = packet->color[1];
    color.b = packet->color[2];
    color.a = 255.0f * packet->alpha;
    fn_800371F8(1, color);
    fn_800371F8(2, *(struct Color *)packet->color_add);
    fn_800728A8(1, 1, 1, 0);
}
/* fzgx:end fn_1_52718 */

/* fzgx:begin fn_1_527B4 */
typedef struct {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 pad_C[0x4];
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x10];
    s16 unk_28;
} FontState;

typedef struct {
    u8 pad_0[0x20];
    Obj_1_data_FCD4_At20 *unk_20;
    u8 pad_24[0x4];
} FontTableEntry;


void fn_1_527B4(void) {
    u8 scratch[0x30];
    FontState *state;
    FontTableEntry *entry;
    Obj_1_data_FCD4_At20 *obj;
    u32 value;
    u32 index;

    state = (FontState *)lbl_1_bss_4C678;
    if (state != 0) {
        fn_80074918(1, 3, 1);
        lbl_8006D7F4(state->unk_4, state->unk_8, lbl_1_rodata_2750);
        lbl_8006E15C(state->unk_10, state->unk_14, lbl_1_rodata_2754);
        mathutil_mtxA_rotate_z(state->unk_28);
        lbl_8006DD7C();
        lbl_8006DB74(&scratch[0]);
        fn_800745A4(1, 1, 4, 0x21, 0, 0x7d);
        GXLoadTexMtxImm( (u32)(void *)(&scratch[0]), 0x21, 1);
        value = state->unk_0;
        index = ((value >> 8) & 0xffff) * 0x28;
        entry = (FontTableEntry *)&lbl_1_data_FCD4;
        entry = (FontTableEntry *)((u8 *)entry + index);
        obj = entry->unk_20;
        if (lbl_1_rodata_2750 == state->unk_10 ||
            lbl_1_rodata_2750 == state->unk_14 ||
            obj == 0) {
            return;
        }
        fn_80073778((void *)((u8 *)obj->unk_C + ((value & 0xff) << 5)), 1);
    }
    fn_80074660(2);
    fn_80073678(2);
    fn_80073C6C(1);
    fn_800734A8(1, 1, 1, 0xff);
    fn_80072C24(0, 0xf, 0xf, 0xf, 0xf);
    fn_80072C24(1, 4, 0xc, 8, 0xf);
    fn_80072D64(1, 0, 0, 0, 1, 0);
    fn_80072CC4(1, 7, 7, 7, 0);
    fn_80072E20(1, 0, 0, 0, 1, 0);
}
/* fzgx:end fn_1_527B4 */

/* fzgx:begin fn_1_52968 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    s = 0.0f;
}
static const unsigned long fzgx_pool_table2[1] = {0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
}
static const unsigned long fzgx_pool_table4[19] = {0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 55.0f;
    s = 0.10000000149011612f;
    s = 90000.0f;
    s = 480.0f;
    s = 640.0f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.5;
    s = 0.75f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.002405626;
    s = 320.0f;
    s = 240.0f;
    s = 255.0f;
    s = 0.5f;
    s = 2.0f;
    s = 4.0f;
}
static const unsigned long fzgx_pool_table10[27] = {0x00000000, 0x40000000, 0x40000000, 0x00000000, 0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000, 0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00, 0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000, 0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern u32 lbl_801A66B4;
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_49738(u32 value);
extern void fn_1_4954C(f32 value);
extern void fn_1_52B68(void *arg0, void *arg1);
extern void fn_1_52B8C(void *arg0, void *arg1);
extern void fn_1_52BB0(void *arg0, void *arg1);
extern void fn_1_52BD4(void *arg0, void *arg1);
extern void fn_1_530C8(void *arg0);

// Draw formatted text as four rotated layers (one vertex callback each, each
// slightly deeper), then the top layer through fn_1_530C8 unless mode 5.
void fn_1_52968(s32 x, s32 y, f32 depth, const char *format, ...) {
    char buffer[4096];
    __va_list args;
    void (*callbacks[4])(void *, void *) = { fn_1_52B68, fn_1_52B8C, fn_1_52BB0, fn_1_52BD4 };
    u32 i;
    f32 step;

    __builtin_va_info(&args);
    fn_8008077C((u32)(char *)buffer, (u32)format, (u32)&args);

    for (i = 0; i < 4; i++) {
        fn_1_496FC((f32)x, (f32)y);
        fn_1_49738((u32)callbacks[i]);
        step = 0.1f * (f32)(s32)i;
        fn_1_4954C(depth + step);
        fn_1_4A0D8(buffer);
    }

    if ((s32)lbl_801A66B4 != 5) {
        fn_1_496FC((f32)x, (f32)(y + 3));
        fn_1_49738((u32)fn_1_530C8);
        fn_1_4954C(0.5f + depth);
        fn_1_4A0D8(buffer);
    }
}
/* fzgx:end fn_1_52968 */

/* fzgx:begin fn_1_52B68 */
void fn_1_52B68(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(void *)(arg1), 0);
}
/* fzgx:end fn_1_52B68 */

/* fzgx:begin fn_1_52B8C */
void fn_1_52B8C(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(void *)(arg1), 0x1000);
}
/* fzgx:end fn_1_52B8C */

/* fzgx:begin fn_1_52BB0 */
void fn_1_52BB0(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(void *)(arg1), 0x2000);
}
/* fzgx:end fn_1_52BB0 */

/* fzgx:begin fn_1_52BD4 */
void fn_1_52BD4(void *arg0, void *arg1) {
    fn_1_52BF8(arg0, (u32)(void *)(arg1), 0x3000);
}
/* fzgx:end fn_1_52BD4 */

/* fzgx:begin fn_1_52BF8 */
struct fn_1_52BF8_lbl_801A6D00 {
    u32 unk_0;
};




void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2) {
    s16 s = arg2;
    s32 t1;
    s32 t2;

    (void)arg1;
    lbl_8006D758();
    t1 = s + 0x4000;
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 12)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 28)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(arg2));
    GXLoadTexMtxImm((u32)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0), (u32)(0x1EU), (u32)(1U));
    t2 = s + 0x8000;
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 12)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t2));
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 28)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    GXLoadTexMtxImm((u32)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0), (u32)(0x21U), (u32)(1U));
    t1 = s + 0xC000;
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 12)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 28)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t2));
    GXLoadTexMtxImm((u32)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0), (u32)(0x24U), (u32)(1U));
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 12)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188((s16) (s + 0x10000)));
    (*(f32 *)((u8 *)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0) + 28)) = (f32) ((*(f32 *)((u8 *)(arg0) + 84)) * lbl_8006D188(t1));
    GXLoadTexMtxImm((u32)((*(struct fn_1_52BF8_lbl_801A6D00 *)&lbl_801A6D00).unk_0), (u32)(0x27U), (u32)(1U));
    fn_8007245C((u32)(0x2200U));
    fn_80073678((u32)(5U));
    fn_80074660((u32)(4U));
    fn_800745A4((u32)(0U), (s32)(1), (s32)(4), (u32)(0x1EU), (u32)(0U), (u32)(0x7DU));
    fn_800745A4((u32)(1U), (s32)(1), (s32)(4), (u32)(0x21U), (u32)(0U), (u32)(0x7DU));
    fn_800745A4((u32)(2U), (s32)(1), (s32)(4), (u32)(0x24U), (u32)(0U), (u32)(0x7DU));
    fn_800745A4((u32)(3U), (s32)(1), (s32)(4), (u32)(0x27U), (u32)(0U), (u32)(0x7DU));
    fn_80073C6C((s32)(0));
    fn_80073C6C((s32)(1));
    fn_80073C6C((s32)(2));
    fn_80073C6C((s32)(3));
    fn_80073C6C((s32)(4));
    fn_800734A8((u32)(0U), (u32)(0U), (u32)(0U), (u32)(0xFFU));
    fn_800734A8((u32)(1U), (u32)(1U), (u32)(0U), (u32)(0xFFU));
    fn_800734A8((u32)(2U), (u32)(2U), (u32)(0U), (u32)(0xFFU));
    fn_800734A8((u32)(3U), (u32)(3U), (u32)(0U), (u32)(0xFFU));
    fn_800734A8((u32)(4U), (u32)(0xFFU), (u32)(0xFFU), (u32)(0xFFU));
    fn_80072C24((s32)(0), (s32)(0xF), (s32)(0xF), (s32)(0xF), (s32)(8));
    fn_80072D64((u32)(0U), (u32)(0U), (u32)(0U), (u32)(0U), (u32)(1U), (u32)(0U));
    fn_80072CC4((u32)(0U), (u32)(7U), (u32)(7U), (u32)(7U), (u32)(4U));
    fn_80072E20((s32)(0), (s32)(0), (s32)(0), (s32)(0), (u8)(1U), (s32)(0));
    fn_80072C24((s32)(1), (s32)(0xF), (s32)(8), (s32)(0xC), (s32)(0));
    fn_80072D64((u32)(1U), (u32)(0U), (u32)(0U), (u32)(0U), (u32)(1U), (u32)(0U));
    fn_80072CC4((u32)(1U), (u32)(4U), (u32)(7U), (u32)(7U), (u32)(0U));
    fn_80072E20((s32)(1), (s32)(0), (s32)(0), (s32)(0), (u8)(1U), (s32)(0));
    fn_80072C24((s32)(2), (s32)(0xF), (s32)(8), (s32)(0xC), (s32)(0));
    fn_80072D64((u32)(2U), (u32)(0U), (u32)(0U), (u32)(0U), (u32)(1U), (u32)(0U));
    fn_80072CC4((u32)(2U), (u32)(4U), (u32)(7U), (u32)(7U), (u32)(0U));
    fn_80072E20((s32)(2), (s32)(0), (s32)(0), (s32)(0), (u8)(1U), (s32)(0));
    fn_80072C24((s32)(3), (s32)(0xF), (s32)(8), (s32)(0xC), (s32)(0));
    fn_80072D64((u32)(3U), (u32)(0U), (u32)(0U), (u32)(0U), (u32)(1U), (u32)(0U));
    fn_80072CC4((u32)(3U), (u32)(4U), (u32)(7U), (u32)(7U), (u32)(0U));
    fn_80072E20((s32)(3), (s32)(0), (s32)(0), (s32)(0), (u8)(1U), (s32)(0));
    fn_80072C24((s32)(4), (s32)(0xF), (s32)(2), (s32)(0), (s32)(4));
    fn_80072D64((u32)(4U), (u32)(0U), (u32)(0U), (u32)(0U), (u32)(1U), (u32)(0U));
    fn_80072CC4((u32)(4U), (u32)(7U), (u32)(1U), (u32)(0U), (u32)(2U));
    fn_80072E20((s32)(4), (s32)(0), (s32)(0), (s32)(0), (u8)(1U), (s32)(0));
    fn_80074918((u8)(1U), (s32)(3), (u8)(1U));
}
/* fzgx:end fn_1_52BF8 */

/* fzgx:begin fn_1_530C8 */
struct fn_1_530C8_lbl_801A6D00 {
    u32 unk_0;
};




#pragma opt_propagation off
void fn_1_530C8(void * arg0) {
    u32 v0;
    f32 v1;
    u32 v2;
    f32 v3;
    u32 v4;
    f32 v5;
    u32 v6;
    f32 v7;
    f32 t1;
    f32 t2;
    f32 t4;
    f32 t5;
    f32 t7;
    f32 t8;
    f32 t10;
    f32 t11;
    lbl_8006D758();
    t1 = lbl_8006D188(-6144);
    v0 = (*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0;
    *(f32 *)((u8 *)v0 + 12) = (*(f32 *)((u8 *)arg0 + 84) * t1);
    t2 = lbl_8006D188(-22528);
    v1 = (*(f32 *)((u8 *)arg0 + 84) * t2);
    *(f32 *)((u8 *)(*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0 + 28) = (((lbl_1_rodata_282C.unk_0) + (v1)));
    GXLoadTexMtxImm((*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0, 30, 1);
    t4 = lbl_8006D188(-2048);
    v2 = (*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0;
    *(f32 *)((u8 *)v2 + 12) = (*(f32 *)((u8 *)arg0 + 84) * t4);
    t5 = lbl_8006D188(-18432);
    v3 = (*(f32 *)((u8 *)arg0 + 84) * t5);
    *(f32 *)((u8 *)(*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0 + 28) = (((lbl_1_rodata_282C.unk_0) + (v3)));
    GXLoadTexMtxImm((*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0, 33, 1);
    t7 = lbl_8006D188(2048);
    v4 = (*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0;
    *(f32 *)((u8 *)v4 + 12) = (*(f32 *)((u8 *)arg0 + 84) * t7);
    t8 = lbl_8006D188(-14336);
    v5 = (*(f32 *)((u8 *)arg0 + 84) * t8);
    *(f32 *)((u8 *)(*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0 + 28) = (((lbl_1_rodata_282C.unk_0) + (v5)));
    GXLoadTexMtxImm((*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0, 36, 1);
    t10 = lbl_8006D188(6144);
    v6 = (*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0;
    *(f32 *)((u8 *)v6 + 12) = (*(f32 *)((u8 *)arg0 + 84) * t10);
    t11 = lbl_8006D188(-10240);
    v7 = (*(f32 *)((u8 *)arg0 + 84) * t11);
    *(f32 *)((u8 *)(*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0 + 28) = (((lbl_1_rodata_282C.unk_0) + (v7)));
    GXLoadTexMtxImm((*(struct fn_1_530C8_lbl_801A6D00 *)&lbl_801A6D00).unk_0, 39, 1);
    fn_8007245C(8704);
    fn_80073678(5);
    fn_80074660(4);
    fn_800745A4(0, 1, 4, 30, 0, 125);
    fn_800745A4(1, 1, 4, 33, 0, 125);
    fn_800745A4(2, 1, 4, 36, 0, 125);
    fn_800745A4(3, 1, 4, 39, 0, 125);
    fn_80073C6C(0);
    fn_80073C6C(1);
    fn_80073C6C(2);
    fn_80073C6C(3);
    fn_80073C6C(4);
    fn_800734A8(0, 0, 0, 255);
    fn_800734A8(1, 1, 0, 255);
    fn_800734A8(2, 2, 0, 255);
    fn_800734A8(3, 3, 0, 255);
    fn_800734A8(4, 255, 255, 255);
    fn_80072C24(0, 15, 15, 15, 8);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 4);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80072C24(1, 15, 8, 12, 0);
    fn_80072D64(1, 0, 0, 0, 1, 0);
    fn_80072CC4(1, 4, 7, 7, 0);
    fn_80072E20(1, 0, 0, 0, 1, 0);
    fn_80072C24(2, 15, 8, 12, 0);
    fn_80072D64(2, 0, 0, 0, 1, 0);
    fn_80072CC4(2, 4, 7, 7, 0);
    fn_80072E20(2, 0, 0, 0, 1, 0);
    fn_80072C24(3, 15, 8, 12, 0);
    fn_80072D64(3, 0, 0, 0, 1, 0);
    fn_80072CC4(3, 4, 7, 7, 0);
    fn_80072E20(3, 0, 0, 0, 1, 0);
    fn_80072C24(4, 15, 2, 0, 4);
    fn_80072D64(4, 0, 0, 0, 1, 0);
    fn_80072CC4(4, 7, 1, 0, 2);
    fn_80072E20(4, 0, 0, 0, 1, 0);
    fn_80074918(1, 3, 1);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_530C8 */

/* fzgx:begin fn_1_535A0 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/font.h"
#include "runtime/va_list.h"
#include "font.h"
#include "types.h"
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
extern u32 fn_1_54298(void);
extern u32 fn_1_542A8(void);
extern f32 fn_1_542B8(void);
extern f32 fn_1_4B1D4(s32 mode, s32 value);
extern const f64 lbl_1_rodata_10F8;
extern s32 fn_8008077C(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_FD0[];
extern u8 *lbl_801A66CC;
extern const f32 lbl_1_rodata_2870;
extern const f64 lbl_1_rodata_2878;
extern void lbl_8006E1B0();
extern f32 lbl_8006D0B4(f32 value);
extern void **fn_1_54448(s32 arg0);
extern void * fn_1_548AC(u32 amount);
extern void fn_1_55C48(void);
extern u16 fn_1_7BE94(void);
extern void fn_1_5489C(void **arg0, void **arg1);
extern void fn_1_56530(void);
extern void lbl_8006DB74(void *value);
extern void lbl_8006DD14(void *value, void *object);
extern void fn_1_4E500(void);
extern void fn_1_48D80(void *value);
extern void fn_1_4E6F4(void);
extern s32 fn_1_4E724(FontParams *arg);
extern s32 fn_1_4B16C(s32 value);
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
extern u32 fn_1_54320(void);
extern void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse);
extern void fn_1_547F8(fn_1_547F8_node *node);
extern u32 fn_1_5448C();
extern void fn_1_563E4(fn_1_563E4_FontState *font);
extern void fn_80074B40(u8 *arg0);
extern void fn_80077B04(f32 value);
extern void fn_80071ED4(u8 value, f32 x, f32 y);
extern void fn_80072014(u32 *value);
extern void fn_80074C74(u8 *arg0);
extern void fn_80077BBC(s32 arg0);
extern void fn_80037D40(u8 a, u8 b);
extern u32 fn_80074A7C();
extern u32 fn_80077BAC();
extern const f32 lbl_1_rodata_10D4;
extern void fn_1_4955C(f32 value1, f32 value2);
extern f32 lbl_1_rodata_10C0[5];
extern size_t strlen(const char *str);
extern int sprintf(char *s, const char *format, ...);
extern f32 lbl_1_rodata_26B8[16];
extern void fn_1_4D10C(void *data, f32 scale, f32 value);
extern void fn_1_4D2AC(void *data, f32 scale, f32 value);
extern s32 fn_1_3F164(void);
extern f32 lbl_1_rodata_26F8[22];
extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_1_50190(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
extern void fn_1_52BF8(void *arg0, u32 arg1, s16 arg2);
extern void *fn_1_541A8(void *arg, s32 column);
extern u32 lbl_801A66B4;
extern void fn_1_9FA18(void);
extern void fn_1_58248(void);
extern void fn_1_54848(void);
extern void fn_800794F0(u8 *data, void *value, s32 size);
extern s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2);
extern void fn_1_55210(void *value);
extern const f32 lbl_1_rodata_28A8;
extern void fn_1_557C4(void *value);
extern void fn_1_556B8(void *value);
extern void fn_80077E7C(void *value);
extern void fn_80077F8C(void *value);
extern void fn_80074CF4();
extern void fn_800749B0(s32 arg0, void *arg1);
extern const f32 lbl_1_rodata_28AC;
extern u8 lbl_1_bss_6C7DC[100];
extern u8 *fn_1_565E8(void);
extern void fn_1_45730(void);
extern void fn_1_45B2C(void);
extern void fn_1_458A0(void);
extern void fn_1_45850(void);
extern void fn_1_565F4(void);
extern void fn_80070D60(void *);
extern s32 fn_1_A5DC4();
extern f32 lbl_1_rodata_2788[6];
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);
extern f32 fn_1_51B84(f32 value);
extern f32 fn_1_51BFC(f32 value);
extern const f64 lbl_1_rodata_2758;
extern void lbl_8006D784(void *arg);
extern void fn_1_55D6C(void);


typedef struct Fn1_535A0_Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Fn1_535A0_Color;


/* font.h declares the packet colour as u8[4]; it holds a GXColor */
#define FN_1_535A0_COLOR(packet) (*(Fn1_535A0_Color *)(packet).color)

void fn_1_535A0(Fn1_535A0_Color color, f32 x, f32 y, f32 z, f32 width, f32 height, f32 thickness) {
    FontDrawPacket packet;

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.scale_x *= width / 8.0f;
    packet.scale_y *= thickness / 8.0f;
    FN_1_535A0_COLOR(packet) = color;
    fn_1_4F734(&packet);

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.scale_x *= thickness / 8.0f;
    packet.scale_y *= height / 8.0f;
    FN_1_535A0_COLOR(packet) = color;
    fn_1_4F734(&packet);

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = x;
    packet.y = y + height;
    packet.z = z;
    packet.scale_x *= width / 8.0f;
    packet.scale_y *= thickness / 8.0f;
    packet.flags = 0xD;
    FN_1_535A0_COLOR(packet) = color;
    fn_1_4F734(&packet);

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = x + width;
    packet.y = y;
    packet.z = z;
    packet.scale_x *= thickness / 8.0f;
    packet.scale_y *= height / 8.0f;
    packet.flags = 0x7;
    FN_1_535A0_COLOR(packet) = color;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_535A0 */

/* fzgx:begin fn_1_53830 noprologue */
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
typedef float f32;
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    s = 0.0f;
    s = 0.10000000149011612f;
}
static const unsigned long fzgx_pool_table2[19] = {0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    d = 4503599627370496.0;
    s = 55.0f;
}
static const unsigned long fzgx_pool_table4[1] = {0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 90000.0f;
    s = 480.0f;
    s = 640.0f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.5;
    s = 0.75f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.002405626;
    s = 320.0f;
    s = 240.0f;
    s = 255.0f;
    s = 0.5f;
    s = 2.0f;
    s = 4.0f;
}
static const unsigned long fzgx_pool_table10[31] = {0x00000000, 0x40000000, 0x40000000, 0x00000000, 0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000, 0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00, 0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000, 0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.125f;
}
static const unsigned long fzgx_pool_table12[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table13[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65536.0f;
    s = 80.0f;
}
#pragma section code_type ".text"

extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(s32);
extern u32 lbl_1_rodata_26F8_w138[1];
extern u32 lbl_1_rodata_26F8_w13c[1];

/* Volatile views preserve the order of color updates and pool reads. */
void fn_1_53830(u32 period, f32 x, u8 val, volatile u8 *a, volatile u8 *b) {
    u32 t = lbl_801A66A0 % period;
    struct { f32 value; } f;
    u8 c;
    if (t < period / 2) {
        f.value = lbl_8006D188((s32)(65536.0f * (f32)t / (f32)period));
        c = (s32)((f32)val * f.value);
        a[2] = c;
        a[1] = c;
        a[0] = c;
        a[3] = 0;
        *(u32 *)b = *(volatile u32 *)fzgx_pool_table12; /* fzgx-allow: S2 ordered packed-color read after component stores */
    } else {
        f.value = lbl_8006D188((s32)(65536.0f * (f32)t / (f32)period));
        f.value = (f32)((1.0f - x) * f.value);
        f.value = 1.0f + f.value;
        c = (s32)(255.0f * f.value);
        b[2] = c;
        b[1] = c;
        b[0] = c;
        b[3] = 0;
        *(u32 *)a = *(volatile u32 *)fzgx_pool_table13; /* fzgx-allow: S2 ordered packed-color read after component stores */
    }
}
/* fzgx:end fn_1_53830 */

/* fzgx:begin fn_1_539CC noprologue */
#include "types.h"
#include "font.h"

extern const f32 lbl_1_rodata_2754;

typedef struct FrameColor {
    u8 r, g, b, a;
} FrameColor;

#pragma fp_contract off
FrameColor fn_1_539CC(const FrameColor *a, const FrameColor *b, f32 t) {
    FrameColor color;
    color.r = (f32)a->r * t + (f32)b->r * (lbl_1_rodata_2754 - t);
    color.g = (f32)a->g * t + (f32)b->g * (lbl_1_rodata_2754 - t);
    color.b = (f32)a->b * t + (f32)b->b * (lbl_1_rodata_2754 - t);
    color.a = (f32)a->a * t + (f32)b->a * (lbl_1_rodata_2754 - t);
    return color;
}
/* fzgx:end fn_1_539CC */

/* fzgx:begin fn_1_53B14 noprologue */
#include "types.h"

extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);

/* 0x58-byte settings record copied from the constant table. */
typedef struct {
    u32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10[7];
    f32 unk2C;
    s32 unk30;
    s32 unk34;
    u32 unk38;
    s32 unk3C[7];
} Fn53B14Params;

/* retail .rodata block [lbl_1_rodata_26F8, +0x15C): the function copies the 0x58-byte
   record through the pool base and reads its constants at fixed displacements. */
static const u32 fzgx_pool_table1[22] = {
	0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000,
	0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000,
	0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table2[2] = {
	0x00000000, 0x3F800000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[58] = {
	0x425C0000, 0x3DCCCCCD, 0x47AFC800, 0x43F00000, 0x44200000, 0x00000000,
	0x43300000, 0x80000000, 0x3FE00000, 0x00000000, 0x3F400000, 0x00000000,
	0x3F63B4F6, 0x9FE2918E, 0x43A00000, 0x43700000, 0x437F0000, 0x3F000000,
	0x40000000, 0x40800000, 0x00000000, 0x40000000, 0x40000000, 0x00000000,
	0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000,
	0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00,
	0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000,
	0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x3E000000, 0xFFFFFF00, 0x00000000,
	0x47800000, 0x42A00000, 0x42700000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 255.0;
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	s = 8.0f;
}
#pragma section code_type ".text"

void fn_1_53B14(u8 *color, f32 a, f32 b, f32 c, f32 d, f32 e)
{
    Fn53B14Params params = *(const Fn53B14Params *)fzgx_pool_table1;

    params.unk0 = 12;
    params.unk4 = a;
    params.unk8 = b;
    params.unkC = e;
    if (color != NULL) {
        params.unk2C = color[3] / 255.0;
        params.unk38 = *(u32 *)color;
    }
    params.unk30 = 10;
    fn_1_50190(&params, c, d, 8.0f, 8.0f, 8.0f, 8.0f);
}
/* fzgx:end fn_1_53B14 */

/* fzgx:begin fn_1_53BD8 noprologue */
#include "types.h"

extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);

/* 0x58-byte settings record copied from the constant table. */
typedef struct {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10[7];
    f32 unk2C;
    s32 unk30;
    s32 unk34;
    u32 unk38;
    s32 unk3C[7];
} Fn53BD8Params;

/* retail .rodata block [lbl_1_rodata_26F8, +0x164): the function copies the 0x58-byte
   record through the pool base and reads its constants at fixed displacements. */
static const u32 fzgx_pool_table1[22] = {
	0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000,
	0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000,
	0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table2[2] = {
	0x00000000, 0x3F800000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[58] = {
	0x425C0000, 0x3DCCCCCD, 0x47AFC800, 0x43F00000, 0x44200000, 0x00000000,
	0x43300000, 0x80000000, 0x3FE00000, 0x00000000, 0x3F400000, 0x00000000,
	0x3F63B4F6, 0x9FE2918E, 0x43A00000, 0x43700000, 0x437F0000, 0x3F000000,
	0x40000000, 0x40800000, 0x00000000, 0x40000000, 0x40000000, 0x00000000,
	0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000,
	0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00,
	0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000,
	0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x3E000000, 0xFFFFFF00, 0x00000000,
	0x47800000, 0x42A00000, 0x42700000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 255.0;
}
static const u32 fzgx_pool_table4[1] = {
	0x41000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
	volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
	s = 13.0f;
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
	volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
	s = 26.0f;
}
#pragma section code_type ".text"

void fn_1_53BD8(u8 *color, f32 a, f32 b, f32 c, f32 d, f32 e)
{
	Fn53BD8Params params = *(const Fn53BD8Params *)fzgx_pool_table1;

	params.unk0 = 2;
	params.unk4 = a;
	params.unk8 = b;
	params.unkC = e;
	if (color != NULL) {
		params.unk2C = (f32)((f64)*((u8 *)color + 3) / 255.0);
		params.unk38 = *(u32 *)color;
	}
	params.unk30 = 10;
	fn_1_50190(&params, c, d, 13.0f, 13.0f, 26.0f, 26.0f);
}
/* fzgx:end fn_1_53BD8 */

/* fzgx:begin fn_1_53C9C noprologue */
#include "dolphin/types.h"

#pragma pool_data on
#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table2[24] = {0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 55.0f;
}
static const unsigned long fzgx_pool_table4[1] = {0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 90000.0f;
    s = 480.0f;
    s = 640.0f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.5;
    s = 0.75f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.002405626;
    s = 320.0f;
    s = 240.0f;
    s = 255.0f;
    s = 0.5f;
    s = 2.0f;
    s = 4.0f;
}
static const unsigned long fzgx_pool_table10[31] = {0x00000000, 0x40000000, 0x40000000, 0x00000000, 0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000, 0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00, 0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000, 0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.125f;
}
static const unsigned long fzgx_pool_table12[2] = {0xFFFFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65536.0f;
    s = 80.0f;
    s = 60.0f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 255.0;
    s = 8.0f;
    s = 13.0f;
    s = 26.0f;
    s = 0.009999999776482582f;
    d = 0.0005;
}
#pragma section code_type ".text"
typedef struct Pk {
    s32 a;
    f32 x, y, z;
    s32 pad1[7];
    f32 al;
    s32 b;
    s32 pad2;
    s32 col;
    s32 pad3[7];
} Pk;

extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_4A0D8(const char *);
extern f32 fn_1_4B068(s32);
extern f32 fn_1_4B090(s32);
extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);

void fn_1_53C9C(u8 *color, s32 id, f32 x, f32 y, f32 z, f32 s, f32 t)
{
    f32 s_local = s;
    Pk p;
    f32 tmp_call5;
    f32 a, b;
    if (z < 0.01f) {
        z = 0.01f;
    }
    fn_1_496FC(x, y);
    fn_1_4954C(z - 0.0005);
    fn_1_4955C(t, t);
    fn_1_495C8(9);
    fn_1_4A0D8((const char *)id);
    tmp_call5 = fn_1_4B068(id);
    a = tmp_call5;
    s_local = s_local * t;
    a = s_local + a;
    b = s_local + fn_1_4B090(id);
    p = *(const Pk *)fzgx_pool_table2;
    p.a = 12;
    p.x = x;
    p.y = y;
    p.z = z;
    if (color != 0) {
        p.al = color[3] / 255.0;
        p.col = *(s32 *)color;
    }
    p.b = 10;
    fn_1_50190(&p, a, b, 8.0f, 8.0f, 8.0f, 8.0f);
}
/* fzgx:end fn_1_53C9C */

/* fzgx:begin fn_1_53E40 noprologue */
#include "types.h"

extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_4A0D8(const char *);
extern f32 fn_1_4B068(const char *);
extern f32 fn_1_4B090(const char *);
extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);

/* 0x58-byte settings record copied from the constant table. */
typedef struct {
	u32 field_0;
	f32 field_4;
	f32 field_8;
	f32 field_c;
	u8 pad_10[0x1c];
	f32 field_2c;
	u32 field_30;
	u8 pad_34[4];
	u32 field_38;
	u8 pad_3c[0x1c];
} Record;

/* retail .rodata block [lbl_1_rodata_26F8, +0x170): the function reads the 0x58-byte
   record through the pool base, the share of the TU pool after it is baked below. */
static const u32 fzgx_pool_table1[22] = {
	0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000,
	0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000,
	0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table2[2] = {
	0x00000000, 0x3F800000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[58] = {
	0x425C0000, 0x3DCCCCCD, 0x47AFC800, 0x43F00000, 0x44200000, 0x00000000,
	0x43300000, 0x80000000, 0x3FE00000, 0x00000000, 0x3F400000, 0x00000000,
	0x3F63B4F6, 0x9FE2918E, 0x43A00000, 0x43700000, 0x437F0000, 0x3F000000,
	0x40000000, 0x40800000, 0x00000000, 0x40000000, 0x40000000, 0x00000000,
	0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000,
	0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00,
	0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000,
	0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x3E000000, 0xFFFFFF00, 0x00000000,
	0x47800000, 0x42A00000, 0x42700000, 0x00000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	d = 255.0;
}
static const u32 fzgx_pool_table4[1] = {
	0x41000000,
};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	s = 13.0f;
	s = 26.0f;
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
	volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
	s = 0.009999999776482582f;
	d = 0.0005;
}
#pragma section code_type ".text"

void fn_1_53E40(u8 *color, const char *name, f32 x, f32 y, f32 z, f32 w, f32 h)
{
	f32 total;
	f32 delta;

	if (z < 0.01f) {
		z = 0.01f;
	}
	fn_1_496FC(x, y);
	fn_1_4954C((f32)(z - 0.0005));
	fn_1_4955C(h, h);
	fn_1_495C8(9);
	fn_1_4A0D8(name);
	total = w * h + fn_1_4B068(name);
	delta = w * h + fn_1_4B090(name);

	{
		Record rec = *(const Record *)fzgx_pool_table1;

		rec.field_0 = 2;
		rec.field_4 = x;
		rec.field_8 = y;
		rec.field_c = z;
		if (color != 0) {
			rec.field_2c = (f32)((f64)(u32)color[3] / 255.0);
			rec.field_38 = *(u32 *)color;
		}
		rec.field_30 = 10;

		fn_1_50190(&rec, total, delta, 13.0f, 13.0f, 26.0f, 26.0f);
	}
}
/* fzgx:end fn_1_53E40 */

/* fzgx:begin fn_1_53FE4 noprologue */
#include "font.h"

extern const struct fn_1_53FE4_lbl_1_rodata_2754_pool {
    f32 unk_0;
} lbl_1_rodata_2754;

extern const struct fn_1_53FE4_lbl_1_rodata_2868_pool {
    f32 unk_0;
} lbl_1_rodata_2868;
extern u16 fn_1_486C4(u32);
extern u16 fn_1_48690(u32);
extern int fn_1_4F734(FontDrawPacket *);

typedef struct {
    u32 p;
    u8 pad[0xC];
    f32 f10, f14, f18, f1c, f20, f24;
} Fn53Obj;

#pragma opt_propagation off
void fn_1_53FE4(Fn53Obj *arg, u8 idx) {
    u32 p;
    s16 h;
    s16 w;
    f32 iw;
    f32 ih;
    s16 x;
    s16 y;
    Fn53Obj *obj;
    obj = arg;
    p = obj->p;
    x = (idx % 10) * 20;
    y = (idx / 10) * 20;
    w = fn_1_486C4(p);
    h = fn_1_48690(p);
    ih = lbl_1_rodata_2754.unk_0 / (f32)h;
    iw = lbl_1_rodata_2754.unk_0 / (f32)w;
    obj->f10 = obj->f10 * (lbl_1_rodata_2868.unk_0 * ih);
    obj->f14 = obj->f14 * (lbl_1_rodata_2868.unk_0 * iw);
    obj->f18 = (f32)x * ih;
    obj->f1c = (f32)y * iw;
    obj->f20 = ih * (f32)(x + 20);
    obj->f24 = iw * (f32)(y + 20);
    fn_1_4F734((FontDrawPacket *)obj);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_53FE4 */

/* fzgx:begin fn_1_5415C */
void fn_1_5415C(void *arg, s32 value) {
    fn_1_541A8(arg, value);
}
/* fzgx:end fn_1_5415C */

/* fzgx:begin fn_1_5417C */
void fn_1_5417C(void *arg) {
    fn_1_541A8(arg, lbl_801A66B4);
}
/* fzgx:end fn_1_5417C */

/* fzgx:begin fn_1_541A8 */
// Select the localized form for a number and column, including the special 10–20 range.
void *fn_1_541A8(void *arg, s32 column) {
    s32 is_special;
    u32 remainder;
    s32 row_index;
    u32 *row;
    u32 number = (u32)arg;

    if (number == 0) {
        return &lbl_1_data_1C5DC;
    }

    remainder = number - (number / 100) * 100;
    is_special = 0;
    if (remainder >= 10 && remainder <= 20) {
        is_special = 1;
    }

    if (is_special != 0) {
        row_index = 3;
    } else {
        number = remainder - (remainder / 10) * 10;
        is_special = 0;
        if (number >= 4 || number == 0) {
            is_special = 1;
        }
        row_index = 3;
        if (is_special == 0) {
            row_index = number - 1;
        }
    }

    row = (u32 *)(lbl_1_data_1C5EC + row_index * 24);
    return (void *)row[column < 0 ? 0 : (column > 5 ? 5 : column)];
}
/* fzgx:end fn_1_541A8 */

/* fzgx:begin fn_1_54278 */
void fn_1_54278(u32 arg0, u32 arg1) {
    lbl_1_bss_4C680 = arg0;
    lbl_1_bss_4C684 = arg1;
}
/* fzgx:end fn_1_54278 */

/* fzgx:begin fn_1_5428C */
void fn_1_5428C(f32 value) {
    lbl_1_data_1C508.unk_0 = value;
}
/* fzgx:end fn_1_5428C */

/* fzgx:begin fn_1_54298 */
u32 fn_1_54298(void) {
    return lbl_1_bss_4C680;
}
/* fzgx:end fn_1_54298 */

/* fzgx:begin fn_1_542A8 */
u32 fn_1_542A8(void) {
    return lbl_1_bss_4C684;
}
/* fzgx:end fn_1_542A8 */

/* fzgx:begin fn_1_542B8 */
f32 fn_1_542B8(void) {
    return lbl_1_data_1C508.unk_0;
}
/* fzgx:end fn_1_542B8 */

/* fzgx:begin fn_1_542C4 */
typedef struct fn_1_542C4_FontState {
    u8 pad30[0x30];
    void *unk_30;
    void *unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    u8 pad44[8];
    f32 unk_4C;
} fn_1_542C4_FontState;

// Volatile preserves the repeated loads of the shared font state.
#define FONT_STATE ((volatile fn_1_542C4_FontState *)lbl_801A66CC)

// Store the current font parameters and notify the font system.
void fn_1_542C4(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4) {
    FONT_STATE->unk_30 = arg0;
    FONT_STATE->unk_34 = arg1;
    FONT_STATE->unk_38 = arg2;
    FONT_STATE->unk_3C = arg3;
    FONT_STATE->unk_40 = arg4;
    FONT_STATE->unk_4C = arg4 - arg3;
    fn_1_54320();
}
/* fzgx:end fn_1_542C4 */

/* fzgx:begin fn_1_54320 */
struct fn_1_54320_lbl_801A66CC {
    u32 unk_0;
};

u32 fn_1_54320(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    v0 = (*(struct fn_1_54320_lbl_801A66CC *)&lbl_801A66CC).unk_0;
    fn_1_54668( (fn_1_54668_node *)(u32)(*(u32 *)((u8 *)v0 + 48)), *(u32 *)((u8 *)v0 + 52), 1);
    v1 = (*(struct fn_1_54320_lbl_801A66CC *)&lbl_801A66CC).unk_0;
    *(u32 *)((u8 *)v1 + 68) = (*(u32 *)((u8 *)v1 + 48) + ((*(u32 *)((u8 *)v1 + 52) - 1) << 3));
    v2 = (*(struct fn_1_54320_lbl_801A66CC *)&lbl_801A66CC).unk_0;
    *(u32 *)((u8 *)v2 + 72) = *(u32 *)((u8 *)v2 + 48);
    return v2;
}
/* fzgx:end fn_1_54320 */

/* fzgx:begin fn_1_54384 */
typedef struct fn_1_54384_FontState {
    u8 pad_00[0x30];
    u8 *glyphs;
    s32 glyph_count;
    f32 start;
    f32 end;
    u8 pad_40[4];
    u8 *lower;
    u8 *upper;
    f32 step;
} fn_1_54384_FontState;



u8 *fn_1_54384(f32 value) {
    fn_1_54384_FontState *state = (*(fn_1_54384_FontState * *)&lbl_801A66CC);
    f32 pos = -value + state->start;
    f32 adjusted = pos - state->end;
    s32 index;
    s32 count;
    u8 *entry;

    if (adjusted < lbl_1_rodata_2870) {
        index = 0;
    } else {
        count = state->glyph_count;
        index = (s32)((f32)(s32)count * adjusted /
                      (adjusted + state->step));
        if (index >= count) {
            index = count - 1;
        }
    }

    entry = state->glyphs + index * 8;
    if (state->lower > entry) {
        state->lower = entry;
    }
    if ((*(fn_1_54384_FontState * *)&lbl_801A66CC)->upper < entry) {
        (*(fn_1_54384_FontState * *)&lbl_801A66CC)->upper = entry;
    }
    return entry;
}
/* fzgx:end fn_1_54384 */

/* fzgx:begin fn_1_54448 */
struct fn_1_54448_lbl_801A66CC {
    u32 unk_0;
};

void **fn_1_54448(s32 arg0) {
    void **temp_r3;

    temp_r3 = (void **)((*(s32 *)((u8 *)((*(struct fn_1_54448_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 48)) + (arg0 * 8));
    if ((void **) (*(void ***)((u8 *)((*(struct fn_1_54448_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 68)) > temp_r3) {
        (*(void ***)((u8 *)((*(struct fn_1_54448_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 68)) = (void **)(temp_r3);
    }
    if ((void **) (*(void ***)((u8 *)((*(struct fn_1_54448_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 72)) < temp_r3) {
        (*(void ***)((u8 *)((*(struct fn_1_54448_lbl_801A66CC *)&lbl_801A66CC).unk_0) + 72)) = (void **)(temp_r3);
        return temp_r3;
    }
    return temp_r3;
}
/* fzgx:end fn_1_54448 */

/* fzgx:begin fn_1_5448C */
typedef struct {
    u8 pad_0[0x30];
    u8 *table;
    s32 count;
    f32 value_38;
    f32 clamp_3c;
    u8 pad_40[4];
    u8 *current;
    u8 *maximum;
    f32 value_4c;
} FontGlobals;



static inline f32 fn_1_5448C_read_pointer(FontGlobals * owner) { return owner->value_4c; }
u32 fn_1_5448C(arg, lab_unused0, lab_unused1, lab_unused2)
void *arg;
u32 lab_unused0;
u32 lab_unused1;
u32 lab_unused2;
{
    f32 fzgx_live_;
    f32 fzgx_live;
    Vec3 vec;
    f32 clamp;
    f32 sum;
    f32 distance;
    s32 index;
    u8 *entry;
    u8 *state;

    lbl_8006E1B0(arg, &vec);
    state = lbl_801A66CC;
    clamp = ((FontGlobals *)state)->clamp_3c;
    fzgx_live = vec.z;
    vec.z = -fzgx_live;
    if (vec.z < clamp) {
        vec.z = clamp;
    }

    sum = vec.x * vec.x;
    fzgx_live_ = vec.y;
    sum += fzgx_live_ * fzgx_live_;
    fzgx_live = vec.z;
    sum += fzgx_live * fzgx_live;
    distance = lbl_8006D0B4(sum);
    state = lbl_801A66CC;
    distance = ((FontGlobals *)state)->value_38 + distance - clamp;

    if (distance < (0.0f)) {
        index = 0;
    } else {
        index = (s32)((f32)((FontGlobals *)state)->count * distance / (distance + fn_1_5448C_read_pointer((FontGlobals *)state)));
        if (index >= ((FontGlobals *)state)->count) {
            index = ((FontGlobals *)state)->count - 1;
        }
    }

    entry = ((FontGlobals *)state)->table + (index << 3);
    if (((FontGlobals *)state)->current > entry) {
        ((FontGlobals *)state)->current = entry;
    }
    if (((FontGlobals *)lbl_801A66CC)->maximum < entry) {
        ((FontGlobals *)lbl_801A66CC)->maximum = entry;
    }
    return (u32)entry;
}
/* fzgx:end fn_1_5448C */

/* fzgx:begin fn_1_545B8 */
typedef struct fn_1_545B8_manager {
    u8 unk_00[0x30];
    void *unk_30;
    u32 unk_34;
    u8 unk_38[0x0C];
    u32 *unk_44;
    u32 *unk_48;
} fn_1_545B8_manager;


// Reset the font manager's node list and process any completed nodes.
void fn_1_545B8(void) {
    if (((fn_1_545B8_manager *)lbl_801A66CC)->unk_48 >=
        ((fn_1_545B8_manager *)lbl_801A66CC)->unk_44) {
        if (((fn_1_545B8_manager *)lbl_801A66CC)->unk_44 >
            (u32 *)((fn_1_545B8_manager *)lbl_801A66CC)->unk_30) {
            *(((fn_1_545B8_manager *)lbl_801A66CC)->unk_44 - 2) = 0;
        }
        fn_1_547F8( (fn_1_547F8_node *)(void *)(((fn_1_545B8_manager *)lbl_801A66CC)->unk_48));
    }

    fn_1_54668( (fn_1_54668_node *)(void *)(((fn_1_545B8_manager *)lbl_801A66CC)->unk_30),
                ((fn_1_545B8_manager *)lbl_801A66CC)->unk_34, 1);
    ((fn_1_545B8_manager *)lbl_801A66CC)->unk_44 =
        (u32 *)((u8 *)((fn_1_545B8_manager *)lbl_801A66CC)->unk_30 +
                (((fn_1_545B8_manager *)lbl_801A66CC)->unk_34 - 1) * 8);
    ((fn_1_545B8_manager *)lbl_801A66CC)->unk_48 =
        (u32 *)((fn_1_545B8_manager *)lbl_801A66CC)->unk_30;
    fn_1_9FA18();
    fn_1_58248();
}
/* fzgx:end fn_1_545B8 */

/* fzgx:begin fn_1_54668 */
// Initialize a forward- or reverse-linked list and notify the allocator.
void fn_1_54668(fn_1_54668_node *node, s32 count, u32 reverse) {
    s32 i;

    if (reverse == 0) {
        i = count - 1;
        for (; i > 0; i--) {
            node->next = node + 1;
            node->data = 0;
            node++;
        }
        node->next = 0;
        node->data = 0;
    } else {
        i = count - 1;
        node += i;
        for (; i > 0; i--) {
            node->next = node - 1;
            node->data = 0;
            node--;
        }
        node->next = 0;
        node->data = 0;
    }
    fn_1_54848();
}
/* fzgx:end fn_1_54668 */

/* fzgx:begin fn_1_547F8 */
// Invoke each node callback while walking the linked list.
void fn_1_547F8(fn_1_547F8_node *node) {
    while (node != 0) {
        if (node->callback != 0) {
            node->callback(node);
        }
        node = node->next;
    }
}
/* fzgx:end fn_1_547F8 */

/* fzgx:begin fn_1_54848 */
typedef struct fn_1_54848_FontState {
    u8 pad_1a0[0x1a0];
    u32 unk_1a0;
    u32 unk_1a4;
    u32 unk_1a8;
    u32 unk_1ac;
} fn_1_54848_FontState;

// Volatile forces each global-state access to retain the retail load ordering.
typedef volatile fn_1_54848_FontState fn_1_54848_VolatileFontState;

// Synchronize the current and previous font-state values for the next update.
void fn_1_54848(void) {
    ((fn_1_54848_VolatileFontState *)lbl_801A66CC)->unk_1a0 =
        ((fn_1_54848_VolatileFontState *)lbl_801A66CC)->unk_1a4;
    ((fn_1_54848_VolatileFontState *)lbl_801A66CC)->unk_1ac =
        ((fn_1_54848_VolatileFontState *)lbl_801A66CC)->unk_1a8;
}
/* fzgx:end fn_1_54848 */

/* fzgx:begin fn_1_54868 */
typedef struct fn_1_54868_FontState {
    u8 pad_1a0[0x1a0];
    u32 unk_1a0;
    u32 unk_1a4;
    u32 unk_1a8;
    u32 unk_1ac;
} fn_1_54868_FontState;



// Copies the current font state's two counter values into its active fields.
void fn_1_54868(u32 arg0, u32 arg1) {
    // Volatile access preserves the first retail global-pointer load.
    ((volatile fn_1_54868_FontState *)lbl_801A66CC)->unk_1a4 = arg0;
    // Volatile access preserves the second retail global-pointer load.
    ((volatile fn_1_54868_FontState *)lbl_801A66CC)->unk_1a8 = arg1;
    // Volatile access preserves the third retail global-pointer load.
    ((volatile fn_1_54868_FontState *)lbl_801A66CC)->unk_1a0 = ((volatile fn_1_54868_FontState *)lbl_801A66CC)->unk_1a4;
    // Volatile access preserves the fourth retail global-pointer load.
    ((volatile fn_1_54868_FontState *)lbl_801A66CC)->unk_1ac = ((volatile fn_1_54868_FontState *)lbl_801A66CC)->unk_1a8;
}
/* fzgx:end fn_1_54868 */

/* fzgx:begin fn_1_5489C */
void fn_1_5489C(void **arg0, void **arg1) {
    void *value = *arg0;
    *arg1 = value;
    *arg0 = (void *)arg1;
}
/* fzgx:end fn_1_5489C */

/* fzgx:begin fn_1_548AC */
typedef struct FontCounterState {
    u8 pad_1a0[0x1a0];
    u32 unk_1a0;
    u8 pad_1a4[8];
    u32 unk_1ac;
} FontCounterState;

/* The shared declaration is opaque; this union gives it the recovered layout. */
typedef union FontCounterStateView {
    u8 *raw;
    FontCounterState *typed;
} FontCounterStateView;

// Advances the font counter when enough capacity remains and returns its prior value.
void * fn_1_548AC(u32 amount) {
    FontCounterStateView view;
    FontCounterState *state;
    u32 previous;

    view.raw = lbl_801A66CC;
    state = view.typed;
    if (state->unk_1ac < amount) {
        return (void *)(0);
    }

    previous = state->unk_1a0;
    state->unk_1a0 = previous + amount;
    view.raw = lbl_801A66CC;
    state = view.typed;
    state->unk_1ac -= amount;
    return (void *)(previous);
}
/* fzgx:end fn_1_548AC */

/* fzgx:begin fn_1_548EC */
typedef struct fn_1_548EC_FontState {
    u8 pad30[0x30];
    u8 *field_30;
} fn_1_548EC_FontState;



s32 fn_1_548EC(void *arg0) {
    u8 *base;
    fn_1_548EC_FontState *fs;
    s32 offset;
    s32 i;

    i = 0;
    offset = 0;
    fs = (*(fn_1_548EC_FontState * *)&lbl_801A66CC);
    while (i < 0x1000) {
        base = fs->field_30;
        if (arg0 == base + offset) {
            return i;
        }
        offset += 8;
        i++;
    }
    return -1;
}
/* fzgx:end fn_1_548EC */

/* fzgx:begin fn_1_549F4 noprologue */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Angles;

typedef struct {
    f32 s;
    f32 c;
} Vec2;

typedef struct {
    u8 pad_0[0x50];
    Vec3 v50;
    Vec3 aim[4];
    Vec3 dir[4];
    Angles rot;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
} State;

typedef struct {
    f32 zero;
    f32 deg;
    f32 half;
    f32 pad_c;
    f64 one;
    f64 degd;
    f64 halfd;
} K;

extern State *lbl_801A66CC;
extern K lbl_1_rodata_2880;
extern f32 lbl_8006D21C(s32);
extern s16 lbl_8006D2AC(f32);
extern void lbl_8006D7DC(Vec3 *);
extern u32 mathutil_mtxA_rotate_x(s32);
extern u32 mathutil_mtxA_rotate_y(s32);
extern u32 mathutil_mtxA_rotate_z(s32);
extern void lbl_8006D1B8(s16, Vec2 *);
extern void lbl_8006E1C0(Vec3 *, Vec3 *);

void fn_1_549F4(Vec3 *arg0, Angles *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 fzgx_live_;
    f32 fzgx_live;
    f32 h;
    K *p = (K *)&lbl_1_rodata_2880;
    s16 t1, t2;
    Angles *a1 = arg1;
    Vec3 *a0 = arg0;
    s16 t3, t4;
    Vec2 v;

    lbl_801A66CC->v50 = *a0;
    lbl_801A66CC->rot = *a1;
    lbl_801A66CC->f1 = arg2;
    lbl_801A66CC->f2 = arg3;
    lbl_801A66CC->f3 = arg4;
    lbl_801A66CC->f4 = arg5;

    if ((0.0f) == arg5) {
        s32 t = (s16)((182.044449f) * arg2);
        t1 = -t / 2;
        t2 = t / 2;
    } else {
        h = lbl_8006D21C((s32)((182.044449f) * ((0.5f) * arg2)));
        t1 = -lbl_8006D2AC(h * ((1.0) - arg5));
        t2 = lbl_8006D2AC(h * ((1.0) + arg5));
    }

    if ((0.0f) == arg4) {
        s16 x = lbl_8006D2AC(arg3 * lbl_8006D21C((s32)((182.04444885253906) * ((0.5) * arg2))));
        s32 t = (s16)(x * 2);
        t3 = t / 2;
        t4 = -t / 2;
    } else {
        f32 s;
        if ((0.0f) == arg5) {
            s = arg3 * lbl_8006D21C((s32)((182.044449f) * ((0.5f) * arg2)));
        } else {
            s = h * arg3;
        }
        t3 = lbl_8006D2AC(s * ((1.0) + arg4));
        t4 = -lbl_8006D2AC(s * ((1.0) - arg4));
    }

    lbl_8006D7DC(a0);
    mathutil_mtxA_rotate_y(a1->y);
    mathutil_mtxA_rotate_x(a1->x);
    mathutil_mtxA_rotate_z(a1->z);

    lbl_8006D1B8((s16)(t3 - 0x4000), &v);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[0].x = -fzgx_live_;
    lbl_801A66CC->dir[0].y = (0.0f);
    lbl_801A66CC->dir[0].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[0], &lbl_801A66CC->aim[0]);

    lbl_8006D1B8((s16)(t4 + 0x4000), &v);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[1].x = -fzgx_live_;
    lbl_801A66CC->dir[1].y = (0.0f);
    lbl_801A66CC->dir[1].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[1], &lbl_801A66CC->aim[1]);

    lbl_8006D1B8((s16)(t1 + 0x4000), &v);
    lbl_801A66CC->dir[2].x = (0.0f);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[2].y = -fzgx_live_;
    lbl_801A66CC->dir[2].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[2], &lbl_801A66CC->aim[2]);

    lbl_8006D1B8((s16)(t2 - 0x4000), &v);
    lbl_801A66CC->dir[3].x = (0.0f);
    fzgx_live_ = v.s;
    lbl_801A66CC->dir[3].y = -fzgx_live_;
    lbl_801A66CC->dir[3].z = -v.c;
    lbl_8006E1C0(&lbl_801A66CC->dir[3], &lbl_801A66CC->aim[3]);
}


/* fzgx:end fn_1_549F4 */

/* fzgx:begin fn_1_54DCC */
void fn_1_54DCC(u8 *data) {
    fn_800794F0(data, (u8 *)lbl_801A66CC + 0x50, 0x84);
}
/* fzgx:end fn_1_54DCC */

/* fzgx:begin fn_1_54E00 */
void fn_1_54E00(void *value) {
    fn_800794F0((u8 *)lbl_801A66CC + 0x50, value, 0x84);
}
/* fzgx:end fn_1_54E00 */

/* fzgx:begin fn_1_54E34 */
typedef struct {
    u8 pad0[0x8c];
    f32 plane0[3];
    f32 plane1[3];
    f32 plane2[3];
    f32 plane3[3];
} Fn154E34Data;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vector;



s32 fn_1_54E34(void *arg0, f32 arg1) {
    Vector vector;
    Fn154E34Data *data;
    f32 *p;
    f32 x;
    f32 y;
    f32 z;
    f32 m0;
    f32 m1;
    f32 m2;
    s32 i;

    lbl_8006E1B0(arg0, (f32 *)&vector, arg1);
    z = vector.z;
    x = vector.x;
    y = vector.y;
    if (z > arg1) {
        return 0;
    }
    arg1 = -arg1;
    data = (Fn154E34Data *)(*(void * *)&lbl_801A66CC);
    p = data->plane0;
    for (i = 0; i < 4; i++) {
        m0 = x * p[0];
        m1 = y * p[1];
        m2 = z * p[2];
        if (m0 + m1 + m2 < arg1) {
            return 0;
        }
        p += 3;
    }
    return 1;
}
/* fzgx:end fn_1_54E34 */

/* fzgx:begin fn_1_54F5C */
typedef struct {
    u8 pad0[0x8c];
    f32 plane0[3];
    f32 plane1[3];
    f32 plane2[3];
    f32 plane3[3];
    u8 pad_bc[0x18];
    f32 value_d4;
    f32 value_d8;
    f32 value_dc;
} Fn154F5CData;



s32 fn_1_54F5C(void *arg0, f32 arg1, f32 arg2) {
    Fn154F5CData *data;
    f32 *p;
    f32 d4;
    f32 d8;
    f32 dc;
    f32 m0;
    f32 m1;
    f32 m2;
    s32 i;

    data = (Fn154F5CData *)(*(void * *)&lbl_801A66CC);
    lbl_8006E1B0(arg0, (Vec3 *)(void *)(&data->value_d4));
    data = (Fn154F5CData *)(*(void * *)&lbl_801A66CC);
    arg1 = arg1 * arg2;
    dc = data->value_dc;
    if (dc > arg1) {
        return 0;
    }
    d4 = data->value_d4;
    d8 = data->value_d8;
    arg1 = -arg1;
    p = data->plane0;
    for (i = 0; i < 4; i++) {
        m0 = d4 * p[0];
        m1 = d8 * p[1];
        m2 = dc * p[2];
        if (m0 + m1 + m2 < arg1) {
            return 0;
        }
        p += 3;
    }
    return 1;
}
/* fzgx:end fn_1_54F5C */

/* fzgx:begin fn_1_550A8 */
void fn_1_550A8(void) {
    fn_800794F0(lbl_1_bss_6C710, (u8 *)lbl_801A66CC + 0x50, 0x84);
}
/* fzgx:end fn_1_550A8 */

/* fzgx:begin fn_1_550E0 */
void fn_1_550E0(void) {
    fn_800794F0((u8 *)lbl_801A66CC + 0x50, lbl_1_bss_6C710, 0x84);
}
/* fzgx:end fn_1_550E0 */

/* fzgx:begin fn_1_55118 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern u32 lbl_801A6410;
extern const f32 lbl_1_rodata_28A8;
extern void fn_800777D4(void);
extern void fn_1_565F8(void);
extern void fn_80072808(void);
extern void fn_1_56664(void *);
extern void fn_1_566A0(void *);
extern u32 fn_80070DE0(u32);
extern u32 fn_80070DF0(u32);
extern void *memset(void *, int, u32);
extern void fn_1_566EC(int, int);
extern void fn_800749B0(s32, void *);

typedef struct {
    u8 color[4];
    u8 shadow[4];
    f32 scale;
    u8 flags[6];
    u8 pad[0x16];
} InitSettings;
typedef struct {
    u32 initial;
    u32 count;
    f32 scale;
    InitSettings settings;
    u32 last;
} InitState;

static inline void init_settings(InitSettings *settings) {
    memset(settings, 0, 0x28);
    settings->color[0] = 255;
    settings->color[1] = 255;
    settings->color[2] = 255;
    settings->color[3] = 255;
    settings->shadow[0] = 0;
    settings->shadow[1] = 0;
    settings->shadow[2] = 0;
    settings->shadow[3] = 0;
    settings->scale = lbl_1_rodata_28A8;
    settings->flags[0] = 1;
    settings->flags[1] = 3;
    settings->flags[2] = 1;
    settings->flags[3] = 0;
    settings->flags[4] = 0;
    settings->flags[5] = 0;
}

typedef struct lbl_1_bss_6C7CC_t {
    u32 last;
    u8 pad_4[0xc];
} lbl_1_bss_6C7CC_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_6C798;
u32 lbl_1_bss_6C79C;
f32 fzgx_obj_lbl_1_bss_6C7A0;
InitSettings fzgx_obj_lbl_1_bss_6C7A4;
lbl_1_bss_6C7CC_t fzgx_obj_lbl_1_bss_6C7CC;
u32 lbl_1_bss_6C7DC[25];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_6C798;
    s = *(u8 *)&lbl_1_bss_6C79C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6C7A0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6C7A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6C7CC;
    s = *(u8 *)&lbl_1_bss_6C7DC;
}
#pragma section code_type ".text"

void fn_1_55118(void) {
    
    InitSettings *settings;
    lbl_1_bss_6C798 = lbl_801A6410;
    fn_800777D4();
    fn_1_565F8();
    fn_80072808();
    fn_80070DE0((u32)fn_1_56664);
    fn_80070DF0((u32)fn_1_566A0);
    lbl_1_bss_6C79C = 0x60;
    fzgx_obj_lbl_1_bss_6C7A0 = lbl_1_rodata_28A8;
    init_settings(&fzgx_obj_lbl_1_bss_6C7A4);
    fn_1_566EC(0, 0);
    fn_800749B0(0, 0);
    fzgx_obj_lbl_1_bss_6C7CC.last = 0;
}
/* fzgx:end fn_1_55118 */

/* fzgx:begin fn_1_55210 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern const f32 lbl_1_rodata_28A8;
extern void *lbl_801A66CC;

extern void fn_1_556B8(void *value);
extern void fn_1_563E4(Obj_1_bss_6C7A4 *settings);
extern void fn_800780A4(void *value);
extern void *fn_1_5448C(void *value);
extern void *fn_1_548AC(s32 size);
extern void fn_1_55EA0(void);
extern void lbl_8006DB74(void *value);
extern u16 fn_1_7BE94(void);
extern void lbl_8006DD14(void *value, void *data);
extern void fn_1_5489C(void *value, void *data);
extern void fn_1_56530(void);
extern void fn_1_557C4(void *value);

typedef struct {
    u8 pad_0[4];
    void (*callback)(void);
    void *context;
    u8 pad_c[0x30];
    u16 unk_3C;
    u8 pad_3E[2];
    Obj_1_bss_6C7A4 unk_40;
    void *entry[4];
} Fn1_55210_Object;

static inline void * fn_1_55210_array_read(void * *array, s32 index) { return array[index]; }
void fn_1_55210(void *value) {
    s32 offset;
    Fn1_55210_Object *obj;
    void *result;
    s32 ok;
    s32 i;

    if (lbl_1_rodata_28A8 == lbl_1_bss_6C7A4.unk_8) {
        if (*(u16 *)((u8 *)value + 0x1c) == 0) {
            fn_1_556B8(value);
            return;
        }
        if ((0) != (*(u16 *)((u8 *)value + 0x1a))) {
            fn_1_563E4(&lbl_1_bss_6C7A4);
            fn_800780A4(value);
        }
        result = fn_1_5448C((u8 *)value + 8);
        obj = fn_1_548AC(0x78);
        if (obj != 0) {
            obj->callback = fn_1_55EA0;
            obj->context = value;
            ok = 1;
            lbl_8006DB74((u8 *)obj + 0xc);
            obj->unk_3C = fn_1_7BE94();
            obj->unk_40 = lbl_1_bss_6C7A4;
            for (i = 0, offset = 0; i < 4; i++, offset += 0x30) {
                if ((__rlwnm(lbl_1_bss_6C7CC.unk_0, ((i + 1) & 31), 31, 31) != 0)) {
                    obj->entry[i] = fn_1_548AC(0x30);
                    if (fn_1_55210_array_read(obj->entry, i) != 0) {
                        lbl_8006DD14(((((((((u8 *)lbl_801A66CC))) + (((offset)))) + (((0xe0)))))), fn_1_55210_array_read(obj->entry, i));
                    } else {
                        ok = 0;
                    }
                } else {
                    obj->entry[i] = 0;
                }
            }
            if (ok != 0) {
                fn_1_5489C(result, obj);
            }
        }
        fn_1_56530();
    } else {
        fn_1_557C4(value);
    }
}
/* fzgx:end fn_1_55210 */

/* fzgx:begin fn_1_553C4 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern const f32 lbl_1_rodata_28A8;
extern void *lbl_801A66CC;

extern void fn_1_556B8(void *value);
extern void fn_1_563E4(Obj_1_bss_6C7A4 *settings);
extern void fn_800780A4(void *value);
extern void *fn_1_54448(void *value);
extern void *fn_1_548AC(s32 size);
extern void fn_1_55EA0(void);
extern void lbl_8006DB74(void *value);
extern u16 fn_1_7BE94(void);
extern void lbl_8006DD14(void *value, void *data);
extern void fn_1_5489C(void *value, void *data);
extern void fn_1_56530(void);
extern void fn_1_55924(void *value, void *arg);

typedef struct {
    u8 pad_0[4];
    void (*callback)(void);
    void *context;
    u8 pad_c[0x30];
    u16 unk_3C;
    u8 pad_3E[2];
    Obj_1_bss_6C7A4 unk_40;
    void *entry[4];
} Fn1_553C4_Object;

static inline void * fn_1_553C4_array_read(void * *array, s32 index) { return array[index]; }
void fn_1_553C4(void *value, void *arg) {
    s32 offset;
    Fn1_553C4_Object *obj;
    void *result;
    s32 ok;
    s32 i;
    u32 bit;

    if (lbl_1_rodata_28A8 == lbl_1_bss_6C7A4.unk_8) {
        if (*(u16 *)((u8 *)value + 0x1c) == 0) {
            fn_1_556B8(value);
            return;
        }
        if (((0) != (*(u16 *)((u8 *)value + 0x1a)))) {
            fn_1_563E4(&lbl_1_bss_6C7A4);
            fn_800780A4(value);
        }
        result = fn_1_54448(arg);
        obj = fn_1_548AC(0x78);
        if (obj != 0) {
            obj->callback = fn_1_55EA0;
            obj->context = value;
            ok = 1;
            lbl_8006DB74((u8 *)obj + 0xc);
            obj->unk_3C = fn_1_7BE94();
            obj->unk_40 = lbl_1_bss_6C7A4;
            for (i = 0, offset = 0; i < 4; i++, offset += 0x30) {
                if ((__rlwnm(lbl_1_bss_6C7CC.unk_0, ((i + 1) & 31), 31, 31) != 0)) {
                    obj->entry[i] = fn_1_548AC(0x30);
                    if (fn_1_553C4_array_read(obj->entry, i) != 0) {
                        lbl_8006DD14(((((((((u8 *)lbl_801A66CC))) + (((offset)))) + (((0xe0)))))), fn_1_553C4_array_read(obj->entry, i));
                    } else {
                        ok = 0;
                    }
                } else {
                    obj->entry[i] = 0;
                }
            }
            if (ok != 0) {
                fn_1_5489C(result, obj);
            }
        }
        fn_1_56530();
    } else {
        fn_1_55924(value, arg);
    }
}
/* fzgx:end fn_1_553C4 */

/* fzgx:begin fn_1_5557C */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_5557CObject;

void fn_1_5557C(Fn1_5557CObject *value) {
    if (fn_1_54F5C( (void *)((u8 *)&value->unk_08), value->unk_14, lbl_1_bss_6C7A0)) {
        fn_1_55210(value);
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_5557C */

/* fzgx:begin fn_1_555D0 */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_555D0Object;

void fn_1_555D0(Fn1_555D0Object *value) {
    if (fn_1_54F5C( (void *)((u8 *)&value->unk_08), value->unk_14, lbl_1_bss_6C7A0)) {
        fn_80072558();
        fn_1_55210(value);
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_555D0 */

/* fzgx:begin fn_1_55628 */
typedef struct {
    u8 pad_00[0x1C];
    u16 unk_1C;
} Fn1_55628Object;

void fn_1_55628(Fn1_55628Object *value) {
    if (value->unk_1C != 0 || lbl_1_rodata_28A8 != lbl_1_bss_6C7A4.unk_8) {
        fn_1_557C4(value);
    } else {
        fn_1_556B8(value);
    }
}
/* fzgx:end fn_1_55628 */

/* fzgx:begin fn_1_55678 */
void fn_1_55678(void *value) {
    fn_1_563E4( (fn_1_563E4_FontState *)(void *)(&lbl_1_bss_6C7A4));
    fn_80077E7C(value);
    fn_1_56530();
}
/* fzgx:end fn_1_55678 */

/* fzgx:begin fn_1_556B8 */
/* Completes the font operation for the supplied value. */
void fn_1_556B8(void *value) {
    fn_1_563E4( (fn_1_563E4_FontState *)(void *)(&lbl_1_bss_6C7A4));
    fn_80077F8C(value);
    fn_1_56530();
}
/* fzgx:end fn_1_556B8 */

/* fzgx:begin fn_1_556F8 */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_556F8Object;

/* Finishes the current font operation after testing its scale threshold. */
void fn_1_556F8(Fn1_556F8Object *value) {
    if (fn_1_54F5C( (void *)((u8 *)&value->unk_08), value->unk_14, lbl_1_bss_6C7A0)) {
        fn_1_563E4( (fn_1_563E4_FontState *)(void *)(&lbl_1_bss_6C7A4));
        fn_80077F8C(value);
        fn_1_56530();
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_556F8 */

/* fzgx:begin fn_1_5575C */
typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Fn1_5575CObject;

void fn_1_5575C(Fn1_5575CObject *value) {
    if (fn_1_54F5C( (void *)((u8 *)&value->unk_08), value->unk_14, lbl_1_bss_6C7A0)) {
        fn_80072558();
        fn_1_563E4( (fn_1_563E4_FontState *)(void *)(&lbl_1_bss_6C7A4));
        fn_80077F8C(value);
        fn_1_56530();
        return;
    }

    fn_1_56530();
}
/* fzgx:end fn_1_5575C */

/* fzgx:begin fn_1_557C4 */
typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wC;
    u32 w10;
    u32 w14;
    u32 w18;
    u32 w1C;
    u32 w20;
    u32 w24;
} Words28;

typedef struct {
    u8 pad_00[4];
    u32 unk_04;
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 pad_3E[2];
    Obj_1_bss_6C7A4 unk_40;
    void *unk_68[4];
} Fn1_557C4Object;

void fn_1_557C4(void *value) {
    s32 offset;
    Fn1_557C4Object *object;
    void *resource;
    s32 valid;
    s32 i;
    u32 shift;
    u32 word;
    Obj_1_bss_6C7CC *bits;

    resource = (void *)fn_1_5448C((u8 *)value + 8);
    object = fn_1_548AC(0x78);
    if (object != 0) {
        valid = 1;
        object->unk_04 = (u32)fn_1_55C48;
        object->unk_08 = value;
        lbl_8006DB74(((0xC) + ((u8 *)object)));
        object->unk_3C = fn_1_7BE94();
        object->unk_40 = lbl_1_bss_6C7A4;
        bits = &lbl_1_bss_6C7CC;
        for (i = 0, offset = 0; i < 4; i++, offset += 0x30) {
            if ((__rlwnm(bits->unk_0, ((i + 1) & 0x1f), 31, 31) != 0)) {
                object->unk_68[i] = fn_1_548AC(0x30);
                if ((*((object->unk_68) + (i))) != 0) {
                    lbl_8006DD14(lbl_801A66CC + offset + 0xE0, (*((object->unk_68) + (i))));
                } else {
                    valid = 0;
                }
            } else {
                object->unk_68[i] = 0;
            }
        }
        if (valid != 0) {
            fn_1_5489C( (void **)(void *)(resource), (void **)(void *)(object));
        }
    }
    fn_1_56530();
}
/* fzgx:end fn_1_557C4 */

/* fzgx:begin fn_1_55924 */
typedef struct {
    u8 pad_00[0x4];
    void *vtable;
    void *owner;
    u8 pad_0C[0x30];
    u16 unk_3C;
    u8 pad_3E[0x2];
    Obj_1_bss_6C7A4 settings;
    void *items[4];
} Fn1_55924Object;

void fn_1_55924(void *value, void *arg) {
    Fn1_55924Object *object;
    void *handle;
    s32 ok;
    s32 i;
    Obj_1_bss_6C7CC *flags;

    handle = (void *)fn_1_54448( (s32)(void *)(arg));
    object = (Fn1_55924Object *)fn_1_548AC(0x78);
    if (object != 0) {
        object->vtable = (void *)fn_1_55C48;
        object->owner = value;
        ok = 1;
        lbl_8006DB74((u8 *)object + 0xC);
        object->unk_3C = fn_1_7BE94();
        object->settings = lbl_1_bss_6C7A4;
        flags = &lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (__rlwnm(flags->unk_0, (i + 1) & 31, 31, 31)) {
                object->items[i] = fn_1_548AC(0x30);
                if (object->items[i] != 0) {
                    lbl_8006DD14((((i * 0x30) + ((u8 *)lbl_801A66CC)) + (0xE0)), object->items[i]);
                } else {
                    ok = 0;
                }
            } else {
                object->items[i] = 0;
            }
        }
        if (ok != 0) {
            fn_1_5489C( (void **)(void *)(handle), (void **)(void *)(object));
        }
    }
    fn_1_56530();
}
/* fzgx:end fn_1_55924 */

/* fzgx:begin fn_1_55A84 */
typedef struct {
    u8 pad_00[0x1c];
    u16 unk_1c;
} FontInput;

typedef struct {
    u8 pad_00[0x4];
    void (*destroy)(void);
    void *owner;
    u8 pad_0c[0x30];
    u16 unk_3c;
    u8 pad_3e[0x2];
    Obj_1_bss_6C7A4 settings;
    void *unk_68;
    u8 pad_6c[0xc];
    void *unk_78;
    void *unk_7c;
    void *unk_80;
} FontObject;

typedef void (*FontCallback)(void *, void *, void *);

void fn_1_55A84(FontCallback callback, FontInput *value, void *arg2, void *arg3) {
    u16 fzgx_value;
    FontObject *cursor;
    int offset;
    FontObject *object;
    void *data;
    int ok;
    int i;
    u32 shift;
    u32 *flags;

    if (value->unk_1c != 0 || lbl_1_rodata_28A8 != lbl_1_bss_6C7A4.unk_8) {
        data = (void *)fn_1_5448C((u8 *)value + 8);
        object = (FontObject *)fn_1_548AC(0x84);
        if (object != 0) {
            ok = 1;
            object->destroy = fn_1_55D6C;
            object->owner = value;
            lbl_8006DB74((u8 *)object + 0xc);
            fzgx_value = fn_1_7BE94();
            object->unk_3c = fzgx_value;
            object->settings = lbl_1_bss_6C7A4;
            i = 0;
            offset = 0;
            cursor = object;
            flags = (u32 *)&lbl_1_bss_6C7CC;
            while (i < 4) {
                shift = (i + 1) & 31;
                if ((__rlwnm(*flags, shift, 31, 31) != 0)) {
                    cursor->unk_68 = fn_1_548AC(0x30);
                    if (cursor->unk_68 != 0) {
                        lbl_8006DD14(lbl_801A66CC + offset + 0xe0, cursor->unk_68);
                    } else {
                        ok = 0;
                    }
                } else {
                    cursor->unk_68 = 0;
                }
                i++;
                cursor = (FontObject *)((u8 *)cursor + 4);
                offset += 0x30;
            }
            object->unk_78 = arg2;
            object->unk_7c = arg3;
            object->unk_80 = callback;
            if (ok != 0) {
                fn_1_5489C( (void **)(void *)(data), (void **)(void *)(object));
            }
        }
        fn_1_56530();
    } else {
        fn_1_563E4( (fn_1_563E4_FontState *)(void *)(&lbl_1_bss_6C7A4));
        callback(value, arg2, arg3);
        fn_1_56530();
    }
}
/* fzgx:end fn_1_55A84 */

/* fzgx:begin fn_1_55C48 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern void lbl_8006DBAC(void *value);
extern void fn_80072558(void);
extern void fn_800749B0(s32 index, void *value);
extern void fn_80077F8C(void *value);
extern u8 lbl_801A66CC[];

typedef struct {
    u8 unk_00[8];
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 unk_3E[2];
    u8 unk_40[0x28];
    void *unk_68;
} Fn1_55C48Object;

static inline void * fn_1_55C48_read_pointer(Fn1_55C48Object * owner) { return owner->unk_68; }

static inline void * fn_1_55C48_read_pointer_(Fn1_55C48Object * owner) { return owner->unk_08; }
void fn_1_55C48(Fn1_55C48Object *value) {
    Fn1_55C48Object * entry;
    s32 lab_t0__2;
    s32 lab_t0_;
    u32 lab_t0;
    s32 offset;
    Fn1_55C48Object * entry_2;
    lbl_8006DBAC((u8 *)value + 0xc);
    fn_80072558();
    fn_1_56470((u8 *)value + 0x40);
    fn_1_7BEAC(value->unk_3C);

    {

        s32 i;
        Obj_1_bss_6C7CC *state;

        entry = value;
        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (((0) != (fn_1_55C48_read_pointer(entry)))) {
                lab_t0 = i;
                lab_t0_ = lab_t0;
                fn_800749B0(lab_t0_, fn_1_55C48_read_pointer(entry));
            } else if ((__rlwnm(state->unk_0, ((u32)(i + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = i;
                fn_800749B0(lab_t0__2, 0);
            }
            entry = (Fn1_55C48Object *)((u8 *)entry + 4);
        }
    }

    fn_80077F8C(fn_1_55C48_read_pointer_(value));
    fn_1_56554();

    {
        u32 *table;
        Obj_1_bss_6C7CC *state;

        s32 j;

        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        table = (u32 *)&lbl_801A66CC;
        entry_2 = value;
        for (j = 0, offset = 0; j < 4; j++, offset += 0x30, entry_2 = (Fn1_55C48Object *)((u8 *)entry_2 + 4)) {
            if ((__rlwnm(state->unk_0, ((u32)(j + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, (((0xe0) + ((u8 *)*table)) + (offset)));
            } else if (fn_1_55C48_read_pointer(entry_2) != 0) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, 0);
            }
        }
    }
}


/* fzgx:end fn_1_55C48 */

/* fzgx:begin fn_1_55D6C noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern void lbl_8006DBAC(void *value);
extern void fn_80072558(void);
extern void fn_800749B0(s32 index, void *value);
extern u8 lbl_801A66CC[];

typedef struct {
    u8 unk_00[8];
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 unk_3E[2];
    u8 unk_40[0x28];
    void *unk_68;
    u8 unk_70[0xC];
    u32 unk_78;
    u32 unk_7C;
    void (*unk_80)(void *, u32, u32);
} Fn1_55D6CObject;

static inline void * fn_1_55D6C_read_pointer(Fn1_55D6CObject * owner) { return owner->unk_68; }

static inline void * fn_1_55D6C_read_pointer_(Fn1_55D6CObject * owner) { return owner->unk_08; }
void fn_1_55D6C(Fn1_55D6CObject *value) {
    Fn1_55D6CObject * entry;
    s32 lab_t0__2;
    s32 lab_t0_;
    u32 lab_t0;
    s32 offset;
    Fn1_55D6CObject * entry_2;
    lbl_8006DBAC((u8 *)value + 0xc);
    fn_80072558();
    fn_1_56470((u8 *)value + 0x40);
    fn_1_7BEAC(value->unk_3C);

    {

        s32 i;
        Obj_1_bss_6C7CC *state;

        entry = value;
        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (((0) != (fn_1_55D6C_read_pointer(entry)))) {
                lab_t0 = i;
                lab_t0_ = lab_t0;
                fn_800749B0(lab_t0_, fn_1_55D6C_read_pointer(entry));
            } else if ((__rlwnm(state->unk_0, ((u32)(i + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = i;
                fn_800749B0(lab_t0__2, 0);
            }
            entry = (Fn1_55D6CObject *)((u8 *)entry + 4);
        }
    }

    value->unk_80(fn_1_55D6C_read_pointer_(value), value->unk_78, value->unk_7C);
    fn_1_56554();

    {
        u32 *table;
        Obj_1_bss_6C7CC *state;

        s32 j;

        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        table = (u32 *)&lbl_801A66CC;
        entry_2 = value;
        for (j = 0, offset = 0; j < 4; j++, offset += 0x30, entry_2 = (Fn1_55D6CObject *)((u8 *)entry_2 + 4)) {
            if ((__rlwnm(state->unk_0, ((u32)(j + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, (((0xe0) + ((u8 *)*table)) + (offset)));
            } else if (fn_1_55D6C_read_pointer(entry_2) != 0) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, 0);
            }
        }
    }
}


/* fzgx:end fn_1_55D6C */

/* fzgx:begin fn_1_55EA0 noprologue */
#include "types.h"
#include "rel/main_rel/font.h"

extern void lbl_8006DBAC(void *value);
extern void fn_80072558(void);
extern void fn_800749B0(s32 index, void *value);
extern void fn_800781B8(void *value);
extern u8 lbl_801A66CC[];

typedef struct {
    u8 unk_00[8];
    void *unk_08;
    u8 unk_0C[0x30];
    u16 unk_3C;
    u8 unk_3E[2];
    u8 unk_40[0x28];
    void *unk_68;
} Fn1_55EA0Object;

static inline void * fn_1_55EA0_read_pointer(Fn1_55EA0Object * owner) { return owner->unk_68; }

static inline void * fn_1_55EA0_read_pointer_(Fn1_55EA0Object * owner) { return owner->unk_08; }
void fn_1_55EA0(Fn1_55EA0Object *value) {
    Fn1_55EA0Object * entry;
    s32 lab_t0__2;
    s32 lab_t0_;
    u32 lab_t0;
    s32 offset;
    Fn1_55EA0Object * entry_2;
    lbl_8006DBAC((u8 *)value + 0xc);
    fn_80072558();
    fn_1_56470((u8 *)value + 0x40);
    fn_1_7BEAC(value->unk_3C);

    {

        s32 i;
        Obj_1_bss_6C7CC *state;

        entry = value;
        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        for (i = 0; i < 4; i++) {
            if (((0) != (fn_1_55EA0_read_pointer(entry)))) {
                lab_t0 = i;
                lab_t0_ = lab_t0;
                fn_800749B0(lab_t0_, fn_1_55EA0_read_pointer(entry));
            } else if ((__rlwnm(state->unk_0, ((u32)(i + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = i;
                fn_800749B0(lab_t0__2, 0);
            }
            entry = (Fn1_55EA0Object *)((u8 *)entry + 4);
        }
    }

    fn_800781B8(fn_1_55EA0_read_pointer_(value));
    fn_1_56554();

    {
        u32 *table;
        Obj_1_bss_6C7CC *state;

        s32 j;

        state = (Obj_1_bss_6C7CC *)&lbl_1_bss_6C7CC;
        table = (u32 *)&lbl_801A66CC;
        entry_2 = value;
        for (j = 0, offset = 0; j < 4; j++, offset += 0x30, entry_2 = (Fn1_55EA0Object *)((u8 *)entry_2 + 4)) {
            if ((__rlwnm(state->unk_0, ((u32)(j + 1) % 32), 31, 31) != 0)) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, (((0xe0) + ((u8 *)*table)) + (offset)));
            } else if (fn_1_55EA0_read_pointer(entry_2) != 0) {
                lab_t0__2 = j;
                fn_800749B0(lab_t0__2, 0);
            }
        }
    }
}


/* fzgx:end fn_1_55EA0 */

/* fzgx:begin fn_1_55FC4 */
void fn_1_55FC4(f32 value) {
    lbl_1_bss_6C7A0 = value;
}
/* fzgx:end fn_1_55FC4 */

/* fzgx:begin fn_1_55FD0 */
void fn_1_55FD0(void) {
    fn_80074CF4();
}
/* fzgx:end fn_1_55FD0 */

/* fzgx:begin fn_1_55FF0 */
void fn_1_55FF0(f32 value) {
    lbl_1_bss_6C7A4.unk_8 = value;
}
/* fzgx:end fn_1_55FF0 */

/* fzgx:begin fn_1_56000 */
void fn_1_56000(u8 value0, u8 value1, u8 value2) {
    lbl_1_bss_6C7A4.unk_C = value0;
    lbl_1_bss_6C7A4.unk_D = value1;
    lbl_1_bss_6C7A4.unk_E = value2;
}
/* fzgx:end fn_1_56000 */

/* fzgx:begin fn_1_56018 */
u32 fn_1_56018(s32 value) {
    s32 i;
    u32 result;

    result = (u32)((-(s32)lbl_1_bss_6C7CC.unk_0 | lbl_1_bss_6C7CC.unk_0) >> 31);
    if (value == 0) {
        for (i = 0; i < 4; i++) {
            if (__rlwnm((s32)lbl_1_bss_6C7CC.unk_0, (i + 1) & 31, 31, 31)) {
                fn_800749B0(0, (void *)0);
            }
        }
        lbl_1_bss_6C7CC.unk_0 = 0;
    } else {
        for (i = 0; i < 4; i++) {
            if (__rlwnm((s32)lbl_1_bss_6C7CC.unk_0, (i + 1) & 31, 31, 31)) {
                fn_800749B0(i, (void *)((u8 *)*(void **)&(*(void * *)&lbl_801A66CC) + i * 0x30 + 0xe0));
            }
        }
    }
    return result;
}
/* fzgx:end fn_1_56018 */

/* fzgx:begin fn_1_560F0 */
// Marks the selected font resource as active before handing it to the loader.
void fn_1_560F0(s32 index, void *arg) {
    if (arg != NULL) {
        lbl_1_bss_6C7CC.unk_0 |= (1u << 31) >> index;
        lbl_8006DD14(arg, lbl_801A66CC + index * 0x30 + 0xe0);
    }
    fn_800749B0(index, arg);
}
/* fzgx:end fn_1_560F0 */

/* fzgx:begin fn_1_5616C */
/* 0x30-byte slot in the table lbl_801A66CC points at */
typedef struct {
    f32 unk_0[12];
} FontSlot;

void fn_1_5616C(s32 value, f32 value1, f32 value2) {
    lbl_1_bss_6C7CC.unk_0 |= ((u32)1 << 31) >> value;

    lbl_8006D784(&(*(FontSlot * *)&lbl_801A66CC)[value].unk_0[0x38]);

    (*(FontSlot * *)&lbl_801A66CC)[value].unk_0[0x3b] = value1;
    (*(FontSlot * *)&lbl_801A66CC)[value].unk_0[0x3f] = value2;

    fn_800749B0(value, &(*(FontSlot * *)&lbl_801A66CC)[value].unk_0[0x38]);
}
/* fzgx:end fn_1_5616C */

/* fzgx:begin fn_1_5621C */
void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3) {
    ((u8 *)&lbl_1_bss_6C7A4)[0] = (u8)(lbl_1_rodata_28AC * value0);
    ((u8 *)&lbl_1_bss_6C7A4)[1] = (u8)(lbl_1_rodata_28AC * value1);
    ((u8 *)&lbl_1_bss_6C7A4)[2] = (u8)(lbl_1_rodata_28AC * value2);
    ((u8 *)&lbl_1_bss_6C7A4)[3] = (u8)(lbl_1_rodata_28AC * value3);
    fn_80074B40((u8 *)&lbl_1_bss_6C7A4);
}
/* fzgx:end fn_1_5621C */

/* fzgx:begin fn_1_56298 */
void fn_1_56298(f32 value0, f32 value1, f32 value2, f32 value3) {
    f32 scale = lbl_1_rodata_28AC;

    lbl_1_bss_6C7A4.unk_4 = (u8)(scale * value0);
    lbl_1_bss_6C7A4.unk_5 = (u8)(scale * value1);
    lbl_1_bss_6C7A4.unk_6 = (u8)(scale * value2);
    lbl_1_bss_6C7A4.unk_7 = (u8)(scale * value3);
    fn_80074C74(&lbl_1_bss_6C7A4.unk_4);
}
/* fzgx:end fn_1_56298 */

/* fzgx:begin fn_1_5631C */
void fn_1_5631C(const u32 *value) {
    Obj_1_bss_6C7A4 *state = &lbl_1_bss_6C7A4;

    // Store the incoming value in the shared font state before notifying the subsystem.
    *(volatile u32 *)&state->unk_4 = *value;
    fn_80074C74((u8 *)value);
}
/* fzgx:end fn_1_5631C */

/* fzgx:begin fn_1_5634C */
void fn_1_5634C(u8 value) {
    lbl_1_bss_6C7A4.unk_12 = value;
}
/* fzgx:end fn_1_5634C */

/* fzgx:begin fn_1_5635C */
void fn_1_5635C(u8 value, f32 value2, f32 value3) {
    lbl_1_bss_6C7A4.unk_13 = value;
    *(f32 *)&lbl_1_bss_6C7A4.unk_18 = value2;
    *(f32 *)&lbl_1_bss_6C7A4.unk_1C = value3;
}
/* fzgx:end fn_1_5635C */

/* fzgx:begin fn_1_56374 */
void fn_1_56374(u8 value1, u8 value2, u8 value3) {
    lbl_1_bss_6C7A4.unk_14 = value1;
    lbl_1_bss_6C7A4.unk_15 = value2;
    lbl_1_bss_6C7A4.unk_16 = value3;
}
/* fzgx:end fn_1_56374 */

/* fzgx:begin fn_1_5638C */
// Stores the current value for the font subsystem and refreshes its state.
void fn_1_5638C(u32 value) {
    lbl_1_bss_6C7A4.unk_20 = value;
    fn_80074A7C();
}
/* fzgx:end fn_1_5638C */

/* fzgx:begin fn_1_563B8 */
void fn_1_563B8(u32 value) {
    lbl_1_bss_6C7A4.unk_24 = value;
    fn_80077BAC();
}
/* fzgx:end fn_1_563B8 */

/* fzgx:begin fn_1_563E4 */
void fn_1_563E4(fn_1_563E4_FontState *font) {
    u32 value;
    u32 lab_t0;
    u32 lab_t2;

    fn_80077B04(font->scale);
    lab_t0 = font->pad_0C[0];
    lab_t2 = font->pad_0C[2];
    fn_80074918(lab_t0, font->pad_0C[1], lab_t2);
    if (font->state == 0) {
        if (font->enabled != 0) {
            fn_80071ED4(font->color, font->x, font->y);
            value = font->value;
            fn_80072014(&value);
            fn_800720B0(1);
        } else {
            fn_800720B0(0);
        }
    }
}
/* fzgx:end fn_1_563E4 */

/* fzgx:begin fn_1_56470 */
typedef struct fn_1_56470_FontState {
    u8 unk_00[4];
    void *unk_04;
    f32 unk_08;
    s8 unk_0C;
    u8 unk_0D;
    s8 unk_0E;
    u8 unk_0F;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u32 unk_20;
    u32 unk_24;
} fn_1_56470_FontState;


void fn_1_56470(fn_1_56470_FontState *state) {
    u32 value;

    fn_80077B04( state->unk_08);
    fn_80074B40( (u8 *)(fn_1_56470_FontState *)(state));
    fn_80074C74( (u8 *)(void *)(&state->unk_04));
    fn_80074918(state->unk_0C, state->unk_0D, state->unk_0E);
    fn_80077BBC(state->unk_0F);
    fn_80037D40(state->unk_10, state->unk_11);
    fn_80074A7C(state->unk_20);
    fn_80077BAC(state->unk_24);
    if (state->unk_24 == 0) {
        if (state->unk_12 != 0) {
            fn_80071ED4(state->unk_13, state->unk_18, state->unk_1C);
            value = state->unk_14;
            fn_80072014( (u32 *)(void *)(&value));
            fn_800720B0(1);
        } else {
            fn_800720B0(0);
        }
    }
}
/* fzgx:end fn_1_56470 */

/* fzgx:begin fn_1_56530 */
void fn_1_56530(void) {
    lbl_1_bss_6C7A0 = lbl_1_rodata_28A8;
    lbl_1_bss_6C7A4.unk_8 = lbl_1_rodata_28A8;
}
/* fzgx:end fn_1_56530 */

/* fzgx:begin fn_1_56554 */
void fn_1_56554(void) {
    u32 lab_t0;
    u32 lab_t2;
    Obj_1_bss_6C7A4 *font = &lbl_1_bss_6C7A4;

    fn_80074B40( (u8 *)(void *)(font));
    fn_80074C74( (u8 *)(void *)(&font->unk_4));
    lab_t0 = font->unk_C;
    lab_t2 = font->unk_E;
    fn_80074918(lab_t0, font->unk_D, lab_t2);
    fn_80077BBC(font->unk_F);
    fn_80037D40(font->unk_10, font->unk_11);
    fn_80074A7C(font->unk_20);
    fn_80077BAC(font->unk_24);
}
/* fzgx:end fn_1_56554 */

/* fzgx:begin fn_1_565E8 */
// Return the font data buffer used by the font subsystem.
u8 *fn_1_565E8(void) {
    return lbl_1_bss_6C7DC;
}
/* fzgx:end fn_1_565E8 */

/* fzgx:begin fn_1_565F4 */
// fn_1_565F4: empty in retail (single blr).
void fn_1_565F4(void) {
}
/* fzgx:end fn_1_565F4 */

/* fzgx:begin fn_1_565F8 */
// Registers the font initialization callbacks with the shared dispatcher.
void fn_1_565F8(void) {
    void (*callbacks[6])(void);

    callbacks[0] = (void (*)(void))fn_1_565E8;
    callbacks[1] = fn_1_45730;
    callbacks[2] = fn_1_45B2C;
    callbacks[3] = fn_1_458A0;
    callbacks[4] = fn_1_45850;
    callbacks[5] = fn_1_565F4;
    fn_80070D60(callbacks);
}
/* fzgx:end fn_1_565F8 */
