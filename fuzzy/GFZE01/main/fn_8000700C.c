/* Non-matching: best partial attempt (86.36% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern char * fn_80083DB0(char *, const char *);
extern char * strcat(char *, const char *);
extern int fn_80083BCC(const char *, const char *);
extern s32 fn_80016DF8(const char *);
extern size_t strlen(const char *);
extern u8 lbl_8015BD40[256];
extern char lbl_801A63F8[2];
extern u32 lbl_801A66F8;
extern u32 lbl_801A66FC;
extern u32 lbl_801A6700;
extern u32 lbl_801A6704;
static char fzgx_pool_strings_lbl_801220C0_0[12] = "file:%s\n";
static char fzgx_pool_strings_lbl_801220C0_C[20] = "open from DVD...";
static char fzgx_pool_strings_lbl_801220C0_20[16] = "entry num:%08x\n";
static char fzgx_pool_strings_lbl_801220C0_30[20] = "reading from DVD...";
static char fzgx_pool_strings_lbl_801220C0_44[20] = "done(%x bytes).\n";
static char fzgx_pool_strings_lbl_801220C0_58[12] = "avfile.c";
static char fzgx_pool_strings_lbl_801220C0_64[28] = "FileReadAsync Buffer Over.\n";
static char fzgx_pool_strings_lbl_801220C0_80[32] = "no initialize entrynum_buffer";
static char fzgx_pool_strings_lbl_801220C0_A0[16] = "filename:%s\n";
static char fzgx_pool_strings_lbl_801220C0_B0[16] = "nowdir  :%s\n";
static char fzgx_pool_strings_lbl_801220C0_C0[16] = "fullname:%s\n";
static char fzgx_pool_strings_lbl_801220C0_D0[12] = "%s -> %08x\n";

extern void OSPanic(const char *, int, const char *, ...);
extern void fn_80006BDC(int, ...);

#pragma opt_common_subs off
#pragma opt_lifetimes off
static inline u8 fn_8000700C_array_read(s32 index, u8 *array) { return array[index]; }
#pragma opt_dead_assignments off
s32 fn_8000700C(char *arg0) {
    
    u8 *walk;
    char * arg0_local = arg0;
    char *name;
    u32 result;
    s32 idx;
    u32 off;
    struct { u32 a[34]; } buf;
    char * lab_t0;

    
    name = arg0_local;
    if (lbl_801A66F8 == 0) {
        result = (u32)fn_80016DF8((const char *)arg0_local);
    } else {
        if (lbl_801A6704 == 0) {
            OSPanic((const char *)(((u8 *)fzgx_pool_strings_lbl_801220C0_58)), 749, (const char *)(((u8 *)fzgx_pool_strings_lbl_801220C0_80)));
        }
        if ((u32)name[0] == '/') {
            walk = (u8 *)name + 1;
            result = 1;
            while (result < strlen((const char *)name) + 1) {
                if (fn_8000700C_array_read(0, walk) != '/') {
                    lab_t0 = (char *)&buf;
                    fn_80083DB0(lab_t0, (const char *)((name + result) - 1));
                    break;
                }
                result++;
                walk++;
            }
        } else {
            lab_t0 = (char *)&buf;
            fn_80083DB0(lab_t0, (const char *)lbl_8015BD40);
            if (fn_8000700C_array_read(0, lbl_8015BD40) != '/' || fn_8000700C_array_read(1, lbl_8015BD40) != 0) {
                strcat((char *)&buf, (const char *)lbl_801A63F8);
            }
            strcat((char *)&buf, (const char *)name);
        }
        fn_80006BDC((int)(((u8 *)fzgx_pool_strings_lbl_801220C0_A0)), (int)name);
        fn_80006BDC((int)(((u8 *)fzgx_pool_strings_lbl_801220C0_B0)), (int)lbl_8015BD40);
        fn_80006BDC((int)(((u8 *)fzgx_pool_strings_lbl_801220C0_C0)), (int)&buf);
        idx = 0;
        result = -1;
        off = 0;
        while (idx < (s32)lbl_801A66FC) {
            if (fn_80083BCC(*(char **)((u8 *)lbl_801A6700 + off), (const char *)&buf) == 0) {
                result = idx | 0x7FFF0000;
                break;
            }
            off += 4;
            idx++;
        }
        fn_80006BDC((int)(((u8 *)fzgx_pool_strings_lbl_801220C0_D0)), (int)&buf, (int)(((0x7FFF0000) | (result))));
    }
    return (s32)result;
}
#pragma opt_dead_assignments reset

#pragma opt_lifetimes reset

#pragma opt_common_subs reset

