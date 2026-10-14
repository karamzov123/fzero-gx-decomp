/* Non-matching: best partial attempt (98.50% in the project ledger). Scored for the
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
struct fn_12_7870_Arg2 {
u32 unk_0;
s32 unk_4;
};
struct fn_12_7870_Arg3 {
u8 pad_0[0xC];
s16 unk_C;
s16 unk_E;
};
#pragma opt_propagation off
#pragma opt_lifetimes off
static inline u8 fn_12_7870_array_read(s32 index, u8 *array) { return array[index]; }
void fn_12_11204(u32 arg0, u32 arg1, struct fn_12_7870_Arg2 *arg2, struct fn_12_7870_Arg3 *arg3) {
s16 x;
u32 offset;
u8 *entry;
s16 y;
s8 a;
s8 b;
x = arg3->unk_C;
offset = arg1 << 1;
y = arg3->unk_E;
entry = (u8 *)offset + 0x1344;
entry = (u8 *)arg0 + (u32)entry;
a = (s8)(*((entry) + (0)));
b = (s8)fn_12_7870_array_read(1, entry);
arg2->unk_0 = ((x) * ((a << 3))) + (b << 3);
arg2->unk_4 = (a << 4) * y + (b << 4);
}
#pragma opt_lifetimes reset
#pragma opt_propagation reset
