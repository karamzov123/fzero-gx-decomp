#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

extern u32 lbl_1_bss_6C8DC[2];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_727BC(u32 arg0, u32 arg1, void *arg2);
extern void fn_1_76A94(void *arg0, u32 arg1);
extern void fn_1_76DBC(void);
extern void fn_80072864(int arg0);
extern void fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8006FD1C(void);
extern void fn_1_79810(void);
extern void fn_1_79948(void);
extern void fn_1_791B0(void);
extern void fn_1_9A1E8(void);

extern void fn_1_727BC();
extern void fn_8006FDEC(void);

/* fzgx:begin fn_1_72648 */
void fn_1_72648(void) {
    if (lbl_1_bss_6C8DC[0] != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_6C8DC[0], lbl_1_data_1DAC0, 0xf9);
        lbl_1_bss_6C8DC[0] = 0;
    }
}
/* fzgx:end fn_1_72648 */

/* fzgx:begin fn_1_7269C */
typedef struct {
    u8 pad_0[0xa0];
    u32 unk_A0;
    u8 pad_A4[0x24];
    u32 unk_C8;
} fn_1_7269C_ScreenEffectEntry;

void fn_1_7269C(u32 arg0, u32 arg1, void *arg2) {
    fn_1_7269C_ScreenEffectEntry *object;

    object = (fn_1_7269C_ScreenEffectEntry *)((u8 *)&lbl_1_bss_6C8EC + (arg0 & 0xff) * 0x10c);
    fn_1_727BC(arg0, arg1, arg2);
    ((fn_1_7269C_ScreenEffectEntry *)((u8 *)object + (arg1 & 0xff) * 4))->unk_A0 = (u32)arg2;
    ((fn_1_7269C_ScreenEffectEntry *)((u8 *)object + (arg1 & 0xff) * 4))->unk_C8 = 1;
    fn_1_76A94(object, arg1);
    fn_1_76DBC();
}
/* fzgx:end fn_1_7269C */

/* fzgx:begin fn_1_72714 */
// Initialize the effect system and return the requested slot subregion.
void *fn_1_72714(u8 slot, u32 subregion) {
    Obj_1_bss_6C8EC *entry;
    u32 offset;

    fn_1_727BC();
    entry = (Obj_1_bss_6C8EC *)((u8 *)&lbl_1_bss_6C8EC + slot * 0x10c);
    offset = (subregion & 0xff) * 0x20;
    return (u8 *)entry + offset;
}
/* fzgx:end fn_1_72714 */

/* fzgx:begin fn_1_72768 */
// Initialize the selected screen-effect slot with its requested value.
void fn_1_72768(u32 arg0, u32 arg1) {
    Obj_1_bss_6C8EC *entry;
    u32 index;

    fn_1_727BC(arg0, 0);
    index = (u8)arg0;
    entry = (Obj_1_bss_6C8EC *)((u8 *)&lbl_1_bss_6C8EC + index * 0x10c);
    entry->unk_104 = arg1;
}
/* fzgx:end fn_1_72768 */

/* fzgx:begin fn_1_727BC noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

Obj_1_data_1D960 lbl_1_data_1D960 = {{0x00,0x00,0x00,0x01}, 0x00000011, {0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x39,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x3A,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x13,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x27}};
Obj_1_data_1D9B8 lbl_1_data_1D9B8 = {{0x00,0x00,0x00,0x00,0x00}, 0x00, {0x06,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00,0x01,0x06,0x06,0x00,0x00,0x00,0x02,0x06,0x06,0x00,0x00,0x00,0x02,0x06,0x06,0x00,0x00,0x00,0x02,0x06,0x06,0x00,0x00,0x00,0x02,0x00,0x01,0x06,0x00,0x00,0x03,0x00,0x01,0x06,0x00,0x00,0x03,0x00,0x01,0x06,0x00,0x00,0x03,0x00,0x01,0x06,0x03,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x01,0x04,0x06,0x00,0x00,0x00,0x02,0x04,0x06,0x00,0x00,0x00,0x02,0x04,0x06,0x00,0x00,0x00,0x02,0x04,0x06,0x00,0x00,0x00,0x02,0x04,0x06,0x00,0x00,0x00,0x02,0x04,0x06,0x00,0x00,0x00,0x02,0x04,0x06,0x00,0x00,0x00,0x02,0x04,0x06,0x00,0x00,0x00,0x02,0x06,0x06,0x00,0x00,0x00,0x02,0x06,0x03,0x00,0x00,0x00,0x02,0x06,0x03,0x00,0x00,0x00,0x02,0x05,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00,0x01,0x05,0x04,0x00,0x00,0x00,0x02,0x09,0x00,0x00,0x00,0x00,0x01,0x04,0x08,0x00,0x00,0x00,0x02,0x04,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x06,0x00,0x00,0x03,0x06,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x07,0x00,0x00,0x03,0x04,0x00,0x00,0x00,0x00,0x01}};
u32 lbl_1_data_1DA9C[5] = {0x30506020, 0x38623420, 0x60605040, 0x60505030, 0x70504020};
u8 lbl_1_data_1DAB0[4] = {0x30,0x50,0x60,0x20};
f32 lbl_1_data_1DAB4 = 1.0f;
f32 lbl_1_data_1DAB8 = 1.0f;
u8 lbl_1_data_1DABC[4] = {0x08,0x00,0x00,0x00};
u8 lbl_1_data_1DAC0[] = "screen_effect.c";
char lbl_1_data_1DAD0[] = "Can't Double Create Heap\n";
char lbl_1_data_1DAEC[] = "Error! : Wrong Value.";

struct fn_1_727BC_lbl_1_data_1D960_58_E6 {
    u8 pad_0[0x5];
    u8 unk_5;
};
extern void OSPanic(const char *, int, const char *, ...);

void fn_1_727BC(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 v0;
    s32 v1;
    s32 v2;
    s32 v3;
    Obj_1_bss_6C8EC *obj;
    struct fn_1_727BC_lbl_1_data_1D960_58_E6 *table;
    s32 valid;
    v0 = (arg0 & 0xFF);
    obj = (Obj_1_bss_6C8EC *)((u8 *)&lbl_1_bss_6C8EC + v0 * 0x10C);
    if (v0 <= 7) {
        v1 = obj->unk_DC;
        v2 = (arg1 & 0xFF);
        table = (struct fn_1_727BC_lbl_1_data_1D960_58_E6 *)&lbl_1_data_1D9B8;
        v3 = (table)[v1].unk_5 - 1;
        valid = v2 <= v3;
        if (valid != 0U && v1 != 0) return;
    }
    OSPanic((const char *)lbl_1_data_1DAC0, 394, lbl_1_data_1DAEC);
}
/* fzgx:end fn_1_727BC */

/* fzgx:begin fn_1_72848 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

struct fn_1_76650_ScreenEffect;
extern void fn_1_76650(struct fn_1_76650_ScreenEffect *);

void fn_1_72848(void) {
    u8 i;

    // Reset each screen-effect entry before clearing the active-effect flag.
    for (i = 0; i < 8; i++) {
        fn_1_76650((struct fn_1_76650_ScreenEffect *)((u8 *)&lbl_1_bss_6C8EC + i * 0x10c));
    }
    lbl_1_bss_6D14C.unk_0 = 0;
}
/* fzgx:end fn_1_72848 */

/* fzgx:begin fn_1_728B0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"
extern void fn_1_4E500(void);
extern void fn_1_4E638(int);
extern void fn_1_4E6F4(void);

typedef struct {
    u8 pad_0[0xdc];
    s32 unk_DC;
    s32 unk_E0;
    u8 pad_E4[0x20];
    void (*unk_104)(void *);
} fn_1_728B0_ScreenEffectEntry;

struct Fn_1_72980_Obj;
struct fn_1_729F8_Arg0;
extern void fn_1_72980(struct Fn_1_72980_Obj *);
extern void *fn_1_729F8(struct fn_1_729F8_Arg0 *);

void fn_1_728B0(void) {
    u8 i;
    u8 *base;
    fn_1_728B0_ScreenEffectEntry *obj;
    void *result;

    if (lbl_1_bss_6D14C.unk_0 == 0) {
        fn_1_4E500();
        fn_1_4E638(0);
        base = (u8 *)&lbl_1_bss_6C8EC;
        for (i = 0; i < 8; i++) {
            obj = (fn_1_728B0_ScreenEffectEntry *)(base + i * 0x10c);
            if (obj->unk_DC != 0) {
                if (obj->unk_DC == 0xe && obj->unk_E0 == 0) {
                    obj->unk_E0 = obj->unk_E0 + 1;
                } else {
                    fn_1_72980((struct Fn_1_72980_Obj *)obj);
                    result = fn_1_729F8((struct fn_1_729F8_Arg0 *)obj);
                    if (obj->unk_104 != 0) {
                        obj->unk_104(result);
                    }
                }
            }
        }
        fn_1_4E6F4();
    }
}
/* fzgx:end fn_1_728B0 */

/* fzgx:begin fn_1_72980 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"
extern void fn_80073778(void *, s32);

typedef struct Fn_1_72980_Obj {
    u8 pad_0[0xdc];
    u32 unk_dc;
} Fn_1_72980_Obj;

void fn_1_72980(Fn_1_72980_Obj *arg0) {
    int index;
    u8 *entry;
    int i;

    entry = (u8 *)arg0;
    i = 0;
    index = 0;
    while (i < ((u8 *)&lbl_1_data_1D9B8)[arg0->unk_dc * 6 + 5]) {
        fn_80073778(entry, index);
        index++;
        entry += 0x20;
        i++;
    }
}
/* fzgx:end fn_1_72980 */

/* fzgx:begin fn_1_729F8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

struct fn_1_729F8_Arg0 {
    u8 pad_0[0xDC];
    s32 unk_DC;
    s32 unk_E0;
    f32 unk_E4;
    u16 unk_E8;
    u16 unk_EA;
    s16 unk_EC;
    s16 unk_EE;
    u16 unk_F0;
    u16 unk_F2;
    u32 unk_F4;
    u16 unk_F8;
    u16 unk_FA;
    u16 unk_FC;
    u16 unk_FE;
    u16 unk_100;
    u16 unk_102;
    u32 unk_104;
};

struct fn_1_729F8_Bss {
    u8 pad_0[0x8D0];
    u32 unk_8D0;
    u16 unk_8D4;
    u16 unk_8D6;
    u16 unk_8D8;
    u8 unk_8DA;
};

struct fn_1_729F8_Data {
    u8 pad_0[0x150];
    u8 unk_150[4];
    f32 unk_154;
    f32 unk_158;
};

struct fn_1_729F8_RoData {
    u32 w0;
    u32 w1;
    u32 w2;
    u32 w3;
    u32 w4;
    u32 w5;
    u32 w6;
    u32 w7;
};

extern f32 *lbl_801A6D00;
extern u32 lbl_801A66A0;



struct fn_1_75D84_Rect;
struct fn_1_75D84_Size;
struct fn_1_761B8_Arg0;
extern void fn_1_75D84(const f32 *, const struct fn_1_75D84_Rect *, struct fn_1_75D84_Size *);
extern void fn_1_761B8(struct fn_1_761B8_Arg0 *, u32);
extern void fn_1_76C60();
extern void fn_1_76EB8(void);
extern void fn_1_77200();
extern u32 fn_1_77C5C(void *, void *, void *);
extern u32 fn_1_4E220(void *, u32, u32, u32, u32);
extern void lbl_8006D758(void);
extern void lbl_8006D784(void *);
extern void lbl_8006E1B0(void *, void *);
extern void mathutil_mtxA_rotate_z(s32);
extern void fn_800371F8(u32, void *);
extern void fn_8003726C(u32, void *);
extern void fn_800720B0(u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072808(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_800729B0(s32, s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80072EDC(s32, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073678(u32);
extern void fn_800736C0(u32, void *);
extern void fn_80073778(void *, s32);
extern void fn_80073898(u32);
extern void fn_800738E0(s32, s32, s32);
extern void fn_800739E0(s32, s32, s32);
extern void fn_80073A58(int, void *, s8);
extern void fn_80073C6C(s32);
extern void fn_80073D60(s32, s32, s32, s32, s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8, s32, u8);
extern void GXLoadTexMtxImm(void *, u32, u32);
extern void GXSetAlphaCompare(s32, s32, s32, s32, s32);

union Color { struct {u8 r, g, b, a;} bytes; u32 word; };

/* The four vec3 rows and the colour/scratch words are members of a single
   aggregate each in the original; splitting them changes the stack layout. */
#define v168 vbuf
#define v174 (vbuf + 3)
#define v180 (vbuf + 6)
#define v18C (vbuf + 9)
#define w88 color88

