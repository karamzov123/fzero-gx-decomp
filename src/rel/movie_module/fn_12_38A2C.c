#include "types.h"


/* --- rel/movie_module/fn_12_38A2C.c --- */
typedef struct MoviePlayer {
    void *interface;
    s32 active;
} MoviePlayer;

typedef struct Movie {
    u8 pad[0x68];
    MoviePlayer player;
    u8 tail[0x228 - 0x70];
} Movie;

extern u32 lbl_12_bss_1B9D8;
extern u32 lbl_12_bss_1BAAC[1131];

extern void mwSfdDestroy(void *);
extern void fn_12_34DB4(void);
extern void fn_12_34CEC(void);
extern void fn_12_34D50(void);
extern void fn_12_35DBC(void);
extern void fn_80057378(void);
extern void fn_12_24B80(void);
extern void ADXT_Finish(void);
extern void fn_12_34FFC(void);
extern void fn_8005870C(void);
extern void fn_80057CC4(void);
extern void fn_80058630(void);
extern void fn_12_34E2C(void);

void fn_12_38A2C(void) {
    Movie *movie = (Movie *)lbl_12_bss_1BAAC;
    int i;

    if (--lbl_12_bss_1B9D8 == 0) {
        for (i = 0; i < 8; i++) {
            MoviePlayer *player = &movie[i].player;
            if (player->active == 1) {
                mwSfdDestroy(player);
            }
        }
        fn_12_34DB4();
        fn_12_34CEC();
        fn_12_34D50();
        fn_12_35DBC();
        fn_80057378();
        fn_12_24B80();
        ADXT_Finish();
        fn_12_34FFC();
        fn_8005870C();
        fn_80057CC4();
        fn_80058630();
        fn_12_34E2C();
    }
}

/* --- rel/movie_module/fn_12_38AD0.c --- */
u32 fn_12_38AD0(void) {
    return lbl_12_bss_1BAAC[15];
}

/* --- rel/movie_module/fn_12_38AE0.c --- */
u32 fn_12_38AE0(void) {
    return lbl_12_bss_1BAAC[14];
}
