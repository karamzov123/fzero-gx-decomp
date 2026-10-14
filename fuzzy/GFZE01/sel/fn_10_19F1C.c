/* Non-matching: best partial attempt (92.38% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int BOOL;
typedef unsigned long size_t;
extern u8 lbl_10_bss_55B04[32];
typedef struct {
u8 pad_00[0x54];
f32 value;
} Fn10_19EC8Object;
extern void fn_80074188(s16, s16, s16, s16);
void fn_10_19F1C(Fn10_19EC8Object *obj, u32 unused) {
s16 *entry;
f32 raw;
s16 index = (s16)raw;
raw = obj->value;
entry = (s16 *)lbl_10_bss_55B04 + index * 4;
fn_80074188(entry[0], entry[1], entry[2], entry[3]);
}
