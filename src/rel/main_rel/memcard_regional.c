/* Previously matched Japan/PAL fragments retained until memcard.c matches those releases as one TU. */
#include "types.h"
#include "game/pad.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/memcard.h"
extern void* lbl_801A6410;
extern int fn_1_45D0(void *arg0, int arg1, Obj_1_data_3C7B8 *arg2, int arg3);
extern void fn_1_AB45C(void);
extern void CARDMountAsync(u8, u32, void (*)(void), s32);
extern int CARDGetSerialNo(u8 value, void *data);
extern void CARDCheckAsync(u8 byte_val, int value);
extern void CARDFormatAsync(u8 byte, int value);
extern const f32 lbl_1_rodata_4CA8;
extern const f64 lbl_1_rodata_4CB0;
extern const f32 lbl_1_rodata_4CAC;
extern void strcpy(void *dst, void *src);
extern void strcat(void *dst, void *src);
extern void CARDDeleteAsync(u8 byte, void *data, int arg);
extern s32 CARDFreeBlocks(u8 byte_val, void *arg1, void *arg2);
extern s32 CARDOpen(u8 byte_val, void *arg1, void *arg2);
extern void CARDFastDeleteAsync(u8 byte_val, void *arg, s32 zero);
extern void CARDCreateAsync(u8 byte_val, void *arg1, void *arg2, void *arg3, u32 arg4);
extern void CARDSetStatusAsync(u8 id, void *arg, void *data, int zero);
extern void CARDRenameAsync(u8 id, void *data1, void *data2, int zero);
extern void CARDReadAsync(void *arg0, void *arg1, void *arg2, int arg3, int arg4);
extern const f64 lbl_1_rodata_4CC8;
extern void fn_80030754(u8 value, void *data, int size, int mode);
extern u8 lbl_1_bss_71810[161];
extern u8 lbl_1_bss_718B8;
extern u8 lbl_1_bss_718B8__fzgx_offset_1[7];
extern int fn_8002A744(void);
extern void fn_8002A74C(u16 value);
extern int fn_8002DFE0(int arg0, u32 arg1, int arg2);
extern int CARDCheck(int arg0);
extern void fn_1_B9C38(s32 index);
extern void fn_1_1596DC(u32);
extern void fn_1_484CC(u32);
extern void fn_80008BEC(void *dst, s32 value, s32 size);
extern void fn_1_AA6D8(s32 arg0, u32 arg1, void *arg2);
extern void fn_1_F755C(u8 value);
extern void fn_1_A6840(u8 value);
extern void OSPanic(void *arg0, u32 arg1, ...);
extern void fn_1_F79C8(void);
extern void *lbl_801A6410;
extern void strncpy(void *arg0, void *arg1, int arg2);
extern u32 lbl_1_bss_77310[28];
extern u32 lbl_1_bss_7730C;
extern u8 lbl_1_bss_772C8[66];
extern u32 fn_1_4630(void *heap, u32 size, void *file, s32 line);
extern s32 fn_8002FC14(s32 chan, void *fileName);
extern s32 fn_80030338(s32 chan, void *oldName, void *newName);
extern const f64 lbl_1_rodata_4CB8;
extern void fn_1_C36EC(void);

/* fzgx:begin fn_1_ABB4C */
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

/* lbl_1_bss_9F8: .bss size 0x50, referenced by 67 functions, shape {'object': 301} */
typedef struct {
u16 unk_0; /* 22 loads, 0 stores */
u16 unk_2; /* 35 loads, 0 stores */
u8 pad_4[0x4];
u16 unk_8; /* 108 loads, 0 stores */
u16 unk_A; /* 22 loads, 0 stores */
u8 pad_C[0x4];
u16 unk_10; /* 56 loads, 0 stores */
u16 unk_12; /* 53 loads, 0 stores */
u8 pad_14[0x3C];
} Obj_1_bss_9F8_fn_1_ABB4C;

