#include "types.h"

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

struct Sig_fn_12_330E0_fn_12_330E0_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};

typedef struct fn_12_340D4_MovieModule {
    u8 pad_00[0x54];
    void *field_54;
} fn_12_340D4_MovieModule;

typedef struct Sig_fn_12_2B25C_MovieModule {
    char pad_960[0x960];
    int value_960;
} Sig_fn_12_2B25C_MovieModule;

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

struct Sig_fn_12_2DF28_fn_12_2DF28_Arg1 {
    u32 unk_0;
};

typedef struct SfdObj {
    u8 pad_0[0x40];
    u32 unk_40;
    u8 pad_44[0xBC - 0x44];
    u8 unk_BC[0xD4 - 0xBC];
    void *unk_D4;
} SfdObj;

typedef struct SfdBuf {
    u8 *data;
    s32 size;
} SfdBuf;

typedef struct SfdHdr {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    SfdBuf *unk_38;
} SfdHdr;

typedef struct SfdInfo {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    u8 *unk_40;
    s32 unk_44;
} SfdInfo;
extern s32 fn_12_2D470(Sig_fn_12_2D470_MovieModuleState *, void * *, u32 *);
extern Sig_fn_12_3310C_MovieEntry * fn_12_3310C(u32, u32);
extern int fn_12_32EAC(void *, u32 *);
extern u32 fn_12_330E0(void *);
extern void MWSFSVM_Error(const char *format, ...);
extern int fn_12_3A36C();
extern u32 lbl_12_rodata_1118;
extern char lbl_12_rodata_114C[50];
extern int fn_12_3A7D8(void *);
extern u32 fn_12_2A508(u32 arg0);
extern char lbl_12_rodata_1180[136];
extern void fn_12_2B1E8(Sig_fn_12_2B25C_MovieModule *, struct fn_12_33C78_Movie *);
extern void fn_12_2A674(u32, u32, u32, void *);
extern u32 fn_12_35670(u32, u32);
extern char lbl_12_rodata_1208[37];
extern u8 lbl_12_rodata_1230[80];
extern s32 fn_12_2DF28(u32, struct Sig_fn_12_2DF28_fn_12_2DF28_Arg1 *);
extern u32 fn_12_38AE0(void);
extern s64 __div2i(s64, s64);
extern void fn_12_2B25C(Sig_fn_12_2B25C_MovieModule *, void *);
extern int fn_12_32DBC(void *, u8, s32 *);
extern int fn_12_31528(void *, u8, s32 *);
extern void fn_12_33A44(SfdObj *obj, SfdHdr *hdr, SfdInfo *info);
extern void fn_12_4D4(u32 movie, s32 count, u32 *result, u32 *duration);
extern void fn_12_35060(void *, u8 *, u32);
extern void fn_12_3530C(void *);
extern int fn_12_3503C(void *);
extern void fn_12_3564C(void *, u32);
extern int fn_12_35018(void *);
extern void * memset(void *, int, u32);
extern void * memcpy(void *, const void *, u32);
extern char lbl_12_rodata_1280[46];
extern char lbl_12_rodata_12B0[46];

/* fzgx:begin fn_12_3379C noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_3379C.c --- */
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

struct Sig_fn_12_330E0_fn_12_330E0_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};
extern s32 fn_12_2D470(Sig_fn_12_2D470_MovieModuleState *, void * *, u32 *);
extern Sig_fn_12_3310C_MovieEntry * fn_12_3310C(u32, u32);
extern int fn_12_32EAC(void *, u32 *);
extern u32 fn_12_330E0(struct Sig_fn_12_330E0_fn_12_330E0_Arg0 *);

s32 fn_12_321E8(Sig_fn_12_3310C_MovieEntry *, s32 *); /* extern */

s32 fn_12_3379C(void *arg0) {
    u32 sp14;
    void *sp10;
    u32 spC;
    s32 sp8;
    s32 var_r31;
    Sig_fn_12_3310C_MovieEntry *temp_r3;

    if (fn_12_2D470((Sig_fn_12_2D470_MovieModuleState *)(*(Sig_fn_12_2D470_MovieModuleState **)((u8 *)(arg0) + 64)), (void * *)(&sp10), (u32 *)(&sp14)) != 0) {
        return -1;
    }
    if ((sp14 < 0x800U) || (sp10 == NULL)) {
        return -1;
    }
    temp_r3 = (Sig_fn_12_3310C_MovieEntry *)(fn_12_3310C((u32)(sp10), sp14));
    if (temp_r3 == NULL) {
        return -1;
    }
    if ((fn_12_32EAC((void *)(temp_r3), (u32 *)(&spC)) == 0) || ((s32) spC == 0)) {
        fn_12_330E0((struct Sig_fn_12_330E0_fn_12_330E0_Arg0 *)((struct Sig_fn_12_330E0_fn_12_330E0_Arg0 *) temp_r3));
        return -1;
    }
    if (fn_12_321E8((Sig_fn_12_3310C_MovieEntry *)(temp_r3), (s32 *)(&sp8)) == 0) {
        var_r31 = -1;
    } else {
        var_r31 = sp8;
    }
    fn_12_330E0((struct Sig_fn_12_330E0_fn_12_330E0_Arg0 *)((struct Sig_fn_12_330E0_fn_12_330E0_Arg0 *) temp_r3));
    return var_r31;
}
/* fzgx:end fn_12_3379C */

