#include "types.h"

typedef struct MPVMCContext MPVMCContext;

typedef void (*MPVMCFunction)(MPVMCContext *context);

struct MPVMCContext {
    union {
        unsigned char padding_extent[68];
        struct {
            MPVMCFunction functions08[4];
        } view_functions08;
        struct {
            unsigned char padding_destination[24];
            u8 *destination;
        } view_destination;
    } fields;
};
void fn_12_2013C(MPVMCContext *context);

/* fzgx:begin fn_12_8AEC */
/* --- rel/movie_module/fn_12_8AEC.c --- */
typedef struct MovieModule_u1 {
    u8 _pad120[0x120];
    s32 field_120;
    u8 _pad124[0x30];
    s32 field_154;
    u8 _pad158[0x4c];
    s32 field_1a4;
} MovieModule_u1;

void fn_12_8AEC(MovieModule_u1 *module) {
    s32 value = 4;

    if (module->field_1a4 == 0) {
        value = -1;
    }
    module->field_154 = value;
    module->field_120 = value;
}
/* fzgx:end fn_12_8AEC */

/* fzgx:begin fn_12_8B0C */
/* --- rel/movie_module/fn_12_8B0C.c --- */
struct fn_12_8B0C_Arg0 {
    u8 pad_0[0x120];
    u32 unk_120;
    s32 values[12];
    u8 pad_154[0x50];
    s32 unk_1a4;
    u8 pad_1a8[0xa8];
    s16 unk_250;
    s16 unk_252;
};

void fn_12_8B0C(struct fn_12_8B0C_Arg0 *arg0) {
    s32 value = 4;
    s32 *values = &arg0->values[0];
    s16 sample;

    if (arg0->unk_1a4 == 0) {
        value = -1;
    }
    arg0->unk_120 = value;
    sample = arg0->unk_250;
    values[1] = sample;
    values[3] = sample;
    sample = arg0->unk_252;
    values[5] = sample;
    values[7] = sample;
    values[9] = sample;
    values[11] = sample;
}
/* fzgx:end fn_12_8B0C */

/* fzgx:begin fn_12_8B4C */
typedef struct MPVContext MPVContext;

typedef struct MPVOutputBlock {
    union {
        unsigned char padding_extent[8];
        struct {
            u8 *destination;
        } view_destination;
        struct {
            unsigned char padding_stride[4];
            s32 stride;
        } view_stride;
    } fields;
} MPVOutputBlock;

typedef struct MPVOutputBlocks {
    union {
        unsigned char padding_extent[52];
        struct {
            s32 count;
        } view_count;
        struct {
            unsigned char padding_blocks[4];
            MPVOutputBlock blocks[6];
        } view_blocks;
    } fields;
} MPVOutputBlocks;

typedef struct MPVConditionState {
    union {
        unsigned char padding_extent[192];
        struct {
            int conditions[16];
        } view_conditions;
    } fields;
} MPVConditionState;

struct MPVContext {
    union {
        unsigned char padding_extent[4992];
        struct {
            unsigned char padding_mc[204];
            MPVMCContext mc;
        } view_mc;
        struct {
            unsigned char padding_secondary_output_blocks[340];
            MPVOutputBlocks secondary_output_blocks;
        } view_secondary_output_blocks;
        struct {
            unsigned char padding_condition_state[400];
            MPVConditionState condition_state;
        } view_condition_state;
        struct {
            unsigned char padding_field_D00[3264];
            u8 field_D00[0x600];
        } view_field_D00;
    } fields;
};

void fn_12_E0C8(MPVMCFunction functions[4]);


void fn_12_8B4C(MPVContext *object) {
    u8 *destination;
    MPVOutputBlocks *output_blocks;
    MPVOutputBlock *blocks;
    s32 count;
    s32 i;
    fn_12_E0C8(object->fields.view_mc.mc.fields.view_functions08.functions08);
    fn_12_2013C(&object->fields.view_mc.mc);
    output_blocks = &object->fields.view_secondary_output_blocks.secondary_output_blocks;
    blocks = output_blocks->fields.view_blocks.blocks;
    destination = object->fields.view_field_D00.field_D00;
    if (object->fields.view_condition_state.condition_state.fields.view_conditions.conditions[5] ==
        0) {
        count = -1;
    } else {
        count = 4;
    }
    output_blocks->fields.view_count.count = count;
    for (i = 0; i < 6; i++) {
        blocks[i].fields.view_destination.destination = destination;
    }
    for (i = 0; i < 6; i++) {
        blocks[i].fields.view_stride.stride = 8;
    }
}
/* fzgx:end fn_12_8B4C */
