#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/rob.h"

extern void fn_1_12ABB4(void *arg0);
extern void fn_1_96230(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_41850(void *arg0);
extern u32 lbl_1_bss_6E98C;
extern u16 fn_1_96B14(void *base, void *arg1, s32 index);
extern s32 fn_80083BCC(void *arg0, void *arg1);
extern void ADXT_Stop(u32 arg0);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern void fn_80008BEC(void *, u32, u32);

extern const char *lbl_1_data_20D1C[];
extern void sprintf(char *buffer, u8 *format, ...);
extern s32 fn_1_12A32C(char *buffer);
extern s16 fn_1_98104(void);

/* fzgx:begin fn_1_95EF0 noprologue */
#include "types.h"

struct fn_1_95EF0_Arg0 {
    u8 pad_0[0x14C];
    u32 unk_14C;
};
struct fn_1_95EF0_lbl_801A6410 {
    u32 unk_0;
};
extern struct fn_1_95EF0_lbl_801A6410 lbl_801A6410;
extern u8 lbl_1_data_27C00[];
extern void fn_1_12ABB4(void *);
extern void fn_1_46B4(u32, u32, const char *, int);

void fn_1_95EF0(void *arg0, s32 arg_sp0) {
    void *var_r28;
    void *temp_r3_7;
    void *temp_r3_6;
    void *temp_r3_5;
    void *temp_r3_4;
    void *temp_r3_3;
    void *temp_r3_2;
    void *temp_r3;
    u32 var_r27;
    u32 temp_r4_7;
    u32 temp_r4_6;
    u32 temp_r4_5;
    u32 temp_r4_4;
    u32 temp_r4_3;
    u32 temp_r4_2;
    u32 temp_r4;

    temp_r3 = (void *)(*(void **)((u8 *)(arg0) + 332));
    if (temp_r3 != NULL) {
        fn_1_12ABB4((void *)(temp_r3));
        (*(void **)((u8 *)(arg0) + 332)) = (void *)(NULL);
    }
    temp_r4 = *(u32 *)((u8 *)(arg0) + 336);
    if (temp_r4 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4, (const char *)((s8 *) lbl_1_data_27C00), 0xB44);
        (*(u32 *)((u8 *)(arg0) + 336)) = 0U;
    }
    temp_r3_2 = (void *)(*(void **)((u8 *)(arg0) + 364));
    if (temp_r3_2 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_2));
        (*(void **)((u8 *)(arg0) + 364)) = (void *)(NULL);
    }
    temp_r4_2 = *(u32 *)((u8 *)(arg0) + 368);
    if (temp_r4_2 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_2, (const char *)((s8 *) lbl_1_data_27C00), 0xB49);
        (*(u32 *)((u8 *)(arg0) + 368)) = 0U;
    }
    temp_r3_3 = (void *)(*(void **)((u8 *)(arg0) + 396));
    if (temp_r3_3 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_3));
        (*(void **)((u8 *)(arg0) + 396)) = (void *)(NULL);
    }
    temp_r4_3 = *(u32 *)((u8 *)(arg0) + 400);
    if (temp_r4_3 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_3, (const char *)((s8 *) lbl_1_data_27C00), 0xB4B);
        (*(u32 *)((u8 *)(arg0) + 400)) = 0U;
    }
    temp_r3_4 = (void *)(*(void **)((u8 *)(arg0) + 428));
    if (temp_r3_4 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_4));
        (*(void **)((u8 *)(arg0) + 428)) = (void *)(NULL);
    }
    temp_r4_4 = *(u32 *)((u8 *)(arg0) + 432);
    if (temp_r4_4 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_4, (const char *)((s8 *) lbl_1_data_27C00), 0xB4D);
        (*(u32 *)((u8 *)(arg0) + 432)) = 0U;
    }
    temp_r3_5 = (void *)(*(void **)((u8 *)(arg0) + 460));
    if (temp_r3_5 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_5));
        (*(void **)((u8 *)(arg0) + 460)) = (void *)(NULL);
    }
    temp_r4_5 = *(u32 *)((u8 *)(arg0) + 464);
    if (temp_r4_5 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_5, (const char *)((s8 *) lbl_1_data_27C00), 0xB4F);
        (*(u32 *)((u8 *)(arg0) + 464)) = 0U;
    }
    temp_r3_6 = (void *)(*(void **)((u8 *)(arg0) + 492));
    if (temp_r3_6 != NULL) {
        fn_1_12ABB4((void *)(temp_r3_6));
        (*(void **)((u8 *)(arg0) + 492)) = (void *)(NULL);
    }
    temp_r4_6 = *(u32 *)((u8 *)(arg0) + 496);
    if (temp_r4_6 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, temp_r4_6, (const char *)((s8 *) lbl_1_data_27C00), 0xB51);
        (*(u32 *)((u8 *)(arg0) + 496)) = 0U;
    }
    var_r28 = (void *)(arg0);
    var_r27 = 0U;
    do {
        temp_r3_7 = (void *)(*(void **)((u8 *)(var_r28) + 524));
        if (temp_r3_7 != NULL) {
            fn_1_12ABB4((void *)(temp_r3_7));
            (*(void **)((u8 *)(var_r28) + 524)) = (void *)(NULL);
        }
        temp_r4_7 = *(u32 *)((u8 *)(var_r28) + 528);
        if (temp_r4_7 != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, temp_r4_7, (const char *)((s8 *) lbl_1_data_27C00), 0xB54);
            (*(u32 *)((u8 *)(var_r28) + 528)) = 0U;
        }
        var_r27 += 1;
        var_r28 = (void *)((u8 *)(var_r28) + 0x20);
    } while (var_r27 < 0x14U);
}
/* fzgx:end fn_1_95EF0 */

