#include "types.h"

/* --- rel/movie_module/fn_12_267C0.c --- */
typedef struct MovieBlob {
    s32 field_0000[10];
} MovieBlob;

typedef struct MovieData {
    s32 ready;
    u8 pad04[8];
    MovieBlob blob;
    u8 pad34[0x200];
    s32 field_0234;
} MovieData;

typedef struct MovieState {
    void *field_0000;
    u8 pad04[0x70];
    s32 field_0074;
    s32 field_0078;
    u8 pad7c[0xc];
    s32 field_0088;
} MovieState;

typedef struct MovieObject {
    u8 pad_0000[0xcdc];
    MovieBlob blob;
    u8 pad_0d04[0xe2c];
    MovieState *state;
    u8 pad_1b34[0xdd4];
    MovieData *movie;
} MovieObject;

typedef struct MovieArgs {
    u32 field_0000;
    u32 field_0004;
} MovieArgs;

extern s32 fn_12_C218(void *base, MovieArgs *args, s32 *out);
extern s32 fn_12_24A88(MovieObject *self, u32 code);
extern s32 fn_12_2D73C(MovieObject *self, int value);

#pragma opt_propagation off
int fn_12_267C0(MovieObject *self) {
    MovieData * fzgx_live;
    u32 fzgx_value;
    MovieData *movie;
    MovieState *state;
    MovieData *data;
    void *ctx;
    MovieArgs args;
    s32 out;
    s32 result;
    s32 success;

    success = 0;
    fzgx_live = self->movie;
    movie = fzgx_live;
    state = self->state;
    if (movie == 0) {
        data = 0;
    } else if (state->field_0088 > 0) {
        data = 0;
    } else {
        data = (MovieData *)((u8 *)movie + 0xac4);
    }
    if (data == 0) {
        result = 0;
    } else if (data->ready == 0) {
        result = 0;
    } else {
        ctx = state->field_0000;
        self->blob = data->blob;
        fzgx_value = (u32)((u8 *)data + 0x34);
        args.field_0000 = fzgx_value;
        args.field_0004 = (u32)data->field_0234;
        if (fn_12_C218(ctx, &args, &out) != 0) {
            result = fn_12_24A88(self, 0xff000f1b);
        } else {
            success = 1;
            result = 0;
        }
    }
    if (result != 0) {
        return result;
    }
    state->field_0074 = 2;
    if (success == 0 || fn_12_2D73C(self, 0x30) == 0) {
        state->field_0078 = 0xc0;
    } else {
        state->field_0078 = 0xc8;
    }
    return 0;
}
#pragma opt_propagation reset

/* --- rel/movie_module/fn_12_2692C.c --- */
/* --- rel/movie_module/fn_12_2692C.c --- */
extern void fn_12_24970(void *);
extern void fn_12_2AB00(void *);
extern void fn_12_24950(void *);

int fn_12_2692C(void *arg0, void *arg1) {
    u8 local[8];
    int index;
    void *context;
    void *entry;
    int result;

    fn_12_24970(local);
    index = *(int *)((u8 *)arg0 + 0x1b3c);
    context = *(void **)((u8 *)arg0 + 0x1b30);
    entry = (u8 *)arg0 + index * 0x74;
    entry = *(void **)((u8 *)entry + 0x1160);
    if (*(int *)entry != 1) {
        result = fn_12_24A88(arg0, 0xff000f0e);
    } else if ((u8 *)entry + 4 != (u8 *)arg1) {
        result = fn_12_24A88(arg0, 0xff000f0f);
    } else {
        *(int *)entry = 0;
        fn_12_2AB00(*(void **)((u8 *)context + 0x70));
        result = 0;
    }
    fn_12_24950(local);
    return result;
}

/* --- rel/movie_module/fn_12_269E4.c --- */
struct fn_12_269E4_arg0_1138_E116 {
    u8 pad_0[0x28];
    u32 unk_28;
    u8 pad_2C[0x48];
};
struct fn_12_269E4_Arg0 {
    u8 pad_0[0x38];
    u32 unk_38;
    u8 pad_3C[0x10FC];
    struct fn_12_269E4_arg0_1138_E116 unk_1138[1];
    u8 pad_11AC[0x984];
    u32 unk_1B30;
    u8 pad_1B34[0x8];
    u32 unk_1B3C;
};
struct fn_12_269E4_Arg1 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x8];
    u32 unk_40;
    u8 pad_44[0x18];
    u32 unk_5C;
    u32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u32 unk_6C;
    u32 unk_70;
    u32 unk_74;
};
struct fn_12_269E4_Arg2 {
    u32 unk_0;
};


void fn_12_269E4(struct fn_12_269E4_Arg0 *arg0, struct fn_12_269E4_Arg1 *arg1, struct fn_12_269E4_Arg2 *arg2) {
    u32 v1;
    u32 v0;
    u32 v2;
    v0 = arg0->unk_1138[arg0->unk_1B3C].unk_28;
    v1 = arg0->unk_1B30;
    arg2->unk_0 = (v0 + 4);
    *(u32 *)((u8 *)v0 + 0) = 1;
    *(u32 *)((u8 *)v1 + 112) = (u32)arg1;
    *(u32 *)((u8 *)arg2->unk_0 + 0) = arg1->unk_28;
    *(u32 *)((u8 *)arg2->unk_0 + 4) = arg1->unk_2C;
    *(u32 *)((u8 *)arg2->unk_0 + 8) = arg1->unk_30;
    *(u32 *)((u8 *)arg2->unk_0 + 12) = arg1->unk_34;
    *(u32 *)((u8 *)arg2->unk_0 + 16) = arg1->unk_40;
    *(u32 *)((u8 *)arg2->unk_0 + 20) = arg1->unk_8;
    *(u32 *)((u8 *)arg2->unk_0 + 24) = arg1->unk_C;
    *(u32 *)((u8 *)arg2->unk_0 + 28) = arg0->unk_38;
    *(u32 *)((u8 *)arg2->unk_0 + 32) = arg1->unk_4;
    *(u32 *)((u8 *)arg2->unk_0 + 36) = arg1->unk_10;
    *(u32 *)((u8 *)arg2->unk_0 + 40) = arg1->unk_14;
    *(u32 *)((u8 *)arg2->unk_0 + 44) = arg1->unk_18;
    *(u32 *)((u8 *)arg2->unk_0 + 48) = arg1->unk_1C;
    *(u32 *)((u8 *)arg2->unk_0 + 52) = arg1->unk_20;
    *(u32 *)((u8 *)arg2->unk_0 + 56) = arg1->unk_24;
    *(u32 *)((u8 *)arg2->unk_0 + 60) = arg1->unk_5C;
    *(u32 *)((u8 *)arg2->unk_0 + 64) = arg1->unk_60;
    *(u32 *)((u8 *)arg2->unk_0 + 68) = arg1->unk_64;
    *(u32 *)((u8 *)arg2->unk_0 + 72) = arg1->unk_68;
    *(u32 *)((u8 *)arg2->unk_0 + 76) = arg1->unk_6C;
    *(u32 *)((u8 *)arg2->unk_0 + 80) = arg1->unk_70;
    v2 = arg2->unk_0;
    *(u32 *)((u8 *)v2 + 84) = arg1->unk_74;
}