void *fn_1_729F8(struct fn_1_729F8_Arg0 *arg0)
{
    struct fn_1_729F8_Bss *p_bss;
    f32 vbuf[12];
    f32 m138[12];
    f32 m108[12];
    f32 mD8[12];
    f32 aC0[6];
    f32 aA8[6];
    f32 a90[6];
    union Color color84 = {{0xFF,0xFF,0xFF,0xFF}};
    union Color color80;
    u32 color7c;
    u32 s78;
    u32 s74;
    u32 s70;
    u32 s6C;
    u32 s68;
    u32 s64;
    u32 s60;
    u32 s5C;
    u32 s58;
    u32 s54;
    u32 s50;
    u32 s4C;
    u32 s48;
    u32 s44;
    u32 s40;
    u32 s3C;
    u32 s38;
    u32 s34;
    u32 s30;
    u32 s2C;
    u32 s28;
    u32 s24;
    u32 s20;
    s32 mode;
    s32 flag;
    s32 i;
    s32 id;

    f32 w;


    mode = 0;
    flag = 0;
    i = 0;
    id = 0;

    p_bss = (struct fn_1_729F8_Bss *)&lbl_1_bss_6C8D8;

    { const union Color initial = {{0xFF,0xFF,0xFF,0xFF}}; color80 = initial; }
    v18C[0] = 0.0f;
    v168[0] = 0.0f;
    w = arg0->unk_EC;
    v174[1] = 0.0f;
    v168[1] = 0.0f;
    v180[0] = w;
    v174[0] = w;
    w = arg0->unk_EE;
    v18C[1] = w;
    v180[1] = w;

    switch (arg0->unk_DC) {
    case 0:
    case 37:
        break;
    case 3:
        mode = 4;
        goto common012; /* MF: three D-C entry points share this tail in retail. */
    case 2:
        mode = 2;
        goto common012; /* MF: same shared tail. */
    case 1:
        mode = 1;
    common012:
        color84.bytes.a = (255.0f - (arg0->unk_E0 * 255) / 40.0f);
        color7c = color84.word;
        fn_800371F8(1, &color7c);
        fn_1_761B8((struct fn_1_761B8_Arg0 *)arg0, mode);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 4:
        if (arg0->unk_E0 == 0)
            arg0->unk_E4 = 1.0f;
        v168[0] = v18C[0] = -(0.5f * arg0->unk_EC) * arg0->unk_E4;
        v174[0] = v180[0] = (0.5f * arg0->unk_EC) * arg0->unk_E4;
        v168[1] = v174[1] = -(0.5f * arg0->unk_EE) * arg0->unk_E4;
        v180[1] = v18C[1] = (0.5f * arg0->unk_EE) * arg0->unk_E4;
        lbl_8006D758();
        v168[0] = v168[0] + 0.5f * arg0->unk_EC;
        v174[0] = v174[0] + 0.5f * arg0->unk_EC;
        v180[0] = v180[0] + 0.5f * arg0->unk_EC;
        v18C[0] = v18C[0] + 0.5f * arg0->unk_EC;
        v168[1] = v168[1] + 0.5f * arg0->unk_EE;
        v174[1] = v174[1] + 0.5f * arg0->unk_EE;
        v180[1] = v180[1] + 0.5f * arg0->unk_EE;
        v18C[1] = v18C[1] + 0.5f * arg0->unk_EE;
        arg0->unk_E0++;
        arg0->unk_E4 -= 0.025f;
        if (arg0->unk_E4 < 0.025f)
            fn_1_76C60(arg0);
        s78 = color84.word;
        fn_800371F8(1, &s78);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 5:
        if (arg0->unk_E0 == 0)
            arg0->unk_E4 = 1.0f;
        v168[0] = v18C[0] = -(0.5f * arg0->unk_EC) * arg0->unk_E4;
        v174[0] = v180[0] = (0.5f * arg0->unk_EC) * arg0->unk_E4;
        v168[1] = v174[1] = -(0.5f * arg0->unk_EE) * arg0->unk_E4;
        v180[1] = v18C[1] = (0.5f * arg0->unk_EE) * arg0->unk_E4;
        lbl_8006D758();
        mathutil_mtxA_rotate_z((-(40.96f * (arg0->unk_E0 * arg0->unk_E0))));
        lbl_8006E1B0(v168, v168);
        lbl_8006E1B0(v174, v174);
        lbl_8006E1B0(v180, v180);
        lbl_8006E1B0(v18C, v18C);
        v168[0] = v168[0] + 0.5f * arg0->unk_EC;
        v174[0] = v174[0] + 0.5f * arg0->unk_EC;
        v180[0] = v180[0] + 0.5f * arg0->unk_EC;
        v18C[0] = v18C[0] + 0.5f * arg0->unk_EC;
        v168[1] = v168[1] + 0.5f * arg0->unk_EE;
        v174[1] = v174[1] + 0.5f * arg0->unk_EE;
        v180[1] = v180[1] + 0.5f * arg0->unk_EE;
        v18C[1] = v18C[1] + 0.5f * arg0->unk_EE;
        arg0->unk_E0++;
        arg0->unk_E4 -= 0.025f;
        if (arg0->unk_E4 < 0.025f)
            fn_1_76C60(arg0);
        s74 = color84.word;
        fn_800371F8(1, &s74);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 6:
        v168[0] = v18C[0] = arg0->unk_E0 * ((-arg0->unk_EC) / 40.0f);
        v174[0] = v180[0] = arg0->unk_EC + arg0->unk_E0 * ((-arg0->unk_EC) / 40.0f);
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        fn_1_761B8((struct fn_1_761B8_Arg0 *)arg0, 1);
        s70 = color84.word;
        fn_800371F8(1, &s70);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 7:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        lbl_8006D758();
        mathutil_mtxA_rotate_z((-(409.6f * arg0->unk_E0)));
        lbl_8006E1B0(v168, v168);
        lbl_8006E1B0(v174, v174);
        lbl_8006E1B0(v180, v180);
        lbl_8006E1B0(v18C, v18C);
        fn_1_761B8((struct fn_1_761B8_Arg0 *)arg0, 1);
        s6C = color84.word;
        fn_800371F8(1, &s6C);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 8:
        if (arg0->unk_E0 == 0)
            arg0->unk_E4 = 0.0f;
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        s68 = color84.word;
        fn_800371F8(1, &s68);
        fn_800734A8(0, 0, 0, 255);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        v168[0] = v18C[0] = -(0.5f * arg0->unk_EC) * arg0->unk_E4;
        v174[0] = v180[0] = (0.5f * arg0->unk_EC) * arg0->unk_E4;
        v168[1] = v174[1] = -(0.5f * arg0->unk_EE) * arg0->unk_E4;
        v180[1] = v18C[1] = (0.5f * arg0->unk_EE) * arg0->unk_E4;
        v168[0] = v168[0] + 0.5f * arg0->unk_EC;
        v174[0] = v174[0] + 0.5f * arg0->unk_EC;
        v180[0] = v180[0] + 0.5f * arg0->unk_EC;
        v18C[0] = v18C[0] + 0.5f * arg0->unk_EC;
        v168[1] = v168[1] + 0.5f * arg0->unk_EE;
        v174[1] = v174[1] + 0.5f * arg0->unk_EE;
        v180[1] = v180[1] + 0.5f * arg0->unk_EE;
        v18C[1] = v18C[1] + 0.5f * arg0->unk_EE;
        arg0->unk_E0++;
        arg0->unk_E4 += 0.025f;
        if (arg0->unk_E4 > 1.0f)
            arg0->unk_E4 = 1.0f;
        if (arg0->unk_E0 > 40.0f)
            fn_1_76C60(arg0);
        s64 = color84.word;
        fn_800371F8(1, &s64);
        fn_800734A8(0, 0, 1, 255);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 9:
        if (arg0->unk_E0 == 0)
            arg0->unk_E4 = 0.0f;
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        s60 = color84.word;
        fn_800371F8(1, &s60);
        fn_800734A8(0, 0, 0, 255);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        v168[0] = v18C[0] = -(0.5f * arg0->unk_EC) * arg0->unk_E4;
        v174[0] = v180[0] = (0.5f * arg0->unk_EC) * arg0->unk_E4;
        v168[1] = v174[1] = -(0.5f * arg0->unk_EE) * arg0->unk_E4;
        v180[1] = v18C[1] = (0.5f * arg0->unk_EE) * arg0->unk_E4;
        lbl_8006D758();
        mathutil_mtxA_rotate_z((-(40.96f * ((40.0f - arg0->unk_E0) * (40.0f - arg0->unk_E0)))));
        lbl_8006E1B0(v168, v168);
        lbl_8006E1B0(v174, v174);
        lbl_8006E1B0(v180, v180);
        lbl_8006E1B0(v18C, v18C);
        v168[0] = v168[0] + 0.5f * arg0->unk_EC;
        v174[0] = v174[0] + 0.5f * arg0->unk_EC;
        v180[0] = v180[0] + 0.5f * arg0->unk_EC;
        v18C[0] = v18C[0] + 0.5f * arg0->unk_EC;
        v168[1] = v168[1] + 0.5f * arg0->unk_EE;
        v174[1] = v174[1] + 0.5f * arg0->unk_EE;
        v180[1] = v180[1] + 0.5f * arg0->unk_EE;
        v18C[1] = v18C[1] + 0.5f * arg0->unk_EE;
        arg0->unk_E0++;
        arg0->unk_E4 += 0.025f;
        if (arg0->unk_E4 > 1.0f)
            arg0->unk_E4 = 1.0f;
        if (arg0->unk_E0 > 40.0f)
            fn_1_76C60(arg0);
        s5C = color84.word;
        fn_800371F8(1, &s5C);
        fn_800734A8(0, 0, 1, 255);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 10:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        s58 = color84.word;
        fn_800371F8(1, &s58);
        fn_800734A8(0, 0, 0, 255);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        v168[0] = v18C[0] = (40.0f - arg0->unk_E0) * ((-arg0->unk_EC) / 40.0f);
        v174[0] = v180[0] = arg0->unk_EC + (40.0f - arg0->unk_E0) * ((-arg0->unk_EC) / 40.0f);
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        fn_1_761B8((struct fn_1_761B8_Arg0 *)arg0, 1);
        s54 = color84.word;
        fn_800371F8(1, &s54);
        fn_800734A8(0, 0, 1, 255);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 11:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        s50 = color84.word;
        fn_800371F8(1, &s50);
        fn_800734A8(0, 0, 0, 255);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        lbl_8006D758();
        mathutil_mtxA_rotate_z((-(409.6f * (40.0f - arg0->unk_E0))));
        lbl_8006E1B0(v168, v168);
        lbl_8006E1B0(v174, v174);
        lbl_8006E1B0(v180, v180);
        lbl_8006E1B0(v18C, v18C);
        fn_1_761B8((struct fn_1_761B8_Arg0 *)arg0, 1);
        s4C = color84.word;
        fn_800371F8(1, &s4C);
        fn_800734A8(0, 0, 1, 255);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 12:
    case 13:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        color84.bytes.a = 0xff;
        flag = (arg0->unk_DC == 12);
        s48 = color84.word;
        fn_800371F8(2, &s48);
        color84.bytes.a = flag ? 0xfe : 0xff;
        s44 = color84.word;
        fn_800371F8(1, &s44);
        lbl_8006D758();
        lbl_801A6D00[3] = 2.0f / arg0->unk_EC;
        lbl_801A6D00[7] = 2.0f / arg0->unk_EE;
        GXLoadTexMtxImm(lbl_801A6D00, 30, 1);
        lbl_801A6D00[3] = 2.0f / arg0->unk_EC;
        lbl_801A6D00[7] = -2.0f / arg0->unk_EE;
        GXLoadTexMtxImm(lbl_801A6D00, 33, 1);
        lbl_801A6D00[3] = -2.0f / arg0->unk_EC;
        lbl_801A6D00[7] = -2.0f / arg0->unk_EE;
        GXLoadTexMtxImm(lbl_801A6D00, 36, 1);
        lbl_801A6D00[3] = -2.0f / arg0->unk_EC;
        lbl_801A6D00[7] = 2.0f / arg0->unk_EE;
        GXLoadTexMtxImm(lbl_801A6D00, 39, 1);
        fn_800724C8();
        fn_8007245C(0x2200);
        fn_80074788(0);
        fn_80074660(5);
        fn_80073678(6);
        fn_80073898(0);
        fn_800745A4(0, 1, 4, 30, 0, 125);
        fn_800745A4(1, 1, 4, 33, 0, 125);
        fn_800745A4(2, 1, 4, 36, 0, 125);
        fn_800745A4(3, 1, 4, 39, 0, 125);
        fn_800745A4(4, 1, 4, 60, 0, 125);
        fn_80073C6C(0);
        fn_80073C6C(1);
        fn_80073C6C(2);
        fn_80073C6C(3);
        fn_80073C6C(4);
        fn_80073C6C(5);
        fn_800734A8(0, 0, 2, 255);
        fn_800734A8(1, 1, 2, 255);
        fn_800734A8(2, 2, 2, 255);
        fn_800734A8(3, 3, 2, 255);
        fn_800734A8(4, 4, 0, 255);
        fn_800734A8(5, 4, 1, 255);
        fn_80072AB0(0, 0, 0);
        fn_80072AB0(1, 0, 0);
        fn_80072AB0(2, 0, 0);
        fn_80072AB0(3, 0, 0);
        fn_80072AB0(4, 0, 0);
        fn_80072AB0(5, 0, 0);
        fn_800735C8(0, 4);
        fn_80072C24(0, 15, 8, 14, 15);
        fn_80072D64(0, 0, 0, 0, 0, 0);
        fn_800735C8(1, 4);
        fn_80072C24(1, 15, 8, 14, 0);
        fn_80072D64(1, 0, 0, 0, 0, 0);
        fn_800735C8(2, 4);
        fn_80072C24(2, 15, 8, 14, 0);
        fn_80072D64(2, 0, 0, 0, 0, 0);
        fn_800735C8(3, 4);
        fn_80072C24(3, 15, 8, 14, 0);
        fn_80072D64(3, 0, 0, 3, 1, 0);
        fn_800735C8(4, 0);
        fn_80073620(4, 0);
        fn_80072C24(4, 15, 15, 15, 0);
        fn_80072D64(4, 0, 0, 0, 1, 0);
        if (flag)
            fn_80072CC4(4, 4, 1, 6, 7);
        else
            fn_80072CC4(4, 1, 4, 6, 7);
        fn_80072E20(4, 14, 0, 0, 1, 0);
        fn_800735C8(5, 0);
        fn_80073620(5, 0);
        fn_80072C24(5, 15, 15, 15, 0);
        fn_80072D64(5, 0, 0, 0, 1, 0);
        if (flag)
            fn_80072CC4(5, 7, 4, 0, 7);
        else
            fn_80072CC4(5, 6, 7, 4, 0);
        fn_80072E20(5, 0, 0, 0, 1, 0);
        fn_800747D0(4, 0, 0, 0, 0, 2, 2);
        fn_80074918(1, 7, 0);
        fn_800728A8(1, 4, 5, 0);
        fn_800720B0(0);
        fn_80072864(2);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 14:
    case 15:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        if (arg0->unk_DC == 12) {
            color84.bytes.a = 0xff;
            flag = 1;
        } else if (arg0->unk_DC == 13) {
            color84.bytes.a = 0xff;
            flag = 0;
        } else if (arg0->unk_DC == 14) {
            color84.bytes.a = 0x80;
            flag = 0;
        } else {
            color84.bytes.a = 0x80;
            flag = 0;
        }
        s40 = color84.word;
        fn_800371F8(2, &s40);
        color84.bytes.a = flag ? 0xfe : 0xff;
        s3C = color84.word;
        fn_800371F8(1, &s3C);
        fn_800724C8();
        fn_8007245C(0x2200);
        fn_80074788(0);
        fn_80074660(1);
        fn_80073678(3);
        fn_80073898(0);
        fn_80073C6C(0);
        fn_80073C6C(1);
        fn_80073C6C(2);
        fn_800745A4(0, 1, 4, 60, 0, 125);
        fn_800734A8(0, 0, 0, 255);
        fn_800734A8(1, 0, 1, 255);
        fn_800734A8(2, 0, 2, 255);
        fn_80072AB0(0, 0, 0);
        fn_80072AB0(1, 0, 0);
        fn_80072AB0(2, 0, 0);
        fn_800735C8(0, 0);
        fn_80073620(0, 0);
        fn_80072C24(0, 15, 15, 15, 14);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        if (flag)
            fn_80072CC4(0, 4, 1, 6, 7);
        else
            fn_80072CC4(0, 1, 4, 6, 7);
        fn_80072E20(0, 14, 0, 0, 1, 0);
        fn_800735C8(1, 0);
        fn_80073620(1, 0);
        fn_80072C24(1, 15, 15, 15, 14);
        fn_80072D64(1, 0, 0, 0, 1, 0);
        if (flag)
            fn_80072CC4(1, 7, 4, 0, 7);
        else
            fn_80072CC4(1, 6, 7, 4, 0);
        fn_80072E20(1, 0, 0, 0, 1, 0);
        fn_80072C24(2, 15, 15, 15, 8);
        fn_80072D64(2, 0, 0, 0, 1, 0);
        fn_80072CC4(2, 7, 2, 0, 7);
        fn_80072E20(2, 0, 0, 0, 1, 0);
        fn_800747D0(4, 0, 0, 0, 0, 2, 2);
        fn_80074918(1, 7, 0);
        fn_800728A8(1, 4, 5, 0);
        fn_800720B0(0);
        fn_80072864(2);
        if (arg0->unk_DC == 15) {
            lbl_8006D784(m138);
            aC0[0] = 0.5f * m138[0];
            aC0[1] = 0.5f * m138[1];
            aC0[2] = 0.0f;
            aC0[3] = 0.5f * m138[4];
            aC0[4] = 0.5f * m138[5];
            aC0[5] = 0.0f;
            fn_80073A58(1, aC0, 1);
            fn_80073898(1);
            fn_800738E0(0, 0, 3);
            fn_80073D60(2, 0, 1, 0, 1);
        }
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        fn_80073678(1);
        fn_80073898(0);
        fn_80072C24(0, 15, 2, 8, 4);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 1, 4, 2);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        break;

    case 36:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        color84.bytes.a = 0xff;
        s38 = color84.word;
        fn_800371F8(2, &s38);
        color84.bytes.a = 0xfe;
        s34 = color84.word;
        fn_800371F8(1, &s34);
        fn_800724C8();
        fn_8007245C(0x2200);
        fn_80074788(0);
        fn_80074660(1);
        fn_80073678(3);
        fn_80073898(0);
        fn_80073C6C(0);
        fn_80073C6C(1);
        fn_80073C6C(2);
        fn_800745A4(0, 1, 4, 60, 0, 125);
        fn_800734A8(0, 0, 0, 255);
        fn_800734A8(1, 0, 1, 255);
        fn_800734A8(2, 0, 2, 255);
        fn_80072AB0(0, 0, 0);
        fn_80072AB0(1, 0, 0);
        fn_80072AB0(2, 0, 0);
        fn_80073620(0, 0);
        fn_80072C24(0, 15, 15, 15, 15);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 4, 1, 6, 7);
        fn_80072E20(0, 14, 0, 0, 1, 0);
        fn_80072C24(1, 15, 15, 15, 15);
        fn_80072D64(1, 0, 0, 0, 1, 0);
        fn_80072CC4(1, 7, 4, 0, 7);
        fn_80072E20(1, 0, 0, 0, 1, 0);
        fn_800735C8(2, 0);
        fn_80072C24(2, 14, 15, 8, 15);
        fn_80072D64(2, 0, 0, 0, 1, 0);
        fn_80072CC4(2, 7, 4, 0, 7);
        fn_80072E20(2, 0, 0, 0, 1, 0);
        fn_800747D0(4, 0, 0, 0, 0, 2, 2);
        fn_80074918(1, 7, 0);
        fn_800728A8(1, 4, 5, 0);
        fn_800720B0(0);
        fn_80072864(2);
        if (arg0->unk_DC == 15) {
            lbl_8006D784(m108);
            aA8[0] = 0.5f * m108[0];
            aA8[1] = 0.5f * m108[1];
            aA8[2] = 0.0f;
            aA8[3] = 0.5f * m108[4];
            aA8[4] = 0.5f * m108[5];
            aA8[5] = 0.0f;
            fn_80073A58(1, aA8, 1);
            fn_80073898(1);
            fn_800738E0(0, 0, 3);
            fn_80073D60(2, 0, 1, 0, 1);
        }
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        fn_80073678(1);
        fn_80073898(0);
        fn_80072C24(0, 15, 2, 8, 4);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 1, 4, 2);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        break;

    case 16:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        lbl_8006D758();
        GXLoadTexMtxImm(lbl_801A6D00, 30, 1);
        lbl_801A6D00[3] = 2.0f / arg0->unk_EC;
        lbl_801A6D00[7] = 2.0f / arg0->unk_EE;
        GXLoadTexMtxImm(lbl_801A6D00, 33, 1);
        lbl_801A6D00[3] = 2.0f / arg0->unk_EC;
        lbl_801A6D00[7] = -2.0f / arg0->unk_EE;
        GXLoadTexMtxImm(lbl_801A6D00, 36, 1);
        lbl_801A6D00[3] = -2.0f / arg0->unk_EC;
        lbl_801A6D00[7] = -2.0f / arg0->unk_EE;
        GXLoadTexMtxImm(lbl_801A6D00, 39, 1);
        lbl_801A6D00[3] = -2.0f / arg0->unk_EC;
        lbl_801A6D00[7] = 2.0f / arg0->unk_EE;
        GXLoadTexMtxImm(lbl_801A6D00, 42, 1);
        fn_800724C8();
        fn_8007245C(0x2200);
        fn_80074660(2);
        fn_80074788(0);
        fn_80073678(2);
        fn_80073898(0);
        fn_800729B0(2, 0, 1, 2, 2);
        fn_80073C6C(0);
        fn_80072AB0(0, 0, 2);
        fn_80073C6C(1);
        fn_80072AB0(1, 0, 2);
        fn_800734A8(0, 0, 0, 255);
        fn_80072EDC(0, 3);
        fn_800734A8(1, 1, 0, 255);
        fn_80072C24(1, 15, 15, 15, 15);
        fn_80072D64(1, 0, 0, 0, 1, 0);
        fn_80072CC4(1, 4, 7, 7, 0);
        fn_80072E20(1, 1, 0, 0, 0, 0);
        GXSetAlphaCompare(4, 1, 0, 1, 255);
        fn_80074918(1, 7, 0);
        fn_800745A4(0, 1, 4, 30, 0, 125);
        i = 0;
        id = 0x21;
        for (; i < 4; i++) {
            fn_800745A4(1, 1, 4, id, 0, 125);
            id += 3;
            fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        }
        break;

    case 23:
        fn_1_76EB8();
        break;

    case 24: {
        if (lbl_1_data_1DAB0[0] < 255)
            lbl_1_data_1DAB0[0]++;
        if (lbl_1_data_1DAB0[1] < 255)
            lbl_1_data_1DAB0[1]++;
        if (lbl_1_data_1DAB0[2] < 255)
            lbl_1_data_1DAB0[2]++;
        if (lbl_1_data_1DAB0[3] < 255)
            lbl_1_data_1DAB0[3]++;
        if (lbl_1_data_1DAB0[0] == 255 && lbl_1_data_1DAB0[1] == 255 && lbl_1_data_1DAB0[2] == 255 && lbl_1_data_1DAB0[3] == 255) {
            fn_1_76C60(arg0);
        } else {
            lbl_1_data_1DAB4 = lbl_1_data_1DAB4 + 0.01f * (1.0f - lbl_1_data_1DAB4);
            lbl_1_data_1DAB8 = lbl_1_data_1DAB8 + 0.01f * (1.0f - lbl_1_data_1DAB4);
            fn_1_76EB8();
        }
        break;
    }

    case 25:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        fn_800724C8();
        fn_8007245C(0x2200);
        fn_80074660(1);
        fn_80074788(0);
        fn_80073678(1);
        fn_80073898(0);
        fn_80072EDC(0, 3);
        fn_800734A8(0, 0, 0, 255);
        fn_80074918(1, 7, 0);
        fn_800745A4(0, 1, 4, 30, 0, 125);
        lbl_8006D758();
        GXLoadTexMtxImm(lbl_801A6D00, 30, 1);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 26:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        fn_1_77200();
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 27:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        fn_1_77200();
        fn_1_4E220((u8 *)&p_bss->unk_8D0 - 0x58, 1, 1, 2, 33);
        fn_80074660(2);
        fn_80073678(2);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 28:
        fn_80074788(0);
        fn_80074660(1);
        fn_80073678(1);
        fn_80073898(0);
        fn_80073C6C(0);
        fn_800745A4(0, 1, 4, 60, 0, 125);
        fn_800734A8(0, 0, 0, 255);
        fn_80072AB0(0, 0, 0);
        fn_80072EDC(0, 3);
        fn_800729B0(2, 3, 1, 2, 3);
        fn_80072AB0(0, 0, 2);
        color84.bytes.r = 0xf0;
        color84.bytes.g = 0xff;
        s30 = color84.word;
        fn_800736C0(0, &s30);
        fn_800735C8(0, 12);
        fn_80072C24(0, 8, 14, 12, 15);
        fn_80072D64(0, 10, 0, 0, 1, 0);
        fn_800728A8(1, 3, 3, 0);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 29:
        fn_80073D60(0, 0, 1, 0, 1);
        fn_80073678(1);
        fn_800734A8(0, 0, 0, 4);
        fn_80073898(1);
        fn_800738E0(0, 1, 1);
        fn_80074660(2);
        fn_800745A4(0, 1, 4, 60, 0, 125);
        fn_800745A4(1, 1, 4, 36, 0, 125);
        fn_80074788(1);
        fn_800747D0(0, 0, 0, 0, 0, 0, 2);
        fn_800747D0(2, 0, 0, 1, 0, 0, 2);
        fn_80073778((void *)p_bss->unk_8D0, 1);
        a90[0] = 0.0f;
        a90[1] = 0.0f;
        a90[2] = 0.003f;
        a90[3] = 0.0f;
        a90[4] = 0.0f;
        a90[5] = 0.003f;
        fn_80073A58(1, a90, 1);
        fn_800739E0(0, 0, 0);
        lbl_8006D784(mD8);
        mD8[0] = 5.0f;
        mD8[5] = 15.0f;
        mD8[3] = 0.0f;
        mD8[7] = 0.01f * lbl_801A66A0;
        GXLoadTexMtxImm(mD8, 36, 1);
        fn_80072C24(0, 15, 15, 15, 8);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 7, 7, 5);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        fn_800728A8(1, 4, 5, 0);
        fn_80074918(1, 7, 0);
        fn_1_77C5C(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;

    case 30:
        fn_80074788(0);
        fn_80074660(1);
        fn_80073678(2);
        fn_80073898(0);
        fn_80073C6C(0);
        fn_80073C6C(1);
        fn_800745A4(0, 1, 4, 60, 0, 125);
        fn_800734A8(0, 0, 0, 255);
        fn_800734A8(1, 0, 1, 255);
        fn_80072AB0(0, 0, 0);
        fn_80072AB0(1, 0, 0);
        fn_800729B0(2, 3, 1, 2, 3);
        fn_80072AB0(0, 0, 2);
        color84.bytes.r = p_bss->unk_8D4;
        color84.bytes.g = (p_bss->unk_8D4 >> 8) & 0xff;
        color84.bytes.a = p_bss->unk_8D6;
        s2C = color84.word;
        fn_800371F8(1, &s2C);
        s28 = color84.word;
        fn_800736C0(0, &s28);
        fn_800735C8(0, 12);
        fn_80072C24(0, 8, 14, 3, 15);
        fn_80072D64(0, 10, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 7, 7, 7);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        color80.bytes.r = p_bss->unk_8D8;
        s24 = color80.word;
        fn_800736C0(1, &s24);
        fn_800735C8(1, 13);
        fn_80072C24(1, 8, 14, 0, 0);
        fn_80072D64(1, 8, 0, 0, 1, 0);
        fn_80072CC4(1, 7, 7, 7, 7);
        fn_80072E20(1, 0, 0, 0, 1, 0);
        fn_800728A8(1, 1, 5, 0);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 31:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        s20 = color84.word;
        fn_800371F8(1, &s20);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 32:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = arg0->unk_EE;
        fn_80074660(2);
        fn_800745A4(0, 1, 4, 60, 0, 125);
        fn_800745A4(1, 1, 4, 60, 0, 125);
        fn_80073678(4);
        fn_80073C6C(0);
        fn_80073C6C(1);
        fn_80073C6C(2);
        fn_80073C6C(3);
        fn_800734A8(0, 0, 1, 255);
        fn_80072C24(0, 15, 8, 14, 2);
        fn_80072D64(0, 0, 0, 0, 0, 0);
        fn_80072CC4(0, 7, 4, 6, 1);
        fn_80072E20(0, 1, 0, 0, 0, 0);
        fn_800735C8(0, 12);
        fn_80073620(0, 28);
        fn_80072AB0(0, 0, 1);
        fn_800734A8(1, 1, 0, 255);
        fn_80072C24(1, 15, 8, 14, 0);
        fn_80072D64(1, 0, 0, 1, 0, 0);
        fn_80072CC4(1, 7, 4, 6, 0);
        fn_80072E20(1, 0, 0, 1, 0, 0);
        fn_800735C8(1, 13);
        fn_80073620(1, 29);
        fn_80072AB0(1, 0, 0);
        fn_800734A8(2, 0, 1, 255);
        fn_80072C24(2, 15, 8, 14, 0);
        fn_80072D64(2, 0, 0, 0, 1, 0);
        fn_80072CC4(2, 7, 4, 6, 0);
        fn_80072E20(2, 1, 0, 0, 1, 0);
        fn_800735C8(2, 14);
        fn_80073620(2, 30);
        fn_80072AB0(2, 0, 2);
        fn_800734A8(3, 255, 255, 255);
        fn_80072C24(3, 0, 1, 14, 15);
        fn_80072D64(3, 0, 0, 0, 1, 0);
        fn_80072CC4(3, 7, 7, 7, 7);
        fn_80072E20(3, 0, 0, 0, 1, 0);
        fn_80072AB0(3, 0, 0);
        fn_800735C8(3, 15);
        { union Color color88[2] = {{{0xFF,0x91,0x00,0x00}},{{0xFF,0x76,0x00,0x44}}};
        fn_8003726C(1, w88); }
        { union Color s1C = {{0x66,0x00,0xFF,0x32}};
        fn_800736C0(0, &s1C); }
        { union Color s18 = {{0x94,0x00,0x94,0x94}};
        fn_800736C0(1, &s18); }
        { union Color s14 = {{0xCB,0x00,0x05,0xCF}};
        fn_800736C0(2, &s14); }
        { union Color s10 = {{0x00,0xFF,0x00,0x00}};
        fn_800736C0(3, &s10); }
        fn_800729B0(0, 0, 1, 2, 3);
        fn_800729B0(1, 0, 3, 3, 3);
        fn_800729B0(2, 0, 0, 3, 0);
        fn_80074788(0);
        fn_80073898(0);
        fn_800728A8(1, 1, 0, 0);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        fn_80072808();
        break;

    case 33:
        color84.bytes.a = (255 - p_bss->unk_8DA);
        { union Color s0C = color84;
        fn_800371F8(1, &s0C); }
        fn_80072C24(0, 8, 15, 15, 15);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 7, 7, 1);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;

    case 34:
        fn_80074788(0);
        fn_80074660(1);
        fn_80073678(3);
        fn_80073898(0);
        fn_80073C6C(0);
        fn_80073C6C(1);
        fn_80073C6C(2);
        fn_800745A4(0, 1, 4, 60, 0, 125);
        fn_800734A8(0, 0, 0, 255);
        fn_800734A8(1, 0, 1, 255);
        fn_800734A8(2, 0, 2, 255);
        fn_80072AB0(0, 0, 0);
        fn_80072AB0(1, 0, 0);
        fn_80072AB0(2, 0, 0);
        fn_80072EDC(0, 3);
        fn_80072C24(1, 15, 8, 12, 0);
        fn_80072D64(1, 1, 0, 0, 1, 0);
        fn_80072CC4(1, 7, 7, 7, 7);
        fn_80072E20(1, 0, 0, 0, 1, 0);
        { union Color s08 = color84;
        fn_800736C0(0, &s08); }
        fn_800735C8(2, 12);
        fn_80072C24(2, 0, 14, 8, 15);
        fn_80072D64(2, 0, 0, 0, 1, 0);
        fn_80072CC4(2, 7, 7, 7, 7);
        fn_80072E20(2, 0, 0, 0, 1, 0);
        fn_80073678(3);
        fn_800728A8(1, 1, 0, 0);
        fn_1_75D84(v168, (const struct fn_1_75D84_Rect *)&arg0->unk_E8, (struct fn_1_75D84_Size *)&arg0->unk_F8);
        break;
    }
}

