#include "types.h"
#include "sofdec/mwsfd.h"
#include "sofdec/mwsst.h"

typedef struct Sig_fn_12_3A384_Fn12_3A384_Object {
    u8 _pad[0x44];
    u32 value;
} Sig_fn_12_3A384_Fn12_3A384_Object;

struct MwsPauseMessages {
    char unknown_000[0x84];
    char invalid_handle[40];
    char pause_failed[35];
    char padding_0cf;
    char on[3];
    char padding_0d3;
    char off[4];
};

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

typedef struct MovieEntryVTable {
    void *pad_00[3];
    void (*method_0C)(void *self);
} MovieEntryVTable;

typedef struct MovieEntry {
    MovieEntryVTable *vtable;
} MovieEntry;

typedef struct fn_12_393F0_MovieModule {
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
} fn_12_393F0_MovieModule;
extern void MWSFSVM_Error(const void *, ...);
extern f64 lbl_12_rodata_24C8;
extern void fn_12_3A384(Sig_fn_12_3A384_Fn12_3A384_Object *, u32, u32);
extern s32 fn_12_3A36C();
extern u8 lbl_12_rodata_24D8[128];
extern void *fn_12_39CA4(void *);
extern u8 lbl_12_rodata_2480[];
extern s32 fn_8004F818(s32 arg0, s32 arg1, char *arg2, u32 *arg3, u32 *arg4, u32 *arg5);
extern u32 fn_12_2D74C(u8 *base, int index, u32 *out);
extern u32 fn_12_38AD0(void);
extern s32 fn_12_38A0C(s32 arg);
extern int fn_12_2AF5C(SfdHandle *handle, int paused);
extern void fn_12_3A888(MwsPlayer *player);
extern char lbl_12_rodata_2558[39];
extern s32 fn_12_2B358(u32 arg0);
extern u8 lbl_12_rodata_2580[240];
extern void fn_12_3B540(void *);
extern void fn_12_34EB0(void *arg);
extern void fn_12_341E4(void *, s32);
extern void fn_80056CD0(void *);
extern u32 *fn_12_38DBC(void);
extern int MWSFCRE_ResetSfdHn(MwsPlayer *player);
extern void fn_12_3B2EC(void *);
extern void fn_12_33A14(void *);
extern void fn_12_353C4(void *);
extern s32 fn_12_35418(void *);
extern void fn_12_353FC(void *);
extern s32 fn_12_2AD88(u32 arg0);
extern void fn_12_3858C(void *);
extern MovieEntry *fn_80057B9C(void *arg0, void *arg1);

/* fzgx:begin fn_12_38DC8 */
/* --- rel/movie_module/fn_12_38D94.c --- */
/* --- rel/movie_module/fn_12_38D94.c --- */

/* --- rel/movie_module/fn_12_38DC8.c --- */

void fn_12_38DC8(Sig_fn_12_3A384_Fn12_3A384_Object *arg0) {
    s32 temp_r5;

    temp_r5 = *(s32 *)((u8 *)(arg0) + 308);
    fn_12_3A384((Sig_fn_12_3A384_Fn12_3A384_Object *)(arg0), (u32)((u32) (s32) ((*(f64 *)((u8 *)(&lbl_12_rodata_24C8) + 0)) * (f64) temp_r5)), (u32)((u32) temp_r5));
}
/* fzgx:end fn_12_38DC8 */

/* fzgx:begin fn_12_38E24 */
/* --- rel/movie_module/fn_12_38E24.c --- */
typedef struct MovieVTable MovieVTable;
typedef struct Movie Movie;

struct MovieVTable {
    u8 pad[0x3c];
    void (*update)(Movie *, void *);
};

struct Movie {
    MovieVTable *vtable;
    u8 pad_004[0x10c];
    void *resource;
    u8 pad_114[4];
    u32 loaded;
    u32 value0;
    u32 value1;
    u32 value2;
};


void fn_12_38E24(Movie *movie, void *arg1, void *arg2) {
    u32 value0;
    u32 value2;
    u32 value1;

    if (fn_12_3A36C(movie) == 0) {
        MWSFSVM_Error(lbl_12_rodata_24D8);
    } else {
        movie->vtable->update(movie, fn_12_39CA4(movie));
        if (fn_8004F818( (s32)(void *)(arg1), (s32)(void *)(arg2), (char *)(void *)(movie->resource), &value0, &value1, &value2) == 0) {
            movie->value0 = value0;
            movie->value1 = value1;
            movie->value2 = value2;
            movie->loaded = 1;
        } else {
            MWSFSVM_Error((((u8 *)&lbl_12_rodata_2480)));
        }
        movie->loaded = 1;
    }
}
/* fzgx:end fn_12_38E24 */

