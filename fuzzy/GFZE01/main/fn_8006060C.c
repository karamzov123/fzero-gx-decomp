/* Non-matching: best partial attempt (41.34% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_80192D68[1344];
extern void fn_8005FBDC(u8 value);

typedef struct fn_8006060C_Entry {
    u8 unk_0;
    u8 unk_1;
    u8 pad_2[0xa];
    u8 unk_c;
    u8 pad_d[3];
    u32 unk_10;
    u8 data[16][4];
} fn_8006060C_Entry;

typedef struct fn_8006060C_Data {
    u8 pad_0[0x444];
    u32 unk_444;
    u8 pad_448[0x56d4];
    u32 unk_5b1c;
} fn_8006060C_Data;

extern fn_8006060C_Data *lbl_801A6C80;

typedef void (*fn_8006060C_Callback)(s32, u32);

void fn_8006060C(u32 arg0) {
    fn_8006060C_Entry *entries = (fn_8006060C_Entry *)lbl_80192D68;
    u8 i;
    u8 j;

    for (i = 0; i < 16; i++) {
        if (arg0 != entries[i].unk_0) {
            continue;
        }
        if (entries[i].unk_1 == 0) {
            fn_8006060C_Data *data = lbl_801A6C80;
            if (data->unk_5b1c != 0) {
                ((fn_8006060C_Callback)data->unk_5b1c)(-5, data->unk_444);
            }
        } else {
            u8 *link = (u8 *)entries[i].unk_10;
            for (j = 0; j <= entries[i].unk_c; j++) {
                if (entries[i].data[j][0] == 1) {
                    if (entries[i].data[j][2] != 0xff) {
                        fn_8005FBDC(entries[i].data[j][2]);
                    }
                    if (entries[i].data[j][3] != 0xff) {
                        fn_8005FBDC(entries[i].data[j][3]);
                    }
                    entries[i].data[j][0] = 0;
                }
                link = link + *link;
            }
            entries[i].pad_2[9] = 0;
        }
        entries[i].unk_0 = 0xff;
        entries[i].unk_1 = 0;
    }
}
