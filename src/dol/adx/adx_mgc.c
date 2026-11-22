#include "types.h"
#include "dolphin/os/OSThread.h"

typedef struct ADXMThreadParams {
    s32 lock_priority;
    s32 safe_priority;
    s32 vsync_priority;
    s32 fs_priority;
    s32 field_10;
    s32 mwidle_priority;
} ADXMThreadParams;

typedef struct ADXMThread {
    u8 data[0x318];
} ADXMThread;

typedef void (*SVMCallbackFunction)(void *object);
typedef void (*AdxmIdleCallback)(u32);

typedef struct AdxmState {
    void (*err_func)(void);      /* 0x000 */
    s32 init_level;              /* 0x004 */
    volatile s32 lock_count;     /* 0x008 */
    s32 unk_C;                   /* 0x00C */
    s32 count_10;                /* 0x010 */
    s32 count_14;                /* 0x014 */
    s32 count_18;                /* 0x018 */
    s32 unk_1C;                  /* 0x01C */
    u32 pad_20;                  /* 0x020 */
    OSThread thread_28;          /* 0x028 (size 0x318 -> 0x340) */
    OSThread thread_340;         /* 0x340 (size 0x318 -> 0x658) */
    OSThread thread_658;         /* 0x658 (size 0x318 -> 0x970) */
    OSThread thread_970;         /* 0x970 (size 0x318 -> 0xC88) */
    u32 unk_C88;                 /* 0xC88 */
    u32 unk_C8C;                 /* 0xC8C */
    s32 field_C90;               /* 0xC90 */
    s32 field_C94;               /* 0xC94 */
    s32 field_C98;               /* 0xC98 */
    s32 field_C9C;               /* 0xC9C */
    s32 field_CA0;               /* 0xCA0 */
    s32 field_CA4;               /* 0xCA4 */
    s32 field_CA8;               /* 0xCA8 */
    s32 field_CAC;               /* 0xCAC */
} AdxmState;

typedef struct AdxmCallbackPair {
    AdxmIdleCallback callback_0;
    u32 unk_4;
} AdxmCallbackPair;

typedef struct AdxmVsyncCounter {
    u32 unk_0;
} AdxmVsyncCounter;

extern void fn_80058B54(void);
extern void fn_80058BFC(const char *build);
extern void fn_80058EE4(SVMCallbackFunction function, void *object);
extern void fn_80058ED4(SVMCallbackFunction function, void *object);
extern void fn_80059028(int server_id, SVMCallbackFunction function, void *object);
extern ADXMThread *fn_800102AC(void);
extern u32 fn_80011358(void);
extern u32 fn_80058EF4(void);
extern s32 fn_80058C94(void);
extern void fn_80058DB4(void);
extern void fn_80058E44(void);
extern void fn_800595A4(const char *message);
extern void VIWaitForRetrace(void);
extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern void OSDisableScheduler(void);
extern void OSEnableScheduler(void);
extern u32 fn_80059AB4(void);
extern u32 fn_80059B44(void);
extern u32 fn_80058D24(void);

extern const char *const lbl_8009115C[];
extern char lbl_80091160[49];
extern ADXMThreadParams lbl_8012B918;
extern AdxmCallbackPair lbl_8012B930;
extern AdxmVsyncCounter lbl_80178CB8;

void fn_8004E7D4(void);
void fn_8004E8A0(void);
void fn_8004E8F8(void);
void fn_8004E9A8(void);
void fn_8004E9D8(void);
void fn_8004EA94(void);
void fn_8004EB00(void);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
void (*lbl_8017E980)(void);
int lbl_8017E984;
/* Shared with the ADX server threads, which run asynchronously. */
volatile int lbl_8017E984__fzgx_offset_4;
int lbl_8017E984__fzgx_offset_8;
int lbl_8017E984__fzgx_offset_C;
int lbl_8017E984__fzgx_offset_10;
int lbl_8017E984__fzgx_offset_14;
int lbl_8017E984__fzgx_offset_18;
int lbl_8017E984__fzgx_offset_1C;
ADXMThread *lbl_8017E984__fzgx_offset_20;
ADXMThread lbl_8017E984__fzgx_offset_24;
ADXMThread lbl_8017E984__fzgx_offset_33C;
ADXMThread lbl_8017E984__fzgx_offset_654;
ADXMThread lbl_8017E984__fzgx_offset_96C;
int lbl_8017E984__fzgx_offset_C84;
int lbl_8017E984__fzgx_offset_C88;
/* Shared with the ADX server threads, which run asynchronously. */
volatile int lbl_8017E984__fzgx_offset_C8C; /* shared with async ADX server threads */
volatile int lbl_8017E984__fzgx_offset_C90; /* shared with async ADX server threads */
volatile int lbl_8017E984__fzgx_offset_C94; /* shared with async ADX server threads */
volatile int lbl_8017E984__fzgx_offset_C98; /* shared with async ADX server threads */
volatile int lbl_8017E984__fzgx_offset_C9C; /* shared with async ADX server threads */
volatile int lbl_8017E984__fzgx_offset_CA0; /* shared with async ADX server threads */
volatile int lbl_8017E984__fzgx_offset_CA4; /* shared with async ADX server threads */
volatile int lbl_8017E984__fzgx_offset_CA8; /* shared with async ADX server threads */
unsigned char lbl_8017E984__fzgx_offset_CAC[0x2000];
unsigned char lbl_8017E984__fzgx_offset_2CAC[0x2000];
unsigned char lbl_8017E984__fzgx_offset_4CAC[0x2000];
unsigned char lbl_8017E984__fzgx_offset_6CAC[0x1000];

