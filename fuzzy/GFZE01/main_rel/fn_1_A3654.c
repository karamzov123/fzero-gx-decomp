/* Non-matching: best partial attempt (94.39% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sound.h"

struct snd_ent {
    u8 a[2];
    u8 flag2;
    u8 rest[0x14 - 3];
};

struct snd_hdr {
    u8 pad_000[0x740];
    u8 unk_740;
    u8 pad_741[3];
    u32 unk_744;
    u8 pad_748[0x74C - 0x748];
    u8 ent[0x830 - 0x74C];
    u32 unk_830[1];
    u8 pad_834[0x894 - 0x834];
    s16 unk_894[1];
};

extern f32 fn_1_8652C(void *);
extern u32 fn_1_864E8(void *);
extern u32 fn_1_864FC(void *);
extern void * fn_1_86254(void *);
extern s32 fn_80067898(u32);
extern const f32 lbl_1_rodata_4540;
extern u32 lbl_801A66C8;

static s32 iabs(s32 x) {
    return x < 0 ? -x : x;
}

#define CHK(v) if (sp->unk_740 == 0 && sp->unk_744 <= 0x2D) fn_80067898(v)
#define TBL(p) (((u32 *)((u8 *)sp + 0x830))[p])
#define HPV(p) (((s16 *)((u8 *)sp + 0x894))[p])
#define ENT(p) (((struct snd_ent *)((u8 *)sp + 0x74C))[p])

void fn_1_A3654(void *arg0, u32 arg1) {
    f32 f;
    struct snd_hdr *sp;
    u32 t1;
    u32 t2;
    u32 p1;
    void *p0;
    void *cur;
    s16 *hp;

    p1 = arg1;
    p0 = arg0;
    sp = (struct snd_hdr *)&lbl_1_bss_6EA98;
    f = fn_1_8652C(p0);
    t1 = fn_1_864E8(p0);
    (void) t1;  /* fzgx: keeps the web at its definition */
    t2 = fn_1_864FC(p0);
    hp = (s16 *)((u8 *)sp + 0x74C);

    if (ENT(p1).flag2 != 0) {
        if ((t1 & 0x8) != 0 && (TBL(p1) & 0x8) == 0) {
            CHK(0xA9090E00);
        } else if ((t1 & 0x20000) != 0 && (TBL(p1) & 0x20000) == 0) {
            CHK(0xA9091D00);
        } else if ((((0x80) & (t1))) != 0 && (TBL(p1) & 0x80) == 0
                   && (t1 & 0x200) == 0) {
            CHK(0xA9091100);
        }
        if ((((0x100000) & (t1))) != 0) {
            CHK(0xA9091300);
        } else if ((t1 & 0x80000) != 0) {
            CHK(0xA9091400);
        }
        if (t1 & 0x200) {
            return;
        }
        if ((t1 & 0x10000) != 0) {
            if ((TBL(p1) & 0x10000) == 0) {
                CHK(0xA9091C00);
            }
            CHK(0xA9091600);
        }
        cur = fn_1_86254(p0);
        if (iabs(*(s16 *)((u8 *)cur + 0x4B0)) >= 0x64) {
            if (hp[p1] == 0) {
                if (f > lbl_1_rodata_4540) {
                    CHK(0xA9091B00);
                }
                hp[p1] = *(s16 *)((u8 *)cur + 0x4B0);
            }
        }
        if (iabs(*(s16 *)((u8 *)cur + 0x4B0)) < 0x64) {
            if (hp[p1] != 0) {
                CHK(0xA9091C00);
                hp[p1] = 0;
            }
        }
    }
    if ((t1 & 0x80) != 0) {
        if ((TBL(p1) & 0x80) == 0) {
            CHK(0xA9091C00);
        }
        CHK(0xA9091600);
        hp[p1] = 0;
    }
    if ((t2 & 0x10) != 0) {
        if (((lbl_801A66C8 + 1) & 0xE0000000) == 0) {
            CHK(0xA9092E00);
            CHK(0xA9091200);
        }
    }
}
