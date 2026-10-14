/* Non-matching: best partial attempt (52.62% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/effect.h"

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[4];
    s16 id;
    u8 pad1a[2];
    f32 unk1c, unk20, unk24, unk28;
    u8 pad2c[0x10];
    f32 unk3c, unk40, unk44, unk48, unk4c, unk50;
    u8 pad54[0x34];
    f32 a; /* 0x88 */
    f32 b; /* 0x8c */
    u8 pad90[0x20];
    f32 unk_b0, n; /* 0xb4 */
} Obj;
typedef struct {
    u8 pad[0x8];
    u32 seed;
} SeedObj;
typedef struct {
    f32 unk0; u8 p4[4]; f32 unk8; u8 pC[0x14];
    f64 unk20; f32 unk28; u8 p2c[0xc]; f64 unk38;
    u8 p40[0x14]; f32 unk54; u8 p58[4]; f32 unk5c; u8 p60[4]; f32 unk64;
    u8 p68[0x10]; f32 unk78; u8 p7c[0x3c]; f32 unkB8; u8 pBC[0x24];
    f32 unkE0; u8 pE4[0xc]; f64 unkF0; u8 pF8[0x14]; f32 unk10c;
    u8 p110[0xb4]; f32 unk1c4; u8 p1c8[0x54]; f32 unk21c;
    u8 p220[0x48]; f64 unk268; u8 p270[0x138]; f32 unk3a8;
    u8 p3ac[0x38]; f32 unk3e4, unk3e8; u8 p3ec[0x24]; f64 unk410; f32 unk418;
} Pool;
extern Pool lbl_1_rodata_2950;
extern u32 lbl_1_data_1D628;
extern u8 lbl_1_data_1D1D8[];
extern void *fn_1_86254(int);
extern u32 fn_1_3FC8C(void);
extern u32 fn_1_3FC58(void);
extern void *memset(void *, int, u32);
extern void *memcpy(void *, const void *, u32);

