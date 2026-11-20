#include "types.h"


/* --- dol/fn_8005BE68.c --- */
u32 fn_8005BE68(u32 arg0) {
    u32 v0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = 0;
    return v0;
    }
    v0 = *(u32 *)((u8 *)v0 + 8);
    return v0;
}

/* --- dol/fn_8005BE80.c --- */
typedef struct {
    int unk00;
    int unk04;
} Fn8005BE80Object;

int fn_8005BE80(Fn8005BE80Object* object) {
    if (object == 0) {
        return 0;
    }
    return object->unk04;
}

/* --- dol/fn_8005BE98.c --- */
struct fn_8005BE98_Arg0 {
    u32 unk_0;
};

void fn_8005BE98(struct fn_8005BE98_Arg0 *arg0) {
    if (arg0 == 0) { return; }
    arg0->unk_0 = 0;
}
