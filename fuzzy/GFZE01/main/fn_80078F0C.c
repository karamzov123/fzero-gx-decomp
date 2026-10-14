/* Non-matching: best partial attempt (98.46% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct Sig_fn_80071C04_Entry { u32 pad00; u32 data; } Sig_fn_80071C04_Entry;
typedef struct Sig_fn_80071C04_Object { u32 flags; u16 index; u16 pad06; u32 value; u8 pad0C[0x14]; } Sig_fn_80071C04_Object;
extern u8 lbl_8015AD38[];
extern void OSPanic(const char *, int, const char *, ...);
extern void OSReport(const char *, ...);
extern u32 fn_80071794(u32);
extern void fn_80071C04(Sig_fn_80071C04_Object *, Sig_fn_80071C04_Entry *);

typedef struct Model {
    u32 unk0;
    u32 flags;
    u8 pad08[0x10];
    u16 count;
    u16 n1A;
    u16 n1C;
    u16 pad1E;
    u32 meshOfs;
    u32 buf;
} Model;

u32 fn_80078F0C(Model *arg0, Sig_fn_80071C04_Entry *arg1, u32 arg2, u32 arg3) {
    s32 v8;
    Sig_fn_80071C04_Object *child;
    u8 *p_lbl_8015AD38;
    struct { s32 value; } v2;
    Sig_fn_80071C04_Object *v4;
    s32 v3;
    s32 v5;
    s32 v1;
    s32 v14;
    u32 v15;
    u32 v11;
    u32 v16;
    u32 v18;
    s32 j;
    const char * lab_t0;
    child = (Sig_fn_80071C04_Object *)((u8 *)arg0 + 0x40);
    p_lbl_8015AD38 = (u8 *)&lbl_8015AD38;
    v2.value = 0;
    if (arg1 == 0) {
        v5 = arg0->count;
        v4 = child;
        v1 = 0;
        for (v3 = 0; v3 < v5; v3++) {
            if (v4->flags & 0x200000) v1++;
            v4++;
        }
        if (v1 != v5) {
            v2.value = 1;
            arg0->count = 0;
        }
    }
    if (arg0->count != 0) {
        if (arg2 != 0) {
            arg0->buf = arg2;
            arg2 += arg0->count << 5;
        } else {
            arg0->buf = fn_80071794(arg0->count * 0x20U);
        }
        if (arg0->buf == 0) {
            lab_t0 = (const char *)(p_lbl_8015AD38 + 164);
            OSReport(lab_t0, arg3);
            OSPanic((const char *)(p_lbl_8015AD38 + 176), 2411, (const char *)(p_lbl_8015AD38 + 188));
        }
    } else {
        arg0->buf = 0;
    }
    v8 = 0;
    while (v8 < arg0->count) {
        child->value = arg0->buf + v8 * 32;
        fn_80071C04(child, arg1);
        if ((child->flags & 0x200000) == 0 && child->value == 0)
            OSReport((const char *)(p_lbl_8015AD38 + 216), arg3, child->index);
        child++;
        v8++;
    }
    v11 = arg0->flags;
    v15 = (u32)arg0 + arg0->meshOfs;
    if (v11 & 0x18) {
        *(u32 *)(v15 + 28) = v11;
        v15 += 32;
    }
    v14 = 0;
    while (v14 < arg0->n1A + arg0->n1C) {
        if (v2.value) *(u8 *)(v15 + 18) = 0;
        if (arg0->flags & 0x18) {
            v16 = v15;
            v15 += 96;
            if (*(u32 *)(v16 + 28) & 0x800) *(u32 *)v16 |= 256;
            if (*(u8 *)(v16 + 18) == 0) *(u32 *)v16 |= 128;
        } else {
            if (*(u32 *)(v15 + 28) & 0x800) *(u32 *)v15 |= 256;
            if (*(u8 *)(v15 + 18) == 0) *(u32 *)v15 |= 128;
            v18 = v15 + 96;
            for (j = 0; j < 2; j++) {
                if (*(u8 *)(v15 + 19) & (1 << j))
                    v18 += *(u32 *)(v15 + 40 + j * 4);
            }
            if (*(u8 *)(v15 + 19) & 0xC) {
                u32 b;
                u32 a;
                a = *(u32 *)(v18 + 8);
                b = *(u32 *)(v18 + 12);
                v18 += 32;
                v18 += a;
                v18 += b;
            }
            v15 = v18;
        }
        v14++;
    }
    return arg2;
}
