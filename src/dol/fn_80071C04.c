#include "types.h"


/* --- dol/fn_80071C04.c --- */
typedef struct Object {
    u32 flags;
    u16 index;
    u16 pad06;
    u32 value;
} Object;

typedef struct Entry {
    u32 pad00;
    u32 data;
} Entry;

extern void fn_800718BC(Object *, void *, Entry *);

void fn_80071C04(Object *obj, Entry *entry) {
    if (obj->flags & 0x00200000) {
        obj->value = 0;
    } else if (entry == 0) {
        obj->value = 0;
    } else {
        fn_800718BC(obj, (u8 *)entry->data + obj->index * 16, entry);
    }
}

/* --- dol/fn_80071C64.c --- */
extern u32 fn_80008E34(u32, u32);
extern u32 lbl_801A6410;

void fn_80071C64(u32 arg0) {
    fn_80008E34(lbl_801A6410, arg0);
}

/* --- dol/fn_80071C8C.c --- */
extern u32 fn_80008E5C(u32, u32);

void fn_80071C8C(u32 arg0) {
    fn_80008E5C(lbl_801A6410, arg0);
}
