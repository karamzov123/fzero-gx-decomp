#include "types.h"

typedef struct MovieState {
    u8 pad0[0x40];
    void *field40;
    u8 pad44[0x2c];
    s8 state70;
    s8 state71;
} MovieState;

typedef struct fn_12_3454C_MovieModule {
    u8 _pad[0x4c];
    void *movie;
} fn_12_3454C_MovieModule;

typedef struct fn_12_34798_MovieObject fn_12_34798_MovieObject;

struct MovieObjectVTable {
    void (*unused_00)(fn_12_34798_MovieObject *);
    void (*unused_04)(fn_12_34798_MovieObject *);
    void (*unused_08)(fn_12_34798_MovieObject *);
    void (*unused_0c)(fn_12_34798_MovieObject *);
    void (*unused_10)(fn_12_34798_MovieObject *);
    void (*method_14)(fn_12_34798_MovieObject *);
};

struct fn_12_34798_MovieObject {
    struct MovieObjectVTable *vtable;
};

typedef struct fn_12_34798_MovieModule fn_12_34798_MovieModule;

struct fn_12_34798_MovieModule {
    u8 pad_00[8];
    int field_08;
    u8 pad_0c[0x34];
    void *field_40;
    u8 pad_44[0x08];
    void *movie;
    u8 pad_50[0x20];
    s8 field_70;
    u8 pad_71[3];
    int field_74;
    u8 pad_78[0xb0];
    fn_12_34798_MovieObject *field_128;
    void *field_12c;
};

typedef struct fn_12_34390_MovieModule {
    u8 pad_00[0x40];
    void *field40;
    u8 pad_44[8];
    void *movies;
    u8 pad_50[0x20];
    s8 state70;
    u8 pad_71[0xb7];
    void *field128;
    void *field12c;
} fn_12_34390_MovieModule;

struct fn_12_34634_MovieModule {
    u8 pad_00[0x70];
    char field_70;
    char field_71;
};

struct VObj {
    struct VTbl *vt;
};

struct VTbl {
    void *pad[5];
    void (*fn14)(struct VObj *);
};

struct fn_12_349CC_MovieModule {
    u8 pad_00[0x40];
    void *field_40;
    u8 pad_44[0x8];
    void *field_4c;
    u8 pad_50[0x20];
    s8 field_70;
    u8 pad_71[0xb7];
    struct VObj *field_128;
    u32 field_12c;
};

typedef struct Sig_fn_12_3A36C_Fn12_3A36C_Object {
    u32 unk0;
    u32 unk4;
} Sig_fn_12_3A36C_Fn12_3A36C_Object;

struct fn_12_3496C_MovieModule {
    u8 pad_00[0x4c];
    void *field_4c;
};

struct fn_12_34AB0_MovieModule {
    u8 pad_00[0x08];
    int field_08;
    u8 pad_0c[0x40];
    void *field_4c;
    u8 pad_50[0x24];
    int field_74;
};
extern int fn_12_3A36C();
extern const u8 lbl_12_rodata_1420[];
extern void MWSFSVM_Error(const char *format, ...);
extern u32 fn_80056730(u32 arg0, u32 arg1);
extern const u8 lbl_12_rodata_12E0[];
extern int fn_800570DC(void *, void *);
extern int fn_12_23280(void *arg0);
extern char lbl_12_rodata_130C[42];
extern u32 fn_800567EC();
extern u32 fn_80056C20();
extern char lbl_12_rodata_1338[46];
extern u8 lbl_12_rodata_1368[88];
extern u32 fn_80056BE0(u32 arg0);
extern void* fn_80056B50(void* movies, int index);
extern u32 fn_80056A50(s32 *arg0, s32 arg1);
extern u8 lbl_12_bss_1B780[288];
extern void fn_80056CD0(void *);
extern s32 fn_8004F818(s32 arg0, s32 arg1, char *arg2, u32 *arg3, u32 *arg4, u32 *arg5);
extern void fn_80056E9C(void *, u8 *, u32, u32, u32);
extern void fn_12_3916C(fn_12_34798_MovieModule *, void *);
extern void fn_12_38DC8(fn_12_34798_MovieModule *);
extern void LSC_Start(void *);
extern void fn_12_3858C(fn_12_34798_MovieModule *);
extern const char lbl_12_rodata_13C0[];
extern const char lbl_12_rodata_13EC[];
extern const u8 lbl_12_rodata_1480[];

