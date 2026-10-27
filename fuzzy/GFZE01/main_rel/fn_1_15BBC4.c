/* Non-matching: best partial attempt (96.06% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_win.h"

extern void fn_1_15C0AC(void);
extern void fn_1_15BEBC(u16, Obj_1_bss_8F8E0 *);
extern u32 fn_1_15BE38(void);
extern void fn_80008BEC(void *, int, u32);

typedef struct {
    u16 unk_0;
    u8 pad_2[2];
    u16 unk_4;
    u8 pad_6[2];
} NameEntry;

typedef struct {
    u8 pad_00[0x20];
    NameEntry entry[16];
    u16 index[16];
    u16 hash[15][32];
    u8 pad_480[4];
    u16 unk_484;
    u16 unk_486;
} WinName;

u16 fn_1_15BBC4(void) {
    u16 *tbl;
    WinName *w = (WinName *)&lbl_1_bss_8F8E0;
    s32 i;
    u16 idx;
    s32 nidx;
    NameEntry *entry;
    u16 *index;
    u16 result;

    if (w->unk_486 != 0) {
        u16 timer = w->unk_486 - 1;
        result = w->unk_484;
        w->unk_486 = timer;
        return result;
    }
    fn_1_15C0AC();
    entry = w->entry;
    index = w->index;
    for (i = 1; i < 0x10; i++) {
        tbl = w->hash[i - 1];
        idx = index[i];
        fn_1_15BEBC(i, (Obj_1_bss_8F8E0 *)&entry[i]);
        if (tbl[idx] == 0) {
            tbl[idx] = entry[i].unk_4;
        } else {
            u16 buttons = entry[i].unk_4;
            if (buttons != tbl[idx]) {
                nidx = (idx + 1) % 32;
                index[i] = nidx;
                tbl[(u16)nidx] = buttons;
            }
        }
    }
    result = fn_1_15BE38();
    w->unk_484 = result;
    if (result != 0xffff) {
        w->unk_486 = 0x78;
        fn_80008BEC(w->hash, 0, 0x3c0);
    }
    return w->unk_484;
}

