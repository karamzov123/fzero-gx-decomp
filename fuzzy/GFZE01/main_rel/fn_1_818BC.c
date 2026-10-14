/* Non-matching: best partial attempt (25.68% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"

typedef struct {
    u8 pad0[2];
    s16 id;
    u8 pad4[8];
    u32 flags;
} Sig_fn_1_81860_fn_1_81860_Obj;

struct fn_1_818BC_lbl_1_bss_6D820 {
    u8 pad_0[0xC];
    u32 unk_C;
    u8 pad_10[0xC];
    u32 unk_1C;
    u32 unk_20;
};
extern u8 lbl_1_bss_6D820;
/* declared by car.h */
extern s32 fn_1_81860(Sig_fn_1_81860_fn_1_81860_Obj *, Sig_fn_1_81860_fn_1_81860_Obj *);
extern void fn_1_12AB38(void *, u32, u32, void *);
extern u32 fn_1_12AC00(void *, u32);
extern void fn_1_80294(void *, void *, u32);
extern u32 fn_1_12A32C(void *);
extern void fn_1_12A2B8(u32);
extern void fn_1_12A2C4(u32);
extern void fn_1_12A2D0(s32);
extern u32 fn_1_D3884(u32);
extern void fn_80008BA8(void *, void *, u32);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
extern char *fn_80083DB0(char *, const char *);
extern int sprintf(char *, const char *, ...);
extern void fn_80006E10(u32);
struct Sig_fn_80077D40_Item { u32 flags; u32 unk_4; u16 width; u16 height; u16 max_lod; u16 pad_e; };
struct Sig_fn_80077D40_TextureList { u32 count; struct Sig_fn_80077D40_Item *items; };
extern u32 fn_80077D40(struct Sig_fn_80077D40_TextureList *);
struct Sig_fn_80071470_fn_80071470_E16_u32 { u32 unk_0; u8 pad_4[0xC]; };
struct Sig_fn_80071470_fn_80071470_Arg0 { u8 pad_0[8]; struct Sig_fn_80071470_fn_80071470_E16_u32 unk_8[1]; };
extern u32 fn_80071470(struct Sig_fn_80071470_fn_80071470_Arg0 *, u32);
struct Sig_fn_80071718_fn_80071718_Arg0 { u8 pad_0[0xC]; u32 unk_C; };
extern void fn_80071718(struct Sig_fn_80071718_fn_80071718_Arg0 *);

