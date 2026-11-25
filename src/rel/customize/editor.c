#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/editor.h"
#include "font.h"

typedef struct EditObj {
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
} EditObj;

typedef struct { u32 c; } Col4;

typedef struct EditPacket {
    union {
        u32 a[22];
        struct {
            u8 pad_0[0x50];
            void (*callback)(void);
            u32 unk_54;
        } named;
    };
} EditPacket;

typedef struct DrawPacket {
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

typedef struct StickInput {
    f32 x;
    f32 y;
    u8 pad[0x18];
} StickInput;

typedef struct Cursor {
    u8 pad[0x10];
    s16 x;
    s16 y;
    u8 pad14[0x8];
    u8 result;
} Cursor;

/* one pad's button words */
typedef struct PadInput {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[4];
    u16 unk_10;
    u16 unk_12;
} PadInput;

typedef struct Arg0 {
    u8 pad_0[4];
    f32 unk_4;
    f32 unk_8;
} Arg0;

typedef struct BorderColor { u8 r, g, b, a; } BorderColor;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

typedef void (*EditorFunc)(EditObj *);

extern EditObj *fn_3_14074(void);
extern void *fn_1_45D0(void *, u32, char *, u32);
extern void fn_80008BEC(void *, u32, u32);
extern void fn_1_46B4(u32, u32, char *, int);
extern u32 lbl_801A6410;
extern u32 lbl_801A66A0;
extern PadInput lbl_1_bss_9F8[4];
extern StickInput lbl_1_bss_BF0[];
extern u8 lbl_1_rodata_26F8[];
extern u8 fn_3_19C94(void);
extern u32 fn_3_17820(void);
extern void fn_3_1445C(void);
extern u8 fn_3_14600(void);
extern u32 fn_3_19F7C(void *, s32, s32);
extern void fn_3_17830(void);
void fn_3_177AC(Color color);
void fn_3_16FD0(void *arg0);
extern void fn_3_19CA4(void);
extern void fn_3_19CCC(void);
extern void DCInvalidateRange(void *, u32);
extern void DCStoreRange(void *, u32);
extern void fn_1_A2D84(u32);
extern f32 lbl_8006D188(u32);
extern s32 fn_1_4FC50(void *, u32, u16, u16, u32);
extern u16 fn_1_48690(u32);
extern u32 fn_1_52690();
extern void GXInvalidateTexAll(void);
extern s32 fn_1_A5DC4(void);
extern void fn_1_A9868();
extern u32 fn_1_A9FFC(s16, s16, s16, s16, void *);
extern void fn_1_AA538(void);
extern void fn_1_4E0F4(void);
extern u32 fn_3_14794(void *, s16, s16, void *);
void fn_3_1683C(Arg0 *arg0, s16 off, s16 size);
void fn_3_169B8(void);
void fn_3_16E14(s16, s16);

u8 lbl_3_bss_A23E8 = 0;
Obj_3_bss_A23EC lbl_3_bss_A23EC;
u8 lbl_3_bss_A2408;
s16 lbl_3_bss_A240A;
s16 lbl_3_bss_A240C;

/* Unknown retail object: .rodata 0x538, 4 bytes (colour FF FF FF FF). No code or data in any REL refers to it. */
const Col4 lbl_3_rodata_538 = {0xFFFFFFFF};

/* fzgx:begin fn_3_1552C */
void fn_3_1552C(void) {
    EditObj *ptr;

    ptr = fn_3_14074();
    ptr->unk_10 = 0x20;
    ptr->unk_12 = 0x20;
    lbl_3_bss_A23EC.unk_C = 0x20000000;
    lbl_3_bss_A23EC.unk_11 = 1;
    lbl_3_bss_A23EC.unk_16 = 0;
    lbl_3_bss_A23EC.unk_0 = 0;
    lbl_3_bss_A23EC.unk_4 = (u32)fn_1_45D0((void *)lbl_801A6410, 0x2000, "editor.c", 0x4A);
    lbl_3_bss_A23EC.unk_8 = (u32)fn_1_45D0((void *)lbl_801A6410, 0x2000, "editor.c", 0x4B);
    fn_80008BEC((void *)lbl_3_bss_A23EC.unk_4, 0, 0x2000);
    fn_80008BEC((void *)lbl_3_bss_A23EC.unk_8, 0, 0x2000);
    lbl_3_bss_A2408 = 0;
}
/* fzgx:end fn_3_1552C */

/* fzgx:begin fn_3_1560C */
void fn_3_1560C(void) {
    lbl_3_bss_A23EC.unk_C = (u32)1 << 31;
}
/* fzgx:end fn_3_1560C */

/* fzgx:begin fn_3_15620 */
void fn_3_15620(void) {
    lbl_3_bss_A23EC.unk_10 = 0;
    lbl_3_bss_A23EC.unk_C = 0x40000000;
}
/* fzgx:end fn_3_15620 */

/* fzgx:begin fn_3_1563C */
void fn_3_1563C(void) {
    fn_1_46B4(lbl_801A6410, lbl_3_bss_A23EC.unk_4, "editor.c", 0x71);
    fn_1_46B4(lbl_801A6410, lbl_3_bss_A23EC.unk_8, "editor.c", 0x72);
}
/* fzgx:end fn_3_1563C */

/* fzgx:begin fn_3_156A8 */
void fn_3_156A8(void) {
    u8 value = (lbl_3_bss_A23EC.unk_11 & 0x7f) << 1;
    lbl_3_bss_A23EC.unk_11 = value;
    if (value > 6) {
        lbl_3_bss_A23EC.unk_11 = 1;
    }
}
/* fzgx:end fn_3_156A8 */

/* fzgx:begin fn_3_156D0 */
#define BUF ((void **)&lbl_3_bss_A23EC.unk_4)[(lbl_3_bss_A23EC.unk_0 + 1) % 2]
#define CALL(n) (((EditorFunc *)&lbl_3_data_3738)[n])(obj)
#define INPUT(f) (lbl_1_bss_9F8[state->unk_12].f)
#define BIT(f, n) ((INPUT(f) >> (n)) & 1)

void fn_3_156D0(void) {
    EditObj *obj;
    Obj_3_bss_A23EC *state;
    void *saved;
    u32 color;
    obj = fn_3_14074();
    fn_80008BEC(BUF, 0, 0x2000);
    if (!(lbl_3_bss_A23EC.unk_C & 0x20000000)) {
        if (fn_3_19C94() != 9 && fn_3_19C94() != 10)
            fn_3_169B8();
        else
            obj->unk_1C = fn_3_19C94();
        if ((lbl_1_bss_9F8[(state = &lbl_3_bss_A23EC)->unk_12].unk_8 >> 8 & 1) && (lbl_3_bss_A23EC.unk_C & 0x40000000)) {
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
        if (((lbl_1_bss_9F8[state->unk_12].unk_0 >> 8) & 1) && (lbl_3_bss_A23EC.unk_C & 0x80000000)) {
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
        if (BIT(unk_8, 8) && (lbl_3_bss_A23EC.unk_C & 0x80000000)) {
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
            if ((INPUT(unk_8) & 1) || (INPUT(unk_A) & 1)) obj->unk_4 |= 0x20000000;
            if (BIT(unk_8, 1) || BIT(unk_A, 1)) obj->unk_4 |= 0x10000000;
            CALL(fn_3_19C94());
        }
        if (obj->unk_1C == 10) {
            if ((INPUT(unk_8) & 1) || (INPUT(unk_A) & 1)) obj->unk_4 |= 0x20000000;
            if (BIT(unk_8, 1) || BIT(unk_A, 1)) obj->unk_4 |= 0x10000000;
            if (BIT(unk_8, 3) || BIT(unk_A, 3)) obj->unk_4 |= 0x80000000;
            if (BIT(unk_8, 2) || BIT(unk_A, 2)) obj->unk_4 |= 0x40000000;
            CALL(fn_3_19C94());
        }
    }
    if ((lbl_1_bss_9F8[(state = &lbl_3_bss_A23EC)->unk_12].unk_8 >> 10 & 1)) {
        color = fn_3_19F7C(obj->unk_20, obj->unk_10, obj->unk_12);
        obj->unk_8 = color;
        if (((u8 *)&color)[3]) {
            fn_3_17830();
            fn_3_177AC(*(Color *)&color);
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
    if (BIT(unk_8, 9)) {
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
#undef BUF
#undef CALL
#undef INPUT
#undef BIT
/* fzgx:end fn_3_156D0 */

/* fzgx:begin fn_3_15F44 */
#define PF(off) (*(f32 *)((u8 *)&loc_C + (off)))
#define PB(off) (*((u8 *)&loc_C + (off)))

void fn_3_15F44(void) {
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
    EditPacket loc_C;
    u32 loc_8;
    u8 *t0;
    u16 t3;
    u32 t15;
    t0 = (u8 *)fn_3_14074();
    p_flags = &lbl_3_bss_A23EC;
    if ((p_flags->unk_C & 0x20000000) != 0) {
        v0 = p_flags->unk_14 - 1;
        p_flags->unk_14 = v0 < 0 ? 0 : v0 > 5 ? 5 : v0;
    } else {
        v1 = p_flags->unk_14 + 1;
        p_flags->unk_14 = v1 < 0 ? 0 : v1 > 5 ? 5 : v1;
    }
    v0 = 64 / (p_lbl_3_bss_A23EC = &lbl_3_bss_A23EC)->unk_11;
    v4 = *(s16 *)(t0 + 16);
    v6 = *(s16 *)(t0 + 18);
    v3 = (v0 / 2);
    v5 = (v0 / 2);
    if (v4 - v3 < 0) v4 = v3;
    else if (v4 + v3 >= 64) v4 = 64 - v3;
    if (v6 - v5 < 0) v6 = v5;
    else if (v6 + v5 >= 64) v6 = 64 - v5;

    loc_C = *(EditPacket *)lbl_1_rodata_26F8;
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

    loc_C = *(EditPacket *)lbl_1_rodata_26F8;
    v13 = 184.0f;
    v14 = 86.0f;
    loc_C.a[0] = 0x8607;
    PF(4) = v13; PF(8) = v14; PF(12) = 100.0f;
    loc_C.a[12] = 5;
    fn_1_4F734((FontDrawPacket *)&loc_C);
    t3 = fn_1_48690(loc_C.a[0]);
    v15 = 4503601774854144.0;
    PF(4) = ((t3 & 0xFFFF) + 184);
    loc_C.a[12] |= 0x80000;
    fn_1_4F734((FontDrawPacket *)&loc_C);
    if ((*(u32 *)t0 & 0x80000000) != 0) fn_3_16E14(192, 105);

    loc_C = *(EditPacket *)lbl_1_rodata_26F8;
    v22 = lbl_3_bss_A23EC.unk_14;
    v16 = 175.0f;
    v17 = 88.0f;
    v18 = 0x8605;
    v19 = 90.0f;
    v20 = 4503601774854144.0;
    v21 = 0.5f;
    loc_C.a[0] = v18;
    PF(4) = v16; PF(8) = v17; PF(12) = v19;
    PF(44) = v21 + (v22 / 10.0f);
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

    loc_C = *(EditPacket *)lbl_1_rodata_26F8;
    v29 = p_lbl_3_bss_A23EC->unk_11;
    loc_C.a[0] = 0x8603;
    v30 = v4;
    v31 = v29 << 1;
    v32 = 4503601774854144.0;
    v33 = v6;
    v34 = (202 + 4 * (v29 * (v3 + (*(s16 *)(t0 + 16) - v30))) + v31);
    PF(4) = v34;
    v35 = 94 + 4 * (v29 * (v5 + (*(s16 *)(t0 + 18) - v33))) + v31;
    PF(8) = v35;
    PF(12) = 29.0f;
    loc_C.a[12] = 10;
    fn_1_4F734((FontDrawPacket *)&loc_C);
    GXInvalidateTexAll();

    loc_C = *(EditPacket *)lbl_1_rodata_26F8;
    v36 = p_lbl_3_bss_A23EC->unk_11;
    v37 = 320.0f;
    v38 = 232.0f;
    v39 = 4.0f;
    v40 = 50.0f;
    PF(4) = 320.0f;
    PF(8) = 232.0f; PF(12) = 50.0f;
    PF(16) = PF(20) = 4.0f * v36;
    loc_C.a[12] = 0x400000A;
    loc_C.named.callback = (void (*)(void))fn_1_52690;
    if (v36 > 1) fn_1_517EC((FontDrawPacket *)&loc_C, v30-v3, v33-v5, v3<<1, v5<<1, 64, 64);
    fn_1_4FC50(&loc_C, 5, 64, 64, *(u32 *)(t0 + 32));

    loc_C = *(EditPacket *)lbl_1_rodata_26F8;
    v42 = 480.0f;
    v43 = 92.0f;
    v44 = 50.0f;
    v45 = 1.0f;
    PF(4) = v42; PF(8) = v43; PF(12) = v44;
    PF(16) = v45; PF(20) = 1.0714285373687744f;
    loc_C.a[12] = 5;
    fn_1_4FC50(&loc_C, 5, 64, 64, *(u32 *)(t0 + 32));

    t15 = fn_3_17820();
    v46 = lbl_801A66A0;
    v47 = 4503599627370496.0;
    v48 = 65535.0f;
    loc_8 = t15;
    v52 = (lbl_3_bss_A23EC.unk_17 * p_lbl_3_bss_A23EC->unk_11) & 0xFF;
    v53 = v48 * (v46 % 120);
    v54 = (lbl_3_bss_A23EC.unk_18 * p_lbl_3_bss_A23EC->unk_11) & 0xFF;
    v56 = (64.0f * (1.0f + lbl_8006D188((s32)(v53 / 119.0f))));

    loc_C = *(EditPacket *)lbl_1_rodata_26F8;
    v36 = p_lbl_3_bss_A23EC->unk_11;
    PF(4) = 320.0f;
    PF(8) = 232.0f;
    PF(12) = 30.0f;
    PF(16) = PF(20) = 4.0f * v36;
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
    fn_1_4FC50(&loc_C, 5, 64, 64, textures[(lbl_3_bss_A23EC.unk_0 + 1) % 2]);

    loc_C = *(EditPacket *)lbl_1_rodata_26F8;
    PF(4) = 480.0f;
    PF(8) = 92.0f;
    PF(12) = 30.0f;
    PF(16) = 1.0f;
    PF(20) = 1.0714285373687744f;
    loc_C.a[12] = 5;
    if (!__rlwnm(p_flags->unk_C, 3, 31, 31)) {
        PB(0x38) = PB(0x39) = PB(0x3A) = 255 - (u8)v56 * 2;
        PB(0x3C) = PB(0x3D) = PB(0x3E) = ((u8)v56 * 2);
    } else {
        PB(0x38) = PB(0x39) = PB(0x3A) = 255;
        PB(0x3C) = PB(0x3D) = PB(0x3A) = 0;
    }
    fn_1_4FC50(&loc_C, 5, 64, 64, textures[(lbl_3_bss_A23EC.unk_0 + 1) % 2]);
    lbl_3_bss_A23EC.unk_0 = (lbl_3_bss_A23EC.unk_0 + 1) % 2;
}
#undef PF
#undef PB
/* fzgx:end fn_3_15F44 */

/* fzgx:begin fn_3_1683C */
void fn_3_1683C(Arg0 *arg0, s16 off, s16 size) {
    s16 x;
    s16 y;
    u8 i;
    u8 j;
    Col4 colA;
    Col4 colB;
    Obj_3_bss_A23EC *p = &lbl_3_bss_A23EC;
    static const Col4 dark = {0x00000064};
    static const Col4 light = {0x37373764};
    x = arg0->unk_4;
    y = arg0->unk_8;
    off = 0;
    size = p->unk_11 << 3;
    colA = dark;
    colB = light;
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

/* fzgx:begin fn_3_169B8 */
#define SPEED (lbl_3_bss_A23EC.unk_11)
/* WARNING: compiler-diff device, not original code (volatile view of the pad port) */
#define PORT (*(volatile u8 *)&lbl_3_bss_A23EC.unk_12)
/* one bit of a controller's held-button word (0x14-byte pad records) */
#define BUTTON(p, n) ((lbl_1_bss_9F8[p].unk_10 >> (n)) & 1)
#define CLAMP_POS(v) ((v) < 1 ? 1 : ((v) > 62 ? 62 : (v)))

void fn_3_169B8(void)
{
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
    lbl_3_bss_A2408++;
    x = ((port)[lbl_1_bss_BF0]).x;
    y = ((port)[lbl_1_bss_BF0]).y;

    if ((x < -0.25f && (lbl_3_bss_A2408 % (SPEED + 6)) == 0) ||
        (x < -0.6f && (lbl_3_bss_A2408 % (SPEED + 4)) == 0) ||
        (x < -0.95f && (lbl_3_bss_A2408 % 4) == 0) ||
        BUTTON(port, 0)) {
        moved = 1;
        v = cursor->x - 1;
        cursor->x = CLAMP_POS(v);
        lbl_3_bss_A23E8 = 1;
    } else if ((x > 0.25f && (lbl_3_bss_A2408 % (SPEED + 6)) == 0) ||
               (x > 0.6f && (lbl_3_bss_A2408 % (SPEED + 4)) == 0) ||
               (x > 0.95f && (lbl_3_bss_A2408 % 4) == 0) ||
               BUTTON(PORT, 1)) {
        moved = 1;
        v = cursor->x + 1;
        cursor->x = CLAMP_POS(v);
        lbl_3_bss_A23E8 = 1;
    }

    if ((y > 0.25f && (lbl_3_bss_A2408 % (SPEED + 6)) == 0) ||
        (y > 0.6f && (lbl_3_bss_A2408 % (SPEED + 4)) == 0) ||
        (y > 0.95f && (lbl_3_bss_A2408 % 4) == 0) ||
        BUTTON(PORT, 3)) {
        moved = 1;
        v = cursor->y - 1;
        cursor->y = CLAMP_POS(v);
        lbl_3_bss_A23E8 = 1;
    } else if ((y < -0.25f && (lbl_3_bss_A2408 % (SPEED + 6)) == 0) ||
               (y < -0.6f && (lbl_3_bss_A2408 % (SPEED + 4)) == 0) ||
               (y < -0.95f && (lbl_3_bss_A2408 % 4) == 0) ||
               BUTTON(PORT, 2)) {
        moved = 1;
        v = cursor->y + 1;
        cursor->y = CLAMP_POS(v);
        lbl_3_bss_A23E8 = 1;
    }

    if (moved) {
        lbl_3_bss_A2408 = 1;
    }

    half = (64 / SPEED) / 2;
    if (lbl_3_bss_A240A + half / 2 < 63 || lbl_3_bss_A240A - half / 2 > 0) {
        lbl_3_bss_A240A = cursor->x;
    }
    {
        s32 half2 = half;
        if (lbl_3_bss_A240C + half2 / 2 < 63 || lbl_3_bss_A240C - half2 / 2 > 0) {
            lbl_3_bss_A240C = cursor->y;
        }
    }

    cursor->result = fn_3_19C94();
}
#undef SPEED
#undef PORT
#undef BUTTON
#undef CLAMP_POS
/* fzgx:end fn_3_169B8 */

/* fzgx:begin fn_3_16E14 */
/* WARNING: compiler-diff device, not original code (opt_common_subs off for this function only) */
#pragma opt_common_subs off
void fn_3_16E14(s16 x, s16 y) {
	u32 mode;
	s32 width;
	s32 hi;
	DrawPacket pkt;
	s32 lo;
	s32 count;
	u32 i;
	u32 n;
	u8 c;
	static const Col4 white = {0xFFFFFFFF};

	count = (0x100 / (u16)(0x40 / lbl_3_bss_A23EC.unk_11) - 1) & 0xFF;
	width = (u16)(0x40 / lbl_3_bss_A23EC.unk_11);
	pkt = *(DrawPacket *)lbl_1_rodata_26F8;
	pkt.unk_0 = 0xC;
	mode = 5;
	pkt.unk_30 = mode;
	lo = (count >> 1) & 0x7F;
	hi = lo + 5;
	pkt.unk_C = 28.0f;
	pkt.unk_3C = white.c;
	{
    s32 k;
for (k = 0; (u8)k < (u8)count; k++) {
		c = k;

		n = ((u8)k + 1) * width;
		pkt.unk_4 = (s32)(n + 191);
		pkt.unk_8 = 105.0f;
		pkt.unk_10 = 0.06f;
		pkt.unk_14 = 10.68f;
		fn_1_4F734((FontDrawPacket *)&pkt);
		pkt.unk_4 = 192.0f;
		pkt.unk_8 = (s32)(n + 104);
		pkt.unk_10 = 10.68f;
		if (c >= lo && c < hi) {
			pkt.unk_14 = 0.04f;
		} else {
			pkt.unk_14 = 0.06f;
		}
		fn_1_4F734((FontDrawPacket *)&pkt);
	}
    i = k;
}
}
#pragma opt_common_subs reset
/* fzgx:end fn_3_16E14 */

/* fzgx:begin fn_3_16FD0 */
void fn_3_16FD0(void *arg0) {
    BorderColor color = {0, 0, 0, 0};
    u32 i;
    for (i = 0; i < 64; i++) {
        BorderColor top = color;
        fn_3_14794(arg0, i, 0, &top);
        {
            BorderColor bottom = color;
            fn_3_14794(arg0, i, 63, &bottom);
        }
    }
    for (i = 0; i < 64; i++) {
        BorderColor left = color;
        fn_3_14794(arg0, 0, i, &left);
        {
            BorderColor right = color;
            fn_3_14794(arg0, 63, i, &right);
        }
    }
}
/* fzgx:end fn_3_16FD0 */
