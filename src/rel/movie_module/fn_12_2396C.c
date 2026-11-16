#include "types.h"
typedef struct Sig_fn_12_6B28_MpsHandle Sig_fn_12_6B28_MpsHandle;
typedef struct Sig_fn_12_2396C_MovieState {
    u8 unk_00;
    u8 unk_01;
    s32 unk_04;
    void *unk_08;
    void *unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u8 unk_28;
    s32 unk_2c;
    u8 pad_30[0x10];
} Sig_fn_12_2396C_MovieState;
typedef struct Sig_fn_12_654C_MovieValues {
    s32 value_00;
    s32 value_04;
    s32 value_08;
    s32 value_0c;
    s32 value_10;
    s32 value_14;
    s32 value_18;
    s32 value_1c;
} Sig_fn_12_654C_MovieValues;
typedef struct Sig_fn_12_654C_MovieModule {
    u8 pad00[0x10]; int field10; u8 field14[0x0c];
    Sig_fn_12_654C_MovieValues values;
    Sig_fn_12_654C_MovieValues slots[3]; u8 fielda0[0x20];
} Sig_fn_12_654C_MovieModule;
typedef struct Sig_fn_12_6A18_MovieValues { u32 value_14, value_18, value_1c; } Sig_fn_12_6A18_MovieValues;
typedef struct Sig_fn_12_6A18_MovieModule { u8 pad[0x14]; Sig_fn_12_6A18_MovieValues values; } Sig_fn_12_6A18_MovieModule;
typedef struct Sig_fn_12_6A90_MovieModule { s32 state; } Sig_fn_12_6A90_MovieModule;
extern Sig_fn_12_6B28_MpsHandle *fn_12_6B28(void);
extern int fn_12_654C(Sig_fn_12_654C_MovieModule *, const u8 *, int, int *, int *);
extern int fn_12_6A18(Sig_fn_12_6A18_MovieModule *, Sig_fn_12_6A18_MovieValues *);
extern s32 fn_12_6A90(Sig_fn_12_6A90_MovieModule *);
extern int fn_12_24760(u8 *, int);
extern u32 fn_12_67A4(const u8 *);
extern u8 lbl_12_rodata_B90[56];
extern u32 lbl_12_bss_69BC[549];
extern void fn_12_57F0();
extern void fn_12_24570(void *);
extern int fn_12_23700(u8 *, int, Sig_fn_12_2396C_MovieState *);
extern int fn_12_232DC(u8 *, int, Sig_fn_12_2396C_MovieState *);

static inline u8 *find_start(u8 *p, int size) {
    while (size >= 4) {
        if (fn_12_67A4(p) == 0x10000) return p;
        p++;
        size--;
    }
    return 0;
}

static inline void probe_buffer(u8 *data, int length, Sig_fn_12_2396C_MovieState *state) {
    u32 *buffer;
    int copy_size;
    int size;
    u8 *cursor;
    int step;
    int tries;
    state->unk_04 = (s32)lbl_12_rodata_B90;
    size = length;
    cursor = data;
    tries = 0;
    step = state->unk_10;
    for (;;) {
        if (fn_12_24760(cursor, size) != 0) goto found; /* Keep the verified branch to found. */
        cursor += step;
        size -= step;
        if (tries >= 3 || size <= 0) return;
        tries++;
    }
found:
    buffer = (u32 *)&lbl_12_bss_69BC;
    copy_size = 0x800;
    if (size < 0x800) copy_size = size;
    fn_12_57F0((u8 *)buffer + 0x94, cursor, copy_size);
    buffer[0x90 / 4] = copy_size;
    fn_12_24570(buffer);
    if ((s32)buffer[0] != 0 && (s32)buffer[3] > 0) state->unk_1c = (*((3) + (buffer)));
}
static inline int detect_stride(u8 *data, int length, int *duration) {
    u8 * first = find_start(data, length);
    struct { int value; } offset;
    struct { int value; } remaining;
    u8 *second;
    u8 *third;
    int stride;
    Sig_fn_12_6B28_MpsHandle *handle;
    Sig_fn_12_6A18_MovieValues loc_10;
    int loc_8;
    int loc_C;
    if (first == 0) return 0;
    offset.value = first - data;
    remaining.value = length - offset.value;
    second = find_start(first + 1, remaining.value - 1);
    if (second == 0) return 0;
    third = find_start(second + 1, length - (second - data) - 1);
    if (third == 0) return 0;
    stride = second - first;
    if (stride != third - second) return -1;
    if (offset.value % stride != 0) return -1;
    third = (u8 *)fn_12_6B28();
    handle = (Sig_fn_12_6B28_MpsHandle *)third;
    if (handle != 0) {
        fn_12_654C((Sig_fn_12_654C_MovieModule *)handle, first, remaining.value, &loc_8, &loc_C);
        if (loc_C & 0x10000) {
            fn_12_6A18((Sig_fn_12_6A18_MovieModule *)handle, &loc_10);
            fn_12_6A90((Sig_fn_12_6A90_MovieModule *)handle);
            *duration = loc_10.value_1c;
        }
    }
    return stride;
}
#pragma opt_common_subs off
#pragma opt_propagation off
int fn_12_2396C(u8 *arg0, s32 arg1, Sig_fn_12_2396C_MovieState *arg2) {
    int stride;
    int duration;
    duration = 0;
    stride = detect_stride(arg0, arg1, &duration);
    if (stride == 0) return 0;
    arg2->unk_10 = stride;
    if (stride == -1) return 1;
    if (duration != -1 && duration > 0) arg2->unk_1c = duration * 50;
    probe_buffer(arg0, arg1, arg2);
    fn_12_23700(arg0, arg1, arg2);
    fn_12_232DC(arg0, arg1, arg2);
    return 1;
}

#pragma opt_propagation reset

#pragma opt_common_subs reset


