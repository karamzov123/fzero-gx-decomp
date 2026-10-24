#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/screen_effect.h"

extern u32 lbl_1_bss_6C8DC[2];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_727BC(u32 arg0, u32 arg1, void *arg2);
extern void fn_1_76A94(void *arg0, u32 arg1);
extern void fn_1_76DBC(void);
extern void fn_1_4E500(void);
extern void fn_1_4E638(int);
extern void fn_1_4E6F4(void);
extern void fn_80073778(void *arg0, int arg1);
extern s32 fn_1_A5D9C(void);
extern const f32 lbl_1_rodata_31AC;
extern u32 fn_80008E84(u32 arg);
extern void fn_1_77238(void);
extern void fn_1_772E0(void);
extern void fn_1_77384(void *arg);
extern void fn_80072864(int arg0);
extern void fn_800745A4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern void fn_80074660(int arg0);
extern void fn_80073678(int arg0);
extern void fn_80073898(int arg0);
extern void fn_80074788(int arg0);
extern void fn_800738E0(int arg0, int arg1, int arg2);
extern void fn_80073D60(int arg0, int arg1, int arg2, int arg3, int arg4);
extern void fn_800734A8(int arg0, int arg1, int arg2, int arg3);
extern void fn_80072EDC(int arg0, int arg1);
extern f32 lbl_1_rodata_31B0[10];
extern const f64 lbl_1_rodata_31A0;
extern void lbl_8006D784(f32 *arg);
extern void fn_80073A58(int arg0, f32 *arg1, int arg2);
extern void fn_800739E0(int arg0, int arg1, int arg2);
extern void GXLoadTexMtxImm(f32 *arg0, int arg1, int arg2);
extern void fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8006FD1C(void);
extern void fn_1_79810(void);
extern void fn_1_79948(void);
extern void fn_1_791B0(void);
extern void fn_1_9A1E8(void);
extern void fn_1_9A864(void);
extern u8 fn_1_7B074(void);
extern void fn_80071718(void *arg);
extern void fn_800711A8(void *arg);
extern void fn_1_14CB4(void);
extern void fn_1_FA84(void);
extern const f32 lbl_1_rodata_32CC;
extern void fn_1_79C88(void *arg0, s32 arg1, f32 arg2, s32 arg3);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void sprintf(char *dst, const char *format, ...);
extern void fn_1_465D0(char *text, int arg);
extern void fn_1_14D5C(void *object, int arg);
extern void fn_1_46EA8(int value);
extern void fn_1_12620(void *object);
extern void fn_1_46DC4(void *obj);

extern void fn_1_727BC();
extern void fn_8006FDEC(void);
extern void fn_80071718(void *);
extern void fn_800711A8(void *);
extern u32 fn_8003526C(u32, u32);
extern u32 fn_80074300(u32, u32, u32, u32);
extern u32 fn_80074438(u32, u32, u32, u32);

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

/* fzgx:begin fn_1_727BC */
struct fn_1_727BC_lbl_1_data_1D960_58_E6 {
    u8 pad_0[0x5];
    u8 unk_5;
};
extern void OSPanic(const char *, int, const char *, ...);

static inline struct fn_1_727BC_lbl_1_data_1D960_58_E6 *fn_1_727BC_array_read(struct fn_1_727BC_lbl_1_data_1D960_58_E6 *array) { return array; }
#pragma opt_dead_assignments off
void fn_1_727BC(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 v0;
    s32 v1;
    s32 v2;
    s32 v3;
    Obj_1_data_1D960 *data = &lbl_1_data_1D960;
    Obj_1_bss_6C8EC *obj;
    struct fn_1_727BC_lbl_1_data_1D960_58_E6 *table;
    s32 valid;
    v0 = (arg0 & 0xFF);
    obj = (Obj_1_bss_6C8EC *)((u8 *)&lbl_1_bss_6C8EC + v0 * 0x10C);
    if (v0 <= 7) {
        v1 = obj->unk_DC;
        v2 = (arg1 & 0xFF);
        table = (struct fn_1_727BC_lbl_1_data_1D960_58_E6 *)(data + 1);
        v3 = fn_1_727BC_array_read(table)[v1].unk_5 - 1;
        valid = v2 <= v3;
        if (valid != 0U && v1 != 0) return;
    }
    OSPanic((const char *)data + 0x160, 394, (const char *)data + 0x18C);
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_727BC */

/* fzgx:begin fn_1_72848 */
extern void fn_1_76650(void *);

void fn_1_72848(void) {
    u8 i;

    // Reset each screen-effect entry before clearing the active-effect flag.
    for (i = 0; i < 8; i++) {
        fn_1_76650((u8 *)&lbl_1_bss_6C8EC + i * 0x10c);
    }
    lbl_1_bss_6D14C.unk_0 = 0;
}
/* fzgx:end fn_1_72848 */

/* fzgx:begin fn_1_728B0 */
typedef struct {
    u8 pad_0[0xdc];
    s32 unk_DC;
    s32 unk_E0;
    u8 pad_E4[0x20];
    void (*unk_104)(void *);
} fn_1_728B0_ScreenEffectEntry;

extern void fn_1_72980(fn_1_728B0_ScreenEffectEntry *);
extern void *fn_1_729F8(fn_1_728B0_ScreenEffectEntry *);

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
                    fn_1_72980(obj);
                    result = fn_1_729F8(obj);
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

/* fzgx:begin fn_1_72980 */
typedef struct {
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

extern struct fn_1_729F8_Bss lbl_1_bss_6C8D8;
u8 lbl_1_data_1D960[88] = {0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x11,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x39,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x3A,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x13,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x27};
u8 lbl_1_data_1D9B8[248] = {0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00,0x01,0x06,0x06,0x00,0x00,0x00,0x02,0x06,0x06,0x00,0x00,0x00,0x02,0x06,0x06,0x00,0x00,0x00,0x02,0x06,0x06,0x00,0x00,0x00,0x02,0x00,0x01,0x06,0x00,0x00,0x03,0x00,0x01,0x06,0x00,0x00,0x03,0x00,0x01,0x06,0x00,0x00,0x03,0x00,0x01,0x06,0x03,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x01,0x04,0x06,0x00,0x00,0x00,0x02,0x04,0x06,0x00,0x00,0x00,0x02,0x04,0x06,0x00,0x00,0x00,0x02,0x04,0x06,0x00,0x00,0x00,0x02,0x04,0x06,0x00,0x00,0x00,0x02,0x04,0x06,0x00,0x00,0x00,0x02,0x04,0x06,0x00,0x00,0x00,0x02,0x04,0x06,0x00,0x00,0x00,0x02,0x06,0x06,0x00,0x00,0x00,0x02,0x06,0x03,0x00,0x00,0x00,0x02,0x06,0x03,0x00,0x00,0x00,0x02,0x05,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00,0x01,0x05,0x04,0x00,0x00,0x00,0x02,0x09,0x00,0x00,0x00,0x00,0x01,0x04,0x08,0x00,0x00,0x00,0x02,0x04,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x06,0x00,0x00,0x03,0x06,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x07,0x00,0x00,0x03,0x04,0x00,0x00,0x00,0x00,0x01,0x30,0x50,0x60,0x20,0x38,0x62,0x34,0x20,0x60,0x60,0x50,0x40,0x60,0x50,0x50,0x30,0x70,0x50,0x40,0x20};
u8 lbl_1_data_1D9B8__fzgx_offset_F8[4] = {0x30,0x50,0x60,0x20};
f32 lbl_1_data_1D9B8__fzgx_offset_FC = 1.0f;
f32 lbl_1_data_1D9B8__fzgx_offset_100 = 1.0f;
u8 lbl_1_data_1D9B8__fzgx_offset_104[4] = {0x08,0x00,0x00,0x00};
u8 lbl_1_data_1DAC0[68] = {0x73,0x63,0x72,0x65,0x65,0x6E,0x5F,0x65,0x66,0x66,0x65,0x63,0x74,0x2E,0x63,0x00,0x43,0x61,0x6E,0x27,0x74,0x20,0x44,0x6F,0x75,0x62,0x6C,0x65,0x20,0x43,0x72,0x65,0x61,0x74,0x65,0x20,0x48,0x65,0x61,0x70,0x0A,0x00,0x00,0x00,0x45,0x72,0x72,0x6F,0x72,0x21,0x20,0x3A,0x20,0x57,0x72,0x6F,0x6E,0x67,0x20,0x56,0x61,0x6C,0x75,0x65,0x2E,0x00,0x00,0x00};
extern f32 *lbl_801A6D00;
extern u32 lbl_801A66A0;



extern void fn_1_75D84(void *, void *, void *);
extern void fn_1_761B8(void *, u32);
extern void fn_1_76C60(void *);
extern void fn_1_76EB8(void);
extern void fn_1_77200(void);
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
extern u32 fn_80072CC4(u32, u32, u32, u32, u32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80072EDC(u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073678(u32);
extern void fn_800736C0(u32, void *);
extern void fn_80073778(void *, s32);
extern void fn_80073898(u32);
extern void fn_800738E0(s32, s32, s32);
extern void fn_800739E0(s32, s32, s32);
extern void fn_80073A58(s32, void *, s8);
extern void fn_80073C6C(s32);
extern void fn_80073D60(u32, u32, u32, u32, u32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8, s32, u8);
extern void GXLoadTexMtxImm(void *, u32, u32);
extern void GXSetAlphaCompare(s32, s32, s32, s32, s32);

union Color { struct {u8 r, g, b, a;} bytes; u32 word; };
#pragma fp_contract off

/* The four vec3 rows and the colour/scratch words are members of a single
   aggregate each in the original; splitting them changes the stack layout. */
#define v168 vbuf
#define v174 (vbuf + 3)
#define v180 (vbuf + 6)
#define v18C (vbuf + 9)
#define w88 color88

void fn_1_729F8(struct fn_1_729F8_Arg0 *arg0)
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

    p_bss = &lbl_1_bss_6C8D8;

    { const union Color initial = {{0xFF,0xFF,0xFF,0xFF}}; color80 = initial; }
    v18C[0] = 0.0f;
    v168[0] = 0.0f;
    w = (f32)(s32)arg0->unk_EC;
    v174[1] = 0.0f;
    v168[1] = 0.0f;
    v180[0] = w;
    v174[0] = w;
    w = (f32)(s32)arg0->unk_EE;
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
        color84.bytes.a = (u8)(s32)(255.0f - (f32)(s32)(arg0->unk_E0 * 255) / 40.0f);
        color7c = color84.word;
        fn_800371F8(1, (&color7c));
        fn_1_761B8(arg0, mode);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;

    case 4:
        if (arg0->unk_E0 == 0)
            arg0->unk_E4 = 1.0f;
        v168[0] = v18C[0] = -(0.5f * (f32)(s32)arg0->unk_EC) * arg0->unk_E4;
        v174[0] = v180[0] = (0.5f * (f32)(s32)arg0->unk_EC) * arg0->unk_E4;
        v168[1] = v174[1] = -(0.5f * (f32)(s32)arg0->unk_EE) * arg0->unk_E4;
        v180[1] = v18C[1] = (0.5f * (f32)(s32)arg0->unk_EE) * arg0->unk_E4;
        lbl_8006D758();
        v168[0] = v168[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v174[0] = v174[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v180[0] = v180[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v18C[0] = v18C[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v168[1] = v168[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        v174[1] = v174[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        v180[1] = v180[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        v18C[1] = v18C[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        arg0->unk_E0++;
        arg0->unk_E4 -= 0.025f;
        if (arg0->unk_E4 < 0.025f)
            fn_1_76C60(arg0);
        s78 = color84.word;
        fn_800371F8(1, &s78);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;

    case 5:
        if (arg0->unk_E0 == 0)
            arg0->unk_E4 = 1.0f;
        v168[0] = v18C[0] = -(0.5f * (f32)(s32)arg0->unk_EC) * arg0->unk_E4;
        v174[0] = v180[0] = (0.5f * (f32)(s32)arg0->unk_EC) * arg0->unk_E4;
        v168[1] = v174[1] = -(0.5f * (f32)(s32)arg0->unk_EE) * arg0->unk_E4;
        v180[1] = v18C[1] = (0.5f * (f32)(s32)arg0->unk_EE) * arg0->unk_E4;
        lbl_8006D758();
        mathutil_mtxA_rotate_z((s32)(-(40.96f * (f32)(s32)(arg0->unk_E0 * arg0->unk_E0))));
        lbl_8006E1B0(v168, v168);
        lbl_8006E1B0(v174, v174);
        lbl_8006E1B0(v180, v180);
        lbl_8006E1B0(v18C, v18C);
        v168[0] = v168[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v174[0] = v174[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v180[0] = v180[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v18C[0] = v18C[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v168[1] = v168[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        v174[1] = v174[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        v180[1] = v180[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        v18C[1] = v18C[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        arg0->unk_E0++;
        arg0->unk_E4 -= 0.025f;
        if (arg0->unk_E4 < 0.025f)
            fn_1_76C60(arg0);
        s74 = color84.word;
        fn_800371F8(1, &s74);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;

    case 6:
        v168[0] = v18C[0] = (f32)(s32)arg0->unk_E0 * ((f32)(s32)(-arg0->unk_EC) / 40.0f);
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC + (f32)(s32)arg0->unk_E0 * ((f32)(s32)(-arg0->unk_EC) / 40.0f);
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
        fn_1_761B8(arg0, 1);
        s70 = color84.word;
        fn_800371F8(1, &s70);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;

    case 7:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
        lbl_8006D758();
        mathutil_mtxA_rotate_z((s32)(-(409.6f * (f32)(s32)arg0->unk_E0)));
        lbl_8006E1B0(v168, v168);
        lbl_8006E1B0(v174, v174);
        lbl_8006E1B0(v180, v180);
        lbl_8006E1B0(v18C, v18C);
        fn_1_761B8(arg0, 1);
        s6C = color84.word;
        fn_800371F8(1, &s6C);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;

    case 8:
        if (arg0->unk_E0 == 0)
            arg0->unk_E4 = 0.0f;
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
        s68 = color84.word;
        fn_800371F8(1, &s68);
        fn_800734A8(0, 0, 0, 255);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        v168[0] = v18C[0] = -(0.5f * (f32)(s32)arg0->unk_EC) * arg0->unk_E4;
        v174[0] = v180[0] = (0.5f * (f32)(s32)arg0->unk_EC) * arg0->unk_E4;
        v168[1] = v174[1] = -(0.5f * (f32)(s32)arg0->unk_EE) * arg0->unk_E4;
        v180[1] = v18C[1] = (0.5f * (f32)(s32)arg0->unk_EE) * arg0->unk_E4;
        v168[0] = v168[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v174[0] = v174[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v180[0] = v180[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v18C[0] = v18C[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v168[1] = v168[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        v174[1] = v174[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        v180[1] = v180[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        v18C[1] = v18C[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        arg0->unk_E0++;
        arg0->unk_E4 += 0.025f;
        if (arg0->unk_E4 > 1.0f)
            arg0->unk_E4 = 1.0f;
        if ((f32)(s32)arg0->unk_E0 > 40.0f)
            fn_1_76C60(arg0);
        s64 = color84.word;
        fn_800371F8(1, &s64);
        fn_800734A8(0, 0, 1, 255);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;

    case 9:
        if (arg0->unk_E0 == 0)
            arg0->unk_E4 = 0.0f;
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
        s60 = color84.word;
        fn_800371F8(1, &s60);
        fn_800734A8(0, 0, 0, 255);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        v168[0] = v18C[0] = -(0.5f * (f32)(s32)arg0->unk_EC) * arg0->unk_E4;
        v174[0] = v180[0] = (0.5f * (f32)(s32)arg0->unk_EC) * arg0->unk_E4;
        v168[1] = v174[1] = -(0.5f * (f32)(s32)arg0->unk_EE) * arg0->unk_E4;
        v180[1] = v18C[1] = (0.5f * (f32)(s32)arg0->unk_EE) * arg0->unk_E4;
        lbl_8006D758();
        mathutil_mtxA_rotate_z((s32)(-(40.96f * ((40.0f - (f32)(s32)arg0->unk_E0) * (40.0f - (f32)(s32)arg0->unk_E0)))));
        lbl_8006E1B0(v168, v168);
        lbl_8006E1B0(v174, v174);
        lbl_8006E1B0(v180, v180);
        lbl_8006E1B0(v18C, v18C);
        v168[0] = v168[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v174[0] = v174[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v180[0] = v180[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v18C[0] = v18C[0] + 0.5f * (f32)(s32)arg0->unk_EC;
        v168[1] = v168[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        v174[1] = v174[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        v180[1] = v180[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        v18C[1] = v18C[1] + 0.5f * (f32)(s32)arg0->unk_EE;
        arg0->unk_E0++;
        arg0->unk_E4 += 0.025f;
        if (arg0->unk_E4 > 1.0f)
            arg0->unk_E4 = 1.0f;
        if ((f32)(s32)arg0->unk_E0 > 40.0f)
            fn_1_76C60(arg0);
        s5C = color84.word;
        fn_800371F8(1, &s5C);
        fn_800734A8(0, 0, 1, 255);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;

    case 10:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
        s58 = color84.word;
        fn_800371F8(1, &s58);
        fn_800734A8(0, 0, 0, 255);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        v168[0] = v18C[0] = (40.0f - (f32)(s32)arg0->unk_E0) * ((f32)(s32)(-arg0->unk_EC) / 40.0f);
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC + (40.0f - (f32)(s32)arg0->unk_E0) * ((f32)(s32)(-arg0->unk_EC) / 40.0f);
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
        fn_1_761B8(arg0, 1);
        s54 = color84.word;
        fn_800371F8(1, &s54);
        fn_800734A8(0, 0, 1, 255);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;

    case 11:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
        s50 = color84.word;
        fn_800371F8(1, &s50);
        fn_800734A8(0, 0, 0, 255);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        lbl_8006D758();
        mathutil_mtxA_rotate_z((s32)(-(409.6f * (40.0f - (f32)(s32)arg0->unk_E0))));
        lbl_8006E1B0(v168, v168);
        lbl_8006E1B0(v174, v174);
        lbl_8006E1B0(v180, v180);
        lbl_8006E1B0(v18C, v18C);
        fn_1_761B8(arg0, 1);
        s4C = color84.word;
        fn_800371F8(1, &s4C);
        fn_800734A8(0, 0, 1, 255);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;

    case 12:
    case 13:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
        color84.bytes.a = 0xff;
        flag = (arg0->unk_DC == 12);
        s48 = color84.word;
        fn_800371F8(2, &s48);
        color84.bytes.a = flag ? 0xfe : 0xff;
        s44 = color84.word;
        fn_800371F8(1, &s44);
        lbl_8006D758();
        lbl_801A6D00[3] = 2.0f / (f32)(s32)arg0->unk_EC;
        lbl_801A6D00[7] = 2.0f / (f32)(s32)arg0->unk_EE;
        GXLoadTexMtxImm(lbl_801A6D00, 30, 1);
        lbl_801A6D00[3] = 2.0f / (f32)(s32)arg0->unk_EC;
        lbl_801A6D00[7] = -2.0f / (f32)(s32)arg0->unk_EE;
        GXLoadTexMtxImm(lbl_801A6D00, 33, 1);
        lbl_801A6D00[3] = -2.0f / (f32)(s32)arg0->unk_EC;
        lbl_801A6D00[7] = -2.0f / (f32)(s32)arg0->unk_EE;
        GXLoadTexMtxImm(lbl_801A6D00, 36, 1);
        lbl_801A6D00[3] = -2.0f / (f32)(s32)arg0->unk_EC;
        lbl_801A6D00[7] = 2.0f / (f32)(s32)arg0->unk_EE;
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
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;

    case 14:
    case 15:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
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
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        fn_80073678(1);
        fn_80073898(0);
        fn_80072C24(0, 15, 2, 8, 4);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 1, 4, 2);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        break;

    case 36:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
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
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        fn_80073678(1);
        fn_80073898(0);
        fn_80072C24(0, 15, 2, 8, 4);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 1, 4, 2);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        break;

    case 16:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
        lbl_8006D758();
        GXLoadTexMtxImm(lbl_801A6D00, 30, 1);
        lbl_801A6D00[3] = 2.0f / (f32)(s32)arg0->unk_EC;
        lbl_801A6D00[7] = 2.0f / (f32)(s32)arg0->unk_EE;
        GXLoadTexMtxImm(lbl_801A6D00, 33, 1);
        lbl_801A6D00[3] = 2.0f / (f32)(s32)arg0->unk_EC;
        lbl_801A6D00[7] = -2.0f / (f32)(s32)arg0->unk_EE;
        GXLoadTexMtxImm(lbl_801A6D00, 36, 1);
        lbl_801A6D00[3] = -2.0f / (f32)(s32)arg0->unk_EC;
        lbl_801A6D00[7] = -2.0f / (f32)(s32)arg0->unk_EE;
        GXLoadTexMtxImm(lbl_801A6D00, 39, 1);
        lbl_801A6D00[3] = -2.0f / (f32)(s32)arg0->unk_EC;
        lbl_801A6D00[7] = 2.0f / (f32)(s32)arg0->unk_EE;
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
            fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        }
        break;

    case 23:
        fn_1_76EB8();
        break;

    case 24: {
        if (lbl_1_data_1D9B8__fzgx_offset_F8[0] < 255)
            lbl_1_data_1D9B8__fzgx_offset_F8[0]++;
        if (lbl_1_data_1D9B8__fzgx_offset_F8[1] < 255)
            lbl_1_data_1D9B8__fzgx_offset_F8[1]++;
        if (lbl_1_data_1D9B8__fzgx_offset_F8[2] < 255)
            lbl_1_data_1D9B8__fzgx_offset_F8[2]++;
        if (lbl_1_data_1D9B8__fzgx_offset_F8[3] < 255)
            lbl_1_data_1D9B8__fzgx_offset_F8[3]++;
        if (lbl_1_data_1D9B8__fzgx_offset_F8[0] == 255 && lbl_1_data_1D9B8__fzgx_offset_F8[1] == 255 && lbl_1_data_1D9B8__fzgx_offset_F8[2] == 255 && lbl_1_data_1D9B8__fzgx_offset_F8[3] == 255) {
            fn_1_76C60(arg0);
        } else {
            lbl_1_data_1D9B8__fzgx_offset_FC = lbl_1_data_1D9B8__fzgx_offset_FC + 0.01f * (1.0f - lbl_1_data_1D9B8__fzgx_offset_FC);
            lbl_1_data_1D9B8__fzgx_offset_100 = lbl_1_data_1D9B8__fzgx_offset_100 + 0.01f * (1.0f - lbl_1_data_1D9B8__fzgx_offset_FC);
            fn_1_76EB8();
        }
        break;
    }

    case 25:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
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
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;

    case 26:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
        fn_1_77200();
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;

    case 27:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
        fn_1_77200();
        fn_1_4E220((u8 *)&p_bss->unk_8D0 - 0x58, 1, 1, 2, 33);
        fn_80074660(2);
        fn_80073678(2);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
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
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
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
        mD8[7] = 0.01f * (f32)lbl_801A66A0;
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
        color84.bytes.r = (u8)p_bss->unk_8D4;
        color84.bytes.g = (p_bss->unk_8D4 >> 8) & 0xff;
        color84.bytes.a = (u8)p_bss->unk_8D6;
        s2C = color84.word;
        fn_800371F8(1, &s2C);
        s28 = color84.word;
        fn_800736C0(0, &s28);
        fn_800735C8(0, 12);
        fn_80072C24(0, 8, 14, 3, 15);
        fn_80072D64(0, 10, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 7, 7, 7);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        color80.bytes.r = (u8)p_bss->unk_8D8;
        s24 = color80.word;
        fn_800736C0(1, &s24);
        fn_800735C8(1, 13);
        fn_80072C24(1, 8, 14, 0, 0);
        fn_80072D64(1, 8, 0, 0, 1, 0);
        fn_80072CC4(1, 7, 7, 7, 7);
        fn_80072E20(1, 0, 0, 0, 1, 0);
        fn_800728A8(1, 1, 5, 0);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;

    case 31:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
        s20 = color84.word;
        fn_800371F8(1, &s20);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;

    case 32:
        v168[0] = v18C[0] = 0.0f;
        v174[0] = v180[0] = (f32)(s32)arg0->unk_EC;
        v168[1] = v174[1] = 0.0f;
        v180[1] = v18C[1] = (f32)(s32)arg0->unk_EE;
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
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        fn_80072808();
        break;

    case 33:
        color84.bytes.a = (u8)(255 - p_bss->unk_8DA);
        { union Color s0C = color84;
        fn_800371F8(1, &s0C); }
        fn_80072C24(0, 8, 15, 15, 15);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 7, 7, 1);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
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
        fn_1_75D84(v168, &arg0->unk_E8, &arg0->unk_F8);
        break;
    }
}
/* fzgx:end fn_1_729F8 */

/* fzgx:begin fn_1_761B8 */
struct fn_1_761B8_Arg0 {
    u8 pad_0[0xE0];
    u32 unk_E0;
};

extern const f32 lbl_1_rodata_31A8;
extern const f64 lbl_1_rodata_31D8[2];
extern void fn_1_76C60(void);

void fn_1_761B8(struct fn_1_761B8_Arg0 *arg0, u32 arg1) {
    u32 v0;
    f32 v1;
    v0 = (arg0->unk_E0 + arg1);
    arg0->unk_E0 = v0;
    v1 = (f32)(s32)arg0->unk_E0;
    if (v1 > lbl_1_rodata_31A8) {
        fn_1_76C60();
    }
}
/* fzgx:end fn_1_761B8 */

/* fzgx:begin fn_1_76218 noprologue */
#include "types.h"

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

struct fn_1_76218_jumptable_1_data_1DBC0 {
    u32 unk_0[1];
};
extern struct fn_1_76218_jumptable_1_data_1DBC0 jumptable_1_data_1DBC0;
extern u8 lbl_1_bss_6C8EC[];
extern void DCInvalidateRange(struct Sig_fn_8004E278_fn_8004E278_Arg0 *, u32);
extern void fn_1_76448(struct Sig_fn_1_76448_fn_1_76448_Arg0 *, u32);
extern void fn_1_76C60(Sig_fn_1_76C60_FnScreenEffect *);
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
            temp_r28 = (struct Sig_fn_1_76448_fn_1_76448_Arg0 *)((u8 *)(lbl_1_bss_6C8EC) + (var_r29 * 0x10C));
            if ((s32) temp_r28->unk_DC == 0x25) {
                DCInvalidateRange((struct Sig_fn_8004E278_fn_8004E278_Arg0 *)(*(struct Sig_fn_8004E278_fn_8004E278_Arg0 **)((u8 *)(temp_r28) + 160)), (u32)(*(u32 *)((u8 *)(temp_r28) + 180)));
                fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28), (u32)(0U));
                fn_1_76C60((Sig_fn_1_76C60_FnScreenEffect *)((Sig_fn_1_76C60_FnScreenEffect *) temp_r28));
                var_r5 = 1;
            }
            var_r29 += 1;
                    }
    }
    var_r29_2 = 0;
    while (var_r29_2 < 8U) {
        temp_r28_2 = (struct Sig_fn_1_76448_fn_1_76448_Arg0 *)((u8 *)(lbl_1_bss_6C8EC) + (var_r29_2 * 0x10C));
        temp_r4 = temp_r28_2->unk_DC;
        if ((temp_r4 != 0) && ((u8) (*(u8 *)((u8 *)(temp_r28_2) + 264)) == 0)) {
            if (arg0 != 0) {
                switch (temp_r4) {
                case 0xE:
                    fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28_2), (u32)(2U));
                    break;
                case 0x17:
                case 0x18:
                    fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28_2), (u32)(0U));
                    fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28_2), (u32)(1U));
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
                    fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28_2), (u32)(0U));
                    break;
                case 14:
                case 30:
                    fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28_2), (u32)(0U));
                    fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28_2), (u32)(1U));
                    break;
                case 12:
                case 13:
                case 15:
                case 36:
                    fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28_2), (u32)(0U));
                    fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28_2), (u32)(1U));
                    fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28_2), (u32)(2U));
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                    if ((s32) (*(s32 *)((u8 *)(temp_r28_2) + 224)) == 0) {
                        fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28_2), (u32)(0U));
                    }
                    break;
                case 8:
                case 9:
                case 10:
                case 11:
                    if ((s32) (*(s32 *)((u8 *)(temp_r28_2) + 224)) == 0) {
                        fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28_2), (u32)(0U));
                    }
                    fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28_2), (u32)(1U));
                    break;
                case 34:
                    fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28_2), (u32)(2U));
                    fn_1_7880C();
                    fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28_2), (u32)(0U));
                    fn_1_788B0();
                    fn_1_76448((struct Sig_fn_1_76448_fn_1_76448_Arg0 *)(temp_r28_2), (u32)(1U));
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
/* fzgx:end fn_1_76218 */

