#include "types.h"


/* --- rel/movie_module/fn_12_34AB0.c --- */
struct MovieModule {
    u8 pad_00[0x08];
    int field_08;
    u8 pad_0c[0x40];
    void *field_4c;
    u8 pad_50[0x24];
    int field_74;
};

extern int fn_12_3A36C(struct MovieModule *, void *);
extern const u8 lbl_12_rodata_12E0[];
extern void MWSFSVM_Error(const u8 *, ...);
extern int fn_800570DC(void *, void *);

void fn_12_34AB0(struct MovieModule *self, void *arg);

/* --- rel/movie_module/fn_12_34B64.c --- */
extern void fn_80058FE4(int);

void fn_12_34B64(void) {
    fn_80058FE4(6);
}
