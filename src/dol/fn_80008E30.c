#include "types.h"


/* --- dol/fn_80008DB4.c --- */
typedef struct Fn80008DB4Value {
    u8 data[0x10];
} Fn80008DB4Value;

extern void lbl_8006DBAC(void *value);
extern void fn_8006E5FC(Fn80008DB4Value *value);
extern void fn_8006EB4C(Fn80008DB4Value *out, Fn80008DB4Value *a, Fn80008DB4Value *b, f32 amount);
extern void PSMTXQuat(void *value, Fn80008DB4Value *transform);

void fn_80008DB4(void *first, f32 amount, void *second, void *out);

/* --- dol/fn_80008E30.c --- */
// fn_80008E30: empty in retail (single blr).
void fn_80008E30(void) {
}
