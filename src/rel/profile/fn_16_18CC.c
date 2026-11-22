#include "types.h"

struct ProfileBss8B614 {
    s16 unk_0;
    u8 pad_2[2];
    u32 unk_4;
    s16 unk_8;
    u16 unk_A;
    s16 unk_C;
    s16 unk_E;
    f32 unk_10, unk_14, unk_18, unk_1C, unk_20, unk_24;
    s16 unk_28;
    s16 unk_2A;
    u32 unk_2C;
    s16 unk_30;
    u8 pad_32[0x1A];
    u32 unk_4C;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
    u8 pad_56[2];
    s16 unk_58;
    s16 unk_5A;
    s32 unk_5C;
};
struct ProfilePad9F8 {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[4];
    u16 unk_10;
    u16 unk_12;
};
struct ProfileBss220Elem {
    u8 pad_0[0x324];
    u32 unk_324;
    u8 pad_328[0x118];
};
extern struct ProfileBss8B614 lbl_1_bss_8B614;
extern struct ProfilePad9F8 lbl_1_bss_9F8[];
extern struct ProfileBss220Elem lbl_16_bss_220[];
extern u32 lbl_16_bss_150;
extern u32 lbl_16_data_82B00;
extern const f32 lbl_16_rodata_0[22];
void fn_16_18CC(void);
s32 fn_16_1A24(void);
void fn_16_1D18(void);
void fn_16_1F1C(void);
void fn_16_2054(void);
s32 fn_16_20F4(void);
void fn_16_2328(void);
void fn_16_23A8(void);
void fn_16_24A4(u32 arg0);
s32 fn_16_24FC(void);
void fn_16_2528(void);
extern s32 fn_1_3F8C();
extern s32 fn_1_426C();
extern u32 fn_1_4A00();

/* --- rel/profile/fn_16_18CC.c --- */
#include "rel/profile/data/lbl_16_data_0.h"

typedef struct {
    s32 active;
    s32 entries[5];
} Sig_fn_1_8F494_Fn1_8F494_Object;

struct fn_16_18CC_Tbl {
    u32 unk_0[1];
};

/* save handles after the profile text data; retail addresses them off one base (data_0 + 0x80000) */
struct fn_16_18CC_ProfileHandles {
    u8 pad_0[0x2B00];
    s32 bioHandle;      /* 0x2B00 */
    s32 machineHandle;  /* 0x2B04 */
    s32 entryHandle[19];/* 0x2B08 */
    struct fn_16_18CC_Tbl tbl; /* 0x2B54 */
};

/* one 0x4E8-byte entry; the first one starts at the head of lbl_1_bss_8B614 */
struct fn_16_18CC_Entry {
    u8 pad_0[0xC];
    s16 unk_C;
    u8 pad_E[0x4A];
    s16 unk_58;
    u8 pad_5A[0x1A];
    Sig_fn_1_8F494_Fn1_8F494_Object obj; /* 0x74 */
    u8 pad_8C[0x4E8 - 0x8C];
};

struct fn_16_18CC_lbl_16_bss_220_elem {
    u8 pad_0[0x324];
    u32 unk_324;
    u8 pad_328[0x118];
};

extern u32 lbl_16_bss_14C;

extern u32 fn_1_435C(u32);
extern void fn_1_8F494(Sig_fn_1_8F494_Fn1_8F494_Object *);
extern s32 fn_1_12CB04(s16);
extern void fn_1_48140(int);
extern void fn_1_80F1C(s32, void *);