/* fzgx:begin fn_12_341E4 */
/* --- rel/movie_module/fn_12_341E4.c --- */


void fn_12_341E4(MovieState *movie, int value) {
    if (fn_12_3A36C(movie) == 0) {
        MWSFSVM_Error((((char *)&lbl_12_rodata_12E0)));
    } else {
        void *field = movie->field40;

        if (movie->state70 == 1 && value == 0) {
            movie->state71 = 1;
        }
        if ((s8)movie->state70 == 0 && value == 1 &&
            fn_12_23280(field) != 0) {
            MWSFSVM_Error(lbl_12_rodata_130C);
        }
        movie->state70 = value;
    }
}
/* fzgx:end fn_12_341E4 */

/* fzgx:begin fn_12_3428C */
/* --- rel/movie_module/fn_12_3428C.c --- */

struct fn_12_3428C_Arg0 {
    u8 pad_0[0x4C];
    u32 unk_4C;
};

void fn_12_3428C(struct fn_12_3428C_Arg0 *arg0) {
    if (arg0->unk_4C != 0) {
    fn_800567EC(arg0->unk_4C);
    }
}
/* fzgx:end fn_12_3428C */

/* fzgx:begin fn_12_342B8 */
/* --- rel/movie_module/fn_12_342B8.c --- */

u32 fn_12_342B8(void) {
    u32 t0;
    t0 = fn_80056C20();
    return ((u32)__cntlzw((3 - t0)) >> 5);
}
/* fzgx:end fn_12_342B8 */

/* fzgx:begin fn_12_342E4 */
typedef struct fn_12_342E4_MovieModule {
    u8 pad_00[0x4c];
    void* movies;
} fn_12_342E4_MovieModule;


int fn_12_342E4(fn_12_342E4_MovieModule* module, int index) {
    if (!fn_12_3A36C()) {
        MWSFSVM_Error(lbl_12_rodata_1338);
        return 0;
    }

    if (index >= ((int)fn_80056BE0( (u32)(void*)(module->movies)))) {
        return 0;
    }

    if (index < 0) {
        MWSFSVM_Error((const char*)lbl_12_rodata_1368, index);
        return 0;
    }

    return ((int)fn_80056A50( (s32 *)(void*)(module->movies), (s32)(void*)(fn_80056B50(module->movies, index))));
}
/* fzgx:end fn_12_342E4 */

/* fzgx:begin fn_12_34390 */
static const char fzgx_pool_strings_lbl_12_rodata_12E0_0[44] = "E1122642: mwPlyLinkStm: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_2C[44] = "E99072101 mwPlyLinkStm: can't link stream";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_58[48] = "E1122637: mwPlyGetSlFname: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_88[40] = "E10821B : Invalid value of stm_no : %d";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_B0[48] = "E1122632: mwPlyStartAfsLp: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_E0[44] = "E1122636: mwPlyEntryAfs: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_10C[52] = "E008311 mwPlyEntryAfs: can't entry pid=%d fid=%d";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_140[44] = "E1122641: mwPlySetLpFlg: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_16C[52] = "E1122634: mwPlyStartSeamless: handle is invalid.";


typedef struct MovieVTable {
    void *pad_00[5];
    void (*method14)(void *object);
} MovieVTable;

typedef struct fn_12_34390_MovieObject {
    MovieVTable *vtable;
} fn_12_34390_MovieObject;

