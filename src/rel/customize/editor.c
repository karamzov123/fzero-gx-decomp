#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/editor.h"


extern struct Obj *fn_3_14074(void);
extern u8 lbl_3_bss_A2408[8];
extern void *fn_1_45D0(void *, u32, char *, u32);
extern void fn_80008BEC(void *, u32, u32);
extern void fn_3_17100(void);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, char *, int);
extern const f32 lbl_3_rodata_5FC[3];

/* fzgx:begin fn_3_1552C */
struct Obj {
    u8 pad[0x10];
    u16 width;
    u16 height;
};

void fn_3_1552C(void) {
    struct Obj *ptr;

    ptr = fn_3_14074();
    ptr->width = 0x20;
    ptr->height = 0x20;
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0xC) = 0x20000000;
    *(u8 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x11) = 1;
    *(u8 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x16) = 0;
    *(u8 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x0) = 0;
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x4) =
        (u32)fn_1_45D0((*(void * *)&lbl_801A6410), 0x2000, (*(char (*)[9])&lbl_3_data_35B0), 0x4A);
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x8) =
        (u32)fn_1_45D0((*(void * *)&lbl_801A6410), 0x2000, (*(char (*)[9])&lbl_3_data_35B0), 0x4B);
    fn_80008BEC(*(void **)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x4), 0, 0x2000);
    fn_80008BEC(*(void **)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x8), 0, 0x2000);
    *lbl_3_bss_A2408 = 0;
}
/* fzgx:end fn_3_1552C */

/* fzgx:begin fn_3_1560C */
void fn_3_1560C(void) {
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0xC) = (u32)1 << 31;
}
/* fzgx:end fn_3_1560C */

/* fzgx:begin fn_3_15620 */
void fn_3_15620(void) {
    *(u8 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x10) = 0;
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0xc) = 0x40000000;
}
/* fzgx:end fn_3_15620 */

/* fzgx:begin fn_3_1563C */
void fn_3_1563C(void) {
    fn_1_46B4(lbl_801A6410, *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x4),
              (*(char (*)[9])&lbl_3_data_35B0), 0x71);
    fn_1_46B4(lbl_801A6410, *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x8),
              (*(char (*)[9])&lbl_3_data_35B0), 0x72);
}
/* fzgx:end fn_3_1563C */

/* fzgx:begin fn_3_156A8 */
void fn_3_156A8(void) {
    u8 value = ((*(u8 (*)[28])&lbl_3_bss_A23EC)[0x11] & 0x7f) << 1;
    (*(u8 (*)[28])&lbl_3_bss_A23EC)[0x11] = value;
    if (value > 6) {
        (*(u8 (*)[28])&lbl_3_bss_A23EC)[0x11] = 1;
    }
}
/* fzgx:end fn_3_156A8 */

/* fzgx:begin fn_3_156D0 */
extern struct Obj *fn_3_14074(void);
extern u8 lbl_3_bss_A2408[8];
extern void *fn_1_45D0(void *, u32, char *, u32);
extern void fn_80008BEC(void *, u32, u32);
extern void fn_3_17100(void);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, char *, int);
extern const f32 lbl_3_rodata_5FC[3];



extern struct Obj *fn_3_14074(void);
extern void fn_80008BEC(void *, u32, u32);

struct Obj {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    s16 unk_12;
    u8 pad_14[8];
    u8 unk_1C;
    u8 pad_1D[3];
    void *unk_20;
};
extern struct Obj *fn_3_14074(void);
extern u8 fn_3_19C94(void);
extern void fn_3_169B8(void);
extern u32 fn_3_17820(void);
extern void fn_3_1445C(void);
extern u8 fn_3_14600(void);
extern u32 fn_3_19F7C(void *, s32, s32);
extern void fn_3_17830(void);
extern void fn_3_177AC(void *);
extern void fn_3_16FD0(void *);
extern void fn_3_19CA4(void);
extern void fn_3_19CCC(void);
extern void fn_80008BEC(void *, u32, u32);
extern void DCInvalidateRange(void *, u32);
extern void DCStoreRange(void *, u32);
extern void fn_1_A2D84(u32);
extern u8 lbl_1_bss_9F8[];
struct Input { u16 unk_0; u8 pad_2[18]; };

typedef void (*EditorFunc)(struct Obj *);
#define BUF ((void **)&lbl_3_bss_A23EC.unk_4)[(lbl_3_bss_A23EC.unk_0 + 1) % 2]
#define CALL(n) (((EditorFunc *)&lbl_3_data_3738)[n])(obj)
#define INPUT(off) (((u16 *)(lbl_1_bss_9F8 + (off)))[state.ptr->unk_12 * 10])
#define BIT(off, n) ((INPUT(off) >> (n)) & 1)

void fn_3_156D0(void) {
    struct Obj *obj;
    struct { Obj_3_bss_A23EC *ptr; } state;
    void *saved;
    u32 color;
    u32 copy;
    obj = fn_3_14074();
    fn_80008BEC(BUF, 0, 0x2000);
    if (!(lbl_3_bss_A23EC.unk_C & 0x20000000)) {
        if (fn_3_19C94() != 9 && fn_3_19C94() != 10)
            fn_3_169B8();
        else
            obj->unk_1C = fn_3_19C94();
        if ((((u16 *)(lbl_1_bss_9F8 + 8))[(state.ptr = &lbl_3_bss_A23EC)->unk_12 * 10] >> 8 & 1) && (lbl_3_bss_A23EC.unk_C & 0x40000000)) {
            obj = fn_3_14074();
            saved = obj->unk_20;
            obj->unk_20 = BUF;
            obj->unk_8 = fn_3_17820();
            CALL(0);
            obj->unk_20 = saved;
            lbl_3_bss_A23EC.unk_C = 0x80000000;
            return;
        }
        /* Sample the controller index again for the held-button state. */
        if (((((struct Input *)lbl_1_bss_9F8)[((volatile Obj_3_bss_A23EC *)state.ptr)->unk_12].unk_0 >> 8) & 1) && (lbl_3_bss_A23EC.unk_C & 0x80000000)) {
            switch (obj->unk_1C) {
            case 1:
                obj->unk_8 = fn_3_17820();
                CALL(obj->unk_1C);
                if (lbl_3_bss_A23EC.unk_16 > 39) {
                    obj->unk_0 |= 0x04000000;
                    fn_3_1445C();
                    lbl_3_bss_A23EC.unk_16 = 0;
                } else if (!fn_3_14600()) {
                    lbl_3_bss_A23EC.unk_16++;
                }
                break;
            case 0:
                obj->unk_8 = fn_3_17820();
                CALL(obj->unk_1C);
                if (lbl_3_bss_A23EC.unk_16 > 39) {
                    obj->unk_0 |= 0x04000000;
                    fn_3_1445C();
                    lbl_3_bss_A23EC.unk_16 = 0;
                } else if (!fn_3_14600()) {
                    lbl_3_bss_A23EC.unk_16++;
                }
                return;
            }
        }
        if (BIT(8, 8) && (lbl_3_bss_A23EC.unk_C & 0x80000000)) {
            obj->unk_8 = fn_3_17820();
            switch (obj->unk_1C) {
            case 2:
                CALL(obj->unk_1C);
                fn_3_1445C();
                break;
            case 3: case 4: case 5: case 7: case 8:
                if (!lbl_3_bss_A23EC.unk_10) {
                    obj->unk_C = obj->unk_10;
                    obj->unk_E = obj->unk_12;
                    lbl_3_bss_A23EC.unk_10 = 1;
                } else {
                    lbl_3_bss_A23EC.unk_10 = 0;
                    DCInvalidateRange(BUF, 0x2000);
                    CALL(obj->unk_1C);
                    DCStoreRange(BUF, 0x2000);
                    fn_3_1445C();
                }
                break;
            }
        }
        if (obj->unk_1C == 9) {
            if ((INPUT(8) & 1) || (INPUT(10) & 1)) obj->unk_4 |= 0x20000000;
            if (BIT(8, 1) || BIT(10, 1)) obj->unk_4 |= 0x10000000;
            CALL(fn_3_19C94());
        }
        if (obj->unk_1C == 10) {
            if ((INPUT(8) & 1) || (INPUT(10) & 1)) obj->unk_4 |= 0x20000000;
            if (BIT(8, 1) || BIT(10, 1)) obj->unk_4 |= 0x10000000;
            if (BIT(8, 3) || BIT(10, 3)) obj->unk_4 |= 0x80000000;
            if (BIT(8, 2) || BIT(10, 2)) obj->unk_4 |= 0x40000000;
            CALL(fn_3_19C94());
        }
    }
    if ((((u16 *)(lbl_1_bss_9F8 + 8))[(state.ptr = &lbl_3_bss_A23EC)->unk_12 * 10] >> 10 & 1)) {
        color = fn_3_19F7C(obj->unk_20, obj->unk_10, obj->unk_12);
        obj->unk_8 = color;
        if (((u8 *)&color)[3]) {
            fn_3_17830();
            copy = color;
            fn_3_177AC(&copy);
        }
    }
    switch (obj->unk_1C) {
    case 3: case 4: case 5: case 7: case 8:
        if (lbl_3_bss_A23EC.unk_10) {
            saved = obj->unk_20;
            obj->unk_20 = BUF;
            obj->unk_8 = fn_3_17820();
            DCInvalidateRange(BUF, 0x2000);
            if (obj->unk_1C == 7) CALL(4);
            else if (obj->unk_1C == 8) CALL(5);
            else CALL(obj->unk_1C);
            fn_3_16FD0(BUF);
            DCStoreRange(BUF, 0x2000);
            obj->unk_20 = saved;
        } else {
            obj->unk_8 = fn_3_17820();
            saved = obj->unk_20;
            obj->unk_20 = BUF;
            CALL(0);
            obj->unk_20 = saved;
        }
        break;
    default:
        saved = obj->unk_20;
        obj->unk_8 = fn_3_17820();
        obj->unk_20 = BUF;
        CALL(0);
        obj->unk_20 = saved;
        break;
    }
    if (BIT(8, 9)) {
        fn_1_A2D84(0xA9150500);
        switch (obj->unk_1C) {
        case 3: case 4: case 5: case 7: case 8:
            if (!lbl_3_bss_A23EC.unk_10) {
                lbl_3_bss_A23EC.unk_10 = 0;
                lbl_3_bss_A23EC.unk_C = 0x20000000;
                fn_3_19CA4();
            } else {
                lbl_3_bss_A23EC.unk_10 = 0;
            }
            break;
        case 0: case 1: case 9: case 10:
            fn_3_1445C();
        default:
            lbl_3_bss_A23EC.unk_10 = 0;
            lbl_3_bss_A23EC.unk_C = 0x20000000;
            fn_3_19CCC();
            break;
        }
    }
    obj->unk_4 = 0;
}
/* fzgx:end fn_3_156D0 */

/* fzgx:begin fn_3_15F44 noprologue */
#include "types.h"
#include "font.h"
#include "rel/customize/editor.h"

