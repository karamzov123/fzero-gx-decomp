/* Non-matching: best partial attempt (98.84% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"

extern void fn_1_14E2DC(void *value);
extern u8 lbl_1_rodata_3968[232];
extern u32 lbl_1_bss_6D82C[3];
extern void fn_1_8E450(void *object);
extern u8 lbl_1_data_1F5A0[164];
extern void fn_1_87610(void *object, void *value);
extern void fn_1_875B4(void *object, void *value, s8 mode, f32 amount);
extern void fn_1_87238(void *object, s8 mode, f32 amount);
extern void fn_1_8E480(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DB30(void);
extern void fn_800713E0(void *value);
extern void fn_800712E4(void *object, u32 value, void *data);

typedef struct Fn1870BCObject {
    u8 pad_000[0x328];
    s8 field_328;
    u8 pad_329[0xF];
    void *field_338;
    u8 pad_33C[0x40];
    void *field_37C[5];
    u32 field_390;
    u8 pad_394[0xC];
    void *field_3A0;
    u8 pad_3A4[0x14];
    s16 field_3B8;
    s16 field_3BA;
} Fn1870BCObject;

typedef void (*Fn1870BCLookup)(Fn1870BCObject *object);

typedef struct Fn1870BCBlob {
    u8 bytes[232];
} Fn1870BCBlob;

static inline void * fn_1_870BC_array_read(void * *array, s32 index) { return array[index]; }
#pragma opt_propagation on
#pragma opt_lifetimes off
void fn_1_870BC(Fn1870BCObject *object, s8 mode, void *value, s16 enabled, s32 index, f32 amount) {
    Fn1870BCBlob data;
    f32 lab_t2;

    object->field_3BA = mode;
    if ((object->field_390 & 0x04000000) != 0) {
        fn_1_14E2DC(object->field_3A0);
        return;
    }

    if (object->field_3B8 != (u8)index) {
        void *entry = fn_1_870BC_array_read(object->field_37C, (u8)index % 4);
        if (entry != 0) {
            Fn1870BCObject *mode_object =
                (Fn1870BCObject *)((u8 *)object + (s32)mode * 12);
{
    void * fzgx_live;
            fzgx_live = mode_object->field_338;
            fn_800713E0(fzgx_live);
}
            {
                void *handle = mode_object->field_338;
                data = *(Fn1870BCBlob *)lbl_1_rodata_3968;
                fn_800712E4(handle, ((0)[lbl_1_bss_6D82C]), &data);
            }
        }
        object->field_3B8 = (u8)index;
    }

    lbl_8006DAEC();
    fn_1_8E450(object);

    if (enabled != 0) {
        Fn1870BCLookup callback =
            ((Fn1870BCLookup *)lbl_1_data_1F5A0)[object->field_328];
        callback(object);
    } else {
        fn_1_87610(object, value);
    }

    fn_1_875B4(object, value, mode, amount);
    lbl_8006DBE4();
    lab_t2 = amount;
    fn_1_87238(object, mode, lab_t2);
    fn_1_8E480();
    lbl_8006DB30();
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset

