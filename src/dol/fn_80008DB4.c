#include "types.h"

typedef struct Fn80008DB4Value {
    u8 data[0x10];
} Fn80008DB4Value;

extern void lbl_8006DBAC(void *value);
extern void fn_8006E5FC(Fn80008DB4Value *value);
extern void fn_8006EB4C(Fn80008DB4Value *out, Fn80008DB4Value *a, Fn80008DB4Value *b, f32 amount);
extern void PSMTXQuat(void *value, Fn80008DB4Value *transform);

void fn_80008DB4(void *first, f32 amount, void *second, void *out) {
    Fn80008DB4Value a;
    Fn80008DB4Value b;

    lbl_8006DBAC(first);
    fn_8006E5FC(&a);
    lbl_8006DBAC(second);
    fn_8006E5FC(&b);
{
    Fn80008DB4Value result;
    fn_8006EB4C(&result, &a, &b, amount);
    PSMTXQuat(out, &result);
}
}
