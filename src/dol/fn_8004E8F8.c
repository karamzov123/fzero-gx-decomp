#include "types.h"

typedef void (*fn_8004E8F8_callback)(u32);

struct fn_8004E8F8_lbl_80178CB8 {
    u32 unk_0;
    u8 pad_4[0x10];
};

struct fn_8004E8F8_lbl_8012B930 {
    fn_8004E8F8_callback callback_0;
    u32 unk_4;
    u8 pad_8[0x10];
};

struct fn_8004E8F8_lbl_8017E980 {
    u8 pad_0[0x14];
    s32 count_14;
    u8 pad_18[0x10];
    u8 thread_28[0x318];
    u8 pad_340[0x958];
    s32 field_C98;
    s32 field_C9C;
    s32 field_CA0;
};

extern struct fn_8004E8F8_lbl_8012B930 lbl_8012B930;
extern struct fn_8004E8F8_lbl_80178CB8 lbl_80178CB8;
extern struct fn_8004E8F8_lbl_8017E980 lbl_8017E980;
extern void OSResumeThread(void *);
extern void fn_80058E44(void);
extern void VIWaitForRetrace(void);

void fn_8004E8F8(void) {
    struct fn_8004E8F8_lbl_8017E980 *p_s = &lbl_8017E980;
    struct fn_8004E8F8_lbl_8012B930 *p_b = &lbl_8012B930;
    struct fn_8004E8F8_lbl_80178CB8 *p_a = &lbl_80178CB8;

    while (p_s->field_C9C == 1) {
        u32 v0;
        u32 v1;

        VIWaitForRetrace();
        v0 = p_a->unk_0;
        v1 = p_s->count_14 + 1;
        p_a->unk_0 = v0 + 1;
        p_s->count_14 = v1;
        fn_80058E44();
        if (p_s->field_CA0 == 0) {
            OSResumeThread(&p_s->thread_28);
            if (p_b->callback_0 != 0) {
                p_b->callback_0(p_b->unk_4);
            }
        }
    }
    p_s->field_C98 = 1;
}
