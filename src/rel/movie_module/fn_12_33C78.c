#include "types.h"

/* --- rel/movie_module/fn_12_33C78.c --- */
typedef struct Sig_fn_12_2B25C_MovieModule {
    char pad_960[0x960];
    int value_960;
} Sig_fn_12_2B25C_MovieModule;

typedef struct Sig_fn_12_2D470_MovieModuleState {
    u8 pad_0[0x78];
    s32 field_78;
    u8 pad_7c[0x8c];
    s32 field_108;
    u8 field_10c[1];
} Sig_fn_12_2D470_MovieModuleState;

typedef struct Sig_fn_12_3310C_MovieEntry {
    s32 used;
    u32 arg0;
    u32 arg1;
    u32 unk_0c;
} Sig_fn_12_3310C_MovieEntry;

struct fn_12_33C78_Self {
    s32 unk_00;
    u8 pad_04[0x18];
    s32 unk_1c;
    u8 pad_20[0x4];
    s32 unk_24;
    u8 pad_28[0x18];
    s32 unk_40;
    u8 pad_44[0x10];
    s32 unk_54;
    u8 pad_58[0x20];
    struct fn_12_33C78_Movie *unk_78;
    s32 unk_7c;
    s32 unk_80;
    s32 unk_84;
    s32 unk_88;
    s32 unk_8c;
    s32 unk_90;
    s32 unk_94;
    s32 unk_98;
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    u8 pad_a8[0xc];
    s32 unk_b4;
    s32 unk_b8;
    u8 pad_bc[0x1c];
    u8 *unk_d8;
    s32 unk_dc;
    u8 *unk_e0;
    s32 unk_e4;
    u8 pad_e8[0x14];
    s32 unk_fc;
};

struct fn_12_33C78_Out {
    s32 unk_00;
    u8 pad_04[0x28];
    s32 unk_2c;
    u8 pad_30[0x18];
    s32 unk_48;
};

struct fn_12_33C78_Movie {
    s32 unk_00;
    u8 pad_04[0x34];
    u32 *unk_38;
    s32 unk_3c;
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
    s32 unk_54;
};

extern void MWSFSVM_Error(const char *, ...);
extern int fn_12_3A36C(void *);
extern int fn_12_3A7D8(void *);
extern int fn_12_2A508(int);
extern void fn_12_2B25C(Sig_fn_12_2B25C_MovieModule *, void *);
extern void fn_12_2B1E8(Sig_fn_12_2B25C_MovieModule *, struct fn_12_33C78_Movie *);
extern s32 fn_12_2D470(Sig_fn_12_2D470_MovieModuleState *, void * *, u32 *);
extern Sig_fn_12_3310C_MovieEntry * fn_12_3310C(u32, u32);
extern int fn_12_32EAC(void *, u32 *);
extern int fn_12_32DBC(void *, u8, s32 *);
extern int fn_12_31528(void *, u8, s32 *);
extern u32 fn_12_35670(u32, u32);
extern u32 fn_12_330E0(void *);
extern void fn_12_33A44(void *, struct fn_12_33C78_Movie *, struct fn_12_33C78_Out *);
extern s32 fn_12_38AE0(void);
extern void fn_12_4D4(u32, s32, u32 *, u32 *);
extern void fn_12_35060(void *, u8 *, u32);
extern void fn_12_3530C(void *);
extern int fn_12_3503C(void *);
extern void fn_12_3564C(void *, u32);
extern int fn_12_35018(void *);
extern void * memset(void *, int, u32);
extern void * memcpy(void *, const void *, u32);