extern void fn_1_A2DC4(u32);
typedef struct {
u8 pad_0[0x24];
void *unk_24;
u8 pad_28[0x2];
u8 unk_2A;
} MemcardArg;
typedef struct {
u8 pad_0[0x1];
u8 unk_1;
u8 pad_2[0x2];
s32 unk_4;
} MemcardState;
/* fzgx-allow: A1 absolute retail data address */
/* fzgx-allow: A1 absolute retail data address */
void fn_1_ABB4C(MemcardArg *arg) {
MemcardState *state;
s32 value;
if ((arg->unk_2A & 1) == 0) {
state = (MemcardState *)arg->unk_24;
if (((((Obj_1_bss_9F8_fn_1_ABB4C *)&lbl_1_bss_9F8)->unk_10 & 1) != 0 ||
(((Obj_1_bss_9F8_fn_1_ABB4C *)&lbl_1_bss_9F8)->unk_12 & 1) != 0) &&
state->unk_1 == 1) {
fn_1_A2DC4(0xA9011300 );
state->unk_1 = 0;
/* Volatile prevents the compiler from reusing the first status read. */
} else if ((((*((u16 *)&((Obj_1_bss_9F8_fn_1_ABB4C *)&lbl_1_bss_9F8)->unk_10) >> 1) & 1) != 0 ||
((((Obj_1_bss_9F8_fn_1_ABB4C *)&lbl_1_bss_9F8)->unk_12 >> 1) & 1) != 0) &&
state->unk_1 == 0) {
fn_1_A2DC4(0xA9011300 );
state->unk_1 = 1;
}
if (((((Obj_1_bss_9F8_fn_1_ABB4C *)&lbl_1_bss_9F8)->unk_8 >> 8) & 1) != 0) {
fn_1_A2DC4(0xA9011100 );
value = 1;
} else {
value = 0;
}
state = (MemcardState *)arg->unk_24;
state->unk_4 = value;
state = (MemcardState *)arg->unk_24;
if (state->unk_4 == 2) {
state->unk_1 = 1;
}
}
}
/* fzgx:end fn_1_ABB4C */

/* fzgx:begin fn_1_ABC5C */
typedef struct {
    u8 byte_0;
    u8 pad_0x1[0x13];
    void *field_0x14;
} fn_1_ABC5C_ArgStruct;

typedef struct {
    u8 pad[0x2];
    u16 field_0x2;
} fn_1_ABC5C_ResultStruct;

typedef struct {
    u8 pad[0x24];
    fn_1_ABC5C_ResultStruct *ptr_0x24;
} StateStruct;

void fn_1_ABC5C(fn_1_ABC5C_ArgStruct *arg) {
    StateStruct *state;

    state = (StateStruct *)arg;
    state->ptr_0x24->field_0x2 = 0x12c;
    CARDFastDeleteAsync(arg->byte_0, arg->field_0x14, 0);
}
/* fzgx:end fn_1_ABC5C */

/* fzgx:begin fn_1_ABC98 */
typedef struct {
    u8 pad[0x2];
    u16 field_0x2;
    s32 field_0x4;
} fn_1_ABC98_ResultStruct;

typedef struct {
    u8 byte_0;
    u8 pad_0x1[0x23];
    fn_1_ABC98_ResultStruct *ptr_0x24;
} fn_1_ABC98_ArgStruct;

void fn_1_ABC98(fn_1_ABC98_ArgStruct *arg) {
    arg->ptr_0x24->field_0x4 = CARDGetResultCode(arg->byte_0);
    if (arg->ptr_0x24->field_0x4 != -1) {
        arg->ptr_0x24->field_0x2 = 0;
    }
}
/* fzgx:end fn_1_ABC98 */

/* fzgx:begin fn_1_ABCE8 */
typedef struct {
    u8 pad[0x2];
    u16 field_0x2;
    u8 pad_0x4[0x8];
    void *ptr_0xc;
} fn_1_ABCE8_ResultStruct;

typedef struct {
    u8 byte_0;
    u8 pad_0x1[0xf];
    u8 data_0x10[0x14];
    fn_1_ABCE8_ResultStruct *ptr_0x24;
} fn_1_ABCE8_ArgStruct;

