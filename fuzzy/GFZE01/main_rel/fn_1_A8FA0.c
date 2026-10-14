/* Non-matching: best partial attempt (73.81% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"

extern char * fn_80083DB0(char *, const char *);
extern size_t strlen(const char *);
extern void * memset(void *dest, int c, unsigned long n);

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
    u8 pad_A[2];
    u32 unk_C;
} Entry_1_A8FA0;

#define ENTRIES ((Entry_1_A8FA0 *)((u8 *)obj + 0x1010))
#define COUNT (*(s32 *)((u8 *)obj + 0x2010))

void fn_1_A8FA0(void) {
    Obj_1_bss_6F648 *obj = &lbl_1_bss_6F648;
    u32 *fields = (u32 *)((u8 *)obj + 0);
    Entry_1_A8FA0 *entries = ENTRIES;
    s32 flags[256];
    Entry_1_A8FA0 *out = entries;
    s32 n = 0;
    s32 i;
    s32 j;

    fields[3] = (u32)((u8 *)obj + 0x10);

    for (i = 0; i < COUNT; i++) {
        if (entries[i].unk_2 & 1) {
            char *name = (char *)entries[i].unk_C;
            size_t len = strlen(name);
            u32 h;
            u32 next;

            if (i != 0) {
                *out = entries[i];
                fn_80083DB0((char *)fields[3], name);
            }
            h = fields[3];
            n++;
            next = (u32)len + h;
            out->unk_C = h;
            fields[3] = next + 1;
            out++;
        }
    }
    COUNT = n;

    memset(flags, 0, (unsigned long)n * 4);

    for (i = n - 1; i >= 1; i--) {
        if (flags[i] == 0) {
            for (j = i - 1; j >= 0; j--) {
                if (ENTRIES[i].unk_4 == ENTRIES[j].unk_4 && ENTRIES[i].unk_6 == ENTRIES[j].unk_6
                    && ENTRIES[i].unk_2 == ENTRIES[j].unk_2 && ENTRIES[i].unk_0 == ENTRIES[j].unk_0) {
                    flags[j] = 1;
                }
            }
        }
    }

    fields[3] = (u32)((u8 *)obj + 0x10);

    n = 0;
    out = entries;

    for (i = 0; i < COUNT; i++) {
        if (flags[i] == 0) {
            char *name = (char *)entries[i].unk_C;
            size_t len = strlen(name);
            u32 h;
            u32 next;

            if (i != 0) {
                *out = entries[i];
                fn_80083DB0((char *)fields[3], name);
            }
            h = fields[3];
            n++;
            next = (u32)len + h;
            out->unk_C = h;
            fields[3] = next + 1;
            out++;
        }
    }
    COUNT = n;
}