#pragma opt_propagation off
void fn_12_33C78(struct fn_12_33C78_Self *self, struct fn_12_33C78_Out *out) {
    struct fn_12_33C78_Movie *movie;
    char *msg;
    s32 size;
    struct fn_12_33C78_Self * self_local = self;
    struct fn_12_33C78_Out * out_local = out;
    void *sp20;
    u32 sp1c;
    Sig_fn_12_3310C_MovieEntry *entry;
    u32 *hdr;
    u32 *data;
    Sig_fn_12_2B25C_MovieModule *module;
    s32 flag;
    s32 i;
    s32 n;
    struct fn_12_33C78_Movie *m;
    s32 sp18;
    u32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 b;

    msg = "E202231: mwPlyGetNumSkipDisp: handle is invalid.";
    if (fn_12_3A36C(self_local) == 0) {
        MWSFSVM_Error(msg + 0x138);
        out_local->unk_00 = 0;
        return;
    }
    module = (Sig_fn_12_2B25C_MovieModule *)fn_12_3A7D8(self_local);
    fn_12_2B25C(module, &movie);
    if ((movie != 0) && (self_local->unk_54 == 0)) {
        n = self_local->unk_1c;
        for (i = 0; i < n; i++) {
            s32 st;
            if (fn_12_3A36C(self_local) == 0) {
                MWSFSVM_Error(msg + 0x34);
                st = 0;
            } else {
                st = fn_12_2A508(fn_12_3A7D8(self_local));
            }
            if (st != 1) {
                break;
            }
            fn_12_2B1E8(module, movie);
            self_local->unk_84++;
            fn_12_2B25C(module, &movie);
        }
    }
    if (movie != 0) {
        if (self_local->unk_b4 != 1) {
            self_local->unk_b8 = 0;
            self_local->unk_b4 = 1;
            if ((fn_12_2D470((Sig_fn_12_2D470_MovieModuleState *)self_local->unk_40, &sp20, &sp1c) == 0)
                && (sp1c >= 0x800) && (sp20 != 0)) {
                entry = fn_12_3310C((u32)sp20, sp1c);
                if (entry != 0) {
                    if ((fn_12_32EAC((void *)entry, (u32 *)&sp8) != 0) && (sp8 != 0)
                        && (fn_12_32DBC((void *)entry, 0xE0, &spC) != 0) && (spC != 0)
                        && (fn_12_31528((void *)entry, 0xE0, &sp10) != 0)) {
                        if (sp10 == 3) {
                            self_local->unk_b8 = 1;
                            fn_12_35670((u32)self_local, 1);
                        } else {
                            fn_12_35670((u32)self_local, 0);
                        }
                    }
                    fn_12_330E0((void *)entry);
                }
            }
        }
        self_local->unk_7c++;
        self_local->unk_78 = movie;
        m = movie;
        self_local->unk_88 = m->unk_3c;
        self_local->unk_8c = m->unk_40;
        self_local->unk_90 = m->unk_44;
        self_local->unk_94 = m->unk_48;
        self_local->unk_98 = m->unk_4c;
        self_local->unk_9c = m->unk_50;
        self_local->unk_a0 = m->unk_54;
        self_local->unk_a4 = 0;
        fn_12_33A44((void *)self_local, movie, out_local);
        hdr = movie->unk_38;
        data = (u32 *)((0)[hdr]);
        size = (s32)((1)[hdr]);
        if ((fn_12_38AE0() == 1) && (self_local->unk_d8 != 0)) {
            if ((data != 0) && (size > 4)) {
                fn_12_4D4((u32)data + 4, size - 4, &sp14, (u32 *)&sp18);
            } else {
                sp14 = 0;
                sp18 = 0;
            }
            if ((sp14 != 0) && (sp18 > 0)) {
                if (sp18 > self_local->unk_dc) {
                    sp18 = self_local->unk_dc;
                }
                memset((void *)self_local->unk_d8, 0, self_local->unk_dc);
                memcpy((void *)self_local->unk_d8, (void *)sp14, sp18);
                self_local->unk_e0 = self_local->unk_d8;
                self_local->unk_e4 = sp18;
            } else {
                self_local->unk_e0 = 0;
                self_local->unk_e4 = 0;
            }
            fn_12_35060((void *)self_local, self_local->unk_e0, self_local->unk_e4);
        }
        if (self_local->unk_fc < out_local->unk_2c) {
            fn_12_3530C((void *)self_local);
        }
        self_local->unk_fc = out_local->unk_2c;
        b = (self_local->unk_e0 != 0);
        if (b == 1) {
            if (fn_12_3503C((void *)self_local) == 1) {
                fn_12_3564C((void *)self_local, 1);
            } else {
                fn_12_3564C((void *)self_local, 0);
            }
        }
        flag = 0;
        switch (movie->unk_3c) {
        case 3:
            if (movie->unk_44 == 0) {
                flag = 2;
            }
            break;
        case 1:
        case 2:
            flag = 2;
            break;
        case 0:
        default:
            MWSFSVM_Error(msg + 0xbc);
        }
        if (fn_12_38AE0() == 1) {
            if (fn_12_35018((void *)self_local) == 1) {
                flag = 2;
            }
        }
        out_local->unk_48 = flag;
    } else {
        out_local->unk_00 = 0;
    }
}
#pragma opt_propagation reset

/* --- rel/movie_module/fn_12_34084.c --- */
extern char lbl_12_rodata_1280[46];

typedef struct MovieModule {
    u8 pad[0x54];
    void *movie;
} MovieModule;

void *fn_12_34084(MovieModule *module) {
    if (fn_12_3A36C(module) == 0) {
        MWSFSVM_Error(lbl_12_rodata_1280);
        return 0;
    }
    return module->movie;
}
