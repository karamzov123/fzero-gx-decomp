/* Non-matching: best partial attempt (94.44% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */


typedef signed short s16;

typedef unsigned char u8;

typedef unsigned long u32;

struct fn_10_7FC0_lbl_10_bss_0 {
u8 pad_0[0x14];
u32 unk_14;
};
extern struct fn_10_7FC0_lbl_10_bss_0 lbl_10_bss_0;
extern u32 fn_1_12F1E8(u32);
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 lbl_10_data_8DC;
extern void fn_10_1B660(void);
void fn_10_CA94(void) {
struct fn_10_7FC0_lbl_10_bss_0 *p_lbl_10_bss_0;
u8 v0;
u32 t1;
p_lbl_10_bss_0 = (struct fn_10_7FC0_lbl_10_bss_0 *)&lbl_10_bss_0;
v0 = ((u32)p_lbl_10_bss_0 + 0x50000);
fn_1_435C(*(u32 *)((u8 *)v0 + -27768));
t1 = fn_1_3F8C((u32)&lbl_10_data_8DC, (u32)fn_10_1B660, 0, 8);
*(u32 *)((u8 *)v0 + 5952) = t1;
fn_1_12F1E8(480);
fn_1_4A00(1, (*(s16 *)((u8 *)v0 + -27764) & 0xFF), *(u32 *)((u8 *)v0 + -27768));
*(u32 *)((u8 *)v0 + 5956) = 0;
p_lbl_10_bss_0->unk_14 = -1;
}
