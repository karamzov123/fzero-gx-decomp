/* Non-matching: best partial attempt (96.17% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef void (*MfCiErrorCallback)(void *object, const char *message, void *handle);

int sprintf(char *output, const char *format, ...);

unsigned long strtoul(const char *str, char **end, int base);

size_t strlen(const char *string);

extern void fn_80083DB0(void *destination, const void *source);

extern char lbl_800924F8[];

typedef struct MfCiObject {
    signed char used;
    signed char status;
    unsigned char reserved_02[2];
    int sector_length;
    int file_size;
    int sector_count;
    int sector_position;
    int transfer_length;
    int request_sectors;
    char filename[20];
    int source_offset;
    int request_length;
} MfCiObject;

struct mfciBss {
    MfCiErrorCallback mfci_err_func;
    void *mfci_err_obj;
    char mfci_err_str[300];
    MfCiObject mfci_objects[40];
};
extern struct mfciBss lbl_80190178;

static inline char *fn_8005A24C_array_read(char *array) { return array; }
#pragma opt_common_subs off
#pragma opt_loop_invariants off
static inline MfCiErrorCallback fn_8005A24C_read_pointer(struct mfciBss * owner) { return owner->mfci_err_func; }
#pragma opt_lifetimes off
MfCiObject *fn_8005A24C(const char *filename, u32 arg1, s32 arg2) {
    MfCiObject *handle;
    const char *rodata = lbl_800924F8;
    struct mfciBss *bss = &lbl_80190178;
    u32 file_size;
    char *end;
    int i;
    MfCiObject *p;
    int total;

    if (filename == 0) {
        if (fn_8005A24C_read_pointer(bss) != 0) {
            fn_8005A24C_read_pointer(bss)(bss->mfci_err_obj, rodata + 0x21c, 0);
        }
        return 0;
    }
    if (arg2 != 0) {
        if (fn_8005A24C_read_pointer(bss) != 0) {
            fn_8005A24C_read_pointer(bss)(bss->mfci_err_obj, rodata + 0x240, 0);
        }
        return 0;
    }
    for (handle = 0, i = 0, p = bss->mfci_objects; i < 40; p++, i++) {
        if (p->used == 0) {
            handle = bss->mfci_objects;
            handle += i;
            break;
        }
    }
    if (handle == 0) {
        if (fn_8005A24C_read_pointer(bss) != 0) {
            fn_8005A24C_read_pointer(bss)(bss->mfci_err_obj, rodata + 0x264, 0);
        }
        return 0;
    }
    fn_80083DB0(handle->filename, filename);
    handle->sector_length = 0x800;
    if (strlen(handle->filename) != 17) {
        sprintf(bss->mfci_err_str, rodata + 0xc0, handle->filename);
        if (fn_8005A24C_read_pointer(bss) != 0) {
            fn_8005A24C_read_pointer(bss)(bss->mfci_err_obj, bss->mfci_err_str, 0);
        }
    }
    if (fn_8005A24C_array_read(handle->filename)[8] != '.') {
        sprintf(bss->mfci_err_str, rodata + 0x100, handle->filename);
        if (fn_8005A24C_read_pointer(bss) != 0) {
            fn_8005A24C_read_pointer(bss)(bss->mfci_err_obj, bss->mfci_err_str, 0);
        }
    }
    end = (char *)handle->filename;
    strtoul(handle->filename, &end, 16);
    if (*end != '\0') {
        end++;
    }
    if (&file_size != 0) {
        file_size = (u32)strtoul(end, &end, 16);
    }
    handle->file_size = (int)file_size;
    total = ((handle->file_size) + (handle->sector_length)) - 1;
    handle->sector_count = total / handle->sector_length;
    handle->sector_position = 0;
    handle->request_sectors = 0;
    handle->transfer_length = 0;
    handle->status = 0;
    handle->used = 1;
    return handle;
}
#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset

#pragma opt_common_subs reset
