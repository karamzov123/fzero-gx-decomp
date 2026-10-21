#pragma use_lmw_stmw on
#include "types.h"
#include "dol/globals.h"

struct ResourceSlot { u8 pad[8]; u8 *resource; u32 unused; };
struct SlotState {
    u8 pad[0x488];
    u8 *command;
    u8 pad48c[4];
    u8 selected;
    u8 pad491;
    u8 mode;
    u8 pad493[5];
};
struct StateEntry { u8 *command; u32 unused; u8 selected; u8 unused9; u8 mode; u8 pad[5]; };
struct Manager {
    struct ResourceSlot resources[16];
    u8 pad100[0x344];
    u32 packed;
    u8 pad448[0x40];
    struct StateEntry states[16];
};
extern void fn_80064FDC(u32, void *);
extern void fn_8006331C(u8, u8);

static inline void set_selected(u32 slot, u8 selected) {
    ((struct StateEntry *)((u8 *)lbl_801A6C80 + 8))[slot + 0x48].selected = selected;
}
static inline void set_mode(u32 slot, u8 mode) {
    ((struct StateEntry *)((u8 *)lbl_801A6C80 + 8))[slot + 0x48].mode = mode;
}
static inline u8 available(u8 index) {
    u8 *entry = (u8 *)lbl_801A6C80 + index * 0x20;
    struct { u8 value; } result;
    result.value = 0;
    if (!(entry[0x589] & 1)) {
        result.value = 1;
    }
    return result.value;
}
static inline void clear_full(u8 index) {
    *(u8 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x588) = 0;
    *(u8 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x589) = 0;
    *(u32 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x5a0) = 0;
    *(u32 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x5a4) = 0;
    *(u8 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x58a) = 0;
    *(u8 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x599) = 0x40;
    *(u8 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x59a) = 0;
    *(u8 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x59b) = 0;
    *(u8 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x59c) = 0;
    *(u8 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x59d) = 0;
}
static inline void clear_partial(u8 index) {
    *(u8 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x58a) = 0;
    *(u8 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x599) = 0x40;
    *(u8 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x59a) = 0;
    *(u8 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x59b) = 0;
    *(u8 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x59c) = 0;
    *(u8 *)((u8 *)lbl_801A6C80 + index * 0x20 + 0x59d) = 0;
}

static inline void clear_slot(u8 slot) {
    u8 i;
    u8 j;
    u8 index;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 4; j++) {
            index = *((u8 *)lbl_801A6C80 + j + 0xd88 + slot * 64 + i * 4);
            if (index != 255 && available(index)) {
                clear_full(index);
                *((u8 *)lbl_801A6C80 + j + 0xd88 + slot * 64 + i * 4) = 255;
            }
        }
    }
}

#define base manager.p
void fn_80065528(u32 force) {
    u8 i;
    u8 j;
    u32 slot;
    struct { struct Manager *p; } manager;
    u8 *resource;
    u32 selected;
    u32 packed;
    u8 *command;
    u8 index;
    manager.p = (struct Manager *)lbl_801A6C80;
    packed = manager.p->packed;
    slot = packed & 15;
    selected = (packed >> 8) & 255;
    resource = base->resources[slot].resource;
    if (resource && (selected != base->states[slot].selected || force)) {
        u8 *data;
        u8 n;
        u16 *table;
        table = (u16 *)(resource + 0x3c);
        data = resource + *(u32 *)(resource + 0x18);
        if (selected > (u32)((*table >> 8) - 1)) return;
        n = 0;
        while (n <= selected + 1) {
            table++;
            n++;
        }
        if (!*table) return;
        command = base->states[slot].command = data + *table;
        set_selected(slot, selected);
        if (command[1] != 0x80)
            set_mode(slot, command[1]);
        clear_slot(slot);
        fn_80064FDC(slot, command);
        fn_8006331C(command[3], command[4]);
    } else if (resource) {
        for (i = 0; i < 16; i++) {
            for (j = 0; j < 4; j++) {
                index = *((u8 *)lbl_801A6C80 + j + 0xd88 + slot * 64 + i * 4);
                if (index != 255) {
                    u8 *entry = (u8 *)lbl_801A6C80 + index * 0x20;
                    u8 active = 0;
                    if (!(entry[0x589] & 1)) active = 1;
                    if (active) clear_partial(index);
                }
            }
        }
    }
}
