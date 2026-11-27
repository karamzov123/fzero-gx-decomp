#include "types.h"
#include "dolphin/types.h"

/* Object put: queues model draws into the depth ordering table (ord_tbl.c) together with the render
 * state and light matrices that were current when they were queued. */

typedef struct {
    f32 x, y, z;
} ObjPutVec;

typedef f32 ObjPutMtx[3][4];

/* The game's shared work block; only the fields this TU uses are named. */
typedef struct {
    u8 unk_0[0xE0];
    ObjPutMtx lights[4];
} ObjPutWork;

typedef struct {
    u8 r, g, b, a;
} ObjPutColor;

/* Render state applied to every queued draw (0x28 bytes). */
typedef struct {
    ObjPutColor color;
    ObjPutColor color2;
    f32 scale;
    s8 zCompareEnable; /* z mode (fn_80074918, called with 1, 3, 1 = enable, LEQUAL, update) */
    u8 zCompareFunc;
    s8 zUpdateEnable;
    u8 unk_F;
    u8 dstAlphaEnable;
    u8 dstAlpha;
    u8 fogEnable;
    u8 fogType;
    ObjPutColor fogColor;
    f32 fogStart;
    f32 fogEnd;
    u32 unk_20;
    u32 unk_24;
} ObjPutState;

/* The object being drawn: a sphere tested against the frustum. */
typedef struct {
    u8 unk_0[8];
    ObjPutVec pos;
    f32 radius;
    u8 unk_18[2];
    u16 unk_1A;
    u16 unk_1C;
} ObjPutObject;

/* A queued draw: an ord_tbl node followed by the state captured when it was queued. */
typedef struct ObjPutNode {
    struct ObjPutNode *next;
    void (*drawFunc)(struct ObjPutNode *);
    ObjPutObject *obj;
    ObjPutMtx mtx;
    u16 unk_3C;
    ObjPutState state;
    ObjPutMtx *lights[4];
} ObjPutNode;

typedef void (*ObjPutCallback)(ObjPutObject *obj, void *arg0, void *arg1);

/* A queued draw that calls back into the caller. */
typedef struct {
    ObjPutNode node;
    void *arg0;
    void *arg1;
    ObjPutCallback callback;
} ObjPutCallbackNode;

typedef struct {
    u32 lightMask;
    u8 unk_4[0xC];
} ObjPutLights;

extern ObjPutWork *lbl_801A66CC;
extern void *lbl_801A6410;
extern void fn_800777D4(void);
extern void fn_80072808(void);
extern u32 fn_80070DE0(u32);
extern u32 fn_80070DF0(u32);
extern void *memset(void *, int, u32);
extern void fn_800749B0(s32 index, void *mtx);
extern void fn_800780A4(ObjPutObject *obj);
extern void *fn_1_5448C(ObjPutVec *pos);
extern void *fn_1_54448(s32 index);
extern void *fn_1_548AC(s32 size);
extern void fn_1_5489C(void *entry, void *node);
extern void lbl_8006DB74(ObjPutMtx mtx);
extern void lbl_8006DBAC(ObjPutMtx mtx);
extern void lbl_8006DD14(void *src, void *dst);
extern void lbl_8006D784(void *mtx);
extern u16 fn_1_7BE94(void);
extern void fn_1_7BEAC(u16 value);
extern s32 fn_1_54F5C(ObjPutVec *center, f32 radius, f32 scale);
extern void fn_80072558(void);
extern void fn_80077E7C(ObjPutObject *obj);
extern void fn_80077F8C(ObjPutObject *obj);
extern void fn_800781B8(ObjPutObject *obj);
extern void fn_80074CF4();
extern void fn_80074B40(ObjPutColor *color);
extern void fn_80074C74(ObjPutColor *color);
extern void fn_80074918(u8 compareEnable, int compareFunc, u8 updateEnable);
extern void fn_80077B04(f32 value);
extern void fn_80077BBC(u8 value);
extern void fn_80037D40(u8 enable, u8 alpha); /* GXSetDstAlpha */
extern void fn_80074A7C(u32 value);
extern void fn_80077BAC(u32 value);
extern void fn_80071ED4(u8 type, f32 start, f32 end); /* fog parameters (avdisp) */
extern void fn_80072014(ObjPutColor *color);
extern void fn_800720B0(int enable);
extern void fn_80070D60(void *callbacks);
extern void fn_1_45730(void);
extern void fn_1_45B2C(void);
extern void fn_1_458A0(void);
extern void fn_1_45850(void);
extern void fn_1_45D0(void *heap, void *ptr, char *file, int line);
extern void fn_1_46B4(void *heap, void *ptr, char *file, int line);