/* fzgx:begin fn_1_76448 */
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
    v2 = *(u8 *)((u8 *)((u8 *)&lbl_1_data_1D9B8 + v1) + v0);
    v3 = (u32)((u8 *)&lbl_1_data_1D960 + (v2 << 3));
    fn_80074300((arg0->unk_F8 & 0xFFFF), (*(s16 *)((u8 *)(u32)arg0 + 250) & 0xFFFF), (*(s16 *)((u8 *)(u32)arg0 + 252) & 0xFFFF), (*(s16 *)((u8 *)(u32)arg0 + 254) & 0xFFFF));
    fn_80074438((*(s16 *)((u8 *)(u32)arg0 + 256) & 0xFFFF), (*(s16 *)((u8 *)(u32)arg0 + 258) & 0xFFFF), *(u32 *)((u8 *)v3 + 4), (*(u32 *)((u8 *)(u32)arg0 + 244) & 0xFF));
    fn_8003526C(arg0->unk_A0[v0], 0);
}
/* fzgx:end fn_1_76448 */

/* fzgx:begin fn_1_76650 */
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

/* fzgx:begin fn_1_76704 */
struct fn_1_76704_Copy16 { u32 a[4]; };

extern const f32 lbl_1_rodata_31E8;
extern const f64 lbl_1_rodata_31D8;
extern u16 fn_1_A5DB0(void);
extern u8 lbl_1_data_1DAC0[0x44];
extern u8 lbl_1_data_1DC80[0x48];
extern void OSPanic(const char *, int, const char *, ...);

