#include "types.h"
extern void fn_80056710(void *);
extern void fn_800566F0(void *);
extern void fn_8004AC58(void *);

extern u32 fn_800565FC(const char *, ...);
extern u32 lbl_80092188[];
extern u32 lbl_800921D0[];


u32 fn_80056730(u32 arg0, u32 arg1) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = (u32)&lbl_80092188;
    t0 = fn_800565FC((const char *)v0);
    v0 = t0;
    } else {
    *(u8 *)((u8 *)v0 + 3) = arg1;
    }
    return v0;
}

typedef u32 (*fn_8005676C_Fn0)(u32, u32);
struct fn_8005676C_lbl_80188A78 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

extern struct fn_8005676C_lbl_80188A78 lbl_80188A78[];

void fn_8005676C(void) {
    u32 v0;
    u32 t0;
    if (lbl_80188A78[0].unk_0 != 0) {
    v0 = lbl_80188A78[0].unk_4;
    t0 = ((fn_8005676C_Fn0)lbl_80188A78[0].unk_0)(v0, lbl_80188A78[0].unk_8);
    v0 = t0;
    }
}

u32 fn_800567AC(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = (u32)&lbl_80092188;
    t0 = fn_800565FC((const char *)v0);
    v0 = t0;
    v0 = -1;
    } else {
    v0 = *(u32 *)(v0 + 20);
    }
    return v0;
}

extern u32 lbl_800921AC[];

u32 fn_800567EC(u32 arg0, u32 arg1) {
    u32 v0;
    u32 t0, t1;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = (u32)&lbl_80092188;
    t0 = fn_800565FC((const char *)v0);
    v0 = t0;
    } else {
    if ((s32)arg1 < 0 || (s32)arg1 > (s32)*(u32 *)(v0 + 24)) {
    v0 = (u32)&lbl_800921AC;
    t1 = fn_800565FC((const char *)v0, arg1);
    v0 = t1;
    } else {
    *(u32 *)((u8 *)v0 + 20) = arg1;
    }
    }
    return v0;
}

typedef struct {
    u32 key;
    u8 unk04[0x18];
    u32 val;
} Entry;

typedef struct {
    u8 unk00[0x38];
    Entry entries[16];
} Table;

u32 fn_80056850(u32 arg0, u32 arg1) {
    u32 v0;
    s32 v3;
    Table *tbl;

    v0 = arg0;
    if (arg0 == 0) {
    v0 = (u32)&lbl_80092188;
    fn_800565FC((const char *)v0);
    v0 = 0;
    } else {
    tbl = (Table *)arg0;
    for (v3 = 0; v3 < 16; v3++) {
    if ((s32)tbl->entries[v3].key == (s32)arg1) {
    break;
    }
    }
    if (v3 == 16) {
    v0 = (u32)&lbl_800921D0;
    fn_800565FC((const char *)v0, arg1);
    v0 = 0;
    } else {
    v0 = tbl->entries[v3].val;
    }
    }
    return v0;
}

typedef struct {
    s32 key;
    u8 unk04[0x14];
    s32 val;
    u8 unk1C[4];
} Lsc950Entry;

typedef struct {
    u8 unk00[0x38];
    Lsc950Entry entries[16];
} Lsc950Table;

int fn_80056950(Lsc950Table *tbl, int value) {
    int count;

    if (tbl == 0) {
        fn_800565FC((const char *)&lbl_80092188);
        return -1;
    }

    for (count = 0; count < 16; count++) {
        if (tbl->entries[count].key == value) {
            break;
        }
    }

    if (count == 16) {
        fn_800565FC((const char *)&lbl_800921D0);
        return -1;
    }

    return tbl->entries[count].val;
}

u32 fn_80056A50(s32 *arg0, s32 arg1) {
    s32 i;

    if (arg0 == 0) {
        fn_800565FC((const char *)&lbl_80092188);
        return 0;
    }

    for (i = 0; i < 16; i++) {
        s32 v = arg0[i * 8 + 14];
        if (v == arg1) {
            break;
        }
    }

    if (i == 16) {
        fn_800565FC((const char *)&lbl_800921D0);
        return 0;
    }

    return arg0[i * 8 + 15];
}