void fn_12_34390(fn_12_34390_MovieModule *module, void *arg1, void *arg2) {
    void * fzgx_live_;
    MovieVTable * fzgx_live;
    
    void *movies;
    fn_12_34390_MovieModule *current;
    int z;
    int y;
    int x;
    void *field;

    

    if (!fn_12_3A36C(module)) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_B0));
        return;
    }

    fn_80056CD0((module->movies));

    if (!fn_12_3A36C(module)) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_E0));
    } else {
        movies = module->movies;
        if (!fn_8004F818( (s32)(void *)(arg1), (s32)(void *)(arg2), (char *)(u8 *)(lbl_12_bss_1B780), (u32 *)(int *)(&x), (u32 *)(int *)(&y), (u32 *)(int *)(&z))) {
            fn_80056E9C(movies, lbl_12_bss_1B780, x, y, z);
        } else {
            MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_10C), arg1, arg2);
        }
    }

    if (!fn_12_3A36C(module)) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_140));
    } else {
        fn_80056730( (u32)(void *)(module->movies), 1);
    }

    if (!fn_12_3A36C(module)) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_16C));
        return;
    }

    current = (fn_12_34390_MovieModule *)module;
    if (!fn_12_3A36C(module)) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_0));
    } else {
        field = module->field40;
        if (module->state70 == 0 && fn_12_23280(field) != 0) {
            MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_2C));
        }
        module->state70 = 1;
    }

    fn_12_3916C( (fn_12_34798_MovieModule *)(fn_12_34390_MovieModule *)(current), current->field12c);
    fn_12_38DC8( (fn_12_34798_MovieModule *)(fn_12_34390_MovieModule *)(current));
    fzgx_live_ = current->movies;
    LSC_Start(fzgx_live_);

    if (current->field128 != 0) {
        fn_12_34390_MovieObject *object = current->field128;
        fzgx_live = object->vtable;
        fzgx_live->method14(object);
    }
    fn_12_3858C( (fn_12_34798_MovieModule *)(fn_12_34390_MovieModule *)(current));
}
/* fzgx:end fn_12_34390 */

/* fzgx:begin fn_12_3454C */
/* --- rel/movie_module/fn_12_3454C.c --- */


void fn_12_3454C(fn_12_3454C_MovieModule *self, const char *arg1, const char *arg2) {
    u32 value_10;
    u32 value_0c;
    u32 value_08;

    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(lbl_12_rodata_13C0);
    } else {
        void *movie = self->movie;

        if (fn_8004F818( (s32)(const char *)(arg1), (s32)(const char *)(arg2), (char *)(u8 *)((((u8 *)&lbl_12_bss_1B780))),
                        &value_10, &value_0c, &value_08) == 0) {
            fn_80056E9C(movie, (((u8 *)&lbl_12_bss_1B780)),
                        value_10, value_0c, value_08);
        } else {
            MWSFSVM_Error(lbl_12_rodata_13EC, arg1, arg2);
        }
    }
}
/* fzgx:end fn_12_3454C */

/* fzgx:begin fn_12_34610 */
/* --- rel/movie_module/fn_12_34610.c --- */

void fn_12_34610(fn_12_3454C_MovieModule *module) {
    fn_80056BE0( (u32)(void *)(module->movie));
}
/* fzgx:end fn_12_34610 */

/* fzgx:begin fn_12_34634 */
void fn_12_34634(struct fn_12_34634_MovieModule *self) {
    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error((const char *)lbl_12_rodata_1480);
    } else {
        if (fn_12_3A36C(self) == 0) {
            MWSFSVM_Error((((const char *)((char *)&lbl_12_rodata_12E0))));
        } else {
            if (self->field_70 == 1) {
                self->field_71 = 1;
            }
            self->field_70 = 0;
        }
    }
}
/* fzgx:end fn_12_34634 */

/* fzgx:begin fn_12_346BC */
static const char fzgx_pool_strings_lbl_12_rodata_12E0_0[44] = "E1122642: mwPlyLinkStm: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_2C[44] = "E99072101 mwPlyLinkStm: can't link stream";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_58[48] = "E1122637: mwPlyGetSlFname: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_88[40] = "E10821B : Invalid value of stm_no : %d";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_B0[48] = "E1122632: mwPlyStartAfsLp: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_E0[44] = "E1122636: mwPlyEntryAfs: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_10C[52] = "E008311 mwPlyEntryAfs: can't entry pid=%d fid=%d";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_140[44] = "E1122641: mwPlySetLpFlg: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_16C[52] = "E1122634: mwPlyStartSeamless: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_1A0[52] = "E1122635: mwPlyReleaseSeamless: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_1D4[48] = "E1122631: mwPlyReleaseLp: handle is invalid.";


