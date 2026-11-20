#include "types.h"

typedef struct ObjectData ObjectData;
typedef struct Object {
    u8 unk0[4];
    ObjectData *data;
    u8 unk8[8];
    u32 value10;
    u8 unk14[4];
    u8 unk18[0];
} Object;

struct ObjectData {
    u8 unk0[0xb0];
    u32 callback_data;
};

extern u32 ADXT_Stop(u32);
struct GlobalBlock {
    u32 value;
    u8 pad[0xfc];
};

extern struct GlobalBlock lbl_8017E58C;
extern struct GlobalBlock lbl_8017A280;
extern struct GlobalBlock lbl_8017A284;
extern u32 fn_80054608(void);
extern u32 fn_8004EBD4(void);
extern u32 fn_80054354(u32, u32, void *, u32, u32);
extern char lbl_80091300[24];
extern char lbl_80091318[20];
extern u32 fn_80047464(char *, char *);
extern u32 fn_80051DC4(void);
extern u32 fn_80051CC0(void);
extern u32 fn_800542B4(void);

extern u32 fn_8004EBB4(void);

void fn_80051E64(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 v2;
    u32 v1;
    u32 v3;

    ADXT_Stop(arg0);
    if (lbl_8017E58C.value != 0) {
        ((void (*)(u32))lbl_8017E58C.value)(arg0);
    }
    fn_80054608();
    v0 = *(u32 *)(arg0 + 4);
    v1 = *(u32 *)(arg0 + 0x10);
    v2 = *(u32 *)(v0 + 4);
    fn_8004EBD4();
    v3 = fn_80054354(v1, 1, (u8 *)arg0 + 0x18, arg1, arg2);
    if (v3 == 0) {
        fn_80047464(lbl_80091300, lbl_80091318);
    } else {
        *(u32 *)((u8 *)v2 + 0xb0) = v3;
        lbl_8017E58C.value = (u32)fn_80051DC4;
        lbl_8017A280.value = (u32)fn_80051CC0;
        lbl_8017A284.value = (u32)fn_800542B4;
        fn_8004EBB4();
    }
}
