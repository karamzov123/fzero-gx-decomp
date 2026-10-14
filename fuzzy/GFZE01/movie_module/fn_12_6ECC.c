/* Non-matching: best partial attempt (95.14% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_6ECC_lbl_12_bss_4DB8 {
    s32 unk_0;
};

typedef struct MovieEntry {
    u32 flag;
    u8 pad[0xbc];
} MovieEntry;

extern struct fn_12_6ECC_lbl_12_bss_4DB8 lbl_12_bss_4DB8;
extern u32 lbl_12_bss_4DB4;
extern u32 lbl_12_rodata_668;
extern void fn_12_33428(u32 *, u32, u32);
extern void fn_12_6708(void);
extern void fn_12_6A8C(void);

static inline void set_flags(MovieEntry *entries, s32 count) {
    struct { s32 value; } i;
    for (i.value = 0; i.value < count; i.value++) {
        entries[i.value].flag = 1;
    }
}

void fn_12_6ECC(s32 arg0, void *arg1) {
    u32 p;
    u32 lab_t2;

    lbl_12_bss_4DB4 = (u32)&"\nCRI MPS/GC Ver.1.669 Build:May  9 2003 15:17:49\n";
    lbl_12_bss_4DB8.unk_0 = (u32)arg1;
    lab_t2 = (u32)(((((((arg0 - 1) * 0xc0))) + ((0xd0))))) >> 2;
    fn_12_33428((u32 *)arg1, 0, lab_t2);
    p = lbl_12_bss_4DB8.unk_0;
    *(u32 *)p = 0;
    *(u32 *)(((((p)) + ((4))))) = 0;
    *(u32 *)(((((p)) + ((8))))) = 0;
    *(u32 *)(((((lbl_12_bss_4DB8.unk_0)) + ((0xc))))) = arg0;
    set_flags((MovieEntry *)(((((lbl_12_bss_4DB8.unk_0)) + ((0x10))))), arg0);
    fn_12_6708();
    fn_12_6A8C();
}
