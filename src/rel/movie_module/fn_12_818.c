#include "types.h"


/* --- rel/movie_module/fn_12_818.c --- */
typedef struct MovieModule {
    u8 pad10[0x10];
    u32 state;
    u32 arg1;
    u32 arg2;
    u8 pad1c[4];
    void *value;
} MovieModule;

extern char lbl_12_rodata_58[8];
extern char lbl_12_rodata_50[5];

typedef struct Sig_SJ_SearchTag_SJCK {
    unsigned char *data;
    int len;
} Sig_SJ_SearchTag_SJCK;

extern unsigned char *SJ_SearchTag(const Sig_SJ_SearchTag_SJCK *needle, const char *name, const char *tag, Sig_SJ_SearchTag_SJCK *out);
extern void fn_12_47C8(void *value, u32 arg1, u32 arg2);

void fn_12_818(MovieModule *self, u32 arg1, u32 arg2) {
    void *value = self->value;
    Sig_SJ_SearchTag_SJCK tag;
    Sig_SJ_SearchTag_SJCK out;

    self->arg1 = arg1;
    self->arg2 = arg2;
    tag.data = (unsigned char *)arg1;
    tag.len = arg2;
    if (SJ_SearchTag(&tag, lbl_12_rodata_50, lbl_12_rodata_58, &out) == 0) {
        fn_12_47C8(value, 0, 0);
    } else {
        fn_12_47C8(value, (u32)out.data, (u32)out.len);
    }
    self->state = 1;
}

/* --- rel/movie_module/fn_12_8B4.c --- */
typedef struct Fn12_8B4Data {
    u8 unk_00[8];
    s32 value_08;
    s32 value_0C;
} Fn12_8B4Data;

void fn_12_8B4(Fn12_8B4Data *data, s32 *value_08, s32 *value_0C) {
    *value_08 = data->value_08;
    *value_0C = data->value_0C;
}

/* --- rel/movie_module/fn_12_8C8.c --- */
typedef struct Fn12_8C8 {
    u8 _pad08[8];
    u32 field_08;
    u32 field_0c;
} Fn12_8C8;

void fn_12_8C8(Fn12_8C8 *self, u32 value_08, u32 value_0c) {
    self->field_08 = value_08;
    self->field_0c = value_0c;
}

/* --- rel/movie_module/fn_12_8D4.c --- */
typedef struct Fn12_8D4 {
    u32 unk0;
    u32 unk4;
} Fn12_8D4;

u32 fn_12_8D4(Fn12_8D4 *self) {
    return self->unk4;
}
