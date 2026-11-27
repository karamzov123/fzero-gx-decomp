#include "types.h"

/* fzgx:begin fn_12_24950 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_24950.c --- */
extern void fn_8004EBB4(void);

void fn_12_24950(void) {
    fn_8004EBB4();
}
/* fzgx:end fn_12_24950 */

/* fzgx:begin fn_12_24970 noprologue */

/* --- rel/movie_module/fn_12_24970.c --- */
extern void fn_8004EBD4(void);

void fn_12_24970(void) {
    fn_8004EBD4();
}
/* fzgx:end fn_12_24970 */

/* fzgx:begin fn_12_24990 noprologue */

/* --- rel/movie_module/fn_12_24990.c --- */
extern u32 lbl_12_bss_7C5C;

s32 fn_12_24990(u32 arg0) {
    u32 v0;
    lbl_12_bss_7C5C = arg0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = -1;
    return v0;
    }
    v0 = (-((__cntlzw(*(u32 *)((u8 *)v0 + 72)) >> 5) & 0x1));
    return v0;
}
/* fzgx:end fn_12_24990 */

/* fzgx:begin fn_12_249BC noprologue */
#include "types.h"

extern u32 lbl_12_bss_7C64[137];
extern u32 lbl_12_bss_7C5C[2];

typedef void (*MovieCallback)(void *, u32);

typedef struct MovieObject {
    u8 pad48[0x48];
    s32 field48;
    u8 pad98c[0x940];
    void *field98c;
    void *field990;
} MovieObject;

s32 fn_12_249BC(MovieObject *obj, void *arg0, void *arg1) {
    s32 result;

    if (obj == 0) {
        lbl_12_bss_7C64[0x19c / 4] = (u32)arg0;
        lbl_12_bss_7C64[0x1a0 / 4] = (u32)arg1;
    } else {
        lbl_12_bss_7C5C[0] = (u32)obj;
        if (obj == 0) {
            result = -1;
        } else if (obj->field48 == 0) {
            result = -1;
        } else {
            result = 0;
        }
        if ((s32)result != 0) {
            if ((s32)lbl_12_bss_7C64[0x1a4 / 4] == 0) {
                lbl_12_bss_7C64[0x1a4 / 4] = 0xff000101;
            }
            if (lbl_12_bss_7C64[0x19c / 4] != 0) {
                ((MovieCallback)(u32)lbl_12_bss_7C64[0x19c / 4])(
                    (void *)lbl_12_bss_7C64[0x1a0 / 4], 0xff000101);
            }
            return 0xff000101;
        }
        obj->field98c = arg0;
        obj->field990 = arg1;
    }
    return 0;
}
/* fzgx:end fn_12_249BC */

/* fzgx:begin fn_12_24A88 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_24A88.c --- */
typedef void (*MovieCallback)(void *, s32);

typedef struct MovieObject {
    u8 pad_0000[0x48];
    s32 state;
    u8 pad_004c[0x940];
    MovieCallback callback;
    void *callback_context;
    s32 callback_data;
} MovieObject;

typedef struct MovieGlobal {
    u8 pad_0000[0x19c];
    MovieCallback callback;
    void *callback_context;
    s32 callback_data;
} MovieGlobal;

extern MovieGlobal lbl_12_bss_7C64;

s32 fn_12_24A88(MovieObject *object, s32 value) {
    if (value == 0) {
        return 0;
    }

    if (object == 0) {
        if (lbl_12_bss_7C64.callback_data == 0) {
            lbl_12_bss_7C64.callback_data = value;
        }
        if (value != 0 && lbl_12_bss_7C64.callback != 0) {
            lbl_12_bss_7C64.callback(lbl_12_bss_7C64.callback_context, value);
        }
    } else {
        if (object->callback_data == 0) {
            object->callback_data = value;
        }
        if (value != 0 && object->callback != 0) {
            object->callback(object->callback_context, value);
        }
        if (object->state > 0) {
            object->state = -object->state;
        }
    }

    return value;
}
/* fzgx:end fn_12_24A88 */

/* fzgx:begin fn_12_24B64 noprologue */

/* --- rel/movie_module/fn_12_24B64.c --- */
void fn_12_24B64(int *value) {
    value[0] = 0;
    value[1] = 0;
    value[2] = 0;
    value[3] = 0;
    value[4] = 0;
}
/* fzgx:end fn_12_24B64 */

/* fzgx:begin fn_12_24B80 noprologue */
#include "types.h"

extern u32 lbl_12_bss_7C64[137];
extern int fn_12_2B6B0(void *);
extern void fn_12_2F19C(void *);
extern void fn_12_22FB4(void *);
extern int fn_12_2F730(void *);
extern void fn_12_24904(void);
extern void fn_80058630(void);

int fn_12_24B80(void) {
    u32 *entry;
    int result;
    int final_result;
    int i;
    int rv;

    entry = &lbl_12_bss_7C64[129];
    result = 0;
    i = 0;
    for (; i < 8; i++) {
        if (*entry != 0) {
            result = fn_12_2B6B0((void *)*entry);
        }
        entry++;
    }
    fn_12_2F19C((void *)&lbl_12_bss_7C64[108]);
    fn_12_22FB4((void *)&lbl_12_bss_7C64[111]);
    final_result = fn_12_2F730((void *)&lbl_12_bss_7C64[112]);
    fn_12_24904();
    fn_80058630();
    if (final_result != 0) {
        return final_result;
    }
    rv = 0;
    if (result != 0) {
        rv = result;
    }
    return rv;
}
/* fzgx:end fn_12_24B80 */

