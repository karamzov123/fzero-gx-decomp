/* Non-matching: best partial attempt (97.24% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Fn12_3A69C_Object {
    u8 _pad0[0x04];
    s32 value;
    u8 _pad8[0x38];
    void *data;
} Fn12_3A69C_Object;

typedef struct Fn12_3A69C_Result {
    u8 _pad0[0x04];
    s32 start;
    u8 _pad8[0x08];
    s32 end;
    u8 _pad14[0x2c];
} Fn12_3A69C_Result;

extern char lbl_12_rodata_2718[304];
extern void MWSFSVM_Error(const char *format, ...);
extern void fn_12_2D58C(void *data, Fn12_3A69C_Result *result);
extern s32 fn_12_33874(Fn12_3A69C_Object *object);

#pragma opt_propagation off
s32 fn_12_3A69C(Fn12_3A69C_Object *object) {
    struct Messages { char first[0x100]; char second[0x30]; char third[1]; };
    struct Messages *msg = (struct Messages *)lbl_12_rodata_2718;
    s32 value;
    Fn12_3A69C_Result result;
    void *data;
    s32 diff;

    if (object == 0) {
        value = 0;
    } else {
        value = object->value;
    }
    if (value == 0) {
        MWSFSVM_Error(msg->second);
        return 0;
    }
    if (object == 0) {
        value = 0;
    } else {
        value = object->value;
    }
    if (value == 0) {
        MWSFSVM_Error(msg->third);
        diff = 0;
    } else {
        if (object == 0) {
            value = 0;
        } else {
            value = object->value;
        }
        if (value == 0) {
            MWSFSVM_Error(lbl_12_rodata_2718);
            data = 0;
        } else {
            data = object->data;
        }
        fn_12_2D58C(data, &result);
        diff = result.start - result.end;
    }
    return diff + fn_12_33874(object);
}