/* fzgx:begin fn_1_961F0 */
typedef struct Fn1961F0Owner Fn1961F0Owner;

struct Fn1961F0Owner {
    u8 unk_00[0x0C];
    void *resource;
};

void fn_1_961F0(Fn1961F0Owner *owner) {
    if (owner->resource != 0) {
        fn_1_12ABB4(owner->resource);
        owner->resource = 0;
    }
}
/* fzgx:end fn_1_961F0 */

/* fzgx:begin fn_1_96630 */
typedef struct Fn196630Object Fn196630Object;

struct Fn196630Object {
    u8 unk_00[0x88];
    void *value_88;
};

void fn_1_96630(Fn196630Object *object, void *arg1, void *arg2) {
    fn_1_96230(object, object->value_88, arg1, arg2, 0);
}
/* fzgx:end fn_1_96630 */

/* fzgx:begin fn_1_96664 */
void fn_1_96664(void *arg0, void *arg1, void *arg2) {
    fn_1_96230(0, arg0, arg1, arg2, 1);
}
/* fzgx:end fn_1_96664 */

/* fzgx:begin fn_1_966A0 */
typedef struct Fn1966A0Object Fn1966A0Object;
struct Fn1966A0Object {
    u32 entries[0x39];
    u32 resource_e4;
    u8 unk_E8[0x10];
    u32 resource_f8;
};

extern void fn_1_12A2D0(s32 arg0);
extern void fn_80071718(u32 arg0);
extern void fn_800711A8(u32 arg0);

void fn_1_966A0(Fn1966A0Object *object) {
    u8 *slot;
    u8 *group;
    u8 *outer;
    int i;
    int j;
    s32 value;
    u8 *walk;

    group = (u8 *)object;
    outer = (u8 *)object;
    for (i = 0; i < 5; i++) {
        slot = group;
        for (j = 0; j < 4; j++) {
            if (((Fn1966A0Object *)slot)->resource_f8 != 0) {
                if (*(s32 *)(outer + 4) != -1) {
                    fn_1_12A2D0(*(s32 *)(outer + 4));
                }
                fn_80071718(((Fn1966A0Object *)slot)->resource_f8);
                ((Fn1966A0Object *)slot)->resource_f8 = 0;
            }
            slot += 4;
        }
        if (((Fn1966A0Object *)outer)->resource_e4 != 0) {
            if (*(s32 *)(outer + 4) != -1) {
                fn_1_12A2D0(*(s32 *)(outer + 4));
            }
            fn_800711A8(((Fn1966A0Object *)outer)->resource_e4);
            ((Fn1966A0Object *)outer)->resource_e4 = 0;
        }
        group += 0x10;
        outer += 4;
    }

    value = -1;
    walk = (u8 *)object;
    for (i = 0; i < 5; i++) {
        if (*(s32 *)(walk + 4) != -1) {
            value = object->entries[i + 1];
            break;
        }
        walk += 4;
    }
    if (value != -1) {
        fn_1_12A2D0(value);
    }
}
/* fzgx:end fn_1_966A0 */