static inline u32 fn_1_76704_operand(u32 right, u32 left) { left *= right; return left; }
#pragma opt_propagation off
static inline u32 fn_1_76704_operand_(u32 right, u32 left) { left *= right; return left; }
#pragma opt_dead_assignments off
f32 fn_1_76704(void * arg0, void * arg1) {
    u8 *p = (u8 *)arg0;
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
    t1 = (u16)(fn_1_A5DB0());
    *(u16 *)(p + 250) = (s32)((f32)(*(s16 *)(p + 234) * (s32)(t1 & 0xFFFF)) / lbl_1_rodata_31E8);
    a = *(s16 *)(p + 248);
    t1 = a - (((a & 1) ^ ((u32)a >> 31)) - ((u32)a >> 31));
    a = t1;
    *(u16 *)(p + 248) = a;
    b = *(s16 *)(p + 250);
    b = b - (((b & 1) ^ ((u32)b >> 31)) - ((u32)b >> 31));
    *(u16 *)(p + 250) = b;
    *(u16 *)(p + 252) = (*(s16 *)(p + 236) + *(s16 *)(p + 232)) - *(s16 *)(p + 248);
    v8 = (f32)(((*(s16 *)(p + 238) + *(s16 *)(p + 234)) - *(s16 *)(p + 250)) * (s32)(((u16)(fn_1_A5DB0())) & 0xFFFF));
    *(u16 *)(p + 254) = (s32)(v8 / lbl_1_rodata_31E8);
    v9 = *(s16 *)(p + 252);
    if ((v9 % 8) > 0) {
        *(u16 *)(p + 252) = fn_1_76704_operand_((8), ((v9 / 8 + 1)));
    }
    v11 = *(s16 *)(p + 254);
    if ((v11 % 8) > 0) {
        *(u16 *)(p + 254) = fn_1_76704_operand((8), ((v11 / 8 + 1)));
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
#pragma opt_dead_assignments reset

#pragma opt_propagation reset
/* fzgx:end fn_1_76704 */

/* fzgx:begin fn_1_76964 */
typedef struct {
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

/* fzgx:begin fn_1_769FC */
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

typedef struct {
    u8 pad_0[5];
    u8 unk_5;
    u8 pad_6[0x102];
} Obj_1_data_1D9B8;
extern Obj_1_data_1D9B8 lbl_1_data_1D9B8;
typedef struct {
    u8 pad_0[4];
    u32 unk_4;
    u8 pad_8[0x50];
} Obj_1_data_1D960;
extern Obj_1_data_1D960 lbl_1_data_1D960;
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
void fn_1_76A94(struct fn_1_76A94_Obj *obj, u32 arg1) {
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

/* fzgx:begin fn_1_76BD0 */
void fn_1_76BD0(u8 index, u8 value) {
    Obj_1_bss_6C8EC *obj =
        (Obj_1_bss_6C8EC *)((u8 *)&lbl_1_bss_6C8EC + index * 0x10c);

    if ((s32)obj->unk_DC != 0) {
        obj->unk_108 = value;
    }
}
/* fzgx:end fn_1_76BD0 */

/* fzgx:begin fn_1_76BF8 */
extern void fn_1_76C60(void);

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

/* fzgx:begin fn_1_76C60 */
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

/* fzgx:begin fn_1_76DBC */
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

/* begin game/main_rel/screen_effect_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_SCREEN_EFFECT_TYPES_H
#define GAME_MAIN_REL_SCREEN_EFFECT_TYPES_H

// Types (and the externs that name them) of screen_effect.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


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

typedef struct {
    u8 pad_0[0xdc];
    u32 unk_dc;
} Fn_1_72980_Obj;

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

typedef struct {
    u8 unk00[0x2c];
    f32 value;
} GlobalData;

struct fn_1_761B8_Arg0 {
    u8 pad_0[0xE0];
    u32 unk_E0;
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
} FnScreenEffect;

struct Sig_fn_8004E278_fn_8004E278_Arg0 {
    u32 unk_0;
};

struct fn_1_76448_Arg0 {
    u8 pad_0[0xA0];
    u32 unk_A0[1];
    u8 pad_A4[0x38];
    u32 unk_DC;
    u8 pad_E0[0x18];
    s16 unk_F8;
};

typedef u8 Sig_GXGetTexBufferSize_GXBool;

typedef struct {
    u32 flags;
    s32 count;
    void *nodes;
} EffectManager;

/* begin game/vec3.h (deltawave784/fzgx, CC0) */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,
// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,
// stcoli). Hand-owned (librarian).


typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

#endif  // GAME_VEC3_H

/* end game/vec3.h */

extern s32 fn_1_79C88(EffectManager *manager, u32 *out, s32 reverse, f32 value);
extern void fn_1_76650(fn_1_76650_ScreenEffect *effect);
extern void fn_1_72980(Fn_1_72980_Obj *arg0);
extern void *fn_1_729F8(struct fn_1_729F8_Arg0 *arg0);
extern void fn_1_761B8(struct fn_1_761B8_Arg0 *arg0, u32 arg1);
extern void DCInvalidateRange(struct Sig_fn_8004E278_fn_8004E278_Arg0 *, u32);
extern void fn_1_76448(struct fn_1_76448_Arg0 *arg0, u32 arg1);
extern u32 GXGetTexBufferSize(u16, u16, u32, Sig_GXGetTexBufferSize_GXBool, u8);

#endif  // GAME_MAIN_REL_SCREEN_EFFECT_TYPES_H

/* end game/main_rel/screen_effect_types.h */

struct Arg0 {
    u8 pad_0[0xA0];
    u32 img[1];
    u8 pad_A4[0x38];
    u32 idx;
    u8 pad_E0[0x20];
    s16 w;
    s16 h;
};
extern const f64 lbl_1_rodata_31A0;
extern void GXInitTexObj(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, int arg5, int arg6, int arg7);
extern void GXInitTexObjLOD(u32 arg0, int arg1, int arg2, int arg3, int arg4, int arg5, f32 arg6, f32 arg7, f32 arg8);
extern u16 fn_1_A5D9C(void);
extern void fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void fn_80038F10(f32* out);
extern void fn_800720B0(u32);
extern void fn_8007245C(u32 value);
extern void fn_800724C8(void);
extern void fn_80072864(u32 arg0);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_800735C8(s32 index, s32 value);
extern void fn_80073620(s32 index, s32 value);
extern void fn_80073678(u32 arg0);
extern void fn_800736C0(u32, void *);
extern void fn_80073898(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5);
extern void fn_80074660(u32 arg0);
extern void fn_80074788(u32 arg0);
extern void fzgx_pool_sink_p(void *);
extern void fzgx_pool_sink_f(f32);
extern void fn_1_7A648(void *arg0);
extern void fn_1_5616C(s32 value, f32 value1, f32 value2);
extern void fn_1_556F8(void *);
extern u32 fn_1_56018(s32 value);
extern void fn_1_55FC4(f32 value);
extern void fn_1_5575C(void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006DFE8(void *);
extern void fn_80072558(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006E0A4(void *);
extern void mathutil_mtxA_rotate_z(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void lbl_8006E13C(void *);
extern void lbl_8006DC20(void);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 fn_800356B8(void *, u32);
extern u8 lbl_1_data_1E558__fzgx_offset_0[];
extern u8 lbl_1_data_1E58C__fzgx_offset_0[];
extern u8 lbl_1_data_1E5F4__fzgx_offset_0[];
extern u8 lbl_1_data_1E628__fzgx_offset_0[];
extern u8 lbl_1_data_1E65C__fzgx_offset_0[];
extern u8 lbl_1_data_1E690__fzgx_offset_0[];
extern u8 lbl_1_data_1E6C4__fzgx_offset_0[];
extern u8 lbl_1_data_1E6F8__fzgx_offset_0[];
extern u8 lbl_1_data_1E72C__fzgx_offset_0[];
extern u8 lbl_1_data_1E760__fzgx_offset_0[];
extern u8 lbl_1_data_1E794__fzgx_offset_0[];
extern u8 lbl_1_data_1E7C8__fzgx_offset_0[];
extern u8 lbl_1_data_1E7FC__fzgx_offset_0[];
extern u8 lbl_1_data_1E830__fzgx_offset_0[];
extern u8 lbl_1_data_1E864__fzgx_offset_0[];
extern u8 lbl_1_data_1E898__fzgx_offset_0[];
extern u8 lbl_1_data_1E8CC__fzgx_offset_0[];
extern u8 lbl_1_data_1E900__fzgx_offset_0[];
extern u8 lbl_1_data_1E934__fzgx_offset_0[];
extern u8 lbl_1_data_1EA70__fzgx_offset_0[];
extern u8 lbl_1_data_1EAA4__fzgx_offset_0[];
extern u8 lbl_1_data_1EAD8__fzgx_offset_0[];
extern u8 lbl_1_data_1EB0C__fzgx_offset_0[];
extern u8 lbl_1_data_1EB40__fzgx_offset_0[];
extern u8 lbl_1_data_1EB74__fzgx_offset_0[];
extern u8 lbl_1_data_1EBA8__fzgx_offset_0[];
extern u8 lbl_1_data_1EBDC__fzgx_offset_0[];
extern u8 lbl_1_data_1EC10__fzgx_offset_0[];
extern u8 lbl_1_data_1EC44__fzgx_offset_0[];
extern u8 lbl_1_data_1EC78__fzgx_offset_0[];
extern u8 lbl_1_data_1ECAC__fzgx_offset_0[];
extern u8 lbl_1_data_1ECE0__fzgx_offset_0[];
extern u8 lbl_1_data_1ED14__fzgx_offset_0[];
extern u16 fn_1_A5DB0(void);
extern u32 fn_800384FC(u32, u32);
extern void fzgx_pool_sink_d(f64);
extern u32 fn_800793D4(u8 *arg0, u32 arg1, u32 arg2);
extern f32 *lbl_801A6D00;
extern u32 lbl_801A66A0;
extern void fn_1_75D84(void *, void *, void *);
extern void fn_1_76C60();
extern void fn_1_76EB8(void);
extern void fn_1_77200();
extern u32 fn_1_77C5C(void *, void *, void *);
extern u32 fn_1_4E220(void *, u32, u32, u32, u32);
extern void lbl_8006D758(void);
extern void lbl_8006D784(f32 *arg);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void fn_800371F8(u32, void *);
extern void fn_8003726C(u32, void *);
extern void fn_80072808(void);
extern void fn_800729B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072EDC(s32 arg0, s32 arg1);
extern void fn_80073778(void *obj, s32 index);
extern void fn_800738E0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_800739E0(s32 index, s32 arg1, s32 arg2);
extern void fn_80073A58(int index, void *arg, s8 value);
extern void fn_80073D60(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void GXLoadTexMtxImm(f32 *arg0, int arg1, int arg2);
extern void GXSetAlphaCompare(s32, s32, s32, s32, s32);
extern const f32 lbl_1_rodata_31A8;
extern const f64 lbl_1_rodata_31D8;
extern u32 fn_1_7880C(void);
extern u32 fn_1_788B0(void);
extern void GXInvalidateTexAll(void);
extern const f32 lbl_1_rodata_31E8;
extern u32 lbl_1_bss_6D1A8[278];
extern u32 fn_80036104(void);
extern u32 GXGetTexObjHeight(u32 arg0);
extern u32 GXGetTexObjWidth(u32 arg0);
extern u32 fn_800360D8(u32 arg0);
extern const f32 lbl_1_rodata_323C;
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void lbl_8006DB74(void *arg);
extern void lbl_8006E0C8(void *arg);
extern f32 lbl_1_rodata_3278[20];
extern f32 fn_1_A71AC(void);
extern s16 fn_1_12EF24(s16 row, s16 column);
extern int sprintf(char *s, const char *format, ...);
extern void fn_1_465D0(char *text, s32 mode);
extern u32 lbl_1_bss_6C8DC[2];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_727BC();
extern void fn_1_76A94(struct Arg0 *arg0, u32 arg1);
extern void fn_1_76DBC(void);
extern void fn_1_4E500(void);
extern void fn_1_4E638(s32 arg);
extern void fn_1_4E6F4(void);
extern const f32 lbl_1_rodata_31AC;
extern u32 fn_80008E84(u32 arg0);
extern void fn_1_77238(void);
extern void fn_1_772E0(void);
extern void fn_1_77384(void *arg);
extern f32 lbl_1_rodata_31B0[10];
extern s32 fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8006FD1C(void);
extern void fn_1_79810(void);
extern void fn_1_79948(void);
extern void fn_1_791B0(void);
extern void fn_1_9A1E8(void);
extern void fn_1_9A864(void);
extern u8 fn_1_7B074(void);
extern void fn_80071718(void *);
extern void fn_800711A8(void *);
extern void fn_1_14CB4(void);
extern void fn_1_FA84(void);
extern const f32 lbl_1_rodata_32CC;
extern void lbl_8006DBAC(void *arg0);
extern void fn_1_14D5C(char *arg0, int arg1);
extern void fn_1_46EA8(u32 value);
extern void fn_1_12620(s32 arg0);
extern s32 fn_1_46DC4(s32 value);
extern u32 fn_8003526C(u32, u32);
extern void fn_80074300();
extern void fn_80074438(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern f32 lbl_1_rodata_31EC;
extern u32 lbl_801A63C0;
extern s32 camera_get_state(void);
extern u8 fn_1_5348(void);
extern s32 fn_1_58C4(void);
extern void fn_1_550A8(void);
extern u32 fn_1_7926C(u32);
extern f64 fn_1_550E0(void);
extern void lbl_8006DD14(void *, void *);
extern void fn_80038FD8(s32 *, s32 *, s32 *, s32 *);
extern void fn_80038BFC(f32* out);
extern void fn_80072270(f32 *, f64);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);

struct S {
    u8 pad_0[0x13C];
    u32 unk_13C[5];
    u8 unk_150[4];
    f32 unk_154;
    f32 unk_158;
};

static u32 fzgx_pool_native_lbl_1_data_1D960_gap_0[79] = {0x00000001, 0x00000011, 0x00000001, 0x00000039, 0x00000001, 0x0000003A, 0x00000003, 0x00000003, 0x00000001, 0x00000001, 0x00000003, 0x00000013, 0x00000005, 0x00000005, 0x00000000, 0x00000000, 0x00000003, 0x00000003, 0x00000006, 0x00000006, 0x00000001, 0x00000027, 0x00000000, 0x00000600, 0x00000001, 0x06000000, 0x00010600, 0x00000001, 0x06000000, 0x00010600, 0x00000001, 0x06000000, 0x00010600, 0x00000001, 0x06060000, 0x00020606, 0x00000002, 0x06060000, 0x00020606, 0x00000002, 0x00010600, 0x00030001, 0x06000003, 0x00010600, 0x00030001, 0x06030004, 0x00000000, 0x00010406, 0x00000002, 0x04060000, 0x00020406, 0x00000002, 0x04060000, 0x00020406, 0x00000002, 0x04060000, 0x00020406, 0x00000002, 0x04060000, 0x00020606, 0x00000002, 0x06030000, 0x00020603, 0x00000002, 0x05000000, 0x00010600, 0x00000001, 0x05040000, 0x00020900, 0x00000001, 0x04080000, 0x00020400, 0x00000001, 0x01010600, 0x00030600, 0x00000001, 0x00010700, 0x00030400, 0x00000001}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_1D960_unk_13C[5] = {0x30506020, 0x38623420, 0x60605040, 0x60505030, 0x70504020}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_1_data_1D960_unk_150[4] = {0x30, 0x50, 0x60, 0x20}; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_1D960_unk_154 = 1.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_1D960_unk_158 = 1.0f; /* fzgx-allow: A1 measured pool bytes and bindings */

void fn_1_76DC0(s32 arg0) {
    
    if (arg0 == 17) {
        u32 v;
        u32 r;
        r = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        v = (r >> 16) & 0x7FFF;
        lbl_801A63C0 = r;
        *(u32 *)fzgx_pool_native_lbl_1_data_1D960_unk_150 = fzgx_pool_native_lbl_1_data_1D960_unk_13C[v % 5];
        arg0 = 23;
    } else if (arg0 >= 18 && arg0 < 23) {
        u32 v = arg0 - 18;
        *(u32 *)fzgx_pool_native_lbl_1_data_1D960_unk_150 = fzgx_pool_native_lbl_1_data_1D960_unk_13C[v % 5];
        arg0 = 23;
    }
    if (arg0 == 23) {
        fzgx_pool_native_lbl_1_data_1D960_unk_154 = (*(f32 *)&lbl_1_rodata_31AC);
        fzgx_pool_native_lbl_1_data_1D960_unk_158 = (*(f32 *)&lbl_1_rodata_31AC);
    }
    if (arg0 != 24) return;
    fzgx_pool_native_lbl_1_data_1D960_unk_150[0] = 48;
    fzgx_pool_native_lbl_1_data_1D960_unk_154 = lbl_1_rodata_31EC;
    fzgx_pool_native_lbl_1_data_1D960_unk_158 = lbl_1_rodata_31EC;
    fzgx_pool_native_lbl_1_data_1D960_unk_150[1] = 48;
    fzgx_pool_native_lbl_1_data_1D960_unk_150[2] = 40;
    fzgx_pool_native_lbl_1_data_1D960_unk_150[3] = 32;
}
/* fzgx:end fn_1_76DC0 */

/* fzgx:begin fn_1_76EB8 noprologue */
#include "types.h"
#include "rel/main_rel/screen_effect.h"

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
}
#pragma section code_type ".text"
struct EffectTail { u32 unk_150; f32 unk_154; f32 unk_158; };
extern u16 fn_1_A5D9C(void);
extern u32 fn_80038EEC(f32,f32,f32,f32,f32,f32);
extern void fn_8003462C(u32,u32,u32);
extern void fn_80038F10(f32 *);
extern void fn_800720B0(u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32,s32,s32,s32);
extern void fn_80072AB0(s32,s32,s32);
extern void fn_80072C24(s32,s32,s32,s32,s32);
extern void fn_80072CC4(s32,s32,s32,s32,s32);
extern void fn_80072D64(s32,s32,s32,s32,u8,s32);
extern void fn_80072E20(s32,s32,s32,s32,u8,s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800735C8(s32,s32);
extern void fn_80073620(s32,s32);
extern void fn_80073678(u32);
extern void fn_800736C0(u32,void *);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32,s32,s32,u32,u32,u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
#pragma opt_dead_assignments on
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
    v1 = (f32)(v0 * ((struct EffectTail *)((u8 *)p_lbl_1_data_1D960 + 0x150))->unk_154);
    v2 = (f32)(v0 * ((struct EffectTail *)((u8 *)p_lbl_1_data_1D960 + 0x150))->unk_158);
    v3 = (f32)(v0-v1);
    v4 = (f32)(v0-v2);
    v5 = (f32)(v0+v1);
    v6 = (f32)(v0+v2);
    fn_80038F10((f32 *)&loc_C);
    t29 = fn_1_A5D9C();
    v7 = (t29 & 0xFFFF);
    v8 = 0.0f;
    fn_80038EEC(v8,v8,640.0f,(f32)(u32)v7,v8,1.0f);
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
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_76EB8 */

/* fzgx:begin fn_1_77200 */
void fn_1_77200(void *arg) {
    fn_1_77238();
    fn_1_772E0();
    fn_1_77384(arg);
}
/* fzgx:end fn_1_77200 */

/* fzgx:begin fn_1_77238 */
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

/* fzgx:begin fn_1_772E0 */
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
    values[5] = *(const f32 *)&lbl_1_rodata_31A0;
    fn_80073A58(1, values, 1);
    fn_800739E0(0, 0, 0);
    lbl_8006D784(second);
    GXLoadTexMtxImm(second, 30, 1);
}
/* fzgx:end fn_1_772E0 */

/* fzgx:begin fn_1_77B80 noprologue */
#include "types.h"

extern u32 lbl_1_bss_6D1A8[278];
extern const f32 lbl_1_rodata_31A0;

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

/* fzgx:begin fn_1_7879C */
extern const f32 lbl_1_rodata_323C;
extern const f64 lbl_1_rodata_31D8;

u8 fn_1_7879C(u32 arg0) {
    s32 v0;

    v0 = (s32)(lbl_1_rodata_323C * (f32)(s32)((arg0 - 0x1000000) + 2048));
    return (u8)(v0 < 0 ? 0 : (v0 <= 255 ? v0 : 0xff));
}
/* fzgx:end fn_1_7879C */

/* fzgx:begin fn_1_7880C noprologue */
#include "dolphin/types.h"

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
    f32 x, y, z;
} Vec3;

extern void fn_80072864(u32);
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

/* fzgx:begin fn_1_788B0 noprologue */
#include "dolphin/types.h"

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
static const u32 fzgx_pool_table5[6] = {0x00000000, 0x00000000, 0x00000000, 0x41A00000, 0x41A00000, 0x41A00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
}
#pragma section code_type ".text"

typedef struct { f32 x, y, z; } Vec3;
extern void fn_80072864(u32);
extern u32 lbl_8006DCA4(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E13C(void *);
extern void fn_80072558(void);
extern u32 fn_800384FC(u32, u32);

#pragma peephole on
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
#pragma peephole reset
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

/* fzgx:begin fn_1_789E8 noprologue */
#include "types.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
#include "types.h"
#include "rel/main_rel/screen_effect.h"

/* begin game/main_rel/car_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_CAR_TYPES_H
#define GAME_MAIN_REL_CAR_TYPES_H

// Types (and the externs that name them) of car.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    u8 pad0[0x1c];
    void *field_1c;
} CarObject;

typedef struct {
    u8 pad0[0x12];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    void *field_28;
    u8 pad2c[0x8];
    void *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} EventNode;

typedef struct {
    u8 pad0[0x24];
    void *field_24;
} EventData;

typedef struct {
    u8 pad0[0x8];
    EventData *field_8;
    void *field_c;
} EventObject;

struct fn_1_7F954_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_7FA04_lbl_801A6410 {
    u32 unk_0;
};

typedef struct {
    u8 pad0[0x40];
    void *value;
} ResourceHolder;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} RawVec3;

/* begin game/vec3.h (deltawave784/fzgx, CC0) */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,
// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,
// stcoli). Hand-owned (librarian).


typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

#endif  // GAME_VEC3_H

/* end game/vec3.h */

typedef struct {
    u8 _pad_000[0x7c];
    Vec3 field_07c;
    u8 _pad_088[0xc4];
    Vec3 field_14c;
} Fn184644Object;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Triple;

typedef struct Fn195158Object Fn195158Object;

struct Fn195158Object {
    u8 unk_00[0x0C];
    f32 unk_0C;
    u8 unk_10[0x1C];
    f32 unk_2C;
    u8 unk_30[0x58];
    u8 unk_88[0x04];
};

struct TargetObj {
    char pad[0x60];
    char field_0x60[0xc];
    f32 field_0x6c;
    char pad2[0xc];
    f32 field_0x7c;
};

struct ModelItem {
    u32 flags;
    char pad[0x1c];
};

struct Model {
    char pad[0x18];
    u16 count;
    char pad2[0x26];
    struct ModelItem items[1];
};

typedef struct {
    u32 entries[41];
} FnTable;

typedef struct {
    u8 pad_0[0x4];
    s32 field_4;
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
} Fn1_8F45C_Object;

typedef struct {
    s32 active;
    s32 entries[5];
} Fn1_8F494_Object;

typedef struct {
    u8 pad_0[0x148];
    u8 pad_148[0x20];
    u8 pad_168[0x40];
    u8 pad_1a8[0x20];
    u8 pad_1c8[0x20];
    u8 pad_1e8[0x20];
    u8 entries[0x14][0x20];
} Fn1_8F5A4_Object;

typedef struct Fn195158Data Fn195158Data;

struct Fn195158Data {
    u8 unk_00[0x08];
    Fn195158Object *unk_08;
};

typedef struct Fn195158Car Fn195158Car;

struct Fn195158Car {
    u8 unk_00[0xA0];
    s16 unk_A0;
    s16 unk_A2;
    s16 unk_A4;
    u8 unk_A6[0x02];
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
    f32 unk_B8;
    u8 unk_BC[0x94];
    Fn195158Data *unk_150;
};

typedef struct Fn935E4Slot {
    u8 pad0[0xa];
    u16 field_a;
} Fn935E4Slot;

typedef struct Fn935E4Node {
    u8 pad0[0xa];
    u16 field_a;
    u8 pad_c[6];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    u8 pad27[1];
    Fn935E4Slot *field_28;
    u8 pad2c[8];
    Fn935E4Slot *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} Fn935E4Node;

typedef struct {
    u8 pad0[0x12];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    void *field_28;
    u8 pad2c[8];
    void *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} Node;

typedef struct Fn935E4Car {
    u8 pad0[0x1c];
    Fn935E4Node *field_1c;
} Fn935E4Car;

typedef struct {
    u8 pad0[0x24];
    void *field_24;
    f32 field_28;
    f32 field_2c;
} OutData;

typedef struct {
    u8 pad0[0x1c];
    Node *field_1c;
    u8 pad20[0x128];
    u16 field_148;
    u8 pad14a[6];
    OutData *field_150;
    void *field_154;
} Owner;

typedef struct Fn1967A8Resource Fn1967A8Resource;

struct Fn1967A8Resource {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};

typedef struct Fn196968Object Fn196968Object;

struct Fn196968Object {
    u8 unk_00[0x28];
    u32 unk_28;
    u8 unk_2C[0x144];
    void *unk_170;
    void *unk_174;
};

typedef struct Fn1969E8Owner Fn1969E8Owner;

struct Fn1969E8Owner {
    u8 unk_00[0x2C];
    u32 unk_2c;
    u8 unk_30[0x180];
    u32 unk_1b0;
    void *unk_1b4;
};

typedef struct Fn196BC0Object Fn196BC0Object;

struct Fn196BC0Object {
    u8 unk_00[0x30];
    void *value_30;
    u8 unk_34[0x19C];
    void *resource_1D0;
    void *resource_1D4;
};

typedef struct Fn196A68Object Fn196A68Object;

struct Fn196A68Object {
    u8 unk_00[0x34];
    u32 unk_34;
    u8 unk_38[0x1B8];
    void *unk_1F0;
    void *unk_1F4;
};

typedef struct CarR29 {
    u8 unk_00[0x14];
    f32 unk_14;
} CarR29;

/* game/vec3.h: inlined above */

typedef struct fn_1_8D210_car {
    f32 position[6];
    f32 scale_z;
    f32 scale_y;
    f32 scale_x;
    f32 field_24;
    u16 field_28;
    u16 field_2a;
    u16 field_2c;
    u16 field_2e;
    u16 field_30;
    u16 field_32;
    u32 field_34;
    u8 field_38;
    u8 field_39;
    u8 field_3a;
    u8 pad_3b;
    u32 field_3c;
    u8 field_40;
    u8 pad_41[3];
    f32 field_44;
    f32 field_48;
    f32 field_4c;
    f32 field_50;
    s16 field_54;
    u8 pad_56[2];
    s32 field_58;
    u8 field_5c[4];
    u32 field_60;
} fn_1_8D210_car;

typedef s32 (*fn_1_8D210_callback)(u32);

typedef struct {
    u8 pad[0x15];
    u8 code;
} State;

typedef struct {
    u8 pad[4];
    State *state;
} fn_1_8E3A4_Object;

typedef struct {
    u8 pad_0[0x400];
    u8 mtx[0x70];
    u8 mtx2[0x30];
} CamObj;

typedef struct {
    u8 pad_0[0x118];
    u32 unk_118;
    u32 unk_11C;
    u8 pad_120[0x20];
    s32 unk_140;
    f32 unk_144;
    f32 unk_148;
    f32 unk_14C;
    f32 unk_150;
} CarSound;

typedef struct {
    u32 flags;
    u8 pad_4[0x498];
    CarSound *sound;
} fn_1_85F90_Car;

extern s32 fn_1_8D210(fn_1_8D210_car *car, fn_1_8D210_callback callback, u32 arg, s32 enable);
extern void fn_1_95158(Fn195158Car *car);
extern s32 fn_1_97174(EventNode *arg0, s32 arg1, void *arg2);
extern void fn_1_93734(CarObject *arg0, void *arg1);
extern Fn1967A8Resource *fn_1_41518(void *arg0);
extern void fn_1_41C18(Fn1967A8Resource *arg0, void *arg1);
extern void fn_1_41F58(Fn1967A8Resource *arg0, s32 arg1, void (*arg2)(void), void *arg3);
extern u16 fn_1_96968(Fn196968Object *object, void *arg1);
extern u16 fn_1_969E8(Fn1969E8Owner *owner, void *arg1);
extern u16 fn_1_96BC0(Fn196BC0Object *object, void *arg1);
extern u16 fn_1_96A68(Fn196A68Object *object, void *arg1);
extern CarR29 *fn_80071268(void *, void *);
extern void lbl_8006E1F0(Vec3f *, f32, f32, f32);
extern void lbl_8006E2C0(Vec3f *, f32, f32, f32);
extern void fn_8006E250(Vec3f *, Vec3f *);
extern void fn_1_B81C(Vec3f *, Vec3f *, s32);
extern void lbl_8006DBAC(Vec3 *a);
extern void fn_1_8E3A4(fn_1_8E3A4_Object *obj);
extern f32 lbl_8006D534(Vec3 *a, Vec3 *b);
extern Triple lbl_1_rodata_3BE8;
extern void fn_1_55210(struct Model *);
/* retail takes (obj, idx, mask, mask2) (fn_1_8F198 passes all four); non-prototype until fn_1_8F45C passes its own four through */
extern void fn_1_8E7D0();
extern void fn_1_966A0(Fn1_8F494_Object *obj);
extern void fn_1_8F5A4(Fn1_8F5A4_Object *obj);
extern void fn_1_968FC(Fn1_8F5A4_Object *obj);
extern void fn_1_943F8(Fn935E4Car *, f32, void *);

#endif  // GAME_MAIN_REL_CAR_TYPES_H

/* end game/main_rel/car_types.h */
/* game/vec3.h: inlined above */

/* Colour/intensity key of one fade channel. */
typedef struct {
    s8 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    s8 unk_F;
    s32 unk_10;
} ScreenFadeKey;

/* A key plus the preset it is heading to, interpolated over 32 frames. */
typedef struct ScreenFadeChannel {
    ScreenFadeKey key;
    struct ScreenFadeChannel *src;
} ScreenFadeChannel;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Obj_1_bss_6D600 fzgx_obj_lbl_1_bss_6D600;
static ScreenFadeChannel lbl_1_bss_6D620__fzgx_offset_0[4];
static ScreenFadeChannel lbl_1_bss_6D620__fzgx_offset_60[4];
static ScreenFadeChannel lbl_1_bss_6D620__fzgx_offset_C0[4];
static ScreenFadeChannel lbl_1_bss_6D620__fzgx_offset_120;
static ScreenFadeChannel lbl_1_bss_6D758__fzgx_offset_0;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D600;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_60;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_C0;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_120;
    s = *(u8 *)&lbl_1_bss_6D758__fzgx_offset_0;
}
#pragma section code_type ".text"

extern s16 fn_1_6B48(s32);
extern s32 fn_1_58C4(void);
extern s32 fn_1_6F84(void);
extern u32 fn_1_1FB80(Vec3f *, u32);
extern u32 fn_1_7A6B4(void);
extern u32 fn_1_7AA50(f32);
extern void fn_1_681C(u32, u32 *);
extern void fn_1_7A9B8(void);
extern void fn_1_862D4(int, Triple *);

#pragma push
#pragma opt_propagation off
static inline int fade_more(u32 channel, s32 *arg) {
    u32 count = fn_1_58C4();
    *arg = channel;
    return channel < count;
}
#pragma pop

void fn_1_789E8(void) {
    ScreenFadeChannel *cur;
    ScreenFadeChannel *prev;
    ScreenFadeChannel *next;
    u32 i;
    s32 idx;
    ScreenFadeChannel *src;
    f32 t;
    f32 s;
    Vec3f pos;

    if (lbl_1_data_1DFA4.unk_8 != -1) {
        lbl_1_data_1DFA4.unk_0 = (s32)lbl_1_data_1DFA4.unk_4;
        fn_1_7A6B4();
        fn_1_7A9B8();
        if (lbl_1_bss_3BE0 != NULL) {
            if (lbl_1_bss_3BE0->unk_80 != 0) {
                fn_1_7AA50(lbl_1_data_1DFA4.unk_0);
            }
            cur = lbl_1_bss_6D620__fzgx_offset_0;
            prev = lbl_1_bss_6D620__fzgx_offset_60;
            next = lbl_1_bss_6D620__fzgx_offset_C0;
            for (i = 0; fade_more(i, &idx); cur++, prev++, next++, i++) {
                idx = fn_1_6B48(idx);
                if (idx >= 0) {
                    if (fn_1_6F84() != 0) {
                        fn_1_681C((u8)i, (u32 *)&pos);
                    } else {
                        fn_1_862D4(idx, (Triple *)&pos);
                    }
                    if (fn_1_1FB80(&pos, 0x4000) & 0x4000) {
                        src = &lbl_1_bss_6D620__fzgx_offset_120;
                    } else {
                        src = &lbl_1_bss_6D758__fzgx_offset_0;
                    }
                } else {
                    src = &lbl_1_bss_6D758__fzgx_offset_0;
                }
                if (src != cur->src) {
                    prev->key = cur->key;
                    prev->src = cur->src;
                    *cur = *src;
                    *next = *src;
                    if (prev->key.unk_F == 0) {
                        prev->key.unk_0 = next->key.unk_0;
                        prev->key.unk_4 = next->key.unk_8;
                        prev->key.unk_8 = next->key.unk_8 + (next->key.unk_8 - next->key.unk_4);
                        prev->key.unk_C = next->key.unk_C;
                        prev->key.unk_D = next->key.unk_D;
                        prev->key.unk_E = next->key.unk_E;
                    }
                    if (next->key.unk_F == 0) {
                        next->key.unk_0 = prev->key.unk_0;
                        cur->key.unk_F = prev->key.unk_F;
                        next->key.unk_4 = prev->key.unk_8;
                        next->key.unk_8 = prev->key.unk_8 + (prev->key.unk_8 - prev->key.unk_4);
                        next->key.unk_C = prev->key.unk_C;
                        next->key.unk_D = prev->key.unk_D;
                        next->key.unk_E = prev->key.unk_E;
                    }
                    cur->src = src;
                    cur->key.unk_10 = (next->key.unk_0 == prev->key.unk_0) ? 0 : 32;
                }
                if (next->key.unk_F != 0) {
                    *next = *src;
                }
                src = cur->src;
                if (cur->key.unk_10 < 32) {
                    cur->key.unk_10++;
                } else {
                    cur->key.unk_F = src->key.unk_F;
                }
                t = cur->key.unk_10 / 32.0f;
                s = 1.0f - t;
                if (prev->key.unk_4 != next->key.unk_4) {
                    cur->key.unk_4 = (f32)(s * prev->key.unk_4) + (f32)(t * next->key.unk_4);
                } else {
                    cur->key.unk_4 = next->key.unk_4;
                }
                if (prev->key.unk_8 != next->key.unk_8) {
                    cur->key.unk_8 = (f32)(s * prev->key.unk_8) + (f32)(t * next->key.unk_8);
                } else {
                    cur->key.unk_8 = next->key.unk_8;
                }
                if (prev->key.unk_C != next->key.unk_C) {
                    cur->key.unk_C = (f32)(s * prev->key.unk_C) + (f32)(t * next->key.unk_C);
                } else {
                    cur->key.unk_C = next->key.unk_C;
                }
                if (prev->key.unk_D != next->key.unk_D) {
                    cur->key.unk_D = (f32)(s * prev->key.unk_D) + (f32)(t * next->key.unk_D);
                } else {
                    cur->key.unk_D = next->key.unk_D;
                }
                if (prev->key.unk_E != next->key.unk_E) {
                    cur->key.unk_E = (f32)(s * prev->key.unk_E) + (f32)(t * next->key.unk_E);
                } else {
                    cur->key.unk_E = next->key.unk_E;
                }
            }
        }
        lbl_1_data_1DFA4.unk_4++;
    }
}
/* fzgx:end fn_1_789E8 */

/* fzgx:begin fn_1_78EBC noprologue */
#include "types.h"
#include "rel/main_rel/screen_effect.h"

typedef struct { u32 flags; s32 count; void *nodes; } Sig_fn_1_79C88_EffectManager;
typedef struct { u8 unk_00[8]; u32 unk_08,unk_0C,unk_10; f32 unk_14; } Sig_fn_1_556F8_Fn1_556F8Object;
typedef Sig_fn_1_556F8_Fn1_556F8Object Sig_fn_1_5575C_Fn1_5575CObject;
typedef struct { u8 pad[0xD4]; u32 count; u8 pad2[0x4b0-0xD8]; } Rec_D4;
extern f32 lbl_1_rodata_32E0;
extern s32 fn_1_79C88(Sig_fn_1_79C88_EffectManager *, u32 *, s32, f32);
extern u32 fn_1_56018(s32);
extern u32 fn_1_7A648(Sig_fn_1_79C88_EffectManager *);
extern u32 lbl_8006DAEC(void);
extern u32 lbl_8006DBE4(void);
extern u32 lbl_8006DCA4(void);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void fn_1_556F8(Sig_fn_1_556F8_Fn1_556F8Object *);
extern void fn_1_5575C(Sig_fn_1_5575C_Fn1_5575CObject *);
extern void fn_1_55FC4(f32);
extern void fn_1_5616C(s32,f32,f32);
extern void fn_80072558(void);
extern void lbl_8006DC20(void);
extern void lbl_8006DFE8(u32);
extern void lbl_8006E0A4(u32);
extern void lbl_8006E13C(void *);
extern u32 mathutil_mtxA_rotate_z(u32);
void fn_1_78EBC(void) {
    Obj_1_bss_3BE0_Target **v0;
    u8 *v13;
    u32 v4;
    u32 v3;
    u8 *v1;
    u32 v11;
    u32 *v10;
    u8 *v18;
    Obj_1_data_2A7E0 *v2;
    u32 v14;
    struct { u32 value; } v19;
    f32 v6,v16,v20;
    if(lbl_1_data_1DFA4.unk_8 != -1) {
        v0=&lbl_1_bss_3BE0;
        if(*v0) {
            v1=(u8 *)(*v0)->unk_1C;
            v3=*(u32 *)&lbl_1_bss_3BE4;
            v2=&lbl_1_data_2A7E0;
            v4=0;
            while(v4 < (*v0)->unk_18) {
                if(v4==0) lbl_8006DCA4();
                else lbl_8006DFE8(v3+44);
                fn_80072558();
                v10=*(u32 **)(v1+224);
                v11=0;
                while(v11 < *(u32 *)(v1+220)) {
                    v14=fn_1_7A648((Sig_fn_1_79C88_EffectManager *)*v10);
                    if(v14) {
                        if(*(u32 *)(v1+272) || *(u32 *)(v1+276) || *(u32 *)(v1+280) || *(u32 *)(v1+284)) {
                            v20=lbl_1_rodata_32E0;
{
    s32 v12;
                            v13=v1; v12=0;
                            do {
                                f32 *v15=*(f32 **)(v13+272);
                                if(v15) {
                                    v16=v20*v2->unk_1C;
                                    fn_1_5616C(v12,v15[0]*v16,v15[1]*v16);
                                }
                                v12++; v13+=4;
                            }while(v12<4);
}
                            fn_1_556F8((Sig_fn_1_556F8_Fn1_556F8Object *)v14);
                            fn_1_56018(0);
                        } else fn_1_556F8((Sig_fn_1_556F8_Fn1_556F8Object *)v14);
                    }
                    v11++; v10++;
                }
                v18=*(u8 **)(((u8 *)(*v0)->unk_1C + 216) + v4*1200);
                lbl_8006DAEC();
                v19.value=0;
                while(v19.value < ((Rec_D4 *)(*v0)->unk_1C)[v4].count) {
                    lbl_8006DBE4();
                    lbl_8006E0A4((u32)(v18+4));
                    mathutil_mtxA_rotate_z(*(s16 *)(v18+20));
                    mathutil_mtxA_rotate_y(*(s16 *)(v18+18));
                    mathutil_mtxA_rotate_x(*(s16 *)(v18+16));
                    lbl_8006E13C(v18+24);
                    v6=*(f32 *)(v18+24)>*(f32 *)(v18+28)?*(f32 *)(v18+24):*(f32 *)(v18+28);
                    v20=*(f32 *)(v18+32)>v6?*(f32 *)(v18+32):v6;
                    fn_1_55FC4(v20);
                    {u32 v8=fn_1_79C88(*(Sig_fn_1_79C88_EffectManager **)v18,0,0,v20);
                    if(v8) fn_1_5575C((Sig_fn_1_5575C_Fn1_5575CObject *)v8);}
                    v19.value++; v18+=36;
                }
                lbl_8006DC20();
                v4++; v3+=160; v1+=1200;
            }
        }
    }
}
/* fzgx:end fn_1_78EBC */

/* fzgx:begin fn_1_79100 */
// Release the active screen-effect resources and reset the effect state.
void fn_1_79100(void) {
    fn_1_9A864();

    if (!fn_1_7B074()) {
        if (lbl_1_bss_6D770 != 0 || lbl_1_bss_6D774 != 0) {
            fn_8006FDEC();
        }

        if (lbl_1_bss_6D770 != 0) {
            fn_80071718((void *)lbl_1_bss_6D770);
            lbl_1_bss_6D770 = 0;
        }

        if (lbl_1_bss_6D774 != 0) {
            fn_800711A8((void *)lbl_1_bss_6D774);
            lbl_1_bss_6D774 = 0;
        }
    }

    fn_1_14CB4();
    fn_1_FA84();
    lbl_1_data_1DFA4.unk_8 = -1;
}
/* fzgx:end fn_1_79100 */

/* fzgx:begin fn_1_791B0 */
typedef struct {
    Obj_1_bss_6D778_At0 *unk_0;
    const u8 *unk_4;
} ScreenEffectEntry;

typedef struct {
    s32 count;
    u8 pad_4[0x4];
    ScreenEffectEntry *entries;
} ScreenEffectTable;

static inline ScreenEffectEntry *fn_1_791B0_array_read(ScreenEffectEntry *array) { return array; }
#pragma opt_common_subs off
void fn_1_791B0(void) {
    struct { s32 value; } i;
    ScreenEffectTable *table;

    lbl_1_bss_6D778.unk_0 = 0;
    if (lbl_1_data_1DFA4.unk_8 < 0) {
        return;
    }

    table = (ScreenEffectTable *)lbl_1_bss_6D774;
    if (table == 0) {
        return;
    }

    for (i.value = 0; i.value < table->count; i.value++) {
        if (fn_1_791B0_array_read(table->entries)[i.value].unk_4[0] == 'C' &&
            fn_1_791B0_array_read(table->entries)[i.value].unk_4[3] == '_' &&
            fn_1_791B0_array_read(table->entries)[i.value].unk_4[4] == 'M' &&
            fn_1_791B0_array_read(table->entries)[i.value].unk_4[5] == 'A' &&
            fn_1_791B0_array_read(table->entries)[i.value].unk_4[6] == 'P' &&
            fn_1_791B0_array_read(table->entries)[i.value].unk_4[7] == '\0') {
            lbl_1_bss_6D778.unk_0 = fn_1_791B0_array_read(table->entries)[i.value].unk_0;
            return;
        }
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_791B0 */

/* fzgx:begin fn_1_7926C noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/screen_effect.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x04050000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -200.0f;
    s = 1000.0f;
}
static const u32 fzgx_pool_table3[3] = {0x006E9600, 0x08050000, 0xC3480000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2000.0f;
}
static const u32 fzgx_pool_table5[3] = {0x0A0A2800, 0x07040000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3000.0f;
}
static const u32 fzgx_pool_table7[3] = {0x171A1D00, 0x0C020000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 820.0f;
}
static const u32 fzgx_pool_table9[3] = {0x6E787900, 0xFF040000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
}
static const u32 fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.03125f;
    s = 1.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 0.01666666753590107f;
}
static const u32 fzgx_pool_table13[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 640.0f;
    s = 480.0f;
    s = 320.0f;
    s = 240.0f;
    s = 0.029999999329447746f;
    s = 0.75f;
    s = 0.019999999552965164f;
    s = 1.5f;
    s = 360.0f;
    s = 128.0f;
    s = 0.5f;
    s = 8.0f;
    s = 408.0f;
}
#pragma section code_type ".text"

typedef struct Sig_fn_80036070_Fn80036070Data {
    u32 flags;
    u8 pad_04[4];
    u32 dimensions;
    u32 scaled_value;
    u8 pad_10[4];
    u32 value_14;
    u8 pad_18[7];
    u8 enabled;
} Sig_fn_80036070_Fn80036070Data;

typedef struct fn_1_7926C_Entry {
    f32 unk_0;
    f32 unk_4[3];
    f32 unk_10[3];
} fn_1_7926C_Entry;

extern FontDrawPacket lbl_1_rodata_26F8;
extern void fn_1_4E638(s32);
extern void fn_1_51914(const FontDrawPacket *);
extern void fn_1_51990(FontDrawPacket *);
extern void fn_1_D07E0(f32, f32, f32);
extern void fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern void fn_80074188(s32, s32, s32, s32);
extern void fn_80036070(const Sig_fn_80036070_Fn80036070Data *, u32 *, u16 *, u16 *, u32 *, u32 *, u32 *, u8 *);
extern void fn_8006F120(void *, void *);
extern f32 fn_8006F774(f32, f32);

#define fn_1_7926C_color fzgx_pool_table13

#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
void fn_1_7926C(s32 arg0) {
    f32 fzgx_live;
    FontDrawPacket packet;
    FontDrawPacket packet2;
    u32 texture;
    u32 texture2;
    u32 format;
    u32 unused14;
    u32 unused10;
    u16 width;
    u16 height;
    u8 flag;
    fn_1_7926C_Entry *entry;
    f32 scale;
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    f32 dx;
    f32 dy;
    s32 idx;

    fn_80038EEC(0.0f, 0.0f, 640.0f, 480.0f, 0.0f, 1.0f);
    fn_80074188(0, 0, 640, 480);
    fn_1_4E638(0);

    if (arg0 != 0) {
        packet = lbl_1_rodata_26F8;
        packet.image = 0x9458;
        packet.x = 320.0f;
        packet.y = 240.0f;
        packet.z += 0.03f;
        packet.alpha = 0.75f;
        fn_1_4F734(&packet);
    }

    if (lbl_1_bss_6D778.unk_0->unk_18 > 1) {
        fn_80036070((const Sig_fn_80036070_Fn80036070Data *)((u8 *)lbl_1_bss_6D778.unk_0->unk_24 + 0x20),
                    &texture2, &width, &height, &format, &unused14, &unused10, &flag);
        texture2 += 0x80000000;
        packet2 = lbl_1_rodata_26F8;
        packet2.x = 0.0f;
        packet2.y = 0.0f;
        packet2.z += 0.02f;
        packet2.flags |= 0x800000;
        packet2.format = format;
        packet2.width = width;
        packet2.height = height;
        packet2.pixels = (void *)texture2;
    }

    fn_80036070((const Sig_fn_80036070_Fn80036070Data *)lbl_1_bss_6D778.unk_0->unk_24,
                &texture, &width, &height, &format, &unused14, &unused10, &flag);
    texture += 0x80000000;
    packet = lbl_1_rodata_26F8;

    if (arg0 != 0) {
        packet.scale_x = 1.5f;
        packet.scale_y = 1.5f;
        x = 480.0f;
        y = 360.0f + (f32)(128.0f * (0.5f * packet.scale_x));
    } else {
        packet.scale_x = 1.0f;
        packet.scale_y = 1.0f;
        x = (640.0f - (f32)(128.0f * (0.5f * packet.scale_x))) - 8.0f;
        y = 408.0f;
    }

    w = (f32)(u32)width;
    h = (f32)(u32)height;
    dx = (0.5f * w) * packet.scale_x;
    dy = h * packet.scale_y;
    x -= dx;
    y -= dy;
    packet.x = x;
    packet.y = y;
    packet.z += 0.02f;
    packet.flags |= 0x800000;
    packet.format = format;
    packet.width = width;
    packet.height = height;
    packet.pixels = (void *)texture;
    *(u32 *)packet.color = fn_1_7926C_color[0];

    if (lbl_1_bss_6D778.unk_0->unk_18 > 1) {
        fn_1_51914(&packet2);
        fn_1_51990(&packet);
    }
    fn_1_4F734(&packet);

    idx = lbl_1_data_1DFA4.unk_8;
    idx = ((u32)idx < 46) ? idx : 0;
    entry = &((fn_1_7926C_Entry *)&lbl_1_data_1DFB0)[idx];
    fn_8006F120(entry->unk_4, entry->unk_10);
    fn_8006F774((f32)(u32)width * packet.scale_x, (f32)(u32)height * packet.scale_y);
    fzgx_live = entry->unk_0;
    fn_1_D07E0(fzgx_live, x, y);
    fn_8006F774(640.0f, 480.0f);
}
#pragma opt_loop_invariants reset

#pragma opt_strength_reduction reset
/* fzgx:end fn_1_7926C */

/* fzgx:begin fn_1_79654 */
typedef struct {
    u8 pad[0x30];
    f32 mtx[3][4];
} Cam_801A6D00;

extern Cam_801A6D00 *lbl_801A6D00[];
extern s8 camera_get_state(void);
extern u8 fn_1_5348(void);
extern u32 fn_1_58C4(void);
extern void fn_1_550A8(void);
extern void fn_1_7926C(s32);
extern void fn_1_550E0(void);
extern void lbl_8006DD14(void *, void *);
extern void fn_80038F10(f32 *);
extern void fn_80038FD8(u32 *, u32 *, u32 *, u32 *);
extern void fn_80038BFC(f32 *);
extern void fn_80072270(f32 *);
extern void fn_80074188(u32, u32, u32, u32);
extern void fn_80038EEC(f32, f32, f32, f32, f32, f32);

void fn_1_79654(void) {
    f32 mtx[3][4];
    f32 proj[6];
    f32 vp[7];
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u8 mode;
    u32 i;
    s8 state;
    struct { s32 value; } flag;

    if ((*(s16 *)&lbl_1_bss_960 == 2 || *(s16 *)&lbl_1_bss_960 == 9) && lbl_1_bss_6D778.unk_0 != 0) {
        mode = 0;
        state = camera_get_state();
        if (state == 0) {
            if ((((u32 *)&lbl_1_data_3D544)[0] >> 23) & 1) {
                mode = 1;
            }
        } else if (state == 7 || (state == 6 && fn_1_5348() == 4)) {
            for (i = 0; i < fn_1_58C4(); i++) {
                if ((((u32 *)&lbl_1_data_3D544)[i] >> 23) & 1) {
                    mode = fn_1_58C4();
                }
            }
        }
        if (mode == 1 || (u8)(mode - 3) <= 1) {
            lbl_8006DD14(lbl_801A6D00[0]->mtx, mtx);
            fn_80038F10(proj);
            fn_80038FD8(&a, &b, &c, &d);
            fn_80038BFC(vp);
            fn_1_550A8();
            flag.value = 1;
            if (!((u8)(mode - 3) <= 1)) {
                flag.value = 0;
            }
            fn_1_7926C(flag.value);
            fn_1_550E0();
            fn_80072270(vp);
            fn_80074188(a, b, c, d);
            fn_80038EEC(proj[0], proj[1], proj[2], proj[3], proj[4], proj[5]);
            lbl_8006DD14(mtx, lbl_801A6D00[0]->mtx);
        }
    }
}
/* fzgx:end fn_1_79654 */

/* fzgx:begin fn_1_79810 */
typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    u8 pad_12[0x6];
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    u8 pad_24[0xd0];
    void *unk_F4;
    u8 pad_F8[0xc];
    u32 unk_104;
} ScreenEffectSource;

extern void fn_80008BEC(void *arg0, s32 arg1, u32 arg2);
extern void lbl_8006D758(void);
extern void lbl_8006DB74(void *arg);
extern void lbl_8006E0C8(void *arg);

void fn_1_79810(void) {
    u32 source_flags;
    Obj_1_bss_3BE4 *dst;
    ScreenEffectSource *src;
    s32 i;

    i = 0;
    dst = *(Obj_1_bss_3BE4 **)&lbl_1_bss_3BE4;
    src = (ScreenEffectSource *)lbl_1_bss_3BE0->unk_1C;
    while (i < (s32)lbl_1_bss_3BE0->unk_18) {
        source_flags = dst->unk_9C;
        fn_80008BEC(dst, 0, 0xa0);
        dst->unk_9C = source_flags;
        dst->unk_8 = src->unk_0;
        dst->unk_C = src->unk_4;
        dst->unk_10 = src->unk_8;
        dst->unk_14 = src->unk_0 - src->unk_18;
        dst->unk_18 = src->unk_4 - src->unk_1C;
        dst->unk_1C = src->unk_8 - src->unk_20;
        dst->unk_20 = src->unk_C;
        dst->unk_22 = src->unk_E;
        dst->unk_24 = src->unk_10;
        dst->unk_26 = src->unk_C;
        dst->unk_28 = src->unk_E;
        dst->unk_2A = src->unk_10;
        lbl_8006D758();
        lbl_8006DB74((u8 *)dst + 0x2c);
        lbl_8006E0C8((u8 *)src + 0x18);
        lbl_8006DB74((u8 *)dst + 0x5c);
        if (src->unk_F4 != 0) {
            dst->unk_98 = *(f32 *)((u8 *)src->unk_F4 + 0xc);
        }
        source_flags = src->unk_104;
        dst->unk_0 |= source_flags;
        i++;
        src = (ScreenEffectSource *)((u8 *)src + 0x4b0);
        dst = (Obj_1_bss_3BE4 *)((u8 *)dst + 0xa0);
    }
}
/* fzgx:end fn_1_79810 */

/* fzgx:begin fn_1_79948 */
extern u32 lbl_1_bss_6C8DC[2];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_727BC(u32 arg0, u32 arg1, void *arg2);
extern void fn_1_76A94(void *arg0, u32 arg1);
extern void fn_1_76DBC(void);
extern void fn_1_4E500(void);
extern void fn_1_4E638(int);
extern void fn_1_4E6F4(void);
extern void fn_80073778(void *arg0, int arg1);
extern s32 fn_1_A5D9C(void);
extern const f32 lbl_1_rodata_31AC;
extern u32 fn_80008E84(u32 arg);
extern void fn_1_77238(void);
extern void fn_1_772E0(void);
extern void fn_1_77384(void *arg);
extern void fn_80072864(int arg0);
extern void fn_800745A4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern void fn_80074660(int arg0);
extern void fn_80073678(int arg0);
extern void fn_80073898(int arg0);
extern void fn_80074788(int arg0);
extern void fn_800738E0(int arg0, int arg1, int arg2);
extern void fn_80073D60(int arg0, int arg1, int arg2, int arg3, int arg4);
extern void fn_800734A8(int arg0, int arg1, int arg2, int arg3);
extern void fn_80072EDC(int arg0, int arg1);
extern f32 lbl_1_rodata_31B0[10];
extern const f64 lbl_1_rodata_31A0;
extern void lbl_8006D784(f32 *arg);
extern void fn_80073A58(int arg0, f32 *arg1, int arg2);
extern void fn_800739E0(int arg0, int arg1, int arg2);
extern void GXLoadTexMtxImm(f32 *arg0, int arg1, int arg2);
extern void fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8006FD1C(void);
extern void fn_1_79810(void);
extern void fn_1_79948(void);
extern void fn_1_791B0(void);
extern void fn_1_9A1E8(void);
extern void fn_1_9A864(void);
extern u8 fn_1_7B074(void);
extern void fn_80071718(void *arg);
extern void fn_800711A8(void *arg);
extern void fn_1_14CB4(void);
extern void fn_1_FA84(void);
extern const f32 lbl_1_rodata_32CC;
extern void fn_1_79C88(void *arg0, s32 arg1, f32 arg2, s32 arg3);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void sprintf(char *dst, const char *format, ...);
extern void fn_1_465D0(char *text, int arg);
extern void fn_1_14D5C(void *object, int arg);
extern void fn_1_46EA8(int value);
extern void fn_1_12620(void *object);
extern void fn_1_46DC4(void *obj);

extern void fn_1_727BC();
extern void fn_8006FDEC(void);
extern void fn_80071718(void *);
extern void fn_800711A8(void *);
extern u32 fn_8003526C(u32, u32);
extern u32 fn_80074300(u32, u32, u32, u32);
extern u32 fn_80074438(u32, u32, u32, u32);

extern u32 lbl_1_bss_6C8DC[2];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_727BC(u32 arg0, u32 arg1, void *arg2);
extern void fn_1_76A94(void *arg0, u32 arg1);
extern void fn_1_76DBC(void);
extern void fn_1_4E500(void);
extern void fn_1_4E638(int);
extern void fn_1_4E6F4(void);
extern void fn_80073778(void *arg0, int arg1);
extern s32 fn_1_A5D9C(void);
extern const f32 lbl_1_rodata_31AC;
extern u32 fn_80008E84(u32 arg);
extern void fn_1_77238(void);
extern void fn_1_772E0(void);
extern void fn_1_77384(void *arg);
extern void fn_80072864(int arg0);
extern void fn_800745A4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern void fn_80074660(int arg0);
extern void fn_80073678(int arg0);
extern void fn_80073898(int arg0);
extern void fn_80074788(int arg0);
extern void fn_800738E0(int arg0, int arg1, int arg2);
extern void fn_80073D60(int arg0, int arg1, int arg2, int arg3, int arg4);
extern void fn_800734A8(int arg0, int arg1, int arg2, int arg3);
extern void fn_80072EDC(int arg0, int arg1);
extern f32 lbl_1_rodata_31B0[10];
extern const f64 lbl_1_rodata_31A0;
extern void lbl_8006D784(f32 *arg);
extern void fn_80073A58(int arg0, f32 *arg1, int arg2);
extern void fn_800739E0(int arg0, int arg1, int arg2);
extern void GXLoadTexMtxImm(f32 *arg0, int arg1, int arg2);
extern void fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8006FD1C(void);
extern void fn_1_79810(void);
extern void fn_1_79948(void);
extern void fn_1_791B0(void);
extern void fn_1_9A1E8(void);
extern void fn_1_9A864(void);
extern u8 fn_1_7B074(void);
extern void fn_80071718(void *arg);
extern void fn_800711A8(void *arg);
extern void fn_1_14CB4(void);
extern void fn_1_FA84(void);
extern const f32 lbl_1_rodata_32CC;
extern void fn_1_79C88(void *arg0, s32 arg1, f32 arg2, s32 arg3);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void sprintf(char *dst, const char *format, ...);
extern void fn_1_465D0(char *text, int arg);
extern void fn_1_14D5C(void *object, int arg);
extern void fn_1_46EA8(int value);
extern void fn_1_12620(void *object);
extern void fn_1_46DC4(void *obj);

extern void fn_1_727BC();
extern void fn_8006FDEC(void);
extern void fn_80071718(void *);
extern void fn_800711A8(void *);
extern u32 fn_8003526C(u32, u32);
extern u32 fn_80074300(u32, u32, u32, u32);
extern u32 fn_80074438(u32, u32, u32, u32);


typedef struct ScreenFx {
    s8 type;
    u8 pad_1[3];
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 active;
    u32 unk_10;
    void *unk_14;
} ScreenFx;

typedef struct ScreenFxEntry {
    s8 key;
    s8 type;
    u8 pad_2[2];
    f32 unk_4;
    f32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 pad_F;
} ScreenFxEntry;

extern u32 fn_1_7AA50(f32);
extern void fn_1_7E8F4(void);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Obj_1_bss_6D600 lbl_1_bss_6D600;
ScreenFx lbl_1_bss_6D620[4];
ScreenFx lbl_1_bss_6D620__fzgx_offset_60[4];
ScreenFx lbl_1_bss_6D620__fzgx_offset_C0[4];
ScreenFx lbl_1_bss_6D620__fzgx_offset_120;
ScreenFx lbl_1_bss_6D758;

const ScreenFxEntry lbl_1_rodata_3278[5] = {
    { 4, 5, { 0, 0 }, -200.0f, 1000.0f, 0x00, 0x6E, 0x96, 0 },
    { 8, 5, { 0, 0 }, -200.0f, 2000.0f, 0x0A, 0x0A, 0x28, 0 },
    { 7, 4, { 0, 0 }, 0.0f, 3000.0f, 0x17, 0x1A, 0x1D, 0 },
    { 12, 2, { 0, 0 }, 0.0f, 820.0f, 0x6E, 0x78, 0x79, 0 },
    { -1, 4, { 0, 0 }, 0.0f, 100.0f, 0, 0, 0, 0 },
};

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_6D600;
    s = *(u8 *)&lbl_1_bss_6D620;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_60;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_C0;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_120;
    s = *(u8 *)&lbl_1_bss_6D758;
}

extern void fzgx_pool_sink_p(const void *);
extern void fzgx_pool_sink_f(f32);
extern void fzgx_pool_sink_d(f64);
static const f32 fzgx_pool_word_50[1] = { 0.03125f };
static const f32 fzgx_pool_word_54[1] = { 1.0f };
static const f64 fzgx_pool_dword_58[1] = { 4503601774854144.0 };
static const f64 fzgx_pool_dword_60[1] = { 4503599627370496.0 };
static const f32 fzgx_pool_word_68[1] = { 0.016666668f };
static const u32 fzgx_pool_word_6C[1] = { 0xFFFFFFFF };

/* primes the TU literal pool in retail order behind the table */
static void fzgx_pool_primer(void) {
    fzgx_pool_sink_p(lbl_1_rodata_3278);
    fzgx_pool_sink_p(fzgx_pool_word_50);
    fzgx_pool_sink_p(fzgx_pool_word_54);
    fzgx_pool_sink_p(fzgx_pool_dword_58);
    fzgx_pool_sink_p(fzgx_pool_dword_60);
    fzgx_pool_sink_p(fzgx_pool_word_68);
    fzgx_pool_sink_p(fzgx_pool_word_6C);
    fzgx_pool_sink_f(0.0f);
    fzgx_pool_sink_f(640.0f);
    fzgx_pool_sink_f(480.0f);
    fzgx_pool_sink_f(320.0f);
    fzgx_pool_sink_f(240.0f);
    fzgx_pool_sink_f(0.03f);
    fzgx_pool_sink_f(0.75f);
    fzgx_pool_sink_f(0.02f);
    fzgx_pool_sink_f(1.5f);
    fzgx_pool_sink_f(360.0f);
    fzgx_pool_sink_f(128.0f);
    fzgx_pool_sink_f(0.5f);
    fzgx_pool_sink_f(8.0f);
    fzgx_pool_sink_f(408.0f);
    fzgx_pool_sink_f(100.0f);
}
#pragma section code_type ".text"

static inline void fx_reset(ScreenFx *e) {
    e->active = 0;
    e->type = 5;
    e->unk_4 = 0.0f;
    e->unk_8 = 100.0f;
    e->unk_C = 0;
    e->unk_D = 0;
    e->unk_E = 0;
}

static inline void fx_lookup(ScreenFx *e, s32 key) {
    const ScreenFxEntry *ent;

    fx_reset(e);
    for (ent = lbl_1_rodata_3278; ent->key != -1; ent++) {
        if (ent->key == lbl_1_data_2A7E0.unk_0) {
            e->active = 1;
            e->type = ent->type;
            e->unk_4 = ent->unk_4;
            e->unk_8 = ent->unk_8;
            e->unk_C = ent->unk_C;
            e->unk_D = ent->unk_D;
            e->unk_E = ent->unk_E;
        }
    }
}

static inline void fx_set(ScreenFx *e, const ScreenFxEntry *ent) {
    e->active = 1;
    e->type = ent->type;
    e->unk_4 = ent->unk_4;
    e->unk_8 = ent->unk_8;
    e->unk_C = ent->unk_C;
    e->unk_D = ent->unk_D;
    e->unk_E = ent->unk_E;
}

void fn_1_79948(void) {
    ScreenFx *e;
    const ScreenFxEntry *ent;
    s32 i;
    ScreenFx tmp;

    if (lbl_1_bss_3BE0 != NULL && lbl_1_bss_3BE0->unk_80 != 0) {
        lbl_1_bss_6D758.active = 1;
        lbl_1_bss_6D758.type = lbl_1_bss_3BE0->unk_84 != 0 ? *(s8 *)lbl_1_bss_3BE0->unk_84 : 4;
        fn_1_7AA50(0.0f);
    } else {
        fx_reset(&lbl_1_bss_6D758);
    }

    e = &lbl_1_bss_6D620__fzgx_offset_120;
    fx_reset(e);
    for (ent = lbl_1_rodata_3278; ent->key != -1; ent++) {
        if (ent->key == lbl_1_data_2A7E0.unk_0) {
            e->active = 1;
            lbl_1_bss_6D620__fzgx_offset_120.type = ent->type;
            e->unk_4 = ent->unk_4;
            e->unk_8 = ent->unk_8;
            e->unk_C = ent->unk_C;
            e->unk_D = ent->unk_D;
            e->unk_E = ent->unk_E;
        }
    }

    for (i = 0; i < 4; i++) {
        lbl_1_bss_6D620[i] = lbl_1_bss_6D758;
        lbl_1_bss_6D620[i].unk_14 = &lbl_1_bss_6D758;
        lbl_1_bss_6D620[i].unk_10 = 0x20;
        lbl_1_bss_6D620__fzgx_offset_60[i] = lbl_1_bss_6D620[i];
        lbl_1_bss_6D620__fzgx_offset_C0[i] = lbl_1_bss_6D620[i];
    }
    fn_1_7E8F4();
}
/* fzgx:end fn_1_79948 */

/* fzgx:begin fn_1_79C88 noprologue */
#include "types.h"

typedef struct {
    u32 flags;
    s32 count;
    void *nodes;
} EffectManager;

typedef struct {
    u32 type;
    u32 unk04;
    void *resource;
    f32 threshold;
} EffectNode;

typedef struct {
    u8 unk00[0x14];
    f32 scale;
} EffectData;

typedef struct {
    u8 unk00[0x8];
    f32 angle;
} EffectResult;

typedef struct {
    u8 unk00[0x2c];
    f32 value;
} GlobalData;

extern f32 lbl_1_rodata_3278[20];
extern GlobalData *lbl_801A6D00;
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern f32 fn_1_A71AC(void);

static inline f32 fn_1_79C88_operand(f32 left, f32 right) { return left * right; }
s32 fn_1_79C88(EffectManager *manager, u32 *out, s32 reverse, f32 value) {
    void * fzgx_live;
    EffectData *data;
    f32 *rodata = lbl_1_rodata_3278;
    EffectNode *node;
    EffectResult result;
    f32 phase;
    f32 limit;
    f32 inv;
    f32 factor;
    f32 tmp;
    s32 index;
    s32 i;

    node = (EffectNode *)manager->nodes;
    data = (EffectData *)node->resource;
    if (((0) == (data))) {
        return 0;
    }

    lbl_8006E1B0((u8 *)data + 8, &result);
    phase = -result.angle;
    limit = -lbl_801A6D00->value;
    if ((manager->flags & 2) != 0) {
        if (limit < rodata[43]) {
            index = 0;
        } else {
            index = 0;
            while (index < manager->count) {
                if (limit < node->threshold) {
                    break;
                }
                index++;
                node++;
            }
        }
    } else {
        if (phase < rodata[43]) {
            index = 0;
        } else {
            tmp = rodata[44] * data->scale;
            value = tmp * value;
            factor = phase * fn_1_A71AC();
            inv = rodata[32];
            index = 0;
            while (index < manager->count) {
                if (value > fn_1_79C88_operand((node->threshold / inv), (factor))) {
                    break;
                }
                index++;
                node++;
            }
        }
    }

    if (node->resource != 0 && index < manager->count) {
        if (reverse != 0) {
            for (i = index; i < manager->count; i++) {
                if (node->resource == 0) {
                    break;
                }
                node++;
            }
            node--;
        }
        if (out != 0) {
            *out = node->type;
        }
        fzgx_live = node->resource;
        return (s32)fzgx_live;
    }
    if (out != 0) {
        *out = 0;
    }
    return 0;
}
/* fzgx:end fn_1_79C88 */

/* fzgx:begin fn_1_79E54 noprologue */
typedef signed long s32;


typedef unsigned char u8;


typedef unsigned long u32;


typedef float f32;


typedef struct {
f32 x;
f32 y;
f32 z;
} Fn183D28Vec3;


extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);


extern f32 lbl_1_data_4;


typedef struct {
u32 id;
u32 unk_4;
void *unk_8;
f32 time;
} EffectEntry;
typedef struct {
u32 flags;
s32 count;
void *entries;
} Sig_fn_1_7A67C_EffectTable;
typedef struct {
u8 pad_0[0x8];
u8 unk_8[0xC];
f32 unk_14;
} EffectObj;
typedef struct {
u8 pad_0[0x8];
EffectObj *obj;
} EffectHolder;
typedef struct {
u8 pad_0[0x2C];
f32 unk_2C;
} CameraLike;
struct fn_1_7A240_lbl_1_rodata_3278 {
u8 pad_0[0x54];
f32 unk_54;
u8 pad_58[0x18];
f32 unk_70;
u8 pad_74[0xC];
f32 unk_80;
u8 pad_84[0x28];
f32 unk_AC;
f32 unk_B0;
};
extern f32 fn_1_A71AC(void);
extern struct fn_1_7A240_lbl_1_rodata_3278 lbl_1_rodata_3278;
extern CameraLike *lbl_801A6D00;
extern void *fn_1_7A67C(Sig_fn_1_7A67C_EffectTable *);
extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);
static inline f32 effect_clamp_final(f32 low, f32 high, f32 value)
{
if (value < low) {
return low;
} else {
return value > high ? high : value;
}
}
void *fn_1_79E54(Sig_fn_1_7A67C_EffectTable *arg0, u32 *outId, f32 *outF,
s32 advance, f32 scale)
{
s32 n31;
s32 n30;
struct fn_1_7A240_lbl_1_rodata_3278 *c;
Sig_fn_1_7A67C_EffectTable *tbl;
EffectObj *obj;
EffectEntry *e;
s32 i;
s32 has1;
s32 has40;
s32 count;
f32 result;
f32 depth;
f32 dist;
f32 blend;
f32 factor;
f32 t;
f32 k;
f32 prevTime;
EffectEntry *p;
Fn183D28Vec3 pos;
blend = scale;
c = &lbl_1_rodata_3278;
*outF = c->unk_54;
e = (EffectEntry *)arg0->entries;
obj = (EffectObj *)e->unk_8;
if (obj == ((void *)0) ) {
return ((void *)0) ;
}
tbl = arg0;
count = tbl->count;
has40 = tbl->flags & 0x40;
has1 = tbl->flags & 1;
n30 = has40 ? count - 2 : count;
n31 = has1 ? n30 - 1 : n30;
if (tbl->flags & 0x80) {
result = c->unk_70;
} else {
result = lbl_1_data_4;
}
lbl_8006E1B0((Fn183D28Vec3 *)obj->unk_8, &pos);
depth = -pos.z;
dist = -lbl_801A6D00->unk_2C;
if (tbl->flags & 2) {
if (dist < c->unk_AC) {
i = 0;
} else {
for (i = 0; i < tbl->count; i++, e++) {
if (dist < e->time) {
if (has1) {
result = dist;
p = (EffectEntry *)tbl->entries + n30 - 1;
prevTime = p[-1].time;
t = (dist - prevTime) / (p->time - prevTime);
*outF = ((t) < c->unk_70 ? c->unk_70 : ((t) > c->unk_54 ? c->unk_54 : (t))) ;
}
if (has40) {
if (!(tbl->flags & 0x80)) {
factor = c->unk_B0 * obj->unk_14;
blend = factor * blend;
result = c->unk_80 * blend / (depth * fn_1_A71AC());
} else if (!has1) {
result = dist;
}
}
break;
}
}
}
} else {
if (depth < c->unk_AC) {
i = 0;
} else {
f32 factorB = c->unk_B0 * obj->unk_14;
blend = factorB * blend;
k = depth * fn_1_A71AC();
for (i = 0; i < n31; i++, e++) {
t = e->time / c->unk_80;
if (blend > t * k) {
if (has1) {
result = c->unk_80 * blend / k;
p = (EffectEntry *)tbl->entries + n30 - 1;
prevTime = p[-1].time;
t = (result - prevTime) / (p->time - prevTime);
*outF = ((t) < c->unk_70 ? c->unk_70 : ((t) > c->unk_54 ? c->unk_54 : (t))) ;
}
if (has40) {
if (tbl->flags & 0x80) {
result = dist;
} else if (!has1) {
result = c->unk_80 * blend / k;
}
}
break;
}
}
}
}
if (e->unk_8 != ((void *)0) && i < n31) {
if (advance && i != n31 - 1) {
    s32 j;
    for (j = i; j < n31 - 1; j++) {
        e++;
        if (!e->unk_8) {
            e--;
            break;
        }
    }
}
if (has40) {
struct { f32 low; f32 high; } bounds;
f32 endTime;
if (*outF >= (bounds.high = c->unk_54)) {
p = (EffectEntry *)tbl->entries + count - 1;
endTime = p->time;
t = (endTime - result) / (endTime - p[-1].time);
bounds.low = c->unk_70;
*outF = effect_clamp_final(bounds.low, bounds.high, t);
}
}
if (*outF > c->unk_70) {
if (outId != ((void *)0) ) {
*outId = e->id;
}
return e->unk_8;
}
}
if (outId != ((void *)0) ) {
*outId = 0;
}
return ((void *)0) ;
}
/* fzgx:end fn_1_79E54 */

/* fzgx:begin fn_1_7A240 noprologue */
typedef signed long s32;


typedef unsigned char u8;


typedef unsigned long u32;


typedef float f32;


typedef struct {
f32 x;
f32 y;
f32 z;
} Fn183D28Vec3;


extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);


extern f32 lbl_1_data_4;


typedef struct {
u32 id;
u32 unk_4;
void *unk_8;
f32 time;
} EffectEntry;
typedef struct {
u32 flags;
s32 count;
void *entries;
} Sig_fn_1_7A67C_EffectTable;
typedef struct {
u8 pad_0[0x8];
u8 unk_8[0xC];
f32 unk_14;
} EffectObj;
typedef struct {
u8 pad_0[0x8];
EffectObj *obj;
} EffectHolder;
typedef struct {
u8 pad_0[0x2C];
f32 unk_2C;
} CameraLike;
struct fn_1_7A240_lbl_1_rodata_3278 {
u8 pad_0[0x54];
f32 unk_54;
u8 pad_58[0x18];
f32 unk_70;
u8 pad_74[0xC];
f32 unk_80;
u8 pad_84[0x28];
f32 unk_AC;
f32 unk_B0;
};
extern f32 fn_1_A71AC(void);
extern struct fn_1_7A240_lbl_1_rodata_3278 lbl_1_rodata_3278;
extern CameraLike *lbl_801A6D00;
extern void *fn_1_7A67C(Sig_fn_1_7A67C_EffectTable *);
extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);
static inline f32 effect_clamp_final(f32 low, f32 high, f32 value)
{
if (value < low) {
return low;
} else {
return value > high ? high : value;
}
}
void *fn_1_7A240(Sig_fn_1_7A67C_EffectTable *arg0, u32 *outId, f32 *outF,
Sig_fn_1_7A67C_EffectTable *arg3, f32 scale)
{
s32 n31;
s32 n30;
struct fn_1_7A240_lbl_1_rodata_3278 *c;
Sig_fn_1_7A67C_EffectTable *tbl;
EffectObj *obj;
EffectEntry *e;
s32 i;
s32 has1;
s32 has40;
s32 count;
f32 result;
f32 depth;
f32 dist;
f32 factor;
f32 t;
f32 k;
f32 prevTime;
EffectEntry *p;
Fn183D28Vec3 pos;
c = &lbl_1_rodata_3278;
*outF = c->unk_54;
obj = ((EffectHolder *)arg0->entries)->obj;
if (obj == ((void *)0) ) {
return ((void *)0) ;
}
if (arg3 != ((void *)0) ) {
tbl = arg3;
} else {
tbl = arg0;
}
count = tbl->count;
has40 = tbl->flags & 0x40;
e = (EffectEntry *)tbl->entries;
has1 = tbl->flags & 1;
n30 = has40 ? count - 2 : count;
n31 = has1 ? n30 - 1 : n30;
if (tbl->flags & 0x80) {
result = c->unk_70;
} else {
result = lbl_1_data_4;
}
lbl_8006E1B0((Fn183D28Vec3 *)obj->unk_8, &pos);
depth = -pos.z;
if (arg0->flags & 2) {
dist = -lbl_801A6D00->unk_2C;
} else {
dist = depth;
}
if (arg3 != ((void *)0) ) {
dist -= obj->unk_14;
}
if (tbl->flags & 2) {
if (dist < c->unk_AC) {
i = 0;
} else {
for (i = 0; i < tbl->count; i++, e++) {
if (dist < e->time) {
if (has1) {
result = dist;
p = (EffectEntry *)tbl->entries + n30 - 1;
prevTime = p[-1].time;
t = (dist - prevTime) / (p->time - prevTime);
*outF = ((t) < c->unk_70 ? c->unk_70 : ((t) > c->unk_54 ? c->unk_54 : (t))) ;
}
if (has40) {
if (!(tbl->flags & 0x80)) {
factor = c->unk_B0 * obj->unk_14;
scale = factor * scale;
result = c->unk_80 * scale / (depth * fn_1_A71AC());
} else if (!has1) {
result = dist;
}
}
break;
}
}
}
} else {
if (depth < c->unk_AC) {
i = 0;
} else {
f32 factorB = c->unk_B0 * obj->unk_14;
f32 scaled = factorB * scale;
k = depth * fn_1_A71AC();
for (i = 0; i < n31; i++, e++) {
t = e->time / c->unk_80;
if (scaled > t * k) {
if (has1) {
result = c->unk_80 * scaled / k;
p = (EffectEntry *)tbl->entries + n30 - 1;
prevTime = p[-1].time;
t = (result - prevTime) / (p->time - prevTime);
*outF = ((t) < c->unk_70 ? c->unk_70 : ((t) > c->unk_54 ? c->unk_54 : (t))) ;
}
if (has40) {
if (tbl->flags & 0x80) {
result = dist;
} else if (!has1) {
result = c->unk_80 * scaled / k;
}
}
break;
}
}
}
}
if (e->unk_8 != ((void *)0) && i < n31) {
if (arg3 != ((void *)0) ) {
obj = fn_1_7A67C(arg0);
}
if (has40) {
struct { f32 low; f32 high; } bounds;
f32 endTime;
if (*outF >= (bounds.high = c->unk_54)) {
p = (EffectEntry *)tbl->entries + count - 1;
endTime = p->time;
t = (endTime - result) / (endTime - p[-1].time);
bounds.low = c->unk_70;
*outF = effect_clamp_final(bounds.low, bounds.high, t);
}
}
if (*outF > c->unk_70 && obj != ((void *)0) ) {
if (outId != ((void *)0) ) {
*outId = e->id;
}
return obj;
}
}
if (outId != ((void *)0) ) {
*outId = 0;
}
return ((void *)0) ;
}
/* fzgx:end fn_1_7A240 */

/* fzgx:begin fn_1_7A648 */
void fn_1_7A648(void *arg0) {
    fn_1_79C88(arg0, 0, lbl_1_rodata_32CC, 0);
}
/* fzgx:end fn_1_7A648 */

/* fzgx:begin fn_1_7A67C */
typedef struct {
    u32 flags;
    s32 count;
    void *entries;
} EffectTable;

typedef struct {
    u8 unk00[0x8];
    void *value;
    u32 unk0c;
} EffectEntry;

void *fn_1_7A67C(EffectTable *table) {
    s32 index;
    EffectEntry *entry;

    index = table->count - 1;
    if ((table->flags & 1) != 0) {
        index--;
    }
    if ((table->flags & 0x40) != 0) {
        index -= 2;
    }
    entry = (EffectEntry *)table->entries;
    entry += index;
    return entry->value;
}
/* fzgx:end fn_1_7A67C */

/* fzgx:begin fn_1_7A9B8 */
typedef struct {
    u8 pad_0[0xf4];
    void *resource;
    u8 pad_f8[0x4b0 - 0xf8];
} fn_1_7A9B8_ScreenEffect;

typedef struct {
    u8 pad_0[0x2c];
    u8 reset_data[0x60];
    u8 load_data[0x14];
} fn_1_7A9B8_ScreenEffectEntry;

// Resets the active screen-effect entries and releases each attached resource.
void fn_1_7A9B8(void) {
    fn_1_7A9B8_ScreenEffectEntry *entry;
    fn_1_7A9B8_ScreenEffect *effect;
    s32 i;

    i = 0;
    entry = (fn_1_7A9B8_ScreenEffectEntry *)lbl_1_bss_3BE4.unk_0;
    effect = (fn_1_7A9B8_ScreenEffect *)lbl_1_bss_3BE0->unk_1C;
    while (i < (s32)lbl_1_bss_3BE0->unk_18) {
        if (effect->resource != 0) {
            lbl_8006DBAC(&entry->reset_data);
            lbl_8006E1B0(effect->resource, &entry->load_data);
        }
        i++;
        entry++;
        effect++;
    }
}
/* fzgx:end fn_1_7A9B8 */

/* fzgx:begin fn_1_7B054 */
// Return the current screen effect value.
s16 fn_1_7B054(void) {
    return lbl_1_data_1DFA4.unk_8;
}
/* fzgx:end fn_1_7B054 */

/* fzgx:begin fn_1_7B064 */
u32 fn_1_7B064(void) {
    return lbl_1_bss_6D774;
}
/* fzgx:end fn_1_7B064 */

/* fzgx:begin fn_1_7B074 */
u8 fn_1_7B074(void) {
    return lbl_1_bss_6D600.unk_0;
}
/* fzgx:end fn_1_7B074 */

/* fzgx:begin fn_1_7B084 */
void fn_1_7B084(void *object, int value) {
    char text_a[32];
    char text_b[32];
    const char *data = (const char *)&lbl_1_data_1DCF0;

    sprintf(text_a, data + 0x7d0, data + 0x7e0, object);
    sprintf(text_b, data + 0x7e8, data + 0x7e0, object);
    if (value == 0) {
        fn_1_465D0(text_a, 1);
        fn_1_465D0(text_b, 1);
        fn_1_14D5C(object, 0);
    } else {
        fn_1_465D0(text_a, 2);
        fn_1_465D0(text_b, 2);
        fn_1_14D5C(object, 1);
    }
    fn_1_46EA8(value);
    fn_1_12620(object);
    sprintf(text_a, data + 0x7f8, object);
    fn_1_465D0(text_a, 1);
    fn_1_46EA8(0);
}
/* fzgx:end fn_1_7B084 */

/* fzgx:begin fn_1_7B184 */
void fn_1_7B184(void *arg) {
    char buf_48[0x20];
    char buf_28[0x20];
    char buf_08[0x20];
    u8 *base = (u8 *)&lbl_1_data_1DCF0;

    sprintf(buf_48, (const char *)(base + 0x7d0), (const char *)(base + 0x7e0), arg);
    sprintf(buf_28, (const char *)(base + 0x7e8), (const char *)(base + 0x7e0), arg);
    sprintf(buf_08, (const char *)(base + 0x810), arg);

    fn_1_46DC4(buf_48);
    fn_1_46DC4(buf_28);
    fn_1_46DC4(buf_08);
}
/* fzgx:end fn_1_7B184 */

/* fzgx:begin fn_1_7B218 noprologue */
#include "types.h"
#include "rel/main_rel/screen_effect.h"

typedef struct {
    u8 pad_0[0x7e0];
    char unk_7e0[0x4c];
    char unk_82c[0x14];
    char unk_840[0x20];
} ScreenEffectData;

extern u16 fn_1_12EF24(s16 value, s16 index);
extern void sprintf(char *dst, const char *format, const char *text, ...);
extern void fn_1_465D0(char *text, s32 mode);

void fn_1_7B218(s32 enabled) {
    char text_a[0x20];
    char text_b[0x20];
    s32 i;
    s16 index;
    ScreenEffectData *data = (ScreenEffectData *)&lbl_1_data_1DCF0;

    i = 0;
    do {
        index = fn_1_12EF24(lbl_1_bss_8B3A0.unk_8C, i);
        if (index >= 0) {
            sprintf(text_a, data->unk_82c, data->unk_7e0, index);
            sprintf(text_b, data->unk_840, data->unk_7e0, index);
            if (enabled == 0) {
                fn_1_465D0(text_a, 1);
                fn_1_465D0(text_b, 1);
            } else {
                fn_1_465D0(text_a, 2);
                fn_1_465D0(text_b, 2);
            }
        }
        i++;
    } while (i < 6);
}
/* fzgx:end fn_1_7B218 */

/* fzgx:begin fn_1_7B4C0 */
// Releases active screen effects and resets the effect state.
void fn_1_7B4C0(void) {
    if (lbl_1_bss_6D770 != 0 || lbl_1_bss_6D774 != 0) {
        fn_8006FDEC();
    }

    if (lbl_1_bss_6D770 != 0) {
        fn_80071718((void *)lbl_1_bss_6D770);
        lbl_1_bss_6D770 = 0;
    }

    if (lbl_1_bss_6D774 != 0) {
        fn_800711A8((void *)lbl_1_bss_6D774);
        lbl_1_bss_6D774 = 0;
    }

    lbl_1_data_1DFA4.unk_8 = -1;
}
/* fzgx:end fn_1_7B4C0 */

/* fzgx:begin fn_1_7B558 noprologue */
#include "types.h"
#include "psvec.h"

typedef struct fn_1_7B558_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} fn_1_7B558_Vec3;

typedef struct fn_1_7B558_List {
    u32 count;
    u32 pad_4;
    struct {
        void *model;
        char *name;
    } *entries;
} fn_1_7B558_List;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_6D600[0x20];
u8 lbl_1_bss_6D620__fzgx_offset_0[312];
u8 lbl_1_bss_6D758__fzgx_offset_0[24];
u32 lbl_1_bss_6D770;
fn_1_7B558_List *lbl_1_bss_6D774;
u32 fzgx_obj_lbl_1_bss_6D778;
f32 lbl_1_bss_6D778__fzgx_offset_4[4];
u8 lbl_1_bss_6D778__fzgx_offset_14[0x14];
u32 lbl_1_bss_6D778__fzgx_offset_28;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D600;
    s = *(u8 *)&lbl_1_bss_6D620__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_1_bss_6D758__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_6D770;
    s = *(u8 *)&lbl_1_bss_6D774;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D778;
    s = *(u8 *)&lbl_1_bss_6D778__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6D778__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_6D778__fzgx_offset_28;
}
#pragma section code_type ".text"