typedef struct { u8 bytes[0x440]; } Record;
typedef struct { u8 bytes[0x20]; } Entry;
#define EFLAGS(e) (*(u32 *)((u8 *)(e)+0xC))
#define EID(e) (*(s16 *)((u8 *)(e)+2))
#define RF(r,o) (*(u32 *)((u8 *)(r)+(o)))
static void make_name(char *out, Entry *e, u8 index) {
    char tmp[32];
    u32 flags = EFLAGS(e);
    fn_80083DB0(tmp, (char *)(lbl_1_data_1F1D8 + 0x324 + EID(e)*4));
    if (flags & 0x800) {
        if (EID(e) == 1) fn_80083DB0(tmp, (char *)(lbl_1_data_1F1D8 + 0x13f4));
        else if (EID(e) == 0) fn_80083DB0(tmp, (char *)(lbl_1_data_1F1D8 + 0x13ec));
        else if (EID(e) == 6) fn_80083DB0(tmp, (char *)(lbl_1_data_1F1D8 + 0x13e4));
    }
    if (index >= 4) sprintf(tmp, (char *)(lbl_1_data_1F1D8+0x1358), tmp, index-4);
    else if (index) sprintf(tmp, (char *)(lbl_1_data_1F1D8+0x1364), tmp);
    else sprintf(tmp, (char *)(lbl_1_data_1F1D8+0x1370), tmp);
    (void)out;
}
void fn_1_818BC(u32 arg0, size_t arg1, u32 arg2) {
    struct fn_1_818BC_lbl_1_bss_6D820 *g = (struct fn_1_818BC_lbl_1_bss_6D820 *)&lbl_1_bss_6D820;
    u8 *data = (u8 *)&lbl_1_data_1F1D8;
    Entry a[43], b[44];
    u32 i, n = 0, j;
    Record *records;
    if (arg2 == 0) {
        fn_80008BA8(a, (void *)arg0, arg1 << 5);
        qsort(a, arg1, 0x20, (int (*)(const void *,const void *))fn_1_81860);
        records = (Record *)g->unk_1C;
        for (i=0;i<arg1;i++) if (EFLAGS(&a[i]) & 0x4000000) {
            RF(&records[n],0x3a0) = g->unk_20 + (s16)n*0xa20;
            *((u8 *)&records[n]+0x328) = EID(&a[i]);
            RF(&records[n],0x390) |= 0x4000000;
            n++;
        }
        fn_1_12AB38(data+0xe0c,0,0,0);
        if (!g->unk_C) g->unk_C=fn_1_12AC00(data+0x140c,0);
        for (i=0;i<(s8)arg1;i++) {
            if (records) fn_1_80294(&a[i], (u8 *)records+i*0x440, 0);
        }
        fn_1_12AB38(data+0xe20,0,0,0);
        return;
    }
    fn_80008BA8(a,(void *)arg0,arg1<<5);
    fn_80008BA8(b,(void *)arg0,arg1<<5);
    for(i=0;i<arg1;i++) {
        b[i].bytes[4]=14;
        b[i].bytes[8]=16;
        if (EFLAGS(&b[i]) & 0xf0000000) {
            b[i].bytes[4]=13; b[i].bytes[8]=1; n++;
        }
    }
    j=(s16)(arg1-(s16)n);
    qsort(a,arg1,0x20,(int (*)(const void *,const void *))fn_1_81860);
    qsort(b,arg1,0x20,(int (*)(const void *,const void *))fn_1_81860);
    records=(Record *)g->unk_1C;
    n=0;
    for(i=0;i<arg1;i++) if(EFLAGS(&b[i])&0x4000000) {
        RF(&records[n],0x3a0)=g->unk_20+n*0xa20;
        *((u8 *)&records[n]+0x328)=EID(&a[i]);
        RF(&records[n],0x390)|=0x4000000;
        n++;
    }
    fn_1_12AB38(data+0xe0c,0,0,0);
    if(!g->unk_C) g->unk_C=fn_1_12AC00(data+0x140c,0);
    fn_1_12AB38(data+0xe20,0,0,0);
    for(i=0;i<j;i++) if (!(EFLAGS(&a[i])&0x4000000)) {
        char tmp[32];
        make_name(tmp,&a[i],0);
        RF(&records[i],0x324)=fn_1_12A32C(tmp);
    }
    for(i=0;i<j;i++) {
        if (RF(&records[i],0x390)&0x4000000) fn_1_80294(&a[i],(u8 *)records+i*0x440,0);
        else {
            fn_1_12A2B8(1); fn_1_12A2C4(1);
            fn_1_12A2D0(RF(&records[i],0x324));
            fn_1_12AB38(data+0xe0c,0,0,0);
            if ((u8 *)records+i*0x440) {
                fn_1_80294(&a[i],(u8 *)records+i*0x440,0);
                fn_1_12AB38(data+0xe20,0,0,0);
                fn_1_12A2B8(0); fn_1_12A2C4(0);
            }
        }
    }
    for(i=j;i<arg1;i++) if (!(EFLAGS(&b[i])&0x4000000)) {
        char tmp[32];
        make_name(tmp,&b[i],b[i].bytes[8]);
        RF(&records[i],0x324)=fn_1_12A32C(tmp);
    }
    for(i=j;i<arg1;i++) {
        if (RF(&records[i],0x390)&0x4000000) fn_1_80294(&b[i],(u8 *)records+i*0x440,0);
        else {
            fn_1_12A2B8(1); fn_1_12A2C4(1);
            fn_1_12A2D0(RF(&records[i],0x324));
            fn_1_12AB38(data+0xe0c,0,0,0);
            if ((u8 *)records+i*0x440) {
                fn_1_80294(&b[i],(u8 *)records+i*0x440,0);
                fn_1_12AB38(data+0xe20,0,0,0);
                fn_1_12A2B8(0); fn_1_12A2C4(0);
            }
        }
    }
}
