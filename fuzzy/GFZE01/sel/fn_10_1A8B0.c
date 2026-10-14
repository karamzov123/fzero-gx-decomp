/* Non-matching: best partial attempt (64.59% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct Sig_fn_10_C258_SelContext {
    u8 pad[0xa4];
    u8 *entries;
} Sig_fn_10_C258_SelContext;
struct Copy88 { u32 a[22]; };
struct Pool {
    u8 pad_0[0x44]; f32 one; f32 half; f32 zero;
    u8 pad_50[0x14]; f32 four;
    u8 pad_68[8]; f32 quarter;
    u8 pad_74[0x14]; f64 magic; f64 magic2;
    u8 pad_98[0x7c]; f32 nine;
    u8 pad_118[0x13c]; f32 two;
    u8 pad_258[0x14]; f32 threequarter;
    u8 pad_270[0x3c]; f32 point6;
    u8 pad_2b0[0x14]; f32 fifteen;
    u8 pad_2c8[0x44]; f32 twelve;
    u8 pad_310[0x8c]; f32 fortyfive;
    u8 pad_3a0[0x2b4]; f32 thirty;
    u8 pad_658[0x548]; u32 word_ba0; f32 thirtysix; f32 twentyone;
};
struct State { u8 pad[0x9e]; u8 index; u8 pad2[0x51]; u32 times[1]; };
extern s32 lbl_10_bss_555FC;
extern f32 lbl_10_rodata_158[19];
extern struct State lbl_1_bss_8B3A0;
extern s16 lbl_1_bss_962;
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A66A0;
extern s32 lbl_801A66B4;
extern s16 fn_10_C258(Sig_fn_10_C258_SelContext *, s32);
extern u32 fn_10_21C20(s16,s16);
extern int fn_1_4C10(void);
extern u32 fn_1_4CAC(void);
extern f32 fn_1_4C24(void);
extern void fn_1_49410(void);
extern u32 fn_1_50A90(void *, u32, u32, u32, u32);
extern void fn_1_495C8(s32);
extern void fn_1_495B0(u32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32,f32);
extern void fn_1_495A0(f32);
extern void fn_1_495FC(void);
extern void fn_1_4966C(f32,f32);
extern void fn_1_496FC(f32,f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4AE0C(const char *,...);

void fn_10_1A8B0(s16 arg0, s16 arg1) {
    struct Pool *pool = (struct Pool *)lbl_10_rodata_158;
    f32 a = pool->one;
    f32 b = pool->one;
    f32 c = pool->one;
    u8 index = lbl_1_bss_8B3A0.index;
    s16 x = arg0, y = arg1;
    struct Copy88 copy;
    u32 message;
    if (lbl_10_bss_555FC != 0) {
        if (fn_1_4C10() != 0 && fn_1_4CAC() != 0) {
            f32 value = fn_1_4C24();
            if (value < pool->quarter) {
                f32 t = pool->four * value;
                if (t < pool->zero) b = pool->zero;
                else if (t > a) b = a;
                else b = t;
                a = pool->zero;
                c = a;
            } else if (value < pool->half) {
                f32 t = pool->four * (value - pool->quarter);
                if (t < pool->zero) a = pool->zero;
                else if (t > b) a = b;
                else a = t;
                c = pool->zero;
            } else if (value < pool->threequarter) {
                f32 t = pool->four * (value - pool->half);
                if (t < pool->zero) c = pool->zero;
                else if (t > b) c = b;
                else c = t;
            }
        }
    }
    if (fn_10_C258((Sig_fn_10_C258_SelContext *)&lbl_1_bss_8B3A0, lbl_1_bss_962) == 1) {
        f32 elapsed = (f32)(*(u32 *)&lbl_801A66A0 - lbl_1_bss_8B3A0.times[index]);
        elapsed = (elapsed - (f32)pool->magic2) / pool->fifteen;
        if (elapsed < pool->quarter) {
            f32 t = pool->four * elapsed;
            if (t < pool->zero) b = pool->zero;
            else if (t > pool->one) b = pool->one;
            else b = t;
            a = pool->one;
            c = pool->one - b;
        } else if (elapsed < pool->half) {
            f32 t = pool->four * (elapsed - pool->quarter);
            if (t < pool->zero) t = pool->zero;
            else if (t > pool->one) t = pool->one;
            a = pool->one - t;
            c = pool->zero;
        } else if (elapsed < pool->threequarter) {
            f32 t = pool->four * (elapsed - pool->half);
            if (t < pool->zero) a = pool->zero;
            else if (t > pool->one) a = pool->one;
            else a = t;
            b = pool->zero;
            c = pool->zero;
        } else {
            a = pool->zero; b = pool->zero; c = pool->zero;
        }
    }
    if (fn_10_C258((Sig_fn_10_C258_SelContext *)&lbl_1_bss_8B3A0, lbl_1_bss_962) < 2) {
        fn_1_49410();
        copy = *(struct Copy88 *)&lbl_1_rodata_26F8;
        copy.a[0] = 2;
        *(f32 *)((u8 *)&copy + 4) = (f32)x;
        *(f32 *)((u8 *)&copy + 8) = (f32)y;
        *(f32 *)((u8 *)&copy + 12) = pool->two;
        copy.a[12] = 10;
        *(f32 *)((u8 *)&copy + 0x38) = b;
        fn_1_50A90(&copy, 18, 45,
            (s32)((pool->thirtysix + pool->twelve * (pool->thirty * a)) * pool->one),
            (s32)(pool->fortyfive + pool->twentyone * (pool->four * a)));
        fn_1_495C8(1);
        fn_1_495B0(0x80000000);
        fn_1_4954C(pool->one);
        fn_1_4955C(pool->point6,pool->point6);
        fn_1_495A0(c);
        fn_1_495FC();
        fn_1_4966C(pool->zero,pool->nine);
        fn_1_496FC((f32)x,(f32)(y - 42));
        message = pool->word_ba0;
        fn_1_49514(&message);
        fn_10_21C20(0,(s16)lbl_801A66B4);
        fn_1_4AE0C((const char *)0);
    }
}
