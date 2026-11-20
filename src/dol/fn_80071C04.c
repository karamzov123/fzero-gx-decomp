#include "types.h"


/* --- dol/fn_80071C04.c --- */
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

/* --- dol/fn_80071CB4.c --- */
extern u32 lbl_8019E210[];

u32 fn_80071CB4(void) {
    return (u32)&lbl_8019E210;
}

/* --- dol/fn_80071CC0.c --- */
extern u32 DVDOpen(void);

void fn_80071CC0(void) {
    DVDOpen();
}

/* --- dol/fn_80071CE0.c --- */
struct fn_80071CE0_Arg0 {
    u8 pad_0[0x34];
    u32 unk_34;
};

u32 fn_80071CE0(struct fn_80071CE0_Arg0 *arg0) {
    return arg0->unk_34;
}

/* --- dol/fn_80071CE8.c --- */
/* --- dol/fn_80071CE8.c --- */
extern u32 DVDReadPrio(u32, u32, u32, u32, u32);

void fn_80071CE8(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    DVDReadPrio(arg0, arg1, arg2, arg3, 2);
}

/* --- dol/fn_80071D0C.c --- */
extern u32 DVDClose(void);

void fn_80071D0C(void) {
    DVDClose();
}

/* --- dol/fn_80071D2C.c --- */
// fn_80071D2C: empty in retail (single blr).
void fn_80071D2C(void) {
}
