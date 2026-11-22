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


static inline int gcci_is_dvd_finished(const GcCiObject *handle) {
    int done = 0;
    if (handle->dvd_status == DVD_STATE_END || handle->dvd_status == DVD_STATE_CANCELED) {
        done = 1;
    }
    return done;
}


extern u32 lbl_80091F7C[];
extern u32 lbl_80091F94[];
extern u32 lbl_80091FAC[];
extern u32 lbl_80091FC8[];
extern char lbl_80091F50[];
extern u32 lbl_80132260[];
static inline int gcci_is_idle(const GcCiObject *handle) {
    int idle = 0;
    if (handle->status == GCCI_STATUS_COMPLETE || handle->status == GCCI_STATUS_IDLE) {
        idle = 1;
    }
    return idle;
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


void fn_800555C0(s32 result, DVDFileInfo *file_info) {
}

typedef u32 (*fn_800555C4_Fn0)(u32, u32, u32);
u32 fn_800555C4(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
    if (((u32)lbl_801878C8) != 0) {
    v0 = ((u32)lbl_801878C4);
    t0 = ((fn_800555C4_Fn0)((u32)lbl_801878C8))(v0, (u32)&lbl_80091F7C, 0);
    v0 = t0;
    }
    v0 = 0;
    } else {
    v0 = *(u32 *)(v0 + 32);
    }
    return v0;
}

typedef u32 (*fn_80055624_Fn0)(u32, u32, u32);
typedef u32 (*fn_80055624_Fn1)(u32, u32, u32);
void fn_80055624(u32 arg0, u32 arg1) {
    u32 v0;
    s32 v1;
    u32 v4;
    u32 v5;
    u32 t0;

    v0 = arg0;
    if (arg0 == 0) {
        if (((u32)lbl_801878C8) != 0) {
            v0 = ((u32)lbl_801878C4);
            t0 = ((fn_80055624_Fn0)((u32)lbl_801878C8))(v0, (u32)&lbl_80091F94, 0);
            v0 = t0;
        }
    } else {
        v1 = *(s32 *)(v0 + 16);
        if ((v1 % 32) != 0) {
            if (((u32)lbl_801878C8) != 0) {
                v0 = ((u32)lbl_801878C4);
                t0 = ((fn_80055624_Fn1)((u32)lbl_801878C8))(v0, (u32)&lbl_80091FAC, 0);
                v0 = t0;
            }
        } else {
            v4 = *(u32 *)(v0 + 28);
            v5 = v4 * v1;
            *(u32 *)((u8 *)v0 + 16) = arg1;
            *(u32 *)((u8 *)v0 + 24) = (*(s32 *)((u8 *)v0 + 16) - 1 + *(s32 *)((u8 *)v0 + 20)) / *(s32 *)((u8 *)v0 + 16);
            *(u32 *)((u8 *)v0 + 28) = (s32)v5 / *(s32 *)((u8 *)v0 + 16);
            *(u32 *)((u8 *)v0 + 32) = *(u32 *)((u8 *)v0 + 36) * arg1;
        }
    }
}

typedef u32 (*fn_80055708_Fn0)(u32, u32, u32);
u32 fn_80055708(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
        if (((u32)lbl_801878C8) != 0) {
            v0 = ((u32)lbl_801878C4);
            t0 = ((fn_80055708_Fn0)((u32)lbl_801878C8))(v0, (u32)&lbl_80091FC8, 0);
            v0 = t0;
        }
        v0 = 0;
    } else {
        v0 = *(u32 *)(v0 + 16);
    }
    return v0;
}

typedef u32 (*fn_80055768_Fn0)(u32, u32, u32);
s32 fn_80055768(u32 arg0) {
    if (arg0 == 0) {
        if (((u32)lbl_801878C8) != 0) {
            ((fn_80055768_Fn0)((u32)lbl_801878C8))(
                ((u32)lbl_801878C4), (u32)&lbl_80091F7C, 0);
        }
        return 0;
    }
    return *(s8 *)(arg0 + 2);
}

void fn_800557CC(void *object) {
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

typedef u32 (*fn_80055D94_Fn0)(u32, u32, u32);
u32 fn_80055D94(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
        if (((u32)lbl_801878C8) != 0) {
            v0 = ((u32)lbl_801878C4);
            t0 = ((fn_80055D94_Fn0)((u32)lbl_801878C8))(v0, (u32)&lbl_80091F7C, 0);
            v0 = t0;
        }
        v0 = 0;
    } else {
        v0 = *(u32 *)(v0 + 28);
    }
    return v0;
}