void fn_1_55210(ObjPutObject *obj);
void fn_1_556B8(ObjPutObject *obj);
void fn_1_557C4(ObjPutObject *obj);
void fn_1_55924(ObjPutObject *obj, s32 index);
void fn_1_55C48(ObjPutNode *node);
void fn_1_55D6C(ObjPutCallbackNode *node);
void fn_1_55EA0(ObjPutNode *node);
void fn_1_563E4(ObjPutState *state);
void fn_1_56470(ObjPutState *state);
void fn_1_56530(void);
void fn_1_56554(void);
u8 *fn_1_565E8(void);
void fn_1_565F4(void);
void fn_1_565F8(void);
void fn_1_56664(void *ptr);
void fn_1_566A0(void *ptr);
void fn_1_566EC(int enable, u8 alpha);

void *lbl_1_bss_6C798;
u32 lbl_1_bss_6C79C;
f32 lbl_1_bss_6C7A0;
ObjPutState lbl_1_bss_6C7A4;
ObjPutLights lbl_1_bss_6C7CC;
u8 lbl_1_bss_6C7DC[100];

/* fzgx:begin fn_1_55118 */
static inline void init_state(ObjPutState *state) {
    memset(state, 0, sizeof(ObjPutState));
    state->color.r = 255;
    state->color.g = 255;
    state->color.b = 255;
    state->color.a = 255;
    state->color2.r = 0;
    state->color2.g = 0;
    state->color2.b = 0;
    state->color2.a = 0;
    state->scale = 1.0f;
    state->zCompareEnable = 1;
    state->zCompareFunc = 3;
    state->zUpdateEnable = 1;
    state->unk_F = 0;
    state->dstAlphaEnable = 0;
    state->dstAlpha = 0;
}

/* Initialises the module (called by _prolog). */
void fn_1_55118(void) {
    lbl_1_bss_6C798 = lbl_801A6410;
    fn_800777D4();
    fn_1_565F8();
    fn_80072808();
    fn_80070DE0((u32)fn_1_56664);
    fn_80070DF0((u32)fn_1_566A0);
    lbl_1_bss_6C79C = 0x60;
    lbl_1_bss_6C7A0 = 1.0f;
    init_state(&lbl_1_bss_6C7A4);
    fn_1_566EC(0, 0);
    fn_800749B0(0, 0);
    lbl_1_bss_6C7CC.lightMask = 0;
}
/* fzgx:end fn_1_55118 */

/* fzgx:begin fn_1_55210 */
void fn_1_55210(ObjPutObject *obj) {
    ObjPutNode *node;
    void *entry;
    s32 ok;
    s32 i;

    if (1.0f == lbl_1_bss_6C7A4.scale) {
        if (obj->unk_1C == 0) {
            fn_1_556B8(obj);
            return;
        }
        if (obj->unk_1A != 0) {
            fn_1_563E4(&lbl_1_bss_6C7A4);
            fn_800780A4(obj);
        }
        entry = fn_1_5448C(&obj->pos);
        node = fn_1_548AC(sizeof(ObjPutNode));
        if (node != NULL) {
            node->drawFunc = fn_1_55EA0;
            node->obj = obj;
            ok = 1;
            lbl_8006DB74(node->mtx);
            node->unk_3C = fn_1_7BE94();
            node->state = lbl_1_bss_6C7A4;
            for (i = 0; i < 4; i++) {
                /* WARNING: compiler-diff device, not original code: __rlwnm light-bit test (7 natural spellings measured, best 4 words off) */
                if (__rlwnm(lbl_1_bss_6C7CC.lightMask, (i + 1) & 31, 31, 31) != 0) {
                    node->lights[i] = fn_1_548AC(sizeof(ObjPutMtx));
                    if (node->lights[i] != NULL) {
                        lbl_8006DD14(&lbl_801A66CC->lights[i], node->lights[i]);
                    } else {
                        ok = 0;
                    }
                } else {
                    node->lights[i] = NULL;
                }
            }
            if (ok != 0) {
                fn_1_5489C(entry, node);
            }
        }
        fn_1_56530();
    } else {
        fn_1_557C4(obj);
    }
}
/* fzgx:end fn_1_55210 */

