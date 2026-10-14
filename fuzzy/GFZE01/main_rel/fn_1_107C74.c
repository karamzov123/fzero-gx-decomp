/* Non-matching: best partial attempt (96.37% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec107C74;

typedef struct {
    u8 pad_0[0xC];
    Vec107C74 unk_C;
    f64 unk_18;
    f32 unk_20;
} Rodata7AB8;

typedef struct {
    u8 pad_0[0x48];
    f32 unk_48;
    f32 unk_4C;
} Sub150B;

typedef struct {
    u8 pad_0[0x8];
    u8 *unk_8;
} Sub150;

typedef struct Owner107C74 {
    u8 pad_0[0x8C];
    s32 unk_8C;
    s32 unk_90;
    u8 pad_94[0xBC];
    Sub150 *unk_150;
} Owner107C74;

typedef struct {
    u8 unk_00[0x8];
    u32 unk_08;
    Owner107C74 *unk_0C;
    u8 unk_10[0x24];
    u8 unk_34[0x34];
} Entry107C74;

typedef void (*EntryFn107C74)(Entry107C74 *);

extern f32 lbl_1_rodata_7AB8[9];
extern void fn_1_1088B8(void *arg);
extern u32 fn_1_107930(void *);
extern u32 lbl_1_bss_88B4C;
extern void fn_1_107E90(Entry107C74 *);
extern void lbl_8006DBAC(void *arg);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void lbl_8006DD14(void *, void *);
extern f64 __fabs(f64);

static inline void fn_1_107C4C_inl(void *arg) {
    if (arg != 0) {
        fn_1_1088B8(arg);
    }
}

static inline void call_entry_inl(EntryFn107C74 *t, Entry107C74 *e) {
    t[e->unk_08](e);
}

static inline u32 fn_1_107C74_array_read(u32 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments off
static inline u8 * fn_1_107C74_read_pointer(Entry107C74 * owner) { return owner->unk_0C->unk_150->unk_8; }
#pragma opt_loop_invariants off
static inline f32 fn_1_107C74_read_pointer_(Vec107C74 * owner) { return owner->x; }
#pragma opt_common_subs off
void fn_1_107C74(Owner107C74 *arg0) {
    Rodata7AB8 *ro = (Rodata7AB8 *)&lbl_1_rodata_7AB8;
    u8 *data = (u8 *)&lbl_1_data_3F510;
    struct { u8 *value; } tbl;
    u32 j;
    Entry107C74 *entry;
    u8 *obj;
    s32 i;
    EntryFn107C74 *fns2;
    u32 k;
    Vec107C74 b;
    Vec107C74 a;
    f32 len;
    f32 dx;
    f32 dy;
    f32 dz;

    if (arg0 == 0) {
        return;
    }
    if (arg0->unk_8C != arg0->unk_90) {
        arg0->unk_90 = arg0->unk_8C;
        fn_1_107C4C_inl(arg0);
        fn_1_107930(arg0);
        return;
    }
    tbl.value = data + 0xC34;
    for (j = 0; j < 0x40; j++) {
        entry = (Entry107C74 *)&lbl_1_bss_86ED0;
        for (i = 0; i < 70; i++, entry++) {
            if (entry->unk_0C != 0 && entry->unk_0C == arg0 && j == tbl.value[entry->unk_08]) {
                u32 *idx = (u32 *)data + 0x2AB;
                obj = fn_1_107C74_read_pointer(entry) + fn_1_107C74_array_read(idx, entry->unk_08) * 0x18C;
                lbl_1_bss_88B4C = 0;
                if (__fabs(((Sub150B *)arg0->unk_150)->unk_4C - ((Sub150B *)arg0->unk_150)->unk_48) <= ro->unk_18) {
                    a = ro->unk_C;
                    b = ro->unk_C;
                    lbl_8006DBAC(obj + 0x88);
                    lbl_8006E1B0(&b, &b);
                    lbl_8006DBAC(entry->unk_34);
                    lbl_8006E1B0(&a, &a);
                    dx = fn_1_107C74_read_pointer_(&b) - a.x;
                    dy = b.y;
                    dy = dy - a.y;
                    dz = b.z - a.z;
                    b.x = dx;
                    b.y = dy;
                    b.z = dz;
                    lbl_1_bss_88B4C = 1;
                    len = (f32)(dx * dx) + dy * dy + dz * dz;
                    if (len > ro->unk_20) {
                        fn_1_107E90(entry);
                        k = 0;
                        fns2 = (EntryFn107C74 *)(data + 0xE20);
                        for (; k < 60; k++) {
                            fns2[entry->unk_08](entry);
                        }
                    }
                    lbl_1_bss_88B4C = 0;
                }
                call_entry_inl((EntryFn107C74 *)(data + 0xE20), entry);
                lbl_8006DD14(obj + 0x88, entry->unk_34);
                break;
            }
        }
    }
}
#pragma opt_common_subs reset

#pragma opt_loop_invariants reset

#pragma opt_dead_assignments reset
