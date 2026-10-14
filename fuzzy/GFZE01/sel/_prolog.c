/* Non-matching: best partial attempt (86.70% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
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
typedef struct Sig_fn_1_45B2C_Fn145B2CData {
    s32 kind;
    u8 pad[0x54];
    void *value;
} Sig_fn_1_45B2C_Fn145B2CData;
struct Sig_fn_1_45850_fn_1_45850_Arg0 {
    u32 unk_0;
};

struct _prolog_lbl_1_bss_8B3A0 {
    u8 pad_0[0x8];
    u16 unk_8;
    s16 unk_A;
    u8 pad_C[0x88];
    u32 unk_94;
    u8 pad_98[0x6];
    u8 unk_9E;
};
struct _prolog_lbl_10_bss_0 {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x8];
    u32 unk_10;
};
struct _prolog_lbl_1_bss_8B5F4 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
};
struct _prolog_lbl_801A6410 {
    u32 unk_0;
};
struct _prolog_lbl_1_bss_960 {
    s16 unk_0;
};

extern int fn_1_45730(void *, Sig_fn_1_45730_LoadResult *);
extern s32 fn_1_45D0(u32, u32, const char *, int);
extern struct _prolog_lbl_10_bss_0 lbl_10_bss_0;
extern struct _prolog_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern struct _prolog_lbl_1_bss_8B5F4 lbl_1_bss_8B5F4;
extern struct _prolog_lbl_1_bss_960 lbl_1_bss_960;
extern struct _prolog_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_3CF0(u32, u32);
extern u32 fn_1_45850(struct Sig_fn_1_45850_fn_1_45850_Arg0 *);
extern u32 fn_1_4630(u32, u32, const char *, int);
extern u32 fn_1_4706C(void);
extern u32 fn_1_7BA08(u32, u32, u32);
extern u32 fn_1_7BA48(void);
extern u32 fn_1_A0680(void);
extern u32 lbl_10_bss_3C0;
extern u8 lbl_10_data_0[];
extern void * fn_1_45B2C(Sig_fn_1_45B2C_Fn145B2CData *);
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_1_159440(int, int);
extern void fn_1_411A4(u32);
extern u32 fn_1_4404(void);
extern void fn_1_469BC(void);
extern void fn_1_46A60(void);
extern void fn_1_479F0(s16);
extern void fn_1_47F74(s32);
extern void fn_1_48418(int);
extern void fn_1_5124(u32, u32);
extern void fn_1_52070(u32);
extern void fn_80008BEC(void *, int, u32);


#define W(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define H(p,o) (*(s16 *)((u8 *)(p)+(o)))
#define B(p,o) (*(u8 *)((u8 *)(p)+(o)))
extern u32 fn_800090A4(u32);
extern void fn_1_46BA0(u32,u32);
extern u32 fn_1_46ED8(void);
extern u32 fn_1_46A8C(u32);
extern void fn_1_465D0(void *,int);
extern void fn_1_46B44(void (*)(void *), void *);
extern void fn_10_C654(void *);
extern void fn_10_C5E0(void *);
extern void fn_1_41104(u32);
extern u32 fn_1_47E54(u32);
extern void fn_1_46BFC(void);
extern u32 fn_80008E84(u32);
extern void fn_8006CE1C(f32);
extern u32 fn_1_435C(u32);
extern void fn_1_7BAF8(void);
extern void fn_1_3F8C(void *,void (*)(void),u32,u32);
extern void fn_1_A5330(u8,s16);
extern s16 fn_1_12EF24(s16,s16);
extern s16 fn_1_8D7C8(void);
extern void fn_10_5780(void *);
extern void fn_10_834(void);
extern void fn_10_AB8(void);
extern void fn_10_CF50(void);
extern void fn_1_12F17C(void);
extern void fn_1_36ADC(void);
extern u8 lbl_1_bss_970[];
extern s16 lbl_1_bss_96A;
extern s16 lbl_1_bss_8CA26;
extern void (*lbl_1_bss_7167C)(void);
extern void (*lbl_1_bss_71680)(void);
extern void (*lbl_1_bss_71684)(void);
extern const u32 lbl_10_rodata_0[12];

void _prolog(void) {
    u32 saved, amount;
    s32 i;
    s16 slot;
    u32 flags;
    struct _prolog_lbl_10_bss_0 *p_lbl_10_bss_0;
    u8 *p_lbl_10_data_0;
    struct _prolog_lbl_1_bss_8B3A0 *p_lbl_1_bss_8B3A0;
    s16 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    s32 v4;
    s32 v5;
    u32 v6;
    u32 v7;
    u32 v8;
    u32 v9;
    u32 v10;
    s32 v11;
    u32 v12;
    s32 v13;
    u32 v14;
    u32 v15;
    struct { u32 a[23]; } loc_8;
    /* frame */
    int t0;
    void * t2;
    u32 t6;
    u32 t7;
    u32 t8;
    s32 t9;
    s32 t11;
    s32 t13;
    v0 = lbl_1_bss_8B3A0.unk_A;
    p_lbl_10_bss_0 = (struct _prolog_lbl_10_bss_0 *)&lbl_10_bss_0;
    p_lbl_10_data_0 = (u8 *)&lbl_10_data_0;
    v1 = ((u32)p_lbl_10_bss_0 + 0x50000);
    if (v0 != -1) {
    lbl_1_bss_8B3A0.unk_8 = v0;
    }
    p_lbl_1_bss_8B3A0 = (struct _prolog_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0;
    v2 = p_lbl_1_bss_8B3A0->unk_94;
    p_lbl_1_bss_8B3A0->unk_9E = 0;
    v3 = (v2 & 0xFFFFFDFF);
    p_lbl_1_bss_8B3A0->unk_94 = v3;
    if ((v2 & 0x40000000) == 0) {
    p_lbl_1_bss_8B3A0->unk_94 = (v3 | 256);
    }
    t0 = fn_1_45730((void *)((u8 *)(u32)p_lbl_10_data_0 + 1436), (Sig_fn_1_45730_LoadResult *)&loc_8);
    if ((s32)t0 == 0) {
    OSPanic((const char *)(u32)((u8 *)(u32)p_lbl_10_data_0 + 1404), 664, (const char *)(u32)((u8 *)(u32)p_lbl_10_data_0 + 1464));
    }
    t2 = (void *)(fn_1_45B2C((Sig_fn_1_45B2C_Fn145B2CData *)&loc_8));
    p_lbl_10_bss_0->unk_10 = ((u32)((u8 *)t2 + 31) & ~0x1F);
    fn_1_45850((struct Sig_fn_1_45850_fn_1_45850_Arg0 *)&loc_8);
    lbl_1_bss_8B5F4.unk_0 = 0;
    lbl_1_bss_8B5F4.unk_4 = 0;
    lbl_1_bss_8B5F4.unk_8 = 0;
    lbl_1_bss_8B5F4.unk_C = 0;
    lbl_1_bss_8B5F4.unk_10 = 0;
    lbl_1_bss_8B5F4.unk_14 = 0;
    lbl_1_bss_8B5F4.unk_18 = 0;
    lbl_1_bss_8B5F4.unk_1C = 0;
    fn_80008BEC((void *)&lbl_10_bss_3C0, 0, (0x50000 - 28736));
    fn_1_A0680();
    t6 = fn_1_4630(lbl_801A6410.unk_0, 3108, (const char *)p_lbl_10_data_0 + 0x57c, 0x2a9);
    p_lbl_10_bss_0->unk_4 = t6;
    t7 = fn_1_4630(lbl_801A6410.unk_0, (0x10000 - 20928), (const char *)p_lbl_10_data_0 + 0x57c, 0x2aa);
    *(u32 *)((u8 *)v1 + -27776) = t7;
    for (v5 = 0; (s16)v5 < 41; v5++) {
        *(s32 *)((u8 *)W(v1,-27776) + v5 * 1088 + 804) = -1;
    }
    t8 = fn_1_7BA08(32, 32, 64);
    t9 = fn_1_45D0(lbl_801A6410.unk_0, t8, (const char *)p_lbl_10_data_0 + 0x57c, 0x2ac);
    p_lbl_10_bss_0->unk_0 = t9;
    fn_1_7BA48();
    t11 = fn_1_45D0(lbl_801A6410.unk_0, 5948, (const char *)p_lbl_10_data_0 + 0x57c, 0x2ad);
    *(u32 *)((u8 *)v1 + -27772) = t11;
    fn_1_3CF0(t11, 128);
    t13 = fn_1_45D0(lbl_801A6410.unk_0, 5948, (const char *)p_lbl_10_data_0 + 0x57c, 0x2ae);
    *(u32 *)((u8 *)v1 + -27768) = t13;
    fn_1_3CF0(t13, 128);
    fn_1_5124(*(u32 *)((u8 *)v1 + -27772), *(u32 *)((u8 *)v1 + -27768));
    fn_1_411A4(1);
    if ((p_lbl_1_bss_8B3A0->unk_94 & 0x40000000) != 0) {
    fn_1_48418(2);
    fn_1_479F0(lbl_1_bss_960.unk_0);
    fn_1_469BC();
    fn_1_4706C();
    fn_1_46A60();
    fn_1_159440(1, 0);
    fn_1_159440(2, 0);
    fn_1_159440(3, 0);
    } else {
    if ((p_lbl_1_bss_8B3A0->unk_94 & 0x2000000) != 0) {
    fn_1_47F74(154);
    fn_1_47F74(155);
    fn_1_47F74(48);
    } else {
    fn_1_48418(2);
    fn_1_47F74(154);
    fn_1_47F74(155);
    fn_1_47F74(157);
    fn_1_47F74(161);
    fn_1_47F74(156);
    fn_1_47F74(162);
    fn_1_469BC();
    fn_1_4706C();
    fn_1_46A60();
    fn_1_159440(2, 1);
    }
    }
    fn_1_52070(320);
    v15 = p_lbl_1_bss_8B3A0->unk_94;
    if ((v15 & 0x2000000) == 0) {
    if ((v15 & ~0x7FFFFFFF) == 0) {

    saved = fn_1_4404();
    amount = fn_800090A4(lbl_801A6410.unk_0) - 0x10000;
    W(p_lbl_10_data_0,0x578) = fn_1_45D0(lbl_801A6410.unk_0,amount,(const char *)p_lbl_10_data_0+0x57c,0x2ed);
    fn_1_46BA0(W(p_lbl_10_data_0,0x578),amount);
    fn_1_46A8C((fn_1_46ED8() & ~31) - p_lbl_10_bss_0->unk_10);
    fn_1_465D0(p_lbl_10_data_0+0x59c,2);
    fn_1_46B44(fn_10_C654,&lbl_1_bss_8B5F4);
    if (!(p_lbl_1_bss_8B3A0->unk_94 & 0x20)) {
        fn_1_41104(1);
        fn_1_41104(6);
        fn_1_47E54(0x9a);
        fn_1_47E54(0x9b);
        fn_1_47E54(0xba);
        fn_1_47E54(0xa0);
    }
    fn_1_46BFC();
    B(p_lbl_10_bss_0,0xc)=1;
    fn_1_46B44(fn_10_C5E0,p_lbl_10_data_0+0x578);
    fn_80008E84(saved);
    }
    }
    W(lbl_1_bss_970,0)=0;
    B(lbl_1_bss_970,4)=13;
    fn_8006CE1C(*(const f32 *)lbl_10_rodata_0);
    fn_1_435C(W(v1,-27768));
    fn_1_3F8C(p_lbl_10_data_0+0x5d8,fn_1_7BAF8,p_lbl_10_bss_0->unk_0,2);
    B(&lbl_1_bss_8B3A0,0x129)=1;
    W(&lbl_1_bss_8B3A0,0xa4)=p_lbl_10_bss_0->unk_4;
    if (!(p_lbl_1_bss_8B3A0->unk_94 & 0x30)) {
        H(&lbl_1_bss_8B3A0,0)=-1;
    }
    p_lbl_1_bss_8B3A0->unk_94 &= ~0x08000000;
    p_lbl_1_bss_8B3A0->unk_94 &= ~0x0c000000;
    p_lbl_1_bss_8B3A0->unk_94 &= ~0x01000000;
    p_lbl_1_bss_8B3A0->unk_94 &= ~0x00200000;
    p_lbl_1_bss_8B3A0->unk_94 &= ~0x00300000;
    p_lbl_1_bss_8B3A0->unk_94 &= ~0x00380000;
    p_lbl_1_bss_8B3A0->unk_94 &= ~0x80;
    p_lbl_1_bss_8B3A0->unk_94 &= ~0xc0;
    flags=p_lbl_1_bss_8B3A0->unk_94;
    if (flags & 0x40000000) {
        lbl_1_bss_96A = (flags & 0x2000) ? 22 : 26;
        for (i=0;(s16)i<4;i++) {
            B(&lbl_1_bss_8B3A0,0x9f+i)=50;
            fn_1_A5330(50,i);
        }
        H(&lbl_1_bss_8B3A0,0)=9;
        H(&lbl_1_bss_8B3A0,4)=1;
        H(&lbl_1_bss_8B3A0,6)=30;
        H(&lbl_1_bss_8B3A0,8)=1;
        for (i=0;(s16)i<4;i++) {
            H(&lbl_1_bss_8B3A0,0xe+i*32)=-1;
            B(&lbl_1_bss_8B3A0,0x9f+i)=50;
            fn_1_A5330(50,i);
        }
        H(&lbl_1_bss_8B3A0,0xe)=6;
        H(&lbl_1_bss_8B3A0,0x8c)=6;
        H(&lbl_1_bss_8B3A0,0x8e)=0;
        H(&lbl_1_bss_8B3A0,0x90)=fn_1_12EF24(6,0);
        B(&lbl_1_bss_8B3A0,0x12a)=1;
        B(&lbl_1_bss_8B3A0,0x12b)=0;
        lbl_1_bss_8CA26=0;
        H(p_lbl_10_bss_0,0x18)=19;
        H(p_lbl_10_bss_0,0x1a)=2;
        H(v1,-27764)=15;
    } else {
        lbl_1_bss_96A=14;
        H(p_lbl_10_bss_0,0x18)=19;
        H(p_lbl_10_bss_0,0x1a)=6;
        H(v1,-27764)=15;
        if (flags & 0x20) {
            lbl_1_bss_96A=15;
        } else if (flags & 0x10) {
            lbl_1_bss_96A=16;
        } else {
            H(W(&lbl_1_bss_8B3A0,0xa4),0)=-1;
            fn_10_5780(&lbl_1_bss_8B3A0);
        }
    }
    if ((p_lbl_1_bss_8B3A0->unk_94 & 0x40000000) ||
        (p_lbl_1_bss_8B3A0->unk_94 & 0x02000000)) {
        p_lbl_1_bss_8B3A0->unk_94 |= 0x20000000;
    }
    W(&lbl_1_bss_8B3A0,0x98)=0;
    W(&lbl_1_bss_8B3A0,0x98)=0x80000000 >> p_lbl_1_bss_8B3A0->unk_9E;
    slot = fn_1_8D7C8() < 30 ? fn_1_8D7C8() : 30;
    B(v1,-27762)=slot;
    lbl_1_bss_7167C=fn_10_834;
    lbl_1_bss_71680=fn_10_AB8;
    lbl_1_bss_71684=fn_10_CF50;
    if (p_lbl_1_bss_8B3A0->unk_94 & 0x02000000) {
        slot=p_lbl_1_bss_8B3A0->unk_9E;
        H(&lbl_1_bss_8B3A0,4)=1;
        H(&lbl_1_bss_8B3A0,0)=4;
        H(&lbl_1_bss_8B3A0,6)=1;
        H(&lbl_1_bss_8B3A0,0xe)=-1;
        H(&lbl_1_bss_8B3A0,0x2e)=-1;
        H(&lbl_1_bss_8B3A0,0x4e)=-1;
        H(&lbl_1_bss_8B3A0,0x6e)=-1;
        H(&lbl_1_bss_8B3A0,0xe+slot*32)=6;
        B(&lbl_1_bss_8B3A0,0x14+slot*32)=1;
        B(&lbl_1_bss_8B3A0,0x9f+slot)=50;
        H(&lbl_1_bss_8B3A0,0x90)=1;
        H(&lbl_1_bss_8B3A0,0x8c)=1;
        H(&lbl_1_bss_8B3A0,0x8e)=0;
        fn_1_A5330(50,slot);
        W(p_lbl_10_data_0,0x45c)=0x80000000;
        lbl_1_bss_96A=18;
    }
    fn_1_12F17C();
    fn_1_36ADC();
    fn_80008BEC((u8 *)&lbl_1_bss_8B3A0+0x140,0,12);
    B(v1,-27760)=0;
    B(v1,-27761)=0;
}