typedef struct fn_1_7B558_Camera {
    u8 pad_0[0xD4];
    fn_1_7B558_Vec3 dir;
} fn_1_7B558_Camera;

extern struct { fn_1_7B558_Camera *cam; } lbl_801A66CC;
extern struct { f32 (*mtx)[4]; } lbl_801A6D00;
extern u32 lbl_801A66A0;
extern s16 lbl_1_bss_960;
extern u8 lbl_1_data_1E4B8[];
extern u8 lbl_1_data_1E5C0[];
extern struct { f32 unk_0; u32 unk_4; s16 unk_8; } lbl_1_data_1DFA4;

extern s8 fn_1_A5DC4(void);
extern u32 __cvt_fp2unsigned(f32);
extern void lbl_8006DD14(void *, void *);
extern void fn_80038F10(f32 *);
extern void fn_80038FD8(u32 *, u32 *, u32 *, u32 *);
extern void fn_1_A71CC(void);
extern void fn_1_550A8(void);
extern f32 lbl_8006D188(s16);
extern void fn_1_A7024(f32, f32, f32, f32);
extern void fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern void fn_80074188(u32, u32, u32, u32);
extern f32 lbl_8006D21C(s32);
extern f32 lbl_8006D668(void *);
extern void fn_8006F120(fn_1_7B558_Vec3 *, fn_1_7B558_Vec3 *);
extern void lbl_8006DCDC(void);
extern void fn_1_F7870(void *);
extern void mathutil_mtxA_rotate_y(s32);
extern void lbl_8006E0B4(f32, f32, f32);
extern void fn_1_55FF0(f32);
extern void fn_80072558(void);
extern char *fn_80083970(char *, u8 *);
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_1_556B8(void *);
extern f64 fn_1_550E0(void);
extern void fn_1_A722C(void);

