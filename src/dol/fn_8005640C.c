
#include "types.h"

typedef struct DVDDiskID {
    char gameName[4];
    char company[2];
    unsigned char diskNumber;
    unsigned char gameVersion;
    unsigned char streaming;
    unsigned char streamingBufSize;
    unsigned char padding[22];
} DVDDiskID;

typedef struct DVDCommandBlock DVDCommandBlock;

typedef struct DVDFileInfo DVDFileInfo;

typedef void (*DVDCBCallback)(long result, DVDCommandBlock *block);

typedef void (*DVDCallback)(long result, DVDFileInfo *file_info);

struct DVDCommandBlock {
    DVDCommandBlock *next;
    DVDCommandBlock *prev;
    unsigned long command;
    long state;
    unsigned long offset;
    unsigned long length;
    void *address;
    unsigned long current_transfer_size;
    unsigned long transferred_size;
    DVDDiskID *id;
    DVDCBCallback callback;
    void *user_data;
};

struct DVDFileInfo {
    DVDCommandBlock cb;
    unsigned long start_address;
    unsigned long length;
    DVDCallback callback;
};

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

void fn_8005640C(void);

void DCStoreRange(void *address, unsigned long length);

void DCInvalidateRange(void *address, unsigned long length);

long DVDGetCommandBlockStatus(const DVDCommandBlock *block);

long DVDGetTransferredSize(DVDFileInfo *file_info);

void *memset(void *destination, int value, unsigned int size);

extern GcCiDebug lbl_801878B8;

extern GcCiObject lbl_801878CC[40];

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
    case -1:
        handle->status = GCCI_STATUS_ERROR;
        lbl_801878B8.transfer_status = GCCI_STATUS_ERROR;
        break;
    case 0:
        read_length = handle->request_sectors * handle->sector_length;
        DCInvalidateRange(handle->transfer_buffer, read_length);
        handle->transfer_length = read_length;
        handle->sector_position += handle->request_sectors;
        if (handle->sector_position * handle->sector_length > handle->file_size) {
            nbyte = handle->sector_position * handle->sector_length - handle->file_size;
            fill = (unsigned char *)handle->transfer_buffer + handle->transfer_length - nbyte;
            memset(fill, 0, nbyte);
            DCStoreRange(fill, nbyte);
        }
        handle->status = GCCI_STATUS_COMPLETE;
        lbl_801878B8.transfer_status = GCCI_STATUS_COMPLETE;
        break;
    case 10:
        nbyte = DVDGetTransferredSize(&handle->file_info);
        DCInvalidateRange(handle->transfer_buffer, nbyte);
        handle->transfer_length = handle->sector_length * (nbyte / handle->sector_length);
        handle->sector_position += nbyte / handle->sector_length;
        handle->status = lbl_801878B8.transfer_status = GCCI_STATUS_IDLE;
        break;
    }
}

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
