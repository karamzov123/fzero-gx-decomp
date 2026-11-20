#include "types.h"


/* --- rel/movie_module/fn_12_654C.c --- */
typedef struct MovieValues {
    s32 value_00;
    s32 value_04;
    s32 value_08;
    s32 value_0c;
    s32 value_10;
    s32 value_14;
    s32 value_18;
    s32 value_1c;
} MovieValues;

typedef struct MovieModule {
    u8 pad00[0x10];
    int field10;
    u8 field14[0x0c];
    MovieValues values;
    MovieValues slots[3];
    u8 fielda0[0x20];
} MovieModule;

extern int fn_12_6C78(MovieModule *);
extern int fn_12_6D5C(int, int);
extern int fn_12_670C(const void *);
extern void fn_12_62F8(void *, const void *, int *);
extern void fn_12_5FA0(void *, const void *, int *);
extern void fn_12_5810(void *, const void *, int *, int);

int fn_12_654C(MovieModule *movie, const u8 *data, int size, int *offset, int *flags) {
    int count;
    struct { int value; } processed;
    int kind;

    *offset = 0;
    *flags = 0;
    if (fn_12_6C78(movie)) {
        return fn_12_6D5C(0, 0xff020301);
    }

    while (size >= 4) {
        processed.value = 0;
        count = 0;
        kind = fn_12_670C(data);
        switch (kind) {
        case 0x10000:
            fn_12_62F8(&movie->field14, data, &count);
            processed.value = 1;
            break;
        case 0x20000:
            fn_12_5FA0(&movie->values, data, &count);
            processed.value = 1;
            break;
        case 0x40000:
            fn_12_5810(&movie->fielda0, data, &count, movie->field10);
            break;
        case 0x80000:
            break;
        }
        *flags |= kind;
        data += count;
        size -= count;
        *offset += count;
        if (!processed.value)
            break;
    }

    if (*flags & 0x20000) {
        int index;
        if (movie->values.value_08 != 0)
            index = 0;
        else if (movie->values.value_0c != 0)
            index = 1;
        else
            index = 2;
        movie->slots[index] = movie->values;
    }
    return 0;
}

/* --- rel/movie_module/fn_12_6704.c --- */
/* --- rel/movie_module/fn_12_6704.c --- */
// fn_12_6704: empty in retail (single blr).
void fn_12_6704(void) {
}

/* --- rel/movie_module/fn_12_6708.c --- */
// fn_12_6708: empty in retail (single blr).
void fn_12_6708(void) {
}