u8 lbl_1_data_1DB9C[] = "Error!: draw_quad   (s,t) is wrong\n";
/* fzgx:end fn_1_729F8 */

/* fzgx:begin fn_1_75D84 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"


typedef struct fn_1_75D84_Rect {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
    s16 unk_A;
} fn_1_75D84_Rect;

typedef struct fn_1_75D84_Size {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
} fn_1_75D84_Size;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} WGPipe;

volatile WGPipe GXWGFifo : 0xCC008000; /* fzgx-allow: A1 write-gather FIFO port */

extern u16 fn_1_A5DB0(void);
extern void fn_8003462C(u32, u32, u32);
extern void OSPanic(const char *, int, const char *, ...);
extern u8 lbl_1_data_1DAC0[0x10];
extern u8 lbl_1_data_1DB9C[0x24];

static inline void GXPosition3f32(const f32 x, const f32 y, const f32 z) {
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
}

static inline void GXTexCoord2f32(const f32 s, const f32 t) {
    GXWGFifo.f32 = s;
    GXWGFifo.f32 = t;
}

static inline BOOL fn_1_75D84_in_unit(f32 v) {
    if (v > 1.0f) {
        return FALSE;
    }
    if (v < 0.0f) {
        return FALSE;
    }
    return TRUE;
}