#pragma opt_propagation off
void fn_16_18CC(void) {
    struct fn_16_18CC_Entry *p;
    struct fn_16_18CC_ProfileHandles *d;
    struct { s32 value; } i;
    struct { s16 value; } idx;
    struct fn_16_18CC_lbl_16_bss_220_elem *e;
    /* one-member carriers: a constant address in a plain pointer is rematerialised */
    struct { struct fn_16_18CC_Entry *value; } ent;
    s32 *handles;
    u32 tb;
    Sig_fn_1_8F494_Fn1_8F494_Object * lab_t0;

    d = (struct fn_16_18CC_ProfileHandles *)((u8 *)&lbl_16_data_0 + 0x80000);
    if (d->bioHandle != -1) {
        fn_1_435C(lbl_16_bss_150);
        fn_1_426C(d->bioHandle);
        d->bioHandle = -1;
    }
    i.value = 0;
    p = (struct fn_16_18CC_Entry *)&lbl_1_bss_8B614;
    idx.value = p->unk_C;
    if (p->unk_58 == 4) {
        lab_t0 = &p->obj;
        fn_1_8F494(lab_t0);
        if (d->machineHandle != -1) {
            fn_1_435C(lbl_16_bss_14C);
            fn_1_426C(d->machineHandle);
            d->machineHandle = -1;
        }
        ent.value = (struct fn_16_18CC_Entry *)&lbl_1_bss_8B614;
        handles = d->entryHandle;
        for (i.value = 0; (s16)i.value < (s16)fn_1_12CB04(idx.value); i.value++) {
            fn_1_8F494(&ent.value[1].obj);
            if (*handles != -1) {
                fn_1_435C(lbl_16_bss_14C);
                fn_1_426C(*handles);
                *handles = -1;
            }
            ent.value++;
            handles++;
        }
        p->unk_58 = 0;
    }
    tb = (u32)d + 0x2B54;
    fn_1_48140(*(s32 *)(tb + p->unk_C * 4));
    e = &((struct fn_16_18CC_lbl_16_bss_220_elem *)lbl_16_bss_220)[p->unk_C];
    fn_1_80F1C((s16)e->unk_324, e);
}
#pragma opt_propagation reset


