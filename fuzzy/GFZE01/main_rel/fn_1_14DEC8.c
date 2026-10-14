/* Non-matching: best partial attempt (91.46% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    s16 id;
    u8 pad[0x35E];
} Entry;

typedef struct {
    void **value;
} Inner;

typedef struct {
    u8 pad8[8];
    Inner *inner;
} Ref;

typedef struct {
    u8 pad344[0x344];
    Ref *ref;
} Record;

extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0(void);
extern s16 fn_1_14F344(s16);
extern void fn_80072558(void);
extern void fn_1_151C3C(int, s16);
extern void fn_1_556B8(void *);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);

static inline Ref * fn_1_14DEC8_read_pointer(Record * owner) { return owner->ref; }
#pragma opt_lifetimes off
void fn_1_14DEC8(Record *arg0, void **arg1, void **arg2, s16 arg3, int arg4, f32 arg5) {
    void *found2;
    s16 i;
    Record *obj;
    Entry *entry;
    void *found1;
    int same;
    void *value;

    same = (lbl_1_rodata_9C30 == arg5);
    if (same == 0) {
        fn_1_55FF0();
    }

    entry = (Entry *)arg0;
    obj = (Record *)((u8 *)arg0 + ((s32)arg3 << 2));
    for (i = 0; (u32)i < 3; i++) {
        if (fn_1_14F344(entry->id) == 0) {
            value = fn_1_14DEC8_read_pointer(obj)->inner->value;
            if (value != 0) {
                fn_80072558();
                fn_1_151C3C(0, ((Entry *)arg0)[i].id);
                if (same != 0 || arg4 != 0) {
                    fn_1_556B8(value);
                } else {
                    fn_1_55210(value);
                }
                found1 = 0;
                fn_1_151C78();
                entry = (Entry *)arg0;
                for (i = 0; (u32)(u32)i < 3; i++) {
                    if (fn_1_14F344(entry->id) == 0) {
                        found1 = (void *)((((i * 0x360) + ((u8 *)arg0)) + (0x23c)));
                        break;
                    }
                    entry++;
                }
                *arg1 = found1;
                found2 = 0;
                entry = (Entry *)arg0;
                for (i = 0; (u32)(s32)i < 3; i++) {
                    if (fn_1_14F344(entry->id) == 0) {
                        found2 = (void *)(((i * 0x360) + ((0x228) + ((u8 *)arg0))));
                        break;
                    }
                    entry++;
                }
                *arg2 = found2;
                break;
            }
        }
        entry++;
        obj = (Record *)((u8 *)obj + 0x360);
    }
}
#pragma opt_lifetimes reset