void fn_1_75D84(const f32 *pos, const fn_1_75D84_Rect *rect, fn_1_75D84_Size *size) {
    f32 s[4];
    f32 t[4];
    s32 h;
    s32 y;
    s32 i;

    s[0] = s[3] = (rect->unk_0 - size->unk_0) / (f32)size->unk_4;
    s[1] = s[2] = (rect->unk_0 + rect->unk_4 - size->unk_0) / (f32)size->unk_4;
    t[0] = t[1] = ((s32)((rect->unk_2 * fn_1_A5DB0()) / 480.0f) - size->unk_2) / (f32)size->unk_6;
    h = ((rect->unk_6 * fn_1_A5DB0()) / 480.0f);
    y = ((rect->unk_2 * fn_1_A5DB0()) / 480.0f);
    t[2] = t[3] = (y + h - size->unk_2) / (f32)size->unk_6;

    for (i = 0; i < 4; i++) {
        if (!fn_1_75D84_in_unit(s[i]) || !fn_1_75D84_in_unit(t[i])) {
            OSPanic((const char *)lbl_1_data_1DAC0, 1939, (const char *)lbl_1_data_1DB9C);
        }
    }

    fn_8003462C(0x80, 0, 4);
    GXPosition3f32(pos[0] + rect->unk_8, pos[1] + rect->unk_A, 0.0f);
    GXTexCoord2f32(s[0], t[0]);
    GXPosition3f32(pos[3] + rect->unk_8, pos[4] + rect->unk_A, 0.0f);
    GXTexCoord2f32(s[1], t[1]);
    GXPosition3f32(pos[6] + rect->unk_8, pos[7] + rect->unk_A, 0.0f);
    GXTexCoord2f32(s[2], t[2]);
    GXPosition3f32(pos[9] + rect->unk_8, pos[10] + rect->unk_A, 0.0f);
    GXTexCoord2f32(s[3], t[3]);
}
/* fzgx:end fn_1_75D84 */

/* fzgx:begin fn_1_761B8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

struct fn_1_761B8_Arg0 {
    u8 pad_0[0xE0];
    u32 unk_E0;
};

extern const f32 lbl_1_rodata_31A8;
extern const f64 lbl_1_rodata_31D8[2];
extern void fn_1_76C60();

void fn_1_761B8(struct fn_1_761B8_Arg0 *arg0, u32 arg1) {
    u32 v0;
    f32 v1;
    v0 = (arg0->unk_E0 + arg1);
    arg0->unk_E0 = v0;
    v1 = (s32)arg0->unk_E0;
    if (v1 > lbl_1_rodata_31A8) {
        fn_1_76C60();
    }
}
/* fzgx:end fn_1_761B8 */

/* fzgx:begin fn_1_76218 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

struct Sig_fn_8004E278_fn_8004E278_Arg0 {
    u32 unk_0;
};

struct Sig_fn_1_76448_fn_1_76448_Arg0 {
    u8 pad_0[0xA0];
    u32 unk_A0[1];
    u8 pad_A4[0x38];
    u32 unk_DC;
    u8 pad_E0[0x18];
    s16 unk_F8;
};

typedef struct {
    u8 pad_0[0xa0];
    u32 unk_a0[5];
    u32 unk_b4[5];
    s32 unk_c8[5];
    u32 unk_dc;
    u32 unk_e0;
    f32 unk_e4;
    u16 unk_e8;
    u16 unk_ea;
    u16 unk_ec;
    u16 unk_ee;
    u16 unk_f0;
    u16 unk_f2;
    u32 unk_f4;
    u16 unk_f8;
    u16 unk_fa;
    u16 unk_fc;
    u16 unk_fe;
    u16 unk_100;
    u16 unk_102;
    u32 unk_104;
    u8 unk_108;
} Sig_fn_1_76C60_FnScreenEffect;

extern void DCInvalidateRange(struct Sig_fn_8004E278_fn_8004E278_Arg0 *, u32);
struct fn_1_76448_Arg0;
extern void fn_1_76448(struct fn_1_76448_Arg0 *, u32);
extern void fn_1_76C60();
extern u32 fn_1_7880C(void);
extern u32 fn_1_788B0(void);
extern void GXInvalidateTexAll(void);


void fn_1_76218(s32 arg0) {
    s32 temp_r4;
    s32 var_r5;
    u8 var_r29;
    u8 var_r29_2;
    struct Sig_fn_1_76448_fn_1_76448_Arg0 *temp_r28;
    struct Sig_fn_1_76448_fn_1_76448_Arg0 *temp_r28_2;

    var_r5 = 0;
    if (arg0 != 0) {
        var_r29 = 0;
        while (var_r29 < 8U) {
            temp_r28 = (struct Sig_fn_1_76448_fn_1_76448_Arg0 *)((u8 *)&lbl_1_bss_6C8EC + (var_r29 * 0x10C));
            if ((s32) temp_r28->unk_DC == 0x25) {
                DCInvalidateRange((struct Sig_fn_8004E278_fn_8004E278_Arg0 *)(*(struct Sig_fn_8004E278_fn_8004E278_Arg0 **)((u8 *)(temp_r28) + 160)), (*(u32 *)((u8 *)(temp_r28) + 180)));
                fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28), (0U));
                fn_1_76C60((Sig_fn_1_76C60_FnScreenEffect *)((Sig_fn_1_76C60_FnScreenEffect *) temp_r28));
                var_r5 = 1;
            }
            var_r29 += 1;
                    }
    }
    var_r29_2 = 0;
    while (var_r29_2 < 8U) {
        temp_r28_2 = (struct Sig_fn_1_76448_fn_1_76448_Arg0 *)((u8 *)&lbl_1_bss_6C8EC + (var_r29_2 * 0x10C));
        temp_r4 = temp_r28_2->unk_DC;
        if ((temp_r4 != 0) && ((*((u8 *)(temp_r28_2) + 264)) == 0)) {
            if (arg0 != 0) {
                switch (temp_r4) {
                case 0xE:
                    fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28_2), (2U));
                    break;
                case 0x17:
                case 0x18:
                    fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28_2), (0U));
                    fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28_2), (1U));
                    break;
                }
            } else {
                switch (temp_r4) {
                case 16:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 33:
                case 35:
                    fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28_2), (0U));
                    break;
                case 14:
                case 30:
                    fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28_2), (0U));
                    fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28_2), (1U));
                    break;
                case 12:
                case 13:
                case 15:
                case 36:
                    fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28_2), (0U));
                    fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28_2), (1U));
                    fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28_2), (2U));
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                    if ((*(s32 *)((u8 *)(temp_r28_2) + 224)) == 0) {
                        fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28_2), (0U));
                    }
                    break;
                case 8:
                case 9:
                case 10:
                case 11:
                    if ((*(s32 *)((u8 *)(temp_r28_2) + 224)) == 0) {
                        fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28_2), (0U));
                    }
                    fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28_2), (1U));
                    break;
                case 34:
                    fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28_2), (2U));
                    fn_1_7880C();
                    fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28_2), (0U));
                    fn_1_788B0();
                    fn_1_76448((struct fn_1_76448_Arg0 *)(temp_r28_2), (1U));
                    break;
                }
            }
            var_r5 = 1;
        }
        var_r29_2 += 1;
            }
    if (var_r5 != 0) {
        GXInvalidateTexAll();
    }
}

char lbl_1_data_1DC54[] = "Error!: ScrefcSetMode   Manager is Full\n";
/* fzgx:end fn_1_76218 */

