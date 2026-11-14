#include "types.h"
#include "sofdec/mwsfd.h"
#include "sofdec/mwsst.h"

struct MovieModuleMessages {
    u8 unknown_000[0x84];
    char invalid_handle[0x28];
    char pause_failed[0x24];
    char on[3];
    char padding_0d3;
    char off[4];
    u8 unknown_0d8[0x28];
    char finalize_failed[0x4C];
    char start_failed[0x2C];
    char prepare_failed[0x2C];
    char state_failed[0x20];
    char no_player[0x40];
};
extern struct MovieModuleMessages lbl_12_rodata_2480;
typedef struct MovieEntryVTable {
    void *pad_00[3];
    void (*method_0C)(void *self);
} MovieEntryVTable;
typedef struct MovieEntry {
    MovieEntryVTable *vtable;
} MovieEntry;
typedef struct MovieModule {
    u8 pad_00[0x08];
    s32 field_08;
    s32 field_0C;
    u8 pad_10[0x30];
    SfdHandle *sfd;
    void *field_44;
    u8 pad_48[0x29];
    u8 field_71;
    s8 paused;
    u8 pad_73[0x09];
    s32 field_7C;
    s32 field_80;
    s32 field_84;
    u8 pad_88[0xA0];
    MovieEntry *field_128;
    u8 pad_12C[0x20];
    MovieEntry *field_14C;
    void *field_150;
    void *field_154;
    u8 pad_158[0x94];
    MwsStHandle sound;
} MovieModule;
extern int fn_12_3A36C(void *player);
extern void MWSFSVM_Error(const char *message, ...);
extern void fn_12_3A888(void *player);
extern s32 fn_12_2B358(void *movie);
extern void fn_12_38A0C(s32 error);
extern void fn_12_3B540(void *sound);
extern void fn_12_34EB0(void *movie);
extern MovieEntry *fn_80057B9C(void *arg0, void *arg1);
extern void fn_12_38DBC(void);
extern void fn_12_3B2EC(void *player);
extern void fn_12_33A14(void *player);
extern void fn_12_353C4(void *player);
extern s32 fn_12_35418(void *player);
extern void fn_12_353FC(void *player);
extern s32 fn_12_2AD88(void *sfd);
extern s32 fn_12_38AD0(void);
extern int fn_12_2D74C(SfdHandle *handle, int condition, int *value);
extern int fn_12_2AF5C(SfdHandle *handle, int paused);
extern void fn_12_3858C(MovieModule *module);

void fn_12_393F0(MovieModule *module, void *arg0, void *arg1) {
    SfdHandle * fzgx_live;
    struct MovieModuleMessages *messages = &lbl_12_rodata_2480;
    int paused;
    int pause_status;
    SfdHandle *sfd;
    if (fn_12_3A36C(module) == 0) {
        MWSFSVM_Error(messages->no_player);
        return;
    }
    fzgx_live = module->sfd;
    sfd = fzgx_live;
    if (sfd != 0) {
        fn_12_3A888(module);
        module->field_08 = 0;
        if (fn_12_2B358(sfd) != 0) {
            fn_12_38A0C(-0x134);
            MWSFSVM_Error(messages->finalize_failed);
        }
        fn_12_3B540(&module->sound);
        if (module->field_44 != 0) {
            fn_12_34EB0(module->field_44);
        }
    }
    module->field_14C->vtable->method_0C(module->field_14C);
    module->field_14C = fn_80057B9C(arg0, arg1);
    module->field_128 = module->field_14C;
    module->field_150 = arg0;
    module->field_154 = arg1;
    fn_12_38DBC();
    if (module->sfd != 0) {
        if (MWSFCRE_ResetSfdHn((MwsPlayer *)module) != 0) {
            MWSFSVM_Error(messages->start_failed);
            goto finish; /* Keep the verified branch to finish. */
        }
        fn_12_3B2EC(module);
        fn_12_33A14(module);
        fn_12_353C4(module);
        if (fn_12_35418(module) != 0) {
            MWSFSVM_Error(messages->prepare_failed);
            goto finish; /* Keep the verified branch to finish. */
        }
        fn_12_353FC(module);
    }
    module->field_7C = 0;
    module->field_80 = 0;
    if (fn_12_2AD88(module->sfd) != 0) {
        fn_12_38A0C(-0x137);
        MWSFSVM_Error(messages->state_failed);
    }
    paused = module->paused;
    if (fn_12_3A36C(module) == 0) {
        MWSFSVM_Error(messages->invalid_handle);
    } else {
        fzgx_live = module->sfd;
        sfd = fzgx_live;
        if (module->paused == 0 && paused == 0) goto start_sound; /* Keep the verified branch to start_sound. */
        if (fn_12_38AD0() == 1 && module->field_0C == 1) {
            if (fn_12_2D74C(sfd, 6, &pause_status) == 0) {
                if (pause_status == 1) {
                    fn_12_3A888(module);
                }
            } else {
                fn_12_3A888(module);
            }
        }
        if (fn_12_2AF5C(sfd, paused) != 0) {
            fn_12_38A0C(-0x136);
            {
                const char *format = messages->pause_failed;
                const char *state = messages->off;
                if (paused == 1) {
                    state = messages->on;
                }
                MWSFSVM_Error(format, state);
            }
        }
        MWSST_Pause(&module->sound, paused);
        module->paused = paused;
    }
start_sound:
    MWSST_Pause(&module->sound, 1);
    MWSST_StartSj(&module->sound);
    module->field_84 = 0;
    module->field_71 = 0;
    module->field_08 = 1;
finish:
    fn_12_3858C(module);
}