extern u32 lbl_800921F4[];

typedef struct {
    u8 pad20[0x20];
    u32 offset;
    u32 count;
    u8 pad2c[0x10];
    u32 values[1];
} Fn80056B50Data;

s32 fn_80056B50(Fn80056B50Data *arg0, s32 arg1) {
    if (arg0 == 0) {
        fn_800565FC((const char *)&lbl_80092188);
        return -1;
    }
    if (arg1 < 0 || arg1 >= (s32)arg0->count) {
        fn_800565FC((const char *)&lbl_800921F4);
        return -1;
    }
    arg1 = arg0->offset + arg1;
    arg0 = (Fn80056B50Data *)((u8 *)arg0 + (arg1 % 16) * 32);
    return arg0->values[0];
}

u32 fn_80056BE0(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = (u32)&lbl_80092188;
    t0 = fn_800565FC((const char *)v0);
    v0 = t0;
    v0 = -1;
    } else {
    v0 = *(u32 *)(v0 + 36);
    }
    return v0;
}

u32 fn_80056C20(u32 arg0) {
    u32 v0;
    u32 t0;

    v0 = arg0;
    if (arg0 == 0) {
        v0 = (u32)&lbl_80092188;
        t0 = fn_800565FC((const char *)v0);
        v0 = t0;
        v0 = -1;
    } else {
        v0 = *(s8 *)(v0 + 1);
    }
    return v0;
}

extern void fn_80057494(void *);

typedef struct Fn80056C64_Lsc950Entry {
    s8 flag;
    u8 pad[0x237];
} Fn80056C64_Lsc950Entry;

extern Fn80056C64_Lsc950Entry lbl_80188A8C[16];

void fn_80056C64(void) {
    u8 local[16];
    s32 i;

    fn_80056710(local);
    i = 0;
    do {
        if (lbl_80188A8C[i].flag == 1) {
            fn_80057494(&lbl_80188A8C[i]);
        }
        i++;
    } while (i < 0x10);
    fn_800566F0(local);
}


typedef struct Fn80056CD0 {
    u8 pad0[1];
    s8 flag1;
    s8 flag2;
    u8 pad3[0x19];
    u32 field1c;
    u32 field20;
    u32 field24;
    u32 resource;
    u32 field2c;
    u8 pad30[4];
    u32 field34;
} Fn80056CD0;

void fn_80056CD0(Fn80056CD0 *arg0) {
    if (arg0 == 0) {
        fn_800565FC((const char *)&lbl_80092188);
    } else if (arg0->flag1) {
        arg0->flag1 = 0;
        if (arg0->resource != 0 && arg0->flag2 == 1) {
            fn_8004AC58((void *)arg0->resource);
            arg0->flag2 = 0;
        }
        arg0->field2c = 0;
        if (arg0 == 0) {
            fn_800565FC((const char *)&lbl_80092188);
        } else if (!arg0->flag1) {
            arg0->field1c = 0;
            arg0->field20 = 0;
            arg0->field24 = 0;
        }
        arg0->field34 = 0;
    }
}