/* fzgx:begin fn_1_968FC */
typedef struct Fn1968FCChild Fn1968FCChild;
typedef struct Fn1968FCObject Fn1968FCObject;

struct Fn1968FCChild {
    u8 unk_00[0x08];
    u32 unk_08;
    u8 unk_0c[0x10];
    u32 unk_1c;
};

struct Fn1968FCObject {
    u8 unk_00[0x1c];
    Fn1968FCChild *unk_1c;
    void *unk_20;
};

void fn_1_968FC(Fn1968FCObject *object) {
    if (object->unk_20 != 0) {
        fn_1_12ABB4(object->unk_20);
        object->unk_20 = 0;
    }

    if (object->unk_1c != 0) {
        object->unk_1c->unk_1c = 0;
        object->unk_1c->unk_08 = 0;
        fn_1_41850(object->unk_1c);
        object->unk_1c = 0;
    }
}
/* fzgx:end fn_1_968FC */

/* fzgx:begin fn_1_96AE8 */
void fn_1_96AE8(void *base, void *arg1) {
    fn_1_96B14(base, arg1, lbl_1_bss_6E98C);
}
/* fzgx:end fn_1_96AE8 */

/* fzgx:begin fn_1_96C40 */
#include "dolphin/hw_regs.h"

extern void fn_1_12ABB4(void *arg0);
extern void fn_1_96230(void *arg0, void *arg1, void *arg2, void *arg3, int arg4);
extern void fn_1_41850(void *arg0);
extern u32 lbl_1_bss_6E98C;
extern u16 fn_1_96B14(void *base, void *arg1, s32 index);
extern s32 fn_80083BCC(void *arg0, void *arg1);
extern void ADXT_Stop(u32 arg0);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern void fn_80008BEC(void *, u32, u32);

extern const char *lbl_1_data_20D1C[];
extern void sprintf(char *buffer, u8 *format, ...);
extern s32 fn_1_12A32C(char *buffer);
extern s16 fn_1_98104(void);


typedef struct {
    u8 r, g, b, a;
} RobColor;

extern u32 lbl_801A6D00;
extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 lbl_8006DCA4(void);
extern void fn_8003462C(u32, u32, u32);
extern void fn_8007245C(u32);
extern void fn_800724C8(void);
extern void fn_800725DC(RobColor *);
extern void fn_80072614(RobColor *);
extern void fn_80072864(u32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072EDC(s32, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);

/* Pool primer: reproduces the TU literal pool (lbl_1_rodata_3E48 .. +0x1D0) ahead of
   this function's own initializers and literals; .fzgxpool is dropped at integration. */
extern void fzgx_sink(const void *p);
extern void fzgx_sinkf(f32 f);
extern s32 fzgx_int;

#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer(void) {
    /* lbl_1_rodata_3E48 / 3E70: string pointer tables (relocated words, zero in the file) */
    u32 names[0x49] = {0};

    fzgx_sink(names);
    fzgx_sinkf(0.0f);
    fzgx_sinkf(1.0f);
    fzgx_sinkf(100.0f);
    fzgx_sinkf(180.0f);
    fzgx_sinkf(32767.0f);
    fzgx_sinkf((f32)fzgx_int);
}

__declspec(section ".fzgxpool") void fzgx_pool_primer2(void) {
    u32 words[36] = {
        0xFFFFFFFF, 0xBF800000, 0xFFFFFFFF, 0x425C0000, 0x41F00000, 0x447A0000,
        0x404040FF, 0x00000000, 0x00000000, 0x00000000,
        0x3B963DC5, 0xBD6DD053, 0xBD953A3F, 0x3B963DC5, 0xBD6DD053, 0x3CF0307F,
        0xBB963DC5, 0xBD6DD053, 0xBD953A3F, 0xBB963DC5, 0xBD6DD053, 0x3CF0307F,
        0x43360B61, 0x3E4F5C29, 0x3D851EB8, 0x3DAE147B, 0x3FA99999, 0x9999999A,
        0x3D4CCCCD, 0x3BA3D70A, 0xBC8F5C29, 0x477FFF00, 0x43300000, 0x00000000,
        0x42480000, 0xBF800000,
    };

    fzgx_sink(words);
}

/* GX write-gather FIFO: every store is a hardware write, hence volatile. */
#define GX_FIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)

#pragma defer_codegen on
static void fn_1_96C40_grid(s32 cx, s32 cz);