void fn_1_ABCE8(fn_1_ABCE8_ArgStruct *arg) {
    u8 local[0x40];

    strcpy(local, (u8 *)arg->ptr_0x24 + 0x98);
    strcat(local, lbl_1_data_3C89C);
    arg->ptr_0x24->field_0x2 = 0x12c;
    CARDCreateAsync(arg->byte_0, local, arg->ptr_0x24->ptr_0xc,
        arg->data_0x10, 0);
}
/* fzgx:end fn_1_ABCE8 */

/* fzgx:begin fn_1_ABD58 */
typedef struct {
    u8 pad[0x2];
    u16 field_0x2;
    s32 field_0x4;
} fn_1_ABD58_ResultStruct;

typedef struct {
    u8 byte_0;
    u8 pad_0x1[0x23];
    fn_1_ABD58_ResultStruct *ptr_0x24;
} fn_1_ABD58_ArgStruct;

void fn_1_ABD58(fn_1_ABD58_ArgStruct *arg) {
    arg->ptr_0x24->field_0x4 = CARDGetResultCode(arg->byte_0);
    if (arg->ptr_0x24->field_0x4 != -1) {
        arg->ptr_0x24->field_0x2 = 0;
    }
}
/* fzgx:end fn_1_ABD58 */

/* fzgx:begin fn_1_ABDA8 */
typedef struct {
    u8 pad[0x2];
    u16 field_0x2;
} fn_1_ABDA8_OffsetStruct;

typedef struct {
    u8 pad[0x24];
    fn_1_ABDA8_OffsetStruct *ptr_0x24;
} fn_1_ABDA8_ArgStruct;

void fn_1_ABDA8(fn_1_ABDA8_ArgStruct *arg) {
    arg->ptr_0x24->field_0x2 = 0x12c;
}
/* fzgx:end fn_1_ABDA8 */

/* fzgx:begin fn_1_ABDB8 */
#include "rel/main_rel/globals.h"

typedef struct {
    u8 pad_0x0[0x2];
    u16 unk_0x2;
    s32 unk_0x4;
    u8 pad_0x8[0x18];
    u8 unk_0x20[1];
} fn_1_ABDB8_ResultStruct;

typedef struct {
    u8 byte_0x0;
    u8 pad_0x1[0x13];
    void *ptr_0x14;
    u8 pad_0x18[0xc];
    fn_1_ABDB8_ResultStruct *ptr_0x24;
} fn_1_ABDB8_ArgStruct;

// Loads the payload into its result buffer and clears the stale offset on success.
void fn_1_ABDB8(fn_1_ABDB8_ArgStruct *arg) {
    arg->ptr_0x24->unk_0x4 =
        CARDGetStatus(arg->byte_0x0, arg->ptr_0x14, arg->ptr_0x24->unk_0x20);
    if (arg->ptr_0x24->unk_0x4 != -1) {
        arg->ptr_0x24->unk_0x2 = 0;
    }
}
/* fzgx:end fn_1_ABDB8 */

/* fzgx:begin fn_1_ABE14 */
typedef struct Fn1ABE14Sub {
    u8 pad_00[0x2];
    u16 value;
    u8 pad_04[0x8];
    void *arg_0xC;
    u8 pad_10[0x84];
    void *arg_0x94;
} Fn1ABE14Sub;

typedef struct Fn1ABE14Arg {
    u8 id;
    u8 pad_01[0x23];
    Fn1ABE14Sub *sub;
    u8 pad_28[0x2];
    u8 flags;
    u8 pad_2B[0x4];
    s32 result;
    u8 pad_34[0x4];
    f32 value;
    u8 pad_3C[0x58];
} Fn1ABE14Arg;

extern s32 fn_8002C0A0(u8 id);
extern void CARDWriteAsync(void *data, void *arg_0x94, void *arg_0xC, int zero_1, int zero_2);

void fn_1_ABE14(Fn1ABE14Arg *arg) {
    arg->sub->value = 300;
    arg->result = fn_8002C0A0(arg->id);
    arg->value = lbl_1_rodata_4CA8;
    arg->flags |= 2;
    CARDWriteAsync((u8 *)arg + 0x10, arg->sub->arg_0x94, arg->sub->arg_0xC, 0, 0);
}
/* fzgx:end fn_1_ABE14 */

