#include "types.h"

typedef struct SJ SJ;
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
} LSCObject;

void fn_800565FC(const char *format, ...);
void fn_8005676C(void);
s32 fn_80056E9C(LSCObject *lsc, const char *filename, void *directory, s32 offset, s32 sector_count);
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

static inline void lsc_StatRead(LSCObject *lsc) {
    LSCStreamInfo *info;
    s32 state;

    if (lsc->stream == 0) {
        fn_800565FC("E0007: lsc->fp=NULL\n");
        return;
    }

    info = &lsc->stream_info[lsc->read_position];
    state = fn_8004AEE4(lsc->stream);
    if (state == 4) {
        lsc->state = 3;
    } else if (state == 2) {
        info->read_sectors = fn_8004AE78(lsc->stream);
    } else if (state == 3) {
        info->read_sectors = lsc->file_sectors;
        info->state = 2;
    }
}

static inline void lsc_StatEnd(LSCObject *lsc) {
    const char *filename = 0;
    void *directory = 0;
    s32 offset = 0;
    s32 sector_count = 0;
    LSCStreamInfo *info;

    if (lsc->stream != 0) {
        if (lsc->loop == 1) {
            info = &lsc->stream_info[lsc->read_position];
            filename = info->filename;
            directory = info->directory;
            offset = info->offset;
            sector_count = info->sector_count;
        }

        lsc->stream_count--;
        lsc->read_position = (lsc->read_position + 1) % 16;

        if (lsc->stream_count <= 0) {
            fn_8005676C();
            lsc->state = 1;
        }

        if (lsc->loop == 1) {
            fn_80056E9C(lsc, filename, directory, offset, sector_count);
        }
    }
}

static inline void lsc_StatWait(LSCObject *lsc) {
    LSCStreamInfo *info;

    info = &lsc->stream_info[lsc->read_position];
    if (lsc->stream_count <= 0) {
        return;
    }

    fn_8004AD84(lsc->stream);
    fn_8004B0EC(lsc->stream);
    fn_8004B180(lsc->stream, info->filename, info->directory, info->offset, info->sector_count);
    fn_8004AC04(lsc->stream, info->sector_count);
    lsc->file_sectors = info->sector_count;
    info->read_sectors = 0;
    lsc->reading = 0;

    if (lsc->reading == 0) {
        fn_8004A550(lsc->stream, lsc->minimum_buffer_size, lsc->buffer_size);
        fn_8004AE94(lsc->stream, 0);
        fn_8004ADF4(lsc->stream);
        lsc->reading = 1;
    }

    info->state = 1;
}

void fn_80057494(LSCObject *lsc) {
    if (lsc->paused == 1) {
        return;
    }
    if (lsc->state != 2) {
        return;
    }
    if (lsc->stream_count <= 0) {
        return;
    }

    if (lsc->stream_info[lsc->read_position].state == 1) {
        lsc_StatRead(lsc);
    }

    if (lsc->stream_info[lsc->read_position].state == 2) {
        lsc_StatEnd(lsc);
    }

    if (lsc->stream_info[lsc->read_position].state != 0) {
        return;
    }

    lsc_StatWait(lsc);
}
