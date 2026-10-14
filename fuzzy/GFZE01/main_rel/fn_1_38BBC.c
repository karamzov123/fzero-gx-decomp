/* Non-matching: best partial attempt (95.76% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/game.h"

extern int fn_1_4C10(void);
typedef struct Sig_fn_1_12C060_FnData Sig_fn_1_12C060_FnData;
struct Sig_fn_1_12C060_FnData {
    u16 unk0;
    u32 unk4;
    u8 unk8;
    u8 pad9[3];
    u8 (*unkC)(Sig_fn_1_12C060_FnData *, u32);
    u32 unk10;
    s32 (*unk14)(Sig_fn_1_12C060_FnData *, u32);
    u32 unk18;
};
extern s32 fn_1_12C060(Sig_fn_1_12C060_FnData *);
typedef struct {
    u8 pad_0[4];
    void *unk_4;
    void *unk_8;
    u8 pad_C[0x10];
    Sig_fn_1_12C060_FnData *unk_1C;
} Sig_fn_1_12B3BC_FnObj;
extern u32 fn_1_12B3BC(Sig_fn_1_12B3BC_FnObj *, void *, void *, void *, void *, void *, void *);
extern void fn_1_3F75C(void);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_47E54(s32);

void fn_1_38BBC(void)
{
    struct { u8 *value; } mid_base;
    u8 *mid;
    struct { u8 *value; } root_base;
    u8 *base;
    struct { u8 *value; } high_base;
    u8 *high;
    Sig_fn_1_12B3BC_FnObj *obj;
    s16 i;
    s32 result;
    void *transition;
    root_base.value = &lbl_1_bss_3C00;
    base = root_base.value;
    mid_base.value = base + 0x20000;
    mid = mid_base.value;
    high_base.value = mid + 0x10000;
    high = high_base.value;
    if (fn_1_4C10() == 0) {
        obj = (Sig_fn_1_12B3BC_FnObj *)(mid + 0x3070);
        for (i = 0; i < 4; i++) {
            fn_1_12C060(&obj->unk_1C[i]);
        }
        result = fn_1_12B3BC((Sig_fn_1_12B3BC_FnObj *)(mid + 0x3070),
            *(void **)(mid + 0x1F88), *(void **)(mid + 0x20A4),
            high + 0x45C0, high + 0x45D0, high + 0x45F0, 0);
        if (fn_1_4C10() == 0) {
            if (*(s32 *)(mid + 0x3028) == 1) {
                fn_1_3F75C();
                if (*(u32 *)(base + 0x30) & 0x201) {
                    *(s16 *)(base + 0x14E8) = 0x28;
                } else {
                    *(s16 *)(base + 0x14E8) = 0x27;
                }
            } else if (*(s32 *)(mid + 0x3028) == -1) {
                fn_1_3F75C();
                *(s16 *)(base + 0x14E8) = 0x25;
            }
        }
        if ((s16)result == 1 && *(s32 *)(mid + 0x3028) == 0) {
            *(s32 *)(mid + 0x3028) = 1;
            transition = *(void **)(base + 0x1500);
            fn_1_4A00(0, 30, transition);
            lbl_1_bss_6EAB4.unk_0 |= 0x2C;
            fn_1_47E54(0x94);
        }
    }
}
