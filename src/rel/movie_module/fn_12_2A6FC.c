#include "types.h"


/* --- rel/movie_module/fn_12_2A6FC.c --- */
typedef struct MovieParams {
    u32 field0;
    u32 field1;
    u32 field2;
    u32 field3;
    u32 field4;
    u32 field5;
    u32 field6;
    s32 field7;
    u32 field8;
} MovieParams;

typedef struct MovieSize {
    u32 width;
    u32 height;
} MovieSize;


/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_12_bss_96A0;
u32 lbl_12_bss_96A0__fzgx_offset_4[16];
MovieSize lbl_12_bss_96A0__fzgx_offset_44;
MovieParams lbl_12_bss_96A0__fzgx_offset_4C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_12_bss_96A0;
    s = *(u8 *)&lbl_12_bss_96A0__fzgx_offset_4;
    s = *(u8 *)&lbl_12_bss_96A0__fzgx_offset_44;
    s = *(u8 *)&lbl_12_bss_96A0__fzgx_offset_4C;
}
#pragma section code_type ".text"

void fn_12_2A6FC(MovieParams *arg0, MovieSize *arg1, u32 *arg2) {
    MovieParams *params = &lbl_12_bss_96A0__fzgx_offset_4C;
    MovieSize *size = &lbl_12_bss_96A0__fzgx_offset_44;
    u32 *dst = lbl_12_bss_96A0__fzgx_offset_4;
    u32 *src = arg2;
    s32 i;

    lbl_12_bss_96A0__fzgx_offset_4C = *arg0;
    params->field4 = 0;
    params->field8 = 0;
    lbl_12_bss_96A0__fzgx_offset_44.width = (arg1->width + 31) & ~31;
    size->height = (arg1->height + 31) & ~31;

    for (i = 0; i < 16; i++) {
        if (i < arg0->field7) {
            dst[0] = (src[0] + 31) & ~31;
        } else {
            dst[0] = 0;
        }
        src++;
        dst++;
    }
}

/* --- rel/movie_module/fn_12_2A85C.c --- */
extern void fn_12_24970(void *arg0);
extern int fn_12_2D73C(void *arg0, int arg1);
extern int fn_12_2DEB0(void *arg0, int arg1, int arg2);
extern void fn_12_24950(void *arg0);

typedef struct MovieEntry {
    int type;
    unsigned char _pad[4];
    int value;
    int value2;
    unsigned char _pad2[0x68];
} MovieEntry;

typedef struct MovieList {
    unsigned char _pad0[0x7c];
    int flag;
    unsigned char _pad1[0xb4];
    int count;
    MovieEntry entries[1];
} MovieList;

typedef struct MovieModule {
    unsigned char _pad0[0x48];
    int state;
    unsigned char _pad1[0x1ae4];
    MovieList *movie_list;
} MovieModule;

int fn_12_2A85C(MovieModule *arg0) {
    unsigned char local[8];
    int matches;
    MovieEntry *entry;
    MovieEntry *previous;
    MovieEntry *current;
    int count;
    MovieList *list;
    int choose;

    fn_12_24970(local);
    list = arg0->movie_list;
    previous = 0;
    current = 0;
    matches = 0;
    count = list->count;
    entry = list->entries;
    for (; count > 0; count--) {
        if (entry->type == 2 || entry->type == 4) {
            matches++;
            if (current == 0) {
                choose = 1;
            } else if (current->value > entry->value) {
                choose = 1;
            } else {
                choose = 0;
            }
            if (choose) {
                previous = current;
                current = entry;
            } else {
                if (previous == 0) {
                    choose = 1;
                } else if (previous->value > entry->value) {
                    choose = 1;
                } else {
                    choose = 0;
                }
                if (choose) {
                    previous = entry;
                }
            }
        }
        entry++;
    }

    if (arg0->state != 4) {
        previous = 0;
    } else if (matches <= 1) {
        previous = 0;
    } else if (matches == 2 && list->flag == 0) {
        previous = 0;
    } else if (fn_12_2D73C(arg0, 15) == 0) {
        previous = (MovieEntry *)1;
    } else if (fn_12_2DEB0(arg0, previous->value, previous->value2) != 0) {
        previous = (MovieEntry *)1;
    } else {
        previous = 0;
    }
    fn_12_24950(local);
    return (int)previous;
}