struct Sig_fn_3_1683C_Arg0 {
    u8 pad_0[4];
    f32 unk_4;
    f32 unk_8;
};
typedef struct { u32 unk_0; } Sig_fn_1_4FC50_InputObject;
struct fn_3_15F44_Copy88 {
    union {
        u32 a[22];
        struct {
            u8 pad_0[0x50];
            void (*callback)(void);
            u32 unk_54;
        } named;
    };
};
struct fn_3_15F44_lbl_3_rodata_538 {
    u8 pad_0[4];
    f32 unk_4, unk_8, unk_C, unk_10, unk_14;
    f32 unk_18, unk_1C, unk_20, unk_24, unk_28;
    f32 unk_2C, unk_30, unk_34, unk_38, unk_3C;
    f32 unk_40, unk_44, unk_48, unk_4C, unk_50;
    f32 unk_54, unk_58, unk_5C, unk_60, unk_64, unk_68, unk_6C;
    f64 unk_70, unk_78;
};
struct fn_3_15F44_lbl_801A66A0 { u32 unk_0; };
extern f32 lbl_8006D188(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_4FC50(Sig_fn_1_4FC50_InputObject *, u32, u16, u16, u32);
extern struct fn_3_15F44_lbl_3_rodata_538 lbl_3_rodata_538;
extern struct fn_3_15F44_lbl_801A66A0 lbl_801A66A0;
extern u16 fn_1_48690(u32);
extern u32 fn_1_52690();
extern u32 fn_3_17820(void);
extern u32 lbl_1_rodata_26F8;
extern u8 *fn_3_14074(void);
extern void GXInvalidateTexAll(void);
extern void fn_1_517EC(FontDrawPacket *, s16, s16, s16, s16, s16, s16);
extern void fn_3_1683C(struct Sig_fn_3_1683C_Arg0 *, s16, s16);
extern void fn_3_16E14(s16, s16);

#define PF(off) (*(f32 *)((u8 *)&loc_C + (off)))
#define PB(off) (*((u8 *)&loc_C + (off)))

const u32 fzgx_pool_table_0[1] = {0xFFFFFFFF};
static inline void fzgx_shared_pool_primer(f32 *p) {
    p[0] = 192.0f;
    p[1] = 105.0f;
    p[2] = 90.0f;
    p[3] = 32.0f;
    p[4] = 0.0f;
    p[5] = 184.0f;
    p[6] = 86.0f;
    p[7] = 100.0f;
    p[8] = 175.0f;
    p[9] = 88.0f;
    p[10] = 0.5f;
    p[11] = 10.0f;
    p[12] = 420.0f;
    p[13] = 334.0f;
    p[14] = 29.0f;
    p[15] = 320.0f;
    p[16] = 232.0f;
    p[17] = 50.0f;
    p[18] = 4.0f;
    p[19] = 480.0f;
    p[20] = 92.0f;
    p[21] = 1.0f;
    p[22] = 1.0714285373687744f;
    p[23] = 64.0f;
    p[24] = 65535.0f;
    p[25] = 119.0f;
    p[26] = 30.0f;
}

void fn_3_15F44(void) {
    struct fn_3_15F44_lbl_3_rodata_538 *p_lbl_3_rodata_538;
    Obj_3_bss_A23EC *p_lbl_3_bss_A23EC;
    Obj_3_bss_A23EC *p_flags;
    s32 v0, v1, v2;
    u32 *textures;
    s16 v3, v4, v5, v6;
    f32 v7, v8, v9, v10;
    u32 v11, v12;
    f32 v13, v14;
    f64 v15;
    f32 v16, v17;
    u32 v18;
    f32 v19;
    f64 v20;
    f32 v21, v23, v24, v25, v26, v27, v28;
    s16 v22;
    s32 v29;
    s16 v30;
    s32 v31;
    f64 v32;
    s16 v33;
    f32 v34;
    s32 v35;
    u8 v36;
    f32 v37, v38, v39, v40, v41, v42, v43, v44, v45;
    u32 v46;
    f64 v47;
    f32 v48;
    u8 v49, v50, v51;
    u32 v52;
    f32 v53;
    u32 v54, v55;
    s32 v56;
    u32 v57, v58;
    struct fn_3_15F44_Copy88 loc_C;
    u32 loc_8;
    u8 *t0;
    u16 t3;
    u32 t15;
    f32 t16;
    p_lbl_3_rodata_538 = &lbl_3_rodata_538;
    t0 = fn_3_14074();
    p_flags = &lbl_3_bss_A23EC;
    if ((p_flags->unk_C & 0x20000000) != 0) {
        v0 = p_flags->unk_14 - 1;
        p_flags->unk_14 = v0 < 0 ? 0 : v0 > 5 ? 5 : v0;
    } else {
        v1 = p_flags->unk_14 + 1;
        p_flags->unk_14 = v1 < 0 ? 0 : v1 > 5 ? 5 : v1;
    }
    v0 = 64 / (s32)(p_lbl_3_bss_A23EC = &lbl_3_bss_A23EC)->unk_11;
    v4 = *(s16 *)(t0 + 16);
    v6 = *(s16 *)(t0 + 18);
    v3 = (s16)(v0 / 2);
    v5 = (s16)(v0 / 2);
    if (v4 - v3 < 0) v4 = v3;
    else if (v4 + v3 >= 64) v4 = 64 - v3;
    if (v6 - v5 < 0) v6 = v5;
    else if (v6 + v5 >= 64) v6 = 64 - v5;

    loc_C = *(struct fn_3_15F44_Copy88 *)&lbl_1_rodata_26F8;
    v7 = 32.0f;
    v8 = 192.0f;
    v9 = 105.0f;
    v10 = 90.0f;
    v11 = 0x863A;
    v12 = 0x400000A;
    loc_C.a[0] = v11;
    PF(4) = v8; PF(8) = v9; PF(12) = v10;
    PF(16) = v7; PF(20) = v7;
    loc_C.a[12] = v12;
    PF(44) = 0.0f;
    loc_C.a[20] = (u32)fn_3_1683C;
    fn_1_4F734((FontDrawPacket *)&loc_C);

    loc_C = *(struct fn_3_15F44_Copy88 *)&lbl_1_rodata_26F8;
    v13 = 184.0f;
    v14 = 86.0f;
    loc_C.a[0] = 0x8607;
    PF(4) = v13; PF(8) = v14; PF(12) = 100.0f;
    loc_C.a[12] = 5;
    fn_1_4F734((FontDrawPacket *)&loc_C);
    t3 = fn_1_48690(loc_C.a[0]);
    v15 = 4503601774854144.0;
    PF(4) = (f32)(s32)((t3 & 0xFFFF) + 184);
    loc_C.a[12] |= 0x80000;
    fn_1_4F734((FontDrawPacket *)&loc_C);
    if ((*(u32 *)t0 & 0x80000000) != 0) fn_3_16E14(192, 105);

    loc_C = *(struct fn_3_15F44_Copy88 *)&lbl_1_rodata_26F8;
    v22 = lbl_3_bss_A23EC.unk_14;
    v16 = 175.0f;
    v17 = 88.0f;
    v18 = 0x8605;
    v19 = 90.0f;
    v20 = 4503601774854144.0;
    v21 = 0.5f;
    loc_C.a[0] = v18;
    PF(4) = v16; PF(8) = v17; PF(12) = v19;
    PF(44) = v21 + (f32)(v22 / 10.0f);
    loc_C.a[12] = 5;
    fn_1_4F734((FontDrawPacket *)&loc_C);
    v23 = 420.0f;
    v24 = 88.0f;
    PF(4) = v23; PF(8) = v24; PF(12) = 90.0f;
    loc_C.a[12] = 0x80005;
    fn_1_4F734((FontDrawPacket *)&loc_C);
    v25 = 175.0f;
    v26 = 334.0f;
    PF(4) = v25; PF(8) = v26; PF(12) = 90.0f;
    loc_C.a[12] = 0x100005;
    fn_1_4F734((FontDrawPacket *)&loc_C);
    v27 = 420.0f;
    v28 = 334.0f;
    PF(4) = v27; PF(8) = v28; PF(12) = 90.0f;
    loc_C.a[12] |= 0x80000;
    fn_1_4F734((FontDrawPacket *)&loc_C);

    loc_C = *(struct fn_3_15F44_Copy88 *)&lbl_1_rodata_26F8;
    v29 = p_lbl_3_bss_A23EC->unk_11;
    loc_C.a[0] = 0x8603;
    v30 = v4;
    v31 = v29 << 1;
    v32 = 4503601774854144.0;
    v33 = v6;
    v34 = (f32)(s32)(202 + 4 * (v29 * (v3 + (*(s16 *)(t0 + 16) - v30))) + v31);
    PF(4) = v34;
    v35 = 94 + 4 * (v29 * (v5 + (*(s16 *)(t0 + 18) - v33))) + v31;
    PF(8) = (f32)(s32)v35;
    PF(12) = 29.0f;
    loc_C.a[12] = 10;
    fn_1_4F734((FontDrawPacket *)&loc_C);
    GXInvalidateTexAll();

    loc_C = *(struct fn_3_15F44_Copy88 *)&lbl_1_rodata_26F8;
    v36 = p_lbl_3_bss_A23EC->unk_11;
    v37 = 320.0f;
    v38 = 232.0f;
    v39 = 4.0f;
    v40 = 50.0f;
    PF(4) = 320.0f;
    PF(8) = 232.0f; PF(12) = 50.0f;
    PF(16) = PF(20) = 4.0f * (f32)(u32)v36;
    loc_C.a[12] = 0x400000A;
    loc_C.named.callback = (void (*)(void))fn_1_52690;
    if (v36 > 1) fn_1_517EC((FontDrawPacket *)&loc_C, v30-v3, v33-v5, v3<<1, v5<<1, 64, 64);
    fn_1_4FC50((Sig_fn_1_4FC50_InputObject *)&loc_C, 5, 64, 64, *(u32 *)(t0 + 32));

    loc_C = *(struct fn_3_15F44_Copy88 *)&lbl_1_rodata_26F8;
    v42 = 480.0f;
    v43 = 92.0f;
    v44 = 50.0f;
    v45 = 1.0f;
    PF(4) = v42; PF(8) = v43; PF(12) = v44;
    PF(16) = v45; PF(20) = 1.0714285373687744f;
    loc_C.a[12] = 5;
    fn_1_4FC50((Sig_fn_1_4FC50_InputObject *)&loc_C, 5, 64, 64, *(u32 *)(t0 + 32));

    t15 = fn_3_17820();
    v46 = lbl_801A66A0.unk_0;
    v47 = 4503599627370496.0;
    v48 = 65535.0f;
    loc_8 = t15;
    v52 = (lbl_3_bss_A23EC.unk_17 * p_lbl_3_bss_A23EC->unk_11) & 0xFF;
    v53 = v48 * (f32)(u32)(v46 % 120);
    v54 = (lbl_3_bss_A23EC.unk_18 * p_lbl_3_bss_A23EC->unk_11) & 0xFF;
    v56 = (s32)(64.0f * (f32)(1.0f + lbl_8006D188((s32)(v53 / 119.0f))));

    loc_C = *(struct fn_3_15F44_Copy88 *)&lbl_1_rodata_26F8;
    v36 = p_lbl_3_bss_A23EC->unk_11;
    PF(4) = 320.0f;
    PF(8) = 232.0f;
    PF(12) = 30.0f;
    PF(16) = PF(20) = 4.0f * (f32)(u32)v36;
    loc_C.a[12] = 10;
    loc_C.named.callback = (void (*)(void))fn_1_52690;
    if (!__rlwnm(p_flags->unk_C, 3, 31, 31)) {
        if (((u8 *)&loc_8)[0] >= 8 || ((u8 *)&loc_8)[1] >= 8 || ((u8 *)&loc_8)[2] >= 8)
            PB(0x38) = PB(0x39) = PB(0x3A) = 255 - v56;
        if (((u8 *)&loc_8)[0] < 248 || ((u8 *)&loc_8)[1] < 248 || ((u8 *)&loc_8)[2] < 248)
            PB(0x3C) = PB(0x3D) = PB(0x3E) = v56;
    } else {
        PB(0x38) = PB(0x39) = PB(0x3A) = 255;
        PB(0x3C) = PB(0x3D) = PB(0x3E) = 0;
    }
    if (p_lbl_3_bss_A23EC->unk_11 > 1)
        fn_1_517EC((FontDrawPacket *)&loc_C, v52 + (v30-v3), v54 + (v33-v5), v3<<1, v5<<1, 64, 64);
    textures = &lbl_3_bss_A23EC.unk_4;
    fn_1_4FC50((Sig_fn_1_4FC50_InputObject *)&loc_C, 5, 64, 64, textures[(lbl_3_bss_A23EC.unk_0 + 1) % 2]);

    loc_C = *(struct fn_3_15F44_Copy88 *)&lbl_1_rodata_26F8;
    PF(4) = 480.0f;
    PF(8) = 92.0f;
    PF(12) = 30.0f;
    PF(16) = 1.0f;
    PF(20) = 1.0714285373687744f;
    loc_C.a[12] = 5;
    if (!__rlwnm(p_flags->unk_C, 3, 31, 31)) {
        PB(0x38) = PB(0x39) = PB(0x3A) = 255 - (u8)v56 * 2;
        PB(0x3C) = PB(0x3D) = PB(0x3E) = (u8)((u8)v56 * 2);
    } else {
        PB(0x38) = PB(0x39) = PB(0x3A) = 255;
        PB(0x3C) = PB(0x3D) = PB(0x3A) = 0;
    }
    fn_1_4FC50((Sig_fn_1_4FC50_InputObject *)&loc_C, 5, 64, 64, textures[(lbl_3_bss_A23EC.unk_0 + 1) % 2]);
    lbl_3_bss_A23EC.unk_0 = (lbl_3_bss_A23EC.unk_0 + 1) % 2;
}
/* fzgx:end fn_3_15F44 */

/* fzgx:begin fn_3_1683C noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/editor.h"
#include "font.h"

typedef struct { u32 c; } Col4;

struct fn_3_156D0_Obj {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    s16 unk_12;
    u8 pad_14[8];
    u8 unk_1C;
    u8 pad_1D[3];
    void *unk_20;
};

typedef struct {
    u32 type;
    f32 x;
    f32 y;
    f32 z;
    f32 a;
    f32 b;
    u8 pad18[0x18];
    u32 mode;
    u8 pad34[8];
    u32 color;
    u8 pad40[0x18];
} Packet16E14;

struct fn_3_1552C_Obj {
    u8 pad[0x10];
    u16 width;
    u16 height;
};

typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} PadInput;

struct Obj {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    s16 unk_12;
    u8 pad_14[8];
    u8 unk_1C;
    u8 pad_1D[3];
    void *unk_20;
};
extern u8 *fn_3_14074(void);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u8 fn_3_19C94(void);
extern void fn_3_169B8(void);
extern u32 fn_3_17820(void);
extern void fn_3_1445C(void);
extern s32 fn_3_14600(void);
extern void fn_3_19F7C();
extern void fn_3_17830(void);
extern void fn_3_177AC(void *);
extern void fn_3_16FD0(u32 arg0);
extern void fn_3_19CA4(void);
extern void fn_3_19CCC(void);
extern void DCInvalidateRange(void *, u32);
extern void DCStoreRange(void *, u32);
extern void fn_1_A2D84(u32 arg0);
extern PadInput lbl_1_bss_9F8[];
extern u8 lbl_3_bss_A2408[8];
extern s32 fn_1_45D0();
extern u32 lbl_801A6410;
extern void fn_3_19CB8(void);
extern void fn_3_15620(void);
extern void fn_3_1560C(void);
extern const Col4 lbl_3_rodata_5B8;
extern const Col4 lbl_3_rodata_5BC;
extern s32 fn_1_A5DC4(void);
extern void fn_1_A9868();
extern u32 fn_1_A9FFC(s16, s16, s16, s16, void *);
extern void fn_1_AA538(void);
extern void fn_1_4E0F4(void);
extern const Packet16E14 lbl_1_rodata_26F8;
extern u8 lbl_3_rodata_538[];
extern Col4 lbl_3_rodata_5EC;
extern u32 fn_3_14794(u32, s16, s16, void *);
extern void fn_3_17100(void);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern const f32 lbl_3_rodata_5FC[3];

struct Arg0 {
    u8 pad_0[4];
    f32 unk_4;
    f32 unk_8;
};


void fn_3_1683C(struct Arg0 *arg0, s16 off, s16 size) {
    s16 x;
    s16 y;
    u8 i;
    u8 j;
    Col4 colA;
    Col4 colB;
    Obj_3_bss_A23EC *p = &lbl_3_bss_A23EC;
    x = arg0->unk_4;
    y = arg0->unk_8;
    off = 0;
    size = p->unk_11 << 3;
    colA = lbl_3_rodata_5B8;
    colB = lbl_3_rodata_5BC;
    if ((s8)fn_1_A5DC4()) {
        off = 4 / p->unk_11;
    }
    fn_1_A9868();
    for (i = 0; i < 256 / size; i++) {
        for (j = off; j < 256 / size - off; j++) {
            if (((i % 2) ^ (j % 2)) != 0) {
                Col4 t = colA;
                fn_1_A9FFC(x + size * j, y + size * i, size, size, &t);
            } else {
                Col4 t = colB;
                fn_1_A9FFC(x + size * j, y + size * i, size, size, &t);
            }
        }
    }
    fn_1_AA538();
    fn_1_4E0F4();
}
/* fzgx:end fn_3_1683C */

/* fzgx:begin fn_3_169B8 noprologue */
#include "dolphin/types.h"

extern const struct fn_3_169B8_lbl_3_rodata_538_pool {
    u8 pad_0[0x88];
    f32 unk_88;
    f32 unk_8C;
    f32 unk_90;
    f32 unk_94;
    f32 unk_98;
    f32 unk_9C;
} lbl_3_rodata_538;

typedef struct {
    f32 x;
    f32 y;
    u8 pad[0x18];
} StickInput;

typedef struct {
    u8 pad[0x10];
    s16 x;
    s16 y;
    u8 pad14[0x8];
    u8 result;
} Cursor;

typedef struct {
    u8 pad[0x11];
    u8 speed;
    volatile u8 port; /* fzgx-allow: S2 controller port is reread for each button query */
    u8 pad13[0x9];
} EditorInput;

typedef struct {
    u32 c;
} fzgx_Col4;

/* literal pool of the retail TU up to this function's constants, in retail order */
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer(s32 i, u32 u) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    volatile fzgx_Col4 c;  /* fzgx-allow: S2 pool primer sink */
    {
        fzgx_Col4 t = {0xFFFFFFFF};
        c = t;
    }
    s = 192.0f;
    s = 105.0f;
    s = 90.0f;
    s = 32.0f;
    s = 0.0f;
    s = 184.0f;
    s = 86.0f;
    s = 100.0f;
    s = 175.0f;
    s = 88.0f;
    s = 0.5f;
    s = 10.0f;
    s = 420.0f;
    s = 334.0f;
    s = 29.0f;
    s = 320.0f;
    s = 232.0f;
    s = 50.0f;
    s = 4.0f;
    s = 480.0f;
    s = 92.0f;
    s = 1.0f;
    s = 1.0714285f;
    s = 64.0f;
    s = 65535.0f;
    s = 119.0f;
    s = 30.0f;
    s = (f32)i;
    s = (f32)u;
}