/* fzgx:begin fn_12_33874 noprologue */
/* --- rel/movie_module/fn_12_33874.c --- */
extern u32 MWSFSVM_Error(u32, ...);
extern u32 fn_12_3A36C(u32);
extern u32 lbl_12_rodata_1118;

u32 fn_12_33874(u32 arg0) {
    u32 v0;
    u32 t0, t1;
    t0 = fn_12_3A36C(arg0);
    v0 = t0;
    if ((s32)t0 == 0) {
    v0 = (u32)&lbl_12_rodata_1118;
    t1 = MWSFSVM_Error((u32)v0);
    v0 = t1;
    v0 = 0;
    } else {
    v0 = *(u32 *)((u8 *)arg0 + 132);
    }
    return v0;
}
/* fzgx:end fn_12_33874 */

/* fzgx:begin fn_12_338C4 */
/* --- rel/movie_module/fn_12_338C4.c --- */
/* --- rel/movie_module/fn_12_338C4.c --- */

int fn_12_338C4(void *self) {
    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(lbl_12_rodata_114C);
        return 0;
    }
    return ((int)fn_12_2A508(fn_12_3A7D8(self)));
}
/* fzgx:end fn_12_338C4 */

/* fzgx:begin fn_12_3391C */
/* --- rel/movie_module/fn_12_3391C.c --- */

typedef struct MovieState {
    u8 field_00[0x78];
    s32 field_78;
    s32 field_7C;
    s32 field_80;
} MovieState;

void fn_12_3391C(MovieState *self) {
    s32 field_78;
    s32 field_7C;
    s32 field_80;
    int result;

    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(lbl_12_rodata_1180);
        return;
    }

    field_78 = self->field_78;
    field_7C = self->field_7C;
    field_80 = self->field_80;
    result = fn_12_3A7D8(self);
    if (field_7C > field_80) {
        fn_12_2B1E8( (Sig_fn_12_2B25C_MovieModule *)(int)(result), (struct fn_12_33C78_Movie *)(s32)(field_78));
        self->field_80 = self->field_80 + 1;
        self->field_7C = self->field_80;
    }
}
/* fzgx:end fn_12_3391C */

/* fzgx:begin fn_12_339B4 */
/* --- rel/movie_module/fn_12_339B4.c --- */

typedef struct MovieResult {
    u32 field_00;
    u32 field_04;
    u32 field_08;
    s16 field_0C;
    s16 field_0E;
} MovieResult;

typedef struct MovieOutput {
    u32 field_00;
    u32 field_04;
    u32 field_08;
    u32 field_0C;
    u32 field_10;
    u32 field_14;
} MovieOutput;

void fn_12_339B4(u32 arg0, u32 arg1, u32 arg2, MovieOutput *out) {
    MovieResult result;
    fn_12_2A674(arg0, arg1, arg2, &result);
    out->field_00 = result.field_08;
    out->field_04 = result.field_00;
    out->field_08 = result.field_04;
    out->field_0C = result.field_0E;
    out->field_10 = result.field_0C;
    out->field_14 = result.field_0C;
}
/* fzgx:end fn_12_339B4 */

/* fzgx:begin fn_12_33A14 */
/* --- rel/movie_module/fn_12_33A14.c --- */

struct fn_12_33A14_Arg0 {
    u8 pad_0[0xB4];
    u32 unk_B4;
    u32 unk_B8;
};

void fn_12_33A14(struct fn_12_33A14_Arg0 *arg0) {
    arg0->unk_B4 = 0;
    arg0->unk_B8 = 0;
    fn_12_35670((u32)arg0, 0);
}
/* fzgx:end fn_12_33A14 */

/* fzgx:begin fn_12_33A44 */
/* --- rel/movie_module/fn_12_33A44.c --- */






