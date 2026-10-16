#include "types.h"

struct VObj;
struct VTbl {
    void *pad[5];
    void (*fn14)(struct VObj *);
};
struct VObj {
    struct VTbl *vt;
};

struct MovieModule {
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

extern int fn_12_3A36C(struct MovieModule *);
extern void MWSFSVM_Error(const char *, ...);
extern int fn_12_23280(void *);
extern void fn_12_3916C(struct MovieModule *, u32);
extern void fn_12_38DC8(struct MovieModule *);
extern void fn_12_3858C(struct MovieModule *);
extern void LSC_Start(void *);

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

static inline void fn_12_349CC_inner(struct MovieModule *self) {
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

void fn_12_349CC(struct MovieModule *self) {
    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error("E1122634: mwPlyStartSeamless: handle is invalid.");
        return;
    }
    fn_12_349CC_inner(self);
    fn_12_3916C(self, self->field_12c);
    fn_12_38DC8(self);
    LSC_Start(self->field_4c);
    if (self->field_128 != 0) {
        self->field_128->vt->fn14(self->field_128);
    }
    fn_12_3858C(self);
}
