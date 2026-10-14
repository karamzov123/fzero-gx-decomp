/* Non-matching: best partial attempt (6.50% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/light.h"

extern const f32 lbl_1_rodata_33A8;
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49514(u32 *);
extern void fn_1_8CB78(void *);
extern void fn_1_A8EB0(int, int);
extern void fn_1_A8DD4(const char *, ...);
extern u8 lbl_1_data_1F318[164];

typedef struct {
    u8 pad0[0x20];
    u32 flags;
} CarTest;

void fn_1_7C7CC(CarTest *arg0) {
    s8 car;
    u8 *data = (u8 *)lbl_1_data_1EEB0;
    f32 *f = (f32 *)&lbl_1_rodata_33A8;
    car = *(s8 *)((u8 *)arg0 + 7);
    if ((arg0->flags & 0x40000000) != 0) {
        fn_1_496FC(f[63], f[1]);
        fn_1_4AE0C((const char *)(data + 0x1cc));
        return;
    }
    if ((lbl_1_bss_9F8.unk_10 & 0x800) != 0) {
        fn_1_A8EB0(0x14, 3);
        fn_1_A8DD4((const char *)(data + 0xc8), *(u32 *)(lbl_1_data_1F318 + ((s8)*((u8 *)*(u32 *)arg0 + car * 0x440 + 0x328)) * 4));
        fn_1_8CB78(*(void **)(*(u32 *)arg0 + car * 0x440 + 0x37c));
    } else {
        fn_1_495C8(1);
        fn_1_496FC(f[66], f[67]);
        fn_1_4AE0C((const char *)(data + 0xc8), *(u32 *)(*(u32 *)((u8 *)arg0 + 0x10) + ((s8)*((u8 *)arg0 + 6) << 2)));
        fn_1_495C8(0);
        fn_1_4955C(f[65], f[0]);
        fn_1_4AE0C((const char *)(data + 0xc8), *(u32 *)(*(u32 *)((u8 *)arg0 + 0x14) + ((s8)*((u8 *)arg0 + 6) << 2)));
    }
}
