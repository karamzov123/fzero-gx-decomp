#include "types.h"

extern char lbl_80123F28[52];
extern char lbl_801A6470[8];
extern void OSPanic(char *, int, char *, ...);
extern void fn_80017590(void);
extern void DVDReadAbsAsyncPrio(void *, int, int, u32, void (*)(void), void *);

typedef struct Fn800174D0Object {
    u8 pad30[0x30];
    u32 field30;
    u32 field34;
    void *field38;
} Fn800174D0Object;

int DVDReadAsyncPrio(Fn800174D0Object *obj, int arg1, int arg2, int index,
               void (*arg4)(void), void *arg5) {
    if (index < 0 || (u32)index >= obj->field34) {
        OSPanic(lbl_801A6470, 0x2e6, lbl_80123F28);
    }
    if (index + arg2 < 0 || (u32)(index + arg2) >= obj->field34 + 0x20) {
        OSPanic(lbl_801A6470, 0x2ec, lbl_80123F28);
    }
    obj->field38 = (void *)arg4;
    DVDReadAbsAsyncPrio(obj, arg1, arg2, obj->field30 + index, fn_80017590, arg5);
    return 1;
}
