#include "types.h"


/* --- rel/movie_module/fn_12_248E8.c --- */
typedef struct MovieModule {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u8 pad_10[0x80];
    u32 unk_90;
} MovieModule;

void fn_12_248E8(MovieModule *self) {
    self->unk_00 = 0;
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_0c = 0;
    self->unk_90 = 0;
}

/* --- rel/movie_module/fn_12_24904.c --- */
extern void fn_12_33178(void);

void fn_12_24904(void) {
    fn_12_33178();
}

/* --- rel/movie_module/fn_12_24924.c --- */
extern u8 lbl_12_bss_7A50[520];
extern void fn_12_331A8(s32, u8 *);

void fn_12_24924(void) {
    fn_12_331A8(0x20, lbl_12_bss_7A50);
}

/* --- rel/movie_module/fn_12_24950.c --- */
extern void fn_8004EBB4(void);

void fn_12_24950(void) {
    fn_8004EBB4();
}

/* --- rel/movie_module/fn_12_24970.c --- */
extern void fn_8004EBD4(void);

void fn_12_24970(void) {
    fn_8004EBD4();
}

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