/* fzgx:begin fn_1_553C4 */
void fn_1_553C4(ObjPutObject *obj, s32 index) {
    ObjPutNode *node;
    void *entry;
    s32 ok;
    s32 i;

    if (1.0f == lbl_1_bss_6C7A4.scale) {
        if (obj->unk_1C == 0) {
            fn_1_556B8(obj);
            return;
        }
        if (obj->unk_1A != 0) {
            fn_1_563E4(&lbl_1_bss_6C7A4);
            fn_800780A4(obj);
        }
        entry = fn_1_54448(index);
        node = fn_1_548AC(sizeof(ObjPutNode));
        if (node != NULL) {
            node->drawFunc = fn_1_55EA0;
            node->obj = obj;
            ok = 1;
            lbl_8006DB74(node->mtx);
            node->unk_3C = fn_1_7BE94();
            node->state = lbl_1_bss_6C7A4;
            for (i = 0; i < 4; i++) {
                /* WARNING: compiler-diff device, not original code: __rlwnm light-bit test (7 natural spellings measured, best 4 words off) */
                if (__rlwnm(lbl_1_bss_6C7CC.lightMask, (i + 1) & 31, 31, 31) != 0) {
                    node->lights[i] = fn_1_548AC(sizeof(ObjPutMtx));
                    if (node->lights[i] != NULL) {
                        lbl_8006DD14(&lbl_801A66CC->lights[i], node->lights[i]);
                    } else {
                        ok = 0;
                    }
                } else {
                    node->lights[i] = NULL;
                }
            }
            if (ok != 0) {
                fn_1_5489C(entry, node);
            }
        }
        fn_1_56530();
    } else {
        fn_1_55924(obj, index);
    }
}
/* fzgx:end fn_1_553C4 */

/* fzgx:begin fn_1_5557C */
void fn_1_5557C(ObjPutObject *obj) {
    if (fn_1_54F5C(&obj->pos, obj->radius, lbl_1_bss_6C7A0)) {
        fn_1_55210(obj);
        return;
    }
    fn_1_56530();
}
/* fzgx:end fn_1_5557C */

/* fzgx:begin fn_1_555D0 */
void fn_1_555D0(ObjPutObject *obj) {
    if (fn_1_54F5C(&obj->pos, obj->radius, lbl_1_bss_6C7A0)) {
        fn_80072558();
        fn_1_55210(obj);
        return;
    }
    fn_1_56530();
}
/* fzgx:end fn_1_555D0 */

/* fzgx:begin fn_1_55628 */
void fn_1_55628(ObjPutObject *obj) {
    if (obj->unk_1C != 0 || 1.0f != lbl_1_bss_6C7A4.scale) {
        fn_1_557C4(obj);
    } else {
        fn_1_556B8(obj);
    }
}
/* fzgx:end fn_1_55628 */

/* fzgx:begin fn_1_55678 */
void fn_1_55678(ObjPutObject *obj) {
    fn_1_563E4(&lbl_1_bss_6C7A4);
    fn_80077E7C(obj);
    fn_1_56530();
}
/* fzgx:end fn_1_55678 */

/* fzgx:begin fn_1_556B8 */
/* Draws the object at once. */
void fn_1_556B8(ObjPutObject *obj) {
    fn_1_563E4(&lbl_1_bss_6C7A4);
    fn_80077F8C(obj);
    fn_1_56530();
}
/* fzgx:end fn_1_556B8 */

/* fzgx:begin fn_1_556F8 */
void fn_1_556F8(ObjPutObject *obj) {
    if (fn_1_54F5C(&obj->pos, obj->radius, lbl_1_bss_6C7A0)) {
        fn_1_563E4(&lbl_1_bss_6C7A4);
        fn_80077F8C(obj);
        fn_1_56530();
        return;
    }
    fn_1_56530();
}
/* fzgx:end fn_1_556F8 */

