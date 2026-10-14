/* Non-matching: best partial attempt (84.54% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieDCTInfo {
    u32 head[8];
    u32 perm[4];
    u8  pad[0x130];
    u32 quant[8];
    u32 flags[12];
} MovieDCTInfo;

extern u8 lbl_12_rodata_6A0[0xC0];
extern u8 lbl_12_bss_4E00[0x40];
extern u8 lbl_12_bss_4DC0[0x40];
extern u32 lbl_12_bss_68F4;
extern u32 lbl_12_bss_68F8;
extern u32 lbl_12_bss_68FC;
extern u32 lbl_12_bss_6900;
extern u32 lbl_12_bss_6904;
extern u32 lbl_12_bss_6908;
extern void * memcpy(void *, const void *, u32);
extern void DCT_FsriInitScanTbl(const signed char *, signed char *);
extern void fn_12_33364(u32 *, u32 *, u32);

static inline u32 * fn_12_6FEC_read_pointer(MovieDCTInfo * owner) { return owner->flags; }
void fn_12_6FEC(MovieDCTInfo *arg0) {
    u8 tbl[0x40];
    u8 work[0x40];
    struct { u8 *value; } base;
    u8 *tblp;
    u8 *dst;
    u8 *srcp;
    u8 *wp;
    u8 *inv;
    s32 i;
    base.value = (u8 *)lbl_12_rodata_6A0;

    for (i = 0; i < 0x40; i++) {
        tbl[i] = (u8)i;
    }
    DCT_FsriInitScanTbl((const signed char *)tbl, (signed char *)work);
    tblp = base.value;
    tblp += 0x20;
    srcp = base.value + 0x60;
    dst = lbl_12_bss_4E00;
    inv = lbl_12_bss_4DC0;
    wp = work;
    for (i = 0; i < 0x40; i++) {
        *dst++ = work[(s8)*tblp++];
        inv[(s8)*wp++] = *srcp++;
    }
    if (arg0 + 0x20) {
        fn_12_33364((u32 *)arg0 + 8, (u32 *)lbl_12_bss_4E00, 0x10);
    }
    if (arg0) {
        fn_12_33364((u32 *)arg0, (u32 *)base.value, 8);
    }
    memcpy(&arg0->quant[0], &base.value[0xA0], 0x20);
    fn_12_6FEC_read_pointer(arg0)[0] = lbl_12_bss_68F4 - 0x10;
    fn_12_6FEC_read_pointer(arg0)[1] = 0x15;
    fn_12_6FEC_read_pointer(arg0)[2] = lbl_12_bss_68F8 - 0x20;
    fn_12_6FEC_read_pointer(arg0)[3] = 0x13;
    fn_12_6FEC_read_pointer(arg0)[4] = lbl_12_bss_68FC - 0x20;
    fn_12_6FEC_read_pointer(arg0)[5] = 0x12;
    fn_12_6FEC_read_pointer(arg0)[6] = lbl_12_bss_6900 - 0x20;
    fn_12_6FEC_read_pointer(arg0)[7] = 0x11;
    fn_12_6FEC_read_pointer(arg0)[8] = lbl_12_bss_6904 - 0x20;
    fn_12_6FEC_read_pointer(arg0)[9] = 0x10;
    fn_12_6FEC_read_pointer(arg0)[10] = lbl_12_bss_6908 - 0x20;
    fn_12_6FEC_read_pointer(arg0)[11] = 0xF;
}
