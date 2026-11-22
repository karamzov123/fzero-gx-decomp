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
extern char lbl_80091258[];
extern char lbl_8009127C[];
extern u32 lbl_80186768[];

extern void fn_80046738(void);
extern void fn_80046718(void);
extern s32 fn_8004AEE4(ADXStream *stream);
extern s32 fn_8004AE78(ADXStream *stream);
extern void DCInvalidateRange(void *address, s32 size);
extern void fn_800474E4(char *);
extern char *strncpy(char *, const char *, size_t);

void fn_8004F7F8(void *address, s32 size);

void fn_8004F7F8(void *address, s32 size) {
    DCInvalidateRange(address, size);
}

s32 fn_8004F818(s32 arg0, s32 arg1, char *arg2, u32 *arg3, u32 *arg4, u32 *arg5) {
    s32 result;
    u32 *vals;
    s32 i;
    AdxfPartitionEntry *entry;
    u32 sum;

    if (arg0 < 0 || arg0 >= 0x100) {
        fn_800474E4(lbl_80091258);
        result = -3;
    } else if ((AdxfPartitionEntry *)lbl_80186768[arg0] == 0) {
        fn_800474E4(lbl_80091258);
        result = -3;
    } else if (arg1 < 0 || arg1 >= (s32)((AdxfPartitionEntry *)lbl_80186768[arg0])->count) {
        fn_800474E4(lbl_8009127C);
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

static inline void adxf_CloseSjStm(ADXFFile *file) {
    SJ *stream;
    if (file->sj != 0 && file->sjflag == 0) {
        if (lbl_80186764 == 1) {
            fn_8004F7F8(file->buf, file->bsize);
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
