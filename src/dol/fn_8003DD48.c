#include "types.h"

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern u32 fn_8000A020(void);
extern u32 fn_8000A040(void);
extern u32 fn_8000A050(void);
extern volatile u32 lbl_801A6C40; /* Shared with timer handler; counter rereads are observable. */
extern u32 lbl_801A6C44;
typedef struct { u32 unk00; s32 unk04; s32 unk08; u32 unk0C; } Slot48;
typedef struct {
    u8 unk00; u8 pad01[3];
    u32 unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    u32 unk20, unk24, unk28, unk2C, unk30, unk34, unk38;
    u8 pad3C[0x74];
} Entry;
typedef struct { Entry *entries; u32 unk04, unk08, unk0C; } Slot;
extern Slot48 *lbl_801A6C48;
extern Slot *lbl_801A6C4C;
extern u32 lbl_801A6C50;
extern u8 lbl_801A6C30;
extern void OSReport(const char *, ...);
extern s32 fn_8003401C(u32);

#pragma opt_propagation off
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("PERF : Unknown event type for ID %d - possibly out of memory\n");
    OSReport("PERF : event is still open for CPU!\n");
}
#pragma section code_type ".text"

void fn_8003DD48(u8 arg0) {
    u32 t7;
    u32 v1;
    u32 v0;
    s32 *v2;
    struct { u32 value; } v6;
    v1 = OSDisableInterrupts();
    v0 = (arg0 * 16) & 0xFF0;
    v2 = (s32 *)((u8 *)lbl_801A6C48 + v0);
    if (*(v2 += 2) < 0) {
        if (lbl_801A6C40 >= lbl_801A6C50 - 1) {
            lbl_801A6C40 = lbl_801A6C50 - 1;
            v6.value = lbl_801A6C40;
        } else {
            v6.value = lbl_801A6C40;
            lbl_801A6C40 = v6.value + 1;
        }
        *v2 = v6.value;
        lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk00 = arg0;
        lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk14 = 0;
        {
        Slot48 *entry;
        entry = (Slot48 *)((u8 *)lbl_801A6C48 + v0);
        switch (entry->unk04) {
        case 2:
            lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk20 = 0;
            lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk30 = 0;
            lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk0C = 0;
            lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk10 = 0;
            fn_8003401C((u16)v6.value + 0x10000 + ((lbl_801A6C30 << 8) & 0xFF00) - 0x2000);
            break;
        case 1:
            lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk0C = 0;
            lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk10 = 0;
            lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk20 = fn_8000A040();
            lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk30 = fn_8000A020();
            fn_8003401C((u16)v6.value + 0x10000 + ((lbl_801A6C30 << 8) & 0xFF00) - 0x2000);
        case 0:
            lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk28 = fn_8000A040();
            lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk38 = fn_8000A020();
            t7 = fn_8000A050();
            lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk04 = t7;
            lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk18 = t7;
            lbl_801A6C4C[lbl_801A6C44].entries[v6.value].unk08 = 0;
            break;
        default:
            OSReport("PERF : Unknown event type for ID %d - possibly out of memory\n", (u8)arg0);
        }
        }
    } else {
        OSReport("PERF : event is still open for CPU!\n");
    }
    OSRestoreInterrupts(v1);
}
#pragma opt_propagation reset
