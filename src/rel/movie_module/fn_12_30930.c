#include "types.h"
#include "sofdec/sftst.h"


/* --- rel/movie_module/fn_12_30930.c --- */
typedef struct MovieModuleData {
    u8 pad_0[0x0c];
    s32 field_0c;
    u8 pad_10[0x118];
    u64 field_128;
    u64 field_130;
} MovieModuleData;

typedef struct Fn12_30930_Arg {
    u64 field_0;
    u32 field_8;
    u32 field_c;
} Fn12_30930_Arg;

extern u64 __div2i(u32, u32, u32, u32);

void fn_12_30930(MovieModuleData *data, Fn12_30930_Arg *arg) {
    if (data->field_0c == 0) {
        data->field_128 += (u64)((s64)(data->field_130 * arg->field_0) /
            (s64)(((u64)arg->field_8 << 32) | arg->field_c));
    }
}

/* --- rel/movie_module/fn_12_309B0.c --- */
/* --- rel/movie_module/fn_12_309B0.c --- */
typedef struct MovieModuleData_u1 {
    u8 pad_0[0x0c];
    u32 field_0c;
} MovieModuleData_u1;

void fn_12_309B0(MovieModuleData_u1 *data, u32 value) {
    data->field_0c = value;
}

/* --- rel/movie_module/fn_12_309B8.c --- */
typedef struct Fn12_309B8_Object {
    int unk0;
    int field4;
} Fn12_309B8_Object;

void fn_12_309B8(Fn12_309B8_Object *object, int value) {
    object->field4 = value;
}

/* --- rel/movie_module/fn_12_309C0.c --- */
void fn_12_309C0(void* self, s32 value) {
    if (value > 0) {
        *(s32*)((u8*)self + 0x10) = value;
    }
}

/* --- rel/movie_module/fn_12_309D0.c --- */
struct fn_12_309D0_Arg0 {
    u8 pad_0[0x168];
    f64 unk_168;
    f64 unk_170;
};
struct fn_12_309D0_Arg1 {
    f64 unk_0;
    f64 unk_8;
};

f64 fn_12_309D0(struct fn_12_309D0_Arg0 *arg0, struct fn_12_309D0_Arg1 *arg1) {
    f64 v0;
    f64 v1;
    v0 = arg1->unk_0;
    v1 = arg1->unk_8;
    arg0->unk_168 = v0;
    arg0->unk_170 = v1;
    return v0;
}

/* --- rel/movie_module/fn_12_309E4.c --- */
struct fn_12_309E4_Arg0 {
    u8 pad_0[0x158];
    f64 unk_158;
    f64 unk_160;
};
struct fn_12_309E4_Arg1 {
    f64 unk_0;
    f64 unk_8;
};

f64 fn_12_309E4(struct fn_12_309E4_Arg0 *arg0, struct fn_12_309E4_Arg1 *arg1) {
    f64 v0;
    f64 v1;
    v0 = arg1->unk_0;
    v1 = arg1->unk_8;
    arg0->unk_158 = v0;
    arg0->unk_160 = v1;
    return v0;
}

/* --- rel/movie_module/fn_12_309F8.c --- */
struct fn_12_309F8_Arg0 {
    u8 pad_0[0x148];
    f64 unk_148;
    f64 unk_150;
};
struct fn_12_309F8_Arg1 {
    f64 unk_0;
    f64 unk_8;
};

f64 fn_12_309F8(struct fn_12_309F8_Arg0 *arg0, struct fn_12_309F8_Arg1 *arg1) {
    f64 v0;
    f64 v1;
    v0 = arg1->unk_0;
    v1 = arg1->unk_8;
    arg0->unk_148 = v0;
    arg0->unk_150 = v1;
    return v0;
}

/* --- rel/movie_module/fn_12_30A0C.c --- */
struct fn_12_30A0C_Arg0 {
    u8 pad_0[0x138];
    f64 unk_138;
    f64 unk_140;
};
struct fn_12_30A0C_Arg1 {
    f64 unk_0;
    f64 unk_8;
};

f64 fn_12_30A0C(struct fn_12_30A0C_Arg0 *arg0, struct fn_12_30A0C_Arg1 *arg1) {
    f64 v0;
    f64 v1;
    v0 = arg1->unk_0;
    v1 = arg1->unk_8;
    arg0->unk_138 = v0;
    arg0->unk_140 = v1;
    return v0;
}

/* --- rel/movie_module/fn_12_30A20.c --- */
void fn_12_30A20(u32 *dst, u32 value) {
    *dst = value;
}

/* --- rel/movie_module/SFTST_Create.c --- */
typedef struct SFTST_Header {
    char text[274];
} SFTST_Header;

void *memset(void *destination, int value, unsigned long size);

char *fn_80083DB0(char *destination, const char *source);

unsigned long strlen(const char *string);

extern const SFTST_Header lbl_12_rodata_F00;

struct SFTST_DebugOutput {
    int size;
    char *buffer;
    char *wrap;
    char *cursor;
    SFTST_Work *last;
};
extern struct SFTST_DebugOutput lbl_12_bss_1B740;

void SFTST_Create(SFTST_Work *work) {
    struct SFTST_DebugOutput *const debug = &lbl_12_bss_1B740;

    memset(work, 0, sizeof(*work));
    work->test_enabled = 1;
    work->paused = 0;
    work->reset_history = 0;
    work->adjust_enabled = 1;
    work->average_count = 10;
    memset(work->errors, 0, sizeof(work->errors));
    work->average_index = 0;
    work->history_resets++;
    work->input_time.value = 0;
    work->input_time.scale = 1;
    work->sample_time.value = 0;
    work->sample_time.scale = 1;
    work->output_time.value = 0;
    work->output_time.scale = 1;
    work->tolerance.value = 0x412b;
    work->tolerance.scale = 1000000;
    work->excess_error.value = 200000;
    work->excess_error.scale = 1000000;
    work->adjustment_start.value = -0x412b;
    work->adjustment_start.scale = 1000000;
    work->adjustment_offset.value = -0x412b;
    work->adjustment_offset.scale = 1000000;
    work->previous_sample = -1;
    work->adjusted_time = 0;
    work->maximum_time = 0;
    work->adjustment_count = 0;
    work->positive_adjustments = 0;
    work->negative_adjustments = 0;
    work->history_resets = 0;
    work->excess_resets = 0;
    work->average = 0;
    work->adjusted_average = 0;
    work->front_max = 0;
    work->front_min = 0;
    work->rear_max = 0;
    work->rear_min = 0;
    {
        SFTST_Header header = lbl_12_rodata_F00;
        if ((debug->buffer) != 0) {
            memset((debug->buffer), 0, (debug->size));
            (debug->cursor) = (debug->buffer);
            fn_80083DB0((debug->buffer), header.text);
            (debug->cursor) += strlen(header.text);
            (debug->wrap) = (debug->cursor);
        }
    }
}