/* fzgx:begin mwSfdPause */










void mwSfdPause(MwsPlayer *player, int paused) {
    struct MwsPauseMessages *messages = &(*((struct MwsPauseMessages *)&lbl_12_rodata_2480));

    SfdHandle *sfd;
    int pause_status;
    if (fn_12_3A36C(player) == 0) {
        MWSFSVM_Error((messages->invalid_handle));
        return;
    }
    sfd = player->sfd;
    if (player->paused == 0 && paused == 0) {
        return;
    }
    if (((int)fn_12_38AD0()) == 1 && player->playback_mode == 1) {
        if (((int)fn_12_2D74C( (u8 *)(SfdHandle *)(sfd), 6, (u32 *)(int *)(&pause_status))) == 0) {
            if (pause_status == 1) {
                fn_12_3A888(player);
            }
        } else {
            fn_12_3A888(player);
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
    MWSST_Pause(&player->sound, paused);
    player->paused = paused;
}
/* fzgx:end mwSfdPause */

/* fzgx:begin fn_12_3901C */
/* --- rel/movie_module/fn_12_3901C.c --- */

typedef struct fn_12_3901C_MovieModule {
    u8 pad0[0x8];
    void *field8;
    u8 padc[0x34];
    void *field40;
    void *field44;
    void *field48;
    void *field4c;
    u8 pad50[0x24];
    u32 field74;
    u8 pad78[0x174];
    u8 field1ec;
} fn_12_3901C_MovieModule;

void fn_12_3901C(fn_12_3901C_MovieModule *module) {
    void *movie;

    if (fn_12_3A36C() == 0) {
        MWSFSVM_Error(lbl_12_rodata_2558);
    } else {
        movie = module->field40;
        if (movie != 0) {
            fn_12_3A888( (MwsPlayer *)(void *)(module));
            module->field8 = 0;
            if (fn_12_2B358( (u32)(void *)(movie)) != 0) {
                fn_12_38A0C(-0x134);
                MWSFSVM_Error(lbl_12_rodata_2580);
            }
            fn_12_3B540(&module->field1ec);
            movie = module->field44;
            if (movie != 0) {
                fn_12_34EB0(movie);
            }
        }
        fn_12_341E4(module, 0);
        module->field74 = 0;
        fn_80056CD0(module->field4c);
    }
}
/* fzgx:end fn_12_3901C */

/* fzgx:begin fn_12_390E4 */
/* --- rel/movie_module/fn_12_390E4.c --- */
typedef struct MovieModule_u1 {
    u8 pad0[0x8];
    void *field8;
    u8 padc[0x34];
    void *field40;
    void *field44;
    u8 pad48[0x1a4];
    u8 field1ec;
} MovieModule_u1;

void fn_12_390E4(MovieModule_u1 *module) {
    void *movie;

    movie = module->field40;
    if (movie != 0) {
        fn_12_3A888( (MwsPlayer *)(void *)(module));
        module->field8 = 0;
        if (fn_12_2B358( (u32)(void *)(movie)) != 0) {
            fn_12_38A0C(-0x134);
            MWSFSVM_Error(lbl_12_rodata_2580);
        }
        fn_12_3B540(&module->field1ec);
        movie = module->field44;
        if (movie != 0) {
            fn_12_34EB0(movie);
        }
    }
}
/* fzgx:end fn_12_390E4 */

/* fzgx:begin fn_12_3916C */
typedef struct fn_12_3916C_MovieModule {
    u8 pad00[0x8];
    s32 field08;
    s32 field0c;
    u8 pad10[0x30];
    void *sfd;
    void *stream;
    u8 pad48[0x28];
    u8 field70;
    u8 field71;
    s8 paused;
    u8 pad73[0x9];
    s32 field7c;
    s32 field80;
    s32 field84;
    u8 pad88[0xa0];
    s32 field128;
    u8 pad12c[0x10];
    s32 field13c;
    s32 field140;
    s32 field144;
    s32 field148;
    u8 pad14c[0xa0];
    MwsStHandle sound;
} fn_12_3916C_MovieModule;



void fn_12_3916C(fn_12_3916C_MovieModule *player, u32 arg1) {
    u8 *messages = (u8 *)&lbl_12_rodata_2480;
    void *sfd;
    s32 old;
    s32 pause_status;
    const char *state;

    if (fn_12_3A36C(player) == 0) {
        MWSFSVM_Error((const char *)(messages + 0x120));
        return;
    }
    sfd = player->sfd;
    if (sfd != 0) {
        fn_12_3A888( (MwsPlayer *)(void *)(player));
        player->field08 = 0;
        if (fn_12_2B358( (u32)(void *)(sfd)) != 0) {
            fn_12_38A0C(-0x134);
            MWSFSVM_Error((const char *)(messages + 0x100));
        }
        fn_12_3B540(&player->sound);
        if (player->stream != 0) {
            fn_12_34EB0(player->stream);
        }
    }
    player->field128 = arg1;
    player->field13c = 2;
    player->field140 = 0;
    player->field144 = 0;
    player->field148 = 0;
    fn_12_38DBC();
    if (player->sfd != 0) {
        if (MWSFCRE_ResetSfdHn( (MwsPlayer *)(void *)(player)) != 0) {
            MWSFSVM_Error((const char *)(messages + 0x14c));
            goto finish; /* shared exit: retail branches to the common finish block */
        }
        fn_12_3B2EC(player);
        fn_12_33A14(player);
        fn_12_353C4(player);
        if (fn_12_35418(player) != 0) {
            MWSFSVM_Error((const char *)(messages + 0x178));
            goto finish; /* shared exit: retail branches to the common finish block */
        }
        fn_12_353FC(player);
    }
    player->field7c = 0;
    player->field80 = 0;
    if (fn_12_2AD88((u32)player->sfd) != 0) {
        fn_12_38A0C(-0x137);
        MWSFSVM_Error((const char *)(messages + 0x1a4));
    }
    old = player->paused;
    if (fn_12_3A36C(player) == 0) {
        MWSFSVM_Error((const char *)(messages + 0x84));
    } else {
        sfd = player->sfd;
        if (player->paused != 0 || old != 0) {
            if (((s32)fn_12_38AD0()) == 1 && player->field0c == 1) {
                if (((s32)fn_12_2D74C((u8 *)sfd, 6, (u32 *)&pause_status)) == 0) {
                    if (pause_status == 1) {
                        fn_12_3A888( (MwsPlayer *)(void *)(player));
                    }
                } else {
                    fn_12_3A888( (MwsPlayer *)(void *)(player));
                }
            }
            if (fn_12_2AF5C((SfdHandle *)sfd, old) != 0) {
                const char *state;
                const char *msg;
                fn_12_38A0C(-0x136);
                msg = (const char *)(messages + 0xac);
                state = (const char *)(messages + 0xd4);
                if (old == 1) {
                    state = (const char *)(messages + 0xd0);
                }
                MWSFSVM_Error(msg, state);
            }
            MWSST_Pause(&player->sound, (s8)old);
            player->paused = (s8)old;
        }
    }
    MWSST_Pause(&player->sound, 1);
    MWSST_StartSj(&player->sound);
    player->field84 = 0;
    player->field71 = 0;
    player->field08 = 1;
finish:
    fn_12_3858C(player);
}
/* fzgx:end fn_12_3916C */

/* fzgx:begin fn_12_393F0 */

void fn_12_393F0(fn_12_393F0_MovieModule *module, void *arg0, void *arg1) {
    SfdHandle * fzgx_live;
    struct MovieModuleMessages *messages = &(*((struct MovieModuleMessages *)&lbl_12_rodata_2480));
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
        fn_12_3A888( (MwsPlayer *)(void *)(module));
        module->field_08 = 0;
        if (fn_12_2B358( (u32)(void *)(sfd)) != 0) {
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
    if (fn_12_2AD88( (u32)(void *)(module->sfd)) != 0) {
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
        if (((s32)fn_12_38AD0()) == 1 && module->field_0C == 1) {
            if (((int)fn_12_2D74C( (u8 *)(SfdHandle *)(sfd), 6, (u32 *)(int *)(&pause_status))) == 0) {
                if (pause_status == 1) {
                    fn_12_3A888( (MwsPlayer *)(void *)(module));
                }
            } else {
                fn_12_3A888( (MwsPlayer *)(void *)(module));
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
    fn_12_3858C( (void *)(fn_12_393F0_MovieModule *)(module));
}
/* fzgx:end fn_12_393F0 */
