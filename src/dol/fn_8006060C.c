#include "types.h"
#include "dol/globals.h"
#pragma use_lmw_stmw on
#pragma opt_propagation on

extern u8 lbl_80192D68[1344];
extern void fn_8005FBDC(u8 value);

struct fn_8006060C_Entry {
    u8 state;
    u8 active;
    u8 pad_2[9];
    u8 unk_b;
    u8 count;
    u8 pad_d[3];
    u8 *record;
    u8 data[16][4];
};

void fn_8006060C(u32 arg0) {
    struct fn_8006060C_Entry *entries = (struct fn_8006060C_Entry *)lbl_80192D68;
    u32 i;
    struct { u32 value; } key;
#define id key.value
    struct { volatile u8 *value; } cursor; /* Preserve observable record reads. */
#define script cursor.value
    struct { u32 value; } counter;
#define j counter.value
    key.value = arg0;
    for (i = 0; i < 16; i++) {
        if (id == entries[i].state) {
            if (entries[i].active) {
                script = entries[i].record;
                for (j = 0; (u8)j <= entries[i].count; j++) {
                    if (((struct fn_8006060C_Entry *)lbl_80192D68)[(u8)i].data[(u8)j][0] == 1) {
                        if (((struct fn_8006060C_Entry *)lbl_80192D68)[(u8)i].data[(u8)j][2] != 0xff) {
                            fn_8005FBDC(((struct fn_8006060C_Entry *)lbl_80192D68)[(u8)i].data[(u8)j][2]);
                        }
                        if (((struct fn_8006060C_Entry *)lbl_80192D68)[(u8)i].data[(u8)j][3] != 0xff) {
                            fn_8005FBDC(((struct fn_8006060C_Entry *)lbl_80192D68)[(u8)i].data[(u8)j][3]);
                        }
                        ((struct fn_8006060C_Entry *)lbl_80192D68)[(u8)i].data[(u8)j][0] = 0;
                    }
                    script += *script;
                }
                entries[i].unk_b = 0;
            } else {
                void (*callback)(s32, u32) = *(void (**)(s32, u32))((u8 *)lbl_801A6C80 + 0x5b1c);
                if (callback) {
                    callback(-5, *(u32 *)((u8 *)lbl_801A6C80 + 0x444));
                }
            }
            entries[i].state = 0xff;
            entries[i].active = 0;
        }
    }
}
