#include "types.h"


/* --- dol/fn_8004A80C.c --- */
typedef struct Fn8004A80C_Chunk {
    u8 *data;
    s32 len;
} Fn8004A80C_Chunk;

typedef struct Fn8004A80C_SJ Fn8004A80C_SJ;

typedef struct Fn8004A80C_SJVtbl {
    u8 pad_0[0x18];
    void (*GetChunk)(Fn8004A80C_SJ *sj, s32 id, s32 nbyte, Fn8004A80C_Chunk *ck);
    void (*UngetChunk)(Fn8004A80C_SJ *sj, s32 id, Fn8004A80C_Chunk *ck);
    void (*PutChunk)(Fn8004A80C_SJ *sj, s32 id, Fn8004A80C_Chunk *ck);
    s32 (*GetNumData)(Fn8004A80C_SJ *sj, s32 id);
} Fn8004A80C_SJVtbl;

struct Fn8004A80C_SJ {
    Fn8004A80C_SJVtbl *vtbl;
};

typedef struct Fn8004A80C_Stm {
    u8 pad_0[0x1];
    s8 stat;
    s8 rqrd;
    s8 retry;
    Fn8004A80C_SJ *sj;
    void *fs;
    s32 ofst;
    s32 len;
    s32 rdsize;
    s32 minsize;
    s32 nrd;
    Fn8004A80C_Chunk ck;
    s32 maxsct;
    s32 eossct;
    u32 total;
    void (*eoscb)(void *obj);
    void *eosobj;
    s32 bufsize;
    s8 unk_40;
    u8 pad_41[0x3];
    s8 req_stop;
    u8 pad_45[0xF];
    s32 pos;
    u32 limit;
} Fn8004A80C_Stm;

extern s32 lbl_8017D700;
extern s32 lbl_8017D704;
extern s32 fn_800546A0(void *fs);
extern void fn_80059B44(void);
extern void fn_80059AB4(void);
extern void fn_800589BC(Fn8004A80C_Chunk *ck, s32 nbyte, Fn8004A80C_Chunk *ck1, Fn8004A80C_Chunk *ck2);
extern void fn_80054930(void *fs, s32 offset, s32 origin);
extern s32 fn_80054870(void *fs, s32 nsct, u8 *buf);

static inline void fn_8004A80C_retry(Fn8004A80C_Stm *stm) {
    if (lbl_8017D700 >= 0) {
        if (stm->retry >= lbl_8017D700) {
            stm->stat = 4;
        } else {
            stm->retry++;
        }
    }
}

void fn_8004A80C(Fn8004A80C_Stm *stm) {
    Fn8004A80C_SJ *sj;
    s32 stat;
    s32 nbyte;
    s32 nsct;
    s32 end;
    Fn8004A80C_Chunk ck1;
    Fn8004A80C_Chunk ck2;
    Fn8004A80C_Chunk ck;

    sj = stm->sj;
    stat = fn_800546A0(stm->fs);
    fn_80059B44();
    if (stm->rqrd == 1) {
        if (stat == 1) {
            stm->rqrd = 0;
            fn_80059AB4();
            nbyte = stm->nrd << 11;
            fn_800589BC(&stm->ck, nbyte, &ck1, &ck2);
            sj->vtbl->PutChunk(sj, 1, &ck1);
            sj->vtbl->UngetChunk(sj, 0, &ck2);
            stm->pos += stm->nrd;
            stm->total += nbyte;
            stm->ck.data = NULL;
            stm->ck.len = 0;
            end = stm->len / 0x800 + (stm->len % 0x800 > 0);
            if (stm->pos == stm->eossct && stm->eoscb != NULL) {
                stm->eoscb(stm->eosobj);
            }
            if (stm->pos >= end) {
                stm->stat = 3;
            } else if ((stm->total >> 11) >= stm->limit && stm->limit < 0xFFFFF) {
                stm->stat = 3;
            }
            stm->retry = 0;
        } else if (stat == 3) {
            stm->rqrd = 0;
            fn_80059AB4();
            sj->vtbl->UngetChunk(sj, 0, &stm->ck);
            stm->ck.data = NULL;
            stm->ck.len = 0;
            fn_8004A80C_retry(stm);
        } else {
            fn_80059AB4();
        }
        return;
    }

    stm->rqrd = 1;
    stm->ck.data = NULL;
    stm->ck.len = 0;
    fn_80059AB4();
    if (stm->unk_40 == 1 || stm->req_stop == 1) {
        stm->rqrd = 0;
        return;
    }
    if (stm->len == 0) {
        stm->rqrd = 0;
        stm->nrd = 0;
        stm->stat = 3;
        return;
    }
    if (sj == NULL || sj->vtbl == NULL) {
        stm->rqrd = 0;
        lbl_8017D704++;
        return;
    }
    if (stm->bufsize - sj->vtbl->GetNumData(sj, 0) >= stm->minsize) {
        stm->rqrd = 0;
        return;
    }
    sj->vtbl->GetChunk(sj, 0, stm->rdsize, &ck);
    nsct = ck.len / 0x800;
    end = (nsct < stm->eossct - stm->pos) ? nsct : stm->eossct - stm->pos;
    nsct = stm->len / 0x800 - stm->pos;
    if (end < nsct) {
        nsct = end;
    }
    end = stm->maxsct;
    if (nsct < end) {
        end = nsct;
    }
    fn_80054930(stm->fs, stm->ofst + stm->pos, 0);
    stm->nrd = fn_80054870(stm->fs, end, ck.data);
    stm->ck.data = ck.data;
    stm->ck.len = ck.len;
    if (stm->nrd > 0) {
        return;
    }
    sj->vtbl->UngetChunk(sj, 0, &stm->ck);
    stm->ck.data = NULL;
    stm->ck.len = 0;
    stm->rqrd = 0;
    if (fn_800546A0(stm->fs) == 3) {
        fn_8004A80C_retry(stm);
    }
}

