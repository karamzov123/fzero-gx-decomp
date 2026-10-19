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

/* fzgx:begin fn_1_14A9CC */
// fn_1_14A9CC: empty in retail (single blr).
void fn_1_14A9CC(void) {
}
/* fzgx:end fn_1_14A9CC */

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

/* fzgx:begin fn_1_14B4FC */
// fn_1_14B4FC: empty in retail (single blr).
void fn_1_14B4FC(void) {
}
/* fzgx:end fn_1_14B4FC */

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
