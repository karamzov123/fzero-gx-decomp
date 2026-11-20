#include "types.h"


/* --- dol/fn_8006A998.c --- */
/* --- dol/fn_8006A998.c --- */
struct fn_8006A998_Arg0 {
    u32 unk_0;
    u32 unk_4;
};

u32 fn_8006A998(struct fn_8006A998_Arg0 *arg0) {
    return (*(u32 *)((u8 *)arg0->unk_0 + 0) + arg0->unk_4);
}

/* --- dol/fn_8006A9AC.c --- */
typedef struct Fn8006A9ACData {
    u8 _pad[8];
    u32 value;
} Fn8006A9ACData;

u32 fn_8006A9AC(Fn8006A9ACData *data) {
    return data->value;
}

/* --- dol/fn_8006A9B4.c --- */
typedef struct Fn8006A9B4Entry {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} Fn8006A9B4Entry;

typedef struct Fn8006A9B4Data {
    u32 unk_0;
    Fn8006A9B4Entry *unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
} Fn8006A9B4Data;

s32 fn_8006A554(void);

s32 fn_8006A9B4(Fn8006A9B4Data *data) {
    s32 idx = fn_8006A554();
    Fn8006A9B4Entry *tbl = data->unk_4;

    if (idx < 0 || ((tbl[idx].unk_0 & 0xFF000000) == 0 ? 0 : 1) == 0) {
        return 0;
    }
    data->unk_18 = idx;
    return 1;
}
