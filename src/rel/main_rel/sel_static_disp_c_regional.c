/* Previously matched Japan/PAL units of sel_static_disp_c.c, retained until that TU matches those releases as one unit. */
#include "types.h"
#include "game/pad.h"
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
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 lbl_801A66B4;
extern void fn_1_14E9E4(int arg0, void *arg1);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern char *strcpy(char *dst, const char *src);
extern s32 fn_1_3F864(void);
extern void fn_1_A2D84(u32 arg0);
extern void fn_1_14A9D0(u8, int, int, int, int, int);
extern void fn_1_14BFD8(void *, void *, int);
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
extern s16 fn_1_14F344(s16);
extern u8 lbl_1_rodata_9CDC[1200];
extern Fn1_14E9E4Entry *fn_1_14F608(int arg0);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_1_rodata_A18C[1800];
extern s32 fn_1_14FE48(void *arg0, void *arg1);
extern void *fn_1_14FDAC(void *arg0, void *arg1, s16 arg2, void *arg3);
extern const u8 lbl_1_rodata_AF9C[2040];
extern u8 lbl_1_rodata_B794[240];
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 lbl_1_rodata_99D8[75];
extern u8 lbl_1_rodata_CB98[324];
extern void fn_1_465D0(char *, int);
extern s32 fn_1_14FD6C(s32 *arg0, s32 *arg1);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern char *strtok(char *string, const char *delimiters);
extern void fn_1_150C8C(fn_1_150C8C_Object *obj);
extern void fn_1_150F30(fn_1_150F30_StaticDisp *self);
extern f32 lbl_1_rodata_CF70[54];
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

/* fzgx:begin fn_1_14EEC4 */
typedef struct {
    u32 values[3][6];
} StaticDispTable;

void *fn_1_14EEC4(s16 index, void *obj, s16 subindex) {
    StaticDispTable table;

    table = *(StaticDispTable *)lbl_1_rodata_B884;
    strcpy( obj, (const char *)(table.values[index][subindex]));
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

    fn_1_14E9E4( (int)(arg0), (Fn1_14EF40Value *)(&value));
    accum = value.value;
    fn_1_14E9E4( (int)(arg1), (Fn1_14EF40Value *)(&value));
    accum = (accum + value.value);
    fn_1_14E9E4( (int)(arg2), (Fn1_14EF40Value *)(&value));
    return (accum + value.value);
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
