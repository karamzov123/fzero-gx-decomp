#include "types.h"

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

int sprintf(char *s, const char *format, ...);
unsigned long strlen(const char *s);
unsigned long strtoul(const char *str, char **endptr, int base);
void *memcpy(void *dst, const void *src, unsigned long n);
void *memset(void *dst, int c, unsigned long n);
void fn_80059B44(void);
void fn_80059AB4(void);

#pragma section code_type ".fzgxpool"
static const void *fzgx_pool_layout(int x) {
    volatile u8 s; // fzgx-allow: S2 BSS primer ordering
    s = *(u8 *)&lbl_80190178;
    s = *(u8 *)&lbl_8019017C;
    s = *(u8 *)&lbl_8019017C__fzgx_offset_4;
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
    return 0;
}
#pragma section code_type ".text"

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

long fn_80059DD8(void *mfci, long nsct, void *buf) {
    MfCiObject *handle = mfci;
    unsigned char *address;
    int file_size;
    long length;
    long offset;
    long remaining;
    long rest;

    if (handle == 0) {
        if (lbl_80190178 != 0) {
            lbl_80190178(lbl_8019017C, "E01100307:handl is null.", 0);
        }
        return 0;
    }
    if (nsct < 0) {
        if (lbl_80190178 != 0) {
            lbl_80190178(lbl_8019017C, "E01100308:nsct < 0.(mfCiReqRd)", handle);
        }
        return 0;
    }
    if (buf == 0) {
        if (lbl_80190178 != 0) {
            lbl_80190178(lbl_8019017C, "E01100309:buf is null.(mfCiReqRd)", handle);
        }
        return 0;
    }
    if (nsct == 0) {
        handle->status = 1;
        return 0;
    }

    fn_80059B44();
    handle->transfer_length = 0;
    remaining = handle->sector_count - handle->sector_position;
    handle->request_sectors = (nsct < remaining) ? nsct : remaining;
    offset = handle->sector_position * handle->sector_length;
    length = handle->request_sectors * handle->sector_length;
    if (length == 0) {
        handle->status = 1;
        fn_80059AB4();
        return 0;
    }
    handle->source_offset = offset;
    handle->request_length = length;
    handle->status = 2;

    address = mfci_get_adr_size(handle->filename, &file_size);
    rest = file_size - handle->source_offset;
    length = (handle->request_length > rest) ? rest : handle->request_length;
    memcpy(buf, address + handle->source_offset, handle->request_length);
    memset((u8 *)buf + length, 0, handle->request_length - length);
    handle->transfer_length = handle->request_sectors * handle->sector_length;
    handle->sector_position += handle->request_sectors;
    handle->status = 1;
    fn_80059AB4();
    return handle->request_sectors;
}
