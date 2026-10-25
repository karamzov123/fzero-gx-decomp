/* Non-matching: best partial attempt (68.75% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_5_169C_Rodata {
    f32 f00;
    f32 f04;
    u8 pad08[0x3C];
    char ext44[2];
    u8 pad46[2];
    f32 f48;
};
extern struct fn_5_169C_Rodata lbl_5_rodata_0;

extern u8 lbl_5_data_0[];

typedef struct {
    u32 w[8];
} fn_5_169C_TexObj;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
} fn_5_169C_Ent;

struct fn_5_169C_Bss {
    u32 unk_00;
    u8 pad04[0x0F];
    s8 unk_13;
    u8 unk_14;
    u8 pad15[7];
    u8 unk_1C;
    u8 pad1D[0x13];
    u32 unk_30;
    u32 unk_34;
    u8 pad38[8];
    u8 unk_40;
    u8 pad41[3];
    u32 unk_44;
    u8 unk_48;
    u8 pad49[1];
    s16 unk_4A;
    s16 unk_4C;
    u8 pad4E[0x0F];
    s8 unk_5D;
    u8 pad5E[9];
    u8 unk_67;
    f32 unk_68;
    f32 unk_6C;
    u32 unk_70;
    u32 unk_74;
    void *unk_78[2];
    void *unk_80[2];
    fn_5_169C_TexObj unk_88;
    fn_5_169C_TexObj unk_A8;
    u32 unk_C8;
    void *unk_CC;
    u8 unk_D0[0x4C];
    fn_5_169C_Ent unk_11C[88];
    u8 pad32C[0x48];
    char unk_374[30][64];
    void *unk_AF4[39];
};
extern struct fn_5_169C_Bss lbl_5_bss_0;

extern u32 lbl_801A6410;
extern char lbl_1_bss_198[][64];
extern s16 lbl_1_bss_964;

struct fn_5_169C_S1 {
    f32 v0;
    u32 v4;
    u32 v8;
    u32 vC;
    u8 pad[0x10];
};

struct fn_5_169C_S2 {
    u32 v00;
    u32 v04;
    u32 v08;
    u32 v0C;
    u32 v10;
    u32 v14;
    void *v18;
    u32 v1C;
    u32 v20;
    u8 pad[0xC];
};

struct fn_5_169C_Load {
    u8 pad[0x5C];
};

extern void (*lbl_1_bss_194)(struct fn_5_169C_S1 *);
extern u32 (*lbl_1_bss_18C)(struct fn_5_169C_S2 *);
extern u32 (*lbl_1_bss_188)(struct fn_5_169C_S2 *);

extern void GXInvalidateTexAll(void);
extern u32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
extern void GXInitTexObj(fn_5_169C_TexObj *, void *, u16, u16, s32, s32, s32, u8);
extern void GXInitTexObjLOD(fn_5_169C_TexObj *, s32, s32, f32, f32, f32, u8, u8, s32);
extern void *fn_1_45D0(u32, u32, const char *, s32);
extern void DCInvalidateRange(void *, u32);
extern void fn_80008BEC(void *, int, u32);
extern s16 fn_5_2C54(char *, s32, s32);
extern void fn_5_20FC(void);
extern void fn_5_2E00(void);
extern int fn_1_45730(char *, struct fn_5_169C_Load *);
extern u32 fn_1_45B2C(struct fn_5_169C_Load *);
extern void OSPanic(const char *, int, const char *, ...);
extern void *fn_1_4630(u32, u32, const char *, s32);
extern void fn_1_458A0(struct fn_5_169C_Load *, void *, u32, u32);
extern int fn_80083BCC(const char *, const char *);
extern u32 VIGetNextField(void);
extern void VIWaitForRetrace(void);
extern u32 fn_1_435C(u32);
extern s32 fn_1_3F8C(const char *, void (*)(void), s32, s32);
extern void fn_80070704(s32);
extern int sprintf(char *, const char *, ...);
extern int strncmp(const char *, const char *, u32);

void fn_5_169C(void) {
    struct fn_5_169C_Bss *p = &lbl_5_bss_0;
    struct fn_5_169C_Rodata *ro = &lbl_5_rodata_0;
    u8 *dat = lbl_5_data_0;
    char buf[0x20];
    struct fn_5_169C_S1 s1;
    struct fn_5_169C_S2 s2;
    struct fn_5_169C_Load d;
    fn_5_169C_Ent *e;
    s16 v;
    s8 j;

    v = 0;
    GXInvalidateTexAll();

    p->unk_67 = 0;
    p->unk_68 = ro->f04;
    p->unk_6C = ro->f00;

    p->unk_70 = (GXGetTexBufferSize(p->unk_4A, p->unk_4C, 1, 0, 0) + 0x1F) & ~0x1F;
    p->unk_74 = (GXGetTexBufferSize(p->unk_4A / 2, p->unk_4C / 2, 3, 0, 0) + 0x1F) & ~0x1F;

    for (j = 0; j < 2; j++) {
        p->unk_78[j] = fn_1_45D0(lbl_801A6410, p->unk_70, (char *)dat + 0x14, 0x432);
        p->unk_80[j] = fn_1_45D0(lbl_801A6410, p->unk_74, (char *)dat + 0x14, 0x433);
        DCInvalidateRange(p->unk_78[j], p->unk_70);
        DCInvalidateRange(p->unk_80[j], p->unk_74);
        fn_80008BEC(p->unk_78[j], 0, p->unk_70);
        fn_80008BEC(p->unk_80[j], 0x80, p->unk_74);
    }

    GXInitTexObj(&p->unk_88, p->unk_78[0], p->unk_4A, p->unk_4C, 1, 0, 0, 0);
    GXInitTexObj(&p->unk_A8, p->unk_80[0], p->unk_4A / 2, p->unk_4C / 2, 3, 0, 0, 0);
    GXInitTexObjLOD(&p->unk_88, 0, 0, ro->f00, ro->f00, ro->f00, 0, 0, 0);
    GXInitTexObjLOD(&p->unk_A8, 0, 0, ro->f00, ro->f00, ro->f00, 0, 0, 0);

    if (lbl_1_bss_964 != 0xF) {
        p->unk_C8 = (GXGetTexBufferSize(0x140, 0xE0, 1, 0, 0) + 0x1F) & ~0x1F;
        p->unk_CC = fn_1_45D0(lbl_801A6410, p->unk_C8, (char *)dat + 0x14, 0x441);
        DCInvalidateRange(p->unk_CC, p->unk_C8);
    } else {
        p->unk_CC = 0;
    }

    fn_80008BEC(&s1, 0, 0x20);
    s1.v0 = ro->f48;
    s1.v4 = 1;
    s1.v8 = 1;
    s1.vC = 0;
    lbl_1_bss_194(&s1);

    fn_80008BEC(&s2, 0, 0x30);
    s2.v20 = 0;
    s2.v00 = 1;
    s2.v04 = 0xC00000;
    s2.v08 = 0x280;
    s2.v0C = 0x1C0;
    s2.v10 = 3;
    s2.v14 = 4;
    s2.v1C = lbl_1_bss_18C(&s2);
    s2.v18 = fn_1_45D0(lbl_801A6410, s2.v1C, (char *)dat + 0x14, 0x459);
    p->unk_00 = lbl_1_bss_188(&s2);
    p->unk_44 = (u32)s2.v18;
    fn_80008BEC(p->unk_D0, 0, 0x4C);

    p->unk_13 = 0;
    e = p->unk_11C;
    while (fn_80083BCC(lbl_1_bss_198[p->unk_13], (char *)dat + 0x12DC) != 0) {
        char ext[2] = "";

        e->a = 0;
        if (strncmp(lbl_1_bss_198[p->unk_13], (char *)dat + 0x169C, 3) == 0) {
            v = fn_5_2C54(lbl_1_bss_198[p->unk_13], 3, 4);
            e->a = 0;
            e->b = 0;
            e->c = 0;
        } else if (strncmp(lbl_1_bss_198[p->unk_13], (char *)dat + 0x13E4, 8) == 0) {
            e->a = 0xB;
            e->b = 0;
            e->c = 0;
        } else if (strncmp(lbl_1_bss_198[p->unk_13], (char *)dat + 0x12F0, 4) == 0) {
            e->a = 0xA;
            e->b = 0;
            e->c = 0;
        } else if (strncmp(lbl_1_bss_198[p->unk_13], (char *)dat + 0x16A0, 3) == 0) {
            if (strncmp(lbl_1_bss_198[p->unk_13], (char *)dat + 0x12E0, 5) == 0) {
                e->a = 9;
                e->b = 1;
                e->c = 0;
            } else {
                e->a = 9;
                e->b = 0;
                e->c = 0;
            }
        } else if (strncmp(lbl_1_bss_198[p->unk_13], (char *)dat + 0x16A4, 5) == 0) {
            e->a = 1;
            e->b = 0;
            e->c = fn_5_2C54(lbl_1_bss_198[p->unk_13], 5, 4);
        } else if (strncmp(lbl_1_bss_198[p->unk_13], (char *)dat + 0x16AC, 3) == 0) {
            e->a = 3;
            e->b = fn_5_2C54(lbl_1_bss_198[p->unk_13], 3, 2);
            e->c = fn_5_2C54(lbl_1_bss_198[p->unk_13], 6, 4);
        } else if (strncmp(lbl_1_bss_198[p->unk_13], (char *)dat + 0x16B0, 3) == 0) {
            e->a = 4;
            e->b = fn_5_2C54(lbl_1_bss_198[p->unk_13], 3, 2) - 1;
            e->c = fn_5_2C54(lbl_1_bss_198[p->unk_13], 6, 4);
        } else if (strncmp(lbl_1_bss_198[p->unk_13], (char *)dat + 0x16B4, 3) == 0) {
            if (strncmp(lbl_1_bss_198[p->unk_13], (char *)dat + 0x12E8, 5) == 0) {
                e->a = 5;
                e->b = 0;
                e->c = 0;
            } else {
                if (strncmp(lbl_1_bss_198[p->unk_13], (char *)dat + 0x16B8, 6) == 0) {
                    e->a = 7;
                } else if (strncmp(lbl_1_bss_198[p->unk_13], (char *)dat + 0x16C0, 5) == 0) {
                    e->a = 6;
                } else if (strncmp(lbl_1_bss_198[p->unk_13], (char *)dat + 0x16C8, 5) == 0) {
                    e->a = 8;
                }
                e->b = fn_5_2C54(lbl_1_bss_198[p->unk_13], 6, 4);
                e->c = fn_5_2C54(lbl_1_bss_198[p->unk_13], 0xB, 4);
            }
        } else {
            sprintf(p->unk_374[p->unk_13], (char *)dat + 0x16D0, lbl_1_bss_198[p->unk_13]);
            e->a = 2;
            e->b = 0;
            e->c = v;
            v = 0;
            if (p->unk_5D != -1) {
                switch (p->unk_5D) {
                case 0:
                    ext[0] = 'e';
                    break;
                case 1:
                    ext[0] = 'g';
                    break;
                case 2:
                    ext[0] = 'f';
                    break;
                case 4:
                    ext[0] = 'i';
                    break;
                default:
                    ext[0] = '\0';
                    break;
                }
                sprintf(buf, (char *)dat + 0x16D8, lbl_1_bss_198[p->unk_13], ext);
                if (fn_1_45730(buf, &d) == 0) {
                    p->unk_AF4[p->unk_13] = 0;
                } else {
                    u32 size = (fn_1_45B2C(&d) + 0x1F) & ~0x1F;
                    if (p->unk_AF4[p->unk_13] != 0) {
                        OSPanic((char *)dat + 0x14, 0x4C7, (char *)dat + 0x16E4);
                    }
                    p->unk_AF4[p->unk_13] = fn_1_4630(lbl_801A6410, size, (char *)dat + 0x14, 0x4C8);
                    fn_1_458A0(&d, p->unk_AF4[p->unk_13], size, 0);
                }
            }
        }
        p->unk_13++;
        e++;
    }

    e->a = 0xC;
    e->b = 0;
    e->c = 0;
    if (VIGetNextField()) {
        VIWaitForRetrace();
    }

    fn_1_435C(p->unk_30);
    fn_1_3F8C((char *)dat + 0x16E8, fn_5_20FC, 0, 1);
    fn_1_435C(p->unk_34);
    fn_1_3F8C((char *)dat + 0x1700, fn_5_2E00, 0, 1);
    fn_80070704(p->unk_48);

    p->unk_67 = 0;
    p->unk_68 = ro->f04;
    p->unk_6C = ro->f00;
    p->unk_AF4[30] = 0;
    p->unk_14 = 0xFF;
    p->unk_1C = 1;
    p->unk_40 = 0;
}
