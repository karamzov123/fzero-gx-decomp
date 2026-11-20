#include "types.h"


/* --- rel/movie_module/fn_12_5EC.c --- */
/* --- rel/movie_module/fn_12_5EC.c --- */
/* --- rel/movie_module/fn_12_5EC.c --- */
extern u32 lbl_12_rodata_34;
extern u32 strncmp(u32, u32, u32);

u32 fn_12_5EC(u32 arg0, u32 arg1) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0 || (s32)arg1 < 0) {
    v0 = 0;
    } else {
    v0 += 18;
    t0 = strncmp(v0, (u32)&lbl_12_rodata_34, 1);
    v0 = t0;
    v0 = ((u32)__cntlzw(v0) >> 5);
    }
    return v0;
}

/* --- rel/movie_module/fn_12_63C.c --- */
extern s32 lbl_12_bss_0;

void fn_12_63C(void) {
    if (lbl_12_bss_0 > 0) {
        lbl_12_bss_0--;
    }
}

/* --- rel/movie_module/fn_12_65C.c --- */
extern char lbl_12_rodata_0[49];
extern u32 lbl_12_bss_4;

void fn_12_65C(void) {
    if (lbl_12_bss_0 < 1) {
        lbl_12_bss_4 = (u32)&lbl_12_rodata_0;
        lbl_12_bss_0 = lbl_12_bss_0 + 1;
    }
}

/* --- rel/movie_module/fn_12_68C.c --- */
struct fn_12_68C_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u8 pad_10[0xC];
    u32 unk_1C;
    u8 pad_20[0xC];
    u32 unk_2C;
};

void fn_12_68C(struct fn_12_68C_Arg0 *arg0, u32 arg1) {
    s32 v0;
    u32 v1;
    s32 v2;
    v0 = ((s32)(((u32)arg1 >> 31) + arg1) >> 1);
    v1 = (v0 << 1);
    arg0->unk_C = v1;
    v2 = ((s32)(((v0 >> 30) & 0x1) + v1) >> 1);
    arg0->unk_1C = v2;
    arg0->unk_2C = v2;
}

/* --- rel/movie_module/fn_12_6B8.c --- */
struct fn_12_6B8_Arg0 {
    u8 pad_0[4];
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    u8 pad_10[4];
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    u8 pad_20[4];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
};

void fn_12_6B8(struct fn_12_6B8_Arg0 *arg0, u32 arg1) {
    s32 v0;
    s32 v2;
    s32 t8;
    s32 t4;
    s32 tc;
    s32 t18;
    s32 t1c;
    s32 t14;
    s32 t28;
    s32 t2c;
    s32 t24;
    t8 = arg0->unk_8;
    t4 = arg0->unk_4;
    tc = arg0->unk_C;
    v0 = ((s32)(((u32)arg1 >> 31) + arg1) >> 1);
{
    s32 v1;
    v1 = (v0 << 1);
    arg0->unk_4 = t4 + v1 * t8;
    arg0->unk_C = tc - v1;
    v2 = ((s32)(((v0 >> 30) & 0x1) + v1) >> 1);
}
    t18 = arg0->unk_18;
    t1c = arg0->unk_1C;
    t14 = arg0->unk_14;
    arg0->unk_14 = t14 + v2 * t18;
    arg0->unk_1C = t1c - v2;
    t28 = arg0->unk_28;
    t2c = arg0->unk_2C;
    t24 = arg0->unk_24;
    arg0->unk_24 = t24 + v2 * t28;
    arg0->unk_2C = t2c - v2;
}

/* --- rel/movie_module/fn_12_738.c --- */
struct MovieData {
    u8 pad[0x64];
    int value;
};

int fn_12_738(struct MovieData *movie) {
    return movie->value;
}

/* --- rel/movie_module/fn_12_740.c --- */
typedef struct MovieModule {
    u8 pad[0x60];
    int value;
} MovieModule;

int fn_12_740(MovieModule *self) {
    return self->value;
}

