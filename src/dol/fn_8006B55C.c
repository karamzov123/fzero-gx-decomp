#include "types.h"


/* --- dol/fn_8006B55C.c --- */
typedef struct Fn8006B55CFlags {
    u8 flag7:1;
    u8 flag6:1;
    u8 rest:6;
} Fn8006B55CFlags;

typedef struct Fn8006B55CData {
    u8 flags_pad[4];
    Fn8006B55CFlags flags;
    u8 _pad0[3];
    u32 value;
    u8 _pad1[0x44];
    u8 payload[1];
} Fn8006B55CData;

extern void fn_8006BC50(void *value);
extern s32 fn_8006BA74(void *value);

static inline s32 Fn8006B55CClose(void *handle) {
    Fn8006B55CData *data = handle;

    if (data == 0 || (u32)data + 0x10000 == 0xffff) {
        return -2;
    }
    if (data->flags.flag7 == 0) {
        return -2;
    }
    data->flags.flag7 = 0;
    data->flags.flag6 = 0;
    fn_8006BC50(data->payload);
    data->value = -1;
    return 0;
}

s32 fn_8006B55C(Fn8006B55CData *data, u32 arg1, u32 arg2) {
    if (data == 0 || (u32)data + 0x10000 == 0xffff) {
        return -2;
    }
    if (data->flags.flag7 == 0) {
        return -2;
    }
    if (arg1 == 0) {
        return -2;
    }
    if (arg2 == 0) {
        return -2;
    }
    if (data->flags.flag6 != 0) {
        Fn8006B55CClose(data);
        return -2;
    }
    return fn_8006BA74(data->payload);
}

/* --- dol/fn_8006B628.c --- */
typedef struct Fn8006B628Data {
    u8 pad_0[4];
    struct {
        u8 flag7 : 1;
        u8 flag6 : 1;
        u8 rest : 6;
    } flags;
    u8 pad_5[3];
    u32 unk_8;
    u8 pad_C[0x44];
    u8 data[1];
} Fn8006B628Data;

extern u8 lbl_80199670[18720];
extern void fn_8006BC50(void *data);
extern s32 fn_8006BB30(void *data, u32 value, u32 param);

s32 fn_8006B628(u32 value, u32 param) {
    u32 index;
    Fn8006B628Data *entry;
    u32 enabled;

    index = value >> 16;
    if (index >= 4) {
        return -2;
    }
    entry = (Fn8006B628Data *)(lbl_80199670 + index * 0x1248);
    enabled = entry->flags.flag7;
    if (enabled == 0) {
        return -2;
    }
    if (param == 0) {
        return -2;
    }
    if (entry->flags.flag6) {
        if (entry != 0 && (u32)entry + 0x10000 != 0xffff && enabled != 0) {
            entry->flags.flag7 = 0;
            entry->flags.flag6 = 0;
            fn_8006BC50(&entry->data[0]);
            entry->unk_8 = -1;
        }
        return -2;
    }
    return fn_8006BB30(&entry->data[0], value, param);
}

/* --- dol/fn_8006B6F8.c --- */
typedef struct Fn8006B6F8Data {
    u8 pad_0[4];
    struct {
        u8 flag7 : 1;
        u8 flag6 : 1;
        u8 rest : 6;
    } flags;
    u8 pad_5[3];
    u32 unk_8;
    u8 pad_C[0x44];
    u8 data[1];
} Fn8006B6F8Data;

extern s32 fn_8006BB9C(void *data, u32 value);

s32 fn_8006B6F8(u32 value) {
    u32 index;
    Fn8006B6F8Data *entry;
    u32 enabled;

    index = value >> 16;
    if (index >= 4) {
        return -2;
    }
    entry = (Fn8006B6F8Data *)(lbl_80199670 + index * 0x1248);
    enabled = entry->flags.flag7;
    if (enabled == 0) {
        return -2;
    }
    if (entry->flags.flag6) {
        if (entry != 0 && (u32)entry + 0x10000 != 0xffff && enabled != 0) {
            entry->flags.flag7 = 0;
            entry->flags.flag6 = 0;
            fn_8006BC50(&entry->data[0]);
            entry->unk_8 = -1;
        }
        return -2;
    }
    return fn_8006BB9C(&entry->data[0], value);
}

/* --- dol/fn_8006B7B4.c --- */
typedef struct Fn8006B7B4Entry {
    u8 pad_0[4];
    struct {
        u8 flag7 : 1;
        u8 flag6 : 1;
        u8 rest : 6;
    } flags;
    u8 pad_5[3];
    u32 unk_8;
    u8 pad_C[0x44];
    u8 data[1];
} Fn8006B7B4Entry;

extern s32 fn_8006BBDC(void *data, u32 value);

s32 fn_8006B7B4(u32 value) {
    u32 index;
    Fn8006B7B4Entry *entry;
    u32 enabled;

    index = value >> 16;
    if (index >= 4) {
        return -2;
    }
    entry = (Fn8006B7B4Entry *)(lbl_80199670 + index * 0x1248);
    enabled = entry->flags.flag7;
    if (enabled == 0) {
        return -2;
    }
    if (entry->flags.flag6) {
        if (entry != 0 && (u32)entry + 0x10000 != 0xffff && enabled != 0) {
            entry->flags.flag7 = 0;
            entry->flags.flag6 = 0;
            fn_8006BC50(&entry->data[0]);
            entry->unk_8 = -1;
        }
        return -2;
    }
    return fn_8006BBDC(&entry->data[0], value);
}

/* --- dol/fn_8006B870.c --- */
typedef struct Fn8006B870Data {
    u8 pad_0[4];
    struct {
        u8 flag7 : 1;
        u8 flag6 : 1;
        u8 rest : 6;
    } flags;
    u8 pad_5[3];
    u32 unk_8;
    u8 pad_C[0x44];
    u8 data[1];
} Fn8006B870Data;

extern s32 fn_8006BB74(void *data, u32 value);

s32 fn_8006B870(u32 value) {
    u32 index;
    Fn8006B870Data *entry;
    u32 enabled;

    index = value >> 16;
    if (index >= 4) {
        return -2;
    }
    entry = (Fn8006B870Data *)(lbl_80199670 + index * 0x1248);
    enabled = entry->flags.flag7;
    if (enabled == 0) {
        return -2;
    }
    if (entry->flags.flag6) {
        if (entry != 0 && entry != (Fn8006B870Data *)-1 && enabled != 0) {
            entry->flags.flag7 = 0;
            entry->flags.flag6 = 0;
            fn_8006BC50(&entry->data[0]);
            entry->unk_8 = -1;
        }
        return -2;
    }
    return fn_8006BB74(&entry->data[0], value);
}
