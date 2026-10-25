#include "types.h"

#define GCCI_MAX_HANDLES 40
#define GCCI_DEFAULT_SECTOR_LENGTH 0x800
#define GCCI_DVD_PRIORITY 2
#define GCCI_CANCEL_TIMEOUT_MS 2000

#define DVD_STATE_FATAL_ERROR -1
#define DVD_STATE_END 0
#define DVD_STATE_CANCELED 10

// Hardware or OS state can change asynchronously.
extern u32 __OSBusClock : 0x800000F8; /* fzgx-allow: A1 fixed cached-RAM bus-clock word; retail carries no reloc */
#define OSTicksToMilliseconds(ticks) ((ticks) / ((__OSBusClock / 4) / 1000))

typedef struct DVDCommandBlock {
    u8 pad[0x30];
} DVDCommandBlock;

typedef struct DVDFileInfo {
    DVDCommandBlock cb;
    u32 startAddr;
    u32 length;
    void *callback;
} DVDFileInfo;

typedef enum GcCiStatus {
    GCCI_STATUS_IDLE = 0,
    GCCI_STATUS_COMPLETE = 1,
    GCCI_STATUS_TRANSFERRING = 2,
    GCCI_STATUS_ERROR = 3
} GcCiStatus;

typedef struct GcCiObject {
    signed char used;
    unsigned char reserved_01;
    signed char status;
    unsigned char reserved_03;
    unsigned char reserved_04[4];
    void *transfer_buffer;
    long dvd_status;
    long sector_length;
    long file_size;
    long sector_count;
    long sector_position;
    long transfer_length;
    long request_sectors;
    DVDFileInfo file_info;
} GcCiObject;

typedef struct GcCiDebug {
    long dvd_status;
    signed char transfer_status;
    unsigned char reserved_05[3];
    long canceling;
} GcCiDebug;

typedef void (*GcCiErrorCallback)(void *object, const char *message, void *handle);

GcCiDebug lbl_801878B8;
void *lbl_801878C4;
GcCiErrorCallback lbl_801878C8;
GcCiObject lbl_801878CC[GCCI_MAX_HANDLES];
// Hardware or OS state can change asynchronously.
const char *volatile lbl_801878CC__fzgx_offset_FA0;

extern int lbl_801322C8[1];
extern char lbl_80188870[256];

s32 DVDGetCommandBlockStatus(const DVDCommandBlock *block);
s32 DVDGetDriveStatus(void);
s32 DVDCancel(DVDCommandBlock *block);
u32 OSGetTick(void);
void DCInvalidateRange(void *addr, u32 nBytes);
void DCStoreRange(void *addr, u32 nBytes);
s32 DVDGetTransferredSize(DVDFileInfo *fileinfo);
void fn_800555C0(s32 result, DVDFileInfo *file_info);
s32 DVDReadAsyncPrio(DVDFileInfo *fileInfo, void *addr, s32 length, s32 offset, void (*callback)(s32, DVDFileInfo *), s32 prio);
s32 DVDReadPrio(DVDFileInfo *fileInfo, void *addr, s32 length, s32 offset, s32 prio);
s32 DVDClose(DVDFileInfo *fileInfo);
s32 DVDOpen(const char *fileName, DVDFileInfo *fileInfo);
void *memset(void *dst, int c, u32 n);
char *fn_80083DB0(char *dst, const char *src);
char *strcat(char *dst, const char *src);
u32 strlen(const char *str);

#pragma section code_type ".fzgxpool"
static const void *fzgx_bss_layout(int x) {
    volatile u8 s; // fzgx-allow: S2 BSS primer ordering
    s = *(u8 *)&lbl_801878B8;
    s = *(u8 *)&lbl_801878C4;
    s = *(u8 *)&lbl_801878C8;
    s = *(u8 *)&lbl_801878CC;
    s = *(u8 *)&lbl_801878CC__fzgx_offset_FA0;
    if (x == 0) return "\nGCCI Ver.1.09 Build:May  9 2003 17:09:53\n";
    if (x == 1) return "E0092912:handl is null.";
    if (x == 2) return "E0040302:handl is null.";
    if (x == 3) return "E0040303:invalidate size.";
    if (x == 4) return "E0040301:handl is null.";
    if (x == 5) return "E0092917:DVDCancel failed.";
    if (x == 6) return "E0092918:DVDCancel time out.";
    if (x == 7) return "E0092913:nsct < 0.(gcCiReqRd)";
    if (x == 8) return "E0092914:buf is null.(gcCiReqRd)";
    if (x == 9) return "E0092908:fname is null.(gcCiOpen)";
    if (x == 10) return "E0092909:rw is illigal.(gcCiOpen)";
    if (x == 11) return "E0092910:not enough handle resource.(gcCiOpen)";
    if (x == 12) return "E0092911:DVDOpen fail.(gcCiOpen)";
    return 0;
}
#pragma section code_type ".text"

static inline void gcci_call_error(const char *message, void *handle) {
    if (lbl_801878C8 != 0) {
        lbl_801878C8(lbl_801878C4, message, handle);
    }
}

