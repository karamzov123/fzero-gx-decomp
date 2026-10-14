/* Non-matching: best partial attempt (89.29% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"

extern u32 lbl_801A6410;
extern void fn_1_12AB38(const char *);
extern int fn_1_12A8A4(const char *, void **);
extern void *fn_1_4630(u32, u32, const char *, u32);
extern void fn_1_4247C(void *, void *, void *);
typedef struct { u16 count; u8 pad[6]; u8 *entries; u8 padC[0x30]; void *value; } Sig_fn_1_426AC_Fn1426ACObject;
extern void fn_1_426AC(Sig_fn_1_426AC_Fn1426ACObject *, void *);
extern int fn_1_12A9BC(const char *, void **);
extern int fn_80083BCC(const char *, const char *);
extern u32 fn_15_5864(void);
extern void sprintf(char *, const char *, ...);

typedef struct {
    u8 pad[0x88];
    s32 unk_88;
    s32 unk_8C;
    u32 unk_90;
    u32 flags;
    u8 pad_98[0xB4];
    void *p_14c;
    void *obj_150;
    u8 pad_154[0x18];
    void *p_16c;
    void *obj_170;
    u8 pad_174[0x18];
    void *p_18c;
    void *obj_190;
    u8 pad_194[0x18];
    void *p_1ac;
    void *obj_1b0;
    u8 pad_1b4[0x18];
    void *p_1cc;
    void *obj_1d0;
    u8 pad_1d4[0x18];
    void *p_1ec;
    void *obj_1f0;
    u8 pad_1f4[0x18];
    void *obj_210;
    void *p_20c;
} Fn195950Object;

#define type self->unk_88
void fn_1_95950(Fn195950Object *self) {
    u8 *data = (u8 *)&lbl_1_data_209C0;
    char path[0x40];
    u32 flags = self->flags;
    const char *name = *(const char **)(data + 0x35c + self->unk_88 * 4);

    fn_1_12AB38((const char *)(data + 0x71e4));
    sprintf(path, (const char *)(data + 0x71ec), name);
    fn_1_12A8A4(path, &self->p_14c);
    self->obj_150 = fn_1_4630(lbl_801A6410, *(u16 *)self->p_14c * 0x18c + 0x70,
                              (const char *)(data + 0x7240), 0xae0);
    fn_1_4247C(self->obj_150, (u8 *)self->obj_150 + 0x70, self->p_14c);

    if (flags & ((self->unk_88 == 0x15 || self->unk_88 == 0x29 || self->unk_88 == 0x21 || self->unk_88 == 0x2a || self->unk_88 == 0x2b) ? 0xe0000000 : 0xc0000000)) {
        if ((((u32 *)(data + 0x5cb4))[type] & 2) != 0) {
            sprintf(path, (const char *)(data + 0x71f4), name);
            if (fn_1_12A8A4(path, &self->p_16c)) {
                self->obj_170 = fn_1_4630(lbl_801A6410, *(u16 *)self->p_16c * 0x18c + 0x70,
                                          (const char *)(data + 0x7240), 0xaef);
                fn_1_4247C(self->obj_170, (u8 *)self->obj_170 + 0x70, self->p_16c);
            }
            sprintf(path, (const char *)(data + 0x7204), name);
            if (fn_1_12A8A4(path, &self->p_18c)) {
                self->obj_190 = fn_1_4630(lbl_801A6410, *(u16 *)self->p_18c * 0x18c + 0x70,
                                          (const char *)(data + 0x7240), 0xaf6);
                fn_1_4247C(self->obj_190, (u8 *)self->obj_190 + 0x70, self->p_18c);
                fn_1_426AC((Sig_fn_1_426AC_Fn1426ACObject *)self->obj_190, data + 0x6308);
                *(u16 *)((u8 *)self->obj_190 + 2) |= 2;
            }
        }
    }

    if ((flags & 0x3fffffff) && (((u32 *)(data + 0x5cb4))[type] & 4)) {
        sprintf(path, (const char *)(data + 0x7214), name);
        if (fn_1_12A8A4(path, &self->p_1ac)) {
            self->obj_1b0 = fn_1_4630(lbl_801A6410, *(u16 *)self->p_1ac * 0x18c + 0x70,
                                      (const char *)(data + 0x7240), 0xb03);
            fn_1_4247C(self->obj_1b0, (u8 *)self->obj_1b0 + 0x70, self->p_1ac);
        }
    }
    if ((flags & 0x3fffffff) && (((u32 *)(data + 0x5cb4))[type] & 8)) {
        sprintf(path, (const char *)(data + 0x7220), name);
        if (fn_1_12A8A4(path, &self->p_1cc)) {
            self->obj_1d0 = fn_1_4630(lbl_801A6410, *(u16 *)self->p_1cc * 0x18c + 0x70,
                                      (const char *)(data + 0x7240), 0xb0d);
            fn_1_4247C(self->obj_1d0, (u8 *)self->obj_1d0 + 0x70, self->p_1cc);
        }
    }
    if ((flags & 0x3fffffff) && (((u32 *)(data + 0x5cb4))[type] & 0x10)) {
        sprintf(path, (const char *)(data + 0x722c), name);
        if (fn_1_12A8A4(path, &self->p_1ec)) {
            self->obj_1f0 = fn_1_4630(lbl_801A6410, *(u16 *)self->p_1ec * 0x18c + 0x70,
                                      (const char *)(data + 0x7240), 0xb17);
            fn_1_4247C(self->obj_1f0, (u8 *)self->obj_1f0 + 0x70, self->p_1ec);
        }
    }

    if ((flags & 0x1fffffff) && (((u32 *)(data + 0x5cb4))[type] & 0x20)) {
        u32 i, j;
        for (i = 0; i < 20; i++) {
            const char *lookup;
            if (type == 0x22 && self->unk_8C == 2 && lbl_1_bss_960 == 1 &&
                lbl_1_bss_8B3A0.unk_4 == 4 &&
                !(i == 1 || i == 5 || i == 9 || i == 11 || i == 13 || i == 15)) {
                continue;
            }
            if (type == 0x22 && self->unk_8C == 1 && lbl_1_bss_960 == 14 &&
                (i - 1) > 3 && (fn_15_5864() & 0xff) == 4) continue;
            if (type == 0x13 && self->unk_8C == 2 && lbl_1_bss_960 == 1 &&
                lbl_1_bss_8B3A0.unk_4 == 4) continue;
            lookup = 0;
            for (j = 0; j < *(u32 *)(data + 0x6e2c); j++) {
                u8 *entry = data + 0x6b14 + j * 0xc;
                if (type == *(u16 *)entry && i == *(u16 *)(entry + 2)) {
                    lookup = *(const char **)(entry + 4);
                    break;
                }
            }
            sprintf(path, (const char *)(data + 0x71ec), lookup);
            if (!fn_80083BCC(path, (const char *)(data + 0x7248)) ||
                !fn_80083BCC(path, (const char *)(data + 0x7258)) ||
                !fn_80083BCC(path, (const char *)(data + 0x7268))) {
                *(void **)((u8 *)self + 0x210 + i * 0x20) = 0;
                continue;
            }
            if (fn_80083BCC(path, (const char *)(data + 0x7238)) &&
                fn_1_12A9BC(path, (void **)((u8 *)self + 0x20c + i * 0x20))) {
                void *p = *(void **)((u8 *)self + 0x20c + i * 0x20);
                void *obj = fn_1_4630(lbl_801A6410, *(u16 *)p * 0x18c + 0x70,
                                     (const char *)(data + 0x7240), 0xb30);
                *(void **)((u8 *)self + 0x210 + i * 0x20) = obj;
                fn_1_4247C(obj, (u8 *)obj + 0x70, p);
            }
        }
    }
    fn_1_12AB38((const char *)(data + 0x6eec));
}