/* fzgx:begin fn_1_5575C */
void fn_1_5575C(ObjPutObject *obj) {
    if (fn_1_54F5C(&obj->pos, obj->radius, lbl_1_bss_6C7A0)) {
        fn_80072558();
        fn_1_563E4(&lbl_1_bss_6C7A4);
        fn_80077F8C(obj);
        fn_1_56530();
        return;
    }
    fn_1_56530();
}
/* fzgx:end fn_1_5575C */

/* fzgx:begin fn_1_557C4 */
/* Queues the object in the depth ordering table at its view depth. */
void fn_1_557C4(ObjPutObject *obj) {
    ObjPutNode *node;
    void *entry;
    s32 ok;
    s32 i;

    entry = fn_1_5448C(&obj->pos);
    node = fn_1_548AC(sizeof(ObjPutNode));
    if (node != NULL) {
        ok = 1;
        node->drawFunc = fn_1_55C48;
        node->obj = obj;
        lbl_8006DB74(node->mtx);
        node->unk_3C = fn_1_7BE94();
        node->state = lbl_1_bss_6C7A4;
        for (i = 0; i < 4; i++) {
            /* WARNING: compiler-diff device, not original code: __rlwnm light-bit test (7 natural spellings measured, best 4 words off) */
            if (__rlwnm(lbl_1_bss_6C7CC.lightMask, (i + 1) & 31, 31, 31) != 0) {
                node->lights[i] = fn_1_548AC(sizeof(ObjPutMtx));
                if (node->lights[i] != NULL) {
                    lbl_8006DD14(&lbl_801A66CC->lights[i], node->lights[i]);
                } else {
                    ok = 0;
                }
            } else {
                node->lights[i] = NULL;
            }
        }
        if (ok != 0) {
            fn_1_5489C(entry, node);
        }
    }
    fn_1_56530();
}
/* fzgx:end fn_1_557C4 */

/* fzgx:begin fn_1_55924 */
/* Queues the object in the given entry of the depth ordering table. */
void fn_1_55924(ObjPutObject *obj, s32 index) {
    ObjPutNode *node;
    void *entry;
    s32 ok;
    s32 i;

    entry = fn_1_54448(index);
    node = fn_1_548AC(sizeof(ObjPutNode));
    if (node != NULL) {
        node->drawFunc = fn_1_55C48;
        node->obj = obj;
        ok = 1;
        lbl_8006DB74(node->mtx);
        node->unk_3C = fn_1_7BE94();
        node->state = lbl_1_bss_6C7A4;
        for (i = 0; i < 4; i++) {
            /* WARNING: compiler-diff device, not original code: __rlwnm light-bit test (7 natural spellings measured, best 4 words off) */
            if (__rlwnm(lbl_1_bss_6C7CC.lightMask, (i + 1) & 31, 31, 31)) {
                node->lights[i] = fn_1_548AC(sizeof(ObjPutMtx));
                if (node->lights[i] != NULL) {
                    lbl_8006DD14(&lbl_801A66CC->lights[i], node->lights[i]);
                } else {
                    ok = 0;
                }
            } else {
                node->lights[i] = NULL;
            }
        }
        if (ok != 0) {
            fn_1_5489C(entry, node);
        }
    }
    fn_1_56530();
}
/* fzgx:end fn_1_55924 */

