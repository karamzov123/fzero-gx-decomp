#include "types.h"


/* --- dol/fn_8007EC80.c --- */
typedef s32 (*fn_8007EC80_Fn0)(u32, u32, u32 *, u32);

struct fn_8007EC80_Arg0 {
    u32 unk_0;
    u8 pad_4[0x14];
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x04];
    fn_8007EC80_Fn0 unk_3C;
    u8 pad_40[0x08];
    u32 unk_48;
};

s32 fn_8007EC80(struct fn_8007EC80_Arg0 *arg0, u32 *arg1, s32 arg2) {
    s32 result;

    arg0->unk_24 = arg0->unk_1C;
    arg0->unk_28 = arg0->unk_20;
    arg0->unk_28 -= arg0->unk_18 & arg0->unk_2C;
    arg0->unk_34 = arg0->unk_18;
    if (arg2 == 1) {
        arg0->unk_28 = arg0->unk_20;
    }
    result = arg0->unk_3C(arg0->unk_0, arg0->unk_1C, &arg0->unk_28, arg0->unk_48);
    if (result == 2) {
        arg0->unk_28 = 0;
    }
    if (arg1 != 0) {
        *arg1 = arg0->unk_28;
    }
    if (result != 0) {
        return result;
    }
    arg0->unk_18 += arg0->unk_28;
    return 0;
}

/* --- dol/__prep_buffer.c --- */
/* --- dol/__prep_buffer.c --- */
typedef struct PrepBuffer {
    u8 pad[0x18];
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    u32 field_24;
    u32 field_28;
    u32 field_2c;
    u32 field_30;
    u32 field_34;
} PrepBuffer;

void __prep_buffer(PrepBuffer* buffer) {
    buffer->field_24 = buffer->field_1c;
    buffer->field_28 = buffer->field_20;
    buffer->field_28 -= buffer->field_18 & buffer->field_2c;
    buffer->field_34 = buffer->field_18;
}

/* --- dol/__end_critical_region.c --- */
// __end_critical_region: empty in retail (single blr).
void __end_critical_region(void) {
}

/* --- dol/__begin_critical_region.c --- */
// __begin_critical_region: empty in retail (single blr).
void __begin_critical_region(void) {
}

/* --- dol/__kill_critical_regions.c --- */
// __kill_critical_regions: empty in retail (single blr).
void __kill_critical_regions(void) {
}

/* --- dol/fn_8007ED90.c --- */
extern u8 lbl_8015B200[256];

s32 fn_8007ED90(s32 value) {
    if (value == -1) {
        return -1;
    }
    return lbl_8015B200[(u8)value];
}
