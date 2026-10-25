#include "types.h"

/* ADXM_SetupThrd, from the CC0 MK Deception decomp (adx_mgc.c) */

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

extern void fn_80058BFC(const char *build);
extern void fn_80058EE4(SVMCallbackFunction function, void *object);
extern void fn_80058ED4(SVMCallbackFunction function, void *object);
extern void fn_80059028(int server_id, SVMCallbackFunction function, void *object);
extern int OSCreateThread(ADXMThread *thread, void *(*func)(void *), void *param,
                          void *stack, u32 stackSize, s32 priority, u16 attr);
extern ADXMThread *fn_800102AC(void);
extern s32 OSResumeThread(ADXMThread *thread);

extern void fn_8004E7D4(void *argument);
extern void fn_8004E8A0(void *argument);
extern void fn_8004E8F8(void *argument);
extern void fn_8004E9A8(void *argument);
extern void fn_8004E9D8(void *object);
extern void fn_8004EA94(void *object);
extern void fn_8004EB00(void *object);

extern const char *const lbl_8009115C[];
extern ADXMThreadParams lbl_8012B918;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
void (*lbl_8017E980)(void);
int lbl_8017E984;
// Shared with the ADX server threads, which run asynchronously.
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
// Shared with the ADX server threads, which run asynchronously.
volatile int lbl_8017E984__fzgx_offset_C8C;
// Shared with the ADX server threads, which run asynchronously.
volatile int lbl_8017E984__fzgx_offset_C90;
// Shared with the ADX server threads, which run asynchronously.
volatile int lbl_8017E984__fzgx_offset_C94;
// Shared with the ADX server threads, which run asynchronously.
volatile int lbl_8017E984__fzgx_offset_C98;
// Shared with the ADX server threads, which run asynchronously.
volatile int lbl_8017E984__fzgx_offset_C9C;
// Shared with the ADX server threads, which run asynchronously.
volatile int lbl_8017E984__fzgx_offset_CA0;
// Shared with the ADX server threads, which run asynchronously.
volatile int lbl_8017E984__fzgx_offset_CA4;
// Shared with the ADX server threads, which run asynchronously.
volatile int lbl_8017E984__fzgx_offset_CA8;
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

void fn_8004E59C(ADXMThreadParams* params)
{
    const char* build = lbl_8009115C[0];

    if (adxm_init_level == 0) {
        fn_80058BFC(build);
        fn_80058EE4(fn_8004EB00, 0);
        fn_80058ED4(fn_8004EA94, 0);

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

        OSCreateThread(&adxm_safe_thread, (void* (*)(void*))fn_8004E9A8, 0,
                       adxm_stack_safe + sizeof(adxm_stack_safe),
                       sizeof(adxm_stack_safe),
                       adxm_save_tprm.safe_priority, 1);
        OSCreateThread(&adxm_vsync_thread, (void* (*)(void*))fn_8004E8F8, 0,
                       adxm_stack_vsync + sizeof(adxm_stack_vsync),
                       sizeof(adxm_stack_vsync),
                       adxm_save_tprm.vsync_priority, 1);
        OSCreateThread(&adxm_fs_thread, (void* (*)(void*))fn_8004E8A0, 0,
                       adxm_stack_fs + sizeof(adxm_stack_fs),
                       sizeof(adxm_stack_fs),
                       adxm_save_tprm.fs_priority, 1);
        OSCreateThread(&adxm_mwidle_thread, (void* (*)(void*))fn_8004E7D4, 0,
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

        OSResumeThread(&adxm_vsync_thread);
        OSResumeThread(&adxm_fs_thread);
        OSResumeThread(&adxm_mwidle_thread);
        fn_80059028(6, fn_8004E9D8, 0);
    }
    adxm_init_level++;
}
