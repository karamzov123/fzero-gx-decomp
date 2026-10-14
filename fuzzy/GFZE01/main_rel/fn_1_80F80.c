/* Non-matching: best partial attempt (99.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/car.h"

typedef struct {
    u32 unk_0;
    u32 unk_4;
} CarSlot;

typedef struct {
    u8 unk_0[0x324];
    const char *unk_names[703];
    u8 unk_e20[0x624];
    char unk_1444[0x10];
    char unk_1454[0x0C];
    char unk_1460[0x10];
    char unk_1470[0x10];
} CarData;

extern void fn_1_12AB38(void *);
extern u32 fn_1_12AC00(void *);
extern u32 fn_1_12ADA0(void *, u32);
extern char *fn_80083DB0(char *, const char *);
extern int sprintf(char *, const char *, ...);

#pragma opt_lifetimes off
void fn_1_80F80(CarSlot *arg0, s16 arg1, s16 arg2)
{
    CarData *data = (CarData *)&lbl_1_data_1F1D8;
    const char **rows = (const char **)data;
    char text[0x40];
    char name[0x40];
    s16 i;
    CarSlot *slot;

    rows = (const char **)((u8 *)rows + 0x324);

    fn_80083DB0(name, rows[arg1]);
    fn_1_12AB38(name);

    for (i = 0; i < 3; i++) {
        slot = &arg0[i];
        if (arg2 & (1 << i)) {
            if (slot->unk_0 == 0) {
                if (i) {
                    fn_80083DB0(name, rows[arg1]);
                    sprintf(text, data->unk_1444, name, i + 1);
                } else {
                    fn_80083DB0(name, rows[arg1]);
                    sprintf(text, data->unk_1454, name);
                }
                slot->unk_4 = fn_1_12AC00(text);
                if (i) {
                    fn_80083DB0(name, rows[arg1]);
                    sprintf(text, data->unk_1460, name, i + 1);
                } else {
                    fn_80083DB0(name, rows[arg1]);
                    sprintf(text, data->unk_1470, name);
                }
                slot->unk_0 = fn_1_12ADA0(text, slot->unk_4);
            }
        }
    }
    fn_1_12AB38(data->unk_e20);
}
#pragma opt_lifetimes reset

