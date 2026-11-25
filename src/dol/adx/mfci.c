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
char *strcpy(char *dst, const char *src);
u32 fn_80059B44(void);
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


u32 fn_80059AB4(void);
extern u32 lbl_80092634[];
extern u32 lbl_8009264C[];
extern u32 lbl_80092664[];
extern u32 lbl_800926DC[];
extern u32 lbl_800926F8[];
extern const char lbl_800925B8[];
extern const char lbl_800925F8[];
extern u8 lbl_801324F0[104];


typedef u32 (*fn_80059BAC_Fn0)(u32, u32, u32);
u32 fn_80059BAC(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
    if (((u32)lbl_80190178) != 0) {
    v0 = ((u32)lbl_8019017C);
    t0 = ((fn_80059BAC_Fn0)((u32)lbl_80190178))(v0, (u32)&lbl_80092634, 0);
    v0 = t0;
    }
    v0 = 0;
    } else {
    v0 = *(u32 *)(v0 + 20);
    }
    return v0;
}

typedef void (*fn_80059C0C_Fn0)(u32, void *, u32);

struct fn_80059C0C_Data {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u8 pad_1C[0x9D4];
};

void fn_80059C0C(struct fn_80059C0C_Data *arg0, s32 arg1) {
    struct { s32 value; } v2;
    s32 t;
    fn_80059C0C_Fn0 callback;

    if (arg0 == 0) {
        callback = ((fn_80059C0C_Fn0)lbl_80190178);
        if (callback != 0) {
            callback(((u32)lbl_8019017C), &lbl_8009264C, 0);
        }
    } else {
        t = arg0->unk_10 * arg0->unk_4;
        arg0->unk_4 = arg1;
        v2.value = arg0->unk_4 + arg0->unk_8;
        v2.value = v2.value - 1;
        arg0->unk_C = v2.value / arg0->unk_4;
        arg0->unk_10 = t / arg0->unk_4;
        arg0->unk_14 = arg0->unk_18 * arg1;
    }
}

typedef u32 (*fn_80059CA4_Fn0)(u32, u32, u32);
u32 fn_80059CA4(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
        if (((u32)lbl_80190178) != 0) {
            v0 = ((u32)lbl_8019017C);
            t0 = ((fn_80059CA4_Fn0)((u32)lbl_80190178))(v0, (u32)&lbl_80092664, 0);
            v0 = t0;
        }
        v0 = 0;
    } else {
        v0 = *(u32 *)(v0 + 4);
    }
    return v0;
}

typedef u32 (*fn_80059D04_Fn0)(u32, u32, u32);
s32 fn_80059D04(s8 *arg0) {
    u32 v0;
    u32 t0;
    if (arg0 == 0) {
        if (((u32)lbl_80190178) != 0) {
            v0 = ((u32)lbl_8019017C);
            t0 = ((fn_80059D04_Fn0)((u32)lbl_80190178))(v0, (u32)&lbl_80092634, 0);
            v0 = t0;
        }
        return 0;
    }
    return arg0[1];
}

typedef void (*fn_80059D68_Fn0)(u32, void *, u32);

typedef struct Fn80059D68 {
    u8 unk00;
    u8 unk01;
} Fn80059D68;

void fn_80059D68(Fn80059D68 *self) {
    if (self == 0) {
        if (((u32)lbl_80190178) != 0) {
            ((fn_80059D68_Fn0)((u32)lbl_80190178))(
                ((u32)lbl_8019017C), &lbl_80092634, 0);
        }
    } else {
        fn_80059B44();
        self->unk01 = 0;
        fn_80059AB4();
    }
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

typedef u32 (*fn_8005A060_Fn0)(u32, u32, u32);
u32 fn_8005A060(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
        if (((u32)lbl_80190178) != 0) {
            v0 = ((u32)lbl_8019017C);
            t0 = ((fn_8005A060_Fn0)((u32)lbl_80190178))(v0, (u32)&lbl_800926DC, 0);
            v0 = t0;
        }
        v0 = 0;
    } else {
        v0 = *(u32 *)(v0 + 16);
    }
    return v0;
}

typedef u32 (*fn_8005A0C0_Fn0)(u32, u32, u32);

#pragma opt_common_subs off
u32 fn_8005A0C0(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t0, t1, t2;
    v0 = arg0;
    if (arg0 == 0) {
        v1 = arg1;
        v2 = arg2;
        if (((u32)lbl_80190178) != 0) {
            v2 = (u32)&lbl_8019017C;
            v1 = (u32)&lbl_800926F8;
            v0 = *(u32 *)(v2);
            v2 = 0;
            t0 = ((fn_8005A0C0_Fn0)((u32)lbl_80190178))(v0, v1, v2);
            v0 = t0;
        }
        v0 = 0;
    } else {
        t1 = fn_80059B44();
        v0 = t1;
        if ((s32)arg2 == 0) {
            *(u32 *)((u8 *)arg0 + 16) = arg1;
        } else {
            if ((s32)arg2 == 2) {
                *(u32 *)((u8 *)arg0 + 16) = (*(u32 *)((u8 *)arg0 + 12) + arg1);
            } else {
                if ((s32)arg2 == 1) {
                    *(u32 *)((u8 *)arg0 + 16) = (*(u32 *)((u8 *)arg0 + 16) + arg1);
                }
            }
        }
        v3 = *(u32 *)(arg0 + 12);
        v0 = *(u32 *)(arg0 + 16);
        if ((s32)v0 < (s32)v3) {
            v3 = v0;
        }
        *(u32 *)((u8 *)arg0 + 16) = v3;
        *(u32 *)((u8 *)arg0 + 16) = (s32)*(u32 *)((u8 *)arg0 + 16) > 0 ? *(u32 *)((u8 *)arg0 + 16) : 0;
        t2 = fn_80059AB4();
        v0 = t2;
        v0 = *(u32 *)(arg0 + 16);
    }
    return v0;
}
#pragma opt_common_subs reset

static inline void mfCiStopTr(void *object) {
    MfCiObject *handle = (MfCiObject *)object;
    if (handle == 0) {
        if (lbl_80190178 != 0) {
            lbl_80190178(lbl_8019017C, "E0092912:handl is null.", 0);
        }
        return;
    }
    fn_80059B44();
    handle->status = MFCI_STATUS_IDLE;
    fn_80059AB4();
}

void mfCiClose(void *object) {
    MfCiObject *handle = (MfCiObject *)object;
    if (handle != 0) {
        mfCiStopTr(handle);
        if (handle->used == 1) {
            handle->used = 0;
            memset(handle, 0, sizeof(*handle));
        }
    }
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

    strcpy(handle->filename, filename);
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

int mfCiGetFileSize(const char *filename) {
    int file_size;
    mfci_get_adr_size(filename, &file_size);
    return file_size;
}

#pragma opt_propagation off

void fn_8005A588(u32 arg0, u32 arg1) {
    lbl_80190178 = (MfCiErrorCallback)arg0;
    lbl_8019017C = (void *)arg1;
}

void fn_8005A59C(void) {
    int i;
    for (i = 0; i < 40; i++) {
    }
}

// The retail code performs this read even though its value is discarded.
u8 *fn_8005A5A8(void) {
    lbl_80092528[0];
    return lbl_801324F0;
}
