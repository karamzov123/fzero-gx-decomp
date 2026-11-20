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

typedef struct Input {
    u16 unk_0;
    u8 pad_2[18];
} Input;

typedef struct Arg0 {
    u8 pad_0[4];
    f32 unk_4;
    f32 unk_8;
} Arg0;

typedef struct BorderColor { u8 r, g, b, a; } BorderColor;

typedef void (*EditorFunc)(EditObj *);

extern EditObj *fn_3_14074(void);
extern void *fn_1_45D0(void *, u32, char *, u32);
extern void fn_80008BEC(void *, u32, u32);
extern void fn_1_46B4(u32, u32, char *, int);
extern u32 lbl_801A6410;
extern u32 lbl_801A66A0;
extern u8 lbl_1_bss_9F8[];
extern StickInput lbl_1_bss_BF0[];
extern u8 lbl_1_rodata_26F8[];
extern u8 fn_3_19C94(void);
extern u32 fn_3_17820(void);
extern void fn_3_1445C(void);
extern u8 fn_3_14600(void);
extern u32 fn_3_19F7C(void *, s32, s32);
extern void fn_3_17830(void);
extern void fn_3_177AC(void *);
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
#define INPUT(off) (((u16 *)(lbl_1_bss_9F8 + (off)))[state->unk_12 * 10])
#define BIT(off, n) ((INPUT(off) >> (n)) & 1)