static inline int gcci_is_idle(const GcCiObject *handle) {
    int idle = 0;
    if (handle->status == GCCI_STATUS_COMPLETE || handle->status == GCCI_STATUS_IDLE) {
        idle = 1;
    }
    return idle;
}

static inline int gcci_is_dvd_finished(const GcCiObject *handle) {
    int done = 0;
    if (handle->dvd_status == DVD_STATE_END || handle->dvd_status == DVD_STATE_CANCELED) {
        done = 1;
    }
    return done;
}

static inline void gcci_update_transfer(GcCiObject *handle) {
    int nbyte;
    int read_length;
    unsigned char *fill;

    if (handle->used != 1 || handle->status != GCCI_STATUS_TRANSFERRING) {
        return;
    }
    handle->dvd_status = DVDGetCommandBlockStatus(&handle->file_info.cb);
    lbl_801878B8.dvd_status = handle->dvd_status;
    switch (handle->dvd_status) {
    case DVD_STATE_FATAL_ERROR:
        handle->status = GCCI_STATUS_ERROR;
        lbl_801878B8.transfer_status = GCCI_STATUS_ERROR;
        break;
    case DVD_STATE_END:
        read_length = handle->request_sectors * handle->sector_length;
        DCInvalidateRange(handle->transfer_buffer, read_length);
        handle->transfer_length = read_length;
        handle->sector_position += handle->request_sectors;
        if (handle->sector_position * handle->sector_length > handle->file_size) {
            nbyte = handle->sector_position * handle->sector_length - handle->file_size;
            fill = (unsigned char *)((u32)handle->transfer_buffer + handle->transfer_length - nbyte);
            memset(fill, 0, nbyte);
            DCStoreRange(fill, nbyte);
        }
        handle->status = GCCI_STATUS_COMPLETE;
        lbl_801878B8.transfer_status = GCCI_STATUS_COMPLETE;
        break;
    case DVD_STATE_CANCELED:
        read_length = DVDGetTransferredSize(&handle->file_info);
        DCInvalidateRange(handle->transfer_buffer, read_length);
        handle->transfer_length = handle->sector_length * (read_length / handle->sector_length);
        handle->sector_position += read_length / handle->sector_length;
        handle->status = lbl_801878B8.transfer_status = GCCI_STATUS_IDLE;
        break;
    }
}

static inline long gcci_is_any_transferring(GcCiObject *table) {
    long index;

    for (index = 0; index < GCCI_MAX_HANDLES; index++) {
        if (table[index].used == 1 && table[index].status == GCCI_STATUS_TRANSFERRING) {
            return 1;
        }
    }
    return 0;
}

static inline void gcci_update_table(GcCiObject *table) {
    long index;

    for (index = 0; index < GCCI_MAX_HANDLES; index++) {
        gcci_update_transfer(&table[index]);
    }
}

int fn_8005596C(void *object, int sectors, void *buffer) {
    int aligned_length;
    GcCiObject *handle = object;
    int offset;
    int length;
    int result;

    if (handle == 0) {
        if (lbl_801878C8 != 0) {
            lbl_801878C8(lbl_801878C4, "E0092912:handl is null.", 0);
        }
        return 0;
    }
    if (sectors < 0) {
        if (lbl_801878C8 != 0) {
            lbl_801878C8(lbl_801878C4, "E0092913:nsct < 0.(gcCiReqRd)", handle);
        }
        return 0;
    }
    if (buffer == 0) {
        if (lbl_801878C8 != 0) {
            lbl_801878C8(lbl_801878C4, "E0092914:buf is null.(gcCiReqRd)", handle);
        }
        return 0;
    }
    if (!gcci_is_idle(handle)) {
        return 0;
    }
    if (!gcci_is_dvd_finished(handle)) {
        return 0;
    }
    if (gcci_is_any_transferring(lbl_801878CC)) {
        return 0;
    }
    if (sectors == 0) {
        handle->status = GCCI_STATUS_COMPLETE;
        lbl_801878B8.transfer_status = GCCI_STATUS_COMPLETE;
        return 0;
    }
    handle->transfer_length = 0;
    handle->transfer_buffer = buffer;
    handle->request_sectors = sectors;
    gcci_update_table(lbl_801878CC);
    offset = handle->sector_position * handle->sector_length;
    length = handle->request_sectors * handle->sector_length;
    if (offset + length > handle->file_size) {
        length = handle->file_size - offset;
        if (length < 0) {
            handle->status = GCCI_STATUS_COMPLETE;
            lbl_801878B8.transfer_status = GCCI_STATUS_COMPLETE;
            return sectors;
        }
    }
    aligned_length = (length + 31) & ~31;
    DCInvalidateRange(buffer, aligned_length);
    if (lbl_801322C8[0] == 0) {
        result = DVDReadAsyncPrio(&handle->file_info, buffer, aligned_length, offset, fn_800555C0, GCCI_DVD_PRIORITY);
    } else {
        result = DVDReadPrio(&handle->file_info, buffer, aligned_length, offset, GCCI_DVD_PRIORITY);
    }
    if (result == 0) {
        return 0;
    }
    handle->status = GCCI_STATUS_TRANSFERRING;
    lbl_801878B8.transfer_status = GCCI_STATUS_TRANSFERRING;
    return handle->request_sectors;
}
