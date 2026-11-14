#include "types.h"
struct fn_12_86B8_Arg0 {
    u8 pad_0[0x118];
    u32 unk_118;
};
extern u32 fn_12_847C(void *, u32, void *, void *, void *);
extern u32 fn_12_80BC(u32, void *, u32);


void fn_12_86B8(void *arg0) {
    u32 temp_r3;
    s32 sp8;
    void *temp_r31;
    void *temp_r30;
    u32 field_118;
    void * lab_t2;
    void * lab_t2_;

    temp_r31 = (void *)((u8 *)(arg0) + 0x234);
    temp_r30 = (void *)((u8 *)(arg0) + 0x110);
    lab_t2 = (void *)(&sp8);
    lab_t2_ = lab_t2;
    fn_12_847C((void *)(arg0), (u32)(*(u32 *)((u8 *)(arg0) + 280)), lab_t2_, (void *)(temp_r31), (void *)((u8 *)(arg0) + 0x2C0));
    lab_t2 = (void *)(&sp8);
    lab_t2_ = lab_t2;
    fn_12_847C((void *)(arg0), (u32)(*(u32 *)((u8 *)(temp_r30) + 12)), lab_t2_, (void *)((u8 *)(temp_r31) + 0x10), (void *)((u8 *)(arg0) + 0x2E4));
    temp_r3 = *(u32 *)((u8 *)(arg0) + 596);
    (*(u32 *)((u8 *)(arg0) + 596)) = (u32) (temp_r3 + 0x180);
    fn_12_80BC((u32)(temp_r3), (void *)(temp_r30), (u32)(*(u32 *)((u8 *)(arg0) + 788)));
}

