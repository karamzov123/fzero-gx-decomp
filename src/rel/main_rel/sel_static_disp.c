#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern Word8 lbl_1_rodata_86D8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern f32 lbl_1_rodata_26F8[22];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern u16 fn_1_486C4(u32 value);
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_88B4;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_88B8;
extern const u32 lbl_1_rodata_8860[6];
extern const u32 lbl_1_rodata_8878[6];
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_48690(u32 unused);
extern void fn_1_52070(u32 value);
extern void fn_1_135D7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_4965C(u8 value);
extern void fn_1_495C8(void* arg0);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 value);
extern void fn_1_49590(f32 value);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A28;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern s32 lbl_1_rodata_8A34;
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_5233C(void* arg0, void* arg1);
extern u32 fn_1_12F118(void);
extern u8* fn_1_36AD0();
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_137364();
extern void fn_1_14E9E4(int arg0, void *arg1);
extern const f32 lbl_1_rodata_8840;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_85F4;
extern int fn_1_D6698(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern void fn_1_139440(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
extern s32 lbl_1_bss_8E3D0[];
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_8BA8;
extern const f32 lbl_1_rodata_8664;
extern const f32 lbl_1_rodata_8BAC;
extern const f32 lbl_1_rodata_8BB0;
extern const f32 lbl_1_rodata_8BB4;
extern const f32 lbl_1_rodata_87D0;
extern int fn_1_D6740();
extern int fn_1_D66B0(void);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern u8 lbl_1_rodata_8558[84];
extern const f32 lbl_1_rodata_8C10;
extern void fn_1_4CF3C(const char *format, f32 x, ...);
extern s16 fn_1_12C930(void* arg0);
extern u8 lbl_1_data_21078[180];
extern f32 fn_1_4B068(const char*);
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8C74;
extern PtrTab lbl_1_rodata_8C4C;
extern s32 fn_1_13B548(s32, s32, s32, u8);
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8D78;
extern const f32 lbl_1_rodata_8D7C;
extern u16 lbl_1_rodata_8CB0[200];
extern u8 lbl_1_bss_9C;
extern void fn_1_133E04(void* arg0, s32 arg1);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_140EE8(u8 arg0, int arg1, int arg2);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern void fn_1_138144(void* arg0, int arg1);
extern u32 fn_1_13C5EC(u8);
extern u32 fn_1_13F7F8(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8DBC;
extern const f32 lbl_1_rodata_8DCC;
extern const f32 lbl_1_rodata_87B4;
extern const u32 lbl_1_rodata_8DC0;
extern const f32 lbl_1_rodata_8818;
extern const u32 lbl_1_rodata_8DC4;
extern const f32 lbl_1_rodata_8DD0;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8A58;
extern int fn_1_B7E98(int index);
extern void fn_1_13EE60();
extern u32 fn_1_13EF64(u32, u32, u32, void *, u32, void *, u32, f32);
extern u32 lbl_1_rodata_8E8C;
extern u8 lbl_1_rodata_8EB4[];
extern char *fn_80083DB0(char *dst, const char *src);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 lbl_1_rodata_91C0[11];
extern const f32 lbl_1_rodata_91EC;
extern const f32 lbl_1_rodata_91F0;
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern void fn_1_494DC(s16 index);
extern const f32 lbl_1_rodata_9208;
extern void fn_1_4966C(f32 value1, f32 value2);
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern const f32 lbl_1_rodata_8E9C;
extern const f64 lbl_1_rodata_93E8;
extern f32 lbl_1_rodata_93F0[15];
extern f32 lbl_1_rodata_92C0[22];
extern f32 lbl_1_rodata_970C[71];
extern const f32 lbl_1_rodata_946C;
extern void fn_1_149C2C();
extern struct fn_1_149C64_lbl_1_bss_8E43C lbl_1_bss_8E43C;
extern struct fn_1_149C64_lbl_1_bss_8E440 lbl_1_bss_8E440;
extern void fn_1_149CA4(u32, u32, u32, u32);
extern void fn_1_520A0(void);
extern f64 lbl_1_rodata_9480[80];
extern f32 lbl_1_rodata_942C[16];
extern f32 fn_1_521B8(s32 value);
extern f32 fn_1_520F8(s32 value);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_1_520CC(void);
extern const f32 lbl_1_rodata_99A4;
extern u8 fn_1_5910(void);
extern u8 fn_1_149FB4(s32 index);
extern s32 fn_1_3F864(void);
extern void fn_1_A52B0(s32 index);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 fn_1_1556B4(u32, u32);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0();
extern s16 fn_1_14F344(s16);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void fn_1_151C3C(u16 value1, u16 value2);
extern void fn_1_556B8(void *value);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern const f64 lbl_1_rodata_B8D0;
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *fn_800839D8(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_1375C0(int arg0, void* arg1, void* arg2, void* arg3, void* arg4);
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern void fn_1_131B90(void);
extern void fn_1_13A9B8();
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void fn_1_13E080(void* arg0, void* arg1, void* arg2, int arg3);
extern void fn_1_144F40(u32 arg0, u32 arg1);
extern u8 fn_1_155F8C(void);
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, u32 arg3);
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);
extern s32 fn_1_45D0();
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 fn_80008BEC(u32 arg0, int arg1, int arg2);
extern void fn_1_7F3AC(void* object);

/* fzgx:begin fn_1_1332FC */
typedef struct {
    u32 v[8];
} Word32;


void fn_1_1332FC(s32 left, s32 top, u8 page) {
    Word32 table;
    FontDrawPacket packet;
    u32 image;
    s32 y;
    s32 j;
    s32 i;
    s32 *entry;

    table = *(Word32 *)&lbl_1_rodata_86D8;
    if (page >= 2U) {
        OSPanic((const char *)(((u8 *)&lbl_1_data_419E0)), 0x3E9, (const char *)(((u8 *)&lbl_1_data_419F4)));
    }

    image = 0x10000 - 0x62FD;
    y = top;
    for (i = 0; i < 5; i++) {
        packet = *(FontDrawPacket *)&(*((u32 *)&lbl_1_rodata_26F8));
        packet.image = image;
        fn_1_51678(&packet, packet.image, 0, 0, 8, 0x60);
        packet.x = (f32)left;
        packet.y = (f32)y;
        packet.z = lbl_1_rodata_86F8;
        fn_1_4F734(&packet);
        y += 0x60;
    }

    entry = (s32 *)((u8 *)&table + page * 0x10);
    for (j = 0; j < 4; j++) {
        packet = *(FontDrawPacket *)&(*((u32 *)&lbl_1_rodata_26F8));
        packet.image = image;
        fn_1_51678(&packet, packet.image, 0, 0x60, 8, 0xC);
        packet.x = (f32)left;
        packet.y = (f32)(top + *entry);
        packet.z = lbl_1_rodata_86FC;
        fn_1_4F734(&packet);
        entry++;
    }
}
/* fzgx:end fn_1_1332FC */

/* fzgx:begin fn_1_13354C */
typedef struct {
    u32 v[16];
} Defaults;

void fn_1_13354C(s32 arg0, s32 arg1, u32 arg2) {
    Defaults defaults;
    FontDrawPacket packet;
    s16 *entry;
    u32 raw;
    s32 i;
    u32 sel;
    s32 acc;
    u32 magic;

    raw = arg2;
    acc = 0;
    defaults = *(Defaults *)lbl_1_rodata_8700;

    if ((u8)arg2 >= 2) {
        OSPanic((const char *)lbl_1_data_419E0, 0x427, (const char *)lbl_1_data_41A10);
    }

    sel = raw & 0xff;
    entry = (s16 *)((u8 *)&defaults + ((raw & 0xff) << 5));
    magic = 0x10000 - 0x62f7;

    for (i = 0; i < 4; i++) {
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x10000 - 0x62f7;
        fn_1_51678(&packet, packet.image, entry[0], entry[1], entry[2], entry[3]);
        packet.x = (f32)arg0;
        packet.y = (f32)(arg1 + acc);
        acc += entry[3];
        packet.z = lbl_1_rodata_8740;
        if (sel == 1) {
            *(u32 *)((u8 *)&packet + 0x30) = 7;
        } else {
            *(u32 *)((u8 *)&packet + 0x30) = 5;
        }
        fn_1_4F734(&packet);
        entry += 4;
    }
}
/* fzgx:end fn_1_13354C */

/* fzgx:begin fn_1_133748 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"
#include "types.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern Word8 lbl_1_rodata_86D8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern f32 lbl_1_rodata_26F8[22];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern u16 fn_1_486C4(u32 value);
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_88B4;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_88B8;
extern const u32 lbl_1_rodata_8860[6];
extern const u32 lbl_1_rodata_8878[6];
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_48690(u32 unused);
extern void fn_1_52070(u32 value);
extern void fn_1_135D7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_4965C(u8 value);
extern void fn_1_495C8(void* arg0);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 value);
extern void fn_1_49590(f32 value);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A28;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern s32 lbl_1_rodata_8A34;
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_5233C(void* arg0, void* arg1);
extern u32 fn_1_12F118(void);
extern u8* fn_1_36AD0();
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_137364();
extern void fn_1_14E9E4(int arg0, void *arg1);
extern const f32 lbl_1_rodata_8840;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_85F4;
extern int fn_1_D6698(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern void fn_1_139440(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
extern s32 lbl_1_bss_8E3D0[];
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_8BA8;
extern const f32 lbl_1_rodata_8664;
extern const f32 lbl_1_rodata_8BAC;
extern const f32 lbl_1_rodata_8BB0;
extern const f32 lbl_1_rodata_8BB4;
extern const f32 lbl_1_rodata_87D0;
extern int fn_1_D6740();
extern int fn_1_D66B0(void);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern u8 lbl_1_rodata_8558[84];
extern const f32 lbl_1_rodata_8C10;
extern void fn_1_4CF3C(const char *format, f32 x, ...);
extern s16 fn_1_12C930(void* arg0);
extern u8 lbl_1_data_21078[180];
extern f32 fn_1_4B068(const char*);
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8C74;
extern PtrTab lbl_1_rodata_8C4C;
extern s32 fn_1_13B548(s32, s32, s32, u8);
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8D78;
extern const f32 lbl_1_rodata_8D7C;
extern u16 lbl_1_rodata_8CB0[200];
extern u8 lbl_1_bss_9C;
extern void fn_1_133E04(void* arg0, s32 arg1);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_140EE8(u8 arg0, int arg1, int arg2);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern void fn_1_138144(void* arg0, int arg1);
extern u32 fn_1_13C5EC(u8);
extern u32 fn_1_13F7F8(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8DBC;
extern const f32 lbl_1_rodata_8DCC;
extern const f32 lbl_1_rodata_87B4;
extern const u32 lbl_1_rodata_8DC0;
extern const f32 lbl_1_rodata_8818;
extern const u32 lbl_1_rodata_8DC4;
extern const f32 lbl_1_rodata_8DD0;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8A58;
extern int fn_1_B7E98(int index);
extern void fn_1_13EE60();
extern u32 fn_1_13EF64(u32, u32, u32, void *, u32, void *, u32, f32);
extern u32 lbl_1_rodata_8E8C;
extern u8 lbl_1_rodata_8EB4[];
extern char *fn_80083DB0(char *dst, const char *src);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 lbl_1_rodata_91C0[11];
extern const f32 lbl_1_rodata_91EC;
extern const f32 lbl_1_rodata_91F0;
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern void fn_1_494DC(s16 index);
extern const f32 lbl_1_rodata_9208;
extern void fn_1_4966C(f32 value1, f32 value2);
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern const f32 lbl_1_rodata_8E9C;
extern const f64 lbl_1_rodata_93E8;
extern f32 lbl_1_rodata_93F0[15];
extern f32 lbl_1_rodata_92C0[22];
extern f32 lbl_1_rodata_970C[71];
extern const f32 lbl_1_rodata_946C;
extern void fn_1_149C2C();
extern struct fn_1_149C64_lbl_1_bss_8E43C lbl_1_bss_8E43C;
extern struct fn_1_149C64_lbl_1_bss_8E440 lbl_1_bss_8E440;
extern void fn_1_149CA4(u32, u32, u32, u32);
extern void fn_1_520A0(void);
extern f64 lbl_1_rodata_9480[80];
extern f32 lbl_1_rodata_942C[16];
extern f32 fn_1_521B8(s32 value);
extern f32 fn_1_520F8(s32 value);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_1_520CC(void);
extern const f32 lbl_1_rodata_99A4;
extern u8 fn_1_5910(void);
extern u8 fn_1_149FB4(s32 index);
extern s32 fn_1_3F864(void);
extern void fn_1_A52B0(s32 index);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 fn_1_1556B4(u32, u32);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0();
extern s16 fn_1_14F344(s16);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void fn_1_151C3C(u16 value1, u16 value2);
extern void fn_1_556B8(void *value);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern const f64 lbl_1_rodata_B8D0;
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *fn_800839D8(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_1375C0(int arg0, void* arg1, void* arg2, void* arg3, void* arg4);
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern void fn_1_131B90(void);
extern void fn_1_13A9B8();
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void fn_1_13E080(void* arg0, void* arg1, void* arg2, int arg3);
extern void fn_1_144F40(u32 arg0, u32 arg1);
extern u8 fn_1_155F8C(void);
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, u32 arg3);
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);
extern s32 fn_1_45D0();
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 fn_80008BEC(u32 arg0, int arg1, int arg2);
extern void fn_1_7F3AC(void* object);


typedef struct { s32 a[4]; } fn_1_133748_Offsets;

extern u32 lbl_1_rodata_8744[4];
extern f32 lbl_1_rodata_26F8[22];

void fn_1_133748(s32 x, s32 y) {
    fn_1_133748_Offsets offs;
    FontDrawPacket pkt;
    s32 i;

    offs = *(fn_1_133748_Offsets *)lbl_1_rodata_8744;
    for (i = 0; i < 6; i++) {
        pkt = *(FontDrawPacket *)lbl_1_rodata_26F8;
        pkt.image = 0x9D03;
        fn_1_51678(&pkt, pkt.image, 0, 0, 8, 96);
        pkt.x = (f32)(x + i * 96);
        pkt.y = (f32)y;
        pkt.z = 200.0f;
        pkt.rotation_z = -0x4000;
        pkt.flags = 0x100000;
        fn_1_4F734(&pkt);
    }
    for (i = 0; i < 4; i++) {
        pkt = *(FontDrawPacket *)lbl_1_rodata_26F8;
        pkt.image = 0x9D03;
        fn_1_51678(&pkt, pkt.image, 0, 96, 8, 12);
        pkt.x = (f32)(x + offs.a[i] - 85);
        pkt.y = (f32)y;
        pkt.z = 180.0f;
        pkt.rotation_z = -0x4000;
        pkt.flags = 0x100000;
        fn_1_4F734(&pkt);
    }
}
/* fzgx:end fn_1_133748 */

/* fzgx:begin fn_1_133968 */
typedef struct {
    s16 v[9];
} IdTable;


void fn_1_133968(void) {
    IdTable ids;
    FontDrawPacket packet;
    u32 i;

    ids = *(IdTable *)lbl_1_rodata_8754;

    for (i = 0; i < 9; i++) {
        packet = *(FontDrawPacket *)&(*((u32 *)&lbl_1_rodata_26F8));
        packet.image = (0x10000 - 26096);
        packet.x = (f32)ids.v[i];
        packet.y = lbl_1_rodata_8768;
        packet.z = lbl_1_rodata_876C;
        fn_1_4F734(&packet);
    }
}
/* fzgx:end fn_1_133968 */

/* fzgx:begin fn_1_133A8C */
void fn_1_133A8C(void) {
    FontDrawPacket packet;
    s16 result;

    packet = *(FontDrawPacket *)&(*((u32 *)&lbl_1_rodata_26F8));
    packet.image = (0x10000 - 0x6300);
    result = fn_1_486C4(packet.image);
    fn_1_51678(&packet, packet.image, 0, 0, 0x14, result);
    packet.x = lbl_1_rodata_8770;
    packet.y = lbl_1_rodata_8774;
    packet.z = lbl_1_rodata_86FC;
    *(u32 *)((u8 *)&packet + 0x30) = 0xa;
    fn_1_4F734(&packet);

    packet = *(FontDrawPacket *)&(*((u32 *)&lbl_1_rodata_26F8));
    packet.image = (0x10000 - 0x6300);
    result = fn_1_486C4(packet.image);
    fn_1_51678(&packet, packet.image, 0x32, 0, 0x12, result);
    packet.x = lbl_1_rodata_8778;
    packet.y = lbl_1_rodata_8774;
    packet.z = lbl_1_rodata_86FC;
    *(u32 *)((u8 *)&packet + 0x30) = 0xa;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_133A8C */

/* fzgx:begin fn_1_133BD8 */
typedef union {
    u32 raw[22];
    struct {
        s32 value;
        f32 x;
        f32 y;
        f32 z;
        u8 pad[32];
        s32 count;
    } obj;
} Local;

void fn_1_133BD8(void) {
    Local local;
    s16 result;

    local = *(Local *)lbl_1_rodata_26F8;
    local.obj.value = 0x9d00;
    result = (s16)fn_1_486C4(0x9d00);
    fn_1_51678( (FontDrawPacket*)(void*)(&local.obj.value), local.obj.value, 0, 0, 0x14, result);
    local.obj.x = lbl_1_rodata_8770;
    local.obj.y = lbl_1_rodata_8774;
    local.obj.z = lbl_1_rodata_86FC;
    local.obj.count = 10;
    fn_1_4F734( (FontDrawPacket*)(void*)(&local.obj.value));

    local = *(Local *)lbl_1_rodata_26F8;
    local.obj.value = 0x9d00;
    result = (s16)fn_1_486C4(0x9d00);
    fn_1_51678( (FontDrawPacket*)(void*)(&local.obj.value), local.obj.value, 0x14, 0, 0x1c, result);
    local.obj.x = lbl_1_rodata_8658;
    local.obj.y = lbl_1_rodata_8774;
    local.obj.z = lbl_1_rodata_86FC;
    local.obj.count = 10;
    fn_1_4F734( (FontDrawPacket*)(void*)(&local.obj.value));

    local = *(Local *)lbl_1_rodata_26F8;
    local.obj.value = 0x9d00;
    result = (s16)fn_1_486C4(0x9d00);
    fn_1_51678( (FontDrawPacket*)(void*)(&local.obj.value), local.obj.value, 0x32, 0, 0x12, result);
    local.obj.x = lbl_1_rodata_8778;
    local.obj.y = lbl_1_rodata_8774;
    local.obj.z = lbl_1_rodata_86FC;
    local.obj.count = 10;
    fn_1_4F734( (FontDrawPacket*)(void*)(&local.obj.value));
}
/* fzgx:end fn_1_133BD8 */

/* fzgx:begin fn_1_133DBC */
void fn_1_133DBC(void* arg0) {
    fn_1_133E04(arg0, 0);
}
/* fzgx:end fn_1_133DBC */

/* fzgx:begin fn_1_133DE0 */
void fn_1_133DE0(void* arg0) {
    fn_1_133E04(arg0, 1);
}
/* fzgx:end fn_1_133DE0 */

/* fzgx:begin fn_1_134A4C */
void fn_1_134A4C(void) {
    StaticDispParams params;

    params = (*((StaticDispParams *)&lbl_1_rodata_26F8));
    params.id = 0x9a14;
    params.x = lbl_1_rodata_882C;
    params.y = lbl_1_rodata_8830;
    params.z = lbl_1_rodata_8834;
    params.count = 10;
    fn_1_4F734( (FontDrawPacket*)(void*)(&params.id));
}
/* fzgx:end fn_1_134A4C */

/* fzgx:begin fn_1_134AD4 noprologue */
#include "types.h"
#include "font.h"

extern FontDrawPacket lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_85F4;
extern int fn_1_4F734(FontDrawPacket *);
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_8838;
extern const f32 lbl_1_rodata_883C;
extern const f32 lbl_1_rodata_8840;
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_486C4(u32);
extern u32 fn_1_48690(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_8848;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_8850;
extern const f32 lbl_1_rodata_885C;
extern const f32 lbl_1_rodata_8854;
extern const f32 lbl_1_rodata_8858;

void fn_1_134AD4(void) {
	FontDrawPacket p;

	p = lbl_1_rodata_26F8;
	p.image = 0x10000 - 0x65FC;
	p.x = lbl_1_rodata_861C;
	p.y = lbl_1_rodata_861C;
	p.z = lbl_1_rodata_85F4;
	fn_1_4F734(&p);

	p = lbl_1_rodata_26F8;
	p.image = 0x10000 - 0x65FB;
	p.x = lbl_1_rodata_8658;
	p.y = lbl_1_rodata_861C;
	p.z = lbl_1_rodata_8838;
	fn_1_4F734(&p);

	p = lbl_1_rodata_26F8;
	p.image = 0x10000 - 0x65FF;
	p.x = lbl_1_rodata_861C;
	p.y = lbl_1_rodata_883C;
	p.z = lbl_1_rodata_8840;
	fn_1_4F734(&p);

	if ((s8)fn_1_A5DC4() != 0) {
		p = lbl_1_rodata_26F8;
		p.image = 0x10000 - 0x65FA;
		fn_1_51678(&p, p.image, 0, 0,
			(s16)((fn_1_48690(p.image) >> 1) & 0x7FFF),
			(s16)fn_1_486C4(p.image));
		p.x = lbl_1_rodata_8844;
		p.y = lbl_1_rodata_861C;
		p.z = lbl_1_rodata_8848;
		fn_1_4F734(&p);

		p = lbl_1_rodata_26F8;
		p.image = 0x10000 - 0x65FA;
		fn_1_51678(&p, p.image,
			(s16)((fn_1_48690(p.image) >> 1) & 0x7FFF), 0,
			(s16)((fn_1_48690(p.image) >> 1) & 0x7FFF),
			(s16)fn_1_486C4(p.image));
		p.x = lbl_1_rodata_884C;
		p.y = lbl_1_rodata_861C;
		p.z = lbl_1_rodata_8850;
		p.flags = 7;
		fn_1_4F734(&p);

		p = lbl_1_rodata_26F8;
		p.image = 0x10000 - 0x65FD;
		fn_1_51678(&p, p.image, 0, 0,
			(s16)((fn_1_48690(p.image) >> 1) & 0x7FFF),
			(s16)fn_1_486C4(p.image));
		p.x = lbl_1_rodata_8844;
		p.y = lbl_1_rodata_8854;
		p.z = lbl_1_rodata_8858;
		p.scale_y = p.scale_y * lbl_1_rodata_885C;
		fn_1_4F734(&p);

		p = lbl_1_rodata_26F8;
		p.image = 0x10000 - 0x65FD;
		fn_1_51678(&p, p.image,
			(s16)((fn_1_48690(p.image) >> 1) & 0x7FFF), 0,
			(s16)((fn_1_48690(p.image) >> 1) & 0x7FFF),
			(s16)fn_1_486C4(p.image));
		p.x = lbl_1_rodata_884C;
		p.y = lbl_1_rodata_8854;
		p.z = lbl_1_rodata_8858;
		p.scale_y = p.scale_y * lbl_1_rodata_885C;
		p.flags = 7;
		fn_1_4F734(&p);
	}
}
/* fzgx:end fn_1_134AD4 */

/* fzgx:begin fn_1_134EE4 */
#pragma opt_strength_reduction on
void fn_1_134EE4(s32 arg0, s32 arg1, s32 arg2, f32 farg0) {
    FontDrawPacket packet;
    s16 temp_r21;
    s16 temp_r22;
    s16 temp_r24;
    f32 temp_f30;
    f32 temp_f31;
    f32 temp_f28;
    FontDrawPacket * lab_t0;
    FontDrawPacket * lab_t0_;

    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = (arg1 != 0) ? 0x9E03 : 0x9B00;
    packet.x = lbl_1_rodata_861C;
    packet.y = lbl_1_rodata_8890;
    packet.z = lbl_1_rodata_8894;
    fn_1_4F734(&packet);
    if (arg0 != 0) {
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x9C02;
        packet.x = (f32)((s8)fn_1_A5DC4() ? 0x48 : 0x58);
        packet.y = lbl_1_rodata_8898;
        packet.z = lbl_1_rodata_889C;
        *(u32 *)((u8 *)&packet + 0x30) = 0xA;
        fn_1_4F734(&packet);
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x9C03;
        packet.x = lbl_1_rodata_8674 - (f32)((s8)fn_1_A5DC4() ? 0x48 : 0x58);
        packet.y = lbl_1_rodata_8898;
        packet.z = lbl_1_rodata_889C;
        *(u32 *)((u8 *)&packet + 0x30) = 0xA;
        fn_1_4F734(&packet);
        if (farg0 < lbl_1_rodata_85F0) {
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9C00;
            packet.x = (f32)(((s8)fn_1_A5DC4() ? 0x48 : 0x58) - 0x39);
            packet.y = lbl_1_rodata_8898;
            packet.z = lbl_1_rodata_88A0;
            *(u32 *)((u8 *)&packet + 0x30) = 9;
            fn_1_4F734(&packet);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9C01;
            packet.x = (f32)(((s8)fn_1_A5DC4() ? 0x48 : 0x58) + 0x3A);
            packet.y = lbl_1_rodata_8898;
            packet.z = lbl_1_rodata_88A4;
            *(u32 *)((u8 *)&packet + 0x30) = 0xB;
            fn_1_4F734(&packet);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9C00;
            packet.x = lbl_1_rodata_88A8 +
                       ((lbl_1_rodata_8674 - (f32)((s8)fn_1_A5DC4() ? 0x48 : 0x58)) -
                        lbl_1_rodata_88AC);
            packet.y = lbl_1_rodata_8898;
            packet.z = lbl_1_rodata_88A0;
            *(u32 *)((u8 *)&packet + 0x30) = 9;
            fn_1_4F734(&packet);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9C01;
            packet.x = lbl_1_rodata_88B0 +
                       ((lbl_1_rodata_8674 - (f32)((s8)fn_1_A5DC4() ? 0x48 : 0x58)) -
                        lbl_1_rodata_88AC);
            packet.y = lbl_1_rodata_8898;
            packet.z = lbl_1_rodata_88A4;
            *(u32 *)((u8 *)&packet + 0x30) = 0xB;
            fn_1_4F734(&packet);
        }
    }
    if ((s8)fn_1_A5DC4() != 0) {
        if (arg2 != 0) {
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9B02;
            temp_r21 = fn_1_486C4(0x9B02);
            lab_t0 = &packet;
            lab_t0_ = lab_t0;
            fn_1_51678(lab_t0_, packet.image, 0, 0, (fn_1_48690(packet.image) >> 1) & 0x7FFF, temp_r21);
            packet.x = lbl_1_rodata_8844;
            packet.y = lbl_1_rodata_86C8;
            packet.z = lbl_1_rodata_88B4;
            fn_1_4F734(&packet);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9B02;
            lab_t0 = &packet;
            lab_t0_ = lab_t0;
            fn_1_51678(lab_t0_, packet.image, 0, 0, 0xA, fn_1_486C4(0x9B02));
            packet.x = lbl_1_rodata_861C;
            packet.y = lbl_1_rodata_86C8;
            packet.z = lbl_1_rodata_88B4;
            fn_1_4F734(&packet);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9B02;
            temp_r22 = fn_1_486C4(0x9B02);
            temp_r21 = (fn_1_48690(packet.image) >> 1) & 0x7FFF;
            lab_t0 = &packet;
            lab_t0_ = lab_t0;
            fn_1_51678(lab_t0_, packet.image, (fn_1_48690(packet.image) >> 1) & 0x7FFF, 0, temp_r21, temp_r22);
            packet.x = lbl_1_rodata_884C;
            packet.y = lbl_1_rodata_86C8;
            packet.z = lbl_1_rodata_88B4;
            *(u32 *)((u8 *)&packet + 0x30) = 7;
            fn_1_4F734(&packet);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9B02;
            lab_t0 = &packet;
            lab_t0_ = lab_t0;
            fn_1_51678(lab_t0_, packet.image, 0, 0, 0xA, fn_1_486C4(0x9B02));
            packet.x = lbl_1_rodata_8674;
            packet.y = lbl_1_rodata_86C8;
            packet.z = lbl_1_rodata_88B4;
            *(u32 *)((u8 *)&packet + 0x30) = 7;
            fn_1_4F734(&packet);
        }
{
    s32 var_r26;
    s32 var_r25;
    struct { u32 * value; } var_r28;
    struct { u32 * value; } var_r27;
        u32 sp20[6] = {0x0, 0x18, 0x18, 0x18, 0x18, 0x28};
        u32 sp8[6] = {0x18, 0x10, 0x10, 0x10, 0x10, 0x20};
        var_r25 = 0x152;
        var_r26 = 0;
        var_r28.value = sp8;
        var_r27.value = sp20;
        for (; var_r26 < 6; var_r26++) {
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9B01;
            lab_t0 = &packet;
            lab_t0_ = lab_t0;
            fn_1_51678(lab_t0_, packet.image, 0, var_r27.value[0], (fn_1_48690(packet.image) >> 1) & 0x7FFF, var_r28.value[0]);
            packet.x = lbl_1_rodata_8844;
            packet.y = (f32)var_r25;
            packet.z = lbl_1_rodata_88B8;
            fn_1_4F734(&packet);
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9B01;
            arg0 = (s16)((fn_1_48690(packet.image) >> 1) & 0x7FFF);
            lab_t0 = &packet;
            lab_t0_ = lab_t0;
            fn_1_51678(lab_t0_, packet.image, (fn_1_48690(packet.image) >> 1) & 0x7FFF, var_r27.value[0], arg0, var_r28.value[0]);
            packet.x = lbl_1_rodata_884C;
            packet.y = (f32)var_r25;
            packet.z = lbl_1_rodata_88B8;
            *(u32 *)((u8 *)&packet + 0x30) = 7;
            fn_1_4F734(&packet);
            var_r27.value += 1;
            var_r25 += var_r28.value[0];
            var_r28.value += 1;
        }
}
        fn_1_52070(0x140);
    }
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_134EE4 */

/* fzgx:begin fn_1_135894 */
void fn_1_135894(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8) { fn_1_135D7C(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, lbl_1_rodata_87DC);
}
/* fzgx:end fn_1_135894 */

/* fzgx:begin fn_1_1358BC noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

typedef struct fn_1_1358BC_Table { u32 image[41]; } fn_1_1358BC_Table;

extern fn_1_1358BC_Table lbl_1_rodata_88BC;
extern FontDrawPacket lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_8960;
extern void fn_1_49410(void);
extern void fn_1_495C8(int);
extern void fn_1_494DC(int);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4962C(void);
extern char* fn_1_14FEAC(void*, void*, void*, void*, int);
extern void fn_1_4CF3C(f32, void*, ...);

void fn_1_1358BC(s16 arg0, s16 arg1, int arg2, s16 arg3, int unused, void* arg5,
                 void* arg6, void* arg7, f32 arg8, f32 arg9, f32 arg10) {
    u32 buf[8];
    FontDrawPacket packet;
    fn_1_1358BC_Table table;
    u32 index;

    table = lbl_1_rodata_88BC;

    if (arg3 >= 41 || arg3 < 0) {
        fn_1_49410();
        switch (arg2) {
        case 5: fn_1_495C8(0); break;
        case 9: fn_1_495C8(8); break;
        case 13: fn_1_495C8(0x10); break;
        case 6: fn_1_495C8(1); break;
        case 10: fn_1_495C8(9); break;
        case 14: fn_1_495C8(0x11); break;
        case 7: fn_1_495C8(2); break;
        case 11: fn_1_495C8(0xa); break;
        case 15: fn_1_495C8(0x12); break;
        }
        fn_1_494DC(0x23);
        fn_1_496FC((f32)arg0, (f32)arg1);
        fn_1_4954C(arg10);
        fn_1_4955C(arg8, arg9);
        fn_1_4962C();
        {
            const f32* scale = &lbl_1_rodata_8960;
            fn_1_4CF3C(*scale * arg8, &lbl_1_data_41A30,
                       fn_1_14FEAC(arg5, arg6, arg7, buf, 0));
        }
    } else {
        packet = lbl_1_rodata_26F8;
        if (arg3 < 0) {
            index = 0;
        } else {
            index = ((u32)arg3 > 40) ? 40 : arg3;
        }
        packet.image = table.image[index];
        packet.x = (f32)arg0;
        packet.y = (f32)arg1;
        packet.z = arg10;
        packet.scale_x = packet.scale_x * arg8;
        packet.scale_y = packet.scale_y * arg9;
        packet.flags = arg2;
        fn_1_4F734(&packet);
    }
}
/* fzgx:end fn_1_1358BC */

/* fzgx:begin fn_1_135B80 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern void fn_1_49410(void);
extern void fn_1_495C8(int);
extern void fn_1_494DC(int);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4962C(void);
extern char* fn_1_14FEAC(void*, void*, void*, void*, int);
extern char* fn_1_7F49C(s16, int, void*);
extern void fn_1_4CF3C(f32, void*, ...);
extern const f32 lbl_1_rodata_8960[];

void fn_1_135B80(f32 scale, f32 arg7, f32 arg8, s16 x, s16 y, u32 mode, s16 index,
                 u32 unused, void* a, void* b, void* c) {
    u8 buf1[0x20];
    u8 buf2[0x40];
    char* str;

    fn_1_49410();
    switch (mode) {
    case 5:
        fn_1_495C8(0);
        break;
    case 9:
        fn_1_495C8(8);
        break;
    case 13:
        fn_1_495C8(0x10);
        break;
    case 6:
        fn_1_495C8(1);
        break;
    case 10:
        fn_1_495C8(9);
        break;
    case 14:
        fn_1_495C8(0x11);
        break;
    case 7:
        fn_1_495C8(2);
        break;
    case 11:
        fn_1_495C8(0xa);
        break;
    case 15:
        fn_1_495C8(0x12);
        break;
    }
    fn_1_494DC(0x1c);
    fn_1_496FC((f32)x, (f32)y);
    fn_1_4954C(arg8);
    fn_1_4955C(scale, arg7);
    fn_1_4962C();

    if (index >= 0x29 || index < 0) {
        fn_1_4CF3C((f32)(lbl_1_rodata_8960[0] * scale), &lbl_1_data_41A30, (str = fn_1_14FEAC(a, b, c, buf1, 0)));
    } else {
        fn_1_4CF3C((f32)(lbl_1_rodata_8960[0] * scale), &lbl_1_data_41A30, (str = fn_1_7F49C(index, 0, buf2)));
    }
}
/* fzgx:end fn_1_135B80 */

/* fzgx:begin fn_1_135D7C noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

/* 164-byte table of 41 image ids. */
typedef struct SelImageTable {
    u32 image[41];
} SelImageTable;

/* FontDrawPacket layout as this unit's template stores it: the word at 0x30
 * receives the integer format code. */
typedef struct SelImagePacket {
    u32 image;
    f32 x, y, z;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 rotation_z, rotation_y;
    f32 alpha;
    u32 format;
    u32 flags;
    u8 color[4], color_add[4];
    u32 unk_40;
    u16 width, height;
    void* pixels;
    void* secondary;
    void* vertex_callback;
    u32 unk_54;
} SelImagePacket;

/* 0x81C0-byte machine entry */
typedef struct SelMachineEntry {
    u32 flags;
    u8 pad_4[0x819C];
    u8 image_index;
    u8 pad_81A1[3];
    u8 body;
    u8 pad_81A5[7];
    u8 cockpit;
    u8 pad_81AD[7];
    u8 booster;
    u8 pad_81B5[0xB];
} SelMachineEntry;

extern SelImageTable lbl_1_rodata_8964;
extern SelImagePacket lbl_1_rodata_26F8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_8960;
extern void* fn_1_12F118(void);
extern u8* fn_1_36AD0(void);
extern void fn_1_49410(void);
extern void fn_1_495C8(int);
extern void fn_1_494DC(int);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4962C(void);
extern u32 fn_1_14FEAC(u32, u32, u32, void*, void*);
extern void fn_1_4CF3C(f32, void*, ...);

void fn_1_135D7C(s16 x, s16 y, u32 format, s16 index, void* arg4, s16 slot, int arg6,
                 f32 scale_x, f32 scale_y, f32 z) {
    SelMachineEntry* entry;
    u8* base;
    u8 name[32];
    SelImagePacket packet;
    SelImageTable images;
    s32 i;

    images = lbl_1_rodata_8964;

    if (index < 0) return;
    if (arg6 != 0) return;

    if (index >= 0x29) {
        base = fn_1_12F118();
        if (base == fn_1_36AD0()) {
            entry = (SelMachineEntry*)base + slot;
        } else {
            entry = (SelMachineEntry*)base + (index - 0x29);
        }
        if (!(entry->flags & 0x40000000)) {
            index = entry->image_index;
            packet = lbl_1_rodata_26F8;
            i = index < 0 ? 0 : ((u32)index > 40 ? 40 : index);
            packet.image = images.image[i];
            packet.x = (f32)x;
            packet.y = (f32)y;
            packet.z = z;
            packet.scale_x *= scale_x;
            packet.scale_y *= scale_y;
            packet.format = format;
            fn_1_4F734((FontDrawPacket*)&packet);
        } else {
            fn_1_49410();
            switch (format) {
            case 5: fn_1_495C8(0); break;
            case 9: fn_1_495C8(8); break;
            case 13: fn_1_495C8(0x10); break;
            case 6: fn_1_495C8(1); break;
            case 10: fn_1_495C8(9); break;
            case 14: fn_1_495C8(0x11); break;
            case 7: fn_1_495C8(2); break;
            case 11: fn_1_495C8(0xA); break;
            case 15: fn_1_495C8(0x12); break;
            }
            fn_1_494DC(0x23);
            fn_1_496FC((f32)x, (f32)y);
            fn_1_4954C(z);
            fn_1_4955C(scale_x, scale_y);
            fn_1_4962C();
            {
                const f32* scale = &lbl_1_rodata_8960;
                fn_1_4CF3C(*scale * scale_x, &lbl_1_data_41A30,
                           fn_1_14FEAC(entry->body, entry->cockpit, entry->booster, name, arg4));
            }
        }
    } else {
        packet = lbl_1_rodata_26F8;
        i = index < 0 ? 0 : ((u32)index > 40 ? 40 : index);
        packet.image = images.image[i];
        packet.x = (f32)x;
        packet.y = (f32)y;
        packet.z = z;
        packet.scale_x *= scale_x;
        packet.scale_y *= scale_y;
        packet.format = format;
        fn_1_4F734((FontDrawPacket*)&packet);
    }
}
/* fzgx:end fn_1_135D7C */

/* fzgx:begin fn_1_136174 noprologue */
#include "types.h"

typedef struct Fn1_136174_Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Fn1_136174_Color;

typedef struct Fn1_136174_Entry {
    u32 flags;
    u8 pad_4[0x819C];
    u8 glyph;
    u8 pad_81A1[0x3];
    u8 unk_81A4;
    u8 pad_81A5[0x7];
    u8 unk_81AC;
    u8 pad_81AD[0x7];
    u8 unk_81B4;
    u8 pad_81B5[0xB];
} Fn1_136174_Entry;

extern char lbl_1_data_41A30[]; /* "%s\n" */
extern char lbl_1_data_41AB8[]; /* "?????\n" */
extern const Fn1_136174_Color lbl_1_rodata_8A08; /* {0xB7, 0xCE, 0xEA, 0xFF} */
extern void fn_1_49410(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49514(Fn1_136174_Color *);
extern void fn_1_5233C(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(s32);
extern void fn_1_4CF3C(f32, const char *, ...);
extern Fn1_136174_Entry *fn_1_12F118(void);
extern Fn1_136174_Entry *fn_1_36AD0(void);
extern char *fn_1_7F49C(s16, s16, char *);
extern void fn_1_4962C(void);
extern char *fn_1_14FEAC(u8, u8, u8, char *, s16);

void fn_1_136174(s16 x, s16 y, s32 type, s16 glyph, s16 id, s16 slot, s32 unknown, f32 scale_x, f32 scale_y) {
    char buf[32];
    Fn1_136174_Entry *base;
    Fn1_136174_Entry *entry;

    if (id == 0) {
        return;
    }
    if (glyph < 0) {
        return;
    }
    fn_1_49410();
    fn_1_496FC(x, y);
    fn_1_4955C(scale_x, scale_y);
    {
        Fn1_136174_Color color = lbl_1_rodata_8A08;

        fn_1_49514(&color);
    }
    fn_1_49738(fn_1_5233C);
    fn_1_49748(1.0f);
    fn_1_4954C(50.0f);
    fn_1_495C8(type);
    if (unknown) {
        fn_1_4CF3C(122.0f, lbl_1_data_41AB8);
        return;
    }
    if (glyph >= 0x29) {
        base = fn_1_12F118();
        if (base == fn_1_36AD0()) {
            entry = &base[slot];
        } else {
            entry = &base[glyph - 0x29];
        }
        if (!(entry->flags & 0x40000000)) {
            fn_1_4CF3C(122.0f, lbl_1_data_41A30, fn_1_7F49C(entry->glyph, id, buf));
            return;
        }
        fn_1_496FC(x, y);
        fn_1_4962C();
        fn_1_4CF3C(122.0f, lbl_1_data_41A30, fn_1_14FEAC(entry->unk_81A4, entry->unk_81AC, entry->unk_81B4, buf, id));
        return;
    }
    fn_1_4CF3C(122.0f, lbl_1_data_41A30, fn_1_7F49C(glyph, id, buf));
}
/* fzgx:end fn_1_136174 */

/* fzgx:begin fn_1_1363F0 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

struct fn_1_1363F0_Copy88 { u32 a[22]; };
struct Record { u8 bytes[0x81C0]; };
extern f32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_8A10, lbl_1_rodata_8A14, lbl_1_rodata_8A18, lbl_1_rodata_8A1C;
extern const f32 lbl_1_rodata_8A20, lbl_1_rodata_861C, lbl_1_rodata_8A24, lbl_1_rodata_8A28;
extern const f32 lbl_1_rodata_8668, lbl_1_rodata_85E8, lbl_1_rodata_87AC, lbl_1_rodata_8A2C, lbl_1_rodata_863C;
extern const f64 lbl_1_rodata_8600;
struct Color { u32 rgba; };
extern struct Color lbl_1_rodata_8A0C;
struct Stat { u32 unk_0; f32 value; u8 pad[0xAC]; };
extern struct Stat lbl_1_data_28060[46];
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_496FC(f32, f32);
extern void *fn_1_12F118(void);
extern u8 *fn_1_36AD0(void);
extern void fn_1_14E9E4(u8, void *);
extern void fn_1_4966C(f32,f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4955C(f32,f32);
extern void fn_1_4954C(f32);
extern void fn_1_4AE0C(const char *,...);
extern void fn_1_136714(f32,f32,f32,s32,s32,s32,s32,void *);

void fn_1_1363F0(s16 arg0, s32 arg1, s32 arg2) {
    struct fn_1_1363F0_Copy88 packet;
    f32 metrics[4];
    struct Color color;
    struct Color color2;
    s16 value;
    s16 index;
    u8 *base;
    u8 *record;
    s16 i;
    packet = *(struct fn_1_1363F0_Copy88 *)lbl_1_rodata_26F8;
    packet.a[0] = 0x9A24;
    *(f32 *)&packet.a[1] = lbl_1_rodata_8A10;
    *(f32 *)&packet.a[2] = lbl_1_rodata_8A14;
    fn_1_4F734((FontDrawPacket *)&packet);
    packet = *(struct fn_1_1363F0_Copy88 *)lbl_1_rodata_26F8;
    packet.a[0] = 0x9A25;
    *(f32 *)&packet.a[1] = lbl_1_rodata_8A18;
    *(f32 *)&packet.a[2] = lbl_1_rodata_8A14;
    fn_1_4F734((FontDrawPacket *)&packet);
    fn_1_49410();
    fn_1_494DC(0x22);
    fn_1_496FC(lbl_1_rodata_8A1C, lbl_1_rodata_8A14);
    index = ((Obj_1_bss_8B3A0 *)((u8 *)&lbl_1_bss_8B3A0 + (s16)lbl_1_bss_8B3A0.unk_9E * 0x20))->unk_E;
    if (index >= 41) {
        base = fn_1_12F118();
        if (base == fn_1_36AD0()) {
            s32 stride = 0x81C0;
            s32 slot = arg0;
            record = base + slot * stride;
        } else {
            record = base + (index - 41) * 0x81C0;
        }
        if (*(u32 *)record & 0x40000000) {
            value = 0;
            for (i = 0; (u32)i < 3; i++) {
                fn_1_14E9E4(record[0x81A4 + i * 8], metrics);
                value = value + metrics[1];
            }
        } else {
            value = lbl_1_data_28060[record[0x81A0]].value;
        }
    } else {
        value = lbl_1_data_28060[index].value;
    }
    color = lbl_1_rodata_8A0C;
    fn_1_4966C(lbl_1_rodata_8A20, lbl_1_rodata_861C);
    color2 = color;
    fn_1_49514(&color2.rgba);
    if (arg1) {
        fn_1_49410();
        fn_1_4955C(lbl_1_rodata_8A24, lbl_1_rodata_8A28);
        fn_1_4966C(lbl_1_rodata_8668, lbl_1_rodata_861C);
        fn_1_4954C(lbl_1_rodata_85E8);
        fn_1_4AE0C((char *)&lbl_1_data_41AC0);
    } else {
        fn_1_4AE0C((char *)&lbl_1_data_41AC8, value);
    }
    if (arg2) {
        fn_1_136714(lbl_1_rodata_87AC, lbl_1_rodata_8A2C, lbl_1_rodata_863C, value, 0x8F, 0x197, 9, 0);
    }
}
/* fzgx:end fn_1_1363F0 */

/* fzgx:begin fn_1_136714 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(s32 arg0);
extern void fn_1_4965C(s32 arg0);
extern void fn_1_495C8(s8 arg0);
extern void fn_1_496FC(f32 arg0, f32 arg1);
extern void fn_1_4954C(f32 arg0);
extern void fn_1_4955C(f32 arg0, f32 arg1);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 arg0);
extern void fn_1_49590(f32 arg0);
extern char* fn_1_13F72C(f32 arg0, s16 arg1, void* arg2);
extern void fn_1_4AE0C(const char* arg0, ...);
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern const f64 lbl_1_rodata_8600;
extern s32 lbl_801A66B4;

void fn_1_136714(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5,
                 s32 arg6, void* arg7) {
    f32 value;
    char buffer[64];

    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(-2147483647 - 1);
    fn_1_4965C(2);
    fn_1_495C8((s8)arg6);
    fn_1_496FC((f32)arg4, (f32)arg5);
    fn_1_4954C(arg0);
    value = arg1 / lbl_1_rodata_85FC;
    fn_1_4955C(value, value);
    if (arg7 != 0) {
        fn_1_49738(arg7);
    }
    fn_1_495A0(arg2);
    switch (lbl_801A66B4) {
    case 5:
        break;
    case 0:
    default:
        fn_1_49590(lbl_1_rodata_85F0);
        fn_1_4955C(lbl_1_rodata_8A30 * arg1 / lbl_1_rodata_85FC, value);
        break;
    }
    fn_1_4AE0C(fn_1_13F72C((f32)arg3, (s16)lbl_801A66B4, buffer));
}
/* fzgx:end fn_1_136714 */

/* fzgx:begin fn_1_1368A0 noprologue */
#include "types.h"
#include "font.h"

struct FzgxCopy_4 { u32 words[1]; };

extern f32 lbl_1_rodata_85E8;
extern f32 lbl_1_rodata_8638;
extern f32 lbl_1_rodata_863C;
extern f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A28;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern u32 lbl_1_data_41ACC;
extern f32 lbl_1_rodata_26F8[22];
extern s32 lbl_1_rodata_8A34;
extern void fn_1_137288(s32, u8 *, u8 *, u8 *, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_49514(u32 *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern u32 fn_1_5158C(FontDrawPacket *, u32, u32, u32);
extern s32 fn_1_5233C;

#pragma opt_propagation off
void fn_1_1368A0(s32 arg0, s16 arg1, s32 arg2, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4) {
    FontDrawPacket loc_14;
    struct FzgxCopy_4 sp10;
    s32 spC;
    u8 loc_8[4];
    f32 temp_f29;
    f32 temp_f31;
    FontDrawPacket * lab_t0;
    struct { f32 value; } prod;
    f32 prod2;
    struct { u32 value; } quot;

    sp10 = *(const struct FzgxCopy_4 *)((u8 *)(&lbl_1_rodata_8A34));
    fn_1_137288((s32)(arg0), (u8 *)((u8 *)((u8 *)(&loc_8) + 2)), (u8 *)((u8 *)((u8 *)(&loc_8) + 1)), (u8 *)((u8 *) &loc_8), arg1);
    loc_14 = *(const FontDrawPacket *)((u8 *)(&lbl_1_rodata_26F8));
    loc_14.x = farg0;
    loc_14.image = 0x9A20;
    loc_14.y = farg1;
    loc_14.z = *(f32 *)((u8 *)(&lbl_1_rodata_87DC) + 0);
    loc_14.scale_x *= farg3;
    loc_14.scale_y *= farg4;
    fn_1_4F734((FontDrawPacket *)(&loc_14));
    if (arg2 != 0) {
        fn_1_49410();
        fn_1_4955C((f32)((*(f32 *)((u8 *)(&lbl_1_rodata_8A28) + 0)) * farg3), (f32)((*(f32 *)((u8 *)(&lbl_1_rodata_8A28) + 0)) * farg4));
        fn_1_4954C((f32)(*(f32 *)((u8 *)(&lbl_1_rodata_85E8) + 0)));
        fn_1_49738((void (*)(void))((u32)(&fn_1_5233C)));
        fn_1_49748((f32)(*(f32 *)((u8 *)(&lbl_1_rodata_863C) + 0)));
        spC = sp10.words[0];
        fn_1_49514((u32 *)(&spC));
        { f32 __reg_value_prod = farg2 * farg3; prod.value = __reg_value_prod; }
        temp_f29 = farg0 + prod.value;
        prod2 = farg4;
        fn_1_496FC((f32)(temp_f29), (f32)(farg1 + prod2));
        fn_1_4AE0C((const char *)((s8 *) &lbl_1_data_41ACC));
        prod2 = (*(f32 *)((u8 *)(&lbl_1_rodata_8A38) + 0)) * farg4;
        fn_1_496FC((f32)(temp_f29), (f32)(farg1 + prod2));
        fn_1_4AE0C((const char *)((s8 *) &lbl_1_data_41ACC));
        prod2 = (*(f32 *)((u8 *)(&lbl_1_rodata_8A3C) + 0)) * farg4;
        fn_1_496FC((f32)(temp_f29), (f32)(farg1 + prod2));
        fn_1_4AE0C((const char *)((s8 *) &lbl_1_data_41ACC));
        return;
    }
    fn_1_51564((u16)(0U), (u16)(0U), (u16)(0x10U), (u16)(0x10U), (u16)(3U), (u16)(2U));
    loc_14 = *(const FontDrawPacket *)((u8 *)(&lbl_1_rodata_26F8));
    { f32 __reg_value_prod = farg2 * farg3; prod.value = __reg_value_prod; }
    temp_f31 = farg0 + prod.value;
    loc_14.x = temp_f31;
    loc_14.image = 0x9A21;
    prod2 = (*(f32 *)((u8 *)(&lbl_1_rodata_8638) + 0)) * farg4;
    loc_14.y = farg1 + prod2;
    loc_14.z = *(f32 *)((u8 *)(&lbl_1_rodata_87DC) + 0);
    loc_14.scale_x *= farg3;
    loc_14.scale_y *= farg4;
    (*(u32 *)((u8 *)(&loc_14) + 56)) = sp10.words[0];
    { u32 __reg_value_quot = loc_8[2] / 3; quot.value = __reg_value_quot; }
    lab_t0 = (FontDrawPacket *)(&loc_14);
    fn_1_5158C(lab_t0, (u32)(0x9A21U), (u32)((u32) (s16) (loc_8[2] % 3)), (u32)((u32) (s16) quot.value));
    fn_1_4F734((FontDrawPacket *)(&loc_14));
    loc_14 = *(const FontDrawPacket *)((u8 *)(&lbl_1_rodata_26F8));
    loc_14.x = temp_f31;
    loc_14.image = 0x9A21;
    prod2 = (*(f32 *)((u8 *)(&lbl_1_rodata_8A40) + 0)) * farg4;
    loc_14.y = farg1 + prod2;
    loc_14.z = *(f32 *)((u8 *)(&lbl_1_rodata_87DC) + 0);
    loc_14.scale_x *= farg3;
    loc_14.scale_y *= farg4;
    (*(u32 *)((u8 *)(&loc_14) + 56)) = sp10.words[0];
    { u32 __reg_value_quot = loc_8[1] / 3; quot.value = __reg_value_quot; }
    lab_t0 = (FontDrawPacket *)(&loc_14);
    fn_1_5158C(lab_t0, (u32)(0x9A21U), (u32)((u32) (s16) (loc_8[1] % 3)), (u32)((u32) (s16) quot.value));
    fn_1_4F734((FontDrawPacket *)(&loc_14));
    loc_14 = *(const FontDrawPacket *)((u8 *)(&lbl_1_rodata_26F8));
    loc_14.x = temp_f31;
    loc_14.image = 0x9A21;
    prod2 = (*(f32 *)((u8 *)(&lbl_1_rodata_8A44) + 0)) * farg4;
    loc_14.y = farg1 + prod2;
    loc_14.z = *(f32 *)((u8 *)(&lbl_1_rodata_87DC) + 0);
    loc_14.scale_x *= farg3;
    loc_14.scale_y *= farg4;
    (*(u32 *)((u8 *)(&loc_14) + 56)) = (*((0) + (sp10.words)));
    { u32 __reg_value_quot = loc_8[0] / 3; quot.value = __reg_value_quot; }
    lab_t0 = (FontDrawPacket *)(&loc_14);
    fn_1_5158C(lab_t0, (u32)(0x9A21U), (u32)((u32) (s16) (loc_8[0] % 3)), (u32)((u32) (s16) quot.value));
    fn_1_4F734((FontDrawPacket *)(&loc_14));
}
#pragma opt_propagation reset
/* fzgx:end fn_1_1368A0 */

/* fzgx:begin fn_1_136CC4 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "font.h"

extern int fn_1_4F734(FontDrawPacket *);
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_87DC;
extern const f32 lbl_1_rodata_8A4C;
extern f32 lbl_1_rodata_26F8[22];
struct ColorWord { u32 value; };
extern struct ColorWord lbl_1_rodata_8A48;
extern void fn_1_137288(s16, u8 *, u8 *, u8 *, s16);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);

void fn_1_136CC4(u32 arg0, u32 arg1, u32 arg2, s16 arg3) {
    f32 v0;
    f32 v1;
    f64 v2;
    f32 v3;
    f32 v4;
    f32 v5;
    u32 v6;
    f32 v7;
    f32 v8;
    f64 v9;
    f32 v10;
    f32 v11;
    f32 v12;
    u32 v13;
    f32 v14;
    f32 v15;
    f64 v16;
    f32 v17;
    f32 v18;
    f32 v19;
    u32 v20;
    s32 v21;
    s32 v22;
    f32 v23;
    f64 v24;
    u32 v25;
    f32 v26;
    f32 v27;
    f32 v28;
    f32 v29;
    s32 v30;
    s32 v31;
    f32 v32;
    f64 v33;
    u32 v34;
    f32 v35;
    f32 v36;
    f32 v37;
    f32 v38;
    s32 v39;
    s32 v40;
    f32 v41;
    f64 v42;
    u32 v43;
    f32 v44;
    f32 v45;
    f32 v46;
    f32 v47;
    FontDrawPacket loc_10;
    struct ColorWord color;
    u8 loc_A;
    u8 loc_9;
    u8 loc_8;
    color = lbl_1_rodata_8A48;
    fn_1_137288((s16)arg2, &loc_A, &loc_9, &loc_8, arg3);
    fn_1_51564(0, 0, 64, 20, 1, 3);
    loc_10 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_10.image = 0x9A20;
    loc_10.x = (f32)(s32)(arg0 + 2);
    loc_10.y = (f32)(s32)arg1;
    loc_10.z = 6.0f;
    loc_10.scale_x *= 0.8f;
    loc_10.scale_y *= 0.8f;
    loc_10.flags = 9;
    fn_1_5158C(&loc_10, 0x9A20, 0, 0);
    fn_1_4F734(&loc_10);
    loc_10 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_10.image = 0x9A20;
    loc_10.x = (f32)(s32)(arg0 + 91);
    loc_10.y = (f32)(s32)arg1;
    loc_10.z = 6.0f;
    loc_10.scale_x *= 0.8f;
    loc_10.scale_y *= 0.8f;
    loc_10.flags = 9;
    fn_1_5158C(&loc_10, 0x9A20, 0, 1);
    fn_1_4F734(&loc_10);
    loc_10 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_10.image = 0x9A20;
    loc_10.x = (f32)(s32)(arg0 + 179);
    loc_10.y = (f32)(s32)arg1;
    loc_10.z = 6.0f;
    loc_10.scale_x *= 0.8f;
    loc_10.scale_y *= 0.8f;
    loc_10.flags = 9;
    fn_1_5158C(&loc_10, 0x9A20, 0, 2);
    fn_1_4F734(&loc_10);
    fn_1_51564(0, 0, 16, 16, 3, 2);
    loc_10 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_10.image = 0x9A21;
    loc_10.x = (f32)(s32)(arg0 + 74);
    loc_10.y = (f32)(s32)arg1;
    loc_10.z = 6.0f;
    loc_10.scale_x *= 0.8f;
    loc_10.scale_y *= 0.8f;
    loc_10.flags = 10;
    *(u32 *)((u8 *)&loc_10 + 56) = color.value;
    fn_1_5158C(&loc_10, 0x9A21, (s16)((s32)loc_A % 3), (s16)((s32)loc_A / 3));
    fn_1_4F734(&loc_10);
    loc_10 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_10.image = 0x9A21;
    loc_10.x = (f32)(s32)(arg0 + 162);
    loc_10.y = (f32)(s32)arg1;
    loc_10.z = 6.0f;
    loc_10.scale_x *= 0.8f;
    loc_10.scale_y *= 0.8f;
    loc_10.flags = 10;
    *(u32 *)((u8 *)&loc_10 + 56) = color.value;
    fn_1_5158C(&loc_10, 0x9A21, (s16)((s32)loc_9 % 3), (s16)((s32)loc_9 / 3));
    fn_1_4F734(&loc_10);
    loc_10 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_10.image = 0x9A21;
    loc_10.x = (f32)(s32)(arg0 + 250);
    loc_10.y = (f32)(s32)arg1;
    loc_10.z = 6.0f;
    loc_10.scale_x *= 0.8f;
    loc_10.scale_y *= 0.8f;
    loc_10.flags = 10;
    *(u32 *)((u8 *)&loc_10 + 56) = color.value;
    fn_1_5158C(&loc_10, 0x9A21, (s16)((s32)loc_8 % 3), (s16)((s32)loc_8 / 3));
    fn_1_4F734(&loc_10);
}
/* fzgx:end fn_1_136CC4 */

/* fzgx:begin fn_1_137288 noprologue */
#include "types.h"

extern void* fn_1_12F118(void);
extern void* fn_1_36AD0(void);
extern void fn_1_1373B0(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_137364(int index, void* value0, void* value1, void* value2, s16 selector);

// Selects the display data source and emits either its configured value or the fallback value.
void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector) {
    void* entry;

    if ((s16)index >= 0x29) {
        entry = fn_1_12F118();
        if (entry == fn_1_36AD0()) {
            entry = (char*)entry + (s32)selector * 0x81c0;
        } else {
            entry = (char*)entry + (s32)((s16)index - 0x29) * 0x81c0;
        }

        if (*(u32*)entry & 0x40000000) {
            fn_1_1373B0(index, value0, value1, value2, selector);
        } else {
            fn_1_137364(*(u8*)((char*)entry + 0x81a0), value0, value1, value2, selector);
        }
    } else {
        fn_1_137364(index, value0, value1, value2, selector);
    }
}
/* fzgx:end fn_1_137288 */

/* fzgx:begin fn_1_1373B0 */
void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4) {
    struct { u8* value; } base;
    u8* tmp;
    s16 i;
    int level;
    struct {
        u8 unk[8];
        s16 value;
    } info;

    { u8* __reg_value_base = (void*)fn_1_12F118(); base.value = __reg_value_base; }
    if (base.value == (void*)fn_1_36AD0()) {
        tmp = ((arg4 * 0x81c0) + (base.value));
    } else {
        tmp = base.value + (arg0 - 0x29) * 0x81c0;
    }
    { u8* __reg_value_base = tmp; base.value = __reg_value_base; }

    for (i = 0; i < 3u; i++) {
        fn_1_14E9E4(base.value[0x81a4], &info);
        switch (info.value) {
        case 0: level = 1; break;
        case 1: level = 1; break;
        case 2: level = 2; break;
        case 3: level = 2; break;
        case 4: level = 3; break;
        case 5: level = 3; break;
        case 6: level = 4; break;
        case 7: level = 4; break;
        case 8: level = 5; break;
        case 9: level = 5; break;
        }
        switch (i) {
        case 0: *arg1 = level; break;
        case 1: *arg3 = level; break;
        case 2: *arg2 = level; break;
        }
        base.value += 8;
    }
}
/* fzgx:end fn_1_1373B0 */

/* fzgx:begin fn_1_13750C */
void fn_1_13750C(void* arg0, void* arg1, void* arg2, void* arg3) {
    fn_1_1375C0(0, arg0, arg1, arg2, arg3);
}
/* fzgx:end fn_1_13750C */

/* fzgx:begin fn_1_137548 */
void fn_1_137548(void* arg0, void* arg1, void* arg2, void* arg3) {
    fn_1_1375C0(1, arg0, arg1, arg2, arg3);
}
/* fzgx:end fn_1_137548 */

/* fzgx:begin fn_1_137584 */
void fn_1_137584(void* arg0, void* arg1, void* arg2, void* arg3) {
    fn_1_1375C0(2, arg0, arg1, arg2, arg3);
}
/* fzgx:end fn_1_137584 */

/* fzgx:begin fn_1_1375C0 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

struct fn_1_1375C0_Copy88 { u32 a[22]; };
typedef struct {
    u32 id;
    f32 y, bgX, bgY, w, h, x, barY, barH, leftX, rightX, textX, textY;
} PanelConfig;
typedef struct { PanelConfig a[3]; } PanelConfigs;
typedef struct {
    u32 id;
    f32 x, y, z, sx, sy;
    u32 a[5];
    f32 alpha;
    u32 flags;
    u32 b[7];
    void (*callback)(void *, void *);
    f32 user;
} PanelPacket;
typedef struct { s32 a[6]; } PanelWidths;

extern u8 lbl_1_rodata_8A5C[156];
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_1_rodata_8AF8[6];
extern u32 lbl_1_rodata_8B10[6];
extern u32 lbl_801A66A0;
extern u32 lbl_801A66B4;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_85F4;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_8664;
extern const f32 lbl_1_rodata_86C4;
extern const f32 lbl_1_rodata_87DC;
extern const f32 lbl_1_rodata_8808;
extern const f32 lbl_1_rodata_8B28;
extern const f32 lbl_1_rodata_8B2C;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8B38;
extern const f32 lbl_1_rodata_8B3C;
extern const f32 lbl_1_rodata_8B40;
extern int fn_1_4F734(FontDrawPacket *);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
typedef struct {
    u8 pad_0[0x54];
    f32 unk_54;
} Sig_fn_1_1392E0_Fn1392E0Arg0;
typedef struct {
    f32 unk_0;
    f32 unk_4;
    u8 pad_8[0x1C];
    f32 unk_24;
    f32 unk_28;
} Sig_fn_1_1392E0_Fn1392E0Arg1;
extern void fn_1_1392E0(Sig_fn_1_1392E0_Fn1392E0Arg0 *, Sig_fn_1_1392E0_Fn1392E0Arg1 *);
extern int fn_1_139A3C(int);
extern f32 lbl_8006D188(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);

#pragma opt_propagation on
static inline s32 panel_position(PanelConfig *p, s32 x, u8 value) {
    f32 first = (lbl_1_rodata_8B28 * (f32)(100 - (s32)value)) / lbl_1_rodata_85F4;
    f32 origin = (f32)x;
    f32 width = p->w - lbl_1_rodata_8638;
    return (s32)(first + (origin + p->x) + (width * (f32)value) / lbl_1_rodata_85F4);
}
static inline f32 panel_ratio(f32 divisor, f32 numerator) {
    return numerator / divisor;
}
#pragma opt_common_subs off
void fn_1_1375C0(u32 arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4) {
    f32 fzgx_live;
    PanelConfigs table = *(PanelConfigs *)lbl_1_rodata_8A5C;
    PanelPacket back;
    PanelPacket draw;
    PanelWidths left;
    PanelWidths right;
    PanelConfig *p = &table.a[arg0];
    f32 pulse;
    f32 fade;
    s32 position;
    u8 value;
    back = *(PanelPacket *)lbl_1_rodata_26F8;
    back.id = p->id;
    back.x = (f32)arg1;
    back.y = (f32)arg2 + p->y;
    back.z = lbl_1_rodata_86C4;
    fn_1_4F734((FontDrawPacket *)&back);

    back = *(PanelPacket *)lbl_1_rodata_26F8;
    back.id = 18;
    back.x = (f32)arg1 + p->bgX;
    back.y = (f32)arg2 + p->bgY;
    back.z = lbl_1_rodata_87DC;
    back.sx *= (p->w - lbl_1_rodata_8B28) / (f32)fn_1_48690(18);
    back.sy *= p->h / (f32)fn_1_486C4(back.id);
    back.alpha = lbl_1_rodata_861C;
    back.flags = 0x4000000;
    back.user = (f32)arg4;
    back.callback = (void (*)(void *, void *))fn_1_1392E0;
    fn_1_4F734((FontDrawPacket *)&back);
    if (lbl_1_bss_8B3A0.unk_94 & 0x40000000) arg4 = 0;
    if (fn_1_139A3C((s16)arg4)) {
        pulse = lbl_1_rodata_861C;
    } else {
        pulse = lbl_1_rodata_8808 + (f32)((f32)(lbl_1_rodata_8664 * (lbl_1_rodata_863C + lbl_8006D188((s32)((lbl_1_rodata_8B2C * (f32)(lbl_801A66A0 % 60)) / lbl_1_rodata_8B30)))) / 2.0f);
    }
    value = (&lbl_1_bss_8B3A0.unk_9F)[arg4];
    {
        f32 first = panel_ratio(lbl_1_rodata_85F4, lbl_1_rodata_8B28 * (f32)(100 - (s32)value));
        f32 x = (f32)arg1;
        struct { f32 value; } width;
        width.value = p->w - lbl_1_rodata_8638;
        fzgx_live = p->x;
        position = (s32)(first + (x + fzgx_live) + panel_ratio(lbl_1_rodata_85F4, width.value * (f32)value));
    }
    draw = *(PanelPacket *)lbl_1_rodata_26F8;
    draw.id = 0x9A0B;
    draw.x = (f32)position;
    draw.y = (f32)arg2 + p->barY;
    draw.z = lbl_1_rodata_8B34;
    fade = lbl_1_rodata_863C - (f32)(lbl_1_rodata_85F0 * pulse);
    draw.flags = 6;
    draw.alpha = fade;
    fn_1_4F734((FontDrawPacket *)&draw);
    if ((f32)position > lbl_1_rodata_8B28 + ((f32)arg1 + p->x)) {
        draw = *(PanelPacket *)lbl_1_rodata_26F8;
        draw.id = 0x9A0C;
        draw.x = (f32)(position - 12);
        draw.y = (f32)arg2 + p->barY;
        draw.z = lbl_1_rodata_8B34;
        draw.flags = 7;
        draw.alpha = pulse;
        fn_1_4F734((FontDrawPacket *)&draw);
    }
    if ((f32)position < p->w + ((f32)arg1 + p->x) - lbl_1_rodata_8638) {
        draw = *(PanelPacket *)lbl_1_rodata_26F8;
        draw.id = 0x9A0C;
        draw.x = (f32)(position + 12);
        draw.y = (f32)arg2 + p->barY;
        draw.z = lbl_1_rodata_8B34;
        draw.flags = 0x80005;
        draw.alpha = pulse;
        fn_1_4F734((FontDrawPacket *)&draw);
    }
    draw = *(PanelPacket *)lbl_1_rodata_26F8;
    draw.id = 0x9A0D;
    draw.x = (f32)position;
    draw.y = (f32)arg2 + p->barY;
    draw.z = lbl_1_rodata_8B38;
    draw.sy = p->barH / (f32)fn_1_486C4(draw.id);
    draw.flags = 14;
    draw.alpha = fade;
    fn_1_4F734((FontDrawPacket *)&draw);
    left = *(PanelWidths *)lbl_1_rodata_8AF8;
    right = *(PanelWidths *)lbl_1_rodata_8B10;
    draw = *(PanelPacket *)lbl_1_rodata_26F8;
    draw.id = 0x9A23;
    fn_1_51678((FontDrawPacket *)&draw, 0x9A23, 0, 0, (s16)left.a[lbl_801A66B4], 20);
    draw.x = (f32)arg1 + p->leftX;
    draw.y = (f32)arg2 + p->barY;
    draw.z = lbl_1_rodata_8B3C;
    draw.flags = 5;
    if ((f32)position < lbl_1_rodata_8B28 + ((f32)arg1 + p->x) + (f32)left.a[lbl_801A66B4]) draw.alpha = lbl_1_rodata_8808;
    fn_1_4F734((FontDrawPacket *)&draw);
    draw = *(PanelPacket *)lbl_1_rodata_26F8;
    draw.id = 0x9A23;
    fn_1_51678((FontDrawPacket *)&draw, 0x9A23, (s16)(72 - right.a[lbl_801A66B4]), 20, (s16)right.a[lbl_801A66B4], 20);
    draw.x = (f32)arg1 + p->rightX;
    draw.y = (f32)arg2 + p->barY;
    draw.z = lbl_1_rodata_8B3C;
    draw.flags = 7;
    if ((f32)position > p->w + ((f32)arg1 + p->x) - lbl_1_rodata_8B28 - (f32)right.a[lbl_801A66B4]) draw.alpha = lbl_1_rodata_8808;
    fn_1_4F734((FontDrawPacket *)&draw);
    if ((s32)arg0 != 0) {
        fn_1_49410();
        fn_1_494DC(4);
        fn_1_4966C(lbl_1_rodata_8B40, lbl_1_rodata_861C);
        fn_1_496FC((f32)arg1 + p->textX, (f32)arg2 + p->textY);
        fn_1_4A0D8((char *)lbl_1_data_41AF8);
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_1375C0 */

/* fzgx:begin fn_1_1380F0 */
void fn_1_1380F0(void* arg0) {
    fn_1_138144(arg0, lbl_1_bss_8B3A0.unk_94 & 0x40000000);
}
/* fzgx:end fn_1_1380F0 */

/* fzgx:begin fn_1_138120 */
void fn_1_138120(void* arg0) {
    fn_1_138144(arg0, 0);
}
/* fzgx:end fn_1_138120 */

/* fzgx:begin fn_1_138144 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

typedef struct {
    s32 type;
    f32 x;
    f32 y;
    f32 z;
    f32 sx;
    f32 sy;
    u8 pad_18[0x18];
    u32 flags;
    u32 pad_34;
    u32 color;
    u8 pad_3C[0x1C];
} FontPkt;

extern s8 fn_1_A5DC4(void);
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_8674;
extern void fn_1_49410(void);
extern const f32 lbl_1_rodata_8B58;
extern void fn_1_4954C(f32);
extern const f32 lbl_1_rodata_8B5C;
extern void fn_1_4955C(f32, f32);
extern void fn_1_49768(u8);
extern const f32 lbl_1_rodata_8B60;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_8B28;
extern void fn_1_49778(s16, s16, s16, s16);
extern const f32 lbl_1_rodata_85F0;
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern f32 fn_1_4B068(s32);
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_8B64;
extern const f32 lbl_1_rodata_86D0;
extern const f32 lbl_1_rodata_87E4;
extern const f32 lbl_1_rodata_8B68;
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern const f32 lbl_1_rodata_8B6C;
extern const f32 lbl_1_rodata_8638;
extern const FontPkt lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_8658;
extern u32 lbl_1_rodata_8B44;
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern const f32 lbl_1_rodata_8834;
extern int fn_1_4F734(FontPkt *);
extern const f32 lbl_1_rodata_8B70;
extern u32 lbl_1_rodata_8B48;
extern const f32 lbl_1_rodata_8B74;
extern u32 lbl_1_rodata_8B4C;
extern const f32 lbl_1_rodata_8838;
extern u32 lbl_1_rodata_8B50;
extern u32 lbl_1_rodata_8B54;
extern s32 lbl_801A66B4;
extern u32 lbl_801A66A0;

void fn_1_138144(s32 arg0, s32 arg1) {
    FontPkt p;
    s32 v0;
    f32 f31;
    f32 f30;

    v0 = (s32)(fn_1_A5DC4() != 0 ? lbl_1_rodata_884C : lbl_1_rodata_8674);
    fn_1_49410();
    fn_1_4954C(lbl_1_rodata_8B58);
    fn_1_4955C(lbl_1_rodata_8B5C, lbl_1_rodata_8B5C);
    fn_1_49768(1);
    fn_1_49778(lbl_1_rodata_8B60, lbl_1_rodata_88A8, (f32)(s16)v0 - lbl_1_rodata_8B60, lbl_1_rodata_8B28);
    if (lbl_801A66B4 != 5) {
        fn_1_49590(lbl_1_rodata_85F0);
        fn_1_495B0(0x80000000);
    }
    f31 = fn_1_4B068(arg0);
    if (lbl_801A66B4 != 5 && f31 > lbl_1_rodata_86F8) {
        fn_1_4955C(lbl_1_rodata_8B64, lbl_1_rodata_8B5C);
        f31 = fn_1_4B068(arg0);
    }
    f31 = f31 + lbl_1_rodata_86D0;
    f30 = (f32)(lbl_801A66A0 % (u32)(s32)f31);
    if (fn_1_A5DC4() != 0) {
        fn_1_496FC((lbl_1_rodata_8B68 + (f32)(lbl_1_rodata_87E4 * f31)) - f30, lbl_1_rodata_88A8);
        fn_1_4A0D8((const char *)arg0);
        fn_1_496FC((lbl_1_rodata_8B68 + (f32)(lbl_1_rodata_8B6C * f31)) - f30, lbl_1_rodata_88A8);
        fn_1_4A0D8((const char *)arg0);
    }
    fn_1_496FC((lbl_1_rodata_8B68 + (f32)(lbl_1_rodata_8638 * f31)) - f30, lbl_1_rodata_88A8);
    fn_1_4A0D8((const char *)arg0);
    fn_1_496FC((lbl_1_rodata_8B68 + f31) - f30, lbl_1_rodata_88A8);
    fn_1_4A0D8((const char *)arg0);
    fn_1_496FC(lbl_1_rodata_8B68 - f30, lbl_1_rodata_88A8);
    fn_1_4A0D8((const char *)arg0);
    fn_1_496FC((lbl_1_rodata_8B68 - f31) - f30, lbl_1_rodata_88A8);
    fn_1_4A0D8((const char *)arg0);
    fn_1_49768(0);
    if (fn_1_A5DC4() != 0) {
        p = lbl_1_rodata_26F8;
        p.type = 5;
        p.x = lbl_1_rodata_8658;
        p.y = lbl_1_rodata_88A8;
        p.color = lbl_1_rodata_8B44;
        p.sx = p.sx * (lbl_1_rodata_8B28 / (f32)fn_1_48690(5));
        p.sy = p.sy * (lbl_1_rodata_8B28 / (f32)fn_1_486C4(p.type));
        p.z = lbl_1_rodata_8834;
        p.flags = 0x80000;
        fn_1_4F734(&p);
        p.x = lbl_1_rodata_8B70;
        p.flags = 0;
        fn_1_4F734(&p);

        p = lbl_1_rodata_26F8;
        p.type = 18;
        p.x = (f32)(s16)v0;
        p.y = lbl_1_rodata_88A8;
        p.z = lbl_1_rodata_8834;
        p.color = lbl_1_rodata_8B48;
        p.sx = p.sx * (lbl_1_rodata_8B28 / (f32)fn_1_486C4(18));
        p.sy = p.sy * (lbl_1_rodata_8B28 / (f32)fn_1_486C4(p.type));
        p.flags = 7;
        fn_1_4F734(&p);

        p = lbl_1_rodata_26F8;
        p.type = 18;
        p.x = lbl_1_rodata_8B74;
        p.y = lbl_1_rodata_88A8;
        p.z = lbl_1_rodata_8834;
        p.color = lbl_1_rodata_8B4C;
        p.sx = p.sx * (lbl_1_rodata_8838 / (f32)fn_1_486C4(18));
        p.sy = p.sy * (lbl_1_rodata_8B28 / (f32)fn_1_486C4(p.type));
        fn_1_4F734(&p);
    } else {
        p = lbl_1_rodata_26F8;
        p.type = 5;
        p.x = lbl_1_rodata_8658;
        p.y = lbl_1_rodata_88A8;
        p.color = lbl_1_rodata_8B50;
        p.sx = p.sx * (lbl_1_rodata_8B28 / (f32)fn_1_48690(5));
        p.sy = p.sy * (lbl_1_rodata_8B28 / (f32)fn_1_486C4(p.type));
        p.z = lbl_1_rodata_8834;
        p.flags = 0x80000;
        fn_1_4F734(&p);
        p.x = (f32)(arg1 != 0 ? 520 : 616);
        p.flags = 0;
        fn_1_4F734(&p);

        p = lbl_1_rodata_26F8;
        p.type = 18;
        p.x = lbl_1_rodata_8674;
        p.y = lbl_1_rodata_88A8;
        p.z = lbl_1_rodata_8834;
        p.color = lbl_1_rodata_8B54;
        if (lbl_1_bss_8B3A0.unk_94 & 0x40000000) {
            p.sx = p.sx * (lbl_1_rodata_8B28 / (f32)fn_1_486C4(18));
        }
        p.sy = p.sy * (lbl_1_rodata_8B28 / (f32)fn_1_486C4(p.type));
        p.flags = 7;
        fn_1_4F734(&p);
    }
}
/* fzgx:end fn_1_138144 */

/* fzgx:begin fn_1_138A04 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

extern FontDrawPacket lbl_1_rodata_26F8;
extern s32 lbl_801A66B4;
extern const f32 lbl_1_rodata_85EC;  /* 0.75f */
extern const f32 lbl_1_rodata_85F4;  /* 100.0f */
extern const f32 lbl_1_rodata_861C;  /* 0.0f */
extern const f32 lbl_1_rodata_863C;  /* 1.0f */
extern const f32 lbl_1_rodata_864C;  /* 0.64f */
extern const f32 lbl_1_rodata_8664;  /* 0.6f */
extern const f32 lbl_1_rodata_86D0;  /* 80.0f */
extern const f32 lbl_1_rodata_87DC;  /* 6.0f */
extern const f32 lbl_1_rodata_8A50;  /* 0.87f */
extern const f32 lbl_1_rodata_8B40;  /* -4.0f */
extern const f32 lbl_1_rodata_8B78;  /* 613.0f */
extern const f32 lbl_1_rodata_8B7C;  /* 519.0f */
extern const f32 lbl_1_rodata_8B80;  /* 591.0f */

extern int fn_1_4F734(FontDrawPacket *);
extern u16 fn_1_486C4(u32);
extern u8 fn_1_141F94(u8);
extern void fn_1_135D7C(s16, s16, s16, s16, s16, s16, s16, f32, f32, f32);
extern void fn_1_136CC4(u32, u32, u32, s16);
extern void fn_1_13A848(s16, s16, s32, s16, s32, f32, f32);
extern void fn_1_13A994(s16, s16, s32, s16, s16, s32, f32, f32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(s32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);

#define fzgx_pool_data_lbl_1_data_40F58_BA8 (data + 0xBA8)
#define fzgx_pool_data_lbl_1_data_40F58_BB8 (data + 0xBB8)
#define fzgx_pool_data_lbl_1_data_40F58_BC0 (data + 0xBC0)

void fn_1_138A04(s32 x, s32 y, s32 idx) {
    const char *data;
    s32 py;
    s16 kind;
    u8 color;
    s16 w;
    FontDrawPacket pkt;

    data = (const char *)&lbl_1_data_40F58;
    kind = (&lbl_1_bss_8B3A0.unk_E)[idx * 16];
    color = fn_1_141F94(idx);

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9D0C;
    w = fn_1_486C4(0x9D0C);
    fn_1_51678(&pkt, pkt.image, 0, 0, 285, w);
    pkt.x = x;
    pkt.y = y;
    pkt.z = lbl_1_rodata_85F4;
    fn_1_4F734(&pkt);

    fn_1_51564(0, 0, 24, 20, 2, 2);
    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9D0B;
    pkt.x = x + 18;
    pkt.y = y + 18;
    pkt.z = 80.0f;
    pkt.flags = 10;
    fn_1_5158C(&pkt, pkt.image, (s16)(color % 2), (s16)(color / 2));
    fn_1_4F734(&pkt);

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x9D08;
    pkt.x = x + 7;
    pkt.y = y + 33;
    pkt.z = lbl_1_rodata_86D0;
    fn_1_4F734(&pkt);

    {
        f32 scale = 0.87f;
        fn_1_135D7C(x + 36, y + 18, 9, kind, 0, idx, 0, scale, scale, lbl_1_rodata_87DC);
    }
    fn_1_136CC4(x + 16, y + 42, kind, idx);
    fn_1_13A848(x + 467, y + 129, 1, kind, 0, lbl_1_rodata_8664, lbl_1_rodata_864C);
    fn_1_13A994(x + 467, y + 148, 1, kind, lbl_801A66B4, 0, lbl_1_rodata_8664, lbl_1_rodata_8664);

    fn_1_49410();
    fn_1_495C8(10);
    fn_1_494DC(4);
    fn_1_4966C(lbl_1_rodata_8B40, lbl_1_rodata_861C);
    fn_1_4954C(lbl_1_rodata_863C);
    fn_1_496FC(lbl_1_rodata_8B78, py = color * 201 + 242);
    fn_1_4A0D8(fzgx_pool_data_lbl_1_data_40F58_BA8);
    fn_1_49410();
    fn_1_495C8(10);
    fn_1_4954C(lbl_1_rodata_863C);
    fn_1_4955C(lbl_1_rodata_85EC, lbl_1_rodata_85EC);
    fn_1_496FC(lbl_1_rodata_8B7C, py);
    fn_1_4A0D8((const char *)fzgx_pool_data_lbl_1_data_40F58_BB8);
    fn_1_4954C(lbl_1_rodata_863C);
    fn_1_496FC(lbl_1_rodata_8B80, py);
    fn_1_4A0D8((const char *)fzgx_pool_data_lbl_1_data_40F58_BC0);
}
/* fzgx:end fn_1_138A04 */

/* fzgx:begin fn_1_138E44 noprologue */
#include "types.h"
#include "font.h"

struct fn_1_138E44_lbl_1_bss_8B3A0_0_E32 {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x10];
};
struct fn_1_138E44_Copy88 { u32 a[22]; };
struct fn_1_138E44_lbl_1_bss_8B3A0 {
    struct fn_1_138E44_lbl_1_bss_8B3A0_0_E32 unk_0[1];
};
struct fn_1_138E44_lbl_1_rodata_8600 {
    f64 unk_0;
};

extern f32 lbl_1_rodata_85EC;
extern f32 lbl_1_rodata_861C;
extern f32 lbl_1_rodata_863C;
extern f32 lbl_1_rodata_86D0;
extern f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A50;
extern f32 lbl_1_rodata_8B40;
extern f32 lbl_1_rodata_8B84;
extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_1_138E44_lbl_1_rodata_8600 lbl_1_rodata_8600;
extern u32 lbl_1_rodata_26F8;
extern u8 fn_1_141F94(u32);
extern void fn_1_135D7C(s16, s16, s32, s16, s32, s16, s32, f32, f32, f32);
extern void fn_1_136CC4(u32, u32, u32, s16);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(void *);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);

#pragma opt_common_subs off
typedef struct lbl_1_bss_8B3A0_t {
    struct fn_1_138E44_lbl_1_bss_8B3A0_0_E32 unk_0[1];
    u8 pad_20[0x12c];
} lbl_1_bss_8B3A0_t;

extern lbl_1_bss_8B3A0_t lbl_1_bss_8B3A0;

extern u8 fn_1_1358BC__fzgx_offset_108[];
extern u8 fn_1_1358BC__fzgx_offset_114[];
extern u8 fn_1_1358BC__fzgx_offset_120[];
extern u8 fn_1_1358BC__fzgx_offset_128[];
extern u8 fn_1_1358BC__fzgx_offset_C0[];
extern u8 fn_1_1358BC__fzgx_offset_CC[];
extern u8 fn_1_1358BC__fzgx_offset_D8[];
extern u8 fn_1_1358BC__fzgx_offset_E4[];
extern u8 fn_1_1358BC__fzgx_offset_F0[];
extern u8 fn_1_1358BC__fzgx_offset_FC[];
extern u8 fn_1_135B80__fzgx_offset_7C[];
extern u8 fn_1_135B80__fzgx_offset_88[];
extern u8 fn_1_135B80__fzgx_offset_94[];
extern u8 fn_1_135B80__fzgx_offset_A0[];
extern u8 fn_1_135B80__fzgx_offset_AC[];
extern u8 fn_1_135B80__fzgx_offset_B8[];
extern u8 fn_1_135B80__fzgx_offset_C4[];
extern u8 fn_1_135B80__fzgx_offset_D0[];
extern u8 fn_1_135B80__fzgx_offset_DC[];
extern u8 fn_1_135B80__fzgx_offset_E4[];
extern u8 fn_1_135D7C__fzgx_offset_1F0[];
extern u8 fn_1_135D7C__fzgx_offset_1FC[];
extern u8 fn_1_135D7C__fzgx_offset_208[];
extern u8 fn_1_135D7C__fzgx_offset_214[];
extern u8 fn_1_135D7C__fzgx_offset_220[];
extern u8 fn_1_135D7C__fzgx_offset_22C[];
extern u8 fn_1_135D7C__fzgx_offset_238[];
extern u8 fn_1_135D7C__fzgx_offset_244[];
extern u8 fn_1_135D7C__fzgx_offset_250[];
extern u8 fn_1_135D7C__fzgx_offset_258[];
extern u8 fn_1_1373B0__fzgx_offset_AC[];
extern u8 fn_1_1373B0__fzgx_offset_B4[];
extern u8 fn_1_1373B0__fzgx_offset_BC[];
extern u8 fn_1_1373B0__fzgx_offset_C4[];
extern u8 fn_1_1373B0__fzgx_offset_CC[];
extern u8 fn_1_1373B0__fzgx_offset_D4[];
extern u8 fn_1_1373B0__fzgx_offset_DC[];
extern u8 fn_1_1373B0__fzgx_offset_E4[];
extern u8 fn_1_1373B0__fzgx_offset_EC[];
extern u8 fn_1_1373B0__fzgx_offset_F4[];
extern u8 lbl_1_data_40F58__fzgx_offset_0[];
extern u8 lbl_1_data_40F5C__fzgx_offset_0[];
extern u8 lbl_1_data_40F68__fzgx_offset_0[];
extern u8 lbl_1_data_40F74__fzgx_offset_0[];
extern u8 lbl_1_data_40F80__fzgx_offset_0[];
extern u8 lbl_1_data_40F8C__fzgx_offset_0[];
extern u8 lbl_1_data_40F94__fzgx_offset_0[];
extern u8 lbl_1_data_40F9C__fzgx_offset_0[];
extern u8 lbl_1_data_40FA4__fzgx_offset_0[];
extern u8 lbl_1_data_40FAC__fzgx_offset_0[];
extern u8 lbl_1_data_40FB8__fzgx_offset_0[];
extern u8 lbl_1_data_40FC8__fzgx_offset_0[];
extern u8 lbl_1_data_40FD8__fzgx_offset_0[];
extern u8 lbl_1_data_40FE0__fzgx_offset_0[];
extern u8 lbl_1_data_40FE8__fzgx_offset_0[];
extern u8 lbl_1_data_40FF4__fzgx_offset_0[];
extern u8 lbl_1_data_41000__fzgx_offset_0[];
extern u8 lbl_1_data_41010__fzgx_offset_0[];
extern u8 lbl_1_data_41018__fzgx_offset_0[];
extern u8 lbl_1_data_41024__fzgx_offset_0[];
extern u8 lbl_1_data_41030__fzgx_offset_0[];
extern u8 lbl_1_data_41040__fzgx_offset_0[];
extern u8 lbl_1_data_41048__fzgx_offset_0[];
extern u8 lbl_1_data_41054__fzgx_offset_0[];
extern u8 lbl_1_data_41060__fzgx_offset_0[];
extern u8 lbl_1_data_41070__fzgx_offset_0[];
extern u8 lbl_1_data_41078__fzgx_offset_0[];
extern u8 lbl_1_data_41084__fzgx_offset_0[];
extern u8 lbl_1_data_4108C__fzgx_offset_0[];
extern u8 lbl_1_data_41098__fzgx_offset_0[];
extern u8 lbl_1_data_410A8__fzgx_offset_0[];
extern u8 lbl_1_data_410B4__fzgx_offset_0[];
extern u8 lbl_1_data_410C0__fzgx_offset_0[];
extern u8 lbl_1_data_410C8__fzgx_offset_0[];
extern u8 lbl_1_data_410DC__fzgx_offset_0[];
extern u8 lbl_1_data_410EC__fzgx_offset_0[];
extern u8 lbl_1_data_410FC__fzgx_offset_0[];
extern u8 lbl_1_data_41108__fzgx_offset_0[];
extern u8 lbl_1_data_41114__fzgx_offset_0[];
extern u8 lbl_1_data_41124__fzgx_offset_0[];
extern u8 lbl_1_data_4112C__fzgx_offset_0[];
extern u8 lbl_1_data_41138__fzgx_offset_0[];
extern u8 lbl_1_data_41140__fzgx_offset_0[];
extern u8 lbl_1_data_41148__fzgx_offset_0[];
extern u8 lbl_1_data_41150__fzgx_offset_0[];
extern u8 lbl_1_data_4120C__fzgx_offset_0[];
extern u8 lbl_1_data_4122C__fzgx_offset_0[];
extern u8 lbl_1_data_41230__fzgx_offset_0[];
extern u8 lbl_1_data_41274__fzgx_offset_0[];
extern u8 lbl_1_data_41294__fzgx_offset_0[];
extern u8 lbl_1_data_412B8__fzgx_offset_0[];
extern u8 lbl_1_data_412FC__fzgx_offset_0[];
extern u8 lbl_1_data_41340__fzgx_offset_0[];
extern u8 lbl_1_data_41348__fzgx_offset_0[];
extern u8 lbl_1_data_41350__fzgx_offset_0[];
extern u8 lbl_1_data_41358__fzgx_offset_0[];
extern u8 lbl_1_data_41364__fzgx_offset_0[];
extern u8 lbl_1_data_41374__fzgx_offset_0[];
extern u8 lbl_1_data_4137C__fzgx_offset_0[];
extern u8 lbl_1_data_41388__fzgx_offset_0[];
extern u8 lbl_1_data_41390__fzgx_offset_0[];
extern u8 lbl_1_data_4139C__fzgx_offset_0[];
extern u8 lbl_1_data_413A4__fzgx_offset_0[];
extern u8 lbl_1_data_413B0__fzgx_offset_0[];
extern u8 lbl_1_data_413C0__fzgx_offset_0[];
extern u8 lbl_1_data_413D0__fzgx_offset_0[];
extern u8 lbl_1_data_413E0__fzgx_offset_0[];
extern u8 lbl_1_data_413EC__fzgx_offset_0[];
extern u8 lbl_1_data_413F8__fzgx_offset_0[];
extern u8 lbl_1_data_41400__fzgx_offset_0[];
extern u8 lbl_1_data_41408__fzgx_offset_0[];
extern u8 lbl_1_data_41410__fzgx_offset_0[];
extern u8 lbl_1_data_41418__fzgx_offset_0[];
extern u8 lbl_1_data_41420__fzgx_offset_0[];
extern u8 lbl_1_data_41428__fzgx_offset_0[];
extern u8 lbl_1_data_41430__fzgx_offset_0[];
extern u8 lbl_1_data_41438__fzgx_offset_0[];
extern u8 lbl_1_data_41448__fzgx_offset_0[];
extern u8 lbl_1_data_41458__fzgx_offset_0[];
extern u8 lbl_1_data_41468__fzgx_offset_0[];
extern u8 lbl_1_data_41478__fzgx_offset_0[];
extern u8 lbl_1_data_41484__fzgx_offset_0[];
extern u8 lbl_1_data_4148C__fzgx_offset_0[];
extern u8 lbl_1_data_4149C__fzgx_offset_0[];
extern u8 lbl_1_data_414A8__fzgx_offset_0[];
extern u8 lbl_1_data_414C0__fzgx_offset_0[];
extern u8 lbl_1_data_418A4__fzgx_offset_0[];
extern u8 lbl_1_data_418BC__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_40F58[746] = {  /* fzgx-allow: A1 retail data bytes and bindings */
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
    (u32)lbl_1_data_40F58__fzgx_offset_0, (u32)lbl_1_data_40F5C__fzgx_offset_0, (u32)lbl_1_data_40F68__fzgx_offset_0, (u32)lbl_1_data_40F74__fzgx_offset_0, (u32)lbl_1_data_40F80__fzgx_offset_0, (u32)lbl_1_data_40F8C__fzgx_offset_0, (u32)lbl_1_data_40F94__fzgx_offset_0, (u32)lbl_1_data_40F9C__fzgx_offset_0,
    (u32)lbl_1_data_40FA4__fzgx_offset_0, (u32)lbl_1_data_40FAC__fzgx_offset_0, (u32)lbl_1_data_40FB8__fzgx_offset_0, (u32)lbl_1_data_40FC8__fzgx_offset_0, (u32)lbl_1_data_40FD8__fzgx_offset_0, (u32)lbl_1_data_40FE0__fzgx_offset_0, (u32)lbl_1_data_40FE8__fzgx_offset_0, (u32)lbl_1_data_40FF4__fzgx_offset_0,
    (u32)lbl_1_data_41000__fzgx_offset_0, (u32)lbl_1_data_41010__fzgx_offset_0, (u32)lbl_1_data_41018__fzgx_offset_0, (u32)lbl_1_data_41024__fzgx_offset_0, (u32)lbl_1_data_41030__fzgx_offset_0, (u32)lbl_1_data_41040__fzgx_offset_0, (u32)lbl_1_data_41048__fzgx_offset_0, (u32)lbl_1_data_41054__fzgx_offset_0,
    (u32)lbl_1_data_41060__fzgx_offset_0, (u32)lbl_1_data_41070__fzgx_offset_0, (u32)lbl_1_data_41078__fzgx_offset_0, (u32)lbl_1_data_41084__fzgx_offset_0, (u32)lbl_1_data_4108C__fzgx_offset_0, (u32)lbl_1_data_41098__fzgx_offset_0, (u32)lbl_1_data_410A8__fzgx_offset_0, (u32)lbl_1_data_410B4__fzgx_offset_0,
    (u32)lbl_1_data_410C0__fzgx_offset_0, (u32)lbl_1_data_410C8__fzgx_offset_0, (u32)lbl_1_data_410DC__fzgx_offset_0, (u32)lbl_1_data_410EC__fzgx_offset_0, (u32)lbl_1_data_410FC__fzgx_offset_0, (u32)lbl_1_data_41108__fzgx_offset_0, (u32)lbl_1_data_41114__fzgx_offset_0, (u32)lbl_1_data_41124__fzgx_offset_0,
    (u32)lbl_1_data_4112C__fzgx_offset_0, (u32)lbl_1_data_41138__fzgx_offset_0, (u32)lbl_1_data_41140__fzgx_offset_0, (u32)lbl_1_data_41148__fzgx_offset_0, (u32)lbl_1_data_41150__fzgx_offset_0, 0x436F6E74, 0x726F6C6C, 0x65722025,
    0x64206973, 0x20646973, 0x636F6E6E, 0x65637465, 0x640A0000, 0x0, 0x83528393, 0x8367838D,
    0x815B8389, 0x256482AA, 0x82CA82AF, 0x82C482A2, 0x82DC82B7, 0xA835283, 0x93836783, 0x8D815B83,  /* fzgx-allow: A1 retail data bytes */
    0x89837C81, 0x5B836725, 0x6482C982, 0xB382B582, 0xC482AD82, 0xBE82B382, 0xA2000000, 0x506C6561,
    0x73652073, 0x65742075, 0x7020796F, 0x7572206D, 0x61636869, 0x6E652E20, 0x0, 0x837D8356,
    0x839382F0, 0x835A8362, 0x83658342, 0x8393834F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    0x50726573, 0x73207468, 0x6520436F, 0x6E74726F, 0x6C205374, 0x69636B20, 0x4C656674, 0x206F7220,
    0x52696768, 0x7420746F, 0x2073656C, 0x65637420, 0x4D616368, 0x696E6520, 0x53657474, 0x696E6773,
    0x2E000000, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E82CC, 0x8DB68945,  /* fzgx-allow: A1 retail data bytes */
    0x82C58141, 0x837D8356, 0x839382F0, 0x835A8362, 0x83658342, 0x8393834F, 0x82B582C4, 0x82AD82BE,
    0x82B382A2, 0x81420000, 0x20456E74, 0x65720000, 0x208C8892, 0xE8000000, 0x2043616E, 0x63656C00,  /* fzgx-allow: A1 retail data bytes */
    0x20834C83, 0x83839383, 0x5A838B00, 0x20436861, 0x6E676520, 0x436F6C6F, 0x72000000, 0x20904691,
    0xD682A600, 0x20526574, 0x75726E20, 0x0, 0x2096DF82, 0xE9000000, 0x2044656C, 0x65746520,
    0x0, 0x208FC182, 0xB7000000, 0x204C6F61, 0x64204768, 0x6F737400, 0x20835381, 0x5B835883,
    0x67838D81, 0x5B836800, 0x2053656C, 0x65637420, 0x47686F73, 0x74000000, 0x20835381, 0x5B835883,
    0x67914991, 0xF0000000, 0x2050656E, 0x2073697A, 0x65000000, 0x20837983, 0x93835483, 0x43835900,
    0x20526F74, 0x61746500, 0x2089F193, 0x5D000000, 0x20496E76, 0x65727400, 0x2094BD93, 0x5D000000,
    0x2048656C, 0x70000000, 0x20837783, 0x8B837600, 0x20536176, 0x65000000, 0x20835A81, 0x5B837500,
    0x204C6F61, 0x64204761, 0x72616765, 0x0, 0x20834B83, 0x8C815B83, 0x57838D81, 0x5B836800,
    0x2053656C, 0x65637420, 0x736C6F74, 0x0, 0x20835883, 0x8D836283, 0x67914991, 0xF0000000,
    0x20506565, 0x6C206F66, 0x66200000, 0x2082CD82, 0xAA82B700, 0x20446966, 0x66696375, 0x6C747981,
    0x46000000, 0x2093EF88, 0xD5937881, 0x46000000, 0x54686520, 0x4E657874, 0x20436F75, 0x72736520,
    0x69732025, 0x732E0000, 0x8E9F82CC, 0x8352815B, 0x835882CD, 0x257382C5, 0x82B78142, 0x0,
    (u32)lbl_1_data_4120C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41230__fzgx_offset_0, (u32)lbl_1_data_41274__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41294__fzgx_offset_0, (u32)lbl_1_data_412B8__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_412FC__fzgx_offset_0, (u32)lbl_1_data_41340__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41348__fzgx_offset_0,
    (u32)lbl_1_data_41350__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41358__fzgx_offset_0, (u32)lbl_1_data_41364__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41374__fzgx_offset_0, (u32)lbl_1_data_4137C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41388__fzgx_offset_0, (u32)lbl_1_data_41390__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4139C__fzgx_offset_0,
    (u32)lbl_1_data_413A4__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_413B0__fzgx_offset_0, (u32)lbl_1_data_413C0__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_413D0__fzgx_offset_0, (u32)lbl_1_data_413E0__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_413EC__fzgx_offset_0, (u32)lbl_1_data_413F8__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41400__fzgx_offset_0,
    (u32)lbl_1_data_41408__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41410__fzgx_offset_0, (u32)lbl_1_data_41418__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41420__fzgx_offset_0, (u32)lbl_1_data_41428__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41430__fzgx_offset_0, (u32)lbl_1_data_41438__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41448__fzgx_offset_0,
    (u32)lbl_1_data_41458__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41468__fzgx_offset_0, (u32)lbl_1_data_41478__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_41484__fzgx_offset_0, (u32)lbl_1_data_4148C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0,
    (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4149C__fzgx_offset_0, (u32)lbl_1_data_414A8__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_4122C__fzgx_offset_0, (u32)lbl_1_data_414C0__fzgx_offset_0,
    0x5, 0x1, 0x3, 0x3, 0x3, 0x1, 0x4, 0x1,
    0x4, 0x2, 0x4, 0x1, 0x1, 0x4, 0x2, 0x1,
    0x2, 0x3, 0x2, 0x3, 0x2, 0x2, 0x2, 0x3,
    0x5, 0x1, 0x4, 0x5, 0x2, 0x2, 0x2, 0x2,
    0x3, 0x2, 0x3, 0x2, 0x5, 0x1, 0x3, 0x2,
    0x4, 0x1, 0x2, 0x4, 0x1, 0x3, 0x1, 0x4,
    0x1, 0x2, 0x4, 0x3, 0x3, 0x1, 0x3, 0x3,
    0x1, 0x5, 0x2, 0x2, 0x5, 0x2, 0x2, 0x5,
    0x1, 0x3, 0x2, 0x1, 0x5, 0x1, 0x3, 0x3,
    0x2, 0x1, 0x5, 0x4, 0x1, 0x4, 0x3, 0x1,
    0x4, 0x5, 0x2, 0x2, 0x1, 0x2, 0x5, 0x1,
    0x5, 0x1, 0x1, 0x2, 0x4, 0x1, 0x2, 0x5,
    0x5, 0x1, 0x3, 0x3, 0x3, 0x1, 0x2, 0x1,
    0x5, 0x4, 0x1, 0x4, 0x2, 0x3, 0x2, 0x4,
    0x2, 0x1, 0x2, 0x4, 0x2, 0x1, 0x4, 0x2,
    0x2, 0x2, 0x3, 0x506C6561, 0x73652077, 0x61697420, 0x61206D6F, 0x6D656E74,
    0x2E200000, 0x82B582CE, 0x82E782AD, 0x82A891D2, 0x82BF89BA, 0x82B382A2, 0x81420000, (u32)lbl_1_data_418A4__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_1_data_418BC__fzgx_offset_0, (u32)lbl_1_data_418BC__fzgx_offset_0, (u32)lbl_1_data_418BC__fzgx_offset_0, (u32)lbl_1_data_418BC__fzgx_offset_0, (u32)lbl_1_data_418BC__fzgx_offset_0, 0x82A982BB, 0x82AD82B6, 0x82E382A4,
    0x82B5205B, 0x20302E30, 0x3C2D3E31, 0x2E30205D, 0x2082B382, 0xA282B182, 0xA482BB82, 0xAD82B682,
    0xE382A482, 0xB50A0000, 0x2A0A0000, 0x25640000, 0x4E554C4C, 0xA000000, 0x25645020, 0x834A8389,
    0x815B5B25, 0x645D0A00, 0x82A482B5, 0x82EB82E4, 0x82D182B3, 0x82B382EA, 0x0, 0x82A482B5,  /* fzgx-allow: A1 retail data bytes */
    0x82EB82AA, 0x82DD82D0, 0x82A982EA, 0x0, 0x81F482C9, 0x82E182F1, 0x82AC82E7, 0x82B781F4,
    0x0, 0x8358815B, 0x83558393, 0x819A82AD, 0x82DD82B1, 0x0, 0x82728272, 0x8B898389,
    0x8343835A, 0x83938358, 0x0, 0x837D8358, 0x835E815B, 0x83898343, 0x835A8393, 0x83580000,
    0x83708343, 0x838D8362, 0x83678CF3, 0x95E290B6, 0x0, 0x82528251, 0x8B898389, 0x8343835A,
    0x83938358, 0x0, 0x73656C5F, 0x73746174, 0x69635F64, 0x6973702E, 0x63000000, 0x4572726F,
    0x72213A73, 0x656C735F, 0x64697370, 0x5F746174, 0x65626F75, 0x200A0000, 0x4572726F, 0x72213A73,
    0x656C735F, 0x64697370, 0x5F746174, 0x65626F75, 0x5F6B6167, 0x69200A00, 0x25730A00, (u32)fn_1_1358BC__fzgx_offset_C0,
    (u32)fn_1_1358BC__fzgx_offset_E4, (u32)fn_1_1358BC__fzgx_offset_108, (u32)fn_1_1358BC__fzgx_offset_128, (u32)fn_1_1358BC__fzgx_offset_CC, (u32)fn_1_1358BC__fzgx_offset_F0, (u32)fn_1_1358BC__fzgx_offset_114, (u32)fn_1_1358BC__fzgx_offset_128, (u32)fn_1_1358BC__fzgx_offset_D8,
    (u32)fn_1_1358BC__fzgx_offset_FC, (u32)fn_1_1358BC__fzgx_offset_120, (u32)fn_1_135B80__fzgx_offset_7C, (u32)fn_1_135B80__fzgx_offset_A0, (u32)fn_1_135B80__fzgx_offset_C4, (u32)fn_1_135B80__fzgx_offset_E4, (u32)fn_1_135B80__fzgx_offset_88, (u32)fn_1_135B80__fzgx_offset_AC,
    (u32)fn_1_135B80__fzgx_offset_D0, (u32)fn_1_135B80__fzgx_offset_E4, (u32)fn_1_135B80__fzgx_offset_94, (u32)fn_1_135B80__fzgx_offset_B8, (u32)fn_1_135B80__fzgx_offset_DC, (u32)fn_1_135D7C__fzgx_offset_1F0, (u32)fn_1_135D7C__fzgx_offset_214, (u32)fn_1_135D7C__fzgx_offset_238,
    (u32)fn_1_135D7C__fzgx_offset_258, (u32)fn_1_135D7C__fzgx_offset_1FC, (u32)fn_1_135D7C__fzgx_offset_220, (u32)fn_1_135D7C__fzgx_offset_244, (u32)fn_1_135D7C__fzgx_offset_258, (u32)fn_1_135D7C__fzgx_offset_208, (u32)fn_1_135D7C__fzgx_offset_22C, (u32)fn_1_135D7C__fzgx_offset_250,
    0x3F3F3F3F, 0x3F0A0000, 0x3F3F3F3F, 0x0, 0x25346400, 0x3F000000, (u32)fn_1_1373B0__fzgx_offset_AC, (u32)fn_1_1373B0__fzgx_offset_B4,
    (u32)fn_1_1373B0__fzgx_offset_BC, (u32)fn_1_1373B0__fzgx_offset_C4, (u32)fn_1_1373B0__fzgx_offset_CC, (u32)fn_1_1373B0__fzgx_offset_D4, (u32)fn_1_1373B0__fzgx_offset_DC, (u32)fn_1_1373B0__fzgx_offset_E4, (u32)fn_1_1373B0__fzgx_offset_EC, (u32)fn_1_1373B0__fzgx_offset_F4,
    0x42414C41, 0x4E434500
};
static u32 fzgx_pool_data_lbl_1_data_40F58_BA8[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x20202020, 0x434F4C4F, 0x52202020, 0x204F4B00
};
static u32 fzgx_pool_data_lbl_1_data_40F58_BB8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x83A183AF, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_40F58_BC0[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x839F0000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_40F58(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_40F58;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_40F58_BA8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_40F58_BB8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_40F58_BC0;
}
#pragma section code_type ".text"

void fn_1_138E44(s32 x, s32 y, s32 idx) {
    u8 t;
    s32 tx;
    s32 col;
    s32 tc;
    s32 row;
    s32 ty;
    s16 v;
    FontDrawPacket p;

    v = lbl_1_bss_8B3A0.unk_0[idx].unk_E;
    t = fn_1_141F94(idx & 0xFF);

    p = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    tc = t;
    p.image = 0x9D0C;
    p.x = x;
    p.y = y;
    p.z = 100 - tc;
    fn_1_4F734(&p);
    fn_1_51564(0, 0, 24, 20, 2, 2);

    p = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    p.image = 0x9D0B;
    p.x = x + 18;
    p.y = y + 18;
    p.z = lbl_1_rodata_86D0;
    p.flags = 10;
    col = tc % 2;
    row = t / 2;
    fn_1_5158C(&p, 0x9D0B, col, row);
    fn_1_4F734(&p);

    p = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    p.image = 0x9D08;
    p.x = x + 7;
    p.y = y + 33;
    p.z = lbl_1_rodata_86D0;
    fn_1_4F734(&p);

    fn_1_135D7C(x + 36, y + 18, 9, v, 0, idx, 0, lbl_1_rodata_8A50, lbl_1_rodata_8A50, lbl_1_rodata_87DC);
    fn_1_136CC4(x + 16, y + 42, v, idx);

    fn_1_49410();
    fn_1_495C8((void *)10);
    fn_1_494DC(4);
    fn_1_4966C(lbl_1_rodata_8B40, lbl_1_rodata_861C);
    fn_1_4954C(lbl_1_rodata_8B84);
    tx = col * 301;
    fn_1_496FC(tx + 312, ty = row * 201 + 242);
    fn_1_4A0D8((const char *)fzgx_pool_data_lbl_1_data_40F58_BA8);

    fn_1_49410();
    fn_1_495C8((void *)10);
    fn_1_4954C(lbl_1_rodata_863C);
    fn_1_4955C(lbl_1_rodata_85EC, lbl_1_rodata_85EC);
    fn_1_496FC(tx + 218, ty);
    fn_1_4A0D8((const char *)fzgx_pool_data_lbl_1_data_40F58_BB8);
    fn_1_4954C(lbl_1_rodata_863C);
    fn_1_496FC(tx + 290, ty);
    fn_1_4A0D8((const char *)fzgx_pool_data_lbl_1_data_40F58_BC0);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_138E44 */

/* fzgx:begin fn_1_13923C */
struct fn_1_13923C_Copy88 { u32 a[22]; };


void fn_1_13923C(u32 arg0, u32 arg1) {
    f32 v0;
    u32 v1;
    f32 v2;
    FontDrawPacket loc_8;
    /* frame */
    loc_8 = *(FontDrawPacket *)&(*((u32 *)&lbl_1_rodata_26F8));
    v0 = (f32)(s32)arg0;
    v1 = (0x10000 - 25334);
    loc_8.image = v1;
    v2 = (f32)(s32)arg1;
    loc_8.x = v0;
    loc_8.y = v2;
    loc_8.z = (*((f32 *)&lbl_1_rodata_8840));
    fn_1_4F734((FontDrawPacket *)&loc_8);
}
/* fzgx:end fn_1_13923C */

/* fzgx:begin fn_1_1392E0 */
typedef struct {
    u8 pad_0[0x54];
    f32 unk_54;
} Fn1392E0Arg0;

typedef struct {
    f32 unk_0;
    f32 unk_4;
    u8 pad_8[0x1C];
    f32 unk_24;
    f32 unk_28;
} Fn1392E0Arg1;

typedef struct {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x10];
} Fn1392E0Elem;

void fn_1_1392E0(Fn1392E0Arg0 *arg0, Fn1392E0Arg1 *arg1) {
    Obj_1_bss_8B3A0 *base;
    u8 *ptr;
    s32 index;
    s32 offset;
    f32 value;

    index = (s32)arg0->unk_54;
    base = &lbl_1_bss_8B3A0;
    ptr = (u8 *)base + 0x9F;
    value = (f32)(u8)ptr[index] / lbl_1_rodata_85F4;
    offset = ((Fn1392E0Elem *)((u8 *)base))[index].unk_E;

    if (base->unk_94 & 0x40000000) {
        if ((u8)fn_1_D6698() == 0) {
            s8 a;
            s8 b;

            fn_1_D66F8(0, (u8 *)(s8 *)(&a), &b);
            offset = a;
            value = (f32)(u8)ptr[0] / lbl_1_rodata_85F4;
        }
    }

    fn_1_139440(value, (s32)arg1->unk_0, (s32)arg1->unk_4,
                (s32)(arg1->unk_24 - arg1->unk_0),
                (s32)(arg1->unk_28 - arg1->unk_4), offset, index);
}
/* fzgx:end fn_1_1392E0 */

/* fzgx:begin fn_1_139A3C */
int fn_1_139A3C(int arg0) {
    s32 index = (s16)arg0;

    if (((u32 *)((u8 *)(((s32 *)&lbl_1_bss_8B3A0)) + 0xF0))[index] == 0) {
        lbl_1_bss_8E3D0[index] = 0;
    }

    if (((s32 *)((u8 *)(((s32 *)&lbl_1_bss_8B3A0)) + 0x100))[index] == 7 &&
        ((s32 *)((u8 *)(((s32 *)&lbl_1_bss_8B3A0)) + 0x110))[index] != 0) {
        lbl_1_bss_8E3D0[index] = 1;
    } else if (((s32 *)((u8 *)(((s32 *)&lbl_1_bss_8B3A0)) + 0x100))[index] == 8 ||
               ((s32 *)((u8 *)(((s32 *)&lbl_1_bss_8B3A0)) + 0x100))[index] == 9) {
        if (((s32 *)((u8 *)(((s32 *)&lbl_1_bss_8B3A0)) + 0x110))[index] == 0) {
            lbl_1_bss_8E3D0[index] = 0;
        }
    }

    return lbl_1_bss_8E3D0[index];
}
/* fzgx:end fn_1_139A3C */

/* fzgx:begin fn_1_139AEC noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u8 pad0[0x20];
    void *unk_20;
    u8 pad24[0x14];
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    u8 pad50[0x14];
    s16 unk_64;
} Arg0Struct;

extern Sp8 lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_8BA8;
extern const f32 lbl_1_rodata_86FC;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_8664;
extern const f32 lbl_1_rodata_8BAC;
extern const f32 lbl_1_rodata_8BB0;
extern const f32 lbl_1_rodata_8BB4;
extern const f32 lbl_1_rodata_87D0;

extern u8 fn_1_D6740(u8);
extern u8 fn_1_D66B0(void);
extern void fn_1_8CED0(void *, s32, s32);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void *, Sp8 *, void (*)(void), void *);

#pragma opt_common_subs off
void fn_1_139AEC(Arg0Struct *arg0) {
    Sp8 sp8 = lbl_1_rodata_26F8;
    s32 var_r31;
    s16 i;
    s16 var_r29;

    arg0->unk_38 = lbl_1_rodata_85F0;
    arg0->unk_3C = lbl_1_rodata_8B9C;
    arg0->unk_40 = lbl_1_rodata_8BA0;
    arg0->unk_44 = lbl_1_rodata_85F0;
    arg0->unk_48 = lbl_1_rodata_861C;
    arg0->unk_4C = lbl_1_rodata_861C;

    sp8 = lbl_1_rodata_26F8;

    sp8.unk_4 = lbl_1_rodata_8BA4;
    sp8.unk_8 = lbl_1_rodata_8BA8;
    sp8.unk_C = lbl_1_rodata_86FC;
    sp8.unk_30 = 10;

    if (lbl_1_bss_8CA28.unk_0 != 0) {
        sp8.unk_10 *= lbl_1_rodata_8638;
        sp8.unk_14 *= lbl_1_rodata_8638;
    }

    if (!(lbl_1_bss_8B3A0.unk_94 & 0x40000000)) {
        return;
    }

    sp8.unk_10 *= lbl_1_rodata_8664;
    sp8.unk_14 *= lbl_1_rodata_8BAC;
    sp8.unk_10 *= lbl_1_rodata_8BB0;
    sp8.unk_14 *= lbl_1_rodata_8BB0;
    sp8.unk_8 = lbl_1_rodata_8BB4;

    i = 0;
    var_r29 = 1;
    var_r31 = 0x64;
    for (; i < 4; i++) {
        if (!fn_1_D6740(i)) {
            continue;
        }
        if (i == fn_1_D66B0()) {
            continue;
        }

        sp8.unk_4 = (var_r29 - 1) * 87 + 66;
        fn_1_8CED0((u8 *)arg0->unk_20 + var_r31, 140, 100);
        *(f32 *)((u8 *)arg0->unk_20 + var_r31 + 0x44) = lbl_1_rodata_87D0;
        arg0->unk_64 = i;
        fn_1_8D3F8((u8 *)arg0->unk_20 + var_r31, &sp8, fn_1_131C08, arg0);
        var_r31 += 100;
        var_r29++;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_139AEC */

/* fzgx:begin fn_1_139D60 */
/* 0x20-byte stride view of the state table at lbl_1_bss_8B3A0. */
typedef struct {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x10];
} BssEntry20;

typedef struct {
    u8 pad_0[0x18];
    f32 unk_18;
    f32 unk_1C;
    void *unk_20;
    u8 pad_24[0x14];
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    u8 pad_50[0x14];
    u16 unk_64;
    u8 pad_66[0x1A];
    void *unk_80;
} StaticDispObj;

void fn_1_139D60(StaticDispObj *self) {
    BssEntry20 *entries = (BssEntry20 *)&lbl_1_bss_8B3A0;
    s16 index;
    int offset;
    u8 values[0x58];
    u32 *src;
    u32 *dst;
    int count;

    index = *(s16 *)self;
    offset = entries[index].unk_E;
    self->unk_38 = lbl_1_rodata_85F0;
    self->unk_3C = lbl_1_rodata_8B9C;
    self->unk_40 = lbl_1_rodata_8BA0;
    self->unk_44 = lbl_1_rodata_85F0;
    self->unk_48 = lbl_1_rodata_861C;
    self->unk_4C = lbl_1_rodata_861C;

    src = (u32 *)lbl_1_rodata_26F8 - 1;
    dst = (u32 *)values - 1;
    count = 11;
    while (count--) {
        dst[1] = src[1];
        dst[2] = src[2];
        dst += 2;
        src += 2;
    }

    ((f32 *)((u8 *)values - 4))[2] = lbl_1_rodata_8BA4;
    if (offset < 0x29) {
        offset = ((s16 *)lbl_1_rodata_8558)[offset] + 0xf0;
    } else {
        offset = 0xf0;
    }
    ((f32 *)((u8 *)values - 4))[3] = (f32)offset;
    ((f32 *)((u8 *)values - 4))[4] = lbl_1_rodata_86FC;
    ((u32 *)((u8 *)values - 4))[13] = 10;
    if (lbl_1_bss_8CA28.unk_0 != 0) {
        ((f32 *)((u8 *)values - 4))[5] *= lbl_1_rodata_8638;
        ((f32 *)((u8 *)values - 4))[6] *= lbl_1_rodata_8638;
    }

    self->unk_64 = (u8)fn_1_D66B0();
    fn_1_8CED0(self->unk_20, 0x230, 0x190);
    ((f32 *)self->unk_20)[0x44 / 4] = lbl_1_rodata_87D0;
    if ((lbl_1_bss_8B3A0.unk_94 & 0x40000000) != 0) {
        self->unk_64 = (u8)fn_1_D66B0();
    }
    fn_1_8D3F8(self->unk_20, values, fn_1_131C08, self);
}
/* fzgx:end fn_1_139D60 */

/* fzgx:begin fn_1_139F18 */
typedef struct {
    u8 pad_0[0x44];
    f32 unk_44;
} Fn139F18Child;

typedef struct {
    u8 pad_0[0x24];
    Fn139F18Child* unk_24;
    u8 pad_28[0x10];
    f32 unk_38;
    f32 unk_3c;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4c;
} Fn139F18Obj;



void fn_1_139F18(Fn139F18Obj* self) {
    Fn139F18Data local;

    self->unk_38 = lbl_1_rodata_861C;
    self->unk_3c = lbl_1_rodata_85F0;
    self->unk_40 = lbl_1_rodata_8BB8;
    self->unk_44 = lbl_1_rodata_861C;
    self->unk_48 = lbl_1_rodata_85F0;
    self->unk_4c = lbl_1_rodata_861C;

    local = (*((Fn139F18Data *)&lbl_1_rodata_26F8));
    ((f32*)local.value)[1] = lbl_1_rodata_8BBC;
    ((f32*)local.value)[2] = lbl_1_rodata_86F8;
    ((f32*)local.value)[3] = lbl_1_rodata_8B84;
    local.value[12] = 10;

    if (lbl_1_bss_8CA28.unk_0 != 0) {
        ((f32*)local.value)[4] *= lbl_1_rodata_8638;
        ((f32*)local.value)[5] *= lbl_1_rodata_8638;
    }

    fn_1_8CED0(self->unk_24, 0x280, 0x18c);
    self->unk_24->unk_44 = lbl_1_rodata_87D0;
    fn_1_8D3F8(self->unk_24, &local, fn_1_131B90, self);
}
/* fzgx:end fn_1_139F18 */

/* fzgx:begin fn_1_13A038 noprologue */
#include "rel/main_rel/sel_static_disp.h"

typedef struct {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    u32 unk_30;
    u8 unk_34[0x24];
} Track;

typedef struct {
    u16 unk_00;
    u8 unk_02[0x1E];
    u32 unk_20;
    u8 unk_24[0x14];
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
} Car;

extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8BC0;
extern const f32 lbl_1_rodata_8BC4;
extern const f32 lbl_1_rodata_8BC8;
extern const f32 lbl_1_rodata_8BCC;
extern const f32 lbl_1_rodata_8BD0;
extern const f32 lbl_1_rodata_8B60;
extern const f32 lbl_1_rodata_8BD4;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_8BD8;
extern const f32 lbl_1_rodata_87D0;
extern Track lbl_1_rodata_26F8;

typedef struct {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    u16 unk_28;
    u16 unk_2A;
    u16 unk_2C;
    u16 unk_2E;
    u16 unk_30;
    u16 unk_32;
    u32 unk_34;
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    u32 unk_3C;
    u8 unk_40[4];
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    u16 unk_54;
    u16 unk_56;
    u32 unk_58;
    u8 unk_5C[4];
} Sig_fn_1_8CED0_Fn1_8CED0State;

typedef struct {
    f32 field_00;
    f32 field_04;
    f32 field_08;
    f32 field_0c;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1c;
    f32 field_20;
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
    u8 field_40[4];
    f32 field_44;
    f32 field_48;
    f32 field_4c;
    f32 field_50;
    s16 field_54;
    u8 pad_56[2];
    s32 field_58;
    u8 field_5c[4];
    u32 field_60;
} Sig_fn_1_8D3F8_Fn1_8D3F8Car;

extern void fn_1_8CED0(Sig_fn_1_8CED0_Fn1_8CED0State *, u16, u16);
extern u32 fn_1_8D3F8(Sig_fn_1_8D3F8_Fn1_8D3F8Car *, Track *, void (*)(void), void *);
extern void fn_1_131C08(void);
extern void _savegpr_27(void);
extern void _restgpr_27(void);

#pragma opt_loop_invariants off
void fn_1_13A038(Car *car)
{
    f32 *fzgx_value;
    Track v;
    s32 x;
    u32 off;
    s32 i;

    car->unk_38 = lbl_1_rodata_861C;
    car->unk_3C = lbl_1_rodata_8BC0;
    fzgx_value = &(car->unk_40);
    *fzgx_value = lbl_1_rodata_8BC4;
    car->unk_44 = lbl_1_rodata_861C;
    car->unk_4C = lbl_1_rodata_861C;

    i = 0;
    x = 140;
    off = 0;

    for (; i < 4; i++) {
        s16 kind = ((Obj_1_bss_8B3A0 *)((u8 *)&lbl_1_bss_8B3A0 + i * 0x20))->unk_E;

        if (kind == -1)
            continue;

        car->unk_00 = (u16)i;

        if (kind == 0x20)
            car->unk_48 = lbl_1_rodata_8BC8;
        else if (kind == 0x27)
            car->unk_48 = lbl_1_rodata_8BCC;
        else
            car->unk_48 = lbl_1_rodata_8BD0;

        v = lbl_1_rodata_26F8;
        v.unk_04 = lbl_1_rodata_8B60;
        v.unk_08 = (f32)(s32)x;
        v.unk_0C = lbl_1_rodata_8BD4;
        v.unk_30 = 10;

        if (lbl_1_bss_8CA28.unk_0 != 0) {
            v.unk_10 *= lbl_1_rodata_8638;
            v.unk_14 *= lbl_1_rodata_8638;
        }

        v.unk_10 *= lbl_1_rodata_8BD8;
        v.unk_14 *= lbl_1_rodata_8BD8;

        fn_1_8CED0((Sig_fn_1_8CED0_Fn1_8CED0State *)(car->unk_20 + off), 0x1A0, 0xC0);
        *(f32 *)(car->unk_20 + off + 0x44) = lbl_1_rodata_87D0;
        fn_1_8D3F8((Sig_fn_1_8D3F8_Fn1_8D3F8Car *)(car->unk_20 + off), &v, fn_1_131C08, car);

        x += 201;
        off += 100;
    }
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_13A038 */

/* fzgx:begin fn_1_13A21C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"
#include "types.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern Word8 lbl_1_rodata_86D8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern f32 lbl_1_rodata_26F8[22];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern u16 fn_1_486C4(u32 value);
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_88B4;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_88B8;
extern const u32 lbl_1_rodata_8860[6];
extern const u32 lbl_1_rodata_8878[6];
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_48690(u32 unused);
extern void fn_1_52070(u32 value);
extern void fn_1_135D7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_4965C(u8 value);
extern void fn_1_495C8(void* arg0);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 value);
extern void fn_1_49590(f32 value);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A28;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern s32 lbl_1_rodata_8A34;
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_5233C(void* arg0, void* arg1);
extern u32 fn_1_12F118(void);
extern u8* fn_1_36AD0();
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_137364();
extern void fn_1_14E9E4(int arg0, void *arg1);
extern const f32 lbl_1_rodata_8840;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_85F4;
extern int fn_1_D6698(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern void fn_1_139440(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
extern s32 lbl_1_bss_8E3D0[];
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_8BA8;
extern const f32 lbl_1_rodata_8664;
extern const f32 lbl_1_rodata_8BAC;
extern const f32 lbl_1_rodata_8BB0;
extern const f32 lbl_1_rodata_8BB4;
extern const f32 lbl_1_rodata_87D0;
extern int fn_1_D6740();
extern int fn_1_D66B0(void);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern u8 lbl_1_rodata_8558[84];
extern const f32 lbl_1_rodata_8C10;
extern void fn_1_4CF3C(const char *format, f32 x, ...);
extern s16 fn_1_12C930(void* arg0);
extern u8 lbl_1_data_21078[180];
extern f32 fn_1_4B068(const char*);
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8C74;
extern PtrTab lbl_1_rodata_8C4C;
extern s32 fn_1_13B548(s32, s32, s32, u8);
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8D78;
extern const f32 lbl_1_rodata_8D7C;
extern u16 lbl_1_rodata_8CB0[200];
extern u8 lbl_1_bss_9C;
extern void fn_1_133E04(void* arg0, s32 arg1);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_140EE8(u8 arg0, int arg1, int arg2);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern void fn_1_138144(void* arg0, int arg1);
extern u32 fn_1_13C5EC(u8);
extern u32 fn_1_13F7F8(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8DBC;
extern const f32 lbl_1_rodata_8DCC;
extern const f32 lbl_1_rodata_87B4;
extern const u32 lbl_1_rodata_8DC0;
extern const f32 lbl_1_rodata_8818;
extern const u32 lbl_1_rodata_8DC4;
extern const f32 lbl_1_rodata_8DD0;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8A58;
extern int fn_1_B7E98(int index);
extern void fn_1_13EE60();
extern u32 fn_1_13EF64(u32, u32, u32, void *, u32, void *, u32, f32);
extern u32 lbl_1_rodata_8E8C;
extern u8 lbl_1_rodata_8EB4[];
extern char *fn_80083DB0(char *dst, const char *src);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 lbl_1_rodata_91C0[11];
extern const f32 lbl_1_rodata_91EC;
extern const f32 lbl_1_rodata_91F0;
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern void fn_1_494DC(s16 index);
extern const f32 lbl_1_rodata_9208;
extern void fn_1_4966C(f32 value1, f32 value2);
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern const f32 lbl_1_rodata_8E9C;
extern const f64 lbl_1_rodata_93E8;
extern f32 lbl_1_rodata_93F0[15];
extern f32 lbl_1_rodata_92C0[22];
extern f32 lbl_1_rodata_970C[71];
extern const f32 lbl_1_rodata_946C;
extern void fn_1_149C2C();
extern struct fn_1_149C64_lbl_1_bss_8E43C lbl_1_bss_8E43C;
extern struct fn_1_149C64_lbl_1_bss_8E440 lbl_1_bss_8E440;
extern void fn_1_149CA4(u32, u32, u32, u32);
extern void fn_1_520A0(void);
extern f64 lbl_1_rodata_9480[80];
extern f32 lbl_1_rodata_942C[16];
extern f32 fn_1_521B8(s32 value);
extern f32 fn_1_520F8(s32 value);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_1_520CC(void);
extern const f32 lbl_1_rodata_99A4;
extern u8 fn_1_5910(void);
extern u8 fn_1_149FB4(s32 index);
extern s32 fn_1_3F864(void);
extern void fn_1_A52B0(s32 index);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 fn_1_1556B4(u32, u32);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0();
extern s16 fn_1_14F344(s16);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void fn_1_151C3C(u16 value1, u16 value2);
extern void fn_1_556B8(void *value);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern const f64 lbl_1_rodata_B8D0;
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *fn_800839D8(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_1375C0(int arg0, void* arg1, void* arg2, void* arg3, void* arg4);
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern void fn_1_131B90(void);
extern void fn_1_13A9B8();
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void fn_1_13E080(void* arg0, void* arg1, void* arg2, int arg3);
extern void fn_1_144F40(u32 arg0, u32 arg1);
extern u8 fn_1_155F8C(void);
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, u32 arg3);
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);
extern s32 fn_1_45D0();
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 fn_80008BEC(u32 arg0, int arg1, int arg2);
extern void fn_1_7F3AC(void* object);


typedef struct fn_1_13A21C_Player {
    u8 pad_0[0xE];
    s16 character;
    u8 pad_10[0x10];
} fn_1_13A21C_Player;

typedef struct fn_1_13A21C_Obj {
    s16 player;
    u8 pad_2[0x1E];
    u8 *icons;
    u8 pad_24[0x14];
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
} fn_1_13A21C_Obj;



extern u8 fn_1_141F94(u32 arg0);
extern void fn_1_8CED0(void *arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void *arg0, void *arg1, void *arg2, void *arg3);

void fn_1_13A21C(fn_1_13A21C_Obj *obj) {
    FontDrawPacket packet;
    s32 offset;
    s32 i;
    s16 character;
    u8 slot;

    obj->unk_38 = 0.6f;
    obj->unk_3C = -1.3f;
    obj->unk_40 = -16.0f;
    obj->unk_44 = 0.2f;
    obj->unk_4C = 0.0f;
    for (i = 0, offset = 0; i < 4; i++) {
        character = ((fn_1_13A21C_Player *)&lbl_1_bss_8B3A0)[i].character;
        slot = fn_1_141F94((u8)i);
        if (character == -1) {
            continue;
        }
        obj->player = i;
        if (character == 0x20) {
            obj->unk_48 = 1.12f;
        } else if (character == 0x27) {
            obj->unk_48 = 0.6f;
        } else if (character == 0x1D) {
            obj->unk_48 = 0.12f;
        } else {
            obj->unk_48 = 0.0f;
        }
        packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
        packet.x = (slot % 2) * 0x12D + 0xE3;
        packet.y = (slot >> 1) * 0xCA + 0xB0;
        packet.z = 161.0f;
        packet.flags = 10;
        if (*(u8 *)&lbl_1_bss_8CA28) {
            packet.scale_x *= 2.0f;
            packet.scale_y *= 2.0f;
        }
        packet.scale_x *= 1.1f;
        packet.scale_y *= 1.1f;
        fn_1_8CED0(obj->icons + offset, 0xA0, 0x78);
        *(f32 *)(obj->icons + offset + 0x44) = 30.0f;
        fn_1_8D3F8(obj->icons + offset, &packet, fn_1_131C08, obj);
        offset += 0x64;
    }
}
/* fzgx:end fn_1_13A21C */

/* fzgx:begin fn_1_13A460 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

struct fn_1_13A460_Arg0 {
    u16 unk_0;
    u8 pad_2[0x22];
    u32 unk_24;
    u8 pad_28[0x10];
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
};

struct fn_1_13A460_Loc {
    u32 a0[1];
    f32 f_04;
    f32 f_08;
    f32 f_0C;
    f32 f_10;
    f32 f_14;
    u8 pad_18[0x18];
    u32 n_30;
    u8 pad_34[0x24];
};

struct fn_1_13A460_Ent {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x10];
};

extern const struct fn_1_13A460_Loc lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_87B8;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_8BF0;
extern const f32 lbl_1_rodata_8BF4;
extern const f32 lbl_1_rodata_8664;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_8BF8;
extern const f32 lbl_1_rodata_880C;
extern const f32 lbl_1_rodata_8BFC;
extern const f32 lbl_1_rodata_8B28;
extern const f32 lbl_1_rodata_87D0;
extern const f64 lbl_1_rodata_8600;

typedef struct {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    u16 unk_28;
    u16 unk_2A;
    u16 unk_2C;
    u16 unk_2E;
    u16 unk_30;
    u16 unk_32;
    u32 unk_34;
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    u32 unk_3C;
    u8 unk_40;
    u8 unk_41[3];
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    u16 unk_54;
    u16 unk_56;
    u32 unk_58;
    u8 unk_5C[4];
} Sig_fn_1_8CED0_Fn1_8CED0State;
extern void fn_1_8CED0(Sig_fn_1_8CED0_Fn1_8CED0State *, u16, u16);

typedef struct Sig_fn_1_131B90_Obj Sig_fn_1_131B90_Obj;
struct Sig_fn_1_131B90_Obj {
    s16 index;
    u8 pad_2[2];
    u32 field_4;
    u32 field_8;
    u8 pad_c[0x2c];
    u32 field_38;
    u32 field_3c;
    u32 field_40;
    u32 field_44;
    u32 field_48;
    u32 field_4c;
    u32 field_50[1];
};
extern s32 fn_1_131B90(Sig_fn_1_131B90_Obj *);

typedef struct Sig_fn_1_8D3F8_Fn1_8D3F8Car {
    f32 field_00;
    f32 field_04;
    f32 field_08;
    f32 field_0c;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1c;
    f32 field_20;
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
    u8 field_40[4];
    f32 field_44;
    f32 field_48;
    f32 field_4c;
    f32 field_50;
    s16 field_54;
    u8 pad_56[2];
    s32 field_58;
    u8 field_5c[4];
    u32 field_60;
} Sig_fn_1_8D3F8_Fn1_8D3F8Car;
extern u32 fn_1_8D3F8(Sig_fn_1_8D3F8_Fn1_8D3F8Car *, void *, u32 (*)(u32), u32);

extern void _savegpr_27(void);
extern void _restgpr_27(void);

#pragma opt_loop_invariants off
static inline f32 fn_1_13A460_read_pointer(struct fn_1_13A460_Loc * owner) { return owner->f_10; }
#pragma opt_lifetimes off
void fn_1_13A460(struct fn_1_13A460_Arg0 *arg0) {
    f32 *fzgx_value_;
    struct fn_1_13A460_Loc loc;
    s32 stepC9;
    s32 step64;
    s32 i = 0;
    f32 fzgx_live;
    f32 fzgx_live_;
    f32 fzgx_value;

    stepC9 = 0x9C;
    step64 = 0;

    arg0->unk_38 = lbl_1_rodata_87B8;
    arg0->unk_3C = lbl_1_rodata_85F0;
    arg0->unk_40 = lbl_1_rodata_8BF0;
    fzgx_value_ = &(arg0->unk_44);
    *fzgx_value_ = lbl_1_rodata_8BF4;
    arg0->unk_48 = lbl_1_rodata_8664;
    arg0->unk_4C = lbl_1_rodata_861C;

    for (; i < 4; i++) {
        s32 v = (s16)(((struct fn_1_13A460_Ent *)&lbl_1_bss_8B3A0)[i].unk_E);
        if (v != -1) {
            arg0->unk_0 = i;
            loc = lbl_1_rodata_26F8;
            loc.f_04 = lbl_1_rodata_8BF8;
            loc.f_08 = (f32)stepC9;
            loc.f_0C = lbl_1_rodata_880C;
            loc.n_30 = 10;
            if (lbl_1_bss_8CA28.unk_0 != 0) {
                fzgx_live = fn_1_13A460_read_pointer(&loc);
                fzgx_value = fzgx_live * lbl_1_rodata_8638;
                (void) fzgx_value;  /* fzgx: keeps the web at its definition */
                loc.f_10 = fzgx_value;
                loc.f_14 = loc.f_14 * lbl_1_rodata_8638;
            }
            fzgx_live = fn_1_13A460_read_pointer(&loc);
            loc.f_10 = fzgx_live * lbl_1_rodata_8BFC;
            fzgx_live_ = loc.f_14;
            loc.f_14 = fzgx_live_ * lbl_1_rodata_8BFC;
            if (v == 0x21) {
                loc.f_08 = loc.f_08 - lbl_1_rodata_8B28;
            }
            fn_1_8CED0((Sig_fn_1_8CED0_Fn1_8CED0State *)((u8 *)arg0->unk_24 + step64), 0x1A0, 0xC0);
            *(f32 *)((u8 *)arg0->unk_24 + step64 + 0x44) = lbl_1_rodata_87D0;
            fn_1_8D3F8((Sig_fn_1_8D3F8_Fn1_8D3F8Car *)((u8 *)arg0->unk_24 + step64), &loc, (u32 (*)(u32))fn_1_131B90, (u32)arg0);
            stepC9 += 0xC9;
            step64 += 0x64;
        }
    }
}
#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_1_13A460 */

/* fzgx:begin fn_1_13A654 noprologue */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct {
u8 pad_0[0x19];
u8 unk_19;
} Obj_1_bss_8B3A0_AtA4;
typedef struct {
s16 unk_0;
u8 pad_2[0x2];
s16 unk_4;
u8 pad_6[0x2];
s16 unk_8;
u8 pad_A[0x4];
s16 unk_E;
u8 pad_10[0x4];
u8 unk_14;
u8 pad_15[0x19];
s16 unk_2E;
u8 pad_30[0x5C];
s16 unk_8C;
u8 pad_8E[0x2];
s16 unk_90;
s16 unk_92;
u32 unk_94;
u8 pad_98[0x6];
u8 unk_9E;
u8 unk_9F;
u8 pad_A0[0x4];
Obj_1_bss_8B3A0_AtA4 *unk_A4;
u8 pad_A8[0x8];
s16 unk_B0;
s16 unk_B2;
u8 pad_B4[0xC];
s16 unk_C0;
s16 unk_C2;
u8 pad_C4[0xC];
s16 unk_D0;
s16 unk_D2;
u8 pad_D4[0xC];
u32 unk_E0;
u32 unk_E4;
u32 unk_E8;
u32 unk_EC;
u32 unk_F0;
u32 unk_F4;
u32 unk_F8;
u32 unk_FC;
u32 unk_100;
u32 unk_104;
u32 unk_108;
u32 unk_10C;
u32 unk_110;
u32 unk_114;
u32 unk_118;
u32 unk_11C;
u32 unk_120;
u32 unk_124;
u8 unk_128;
u8 unk_129;
u8 pad_12A[0x2];
s16 unk_12C;
s16 unk_12E;
s16 unk_130;
s16 unk_132;
s16 unk_134;
s16 unk_136;
s16 unk_138;
s16 unk_13A;
s16 unk_13C;
u8 pad_13E[0x2];
u32 unk_140;
u8 pad_144[0x2];
s16 unk_146;
s16 unk_148;
u8 pad_14A[0x2];
} Obj_1_bss_8B3A0;
extern Obj_1_bss_8B3A0 lbl_1_bss_8B3A0;


typedef struct {
u8 unk_0;
u8 pad_1[0x17];
} Obj_1_bss_8CA28;
extern Obj_1_bss_8CA28 lbl_1_bss_8CA28;


typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);


struct Elem { u8 pad_0[0xe]; s16 unk_E; u8 pad_10[0x10]; };
struct Arg { s16 index; u8 pad_2[0x22]; u8 *unk_24; u8 pad_28[0x10]; f32 f[6]; };


struct fn_1_13A654_Copy88 { f32 a[22]; };


extern const f32 lbl_1_rodata_861C;


extern const f32 lbl_1_rodata_8638;


extern const f32 lbl_1_rodata_87D0;
extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);


extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);


extern const f32 lbl_1_rodata_880C;


extern void fn_1_131B90(void);
extern const f32 lbl_1_rodata_8C00;
extern const f32 lbl_1_rodata_8C04;
extern const f32 lbl_1_rodata_8C08;
extern const f32 lbl_1_rodata_864C;
extern const f32 lbl_1_rodata_8C0C;
extern u8 fn_1_141F94(u32);


void fn_1_13A654(struct Arg *arg0) {
s32 off;
s32 i;
struct fn_1_13A654_Copy88 loc;
i = 0;
arg0->f[0] = lbl_1_rodata_861C;
arg0->f[1] = lbl_1_rodata_8C00;
arg0->f[2] = lbl_1_rodata_8C04;
arg0->f[3] = lbl_1_rodata_8C08;
arg0->f[4] = lbl_1_rodata_864C;
arg0->f[5] = lbl_1_rodata_861C;
off = 0;
for (; i < 4; i++) {
s16 v = (((struct Elem *)&lbl_1_bss_8B3A0))[i].unk_E;
u8 k = fn_1_141F94((u8)i);
if (v != -1) {
arg0->index = i;
loc = (*((struct fn_1_13A654_Copy88 *)&lbl_1_rodata_26F8));
loc.a[1] = (f32)((k % 2) * 300 + 224);
loc.a[2] = (f32)(((k >> 1) & 0x7f) * 200 + 176);
loc.a[3] = lbl_1_rodata_880C;
((s32 *)&loc)[12] = 10;
if ((*((u8 *)&lbl_1_bss_8CA28)) != 0) {
loc.a[4] = loc.a[4] * lbl_1_rodata_8638;
loc.a[5] = loc.a[5] * lbl_1_rodata_8638;
}
loc.a[4] = loc.a[4] * lbl_1_rodata_8C0C;
loc.a[5] = loc.a[5] * lbl_1_rodata_8C0C;
fn_1_8CED0(arg0->unk_24 + off, 0xa0, 0x8c);
*(f32 *)(arg0->unk_24 + off + 0x44) = lbl_1_rodata_87D0;
fn_1_8D3F8(arg0->unk_24 + off, &loc, fn_1_131B90, arg0);
off += 100;
}
}
}
/* fzgx:end fn_1_13A654 */

/* fzgx:begin fn_1_13A848 */
void fn_1_13A848(s16 arg0, s16 arg1, void* arg2, void* arg3, int arg4, f32 arg5, f32 arg6) {
    fn_1_49410();
    fn_1_494DC(8);
    fn_1_495B0(0x8001 << 16);
    fn_1_49738(&fn_1_5233C);
    fn_1_49748(lbl_1_rodata_861C);
    fn_1_4954C(lbl_1_rodata_87DC);
    fn_1_495C8(arg2);
    fn_1_4966C(lbl_1_rodata_863C, lbl_1_rodata_861C);
    fn_1_4955C(arg5, arg6);
    fn_1_49590(lbl_1_rodata_85F0);
    fn_1_496FC((f32)arg0, (f32)arg1);
    if (arg4 == 1) {
        fn_1_4A0D8( (const char*)(void*)(&lbl_1_data_41B1C));
    } else {
        fn_1_4A0D8( (const char*)((void*)((u32*)&lbl_1_data_212A8)[fn_1_12C930(arg3)]));
    }
}
/* fzgx:end fn_1_13A848 */

/* fzgx:begin fn_1_13A994 */
void fn_1_13A994(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5) {
    fn_1_13A9B8(arg0, arg1, arg2, arg3, arg4, arg5, -1);
}
/* fzgx:end fn_1_13A994 */

/* fzgx:begin fn_1_13A9B8 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern void fn_1_49410(void);
extern const f32 lbl_1_rodata_8C10;
extern void fn_1_49514(u32*);
extern void fn_1_5233C(void);
extern void fn_1_49738(void (*func)(void));
extern const f32 lbl_1_rodata_861C;
extern void fn_1_49748(f32);
extern const f32 lbl_1_rodata_87DC;
extern void fn_1_4954C(f32);
extern void fn_1_495C8(int);
extern void fn_1_4955C(f32, f32);
extern const f32 lbl_1_rodata_85F0;
extern void fn_1_49590(f32);
extern const f64 lbl_1_rodata_8600;
extern void fn_1_496FC(f32, f32);
extern u8 lbl_1_data_41B24[24];
extern void fn_1_4CF3C(void*, ...);
extern s16 fn_1_12C930(void*);
extern u8 lbl_1_data_21078[180];
extern void fn_1_4AE0C(void*, ...);

void fn_1_13A9B8(f32 arg7, f32 arg8, s16 arg0, s16 arg1, int arg2, void* arg3,
                 s16 arg4, int arg5, int arg6) {
    u32 local;

    if (arg4 == 0) return;
    fn_1_49410();
    local = *(u32*)&lbl_1_rodata_8C10;
    fn_1_49514(&local);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(lbl_1_rodata_861C);
    fn_1_4954C(lbl_1_rodata_87DC);
    fn_1_495C8(arg2);
    fn_1_4955C(arg7, arg8);
    fn_1_49590(lbl_1_rodata_85F0);
    fn_1_496FC((f32)arg0, (f32)arg1);

    if (arg6 != -1) {
        if (arg5 != 0) {
            fn_1_4CF3C(lbl_1_data_41B24, (f32)arg6);
        } else {
            fn_1_4CF3C(&lbl_1_data_41A30,
                       ((u32*)lbl_1_data_21078)[fn_1_12C930(arg3)], (f32)arg6);
        }
    } else if (arg5 != 0) {
        fn_1_4AE0C(lbl_1_data_41B24);
    } else {
        s16 index = fn_1_12C930(arg3);
        fn_1_4AE0C(&lbl_1_data_41A30, ((u32*)lbl_1_data_21078)[index]);
    }
}
/* fzgx:end fn_1_13A9B8 */

/* fzgx:begin fn_1_13B24C */
s32 fn_1_13B24C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, const char* arg4) {
    f32 temp;

    temp = (f32)arg3 / lbl_1_rodata_85FC;
    fn_1_4955C(temp, temp);
    if (arg0 != 0) {
        fn_1_496FC((f32)arg1, (f32)arg2);
        fn_1_4A0D8(arg4);
    }
    return (s32)fn_1_4B068(arg4);
}
/* fzgx:end fn_1_13B24C */

/* fzgx:begin fn_1_13B328 */
void fn_1_13B328(u32 arg0, s32 arg1) {
    FontDrawPacket packet;
    PtrTab tab;
    const char *temp_r29;
    s32 var_r28;
    s32 var_r27;
    s32 var_r26;
    s32 var_r25;
    u32 var_r24;
    u8 var_r23;

    var_r26 = 0;
    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = (arg1 != 0) ? 0x9E02 : 0x9A02;
    packet.x = lbl_1_rodata_861C;
    packet.y = lbl_1_rodata_8C44;
    packet.z = lbl_1_rodata_8C48;
    fn_1_4F734(&packet);

    if (lbl_1_bss_8B3A0.unk_129 != 0) {
        fn_1_49410();
        fn_1_49590(lbl_1_rodata_85F0);
        var_r27 = 0;
        do {
            var_r24 = arg0;
            var_r23 = __cntlzw(arg0);
            var_r25 = 0;
            var_r28 = 320 - var_r26 / 2;
            while (var_r24 != 0) {
                tab = lbl_1_rodata_8C4C;
                var_r25 += fn_1_13B548(var_r27, var_r25 + var_r28, 0x1AC, var_r23);
                if (var_r23 != 6) {
                    temp_r29 = tab.p[var_r23];
                    fn_1_4955C(lbl_1_rodata_8C70, lbl_1_rodata_8C70);
                    if (var_r27 != 0) {
                        fn_1_496FC((f32)(var_r25 + var_r28), lbl_1_rodata_8C74);
                        fn_1_4A0D8(temp_r29);
                    }
                    var_r25 += (s32)fn_1_4B068(temp_r29);
                    var_r25 += 0x18;
                }
                var_r24 &= ~(0x80000000U >> var_r23);
                var_r23 = __cntlzw(var_r24);
            }
            if (var_r27 == 0) {
                var_r26 = var_r25 - 0x18;
            }
            var_r27++;
        } while (var_r27 <= 1);
    }
}
/* fzgx:end fn_1_13B328 */

/* fzgx:begin fn_1_13B548 noprologue */
#include "types.h"
#include "font.h"

struct fn_1_13B548_Copy88 { u32 a[22]; };
struct fn_1_13B548_lbl_1_rodata_8C78 { u32 unk_0; };
struct fn_1_13B548_lbl_1_rodata_8C80 { u32 unk_0; };
struct fn_1_13B548_lbl_1_rodata_8C84 { u32 unk_0; };
struct fn_1_13B548_lbl_1_rodata_8B3C { f32 unk_0; };
struct fn_1_13B548_lbl_1_rodata_8C88 { u32 unk_0; };
struct fn_1_13B548_lbl_1_rodata_85F0 { f32 unk_0; };
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8C9C;
extern const f64 lbl_1_rodata_8CA0;
extern const f64 lbl_1_rodata_8CA8;
extern const f64 lbl_1_rodata_8600;
extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_1_13B548_lbl_1_rodata_85F0 lbl_1_rodata_85F0;
extern struct fn_1_13B548_lbl_1_rodata_8B3C lbl_1_rodata_8B3C;
extern struct fn_1_13B548_lbl_1_rodata_8C78 lbl_1_rodata_8C78;
extern struct fn_1_13B548_lbl_1_rodata_8C80 lbl_1_rodata_8C80;
extern struct fn_1_13B548_lbl_1_rodata_8C84 lbl_1_rodata_8C84;
extern struct fn_1_13B548_lbl_1_rodata_8C88 lbl_1_rodata_8C88;
extern u16 fn_1_48690(u32);
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_1_rodata_8C7C;
extern u32 lbl_1_rodata_8C8C;
extern u32 lbl_1_rodata_8C90;
extern u32 lbl_1_rodata_8C94;
extern u32 lbl_1_rodata_8C98;
extern u32 lbl_801A66A0;
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);

#pragma opt_common_subs off
s32 fn_1_13B548(u32 arg0, s32 arg1, s32 arg2, u32 arg3) {
    f32 initial_z;
    f32 v0;
    f64 v2;
    f32 v3;
    u32 v64;
    u32 v4;
    s32 unk_1;
    u32 v6;
    u32 v7;
    s32 v8;
    u32 v9;
    s32 v1;
    s32 v10;
    s32 v11;
    s32 v65 = 0;
    s32 v12;
    u32 v13;
    s32 v14;
    u32 v15;
    s32 v16;
    u32 v17;
    s32 v18;
    u32 v19;
    s32 v20;
    f64 v21;
    f32 v22;
    f32 v23;
    f64 v24;
    u32 v25;
    f32 v26;
    f64 v27;
    u32 v28;
    f32 v29;
    u32 v30;
    u32 v31;
    s32 v32;
    u32 v33;
    s32 v35;
    s32 v34;
    u32 v36;
    u32 v37;
    f64 v38;
    u32 v39;
    f32 v40;
    f64 v41;
    u32 v42;
    f32 v43;
    f64 v44;
    f32 v45;
    u32 v46;
    f64 v47;
    f32 v48;
    u32 v49;
    f64 v50;
    f32 v51;
    f32 v52;
    f64 v53;
    f32 v54;
    u32 v55;
    f32 v56;
    f32 overlay_z;
    f32 v57;
    f64 v58;
    f32 v59;
    u32 v60;
    f64 v61;
    f32 v62;
    u32 v63;
    FontDrawPacket loc_10;
    struct fn_1_13B548_lbl_1_rodata_8C78 loc_C;
    struct fn_1_13B548_lbl_1_rodata_8C78 loc_8;
    s16 t3;
    if ((s32)arg0 != 0) {
        loc_C = lbl_1_rodata_8C78;
        loc_8.unk_0 = lbl_1_rodata_8C7C;
        loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
        v1 = (u8)arg3;
        loc_10.x = (f32)(s32)arg1;
        loc_10.y = (f32)(s32)arg2;
        loc_10.z = lbl_1_rodata_8C9C;
        switch (v1) {
        case 0: case 1: case 2: case 3: case 4: case 6:
            loc_10.image = 0x9E09;
            fn_1_4F734(&loc_10);
            break;
        case 5: case 7: case 8:
            loc_10.image = 0x9E11;
            fn_1_4F734(&loc_10);
            break;
        }
        v64 = lbl_801A66A0;
        v4 = v64 % 60;
        unk_1 = v4 < 30;
        if (unk_1) {
            loc_C = *(struct fn_1_13B548_lbl_1_rodata_8C78 *)&lbl_1_rodata_8C80;
        }
        if (!unk_1) {
            loc_8 = *(struct fn_1_13B548_lbl_1_rodata_8C78 *)&lbl_1_rodata_8C84;
        }
        switch (v1) {
        case 0:
            v10 = 0;
            v11 = 0;
            v12 = 9;
            switch ((s32)(v64 % 240) / 60) {
            case 0:
                v13 = v4 / 3;
                v14 = 11;
                if (v13 < 11) v14 = v13;
                v10 = v14;
                break;
            case 1:
                v15 = v4 / 3;
                v16 = 11;
                if (v15 < 11) v16 = v15;
                v11 = v16;
                break;
            case 2:
                v17 = v4 / 3;
                v18 = 9;
                if (v17 < 9) v18 = v17;
                v12 = 9 - v18;
                break;
            case 3:
                v19 = v4 / 3;
                v20 = 9;
                if (v19 < 9) v20 = v19;
                v12 = v20 + 10;
                break;
            }
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E12;
            loc_10.x = lbl_1_rodata_8CA0 + (f64)(s32)arg1;
            loc_10.y = (f32)(s32)(arg2 - 2);
            loc_10.z = lbl_1_rodata_8A54;
            fn_1_4F734(&loc_10);
            t3 = fn_1_48690((u32)loc_10.image);
            fn_1_51678(&loc_10, (u32)loc_10.image, 0, (s16)v12, (s16)t3, 10);
            v0 = loc_10.y + (f32)v12;
            loc_10.z = lbl_1_rodata_8B3C.unk_0;
            *(u32 *)((u8 *)&loc_10 + 60) = lbl_1_rodata_8C88.unk_0;
            loc_10.y = v0;
            fn_1_4F734(&loc_10);
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E0B;
            loc_10.x = (f32)(s32)(arg1 - 8);
            loc_10.y = (f32)(s32)arg2;
            loc_10.z = lbl_1_rodata_8A54;
            fn_1_4F734(&loc_10);
            fn_1_51678(&loc_10, (u32)loc_10.image, 0, 0, 8, (s16)v10);
            overlay_z = lbl_1_rodata_8B3C.unk_0;
            *(u32 *)((u8 *)&loc_10 + 60) = lbl_1_rodata_8C8C;
            loc_10.z = overlay_z;
            fn_1_4F734(&loc_10);
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E0B;
            loc_10.x = (f32)(s32)(arg1 + 37);
            loc_10.y = (f32)(s32)arg2;
            loc_10.z = lbl_1_rodata_8A54;
            loc_10.flags = 0x80000;
            fn_1_4F734(&loc_10);
            fn_1_51678(&loc_10, (u32)loc_10.image, 0, 0, 8, (s16)v11);
            overlay_z = lbl_1_rodata_8B3C.unk_0;
            *(u32 *)((u8 *)&loc_10 + 60) = lbl_1_rodata_8C90;
            loc_10.z = overlay_z;
            fn_1_4F734(&loc_10);
            break;
        case 1: case 2:
            v10 = 0;
            v11 = v10;
            switch ((s32)(v64 % 120) / 60) {
            case 0:
                v10 = 11;
                v36 = v4 / 3;
                if (v36 < 11) v10 = v36;
                break;
            case 1:
                v11 = 11;
                v37 = v4 / 3;
                if (v37 < 11) v11 = v37;
                break;
            }
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E0B;
            loc_10.x = (f32)(s32)(arg1 - 8);
            loc_10.y = (f32)(s32)arg2;
            loc_10.z = lbl_1_rodata_8A54;
            fn_1_4F734(&loc_10);
            fn_1_51678(&loc_10, (u32)loc_10.image, 0, 0, 8, (s16)v10);
            overlay_z = lbl_1_rodata_8B3C.unk_0;
            *(u32 *)((u8 *)&loc_10 + 60) = lbl_1_rodata_8C94;
            loc_10.z = overlay_z;
            fn_1_4F734(&loc_10);
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E0B;
            loc_10.x = (f32)(s32)(arg1 + 37);
            loc_10.y = (f32)(s32)arg2;
            loc_10.z = lbl_1_rodata_8A54;
            loc_10.flags = 0x80000;
            fn_1_4F734(&loc_10);
            fn_1_51678(&loc_10, (u32)loc_10.image, 0, 0, 8, (s16)v11);
            overlay_z = lbl_1_rodata_8B3C.unk_0;
            *(u32 *)((u8 *)&loc_10 + 60) = lbl_1_rodata_8C98;
            loc_10.z = overlay_z;
            fn_1_4F734(&loc_10);
            break;
        case 3: case 4:
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E10;
            loc_10.x = (f32)(s32)(arg1 + 6);
            loc_10.y = (f32)(s32)(arg2 + 6);
            loc_10.z = lbl_1_rodata_8A54;
            *(u32 *)((u8 *)&loc_10 + 60) = loc_C.unk_0;
            fn_1_4F734(&loc_10);
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E10;
            loc_10.x = (f32)(s32)(arg1 + 24);
            loc_10.y = (f32)(s32)(arg2 + 6);
            loc_10.z = lbl_1_rodata_8A54;
            loc_10.flags = 0x80000;
            *(u32 *)((u8 *)&loc_10 + 60) = loc_8.unk_0;
            fn_1_4F734(&loc_10);
            break;
        case 6:
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.x = lbl_1_rodata_8CA8 + (f64)(s32)arg1;
            loc_10.y = (f32)(s32)(arg2 + 9);
            loc_10.image = 0x9E07;
            loc_10.z = lbl_1_rodata_8A54;
            *(u32 *)((u8 *)&loc_10 + 60) = loc_C.unk_0;
            fn_1_4F734(&loc_10);
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E07;
            loc_10.x = (f32)(s32)(arg1 + 27);
            loc_10.y = (f32)(s32)(arg2 + 9);
            loc_10.z = lbl_1_rodata_8A54;
            loc_10.scale_x *= lbl_1_rodata_85F0.unk_0;
            loc_10.scale_y *= lbl_1_rodata_85F0.unk_0;
            *(u32 *)((u8 *)&loc_10 + 60) = loc_C.unk_0;
            fn_1_4F734(&loc_10);
            break;
        case 5:
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E08;
            loc_10.x = (f32)(s32)(arg1 + 3);
            loc_10.y = (f32)(s32)(arg2 + 5);
            loc_10.z = lbl_1_rodata_8A54;
            *(u32 *)((u8 *)&loc_10 + 60) = loc_C.unk_0;
            fn_1_4F734(&loc_10);
            break;
        case 7: case 8:
            loc_10 = *(FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x9E06;
            loc_10.x = (f32)(s32)(arg1 + 14);
            loc_10.y = (f32)(s32)(arg2 + 1);
            loc_10.z = lbl_1_rodata_8A54;
            *(u32 *)((u8 *)&loc_10 + 60) = loc_C.unk_0;
            fn_1_4F734(&loc_10);
            break;
        }
    }
    switch ((s32)(arg3 & 0xFF)) {
    case 0: case 1: case 2: v65 = 43; break;
    case 3: case 4: v65 = 35; break;
    case 6: v65 = 39; break;
    case 5: case 7: case 8: v65 = 24; break;
    }
    return v65;
}
/* fzgx:end fn_1_13B548 */

/* fzgx:begin fn_1_13C134 */
void fn_1_13C134(void) {
    fn_1_5621C(lbl_1_rodata_861C, lbl_1_rodata_861C,
               lbl_1_rodata_861C, lbl_1_rodata_85EC);
}
/* fzgx:end fn_1_13C134 */

/* fzgx:begin fn_1_13C16C */
void fn_1_13C16C(void) {
    fn_1_5621C(lbl_1_rodata_863C, lbl_1_rodata_863C,
               lbl_1_rodata_863C, lbl_1_rodata_863C);
}
/* fzgx:end fn_1_13C16C */

/* fzgx:begin fn_1_13C1A0 */
struct Copy88 { u32 words[22]; };
struct Copy200 { u32 words[10][5]; };

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_strength_reduction off
void fn_1_13C1A0(u8 *arg0) {
    char buf[256];
    struct Copy88 loc_60;
    struct Copy88 loc_8;
    struct Copy200 loc_B8;
    u32 temp_r31;
    u8 tempbyte;
    u32 temp_r30;
    u32 temp_r28;
    u32 idx;
    f32 var_f31;
    u32 lab_t2;
    char * lab_t0;

    fn_1_133E04((void *)1, 0);
    fn_1_134AD4();
    if (*(s16 *)&lbl_1_bss_960 == 9) {
        loc_B8 = *(struct Copy200 *)lbl_1_rodata_8CB0;
        tempbyte = lbl_1_bss_9C;
        loc_60 = *(struct Copy88 *)(((u32 *)&lbl_1_rodata_26F8));
        (*((0) + (loc_60.words))) = 0xBA16;
        *(f32 *)((u8 *)&loc_60 + 4) = lbl_1_rodata_882C;
        *(f32 *)((u8 *)&loc_60 + 8) = lbl_1_rodata_8830;
        *(f32 *)((u8 *)&loc_60 + 12) = lbl_1_rodata_8834;
        *(u32 *)((u8 *)&loc_60 + 0x30) = 0xA;
        fn_1_4F734((FontDrawPacket *)&loc_60);
        fn_1_13ABA8(0x28000000);
        fn_1_140EE8(arg0[0], 0, 1);
        if ((s8)tempbyte == 2 || (u8)(tempbyte - 4) <= 1 || (s8)tempbyte == 6) {
            var_f31 = lbl_1_rodata_8BEC;
        } else {
            var_f31 = lbl_1_rodata_8D78;
        }
        temp_r31 = (u32)(((f32)fn_1_A5DB0() - lbl_1_rodata_8B58) - lbl_1_rodata_8B84);
        temp_r28 = (u32)(lbl_1_rodata_863C * (f32)fn_1_A5D88());
        temp_r30 = (u32)lbl_1_rodata_8B58;
        lab_t2 = (u32)(lbl_1_rodata_861C * (f32)fn_1_A5D88());
        fn_1_7B558(1, 1, lab_t2, temp_r30, temp_r28, temp_r31, var_f31);
        sprintf(buf, (const char *)&lbl_1_data_41DE4, loc_B8.words[(s8)tempbyte][lbl_801A66B4]);
        fn_1_138144( (void*)((u32)buf), lbl_1_bss_8B3A0.unk_94 & 0x40000000);
        return;
    }
    loc_8 = *(struct Copy88 *)(((u32 *)&lbl_1_rodata_26F8));
    (*((0) + (loc_8.words))) = 0x9A12;
    *(f32 *)((u8 *)&loc_8 + 4) = lbl_1_rodata_882C;
    *(f32 *)((u8 *)&loc_8 + 8) = lbl_1_rodata_8830;
    *(f32 *)((u8 *)&loc_8 + 12) = lbl_1_rodata_8834;
    *(u32 *)((u8 *)&loc_8 + 0x30) = 0xA;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    fn_1_13ABA8(0x08000000);
    fn_1_13C5EC(arg0[0]);
    temp_r31 = (u32)(lbl_1_rodata_8A4C * (f32)fn_1_A5DB0());
    temp_r30 = (u32)(lbl_1_rodata_8A4C * (f32)fn_1_A5D88());
    lab_t2 = (u32)(lbl_1_rodata_87AC * (f32)fn_1_A5D88());
    fn_1_7B558(1, 1, lab_t2, 0, temp_r30, temp_r31, lbl_1_rodata_8D7C);
    idx = lbl_801A66B4;
    sprintf(buf, (const char *)fn_1_13F7F8(0x13, (s16)idx),
            *(u32 *)(lbl_1_data_2BD54 + arg0[0] * 0x18 + idx * 4));
    fn_1_138144( (void*)((u32)buf), lbl_1_bss_8B3A0.unk_94 & 0x40000000);
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset

#pragma opt_propagation reset
/* fzgx:end fn_1_13C1A0 */

/* fzgx:begin fn_1_13D02C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern Word8 lbl_1_rodata_86D8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern f32 lbl_1_rodata_26F8[22];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern u16 fn_1_486C4(u32 value);
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_88B4;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_88B8;
extern const u32 lbl_1_rodata_8860[6];
extern const u32 lbl_1_rodata_8878[6];
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_48690(u32 unused);
extern void fn_1_52070(u32 value);
extern void fn_1_135D7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_4965C(u8 value);
extern void fn_1_495C8(void* arg0);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 value);
extern void fn_1_49590(f32 value);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A28;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern s32 lbl_1_rodata_8A34;
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_5233C(void* arg0, void* arg1);
extern u32 fn_1_12F118(void);
extern u8* fn_1_36AD0();
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_137364();
extern void fn_1_14E9E4(int arg0, void *arg1);
extern const f32 lbl_1_rodata_8840;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_85F4;
extern int fn_1_D6698(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern void fn_1_139440(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
extern s32 lbl_1_bss_8E3D0[];
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_8BA8;
extern const f32 lbl_1_rodata_8664;
extern const f32 lbl_1_rodata_8BAC;
extern const f32 lbl_1_rodata_8BB0;
extern const f32 lbl_1_rodata_8BB4;
extern const f32 lbl_1_rodata_87D0;
extern int fn_1_D6740();
extern int fn_1_D66B0(void);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern u8 lbl_1_rodata_8558[84];
extern const f32 lbl_1_rodata_8C10;
extern void fn_1_4CF3C(const char *format, f32 x, ...);
extern s16 fn_1_12C930(void* arg0);
extern u8 lbl_1_data_21078[180];
extern f32 fn_1_4B068(const char*);
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8C74;
extern PtrTab lbl_1_rodata_8C4C;
extern s32 fn_1_13B548(s32, s32, s32, u8);
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8D78;
extern const f32 lbl_1_rodata_8D7C;
extern u16 lbl_1_rodata_8CB0[200];
extern u8 lbl_1_bss_9C;
extern void fn_1_133E04(void* arg0, s32 arg1);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_140EE8(u8 arg0, int arg1, int arg2);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern void fn_1_138144(void* arg0, int arg1);
extern u32 fn_1_13C5EC(u8);
extern u32 fn_1_13F7F8(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8DBC;
extern const f32 lbl_1_rodata_8DCC;
extern const f32 lbl_1_rodata_87B4;
extern const u32 lbl_1_rodata_8DC0;
extern const f32 lbl_1_rodata_8818;
extern const u32 lbl_1_rodata_8DC4;
extern const f32 lbl_1_rodata_8DD0;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8A58;
extern int fn_1_B7E98(int index);
extern void fn_1_13EE60();
extern u32 fn_1_13EF64(u32, u32, u32, void *, u32, void *, u32, f32);
extern u32 lbl_1_rodata_8E8C;
extern u8 lbl_1_rodata_8EB4[];
extern char *fn_80083DB0(char *dst, const char *src);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 lbl_1_rodata_91C0[11];
extern const f32 lbl_1_rodata_91EC;
extern const f32 lbl_1_rodata_91F0;
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern void fn_1_494DC(s16 index);
extern const f32 lbl_1_rodata_9208;
extern void fn_1_4966C(f32 value1, f32 value2);
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern const f32 lbl_1_rodata_8E9C;
extern const f64 lbl_1_rodata_93E8;
extern f32 lbl_1_rodata_93F0[15];
extern f32 lbl_1_rodata_92C0[22];
extern f32 lbl_1_rodata_970C[71];
extern const f32 lbl_1_rodata_946C;
extern void fn_1_149C2C();
extern struct fn_1_149C64_lbl_1_bss_8E43C lbl_1_bss_8E43C;
extern struct fn_1_149C64_lbl_1_bss_8E440 lbl_1_bss_8E440;
extern void fn_1_149CA4(u32, u32, u32, u32);
extern void fn_1_520A0(void);
extern f64 lbl_1_rodata_9480[80];
extern f32 lbl_1_rodata_942C[16];
extern f32 fn_1_521B8(s32 value);
extern f32 fn_1_520F8(s32 value);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_1_520CC(void);
extern const f32 lbl_1_rodata_99A4;
extern u8 fn_1_5910(void);
extern u8 fn_1_149FB4(s32 index);
extern s32 fn_1_3F864(void);
extern void fn_1_A52B0(s32 index);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 fn_1_1556B4(u32, u32);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0();
extern s16 fn_1_14F344(s16);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void fn_1_151C3C(u16 value1, u16 value2);
extern void fn_1_556B8(void *value);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern const f64 lbl_1_rodata_B8D0;
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *fn_800839D8(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_1375C0(int arg0, void* arg1, void* arg2, void* arg3, void* arg4);
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern void fn_1_131B90(void);
extern void fn_1_13A9B8();
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void fn_1_13E080(void* arg0, void* arg1, void* arg2, int arg3);
extern void fn_1_144F40(u32 arg0, u32 arg1);
extern u8 fn_1_155F8C(void);
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, u32 arg3);
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);
extern s32 fn_1_45D0();
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 fn_80008BEC(u32 arg0, int arg1, int arg2);
extern void fn_1_7F3AC(void* object);


extern u32 lbl_1_rodata_8DA0;
extern u32 lbl_1_rodata_8DA4;
extern u32 lbl_1_rodata_8DA8;
extern u16 lbl_1_bss_962;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_8B2C;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87B4;
extern const f32 lbl_1_rodata_8808;
extern const f32 lbl_1_rodata_8838;
extern const f32 lbl_1_rodata_8A2C;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8C9C;
extern const f32 lbl_1_rodata_8D94;
extern const f32 lbl_1_rodata_8DAC;
extern const f32 lbl_1_rodata_8DB0;
extern const f32 lbl_1_rodata_8DB4;
extern const f32 lbl_1_rodata_8DB8;
extern f32 lbl_8006D188(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_12F258(void);
extern u32 fn_1_539CC(void *, void *, f32);
extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_495A0(f32);
extern void fn_1_495C8(void *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);

#pragma opt_propagation off
void fn_1_13D02C(void) {
    s32 v0;
    u32 v1;
    u32 v2;
    f32 v12;
    u32 v13;
    u32 v14;
    s32 v20;
    u32 v21;
    f32 v22;
    u32 v23;
    FontDrawPacket loc_38;
    struct { u32 a[5]; } loc_24;
    u32 loc_20;
    u32 loc_1C;
    u32 loc_18;
    u32 loc_14;
    u32 loc_10;
    u32 loc_C;
    u32 loc_8;
    s32 t0;
    s32 t1;
    s32 t2;
    f32 t3;
    u32 t4;
    u32 t5;
    t0 = fn_1_12F258();
    if ((u32)(t0 + 0x10000) != 65535) {
        t1 = fn_1_12F258();
        v0 = (u32)t1 / 60 + 1;
    } else {
        v0 = 0;
    }
    v1 = lbl_1_rodata_8DA0;
    v2 = lbl_1_rodata_8DA4;
    loc_24.a[3] = v1;
    loc_24.a[2] = v2;
    loc_24.a[1] = lbl_1_rodata_8DA8;
    t2 = fn_1_12F258();
    v12 = (f32)(t2 % 60 % 120);
    t3 = lbl_8006D188((s32)(lbl_1_rodata_8B2C * v12 / lbl_1_rodata_8838));
    v12 = t3;
    v20 = 0;
    if ((lbl_1_bss_8B3A0.unk_94 & 0x40000000) != 0) {
        if (v0 > 99) {
            v13 = 9;
            v14 = 9;
        } else {
            v13 = (v0 / 10) & 0xFF;
            v14 = (v0 % 10) & 0xFF;
        }
        switch (*(s16 *)&lbl_1_bss_962) {
        case 16: case 24:
            if (v0 < 10) v20 = 1;
            break;
        case 15: case 18: case 19: case 23:
            if (v0 < 6) v20 = 1;
            break;
        case 14:
            if (v0 < 4) v20 = 1;
            break;
        }
        if (v20 != 0) {
            v12 = (f32)(lbl_1_rodata_863C - t3);
            loc_20 = loc_24.a[2];
            loc_24.a[0] = loc_24.a[1];
            t4 = fn_1_539CC((void *)&loc_24, (void *)&loc_20, v12);
            loc_24.a[4] = t4;
        } else {
            v12 = (f32)(lbl_1_rodata_863C - t3);
            loc_18 = loc_24.a[2];
            loc_1C = loc_24.a[3];
            t5 = fn_1_539CC((void *)&loc_1C, (void *)&loc_18, v12);
            loc_24.a[4] = t5;
        }
        loc_38 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
        loc_38.image = (0x10000 - 25064);
        loc_38.x = lbl_1_rodata_8DAC;
        loc_38.y = lbl_1_rodata_8B84;
        loc_38.z = lbl_1_rodata_8DB0;
        fn_1_4F734((FontDrawPacket *)&loc_38);
        fn_1_49410();
        v12 = lbl_1_rodata_8DB4;
        fn_1_496FC(v12, lbl_1_rodata_8D94);
        fn_1_495C8((void *)9);
        fn_1_494DC(37);
        loc_14 = loc_24.a[4];
        fn_1_49514((u32 *)&loc_14);
        v12 = lbl_1_rodata_8C9C;
        fn_1_4954C(v12);
        v21 = (v13 & 0xFF);
        fn_1_4AE0C((const char *)&lbl_1_data_41DEC, v21);
        fn_1_494DC(38);
        v12 = lbl_1_rodata_8DB4;
        fn_1_496FC(v12, lbl_1_rodata_8D94);
        loc_10 = loc_24.a[3];
        fn_1_49514((u32 *)&loc_10);
        v12 = lbl_1_rodata_8A2C;
        fn_1_4954C(v12);
        v12 = lbl_1_rodata_87B4;
        v22 = (f32)(v12 + (f32)(lbl_1_rodata_8808 * t3));
        v12 = v22;
        fn_1_495A0(v12);
        fn_1_4AE0C((const char *)&lbl_1_data_41DEC, v21);
        fn_1_49410();
        v12 = lbl_1_rodata_8DB8;
        fn_1_496FC(v12, lbl_1_rodata_8D94);
        fn_1_495C8((void *)9);
        fn_1_494DC(37);
        loc_C = loc_24.a[4];
        fn_1_49514((u32 *)&loc_C);
        v12 = lbl_1_rodata_8C9C;
        fn_1_4954C(v12);
        v23 = (v14 & 0xFF);
        fn_1_4AE0C((const char *)&lbl_1_data_41DEC, v23);
        fn_1_494DC(38);
        v12 = lbl_1_rodata_8DB8;
        fn_1_496FC(v12, lbl_1_rodata_8D94);
        loc_8 = loc_24.a[3];
        fn_1_49514((u32 *)&loc_8);
        v12 = lbl_1_rodata_8A2C;
        fn_1_4954C(v12);
        v12 = v22;
        fn_1_495A0(v12);
        fn_1_4AE0C((const char *)&lbl_1_data_41DEC, v23);
    }
}
/* fzgx:end fn_1_13D02C */

/* fzgx:begin fn_1_13D460 */
static inline s32 fn_1_13D460_strip_position(s32 x, s32 y) { return x + y; }
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_1_13D460(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    FontDrawPacket setup;
    FontDrawPacket packet;
    s32 total;
    s32 i;
    s32 count;
    s16 lab_t5;
    s16 lab_t2;

    setup = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    setup.image = arg3 ? (0x10000 - 0x61FF) : (0x10000 - 0x68F8);
    setup.y = (f32)arg1;
    setup.z = lbl_1_rodata_8B30;

    count = arg2 - 0x18;
    packet = setup;
    packet.x = (f32)arg0;
    lab_t5 = 4;
    lab_t2 = 0;
    fn_1_51678(&packet, setup.image, lab_t2, 0, 0xC, lab_t5);
    fn_1_4F734(&packet);

    packet = setup;
    total = arg0 + arg2;
    packet.x = (f32)total;
    lab_t5 = 4;
    lab_t2 = 0;
    fn_1_51678(&packet, setup.image, lab_t2, 0, 0xC, lab_t5);
    *(u32 *)((u8 *)&packet + 0x30) = 0x80007;
    fn_1_4F734(&packet);

    i = 0;

    while (i < count / (s32)fn_1_48690(setup.image)) {
        packet = setup;
        packet.x = (f32)(fn_1_13D460_strip_position(arg0, i * fn_1_48690(setup.image)) + 0xC);
        lab_t5 = 4;
        lab_t2 = 0;
        fn_1_51678(&packet, setup.image, lab_t2, 4, 0x10, lab_t5);
        fn_1_4F734(&packet);
        i++;
    }

    packet = setup;
    packet.x = (f32)(fn_1_13D460_strip_position(arg0, i * fn_1_48690(setup.image)) + 0xC);
    lab_t5 = 4;
    lab_t2 = 0;
    fn_1_51678(&packet, setup.image, lab_t2, 4, (s16)((f32)(total - 0xC) - packet.x), lab_t5);
    fn_1_4F734(&packet);

    packet = setup;
    packet.x = (f32)(arg0 + 0xC);
    packet.z = packet.z - lbl_1_rodata_87AC;
    lab_t5 = 4;
    lab_t2 = 0xC;
    fn_1_51678(&packet, setup.image, lab_t2, 0, 4, lab_t5);
    fn_1_4F734(&packet);
    packet.x = packet.x + lbl_1_rodata_8A54;
    fn_1_4F734(&packet);
    packet.x = packet.x + lbl_1_rodata_8DBC;
    fn_1_4F734(&packet);
    packet.x = packet.x + lbl_1_rodata_8A54;
    fn_1_4F734(&packet);

    packet = setup;
    packet.x = (f32)(total - 0x34);
    packet.z = packet.z - lbl_1_rodata_87AC;
    lab_t5 = 4;
    lab_t2 = 0xC;
    fn_1_51678(&packet, setup.image, lab_t2, 0, 4, lab_t5);
    fn_1_4F734(&packet);
    packet.x = packet.x + lbl_1_rodata_8A54;
    fn_1_4F734(&packet);
    packet.x = packet.x + lbl_1_rodata_8DBC;
    fn_1_4F734(&packet);
    packet.x = packet.x + lbl_1_rodata_8A54;
    fn_1_4F734(&packet);

    if (arg2 > 0x15E) {
        packet = setup;
        packet.x = (f32)(arg0 + 0x100);
        packet.z = packet.z - lbl_1_rodata_87AC;
        lab_t5 = 4;
        lab_t2 = 0xC;
        fn_1_51678(&packet, setup.image, lab_t2, 0, 4, lab_t5);
        fn_1_4F734(&packet);
        packet.x = packet.x + lbl_1_rodata_8A54;
        fn_1_4F734(&packet);
        packet.x = packet.x + lbl_1_rodata_8DBC;
        fn_1_4F734(&packet);
        packet.x = packet.x + lbl_1_rodata_8A54;
        fn_1_4F734(&packet);
    }
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset
/* fzgx:end fn_1_13D460 */

/* fzgx:begin fn_1_13DA0C */
// Register the three groups of static display configurations.
void fn_1_13DA0C(void) {
    struct Struct_26F8 config;

    config = (*((const struct Struct_26F8 *)&lbl_1_rodata_26F8));
    config.unk00 = 0x9E1C;
    config.unk04 = lbl_1_rodata_8658;
    config.unk08 = lbl_1_rodata_8DCC;
    config.unk0C = lbl_1_rodata_8840;
    config.unk2C = lbl_1_rodata_87B4;
    config.unk38 = lbl_1_rodata_8DC0;
    config.unk30 = 0xF;
    fn_1_4F734( (FontDrawPacket*)(void*)(&config));

    config.unk30 = 0x8000D;
    fn_1_4F734( (FontDrawPacket*)(void*)(&config));

    config.unk30 = 0x100007;
    fn_1_4F734( (FontDrawPacket*)(void*)(&config));

    config.unk30 = 0x180005;
    fn_1_4F734( (FontDrawPacket*)(void*)(&config));

    config = (*((const struct Struct_26F8 *)&lbl_1_rodata_26F8));
    config.unk00 = 0x9E1D;
    config.unk04 = lbl_1_rodata_8818;
    config.unk08 = lbl_1_rodata_8DCC;
    config.unk0C = lbl_1_rodata_86F8;
    config.unk38 = lbl_1_rodata_8DC4;
    config.unk2C = lbl_1_rodata_87B4;
    config.unk30 = 0xD;
    fn_1_4F734( (FontDrawPacket*)(void*)(&config));

    config.unk30 = 0x100005;
    fn_1_4F734( (FontDrawPacket*)(void*)(&config));

    config = (*((const struct Struct_26F8 *)&lbl_1_rodata_26F8));
    config.unk00 = 0x9E1E;
    config.unk04 = lbl_1_rodata_8DD0;
    config.unk08 = lbl_1_rodata_8DCC;
    config.unk0C = lbl_1_rodata_86F8;
    config.unk38 = lbl_1_rodata_8DC8;
    config.unk2C = lbl_1_rodata_87B4;
    config.unk30 = 0xF;
    fn_1_4F734( (FontDrawPacket*)(void*)(&config));

    config.unk30 = 0x100007;
    fn_1_4F734( (FontDrawPacket*)(void*)(&config));
}
/* fzgx:end fn_1_13DA0C */

/* fzgx:begin fn_1_13DC54 */
typedef struct {
    u32 words[22];
} FnData;



void fn_1_13DC54(void) {
    FnData data;
    u32 value;

    data = *(FnData *)lbl_1_rodata_26F8;
    *(u32 *)((u8 *)&data + 0) = 0x9E0A;
    *(f32 *)((u8 *)&data + 4) = lbl_1_rodata_8DDC;
    *(f32 *)((u8 *)&data + 8) = lbl_1_rodata_8DE0;
    *(f32 *)((u8 *)&data + 12) = lbl_1_rodata_8B30;
    *(u32 *)((u8 *)&data + 48) = 10;
    fn_1_4F734( (FontDrawPacket*)(void *)(&data));

    data = *(FnData *)lbl_1_rodata_26F8;
    *(f32 *)((u8 *)&data + 4) = lbl_1_rodata_8DE4;
    *(f32 *)((u8 *)&data + 8) = lbl_1_rodata_8DE0;
    *(f32 *)((u8 *)&data + 12) = lbl_1_rodata_8B30;
    if (fn_1_B7E98(1) == 0) {
        value = *(u32 *)&lbl_1_rodata_8DD4;
        *(u32 *)((u8 *)&data + 56) = value;
    }

    *(u32 *)((u8 *)&data + 0) = 0x9E0C;
    *(u32 *)((u8 *)&data + 48) = 10;
    fn_1_4F734( (FontDrawPacket*)(void *)(&data));
    if (fn_1_B7E98(1) != 0) {
        f32 z;
        z = *(f32 *)((u8 *)&data + 12);
        *(u32 *)((u8 *)&data + 0) = 0x9E26;
        *(u32 *)((u8 *)&data + 56) = *(u32 *)&lbl_1_rodata_8DD8;
        *(f32 *)((u8 *)&data + 44) = lbl_1_rodata_8A58;
        *(f32 *)((u8 *)&data + 12) = z + lbl_1_rodata_8B34;
        fn_1_4F734( (FontDrawPacket*)(void *)(&data));
    }
}
/* fzgx:end fn_1_13DC54 */

/* fzgx:begin fn_1_13DDB8 */
typedef struct {
	u32 image;
	f32 x;
	f32 y;
	f32 z;
	u8 pad0[0x1C];
	f32 field_2C;
	u32 flags;
	u8 pad1[4];
	u32 unk_38;
	u8 color_add[3];
	u8 pad2[0x19];
} Packet;

extern f32 lbl_1_rodata_26F8[22];
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_8B2C;
extern const f32 lbl_1_rodata_8838;
extern const f32 lbl_1_rodata_8DF0;
extern const f32 lbl_1_rodata_8684;
extern const f32 lbl_1_rodata_86D0;
extern u32 lbl_1_rodata_8DE8;
extern const f32 lbl_1_rodata_87B4;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_880C;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_8DF4;
extern u32 lbl_1_rodata_8DEC;
extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern int fn_1_B7E98(int);

static inline f32 fn_1_13DDB8_operand(f32 left, f32 right) { return left * right; }
#pragma opt_propagation off
void fn_1_13DDB8(void) {
	f32 f;
	Packet p;
	f32 s;
	f32 t;
	f32 f_2;
	f32 s_2;

	p = *(Packet *)lbl_1_rodata_26F8;
	p.image = 0x10000 - 25055;
	p.x = lbl_1_rodata_8DF0;
	p.y = lbl_1_rodata_8684;
	p.z = lbl_1_rodata_86D0;
	p.field_2C = lbl_1_rodata_87B4;
	p.flags = 10;
	p.unk_38 = lbl_1_rodata_8DE8;
	f = lbl_8006D188((s32)(lbl_1_rodata_8B2C * (lbl_801A66A0 % 120) / lbl_1_rodata_8838));
	s = lbl_1_rodata_863C + f;
	t = lbl_1_rodata_880C * s;
	p.color_add[0] = p.color_add[1] = p.color_add[2] = (u8)(s32)(fn_1_13DDB8_operand((t), (lbl_1_rodata_85F0)));
	p.field_2C = lbl_1_rodata_87B4;
	fn_1_4F734((FontDrawPacket *)&p);

	if (fn_1_B7E98(1)) {
		p = *(Packet *)lbl_1_rodata_26F8;
		p.image = 0x10000 - 25055;
		p.x = lbl_1_rodata_8DF4;
		p.y = lbl_1_rodata_8684;
		p.z = lbl_1_rodata_86D0;
		p.flags = 0x8000A;
		p.unk_38 = lbl_1_rodata_8DEC;
		f_2 = lbl_8006D188((s32)(lbl_1_rodata_8B2C * (lbl_801A66A0 % 120) / lbl_1_rodata_8838));
		s_2 = lbl_1_rodata_863C + f_2;
		t = lbl_1_rodata_86D0 * s_2;
		p.color_add[0] = p.color_add[1] = p.color_add[2] = (u8)(s32)(fn_1_13DDB8_operand((t), (lbl_1_rodata_85F0)));
		p.field_2C = lbl_1_rodata_87B4;
		fn_1_4F734((FontDrawPacket *)&p);
	}
}
#pragma opt_propagation reset
/* fzgx:end fn_1_13DDB8 */

/* fzgx:begin fn_1_13E054 */
void fn_1_13E054(void* arg0, void* arg1, void* arg2, int arg3) {
    u8* fixed = (u8*)0;
    fixed += 0xA204;
    fn_1_13E080(arg0, arg1, fixed, 31);
}
/* fzgx:end fn_1_13E054 */

/* fzgx:begin fn_1_13EA9C noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/globals.h"

typedef struct {
    char s[17]; } fn_1_13EA9C_Str17;
typedef struct { char s[29]; } fn_1_13EA9C_Str29;
typedef struct { FontDrawPacket p; } fn_1_13EA9C_Pkt;

extern const fn_1_13EA9C_Str17 lbl_1_rodata_8E38;
extern const fn_1_13EA9C_Str29 lbl_1_rodata_8E4C;
extern f32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_8648;
extern const f32 lbl_1_rodata_8670;
extern const f32 lbl_1_rodata_86C4;
extern const f32 lbl_1_rodata_87D0;
extern const f32 lbl_1_rodata_8820;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8E04;
extern const f32 lbl_1_rodata_8E6C;
extern const f32 lbl_1_rodata_8E70;
extern const f32 lbl_1_rodata_8E74;
extern const f32 lbl_1_rodata_8E78;
extern const f32 lbl_1_rodata_8E7C;
extern const f32 lbl_1_rodata_8E80;
extern const f32 lbl_1_rodata_8E84;
extern const f32 lbl_1_rodata_8E88;

extern int fn_1_8623C(void);
extern void fn_1_50164(f32, f32, f32, f32, FontDrawPacket *);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern u32 fn_1_53FE4(FontDrawPacket *, u32);
extern void fn_1_49410(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4965C(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4CE48(char *, f32);

#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_13EA9C(void) {
    fn_1_13EA9C_Str17 name = lbl_1_rodata_8E38;
    fn_1_13EA9C_Str29 text = lbl_1_rodata_8E4C;
    FontDrawPacket packet;
    int n;
    char *namep = name.s;
    char *textp = text.s;

    n = fn_1_8623C();

    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 12;
    packet.flags = 5;
    packet.x = lbl_1_rodata_8E6C;
    packet.y = lbl_1_rodata_8648;
    packet.z = lbl_1_rodata_8E04;
    fn_1_50164(lbl_1_rodata_8670, lbl_1_rodata_87D0, lbl_1_rodata_86C4, lbl_1_rodata_86C4, &packet);

    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x9E14;
    fn_1_51564(0, 0, 24, 20, 2, 2);
    fn_1_5158C(&packet, packet.image, n % 2, n / 2);
    packet.x = lbl_1_rodata_8E70;
    packet.y = lbl_1_rodata_8E74;
    packet.z = lbl_1_rodata_8E78;
    packet.scale_x *= lbl_1_rodata_85EC;
    packet.scale_y *= lbl_1_rodata_85EC;
    packet.flags = 9;
    fn_1_4F734(&packet);

    fn_1_49410();
    fn_1_496FC(lbl_1_rodata_8820, lbl_1_rodata_8E74);
    fn_1_495C8(8);
    fn_1_4955C(lbl_1_rodata_8C70, lbl_1_rodata_8C70);
    fn_1_4965C(2);
    fn_1_495B0(0x40000000);
    fn_1_49590(lbl_1_rodata_85F0);
    fn_1_4CE48(namep, lbl_1_rodata_8E7C);

    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.x = lbl_1_rodata_8E80;
    packet.y = lbl_1_rodata_8E74;
    packet.z = lbl_1_rodata_8E78;
    packet.flags = 10;
    packet.image = 0x9500;
    fn_1_53FE4(&packet, 0);

    fn_1_49410();
    fn_1_496FC(lbl_1_rodata_8E84, lbl_1_rodata_8E74);
    fn_1_495C8(8);
    fn_1_4955C(lbl_1_rodata_8C70, lbl_1_rodata_8C70);
    fn_1_4965C(2);
    fn_1_495B0(0x40000000);
    fn_1_49590(lbl_1_rodata_85F0);
    fn_1_4CE48(textp, lbl_1_rodata_8E88);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_13EA9C */

/* fzgx:begin fn_1_13EDDC */
// Build the selected display data unless the caller requested the cached path.
void fn_1_13EDDC(u32 arg0, u32 arg1, u32 arg2, u32 arg3, s32 arg4) {
    u32 display_data[47];
    u32 nan_value;

    if (arg4 != 1) {
        fn_1_13EE60(arg2, arg3, display_data, arg3, arg4);
        nan_value = lbl_1_rodata_8E8C;
        fn_1_13EF64(arg0, arg1, 2, display_data, 0x9e20, &nan_value, 0, lbl_1_rodata_85F0);
    }
}
/* fzgx:end fn_1_13EDDC */

/* fzgx:begin fn_1_13F72C */
typedef struct {
    s16 first;
    u16 pad;
    u32 vals[6];
} fn_1_13F72C_Entry;

typedef struct {
    fn_1_13F72C_Entry e[5];
} EntryTable;


u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0) {
    EntryTable tbl;
    fn_1_13F72C_Entry* p;
    s16 i;

    tbl = *(const EntryTable*)lbl_1_rodata_8EB4;
    p = tbl.e;
    i = 0;
    while (1) {
        if (farg0 >= (f32)p->first) {
            fn_80083DB0( (char *)(u32)(arg1), (const char *)(u32)(tbl.e[i].vals[arg0]));
            return arg1;
        }
        p++;
        i++;
    }
}
/* fzgx:end fn_1_13F72C */

/* fzgx:begin fn_1_13F81C */
// Clear the cached display-resource handles before loading a new selection.
void fn_1_13F81C(void) {
    u32 *handles = (u32 *)(((u8 *)&lbl_1_bss_8E3E4));

    handles[0] = 0;
    handles[1] = 0;
    handles[2] = 0;
    handles[3] = 0;
    handles[4] = 0;
    handles[5] = 0;
    handles[6] = 0;
    handles[7] = 0;
}
/* fzgx:end fn_1_13F81C */

/* fzgx:begin fn_1_13F848 */
// Load the selected display resource, store its handle, and activate it.
void fn_1_13F848(u32 arg0) {
    u32 selected_slot = arg0 & 0xFF;
    u32* handles = (u32*)lbl_1_bss_8E3E4;

    handles[selected_slot] =
        fn_1_45D0(lbl_801A6410, 0x10440, lbl_1_data_419E0, 0x14F9);
    fn_1_FC414( (void *)(u32)(handles[selected_slot]), (void *)(int)(1));
}
/* fzgx:end fn_1_13F848 */

/* fzgx:begin fn_1_13F8B0 */
// Resolve a cached display handle from the key's low-byte slot.
u32 fn_1_13F8B0(u32 key) {
    u32 slot = key & 0xFF;

    return ((u32 *)lbl_1_bss_8E3E4)[slot];
}
/* fzgx:end fn_1_13F8B0 */

/* fzgx:begin fn_1_13F8C4 */
void fn_1_13F8C4(s32 arg_sp0) {
    s32 temp_r27;
    u8 var_r26;
    void *temp_r4;

    var_r26 = 0;
    while (var_r26 < 8U) {
        temp_r27 = (var_r26 * 4) & 0x3FC;
        temp_r4 = (void *)(*(void **)((u8 *)(&(((u8 *)&lbl_1_bss_8E3E4))[temp_r27]) + 0));
        if (temp_r4 != NULL) {
            fn_1_46B4((*((struct fn_1_13F8C4_lbl_801A6410 *)&lbl_801A6410)).unk_0, (u32)((void *)(temp_r4)), (const char *)((s8 *) (((u8 *)&lbl_1_data_419E0))), 0x150B);
        }
        (*(s32 *)((u8 *)(&(((u8 *)&lbl_1_bss_8E3E4))[temp_r27]) + 0)) = 0;
        var_r26 += 1;
            }
}
/* fzgx:end fn_1_13F8C4 */

/* fzgx:begin fn_1_13F948 */
// Clear the cached static-display handles before rebuilding the resource set.
void fn_1_13F948(void) {
    ((u32 *)lbl_1_bss_8E404)[0] = 0;
    ((u32 *)lbl_1_bss_8E404)[1] = 0;
    ((u32 *)lbl_1_bss_8E404)[2] = 0;
    ((u32 *)lbl_1_bss_8E404)[3] = 0;
    ((u32 *)lbl_1_bss_8E404)[4] = 0;
    ((u32 *)lbl_1_bss_8E404)[5] = 0;
    ((u32 *)lbl_1_bss_8E404)[6] = 0;
    ((u32 *)lbl_1_bss_8E404)[7] = 0;
}
/* fzgx:end fn_1_13F948 */

/* fzgx:begin fn_1_13F974 */
// Allocate and initialize the static-display resource for a byte-sized slot.
u32 fn_1_13F974(u32 slot_arg) {
    u32 slot = slot_arg & 0xFF;
    u32* resource_slots = (u32*)lbl_1_bss_8E404;

    resource_slots[slot] =
        fn_1_45D0(lbl_801A6410, 0x440, lbl_1_data_419E0, 0x1528);
    return fn_80008BEC(resource_slots[slot], 0, 0x440);
}
/* fzgx:end fn_1_13F974 */

/* fzgx:begin fn_1_13F9DC */
// Look up the static-display object stored in the caller-selected byte slot.
u32 fn_1_13F9DC(u32 slot) {
    return ((u32*)lbl_1_bss_8E404)[slot & 0xFF];
}
/* fzgx:end fn_1_13F9DC */

/* fzgx:begin fn_1_13F9F0 */
typedef struct {
    char pad[0x3A4];
    u32 unk_3A4;
} FnObject;

// Releases each active static-display object before clearing its slot.
void fn_1_13F9F0(void) {
    u8 slot;

    for (slot = 0; slot < 8; slot++) {
        if (((u32 *)lbl_1_bss_8E404)[slot] != 0) {
            if (((FnObject *)((u32 *)lbl_1_bss_8E404)[slot])->unk_3A4 != 0) {
                fn_1_7F3AC((void *)((u32 *)lbl_1_bss_8E404)[slot]);
            }
            fn_1_46B4(lbl_801A6410, (u32)(void*)((void *)((u32 *)lbl_1_bss_8E404)[slot]), (const char *)(u8*)(lbl_1_data_419E0), 0x153E);
        }
        ((u32 *)lbl_1_bss_8E404)[slot] = 0;
    }
}
/* fzgx:end fn_1_13F9F0 */

/* fzgx:begin fn_1_13FA88 */
u32 fn_1_13FA88(s16 arg0) {
    switch (arg0) {
    case 4:
        return 1;
    case 6:
        if (lbl_1_bss_8B3A0.unk_4 == 3) {
            break;
        }
        return 1;
    case 3:
        if (lbl_1_bss_8B3A0.unk_4 == 4) {
            return 1;
        }
        break;
    case 7:
        if (lbl_1_bss_8B3A0.unk_4 == 2) {
            break;
        }
        return 1;
    case 5:
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_13FA88 */

/* fzgx:begin fn_1_13FB24 */
int fn_1_13FB24(u32 arg0) {
    switch ((s16)arg0) {
    case 6:
        return 1;
    case 3:
        return 1;
    case 7:
        return 1;
    case 1:
        return 1;
    case 5:
        if (lbl_1_bss_8B3A0.unk_12C != 0) {
            break;
        }
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_13FB24 */

/* fzgx:begin fn_1_13FB8C noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

struct fn_1_13FB8C_Copy88 { u32 a[22]; };
struct fn_1_13FB8C_Copy96 { u32 a[24]; };
struct fn_1_13FB8C_Copy216 { u32 a[54]; };

extern u32 lbl_1_rodata_8F40;
extern u8 lbl_1_rodata_9018[216];
extern u8 lbl_1_rodata_90F0[96];
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_801A66A8;
extern s32 lbl_801A66B4;
extern u32 lbl_1_rodata_9150;
extern u32 lbl_1_rodata_9154;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_9158;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_85F8;
extern const f32 lbl_1_rodata_8B2C;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_9164;
extern const f32 lbl_1_rodata_915C;
extern const f32 lbl_1_rodata_8818;
extern const f32 lbl_1_rodata_8B6C;
extern const f32 lbl_1_rodata_9160;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_9168;
extern const f32 lbl_1_rodata_916C;
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32);
extern void fn_1_4965C(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4954C(f32);
extern void fn_1_49514(u32 *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495C8(u32);
extern void fn_1_4AE0C(const char *, ...);
extern u32 fn_1_4DCB8(u32);
extern void fn_1_4953C(u16);
extern f32 lbl_8006D188(u32);
#pragma opt_common_subs off
#pragma opt_loop_invariants off

static inline s16 fn_1_13FB8C_hidden(s16 row, Obj_1_bss_8B3A0 *state) {
    switch (row) {
    case 6: return 1;
    case 3: return 1;
    case 7: return 1;
    case 1: return 1;
    case 5: if (state->unk_12C == 0) return 1;
    default: return 0;
    }
}
static inline s16 fn_1_13FB8C_hidden0(s16 row, Obj_1_bss_8B3A0 *state) {
    switch (row) {
    case 4: return 1;
    case 6: if (state->unk_4 != 3) return 1; break;
    case 3: if (state->unk_4 == 4) return 1; break;
    case 7: if (state->unk_4 != 2) return 1; break;
    case 5: return 1;
    }
    return 0;
}
static inline f32 fn_1_13FB8C_max(f32 a) {
    f32 b = lbl_1_rodata_861C;
    if (a > b) return a;
    return b;
}
static inline void fn_1_13FB8C_fade_in(f32 delta, f32 half, f32 *alpha) {
    if (fn_1_13FB8C_max(delta) / half < lbl_1_rodata_861C) {
        *alpha = lbl_1_rodata_861C;
    } else if (fn_1_13FB8C_max(delta) / half > lbl_1_rodata_863C) {
        *alpha = lbl_1_rodata_863C;
    } else {
        *alpha = (delta > lbl_1_rodata_861C ? delta : lbl_1_rodata_861C) / half;
    }
}
static inline f32 fn_1_13FB8C_clamp(f32 t) {
    if (t < lbl_1_rodata_861C) return lbl_1_rodata_861C;
    if (t > lbl_1_rodata_863C) return lbl_1_rodata_863C;
    return t;
}
#define PANEL_MAX(a,b) fn_1_13FB8C_max((a))
#define PANEL_CLAMP(v,lo,hi) ((v) < (lo) ? (lo) : ((v) > (hi) ? (hi) : (v)))
#define PACKET_F(n) (((f32 *)&packet)[(n)])
#define PACKET_B(n) (((u8 *)&packet)[(n)])
#define PRINT_VALUE(n) fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0xe8c, ((char **)values.a)[(n) * 6 + lbl_801A66B4])

void fn_1_13FB8C(u32 arg0, u32 arg1, s16 arg2, s16 arg3, s32 arg4, f32 arg5) {
    u8 *p_lbl_1_data_40F58;
    struct fn_1_13FB8C_Copy216 values;
    struct fn_1_13FB8C_Copy216 labels;
    struct fn_1_13FB8C_Copy96 choices;
    char *(*labelRow)[6];
    s32 valueX;
    s16 row;
    s16 originX;
    s16 originY;
    f32 selectedAlpha;
    f32 arrowLeft;
    f32 arrowRight;
    f32 arrowOffset;
    f32 scale;
    f32 alpha;
    f32 half;
    f32 delta;
    u32 oldFont;
    Obj_1_bss_8B3A0 *state;
    p_lbl_1_data_40F58 = (u8 *)&lbl_1_data_40F58;
    values = *(struct fn_1_13FB8C_Copy216 *)&lbl_1_rodata_8F40;
    labels = *(struct fn_1_13FB8C_Copy216 *)lbl_1_rodata_9018;
    choices = *(struct fn_1_13FB8C_Copy96 *)lbl_1_rodata_90F0;
    alpha = lbl_1_rodata_863C;
    scale = lbl_1_rodata_8A4C;
    originX = arg0 + 21 - (s16)arg2 / 2;
    originY = arg1 + 21 - (s16)arg3 / 2;
    if (lbl_801A66B4 != 5) scale = lbl_1_rodata_9158;
    {
    u32 flags;
    Obj_1_bss_8B3A0 *fadeState;
    fadeState = (Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0;
    flags = fadeState->unk_140;
    if ((flags & 0x80000000) && (flags & 0x20)) {
        half = (f32)fadeState->unk_148 / 2.0f;
        if (flags & 2) {
            fn_1_13FB8C_fade_in((f32)fadeState->unk_146 - half, half, &alpha);
        } else if (flags & 1) {
            f32 t = (f32)fadeState->unk_146 / half;
            t = fn_1_13FB8C_clamp(t);
            alpha = lbl_1_rodata_863C - t;
        }
    } else if (lbl_1_bss_8B3A0.unk_0 == -1) {
        return;
    }
    }
    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_4955C(scale, scale);
    fn_1_495A0(alpha);
    fn_1_4954C(arg5);
    labelRow = (char *(*)[6])labels.a;
    state = (Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0;
    arrowOffset = lbl_1_rodata_85F8 * scale;
    selectedAlpha = lbl_1_rodata_85F0 * alpha;
    arrowLeft = (f32)(originX + 158) + arrowOffset;
    arrowRight = (f32)(originX + 301) + arrowOffset;
    valueX = originX + 238;
    for (row = 0; row < 9; labelRow++, row++) {
        u32 color = lbl_1_rodata_9150;
        fn_1_49514(&color);
        if (row == state->unk_92) {
            struct fn_1_13FB8C_Copy88 packet;
            packet = *(struct fn_1_13FB8C_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 18;
            PACKET_F(1) = (f32)(s16)arg0;
            PACKET_F(2) = (f32)((s16)originY - 2);
            PACKET_F(3) = lbl_1_rodata_915C;
            packet.a[12] = 6;
            PACKET_F(4) = PACKET_F(4) * lbl_1_rodata_8818;
            PACKET_F(5) = PACKET_F(5) * lbl_1_rodata_8B6C;
            PACKET_B(0x38) = (s32)(lbl_1_rodata_9160 + (f32)(lbl_1_rodata_88A8 * lbl_8006D188((s32)(lbl_1_rodata_9164 + (f32)(lbl_1_rodata_8B2C * (lbl_801A66A8 % 60)) / lbl_1_rodata_8B30))));
            PACKET_B(0x39) = (s32)(lbl_1_rodata_9168 + (f32)(lbl_1_rodata_916C * lbl_8006D188((s32)(lbl_1_rodata_9164 + (f32)(lbl_1_rodata_8B2C * (lbl_801A66A8 % 60)) / lbl_1_rodata_8B30))));
            PACKET_B(0x3a) = (s32)(lbl_1_rodata_9168 + (f32)(lbl_1_rodata_916C * lbl_8006D188((s32)(lbl_1_rodata_9164 + (f32)(lbl_1_rodata_8B2C * (lbl_801A66A8 % 60)) / lbl_1_rodata_8B30))));
            PACKET_F(11) = selectedAlpha;
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        if (arg4 == 1 && fn_1_13FB8C_hidden(row, state) && row != 5) continue;
        if (arg4 == 0 && fn_1_13FB8C_hidden0(row, state)) continue;
        if (row == 8) {
            fn_1_496FC((f32)(s16)arg0, (f32)(s16)originY);
            fn_1_495C8(1);
            fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0x11cc, (*labelRow)[lbl_801A66B4]);
        } else {
            if (arg4 == 1 && fn_1_13FB8C_hidden(row, state) && row == 5) {
                u32 disabledColor = lbl_1_rodata_9154;
                fn_1_49514(&disabledColor);
            }
            fn_1_496FC((f32)originX, (f32)(s16)originY);
            fn_1_495C8(0);
            fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0x11cc, (*labelRow)[lbl_801A66B4]);
            {
                alpha = (f32)(s16)originY + arrowOffset;
                fn_1_496FC(arrowLeft, alpha);
                oldFont = fn_1_4DCB8(10);
                fn_1_4953C(0x4444);
                fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0x11d0);
                fn_1_4DCB8(oldFont);
                fn_1_496FC(arrowRight, alpha);
                oldFont = fn_1_4DCB8(10);
                fn_1_4953C(0xbbbb);
                fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0x11d0);
                fn_1_4DCB8(oldFont);
                fn_1_4953C(0);
            }
        }
        fn_1_496FC((f32)valueX, (f32)(s16)originY);
        fn_1_495C8(1);
        switch (row) {
        case 4:
            fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0x11d4, state->unk_12C);
            break;
        case 6:
            if (state->unk_12E == 0) PRINT_VALUE(0);
            else PRINT_VALUE(1);
            break;
        case 3:
            if (state->unk_130 == 0) PRINT_VALUE(5);
            else PRINT_VALUE(4);
            break;
        case 1:
            if (state->unk_132 == 0) PRINT_VALUE(3);
            else PRINT_VALUE(2);
            break;
        case 7:
            if (state->unk_134 == 0) PRINT_VALUE(7);
            else PRINT_VALUE(6);
            break;
        case 2:
            if (arg4 == 1) {
                if (state->unk_136 == 0) PRINT_VALUE(3);
                else PRINT_VALUE(2);
            } else {
                if (state->unk_138 == 0) PRINT_VALUE(3);
                else PRINT_VALUE(2);
            }
            break;
        case 0:
            if (arg4 == 1) {
                s16 count = state->unk_13A;
                if ((s16)count == 0) PRINT_VALUE(8);
                else fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0x11d4, count);
            } else fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0x11d4, state->unk_13C);
            break;
        case 5:
            fn_1_4AE0C((char *)p_lbl_1_data_40F58 + 0xe8c, ((char *(*)[6])choices.a)[state->unk_8][lbl_801A66B4]);
            break;
        }
        originY += 23;
    }
}
/* fzgx:end fn_1_13FB8C */

/* fzgx:begin fn_1_14108C noprologue */
#include "types.h"
#include "font.h"

typedef struct {
    u32 words[11];
} U32x11;

typedef struct {
    u32 unk0;      // 0x00
    f32 x;         // 0x04
    f32 y;         // 0x08
    f32 z;         // 0x0c
    f32 unk10;     // 0x10
    f32 unk14;     // 0x14
    u32 unk18[6];  // 0x18
    u32 unk30;     // 0x30
    u32 unk34[9];  // 0x34
} Packet;

extern u32 lbl_1_rodata_91C0[11];
extern f32 lbl_1_rodata_26F8[22];
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_91EC;
extern const f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_91F0;
extern const f32 lbl_1_rodata_8B30;
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_141338(u8, u32, u32, u32, f32);

void fn_1_14108C(s16 arg0, s32 arg1, s32 arg2) {
    U32x11 ids;
    Packet packet;
    f32 v;

    ids = *(U32x11 *)lbl_1_rodata_91C0;

    packet = *(Packet *)lbl_1_rodata_26F8;
    packet.unk0 = ids.words[arg0];
    packet.x = (f32)arg1;
    packet.y = (f32)arg2;
    packet.z = lbl_1_rodata_85E8;
    packet.unk10 = packet.unk10 * lbl_1_rodata_91EC;
    packet.unk14 = packet.unk14 * lbl_1_rodata_91EC;
    packet.unk30 = 10;
    fn_1_4F734((FontDrawPacket *)&packet);

    v = lbl_1_rodata_8674 - (f32)arg1;
    packet.x = v;
    fn_1_4F734((FontDrawPacket *)&packet);

    packet = *(Packet *)lbl_1_rodata_26F8;
    packet.unk0 = 0x10000 - 0x5EF7;
    packet.x = (f32)arg1;
    packet.y = (f32)arg2;
    packet.z = lbl_1_rodata_8B30;
    packet.unk10 = packet.unk10 * lbl_1_rodata_91F0;
    packet.unk14 = packet.unk14 * lbl_1_rodata_91EC;
    packet.unk30 = 10;
    fn_1_4F734((FontDrawPacket *)&packet);

    packet.x = v;
    fn_1_4F734((FontDrawPacket *)&packet);

    fn_1_141338(arg0, (u32)arg1, (u32)arg2, 0x2D, lbl_1_rodata_91EC);
    fn_1_141338(arg0, (u32)(s32)v, (u32)arg2, 0x2D, lbl_1_rodata_91EC);
}
/* fzgx:end fn_1_14108C */

/* fzgx:begin fn_1_141338 */
// Pass through the caller's arguments and append the default scale factor.
void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4) {
    fn_1_141360(arg0, arg1, arg2, arg3, arg4, lbl_1_rodata_863C);
}
/* fzgx:end fn_1_141338 */

/* fzgx:begin fn_1_141360 noprologue */
#include "types.h"

typedef struct { u8 a, b, c, d; } Ent;
typedef struct { Ent e[5]; } Tbl;
typedef struct {
    u32 f00;
    f32 f04;
    f32 f08;
    f32 f0C;
    f32 f10;
    f32 f14;
    u8  f18[0x18];
    u32 f30;
    u32 f34;
    u8  f38;
    u8  f39;
    u8  f3A;
    u8  f3B[0x15];
    u32 f50;
    u32 f54;
} Pkt;

extern Tbl lbl_1_rodata_91F4;
extern Pkt lbl_1_rodata_26F8;
extern u32 lbl_801A66A0[1];
extern f32 lbl_8006D188(u32);
extern const f32 lbl_1_rodata_8B2C;
extern const f64 lbl_1_rodata_8608;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_87E8;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_8A24;
extern int fn_1_4F734(Pkt *);
extern void fn_1_52718(void);

#pragma opt_propagation off
static inline f32 fn_1_141360_operand(f32 right, f32 left) { return left * right; }
void fn_1_141360(u32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5)
{
    Tbl tbl;
    Pkt pkt;
    s32 idx;
    s32 j;
    f32 t, u, v;

    tbl = lbl_1_rodata_91F4;
    j = (s32)(arg0 & 0xFF) - 1;
    if (j < 0) {
        idx = 0;
    } else {
        idx = 4;
        if ((u32)j <= 4) {
            idx = j;
        }
    }
    t = (*(const f32 volatile *)&lbl_1_rodata_87AC) /* Retail reloads this object. */ * (lbl_1_rodata_863C + (lbl_8006D188((s32)(fn_1_141360_operand((lbl_1_rodata_87E8), (lbl_1_rodata_8B2C * (f32)(u32)(lbl_801A66A0[0] & 3)))))));
    u = t * lbl_1_rodata_85F0;
    v = lbl_1_rodata_8A24 + u;
    v = arg5 * v;
    pkt = lbl_1_rodata_26F8;
    pkt.f00 = 0x10000 - 0x5EEE;
    pkt.f04 = (f32)arg1;
    pkt.f08 = (f32)arg2;
    pkt.f0C = (f32)arg3;
    pkt.f10 = pkt.f10 * arg4;
    pkt.f14 = pkt.f14 * arg4;
    pkt.f38 = (u8)(s32)(v * (f32)(u32)tbl.e[(u8)idx].a);
    pkt.f39 = (u8)(s32)(v * (f32)(u32)tbl.e[(u8)idx].b);
    pkt.f3A = (u8)(s32)(v * (f32)(u32)tbl.e[(u8)idx].c);
    pkt.f30 = 0x4000000 + 0xA;
    pkt.f50 = (u32)&fn_1_52718;
    fn_1_4F734(&pkt);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_141360 */

/* fzgx:begin fn_1_141614 */
void fn_1_141614(s16 arg0) {
    fn_1_49410();
    fn_1_494DC(8);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(lbl_1_rodata_861C);
    fn_1_495B0(1u << 31);
    fn_1_495C8( (void*)(int)(1));
    fn_1_4955C(lbl_1_rodata_9208, lbl_1_rodata_9208);
    fn_1_4966C(lbl_1_rodata_8638, lbl_1_rodata_861C);
    fn_1_496FC(lbl_1_rodata_8658, lbl_1_rodata_920C);
    fn_1_4A0D8( (const char*)(void*)(*(void**)(lbl_1_data_2AA24 +
            4 * ((u8*)&lbl_1_data_2B0D4)[(s16)arg0])));

    fn_1_49410();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(lbl_1_rodata_861C);
    fn_1_495B0(1u << 31);
    fn_1_495C8( (void*)(int)(1));
    fn_1_4966C(lbl_1_rodata_8638, lbl_1_rodata_861C);
    fn_1_4955C(lbl_1_rodata_85EC, lbl_1_rodata_85EC);
    fn_1_496FC(lbl_1_rodata_8658, lbl_1_rodata_9210);
    fn_1_4A0D8( (const char*)(void*)(((void**)(lbl_1_data_2BD54 + (s16)arg0 * 24))[lbl_801A66B4]));
}
/* fzgx:end fn_1_141614 */

/* fzgx:begin fn_1_141754 */
typedef struct {
    u32 w[3];
} Copy9214;

typedef struct {
    u32 w0;
    u32 w1;
    u16 h;
} Copy9220;

void fn_1_141754(s32 arg0, s32 arg1) {
    FontDrawPacket packet;
    Copy9214 copy9214;
    Copy9220 copy9220;
    u8 *var_r29;
    u8 *var_r28;
    s32 var_r27;
    s32 var_r26;
    u32 i;
    u32 image;
    FontDrawPacket *src;

    copy9214.w[0] = *(u32 *)((u8 *)lbl_1_rodata_9214 + 0);
    copy9214.w[1] = *(u32 *)((u8 *)lbl_1_rodata_9214 + 4);
    copy9214.w[2] = *(u32 *)((u8 *)lbl_1_rodata_9214 + 8);
    copy9220.w0 = *(u32 *)((u8 *)lbl_1_rodata_9220 + 0);
    copy9220.w1 = *(u32 *)((u8 *)lbl_1_rodata_9220 + 4);
    copy9220.h = *(u16 *)((u8 *)lbl_1_rodata_9220 + 8);
    image = (0x10000 - 0x5EF1);
    var_r27 = 0;
    var_r26 = 0;
    var_r29 = (u8 *)&copy9214;
    var_r28 = (u8 *)&copy9220;
    i = 0;
    src = (FontDrawPacket *)&(*((u32 *)&lbl_1_rodata_26F8));
    do {
        packet = *src;
        packet.image = image;
        fn_1_51678(&packet, packet.image, var_r26, 0, *(u16 *)var_r29,
                   fn_1_486C4(packet.image));
        packet.x = (f32)((((arg0) + (0x16)) + (var_r27)));
        packet.y = (f32)(arg1 + 0x12);
        packet.z = lbl_1_rodata_8E9C;
        *(u32 *)((u8 *)&packet + 0x30) = 0xa;
        fn_1_4F734(&packet);
        var_r27 += *(u16 *)var_r28;
        var_r26 += *(u16 *)var_r29;
        if (i == 4) {
            var_r26 += 0x14;
        }
        i += 1;
        var_r29 += 2;
        var_r28 += 2;
    } while (i < 6);
}
/* fzgx:end fn_1_141754 */

/* fzgx:begin fn_1_1418EC noprologue */
#include "types.h"
#include "font.h"

struct S16 {
	u32 a;
	u32 b;
	u32 c;
	u16 d;
};

struct Pkt {
	u32 index;
	f32 x;
	f32 y;
	f32 z;
	u8 pad[32];
	u32 flags;
	u8 tail[36];
};

extern struct S16 lbl_1_rodata_922C;
extern u32 lbl_1_rodata_923C[3];
extern struct Pkt lbl_1_rodata_26F8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_8E9C;
extern u16 fn_1_486C4(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

static inline u32 fn_1_1418EC_array_read(u32 *array, s32 index) { return array[index]; }
#pragma opt_loop_invariants off
void fn_1_1418EC(u32 arg0, u32 arg1) {
	struct S16 wid;
	u32 ln[3];
	struct Pkt pkt;
	u32 xoff = 0;
	s32 aoff = 0;
	u32 i;
	u32 a0 = arg0;
	u32 id = 0xA10F;
	s16 w;

	wid.a = lbl_1_rodata_922C.a;
	wid.b = lbl_1_rodata_922C.b;
	wid.c = lbl_1_rodata_922C.c;
	wid.d = lbl_1_rodata_922C.d;

	ln[0] = fn_1_1418EC_array_read(lbl_1_rodata_923C, 0);
	ln[1] = fn_1_1418EC_array_read(lbl_1_rodata_923C, 1);
	ln[2] = fn_1_1418EC_array_read(lbl_1_rodata_923C, 2);

	for (i = 0; i < 7; i++) {
		pkt = lbl_1_rodata_26F8;
		pkt.index = id;
		w = fn_1_486C4(pkt.index);
		fn_1_51678((FontDrawPacket *)&pkt, pkt.index, (s16)aoff, 0,
			(s16)((u16 *)&wid)[i], w);
		pkt.x = (f32)(s32)((((a0) + (0x16)) + (xoff)));
		pkt.y = (f32)(s32)(arg1 + 0x12);
		pkt.z = lbl_1_rodata_8E9C;
		pkt.flags = 10;
		fn_1_4F734((FontDrawPacket *)&pkt);
		xoff += ((u16 *)ln)[i];
		aoff += ((u16 *)&wid)[i];
	}
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_1418EC */

/* fzgx:begin fn_1_141F94 */
typedef struct fn_1_141F94_Entry {
    u8 pad[0x0E];
    s16 value;
    u8 tail[0x10];
} fn_1_141F94_Entry;


u8 fn_1_141F94(u32 arg0) {
    fn_1_141F94_Entry *entry;
    u32 index = arg0 & 0xFF;
    u8 count = 0;

    if (index >= 4) {
        return 0;
    }
    entry = (((fn_1_141F94_Entry *)&lbl_1_bss_8B3A0));
    if ((((fn_1_141F94_Entry *)&lbl_1_bss_8B3A0))[(u8)arg0].value == -1) {
        return 0;
    }
    for (; (s32)index > 0; index--) {
        if (entry->value != -1) {
            count++;
        }
        entry++;
    }
    return count;
}
/* fzgx:end fn_1_141F94 */

/* fzgx:begin fn_1_142004 */
typedef struct fn_1_142004_Entry {
    u8 pad[0x0E];
    s16 value;
    u8 tail[0x10];
} fn_1_142004_Entry;


int fn_1_142004(u8 arg0) {
    fn_1_142004_Entry *entry = (((fn_1_142004_Entry *)&lbl_1_bss_8B3A0));
    s32 index = -1;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (entry->value != -1) {
            if (++index == arg0) {
                return i;
            }
        }
        entry++;
    }
    return 0;
}
/* fzgx:end fn_1_142004 */

/* fzgx:begin fn_1_1420A4 */
void fn_1_1420A4(void) {
    ((void (**)(void))lbl_1_data_4244C)[lbl_1_bss_8E51D]();
}
/* fzgx:end fn_1_1420A4 */

/* fzgx:begin fn_1_1420E0 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern int fn_1_5910(void);
extern u32 fn_1_58C4(void);
extern void fn_1_52070(int);
extern void fn_1_52088(void);
extern u8 lbl_1_bss_26B1E[46];
extern void fn_1_1421D8(u32, u32, u32);
extern void fn_1_1424E8(u32, u32, u32);
extern void fn_1_14267C(u32, u32, u32);
extern void fn_1_142BDC(u32, u32, u32);
extern void fn_1_14328C(u32, u32, u32);
extern void fn_1_143780(u32, u32, u32);
extern void fn_1_143F5C(u32, u32, u32);
extern void fn_1_144254(u32, u32, u32);

#pragma opt_branch off
void fn_1_1420E0(void) {
    u32 v;
    u8 flag;
    u8 mask;

    v = fn_1_5910();
    flag = lbl_1_bss_3C30.unk_8;
    mask = (u8)(1 << v);
    if (flag < 1 || !(lbl_1_bss_26B1E[0] & mask)) {
        return;
    }
    fn_1_52070(0x140);
    if (fn_1_58C4() == 1) {
        fn_1_1421D8(0x25, 0x31, v);
        fn_1_14267C(0x2c, 0x40, v);
        fn_1_14328C(0xdb, 0x14a, v);
        fn_1_142BDC(0x39, 0x128, v);
        fn_1_1424E8(0x25, 0x31, v);
        fn_1_143780(0xf2, 0x40, v);
        fn_1_143F5C(0xf2, 0x122, v);
        fn_1_144254(0x2c, 0x15a, v);
    }
    fn_1_52088();
}
/* fzgx:end fn_1_1420E0 */

/* fzgx:begin fn_1_1421D8 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 1.0f;
}
static const unsigned long fzgx_pool_table3[61] = {0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 0.9583333134651184f;
    s = 23.0f;
    s = 2.0f;
    s = 0.6666666865348816f;
    s = 0.5f;
    s = 0.5833333134651184f;
}
static const unsigned long fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

extern f32 fn_1_4B068(s32);
extern u32 fn_1_5233C(void *, void *);
extern u32 lbl_801A66B4;
extern void fn_1_13D460(s32, s32, s32, s32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(void *);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);

void fn_1_1421D8(u32 arg0, u32 arg1) {
    u32 v8;
    Obj_1_bss_3C30 *p_lbl_1_bss_3C30;
    f32 v0;
    s32 v3;
    u32 v2;
    f32 v4;
    s32 v7;
    u32 v9;
    f32 v10;
    f32 v11;
    s32 v14;
    f32 v15;
    f32 v18;
    s32 v19;
    f32 t15;
    f32 t23;
    fn_1_49410();
    fn_1_494DC(8);
    fn_1_495B0(0x80000000);
    fn_1_49738((void *)fn_1_5233C);
    fn_1_49748(0.0f);
    fn_1_495C8((void *)8);
    v0 = 0.9583333134651184f;
    fn_1_4955C(v0, v0);
    fn_1_496FC((f32)(s32)arg0, (f32)(s32)arg1);
    fn_1_4AE0C((const char *)&lbl_1_data_42478);
    p_lbl_1_bss_3C30 = &lbl_1_bss_3C30;
    v2 = ((u32 *)lbl_1_data_2AA24)[((u8 *)&lbl_1_data_2B0D4)[p_lbl_1_bss_3C30->unk_6]];
    v3 = arg0;
    v3 += 23.0f;
    fn_1_4966C(2.0f, 0.0f);
    v4 = 0.6666666865348816f;
    fn_1_4955C(v4, v4);
    fn_1_496FC((f32)v3, (f32)(s32)arg1);
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_4A0D8((const char *)v2);
    t15 = fn_1_4B068(v2);
    v3 += t15;
    v3 += 14;
    v7 = p_lbl_1_bss_3C30->unk_6 * 24;
    v8 = ((u32 (*)[6])lbl_1_data_2BD54)[p_lbl_1_bss_3C30->unk_6][lbl_801A66B4];
    fn_1_494DC(42);
    v10 = 0.0f;
    fn_1_4966C(v10, v10);
    v11 = 0.5833333134651184f;
    fn_1_4955C(v11, v11);
    fn_1_496FC((f32)v3, (f32)(s32)arg1);
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_4A0D8((const char *)v8);
    t23 = fn_1_4B068(v8);
    v3 += t23;
    fn_1_494DC(8);
    v15 = 0.9583333134651184f;
    fn_1_4955C(v15, v15);
    fn_1_496FC((f32)v3, (f32)(s32)arg1);
    fn_1_4AE0C((const char *)&lbl_1_data_4247C);
    v3 += 23.0f;
    fn_1_13D460(v3, arg1 + 8, 596 - v3, 0);
}
/* fzgx:end fn_1_1421D8 */

/* fzgx:begin fn_1_1424E8 */
void fn_1_1424E8(u32 unused, s32 arg1) {
    FontDrawPacket loc_8;
    s32 mode;

    if (lbl_1_bss_3C30.unk_0 & 0x04000000) {
        mode = 7;
    } else {
        switch (lbl_1_bss_3C30.unk_5) {
        case 1:
            switch (lbl_1_bss_3C30.unk_A6) {
            case 1: mode = 0; break;
            case 2: mode = 1; break;
            case 3: mode = 2; break;
            case 4: mode = 3; break;
            case 5: mode = 4; break;
            default: mode = 0; break;
            }
            break;
        case 0:
        case 6:
            mode = 5;
            break;
        case 2:
            mode = 6;
            break;
        default:
            mode = 7;
            break;
        }
    }

    loc_8 = *(FontDrawPacket *)&(*((u32 *)&lbl_1_rodata_26F8));
    loc_8.image = 0x9901;
    fn_1_51564(0, 0, 0xA0, 0x10, 1, 8);
    fn_1_5158C(&loc_8, loc_8.image, 0, mode);
    loc_8.x = lbl_1_rodata_93F0[0];
    loc_8.y = (f32)(arg1 - 8);
    loc_8.flags = 7;
    fn_1_4F734(&loc_8);
}
/* fzgx:end fn_1_1424E8 */

/* fzgx:begin fn_1_14267C noprologue */
#include "types.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/shadowmap.h"
#include "psvec.h"
#include "rel/main_rel/sel_static_disp.h"

/* begin game/main_rel/shadowmap_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_SHADOWMAP_TYPES_H
#define GAME_MAIN_REL_SHADOWMAP_TYPES_H

// Types (and the externs that name them) of shadowmap.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct fn_1_568F8_Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_1_568F8_Color;

typedef struct fn_1_568F8_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} fn_1_568F8_Vec3;

typedef struct fn_1_568F8_Pool {
    fn_1_568F8_Color tev_color;  // 0x00
    f32 zero;                    // 0x04
    fn_1_568F8_Vec3 axis_x;      // 0x08
    fn_1_568F8_Vec3 axis_y;      // 0x14
    fn_1_568F8_Vec3 axis_z;      // 0x20
    fn_1_568F8_Vec3 up;          // 0x2c
    fn_1_568F8_Color clear_color;  // 0x38
    fn_1_568F8_Color chan_color;   // 0x3c
    f32 neg_three;               // 0x40
    f32 one;                     // 0x44
    f32 twenty;                  // 0x48
    f32 three;                   // 0x4c
    f32 hundred;                 // 0x50
    f32 size;                    // 0x54
} fn_1_568F8_Pool;

typedef struct fn_1_568F8_Data {
    u8 pad_0[0x38c];
    u8 light_mask;               // 0x38c
    u8 pad_38d[0x2b];
    s16 light_param;             // 0x3b8
} fn_1_568F8_Data;

typedef struct fn_1_568F8_Mtx44 {
    f32 m[4][4];
} fn_1_568F8_Mtx44;

extern fn_1_568F8_Pool lbl_1_rodata_28B0;
extern void fn_1_870BC(fn_1_568F8_Data *, s8, fn_1_568F8_Data *, s32, u8, f32);
extern void fn_80015EE8(fn_1_568F8_Mtx44 *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(fn_1_568F8_Mtx44 *, s32);
extern void fn_800744F8(fn_1_568F8_Color, u32);
extern void fn_800725DC(fn_1_568F8_Color);
extern void fn_80072614(fn_1_568F8_Color);

#endif  // GAME_MAIN_REL_SHADOWMAP_TYPES_H

/* end game/main_rel/shadowmap_types.h */

typedef struct Sig_fn_1_144A5C_fn_1_143F5C_Args {
 s32 x,y,w0,h0,w1,h1; u32 *list0; s32 count0; u32 *list1; s32 count1;
} Sig_fn_1_144A5C_fn_1_143F5C_Args;
typedef struct { u8 _pad[6]; s16 field_6; } Sig_fn_1_8472C_Fn18472CObject;
typedef struct Sig_fn_80015EE8_Fn80015EE8Out { f32 f[16]; } Sig_fn_80015EE8_Fn80015EE8Out;
struct Sig_fn_800737E4_fn_800737E4_Arg0 { f32 unk_0; u8 pad_4[4]; f32 unk_8,unk_C; u8 pad_10[4]; f32 unk_14,unk_18,unk_1C; u8 pad_20[8]; f32 unk_28,unk_2C; };
struct Sig_fn_80072270_fn_80072270_Arg0 { f32 unk_0,unk_4,unk_8,unk_c,unk_10,unk_14,unk_18; };
struct fn_1_14267C_Copy88 { u32 a[22]; };
struct fn_1_14267C_lbl_1_rodata_92C0 {
 u8 pad_0[0x108]; f32 unk_108; u8 pad_10C[0x1C]; f64 unk_128; u8 pad_130[8];
 u32 unk_138,unk_13C,unk_140,unk_144,unk_148,unk_14C,unk_150,unk_154,unk_158,unk_15C,unk_160;
 f32 unk_164,unk_168,unk_16C,unk_170,unk_174,unk_178,unk_17C,unk_180,unk_184,unk_188,unk_18C,unk_190,unk_194;
};
struct fn_1_14267C_lbl_1_data_1E5C0 { u32 unk_0,unk_4,unk_8,unk_C,unk_10,unk_14,unk_18,unk_1C,unk_20,unk_24,unk_28,unk_2C,unk_30; };
extern struct fn_1_14267C_lbl_1_data_1E5C0 lbl_1_data_1E5C0;
struct PanelPoolU32 { u32 v; };
struct PanelPoolF32 { f32 v; };
extern u8 fn_1_149BF4__fzgx_offset_0[], fn_1_149C2C__fzgx_offset_0[], fn_1_149C64__fzgx_offset_0[];
static const union { u32 w[66]; u32 v[66]; } fzgx_pool_prefix = {{ /* fzgx-allow: A1 retail data bytes and bindings */
0x0,0x0,0x0,0x3DCCCCCD,0x3F800000,0x3F800000,0x0,0x0,0x3F800000,0x3F800000,0x0,0x3F800000,0x4000000,0x0,0xFFFFFFFF,0x0,0x0,0x0,0x0,0x0,(u32)fn_1_149BF4__fzgx_offset_0,0x0,0x0,0x0,0x0,0x3DCCCCCD,0x3F800000,0x3F800000,0x0,0x0,0x3F800000,0x3F800000,0x0,0x3F800000,0x4000000,0x0,0xFFFFFFFF,0x0,0x0,0x0,0x0,0x0,(u32)fn_1_149C2C__fzgx_offset_0,0x0,0x0,0x0,0x0,0x3DCCCCCD,0x3F800000,0x3F800000,0x0,0x0,0x3F800000,0x3F800000,0x0,0x3F800000,0x4000000,0x0,0xFFFFFFFF,0x0,0x0,0x0,0x0,0x0,(u32)fn_1_149C64__fzgx_offset_0,0x0
}};
const struct PanelPoolF32 fzgx_pool_108 = {0.0f};
const u32 fzgx_pool_table_10C[7] = {0x3F755555,0x41B80000,0x40000000,0x3F2AAAAB,0x3F000000,0x3F155555,0};
#define lbl_1_rodata_92C0 ((const u32 *)((const u8 *)&fzgx_pool_108 - 0x108))
#define fn_1_14267C_pool_primer fzgx_panel_pool_primer
#pragma section code_type ".fzgxpool"
f32 fzgx_panel_pool_primer(s32 v) { return (f32)v; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_130[2] = {0x44150000,0x44040000};
const struct PanelPoolU32 fzgx_pool_138 = {26};
const struct PanelPoolU32 fzgx_pool_13C = {35};
const struct PanelPoolU32 fzgx_pool_140 = {156};
const struct PanelPoolU32 fzgx_pool_144 = {165};
const struct PanelPoolU32 fzgx_pool_148 = {24};
const struct PanelPoolU32 fzgx_pool_14C = {33};
const struct PanelPoolU32 fzgx_pool_150 = {133};
const struct PanelPoolU32 fzgx_pool_154 = {142};
const struct PanelPoolU32 fzgx_pool_158 = {242};
const struct PanelPoolU32 fzgx_pool_15C = {251};
const struct PanelPoolU32 fzgx_pool_160 = {0xC0C0C000}; /* fzgx-allow: A1 retail RGBA data bytes */
const struct PanelPoolF32 fzgx_pool_164 = {-4.0f};
const struct PanelPoolF32 fzgx_pool_168 = {40.0f};
const struct PanelPoolF32 fzgx_pool_16C = {480.0f};
const struct PanelPoolF32 fzgx_pool_170 = {640.0f};
const struct PanelPoolF32 fzgx_pool_174 = {90000.0f};
const struct PanelPoolF32 fzgx_pool_178 = {0.3f};
const struct PanelPoolF32 fzgx_pool_17C = {0.7f};
const struct PanelPoolF32 fzgx_pool_180 = {-1.0f};
const struct PanelPoolF32 fzgx_pool_184 = {208.0f};
const struct PanelPoolF32 fzgx_pool_188 = {-1000.0f};
const struct PanelPoolF32 fzgx_pool_18C = {-50.0f};
const struct PanelPoolF32 fzgx_pool_190 = {1.0f};
const struct PanelPoolF32 fzgx_pool_194 = {10.0f};
extern struct fn_1_14267C_Copy88 lbl_1_rodata_26F8;
extern u8 lbl_1_data_1A2B4[176];
extern u32 fn_1_144A5C(void *);
extern u32 fn_1_86900(u32);
extern s16 fn_1_12C930(void *);
extern void fn_1_49410(void),fn_1_4962C(void);
extern void fn_1_494DC(s16);
extern void fn_1_4966C(f32,f32),fn_1_496FC(f32,f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4AE0C(const char *,...);
extern void fn_1_4A0D8(const char *);
extern void *fn_1_8472C(Sig_fn_1_8472C_Fn18472CObject *);
extern char *fn_1_14FEAC(void *,void *,void *,char *,void *);
extern void *fn_1_7F49C(s16,void *,void *);
extern s8 fn_1_8421C(u32,u32);
extern void fn_80038BFC(f32 *);
extern u32 fn_80038FD8(void *,void *,void *,void *);


extern void fn_1_F7870(u32);
extern void fn_1_149CA4(u32,u32,u32,u32);
extern f32 fn_1_520F8(s32),fn_1_521B8(s32);
extern u32 lbl_8006D7F4(f32,f32,f32);
extern void lbl_8006E14C(f32),lbl_8006E15C(f32,f32,f32);
extern u32 mathutil_mtxA_rotate_z(u32),mathutil_mtxA_rotate_x(u32);
extern void fn_80072558(void),fn_80074918(u8,s32,u8);
extern void fn_1_151BDC(void *);
extern void fn_1_870BC(fn_1_568F8_Data *,s8,fn_1_568F8_Data *,s32,u8,f32);
extern f64 fn_80074188(u32,u32,u32,u32);
extern void fn_80072270(struct Sig_fn_80072270_fn_80072270_Arg0 *);
extern int fn_1_4F734(void *);

static inline f32 panel_float(s32 v, f64 bias) {
 union { f64 d; u32 w[2]; } c;
 c.w[0]=0x43300000; c.w[1]=(u32)v^0x80000000;
 return c.d-bias;
}
#pragma opt_common_subs off
void fn_1_14267C(u32 arg0,u32 arg1,u32 arg2,f32 arg3,f32 arg4) {
 u32 v2;
 s32 v3;
 s32 v5;
 s16 t3;
 u32 v8;
 s8 t24;
 u8 *t19;
 struct fn_1_14267C_lbl_1_data_1E5C0 *q;
 struct fn_1_14267C_Copy88 packet;
 Sig_fn_1_144A5C_fn_1_143F5C_Args loc_114;
 Sig_fn_80015EE8_Fn80015EE8Out loc_D4;
 struct fn_1_14267C_lbl_1_data_1E5C0 loc_A0;
 struct { u32 a[6]; } loc_88;
 char loc_68[32],loc_48[32];
 struct Sig_fn_80072270_fn_80072270_Arg0 loc_2C;
 struct { u32 a[4]; } loc_1C;
 u32 loc_18,loc_14,loc_10,loc_C,loc_8;
 s32 level;
 loc_1C.a[0]=fzgx_pool_138.v; loc_1C.a[1]=fzgx_pool_13C.v; loc_1C.a[2]=fzgx_pool_140.v; loc_1C.a[3]=fzgx_pool_144.v;
 loc_88.a[0]=fzgx_pool_148.v; loc_88.a[1]=fzgx_pool_14C.v; loc_88.a[2]=fzgx_pool_150.v; loc_88.a[3]=fzgx_pool_154.v; loc_88.a[4]=fzgx_pool_158.v; loc_88.a[5]=fzgx_pool_15C.v;
 loc_114.x=arg0; loc_114.y=arg1; loc_114.w0=192; loc_114.h0=278; loc_114.w1=180; loc_114.h1=270;
 loc_114.list0=loc_1C.a; loc_114.count0=4; loc_114.list1=loc_88.a; loc_114.count1=6;
 fn_1_144A5C(&loc_114);
 v2=fn_1_86900((s8)arg2);
 if (!v2) {
  for(v3=0;v3<4;v3++) { v2=fn_1_86900((s8)v3); if(v2) break; }
  if(!v2) return;
 }
 v5=*(s8 *)(v2+0x328);
 t3=fn_1_12C930((void *)v5);
 fn_1_49410(); fn_1_494DC(4); fn_1_4962C();
 fn_1_4966C(fzgx_pool_164.v,((const f32 *)lbl_1_rodata_92C0)[66]);
 loc_8=fzgx_pool_160.v; fn_1_49514(&loc_8);
 fn_1_496FC(fn_1_14267C_pool_primer(arg0+15),(f32)(s32)(arg1+16));
 fn_1_4954C(fzgx_pool_168.v);
 fn_1_4AE0C((char *)&lbl_1_data_42480);
 fn_1_496FC((f32)(s32)(arg0+15),(f32)(s32)(arg1+32));
 v8=(s16)t3<<2;
 fn_1_4A0D8((char *)*(u32 *)((u8 *)&lbl_1_data_212A8.unk_0+v8));
 fn_1_496FC((f32)(s32)(arg0+15),(f32)(s32)(arg1+54));
 fn_1_4AE0C((char *)&lbl_1_data_422B0);
 fn_1_496FC((f32)(s32)(arg0+15),(f32)(s32)(arg1+70));
 fn_1_4962C();
 if(v5>40) {
  fn_1_8472C(*(Sig_fn_1_8472C_Fn18472CObject **)(v2+812));
  if(v2) {
   t19=fn_1_8472C(*(Sig_fn_1_8472C_Fn18472CObject **)(v2+812));
   if(t19) fn_1_4A0D8(fn_1_14FEAC((void *)t19[0x81A4],(void *)t19[0x81AC],(void *)t19[0x81B4],loc_48,0));
  }
 } else fn_1_4A0D8(fn_1_7F49C(v5,0,loc_68));
 if(v2) {
  t24=fn_1_8421C(v2,0);
  fn_80038BFC((f32 *)&loc_2C);
  fn_80038FD8(&loc_18,&loc_14,&loc_10,&loc_C);
  fn_80015EE8((void *)&loc_D4,((const f32 *)lbl_1_rodata_92C0)[66],fzgx_pool_16C.v,((const f32 *)lbl_1_rodata_92C0)[66],fzgx_pool_170.v,((const f32 *)lbl_1_rodata_92C0)[66],fzgx_pool_174.v);
  fn_800737E4((void *)&loc_D4,1);
  q=&lbl_1_data_1E5C0;
  loc_A0=*q;
  *(f32 *)&loc_A0.unk_C=fzgx_pool_178.v;
  *(f32 *)&loc_A0.unk_10=fzgx_pool_17C.v;
  *(f32 *)&loc_A0.unk_14=fzgx_pool_180.v;
  fn_1_F7870((u32)&loc_A0);
  fn_1_149CA4(48,69,180,270);
  lbl_8006D7F4(fn_1_520F8(138),fzgx_pool_184.v,fzgx_pool_188.v);
  lbl_8006E14C(fzgx_pool_18C.v);
  { f32 t34=fn_1_521B8(1); lbl_8006E15C(t34,fzgx_pool_190.v,fzgx_pool_190.v); }
  mathutil_mtxA_rotate_z(32768); mathutil_mtxA_rotate_x(-16384);
  fn_80072558(); fn_80074918(1,3,0);
  fn_1_151BDC(fn_1_8472C(*(Sig_fn_1_8472C_Fn18472CObject **)(v2+812)));
  fn_1_870BC((void *)v2,t24,(void *)v2,0,*(s16 *)(v2+952),fzgx_pool_190.v);
  fn_80074188(loc_18,loc_14,loc_10,loc_C);
  fn_80072270(&loc_2C);
 }
 { s16 rawLevel = *(s16 *)(v2+952);
 if(rawLevel<0) level=0; else { level=3; if(rawLevel<=3) level=rawLevel; }
 }
 packet=lbl_1_rodata_26F8;
 packet.a[0]=(s16)level|(*(u32 *)(lbl_1_data_1A2B4+v8)<<8);
 *(f32 *)&packet.a[1]=(f32)(s32)(arg0+96);
 *(f32 *)&packet.a[2]=(f32)(s32)(arg1+11);
 *(f32 *)&packet.a[3]=fzgx_pool_194.v;
 *(f32 *)&packet.a[11]=fzgx_pool_190.v;
 packet.a[12]=6;
 fn_1_4F734(&packet);
}
/* fzgx:end fn_1_14267C */

/* fzgx:begin fn_1_142BDC noprologue */
#include "types.h"
#include "font.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 1.0f;
}
static const u32 fzgx_pool_table3[61] = {0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 0.9583333134651184f;
    s = 23.0f;
    s = 2.0f;
    s = 0.6666666865348816f;
    s = 0.5f;
    s = 0.5833333134651184f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 596.0f;
    s = 528.0f;
}
static const u32 fzgx_pool_table7[11] = {0x0000001A, 0x00000023, 0x0000009C, 0x000000A5, 0x00000018, 0x00000021, 0x00000085, 0x0000008E, 0x000000F2, 0x000000FB, 0xC0C0C000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -4.0f;
    s = 40.0f;
    s = 480.0f;
    s = 640.0f;
    s = 90000.0f;
    s = 0.30000001192092896f;
    s = 0.699999988079071f;
    s = -1.0f;
    s = 208.0f;
    s = -1000.0f;
    s = -50.0f;
}
static const u32 fzgx_pool_table9[1] = {0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10.0f;
    s = 140.0f;
    s = 224.0f;
    s = 254.0f;
    s = 256.0f;
    s = -6.0f;
    s = 5.0f;
    s = 4.0f;
    s = 12.0f;
}
#pragma section code_type ".text"

struct fn_1_142BDC_Copy88 { u32 a[22]; };
struct fn_1_142BDC_lbl_1_rodata_92C0 {
    u8 pad_0[0x108];
    f32 unk_108;
    u8 pad_10C[0x1C];
    f64 unk_128;
    u8 pad_130[0x68];
    f32 unk_198;
    f32 unk_19C;
    f32 unk_1A0;
    f32 unk_1A4;
    f32 unk_1A8;
    f32 unk_1AC;
    f32 unk_1B0;
};
struct fn_1_142BDC_lbl_1_bss_3C30 {
    u8 pad_0[0x5];
    u8 unk_5;
};

extern f32 fn_1_4B068(s32);
extern int fn_1_4F734(FontDrawPacket *);
extern int sprintf(char *, const char *, ...);
extern struct fn_1_142BDC_lbl_1_bss_3C30 lbl_1_bss_3C30;
extern struct fn_1_142BDC_lbl_1_rodata_92C0 lbl_1_rodata_92C0;
extern u32 lbl_1_data_42488;
extern u32 lbl_1_rodata_26F8;
extern s32 fn_1_149FB4(s32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(void *);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);

void fn_1_142BDC(u32 arg0, u32 arg1, u32 arg2) {
    struct fn_1_142BDC_lbl_1_rodata_92C0 *p_lbl_1_rodata_92C0;
    u32 v0;
    f32 v1;
    u32 v2;
    f32 v3;
    u32 v4;
    f32 v5;
    u32 v6 = arg0;
    u32 arg0_local = arg0;
    s32 v7;
    u32 v8;
    s32 v9;
    s32 v10;
    s32 v13;
    s32 v12;
    s32 v15;
    u32 v18;
    u32 v23;
    f32 v25;
    u32 v36;
    f32 v39;
    f32 v40;
    f32 v41;
    FontDrawPacket loc_18;
    struct { u32 a[4]; } loc_8;
    /* frame */
    s32 t0;
    f32 t27;

    p_lbl_1_rodata_92C0 = (struct fn_1_142BDC_lbl_1_rodata_92C0 *)&lbl_1_rodata_92C0;
    t0 = fn_1_149FB4(arg2);
    if (t0 != -1) {
        if (lbl_1_bss_3C30.unk_5 == 2) {
            if (t0 == 0) {
                loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
                v0 = 0x9730;
                loc_18.flags = 6;
                loc_18.image = v0;
                fn_1_51678(&loc_18, v0, 0, 0, 116, 32);
                v1 = (140.0f);
                loc_18.x = v1;
                loc_18.y = (224.0f);
                fn_1_4F734(&loc_18);
                loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
                v2 = 0x9730;
                loc_18.flags = 6;
                loc_18.image = v2;
                fn_1_51678(&loc_18, v2, 0, 32, 160, 32);
                v3 = (140.0f);
                loc_18.x = v3;
                loc_18.y = (254.0f);
                fn_1_4F734(&loc_18);
            } else {
                loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
                v4 = 0x9730;
                loc_18.flags = 6;
                loc_18.image = v4;
                fn_1_51678(&loc_18, v4, 0, 64, 160, 32);
                v5 = (140.0f);
                loc_18.x = v5;
                loc_18.y = (256.0f);
                fn_1_4F734(&loc_18);
            }
            v6 = arg0_local + 70;
            v7 = arg1 - 3;
            fn_1_49410();
            fn_1_494DC(19);
            fn_1_4966C((-6.0f), (0.0f));
            fn_1_4954C((5.0f));
            fn_1_495C8((void *)2);
            fn_1_496FC((f32)(s32)v6, (f32)(s32)v7);
            sprintf((char *)&loc_8, (const char *)&lbl_1_data_42488, (t0 + 1));
            fn_1_4A0D8((const char *)&loc_8);
            v9 = t0 + 1;
            v13 = 0;
            v12 = v9 % 100;
            if (v12 >= 10 && v9 % 100 <= 20) {
                v13 = 1;
            }
            if (v13 != 0) {
                v15 = 3;
            } else {
                v13 = 0;
                if ((v12 % 10) >= 4 || (v12 % 10) == 0) {
                    v13 = 1;
                }
                if (v13 != 0) {
                    v15 = 3;
                } else {
                    v2 = (v12 % 10) - 1;
                    v15 = v2;
                }
            }
            v18 = (v15 & 0xFF);
            loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            loc_18.image = 0x9705;
            fn_1_51564(0, 0, 24, 24, 2, 2);
            v40 = (f32)(s32)(v6 - 4);
            v41 = (f32)(s32)(v7 + 8);
            loc_18.x = v40;
            loc_18.y = v41;
            loc_18.z = (5.0f);
            fn_1_5158C((FontDrawPacket *)&loc_18, loc_18.image,
                       (s16)((s32)v18 % 2),
                       (s16)((v18 >> 1) & 0x7F));
            fn_1_4F734((FontDrawPacket *)&loc_18);
            loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            v23 = 0x9730;
            loc_18.image = v23;
            fn_1_51678((FontDrawPacket *)&loc_18, v23, 116, 0, 44, 32);
            v25 = (f32)(s32)(v6 + 26);
            loc_18.x = v25;
            loc_18.y = (f32)(s32)(v7 + 6);
            fn_1_4F734((FontDrawPacket *)&loc_18);
        } else {
            fn_1_49410();
            fn_1_494DC(19);
            fn_1_4966C((-6.0f), (0.0f));
            fn_1_4954C((5.0f));
            fn_1_496FC((f32)(s32)arg0_local, (f32)(s32)arg1);
            sprintf((char *)&loc_8, (const char *)&lbl_1_data_42488, (t0 + 1));
            fn_1_4A0D8((const char *)&loc_8);
            t27 = fn_1_4B068((s32)&loc_8);
            v9 = t0 + 1;
            v12 = v9 % 100;
            v13 = 0;
            if (v12 >= 10 && v9 % 100 <= 20) {
                v13 = 1;
            }
            if (v13 != 0) {
                v15 = 3;
            } else {
                v13 = 0;
                if ((v12 % 10) >= 4 || (v12 % 10) == 0) {
                    v13 = 1;
                }
                if (v13 != 0) {
                    v15 = 3;
                } else {
                    v15 = (v12 % 10) - 1;
                }
            }
            v36 = (v15 & 0xFF);
            loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            loc_18.image = 0x9705;
            fn_1_51564(0, 0, 24, 24, 2, 2);
            loc_18.x = (f32)(s32)v6 + t27 - 4.0f;
            loc_18.y = (f32)(s32)(arg1 + 7);
            loc_18.z = 5.0f;
            fn_1_5158C((FontDrawPacket *)&loc_18, loc_18.image,
                       (s16)((s32)v36 % 2),
                       (s16)((v36 >> 1) & 0x7F));
            fn_1_4F734((FontDrawPacket *)&loc_18);
        }
    }
}
/* fzgx:end fn_1_142BDC */

/* fzgx:begin fn_1_14328C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"
#include "types.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern Word8 lbl_1_rodata_86D8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern f32 lbl_1_rodata_26F8[22];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern u16 fn_1_486C4(u32 value);
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_88B4;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_88B8;
extern const u32 lbl_1_rodata_8860[6];
extern const u32 lbl_1_rodata_8878[6];
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_48690(u32 unused);
extern void fn_1_52070(u32 value);
extern void fn_1_135D7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_4965C(u8 value);
extern void fn_1_495C8(void* arg0);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 value);
extern void fn_1_49590(f32 value);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A28;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern s32 lbl_1_rodata_8A34;
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_5233C(void* arg0, void* arg1);
extern u32 fn_1_12F118(void);
extern u8* fn_1_36AD0();
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_137364();
extern void fn_1_14E9E4(int arg0, void *arg1);
extern const f32 lbl_1_rodata_8840;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_85F4;
extern int fn_1_D6698(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern void fn_1_139440(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
extern s32 lbl_1_bss_8E3D0[];
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_8BA8;
extern const f32 lbl_1_rodata_8664;
extern const f32 lbl_1_rodata_8BAC;
extern const f32 lbl_1_rodata_8BB0;
extern const f32 lbl_1_rodata_8BB4;
extern const f32 lbl_1_rodata_87D0;
extern int fn_1_D6740();
extern int fn_1_D66B0(void);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern u8 lbl_1_rodata_8558[84];
extern const f32 lbl_1_rodata_8C10;
extern void fn_1_4CF3C(const char *format, f32 x, ...);
extern s16 fn_1_12C930(void* arg0);
extern u8 lbl_1_data_21078[180];
extern f32 fn_1_4B068(const char*);
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8C74;
extern PtrTab lbl_1_rodata_8C4C;
extern s32 fn_1_13B548(s32, s32, s32, u8);
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8D78;
extern const f32 lbl_1_rodata_8D7C;
extern u16 lbl_1_rodata_8CB0[200];
extern u8 lbl_1_bss_9C;
extern void fn_1_133E04(void* arg0, s32 arg1);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_140EE8(u8 arg0, int arg1, int arg2);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern void fn_1_138144(void* arg0, int arg1);
extern u32 fn_1_13C5EC(u8);
extern u32 fn_1_13F7F8(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8DBC;
extern const f32 lbl_1_rodata_8DCC;
extern const f32 lbl_1_rodata_87B4;
extern const u32 lbl_1_rodata_8DC0;
extern const f32 lbl_1_rodata_8818;
extern const u32 lbl_1_rodata_8DC4;
extern const f32 lbl_1_rodata_8DD0;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8A58;
extern int fn_1_B7E98(int index);
extern void fn_1_13EE60();
extern u32 fn_1_13EF64(u32, u32, u32, void *, u32, void *, u32, f32);
extern u32 lbl_1_rodata_8E8C;
extern u8 lbl_1_rodata_8EB4[];
extern char *fn_80083DB0(char *dst, const char *src);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 lbl_1_rodata_91C0[11];
extern const f32 lbl_1_rodata_91EC;
extern const f32 lbl_1_rodata_91F0;
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern void fn_1_494DC(s16 index);
extern const f32 lbl_1_rodata_9208;
extern void fn_1_4966C(f32 value1, f32 value2);
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern const f32 lbl_1_rodata_8E9C;
extern const f64 lbl_1_rodata_93E8;
extern f32 lbl_1_rodata_93F0[15];
extern f32 lbl_1_rodata_92C0[22];
extern f32 lbl_1_rodata_970C[71];
extern const f32 lbl_1_rodata_946C;
extern void fn_1_149C2C();
extern struct fn_1_149C64_lbl_1_bss_8E43C lbl_1_bss_8E43C;
extern struct fn_1_149C64_lbl_1_bss_8E440 lbl_1_bss_8E440;
extern void fn_1_149CA4(u32, u32, u32, u32);
extern void fn_1_520A0(void);
extern f64 lbl_1_rodata_9480[80];
extern f32 lbl_1_rodata_942C[16];
extern f32 fn_1_521B8(s32 value);
extern f32 fn_1_520F8(s32 value);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_1_520CC(void);
extern const f32 lbl_1_rodata_99A4;
extern u8 fn_1_5910(void);
extern u8 fn_1_149FB4(s32 index);
extern s32 fn_1_3F864(void);
extern void fn_1_A52B0(s32 index);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 fn_1_1556B4(u32, u32);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0();
extern s16 fn_1_14F344(s16);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void fn_1_151C3C(u16 value1, u16 value2);
extern void fn_1_556B8(void *value);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern const f64 lbl_1_rodata_B8D0;
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *fn_800839D8(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_1375C0(int arg0, void* arg1, void* arg2, void* arg3, void* arg4);
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern void fn_1_131B90(void);
extern void fn_1_13A9B8();
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void fn_1_13E080(void* arg0, void* arg1, void* arg2, int arg3);
extern void fn_1_144F40(u32 arg0, u32 arg1);
extern u8 fn_1_155F8C(void);
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, u32 arg3);
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);
extern s32 fn_1_45D0();
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 fn_80008BEC(u32 arg0, int arg1, int arg2);
extern void fn_1_7F3AC(void* object);


struct fn_1_14328C_Copy88 { u32 a[22]; };
struct fn_1_14328C_lbl_1_bss_26B04 {
    u8 unk_0[1];
};

extern u8 lbl_1_bss_26B04[20];
extern f32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_9474;
extern const f32 lbl_1_rodata_9478;
extern u16 fn_1_48690(u32);
extern int fn_1_4F734(FontDrawPacket *);

void fn_1_14328C(u32 arg0, u32 arg1, u32 arg2) {
    s32 v0;
    s32 v5;
    s32 j;
    s32 i;
    s32 v6;
    struct fn_1_14328C_Copy88 packet;
    v0 = lbl_1_bss_26B04[arg2];
    v6 = v0 % 10;
    v5 = v0 / 10;
    packet = *(struct fn_1_14328C_Copy88 *)lbl_1_rodata_26F8;
    *(f32 *)&packet.a[2] = (f32)(s32)arg1;
    if (v6 >= 6) {
        for (i = 6; i <= v6; i++) {
            packet = *(struct fn_1_14328C_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 0x9713;
            *(f32 *)&packet.a[1] = (f32)(s32)arg0 - (f32)((f32)((i - 1) % 5) * lbl_1_rodata_9474);
            *(f32 *)&packet.a[2] = (f32)(s32)arg1;
            packet.a[12] = 15;
            *(f32 *)&packet.a[4] *= lbl_1_rodata_9474 / (f32)fn_1_48690(packet.a[0]);
            *(f32 *)&packet.a[5] *= lbl_1_rodata_9474 / (f32)fn_1_48690(packet.a[0]);
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        arg1 = (s32)((f32)(s32)arg1 - lbl_1_rodata_9478);
    }
    if (v6 >= 1) {
        for (j = 1; j <= v6; j++) {
            packet = *(struct fn_1_14328C_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 0x9713;
            *(f32 *)&packet.a[1] = (f32)(s32)arg0 - (f32)((f32)((j - 1) % 5) * lbl_1_rodata_9474);
            *(f32 *)&packet.a[2] = (f32)(s32)arg1;
            packet.a[12] = 15;
            *(f32 *)&packet.a[4] *= lbl_1_rodata_9474 / (f32)fn_1_48690(packet.a[0]);
            *(f32 *)&packet.a[5] *= lbl_1_rodata_9474 / (f32)fn_1_48690(packet.a[0]);
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        arg1 = (s32)((f32)(s32)arg1 - lbl_1_rodata_9478);
    }
    if (v5 >= 1) {
        for (i = 0; i < v5; i++) {
            packet = *(struct fn_1_14328C_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 0x9712;
            *(f32 *)&packet.a[1] = (f32)((s32)arg0 - i * 12);
            *(f32 *)&packet.a[2] = (f32)(s32)arg1;
            packet.a[12] = 15;
            *(f32 *)&packet.a[4] *= lbl_1_rodata_9474 / (f32)fn_1_48690(packet.a[0]);
            *(f32 *)&packet.a[5] *= lbl_1_rodata_9474 / (f32)fn_1_48690(packet.a[0]);
            fn_1_4F734((FontDrawPacket *)&packet);
        }
    }
}
/* fzgx:end fn_1_14328C */

/* fzgx:begin fn_1_143780 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

struct fn_1_143780_lbl_801A66A4 { s32 unk_0; };
struct fn_1_143780_entry { u32 unk_0; f32 unk_4; u8 unk_8, unk_9; u16 unk_A; };
struct fn_1_143780_view { u8 pad_0[0x16C]; struct fn_1_143780_entry entries[10]; };

typedef struct fn_1_143780_Color { u8 c[4]; } Color;
extern f32 lbl_8006D188(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_1_143780_lbl_801A66A4 lbl_801A66A4;
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern u32 fn_1_144A5C(void *);
extern f32 lbl_1_rodata_26F8[22];
extern u8 fn_1_3F114(void);
extern void fn_1_143E7C(u32, u32, u32, u32, u32, u32, void *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_49514(u32 *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);

#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_a(void) {
    struct { u32 a[66]; } p = {{0,0,0,0x3dcccccd,0x3f800000,0x3f800000,0,0,0x3f800000,0x3f800000,0,0x3f800000,0x04000000,0,0xffffffff,0,0,0,0,0,0,0,0,0,0,0x3dcccccd,0x3f800000,0x3f800000,0,0,0x3f800000,0x3f800000,0,0x3f800000,0x04000000,0,0xffffffff,0,0,0,0,0,0,0,0,0,0,0x3dcccccd,0x3f800000,0x3f800000,0,0,0x3f800000,0x3f800000,0,0x3f800000,0x04000000,0,0xffffffff,0,0,0,0,0,0,0}};
    volatile f32 f; /* Preserve literal-pool primer order. */
    volatile f64 d; /* Preserve conversion constants in the pool. */
    fn_1_144A5C(&p);
    f = 0.0f;
    f = 0.9583333134651184f;
    f = 23.0f;
    f = 2.0f;
    f = 0.6666666865348816f;
    f = 0.5f;
    f = 0.5833333134651184f;
    d = 4503601774854144.0;
    f = 596.0f;
    f = 528.0f;
}
static void fzgx_pool_primer_b(void) {
    struct { u32 a[11]; } p = {{0x1a,0x23,0x9c,0xa5,0x18,0x21,0x85,0x8e,0xf2,0xfb,3233857536U /* RGBA */}};
    volatile f32 f; /* Preserve literal-pool primer order. */
    volatile f64 d; /* Preserve conversion constants in the pool. */
    fn_1_144A5C(&p);
    f = -4.0f;
    f = 40.0f;
    f = 480.0f;
    f = 640.0f;
    f = 90000.0f;
    f = 0.3f;
    f = 0.7f;
    f = -1.0f;
    f = 208.0f;
    f = -1000.0f;
    f = -50.0f;
    f = 1.0f;
    f = 10.0f;
    f = 140.0f;
    f = 224.0f;
    f = 254.0f;
    f = 256.0f;
    f = -6.0f;
    f = 5.0f;
    f = 4.0f;
    f = 12.0f;
    f = 15.0f;
    d = 4503599627370496.0;
}
static void fzgx_pool_primer_c(void) {
    struct { u32 a[4]; } p = {{0x4e4f204e,0x414d4500,0x4e4f2044,0x41544100}};
    volatile f32 f; /* Preserve literal-pool primer order. */
    fn_1_144A5C(&p);
    f = 100.0f;
    f = 350.0f;
    f = 44.0f;
    f = 8.0f;
}
#pragma section code_type ".text"

static inline void draw_color(u32 a,u32 b,u32 c,u32 d,u32 e,u32 f,Color color) {
    fn_1_143E7C(a,b,c,d,e,f,&color);
}
static inline void set_color(Color color) {
    fn_1_49514((u32 *)&color);
}
static inline void blend_color(FontDrawPacket *out, u32 a0, u32 b0, u32 a1, u32 b1, u32 a2, u32 b2, f32 sn) {
    f32 one = 1.0f;
    f32 t = (one + sn) / 2.0f;
    out->color[0] = (s32)((f32)((f32)a0 * (one - t)) + (f32)((f32)b0 * t));
    out->color[1] = (s32)((f32)((f32)a1 * (one - t)) + (f32)((f32)b1 * t));
    out->color[2] = (s32)((f32)((f32)a2 * (one - t)) + (f32)((f32)b2 * t));
    out->alpha = 0.35f;
}

#pragma opt_common_subs on
#pragma opt_loop_invariants off
void fn_1_143780(u32 arg0, u32 arg1, u32 arg2) {
    u32 count;
    u32 y1;
    u32 y0;
    s32 last;
    struct fn_1_143780_entry *cur;
    s32 i;
    Obj_1_bss_26314 *obj;
    struct fn_1_143780_entry *e;
    u32 image;
    f32 scale;
    s32 frame;
    s32 rem;
    u32 a0, b0, a1, b1, a2, b2;
    f32 sn;
    f32 one;
    f32 t;
    f32 u;
    Color loc_40;
    Color loc_3C;
    Color loc_38;
    Color loc_34;
    Color loc_30;
    Color loc_2C;
    Color loc_28;
    Color loc_24;
    Color loc_10;
    Color loc_C;
    Color loc_8;
    struct { u32 a[10]; } loc_6C;
    FontDrawPacket loc_94;
    loc_10 = (Color){{255,255,255,255}};
    loc_40 = loc_2C = loc_10;
    loc_C = (Color){{0,240,230,255}};
    loc_3C = loc_28 = loc_C;
    loc_38 = (Color){{0,120,115,255}};
    loc_8 = (Color){{160,255,0,255}};
    loc_34 = loc_24 = loc_8;
    {
    struct { u32 a[4]; } loc_44 = {{26, 35, 316, 325}};
    struct { u32 a[6]; } loc_54 = {{24, 33, 101, 110, 178, 187}};
    loc_6C.a[0] = arg0;
    loc_6C.a[1] = arg1;
    loc_6C.a[2] = 354;
    loc_6C.a[3] = 222;
    loc_6C.a[4] = 340;
    loc_6C.a[5] = 208;
    loc_6C.a[6] = (u32)&loc_44;
    loc_6C.a[7] = 4;
    loc_6C.a[8] = (u32)&loc_54;
    loc_6C.a[9] = 6;
    fn_1_144A5C(&loc_6C);
    loc_94 = *(FontDrawPacket *)lbl_1_rodata_26F8;
    image = 0x9903;
    loc_94.image = image;
    fn_1_51678(&loc_94, image, 0, 108, 96, 36);
    loc_94.x = (f32)(s32)(arg0 + 22);
    loc_94.y = (f32)(s32)(arg1 + 179);
    loc_94.z = 30.0f;
    loc_94.scale_x *= 0.75f;
    loc_94.scale_y *= 0.75f;
    fn_1_4F734(&loc_94);
    obj = (Obj_1_bss_26314 *)((u8 *)&lbl_1_bss_26314 + arg2 * 508);
    count = fn_1_3F114() & 0xFF;
    if (count <= 5) {
        y1 = arg1 + 18;
        y0 = arg1 + 16;
        last = count - 1;
        for (i = 0; i < (s32)count; i++) {
            if (i < 5) {
                e = &((struct fn_1_143780_view *)obj)->entries[last - i];
                if (e->unk_0 == obj->unk_1CC && e->unk_4 == obj->unk_1D0) {
                    loc_30 = loc_34;
                } else {
                    loc_30 = loc_40;
                }
                draw_color(arg0 + 332, y1, arg2, e->unk_8, e->unk_9, e->unk_A, loc_30);
                loc_94 = *(FontDrawPacket *)lbl_1_rodata_26F8;
                image = 0x9903;
                loc_94.image = image;
                fn_1_51678(&loc_94, image, 0, 36, 96, 36);
                loc_94.x = (f32)((s32)arg0 + 22);
                loc_94.y = (f32)(s32)y0;
                loc_94.z = 30.0f;
                loc_94.scale_x *= 0.75f;
                loc_94.scale_y *= 0.75f;
                *(Color *)loc_94.color = loc_30;
                fn_1_4F734(&loc_94);
                fn_1_49410();
                fn_1_494DC(19);
                fn_1_496FC((f32)(s32)(arg0 + 80), (f32)(s32)y1);
                set_color(loc_30);
                scale = 0.75f;
                fn_1_4955C(scale, scale);
                fn_1_4AE0C((const char *)lbl_1_data_424A0, i + 1);
            }
            y1 += 32;
            y0 += 32;
        }
    } else {
        cur = &((struct fn_1_143780_view *)obj)->entries[8];
        loc_94 = *(FontDrawPacket *)lbl_1_rodata_26F8;
        image = 0x9900;
        loc_94.image = image;
        loc_94.x = (f32)((s32)arg0 + 22);
        loc_94.y = (f32)((s32)arg1 + 7);
        loc_94.z = 30.0f;
        fn_1_4F734(&loc_94);
        draw_color(arg0 + 332, arg1 + 18, arg2, cur->unk_8, cur->unk_9, cur->unk_A, loc_24);
    }
    e = (struct fn_1_143780_entry *)((u32)obj + 0x1d8);
    draw_color(arg0 + 332, arg1 + 179, arg2, e->unk_8, e->unk_9, e->unk_A, loc_2C);
    loc_94 = *(FontDrawPacket *)lbl_1_rodata_26F8;
    loc_94.image = 18;
    loc_94.x = (f32)((s32)arg0 + 1);
    loc_94.y = (f32)((s32)arg1 + 176);
    loc_94.z = 54.0f;
    *(Color *)loc_94.color = loc_28;
    loc_94.scale_x *= 343.0f / (f32)fn_1_48690(18);
    loc_94.scale_y *= 30.0f / (f32)fn_1_486C4((u32)loc_94.image);
    frame = lbl_801A66A4.unk_0;
    scale = 65536.0f;
    rem = frame % 120;
    scale = (f32)(scale * (f32)rem);
    one = 1.0f;
    t = (one + lbl_8006D188((s32)(f32)(scale / 120.0f))) / 2.0f;
    loc_94.color[0] = (f32)((f32)loc_3C.c[0] * (one - t)) + (f32)((f32)loc_38.c[0] * t);
    loc_94.color[1] = (f32)((f32)loc_3C.c[1] * (one - t)) + (f32)((f32)loc_38.c[1] * t);
    loc_94.color[2] = (f32)((f32)loc_3C.c[2] * (one - t)) + (f32)((f32)loc_38.c[2] * t);
    loc_94.alpha = 0.35f;
    fn_1_4F734(&loc_94);
    }
}
/* fzgx:end fn_1_143780 */

/* fzgx:begin fn_1_143E7C noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 1.0f;
}
static const u32 fzgx_pool_table3[61] = {0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 0.9583333134651184f;
    s = 23.0f;
    s = 2.0f;
    s = 0.6666666865348816f;
    s = 0.5f;
    s = 0.5833333134651184f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 596.0f;
    s = 528.0f;
}
static const u32 fzgx_pool_table7[11] = {0x0000001A, 0x00000023, 0x0000009C, 0x000000A5, 0x00000018, 0x00000021, 0x00000085, 0x0000008E, 0x000000F2, 0x000000FB, 0xC0C0C000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -4.0f;
    s = 40.0f;
    s = 480.0f;
    s = 640.0f;
    s = 90000.0f;
    s = 0.30000001192092896f;
    s = 0.699999988079071f;
    s = -1.0f;
    s = 208.0f;
    s = -1000.0f;
    s = -50.0f;
}
static const u32 fzgx_pool_table9[1] = {0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10.0f;
    s = 140.0f;
    s = 224.0f;
    s = 254.0f;
    s = 256.0f;
    s = -6.0f;
    s = 5.0f;
    s = 4.0f;
    s = 12.0f;
    s = 15.0f;
}
static const u32 fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table13[1] = {0x4E4F204E};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.829345703125f;
}
static const u32 fzgx_pool_table15[1] = {0x4E4F2044};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 13.265869140625f;
    s = 100.0f;
    s = 350.0f;
    s = 44.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table17[14] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    s = 0.75f;
    s = 54.0f;
    s = 343.0f;
    s = 65536.0f;
    s = 120.0f;
    s = 0.3499999940395355f;
}
static const u32 fzgx_pool_table19[25] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.748046875f;
}
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
}
static const u32 fzgx_pool_table23[14] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = -2.0f;
}
static const u32 fzgx_pool_table25[1] = {0x0000001A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern void fn_1_49410(void);
extern void fn_1_494DC(int arg0);
extern void fn_1_495B0(u32 arg0);
extern void fn_1_495C8(int arg0);
extern void fn_1_49514(void* arg0);
extern void fn_1_4966C(f32 arg0, f32 arg1);
extern void fn_1_4955C(f32 arg0, f32 arg1);
extern void fn_1_496FC(f32 arg0, f32 arg1);
extern u8 lbl_1_data_424AC[32];
extern void fn_1_4AE0C(u8* arg0, ...);

void fn_1_143E7C(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, void* arg6) {
    u32 local;
    f32 value;

    fn_1_49410();
    fn_1_494DC(0x13);
    fn_1_495B0((u32)0x8000 << 16);
    fn_1_495C8(2);
    local = *(u32*)arg6;
    fn_1_49514(&local);
    fn_1_4966C(-2.0f, 0.0f);
    value = 0.75f;
    fn_1_4955C(value, value);
    fn_1_496FC((f32)(s32)arg0, (f32)(s32)arg1);
    fn_1_4AE0C(lbl_1_data_424AC, arg3 & 0xFF, arg4 & 0xFF, arg5 & 0xFFFF);
}
/* fzgx:end fn_1_143E7C */

/* fzgx:begin fn_1_143F5C noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 1.0f;
}
static const u32 fzgx_pool_table3[61] = {0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 0.9583333134651184f;
    s = 23.0f;
    s = 2.0f;
    s = 0.6666666865348816f;
    s = 0.5f;
    s = 0.5833333134651184f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 596.0f;
    s = 528.0f;
}
static const u32 fzgx_pool_table7[11] = {0x0000001A, 0x00000023, 0x0000009C, 0x000000A5, 0x00000018, 0x00000021, 0x00000085, 0x0000008E, 0x000000F2, 0x000000FB, 0xC0C0C000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -4.0f;
    s = 40.0f;
    s = 480.0f;
    s = 640.0f;
    s = 90000.0f;
    s = 0.30000001192092896f;
    s = 0.699999988079071f;
    s = -1.0f;
    s = 208.0f;
    s = -1000.0f;
    s = -50.0f;
}
static const u32 fzgx_pool_table9[1] = {0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10.0f;
    s = 140.0f;
    s = 224.0f;
    s = 254.0f;
    s = 256.0f;
    s = -6.0f;
    s = 5.0f;
    s = 4.0f;
    s = 12.0f;
    s = 15.0f;
}
static const u32 fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table13[1] = {0x4E4F204E};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.829345703125f;
}
static const u32 fzgx_pool_table15[1] = {0x4E4F2044};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 13.265869140625f;
    s = 100.0f;
    s = 350.0f;
    s = 44.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table17[14] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    s = 0.75f;
    s = 54.0f;
    s = 343.0f;
    s = 65536.0f;
    s = 120.0f;
    s = 0.3499999940395355f;
}
static const u32 fzgx_pool_table19[25] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.748046875f;
}
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
}
static const u32 fzgx_pool_table23[14] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = -2.0f;
}
#pragma section code_type ".text"

typedef struct fn_1_143F5C_Args {
    s32 x;
    s32 y;
    s32 w0;
    s32 h0;
    s32 w1;
    s32 h1;
    u32 *list0;
    s32 count0;
    u32 *list1;
    s32 count1;
} fn_1_143F5C_Args;

extern FontDrawPacket lbl_1_rodata_26F8;
extern f32 lbl_1_bss_26304[4];
extern u32 fn_1_144A5C(fn_1_143F5C_Args *args);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16 index);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(u8 value);
extern u16 fn_1_48690(u32 id);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_49514(u32 *value);
extern void fn_1_4955C(f32 value1, f32 value2);

void fn_1_143F5C(s32 x, s32 y, s32 idx) {
    u8 color[4];
    u32 colorCopy;
    u32 list0[4] = {0x1a, 0x23, 0x13c, 0x145};
    u32 list1[2] = {0x18, 0x21};
    fn_1_143F5C_Args args;
    FontDrawPacket packet;
    u16 width;

    args.x = x;
    args.y = y;
    args.w0 = 0x162;
    args.h0 = 0x34;
    args.w1 = 0x154;
    args.h1 = 0x2a;
    args.list0 = list0;
    args.count0 = 4;
    args.list1 = list1;
    args.count1 = 2;
    fn_1_144A5C(&args);

    color[0] = 0xa0;
    color[1] = 0xff;
    color[2] = 0;
    color[3] = 0xff;

    packet = lbl_1_rodata_26F8;
    packet.image = 0x9903;
    fn_1_51678(&packet, 0x9903, 0, 0x90, 0x60, 0x24);
    packet.x = (f32)(x + 0x1a);
    packet.y = (f32)(y + 0xe);
    packet.z = 30.0f;
    packet.scale_x *= 0.75f;
    packet.scale_y *= 0.75f;
    fn_1_4F734(&packet);

    fn_1_49410();
    fn_1_494DC(0x13);
    fn_1_495B0(0x80000000);
    fn_1_495C8(2);
    fn_1_496FC((f32)(x + 0x14c - fn_1_48690(0x9904)), (f32)(y + 0x10));
    colorCopy = *(u32 *)color;
    fn_1_49514(&colorCopy);
    fn_1_4955C(0.75f, 0.75f);
    fn_1_4AE0C((const char *)&lbl_1_data_424CC, (s32)lbl_1_bss_26304[idx]);

    packet = lbl_1_rodata_26F8;
    packet.image = 0x9904;
    packet.x = (f32)(x + 0x14c);
    packet.y = (f32)(y + 0x17);
    packet.z = 30.0f;
    packet.flags = 7;
    packet.scale_x *= 0.75f;
    packet.scale_y *= 0.75f;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_143F5C */

/* fzgx:begin fn_1_144E90 */
void fn_1_144E90(void) {
    lbl_1_bss_8E428.unk_0 = (u32)&lbl_1_bss_3C30.unk_E;
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(0, 0);
    }
}
/* fzgx:end fn_1_144E90 */

/* fzgx:begin fn_1_144EE8 */
void fn_1_144EE8(void) {
    lbl_1_bss_8E428.unk_0 = (u32)((u8*)&lbl_1_bss_3C30 + 0x1394);
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(1, 0);
    }
}
/* fzgx:end fn_1_144EE8 */

/* fzgx:begin fn_1_145B58 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern u32 fn_1_155F7C(void);
extern u32 fn_1_155F8C(void);

static inline s32 fn_1_145B58_test(s32 arg0, s32 range, s32 one) {
    s32 d, c, b, a;
    b = one; c = one; d = one; a = one;
    if (range == 0) a = 0;
    if (a == 0 && arg0 != 9) d = 0;
    if (d == 0 && arg0 != 10) c = 0;
    if (c == 0 && arg0 != 6) b = 0;
    return b;
}

u32 fn_1_145B58(s32 arg0, s32 *arg1) {
    u32 r;
    if (arg0 == 10 || arg0 == 6) {
        return arg1[8] == 0;
    }
    if (fn_1_145B58_test(arg0, (u32)(arg0 - 4) <= 1, 1) != 0) {
        r = 0;
        if ((s32)fn_1_155F7C() != 0) {
            if (arg1[8] == (s32)fn_1_155F8C()) {
                r = 1;
            }
        }
        return r;
    }
    return (s32)lbl_1_bss_3C30.unk_8 > arg1[19];
}
/* fzgx:end fn_1_145B58 */

/* fzgx:begin fn_1_1461C8 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
}
static const unsigned long fzgx_pool_table3[62] = {0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 0.9583333134651184f;
    s = 23.0f;
    s = 2.0f;
    s = 0.6666666865348816f;
    s = 0.5f;
    s = 0.5833333134651184f;
}
static const unsigned long fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 596.0f;
    s = 528.0f;
}
static const unsigned long fzgx_pool_table7[11] = {0x0000001A, 0x00000023, 0x0000009C, 0x000000A5, 0x00000018, 0x00000021, 0x00000085, 0x0000008E, 0x000000F2, 0x000000FB, 0xC0C0C000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -4.0f;
    s = 40.0f;
    s = 480.0f;
    s = 640.0f;
    s = 90000.0f;
    s = 0.30000001192092896f;
    s = 0.699999988079071f;
    s = -1.0f;
    s = 208.0f;
    s = -1000.0f;
    s = -50.0f;
    s = 1.0f;
    s = 10.0f;
    s = 140.0f;
    s = 224.0f;
    s = 254.0f;
    s = 256.0f;
    s = -6.0f;
    s = 5.0f;
    s = 4.0f;
    s = 12.0f;
    s = 15.0f;
}
static const unsigned long fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table11[1] = {0x4E4F204E};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.829345703125f;
}
static const unsigned long fzgx_pool_table13[1] = {0x4E4F2044};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 13.265869140625f;
    s = 100.0f;
    s = 350.0f;
    s = 44.0f;
    s = 8.0f;
}
static const unsigned long fzgx_pool_table15[14] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const unsigned long *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    s = 0.75f;
    s = 54.0f;
    s = 343.0f;
    s = 65536.0f;
    s = 120.0f;
    s = 0.3499999940395355f;
}
static const unsigned long fzgx_pool_table17[25] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const unsigned long *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.748046875f;
}
static const unsigned long fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const unsigned long *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
}
static const unsigned long fzgx_pool_table21[14] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const unsigned long *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = -2.0f;
}
static const unsigned long fzgx_pool_table23[28] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0xFFFF00FF, 0x19FF1900, 0x00000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const unsigned long *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 68.0f;
    s = 86.0f;
    s = 0.375f;
    s = 80.0f;
    s = 14.0f;
    s = 21.0f;
    s = 1.100000023841858f;
    s = 399.0f;
    s = 574.0f;
    s = 0.8500000238418579f;
    s = 510.0f;
}
static const unsigned long fzgx_pool_table25[27] = {0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xFFFF00FF, 0x00000000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const unsigned long *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 354.0f;
    s = 84.0f;
    s = 22.0f;
    s = 0.6499999761581421f;
    s = 192.0f;
    s = 48.0f;
    s = 46.0f;
    s = 55.0f;
}
static const unsigned long fzgx_pool_table27[2] = {0xFADC82FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const unsigned long *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 639.0f;
    s = 479.0f;
    s = 320.0f;
    s = 70.0f;
    s = 112.0f;
    s = 492.0f;
    s = 33.0f;
    s = 19.0f;
    s = 24.0f;
    s = 50.0f;
    s = 29.0f;
    s = 72.0f;
}

/* TU string-literal pool (lbl_1_data_42198): the TU's earlier functions emit these literals and
 * two local aggregate initializers in this order, so the function's own literals land at +0x3E0. */
__declspec(section ".fzgxpool") static void fzgx_strings_prime1(void) {
    fn_1_4A0D8("NON");
    fn_1_4A0D8("MASTER RECV");
    fn_1_4A0D8("MASTER SEND");
    fn_1_4A0D8("SLAVE SEND");
    fn_1_4A0D8("SLAVE RECV");
    fn_1_4A0D8("INIT");
    fn_1_4A0D8("TEST");
    fn_1_4A0D8("TESTEND");
    fn_1_4A0D8("SETUP");
    fn_1_4A0D8("SETUP_DONE");
    fn_1_4A0D8("SETUP_COUNTER");
    fn_1_4A0D8("SETUP_CNT_DONE");
    fn_1_4A0D8("UNLINK");
    fn_1_4A0D8("COIN");
    fn_1_4A0D8("ENTRY_WAIT");
    fn_1_4A0D8("CHALLENGER");
    fn_1_4A0D8("CHALLENGER_OK");
    fn_1_4A0D8("ENTRY");
    fn_1_4A0D8("ENTRY_OK");
    fn_1_4A0D8("SINGLECHECK");
    fn_1_4A0D8("SINGLECHECK_OK");
    fn_1_4A0D8("COURSE");
    fn_1_4A0D8("COURSE_OK");
    fn_1_4A0D8("COURSE_DATA");
    fn_1_4A0D8("COURSE_DATA_OK");
    fn_1_4A0D8("MACHINE");
    fn_1_4A0D8("MACHINE_OK");
    fn_1_4A0D8("CONFIG");
    fn_1_4A0D8("CONFIG_OK");
    fn_1_4A0D8("COUNTERADJUST");
    fn_1_4A0D8("LINKWAIT");
    fn_1_4A0D8("LINKWAITOK");
    fn_1_4A0D8("LINKSEL");
    fn_1_4A0D8("LINKDELIVERYSTART");
    fn_1_4A0D8("LINKDELIVERY");
    fn_1_4A0D8("LINKDELIVERYOK");
    fn_1_4A0D8("LINKSELOK");
    fn_1_4A0D8("COURSEVIEW");
    fn_1_4A0D8("COURSEVIEW_OK");
    fn_1_4A0D8("LINKREQ");
    fn_1_4A0D8("LINKSTANDBY");
    fn_1_4A0D8("LINKOK");
    fn_1_4A0D8("LINK");
    fn_1_4A0D8("PAUSE");
    fn_1_4A0D8("ERROR");
}
extern void fn_1_1420E0(void);
extern void fn_1_144E90(void);
extern void fn_1_144EE8(void);
extern void fn_1_149E2C(void);
extern void fn_1_149F04(void);
extern void fn_1_149DA4(void);
extern void fn_1_149DE8(void);
extern void fn_1_149F5C(void);
extern void fn_1_14A000(void);
extern void fn_1_14A004(void);
extern void fn_1_14A008(void);
extern void fn_1_5233C(void *, void *);
/* two file-scope statics of the TU sit between the two literal groups (+0x200 and +0x2B4) */
static Obj_1_data_212A8 fzgx_pool_fzgx_data_zero_block = {0};
/* retail: a table of 11 handler pointers (fn_1_1420E0 ...); plain words keep the primer relocation-free */
static u32 fzgx_pool_fzgx_data_handlers[11] = {0};
__declspec(section ".fzgxpool") static void fzgx_strings_keep(void) { void *volatile p; p = &fzgx_pool_fzgx_data_zero_block; p = fzgx_pool_fzgx_data_handlers; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_strings_prime2(void) {
    fn_1_4A0D8("[");
    fn_1_4A0D8("]");
    fn_1_4A0D8("NAME:");
    fn_1_4A0D8("%d");
    fn_1_4A0D8("NAME");
    fn_1_4A0D8("PILOT RANK");
    fn_1_4A0D8("%1d");
    fn_1_4A0D8("%-2d");
    fn_1_4A0D8("%02d<%02d=%03d");
    fn_1_4A0D8("%02d;%02d<%03d");
    fn_1_4A0D8("%4d");
    fn_1_4A0D8("\203\101\203\103\203\213\203\147\203\223\201\100\203\132\203\151");
    fn_1_4A0D8("\202\140\201\104\203\140\203\106\203\125\203\212\203\130\201\100");
    fn_1_4A0D8("\203\154\203\213\203\134\203\223\201\100\203\163\203\120\201\100");
    fn_1_4A0D8("\203\101\203\211\203\223\201\100\203\166\203\215\203\130\203\147");
    fn_1_4A0D8("\203\175\203\130\203\136\201\133\203\211\203\103\203\132\203\223\203\130");
    fn_1_4A0D8("\202\122\202\121\213\211\203\211\203\103\203\132\203\223\203\130");
    fn_1_4A0D8("\203\160\203\103\203\215\203\142\203\147\214\363\225\342\220\266");
    fn_1_4A0D8("\202\162\202\162\213\211\203\211\203\103\203\132\203\223\203\130");
    fn_1_4A0D8("NO DATA");
}
#pragma section code_type ".text"

extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_49410(void);
extern void fn_1_494DC(s16 index);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_495C8(u8 value);
extern void fn_1_495B0(u32 value);
extern void fn_1_4954C(f32 value);
extern void fn_1_49590(f32 value);
extern void fn_1_4966C(f32 value1, f32 value2);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void *value);
extern void fn_1_49748(f32 value);
extern f32 fn_1_4B068(const char *);

#pragma opt_propagation off
void fn_1_1461C8(s32 mode, u32 index) {
    u8 idx;
    u8 pass;
    s32 width;
    s32 total;
    FontDrawPacket packet;
    s32 left;
    const char *text;

    total = 0;
    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x9909;
    packet.x = 320.0f;
    packet.y = 24.0f;
    packet.z = 50.0f;
    packet.flags = 6;
    fn_1_4F734(&packet);

    fn_1_49410();
    fn_1_494DC(0x1d);
    fn_1_496FC(320.0f, 29.0f);
    fn_1_495C8(1);
    fn_1_495B0(0x80000000);
    fn_1_4954C(40.0f);
    fn_1_49590(0.5f);
    switch (mode) {
    case 0:
        fn_1_4AE0C("RESULTS");
        break;
    case 1:
        fn_1_4AE0C("TOTAL RANKING");
        break;
    case 2:
        fn_1_4AE0C("VS RESULTS");
        break;
    case 3:
        fn_1_4AE0C("VS TOTAL RANKING");
        break;
    case 4:
    case 5:
    case 6:
        fn_1_4AE0C("TIME ATTACK");
        break;
    case 7:
        fn_1_4AE0C("PRACTICE");
        break;
    }

    idx = index;
    /* pass 0 measures the line, pass 1 draws it centred */
    for (pass = 0; pass <= 1; pass++) {
        left = (s32)(320.0f - (f32)(total / 2));
        width = 0;
        text = (const char *)((u32 *)lbl_1_data_2AA24)[((u8 *)&lbl_1_data_2B0D4)[idx]];
        fn_1_49410();
        fn_1_494DC(0x1e);
        fn_1_495B0(0x80000000);
        fn_1_4954C(40.0f);
        fn_1_495C8(8);
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 0.0f);
        if (pass) {
            fn_1_496FC((f32)left, 72.0f);
            fn_1_4A0D8(text);
        }
        width += fn_1_4B068(text);
        width += 10;

        text = (const char *)((u32 *)(lbl_1_data_2BD54 + idx * 0x18))[lbl_801A66B4];
        fn_1_49410();
        fn_1_494DC(0x2a);
        fn_1_4955C(0.5833333134651184f, 0.5833333134651184f);
        fn_1_495B0(0x80000000);
        fn_1_4954C(40.0f);
        fn_1_495C8(8);
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 0.0f);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(1.0f);
        if (pass) {
            fn_1_496FC((f32)(left + width), 72.0f);
            fn_1_4A0D8(text);
        }
        width = (s32)((f32)width + fn_1_4B068(text));
        total = width;
    }
}
/* fzgx:end fn_1_1461C8 */

/* fzgx:begin fn_1_146B5C */
#pragma opt_propagation off
void fn_1_146B5C(u32 unused, u8 *arg1) {
    s32 pos;
    s32 c;
    s32 b;
    s32 a;
    s32 v;
    FontDrawPacket pkt;

    fn_1_51564(0, 0, 0x24, 0x28, 0xa, 4);

    pkt = *(FontDrawPacket *)lbl_1_rodata_92C0;

    v = *(s32 *)(arg1 + 0x20);
    a = *(s32 *)(arg1 + 0x68);
    b = *(s32 *)(arg1 + 0x70);
    c = *(s32 *)(arg1 + 0x64);
    pos = a + b;

    pkt.image = 0x973E;
    pkt.x = (f32)(pos + 0x37);
    pkt.y = (f32)(c + 4);
    pkt.z = lbl_1_rodata_970C[0];

    fn_1_5158C(&pkt, 0x973E, (s16)(v % 10), (s16)(v / 10));
    fn_1_4F734(&pkt);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_146B5C */

/* fzgx:begin fn_1_147508 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

/* Raw retail literal-pool bits. Volatile stores keep the shared-pool literals emitted. */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table_0[71] = {
    0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD,
    0x3F800000, 0x3F800000, 0x00000000, 0x00000000,
    0x3F800000, 0x3F800000, 0x00000000, 0x3F800000,
    0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0 /* unused relocation addend */, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000,
    0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x00000000, 0x3F800000, 0x04000000, 0x00000000,
    0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0 /* unused relocation addend */, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD,
    0x3F800000, 0x3F800000, 0x00000000, 0x00000000,
    0x3F800000, 0x3F800000, 0x00000000, 0x3F800000,
    0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0 /* unused relocation addend */, 0x00000000, 0x00000000, 0x3F755555,
    0x41B80000, 0x40000000, 0x3F2AAAAB,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_11C(volatile f32 *out) { *out = 0.5f; }

static const u32 fzgx_pool_table_120[2] = {
    0x3F155555, 0x00000000,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_128(volatile f64 *out) { *out = 4503601774854144.0; }

static const u32 fzgx_pool_table_130[24] = {
    0x44150000, 0x44040000, 0x0000001A, 0x00000023,
    0x0000009C, 0x000000A5, 0x00000018, 0x00000021,
    0x00000085, 0x0000008E, 0x000000F2, 0x000000FB,
    3233857536U, 3229614080U, 0x42200000, 0x43F00000,
    0x44200000, 0x47AFC800, 0x3E99999A, 0x3F333333,
    0xBF800000, 0x43500000, 0xC47A0000, 0xC2480000,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_190(volatile f32 *out) { *out = 1.0f; }

static const u32 fzgx_pool_table_194[11] = {
    0x41200000, 0x430C0000, 0x43600000, 0x437E0000,
    0x43800000, 3233808384U, 0x40A00000, 0x40800000,
    0x41400000, 0x41700000, 0x00000000,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_1C0(volatile f64 *out) { *out = 4503599627370496.0; }

static const u32 fzgx_pool_table_1C8[26] = {
    0x4E4F204E, 0x414D4500, 0x4E4F2044, 0x41544100,
    0x42C80000, 0x43AF0000, 0x42300000, 0x41000000,
    0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF,
    0x0000001A, 0x00000023, 0x0000013C, 0x00000145,
    0x00000018, 0x00000021, 0x00000065, 0x0000006E,
    0x000000B2, 0x000000BB, 0x41F00000, 0x3F400000,
    0x42580000, 0x43AB8000,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_230(volatile f32 *out) { *out = 65536.0f; }

static const u32 fzgx_pool_table_234[117] = {
    0x42F00000, 0x3EB33333, 0xFFFFFFFF, 0x00F0E6FF,
    0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 2155937791U,
    0x0000001A, 0x00000023, 0x0000013C, 0x00000145,
    0x00000018, 0x00000021, 0x00000065, 0x0000006E,
    0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x406FE000,
    0x00000000, 0x41A00000, 0x0000001A, 0x00000023,
    0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900,
    0x0000001A, 0x00000023, 0x0000013C, 0x00000145,
    0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00,
    0x3F4CCCCD, 3221225472U, 0x0000001A, 0x00000023,
    0x0000013C, 0x00000145, 0x00000018, 0x00000021,
    0x0000001A, 0x00000023, 0x0000013C, 0x00000145,
    0x00000018, 0x00000021, 0xFFFF00FF, 0x19FF1900,
    0x00000000, 0x0000001A, 0x00000023, 0x0000013C,
    0x00000145, 0x19FF1900, 0 /* unused relocation addend */, 0 /* unused relocation addend */,
    0 /* unused relocation addend */, 0 /* unused relocation addend */, 0 /* unused relocation addend */, 0 /* unused relocation addend */,
    0 /* unused relocation addend */, 0 /* unused relocation addend */, 0x42880000, 0x42AC0000,
    0x3EC00000, 0x42A00000, 0x41600000, 0x41A80000,
    0x3F8CCCCD, 0x43C78000, 0x440F8000, 0x3F59999A,
    0x43FF0000, 0x19FF1900, 0x19FF1900, 0xF4962800,
    0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00,
    0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000,
    0xFFFFFF00, 0xF4962800, 0xFFFF00FF, 0x00000000,
    0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800,
    2155937536U, 0x00000000, 0xFFFFFF00, 0xF4962800,
    0xF4962800, 2155937536U, 0x00000000, 0xFFFFFF00,
    0x43B10000, 0x42A80000, 0x41B00000, 0x3F266666,
    0x43400000,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_408(volatile f32 *out) { *out = 48.0f; }

static const u32 fzgx_pool_table_40C[16] = {
    0x42380000, 0x425C0000, 0xFADC82FF, 0x00000000,
    0x441FC000, 0x43EF8000, 0x43A00000, 0x428C0000,
    0x42E00000, 0x43F60000, 0x42040000, 0x41980000,
    0x41C00000, 0x42480000, 0x41E80000, 0x42900000,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_44C(volatile f32 *out) { *out = 47.0f; }

static const u32 fzgx_pool_table_450[14] = {
    0x00009736, 0x00009737, 0x00009738, 0x00009739,
    0x0000973A, 0x0000973B, 0x0000973C, 0x0000973D,
    0x42340000, 0x42280000, 0x42180000, 0x00000000,
    3233857536U, 0x42240000,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_488(volatile f32 *out) { *out = 255.0f; }

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_48C(volatile f32 *out) { *out = 60.0f; }
#pragma section code_type ".text"

typedef struct fn_1_147508_Color {
    u8 r, g, b, a;
} fn_1_147508_Color;

typedef struct fn_1_147508_Entry {
    u8 pad_0[0x20];
    s32 unk_20;
    s32 unk_24;
    u8 pad_28[0xD];
    u8 unk_35;
    u8 pad_36;
    u8 unk_37;
    u8 unk_38;
    u8 unk_39;
    u8 pad_3A[0x12];
    s32 unk_4C;
    u8 pad_50[0x14];
    s32 unk_64;
    u8 pad_68[0xC];
    s32 unk_74;
    u8 pad_78[0x5C];
    FontDrawPacket packet;
} fn_1_147508_Entry;


extern f32 lbl_8006D188(s32);
extern s16 fn_1_12C930(s16);
extern s32 fn_8006FC1C(const char *, const char *);
extern s32 lbl_801A66A4;
extern char *fn_1_14FEAC(u8, u8, u8, char *, void *);
extern s32 fn_1_155F7C(void);
extern s32 fn_1_155F8C(void);

extern char *fn_1_7F49C(u8, void *, char *);
extern void fn_1_149C2C(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_49514(fn_1_147508_Color);
extern void fn_1_4954C(f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_4962C(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(void (*)(void));

#pragma opt_propagation off
static inline BOOL fn_1_147508_le(u32 a, u32 b) {
    return ((b | ~a) - ((b - a) >> 1)) >> 31;
}

static inline BOOL fn_1_147508_inRange(s32 m, s32 lo, s32 hi) {
    return m == lo || m == hi;
}

static inline BOOL fn_1_147508_isModeA(s32 m) {
    return fn_1_147508_inRange(m, 8, 9) || m == 10;
}

static inline BOOL fn_1_147508_isModeB2(s32 m) {
    return fn_1_147508_inRange(m, 4, 5) || m == 9;
}

static inline BOOL fn_1_147508_isModeB1(s32 m) {
    return fn_1_147508_isModeB2(m) || m == 10;
}

static inline BOOL fn_1_147508_isModeB(s32 m) {
    return fn_1_147508_isModeB1(m) || m == 6;
}

static inline BOOL fn_1_147508_isValidChar(u32 c) {
    BOOL valid = c <= 74;
    return valid;
}

static inline BOOL fn_1_147508_validName(u8 a, u8 b, u8 c) {
    return fn_1_147508_isValidChar(a) && fn_1_147508_isValidChar(b) && fn_1_147508_isValidChar(c);
}

#define IS_MODE_A(m) fn_1_147508_isModeA(m)
#define IS_MODE_B(m) fn_1_147508_isModeB(m)
#define IS_VALID_CHAR(c) fn_1_147508_isValidChar(c)

#pragma opt_propagation off
static inline void fn_1_147508_setPacket(FontDrawPacket *p, u32 image, f32 x, f32 y) {
    p->image = image;
    p->x = x;
    p->y = y;
    p->z = 48.0f;
}

void fn_1_147508(s32 mode, fn_1_147508_Entry *entry) {
    u32 x;
    u32 y;
    s32 show;
    f32 px, py;
    s32 iy, ix;
    u32 image;
    FontDrawPacket packet;
    fn_1_147508_Color color;
    char buf[0x100];

    x = entry->unk_74 + 160;
    y = entry->unk_64 + 37;
    if (IS_MODE_A(mode) || IS_MODE_B(mode)) {
        s32 packetIY, packetIX;
        u32 packetImage;
        packet = entry->packet;
        packetImage = 0x9724;
        packetIX = entry->unk_74 + 126;
        packetIY = entry->unk_64 + 32;
        fn_1_147508_setPacket(&packet, packetImage, packetIX, packetIY);
        fn_1_4F734(&packet);
    }
    if (!IS_MODE_B(mode)) {
        return;
    }
    fn_1_49410();
    fn_1_494DC(22);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_1_149C2C);
    fn_1_4954C(47.0f);
    fn_1_4962C();
    fn_1_49590(0.5f);
    fn_1_496FC(x, y);
    if (mode == 10 || mode == 6) {
        show = entry->unk_20 == 0;
    } else if (IS_MODE_B(mode)) {
        show = 0;
        if (fn_1_155F7C() != 0 && entry->unk_20 == fn_1_155F8C()) {
            show = 1;
        }
    } else {
        show = lbl_1_bss_3C30.unk_8 > entry->unk_4C;
    }
    if (show) {
        color.a = 255;
        color.b = 255;
        color.r = 255;
        px = 1.0f - lbl_8006D188((s32)(65536.0f * (f32)(lbl_801A66A4 % 60) / 60.0f));
        {
            f32 half = 0.5f;
            py = px * half;
        }
        color.g = 255.0f * py;
        fn_1_49514(color);
    }
    if (lbl_1_bss_8E52C != 0) {
        if (fn_8006FC1C(((char **)&lbl_1_data_212A8)[fn_1_12C930((s16)entry->unk_24)], (char *)lbl_1_data_425C8)) {
            fn_1_4A0D8((char *)lbl_1_data_425D8);
        } else {
            fn_1_4A0D8(((char **)&lbl_1_data_212A8)[fn_1_12C930((s16)entry->unk_24)]);
        }
    } else if (entry->unk_35 < 41) {
        fn_1_4A0D8(fn_1_7F49C(entry->unk_35, 0, buf));
    } else if (IS_VALID_CHAR(entry->unk_37) && IS_VALID_CHAR(entry->unk_38) && IS_VALID_CHAR(entry->unk_39)) {
        fn_1_4A0D8(fn_1_14FEAC(entry->unk_37, entry->unk_38, entry->unk_39, buf, 0));
    }
}
/* fzgx:end fn_1_147508 */

/* fzgx:begin fn_1_148444 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_149C2C(void);
extern void fn_1_49738(void *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(s32);
extern f32 fn_1_4B068(char *);
extern u8 lbl_1_rodata_9318[208];
extern int sprintf(char *, const char *, ...);

typedef struct {
    u8 pad_0[0x56];
    u8 unk_56[6];
    s32 unk_5C;
    u8 pad_60[0x4];
    s32 unk_64;
    s32 unk_68;
    u8 pad_6C[0x8];
    s32 unk_74;
} fn_1_148444_Obj;

static inline BOOL fn_1_148444_isA(s32 mode) {
    BOOL r = FALSE;
    if (mode == 8 || mode == 2 || mode == 3) {
        r = TRUE;
    }
    return r;
}

static inline BOOL fn_1_148444_isB(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)mode <= 1)) {
        r = FALSE;
    }
    return r;
}

static inline BOOL fn_1_148444_isC(s32 mode) {
    BOOL r = FALSE;
    if (mode == 1 || mode == 3) {
        r = TRUE;
    }
    return r;
}

void fn_1_148444(s32 mode, fn_1_148444_Obj *obj) {
    s32 x;
    s32 y;
    s32 value;
    s32 width;
    FontDrawPacket packet;
    char buf[0x100];

    if (!fn_1_148444_isA(mode) && !fn_1_148444_isB(mode)) {
        return;
    }
    if (!fn_1_148444_isC(mode)) {
        return;
    }
    if (obj->unk_5C == 0xFF) {
        return;
    }
    x = obj->unk_68 + obj->unk_74;
    y = obj->unk_64 + 14;
    x += 0x1A7;
    if (mode == 3) {
        x -= 10;
    }
    fn_1_49410();
    fn_1_494DC(0x1B);
    fn_1_49738(fn_1_149C2C);
    fn_1_496FC((f32)x, (f32)y);
    fn_1_4954C(47.0f);
    fn_1_495C8(2);
    if (fn_1_148444_isB(mode)) {
        value = obj->unk_56[lbl_1_bss_3C30.unk_A7];
    } else {
        value = obj->unk_56[0];
    }
    if (fn_1_148444_isA(mode)) {
        sprintf(buf, (const char *)&lbl_1_data_42808, value < 0 ? 0 : (value > 99 ? 99 : value));
    } else {
        sprintf(buf, (const char *)lbl_1_data_42810, value < 0 ? 0 : (value > 999 ? 999 : value));
    }
    fn_1_4A0D8(buf);
    width = fn_1_4B068(buf);
    packet = *(FontDrawPacket *)lbl_1_rodata_9318;
    packet.image = 0x9905;
    fn_1_51678(&packet, 0x9905, 100, 0, 10, 16);
    packet.x = (f32)(x - width);
    packet.y = (f32)y;
    packet.z = 47.0f;
    packet.flags |= 7;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_148444 */

/* fzgx:begin fn_1_1492E0 */
struct fn_1_1492E0_Copy88 { u32 a[22]; };
struct Results56 { u32 a[14]; };

extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_156218(u32, void *, void *, void *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4A0D8(const char *);
extern int sprintf(char *, const char *, ...);

/* Shared literal pool layout of the TU (lbl_1_rodata_92C0 .. +0x54C): tables and
   the literals this function reads, in retail order. */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table_000[71] = {
    0, 0, 0, 0x3DCCCCCD,
    0x3F800000, 0x3F800000, 0, 0,
    0x3F800000, 0x3F800000, 0, 0x3F800000,
    0x04000000, 0, 0xFFFFFFFF, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0x3DCCCCCD, 0x3F800000, 0x3F800000,
    0, 0, 0x3F800000, 0x3F800000,
    0, 0x3F800000, 0x04000000, 0,
    0xFFFFFFFF, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0x3DCCCCCD,
    0x3F800000, 0x3F800000, 0, 0,
    0x3F800000, 0x3F800000, 0, 0x3F800000,
    0x04000000, 0, 0xFFFFFFFF, 0,
    0, 0, 0, 0,
    0, 0, 0, 0x3F755555,
    0x41B80000, 0x40000000, 0x3F2AAAAB
};
void fzgx_pool_prime_000(const u32 **t, f32 *f) {
    t[0] = fzgx_pool_table_000;
    f[0] = 0.5f;
}
static const u32 fzgx_pool_table_120[2] = { 0x3F155555, 0 };
void fzgx_pool_prime_120(const u32 **t, f32 *f, s32 n) {
    t[0] = fzgx_pool_table_120;
    f[0] = (f32)n;
}
static const u32 fzgx_pool_table_130[109] = {
    0x44150000, 0x44040000, 0x1A, 0x23,
    0x9C, 0xA5, 0x18, 0x21,
    0x85, 0x8E, 0xF2, 0xFB,
    0xC0C0C000, 0xC0800000, 0x42200000, 0x43F00000,  /* fzgx-allow: A1 retail pool bytes */
    0x44200000, 0x47AFC800, 0x3E99999A, 0x3F333333,
    0xBF800000, 0x43500000, 0xC47A0000, 0xC2480000,
    0x3F800000, 0x41200000, 0x430C0000, 0x43600000,
    0x437E0000, 0x43800000, 0xC0C00000, 0x40A00000,  /* fzgx-allow: A1 retail pool bytes */
    0x40800000, 0x41400000, 0x41700000, 0,
    0x43300000, 0, 0x4E4F204E, 0x414D4500,
    0x4E4F2044, 0x41544100, 0x42C80000, 0x43AF0000,
    0x42300000, 0x41000000, 0xFFFFFFFF, 0x00F0E6FF,
    0x007873FF, 0xA0FF00FF, 0x1A, 0x23,
    0x13C, 0x145, 0x18, 0x21,
    0x65, 0x6E, 0xB2, 0xBB,
    0x41F00000, 0x3F400000, 0x42580000, 0x43AB8000,
    0x47800000, 0x42F00000, 0x3EB33333, 0xFFFFFFFF,
    0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF,
    0x8080FFFF, 0x1A, 0x23, 0x13C,  /* fzgx-allow: A1 retail pool bytes */
    0x145, 0x18, 0x21, 0x65,
    0x6E, 0xB2, 0xBB, 0x19FF1900,
    0x19FF1900, 0, 0, 0,
    0, 0, 0, 0,
    0x406FE000, 0, 0x41A00000, 0x1A,
    0x23, 0x13C, 0x145, 0xFFFFFF00,
    0x19FF1900, 0x1A, 0x23, 0x13C,
    0x145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF,
    0xFFFFFF00
};
void fzgx_pool_prime_130(const u32 **t, f32 *f) {
    t[0] = fzgx_pool_table_130;
    f[0] = 0.8f;
}
static const u32 fzgx_pool_table_2E8[105] = {
    0xC0000000, 0x1A,  /* fzgx-allow: A1 retail pool bytes */
    0x23, 0x13C, 0x145, 0x18,
    0x21, 0x1A, 0x23, 0x13C,
    0x145, 0x18, 0x21, 0xFFFF00FF,
    0x19FF1900, 0, 0x1A, 0x23,
    0x13C, 0x145, 0x19FF1900, 0,
    0, 0, 0, 0,
    0, 0, 0, 0x42880000,
    0x42AC0000, 0x3EC00000, 0x42A00000, 0x41600000,
    0x41A80000, 0x3F8CCCCD, 0x43C78000, 0x440F8000,
    0x3F59999A, 0x43FF0000, 0x19FF1900, 0x19FF1900,
    0xF4962800, 0xF4962800, 0xFFFF0000, 0,
    0xFFFFFF00, 0xF4962800, 0xF4962800, 0xFFFF0000,
    0, 0xFFFFFF00, 0xF4962800, 0xFFFF00FF,
    0, 0x19FF1900, 0x19FF1900, 0xF4962800,
    0xF4962800, 0x8080FF00, 0, 0xFFFFFF00,  /* fzgx-allow: A1 retail pool bytes */
    0xF4962800, 0xF4962800, 0x8080FF00, 0,  /* fzgx-allow: A1 retail pool bytes */
    0xFFFFFF00, 0x43B10000, 0x42A80000, 0x41B00000,
    0x3F266666, 0x43400000, 0x42400000, 0x42380000,
    0x425C0000, 0xFADC82FF, 0, 0x441FC000,
    0x43EF8000, 0x43A00000, 0x428C0000, 0x42E00000,
    0x43F60000, 0x42040000, 0x41980000, 0x41C00000,
    0x42480000, 0x41E80000, 0x42900000, 0x423C0000,
    0x9736, 0x9737, 0x9738, 0x9739,
    0x973A, 0x973B, 0x973C, 0x973D,
    0x42340000, 0x42280000, 0x42180000, 0,
    0xC0C0C000, 0x42240000, 0x437F0000  /* fzgx-allow: A1 retail pool bytes */
};
void fzgx_pool_prime_2E8(const u32 **t, f32 *f) {
    t[0] = fzgx_pool_table_2E8;
    f[0] = 60.0f;
}
static const u32 fzgx_pool_table_490[43] = {
    0xFFFF00FF, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0x3C23D70A, 0, 0x3F40624D, 0xD2F1A9FC,
    0x41555556, 0x43260000, 0x43AE2AAB, 0x41100000,
    0x40E00000, 0x432A0000, 0xC1200000  /* fzgx-allow: A1 retail pool bytes */
};

void fzgx_pool_prime_1492E0(const u32 **t, f32 *f, s32 n) {
    t[0] = fzgx_pool_table_000;
    f[0] = 0.5f;
    t[1] = fzgx_pool_table_120;
    f[1] = (f32)n;
    t[2] = fzgx_pool_table_130;
    f[2] = 0.8f;
    t[3] = fzgx_pool_table_2E8;
    f[3] = 60.0f;
    t[4] = fzgx_pool_table_490;
    f[4] = 74.0f;
    f[5] = 92.0f;
    f[6] = 105.0f;
    f[7] = 110.0f;
}
#pragma section code_type ".text"

#define FONT_SETUP(n)            \
    fn_1_49410();                \
    fn_1_494DC(n);               \
    fn_1_495B0(0x80000000);      \
    fn_1_49590(0.5f);            \
    fn_1_4955C(0.8f, 0.8f)

extern u8 fn_1_1420E0__fzgx_offset_0[];
extern u8 fn_1_144E90__fzgx_offset_0[];
extern u8 fn_1_144EE8__fzgx_offset_0[];
extern u8 fn_1_149DA4__fzgx_offset_0[];
extern u8 fn_1_149DE8__fzgx_offset_0[];
extern u8 fn_1_149E2C__fzgx_offset_0[];
extern u8 fn_1_149F04__fzgx_offset_0[];
extern u8 fn_1_149F5C__fzgx_offset_0[];
extern u8 fn_1_14A000__fzgx_offset_0[];
extern u8 fn_1_14A004__fzgx_offset_0[];
extern u8 fn_1_14A008__fzgx_offset_0[];
extern u8 lbl_1_data_42198__fzgx_offset_0[];
extern u8 lbl_1_data_4219C__fzgx_offset_0[];
extern u8 lbl_1_data_421A8__fzgx_offset_0[];
extern u8 lbl_1_data_421B4__fzgx_offset_0[];
extern u8 lbl_1_data_421C0__fzgx_offset_0[];
extern u8 lbl_1_data_421CC__fzgx_offset_0[];
extern u8 lbl_1_data_421D4__fzgx_offset_0[];
extern u8 lbl_1_data_421DC__fzgx_offset_0[];
extern u8 lbl_1_data_421E4__fzgx_offset_0[];
extern u8 lbl_1_data_421EC__fzgx_offset_0[];
extern u8 lbl_1_data_421F8__fzgx_offset_0[];
extern u8 lbl_1_data_42208__fzgx_offset_0[];
extern u8 lbl_1_data_42218__fzgx_offset_0[];
extern u8 lbl_1_data_42220__fzgx_offset_0[];
extern u8 lbl_1_data_42228__fzgx_offset_0[];
extern u8 lbl_1_data_42234__fzgx_offset_0[];
extern u8 lbl_1_data_42240__fzgx_offset_0[];
extern u8 lbl_1_data_42250__fzgx_offset_0[];
extern u8 lbl_1_data_42258__fzgx_offset_0[];
extern u8 lbl_1_data_42264__fzgx_offset_0[];
extern u8 lbl_1_data_42270__fzgx_offset_0[];
extern u8 lbl_1_data_42280__fzgx_offset_0[];
extern u8 lbl_1_data_42288__fzgx_offset_0[];
extern u8 lbl_1_data_42294__fzgx_offset_0[];
extern u8 lbl_1_data_422A0__fzgx_offset_0[];
extern u8 lbl_1_data_422B0__fzgx_offset_0[];
extern u8 lbl_1_data_422B8__fzgx_offset_0[];
extern u8 lbl_1_data_422C4__fzgx_offset_0[];
extern u8 lbl_1_data_422CC__fzgx_offset_0[];
extern u8 lbl_1_data_422D8__fzgx_offset_0[];
extern u8 lbl_1_data_422E8__fzgx_offset_0[];
extern u8 lbl_1_data_422F4__fzgx_offset_0[];
extern u8 lbl_1_data_42300__fzgx_offset_0[];
extern u8 lbl_1_data_42308__fzgx_offset_0[];
extern u8 lbl_1_data_4231C__fzgx_offset_0[];
extern u8 lbl_1_data_4232C__fzgx_offset_0[];
extern u8 lbl_1_data_4233C__fzgx_offset_0[];
extern u8 lbl_1_data_42348__fzgx_offset_0[];
extern u8 lbl_1_data_42354__fzgx_offset_0[];
extern u8 lbl_1_data_42364__fzgx_offset_0[];
extern u8 lbl_1_data_4236C__fzgx_offset_0[];
extern u8 lbl_1_data_42378__fzgx_offset_0[];
extern u8 lbl_1_data_42380__fzgx_offset_0[];
extern u8 lbl_1_data_42388__fzgx_offset_0[];
extern u8 lbl_1_data_42390__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_42198[422] = {  /* fzgx-allow: A1 retail data bytes and bindings */
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
    (u32)lbl_1_data_42198__fzgx_offset_0, (u32)lbl_1_data_4219C__fzgx_offset_0, (u32)lbl_1_data_421A8__fzgx_offset_0, (u32)lbl_1_data_421B4__fzgx_offset_0, (u32)lbl_1_data_421C0__fzgx_offset_0, (u32)lbl_1_data_421CC__fzgx_offset_0, (u32)lbl_1_data_421D4__fzgx_offset_0, (u32)lbl_1_data_421DC__fzgx_offset_0,
    (u32)lbl_1_data_421E4__fzgx_offset_0, (u32)lbl_1_data_421EC__fzgx_offset_0, (u32)lbl_1_data_421F8__fzgx_offset_0, (u32)lbl_1_data_42208__fzgx_offset_0, (u32)lbl_1_data_42218__fzgx_offset_0, (u32)lbl_1_data_42220__fzgx_offset_0, (u32)lbl_1_data_42228__fzgx_offset_0, (u32)lbl_1_data_42234__fzgx_offset_0,
    (u32)lbl_1_data_42240__fzgx_offset_0, (u32)lbl_1_data_42250__fzgx_offset_0, (u32)lbl_1_data_42258__fzgx_offset_0, (u32)lbl_1_data_42264__fzgx_offset_0, (u32)lbl_1_data_42270__fzgx_offset_0, (u32)lbl_1_data_42280__fzgx_offset_0, (u32)lbl_1_data_42288__fzgx_offset_0, (u32)lbl_1_data_42294__fzgx_offset_0,
    (u32)lbl_1_data_422A0__fzgx_offset_0, (u32)lbl_1_data_422B0__fzgx_offset_0, (u32)lbl_1_data_422B8__fzgx_offset_0, (u32)lbl_1_data_422C4__fzgx_offset_0, (u32)lbl_1_data_422CC__fzgx_offset_0, (u32)lbl_1_data_422D8__fzgx_offset_0, (u32)lbl_1_data_422E8__fzgx_offset_0, (u32)lbl_1_data_422F4__fzgx_offset_0,
    (u32)lbl_1_data_42300__fzgx_offset_0, (u32)lbl_1_data_42308__fzgx_offset_0, (u32)lbl_1_data_4231C__fzgx_offset_0, (u32)lbl_1_data_4232C__fzgx_offset_0, (u32)lbl_1_data_4233C__fzgx_offset_0, (u32)lbl_1_data_42348__fzgx_offset_0, (u32)lbl_1_data_42354__fzgx_offset_0, (u32)lbl_1_data_42364__fzgx_offset_0,
    (u32)lbl_1_data_4236C__fzgx_offset_0, (u32)lbl_1_data_42378__fzgx_offset_0, (u32)lbl_1_data_42380__fzgx_offset_0, (u32)lbl_1_data_42388__fzgx_offset_0, (u32)lbl_1_data_42390__fzgx_offset_0, (u32)fn_1_1420E0__fzgx_offset_0, (u32)fn_1_144E90__fzgx_offset_0, (u32)fn_1_144EE8__fzgx_offset_0,
    (u32)fn_1_149E2C__fzgx_offset_0, (u32)fn_1_149F04__fzgx_offset_0, (u32)fn_1_149DA4__fzgx_offset_0, (u32)fn_1_149DE8__fzgx_offset_0, (u32)fn_1_149F5C__fzgx_offset_0, (u32)fn_1_14A000__fzgx_offset_0, (u32)fn_1_14A004__fzgx_offset_0, (u32)fn_1_14A008__fzgx_offset_0,
    0x5B000000, 0x5D000000, 0x4E414D45, 0x3A000000, 0x25640000, 0x4E414D45, 0x0, 0x50494C4F,
    0x54205241, 0x4E4B0000, 0x25316400, 0x252D3264, 0x0, 0x25303264, 0x3C253032, 0x643D2530,
    0x33640000, 0x25303264, 0x3B253032, 0x643C2530, 0x33640000, 0x25346400, 0x83418343, 0x838B8367,
    0x83938140, 0x835A8369, 0x0, 0x82608144, 0x83608346, 0x8355838A, 0x83588140, 0x0,
    0x836C838B, 0x835C8393, 0x81408373, 0x83508140, 0x0, 0x83418389, 0x83938140, 0x8376838D,  /* fzgx-allow: A1 retail data bytes */
    0x83588367, 0x0, 0x837D8358, 0x835E815B, 0x83898343, 0x835A8393, 0x83580000, 0x82528251,
    0x8B898389, 0x8343835A, 0x83938358, 0x0, 0x83708343, 0x838D8362, 0x83678CF3, 0x95E290B6,
    0x0, 0x82728272, 0x8B898389, 0x8343835A, 0x83938358, 0x0, 0x4E4F2044, 0x41544100,
    0x52455355, 0x4C545300, 0x544F5441, 0x4C205241, 0x4E4B494E, 0x47000000, 0x56532052, 0x4553554C,
    0x54530000, 0x56532054, 0x4F54414C, 0x2052414E, 0x4B494E47, 0x0, 0x54494D45, 0x20415454,
    0x41434B00, 0x50524143, 0x54494345, 0x0, 0x474F4D41, 0x52202620, 0x5348494F, 0x48000000,
    0x474F4D41, 0x52202C20, 0x5348494F, 0x48000000, 0x43617069, 0x74616C20, 0x4C657474, 0x65727300,
    0x47455220, 0x43617069, 0x74616C20, 0x4C657474, 0x65727300, 0x46524520, 0x43617069, 0x74616C20,
    0x4C657474, 0x65727300, 0x53504120, 0x43617069, 0x74616C20, 0x4C657474, 0x65727300, 0x49544120,
    0x43617069, 0x74616C20, 0x4C657474, 0x65727300, 0x89709094, 0x0, 0x20536D61, 0x6C6C204C,
    0x65747465, 0x72732000, 0x47455220, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x46524520,
    0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x53504120, 0x536D616C, 0x6C204C65, 0x74746572,
    0x73000000, 0x49544120, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x8B4C8D86, 0x0,
    0x20202020, 0x20536967, 0x6E732020, 0x20202000, 0x47455220, 0x5369676E, 0x73000000, 0x46524520,
    0x5369676E, 0x73000000, 0x53504120, 0x5369676E, 0x73000000, 0x49544120, 0x5369676E, 0x73000000,
    0x82A982C8, 0x0, 0x20202020, 0x4E756D62, 0x65727320, 0x20200000, 0x47455220, 0x4E756D62,
    0x65727300, 0x46524520, 0x4E756D62, 0x65727300, 0x53504120, 0x4E756D62, 0x65727300, 0x49544120,
    0x4E756D62, 0x65727300, 0x834A8369, 0x0, 0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74,
    0x65722083, 0xB45B2573, 0x5D000000, 0x47455220, 0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74,
    0x65722083, 0xB45B2573, 0x5D000000, 0x46524520, 0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74,
    0x65722083, 0xB45B2573, 0x5D000000, 0x53504120, 0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74,
    0x65722083, 0xB45B2573, 0x5D000000, 0x49544120, 0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74,
    0x65722083, 0xB45B2573, 0x5D000000, 0x83A0208F, 0xC182B720, 0x839F208C, 0x8892E820, 0x83B45B25,
    0x735D0000, 0x81E70000, 0x20200000, 0x81E80000, 0x25303264, 0x0, 0x25303364, 0x0,
    0x52554E4E, 0x494E4700, 0x44495351, 0x55414C49, 0x46494544, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_42198_698[7] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25303264, 0x3A253032, 0x643B2530, 0x33640000, 0x25303464, 0x0, 0x25326400
};
static u32 fzgx_pool_data_lbl_1_data_42198_6B4[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x544F5441, 0x4C205449, 0x4D450000
};
static u32 fzgx_pool_data_lbl_1_data_42198_6C0[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4D415820, 0x53504545, 0x44000000
};
static u32 fzgx_pool_data_lbl_1_data_42198_6CC[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42455354, 0x204C4150, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_42198_6D8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x20202530, 0x34640000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_42198(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_42198;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_42198_698;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_42198_6B4;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_42198_6C0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_42198_6CC;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_42198_6D8;
}
#pragma section code_type ".text"

#pragma opt_propagation on
static inline s32 fn_1_1492E0_range(s32 mode) {
    s32 result = 1;
    if (!((u32)(mode - 4) <= 1)) result = 0;
    return result;
}
static inline s32 fn_1_1492E0_mode9(s32 mode) {
    s32 result = 1;
    if (!fn_1_1492E0_range(mode) && mode != 9) result = 0;
    return result;
}
static inline s32 fn_1_1492E0_mode10(s32 mode) {
    s32 result = 1;
    if (!fn_1_1492E0_mode9(mode) && mode != 10) result = 0;
    return result;
}
static inline s32 fn_1_1492E0_visible(s32 mode) {
    s32 result = 1;
    if (!fn_1_1492E0_mode10(mode) && mode != 6) result = 0;
    return result;
}
void fn_1_1492E0(s32 arg0, void *arg1) {
    u32 v0;
    
    s32 flag0;
    s32 flag2;
    s32 flag3;
    char buf[256];
    struct fn_1_1492E0_Copy88 packet;
    struct Results56 a;
    struct Results56 b;
    struct Results56 c;
    s32 pos;
    s32 x;
    s32 y;
    s32 z;
    s32 i;

    if (fn_1_1492E0_visible(arg0)) {
        packet = *(struct fn_1_1492E0_Copy88 *)lbl_1_rodata_26F8;
        packet.a[0] = 0x9726;
        fn_1_51678((FontDrawPacket *)&packet, 0x9726, 0, 0, 87, 40);
        ((f32 *)packet.a)[1] = 74.0f;
        ((f32 *)packet.a)[2] = 92.0f;
        ((f32 *)packet.a)[3] = 60.0f;
        fn_1_4F734((FontDrawPacket *)&packet);
        for (i = 0, pos = 161; i < 9; i++, pos += 40) {
            packet = *(struct fn_1_1492E0_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 0x9726;
            fn_1_51678((FontDrawPacket *)&packet, packet.a[0], 47, 0, 40, 40);
            ((f32 *)packet.a)[1] = (f32)pos;
            ((f32 *)packet.a)[2] = 92.0f;
            ((f32 *)packet.a)[3] = 60.0f;
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        packet = *(struct fn_1_1492E0_Copy88 *)lbl_1_rodata_26F8;
        packet.a[0] = 0x9726;
        fn_1_51678((FontDrawPacket *)&packet, 0x9726, 87, 0, 45, 40);
        ((f32 *)packet.a)[1] = (f32)pos;
        ((f32 *)packet.a)[2] = 92.0f;
        ((f32 *)packet.a)[3] = 60.0f;
        fn_1_4F734((FontDrawPacket *)&packet);
        fn_1_156218(*((u8 *)arg1 + 0x34), &a, &b, &c);
        if (lbl_1_bss_8E559 == 0) { x = -1; y = 115; z = 319; }
        if (lbl_1_bss_8E559 == 1) { x = 101; y = -1; z = 326; }
        if (lbl_1_bss_8E559 == 2) { x = 106; y = 341; z = -1; }
        if (x != -1) { FONT_SETUP(21); fn_1_496FC((f32)x, 105.0f); fn_1_4AE0C(((char *)fzgx_pool_data_lbl_1_data_42198_6B4)); }
        if (y != -1) { FONT_SETUP(21); fn_1_496FC((f32)y, 105.0f); fn_1_4AE0C(((char *)fzgx_pool_data_lbl_1_data_42198_6C0)); }
        if (z != -1) { FONT_SETUP(21); fn_1_496FC((f32)z, 105.0f); fn_1_4AE0C(((char *)fzgx_pool_data_lbl_1_data_42198_6CC)); }
        if (x != -1) {
            FONT_SETUP(18);
            sprintf(buf, ((char *)fzgx_pool_data_lbl_1_data_42198_698), (a.a[0] >> 20) & 255, (a.a[0] >> 12) & 255, a.a[0] & 4095);
            fn_1_496FC((f32)(x + 106), 105.0f);
            fn_1_4A0D8(buf);
        }
        if (y != -1) {
            FONT_SETUP(18);
            sprintf(buf, ((char *)fzgx_pool_data_lbl_1_data_42198_6D8), *(u16 *)((u8 *)&b + 0x18));
            fn_1_496FC((f32)(y + 89), 105.0f);
            fn_1_4A0D8(buf);
            packet = *(struct fn_1_1492E0_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 0x9704;
            ((f32 *)packet.a)[1] = (f32)(y + 156);
            ((f32 *)packet.a)[2] = 110.0f;
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        if (z != -1) {
            FONT_SETUP(18);
            sprintf(buf, ((char *)fzgx_pool_data_lbl_1_data_42198_698), (c.a[1] >> 20) & 255, (c.a[1] >> 12) & 255, c.a[1] & 4095);
            fn_1_496FC((f32)(z + 101), 105.0f);
            fn_1_4A0D8(buf);
        }
    }
}
/* fzgx:end fn_1_1492E0 */

/* fzgx:begin fn_1_1498B8 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
}
static const u32 fzgx_pool_table3[62] = {0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 0.9583333134651184f;
    s = 23.0f;
    s = 2.0f;
    s = 0.6666666865348816f;
    s = 0.5f;
    s = 0.5833333134651184f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 596.0f;
    s = 528.0f;
}
static const u32 fzgx_pool_table7[11] = {0x0000001A, 0x00000023, 0x0000009C, 0x000000A5, 0x00000018, 0x00000021, 0x00000085, 0x0000008E, 0x000000F2, 0x000000FB, 0xC0C0C000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -4.0f;
    s = 40.0f;
    s = 480.0f;
    s = 640.0f;
    s = 90000.0f;
    s = 0.30000001192092896f;
    s = 0.699999988079071f;
    s = -1.0f;
    s = 208.0f;
    s = -1000.0f;
    s = -50.0f;
    s = 1.0f;
    s = 10.0f;
    s = 140.0f;
    s = 224.0f;
    s = 254.0f;
    s = 256.0f;
    s = -6.0f;
    s = 5.0f;
    s = 4.0f;
    s = 12.0f;
    s = 15.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table11[1] = {0x4E4F204E};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.829345703125f;
}
static const u32 fzgx_pool_table13[1] = {0x4E4F2044};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 13.265869140625f;
    s = 100.0f;
    s = 350.0f;
    s = 44.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table15[14] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    s = 0.75f;
    s = 54.0f;
    s = 343.0f;
    s = 65536.0f;
    s = 120.0f;
    s = 0.3499999940395355f;
}
static const u32 fzgx_pool_table17[25] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.748046875f;
}
static const u32 fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
}
static const u32 fzgx_pool_table21[14] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = -2.0f;
}
static const u32 fzgx_pool_table23[28] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0xFFFF00FF, 0x19FF1900, 0x00000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 68.0f;
    s = 86.0f;
    s = 0.375f;
    s = 80.0f;
    s = 14.0f;
    s = 21.0f;
    s = 1.100000023841858f;
    s = 399.0f;
    s = 574.0f;
    s = 0.8500000238418579f;
    s = 510.0f;
}
static const u32 fzgx_pool_table25[27] = {0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xFFFF00FF, 0x00000000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 354.0f;
    s = 84.0f;
    s = 22.0f;
    s = 0.6499999761581421f;
    s = 192.0f;
    s = 48.0f;
    s = 46.0f;
    s = 55.0f;
}
static const u32 fzgx_pool_table27[2] = {0xFADC82FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const u32 *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 639.0f;
    s = 479.0f;
    s = 320.0f;
    s = 70.0f;
    s = 112.0f;
    s = 492.0f;
    s = 33.0f;
    s = 19.0f;
    s = 24.0f;
    s = 50.0f;
    s = 29.0f;
    s = 72.0f;
    s = 47.0f;
}
static const u32 fzgx_pool_table29[8] = {0x00009736, 0x00009737, 0x00009738, 0x00009739, 0x0000973A, 0x0000973B, 0x0000973C, 0x0000973D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const u32 *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 45.0f;
    s = 42.0f;
    s = 38.0f;
}
static const u32 fzgx_pool_table31[2] = {0x00000000, 0xC0C0C000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const u32 *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 41.0f;
    s = 255.0f;
    s = 60.0f;
}
static const u32 fzgx_pool_table33[32] = {0xFFFF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep33(void) { const u32 *volatile cp; cp = fzgx_pool_table33; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime34(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table35[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep35(void) { const u32 *volatile cp; cp = fzgx_pool_table35; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime36(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0005;
    s = 13.333333969116211f;
    s = 166.0f;
    s = 348.3333435058594f;
    s = 9.0f;
    s = 7.0f;
    s = 170.0f;
    s = -10.0f;
    s = 74.0f;
    s = 92.0f;
    s = 105.0f;
    s = 110.0f;
    s = 302.0f;
}
#pragma section code_type ".text"

struct fn_1_1498B8_Copy88 { u32 a[22]; };
struct fn_1_1498B8_lbl_801A66A4 { u32 unk_0; };
extern struct fn_1_1498B8_lbl_801A66A4 lbl_801A66A4;
extern u32 lbl_1_bss_8E554;
extern u8 lbl_1_rodata_26F8;
extern u8 lbl_1_bss_8E550;
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

#pragma opt_strength_reduction off
#pragma opt_propagation off
void fn_1_1498B8(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6) {
    struct fn_1_1498B8_Copy88 loc_8;
    if (lbl_801A66A4.unk_0 - lbl_1_bss_8E528 >= lbl_1_bss_8E554 && (s32)arg0 != 5) {
        if (arg6 < (f32)(s32)(lbl_1_bss_8E550 - arg1)) {
            loc_8 = *(struct fn_1_1498B8_Copy88 *)&lbl_1_rodata_26F8;
            loc_8.a[0] = 0x971C;
            fn_1_51678((FontDrawPacket *)&loc_8, (*((0) + (loc_8.a))), 20, 0, 20, 12);
            *(f32 *)((u8 *)&loc_8 + 4) = 302.0f;
            {
                s32 v7 = arg1 * arg2 - 6;
                v7 += arg5;
                *(f32 *)((u8 *)&loc_8 + 8) = (f32)(arg3 + v7);
            }
            *(f32 *)((u8 *)&loc_8 + 12) = 50.0f;
            *(f32 *)((u8 *)&loc_8 + 44) = lbl_801A66A4.unk_0 % 60 > 30 ? 1.0f : 0.0f;
            fn_1_4F734((FontDrawPacket *)&loc_8);
        }
        if (arg6 > 0.0f) {
            loc_8 = *(struct fn_1_1498B8_Copy88 *)&lbl_1_rodata_26F8;
            loc_8.a[0] = 0x971C;
            fn_1_51678((FontDrawPacket *)&loc_8, (*((0) + (loc_8.a))), 0, 0, 20, 12);
            *(f32 *)((u8 *)&loc_8 + 4) = 302.0f;
            {
                s32 v12 = arg3 + arg4;
                v12 -= 16;
                *(f32 *)((u8 *)&loc_8 + 8) = (f32)v12;
            }
            *(f32 *)((u8 *)&loc_8 + 12) = 50.0f;
            *(f32 *)((u8 *)&loc_8 + 44) = lbl_801A66A4.unk_0 % 60 > 30 ? 1.0f : 0.0f;
            fn_1_4F734((FontDrawPacket *)&loc_8);
        }
    }
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_1498B8 */

/* fzgx:begin fn_1_149B24 */
typedef struct {
    f32 value0;
    u8 pad[8];
    f32 value_c;
} Fn149B24Data;


void fn_1_149B24(void* context, Fn149B24Data* data) {
    f32 increment = lbl_1_rodata_946C;

    data->value0 += increment;
    data->value_c += increment;
    fn_1_149C2C(context, data);
}
/* fzgx:end fn_1_149B24 */

/* fzgx:begin fn_1_149B64 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"

extern void fn_1_5233C(void* arg0, void* arg1);
extern void fn_1_149CA4(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern u32 fn_1_A5DB0(void);
extern u32 fn_1_A5D88(void);
extern void fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_1_149C2C(void);
extern void fn_1_149C2C();

// Rebuild the display state and publish the current display and effect IDs.
void fn_1_149B64(void* display_state, void* display_context) {
    u32 display_id;
    u32 effect_id;

    fn_1_149CA4(lbl_1_bss_8E428.unk_C,
                 *(u32*)((u8*)&lbl_1_bss_8E428 + 0x14),
                 lbl_1_bss_8E428.unk_10,
                 *(u32*)((u8*)&lbl_1_bss_8E428 + 0x18));
    fn_1_5233C(display_state, display_context);

    display_id = fn_1_A5DB0() & 0xffff;
    effect_id = fn_1_A5D88() & 0xffff;
    fn_80074188(0, 0, effect_id, display_id);

    fn_1_149C2C(display_state, display_context);
}
/* fzgx:end fn_1_149B64 */

/* fzgx:begin fn_1_149BF4 */
// Load four values from BSS table and pass to fn_1_149CA4.
void fn_1_149BF4(void) {
    u8* base = (u8*)&lbl_1_bss_8E428;
    u32 arg0 = *(u32*)(base + 0x4);
    u32 arg1 = *(u32*)(base + 0x14);
    u32 arg2 = *(u32*)(base + 0x8);
    u32 arg3 = *(u32*)(base + 0x18);
    fn_1_149CA4(arg0, arg1, arg2, arg3);
}
/* fzgx:end fn_1_149BF4 */

/* fzgx:begin fn_1_149C2C */
// Forward the four current static-display values to the display-update routine.
void fn_1_149C2C(void) {
    u8* table = (u8*)&lbl_1_bss_8E428;
    u32 position = *(u32*)(table + 0xC);
    u32 direction = *(u32*)(table + 0x14);
    u32 scale = *(u32*)(table + 0x10);
    u32 flags = *(u32*)(table + 0x18);

    fn_1_149CA4(position, direction, scale, flags);
}
/* fzgx:end fn_1_149C2C */

/* fzgx:begin fn_1_149C64 */
// Initialize the static display state with the default viewport dimensions.
void fn_1_149C64(void) {
    struct fn_1_149C64_lbl_1_bss_8E43C *display_state = &lbl_1_bss_8E43C;
    struct fn_1_149C64_lbl_1_bss_8E440 *display_config = &lbl_1_bss_8E440;

    fn_1_149CA4(0, display_state->unk_0, 0x280, display_config->unk_0);
}
/* fzgx:end fn_1_149C64 */

/* fzgx:begin fn_1_149CA4 */
void fn_1_149CA4(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    fn_1_520A0();
    fn_1_52070(0x140);
    fn_80074188((s32)__cvt_fp2unsigned(fn_1_520F8(arg0)),
                __cvt_fp2unsigned((f32)(arg1 * ((u32)fn_1_A5DB0() & 0xffff)) / lbl_1_rodata_942C[0]),
                __cvt_fp2unsigned(fn_1_521B8(arg2)),
                __cvt_fp2unsigned((f32)(arg3 * ((u32)fn_1_A5DB0() & 0xffff)) / lbl_1_rodata_942C[0]));
    fn_1_520CC();
}
/* fzgx:end fn_1_149CA4 */

/* fzgx:begin fn_1_149DA4 */
void fn_1_149DA4(void) {
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(4, 0);
    }
}
/* fzgx:end fn_1_149DA4 */

/* fzgx:begin fn_1_149DE8 */
void fn_1_149DE8(void) {
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(5, 0);
    }
}
/* fzgx:end fn_1_149DE8 */

/* fzgx:begin fn_1_149F04 */
void fn_1_149F04(void) {
    lbl_1_bss_8E428.unk_0 = (u32)((u8 *)&lbl_1_bss_3C30 + 0x1394);
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(3, 0);
    }
}
/* fzgx:end fn_1_149F04 */

/* fzgx:begin fn_1_149F5C */
void fn_1_149F5C(void) {
    lbl_1_bss_8E428.unk_0 = (u32)&lbl_1_bss_3C30 + 0xe;
    if (lbl_1_bss_8E51D != lbl_1_bss_8E524) {
        return;
    }
    fn_1_144F40(7, 0);
}
/* fzgx:end fn_1_149F5C */

/* fzgx:begin fn_1_149FB4 */
u8 fn_1_149FB4(s32 index) {
    u8 *entry = (u8 *)&lbl_1_bss_26314 + index * 0x1fc;

    if (lbl_1_bss_3C30.unk_5 == 2) {
        return fn_1_155F8C();
    }

    return entry[0x115];
}
/* fzgx:end fn_1_149FB4 */

/* fzgx:begin fn_1_14A000 */
// fn_1_14A000: empty in retail (single blr).
void fn_1_14A000(void) {
}
/* fzgx:end fn_1_14A000 */

/* fzgx:begin fn_1_14A004 */
// fn_1_14A004: empty in retail (single blr).
void fn_1_14A004(void) {
}
/* fzgx:end fn_1_14A004 */

/* fzgx:begin fn_1_14A008 */
// fn_1_14A008: empty in retail (single blr).
void fn_1_14A008(void) {
}
/* fzgx:end fn_1_14A008 */

/* fzgx:begin fn_1_14A00C */
void fn_1_14A00C(void) {
    lbl_1_bss_8E520 = 1;
    lbl_1_bss_8E524 = 0xff;
}
/* fzgx:end fn_1_14A00C */

/* fzgx:begin fn_1_14A028 noprologue */
#include "types.h"

extern u8 lbl_1_bss_38200;
extern u16 lbl_1_bss_50EC[10];
extern u32 lbl_801A66A4;

typedef struct {
    void (*unk_0)(void *, u32);
    void (*unk_4)(void);
    void (*unk_8)(void);
    u32 unk_C;
} Ent;

extern Ent lbl_1_data_42B94[];

typedef struct {
    u32 unk_0;
    u8 pad_4[4];
    u8 unk_8;
} Obj3C30;
extern Obj3C30 lbl_1_bss_3C30;

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[6];
    u8 unk_C;
    u8 pad_D[3];
    u32 unk_10;
    u8 unk_14;
} Obj518;
extern Obj518 lbl_1_bss_8E518;

typedef struct {
    u8 pad_0[8];
    u16 unk_8;
} Obj9F8;
extern Obj9F8 lbl_1_bss_9F8;

extern void fn_1_14A1AC(u8);

#pragma opt_dead_assignments off
#pragma opt_common_subs off
void fn_1_14A028(void) {
    u32 fzgx_value;
    Obj518 *s = &lbl_1_bss_8E518;
    int flag = 1;
    u8 tmp_ra2;

    if ((lbl_1_bss_3C30.unk_0 & 0x8) == 0 && (((((0x1000 & lbl_1_bss_3C30.unk_0))) != ((0))))) {
        if (((((lbl_1_bss_38200)) != ((0))))) {
            flag = 0;
        } else {
            int n = lbl_1_bss_3C30.unk_8;
            int i = 0;

            while (n > 0) {
                if (lbl_1_bss_50EC[i] != 0) {
                    flag = 0;
                    break;
                }
                i++;
                n--;
            }
        }

        tmp_ra2 = s->unk_C;

        if (((((tmp_ra2)) != ((s->unk_5))))) {
            if (((((tmp_ra2)) != ((0xFF))))) {
                lbl_1_data_42B94[tmp_ra2].unk_8();
            }

            tmp_ra2 = s->unk_5;
            fzgx_value = lbl_801A66A4;
            s->unk_C = tmp_ra2;
            s->unk_10 = fzgx_value;
            lbl_1_data_42B94[tmp_ra2].unk_0(lbl_1_data_42B94, lbl_801A66A4);
        }

        fn_1_14A1AC(s->unk_5);

        if (((((flag)) != ((0))))) {
            lbl_1_data_42B94[s->unk_5].unk_4();
            if (((0) != (((lbl_1_bss_9F8.unk_8 >> 4) & 1)))) {
                s->unk_14 ^= 1;
            }
        }
    }
}
#pragma opt_common_subs reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_14A028 */

/* fzgx:begin fn_1_14A17C noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x18];
    f32 unk_18;
    f32 unk_1c;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
} fn_1_14A17C_Obj_1_bss_8E518;

extern const f32 lbl_1_rodata_99A4;
extern fn_1_14A17C_Obj_1_bss_8E518 lbl_1_bss_8E518;

// Reset the static display state to its initial values.
void fn_1_14A17C(void) {
    lbl_1_bss_8E518.unk_20 = 0;
    lbl_1_bss_8E518.unk_18 = lbl_1_rodata_99A4;
    lbl_1_bss_8E518.unk_1c = lbl_1_rodata_99A4;
    lbl_1_bss_8E518.unk_24 = 0;
    lbl_1_bss_8E518.unk_28 = 0;
    lbl_1_bss_8E518.unk_2c = 0;
}
/* fzgx:end fn_1_14A17C */

/* fzgx:begin fn_1_14A1AC */
typedef struct {
    u8 pad_0[0x8];
    u8 unk_8;
    u8 unk_9;
} fn_1_14A1AC_Obj_1_bss_3C30;


void fn_1_14A1AC(u8 arg) {
    if ((*((s16 *)&lbl_1_bss_960)) == 1) {
        lbl_1_bss_8E548 = 4;
        return;
    }

    switch (arg) {
    case 5:
    case 6:
        lbl_1_bss_8E548 = 4;
        return;
    case 3:
        lbl_1_bss_8E548 = (*((fn_1_14A1AC_Obj_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_9 < 6 ? (*((fn_1_14A1AC_Obj_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_9 : 6;
        return;
    case 4:
        lbl_1_bss_8E548 = (*((fn_1_14A1AC_Obj_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_8 < 6 ? (*((fn_1_14A1AC_Obj_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_8 : 6;
        return;
    default:
        lbl_1_bss_8E548 = (*((fn_1_14A1AC_Obj_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_9 < 6 ? (*((fn_1_14A1AC_Obj_1_bss_3C30 *)&lbl_1_bss_3C30)).unk_9 : 6;
        return;
    }
}
/* fzgx:end fn_1_14A1AC */

/* fzgx:begin fn_1_14A278 */
// fn_1_14A278: empty in retail (single blr).
void fn_1_14A278(void) {
}
/* fzgx:end fn_1_14A278 */

/* fzgx:begin fn_1_14A27C */
// fn_1_14A27C: empty in retail (single blr).
void fn_1_14A27C(void) {
}
/* fzgx:end fn_1_14A27C */

/* fzgx:begin fn_1_14A280 */
// fn_1_14A280: empty in retail (single blr).
void fn_1_14A280(void) {
}
/* fzgx:end fn_1_14A280 */

/* fzgx:begin fn_1_14A284 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern void *fn_1_5910(void);
extern s32 fn_1_149FB4(void *obj);
extern int fn_1_3F864(void);
extern void fn_1_A52B0(u8 value);
extern void fn_1_A2D84(u32 value);

void fn_1_14A284(void) {
    void *obj;
    s32 value;
    s32 ok;

    obj = fn_1_5910();
    fn_1_149FB4(obj);
    if (fn_1_3F864() != 0) {
        if (lbl_1_bss_3C30.unk_5 == 2) {
            value = fn_1_149FB4(obj);
            ok = (value + 1 > 30) ? 0 : (value + 1 >= 1);
            if (ok != 0) {
                fn_1_A52B0((u8)(value + 1));
            }
        } else {
            fn_1_A2D84(0xA9071F00);
        }
    }
}
/* fzgx:end fn_1_14A284 */

/* fzgx:begin fn_1_14A328 noprologue */
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"

/* begin rel/main_rel/game.h (deltawave784/windows-and-types@cf9407c75) */
#ifndef REL_MAIN_REL_GAME_H
#define REL_MAIN_REL_GAME_H

/* begin rel/main_rel/globals.h (deltawave784/windows-and-types@cf9407c75) */
#ifndef REL_MAIN_REL_GLOBALS_H
#define REL_MAIN_REL_GLOBALS_H


// Generated by `fzgx headers --module main_rel`: layouts recovered from every access in the
// module's disassembly (matched or not). Field names are offsets until the librarian names them;
// offsets and widths are facts, names are not. Regenerate rather than hand-edit padding.

// lbl_1_bss_960: .bss size 0x2, referenced by 110 functions, shape {'object': 231}
extern s16 lbl_1_bss_960;

// lbl_1_bss_3C30: .bss size 0x14BC, referenced by 95 functions, shape {'object': 411}
typedef struct {
    u32 unk_0;  // 35 loads, 5 stores
    u8 unk_4;  // 3 loads, 0 stores
    u8 unk_5;  // 34 loads, 2 stores
    u8 unk_6;  // 12 loads, 0 stores
    u8 unk_7;  // 1 loads, 0 stores
    u8 unk_8;  // 47 loads, 0 stores
    u8 unk_9;  // 55 loads, 0 stores
    u8 pad_A[0x3];
    u8 unk_D;  // 1 loads, 0 stores
    u8 unk_E;  // 4 loads, 0 stores
    u8 unk_F;  // 1 loads, 0 stores
    u8 pad_10[0x1C];
    u32 unk_2C;  // 1 loads, 0 stores
    u8 pad_30[0x74];
    u16 unk_A4;  // 2 loads, 0 stores
    u8 unk_A6;  // 3 loads, 0 stores
    u8 unk_A7;  // 39 loads, 0 stores
    u8 pad_A8[0x2C];
    u32 unk_D4;  // 2 loads, 0 stores
    u16 unk_D8;  // 5 loads, 6 stores
    u16 unk_DA;  // 1 loads, 2 stores
    u8 unk_DC;  // 7 loads, 3 stores
    u8 unk_DD;  // 2 loads, 3 stores
    u8 unk_DE;  // 1 loads, 0 stores
    u8 unk_DF;  // 1 loads, 0 stores
    u8 unk_E0;  // 1 loads, 0 stores
    u8 unk_E1;  // 1 loads, 0 stores
    u8 unk_E2;  // 1 loads, 2 stores
    u8 pad_E3[0x4];
    u8 unk_E7;  // 0 loads, 2 stores
    u8 pad_E8[0x4];
    u16 unk_EC;  // 1 loads, 2 stores
    u8 pad_EE[0xA];
    u32 unk_F8;  // 2 loads, 1 stores
    u8 pad_FC[0x10];
    u32 unk_10C;  // 1 loads, 1 stores
    u8 pad_110[0x10];
    u16 unk_120;  // 3 loads, 3 stores
    u16 unk_122;  // 1 loads, 0 stores
    u16 unk_124;  // 1 loads, 0 stores
    u16 unk_126;  // 1 loads, 0 stores
    u16 unk_128;  // 1 loads, 0 stores
    u8 pad_12A[0x2];
    u32 unk_12C;  // 0 loads, 1 stores
    u8 pad_130[0x1C];
    u32 unk_14C;  // 2 loads, 3 stores
    u8 pad_150[0x4];
    u8 unk_154;  // 4 loads, 0 stores
    u8 unk_155;  // 2 loads, 0 stores
    u8 unk_156;  // 3 loads, 0 stores
    u8 unk_157;  // 1 loads, 3 stores
    u8 pad_158[0x1A];
    u16 unk_172;  // 1 loads, 2 stores
    u8 pad_174[0x4];
    u16 unk_178;  // 0 loads, 1 stores
    u8 pad_17A[0x1];
    u8 unk_17B;  // 7 loads, 0 stores
    u8 unk_17C;  // 0 loads, 1 stores
    u8 pad_17D[0x7A];
    u8 unk_1F7;  // 0 loads, 1 stores
    u8 pad_1F8[0x20];
    u16 unk_218;  // 0 loads, 1 stores
    u8 pad_21A[0x2];
    u8 unk_21C;  // 0 loads, 1 stores
    u8 pad_21D[0x7A];
    u8 unk_297;  // 0 loads, 1 stores
    u8 pad_298[0x20];
    u16 unk_2B8;  // 0 loads, 1 stores
    u8 pad_2BA[0x2];
    u8 unk_2BC;  // 0 loads, 1 stores
    u8 pad_2BD[0x7A];
    u8 unk_337;  // 0 loads, 1 stores
    u8 pad_338[0x20];
    u16 unk_358;  // 0 loads, 1 stores
    u8 pad_35A[0x2];
    u8 unk_35C;  // 0 loads, 1 stores
    u8 pad_35D[0x7A];
    u8 unk_3D7;  // 0 loads, 1 stores
    u8 pad_3D8[0x20];
    u16 unk_3F8;  // 0 loads, 1 stores
    u8 pad_3FA[0x2];
    u8 unk_3FC;  // 0 loads, 1 stores
    u8 pad_3FD[0x7A];
    u8 unk_477;  // 0 loads, 1 stores
    u8 pad_478[0xF1C];
    u8 unk_1394;  // 1 loads, 0 stores
    u8 pad_1395[0x1F];
    u32 unk_13B4;  // 2 loads, 1 stores
    u8 pad_13B8[0x1C];
    u32 unk_13D4;  // 1 loads, 1 stores
    u8 pad_13D8[0x1C];
    u8 unk_13F4;  // 4 loads, 1 stores
    u8 unk_13F5;  // 3 loads, 1 stores
    u8 unk_13F6;  // 2 loads, 0 stores
    u8 pad_13F7[0x1];
    u16 unk_13F8;  // 0 loads, 1 stores
    u16 unk_13FA;  // 0 loads, 1 stores
    u16 unk_13FC;  // 0 loads, 1 stores
    u16 unk_13FE;  // 0 loads, 1 stores
    u16 unk_1400;  // 0 loads, 1 stores
    u8 unk_1402;  // 0 loads, 1 stores
    u8 pad_1403[0x2];
    u8 unk_1405;  // 2 loads, 0 stores
    u8 pad_1406[0x5E];
    u32 unk_1464;  // 5 loads, 1 stores
    u8 pad_1468[0x4];
    u8 unk_146C;  // 1 loads, 1 stores
    u8 unk_146D;  // 1 loads, 1 stores
    u16 unk_146E;  // 1 loads, 1 stores
    u8 unk_1470;  // 1 loads, 1 stores
    u8 pad_1471[0x3];
    u32 unk_1474;  // 3 loads, 1 stores
    u16 unk_1478;  // 2 loads, 1 stores
    u16 unk_147A;  // 0 loads, 1 stores
    u16 unk_147C;  // 0 loads, 1 stores
    u16 unk_147E;  // 0 loads, 1 stores
    u32 unk_1480;  // 3 loads, 1 stores
    u32 unk_1484;  // 0 loads, 1 stores
    u32 unk_1488;  // 0 loads, 1 stores
    u32 unk_148C;  // 0 loads, 1 stores
    u32 unk_1490;  // 0 loads, 1 stores
    u32 unk_1494;  // 0 loads, 1 stores
    u32 unk_1498;  // 0 loads, 1 stores
    u32 unk_149C;  // 0 loads, 1 stores
    u32 unk_14A0;  // 0 loads, 1 stores
    u32 unk_14A4;  // 0 loads, 1 stores
    u32 unk_14A8;  // 1 loads, 1 stores
    u8 pad_14AC[0x10];
} Obj_1_bss_3C30;
extern Obj_1_bss_3C30 lbl_1_bss_3C30;

// lbl_1_bss_9F8: .bss size 0x50, referenced by 67 functions, shape {'object': 304}
typedef struct {
    u16 unk_0;  // 25 loads, 0 stores
    u16 unk_2;  // 35 loads, 0 stores
    u8 pad_4[0x4];
    u16 unk_8;  // 108 loads, 0 stores
    u16 unk_A;  // 22 loads, 0 stores
    u8 pad_C[0x4];
    u16 unk_10;  // 56 loads, 0 stores
    u16 unk_12;  // 53 loads, 0 stores
    u8 pad_14[0x3C];
} Obj_1_bss_9F8;
extern Obj_1_bss_9F8 lbl_1_bss_9F8;

#endif  // REL_MAIN_REL_GLOBALS_H

// lbl_1_bss_25BA0: .bss size 0xA8, 5 refs from game.c
#ifndef FZGX_TYPES_LBL_1_BSS_25BA0
#define FZGX_TYPES_LBL_1_BSS_25BA0
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u32 unk_0;  // 11 loads, 4 stores
    u8 pad_4[0xA4];
} Obj_1_bss_25BA0;
#endif
extern Obj_1_bss_25BA0 lbl_1_bss_25BA0;

#endif  // REL_MAIN_REL_GAME_H
#ifndef REL_MAIN_REL_SEL_STATIC_DISP_H
#define REL_MAIN_REL_SEL_STATIC_DISP_H

// lbl_1_bss_25BA0: .bss size 0xA8, 7 refs from sel_static_disp.c
#ifndef FZGX_TYPES_LBL_1_BSS_25BA0
#define FZGX_TYPES_LBL_1_BSS_25BA0
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u32 unk_0;  // 11 loads, 4 stores
    u8 pad_4[0xA4];
} Obj_1_bss_25BA0;
#endif
extern Obj_1_bss_25BA0 lbl_1_bss_25BA0;

#endif  // REL_MAIN_REL_SEL_STATIC_DISP_H

extern f64 lbl_1_rodata_99B0;
extern int fn_1_8623C(void);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_8E518;
u8 lbl_1_bss_8E518__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E51D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
u32 fzgx_obj_lbl_1_bss_8E520;
u8 fzgx_obj_lbl_1_bss_8E524;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E525;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
u32 fzgx_obj_lbl_1_bss_8E528;
u8 fzgx_obj_lbl_1_bss_8E52C;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
u8 lbl_1_bss_8E530;
u8 lbl_1_bss_8E530__fzgx_offset_1;
u16 lbl_1_bss_8E530__fzgx_offset_2;
u32 lbl_1_bss_8E534;
u32 lbl_1_bss_8E538;
u32 lbl_1_bss_8E53C;
u32 fzgx_obj_lbl_1_bss_8E540;
u32 fzgx_obj_lbl_1_bss_8E544;
u8 fzgx_obj_lbl_1_bss_8E548;
u8 lbl_1_bss_8E548__fzgx_offset_1;
u16 lbl_1_bss_8E548__fzgx_offset_2;
u32 lbl_1_bss_8E548__fzgx_offset_4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E518;
    s = *(u8 *)&lbl_1_bss_8E518__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E51D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E520;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E524;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E528;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E52C;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
    s = *(u8 *)&lbl_1_bss_8E530;
    s = *(u8 *)&lbl_1_bss_8E530__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_8E530__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_8E534;
    s = *(u8 *)&lbl_1_bss_8E538;
    s = *(u8 *)&lbl_1_bss_8E53C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E540;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E544;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E548;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_4;
}
#pragma section code_type ".text"

void fn_1_14A328(void) {
    Obj_1_bss_3C30 *p_lbl_1_bss_3C30;
    f32 v0;
    s32 v1;
    u8 v2;
    void * v3;
    void * v4;
    u8 v5;
    s32 v6;
    s32 v7;
    u8 v8;
    u32 v9;
    u32 v10;
    void * v12;
    void * v11;
    u8 v13;
    s32 v14;
    s32 v15;
    u8 v16;
    u8 v17;
    u8 v18;
    void * v19;
    void * v20;
    u8 v21;
    s32 v22;
    s32 v23;
    u8 v24;
    u32 v25;
    u32 v26;
    void * v28;
    void * v27;
    u8 v29;
    s32 v30;
    s32 v31;
    u8 v32;
    u8 v33;
    void * v34;
    void * v35;
    u8 v36;
    s32 v37;
    s32 v38;
    u8 v39;
    u32 v40;
    u32 v41;
    void * v43;
    void * v42;
    u8 v44;
    s32 v45;
    s32 v46;
    u8 v47;
    u8 v48;
    int t0;
    int t1;
    int t2;
    int t3;
    int t4;
    int t5;

    if ((s32)lbl_1_bss_25BA0.unk_0 == 0 && ((lbl_1_bss_9F8.unk_8 >> 8) & 0x1) != 0) {
    p_lbl_1_bss_3C30 = &lbl_1_bss_3C30;
    if ((p_lbl_1_bss_3C30->unk_0 & 0x4000000) != 0) {
    v2 = p_lbl_1_bss_3C30->unk_9;
    if (v2 >= 2) {
    fzgx_obj_lbl_1_bss_8E51D = 7;
    lbl_1_bss_8E518__fzgx_offset_4 = 0;
    if (lbl_1_bss_960 == 1) {
    fzgx_obj_lbl_1_bss_8E548 = 4;
    } else {
    fzgx_obj_lbl_1_bss_8E548 = v2 < 6 ? v2 : 6;
    }
    if ((s32)fzgx_obj_lbl_1_bss_8E540 != 0) {
    v3 = (void *)(((u8 *)&lbl_1_bss_8E530));
    v4 = (void *)(((u8 *)&lbl_1_bss_8E538));
    t0 = fn_1_8623C();
    v5 = fzgx_obj_lbl_1_bss_8E548;
    v8 = *((u8 *)&lbl_1_bss_3C30 + t0 * 160 + lbl_1_bss_3C30.unk_A7 + 226);
    v1 = v8 - ((v5 >> 1) - 1);
    lbl_1_bss_8E538 = v8;
    lbl_1_bss_8E538 = v1;
    if (v1 < 0) {
    *(u32 *)((u8 *)v4 + 0) = 0;
    } else {
    v9 = (p_lbl_1_bss_3C30->unk_9 - v5);
    if (v1 >= (s32)v9) {
    *(u32 *)((u8 *)v4 + 0) = v9;
    }
    }
    v10 = *(u32 *)((u8 *)v4 + 0);
    v0 = lbl_1_rodata_99B0;
    *(f32 *)((u8 *)v3 + 0) = (f32)(s32)v10;
    } else {
    v11 = (void *)(((u8 *)&lbl_1_bss_8E530));
    v12 = (void *)(u32)&lbl_1_bss_8E538;
    t1 = fn_1_8623C();
    v13 = fzgx_obj_lbl_1_bss_8E548;
    v1 = *((u8 *)&lbl_1_bss_3C30 + t1 * 160 + lbl_1_bss_3C30.unk_A7 + 226);
    v15 = v1 - ((v13 >> 1) - 1);
    lbl_1_bss_8E538 = v1;
    lbl_1_bss_8E538 = v15;
    if (v15 < 0) {
    *(u32 *)((u8 *)v12 + 0) = 0;
    } else {
    v16 = fzgx_obj_lbl_1_bss_8E51D;
    if (*(s32 *)v12 >= (u8)(v16 == 4 ? lbl_1_bss_3C30.unk_8 : p_lbl_1_bss_3C30->unk_9) - v13) {
    *(s32 *)v12 = (u8)(v16 == 4 ? lbl_1_bss_3C30.unk_8 : p_lbl_1_bss_3C30->unk_9) - v13;
    }
    }
    v17 = v16;
    if (fzgx_obj_lbl_1_bss_8E51D == 4) {
    v1 = (u32)&lbl_1_bss_3C30;
    v17 = *(u8 *)((u8 *)v1 + 8);
    } else {
    v17 = p_lbl_1_bss_3C30->unk_9;
    }
    v1 = 0x43300000;
    v0 = (f32)((f32)(u32)(v17 & 0xFF));
    *(f32 *)((u8 *)v11 + 0) = (f32)(v0 - (f32)(u32)fzgx_obj_lbl_1_bss_8E548);
    }
    } else {
    fzgx_obj_lbl_1_bss_8E51D = 8;
    }
    } else {
    v18 = p_lbl_1_bss_3C30->unk_5;
    switch ((s32)v18) {
    case 1:
    fzgx_obj_lbl_1_bss_8E51D = 1;
    lbl_1_bss_8E518__fzgx_offset_4 = 0;
    if (lbl_1_bss_960 == 1) {
    fzgx_obj_lbl_1_bss_8E548 = 4;
    } else {
    v1 = p_lbl_1_bss_3C30->unk_9;
    fzgx_obj_lbl_1_bss_8E548 = (u32)v1 < 6 ? v1 : 6;
    }
    if ((s32)fzgx_obj_lbl_1_bss_8E540 != 0) {
    v19 = (void *)(((u8 *)&lbl_1_bss_8E530));
    v20 = (void *)(((u8 *)&lbl_1_bss_8E538));
    t2 = fn_1_8623C();
    v21 = fzgx_obj_lbl_1_bss_8E548;
    v24 = *((u8 *)&lbl_1_bss_3C30 + t2 * 160 + lbl_1_bss_3C30.unk_A7 + 226);
    v1 = v24 - ((v21 >> 1) - 1);
    lbl_1_bss_8E538 = v24;
    lbl_1_bss_8E538 = v1;
    if (v1 < 0) {
    *(u32 *)((u8 *)v20 + 0) = 0;
    } else {
    v25 = (lbl_1_bss_3C30.unk_9 - v21);
    if (v1 >= (s32)v25) {
    *(u32 *)((u8 *)v20 + 0) = v25;
    }
    }
    v26 = *(u32 *)((u8 *)v20 + 0);
    v0 = lbl_1_rodata_99B0;
    *(f32 *)((u8 *)v19 + 0) = (f32)(s32)v26;
    } else {
    v27 = (void *)(((u8 *)&lbl_1_bss_8E530));
    v28 = (void *)(((u8 *)&lbl_1_bss_8E538));
    t3 = fn_1_8623C();
    v29 = fzgx_obj_lbl_1_bss_8E548;
    v1 = *((u8 *)&lbl_1_bss_3C30 + t3 * 160 + lbl_1_bss_3C30.unk_A7 + 226);
    v31 = v1 - ((v29 >> 1) - 1);
    lbl_1_bss_8E538 = v1;
    lbl_1_bss_8E538 = v31;
    if (v31 < 0) {
    *(u32 *)((u8 *)v28 + 0) = 0;
    } else {
    v32 = fzgx_obj_lbl_1_bss_8E51D;
    if (*(s32 *)v28 >= (u8)(v32 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v29) {
    *(s32 *)v28 = (u8)(v32 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v29;
    }
    }
    v33 = v32;
    if (fzgx_obj_lbl_1_bss_8E51D == 4) {
    v1 = (u32)&lbl_1_bss_3C30;
    v33 = *(u8 *)((u8 *)v1 + 8);
    } else {
    v1 = (u32)&lbl_1_bss_3C30;
    v33 = *(u8 *)((u8 *)v1 + 9);
    }
    v1 = 0x43300000;
    v0 = (f32)((f32)(u32)(v33 & 0xFF));
    *(f32 *)((u8 *)v27 + 0) = (f32)(v0 - (f32)(u32)fzgx_obj_lbl_1_bss_8E548);
    break;
    case 2:
    fzgx_obj_lbl_1_bss_8E51D = 6;
    break;
    case 0:
case 6:
    fzgx_obj_lbl_1_bss_8E51D = 3;
    lbl_1_bss_8E518__fzgx_offset_4 = 0;
    if (lbl_1_bss_960 == 1) {
    fzgx_obj_lbl_1_bss_8E548 = 4;
    } else {
    v1 = (u32)&lbl_1_bss_3C30;
    v1 = *(u8 *)((u8 *)v1 + 9);
    fzgx_obj_lbl_1_bss_8E548 = (u32)v1 < 6 ? v1 : 6;
    }
    if ((s32)fzgx_obj_lbl_1_bss_8E540 != 0) {
    v34 = (void *)(((u8 *)&lbl_1_bss_8E530));
    v35 = (void *)(((u8 *)&lbl_1_bss_8E538));
    t4 = fn_1_8623C();
    v36 = fzgx_obj_lbl_1_bss_8E548;
    v39 = *((u8 *)&lbl_1_bss_3C30 + t4 * 160 + lbl_1_bss_3C30.unk_A7 + 226);
    v1 = v39 - ((v36 >> 1) - 1);
    lbl_1_bss_8E538 = v39;
    lbl_1_bss_8E538 = v1;
    if (v1 < 0) {
    *(u32 *)((u8 *)v35 + 0) = 0;
    } else {
    v40 = (lbl_1_bss_3C30.unk_9 - v36);
    if (v1 >= (s32)v40) {
    *(u32 *)((u8 *)v35 + 0) = v40;
    }
    }
    v41 = *(u32 *)((u8 *)v35 + 0);
    v0 = lbl_1_rodata_99B0;
    *(f32 *)((u8 *)v34 + 0) = (f32)(s32)v41;
    } else {
    v42 = (void *)(((u8 *)&lbl_1_bss_8E530));
    v43 = (void *)(((u8 *)&lbl_1_bss_8E538));
    t5 = fn_1_8623C();
    v44 = fzgx_obj_lbl_1_bss_8E548;
    v1 = *((u8 *)&lbl_1_bss_3C30 + t5 * 160 + lbl_1_bss_3C30.unk_A7 + 226);
    v46 = v1 - ((v44 >> 1) - 1);
    lbl_1_bss_8E538 = v1;
    lbl_1_bss_8E538 = v46;
    if (v46 < 0) {
    *(u32 *)((u8 *)v43 + 0) = 0;
    } else {
    v47 = fzgx_obj_lbl_1_bss_8E51D;
    if (*(s32 *)v43 >= (u8)(v47 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v44) {
    *(s32 *)v43 = (u8)(v47 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v44;
    }
    }
    v48 = v47;
    if (fzgx_obj_lbl_1_bss_8E51D == 4) {
    v1 = (u32)&lbl_1_bss_3C30;
    v48 = *(u8 *)((u8 *)v1 + 8);
    } else {
    v1 = (u32)&lbl_1_bss_3C30;
    v48 = *(u8 *)((u8 *)v1 + 9);
    }
    v1 = 0x43300000;
    *(f32 *)((u8 *)v42 + 0) = (f32)(((f32)((f32)(u32)(v48 & 0xFF))) - (f32)(u32)fzgx_obj_lbl_1_bss_8E548);
    break;
    default:
    fzgx_obj_lbl_1_bss_8E51D = 8;
    }
    }
    }
    }
    }
    return;
}
/* fzgx:end fn_1_14A328 */

/* fzgx:begin fn_1_14A9CC */
// fn_1_14A9CC: empty in retail (single blr).
void fn_1_14A9CC(void) {
}
/* fzgx:end fn_1_14A9CC */

/* fzgx:begin fn_1_14A9D0 noprologue */
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;
typedef double f64;

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[95] = {0x82A082A2, 0x82A482A6, 0x82A882A9, 0x82AB82AD, 0x82AF82B1, 0x82B382B5, 0x82B782B9, 0x82BB82BD, 0x82BF82C2, 0x82C482C6, 0x82C882C9, 0x82CA82CB, 0x82CC82CD, 0x82D082D3, 0x82D682D9, 0x82DC82DD, 0x82DE82DF, 0x82E082E2, 0x82E482E6, 0x82E782E8, 0x82E982EA, 0x82EB82ED, 0x82EE82EF, 0x82F082F1, 0x82A482AA, 0x82AC82AE, 0x82B082B2, 0x82B482B6, 0x82B882BA, 0x82BC82BE, 0x82C082C3, 0x82C582C7, 0x82CE82D1, 0x82D482D7, 0x82DA82CF, 0x82D282D5, 0x82D882DB, 0x829F82A1, 0x82A382A5, 0x82A782C1, 0x82E182E3, 0x82E582EC, 0x00000000, 0x83418343, 0x83458347, 0x8349834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x8369836A, 0x836B836C, 0x836D836E, 0x83718374, 0x8377837A, 0x837D837E, 0x83808381, 0x83828384, 0x83868388, 0x8389838A, 0x838B838C, 0x838D838F, 0x83908391, 0x83928393, 0x8394834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618364, 0x83668368, 0x836F8372, 0x83758378, 0x837B8370, 0x83738376, 0x8379837C, 0x83408342, 0x83448346, 0x83488362, 0x83838385, 0x8387838E, 0x00000000, 0x81968196, 0x81960000, 0x83478374, 0x835B838D, 0x00000000, 0x8265817C, 0x82798264, 0x8271826E, 0x00000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
volatile f32 s; volatile f64 d; /* fzgx-allow: S2 pool primer sinks */
s = 0.0f;
d = 4503599627370496.0;
d = 4503601774854144.0;
s = 0.20000000298023224f;
s = 0.10000000149011612f;
s = 0.05999999865889549f;
s = 0.014999999664723873f;
s = -0.10000000149011612f;
s = 0.05000000074505806f;
s = -0.05000000074505806f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; } /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"
struct fn_1_14A9D0_lbl_1_bss_8E518 {
u8 pad_0[0x4];
u8 unk_4;
u8 pad_5[0xB];
u32 unk_10;
u8 pad_14[0x4];
f32 unk_18;
f32 unk_1C;
s32 unk_20;
s32 unk_24;
u8 pad_28[0x8];
u8 unk_30;
u8 pad_31[0x3];
f32 unk_34;
u8 unk_38;
u8 pad_39[0x3];
u32 unk_3C;
};
struct fn_1_14A9D0_lbl_1_bss_9F8 {
u8 pad_0[0x10];
u16 unk_10;
u16 unk_12;
};
extern struct fn_1_14A9D0_lbl_1_bss_8E518 lbl_1_bss_8E518;

static const u8 fzgx_pool_fzgx_unused_rodata_9828[172] = {0x82,0xA0,0x82,0xA2,0x82,0xA4,0x82,0xA6,0x82,0xA8,0x82,0xA9,0x82,0xAB,0x82,0xAD,0x82,0xAF,0x82,0xB1,0x82,0xB3,0x82,0xB5,0x82,0xB7,0x82,0xB9,0x82,0xBB,0x82,0xBD,0x82,0xBF,0x82,0xC2,0x82,0xC4,0x82,0xC6,0x82,0xC8,0x82,0xC9,0x82,0xCA,0x82,0xCB,0x82,0xCC,0x82,0xCD,0x82,0xD0,0x82,0xD3,0x82,0xD6,0x82,0xD9,0x82,0xDC,0x82,0xDD,0x82,0xDE,0x82,0xDF,0x82,0xE0,0x82,0xE2,0x82,0xE4,0x82,0xE6,0x82,0xE7,0x82,0xE8,0x82,0xE9,0x82,0xEA,0x82,0xEB,0x82,0xED,0x82,0xEE,0x82,0xEF,0x82,0xF0,0x82,0xF1,0x82,0xA4,0x82,0xAA,0x82,0xAC,0x82,0xAE,0x82,0xB0,0x82,0xB2,0x82,0xB4,0x82,0xB6,0x82,0xB8,0x82,0xBA,0x82,0xBC,0x82,0xBE,0x82,0xC0,0x82,0xC3,0x82,0xC5,0x82,0xC7,0x82,0xCE,0x82,0xD1,0x82,0xD4,0x82,0xD7,0x82,0xDA,0x82,0xCF,0x82,0xD2,0x82,0xD5,0x82,0xD8,0x82,0xDB,0x82,0x9F,0x82,0xA1,0x82,0xA3,0x82,0xA5,0x82,0xA7,0x82,0xC1,0x82,0xE1,0x82,0xE3,0x82,0xE5,0x82,0xEC,0x00,0x00,0x00,0x00};
const u8 fzgx_pool_lbl_1_rodata_98D4[208] = {0x83,0x41,0x83,0x43,0x83,0x45,0x83,0x47,0x83,0x49,0x83,0x4A,0x83,0x4C,0x83,0x4E,0x83,0x50,0x83,0x52,0x83,0x54,0x83,0x56,0x83,0x58,0x83,0x5A,0x83,0x5C,0x83,0x5E,0x83,0x60,0x83,0x63,0x83,0x65,0x83,0x67,0x83,0x69,0x83,0x6A,0x83,0x6B,0x83,0x6C,0x83,0x6D,0x83,0x6E,0x83,0x71,0x83,0x74,0x83,0x77,0x83,0x7A,0x83,0x7D,0x83,0x7E,0x83,0x80,0x83,0x81,0x83,0x82,0x83,0x84,0x83,0x86,0x83,0x88,0x83,0x89,0x83,0x8A,0x83,0x8B,0x83,0x8C,0x83,0x8D,0x83,0x8F,0x83,0x90,0x83,0x91,0x83,0x92,0x83,0x93,0x83,0x94,0x83,0x4B,0x83,0x4D,0x83,0x4F,0x83,0x51,0x83,0x53,0x83,0x55,0x83,0x57,0x83,0x59,0x83,0x5B,0x83,0x5D,0x83,0x5F,0x83,0x61,0x83,0x64,0x83,0x66,0x83,0x68,0x83,0x6F,0x83,0x72,0x83,0x75,0x83,0x78,0x83,0x7B,0x83,0x70,0x83,0x73,0x83,0x76,0x83,0x79,0x83,0x7C,0x83,0x40,0x83,0x42,0x83,0x44,0x83,0x46,0x83,0x48,0x83,0x62,0x83,0x83,0x83,0x85,0x83,0x87,0x83,0x8E,0x00,0x00,0x00,0x00,0x81,0x96,0x81,0x96,0x81,0x96,0x00,0x00,0x83,0x47,0x83,0x74,0x83,0x5B,0x83,0x8D,0x00,0x00,0x00,0x00,0x82,0x65,0x81,0x7C,0x82,0x79,0x82,0x64,0x82,0x71,0x82,0x6E,0x00,0x00,0x00,0x00};
const f32 fzgx_pool_lbl_1_rodata_99A4 = 0.0f;
const u8 fzgx_pool_lbl_1_rodata_99A8[8] = {0x43,0x30,0x00,0x00,0x00,0x00,0x00,0x00};
const f64 fzgx_pool_lbl_1_rodata_99B0 = 4503601774854144.0;
const f32 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_8 = 0.200000003f;
const f32 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_C = 0.100000001f;
const f32 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_10 = 0.0599999987f;
const f32 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_14 = 0.0149999997f;
const f32 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_18 = -0.100000001f;
const f32 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_1C = 0.0500000007f;
const f32 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_20 = -0.0500000007f;
const u8 fzgx_pool_lbl_1_rodata_99B0__fzgx_offset_24[4] = {0x00,0x00,0x00,0x00};
extern u32 lbl_801A66A4;
extern void fn_1_A2D84(u32);
/* 1 when x is within eps of n */
/* cursor count that fits on the page */
typedef struct lbl_1_bss_9F8_t {
    u8 pad_0[0x10];
    u16 unk_10;
    u16 unk_12;
    u8 pad_14[0x3c];
} lbl_1_bss_9F8_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_1_bss_9F8_t fzgx_obj_lbl_1_bss_9F8;
u32 fzgx_obj_lbl_1_bss_A48[16];
u32 fzgx_obj_lbl_1_bss_A88[6];
u32 fzgx_obj_lbl_1_bss_AA0[84];
u32 lbl_1_bss_BF0[32];
u32 fzgx_obj_lbl_1_bss_C70[20];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_9F8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_A48;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_A88;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_AA0;
    s = *(u8 *)&lbl_1_bss_BF0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_C70;
}
#pragma section code_type ".text"

#pragma opt_dead_assignments off
void fn_1_14A9D0(u8 arg0, s32 arg1, u32 arg2, u32 arg3, s32 arg4, s32 arg5, u8 arg6) {
struct fn_1_14A9D0_lbl_1_bss_8E518 *p;
f32 *pos;
s32 *target;
s32 n;
u32 elapsed;
f32 x;
struct { f32 value; } cur;
struct { f32 value; } lo;
f32 k;
f32 step;
f32 delta;
s32 near;
p = &lbl_1_bss_8E518;
p->unk_38 = arg0;
p->unk_3C = arg3;
if (arg5 != 0) {
pos = &p->unk_1C;
target = &p->unk_24;
} else {
pos = &p->unk_18;
target = &p->unk_20;
}
if ((lbl_801A66A4 - p->unk_10) > arg3) {
if (((fzgx_obj_lbl_1_bss_9F8.unk_10 >> 3) & 1) || ((fzgx_obj_lbl_1_bss_9F8.unk_12 >> 3) & 1)) {
n = *target;
if (n > 0) {
*target = n - 1;
fn_1_A2D84(0xA9010400U);
}
} else if (((fzgx_obj_lbl_1_bss_9F8.unk_10 >> 2) & 1) || ((fzgx_obj_lbl_1_bss_9F8.unk_12 >> 2) & 1)) {
n = *target;
if (n < (s32)(p->unk_38 - p->unk_30)) {
*target = n + 1;
fn_1_A2D84(0xA9010400U);
}
}
}
elapsed = lbl_801A66A4 - p->unk_10;
if (elapsed > arg2) {
if (elapsed >= (*(u32 volatile *)&(p->unk_3C)) /* Retail reloads this field. */) {
cur.value = *pos;
lo.value = 0.0f;
delta = 0.2f * ((f32)*target - cur.value);
*pos = cur.value + delta;
*pos = (((*pos) < (lo.value)) ? (lo.value) : (((*pos) > (((f32)((p)->unk_38 - (p)->unk_30)))) ? (((f32)((p)->unk_38 - (p)->unk_30))) : (*pos))) ;
n = *target;
x = *pos;
near = (((x) > ((f32)n) + (0.1f)) ? 0 : (((x) < ((f32)n) - (0.1f)) ? 0 : 1)) ;
if (near != 0) {
*pos = (f32)n;
}
goto done; /* Retail's settled interpolation path skips the scrolling update below. */
} else if (arg1 != 0) {
if (p->unk_4 != 0) {
k = 0.06f;
} else {
k = 0.015f;
}
step = k * ((f32)*target - *pos);
if (step < 0.0f) {
if (step > -0.1f) {
step = -0.1f;
}
} else if (step < 0.1f) {
step = 0.1f;
}
*pos += step;
} else {
n = *target;
x = *pos;
if ((f32)n > x) {
x += 0.05f;
*pos = (((x) < ((f32)n)) ? (x) : ((f32)n)) ;
} else if ((f32)n < x) {
x += -0.05f;
*pos = (((x) > ((f32)n)) ? (x) : ((f32)n)) ;
}
}
x = *pos;
*pos = (((x) < (0.0f)) ? (0.0f) : (((x) > (((f32)((p)->unk_38 - (p)->unk_30)))) ? (((f32)((p)->unk_38 - (p)->unk_30))) : (x))) ;
if ((s32)p->unk_34 != (s32)*pos) {
fn_1_A2D84(0xA9010500U);
}
p->unk_34 = *pos;
n = *target;
x = *pos;
near = (((x) > ((f32)n) + (0.1f)) ? 0 : (((x) < ((f32)n) - (0.1f)) ? 0 : 1)) ;
if (near != 0) {
*pos = (f32)n;
elapsed = (*(u32 volatile *)&(p->unk_3C)) /* Retail reloads this field. */;
p->unk_10 = (*(volatile u32 *)&lbl_801A66A4) - elapsed;
}
}
done:
if (arg4 != 0) {
return;
}
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_14A9D0 */

/* fzgx:begin fn_1_14AE94 */
void fn_1_14AE94(void) {
    if ((s32)lbl_1_bss_8E540 != 0) {
        lbl_1_bss_8E528 = lbl_801A66A4 - 0xbe;
    }
    if ((s32)lbl_1_bss_8E540 == 0) {
        lbl_1_bss_8E540 = 1;
    }
}
/* fzgx:end fn_1_14AE94 */

/* fzgx:begin fn_1_14AED4 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern Word8 lbl_1_rodata_86D8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern f32 lbl_1_rodata_26F8[22];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_1_rodata_8700[16];
extern const f32 lbl_1_rodata_8740;
extern u16 lbl_1_rodata_8754[10];
extern const f32 lbl_1_rodata_8768;
extern const f32 lbl_1_rodata_876C;
extern const f32 lbl_1_rodata_8770;
extern const f32 lbl_1_rodata_8774;
extern const f32 lbl_1_rodata_8778;
extern u16 fn_1_486C4(u32 value);
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8890;
extern const f32 lbl_1_rodata_8894;
extern const f32 lbl_1_rodata_8898;
extern const f32 lbl_1_rodata_889C;
extern const f32 lbl_1_rodata_8674;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_88A0;
extern const f32 lbl_1_rodata_88A4;
extern const f32 lbl_1_rodata_88A8;
extern const f32 lbl_1_rodata_88AC;
extern const f32 lbl_1_rodata_88B0;
extern const f32 lbl_1_rodata_86C8;
extern const f32 lbl_1_rodata_88B4;
extern const f32 lbl_1_rodata_8844;
extern const f32 lbl_1_rodata_884C;
extern const f32 lbl_1_rodata_88B8;
extern const u32 lbl_1_rodata_8860[6];
extern const u32 lbl_1_rodata_8878[6];
extern s32 fn_1_A5DC4(void);
extern u16 fn_1_48690(u32 unused);
extern void fn_1_52070(u32 value);
extern void fn_1_135D7C(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, f32 arg7, f32 arg8, f32 arg9);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_4965C(u8 value);
extern void fn_1_495C8(void* arg0);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void* arg0);
extern void fn_1_495A0(f32 value);
extern void fn_1_49590(f32 value);
extern u32 fn_1_13F72C(s16 arg0, u32 arg1, f32 farg0);
extern const f32 lbl_1_rodata_85FC;
extern const f32 lbl_1_rodata_8A30;
extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_85E8;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern f32 lbl_1_rodata_8A28;
extern f32 lbl_1_rodata_8A38;
extern f32 lbl_1_rodata_8A3C;
extern f32 lbl_1_rodata_8A40;
extern f32 lbl_1_rodata_8A44;
extern s32 lbl_1_rodata_8A34;
extern void fn_1_137288(int index, void* value0, void* value1, void* value2, s16 selector);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_5233C(void* arg0, void* arg1);
extern u32 fn_1_12F118(void);
extern u8* fn_1_36AD0();
extern void fn_1_1373B0(s16 arg0, u8* arg1, u8* arg2, u8* arg3, s16 arg4);
extern void fn_1_137364();
extern void fn_1_14E9E4(int arg0, void *arg1);
extern const f32 lbl_1_rodata_8840;
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_85F4;
extern int fn_1_D6698(void);
extern void fn_1_D66F8(u8 arg0, u8 *arg1, s8 *arg2);
extern void fn_1_139440(f32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
extern s32 lbl_1_bss_8E3D0[];
extern const f32 lbl_1_rodata_8B9C;
extern const f32 lbl_1_rodata_8BA0;
extern const f32 lbl_1_rodata_8BA4;
extern const f32 lbl_1_rodata_8BA8;
extern const f32 lbl_1_rodata_8664;
extern const f32 lbl_1_rodata_8BAC;
extern const f32 lbl_1_rodata_8BB0;
extern const f32 lbl_1_rodata_8BB4;
extern const f32 lbl_1_rodata_87D0;
extern int fn_1_D6740();
extern int fn_1_D66B0(void);
extern void fn_1_8CED0(void* arg0, int arg1, int arg2);
extern void fn_1_131C08(void);
extern void fn_1_8D3F8(void* arg0, void* arg1, void* arg2, void* arg3);
extern u8 lbl_1_rodata_8558[84];
extern const f32 lbl_1_rodata_8C10;
extern void fn_1_4CF3C(const char *format, f32 x, ...);
extern s16 fn_1_12C930(void* arg0);
extern u8 lbl_1_data_21078[180];
extern f32 fn_1_4B068(const char*);
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8C74;
extern PtrTab lbl_1_rodata_8C4C;
extern s32 fn_1_13B548(s32, s32, s32, u8);
extern const f32 lbl_1_rodata_87AC;
extern const f32 lbl_1_rodata_882C;
extern const f32 lbl_1_rodata_8830;
extern const f32 lbl_1_rodata_8834;
extern const f32 lbl_1_rodata_8A4C;
extern const f32 lbl_1_rodata_8B58;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8BEC;
extern const f32 lbl_1_rodata_8D78;
extern const f32 lbl_1_rodata_8D7C;
extern u16 lbl_1_rodata_8CB0[200];
extern u8 lbl_1_bss_9C;
extern void fn_1_133E04(void* arg0, s32 arg1);
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_140EE8(u8 arg0, int arg1, int arg2);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern void fn_1_138144(void* arg0, int arg1);
extern u32 fn_1_13C5EC(u8);
extern u32 fn_1_13F7F8(s16 arg0, s16 arg1);
extern int sprintf(char *s, const char *format, ...);
extern const f32 lbl_1_rodata_8A54;
extern const f32 lbl_1_rodata_8B30;
extern const f32 lbl_1_rodata_8DBC;
extern const f32 lbl_1_rodata_8DCC;
extern const f32 lbl_1_rodata_87B4;
extern const u32 lbl_1_rodata_8DC0;
extern const f32 lbl_1_rodata_8818;
extern const u32 lbl_1_rodata_8DC4;
extern const f32 lbl_1_rodata_8DD0;
extern const u32 lbl_1_rodata_8DC8;
extern const f32 lbl_1_rodata_8DDC;
extern const f32 lbl_1_rodata_8DE0;
extern const f32 lbl_1_rodata_8DE4;
extern const f32 lbl_1_rodata_8DD4;
extern const f32 lbl_1_rodata_8B34;
extern const f32 lbl_1_rodata_8DD8;
extern const f32 lbl_1_rodata_8A58;
extern int fn_1_B7E98(int index);
extern void fn_1_13EE60();
extern u32 fn_1_13EF64(u32, u32, u32, void *, u32, void *, u32, f32);
extern u32 lbl_1_rodata_8E8C;
extern u8 lbl_1_rodata_8EB4[];
extern char *fn_80083DB0(char *dst, const char *src);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 lbl_1_rodata_91C0[11];
extern const f32 lbl_1_rodata_91EC;
extern const f32 lbl_1_rodata_91F0;
extern void fn_1_141338(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4);
extern u32 fn_1_141360(u32, u32, u32, u32, f32, f32);
extern void fn_1_494DC(s16 index);
extern const f32 lbl_1_rodata_9208;
extern void fn_1_4966C(f32 value1, f32 value2);
extern const f32 lbl_1_rodata_920C;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_9210;
extern u32 lbl_1_rodata_9214[3];
extern u16 lbl_1_rodata_9220[6];
extern const f32 lbl_1_rodata_8E9C;
extern const f64 lbl_1_rodata_93E8;
extern f32 lbl_1_rodata_93F0[15];
extern f32 lbl_1_rodata_92C0[22];
extern f32 lbl_1_rodata_970C[71];
extern const f32 lbl_1_rodata_946C;
extern void fn_1_149C2C();
extern struct fn_1_149C64_lbl_1_bss_8E43C lbl_1_bss_8E43C;
extern struct fn_1_149C64_lbl_1_bss_8E440 lbl_1_bss_8E440;
extern void fn_1_149CA4(u32, u32, u32, u32);
extern void fn_1_520A0(void);
extern f64 lbl_1_rodata_9480[80];
extern f32 lbl_1_rodata_942C[16];
extern f32 fn_1_521B8(s32 value);
extern f32 fn_1_520F8(s32 value);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_1_520CC(void);
extern const f32 lbl_1_rodata_99A4;
extern u8 fn_1_5910(void);
extern u8 fn_1_149FB4(s32 index);
extern s32 fn_1_3F864(void);
extern void fn_1_A52B0(s32 index);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
extern u32 fn_1_1556B4(u32, u32);
extern u32 lbl_801A66A4;
extern void fn_1_14CA4C(void);
extern u8 lbl_1_bss_5138[260];
extern int fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_320A4(void);
extern u8 lbl_1_rodata_9B04[300];
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);
extern void fn_1_12A7C4(const char *src, char *dst, int size);
extern u8 lbl_8015B200[];
extern size_t strlen(const char *str);
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_D3884(void *arg0);
extern void fn_1_14D728(Source *source, Display *displays);
extern void fn_80071718(void *arg0);
extern void fn_800711A8(void *arg0);
extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0();
extern s16 fn_1_14F344(s16);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void fn_1_151C3C(u16 value1, u16 value2);
extern void fn_1_556B8(void *value);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern const f64 lbl_1_rodata_B8D0;
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *fn_800839D8(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
extern void fn_1_1375C0(int arg0, void* arg1, void* arg2, void* arg3, void* arg4);
extern const f32 lbl_1_rodata_8BB8;
extern const f32 lbl_1_rodata_8BBC;
extern void fn_1_131B90(void);
extern void fn_1_13A9B8();
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void fn_1_13E080(void* arg0, void* arg1, void* arg2, int arg3);
extern void fn_1_144F40(u32 arg0, u32 arg1);
extern u8 fn_1_155F8C(void);
extern void fn_1_14BFB8(void);
extern u32 lbl_801A63C0;
extern u32 fn_1_14D6D8(s16 index);
extern void fn_1_14DEC8(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_14E09C();
extern void fn_1_14E1E0();
extern u8 lbl_1_rodata_B884[76];
extern u8 lbl_1_rodata_B8D8[1200];
extern u8 lbl_1_rodata_BD88[2400];
extern u8 lbl_1_rodata_C6E8[1200];
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, u32 arg3);
extern u8 lbl_1_rodata_CCDC[308];
extern void fn_1_14FD7C(u32 *arg0, u32 arg1);
extern void fn_1_9A508(Obj_1_data_2A7E0 *state);
extern void fn_1_9AD54(void);
extern u32 fn_1_9D260(void);
extern void fn_1_150D3C(Obj_1_data_2A7E0_At3C *arg0, u32 arg1);
extern void fn_1_150654(void);
extern void fn_1_151054(Obj_1_data_2A7E0_At3C *arg);
extern void fn_1_103090(void *entry);
extern void fn_1_1030A4(void *entry);
extern void fn_1_103264(void *entry, void *arg);
extern void fn_1_151668(fn_1_151668_StaticDisp *self);
extern const f32 lbl_1_rodata_CF40[];
extern void fn_1_150F74(void *self);
extern s32 fn_1_45D0();
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 fn_80008BEC(u32 arg0, int arg1, int arg2);
extern void fn_1_7F3AC(void* object);


extern u32 lbl_801A66A4;
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_3F2A0(void);
extern int fn_1_8623C(void);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14CA4C(void);

/* file-scope objects of the retail TU (from a matched sibling), in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_8E518;
u8 lbl_1_bss_8E518__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E51D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
u32 fzgx_obj_lbl_1_bss_8E520;
u8 fzgx_obj_lbl_1_bss_8E524;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E525;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
u32 fzgx_obj_lbl_1_bss_8E528;
u8 fzgx_obj_lbl_1_bss_8E52C;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
f32 lbl_1_bss_8E530;
f32 lbl_1_bss_8E534;
s32 lbl_1_bss_8E538;
s32 lbl_1_bss_8E53C;
s32 fzgx_obj_lbl_1_bss_8E540;
s32 fzgx_obj_lbl_1_bss_8E544;
u8 fzgx_obj_lbl_1_bss_8E548;
u8 lbl_1_bss_8E548__fzgx_offset_1;
u16 lbl_1_bss_8E548__fzgx_offset_2;
u32 lbl_1_bss_8E548__fzgx_offset_4;
u8 lbl_1_bss_8E550;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E551;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E551_fill_8E552;
u32 lbl_1_bss_8E554;
u8 lbl_1_bss_8E554__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E559;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E55A;
u32 lbl_1_bss_8E55C;
u32 lbl_1_bss_8E560[4];
u32 lbl_1_bss_8E570[7];
s32 lbl_1_bss_8E570__fzgx_offset_1C;
u32 lbl_1_bss_8E570__fzgx_offset_20;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E518;
    s = *(u8 *)&lbl_1_bss_8E518__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E51D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E520;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E524;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E528;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E52C;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
    s = *(u8 *)&lbl_1_bss_8E530;
    s = *(u8 *)&lbl_1_bss_8E534;
    s = *(u8 *)&lbl_1_bss_8E538;
    s = *(u8 *)&lbl_1_bss_8E53C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E540;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E544;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E548;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_8E550;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E551;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E551_fill_8E552;
    s = *(u8 *)&lbl_1_bss_8E554;
    s = *(u8 *)&lbl_1_bss_8E554__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E559;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E55A;
    s = *(u8 *)&lbl_1_bss_8E55C;
    s = *(u8 *)&lbl_1_bss_8E560;
    s = *(u8 *)&lbl_1_bss_8E570;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_20;
}
#pragma section code_type ".text"


/* number of selectable entries in the current mode */
static inline u8 fn_1_14AED4_sel_max(void) {
    return fzgx_obj_lbl_1_bss_8E51D == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9;
}

static inline void fn_1_14AED4_set_from_list(f32 *pos, s32 *value) {
    u8 v;
    fn_1_3F2A0();
    v = *((u8 *)&lbl_1_bss_3C30 + fn_1_8623C() * 0xA0 + 0xDC);
    lbl_1_bss_8E53C = v;
    lbl_1_bss_8E53C = lbl_1_bss_8E53C - (fzgx_obj_lbl_1_bss_8E548 / 2 - 1);
    if (*value < 0) {
        *value = 0;
    } else if (*value >= lbl_1_bss_3C30.unk_9 - fzgx_obj_lbl_1_bss_8E548) {
        *value = lbl_1_bss_3C30.unk_9 - fzgx_obj_lbl_1_bss_8E548;
    }
    *pos = *value;
}

static inline void fn_1_14AED4_set_from_max(s32 *value, f32 *pos) {
    u8 v;
    fn_1_3F2A0();
    v = *((u8 *)&lbl_1_bss_3C30 + fn_1_8623C() * 0xA0 + 0xDC);
    lbl_1_bss_8E53C = v;
    lbl_1_bss_8E53C = v - (fzgx_obj_lbl_1_bss_8E548 / 2 - 1);
    if (*value < 0) {
        *value = 0;
    } else {
        s32 limit = fn_1_14AED4_sel_max() - fzgx_obj_lbl_1_bss_8E548;
        if (*value >= limit) {
            *value = fn_1_14AED4_sel_max() - fzgx_obj_lbl_1_bss_8E548;
        }
    }
    *pos = (f32)fn_1_14AED4_sel_max() - (f32)fzgx_obj_lbl_1_bss_8E548;
}

void fn_1_14AED4(void) {
    Obj_1_bss_9F8 *flags;

    fn_1_14A9D0(fn_1_14AED4_sel_max(), 1, 30, 180, 1, 0);
    flags = &lbl_1_bss_9F8;
    if (((flags->unk_8 >> 8) & 1) && !((lbl_1_bss_D58.unk_8 >> 12) & 1)) {
        if (lbl_801A66A4 - fzgx_obj_lbl_1_bss_8E528 >= 195) {
            fzgx_obj_lbl_1_bss_8E51D = 2;
            lbl_1_bss_8E518__fzgx_offset_4 = 0;
            if (*(s16 *)&lbl_1_bss_960 == 1) {
                fzgx_obj_lbl_1_bss_8E548 = 4;
            } else {
                fzgx_obj_lbl_1_bss_8E548 = lbl_1_bss_3C30.unk_9 < 6 ? lbl_1_bss_3C30.unk_9 : 6;
            }
            if (fzgx_obj_lbl_1_bss_8E544 != 0) {
                f32 *pos = (f32 *)&lbl_1_bss_8E534;
                s32 *value = (s32 *)&lbl_1_bss_8E53C;
                fn_1_14AED4_set_from_list(pos, value);
            } else {
                s32 *value;
                f32 *pos;
                pos = (f32 *)&lbl_1_bss_8E534;
                value = (s32 *)&lbl_1_bss_8E53C;
                fn_1_14AED4_set_from_max(value, pos);
            }
            fn_1_A2D84(0xA9010400);
        } else {
            fn_1_14CA4C();
        }
    } else if ((flags->unk_8 >> 9) & 1) {
        fzgx_obj_lbl_1_bss_8E51D = 0;
        fn_1_A2D84(0xA9010400);
    }
}
/* fzgx:end fn_1_14AED4 */

/* fzgx:begin fn_1_14B1B8 */
// fn_1_14B1B8: empty in retail (single blr).
void fn_1_14B1B8(void) {
}
/* fzgx:end fn_1_14B1B8 */

/* fzgx:begin fn_1_14B1BC */
void fn_1_14B1BC(void) {
    int flag = lbl_1_bss_8E544;

    if (flag != 0) {
        lbl_1_bss_8E528 = lbl_801A66A4 - 0xbe;
    }
    if (flag == 0) {
        lbl_1_bss_8E544 = 1;
    }
}
/* fzgx:end fn_1_14B1BC */

/* fzgx:begin fn_1_14B1FC noprologue */
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"

/* begin rel/main_rel/game.h (deltawave784/fzgx@13b0aeca (CC0)) */
#ifndef REL_MAIN_REL_GAME_H
#define REL_MAIN_REL_GAME_H

/* begin rel/main_rel/globals.h (deltawave784/fzgx@13b0aeca (CC0)) */
#ifndef REL_MAIN_REL_GLOBALS_H
#define REL_MAIN_REL_GLOBALS_H


// Generated by `fzgx headers --module main_rel`: layouts recovered from every access in the
// module's disassembly (matched or not). Field names are offsets until the librarian names them;
// offsets and widths are facts, names are not. Regenerate rather than hand-edit padding.

// lbl_1_bss_960: .bss size 0x2, referenced by 110 functions, shape {'object': 231}
extern s16 lbl_1_bss_960;

// lbl_1_bss_3C30: .bss size 0x14BC, referenced by 95 functions, shape {'object': 411}
typedef struct {
    u32 unk_0;  // 35 loads, 5 stores
    u8 unk_4;  // 3 loads, 0 stores
    u8 unk_5;  // 34 loads, 2 stores
    u8 unk_6;  // 12 loads, 0 stores
    u8 unk_7;  // 1 loads, 0 stores
    u8 unk_8;  // 47 loads, 0 stores
    u8 unk_9;  // 55 loads, 0 stores
    u8 pad_A[0x3];
    u8 unk_D;  // 1 loads, 0 stores
    u8 unk_E;  // 4 loads, 0 stores
    u8 unk_F;  // 1 loads, 0 stores
    u8 pad_10[0x1C];
    u32 unk_2C;  // 1 loads, 0 stores
    u8 pad_30[0x74];
    u16 unk_A4;  // 2 loads, 0 stores
    u8 unk_A6;  // 3 loads, 0 stores
    u8 unk_A7;  // 39 loads, 0 stores
    u8 pad_A8[0x2C];
    u32 unk_D4;  // 2 loads, 0 stores
    u16 unk_D8;  // 5 loads, 6 stores
    u16 unk_DA;  // 1 loads, 2 stores
    u8 unk_DC;  // 7 loads, 3 stores
    u8 unk_DD;  // 2 loads, 3 stores
    u8 unk_DE;  // 1 loads, 0 stores
    u8 unk_DF;  // 1 loads, 0 stores
    u8 unk_E0;  // 1 loads, 0 stores
    u8 unk_E1;  // 1 loads, 0 stores
    u8 unk_E2;  // 1 loads, 2 stores
    u8 pad_E3[0x4];
    u8 unk_E7;  // 0 loads, 2 stores
    u8 pad_E8[0x4];
    u16 unk_EC;  // 1 loads, 2 stores
    u8 pad_EE[0xA];
    u32 unk_F8;  // 2 loads, 1 stores
    u8 pad_FC[0x10];
    u32 unk_10C;  // 1 loads, 1 stores
    u8 pad_110[0x10];
    u16 unk_120;  // 3 loads, 3 stores
    u16 unk_122;  // 1 loads, 0 stores
    u16 unk_124;  // 1 loads, 0 stores
    u16 unk_126;  // 1 loads, 0 stores
    u16 unk_128;  // 1 loads, 0 stores
    u8 pad_12A[0x2];
    u32 unk_12C;  // 0 loads, 1 stores
    u8 pad_130[0x1C];
    u32 unk_14C;  // 2 loads, 3 stores
    u8 pad_150[0x4];
    u8 unk_154;  // 4 loads, 0 stores
    u8 unk_155;  // 2 loads, 0 stores
    u8 unk_156;  // 3 loads, 0 stores
    u8 unk_157;  // 1 loads, 3 stores
    u8 pad_158[0x1A];
    u16 unk_172;  // 1 loads, 2 stores
    u8 pad_174[0x4];
    u16 unk_178;  // 0 loads, 1 stores
    u8 pad_17A[0x1];
    u8 unk_17B;  // 7 loads, 0 stores
    u8 unk_17C;  // 0 loads, 1 stores
    u8 pad_17D[0x7A];
    u8 unk_1F7;  // 0 loads, 1 stores
    u8 pad_1F8[0x20];
    u16 unk_218;  // 0 loads, 1 stores
    u8 pad_21A[0x2];
    u8 unk_21C;  // 0 loads, 1 stores
    u8 pad_21D[0x7A];
    u8 unk_297;  // 0 loads, 1 stores
    u8 pad_298[0x20];
    u16 unk_2B8;  // 0 loads, 1 stores
    u8 pad_2BA[0x2];
    u8 unk_2BC;  // 0 loads, 1 stores
    u8 pad_2BD[0x7A];
    u8 unk_337;  // 0 loads, 1 stores
    u8 pad_338[0x20];
    u16 unk_358;  // 0 loads, 1 stores
    u8 pad_35A[0x2];
    u8 unk_35C;  // 0 loads, 1 stores
    u8 pad_35D[0x7A];
    u8 unk_3D7;  // 0 loads, 1 stores
    u8 pad_3D8[0x20];
    u16 unk_3F8;  // 0 loads, 1 stores
    u8 pad_3FA[0x2];
    u8 unk_3FC;  // 0 loads, 1 stores
    u8 pad_3FD[0x7A];
    u8 unk_477;  // 0 loads, 1 stores
    u8 pad_478[0xF1C];
    u8 unk_1394;  // 1 loads, 0 stores
    u8 pad_1395[0x1F];
    u32 unk_13B4;  // 2 loads, 1 stores
    u8 pad_13B8[0x1C];
    u32 unk_13D4;  // 1 loads, 1 stores
    u8 pad_13D8[0x1C];
    u8 unk_13F4;  // 4 loads, 1 stores
    u8 unk_13F5;  // 3 loads, 1 stores
    u8 unk_13F6;  // 2 loads, 0 stores
    u8 pad_13F7[0x1];
    u16 unk_13F8;  // 0 loads, 1 stores
    u16 unk_13FA;  // 0 loads, 1 stores
    u16 unk_13FC;  // 0 loads, 1 stores
    u16 unk_13FE;  // 0 loads, 1 stores
    u16 unk_1400;  // 0 loads, 1 stores
    u8 unk_1402;  // 0 loads, 1 stores
    u8 pad_1403[0x2];
    u8 unk_1405;  // 2 loads, 0 stores
    u8 pad_1406[0x5E];
    u32 unk_1464;  // 5 loads, 1 stores
    u8 pad_1468[0x4];
    u8 unk_146C;  // 1 loads, 1 stores
    u8 unk_146D;  // 1 loads, 1 stores
    u16 unk_146E;  // 1 loads, 1 stores
    u8 unk_1470;  // 1 loads, 1 stores
    u8 pad_1471[0x3];
    u32 unk_1474;  // 3 loads, 1 stores
    u16 unk_1478;  // 2 loads, 1 stores
    u16 unk_147A;  // 0 loads, 1 stores
    u16 unk_147C;  // 0 loads, 1 stores
    u16 unk_147E;  // 0 loads, 1 stores
    u32 unk_1480;  // 3 loads, 1 stores
    u32 unk_1484;  // 0 loads, 1 stores
    u32 unk_1488;  // 0 loads, 1 stores
    u32 unk_148C;  // 0 loads, 1 stores
    u32 unk_1490;  // 0 loads, 1 stores
    u32 unk_1494;  // 0 loads, 1 stores
    u32 unk_1498;  // 0 loads, 1 stores
    u32 unk_149C;  // 0 loads, 1 stores
    u32 unk_14A0;  // 0 loads, 1 stores
    u32 unk_14A4;  // 0 loads, 1 stores
    u32 unk_14A8;  // 1 loads, 1 stores
    u8 pad_14AC[0x10];
} Obj_1_bss_3C30;
extern Obj_1_bss_3C30 lbl_1_bss_3C30;

// lbl_1_bss_9F8: .bss size 0x50, referenced by 67 functions, shape {'object': 304}
typedef struct {
    u16 unk_0;  // 25 loads, 0 stores
    u16 unk_2;  // 35 loads, 0 stores
    u8 pad_4[0x4];
    u16 unk_8;  // 108 loads, 0 stores
    u16 unk_A;  // 22 loads, 0 stores
    u8 pad_C[0x4];
    u16 unk_10;  // 56 loads, 0 stores
    u16 unk_12;  // 53 loads, 0 stores
    u8 pad_14[0x3C];
} Obj_1_bss_9F8;
extern Obj_1_bss_9F8 lbl_1_bss_9F8;

#endif  // REL_MAIN_REL_GLOBALS_H

// lbl_1_bss_25BA0: .bss size 0xA8, 5 refs from game.c
#ifndef FZGX_TYPES_LBL_1_BSS_25BA0
#define FZGX_TYPES_LBL_1_BSS_25BA0
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u32 unk_0;  // 11 loads, 4 stores
    u8 pad_4[0xA4];
} Obj_1_bss_25BA0;
#endif
extern Obj_1_bss_25BA0 lbl_1_bss_25BA0;

// lbl_1_bss_D58: .bss size 0x18, 2 refs from game.c
#ifndef FZGX_TYPES_LBL_1_BSS_D58
#define FZGX_TYPES_LBL_1_BSS_D58
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u16 unk_0;  // 5 loads, 0 stores
    u16 unk_2;  // 1 loads, 0 stores
    u8 pad_4[0x4];
    u16 unk_8;  // 24 loads, 0 stores
    u16 unk_A;  // 3 loads, 0 stores
    u8 pad_C[0x4];
    u16 unk_10;  // 18 loads, 0 stores
    u16 unk_12;  // 4 loads, 0 stores
    u8 pad_14[0x4];
} Obj_1_bss_D58;
#endif
extern Obj_1_bss_D58 lbl_1_bss_D58;

#endif  // REL_MAIN_REL_GAME_H
#ifndef REL_MAIN_REL_SEL_STATIC_DISP_H
#define REL_MAIN_REL_SEL_STATIC_DISP_H

// lbl_1_bss_25BA0: .bss size 0xA8, 7 refs from sel_static_disp.c
#ifndef FZGX_TYPES_LBL_1_BSS_25BA0
#define FZGX_TYPES_LBL_1_BSS_25BA0
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u32 unk_0;  // 11 loads, 4 stores
    u8 pad_4[0xA4];
} Obj_1_bss_25BA0;
#endif
extern Obj_1_bss_25BA0 lbl_1_bss_25BA0;

// lbl_1_bss_D58: .bss size 0x18, 6 refs from sel_static_disp.c
#ifndef FZGX_TYPES_LBL_1_BSS_D58
#define FZGX_TYPES_LBL_1_BSS_D58
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u16 unk_0;  // 5 loads, 0 stores
    u16 unk_2;  // 1 loads, 0 stores
    u8 pad_4[0x4];
    u16 unk_8;  // 24 loads, 0 stores
    u16 unk_A;  // 3 loads, 0 stores
    u8 pad_C[0x4];
    u16 unk_10;  // 18 loads, 0 stores
    u16 unk_12;  // 4 loads, 0 stores
    u8 pad_14[0x4];
} Obj_1_bss_D58;
#endif
extern Obj_1_bss_D58 lbl_1_bss_D58;

#endif  // REL_MAIN_REL_SEL_STATIC_DISP_H

/* end rel/main_rel/sel_static_disp.h */

extern u32 lbl_801A66A4;
extern void fn_1_3F2A0(void);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_A2D84(u32);
extern void fn_1_14CA4C(void);
extern int fn_1_8623C(void);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_8E518;
u8 lbl_1_bss_8E518__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E51D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
u32 fzgx_obj_lbl_1_bss_8E520;
u8 fzgx_obj_lbl_1_bss_8E524;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E525;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
u32 fzgx_obj_lbl_1_bss_8E528;
u8 fzgx_obj_lbl_1_bss_8E52C;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
f32 lbl_1_bss_8E530;
u32 lbl_1_bss_8E534;
s32 lbl_1_bss_8E538;
u32 lbl_1_bss_8E53C;
s32 fzgx_obj_lbl_1_bss_8E540;
u32 fzgx_obj_lbl_1_bss_8E544;
u8 fzgx_obj_lbl_1_bss_8E548;
u8 lbl_1_bss_8E548__fzgx_offset_1;
u16 lbl_1_bss_8E548__fzgx_offset_2;
u32 lbl_1_bss_8E548__fzgx_offset_4;
u8 lbl_1_bss_8E550;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E551;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E551_fill_8E552;
u32 lbl_1_bss_8E554;
u8 lbl_1_bss_8E554__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E559;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E55A;
u32 lbl_1_bss_8E55C;
u32 lbl_1_bss_8E560[4];
u32 lbl_1_bss_8E570[7];
s32 lbl_1_bss_8E570__fzgx_offset_1C;
u32 lbl_1_bss_8E570__fzgx_offset_20;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E518;
    s = *(u8 *)&lbl_1_bss_8E518__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E51D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E520;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E524;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E528;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E52C;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
    s = *(u8 *)&lbl_1_bss_8E530;
    s = *(u8 *)&lbl_1_bss_8E534;
    s = *(u8 *)&lbl_1_bss_8E538;
    s = *(u8 *)&lbl_1_bss_8E53C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E540;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E544;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E548;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_8E550;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E551;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E551_fill_8E552;
    s = *(u8 *)&lbl_1_bss_8E554;
    s = *(u8 *)&lbl_1_bss_8E554__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E559;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E55A;
    s = *(u8 *)&lbl_1_bss_8E55C;
    s = *(u8 *)&lbl_1_bss_8E560;
    s = *(u8 *)&lbl_1_bss_8E570;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_20;
}
#pragma section code_type ".text"

/* row count of the list currently shown */
#define SEL_ROWS() (fzgx_obj_lbl_1_bss_8E51D == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9)

void fn_1_14B1FC(void) {
    Obj_1_bss_9F8 *flags;
    u8 mode;

    fn_1_3F2A0();
    if ((s32)lbl_1_bss_25BA0.unk_0 != 0) {
        return;
    }

    if (fzgx_obj_lbl_1_bss_8E51D == 4) {
        mode = lbl_1_bss_3C30.unk_8;
    } else {
        mode = lbl_1_bss_3C30.unk_9;
    }
    fn_1_14A9D0(mode, 1, 30, 180, 0, 1);

    flags = &lbl_1_bss_9F8;
    if (((flags->unk_8 >> 8) & 1) != 0) {
        if (((lbl_1_bss_D58.unk_8 >> 12) & 1) == 0) {
            if (lbl_801A66A4 - fzgx_obj_lbl_1_bss_8E528 >= 0xC3) {
                fzgx_obj_lbl_1_bss_8E51D = 8;
                fn_1_A2D84(0xA9010400);
            } else {
                fn_1_14CA4C();
            }
            return;
        }
    }
    if (((flags->unk_8 >> 9) & 1) != 0) {
        fzgx_obj_lbl_1_bss_8E51D = 1;
        lbl_1_bss_8E518__fzgx_offset_4 = 0;
        if (lbl_1_bss_960 == 1) {
            fzgx_obj_lbl_1_bss_8E548 = 4;
        } else {
            fzgx_obj_lbl_1_bss_8E548 = lbl_1_bss_3C30.unk_9 < 6 ? lbl_1_bss_3C30.unk_9 : 6;
        }
        if (fzgx_obj_lbl_1_bss_8E540 != 0) {
            s32 *idx;
            f32 *pos;
            s32 v;
            u8 n;
            s32 w;
            s32 max;
            pos = &lbl_1_bss_8E530;
            idx = &lbl_1_bss_8E538;
            v = fn_1_8623C();
            n = fzgx_obj_lbl_1_bss_8E548;
            w = *((u8 *)&lbl_1_bss_3C30 + v * 0xA0 + lbl_1_bss_3C30.unk_A7 + 0xE2);
            lbl_1_bss_8E538 = w;
            lbl_1_bss_8E538 = w - ((u8)(n / 2) - 1);
            w = lbl_1_bss_8E538;
            if (w < 0) {
                *idx = 0;
            } else {
                max = lbl_1_bss_3C30.unk_9 - n;
                if (w >= max) {
                    *idx = max;
                }
            }
            *pos = (f32)*idx;
        } else {
            s32 *idx;
            f32 *pos;
            s32 v;
            u8 n;
            s32 w;
            pos = &lbl_1_bss_8E530;
            idx = &lbl_1_bss_8E538;
            v = fn_1_8623C();
            n = fzgx_obj_lbl_1_bss_8E548;
            w = *((u8 *)&lbl_1_bss_3C30 + v * 0xA0 + lbl_1_bss_3C30.unk_A7 + 0xE2);
            lbl_1_bss_8E538 = w;
            lbl_1_bss_8E538 = w - ((u8)(n / 2) - 1);
            if (lbl_1_bss_8E538 < 0) {
                *idx = 0;
            } else if (*idx >= (u8)SEL_ROWS() - n) {
                *idx = (u8)SEL_ROWS() - n;
            }
            *pos = (f32)(u8)SEL_ROWS() - (f32)fzgx_obj_lbl_1_bss_8E548;
        }
        fn_1_A2D84(0xA9010400);
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_14B1FC */

/* fzgx:begin fn_1_14B4FC */
// fn_1_14B4FC: empty in retail (single blr).
void fn_1_14B4FC(void) {
}
/* fzgx:end fn_1_14B4FC */

/* fzgx:begin fn_1_14B62C noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

typedef struct {
    u8 pad_0[0x4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[0xA];
    u32 unk_10;
    u8 pad_14[0x8];
    f32 unk_1C;
    u8 pad_20[0x4];
    s32 unk_24;
    u8 pad_28[0x4];
    s32 unk_2C;
    u8 unk_30;
} SelState_8E518;

extern u32 lbl_801A66A4;
extern u32 fn_1_14A9D0(u8, u32, u32, u32, u32, u32);
extern void fn_1_3F2A0(void);
extern int fn_1_8623C(void);
extern void fn_1_A2D84(u32);
extern void fn_1_14CA4C(void);

/* file-scope objects of the retail TU (from a matched sibling), in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_8E518;
u8 lbl_1_bss_8E518__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E51D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
u32 fzgx_obj_lbl_1_bss_8E520;
u8 fzgx_obj_lbl_1_bss_8E524;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E525;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
u32 fzgx_obj_lbl_1_bss_8E528;
u8 fzgx_obj_lbl_1_bss_8E52C;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
f32 lbl_1_bss_8E530;
u32 lbl_1_bss_8E534;
s32 lbl_1_bss_8E538;
u32 lbl_1_bss_8E53C;
s32 fzgx_obj_lbl_1_bss_8E540;
u32 fzgx_obj_lbl_1_bss_8E544;
u8 fzgx_obj_lbl_1_bss_8E548;
u8 lbl_1_bss_8E548__fzgx_offset_1;
u16 lbl_1_bss_8E548__fzgx_offset_2;
u32 lbl_1_bss_8E548__fzgx_offset_4;
u8 lbl_1_bss_8E550;
u8 fzgx_pool_lbl_1_bss_8E518_gap_8E551;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E551_fill_8E552;
u32 lbl_1_bss_8E554;
u8 lbl_1_bss_8E554__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E559;
u16 fzgx_pool_lbl_1_bss_8E518_gap_8E55A;
u32 lbl_1_bss_8E55C;
u32 lbl_1_bss_8E560[4];
u32 lbl_1_bss_8E570[7];
s32 lbl_1_bss_8E570__fzgx_offset_1C;
u32 lbl_1_bss_8E570__fzgx_offset_20;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E518;
    s = *(u8 *)&lbl_1_bss_8E518__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E51D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E51E;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E520;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E524;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E525_fill_8E526;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E528;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E52C;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
    s = *(u8 *)&lbl_1_bss_8E530;
    s = *(u8 *)&lbl_1_bss_8E534;
    s = *(u8 *)&lbl_1_bss_8E538;
    s = *(u8 *)&lbl_1_bss_8E53C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E540;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E544;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E548;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_8E548__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_8E550;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E551;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E551_fill_8E552;
    s = *(u8 *)&lbl_1_bss_8E554;
    s = *(u8 *)&lbl_1_bss_8E554__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E559;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_8E518_gap_8E55A;
    s = *(u8 *)&lbl_1_bss_8E55C;
    s = *(u8 *)&lbl_1_bss_8E560;
    s = *(u8 *)&lbl_1_bss_8E570;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_1C;
    s = *(u8 *)&lbl_1_bss_8E570__fzgx_offset_20;
}
#pragma section code_type ".text"


static inline u8 sel_count(SelState_8E518 *p) {
    return fzgx_obj_lbl_1_bss_8E51D == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9;
}

/* centre the visible window (n rows) on the current entry; the raw index and the
   centred index are distinct values so the raw store can sink below the subtract */
static inline void sel_scroll_a(SelState_8E518 *p, f32 *pos, s32 *top) {
    u8 n;
    s32 raw;
    s32 t;
    fn_1_3F2A0();
    raw = ((u8 *)&lbl_1_bss_3C30)[fn_1_8623C() * 0xA0 + 0xDC];
    n = fzgx_obj_lbl_1_bss_8E548;
    (*(s32 *)&lbl_1_bss_8E53C) = raw;
    t = raw - ((u8)(n >> 1) - 1);
    (*(s32 *)&lbl_1_bss_8E53C) = t;
    if (t < 0) {
        *top = 0;
    } else if (t >= lbl_1_bss_3C30.unk_9 - n) {
        *top = lbl_1_bss_3C30.unk_9 - n;
    }
    *pos = *top;
}

static inline void sel_scroll_b(SelState_8E518 *p, f32 *pos, s32 *top) {
    u8 n;
    s32 raw;
    s32 t;
    fn_1_3F2A0();
    raw = ((u8 *)&lbl_1_bss_3C30)[fn_1_8623C() * 0xA0 + 0xDC];
    n = fzgx_obj_lbl_1_bss_8E548;
    (*(s32 *)&lbl_1_bss_8E53C) = raw;
    t = raw - ((u8)(n >> 1) - 1);
    (*(s32 *)&lbl_1_bss_8E53C) = t;
    if (t < 0) {
        *top = 0;
    } else if (*top >= sel_count(p) - n) {
        *top = sel_count(p) - n;
    }
    *pos = (f32)sel_count(p) - (f32)fzgx_obj_lbl_1_bss_8E548;
}

void fn_1_14B62C(void) {
    SelState_8E518 *p = (SelState_8E518 *)((void *)&fzgx_obj_lbl_1_bss_8E518);

    if ((s32)lbl_1_bss_25BA0.unk_0 != 0) {
        return;
    }
    fn_1_14A9D0(sel_count(p), 1, 30, 180, 1, 0);
    if ((lbl_1_bss_9F8.unk_8 >> 8) & 1) {
        if (!((lbl_1_bss_D58.unk_8 >> 12) & 1)) {
            if (lbl_801A66A4 - fzgx_obj_lbl_1_bss_8E528 >= 195) {
                fzgx_obj_lbl_1_bss_8E51D = 4;
                lbl_1_bss_8E518__fzgx_offset_4 = 0;
                if (*(s16 *)&lbl_1_bss_960 == 1) {
                    fzgx_obj_lbl_1_bss_8E548 = 4;
                } else {
                    fzgx_obj_lbl_1_bss_8E548 = lbl_1_bss_3C30.unk_8 < 6 ? lbl_1_bss_3C30.unk_8 : 6;
                }
                if ((*(s32 *)&fzgx_obj_lbl_1_bss_8E544) != 0) {
                    f32 *pos = (f32 *)&lbl_1_bss_8E534;
                    s32 *top = (s32 *)&lbl_1_bss_8E53C;
                    sel_scroll_a(p, pos, top);
                } else {
                    s32 *top;
                    f32 *pos;
                    pos = (f32 *)&lbl_1_bss_8E534;
                    top = (s32 *)&lbl_1_bss_8E53C;
                    sel_scroll_b(p, pos, top);
                }
                fn_1_A2D84(0xA9010400);
            } else {
                fn_1_14CA4C();
            }
        }
    }
}
/* fzgx:end fn_1_14B62C */

/* fzgx:begin fn_1_14B8F8 */
// fn_1_14B8F8: empty in retail (single blr).
void fn_1_14B8F8(void) {
}
/* fzgx:end fn_1_14B8F8 */

/* fzgx:begin fn_1_14B8FC */
void fn_1_14B8FC(void) {
    s32 flag = lbl_1_bss_8E544;
    if (flag != 0) {
        lbl_1_bss_8E528 = lbl_801A66A4 - 0xbe;
    }
    if (flag == 0) {
        lbl_1_bss_8E544 = 1;
    }
}
/* fzgx:end fn_1_14B8FC */

/* fzgx:begin fn_1_14B93C noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

struct fn_1_14B93C_state {
    u8 pad_0[4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[10];
    u32 unk_10;
    u8 pad_14[4];
    f32 unk_18;
    u8 pad_1C[4];
    s32 unk_20;
    u8 pad_24[4];
    s32 unk_28;
    u8 pad_2C[4];
    u8 unk_30;
};
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_8E518[4];
u8 lbl_1_bss_8E518__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_8E51D;
u32 fzgx_obj_lbl_1_bss_8E520;
u8 fzgx_obj_lbl_1_bss_8E524;
u32 fzgx_obj_lbl_1_bss_8E528;
u8 fzgx_obj_lbl_1_bss_8E52C;
u32 fzgx_obj_lbl_1_bss_8E530;
u32 fzgx_obj_lbl_1_bss_8E534;
u32 fzgx_obj_lbl_1_bss_8E538;
u32 fzgx_obj_lbl_1_bss_8E53C;
u32 fzgx_obj_lbl_1_bss_8E540;
u32 fzgx_obj_lbl_1_bss_8E544;
u8 fzgx_obj_lbl_1_bss_8E548[0x8];
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E518;
    s = *(u8 *)&lbl_1_bss_8E518__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E51D;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E520;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E524;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E528;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E52C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E530;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E534;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E538;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E53C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E540;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E544;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E548;
}
#pragma section code_type ".text"

extern u32 fn_1_3F2A0(void);
extern u32 fn_1_14A9D0(u32,u32,u32,u32,u32,u32);
extern void fn_1_A2D84(u32);
extern void fn_1_14CA4C(void);
extern int fn_1_8623C(void);
extern u32 lbl_801A66A4;

#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
void fn_1_14B93C(void) {
    u32 v0;
    s32 *v4;
    f32 *v3;
    u8 v5;
    s32 v6;
    s32 v7;
    s32 *v12;
    s32 v9;
    f32 *v11;
    u8 v8;
    u8 v13;
    s32 v14;
    s32 v15;
    u16 v16;
    u8 v17;
    fn_1_3F2A0();
    if ((s32)lbl_1_bss_25BA0.unk_0 == 0) {
        if (fzgx_obj_lbl_1_bss_8E51D == 4) v0 = lbl_1_bss_3C30.unk_8;
        else v0 = lbl_1_bss_3C30.unk_9;
        fn_1_14A9D0(v0,1,30,180,0,1);
        if (((*(u16 *)&lbl_1_bss_9F8.unk_8 >> 8) & 1) && !((lbl_1_bss_D58.unk_8 >> 12) & 1)) {
            if (lbl_801A66A4 - fzgx_obj_lbl_1_bss_8E528 >= 195) {
                fzgx_obj_lbl_1_bss_8E51D = 8;
                fn_1_A2D84(0xA9010400);
            } else fn_1_14CA4C();
        } else if ((lbl_1_bss_9F8.unk_8 >> 9) & 1) {
            fzgx_obj_lbl_1_bss_8E51D = 3;
            lbl_1_bss_8E518__fzgx_offset_4 = 0;
            if (*(s16 *)&lbl_1_bss_960 == 1) fzgx_obj_lbl_1_bss_8E548[0] = 4;
            else {
                v0 = lbl_1_bss_3C30.unk_9 < 6 ? lbl_1_bss_3C30.unk_9 : 6;
                fzgx_obj_lbl_1_bss_8E548[0] = v0;
            }
            if ((s32)fzgx_obj_lbl_1_bss_8E540 != 0) {
                v3 = (f32 *)&fzgx_obj_lbl_1_bss_8E530;
                v4 = (s32 *)&fzgx_obj_lbl_1_bss_8E538;
                v6 = fn_1_8623C() * 160;
                v5 = fzgx_obj_lbl_1_bss_8E548[0];
                v7 = ((u32)v5 >> 1) - 1;
                v8 = *((u8 *)&lbl_1_bss_3C30 + v6 + lbl_1_bss_3C30.unk_A7 + 226);
                v9 = v8 - v7;
                *(s32 *)&fzgx_obj_lbl_1_bss_8E538 = v8;
                *(s32 *)&fzgx_obj_lbl_1_bss_8E538 = v9;
                if (v9 < 0) *v4 = 0;
                else {
                    s32 limit = lbl_1_bss_3C30.unk_9 - v5;
                    if (v9 >= limit) *v4 = limit;
                }
                *v3 = (f32)*v4;
            } else {
                v11 = (f32 *)&fzgx_obj_lbl_1_bss_8E530;
                v12 = (s32 *)&fzgx_obj_lbl_1_bss_8E538;
                v14 = fn_1_8623C() * 160;
                v13 = fzgx_obj_lbl_1_bss_8E548[0];
                v15 = ((u32)v13 >> 1) - 1;
                v0 = *((u8 *)&lbl_1_bss_3C30 + v14 + lbl_1_bss_3C30.unk_A7 + 226);
                *(s32 *)&fzgx_obj_lbl_1_bss_8E538 = v0;
                *(s32 *)&fzgx_obj_lbl_1_bss_8E538 = v0 - v15;
                if ((s32)(v0 - v15) < 0) *v12 = 0;
                else {
                    v16 = fzgx_obj_lbl_1_bss_8E51D;
                    if (*v12 >= (s32)((u8)(v16 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v13))
                        *v12 = (u8)(v16 == 4 ? lbl_1_bss_3C30.unk_8 : lbl_1_bss_3C30.unk_9) - v13;
                }
                if (fzgx_obj_lbl_1_bss_8E51D == 4) v17 = lbl_1_bss_3C30.unk_8;
                else v17 = lbl_1_bss_3C30.unk_9;
                *v11 = (f32)(u32)v17 - (f32)(u32)fzgx_obj_lbl_1_bss_8E548[0];
            }
            fn_1_A2D84(0xA9010400);
        }
    }
}
#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_1_14B93C */

/* fzgx:begin fn_1_14BC3C */
// fn_1_14BC3C: empty in retail (single blr).
void fn_1_14BC3C(void) {
}
/* fzgx:end fn_1_14BC3C */

/* fzgx:begin fn_1_14BC40 noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[4];
    f32 unk_18;
    f32 unk_1c;
    s32 unk_20;
    u8 pad_24[0xc];
    u8 unk_30;
} fn_1_14BC40_Obj;
extern fn_1_14BC40_Obj lbl_1_bss_8E518;
extern u32 lbl_801A66A4;
extern const f32 lbl_1_rodata_99A4;
extern u32 fn_1_14BE30(void);

static inline s32 clamp_value(s32 value, s32 minimum, s32 maximum) {
    if (value < minimum) return minimum;
    if (value > maximum) value = maximum;
    return value;
}

void fn_1_14BC40(void) {
    fn_1_14BC40_Obj *p = &lbl_1_bss_8E518;
    s32 value;
    s32 maximum;
    s32 result = 0;
    u32 lab_v;
    p->unk_20 = 0;
    lab_v = p->unk_30;
    p->unk_20 = -((s32)(((u32)lab_v >> 1) & 0x7f) - 1);
    p->unk_20 = clamp_value(p->unk_20, 0, 10 - lab_v);
    p->unk_18 = lbl_1_rodata_99A4;
    p->unk_10 = lbl_801A66A4;
    fn_1_14BE30();
}
/* fzgx:end fn_1_14BC40 */

/* fzgx:begin fn_1_14BCBC noprologue */
#include "types.h"

struct fn_1_14BCBC_lbl_1_bss_9F8_0_E20 {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0xA];
};
struct fn_1_14BCBC_lbl_1_bss_9F8 {
    struct fn_1_14BCBC_lbl_1_bss_9F8_0_E20 unk_0[1];
};
struct fn_1_14BCBC_lbl_1_bss_8E52C {
    u8 unk_0;
};

extern struct fn_1_14BCBC_lbl_1_bss_8E52C lbl_1_bss_8E52C;
extern struct fn_1_14BCBC_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern u32 fn_1_14A9D0(u32, u32, u32, u32, u32, u32);
extern u32 fn_1_14BFD8(u32, u32, u32);

void fn_1_14BCBC(u32 arg0, u32 arg1) {
    fn_1_14BFD8(arg1, arg0, 1);
    if (((lbl_1_bss_9F8.unk_0[(s16)arg1].unk_8 >> 4) & 0x1) != 0) {
    lbl_1_bss_8E52C.unk_0 = (lbl_1_bss_8E52C.unk_0 ^ 1);
    }
    fn_1_14A9D0(10, 1, 30, 180, 0, 0);
}
/* fzgx:end fn_1_14BCBC */

/* fzgx:begin fn_1_14BD44 */
void fn_1_14BD44(void *arg0, void *arg1) {
    fn_1_14BFD8(arg1, arg0, 0);
}
/* fzgx:end fn_1_14BD44 */

/* fzgx:begin fn_1_14BD74 */
void fn_1_14BD74(void) {
    fn_1_14BFB8();
}
/* fzgx:end fn_1_14BD74 */

/* fzgx:begin fn_1_14BE30 noprologue */
#include "types.h"

extern s16 lbl_1_bss_960;
extern struct fn_1_14BE30_lbl_1_bss_8E518 lbl_1_bss_8E518;
extern u32 fn_1_1556B4(u32, u32);
extern u32 fn_1_A2D84(u32);
extern u32 lbl_801A66A4;

struct fn_1_14BE30_lbl_1_bss_8E518 {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x14];
    u32 unk_28;
    u8 pad_2C[0x14];
    u8 unk_40;
    u8 unk_41;
};

u32 fn_1_14BE30(void) {
    struct fn_1_14BE30_lbl_1_bss_8E518 *p_lbl_1_bss_8E518;
    u32 v0;
    u32 v1;
    u32 t1;
    p_lbl_1_bss_8E518 = (struct fn_1_14BE30_lbl_1_bss_8E518 *)&lbl_1_bss_8E518;
    p_lbl_1_bss_8E518->unk_40 = 42;
    p_lbl_1_bss_8E518->unk_41 = 0;
    fn_1_1556B4(42, 0);
    p_lbl_1_bss_8E518->unk_10 = lbl_801A66A4;
    v0 = lbl_801A66A4;
    if (lbl_1_bss_960 == 2) {
    v0 = 0xA9070000;
    v0 += 8192;
    t1 = fn_1_A2D84(v0);
    v0 = t1;
    }
    v1 = p_lbl_1_bss_8E518->unk_28;
    if ((s32)v1 != 0) {
    v0 = (u32)&lbl_801A66A4;
    v0 = *(u32 *)((u8 *)v0 + 0);
    p_lbl_1_bss_8E518->unk_10 = (v0 - 190);
    }
    if ((s32)v1 == 0) {
    p_lbl_1_bss_8E518->unk_28 = 1;
    }
    return v0;
}
/* fzgx:end fn_1_14BE30 */

/* fzgx:begin fn_1_14BED0 */
void fn_1_14BED0(void) {
    Obj_1_bss_9F8 *obj_9f8;

    fn_1_14BFD8(0, 0, 1);
    fn_1_14A9D0(10, 1, 30, 180, 1, 0);

    if ((s32)lbl_1_bss_25BA0.unk_0 == 0) {
        obj_9f8 = &lbl_1_bss_9F8;
        if (((obj_9f8->unk_8 >> 8) & 1) != 0
            && ((lbl_1_bss_D58.unk_8 >> 12) & 1) == 0) {
            if (lbl_801A66A4 - lbl_1_bss_8E528 >= 0xc3) {
                lbl_1_bss_8E51D = 8;
                fn_1_A2D84(0xa9010400);
            } else {
                fn_1_14CA4C();
            }
        } else if (((obj_9f8->unk_8 >> 9) & 1) != 0) {
            lbl_1_bss_8E51D = 0;
            fn_1_A2D84(0xa9010400);
        }
    }
}
/* fzgx:end fn_1_14BED0 */

/* fzgx:begin fn_1_14BFB8 */
void fn_1_14BFB8(void) {
    if (lbl_1_bss_8E51D != 0) {
        lbl_1_bss_8E520 = 1;
    }
}
/* fzgx:end fn_1_14BFB8 */

/* fzgx:begin fn_1_14C6F8 noprologue */
#include "rel/main_rel/game.h"

extern s32 fn_1_155F8C(void);
extern void fn_1_14CAC8(void);
extern u32 lbl_1_bss_3C04;

/* Offsets recovered from the retail accesses in fn_1_14C6F8. */
typedef struct {
	u32 unk_0;
	u8 unk_4;
	u8 unk_5;
	u8 pad_6[0x12];
	f32 unk_18;
	u32 unk_1C;
	s32 unk_20;
	u32 unk_24;
	s32 unk_28;
	u32 unk_2C;
	u8 unk_30;
	u8 pad_31[0x43];
	s32 unk_74;
} Obj_1_bss_8E518;

extern Obj_1_bss_8E518 lbl_1_bss_8E518;

void fn_1_14C6F8(void)
{
	Obj_1_bss_8E518 *state = (Obj_1_bss_8E518 *)&lbl_1_bss_8E518;
	s32 value;
	s32 left;
	f32 scale;

	if ((s32)lbl_1_bss_25BA0.unk_0 != 0) {
		return;
	}
	if (state->unk_74 != 0) {
		fn_1_14CAC8();
		return;
	}
	state->unk_5 = 5;
	value = fn_1_155F8C() - 2;
	if (value < 0) {
		value = 0;
	} else {
		if (fn_1_155F8C() - 2 > 10 - state->unk_30) {
			value = 10 - state->unk_30;
		} else {
			value = fn_1_155F8C() - 2;
		}
	}
	state->unk_20 = value;
	if (state->unk_28 != 0) {
		scale = value;
	} else {
		scale = 10 - state->unk_30;
	}
	state->unk_18 = scale;
	lbl_1_bss_3C04 = 0x294;
}
/* fzgx:end fn_1_14C6F8 */

/* fzgx:begin fn_1_14C7F4 */
// fn_1_14C7F4: empty in retail (single blr).
void fn_1_14C7F4(void) {
}
/* fzgx:end fn_1_14C7F4 */

/* fzgx:begin fn_1_14C7F8 */
void fn_1_14C7F8(void) {
    s32 state;

    if (fn_1_3F864() != 0) {
        fn_1_A2D84(0xa9070000);
    }

    state = lbl_1_bss_8E540;
    if (state != 0) {
        lbl_1_bss_8E528 = lbl_801A66A4 - 0xbe;
    }
    if (state == 0) {
        lbl_1_bss_8E540 = 1;
    }
}
/* fzgx:end fn_1_14C7F8 */

/* fzgx:begin fn_1_14C864 */
void fn_1_14C864(void) {
    Obj_1_bss_9F8 *flags;
    u8 mode;

    if ((s32)lbl_1_bss_25BA0.unk_0 != 0) {
        return;
    }

    if (lbl_1_bss_8E51D == 4) {
        mode = lbl_1_bss_3C30.unk_8;
    } else {
        mode = lbl_1_bss_3C30.unk_9;
    }

    fn_1_14A9D0(mode, 1, 30, 180, 1, 0);

    flags = &lbl_1_bss_9F8;
    if (((flags->unk_8 >> 8) & 1) != 0) {
        if (((lbl_1_bss_D58.unk_8 >> 12) & 1) == 0) {
            if (lbl_801A66A4 - lbl_1_bss_8E528 >= 0xC3) {
                lbl_1_bss_8E51D = 8;
                fn_1_A2D84(0xA9010400);
            } else {
                fn_1_14CA4C();
            }
            return;
        }
    }

    if (((flags->unk_8 >> 9) & 1) == 0) {
        return;
    }

    lbl_1_bss_8E51D = 0;
    fn_1_A2D84(0xA9010400);
}
/* fzgx:end fn_1_14C864 */

/* fzgx:begin fn_1_14C964 */
// fn_1_14C964: empty in retail (single blr).
void fn_1_14C964(void) {
}
/* fzgx:end fn_1_14C964 */

/* fzgx:begin fn_1_14C968 */
void fn_1_14C968(void) {
    if (lbl_1_bss_3C30.unk_5 == 2) {
        fn_1_3FF90();
    }
    fn_1_C2454();
}
/* fzgx:end fn_1_14C968 */

/* fzgx:begin fn_1_14C9A0 */
void fn_1_14C9A0(void) {
    int state = lbl_1_bss_5138[0xe2];

    if (state != 0) {
        s32 bit = (lbl_1_bss_9F8.unk_8 >> 8) & 1;
        if (lbl_1_bss_5138[0xe2] != 0 && bit != 0) {
            if (lbl_1_bss_5138[0xe0] >= 0xf &&
                lbl_1_bss_5138[0xe0] <= 0x78) {
                lbl_1_bss_5138[0xe0] = 0x78;
            }
        }
    }

    if (state == 0 &&
        fn_1_C24A4() == 0 &&
        fn_1_B7C00() == 0) {
        fn_1_320A4();
        lbl_1_bss_8E51D = 0xa;
    }
}
/* fzgx:end fn_1_14C9A0 */

/* fzgx:begin fn_1_14CA3C */
// fn_1_14CA3C: empty in retail (single blr).
void fn_1_14CA3C(void) {
}
/* fzgx:end fn_1_14CA3C */

/* fzgx:begin fn_1_14CA40 */
// fn_1_14CA40: empty in retail (single blr).
void fn_1_14CA40(void) {
}
/* fzgx:end fn_1_14CA40 */

/* fzgx:begin fn_1_14CA44 */
// fn_1_14CA44: empty in retail (single blr).
void fn_1_14CA44(void) {
}
/* fzgx:end fn_1_14CA44 */

/* fzgx:begin fn_1_14CA48 */
// fn_1_14CA48: empty in retail (single blr).
void fn_1_14CA48(void) {
}
/* fzgx:end fn_1_14CA48 */

/* fzgx:begin fn_1_14CA4C */
// Arms the display update and refreshes it when the selected value exceeds the current one.
void fn_1_14CA4C(void) {
    u8 *display_state = (u8 *)&lbl_1_bss_8E518;
    u8 selected_limit;

    if (lbl_1_bss_8E518.unk_4 != 0) {
        return;
    }

    lbl_1_bss_8E518.unk_4 = 1;
    selected_limit = display_state[5] == 4
        ? lbl_1_bss_3C30.unk_8
        : lbl_1_bss_3C30.unk_9;

    if (selected_limit > display_state[0x30]) {
        fn_1_A2D84(0xA9010400);
    }
}
/* fzgx:end fn_1_14CA4C */

/* fzgx:begin fn_1_14D5CC */
// Keep sampling candidates until one satisfies the required and forbidden flags.
s16 fn_1_14D5CC(s16 arg0, u32 required_mask, u32 forbidden_mask) {
    s16 candidate_index;
    s32 random_value;

    do {
        lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
        random_value = (lbl_801A63C0 >> 16) & 0x7fff;
        candidate_index =
            fn_1_14F090(arg0, (s16)(random_value % fn_1_14F01C(arg0)));
        random_value = fn_1_14D6D8(candidate_index);
    } while ((required_mask & random_value) == 0 ||
             (forbidden_mask & fn_1_14D6D8(candidate_index)) != 0);

    return candidate_index;
}
/* fzgx:end fn_1_14D5CC */

/* fzgx:begin fn_1_14D670 */
s16 fn_1_14D670(void) {
    u32 value;
    s32 sample;
    s16 result;

    do {
        value = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
        lbl_801A63C0 = value;
        sample = (value >> 16) & 0x7fff;
        result = sample % 30;
    } while (result == 2 || (u16)(result - 4) <= 2);

    return result;
}
/* fzgx:end fn_1_14D670 */

/* fzgx:begin fn_1_14D6D8 */
typedef struct {
    u32 values[75];
} Table75;

u32 fn_1_14D6D8(s16 index) {
    Table75 values = *(Table75 *)lbl_1_rodata_99D8;

    return values.values[index];
}
/* fzgx:end fn_1_14D6D8 */

/* fzgx:begin fn_1_14D728 */
typedef struct { u32 values[75]; } InitTable;

static inline u32 fn_1_14D728_array_read(u32 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments on
static inline u8 fn_1_14D728_array_read_(u8 *array, s32 index) { return array[index]; }
void fn_1_14D728(Source *source, Display *displays) {
    char * data = (((char *)&lbl_1_data_43E78));
    InitTable table;
    struct { Display * value; } current;
    Source * base;
    struct { s16 * value; } index_ptr;
    s16 group;

    table = *(InitTable *)lbl_1_rodata_9B04;
    base = source;
    index_ptr.value = source->indices;
    current.value = displays;

    for (group = 0; group < 3u; group++) {
        s16 index = *index_ptr.value;
        current.value->index = index;
        if (index != -1) {
            s16 slot;
            s16 pos;
            for (pos = 0; pos < strlen((char *)fn_1_14D728_array_read(table.values, index)); pos++) {
                u8 *p = (u8 *)fn_1_14D728_array_read(table.values, index);
                u8 c = fn_1_14D728_array_read_(p, pos);
                p[pos] = (c == -1) ? -1 : fn_1_14D728_array_read_((((u8 *)&lbl_8015B200)), c);
            }
            for (slot = 0; slot < 4; slot++) {
                if (current.value->handle[slot] == 0 && (base->flags & (1 << slot)) != 0) {
                    char buffer[0x20];
                    if (slot == 0)
                        sprintf(buffer, data + 0x1338, fn_1_14D728_array_read(table.values, index), slot);
                    else
                        sprintf(buffer, data + 0x1348, fn_1_14D728_array_read(table.values, index), slot + 1);
                    current.value->handle[slot] = fn_1_12ADA0(buffer, current.value->object);
                    fn_1_8019C(((slot)[current.value->handle]));
                }
            }
            {
                char buffer[0x20];
                sprintf(buffer, data + 0x135c, fn_1_14D728_array_read(table.values, index));
                fn_1_12A7C4(buffer, (char *)current.value + 0x20, 0x320);
            }
        }
        index_ptr.value++;
        current.value = (Display *)((u8 *)current.value + 0x360);
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_14D728 */

/* fzgx:begin fn_1_14D8DC */
void fn_1_14D8DC(u8 *arg0, u8 *arg1, s16 arg2) {
    u8 *data;
    u8 *p1;
    u8 *p0;
    s16 i;

    data = lbl_1_data_43E78;
    if (lbl_1_bss_6D82C.unk_0 == 0) {
        fn_1_12AB38(data + 0x136c);
        lbl_1_bss_6D82C.unk_0 = (u32)fn_1_D3884(data + 0x1378);
        fn_1_12AB38(data + 0x1388);
    }

    fn_1_12AB38(data + 0x138c);

    p1 = arg1;
    p0 = arg0;
    for (i = 0; i < arg2; i++) {
        fn_1_14D728( (Source *)(void *)(p0), (Display *)(void *)(p1));
        p1 += 0xa20;
        p0 += 0x10;
    }

    fn_1_12AB38(data + 0x1388);
}
/* fzgx:end fn_1_14D8DC */

/* fzgx:begin fn_1_14D994 noprologue */
#include "rel/main_rel/sel_static_disp.h"

extern void *fn_1_D3884(u32);
typedef struct {
    s16 a;
    s16 b;
    s16 c;
    u8 pad[2];
    u32 v;
    u32 pad2;
} Ent_14D994;

static inline void init_14D994(Ent_14D994 *e, u32 v, s32 i)
{
    e->v = v;
    e->a = i;
    e->b = i + 25;
    e->c = i + 50;
}

void fn_1_14D994(u8 *arg0, u32 arg1, int flag)
{
    Ent_14D994 ents[25];
    Ent_14D994 *p = ents;
    u8 *d = lbl_1_data_43E78;
    struct { s16 value; } j;
    s16 k;
    u8 *q_else;
    struct { u8 *ptr; } q;
    struct { Ent_14D994 *ptr; } e;
    s16 i;
    e.ptr = p;
    for (i = 0; i < 25; i++) {
        init_14D994(e.ptr, arg1, i);
        e.ptr++;
    }
    if (flag) {
        if (lbl_1_bss_6D82C.unk_0 == 0) {
            fn_1_12AB38(d + 0x136c);
            *(void **)&lbl_1_bss_6D82C = fn_1_D3884((u32)(d + 0x1378));
            fn_1_12AB38(d + 0x1388);
        }
        fn_1_12AB38(d + 0x138c);
        j.value = 0;
        q.ptr = arg0;
        for (; j.value < 25; j.value++) {
            fn_1_14D728((void *)p, (void *)q.ptr);
            q.ptr += 0xa20;
            p++;
        }
        fn_1_12AB38(d + 0x1388);
    } else {
        fn_1_12AB38(d + 0x138c);
        q_else = arg0;
        for (k = 0; k < 25; k++) {
            fn_1_14D728((void *)p, (void *)q_else);
            q_else += 0xa20;
            p++;
        }
        fn_1_12AB38(d + 0x1388);
    }
}
/* fzgx:end fn_1_14D994 */

/* fzgx:begin fn_1_14DB48 */
typedef struct {
    u16 values[3];
    u32 extra;
} StaticDispPacket;

void fn_1_14DB48(u32 *state, void *arg1, u32 arg2) {
    u32 flags = *state;

    if ((flags & (1u << 31)) == 0 || (flags & (1u << 30)) == 0) {
        return;
    }

    {
        u8 *base = (u8 *)state + 0x10000;
        StaticDispPacket packet;

        packet.extra = arg2;
        packet.values[0] = base[0x81a4 - 0x10000];
        packet.values[1] = base[0x81ac - 0x10000];
        packet.values[2] = base[0x81b4 - 0x10000];
        fn_1_12AB38(lbl_1_data_45204);
        fn_1_14D728( (Source *)(void *)(&packet), (Display *)(void *)(arg1));
        fn_1_12AB38(&lbl_1_data_45200);
    }
}
/* fzgx:end fn_1_14DB48 */

/* fzgx:begin fn_1_14DBCC */
typedef struct {
    u8 pad[0x340];
    void *field_340;
    void *fields_344[4];
    u8 tail[0xc];
} Fn1_14DBCC_Item;

void fn_1_14DBCC(Fn1_14DBCC_Item *arg0) {
    Fn1_14DBCC_Item *base;
    s16 i;
    s16 j;
    Fn1_14DBCC_Item *item;

    base = arg0;
    for (i = 0; (u32)i < 3; i++) {
        item = base;
        for (j = 0; j < 4; j++) {
            if (item->fields_344[j] != 0) {
                fn_800711A8(item->fields_344[j]);
                item->fields_344[j] = 0;
            }
        }
        if (base->field_340 != 0) {
            fn_80071718(base->field_340);
            base->field_340 = 0;
        }
        base++;
    }
}
/* fzgx:end fn_1_14DBCC */

/* fzgx:begin fn_1_14DC68 */
typedef struct {
    u8 pad_0[0x340];
    void *unk_340;
    void *unk_344;
    u8 pad_348[0x18];
} fn_1_14DC68_StaticDispEntry;

void fn_1_14DC68(fn_1_14DC68_StaticDispEntry *arg0, s16 arg1) {
    struct { s16 value; } k;
    s16 j;
    fn_1_14DC68_StaticDispEntry *cursor;
    fn_1_14DC68_StaticDispEntry *base;
    fn_1_14DC68_StaticDispEntry *p;
    s16 i;

    if (lbl_1_bss_6D82C.unk_0 != 0) {
        fn_80071718((void *)lbl_1_bss_6D82C.unk_0);
        lbl_1_bss_6D82C.unk_0 = 0;
    }

    p = arg0;

    fn_1_12AB38(&"vehicle_parts/");

    for (i = 0; i < arg1; i++) {
        base = p;
        for (j = 0; j < 3u; j++) {
            cursor = base;
            for (k.value = 0; k.value < 4; k.value++) {
                if (cursor->unk_344 != 0) {
                    fn_800711A8(cursor->unk_344);
                    cursor->unk_344 = 0;
                }
                cursor = (fn_1_14DC68_StaticDispEntry *)((u8 *)cursor + 4);
            }
            if (base->unk_340 != 0) {
                fn_80071718(base->unk_340);
                base->unk_340 = 0;
            }
            base = (fn_1_14DC68_StaticDispEntry *)((u8 *)base + 0x360);
        }
        p = (fn_1_14DC68_StaticDispEntry *)((u8 *)p + 0xa20);
    }

    fn_1_12AB38(&lbl_1_data_45200);
}
/* fzgx:end fn_1_14DC68 */

/* fzgx:begin fn_1_14DD68 noprologue */
#include "dolphin/types.h"

extern s16 fn_1_14F344(s16);

static inline u8 *fn_1_14DD68_find(u8 *base) {
    u8 *p;
    u8 *result;
    s16 i;

    result = 0;
    i = 0;
    p = base;

    for (; (u32)i < 3; i++) {
        if ((s16)fn_1_14F344(*(s16 *)p) == 0) {
            result = base + i * 0x360 + 0x23c;
            break;
        }
        p += 0x360;
    }
    return result;
}

void *fn_1_14DD68(void *arg0) {
    return fn_1_14DD68_find(arg0);
}
/* fzgx:end fn_1_14DD68 */

/* fzgx:begin fn_1_14DDF4 noprologue */
#include "dolphin/types.h"

extern s16 fn_1_14F344(s16);

static inline u8 *fn_1_14DDF4_find(u8 *base) {
    u8 *p;
    u8 *result;
    s16 i;

    result = 0;
    i = 0;
    p = base;

    for (; (u32)i < 3; i++) {
        if ((s16)fn_1_14F344(*(s16 *)p) == 0) {
            result = base + i * 0x360 + 0x228;
            break;
        }
        p += 0x360;
    }
    return result;
}

void *fn_1_14DDF4(void *arg0) {
    return fn_1_14DDF4_find(arg0);
}
/* fzgx:end fn_1_14DDF4 */

/* fzgx:begin fn_1_14DE80 */
void fn_1_14DE80(void *arg0, void *arg1, void *arg2, void *arg3) {
    fn_1_14DEC8(arg0, arg1, arg2, arg3, 0);
}
/* fzgx:end fn_1_14DE80 */

/* fzgx:begin fn_1_14DEA4 */
void fn_1_14DEA4(void *arg0, void *arg1, void *arg2, void *arg3) {
    fn_1_14DEC8(arg0, arg1, arg2, arg3, 1);
}
/* fzgx:end fn_1_14DEA4 */

/* fzgx:begin fn_1_14DEC8 noprologue */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);


typedef struct {
void *value;
} Val;
typedef struct {
u8 pad8[8];
Val *value;
} Ref;
typedef struct {
u8 pad344[0x344];
Ref *ref;
} Obj;
extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0(f32);
extern s16 fn_1_14F344(s16);
extern void fn_80072558(void);
extern void fn_1_151C3C(int, s16);
extern void fn_1_556B8(void *);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);
static inline void *find(void *base, int off) {
s16 *entry = (s16 *)base;
void *r = 0;
s16 i;
for (i = 0; (u32)(s32)i < 3; i++) {
if (fn_1_14F344(*entry) == 0) {
r = (u8 *)base + (s16)i * 0x360 + off;
break;
}
entry = (s16 *)((u8 *)entry + 0x360);
}
return r;
}
static inline void *find2(void *base, int off) {
void *r = 0;
s16 i;
s16 *entry;
i = 0;
entry = (s16 *)base;
for (; (u32)(s32)i < 3; i++) {
if (fn_1_14F344(*entry) == 0) {
r = (u8 *)base + (s16)i * 0x360 + off;
break;
}
entry = (s16 *)((u8 *)entry + 0x360);
}
return r;
}
void fn_1_14DEC8(void *arg0, void **arg1, void **arg2, s16 arg3, int arg4, f32 arg5) {
s16 *entry;
Obj *obj;
s16 i;
int same;
void *value;
same = lbl_1_rodata_9C30 == arg5;
if (!same) {
fn_1_55FF0(arg5);
}
i = 0;
entry = (s16 *)arg0;
obj = (Obj *)((u8 *)arg0 + ((s32)arg3 << 2));
for (; (u32)(s32)i < 3; i++) {
if (fn_1_14F344(*entry) == 0) {
value = obj->ref->value->value;
if (value != 0) {
fn_80072558();
fn_1_151C3C(0, *(s16 *)((u8 *)arg0 + (s16)i * 0x360));
if (same || arg4 != 0) {
fn_1_556B8(value);
} else {
fn_1_55210(value);
}
fn_1_151C78();
*arg1 = find(arg0, 0x23c);
*arg2 = find2(arg0, 0x228);
break;
}
}
entry = (s16 *)((u8 *)entry + 0x360);
obj = (Obj *)((u8 *)obj + 0x360);
}
}
/* fzgx:end fn_1_14DEC8 */

/* fzgx:begin fn_1_14E054 */
void fn_1_14E054(void *arg0, void *arg1, void *arg2) {
    fn_1_14E09C(arg0, arg1, arg2, 0);
}
/* fzgx:end fn_1_14E054 */

/* fzgx:begin fn_1_14E078 */
void fn_1_14E078(void *arg0, void *arg1, void *arg2) {
    fn_1_14E09C(arg0, arg1, arg2, 1);
}
/* fzgx:end fn_1_14E078 */

/* fzgx:begin fn_1_14E09C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0(void);
extern s16 fn_1_14F344(s16);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void fn_1_151C3C(int, s16);
extern void fn_1_556B8(void *);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

void fn_1_14E09C(Fn14E09CObj *arg0, void *arg1, s16 arg2, int arg3, f32 arg4) {
    s16 *entry;
    Fn14E09CObj *obj;
    s16 i;
    int same;
    void *value;

    same = lbl_1_rodata_9C30 == arg4;
    if (arg1 != 0) {
        if (!same) {
            fn_1_55FF0();
        }

        entry = (s16 *)arg0;
        obj = (Fn14E09CObj *)((u8 *)arg0 + ((s32)arg2 << 2));
        for (i = 0; (u32)(s32)i < 3; i++) {
            if (fn_1_14F344(*entry) == 1) {
                value = obj->ref->value->value;
                if (value != 0) {
                    lbl_8006E0A4(arg1);
                    fn_80072558();
                    fn_1_151C3C(1, *entry);
                    if (same || arg3 != 0) {
                        fn_1_556B8(value);
                    } else {
                        fn_1_55210(value);
                    }
                    fn_1_151C78();
                }
            }
            entry = (s16 *)((u8 *)entry + 0x360);
            obj = (Fn14E09CObj *)((u8 *)obj + 0x360);
        }
    }
}
/* fzgx:end fn_1_14E09C */

/* fzgx:begin fn_1_14E198 */
void fn_1_14E198(void *arg0, void *arg1, void *arg2) {
    fn_1_14E1E0(arg0, arg1, arg2, 0);
}
/* fzgx:end fn_1_14E198 */

/* fzgx:begin fn_1_14E1BC */
void fn_1_14E1BC(void *arg0, void *arg1, void *arg2) {
    fn_1_14E1E0(arg0, arg1, arg2, 1);
}
/* fzgx:end fn_1_14E1BC */

/* fzgx:begin fn_1_14E1E0 noprologue */
#include "types.h"

typedef struct {
    unsigned char pad[8];
    void **value;
} Inner;

typedef struct {
    unsigned char pad[0x344];
    Inner *inner;
} Record;

extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0(void);
extern s16 fn_1_14F344(s16);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void fn_1_151C3C(int, s16);
extern void fn_1_556B8(void *);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);

void fn_1_14E1E0(void *arg0, void *arg1, s16 arg2, int arg3, f32 arg4) {
    unsigned char *p;
    Record *q;
    s16 i;
    int same;
    void *value;

    same = (lbl_1_rodata_9C30 == arg4);
    if (arg1 != 0) {
        if (same == 0) {
            fn_1_55FF0();
        }

        p = (unsigned char *)arg0;
        q = (Record *)(p + arg2 * 4);
        i = 0;
        while ((u32)(s32)i < 3) {
            if (fn_1_14F344(*(s16 *)p) == 2) {
                value = *q->inner->value;
                if (value != 0) {
                    lbl_8006E0A4(arg1);
                    fn_80072558();
                    fn_1_151C3C(2, *(s16 *)p);
                    if (same != 0 || arg3 != 0) {
                        fn_1_556B8(value);
                    } else {
                        fn_1_55210(value);
                    }
                    fn_1_151C78();
                }
            }
            p += 0x360;
            q = (Record *)((unsigned char *)q + 0x360);
            i++;
        }
    }
}
/* fzgx:end fn_1_14E1E0 */

/* fzgx:begin fn_1_14E8A4 */
typedef struct {
    s16 value;
    s16 sort_key;
} Fn1_14E8A4Entry;

int fn_1_14E8A4(const Fn1_14E8A4Entry *arg0, const Fn1_14E8A4Entry *arg1) {
    if (arg0->sort_key == arg1->sort_key) {
        return arg0->value - arg1->value;
    }
    return arg0->sort_key - arg1->sort_key;
}
/* fzgx:end fn_1_14E8A4 */

/* fzgx:begin fn_1_14E8CC */
typedef struct {
    s16 value;
    u8 pad[8];
    s16 sort_key;
} Fn1_14E8CCEntry;

int fn_1_14E8CC(const Fn1_14E8CCEntry *arg0, const Fn1_14E8CCEntry *arg1) {
    if (arg0->sort_key == arg1->sort_key) {
        return arg0->value - arg1->value;
    }
    return arg0->sort_key - arg1->sort_key;
}
/* fzgx:end fn_1_14E8CC */

/* fzgx:begin fn_1_14E8F4 */
typedef struct {
    s16 value;
    u8 padding[8];
    s16 sort_key;
} Fn1_14E8F4Entry;

int fn_1_14E8F4(const Fn1_14E8F4Entry *arg0, const Fn1_14E8F4Entry *arg1) {
    if (arg0->sort_key == arg1->sort_key) {
        return arg0->value - arg1->value;
    }
    return arg1->sort_key - arg0->sort_key;
}
/* fzgx:end fn_1_14E8F4 */

/* fzgx:begin fn_1_14E91C */
typedef struct {
    s16 value;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 sort_key;
} Fn1_14E91CEntry;

int fn_1_14E91C(const Fn1_14E91CEntry *arg0, const Fn1_14E91CEntry *arg1) {
    if (arg0->sort_key == arg1->sort_key) {
        return arg0->value - arg1->value;
    }
    return arg0->sort_key - arg1->sort_key;
}
/* fzgx:end fn_1_14E91C */

/* fzgx:begin fn_1_14E944 */
typedef struct {
    s16 value;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 sort_key;
} Fn1_14E944Entry;

int fn_1_14E944(const Fn1_14E944Entry *arg0, const Fn1_14E944Entry *arg1) {
    if (arg0->sort_key == arg1->sort_key) {
        return arg0->value - arg1->value;
    }
    return arg1->sort_key - arg0->sort_key;
}
/* fzgx:end fn_1_14E944 */

/* fzgx:begin fn_1_14E96C noprologue */
#include "dolphin/types.h"

typedef struct CompareEntry {
    s16 index;
    f32 value;
} CompareEntry;

s32 fn_1_14E96C(const CompareEntry *a, const CompareEntry *b)
{
    if (a->value == b->value) {
        return a->index - b->index;
    }
    return (s32)(a->value - b->value);
}
/* fzgx:end fn_1_14E96C */

/* fzgx:begin fn_1_14E9A8 noprologue */
#include "dolphin/types.h"

typedef struct CompareEntry {
    s16 index;
    f32 value;
} CompareEntry;

s32 fn_1_14E9A8(const CompareEntry *a, const CompareEntry *b)
{
    if (a->value == b->value) {
        return a->index - b->index;
    }
    return (s32)(b->value - a->value);
}
/* fzgx:end fn_1_14E9A8 */

/* fzgx:begin fn_1_14E9E4 */
typedef struct {
    Fn1_14E9E4Entry entries[75];
} Fn1_14E9E4Blob;


void fn_1_14E9E4(int arg0, void *arg1) {
    Fn1_14E9E4Blob buf;

    buf = *(Fn1_14E9E4Blob *)lbl_1_rodata_9CDC;
    buf.entries[(s16)arg0].value = fn_1_14F608(arg0)->value;
    fn_80008BA8( (u32)(void *)(arg1), (u32)(void *)(&buf.entries[(s16)arg0]), 16);
}
/* fzgx:end fn_1_14E9E4 */

/* fzgx:begin fn_1_14EA74 */
typedef struct {
    u8 bytes[0x708];
} Fn1_14EA74Blob;


#pragma opt_propagation off
#pragma opt_lifetimes off
char *fn_1_14EA74(s16 arg0, char *arg1, s16 arg2) {
    char first[0x40];
    u8 second[0x40];
    Fn1_14EA74Blob local;
    const char *data;
    u8 *base;
    s32 index;

    data = (((char *)&lbl_1_data_43E78));
    local = *(const Fn1_14EA74Blob *)lbl_1_rodata_A18C;
    base = local.bytes;
    index = (s32)(s16)arg0 * 0x18 + (s32)(s16)arg2 * 4;
    if ((s16)fn_1_14FE48(*(void **)(base + index), (void *)(const char *)(data + 0x2428)) < 2) {
        sprintf(arg1, data + 0x242c,
                fn_1_14FDAC(*(void **)(base + index), (void *)(const char *)(data + 0x2428), 0, (void *)(char *)(first)));
    } else {
        if (fn_1_14F344(arg0) == 0) {
            fn_1_14FDAC(*(void **)(base + index), (void *)(const char *)(data + 0x2428), 0, (void *)(char *)(first));
            fn_1_14FDAC(*(void **)(base + index), (void *)(const char *)(data + 0x2428), 1, (void *)((char *)second));
            if (second[0] == 0x2d) {
                sprintf(arg1, data + 0x2430, first, (char *)second);
            } else {
                sprintf(arg1, data + 0x2438, first, (char *)second);
            }
        }
        sprintf(arg1, data + 0x2438,
                fn_1_14FDAC(*(void **)(base + index), (void *)(const char *)(data + 0x2428), 0, (void *)(char *)(first)),
                fn_1_14FDAC(*(void **)(base + index), (void *)(const char *)(data + 0x2428), 1, (void *)((char *)second)));
    }
    return arg1;
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset
/* fzgx:end fn_1_14EA74 */

/* fzgx:begin fn_1_14EBF8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"

extern u8 lbl_1_rodata_A894[1800];
extern s16 fn_1_14FE48(void *arg0, void *arg1);
extern s32 fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern int sprintf(char *arg0, const char *arg1, ...);

typedef struct {
    void *word[75][6];
} Table1800;

u32 fn_1_14EBF8(s16 arg0, u32 arg1, s16 arg2) {
    char *data = (char *)lbl_1_data_43E78;
    char buf0[64];
    Table1800 table;
    char buf3[64];

    table = *(Table1800 *)lbl_1_rodata_A894;

    if (fn_1_14FE48(table.word[arg0][arg2], data + 0x2428) < 2) {
        sprintf((char *)arg1, data + 0x242c,
                fn_1_14FDAC(table.word[arg0][arg2], data + 0x2428, 0, buf0));
    } else {
        sprintf((char *)arg1, data + 0x2438,
                fn_1_14FDAC(table.word[arg0][arg2], data + 0x2428, 2, buf0),
                fn_1_14FDAC(table.word[arg0][arg2], data + 0x2428, 3, buf3));
    }
    return arg1;
}
/* fzgx:end fn_1_14EBF8 */

/* fzgx:begin fn_1_14ED00 */
typedef struct {
    u32 values[5];
    u32 unk0;
} Fn1_14ED00Row;

typedef struct {
    Fn1_14ED00Row rows[75];
} Fn1_14ED00Blob;


s32 fn_1_14ED00(s32 arg0, void *arg1, s32 arg2) {
    u8 buffer[64];
    Fn1_14ED00Blob blob = *(const Fn1_14ED00Blob *)lbl_1_rodata_AF9C;
    s16 type;

    type = (s16)fn_1_14FE48( (void *)(s32)(blob.rows[(s16)arg0].values[(s16)arg2]), (void *)(const u16 *)(&lbl_1_data_462A0));
    if (type < 2) {
        sprintf(arg1, (const char *)(((u8 *)&lbl_1_data_462A4)),
                    fn_1_14FDAC( (void *)(s32)(blob.rows[(s16)arg0].values[(s16)arg2]), (void *)(const u16 *)(&lbl_1_data_462A0), 0, buffer));
    } else {
        sprintf(arg1, (const char *)(((u8 *)&lbl_1_data_462A4)),
                    fn_1_14FDAC( (void *)(s32)(blob.rows[(s16)arg0].values[(s16)arg2]), (void *)(const u16 *)(&lbl_1_data_462A0), 2, buffer));
    }
    return (s32)arg1;
}
/* fzgx:end fn_1_14ED00 */

/* fzgx:begin fn_1_14EE00 */
typedef struct {
    u32 word[60];
} Table240;

int fn_1_14EE00(s16 arg0, void *arg1, s16 arg2) {
    u32 table[60];

    *(Table240 *)table = *(Table240 *)lbl_1_rodata_B794;

    switch (arg0) {
    case 0:
        arg0 = 1;
        break;
    case 2:
        arg0 = 3;
        break;
    case 4:
        arg0 = 5;
        break;
    case 6:
        arg0 = 7;
        break;
    case 8:
        arg0 = 9;
        break;
    default:
        break;
    }

    fn_80083DB0( (char *)(void *)(arg1), (const char *)((void *)*(u32 *)((u8 *)table + arg0 * 24 + arg2 * 4)));
    return (int)arg1;
}
/* fzgx:end fn_1_14EE00 */

/* fzgx:begin fn_1_14EEC4 */
typedef struct {
    u32 values[3][6];
} StaticDispTable;

void *fn_1_14EEC4(s16 index, void *obj, s16 subindex) {
    StaticDispTable table;

    table = *(StaticDispTable *)lbl_1_rodata_B884;
    fn_80083DB0( (char *)(void *)(obj), (const char *)(u32)(table.values[index][subindex]));
    return obj;
}
/* fzgx:end fn_1_14EEC4 */

/* fzgx:begin fn_1_14EF40 */
typedef struct {
    u8 pad[4];
    f32 value;
    u8 tail[8];
} Fn1_14EF40Value;


s16 fn_1_14EF40(void *arg0, void *arg1, void *arg2) {
    Fn1_14EF40Value value;
    s16 accum;

    fn_1_14E9E4( (int)(void *)(arg0), (void *)(Fn1_14EF40Value *)(&value));
    accum = (s16)value.value;
    fn_1_14E9E4( (int)(void *)(arg1), (void *)(Fn1_14EF40Value *)(&value));
    accum = (s16)((f32)accum + value.value);
    fn_1_14E9E4( (int)(void *)(arg2), (void *)(Fn1_14EF40Value *)(&value));
    return (s16)((f32)accum + value.value);
}
/* fzgx:end fn_1_14EF40 */

/* fzgx:begin fn_1_14F014 */
// fn_1_14F014: returns a constant.
int fn_1_14F014(void) {
    return 75;
}
/* fzgx:end fn_1_14F014 */

/* fzgx:begin fn_1_14F01C */
typedef struct {
    u8 unk0[2];
    s16 value;
    u8 unk4[12];
} fn_1_14F01C_Entry;

typedef struct {
    fn_1_14F01C_Entry entries[75];
} fn_1_14F01C_Table;

// Count entries in the static display table whose value matches the argument.
s16 fn_1_14F01C(s16 value) {
    fn_1_14F01C_Table table;
    s16 count;
    s16 i;

    table = *(fn_1_14F01C_Table *)lbl_1_rodata_B8D8;
    i = 0;
    count = 0;
    while (i < 75) {
        if (table.entries[i].value == value) {
            count++;
        }
        i++;
    }
    return count;
}
/* fzgx:end fn_1_14F01C */

/* fzgx:begin fn_1_14F090 */
typedef struct {
    u8 unk0[2];
    s16 value;
    u8 unk4[12];
} fn_1_14F090_Entry;

typedef struct {
    fn_1_14F090_Entry entries[75];
} fn_1_14F090_Table;

// Finds the index of the requested occurrence of a value in the static table.
s16 fn_1_14F090(s16 value, s16 occurrence) {
    fn_1_14F090_Table table;
    s16 i;
    s16 count;

    table = *(fn_1_14F090_Table *)lbl_1_rodata_BD88;
    i = 0;
    count = 0;
    while (i < 75) {
        if (table.entries[i].value == value) {
            if (count == occurrence) {
                return i;
            }
            count++;
        }
        i++;
    }
    return -1;
}
/* fzgx:end fn_1_14F090 */

/* fzgx:begin fn_1_14F118 noprologue */
#include "types.h"

extern s16 fn_1_14F090(void *table, s16 index);
extern s16 fn_1_14F01C(void *table);

// Returns the index of the first table entry matching the requested value.
s16 fn_1_14F118(s16 value, void *table) {
    s16 index;

    for (index = 0; index < fn_1_14F01C(table); index++) {
        if (fn_1_14F090(table, index) == value) {
            return index;
        }
    }
    return -1;
}
/* fzgx:end fn_1_14F118 */

/* fzgx:begin fn_1_14F19C */
typedef struct {
    u32 values[75];
} FlagTable;

// Returns the ordinal among enabled entries for the requested value, or -1 if absent.
s16 fn_1_14F19C(s16 wanted, s16 arg, u32 mask) {
    FlagTable table;
    s16 entry_index;
    s16 enabled_ordinal;

    entry_index = 0;
    enabled_ordinal = 0;
    for (; entry_index < fn_1_14F01C(arg); entry_index++) {
        s16 value;

        value = fn_1_14F090(arg, entry_index);
        table = *(FlagTable *)lbl_1_rodata_99D8;
        if (mask & table.values[value]) {
            if (value == wanted) {
                return enabled_ordinal;
            }
            enabled_ordinal++;
        }
    }
    return -1;
}
/* fzgx:end fn_1_14F19C */

/* fzgx:begin fn_1_14F270 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

extern f32 lbl_1_rodata_99D8[75];
extern s16 fn_1_14F090(void *arg, s16 index);
extern s16 fn_1_14F01C(void *arg);

typedef struct {
    u32 values[75];
} MaskTable;

s16 fn_1_14F270(s16 wanted, void *arg, u32 mask) {
    MaskTable table;
    const MaskTable *source;
    s16 i;
    s16 count;
    s16 index;

    source = (const MaskTable *)(void *)lbl_1_rodata_99D8;
    i = 0;
    count = 0;
    for (; i < fn_1_14F01C(arg); i++) {
        index = fn_1_14F090(arg, i);
        table = *source;
        if (mask & table.values[index]) {
            if (count == wanted) {
                return index;
            }
            count++;
        }
    }
    return -1;
}
/* fzgx:end fn_1_14F270 */

/* fzgx:begin fn_1_14F344 */
typedef struct {
    u8 unk0[2];
    s16 value;
    u8 unk4[12];
} fn_1_14F344_Entry;

typedef struct {
    fn_1_14F344_Entry entries[75];
} fn_1_14F344_Table;

s16 fn_1_14F344(s16 index) {
    fn_1_14F344_Table table;

    table = *(fn_1_14F344_Table *)lbl_1_rodata_C6E8;
    return table.entries[index].value;
}
/* fzgx:end fn_1_14F344 */

/* fzgx:begin fn_1_14F38C */
typedef struct {
    u8 unk0[2];
    s16 unk2;
    u8 unk4[6];
    u32 flags;
    s16 value;
} fn_1_14F38C_StaticDisp;


static inline s16 find_index(s16 value, s16 table) {
    s16 index;

    for (index = 0; index < fn_1_14F01C(table); index++) {
        if (value == fn_1_14F090(table, index)) {
            return index;
        }
    }
    return -1;
}

void fn_1_14F38C(fn_1_14F38C_StaticDisp *disp, u8 *table) {
    s16 j;
    s16 value;
    u8 *p;
    u8 *cur;
    s16 i;

    if (disp->unk2 > 0x28) {
        p = table;
        cur = (u8 *)disp;
        for (i = 0; i < 3u; i++) {
            *(s16 *)(cur + 0x10) = p[0x81a4];
            value = *(s16 *)(cur + 0x10);
            j = find_index(value, i);
            if (j == -1) {
                *(s16 *)(cur + 0x10) = fn_1_14F090(i, 0);
            }
            p += 8;
            cur += 2;
        }
        disp->flags |= 0x04000000;
    }
}
/* fzgx:end fn_1_14F38C */

/* fzgx:begin fn_1_14F46C */
typedef struct {
    char *entries[75];
} StaticDisplayStrings;

typedef struct {
    u8 unk0[8];
    u32 flags;
} DisplayState;

void fn_1_14F46C(DisplayState *state) {
    StaticDisplayStrings strings;
    char buffer0[32];
    char buffer1[32];
    char buffer2[32];
    char *data;
    s16 entry;
    s16 i;
    s16 j;

    data = (((char *)&lbl_1_data_43E78));
    strings = *(StaticDisplayStrings *)lbl_1_rodata_CB98;

    entry = 0;
    while ((u32)entry < 3) {
        s16 index;
        char *string;
        s16 i;

        index = ((s16 *)state)[entry];
        string = strings.entries[index];
        i = 0;
        while (i < strlen(string)) {
            u8 *p = (u8 *)strings.entries[index];
            int c = p[i];
            if (c == -1) {
                c = -1;
            } else {
                c = lbl_8015B200[c];
            }
            p[i] = c;
            i++;
        }

        sprintf(buffer1, data + 0x24c4, strings.entries[index]);
        fn_1_465D0(buffer1, 1);

        j = 0;
        while (j < 4) {
            if (state->flags & (1 << j)) {
                if (j == 0) {
                    sprintf(buffer0, data + 0x1338, strings.entries[index]);
                } else {
                    sprintf(buffer0, data + 0x1348, strings.entries[index], j + 1);
                }
                fn_1_465D0(buffer0, 1);
            }
            j++;
        }

        sprintf(buffer2, data + 0x135c, strings.entries[index]);
        fn_1_465D0(buffer2, 1);
        entry++;
    }
}
/* fzgx:end fn_1_14F46C */

/* fzgx:begin fn_1_14F608 noprologue */
#include "types.h"

extern s16 fn_1_14F01C(void *arg);
extern s16 fn_1_14F090(void *table, s16 index);
extern void *fn_1_14F344(void *self);

// Index of the first table entry matching value, or -1 when absent.
static inline s16 find_ordinal(void *table, s16 value) {
    s16 index;

    for (index = 0; index < fn_1_14F01C(table); index++) {
        if (fn_1_14F090(table, index) == value) {
            return index;
        }
    }
    return -1;
}

u8 *fn_1_14F608(void *arg0) {
    u8 *base;
    void *table;

    table = fn_1_14F344(arg0);

    switch ((s16)table) {
    case 0:
        base = (u8 *)0x23801F04; /* fzgx-allow: A2 table base literal matches retail */
        break;
    case 1:
        base = (u8 *)0x23803098; /* fzgx-allow: A2 table base literal matches retail */
        break;
    case 2:
        base = (u8 *)0x2380422C; /* fzgx-allow: A2 table base literal matches retail */
        break;
    default:
        base = (u8 *)0x23801F04; /* fzgx-allow: A2 table base literal matches retail */
        break;
    }

    return base + find_ordinal(table, (s16)arg0) * 0xb4;
}
/* fzgx:end fn_1_14F608 */

/* fzgx:begin fn_1_14F6F8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[150] = {0x80000000, 0x10000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x00000000, 0x80000000, 0x10000000, 0x60000000, 0x80000000, 0x90000000, 0x00000000, 0x20000000, 0x20000000, 0x80000000, 0x80000000, 0x10000000, 0x00000000, 0x20000000, 0x20000000, 0x80000000, 0x90000000, 0x00000000, 0x00000000, 0x80000000, 0x10000000, 0x80000000, 0x00000000, 0x80000000, 0x80000000, 0x80000000, 0x20000000, 0x80000000, 0x60000000, 0x80000000, 0x00000000, 0x20000000, 0x10000000, 0x00000000, 0x80000000, 0x00000000, 0x80000000, 0x80000000, 0x10000000, 0x20000000, 0x90000000, 0x00000000, 0x90000000, 0x20000000, 0x80000009, 0x8000001A, 0x10000002, 0x60000001, 0x00000018, 0x8000000A, 0x80000002, 0x90000003, 0x0000000A, 0x8000000B, 0x0000001B, 0x20000010, 0x90000002, 0x80000013, 0x2000001A, 0x0000000B, 0x80000019, 0x20000000, 0x8000001B, 0x20000011, 0x10000012, 0x80000008, 0x80000012, 0x10000003, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
}
static const u32 fzgx_pool_table3[1831] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00070008, 0x80000000, 0x00010000, 0x00000000, 0x0009000F, 0x10000000, 0x00020000, 0x00000000, 0x00030008, 0x80000000, 0x00030000, 0x00000000, 0x00010008, 0x80000000, 0x00040000, 0x00000000, 0x00090008, 0x80000000, 0x00050000, 0x00000000, 0x00030008, 0x80000000, 0x00060000, 0x00000000, 0x00030004, 0x00000000, 0x00070000, 0x00000000, 0x00050008, 0x80000000, 0x00080000, 0x00000000, 0x0005000F, 0x10000000, 0x00090000, 0x00000000, 0x00070063, 0x60000000, 0x000A0000, 0x00000000, 0x00070008, 0x80000000, 0x000B0000, 0x00000000, 0x0003000F, 0x90000000, 0x000C0000, 0x00000000, 0x00010005, 0x00000000, 0x000D0000, 0x00000000, 0x00010005, 0x20000000, 0x000E0000, 0x00000000, 0x00030003, 0x20000000, 0x000F0000, 0x00000000, 0x00010008, 0x80000000, 0x00100000, 0x00000000, 0x00050008, 0x80000000, 0x00110000, 0x00000000, 0x0007000F, 0x10000000, 0x00120000, 0x00000000, 0x00050005, 0x00000000, 0x00130000, 0x00000000, 0x00050004, 0x20000000, 0x00140000, 0x00000000, 0x00050004, 0x20000000, 0x00150000, 0x00000000, 0x00050008, 0x80000000, 0x00160000, 0x00000000, 0x0003000F, 0x90000000, 0x00170000, 0x00000000, 0x0009000A, 0x00000000, 0x00180000, 0x00000000, 0x00070007, 0x00000000, 0x00190001, 0x00000000, 0x00070008, 0x80000000, 0x001A0001, 0x00000000, 0x0007000F, 0x10000000, 0x001B0001, 0x00000000, 0x00010008, 0x80000000, 0x001C0001, 0x00000000, 0x00050004, 0x00000000, 0x001D0001, 0x00000000, 0x00050008, 0x80000000, 0x001E0001, 0x00000000, 0x00030008, 0x80000000, 0x001F0001, 0x00000000, 0x00090008, 0x80000000, 0x00200001, 0x00000000, 0x00090003, 0x20000000, 0x00210001, 0x00000000, 0x00030008, 0x80000000, 0x00220001, 0x00000000, 0x00070063, 0x60000000, 0x00230001, 0x00000000, 0x00090008, 0x80000000, 0x00240001, 0x00000000, 0x0001000A, 0x00000000, 0x00250001, 0x00000000, 0x00050004, 0x20000000, 0x00260001, 0x00000000, 0x0003000F, 0x10000000, 0x00270001, 0x00000000, 0x00030005, 0x00000000, 0x00280001, 0x00000000, 0x00070008, 0x80000000, 0x00290001, 0x00000000, 0x00090005, 0x00000000, 0x002A0001, 0x00000000, 0x00050008, 0x80000000, 0x002B0001, 0x00000000, 0x00050008, 0x80000000, 0x002C0001, 0x00000000, 0x0001000F, 0x10000000, 0x002D0001, 0x00000000, 0x00070004, 0x20000000, 0x002E0001, 0x00000000, 0x0001000F, 0x90000000, 0x002F0001, 0x00000000, 0x00050007, 0x00000000, 0x00300001, 0x00000000, 0x0005000F, 0x90000000, 0x00310001, 0x00000000, 0x00030005, 0x20000000, 0x00320002, 0x00000000, 0x00090008, 0x80000009, 0x00330002, 0x00000000, 0x00050008, 0x8000001A, 0x00340002, 0x00000000, 0x0005000F, 0x10000002, 0x00350002, 0x00000000, 0x00090063, 0x60000001, 0x00360002, 0x00000000, 0x00070004, 0x00000018, 0x00370002, 0x00000000, 0x00050008, 0x8000000A, 0x00380002, 0x00000000, 0x00010008, 0x80000002, 0x00390002, 0x00000000, 0x0007000F, 0x90000003, 0x003A0002, 0x00000000, 0x00030005, 0x0000000A, 0x003B0002, 0x00000000, 0x00030008, 0x8000000B, 0x003C0002, 0x00000000, 0x0001000A, 0x0000001B, 0x003D0002, 0x00000000, 0x00050005, 0x20000010, 0x003E0002, 0x00000000, 0x0003000F, 0x90000002, 0x003F0002, 0x00000000, 0x00030008, 0x80000013, 0x00400002, 0x00000000, 0x00050004, 0x2000001A, 0x00410002, 0x00000000, 0x00030005, 0x0000000B, 0x00420002, 0x00000000, 0x00070008, 0x80000019, 0x00430002, 0x00000000, 0x00070003, 0x20000000, 0x00440002, 0x00000000, 0x00030008, 0x8000001B, 0x00450002, 0x00000000, 0x00050004, 0x20000011, 0x00460002, 0x00000000, 0x0001000F, 0x10000012, 0x00470002, 0x00000000, 0x00070008, 0x80000008, 0x00480002, 0x00000000, 0x00050008, 0x80000012, 0x00490002, 0x00000000, 0x0007000F, 0x10000003, 0x004A0002, 0x00000000, 0x00010007, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table5[1275] = {0x00000000, 0x00000000, 0x00070000, 0x00000000, 0x00010000, 0x00000000, 0x00090000, 0x00000000, 0x00020000, 0x00000000, 0x00030000, 0x00000000, 0x00030000, 0x00000000, 0x00010000, 0x00000000, 0x00040000, 0x00000000, 0x00090000, 0x00000000, 0x00050000, 0x00000000, 0x00030000, 0x00000000, 0x00060000, 0x00000000, 0x00030000, 0x00000000, 0x00070000, 0x00000000, 0x00050000, 0x00000000, 0x00080000, 0x00000000, 0x00050000, 0x00000000, 0x00090000, 0x00000000, 0x00070000, 0x00000000, 0x000A0000, 0x00000000, 0x00070000, 0x00000000, 0x000B0000, 0x00000000, 0x00030000, 0x00000000, 0x000C0000, 0x00000000, 0x00010000, 0x00000000, 0x000D0000, 0x00000000, 0x00010000, 0x00000000, 0x000E0000, 0x00000000, 0x00030000, 0x00000000, 0x000F0000, 0x00000000, 0x00010000, 0x00000000, 0x00100000, 0x00000000, 0x00050000, 0x00000000, 0x00110000, 0x00000000, 0x00070000, 0x00000000, 0x00120000, 0x00000000, 0x00050000, 0x00000000, 0x00130000, 0x00000000, 0x00050000, 0x00000000, 0x00140000, 0x00000000, 0x00050000, 0x00000000, 0x00150000, 0x00000000, 0x00050000, 0x00000000, 0x00160000, 0x00000000, 0x00030000, 0x00000000, 0x00170000, 0x00000000, 0x00090000, 0x00000000, 0x00180000, 0x00000000, 0x00070000, 0x00000000, 0x00190001, 0x00000000, 0x00070000, 0x00000000, 0x001A0001, 0x00000000, 0x00070000, 0x00000000, 0x001B0001, 0x00000000, 0x00010000, 0x00000000, 0x001C0001, 0x00000000, 0x00050000, 0x00000000, 0x001D0001, 0x00000000, 0x00050000, 0x00000000, 0x001E0001, 0x00000000, 0x00030000, 0x00000000, 0x001F0001, 0x00000000, 0x00090000, 0x00000000, 0x00200001, 0x00000000, 0x00090000, 0x00000000, 0x00210001, 0x00000000, 0x00030000, 0x00000000, 0x00220001, 0x00000000, 0x00070000, 0x00000000, 0x00230001, 0x00000000, 0x00090000, 0x00000000, 0x00240001, 0x00000000, 0x00010000, 0x00000000, 0x00250001, 0x00000000, 0x00050000, 0x00000000, 0x00260001, 0x00000000, 0x00030000, 0x00000000, 0x00270001, 0x00000000, 0x00030000, 0x00000000, 0x00280001, 0x00000000, 0x00070000, 0x00000000, 0x00290001, 0x00000000, 0x00090000, 0x00000000, 0x002A0001, 0x00000000, 0x00050000, 0x00000000, 0x002B0001, 0x00000000, 0x00050000, 0x00000000, 0x002C0001, 0x00000000, 0x00010000, 0x00000000, 0x002D0001, 0x00000000, 0x00070000, 0x00000000, 0x002E0001, 0x00000000, 0x00010000, 0x00000000, 0x002F0001, 0x00000000, 0x00050000, 0x00000000, 0x00300001, 0x00000000, 0x00050000, 0x00000000, 0x00310001, 0x00000000, 0x00030000, 0x00000000, 0x00320002, 0x00000000, 0x00090009, 0x00000000, 0x00330002, 0x00000000, 0x0005001A, 0x00000000, 0x00340002, 0x00000000, 0x00050002, 0x00000000, 0x00350002, 0x00000000, 0x00090001, 0x00000000, 0x00360002, 0x00000000, 0x00070018, 0x00000000, 0x00370002, 0x00000000, 0x0005000A, 0x00000000, 0x00380002, 0x00000000, 0x00010002, 0x00000000, 0x00390002, 0x00000000, 0x00070003, 0x00000000, 0x003A0002, 0x00000000, 0x0003000A, 0x00000000, 0x003B0002, 0x00000000, 0x0003000B, 0x00000000, 0x003C0002, 0x00000000, 0x0001001B, 0x00000000, 0x003D0002, 0x00000000, 0x00050010, 0x00000000, 0x003E0002, 0x00000000, 0x00030002, 0x00000000, 0x003F0002, 0x00000000, 0x00030013, 0x00000000, 0x00400002, 0x00000000, 0x0005001A, 0x00000000, 0x00410002, 0x00000000, 0x0003000B, 0x00000000, 0x00420002, 0x00000000, 0x00070019, 0x00000000, 0x00430002, 0x00000000, 0x00070000, 0x00000000, 0x00440002, 0x00000000, 0x0003001B, 0x00000000, 0x00450002, 0x00000000, 0x00050011, 0x00000000, 0x00460002, 0x00000000, 0x00010012, 0x00000000, 0x00470002, 0x00000000, 0x00070008, 0x00000000, 0x00480002, 0x00000000, 0x00050012, 0x00000000, 0x00490002, 0x00000000, 0x00070003, 0x00000000, 0x004A0002, 0x00000000, 0x00010003, 0x00000000, 0x00000000, 0x00000000, 0x00070000, 0x00000000, 0x00010000, 0x00000000, 0x00090000, 0x00000000, 0x00020000, 0x00000000, 0x00030000, 0x00000000, 0x00030000, 0x00000000, 0x00010000, 0x00000000, 0x00040000, 0x00000000, 0x00090000, 0x00000000, 0x00050000, 0x00000000, 0x00030000, 0x00000000, 0x00060000, 0x00000000, 0x00030000, 0x00000000, 0x00070000, 0x00000000, 0x00050000, 0x00000000, 0x00080000, 0x00000000, 0x00050000, 0x00000000, 0x00090000, 0x00000000, 0x00070000, 0x00000000, 0x000A0000, 0x00000000, 0x00070000, 0x00000000, 0x000B0000, 0x00000000, 0x00030000, 0x00000000, 0x000C0000, 0x00000000, 0x00010000, 0x00000000, 0x000D0000, 0x00000000, 0x00010000, 0x00000000, 0x000E0000, 0x00000000, 0x00030000, 0x00000000, 0x000F0000, 0x00000000, 0x00010000, 0x00000000, 0x00100000, 0x00000000, 0x00050000, 0x00000000, 0x00110000, 0x00000000, 0x00070000, 0x00000000, 0x00120000, 0x00000000, 0x00050000, 0x00000000, 0x00130000, 0x00000000, 0x00050000, 0x00000000, 0x00140000, 0x00000000, 0x00050000, 0x00000000, 0x00150000, 0x00000000, 0x00050000, 0x00000000, 0x00160000, 0x00000000, 0x00030000, 0x00000000, 0x00170000, 0x00000000, 0x00090000, 0x00000000, 0x00180000, 0x00000000, 0x00070000, 0x00000000, 0x00190001, 0x00000000, 0x00070000, 0x00000000, 0x001A0001, 0x00000000, 0x00070000, 0x00000000, 0x001B0001, 0x00000000, 0x00010000, 0x00000000, 0x001C0001, 0x00000000, 0x00050000, 0x00000000, 0x001D0001, 0x00000000, 0x00050000, 0x00000000, 0x001E0001, 0x00000000, 0x00030000, 0x00000000, 0x001F0001, 0x00000000, 0x00090000, 0x00000000, 0x00200001, 0x00000000, 0x00090000, 0x00000000, 0x00210001, 0x00000000, 0x00030000, 0x00000000, 0x00220001, 0x00000000, 0x00070000, 0x00000000, 0x00230001, 0x00000000, 0x00090000, 0x00000000, 0x00240001, 0x00000000, 0x00010000, 0x00000000, 0x00250001, 0x00000000, 0x00050000, 0x00000000, 0x00260001, 0x00000000, 0x00030000, 0x00000000, 0x00270001, 0x00000000, 0x00030000, 0x00000000, 0x00280001, 0x00000000, 0x00070000, 0x00000000, 0x00290001, 0x00000000, 0x00090000, 0x00000000, 0x002A0001, 0x00000000, 0x00050000, 0x00000000, 0x002B0001, 0x00000000, 0x00050000, 0x00000000, 0x002C0001, 0x00000000, 0x00010000, 0x00000000, 0x002D0001, 0x00000000, 0x00070000, 0x00000000, 0x002E0001, 0x00000000, 0x00010000, 0x00000000, 0x002F0001, 0x00000000, 0x00050000, 0x00000000, 0x00300001, 0x00000000, 0x00050000, 0x00000000, 0x00310001, 0x00000000, 0x00030000, 0x00000000, 0x00320002, 0x00000000, 0x00090009, 0x00000000, 0x00330002, 0x00000000, 0x0005001A, 0x00000000, 0x00340002, 0x00000000, 0x00050002, 0x00000000, 0x00350002, 0x00000000, 0x00090001, 0x00000000, 0x00360002, 0x00000000, 0x00070018, 0x00000000, 0x00370002, 0x00000000, 0x0005000A, 0x00000000, 0x00380002, 0x00000000, 0x00010002, 0x00000000, 0x00390002, 0x00000000, 0x00070003, 0x00000000, 0x003A0002, 0x00000000, 0x0003000A, 0x00000000, 0x003B0002, 0x00000000, 0x0003000B, 0x00000000, 0x003C0002, 0x00000000, 0x0001001B, 0x00000000, 0x003D0002, 0x00000000, 0x00050010, 0x00000000, 0x003E0002, 0x00000000, 0x00030002, 0x00000000, 0x003F0002, 0x00000000, 0x00030013, 0x00000000, 0x00400002, 0x00000000, 0x0005001A, 0x00000000, 0x00410002, 0x00000000, 0x0003000B, 0x00000000, 0x00420002, 0x00000000, 0x00070019, 0x00000000, 0x00430002, 0x00000000, 0x00070000, 0x00000000, 0x00440002, 0x00000000, 0x0003001B, 0x00000000, 0x00450002, 0x00000000, 0x00050011, 0x00000000, 0x00460002, 0x00000000, 0x00010012, 0x00000000, 0x00470002, 0x00000000, 0x00070008, 0x00000000, 0x00480002, 0x00000000, 0x00050012, 0x00000000, 0x00490002, 0x00000000, 0x00070003, 0x00000000, 0x004A0002, 0x00000000, 0x00010003, 0x00000000, 0x00000000, 0x00000000, 0x00070000, 0x00000000, 0x00010000, 0x00000000, 0x00090000, 0x00000000, 0x00020000, 0x00000000, 0x00030000, 0x00000000, 0x00030000, 0x00000000, 0x00010000, 0x00000000, 0x00040000, 0x00000000, 0x00090000, 0x00000000, 0x00050000, 0x00000000, 0x00030000, 0x00000000, 0x00060000, 0x00000000, 0x00030000, 0x00000000, 0x00070000, 0x00000000, 0x00050000, 0x00000000, 0x00080000, 0x00000000, 0x00050000, 0x00000000, 0x00090000, 0x00000000, 0x00070000, 0x00000000, 0x000A0000, 0x00000000, 0x00070000, 0x00000000, 0x000B0000, 0x00000000, 0x00030000, 0x00000000, 0x000C0000, 0x00000000, 0x00010000, 0x00000000, 0x000D0000, 0x00000000, 0x00010000, 0x00000000, 0x000E0000, 0x00000000, 0x00030000, 0x00000000, 0x000F0000, 0x00000000, 0x00010000, 0x00000000, 0x00100000, 0x00000000, 0x00050000, 0x00000000, 0x00110000, 0x00000000, 0x00070000, 0x00000000, 0x00120000, 0x00000000, 0x00050000, 0x00000000, 0x00130000, 0x00000000, 0x00050000, 0x00000000, 0x00140000, 0x00000000, 0x00050000, 0x00000000, 0x00150000, 0x00000000, 0x00050000, 0x00000000, 0x00160000, 0x00000000, 0x00030000, 0x00000000, 0x00170000, 0x00000000, 0x00090000, 0x00000000, 0x00180000, 0x00000000, 0x00070000, 0x00000000, 0x00190001, 0x00000000, 0x00070000, 0x00000000, 0x001A0001, 0x00000000, 0x00070000, 0x00000000, 0x001B0001, 0x00000000, 0x00010000, 0x00000000, 0x001C0001, 0x00000000, 0x00050000, 0x00000000, 0x001D0001, 0x00000000, 0x00050000, 0x00000000, 0x001E0001, 0x00000000, 0x00030000, 0x00000000, 0x001F0001, 0x00000000, 0x00090000, 0x00000000, 0x00200001, 0x00000000, 0x00090000, 0x00000000, 0x00210001, 0x00000000, 0x00030000, 0x00000000, 0x00220001, 0x00000000, 0x00070000, 0x00000000, 0x00230001, 0x00000000, 0x00090000, 0x00000000, 0x00240001, 0x00000000, 0x00010000, 0x00000000, 0x00250001, 0x00000000, 0x00050000, 0x00000000, 0x00260001, 0x00000000, 0x00030000, 0x00000000, 0x00270001, 0x00000000, 0x00030000, 0x00000000, 0x00280001, 0x00000000, 0x00070000, 0x00000000, 0x00290001, 0x00000000, 0x00090000, 0x00000000, 0x002A0001, 0x00000000, 0x00050000, 0x00000000, 0x002B0001, 0x00000000, 0x00050000, 0x00000000, 0x002C0001, 0x00000000, 0x00010000, 0x00000000, 0x002D0001, 0x00000000, 0x00070000, 0x00000000, 0x002E0001, 0x00000000, 0x00010000, 0x00000000, 0x002F0001, 0x00000000, 0x00050000, 0x00000000, 0x00300001, 0x00000000, 0x00050000, 0x00000000, 0x00310001, 0x00000000, 0x00030000, 0x00000000, 0x00320002, 0x00000000, 0x00090009, 0x00000000, 0x00330002, 0x00000000, 0x0005001A, 0x00000000, 0x00340002, 0x00000000, 0x00050002, 0x00000000, 0x00350002, 0x00000000, 0x00090001, 0x00000000, 0x00360002, 0x00000000, 0x00070018, 0x00000000, 0x00370002, 0x00000000, 0x0005000A, 0x00000000, 0x00380002, 0x00000000, 0x00010002, 0x00000000, 0x00390002, 0x00000000, 0x00070003, 0x00000000, 0x003A0002, 0x00000000, 0x0003000A, 0x00000000, 0x003B0002, 0x00000000, 0x0003000B, 0x00000000, 0x003C0002, 0x00000000, 0x0001001B, 0x00000000, 0x003D0002, 0x00000000, 0x00050010, 0x00000000, 0x003E0002, 0x00000000, 0x00030002, 0x00000000, 0x003F0002, 0x00000000, 0x00030013, 0x00000000, 0x00400002, 0x00000000, 0x0005001A, 0x00000000, 0x00410002, 0x00000000, 0x0003000B, 0x00000000, 0x00420002, 0x00000000, 0x00070019, 0x00000000, 0x00430002, 0x00000000, 0x00070000, 0x00000000, 0x00440002, 0x00000000, 0x0003001B, 0x00000000, 0x00450002, 0x00000000, 0x00050011, 0x00000000, 0x00460002, 0x00000000, 0x00010012, 0x00000000, 0x00470002, 0x00000000, 0x00070008, 0x00000000, 0x00480002, 0x00000000, 0x00050012, 0x00000000, 0x00490002, 0x00000000, 0x00070003, 0x00000000, 0x004A0002, 0x00000000, 0x00010003, 0x00000000, 0x00000000, 0x00000000, 0x00070000, 0x00000000, 0x00010000, 0x00000000, 0x00090000, 0x00000000, 0x00020000, 0x00000000, 0x00030000, 0x00000000, 0x00030000, 0x00000000, 0x00010000, 0x00000000, 0x00040000, 0x00000000, 0x00090000, 0x00000000, 0x00050000, 0x00000000, 0x00030000, 0x00000000, 0x00060000, 0x00000000, 0x00030000, 0x00000000, 0x00070000, 0x00000000, 0x00050000, 0x00000000, 0x00080000, 0x00000000, 0x00050000, 0x00000000, 0x00090000, 0x00000000, 0x00070000, 0x00000000, 0x000A0000, 0x00000000, 0x00070000, 0x00000000, 0x000B0000, 0x00000000, 0x00030000, 0x00000000, 0x000C0000, 0x00000000, 0x00010000, 0x00000000, 0x000D0000, 0x00000000, 0x00010000, 0x00000000, 0x000E0000, 0x00000000, 0x00030000, 0x00000000, 0x000F0000, 0x00000000, 0x00010000, 0x00000000, 0x00100000, 0x00000000, 0x00050000, 0x00000000, 0x00110000, 0x00000000, 0x00070000, 0x00000000, 0x00120000, 0x00000000, 0x00050000, 0x00000000, 0x00130000, 0x00000000, 0x00050000, 0x00000000, 0x00140000, 0x00000000, 0x00050000, 0x00000000, 0x00150000, 0x00000000, 0x00050000, 0x00000000, 0x00160000, 0x00000000, 0x00030000, 0x00000000, 0x00170000, 0x00000000, 0x00090000, 0x00000000, 0x00180000, 0x00000000, 0x00070000, 0x00000000, 0x00190001, 0x00000000, 0x00070000, 0x00000000, 0x001A0001, 0x00000000, 0x00070000, 0x00000000, 0x001B0001, 0x00000000, 0x00010000, 0x00000000, 0x001C0001, 0x00000000, 0x00050000, 0x00000000, 0x001D0001, 0x00000000, 0x00050000, 0x00000000, 0x001E0001, 0x00000000, 0x00030000, 0x00000000, 0x001F0001, 0x00000000, 0x00090000, 0x00000000, 0x00200001, 0x00000000, 0x00090000, 0x00000000, 0x00210001, 0x00000000, 0x00030000, 0x00000000, 0x00220001, 0x00000000, 0x00070000, 0x00000000, 0x00230001, 0x00000000, 0x00090000, 0x00000000, 0x00240001, 0x00000000, 0x00010000, 0x00000000, 0x00250001, 0x00000000, 0x00050000, 0x00000000, 0x00260001, 0x00000000, 0x00030000, 0x00000000, 0x00270001, 0x00000000, 0x00030000, 0x00000000, 0x00280001, 0x00000000, 0x00070000, 0x00000000, 0x00290001, 0x00000000, 0x00090000, 0x00000000, 0x002A0001, 0x00000000, 0x00050000, 0x00000000, 0x002B0001, 0x00000000, 0x00050000, 0x00000000, 0x002C0001, 0x00000000, 0x00010000, 0x00000000, 0x002D0001, 0x00000000, 0x00070000, 0x00000000, 0x002E0001, 0x00000000, 0x00010000, 0x00000000, 0x002F0001, 0x00000000, 0x00050000, 0x00000000, 0x00300001, 0x00000000, 0x00050000, 0x00000000, 0x00310001, 0x00000000, 0x00030000, 0x00000000, 0x00320002, 0x00000000, 0x00090009, 0x00000000, 0x00330002, 0x00000000, 0x0005001A, 0x00000000, 0x00340002, 0x00000000, 0x00050002, 0x00000000, 0x00350002, 0x00000000, 0x00090001, 0x00000000, 0x00360002, 0x00000000, 0x00070018, 0x00000000, 0x00370002, 0x00000000, 0x0005000A, 0x00000000, 0x00380002, 0x00000000, 0x00010002, 0x00000000, 0x00390002, 0x00000000, 0x00070003, 0x00000000, 0x003A0002, 0x00000000, 0x0003000A, 0x00000000, 0x003B0002, 0x00000000, 0x0003000B, 0x00000000, 0x003C0002, 0x00000000, 0x0001001B, 0x00000000, 0x003D0002, 0x00000000, 0x00050010, 0x00000000, 0x003E0002, 0x00000000, 0x00030002, 0x00000000, 0x003F0002, 0x00000000, 0x00030013, 0x00000000, 0x00400002, 0x00000000, 0x0005001A, 0x00000000, 0x00410002, 0x00000000, 0x0003000B, 0x00000000, 0x00420002, 0x00000000, 0x00070019, 0x00000000, 0x00430002, 0x00000000, 0x00070000, 0x00000000, 0x00440002, 0x00000000, 0x0003001B, 0x00000000, 0x00450002, 0x00000000, 0x00050011, 0x00000000, 0x00460002, 0x00000000, 0x00010012, 0x00000000, 0x00470002, 0x00000000, 0x00070008, 0x00000000, 0x00480002, 0x00000000, 0x00050012, 0x00000000, 0x00490002, 0x00000000, 0x00070003, 0x00000000, 0x004A0002, 0x00000000, 0x00010003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.125f;
    s = 1200.0f;
    s = 0.00022222222469281405f;
    s = 0.0002142857265425846f;
    s = 0.0f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table7[1] = {0x00000434};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"
extern s16 fn_1_14F01C(void *arg);
extern s16 fn_1_14F090(void *table, s16 index);
extern void *fn_1_14F344(void *self);
extern u8 lbl_1_data_4634C[];

typedef struct {
    u32 words[3];
} Blend3;

typedef struct {
    u8 *kind;        /* 0x00: descriptor pointer, byte 3 is the blend key */
    f32 f04;
    f32 f08;
    f32 f0C;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    u8 b48;
    u8 b49;
    u8 pad4A[2];
    f32 f4C;
    f32 f50;
    Blend3 tail[8];  /* 0x54..0xB4 */
} DispEntry;

static inline s16 find_ordinal_1_14F6F8(void *table, s16 value) {
    s16 index;

    for (index = 0; index < fn_1_14F01C(table); index++) {
        if (fn_1_14F090(table, index) == value) {
            return index;
        }
    }
    return -1;
}

static inline s16 ordinal_via_1_14F6F8(void *table, s16 value) {
    return find_ordinal_1_14F6F8(table, value);
}

static inline u8 *select_entry_1_14F6F8(void *key) {
    u8 *base;
    void *table;

    table = fn_1_14F344(key);

    switch ((s16)table) {
    case 0:
        base = (u8 *)0x23801F04; /* fzgx-allow: A2 table base literal matches retail */
        break;
    case 1:
        base = (u8 *)0x23803098; /* fzgx-allow: A2 table base literal matches retail */
        break;
    case 2:
        base = (u8 *)0x2380422C; /* fzgx-allow: A2 table base literal matches retail */
        break;
    default:
        base = (u8 *)0x23801F04; /* fzgx-allow: A2 table base literal matches retail */
        break;
    }

    return base + find_ordinal_1_14F6F8(table, (s16)key) * 0xb4;
}

// Blends three static display entries into one output record.
void *fn_1_14F6F8(void *arg0, void *arg1, void *arg2, DispEntry *out) {
    DispEntry *x = (DispEntry *)select_entry_1_14F6F8(arg0);
    DispEntry *y = (DispEntry *)select_entry_1_14F6F8(arg1);
    DispEntry *z;
    void *t3;
    u8 *b3;
    f32 q;
    f32 blend;
    s32 i;
    s32 delta;
    f32 rate;

    t3 = fn_1_14F344(arg2);
    switch ((s16)t3) {
    case 0:
        b3 = (u8 *)0x23801F04; /* fzgx-allow: A2 table base literal matches retail */
        break;
    case 1:
        b3 = (u8 *)0x23803098; /* fzgx-allow: A2 table base literal matches retail */
        break;
    case 2:
        b3 = (u8 *)0x2380422C; /* fzgx-allow: A2 table base literal matches retail */
        break;
    default:
        b3 = (u8 *)0x23801F04; /* fzgx-allow: A2 table base literal matches retail */
        break;
    }
    z = (DispEntry *)(b3 + ordinal_via_1_14F6F8(t3, (s16)arg2) * 0xb4);
    delta = (s32)x->kind[3] - (s32)y->kind[3];
    rate = (f32)delta;
    rate /= 8.0f;

    out->kind = lbl_1_data_4634C;
    out->f04 = x->f04 + y->f04 + z->f04;

    blend = out->f04;
    blend -= 1200.0f;
    if (blend > 0.0f) {
        blend *= 0.00022222222469281405f;
    } else {
        blend *= 0.0002142857265425846f;
    }
    blend += 1.0f;

    out->f08 = x->f08 + y->f08 + z->f08;
    out->f0C = x->f0C + y->f0C + z->f0C;
    out->f1C = x->f1C + y->f1C + z->f1C;
    out->f18 = x->f18 + y->f18 + z->f18;
    {
        f32 adjust = 0.30000001192092896f * out->f18 * rate;
        out->f18 += adjust;
    }
    out->f20 = x->f20 + y->f20 + z->f20;
    {
        f32 adjust = 0.30000001192092896f * out->f20 * rate;
        out->f20 -= adjust;
    }
    out->f24 = x->f24 + y->f24 + z->f24;
    out->f28 = x->f28 + y->f28 + z->f28;
    out->f2C = x->f2C + y->f2C + z->f2C;
    out->f30 = x->f30 + y->f30 + z->f30;
    out->f34 = (x->f34 + y->f34 + z->f34) * blend;
    out->f38 = x->f38 + y->f38 + z->f38;
    out->f3C = x->f3C + y->f3C + z->f3C;
    out->f40 = x->f40 + y->f40 + z->f40;
    out->f44 = x->f44 * y->f44;
    out->b48 = x->b48 + y->b48 + z->b48;

    {
        f32 scaled = x->f10 * rate;
        out->f10 = x->f10 + scaled;
    }
    {
        f32 scaled = x->f14 * rate;
        out->f14 = x->f14 + scaled;
    }

    out->f4C = y->f4C;
    out->f50 = y->f50;
    out->b49 = x->b49 | y->b49 | z->b49;

    for (i = 0; i < 4; i++) {
        out->tail[i] = x->tail[i];
        out->tail[i + 4] = x->tail[i + 4];
    }

    return out;
}
/* fzgx:end fn_1_14F6F8 */

/* fzgx:begin fn_1_14FC80 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"

extern void *fn_1_36AD0(s16 arg0, u32 arg1);
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, u32 arg3);

void fn_1_14FC80(s16 arg0, u32 arg1) {
    u8 *data;

    data = (u8 *)fn_1_36AD0(arg0, arg1) + (s32)arg0 * 0x81C0;
    fn_1_14F6F8(data[0x81A4], data[0x81AC], data[0x81B4], arg1);
}
/* fzgx:end fn_1_14FC80 */

/* fzgx:begin fn_1_14FCE4 */
typedef struct {
    u32 words[77];
} Data;

void fn_1_14FCE4(u32 arg0, s16 arg1) {
    Data data;

    data = *(Data *)lbl_1_rodata_CCDC;
    fn_1_14FD7C(data.words, 77);
    fn_80008BA8(arg0, (u32)(u32 *)(data.words), (s32)arg1 << 2);
}
/* fzgx:end fn_1_14FCE4 */

/* fzgx:begin fn_1_14FD6C */
s32 fn_1_14FD6C(s32 *arg0, s32 *arg1) {
    return *arg0 - *arg1;
}
/* fzgx:end fn_1_14FD6C */

/* fzgx:begin fn_1_14FD7C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"

extern void fn_1_14FD7C(u32 *data, u32 count);

extern void fn_1_14FD6C(void);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);

// Forward a callback and its selector to the dispatch helper.
void fn_1_14FD7C(u32 *arg0, u32 arg1) {
    s16 selector = arg1;
    void (*callback)(void) = fn_1_14FD6C;

    qsort(arg0, selector, 4, callback);
}
/* fzgx:end fn_1_14FD7C */

/* fzgx:begin fn_1_14FDAC */
void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3) {
    u8 local[0x40];
    void *value;
    s16 index;
    void *entry;

    fn_80083DB0( (char *)(void *)(local), (const char *)(void *)(arg0));
    value = local;
    index = 0;
    while ((entry = (void *)fn_800839D8( (char *)(void *)(value), (const char *)(void *)(arg1))) != NULL) {
        if (index == arg2) {
            fn_80083DB0( (char *)(void *)(arg3), (const char *)(void *)(entry));
            return arg3;
        }
        value = 0;
        index++;
    }
    fn_80083DB0( (char *)(void *)(arg3), (const char *)(void *)(arg0));
    return arg3;
}
/* fzgx:end fn_1_14FDAC */

/* fzgx:begin fn_1_14FE48 */
s32 fn_1_14FE48(void *arg0, void *arg1) {
    u8 data[64];
    void *value;
    s32 count;

    fn_80083DB0( (char *)(void *)(data), (const char *)(void *)(arg0));
    value = data;
    count = 0;
    while ((void *)fn_800839D8( (char *)(void *)(value), (const char *)(void *)(arg1)) != 0) {
        value = 0;
        count += 1;
    }
    return count;
}
/* fzgx:end fn_1_14FE48 */

/* fzgx:begin fn_1_14FEAC noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

typedef s32 (*Sig_fn_8007E96C_fn_8007E96C_Compare)(u32, u32);

extern u8 lbl_1_bss_8E6B0[308];
extern s32 fn_1_14FD6C(s32 *, s32 *);
extern u16 lbl_1_bss_8E7E4[722];
extern f32 lbl_1_rodata_99D8[75];
extern char *fn_1_14EBF8(s16, char *, s16);
extern char *fn_1_14EA74(s16, char *, s16);
extern s32 fn_1_14ED00(s16, char *, s16);
extern u32 fn_8007E96C(u32, u32, u32, u32, Sig_fn_8007E96C_fn_8007E96C_Compare);
extern char *fn_80083DB0(char *, const char *);
extern char *fn_800839D8(char *, const char *);
extern int sprintf(char *, const char *, ...);

typedef struct {
    s16 id;
    u32 key;
    char str[0x40];
} NameCacheEntry;

typedef struct {
    s16 next;
    NameCacheEntry entries[20];
} NameCache;

typedef struct {
    u32 flags[75];
} NameFlags;

/* The TU's string literals are addressed off one data base in retail; keep each
   base + offset address recomputed at its use instead of CSE'd into a register. */
#pragma opt_loop_invariants off
#pragma opt_common_subs off
extern u8 fn_1_14E8A4__fzgx_offset_0[];
extern u8 fn_1_14E8CC__fzgx_offset_0[];
extern u8 fn_1_14E8F4__fzgx_offset_0[];
extern u8 fn_1_14E91C__fzgx_offset_0[];
extern u8 fn_1_14E944__fzgx_offset_0[];
extern u8 fn_1_14E96C__fzgx_offset_0[];
extern u8 fn_1_14E9A8__fzgx_offset_0[];
extern u8 fn_1_14EE00__fzgx_offset_64[];
extern u8 fn_1_14EE00__fzgx_offset_6C[];
extern u8 fn_1_14EE00__fzgx_offset_74[];
extern u8 fn_1_14EE00__fzgx_offset_7C[];
extern u8 fn_1_14EE00__fzgx_offset_84[];
extern u8 fn_1_14EE00__fzgx_offset_88[];
extern u8 lbl_1_data_43E78__fzgx_offset_0[];
extern u8 lbl_1_data_43E84__fzgx_offset_0[];
extern u8 lbl_1_data_43E88__fzgx_offset_0[];
extern u8 lbl_1_data_43E9C__fzgx_offset_0[];
extern u8 lbl_1_data_43EA8__fzgx_offset_0[];
extern u8 lbl_1_data_43EB8__fzgx_offset_0[];
extern u8 lbl_1_data_43EC8__fzgx_offset_0[];
extern u8 lbl_1_data_43EE8__fzgx_offset_0[];
extern u8 lbl_1_data_43EF4__fzgx_offset_0[];
extern u8 lbl_1_data_43F08__fzgx_offset_0[];
extern u8 lbl_1_data_43F18__fzgx_offset_0[];
extern u8 lbl_1_data_43F2C__fzgx_offset_0[];
extern u8 lbl_1_data_43F38__fzgx_offset_0[];
extern u8 lbl_1_data_43F4C__fzgx_offset_0[];
extern u8 lbl_1_data_43F54__fzgx_offset_0[];
extern u8 lbl_1_data_43F64__fzgx_offset_0[];
extern u8 lbl_1_data_43F74__fzgx_offset_0[];
extern u8 lbl_1_data_43F84__fzgx_offset_0[];
extern u8 lbl_1_data_43F90__fzgx_offset_0[];
extern u8 lbl_1_data_43FA0__fzgx_offset_0[];
extern u8 lbl_1_data_43FB0__fzgx_offset_0[];
extern u8 lbl_1_data_43FC8__fzgx_offset_0[];
extern u8 lbl_1_data_43FD8__fzgx_offset_0[];
extern u8 lbl_1_data_43FEC__fzgx_offset_0[];
extern u8 lbl_1_data_43FF8__fzgx_offset_0[];
extern u8 lbl_1_data_44008__fzgx_offset_0[];
extern u8 lbl_1_data_44018__fzgx_offset_0[];
extern u8 lbl_1_data_44030__fzgx_offset_0[];
extern u8 lbl_1_data_44038__fzgx_offset_0[];
extern u8 lbl_1_data_44048__fzgx_offset_0[];
extern u8 lbl_1_data_44054__fzgx_offset_0[];
extern u8 lbl_1_data_44064__fzgx_offset_0[];
extern u8 lbl_1_data_44070__fzgx_offset_0[];
extern u8 lbl_1_data_44084__fzgx_offset_0[];
extern u8 lbl_1_data_44090__fzgx_offset_0[];
extern u8 lbl_1_data_440A4__fzgx_offset_0[];
extern u8 lbl_1_data_440B0__fzgx_offset_0[];
extern u8 lbl_1_data_440C0__fzgx_offset_0[];
extern u8 lbl_1_data_440CC__fzgx_offset_0[];
extern u8 lbl_1_data_440DC__fzgx_offset_0[];
extern u8 lbl_1_data_440EC__fzgx_offset_0[];
extern u8 lbl_1_data_44100__fzgx_offset_0[];
extern u8 lbl_1_data_4410C__fzgx_offset_0[];
extern u8 lbl_1_data_44120__fzgx_offset_0[];
extern u8 lbl_1_data_4412C__fzgx_offset_0[];
extern u8 lbl_1_data_44138__fzgx_offset_0[];
extern u8 lbl_1_data_44144__fzgx_offset_0[];
extern u8 lbl_1_data_44154__fzgx_offset_0[];
extern u8 lbl_1_data_44160__fzgx_offset_0[];
extern u8 lbl_1_data_44170__fzgx_offset_0[];
extern u8 lbl_1_data_4417C__fzgx_offset_0[];
extern u8 lbl_1_data_4418C__fzgx_offset_0[];
extern u8 lbl_1_data_4419C__fzgx_offset_0[];
extern u8 lbl_1_data_441AC__fzgx_offset_0[];
extern u8 lbl_1_data_441B8__fzgx_offset_0[];
extern u8 lbl_1_data_441D0__fzgx_offset_0[];
extern u8 lbl_1_data_441DC__fzgx_offset_0[];
extern u8 lbl_1_data_441EC__fzgx_offset_0[];
extern u8 lbl_1_data_441F8__fzgx_offset_0[];
extern u8 lbl_1_data_4420C__fzgx_offset_0[];
extern u8 lbl_1_data_44220__fzgx_offset_0[];
extern u8 lbl_1_data_4423C__fzgx_offset_0[];
extern u8 lbl_1_data_44244__fzgx_offset_0[];
extern u8 lbl_1_data_44250__fzgx_offset_0[];
extern u8 lbl_1_data_44260__fzgx_offset_0[];
extern u8 lbl_1_data_44270__fzgx_offset_0[];
extern u8 lbl_1_data_4427C__fzgx_offset_0[];
extern u8 lbl_1_data_44290__fzgx_offset_0[];
extern u8 lbl_1_data_4429C__fzgx_offset_0[];
extern u8 lbl_1_data_442AC__fzgx_offset_0[];
extern u8 lbl_1_data_442BC__fzgx_offset_0[];
extern u8 lbl_1_data_442D0__fzgx_offset_0[];
extern u8 lbl_1_data_442E0__fzgx_offset_0[];
extern u8 lbl_1_data_442F4__fzgx_offset_0[];
extern u8 lbl_1_data_44304__fzgx_offset_0[];
extern u8 lbl_1_data_4431C__fzgx_offset_0[];
extern u8 lbl_1_data_44328__fzgx_offset_0[];
extern u8 lbl_1_data_4433C__fzgx_offset_0[];
extern u8 lbl_1_data_4434C__fzgx_offset_0[];
extern u8 lbl_1_data_44360__fzgx_offset_0[];
extern u8 lbl_1_data_4436C__fzgx_offset_0[];
extern u8 lbl_1_data_44378__fzgx_offset_0[];
extern u8 lbl_1_data_44384__fzgx_offset_0[];
extern u8 lbl_1_data_44394__fzgx_offset_0[];
extern u8 lbl_1_data_443A4__fzgx_offset_0[];
extern u8 lbl_1_data_443B8__fzgx_offset_0[];
extern u8 lbl_1_data_443C8__fzgx_offset_0[];
extern u8 lbl_1_data_443DC__fzgx_offset_0[];
extern u8 lbl_1_data_443EC__fzgx_offset_0[];
extern u8 lbl_1_data_44400__fzgx_offset_0[];
extern u8 lbl_1_data_44410__fzgx_offset_0[];
extern u8 lbl_1_data_44424__fzgx_offset_0[];
extern u8 lbl_1_data_44430__fzgx_offset_0[];
extern u8 lbl_1_data_44444__fzgx_offset_0[];
extern u8 lbl_1_data_44450__fzgx_offset_0[];
extern u8 lbl_1_data_4445C__fzgx_offset_0[];
extern u8 lbl_1_data_44468__fzgx_offset_0[];
extern u8 lbl_1_data_44478__fzgx_offset_0[];
extern u8 lbl_1_data_4448C__fzgx_offset_0[];
extern u8 lbl_1_data_444AC__fzgx_offset_0[];
extern u8 lbl_1_data_444BC__fzgx_offset_0[];
extern u8 lbl_1_data_444D0__fzgx_offset_0[];
extern u8 lbl_1_data_444DC__fzgx_offset_0[];
extern u8 lbl_1_data_444F0__fzgx_offset_0[];
extern u8 lbl_1_data_444F8__fzgx_offset_0[];
extern u8 lbl_1_data_44504__fzgx_offset_0[];
extern u8 lbl_1_data_44510__fzgx_offset_0[];
extern u8 lbl_1_data_44520__fzgx_offset_0[];
extern u8 lbl_1_data_4452C__fzgx_offset_0[];
extern u8 lbl_1_data_4453C__fzgx_offset_0[];
extern u8 lbl_1_data_44548__fzgx_offset_0[];
extern u8 lbl_1_data_44558__fzgx_offset_0[];
extern u8 lbl_1_data_44568__fzgx_offset_0[];
extern u8 lbl_1_data_4457C__fzgx_offset_0[];
extern u8 lbl_1_data_4458C__fzgx_offset_0[];
extern u8 lbl_1_data_445A8__fzgx_offset_0[];
extern u8 lbl_1_data_445B8__fzgx_offset_0[];
extern u8 lbl_1_data_445CC__fzgx_offset_0[];
extern u8 lbl_1_data_445D8__fzgx_offset_0[];
extern u8 lbl_1_data_445E8__fzgx_offset_0[];
extern u8 lbl_1_data_445F4__fzgx_offset_0[];
extern u8 lbl_1_data_44608__fzgx_offset_0[];
extern u8 lbl_1_data_44614__fzgx_offset_0[];
extern u8 lbl_1_data_44624__fzgx_offset_0[];
extern u8 lbl_1_data_44630__fzgx_offset_0[];
extern u8 lbl_1_data_44640__fzgx_offset_0[];
extern u8 lbl_1_data_44650__fzgx_offset_0[];
extern u8 lbl_1_data_44664__fzgx_offset_0[];
extern u8 lbl_1_data_44670__fzgx_offset_0[];
extern u8 lbl_1_data_44684__fzgx_offset_0[];
extern u8 lbl_1_data_44690__fzgx_offset_0[];
extern u8 lbl_1_data_446A0__fzgx_offset_0[];
extern u8 lbl_1_data_446B0__fzgx_offset_0[];
extern u8 lbl_1_data_446C8__fzgx_offset_0[];
extern u8 lbl_1_data_446D8__fzgx_offset_0[];
extern u8 lbl_1_data_446EC__fzgx_offset_0[];
extern u8 lbl_1_data_446F8__fzgx_offset_0[];
extern u8 lbl_1_data_44708__fzgx_offset_0[];
extern u8 lbl_1_data_44714__fzgx_offset_0[];
extern u8 lbl_1_data_44728__fzgx_offset_0[];
extern u8 lbl_1_data_44738__fzgx_offset_0[];
extern u8 lbl_1_data_44750__fzgx_offset_0[];
extern u8 lbl_1_data_4475C__fzgx_offset_0[];
extern u8 lbl_1_data_4476C__fzgx_offset_0[];
extern u8 lbl_1_data_44778__fzgx_offset_0[];
extern u8 lbl_1_data_44788__fzgx_offset_0[];
extern u8 lbl_1_data_44794__fzgx_offset_0[];
extern u8 lbl_1_data_447A8__fzgx_offset_0[];
extern u8 lbl_1_data_447B0__fzgx_offset_0[];
extern u8 lbl_1_data_447BC__fzgx_offset_0[];
extern u8 lbl_1_data_447C8__fzgx_offset_0[];
extern u8 lbl_1_data_447DC__fzgx_offset_0[];
extern u8 lbl_1_data_447E8__fzgx_offset_0[];
extern u8 lbl_1_data_447FC__fzgx_offset_0[];
extern u8 lbl_1_data_44808__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_43E78[616] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x476C6164, 0x6961746F, 0x72000000, 0x0, 0x834F8389, 0x83668342, 0x8347815B, 0x835E815B,
    0x0, 0x4A616262, 0x6572776F, 0x636B0000, 0x83578383, 0x836F8345, 0x83488362, 0x834E0000,
    0x46696E61, 0x6C204576, 0x6F6C7574, 0x696F6E00, 0x83748340, 0x83438369, 0x838B8140, 0x8347837B,
    0x838A8385, 0x815B8356, 0x83878393, 0x0, 0x53757065, 0x72204E6F, 0x76610000, 0x8358815B,  /* fzgx-allow: A1 retail data bytes */
    0x8370815B, 0x8140836D, 0x83948340, 0x0, 0x53617465, 0x6C6C6974, 0x65204F72, 0x62000000,  /* fzgx-allow: A1 retail data bytes */
    0x83548365, 0x83898343, 0x83672083, 0x49815B83, 0x75000000, 0x48617264, 0x2042616E, 0x67657200,
    0x836E815B, 0x83688140, 0x836F8393, 0x834B815B, 0x0, 0x42696720, 0x41636500, 0x83728362,
    0x834F8140, 0x8347815B, 0x83580000, 0x48697070, 0x6F706F74, 0x616D7573, 0x0, 0x8371837C,
    0x8370835E, 0x837D8358, 0x0, 0x446F6E20, 0x51756978, 0x6F746500, 0x83688393, 0x8140834C,  /* fzgx-allow: A1 retail data bytes */
    0x837A815B, 0x83650000, 0x52656420, 0x53616C61, 0x6D616E64, 0x65720000, 0x838C8362, 0x83688140,
    0x83548389, 0x837D8393, 0x835F815B, 0x0, 0x51756565, 0x6E205361, 0x70706869, 0x72650000,
    0x834E8343, 0x815B8393, 0x20835483, 0x74834083, 0x43834100, 0x43656E74, 0x61757275, 0x73000000,  /* fzgx-allow: A1 retail data bytes */
    0x83508393, 0x835E8345, 0x838B8358, 0x0, 0x4772616E, 0x6420456C, 0x65706861, 0x6E740000,
    0x834F8389, 0x83938368, 0x20834783, 0x8C837483, 0x40839383, 0x67000000, 0x54726975, 0x6D706800,
    0x83678389, 0x83438341, 0x83938374, 0x0, 0x53636F72, 0x63686572, 0x0, 0x83588352,
    0x83628360, 0x8383815B, 0x0, 0x426C7565, 0x20537472, 0x65616B00, 0x8375838B, 0x815B8358,  /* fzgx-allow: A1 retail data bytes */
    0x81408367, 0x838A815B, 0x834E0000, 0x57686974, 0x65205379, 0x6C706800, 0x837A838F, 0x83438367,  /* fzgx-allow: A1 retail data bytes */
    0x81408356, 0x838B8374, 0x0, 0x43617262, 0x756E636C, 0x65000000, 0x834A815B, 0x836F8393,  /* fzgx-allow: A1 retail data bytes */
    0x834E838B, 0x0, 0x506C6569, 0x61646573, 0x0, 0x8376838C, 0x83418366, 0x8342815B,
    0x83590000, 0x4368726F, 0x6E6F2053, 0x796D7068, 0x6F6E7900, 0x834E838D, 0x836D2083, 0x56839383,
    0x74834883, 0x6A815B00, 0x49636172, 0x75732057, 0x696E6700, 0x8343834A, 0x838D8358, 0x20834583,
    0x43839383, 0x4F000000, 0x47617267, 0x6F796C65, 0x0, 0x834B815B, 0x83538343, 0x838B0000,
    0x4F757420, 0x52696465, 0x72000000, 0x83418345, 0x83678389, 0x8343835F, 0x815B0000, 0x4C696265,  /* fzgx-allow: A1 retail data bytes */
    0x7261746F, 0x72000000, 0x838A8378, 0x838C8343, 0x835E815B, 0x0, 0x54726963, 0x6B737465,
    0x72000000, 0x8367838A, 0x8362834E, 0x8358835E, 0x815B0000, 0x53617661, 0x6E6E6120, 0x42756767,  /* fzgx-allow: A1 retail data bytes */
    0x79000000, 0x8354836F, 0x83938369, 0x20836F83, 0x4D815B00, 0x426C7565, 0x20556E64, 0x696E6500,
    0x8375838B, 0x815B8140, 0x83458393, 0x83668342, 0x815B836C, 0x0, 0x56616C6B, 0x79726965,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x83948340, 0x838B834C, 0x838A815B, 0x0, 0x466F7274, 0x69737369, 0x6D6F0000,
    0x83748348, 0x838B8365, 0x83428362, 0x83568382, 0x0, 0x42697264, 0x204F6620, 0x50617261,
    0x64697365, 0x0, 0x836F815B, 0x83688140, 0x83498375, 0x81408370, 0x8389835F, 0x83438358,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x42616861, 0x6D757400, 0x836F836E, 0x8380815B, 0x83670000, 0x536F7574, 0x6865726E,
    0x2043726F, 0x73730000, 0x83548355, 0x83938140, 0x834E838D, 0x83580000, 0x536F636B, 0x646F6C61,
    0x67657200, 0x835C8362, 0x834E8368, 0x838C8343, 0x834B815B, 0x0, 0x48696768, 0x20526F6C,
    0x6C657200, 0x836E8343, 0x20838D81, 0x5B838981, 0x5B000000, 0x5374726F, 0x6E672047, 0x75737461,
    0x76000000, 0x83588367, 0x838D8393, 0x834F2083, 0x4F835883, 0x5E837400, 0x44657365, 0x72742043,
    0x616D656C, 0x0, 0x83668355, 0x815B8367, 0x8140834C, 0x83838381, 0x838B0000, 0x4D616D6D,  /* fzgx-allow: A1 retail data bytes */
    0x6F746820, 0x496D7061, 0x63740000, 0x837D8393, 0x83828358, 0x81408343, 0x83938370, 0x834E8367,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x43757269, 0x6F205269, 0x64657200, 0x834E838A, 0x83498140, 0x83898343, 0x835F815B,
    0x0, 0x4D757363, 0x6C652045, 0x6D707265, 0x73730000, 0x837D8362, 0x8358838B, 0x20834783,
    0x93837683, 0x8C835800, 0x4E696768, 0x746D6172, 0x65000000, 0x83698343, 0x83678381, 0x83410000,
    0x416C6D61, 0x67657374, 0x0, 0x8341838B, 0x837D8351, 0x83588367, 0x0, 0x4B696E67,
    0x204E6570, 0x74756E65, 0x0, 0x834C8393, 0x834F2083, 0x6C837683, 0x60838581, 0x5B839300,
    0x42616E64, 0x6572736E, 0x61746368, 0x0, 0x836F8393, 0x835F815B, 0x83588369, 0x83628360,
    0x0, 0x42656174, 0x20546865, 0x20426561, 0x73740000, 0x8372815B, 0x83672083, 0x55208372,
    0x815B8358, 0x83670000, 0x4C696265, 0x72747920, 0x54726974, 0x6F6E0000, 0x838A836F, 0x83658342,  /* fzgx-allow: A1 retail data bytes */
    0x20836783, 0x8A836783, 0x93000000, 0x46697265, 0x2042616C, 0x6C000000, 0x83748340, 0x83438341,
    0x815B8140, 0x837B815B, 0x838B0000, 0x506F7365, 0x69646F6E, 0x0, 0x837C835A, 0x83438368,  /* fzgx-allow: A1 retail data bytes */
    0x83930000, 0x4C657669, 0x61746861, 0x6E000000, 0x838A836F, 0x83438341, 0x83548393, 0x0,
    0x46696E61, 0x6C205265, 0x766F6C75, 0x74696F6E, 0x0, 0x83748340, 0x83438369, 0x838B8140,
    0x838C837B, 0x838A8385, 0x815B8356, 0x83878393, 0x0, 0x4E6F746F, 0x72696F75, 0x73204765,  /* fzgx-allow: A1 retail data bytes */
    0x61720000, 0x836D815B, 0x8367838A, 0x83418358, 0x8140834D, 0x83410000, 0x54726169, 0x6C626C61,  /* fzgx-allow: A1 retail data bytes */
    0x7A657200, 0x8367838C, 0x8343838B, 0x8375838C, 0x83438355, 0x815B0000, 0x456E6967, 0x6D610000,  /* fzgx-allow: A1 retail data bytes */
    0x8347836A, 0x834F837D, 0x0, 0x416C6578, 0x616E6465, 0x72000000, 0x8341838C, 0x834E8354,
    0x8393835F, 0x815B0000, 0x45786361, 0x6C696275, 0x72000000, 0x8347834E, 0x8358834A, 0x838A836F,  /* fzgx-allow: A1 retail data bytes */
    0x815B0000, 0x4865726D, 0x65732053, 0x74617200, 0x8377838B, 0x83818358, 0x20835883, 0x5E815B00,  /* fzgx-allow: A1 retail data bytes */
    0x5468756E, 0x64657220, 0x53746F72, 0x6D000000, 0x83548393, 0x835F815B, 0x81408358, 0x8367815B,  /* fzgx-allow: A1 retail data bytes */
    0x83800000, 0x4372617A, 0x79204D69, 0x6E6F7461, 0x75720000, 0x834E838C, 0x83438357, 0x815B8140,  /* fzgx-allow: A1 retail data bytes */
    0x837E836D, 0x835E8345, 0x83898358, 0x0, 0x4B616C65, 0x69646F73, 0x636F7065, 0x0,
    0x834A838C, 0x83438368, 0x83588352, 0x815B8376, 0x0, 0x456C696D, 0x696E6174, 0x6F720000,  /* fzgx-allow: A1 retail data bytes */
    0x8347838A, 0x837E836C, 0x8343835E, 0x815B0000, 0x4C6F6E67, 0x2053686F, 0x74000000, 0x838D8393,  /* fzgx-allow: A1 retail data bytes */
    0x834F8140, 0x83568387, 0x83628367, 0x0, 0x53616C76, 0x6174696F, 0x6E000000, 0x8354838B,
    0x83788343, 0x83568387, 0x83930000, 0x536C6569, 0x706E6972, 0x0, 0x8358838C, 0x83438376,
    0x836A838B, 0x0, 0x456D6572, 0x616C6420, 0x50656761, 0x73757300, 0x83478381, 0x8389838B,
    0x83682083, 0x79834B83, 0x54835800, 0x4D617374, 0x65722057, 0x6F726B00, 0x837D8358, 0x835E815B,
    0x8140838F, 0x815B834E, 0x0, 0x56616E20, 0x47756172, 0x64000000, 0x83948340, 0x83938140,  /* fzgx-allow: A1 retail data bytes */
    0x834B815B, 0x83680000, 0x53706C61, 0x7368204D, 0x65726D61, 0x69640000, 0x83588376, 0x83898362,
    0x83568385, 0x20837D81, 0x5B838183, 0x43836800, 0x41717561, 0x20477269, 0x6666696E, 0x0,
    0x8341834E, 0x83418140, 0x834F838A, 0x83748342, 0x83930000, 0x54757262, 0x756C656E, 0x63650000,
    0x835E815B, 0x83728385, 0x83898393, 0x83580000, 0x4865726D, 0x69742043, 0x72616200, 0x836E815B,
    0x837E8362, 0x83672083, 0x4E838983, 0x75000000, 0x41737472, 0x6F205363, 0x6F727069, 0x6F6E0000,
    0x83418358, 0x8367838D, 0x81408358, 0x8352815B, 0x83738349, 0x83930000, 0x50726F6D, 0x696E656E,  /* fzgx-allow: A1 retail data bytes */
    0x63650000, 0x8376838D, 0x837E836C, 0x83938358, 0x0, 0x456C2044, 0x6F726164, 0x6F000000,
    0x8347838B, 0x20836883, 0x89815B83, 0x68000000, 0x50617065, 0x72204372, 0x61667400, 0x8379815B,
    0x8370815B, 0x8140834E, 0x83898374, 0x83670000, 0x44726167, 0x6F6F6E00, 0x83688389, 0x834F815B,  /* fzgx-allow: A1 retail data bytes */
    0x83930000, 0x4A756E6B, 0x20526964, 0x65720000, 0x83578383, 0x8393834E, 0x81408389, 0x8343835F,  /* fzgx-allow: A1 retail data bytes */
    0x815B0000, 0x47726F75, 0x6E642057, 0x61766500, 0x834F8389, 0x83938368, 0x81408345, 0x83468343,  /* fzgx-allow: A1 retail data bytes */
    0x83750000, 0x46616E74, 0x61736973, 0x74610000, 0x83748340, 0x8393835E, 0x83578358, 0x835E0000
};
static u32 fzgx_pool_data_lbl_1_data_43E78_9A0[464] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_43E78__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E88__fzgx_offset_0, (u32)lbl_1_data_43E9C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43EA8__fzgx_offset_0, (u32)lbl_1_data_43EB8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43EC8__fzgx_offset_0, (u32)lbl_1_data_43EE8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43EF4__fzgx_offset_0,
    (u32)lbl_1_data_43F08__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43F18__fzgx_offset_0, (u32)lbl_1_data_43F2C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43F38__fzgx_offset_0, (u32)lbl_1_data_43F4C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43F54__fzgx_offset_0, (u32)lbl_1_data_43F64__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43F74__fzgx_offset_0,
    (u32)lbl_1_data_43F84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43F90__fzgx_offset_0, (u32)lbl_1_data_43FA0__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43FB0__fzgx_offset_0, (u32)lbl_1_data_43FC8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43FD8__fzgx_offset_0, (u32)lbl_1_data_43FEC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43FF8__fzgx_offset_0,
    (u32)lbl_1_data_44008__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44018__fzgx_offset_0, (u32)lbl_1_data_44030__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44038__fzgx_offset_0, (u32)lbl_1_data_44048__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44054__fzgx_offset_0, (u32)lbl_1_data_44064__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44070__fzgx_offset_0,
    (u32)lbl_1_data_44084__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44090__fzgx_offset_0, (u32)lbl_1_data_440A4__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_440B0__fzgx_offset_0, (u32)lbl_1_data_440C0__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_440CC__fzgx_offset_0, (u32)lbl_1_data_440DC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_440EC__fzgx_offset_0,
    (u32)lbl_1_data_44100__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4410C__fzgx_offset_0, (u32)lbl_1_data_44120__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4412C__fzgx_offset_0, (u32)lbl_1_data_44138__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44144__fzgx_offset_0, (u32)lbl_1_data_44154__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44160__fzgx_offset_0,
    (u32)lbl_1_data_44170__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4417C__fzgx_offset_0, (u32)lbl_1_data_4418C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4419C__fzgx_offset_0, (u32)lbl_1_data_441AC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_441B8__fzgx_offset_0, (u32)lbl_1_data_441D0__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_441DC__fzgx_offset_0,
    (u32)lbl_1_data_441EC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_441F8__fzgx_offset_0, (u32)lbl_1_data_4420C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44220__fzgx_offset_0, (u32)lbl_1_data_4423C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44244__fzgx_offset_0, (u32)lbl_1_data_44250__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44260__fzgx_offset_0,
    (u32)lbl_1_data_44270__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4427C__fzgx_offset_0, (u32)lbl_1_data_44290__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4429C__fzgx_offset_0, (u32)lbl_1_data_442AC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_442BC__fzgx_offset_0, (u32)lbl_1_data_442D0__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_442E0__fzgx_offset_0,
    (u32)lbl_1_data_442F4__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44304__fzgx_offset_0, (u32)lbl_1_data_4431C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44328__fzgx_offset_0, (u32)lbl_1_data_4433C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4434C__fzgx_offset_0, (u32)lbl_1_data_44360__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4436C__fzgx_offset_0,
    (u32)lbl_1_data_44378__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44384__fzgx_offset_0, (u32)lbl_1_data_44394__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_443A4__fzgx_offset_0, (u32)lbl_1_data_443B8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_443C8__fzgx_offset_0, (u32)lbl_1_data_443DC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_443EC__fzgx_offset_0,
    (u32)lbl_1_data_44400__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44410__fzgx_offset_0, (u32)lbl_1_data_44424__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44430__fzgx_offset_0, (u32)lbl_1_data_44444__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44450__fzgx_offset_0, (u32)lbl_1_data_4445C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44468__fzgx_offset_0,
    (u32)lbl_1_data_44478__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4448C__fzgx_offset_0, (u32)lbl_1_data_444AC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_444BC__fzgx_offset_0, (u32)lbl_1_data_444D0__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_444DC__fzgx_offset_0, (u32)lbl_1_data_444F0__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_444F8__fzgx_offset_0,
    (u32)lbl_1_data_44504__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44510__fzgx_offset_0, (u32)lbl_1_data_44520__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4452C__fzgx_offset_0, (u32)lbl_1_data_4453C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44548__fzgx_offset_0, (u32)lbl_1_data_44558__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44568__fzgx_offset_0,
    (u32)lbl_1_data_4457C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4458C__fzgx_offset_0, (u32)lbl_1_data_445A8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_445B8__fzgx_offset_0, (u32)lbl_1_data_445CC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_445D8__fzgx_offset_0, (u32)lbl_1_data_445E8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_445F4__fzgx_offset_0,
    (u32)lbl_1_data_44608__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44614__fzgx_offset_0, (u32)lbl_1_data_44624__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44630__fzgx_offset_0, (u32)lbl_1_data_44640__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44650__fzgx_offset_0, (u32)lbl_1_data_44664__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44670__fzgx_offset_0,
    (u32)lbl_1_data_44684__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44690__fzgx_offset_0, (u32)lbl_1_data_446A0__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_446B0__fzgx_offset_0, (u32)lbl_1_data_446C8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_446D8__fzgx_offset_0, (u32)lbl_1_data_446EC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_446F8__fzgx_offset_0,
    (u32)lbl_1_data_44708__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44714__fzgx_offset_0, (u32)lbl_1_data_44728__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44738__fzgx_offset_0, (u32)lbl_1_data_44750__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_4475C__fzgx_offset_0, (u32)lbl_1_data_4476C__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44778__fzgx_offset_0,
    (u32)lbl_1_data_44788__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44794__fzgx_offset_0, (u32)lbl_1_data_447A8__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_447B0__fzgx_offset_0, (u32)lbl_1_data_447BC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0,
    (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_447C8__fzgx_offset_0, (u32)lbl_1_data_447DC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_447E8__fzgx_offset_0,
    (u32)lbl_1_data_447FC__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_43E84__fzgx_offset_0, (u32)lbl_1_data_44808__fzgx_offset_0, 0xFFFFFFFF, 0xFFFFFFFF
};
static u32 fzgx_pool_data_lbl_1_data_44F58[1234] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42445930, 0x31000000, 0x42445930, 0x32000000, 0x42445930, 0x33000000, 0x42445930, 0x34000000,
    0x42445930, 0x35000000, 0x42445930, 0x36000000, 0x42445930, 0x37000000, 0x42445930, 0x38000000,
    0x42445930, 0x39000000, 0x42445931, 0x30000000, 0x42445931, 0x31000000, 0x42445931, 0x32000000,
    0x42445931, 0x33000000, 0x42445931, 0x34000000, 0x42445931, 0x35000000, 0x42445931, 0x36000000,
    0x42445931, 0x37000000, 0x42445931, 0x38000000, 0x42445931, 0x39000000, 0x42445932, 0x30000000,
    0x42445932, 0x31000000, 0x42445932, 0x32000000, 0x42445932, 0x33000000, 0x42445932, 0x34000000,
    0x42445932, 0x35000000, 0x43505430, 0x31000000, 0x43505430, 0x32000000, 0x43505430, 0x33000000,
    0x43505430, 0x34000000, 0x43505430, 0x35000000, 0x43505430, 0x36000000, 0x43505430, 0x37000000,
    0x43505430, 0x38000000, 0x43505430, 0x39000000, 0x43505431, 0x30000000, 0x43505431, 0x31000000,
    0x43505431, 0x32000000, 0x43505431, 0x33000000, 0x43505431, 0x34000000, 0x43505431, 0x35000000,
    0x43505431, 0x36000000, 0x43505431, 0x37000000, 0x43505431, 0x38000000, 0x43505431, 0x39000000,
    0x43505432, 0x30000000, 0x43505432, 0x31000000, 0x43505432, 0x32000000, 0x43505432, 0x33000000,
    0x43505432, 0x34000000, 0x43505432, 0x35000000, 0x42535430, 0x31000000, 0x42535430, 0x32000000,
    0x42535430, 0x33000000, 0x42535430, 0x34000000, 0x42535430, 0x35000000, 0x42535430, 0x36000000,
    0x42535430, 0x37000000, 0x42535430, 0x38000000, 0x42535430, 0x39000000, 0x42535431, 0x30000000,
    0x42535431, 0x31000000, 0x42535431, 0x32000000, 0x42535431, 0x33000000, 0x42535431, 0x34000000,
    0x42535431, 0x35000000, 0x42535431, 0x36000000, 0x42535431, 0x37000000, 0x42535431, 0x38000000,
    0x42535431, 0x39000000, 0x42535432, 0x30000000, 0x42535432, 0x31000000, 0x42535432, 0x32000000,
    0x42535432, 0x33000000, 0x42535432, 0x34000000, 0x42535432, 0x35000000, 0x70617274, 0x735F2573,
    0x2E676D61, 0x0, 0x70617274, 0x735F2573, 0x5F302564, 0x2E676D61, 0x0, 0x70617274,
    0x735F2573, 0x2E666D69, 0x0, 0x76656869, 0x636C652F, 0x0, 0x63617263, 0x6D6E7465,
    0x782E7470, 0x6C000000, 0x2E2E0000, 0x76656869, 0x636C655F, 0x70617274, 0x732F0000, (u32)fn_1_14E8A4__fzgx_offset_0,
    (u32)fn_1_14E8CC__fzgx_offset_0, (u32)fn_1_14E8F4__fzgx_offset_0, (u32)fn_1_14E91C__fzgx_offset_0, (u32)fn_1_14E944__fzgx_offset_0, (u32)fn_1_14E96C__fzgx_offset_0, (u32)fn_1_14E9A8__fzgx_offset_0, 0x43000000, 0x83668374,
    0x8348838B, 0x83678F87, 0x0, 0x50000000, 0x837C8343, 0x83938367, 0x8F870000, 0x52500000,
    0x837C8343, 0x83938367, 0x8B748F87, 0x0, 0x90AB945C, 0x8F870000, 0x90AB945C, 0x8B748F87,
    0x0, 0x57000000, 0x83458347, 0x83438367, 0x8F870000, 0x52570000, 0x83458347, 0x83438367,
    0x8B748F87, 0x0, 0x42726176, 0x65204561, 0x676C6520, 0x53747269, 0x6B652043, 0x6F6E646F,
    0x72000000, 0x8375838C, 0x83438375, 0x20834381, 0x5B834F83, 0x8B208358, 0x83678389, 0x8343834E,
    0x20835283, 0x93836883, 0x8B000000, 0x47616C61, 0x78792046, 0x616C636F, 0x6E20436F, 0x736D6F20,
    0x54657263, 0x656C0000, 0x834D8383, 0x8389834E, 0x8356815B, 0x20837483, 0x40838B83, 0x52839320,
    0x83528358, 0x83822083, 0x5E815B83, 0x5A838B00, 0x4769616E, 0x7420506C, 0x616E6574, 0x20436F73,
    0x6D696320, 0x43697263, 0x6C650000, 0x83578383, 0x83438341, 0x83938367, 0x20837683, 0x89836C83,
    0x62836720, 0x83528359, 0x837E8362, 0x834E2083, 0x54815B83, 0x4E838B00, 0x4D656761, 0x6C6F2043,
    0x72756973, 0x65722048, 0x65617679, 0x20427275, 0x69736572, 0x0, 0x8381834B, 0x838D2083,
    0x4E838B81, 0x5B835581, 0x5B208377, 0x8372815B, 0x20837583, 0x8B815B83, 0x55815B00, 0x53706C61,
    0x73682057, 0x68616C65, 0x20466C75, 0x73682047, 0x72616D70, 0x75730000, 0x83588376, 0x83898362,
    0x83568385, 0x20837A83, 0x47815B83, 0x8B208374, 0x83898362, 0x83568385, 0x20834F83, 0x89839383,
    0x70835800, 0x57696C64, 0x20436861, 0x72696F74, 0x20537472, 0x6F6E6720, 0x54616E6B, 0x0,
    0x838F8343, 0x838B8368, 0x20836083, 0x83838A83, 0x49836283, 0x67208358, 0x8367838D, 0x8393834F,
    0x20835E83, 0x93834E00, 0x56616C69, 0x616E7420, 0x4A616775, 0x61722042, 0x65727365, 0x726B2050,
    0x616E7468, 0x65720000, 0x836F838A, 0x83418393, 0x83672083, 0x57838383, 0x4B815B20, 0x836F815B,
    0x8354834E, 0x20837083, 0x93835481, 0x5B000000, 0x486F6C79, 0x20537069, 0x64657220, 0x53616372,
    0x65642047, 0x6C696465, 0x72000000, 0x837A815B, 0x838A815B, 0x20835883, 0x70834383, 0x5F815B20,
    0x835A8343, 0x834E838A, 0x83628368, 0x20834F83, 0x89834383, 0x5F815B00, 0x426C6F6F, 0x64205261,
    0x76656E20, 0x536C6173, 0x68204372, 0x6F770000, 0x83758389, 0x83628368, 0x20838C83, 0x43837583,
    0x93208358, 0x83898362, 0x83568385, 0x20834E83, 0x8D834500, 0x46756E6E, 0x79205377, 0x616C6C6F,
    0x77205072, 0x65747479, 0x20506967, 0x656F6E00, 0x83748340, 0x836A815B, 0x20835883, 0x8F838D81,
    0x5B208376, 0x838A8365, 0x8342815B, 0x20837383, 0x57838783, 0x93000000, 0x4F707469, 0x63616C20,
    0x57696E67, 0x2050686F, 0x746F6E20, 0x426C6164, 0x65000000, 0x83498376, 0x83658342, 0x834A838B,
    0x20834583, 0x42839383, 0x4F208374, 0x83488367, 0x83932083, 0x75838C81, 0x5B836800, 0x4D616420,
    0x42756C6C, 0x20526F77, 0x64792042, 0x6565746C, 0x65000000, 0x837D8362, 0x83682083, 0x75838B20,
    0x83898345, 0x83668342, 0x20837281, 0x5B836783, 0x8B000000, 0x42696720, 0x54797261, 0x6E74204A,
    0x756D626F, 0x20456D70, 0x65726F72, 0x0, 0x83728362, 0x834F2083, 0x5E834383, 0x89839383,
    0x67208357, 0x83838393, 0x837B2083, 0x47839383, 0x79838981, 0x5B000000, 0x4772616E, 0x64204261,
    0x73652047, 0x72656174, 0x2047656E, 0x6572616C, 0x0, 0x834F8389, 0x83938368, 0x20837881,
    0x5B835820, 0x834F838C, 0x815B8367, 0x20835783, 0x46836C83, 0x89838B00, 0x46697265, 0x20576F6C,  /* fzgx-allow: A1 retail data bytes */
    0x66204275, 0x726E696E, 0x6720436F, 0x796F7465, 0x0, 0x83748340, 0x83438384, 0x815B2083,  /* fzgx-allow: A1 retail data bytes */
    0x45838B83, 0x7420836F, 0x815B836A, 0x8393834F, 0x20835283, 0x88815B83, 0x65000000, 0x44726561,  /* fzgx-allow: A1 retail data bytes */
    0x64204861, 0x6D6D6572, 0x2047616C, 0x6C616E74, 0x2047616E, 0x746C6574, 0x0, 0x8368838C,
    0x83628368, 0x20836E83, 0x93837D81, 0x5B20834B, 0x815B8389, 0x83938367, 0x20834B83, 0x93836783,  /* fzgx-allow: A1 retail data bytes */
    0x8C836283, 0x67000000, 0x53696C76, 0x65722053, 0x776F7264, 0x20417263, 0x68204A61, 0x76656C69,
    0x6E000000, 0x8356838B, 0x836F815B, 0x20835C81, 0x5B836820, 0x8341815B, 0x834E2083, 0x57838383,
    0x78838A83, 0x93000000, 0x52616765, 0x204B6E69, 0x67687420, 0x53746F72, 0x6D792042, 0x6F756E63,
    0x65720000, 0x838C8343, 0x83572083, 0x69834383, 0x67208358, 0x8367815B, 0x837E815B, 0x20836F83,
    0x45839383, 0x54815B00, 0x52617069, 0x64204261, 0x7272656C, 0x2053686F, 0x636B204D, 0x61676E75,
    0x6D000000, 0x83898373, 0x83628368, 0x20836F83, 0x8C838B20, 0x83568387, 0x8362834E, 0x20837D83,
    0x4F836983, 0x80000000, 0x536B7920, 0x486F7273, 0x65204163, 0x726F204D, 0x75737461, 0x6E670000,  /* fzgx-allow: A1 retail data bytes */
    0x8358834A, 0x83432083, 0x7A815B83, 0x58208341, 0x834E838D, 0x20838083, 0x58835E83, 0x93834F00,
    0x41717561, 0x20476F6F, 0x73652046, 0x726F7374, 0x20447261, 0x6B650000, 0x8341834E, 0x83412083,
    0x4F815B83, 0x58208374, 0x838D8358, 0x83672083, 0x68838C83, 0x43834E00, 0x53706163, 0x65204361,
    0x6E636572, 0x20417374, 0x726F2043, 0x72616200, 0x83588379, 0x815B8358, 0x20834C83, 0x83839383,  /* fzgx-allow: A1 retail data bytes */
    0x54815B20, 0x83418358, 0x8367838D, 0x20834E83, 0x89837500, 0x4D657461, 0x6C205368, 0x656C6C20,
    0x53746565, 0x6C205475, 0x72746C65, 0x0, 0x8381835E, 0x838B2083, 0x56834683, 0x8B208358,
    0x83658342, 0x815B838B, 0x20835E81, 0x5B836783, 0x8B000000, 0x53706565, 0x64792044, 0x7261676F,  /* fzgx-allow: A1 retail data bytes */
    0x6E205175, 0x69636B20, 0x57797665, 0x726E0000, 0x83588373, 0x815B8366, 0x8342815B, 0x20836883,  /* fzgx-allow: A1 retail data bytes */
    0x89835383, 0x9320834E, 0x83438362, 0x834E2083, 0x8F834383, 0x6F815B83, 0x93000000, 0x4C696265,
    0x72747920, 0x4D616E74, 0x6120466C, 0x79696E67, 0x20537175, 0x69640000, 0x838A836F, 0x83658342,
    0x20837D83, 0x93835E20, 0x83748389, 0x83438393, 0x834F2083, 0x58834E83, 0x43836800, 0x576F6E64,
    0x65722057, 0x6F726D20, 0x4D697261, 0x636C6520, 0x496E7365, 0x63740000, 0x838F8393, 0x835F815B,
    0x20838F81, 0x5B838020, 0x837E8389, 0x834E838B, 0x20834383, 0x93835A83, 0x4E836700, 0x52757368,
    0x20437963, 0x6C6F6E65, 0x20446173, 0x68205477, 0x69737465, 0x72000000, 0x83898362, 0x83568385,
    0x20835483, 0x43834E83, 0x8D839320, 0x835F8362, 0x83568385, 0x20836383, 0x43835883, 0x5E815B00,
    0x436F6D62, 0x61742043, 0x616E6E6F, 0x6E20546F, 0x726E6164, 0x6F204D61, 0x73746572, 0x0,
    0x83528393, 0x836F8362, 0x83672083, 0x4C838383, 0x6D839320, 0x8367838B, 0x836C815B, 0x83682083,
    0x7D835883, 0x5E815B00, 0x4D757363, 0x6C652047, 0x6F72696C, 0x6C612053, 0x70696379, 0x20547573,
    0x6B000000, 0x837D8362, 0x8358838B, 0x20835383, 0x8A838920, 0x83588370, 0x83438356, 0x815B2083,  /* fzgx-allow: A1 retail data bytes */
    0x5E835883, 0x4E000000, 0x43796265, 0x7220466F, 0x78204A65, 0x74205669, 0x78656E00, 0x83548343,
    0x836F815B, 0x20837483, 0x48836283, 0x4E835820, 0x83578346, 0x83628367, 0x20837283, 0x4E835A83,
    0x93000000, 0x48656174, 0x20536E61, 0x6B652046, 0x6C616D65, 0x204C697A, 0x61726400, 0x8371815B,
    0x83672083, 0x58836C81, 0x5B834E20, 0x8374838C, 0x83438380, 0x20838A83, 0x55815B83, 0x68000000,
    0x52617665, 0x20447269, 0x66746572, 0x20416374, 0x69766520, 0x47616D62, 0x6C657200, 0x838C8343,
    0x83752083, 0x68838A83, 0x74835E81, 0x5B208341, 0x834E8365, 0x83428375, 0x20834D83, 0x83839383,
    0x75838981, 0x5B000000, 0x41657269, 0x616C2042, 0x756C6C65, 0x74204169, 0x72205368, 0x6F740000,
    0x83478341, 0x838A8341, 0x838B2083, 0x6F838C83, 0x62836720, 0x83478341, 0x815B2083, 0x56838783,  /* fzgx-allow: A1 retail data bytes */
    0x62836700, 0x53706172, 0x6B204269, 0x72642050, 0x6C61736D, 0x61204B69, 0x74650000, 0x83588370,
    0x815B834E, 0x20836F81, 0x5B836820, 0x83768389, 0x8359837D, 0x20834A83, 0x43836700, 0x426C6173,  /* fzgx-allow: A1 retail data bytes */
    0x74204361, 0x6D656C20, 0x426C617A, 0x65204769, 0x72616666, 0x65000000, 0x83758389, 0x83588367,
    0x20834C83, 0x83838183, 0x8B208375, 0x838C8343, 0x83592083, 0x57838983, 0x74000000, 0x4461726B,
    0x20436861, 0x73657220, 0x53686164, 0x6F772053, 0x6E697065, 0x72000000, 0x835F815B, 0x834E2083,
    0x60834683, 0x43835481, 0x5B208356, 0x83838368, 0x83452083, 0x58836983, 0x43837081, 0x5B000000,
    0x4761726E, 0x65742050, 0x68616E74, 0x6F6D204A, 0x6577656C, 0x204D6972, 0x61676500, 0x834B815B,
    0x836C8362, 0x83672083, 0x74834083, 0x93836783, 0x80208357, 0x83858347, 0x838B2083, 0x7E838981,  /* fzgx-allow: A1 retail data bytes */
    0x5B835783, 0x85000000, 0x42726967, 0x68742053, 0x70656172, 0x20536869, 0x6E696E67, 0x204C616E,
    0x63657200, 0x83758389, 0x83438367, 0x20835883, 0x73834181, 0x5B208356, 0x83838343, 0x836A8393,
    0x834F2083, 0x89839383, 0x54815B00, 0x48797065, 0x72205374, 0x7265616D, 0x20426174, 0x746C6520,
    0x566F7274, 0x65780000, 0x836E8343, 0x8370815B, 0x20835883, 0x67838A81, 0x5B838020, 0x836F8367,
    0x838B2083, 0x7B838B83, 0x65836283, 0x4E835800, 0x53757065, 0x72204C79, 0x6E782055, 0x6C747261,
    0x204C6567, 0x696F6E00, 0x8358815B, 0x8370815B, 0x20838A83, 0x93834E83, 0x58208345, 0x838B8367,
    0x83892083, 0x8C834D83, 0x49839300, 0x43727973, 0x74616C20, 0x45676720, 0x526F7961, 0x6C205269,
    0x64657200, 0x834E838A, 0x8358835E, 0x838B2083, 0x47836283, 0x4F20838D, 0x83438384, 0x838B2083,
    0x89834383, 0x5F815B00, 0x57696E64, 0x79205368, 0x61726B20, 0x536C6173, 0x68205479, 0x70686F6F,
    0x6E000000, 0x83458343, 0x83938366, 0x83422083, 0x56838381, 0x5B834E20, 0x83588389, 0x83628356,
    0x83852083, 0x5E834383, 0x74815B83, 0x93000000, 0x52656420, 0x52657820, 0x4372696D, 0x736F6E20,
    0x4B696E67, 0x0, 0x838C8362, 0x83682083, 0x8C836283, 0x4E835820, 0x834E838A, 0x8380835D,
    0x83932083, 0x4C839383, 0x4F000000, 0x536F6E69, 0x6320536F, 0x6C646965, 0x72204869, 0x67687761,
    0x79204669, 0x67687465, 0x72000000, 0x835C836A, 0x8362834E, 0x20835C83, 0x8B835783, 0x83815B20,
    0x836E8343, 0x83458346, 0x83432083, 0x74834083, 0x43835E81, 0x5B000000, 0x4D617869, 0x6D756D20,
    0x53746172, 0x204F6D65, 0x67612057, 0x697A6172, 0x64000000, 0x837D834C, 0x8356837D, 0x83802083,
    0x58835E81, 0x5B208349, 0x8381834B, 0x20834583, 0x42835581, 0x5B836800, 0x4D6F6F6E, 0x20536E61,
    0x696C204C, 0x756E6172, 0x204C6F62, 0x73746572, 0x0, 0x8380815B, 0x83932083, 0x58836C83,
    0x43838B20, 0x838B8369, 0x815B2083, 0x8D837583, 0x58835E81, 0x5B000000, 0x4372617A, 0x79204275,  /* fzgx-allow: A1 retail data bytes */
    0x6666616C, 0x6F204D69, 0x67687479, 0x20426973, 0x6F6E0000, 0x834E838C, 0x83438357, 0x815B2083,  /* fzgx-allow: A1 retail data bytes */
    0x6F836283, 0x74834083, 0x8D815B20, 0x837D8343, 0x83658342, 0x815B2083, 0x6F834383, 0x5C839300,  /* fzgx-allow: A1 retail data bytes */
    0x53637564, 0x20566970, 0x6572204D, 0x69737479, 0x20536572, 0x70656E74, 0x0, 0x8358834A,
    0x83628368, 0x20836F83, 0x43837081, 0x5B20837E, 0x83588365, 0x83422083, 0x54815B83, 0x79839383,
    0x67000000, 0x526F756E, 0x64204469, 0x736B2046, 0x6C617420, 0x53617563, 0x65720000, 0x83898345,
    0x83938368, 0x20836683, 0x42835883, 0x4E208374, 0x83898362, 0x83672083, 0x5C815B83, 0x54815B00,
    0x456E6572, 0x67792043, 0x72657374, 0x20466576, 0x65722055, 0x6E69636F, 0x726E0000, 0x83478369,
    0x8357815B, 0x20834E83, 0x8C835883, 0x67208374, 0x8342815B, 0x836F815B, 0x20838683, 0x6A835281,
    0x5B839300, 0x4575726F, 0x73202D30, 0x31000000, 0x83478345, 0x838D8358, 0x2D303100, 0x54726961,
    0x6E676C65, 0x202D4754, 0x202D4754, 0x0, 0x83678389, 0x83438341, 0x8393834F, 0x838B2047,
    0x54204754, 0x0, 0x56656C6F, 0x63697479, 0x202D4A20, 0x2D4A0000, 0x8378838D, 0x83568365,
    0x8342204A, 0x204A0000, 0x53756E72, 0x69736520, 0x31343000, 0x83548393, 0x83898343, 0x83592031,
    0x34300000, 0x53617475, 0x726E202D, 0x53470000, 0x8354835E, 0x815B8393, 0x20534700, 0x426C7573,  /* fzgx-allow: A1 retail data bytes */
    0x74657220, 0x2D58202D, 0x58000000, 0x83758389, 0x8358835E, 0x815B2058, 0x20580000, 0x44657669,  /* fzgx-allow: A1 retail data bytes */
    0x6C666973, 0x68202D52, 0x58202D52, 0x58000000, 0x83668372, 0x838B8374, 0x83428362, 0x83568385,
    0x20525820, 0x52580000, 0x4D617273, 0x202D4558, 0x202D4558, 0x0, 0x837D815B, 0x83592045,
    0x58204558, 0x0, 0x54697461, 0x6E202D47, 0x34202D47, 0x34000000, 0x835E8343, 0x835E8393,
    0x20473420, 0x47340000, 0x45787472, 0x656D6520, 0x2D5A5A20, 0x2D5A5A00, 0x8347834E, 0x83588367,
    0x838A815B, 0x8380205A, 0x5A205A5A, 0x0, 0x5468756E, 0x64657262, 0x6F6C7420, 0x2D563220,
    0x2D563200, 0x83548393, 0x835F815B, 0x837B838B, 0x83672056, 0x32205632, 0x0, 0x426F7865,
    0x72202D32, 0x43000000, 0x837B834E, 0x8354815B, 0x20324300, 0x53687574, 0x746C6520, 0x2D4D3220,
    0x2D4D3200, 0x83568383, 0x8367838B, 0x204D3220, 0x4D320000, 0x50756E69, 0x73686572, 0x202D3458,
    0x202D3458, 0x0, 0x8370836A, 0x83568383, 0x815B2034, 0x58203458, 0x0, 0x53636F72,  /* fzgx-allow: A1 retail data bytes */
    0x70696F6E, 0x202D5220, 0x2D520000, 0x83588352, 0x815B8373, 0x83498393, 0x20522052, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x52616964, 0x656E202D, 0x3838202D, 0x38380000, 0x83898343, 0x83668393, 0x20383820, 0x38380000,
    0x496D7075, 0x6C736520, 0x32323000, 0x83438393, 0x8370838B, 0x83582032, 0x32300000, 0x42617A6F,
    0x6F6B6120, 0x2D595300, 0x836F8359, 0x815B834A, 0x20595300, 0x4D657465, 0x6F72202D, 0x5252202D,  /* fzgx-allow: A1 retail data bytes */
    0x52520000, 0x83818365, 0x83492052, 0x52205252, 0x0, 0x54696765, 0x72202D52, 0x5A000000,
    0x835E8343, 0x834B815B, 0x20525A00, 0x486F726E, 0x6574202D, 0x4658202D, 0x46580000, 0x837A815B,
    0x836C8362, 0x83672046, 0x58204658, 0x0, 0x4A757069, 0x74657220, 0x2D510000, 0x83578385,
    0x8373835E, 0x815B2051, 0x0, 0x436F6D65, 0x74202D56, 0x202D5600, 0x83528381, 0x83628367,  /* fzgx-allow: A1 retail data bytes */
    0x20562056, 0x0, 0x43726F77, 0x6E202D37, 0x37202D37, 0x37000000, 0x834E8389, 0x83458393,
    0x20373720, 0x37370000, 0x54726970, 0x6C65202D, 0x5A202D5A, 0x0, 0x8367838A, 0x8376838B,
    0x205A205A, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_462A0[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x20000000
};
static u32 fzgx_pool_data_lbl_1_data_462A4[45] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25730000, 0x25732573, 0x0, 0x25732025, 0x73000000, 0x412B0000, 0x41000000, 0x422B0000,
    0x42000000, 0x432B0000, 0x442B0000, 0x44000000, 0x452B0000, 0x45000000, (u32)fn_1_14EE00__fzgx_offset_64, (u32)fn_1_14EE00__fzgx_offset_88,
    (u32)fn_1_14EE00__fzgx_offset_6C, (u32)fn_1_14EE00__fzgx_offset_88, (u32)fn_1_14EE00__fzgx_offset_74, (u32)fn_1_14EE00__fzgx_offset_88, (u32)fn_1_14EE00__fzgx_offset_7C, (u32)fn_1_14EE00__fzgx_offset_88, (u32)fn_1_14EE00__fzgx_offset_84, 0x426F6479,
    0x0, 0x837B8366, 0x83420000, 0x436F636B, 0x50697400, 0x83528362, 0x834E8373, 0x83628367,
    0x0, 0x426F6F73, 0x74000000, 0x8375815B, 0x83588367, 0x0, 0x70617274, 0x735F2573,
    0x2E74706C, 0x0, 0x43757374, 0x6F6D697A, 0x65000000
};
static u32 fzgx_pool_data_lbl_1_data_43E78_24E0[28] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25732025, 0x73257300, 0x70617274, 0x735F2573, 0x5F302564, 0x656D622E, 0x676D6100, 0x70617274,
    0x735F2573, 0x5F656D62, 0x2E676D61, 0x0, 0x505B2564, 0x5D3A2025, 0x73202C20, 0x2573202C,
    0x2025730A, 0x0, 0x505B2564, 0x5D20496E, 0x76616C69, 0x64202E2E, 0x2E0A0000, 0x25336420,
    0x0, 0x2533640A, 0x0, 0x0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_data_43E78(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_43E78;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_43E78_9A0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_44F58;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_462A0;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_462A4;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_43E78_24E0;
}
#pragma section code_type ".text"

char *fn_1_14FEAC(s16 arg0, s16 arg1, s16 arg2, char *out, s16 arg4) {
    s16 i;
    NameCache *cache;
    s16 k;
    char *p0;
    char *p1;
    char *p2;
    u32 code;
    u32 flags;
    s32 n;
    s16 j;
    char *tok;
    char *str;
    char *s2;
    char *s1;
    u32 found;
    s16 idx;
    NameFlags table;
    char part2[2][0x20];
    char part1[2][0x20];
    char part0[2][0x20];
    char name2[0x40];
    char name1[0x40];
    char name0[0x40];
    char tok0[0x40];
    char tok1[0x40];
    char tok2[0x40];
    s32 key;

    code = (arg0 << 10) | ((arg1 - 25) << 5) | (arg2 - 50);
    key = (s16)code;
    
    found = fn_8007E96C((u32)&key, (u32)lbl_1_bss_8E6B0, 77, 4, (Sig_fn_8007E96C_fn_8007E96C_Compare)fn_1_14FD6C);
    if (found == 0) {
        idx = -1;
    } else {
        idx = ((s32)found - (s32)lbl_1_bss_8E6B0) / 4;
    }
    if (idx != -1) {
        fn_80083DB0(out, ((char *(*)[6])fzgx_pool_data_lbl_1_data_43E78_9A0)[idx][arg4]);
        goto done; /* share the final output return with the cache update path */
    }
    cache = (NameCache *)lbl_1_bss_8E7E4;
    for (i = 0; i < 20; i++) {
        if (cache->entries[i].key == code && arg4 == cache->entries[i].id) {
            fn_80083DB0(out, cache->entries[i].str);
            return out;
        }
    }
    n = 0;
    table = *(NameFlags *)lbl_1_rodata_99D8;
    flags = table.flags[arg2];
    if (flags & 8) {
        fn_1_14EBF8(arg0, name0, arg4);
    } else {
        fn_1_14EA74(arg0, name0, arg4);
    }
    if (flags & 4) {
        fn_1_14EBF8(arg2, name2, arg4);
    } else {
        fn_1_14EA74(arg2, name2, arg4);
    }
    if (flags & 0x10) {
        fn_1_14EBF8(arg1, name1, arg4);
    } else {
        fn_1_14EA74(arg1, name1, arg4);
    }
    p0 = part0[0];
    p1 = part1[0];
    p2 = part2[0];
    for (k = 0; k < 2; k++) {
        /* take the k-th token of each name, or the whole name if it has fewer */
        fn_80083DB0(tok0, name0);
        str = tok0;
        for (j = 0; (tok = fn_800839D8(str, (char *)((u8 *)fzgx_pool_data_lbl_1_data_462A0))) != NULL; j++) {
            if (j == k) {
                fn_80083DB0(p0, tok);
                goto found0; /* token found: skip the whole-name fallback */
            }
            str = NULL;
        }
        fn_80083DB0(p0, name0);
found0:
        fn_80083DB0(tok1, name1);
        str = tok1;
        for (j = 0; (tok = fn_800839D8(str, (char *)((u8 *)fzgx_pool_data_lbl_1_data_462A0))) != NULL; j++) {
            if (j == k) {
                fn_80083DB0(p1, tok);
                goto found1; /* token found: skip the whole-name fallback */
            }
            str = NULL;
        }
        fn_80083DB0(p1, name1);
found1:
        fn_80083DB0(tok2, name2);
        str = tok2;
        for (j = 0; (tok = fn_800839D8(str, (char *)((u8 *)fzgx_pool_data_lbl_1_data_462A0))) != NULL; j++) {
            if (j == k) {
                fn_80083DB0(p2, tok);
                goto found2; /* token found: skip the whole-name fallback */
            }
            str = NULL;
        }
        fn_80083DB0(p2, name2);
found2:
        p0 += 0x20;
        p1 += 0x20;
        p2 += 0x20;
    }
    s1 = part0[0];
    s2 = part1[1];
    if (flags & 1) {
        s1 = part1[0];
        s2 = part0[1];
    }
    if (flags & 2) {
        n = fn_1_14ED00(arg2, name2, arg4);
    }
    sprintf(out, (char *)((u8 *)fzgx_pool_data_lbl_1_data_43E78_24E0), s1, s2, n);
    fn_80083DB0(cache->entries[cache->next].str, out);
    cache->entries[cache->next].key = code;
    cache->entries[cache->next].id = arg4;
    n = cache->next + 1;
    cache->next = (n > 19) ? 0 : ((n < 0) ? 19 : n);
done:
    return out;
}
/* fzgx:end fn_1_14FEAC */

/* fzgx:begin fn_1_1502BC */
extern int sprintf(char *s, const char *format, ...);
extern size_t strlen(const char *str);
extern u8 lbl_8015B200[];
extern void fn_1_12AB38(void *arg0);
extern void *fn_1_12ADA0(char *dst, void *arg);
extern void fn_1_8019C(void *arg0);

struct Entry {
	void *a;
	void *b;
};

struct Group {
	struct Entry e[6];
};

struct Names {
	u8 *p[75];
};

extern struct Names lbl_1_rodata_CE10;

static inline void fn_1_1502BC_load(struct Group *g, s16 v, s16 mask, char *data)
{
	s16 j;
	s16 k;
	struct Names names;
	char buf[64];

	names = lbl_1_rodata_CE10;

	for (j = 0; j < strlen((const char *)names.p[v]); j++) {
		u8 c = names.p[v][j];

		names.p[v][j] = (c == -1) ? -1 : lbl_8015B200[c];
	}

	for (k = 0; k < 3; k++) {
		if ((mask & (1 << k)) != 0 && g->e[k].a == 0) {
			if (k != 0) {
				sprintf(buf, data + 0x24e8, names.p[v], k + 1);
			} else {
				sprintf(buf, data + 0x24fc, names.p[v]);
			}
			g->e[k].b = 0;
			g->e[k].a = fn_1_12ADA0(buf, g->e[k].b);
			fn_1_8019C(g->e[k].a);
		}
	}
}

struct Group *fn_1_1502BC(struct Group *arg0, s16 *arg1, s16 arg2)
{
	char *data = (char *)lbl_1_data_43E78;
	s16 i;

	fn_1_12AB38(data + 5004);

	for (i = 0; i < 3; i++) {
		fn_1_1502BC_load(&arg0[i], arg1[i], arg2, data);
	}

	fn_1_12AB38(data + 5000);
	return arg0;
}
/* fzgx:end fn_1_1502BC */

/* fzgx:begin fn_1_150464 */
void fn_1_150464(u32 arg0) {
    u32 v2;
    u32 v1;
    s32 v0;
    struct { s32 value; } v3;
    u32 v4;
    u32 v5;
    v0 = 0;
    v1 = arg0;
    while ((s16)v0 < 3) {
    v2 = v1;
    v3.value = 0;
    while ((s16)v3.value < 3) {
    v4 = *(u32 *)((u8 *)v2 + 0);
    if (v4 != 0) {
    fn_800711A8( (void *)((struct Sig_fn_800711A8_fn_800711A8_Arg0 *)v4));
    *(u32 *)((u8 *)v2 + 0) = 0;
    }
    v5 = *(u32 *)((u8 *)v2 + 4);
    if (v5 != 0) {
    fn_80071718( (void *)((struct Sig_fn_80071718_fn_80071718_Arg0 *)v5));
    *(u32 *)((u8 *)v2 + 4) = 0;
    }
    v2 += 8;
    v3.value++;
    }
    v1 += 48;
    v0++;
    }
}
/* fzgx:end fn_1_150464 */

/* fzgx:begin fn_1_150500 */
void fn_1_150500(void) {
    lbl_1_data_2A7E0.unk_3C->unk_0 = 0;
}
/* fzgx:end fn_1_150500 */

/* fzgx:begin fn_1_150518 */
// Reset the active object's counters and re-run its two setup passes.
void fn_1_150518(void) {
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;

    obj->unk_84 = 0;
    obj->unk_2724 = 0;
    fn_1_9A508(&lbl_1_data_2A7E0);
    fn_1_150C8C( (fn_1_150C8C_Object *)(Obj_1_data_2A7E0_At3C *)(obj));
    fn_1_150F30( (fn_1_150F30_StaticDisp *)(Obj_1_data_2A7E0_At3C *)(obj));
    obj->unk_0 = 1;
}
/* fzgx:end fn_1_150518 */

/* fzgx:begin fn_1_150570 */
// fn_1_150570: empty in retail (single blr).
void fn_1_150570(void) {
}
/* fzgx:end fn_1_150570 */

/* fzgx:begin fn_1_150574 */
// Initializes the static display object referenced by the main state.
void fn_1_150574(void) {
    Obj_1_data_2A7E0_At3C *display = lbl_1_data_2A7E0.unk_3C;

    fn_1_150CEC(display);
    fn_1_151668( (fn_1_151668_StaticDisp *)(void *)(display));
}
/* fzgx:end fn_1_150574 */

/* fzgx:begin fn_1_1505B4 */
// Refreshes the static display state and applies the current object selection.
void fn_1_1505B4(void) {
    Obj_1_data_2A7E0_At3C *display_state;
    u32 result;

    display_state = lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD54();
    result = fn_1_9D260();
    fn_1_150D3C(display_state, result);
    fn_1_150654();
    fn_1_151054(display_state);
}
/* fzgx:end fn_1_1505B4 */

/* fzgx:begin fn_1_150608 */
// Prepare the static display state and pass it to the display routine.
void fn_1_150608(void) {
    Obj_1_data_2A7E0_At3C *value;
    u32 result;

    value = lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD88();
    result = fn_1_9D260();
    fn_1_150ED0(value, result);
}
/* fzgx:end fn_1_150608 */

/* fzgx:begin fn_1_150650 */
// fn_1_150650: empty in retail (single blr).
void fn_1_150650(void) {
}
/* fzgx:end fn_1_150650 */

/* fzgx:begin fn_1_150654 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f64 unk_18;
} PoolCF40;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

typedef struct {
    u8 pad[0x24];
} Entry24;

extern PoolCF40 lbl_1_rodata_CF40;
extern u32 lbl_801A63C0;
extern s16 fn_1_3F0C8(Obj_1_data_2A7E0 *);
extern void fn_1_1507C4(Entry24 *, Vec3 *);

#pragma opt_propagation off
static inline s32 *fn_1_150654_array_read(s32 *array) { return array; }
void fn_1_150654(void) {
    s32 *counters;
    s32 i;
    Entry24 *entries;
    s32 *base;
    s32 x;

    base = (s32 *)lbl_1_data_2A7E0.unk_3C;
    if (fn_1_3F0C8(&lbl_1_data_2A7E0) == 40) {
        return;
    }

    counters = base;

    entries = (Entry24 *)lbl_1_bss_3BE0->unk_A8;
    i = 0;
    while (i < (s32)lbl_1_bss_3BE0->unk_A4) {
        u32 n = lbl_801A63C0 * 0x676A4B6B + 0x33CB;

{
    u32 *seed = &lbl_801A63C0;
        *seed = n;
}
        x = (n >> 16) & 0x7FFF;
        if (x % 70 == 0) {
            u32 m = n * 0x676A4B6B + 0x33CB;

            lbl_801A63C0 = m;
            x = (m >> 16) & 0x7FFF;
            counters[1] = (s16)(20.0f + (f32)(10.0f * ((f32)x / 32767.0f)));
        }
        if (fn_1_150654_array_read(counters)[1] != 0) {
            counters[1] = fn_1_150654_array_read(counters)[1] - 1;
            {
                Vec3 v = {0x00000000u, 0xBF800000u, 0x00000000u};

                fn_1_1507C4(entries, &v);
            }
        }
        counters = counters + 1;
        i = i + 1;
        entries = (Entry24 *)((u8 *)entries + 0x24);
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_150654 */

/* fzgx:begin fn_1_150C8C */
// Marks each static display entry active before updating it.
void fn_1_150C8C(fn_1_150C8C_Object *obj) {
    s32 count;
    fn_1_150C8C_Entry *entry;

    count = obj->count;
    entry = obj->entries;
    while (count > 0) {
        entry->active = 1;
        fn_1_103090(entry);
        count -= 1;
        entry += 1;
    }
}
/* fzgx:end fn_1_150C8C */

/* fzgx:begin fn_1_150CEC */
typedef struct fn_1_150CEC_Entry {
    u8 data[0xac];
} fn_1_150CEC_Entry;

typedef struct fn_1_150CEC_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150CEC_Entry entries[1];
} fn_1_150CEC_Object;

void fn_1_150CEC(fn_1_150CEC_Object *obj) {
    s32 count;
    fn_1_150CEC_Entry *entry;

    count = obj->count;
    entry = obj->entries;
    while (count > 0) {
        fn_1_1030A4(entry);
        count -= 1;
        entry += 1;
    }
}
/* fzgx:end fn_1_150CEC */

/* fzgx:begin fn_1_150D3C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[3] = {0x00000000, 0xBF800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
    s = 10.0f;
    s = 32767.0f;
    d = 4503601774854144.0;
    s = -1.1920928955078125e-07f;
    s = 2400.0f;
    s = 50.0f;
    s = 0.5f;
    s = 60.0f;
    s = 0.20000000298023224f;
    s = 0.800000011920929f;
    s = 0.699999988079071f;
    s = 0.30000001192092896f;
    s = 7.0f;
    d = 0.5;
    s = 255.0f;
    s = 1.0f;
    s = 102.0f;
    s = 0.0f;
    s = 0.0005000000237487257f;
    s = 0.003000000026077032f;
    s = 0.6499999761581421f;
    s = 0.75f;
    s = 182.04444885253906f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

extern void fn_1_1030D4(void *entry, void *arg);
extern f64 lbl_8006D188(s32 value);
extern u32 lbl_801A66A0;

typedef struct Pool {
    u8 pad_00[0x48];
    f64 c48;
    u8 pad_50[4];
    f32 c54;
    u8 pad_58[4];
    f32 c5c;
    u8 pad_60[8];
    f32 c68;
    f32 c6c;
    f32 c70;
    u8 pad_74[4];
    f64 c78;
    f64 c80;
} Pool;

extern const Pool lbl_1_rodata_CF40;

typedef struct Entry {
    u8 pad_08[8];
    u32 flags;
    u8 pad_0c[0x20];
    f32 x;
    f32 y;
    f32 z;
    u8 tail[0x74];
} Entry;

typedef struct Object {
    u8 pad_84[0x84];
    s32 count;
    Entry entries[1];
} Object;

void fn_1_150D3C(Object *obj, void *arg) {
    s32 count;
    Entry *entry;

    count = obj->count;
    entry = obj->entries;
    while (count > 0) {
        if (((entry->flags >> 28) & 1) != 0) {
            entry->x = (0.649999976f);
            entry->y = (0.75f);
            entry->z = (1.0f);
        } else if (((entry->flags >> 29) & 1) != 0) {
            entry->x = (1.0f);
            entry->y = (0.0f);
            entry->z = (0.0f);
        } else {
            entry->x = (f32)__fabs(
                lbl_8006D188((s32)((182.044449f) * (f32)lbl_801A66A0)));
            entry->y = (f32)__fabs(
                lbl_8006D188((s32)((182.044449f) * (f32)lbl_801A66A0 * (0.5))));
            entry->z = (f32)__fabs(
                lbl_8006D188((s32)((182.044449f) * (f32)lbl_801A66A0 * (2.0))));
        }
        fn_1_1030D4(entry, arg);
        count -= 1;
        entry += 1;
    }
}
/* fzgx:end fn_1_150D3C */

/* fzgx:begin fn_1_150ED0 */
typedef struct fn_1_150ED0_Entry {
    u8 data[0xac];
} fn_1_150ED0_Entry;

typedef struct fn_1_150ED0_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150ED0_Entry entries[1];
} fn_1_150ED0_Object;

void fn_1_150ED0(fn_1_150ED0_Object *obj, void *arg) {
    s32 count;
    fn_1_150ED0_Entry *entry;

    count = obj->count;
    entry = obj->entries;
    while (count > 0) {
        fn_1_103264(entry, arg);
        count -= 1;
        entry += 1;
    }
}
/* fzgx:end fn_1_150ED0 */

/* fzgx:begin fn_1_150F30 */
// Reset the display state before rebuilding its static entries.
void fn_1_150F30(fn_1_150F30_StaticDisp *self) {
    self->unk_2728 = 0;
    self->unk_272c = -1;
    fn_1_150F74(self);
    fn_1_151668( (fn_1_151668_StaticDisp *)(void *)(self));
}
/* fzgx:end fn_1_150F30 */

/* fzgx:begin fn_1_150F74 */
typedef struct fn_1_150F74_Object {
    u8 pad_0[0x2730];
    f32 value_2730;
    f32 value_2734;
    f32 value_2738;
    f32 value_273c;
    u8 pad_2740[4];
    f32 value_2744;
} fn_1_150F74_Object;

typedef struct fn_1_150F74_Entry {
    u8 pad_0[0x1824];
    f32 value_1824;
    f32 value_1828;
    f32 value_182c;
    f32 value_1830;
    f32 value_1834;
    f32 value_1838;
    f32 value_183c;
    f32 value_1840;
    f32 value_1844;
    f32 value_1848;
    u8 pad_184c[0xc];
    u32 *bits;
    u8 flag_185c;
    u8 flag_185d;
    u8 flag_185e;
    u8 flag_185f;
} fn_1_150F74_Entry;

// Initialize display values and propagate enabled display flags across all entries.
void fn_1_150F74(void *self) {
    fn_1_150F74_Object *obj;
    const f32 *constants;
    fn_1_150F74_Entry *entry;
    u32 *bit_flags;
    s32 index;

    obj = (fn_1_150F74_Object *)self;
    constants = lbl_1_rodata_CF40;
    obj->value_2730 = constants[58];
    obj->value_2734 = constants[23];
    obj->value_2738 = constants[23];
    obj->value_273c = constants[59];
    obj->value_2744 = constants[60];

    entry = (fn_1_150F74_Entry *)obj;
    for (index = 0; index < 0x40; index++) {
        bit_flags = entry->bits;
        if (entry->flag_185c != 0) {
            entry->value_1824 = obj->value_2730;
            entry->value_1828 = constants[23];
            entry->value_182c = constants[23];
            *bit_flags |= ((u32)1 << 31);
        }
        if (entry->flag_185d != 0) {
            entry->value_1824 = constants[23];
            entry->value_1828 = constants[23];
            entry->value_182c = constants[23];
            entry->value_1830 = constants[23];
        }
        if (entry->flag_185d != 0 || entry->flag_185e != 0) {
            entry->value_1834 = constants[23];
            entry->value_1840 = constants[23];
            entry->value_1838 = constants[23];
            entry->value_1844 = constants[23];
            entry->value_183c = constants[23];
            entry->value_1848 = constants[23];
        }
        if (entry->flag_185f != 0) {
            *bit_flags &= 0x7fffffff;
        }
        entry = (fn_1_150F74_Entry *)((u8 *)entry + 0x3c);
    }
}
/* fzgx:end fn_1_150F74 */

/* fzgx:begin fn_1_151054 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern const f32 lbl_1_rodata_CF40[12];
extern s32 fn_1_58C4(void);
extern void fn_1_5948(s32 index);
extern s16 camera_get_mode(void);
extern void fn_1_627C(s32 index);

typedef struct CameraState151054 {
    u8 pad_0[0x118];
    s32 unk_118;
} CameraState151054;
extern CameraState151054 *fn_1_8627C(s32 mode);

typedef struct Rotation151054 {
    u32 unk_0;
    f32 unk_4;
} Rotation151054;

typedef struct Display151054 {
    u32 unk_0;
    u8 pad_4[0xC];
    f32 unk_10;
    u8 pad_14[0x20];
    Rotation151054 **unk_34;
} Display151054;

typedef struct Entry151054 {
    f32 unk_1824;
    f32 unk_1828;
    f32 unk_182C;
    f32 unk_1830;
    f32 unk_1834;
    f32 unk_1838;
    f32 unk_183C;
    f32 unk_1840;
    f32 unk_1844;
    f32 unk_1848;
    f32 unk_184C;
    f32 unk_1850;
    f32 unk_1854;
    Display151054 *unk_1858;
    u8 unk_185C;
    u8 unk_185D;
    u8 unk_185E;
    u8 unk_185F;
} Entry151054;

typedef struct State151054 {
    u8 pad_0[0x1824];
    Entry151054 entries[64];
    s32 unk_2724;
    s32 unk_2728;
    s32 unk_272C;
    f32 unk_2730;
    f32 unk_2734;
    f32 unk_2738;
    f32 unk_273C;
    f32 unk_2740;
    f32 unk_2744;
} State151054;

#define clamp151054(value, min, max) ((value) < (min) ? (min) : (value) > (max) ? (max) : (value))

void fn_1_151054(State151054 *arg0) {
    s32 i;
    s32 count;
    const f32 *pool = lbl_1_rodata_CF40;
    CameraState151054 *camera;

    if (arg0->unk_2728 == 0 && arg0->unk_272C == -1) {
        count = fn_1_58C4();
        if (count == 1) {
            for (i = 0; i < count; i++) {
                fn_1_5948(i);
                {
                    s32 mode = camera_get_mode();
                    if (mode >= 0) {
                        camera = fn_1_8627C(mode);
                        if (camera != 0 && camera->unk_118 + 1 == 3) {
                            arg0->unk_272C = 0;
                            break;
                        }
                    }
                }
                fn_1_627C(i);
            }
        }
    }
    if (arg0->unk_2728 == 0 && arg0->unk_272C != -1) {
        arg0->unk_272C++;
        if (arg0->unk_272C > 1000) {
            arg0->unk_2728 = 1;
            arg0->unk_272C = -1;
        }
    }
    if (arg0->unk_2728 != 0) {
        arg0->unk_2740 = clamp151054(pool[0x54/4] + arg0->unk_2740, pool[0x5C/4], pool[0xF4/4]);
    }
    if (arg0->unk_2728 != 0) {
        for (i = 0; i < arg0->unk_2724; i++) {
            Entry151054 *entry = &arg0->entries[i];
            Display151054 *display = entry->unk_1858;
            if (entry->unk_185C || entry->unk_185D) {
                f32 duration;
                f32 elapsed;
                elapsed = arg0->unk_2740;
                duration = arg0->unk_2744;
                if (elapsed < duration) {
                    entry->unk_1828 = pool[0xF8/4] * elapsed / duration;
                } else {
                    f32 speed = (pool[0xF8/4] * elapsed / duration) +
                        (pool[0x90/4] * (elapsed - duration) / duration);
                    f32 limit = pool[0x5C/4];
                    if (entry->unk_185C) {
                        limit = pool[0xFC/4] * (arg0->unk_2734 - entry->unk_1824);
                    } else if (entry->unk_185D) {
                        limit = pool[0xFC/4] * (arg0->unk_273C - entry->unk_1824);
                    }
                    entry->unk_1828 = speed > limit ? speed : limit;
                }
                if (entry->unk_1828 > pool[0x5C/4] || entry->unk_182C != pool[0x5C/4]) {
                    /* Keep the reset's independent pool read; do not reuse the comparison load. */
                    entry->unk_1828 = *(volatile const f32 *)&pool[0x5C/4];
                }
                if (entry->unk_185C) {
                    entry->unk_1824 = clamp151054(entry->unk_1828 + entry->unk_1824, arg0->unk_2734, arg0->unk_2730);
                    if (entry->unk_1824 == arg0->unk_2734) {
                        entry->unk_182C = pool[0x54/4];
                    }
                } else if (entry->unk_185D) {
                    entry->unk_1824 = clamp151054(entry->unk_1828 + entry->unk_1824, arg0->unk_273C, arg0->unk_2738);
                    if (entry->unk_1824 == arg0->unk_273C) {
                        entry->unk_182C = pool[0x54/4];
                    }
                }
            }
            if (entry->unk_185D || entry->unk_185E) {
                if (entry->unk_185D) {
                    s32 axis;
                    struct { f32 value; } zero;
                    zero.value = pool[0x5C/4];
                    for (axis = 0; axis < 3; axis++) {
                        f32 elapsed = arg0->unk_2740;
                        f32 duration = arg0->unk_2744;
                        if (elapsed < duration) {
                            f32 initial = (&entry->unk_184C)[axis];
                            elapsed = initial * elapsed;
                            elapsed /= duration;
                            elapsed = initial - elapsed;
                            (&entry->unk_1840)[axis] = elapsed;
                        } else {
                            (&entry->unk_1840)[axis] = zero.value;
                        }
                    }
                }
                if (entry->unk_185E) {
                    s32 axis;
                    f32 zero;
                    f32 factor = pool[0x100/4];
                    zero = pool[0x5C/4];
                    for (axis = 0; axis < 3; axis++) {
                        f32 duration = arg0->unk_2744;
                        if (factor * arg0->unk_2740 < duration) {
                            (&entry->unk_1840)[axis] = (&entry->unk_184C)[axis];
                        } else {
                            f32 initial = (&entry->unk_184C)[axis];
                            f32 value = initial - initial * (factor * arg0->unk_2740 - duration) / duration;
                            if (zero > value) value = zero;
                            (&entry->unk_1840)[axis] = value;
                        }
                    }
                }
                {
                    f32 scale = pool[0x30/4];
                    entry->unk_1834 += entry->unk_1840;
                    entry->unk_1838 += entry->unk_1844;
                    entry->unk_183C += entry->unk_1848;
                    if (display->unk_34 != 0 && display->unk_34[0] != 0) {
                        display->unk_34[0]->unk_4 = scale * entry->unk_1834 / lbl_1_data_2A7E0.unk_1C;
                    }
                    if (display->unk_34 != 0 && display->unk_34[1] != 0) {
                        display->unk_34[1]->unk_4 = scale * entry->unk_1838 / lbl_1_data_2A7E0.unk_1C;
                    }
                    if (display->unk_34 != 0 && display->unk_34[2] != 0) {
                        display->unk_34[2]->unk_4 = scale * entry->unk_183C / lbl_1_data_2A7E0.unk_1C;
                    }
                }
            }
            if (entry->unk_185C) {
                display->unk_0 &= 0x7FFFFFFF;
            }
            if (entry->unk_185F) {
                display->unk_0 |= 0x80000000;
            }
        }
    }
    for (i = 0; i < arg0->unk_2724; i++) {}
    for (i = 0; i < arg0->unk_2724; i++) {
        Entry151054 *entry = &arg0->entries[i];
        Display151054 *display = entry->unk_1858;
        if (entry->unk_185C || entry->unk_185D) {
            display->unk_10 = entry->unk_1830 + entry->unk_1824;
        }
    }
}
/* fzgx:end fn_1_151054 */

/* fzgx:begin fn_1_151668 */
void fn_1_151668(fn_1_151668_StaticDisp *self) {
    s32 i;
    s32 j;

    self->value_2728 = 0;
    self->value_272c = -1;
    for (i = 0; i < self->entry_count; i++) {
        fn_1_151668_StaticDispEntry *entry = &self->entries[i];
        DispObject *object = entry->object;

        if (entry->active != 0) {
            object->value = entry->first;
            object->flags |= (u32)1 << 31;
        }
        if (entry->scale_first != 0 || entry->scale_second != 0) {
            f32 scale = lbl_1_rodata_CF70[0];
            for (j = 0; j < 3; j++) {
                if (object->children != 0 && object->children->child[j] != 0) {
                    object->children->child[j]->value = scale * entry->values[j];
                }
            }
        }
        if (entry->clear_flag != 0) {
            object->flags &= ~((u32)1 << 31);
        }
    }
}
/* fzgx:end fn_1_151668 */

/* fzgx:begin fn_1_151764 */
// fn_1_151764: returns a constant.
int fn_1_151764(void) {
    return 1;
}
/* fzgx:end fn_1_151764 */
