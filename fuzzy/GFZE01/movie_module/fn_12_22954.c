/* Non-matching: best partial attempt (54.12% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieTmp {
    u32 a, b, c, d, e;
} MovieTmp;
extern void fn_12_24970(void *);
extern void fn_12_24950(void *);
extern void fn_12_2CFEC(void *);
extern s32 fn_12_24A88(void *, s32);
extern u32 fn_80058498(u32, u32, u32);

typedef struct Config {
    u32 pad0, a, b, c, d, e, f, g, h, i, j;
} Config;

static void clear16(void *p) {
    u32 i;
    for (i = 0; i < 16; i++) *(u32 *)((u8 *)p + i * 0x5c) = 0;
}

s32 fn_12_22954(void *obj, u8 *out, Config *cfg) {
    u32 n, rem, q, ok1, ok2, ok3, state1, state2, state3;
    u32 tmp[6];
    MovieTmp movie;
    u32 *p;

    n = cfg->b;
    q = cfg->j;
    rem = n - (n / q) * q;
    *(u32 *)(out + 0x5c) = cfg->a;
    *(u32 *)(out + 0x60) = *(u32 *)(out + 0x5c) + cfg->b;
    *(u32 *)(out + 0x64) = *(u32 *)(out + 0x60) + cfg->c;
    *(u32 *)(out + 0x68) = *(u32 *)(out + 0x64) + cfg->d;
    *(u32 *)(out + 0x6c) = *(u32 *)(out + 0x68) + cfg->e;
    *(u32 *)(out + 0x70) = *(u32 *)(out + 0x6c) + cfg->f;
    *(u32 *)(out + 0x74) = *(u32 *)(out + 0x70) + cfg->g;
    *(u32 *)(out + 0x78) = *(u32 *)(out + 0x74) + cfg->h;
    state1 = 4; ok1 = 0;
    if (n != 0) {
        state1 = 5; ok1 = 1;
        tmp[0] = 0; tmp[1] = cfg->a; tmp[2] = n-rem; tmp[3] = rem; tmp[4] = 0;
        p = 0;
        if ((s32)(n-rem) > 0) { tmp[4] = rem; tmp[5] = 0; p = (u32 *)fn_80058498(cfg->a, n-rem, rem); }
        if (p == 0) state1 = -1;
        else {
            fn_12_24970(&movie);
            *(u32 *)(out+4)=1;
            *(u32 *)(out+0x10)=tmp[0]; *(u32 *)(out+0x14)=(u32)p;
            *(u32 *)(out+0x18)=cfg->a; *(u32 *)(out+0x1c)=n-rem;
            *(u32 *)(out+0x20)=rem; *(u32 *)(out+0x24)=0;
            *(u32 *)(out+0x28)=0; *(u32 *)(out+0x2c)=0;
            *(u32 *)(out+0x30)=0; *(u32 *)(out+0x34)=0;
            fn_12_2CFEC(out+0x38); fn_12_24950(&movie);
        }
    }
    *(u32 *)out=state1; *(u32 *)(out+4)=ok1;
    *(u32 *)(out+8)=0; *(u32 *)(out+0xc)=0;
    *(u32 *)(out+0x4c)=9; *(u32 *)(out+0x50)=9;
    if (state1 != (u32)-1) state1 = 0;

    n=cfg->c; state2=4; ok2=0;
    if (n) {
        state2=5; ok2=1; rem=n-0x800;
        tmp[0]=0; tmp[1]=cfg->b; tmp[2]=rem; tmp[3]=0; tmp[4]=0; tmp[5]=0;
        p=0;
        if ((s32)rem>0) p=(u32 *)fn_80058498(cfg->b,rem,0x800);
        if (!p) state2=-1;
        else {
            fn_12_24970(&movie);
            *(u32 *)(out+0x78)=1;
            *(u32 *)(out+0x84)=0; *(u32 *)(out+0x88)=(u32)p;
            *(u32 *)(out+0x8c)=cfg->b; *(u32 *)(out+0x90)=rem;
            *(u32 *)(out+0x94)=0x800; *(u32 *)(out+0x98)=0;
            *(u32 *)(out+0x9c)=0; *(u32 *)(out+0xa0)=0;
            *(u32 *)(out+0xa4)=0; *(u32 *)(out+0xa8)=0;
            fn_12_2CFEC(out+0xac); fn_12_24950(&movie);
        }
    }
    *(u32 *)(out+0x74)=state2; *(u32 *)(out+0x78)=ok2;
    *(u32 *)(out+0x7c)=0; *(u32 *)(out+0x80)=0;
    *(u32 *)(out+0xc0)=9; *(u32 *)(out+0xc4)=9;

    n=cfg->d; state3=4; ok3=0;
    if (n) {
        state3=5; ok3=1; tmp[0]=0; tmp[1]=0; tmp[2]=0; tmp[3]=cfg->c; tmp[4]=n; tmp[5]=0;
        p=0; if ((s32)n>0) p=(u32 *)fn_80058498(cfg->c,n,0);
        if (!p) state3=-1;
        else {
            fn_12_24970(&movie);
            *(u32 *)(out+0xec)=1;
            *(u32 *)(out+0xf8)=0; *(u32 *)(out+0xfc)=(u32)p;
            *(u32 *)(out+0x100)=cfg->c; *(u32 *)(out+0x104)=n;
            *(u32 *)(out+0x108)=0; *(u32 *)(out+0x10c)=0;
            *(u32 *)(out+0x110)=0; *(u32 *)(out+0x114)=0;
            *(u32 *)(out+0x118)=0; *(u32 *)(out+0x11c)=0;
            fn_12_2CFEC(out+0x120); fn_12_24950(&movie);
        }
    }
    *(u32 *)(out+0xe8)=state3; *(u32 *)(out+0xec)=ok3;
    *(u32 *)(out+0xf0)=0; *(u32 *)(out+0xf4)=0;
    *(u32 *)(out+0x134)=9; *(u32 *)(out+0x138)=9;

    if (state1 != 0 || state2 != 0 || state3 != 0)
        return fn_12_24A88(obj, 0xff00040a);

    *(u32 *)(out+0x15c)=1; *(u32 *)(out+0x164)=0; *(u32 *)(out+0x168)=0;
    *(u32 *)(out+0x16c)=cfg->e; *(u32 *)(out+0x170)=cfg->e;
    *(u32 *)(out+0x174)=0; *(u32 *)(out+0x178)=0;
    *(u32 *)(out+0x17c)=(u32)obj+0x14e0;
    if ((s32)cfg->e < 16) clear16((void *)(out+0x17c));
    *(u32 *)(out+0x1d0)=2; *(u32 *)(out+0x1d8)=0; *(u32 *)(out+0x1dc)=0;
    *(u32 *)(out+0x1e0)=cfg->f; *(u32 *)(out+0x1e4)=cfg->f;
    *(u32 *)(out+0x1e8)=0; *(u32 *)(out+0x1ec)=0;
    *(u32 *)(out+0x1f0)=0; *(u32 *)(out+0x1f4)=0;
    *(u32 *)(out+0x1f8)=0; *(u32 *)(out+0x1fc)=0;
    *(u32 *)(out+0x200)=0; *(u32 *)(out+0x204)=0;
    *(u32 *)(out+0x208)=0; *(u32 *)(out+0x20c)=0;
    *(u32 *)(out+0x244)=1; *(u32 *)(out+0x24c)=0; *(u32 *)(out+0x250)=0;
    *(u32 *)(out+0x254)=cfg->g; *(u32 *)(out+0x258)=cfg->g;
    *(u32 *)(out+0x25c)=0; *(u32 *)(out+0x260)=0;
    *(u32 *)(out+0x264)=(u32)obj+0x14e0;
    if ((s32)cfg->g < 16) clear16((void *)(out+0x264));
    *(u32 *)(out+0x2b8)=2; *(u32 *)(out+0x2c0)=0; *(u32 *)(out+0x2c4)=0;
    *(u32 *)(out+0x2c8)=cfg->h; *(u32 *)(out+0x2cc)=cfg->h;
    *(u32 *)(out+0x2d0)=0; *(u32 *)(out+0x2d4)=0;
    *(u32 *)(out+0x2d8)=0; *(u32 *)(out+0x2dc)=0;
    *(u32 *)(out+0x2e0)=0; *(u32 *)(out+0x2e4)=0;
    *(u32 *)(out+0x2e8)=0; *(u32 *)(out+0x2ec)=0;
    *(u32 *)(out+0x2f0)=0; *(u32 *)(out+0x2f4)=0;
    *(u32 *)(out+0x32c)=3; *(u32 *)(out+0x330)=1;
    *(u32 *)(out+0x334)=0; *(u32 *)(out+0x338)=0;
    *(u32 *)(out+0x378)=9; *(u32 *)(out+0x37c)=9;
    *(u32 *)(out+0x33c)=0; *(u32 *)(out+0x340)=0;
    *(u32 *)(out+0x344)=0; *(u32 *)(out+0x348)=0;
    *(u32 *)(out+0x34c)=0; *(u32 *)(out+0x350)=0;
    *(u32 *)(out+0x354)=0; *(u32 *)(out+0x358)=0;
    *(u32 *)(out+0x35c)=0; *(u32 *)(out+0x360)=0;
    *(u32 *)(out+0x364)=0; *(u32 *)(out+0x368)=0;
    return 0;
}
