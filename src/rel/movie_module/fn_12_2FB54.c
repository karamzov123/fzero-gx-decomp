#include "types.h"


/* --- rel/movie_module/fn_12_2F9E8.c --- */
/* --- rel/movie_module/fn_12_2F9E8.c --- */
typedef struct MovieModule {
    u8 pad_0000[0x1cd0];
    int movie_state;
} MovieModule;

extern int fn_12_2F1D0(MovieModule *, int);
extern int fn_12_21D30(MovieModule *, int);
extern void fn_12_2F1E0(MovieModule *, int, int);
extern int fn_12_2F1F0(MovieModule *, int);
extern int fn_12_21D50(MovieModule *, int);
extern void fn_12_2F200(MovieModule *, int, int);

int fn_12_2F9E8(MovieModule *module);

/* --- rel/movie_module/fn_12_2FA80.c --- */
// fn_12_2FA80: returns a constant.
int fn_12_2FA80(void);

/* --- rel/movie_module/fn_12_2FA88.c --- */
// fn_12_2FA88: returns a constant.
int fn_12_2FA88(void);

/* --- rel/movie_module/fn_12_2FA90.c --- */
/* --- rel/movie_module/fn_12_2FA90.c --- */
typedef struct MovieEntry {
    u32 unk00;
    void *unk04;
    void *unk08;
    u32 unk0c;
} MovieEntry;

typedef struct MovieModule_u1 {
    u8 unk0000[0x1cc8];
    MovieEntry *entries;
    u8 unk1ccc[4];
    int count;
} MovieModule_u1;

extern int fn_12_24990(MovieModule_u1 *);
extern void fn_12_24A88(void *, int);
extern void fn_12_2269C(MovieModule_u1 *, int, int, void *);

int fn_12_2FA90(MovieModule_u1 *module, int index, void *arg1, void *arg2);

/* --- rel/movie_module/fn_12_2FB54.c --- */
// fn_12_2FB54: returns a constant.
int fn_12_2FB54(void) {
    return 0;
}
