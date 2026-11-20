#include "types.h"


/* --- dol/LSC_Start.c --- */
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

typedef struct LSCStreamInfo {
    s32 id;
    const char *filename;
    u32 filename_checksum;
    void *directory;
    s32 offset;
    s32 sector_count;
    s32 state;
    s32 read_sectors;
} LSCStreamInfo;

typedef struct LSCObject {
    s8 used;
    s8 state;
    s8 reading;
    s8 loop;
    s8 paused;
    u8 reserved_05;
    u16 reserved_06;
    SJ *sj;
    SJCK chunk;
    s32 minimum_buffer_size;
    s32 buffer_size;
    s32 write_position;
    s32 read_position;
    s32 stream_count;
    ADXStream *stream;
    s32 file_sectors;
    s32 requested_sectors;
    s32 error_count;
    LSCStreamInfo stream_info[16];
} LSCObject;

extern void fn_800565FC(const char *format, ...);

extern void fn_80056710(s32 *state);

extern void fn_800566F0(s32 *state);

extern void fn_8004AC58(ADXStream *stream);

static inline void lsc_ResetEntries(LSCObject *lsc) {
    if (lsc == 0) {
        fn_800565FC("E0003: Illigal parameter lsc=NULL\n");
    } else if (lsc->state == 0) {
        lsc->write_position = 0;
        lsc->read_position = 0;
        lsc->stream_count = 0;
    }
}

static inline void LSC_Stop(LSCObject *lsc) {
    if (lsc == 0) {
        fn_800565FC("E0003: Illigal parameter lsc=NULL\n");
        return;
    }
    if (lsc->state != 0) {
        lsc->state = 0;
        if (lsc->stream != 0 && lsc->reading == 1) {
            fn_8004AC58(lsc->stream);
            lsc->reading = 0;
        }
        lsc->file_sectors = 0;
        lsc_ResetEntries(lsc);
        lsc->error_count = 0;
    }
}

void LSC_Start(LSCObject *lsc) {
    s32 critical_state;
    if (lsc == 0) {
        fn_800565FC("E0003: Illigal parameter lsc=NULL\n");
        return;
    }
    fn_80056710(&critical_state);
    if (lsc->state != 0) {
        LSC_Stop(lsc);
    }
    if (lsc->stream_count > 0) {
        lsc->state = 2;
    } else {
        lsc->state = 1;
    }
    fn_800566F0(&critical_state);
}

/* --- dol/fn_80056E9C.c --- */
typedef struct LSCObject_u1 {
    s8 used;
    s8 state;
    s8 reading;
    s8 loop;
    s8 paused;
    u8 reserved_05[3];
    SJ *sj;
    s32 reserved_0C;
    s32 reserved_10;
    s32 minimum_buffer_size;
    s32 buffer_size;
    s32 write_position;
    s32 read_position;
    s32 stream_count;
    ADXStream *stream;
    s32 file_sectors;
    s32 reserved_30;
    s32 reserved_34;
    LSCStreamInfo stream_info[16];
} LSCObject_u1;

void fn_800565FC(const char *format, ...);
void fn_8005676C(void);
s32 fn_80056E9C(LSCObject_u1 *lsc, const char *filename, void *directory, s32 offset, s32 sector_count);
unsigned long strlen(const char *str);
s32 fn_8004AEE4(ADXStream *stream);
s32 fn_8004AE78(ADXStream *stream);
void fn_8004AD84(ADXStream *stream);
void fn_8004B0EC(ADXStream *stream);
void fn_8004B180(ADXStream *stream, const char *filename, void *directory, s32 offset, s32 sector_count);
void fn_8004AC04(ADXStream *stream, s32 sector_count);
s32 fn_8004A550(ADXStream *stream, s32 minimum_size, s32 buffer_size);
void fn_8004AE94(ADXStream *stream, s32 position);
void fn_8004ADF4(ADXStream *stream);


static inline LSCStreamInfo *lsc_GetWriteEntry(LSCObject_u1 *lsc) {
    return &lsc->stream_info[lsc->write_position];
}

s32 fn_80056E9C(LSCObject_u1 *lsc, const char *filename, void *directory, s32 offset, s32 sector_count) {
    LSCStreamInfo *info;
    s32 stream_id;
    u32 *words;
    unsigned long i;
    unsigned long filename_length;

    if (lsc == 0) {
        fn_800565FC("E0003: Illigal parameter lsc=NULL\n");
        return -1;
    }
    if (lsc->stream_count >= 16) {
        return -1;
    }
    if (filename == 0) {
        fn_800565FC("E0011: Illigal parameter fname=%s\n", filename);
        return -1;
    }

    words = (u32 *)filename;
    stream_id = lsc->stream_info[(lsc->write_position + 15) % 16].id;
    info = lsc_GetWriteEntry(lsc);
    stream_id = (stream_id == 0x7FFFFFFF) ? 0 : stream_id + 1;
    info->id = stream_id;
    info->filename = filename;
    filename_length = strlen(filename) / 4;
    info->filename_checksum = 0;
    for (i = 0; i < filename_length; i++) {
        info->filename_checksum += words[i];
    }
    info->offset = offset;
    info->sector_count = sector_count;
    info->directory = directory;
    info->state = 0;
    info->read_sectors = 0;

    lsc->stream_count++;
    lsc->write_position = (lsc->write_position + 1) % 16;
    if (lsc->state == 1) {
        lsc->state = 2;
    }
    return stream_id;
}
