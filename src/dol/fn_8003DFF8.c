#include "types.h"

typedef struct {
    u8 pad00[4];
    s32 unk04;
    s32 unk08;
} Slot48;

typedef struct {
    u8 pad00[8];
    u32 unk08;
    u8 pad0C[0x20];
    u32 unk2C;
    u8 pad30[0x0C];
    u32 unk3C;
    u8 pad40[0x70];
} Entry;

typedef struct {
    Entry *entries;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
} Slot;

extern u32 OSDisableInterrupts(void);
extern void OSReport(const char *fmt, ...);
extern void OSRestoreInterrupts(u32 level);
extern s32 fn_8003401C(u32 arg);
extern u32 fn_8000A050(void);
extern u32 fn_8000A040(void);
extern u32 fn_8000A020(void);

extern Slot48 *lbl_801A6C48;
extern u8 lbl_801A6C30;
extern u32 lbl_801A6C44;
extern Slot *lbl_801A6C4C;
extern char lbl_8012B5F8[];

#pragma opt_propagation off
void fn_8003DFF8(s32 arg0) {
    s32 offset;
    u32 level;
    s32 id;
    Slot48 *entry;

    u8 *p;

    level = OSDisableInterrupts();
    offset = (arg0 * 0x10) & 0xFF0;
    entry = (Slot48 *)(((offset) + ((u8 *)lbl_801A6C48)));
    id = entry->unk08;
    if (id < 0) {
        OSReport(lbl_8012B5F8);
        OSRestoreInterrupts(level);
        return;
    }
    switch (entry->unk04) {
    case 2:
        fn_8003401C((u32)(((u16)id + 0x10000 + (((lbl_801A6C30 << 8) & 0xFF00))) - 0x1000));
        break;
    case 1:
        fn_8003401C((u32)(((u16)id + 0x10000 + (((lbl_801A6C30 << 8) & 0xFF00))) - 0x1000));
        /* fallthrough */
    case 0:
        lbl_801A6C4C[lbl_801A6C44].entries[id].unk08 = fn_8000A050();
        lbl_801A6C4C[lbl_801A6C44].entries[id].unk2C = fn_8000A040();
        lbl_801A6C4C[lbl_801A6C44].entries[id].unk3C = fn_8000A020();
        break;
    }
    {
        s32 v = -1;
        entry = (Slot48 *)((u8 *)lbl_801A6C48 + offset);
        entry->unk08 = v;
    }
    OSRestoreInterrupts(level);
}

#pragma opt_propagation reset

