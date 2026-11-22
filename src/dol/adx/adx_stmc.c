#include "types.h"

extern u8 lbl_8017D708[3680];
extern s32 lbl_8017D6FC;
extern void fn_800547C8(void *);
extern void fn_80054AB0(void *);
extern s32 fn_80059B44(void);
extern s32 fn_80059AB4(void);
extern void *fn_80054B6C(char *, void *, int);
extern s32 fn_80054930(void *, s32, s32);
extern s32 fn_800549F0(void *);
extern s32 fn_800546A0(void *);
extern s32 fn_80054870(void *, s32, u8 *);
extern s32 fn_80058A40(s32 *);
extern void *memset(void *, int, u32);
void fn_8004A5F4(void *);
void fn_8004A80C(void *);


typedef struct SJCK {
    unsigned char *data;
    int len;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface SJInterface;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface {
    void *reserved[3];
    void (*destroy)(SJ *sj);
    const void *(*get_uuid)(SJ *sj);
    void (*reset)(SJ *sj);
    void (*get_chunk)(SJ *sj, int channel, int max_size, SJCK *chunk);
    void (*unget_chunk)(SJ *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
    int (*get_num_data)(SJ *sj, int channel);
    int (*is_get_chunk)(SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ *sj, SJErrorCallback callback, void *object);
};

struct SJ {
    const SJInterface *interface;
};

enum {
    ADXSTM_STATUS_STOP = 1,
    ADXSTM_STATUS_READING = 2,
    ADXSTM_STATUS_END = 3,
    ADXSTM_STATUS_ERROR = 4,
    ADXSTM_MAX_SECTORS = 0xFFFFF,
    ADXSTM_SECTOR_SIZE = 0x800,
    ADXSTM_NUM_OBJECTS = 40
};

typedef struct CvFsObject CvFsObject;

typedef struct StmExec_ADXStream StmExec_ADXStream;

typedef void (*StmExec_ADXStreamEosCallback)(void *object);

struct StmExec_ADXStream {
    s8 used;
    s8 status;
    s8 read_active;
    s8 retry_count;
    SJ *sj;
    CvFsObject *file;
    s32 file_offset;
    s32 file_size;
    s32 file_sectors;
    s32 maximum_buffer_size;
    s32 minimum_buffer_size;
    s32 request_sectors;
    SJCK request_chunk;
    s32 maximum_request_sectors;
    s32 eos_sector;
    s32 transferred_bytes;
    StmExec_ADXStreamEosCallback eos_callback;
    void *eos_object;
    s32 sj_buffer_size;
    s8 stop_requested;
    s8 bind_requested;
    s8 release_requested;
    s8 start_requested;
    s8 stop_pending;
    s8 file_open;
    s8 realtime;
    u8 reserved_4B[1];
    const char *filename;
    void *directory;
    s32 position;
    s32 transfer_limit;
};

void ADXSTM_ExecServer(void) {
    s32 index;
    if (fn_80058A40(&lbl_8017D6FC) != 0) {
        for (index = 0; index < ADXSTM_NUM_OBJECTS; index++) {
            if (((StmExec_ADXStream *)lbl_8017D708)[index].used == 1) {
                fn_8004A5F4(&((StmExec_ADXStream *)lbl_8017D708)[index]);
            }
        }
        lbl_8017D6FC = 0;
    }
}

typedef struct ADXStream {
    s8 used;
    s8 status;
    s8 read_active;
    s8 retry_count;
    void *sj;
    void *file;
    s32 file_offset;
    s32 file_size;
    u8 pad_14[0x2D];
    s8 stop_requested;
    s8 bind_requested;
    s8 release_requested;
    s8 start_requested;
    s8 stop_pending;
    u8 pad_46[6];
    char *filename;
    void *directory;
    /* volatile: retail reloads this field from memory (lwz) after storing it */
    volatile s32 position;
} ADXStream;

extern char lbl_80090990[];
extern void fn_80047464(char *message, char *filename);
void fn_8004A5F4(void *arg0_v) {
    ADXStream *arg0 = (ADXStream *)arg0_v;
    s32 sectors;
    s32 bytes;

    if (arg0->read_active == 0) {
        if (arg0->start_requested == 1) {
            arg0->start_requested = 0;
            if (arg0->release_requested == 0) {
                arg0->status = 1;
            }
        }
        if (arg0->bind_requested == 1) {
            void *handle = arg0->file;
            if (handle != 0) {
                arg0->file = 0;
                fn_80054AB0(handle);
            }
            arg0->bind_requested = 0;
            arg0->stop_pending = 0;
        }
        fn_80059B44();
        if (arg0->stop_requested == 1) {
            arg0->stop_pending = 1;
            fn_80059AB4();
            if (arg0->file == 0) {
                void *handle = fn_80054B6C(arg0->filename, arg0->directory, 0);
                arg0->file = handle;
                if (handle == 0) {
                    fn_80047464(lbl_80090990, arg0->filename);
                    arg0->status = 4;
                    arg0->stop_pending = 0;
                    arg0->stop_requested = 0;
                    return;
                }
                fn_80054930(arg0->file, 0, 2);
                sectors = fn_800549F0(arg0->file);
                bytes = sectors << 11;
                fn_80054930(arg0->file, 0, 0);
                if (arg0->file_size + 0x80010000u == 0xF800u) {
                    arg0->file_size = bytes;
                } else {
                    if (arg0->file_offset > sectors) {
                        arg0->file_offset = sectors;
                    }
                    if ((arg0->file_size / 0x800) + arg0->file_offset > sectors) {
                        arg0->file_size = (sectors - arg0->file_offset) * 0x800;
                    }
                }
                arg0->position = 0;
                if (arg0->position * 0x800 > arg0->file_size) {
                    arg0->position = (arg0->file_size / 0x800) +
                        (arg0->file_size % 0x800 > 0);
                }
                arg0->stop_requested = 0;
            }
        } else {
            fn_80059AB4();
        }
        if (arg0->release_requested == 1) {
            arg0->release_requested = 0;
        }
    }
    if (arg0->status == 2) {
        if (arg0->stop_pending == 1) {
            fn_8004A80C(arg0);
        }
    }
}

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
extern void fn_800589BC(Fn8004A80C_Chunk *ck, s32 nbyte, Fn8004A80C_Chunk *ck1, Fn8004A80C_Chunk *ck2);
static inline void fn_8004A80C_retry(Fn8004A80C_Stm *stm) {
    if (lbl_8017D700 >= 0) {
        if (stm->retry >= lbl_8017D700) {
            stm->stat = 4;
        } else {
            stm->retry++;
        }
    }
}

void fn_8004A80C(void *stm_v) {
    Fn8004A80C_Stm *stm = (Fn8004A80C_Stm *)stm_v;
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

struct fn_8004AC4C_Arg0 {
    u8 pad_0[0x34];
    u32 unk_34;
    u32 unk_38;
};

void fn_8004AC4C(struct fn_8004AC4C_Arg0 *arg0, u32 arg1, u32 arg2) {
    arg0->unk_34 = arg1;
    arg0->unk_38 = arg2;
}

typedef struct StmA80C_Stream {
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
} StmA80C_Stream;

static inline void endStatus_A80C(StmA80C_Stream *arg0) {
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

static inline void stopStmA80C_Stream(StmA80C_Stream *arg0) {
    if (arg0->handle != NULL && arg0->f42 == 0) {
        fn_800547C8(arg0->handle);
    }
    fn_80059B44();
    arg0->status = 1;
    arg0->substatus = 0;
    arg0->flags20 = 0;
    fn_80059AB4();
    endStatus_A80C(arg0);
}

static inline void execServer_A80C(void) {
    s32 index;

    if (fn_80058A40(&lbl_8017D6FC) != 0) {
        for (index = 0; index < 40; index++) {
            if (((StmA80C_Stream *)lbl_8017D708)[index].used == 1) {
                fn_8004A5F4(&((StmA80C_Stream *)lbl_8017D708)[index]);
            }
        }
        lbl_8017D6FC = 0;
    }
}

void fn_8004AC58(StmA80C_Stream *arg0) {
    stopStmA80C_Stream(arg0);
    do {
        execServer_A80C();
    } while (arg0->status != 1 || arg0->flags20 != 0);
}

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

struct fn_8004AEE4_Arg0 {
    u8 pad_0[0x1];
    s8 unk_1;
};

s32 fn_8004AEE4(struct fn_8004AEE4_Arg0 *arg0) {
    return arg0->unk_1;
}

typedef struct StmAEF0_Stream {
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
} StmAEF0_Stream;

static inline void endStatus_AEF0(StmAEF0_Stream *arg0) {
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

static inline void stopStmAEF0_Stream(StmAEF0_Stream *arg0) {
    if (arg0->handle != NULL && arg0->f42 == 0) {
        fn_800547C8(arg0->handle);
    }
    fn_80059B44();
    arg0->status = 1;
    arg0->substatus = 0;
    arg0->flags20 = 0;
    fn_80059AB4();
    endStatus_AEF0(arg0);
}

static inline void execServer_AEF0(void) {
    s32 index;

    if (fn_80058A40((s32 *)((u8 *)&lbl_8017D6FC)) != 0) {
        for (index = 0; index < 40; index++) {
            if (((StmAEF0_Stream *)lbl_8017D708)[index].used == 1) {
                fn_8004A5F4(&((StmAEF0_Stream *)lbl_8017D708)[index]);
            }
        }
        *(s32 *)((u8 *)&lbl_8017D6FC) = 0;
    }
}

void fn_8004AEF0(StmAEF0_Stream *arg0) {
    stopStmAEF0_Stream(arg0);
    do {
        execServer_AEF0();
    } while (arg0->status != 1 || arg0->flags20 != 0);
    endStatus_AEF0(arg0);
    fn_80059B44();
    if (arg0->f45 == 1) {
        arg0->f42 = 1;
    }
    arg0->f41 = 0;
    fn_80059AB4();
    for (;;) {
        if (arg0->f45 == 0) {
            break;
        }
        execServer_AEF0();
    }
}

typedef struct Fn8004B0EC {
    s8 unk00;
    s8 unk01;
    s8 unk02;
    s8 unk03[0x3e];
    s8 unk41;
    s8 unk42;
    s8 unk43;
    s8 unk44;
    s8 unk45;
} Fn8004B0EC;

void fn_8004B0EC(Fn8004B0EC *self) {
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
    fn_80059B44();
    if (self->unk45 == 1) {
        self->unk42 = 1;
    }
    self->unk41 = 0;
    fn_80059AB4();
}

void fn_8004B180(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 v0;
    fn_80059B44();
    *(u32 *)((u8 *)arg0 + 12) = arg3;
    v0 = (arg4 << 11);
    *(u32 *)((u8 *)arg0 + 16) = v0;
    *(u32 *)((u8 *)arg0 + 76) = arg1;
    *(u32 *)((u8 *)arg0 + 80) = arg2;
    *(u8 *)((u8 *)arg0 + 65) = 1;
    fn_80059AB4();
}

void fn_8004B1DC(StmAEF0_Stream *arg0) {
    if (arg0 != NULL) {
        stopStmAEF0_Stream(arg0);
        do {
            execServer_AEF0();
        } while (arg0->status != 1 || arg0->flags20 != 0);
        stopStmAEF0_Stream(arg0);
        do {
            execServer_AEF0();
        } while (arg0->status != 1 || arg0->flags20 != 0);
        endStatus_AEF0(arg0);
        fn_80059B44();
        if (arg0->f45 == 1) {
            arg0->f42 = 1;
        }
        arg0->f41 = 0;
        fn_80059AB4();
        for (;;) {
            if (arg0->f45 == 0) {
                break;
            }
            execServer_AEF0();
        }
        arg0->used = 0;
        memset(arg0, 0, 0x5C);
    }
}

typedef struct StmSource StmSource;

typedef struct StmSourceVtbl {
    u8 reserved_00[0x24];
    s32 (*get_count)(StmSource *src, s32 flag);
} StmSourceVtbl;

struct StmSource {
    StmSourceVtbl *vtbl;
};

typedef struct AdxStm {
    s8 used;
    s8 unk_01;
    s8 unk_02;
    u8 pad_03;
    StmSource *src;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u8 pad_1C[0x0C];
    s32 unk_28;
    s32 unk_2C;
    u8 pad_30[0x0C];
    s32 unk_3C;
    s8 unk_40;
    u8 pad_41[0x13];
    s32 unk_54;
    s32 unk_58;
} AdxStm;

extern s32 lbl_8012B900[4];
extern s32 lbl_8017D6F8[];
extern void fn_80046738(void);
extern void fn_80046718(void);

static inline AdxStm *adxstm_CreateIn(StmSource *src, s32 start, s32 count) {
    AdxStm *stm;
    u32 i;

    stm = 0;
    for (i = 0; (s32)i < count; i++) {
        stm = &((AdxStm *)lbl_8017D708)[start + i];
        if (stm->used == 0) {
            break;
        }
    }
    if ((s32)i == count) {
        return 0;
    }
    fn_80046738();
    stm->unk_01 = 1;
    stm->unk_02 = 0;
    stm->src = src;
    stm->unk_08 = 0;
    stm->unk_0C = 0;
    stm->unk_10 = 0;
    stm->unk_28 = 0x200;
    stm->unk_54 = 0;
    stm->unk_58 = 0xFFFFF;
    stm->unk_2C = stm->unk_10 / 2048;
    if (stm->unk_10 % 2048 > 0) {
        stm->unk_2C++;
    }
    if (stm->src != 0) {
        stm->unk_3C = src->vtbl->get_count(src, 0) + src->vtbl->get_count(src, 1);
        stm->unk_18 = stm->unk_14 = stm->unk_3C;
    }
    stm->unk_40 = 0;
    stm->used = 1;
    fn_80046718();
    return stm;
}

AdxStm *fn_8004B4E0(StmSource *src, s32 kind) {
    s32 *config = lbl_8012B900;
    if (kind < 0x100) {
        return adxstm_CreateIn(src, ((lbl_8017D6F8)[0]), config[0]);
    }
    return adxstm_CreateIn(src, config[1], config[2]);
}

// fn_8004B79C: empty in retail (single blr).
void fn_8004B79C(void) {
}

s32 fn_8004B7A0(void) {
    memset(lbl_8017D708, 0, 3680);
    return 1;
}

extern u32 fn_80046F7C(void);

void fn_8004B7D4(void) {
    fn_80046F7C();
}
