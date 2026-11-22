#include "types.h"

extern u32 fn_800576DC(void);
extern u32 fn_80057728(void);
extern void *memset(void *destination, int value, u32 size);
extern u32 lbl_8018AE18[];
extern u8 lbl_8018AE1C[1156];


typedef u32 (*fn_80057774_Fn0)(s32, s32);


u32 fn_80057774(u32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    s32 var_r0;
    s32 temp_r3;
    fn_80057774_Fn0 temp_r12;

    fn_80057728();
    if (arg1 == 0) {
        var_r0 = 0;
    } else if (arg1 == 1) {
        temp_r3 = *(s32 *)(arg0 + 12);
        var_r0 = (temp_r3 < arg2) ? temp_r3 : arg2;
    } else {
        var_r0 = 0;
        temp_r12 = *(fn_80057774_Fn0 *)(arg0 + 28);
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)(arg0 + 32), -3);
        }
    }
    *arg3 = var_r0;
    fn_800576DC();
    return !(arg2 - var_r0);
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

typedef struct SJMemoryUuid {
    u32 time_low;
    u16 time_mid;
    u16 time_high_and_version;
    u8 clock_sequence_and_node[8];
} SJMemoryUuid;

typedef struct SJMemory {
    const SJInterface *interface;
    int used;
    const SJMemoryUuid *uuid;
    int available;
    int read_position;
    u8 *buffer;
    int buffer_size;
    SJErrorCallback error_callback;
    void *error_object;
} SJMemory;


#pragma opt_dead_assignments off
u32 fn_8005782C(SJ *sj, int channel, SJCK *chunk) {
    int *fzgx_value_;
    u8 * fzgx_live__;
    u8 * fzgx_live_;
    int *fzgx_value;
    int chunk_len;
    int position;
    int clamped_position;
    int data_position;
    SJMemory *memory;

    memory = (SJMemory *)sj;
    if (chunk->len > 0) {
        if (chunk->data == 0) {
            return (u32)memory;
        }
        fn_80057728();
        if (channel == 0) {
            if (memory->error_callback != 0) {
                memory->error_callback(memory->error_object, -3);
            }
        } else if (channel == 1) {
            chunk_len = chunk->len;
            position = memory->read_position;
            position = position - chunk_len;
            clamped_position = position > 0 ? position : 0;
            fzgx_value = &memory->read_position;
            *fzgx_value = clamped_position;
            position = memory->available + chunk->len;
            fzgx_value_ = &memory->available;
            *fzgx_value_ = memory->buffer_size < position ? memory->buffer_size : position;
            fzgx_live__ = memory->buffer;
            fzgx_live_ = fzgx_live__;
            data_position = (chunk->data) - fzgx_live_;
            if (clamped_position != data_position && memory->error_callback != 0) {
                memory->error_callback(memory->error_object, -3);
            }
        } else {
            (*( int * )(&chunk->len) = (0));
            chunk->data = 0;
            if (memory->error_callback != 0) {
                memory->error_callback(memory->error_object, -3);
            }
        }
        return fn_800576DC();
    }
    return (u32)memory;
}
#pragma opt_dead_assignments reset

typedef u32 (*fn_8005795C_Fn0)(u32, u32);
struct fn_8005795C_Arg2 {
    u8 pad_0[0x4];
    u32 unk_4;
};


u32 fn_8005795C(u32 arg0, u32 arg1, struct fn_8005795C_Arg2 *arg2) {
    u32 t1, t2;
    if ((s32)arg2->unk_4 > 0) {
    if (*(u32 *)(arg2) == 0) {
    return arg0;
    }
    fn_80057728();
    if (arg1 > 1) {
    *(u32 *)((u8 *)(u32)arg2 + 4) = 0;
    *(u32 *)((u8 *)(u32)arg2 + 0) = 0;
    if (*(u32 *)(arg0 + 28) != 0) {
    t1 = ((fn_8005795C_Fn0)*(u32 *)(arg0 + 28))(*(u32 *)(arg0 + 32), -3);
    }
    }
    t2 = fn_800576DC();
    return t2;
    }
    return arg0;
}

typedef u32 (*fn_800579F0_Fn0)(u32, u32);


