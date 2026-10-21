#include "types.h"

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
