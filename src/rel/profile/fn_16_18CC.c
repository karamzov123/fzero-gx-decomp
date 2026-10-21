#include "types.h"
#include "rel/profile/data/lbl_16_data_0.h"

typedef struct {
    s32 active;
    s32 entries[5];
} Sig_fn_1_8F494_Fn1_8F494_Object;

struct fn_16_18CC_Tbl {
    u32 unk_0[1];
};

/* save handles after the profile text data; retail addresses them off one base (data_0 + 0x80000) */
struct fn_16_18CC_ProfileHandles {
    u8 pad_0[0x2B00];
    s32 bioHandle;      /* 0x2B00 */
    s32 machineHandle;  /* 0x2B04 */
    s32 entryHandle[19];/* 0x2B08 */
    struct fn_16_18CC_Tbl tbl; /* 0x2B54 */
};

/* one 0x4E8-byte entry; the first one starts at the head of lbl_1_bss_8B614 */
struct fn_16_18CC_Entry {
    u8 pad_0[0xC];
    s16 unk_C;
    u8 pad_E[0x4A];
    s16 unk_58;
    u8 pad_5A[0x1A];
    Sig_fn_1_8F494_Fn1_8F494_Object obj; /* 0x74 */
    u8 pad_8C[0x4E8 - 0x8C];
};

struct fn_16_18CC_lbl_16_bss_220_elem {
    u8 pad_0[0x324];
    u32 unk_324;
    u8 pad_328[0x118];
};

extern u32 lbl_16_bss_150;
extern u32 lbl_16_bss_14C;
extern struct fn_16_18CC_lbl_16_bss_220_elem lbl_16_bss_220[];
extern struct fn_16_18CC_Entry lbl_1_bss_8B614[];

extern u32 fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_1_8F494(Sig_fn_1_8F494_Fn1_8F494_Object *);
extern s32 fn_1_12CB04(s16);
extern void fn_1_48140(int);
extern void fn_1_80F1C(s32, void *);

#pragma opt_propagation off
void fn_16_18CC(void) {
    struct fn_16_18CC_Entry *p;
    struct fn_16_18CC_ProfileHandles *d;
    struct { s32 value; } i;
    struct { s16 value; } idx;
    struct fn_16_18CC_lbl_16_bss_220_elem *e;
    /* one-member carriers: a constant address in a plain pointer is rematerialised */
    struct { struct fn_16_18CC_Entry *value; } ent;
    s32 *handles;
    struct { u32 value; } tb;
    Sig_fn_1_8F494_Fn1_8F494_Object * lab_t0;

    d = (struct fn_16_18CC_ProfileHandles *)((u8 *)&lbl_16_data_0 + 0x80000);
    if (d->bioHandle != -1) {
        fn_1_435C(lbl_16_bss_150);
        fn_1_426C(d->bioHandle);
        d->bioHandle = -1;
    }
    i.value = 0;
    p = lbl_1_bss_8B614;
    idx.value = p->unk_C;
    if (p->unk_58 == 4) {
        lab_t0 = &p->obj;
        fn_1_8F494(lab_t0);
        if (d->machineHandle != -1) {
            fn_1_435C(lbl_16_bss_14C);
            fn_1_426C(d->machineHandle);
            d->machineHandle = -1;
        }
        ent.value = lbl_1_bss_8B614;
        handles = d->entryHandle;
        for (i.value = 0; (s16)i.value < (s16)fn_1_12CB04(idx.value); i.value++) {
            fn_1_8F494(&ent.value[1].obj);
            if (*handles != -1) {
                fn_1_435C(lbl_16_bss_14C);
                fn_1_426C(*handles);
                *handles = -1;
            }
            ent.value++;
            handles++;
        }
        p->unk_58 = 0;
    }
    tb.value = (u32)d + 0x2B54;
    fn_1_48140(*(s32 *)(tb.value + p->unk_C * 4));
    e = &lbl_16_bss_220[p->unk_C];
    fn_1_80F1C((s16)e->unk_324, e);
}
#pragma opt_propagation reset

