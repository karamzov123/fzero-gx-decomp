#include "types.h"


/* --- rel/movie_module/fn_12_2692C.c --- */
extern void fn_12_24970(void *);
extern int fn_12_24A88(void *, int);
extern void fn_12_2AB00(void *);
extern void fn_12_24950(void *);

int fn_12_2692C(void *arg0, void *arg1) {
    u8 local[8];
    int index;
    void *context;
    void *entry;
    int result;

    fn_12_24970(local);
    index = *(int *)((u8 *)arg0 + 0x1b3c);
    context = *(void **)((u8 *)arg0 + 0x1b30);
    entry = (u8 *)arg0 + index * 0x74;
    entry = *(void **)((u8 *)entry + 0x1160);
    if (*(int *)entry != 1) {
        result = fn_12_24A88(arg0, 0xff000f0e);
    } else if ((u8 *)entry + 4 != (u8 *)arg1) {
        result = fn_12_24A88(arg0, 0xff000f0f);
    } else {
        *(int *)entry = 0;
        fn_12_2AB00(*(void **)((u8 *)context + 0x70));
        result = 0;
    }
    fn_12_24950(local);
    return result;
}

/* --- rel/movie_module/fn_12_269E4.c --- */
struct fn_12_269E4_arg0_1138_E116 {
    u8 pad_0[0x28];
    u32 unk_28;
    u8 pad_2C[0x48];
};
struct fn_12_269E4_Arg0 {
    u8 pad_0[0x38];
    u32 unk_38;
    u8 pad_3C[0x10FC];
    struct fn_12_269E4_arg0_1138_E116 unk_1138[1];
    u8 pad_11AC[0x984];
    u32 unk_1B30;
    u8 pad_1B34[0x8];
    u32 unk_1B3C;
};
struct fn_12_269E4_Arg1 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x8];
    u32 unk_40;
    u8 pad_44[0x18];
    u32 unk_5C;
    u32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u32 unk_6C;
    u32 unk_70;
    u32 unk_74;
};
struct fn_12_269E4_Arg2 {
    u32 unk_0;
};


void fn_12_269E4(struct fn_12_269E4_Arg0 *arg0, struct fn_12_269E4_Arg1 *arg1, struct fn_12_269E4_Arg2 *arg2) {
    u32 v1;
    u32 v0;
    u32 v2;
    v0 = arg0->unk_1138[arg0->unk_1B3C].unk_28;
    v1 = arg0->unk_1B30;
    arg2->unk_0 = (v0 + 4);
    *(u32 *)((u8 *)v0 + 0) = 1;
    *(u32 *)((u8 *)v1 + 112) = (u32)arg1;
    *(u32 *)((u8 *)arg2->unk_0 + 0) = arg1->unk_28;
    *(u32 *)((u8 *)arg2->unk_0 + 4) = arg1->unk_2C;
    *(u32 *)((u8 *)arg2->unk_0 + 8) = arg1->unk_30;
    *(u32 *)((u8 *)arg2->unk_0 + 12) = arg1->unk_34;
    *(u32 *)((u8 *)arg2->unk_0 + 16) = arg1->unk_40;
    *(u32 *)((u8 *)arg2->unk_0 + 20) = arg1->unk_8;
    *(u32 *)((u8 *)arg2->unk_0 + 24) = arg1->unk_C;
    *(u32 *)((u8 *)arg2->unk_0 + 28) = arg0->unk_38;
    *(u32 *)((u8 *)arg2->unk_0 + 32) = arg1->unk_4;
    *(u32 *)((u8 *)arg2->unk_0 + 36) = arg1->unk_10;
    *(u32 *)((u8 *)arg2->unk_0 + 40) = arg1->unk_14;
    *(u32 *)((u8 *)arg2->unk_0 + 44) = arg1->unk_18;
    *(u32 *)((u8 *)arg2->unk_0 + 48) = arg1->unk_1C;
    *(u32 *)((u8 *)arg2->unk_0 + 52) = arg1->unk_20;
    *(u32 *)((u8 *)arg2->unk_0 + 56) = arg1->unk_24;
    *(u32 *)((u8 *)arg2->unk_0 + 60) = arg1->unk_5C;
    *(u32 *)((u8 *)arg2->unk_0 + 64) = arg1->unk_60;
    *(u32 *)((u8 *)arg2->unk_0 + 68) = arg1->unk_64;
    *(u32 *)((u8 *)arg2->unk_0 + 72) = arg1->unk_68;
    *(u32 *)((u8 *)arg2->unk_0 + 76) = arg1->unk_6C;
    *(u32 *)((u8 *)arg2->unk_0 + 80) = arg1->unk_70;
    v2 = arg2->unk_0;
    *(u32 *)((u8 *)v2 + 84) = arg1->unk_74;
}
