/* Non-matching: best partial attempt (95.36% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"

extern void fn_800793D4(void *dst, int value, int size);
extern void fn_1_8B9B8(void *arg);

typedef struct {
    s8 unk_0[0x18];
    void *unk_18;
    u8 unk_1c[0x200];
    u8 array_21c[0x20];
    u8 array_23c[0x1a];
    u8 unk_256[4];
    u8 flags_25a[4];
    u8 unk_25e[2];
    u8 unk_260[0x6e0];
    u8 unk_940[0x6cc];
} CarInitData;

extern u8 lbl_1_bss_6D820;

#pragma opt_propagation off
static inline void * fn_1_8B8A4_read_pointer(CarInitData * owner) { return owner->unk_18; }
void fn_1_8B8A4(void *arg) {
    CarInitData * data = (CarInitData *)&lbl_1_bss_6D820;
    u8 * p23c;
    u8 * p21c = data->array_21c;
    int i;
    void *obj;
    p23c = data->array_23c;

    for (i = 0; i < 30; i++) {
        *p23c++ = i;
        *p21c++ = i;
    }

    fn_800793D4(data->unk_260, 0, 0x6cc);
    fn_800793D4(data->unk_940, 0, 0x6cc);

    obj = fn_1_8B8A4_read_pointer(data);
    data->flags_25a[2] = 0;
    data->flags_25a[3] = 0;
    data->flags_25a[0] = 1;
    data->flags_25a[1] = 1;
    if (((0) != (obj)) && *(void **)((u8 *)obj + 0x49c) != 0) {
        data->flags_25a[0] = *((u8 *)*(void **)((u8 *)obj + 0x49c) + 0x115);
        (*((data->flags_25a) + (1))) = *((u8 *)*(void **)((u8 *)obj + 0x49c) + 0x115);
    }

    fn_1_8B9B8(arg);
}
#pragma opt_propagation reset

