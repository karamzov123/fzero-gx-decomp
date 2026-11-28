#include "types.h"

struct fn_12_330E0_lbl_12_bss_1B75C {
    u8 pad_0[0x4];
    u32 unk_4;
};
extern s32 memcmp(u32 arg0, u32 arg1, u32 arg2);
extern char lbl_12_rodata_10DC[5];
extern char lbl_12_rodata_10E4[25];
extern u8 *strstr(u8 *str, const u8 *needle);
extern void *memcpy(void *, const void *, u32);
extern void *memset(void *, int, u32);
extern u32 lbl_12_bss_1B75C[5];
extern s32 lbl_12_bss_1B758;
extern const char lbl_12_rodata_10A8[49];

/* fzgx:begin fn_12_32EAC */
/* --- rel/movie_module/fn_12_32EAC.c --- */
struct fn_12_32EAC_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};
struct fn_12_32EAC_Arg1 {
    u32 unk_0;
};


static inline s32 digit(s32 c) {
    s32 result = 0;
    if (c >= 48 && c <= 57) result = 1;
    return result;
}
static inline u32 number(s8 **p) {
    s8 *v6 = *p;
    s32 c;
    u32 v0 = 0;
    for (;;) {
        c = *v6;
        if (c == 46 || c == 32 || c == 0) break;
        if (!digit(c)) break;
        v0 = c + v0 * 10;
        v0 -= 48;
        ++v6;
    }
    *p = v6;
    return v0;
}
static inline s32 parse(u8 *buf, u32 *major, u32 *minor) {
    s8 *v4 = (s8 *)strstr(buf, (const u8 *)lbl_12_rodata_10DC);
    if (!v4) return 0;
    v4 += 4;
    *major = number(&v4);
    ++v4;
    *minor = number(&v4);
    return 1;
}
static inline s32 copy(struct fn_12_32EAC_Arg0 *arg0, void *buf) {
    u32 v1 = arg0->unk_4 + 96;
    s32 ok;
    switch ((s32)arg0->unk_0) {
    case -1: case 0: case 1: ok = 0; break;
    default: ok = 1; break;
    }
    if (!ok) return 0;
    memset(buf, 0, 33);
    memcpy(buf, (void *)v1, 32);
    return 1;
}
static inline s32 version(struct fn_12_32EAC_Arg0 *arg0, u32 *major, u32 *minor) {
    struct { u8 a[33]; } loc_8;
    if (!copy(arg0, &loc_8)) return 0;
    if (!parse((u8 *)&loc_8, major, minor)) return 0;
    return 1;
}
s32 fn_12_32EAC(struct fn_12_32EAC_Arg0 *arg0, struct fn_12_32EAC_Arg1 *arg1) {
    u32 v0;
    u32 v2;
    u32 v3;
    arg1->unk_0 = 0;
    v0 = arg0->unk_4 + 32;
    if ((s32)((u32)__cntlzw(arg0->unk_0) >> 5) == 1) return 0;
    if (arg0->unk_8 < 2048) {
        arg0->unk_0 = -1;
        return 0;
    }
    if (memcmp(v0, (u32)lbl_12_rodata_10E4, 24) != 0) {
        arg0->unk_0 = -1;
        return 0;
    }
    arg0->unk_0 = 2;
    if (!version(arg0, &v2, &v3)) return 0;
    arg0->unk_C = v3 + v2 * 100;
    arg1->unk_0 = 1;
    return 1;
}
/* fzgx:end fn_12_32EAC */

/* fzgx:begin fn_12_330E0 */
/* --- rel/movie_module/fn_12_330E0.c --- */

struct fn_12_330E0_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};

u32 fn_12_330E0(struct fn_12_330E0_Arg0 *arg0) {
    u32 v0;
    arg0->unk_0 = 0;
    arg0->unk_4 = 0;
    arg0->unk_8 = 0;
    arg0->unk_C = 0;
    v0 = (*((struct fn_12_330E0_lbl_12_bss_1B75C *)&lbl_12_bss_1B75C)).unk_4;
    (*((struct fn_12_330E0_lbl_12_bss_1B75C *)&lbl_12_bss_1B75C)).unk_4 = (v0 - 1);
    return v0;
}
/* fzgx:end fn_12_330E0 */

/* fzgx:begin fn_12_3310C */
/* --- rel/movie_module/fn_12_3310C.c --- */

typedef struct MovieEntry {
    s32 used;
    u32 arg0;
    u32 arg1;
    u32 unk_0c;
} MovieEntry;

MovieEntry *fn_12_3310C(u32 arg0, u32 arg1) {
    MovieEntry *entry;
    s32 count;
    MovieEntry *last;
    s32 index;
    s32 i;

    count = (s32)lbl_12_bss_1B75C[0];
    last = 0;
    index = (s32)lbl_12_bss_1B75C[1];
    entry = (MovieEntry *)lbl_12_bss_1B75C[2];
    if (index >= count) {
        return 0;
    }

    for (i = 0; i < count; i++) {
        last = entry;
        if (entry->used == 0) {
            break;
        }
        entry++;
    }

    last->used = 1;
    last->arg0 = arg0;
    last->arg1 = arg1;
    lbl_12_bss_1B75C[1]++;
    return last;
}
/* fzgx:end fn_12_3310C */

/* fzgx:begin fn_12_33178 */
/* --- rel/movie_module/fn_12_33178.c --- */

void fn_12_33178(u32 arg0) {
    if (--lbl_12_bss_1B758 > 0) {
        return;
    }
    lbl_12_bss_1B75C[0] = 0;
    lbl_12_bss_1B75C[1] = 0;
    lbl_12_bss_1B75C[2] = 0;
}
/* fzgx:end fn_12_33178 */

/* fzgx:begin fn_12_331A8 noprologue */
#include "types.h"

typedef struct SFHHandle {
    int state;
    const unsigned char *header;
    int header_size;
    int version;
} SFHHandle;

typedef struct SFHObjectInfo {
    int capacity;
    int active_count;
    SFHHandle *objects;
} SFHObjectInfo;

extern const char lbl_12_rodata_10A8[49];

u32 lbl_12_bss_1B758;
SFHObjectInfo lbl_12_bss_1B75C;
u32 lbl_12_bss_1B75C__fzgx_offset_C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s; // fzgx-allow: S2 BSS primer ordering
    s = *(u8 *)&lbl_12_bss_1B758;
    s = *(u8 *)&lbl_12_bss_1B75C;
    s = *(u8 *)&lbl_12_bss_1B75C__fzgx_offset_C;
}
#pragma section code_type ".text"

static inline void sfh_ClearHn(SFHHandle *objects, int capacity) {
    int i;
    for (i = 0; i < capacity; i++) {
        objects[i].state = 0;
        objects[i].header = 0;
        objects[i].header_size = 0;
        objects[i].version = 0;
    }
}

void fn_12_331A8(int capacity, SFHHandle *objects) {
    if ((s32)lbl_12_bss_1B758 > 0) {
        return;
    }
    lbl_12_bss_1B758++;
    lbl_12_bss_1B75C__fzgx_offset_C = (u32)lbl_12_rodata_10A8;
    sfh_ClearHn(objects, capacity);
    lbl_12_bss_1B75C.capacity = capacity;
    lbl_12_bss_1B75C.active_count = 0;
    lbl_12_bss_1B75C.objects = objects;
}
/* fzgx:end fn_12_331A8 */
