#include "types.h"


/* --- dol/fn_80057B5C.c --- */
extern u32 memset(u32, u32, u32);

void fn_80057B5C(u32 arg0) {
    if (arg0 != 0) {
    memset(arg0, 0, 36);
    *(u32 *)((u8 *)arg0 + 4) = 0;
    }
}

/* --- dol/fn_80057B9C.c --- */
typedef struct {
    void *vtable;
    int active;
    void *type;
    void *link;
    int zero;
    void *arg0;
    void *arg1;
    void *callback;
    void *self;
} Fn80057B9CEntry;

extern u8 lbl_8018AE1C[1156];
extern u8 lbl_801322D0[48];
extern u8 lbl_800922E0[16];
extern void fn_80057D60(void);

Fn80057B9CEntry *fn_80057B9C(void *arg0, void *arg1) {
    Fn80057B9CEntry *entry;
    int count;

    for (count = 0; count < 32; count++) {
        if (((Fn80057B9CEntry *)lbl_8018AE1C)[count].active == 0) {
            break;
        }
    }
    if (count == 32) {
        return 0;
    }
    entry = &((Fn80057B9CEntry *)lbl_8018AE1C)[count];
    entry->active = 1;
    entry->vtable = lbl_801322D0;
    entry->arg0 = arg0;
    entry->arg1 = arg1;
    entry->type = lbl_800922E0;
    entry->callback = fn_80057D60;
    entry->self = entry;
    entry->link = entry->arg1;
    entry->zero = 0;
    return entry;
}