/* --- rel/profile/fn_16_1A24.c --- */
typedef struct Sig_fn_1_95120_Fn195120Data Sig_fn_1_95120_Fn195120Data;
typedef struct Sig_fn_1_95120_Fn195120Owner Sig_fn_1_95120_Fn195120Owner;
struct Sig_fn_1_95120_Fn195120Data { u8 unk_00[0x4C]; f32 value_50; f32 value_4C; };
struct Sig_fn_1_95120_Fn195120Owner { u8 unk_00[8]; Sig_fn_1_95120_Fn195120Data *data; };
typedef struct Sig_fn_1_41488_Fn41488Data { u32 count; char *strings; } Sig_fn_1_41488_Fn41488Data;
typedef struct { u8 pad0[0x1c]; void *field_1c; } Sig_fn_1_933D8_CarObject;
typedef struct { u8 pad0[0x24]; void *field_24; } Sig_fn_1_933D8_EventData;
typedef struct { u8 pad0[8]; Sig_fn_1_933D8_EventData *field_8; void *field_c; } Sig_fn_1_933D8_EventObject;
struct fn_16_1A24_lbl_1_bss_8B614 {
    s16 unk_0;
    u8 pad_2[6];
    s16 unk_8;
    u8 pad_A[2];
    s16 unk_C;
    s16 unk_E;
    u8 pad_10[0x20];
    s16 unk_30;
    u8 pad_32[0x1A];
    u32 unk_4C;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
};
struct fn_16_1A24_lbl_16_data_82B34 { u32 unk_0[8]; };
extern int fn_1_41488(Sig_fn_1_41488_Fn41488Data *, const char *);
extern s16 lbl_16_bss_860B8;
extern s32 fn_1_95120(Sig_fn_1_95120_Fn195120Owner *);
extern struct fn_16_1A24_lbl_16_data_82B34 lbl_16_data_82B34;
extern s32 fn_1_FA1A8(u32);
extern void fn_1_933D8(Sig_fn_1_933D8_CarObject *, Sig_fn_1_933D8_EventObject *, u32);
extern void fn_1_A2D84(u32);
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_loop_invariants off
s32 fn_16_1A24(void) {
    struct ProfileBss8B614 *p_lbl_1_bss_8B614;
    s32 v0;
    u16 *v1;
    u16 *v8;
    s32 v3;
    s32 v4;
    s16 v5;
    s16 v6;
    u8 *v14;
    int v12;
    s32 v13;
    u8 *v10;
    v3 = 0;
    v1 = (u16 *)&lbl_1_bss_9F8;
    v0 = lbl_1_bss_8B614.unk_8 * 20;
    v1 = (u16 *)((u8 *)v1 + v0);
    if (((*(v1 += 4) >> 9) & 1) != 0) {
        fn_1_A2D84(0xA9010200);
        return -1;
    }
    if (((*v1 >> 10) & 1) != 0) {
        fn_1_A2D84(0xA9010100);
        return 1;
    }
    if (((*v1 >> 11) & 1) != 0 && fn_1_FA1A8(lbl_1_bss_8B614.unk_C) == 1) {
        fn_1_A2D84(0xA9010100);
        return 2;
    }
    v8 = (u16 *)((u8 *)&lbl_1_bss_9F8 + v0);
    if (((*(v8 += 9) >> 8) & 1) != 0) v3 = 1;
    if (((*v8 >> 9) & 1) != 0) v3--;
    p_lbl_1_bss_8B614 = &lbl_1_bss_8B614;
    v4 = p_lbl_1_bss_8B614->unk_30 + (s16)v3;
    { s32 result;
      if (v4 > 3) result = 0;
      else { result = 3; if (v4 >= 0) result = v4; }
      p_lbl_1_bss_8B614->unk_30 = result;
    }
    if ((s16)v3 != 0) fn_1_A2D84(0xA9010000);
    v6 = lbl_16_bss_860B8 - 10;
    p_lbl_1_bss_8B614 = &lbl_1_bss_8B614;
    v5 = p_lbl_1_bss_8B614->unk_E;
    if (v6 > 0) {
        v3 = 0;
        v1 = (u16 *)((u8 *)&lbl_1_bss_9F8 + v0);
        if (((*(v1 += 8) >> 2) & 1) != 0 || ((*v8 >> 2) & 1) != 0) v3 = 1;
        if (((*v1 >> 3) & 1) != 0 || ((*v8 >> 3) & 1) != 0) v3--;
        v4 = p_lbl_1_bss_8B614->unk_E + (s16)v3;
        if (v4 < 0) v4 = 0;
        else if (v4 > v6) v4 = v6;
        p_lbl_1_bss_8B614->unk_E = v4;
    } else p_lbl_1_bss_8B614->unk_E = 0;
    if (v5 != p_lbl_1_bss_8B614->unk_E) {
        if ((lbl_1_bss_8B614.unk_4C & 0x80000000) == 0) {
            lbl_1_bss_8B614.unk_50 = v3;
            lbl_1_bss_8B614.unk_4C = 0;
            lbl_1_bss_8B614.unk_4C |= 0x80000000;
            lbl_1_bss_8B614.unk_4C |= 0x02000001;
            lbl_1_bss_8B614.unk_52 = 0;
            lbl_1_bss_8B614.unk_54 = v3 * 5;
        }
        fn_1_A2D84(0xA9010000);
    }
    if (*(s16 *)((u8 *)&lbl_1_bss_8B614 + 0x58) == 4) {
        v10 = (u8 *)&lbl_1_bss_8B614 + 0x74;
        if (fn_1_95120((Sig_fn_1_95120_Fn195120Owner *)(v10 + 0x148)) != 0) {
            v12 = fn_1_41488((Sig_fn_1_41488_Fn41488Data *)(*(Sig_fn_1_933D8_EventData **)(v10 + 0x150))->field_24,
                (const char *)lbl_16_data_82B34.unk_0[lbl_1_bss_8B614.unk_0]);
            fn_1_933D8((Sig_fn_1_933D8_CarObject *)v10, (Sig_fn_1_933D8_EventObject *)(v10 + 0x148), v12 & 0xffff);
            p_lbl_1_bss_8B614 = &lbl_1_bss_8B614;
            v14 = (u8 *)p_lbl_1_bss_8B614;
            for (v13 = 0; (s16)v13 < (s16)fn_1_12CB04(p_lbl_1_bss_8B614->unk_C); v13++) {
                fn_1_933D8((Sig_fn_1_933D8_CarObject *)(v14 + 0x55c), (Sig_fn_1_933D8_EventObject *)(v14 + 0x6a4), v12 & 0xffff);
                v14 += 0x4e8;
            }
            lbl_1_bss_8B614.unk_0++;
            lbl_1_bss_8B614.unk_0 &= 7;
        }
    }
    return 0;
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
#pragma opt_loop_invariants reset

/* --- rel/profile/fn_16_1D18.c --- */
#include "rel/profile/data/lbl_16_data_0.h"
struct State {
u8 pad0[12]; s16 index; u8 padE[2];
f32 a,b,c,d,e,f; s16 g,h; u32 i; s16 selection; u8 pad32[0x1A]; u32 flags; s16 j,k,l; u8 pad56[6]; s32 slot;
};
struct Entry {
u8 pad0[0x324]; s32 handle; u8 pad328[0x10]; void *objects[5][3]; u8 pad374[8]; u32 items[49];
};
struct Params { s16 a,b; u32 c; u8 d; u8 pad[23]; };
extern u32 lbl_16_bss_B0B4;
extern u32 lbl_16_bss_21C;
extern void fn_16_6B24(void);
extern s32 fn_1_80CC4(s32,s32,s32,void *);
extern void fn_80008BEC(void *,int,u32);
extern void fn_1_12AB38(void *);
extern void fn_1_80270(void *,void *);
extern void fn_800713E0(void *,u32);
extern void fn_1_8019C(void *);
extern void fn_1_47F74(s32);
#pragma opt_common_subs off
#pragma opt_propagation off
#define lbl_1_bss_8B614 (*(struct State *)&lbl_1_bss_8B614)
void fn_16_1D18(void) {
struct State *state;
u8 *data;
struct Entry *entry;
s16 index;
s32 offset;
struct Params params;
const f32 *pool = lbl_16_rodata_0;
data = (u8 *)&lbl_16_data_0 + 0x80000;
fn_1_435C(lbl_16_bss_150);
fn_1_4A00(1,15,lbl_16_bss_150);
lbl_16_bss_B0B4=0;
*(s32 *)(data+0x2B00)=fn_1_3F8C(data+0x2D84,fn_16_6B24,0,8);
state=(struct State *)&lbl_1_bss_8B614;
index=state->index;
lbl_16_bss_21C=-1;
state->a=pool[0];
state->b=pool[16];
state->c=pool[17];
state->d=pool[0];
state->e=pool[16];
state->f=pool[0];
state->g=330;
state->h=330;
offset=index*0x440;
entry=(struct Entry *)((u8 *)lbl_16_bss_220+offset);
((struct Entry *)((u8 *)lbl_16_bss_220+offset))->handle=(s16)fn_1_80CC4(index,0,0,entry);
fn_80008BEC(&params,0,32);
params.b=index;
params.c=0;
params.d=15;
params.a=index;
fn_1_12AB38(data+0x2D24);
fn_1_80270(&params,entry);
fn_1_12AB38(data+0x2D30);
{
struct State *second = (struct State *)&lbl_1_bss_8B614;
s32 off = state->index*0x440;
u8 *objects = (u8 *)lbl_16_bss_220+0x338;
fn_800713E0(*(void **)(objects+off+second->slot*12),((struct Entry *)((u8 *)lbl_16_bss_220+off))->items[second->selection]);
fn_1_8019C(*(void **)(objects+state->index*0x440+second->slot*12));
}
{
s32 *handles = (s32 *)(data+0x2B54);
fn_1_47F74(handles[state->index]);
}
lbl_1_bss_8B614.flags=0;
lbl_1_bss_8B614.flags|=0x80000000;
lbl_1_bss_8B614.flags|=0x10000000;
lbl_1_bss_8B614.j=1;
lbl_1_bss_8B614.k=0;
lbl_1_bss_8B614.l=15;
lbl_1_bss_8B614.i=0;
}


#undef lbl_1_bss_8B614
#pragma opt_common_subs reset
#pragma opt_propagation reset
/* --- rel/profile/fn_16_1F1C.c --- */

struct fn_16_1F1C_lbl_1_bss_8B614 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x44];
    u32 unk_4C;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
};