static void fzgx_pool_primer2(void) {
    volatile fzgx_Col4 c;  /* fzgx-allow: S2 pool primer sink */
    {
        fzgx_Col4 t = {0x00000064};
        c = t;
    }
    {
        fzgx_Col4 t = {0x37373764};
        c = t;
    }
}
#pragma section code_type ".text"

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 lbl_3_bss_A23E8;
EditorInput fzgx_obj_lbl_3_bss_A23EC;
u8 fzgx_obj_lbl_3_bss_A2408;
s16 lbl_3_bss_A2408__fzgx_offset_2;
s16 lbl_3_bss_A2408__fzgx_offset_4;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_3_bss_A23E8;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_A23EC;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_A2408;
    s = *(u8 *)&lbl_3_bss_A2408__fzgx_offset_2;
    s = *(u8 *)&lbl_3_bss_A2408__fzgx_offset_4;
}
#pragma section code_type ".text"

extern StickInput lbl_1_bss_BF0[];
extern u8 lbl_1_bss_9F8[];
extern u8 *fn_3_14074(void);
extern u8 fn_3_19C94(void);

#define SPEED (fzgx_obj_lbl_3_bss_A23EC.speed)
#define PORT (fzgx_obj_lbl_3_bss_A23EC.port)
#define PORT2 (((EditorInput *)&fzgx_obj_lbl_3_bss_A23EC)->port)
/* one bit of a controller's held-button word (0x14-byte pad records) */
#define BUTTON(p, n) ((((u16 *)(lbl_1_bss_9F8 + 0x10))[(p) * 10] >> (n)) & 1)
#define CLAMP_POS(v) ((v) < 1 ? 1 : ((v) > 62 ? 62 : (v)))

#pragma opt_propagation off
void fn_3_169B8(void)
{
    struct fn_3_169B8_lbl_3_rodata_538_pool *pool_lbl_3_rodata_538 = (struct fn_3_169B8_lbl_3_rodata_538_pool *)&lbl_3_rodata_538;
    Cursor *cursor;
    u8 moved;
    f32 x;
    f32 y;
    s32 v;
    s16 half;
    u32 port;

    moved = 0;
    cursor = (Cursor *)fn_3_14074();
    port = PORT;
    fzgx_obj_lbl_3_bss_A2408++;
    x = ((port)[lbl_1_bss_BF0]).x;
    y = ((port)[lbl_1_bss_BF0]).y;

    if ((x < pool_lbl_3_rodata_538->unk_88 && (fzgx_obj_lbl_3_bss_A2408 % (SPEED + 6)) == 0) ||
        (x < pool_lbl_3_rodata_538->unk_8C && (fzgx_obj_lbl_3_bss_A2408 % (SPEED + 4)) == 0) ||
        (x < pool_lbl_3_rodata_538->unk_90 && (fzgx_obj_lbl_3_bss_A2408 % 4) == 0) ||
        BUTTON(port, 0)) {
        moved = 1;
        v = cursor->x - 1;
        cursor->x = CLAMP_POS(v);
        lbl_3_bss_A23E8 = 1;
    } else if ((x > pool_lbl_3_rodata_538->unk_94 && (fzgx_obj_lbl_3_bss_A2408 % (SPEED + 6)) == 0) ||
               (x > pool_lbl_3_rodata_538->unk_98 && (fzgx_obj_lbl_3_bss_A2408 % (SPEED + 4)) == 0) ||
               (x > pool_lbl_3_rodata_538->unk_9C && (fzgx_obj_lbl_3_bss_A2408 % 4) == 0) ||
               BUTTON(PORT, 1)) {
        moved = 1;
        v = cursor->x + 1;
        cursor->x = CLAMP_POS(v);
        lbl_3_bss_A23E8 = 1;
    }

    if ((y > pool_lbl_3_rodata_538->unk_94 && (fzgx_obj_lbl_3_bss_A2408 % (SPEED + 6)) == 0) ||
        (y > pool_lbl_3_rodata_538->unk_98 && (fzgx_obj_lbl_3_bss_A2408 % (SPEED + 4)) == 0) ||
        (y > pool_lbl_3_rodata_538->unk_9C && (fzgx_obj_lbl_3_bss_A2408 % 4) == 0) ||
        BUTTON(PORT, 3)) {
        moved = 1;
        v = cursor->y - 1;
        cursor->y = CLAMP_POS(v);
        lbl_3_bss_A23E8 = 1;
    } else if ((y < pool_lbl_3_rodata_538->unk_88 && (fzgx_obj_lbl_3_bss_A2408 % (SPEED + 6)) == 0) ||
               (y < pool_lbl_3_rodata_538->unk_8C && (fzgx_obj_lbl_3_bss_A2408 % (SPEED + 4)) == 0) ||
               (y < pool_lbl_3_rodata_538->unk_90 && (fzgx_obj_lbl_3_bss_A2408 % 4) == 0) ||
               BUTTON(PORT, 2)) {
        moved = 1;
        v = cursor->y + 1;
        cursor->y = CLAMP_POS(v);
        lbl_3_bss_A23E8 = 1;
    }

    if (moved) {
        fzgx_obj_lbl_3_bss_A2408 = 1;
    }

    half = (64 / SPEED) / 2;
    if (lbl_3_bss_A2408__fzgx_offset_2 + half / 2 < 63 || lbl_3_bss_A2408__fzgx_offset_2 - half / 2 > 0) {
        lbl_3_bss_A2408__fzgx_offset_2 = cursor->x;
    }
    {
        s32 half2 = half;
        if (lbl_3_bss_A2408__fzgx_offset_4 + half2 / 2 < 63 || lbl_3_bss_A2408__fzgx_offset_4 - half2 / 2 > 0) {
            lbl_3_bss_A2408__fzgx_offset_4 = cursor->y;
        }
    }

    cursor->result = fn_3_19C94();
}
/* fzgx:end fn_3_169B8 */