/* fzgx:begin fn_1_ABE88 */
#include "types.h"

struct fn_1_ABE88_Arg0 {
    u8 unk_0;
};




extern u32 CARDGetResultCode(u32);
extern u32 fn_8002C0A0(u32);


void fn_1_ABE88(void *arg0) {
    (*(u32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 4)) = CARDGetResultCode(((*(u8 *)(arg0))));
    (*(f32 *)((u8 *)(arg0) + 56)) = (f32) (s32) (fn_8002C0A0(((*(u8 *)(arg0)))) - (*(s32 *)((u8 *)(arg0) + 48))) / (u32) ((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 12)) + 0x2000);
    if ((s32) (*(u32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 4)) != -1) {
        (*((u8 *)(arg0) + 42)) = ((*((u8 *)(arg0) + 42)) & 0xFFFFFFFD);
        (*(s16 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 2)) = 0;
    }
}
/* fzgx:end fn_1_ABE88 */

/* fzgx:begin fn_1_ABF44 */
typedef struct {
    u8 pad_00[0x2];
    u16 field_0x2;
    s32 field_0x4;
    u8 pad_08[0x84];
    void *field_0x8c;
    s32 field_0x90;
    s32 field_0x94;
    u8 field_0x98[0x10];
} Fn1ABF44State;

typedef struct {
    u8 id;
    u8 pad_01[0xF];
    u8 data_0x10[0x14];
    Fn1ABF44State *state;
    u8 pad_28[0x2];
    u8 flags_0x2a;
    u8 pad_2b[0x5];
    s32 value_0x30;
    u8 pad_34[0x4];
    f32 value_0x38;
} Fn1ABF44Object;

void fn_1_ABF44(Fn1ABF44Object *arg) {
    u8 work[0x40];
    s32 value;
    s32 size;
    s32 aligned;

    arg->state->field_0x2 = 300;
    strcpy(work, (u8 *)arg->state + 0x98);
    strcat(work, lbl_1_data_3C7C4);
    value = CARDOpen(arg->id, work, arg->data_0x10);
    arg->state->field_0x4 = value;
    arg->value_0x30 = fn_8002C0A0(arg->id);
    arg->value_0x38 = lbl_1_rodata_4CA8;
    arg->flags_0x2a |= 2;
    size = arg->state->field_0x94 +
        *(s32 *)((u8 *)arg->state->field_0x8c + 0x44);
    aligned = (*(s32 *)((u8 *)arg->state->field_0x8c + 0x48) + 0x1fff) &
        ~0x1fff;
    CARDWriteAsync(arg->data_0x10, size, aligned,
                *(s32 *)((u8 *)arg->state->field_0x8c + 0x44), 0);
}
/* fzgx:end fn_1_ABF44 */

/* fzgx:begin fn_1_AC000 */
typedef struct Fn1AC000Table {
    u8 pad_00[0x48];
    u32 value_0x48;
} Fn1AC000Table;

typedef struct Fn1AC000State {
    u8 pad_00[0x2];
    u16 value_0x2;
    s32 value_0x4;
    u8 pad_08[0x84];
    Fn1AC000Table *table;
} Fn1AC000State;

typedef struct Fn1AC000Target {
    u8 id;
    u8 pad_01[0x23];
    Fn1AC000State *state;
    u8 pad_28[0x2];
    u8 flags;
    u8 pad_2b[0x5];
    s32 start;
    u8 pad_34[0x4];
    f32 ratio;
} Fn1AC000Target;




extern u32 CARDGetResultCode(u32);
extern u32 fn_8002C0A0(u32);