extern u16 lbl_1_bss_96A;
extern int fn_1_4C10(void);

#pragma opt_common_subs off
void fn_16_1F1C(void) {
    struct fn_16_1F1C_lbl_1_bss_8B614 *p;
    s32 v;
    u32 v0;
    s32 b;
    u32 v2;

    if ((s32)lbl_16_bss_21C == -1) {
        fn_1_4C10();
    }
    p = (struct fn_16_1F1C_lbl_1_bss_8B614 *)&lbl_1_bss_8B614;
    v0 = p->unk_4C;
    if ((v0 & 0x80000000) != 0 && (v0 & 0x1) == 0 && (p->unk_4 & 0x10000000) == 0) {
        b = 1;
    } else if (fn_1_4C10() != 0) {
        b = 1;
    } else {
        b = 0;
    }
    if (b == 0) {
        if ((s32)lbl_16_bss_21C != -1) {
            v2 = lbl_16_bss_21C;
            lbl_16_bss_21C = -1;
            lbl_1_bss_96A = v2;
        } else {
            v = fn_16_20F4();
            if ((s16)v != 0) {
                fn_1_4A00(0, 15, lbl_16_bss_150);
                p->unk_4C = 0;
                p->unk_4C |= 0x80000000;
                lbl_16_bss_B0B4 = 0;
                p->unk_4C |= 0x08000000;
                lbl_1_bss_8B614.unk_50 = 1;
                lbl_1_bss_8B614.unk_52 = 0;
                lbl_1_bss_8B614.unk_54 = 15;
            }
            if ((s16)v == -1) {
                lbl_16_bss_21C = 192;
            }
        }
    }
}
#pragma opt_common_subs reset