void fn_1_96C40(void *arg0) {
    RobColor colA = {0x40, 0x40, 0x60, 0x80};
    RobColor colB = {0x00, 0x00, 0x00, 0x00};
    s32 cx;
    s32 cz;
    RobColor c0;
    RobColor c1;

    lbl_8006DCA4();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    cx = (s32)*(f32 *)((u8 *)arg0 + 0xA8);
    cz = (s32)*(f32 *)((u8 *)arg0 + 0xB0);
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(1);
    c0 = colA;
    fn_800725DC(&c0);
    c1 = colB;
    fn_80072614(&c1);
    fn_800747D0(4, 0, 0, 0, 0, 0, 2);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 255, 255, 4);
    fn_80072EDC(0, 4);
    fn_80072864(0);
    fn_1_96C40_grid(cx, cz);
}

/* Draws a 21x21 checkerboard of unit quads around (cx, cz), one colour per pass. */
static inline void fn_1_96C40_grid(s32 cx, s32 cz) {
    s32 j;
    s32 i;
    s32 pass;
    f32 z1;
    f32 z0;
    f32 x1;
    f32 x0;

    for (pass = 0; pass < 2; pass++) {
        for (i = -10; i <= 10; i++) {
            x0 = (f32)(cx + i) - 0.5f;
            x1 = 0.5f + (f32)(cx + i);
            for (j = -10; j <= 10; j++) {
                if ((u32)pass == ((i + j) & 1)) {
                    continue;
                }
                z0 = (f32)(cz + j) - 0.5f;
                z1 = 0.5f + (f32)(cz + j);
                fn_8003462C(0x80, 7, 4);
                GX_FIFO_F32 = x0;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z0;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = x1;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z0;
                GX_FIFO_F32 = 1.0f;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = x1;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z1;
                GX_FIFO_F32 = 1.0f;
                GX_FIFO_F32 = 1.0f;
                GX_FIFO_F32 = x0;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = z1;
                GX_FIFO_F32 = 0.0f;
                GX_FIFO_F32 = 1.0f;
            }
        }
        {
            RobColor colC = {0x00, 0x20, 0x40, 0x80};

            fn_800725DC(&colC);
        }
    }
}
#pragma defer_codegen reset
/* fzgx:end fn_1_96C40 */

/* fzgx:begin fn_1_97174 */
typedef struct Fn197174Owner Fn197174Owner;
typedef struct Fn197174Root Fn197174Root;
typedef struct Fn197174Entry Fn197174Entry;

struct Fn197174Owner {
    u8 unk_00[0x14];
    u8 *base;
};

struct Fn197174Root {
    u8 unk_00[0x08];
    u16 count;
};

struct Fn197174Entry {
    u8 unk_00[0x1C];
    u32 offset;
};

extern Fn197174Root *fn_1_41BDC(void);
extern Fn197174Entry *fn_1_41B18(Fn197174Owner *owner, void *arg1, s32 index);

s32 fn_1_97174(Fn197174Owner *owner, void *arg1, void *arg2) {
    Fn197174Root *root = fn_1_41BDC();
    s32 index = 0;

    while (index < (s32)root->count) {
        Fn197174Entry *entry = fn_1_41B18(owner, arg1, index);
        if (fn_80083BCC(owner->base + entry->offset, arg2) == 0) {
            return index;
        }
        index++;
    }
    return -1;
}
/* fzgx:end fn_1_97174 */

/* fzgx:begin fn_1_97204 */
extern void fn_1_9724C(void *arg0, void *arg1);
extern u8 fn_1_97F80(void *arg0, void *arg1);

void fn_1_97204(void *arg0, void *arg1) {
    fn_1_9724C(arg0, arg1);
    if (fn_1_97F80(arg0, arg1)) {
        return;
    }
}
/* fzgx:end fn_1_97204 */

/* fzgx:begin fn_1_9724C */
// Loads the active resource value when the initialization check has not completed.
void fn_1_9724C(void) {
    if (fn_1_98104() == 0) {
        ADXT_Stop(lbl_1_bss_6EAD0.unk_0->unk_4);
    }
}
/* fzgx:end fn_1_9724C */

/* fzgx:begin fn_1_97F1C */
typedef struct {
    u8 unk_000[0x4A4];
    s32 unk_4A4;
} Fn197F1CObject;

