/* Non-matching: best partial attempt (88.52% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern const f32 lbl_1_rodata_42E0;
extern const f32 lbl_1_rodata_42E4;
extern const f32 lbl_1_rodata_42E8;

typedef struct Sig_ADXT_Stop_ADXTHandle Sig_ADXT_Stop_ADXTHandle;
extern void fn_8004D18C(Sig_ADXT_Stop_ADXTHandle *handle, const char *name);
extern u32 fn_8004BF0C(Sig_ADXT_Stop_ADXTHandle *handle, u32 value);

extern s16 lbl_1_data_2D93C[];
extern const char *lbl_1_data_2D7B8[];

typedef struct {
    u8 pad_0[0x1C];
    u32 unk_1C;
    u8 pad_20[4];
    f32 unk_24;
    f32 unk_28;
    u8 unk_2C;
    u8 pad_2D[0xB];
    u32 *unk_38;
    u8 pad_3C[0x846];
    u8 unk_882;
    u8 pad_883;
    s16 unk_884;
    s16 unk_886;
    f32 unk_888;
    f32 unk_88C;
} Obj_1_bss_6EA98;

extern Obj_1_bss_6EA98 lbl_1_bss_6EA98;

#pragma opt_common_subs off
static inline u32 * fn_1_A1588_read_pointer(Obj_1_bss_6EA98 * owner) { return owner->unk_38; }
#pragma opt_lifetimes on
static inline const char * fn_1_A1588_array_read(const char * *array, s32 index) { return array[index]; }
void fn_1_A1588(Sig_ADXT_Stop_ADXTHandle *handle, u8 channel) {
    f32 *fzgx_value;
    Obj_1_bss_6EA98 *obj = &lbl_1_bss_6EA98;
    u32 flags;
    u16 flags_2;

    if (!(obj->unk_882 == 0 && handle != 0 && (u32)handle + 1 != 0xFFFF)) {
        return;
    } else {
        u32 *ids = fn_1_A1588_read_pointer(obj);

        if ((u32)handle == ids[0]) {
            flags = obj->unk_1C;
            obj->unk_1C = flags & 0x70000000;
            if (flags & 0x80000000) {
                obj->unk_884 = lbl_1_data_2D93C[(u64)channel];
            } else {
                obj->unk_24 = lbl_1_rodata_42E0;
                obj->unk_888 = lbl_1_data_2D93C[(u64)channel];
            }
        }

        if ((u32)handle == ids[1]) {
            flags = obj->unk_1C;
            obj->unk_1C = flags & 0x38000000;
            if (flags & 0x40000000) {
                obj->unk_886 = lbl_1_data_2D93C[(u64)channel];
            } else {
                obj->unk_28 = lbl_1_rodata_42E4;
                obj->unk_88C = lbl_1_data_2D93C[(u64)channel];
            }
        }

        {
            u32 ch = (u8)channel;

            fn_8004D18C(handle, fn_1_A1588_array_read(lbl_1_data_2D7B8, (u64)channel));

            flags_2 = obj->unk_1C;
            if (flags_2 & 0x20000000) {
                if (flags_2 & 0x80000000) {
                    obj->unk_888 = lbl_1_rodata_42E8;
                }
                if (flags_2 & 0x40000000) {
                    fzgx_value = &(obj->unk_88C);
                    *fzgx_value = lbl_1_rodata_42E8;
                }
                fn_8004BF0C(handle, -400);
            } else {
                fn_8004BF0C(handle, lbl_1_data_2D93C[ch]);
            }
        }

        obj->unk_2C = (u8)channel;
    }
}
#pragma opt_lifetimes reset

#pragma opt_common_subs reset

