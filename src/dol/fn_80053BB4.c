#include "types.h"


/* --- dol/fn_80053BB4.c --- */
/* --- dol/fn_80053BB4.c --- */
extern u32 lbl_80187370[4];
extern u32 lbl_80187380[16];
extern void *memset(void *dest, int value, u32 size);

void fn_80053BB4(void) {
    u32 *counter = lbl_80187370;
    *counter -= 1;
    if (*counter == 0) {
        memset(lbl_80187380, 0, 0x40);
    }
}

/* --- dol/fn_80053BFC.c --- */
typedef struct AdxtGlobal {
    s32 ref_count;
    s32 initialized;
    f32* table1;
    void* table2;
} AdxtGlobal;

extern u32 lbl_80187370[];
extern u8 lbl_801319E0[];
extern const f32 lbl_80091350[];
extern u8 lbl_8012B938[];

void fn_80053BFC(void)
{
    AdxtGlobal* g = (AdxtGlobal*)lbl_80187370;

    if (g->ref_count == 0) {
        memset((char*)g + 0x10, 0, 0x40);
        if (g->initialized == 0) {
            char* src1 = (char*)lbl_801319E0 + 0x800;
            char* dst1;
            long n;
            char* src2;
            char* dst2;

            g->table1 = (float*)(((unsigned int)lbl_801319E0 + 0x1F) & ~0x1F);
            dst1 = (char*)g->table1 + 0x800;

            for (n = 0x2AB; n > 0; n--) {
                *dst1 = *src1;
                *(dst1 - 1) = *(src1 - 1);
                *(dst1 - 2) = *(src1 - 2);
                src1 -= 3;
                dst1 -= 3;
            }

            for (n = 0; n < 0x200; n++) {
                g->table1[n] *= lbl_80091350[0];
            }

            src2 = (char*)lbl_8012B938 + 0x2000;
            g->table2 = (void*)(((unsigned int)lbl_8012B938 + 0x1F) & ~0x1F);
            dst2 = (char*)g->table2 + 0x2000;

            for (n = 0xAAB; n > 0; n--) {
                *dst2 = *src2;
                *(dst2 - 1) = *(src2 - 1);
                *(dst2 - 2) = *(src2 - 2);
                src2 -= 3;
                dst2 -= 3;
            }

            g->initialized = 1;
        }
    }
    g->ref_count++;
}

/* --- dol/fn_80053DB4.c --- */
struct fn_80053DB4_Arg0 {
    u8 pad_0[0xC];
    void *unk_C;
    void *unk_10;
};

extern u32 fn_80053A30(void);
extern void fn_80051F38(u32, void *, void *);
extern u32 lbl_801873C0[6];
extern void (*lbl_80130BC0[16])(void *, void *, void *);

void fn_80053DB4(struct fn_80053DB4_Arg0 *obj, u32 arg1, u32 ch, void *arg3) {
    u32 *p;
    u8 *buf;
    s32 idx;
    void *unkC;
    void *addr;

    p = (u32 *)((u8 *)obj + (ch << 2));
    buf = (u8 *)obj + (ch << 12);
    p[1] = ((*((1) + (p))) - 0x40) & 0x3FF;
    idx = (*((1) + (p)));
    unkC = obj->unk_C;
    addr = buf + 0x14 + (idx << 2);
    lbl_801873C0[0] = fn_80053A30();
    if (((arg1 & 0x1F) != 0) || (((u32)unkC & 0x1F) != 0)) {
        while (1) {
        }
    }
    fn_80051F38(arg1, unkC, addr);
    lbl_801873C0[4] = fn_80053A30();
    idx = (*((1) + (p)));
    lbl_801873C0[0] = fn_80053A30();
    (*((idx >> 6) + (lbl_80130BC0)))((u8 *)((u32 *)(buf + 0x14) + idx), obj->unk_10, arg3);
    lbl_801873C0[4] = fn_80053A30();
}

/* --- dol/fn_80053EA0.c --- */
/* --- dol/fn_80053EA0.c --- */
/* --- dol/fn_80053EA0.c --- */
struct fn_80053EA0_Arg0 {
    u8 pad_0[0x1C];
    u32 unk_1C;
};

u32 fn_80053EA0(struct fn_80053EA0_Arg0 *arg0) {
    return arg0->unk_1C;
}

/* --- dol/fn_80053EA8.c --- */
struct fn_80053EA8_Arg0 {
    u8 pad_0[0x20];
    u32 unk_20;
};

u32 fn_80053EA8(struct fn_80053EA8_Arg0 *arg0) {
    return arg0->unk_20;
}

/* --- dol/fn_80053EB0.c --- */
typedef u32 (*fn_80053EB0_Fn0)(u32, u32);
struct fn_80053EB0_Arg0 {
    u8 pad_0[0x5];
    u8 unk_5;
};

extern u32 fn_800510D8(u32);
extern u32 fn_80051448(u32);
extern u32 fn_80053F38(void);

void fn_80053EB0(struct fn_80053EB0_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    u32 t0, t1, t2, t3;
    v0 = (u32)arg0;
    if ((s8)arg0->unk_5 == 2) {
    t0 = fn_80053F38();
    v0 = t0;
    } else {
    if ((s8)arg0->unk_5 == 1) {
    v0 = *(u32 *)((u8 *)(u32)arg0 + 12);
    v1 = *(u32 *)((u8 *)v0 + 0);
    t1 = ((fn_80053EB0_Fn0)*(u32 *)((u8 *)v1 + 36))(v0, 1);
    v0 = t1;
    if ((s32)v0 >= 36) {
    v0 = *(u32 *)((u8 *)(u32)arg0 + 0);
    t2 = fn_80051448(v0);
    v0 = t2;
    v0 = *(u32 *)((u8 *)(u32)arg0 + 0);
    t3 = fn_800510D8(v0);
    v0 = t3;
    v0 = 1;
    *(u8 *)((u8 *)(u32)arg0 + 7) = v0;
    *(u8 *)((u8 *)(u32)arg0 + 5) = 2;
    }
    }
    }
}