/* fzgx:begin fn_1_76448 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"
extern u32 fn_8003526C(u32, u32);
extern u32 fn_80074300(u32, u32, u32, u32);
extern u32 fn_80074438(u32, u32, u32, u32);

#include "types.h"

struct fn_1_76448_Arg0 {
    u8 pad_0[0xA0];
    u32 unk_A0[1];
    u8 pad_A4[0x38];
    u32 unk_DC;
    u8 pad_E0[0x18];
    s16 unk_F8;
};

void fn_1_76448(struct fn_1_76448_Arg0 *arg0, u32 arg1) {
    u32 v0;
    s32 v1;
    u8 v2;
    u32 v3;
    v0 = (arg1 & 0xFF);
    v1 = (arg0->unk_DC * 6);
    v2 = *(((u8 *)&lbl_1_data_1D9B8 + v1) + v0);
    v3 = (u32)((u8 *)&lbl_1_data_1D960 + (v2 << 3));
    fn_80074300((arg0->unk_F8 & 0xFFFF), (*(s16 *)((u32)arg0 + 250) & 0xFFFF), (*(s16 *)((u32)arg0 + 252) & 0xFFFF), (*(s16 *)((u8 *)arg0 + 254) & 0xFFFF));
    fn_80074438((*(s16 *)((u8 *)arg0 + 256) & 0xFFFF), (*(s16 *)((u8 *)arg0 + 258) & 0xFFFF), *(u32 *)(v3 + 4), (*(u32 *)((u8 *)arg0 + 244) & 0xFF));
    fn_8003526C(arg0->unk_A0[v0], 0);
}
/* fzgx:end fn_1_76448 */

/* fzgx:begin fn_1_76504 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

typedef struct fn_1_76504_Effect {
    u8 pad_0[0xA0];
    u32 unk_A0[15];
    s32 unk_DC;
    u8 pad_E0[0x2C];
} fn_1_76504_Effect;

typedef struct fn_1_76504_Kind {
    u8 pad_0[0x5];
    u8 count;
} fn_1_76504_Kind;

extern void OSPanic(const char *, int, const char *, ...);
struct fn_1_76650_ScreenEffect;
struct Fn1_76964Obj;
struct fn_1_76A94_Obj;
extern void fn_1_76650(struct fn_1_76650_ScreenEffect *);
extern void fn_1_76DC0(s32);
extern f32 fn_1_76704(void *, void *);
extern void fn_1_76964(struct Fn1_76964Obj *);
extern void fn_1_769FC(u32 *, u8);
extern void fn_1_76A94(struct fn_1_76A94_Obj *, u8);
extern void fn_1_76DBC(void);

u8 fn_1_76504(s32 kind, s32 arg1, s32 flag) {
    u8 *data = (u8 *)&lbl_1_data_1D960;
    fn_1_76504_Effect *effect;
    u8 i;
    u8 j;

    if (lbl_1_bss_6D14C.unk_0 != 0) {
        return 0xFF;
    }
    if (kind == 0 || kind >= 0x26) {
        return 0xFF;
    }
    for (i = 0; i < 8; i++) {
        effect = (fn_1_76504_Effect *)((u8 *)&lbl_1_bss_6C8EC + i * 0x10C);
        if (effect->unk_DC == 0) {
            goto found;  /* fzgx-allow: S1 retail falls from the exhausted loop straight into OSPanic */
        }
    }
    OSPanic((const char *)data + 0x160, 0x879, (const char *)data + 0x2F4);
found:
    fn_1_76650((struct fn_1_76650_ScreenEffect *)effect);
    effect->unk_DC = kind;
    fn_1_76DC0(effect->unk_DC);
    fn_1_76704(effect, (void *)arg1);
    fn_1_76964((struct Fn1_76964Obj *)effect);
    kind = (s32)(data + 0x58);
    for (j = 0; j < ((u8 *)kind)[effect->unk_DC * 6 + 5]; j++) {
        if (flag != 0) {
            fn_1_769FC((u32 *)effect, j);
            fn_1_76A94((struct fn_1_76A94_Obj *)effect, j);
        } else {
            effect->unk_A0[j] = 0;
        }
    }
    fn_1_76DBC();
    return i;
}
/* fzgx:end fn_1_76504 */

/* fzgx:begin fn_1_76650 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"
extern u16 fn_1_A5D9C(void);
extern const f32 lbl_1_rodata_31AC;

typedef struct fn_1_76650_ScreenEffect {
    u8 pad_00[0xa0];
    s32 field_a0;
    s32 field_a4;
    s32 field_a8;
    s32 field_ac;
    s32 field_b0;
    u8 pad_b4[0x14];
    s32 field_c8;
    s32 field_cc;
    s32 field_d0;
    s32 field_d4;
    s32 field_d8;
    s32 field_dc;
    s32 field_e0;
    f32 field_e4;
    s16 field_e8;
    s16 field_ea;
    s16 field_ec;
    s16 field_ee;
    s16 field_f0;
    s16 field_f2;
    s32 field_f4;
    s16 field_f8;
    s16 field_fa;
    s16 field_fc;
    s16 field_fe;
    s16 field_100;
    s16 field_102;
    s32 field_104;
    u8 field_108;
} fn_1_76650_ScreenEffect;

void fn_1_76650(fn_1_76650_ScreenEffect *effect) {
    s32 value;

    effect->field_f2 = 0;
    effect->field_f0 = 0;
    effect->field_ea = 0;
    effect->field_e8 = 0;
    effect->field_ec = 0x280;
    effect->field_ee = 0x1e0;
    effect->field_f4 = 0;
    effect->field_fa = 0;
    effect->field_f8 = 0;
    effect->field_100 = 0x280;
    effect->field_fc = 0x280;
    value = fn_1_A5D9C();
    effect->field_102 = value;
    effect->field_fe = value;
    effect->field_dc = 0;
    effect->field_e0 = 0;
    effect->field_e4 = lbl_1_rodata_31AC;
    effect->field_104 = 0;
    effect->field_108 = 0;
    effect->field_a0 = 0;
    effect->field_c8 = 0;
    effect->field_a4 = 0;
    effect->field_cc = 0;
    effect->field_a8 = 0;
    effect->field_d0 = 0;
    effect->field_ac = 0;
    effect->field_d4 = 0;
    effect->field_b0 = 0;
    effect->field_d8 = 0;
}
/* fzgx:end fn_1_76650 */

/* fzgx:begin fn_1_76704 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

struct fn_1_76704_Copy16 { u32 a[4]; };

extern const f32 lbl_1_rodata_31E8;
extern const f64 lbl_1_rodata_31D8[2];
extern u16 fn_1_A5DB0(void);
extern u8 lbl_1_data_1DAC0[0x10];
u8 lbl_1_data_1DC80[] = "Error!: ScrefcSetModeLocsize   Copy size is zero.\n";
extern void OSPanic(const char *, int, const char *, ...);

f32 fn_1_76704(void * arg0, void * arg1) {
    u8 *p = arg0;
    s32 a;
    s32 b;
    f32 v8;
    s16 v9;
    s16 v11;
    u32 t1;
    if (arg1 != 0) {
        if (*(s16 *)((u8 *)arg1 + 4) <= 1 || *(s16 *)((u8 *)arg1 + 6) <= 1) {
            OSPanic((const char *)lbl_1_data_1DAC0, 2262, (const char *)lbl_1_data_1DC80);
        }
        *(struct fn_1_76704_Copy16 *)(p + 232) = *(struct fn_1_76704_Copy16 *)arg1;
    } else {
        *(u16 *)(p + 232) = 0;
        *(u16 *)(p + 234) = 0;
        *(u16 *)(p + 236) = 640;
        *(u16 *)(p + 238) = 480;
        *(u16 *)(p + 240) = 0;
        *(u16 *)(p + 242) = 0;
        *(u32 *)(p + 244) = 0;
    }
    *(u16 *)(p + 248) = *(s16 *)(p + 232);
    t1 = (fn_1_A5DB0());
    *(u16 *)(p + 250) = (s32)((f32)(*(s16 *)(p + 234) * (s32)(t1 & 0xFFFF)) / lbl_1_rodata_31E8);
    a = *(s16 *)(p + 248);
    t1 = a - (((a & 1) ^ ((u32)a >> 31)) - ((u32)a >> 31));
    a = t1;
    *(u16 *)(p + 248) = a;
    b = *(s16 *)(p + 250);
    b = b - (((b & 1) ^ ((u32)b >> 31)) - ((u32)b >> 31));
    *(u16 *)(p + 250) = b;
    *(u16 *)(p + 252) = (*(s16 *)(p + 236) + *(s16 *)(p + 232)) - *(s16 *)(p + 248);
    v8 = (((*(s16 *)(p + 238) + *(s16 *)(p + 234)) - *(s16 *)(p + 250)) * (((fn_1_A5DB0())) & 0xFFFF));
    *(u16 *)(p + 254) = (s32)(v8 / lbl_1_rodata_31E8);
    v9 = *(s16 *)(p + 252);
    if ((v9 % 8) > 0) {
        v9 = (v9 / 8 + 1) * 8;
        *(u16 *)(p + 252) = v9;
    }
    v11 = *(s16 *)(p + 254);
    if ((v11 % 8) > 0) {
        v11 = (v11 / 8 + 1) * 8;
        *(u16 *)(p + 254) = v11;
    }
    if (*(s32 *)(p + 244) != 0) {
        *(u16 *)(p + 256) = *(s16 *)(p + 252) / 2;
        *(u16 *)(p + 258) = *(s16 *)(p + 254) / 2;
    } else {
        *(u16 *)(p + 256) = *(s16 *)(p + 252);
        *(u16 *)(p + 258) = *(s16 *)(p + 254);
    }
    return v8;
}
/* fzgx:end fn_1_76704 */

/* fzgx:begin fn_1_76964 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

typedef struct Fn1_76964Obj {
    u8 pad_0[0xB4];
    u32 unk_B4[6];
    u8 pad_CC[0x10];
    u32 unk_DC;
    u8 pad_E0[0x20];
    s16 unk_100;
    s16 unk_102;
} Fn1_76964Obj;

typedef struct {
    u8 unk_0[5];
    u8 unk_5;
} Fn1_76964Record;

typedef u8 Sig_GXGetTexBufferSize_GXBool;
extern u32 GXGetTexBufferSize(u16, u16, u32, Sig_GXGetTexBufferSize_GXBool, u8);

void fn_1_76964(Fn1_76964Obj *obj) {
    int i;

    for (i = 0; i < ((Fn1_76964Record *)&lbl_1_data_1D9B8)[obj->unk_DC].unk_5; i++) {
        obj->unk_B4[i] = GXGetTexBufferSize(
            obj->unk_100,
            obj->unk_102,
            *(u32 *)((u8 *)&lbl_1_data_1D960 +
                     ((*(u8 *)((u8 *)&lbl_1_data_1D9B8 + obj->unk_DC * 6 + i)) << 3)),
            0,
            0);
    }
}
/* fzgx:end fn_1_76964 */