void fn_1_AC000(Fn1AC000Target *target) {
    f32 numerator;
    f32 denominator;
    f32 ratio;

    target->state->value_0x4 = CARDGetResultCode(target->id);

    ratio = ((target->state->table->value_0x48 + 0x1fff) & ~0x1fff);
    denominator = (((target->state->table->value_0x48 + 0x1fff) & ~0x1fff) + 0x4000);
    ratio = ratio / denominator;

    numerator = (s32)(fn_8002C0A0(target->id) - target->start);
    denominator = (((target->state->table->value_0x48 + 0x1fff) & ~0x1fff) + 0x2000);
    target->ratio = ratio * numerator / denominator;

    if (target->state->value_0x4 != -1 && target->state->value_0x4 != 0) {
        target->flags = target->flags & 0xfffffffd;
        target->state->value_0x2 = 0;
    }
}
/* fzgx:end fn_1_AC000 */

/* fzgx:begin fn_1_AC12C */
extern int fn_1_45D0(void *arg0, int arg1, Obj_1_data_3C7B8 *arg2, int arg3);
extern void CARDMountAsync(u8, u32, void (*)(void), s32);
extern int CARDGetSerialNo(u8 value, void *data);
extern void CARDCheckAsync(u8 byte_val, int value);
extern void CARDFormatAsync(u8 byte, int value);

extern void strcpy(void *dst, void *src);
extern void strcat(void *dst, void *src);
extern s32 CARDOpen(u8 byte_val, void *arg1, void *arg2);
extern void CARDFastDeleteAsync(u8 byte_val, void *arg, s32 zero);
extern void CARDCreateAsync(u8 byte_val, void *arg1, void *arg2, void *arg3, u32 arg4);
extern void fn_8002A74C(u16 value);
extern int CARDCheck(int arg0);
extern void fn_80008BEC(void *dst, s32 value, s32 size);
extern void fn_1_AA6D8(s32 arg0, u32 arg1, void *arg2);
extern void fn_1_A6840(u8 value);
extern void OSPanic(void *arg0, u32 arg1, ...);
extern void fn_1_F79C8(void);
extern void strncpy(void *arg0, void *arg1, int arg2);
extern u32 lbl_1_bss_7730C;

typedef struct MemcardRequestState {
    u8 pad_00[0x2];
    u16 value;
    u8 pad_04[0x90];
    void *data;
} MemcardRequestState;

typedef struct fn_1_AC12C_MemcardRequest {
    u8 id;
    u8 pad_01[0xF];
    u8 buffer[0x14];
    MemcardRequestState *state;
    u8 pad_28[0x8];
    void *result;
} fn_1_AC12C_MemcardRequest;

extern void *fn_8002C0A0(u8 id);
extern void CARDWriteAsync(void *dst, void *src, int size, int zero, int flags);

// Initializes the request state, records the backing resource, and starts its transfer.
void fn_1_AC12C(fn_1_AC12C_MemcardRequest *request) {
    request->state->value = 300;
    request->result = fn_8002C0A0(request->id);
    CARDWriteAsync(request->buffer, request->state->data, 0x4000, 0, 0);
}
/* fzgx:end fn_1_AC12C */

/* fzgx:begin fn_1_AD0A0 noprologue */
#include "types.h"
#include "dolphin/card.h"
#include "dolphin/card/CARDPriv.h"

struct fn_1_AD0A0_Arg0 {
    u8 pad_0[0x2C];
    u8 unk_2C;
};
extern f32 lbl_1_rodata_4CD0;
extern f64 lbl_1_rodata_4CB8;
extern s32 CARDGetStatus(s32, s32, CARDStat *);


void fn_1_AD0A0(void *arg0) {
    u8 temp_r4;

    temp_r4 = *((u8 *)(arg0) + 44);
    if (temp_r4 < 0x7FU) {
        (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 4)) = CARDGetStatus((*(u8 *)(arg0)), temp_r4, (CARDStat *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 0x20));
    }
    (*(f32 *)((u8 *)(arg0) + 56)) = ((*((u8 *)(arg0) + 44)) / lbl_1_rodata_4CD0);
    if ((*((u8 *)(arg0) + 44)) == 0x7E) {
        (*((u8 *)(arg0) + 42)) = ((*((u8 *)(arg0) + 42)) & 0xFFFFFFFD);
        (*(s16 *)((u8 *)((*(void **)((u8 *)(arg0) + 36))) + 2)) = 0;
    }
}
/* fzgx:end fn_1_AD0A0 */

