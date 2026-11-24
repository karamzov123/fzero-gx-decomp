#include "types.h"

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

typedef struct ADXStream ADXStream;

typedef struct ADXFCommandRecord {
    u8 command;
    u8 phase;
    u16 sequence;
    void *file;
    s32 position;
    s32 length;
} ADXFCommandRecord;

typedef struct ADXFFile {
    s8 used;
    s8 state;
    s8 sjflag;
    s8 stop_requested;
    ADXStream *stm;
    SJ *sj;
    u8 reserved_0C[8];
    s32 skpos;
    u8 reserved_18[8];
    s32 rdsct;
    void *buf;
    s32 bsize;
    u8 reserved_2C[0x18];
} ADXFFile;

typedef struct {
    u8 pad0[8];
    u32 count;
    u8 padC[3];
    s8 type;
    u8 pad10[0x100];
    u32 field_110;
    u32 field_114;
} AdxfPartitionEntry;

extern s32 lbl_80186764;
extern ADXFFile lbl_80186B68[16];
extern u32 lbl_80186768[];

extern void fn_80046738(void);
extern void fn_80046718(void);
extern s32 fn_8004AEE4(ADXStream *stream);
extern s32 fn_8004AE78(ADXStream *stream);

extern void fn_800474E4(const char *message);
extern char *strncpy(char *, const char *, size_t);

void ADXF_Ocbi(void *address, s32 size);

void *memset(void *destination, int value, unsigned long size);
extern s32 lbl_80186640;
extern u16 lbl_80186644[16];
extern ADXFCommandRecord lbl_80186664[16];
extern void fn_8004AC58(ADXStream *stream);
extern void fn_8004AEF0(ADXStream *stream);
extern void fn_8004B1DC(ADXStream *stream);
void ADXF_Close(ADXFFile *file);

s32 fn_8004F818(s32 arg0, s32 arg1, char *arg2, u32 *arg3, u32 *arg4, u32 *arg5) {
    s32 result;
    u32 *vals;
    s32 i;
    AdxfPartitionEntry *entry;
    u32 sum;

    if (arg0 < 0 || arg0 >= 0x100) {
        fn_800474E4("E9040828:'ptid' is range outside.");
        result = -3;
    } else if ((AdxfPartitionEntry *)lbl_80186768[arg0] == 0) {
        fn_800474E4("E9040828:'ptid' is range outside.");
        result = -3;
    } else if (arg1 < 0 || arg1 >= (s32)((AdxfPartitionEntry *)lbl_80186768[arg0])->count) {
        fn_800474E4("E9040828:'flid' is range outside.");
        result = -3;
    } else {
        result = 0;
    }

    if (result < 0) {
        *arg3 = 0;
        *arg4 = -1;
        *arg5 = -1;
        return result;
    }

    entry = (AdxfPartitionEntry *)lbl_80186768[arg0];
    if (entry->type == 1) {
        vals = (u32 *)((u8 *)entry + 0x11C);
        sum = *(u32 *)((u8 *)entry + 0x118);
        for (i = 0; i < arg1; i++) {
            sum += vals[i];
        }
        *arg5 = vals[arg1];
    } else {
        u16 *vals16 = (u16 *)((u8 *)entry + 0x11A);
        sum = *(u16 *)((u8 *)entry + 0x118);
        for (i = 0; i < arg1; i++) {
            sum += vals16[i];
        }
        *arg5 = vals16[arg1];
    }
    strncpy(arg2, (char *)entry + 0x10, 0x100);
    *arg3 = *(u32 *)((u8 *)entry + 0x110);
    *arg4 = *(u32 *)((u8 *)entry + 0x114) + sum;
    return result;
}

static inline void adxf_SetCmdHstry(s32 command, s32 phase, ADXFFile *file, s32 position,
                                    s32 length) {
    ADXFCommandRecord *history;
    lbl_80186640 %= 16;
    history = &lbl_80186664[lbl_80186640];
    if (phase == 0) {
        lbl_80186644[command]++;
    }
    history->command = command;
    history->phase = phase;
    history->sequence = lbl_80186644[command];
    history->file = file;
    history->position = position;
    history->length = length;
    lbl_80186640++;
}

static inline void adxf_CloseSjStm(ADXFFile *file) {
    SJ *stream;
    if (file->sj != 0 && file->sjflag == 0) {
        if (lbl_80186764 == 1) {
            ADXF_Ocbi(file->buf, file->bsize);
        }
        stream = file->sj;
        file->sj = 0;
        stream->interface->destroy(stream);
    }
}

static inline void adxf_ExecOne(ADXFFile *file) {
    if (file->state == 2) {
        file->state = fn_8004AEE4(file->stm);
        file->rdsct = fn_8004AE78(file->stm) - file->skpos;
        if (file->state == 3 || file->state == 4) {
            file->skpos += file->rdsct;
            adxf_CloseSjStm(file);
        }
    }
    if (file->stop_requested == 1 && fn_8004AEE4(file->stm) == 1) {
        file->rdsct = fn_8004AE78(file->stm) - file->skpos;
        adxf_CloseSjStm(file);
        file->state = 1;
        file->stop_requested = 0;
    }
}

void ADXF_ExecServer(void) {
    s32 index;
    fn_80046738();
    for (index = 0; index < 16; index++) {
        if (lbl_80186B68[index].used == 1) {
            adxf_ExecOne(&lbl_80186B68[index]);
        }
    }
    fn_80046718();
}

static inline s32 adxf_Stop(ADXFFile *file) {
    adxf_SetCmdHstry(5, 0, file, -1, -1);
    if (file == 0) {
        fn_800474E4("E9040822:'adxf' is NULL.(ADXF_Stop)");
        return -1;
    }
    if (file->state == 1) {
        return file->skpos;
    }
    if (file->state == 3) {
        file->state = 1;
        return file->skpos;
    }
    if (file->stm == 0) {
        fn_800474E4("E9040823:'adxf->stm' is NULL.(ADXF_Stop)");
        return -1;
    }
    fn_8004AC58(file->stm);
    fn_80046738();
    file->rdsct = fn_8004AE78(file->stm) - file->skpos;
    adxf_CloseSjStm(file);
    file->state = 1;
    fn_80046718();
    adxf_SetCmdHstry(5, 1, file, -1, -1);
    return file->skpos;
}

void ADXF_CloseAll(void) {
    s32 index;

    for (index = 0; index < 16; index++) {
        if (lbl_80186B68[index].used == 1) {
            ADXF_Close(&lbl_80186B68[index]);
        }
    }
}

void ADXF_Close(ADXFFile *file) {
    ADXStream *stream;
    adxf_SetCmdHstry(3, 0, file, -1, -1);
    if (file != 0) {
        if (file->state == 2) {
            adxf_Stop(file);
        }
        if (file->stm != 0) {
            stream = file->stm;
            file->stm = 0;
            fn_8004AEF0(stream);
            fn_8004B1DC(stream);
        }
        memset(file, 0, sizeof(*file));
        adxf_SetCmdHstry(3, 1, file, -1, -1);
    }
}
