#include "types.h"


/* --- dol/fn_80058754.c --- */
struct fn_80058754_lbl_8018F2A8 {
    u32 unk_0;
};

extern struct fn_80058754_lbl_8018F2A8 lbl_8018F2A8[];
extern u32 lbl_8018F2AC[];
extern u32 memset(u32, u32, u32);

u32 fn_80058754(u32 arg0, u32 arg1);

/* --- dol/SJ_SearchTag.c --- */
typedef struct SJCK {
    unsigned char *data;
    int len;
} SJCK;

int strncmp(const char *lhs, const char *rhs, unsigned long count);

extern int lbl_80132330[0x70];

static inline int sj_hexstr_to_val(const unsigned char *text, const int *table) {
    int value;
    value = table[(signed char)text[0]];
    value = (value << 4) + table[(signed char)text[1]];
    value = (value << 4) + table[(signed char)text[2]];
    value = (value << 4) + table[(signed char)text[3]];
    value = (value << 4) + table[(signed char)text[4]];
    value = (value << 4) + table[(signed char)text[5]];
    value = (value << 4) + table[(signed char)text[6]];
    return value;
}

unsigned char *SJ_SearchTag(const SJCK *source, const char *tag, const char *terminator,
                           SJCK *result) {
    unsigned char *current;
    unsigned char *end;
    unsigned char *start;
    const int *table;
    result->data = 0;
    table = lbl_80132330;
    result->len = 0;
    start = source->data;
    current = start;
    end = start + source->len;
    while (current < end) {
        if (strncmp((const char *)current, tag, 7) == 0) {
            result->data = current + 0x10;
            result->len = sj_hexstr_to_val(current + 8, lbl_80132330);
            break;
        }
        if (terminator != 0 && strncmp((const char *)current, terminator, 7) == 0) {
            return 0;
        }
        current += sj_hexstr_to_val(current + 8, table) + 0x10;
    }
    return current < end ? current : 0;
}

/* --- dol/fn_800589BC.c --- */
/* --- dol/fn_800589BC.c --- */
struct fn_800589BC_Arg2 {
    u32 unk_0;
    u32 unk_4;
};
struct fn_800589BC_Arg3 {
    u32 unk_0;
    u32 unk_4;
};
struct fn_800589BC_Copy8 { u32 a[2]; };

u32 fn_800589BC(u32 arg0, u32 arg1, struct fn_800589BC_Arg2 *arg2, struct fn_800589BC_Arg3 *arg3) {
    u32 v0;
    u32 v1;
    *(struct fn_800589BC_Copy8 *)(u32)arg2 = *(struct fn_800589BC_Copy8 *)arg0;
    arg3->unk_4 = arg2->unk_4;
    if ((s32)arg2->unk_4 > (s32)arg1) {
    arg2->unk_4 = arg1;
    }
    v0 = arg2->unk_4;
    arg3->unk_4 = (arg3->unk_4 - v0);
    if ((s32)arg3->unk_4 == 0) {
    arg3->unk_0 = 0;
    return v0;
    }
    v1 = arg2->unk_0;
    arg3->unk_0 = (v1 + arg2->unk_4);
    return v1;
}
