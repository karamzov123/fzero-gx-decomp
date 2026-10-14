/* Non-matching: best partial attempt (94.51% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/card.h"
#include "rel/main_rel/memcard.h"

typedef struct {
    u8 pad_0[0xC];
    void *unk_C;
    u8 pad_10[0x88];
    u64 unk_98;
} MemcardSlot;
typedef struct {
    u8 pad_0[0x1A];
    s16 unk_1A;
    s16 unk_1C;
    u8 pad_1E[4];
    u8 unk_22;
    u8 pad_23[0x19];
    u8 unk_3C;
    u8 unk_3D;
} MemcardArg;
typedef struct {
    u8 pad_0[0x94];
    s32 unk_94[16];
    s32 unk_D4[16];
    s32 unk_114[16];
} MemcardData;
extern u32 lbl_801A66B4;
extern u32 lbl_801A6410;
extern u32 lbl_1_bss_7A388[5];
extern void fn_80008BEC(void *, int, u32);
extern s32 fn_1_465D0(s32, s32);
extern void *fn_1_45D0(u32, u32, const char *, int);
extern void fn_1_46B4(u32, void *, const char *, int);
extern s32 fn_8002DFE0(s32, void *, CARDCallback);
#define FILE_STR ((const char *)(data + 0x6CF0))
static inline s32 fn_1_B9DE8_mount(u32 data, s32 chan) {
    s32 result;
    MemcardSlot *slot = (MemcardSlot *)&lbl_1_bss_716C8 + chan;
    slot->unk_C = fn_1_45D0(lbl_801A6410, 0xA000, FILE_STR, 0x256D);
    do {
        result = fn_8002DFE0(chan, slot->unk_C, 0);
    } while (result == -1);
    if (result != 0 && result != -6) {
        if (slot->unk_C != 0) {
            fn_1_46B4(lbl_801A6410, slot->unk_C, FILE_STR, 0x2573);
            slot->unk_C = 0;
        }
    } else {
        s32 tmp;
        do {
            tmp = CARDCheck(chan);
        } while (tmp == -1);
        result = tmp;
    }
    return result;
}
static inline void *fn_1_B9DE8_unmount_read_pointer(MemcardSlot *owner) { return owner->unk_C; }
static inline void fn_1_B9DE8_unmount(u32 data, s32 chan) {
    MemcardSlot *slot = (MemcardSlot *)&lbl_1_bss_716C8 + chan;
    do {
    } while (CARDUnmount(chan) == -1);
    if (fn_1_B9DE8_unmount_read_pointer(slot) != 0) {
        fn_1_46B4(lbl_801A6410, slot->unk_C, FILE_STR, 0x258C);
        slot->unk_C = 0;
    }
}
static inline void fn_1_B9DE8_slot(u32 data, u32 chan) {
    if (fn_1_B9DE8_mount(data, chan) == 0) {
        u64 *serial = &((MemcardSlot *)&lbl_1_bss_716C8)[chan].unk_98;
        if (CARDGetSerialNo(chan, serial) != 0) {
            *serial = 0;
        }
        ((u64 *)lbl_1_bss_7A388)[chan] = *serial;
    } else {
        ((u64 *)lbl_1_bss_7A388)[chan] = 0;
    }
    fn_1_B9DE8_unmount(data, chan);
}
#pragma peephole off
static inline u32 fn_1_B9DE8_language(u32 *language) { return *language; }
#pragma peephole reset
#pragma opt_dead_assignments off
#pragma opt_lifetimes off
void fn_1_B9DE8(MemcardArg *arg0) {
    u32 data = (u32)&lbl_1_data_35AC8;
    u32 *lang = &lbl_801A66B4;
    u32 *flag = &lbl_1_bss_7A380;
    fn_80008BEC(arg0, 0, 0x48);
    arg0->unk_22 = 3;
    arg0->unk_1A = -1;
    arg0->unk_1C = -1;
    *flag = 0;
    fn_1_465D0(((MemcardData *)data)->unk_94[fn_1_B9DE8_language(lang)], 1);
    fn_1_465D0(((MemcardData *)data)->unk_D4[fn_1_B9DE8_language(lang)], 1);
    fn_1_465D0(((MemcardData *)data)->unk_114[fn_1_B9DE8_language(lang)], 1);
    arg0->unk_3C = 0xFF;
    arg0->unk_3D = 0;
    fn_1_B9DE8_slot(data, 0);
    fn_1_B9DE8_slot(data, 1);
}
#pragma opt_lifetimes reset
#pragma opt_dead_assignments reset
