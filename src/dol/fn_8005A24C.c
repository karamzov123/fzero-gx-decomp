#include "types.h"

#define MFCI_MAX_HANDLES 40
#define MFCI_DEFAULT_SECTOR_LENGTH 0x800

typedef enum MfCiStatus {
    MFCI_STATUS_IDLE = 0,
    MFCI_STATUS_COMPLETE = 1,
    MFCI_STATUS_TRANSFERRING = 2
} MfCiStatus;

typedef struct MfCiObject {
    signed char used;
    signed char status;
    unsigned char reserved_02[2];
    long sector_length;
    long file_size;
    long sector_count;
    long sector_position;
    long transfer_length;
    long request_sectors;
    char filename[20];
    long source_offset;
    long request_length;
} MfCiObject;

typedef void (*MfCiErrorCallback)(void *object, const char *message, void *handle);

// Hardware or OS state can change asynchronously.
const char *const volatile lbl_80092528 = "\nMFCI/GC Ver.1.05 Build:May  9 2003 17:10:33\n";

MfCiErrorCallback lbl_80190178;
void *lbl_8019017C;
char lbl_8019017C__fzgx_offset_4[300];
MfCiObject lbl_8019017C__fzgx_offset_130[MFCI_MAX_HANDLES];
int fzgx_pool_lbl_80190B70;

int sprintf(char *s, const char *format, ...);
unsigned long strlen(const char *s);
unsigned long strtoul(const char *str, char **endptr, int base);
void *memcpy(void *dst, const void *src, unsigned long n);
void *memset(void *dst, int c, unsigned long n);
char *fn_80083DB0(char *dst, const char *src);
void fn_80059B44(void);
void fn_80059AE0(void);

#pragma section code_type ".fzgxpool"
static const void *fzgx_pool_layout(int x) {
    volatile u8 s; // fzgx-allow: S2 BSS primer ordering
    s = *(u8 *)&lbl_80190178;
    s = *(u8 *)&lbl_8019017C;
    s = *(u8 *)&lbl_8019017C__fzgx_offset_4;
    s = *(u8 *)&lbl_8019017C__fzgx_offset_130;
    s = *(u8 *)&fzgx_pool_lbl_80190B70;
    if (x == 0) return lbl_80092528;
    if (x == 1) return "E1041001:invalid entry number.(mfCiOpenEntry)";
    if (x == 2) return "E1041002:rw is illigal.(mfCiOpenEntry)";
    if (x == 3) return "E1041002:not enough handle resource.(mfCiOpenEntry)";
    if (x == 4) return "E01100308:length of '%s' is not 17 bytes.(mfci_get_adr_size)";
    if (x == 5) return "E01100309:illegal file name format '%s'(mfci_get_adr_size)";
    if (x == 6) return "E0092912:handl is null.";
    if (x == 7) return "E0040302:handl is null.";
    if (x == 8) return "E0040301:handl is null.";
    if (x == 9) return "E01100307:handl is null.";
    if (x == 10) return "E01100308:nsct < 0.(mfCiReqRd)";
    if (x == 11) return "E01100309:buf is null.(mfCiReqRd)";
    if (x == 12) return "E01100306:handl is null.";
    if (x == 13) return "E01100305:handl is null.";
    if (x == 14) return "E01100301:fname is null.(mfCiOpen)";
    if (x == 15) return "E01100302:rw is illigal.(mfCiOpen)";
    if (x == 16) return "E01100303:not enough handle resource.(mfCiOpen)";
    return 0;
}
#pragma section code_type ".text"

static inline void mfci_call_errfn(const char *message, void *handle) {
    if (lbl_80190178 != 0) {
        lbl_80190178(lbl_8019017C, message, handle);
    }
}

static inline int mfci_ByteToSct(int sector_length, int byte_count) {
    int sector_count;

    sector_count = sector_length;
    sector_count += byte_count;
    return (sector_count - 1) / sector_length;
}

static inline MfCiObject *mfci_alloc(void) {
    MfCiObject *handle = 0;
    int index;

    for (index = 0; index < MFCI_MAX_HANDLES; index++) {
        if (lbl_8019017C__fzgx_offset_130[index].used == 0) {
            handle = &lbl_8019017C__fzgx_offset_130[index];
            break;
        }
    }
    return handle;
}

static inline unsigned char *mfci_get_adr_size(const char *filename, int *file_size) {
    char *end;
    unsigned long address;

    if (strlen(filename) != 17) {
        sprintf(lbl_8019017C__fzgx_offset_4, "E01100308:length of '%s' is not 17 bytes.(mfci_get_adr_size)", filename);
        if (lbl_80190178 != 0) {
            lbl_80190178(lbl_8019017C, lbl_8019017C__fzgx_offset_4, 0);
        }
    }
    if (filename[8] != '.') {
        sprintf(lbl_8019017C__fzgx_offset_4, "E01100309:illegal file name format '%s'(mfci_get_adr_size)", filename);
        if (lbl_80190178 != 0) {
            lbl_80190178(lbl_8019017C, lbl_8019017C__fzgx_offset_4, 0);
        }
    }

    end = (char *)filename;
    address = strtoul(filename, &end, 16);
    if (*end != '\0') {
        end++;
    }
    if (file_size != 0) {
        *file_size = strtoul(end, &end, 16);
    }
    return (unsigned char *)address;
}

void *fn_8005A24C(const char *filename, void *parameter, int mode) {
    MfCiObject *handle;
    int file_size;

    if (filename == 0) {
        mfci_call_errfn("E01100301:fname is null.(mfCiOpen)", 0);
        return 0;
    }
    if (mode != 0) {
        if (lbl_80190178 != 0) {
            lbl_80190178(lbl_8019017C, "E01100302:rw is illigal.(mfCiOpen)", 0);
        }
        return 0;
    }

    handle = mfci_alloc();
    if (handle == 0) {
        if (lbl_80190178 != 0) {
            lbl_80190178(lbl_8019017C, "E01100303:not enough handle resource.(mfCiOpen)", 0);
        }
        return 0;
    }

    fn_80083DB0(handle->filename, filename);
    handle->sector_length = MFCI_DEFAULT_SECTOR_LENGTH;
    mfci_get_adr_size(handle->filename, &file_size);
    handle->file_size = file_size;
    handle->sector_count =
        mfci_ByteToSct(handle->sector_length, handle->file_size);
    handle->sector_position = 0;
    handle->request_sectors = 0;
    handle->transfer_length = 0;
    handle->status = MFCI_STATUS_IDLE;
    handle->used = 1;
    return handle;
}
