#include "types.h"

typedef struct Fn12_39A68_Object {
    u8 _pad0[4];
    s32 unk4;
    u8 _pad8[0x38];
    u32 unk40;
} Fn12_39A68_Object;

typedef struct Fn12_39A68_Result {
    u8 _pad0[4];
    s32 f04;
    u8 _pad8[8];
    s32 f10;
    u8 _pad14[8];
    s32 f1c;
    u8 _pad20[0x20];
} Fn12_39A68_Result;

typedef struct Fn12_39A68_Out {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Fn12_39A68_Out;

static const char lbl_12_rodata_2718[212] = { 69, 49, 49, 50, 50, 54, 52, 48, 58, 32, 109, 119, 80, 108, 121, 71, 101, 116, 83, 102, 100, 72, 110, 58, 32, 104, 97, 110, 100, 108, 101, 32, 105, 115, 32, 105, 110, 118, 97, 108, 105, 100, 46, 0, 69, 50, 48, 57, 51, 48, 48, 49, 32, 109, 119, 80, 108, 121, 65, 116, 116, 97, 99, 104, 77, 50, 118, 58, 32, 119, 111, 114, 107, 115, 105, 122, 101, 32, 105, 115, 32, 105, 110, 118, 97, 108, 105, 100, 46, 0, 0, 0, 69, 50, 49, 49, 48, 53, 49, 58, 32, 109, 119, 80, 108, 121, 83, 101, 116, 70, 108, 111, 97, 116, 83, 112, 101, 101, 100, 58, 32, 104, 97, 110, 100, 108, 101, 32, 105, 115, 32, 105, 110, 118, 97, 108, 105, 100, 46, 0, 0, 0, 0, 0, 63, -32, 0, 0, 0, 0, 0, 0, 68, 122, 0, 0, 0, 0, 0, 0, 67, 48, 0, 0, -128, 0, 0, 0, 69, 51, 48, 50, 50, 53, 49, 58, 32, 109, 119, 80, 108, 121, 83, 101, 116, 83, 112, 101, 101, 100, 58, 32, 104, 97, 110, 100, 108, 101, 32, 105, 115, 32, 105, 110, 118, 97, 108, 105, 100, 46, 0, 0 };
static const char lbl_12_rodata_2718__fzgx_offset_D4[44] = { 69, 50, 48, 50, 49, 57, 49, 58, 32, 109, 119, 80, 108, 121, 71, 101, 116, 80, 108, 121, 73, 110, 102, 58, 32, 104, 97, 110, 100, 108, 101, 32, 105, 115, 32, 105, 110, 118, 97, 108, 105, 100, 46, 0 };
static const char lbl_12_rodata_2718__fzgx_offset_100[48] = { 69, 50, 48, 50, 50, 51, 50, 58, 32, 109, 119, 80, 108, 121, 71, 101, 116, 78, 117, 109, 68, 114, 111, 112, 70, 114, 109, 58, 32, 104, 97, 110, 100, 108, 101, 32, 105, 115, 32, 105, 110, 118, 97, 108, 105, 100, 46, 0 };
static const char lbl_12_rodata_2848[49] = { 69, 49, 49, 50, 50, 54, 49, 57, 58, 32, 109, 119, 80, 108, 121, 71, 101, 116, 78, 117, 109, 83, 107, 105, 112, 68, 101, 99, 58, 32, 104, 97, 110, 100, 108, 101, 32, 105, 115, 32, 105, 110, 118, 97, 108, 105, 100, 46, 0 };
extern void MWSFSVM_Error(const char *format, ...);
extern void fn_12_2D58C(void *data, Fn12_39A68_Result *result);
extern u32 fn_12_33874(Fn12_39A68_Object *object);

static inline s32 ply_is_valid(Fn12_39A68_Object *object) {
    if (object == 0) return 0;
    return object->unk4;
}

static inline void *ply_get_stream(Fn12_39A68_Object *object) {
    if (!ply_is_valid(object)) {
        MWSFSVM_Error(lbl_12_rodata_2718);
        return 0;
    }
    return (void *)object->unk40;
}

static inline s32 ply_get_skip_dec(Fn12_39A68_Object *object) {
    Fn12_39A68_Result result;
    if (!ply_is_valid(object)) {
        MWSFSVM_Error(lbl_12_rodata_2848);
        return 0;
    }
    fn_12_2D58C(ply_get_stream(object), &result);
    return result.f04 - result.f10;
}





s32 fn_12_3A69C(Fn12_39A68_Object *object) {
    s32 skipped;
    if (!ply_is_valid(object)) {
        MWSFSVM_Error(lbl_12_rodata_2718__fzgx_offset_100);
        return 0;
    }
    skipped = ply_get_skip_dec(object);
    return skipped + fn_12_33874(object);
}
