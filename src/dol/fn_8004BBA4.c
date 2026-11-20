#include "types.h"


/* --- dol/fn_8004BBA4.c --- */
extern u32 fn_80047548(void);

void fn_8004BBA4(void) {
    fn_80047548();
}

/* --- dol/fn_8004BBC4.c --- */
/* --- dol/fn_8004BBC4.c --- */
// fn_8004BBC4: empty in retail (single blr).
void fn_8004BBC4(void) {
}

/* --- dol/fn_8004BBC8.c --- */
// fn_8004BBC8: empty in retail (single blr).
void fn_8004BBC8(void) {
}

/* --- dol/fn_8004BBCC.c --- */
extern char lbl_80090A28[45];
extern void fn_800474E4(void *arg);

typedef struct {
    u8 _pad[0x72];
    s8 value;
} Fn8004BBCCObject;

s32 fn_8004BBCC(Fn8004BBCCObject *object) {
    if (object == 0) {
        fn_800474E4(lbl_80090A28);
        return 0;
    }
    return object->value;
}