void fn_3_156D0(void) {
    EditObj *obj;
    Obj_3_bss_A23EC *state;
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
        if ((((u16 *)(lbl_1_bss_9F8 + 8))[(state = &lbl_3_bss_A23EC)->unk_12 * 10] >> 8 & 1) && (lbl_3_bss_A23EC.unk_C & 0x40000000)) {
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
        if (((((Input *)lbl_1_bss_9F8)[state->unk_12].unk_0 >> 8) & 1) && (lbl_3_bss_A23EC.unk_C & 0x80000000)) {
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
    if ((((u16 *)(lbl_1_bss_9F8 + 8))[(state = &lbl_3_bss_A23EC)->unk_12 * 10] >> 10 & 1)) {
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
    f32 t16;
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
#define BUTTON(p, n) ((((u16 *)(lbl_1_bss_9F8 + 0x10))[(p) * 10] >> (n)) & 1)
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

/* fzgx:begin fn_3_17098 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "font.h"

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3[0x1];
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 pad_7[0x1];
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    s16 unk_E;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
    s16 unk_18;
    u8 pad_1A[0x2];
    f32 unk_1C;
    s16 unk_20;
    u8 pad_22[0x6];
} Obj_3_bss_A2410;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

typedef struct BorderColor { u8 r, g, b, a; } BorderColor;


typedef struct StickInput {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
} StickInput;

typedef struct PadInput17100 {
    u8 pad_0[2];
    u16 unk_2;
    u8 pad_4[0xE];
    u16 unk_12;
} PadInput17100;

typedef struct PadD58 {
    u8 pad_0[0x12];
    u16 unk_12;
} PadD58;

extern u32 fn_3_14794(u32, s16, s16, void *);
extern f64 __fabs(f64);
extern StickInput lbl_1_bss_BF0[];
extern PadD58 lbl_1_bss_D58;
extern PadInput17100 lbl_1_bss_9F8[];
extern void fn_1_A2D84(u32);
extern u8 lbl_1_rodata_26F8[];
extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(s32);
extern void fn_1_49410(void);
extern void fn_1_4954C(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495B0(u32);
void fn_3_17100(void);
void fn_3_177AC(Color color);

/* editor palette (own data block of the retail TU) */
Color lbl_3_data_35C0[16] = {
    {0xED, 0x1C, 0x24, 0xFF}, {0xF7, 0x94, 0x1D, 0xFF}, {0xFF, 0xF2, 0x00, 0xFF}, {0x8D, 0xC6, 0x3F, 0xFF},
    {0x39, 0xB5, 0x4A, 0xFF}, {0x00, 0xAE, 0xEF, 0xFF}, {0x00, 0x54, 0xA6, 0xFF}, {0x66, 0x2D, 0x91, 0xFF},
    {0xEC, 0x00, 0x8C, 0xFF}, {0x9E, 0x0B, 0x0E, 0xFF}, {0x82, 0x7B, 0x00, 0xFF}, {0x00, 0x5E, 0x20, 0xFF},
    {0x00, 0x36, 0x63, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, {0x81, 0x81, 0x81, 0xFF}, {0x00, 0x00, 0x00, 0xFF},
};

Obj_3_bss_A2410 lbl_3_bss_A2410;

void fn_3_17098(void) {
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    lbl_3_bss_A2410.unk_C = 0;
    *(Color *)&lbl_3_bss_A2410.unk_4 = lbl_3_data_35C0[lbl_3_bss_A2410.unk_C];
    lbl_3_bss_A2410.unk_10 = 0;
    lbl_3_bss_A2410.unk_12 = 0;
    lbl_3_bss_A2410.unk_14 = 0;
    lbl_3_bss_A2410.unk_16 = 0xFF;
    lbl_3_bss_A2410.unk_20 = 0;
}
/* fzgx:end fn_3_17098 */

/* fzgx:begin fn_3_170E0 noprologue */
void fn_3_170E0(void) {
    fn_3_17100();
}
/* fzgx:end fn_3_170E0 */

/* fzgx:begin fn_3_17100 noprologue */
void fn_3_17100(void) {
    Obj_3_bss_A2410 *p_lbl_3_bss_A2410;
    Obj_3_bss_A2410 *branchMain;
    s32 v36;
    s32 v39;
    s32 v0;
    f32 v1;
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
    lbl_3_bss_A2410.unk_1C = 0.0f;
    } else {
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = ((u32 *)&lbl_3_data_35C0)[v3];
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_C -= 4;
    lbl_3_bss_A2410.unk_1C = 0.0f;
    fn_3_177AC(lbl_3_data_35C0[lbl_3_bss_A2410.unk_C]);
    }
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 6) & 0x1) != 0) {
    v0 = lbl_3_bss_A2410.unk_C;
    if ((v0 + 4) < 16) {
    v12 = (v0 << 2);
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = *(u32 *)((u8 *)&lbl_3_data_35C0 + v12);
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_C += 4;
    lbl_3_bss_A2410.unk_1C = 0.0f;
    }
    fn_3_177AC(lbl_3_data_35C0[lbl_3_bss_A2410.unk_C]);
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 4) & 0x1) != 0) {
    v14 = lbl_3_bss_A2410.unk_C;
    if (v14 % 4 != 0) {
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = ((u32 *)&lbl_3_data_35C0)[v14];
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_1C = 0.0f;
    lbl_3_bss_A2410.unk_C--;
    }
    fn_3_177AC(lbl_3_data_35C0[lbl_3_bss_A2410.unk_C]);
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 5) & 0x1) != 0) {
    v15 = lbl_3_bss_A2410.unk_C;
    if (v15 % 4 != 3) {
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = ((u32 *)&lbl_3_data_35C0)[v15];
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_1C = 0.0f;
    lbl_3_bss_A2410.unk_C++;
    }
    fn_3_177AC(lbl_3_data_35C0[lbl_3_bss_A2410.unk_C]);
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
    fn_3_177AC((Color){lbl_3_bss_A2410.unk_10, lbl_3_bss_A2410.unk_12, lbl_3_bss_A2410.unk_14, 255});
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
    lbl_3_bss_A2410.unk_1C = 0.0f;
    fn_3_177AC(lbl_3_data_35C0[lbl_3_bss_A2410.unk_C]);
    } else {
    lbl_3_bss_A2410.unk_8 = 0x80000000;
    fn_3_177AC((Color){lbl_3_bss_A2410.unk_10, lbl_3_bss_A2410.unk_12, lbl_3_bss_A2410.unk_14, 255});
    }
    }
    v0 = (u32)&lbl_1_bss_9F8;
    v0 = (u32)(v0 + 2);
    v0 = *(u16 *)(v0 + (lbl_3_bss_A2410.unk_D * 20));
    if (((v0 >> 4) & 0x1) != 0 || ((v0 >> 5) & 0x1) != 0) {
    v32 = (&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C];
    fn_3_177AC((Color){lbl_3_bss_A2410.unk_10, lbl_3_bss_A2410.unk_12, lbl_3_bss_A2410.unk_14, 255});
    v0 = (u32)&lbl_3_bss_A2410;
    if ((*(s16 *)((u8 *)v0 + 32)) > 40) {
    v1 = (lbl_1_bss_BF0[lbl_3_bss_A2410.unk_D].unk_8);
    if (v1 < 0.0f) {
    v34 = -8;
    } else {
    v34 = 8;
    }
    v34 = (s16)v34;
    } else {
    if ((*(s16 *)((u8 *)v0 + 32)) > 20) {
    v1 = (lbl_1_bss_BF0[lbl_3_bss_A2410.unk_D].unk_8);
    if (v1 < 0.0f) {
    v34 = -4;
    } else {
    v34 = 4;
    }
    v34 = (s16)v34;
    } else {
    v1 = (lbl_1_bss_BF0[lbl_3_bss_A2410.unk_D].unk_8);
    if (v1 < 0.0f) {
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
    v1 = (lbl_1_bss_BF0[lbl_3_bss_A2410.unk_D].unk_8);
    if (__fabs(v1) >= 0.8f) {
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

/* fzgx:begin fn_3_177AC noprologue */
void fn_3_177AC(Color color) {
    *(Color *)&lbl_3_bss_A2410.unk_4 = color;
    if (__rlwnm(lbl_3_bss_A2410.unk_8, 3, 31, 31)) {
        Color prev = {0, 0, 0, 255};
        prev.r = lbl_3_bss_A2410.unk_10;
        prev.g = lbl_3_bss_A2410.unk_12;
        prev.b = lbl_3_bss_A2410.unk_14;
        *(Color *)&lbl_3_bss_A2410.unk_0 = prev;
        lbl_3_bss_A2410.unk_10 = color.r;
        lbl_3_bss_A2410.unk_12 = color.g;
        lbl_3_bss_A2410.unk_14 = color.b;
    }
}
/* fzgx:end fn_3_177AC */

/* fzgx:begin fn_3_17820 noprologue */
u32 fn_3_17820(void) {
    return *(u32 *)&lbl_3_bss_A2410.unk_4;
}
/* fzgx:end fn_3_17820 */

/* fzgx:begin fn_3_17830 noprologue */
void fn_3_17830(void) {
    lbl_3_bss_A2410.unk_1C = 0.0f;
    lbl_3_bss_A2410.unk_8 |= 0x20000000u;
}
/* fzgx:end fn_3_17830 */

/* fzgx:begin fn_3_17854 noprologue */
#define PALETTE lbl_3_data_35C0
#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))
#define EDITOR lbl_3_bss_A2410
#define RGB(i) ((&lbl_3_bss_A2410.unk_10)[i])

void fn_3_17854(void) {
    FontDrawPacket pkt;
    u8 step;
    u8 channel;
    u8 i;
    u8 j;

    if (EDITOR.unk_8 & 0x80000000) {
        EDITOR.unk_18 = CLAMP(EDITOR.unk_18 + 1, 0, 10);
    } else {
        EDITOR.unk_18 = CLAMP(EDITOR.unk_18 - 1, 0, 10);
    }
    EDITOR.unk_1C = CLAMP(EDITOR.unk_1C + 0.1f, 0.0f, 1.0f);

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x8609;
    pkt.x = 456.0f;
    pkt.y = 86.0f;
    pkt.z = 75.0f;
    pkt.flags = 5;
    fn_1_4F734(&pkt);

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x860B;
    pkt.x = 474.0f;
    pkt.y = 141.0f;
    pkt.z = 60.0f;
    pkt.color[0] = 255;
    pkt.color[1] = 242;
    pkt.color[2] = 0;
    pkt.color[3] = 255;
    pkt.alpha = CLAMP(EDITOR.unk_18 / 10.0f, 0.0f, 1.0f);
    pkt.flags = 5;
    fn_1_4F734(&pkt);

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x860A;
    pkt.x = 474.0f;
    pkt.y = 294.0f;
    pkt.z = 60.0f;
    pkt.color[0] = 255;
    pkt.color[1] = 242;
    pkt.color[2] = 0;
    pkt.color[3] = 255;
    pkt.alpha = CLAMP(1.0f - EDITOR.unk_18 / 10.0f, 0.0f, 1.0f);
    pkt.flags = 5;
    fn_1_4F734(&pkt);

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x8634;
    pkt.x = 564.0f;
    pkt.y = 91.0f;
    pkt.z = 40.0f;
    if (__rlwnm(EDITOR.unk_8, 2, 31, 31) && !__rlwnm(EDITOR.unk_8, 3, 31, 31)) {
        pkt.color[0] = EDITOR.unk_0 * (1.0f - EDITOR.unk_1C) + EDITOR.unk_1C * PALETTE[EDITOR.unk_C].r;
        pkt.color[1] = EDITOR.unk_1 * (1.0f - EDITOR.unk_1C) + EDITOR.unk_1C * PALETTE[EDITOR.unk_C].g;
        pkt.color[2] = EDITOR.unk_2 * (1.0f - EDITOR.unk_1C) + EDITOR.unk_1C * PALETTE[EDITOR.unk_C].b;
    } else if (EDITOR.unk_8 & 0xA0000000) {
        pkt.color[0] = EDITOR.unk_0 * (1.0f - EDITOR.unk_1C) + EDITOR.unk_10 * EDITOR.unk_1C;
        pkt.color[1] = EDITOR.unk_1 * (1.0f - EDITOR.unk_1C) + EDITOR.unk_12 * EDITOR.unk_1C;
        pkt.color[2] = EDITOR.unk_2 * (1.0f - EDITOR.unk_1C) + EDITOR.unk_14 * EDITOR.unk_1C;
        pkt.color[3] = 255;
    }
    pkt.flags = 5;
    fn_1_4F734(&pkt);
    pkt.x = 587.0f;
    pkt.flags |= 0x80000;
    fn_1_4F734(&pkt);

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x860D;
    pkt.x = 565.0f;
    pkt.y = 152.0f;
    pkt.z = 50.0f;
    pkt.color[0] = EDITOR.unk_10;
    pkt.color[1] = EDITOR.unk_12;
    pkt.color[2] = EDITOR.unk_14;
    pkt.color[3] = 255;
    pkt.flags = 5;
    fn_1_4F734(&pkt);
    pkt.x = 585.0f;
    pkt.flags |= 0x80000;
    fn_1_4F734(&pkt);

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x8600;
    for (i = 0; i < 3; i++) {
        pkt.x = RGB(i) * 124 / 255 + 479;
        pkt.y = i * 40 + 203;
        pkt.z = 50.0f;
        pkt.flags = 5;
        fn_1_4F734(&pkt);
    }

    if (EDITOR.unk_8 & 0x40000000) {
        pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
        pkt.image = 0x8635;
        pkt.x = 474 + (EDITOR.unk_C % 4) * 33 + (EDITOR.unk_C % 4) / 2;
        pkt.y = (EDITOR.unk_C / 4) * 24 + 297;
        pkt.z = 40.0f;
        pkt.alpha = 1.0f - lbl_8006D188(65535.0f * (lbl_801A66A0 % 60) / 120.0f) / 2.0f;
        pkt.flags = 5;
        fn_1_4F734(&pkt);
    }

    if ((EDITOR.unk_8 & 0x80000000) && EDITOR.unk_C < 3) {
        pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
        pkt.image = 0x8636;
        pkt.x = 472.0f;
        pkt.y = EDITOR.unk_C * 40 + 186;
        pkt.z = 40.0f;
        pkt.alpha = 1.0f - lbl_8006D188(65535.0f * (lbl_801A66A0 % 60) / 120.0f) / 2.0f;
        pkt.flags = 5;
        fn_1_4F734(&pkt);
        pkt.x = 544.0f;
        pkt.y = EDITOR.unk_C * 40 + 186;
        pkt.flags |= 0x80000;
        fn_1_4F734(&pkt);
    }

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x863A;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            pkt.x = 482 + j * 33 + j / 2;
            pkt.y = i * 24 + 303;
            pkt.z = 40.0f;
            pkt.scale_x = 3.0f;
            pkt.scale_y = 1.5f;
            pkt.flags = 5;
            *(Color *)pkt.color = PALETTE[i * 4 + j];
            fn_1_4F734(&pkt);
        }
    }

    fn_1_49410();
    fn_1_4954C(30.0f);
    fn_1_496FC(484.0f, 174.0f);
    fn_1_495C8(0);
    fn_1_4955C(0.5f, 0.5f);
    fn_1_495B0(0x80000000);
    fn_1_4AE0C("R%3u", EDITOR.unk_10);
    fn_1_49410();
    fn_1_4954C(30.0f);
    fn_1_496FC(484.0f, 215.0f);
    fn_1_4955C(0.5f, 0.5f);
    fn_1_495C8(0);
    fn_1_495B0(0x80000000);
    fn_1_4AE0C("G%3u", EDITOR.unk_12);
    fn_1_49410();
    fn_1_4954C(30.0f);
    fn_1_496FC(484.0f, 255.0f);
    fn_1_495B0(0x80000000);
    fn_1_495C8(0);
    fn_1_4955C(0.5f, 0.5f);
    fn_1_4AE0C("B%3u", EDITOR.unk_14);

    pkt.image = 0x863A;
    pkt.z = 30.0f;
    pkt.scale_x = 0.5f;
    pkt.scale_y = 1.5f;
    pkt.flags = 5;
    for (channel = 0; channel < 3; channel++) {
        pkt.y = channel * 40 + 191;
        for (step = 0; step < 31; step++) {
            pkt.x = step * 4 + 482;
            switch (channel) {
            case 0:
                pkt.color[0] = step << 3;
                pkt.color[1] = EDITOR.unk_12;
                pkt.color[2] = EDITOR.unk_14;
                break;
            case 1:
                pkt.color[0] = EDITOR.unk_10;
                pkt.color[1] = step << 3;
                pkt.color[2] = EDITOR.unk_14;
                break;
            case 2:
                pkt.color[0] = EDITOR.unk_10;
                pkt.color[1] = EDITOR.unk_12;
                pkt.color[2] = step << 3;
                break;
            }
            fn_1_4F734(&pkt);
        }
    }

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x8601;
    pkt.x = 594.0f;
    pkt.y = 92.0f;
    pkt.z = 30.0f;
    pkt.flags = 5;
    fn_1_4F734(&pkt);
}
/* fzgx:end fn_3_17854 */