/* --- rel/movie_module/fn_12_748.c --- */
/* --- rel/movie_module/fn_12_748.c --- */
typedef struct MovieModule_u1 {
    u8 pad30[0x30];
    int value;
} MovieModule_u1;

int fn_12_748(MovieModule_u1 *self) {
    return self->value;
}

/* --- rel/movie_module/fn_12_750.c --- */
typedef struct Fn12750Object {
    u8 _pad30[0x30];
    u32 value;
} Fn12750Object;

void fn_12_750(Fn12750Object *self, u32 value) {
    self->value = value;
}

/* --- rel/movie_module/fn_12_758.c --- */
/* --- rel/movie_module/fn_12_758.c --- */
extern void fn_12_34A8(void *);

typedef struct MovieModule_u2 {
    u8 pad2c[0x2c];
    void *value;
} MovieModule_u2;

void fn_12_758(MovieModule_u2 *self) {
    fn_12_34A8(self->value);
}

/* --- rel/movie_module/fn_12_77C.c --- */
extern void fn_12_34C4(void *value);

void fn_12_77C(MovieModule_u2 *self) {
    fn_12_34C4(self->value);
}

/* --- rel/movie_module/fn_12_7A0.c --- */
typedef struct Fn127A0Object {
    u8 _pad20[0x20];
    void *value;
} Fn127A0Object;

extern void fn_12_365C(void *value);

void fn_12_7A0(Fn127A0Object *self) {
    fn_12_365C(self->value);
}

/* --- rel/movie_module/fn_12_7C4.c --- */
/* --- rel/movie_module/fn_12_7C4.c --- */
typedef struct MovieModule_u3 {
    u8 pad20[0x20];
    void *value;
} MovieModule_u3;

extern void fn_12_3670(void *value);

void fn_12_7C4(MovieModule_u3 *self) {
    fn_12_3670(self->value);
}

/* --- rel/movie_module/fn_12_7E8.c --- */
struct fn_12_7E8_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};
struct fn_12_7E8_Arg1 {
    u32 unk_0;
};
struct fn_12_7E8_Arg2 {
    u32 unk_0;
};

u32 fn_12_7E8(struct fn_12_7E8_Arg0 *arg0, struct fn_12_7E8_Arg1 *arg1, struct fn_12_7E8_Arg2 *arg2) {
    if ((s32)arg0->unk_10 != 1) {
    arg1->unk_0 = 0;
    arg2->unk_0 = 0;
    return (u32)arg0;
    }
    arg1->unk_0 = arg0->unk_14;
    arg2->unk_0 = arg0->unk_18;
}

/* --- rel/movie_module/fn_12_818.c --- */
/* --- rel/movie_module/fn_12_818.c --- */
typedef struct MovieModule_u4 {
    u8 pad10[0x10];
    u32 state;
    u32 arg1;
    u32 arg2;
    u8 pad1c[4];
    void *value;
} MovieModule_u4;

extern char lbl_12_rodata_58[8];
extern char lbl_12_rodata_50[5];

typedef struct Sig_SJ_SearchTag_SJCK {
    unsigned char *data;
    int len;
} Sig_SJ_SearchTag_SJCK;

extern unsigned char *SJ_SearchTag(const Sig_SJ_SearchTag_SJCK *needle, const char *name, const char *tag, Sig_SJ_SearchTag_SJCK *out);
extern void fn_12_47C8(void *value, u32 arg1, u32 arg2);

void fn_12_818(MovieModule_u4 *self, u32 arg1, u32 arg2) {
    void *value = self->value;
    Sig_SJ_SearchTag_SJCK tag;
    Sig_SJ_SearchTag_SJCK out;

    self->arg1 = arg1;
    self->arg2 = arg2;
    tag.data = (unsigned char *)arg1;
    tag.len = arg2;
    if (SJ_SearchTag(&tag, lbl_12_rodata_50, lbl_12_rodata_58, &out) == 0) {
        fn_12_47C8(value, 0, 0);
    } else {
        fn_12_47C8(value, (u32)out.data, (u32)out.len);
    }
    self->state = 1;
}

