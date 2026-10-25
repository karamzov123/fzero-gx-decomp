/* Non-matching: best partial attempt (55.44% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/game.h"
#pragma cats off
#pragma optimization_level 3
typedef u32 (*Callback)(void *);
typedef struct {
    u32 flags;
    u8 pad4;
    u8 mode;
    u8 arg;
    u8 selection;
    u8 count;
    u8 pad9[0xA7];
    Callback callback;
} Menu;
typedef struct {
    u8 pad0[0x2A];
    s16 state;
    u8 pad2C[4];
    Menu menu;
    u8 rest[0x14E8-0x30-sizeof(Menu)];
    u16 next;
    u8 pad14EA[0x16];
    void *object;
    u8 pad1504[0x163C-0x1504];
    u8 values[0x20];
    u8 entries[0x198];
    u16 result;
} Work;
extern int fn_1_EB200(void);
extern void fn_1_3F2A0(void);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_469BC(void);
extern void fn_1_8DBA4(u8);
extern void fn_1_A2210(u8);
void fn_1_39C60(void) {
    Work *w = (Work *)(u32)&lbl_1_bss_3C00;
    u8 *high = (u8 *)w + 0x20000;
    u32 flags;
    Menu *m;
    u8 n;
    int i;
    u8 *src;
    u8 *values;
    u8 *entries;
    if (fn_1_EB200() != 0) return;
    *(u32 *)(high+0x1F9C) = 0;
    if (w->menu.callback != 0) {
        flags = w->menu.callback(&w->menu);
        if (flags & 4) *(u32 *)(high+0x1F9C) = 1;
        if ((flags & 2) && *(s32 *)(high+0x1FA0) == 0) {
            m = &w->menu;
            w->result = m->selection;
            if (m->mode == 0) {
                for (i=0; i < m->count; i++) {
                    if (*(u32 *)((u8 *)m + 0x1480 + i*4) != 0) {
                        if (!(w->menu.flags & 0x400000)) {
                            fn_1_3F2A0();
                            n = m->count;
                            src = (u8 *)m;
                            values = (u8 *)w + 0x163C;
                            entries = (u8 *)w + 0x165C;
                            i = 0;
                            if (w->state <= 41) {
                                for(; i<n; i++) {
                                    int id = src[0x157];
                                    u8 *entry = w->entries + id*8;
                                    entry[4] = src[0x154];
                                    entry[6] = *values;
                                    entries[id+0x194] = i;
                                    src += 0xA0;
                                    values++;
                                }
                            } else {
                                for(; i<n; i++) {
                                    int id = src[0xDC];
                                    u8 *entry = w->entries + id*8;
                                    entry[4] = src[0x154];
                                    entry[6] = *values;
                                    entries[id+0x194] = i;
                                    src += 0xA0;
                                    values++;
                                }
                            }
                            w->entries[0x192] = n;
                            w->entries[0x191] |= 2;
                            w->entries[0x190] = m->selection;
                            w->menu.flags |= 0x400000;
                            w->result = 14;
                        }
                        break;
                    }
                }
            }
            fn_1_4A00(0,30,w->object);
            *(u32 *)(high+0x1FA0) = 1;
            lbl_1_bss_6EAB4.unk_0 |= 0x2C;
            if(m->mode == 0) lbl_1_data_5B84 = 1;
            fn_1_469BC();
            fn_1_8DBA4(0);
        }
        if(flags & 1) return;
    }
    fn_1_A2210(w->menu.arg);
    if(*(u16 *)(high+0x3068) < 60 || (w->menu.flags & 1))
        w->next = 41;
}
