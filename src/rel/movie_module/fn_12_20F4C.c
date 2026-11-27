#include "types.h"

/* --- rel/movie_module/fn_12_20F4C.c --- */
extern void *fn_12_57F0(void *value, const void *unused, u32 frames);
extern void fn_800589BC(int *a, int frames, int *b, int *c);

typedef void (*MoviePrepareFn)(void *, int, int, void *);
typedef void (*MovieUpdateFn)(void *, int, void *);
typedef void (*MovieProcessFn)(void *, int, void *);

typedef struct MovieVTable {
    void *unused[6];
    MoviePrepareFn prepare;
    MovieUpdateFn update;
    MovieProcessFn process;
} MovieVTable;

typedef struct MovieData {
    MovieVTable *vtable;
} MovieData;

typedef union MovieResult {
    f64 real;
    struct {
        int value;
        int duration;
    } words;
} MovieResult;

typedef struct MovieState {
    char pad0000[4];
    MovieData *movie;
    int field8;
    char pad000c[0x3c];
    int elapsed;
} MovieState;

typedef struct MovieModule {
    char pad0000[0x1b74];
    MovieState *state;
} MovieModule;

void fn_12_20F4C(MovieModule *module, void *unused, int frames, int *result) {
    int local8;
    f64 local10;
    int frame_count = frames;
    MovieState *state = module->state;
    MovieData *movie = state->movie;
    int duration;
    void *value;
    int *words;

    movie->vtable->prepare(movie, 0, state->field8, &local10);
    words = (int *)&local10;
    value = (void *)words[0];
    duration = words[1];
    if (frame_count < duration) {
        duration = frame_count;
    }
    frame_count = 0x19000;
    if (duration < frame_count) {
        frame_count = duration;
    }

    fn_12_57F0(value, unused, frame_count);
    if (frame_count == 0) {
        movie->vtable->update(movie, 0, &local10);
    } else {
        fn_800589BC((int *)&local10, frame_count, (int *)&local10, &local8);
        movie->vtable->process(movie, 1, &local10);
        movie->vtable->update(movie, 0, &local8);
    }
    state->elapsed += frame_count;
    *result = frame_count;
}

/* --- rel/movie_module/fn_12_2105C.c --- */
typedef struct MovieModule_u1 MovieModule_u1;
typedef void (*MovieReadFn)(MovieModule_u1 *, int, int, int *);

typedef struct MovieState_u1 {
    void *movie;
    u8 pad04[0x38];
    MovieReadFn read;
    int field40;
    int field44;
    int field48;
} MovieState_u1;

typedef struct MovieInfo {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
} MovieInfo;

struct MovieModule_u1 {
    u8 pad0000[0xe70];
    int fieldE70;
    int fieldE74;
    u8 padE78[0x1b74 - 0xe78];
    MovieState_u1 *state;
    int field1b78;
    int field1b7c;
    int field1b80;
    u8 pad1b84[0x2908 - 0x1b84];
    u8 *field2908;
};

extern int fn_12_2D73C(MovieModule_u1 *, int);
extern int fn_12_21D30(MovieModule_u1 *, int);
extern int fn_12_22390(MovieModule_u1 *, int, int *);
extern int fn_12_22008(MovieModule_u1 *, int, int);
extern int fn_12_21D50(MovieModule_u1 *, int);
extern void fn_12_21D60(MovieModule_u1 *, int, int);
extern int lbl_12_bss_698C;
extern int fn_12_24A88(MovieModule_u1 *, int);
extern void fn_12_309B0(void *, int);
extern void fn_12_21D40(MovieModule_u1 *, int, int);
extern int fn_12_23078(MovieModule_u1 *, int, int);
extern int fn_8004C658(void *);
extern int fn_8004BD9C(void *);
extern int fn_8004C0B4(void *);
extern int fn_8004C10C(void *);
extern int fn_8004C05C(void *);
extern int fn_8004BE98(void *, int);

