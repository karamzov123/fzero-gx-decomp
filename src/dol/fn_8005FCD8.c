#include "types.h"

typedef struct Sig_fn_80023168_Fn80023168State {
    u8 pad_000[0x1c];
    u32 flags;
    u32 state;
    u8 pad_024[0x122];
    u16 value;
} Sig_fn_80023168_Fn80023168State;

typedef struct Sig_fn_80028424_Fn80028424Node Sig_fn_80028424_Fn80028424Node;
struct Sig_fn_80028424_Fn80028424Node {
    Sig_fn_80028424_Fn80028424Node *next;
    Sig_fn_80028424_Fn80028424Node *prev;
    void *data;
};

typedef struct Fn8005FCD8Entry {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[7];
    u8 unk_9;
    u8 unk_a;
    u8 pad_b[0xd];
    u32 unk_18;
    u32 pad_1c;
    u32 pad_20;
    u32 unk_24;
    u32 pad_28;
    u32 unk_2c;
    u8 unk_30[0xe8];
} Fn8005FCD8Entry;

typedef struct Fn8005FCD8Data {
    u8 pad_0[0x1408];
    Fn8005FCD8Entry entries[0x40];
} Fn8005FCD8Data;

extern Fn8005FCD8Data *lbl_801A6C80;
extern void fn_80020ABC(u32);
extern void fn_80023168(Sig_fn_80023168_Fn80023168State *, u16);
extern u32 fn_80026D70(void *);
extern void fn_80028424(Sig_fn_80028424_Fn80028424Node *);
extern void fn_80060BDC(u32);

void fn_8005FCD8(u32 arg0) {
    if (lbl_801A6C80->entries[arg0].unk_0 != 0xFF) {
        fn_80023168((Sig_fn_80023168_Fn80023168State *)
                        lbl_801A6C80->entries[arg0].unk_2c,
                    0);
        fn_80026D70((void *)lbl_801A6C80->entries[arg0].unk_2c);
        fn_80020ABC(lbl_801A6C80->entries[arg0].unk_2c);
        lbl_801A6C80->entries[arg0].unk_2c = 0;
        if (lbl_801A6C80->entries[arg0].unk_0 == 3) {
            fn_80060BDC(arg0);
        } else {
            fn_80028424((Sig_fn_80028424_Fn80028424Node *)
                            lbl_801A6C80->entries[arg0].unk_30);
        }
        lbl_801A6C80->entries[arg0].unk_0 = 0xFF;
        lbl_801A6C80->entries[arg0].unk_18 = 0;
        lbl_801A6C80->entries[arg0].unk_1 = 0;
        if (lbl_801A6C80->entries[arg0].unk_9 == arg0) {
            lbl_801A6C80->entries[arg0].unk_9 = 0xFF;
        } else {
            if (lbl_801A6C80->entries[arg0].unk_a == arg0) {
                lbl_801A6C80->entries[arg0].unk_a = 0xFF;
            }
        }
    }
}