/* Formats the indexed message and stores its parsed value in the object. */
s16 fn_1_97F1C(Fn197F1CObject *object, s16 index) {
    char buffer[0x80];

    sprintf(buffer, lbl_1_data_27D90, lbl_1_data_20D1C[index]);
    object->unk_4A4 = fn_1_12A32C(buffer);
    return (s16)object->unk_4A4;
}
/* fzgx:end fn_1_97F1C */

/* fzgx:begin fn_1_97F80 noprologue */
#include "types.h"

extern u32 lbl_801A6410;

typedef struct Fn197F80Object Fn197F80Object;
struct Fn197F80Object {
    u8 unk_000[0x488];
    u8 unk_488;
    u8 unk_489;
    u8 unk_48A[0x1A];
    void *unk_4A4;
    void *unk_4A8;
    void *unk_4AC;
    void *unk_4B0;
    void *unk_4B4;
};

extern u32 lbl_1_data_209C0;



extern void *fn_80083970(const char *, const char *);
extern void sprintf(char *, const char *, ...);
extern int fn_80083BCC(const char *, const char *);
extern void fn_1_12A2D0(void *);
extern void fn_1_12A2B8(int);
extern void fn_1_12AB38(const char *);
extern int fn_1_12A8A4(const char *, void **);
extern void *fn_1_4630(u32, u32, const char *, u32);
extern void fn_80083DB0(void *, const char *);
extern u32 strlen(const char *);

u32 fn_1_97F80(Fn197F80Object *rob, const char *name) {
    void *resource = 0;
    char path[0x40];
    u8 *data = (u8 *)&lbl_1_data_209C0;
    u32 length;

    if (name == 0 || fn_80083970(name, (const char *)(data + 0x6390)) == 0) {
        return 0;
    }

    sprintf(path, (const char *)(data + 0x73e0), name);
    if (fn_80083BCC(path, (const char *)(data + 0x73e8)) == 0 ||
        fn_80083BCC(path, (const char *)(data + 0x73f4)) == 0 ||
        fn_80083BCC(path, (const char *)(data + 0x7400)) == 0 ||
        fn_80083BCC(path, (const char *)(data + 0x740c)) == 0) {
        return 1;
    }

    fn_1_12A2D0(rob->unk_4A4);
    fn_1_12A2B8(1);
    fn_1_12AB38((const char *)(data + 0x7418));
    if (fn_1_12A8A4(path, &resource) == 0) {
        return 0;
    }

    fn_1_12AB38((const char *)(data + 0x6eec));
    fn_1_12A2B8(0);
    length = strlen(name);
    rob->unk_488 = 1;
    rob->unk_489 = 1;
    rob->unk_4A8 = resource;
    rob->unk_4AC = *(void **)resource;
    rob->unk_4B0 = (u8 *)resource + 4;
    rob->unk_4B4 = fn_1_4630(*(u32 *)&lbl_801A6410,
                            (length + 0x20) & ~0x1f,
                            (const char *)(data + 0x7240), 0xfa9);
    fn_80083DB0(rob->unk_4B4, name);
    return 1;
}
/* fzgx:end fn_1_97F80 */

/* fzgx:begin fn_1_98104 noprologue */
#include "types.h"

extern u8 lbl_1_data_27C00[0xE0];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern void fn_80008BEC(void *, u32, u32);

typedef struct Fn198104Obj {
    u8 unk_00[0x1C];
    u32 value_1C;
    u8 unk_20[0x0C];
    u32 value_2C;
} Fn198104Obj;

s32 fn_1_98104(Fn198104Obj *obj) {
    Fn198104Obj *ptr = (Fn198104Obj *)((u8 *)obj + 0x488);
    u32 saved;

    if (ptr == 0) {
        return 0;
    }

    saved = ptr->value_1C;
    if (ptr->value_2C != 0) {
        fn_1_46B4(lbl_801A6410, ptr->value_2C, lbl_1_data_27C00, 0xfc0);
        ptr->value_2C = 0;
    }

    fn_80008BEC(ptr, 0, 0x30);
    ptr->value_1C = saved;
    return 1;
}
/* fzgx:end fn_1_98104 */

/* fzgx:begin fn_1_9818C */
extern u32 fn_1_12A734(u32);

s32 fn_1_9818C(u32 arg0) {
    s16 v0;
    s32 v1;
    u32 t0;
    v0 = (s16)arg0;
    v1 = v0;
    if (v0 != -1) {
    t0 = fn_1_12A734(v1);
    v1 = t0;
    v1 = 1;
    } else {
    v1 = 0;
    }
    return v1;
}
/* fzgx:end fn_1_9818C */
