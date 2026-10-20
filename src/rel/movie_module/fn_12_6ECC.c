#include "types.h"

typedef struct MovieEntry {
    u32 flag;
    u8 pad[0xbc];
} MovieEntry;

typedef struct MovieWorkspace {
    u32 callback_words[3];
    s32 count;
    MovieEntry entries[];
} MovieWorkspace;

extern MovieWorkspace *lbl_12_bss_4DB8;
extern const char *lbl_12_bss_4DB4;
extern const char lbl_12_rodata_668[50];
extern void fn_12_33428(u32 *, u32, u32);
extern void fn_12_6708(void);
extern void fn_12_6A8C(void);

static inline void initialize_entry_range(MovieEntry *entries, s32 count, s32 first) {
    for (; first < count; first++) {
        entries[first].flag = 1;
    }
}

static inline s32 initialize_entries(s32 count, void *memory) {
    MovieWorkspace *workspace;
    u32 word_count;

    lbl_12_bss_4DB4 = lbl_12_rodata_668;
    lbl_12_bss_4DB8 = memory;
    word_count = (u32)((count - 1) * 0xc0 + 0xd0) >> 2;
    fn_12_33428((u32 *)memory, 0, word_count);
    workspace = lbl_12_bss_4DB8;
    workspace->callback_words[0] = 0;
    workspace->callback_words[1] = 0;
    workspace->callback_words[2] = 0;
    lbl_12_bss_4DB8->count = count;
    initialize_entry_range(lbl_12_bss_4DB8->entries, count, 0);
    return 0;
}

s32 fn_12_6ECC(s32 count, void *memory) {
    s32 result = initialize_entries(count, memory);
    if (result != 0) {
        return result;
    }
    fn_12_6708();
    fn_12_6A8C();
    return 0;
}