/* --- rel/profile/fn_16_2054.c --- */
struct fn_16_2054_lbl_16_bss_220_0_E1088 {
    u8 pad_0[0x324];
    u32 unk_324;
    u8 pad_328[0x118];
};
struct fn_16_2054_lbl_16_data_82B00 {
    u32 unk_0;
};
struct fn_16_2054_lbl_16_bss_150 {
    u32 unk_0;
};
struct fn_16_2054_lbl_1_bss_8B614 {
    u8 pad_0[0xC];
    s16 unk_C;
};
struct fn_16_2054_lbl_16_data_82B54 {
    u32 unk_0[1];
};
struct fn_16_2054_lbl_16_bss_220 {
    struct fn_16_2054_lbl_16_bss_220_0_E1088 unk_0[1];
};
extern struct fn_16_2054_lbl_16_data_82B54 lbl_16_data_82B54;



void fn_16_2054(void) {
    struct ProfileBss220Elem *temp_r4;

    if ((s32) lbl_16_data_82B00 != -1) {
        fn_1_435C(lbl_16_bss_150);
        fn_1_426C(lbl_16_data_82B00);
        lbl_16_data_82B00 = -1U;
    }
    fn_1_48140((*(s32 *)&((&lbl_16_data_82B54)[lbl_1_bss_8B614.unk_C])));
    temp_r4 = &lbl_16_bss_220[lbl_1_bss_8B614.unk_C];
    fn_1_80F1C(((s16) temp_r4->unk_324), temp_r4);
}

/* --- rel/profile/fn_16_20F4.c --- */
struct fn_16_20F4_9F8 {
    u16 unk_0;
    u8 pad_2[0x6];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[0x6];
    u16 unk_12;
};
struct fn_16_20F4_8B614 {
    u8 pad_0[0x8];
    s16 unk_8;
    u8 pad_A[0xE];
    f32 unk_18;
    u8 pad_1C[0xC];
    s16 unk_28;
    s16 unk_2A;
    u32 unk_2C;
    s16 unk_30;
};
struct fn_16_20F4_A48 {
    s8 unk_0;
    s8 unk_1;
    u8 pad_2[0xE];
};
struct fn_16_20F4_BF0 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x10];
};
extern struct fn_16_20F4_A48 lbl_1_bss_A48[];
extern struct fn_16_20F4_BF0 lbl_1_bss_BF0[];
#pragma opt_propagation off
static inline const f32 *fn_16_20F4_array_read(const f32 *array) { return array; }
s32 fn_16_20F4(void) {
    u16 * p; /* Controller flags are read on each test. */
    volatile u16 *q;
    s32 idx = lbl_1_bss_8B614.unk_8;
    s16 flag = 0;
    s32 a;
    s32 b;
    s32 t;
    f32 v;
    const f32 *pool = lbl_16_rodata_0;
    a = lbl_1_bss_8B614.unk_2A + lbl_1_bss_A48[idx].unk_0 / 20;
    a = (a > 0x168) ? 0 : (a < 0 ? 0x168 : a);
    lbl_1_bss_8B614.unk_2A = a;
    b = lbl_1_bss_8B614.unk_28 + lbl_1_bss_A48[idx].unk_1 / 20;
    b = (b > 0x168) ? 0 : (b < 0 ? 0x168 : b);
    lbl_1_bss_8B614.unk_28 = b;
    v = lbl_1_bss_8B614.unk_18 + (f32)(lbl_1_bss_BF0[idx].unk_C * fn_16_20F4_array_read(pool)[6]);
    v = (v < fn_16_20F4_array_read(pool)[20]) ? fn_16_20F4_array_read(pool)[20]
      : (v > fn_16_20F4_array_read(pool)[21] ? fn_16_20F4_array_read(pool)[21] : v);
    lbl_1_bss_8B614.unk_18 = v;
    {
    s32 offset = idx * 20;
    p = (u16 *)((u8 *)lbl_1_bss_9F8 + offset);
    p += 4;
    if ((*p >> 4) & 1) {
        fn_1_A2D84(0xA9010000);
        lbl_1_bss_8B614.unk_2C = lbl_1_bss_8B614.unk_2C != 1;
    }
    q = (u16 *)((u32)lbl_1_bss_9F8 + offset + 18);
    }
    if ((*q >> 8) & 1) {
        flag = 1;
    }
    if ((*q >> 9) & 1) {
        flag--;
    }
    if (flag != 0) {
        t = lbl_1_bss_8B614.unk_30 + flag;
        t = (t > 3) ? 0 : (t < 0 ? 3 : t);
        lbl_1_bss_8B614.unk_30 = t;
        fn_1_A2D84(0xA9010000);
    }
    if ((*p >> 9) & 1) {
        fn_1_A2D84(0xA9010000 + 0x200);
        return -1;
    }
    return 0;
}
#pragma opt_propagation reset


