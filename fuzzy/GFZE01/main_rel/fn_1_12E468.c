/* Non-matching: best partial attempt (64.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/archive.h"

extern void *fn_1_12F118(void);
extern u8 *fn_1_36AD0(void);
extern int fn_1_41488(void *, const char *);
extern void fn_1_933D8(void *, void *, u32);
extern u8 lbl_1_rodata_8180[164];
extern u32 lbl_1_data_40BB0;

typedef struct { u8 pad0[0x18]; u32 flags; } CarFlags;
typedef struct { u8 pad0[0x88]; u32 type; } CarType;
typedef struct { u8 pad0[0x148]; u8 event[4]; } Obj;
typedef struct { u8 pad0[0x150]; struct { u8 pad0[0x24]; void *field; } *event; } MainObj;
typedef struct { void *main; void *others; } Manager;
typedef struct { u32 a[41]; } Copy164;

static s32 translate(s32 index, s32 *table) {
    void *p;
    u8 *q;
    s32 j;
    if (index < 0) return 1;
    if (index < 0x29) return index;
    p = fn_1_12F118();
    if (!p) return 6;
    q = fn_1_36AD0();
    if (p != q) {
        for (j = 0; j < 9; j++) {
            if (((u8 *)p)[j + 5] == index)
                return ((u8 *)p)[j * 0x81c0 + 0x81a0];
        }
        return 6;
    }
    if (index >= 0x32 && index <= 0x35)
        return ((u8 *)p)[(index - 0x32) * 0x81c0 + 0x81a0];
    if (index >= 0x36 && index <= 0x39)
        return ((u8 *)p)[(index - 0x36) * 0x81c0 + 0x81a0];
    for (j = 0; j < 4; j++) {
        if (((u8 *)p)[j + 5] == index)
            return ((u8 *)p)[j * 0x81c0 + 0x81a0];
    }
    return 6;
}
static s32 special(s32 value) {
    if (value == 0x15 || value == 0x29) return 0x15;
    if (value == 0x21 || (value > 0x29 && value < 0x2c)) return 0x21;
    return 0;
}
static s32 quota(s32 value) {
    if (value == 0x15) return 1;
    if (value == 0x21) return 2;
    return 0;
}
void fn_1_12E468(u16 *arg0, Manager *arg1) {
    s32 i, count;
    s32 cur, wanted, val;
    Copy164 copy;
    if (!(lbl_1_bss_8B3A0.unk_94 & 0x80000000)) {
        *arg0 = 2;
        if (*(s16 *)&lbl_1_bss_960 == 2) {
            ((CarFlags *)arg1->main)->flags |= 0x80000000;
            count = 0;
            for (i = 0; ; i++) {
                ((CarFlags *)((u8 *)arg1->others + i * 0x4e0))->flags |= 0x80000000;
                cur = ((CarType *)arg1->main)->type;
                wanted = special(cur);
                if (!wanted) {
                    for (val = 0; val < 0x29; val++) {
                        copy = *(Copy164 *)lbl_1_rodata_8180;
                        if (cur == (s16)copy.a[translate(val, (s32 *)copy.a)]) break;
                    }
                    if (val >= 0x29) val = -1;
                    wanted = special(translate(val, (s32 *)copy.a));
                }
                if (count >= quota(wanted)) break;
                count++;
            }
        } else {
            MainObj *main = (MainObj *)arg1->main;
            s32 n = fn_1_41488(main->event->field, (char *)&lbl_1_data_40BB0);
            fn_1_933D8((void *)main, (void *)((u8 *)main + 0x148), (u16)n);
            count = 0;
            for (i = 0; ; i++) {
                fn_1_933D8((void *)((u8 *)arg1->others + i * 0x4e0),
                           (void *)((u8 *)arg1->others + i * 0x4e0 + 0x148), (u16)n);
                cur = ((CarType *)arg1->main)->type;
                wanted = special(cur);
                if (!wanted) {
                    for (val = 0; val < 0x29; val++) {
                        copy = *(Copy164 *)lbl_1_rodata_8180;
                        if (cur == (s16)copy.a[translate(val, (s32 *)copy.a)]) break;
                    }
                    if (val >= 0x29) val = -1;
                    wanted = special(translate(val, (s32 *)copy.a));
                }
                if (count >= quota(wanted)) break;
                count++;
            }
        }
    }
}
