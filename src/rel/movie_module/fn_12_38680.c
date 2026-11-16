#include "types.h"

extern char lbl_12_rodata_2240[45];
extern void MWSFSVM_Error(const char *, ...);
extern u32 fn_12_38704(void);
extern u32 fn_12_35DB4(u32, u32);
extern s32 fn_12_35548(void *);

typedef struct MovieResource {
    u8 pad[8];
    u32 field_8;
    u32 field_c;
} MovieResource;

static inline u32 resource_offset(MovieResource *movie) {
    u32 offset;

    offset = fn_12_35DB4(movie->field_8, movie->field_c);
    if (fn_12_35548(movie) == 1) {
        offset += 0x20000;
    }
    return offset;
}

u32 fn_12_38680(MovieResource *movie) {
    u32 base;

    if (movie == 0) {
        MWSFSVM_Error(lbl_12_rodata_2240);
        return 0;
    }

    base = fn_12_38704();
    return base + resource_offset(movie);
}