void fn_12_346BC(u32 arg0) {
    
    u32 v0;
    u32 t0;
    u32 t2;
    u32 t4;
    s32 t5;
    u32 t7;
    
    t0 = ((u32)fn_12_3A36C((Sig_fn_12_3A36C_Fn12_3A36C_Object *)arg0));
    v0 = t0;
    if ((s32)t0 == 0) {
    v0 = (u32)(((u8 *)fzgx_pool_strings_lbl_12_rodata_12E0_1D4));
    MWSFSVM_Error((const char *)(u32)v0);
    } else {
    v0 = arg0;
    t2 = ((u32)fn_12_3A36C((Sig_fn_12_3A36C_Fn12_3A36C_Object *)v0));
    v0 = t2;
    if ((s32)v0 == 0) {
    v0 = (u32)(((u8 *)fzgx_pool_strings_lbl_12_rodata_12E0_140));
    MWSFSVM_Error((const char *)(u32)v0);
    } else {
    v0 = *(u32 *)((u8 *)arg0 + 76);
    t4 = fn_80056730(v0, 0);
    v0 = t4;
    }
    v0 = arg0;
    t5 = ((u32)fn_12_3A36C((Sig_fn_12_3A36C_Fn12_3A36C_Object *)v0));
    v0 = t5;
    if (((0) == ((s32)v0))) {
    v0 = (u32)(((u8 *)fzgx_pool_strings_lbl_12_rodata_12E0_1A0));
    MWSFSVM_Error((const char *)(u32)v0);
    } else {
    v0 = arg0;
    t7 = ((u32)fn_12_3A36C((Sig_fn_12_3A36C_Fn12_3A36C_Object *)v0));
    v0 = t7;
    if ((s32)v0 == 0) {
    v0 = (u32)(((u8 *)fzgx_pool_strings_lbl_12_rodata_12E0_0));
    MWSFSVM_Error((const char *)(u32)v0);
    } else {
    if ((s32)*(u8 *)((u8 *)arg0 + 112) == 1) {
    *(u8 *)((u8 *)arg0 + 113) = 1;
    }
    *(u8 *)((u8 *)arg0 + 112) = 0;
    }
    }
    }
}
/* fzgx:end fn_12_346BC */

/* fzgx:begin fn_12_34798 */
static const char fzgx_pool_strings_lbl_12_rodata_12E0_0[44] = "E1122642: mwPlyLinkStm: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_2C[44] = "E99072101 mwPlyLinkStm: can't link stream";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_58[48] = "E1122637: mwPlyGetSlFname: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_88[40] = "E10821B : Invalid value of stm_no : %d";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_B0[48] = "E1122632: mwPlyStartAfsLp: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_E0[44] = "E1122636: mwPlyEntryAfs: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_10C[52] = "E008311 mwPlyEntryAfs: can't entry pid=%d fid=%d";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_140[44] = "E1122641: mwPlySetLpFlg: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_16C[52] = "E1122634: mwPlyStartSeamless: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_1A0[52] = "E1122635: mwPlyReleaseSeamless: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_1D4[48] = "E1122631: mwPlyReleaseLp: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_204[48] = "E1122630: mwPlyStartFnameLp: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_234[44] = "E10915A: mwPlyStartFnameLp: fname is NULL.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_260[48] = "E1122633: mwPlyEntryFname: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_290[44] = "E10915B: mwPlyEntryFname: fname is NULL.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_2BC[48] = "E204021: mwPlyEntryFname: Can't entry file'%s'";


void fn_12_34798(fn_12_34798_MovieModule *self, void *arg) {
    void (* fzgx_live)(fn_12_34798_MovieObject *);
    

    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_204));
        return;
    }
    if (arg == 0) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_234));
        return;
    }

    fn_80056CD0(self->movie);
    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_260));
    } else if (arg == 0) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_290));
    } else if (fn_800570DC(self->movie, arg) < 0) {
        self->field_08 = 4;
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_2BC), arg);
    } else {
        self->field_74 += 1;
    }

    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_140));
    } else {
        fn_80056730( (u32)(void *)(self->movie), 1);
    }

    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_16C));
        return;
    }

    {
        fn_12_34798_MovieModule *module = (fn_12_34798_MovieModule *)(u32)self;

        if (fn_12_3A36C(self) == 0) {
            MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_0));
        } else {
            int flag = self->field_70;
            void *field = self->field_40;

            if (flag == 0 && fn_12_23280(field) != 0) {
                MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_2C));
            }
            self->field_70 = 1;
        }

        fn_12_3916C(module, module->field_12c);
        fn_12_38DC8(module);
        LSC_Start(module->movie);
        if ((module->field_128) != 0) {
            fzgx_live = module->field_128->vtable->method_14;
            fzgx_live(module->field_128);
        }
        fn_12_3858C(module);
    }
}
/* fzgx:end fn_12_34798 */

