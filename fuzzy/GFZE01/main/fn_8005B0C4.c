/* Non-matching: best partial attempt (95.72% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct AXNode AXNode;
typedef struct AXVtbl AXVtbl;

struct AXVtbl {
    s32 pad[5];
    void (*f5)(AXNode *);
};

struct AXNode {
    AXVtbl *vtbl;
};

typedef struct AXWork {
    s16 f0;
    s16 f1;
    s16 f2;
    s16 f3;
    s16 f4;
    s16 f5;
    s16 f6;
    s16 f7;
} AXWork;

typedef struct AXObj {
    u8 pad_0;
    u8 flags;
    s8 cnt_2;
    s8 cnt_3;
    s32 field_4;
    void *ptr[4];
    s32 val[2];
    s32 field_20;
    s32 pad_24[5];
    AXNode *node[8];
} AXObj;

extern void fn_8005A648(void);
extern void fn_80023284(void *, AXWork *, s32, s32, s32);
extern void fn_80023168(void *, s32);
extern void fn_8005A5BC(u32);
extern void fn_8005A628(void);
extern u8 lbl_800927D0[440];

void fn_8005B0C4(AXObj *obj, s32 mode) {
    s32 v;
    s32 i;
    if (obj == 0) {
        v = -1;
    } else {
        v = (obj->flags >> 1) & 1;
    }
    if (mode == v) {
        return;
    }
    fn_8005A648();
    if (mode == 1) {
        obj->field_4 = -1;
        for (i = 0; i < obj->cnt_3; i++) {
            if (obj->ptr[i] != 0) {
                s32 n = obj->field_20;
                s32 val = obj->val[i];
                s32 w = val + n - 1;
                AXWork work;
                work.f0 = 1;
                work.f1 = 10;
                work.f2 = val >> 16;
                work.f3 = val;
                work.f4 = w >> 16;
                work.f5 = w;
                work.f6 = val >> 16;
                work.f7 = val;
                fn_80023284(obj->ptr[i], &work, w >> 16, val, w);
                fn_80023168(obj->ptr[i], 1);
            }
        }
        obj->flags |= 2;
    } else if (mode == 0) {
        for (i = 0; i < obj->cnt_3; i++) {
            if (obj->ptr[i] != 0) {
                fn_80023168(obj->ptr[i], 0);
            }
        }
        for (i = 0; i < obj->cnt_2; i++) {
            AXNode *node = obj->node[i];
            node->vtbl->f5(node);
        }
        obj->flags &= 1;
    } else {
        fn_8005A5BC((u32)lbl_800927D0);
    }
    fn_8005A628();
}
