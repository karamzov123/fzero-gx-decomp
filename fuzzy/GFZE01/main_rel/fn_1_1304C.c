/* Non-matching: best partial attempt (46.39% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/live_camera.h"

typedef struct {
    u32 flags;
    s32 unk_4;
    u32 unk_8;
    u32 unk_C;
} Sig_fn_1_45730_LoadEntry;
typedef struct {
    u32 unk_0;
    u8 pad_4[0x48];
    Sig_fn_1_45730_LoadEntry entry;
} Sig_fn_1_45730_LoadResult;
typedef struct {
    s32 kind;
    u8 pad[0x54];
    void *value;
} Sig_fn_1_45B2C_Fn145B2CData;

struct fn_1_1304C_Arg0 {
    u8 pad_0[0x80];
    u32 unk_80;
    u32 unk_84;
};
extern int fn_1_45730(void *, Sig_fn_1_45730_LoadResult *);
extern void *fn_1_45D0(void *, u32, const char *, int);
extern int fn_1_45850(void *);
extern void fn_1_46B4(void *, u32, const char *, int);
extern u32 fn_1_1361C(Sig_fn_1_45B2C_Fn145B2CData *, void *);
extern void fn_80008BA8(void *, const void *, u32);
extern void *lbl_801A6410;
extern u32 lbl_1_data_5184;
extern char lbl_1_data_5188[];
extern u8 lbl_1_bss_1800[];

u32 *fn_1_1304C(struct fn_1_1304C_Arg0 *arg0, u32 arg1) {
    u8 path[0x5c];
    u32 alloc1;
    u32 alloc2;
    u32 header[2];
    u8 window[0x1000];
    u32 src_end;
    u32 out_size;
    u32 inpos;
    u32 winpos;
    u32 flags;
    u8 *out;
    u32 i;
    u32 j;

    lbl_1_bss_1800[0x2328] = 0;
    lbl_1_bss_1800[0x232c] = 0;
    lbl_1_bss_1800[0x23b8] = 0;

    if (arg1 != 0) {
        fn_80008BA8(path, (void *)arg1, 0x5c);
    } else if (fn_1_45730(arg0, (Sig_fn_1_45730_LoadResult *)path) == 0) {
        return 0;
    }

    alloc1 = (u32)fn_1_45D0(lbl_801A6410, *(u32 *)lbl_1_data_5184,
                            lbl_1_data_5188, 0x243);
    alloc2 = (u32)fn_1_45D0(lbl_801A6410, *(u32 *)lbl_1_data_5184,
                            lbl_1_data_5188, 0x244);
    header[0] = header[1] = 0;
    for (i = 0; i < 8; i++) {
        u32 c = fn_1_1361C((Sig_fn_1_45B2C_Fn145B2CData *)path, (void *)header);
        if (i < 4) header[0] = (header[0] << 8) | (c & 0xff);
        else header[1] = (header[1] << 8) | (c & 0xff);
    }
    out_size = __lwbrx(header, header[1]);
    src_end = __lwbrx(header, 4);
    if ((s32)(out_size + 8) == 0 || src_end == 0) {
        return 0;
    }

    out = (u8 *)arg0->unk_80;
    for (i = 0; i < 0x1000; i++) window[i] = 0;
    inpos = 8;
    winpos = 0xfee;
    flags = 0;
    while (inpos < out_size + 8) {
        flags >>= 1;
        if ((flags & 0x100) == 0) {
            if (inpos >= out_size + 8) break;
            flags = (fn_1_1361C((Sig_fn_1_45B2C_Fn145B2CData *)path, (void *)header) & 0xff) | 0xff00;
            inpos++;
        }
        if (flags & 1) {
            u8 c;
            if (inpos >= out_size + 8) break;
            c = (u8)fn_1_1361C((Sig_fn_1_45B2C_Fn145B2CData *)path, (void *)header);
            inpos++;
            *out++ = c;
            window[winpos] = c;
            winpos = (winpos + 1) & 0xfff;
        } else {
            u32 a, b, offset, len;
            if (inpos >= out_size + 8) break;
            a = fn_1_1361C((Sig_fn_1_45B2C_Fn145B2CData *)path, (void *)header);
            inpos++;
            if (inpos >= out_size + 8) break;
            b = fn_1_1361C((Sig_fn_1_45B2C_Fn145B2CData *)path, (void *)header);
            inpos++;
            offset = ((b & 0xf) << 8) | a;
            len = (b >> 4) + 2;
            for (j = 0; j < len; j++) {
                u8 c = window[(offset + j) & 0xfff];
                *out++ = c;
                window[winpos] = c;
                winpos = (winpos + 1) & 0xfff;
            }
        }
    }
    fn_1_45850(path);
    fn_1_46B4(lbl_801A6410, alloc2, lbl_1_data_5188, 0x277);
    fn_1_46B4(lbl_801A6410, alloc1, lbl_1_data_5188, 0x278);
    if (arg0->unk_84 != 0) {
        ((void (*)(u32))arg0->unk_84)(src_end);
    }
    return (u32 *)&src_end;
}