/* fzgx:begin fn_12_24C48 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_24C48.c --- */
/* SFD_Init (sfd_lib.c, CRI Sofdec) */

typedef struct SfdHandle SfdHandle;

typedef struct SfdTransportRegistry {
    unsigned int entries[15];
} SfdTransportRegistry;

typedef struct SfdLibraryConfig {
    const SfdTransportRegistry *transport_registry;
    int timer_source;
} SfdLibraryConfig;

typedef void (*SfdErrorCallback)(int object, int error);

typedef struct SfdErrorInfo {
    SfdErrorCallback callback;
    int callback_object;
    int first_error;
    int field_0C;
    int field_10;
} SfdErrorInfo;

typedef struct SfdTimerLibraryWork {
    int fields[3];
} SfdTimerLibraryWork;

typedef struct SfdLibraryWork {
    int default_conditions[100];
    const SfdTransportRegistry *transport_registry_source;
    int timer_source;
    int field_0198;
    SfdErrorInfo error_info;
    SfdTimerLibraryWork timer_work;
    int buffer_work;
    SfdTransportRegistry transport_registry;
    int reset_in_progress;
    int retained_adxt;
    SfdHandle *handles[8];
} SfdLibraryWork;

extern void fn_80058680(void);
extern void fn_12_24924(void);
extern void fn_12_2F1A0(SfdTimerLibraryWork *work, int source);
extern void fn_12_22FB8(int *work);
extern int fn_12_2F7AC(SfdTransportRegistry *registry, const SfdTransportRegistry *source);
extern void fn_12_2CD8C(void);
extern void fn_12_33428(void *destination, unsigned int value, unsigned int count);
extern void *fn_12_57F0(void *destination, const void *source, unsigned long size);
extern const char lbl_12_rodata_B00[];
extern const int lbl_12_rodata_C78[100];

static int lbl_12_bss_7C58;                       /* sflib_sizeof_sfdhn */
static int lbl_12_bss_7C5C;
static const char *lbl_12_bss_7C5C__fzgx_offset_4; /* cri_verstr_ptr */
static SfdLibraryWork lbl_12_bss_7C64;            /* SFLIB_libwork */

#pragma section code_type ".fzgxpool"
static void sfd_lib_layout(void) {
    const void *volatile object; /* fzgx-allow: S2 bss object first-access order */
    object = &lbl_12_bss_7C58;
    object = &lbl_12_bss_7C5C;
    object = &lbl_12_bss_7C5C__fzgx_offset_4;
    object = &lbl_12_bss_7C64;
}
#pragma section code_type ".text"

static inline void SFLIB_InitErrInf(SfdErrorInfo *info) {
    info->callback = 0;
    info->callback_object = 0;
    info->first_error = 0;
    info->field_0C = 0;
    info->field_10 = 0;
}

static inline int sflib_CheckResult(int result) {
    int error = 0;
    if (result != 0) {
        error = result;
    }
    return error;
}

int fn_12_24C48(SfdLibraryConfig *config) {
    int timer_source;
    const SfdTransportRegistry *registry_source;
    int error;
    int i;

    lbl_12_bss_7C58 = 0x29D8; /* sizeof(SfdHandle) */
    lbl_12_bss_7C5C__fzgx_offset_4 = lbl_12_rodata_B00;
    fn_80058680();
    fn_12_33428(&lbl_12_bss_7C64, 0, sizeof(lbl_12_bss_7C64) / sizeof(unsigned int));
    fn_12_57F0(lbl_12_bss_7C64.default_conditions, lbl_12_rodata_C78,
               sizeof(lbl_12_bss_7C64.default_conditions));
    timer_source = config->timer_source;
    registry_source = config->transport_registry;
    lbl_12_bss_7C64.transport_registry_source = registry_source;
    lbl_12_bss_7C64.timer_source = timer_source;
    lbl_12_bss_7C64.field_0198 = 0;
    SFLIB_InitErrInf(&lbl_12_bss_7C64.error_info);
    fn_12_2F1A0(&lbl_12_bss_7C64.timer_work, timer_source);
    fn_12_22FB8(&lbl_12_bss_7C64.buffer_work);
    lbl_12_bss_7C64.reset_in_progress = 0;
    lbl_12_bss_7C64.retained_adxt = 0;
    for (i = 0; i < 8; i++) {
        lbl_12_bss_7C64.handles[i] = 0;
    }
    error = sflib_CheckResult(fn_12_2F7AC(&lbl_12_bss_7C64.transport_registry, config->transport_registry));
    if (error != 0) {
        return error;
    }
    fn_12_2CD8C();
    fn_12_24924();
    return 0;
}
/* fzgx:end fn_12_24C48 */

/* fzgx:begin fn_12_24D68 noprologue */

/* --- rel/movie_module/fn_12_24D68.c --- */
/* --- rel/movie_module/fn_12_24D68.c --- */
int fn_12_24D68(int unused, int value) {
    return value == 0x29d8;
}

/* --- rel/movie_module/fn_12_24D78.c --- */
// fn_12_24D78: returns a constant.
int fn_12_24D78(void);

/* --- rel/movie_module/fn_12_24D80.c --- */
extern void fn_12_24A88(int arg0, int arg1);

void fn_12_24D80(int arg0);
/* fzgx:end fn_12_24D68 */
