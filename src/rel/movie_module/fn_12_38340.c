#include "types.h"


/* --- rel/movie_module/fn_12_38340.c --- */
typedef u32 (*fn_12_38340_Fn0)(u32, u32);
typedef u32 (*fn_12_38340_Fn1)(u32, u32);
struct fn_12_38340_Arg0 {
 u8 pad_0[0x158];
 u32 arena;
 u32 capacity;
 u32 current;
 u32 used;
 s32 count;
 u32 unk_16C[32];
};
struct fn_12_38340_Arg1 {
 u8 pad_0[8];
 s32 unk_8;
 s32 unk_C;
};
extern u32 *fn_12_38DBC(void);
extern char lbl_12_rodata_1DF4[33];
extern void MWSFSVM_Error(const char *, ...);
static inline u32 allocate(struct fn_12_38340_Arg0 *arg0, s32 size) {
 u32 result;
 u32 *manager;
 if (arg0->count >= 32) {
  MWSFSVM_Error(lbl_12_rodata_1DF4);
  return 0;
 }
 if (size < 0) return 0;
 if (arg0->arena != 0) {
  if (arg0->used + size > arg0->capacity) result = 0;
  else {
   result = arg0->current;
   arg0->current = result + size;
   arg0->used = arg0->used + size;
  }
 } else {
  manager = fn_12_38DBC();
  result = ((fn_12_38340_Fn0)manager[10])(manager[12], size);
 }
 if (result != 0) {
  arg0->unk_16C[arg0->count] = result;
  arg0->count++;
 }
 return result;
}
s32 fn_12_38340(struct fn_12_38340_Arg0 *arg0, struct fn_12_38340_Arg1 *arg1, u32 *arg2) {
 s32 v0;
 s32 v1;
 s32 v2;
 s32 v3;
 s32 v5;
 s32 v6;
 s32 v7;
 s32 v13 = 0;
 v0 = (arg1->unk_8 + 15) / 16;
 v1 = (arg1->unk_C + 15) / 16;
 v2 = v0 << 4;
 v3 = v1 << 4;
 v5 = v3 / 2;
 v6 = ((v2 + 31) / 32) << 5;
 v7 = v3 * v6 + ((v5 * (((v2 / 2 + 31) / 32) << 5)) << 1) + 32;
 arg2[0] = allocate(arg0, v7);
 arg2[1] = allocate(arg0, v7);
 if (arg2[0] == 0 || arg2[1] == 0) v13 = -1;
 return v13;
}

/* --- rel/movie_module/fn_12_3858C.c --- */
typedef struct MovieModule {
    u8 pad_0x00[0x40];
    void* player;
    u8 pad_0x44[0xE4];
    void* movie;
    void* movie_data_alt;
    u32 movie_data_alt_1;
    u32 movie_data_alt_2;
    u32 movie_data_alt_3;
    u32 movie_data_1;
    u32 movie_data_2;
    u32 movie_data_3;
    u32 movie_data_4;
    void* movie_data;
    u32 movie_data_5;
    u32 movie_data_6;
} MovieModule;

typedef struct MovieRequest {
    u32 flags;
    void* movie;
    u32 data;
    u32 data_size;
    u32 data_type;
    u32 data_flags;
} MovieRequest;

extern s32 fn_12_2B188(void*, MovieRequest*);
extern void fn_12_38A0C(s32);
extern char lbl_12_rodata_221C[33];

void fn_12_3858C(MovieModule* module) {
    void* movie;
    void* player;
    MovieRequest request;

    movie = module->movie;
    player = module->player;
    if (movie != NULL) {
        if (movie == module->movie_data) {
            request.flags = 1;
            request.movie = movie;
            request.data = module->movie_data_5;
            request.data_size = module->movie_data_6;
            request.data_type = 0;
            request.data_flags = 0;
        } else if (movie == module->movie_data_alt) {
            request.flags = 0;
            request.movie = movie;
            request.data = module->movie_data_alt_1;
            request.data_size = module->movie_data_alt_2;
            request.data_type = module->movie_data_alt_3;
            request.data_flags = 0;
        } else {
            request.flags = module->movie_data_1;
            request.movie = movie;
            request.data = module->movie_data_2;
            request.data_size = module->movie_data_3;
            request.data_type = module->movie_data_4;
            request.data_flags = 0;
        }
        if (fn_12_2B188(player, &request) != 0) {
            fn_12_38A0C(-0x138);
            MWSFSVM_Error(lbl_12_rodata_221C);
        }
    }
}

/* --- rel/movie_module/fn_12_38680.c --- */
extern char lbl_12_rodata_2240[45];
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