/* fzgx:begin fn_1_55A84 */
/* Queues a callback draw, or calls it at once when the object needs no sorting. */
void fn_1_55A84(ObjPutCallback callback, ObjPutObject *obj, void *arg0, void *arg1) {
    ObjPutCallbackNode *node;
    void *entry;
    s32 ok;
    s32 i;

    if (obj->unk_1C != 0 || 1.0f != lbl_1_bss_6C7A4.scale) {
        entry = fn_1_5448C(&obj->pos);
        node = fn_1_548AC(sizeof(ObjPutCallbackNode));
        if (node != NULL) {
            ok = 1;
            node->node.drawFunc = (void (*)(ObjPutNode *))fn_1_55D6C;
            node->node.obj = obj;
            lbl_8006DB74(node->node.mtx);
            node->node.unk_3C = fn_1_7BE94();
            node->node.state = lbl_1_bss_6C7A4;
            for (i = 0; i < 4; i++) {
                /* WARNING: compiler-diff device, not original code: __rlwnm light-bit test (7 natural spellings measured, best 4 words off) */
                if (__rlwnm(lbl_1_bss_6C7CC.lightMask, (i + 1) & 31, 31, 31) != 0) {
                    node->node.lights[i] = fn_1_548AC(sizeof(ObjPutMtx));
                    if (node->node.lights[i] != NULL) {
                        lbl_8006DD14(&lbl_801A66CC->lights[i], node->node.lights[i]);
                    } else {
                        ok = 0;
                    }
                } else {
                    node->node.lights[i] = NULL;
                }
            }
            node->arg0 = arg0;
            node->arg1 = arg1;
            node->callback = callback;
            if (ok != 0) {
                fn_1_5489C(entry, node);
            }
        }
        fn_1_56530();
    } else {
        fn_1_563E4(&lbl_1_bss_6C7A4);
        callback(obj, arg0, arg1);
        fn_1_56530();
    }
}
/* fzgx:end fn_1_55A84 */

/* fzgx:begin fn_1_55C48 */
/* Draw function of a node queued by fn_1_557C4/fn_1_55924. */
void fn_1_55C48(ObjPutNode *node) {
    s32 i;
    s32 j;

    lbl_8006DBAC(node->mtx);
    fn_80072558();
    fn_1_56470(&node->state);
    fn_1_7BEAC(node->unk_3C);
    for (i = 0; i < 4; i++) {
        if (node->lights[i] != NULL) {
            fn_800749B0(i, node->lights[i]);
        /* WARNING: compiler-diff device, not original code: __rlwnm light-bit test (7 natural spellings measured, best 4 words off) */
        } else if (__rlwnm(lbl_1_bss_6C7CC.lightMask, (i + 1) & 31, 31, 31) != 0) {
            fn_800749B0(i, NULL);
        }
    }
    fn_80077F8C(node->obj);
    fn_1_56554();
    for (j = 0; j < 4; j++) {
        /* WARNING: compiler-diff device, not original code: __rlwnm light-bit test (7 natural spellings measured, best 4 words off) */
        if (__rlwnm(lbl_1_bss_6C7CC.lightMask, (j + 1) & 31, 31, 31) != 0) {
            fn_800749B0(j, &lbl_801A66CC->lights[j]);
        } else if (node->lights[j] != NULL) {
            fn_800749B0(j, NULL);
        }
    }
}
/* fzgx:end fn_1_55C48 */

/* fzgx:begin fn_1_55D6C */
/* Draw function of a node queued by fn_1_55A84. */
void fn_1_55D6C(ObjPutCallbackNode *node) {
    s32 i;
    s32 j;

    lbl_8006DBAC(node->node.mtx);
    fn_80072558();
    fn_1_56470(&node->node.state);
    fn_1_7BEAC(node->node.unk_3C);
    for (i = 0; i < 4; i++) {
        if (node->node.lights[i] != NULL) {
            fn_800749B0(i, node->node.lights[i]);
        /* WARNING: compiler-diff device, not original code: __rlwnm light-bit test (7 natural spellings measured, best 4 words off) */
        } else if (__rlwnm(lbl_1_bss_6C7CC.lightMask, (i + 1) & 31, 31, 31) != 0) {
            fn_800749B0(i, NULL);
        }
    }
    node->callback(node->node.obj, node->arg0, node->arg1);
    fn_1_56554();
    for (j = 0; j < 4; j++) {
        /* WARNING: compiler-diff device, not original code: __rlwnm light-bit test (7 natural spellings measured, best 4 words off) */
        if (__rlwnm(lbl_1_bss_6C7CC.lightMask, (j + 1) & 31, 31, 31) != 0) {
            fn_800749B0(j, &lbl_801A66CC->lights[j]);
        } else if (node->node.lights[j] != NULL) {
            fn_800749B0(j, NULL);
        }
    }
}
/* fzgx:end fn_1_55D6C */

