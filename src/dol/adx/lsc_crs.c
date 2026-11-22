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

extern u32 lbl_80188A88[];
extern LSCObject lbl_80188A8C[16];
/* read through a volatile lvalue so the access is not optimised away */
extern volatile u32 lbl_800922C0[];
extern s32 lbl_8018AE10[];
extern s32 lbl_8018AE14[];

extern void fn_80056710(void *);
extern void fn_80057114(void *);
extern void *memset(void *, int, u32);
extern void fn_800566BC(int, int);
extern void fn_800566F0();
extern void fn_800565FC(const char *format, ...);
extern void fn_8005676C(void);
extern s32 fn_80056E9C(LSCObject *lsc, const char *filename, void *directory, s32 offset, s32 sector_count);
extern s32 fn_8004AEE4(ADXStream *stream);
extern s32 fn_8004AE78(ADXStream *stream);
extern void fn_8004AD84(ADXStream *stream);
extern void fn_8004B0EC(ADXStream *stream);
extern void fn_8004B180(ADXStream *stream, const char *filename, void *directory, s32 offset, s32 sector_count);
extern void fn_8004AC04(ADXStream *stream, s32 sector_count);
extern s32 fn_8004A550(ADXStream *stream, s32 minimum_size, s32 buffer_size);
extern void fn_8004AE94(ADXStream *stream, s32 position);
extern void fn_8004ADF4(ADXStream *stream);
extern u32 OSRestoreInterrupts(u32);
extern u32 OSDisableInterrupts(void);

#pragma use_lmw_stmw off
void fn_80057378(void) {
    u8 local[16];
    int i;

    fn_80056710(local);
    if (--lbl_80188A88[0] == 0) {
        i = 0;
        do {
            if (lbl_80188A8C[i].used == 1) {
                fn_80057114(&lbl_80188A8C[i]);
            }
            i++;
        } while (i < 0x10);
        memset(lbl_80188A8C, 0, 0x2380);
        fn_800566BC(0, 0);
    }
    fn_800566F0(local);
}
#pragma use_lmw_stmw on

void fn_8005741C(void) {
    f64 loc_8[1];
    u32 value;

    (void)lbl_800922C0[0];
    fn_80056710((u32 *)&loc_8);
    if ((s32)lbl_80188A88[0] == 0) {
        memset(&lbl_80188A8C, 0, 0x2380);
        fn_800566BC(0, 0);
    }
    value = lbl_80188A88[0];
    lbl_80188A88[0] = value + 1;
    fn_800566F0((u32 *)&loc_8, value, lbl_80188A88);
}

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

void fn_800576DC(void) {
    /* refcount is decremented from interrupt context; the test must re-read it */
    volatile s32 *counter = (volatile s32 *)&lbl_8018AE10;
    *counter = *counter - 1;
    if (*counter == 0) {
        OSRestoreInterrupts(lbl_8018AE14[0]);
    }
}

u32 fn_80057728(void) {
    u32 v0;
    u32 v1;
    u32 t0;
    if ((s32)lbl_8018AE10[0] == 0) {
        t0 = OSDisableInterrupts();
        lbl_8018AE14[0] = t0;
    }
    v0 = (u32)&lbl_8018AE10;
    v1 = *(u32 *)(v0);
    *(u32 *)((u8 *)v0 + 0) = (v1 + 1);
    return v1;
}
