#include "types.h"


/* --- dol/fn_8004784C.c --- */
extern struct fn_8004784C_lbl_8017B5A0 lbl_8017B5A0;

struct fn_8004784C_lbl_8017B5A0 {
    u32 unk_0;
};

u32 fn_8004784C(void);

/* --- dol/ADXSJE_ExecServer.c --- */
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

enum {
    ADXSJE_MAX_HANDLES = 8,
    ADXSJE_MAX_CHANNELS = 2,
    ADXSJE_MAX_FILTERS = 16,
    ADXSJE_MAX_BLOCK_SAMPLES = 32,
    ADXSJE_BLOCK_BYTES = 18
};

typedef struct AdxSjeIirFilter {
    union {
        unsigned char padding_extent[12];
        struct {
            s8 used;
        } view_used;
    } fields;
} AdxSjeIirFilter;

typedef struct AdxSjePredictorFilter {
    union {
        unsigned char padding_extent[144];
        struct {
            s8 used;
        } view_used;
    } fields;
} AdxSjePredictorFilter;

typedef struct AdxSjeHandle {
    union {
        unsigned char padding_extent[752];
        struct {
            s8 used;
        } view_used;
    } fields;
} AdxSjeHandle;

extern AdxSjeHandle lbl_8017BF78[ADXSJE_MAX_HANDLES];

void fn_800478C0(AdxSjeHandle *encoder);

void ADXSJE_ExecServer(void) {
    s32 index;
    for (index = 0; index < ADXSJE_MAX_HANDLES; index++) {
        if (lbl_8017BF78[index].fields.view_used.used == 1) {
            fn_800478C0(&lbl_8017BF78[index]);
        }
    }
}
