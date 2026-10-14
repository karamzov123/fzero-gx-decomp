/* Non-matching: best partial attempt (97.97% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_12_rodata_15D0[];
extern void MWSFSVM_Error(const char *, ...);
typedef struct Sig_fn_12_339B4_MovieOutput {
    u32 field_00;
    u32 field_04;
    u32 field_08;
    u32 field_0C;
    u32 field_10;
    u32 field_14;
} Sig_fn_12_339B4_MovieOutput;
extern void fn_12_339B4(u32, u32, u32, Sig_fn_12_339B4_MovieOutput *);
struct Sig_fn_12_7E8_fn_12_7E8_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};
struct Sig_fn_12_7E8_fn_12_7E8_Arg1 { u32 unk_0; };
struct Sig_fn_12_7E8_fn_12_7E8_Arg2 { u32 unk_0; };
extern u32 fn_12_7E8(struct Sig_fn_12_7E8_fn_12_7E8_Arg0 *, struct Sig_fn_12_7E8_fn_12_7E8_Arg1 *, struct Sig_fn_12_7E8_fn_12_7E8_Arg2 *);

#pragma opt_propagation off
void fn_12_35B08(u32 input0, u32 arg1, u32 input2) {
    u32 arg2 = input2;
    u32 arg0 = input0;
    struct { u8 *value; } text;
    u8 *p_lbl_12_rodata_15D0;
    u32 v0;
    u32 width;
    u32 height;
    s32 mode;
    Sig_fn_12_339B4_MovieOutput planes;
    struct Sig_fn_12_7E8_fn_12_7E8_Arg2 b;
    struct Sig_fn_12_7E8_fn_12_7E8_Arg1 a;
    text.value = (u8 *)&lbl_12_rodata_15D0;
    p_lbl_12_rodata_15D0 = text.value;
    v0 = *(u32 *)((u8 *)arg1 + 4);
    switch ((s32)v0) {
    case 1: v0 = 1; break;
    case 2: v0 = 2; break;
    case 3: v0 = 3; break;
    default:
    MWSFSVM_Error((const char *)(p_lbl_12_rodata_15D0 + 0x790));
    v0 = 3;
    break;
    }
    *(u32 *)arg2 = v0;
    width = *(u32 *)((u8 *)arg1 + 8);
    height = *(u32 *)((u8 *)arg1 + 12);
    *(u32 *)((u8 *)arg2 + 0x44) = width;
    *(u32 *)((u8 *)arg2 + 0x48) = height;
    if (*(s32 *)((u8 *)arg1 + 4) != 3) {
    *(u32 *)((u8 *)arg2 + 4) = *(u32 *)arg1;
    *(u32 *)((u8 *)arg2 + 8) = width;
    *(u32 *)((u8 *)arg2 + 12) = height;
    } else {
    fn_12_339B4(*(u32 *)arg1, width, height, &planes);
    width = planes.field_0C;
    *(u32 *)((u8 *)arg2 + 4) = planes.field_00;
    *(u32 *)((u8 *)arg2 + 8) = width;
    *(u32 *)((u8 *)arg2 + 12) = height;
    v0 = planes.field_04;
    width = planes.field_10;
    *(u32 *)((u8 *)arg2 + 0x14) = v0;
    *(u32 *)((u8 *)arg2 + 0x18) = width;
    *(u32 *)((u8 *)arg2 + 0x1c) = height;
    width = planes.field_14;
    *(u32 *)((u8 *)arg2 + 0x24) = planes.field_08;
    *(u32 *)((u8 *)arg2 + 0x28) = width;
    *(u32 *)((u8 *)arg2 + 0x2c) = height;
    }
    *(u32 *)((u8 *)arg2 + 0x4c) = *(u32 *)((u8 *)arg1 + 0x30);
    fn_12_7E8(*(struct Sig_fn_12_7E8_fn_12_7E8_Arg0 **)((u8 *)arg0 + 0xa8), &a, &b);
    *(u32 *)((u8 *)arg2 + 0x50) = a.unk_0;
    *(u32 *)((u8 *)arg2 + 0x54) = b.unk_0;
    *(u32 *)((u8 *)arg2 + 0x58) = 0;
    *(u32 *)((u8 *)arg2 + 0x5c) = 0;
    mode = 3;
    switch (*(s32 *)((u8 *)arg0 + 0x88)) {
    case 1: mode = 1; break;
    case 2: mode = 2; break;
    case 3: break;
    default: MWSFSVM_Error((const char *)(p_lbl_12_rodata_15D0 + 0x768)); break;
    }
    *(u32 *)((u8 *)arg2 + 0x60) = mode;
    mode = 1;
    switch (*(s32 *)((u8 *)arg0 + 0x8c)) {
    case 1: mode = 1; break;
    case 2: mode = 2; break;
    case 3: mode = 3; break;
    default: MWSFSVM_Error((const char *)(p_lbl_12_rodata_15D0 + 0x744)); break;
    }
    *(u32 *)((u8 *)arg2 + 0x64) = mode;
    *(u32 *)((u8 *)arg2 + 0x68) = *(u32 *)((u8 *)arg0 + 0x90);
    *(u32 *)((u8 *)arg2 + 0x6c) = *(u32 *)((u8 *)arg0 + 0x94);
    *(u32 *)((u8 *)arg2 + 0x70) = *(u32 *)((u8 *)arg0 + 0x98);
    mode = 1;
    switch (*(s32 *)((u8 *)arg0 + 0x9c)) {
    case 0: mode = 0; break;
    case 1: mode = 1; break;
    default: MWSFSVM_Error((const char *)(p_lbl_12_rodata_15D0 + 0x724)); break;
    }
    *(u32 *)((u8 *)arg2 + 0x74) = mode;
    mode = 1;
    switch (*(s32 *)((u8 *)arg0 + 0xa0)) {
    case 0: mode = 0; break;
    case 1: mode = 1; break;
    default: MWSFSVM_Error((const char *)(p_lbl_12_rodata_15D0 + 0x724)); break;
    }
    *(u32 *)((u8 *)arg2 + 0x78) = mode;
}
