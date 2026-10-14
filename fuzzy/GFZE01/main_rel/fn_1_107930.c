/* Non-matching: best partial attempt (98.67% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_common.h"

typedef struct {
    u8 pad_0[0xc];
    u32 unk_c;
    u8 pad_10[0x58];
} Sig_fn_1_108870_fn_1_108870_AccessoryEntry;

typedef void (*fn_1_107930_Fn0)(Sig_fn_1_108870_fn_1_108870_AccessoryEntry *, void *);

typedef struct { void *unk_0; char *unk_4; } AccessoryModel;
typedef struct { u32 unk_0; u32 unk_4; AccessoryModel *unk_8; } AccessoryList;
typedef struct { u8 pad_0[0x88]; s32 unk_88; s32 unk_8C; u8 pad_90[0x54]; AccessoryList *unk_E4[3]; } AccessoryObject;
typedef struct { u32 unk_0, unk_4, unk_8; } AccessoryVec;

extern Sig_fn_1_108870_fn_1_108870_AccessoryEntry *fn_1_108870(void);
extern u8 *fn_80083970(u8 *, const u8 *);
extern int fn_80083BCC(const char *, const char *);
extern int sprintf(char *, const char *, ...);
extern f32 lbl_1_rodata_7AB8[9];
extern u32 lbl_1_bss_88B40[3];

#pragma opt_dead_assignments off
static inline void * fn_1_107930_read_pointer(AccessoryModel * owner) { return owner->unk_0; }
#pragma opt_dead_assignments reset

#pragma opt_loop_invariants off
static inline AccessoryList * * fn_1_107930_read_pointer_(AccessoryObject * owner) { return owner->unk_E4; }
static inline AccessoryModel * fn_1_107930_read_pointer__(AccessoryList * owner) { return owner->unk_8; }
#pragma opt_lifetimes off

void fn_1_107930(AccessoryObject *arg0) {
    struct {
    u8 lab_pad[4]; s32 value; } v9;
    Obj_1_bss_8B3A0 *p_lbl_1_bss_8B3A0;
    u32 v17;
    u32 v8;
    struct { s32 value; } v5;
    u32 i;
    AccessoryList *v1;
    const char **names;
    s32 *ids;
    s32 v11;
    u32 v24;
    void *v19;
    void *v25;
    AccessoryModel *v7;
    u8 *p_lbl_1_data_3F510 = lbl_1_data_3F510;
    fn_1_107930_Fn0 *table;
    s32 tmp_ra3;

    if (!arg0) return;
    if (arg0->unk_8C != 0 && (u32)(arg0->unk_8C-1) > 1) return;
    v1 = fn_1_107930_read_pointer_(arg0)[arg0->unk_8C];
    if (!v1) return;
    v5.value = 1;
    ids = (s32 *)(p_lbl_1_data_3F510 + 0x924);
    { u32 count = *(u32 *)(p_lbl_1_data_3F510 + 0xFA8);
    for (i = 0; i < count; i++) {
        if (arg0->unk_88 == ids[i]) { v5.value = 0; break; }
    }
    }
    if (v5.value) return;
    p_lbl_1_bss_8B3A0 = &lbl_1_bss_8B3A0;
    v7 = fn_1_107930_read_pointer__(v1);
    for (v8 = 0; v8 < v1->unk_0; v8++, v7++) {
        if (!v7) continue;
        if (!fn_80083970((u8 *)v7->unk_4, p_lbl_1_data_3F510 + 0xFFC)) continue;
        if (fn_80083BCC(v7->unk_4, (char *)p_lbl_1_data_3F510 + 0x650) == 0 && *(s16 *)&lbl_1_bss_960 == 1 && p_lbl_1_bss_8B3A0->unk_4 == 4) continue;
        if (fn_80083BCC(v7->unk_4, (char *)p_lbl_1_data_3F510 + 0x660) == 0 && *(s16 *)&lbl_1_bss_960 == 1 && p_lbl_1_bss_8B3A0->unk_4 == 4) continue;
        if (fn_80083BCC(v7->unk_4, (char *)p_lbl_1_data_3F510 + 0x670) == 0 && *(s16 *)&lbl_1_bss_960 == 1 && p_lbl_1_bss_8B3A0->unk_4 == 4) continue;
        tmp_ra3 = arg0->unk_8C;
        if (tmp_ra3 == 2) {
            ids = (s32 *)(p_lbl_1_data_3F510 + 0xFAC);
            v9.value = 0;
            for (v11 = 0; v11 < *(u32 *)(p_lbl_1_data_3F510 + 0xFF8); v11++) {
                if (fn_80083BCC(v7->unk_4, ((const char **)ids)[v11]) == 0) v9.value = 1;
            }
        } else v9.value = 1;
        if (!v9.value) continue;
        ids = (s32 *)(p_lbl_1_data_3F510 + 0x924);
        names = (const char **)(p_lbl_1_data_3F510 + 0x79C);
        v11 = 1;
        for (v17 = 0; v17 < *(u32 *)(p_lbl_1_data_3F510 + 0xFA8); v17++) {
            if (arg0->unk_88 == ids[v17] && fn_80083BCC(v7->unk_4, names[v17]) == 0) { v11 = 0; break; }
        }
        if (v11) continue;
        v19 = v7->unk_0;
        if (!v19) continue;
        v25 = 0;
        names = (const char **)((u32)p_lbl_1_data_3F510 + 0x79C);
{
    struct { u32 a[64]; } loc_8;
        sprintf((char *)&loc_8, (char *)p_lbl_1_data_3F510 + 0x1004, names[v17]);
{
    AccessoryModel *v23;
        v23 = fn_1_107930_read_pointer__(v1);
        ids = (s32 *)((u32)p_lbl_1_data_3F510 + 0x924);
        for (v24 = 0; v24 < v1->unk_0; v24++, v23++) {
            if (arg0->unk_88 == ids[v17] && fn_80083BCC(v23->unk_4, (char *)&loc_8) == 0) { v25 = fn_1_107930_read_pointer(v23); break; }
}
}
        }
{
    Sig_fn_1_108870_fn_1_108870_AccessoryEntry *entry;
        entry = fn_1_108870();
        if (entry) {
            *(u32 *)((u8 *)entry + 8) = v17;
            entry->unk_c = (u32)arg0;
            *(void **)((u8 *)entry + 0x10) = v19;
            entry->pad_0[0] = 2;
            *(void **)((u8 *)entry + 0x30) = v25;
            *(s32 *)((u8 *)entry + 4) = arg0->unk_8C;
        }
        table = (fn_1_107930_Fn0 *)((u32)p_lbl_1_data_3F510 + 0xC98);
        table[*(u32 *)((u8 *)entry + 8)](entry, table);
}
    }
    *(AccessoryVec *)lbl_1_bss_88B40 = *(AccessoryVec *)lbl_1_rodata_7AB8;
}
#pragma opt_lifetimes reset
#pragma opt_loop_invariants reset