/* fzgx:begin fn_1_55EA0 */
/* Draw function of a node queued by fn_1_55210/fn_1_553C4. */
void fn_1_55EA0(ObjPutNode *node) {
    s32 i;
    s32 j;

    lbl_8006DBAC(node->mtx);
    fn_80072558();
    fn_1_56470(&node->state);
    fn_1_7BEAC(node->unk_3C);
    for (i = 0; i < 4; i++) {
        if (node->lights[i] != NULL) {
            fn_800749B0(i, node->lights[i]);
        /* WARNING: compiler-diff device, not original code: __rlwnm light-bit test (7 natural spellings measured, best 4 words off) */
        } else if (__rlwnm(lbl_1_bss_6C7CC.lightMask, (i + 1) & 31, 31, 31) != 0) {
            fn_800749B0(i, NULL);
        }
    }
    fn_800781B8(node->obj);
    fn_1_56554();
    for (j = 0; j < 4; j++) {
        /* WARNING: compiler-diff device, not original code: __rlwnm light-bit test (7 natural spellings measured, best 4 words off) */
        if (__rlwnm(lbl_1_bss_6C7CC.lightMask, (j + 1) & 31, 31, 31) != 0) {
            fn_800749B0(j, &lbl_801A66CC->lights[j]);
        } else if (node->lights[j] != NULL) {
            fn_800749B0(j, NULL);
        }
    }
}
/* fzgx:end fn_1_55EA0 */

/* fzgx:begin fn_1_55FC4 */
void fn_1_55FC4(f32 scale) {
    lbl_1_bss_6C7A0 = scale;
}
/* fzgx:end fn_1_55FC4 */

/* fzgx:begin fn_1_55FD0 */
void fn_1_55FD0(void) {
    fn_80074CF4();
}
/* fzgx:end fn_1_55FD0 */

/* fzgx:begin fn_1_55FF0 */
void fn_1_55FF0(f32 scale) {
    lbl_1_bss_6C7A4.scale = scale;
}
/* fzgx:end fn_1_55FF0 */

/* fzgx:begin fn_1_56000 */
void fn_1_56000(u8 compareEnable, u8 compareFunc, u8 updateEnable) {
    lbl_1_bss_6C7A4.zCompareEnable = compareEnable;
    lbl_1_bss_6C7A4.zCompareFunc = compareFunc;
    lbl_1_bss_6C7A4.zUpdateEnable = updateEnable;
}
/* fzgx:end fn_1_56000 */

/* fzgx:begin fn_1_56018 */
/* Turns all lights off (enable 0) or reloads the enabled ones; returns whether any light was enabled. */
u32 fn_1_56018(s32 enable) {
    s32 i;
    u32 result;

    result = (-lbl_1_bss_6C7CC.lightMask | lbl_1_bss_6C7CC.lightMask) >> 31;
    if (enable == 0) {
        for (i = 0; i < 4; i++) {
            /* WARNING: compiler-diff device, not original code: __rlwnm light-bit test (7 natural spellings measured, best 4 words off) */
            if (__rlwnm(lbl_1_bss_6C7CC.lightMask, (i + 1) & 31, 31, 31)) {
                fn_800749B0(0, NULL);
            }
        }
        lbl_1_bss_6C7CC.lightMask = 0;
    } else {
        for (i = 0; i < 4; i++) {
            /* WARNING: compiler-diff device, not original code: __rlwnm light-bit test (7 natural spellings measured, best 4 words off) */
            if (__rlwnm(lbl_1_bss_6C7CC.lightMask, (i + 1) & 31, 31, 31)) {
                fn_800749B0(i, &lbl_801A66CC->lights[i]);
            }
        }
    }
    return result;
}
/* fzgx:end fn_1_56018 */

/* fzgx:begin fn_1_560F0 */
/* Enables light index with the matrix mtx. */
void fn_1_560F0(s32 index, void *mtx) {
    if (mtx != NULL) {
        lbl_1_bss_6C7CC.lightMask |= (1u << 31) >> index;
        lbl_8006DD14(mtx, &lbl_801A66CC->lights[index]);
    }
    fn_800749B0(index, mtx);
}
/* fzgx:end fn_1_560F0 */

