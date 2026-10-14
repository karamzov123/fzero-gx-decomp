/* Non-matching: best partial attempt (98.21% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
struct fn_80025D5C_Obj {
 void *unk0; u32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14; s32 unk18; s32 unk1C;
 s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34;
 u16 unk38,unk3A,unk3C,unk3E,unk40,unk42,unk44,unk46,unk48,unk4A,unk4C,unk4E,unk50,unk52,unk54,unk56,unk58,unk5A,unk5C;
};
struct fn_80025EF4_lbl_80128990 { u8 pad_0[0x710]; u16 unk_710[512]; };
struct fn_80025EF4_Arg0 { u8 pad_0[0x18]; u32 unk_18; };
extern struct fn_80025EF4_lbl_80128990 lbl_80128990;
extern u8 lbl_80176160[];
extern u32 lbl_801A6B88[2];
extern void fn_80025D5C(struct fn_80025D5C_Obj *);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
static inline u16 fn_80025EF4_attn(s32 v, struct fn_80025EF4_lbl_80128990 *tbl) { return v <= -0x388 ? 0 : (v >= 0x3C ? 0xFF64 : tbl->unk_710[v]); }
#define ATTN(v) fn_80025EF4_attn((v), tbl)
static inline void fn_80025EF4_store(void *destination, u32 value) { *(s32 *)destination = value; }
#pragma opt_propagation off
static inline void fn_80025EF4_store_(s32 *destination, s32 value) { *destination = value; }
#pragma opt_propagation reset

#pragma opt_dead_assignments off
static inline void fn_80025EF4_call_fn_80025D5C(struct fn_80025EF4_lbl_80128990 **tbl, struct fn_80025D5C_Obj * a0) { fn_80025D5C(a0); }
#pragma opt_dead_assignments reset
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
void fn_80025EF4(struct fn_80025EF4_Arg0 *arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5, u32 arg6, u32 arg7) {
 u32 fzgx_frame_pad[42];
 u16 fzgx_value;
 struct fn_80025EF4_lbl_80128990 *tbl;
 struct fn_80025D5C_Obj *entry;
 u32 v_2;
 s16 flags;
 u32 v;
 u32 lab_t0;
 tbl = &lbl_80128990;
 entry = (struct fn_80025D5C_Obj *)((u8 *)lbl_80176160 + arg0->unk_18 * 0x60);
 entry->unk0 = arg0;
 entry->unk4 = arg1 & 7;
 entry->unk8 = arg2;
 fn_80025EF4_store_(&entry->unkC, arg3);
 entry->unk10 = arg4;
 entry->unk14 = arg5;
 fn_80025EF4_store(&entry->unk18, arg6);
 entry->unk1C = arg7;
 fn_80025EF4_call_fn_80025D5C(&tbl, entry);
 if (entry->unk4 & 4) entry->unk38 = 0;
 else entry->unk38 = ATTN(arg2);
 flags = 0;
 switch (lbl_801A6B88[0]) {
 case 0:
 entry->unk3C = ATTN(entry->unk1C + entry->unk28);
 entry->unk40 = ATTN(entry->unk1C + entry->unk28);
 { s32 t = entry->unk2C; t -= 0x1E; t = entry->unk1C + t; entry->unk44 = ATTN(t); }
 if (entry->unk4 & 1) {
 entry->unk48 = ATTN(entry->unkC + entry->unk28);
 entry->unk4C = ATTN(entry->unkC + entry->unk28);
 { s32 t = entry->unk2C; t -= 0x1E; t = ((((entry->unkC)) + ((t)))); entry->unk50 = ATTN(t); }
 } else {
 entry->unk48 = ATTN(entry->unk28 + (entry->unk1C + entry->unkC));
 entry->unk4C = ATTN(entry->unk28 + (entry->unk1C + entry->unkC));
 { s32 t = entry->unk2C; s32 u; t = ((t) + (entry->unkC)); t -= 0x1E; u = ((t) + (entry->unk1C)); entry->unk50 = ATTN(u); }
 }
 if (entry->unk4 & 2) {
 entry->unk54 = ATTN(entry->unk10 + entry->unk28);
 entry->unk58 = ATTN(entry->unk10 + entry->unk28);
 { s32 t = entry->unk2C; t -= 0x1E; t = entry->unk10 + t; entry->unk5C = ATTN(t); }
 } else {
 entry->unk54 = ATTN(entry->unk28 + (entry->unk1C + entry->unk10));
 entry->unk58 = ATTN(entry->unk28 + (entry->unk1C + entry->unk10));
 { s32 t = entry->unk2C; s32 u; t = ((t) + (entry->unk10)); t -= 0x1E; u = ((t) + (entry->unk1C)); entry->unk5C = ATTN(u); }
 }
 break;
 case 1:
 case 2:
 entry->unk3C = ATTN(entry->unk28 + (entry->unk1C + entry->unk20));
 entry->unk40 = ATTN(entry->unk28 + (entry->unk1C + entry->unk24));
 { s32 t = entry->unk2C; t -= 0x1E; t = ((entry->unk1C) + (t)); entry->unk44 = ATTN(t); }
 if (entry->unk4 & 1) {
 entry->unk48 = ATTN(entry->unk28 + (entry->unkC + entry->unk20));
 entry->unk4C = ATTN(entry->unk28 + (entry->unkC + entry->unk24));
 { s32 t = entry->unk2C; t -= 0x1E; t = ((entry->unkC) + (t)); entry->unk50 = ATTN(t); }
 } else {
 entry->unk48 = ATTN(entry->unk1C + ((((entry->unk28) + (entry->unkC))) + entry->unk20));
 entry->unk4C = ATTN((entry->unk24 + (entry->unk1C + entry->unkC)) + entry->unk28);
 { s32 t = entry->unk2C; t = t + entry->unkC; t -= 0x1E; t = ((t) + (entry->unk1C)); entry->unk50 = ATTN(t); }
 }
 if (entry->unk4 & 2) {
 entry->unk54 = ATTN(entry->unk28 + (entry->unk10 + entry->unk20));
 entry->unk58 = ATTN(entry->unk28 + (entry->unk10 + entry->unk24));
 { s32 t = entry->unk2C; t -= 0x1E; t = ((entry->unk10) + (t)); entry->unk5C = ATTN(t); }
 } else {
 entry->unk54 = ATTN(entry->unk1C + ((entry->unk28 + entry->unk10) + entry->unk20));
 entry->unk58 = ATTN(entry->unk28 + ((entry->unk1C + entry->unk10) + entry->unk24));
 { s32 t = entry->unk2C; t = t + entry->unk10; t -= 0x1E; t = ((t) + (entry->unk1C)); entry->unk5C = ATTN(t); }
 }
 break;
 case 3:
 lab_t0 = entry->unk28 + (entry->unk1C + entry->unk20);
 entry->unk3C = ATTN(lab_t0);
 entry->unk40 = ATTN(entry->unk28 + (entry->unk1C + entry->unk24));
 entry->unk54 = ATTN(entry->unk2C + (entry->unk1C + entry->unk30));
 entry->unk58 = ATTN(entry->unk2C + (entry->unk1C + entry->unk34));
 if (entry->unk4 & 1) {
 entry->unk48 = ATTN(entry->unk28 + (entry->unkC + entry->unk20));
 entry->unk4C = ATTN(entry->unk28 + (entry->unkC + entry->unk24));
 entry->unk50 = ATTN(entry->unk2C + (entry->unkC + entry->unk30));
 entry->unk5C = ATTN(entry->unk2C + (entry->unkC + entry->unk34));
 } else {
 entry->unk48 = ATTN(entry->unk1C + ((entry->unkC + entry->unk28) + entry->unk20));
 entry->unk4C = ATTN(entry->unk1C + (entry->unkC + entry->unk24) + entry->unk28);
 entry->unk50 = ATTN(entry->unk1C + ((entry->unkC + entry->unk2C) + entry->unk30));
 entry->unk5C = ATTN(entry->unk1C + ((entry->unk34 + entry->unkC) + entry->unk2C));
 }
 flags |= 0x4000;
 break;
 }
 {
 BOOL oldInts;
 u16 *q;
 oldInts = OSDisableInterrupts();
 *(u16 *)((u8 *)arg0 + 0x19C) = entry->unk38;
 *(u16 *)((u8 *)arg0 + 0x19E) = 0;
 q = (u16 *)((u8 *)arg0 + 0x14A);
 v = entry->unk3C;
 q[0] = v;
 q += 1;
 if (v != 0) flags |= 1;
 q[0] = 0;
 v = entry->unk40;
 q[1] = v;
 q += 2;
 if (0 != v) flags |= 2;
 q[0] = 0;
 v = entry->unk48;
 q[1] = v;
 q += 2;
 if (v != 0) flags |= 16;
 q[0] = 0;
 v = entry->unk4C;
 q[1] = v;
 q += 2;
 if (v != 0) flags |= 32;
 q[0] = 0;
 v = entry->unk54;
 q[1] = v;
 q += 2;
 if (v != 0) flags |= 512;
 q[0] = 0;
 v = entry->unk58;
 q[1] = v;
 q += 2;
 if (v != 0) flags |= 1024;
 q[0] = 0;
 v = entry->unk5C;
 q[1] = v;
 q += 2;
 if (v != 0) flags |= 4096;
 q[0] = 0;
 v = entry->unk44;
 q[1] = v;
 q += 2;
 if (v != 0) flags |= 4;
 q[0] = 0;
 v_2 = entry->unk50;
 q[1] = v_2;
 q += 2;
 if (v_2 != 0) flags |= 128;
 q[0] = 0;
 *(s16 *)((u8 *)arg0 + 0x144) = flags;
 *(u32 *)((u8 *)arg0 + 0x1C) = *(u32 *)((u8 *)arg0 + 0x1C) | 0x212;
 OSRestoreInterrupts(oldInts);
 }
}
#pragma opt_lifetimes reset

#pragma opt_strength_reduction reset
#pragma opt_loop_invariants reset
#pragma opt_propagation reset
#pragma opt_common_subs reset