/* fzgx:begin fn_1_AEC34 */
typedef struct Fn1AEC34A {
    u8 pad0[8];
    void *payload;
    void *result;
} Fn1AEC34A;

typedef struct Fn1AEC34P {
    u8 pad0[8];
    u32 flags;
    u8 padC[0x88];
    void *buffer;
    u8 pad98[0x4c];
    void *length;
} Fn1AEC34P;

typedef struct Fn1AEC34B {
    u8 pad0[3];
    u8 state;
    u8 pad4[0x20];
    Fn1AEC34P *card;
} Fn1AEC34B;

// Finalize the card operation and publish its completion state.
void fn_1_AEC34(Fn1AEC34A *request, Fn1AEC34B *operation) {
    if ((operation->card->flags & 0x20) == 0) {
        if (request->payload != 0) {
            strncpy((u8 *)operation->card->buffer + 0x24,
                        request->payload, 0x20);
        }
        fn_80008BA8((u8 *)operation->card->buffer + 0x2060,
                    request->result, operation->card->length);
    }
    operation->state = 3;
    lbl_1_bss_77310[0] = 1;
    lbl_1_bss_7730C = 0;
}
/* fzgx:end fn_1_AEC34 */

/* fzgx:begin fn_1_B5258 noprologue */
#include "types.h"

extern void strcpy(char *destination, const char *source);
extern char *strstr(char *buffer, const char *source);
extern unsigned int strlen(const char *string);
extern char *strncpy(char *destination, const char *source, unsigned int count);
extern char *strcat(char *destination, const char *source);

void fn_1_B5258(char *destination, void *unused, const char *source, const char *suffix) {
    char buffer[0x400];
    char *prefix;
    unsigned int source_length;
    unsigned int prefix_length;

    strcpy(buffer, unused);
    prefix = strstr(buffer, source);
    if (prefix == 0) {
        strcpy(destination, buffer);
    } else {
        source_length = strlen(source);
        if (prefix != buffer) {
            prefix_length = (unsigned int)(prefix - buffer);
            strncpy(destination, buffer, prefix_length);
            destination[prefix_length] = 0;
        } else {
            destination[0] = 0;
        }
        strcat(destination, suffix);
        strcat(destination, prefix + source_length);
    }
}
/* fzgx:end fn_1_B5258 */

/* fzgx:begin fn_1_B7C6C noprologue */
#include "types.h"

extern s8 lbl_1_bss_716C8[320];
extern u8 lbl_1_bss_718B1;

s32 fn_1_B7C6C(u32 arg0) {
    u32 index = arg0 & 0xff;
    switch (index) {
    case 0:
    case 1:
        return lbl_1_bss_716C8[index * 0xa0 + 1];
    default:
        break;
    }

    if (lbl_1_bss_718B1 == 5) {
        return 0;
    }
    return lbl_1_bss_716C8[lbl_1_bss_718B1 * 0xa0 + 1];
}
/* fzgx:end fn_1_B7C6C */

/* fzgx:begin fn_1_B8170 noprologue */
#include "types.h"
#include "rel/main_rel/memcard.h"

extern f32 lbl_1_rodata_4AE0[114];
extern u8 lbl_1_data_3C7C4[216];
extern u8 lbl_1_data_3C89C[68];

extern void strcpy(void *dst, const void *src);
extern void strcat(void *dst, const void *src);
extern s32 CARDOpen(s32 card, void *work, void *entry);
extern s32 CARDClose(void *entry);

static inline s32 wait_card(s32 card, void *work, void *entry) {
    s32 result;

    do {
        result = CARDOpen(card, work, entry);
    } while (result == -1);
    return result;
}

static inline s32 wait_write(void *entry) {
    s32 result;

    do {
        result = CARDClose(entry);
    } while (result == -1);
    return result;
}