/* fzgx:begin fn_1_5616C */
/* Enables light index with the current matrix moved to (x, y). */
void fn_1_5616C(s32 index, f32 x, f32 y) {
    lbl_1_bss_6C7CC.lightMask |= (1u << 31) >> index;
    lbl_8006D784(&lbl_801A66CC->lights[index]);
    lbl_801A66CC->lights[index][0][3] = x;
    lbl_801A66CC->lights[index][1][3] = y;
    fn_800749B0(index, &lbl_801A66CC->lights[index]);
}
/* fzgx:end fn_1_5616C */

/* fzgx:begin fn_1_5621C */
void fn_1_5621C(f32 r, f32 g, f32 b, f32 a) {
    lbl_1_bss_6C7A4.color.r = 255.0f * r;
    lbl_1_bss_6C7A4.color.g = 255.0f * g;
    lbl_1_bss_6C7A4.color.b = 255.0f * b;
    lbl_1_bss_6C7A4.color.a = 255.0f * a;
    fn_80074B40(&lbl_1_bss_6C7A4.color);
}
/* fzgx:end fn_1_5621C */

/* fzgx:begin fn_1_56298 */
void fn_1_56298(f32 r, f32 g, f32 b, f32 a) {
    lbl_1_bss_6C7A4.color2.r = 255.0f * r;
    lbl_1_bss_6C7A4.color2.g = 255.0f * g;
    lbl_1_bss_6C7A4.color2.b = 255.0f * b;
    lbl_1_bss_6C7A4.color2.a = 255.0f * a;
    fn_80074C74(&lbl_1_bss_6C7A4.color2);
}
/* fzgx:end fn_1_56298 */

/* fzgx:begin fn_1_5631C */
void fn_1_5631C(ObjPutColor *color) {
    lbl_1_bss_6C7A4.color2 = *color;
    fn_80074C74(color);
}
/* fzgx:end fn_1_5631C */

/* fzgx:begin fn_1_5634C */
void fn_1_5634C(u8 enable) {
    lbl_1_bss_6C7A4.fogEnable = enable;
}
/* fzgx:end fn_1_5634C */

/* fzgx:begin fn_1_5635C */
void fn_1_5635C(u8 type, f32 start, f32 end) {
    lbl_1_bss_6C7A4.fogType = type;
    lbl_1_bss_6C7A4.fogStart = start;
    lbl_1_bss_6C7A4.fogEnd = end;
}
/* fzgx:end fn_1_5635C */

/* fzgx:begin fn_1_56374 */
void fn_1_56374(u8 r, u8 g, u8 b) {
    lbl_1_bss_6C7A4.fogColor.r = r;
    lbl_1_bss_6C7A4.fogColor.g = g;
    lbl_1_bss_6C7A4.fogColor.b = b;
}
/* fzgx:end fn_1_56374 */

/* fzgx:begin fn_1_5638C */
void fn_1_5638C(u32 value) {
    lbl_1_bss_6C7A4.unk_20 = value;
    fn_80074A7C(value);
}
/* fzgx:end fn_1_5638C */

/* fzgx:begin fn_1_563B8 */
void fn_1_563B8(u32 value) {
    lbl_1_bss_6C7A4.unk_24 = value;
    fn_80077BAC(value);
}
/* fzgx:end fn_1_563B8 */

/* fzgx:begin fn_1_563E4 */
/* Applies part of a render state (scale, z mode and, when unk_24 is 0, the fog). */
void fn_1_563E4(ObjPutState *state) {
    ObjPutColor color;

    fn_80077B04(state->scale);
    fn_80074918(state->zCompareEnable, state->zCompareFunc, state->zUpdateEnable);
    if (state->unk_24 == 0) {
        if (state->fogEnable != 0) {
            fn_80071ED4(state->fogType, state->fogStart, state->fogEnd);
            color = state->fogColor;
            fn_80072014(&color);
            fn_800720B0(1);
        } else {
            fn_800720B0(0);
        }
    }
}
/* fzgx:end fn_1_563E4 */