void fn_800579F0(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    s32 var_r0;
    s32 (*temp_r12)(s32, s32);
    s32 temp_r3;

    fn_80057728();
    if (arg1 == 0) {
        (*(s32 *)((u8 *)(arg3) + 4)) = 0;
        (*(s32 *)((u8 *)(arg3))) = 0;
    } else if (arg1 == 1) {
        temp_r3 = *(s32 *)((u8 *)(arg0) + 12);
        var_r0 = arg2;
        if (temp_r3 < arg2) {
            var_r0 = temp_r3;
        }
        (*(s32 *)((u8 *)(arg3) + 4)) = var_r0;
        (*(s32 *)((u8 *)(arg3))) = ((*(s32 *)((u8 *)(arg0) + 20)) + (*(s32 *)((u8 *)(arg0) + 16)));
        (*(s32 *)((u8 *)(arg0) + 16)) = ((*(s32 *)((u8 *)(arg0) + 16)) + (*(s32 *)((u8 *)(arg3) + 4)));
        (*(s32 *)((u8 *)(arg0) + 12)) = ((*(s32 *)((u8 *)(arg0) + 12)) - (*(s32 *)((u8 *)(arg3) + 4)));
    } else {
        (*(s32 *)((u8 *)(arg3) + 4)) = 0;
        (*(s32 *)((u8 *)(arg3))) = 0;
        temp_r12 = (s32 (*)(s32, s32))(*(s32 (**)(s32, s32))((u8 *)(arg0) + 28));
        if (temp_r12 != NULL) {
            temp_r12(*(s32 *)((u8 *)(arg0) + 32), -3);
        }
    }
    fn_800576DC();
}

typedef void (*fn_80057AD8_Fn0)(u32, s32);

struct fn_80057AD8_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u8 pad_10[0xC];
    fn_80057AD8_Fn0 unk_1C;
    u32 unk_20;
};

s32 fn_80057AD8(struct fn_80057AD8_Arg0 *arg0, s32 arg1) {
    if (arg1 == 1) {
        return arg0->unk_C;
    } else if (arg1 == 0) {
        return 0;
    } else {
        if (arg0->unk_1C != 0) {
            arg0->unk_1C(arg0->unk_20, -3);
        }
        return 0;
    }
}

struct fn_80057B34_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[0x4];
    u32 unk_18;
};

void fn_80057B34(struct fn_80057B34_Arg0 *arg0) {
    arg0->unk_C = arg0->unk_18;
    arg0->unk_10 = 0;
}

struct fn_80057B48_Arg0 {
    u8 pad_0[0x1C];
    u32 unk_1C;
    u32 unk_20;
};

void fn_80057B48(struct fn_80057B48_Arg0 *arg0, u32 arg1, u32 arg2) {
    arg0->unk_1C = arg1;
    arg0->unk_20 = arg2;
}

struct fn_80057B54_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

u32 fn_80057B54(struct fn_80057B54_Arg0 *arg0) {
    return arg0->unk_8;
}

void fn_80057B5C(u32 arg0) {
    if (arg0 != 0) {
    memset((void *)arg0, 0, 36);
    *(u32 *)((u8 *)arg0 + 4) = 0;
    }
}

typedef struct {
    void *vtable;
    int active;
    void *type;
    void *link;
    int zero;
    void *arg0;
    void *arg1;
    void *callback;
    void *self;
} Fn80057B9CEntry;

extern u8 lbl_801322D0[48];
extern u8 lbl_800922E0[16];
extern void fn_80057D60(void);

Fn80057B9CEntry *fn_80057B9C(void *arg0, void *arg1) {
    Fn80057B9CEntry *entry;
    int count;

    for (count = 0; count < 32; count++) {
        if (((Fn80057B9CEntry *)lbl_8018AE1C)[count].active == 0) {
            break;
        }
    }
    if (count == 32) {
        return 0;
    }
    entry = &((Fn80057B9CEntry *)lbl_8018AE1C)[count];
    entry->active = 1;
    entry->vtable = lbl_801322D0;
    entry->arg0 = arg0;
    entry->arg1 = arg1;
    entry->type = lbl_800922E0;
    entry->callback = fn_80057D60;
    entry->self = entry;
    entry->link = entry->arg1;
    entry->zero = 0;
    return entry;
}

void fn_80057CC4(void) {
    if (--lbl_8018AE18[0] == 0) {
        memset(lbl_8018AE1C, 0, 0x480);
    }
}

u32 fn_80057D0C(u32 arg0, u32 arg1) {
    u32 v0;
    u32 v1;
    u32 t0;
    v0 = arg0;
    v1 = arg1;
    if ((s32)lbl_8018AE18[0] == 0) {
    v1 = 0;
    v0 = (u32)&lbl_8018AE1C;
    t0 = (u32)memset((void *)v0, v1, 1152);
    v0 = t0;
    }
    v1 = (u32)&lbl_8018AE18;
    v0 = *(u32 *)(v1);
    *(u32 *)((u8 *)v1 + 0) = (v0 + 1);
    return v0;
}

extern u32 fn_80058A20(u32);
extern u32 lbl_800922F0[];

void fn_80057D60(void) {
    fn_80058A20((u32)&lbl_800922F0);
}
