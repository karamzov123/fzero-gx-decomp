/* Non-matching: best partial attempt (98.70% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */

#include "types.h"

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

extern u32 fn_80057728(void);
extern u32 fn_800576DC(void);

static inline void fn_8005782C_store(void *destination, int value) { *(int *)destination = value; }
#pragma opt_loop_invariants on
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
            fzgx_value = &(memory->read_position);
            *fzgx_value = clamped_position;
            position = memory->available + chunk->len;
            fzgx_value_ = &(memory->available);
            *fzgx_value_ = memory->buffer_size < position ? memory->buffer_size : position;
            fzgx_live__ = memory->buffer;
            fzgx_live_ = fzgx_live__;
            data_position = (chunk->data) - fzgx_live_;
            if (clamped_position != data_position && memory->error_callback != 0) {
                memory->error_callback(memory->error_object, -3);
            }
        } else {
            fn_8005782C_store(&(chunk->len), 0);
            chunk->data = 0;
            if (memory->error_callback != 0) {
                memory->error_callback(memory->error_object, -3);
            }
        }
        fn_800576DC();
    }
    return (u32)memory;
}
#pragma opt_dead_assignments reset

#pragma opt_loop_invariants reset

