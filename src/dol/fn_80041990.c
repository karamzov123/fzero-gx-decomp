#include "types.h"
typedef struct Sig_fn_80041990_AdxSjdHandle Sig_fn_80041990_AdxSjdHandle;
typedef struct Sig_fn_80041BF8_fn_80041BF8_Obj Sig_fn_80041BF8_fn_80041BF8_Obj;
struct Sig_fn_80041BF8_fn_80041BF8_Obj { void **vtable; };
struct Sig_fn_80045414_fn_80045414_Arg0 { u8 pad_0[4]; u32 unk_4; };
struct Sig_fn_80044E7C_fn_80044E7C_Arg0 { u8 pad_0[0x98]; s16 unk_98; };
struct Sig_fn_8004550C_fn_8004550C_Arg0 { u8 pad_0[0x18]; u32 unk_18; };
struct Sig_fn_80045304_fn_80045304_Arg0 { u8 pad_0[0x94]; u32 unk_94; };
typedef struct { u8 pad[0x90]; u32 field; } Sig_fn_800452FC_Fn800452FCObject;
struct Sig_fn_800589BC_fn_800589BC_Arg2 { u32 unk_0; u32 unk_4; };
struct Sig_fn_800589BC_fn_800589BC_Arg3 { u32 unk_0; u32 unk_4; };
struct Sig_fn_80045588_fn_80045588_Arg0 { u8 pad_0[0xE]; u8 unk_E; };
struct Sig_fn_8004530C_fn_8004530C_Arg0 { u8 pad_0[4]; u32 unk_4; };
struct Sig_fn_80041BF8_fn_80041BF8_Arg0;
typedef u32 (*fn_80041990_Fn0)(u32, u32, void *);
typedef u32 (*fn_80041990_Fn1)(u32, u32, void *);
typedef u32 (*fn_80041990_Fn2)(u32, u32, u32, u32);
typedef u32 (*fn_80041990_Fn3)(u32, u32, void *);
typedef u32 (*fn_80041990_Fn4)(u32, u32, void *);
extern s32 fn_80045588(struct Sig_fn_80045588_fn_80045588_Arg0 *);
extern u32 fn_80041EF8(Sig_fn_80041990_AdxSjdHandle *);
extern u32 fn_800452FC(Sig_fn_800452FC_Fn800452FCObject *);
extern u32 fn_80045304(struct Sig_fn_80045304_fn_80045304_Arg0 *);
extern u32 fn_8004530C(struct Sig_fn_8004530C_fn_8004530C_Arg0 *);
extern u32 fn_80045414(struct Sig_fn_80045414_fn_80045414_Arg0 *);
extern u32 fn_8004550C(struct Sig_fn_8004550C_fn_8004550C_Arg0 *);
extern u32 fn_800589BC(void *, u32, struct Sig_fn_800589BC_fn_800589BC_Arg2 *, struct Sig_fn_800589BC_fn_800589BC_Arg3 *);
extern void fn_80041BF8(struct Sig_fn_80041BF8_fn_80041BF8_Arg0 *);
extern void fn_80044E7C(struct Sig_fn_80044E7C_fn_80044E7C_Arg0 *);
void fn_80041990(Sig_fn_80041990_AdxSjdHandle *arg0) {
    struct { u32 value; } v1;
    u32 v2;
    u32 v3;
    Sig_fn_80041990_AdxSjdHandle *v10;
    struct { u32 value; } v5;
    u32 v6;
    Sig_fn_80041990_AdxSjdHandle *v9;
    u32 v4;
    struct { s32 value; } v11;
    u32 doubled;
    u32 limit;
    s16 v15;
    struct { u32 value; } v16;
    u32 v17;
    u32 v18;
    u32 v19;
    struct Sig_fn_800589BC_fn_800589BC_Arg3 loc_10;
    struct Sig_fn_800589BC_fn_800589BC_Arg2 loc_8;
    if ((s8)*((u8 *)arg0 + 1) == 2) {
        v1.value = *(u32 *)((u8 *)arg0 + 4);
        if ((s32)fn_80045414((struct Sig_fn_80045414_fn_80045414_Arg0 *)v1.value) == 0)
            fn_80041BF8((struct Sig_fn_80041BF8_fn_80041BF8_Arg0 *)arg0);
        fn_80044E7C((struct Sig_fn_80044E7C_fn_80044E7C_Arg0 *)v1.value);
        if ((s32)fn_80045414((struct Sig_fn_80045414_fn_80045414_Arg0 *)v1.value) == 3) {
            v2 = *(u32 *)((u8 *)arg0 + 4);
            v3 = *(u32 *)((u8 *)arg0 + 8);
            v4 = fn_8004550C((struct Sig_fn_8004550C_fn_8004550C_Arg0 *)v2);
            v5.value = fn_80045304((struct Sig_fn_80045304_fn_80045304_Arg0 *)v2);
            limit = fn_800452FC((Sig_fn_800452FC_Fn800452FCObject *)v2);
            v6 = v4 - *(u32 *)((u8 *)arg0 + 52);
            if ((s32)limit < (s32)v6) v6 = limit;
            fn_800589BC((u8 *)arg0 + 20, v5.value, &loc_8, &loc_10);
            ((fn_80041990_Fn0)*(u32 *)(*(u32 *)v3 + 32))(v3, 0, &loc_8);
            ((fn_80041990_Fn1)*(u32 *)(*(u32 *)v3 + 28))(v3, 1, &loc_10);
            v10 = arg0;
            v9 = arg0;
            doubled = v6 << 1;
            for (v11.value = 0; v11.value < fn_80045588((struct Sig_fn_80045588_fn_80045588_Arg0 *)*(u32 *)((u8 *)arg0 + 4)); v11.value++) {
                u32 obj;
                fn_800589BC((u8 *)v10 + 28, doubled, &loc_8, &loc_10);
                if (*(u32 *)((u8 *)arg0 + 80) != 0)
                    ((fn_80041990_Fn2)*(u32 *)((u8 *)arg0 + 80))(*(u32 *)((u8 *)arg0 + 84), v11.value, loc_8.unk_0, loc_8.unk_4);
                obj = *(u32 *)((u8 *)v9 + 12);
                ((fn_80041990_Fn3)*(u32 *)(*(u32 *)obj + 32))(obj, 1, &loc_8);
                obj = *(u32 *)((u8 *)v9 + 12);
                ((fn_80041990_Fn4)*(u32 *)(*(u32 *)obj + 28))(obj, 0, &loc_10);
                v10 = (Sig_fn_80041990_AdxSjdHandle *)((u8 *)v10 + 8);
                v9 = (Sig_fn_80041990_AdxSjdHandle *)((u8 *)v9 + 4);
            }
            *(u32 *)((u8 *)arg0 + 44) += v6;
            *(u32 *)((u8 *)arg0 + 48) += v5.value;
            *(u32 *)((u8 *)arg0 + 52) += v6;
            *(u32 *)((u8 *)arg0 + 64) += v6;
            *(u32 *)((u8 *)arg0 + 68) += v5.value;
            fn_8004530C((struct Sig_fn_8004530C_fn_8004530C_Arg0 *)v2);
        }
        v15 = *(s16 *)(v1.value + 152);
        if ((s32)v15 == 10 || v15 == 20 || v15 == 11 || v15 == 15) {
            v16.value = *(u32 *)((u8 *)arg0 + 4);
            v17 = fn_8004550C((struct Sig_fn_8004550C_fn_8004550C_Arg0 *)v16.value);
            v18 = fn_80045304((struct Sig_fn_80045304_fn_80045304_Arg0 *)v16.value);
            limit = fn_800452FC((Sig_fn_800452FC_Fn800452FCObject *)v16.value);
            v19 = v17 - *(u32 *)((u8 *)arg0 + 52);
            if ((s32)limit < (s32)v19) v19 = limit;
            *(u32 *)((u8 *)arg0 + 44) += v19;
            *(u32 *)((u8 *)arg0 + 48) += v18;
            *(u32 *)((u8 *)arg0 + 52) += v19;
        }
    } else if ((s8)*((u8 *)arg0 + 1) == 1) {
        fn_80041EF8(arg0);
    }
}