u32 fn_1_B8170(s32 card) {
    u8 work1[0x40];
    u8 work2[0x40];
    const f32 *table;
    u32 flags;
    u8 *entry;

    entry = (u8 *)&lbl_1_bss_716C8 + card * 0xa0;
    table = lbl_1_rodata_4AE0 + 19;
    flags = 0;

    strcpy(work1, table);
    strcat(work1, lbl_1_data_3C7C4);
    if (wait_card(card, work1, entry + 0x10) == 0) {
        wait_write(entry + 0x10);
        flags |= 2;
    } else {
        strcpy(work2, table);
        strcat(work2, lbl_1_data_3C89C);
        if (wait_card(card, work2, entry + 0x10) == 0) {
            wait_write(entry + 0x10);
            flags |= 2;
        } else {
            flags &= ~2;
        }
    }

    table = lbl_1_rodata_4AE0 + 57;
    strcpy(work1, table);
    strcat(work1, lbl_1_data_3C7C4);
    if (wait_card(card, work1, entry + 0x10) == 0) {
        wait_write(entry + 0x10);
        flags |= 8;
    } else {
        strcpy(work2, table);
        strcat(work2, lbl_1_data_3C89C);
        if (wait_card(card, work2, entry + 0x10) == 0) {
            wait_write(entry + 0x10);
            flags |= 8;
        } else {
            flags &= ~8;
        }
    }
    return flags;
}
/* fzgx:end fn_1_B8170 */

/* fzgx:begin fn_1_BB974 noprologue */
#include "types.h"

/* one save file in a card's directory listing */
typedef struct {
    u8 used;            /* 0x00 */
    u8 type;            /* 0x01 */
    u8 pad_2[0x22];
    u32 size;           /* 0x24 */
    u32 time;           /* 0x28: seconds */
    void *info;         /* 0x2C */
} McFile;

typedef struct {
    u8 unk_0, unk_1, unk_2, unk_3, unk_4, unk_5, unk_6, unk_7;
} McFileKey;

extern McFile lbl_1_bss_77380[2][128];
extern McFileKey lbl_1_bss_7A39C[2][127];

// Sorts both cards' directory listings: type 2 files first, then type 4, then the rest;
// the type 2, 4 and 5 groups are each ordered by time.
void fn_1_BB974(void) {
    s32 i;
    s32 j;
    s32 count;
    s32 start;
    s32 n;
    s32 card;
    McFile *files;
    McFileKey *keys;
    McFile file1;
    McFile file5;
    McFile file4;
    McFile file3;
    McFile file2;
    McFileKey key1;
    McFileKey key5;
    McFileKey key4;
    McFileKey key3;
    McFileKey key2;

    for (card = 0; card < 2; card++) {
        files = lbl_1_bss_77380[card];
        keys = lbl_1_bss_7A39C[card];

        count = 0;
        for (i = 0; i < 127; i++) {
            if (files[i].size != 0) {
                count++;
            }
        }

        /* type 2 files to the front */
        for (i = 0; i < count - 1; i++) {
            for (j = i + 1; j < count; j++) {
                if (files[i].type != 2 && files[j].type == 2) {
                    file1 = files[i];
                    files[i] = files[j];
                    files[j] = file1;
                    key1 = keys[i];
                    keys[i] = keys[j];
                    keys[j] = key1;
                }
            }
        }

        /* type 4 files right after them */
        start = 0;
        for (i = 0; i < 127; i++) {
            if (files[i].type == 2) {
                start++;
            }
        }
        for (i = start; i < count - 1; i++) {
            for (j = i + 1; j < count; j++) {
                if (files[i].type != 4 && files[j].type == 4) {
                    file2 = files[i];
                    files[i] = files[j];
                    files[j] = file2;
                    key2 = keys[i];
                    keys[i] = keys[j];
                    keys[j] = key2;
                }
            }
        }

        /* each group by time */
        start = 0;
        for (i = 0; i < 127; i++) {
            if (files[i].type == 2) {
                start++;
            }
        }
        for (i = 0; i < start - 1; i++) {
            for (j = i + 1; j < start; j++) {
                if (files[i].time > files[j].time) {
                    file3 = files[i];
                    files[i] = files[j];
                    files[j] = file3;
                    key3 = keys[i];
                    keys[i] = keys[j];
                    keys[j] = key3;
                }
            }
        }

        n = 0;
        for (i = 0; i < 127; i++) {
            if (files[i].type == 4) {
                n++;
            }
        }
        for (i = start; i < start + n - 1; i++) {
            for (j = i + 1; j < start + n; j++) {
                if (files[i].time > files[j].time) {
                    file4 = files[i];
                    files[i] = files[j];
                    files[j] = file4;
                    key4 = keys[i];
                    keys[i] = keys[j];
                    keys[j] = key4;
                }
            }
        }
        start += n;

        n = 0;
        for (i = 0; i < 127; i++) {
            if (files[i].type == 5) {
                n++;
            }
        }
        for (i = start; i < start + n - 1; i++) {
            for (j = i + 1; j < start + n; j++) {
                if (files[i].time > files[j].time) {
                    file5 = files[i];
                    files[i] = files[j];
                    files[j] = file5;
                    key5 = keys[i];
                    keys[i] = keys[j];
                    keys[j] = key5;
                }
            }
        }
    }
}
/* fzgx:end fn_1_BB974 */

