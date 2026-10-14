/* Non-matching: best partial attempt (90.59% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/sel_static_disp.h"

typedef struct {
    s16 indices[3];
    u8 pad_6[2];
    u32 flags;
    u8 pad_C[4];
} DisplaySource;

extern void fn_1_12AB38(void *);
extern void *fn_1_D3884(void *);
extern void fn_1_14D728(DisplaySource *, void *);

void fn_1_14D994(void *display, u32 flags, s32 load)
{
    u8 *data = (u8 *)&lbl_1_data_43E78;
    DisplaySource sources[25];
    s16 i;
    s16 j;
    s16 k;
    for (i = 0; i < 25; i++) {
        sources[i].flags = flags;
        sources[i].indices[0] = i;
        sources[i].indices[1] = i + 25;
        sources[i].indices[2] = i + 50;
    }
    if (load) {
        if (lbl_1_bss_6D82C.unk_0 == 0) {
            fn_1_12AB38(data + 0x136C);
            lbl_1_bss_6D82C.unk_0 = (u32)fn_1_D3884(data + 0x1378);
            fn_1_12AB38(data + 0x1388);
        }
        fn_1_12AB38(data + 0x138C);
        for (j = 0; j < 25; j++) {
            fn_1_14D728(&sources[j], (u8 *)display + j * 0xA20);
        }
        fn_1_12AB38(data + 0x1388);
    } else {
        fn_1_12AB38(data + 0x138C);
        for (k = 0; k < 25; k++) {
            fn_1_14D728(&sources[k], (u8 *)display + k * 0xA20);
        }
        fn_1_12AB38(data + 0x1388);
    }
}
