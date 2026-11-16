#include "types.h"

typedef struct MovieObject MovieObject;
typedef struct MovieModule MovieModule;

struct MovieObjectVTable {
    void (*unused_00)(MovieObject *);
    void (*unused_04)(MovieObject *);
    void (*unused_08)(MovieObject *);
    void (*unused_0c)(MovieObject *);
    void (*unused_10)(MovieObject *);
    void (*method_14)(MovieObject *);
};

struct MovieObject {
    struct MovieObjectVTable *vtable;
};

struct MovieModule {
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
    MovieObject *field_128;
    void *field_12c;
};

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

extern int fn_12_3A36C(MovieModule *);
extern void MWSFSVM_Error(const char *, ...);
extern int fn_12_23280(void *);
extern void fn_12_3916C(MovieModule *, void *);
extern void fn_12_38DC8(MovieModule *);
extern void fn_12_3858C(MovieModule *);
extern void fn_80056CD0(void *);
extern int fn_800570DC(void *, void *);
extern void fn_80056730(void *, int);
extern void LSC_Start(void *);

static inline MovieObject * fn_12_34798_read_pointer(MovieModule * owner) { return owner->field_128; }
void fn_12_34798(MovieModule *self, void *arg) {
    void (* fzgx_live)(MovieObject *);
    

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
        fn_80056730(self->movie, 1);
    }

    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_16C));
        return;
    }

    {
        MovieModule *module = (MovieModule *)(u32)self;

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
        if (fn_12_34798_read_pointer(module) != 0) {
            fzgx_live = module->field_128->vtable->method_14;
            fzgx_live(module->field_128);
        }
        fn_12_3858C(module);
    }
}