/* fzgx:begin fn_1_BF520 */
#include "types.h"

struct fn_1_BF520_Arg4 {
    u32 unk_0;
};
struct fn_1_BF520_Copy88 { u32 a[22]; };
struct fn_1_BF520_lbl_1_rodata_4CB0 {
    f64 unk_0;
};
extern f32 lbl_1_rodata_4D18;
extern f32 lbl_1_rodata_5080;


extern u32 lbl_1_rodata_26F8;
extern void fn_1_50164(f32, f32, f32, f32, void *);

struct FzgxCopy_88 { u32 words[22]; };
void fn_1_BF520(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u32 *arg4) {
    struct FzgxCopy_88 loc_8;

    loc_8 = *(const struct FzgxCopy_88 *)((((((&lbl_1_rodata_26F8) + -4))) + 4));
    loc_8.words[0] = 0xC;
    loc_8.words[0xF] = *arg4;
    (*(f32 *)((u8 *)(&loc_8) + 12)) = lbl_1_rodata_5080;
    (*(f32 *)((u8 *)(&loc_8) + 4)) = arg0;
    (*(f32 *)((u8 *)(&loc_8) + 8)) = arg1;
    fn_1_50164(arg2, arg3, (*(f32 *)(&lbl_1_rodata_4D18)), (*(f32 *)(&lbl_1_rodata_4D18)), &loc_8);
}
/* fzgx:end fn_1_BF520 */

/* fzgx:begin fn_1_C132C */
typedef struct {
    u8 unk0[0x16];
    s16 unk16;
} Fn1C132CObject;

void fn_1_C132C(Fn1C132CObject *object, u8 *data) {
    u8 local[0x24];

    fn_80008BEC(local, 0, 0x24);
    local[0] = data[1];
    *(u8 **)(local + 0x14) = data + 2;
    fn_1_AA6D8(5, (u8)object->unk16, local);
}
/* fzgx:end fn_1_C132C */

/* fzgx:begin fn_1_C23CC */
extern void fn_80008BA8(void *arg0, void *arg1, u32 arg2);

void fn_1_C23CC(void *base0, u32 stride0, u32 arg2, void *base1,
                u32 stride1, u32 count_add, u32 offset, u32 count) {
    s32 i;
    u32 size;
    u32 end;
    u32 p;

    i = count >> 2;
    size = (stride1 & 0x7FFFFFF) << 3;
    end = count + count_add;
    p = count;
    while (p < end) {
        fn_80008BA8((u8 *)base0 + (((offset + i * stride0) & 0x7FFFFFF) << 3),
                    (u8 *)base1 + (((i * stride1) & 0x7FFFFFF) << 3),
                    size);
        i++;
        p += 4;
    }
}
/* fzgx:end fn_1_C23CC */

/* fzgx:begin fn_1_C2454 */
void fn_1_C2454(void) {
    u8 *state = &lbl_1_bss_716C0 + 0x10000;

    state[-0x6b04] = 0;
    state[-0x6afc] = 0;
    fn_1_C36EC();
    *(u32 *)(state - 0x6af8) = 3;
    state[-0x6af4] = 0;
}
/* fzgx:end fn_1_C2454 */