static inline int step1(MovieModule_u1 *m, int *out) {
    MovieState_u1 *s = m->state;
    int pair[6];
    int loc8;
    int r;
    int a;
    int b;

    *out = 0;
    r = fn_12_22390(m, m->field1b7c, pair);
    a = pair[0];
    b = pair[1];
    if (r != 0) {
        return r;
    }
    *out = b;
    s->read(m, a, b, &loc8);
    r = fn_12_22008(m, m->field1b7c, loc8);
    a = 0;
    if (r != 0) {
        a = r;
    }
    if (a != 0) {
        return a;
    }
    return a;
}

static inline int isThree(MovieModule_u1 *m) {
    return fn_8004C658(m->state->movie) == 3;
}

static inline void step2(MovieModule_u1 *m) {
    int b;
    int a;

    a = m->field1b80;
    b = m->field1b7c;
    if (fn_12_21D50(m, a) != 1 && fn_12_21D50(m, b) == 1) {
        int three = isThree(m);
        if (three) {
            fn_12_21D60(m, a, 1);
        }
    }
}

static inline void step3(MovieModule_u1 *m, int flag) {
    MovieState_u1 *s = m->state;
    void *movie = s->movie;
    int st;
    int err;
    void *obj = (u8 *)m + 0xf60;

    st = fn_8004C658(movie);
    err = fn_8004BD9C(movie);
    (void) err;  /* fzgx: keeps the web at its definition */
    if (err != 0) {
        lbl_12_bss_698C = err;
    }
    if (fn_12_2D73C(m, 0x1a) == 0) {
        err = 0;
    }
    switch (err) {
    case -1:
        fn_12_24A88(m, 0xff000c08);
        break;
    case -2:
        fn_12_24A88(m, 0xff000c09);
        break;
    case 0:
        break;
    default:
        fn_12_24A88(m, 0xff000c07);
        break;
    }
    if (st == 4 || st == 5) {
        fn_12_309B0(obj, 0);
    }
    if (st == 5 || err != 0) {
        fn_12_21D40(m, m->field1b80, 1);
    }
    if (fn_12_21D30(m, m->field1b7c) == 1 && flag == 0 && s->field48 == 0) {
        fn_12_21D40(m, m->field1b80, 1);
    }
}

static inline MovieInfo *getInfo(MovieModule_u1 *m, MovieState_u1 *s) {
    if (m->field2908 == 0) {
        return 0;
    }
    if (s->field40 > 0) {
        return 0;
    }
    return (MovieInfo *)(m->field2908 + 0xcfc);
}

static inline int isPlaying(void *movie) {
    int t = fn_8004C658(movie);
    if (t == 0 || t == 1) {
        return 0;
    }
    return 1;
}

static inline void step4(MovieModule_u1 *m) {
    MovieState_u1 *s = m->state;
    MovieInfo *p = getInfo(m, s);

    if (p != 0 && p->field0 == 0) {
        void *movie = s->movie;
        if (isPlaying(movie)) {
            p->field10 = fn_8004C0B4(movie);
            p->field14 = fn_8004C10C(movie);
            p->fieldC = fn_8004C05C(movie);
            p->field4 = p->field10 * p->fieldC * 9 / 16;
            p->field8 = 1;
            p->field0 = 1;
        }
    }
}

static inline void step5(MovieModule_u1 *m) {
    MovieState_u1 *s = m->state;
    void *movie = s->movie;
    int v = fn_12_2D73C(m, 0x1b);

    if (s->field44 != v) {
        s->field44 = v;
        fn_8004BE98(movie, v);
    }
}

static inline void step6(MovieModule_u1 *m) {
    void *movie = m->state->movie;

    if (m->fieldE70 == m->fieldE74) {
        int h = fn_8004C10C(movie);
        int w = fn_8004C0B4(movie);
        if (h > 0 && w > 0) {
            fn_12_23078(m, h, w);
        }
    }
}

#pragma opt_common_subs off
int fn_12_2105C(MovieModule_u1 *m) {
    int flag;
    int result;

    if (fn_12_2D73C(m, 6) == 0) {
        return 0;
    }
    if (fn_12_21D30(m, m->field1b80) == 1) {
        return 0;
    }
    result = step1(m, &flag);
    if (result != 0) {
    }
    step2(m);
    step3(m, flag);
    step4(m);
    step5(m);
    step6(m);
    return result;
}
#pragma opt_common_subs reset
