#include "types.h"


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
