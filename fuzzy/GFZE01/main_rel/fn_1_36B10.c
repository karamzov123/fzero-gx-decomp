/* Non-matching: best partial attempt (23.78% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/game.h"
extern const f32 lbl_1_rodata_BD8;
extern int fn_1_3F2A0(void);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_469BC(void);
extern void fn_1_8DBA4(u8);
extern int fn_1_EB248(void);
extern s32 fn_1_154C84(void);
extern void fn_1_F2EFC(void);
extern void fn_1_F2EDC(void);
extern u32 fn_1_33A20(void);
extern int fn_1_40354(void);
extern int fn_1_402D4(void);
extern u32 fn_1_2EBB8(u32, u32);
extern void fn_1_A0C68(void);
extern void fn_1_A2DC4(u32);
extern int fn_1_4C10(void);
extern void fn_1_1280(u32);
extern u8 lbl_1_bss_3C00;
extern u32 lbl_1_bss_3C08[2];

void fn_1_36B10(void) {
    u8 *g = &lbl_1_bss_3C00;
    u8 *s = g + 0x30;
    u8 *tab = g + 0x165c;
    u32 *state = (u32 *)(g + 0x20000);
    u32 flags, ret;
    s32 i, j;
    u8 n, mode;

    state[0x2f50 / 4] = 0;
    state[0x2044 / 4] = 0;
    state[0x1f9c / 4] = 0;
    ret = *(u32 *)(s + 0xa8) ? ((u32 (*)(void))*(u32 *)(s + 0xa8))() : 0;
    flags = ret;
    if (ret & 4) state[0x1f9c / 4] = 1;
    if ((ret & 2) && !state[0x1fa0 / 4]) {
        n = s[8];
        *(u16 *)(g + 0x17f4) = s[7];
        if (s[5] == 0) {
            if (!( *(u32 *)(g + 0x30) & 0x400000)) {
                fn_1_3F2A0();
                for (i=0;i<n;i++) {
                    u8 *src=s+i*0xa0;
                    for (j=0;j<4;j++) {
                        u8 ix=src[(g[0x2a] <= 0x29 ? 0x157 : 0xdc)+j*0xa0];
                        u8 *dst=tab+ix*8;
                        dst[4]=src[0x154+j*0xa0]; dst[6]=g[0x163c+i*4+j];
                        tab[0x194+ix]=(u8)(i*4+j);
                    }
                }
                tab[0x192]=n; tab[0x191]|=2; tab[0x190]=s[7];
                *(u32 *)(g+0x30)|=0x400000;
                *(u16 *)(g+0x17f4)=14;
            }
        } else {
            for (i=0;i<n;i++) if (*(u32 *)(s+i*0xa0+0x1480)) break;
            if (i<n && !(*(u32 *)(g+0x30)&0x200)) {
                fn_1_3F2A0();
                for (i=0;i<n;i++) {
                    u8 *src=s+i*0xa0;
                    for(j=0;j<4;j++) { u8 ix=src[0x157+j*0xa0]; tab[ix*8+4]=src[0x154+j*0xa0]; tab[0x194+ix]=i*4+j; }
                }
                tab[0x192]=n; tab[0x191]|=2; tab[0x190]=s[7]; *(u32 *)(g+0x30)|=0x400000; *(u16 *)(g+0x17f4)=14;
            }
        }
        fn_1_4A00(0,30,*(void **)(g+0x1500));
        state[0x1fa0/4]=1; lbl_1_bss_6EAB4.unk_0 |= 0x2c;
        if (!s[5]) *((u8 *)&lbl_1_data_5730 + 0x454)=1;
        fn_1_469BC(); fn_1_8DBA4(0);
    }
    if ((s8)g[0x1504] != -1) {
        state[0x1f9c/4]=0;
        ret=*(u32 *)(s+0xc4) ? ((u32 (*)(void))*(u32 *)(s+0xc4))() : 0;
        if(ret&4) state[0x1f9c/4]=1;
        if((ret&2)&&!state[0x1fa0/4]) {
            *(u16 *)(g+0x17f4)=s[7];
            if(!s[5]) fn_1_3F2A0();
            fn_1_4A00(0,30,*(void **)(g+0x1500)); state[0x1fa0/4]=1;
            lbl_1_bss_6EAB4.unk_0 |= 0x2c;
            if(!s[5]) *((u8 *)&lbl_1_data_5730 + 0x454)=1;
            fn_1_469BC(); fn_1_8DBA4(0);
        }
        if(!(ret&1)) {
            if(!fn_1_EB248() && !fn_1_154C84()) {
                if(state[0x1ff0/4]) { if(*(u32 *)(g+0x30)&0x100) fn_1_F2EFC(); state[0x1ff0/4]=0; state[0x2f50/4]=1; }
                else if(!state[0x1f9c/4]) fn_1_33A20();
                else if(*(u32 *)(g+0x30)&2) state[0x2f50/4]=1;
            } else if(*(u32 *)(g+0x30)&0x800) { if(!state[0x1ff0/4]) { if(*(u32 *)(g+0x30)&0x100) fn_1_F2EDC(); state[0x1ff0/4]=1; } state[0x2f50/4]=1; }
        }
    }
    if (g[0x1504] == 0xff) {
        int ok=1;
        if(*(s16 *)(g+0x2a)<40 || *(s16 *)(g+0x2a)>=42 || state[0x1fa0/4] || state[0x2294/4]) ok=0;
        if(*(f32 *)(g+0x20000+0x1ff8)>*(f32 *)((u8 *)&lbl_1_rodata_BD8+4)) ok=0;
        if(fn_1_EB248() || fn_1_154C84()) ok=0;
        if(*(u32 *)(g+0x30)&0x8000000) ok=0;
        else if((*(u32 *)(g+0x30)&0x800)&&*(s16 *)(g+0x2a)<=40) ok=0;
        else if(!fn_1_40354()) { if(!(*(u32 *)(g+0x30)&0x400) || !fn_1_402D4()) ok=0; }
        if(ok) {
            u32 v=0x2029, f=*(u32 *)(g+0x30);
            if(f&0x800) { if(s[5]==5) v=(v&~0x180)|0x10; else if(s[5]!=1) v|=0x40; }
            fn_1_2EBB8(v,0);
            if(!(f&0x800)) { state[0x2f50/4]=1; *(u32 *)(g+0x30)|=2; fn_1_A0C68(); }
        }
    }
    if(*(s16 *)(g+0x17f4)==-1 || fn_1_4C10()) {
        if(*(u32 *)(g+0xc)) { state[0x1f9c/4]=0; ret=*(u32 *)(s+0xc0)?((u32(*)(void))*(u32 *)(s+0xc0))():0; if(ret&4)state[0x1f9c/4]=1; }
        else { fn_1_1280(0); g[0x3058]=1; }
    }
    if(!state[0x2f50/4] && !state[0x228c/4] && !(*(u32 *)(g+0x30)&0x20000000)) {
        if(*(s16 *)(g+0x14e8)==0x24) *(s16 *)(g+0x14e8)=(*(u32 *)(g+0x30)&0x201)?0x28:0x27;
        i=*(s16 *)(g+0x2a);
        (void)i;
    }
}