#define adxm_init_level lbl_8017E984
#define adxm_main_thread lbl_8017E984__fzgx_offset_20
#define adxm_mwidle_thread lbl_8017E984__fzgx_offset_24
#define adxm_vsync_thread lbl_8017E984__fzgx_offset_33C
#define adxm_fs_thread lbl_8017E984__fzgx_offset_654
#define adxm_safe_thread lbl_8017E984__fzgx_offset_96C
#define adxm_set_prio lbl_8017E984__fzgx_offset_C88
#define adxm_fs_end lbl_8017E984__fzgx_offset_C8C
#define adxm_fs_act lbl_8017E984__fzgx_offset_C90
#define adxm_vsync_end lbl_8017E984__fzgx_offset_C94
#define adxm_vsync_act lbl_8017E984__fzgx_offset_C98
#define adxm_mwidle_end lbl_8017E984__fzgx_offset_C9C
#define adxm_mwidle_act lbl_8017E984__fzgx_offset_CA0
#define adxm_safe_end lbl_8017E984__fzgx_offset_CA4
#define adxm_safe_act lbl_8017E984__fzgx_offset_CA8
#define adxm_stack_mwidle lbl_8017E984__fzgx_offset_CAC
#define adxm_stack_fs lbl_8017E984__fzgx_offset_2CAC
#define adxm_stack_vsync lbl_8017E984__fzgx_offset_4CAC
#define adxm_stack_safe lbl_8017E984__fzgx_offset_6CAC
#define adxm_save_tprm lbl_8012B918

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s; /* fzgx-allow: S2 BSS primer ordering */
    s = *(u8 *)&lbl_8017E980;
    s = *(u8 *)&lbl_8017E984;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_4;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_8;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_C;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_10;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_14;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_18;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_1C;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_20;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_24;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_33C;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_654;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_96C;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_C84;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_C88;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_C8C;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_C90;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_C94;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_C98;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_C9C;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_CA0;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_CA4;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_CA8;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_CAC;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_2CAC;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_4CAC;
    s = *(u8 *)&lbl_8017E984__fzgx_offset_6CAC;
}
#pragma section code_type ".text"

void fn_8004E4DC(void) {
    AdxmState *state = (AdxmState *)&lbl_8017E980;

    if (--state->init_level == 0) {
        state->field_CA4 = 0;
        OSSetThreadPriority(&state->thread_28, 1);
        while (state->field_CA0 == 0) {
            OSResumeThread(&state->thread_28);
        }
        OSCancelThread(&state->thread_340);
        OSCancelThread(&state->thread_658);
        state->field_CAC = 0;
        OSResumeThread(&state->thread_970);
        while (state->field_CA8 == 0) {
            OSResumeThread(&state->thread_970);
        }
        fn_80058B54();
    }
}

u32 fn_8004E580(void) {
    return (u32)(((-adxm_init_level) | adxm_init_level)) >> 31;
}

void fn_8004E59C(ADXMThreadParams *params) {
    const char *build = lbl_8009115C[0];

    if (adxm_init_level == 0) {
        fn_80058BFC(build);
        fn_80058EE4((SVMCallbackFunction)fn_8004EB00, 0);
        fn_80058ED4((SVMCallbackFunction)fn_8004EA94, 0);

        if (params == 0) {
            adxm_save_tprm.field_10 = 16;
            adxm_save_tprm.lock_priority = 1;
            adxm_save_tprm.safe_priority = 8;
            adxm_save_tprm.vsync_priority = 12;
            adxm_save_tprm.fs_priority = 14;
            adxm_save_tprm.mwidle_priority = 24;
        } else {
            adxm_save_tprm = *params;
        }

        OSCreateThread((OSThread *)&adxm_safe_thread, (void *(*)(void *))fn_8004E9A8, 0,
                       adxm_stack_safe + sizeof(adxm_stack_safe),
                       sizeof(adxm_stack_safe),
                       adxm_save_tprm.safe_priority, 1);
        OSCreateThread((OSThread *)&adxm_vsync_thread, (void *(*)(void *))fn_8004E8F8, 0,
                       adxm_stack_vsync + sizeof(adxm_stack_vsync),
                       sizeof(adxm_stack_vsync),
                       adxm_save_tprm.vsync_priority, 1);
        OSCreateThread((OSThread *)&adxm_fs_thread, (void *(*)(void *))fn_8004E8A0, 0,
                       adxm_stack_fs + sizeof(adxm_stack_fs),
                       sizeof(adxm_stack_fs),
                       adxm_save_tprm.fs_priority, 1);
        OSCreateThread((OSThread *)&adxm_mwidle_thread, (void *(*)(void *))fn_8004E7D4, 0,
                       adxm_stack_mwidle + sizeof(adxm_stack_mwidle),
                       sizeof(adxm_stack_mwidle),
                       adxm_save_tprm.mwidle_priority, 1);

        adxm_main_thread = fn_800102AC();
        adxm_fs_act = 1;
        adxm_mwidle_act = 1;
        adxm_vsync_act = 1;
        adxm_safe_act = 1;
        adxm_fs_end = 0;
        adxm_mwidle_end = 0;
        adxm_vsync_end = 0;
        adxm_safe_end = 0;
        adxm_set_prio = 0;

        OSResumeThread((OSThread *)&adxm_vsync_thread);
        OSResumeThread((OSThread *)&adxm_fs_thread);
        OSResumeThread((OSThread *)&adxm_mwidle_thread);
        fn_80059028(6, (SVMCallbackFunction)fn_8004E9D8, 0);
    }
    adxm_init_level++;
}