void fn_12_33A44(SfdObj *obj, SfdHdr *hdr, SfdInfo *info) {
    u32 handle;
    s32 v20;
    struct { s32 value; } kind;
    s32 v0;
    s32 v4;
    s32 v8;
    s32 vC;
    struct { s32 value; } type;
    s32 v34;
    s32 v24;
    s32 v28;
    s32 v18;
    s32 v30;
    void *cur;
    struct Sig_fn_12_2DF28_fn_12_2DF28_Arg1 rate;
    s32 r;
    s32 v2C;
    s32 size;
    u8 *data;
    void *base;
    s32 time;

    handle = obj->unk_40;
    v20 = hdr->unk_20;
    switch (hdr->unk_1C) {
    case 1:
        kind.value = 1;
        break;
    case 2:
        kind.value = 2;
        break;
    case 3:
        kind.value = 3;
        break;
    default:
        kind.value = 3;
        break;
    }
    v0 = hdr->unk_00;
    v4 = hdr->unk_04;
    v8 = hdr->unk_08;
    vC = hdr->unk_0C;
    switch (hdr->unk_10) {
    case 1:
        type.value = 1;
        break;
    case 2:
        type.value = 2;
        break;
    case 3:
        type.value = 3;
        break;
    case 4:
        type.value = 4;
        break;
    default:
        MWSFSVM_Error(lbl_12_rodata_1208);
        type.value = 1;
        break;
    }
    v24 = hdr->unk_24;
    v34 = hdr->unk_34;
    v18 = hdr->unk_18;
    v30 = hdr->unk_30;
    v2C = hdr->unk_2C;
    v28 = hdr->unk_28;
    if (fn_12_2DF28(handle, &rate) != 0) {
        MWSFSVM_Error((const char *)lbl_12_rodata_1230);
    }
    r = rate.unk_0;
    {
        time = (s32)__div2i((s64)v34 * r, (s64)v18 * 1000);
    }
    info->unk_00 = v20;
    info->unk_04 = kind.value;
    info->unk_08 = v0;
    info->unk_0C = v4;
    info->unk_10 = v8;
    info->unk_14 = vC;
    info->unk_18 = type.value;
    info->unk_1C = rate.unk_0;
    info->unk_20 = time;
    info->unk_24 = v34;
    info->unk_28 = v18;
    info->unk_2C = v2C;
    info->unk_30 = (s32)(((s64)r * (s64)v30) / ((s64)v18 * 1000));
    info->unk_34 = v30;
    info->unk_38 = v24;
    info->unk_3C = v28;

    base = obj->unk_BC;
    cur = obj->unk_D4;
    data = hdr->unk_38->data;
    size = hdr->unk_38->size;
    if ((s32)fn_12_38AE0() != 1) {
        info->unk_40 = 0;
        info->unk_44 = 0;
    } else if (cur == base) {
        info->unk_40 = 0;
        info->unk_44 = 0;
    } else {
        if (data != 0 && size > 4) {
            data += 4;
            size -= 4;
        }
        info->unk_40 = data;
        info->unk_44 = size;
    }
}
/* fzgx:end fn_12_33A44 */

/* fzgx:begin fn_12_33C78 */
/* --- rel/movie_module/fn_12_33C78.c --- */



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
                st = ((int)fn_12_2A508(fn_12_3A7D8(self_local)));
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
        fn_12_33A44( (SfdObj *)((void *)self_local), (SfdHdr *)(struct fn_12_33C78_Movie *)(movie), (SfdInfo *)(struct fn_12_33C78_Out *)(out_local));
        hdr = movie->unk_38;
        data = (u32 *)((0)[hdr]);
        size = (s32)((1)[hdr]);
        if ((((s32)fn_12_38AE0()) == 1) && (self_local->unk_d8 != 0)) {
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
        if (((s32)fn_12_38AE0()) == 1) {
            if (fn_12_35018((void *)self_local) == 1) {
                flag = 2;
            }
        }
        out_local->unk_48 = flag;
    } else {
        out_local->unk_00 = 0;
    }
}
/* fzgx:end fn_12_33C78 */

/* fzgx:begin fn_12_34084 */
#pragma opt_propagation reset

/* --- rel/movie_module/fn_12_34084.c --- */

typedef struct fn_12_34084_MovieModule {
    u8 pad[0x54];
    void *movie;
} fn_12_34084_MovieModule;

void *fn_12_34084(fn_12_34084_MovieModule *module) {
    if (fn_12_3A36C(module) == 0) {
        MWSFSVM_Error(lbl_12_rodata_1280);
        return 0;
    }
    return module->movie;
}
/* fzgx:end fn_12_34084 */

/* fzgx:begin fn_12_340D4 */
/* --- rel/movie_module/fn_12_340D4.c --- */


void fn_12_340D4(fn_12_340D4_MovieModule *self, void *value) {
    if (fn_12_3A36C(self, value) == 0) {
        MWSFSVM_Error(lbl_12_rodata_12B0);
    } else {
        self->field_54 = value;
    }
}
/* fzgx:end fn_12_340D4 */
