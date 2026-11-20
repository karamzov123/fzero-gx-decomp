#include "types.h"


/* --- dol/fn_8004FC94.c --- */
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

void fn_8004FC94(ADXFFile *file);

void *memset(void *destination, int value, unsigned long size);

extern s32 lbl_80186640;

extern u16 lbl_80186644[16];

extern ADXFCommandRecord lbl_80186664[16];

extern s32 lbl_80186764;

extern void fn_80046738(void);

extern void fn_80046718(void);

extern s32 fn_8004AE78(ADXStream *stream);

extern void fn_8004AC58(ADXStream *stream);

extern void fn_8004AEF0(ADXStream *stream);

extern void fn_8004B1DC(ADXStream *stream);

extern void fn_8004F7F8(void *address, s32 size);

extern void fn_800474E4(const char *message);

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
            fn_8004F7F8(file->buf, file->bsize);
        }
        stream = file->sj;
        file->sj = 0;
        stream->interface->destroy(stream);
    }
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

void fn_8004FC94(ADXFFile *file) {
    ADXStream *stream;
    adxf_SetCmdHstry(3, 0, file, -1, -1);
    if (file != 0) {
        if (file->state == 2) {
            adxf_Stop(file);
        }
        if (file->stm != 0) {
            /* removed */
            stream = file->stm;
            file->stm = 0;
            fn_8004AEF0(stream);
            fn_8004B1DC(stream);
        }
        memset(file, 0, sizeof(*file));
        adxf_SetCmdHstry(3, 1, file, -1, -1);
    }
}

/* --- dol/fn_8004FF68.c --- */
/* --- dol/fn_8004FF68.c --- */
typedef struct Fn8004FF68_Stream Fn8004FF68_Stream;

typedef struct Fn8004FF68_StreamVtbl {
    u8 pad_0[0x24];
    s32 (*unk_24)(Fn8004FF68_Stream *, s32);
} Fn8004FF68_StreamVtbl;

struct Fn8004FF68_Stream {
    Fn8004FF68_StreamVtbl *vtbl;
};

typedef struct Fn8004FF68_BitReader {
    u8 pad_0[0x4];
    Fn8004FF68_Stream *stream;
    s32 buffer;
    s32 bits_left;
    s32 bit_pos;
    u8 pad_14[0x10];
    s32 eof;
} Fn8004FF68_BitReader;

extern u32 lbl_801309C0[];
extern u32 lbl_80186FA8;
extern void fn_800502A0(Fn8004FF68_BitReader *);

static inline void fn_8004FF68_SkipBits(Fn8004FF68_BitReader *reader, s32 count) {
    lbl_80186FA8++;
    if (reader->bits_left < count) {
        fn_800502A0(reader);
    }
    if (count > reader->bits_left) {
        reader->bit_pos += reader->bits_left;
        reader->bits_left = 0;
    } else {
        reader->bits_left -= count;
        reader->bit_pos += count;
    }
}

static inline u32 fn_8004FF68_GetBits(Fn8004FF68_BitReader *reader, s32 count) {
    u32 value;

    lbl_80186FA8++;
    if (reader->bits_left < count) {
        fn_800502A0(reader);
    }
    if (count > reader->bits_left) {
        reader->bit_pos += reader->bits_left;
        reader->bits_left = 0;
        value = 0;
    } else {
        value = reader->buffer >> (reader->bits_left - count);
        value &= lbl_801309C0[count];
        reader->bits_left -= count;
        reader->bit_pos += count;
    }
    return value;
}

static inline int fn_8004FF68_IsEnd(Fn8004FF68_BitReader *reader) {
    if (reader->stream->vtbl->unk_24(reader->stream, 1) == 0 && reader->bits_left == 0 && reader->eof == 0) {
        return 1;
    }
    return 0;
}

s32 fn_8004FF68(Fn8004FF68_BitReader *reader) {
    u32 bits;
    u32 mask = lbl_801309C0[12];

    if (reader->bit_pos & 7) {
        fn_8004FF68_SkipBits(reader, 8 - (reader->bit_pos & 7));
    }
    bits = fn_8004FF68_GetBits(reader, 12);
    while (!fn_8004FF68_IsEnd(reader)) {
        if ((bits & mask) == 0xFFF) {
            return 1;
        }
        if (bits == 0x8001000C) { /* fzgx-allow: A1 bit pattern of the scan window, not an address */
            return 2;
        }
        bits <<= 4;
        bits |= fn_8004FF68_GetBits(reader, 4);
    }
    return 0;
}

/* --- dol/fn_80050180.c --- */
/* --- dol/fn_80050180.c --- */
typedef u32 (*fn_80050180_Fn0)(u32, u32);
struct fn_80050180_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};


s32 fn_80050180(struct fn_80050180_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    v0 = arg0->unk_4;
    if ((s32)((fn_80050180_Fn0)*(u32 *)((u8 *)*(u32 *)((u8 *)v0 + 0) + 36))(v0, 1) == 0 && (s32)*(u32 *)((u8 *)(u32)arg0 + 12) == 0 && (s32)*(u32 *)((u8 *)(u32)arg0 + 36) == 0) {
    v1 = 1;
    } else {
    v1 = 0;
    }
    return v1;
}

/* --- dol/fn_800501EC.c --- */
struct fn_800501EC_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
};

u32 fn_800501EC(struct fn_800501EC_Arg0 *arg0) {
    return arg0->unk_10;
}