void fn_8004E7B4(void) {
    fn_80058EF4();
}

void fn_8004E7D4(void) {
    while (adxm_mwidle_act == 1) {
        lbl_8017E984__fzgx_offset_18 += 1;
        if (fn_80058C94() == 0 || lbl_8017E984__fzgx_offset_8 == 1) {
            if (lbl_8017E984__fzgx_offset_8 == 1) {
                lbl_8017E984__fzgx_offset_8 = 0;
                OSSetThreadPriority((OSThread *)&adxm_mwidle_thread, adxm_save_tprm.mwidle_priority);
            }
            if (lbl_8012B930.callback_0 != 0) {
                lbl_8012B930.callback_0(lbl_8012B930.unk_4);
            }
            OSSuspendThread((OSThread *)&adxm_mwidle_thread);
        }
    }
    adxm_mwidle_end = 1;
}

void fn_8004E8A0(void) {
    AdxmState *state = (AdxmState *)&lbl_8017E980;

    while (state->field_C94 == 1) {
        VIWaitForRetrace();
        state->count_18 += 1;
        fn_80058DB4();
    }
    state->field_C90 = 1;
}

void fn_8004E8F8(void) {
    while (adxm_vsync_act == 1) {
        VIWaitForRetrace();
        lbl_8017E984__fzgx_offset_10 += 1;
        lbl_80178CB8.unk_0 += 1;
        fn_80058E44();
        if (adxm_mwidle_end == 0) {
            OSResumeThread((OSThread *)&adxm_mwidle_thread);
            if (lbl_8012B930.callback_0 != 0) {
                lbl_8012B930.callback_0(lbl_8012B930.unk_4);
            }
        }
    }
    adxm_vsync_end = 1;
}

void fn_8004E9A8(void) {
    AdxmState *state = (AdxmState *)&lbl_8017E980;

    while (state->field_CAC == 1) {
        state->count_10 += 1;
    }
    state->field_CA8 = 1;
}

void fn_8004E9D8(void) {
    s32 i;
    s32 limit;

    if (adxm_mwidle_end != 1) {
        lbl_8017E984__fzgx_offset_8 = 1;
        OSSetThreadPriority((OSThread *)&adxm_mwidle_thread, adxm_save_tprm.lock_priority);

        i = 0;
        limit = (s32)0x0bebc200;
        while (i < limit) {
            OSResumeThread((OSThread *)&adxm_mwidle_thread);
            if (lbl_8017E984__fzgx_offset_8 == 0) {
                break;
            }
            i += 1;
        }
        if (i == limit) {
            fn_800595A4(lbl_80091160);
        }
        OSSetThreadPriority((OSThread *)&adxm_mwidle_thread, adxm_save_tprm.mwidle_priority);
    }
}

void fn_8004EA94(void) {
    OSThread *value;

    lbl_8017E984__fzgx_offset_4--;
    if (lbl_8017E984__fzgx_offset_4 == 0) {
        value = (OSThread *)fn_800102AC();
        OSSuspendThread((OSThread *)&adxm_safe_thread);
        OSSetThreadPriority(value, lbl_8017E984__fzgx_offset_C84);
    }
}

void fn_8004EB00(void) {
    u32 interrupts;
    OSThread *value;
    u32 result;

    if (lbl_8017E984__fzgx_offset_4 == 0) {
        interrupts = OSDisableInterrupts();
        OSDisableScheduler();
        adxm_set_prio = 1;
        value = (OSThread *)fn_800102AC();
        result = fn_80011358();
        OSSetThreadPriority(value, adxm_save_tprm.lock_priority);
        lbl_8017E984__fzgx_offset_C84 = result;
        adxm_set_prio = 0;
        OSEnableScheduler();
        OSRestoreInterrupts(interrupts);
        OSResumeThread((OSThread *)&adxm_safe_thread);
    }
    lbl_8017E984__fzgx_offset_4++;
}

void fn_8004EBB4(void) {
    fn_80059AB4();
}

void fn_8004EBD4(void) {
    fn_80059B44();
}

void fn_8004EBF4(void) {
    fn_80058D24();
}

void fn_8004EC14(void) {
    VIWaitForRetrace();
}
