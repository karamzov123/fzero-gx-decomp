/* Non-matching: best partial attempt (97.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieObject {
    u8 pad[0x5c];
    s32 active;
    s32 state;
} MovieObject;

extern void fn_12_341C0(void);
extern u32 *fn_12_38DBC(void);
extern void fn_12_34B64(void);
extern void fn_12_341BC(void);
extern void fn_8004EC14(void);

#pragma opt_propagation off
void fn_12_3A888(MovieObject *object) {
    s32 fzgx_value;
    u32 *global;
    s32 zero1;
    s32 one;
    s32 i;
    s32 zero2;

    fn_12_341C0();
    global = fn_12_38DBC();
    object->active = 1;
    global[9] = 1;
    fn_12_34B64();
    global = fn_12_38DBC();
    object->active = 0;
    global[9] = 0;
    fn_12_341BC();
    if (object->state == 1) {
        i = 0;
        one = 1;
        zero1 = i;
        zero2 = i;
        do {
            global = fn_12_38DBC();
            fzgx_value = one;
            object->active = fzgx_value;
            global[9] = one;
            fn_8004EC14();
            global = fn_12_38DBC();
            object->active = zero1;
            global[9] = zero2;
            if (object->state == 0) {
                break;
            }
            i++;
        } while (i < 10);
    }
}