extern void fzgx_pool_sink_p(void *);
extern void fzgx_pool_sink_f(f32);

/* Shared literal pool primer: screen_effect.c pools its literals behind one
   base (lbl_1_rodata_3278 here). These dummy functions, in a section the link
   ignores, reference the pooled literals in retail address order. */
#pragma section ".fzgxpool"

typedef struct { u32 a; f32 b; f32 c; u32 d; } fzgx_pool_Img16;
typedef struct { u8 r, g, b, a; } fzgx_pool_Color;
typedef struct { u32 w[12]; } fzgx_pool_Img48;

__declspec(section ".fzgxpool") void fzgx_pool_primer_0(void) {
    fzgx_pool_Img16 i0 = {0x04050000, -200.0f, 1000.0f, 0x006E9600};
    fzgx_pool_Img16 i1 = {0x08050000, -200.0f, 2000.0f, 0x0A0A2800};
    fzgx_pool_Img16 i2 = {0x07040000, 0.0f, 3000.0f, 0x171A1D00};
    fzgx_pool_Img16 i3 = {0x0C020000, 0.0f, 820.0f, 0x6E787900};
    fzgx_pool_Img16 i4 = {0xFF040000, 0.0f, 100.0f, 0};
    fzgx_pool_sink_p(&i0);
    fzgx_pool_sink_p(&i1);
    fzgx_pool_sink_p(&i2);
    fzgx_pool_sink_p(&i3);
    fzgx_pool_sink_p(&i4);
    fzgx_pool_sink_f(0.03125f);
    fzgx_pool_sink_f(1.0f);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_1(s32 a, u32 b) {
    fzgx_pool_sink_f((f32)a);
    fzgx_pool_sink_f((f32)b);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_2(void) {
    fzgx_pool_sink_f(0.016666668f);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_3(void) {
    fzgx_pool_Color c0 = {0xFF, 0xFF, 0xFF, 0xFF};
    fzgx_pool_sink_p(&c0);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_4(void) {
    fzgx_pool_sink_f(0.0f);
    fzgx_pool_sink_f(640.0f);
    fzgx_pool_sink_f(480.0f);
    fzgx_pool_sink_f(320.0f);
    fzgx_pool_sink_f(240.0f);
    fzgx_pool_sink_f(0.03f);
    fzgx_pool_sink_f(0.75f);
    fzgx_pool_sink_f(0.02f);
    fzgx_pool_sink_f(1.5f);
    fzgx_pool_sink_f(360.0f);
    fzgx_pool_sink_f(128.0f);
    fzgx_pool_sink_f(0.5f);
    fzgx_pool_sink_f(8.0f);
    fzgx_pool_sink_f(408.0f);
    fzgx_pool_sink_f(100.0f);
    fzgx_pool_sink_f(1.1920928955078125e-07f);
    fzgx_pool_sink_f(2.0f);
    fzgx_pool_sink_f(60.0f);
    fzgx_pool_sink_f(182.04444885f);
    fzgx_pool_sink_f(255.0f);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_5(void) {
    fzgx_pool_Img48 z0 = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00403AFF}};
    fzgx_pool_sink_p(&z0);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer_6(void) {
    fzgx_pool_sink_f(63.0f);
    fzgx_pool_sink_f(0.9960784316062927f);
    fzgx_pool_sink_f(0.800000011920929f);
    fzgx_pool_sink_f(0.9411764740943909f);
    fzgx_pool_sink_f(0.8999999761581421f);
    fzgx_pool_sink_f(427.0f);
    fzgx_pool_sink_f(854.0f);
    fzgx_pool_sink_f(8192.0f);
    fzgx_pool_sink_f(4096.0f);
    fzgx_pool_sink_f(16384.0f);
    fzgx_pool_sink_f(55.0f);
    fzgx_pool_sink_f(1.2f);
    fzgx_pool_sink_f(0.1f);
    fzgx_pool_sink_f(90000.0f);
}

#pragma section ".text"

#pragma opt_strength_reduction off
void fn_1_7B558(s32 arg0, s32 arg1, u32 x, u32 y, u32 w, u32 h, f32 scale) {
    f32 mtx[3][4];
    f32 viewport[6];
    fn_1_7B558_Vec3 at;
    fn_1_7B558_Vec3 eye;
    u32 sx;
    u32 sy;
    u32 sw;
    u32 sh;
    s32 angle;
    f32 alpha;
    f32 radius;
    f32 fov;
    f32 dist;
    struct { s32 value; s32 offset; } i;
    void *model;
    void * lab_t0;

    if (fn_1_A5DC4() != 0) {
        x = __cvt_fp2unsigned(320.0f - (320.0f * (320.0f - (f32)x)) / 427.0f);
        w = __cvt_fp2unsigned((640.0f * (f32)w) / 854.0f);
    }
    if (lbl_1_bss_6D770 == 0 || lbl_1_bss_6D774 == 0) {
        return;
    }
    if (arg1 != 0) {
        lbl_1_bss_6D778__fzgx_offset_28 = (lbl_801A66A0 & 0x1FF) << 7;
    } else if ((lbl_1_bss_6D778__fzgx_offset_28 & 0x3F) == 0) {
        lbl_1_bss_6D778__fzgx_offset_28 = 1;
    } else if ((lbl_1_bss_6D778__fzgx_offset_28 & 0x3F) < 63) {
        lbl_1_bss_6D778__fzgx_offset_28 = lbl_1_bss_6D778__fzgx_offset_28 + 1;
    }
    lbl_8006DD14(lbl_801A6D00.mtx + 3, mtx);
    fn_80038F10(viewport);
    fn_80038FD8(&sx, &sy, &sw, &sh);
    fn_1_A71CC();
    fn_1_550A8();
    angle = (s16)lbl_1_bss_6D778__fzgx_offset_28 + 0x4000;
    eye.x = 0.0f;
    eye.y = lbl_8006D188((s16)(8192.0f + (f32)(4096.0f * lbl_8006D188(angle))));
    eye.z = lbl_8006D188((s16)(16384.0f + (8192.0f + (f32)(4096.0f * lbl_8006D188(angle)))));
    radius = lbl_1_bss_6D778__fzgx_offset_4[3];
    at.x = 0.0f;
    at.y = 0.0f;
    at.z = 0.0f;
    fn_1_A7024(55.0f, 1.2f, 0.1f, 90000.0f);
    fn_80038EEC((f32)x, (f32)y, (f32)w, (f32)h, 0.0f, 1.0f);
    fn_80074188(x, y, w, h);
    fov = 5006.22216796875f;
    dist = (scale * radius) / lbl_8006D21C((s32)fov);
    psvec_sub(&eye, &at, &lbl_801A66CC.cam->dir);
    lbl_8006D668(&lbl_801A66CC.cam->dir);
    psvec_scale_add(&at, &lbl_801A66CC.cam->dir, dist, &eye);
    fn_8006F120(&eye, &at);
    lbl_8006DCDC();
    if (arg0 != 0) {
        fn_1_F7870(lbl_1_data_1E5C0);
    }
    alpha = 1.0f;
    if (lbl_1_data_1DFA4.unk_8 != -1) {
        if (arg1 == 0) {
            alpha = (f32)(lbl_1_bss_6D778__fzgx_offset_28 & 0x3F) / 63.0f;
        }
        mathutil_mtxA_rotate_y((s16)(lbl_1_bss_6D778__fzgx_offset_28 + 0x4000));
        lbl_8006E0B4(-lbl_1_bss_6D778__fzgx_offset_4[0], -lbl_1_bss_6D778__fzgx_offset_4[1], -lbl_1_bss_6D778__fzgx_offset_4[2]);
        fn_1_55FF0(alpha);
        fn_80072558();
        for (i.value = 0, i.offset = 0; i.value < lbl_1_bss_6D774->count; i.offset += 8, i.value++) {
            arg1 = (s32)*(void **)((u8 *)lbl_1_bss_6D774->entries + i.offset);
            if (lbl_1_bss_960 == 5) {
                if (fn_80083970(*(char **)((u8 *)lbl_1_bss_6D774->entries + i.offset + 4), lbl_1_data_1E4B8) == 0) {
                    fn_1_5621C(0.9960784316062927f, 0.800000011920929f, 0.9411764740943909f, 0.8999999761581421f);
                    fn_1_556B8((void *)arg1);
                    fn_1_5621C(1.0f, 1.0f, 1.0f, 1.0f);
                }
            } else {
                fn_1_556B8((void *)arg1);
            }
        }
    }
    fn_1_550E0();
    fn_1_A722C();
    fn_80074188(sx, sy, sw, sh);
    fn_80038EEC(viewport[0], viewport[1], viewport[2], viewport[3], viewport[4], viewport[5]);
    lbl_8006DD14(mtx, lbl_801A6D00.mtx + 3);
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_7B558 */

/* fzgx:begin fn_1_7BA08 */
u32 fn_1_7BA08(u16 arg0, u16 arg1, u16 arg2) {
    Obj_1_bss_6D7A8 *state = &lbl_1_bss_6D7A8;
    state->unk_2 = arg1;
    state->unk_0 = arg0;
    state->unk_4 = arg2;
    state->unk_8 = arg0 * 64;
    state->unk_C = arg1 * 12;
    state->unk_10 = arg2 * 20;
    return state->unk_8 + state->unk_C + state->unk_10;
}
/* fzgx:end fn_1_7BA08 */

/* fzgx:begin fn_1_7BA48 */
extern u32 lbl_1_bss_6C8DC[2];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_727BC(u32 arg0, u32 arg1, void *arg2);
extern void fn_1_76A94(void *arg0, u32 arg1);
extern void fn_1_76DBC(void);
extern void fn_1_4E500(void);
extern void fn_1_4E638(int);
extern void fn_1_4E6F4(void);
extern void fn_80073778(void *arg0, int arg1);
extern s32 fn_1_A5D9C(void);
extern const f32 lbl_1_rodata_31AC;
extern u32 fn_80008E84(u32 arg);
extern void fn_1_77238(void);
extern void fn_1_772E0(void);
extern void fn_1_77384(void *arg);
extern void fn_80072864(int arg0);
extern void fn_800745A4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern void fn_80074660(int arg0);
extern void fn_80073678(int arg0);
extern void fn_80073898(int arg0);
extern void fn_80074788(int arg0);
extern void fn_800738E0(int arg0, int arg1, int arg2);
extern void fn_80073D60(int arg0, int arg1, int arg2, int arg3, int arg4);
extern void fn_800734A8(int arg0, int arg1, int arg2, int arg3);
extern void fn_80072EDC(int arg0, int arg1);
extern f32 lbl_1_rodata_31B0[10];
extern const f64 lbl_1_rodata_31A0;
extern void lbl_8006D784(f32 *arg);
extern void fn_80073A58(int arg0, f32 *arg1, int arg2);
extern void fn_800739E0(int arg0, int arg1, int arg2);
extern void GXLoadTexMtxImm(f32 *arg0, int arg1, int arg2);
extern void fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8006FD1C(void);
extern void fn_1_79810(void);
extern void fn_1_79948(void);
extern void fn_1_791B0(void);
extern void fn_1_9A1E8(void);
extern void fn_1_9A864(void);
extern u8 fn_1_7B074(void);
extern void fn_80071718(void *arg);
extern void fn_800711A8(void *arg);
extern void fn_1_14CB4(void);
extern void fn_1_FA84(void);
extern const f32 lbl_1_rodata_32CC;
extern void fn_1_79C88(void *arg0, s32 arg1, f32 arg2, s32 arg3);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void sprintf(char *dst, const char *format, ...);
extern void fn_1_465D0(char *text, int arg);
extern void fn_1_14D5C(void *object, int arg);
extern void fn_1_46EA8(int value);
extern void fn_1_12620(void *object);
extern void fn_1_46DC4(void *obj);

extern void fn_1_727BC();
extern void fn_8006FDEC(void);
extern void fn_80071718(void *);
extern void fn_800711A8(void *);
extern u32 fn_8003526C(u32, u32);
extern u32 fn_80074300(u32, u32, u32, u32);
extern u32 fn_80074438(u32, u32, u32, u32);

extern u32 lbl_1_bss_6C8DC[2];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_727BC(u32 arg0, u32 arg1, void *arg2);
extern void fn_1_76A94(void *arg0, u32 arg1);
extern void fn_1_76DBC(void);
extern void fn_1_4E500(void);
extern void fn_1_4E638(int);
extern void fn_1_4E6F4(void);
extern void fn_80073778(void *arg0, int arg1);
extern s32 fn_1_A5D9C(void);
extern const f32 lbl_1_rodata_31AC;
extern u32 fn_80008E84(u32 arg);
extern void fn_1_77238(void);
extern void fn_1_772E0(void);
extern void fn_1_77384(void *arg);
extern void fn_80072864(int arg0);
extern void fn_800745A4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern void fn_80074660(int arg0);
extern void fn_80073678(int arg0);
extern void fn_80073898(int arg0);
extern void fn_80074788(int arg0);
extern void fn_800738E0(int arg0, int arg1, int arg2);
extern void fn_80073D60(int arg0, int arg1, int arg2, int arg3, int arg4);
extern void fn_800734A8(int arg0, int arg1, int arg2, int arg3);
extern void fn_80072EDC(int arg0, int arg1);
extern f32 lbl_1_rodata_31B0[10];
extern const f64 lbl_1_rodata_31A0;
extern void lbl_8006D784(f32 *arg);
extern void fn_80073A58(int arg0, f32 *arg1, int arg2);
extern void fn_800739E0(int arg0, int arg1, int arg2);
extern void GXLoadTexMtxImm(f32 *arg0, int arg1, int arg2);
extern void fn_8006FDEC(void);
extern void fn_8006FEFC(void);
extern void fn_8006FD1C(void);
extern void fn_1_79810(void);
extern void fn_1_79948(void);
extern void fn_1_791B0(void);
extern void fn_1_9A1E8(void);
extern void fn_1_9A864(void);
extern u8 fn_1_7B074(void);
extern void fn_80071718(void *arg);
extern void fn_800711A8(void *arg);
extern void fn_1_14CB4(void);
extern void fn_1_FA84(void);
extern const f32 lbl_1_rodata_32CC;
extern void fn_1_79C88(void *arg0, s32 arg1, f32 arg2, s32 arg3);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void sprintf(char *dst, const char *format, ...);
extern void fn_1_465D0(char *text, int arg);
extern void fn_1_14D5C(void *object, int arg);
extern void fn_1_46EA8(int value);
extern void fn_1_12620(void *object);
extern void fn_1_46DC4(void *obj);

extern void fn_1_727BC();
extern void fn_8006FDEC(void);
extern void fn_80071718(void *);
extern void fn_800711A8(void *);
extern u32 fn_8003526C(u32, u32);
extern u32 fn_80074300(u32, u32, u32, u32);
extern u32 fn_80074438(u32, u32, u32, u32);


extern u32 fn_800793D4(u8 *, u32, u32);

typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u8 pad_1A[0x2];
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u16 unk_28[8];
    u32 unk_38;
} Fn17BA48State;


/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6D7A8[2];
u32 lbl_1_bss_6D7A8__fzgx_offset_8;
u32 lbl_1_bss_6D7A8__fzgx_offset_C;
u32 lbl_1_bss_6D7A8__fzgx_offset_10;
u16 lbl_1_bss_6D7A8__fzgx_offset_14;
u16 lbl_1_bss_6D7A8__fzgx_offset_16;
u16 lbl_1_bss_6D7C0;
u16 lbl_1_bss_6D7C0__fzgx_offset_2;
u32 lbl_1_bss_6D7C0__fzgx_offset_4;
u32 lbl_1_bss_6D7C0__fzgx_offset_8;
u32 lbl_1_bss_6D7C0__fzgx_offset_C;
u16 lbl_1_bss_6D7C0__fzgx_offset_10[8];
u32 lbl_1_bss_6D7C0__fzgx_offset_20;
u32 lbl_1_bss_6D7C0__fzgx_offset_24;
u32 fzgx_obj_lbl_1_bss_6D7E8[2];
u8 fzgx_obj_lbl_1_bss_6D7F0;
u8 fzgx_pool_lbl_1_bss_6D7A8_gap_6D7F1;
u16 fzgx_pool_lbl_1_bss_6D7A8_gap_6D7F1_fill_6D7F2;
u32 fzgx_obj_lbl_1_bss_6D7F4[11];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7A8;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_16;
    s = *(u8 *)&lbl_1_bss_6D7C0;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_20;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_24;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7E8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7F0;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6D7A8_gap_6D7F1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6D7A8_gap_6D7F1_fill_6D7F2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7F4;
}
#pragma section code_type ".text"

void fn_1_7BA48(u8 *arg0) {
    
    fn_800793D4(arg0, 0, ((lbl_1_bss_6D7A8__fzgx_offset_10) + ((lbl_1_bss_6D7A8__fzgx_offset_8) + (lbl_1_bss_6D7A8__fzgx_offset_C))));
    lbl_1_bss_6D7C0 = 0;
    lbl_1_bss_6D7A8__fzgx_offset_16 = 0;
    lbl_1_bss_6D7A8__fzgx_offset_14 = 0;
    lbl_1_bss_6D7C0__fzgx_offset_4 = (u32)arg0;
    lbl_1_bss_6D7C0__fzgx_offset_8 = (u32)arg0 + lbl_1_bss_6D7A8__fzgx_offset_8;
    lbl_1_bss_6D7C0__fzgx_offset_C = lbl_1_bss_6D7C0__fzgx_offset_8 + lbl_1_bss_6D7A8__fzgx_offset_C;
    lbl_1_bss_6D7C0__fzgx_offset_10[0] = 0xFFFF;
    lbl_1_bss_6D7C0__fzgx_offset_10[1] = 0xFFFF;
    lbl_1_bss_6D7C0__fzgx_offset_10[2] = 0xFFFF;
    lbl_1_bss_6D7C0__fzgx_offset_10[3] = 0xFFFF;
    lbl_1_bss_6D7C0__fzgx_offset_10[4] = 0xFFFF;
    lbl_1_bss_6D7C0__fzgx_offset_10[5] = 0xFFFF;
    lbl_1_bss_6D7C0__fzgx_offset_10[6] = 0xFFFF;
    lbl_1_bss_6D7C0__fzgx_offset_10[7] = 0xFFFF;
    lbl_1_bss_6D7C0__fzgx_offset_20 = 0;
}
/* fzgx:end fn_1_7BA48 */

/* fzgx:begin fn_1_7BAF8 noprologue */
#include "types.h"

extern u16 fn_800793D4(u8 *, u32, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_6D7A8[2];
u32 lbl_1_bss_6D7A8__fzgx_offset_8;
u32 lbl_1_bss_6D7A8__fzgx_offset_C;
u32 lbl_1_bss_6D7A8__fzgx_offset_10;
u16 lbl_1_bss_6D7A8__fzgx_offset_14;
u16 lbl_1_bss_6D7A8__fzgx_offset_16;
u16 lbl_1_bss_6D7C0;
u16 lbl_1_bss_6D7C0__fzgx_offset_2;
u32 lbl_1_bss_6D7C0__fzgx_offset_4[3];
u16 lbl_1_bss_6D7C0__fzgx_offset_10[8];
u32 lbl_1_bss_6D7C0__fzgx_offset_20;
u32 lbl_1_bss_6D7C0__fzgx_offset_24;
u32 fzgx_obj_lbl_1_bss_6D7E8[2];
u8 fzgx_obj_lbl_1_bss_6D7F0;
u8 fzgx_pool_lbl_1_bss_6D7A8_gap_6D7F1;
u16 fzgx_pool_lbl_1_bss_6D7A8_gap_6D7F2_fill;
u32 fzgx_obj_lbl_1_bss_6D7F4[11];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_6D7A8;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_C;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_6D7A8__fzgx_offset_16;
    s = *(u8 *)&lbl_1_bss_6D7C0;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_20;
    s = *(u8 *)&lbl_1_bss_6D7C0__fzgx_offset_24;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7E8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7F0;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6D7A8_gap_6D7F1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_6D7A8_gap_6D7F2_fill;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7F4;
}
#pragma section code_type ".text"

#pragma opt_strength_reduction off
void fn_1_7BAF8(u8 *arg0) {
    u16 *blk;
    u32 v1;

    fn_800793D4(arg0, 0, (lbl_1_bss_6D7A8__fzgx_offset_10) + (lbl_1_bss_6D7A8__fzgx_offset_8 + lbl_1_bss_6D7A8__fzgx_offset_C));
    v1 = 0x10000 - 1;
    lbl_1_bss_6D7C0 = 0;
    lbl_1_bss_6D7A8__fzgx_offset_16 = 0;
    lbl_1_bss_6D7A8__fzgx_offset_14 = 0;
    blk = &lbl_1_bss_6D7C0__fzgx_offset_10[0];
    blk[0] = v1;
    blk[1] = v1;
    blk[2] = v1;
    blk[3] = v1;
    blk[4] = v1;
    blk[5] = v1;
    blk[6] = v1;
    blk[7] = v1;
    lbl_1_bss_6D7C0__fzgx_offset_20 = 0;
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_7BAF8 */

/* fzgx:begin fn_1_7BB80 */
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_800356B8(void *, int);

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3c;
} Fn17BB80Entry;

typedef struct {
    u16 unk_0;
    u8 pad_2[0x12];
    u16 unk_14;
    u8 pad_16[0x6];
    Fn17BB80Entry *unk_1C;
    u8 pad_20[0x8];
    u16 unk_28[8];
} Fn17BB80State;

#pragma opt_propagation off
static inline void fn_1_7BB80_set(u16 val, u16 *arr, s32 off) {
    *(u16 *)((u8 *)arr + off) = val;
}
#pragma opt_propagation reset


static inline u16 * fn_1_7BB80_read_pointer(Fn17BB80State * owner) { return owner->unk_28; }
#pragma opt_dead_assignments off
#pragma opt_lifetimes off
void fn_1_7BB80(Fn17BB80Entry *arg0, s32 arg1) {
    Fn17BB80Entry * fzgx_live;
    u8 *data = (u8 *)&lbl_1_data_1E558;
    Fn17BB80State *bss = (Fn17BB80State *)&lbl_1_bss_6D7A8;
    s32 index;
    struct { u32 value; } lab_t2;

    if ((u32)bss->unk_14 >= bss->unk_0) {
        OSPanic((const char *)(data + 0x8ec), 0x79, (const char *)(data + 0x8f4));
    }

    fzgx_live = bss->unk_1C;
    fzgx_live[bss->unk_14] = *arg0;
    index = 31 - __cntlzw(arg1);

    if (index > 7 || index < 0) {
        OSPanic((const char *)(data + 0x8ec), 0x30, (const char *)(0x904 + data));
    }

    fn_1_7BB80_set(bss->unk_14, fn_1_7BB80_read_pointer(bss), (lab_t2.value = index << 1));
    fn_800356B8(arg0, arg1);
    bss->unk_14++;
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_7BB80 */

/* fzgx:begin fn_1_7BD6C */
extern void OSPanic(const char *, int, const char *, ...);
extern s32 fn_80074D08(u32);

static inline s32 highest_bit(u32 value, u8 *data) {
    s32 highest = 31 - __cntlzw(value);
    if (highest > 7 || highest < 0) {
        OSPanic((const char *)(data + 0x8ec), 0x30, (const char *)(data + 0x904));
    }
    return highest;
}

u32 fn_1_7BD6C(s32 value) {
    s32 highest;
    struct { u16 *value; } map;
    s32 bit;
    u16 *entries;
    u32 result;
    u8 *data = lbl_1_data_1E558;
    u8 *state = (u8 *)&lbl_1_bss_6D7A8;

    if (*(u16 *)(state + 0x18) >= lbl_1_bss_6D7A8.unk_4) {
        OSPanic((const char *)(data + 0x8ec), 0xa5, (const char *)(data + 0x92c));
    }
    entries = (u16 *)(*(u32 *)(state + 0x24) + *(u16 *)(state + 0x18) * 0x14);
    entries[0] = (u16)value;
    entries[1] = ((Obj_1_bss_6D7A8 *)state)->unk_16 - 1;
    *(u32 *)(state + 0x38) = value;
    result = fn_80074D08(value);
    highest = highest_bit(value, data);
    bit = highest;
    map.value = (u16 *)(state + 0x28);
    highest = 1;
    while (bit >= 0) {
        if (map.value[bit] == 0xffff) {
            OSPanic((const char *)(data + 0x8ec), 0xb1, (const char *)(data + 0x940));
        }
        entries[bit + 2] = map.value[bit];
        value = value & ~(highest << bit);
        bit = 31 - __cntlzw(value);
    }
    *(u16 *)(state + 0x18) += 1;
    return result;
}
/* fzgx:end fn_1_7BD6C */