/* fzgx:begin fn_1_769FC noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"
extern u32 lbl_801A6410;
extern u32 fn_80008E84(u32);

extern u32 lbl_801A6410;
extern s32 fn_1_45D0(u32, u32, void *, u32);
extern u32 fn_80008E84(u32);

void fn_1_769FC(u32 *arg0, u8 index)
{
    lbl_1_bss_6C8E8 = fn_80008E84(lbl_1_bss_6C8E4);

    arg0[index + 0x28] =
        fn_1_45D0(lbl_801A6410, arg0[index + 0x2D], lbl_1_data_1DAC0, 0x919);

    arg0[index + 0x32] = 0;

    fn_80008E84(lbl_1_bss_6C8E8);
}
/* fzgx:end fn_1_769FC */

/* fzgx:begin fn_1_76A94 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

typedef enum Sig_GXInitTexObj__GXTexFmt {
    Sig_GXInitTexObj_GX_TF_I4 = 0x0,
    Sig_GXInitTexObj_GX_TF_I8 = 0x1,
    Sig_GXInitTexObj_GX_TF_IA4 = 0x2,
    Sig_GXInitTexObj_GX_TF_IA8 = 0x3,
    Sig_GXInitTexObj_GX_TF_RGB565 = 0x4,
    Sig_GXInitTexObj_GX_TF_RGB5A3 = 0x5,
    Sig_GXInitTexObj_GX_TF_RGBA8 = 0x6,
    Sig_GXInitTexObj_GX_TF_CMPR = 0xE,
    Sig_GXInitTexObj_GX_CTF_R4 = 0x0 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA4 = 0x2 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA8 = 0x3 | 0x20,
    Sig_GXInitTexObj_GX_CTF_YUVA8 = 0x6 | 0x20,
    Sig_GXInitTexObj_GX_CTF_A8 = 0x7 | 0x20,
    Sig_GXInitTexObj_GX_CTF_R8 = 0x8 | 0x20,
    Sig_GXInitTexObj_GX_CTF_G8 = 0x9 | 0x20,
    Sig_GXInitTexObj_GX_CTF_B8 = 0xA | 0x20,
    Sig_GXInitTexObj_GX_CTF_RG8 = 0xB | 0x20,
    Sig_GXInitTexObj_GX_CTF_GB8 = 0xC | 0x20,
    Sig_GXInitTexObj_GX_TF_Z8 = 0x1 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z16 = 0x3 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z24X8 = 0x6 | 0x10,
    Sig_GXInitTexObj_GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_TF_A8 = Sig_GXInitTexObj_GX_CTF_A8,
} Sig_GXInitTexObj__GXTexFmt;
typedef struct Sig_GXInitTexObj__GXTexObj {
    u32 dummy[8];
} Sig_GXInitTexObj_GXTexObj;
typedef enum Sig_GXInitTexObj__GXTexWrapMode {
    Sig_GXInitTexObj_GX_CLAMP,
    Sig_GXInitTexObj_GX_REPEAT,
    Sig_GXInitTexObj_GX_MIRROR,
    Sig_GXInitTexObj_GX_MAX_TEXWRAPMODE,
} Sig_GXInitTexObj__GXTexWrapMode;
typedef enum Sig_GXInitTexObjLOD__GXAnisotropy {
    Sig_GXInitTexObjLOD_GX_ANISO_1,
    Sig_GXInitTexObjLOD_GX_ANISO_2,
    Sig_GXInitTexObjLOD_GX_ANISO_4,
    Sig_GXInitTexObjLOD_GX_MAX_ANISOTROPY,
} Sig_GXInitTexObjLOD_GXAnisotropy;
typedef u8 Sig_GXInitTexObjLOD_GXBool;
typedef enum Sig_GXInitTexObjLOD__GXTexFilter {
    Sig_GXInitTexObjLOD_GX_NEAR,
    Sig_GXInitTexObjLOD_GX_LINEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_NEAR,
    Sig_GXInitTexObjLOD_GX_NEAR_MIP_LIN,
    Sig_GXInitTexObjLOD_GX_LIN_MIP_LIN,
} Sig_GXInitTexObjLOD_GXTexFilter;
typedef struct Sig_GXInitTexObjLOD__GXTexObj {
    u32 texture_filter;
    u32 texture_lod;
    u32 texture_size;
    u32 texture_address;
    u32 user_data;
    u32 texture_format;
    u32 tlut_name;
    u16 texture_time_count;
    u8 texture_tile_type;
    u8 texture_flags;
} Sig_GXInitTexObjLOD_GXTexObj;
extern void GXInitTexObj(Sig_GXInitTexObj_GXTexObj *, void *, u16, u16, Sig_GXInitTexObj__GXTexFmt, Sig_GXInitTexObj__GXTexWrapMode, Sig_GXInitTexObj__GXTexWrapMode, u8);
extern void GXInitTexObjLOD(Sig_GXInitTexObjLOD_GXTexObj *, Sig_GXInitTexObjLOD_GXTexFilter, Sig_GXInitTexObjLOD_GXTexFilter, f32, f32, f32, Sig_GXInitTexObjLOD_GXBool, Sig_GXInitTexObjLOD_GXBool, Sig_GXInitTexObjLOD_GXAnisotropy);

extern const f32 lbl_1_rodata_31A0;

struct fn_1_76A94_Obj {
    u8 pad_0[0xA0];
    u32 unk_A0[15];
    u32 unk_DC;
    u8 pad_E0[0x20];
    s16 unk_100;
    s16 unk_102;
};

#pragma opt_dead_assignments off
void fn_1_76A94(struct fn_1_76A94_Obj *obj, u8 arg1) {
    u32 * fzgx_live;
    u32 i;
    u32 fmt;
    u32 w;
    u32 h;
    u32 fidx;
    u32 *tbl;
    u8 *row;

    i = arg1 & 0xFF;
    row = (u8 *)&lbl_1_data_1D9B8 + (obj->unk_DC * 6);
    tbl = (u32 *)&lbl_1_data_1D960;
    fmt = row[i];
    fidx = fmt << 3;
    if (fmt == 3) {
        w = 64;
        h = 64;
    } else if (fmt == 8) {
        w = obj->unk_100 / 2;
        h = obj->unk_102 / 2;
    } else {
        w = obj->unk_100;
        h = obj->unk_102;
    }
    if (fmt != 3) {
        fzgx_live = obj->unk_A0;
        GXInitTexObj((Sig_GXInitTexObj_GXTexObj *)((u8 *)obj + i * 32), (void *)fzgx_live[i], w, h, *(u32 *)((u8 *)tbl + fidx), Sig_GXInitTexObj_GX_CLAMP, Sig_GXInitTexObj_GX_CLAMP, 0);
    } else {
        fzgx_live = obj->unk_A0;
        GXInitTexObj((Sig_GXInitTexObj_GXTexObj *)((u8 *)obj + i * 32), (void *)fzgx_live[i], w, h, *(u32 *)((u8 *)tbl + fidx), Sig_GXInitTexObj_GX_REPEAT, Sig_GXInitTexObj_GX_REPEAT, 0);
    }
    GXInitTexObjLOD((Sig_GXInitTexObjLOD_GXTexObj *)((u8 *)obj + i * 32), Sig_GXInitTexObjLOD_GX_LINEAR, Sig_GXInitTexObjLOD_GX_LINEAR, lbl_1_rodata_31A0, lbl_1_rodata_31A0, lbl_1_rodata_31A0, 0, 0, Sig_GXInitTexObjLOD_GX_ANISO_1);
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_76A94 */

/* fzgx:begin fn_1_76BD0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

void fn_1_76BD0(u8 index, u8 value) {
    Obj_1_bss_6C8EC *obj =
        (Obj_1_bss_6C8EC *)((u8 *)&lbl_1_bss_6C8EC + index * 0x10c);

    if ((s32)obj->unk_DC != 0) {
        obj->unk_108 = value;
    }
}
/* fzgx:end fn_1_76BD0 */

/* fzgx:begin fn_1_76BF8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

extern void fn_1_76C60();

typedef struct {
    u8 pad_0[0xDC];
    s32 unk_DC;
    u8 pad_E0[0x2C];
} fn_1_76BF8_ScreenEffectEntry;

void fn_1_76BF8(void) {
    u8 i;
    fn_1_76BF8_ScreenEffectEntry *entry;

    entry = (fn_1_76BF8_ScreenEffectEntry *)&lbl_1_bss_6C8EC;
    for (i = 0; i < 8; i++) {
        entry = (fn_1_76BF8_ScreenEffectEntry *)((u8 *)&lbl_1_bss_6C8EC + i * 0x10C);
        if (entry->unk_DC != 0) {
            fn_1_76C60();
        }
    }
}
/* fzgx:end fn_1_76BF8 */

/* fzgx:begin fn_1_76C60 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_76DBC(void);
extern u16 fn_1_A5D9C(void);
extern const f32 lbl_1_rodata_31AC;
extern u32 fn_80008E84(u32);

typedef struct {
    u8 pad_0[0xa0];
    u32 unk_a0[5];
    u32 unk_b4[5];
    s32 unk_c8[5];
    u32 unk_dc;
    u32 unk_e0;
    f32 unk_e4;
    u16 unk_e8;
    u16 unk_ea;
    u16 unk_ec;
    u16 unk_ee;
    u16 unk_f0;
    u16 unk_f2;
    u32 unk_f4;
    u16 unk_f8;
    u16 unk_fa;
    u16 unk_fc;
    u16 unk_fe;
    u16 unk_100;
    u16 unk_102;
    u32 unk_104;
    u8 unk_108;
} FnScreenEffect;

// Clears the active screen-effect state and resets its rendering parameters.
void fn_1_76C60(FnScreenEffect *arg) {
    u8 i;
    u16 value;

    lbl_1_bss_6C8E8 = fn_80008E84(lbl_1_bss_6C8E4);
    i = 0;
    while (i < ((u8 *)&lbl_1_data_1D9B8)[arg->unk_dc * 6 + 5]) {
        if (arg->unk_c8[i] == 0) {
            fn_1_46B4(lbl_801A6410, arg->unk_a0[i], lbl_1_data_1DAC0, 0x9a1);
            arg->unk_a0[i] = 0;
        }
        i++;
    }
    fn_80008E84(lbl_1_bss_6C8E8);
    arg->unk_f2 = 0;
    arg->unk_f0 = 0;
    arg->unk_ea = 0;
    arg->unk_e8 = 0;
    arg->unk_ec = 0x280;
    arg->unk_ee = 0x1e0;
    arg->unk_f4 = 0;
    arg->unk_fa = 0;
    arg->unk_f8 = 0;
    arg->unk_100 = 0x280;
    arg->unk_fc = 0x280;
    value = fn_1_A5D9C();
    arg->unk_102 = value;
    arg->unk_fe = value;
    arg->unk_dc = 0;
    arg->unk_e0 = 0;
    arg->unk_e4 = lbl_1_rodata_31AC;
    arg->unk_104 = 0;
    arg->unk_108 = 0;
    arg->unk_a0[0] = 0;
    arg->unk_c8[0] = 0;
    arg->unk_a0[1] = 0;
    arg->unk_c8[1] = 0;
    arg->unk_a0[2] = 0;
    arg->unk_c8[2] = 0;
    arg->unk_a0[3] = 0;
    arg->unk_c8[3] = 0;
    arg->unk_a0[4] = 0;
    arg->unk_c8[4] = 0;
    fn_1_76DBC();
}
/* fzgx:end fn_1_76C60 */

/* fzgx:begin fn_1_76DBC noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"
extern void fn_1_76DBC(void);

// fn_1_76DBC: empty in retail (single blr).
void fn_1_76DBC(void) {
}
/* fzgx:end fn_1_76DBC */

/* fzgx:begin fn_1_76DC0 noprologue */
#include "types.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"
#include "dolphin/hw_regs.h"

extern u32 lbl_801A63C0;
extern const f32 lbl_1_rodata_31AC;

void fn_1_76DC0(s32 arg0) {
    
    if (arg0 == 17) {
        u32 v;
        u32 r;
        r = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        v = (r >> 16) & 0x7FFF;
        lbl_801A63C0 = r;
        *(u32 *)lbl_1_data_1DAB0 = lbl_1_data_1DA9C[v % 5];
        arg0 = 23;
    } else if (arg0 >= 18 && arg0 < 23) {
        u32 v = arg0 - 18;
        *(u32 *)lbl_1_data_1DAB0 = lbl_1_data_1DA9C[v % 5];
        arg0 = 23;
    }
    if (arg0 == 23) {
        lbl_1_data_1DAB4 = (*(f32 *)&lbl_1_rodata_31AC);
        lbl_1_data_1DAB8 = (*(f32 *)&lbl_1_rodata_31AC);
    }
    if (arg0 != 24) return;
    lbl_1_data_1DAB0[0] = 48;
    lbl_1_data_1DAB4 = 0.95f;
    lbl_1_data_1DAB8 = 0.95f;
    lbl_1_data_1DAB0[1] = 48;
    lbl_1_data_1DAB0[2] = 40;
    lbl_1_data_1DAB0[3] = 32;
}
/* fzgx:end fn_1_76DC0 */

/* fzgx:begin fn_1_76EB8 noprologue */
#include "types.h"
#include "rel/main_rel/screen_effect.h"