/* fzgx:begin fn_12_3496C noprologue */
#include "types.h"

struct MovieModule {
    u8 pad_00[0x4c];
    void *field_4c;
};

extern int fn_12_3A36C(struct MovieModule *, void *);
extern const u8 lbl_12_rodata_1420[];
extern void MWSFSVM_Error(const u8 *, ...);
extern void fn_80056730(void *, void *);

void fn_12_3496C(struct MovieModule *self, void *arg) {
    if (fn_12_3A36C(self, arg) == 0) {
        MWSFSVM_Error(lbl_12_rodata_1420);
    } else {
        fn_80056730(self->field_4c, arg);
    }
}
/* fzgx:end fn_12_3496C */

/* fzgx:begin fn_12_349CC */
struct VObj;



#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime(void) {
    const char *volatile s;  /* fzgx-allow: S2 pool primer sink */
    s = "E1122642: mwPlyLinkStm: handle is invalid.";
    s = "E99072101 mwPlyLinkStm: can't link stream";
    s = "E1122637: mwPlyGetSlFname: handle is invalid.";
    s = "E10821B : Invalid value of stm_no : %d";
    s = "E1122632: mwPlyStartAfsLp: handle is invalid.";
    s = "E1122636: mwPlyEntryAfs: handle is invalid.";
    s = "E008311 mwPlyEntryAfs: can't entry pid=%d fid=%d";
    s = "E1122641: mwPlySetLpFlg: handle is invalid.";
    s = "E1122634: mwPlyStartSeamless: handle is invalid.";
}
#pragma section code_type ".text"

static inline void fn_12_349CC_inner(struct fn_12_349CC_MovieModule *self) {
    void *p;
    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error("E1122642: mwPlyLinkStm: handle is invalid.");
        return;
    }
    p = self->field_40;
    if (self->field_70 == 0) {
        if (fn_12_23280(p) != 0) {
            MWSFSVM_Error("E99072101 mwPlyLinkStm: can't link stream");
        }
    }
    self->field_70 = 1;
}

void fn_12_349CC(struct fn_12_349CC_MovieModule *self) {
    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error("E1122634: mwPlyStartSeamless: handle is invalid.");
        return;
    }
    fn_12_349CC_inner(self);
    fn_12_3916C( (fn_12_34798_MovieModule *)(struct fn_12_349CC_MovieModule *)(self), (void *)(u32)(self->field_12c));
    fn_12_38DC8( (fn_12_34798_MovieModule *)(struct fn_12_349CC_MovieModule *)(self));
    LSC_Start(self->field_4c);
    if (self->field_128 != 0) {
        self->field_128->vt->fn14(self->field_128);
    }
    fn_12_3858C( (fn_12_34798_MovieModule *)(struct fn_12_349CC_MovieModule *)(self));
}
/* fzgx:end fn_12_349CC */

/* fzgx:begin fn_12_34AB0 noprologue */
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

void fn_12_34AB0(struct MovieModule *self, void *arg) {
    const u8 *base = lbl_12_rodata_12E0;

    if (fn_12_3A36C(self, arg) == 0) {
        MWSFSVM_Error(base + 0x260);
    } else if (arg == 0) {
        MWSFSVM_Error(base + 0x290);
    } else if (fn_800570DC(self->field_4c, arg) < 0) {
        self->field_08 = 4;
        MWSFSVM_Error(base + 0x2bc, arg);
    } else {
        self->field_74++;
    }
}
/* fzgx:end fn_12_34AB0 */
