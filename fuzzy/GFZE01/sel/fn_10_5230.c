/* Non-matching: best partial attempt (76.17% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/sel/data/lbl_10_rodata_58.h"

typedef struct {
    s16 unk_0;
    u8 pad_2[2];
    s16 unk_4;
    u8 pad_6[8];
    s16 unk_E;
    u8 pad_10[4];
    u8 unk_14;
    u8 pad_15[11];
} SelEnt;

typedef struct {
    SelEnt ent[4];
    u8 pad_80[0x10];
    s16 unk_90;
    u8 pad_92[2];
    u32 unk_94;
    u8 pad_98[6];
    u8 unk_9E;
    u8 pad_9F[5];
    u32 unk_A4;
} SelA;

typedef struct {
    u8 pad_0[0x19];
    u8 unk_19;
    u8 pad_1A[0xA];
    u32 unk_24;
    u8 pad_28[0x94 - 0x28];
} SelTbl94;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    s16 unk_14;
    s16 unk_16;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x28];
    u32 unk_60;
} SelRec;

typedef struct {
    u8 pad_0[0xC];
    u8 unk_C;
    u8 pad_D[7];
    u32 unk_14;
} Bss0;

typedef struct {
    u8 pad_0[0x454];
    s16 unk_454;
    u8 pad_456[4];
    s16 unk_45A;
    u32 unk_45C;
    u8 pad_460[0x578 - 0x460];
    u32 unk_578;
    u8 unk_57C[0xC60];
} Data0;

typedef struct {
    s16 unk_0;
    s16 unk_2;
    u8 pad_4[4];
    u8 unk_8;
    u8 pad_9[0x17];
} BufEnt;

typedef struct {
    u32 w[10];
} LocTab;

typedef struct Sig_fn_10_3DE0_SelEntry {
    u32 flags;
    u8 pad04;
    u8 value5;
    u8 pad06;
    u8 type7;
    u8 pad08[0x81a0 - 0x8];
    u8 source_index;
    u8 pad81a1[0x81c0 - 0x81a1];
} Sig_fn_10_3DE0_SelEntry;

extern Bss0 lbl_10_bss_0;
extern Data0 lbl_10_data_0;
extern SelA lbl_1_bss_8B3A0;
extern s16 lbl_1_bss_962;
extern u8 lbl_1_bss_9C;
extern u32 lbl_801A63C0;
extern u32 lbl_1_bss_718C0;
extern u32 lbl_801A6410;
extern u32 lbl_1_bss_8B5F4[4];

extern void fn_10_C594(void *);
extern int fn_1_8623C(void);
extern u32 fn_1_12B4EC(u32, u32);
extern void fn_80008BA8(u32, u32, s32);
extern void fn_1_12B120(u8 *, void *, void *, void *, void *, s32, s32);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_13F81C(void);
extern void fn_1_13F948(void);
extern u8 * fn_1_36AD0(void);
extern void fn_10_3DE0(u32, Sig_fn_10_3DE0_SelEntry *, s16);
extern void fn_1_FE004(void);
extern u32 fn_1_4404(void);
extern long fn_800090A4(int);
extern s32 fn_1_45D0(u32, s32, void *, s32);
extern u32 fn_1_46BA0(u32, u32);
extern void fn_1_46A60(void);
extern u32 fn_1_46B44(void *, void *);
extern void fn_1_7B084(char *, int);
extern u32 fn_1_9A958(u32, u32);
extern void fn_1_46EA8(u32);
extern void fn_1_4100C(void);
extern void fn_1_41104(void *);
extern void fn_1_47E54(s32);
extern void fn_1_8001C(void);
extern u32 fn_1_46A8C(u32);
extern u32 fn_1_46BFC(void);
extern u32 fn_80008E84(u32);
extern void fn_10_C654(u32 *);
extern void fn_10_C5E0(u32 *);

void fn_10_5230(u32 arg0) {
    LocTab tab;
    BufEnt buf[4];
    s16 i;
    s16 rnd;
    u8 j;
    Bss0 *pBss;
    Data0 *pDat;
    void *mgr;
    SelA *pSel;
    SelTbl94 *tbl;
    SelRec *rec;
    u32 w1c;
    u16 w14;
    u16 w16;
    u32 w18;
    s32 n;
    u32 v;
    u32 res;

    pBss = &lbl_10_bss_0;
    pDat = &lbl_10_data_0;
    mgr = (u8 *)pBss + 0x50000;
    fn_10_C594(&lbl_10_bss_0);

    if (lbl_1_bss_8B3A0.ent[0].unk_4 == 0) {
        lbl_1_bss_8B3A0.ent[0].unk_E = -1;
        lbl_1_bss_8B3A0.unk_94 |= 0x08000000;
        lbl_1_bss_8B3A0.ent[1].unk_E = -1;
        lbl_1_bss_8B3A0.ent[2].unk_E = -1;
        lbl_1_bss_8B3A0.ent[3].unk_E = -1;
        lbl_1_bss_8B3A0.ent[lbl_1_bss_8B3A0.unk_9E].unk_E = 6;
    }

    pSel = &lbl_1_bss_8B3A0;
    if (pSel->unk_94 & 0x40000000) {
        if (pSel->ent[pSel->unk_9E].unk_E == 0x31 || pSel->ent[pSel->unk_9E].unk_E < 0x29) {
            v = lbl_801A63C0;
            v = v * 0x676A4B6B;
            v += 0x33CB;
            lbl_801A63C0 = v;
            rnd = (s16)((v >> 14) & 3);
            lbl_1_bss_8B3A0.ent[lbl_1_bss_8B3A0.unk_9E].unk_14 = (u8)(1 << rnd);
            fn_1_12B4EC((s16)fn_1_8623C(), rnd);
        }
    }

    if ((pSel->unk_94 & 0x02000000) == 0) {
        fn_80008BA8((u32)buf, lbl_1_bss_718C0 + 14, 0x80);
        for (i = 0; i < 4; i++) {
            if (lbl_1_bss_8B3A0.ent[i].unk_E == buf[i].unk_2) {
                lbl_1_bss_8B3A0.ent[i].unk_14 = buf[i].unk_8;
            }
        }
    } else {
        lbl_1_bss_8B3A0.ent[0].unk_14 = 1;
    }

    rec = (SelRec *)((u8 *)mgr + 0x1B14);
    rec->unk_4 = (u32)((u8 *)mgr + 0x1B7C);
    rec->unk_8 = (u32)((u8 *)mgr + 0x2EFC);
    rec->unk_C = *(u32 *)((u8 *)mgr - 0x6C80);
    rec->unk_10 = (u32)((u8 *)mgr - 0x6C60);
    tbl = (SelTbl94 *)pSel->unk_A4;
    w1c = (u32)&tbl[lbl_1_bss_962 - 14].unk_24;
    w14 = pDat->unk_454;
    w16 = pDat->unk_45A;
    w18 = pDat->unk_45C;
    rec->unk_1C = w1c;
    rec->unk_14 = w14;
    rec->unk_16 = w16;
    rec->unk_18 = w18;
    rec->unk_24 = (u32)((u8 *)mgr + 0x17EC);
    rec->unk_2C = 8;
    rec->unk_28 = 8;
    rec->unk_30 = 0xF0000000;
    rec->unk_34 = 1;
    rec->unk_60 = 1;
    fn_1_12B120((u8 *)rec, *(void **)((u8 *)mgr - 0x6C7C), *(void **)((u8 *)mgr - 0x6C78),
                (void *)((u8 *)mgr + 0x1758), (void *)((u8 *)mgr + 0x1768),
                (u8)*(s16 *)((u8 *)mgr - 0x6C74), 0xF0000000);

    pBss->unk_14 = -1;
    fn_1_4A00(1, (u8)*(s16 *)((u8 *)mgr - 0x6C74), *(void **)((u8 *)mgr - 0x6C78));
    *(u32 *)((u8 *)mgr + 0x1744) = 0;
    ((SelTbl94 *)pSel->unk_A4)->unk_19 = 0;

    if (pSel->unk_94 & 0x40000000) {
        fn_1_13F81C();
        fn_1_13F948();
        fn_10_3DE0((u8)fn_1_8623C(), (Sig_fn_10_3DE0_SelEntry *)fn_1_36AD0(), 1);
    } else if (lbl_1_bss_8B3A0.ent[0].unk_0 == 3 || lbl_1_bss_8B3A0.ent[0].unk_0 == 2) {
        fn_1_13F948();
        fn_1_13F81C();
        fn_10_3DE0(0, (Sig_fn_10_3DE0_SelEntry *)fn_1_36AD0(), 1);
        fn_1_FE004();
    } else if ((s16)lbl_1_bss_8B3A0.ent[0].unk_0 == 0) {
        fn_1_13F948();
        fn_1_13F81C();
        j = 0;
        while (j < 4) {
            fn_10_3DE0(j, (Sig_fn_10_3DE0_SelEntry *)fn_1_36AD0(), 1);
            j++;
        }
        fn_1_FE004();
    }

    res = fn_1_4404();
    n = (s32)fn_800090A4(lbl_801A6410) - 1;
    pDat->unk_578 = fn_1_45D0(lbl_801A6410, n, pDat->unk_57C, 0xC60);
    fn_1_46BA0(pDat->unk_578, n);

    if (pSel->unk_94 & 0x40000000) {
        tab = *(LocTab *)&lbl_10_rodata_58;
        fn_1_46A60();
        fn_1_46B44(fn_10_C654, &lbl_1_bss_8B5F4[0]);
        fn_1_7B084((char *)&tab.w[(s8)lbl_1_bss_9C], 1);
        fn_1_9A958((u32)&tab.w[(s8)lbl_1_bss_9C], 1);
        fn_1_46B44(fn_10_C654, &lbl_1_bss_8B5F4[1]);
        lbl_1_bss_8B5F4[2] = lbl_1_bss_8B5F4[1];
        fn_1_46EA8(1);
        fn_1_4100C();
        fn_1_41104((void *)2);
        fn_1_47E54(0xBA);
        fn_1_47E54(0xBB);
        fn_1_8001C();
        fn_1_47E54(0x94);
        fn_1_46EA8(0);
        fn_1_46B44(fn_10_C654, &lbl_1_bss_8B5F4[3]);
    } else {
        fn_1_46A8C(lbl_1_bss_8B5F4[0]);
        fn_1_7B084((char *)lbl_1_bss_8B3A0.unk_90, 1);
        fn_1_9A958(lbl_1_bss_8B3A0.unk_90, 1);
        fn_1_46B44(fn_10_C654, &lbl_1_bss_8B5F4[1]);
        lbl_1_bss_8B5F4[2] = lbl_1_bss_8B5F4[1];
        fn_1_4100C();
        fn_1_41104((void *)2);
        fn_1_47E54(0xBB);
        fn_1_46B44(fn_10_C654, &lbl_1_bss_8B5F4[3]);
    }

    fn_1_46BFC();
    pBss->unk_C = 1;
    fn_1_46B44(fn_10_C5E0, &pDat->unk_578);
    fn_80008E84(res);
}