struct EffectTail { u32 unk_150; f32 unk_154; f32 unk_158; };
extern u16 fn_1_A5D9C(void);
extern u32 fn_80038EEC(f32,f32,f32,f32,f32,f32);
extern void fn_8003462C(u32, u32, u32);
extern void fn_80038F10(f32 *);
extern void fn_800720B0(u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073678(u32);
extern void fn_800736C0(u32,void *);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
void fn_1_76EB8(void) {
    Obj_1_data_1D960 *p_lbl_1_data_1D960;
    s32 lab_t1;
    s32 lab_t2;
    f32 v0,v1,v2,v3,v4,v5,v6;
    u32 v7;
    f32 v8,v9,v10,v11;
    struct { f32 a[6]; } loc_C;
    u32 loc_8;
    u16 t29;
    p_lbl_1_data_1D960 = &lbl_1_data_1D960;
    loc_8 = ((struct EffectTail *)((u8 *)p_lbl_1_data_1D960 + 0x150))->unk_150;
    fn_800736C0(0, &loc_8);
    fn_800724C8();
    fn_8007245C(8704);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(2);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0,1,4,60,0,125);
    fn_80072AB0(0,0,0);
    fn_800734A8(0,0,0,255);
    fn_800735C8(0,12);
    fn_80073620(0,28);
    fn_80072C24(0,14,15,15,8);
    fn_80072D64(0,1,0,0,1,0);
    fn_80072CC4(0,4,7,7,6);
    fn_80072E20(0,0,0,1,1,0);
    fn_80073C6C(1);
    fn_80072AB0(1,0,0);
    fn_800734A8(1,0,1,255);
    fn_80073620(1,0);
    lab_t1 = 15;
    fn_80072C24(1, lab_t1, 0, 8, 15);
    fn_80072D64(1,0,0,0,1,0);
    fn_80072CC4(1,6,7,0,7);
    fn_80072E20(1,0,0,0,1,0);
    fn_800720B0(0);
    lab_t2 = 5;
    fn_800728A8(1, 1, lab_t2, 0);
    fn_80072864(2);
    v0 = 0.5f;
    v1 = (v0 * ((struct EffectTail *)((u8 *)p_lbl_1_data_1D960 + 0x150))->unk_154);
    v2 = (v0 * ((struct EffectTail *)((u8 *)p_lbl_1_data_1D960 + 0x150))->unk_158);
    v3 = (v0-v1);
    v4 = (v0-v2);
    v5 = (v0+v1);
    v6 = (v0+v2);
    fn_80038F10((f32 *)&loc_C);
    t29 = fn_1_A5D9C();
    v7 = (t29 & 0xFFFF);
    v8 = 0.0f;
    fn_80038EEC(v8,v8,640.0f,v7,v8,1.0f);
    fn_8003462C(128,7,4);
    v9 = 0.0f;
    v10 = 640.0f;
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v9;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    v11 = 480.0f;
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v9;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = 0.0f;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v3;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v4;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v10;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v9;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = 0.0f;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v5;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v4;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v10;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v11;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = 0.0f;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v5;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v6;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v9;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v11;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = 0.0f;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v3;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = v6;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    fn_80038EEC(loc_C.a[0],loc_C.a[1],loc_C.a[2],loc_C.a[3],loc_C.a[4],loc_C.a[5]);
}
/* fzgx:end fn_1_76EB8 */

/* fzgx:begin fn_1_77200 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"
extern void fn_1_77238(void);
extern void fn_1_772E0(void);
struct fn_1_77384_Work;
extern void fn_1_77384(struct fn_1_77384_Work *);

void fn_1_77200(void *arg) {
    fn_1_77238();
    fn_1_772E0();
    fn_1_77384(arg);
}
/* fzgx:end fn_1_77200 */

/* fzgx:begin fn_1_77238 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"
extern void fn_1_77238(void);
extern void fn_80072864(u32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_80074788(u32);
extern void fn_800738E0(s32, s32, s32);
extern void fn_80073D60(s32, s32, s32, s32, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072EDC(s32, s32);

void fn_1_77238(void) {
    fn_80072864(2);
    fn_800745A4(0, 1, 4, 30, 0, 125);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(1);
    fn_80074788(0);
    fn_800738E0(0, 0, 1);
    fn_80073D60(0, 0, 1, 0, 1);
    fn_800734A8(0, 0, 0, 255);
    fn_80072EDC(0, 3);
}
/* fzgx:end fn_1_77238 */

/* fzgx:begin fn_1_772E0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"
extern void fn_1_772E0(void);
extern f32 lbl_1_rodata_31B0[10];
extern const f32 lbl_1_rodata_31A0;
extern void lbl_8006D784(void *);
extern void fn_80073A58(int, void *, s8);
extern void fn_800739E0(s32, s32, s32);
extern void GXLoadTexMtxImm(void *, u32, u32);

void fn_1_772E0(void) {
    f32 first[16];
    f32 second[8];
    f32 values[6];

    lbl_8006D784(&first[4]);
    values[0] = lbl_1_rodata_31B0[0] * first[4];
    values[1] = lbl_1_rodata_31B0[0] * first[5];
    values[2] = *(const f32 *)&lbl_1_rodata_31A0;
    values[3] = lbl_1_rodata_31B0[0] * first[8];
    values[4] = lbl_1_rodata_31B0[0] * first[9];
    values[5] = lbl_1_rodata_31A0;
    fn_80073A58(1, values, 1);
    fn_800739E0(0, 0, 0);
    lbl_8006D784(second);
    GXLoadTexMtxImm(second, 30, 1);
}
/* fzgx:end fn_1_772E0 */

/* fzgx:begin fn_1_77384 noprologue */
#include "types.h"

extern u32 lbl_1_bss_6C8D8;


char lbl_1_data_1DCB4[] = "Error!:noise_update";

typedef struct fn_1_77384_Work {
    u8 pad_0[0xA0];
    u32 unk_A0[2];
    u8 pad_A8[0x38];
    s32 unk_E0;
} fn_1_77384_Work;

extern u32 lbl_801A63C0;
extern void OSPanic(const char *, int, const char *, ...);
extern s32 lbl_8006D2AC(f32);
extern f32 lbl_8006D188(s32);
extern s32 lbl_8006D3D0(f32);
extern f32 lbl_8006D21C(s32);
extern void DCFlushRange(void *, u32);

static inline s32 fn_1_77384_rand(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

#define CLAMP(v, lo, hi) ((v) < (lo) ? (lo) : ((v) > (hi) ? (hi) : (v)))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void fn_1_77384(fn_1_77384_Work *work) {
    u16 shift;
    s32 i;
    s32 n;
    s32 y;
    s32 x;
    s32 offset;
    s32 row;
    s8 dx;
    s8 dy;
    f32 depth = 30.0f;

    shift = 0;
    for (i = 1, n = 2; i <= 10; i++, n <<= 1) {
        if (n == 64) {
            shift = i;
        }
    }
    if (shift == 0) {
        OSPanic((const char *)lbl_1_data_1DAC0, 2847, lbl_1_data_1DCB4);
    }

    for (y = 0; y < 64; y++) {
        {
            s32 range = lbl_1_data_1DABC[0];
            row = fn_1_77384_rand() % (range * 2 + 1) - range;
        }
        for (x = 0; x < 64; x++) {
            switch (lbl_1_bss_6C8D8) {
            case 0:
                dx = row;
                dy = 0;
                break;
            case 1:
                dx = row;
                dy = 0;
                break;
            case 2: {
                s32 range = lbl_1_data_1DABC[0];
                dx = fn_1_77384_rand() % (range * 2 + 1) - range;
                dy = fn_1_77384_rand() % (range * 2 + 1) - range;
                break;
            }
            case 3: {
                s32 v = MIN(127.0f, ((work->unk_E0 * 2) % 64) * (0.2f * __abs(y % 16 - 8)));
                if (y % 32 < 16) {
                    dx = v;
                    dy = 0;
                } else {
                    dx = -v;
                    dy = 0;
                }
                break;
            }
            case 4: {
                s8 t = CLAMP((320.0f - x) / 4.0f, -128.0f, 127.0f);
                dx = CLAMP(t * (30 - work->unk_E0) * (0.3 + 0.2f * __abs(y % 16 - 8)), -128.0, 127.0);
                dy = 0;
                break;
            }
            case 5: {
                s16 size = lbl_1_data_1DABC[0] * 2;
                s16 cx = size / 2 + size * (x / size);
                s16 cy = size / 2 + size * (y / size);
                s32 tx;
                s32 ty;
                if (cx - x < -128) tx = -128; else tx = (cx - x > 127) ? 127 : cx - x;
                dx = tx;
                if (cy - y < -128) ty = -128; else ty = (cy - y > 127) ? 127 : cy - y;
                dy = ty;
                break;
            }
            case 6: {
                s16 size = lbl_1_data_1DABC[0];
                s16 cx;
                s16 cy;
                if ((y / size) % 2 != 0) {
                    cx = size / 2 + size * (x / size);
                } else {
                    cx = size * ((x - size / 2) / size);
                }
                cy = size / 2 + size * (y / size);
                dx = cx - x + fn_1_77384_rand() % (size * 2) - size;
                dy = cy - y + fn_1_77384_rand() % (size * 2) - size;
                break;
            }
            case 7: {
                s16 size = lbl_1_data_1DABC[0];
                s32 jx = fn_1_77384_rand() % (size / 2);
                s32 jy = fn_1_77384_rand() % (size / 2);
                s32 quarter = size / 4;
                s16 rx = x + jx - quarter;
                s16 ry = y + jy - quarter;
                s16 cx;
                s16 cy;
                if ((ry / size) % 2 != 0) {
                    cx = size / 2 + size * (rx / size);
                } else {
                    cx = size * ((rx - size / 2) / size);
                }
                cy = size / 2 + size * (ry / size);
                dx = cx - rx;
                dy = cy - ry;
                break;
            }
            case 8: {
                f32 k = -depth / 1024.0f;
                f32 ka = k * (x - 32.0f);
                f32 h0 = depth + ka * (x - 32.0f);
                f32 kb = k * ((x + 1) - 32.0f);
                f32 h1 = depth + kb * ((x + 1) - 32.0f);
                s32 a = lbl_8006D2AC(h1 - h0);
                dx = -h0 * lbl_8006D21C((s16)(a - lbl_8006D3D0(1.46f * lbl_8006D188(a))));
                dy = 0;
                break;
            }
            case 9:
            default:
                dx = 0;
                dy = 0;
                break;
            }
            offset = ((((x & 3) | ((x >> 2) << 4)) | ((y & 3) << 2)) | ((y >> 2) << (shift + 2))) * 2;
            ((u8 *)work->unk_A0[1])[offset] = dx + 0x80;
            ((u8 *)work->unk_A0[1])[offset + 1] = dy + 0x80;
        }
    }
    DCFlushRange((void *)work->unk_A0[1], 0x2000);
}
/* fzgx:end fn_1_77384 */

/* fzgx:begin fn_1_77B80 */
extern u32 lbl_1_bss_6D1A8[278];

extern u32 fn_80036104(void);
extern u32 GXGetTexObjHeight(u32 arg0);
extern u32 GXGetTexObjWidth(u32 arg0);
extern u32 fn_800360D8(u32 arg0);
extern void GXInitTexObj(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, int arg5, int arg6, int arg7);
extern void GXInitTexObjLOD(u32 arg0, int arg1, int arg2, int arg3, int arg4, int arg5, f32 arg6, f32 arg7, f32 arg8);

void fn_1_77B80(u32 arg0) {
    struct { u32 value; } value0;

    lbl_1_bss_6D1A8[0] = arg0;
    value0.value = fn_80036104();
    GXInitTexObj(lbl_1_bss_6D1A8[0], fn_800360D8(lbl_1_bss_6D1A8[0]), (GXGetTexObjWidth(lbl_1_bss_6D1A8[0])), (GXGetTexObjHeight(lbl_1_bss_6D1A8[0])), value0.value, 1, 1, 0);
    GXInitTexObjLOD(lbl_1_bss_6D1A8[0], 1, 1, 0, 0, 0,
        0.0f, 0.0f, 0.0f);
}
/* fzgx:end fn_1_77B80 */

/* fzgx:begin fn_1_77C5C noprologue */
#include "types.h"


typedef struct Elem {
    s16 x;
    s16 y;
    u32 unk_4;
    u32 unk_8;
} Elem;

typedef struct Node {
    struct Node *next;
    u32 count;
    Elem *elems;
} Node;

