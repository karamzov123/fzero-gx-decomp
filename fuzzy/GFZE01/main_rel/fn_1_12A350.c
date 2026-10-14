/* Non-matching: best partial attempt (92.44% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/archive.h"

typedef struct {
    u32 flags;
    s32 unk_4;
    u32 unk_8;
    u32 unk_C;
} Sig_fn_1_45730_LoadEntry;
typedef struct {
    u8 lab_pad[8];
    u32 unk_0;
    u8 pad_4[0x48];
    Sig_fn_1_45730_LoadEntry entry;
} Sig_fn_1_45730_LoadResult;
extern s32 fn_1_45730(void *, void *);
extern void *fn_1_12A4B0(void *, s32, s32);
extern s32 fn_8006A3DC(void *, void *);
extern void OSPanic(u8 *, s32, u8 *, ...);
extern u32 strlen(const char *);
extern s32 strncmp(const char *, const char *, u32);

u32 fn_1_12A350(void *arg0, s32 arg1) {
    Sig_fn_1_45730_LoadResult result;
    s32 i;
    u32 length;
    s32 compressed;
    u8 *strings = (u8 *)&lbl_1_data_40600;
    s32 lab_t1;
    u8 *lab_t2;
    s32 tmp_call3;

    for (i = 0; i < 64; i++) {
        if (*(s32 *)((u8 *)&lbl_1_bss_897AC + i * 0x6c) == 0) {
            lbl_1_bss_897A0 = i;
            goto found;
        }
    }
    lab_t2 = strings + 0x38;
    OSPanic(strings + 8, 0x7f, lab_t2);
found:
    if (fn_1_45730(arg0, &result) == 1) {
        tmp_call3 = strlen(arg0);
        length = tmp_call3;
        if ((s32)length >= 3 && strncmp((char *)((s32)(((length) + ((char *)arg0))) - 3), (char *)strings + 0x58, 3) == 0) {
            compressed = 1;
        } else {
            compressed = 0;
        }
        if (fn_8006A3DC(fn_1_12A4B0(&result, compressed, arg1),
            (u8 *)&lbl_1_bss_897AC + lbl_1_bss_897A0 * 0x6c + 0x4c) == 0) {
            lab_t1 = 0x94;
            OSPanic(strings + 8, lab_t1, strings + 0x5c);
        }
    } else {
        OSPanic(strings + 8, 0x97, strings + 0x84);
    }
    *(u32 *)((u8 *)&lbl_1_bss_897AC + lbl_1_bss_897A0 * 0x6c) = 1;
    return (u32)lab_t1;
}
