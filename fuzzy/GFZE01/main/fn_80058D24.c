/* Non-matching: best partial attempt (80.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

typedef u32 (*fn_80058D24_Fn)(u32);

typedef struct {
    u8 lab_pad[4];
    fn_80058D24_Fn fn;
    u32 arg;
} fn_80058D24_Entry;

typedef struct {
    u8 pad_0[0xF0];
    fn_80058D24_Entry entries[6];
} fn_80058D24_Table;

typedef struct {
    u8 pad_0[0x14];
    u32 value;
} fn_80058D24_Flag;

typedef struct {
    u8 pad_0[0x108];
    fn_80058D24_Table table;
    u8 pad_228[0x60];
    fn_80058D24_Flag flag;
    u8 pad_2A0[0x8];
    fn_80058D24_Flag counter;
} fn_80058D24_Obj;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_8018FEB0[12];
u32 lbl_8018FEE0[32];
u32 lbl_8018FF60[2];
u32 lbl_8018FF68[2];
u32 lbl_8018FF70[2];
u32 lbl_8018FF78_fill_8018FF78[16];
fn_80058D24_Table lbl_8018FF78_40;
u32 lbl_8018FF78_fill_801900D8[24];
fn_80058D24_Flag lbl_8018FF78_1C0;
u32 lbl_8018FF78_fill_80190150[2];
fn_80058D24_Flag lbl_8018FF78_1E0;
u32 lbl_8018FF78_fill_80190170[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_8018FEB0;
    s = *(u8 *)&lbl_8018FEE0;
    s = *(u8 *)&lbl_8018FF60;
    s = *(u8 *)&lbl_8018FF68;
    s = *(u8 *)&lbl_8018FF70;
    s = *(u8 *)&lbl_8018FF78_fill_8018FF78;
    s = *(u8 *)&lbl_8018FF78_40;
    s = *(u8 *)&lbl_8018FF78_fill_801900D8;
    s = *(u8 *)&lbl_8018FF78_1C0;
    s = *(u8 *)&lbl_8018FF78_fill_80190150;
    s = *(u8 *)&lbl_8018FF78_1E0;
    s = *(u8 *)&lbl_8018FF78_fill_80190170;
}
#pragma section code_type ".text"

u32 fn_80058D24(void) {
    struct { u32 value; } result;
    s32 i;
    fn_80058D24_Flag *fl;
    fn_80058D24_Entry *e;
    fn_80058D24_Fn f;

    
    fl = &lbl_8018FF78_1C0;
    e = lbl_8018FF78_40.entries;
    result.value = 0;

    for (i = 0; i < 6; i++) {
        f = e[i].fn;
        if (f != 0) {
            fl->value = 1;
            result.value |= f(e[i].arg);
            fl->value = 0;
        }
    }

    (&lbl_8018FF78_1E0)->value++;
    return result.value;
}