typedef struct SJCK {
    unsigned char *data;
    int len;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface SJInterface;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface {
    void *reserved[3];
    void (*destroy)(SJ *sj);
    const void *(*get_uuid)(SJ *sj);
    void (*reset)(SJ *sj);
    void (*get_chunk)(SJ *sj, int channel, int max_size, SJCK *chunk);
    void (*unget_chunk)(SJ *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
    int (*get_num_data)(SJ *sj, int channel);
    int (*is_get_chunk)(SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ *sj, SJErrorCallback callback, void *object);
};

struct SJ {
    const SJInterface *interface;
};

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
    u8 reserved_05;
    u16 reserved_06;
    SJ *sj;
    SJCK chunk;
    s32 minimum_buffer_size;
    s32 buffer_size;
    s32 write_position;
    s32 read_position;
    s32 stream_count;
    ADXStream *stream;
    s32 file_sectors;
    s32 requested_sectors;
    s32 error_count;
    LSCStreamInfo stream_info[16];
} LSCObject;




static inline void lsc_ResetEntries(LSCObject *lsc) {
    if (lsc == 0) {
        fn_800565FC("E0003: Illigal parameter lsc=NULL\n");
    } else if (lsc->state == 0) {
        lsc->write_position = 0;
        lsc->read_position = 0;
        lsc->stream_count = 0;
    }
}

static inline void LSC_Stop(LSCObject *lsc) {
    if (lsc == 0) {
        fn_800565FC("E0003: Illigal parameter lsc=NULL\n");
        return;
    }
    if (lsc->state != 0) {
        lsc->state = 0;
        if (lsc->stream != 0 && lsc->reading == 1) {
            fn_8004AC58(lsc->stream);
            lsc->reading = 0;
        }
        lsc->file_sectors = 0;
        lsc_ResetEntries(lsc);
        lsc->error_count = 0;
    }
}

void LSC_Start(LSCObject *lsc) {
    s32 critical_state;
    if (lsc == 0) {
        fn_800565FC("E0003: Illigal parameter lsc=NULL\n");
        return;
    }
    fn_80056710(&critical_state);
    if (lsc->state != 0) {
        LSC_Stop(lsc);
    }
    if (lsc->stream_count > 0) {
        lsc->state = 2;
    } else {
        lsc->state = 1;
    }
    fn_800566F0(&critical_state);
}

typedef struct LSCObject_u1 {
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
} LSCObject_u1;

void fn_8005676C(void);
s32 fn_80056E9C(LSCObject_u1 *lsc, const char *filename, void *directory, s32 offset, s32 sector_count);
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


static inline LSCStreamInfo *lsc_GetWriteEntry(LSCObject_u1 *lsc) {
    return &lsc->stream_info[lsc->write_position];
}

s32 fn_80056E9C(LSCObject_u1 *lsc, const char *filename, void *directory, s32 offset, s32 sector_count) {
    LSCStreamInfo *info;
    s32 stream_id;
    u32 *words;
    unsigned long i;
    unsigned long filename_length;

    if (lsc == 0) {
        fn_800565FC("E0003: Illigal parameter lsc=NULL\n");
        return -1;
    }
    if (lsc->stream_count >= 16) {
        return -1;
    }
    if (filename == 0) {
        fn_800565FC("E0011: Illigal parameter fname=%s\n", filename);
        return -1;
    }

    words = (u32 *)filename;
    stream_id = lsc->stream_info[(lsc->write_position + 15) % 16].id;
    info = lsc_GetWriteEntry(lsc);
    stream_id = (stream_id == 0x7FFFFFFF) ? 0 : stream_id + 1;
    info->id = stream_id;
    info->filename = filename;
    filename_length = strlen(filename) / 4;
    info->filename_checksum = 0;
    for (i = 0; i < filename_length; i++) {
        info->filename_checksum += words[i];
    }
    info->offset = offset;
    info->sector_count = sector_count;
    info->directory = directory;
    info->state = 0;
    info->read_sectors = 0;

    lsc->stream_count++;
    lsc->write_position = (lsc->write_position + 1) % 16;
    if (lsc->state == 1) {
        lsc->state = 2;
    }
    return stream_id;
}

void fn_800570DC(u32 arg0, u32 arg1) {
    fn_80056E9C((void *)arg0, (void *)arg1, 0, 0, (0x100000 - 1));
}

typedef struct {
    u8 pad_0x00[0x28];
    int value;
} Fn8005710CObject;

void fn_8005710C(Fn8005710CObject *object, int value) {
    object->value = value;
}

extern u32 memset(u32, u32, u32);

u32 fn_80057114(u32 arg0) {
    u32 v0;
    u32 t0, t1, t2, t3;
    v0 = arg0;
    if (arg0 != 0) {
    if (arg0 == 0) {
    v0 = (u32)&lbl_80092188;
    t0 = fn_800565FC((const char *)v0);
    v0 = t0;
    } else {
    if ((s8)*(u8 *)(arg0 + 1) != 0) {
    *(u8 *)((u8 *)arg0 + 1) = 0;
    v0 = *(u32 *)(arg0 + 40);
    if (v0 != 0 && (s32)*(u8 *)(arg0 + 2) == 1) {
    fn_8004AC58((void *)v0);
    v0 = t1;
    *(u8 *)((u8 *)arg0 + 2) = 0;
    }
    v0 = 0;
    *(u32 *)((u8 *)arg0 + 44) = v0;
    if (arg0 == 0) {
    v0 = (u32)&lbl_80092188;
    t2 = fn_800565FC((const char *)v0);
    v0 = t2;
    } else {
    if ((s8)*(u8 *)(arg0 + 1) == 0) {
    *(u32 *)((u8 *)arg0 + 28) = v0;
    *(u32 *)((u8 *)arg0 + 32) = v0;
    *(u32 *)((u8 *)arg0 + 36) = v0;
    }
    }
    *(u32 *)((u8 *)arg0 + 52) = 0;
    }
    }
    v0 = arg0;
    *(u8 *)((u8 *)arg0 + 0) = 0;
    t3 = memset(v0, 0, 568);
    v0 = t3;
    }
    return v0;
}

typedef struct Fn800571EC_Stream Fn800571EC_Stream;

typedef struct Fn800571EC_StreamVtbl {
    u8 pad_0[0x24];
    s32 (*unk_24)(Fn800571EC_Stream *, s32);
} Fn800571EC_StreamVtbl;

struct Fn800571EC_Stream {
    Fn800571EC_StreamVtbl *vtbl;
};

typedef struct Fn800571EC_Slot {
    u8 pad_0[0x18];
    s32 unk_18;
    u8 pad_1C[0x4];
} Fn800571EC_Slot;

typedef struct Fn800571EC_Entry {
    s8 unk_0;
    s8 unk_1;
    u8 pad_2[0x6];
    Fn800571EC_Stream *unk_8;
    u8 pad_C[0x8];
    s32 unk_14;
    s32 unk_18;
    u8 pad_1C[0x1C];
    Fn800571EC_Slot slots[16];
} Fn800571EC_Entry;

extern char lbl_80092238[];
extern char lbl_80092264[];

static inline Fn800571EC_Entry *fn_800571EC_FindFree(void) {
    Fn800571EC_Entry *entry = NULL;
    s32 i;

    for (i = 0; i < 16; i++) {
        if (((Fn800571EC_Entry *)lbl_80188A8C)[i].unk_0 == 0) {
            entry = &((Fn800571EC_Entry *)lbl_80188A8C)[i];
            break;
        }
    }
    return entry;
}

Fn800571EC_Entry *fn_800571EC(Fn800571EC_Stream *stream) {
    u8 lock[8];
    Fn800571EC_Entry *entry;
    s32 i;

    if (stream == NULL) {
        fn_800565FC(lbl_80092238);
        return NULL;
    }

    fn_80056710(lock);
    entry = fn_800571EC_FindFree();

    if (entry == NULL) {
        fn_800565FC(lbl_80092264);
    } else {
        entry->unk_8 = stream;
        entry->unk_1 = 0;
        entry->unk_18 = stream->vtbl->unk_24(stream, 0) + stream->vtbl->unk_24(stream, 1);
        entry->unk_14 = entry->unk_18 * 8 / 10;
        for (i = 0; i < 16; i++) {
            entry->slots[i].unk_18 = 0;
        }
        entry->unk_0 = 1;
    }
    fn_800566F0(lock);
    return entry;
}