/* --- rel/movie_module/fn_12_8B4.c --- */
typedef struct Fn12_8B4Data {
    u8 unk_00[8];
    s32 value_08;
    s32 value_0C;
} Fn12_8B4Data;

void fn_12_8B4(Fn12_8B4Data *data, s32 *value_08, s32 *value_0C) {
    *value_08 = data->value_08;
    *value_0C = data->value_0C;
}

/* --- rel/movie_module/fn_12_8C8.c --- */
typedef struct Fn12_8C8 {
    u8 _pad08[8];
    u32 field_08;
    u32 field_0c;
} Fn12_8C8;

void fn_12_8C8(Fn12_8C8 *self, u32 value_08, u32 value_0c) {
    self->field_08 = value_08;
    self->field_0c = value_0c;
}

/* --- rel/movie_module/fn_12_8D4.c --- */
typedef struct Fn12_8D4 {
    u32 unk0;
    u32 unk4;
} Fn12_8D4;

u32 fn_12_8D4(Fn12_8D4 *self) {
    return self->unk4;
}

/* --- rel/movie_module/fn_12_8DC.c --- */
typedef struct MovieModule_u5 {
    u8 unk0[4];
    s32 value;
} MovieModule_u5;

void fn_12_8DC(MovieModule_u5* module, s32 value) {
    module->value = value;
}

/* --- rel/movie_module/fn_12_8E4.c --- */
typedef struct Fn12_8E4_Self {
    u32 unk_00;
    u32 unk_04;
    s32 field_08;
    s32 field_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
    u32 field_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    s32 field_34;
    u32 field_38;
} Fn12_8E4_Self;

typedef struct Fn12_8E4_Arg1 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    s32 unk_0c;
    u32 unk_10[15];
    u32 unk_4c;
} Fn12_8E4_Arg1;

extern u8 lbl_12_rodata_194[248];
extern void fn_12_309C(u32, u32, void *);
extern void fn_12_3710(u32, u32, u32);
extern void fn_12_3DBDC(void *, void *, u32);

void fn_12_8E4(Fn12_8E4_Self *self, Fn12_8E4_Arg1 *arg1, s32 arg2, void *arg3) {
    struct { u32 v[6]; } vec_a;
    struct { u32 v[6]; } vec_b;
    s32 x;
    s32 y;
    u32 mode;
    s32 cond;

    vec_a.v[0] = arg1->unk_04;
    vec_a.v[1] = arg1->unk_08;
    vec_a.v[2] = arg1->unk_0c;
    vec_a.v[3] = 0x40;

    if (self->field_08 == 0) {
        x = (s32)arg1->unk_08;
    } else {
        x = self->field_08;
    }
    if (self->field_0c == 0) {
        y = arg1->unk_0c / 2;
    } else {
        y = self->field_0c;
    }

    switch (arg2) {
    case 0x10:
        mode = 1;
        break;
    case 0x18:
        mode = 2;
        break;
    case 0x20:
        mode = 3;
        break;
    case 0:
    default:
        fn_12_309C(0, 0, lbl_12_rodata_194);
        mode = 0;
        break;
    }

    vec_b.v[0] = mode;
    vec_b.v[1] = (u32)arg3;
    vec_b.v[2] = (u32)x;
    vec_b.v[3] = (u32)y;
    vec_b.v[4] = arg1->unk_08;
    vec_b.v[5] = (u32)(arg1->unk_0c / 2);

    switch (arg2) {
    case 0x10:
        break;
    case 0x20:
        cond = (self->field_34 != 100);
        if (cond == 1) {
            self->field_34 = 13;
            fn_12_3710(self->field_20, arg1->unk_4c, self->field_38);
        }
        fn_12_3DBDC(&vec_a, &vec_b, self->field_38);
        break;
    }
}
