#include "types.h"


/* --- rel/movie_module/fn_12_3454C.c --- */
typedef struct MovieModule {
    u8 _pad[0x4c];
    void *movie;
} MovieModule;

extern int fn_12_3A36C(MovieModule *);
extern const char lbl_12_rodata_13C0[];
extern const char lbl_12_rodata_13EC[];
extern void MWSFSVM_Error(const char *, ...);
extern u8 lbl_12_bss_1B780[0x120];
extern int fn_8004F818(const char *, const char *, u8 *, u32 *, u32 *, u32 *);
extern void fn_80056E9C(void *, u8 *, u32, u32, u32);

void fn_12_3454C(MovieModule *self, const char *arg1, const char *arg2) {
    u32 value_10;
    u32 value_0c;
    u32 value_08;

    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(lbl_12_rodata_13C0);
    } else {
        void *movie = self->movie;

        if (fn_8004F818(arg1, arg2, lbl_12_bss_1B780,
                        &value_10, &value_0c, &value_08) == 0) {
            fn_80056E9C(movie, lbl_12_bss_1B780,
                        value_10, value_0c, value_08);
        } else {
            MWSFSVM_Error(lbl_12_rodata_13EC, arg1, arg2);
        }
    }
}

/* --- rel/movie_module/fn_12_34610.c --- */
extern void fn_80056BE0(void *movie);

void fn_12_34610(MovieModule *module) {
    fn_80056BE0(module->movie);
}
