#include "types.h"

typedef void (*fn_8005B464_Fn0)(void *);

typedef struct fn_8005B464_Vtbl {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    fn_8005B464_Fn0 fn0;
} fn_8005B464_Vtbl;

typedef struct fn_8005B464_Node {
    fn_8005B464_Vtbl *vtable;
} fn_8005B464_Node;

typedef struct fn_8005B464_Obj {
    u8 unk0[2];
    s8 count;
    u8 unk3;
    u32 unk4;
    u32 field8;
    u32 unkC;
    u32 field10;
    u32 unk14[9];
    fn_8005B464_Node *field38;
} fn_8005B464_Obj;

extern u32 AXRNA_SetPlaySw(u32, u32);
extern u32 AXRNA_SetTransSw(u32, u32);
extern u32 fn_8005BE98(u32);
extern u32 memset(u32, u32, u32);
extern void fn_80020ABC(u32);
extern void fn_80026D70(void *);
extern void fn_8005A628(void);
extern void fn_8005A648(void);

void AXRNA_Destroy(u32 arg0) {
    fn_8005B464_Obj *p;
    s32 i;

    if (arg0 != 0) {
        AXRNA_SetPlaySw(arg0, 0);
        AXRNA_SetTransSw(arg0, 0);
        p = (fn_8005B464_Obj *)arg0;
        i = 0;
        while (i < ((fn_8005B464_Obj *)arg0)->count) {
            if (p->field38 != 0) {
                p->field38->vtable->fn0(p->field38);
            }
            if (p->field10 != 0) {
                fn_8005BE98(p->field10);
            }
            fn_8005A648();
            if (p->field8 != 0) {
                fn_80026D70((void *)p->field8);
                fn_80020ABC(p->field8);
            }
            fn_8005A628();
            p = (fn_8005B464_Obj *)((u8 *)p + 4);
            i++;
        }
        memset(arg0, 0, 232);
    }
}
