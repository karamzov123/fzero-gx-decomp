/* Non-matching: best partial attempt (87.57% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 unk_0;
    u32 unk_4;
    s16 unk_8;
    s16 unk_A;
    u8 unk_C;
    u8 pad_D[3];
    u32 unk_10;
    u32 unk_14;
} Obj_10_bss_0;

extern Obj_10_bss_0 lbl_10_bss_0;
extern u8 lbl_10_data_6FC[0x48];

extern void fn_10_1B658(void);
extern void fn_1_4A00(s32 value, u8 flag, u32 ptr);
extern void fn_1_435C(u32 value);
extern s32 fn_1_3F8C(const void *a, void (*b)(void), s32 c, s32 d);
extern void fn_1_12F1E8(s32 arg);

void fn_10_7320(void) {
    Obj_10_bss_0 *obj;
    u8 *base;

    obj = (Obj_10_bss_0 *)&lbl_10_bss_0;
    base = (u8 *)obj + 0x50000;
    fn_1_4A00(1, (u8)*(s16 *)(base - 0x6c74), *(u32 *)(base - 0x6c78));
    *(u32 *)(base + 0x1744) = 0;
    fn_1_435C(*(u32 *)(base - 0x6c78));
    *(u32 *)(base + 0x1740) = (u32)fn_1_3F8C(lbl_10_data_6FC, fn_10_1B658, 0, 8);
    fn_1_12F1E8(0x1e0);
    obj->unk_14 = -1;
}