/* --- rel/profile/fn_16_2328.c --- */

extern u32 lbl_16_data_82D98;
extern void fn_16_6CD8(void);

struct fn_16_2328_lbl_16_bss_150 {
    u32 unk_0;
};

void fn_16_2328(void) {
    u32 t2;
    fn_1_435C(lbl_16_bss_150);
    fn_1_4A00(1, 15, lbl_16_bss_150);
    lbl_16_bss_B0B4 = 0;
    t2 = fn_1_3F8C((u32)&lbl_16_data_82D98, (u32)fn_16_6CD8, 0, 8);
    lbl_16_data_82B00 = t2;
    lbl_16_bss_21C = -1;
}

/* --- rel/profile/fn_16_23A8.c --- */

struct fn_16_23A8_lbl_1_bss_8B614 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x44];
    u32 unk_4C;
};


#pragma opt_common_subs off
void fn_16_23A8(void) {
    u32 v0;
    s32 r;

    if ((s32)lbl_16_bss_21C == -1) {
        fn_1_4C10();
    }
    v0 = lbl_1_bss_8B614.unk_4C;
    if ((v0 & 0x80000000) != 0 && (v0 & 0x1) == 0
        && (lbl_1_bss_8B614.unk_4 & 0x10000000) == 0) {
        r = 1;
    } else {
        if (fn_1_4C10()) {
            r = 1;
        } else {
            r = 0;
        }
    }
    if (!r) {
        if ((s32)lbl_16_bss_21C != -1) {
            u32 t = lbl_16_bss_21C;
            lbl_16_bss_21C = -1;
            lbl_1_bss_96A = t;
        } else {
            r = fn_16_24FC();
            if ((s16)r != 0) {
                fn_1_4A00(0, 15, lbl_16_bss_150);
                lbl_16_bss_B0B4 = 0;
            }
            if ((s16)r == -1) {
                lbl_16_bss_21C = 192;
            }
        }
    }
}
#pragma opt_common_subs reset


/* --- rel/profile/fn_16_24A4.c --- */

struct fn_16_24A4_lbl_16_data_82B00 {
    u32 unk_0;
};


void fn_16_24A4(u32 arg0) {
    u32 v0;
    u32 t0, t1;
    v0 = arg0;
    if ((s32)lbl_16_data_82B00 != -1) {
    v0 = (u32)&lbl_16_bss_150;
    v0 = *(u32 *)(v0);
    t0 = fn_1_435C(v0);
    v0 = t0;
    v0 = (u32)&lbl_16_data_82B00;
    v0 = *(u32 *)(v0);
    t1 = fn_1_426C(v0);
    v0 = t1;
    lbl_16_data_82B00 = -1;
    }
}

/* --- rel/profile/fn_16_24FC.c --- */


struct fn_16_24FC_lbl_1_bss_9F8_0_E20 {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0xA];
};
struct fn_16_24FC_lbl_1_bss_8B614 {
    u8 pad_0[0x8];
    s16 unk_8;
};
struct fn_16_24FC_lbl_1_bss_9F8 {
    struct fn_16_24FC_lbl_1_bss_9F8_0_E20 unk_0[1];
};

s32 fn_16_24FC(void) {
    return (-((lbl_1_bss_9F8[lbl_1_bss_8B614.unk_8].unk_8 >> 9) & 0x1));
}

/* --- rel/profile/fn_16_2528.c --- */

extern struct fn_16_2528_lbl_16_bss_860C0 lbl_16_bss_860C0;
extern u32 fn_80074188(u32, u32, u32, u32);

struct fn_16_2528_lbl_16_bss_860C0 {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
};

void fn_16_2528(void) {
    fn_80074188(lbl_16_bss_860C0.unk_0, lbl_16_bss_860C0.unk_2, lbl_16_bss_860C0.unk_4, lbl_16_bss_860C0.unk_6);
}