/* fzgx:begin fn_1_56470 */
/* Applies a whole render state. */
void fn_1_56470(ObjPutState *state) {
    ObjPutColor color;

    fn_80077B04(state->scale);
    fn_80074B40(&state->color);
    fn_80074C74(&state->color2);
    fn_80074918(state->zCompareEnable, state->zCompareFunc, state->zUpdateEnable);
    fn_80077BBC(state->unk_F);
    fn_80037D40(state->dstAlphaEnable, state->dstAlpha);
    fn_80074A7C(state->unk_20);
    fn_80077BAC(state->unk_24);
    if (state->unk_24 == 0) {
        if (state->fogEnable != 0) {
            fn_80071ED4(state->fogType, state->fogStart, state->fogEnd);
            color = state->fogColor;
            fn_80072014(&color);
            fn_800720B0(1);
        } else {
            fn_800720B0(0);
        }
    }
}
/* fzgx:end fn_1_56470 */

/* fzgx:begin fn_1_56530 */
/* Resets both scales to 1. */
void fn_1_56530(void) {
    lbl_1_bss_6C7A0 = 1.0f;
    lbl_1_bss_6C7A4.scale = 1.0f;
}
/* fzgx:end fn_1_56530 */

/* fzgx:begin fn_1_56554 */
/* Reapplies the current render state (except the scale and the fog). */
void fn_1_56554(void) {
    fn_80074B40(&lbl_1_bss_6C7A4.color);
    fn_80074C74(&lbl_1_bss_6C7A4.color2);
    fn_80074918(lbl_1_bss_6C7A4.zCompareEnable, lbl_1_bss_6C7A4.zCompareFunc, lbl_1_bss_6C7A4.zUpdateEnable);
    fn_80077BBC(lbl_1_bss_6C7A4.unk_F);
    fn_80037D40(lbl_1_bss_6C7A4.dstAlphaEnable, lbl_1_bss_6C7A4.dstAlpha);
    fn_80074A7C(lbl_1_bss_6C7A4.unk_20);
    fn_80077BAC(lbl_1_bss_6C7A4.unk_24);
}
/* fzgx:end fn_1_56554 */

/* fzgx:begin fn_1_565E8 */
u8 *fn_1_565E8(void) {
    return lbl_1_bss_6C7DC;
}
/* fzgx:end fn_1_565E8 */

/* fzgx:begin fn_1_565F4 */
void fn_1_565F4(void) {
}
/* fzgx:end fn_1_565F4 */

/* fzgx:begin fn_1_565F8 */
/* Registers the module's callbacks. */
void fn_1_565F8(void) {
    void (*callbacks[6])(void);

    callbacks[0] = (void (*)(void))fn_1_565E8;
    callbacks[1] = fn_1_45730;
    callbacks[2] = fn_1_45B2C;
    callbacks[3] = fn_1_458A0;
    callbacks[4] = fn_1_45850;
    callbacks[5] = fn_1_565F4;
    fn_80070D60(callbacks);
}
/* fzgx:end fn_1_565F8 */

/* fzgx:begin fn_1_56664 */
/* Allocation callback: allocates from the module heap. */
void fn_1_56664(void *ptr) {
    fn_1_45D0(lbl_801A6410, ptr, "objput.c", 1273);
}
/* fzgx:end fn_1_56664 */

/* fzgx:begin fn_1_566A0 */
/* Free callback. */
void fn_1_566A0(void *ptr) {
    fn_1_46B4(lbl_801A6410, ptr, "objput.c", 1281);
}
/* fzgx:end fn_1_566A0 */

/* fzgx:begin fn_1_566DC */
u32 fn_1_566DC(void) {
    return lbl_1_bss_6C79C;
}
/* fzgx:end fn_1_566DC */

/* fzgx:begin fn_1_566EC */
void fn_1_566EC(int enable, u8 alpha) {
    lbl_1_bss_6C7A4.dstAlphaEnable = enable;
    lbl_1_bss_6C7A4.dstAlpha = alpha;
    fn_80037D40(enable, alpha);
}
/* fzgx:end fn_1_566EC */

/* fzgx:begin fn_1_56724 */
int fn_1_56724(void) {
    return 1;
}
/* fzgx:end fn_1_56724 */