/* --- dol/fn_8004AC04.c --- */
/* --- dol/fn_8004AC04.c --- */
typedef struct AdxtVoice {
    u8 pad00[0x10];
    s32 unk10;
    u8 pad14[0x18];
    s32 unk2C;
} AdxtVoice;

void fn_8004AC04(AdxtVoice* p, int a)
{
    if (a >= 0) {
        p->unk2C = a;
        return;
    }
    {
        int q;
        q = p->unk10 % 2048 > 0;
        q = (p->unk10 / 2048) + q;
        p->unk2C = q;
    }
}

/* --- dol/fn_8004AC4C.c --- */
struct fn_8004AC4C_Arg0 {
    u8 pad_0[0x34];
    u32 unk_34;
    u32 unk_38;
};

void fn_8004AC4C(struct fn_8004AC4C_Arg0 *arg0, u32 arg1, u32 arg2) {
    arg0->unk_34 = arg1;
    arg0->unk_38 = arg2;
}

/* --- dol/fn_8004AC58.c --- */
/* --- dol/fn_8004AC58.c --- */
typedef struct Stream {
    s8 used;
    s8 status;
    s8 substatus;
    u8 pad0[5];
    void *handle;
    u8 pad1[0x14];
    u32 flags20;
    u8 pad2[0x1C];
    u8 pad3;
    s8 f41;
    s8 f42;
    s8 f43;
    s8 f44;
    s8 f45;
    u8 pad4[0x16];
} Stream;

extern void fn_800547C8(void *);
extern s32 fn_80058A40(s32 *value);
extern u8 lbl_8017D6FC[];
extern Stream lbl_8017D708[40];
extern void fn_8004A5F4(Stream *);

static inline void endStatus(Stream *arg0) {
    fn_80059B44();
    if (arg0->status == 2 && arg0->substatus == 1) {
        arg0->f44 = 1;
        if (arg0->f43 == 1) {
            arg0->f43 = 0;
        }
    } else {
        arg0->status = 1;
    }
    fn_80059AB4();
}

static inline void stopStream(Stream *arg0) {
    if (arg0->handle != NULL && arg0->f42 == 0) {
        fn_800547C8(arg0->handle);
    }
    fn_80059B44();
    arg0->status = 1;
    arg0->substatus = 0;
    arg0->flags20 = 0;
    fn_80059AB4();
    endStatus(arg0);
}

static inline void execServer(void) {
    s32 index;

    if (fn_80058A40((s32 *)lbl_8017D6FC) != 0) {
        for (index = 0; index < 40; index++) {
            if (lbl_8017D708[index].used == 1) {
                fn_8004A5F4(&lbl_8017D708[index]);
            }
        }
        *(s32 *)lbl_8017D6FC = 0;
    }
}

void fn_8004AC58(Stream *arg0) {
    stopStream(arg0);
    do {
        execServer();
    } while (arg0->status != 1 || arg0->flags20 != 0);
}

/* --- dol/fn_8004AD84.c --- */
/* --- dol/fn_8004AD84.c --- */

typedef struct Fn8004AD84 {
    s8 unk00;
    s8 unk01;
    s8 unk02;
    s8 unk03[0x3e];
    s8 unk41;
    s8 unk42;
    s8 unk43;
    s8 unk44;
} Fn8004AD84;

void fn_8004AD84(Fn8004AD84 *self) {
    fn_80059B44();
    if (self->unk01 == 2 && self->unk02 == 1) {
        self->unk44 = 1;
        if (self->unk43 == 1) {
            self->unk43 = 0;
        }
    } else {
        self->unk01 = 1;
    }
    fn_80059AB4();
}

/* --- dol/fn_8004ADF4.c --- */
extern void fn_80046718(void);
extern void fn_80046738(void);

s32 fn_8004ADF4(u32 arg0) {
    fn_80046738();
    *(u32 *)((u8 *)arg0 + 48) = 0;
    *(u8 *)((u8 *)arg0 + 3) = 0;
    if ((s32)*(u32 *)(arg0 + 16) == 0) {
    *(u8 *)((u8 *)arg0 + 1) = 3;
    } else {
    *(u8 *)((u8 *)arg0 + 1) = 2;
    }
    *(u8 *)((u8 *)arg0 + 2) = 0;
    *(u32 *)((u8 *)arg0 + 32) = 0;
    *(u32 *)((u8 *)arg0 + 36) = 0;
    *(u8 *)((u8 *)arg0 + 67) = 1;
    *(u32 *)((u8 *)arg0 + 88) = (0x100000 - 1);
    fn_80046718();
    return 1;
}

/* --- dol/fn_8004AE78.c --- */
struct fn_8004AE78_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

s32 fn_8004AE78(struct fn_8004AE78_Arg0 *arg0) {
    u32 v0;
    v0 = (u32)arg0;
    if (arg0->unk_8 != 0) {
    v0 = *(u32 *)(v0 + 84);
    return v0;
    }
    v0 = 0;
    return v0;
}

/* --- dol/fn_8004AE94.c --- */
typedef struct AdxtVoice_u4 {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0x40];
    s32 unk54;
} AdxtVoice_u4;

// Donor seed for fn_8004AE94 (addr 0x8004AE94)
// Extracted from adxt_8004AC04.c (original name: fn_8004AE94)

int fn_8004AE94(AdxtVoice_u4* p, int n)
{
    p->unk54 = n;
    if (p->unk54 * 2048 > p->unk10) {
        p->unk54 = p->unk10 / 2048 + (p->unk10 % 2048 > 0);
    }
    return p->unk54;
}
