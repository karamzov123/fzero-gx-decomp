#include "types.h"

typedef struct {
    u32 unk_00;
    u8 pad_04[0xf];
    u8 unk_13;
    u8 pad_14[0x8];
    u32 unk_1c;
    u8 pad_20[0x8];
    u32 arr_28[2];
    u32 arr_30[6];
    u32 arr_48[2];
    u32 arr_50[2];
} fn_80078360_Arg0;

typedef struct {
    u8 pad_00[0x8];
    u32 offset;
    u8 pad_0c[0x10];
    u32 unk_1c;
} fn_80078360_Arg2;

typedef struct {
    u8 pad_00[0x4];
    u32 flags;
    u8 pad_08[0x28];
    u32 unk_30;
    u32 unk_34;
} fn_80078360_Arg4;

typedef u32 (*fn_80078360_Cb)(void *);

extern u32 fn_80075908(u32, u32);
extern u32 fn_80078344(u32, u32);
extern u32 fn_80078884(u32, u32, u32, u32);
extern u32 fn_80078944(u32, u32, u32, u32);
extern u32 lbl_801A6D90;
extern s32 lbl_801A6D94;
extern u32 lbl_801A6D98;
extern void fn_80033E7C(void);
extern void fn_8003458C(void);
extern void fn_800723B8(u32, u32);
extern u32 fn_800723D8(void);
extern void fn_8007245C(u32);
extern void fn_80078D60(s32);

#pragma opt_loop_invariants off
#pragma opt_propagation off
static inline void fn_80078360_store(void *destination, u32 value) { *(u32 *)destination = value; }
void *fn_80078360(fn_80078360_Arg0 *arg0, u8 *arg1, fn_80078360_Arg2 *arg2, u8 *arg3, fn_80078360_Arg4 *arg4) {
    u32 v0;
    s32 mask2;
    u32 v1;
    u8 *p;
    s32 i;
    s32 flag;
    u32 t;
    u8 *v2;
    u8 cond;
    struct { u32 a[14]; } loc_8;
    s32 tmp_ra3;

    v1 = arg2->offset;
    v2 = (u8 *)arg2 + v1;
    t = lbl_801A6D98 ^ 2;
    mask2 = arg0->unk_00 & 2;
    if (mask2 != 0) {
        t = 0;
    }
    flag = t ^ 0;
    fn_8007245C(arg0->unk_1c);
    if (lbl_801A6D90 != 0) {
        (*((loc_8.a) + (1))) = (u32)arg0;
        (*((loc_8.a) + (2))) = (u32)arg1;
        cond = (u8)((fn_80078360_Cb)lbl_801A6D90)(&loc_8);
    } else {
        if (lbl_801A6D94 == 0) {
            fn_80075908((u32)arg0, (u32)arg1);
        }
        cond = 1;
    }
    if (cond != 0) {
        fn_8003458C();
        p = (u8 *)arg0;
        for (i = 0, p = (u8 *)arg0; i < 2; i++, p += 4) {
            if ((arg0->unk_13 & (1 << i)) != 0) {
                fn_80078D60(flag);
                if ((arg4->flags & 0x40) != 0) {
                    fn_80078344(*(u32 *)(p + 0x48), *(u32 *)(p + 0x50));
                } else {
                    tmp_ra3 = arg4->flags;
                    if ((tmp_ra3 & 0x20) != 0) {
                        *(u32 *)(p + 0x48) = (arg4->unk_30 + 31) & ~0x1F;
                        fn_800723B8(*(u32 *)(p + 0x48), 0x80000);
                        fn_80033E7C();
                    }
                    if ((arg2->unk_1c & 1) != 0) {
                        fn_80078944(arg0->unk_1c, (u32)v2, (u32)arg3, *(u32 *)(p + 0x28));
                        arg3 += *(u32 *)(p + 0x28) << 1;
                    } else {
                        fn_80078884(arg0->unk_1c, (u32)v2, (u32)arg3, *(u32 *)(p + 0x28));
                        arg3 += *(u32 *)(p + 0x28) << 2;
                    }
                    if ((arg4->flags & 0x20) != 0) {
                        *(u32 *)(p + 0x50) = fn_800723D8();
                        fn_80078344(*(u32 *)(p + 0x48), *(u32 *)(p + 0x50));
                        arg4->unk_30 = *(u32 *)(p + 0x48) + *(u32 *)(p + 0x50);
                        fn_80078360_store(&(arg4->unk_34), arg4->unk_34 + *(u32 *)(p + 0x50));
                    }
                }
            }
            if (flag != 0) {
                flag = lbl_801A6D98 ^ 1;
            }
        }
    }
    return arg3;
}
#pragma opt_loop_invariants reset
