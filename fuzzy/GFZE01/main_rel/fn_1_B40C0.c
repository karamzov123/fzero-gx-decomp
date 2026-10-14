/* Non-matching: best partial attempt (21.62% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/card.h"
#include "dolphin/card/CARDPriv.h"
#include "rel/main_rel/memcard.h"

extern void* lbl_801A6410;
extern s32 lbl_801A66B4;
extern const f32 lbl_1_rodata_4CA8;
extern void fn_1_46B4(u32, u32, const char *, int);
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
extern const char* fn_80019C48(void);
extern u8* fn_80083970(u8 *, const u8 *);
extern s32 strncmp(const char *, const char *, size_t);
extern size_t strlen(const char *);

typedef struct {
    u32 unk_0, status, flags;
    u32 unk_C[5];
    u8 data_20[0x28];
    u8 name_48[4];
    u8 name_4C[0x48];
    u32 unk_94;
} Node;

typedef struct {
    u8 unk_0, unk_1, unk_2, state, type, prev, next, unk_7;
    s16 unk_8, unk_A;
    u8 unk_C[0x1C];
    s8 timer;
    u8 unk_29, flags, unk_2B, count;
    u8 pad_2D[3];
    Node *node;
    u8 pad_34[0x50];
    f32 f84[2];
} Card;

#define B (*(u8 *)((u8 *)&lbl_1_bss_716C0 + off))
#define FLAG(p, mask) ((p)->flags & (mask))
void fn_1_B40C0(Card *c) {
    u8 *data = (u8 *)&lbl_1_data_35AC8;
    u8 *bss = (u8 *)&lbl_1_bss_716C0;
    u32 *jt = (u32 *)&jumptable_1_data_3CD44;
    Node *p;
    s32 e, n, i, found;
    u8 *q;
    for (;;) {
        u8 code = c->type;
        if (code == 0xff) break;
        p = c->node;
        switch (code) {
        case 1:
            p->flags &= ~0x10000;
            if (p->flags & 0x10000) {
                c->state = 0x1b;
            } else if (lbl_1_bss_9F8.unk_8 & 0x100) {
                c->state = 0x1b;
            } else if ((lbl_1_bss_9F8.unk_8 & 8) && !(p->flags & 2)) {
                if (c->type == 3 && *(u32 *)((u8 *)c + 0xc)) {
                    while (CARDUnmount(c->unk_0) == -1) {}
                    fn_1_46B4(*(u32 *)lbl_801A6410, *(u32 *)((u8 *)c + 0xc), (const char *)data + 0x6cf0, 0x1bd0);
                    c->unk_7 = 0;
                    *(u32 *)((u8 *)c + 0xc) = 0;
                    p->unk_0 = p->unk_0;
                }
                if (c->next != 0xff) {
                    c->state = c->next;
                    c->next = 0xff;
                } else c->state = c->type;
                c->unk_8 = -1; c->unk_A = -1;
                c->flags &= ~2;
            } else if ((lbl_1_bss_9F8.unk_8 & 4) && (p->flags & 0x200)) {
                c->state = 5;
                p->flags &= ~0x20000;
                p->flags |= 0x200;
                c->flags = (c->flags & ~2) | 0x10;
            }
            bss[0x5c49] = 0;
            break;
        case 27:
            if (p->flags & 0x10000) c->unk_2 = 0xfe;
            else if (lbl_1_bss_9F8.unk_8 & 0x100) c->unk_2 = 0xfe;
            break;
        case 3:
            e = (s8)c->unk_1;
            if (e == -127) {
                p->status = e; c->state = 1; break;
            }
            e = p->status;
            if (e == -5) { p->flags |= 2; c->state = 1; }
            else if (e == -128 || e == -3) c->state = 1;
            else if (e == -13) {
                if (p->flags & 0x10000) { c->flags |= 4; c->unk_2=0xfe; }
                else if (lbl_801A66B4 == 5) c->state=5;
                else { p->flags |= 0x400; c->state=1; }
            } else if (e == -6 || e == -1) {}
            else if (e < -13 || e >= 1) c->state=0;
            else c->state=4;
            break;
        case 4:
            e=p->status;
            if (e == -5) {p->flags|=2;c->state=1;}
            else if(e==-128 || e==-3) c->state=1;
            else if(e==-13) {
                if(p->flags&0x10000){c->flags|=4;c->unk_2=0xfe;}
                else if(lbl_1_bss_9F8.unk_8&0x100){c->state=5;}
                else {p->flags|=0x400;c->state=1;}
            } else if(e==-6) {
                if(p->flags&0x10000){c->flags|=4;c->unk_2=0xfe;} else c->state=5;
            } else if(e==-1) {}
            else if(e < -13 || e>=1) c->state=0;
            else c->state=7;
            break;
        case 5:
            if (p->status == 0) break;
            if (!(c->flags & 1)) { c->timer=12; c->flags|=1; e=0; }
            else { e=(s8)c->timer; if(e>0){c->timer--;e=0;}else e=1; }
            if (!e) break;
            if (p->status==2 || *(u8 *)((u8 *)p+1)==1) {p->status=-126;c->state=1;}
            else {c->state=6;p->flags|=0x200;}
            break;
        case 6:
            e=p->status;
            if(e==-3) c->state=1;
            else if(e==-5){p->flags|=2;c->state=1;}
            else if(e==-128 || e==-3) c->state=1;
            else if(e==0){c->state=0x16;p->flags &= ~0x10000;}
            else if(e!=-1) c->state=0;
            break;
        case 7:
            e=p->status;
            if(e==-2 || e==-128) c->state=1;
            else if(e==-3) c->state=1;
            else if(e==0) c->state=0x23;
            else if(e!=-1) c->state=0;
            break;
        case 22:
            if(lbl_1_bss_9F8.unk_8 & 0x100){c->state=0x1b;p->status=-121;}
            break;
        case 35:
            if (p->flags & 0x20000000) {
                if (!(p->flags & 0x10000000)) {c->timer=45; p->flags|=8; e=0;}
                else {e=(s8)c->timer;if(e>0){c->timer--;e=0;}else e=1;}
                if(e) {
                    fn_1_46B4(*(u32 *)lbl_801A6410,p->status,(const char *)data+0x6cf0,0x3ec);
                    *(u32 *)((u8 *)c+0x24)=0;
                    c->unk_2=c->state=c->type=c->prev=c->next=0xff;c->unk_7=0;
                    c->unk_8=c->unk_A=-1;
                    *(u32 *)((u8 *)c+0x30)=0;
                    c->f84[0]=lbl_1_rodata_4CA8;c->f84[1]=lbl_1_rodata_4CA8;
                    c->flags &= ~2; bss[0x5c08]=0;bss[0x1f8]=1;
                }
            } else if(lbl_1_bss_9F8.unk_8&0x100) {
                fn_1_46B4(*(u32 *)lbl_801A6410,p->status,(const char *)data+0x6cf0,0x3ec);
                *(u32 *)((u8 *)c+0x24)=0;
                c->unk_2=c->state=c->type=c->prev=c->next=0xff;c->unk_7=0;
                c->unk_8=c->unk_A=-1; *(u32 *)((u8 *)c+0x30)=0;
                c->f84[0]=0;c->f84[1]=0;c->flags &= ~2;bss[0x5c08]=0;bss[0x1f8]=1;
            }
            break;
        case 38: c->state=3; break;
        default:
            if (code > 0x26) {
                OSReport((const char *)data+0x6ddc);
                OSReport((const char *)data+0x6df0,c->state);
                OSPanic((const char *)data+0x6cf0,0x1bbe,(const char *)data+0x6e04);
            } else if (code == 34) {
                /* status poll */
            }
        }
        if (c->node) bss[0x1f4]=c->node->status;
    }
}
