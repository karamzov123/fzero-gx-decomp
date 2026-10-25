/* Non-matching: best partial attempt (86.93% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/phys.h"
typedef struct { u32 flags; s32 unk_4; u32 unk_8; u32 unk_C; } Sig_fn_1_45730_LoadEntry;
typedef struct { u32 unk_0; u8 pad_4[0x48]; Sig_fn_1_45730_LoadEntry entry; } Sig_fn_1_45730_LoadResult;
typedef struct Sig_fn_1_45B2C_Fn145B2CData { s32 kind; u8 pad[0x54]; void *value; } Sig_fn_1_45B2C_Fn145B2CData;
struct Sig_fn_1_458A0_fn_1_458A0_Arg0 { u32 unk_0; u8 pad_4[0x50]; u32 unk_54; };
struct Sig_fn_1_45850_fn_1_45850_Arg0 { u32 unk_0; };
extern u32 lbl_801A6410;
extern u32 fn_1_3F8C0(void);
extern u32 fn_80008E84(u32);
extern void *fn_1_4630(u32, u32, void *, u32);
extern void *fn_1_435C(void *);
extern u32 fn_1_E9BA8(void);
extern void fn_1_E9C68(void);
extern s32 fn_1_3F8C(void *, void *, u32, u32);
extern int sprintf(char *, const char *, ...);
extern s32 DVDConvertPathToEntrynum(const char *);
extern void OSReport(const char *, ...);
extern s32 fn_1_45730(void *, void *);
extern s32 fn_1_45B2C(void *);
extern void fn_1_458A0(void *, void *, u32, u32);
extern void fn_1_45850(void *);
extern void fn_1_F0508(void);
extern void fn_1_F1D8C(s32);
extern void fn_1_F1A24(void);
extern void DCFlushRange(void *, u32);
extern void fn_80008BEC(void *, int, int);
#define W(o) (*(u32 *)(base + (o)))
#define S(o) (*(s32 *)(base + (o)))
#define B(o) (*(u8 *)(base + (o)))
#define D(o) (*(s32 *)(data + (o)))
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma opt_lifetimes off
void fn_1_E9770(void *arg0, void *arg1, u32 arg2, u32 arg3) {
    s32 tmp_call7;
    u8 *data;
    u8 *base;
    s16 v0;
    u32 *v3;
    u32 *v4;
    u32 *v5;
    u32 *v6;
    s32 v12;
    void *p;
    char loc_1C0[0x100];
    char loc_C0[0x100];
    u8 loc_64[0x5c];
    u8 loc_8[0x5c];
    int i;
    s32 tmp_call2;
    s32 tmp_call9;
    s32 tmp_call16;
    char * lab_t0;
    data = lbl_1_data_3E358;
    base = (u8 *)&lbl_1_bss_7B180;
    v0 = *(s16 *)&lbl_1_bss_960;
    W(0x16d4) = 0;
    tmp_call2 = W(0x16d8);
    tmp_call2 = 0;
    if (v0 != 9 || S(0x16c8) == -1) {
        if ((arg2 & 0xff) != 2 && (arg2 & 0xff) != 10) {
            W(8) = 0;
            return;
        }
    }
    if (v0 == 9) W(0x16dc) = fn_80008E84(fn_1_3F8C0());
    B(0x16e0) = arg3;
    W(8) = 1;
    tmp_call7 = W(0x16e4);
    tmp_call7 = (u32)fn_1_4630(lbl_801A6410, 0x120000 - 0x6c00, data + 0x2d4, 0x229);
    tmp_call9 = W(0x16e8);
    tmp_call9 = (u32)fn_1_4630(lbl_801A6410, 0x20000 - 0x3e00, data + 0x2d4, 0x22a);
    v3 = (u32 *)(base + 0x16ec);
    v4 = (u32 *)(base + 0x1700);
    v5 = (u32 *)(base + 0x1714);
    v6 = (u32 *)(base + 0x1728);
    for (i=0; i<5; i++) {
        *v3++=0; *v4++=0; *v5++=0; *v6++=0;
    }
    W(0x173c)=0; W(0x1740)=0;
    W(0x1744)=(u32)arg0; W(0x1748)=(u32)arg1;
    fn_1_435C(arg0);
    W(0x173c)=(u32)fn_1_3F8C(data+0x2dc, (void *)fn_1_E9BA8, 0, 29);
    fn_1_435C(arg1);
    W(0x1740)=(u32)fn_1_3F8C(data+0x2e8, (void *)fn_1_E9C68, 0, 26);
    W(0x10)=0; D(0x1d8)=-1;
    B(0x174c)=0; B(0x174d)=0;
    if (S(0x16c8)>=0) {
        tmp_call16 = W(0x16b4);
        tmp_call16=(u32)fn_1_4630(lbl_801A6410,0x3ea8,data+0x2d4,0x25e);
        lab_t0 = loc_1C0;
        sprintf(lab_t0, (char *)data+0x2f4, ((u32 *)(data+0x8c))[S(0x16c8)]);
        OSReport((char *)data+0x304, loc_1C0, DVDConvertPathToEntrynum(loc_1C0));
        if (fn_1_45730(loc_1C0, loc_64)!=0) {
            B(0x174e)++;
            v12=(fn_1_45B2C(loc_64)+31)&~31;
            p = fn_1_4630(lbl_801A6410,v12,data+0x2d4,0x264);
            W(0x1750)=(u32)p;
            DCFlushRange(p,v12+32);
            fn_1_458A0(loc_64,(void *)W(0x1750),v12,0);
            fn_1_45850(loc_64);
            fn_1_F0508();
        }
    }
    if (B(0x16cc)!=0xff) {
        ((u32 *)(base+0x16b4))[B(0x174e)-1]=(u32)fn_1_4630(lbl_801A6410,0x3ea8,data+0x2d4,0x27a);
        lab_t0 = loc_C0;
        sprintf(lab_t0, (char *)data+0x31c, B(0x16cc));
        if (fn_1_45730(loc_C0,loc_8)!=0) {
            v12=(fn_1_45B2C(loc_8)+31)&~31;
            p = fn_1_4630(lbl_801A6410,v12,data+0x2d4,0x27e);
            W(0x1750)=(u32)p;
            DCFlushRange(p,v12+32);
            fn_1_458A0(loc_8, (void *)W(0x1750), v12, 0);
            fn_1_45850(loc_8);
            fn_1_F0508();
        } else {
            B(0x174e)--;
            fn_1_F1D8C(0);
        }
    }
    fn_1_F1A24();
    if (B(0x1754)!=0) D(0x1d4)=14;
    else if (B(0x16cc)!=0xff || S(0x16c8)>=0) D(0x1d4)=16;
    fn_80008BEC(base+0x1758,0,0x3c);
    fn_80008BEC(base+0x1794,0,0x14);
    fn_80008BEC(base+0x17a8,0,0x14);
    W(0x17bc)=0; W(0x20)=0;
    W(0x17c0)=1; W(0x17c4)=0; W(0x17c8)=1;
    if (*(s16 *)&lbl_1_bss_960==9) fn_80008E84(W(0x16dc));
    W(0x17cc)=1; W(0xc)=0;
    *(s16 *)(data+0x1dc)=-1;
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset
