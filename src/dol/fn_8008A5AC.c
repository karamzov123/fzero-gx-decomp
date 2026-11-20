#include "types.h"


/* --- dol/fn_8008A5AC.c --- */
/* --- dol/fn_8008A5AC.c --- */
// fn_8008A5AC: returns a constant.
int fn_8008A5AC(void) {
    return 0;
}

/* --- dol/fn_8008A5B4.c --- */
// fn_8008A5B4: returns a constant.
int fn_8008A5B4(void) {
    return 0;
}

/* --- dol/fn_8008A5BC.c --- */
/* --- dol/fn_8008A5BC.c --- */
extern void *memset(void *dest, int value, u32 size);
extern void fn_8008D398(void *arg0, u32 arg1);
extern void fn_8008D028(void);

struct Fn8008A5BCData {
    u32 field0;
    u8 field4;
    u8 padding5[3];
    u8 field8;
    u8 padding9[0x38];
};

int fn_8008A5BC(void) {
    struct Fn8008A5BCData data;
    u32 size = 0x40;

    memset(&data, 0, size);
    data.field4 = 0x80;
    data.field0 = size;
    data.field8 = 0;
    fn_8008D398(&data, size);
    fn_8008D028();
    return 0;
}

/* --- dol/fn_8008A614.c --- */
extern void fn_80005518(void);

typedef struct InitData {
    u32 size;
    u8 type;
    u8 padding0[3];
    u8 flag;
    u8 padding1[0x3b];
} InitData;

int fn_8008A614(void) {

{
    InitData data;
    memset(&data, 0, 0x40);
    data.type = 0x80;
    data.size = 0x40;
    data.flag = 0;
    fn_8008D398(&data, 0x40);
}
    fn_80005518();
    return 0;
}

/* --- dol/fn_8008A66C.c --- */
extern u32 lbl_801A50B0[];
extern void fn_80088764(void *value, s32 arg);
extern void TRKPostEvent(void *value);

struct fn_8008A66C_Data {
    u32 size;
    u8 type;
    u8 padding0[3];
    u8 flag;
    u8 padding1[0x3b];
};

s32 fn_8008A66C(void) {
    struct fn_8008A66C_Data data;
    u32 value[3];

    lbl_801A50B0[0] = 0;
    memset(&data, 0, 0x40);
    data.type = 0x80;
    data.size = 0x40;
    data.flag = 0;
    fn_8008D398(&data, 0x40);
    fn_80088764(value, 1);
    TRKPostEvent(value);
    return 0;
}

/* --- dol/fn_8008A6E4.c --- */

struct fn_8008A6E4_local {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[3];
    u8 unk_8;
    u8 pad_9[0x37];
};

s32 fn_8008A6E4(void) {
    struct fn_8008A6E4_local local;
    u32 size = 0x40;

    lbl_801A50B0[0] = 1;
    memset(&local, 0, size);
    local.unk_4 = 0x80;
    local.unk_0 = size;
    local.unk_8 = 0;
    fn_8008D398(&local, size);
    return 0;
}

/* --- dol/fn_8008A748.c --- */
void fn_8008A748(u32 arg0) {
    lbl_801A50B0[0] = arg0;
}