typedef struct Fn80055DF4_Obj {
    u8 pad18[0x18];
    s32 max_value;
    s32 value;
} Fn80055DF4_Obj;

typedef u32 (*fn_80055DF4_Fn0)(u32, u32, u32);

u32 fn_80055DF4(Fn80055DF4_Obj *arg0, s32 arg1, s32 arg2) {
    s32 value;
    s32 max_value;

    if (arg0 == 0) {
        if (((u32)lbl_801878C8) != 0) {
            ((fn_80055DF4_Fn0)((u32)lbl_801878C8))(((u32)lbl_801878C4), (u32)&lbl_80091F7C, 0);
        }
        return 0;
    }

    if (arg2 == 0) {
        arg0->value = arg1;
    } else if (arg2 == 2) {
        arg0->value = arg0->max_value + arg1;
    } else if (arg2 == 1) {
        arg0->value = arg0->value + arg1;
    }

    max_value = arg0->max_value;
    value = arg0->value;
    if (value < max_value) {
        max_value = value;
    }
    arg0->value = max_value;

    arg0->value = (arg0->value > 0) ? arg0->value : 0;
    return arg0->value;
}

void fn_80055EC0(void *object) {
    GcCiObject *handle;

    handle = object;
    if (handle == 0) {
        return;
    }
    gcci_StopTr(object);
    DVDClose(&handle->file_info);
    handle->used = 0;
    memset(handle, 0, sizeof(GcCiObject));
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

typedef void (*fn_80056294_Fn)(u32, u32, u32);
u32 fn_80056294(char *arg0, u32 arg1, u32 arg2) {
    struct { u32 a[65]; } buf;
    DVDFileInfo info;
    u8 *base;
    char *p;
    u32 n;
    u32 i;
    u32 size;

    base = (u8 *)lbl_80091F50;
    if (arg0 == 0) {
        if (((u32)lbl_801878C8) != 0) {
            ((fn_80056294_Fn)((u32)lbl_801878C8))(((u32)lbl_801878C4), (u32)(base + 0x1ac), 0);
        }
        return 0;
    }
    fn_80083DB0((char *)&buf, (const char *)lbl_80188870);
    strcat((char *)&buf, arg0);
    n = strlen((char *)&buf);
    p = (char *)&buf;
    for (i = 0; i < n; i++) {
        if (p[i] == '\\') {
            p[i] = '/';
        }
    }
    if (!DVDOpen((char *)&buf, &info)) {
        if (((u32)lbl_801878C8) != 0) {
            ((fn_80056294_Fn)((u32)lbl_801878C8))(((u32)lbl_801878C4), (u32)(base + 0x1d8), 0);
        }
        return 0;
    }
    size = info.length;
    if (size & ~0x7fffffff) {
        size = 0x7fffffff;
    }
    if (!DVDClose(&info)) {
        if (((u32)lbl_801878C8) != 0) {
            ((fn_80056294_Fn)((u32)lbl_801878C8))(((u32)lbl_801878C4), (u32)(base + 0x208), 0);
        }
        return 0;
    }
    return size;
}

/* --- dol/fn_800563F8.c --- */
void fn_800563F8(u32 arg0, u32 arg1) {
    lbl_801878C8 = (GcCiErrorCallback)arg0;
    lbl_801878C4 = (void *)arg1;
}

void fn_8005640C(void);

void DCStoreRange(void *address, unsigned long length);

void DCInvalidateRange(void *address, unsigned long length);

long DVDGetCommandBlockStatus(const DVDCommandBlock *block);

long DVDGetTransferredSize(DVDFileInfo *file_info);


extern GcCiDebug lbl_801878B8;

extern GcCiObject lbl_801878CC[40];


static inline void gcci_update_transfers(void) {
    int index = 0;
    GcCiObject *current = lbl_801878CC;
    do {
        gcci_update_transfer(current);
        index++;
        current++;
    } while (index < 40);
}

void fn_8005640C(void) { gcci_update_transfers(); }

void *fn_80056584(void) {
    lbl_801878CC__fzgx_offset_FA0 = lbl_801878CC__fzgx_offset_FA0;
    memset(lbl_80188870, 0, sizeof(lbl_80188870));
    lbl_801878C8 = 0;
    lbl_801878C4 = 0;
    memset(&lbl_801878B8, 0, sizeof(lbl_801878B8));
    return &lbl_80132260;
}
