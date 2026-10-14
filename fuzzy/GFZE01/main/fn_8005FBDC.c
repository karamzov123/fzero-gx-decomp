/* Non-matching: best partial attempt (84.52% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

struct Sig_fn_80020CB0_fn_80020CB0_object {
    struct Sig_fn_80020CB0_fn_80020CB0_object *next;
    struct Sig_fn_80020CB0_fn_80020CB0_object *prev;
    u8 pad_8[4];
    u32 index;
};
extern void fn_80020CB0(struct Sig_fn_80020CB0_fn_80020CB0_object *, u32);

typedef struct Fn8005FBDCSource {
    u8 pad_0[0x12];
    s16 value;
} Fn8005FBDCSource;

typedef struct Fn8005FBDCData {
    u8 pad_0[0x1408];
    u8 state;
    u8 mode;
    u8 pad_140a[6];
    u8 count;
    u8 pad_1411[5];
    u16 duration;
    s32 step;
    u8 pad_141c[8];
    Fn8005FBDCSource *source;
    u8 pad_1428[12];
    struct Sig_fn_80020CB0_fn_80020CB0_object *object;
    u8 pad_1438[0x84];
    s32 value;
    s32 target;
} Fn8005FBDCData;

#define ENTRY ((Fn8005FBDCData *)((u8 *)lbl_801A6C80 + arg0 * 0x118))
void fn_8005FBDC(u32 arg0) {
    s16 value;
    if (ENTRY->state != 0xff) {
        ENTRY->mode = 2;
        if (ENTRY->state == 3) {
            ENTRY->step = -960 / ENTRY->duration;
            if (ENTRY->step == 0) {
                ENTRY->step = -1;
            }
        } else {
            value = ENTRY->source->value;
            if (value != 0) {
                ENTRY->value = value << 16;
            } else {
                ENTRY->value = -960 << 16;
            }
            ENTRY->target = -960 << 16;
            ENTRY->duration = 2;
        }
        if (ENTRY->count >= 2 && !(ENTRY->count & 0x80)) {
            ENTRY->count--;
            fn_80020CB0(ENTRY->object, ENTRY->count);
        }
    }
}