/* fzgx:begin fn_3_16E14 */
#include "font.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 192.0f;
    s = 105.0f;
    s = 90.0f;
    s = 32.0f;
    s = 0.0f;
    s = 184.0f;
    s = 86.0f;
    s = 100.0f;
    s = 175.0f;
    s = 88.0f;
    s = 0.5f;
    s = 10.0f;
    s = 420.0f;
    s = 334.0f;
    s = 29.0f;
    s = 320.0f;
    s = 232.0f;
    s = 50.0f;
    s = 4.0f;
    s = 480.0f;
    s = 92.0f;
    s = 1.0f;
    s = 1.0714285373687744f;
    s = 64.0f;
    s = 65535.0f;
    s = 119.0f;
    s = 30.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[1] = {0x00000064};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0920546628767624e-05f;
    s = -0.25f;
    s = -0.6000000238418579f;
    s = -0.949999988079071f;
    s = 0.25f;
    s = 0.6000000238418579f;
    s = 0.949999988079071f;
}
static const u32 fzgx_pool_table5[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 28.0f;
    s = 0.05999999865889549f;
    s = 10.680000305175781f;
    s = 0.03999999910593033f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern s32 lbl_1_rodata_26F8;
extern int fn_1_4F734(FontDrawPacket *);

typedef struct {
	s32 unk_0;
	f32 unk_4;
	f32 unk_8;
	f32 unk_C;
	f32 unk_10;
	f32 unk_14;
	u8 pad_18[0x18];
	u32 unk_30;
	u8 pad_34[0x8];
	u32 unk_3C;
	u8 pad_40[0x18];
} DrawPacket;

#pragma opt_dead_assignments off
#pragma opt_propagation on
#pragma opt_common_subs off
#pragma opt_lifetimes on
#pragma opt_loop_invariants off
void fn_3_16E14(void) {
	u32 fzgx_value;
	s32 width;
	s32 hi;
	DrawPacket pkt;
	s32 lo;
	s32 count;
	u32 i;
	u32 n;
	u8 c;

	count = (0x100 / (u16)(0x40 / lbl_3_bss_A23EC.unk_11) - 1) & 0xFF;
	width = (u16)(0x40 / lbl_3_bss_A23EC.unk_11);
	pkt = *(DrawPacket *)&lbl_1_rodata_26F8;
	pkt.unk_0 = 0xC;
	fzgx_value = 5;
	pkt.unk_30 = fzgx_value;
	lo = (count >> 1) & 0x7F;
	hi = lo + 5;
	pkt.unk_C = 28.0f;
	pkt.unk_3C = fzgx_pool_table5[0];
	{
    s32 fzgx_loop_i_3181;
for (fzgx_loop_i_3181 = 0; (u8)fzgx_loop_i_3181 < (u8)count; fzgx_loop_i_3181++) {
		c = (u8)fzgx_loop_i_3181;

		n = ((u8)fzgx_loop_i_3181 + 1) * width;
		pkt.unk_4 = (f32)(s32)(n + 191);
		pkt.unk_8 = 105.0f;
		pkt.unk_10 = 0.06f;
		pkt.unk_14 = 10.68f;
		fn_1_4F734((FontDrawPacket *)&pkt);
		pkt.unk_4 = 192.0f;
		pkt.unk_8 = (f32)(s32)(n + 104);
		pkt.unk_10 = 10.68f;
		if (c >= lo && c < hi) {
			pkt.unk_14 = 0.04f;
		} else {
			pkt.unk_14 = 0.06f;
		}
		fn_1_4F734((FontDrawPacket *)&pkt);
	}
    i = fzgx_loop_i_3181;
}
}
#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset

#pragma opt_common_subs reset

#pragma opt_propagation reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_3_16E14 */

/* fzgx:begin fn_3_16FD0 */
typedef struct BorderColor { u8 r, g, b, a; } BorderColor;
extern BorderColor lbl_3_rodata_5EC;
extern u32 fn_3_14794(u32, s16, s16, void *);

void fn_3_16FD0(u32 arg0) {
    BorderColor color = lbl_3_rodata_5EC;
    u32 i;
    for (i = 0; i < 64; i++) {
        BorderColor top = color;
        fn_3_14794(arg0, (s16)i, 0, &top);
        {
            BorderColor bottom = color;
            fn_3_14794(arg0, (s16)i, 63, &bottom);
        }
    }
    for (i = 0; i < 64; i++) {
        BorderColor left = color;
        fn_3_14794(arg0, 0, (s16)i, &left);
        {
            BorderColor right = color;
            fn_3_14794(arg0, 63, (s16)i, &right);
        }
    }
}
/* fzgx:end fn_3_16FD0 */

/* fzgx:begin fn_3_17098 */
#pragma opt_propagation off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */

#pragma opt_common_subs off
#pragma peephole off
void fn_3_17098(void) {
    u32 *b = (u32 *)&lbl_3_bss_A2410;
    s32 c = 0x40000000;
    b[2] = c;
{
    s8 i = 0;
    ((u8 *)b)[0xC] = i;
    b[1] = *(u32 *)((u8 *)&lbl_3_data_35C0 + (i * 4));
    ((u16 *)b)[8] = i;
    ((u16 *)b)[9] = i;
    ((u16 *)b)[10] = i;
    ((u16 *)b)[11] = 0xFF;
    ((u16 *)b)[16] = i;
}
}
#pragma peephole reset

#pragma opt_common_subs reset
/* fzgx:end fn_3_17098 */

/* fzgx:begin fn_3_170E0 */
void fn_3_170E0(void) {
    fn_3_17100();
}
/* fzgx:end fn_3_170E0 */

/* fzgx:begin fn_3_17100 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/editor.h"
#include "types.h"
#include "rel/customize/editor.h"

extern struct Obj *fn_3_14074(void);
extern u8 lbl_3_bss_A2408[8];
extern void *fn_1_45D0(void *, u32, char *, u32);
extern void fn_80008BEC(void *, u32, u32);
extern void fn_3_17100(void);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, char *, int);
extern const f32 lbl_3_rodata_5FC[3];


struct fn_3_17100_lbl_1_bss_BF0_0_E32 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
};
struct fn_3_17100_lbl_3_rodata_5F0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    f32 unk_C;
    f64 unk_10;
};
struct fn_3_17100_lbl_1_bss_BF0 {
    struct fn_3_17100_lbl_1_bss_BF0_0_E32 unk_0[1];
};
struct fn_3_17100_lbl_1_bss_D58 {
    u8 pad_0[0x12];
    u16 unk_12;
};

extern f64 __fabs(f64);
extern struct fn_3_17100_lbl_1_bss_BF0 lbl_1_bss_BF0;
extern struct fn_3_17100_lbl_1_bss_D58 lbl_1_bss_D58;
extern struct fn_3_17100_lbl_3_rodata_5F0 lbl_3_rodata_5F0;
typedef struct {
    u8 pad_0[2];
    u16 unk_2;
    u8 pad_4[0xE];
    u16 unk_12;
} PadInput17100;
extern PadInput17100 lbl_1_bss_9F8[];
extern void fn_1_A2D84(u32);
extern void fn_3_177AC(void *);

void fn_3_17100(void) {
    Obj_3_bss_A2410 *p_lbl_3_bss_A2410;
    struct fn_3_17100_lbl_3_rodata_5F0 *p_lbl_3_rodata_5F0;
    Obj_3_bss_A2410 *branchMain;
    s32 v36;
    s32 v39;
    s32 v0;
    f64 v1;
    void * v2;
    s32 v3;
    s32 v4;
    s32 v5;
    s32 v6;
    u32 v7;
    f32 v8;
    u32 v9;
    u32 v10;
    f32 v11;
    u32 v12;
    f32 v13;
    s32 v14;
    s32 v15;
    void * v16;
    u8 v17;
    s32 v18;
    s32 v19;
    s32 v20;
    s32 v21;
    s32 v22;
    u32 v23;
    s32 v24;
    f32 v25;
    u8 v26;
    u8 v27;
    u16 *v28;
    u8 v29;
    u8 v30;
    u16 v31;
    s16 v32;
    s16 v33;
    s16 v34;
    u32 v35;
    u16 v37;
    u32 v38;
    s16 v40;
    u32 v41;
    union { u32 word; u8 byte[4]; }
        loc_30, loc_2C, loc_28, loc_24, loc_20, loc_1C,
        loc_18, loc_14, loc_10, loc_C, loc_8;
    p_lbl_3_rodata_5F0 = (struct fn_3_17100_lbl_3_rodata_5F0 *)&lbl_3_rodata_5F0;
    if ((lbl_3_bss_A2410.unk_8 & 0x40000000) != 0) {
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 7) & 0x1) != 0) {
    v3 = lbl_3_bss_A2410.unk_C;
    if ((v3 - 4) < 0) {
    lbl_3_bss_A2410.unk_4 = lbl_3_bss_A2410.unk_10;
    lbl_3_bss_A2410.unk_5 = lbl_3_bss_A2410.unk_12;
    lbl_3_bss_A2410.unk_6 = lbl_3_bss_A2410.unk_14;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = ((u32 *)&lbl_3_data_35C0)[v3];
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_E = lbl_3_bss_A2410.unk_C;
    lbl_3_bss_A2410.unk_C = 2;
    lbl_3_bss_A2410.unk_8 = 0x80000000;
    lbl_3_bss_A2410.unk_1C = p_lbl_3_rodata_5F0->unk_C;
    } else {
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = ((u32 *)&lbl_3_data_35C0)[v3];
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_C -= 4;
    lbl_3_bss_A2410.unk_1C = p_lbl_3_rodata_5F0->unk_C;
    loc_30.word = ((u32 *)&lbl_3_data_35C0)[lbl_3_bss_A2410.unk_C];
    fn_3_177AC(&loc_30);
    }
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 6) & 0x1) != 0) {
    v0 = lbl_3_bss_A2410.unk_C;
    if ((s32)(v0 + 4) < 16) {
    v12 = (v0 << 2);
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = *(u32 *)((u8 *)&lbl_3_data_35C0 + v12);
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_C += 4;
    lbl_3_bss_A2410.unk_1C = p_lbl_3_rodata_5F0->unk_C;
    }
    v0 = (u32)&loc_2C;
    loc_2C.word = ((u32 *)&lbl_3_data_35C0)[lbl_3_bss_A2410.unk_C];
    fn_3_177AC((void *)v0);
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 4) & 0x1) != 0) {
    v14 = lbl_3_bss_A2410.unk_C;
    if (v14 % 4 != 0) {
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = ((u32 *)&lbl_3_data_35C0)[v14];
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_1C = p_lbl_3_rodata_5F0->unk_C;
    lbl_3_bss_A2410.unk_C--;
    }
    v0 = (u32)&loc_28;
    loc_28.word = ((u32 *)&lbl_3_data_35C0)[lbl_3_bss_A2410.unk_C];
    fn_3_177AC((void *)v0);
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 5) & 0x1) != 0) {
    v15 = lbl_3_bss_A2410.unk_C;
    if (v15 % 4 != 3) {
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = ((u32 *)&lbl_3_data_35C0)[v15];
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_1C = p_lbl_3_rodata_5F0->unk_C;
    lbl_3_bss_A2410.unk_C++;
    }
    v0 = (u32)&loc_24;
    loc_24.word = ((u32 *)&lbl_3_data_35C0)[lbl_3_bss_A2410.unk_C];
    fn_3_177AC((void *)v0);
    }
    } else {
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 7) & 0x1) != 0) {
    v0 = lbl_3_bss_A2410.unk_C;
    lbl_3_bss_A2410.unk_20 = 0;
    if ((v0 - 1) >= 0) {
    lbl_3_bss_A2410.unk_8 = 0x80000000;
    fn_1_A2D84(0xA9150600);
    v0 = lbl_3_bss_A2410.unk_C;
    lbl_3_bss_A2410.unk_C = (v0 - 1);
    }
    loc_1C.word = p_lbl_3_rodata_5F0->unk_0;
    loc_1C.byte[0] = lbl_3_bss_A2410.unk_10;
    loc_1C.byte[1] = lbl_3_bss_A2410.unk_12;
    loc_1C.byte[2] = lbl_3_bss_A2410.unk_14;
    loc_20.word = loc_1C.word;
    fn_3_177AC(&loc_20);
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 6) & 0x1) != 0) {
    v19 = lbl_3_bss_A2410.unk_C;
    lbl_3_bss_A2410.unk_20 = 0;
    lbl_3_bss_A2410.unk_C = (v19 + 1);
    fn_1_A2D84(0xA9150600);
    if (lbl_3_bss_A2410.unk_C >= 3) {
    lbl_3_bss_A2410.unk_C = lbl_3_bss_A2410.unk_E;
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    lbl_3_bss_A2410.unk_0 = lbl_3_bss_A2410.unk_10;
    lbl_3_bss_A2410.unk_1 = lbl_3_bss_A2410.unk_12;
    lbl_3_bss_A2410.unk_2 = lbl_3_bss_A2410.unk_14;
    lbl_3_bss_A2410.unk_1C = p_lbl_3_rodata_5F0->unk_C;
    loc_18.word = ((u32 *)&lbl_3_data_35C0)[lbl_3_bss_A2410.unk_C];
    fn_3_177AC(&loc_18);
    } else {
    v7 = 0x80000000;
    loc_10.word = p_lbl_3_rodata_5F0->unk_4;
    lbl_3_bss_A2410.unk_8 = v7;
    v26 = lbl_3_bss_A2410.unk_10;
    v27 = lbl_3_bss_A2410.unk_12;
    v24 = lbl_3_bss_A2410.unk_14;
    loc_10.byte[0] = v26;
    loc_10.byte[1] = v27;
    loc_10.byte[2] = v24;
    v0 = loc_10.word;
    loc_14.word = v0;
    fn_3_177AC(&loc_14);
    }
    }
    v0 = (u32)&lbl_1_bss_9F8;
    v0 = (u32)((u8 *)v0 + 2);
    v0 = *(u16 *)((u8 *)v0 + (lbl_3_bss_A2410.unk_D * 20));
    if (((v0 >> 4) & 0x1) != 0 || ((v0 >> 5) & 0x1) != 0) {
    loc_8.word = p_lbl_3_rodata_5F0->unk_8;
    v0 = (u32)&loc_C;
    v30 = lbl_3_bss_A2410.unk_C;
    v29 = lbl_3_bss_A2410.unk_10;
    v32 = (s16)(&lbl_3_bss_A2410.unk_10)[v30];
    loc_8.byte[0] = v29;
    loc_8.byte[1] = lbl_3_bss_A2410.unk_12;
    loc_8.byte[2] = lbl_3_bss_A2410.unk_14;
    loc_C.word = loc_8.word;
    fn_3_177AC((void *)v0);
    v0 = (u32)&lbl_3_bss_A2410;
    if ((*(s16 *)((u8 *)v0 + 32)) > 40) {
    v1 = (f32)(lbl_1_bss_BF0.unk_0[lbl_3_bss_A2410.unk_D].unk_8);
    if (v1 < p_lbl_3_rodata_5F0->unk_C) {
    v34 = -8;
    } else {
    v34 = 8;
    }
    v34 = (s16)v34;
    } else {
    if ((*(s16 *)((u8 *)v0 + 32)) > 20) {
    v1 = (f32)(lbl_1_bss_BF0.unk_0[lbl_3_bss_A2410.unk_D].unk_8);
    if (v1 < p_lbl_3_rodata_5F0->unk_C) {
    v34 = -4;
    } else {
    v34 = 4;
    }
    v34 = (s16)v34;
    } else {
    v1 = (f32)(lbl_1_bss_BF0.unk_0[lbl_3_bss_A2410.unk_D].unk_8);
    if (v1 < p_lbl_3_rodata_5F0->unk_C) {
    v34 = -1;
    } else {
    v34 = 1;
    }
    v34 = (s16)v34;
    }
    }
    if ((*(s16 *)((u8 *)v0 + 32)) >= 20) {
    (&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] = ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34) < 0 ? 0 : ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34) > 255 ? 255 : ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34);
    } else {
    v37 = lbl_1_bss_D58.unk_12;
    if (((v37 >> 5) & 0x1) != 0 || ((v37 >> 4) & 0x1) != 0) {
    (&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] = ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34) < 0 ? 0 : ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34) > 255 ? 255 : ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34);
    }
    }
    v1 = (f32)(lbl_1_bss_BF0.unk_0[lbl_3_bss_A2410.unk_D].unk_8);
    v1 = __fabs(v1);
    if (v1 >= p_lbl_3_rodata_5F0->unk_10) {
    v40 = *(s16 *)((u8 *)v0 + 32);
    *(u16 *)((u8 *)v0 + 32) = (v40 + 1);
    } else {
    *(u16 *)((u8 *)v0 + 32) = 0;
    }
    v41 = (&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C];
    if (v41 != 0 && v41 != 255 && v32 != (s32)v41) {
    fn_1_A2D84(0xA9150700);
    }
    }
    }
}
/* fzgx:end fn_3_17100 */

/* fzgx:begin fn_3_17820 */
u32 fn_3_17820(void) {
    return *(u32 *)&(*(u16 (*)[20])&lbl_3_bss_A2410)[2];
}
/* fzgx:end fn_3_17820 */

/* fzgx:begin fn_3_17830 */
typedef struct CustomizeState {
    u8 _pad0[8];
    u32 flags;
    u8 _pad1[16];
    f32 field_1c;
} CustomizeState;

void fn_3_17830(void) {
    (*(CustomizeState *)&lbl_3_bss_A2410).field_1c = lbl_3_rodata_5FC[0];
    (*(CustomizeState *)&lbl_3_bss_A2410).flags |= 0x20000000u;
}
/* fzgx:end fn_3_17830 */

/* fzgx:begin fn_3_18614 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/editor.h"
#include "font.h"

typedef struct { u32 c; } Col4;

struct fn_3_156D0_Obj {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    s16 unk_12;
    u8 pad_14[8];
    u8 unk_1C;
    u8 pad_1D[3];
    void *unk_20;
};

typedef struct {
    u32 type;
    f32 x;
    f32 y;
    f32 z;
    f32 a;
    f32 b;
    u8 pad18[0x18];
    u32 mode;
    u8 pad34[8];
    u32 color;
    u8 pad40[0x18];
} Packet16E14;

struct fn_3_1552C_Obj {
    u8 pad[0x10];
    u16 width;
    u16 height;
};

typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} PadInput;

struct Obj {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    s16 unk_12;
    u8 pad_14[8];
    u8 unk_1C;
    u8 pad_1D[3];
    void *unk_20;
};
extern u8 *fn_3_14074(void);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u8 fn_3_19C94(void);
extern void fn_3_169B8(void);
extern u32 fn_3_17820(void);
extern void fn_3_1445C(void);
extern s32 fn_3_14600(void);
extern void fn_3_19F7C();
extern void fn_3_17830(void);
extern void fn_3_177AC(void *);
extern void fn_3_16FD0(u32 arg0);
extern void fn_3_19CA4(void);
extern void fn_3_19CCC(void);
extern void DCInvalidateRange(void *, u32);
extern void DCStoreRange(void *, u32);
extern void fn_1_A2D84(u32 arg0);
extern PadInput lbl_1_bss_9F8[];
extern u8 lbl_3_bss_A2408[8];
extern s32 fn_1_45D0();
extern u32 lbl_801A6410;
extern void fn_3_19CB8(void);
extern void fn_3_15620(void);
extern void fn_3_1560C(void);
extern const Col4 lbl_3_rodata_5B8;
extern const Col4 lbl_3_rodata_5BC;
extern s32 fn_1_A5DC4(void);
extern void fn_1_A9868();
extern u32 fn_1_A9FFC(s16, s16, s16, s16, void *);
extern void fn_1_AA538(void);
extern void fn_1_4E0F4(void);
extern const Packet16E14 lbl_1_rodata_26F8;
extern u8 lbl_3_rodata_538[];
extern Col4 lbl_3_rodata_5EC;
extern u32 fn_3_14794(u32, s16, s16, void *);
extern void fn_3_17100(void);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern const f32 lbl_3_rodata_5FC[3];

typedef struct {
    u32 flags;
    u8 pad_4[0x18];
    u8 unk_1C;
} EditorObj;

typedef struct {
    u8 unk_0;
    u8 pad_1[0x3];
    u32 unk_4;
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
    u8 unk_10;
} EditorState;


typedef struct {
    u16 unk_0;
    u8 pad_2[0xE];
} MenuEntry;

typedef void (*EditorHandler)(EditorObj *);


/* pressed / repeat button words of the current pad slot (0x14-byte rows) */
#define PAD_PRESS() ((&lbl_1_bss_9F8[0].unk_10)[(*((EditorState *)&lbl_3_bss_A2438)).unk_0 * 10])
#define PAD_REPEAT() (lbl_1_bss_9F8[(*((EditorState *)&lbl_3_bss_A2438)).unk_0].unk_12)
#define BIT(word, n) (((word) >> (n)) & 1)

/* entry is within [lo, hi] (unsigned byte range test) */
#define ENTRY_IN(e, lo, hi) ((u8)((e) - (lo)) <= (hi) - (lo))

#pragma opt_propagation off

void fn_3_18614(void) {
    EditorObj *obj;
    EditorState *st;
    s32 mode;
    u8 entry;
    u16 buttons;
    u16 *trig;

    obj = (EditorObj *)fn_3_14074();
    mode = fn_3_19C94();
    obj->unk_1C = mode;
    if ((*((EditorState *)&lbl_3_bss_A2438)).unk_4 & 0x20000000) {
        return;
    }
    switch (mode) {
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
        (((EditorHandler *)&lbl_3_data_3738))[mode](obj);
        return;
    default:
        break;
    }

    trig = &lbl_1_bss_9F8[0].unk_8;
    buttons = trig[(*((EditorState *)&lbl_3_bss_A2438)).unk_0 * 10];
    if (BIT(buttons, 8)) {
        fn_1_A2D84(0xA9150400);
        entry = (((MenuEntry *)&lbl_3_data_3618))[(*((EditorState *)&lbl_3_bss_A2438)).unk_F].unk_0;
        (*((EditorState *)&lbl_3_bss_A2438)).unk_E = entry;
        if (entry == 6) {
            (((EditorHandler *)&lbl_3_data_3738))[(*((EditorState *)&lbl_3_bss_A2438)).unk_F](obj);
            return;
        }
        if (ENTRY_IN(entry, 11, 12) || ENTRY_IN(entry, 14, 17) || entry == 13) {
            return;
        }
        if (entry == 0 || entry == 1) {
            fn_3_19CB8();
            fn_3_15620();
        } else {
            fn_3_19CB8();
            fn_3_1560C();
        }
    } else if (BIT(buttons, 9)) {
        fn_1_A2D84(0xA9150500);
        fn_3_19CCC();
        (*((EditorState *)&lbl_3_bss_A2438)).unk_8 |= 0x40000000;
        obj->flags |= 0x10000000;
        (*((EditorState *)&lbl_3_bss_A2438)).unk_10 = 0;
        (*((EditorState *)&lbl_3_bss_A2438)).unk_E = 0x11;
        return;
    }

    if ((PAD_PRESS() & 1) || (PAD_REPEAT() & 1)) {
        if ((*((EditorState *)&lbl_3_bss_A2438)).unk_F % 3 != 0) {
            (*((EditorState *)&lbl_3_bss_A2438)).unk_F--;
            fn_1_A2D84(0xA9150600);
        }
    }
    if (BIT(PAD_PRESS(), 1) || BIT(PAD_REPEAT(), 1)) {
        st = &(*((EditorState *)&lbl_3_bss_A2438));
        if (st->unk_F % 3 < 2) {
            fn_1_A2D84(0xA9150600);
            st->unk_F++;
        }
    }
    if (BIT(PAD_PRESS(), 3) || BIT(PAD_REPEAT(), 3)) {
        st = &(*((EditorState *)&lbl_3_bss_A2438));
        if (st->unk_F - 3 >= 0) {
            fn_1_A2D84(0xA9150600);
            st->unk_F -= 3;
        }
    }
    if (BIT(PAD_PRESS(), 2) || BIT(PAD_REPEAT(), 2)) {
        st = &(*((EditorState *)&lbl_3_bss_A2438));
        if (st->unk_F + 3 < 18) {
            fn_1_A2D84(0xA9150600);
            st->unk_F += 3;
        }
    }
}

#pragma opt_propagation reset
/* fzgx:end fn_3_18614 */

/* fzgx:begin fn_3_18960 noprologue */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 24.0f;
    s = 86.0f;
    s = 100.0f;
    s = 385.0f;
    s = 170.0f;
    s = 104.0f;
    s = 40.0f;
    s = 96.0f;
    s = 90.0f;
    s = 0.5f;
    s = 20.0f;
    s = 60.0f;
    s = 80.0f;
    s = 15.0f;
    s = 30.0f;
    s = 320.0f;
    s = 372.0f;
    s = 0.10000000149011612f;
    s = 0.6000000238418579f;
    s = 375.0f;
    s = 0.75f;
    s = 248.0f;
    s = 1.0f;
    s = 0.800000011920929f;
    s = 240.0f;
    s = 25.0f;
    s = 1.0199999809265137f;
    s = 1.0099999904632568f;
    s = 0.4000000059604645f;
    s = 32768.0f;
    s = 10.0f;
    s = 81.0f;
    s = 399.0f;
    s = 18.0f;
    s = 12.0f;
    s = 0.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"


/* lbl_3_bss_A2438: .bss size 0x1C, 2 refs from editor.c */
/* one layout for every TU header that declares this symbol (librarian, typedefs.json) */
typedef struct {
u8 unk_0; /* 23 loads, 1 stores */
u8 pad_1[0x3];
u32 unk_4; /* 3 loads, 14 stores */
u32 unk_8; /* 10 loads, 6 stores */
u8 unk_C; /* 13 loads, 2 stores */
u8 unk_D; /* 0 loads, 1 stores */
u8 unk_E; /* 1 loads, 13 stores */
u8 unk_F; /* 13 loads, 5 stores */
u8 unk_10; /* 14 loads, 14 stores */
u8 pad_11[0x1];
s16 unk_12; /* 12 loads, 3 stores */
u8 unk_14; /* 9 loads, 3 stores */
u8 unk_15; /* 11 loads, 5 stores */
s16 unk_16; /* 3 loads, 2 stores */
s16 unk_18; /* 2 loads, 4 stores */
s16 unk_1A; /* 2 loads, 4 stores */
} Obj_3_bss_A2438;
extern Obj_3_bss_A2438 lbl_3_bss_A2438; /* typedefs.json decl override */
/* lbl_3_data_3618: .data size 0x120, 2 refs from editor.c (own data block) */
typedef struct {
u8 pad_0[0x4];
u32 unk_4; /* 1 loads, 0 stores */
u32 unk_8; /* 1 loads, 0 stores */
u16 unk_C; /* 6 loads, 4 stores */
u8 pad_E[0x112];
} Obj_3_data_3618;

typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);
extern const FontDrawPacket lbl_1_rodata_26F8;
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern u32 fn_1_50A90(void *, u32, u32, u32, u32);
extern s32 fn_1_A5DC4(void);
extern s32 fn_1_4FC50(void *, u32, u16, u16, u32);
extern f32 lbl_8006D188(u32);
extern u8 fn_3_19C94(void);
extern u8 *fn_3_14074(void);
extern u8 lbl_3_bss_A2458[8];
extern s32 lbl_3_bss_A179C;
extern u32 lbl_3_bss_A1798;
extern s32 lbl_801A66B4[1];
#define lbl_801A66B4 (*lbl_801A66B4)
extern u32 fn_3_1402C(u8);
extern u32 fn_3_14064(void);
extern void fn_3_146BC(u32);
typedef struct { u32 id; u32 image; u32 image2; u16 fade_values[1]; u16 pad; } Tool;
#define fade fade_values[0]
extern u8 fn_3_19D14__fzgx_offset_0[];
extern u8 fn_3_19D88__fzgx_offset_0[];
extern u8 fn_3_19DC8__fzgx_offset_0[];
extern u8 fn_3_19E40__fzgx_offset_0[];
extern u8 fn_3_19EB8__fzgx_offset_0[];
extern u8 fn_3_19EFC__fzgx_offset_0[];
extern u8 fn_3_19F40__fzgx_offset_0[];
extern u8 fn_3_19F9C__fzgx_offset_0[];
extern u8 fn_3_19FE0__fzgx_offset_0[];
extern u8 fn_3_1A024__fzgx_offset_0[];
extern u8 fn_3_1A068__fzgx_offset_0[];
extern u8 fn_3_1A0F4__fzgx_offset_0[];
extern u8 fn_3_1A1B8__fzgx_offset_0[];
extern u8 fn_3_1A1D8__fzgx_offset_0[];
extern u8 fn_3_1A264__fzgx_offset_0[];
extern u8 fn_3_1A2EC__fzgx_offset_0[];
extern u8 fn_3_1A488__fzgx_offset_0[];
extern u8 fn_3_1A648__fzgx_offset_0[];
extern u8 lbl_3_data_3780__fzgx_offset_0[];
extern u8 lbl_3_data_3788__fzgx_offset_0[];
extern u8 lbl_3_data_378C__fzgx_offset_0[];
extern u8 lbl_3_data_379C__fzgx_offset_0[];
extern u8 lbl_3_data_37A4__fzgx_offset_0[];
extern u8 lbl_3_data_37B4__fzgx_offset_0[];
extern u8 lbl_3_data_37BC__fzgx_offset_0[];
extern u8 lbl_3_data_37CC__fzgx_offset_0[];
extern u8 lbl_3_data_37D8__fzgx_offset_0[];
extern u8 lbl_3_data_37E8__fzgx_offset_0[];
extern u8 lbl_3_data_37F8__fzgx_offset_0[];
extern u8 lbl_3_data_3808__fzgx_offset_0[];
extern u8 lbl_3_data_381C__fzgx_offset_0[];
extern u8 lbl_3_data_3830__fzgx_offset_0[];
extern u8 lbl_3_data_3848__fzgx_offset_0[];
extern u8 lbl_3_data_3864__fzgx_offset_0[];
extern u8 lbl_3_data_387C__fzgx_offset_0[];
extern u8 lbl_3_data_3898__fzgx_offset_0[];
extern u8 lbl_3_data_38B4__fzgx_offset_0[];
extern u8 lbl_3_data_38D4__fzgx_offset_0[];
extern u8 lbl_3_data_38E4__fzgx_offset_0[];
extern u8 lbl_3_data_38FC__fzgx_offset_0[];
extern u8 lbl_3_data_390C__fzgx_offset_0[];
extern u8 lbl_3_data_3924__fzgx_offset_0[];
extern u8 lbl_3_data_3934__fzgx_offset_0[];
extern u8 lbl_3_data_394C__fzgx_offset_0[];
extern u8 lbl_3_data_395C__fzgx_offset_0[];
extern u8 lbl_3_data_3974__fzgx_offset_0[];
extern u8 lbl_3_data_3984__fzgx_offset_0[];
extern u8 lbl_3_data_3998__fzgx_offset_0[];
extern u8 lbl_3_data_39A8__fzgx_offset_0[];
extern u8 lbl_3_data_39C0__fzgx_offset_0[];
extern u8 lbl_3_data_39CC__fzgx_offset_0[];
extern u8 lbl_3_data_39E8__fzgx_offset_0[];
extern u8 lbl_3_data_39F4__fzgx_offset_0[];
extern u8 lbl_3_data_3A10__fzgx_offset_0[];
extern u8 lbl_3_data_3A24__fzgx_offset_0[];
extern u8 lbl_3_data_3BEC__fzgx_offset_0[];
extern u8 lbl_3_data_3C00__fzgx_offset_0[];
extern u8 lbl_3_data_3C1C__fzgx_offset_0[];
extern u8 lbl_3_data_3C34__fzgx_offset_0[];
extern u8 lbl_3_data_3C58__fzgx_offset_0[];
extern u8 lbl_3_data_3C68__fzgx_offset_0[];
extern u8 lbl_3_data_3C84__fzgx_offset_0[];
extern u8 lbl_3_data_3C88__fzgx_offset_0[];
extern u8 lbl_3_data_3C90__fzgx_offset_0[];
extern u8 lbl_3_data_3C94__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_3_data_3618[72] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x8629, 0x8617, 0x0, 0x10000, 0x8624, 0x8612, 0x0,
    0x20000, 0x8628, 0x8616, 0x0, 0x30000, 0x8625, 0x8613, 0x0,
    0x40000, 0x8620, 0x860E, 0x0, 0x50000, 0x8631, 0x861D, 0x0,
    0x60000, 0x8627, 0x8615, 0x0, 0x70000, 0x8621, 0x860F, 0x0,
    0x80000, 0x8632, 0x861E, 0x0, 0x90000, 0x862E, 0x861A, 0x0,
    0xA0000, 0x862D, 0x8619, 0x0, 0xB0000, 0x862F, 0x861B, 0x0,
    0xC0000, 0x8622, 0x8610, 0x0, 0xD0000, 0x8633, 0x861F, 0x0,
    0xE0000, 0x862C, 0x8618, 0x0, 0xF0000, 0x8626, 0x8614, 0x0,
    0x100000, 0x8630, 0x861C, 0x0, 0x110000, 0x8623, 0x8611, 0x0
};
static u32 fzgx_pool_data_lbl_3_data_3738[] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)fn_3_19D14__fzgx_offset_0, (u32)fn_3_19D88__fzgx_offset_0, (u32)fn_3_19F40__fzgx_offset_0, (u32)fn_3_19F9C__fzgx_offset_0, (u32)fn_3_19FE0__fzgx_offset_0, (u32)fn_3_19EB8__fzgx_offset_0, (u32)fn_3_1A1B8__fzgx_offset_0, (u32)fn_3_1A024__fzgx_offset_0,
    (u32)fn_3_19EFC__fzgx_offset_0, (u32)fn_3_19E40__fzgx_offset_0, (u32)fn_3_19DC8__fzgx_offset_0, (u32)fn_3_1A648__fzgx_offset_0, (u32)fn_3_1A488__fzgx_offset_0, (u32)fn_3_1A1D8__fzgx_offset_0, (u32)fn_3_1A264__fzgx_offset_0, (u32)fn_3_1A0F4__fzgx_offset_0,
    (u32)fn_3_1A068__fzgx_offset_0, (u32)fn_3_1A2EC__fzgx_offset_0, 0x44726177, 0x0, 0x0, 0x935F82F0, 0x82A982AB, 0x82DC82B7,
    0x0, 0x45726173, 0x65000000, 0x935F82F0, 0x8FC182B5, 0x82DC82B7, 0x0, 0x46696C6C,
    0x0, 0x82CA82E8, 0x82C282D4, 0x82B582DC, 0x82B70000, 0x44726177, 0x2061204C, 0x696E6500,
    0x90FC82F0, 0x88F882AB, 0x82DC82B7, 0x0, 0x44726177, 0x20612043, 0x6972636C, 0x65000000,
    0x897E82F0, 0x82A982AB, 0x82DC82B7, 0x0, 0x44726177, 0x20612052, 0x65637461, 0x6E676C65,
    0x0, 0x8E6C8A70, 0x8C6082F0, 0x82A982AB, 0x82DC82B7, 0x0, 0x456E6C61, 0x72676520,
    0x74686520, 0x45646974, 0x20536372, 0x65656E00, 0x83478366, 0x83428362, 0x836789E6, 0x96CA82F0,
    0x8A6791E5, 0x82B582DC, 0x82B70000, 0x44726177, 0x20616E64, 0x2046696C, 0x6C206120, 0x43697263,
    0x6C650000, 0x897E82F0, 0x82A982A2, 0x82C482CA, 0x82E882C2, 0x82D482B5, 0x82DC82B7, 0x0,
    0x44726177, 0x20616E64, 0x2046696C, 0x6C206120, 0x52656374, 0x616E676C, 0x65000000, 0x8E6C8A70,
    0x8C6082F0, 0x82A982A2, 0x82C482CA, 0x82E882C2, 0x82D482B5, 0x82DC82B7, 0x0, 0x526F7461,
    0x74652045, 0x6D626C65, 0x6D000000, 0x83478393, 0x8375838C, 0x838082F0, 0x89F1935D, 0x82B582DC,
    0x82B70000, 0x496E7665, 0x72742045, 0x6D626C65, 0x6D000000, 0x83478393, 0x8375838C, 0x838082F0,
    0x94BD935D, 0x82B582DC, 0x82B70000, 0x4C6F6164, 0x20612053, 0x616D706C, 0x65000000, 0x83548393,
    0x8376838B, 0x82F0838D, 0x815B8368, 0x82B582DC, 0x82B70000, 0x436C6561, 0x7220456D, 0x626C656D,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x83478393, 0x8375838C, 0x838082F0, 0x8FC182B5, 0x82DC82B7, 0x0, 0x556E646F,
    0x204F7065, 0x72617469, 0x6F6E0000, 0x91808DEC, 0x82F08EE6, 0x82E88FC1, 0x82B582DC, 0x82B70000,
    0x5265646F, 0x204F7065, 0x72617469, 0x6F6E0000, 0x91808DEC, 0x8EE682E8, 0x8FC182B5, 0x82F096DF,
    0x82B582DC, 0x82B70000, 0x4C6F6164, 0x20456D62, 0x6C656D00, 0x83478393, 0x8375838C, 0x838082F0,
    0x838D815B, 0x836882B5, 0x82DC82B7, 0x0, 0x53617665, 0x20456D62, 0x6C656D00, 0x83478393,
    0x8375838C, 0x838082F0, 0x835A815B, 0x837582B5, 0x82DC82B7, 0x0, 0x436C6F73, 0x65207468,
    0x65204564, 0x69746F72, 0x0, 0x83478366, 0x8342835E, 0x82F08F49, 0x97B982B5, 0x82DC82B7,
    0x0
};
static u32 fzgx_pool_data_lbl_3_data_3618_424[152] = { /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_3780__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_378C__fzgx_offset_0, (u32)lbl_3_data_379C__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_37A4__fzgx_offset_0, (u32)lbl_3_data_37B4__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_37BC__fzgx_offset_0, (u32)lbl_3_data_37CC__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_37D8__fzgx_offset_0, (u32)lbl_3_data_37E8__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_37F8__fzgx_offset_0, (u32)lbl_3_data_3808__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_381C__fzgx_offset_0, (u32)lbl_3_data_3830__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3848__fzgx_offset_0, (u32)lbl_3_data_3864__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_387C__fzgx_offset_0, (u32)lbl_3_data_3898__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_38B4__fzgx_offset_0, (u32)lbl_3_data_38D4__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_38E4__fzgx_offset_0, (u32)lbl_3_data_38FC__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_390C__fzgx_offset_0, (u32)lbl_3_data_3924__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_3934__fzgx_offset_0, (u32)lbl_3_data_394C__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_395C__fzgx_offset_0, (u32)lbl_3_data_3974__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3984__fzgx_offset_0, (u32)lbl_3_data_3998__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_39A8__fzgx_offset_0, (u32)lbl_3_data_39C0__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_39CC__fzgx_offset_0, (u32)lbl_3_data_39E8__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_39F4__fzgx_offset_0, (u32)lbl_3_data_3A10__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3A24__fzgx_offset_0, 0x49732069, 0x74204F4B, 0x20746F20,
    0x71756974, 0x3F000000, 0x8F4997B9, 0x82B582C4, 0x82E082E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9,
    0x81480000, 0x4F4B2074, 0x6F206572, 0x61736520, 0x74686520, 0x656D626C, 0x656D3F00, 0x83478393,  /* fzgx-allow: A1 retail data bytes */
    0x8375838C, 0x838082F0, 0x8FC182B5, 0x82C482E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x81480000,  /* fzgx-allow: A1 retail data bytes */
    0x4C6F6164, 0x20612073, 0x616D706C, 0x653F0000, 0x83548393, 0x8376838B, 0x82F0838D, 0x815B8368,  /* fzgx-allow: A1 retail data bytes */
    0x82B582DC, 0x82B782A9, 0x81480000, 0x59455300, 0x82CD82A2, 0x0, 0x4E4F0000, 0x82A282A2,  /* fzgx-allow: A1 retail data bytes */
    0x82A60000
};
static u32 fzgx_pool_data_lbl_3_data_3618_684[5][6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_3BEC__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3C00__fzgx_offset_0, (u32)lbl_3_data_3C1C__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3C34__fzgx_offset_0, (u32)lbl_3_data_3C58__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3C68__fzgx_offset_0, (u32)lbl_3_data_3C84__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3C88__fzgx_offset_0,
    (u32)lbl_3_data_3C90__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3C94__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_3_data_3D14[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x746F6F6C, 0x6B69742E, 0x63000000
};
static u32 fzgx_pool_data_lbl_3_data_3618_708[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25730A00
};
static u32 fzgx_pool_data_lbl_3_data_3618_70C[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x2F626366, 0x66666666, 0x662F0000
};
static u32 fzgx_pool_data_lbl_3_data_3618_718[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x2F626366, 0x66663230, 0x302F0000
};
static u32 fzgx_pool_data_lbl_3_data_3618_724[5] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25732573, 0x25732020, 0x20257325, 0x7325730A, 0x0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_3_data_3618(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3618;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3738;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3618_424;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3618_684;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3D14;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3618_708;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3618_70C;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3618_718;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3618_724;
}
#pragma section code_type ".text"

static inline int clamp(int v, int max) { return v < 0 ? 0 : v > max ? max : v; }
static inline void fade_set(u16 *value, int updated) { *value = clamp(updated, 40); }
#define fade_add(value, delta) fade_set(value, *(value) + (delta))
typedef struct { char *line[6]; } MessageRow;
typedef struct { char *quit; u8 pad_4[20]; char *erase; u8 pad_1C[20]; char *load; u8 pad_34[20]; char *yes; u8 pad_4C[20]; char *no; } MessageColumn;
void fn_3_18960(u32 arg0) {

Obj_3_bss_A2438 *state;
u8 i, j;
s16 xoff, yoff;
int y0, y1, x0, x1;
Tool *tool;
int x, y;
u16 *fadePtr;
int fullindex;
u8 index;
u32 image;
f32 pulse;
FontDrawPacket p;
if (lbl_3_bss_A2438.unk_4 & 0x20000000)
lbl_3_bss_A2438.unk_16 = clamp(lbl_3_bss_A2438.unk_16 - 1, 10);
else
lbl_3_bss_A2438.unk_16 = clamp(lbl_3_bss_A2438.unk_16 + 1, 10);
p = lbl_1_rodata_26F8 ;
p.image = 0x863e; p.x = 24.0f; p.y = 86.0f; p.z = 100.0f; p.flags = 5; fn_1_4F734(&p) ;
for (i = 0; i < 6; i++) {
p = lbl_1_rodata_26F8 ;
p.image = 0x8608; p.x = 24.0f; p.y = (s32)(i * 46 + 113);
p.z = 100.0f; p.flags = 5; fn_1_4F734(&p) ;
}
p = lbl_1_rodata_26F8 ;
p.image = 0x863f; p.x = 24.0f; p.y = 385.0f; p.z = 100.0f; p.flags = 5; fn_1_4F734(&p) ;
p = lbl_1_rodata_26F8 ;
p.image = 0x863b; p.x = 170.0f; p.y = 104.0f; p.z = 100.0f; p.flags = 5; fn_1_4F734(&p) ;
p = lbl_1_rodata_26F8 ;
p.image = 0x860c; p.x = 40.0f; p.y = 96.0f; p.z = 90.0f; p.flags = 5; fn_1_4F734(&p) ;
state = &lbl_3_bss_A2438;
xoff = (state->unk_F % 3) * 48;
p = lbl_1_rodata_26F8 ;
yoff = (state->unk_F / 3) * 46;
p.image = 0x8604;
p.x = xoff + 19; p.y = yoff + 104;
p.alpha = 0.5f + (f32)lbl_3_bss_A2438.unk_16 / 20.0f;
p.z = 90.0f; p.flags = 5; fn_1_4F734(&p) ;
p.x = xoff + 51; p.y = yoff + 104; p.z = 90.0f; p.flags = 0x80005; fn_1_4F734(&p) ;
p.x = xoff + 19; p.y = yoff + 136; p.z = 90.0f; p.flags = 0x100005; fn_1_4F734(&p) ;
p.x = xoff + 51; p.y = yoff + 136; p.z = 90.0f; p.flags |= 0x80000; fn_1_4F734(&p) ;
{
u8 i, j;
for (i = 0; i < 6; i++) {
for (j = 0; j < 3; j++) {
fullindex = j + i * 3;
index = fullindex;
p = lbl_1_rodata_26F8 ;
tool = (Tool *)((((u8 (*)[16])fzgx_pool_data_lbl_3_data_3618)[index]));
x = j * 48 + 49; y = i * 46 + 134;
p.image = tool->image; p.x = x; p.y = y; p.z = 60.0f;
if (state->unk_F == index) fade_add(&((Tool *)fzgx_pool_data_lbl_3_data_3618)[index].fade, 4);
else fade_add(&((Tool *)fzgx_pool_data_lbl_3_data_3618)[index].fade, -1);
fadePtr = &((Tool *)fzgx_pool_data_lbl_3_data_3618)[index].fade;
p.alpha = 0.5f + (f32)*fadePtr / 80.0f;
((u8 *)&p.color)[0] = 255; ((u8 *)&p.color)[1] = 255; ((u8 *)&p.color)[2] = 255; ((u8 *)&p.color)[3] = 255;
p.flags = 10; fn_1_4F734(&p) ;
p = lbl_1_rodata_26F8 ;
p.image = tool->image2; p.x = x; p.y = y; p.z = 80.0f;
if ((s16)arg0 > 15) {
if (state->unk_F == index) *fadePtr = clamp(*fadePtr + 4,40);
else *fadePtr = clamp(*fadePtr - 1,40);
p.alpha = 0.5f + (f32)*fadePtr / 80.0f;
} else {
if (state->unk_F == fullindex) p.alpha = (f32)(s16)arg0 / 15.0f;
else p.alpha = (f32)(s16)arg0 / 30.0f;
}
((u8 *)&p.color)[0] = 0; ((u8 *)&p.color)[1] = 255; ((u8 *)&p.color)[2] = 255; ((u8 *)&p.color)[3] = 255; p.flags = 10; fn_1_4F734(&p) ;
}
}
}
fn_1_49410(); fn_1_495B0(0x80000000); fn_1_495C8(1);
fn_1_496FC(320.0f,372.0f);
if (fn_3_19C94() == 16 || fn_3_19C94() == 15 || fn_3_19C94() == 11 || (__rlwnm(*(u32 *)fn_3_14074(), 7, 31, 31)))
fn_1_4954C(30.0f);
else fn_1_4954C(0.1f);
if (lbl_801A66B4 != 5) {
fn_1_49590(0.5f); fn_1_4955C(0.6f,0.6f); fn_1_496FC(320.0f,375.0f);
} else fn_1_4955C(0.75f,0.75f);
fn_1_4AE0C(((char *)(((u8 *)fzgx_pool_data_lbl_3_data_3618_708))) , ((MessageRow *)fzgx_pool_data_lbl_3_data_3618_424)[state->unk_F].line[lbl_801A66B4] );
if (fn_3_19C94() == 17) {
p = lbl_1_rodata_26F8 ;
p.image = 12; p.x = 320.0f; p.y = 248.0f; p.z = 20.0f; p.alpha = 1.0f; p.flags = 10;
fn_1_50A90(&p,7,7,360,68);
fn_1_49410(); fn_1_4955C(0.8f,0.8f); fn_1_496FC(320.0f,240.0f);
fn_1_495C8(9); fn_1_495B0(0x80000000);
if (lbl_801A66B4 != 5) fn_1_49590(0.5f);
fn_1_4AE0C(((char *)(((u8 *)fzgx_pool_data_lbl_3_data_3618_708))) , ((MessageRow *)fzgx_pool_data_lbl_3_data_3618_684)[0].line[lbl_801A66B4] );
fn_1_4AE0C((char *)fzgx_pool_data_lbl_3_data_3618_724,
lbl_3_bss_A2438.unk_10 ? (char *)fzgx_pool_data_lbl_3_data_3618_718 : (char *)fzgx_pool_data_lbl_3_data_3618_70C,
(char *)fzgx_pool_data_lbl_3_data_3618_684[3][lbl_801A66B4],
(char *)fzgx_pool_data_lbl_3_data_3618_70C,
lbl_3_bss_A2438.unk_10 ? (char *)fzgx_pool_data_lbl_3_data_3618_70C : (char *)fzgx_pool_data_lbl_3_data_3618_718,
(char *)fzgx_pool_data_lbl_3_data_3618_684[4][lbl_801A66B4],
(char *)fzgx_pool_data_lbl_3_data_3618_70C);
}
if (fn_3_19C94() == 12) {
p = lbl_1_rodata_26F8 ;
p.image = 12; p.x = 320.0f; p.y = 248.0f; p.z = 20.0f; p.alpha = 1.0f; p.flags = 10;
fn_1_50A90(&p,7,7,400,68);
fn_1_49410(); fn_1_4955C(0.8f,0.8f); fn_1_496FC(320.0f,240.0f); fn_1_495B0(0x80000000);
if (lbl_801A66B4 != 5) fn_1_49590(0.5f);
fn_1_495C8(9);
fn_1_4AE0C(((char *)(((u8 *)fzgx_pool_data_lbl_3_data_3618_708))) , (char *)fzgx_pool_data_lbl_3_data_3618_684[1][lbl_801A66B4] );
fn_1_4AE0C((char *)fzgx_pool_data_lbl_3_data_3618_724,
lbl_3_bss_A2438.unk_10 ? (char *)fzgx_pool_data_lbl_3_data_3618_718 : (char *)fzgx_pool_data_lbl_3_data_3618_70C,
(char *)fzgx_pool_data_lbl_3_data_3618_684[3][lbl_801A66B4],
(char *)fzgx_pool_data_lbl_3_data_3618_70C,
lbl_3_bss_A2438.unk_10 ? (char *)fzgx_pool_data_lbl_3_data_3618_70C : (char *)fzgx_pool_data_lbl_3_data_3618_718,
(char *)fzgx_pool_data_lbl_3_data_3618_684[4][lbl_801A66B4],
(char *)fzgx_pool_data_lbl_3_data_3618_70C);
}
if (fn_3_19C94() == 15 || fn_3_19C94() == 16) {
if (lbl_3_bss_A2458[0] || lbl_3_bss_A179C) lbl_3_bss_A1798 = 0;
else lbl_3_bss_A1798 = 1;
} else lbl_3_bss_A1798 = 0;
if (fn_3_19C94() == 11) {
p = lbl_1_rodata_26F8 ;
p.image = 12; p.x = 320.0f; p.y = 240.0f; p.z = 25.0f; p.flags = 10;
fn_1_50A90(&p,7,7,429,340);
{
Obj_3_bss_A2438 *state2 = &lbl_3_bss_A2438;
s16 yoff, xoff;
int x0, x1, y0, y1;
for (i = 0; i < 4; i++) {
for (j = 0; j < 5; j++) {
image = fn_3_1402C((u8)(state2 ->unk_12 + i * 5 + j));
if (image) {
p = lbl_1_rodata_26F8 ;
p.x = j * 75 + 139; p.y = i * 72 + 100; (*(f32 *)((u8 *)&p + 0x14)) = 1.02f;
if ((s8)fn_1_A5DC4()) (*(f32 *)((u8 *)&p + 0x10)) = 1.01f; else (*(f32 *)((u8 *)&p + 0x10)) = 1.02f;
p.z = 20.0f; p.flags = 5;
fn_1_4FC50(&p,5,64,64,image);
}
}
}
yoff = lbl_3_bss_A2438.unk_15 * 72;
p = lbl_1_rodata_26F8 ;
xoff = lbl_3_bss_A2438.unk_14;
xoff *= 75;
p.image = 0x8604; p.x = xoff + 125; p.y = yoff + 86; p.z = 20.0f; p.flags = 5; fn_1_4F734(&p) ;
p.x = xoff + 188; p.y = yoff + 86; p.z = 20.0f; p.flags = 0x80005; fn_1_4F734(&p) ;
p.x = xoff + 125; p.y = yoff + 151; p.z = 20.0f; p.flags = 0x100005; fn_1_4F734(&p) ;
p.x = xoff + 188; p.y = yoff + 151; p.z = 20.0f; p.flags |= 0x80000; fn_1_4F734(&p) ;
if (state2 ->unk_12 - 5 >= 0) {
pulse = 0.4f * lbl_8006D188((s32)(32768.0f * ((f32)lbl_3_bss_A2438.unk_18 / 10.0f)));
p = lbl_1_rodata_26F8 ;
p.scale_y = p.scale_x = 1.0f + pulse; p.alpha = 1.0f - pulse;
p.image = 0x8901; p.x = 320.0f; p.y = 81.0f; p.z = 20.0f; (*(s16 *)((u8 *)&p + 0x28)) = -16384; p.flags = 10; fn_1_4F734(&p) ;
if (lbl_3_bss_A2438.unk_18 < 10) lbl_3_bss_A2438.unk_18++;
}
if (state2 ->unk_12 + 20 < (u8)fn_3_14064()) {
pulse = 0.4f * lbl_8006D188((s32)(32768.0f * ((f32)lbl_3_bss_A2438.unk_1A / 10.0f)));
p = lbl_1_rodata_26F8 ;
p.scale_y = p.scale_x = 1.0f + pulse; p.alpha = 1.0f - pulse;
p.image = 0x8901; p.x = 320.0f; p.y = 399.0f; p.z = 20.0f; (*(s16 *)((u8 *)&p + 0x28)) = 16384; p.flags = 10; fn_1_4F734(&p) ;
if (lbl_3_bss_A2438.unk_1A < 10) lbl_3_bss_A2438.unk_1A++;
}
if ((__rlwnm(lbl_3_bss_A2438.unk_8, 32 - (30), 31, 31))) {
p = lbl_1_rodata_26F8 ;
p.image = 12; p.x = 320.0f; p.y = 248.0f; p.z = 18.0f; p.alpha = 1.0f; p.flags = 10;
fn_1_50A90(&p,7,7,360,68);
fn_1_49410(); fn_1_4955C(0.8f,0.8f); fn_1_496FC(320.0f,240.0f); fn_1_4954C(12.0f);
fn_1_495C8(9); fn_1_495B0(0x80000000);
if (lbl_801A66B4 != 5) fn_1_49590(0.5f);
fn_1_4AE0C(((char *)(((u8 *)fzgx_pool_data_lbl_3_data_3618_708))) ,(char *)fzgx_pool_data_lbl_3_data_3618_684[2][lbl_801A66B4] );
fn_1_4AE0C((char *)fzgx_pool_data_lbl_3_data_3618_724,
lbl_3_bss_A2438.unk_10 ? (char *)fzgx_pool_data_lbl_3_data_3618_718 : (char *)fzgx_pool_data_lbl_3_data_3618_70C,
(char *)fzgx_pool_data_lbl_3_data_3618_684[3][lbl_801A66B4],
(char *)fzgx_pool_data_lbl_3_data_3618_70C,
lbl_3_bss_A2438.unk_10 ? (char *)fzgx_pool_data_lbl_3_data_3618_70C : (char *)fzgx_pool_data_lbl_3_data_3618_718,
(char *)fzgx_pool_data_lbl_3_data_3618_684[4][lbl_801A66B4],
(char *)fzgx_pool_data_lbl_3_data_3618_70C);
}
}
}
if (fn_3_19C94() == 13 || fn_3_19C94() == 14) fn_3_146BC(arg0);
}
/* fzgx:end fn_3_18960 */