/* screen_effect.c .bss in retail order */
static u32 lbl_1_bss_6C8D8;
static u32 lbl_1_bss_6C8DC[2];
static u32 lbl_1_bss_6C8E4;
static u32 lbl_1_bss_6C8E8;
static u8 lbl_1_bss_6C8EC[0x860];
static u8 lbl_1_bss_6D14C[0x5C];
static u32 lbl_1_bss_6D1A8[3];
static BOOL sGridInit;
static Node sGridNode;
static Elem sGridElems[66];
static u32 sGridAlpha[66];
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_order(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink */
    s = *(u8 *)&lbl_1_bss_6C8D8;
    s = *(u8 *)&lbl_1_bss_6C8DC;
    s = *(u8 *)&lbl_1_bss_6C8E4;
    s = *(u8 *)&lbl_1_bss_6C8E8;
    s = *(u8 *)&lbl_1_bss_6C8EC;
    s = *(u8 *)&lbl_1_bss_6D14C;
    s = *(u8 *)&lbl_1_bss_6D1A8;
    s = *(u8 *)&sGridInit;
    s = *(u8 *)&sGridNode;
    s = *(u8 *)&sGridElems;
    s = *(u8 *)&sGridAlpha;
}
#pragma section code_type ".text"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[8] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFF910000, 0xFF760044, 0x6600FF32, 0x94009494, 0xCB0005CF, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 255.0f;
    s = 40.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.02500000037252903f;
    s = 40.959999084472656f;
    s = 409.6000061035156f;
    s = 2.0f;
    s = -2.0f;
    s = 0.009999999776482582f;
    s = 0.003000000026077032f;
    s = 5.0f;
    s = 15.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 480.0f;
    s = 0.949999988079071f;
    s = 640.0f;
    s = 30.0f;
    s = 127.0f;
    s = 0.20000000298023224f;
    s = -128.0f;
    s = 320.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3;
    d = -128.0;
    d = 127.0;
    s = 0.0009765625f;
    s = 32.0f;
    s = 1.4600000381469727f;
    s = 639.0f;
    s = 10.0f;
    s = 0.1422991007566452f;
}
#pragma section code_type ".text"


typedef struct {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
    s16 unk_A;
} fn_1_77C5C_Rect;

typedef struct {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
} fn_1_77C5C_Size;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} WGPipe;

volatile WGPipe GXWGFifo : 0xCC008000; /* fzgx-allow: A1 write-gather FIFO port */

extern u8 lbl_1_data_1DAC0[0x44];
extern u8 lbl_1_data_1DB9C[0x24];
extern u16 fn_1_A5DB0(void);
extern void fn_1_9E598(Node *);
extern u8 fn_1_7879C(u32);
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_8007245C(u32);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800724C8(void);

static inline void GXPosition3f32(const f32 x, const f32 y, const f32 z) {
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
}

static inline void GXColor4u8(const u8 r, const u8 g, const u8 b, const u8 a) {
    GXWGFifo.u8 = r;
    GXWGFifo.u8 = g;
    GXWGFifo.u8 = b;
    GXWGFifo.u8 = a;
}

static inline void GXTexCoord2f32(const f32 s, const f32 t) {
    GXWGFifo.f32 = s;
    GXWGFifo.f32 = t;
}

static inline BOOL fn_1_77C5C_in_unit(f32 v) {
    if (v > 1.0f) {
        return FALSE;
    }
    if (v < 0.0f) {
        return FALSE;
    }
    return TRUE;
}

void fn_1_77C5C(const f32 *pos, const fn_1_77C5C_Rect *rect, const fn_1_77C5C_Size *size) {
    f32 s[4];
    f32 t[4];
    s32 j;
    s32 i;
    f32 vx[4];
    f32 vy[4];
    f32 vs[4];
    f32 vt[4];
    u8 a0;
    u8 a1;
    u8 a2;
    u8 a3;

    if (!sGridInit) {
        sGridNode.count = 66;
        sGridNode.elems = sGridElems;
        for (i = 0; i <= 5; i++) {
            for (j = 0; j <= 10; j++) {
                sGridNode.elems[i * 11 + j].x = 639.0f * (pos[0] * (10 - j) / 10.0f + pos[3] * j / 10.0f) / 640.0f;
                sGridNode.elems[i * 11 + j].y = (pos[1] * (5 - i) / 5.0f + pos[10] * i / 5.0f) * (fn_1_A5DB0() - 1) / 480.0f;
                sGridNode.elems[i * 11 + j].unk_4 = 0;
            }
        }
        sGridInit = 1;
    }

    fn_1_9E598(&sGridNode);

    s[0] = s[3] = (rect->unk_0 - size->unk_0) / (f32)size->unk_4;
    s[1] = s[2] = (rect->unk_0 + rect->unk_4 - size->unk_0) / (f32)size->unk_4;
    t[0] = t[1] = ((s32)((rect->unk_2 * fn_1_A5DB0()) / 480.0f) - size->unk_2) / (f32)size->unk_6;
    t[2] = t[3] = ((s32)((rect->unk_2 * fn_1_A5DB0()) / 480.0f) + (s32)((rect->unk_6 * fn_1_A5DB0()) / 480.0f) - size->unk_2) / (f32)size->unk_6;

    for (i = 0; i < 4; i++) {
        if (!fn_1_77C5C_in_unit(s[i]) || !fn_1_77C5C_in_unit(t[i])) {
            OSPanic((const char *)lbl_1_data_1DAC0, 3108, (const char *)lbl_1_data_1DB9C);
        }
    }

    for (i = 0; i <= 5; i++) {
        for (j = 0; j <= 10; j++) {
            if (i != 5) {
                sGridAlpha[i * 11 + j] += 0.2f * (s32)(sGridNode.elems[i * 11 + j].unk_4 - sGridAlpha[i * 11 + j]);
            } else {
                sGridAlpha[i * 11 + j] = 0;
            }
        }
    }

    fn_8007245C(0x2A00);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 10; j++) {
            vx[0] = vx[3] = rect->unk_8 + pos[0] * (10 - j) / 10.0f + pos[3] * j / 10.0f;
            vx[1] = vx[2] = rect->unk_8 + pos[0] * (10 - (j + 1)) / 10.0f + pos[3] * (j + 1) / 10.0f;
            vy[0] = vy[1] = rect->unk_A + pos[1] * (5 - i) / 5.0f + pos[10] * i / 5.0f;
            vy[2] = vy[3] = rect->unk_A + pos[1] * (5 - (i + 1)) / 5.0f + pos[10] * (i + 1) / 5.0f;
            vs[0] = vs[3] = s[0] * (10 - j) / 10.0f + s[1] * j / 10.0f;
            vs[1] = vs[2] = s[0] * (10 - (j + 1)) / 10.0f + s[1] * (j + 1) / 10.0f;
            vt[0] = vt[1] = t[0] * (5 - i) / 5.0f + t[3] * i / 5.0f;
            vt[2] = vt[3] = t[0] * (5 - (i + 1)) / 5.0f + t[3] * (i + 1) / 5.0f;
            a0 = fn_1_7879C(sGridAlpha[i * 11 + j]);
            a1 = fn_1_7879C(sGridAlpha[i * 11 + (j + 1)]);
            a2 = fn_1_7879C(sGridAlpha[(i + 1) * 11 + (j + 1)]);
            a3 = fn_1_7879C(sGridAlpha[(i + 1) * 11 + j]);
            fn_8003462C(0x80, 0, 4);
            GXPosition3f32(vx[0], vy[0], 0.0f);
            GXColor4u8(0, 0, 0, a0);
            GXTexCoord2f32(vs[0], vt[0]);
            GXPosition3f32(vx[1], vy[1], 0.0f);
            GXColor4u8(0, 0, 0, a1);
            GXTexCoord2f32(vs[1], vt[1]);
            GXPosition3f32(vx[2], vy[2], 0.0f);
            GXColor4u8(0, 0, 0, a2);
            GXTexCoord2f32(vs[2], vt[2]);
            GXPosition3f32(vx[3], vy[3], 0.0f);
            GXColor4u8(0, 0, 0, a3);
            GXTexCoord2f32(vs[3], vt[3]);
        }
    }
    fn_800724C8();

    for (i = 0; i <= 5; i++) {
        for (j = 0; j <= 10; j++) {
            sGridNode.elems[i * 11 + j].unk_4 = 0;
        }
    }
}
/* fzgx:end fn_1_77C5C */

/* fzgx:begin fn_1_7879C */
extern const f32 lbl_1_rodata_323C;
extern const f64 lbl_1_rodata_31D8;

u8 fn_1_7879C(u32 arg0) {
    s32 v0;

    v0 = (lbl_1_rodata_323C * (s32)((arg0 - 0x1000000) + 2048));
    return (v0 < 0 ? 0 : (v0 <= 255 ? v0 : 0xff));
}
/* fzgx:end fn_1_7879C */

/* fzgx:begin fn_1_7880C */
#pragma section code_type ".fzgxpool"
static const u32 fn_1_7880C_fzgx_pool_table1[8] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFF910000, 0xFF760044, 0x6600FF32, 0x94009494, 0xCB0005CF, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7880C_fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fn_1_7880C_fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7880C_fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 255.0f;
    s = 40.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.02500000037252903f;
    s = 40.959999084472656f;
    s = 409.6000061035156f;
    s = 2.0f;
    s = -2.0f;
    s = 0.009999999776482582f;
    s = 0.003000000026077032f;
    s = 5.0f;
    s = 15.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 480.0f;
    s = 0.949999988079071f;
    s = 640.0f;
    s = 30.0f;
    s = 127.0f;
    s = 0.20000000298023224f;
    s = -128.0f;
    s = 320.0f;
    s = 0.25f;
}
static const u32 fn_1_7880C_fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_7880C_fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fn_1_7880C_fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_7880C_fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3;
    d = -128.0;
    d = 127.0;
    s = 0.0009765625f;
    s = 32.0f;
    s = 1.4600000381469727f;
    s = 639.0f;
    s = 10.0f;
    s = 0.1422991007566452f;
}
#pragma section code_type ".text"

typedef struct {
    f32 x, y, z;
} Vec3;

extern void fn_80072558(void);
extern u32 lbl_8006DCA4(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E13C(void *);
extern u32 fn_800384FC(u32, u32);

void fn_1_7880C(void)
{
    Vec3 pos = { 0.0f, 0.0f, 0.0f };
    Vec3 scale = { 20.0f, 20.0f, 20.0f };

    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    scale.x = 20.0f;
    scale.y = 20.0f;
    scale.z = 20.0f;
    fn_80072864(1);
    fn_80072558();
    lbl_8006DCA4();
    lbl_8006E0A4(&pos);
    lbl_8006E13C(&scale);
    fn_80072558();
    fn_800384FC(10, 10);
}
/* fzgx:end fn_1_7880C */

/* fzgx:begin fn_1_788B0 */
#pragma section code_type ".fzgxpool"
static const u32 fn_1_788B0_fzgx_pool_table1[8] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFF910000, 0xFF760044, 0x6600FF32, 0x94009494, 0xCB0005CF, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_788B0_fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fn_1_788B0_fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_788B0_fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 255.0f;
    s = 40.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.02500000037252903f;
    s = 40.959999084472656f;
    s = 409.6000061035156f;
    s = 2.0f;
    s = -2.0f;
    s = 0.009999999776482582f;
    s = 0.003000000026077032f;
    s = 5.0f;
    s = 15.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 480.0f;
    s = 0.949999988079071f;
    s = 640.0f;
    s = 30.0f;
    s = 127.0f;
    s = 0.20000000298023224f;
    s = -128.0f;
    s = 320.0f;
    s = 0.25f;
}
static const u32 fn_1_788B0_fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fn_1_788B0_fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fn_1_788B0_fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fn_1_788B0_fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3;
    d = -128.0;
    d = 127.0;
    s = 0.0009765625f;
    s = 32.0f;
    s = 1.4600000381469727f;
    s = 639.0f;
    s = 10.0f;
    s = 0.1422991007566452f;
}
static const u32 fzgx_pool_table5[6] = {0x00000000, 0x00000000, 0x00000000, 0x41A00000, 0x41A00000, 0x41A00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
}
#pragma section code_type ".text"

typedef struct { f32 x, y, z; } Vec3;
extern u32 lbl_8006DCA4(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E13C(void *);
extern void fn_80072558(void);
extern u32 fn_800384FC(u32, u32);

void fn_1_788B0(u32 lab_unused0, u32 lab_unused1, u16 lab_unused2)
{
    Vec3 pos = { 0.0f, 0.0f, 0.0f };
    Vec3 scale = { 20.0f, 20.0f, 20.0f };
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    scale.x = 20.0f;
    scale.y = 20.0f;
    scale.z = 20.0f;
    fn_80072864(2);
    lbl_8006DCA4();
    lbl_8006E0A4(&pos);
    lbl_8006E13C(&scale);
    fn_80072558();
    fn_800384FC(10, 10);
}
/* fzgx:end fn_1_788B0 */

/* fzgx:begin fn_1_78950 */
// Reset the screen effect state and refresh its processing stages twice.
void fn_1_78950(void) {
    int i;

    lbl_1_bss_6D14C.unk_0 = 1;
    for (i = 0; i < 2; i++) {
        fn_8006FDEC();
        fn_8006FEFC();
        fn_8006FD1C();
    }
}
/* fzgx:end fn_1_78950 */

/* fzgx:begin fn_1_7899C */
// Reset the screen-effect state before the next effect begins.
void fn_1_7899C(void) {
    lbl_1_bss_6D14C.unk_0 = 0;
}
/* fzgx:end fn_1_7899C */

/* fzgx:begin fn_1_789AC */
void fn_1_789AC(void) {
    fn_1_79810();
    fn_1_79948();
    fn_1_791B0();
    fn_1_9A1E8();
    lbl_1_data_1DFA4.unk_4 = 0;
}
/* fzgx:end fn_1_789AC */
