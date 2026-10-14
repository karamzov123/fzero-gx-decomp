/* Non-matching: best partial attempt (95.06% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80055304_object {
    u32 unk_0;
    void (*callback)(void (*)(void), u32);
};
struct fn_80055304_entry {
    struct fn_80055304_object *object;
    char text[12];
};
struct fn_80055304_state {
    void (*callback)(u32, u32, u32);
    u32 callback_arg;
    u8 unk_8[0x130];
    char buffer[12];
    struct fn_80055304_entry entries[32];
};
extern struct fn_80055304_state lbl_80187430;
extern u8 lbl_80091390[];
extern size_t strlen(const char *);
extern s32 strncmp(const char *, const char *, size_t);
extern void *memcpy(void *, const void *, size_t);
extern void fn_80055580(void);

#pragma opt_propagation off
static inline struct fn_80055304_object *find(char *name, struct fn_80055304_state *state, s32 len) {
    struct fn_80055304_entry *entry = state->entries;
    u32 i;
    for (i = 0; i < 32; i++) {
        if (strncmp(name, entry->text, len) == 0) {
            struct fn_80055304_entry *base = state->entries;
            return base[i].object;
        }
        entry++;
    }
    return 0;
}
static inline char * free_entry_read_pointer(struct fn_80055304_entry * owner) { return owner->text; }
#pragma opt_common_subs off
static inline s32 free_entry(struct fn_80055304_entry *entry) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if (free_entry_read_pointer(entry)[0] == 0) break;
        entry++;
    }
    return i;
}
#pragma opt_common_subs reset


static inline void (* fn_80055304_read_pointer(struct fn_80055304_object * owner))(void (*)(void), u32) { return owner->callback; }
void fn_80055304(char *name, struct fn_80055304_object *(*arg1)(void)) {
    struct fn_80055304_state *state;
    u8 *pool;
    u32 count;
    s32 i;
    char *arg0 = name;
    struct fn_80055304_object *object;
    pool = lbl_80091390;
    (void)*(volatile u32 *)(pool + 0x30);
    state = (struct fn_80055304_state *)&lbl_80187430;
    if (arg0 == 0) {
        if (state->callback != 0) state->callback(state->callback_arg, (u32)(pool + 0xb54), 0);
        return;
    }
    if (arg1 == 0) {
        if (state->callback != 0) state->callback(state->callback_arg, (u32)(pool + 0xb78), 0);
        return;
    }
    count = strlen(arg0) + 1;
    for (i = 0; i < count; i++) {
        if (arg0[i] >= 'a' && arg0[i] <= 'z') arg0[i] -= 0x20;
    }
#pragma opt_propagation on
    object = arg1();
    if (find(arg0, state, strlen(arg0)) == 0) {
        struct fn_80055304_entry *entry;
        i = free_entry(state->entries);
        if (i == 32) {
            object = 0;
        } else {
            entry = state->entries;
            entry += i;
            entry->object = object;
            memcpy(entry->text, arg0, strlen(arg0) + 1);
        }
    }
found:
    if (object == 0) {
        if (state->callback != 0) state->callback(state->callback_arg, (u32)(pool + 0xb9c), 0);
        return;
    }
    if (fn_80055304_read_pointer(object) != 0) object->callback(fn_80055580, 0);
}
