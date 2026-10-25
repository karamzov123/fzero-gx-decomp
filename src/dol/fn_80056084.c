#include "types.h"

#define GCCI_MAX_HANDLES 40
#define GCCI_DEFAULT_SECTOR_LENGTH 0x800
#define GCCI_DVD_PRIORITY 2
#define GCCI_CANCEL_TIMEOUT_MS 2000

#define DVD_STATE_FATAL_ERROR -1
#define DVD_STATE_END 0
#define DVD_STATE_CANCELED 10

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

static inline void gcci_StopTr(void *object) {
    GcCiObject *handle;
    int cancel_result;
    unsigned long start;
    unsigned long current;
    unsigned long elapsed;

    handle = object;
    if (handle == 0) {
        gcci_call_error("E0092912:handl is null.", 0);
        return;
    }
    if (handle->status == GCCI_STATUS_COMPLETE || handle->status == GCCI_STATUS_IDLE) {
        return;
    }
    DVDGetCommandBlockStatus(&handle->file_info.cb);
    DVDGetDriveStatus();
    lbl_801878B8.canceling = 1;
    cancel_result = DVDCancel(&handle->file_info.cb);
    lbl_801878B8.canceling = 0;
    if (cancel_result < 0) {
        gcci_call_error("E0092917:DVDCancel failed.", handle);
        return;
    }
    start = OSTicksToMilliseconds(OSGetTick());
    while (!gcci_is_dvd_finished(handle)) {
        handle->dvd_status = DVDGetCommandBlockStatus(&handle->file_info.cb);
        lbl_801878B8.dvd_status = handle->dvd_status;
        current = OSTicksToMilliseconds(OSGetTick());
        elapsed = (current >= start) ? (current - start) : (0xFFFFFFFF - start + current);
        if (elapsed > GCCI_CANCEL_TIMEOUT_MS) {
            gcci_call_error("E0092918:DVDCancel time out.", handle);
            break;
        }
    }
    handle->status = GCCI_STATUS_IDLE;
    lbl_801878B8.transfer_status = GCCI_STATUS_IDLE;
    DVDGetCommandBlockStatus(&handle->file_info.cb);
    DVDGetDriveStatus();
}
static inline void gcci_make_path(char *path, const char *filename) {
    char *current;
    unsigned long length;
    unsigned long index;

    fn_80083DB0(path, lbl_80188870);
    strcat(path, filename);
    length = strlen(path);
    current = path;
    for (index = 0; index < length; index++) {
        if (*current == '\\') {
            *current = '/';
        }
        current++;
    }
}

static inline GcCiObject *gcci_find_unused_handle(void) {
    GcCiObject *handle;
    GcCiObject *current;
    int index;

    handle = 0;
    current = lbl_801878CC;
    for (index = 0; index < GCCI_MAX_HANDLES; current++, index++) {
        if (current->used == 0) {
            handle = &lbl_801878CC[index];
            break;
        }
    }
    return handle;
}

void *fn_80056084(const char *filename, void *parameter, int mode) {
    char path[256];
    GcCiObject *handle;
    int file_size;

    if (filename == 0) {
        gcci_call_error("E0092908:fname is null.(gcCiOpen)", 0);
        return 0;
    }
    if (mode != 0) {
        gcci_call_error("E0092909:rw is illigal.(gcCiOpen)", 0);
        return 0;
    }
    handle = gcci_find_unused_handle();
    if (handle == 0) {
        gcci_call_error("E0092910:not enough handle resource.(gcCiOpen)", 0);
        return 0;
    }
    gcci_make_path(path, filename);
    if (DVDOpen(path, &handle->file_info) == 0) {
        gcci_call_error("E0092911:DVDOpen fail.(gcCiOpen)", 0);
        memset(handle, 0, sizeof(*handle));
        return 0;
    }
    handle->sector_length = GCCI_DEFAULT_SECTOR_LENGTH;
    file_size = handle->file_info.length;
    if ((file_size & 0x80000000U) != 0) {
        file_size = 0x7FFFFFFF;
    }
    handle->file_size = file_size;
    handle->sector_count = (int)((unsigned int)handle->file_size + ((unsigned int)handle->sector_length - 1U)) / handle->sector_length;
    handle->sector_position = 0;
    handle->transfer_buffer = 0;
    handle->request_sectors = 0;
    handle->transfer_length = 0;
    handle->status = GCCI_STATUS_IDLE;
    handle->used = 1;
    return handle;
}