u32 fn_1_67680(Obj *arg0) {
    u8 temp[0xe8];
    Obj *p = arg0;
    u8 *effects;
    void *info;
    s32 i, idx;
    u32 r;
    f32 scale, blend;
    u32 seed;
    f32 fA, fB, fC;
    f64 dA, dB;
    s16 count;

    scale = lbl_1_rodata_2950.unk28 - p->a;
    p->unk48 *= scale; p->unk4c *= scale; p->unk50 *= scale;
    p->unk4c = (f32)((f64)p->unk4c + lbl_1_rodata_2950.unk410);
    psvec_add((u8 *)p + 0x3c, (u8 *)p + 0x48, (u8 *)p + 0x3c);
    p->unk44 += p->unk50;
    blend = (f32)(lbl_1_rodata_2950.unk1c4 * (p->b - p->a));
    p->a = p->a + blend;
    if ((s32)p->unk10 < 40)
        p->n *= (f32)((s32)p->unk10 / 40.0f);
    if ((s32)p->unk10 < 40) {
        blend = lbl_1_rodata_2950.unk28 -
            (lbl_1_rodata_2950.unk28 + lbl_1_rodata_2950.unk3a8 * (s32)p->unk10);
        p->unk1c *= blend; p->unk20 *= blend; p->unk24 *= blend;
    }
    info = fn_1_86254(p->id);
    memset(temp, 0, sizeof(temp));
    *(s16 *)(temp + 0x18) = p->id;
    *(s16 *)(temp + 0x14) = 36;
    *(s16 *)(temp + 0x1a) = -1;
    seed = 0x41c64e6d;
    *(u32 *)(temp + 0x34) = *(u32 *)((u8 *)*(u32 *)(*(u32 *)&lbl_1_bss_38458 + 0x0) + 0x148);
    count = 1;
    do {
        *(u32 *)(temp + 0x3c) = *(u32 *)((u8 *)p + 0x3c);
        *(u32 *)(temp + 0x40) = *(u32 *)((u8 *)p + 0x40);
        *(u32 *)(temp + 0x44) = *(u32 *)((u8 *)p + 0x44);
        *(u32 *)(temp + 0x48) = *(u32 *)((u8 *)p + 0x48);
        *(u32 *)(temp + 0x4c) = *(u32 *)((u8 *)p + 0x4c);
        *(u32 *)(temp + 0x50) = *(u32 *)((u8 *)p + 0x50);
        *(u32 *)(temp + 0x54) = *(u32 *)((u8 *)p + 0x54);
        seed = lbl_1_data_1D628 * seed + 12345;
        r = seed;
        seed = r * 0x41c64e6d + 12345;
        fA = lbl_1_rodata_2950.unk54 + lbl_1_rodata_2950.unk64 * ((f32)((r >> 16) & 0x7fff) / 32767.0f);
        lbl_1_data_1D628 = seed;
        r = seed;
        seed = r * 0x41c64e6d + 12345;
        fB = lbl_1_rodata_2950.unkB8 + lbl_1_rodata_2950.unk64 * ((f32)((r >> 16) & 0x7fff) / 32767.0f);
        lbl_1_data_1D628 = seed;
        *(f32 *)(temp + 0x50) *= 0.9f;
        *(f32 *)(temp + 0x54) *= 0.9f;
        *(f32 *)(temp + 0x58) *= 0.9f;
        *(f32 *)(temp + 0x3c) -= *(f32 *)(temp + 0x50);
        *(f32 *)(temp + 0x40) -= *(f32 *)(temp + 0x54);
        *(f32 *)(temp + 0x44) -= *(f32 *)(temp + 0x58);
        *(s32 *)(temp + 0x10) = (s32)(p->n * (60.0f * fA));
        *(f32 *)(temp + 0x28) = p->unk28 * (p->n * (0.3f + 0.5f * ((f32)((seed >> 16) & 0x7fff) / 32767.0f)));
        seed = seed * 0x41c64e6d + 12345; lbl_1_data_1D628 = seed;
        r = seed;
        seed = r * 0x41c64e6d + 12345; lbl_1_data_1D628 = seed;
        r = seed;
        seed = r * 0x41c64e6d + 12345; lbl_1_data_1D628 = seed;
        *(f32 *)(temp + 0x8c) = 0.02f;
        *(s16 *)(temp + 0xb4) = 364;
        fA = 0.8f + 0.5f * ((f32)((r >> 16) & 0x7fff) / 32767.0f);
        fB = 224.0f * fA / 255.0f;
        *(f32 *)(temp + 0x28) = 176.0f * fA / 255.0f;
        *(f32 *)(temp + 0x24) = (255.0f * (0.5f * fA)) / 255.0f;
        dA = 10.0 + (f64)(5.0f * ((f32)((*(u32 *)(temp + 0x100)) - 0x43300000)));
        dB = 0.003 * ((f64)(*(u32 *)(temp + 0x110)) - 4503599627370496.0);
        *(f32 *)(temp + 0x90) = (f32)dB;
        *(f32 *)(temp + 0x34) = (f32)(p->unk28 * (p->n * (f32)dA));
        if ((s8)*((u8 *)info + 0x475) != -1) {
            if (fn_1_3FC8C() == 0 && fn_1_3FC58() == 0) {
                effects = (u8 *)((u8 *)&lbl_1_bss_6C848 + 4);
                for (idx=0; idx<190; idx++, effects+=0xe8) if ((s8)*effects==0) { *effects=1; break; }
                if (idx<190) {
                    memcpy(effects,temp,0xe8); *(s16 *)(effects+2)=idx;
                    ((void (*)(void))((u32 *)lbl_1_data_1D1D8)[*(s16 *)(effects+12)])();
                }
            }
        } else if (fn_1_3FC8C()==0 && fn_1_3FC58()==0) {
            effects=(u8 *)&lbl_1_bss_6C848;
            for(idx=0;idx<190;idx++,effects+=0xe8) if((s8)*effects==0){*effects=1;break;}
            if(idx<190){memcpy(effects,temp,0xe8);*(s16 *)(effects+2)=idx;
                ((void (*)(void))((u32 *)lbl_1_data_1D1D8)[*(s16 *)(effects+12)])();}
        }
        count--;
    } while (count > 0);
    return seed;
}
