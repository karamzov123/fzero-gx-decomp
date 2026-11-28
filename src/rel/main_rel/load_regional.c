/* Previously matched Japan/PAL units of load.c, retained until that TU matches those releases as one unit. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/load.h"
#include "dolphin/dvd.h"
#include "sdk_addresses.h"




typedef void (*ARQCallback)(u32 pointerToARQRequest);

typedef struct ARQRequest {
    struct ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    ARQCallback callback;
} ARQRequest;

typedef struct Fn464BCEntry {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Fn464BCEntry;

typedef struct Fn464BCObject {
    u8 unk_00[4];
    Fn464BCEntry *unk_04;
    u8 unk_08[8];
    u8 *unk_10;
} Fn464BCObject;

typedef struct fn_1_45BF0_LoadEntry {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_c;
} fn_1_45BF0_LoadEntry;

typedef struct {
    u8 pad_0[8];
    u32 aram;
    u32 end;
} LoadArchive;

typedef void (*fn_1_458A0_Sig_ARQPostRequest_ARQCallback)(u32 pointerToARQRequest);

typedef struct fn_1_458A0_Sig_ARQPostRequest_ARQRequest {
    struct fn_1_458A0_Sig_ARQPostRequest_ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    fn_1_458A0_Sig_ARQPostRequest_ARQCallback callback;
} fn_1_458A0_Sig_ARQPostRequest_ARQRequest;

typedef void (*fn_1_45E98_Sig_ARQPostRequest_ARQCallback)(u32);

typedef struct fn_1_45E98_Sig_ARQPostRequest_ARQRequest {
    struct fn_1_45E98_Sig_ARQPostRequest_ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    fn_1_45E98_Sig_ARQPostRequest_ARQCallback callback;
} fn_1_45E98_Sig_ARQPostRequest_ARQRequest;

typedef struct {
    void *header;
    void *data;
    void *table;
    u32 count;
    void *end;
    u32 unk_14;
    u32 unk_18;
} Fn8006A3DCResult;

typedef struct Sig_fn_8006A3DC_Fn8006A3DCHeader {
    u32 magic;
    u32 data_offset;
    u32 unk_8;
    u32 table_offset;
} Sig_fn_8006A3DC_Fn8006A3DCHeader;

typedef struct Sig_fn_8006A3DC_Fn8006A3DCResult {
    void *header, *data, *table;
    u32 count;
    void *end;
    u32 unk_14;
    u32 unk_18;
} Sig_fn_8006A3DC_Fn8006A3DCResult;
extern s32 fn_1_45E84(s32);
extern fn_1_45BF0_LoadEntry *fn_1_45BF0(u32 size);
extern void fn_1_45BE0(void);
extern void fn_1_45BA4(s32);
extern void fn_1_451D4(void);
extern int fn_1_46144(LoadArchive *archive, s32 locked, s32 named);
extern void *memset(void *, int, u32);
extern u32 fn_80006C2C(s32 arg0, u32 arg1);
extern void *fn_80006DE8(void *);
extern u32 fn_80006CE4(u32);
extern u32 fn_80006DAC(void *, void *, u32, u32, void *, void *, u32);
extern void ARQPostRequest(ARQRequest *request, u32 owner, u32 type, u32 priority, u32 source, u32 dest, u32 length, ARQCallback callback);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void fn_1_45E98(u32 arg0, void *arg1);
extern s32 fn_8000700C();
extern void DCInvalidateRange(void *, u32);
extern void fn_1_45890(void);
extern void fn_1_D3214(void);
extern int fn_1_45AD4(void);
extern u32 fn_80006D1C(void *arg0);
extern void fn_1_45A58(u32 arg0);
extern u32 lbl_1_bss_3DCE4[17];
extern void *fn_80006DFC(void *arg);
extern void fn_1_3BDC(u32 arg0);
extern void fn_8000659C(void);
extern u32 lbl_1_bss_384C4;
extern u32 fn_1_46A8C(u32 value);
extern u32 lbl_1_bss_3DCD8;
extern u32 lbl_1_bss_3DD28[179];
extern void fn_1_47EE4(s32 index);
extern void fn_1_485C8(u32 arg0);
extern void fn_1_48140(int index);
extern void fn_1_4DDC0(void);
extern void fn_1_4F724(void);
extern u8 lbl_1_bss_3E024[52];
extern char lbl_1_data_1A3AC[5];
extern char *strcpy(char *dst, const char *src);
extern u32 lbl_801A6410;
extern u32 fn_1_4630();
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern char *strcat(char *dest, const char *src);
extern void fn_1_48004(s32 index, s32 image);
extern int fn_1_45D78(u32 start, u32 size, u32 *out_end, s32 mode);
extern int fn_1_45CD8(int);
extern s32 fn_8006A3DC(void *header, Fn8006A3DCResult *result);
extern void fn_80006FE0(u32 arg0, u32 arg1);
extern s32 fn_8006A554(void *, void *);
extern u8 fn_1_451E4__fzgx_offset_104[];
extern u8 fn_1_451E4__fzgx_offset_110[];
extern u8 fn_1_451E4__fzgx_offset_11C[];
extern u8 fn_1_451E4__fzgx_offset_128[];
extern u8 fn_1_451E4__fzgx_offset_26C[];
extern u8 fn_1_451E4__fzgx_offset_298[];
extern u8 fn_1_451E4__fzgx_offset_39C[];
extern u8 fn_1_451E4__fzgx_offset_3D8[];
extern u8 fn_1_451E4__fzgx_offset_534[];
extern u8 fn_1_451E4__fzgx_offset_64[];
extern u8 fn_1_451E4__fzgx_offset_78[];
extern u8 fn_1_451E4__fzgx_offset_A0[];
extern u8 fn_1_451E4__fzgx_offset_C0[];
extern u8 fn_1_451E4__fzgx_offset_EC[];
extern u8 fn_1_451E4__fzgx_offset_F8[];
extern u32 fn_1_46EC8(void);
extern u32 fn_1_46ED8(void);
extern void fn_1_464BC(Fn464BCObject *object, u32 index, void *arg2, void *arg3);
extern void OSReport(const char *msg, ...);
extern u32 fn_1_467F4(void);
extern void fn_1_469BC(void);
extern u32 lbl_1_bss_958[2];
extern void fn_80074918(u8 arg0, s32 arg1, u8 arg2);
extern void fn_80074788(u32 arg0);
extern void fn_80074660(u32 arg0);
extern void fn_80073678(u32 arg0);
extern void fn_80073C6C(s32 index);
extern void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6);
extern void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2);
extern void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
extern void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_80072864(u32 arg0);
extern void fn_8007245C(u32 value);
extern u32 fn_800371F8(u32, void *);
extern void fn_8003462C(u32 type, u32 vtxfmt, u16 nverts);

/* fzgx:begin fn_1_46A60 */
void fn_1_46A60(void) {
    fn_1_46A8C(lbl_1_bss_3DCDC);
}
/* fzgx:end fn_1_46A60 */

/* fzgx:begin fn_1_46A8C */
typedef struct {
    u32 type;
    u32 value;
    u32 unk_8;
} Entry;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8[0x4010];
    Entry entries[0x200];
} State;


u32 fn_1_46A8C(u32 value) {
    State *base;
    s32 next;
    s32 current;
    u32 initial;
    u32 arg;
    Entry *entry;

    base = (State *)&lbl_1_bss_384C0;
    arg = value;
    initial = base->unk_0;
    next = initial + 1;
    current = initial;
    if (next >= 0x200) {
        next = 0;
    }

    if ((s32)base->unk_4 == next) {
        return -1;
    }

    if (arg < fn_1_46EC8() || arg > fn_1_46ED8()) {
        arg = fn_1_46EC8();
    }

    entry = base->entries;
    entry += base->unk_0;
    base->unk_0 = next;
    entry->type = 0xb;
    entry->value = arg;

    return current;
}
/* fzgx:end fn_1_46A8C */
