#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect.h"

typedef struct fn_1_58D38_EffectEntry {
    s8 unk_00;
    u8 pad_01[7];
    u32 unk_08;
    s16 unk_0C;
    u8 pad_0E[0x0C];
    u16 unk_1A;
    u8 pad_1C[0xCC];
} fn_1_58D38_EffectEntry;

struct fn_1_5BF70_lbl_1_rodata_2950 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f64 unk_20;
    u8 pad_28[0xC8];
    f64 unk_F0;
    f64 unk_F8;
    u8 pad_100[0x30];
    f64 unk_130;
};

typedef struct {
    u8 unk00[0x18];
    s16 value18;
    u8 unk1A[2];
    f32 value1C;
    f32 value20;
    f32 value24;
    f32 value28;
    u8 unk2C[8];
    void *field34;
    u8 unk38[0x1c];
    s16 value54;
    s16 value56;
} fn_1_5FEBC_EffectData;

typedef struct {
    u8 unk00[8];
    fn_1_5FEBC_EffectData *data;
} fn_1_5FEBC_EffectObject;

typedef struct {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x20];
    u32 unk_34;
    void *unk_38;
    u8 pad_3c[0x18];
    s16 unk_54;
    u8 pad_56[0x4];
    u16 unk_5a;
    u8 pad_5c[0x58];
    f32 unk_b4;
} fn_1_61D08_EffectObject;

typedef struct {
    u8 pad_00[0x8];
    void *unk_08;
} fn_1_652F4_Effect;

typedef struct {
    u8 pad20[0x20];
    void *unk_20;
} Fn1_61E60Node;

typedef struct {
    u8 pad38[0x38];
    Fn1_61E60Node *unk_38;
} Fn1_61E60Object;
extern void fn_1_62360(fn_1_58D38_EffectEntry *arg0);
extern u32 fn_1_3FC58(void);
extern void *memcpy(void *, const void *, u32);
extern void fn_1_862D4(s16 value, void *result);
extern f32 lbl_8006D0B4(f32 value);
extern s32 fn_1_54E34(void *arg0, f32 arg1);
extern void lbl_8006D7B0(void);
extern void lbl_8006D9D8(void *);
extern void mathutil_mtxA_rotate_z(int);
extern const f32 lbl_1_rodata_2950;
extern void fn_1_8636C();
extern void fn_1_867CC(s16 value, void *out);
extern void mathutil_mtxA_rotate_y(s16 value);
extern void mathutil_mtxA_rotate_x(s16 value);
extern void lbl_8006DB74(void *);
extern int fn_1_9F914(const void *src0, const void *src1);
extern const f32 lbl_1_rodata_2AA0[21];
extern f32 lbl_1_rodata_29AC[5];
extern void *memset(void *, int, u32);
extern void *lbl_801A6D00;
extern void fn_1_55FC4(f32 value);
extern void fn_1_55FF0(f32 value);
extern void fn_1_5557C(void *object);
extern void fn_1_555D0(void *object);
extern void lbl_8006E1B0(void *src, void *dst);
extern void lbl_8006E14C(f32);
extern void *lbl_801A6410;
extern s32 fn_1_45D0();
extern u32 GXGetTexBufferSize(u16, u16, u32, u32, u8);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_4730(u32 value, u32 count, u32 size, const char *file, int line);
extern void lbl_8006DCA4();
extern void lbl_8006D7DC(void *obj);
extern void *fn_1_868C0(s8 index);
extern void *fn_1_86254(int index);
extern void lbl_8006D95C(s32);
extern void lbl_8006DFC4(void *);
extern void fn_1_3BDC(u32 arg0);
extern u32 fn_1_3C18(s32 arg0);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_80008BA8(void *, void *, int);
extern void fn_1_680F8(void);
extern void fn_1_68284(void);
extern void fn_1_68B68(void);
extern void fn_1_68248(void);
extern void fn_1_69BBC(void);
extern void fn_1_69BCC(void);
extern f32 lbl_1_rodata_2978[4];
extern f32 lbl_1_rodata_2AF4[14];
extern void fn_1_5EB98(void);
extern void fn_1_5FEBC(fn_1_5FEBC_EffectObject *object);
extern f32 lbl_1_rodata_2A5C[5];
extern int fn_1_61D08();
extern void fn_1_61EF4(void);
extern void fn_1_620C4(void);
extern f32 lbl_1_rodata_2B2C[145];
extern void fn_1_638E8(void);
extern const f32 lbl_1_rodata_2A70[12];
extern void fn_1_64388(void);
extern void fn_1_652F4(fn_1_652F4_Effect *effect);
extern void fn_1_65748(void);
extern void *fn_1_5448C(void *);
extern int fn_1_61E60();
extern void fn_1_5489C(void **arg0, void **arg1);
extern void *fn_1_548AC(u32 size);
extern u32 fn_1_3FC8C(void);
extern const f32 lbl_1_rodata_29A4;
extern f64 lbl_1_rodata_2988;
extern u32 fn_1_620C8(void *);
extern f32 fn_1_8652C(int index);
extern void fn_1_557C4(void *value);
extern void fn_1_56000(u8 value0, u8 value1, u8 value2);
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern const f32 lbl_1_rodata_29C0;
extern const f32 lbl_1_rodata_29F0;
extern u32 fn_1_58C4(void);
extern const f64 lbl_1_rodata_2954;

/* fzgx:begin fn_1_58994 noprologue */
#include "types.h"
#include "rel/main_rel/effect.h"

typedef struct AvlineVec3 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} AvlineVec3;

typedef struct AvlineEntry {
    s8 unk_00;
    u8 pad01[0x07];
    u32 unk_08;
    s16 unk_0c;
    u8 pad0e[0x02];
    u32 unk_10;
    u32 unk_14;
    u8 pad18[0x02];
    u16 unk_1a;
    u8 pad1c[0x20];
    AvlineVec3 unk_3c;
    u8 pad48[0x18];
    AvlineVec3 unk_60;
    u8 pad6c[0x7c];
} AvlineEntry;

typedef void (*AvlineHandler)(AvlineEntry *);

typedef struct AvlineTables {
    u8 pad000[0xd68];
    AvlineHandler unk_d68[0x45];
    AvlineHandler unk_e7c[0x45];
    u32 unk_f90;
} AvlineTables;

typedef struct AvlineState {
    AvlineEntry *unk_00;
    AvlineEntry *unk_04;
    u32 unk_08;
    u32 unk_0c;
} AvlineState;

typedef struct Effect_63518Vec {
    u32 x;
    u32 y;
    u32 z;
} Effect_63518Vec;

typedef struct Effect_63518 {
    u8 unk00[0x14];
    u32 unk14;
    u8 unk18[0x20];
    Effect_63518Vec *unk38;
    Effect_63518Vec unk3c;
    u8 unk48[0x10];
    u16 unk58;
    u8 unk5a[0x06];
    Effect_63518Vec unk60;
    u8 unk6c[0x40];
    u16 unkac;
    u16 unkae;
    u16 unkb0;
} Effect_63518;

extern void fn_1_3BDC(s32);
extern s32 fn_1_3F164(void);
extern void fn_1_9F8FC(void);
extern void fn_1_5819C(void);
extern u32 fn_1_58C4(void);
extern u32 camera_forward_status(void);
extern u32 fn_1_3C18(s32);
extern void fn_1_63518(Effect_63518 *);

static inline AvlineHandler *fn_1_58994_array_read(AvlineHandler *array) { return array; }
#pragma opt_propagation off
void fn_1_58994(void) {
    AvlineTables *tables = (AvlineTables *)&lbl_1_data_1C698;
    u16 active_2;
    AvlineState *state = (AvlineState *)&lbl_1_bss_6C848;
    u32 value;
    struct { u32 value; } active;
    AvlineHandler *tbl;
    AvlineEntry *entry;
    s32 count;
    u32 mode;
    u16 mask;
    u32 best;

    fn_1_3BDC(9);
    if (fn_1_3F164() != 0) {
        tables->unk_f90 = 1;
    }
    fn_1_9F8FC();
    fn_1_5819C();
    mode = fn_1_58C4();
    if (mode >= 1 && mode <= 4) {
        mask = 1 << (mode - 1);
    } else {
        mask = 0xffff;
    }

    entry = state->unk_00;
    if ((camera_forward_status() & 0x80000000) == 0) {
        active.value = mask;
        tbl = tables->unk_d68;
        count = 0xbe;
        while (count > 0) {
            if (entry->unk_00 != 0) {
                if ((entry->unk_1a & active.value) != 0) {
                    if ((entry->unk_08 & 0x80000000) == 0) {
                        tbl[entry->unk_0c](entry);
                    }
                }
            }
            entry++;
            count--;
        }
{
    AvlineEntry * fzgx_loop_entry_2643;
        fzgx_loop_entry_2643 = state->unk_04;
        tbl = tables->unk_d68;
        count = 0xc8;
        while (count > 0) {
            if (fzgx_loop_entry_2643->unk_00 != 0) {
                if ((fzgx_loop_entry_2643->unk_1a & active.value) != 0) {
                    if ((fzgx_loop_entry_2643->unk_08 & 0x80000000) == 0) {
                        tbl[fzgx_loop_entry_2643->unk_0c](fzgx_loop_entry_2643);
                    }
                }
            }
            fzgx_loop_entry_2643++;
            count--;
        }
    entry = fzgx_loop_entry_2643;
}
    } else {
        active_2 = mask;
        count = 0xbe;
        while (count > 0) {
            if (entry->unk_00 != 0) {
                if ((entry->unk_1a & active_2) != 0) {
                    if ((entry->unk_08 & 0x80000000) == 0) {
                        if ((entry->unk_08 & 0x08000000) != 0) {
                            fn_1_58994_array_read(tables->unk_e7c)[entry->unk_0c](entry);
                            entry->unk_00 = 0;
                        } else {
                            if ((entry->unk_08 & 0x70000000) != 0) {
                                entry->unk_60 = entry->unk_3c;
                            }
                            if (entry->unk_0c == 28) {
                                fn_1_63518((Effect_63518 *)entry);
                            }
                            fn_1_58994_array_read(tables->unk_d68)[entry->unk_0c](entry);
                        }
                    }
                }
            }
            entry++;
            count--;
        }
        entry = state->unk_04;
        count = 0xc8;
        while (count > 0) {
            if (entry->unk_00 != 0) {
                if ((entry->unk_1a & active_2) != 0) {
                    if ((entry->unk_08 & 0x80000000) == 0) {
                        if ((entry->unk_08 & 0x08000000) != 0) {
                            fn_1_58994_array_read(tables->unk_e7c)[entry->unk_0c](entry);
                            entry->unk_00 = 0;
                        } else {
                            if ((entry->unk_08 & 0x70000000) != 0) {
                                entry->unk_60 = entry->unk_3c;
                            }
                            if (entry->unk_0c == 28) {
                                fn_1_63518((Effect_63518 *)entry);
                            }
                            fn_1_58994_array_read(tables->unk_d68)[entry->unk_0c](entry);
                        }
                    }
                }
            }
            entry++;
            count--;
        }
    }

    value = fn_1_3C18(9);
    best = state->unk_0c;
    if (value > best) {
        best = value;
    }
    state->unk_0c = best;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_58994 */

/* fzgx:begin fn_1_58C6C */
struct fn_1_58C6C_lbl_1_bss_6C848_T {
    u8 unk_0;
    u8 pad_1[0x7];
    u32 unk_8;
    s16 unk_C;
    u8 pad_E[0xC];
    u16 unk_1A;
};
struct fn_1_58C6C_lbl_1_bss_6C84C_T {
    u8 unk_0;
    u8 pad_1[0x7];
    u32 unk_8;
    s16 unk_C;
    u8 pad_E[0xC];
    u16 unk_1A;
};

void fn_1_58C6C(void) {
    struct fn_1_58C6C_lbl_1_bss_6C848_T *var_r31;
    s32 var_r30;
    s32 var_r30_2;
    struct fn_1_58C6C_lbl_1_bss_6C84C_T *var_r31_2;

    var_r30 = 0xBE;
    var_r31 = (struct fn_1_58C6C_lbl_1_bss_6C848_T *)(*(struct fn_1_58C6C_lbl_1_bss_6C848_T **)((u8 *)(&(*(struct fn_1_58C6C_lbl_1_bss_6C848_T * *)&lbl_1_bss_6C848)) + 0));
    do {
        if (((s16) var_r31->unk_C == 0x19) && ((s8) var_r31->unk_0 != 0) && ((s32) var_r31->unk_1A != 0) && !(var_r31->unk_8 & 0x80000000)) {
            fn_1_620C8((void *)(var_r31));
        }
        var_r30 -= 1;
        var_r31 = (struct fn_1_58C6C_lbl_1_bss_6C848_T *)((u8 *)(var_r31) + 0xE8);
    } while (var_r30 > 0);
    var_r30_2 = 0xC8;
    var_r31_2 = (struct fn_1_58C6C_lbl_1_bss_6C84C_T *)(*(struct fn_1_58C6C_lbl_1_bss_6C84C_T **)((u8 *)(&(*(struct fn_1_58C6C_lbl_1_bss_6C84C_T * *)&lbl_1_bss_6C84C)) + 0));
    do {
        if (((s16) var_r31_2->unk_C == 0x19) && ((s8) var_r31_2->unk_0 != 0) && ((s32) var_r31_2->unk_1A != 0) && !(var_r31_2->unk_8 & 0x80000000)) {
            fn_1_620C8((void *)(var_r31_2));
        }
        var_r30_2 -= 1;
        var_r31_2 = (struct fn_1_58C6C_lbl_1_bss_6C84C_T *)((u8 *)(var_r31_2) + 0xE8);
    } while (var_r30_2 > 0);
}
/* fzgx:end fn_1_58C6C */

/* fzgx:begin fn_1_58D38 */
typedef struct fn_1_58D38_EffectState {
    fn_1_58D38_EffectEntry *unk_00;
    fn_1_58D38_EffectEntry *unk_04;
    u8 pad_08[8];
    u32 unk_10;
} fn_1_58D38_EffectState;


void fn_1_58D38(void) {
    fn_1_58D38_EffectState *state;
    s32 count;
    fn_1_58D38_EffectEntry *entry;
    u32 max_count;

    state = (fn_1_58D38_EffectState *)&lbl_1_bss_6C848;
    if (state->unk_00 != 0) {
        fn_1_3BDC(9);

        entry = state->unk_00;
        count = 190;
        do {
            if (entry->unk_0C == 25 &&
                (s32)entry->unk_00 != 0 &&
                entry->unk_1A != (s16)0 &&
                (entry->unk_08 & ~0x7fffffff) == 0) {
                fn_1_62360(entry);
            }
            count--;
            entry++;
        } while (count > 0);

        entry = state->unk_04;
        count = 200;
        do {
            if (entry->unk_0C == 25 &&
                (s32)entry->unk_00 != 0 &&
                entry->unk_1A != (s16)0 &&
                (entry->unk_08 & ~0x7fffffff) == 0) {
                fn_1_62360(entry);
            }
            count--;
            entry++;
        } while (count > 0);

        count = fn_1_3C18(9);
        max_count = state->unk_10;
        if (count > max_count) {
            max_count = count;
        }
        state->unk_10 = max_count;
    }
}
/* fzgx:end fn_1_58D38 */

/* fzgx:begin fn_1_58E3C */
typedef struct {
    s8 unk_0;
    u8 pad_1;
    s16 unk_2;
    s16 unk_4;
    u8 pad_6[6];
    s16 unk_C;
    u8 pad_E[0xDA];
} EffectEntry;

s16 fn_1_58E3C(void *source) {
    s32 i;

    if ((s32)fn_1_3FC58() != 0) {
        return -1;
    }

    {
        EffectEntry *scan;
        scan = *(EffectEntry **)&lbl_1_bss_6C848;
        i = 0;
        for (; i < 0xbe; i++, scan++) {
            if (!scan->unk_0) {
                scan->unk_0 = 1;
                /* The shared exit preserves the counted search result. */
                goto slot_found;
            }
        }
        i = -1;
    }
slot_found:
    if (i < 0) {
        return -1;
    }
    {
        EffectEntry *entry;
        entry = *(EffectEntry **)&lbl_1_bss_6C848 + i;
    memcpy(entry, source, 0xe8);
    entry->unk_0 = 1;
    entry->unk_2 = i;
    ((void (**)(void *))lbl_1_data_1D1D8)[entry->unk_C](entry);
    entry->unk_4 = lbl_1_bss_6C850.unk_0;
    lbl_1_bss_6C850.unk_0++;
    if (lbl_1_bss_6C850.unk_0 < 0) {
        lbl_1_bss_6C850.unk_0 = 0;
    }
        return entry->unk_4;
    }
}
/* fzgx:end fn_1_58E3C */

/* fzgx:begin fn_1_58F50 */
typedef struct {
    u8 unk_0;
    u8 pad_1[1];
    s16 unk_2;
    s16 unk_4;
    u8 pad_6[6];
    s16 unk_C;
    u8 pad_E[0xDA];
} fn_1_58F50_EffectEntry;

/* Allocate an effect entry, initialize it, and return its sequence number. */
s16 fn_1_58F50(const void *source) {
    fn_1_58F50_EffectEntry *entry;
    s32 index;
    u8 *cursor;

    if ((int)fn_1_3FC8C() != 0) {
        return -1;
    }
    if ((int)fn_1_3FC58() != 0) {
        return -1;
    }

    cursor = *(u8 **)&lbl_1_bss_6C848;
    index = 0;
    for (; index < 0xbe;) {
        if (*(s8 *)cursor == 0) {
            *cursor = 1;
            goto found; /* irreducible split between allocation and failure */
        }
        index++;
        cursor += 0xe8;
    }
    index = -1;
found:
    if (index < 0) {
        return -1;
    }

    entry = (fn_1_58F50_EffectEntry *)(*(u8 **)&lbl_1_bss_6C848) + index;
    memcpy(entry, source, 0xe8);
    entry->unk_0 = 1;
    entry->unk_2 = index;
    ((void (*)(void *))(*(u32 *)((*(u8 (*)[276])&lbl_1_data_1D1D8) + (entry->unk_C << 2))))(entry);

    entry->unk_4 = lbl_1_bss_6C850.unk_0;
    lbl_1_bss_6C850.unk_0++;
    if (lbl_1_bss_6C850.unk_0 < 0) {
        lbl_1_bss_6C850.unk_0 = 0;
    }
    return entry->unk_4;
}
/* fzgx:end fn_1_58F50 */

/* fzgx:begin fn_1_59078 */
s16 fn_1_59078(Obj_1_bss_6C84C_Target *arg0) {
    Obj_1_bss_6C84C_Target *obj;
    s32 i;

    if ((int)fn_1_3FC8C() != 0) {
        return -1;
    }
    if ((int)fn_1_3FC58() != 0) {
        return -1;
    }

    obj = lbl_1_bss_6C84C;
    for (i = 0; i < 0xbe; i++, obj++) {
        if ((s8)obj->unk_0 == 0) {
            obj->unk_0 = 1;
            // Skip the exhaustion path when a free slot is found.
            goto slot_found;
        }
    }
    i = -1;
slot_found:
    if (i < 0) {
        return -1;
    }

    obj = lbl_1_bss_6C84C + i;
    memcpy(obj, arg0, 0xe8);
    obj->unk_0 = 1;
    obj->unk_2 = i;
    ((void (**)(Obj_1_bss_6C84C_Target *))lbl_1_data_1D1D8)[obj->unk_C](obj);
    obj->unk_4 = lbl_1_bss_6C850.unk_0;
    lbl_1_bss_6C850.unk_0++;
    if (lbl_1_bss_6C850.unk_0 < 0) {
        lbl_1_bss_6C850.unk_0 = 0;
    }
    return obj->unk_4;
}
/* fzgx:end fn_1_59078 */

/* fzgx:begin fn_1_59290 */
void fn_1_59290(void) {
    u8 buffer1[0xe8];
    u8 buffer2[0xe8];
    int count;
    Obj_1_bss_6C84C_Target *effect;
    Obj_1_bss_6C84C_Target *effects;

    effects = *(Obj_1_bss_6C84C_Target **)(void *)&lbl_1_bss_6C848;
    effect = effects;
    count = 0xbe;
    for (; count > 0; count--, effect++) {
        if ((s8)effect->unk_0 != 0) {
            if (effect->unk_C == 1) {
                fn_80008BEC(buffer1, 0, 0xe8);
                *(s16 *)(buffer1 + 0x4) = effect->unk_4;
                buffer1[0] = effect->unk_0;
                *(s16 *)(buffer1 + 0xc) = effect->unk_C;
                *(u32 *)(buffer1 + 0x38) = effect->unk_38;
                *(u32 *)(buffer1 + 0x34) = effect->unk_34;
                *(u16 *)(buffer1 + 0x1a) = effect->unk_1A;
                *(s16 *)(buffer1 + 0x18) = effect->unk_18;
                fn_80008BEC(effect, 0, 0xe8);
                fn_80008BA8(effect, buffer1, 0xe8);
            } else if (effect->unk_C != 4) {
                effect->unk_0 = 3;
                effect->unk_8 |= (u32)1 << 31;
            }
        }
    }

    effects = lbl_1_bss_6C84C;
    effect = effects;
    count = 0xc8;
    for (; count > 0; count--, effect++) {
        if ((s8)effect->unk_0 != 0) {
            if (effect->unk_C == 1) {
                fn_80008BEC(buffer2, 0, 0xe8);
                *(s16 *)(buffer2 + 0x4) = effect->unk_4;
                buffer2[0] = effect->unk_0;
                *(s16 *)(buffer2 + 0xc) = effect->unk_C;
                *(u32 *)(buffer2 + 0x38) = effect->unk_38;
                *(u32 *)(buffer2 + 0x34) = effect->unk_34;
                *(u16 *)(buffer2 + 0x1a) = effect->unk_1A;
                *(s16 *)(buffer2 + 0x18) = effect->unk_18;
                fn_80008BEC(effect, 0, 0xe8);
                fn_80008BA8(effect, buffer2, 0xe8);
            } else if (effect->unk_C != 4) {
                effect->unk_0 = 3;
                effect->unk_8 |= (u32)1 << 31;
            }
        }
    }
}
/* fzgx:end fn_1_59290 */

/* fzgx:begin fn_1_5942C */
// fn_1_5942C: wrapper that calls fn_1_680F8
void fn_1_5942C(void) {
    fn_1_680F8();
}
/* fzgx:end fn_1_5942C */

/* fzgx:begin fn_1_5944C */
void fn_1_5944C(void) {
    fn_1_68284();
}
/* fzgx:end fn_1_5944C */

/* fzgx:begin fn_1_5946C */
void fn_1_5946C(void) {
    fn_1_68B68();
}
/* fzgx:end fn_1_5946C */

/* fzgx:begin fn_1_5948C */
void fn_1_5948C(void) {
    fn_1_68248();
}
/* fzgx:end fn_1_5948C */

/* fzgx:begin fn_1_594AC */
void fn_1_594AC(void) {
    fn_1_69BBC();
}
/* fzgx:end fn_1_594AC */

/* fzgx:begin fn_1_594CC */
void fn_1_594CC(void) {
    fn_1_69BCC();
}
/* fzgx:end fn_1_594CC */

/* fzgx:begin fn_1_594EC */
// fn_1_594EC: empty in retail (single blr).
void fn_1_594EC(void) {
}
/* fzgx:end fn_1_594EC */

/* fzgx:begin fn_1_594F0 */
// fn_1_594F0: empty in retail (single blr).
void fn_1_594F0(void) {
}
/* fzgx:end fn_1_594F0 */

/* fzgx:begin fn_1_594F4 */
// fn_1_594F4: empty in retail (single blr).
void fn_1_594F4(void) {
}
/* fzgx:end fn_1_594F4 */

/* fzgx:begin fn_1_594F8 */
// fn_1_594F8: empty in retail (single blr).
void fn_1_594F8(void) {
}
/* fzgx:end fn_1_594F8 */

/* fzgx:begin fn_1_594FC */
// fn_1_594FC: empty in retail (single blr).
void fn_1_594FC(void) {
}
/* fzgx:end fn_1_594FC */

/* fzgx:begin fn_1_59500 */
// fn_1_59500: empty in retail (single blr).
void fn_1_59500(void) {
}
/* fzgx:end fn_1_59500 */

/* fzgx:begin fn_1_59504 */
// fn_1_59504: empty in retail (single blr).
void fn_1_59504(void) {
}
/* fzgx:end fn_1_59504 */

/* fzgx:begin fn_1_59508 */
// fn_1_59508: empty in retail (single blr).
void fn_1_59508(void) {
}
/* fzgx:end fn_1_59508 */

/* fzgx:begin fn_1_5950C */
// fn_1_5950C: empty in retail (single blr).
void fn_1_5950C(void) {
}
/* fzgx:end fn_1_5950C */

/* fzgx:begin fn_1_59510 */
// fn_1_59510: empty in retail (single blr).
void fn_1_59510(void) {
}
/* fzgx:end fn_1_59510 */

/* fzgx:begin fn_1_59514 */
void fn_1_59514(void *obj) {
    if (*(s32 *)((u8 *)obj + 0x10) == 0) {
        u32 s = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        u32 r;
        lbl_1_data_1D628 = s;
        r = (s >> 16) & 0x7fff;
        *(s32 *)((u8 *)obj + 0x10) = (s32)(60.0f * (0.1f + (f32)r / 32767.0f));
    }

    {
        f32 t = fn_1_8652C(*(s16 *)((u8 *)obj + 0x18));
        u32 s = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        u32 r;
        lbl_1_data_1D628 = s;
        r = (s >> 16) & 0x7fff;
        *(f32 *)((u8 *)obj + 0x94) = 0.05f * ((f32)r / 32767.0f);
        *(f32 *)((u8 *)obj + 0x98) = (f32)(0.07 + t / 20000.0f);
    }
}
/* fzgx:end fn_1_59514 */

/* fzgx:begin fn_1_5962C noprologue */
#include "dolphin/types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3i;

typedef struct {
    s32 field_00[4];
    s32 timer;
    s32 field_14;
    s32 field_18;
    f32 field_1c;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2c;
    s32 field_30;
    s32 field_34;
    s32 field_38;
    union {
        Vec3f pos;
        Vec3i bits;
    } field_3c;
    f32 field_48;
    f32 field_4c;
    f32 field_50;
    s32 field_54;
    s32 field_58;
    s32 field_5c;
    Vec3i prev;
    s32 field_6c[10];
    f32 field_94;
    f32 field_98;
} Fn_1_5962C_State;

static inline f32 fn_1_5962C_operand(f32 right, f32 left) { return left * right; }
#pragma opt_dead_assignments off
#pragma opt_strength_reduction off
void fn_1_5962C(Fn_1_5962C_State *self) {
    f32 fzgx_live;
    f32 scale;
    f32 rate;

    self->prev = self->field_3c.bits;

    scale = 1.0f - self->field_94;

    self->field_4c += -0.03f;
    self->field_48 = self->field_48 * scale;
    self->field_4c = self->field_4c * scale;
    self->field_50 = self->field_50 * scale;

    self->field_3c.pos.x = self->field_3c.pos.x + self->field_48;
    fzgx_live = self->field_3c.pos.y;
    self->field_3c.pos.y = fzgx_live + self->field_4c;
    self->field_3c.pos.z = self->field_3c.pos.z + self->field_50;

    self->field_94 = self->field_94 + (f32)(0.05f * (self->field_98 - self->field_94));
    self->field_28 = self->field_28 + (f32)(0.1f * (self->field_2c - self->field_28));

    if ((f64)(s32)self->timer < 15.0) {
        rate = 1.0f - 1.0f / (f32)(self->timer + 1);
        self->field_1c = fn_1_5962C_operand((rate), (self->field_1c));
        self->field_20 = self->field_20 * rate;
        self->field_24 = self->field_24 * rate;
    }
}
#pragma opt_strength_reduction reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_5962C */

/* fzgx:begin fn_1_59A70 */
// fn_1_59A70: empty in retail (single blr).
void fn_1_59A70(void) {
}
/* fzgx:end fn_1_59A70 */

/* fzgx:begin fn_1_59A74 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
}
#pragma section code_type ".text"


struct fn_1_59A74_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x6];
    u16 unk_1A;
};

void fn_1_59A74(struct fn_1_59A74_Arg0 *arg0) {
    u32 v0;
    f32 v1;
    f32 v2;
    f32 v3;
    f32 v4;

    arg0->unk_1A = (0x10000 - 1);
    v0 = ((lbl_1_data_1D628 * (0x41C60000 + 20077)) + 12345);
    lbl_1_data_1D628 = v0;
    v1 = (f32)(u32)((v0 >> 16) & 0x7FFF);
    v2 = v1 / 32767.0f;
    v3 = 0.5f * v2;
    v4 = 0.1f + v3;
    arg0->unk_10 = (s32)(60.0f * v4);
}
/* fzgx:end fn_1_59A74 */

/* fzgx:begin fn_1_59B00 */
typedef struct fn_1_59B00_Effect {
    u8 pad_00[0x10];
    s32 frame;
    u8 pad_14[0x14];
    f32 value;
    f32 target;
} fn_1_59B00_Effect;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
}
#pragma section code_type ".text"
void fn_1_59B00(fn_1_59B00_Effect *effect) {
    if ((f32)effect->frame < 15.0f) {
        effect->value = effect->value * (1.0f - 1.0f / (f32)(effect->frame + 1));
    } else {
        f32 delta = (effect->target - effect->value) * 0.2f;

        effect->value += delta;
    }
}
/* fzgx:end fn_1_59B00 */

/* fzgx:begin fn_1_59B90 noprologue */
#include "dolphin/types.h"
#include "psvec.h"
#include "rel/main_rel/effect.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    f32 m[12];
} Mtx;

typedef struct {
    u8 pad_0[0x8];
    Vec3 v8;
    f32 f14;
} NodeObj;

typedef struct {
    u8 pad_0[0x90];
    NodeObj *unk_90;
} MgrObj;

typedef struct {
    u8 pad_0[0x28];
    f32 f28;
    u8 pad_2C[0x10];
    u32 unk_3C;
    u8 pad_40[0x14];
    s16 unk_54;
    s16 unk_56;
} SelfObj;

extern const f32 lbl_1_rodata_2954[2];
extern u32 lbl_801A6D00[2];
extern void lbl_8006D9D8(void *, u32);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006E14C(f32);
extern s32 fn_1_54E34(Vec3 *, f32);
extern void lbl_8006DB74(void *);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void fn_1_56000(u8, u8, u8);
extern void u_gxutil_upload_some_mtx(u32, u32);
extern void fn_1_556B8(void *);

#pragma opt_common_subs off
void fn_1_59B90(SelfObj *arg0) {
    MgrObj *mgr;
    NodeObj *r;
    Mtx pos;
    Vec3 dir;
    f32 len;
    f32 t;

    mgr = (MgrObj *)(void *)lbl_1_bss_38458->unk_8;
    r = mgr->unk_90;
    lbl_8006D9D8(&arg0->unk_3C, (u32)mgr);
    mathutil_mtxA_rotate_y(arg0->unk_56);
    mathutil_mtxA_rotate_x(arg0->unk_54);
    lbl_8006E14C(arg0->f28 / r->f14);
    if (fn_1_54E34(&r->v8, arg0->f28) != 0) {
        psvec_set(&dir, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
        lbl_8006DB74(&pos);
        len = dir.x * dir.x;
        len += dir.y * dir.y;
        len += dir.z * dir.z;
        len = lbl_8006D0B4(len);
        t = (len - lbl_1_rodata_2954[0]) / len;
        lbl_8006D848(t);
        lbl_8006DFC4(&pos);
        fn_1_56000(1, 3, 0);
        u_gxutil_upload_some_mtx(*lbl_801A6D00, 0);
        fn_1_556B8(r);
        fn_1_56000(1, 3, 1);
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_59B90 */

/* fzgx:begin fn_1_59CC4 */
// fn_1_59CC4: empty in retail (single blr).
void fn_1_59CC4(void) {
}
/* fzgx:end fn_1_59CC4 */

/* fzgx:begin fn_1_59CC8 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
}
#pragma section code_type ".text"

extern const f32 lbl_1_rodata_2950;  /* +0x0 = 60.0f */
extern const f64 lbl_1_rodata_2950_20; /* placeholder, replaced below */

struct Fn159CC8Object {
    u8 pad[0x10];
    s32 unk_10;
};

#pragma opt_lifetimes off
void fn_1_59CC8(struct Fn159CC8Object *arg0) {
    if (arg0->unk_10 == 0) {
        u32 seed = (0x41C64E6D * lbl_1_data_1D628) + 0x3039;

        f32 value;
        f32 scaled;

        lbl_1_data_1D628 = seed;
        value = (f32)((seed >> 16) & 0x7FFF);
        scaled = 0.25f * (value / 32767.0f);
        arg0->unk_10 = (s32)(60.0f * (0.08f + scaled));
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_59CC8 */

/* fzgx:begin fn_1_59D54 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
}
#pragma section code_type ".text"


typedef struct fn_1_59D54_Effect {
    u8 state;
    u8 pad0[0xf];
    s32 frame;
    u8 pad1[0x4];
    s16 effect_id;
    u8 pad2[0x22];
    f32 position_x;
    f32 position_y;
    f32 position_z;
    f32 velocity_x;
    f32 velocity_y;
    f32 velocity_z;
    u8 pad3[0x40];
    f32 accumulator_x;
    f32 accumulator_y;
    f32 accumulator_z;
    f32 scale_x;
    f32 scale_y;
    f32 scale_z;
    u8 pad4[0x8];
    f32 intensity;
} fn_1_59D54_Effect;

void fn_1_59D54(fn_1_59D54_Effect *effect) {
    f32 coords[3];
    f32 dz, dy, dx, dist;

    effect->velocity_x *= 0.98f;
    effect->velocity_y *= 0.98f;
    effect->velocity_z *= 0.98f;
    effect->position_x += effect->velocity_x;
    effect->position_y += effect->velocity_y;
    effect->position_z += effect->velocity_z;

    effect->scale_x *= 0.99f;
    effect->scale_y *= 0.99f;
    effect->scale_z *= 0.99f;
    effect->accumulator_x += effect->scale_x;
    effect->accumulator_y += effect->scale_y;
    effect->accumulator_z += effect->scale_z;

    effect->intensity = 0.5f * (f32)effect->frame;

    fn_1_862D4(effect->effect_id, coords);

    dx = coords[0] - effect->position_x;
    dist = dx * dx;
    dy = coords[1];
    dy = dy - effect->position_y;
    dist += dy * dy;
    dz = coords[2];
    dz = dz - effect->position_z;
    dist += dz * dz;
    dist = lbl_8006D0B4(dist);

    if (dist > 40.0f) {
        effect->state = 3;
    } else if (dist > 20.0f) {
        effect->intensity *= 0.05f * (dist - 20.0f);
    }
}
/* fzgx:end fn_1_59D54 */

/* fzgx:begin fn_1_5A8CC */
// fn_1_5A8CC: empty in retail (single blr).
void fn_1_5A8CC(void) {
}
/* fzgx:end fn_1_5A8CC */

/* fzgx:begin fn_1_5A8D0 */
typedef struct {
    u8 pad[0x10];
    s32 field_10;
} Fn1_5A8D0Data;

void fn_1_5A8D0(Fn1_5A8D0Data *data) {
    data->field_10 = 2;
}
/* fzgx:end fn_1_5A8D0 */

/* fzgx:begin fn_1_5A8DC */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
}
#pragma section code_type ".text"

typedef struct { f32 x,y,z; } Vec3_5A8DC;
typedef struct {
 u8 pad_0[0x18]; s16 unk_18; u8 pad_1A[2];
 Vec3_5A8DC unk_1C; u8 pad_28[0x14];
 Vec3_5A8DC unk_3C; u8 pad_48[0x4C];
 Vec3_5A8DC unk_94;
} Arg_5A8DC;
typedef struct {
 s8 unk_0; u8 pad_1; s16 unk_2,unk_4; u8 pad_6[6];
 s16 unk_C; u8 pad_E[0xA]; s16 unk_18; u16 unk_1A;
 Vec3_5A8DC unk_1C; f32 unk_28,unk_2C; u8 pad_30[4];
 u32 unk_34; u8 pad_38[4];
 Vec3_5A8DC unk_3C,unk_48; s16 unk_54,unk_56;
 u8 pad_58[0x3C]; Vec3_5A8DC unk_94; u8 pad_A0[0x48];
} Effect_5A8DC;
extern void *lbl_801A6D00;
extern void fn_1_8645C(int, void *);
extern void lbl_8006E1B0(void *, void *);
extern void *lbl_8006E1F0(void *, f32, f32, f32);
extern void fn_8006EF10(void *, s16 *, s16 *);
extern u32 fn_1_3FC58(void);
extern void *memset(void *, int, u32);
extern void *memcpy(void *, const void *, u32);

static inline s32 allocate_5A8DC(void) {
 Effect_5A8DC *p = *(Effect_5A8DC **)&lbl_1_bss_6C848;
 s32 i;
 for (i=0; i<190; i++,p++) {
  if(p->unk_0 == 0) { p->unk_0=1; return i; }
 }
 return -1;
}
void fn_1_5A8DC(Arg_5A8DC *arg0) {
 Vec3_5A8DC loc_20;
 Vec3_5A8DC old;
 Vec3_5A8DC loc_8;
 Effect_5A8DC loc_2C;
 f32 dx,dy,dz;
 s32 i;
 Effect_5A8DC *p;
 old = arg0->unk_3C;
 fn_1_8645C(arg0->unk_18, lbl_801A6D00);
 lbl_8006E1B0(&arg0->unk_94, &loc_20);
 lbl_8006E1F0(&loc_8, 0.0f, 0.0f, 1.0f);
 dx = loc_20.x-old.x;
 dy = loc_20.y-old.y;
 dz = loc_20.z-old.z;
 arg0->unk_3C = loc_20;
 memset(&loc_2C,0,sizeof(loc_2C));
 loc_2C.unk_18 = arg0->unk_18;
 loc_2C.unk_C = 9;
 loc_2C.unk_1A = 65535;
 loc_2C.unk_34 = *(u32 *)(lbl_1_bss_38458->unk_8+0x120);
 loc_2C.unk_3C = loc_20;
 loc_2C.unk_94 = arg0->unk_94;
 loc_2C.unk_48.x = dx;
 loc_2C.unk_48.y = dy;
 loc_2C.unk_48.z = dz;
 loc_2C.unk_3C.x -= dx;
 loc_2C.unk_3C.y -= dy;
 loc_2C.unk_3C.z -= dz;
 fn_8006EF10(&loc_8,&loc_2C.unk_54,&loc_2C.unk_56);
 loc_2C.unk_28 = 0.3f;
 lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
 loc_2C.unk_2C = 0.3f + (f32)(0.2f * ((f32)((lbl_1_data_1D628 >> 16)&0x7FFF) / 32767.0f));
 loc_2C.unk_1C = arg0->unk_1C;
 if ((s32)fn_1_3FC58() == 0) {
  i = allocate_5A8DC();
  if(i>=0) {
   arg0 = (Arg_5A8DC *)&(*(Effect_5A8DC **)&lbl_1_bss_6C848)[i];
   memcpy(arg0,&loc_2C,sizeof(loc_2C));
   ((Effect_5A8DC *)arg0)->unk_0=1;
   ((Effect_5A8DC *)arg0)->unk_2=i;
   ((void (**)(Effect_5A8DC *))lbl_1_data_1D1D8)[((Effect_5A8DC *)arg0)->unk_C]((Effect_5A8DC *)arg0);
   ((Effect_5A8DC *)arg0)->unk_4=lbl_1_bss_6C850.unk_0;
   lbl_1_bss_6C850.unk_0++;
   if(lbl_1_bss_6C850.unk_0<0) lbl_1_bss_6C850.unk_0=0;
  }
 }
}
/* fzgx:end fn_1_5A8DC */

/* fzgx:begin fn_1_5ABC4 */
// fn_1_5ABC4: empty in retail (single blr).
void fn_1_5ABC4(void) {
}
/* fzgx:end fn_1_5ABC4 */

/* fzgx:begin fn_1_5ABC8 */
// fn_1_5ABC8: empty in retail (single blr).
void fn_1_5ABC8(void) {
}
/* fzgx:end fn_1_5ABC8 */

/* fzgx:begin fn_1_5ABCC noprologue */
#include "types.h"
#include "rel/main_rel/effect.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
}
#pragma section code_type ".text"

extern const struct fn_1_5ABCC_lbl_1_rodata_2950_pool {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    u8 pad_C[0x60];
    f32 unk_6C;
} lbl_1_rodata_2950;

typedef struct {
    u8 pad_00[0x10];
    s32 unk_10;
} Fn1_5ABCCOutput;

extern u32 lbl_1_data_1D628;

#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_pointer_analysis off
void fn_1_5ABCC(Fn1_5ABCCOutput *out) {
    f32 t;
    f32 scaled;

{
    u32 value;
    value = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    lbl_1_data_1D628 = value;
    t = (f32)((value >> 16) & 0x7fff);
}
    scaled = (0.25f) * (t / (32767.0f));
    out->unk_10 = (s32)((60.0f) * ((0.25f) + scaled));
}
#pragma opt_pointer_analysis reset

#pragma opt_common_subs reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_1_5ABCC */

/* fzgx:begin fn_1_5AF28 noprologue */
#include "dolphin/types.h"
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    f32 m[12];
} Mtx;

typedef struct {
    u8 pad_0[0x8];
    Vec3 v8;
    f32 f14;
} NodeObj;

typedef struct {
    u8 pad_0[0x1C];
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad_2C[0x8];
    NodeObj *unk_34;
    u8 pad_38[0x4];
    u32 unk_3C;
} SelfObj;

extern const f32 lbl_1_rodata_2954[2];
extern const f32 lbl_1_rodata_2978[4];
extern void lbl_8006D9D8(void *);
extern void lbl_8006D7B0(void);
extern void lbl_8006E14C(f32);
extern s32 fn_1_54E34(Vec3 *, f32);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_1_56000(u8, u8, u8);
extern void fn_1_557C4(void *);

#pragma opt_common_subs on
static inline f32 fn_1_5AF28_read_pointer(SelfObj * owner) { return owner->f28; }
void fn_1_5AF28(SelfObj *arg0) {
    f32 fzgx_live_;
    f32 fzgx_live;
    NodeObj *r;
    Mtx pos;
    Vec3 dir;
    f32 len;

    r = arg0->unk_34;
    lbl_8006D9D8(&arg0->unk_3C);
    lbl_8006D7B0();
    lbl_8006E14C(arg0->f28 / r->f14);
    if (fn_1_54E34(&r->v8, arg0->f28) != 0) {
        psvec_set(&dir, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
        len = dir.x * dir.x;
        fzgx_live = dir.y;
        len += fzgx_live * fzgx_live;
        fzgx_live_ = dir.z;
        len += fzgx_live_ * fzgx_live_;
        len = lbl_8006D0B4(len);
        if (len > fn_1_5AF28_read_pointer(arg0) + lbl_1_rodata_2954[0]) {
            lbl_8006DB74(&pos);
            lbl_8006D848((len - arg0->f28) / len);
            lbl_8006DFC4(&pos);
        }
        fn_1_5621C(arg0->f1C, arg0->f20, arg0->f24, lbl_1_rodata_2978[0]);
        fn_1_56000(1, 3, 0);
        fn_1_557C4(r);
        fn_1_5621C(lbl_1_rodata_2978[0], lbl_1_rodata_2978[0], lbl_1_rodata_2978[0], lbl_1_rodata_2978[0]);
        fn_1_56000(1, 3, 1);
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_5AF28 */

/* fzgx:begin fn_1_5B074 */
// fn_1_5B074: empty in retail (single blr).
void fn_1_5B074(void) {
}
/* fzgx:end fn_1_5B074 */

/* fzgx:begin fn_1_5B078 noprologue */
#include "dolphin/types.h"
#include "rel/main_rel/effect.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
}
#pragma section code_type ".text"

struct fx_5b078_out {
    u8 pad_00[0x10];
    s32 field_10;
    u8 pad_14[0x44];
    s16 field_58;
    u8 pad_5a[0x4];
    s16 field_5e;
    u8 pad_60[0x54];
    f32 field_b4;
};

void fn_1_5B078(struct fx_5b078_out *out)
{
    u32 rnd;
    u32 n;
    u32 n_2;

    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6Du + 0x3039u;
    rnd = lbl_1_data_1D628;
    n = (rnd >> 16) & 0x7FFFu;
    out->field_10 = (s32)(((f32)(n / 32767.0f * 0.1f) + 0.125f) * 60.0f);

    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6Du + 0x3039u;
    rnd = lbl_1_data_1D628;
    n = (rnd >> 16) & 0x7FFFu;
    out->field_58 = (s16)((n / 32767.0f - 0.5f) * 65536.0f);

    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6Du + 0x3039u;
    rnd = lbl_1_data_1D628;
    n_2 = (rnd >> 16) & 0x7FFFu;
    out->field_5e = (s16)((n_2 / 32767.0f - 0.5f) * 4096.0f);

    out->field_b4 = 0.5f;
}
/* fzgx:end fn_1_5B078 */

/* fzgx:begin fn_1_5B188 noprologue */
#include "dolphin/types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
}
#pragma section code_type ".text"

#pragma section code_type ".text"

struct fx_5b188 {
    u8 pad_00[0x10];
    s32 field_10;
    u8 pad_14[0x8];
    f32 field_1C;
    f32 field_20;
    f32 field_24;
    u8 pad_28[0x4];
    f32 field_2C;
    u8 pad_30[0xC];
    f32 field_3C;
    f32 field_40;
    f32 field_44;
    f32 field_48;
    f32 field_4C;
    f32 field_50;
    u8 pad_54[0x4];
    s16 field_58;
    u8 pad_5A[0x4];
    s16 field_5E;
    u8 pad_60[0x54];
    f32 field_B4;
};

static inline f32 fn_1_5B188_operand(f32 right, f32 left) { return left * right; }
#pragma opt_common_subs off
void fn_1_5B188(struct fx_5b188 *p)
{
    f32 d;

    d = 1.0f / (f32)(s32)(p->field_10 + 1);
    p->field_48 = fn_1_5B188_operand((0.96f), (p->field_48));
    p->field_4C = fn_1_5B188_operand((0.96f), (p->field_4C));
    p->field_50 = fn_1_5B188_operand((0.96f), (p->field_50));
    p->field_3C = p->field_3C + p->field_48;
    p->field_40 = p->field_40 + p->field_4C;
    p->field_44 = p->field_44 + p->field_50;
    p->field_5E = (s16)(fn_1_5B188_operand(((f32)p->field_5E), (0.99f)));
    p->field_58 = p->field_58 + p->field_5E;
    p->field_1C = p->field_1C + (f32)(fn_1_5B188_operand(((0.4f - p->field_1C)), (0.05f)));
    p->field_20 = p->field_20 + (f32)(fn_1_5B188_operand(((0.4f - p->field_20)), (0.0505f)));
    p->field_24 = p->field_24 + (f32)(fn_1_5B188_operand(((0.4f - p->field_24)), (0.051f)));
    if ((f32)(s32)p->field_10 < 15.0f) {
        p->field_B4 = fn_1_5B188_operand(((1.0f - d)), (p->field_B4));
        p->field_2C = fn_1_5B188_operand((0.95f), (p->field_2C));
    } else {
        p->field_B4 = p->field_B4 + (f32)(fn_1_5B188_operand(((1.0f - p->field_B4)), (0.2f)));
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_5B188 */

/* fzgx:begin fn_1_5B30C */
struct fn_1_5B30C_Arg0 {
    u8 pad_0[0x34];
    u32 unk_34;
};


void fn_1_5B30C(struct fn_1_5B30C_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    f32 v2;
    u32 t3;
    v0 = arg0->unk_34;
    lbl_8006D9D8((void *)((u32)arg0 + 60));
    lbl_8006D7B0();
    lbl_8006E14C((*(f32 *)((u8 *)(u32)arg0 + 40) / *(f32 *)((u8 *)v0 + 20)));
    t3 = fn_1_54E34((void *)(v0 + 8), *(f32 *)((u8 *)(u32)arg0 + 40));
    v1 = t3;
    if ((s32)t3 != 0) {
    v1 = *(s16 *)((u8 *)(u32)arg0 + 88);
    mathutil_mtxA_rotate_z(v1);
    v2 = *(f32 *)((u8 *)(u32)arg0 + 28);
    fn_1_5621C(v2, *(f32 *)((u8 *)(u32)arg0 + 32), *(f32 *)((u8 *)(u32)arg0 + 36), *(f32 *)((u8 *)(u32)arg0 + 180));
    v1 = 1;
    fn_1_56000(v1, 3, 0);
    v1 = v0;
    fn_1_557C4((void *)v1);
    v2 = (*(f32 *)&lbl_1_rodata_2978);
    fn_1_5621C(v2, v2, v2, v2);
    v1 = 1;
    fn_1_56000(v1, 3, 1);
    }
}
/* fzgx:end fn_1_5B30C */

/* fzgx:begin fn_1_5B3CC */
// fn_1_5B3CC: empty in retail (single blr).
void fn_1_5B3CC(void) {
}
/* fzgx:end fn_1_5B3CC */

/* fzgx:begin fn_1_5B3D0 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
}
#pragma section code_type ".text"

extern const struct fn_1_5B3D0_lbl_1_rodata_2950_pool {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    u8 pad_C[0x88];
    f32 unk_94;
} lbl_1_rodata_2950;

struct fn_1_5B3D0_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
};

struct fn_1_5B3D0_State {
    u32 unk_0;
};

extern struct fn_1_5B3D0_State lbl_1_data_1D628;

#pragma opt_common_subs off
#pragma opt_lifetimes on
#pragma opt_strength_reduction off
void fn_1_5B3D0(struct fn_1_5B3D0_Arg0 *arg0) {
    u32 next;
    struct fn_1_5B3D0_State *state;
    struct { u32 value; } random;
    struct { f32 value; } r;

    state = &lbl_1_data_1D628;
    next = ((1103515245) * (state->unk_0)) + 12345;
    { u32 __reg_value_random = (next >> 16) & 0x7FFF; random.value = __reg_value_random; }
    { f32 __reg_value_r = (f32)random.value; r.value = __reg_value_r; }
    { f32 __reg_value_r = r.value / (32767.0f); r.value = __reg_value_r; }
    { f32 __reg_value_r = (0.100000001f) * r.value; r.value = __reg_value_r; }
    state->unk_0 = next;
    arg0->unk_10 = (s32)((60.0f) * ((0.125f) + r.value));
}
#pragma opt_strength_reduction reset

#pragma opt_lifetimes reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_5B3D0 */

/* fzgx:begin fn_1_5B450 noprologue */
#include "types.h"
#include "rel/main_rel/effect.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
}
#pragma section code_type ".text"
#pragma opt_propagation off

extern u32 lbl_801A6D00;
extern s32 fn_1_8645C(s16, u32);
extern void lbl_8006E1B0(void *, void *);
extern u32 lbl_1_data_1D628;

typedef struct Fn1_5B450Object {
    u8 pad_00[0x10];
    s32 unk_10;
    u8 pad_14[0x04];
    s16 unk_18;
    u8 pad_1a[0x02];
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2c;
    u8 pad_30[0x28];
    s16 unk_58;
} Fn1_5B450Object;

void fn_1_5B450(Fn1_5B450Object *arg0) {
    f32 scale;
    u32 random_value;
    u32 *statep;
    u32 rnd;
    s32 frame;
    f32 t;

    fn_1_8645C(arg0->unk_18, lbl_801A6D00);
    lbl_8006E1B0((u8 *)arg0 + 0x94, (u8 *)arg0 + 0x3c);

    scale = 0.95f;
    statep = &lbl_1_data_1D628;
    *statep = *statep * 0x41c64e6d + 0x3039;
    rnd = (*statep >> 16) & 0x7fff;
    arg0->unk_58 += rnd;

    arg0->unk_2c *= scale;
    arg0->unk_28 += arg0->unk_2c;

    frame = arg0->unk_10;
    if ((f32)frame < 60.0f) {
        t = 1.0f - 1.0f / (f32)(frame + 1);
        arg0->unk_1c *= t;
        arg0->unk_20 *= 0.99f * t;
        arg0->unk_24 *= scale * t;
    }
}
/* fzgx:end fn_1_5B450 */

/* fzgx:begin fn_1_5B578 noprologue */
#include "rel/main_rel/effect.h"

extern const struct fn_1_5B578_lbl_1_rodata_2950_pool {
    u8 pad_0[0x4];
    f32 unk_4;
    u8 pad_8[0x20];
    f32 unk_28;
    u8 pad_2C[0x38];
    f32 unk_64;
    u8 pad_68[0x38];
    f32 unk_A0;
    u8 pad_A4[0x3C];
    f32 unk_E0;
} lbl_1_rodata_2950;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec_1_5B578_T;

typedef struct {
    u8 pad_0[8];
    u32 unk_8;
} Obj_1_5B578_Scene_T;

typedef struct {
    u8 pad_0[0x70];
    u32 unk_70;
} Obj_1_5B578_World_T;

typedef struct {
    u8 pad_0[0x14];
    f32 unk_14;
} Obj_1_5B578_Entity_T;

typedef struct {
    u8 pad_8[8];
    Vec_1_5B578_T vec;
} Obj_1_5B578_Child_T;

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[0x18];
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 pad_2c[8];
    Obj_1_5B578_Child_T *unk_34;
    u8 pad_38[4];
    u32 unk_3c;
} Obj_1_5B578_T;

extern u32 lbl_801A66A0;

extern s32 fn_1_54E34(Vec_1_5B578_T *, f32);
extern void fn_1_56000(u8, u8, u8);
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_1_557C4(void *);
extern void *lbl_8006D9D8(void *);
extern void lbl_8006D7B0(void);
extern void lbl_8006E14C(f32);
extern f32 lbl_8006D0B4(f32);
extern void *lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void *lbl_8006DFC4(void *);

void fn_1_5B578(Obj_1_5B578_T *p)
{
    struct fn_1_5B578_lbl_1_rodata_2950_pool *pool_lbl_1_rodata_2950 = (struct fn_1_5B578_lbl_1_rodata_2950_pool *)&lbl_1_rodata_2950;
    Obj_1_5B578_Child_T *child;
    f32 d;
    f32 t;
    f32 acc;
    f32 vx;
    f32 vy;
    f32 vz;
    /* volatile: the update calls leave this vector in its frame slot */
    volatile Vec_1_5B578_T v;
    Obj_1_5B578_Entity_T *entity;
    u32 debug[12];

    child = p->unk_34;
    t = ((lbl_801A66A0 + p->unk_2) & 1) ? pool_lbl_1_rodata_2950->unk_28 : pool_lbl_1_rodata_2950->unk_E0;
    lbl_8006D9D8(&p->unk_3c);
    if (fn_1_54E34(&child->vec, p->unk_28) == 0) {
        return;
    }
    entity = (Obj_1_5B578_Entity_T *)(u32)((Obj_1_5B578_World_T *)(u32)((Obj_1_5B578_Scene_T *)lbl_1_bss_38458->pad_0)->unk_8)->unk_70;
    lbl_8006D7B0();
    d = p->unk_28 / entity->unk_14;
    lbl_8006E14C(d * t);
    vx = v.x;
    vy = v.y;
    vz = v.z;
    acc = vx * vx;
    acc += vy * vy;
    acc += vz * vz;
    t = lbl_8006D0B4(acc);
    if (t > pool_lbl_1_rodata_2950->unk_4 + (f32)(pool_lbl_1_rodata_2950->unk_A0 * p->unk_28)) {
        lbl_8006DB74(debug);
        lbl_8006D848((t - (f32)(pool_lbl_1_rodata_2950->unk_A0 * p->unk_28)) / t);
        lbl_8006DFC4(debug);
    }
    fn_1_56000(1, 3, 0);
    fn_1_5621C(p->unk_1c, p->unk_20, p->unk_24, pool_lbl_1_rodata_2950->unk_64);
    fn_1_557C4(entity);
    t = pool_lbl_1_rodata_2950->unk_28;
    fn_1_5621C(t, t, t, t);
    fn_1_56000(1, 3, 1);
}
/* fzgx:end fn_1_5B578 */

/* fzgx:begin fn_1_5B6F0 */
// fn_1_5B6F0: empty in retail (single blr).
void fn_1_5B6F0(void) {
}
/* fzgx:end fn_1_5B6F0 */

/* fzgx:begin fn_1_5B6F4 */
typedef struct Fn15B6F4 {
    u8 _pad00[0x10];
    s32 unk_10;
    s32 unk_14;
} Fn15B6F4;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
#pragma section code_type ".text"
void fn_1_5B6F4(Fn15B6F4 *obj) {
    u32 seed = lbl_1_data_1D628 * 1103515245 + 12345;
    f32 r = (f32)((seed >> 16) & 0x7FFF) / 32767.0f;
    f64 d = 10.0 * ((f64)r - 3.0);

    lbl_1_data_1D628 = seed;
    obj->unk_10 = (s32)(150.0 + d);
    obj->unk_14 = obj->unk_10 - 20;
}
/* fzgx:end fn_1_5B6F4 */

/* fzgx:begin fn_1_5B780 */
typedef struct Fn15B780 {
    u8 state;
    u8 _pad01[0x0f];
    int current;
    int maximum;
    u8 _pad18[0x94];
    s16 step;
    u8 _padAE[0x04];
    f32 result;
} Fn15B780;

void fn_1_5B780(Fn15B780 *effect) {
    effect->state = 2;
    if (effect->current <= effect->maximum) {
        effect->step += 2;
        if (effect->step >= 14) {
            effect->step = 14;
        }
    }
    effect->result = lbl_1_rodata_29A4 * (f32)effect->current;
}
/* fzgx:end fn_1_5B780 */

/* fzgx:begin fn_1_5BF6C */
// fn_1_5BF6C: empty in retail (single blr).
void fn_1_5BF6C(void) {
}
/* fzgx:end fn_1_5BF6C */

/* fzgx:begin fn_1_5BF70 */
struct fn_1_5BF70_Arg0 {
    u8 pad_0[0x10];
    s32 unk_10;
};
struct fn_1_5BF70_lbl_1_data_1D628 {
    u32 unk_0;
};


#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[2] = {0x00000000, 0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.4000000953674316f;
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
#pragma section code_type ".text"
void fn_1_5BF70(struct fn_1_5BF70_Arg0 *arg0) {
    u32 seed;
    f32 normalized;
    f64 value;

    seed = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    lbl_1_data_1D628 = seed;
    normalized = (f32)((seed >> 16) & 0x7fff) / 32767.0f;
    value = 10.0 * ((f64)normalized - 3.0);
    arg0->unk_10 = (s32)(value + 50.0);
}
/* fzgx:end fn_1_5BF70 */

/* fzgx:begin fn_1_5BFF0 */
struct fn_1_5BFF0_Arg0 {
    u8 unk_0;
    u8 pad_1[0xF];
    u32 unk_10;
    u8 pad_14[0x98];
    s16 unk_AC;
    u8 pad_AE[0x6];
    f32 unk_B4;
};

void fn_1_5BFF0(struct fn_1_5BFF0_Arg0 *arg0) {
    arg0->unk_0 = 2;
    arg0->unk_AC += 2;
    if (arg0->unk_AC >= 15) {
    arg0->unk_AC = 15;
    }
    arg0->unk_B4 = (lbl_1_rodata_29A4 * (f32)(s32)arg0->unk_10);
}
/* fzgx:end fn_1_5BFF0 */

/* fzgx:begin fn_1_5C780 */
// fn_1_5C780: empty in retail (single blr).
void fn_1_5C780(void) {
}
/* fzgx:end fn_1_5C780 */

/* fzgx:begin fn_1_5C784 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

extern const struct fn_1_5C784_lbl_1_rodata_2950_pool {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
} lbl_1_rodata_2950;

extern u32 lbl_1_data_1D628;
extern void fn_1_8636C(s16, void *);

typedef struct Vec3 {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

typedef struct EffectWork {
    u8 pad_00[0x10];
    s32 unk_10;
    u8 pad_14[0x4];
    s16 unk_18;
    u8 pad_1a[0x22];
    Vec3 unk_3c;
    u8 pad_48[0x4c];
    Vec3 unk_94;
    u8 pad_a0[0x18];
    u8 unk_b8;
} EffectWork;

#pragma opt_loop_invariants off
void fn_1_5C784(EffectWork *self) {
    struct fn_1_5C784_lbl_1_rodata_2950_pool *pool_lbl_1_rodata_2950 = (struct fn_1_5C784_lbl_1_rodata_2950_pool *)&lbl_1_rodata_2950;
    if (self->unk_10 == 0) {
        u32 value = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        lbl_1_data_1D628 = value;
        value = (value >> 16) & 0x7FFF;
        self->unk_10 = (s32)((60.0f) * ((0.100000001f) + (f32)value / (32767.0f)));
    }
    self->unk_3c = self->unk_94;
    fn_1_8636C(self->unk_18, &self->unk_b8);
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_5C784 */

/* fzgx:begin fn_1_5D010 */
// fn_1_5D010: empty in retail (single blr).
void fn_1_5D010(void) {
}
/* fzgx:end fn_1_5D010 */

/* fzgx:begin fn_1_5D014 */
typedef struct Fn1_5D014Object {
    u8 pad[0xae];
    s16 field_ae;
} Fn1_5D014Object;

void fn_1_5D014(Fn1_5D014Object *obj) {
    obj->field_ae = 0;
}
/* fzgx:end fn_1_5D014 */

/* fzgx:begin fn_1_5D1B8 noprologue */
#include "dolphin/types.h"

typedef struct { f32 x; f32 y; f32 z; } Vec3;
typedef struct { f32 x; f32 y; Vec3 pos; u8 pad_14[0x28]; u8 r; u8 g; u8 b; u8 a; } Quad;
typedef struct { u8 pad_00[0x14]; f32 f_14; } Obj;
typedef struct {
u8 pad_00[0x14]; f32 f_14; u8 pad_18[4];
f32 f_1c; f32 f_20; f32 f_24; f32 f_28;
u8 pad_2c[8]; Obj *f_34; u8 pad_38[4]; Vec3 v_3c;
u8 pad_48[0x66]; s16 s_ae;
} Self;
extern struct fn_1_620C8_lbl_1_rodata_2950 lbl_1_rodata_2950[];
extern u32 lbl_8006DCA4(void);
extern void lbl_8006E1B0(const Vec3 *in, Vec3 *out);
extern void lbl_8006D7DC(Vec3 *v);
extern void lbl_8006DB74(Vec3 *v);
extern void mathutil_mtxA_rotate_z(s32 angle);
extern void *memset(void *dst, int c, u32 n);
extern f32 fn_1_A71AC(void);
extern int fn_1_9F914(const void *a, const void *b);
#define LIT(off) (*(const f32 *)(pool + (off)))
#pragma opt_lifetimes off
static inline f32 fn_1_5D1B8_read_pointer(Self * owner) { return owner->f_24; }
static inline f32 fn_1_5D1B8_scaled(f32 product, f32 scale) { return product; }
#pragma opt_lifetimes reset
#pragma opt_common_subs off
#pragma peephole on
void fn_1_5D1B8(Self *self)
{
f32 fzgx_live_;
Vec3 v;
Obj * fzgx_live;
Quad out;
const u8 *pool = (const u8 *)&lbl_1_rodata_2950;
Obj *obj;
Self *s;
f32 cr;
f32 cg;
f32 cb;
f32 scale;
f32 fade;
f32 d;
s = self;
fzgx_live = s->f_34;
obj = fzgx_live;
scale = s->f_28;
lbl_8006DCA4();
lbl_8006E1B0(&s->v_3c, &v);
if (v.z > LIT(0x17c)) { return; }
d = LIT(0x180) * ((LIT(0xa0) * obj->f_14) * fn_1_5D1B8_scaled(scale, 1.0f)) / (-v.z * fn_1_A71AC());
fade = LIT(0x28);
if (d < LIT(0x184)) { return; }
if (d < LIT(0x188)) { fade = fade * ((d - LIT(0x184)) / LIT(0x18c)); }
if (d > LIT(0x190)) { return; }
if (d > LIT(0x194)) { fade = fade * (LIT(0x28) - (d - LIT(0x194)) / LIT(0x194)); }
lbl_8006D7DC(&v);
mathutil_mtxA_rotate_z(s->s_ae);
memset(&out, 0, 0x40);
lbl_8006DB74(&out.pos);
out.x = LIT(0x150) * scale;
fzgx_live_ = s->f_1c;
cr = LIT(0x5c) * fzgx_live_;
out.r = cr * fade;
cg = LIT(0x5c) * s->f_20;
out.g = cg * fade;
cb = LIT(0x5c) * fn_1_5D1B8_read_pointer(s);
out.b = cb * fade;
out.a = LIT(0x5c) * fade;
out.y = LIT(0x150) * scale;
fn_1_9F914(&out, obj);
}
#pragma peephole reset
#pragma opt_common_subs reset
/* fzgx:end fn_1_5D1B8 */

/* fzgx:begin fn_1_5D374 */
// fn_1_5D374: empty in retail (single blr).
void fn_1_5D374(void) {
}
/* fzgx:end fn_1_5D374 */

/* fzgx:begin fn_1_5D378 pool noprologue */
#include "dolphin/types.h"
#include "rel/main_rel/effect.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
}
#pragma section code_type ".text"

typedef struct fn_1_5D378_obj {
    s8 unk_00[0x10];
    s32 unk_10;
    u8 unk_14[4];
    s16 unk_18;
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
} fn_1_5D378_obj;

extern u32 fn_1_86634(int);
extern s32 fn_1_6EC0(u8);
extern s16 camera_get_entry_field_0xa4(u32);

static f32 rnd_unit(void)
{
    u32 r;

    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    r = (lbl_1_data_1D628 >> 16) & 0x7fff;
    return (f32)r / 32767.0f;
}

void fn_1_5D378(fn_1_5D378_obj *self)
{
    f32 a;
    f32 *fzgx_value;
    f32 b;
    u32 v;

    if (self->unk_10 == 0) {
        a = rnd_unit();
        a = 0.1f * a;
        self->unk_10 = (s32)((0.4f + a) * 60.0f);
    }

    v = (s8)fn_1_86634(self->unk_18);

    if (fn_1_6EC0((u8)v) != 0 && (s16)camera_get_entry_field_0xa4((u8)v) == 0) {
        fzgx_value = &(self->unk_1c);
        *fzgx_value = 0.0f;
        self->unk_20 = 0.0f;
        self->unk_24 = 0.0f;
    } else {
        b = rnd_unit();
        a = 0.2f * b;
        b = 0.5f + a;
        self->unk_1c = (204.0f * (0.5f * (1.0f + b))) / 255.0f;
        self->unk_20 = (85.0f * b) / 255.0f;
        self->unk_24 = 0.0f;
    }
}
/* fzgx:end fn_1_5D378 */

/* fzgx:begin fn_1_5D4FC */
// fn_1_5D4FC: empty in retail (single blr).
void fn_1_5D4FC(void) {
}
/* fzgx:end fn_1_5D4FC */

/* fzgx:begin fn_1_5D500 noprologue */
#include "rel/main_rel/effect.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
}
#pragma section code_type ".text"
extern u32 fn_1_86514(int);
extern u32 fn_1_867CC(u32, void *);
extern s8 fn_1_86634(int);
extern s32 fn_1_6EC0(u8);
extern s16 camera_get_entry_field_0xa4(u32);
typedef struct {
    u8 pad_0[8];
    u32 unk_8;
    u32 unk_C;
    s32 unk_10;
    u32 unk_14;
    s16 unk_18;
    u8 pad_1A[2];
    f32 unk_1C, unk_20, unk_24;
    u8 pad_28[0x14];
    u8 unk_3C[3];
} EffectUpdate;
#pragma opt_lifetimes off
void fn_1_5D500(EffectUpdate *arg0)
{
    f32 fzgx_live;
    s32 camera;
    f32 random;
    f32 scale;
    if (((fn_1_86514(arg0->unk_18) >> 27) & 1) && ((arg0->unk_8 >> 18) & 1)) {
        arg0->unk_10++;
    } else {
        arg0->unk_8 &= ~0x40000;
    }
    fn_1_867CC(arg0->unk_18, &arg0->unk_3C);
    camera = fn_1_86634(arg0->unk_18);
    if (fn_1_6EC0((u8)camera) && camera_get_entry_field_0xa4((u8)camera) == 0) {
        arg0->unk_1C += (f32)(0.05f * -arg0->unk_1C);
        fzgx_live = arg0->unk_20;
        arg0->unk_20 += (f32)(0.05f * -fzgx_live);
        arg0->unk_24 += (f32)(0.05f * -arg0->unk_24);
    } else {
        lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
        random = 0.5f + (f32)(0.1f * ((f32)((lbl_1_data_1D628 >> 16) & 0x7FFF) / 32767.0f));
        arg0->unk_1C = (204.0f * (0.5f * (1.0f + random))) / 255.0f;
        arg0->unk_20 = (85.0f * random) / 255.0f;
        arg0->unk_24 = 0.0f;
    }
    if (lbl_1_data_2A7E0.unk_0 == 6) {
        arg0->unk_1C *= 0.2f;
        arg0->unk_20 *= 0.2f;
        arg0->unk_24 *= 0.2f;
    }
    if (arg0->unk_10 < 20) {
        scale = 1.0f + (f32)(-0.05f * arg0->unk_10);
        arg0->unk_1C *= 1.0f - scale;
        arg0->unk_20 *= 1.0f - scale;
        arg0->unk_24 *= 1.0f - scale;
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_5D500 */

/* fzgx:begin fn_1_5D718 noprologue */
#include "dolphin/hw_regs.h"
#include "psvec.h"

typedef unsigned char u8;

typedef unsigned long u32;

typedef float f32;
typedef double f64;

extern const f32 lbl_1_rodata_2950[];
extern void lbl_8006D9D8(void *);
extern void lbl_8006D7B0(void);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void fn_1_9F914(void *, u32);
extern void *memset(void *, int, u32);
/* Fixed engine address; three floats at 0xc, 0x1c, 0x2c. */
struct Fn15D718 {
	u8 _pad00[0x1c];
	f32 value1c;
	f32 value20;
	f32 value24;
	f32 value28;
	u8 _pad2c[0x08];
	u32 object34;
	u8 _pad38[0x04];
	f32 value3c;
};
struct Fn15D718Tmp {
	u8 data[0x30];
};
struct Fn15D718Sub {
	u8 data[0x34];
};
struct Fn15D718Work {
	f32 alpha;
	f32 alpha2;
	struct Fn15D718Sub sub;
	u8 red;
	u8 green;
	u8 blue;
	u8 alphaByte;
};
#pragma opt_propagation off
#pragma opt_common_subs off
static inline f32 fn_1_64760_array_read(f32 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments off
void fn_1_5D718(struct Fn15D718 *self) {
struct Fn15D718Work work;
struct Fn15D718Tmp tmp;
u32 object;
f32 radius;
f32 distance;
f32 alpha;
const f32 *pool;
f32 v[3];
f32 x;
f32 y;
f32 z;
f32 sum;
f32 *m;
object = self->object34;
pool = lbl_1_rodata_2950;
radius = self->value28;
lbl_8006D9D8(&self->value3c);
lbl_8006D7B0();
m = (f32 *)(LC_BASE + 0x0);
x = fn_1_64760_array_read(m, 3);
y = fn_1_64760_array_read(m, 7);
z = fn_1_64760_array_read(m, 11);
psvec_set(v, z, y, x);
sum = (f32) (fn_1_64760_array_read(v, 0) * fn_1_64760_array_read(v, 0));
sum = sum + fn_1_64760_array_read(v, 1) * fn_1_64760_array_read(v, 1);
sum = sum + z * z;
distance = lbl_8006D0B4(sum);
if (distance > pool[1] + radius) {
lbl_8006DB74(&tmp);
lbl_8006D848((distance - radius) / distance);
lbl_8006DFC4(&tmp);
}
memset(&work, 0, 0x40);
lbl_8006DB74(&work.sub);
alpha = pool[0x150 / 4] * self->value28;
work.alpha = alpha;
work.red = (u8) (pool[0x5c / 4] * self->value1c);
work.green = (u8) (pool[0x5c / 4] * self->value20);
work.blue = (u8) (pool[0x5c / 4] * self->value24);
work.alphaByte = 0xff;
work.alpha2 = alpha;
fn_1_9F914(&work, object);
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

#pragma opt_propagation reset
/* fzgx:end fn_1_5D718 */

/* fzgx:begin fn_1_5D88C */
struct Fn15D88C {
    u8 _pad08[0x08];
    u32 flags;
    u8 _pad0c[0x1c];
    f32 value28;
    u8 _pad2c[0x08];
    u32 enabled;
    u8 _pad38[0x1c];
    u16 value54;
    u16 value56;
    u16 value58;
    u8 _pad5a[0x5a];
    f32 value_b4;
};

void fn_1_5D88C(struct Fn15D88C *self) {
    self->value_b4 = lbl_1_rodata_29AC[0];
    if (self->enabled != 0) {
        f32 value28;
        lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
        value28 = lbl_1_rodata_2978[0];
        self->value54 = (u16)((lbl_1_data_1D628 >> 16) & 0x7fff);
        lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
        self->value56 = (u16)((lbl_1_data_1D628 >> 16) & 0x7fff);
        lbl_1_data_1D628 = lbl_1_data_1D628 * 1103515245 + 12345;
        self->value58 = (u16)((lbl_1_data_1D628 >> 16) & 0x7fff);
        self->value28 = value28;
    }
    self->flags |= 0x40000000;
}
/* fzgx:end fn_1_5D88C */

/* fzgx:begin fn_1_5D918 */
// fn_1_5D918: empty in retail (single blr).
void fn_1_5D918(void) {
}
/* fzgx:end fn_1_5D918 */

/* fzgx:begin fn_1_5E3C4 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
}
#pragma section code_type ".text"

struct fn_1_5E3C4_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x9E];
    u16 unk_B2;
};

#pragma opt_dead_assignments off
#pragma opt_strength_reduction off
f32 fn_1_5E3C4(struct fn_1_5E3C4_Arg0 *arg0, f32 arg1) {
    f32 v0;
    u32 v1;
    f64 v2;
    f32 v4;
    f32 v5;
    f32 v6;
    u32 v7;
    f64 v8;
    f32 v10;
    f32 v11;
    f32 v12;
    v0 = arg1;
    if (arg0->unk_B2 == 1) {
        if (((0) == ((s32)(*(u32 volatile *)&arg0->unk_10)))) { /* Retail requires a distinct field reload. */
            v1 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
            v2 = 4503599627370496.0;
            v4 = 0.25f;
            v5 = 0.400000006f;
            lbl_1_data_1D628 = v1;
            v6 = 60.0f;
            v0 = (f32)(u32)((v1 >> 16) & 0x7FFF);
            arg0->unk_10 = (s32)(f32)(v6 * (f32)(v5 + (f32)(v4 * (f32)(v0 / (32767.0f)))));
        }
    } else {
        if (((0) == ((s32)(*(u32 volatile *)&arg0->unk_10)))) { /* Retail requires a distinct field reload. */
            v7 = lbl_1_data_1D628 * 0x41C64E6D + 12345;
            v8 = 4503599627370496.0;
            v10 = 0.25f;
            v11 = 0.0799999982f;
            v12 = 60.0f;
            lbl_1_data_1D628 = v7;
            v0 = (f32)(u32)((v7 >> 16) & 0x7FFF);
            arg0->unk_10 = (s32)(f32)(v12 * (f32)(v11 + (f32)(v10 * (f32)(v0 / (32767.0f)))));
        }
    }
    return v0;
}
#pragma opt_strength_reduction reset
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_5E3C4 */

/* fzgx:begin fn_1_5EB08 */
typedef struct FnObj {
    u8 pad18[0x18];
    s16 value;
    u8 pad3c[0x22];
    f32 field3c;
} FnObj;

typedef struct FnLocal {
    u8 data[0x10];
} FnLocal;

typedef struct FnNode {
    u8 pad4[4];
    void (*callback)(void);
    FnObj *object;
} FnNode;

void fn_1_5EB08(FnObj *object) {
    FnLocal local;
    FnNode *node;
    FnNode *allocated;

    fn_1_862D4(object->value, &local);
    lbl_8006DCA4();
    if (fn_1_54E34(&object->field3c, lbl_1_rodata_2AF4[0])) {
        node = fn_1_5448C(&local);
        allocated = fn_1_548AC(0xc);
        if (allocated != 0) {
            allocated->callback = fn_1_5EB98;
            allocated->object = object;
            fn_1_5489C( (void **)(void *)(node), (void **)(void *)(allocated));
        }
    }
}
/* fzgx:end fn_1_5EB08 */

/* fzgx:begin fn_1_5F5C4 */
// fn_1_5F5C4: empty in retail (single blr).
void fn_1_5F5C4(void) {
}
/* fzgx:end fn_1_5F5C4 */

/* fzgx:begin fn_1_5F5C8 pool noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
}
#pragma section code_type ".text"

struct fn_1_5F5C8_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
};
struct fn_1_5F5C8_lbl_1_data_1D628 {
    u32 unk_0;
};
struct fn_1_5F5C8_lbl_1_rodata_2950 {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    u8 pad_C[0x14];
    f64 unk_20;
    u8 pad_28[0x44];
    f32 unk_6C;
    u8 pad_70[0x48];
    f32 unk_B8;
};

extern struct fn_1_5F5C8_lbl_1_data_1D628 lbl_1_data_1D628;
const f32 lbl_1_rodata_2950 = 60.0f;
const u8 lbl_1_rodata_2954[4] = {0x3D,0xCC,0xCC,0xCD};
const f32 lbl_1_rodata_2954__fzgx_offset_4 = 32767.0f;
const u8 lbl_1_rodata_295C[20] = {0x3D,0x4C,0xCC,0xCD,0x3F,0xB1,0xEB,0x85,0x1E,0xB8,0x51,0xEC,0x46,0x9C,0x40,0x00,0x00,0x00,0x00,0x00};
const f64 lbl_1_rodata_295C__fzgx_offset_14 = 4503599627370496.0;
const u8 lbl_1_rodata_2978[16] = {0x3F,0x80,0x00,0x00,0xBC,0xF5,0xC2,0x8F,0x40,0x2E,0x00,0x00,0x00,0x00,0x00,0x00};
const u8 lbl_1_rodata_2988[28] = {0x43,0x30,0x00,0x00,0x80,0x00,0x00,0x00,0x3F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
const u8 lbl_1_rodata_29A4[8] = {0x3F,0x00,0x00,0x00,0x41,0x00,0x00,0x00};
const u8 lbl_1_rodata_29AC[16] = {0x43,0x7F,0x00,0x00,0x41,0x70,0x00,0x00,0x3E,0x4C,0xCC,0xCD,0x3D,0xA3,0xD7,0x0A};
const f32 lbl_1_rodata_29AC__fzgx_offset_10 = 0.25f;
const u8 lbl_1_rodata_29C0[48] = {0x3F,0x7A,0xE1,0x48,0x3F,0x7D,0x70,0xA4,0x42,0x20,0x00,0x00,0x41,0xA0,0x00,0x00,0x3F,0xC0,0x00,0x00,0x3E,0xE6,0x66,0x66,0xC0,0x00,0x00,0x00,0x3D,0xAA,0xAA,0xAB,0x3E,0x19,0x99,0x9A,0x3E,0x00,0x00,0x00,0xBE,0xCC,0xCC,0xCD,0xBE,0x99,0x99,0x9A};
const u8 lbl_1_rodata_29F0[24] = {0x40,0x00,0x00,0x00,0x43,0x7A,0x00,0x00,0x3F,0xE3,0x33,0x33,0x33,0x33,0x33,0x33,0x3F,0xD9,0x99,0x99,0x99,0x99,0x99,0x9A};
const f32 lbl_1_rodata_29F0__fzgx_offset_18 = 0.300000012f;
const u8 lbl_1_rodata_29F0__fzgx_offset_1C[80] = {0xBB,0x83,0x12,0x6F,0x3C,0x88,0x88,0x89,0x47,0x80,0x00,0x00,0x45,0x80,0x00,0x00,0x3F,0x75,0xC2,0x8F,0x3E,0xCC,0xCC,0xCD,0x3D,0x4E,0xD9,0x17,0x3D,0x50,0xE5,0x60,0x3F,0x73,0x33,0x33,0x3F,0x66,0x66,0x66,0x00,0x00,0x00,0x00,0x40,0x62,0xC0,0x00,0x00,0x00,0x00,0x00,0x40,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3D,0xCC,0xCC,0xCD,0xC0,0x19,0x99,0x9A};

#pragma opt_dead_assignments off
f32 fn_1_5F5C8(struct fn_1_5F5C8_Arg0 *arg0, f32 arg1) {
    f32 v0;
    u32 v1;
    f32 v2;
    f32 v3;
    f32 v4;
    f32 v5;
    f32 v6;
    v0 = arg1;
    if ((s32)arg0->unk_10 == 0) {
    v1 = (((12345) + ((lbl_1_data_1D628.unk_0 * (0x41C60000 + 20077)))));
    v2 = (4503599627370496.0);
    v4 = (0.25f);
    v5 = (0.300000012f);
    v6 = (60.0f);
    lbl_1_data_1D628.unk_0 = v1;
    v0 = (f32)(u32)((v1 >> 16) & 0x7FFF);
    arg0->unk_10 = (s32)(f32)(v6 * (f32)(v5 + (f32)(v4 * (f32)(v0 / ((32767.0f))))));
    }
    return v0;
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_5F5C8 */

/* fzgx:begin fn_1_5FE24 */
// fn_1_5FE24: empty in retail (single blr).
void fn_1_5FE24(void) {
}
/* fzgx:end fn_1_5FE24 */

/* fzgx:begin fn_1_5FE28 */
// fn_1_5FE28: empty in retail (single blr).
void fn_1_5FE28(void) {
}
/* fzgx:end fn_1_5FE28 */

/* fzgx:begin fn_1_5FE2C */
// fn_1_5FE2C: empty in retail (single blr).
void fn_1_5FE2C(void) {
}
/* fzgx:end fn_1_5FE2C */

/* fzgx:begin fn_1_5FE30 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect.h"

extern void lbl_8006DCA4(void);
extern s32 fn_1_54E34(void *object, f32 value);
extern void fn_1_5FEBC(void);

extern void lbl_8006DCA4(void);
extern s32 fn_1_54E34(void *object, f32 value);
extern void *fn_1_5448C(void *);
extern void fn_1_5489C(void *, void *);
extern void fn_1_862D4(s16 value, void *result);
extern void *fn_1_548AC(u32 size);

#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect.h"

typedef struct {
    u8 unk[0x18];
    s16 value;
    u8 unk1A[0x0E];
    f32 rate;
    u8 unk2C[0x10];
    u8 field3C[1];
} fn_1_5FE30_FZeroObject;

typedef struct {
    u8 unk0[4];
    void (*callback)(void);
    fn_1_5FE30_FZeroObject *owner;
} FZeroEvent;

void fn_1_5FE30(fn_1_5FE30_FZeroObject *object) {
    u8 result[8];
    void *callback;
    FZeroEvent *event;

    fn_1_862D4(object->value, result);
    lbl_8006DCA4();
    if (fn_1_54E34(object->field3C, object->rate) != 0) {
        callback = fn_1_5448C(result);
        event = (FZeroEvent *)fn_1_548AC(12);
        if (event != 0) {
            event->callback = fn_1_5FEBC;
            event->owner = object;
            fn_1_5489C(callback, event);
        }
    }
}
/* fzgx:end fn_1_5FE30 */

/* fzgx:begin fn_1_5FEBC */
void fn_1_5FEBC(fn_1_5FEBC_EffectObject *object) {
    u8 result[12];
    u8 data[64];
    fn_1_5FEBC_EffectData *effect;
    void *owner;
    f32 color_scale;
    f32 size;

    effect = object->data;
    fn_1_867CC(effect->value18, result);
    owner = effect->field34;
    lbl_8006D9D8(result);
    lbl_8006D7B0();
    mathutil_mtxA_rotate_y(effect->value56);
    mathutil_mtxA_rotate_x(effect->value54);
    memset(data, 0, 64);
    lbl_8006DB74(data + 8);
    size = lbl_1_rodata_2AA0[0];
    size = size * effect->value28;
    *(f32 *)(data + 0) = size;
    color_scale = (((const f32 *)&lbl_1_rodata_29AC))[0];
    data[60] = (u8)(s32)(color_scale * effect->value1C);
    data[61] = (u8)(s32)(color_scale * effect->value20);
    data[62] = (u8)(s32)(color_scale * effect->value24);
    data[63] = 0xff;
    *(f32 *)(data + 4) = size;
    fn_1_9F914(data, owner);
}
/* fzgx:end fn_1_5FEBC */

/* fzgx:begin fn_1_5FFAC */
// fn_1_5FFAC: empty in retail (single blr).
void fn_1_5FFAC(void) {
}
/* fzgx:end fn_1_5FFAC */

/* fzgx:begin fn_1_60170 */
typedef struct {
    u8 unk[0x38];
    void *field38;
} fn_1_60170_FZeroObject;

// Submit the effect data when this object has an associated field.
void fn_1_60170(fn_1_60170_FZeroObject *object) {
    if (object->field38 != 0) {
        fn_1_46B4((u32)lbl_801A6410, (u32)(void *)(object->field38), (const char *)(u8 *)(lbl_1_data_1D62C), 0x1261);
    }
}
/* fzgx:end fn_1_60170 */

/* fzgx:begin fn_1_601B4 */
typedef struct {
    u8 unk_0[0x10];
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0x24];
    f32 unk_3c;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4c;
    f32 unk_50;
    u8 unk_54[0x60];
    f32 unk_b4;
} EffectState;


void fn_1_601B4(EffectState *effect) {
    f32 factor;

    effect->unk_14--;
    if (effect->unk_14 > 0) {
        factor = lbl_1_rodata_29C0;
        effect->unk_48 *= factor;
        effect->unk_4c *= factor;
        effect->unk_50 *= factor;
        effect->unk_3c += effect->unk_48;
        effect->unk_40 += effect->unk_4c;
        effect->unk_44 += effect->unk_50;
        effect->unk_b4 = lbl_1_rodata_29F0;
    } else {
        s32 numerator = effect->unk_10;
        s32 denominator = lbl_1_bss_6C86C;

        effect->unk_b4 = (f32)numerator / (f32)denominator;
    }
}
/* fzgx:end fn_1_601B4 */

/* fzgx:begin fn_1_60734 */
typedef struct Fn60734 {
    u8 pad_00[0x0e];
    s16 unk_0e;
    s32 unk_10;
    u8 pad_14[0x14];
    f32 unk_28;
    u8 pad_2c[0x28];
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
} Fn60734;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[2] = {0x00000000, 0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.4000000953674316f;
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table12[1] = {0xB4000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
    s = 1.100000023841858f;
}
static const u32 fzgx_pool_table16[2] = {0x00000000, 0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.100000023841858f;
}
static const u32 fzgx_pool_table18[4] = {0x00000000, 0x3F666666, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.699999988079071f;
}
static const u32 fzgx_pool_table20[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table22[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
}
#pragma section code_type ".text"
void fn_1_60734(Fn60734 *effect) {
    u32 value;

    if (effect->unk_10 == 0) {
        value = lbl_1_data_1D628 * 1103515245 + 12345;
        lbl_1_data_1D628 = value;
        effect->unk_10 = (s32)(210.0 + 60.0f * ((f32)((value >> 16) & 0x7fff) / 32767.0f));
    }

    effect->unk_0e = 0;
    if (0.0f == effect->unk_28) {
        f64 prod;
        value = lbl_1_data_1D628 * 1103515245 + 12345;
        lbl_1_data_1D628 = value;
        prod = 0.02 * ((f32)((value >> 16) & 0x7fff) / 32767.0f);
        effect->unk_28 = (f32)(prod + 0.02);
    }

    value = lbl_1_data_1D628 * 1103515245 + 12345;
    lbl_1_data_1D628 = value;
    effect->unk_54 = (value >> 16) & 0x7fff;

    value = lbl_1_data_1D628 * 1103515245 + 12345;
    lbl_1_data_1D628 = value;
    effect->unk_56 = (value >> 16) & 0x7fff;

    value = lbl_1_data_1D628 * 1103515245 + 12345;
    lbl_1_data_1D628 = value;
    effect->unk_58 = (value >> 16) & 0x7fff;
}
/* fzgx:end fn_1_60734 */

/* fzgx:begin fn_1_60B80 noprologue */
#include "dolphin/types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
}
#pragma section code_type ".text"

typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Sig_fn_1_5557C_Fn1_5557CObject;

typedef Sig_fn_1_5557C_Fn1_5557CObject Sig_fn_1_555D0_Fn1_555D0Object;

typedef struct {
    u8 unk_00[0x10];
    s32 unk_10;
    u8 unk_14[0x14];
    f32 unk_28;
    u8 unk_2C[0x8];
    Sig_fn_1_5557C_Fn1_5557CObject *unk_34;
    u8 unk_38[0x4];
    u32 unk_3C;
    u8 unk_40[0x14];
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
} Sig_fn_1_60B80_Obj;

extern void fn_1_55FC4(f32);
extern void fn_1_55FF0(f32);
extern void fn_1_5557C(Sig_fn_1_5557C_Fn1_5557CObject *);
extern void fn_1_555D0(Sig_fn_1_555D0_Fn1_555D0Object *);
extern void lbl_8006D9D8(void *mtx);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void lbl_8006E14C(f32);

void fn_1_60B80(Sig_fn_1_60B80_Obj *obj, u32 lab_unused0, u32 lab_unused1, u32 lab_unused2)
{
    f32 fzgx_live;
    f32 v = 1.0f;

    lbl_8006D9D8(&obj->unk_3C);
    mathutil_mtxA_rotate_y(obj->unk_56);
    mathutil_mtxA_rotate_x(obj->unk_54);
    mathutil_mtxA_rotate_z(obj->unk_58);
    if (v < 0.0) {
        return;
    }
    if (v > 1.0) {
        v = 1.0f;
    }
    fzgx_live = obj->unk_28;
    lbl_8006E14C(fzgx_live);
    fzgx_live = obj->unk_28;
    fn_1_55FC4(fzgx_live);
    if (obj->unk_10 < 12) {
        v *= 0.0833333358168602f * (f32)(s32)obj->unk_10;
    }
    if (v < 1.0) {
        fn_1_55FF0(v);
        fn_1_5557C(obj->unk_34);
    }
    else {
        fn_1_555D0(obj->unk_34);
    }
}
/* fzgx:end fn_1_60B80 */

/* fzgx:begin fn_1_60C70 */
// fn_1_60C70: empty in retail (single blr).
void fn_1_60C70(void) {
}
/* fzgx:end fn_1_60C70 */

/* fzgx:begin fn_1_60C74 */
struct fn_1_60C74_Effect {
    u8 _pad[0x28];
    f32 field_28;
};

void fn_1_60C74(struct fn_1_60C74_Effect *effect) {
    effect->field_28 = lbl_1_rodata_2A5C[0];
}
/* fzgx:end fn_1_60C74 */

/* fzgx:begin fn_1_60C84 */
// fn_1_60C84: empty in retail (single blr).
void fn_1_60C84(void) {
}
/* fzgx:end fn_1_60C84 */

/* fzgx:begin fn_1_60C88 noprologue */
#include "dolphin/types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_f;

extern void fn_1_862D4(int, Vec3_f *);
extern void fn_1_8636C(int, void *);
extern void *lbl_801A6D00[1];

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4_f;

extern void lbl_8006E1B0(Vec4_f *, Vec4_f *);

typedef struct {
    u8 pad_00[0x10];
    u32 i10;
    u8 pad_14[4];
    s16 s18;
    u8 pad_1A[0xE];
    f32 f28;
    u8 pad_2C[0x10];
    Vec4_f v3c;
    u8 pad_4C[0x48];
    Vec4_f v94;
    u8 pad_A4[0x10];
    f32 fb4;
} Obj_60C88;

static inline f32 fn_1_60C88_read_pointer(Obj_60C88 * owner) { return owner->f28; }
#pragma opt_propagation off
void fn_1_60C88(Obj_60C88 *this)
{
    Vec3_f v;
    void * lab_t1;
    f32 tz, ty, tx;

    fn_1_862D4((int)this->s18, &v);
    lab_t1 = (*((0) + (lbl_801A6D00)));
    fn_1_8636C((int)this->s18, lab_t1);

    tx = v.x;
    ty = v.y;
    tz = v.z;
    *(f32 *)(0xE0000000 + 0x0C) = tx;
    *(f32 *)(0xE0000000 + 0x1C) = ty;
    *(f32 *)(0xE0000000 + 0x2C) = tz;

    lbl_8006E1B0(&this->v94, &this->v3c);

    this->fb4 = (f32)(s32)this->i10 * 0.5f;
    if (fn_1_60C88_read_pointer(this) > 0.0f) {
        this->f28 = (f32)((f64)fn_1_60C88_read_pointer(this) - 0.3);
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_60C88 */

/* fzgx:begin fn_1_60F7C */
// fn_1_60F7C: empty in retail (single blr).
void fn_1_60F7C(void) {
}
/* fzgx:end fn_1_60F7C */

/* fzgx:begin fn_1_60F80 */
// fn_1_60F80: empty in retail (single blr).
void fn_1_60F80(void) {
}
/* fzgx:end fn_1_60F80 */

/* fzgx:begin fn_1_60F84 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect.h"

typedef struct fn_1_58D38_EffectEntry {
    s8 unk_00;
    u8 pad_01[7];
    u32 unk_08;
    s16 unk_0C;
    u8 pad_0E[0x0C];
    u16 unk_1A;
    u8 pad_1C[0xCC];
} fn_1_58D38_EffectEntry;

struct fn_1_5BF70_lbl_1_rodata_2950 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
    f64 unk_20;
    u8 pad_28[0xC8];
    f64 unk_F0;
    f64 unk_F8;
    u8 pad_100[0x30];
    f64 unk_130;
};

typedef struct {
    u8 unk00[0x18];
    s16 value18;
    u8 unk1A[2];
    f32 value1C;
    f32 value20;
    f32 value24;
    f32 value28;
    u8 unk2C[8];
    void *field34;
    u8 unk38[0x1c];
    s16 value54;
    s16 value56;
} fn_1_5FEBC_EffectData;

typedef struct {
    u8 unk00[8];
    fn_1_5FEBC_EffectData *data;
} fn_1_5FEBC_EffectObject;

typedef struct {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x20];
    u32 unk_34;
    void *unk_38;
    u8 pad_3c[0x18];
    s16 unk_54;
    u8 pad_56[0x4];
    u16 unk_5a;
    u8 pad_5c[0x58];
    f32 unk_b4;
} fn_1_61D08_EffectObject;

typedef struct {
    u8 pad_00[0x8];
    void *unk_08;
} fn_1_652F4_Effect;

typedef struct {
    u8 pad20[0x20];
    void *unk_20;
} Fn1_61E60Node;

typedef struct {
    u8 pad38[0x38];
    Fn1_61E60Node *unk_38;
} Fn1_61E60Object;
extern void fn_1_62360(fn_1_58D38_EffectEntry *arg0);
extern u32 fn_1_3FC58(void);
extern void *memcpy(void *, const void *, u32);
extern void fn_1_862D4(s16 value, void *result);
extern f32 lbl_8006D0B4(f32 value);
extern s32 fn_1_54E34(void *arg0, f32 arg1);
extern void lbl_8006D7B0(void);
extern void lbl_8006D9D8(void *);
extern void mathutil_mtxA_rotate_z(int);
extern const f32 lbl_1_rodata_2950;
extern void fn_1_8636C();
extern void fn_1_867CC(s16 value, void *out);
extern void mathutil_mtxA_rotate_y(s16 value);
extern void mathutil_mtxA_rotate_x(s16 value);
extern void lbl_8006DB74(void *);
extern int fn_1_9F914(const void *src0, const void *src1);
extern const f32 lbl_1_rodata_2AA0[21];
extern f32 lbl_1_rodata_29AC[5];
extern void *memset(void *, int, u32);
extern void *lbl_801A6D00;
extern void fn_1_55FC4(f32 value);
extern void fn_1_55FF0(f32 value);
extern void fn_1_5557C(void *object);
extern void fn_1_555D0(void *object);
extern void lbl_8006E1B0(void *src, void *dst);
extern void lbl_8006E14C(f32);
extern void *lbl_801A6410;
extern s32 fn_1_45D0();
extern u32 GXGetTexBufferSize(u16, u16, u32, u32, u8);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_4730(u32 value, u32 count, u32 size, const char *file, int line);
extern void lbl_8006DCA4();
extern void lbl_8006D7DC(void *obj);
extern void *fn_1_868C0(s8 index);
extern void *fn_1_86254(int index);
extern void lbl_8006D95C(s32);
extern void lbl_8006DFC4(void *);
extern void fn_1_3BDC(u32 arg0);
extern u32 fn_1_3C18(s32 arg0);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_80008BA8(void *, void *, int);
extern void fn_1_680F8(void);
extern void fn_1_68284(void);
extern void fn_1_68B68(void);
extern void fn_1_68248(void);
extern void fn_1_69BBC(void);
extern void fn_1_69BCC(void);
extern f32 lbl_1_rodata_2978[4];
extern f32 lbl_1_rodata_2AF4[14];
extern void fn_1_5EB98(void);
extern void fn_1_5FEBC(fn_1_5FEBC_EffectObject *object);
extern f32 lbl_1_rodata_2A5C[5];
extern int fn_1_61D08();
extern void fn_1_61EF4(void);
extern void fn_1_620C4(void);
extern f32 lbl_1_rodata_2B2C[145];
extern void fn_1_638E8(void);
extern const f32 lbl_1_rodata_2A70[12];
extern void fn_1_64388(void);
extern void fn_1_652F4(fn_1_652F4_Effect *effect);
extern void fn_1_65748(void);
extern void *fn_1_5448C(void *);
extern int fn_1_61E60();
extern void fn_1_5489C(void **arg0, void **arg1);
extern void *fn_1_548AC(u32 size);
extern u32 fn_1_3FC8C(void);
extern const f32 lbl_1_rodata_29A4;
extern f64 lbl_1_rodata_2988;
extern u32 fn_1_620C8(void *);
extern f32 fn_1_8652C(int index);
extern void fn_1_557C4(void *value);
extern void fn_1_56000(u8 value0, u8 value1, u8 value2);
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern const f32 lbl_1_rodata_29C0;
extern const f32 lbl_1_rodata_29F0;
extern u32 fn_1_58C4(void);
extern const f64 lbl_1_rodata_2954;

/* Shared literal pool primer: lays out lbl_1_rodata_2950 in retail order so the
   function's own literals dedupe onto retail's offsets (0xcc, 0x118, 0x38, 0x28, 0x1a0). */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[2] = {0x00000000, 0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.4000000953674316f;
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table12[1] = {0xB4000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
}
#pragma section code_type ".text"

typedef struct fn_1_60F84_Effect {
    u8 pad0[0x10];
    s32 age;
    u8 pad14[8];
    f32 color_1c;
    f32 color_20;
    f32 color_24;
    f32 size;
    f32 target_size;
    u8 pad30[0xC];
    f32 pos_x;
    f32 pos_y;
    f32 pos_z;
    f32 vel_x;
    f32 vel_y;
    f32 vel_z;
} fn_1_60F84_Effect;

void fn_1_60F84(fn_1_60F84_Effect *obj)
{
    f32 t;
    f64 d;
    f32 k = 0.96f;

    obj->vel_x = obj->vel_x * k;
    obj->vel_y = obj->vel_y * k;
    obj->vel_z = obj->vel_z * k;
    obj->pos_x = obj->pos_x + obj->vel_x;
    obj->pos_y = obj->pos_y + obj->vel_y;
    obj->pos_z = obj->pos_z + obj->vel_z;
    /* held in a double so the product and sum stay separate (fmul; fadd; frsp) */
    d = 0.1 * (obj->target_size - obj->size);
    obj->size = obj->size + d;

    if (obj->age < 20) {
        t = 1.0f + (f32)(-0.05f * (f32)obj->age);
        /* the common factor is CSE'd by the compiler; a named local would
           coalesce it with the chain and move the color load's register */
        obj->color_1c = obj->color_1c * (1.0f - t);
        obj->color_20 = obj->color_20 * (1.0f - t);
        obj->color_24 = obj->color_24 * (1.0f - t);
    }
}
/* fzgx:end fn_1_60F84 */

/* fzgx:begin fn_1_61070 noprologue */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect.h"

typedef struct Fn161070 {
    u8 pad00[0x1c];
    f32 field1c;
    f32 field20;
    f32 field24;
    f32 field28;
    u8 pad2c[0x8];
    int field34;
    u8 pad38[0x4];
    u8 field3c[0x1c];
    s16 field58;
} Fn161070;

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
} Vec;

#define FZGX_CURRENT_MTX_ADDR 0xE0000000u
typedef struct Mat44 {
    f32 m[4][4];
} Mat44;

typedef struct EfxData {
    f32 field0;
    f32 field4;
    u8 mtx[0x34];
    u8 color[4];
} EfxData;

typedef struct Fade {
    f32 m[12];
} Fade;

extern const f32 lbl_1_rodata_2950[200];
extern void lbl_8006D9D8(void *);
extern void lbl_8006D7B0(void);
extern void mathutil_mtxA_rotate_z(s16);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void fn_1_9F914(void *, int);
extern u8 *memset(u8 *, int, u32);

#pragma opt_loop_invariants off
#pragma opt_propagation off
static inline f32 fn_1_61070_read_pointer(Vec * owner) { return owner->y; }
#pragma opt_dead_assignments off
#pragma opt_common_subs off
static inline f32 fn_1_61070_read_pointer_(Vec * owner) { return owner->x; }
#pragma opt_strength_reduction off
void fn_1_61070(Fn161070 *self) {
    f32 fzgx_live;
    EfxData data;
    Fade fade;
    Vec vector;
    struct { const f32 *value; } pool;
    int id = self->field34;
    f32 radius = self->field28;
    f32 acc;
    f32 distance;
    f32 scale;
    pool.value = lbl_1_rodata_2950;

    lbl_8006D9D8(self->field3c);
    lbl_8006D7B0();
    mathutil_mtxA_rotate_z(self->field58);

    {
        const Mat44 *src = (const Mat44 *)(FZGX_CURRENT_MTX_ADDR);
        psvec_set(&vector, src->m[2][3], src->m[1][3], src->m[0][3]);
    }
    fzgx_live = fn_1_61070_read_pointer_(&vector);
    acc = fzgx_live * fzgx_live;
    acc = fn_1_61070_read_pointer(&vector) * fn_1_61070_read_pointer(&vector) + acc;
    acc = vector.z * vector.z + acc;
    distance = lbl_8006D0B4(acc);

    if (distance > pool.value[1] + radius) {
        lbl_8006DB74(&fade);
        lbl_8006D848((distance - radius) / distance);
        lbl_8006DFC4(&fade);
    }

    memset((u8 *)&data, 0, 0x40);
    lbl_8006DB74(data.mtx);
    scale = pool.value[0x54] * self->field28;
    data.field0 = scale;
    data.color[0] = (u8)(pool.value[0x17] * self->field1c);
    data.color[1] = (u8)(pool.value[0x17] * self->field20);
    data.color[2] = (u8)(pool.value[0x17] * self->field24);
    data.color[3] = 0xff;
    data.field4 = scale;
    fn_1_9F914(&data, id);
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset

#pragma opt_dead_assignments reset

#pragma opt_propagation reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_1_61070 */

/* fzgx:begin fn_1_61640 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
}
#pragma section code_type ".text"


struct Fn1_61640Pool {
    u8 _pad00[0x28];
    f32 initial;
    u8 _pad2c[0xc];
    f64 int_bias;
    u8 _pad40[0x4c];
    f32 scale;
    u8 _pad90[0x200];
    f64 threshold;
};

struct Fn1_61640Object {
    u8 _pad10[0x10];
    s32 field_10;
    u8 _pad14[0x4];
    s16 field_18;
    u8 _pad1a[0xe];
    f32 field_28;
    u8 _pad2c[0x8];
    void *field_34;
    u8 _pad38[0x4];
    f32 field_3c[3];
    u8 _pad48[0xc];
    s16 field_54;
    s16 field_56;
    s16 field_58;
};

#pragma opt_propagation off
void fn_1_61640(struct Fn1_61640Object *object) {
    const struct Fn1_61640Pool *pool = (const struct Fn1_61640Pool *)&lbl_1_rodata_2950;
    f32 value = (1.0f);
    f32 output[3];
    f32 temp[3];
    f32 pz, py, px;

    fn_1_862D4(object->field_18, output);
    fn_1_8636C(object->field_18, lbl_801A6D00);

    px = ((0)[output]);
    py = ((1)[output]);
    pz = ((2)[output]);

    *(f32 *)(0xE0000000 + 0x0c) = px;
    *(f32 *)(0xE0000000 + 0x1c) = py;
    *(f32 *)(0xE0000000 + 0x2c) = pz;

    lbl_8006E1B0(object->field_3c, temp);
    lbl_8006D9D8(temp);
    mathutil_mtxA_rotate_y(object->field_56);
    mathutil_mtxA_rotate_x(object->field_54);
    mathutil_mtxA_rotate_z(object->field_58);
    lbl_8006E14C(object->field_28);
    fn_1_55FC4(object->field_28);

    if (object->field_10 < 12) {
        value *= (0.0833333358f) * (f32)object->field_10;
    }
    if (value < (1.0)) {
        fn_1_55FF0(value);
        fn_1_5557C(object->field_34);
    } else {
        fn_1_555D0(object->field_34);
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_61640 */

/* fzgx:begin fn_1_61760 */
struct Fn1_61760Object {
    u8 _pad38[0x38];
    void *effect_resource;
};

// Dispatches the object's effect resource when one is available.
void fn_1_61760(struct Fn1_61760Object *object) {
    if (object->effect_resource != 0) {
        fn_1_46B4((u32)lbl_801A6410, (u32)(void *)(object->effect_resource), (const char *)(u8 *)(lbl_1_data_1D62C), 0x16c1);
    }
}
/* fzgx:end fn_1_61760 */

/* fzgx:begin fn_1_617A4 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
}
#pragma section code_type ".text"


struct Fn1_617A4Object {
    u8 _pad10[0x10];
    s32 unk_10;
    u8 _pad14[0x80];
    f32 unk_94;
    f32 unk_98;
};

void fn_1_617A4(struct Fn1_617A4Object *object) {
    const f32 *pool;
    f32 t;

    pool = (((const f32 *)&lbl_1_rodata_2950));

    if (object->unk_10 == 0) {
        lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        object->unk_10 = (s32)((60.0f) *
            ((0.100000001f) + (f32)(u32)((lbl_1_data_1D628 >> 16) & 0x7fff) / (32767.0f)));
    }

    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    t = (0.0299999993f) * ((f32)(u32)((lbl_1_data_1D628 >> 16) & 0x7fff) / (32767.0f));
    object->unk_94 = (0.0700000003f) + t;

    lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
    t = (0.100000001f) * ((f32)(u32)((lbl_1_data_1D628 >> 16) & 0x7fff) / (32767.0f));
    object->unk_98 = (0.0700000003f) + t;
}
/* fzgx:end fn_1_617A4 */

/* fzgx:begin fn_1_618B8 noprologue */
#include "dolphin/types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
}
#pragma section code_type ".text"

struct obj_state {
	u8 pad00[0x10];
	s32 timer;
	u8 pad14[8];
	f32 f1c;
	f32 f20;
	f32 f24;
	f32 f28;
	f32 f2c;
	u8 pad30[0xc];
	f32 f3c;
	f32 f40;
	f32 f44;
	f32 f48;
	f32 f4c;
	f32 f50;
	u8 pad54[0x40];
	f32 f94;
	f32 f98;
};

#pragma peephole on
#pragma opt_dead_assignments off
#pragma opt_propagation off
void fn_1_618B8(struct obj_state *p)
{
    f32 fzgx_live__;
	f32 fzgx_live_;
	f32 fzgx_live;
	f32 s;
	s32 t;

	s = 1.0f - p->f94;
	p->f4c += -0.004f;
	p->f48 = p->f48 * s;
	p->f4c = p->f4c * s;
	p->f50 = p->f50 * s;
	p->f3c = p->f3c + p->f48;
	p->f40 = p->f40 + p->f4c;
	p->f44 = p->f44 + p->f50;
	p->f94 = (f32)(0.05f * (p->f98 - p->f94)) + p->f94;
	p->f28 = (f32)(0.2f * (p->f2c - p->f28)) + p->f28;
	t = p->timer;
	if ((f64)t < 15.0) {
		f32 k = 1.0f - 1.0f / (f32)(t + 1);

		fzgx_live_ = p->f1c;
		fzgx_live = fzgx_live_;
		p->f1c = fzgx_live * k;
		p->f20 = p->f20 * k;
		fzgx_live__ = p->f24;
		p->f24 = fzgx_live__ * k;
	}
}
#pragma opt_propagation reset

#pragma opt_dead_assignments reset

#pragma peephole reset
/* fzgx:end fn_1_618B8 */

/* fzgx:begin fn_1_61C84 */
// fn_1_61C84: empty in retail (single blr).
void fn_1_61C84(void) {
}
/* fzgx:end fn_1_61C84 */

/* fzgx:begin fn_1_61C88 */
void fn_1_61C88(void) {
    fn_1_61D08();
}
/* fzgx:end fn_1_61C88 */

/* fzgx:begin fn_1_61CA8 */
void fn_1_61CA8(void) {
    fn_1_61EF4();
}
/* fzgx:end fn_1_61CA8 */

/* fzgx:begin fn_1_61CC8 */
void fn_1_61CC8(void) {
    fn_1_620C4();
}
/* fzgx:end fn_1_61CC8 */

/* fzgx:begin fn_1_61CE8 */
void fn_1_61CE8(void) {
    fn_1_61E60();
}
/* fzgx:end fn_1_61CE8 */

/* fzgx:begin fn_1_61D08 */
typedef struct {
    u8 pad_0[0x20];
    void *unk_20;
} EffectChild;

typedef struct {
    u8 pad_0[0x130];
    u32 unk_130;
} EffectInner;

#pragma opt_common_subs off
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[2] = {0x00000000, 0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.4000000953674316f;
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table12[1] = {0xB4000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
    s = 1.100000023841858f;
}
static const u32 fzgx_pool_table16[2] = {0x00000000, 0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.100000023841858f;
}
static const u32 fzgx_pool_table18[4] = {0x00000000, 0x3F666666, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.699999988079071f;
}
static const u32 fzgx_pool_table20[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table22[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
}
#pragma section code_type ".text"
int fn_1_61D08(obj)
fn_1_61D08_EffectObject *obj;
{
    u8 *data;
    EffectChild *child;
    u32 size;
    u32 random;
    f32 initial;
    f32 value;

    data = (u8 *)(((u8 *)&lbl_1_data_1C698));
    obj->unk_38 = (void *)fn_1_45D0(lbl_801A6410, 0x24, data + 0xf94, 0x17a6);
    child = (EffectChild *)obj->unk_38;
    size = GXGetTexBufferSize(0x14, 0xe, 0, 0, 0);
    child->unk_20 = (void *)fn_1_45D0(lbl_801A6410, size, data + 0xf94, 0x17ab);

    initial = 30.0f;
    *(f32 *)(data + 0x120c) = initial;
    obj->unk_10 = (s32)initial;
    obj->unk_b4 = 0.3f;

    random = ((0x41c64e6d) * (*(u32 *)(data + 0xf90))) + 0x3039;
    *(u32 *)(data + 0xf90) = random;
    obj->unk_54 = (u16)((random >> 16) & 0x7fff);

    random = ((0x41c64e6d) * (*(u32 *)(data + 0xf90))) + 0x3039;
    *(u32 *)(data + 0xf90) = random;
    value = (f32)((random >> 16) & 0x7fff);
    obj->unk_5a = (s16)(4096.0f * (value / 32767.0f - 0.5f));

    obj->unk_34 = ((EffectInner *)(u8 *)lbl_1_bss_38458->unk_8)->unk_130;
    return 1;
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_61D08 */

/* fzgx:begin fn_1_61E60 */
// Releases the effect resources and clears the active effect references.
int fn_1_61E60(object)
Fn1_61E60Object *object;
{
    Fn1_61E60Node *node = object->unk_38;

    if (node != 0) {
        fn_1_4730( (u32)(void *)(lbl_801A6410), (u32)(void *)(node->unk_20), 1, (const char *)(u8 *)(lbl_1_data_1D62C), 0x17D5);
        node->unk_20 = 0;
        fn_1_46B4((u32)lbl_801A6410, (u32)(void *)(object->unk_38), (const char *)(u8 *)(lbl_1_data_1D62C), 0x17D8);
        object->unk_38 = 0;
    }

    return 1;
}
/* fzgx:end fn_1_61E60 */

/* fzgx:begin fn_1_620C4 */
// fn_1_620C4: empty in retail (single blr).
void fn_1_620C4(void) {
}
/* fzgx:end fn_1_620C4 */

/* fzgx:begin fn_1_620C8 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
}
#pragma section code_type ".text"

typedef struct Sig_GXInitTexObj__GXTexObj {
    u32 dummy[8];
} Sig_GXInitTexObj_GXTexObj;

struct fn_1_620C8_lbl_1_rodata_2950 {
    u8 pad_0[0x28];
    f32 unk_28;
    u8 pad_2C[0xC];
    f64 unk_38;
    u8 pad_40[0x10];
    f32 unk_50;
    u8 pad_54[0x24];
    f32 unk_78;
    u8 pad_7C[0x248];
    f32 unk_2C4;
};

extern s32 fn_1_54E34(void *, f32);
extern struct fn_1_620C8_lbl_1_rodata_2950 lbl_1_rodata_2950;
extern void fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern void fn_80074188(s32, s32, s32, s32);
extern void lbl_8006DA50(void);
extern void GXInitTexObj(Sig_GXInitTexObj_GXTexObj *, void *, u16, u16, s32, s32, s32, u8);
extern void fn_1_556B8(void *);
extern void fn_1_56000(u8, u8, u8);
extern void fn_1_5621C(f32, f32, f32, f32);
extern void fn_80038F10(f32 *);
extern void fn_80072558(void);
extern void fn_80074300(u16, u16, u16, u16);
extern void fn_80074438(u16, u16, s32, s32);
extern void fn_80074918(s32, s32, s32);
extern void lbl_8006DFE8(void *);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E14C(f32);
extern void mathutil_mtxA_rotate_x(s32);
extern void fn_8003526C(void *, u8);

void fn_1_620C8(void *arg0)
{
    struct fn_1_620C8_lbl_1_rodata_2950 *p = (struct fn_1_620C8_lbl_1_rodata_2950 *)&lbl_1_rodata_2950;
    s32 w;
    s32 h;
    s32 hw;
    s32 hh;
    void *tex = *(void **)((u8 *)arg0 + 0x38);
    void *obj;
    f32 col;
    f32 one;
    f32 vp[6];

    fn_80038F10(vp);
    w = (s32)((vp[2] < 40.0f) ? vp[2] : 40.0f);
    h = (s32)((vp[3] < 28.0f) ? vp[3] : 28.0f);
    hw = w >> 1;
    hh = h >> 1;
    fn_80038EEC(vp[0], vp[1], (f32)w, (f32)h, 0.0f, 1.0f);
    fn_80074188((s32)vp[0], (s32)vp[1], w, h);
    col = *(f32 *)((u8 *)arg0 + 0xB4);
    obj = *(void **)((u8 *)arg0 + 0x34);
    lbl_8006DFE8((u8 *)arg0 + 0xB8);
    lbl_8006DA50();
    lbl_8006E0A4((u8 *)arg0 + 0x3C);
    lbl_8006E14C(*(f32 *)((u8 *)arg0 + 0x28) / *(f32 *)((u8 *)obj + 0x14));
    mathutil_mtxA_rotate_x(-0x8000);
    if (fn_1_54E34((u8 *)obj + 8, *(f32 *)((u8 *)arg0 + 0x28)) != 0) {
        fn_1_56000(1, 3, 0);
        fn_1_5621C(col, col, col, 1.0f);
        fn_80072558();
        fn_1_556B8(obj);
        fn_1_56000(1, 3, 1);
        fn_1_5621C(1.0f, 1.0f, 1.0f, 1.0f);
    }
    fn_80074918(1, 3, 1);
    fn_80074300((s32)vp[0], (s32)vp[1], w, h);
    fn_80074438(hw, hh, 0, 1);
    fn_8003526C(*(void **)((u8 *)tex + 0x20), 1);
    GXInitTexObj((Sig_GXInitTexObj_GXTexObj *)tex, *(void **)((u8 *)tex + 0x20), hw, hh, 0, 0, 0, 0);
    fn_80038EEC(vp[0], vp[1], vp[2], vp[3], vp[4], vp[5]);
    fn_80074188((s32)vp[0], (s32)vp[1], (s32)vp[2], (s32)vp[3]);
}
/* fzgx:end fn_1_620C8 */

/* fzgx:begin fn_1_62794 noprologue */
#include "types.h"

typedef struct { u32 dummy[8]; } TexObj62794;

struct fn_1_62794_pool {
    u8 pad_0[0x50];
    f32 unk_50;
    f32 unk_54;
    u8 pad_58[0x154];
    f32 unk_1AC;
};

extern struct fn_1_62794_pool lbl_1_rodata_2950;
extern f32 *lbl_801A6D00;
extern void *lbl_801A63D0;
extern void GXLoadTexMtxImm(f32 *, u32, u32);
extern void fn_800720B0(u32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DFD8(void *);
extern void GXInitTexObj(TexObj62794 *, void *, u16, u16, s32, s32, s32, u8);
extern void fn_8003526C(void *, u8);
extern void fn_80038BFC(f32 *);
extern void fn_80038F10(f32 *);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073778(void *, s32);
extern void fn_80073898(u32);
extern void fn_800738E0(s32, s32, s32);
extern void fn_80073A58(int, void *, s8);
extern void fn_80074300(u16, u16, u16, u16);
extern void fn_80074438(u16, u16, u32, u32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8, s32, u8);
extern void fn_80073B50(u32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void lbl_8006D758(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DB74(void *);

#pragma opt_lifetimes off
void fn_1_62794(void *arg0) {
    struct fn_1_62794_pool *pool;
    s32 w;
    s32 h;
    void *buf;
    f32 half;
    f32 zero;
    u32 loc_7C[12];
    TexObj62794 loc_5C;
    f32 loc_44[6];
    f32 loc_28[7];
    f32 loc_10[6];

    pool = (struct fn_1_62794_pool *)&lbl_1_rodata_2950;
    buf = lbl_801A63D0;
    fn_80038F10(loc_44);
    w = (s32)((2)[loc_44]) >> 1;
    h = (s32)((3)[loc_44]) >> 1;
    fn_80074300((s32)((0)[loc_44]), (s32)((1)[loc_44]), (s32)((2)[loc_44]), (s32)((3)[loc_44]));
    fn_80074438(w, h, 4, 1);
    fn_8003526C(buf, 0);
    GXInitTexObj(&loc_5C, buf, w, h, 4, 0, 0, 0);
    fn_80072864(0);
    fn_80038BFC(loc_28);
    lbl_8006DAEC();
    lbl_8006DAEC();
    lbl_8006D758();
    {
        f32 hh = pool->unk_1AC;
        f32 t = hh * ((1)[loc_28]);
        hh = pool->unk_54;
        lbl_801A6D00[0] = t;
        lbl_801A6D00[2] = hh + (f32)(hh * ((2)[loc_28]));
        lbl_801A6D00[5] = hh * ((3)[loc_28]);
        lbl_801A6D00[6] = hh + (f32)(hh * ((4)[loc_28]));
    }
    lbl_8006DB74(loc_7C);
    lbl_8006DB30();
    lbl_8006DFD8(loc_7C);
    GXLoadTexMtxImm(lbl_801A6D00, 30, 0);
    lbl_8006DB30();
    zero = pool->unk_50;
    half = pool->unk_54;
    loc_10[0] = zero;
    loc_10[1] = half;
    loc_10[2] = zero;
    loc_10[3] = half;
    loc_10[4] = zero;
    loc_10[5] = zero;
    fn_80073A58(1, loc_10, 0);
    fn_80074788(1);
    fn_800747D0(0, 0, 0, 0, 0, 0, 2);
    fn_800747D0(2, 0, 0, 1, 0, 0, 2);
    fn_80073778(&loc_5C, 0);
    fn_80073778(arg0, 1);
    fn_800745A4(0, 0, 0, 30, 0, 125);
    fn_800734A8(0, 0, 0, 4);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 15, 15, 15, 8);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 5);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80074918(1, 7, 0);
    fn_800720B0(0);
    fn_800728A8(1, 4, 1, 0);
    fn_800745A4(1, 0, 0, 30, 0, 125);
    fn_800738E0(0, 1, 1);
    fn_80073B50(0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    fn_80073678(1);
    fn_80074660(2);
    fn_80073898(1);
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_62794 */

/* fzgx:begin fn_1_62AF8 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const u32 fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
}
#pragma section code_type ".text"

extern const f32 lbl_1_rodata_2950;
extern u32 lbl_1_data_1D628;

struct fn_1_62AF8_obj {
    u8 pad_00[0x0E];
    s16 unk_0E;
    s32 unk_10;
    u8 pad_14[0x14];
    f32 unk_28;
    u8 pad_2C[0x28];
    u16 unk_54;
    u16 unk_56;
    u16 unk_58;
};

void fn_1_62AF8(struct fn_1_62AF8_obj *obj) {
    u32 random;

    if (obj->unk_10 == 0) {
        u32 r15;
        f32 ratio;

        random = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        lbl_1_data_1D628 = random;
        r15 = (random >> 16) & 0x7FFF;
        ratio = (f32)r15 / 32767.0f;
        obj->unk_10 = (s32)(30.0 + 60.0f * ratio);
    }

    obj->unk_0E = 0;
    if (0.0f == obj->unk_28) {
        u16 r15a;
        u16 r15b;
        f32 qa;
        f32 qb;
        f64 da;
        f64 db;

        r15a = (lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 0x3039) >> 16 & 0x7FFF;
        qa = (f32)r15a / 32767.0f;

        r15b = (lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 0x3039) >> 16 & 0x7FFF;
        qb = (f32)r15b / 32767.0f;

        da = 0.02 * qa;
        db = 0.5 * qb;
        obj->unk_28 = (f32)((5.0f * (f32)(0.02 + da)) * (0.5 + db));
    }

    random = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
    lbl_1_data_1D628 = random;
    obj->unk_54 = (random >> 16) & 0x7FFF;
    random = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
    lbl_1_data_1D628 = random;
    obj->unk_56 = (random >> 16) & 0x7FFF;
    random = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
    lbl_1_data_1D628 = random;
    obj->unk_58 = (random >> 16) & 0x7FFF;
}
/* fzgx:end fn_1_62AF8 */

/* fzgx:begin fn_1_6312C */
// fn_1_6312C: empty in retail (single blr).
void fn_1_6312C(void) {
}
/* fzgx:end fn_1_6312C */

/* fzgx:begin fn_1_63130 */
struct fn_1_63130_obj {
    u8 unk_00[0xAE];
    s16 unk_AE;
};

void fn_1_63130(struct fn_1_63130_obj *obj) {
    obj->unk_AE = 0;
}
/* fzgx:end fn_1_63130 */

/* fzgx:begin fn_1_6313C noprologue */
typedef unsigned char u8;
typedef signed short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const unsigned long fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const unsigned long fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
#pragma section code_type ".text"


typedef struct Fx {
    u8 state;
    u8 pad1[0xF];
    s32 unk10;
    u8 pad14[8];
    f32 unk1c, unk20, unk24, unk28, unk2c;
    u8 pad30[0xC];
    f32 unk3c, unk40, unk44, unk48, unk4c, unk50;
    u8 pad54[0x34];
    f32 unk88, unk8c;
    u8 pad90[0x1C];
    s16 unkac, unkae;
} Fx;

extern s32 lbl_1_bss_6C860;
extern s32 fn_1_66B8(void *, f32);

#pragma opt_propagation off
#pragma opt_common_subs off
void fn_1_6313C(Fx *p) {
    f32 v;
    f32 w;
    f32 t;
    f32 g;
    p->state = 2;
    lbl_1_bss_6C860 = lbl_1_bss_6C860 + 1;
    if (lbl_1_bss_6C860 > 150) {
        p->state = 3;
    }
    if (fn_1_66B8(&p->unk3c, p->unk28) == 0) {
        p->state = 3;
    }
    t = 1.0f - p->unk88;
    p->unk48 *= t;
    v = p->unk4c;
    p->unk4c = v * t;
    p->unk50 *= t;
    p->unk4c += -0.08f;
    p->unk48 += 0.001f;
    p->unk3c += p->unk48;
    p->unk40 += p->unk4c;
    p->unk44 += p->unk50;
    p->unk88 = p->unk88 + (f32)(0.05f * (p->unk8c - p->unk88));
    p->unk28 = p->unk28 + (f32)(0.01f * (p->unk2c - p->unk28));
    p->unkae += p->unkac;
    g = 1.0f - 1.0f / (f32)(p->unk10 + 1);
    w = p->unk1c;
    p->unk1c = w * g;
    p->unk20 *= g;
    p->unk24 *= g;
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
/* fzgx:end fn_1_6313C */

/* fzgx:begin fn_1_632D4 */
struct fn_1_632D4_obj {
    u8 unk_00[0x1C];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 unk_2C[0x8];
    int unk_34;
    u8 unk_38[0x4];
    void *unk_3C;
    u8 unk_40[0x6E];
    s16 unk_AE;
};

struct fn_1_632D4_data {
    f32 unk_00;
    f32 unk_04;
    u8 unk_08[0x34];
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
};

void fn_1_632D4(struct fn_1_632D4_obj *obj) {
    struct fn_1_632D4_value { s32 a, b, c; } value;
    struct fn_1_632D4_data data;
    int id;
    s32 red;
    s32 green;
    s32 blue;
    f32 color_scale;
    f32 size;

    id = obj->unk_34;
    lbl_8006DCA4(obj);
    lbl_8006E1B0(&obj->unk_3C, &value);
    lbl_8006D7DC(&value);
    mathutil_mtxA_rotate_z(obj->unk_AE);
    memset(&data, 0, 0x40);
    lbl_8006DB74(&data.unk_08);

    size = (((f32 *)&lbl_1_rodata_2AA0))[0];
    size = size * obj->unk_28;
    data.unk_00 = size;
    color_scale = lbl_1_rodata_29AC[0];
    red = color_scale * obj->unk_1C;
    data.red = red;
    green = color_scale * obj->unk_20;
    data.green = green;
    blue = color_scale * obj->unk_24;
    data.alpha = 0xff;
    data.unk_04 = size;
    data.blue = blue;

    fn_1_9F914(&data, (const void *)(int)(id));
}
/* fzgx:end fn_1_632D4 */

/* fzgx:begin fn_1_633BC */
// fn_1_633BC: empty in retail (single blr).
void fn_1_633BC(void) {
}
/* fzgx:end fn_1_633BC */

/* fzgx:begin fn_1_633C0 noprologue */
#include "rel/main_rel/effect.h"

typedef struct { f32 x, y, z; } FxVec;
typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[4];
    s16 unk18;
    u8 pad1A[0x3c - 0x1a];
    FxVec unk3c;
    u8 pad48[0x60 - 0x48];
    FxVec unk60;
    u8 pad6c[0x94 - 0x6c];
    FxVec unk94;
} FxObj633C0;

extern void fn_1_862D4(int, void *);
extern void fn_1_8645C(int, void *);
extern void *lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);


/* Establish the native shared literal pool in retail order. */
#pragma section code_type ".fzgxpool"
/* Volatile output preserves the native shared literal-pool priming stores. */
void fzgx_pool_primer_fn_1_633C0(volatile f32 *f, volatile f64 *d) {
    f[0] = 60.0f;
    f[1] = 0.1f;
    f[2] = 32767.0f;
    f[3] = 0.05f;
    d[0] = 0.07;
    f[4] = 20000.0f;
    d[1] = 4503599627370496.0;
    f[5] = 1.0f;
    f[6] = -0.03f;
    d[2] = 15.0;
    d[3] = 4503601774854144.0;
    d[4] = 1.5;
    d[5] = 0.5;
    f[7] = 0.0f;
    f[8] = 0.5f;
    f[9] = 8.0f;
    f[10] = 255.0f;
    f[11] = 15.0f;
    f[12] = 0.2f;
}
#pragma section code_type ".text"

#pragma section code_type ".fzgxpool"
void fzgx_pool_tail_fn_1_633C0(void (*use)(void *)) {
    /* Raw IEEE-754 pool words, including padding, not pointer addresses. */
    u32 words[] = {
        1034147594U, 1048576000U, 1065017672U, 1065185444U,
        1109393408U, 1101004800U, 1069547520U, 1055286886U,
        3221225472U, 1034594987U, 1041865114U, 1040187392U,
        3201092813U, 3197737370U, 1073741824U, 1132068864U,
        1071854387U, 858993459U, 1071225241U, 2576980378U,
        1050253722U, 3145929327U, 1015580809U, 1199570944U,
        1166016512U, 1064682127U, 1053609165U, 1028577559U,
        1028711776U, 1064514355U, 1063675494U, 0U,
        1080213504U, 0U, 1076101120U, 0U,
        1074266112U, 0U, 0U, 1036831949U,
        3222903194U, 1084227584U, 1072902963U, 858993459U,
        1069128089U, 2576980378U, 1092616192U, 1099956224U,
        1072064102U, 1717986918U, 1078525952U, 0U,
        0U, 1036831949U, 3222903194U, 1100480512U,
        1077411840U, 0U, 1060439283U, 0U,
        0U, 0U, 1081073664U, 0U,
        1072483532U, 3435973837U, 998445679U, 981668463U,
        1008981770U, 3019898880U, 1131413504U, 1120403456U,
        1133903872U, 1128792064U, 1176256512U, 1167867904U,
        1129054208U, 1118437376U, 3175926989U, 1082130432U,
        3178611343U, 3204448256U, 3212836864U, 0U,
        1070176665U, 2576980378U, 1140850688U, 1022739087U,
        1112276992U, 1118830592U, 3221749760U, 0U,
        1083179008U, 1086324736U, 1066192077U, 0U,
        1063675494U, 3213675725U, 0U, 1063675494U,
        0U, 0U, 3207803699U, 0U,
        0U, 0U, 1067030938U, 1112014848U,
        1020054733U, 1061997773U, 1031798784U, 1075838976U,
        0U, 0U, 0U, 0U,
        0U, 0U, 3225419776U, 0U,
        1065646817U, 1202590843U, 1072567419U, 0U,
        1080705024U, 0U, 1066695393U, 1202590843U,
        1063818100U, 3161095930U, 3219547750U, 1610612736U,
        3214850129U, 3758096384U, 1069681737U, 3126736191U,
        1072064102U, 1610612736U, 1072693248U, 0U,
        1070805811U, 858993459U, 1072273817U, 2684354560U,
        1076363264U, 0U, 3211159142U, 1032805417U,
        1058642330U, 1106247680U, 1065856532U, 1105199104U,
        1075052544U, 0U, 1080033280U, 1127481344U,
        4294967295U, 4294967295U, 1077805056U, 0U,
        1067366481U, 3951369912U, 1064346583U, 3181631242U,
    };
    use(words);
}
#pragma section code_type ".text"

#pragma opt_propagation off
void fn_1_633C0(FxObj633C0 *obj) {
    FxVec b[4];
    FxVec a;
    FxVec d;

    if (obj->unk10 == 0) {
        u32 r;
        r = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        lbl_1_data_1D628 = r;
        obj->unk10 = (s32)(60.0f * (0.2f + (f32)((0.2f * ((f32)((r >> 16) & 0x7FFF) / 32767.0f)))));
    }
    fn_1_862D4(obj->unk18, &a);
    fn_1_8645C(obj->unk18, &b);
    lbl_8006DC6C(&b);
    {
        f32 fzgx_lc0_z;
        f32 fzgx_lc0_y;
        f32 fzgx_lc0_x;
        fzgx_lc0_x = a.x;
        fzgx_lc0_y = a.y;
        fzgx_lc0_z = a.z;
        *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc0_x;
        *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc0_y;
        *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc0_z;
    }
    {
    FxVec c = {0.0f, 0.0f, 0.0f};
    c.x = obj->unk94.x;
    c.y = obj->unk94.y;
    c.z = obj->unk94.z;
    d = c;
    }
    lbl_8006E1B0(&d, &obj->unk3c);
    obj->unk60 = obj->unk3c;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_633C0 */

/* fzgx:begin fn_1_63514 */
// fn_1_63514: empty in retail (single blr).
void fn_1_63514(void) {
}
/* fzgx:end fn_1_63514 */

/* fzgx:begin fn_1_63518 */
typedef struct Effect_63518_vec {
    u32 x;
    u32 y;
    u32 z;
} Effect_63518_vec;

typedef struct Effect_63518 {
    u8 unk00[0x14];
    u32 unk14;
    u8 unk18[0x20];
    Effect_63518_vec *unk38;
    Effect_63518_vec unk3c;
    u8 unk48[0x10];
    u16 unk58;
    u8 unk5a[0x06];
    Effect_63518_vec unk60;
    u8 unk6c[0x40];
    u16 unkac;
    u16 unkae;
    u16 unkb0;
} Effect_63518;

void fn_1_63518(Effect_63518 *effect) {
    Effect_63518_vec *dst;
    u32 i;

    effect->unk14 = 0;
    effect->unkac = 0;
    effect->unkae = 0;
    effect->unkb0 = 0;
    effect->unk58 = 0;

    effect->unk60 = effect->unk3c;
    dst = effect->unk38;

    for (i = 0; i < fn_1_58C4() * 8; i++) {
        *dst++ = effect->unk3c;
    }
}
/* fzgx:end fn_1_63518 */

/* fzgx:begin fn_1_63858 */
struct LocalData {
    u8 data[0x10];
};

struct fn_1_63858_Event {
    u8 data[4];
    void (*callback)(void);
    void *owner;
};

struct fn_1_63858_Object {
    u8 data[0x18];
    s16 value;
};

void fn_1_63858(struct fn_1_63858_Object *object) {
    struct LocalData local;
    struct fn_1_63858_Event *event;
    void *target;

    fn_1_862D4(object->value, &local);
    lbl_8006DCA4();
    if (fn_1_54E34(&local, lbl_1_rodata_2B2C[0]) != 0) {
        target = fn_1_5448C(&local);
        event = (struct fn_1_63858_Event *)fn_1_548AC(0xc);
        if (event != 0) {
            event->callback = fn_1_638E8;
            event->owner = object;
            fn_1_5489C( (void **)(void *)(target), (void **)(void *)(event));
        }
    }
}
/* fzgx:end fn_1_63858 */

/* fzgx:begin fn_1_64098 */
typedef struct Fn164098Object {
    u8 pad[0xae];
    u16 value;
} Fn164098Object;

void fn_1_64098(Fn164098Object *object) {
    object->value = 0;
}
/* fzgx:end fn_1_64098 */

/* fzgx:begin fn_1_640A4 noprologue */
#include "types.h"
#include "rel/main_rel/effect.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const u32 fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
static const u32 fzgx_pool_table24[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.00800000037997961f;
    s = 0.004545454401522875f;
    s = 0.014285714365541935f;
}
#pragma section code_type ".text"

struct fn_1_640A4_lbl_1_rodata_2950 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x18];
    f32 unk_28;
    u8 pad_2C[0xC];
    f64 unk_38;
    u8 pad_40[0x130];
    f32 unk_170;
    f32 unk_174;
    f32 unk_178;
    u8 pad_17C[0x98];
    f32 unk_214;
    u8 pad_218[0xFC];
    f32 unk_314;
    f32 unk_318;
    f32 unk_31C;
};
extern struct fn_1_640A4_lbl_1_rodata_2950 lbl_1_rodata_2950;
extern s32 fn_1_66B8(void *, f32);

void fn_1_640A4(u8 *arg0) {
    struct fn_1_640A4_lbl_1_rodata_2950 *r = &lbl_1_rodata_2950;
    u8 *o = arg0;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 var_f1;
    s32 temp_r0;

    o[0] = 2;
    temp_r0 = lbl_1_bss_6C860 + 1;
    lbl_1_bss_6C860 = (u32) temp_r0;
    if (temp_r0 > 0x96) {
        o[0] = 3;
    }
    if (fn_1_66B8(o + 0x3c, *(f32 *)(o + 0x28)) == 0) {
        o[0] = 3;
    }
    temp_f2 = (1.0f) - *(f32 *)(o + 0x88);
    *(f32 *)(o + 0x48) = *(f32 *)(o + 0x48) * temp_f2;
    *(f32 *)(o + 0x4c) = *(f32 *)(o + 0x4c) * temp_f2;
    *(f32 *)(o + 0x50) = *(f32 *)(o + 0x50) * temp_f2;
    *(s16 *)(o + 0xac) = (s16) ((f32) (*(s16 *)(o + 0xac)) * temp_f2);
    if (!(((u32) (*(u32 *)(o + 8)) >> 0x11U) & 1)) {
        *(f32 *)(o + 0x4c) += (0.00800000038f);
    } else {
        *(f32 *)(o + 0x4c) += (0.00400000019f);
    }
    temp_f1 = (0.00100000005f);
    temp_f2 = (0.0500000007f);
    temp_f3 = (0.00999999978f);
    *(f32 *)(o + 0x48) = *(f32 *)(o + 0x48) + temp_f1;
    *(f32 *)(o + 0x3c) = *(f32 *)(o + 0x3c) + *(f32 *)(o + 0x48);
    *(f32 *)(o + 0x40) = *(f32 *)(o + 0x40) + *(f32 *)(o + 0x4c);
    *(f32 *)(o + 0x44) = *(f32 *)(o + 0x44) + *(f32 *)(o + 0x50);
    *(s16 *)(o + 0xae) = (s16) ((*(s16 *)(o + 0xae)) + (*(s16 *)(o + 0xac)));
    temp_f4 = *(f32 *)(o + 0x88);
    temp_f0 = temp_f2 * (*(f32 *)(o + 0x8c) - temp_f4);
    *(f32 *)(o + 0x88) = temp_f4 + temp_f0;
    temp_f4 = *(f32 *)(o + 0x28);
    temp_f0 = temp_f3 * (*(f32 *)(o + 0x2c) - temp_f4);
    *(f32 *)(o + 0x28) = temp_f4 + temp_f0;
    if (*(f32 *)(o + 0x2c) > (50.0f)) {
        temp_r0 = *(s32 *)(o + 0x10);
        if (temp_r0 < 0xDC) {
            var_f1 = (f32) temp_r0;
            var_f1 = (0.0045454544f) * var_f1;
        } else {
            var_f1 = (1.0f);
        }
    } else {
        temp_r0 = *(s32 *)(o + 0x10);
        if (temp_r0 < 0x46) {
            var_f1 = (f32) temp_r0;
            var_f1 = (0.0142857144f) * var_f1;
        } else {
            var_f1 = (1.0f);
        }
    }
    *(f32 *)(o + 0x1c) = *(f32 *)(o + 0x1c) * var_f1;
    *(f32 *)(o + 0x20) = *(f32 *)(o + 0x20) * var_f1;
    *(f32 *)(o + 0x24) = *(f32 *)(o + 0x24) * var_f1;
}
/* fzgx:end fn_1_640A4 */

/* fzgx:begin fn_1_642E8 */
typedef struct fn_1_642E8_EffectState {
    char bytes[0x14];
} fn_1_642E8_EffectState;

typedef struct fn_1_642E8_EffectObject {
    char pad0[0x28];
    f32 value;
    char pad2c[0x10];
    fn_1_642E8_EffectState state;
} fn_1_642E8_EffectObject;

typedef struct EffectNode {
    char pad0[4];
    void (*callback)(void);
    void *owner;
} EffectNode;

void fn_1_642E8(fn_1_642E8_EffectObject *self) {
    f32 value;
    void *state;
    EffectNode *node;

    value = self->value / lbl_1_rodata_2A70[0];
    lbl_8006DCA4();
    if (fn_1_54E34(&self->state, value)) {
        state = fn_1_5448C(&self->state);
        node = fn_1_548AC(0xc);
        if (node != 0) {
            node->callback = fn_1_64388;
            node->owner = self;
            fn_1_5489C( (void **)(void *)(state), (void **)(void *)(node));
        }
    }
}
/* fzgx:end fn_1_642E8 */

/* fzgx:begin fn_1_64388 noprologue */
#include "dolphin/types.h"
#include "psvec.h"
#include "rel/main_rel/effect.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const u32 fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
static const u32 fzgx_pool_table24[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.00800000037997961f;
    s = 0.004545454401522875f;
    s = 0.014285714365541935f;
    s = 2000.0f;
    s = 1000.0f;
    s = 2.0999999046325684f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"
typedef struct { f32 x,y,z; } Vec3;
typedef struct { f32 m[12]; } Mtx;
typedef struct { u8 pad[0x14]; f32 f14; } NodeObj;
typedef struct {
 u8 pad0[0x10]; s32 age;
 u8 pad14[8]; f32 x,y,z,size;
 u8 pad2c[8]; NodeObj *node;
 u8 pad38[4]; Vec3 pos;
 u8 pad48[0x66]; s16 angle;
} SelfObj;
typedef struct { u8 pad[8]; SelfObj *obj; } ArgObj;
extern void lbl_8006DCA4(void *);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006D7DC(void *);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void mathutil_mtxA_rotate_z(s16);
extern void lbl_8006E14C(f32);
extern f32 fn_1_A71AC(void);
extern void fn_1_55FC4(f32);
extern void fn_1_56000(u8,u8,u8);
extern void fn_1_5621C(f32,f32,f32,f32);
extern void fn_1_556B8(void *);
extern void fn_80072558(void);
#pragma fp_contract on
static inline f32 fn_1_64388_read_pointer(SelfObj * owner) { return owner->size; }
#pragma opt_common_subs off
static inline f32 fn_1_64388_read_pointer_(Vec3 * owner) { return owner->y; }
#pragma opt_dead_assignments off
void fn_1_64388(ArgObj *arg0) {
 SelfObj *obj;
 NodeObj *node;
 Vec3 pos;
 Vec3 dir;
 Mtx mtx;
 f32 scale;
 f32 alpha;
 f32 ratio;
 f32 len;
 obj=arg0->obj;
 lbl_8006DCA4(arg0);
 lbl_8006E1B0(&obj->pos,&pos);
 scale=fn_1_64388_read_pointer(obj)/10.0f;
 node=obj->node;
 if(pos.z > -1.1920928955078125e-7f) return;
 ratio=fn_1_A71AC();
 ratio=(240.0f*((2.0f*node->f14)*scale))/(-pos.z*ratio);
 alpha=1.0f;
 if(ratio<10.0f) return;
 if(ratio<20.0f) alpha*= (ratio-10.0f)/10.0f;
 if(ratio>2000.0f) return;
 if(ratio>1000.0f) alpha*=1.0f-(ratio-1000.0f)/1000.0f;
 lbl_8006D7DC(&pos);
 psvec_set(&dir,*(f32 *)(0xE0000000+0x2C),*(f32 *)(0xE0000000+0x1C),*(f32 *)(0xE0000000+0x0C));
 len=dir.x;
 len*=len;
 len+=fn_1_64388_read_pointer_(&dir)*fn_1_64388_read_pointer_(&dir);
 len+=dir.z*dir.z;
 len=lbl_8006D0B4(len);
 if(len>2.1f) {
 lbl_8006DB74(&mtx);
 lbl_8006D848((len-2.0f)/len);
 lbl_8006DFC4(&mtx);
 }
 mathutil_mtxA_rotate_z(obj->angle);
 lbl_8006E14C(scale);
 fn_1_55FC4(scale);
 fn_1_56000(1,3,0);
 fn_80072558();
 fn_1_5621C(obj->x,obj->y,obj->z,obj->age<60 ? (0.01666666753590107f*obj->age)*alpha : alpha);
 fn_1_556B8(node);
 fn_1_56000(1,3,1);
 fn_1_5621C(1.0f,1.0f,1.0f,1.0f);
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_64388 */

/* fzgx:begin fn_1_645C8 */
// fn_1_645C8: empty in retail (single blr).
void fn_1_645C8(void) {
}
/* fzgx:end fn_1_645C8 */

/* fzgx:begin fn_1_645CC */
// fn_1_645CC: empty in retail (single blr).
void fn_1_645CC(void) {
}
/* fzgx:end fn_1_645CC */

/* fzgx:begin fn_1_645D0 */
// fn_1_645D0: empty in retail (single blr).
void fn_1_645D0(void) {
}
/* fzgx:end fn_1_645D0 */

/* fzgx:begin fn_1_645D4 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const unsigned long fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const unsigned long fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
static const unsigned long fzgx_pool_table24[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const unsigned long *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.00800000037997961f;
    s = 0.004545454401522875f;
    s = 0.014285714365541935f;
    s = 2000.0f;
    s = 1000.0f;
    s = 2.0999999046325684f;
}
#pragma section code_type ".text"

typedef struct { f32 x, y, z; } V3;
struct A { u8 pad_0[0x18]; s16 unk_18; };
extern u32 lbl_801A63C0;
extern void fn_1_862D4(int, V3 *);
extern void fn_1_8636C(int, void *);
extern void lbl_8006D5A4(void *, void *, void *, f32);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);

#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_645D4(struct A *arg0) {
    V3 pos;
    V3 rnd2;
    u8 mtx[0x30];
    fn_1_862D4(arg0->unk_18, &pos);
    fn_1_8636C(arg0->unk_18, mtx);
{
    V3 rnd = {0.0f, 0.0f, 0.0f};
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    rnd.x = 0.2 * ((f32)(s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f);
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    rnd.y = 0.2 * ((f32)(s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f);
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    rnd.z = 0.2 * ((f32)(s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f);
    rnd2 = rnd;
}
    lbl_8006D5A4((u8 *)arg0 + 0x94, &rnd2, (u8 *)arg0 + 0x94, 0.05f);
    lbl_8006DC6C(mtx);
    {
        f32 fzgx_lc0_z;
        f32 fzgx_lc0_y;
        f32 fzgx_lc0_x;
        fzgx_lc0_x = pos.x;
        fzgx_lc0_y = pos.y;
        fzgx_lc0_z = pos.z;
        *(f32 *)(0xE0000000 + 0x0C) = fzgx_lc0_x;
        *(f32 *)(0xE0000000 + 0x1C) = fzgx_lc0_y;
        *(f32 *)(0xE0000000 + 0x2C) = fzgx_lc0_z;
    }
    lbl_8006E1B0((u8 *)arg0 + 0x94, (u8 *)arg0 + 0x3c);
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
/* fzgx:end fn_1_645D4 */

/* fzgx:begin fn_1_64760 noprologue */
#include "dolphin/hw_regs.h"
#include "psvec.h"

typedef unsigned char u8;

typedef unsigned long u32;

typedef float f32;
typedef double f64;

extern const f32 lbl_1_rodata_2950[];
extern void lbl_8006D9D8(void *);
extern void lbl_8006D7B0(void);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void fn_1_9F914(void *, u32);
extern void *memset(void *, int, u32);
/* Fixed engine address; three floats at 0xc, 0x1c, 0x2c. */
struct Fn15D718 {
	u8 _pad00[0x1c];
	f32 value1c;
	f32 value20;
	f32 value24;
	f32 value28;
	u8 _pad2c[0x08];
	u32 object34;
	u8 _pad38[0x04];
	f32 value3c;
};
struct Fn15D718Tmp {
	u8 data[0x30];
};
struct Fn15D718Sub {
	u8 data[0x34];
};
struct Fn15D718Work {
	f32 alpha;
	f32 alpha2;
	struct Fn15D718Sub sub;
	u8 red;
	u8 green;
	u8 blue;
	u8 alphaByte;
};
#pragma opt_propagation off
#pragma opt_common_subs off
static inline f32 fn_1_64760_array_read(f32 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments off
void fn_1_64760(struct Fn15D718 *self) {
struct Fn15D718Work work;
struct Fn15D718Tmp tmp;
u32 object;
f32 radius;
f32 distance;
f32 alpha;
const f32 *pool;
f32 v[3];
f32 x;
f32 y;
f32 z;
f32 sum;
f32 *m;
object = self->object34;
pool = lbl_1_rodata_2950;
radius = self->value28;
lbl_8006D9D8(&self->value3c);
lbl_8006D7B0();
m = (f32 *)(LC_BASE + 0x0);
x = fn_1_64760_array_read(m, 3);
y = fn_1_64760_array_read(m, 7);
z = fn_1_64760_array_read(m, 11);
psvec_set(v, z, y, x);
sum = (f32) (fn_1_64760_array_read(v, 0) * fn_1_64760_array_read(v, 0));
sum = sum + fn_1_64760_array_read(v, 1) * fn_1_64760_array_read(v, 1);
sum = sum + z * z;
distance = lbl_8006D0B4(sum);
if (distance > pool[1] + radius) {
lbl_8006DB74(&tmp);
lbl_8006D848((distance - radius) / distance);
lbl_8006DFC4(&tmp);
}
memset(&work, 0, 0x40);
lbl_8006DB74(&work.sub);
alpha = pool[0x150 / 4] * self->value28;
work.alpha = alpha;
work.red = (u8) (pool[0x5c / 4] * self->value1c);
work.green = (u8) (pool[0x5c / 4] * self->value20);
work.blue = (u8) (pool[0x5c / 4] * self->value24);
work.alphaByte = 0xff;
work.alpha2 = alpha;
fn_1_9F914(&work, object);
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

#pragma opt_propagation reset
/* fzgx:end fn_1_64760 */

/* fzgx:begin fn_1_648D4 */
// fn_1_648D4: empty in retail (single blr).
void fn_1_648D4(void) {
}
/* fzgx:end fn_1_648D4 */

/* fzgx:begin fn_1_648D8 */
// fn_1_648D8: empty in retail (single blr).
void fn_1_648D8(void) {
}
/* fzgx:end fn_1_648D8 */

/* fzgx:begin fn_1_64E1C noprologue */
#include "types.h"

extern f32 lbl_1_rodata_295C;
extern f32 lbl_1_rodata_2978;
extern const f64 lbl_1_rodata_2988;
extern u32 fn_1_55210(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern void fn_1_55FC4(f32);
extern void fn_1_55FF0(f32);
extern void fn_80072558(void);
extern void lbl_8006D9D8(u32);
extern void lbl_8006E14C(f32);
extern void mathutil_mtxA_rotate_y(u32);
extern void mathutil_mtxA_rotate_z(u32);

void fn_1_64E1C(void * arg0) {
    f32 v0;
    u32 v1;
    f32 v2;
    f32 v3;
    u32 v4;
    f32 v5;
    struct { f32 a[3]; } loc_8;
    v0 = *(f32 *)((u8 *)arg0 + 44);
    v1 = *(u32 *)((u8 *)arg0 + 52);
    loc_8.a[0] = (f32)(*(f32 *)((u8 *)arg0 + 60) + (f32)(v0 * *(f32 *)((u8 *)arg0 + 160)));
    loc_8.a[1] = (f32)(*(f32 *)((u8 *)arg0 + 64) + (f32)(v0 * *(f32 *)((u8 *)arg0 + 164)));
    v2 = *(f32 *)((u8 *)arg0 + 68);
    loc_8.a[2] = (f32)(v2 + (f32)(v0 * *(f32 *)((u8 *)arg0 + 168)));
    v3 = *(f32 *)((u8 *)arg0 + 40);
    lbl_8006D9D8((u32)&loc_8);
    mathutil_mtxA_rotate_y(*(s16 *)((u8 *)arg0 + 86));
    mathutil_mtxA_rotate_x(*(s16 *)((u8 *)arg0 + 84));
    mathutil_mtxA_rotate_z(*(s16 *)((u8 *)arg0 + 88));
    lbl_8006E14C(v3);
    fn_1_55FC4(v3);
    fn_80072558();
    v4 = *(u32 *)((u8 *)arg0 + 16);
    if ((s32)v4 < 20) {
        v5 = (f32)(lbl_1_rodata_295C * (f32)(s32)v4);
    } else {
        v5 = lbl_1_rodata_2978;
    }
    fn_1_55FF0(v5);
    fn_1_55210(v1);
}
/* fzgx:end fn_1_64E1C */

/* fzgx:begin fn_1_64F2C */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
}
#pragma section code_type ".text"

typedef struct {
    u8 pad_00[0x10];
    s32 unk_10;
} Fn_1_64F2C_Object;


void fn_1_64F2C(Fn_1_64F2C_Object *obj) {
    f32 random;
    f32 scaled;
    f32 offset;

    if (obj->unk_10 == 0) {
{
    u32 value;
        value = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        lbl_1_data_1D628 = value;
        random = (f32)((value >> 16) & 0x7fff) / 32767.0f;
}
        scaled = 0.25f * random;
        offset = 0.3f + scaled;
        obj->unk_10 = (s32)(60.0f * offset);
    }
}
/* fzgx:end fn_1_64F2C */

/* fzgx:begin fn_1_64FB8 noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const u32 fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
static const u32 fzgx_pool_table24[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.00800000037997961f;
    s = 0.004545454401522875f;
    s = 0.014285714365541935f;
    s = 2000.0f;
    s = 1000.0f;
    s = 2.0999999046325684f;
}
static const u32 fzgx_pool_table26[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04;
    d = 0.98;
    d = 0.96;
    d = 0.025;
    d = -1.0;
    d = 0.8;
}
static const u32 fzgx_pool_table28[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table29[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const u32 *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table30[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table31[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const u32 *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table32[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table33[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep33(void) { const u32 *volatile cp; cp = fzgx_pool_table33; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"
typedef struct { u32 x,y,z; } ClosureEffectWords;
typedef struct { f32 x,y,z; } ClosureEffectVec;
typedef struct { f32 values[12]; } ClosureEffectMatrix;
extern void *fn_1_86254(int);
extern void fn_1_862D4(int,void *);
extern void fn_1_8636C(int,void *);
extern s32 fn_1_6EC0(u8);
extern s16 camera_get_entry_field_0xa4(u32);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *,void *);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern u32 lbl_1_data_1D628;
#pragma fp_contract off
#pragma opt_propagation off
void fn_1_64FB8(void *arg0) {
    ClosureEffectMatrix matrix;
    ClosureEffectVec position;
    ClosureEffectWords offset;
    ClosureEffectWords displacement;
    ClosureEffectWords default_displacement;
    ClosureEffectWords default_offset;
    u8 *p=arg0;
    u8 *entry;
    f32 f9,gain,v0,v1,v2;
    u32 random;
    *(s16 *)(p+0x5a) *= (0.980000019f);
    *(s16 *)(p+0x5c) *= (0.980000019f);
    entry=fn_1_86254(*(s16 *)(p+0x18));
    fn_1_862D4(*(s16 *)(p+0x18),&position);
    fn_1_8636C(*(s16 *)(p+0x18),&matrix);
    lbl_8006DC6C(&matrix);
    {
        f32 *lc=(f32 *)LC_BASE; /* fzgx-allow: S2 locked-cache hardware storage */
        f32 z,y,x;
        x=position.x; y=position.y; z=position.z;
        lc[3]=x; lc[7]=y; lc[11]=z;
    }
    if((s8)entry[0x475] != -1 && fn_1_6EC0(entry[0x475]) && camera_get_entry_field_0xa4(entry[0x475])==0) {
        default_displacement.x=fzgx_pool_table28[0];
        default_displacement.y=fzgx_pool_table29[0];
        default_displacement.z=fzgx_pool_table30[0];
        *(f32 *)&default_displacement.z=(-3.0f);
        displacement=default_displacement;
        lbl_8006E1B0(&displacement,&displacement);
        { f32 *lc=(f32 *)LC_BASE; f32 z,y,x;
        x=*(f32 *)&displacement.x; y=*(f32 *)&displacement.y; z=*(f32 *)&displacement.z;
        lc[3]=x; lc[7]=y; lc[11]=z; }
    }
    *(s16 *)(p+0x54)+=*(s16 *)(p+0x5a);
    *(s16 *)(p+0x56)+=*(s16 *)(p+0x5c);
    mathutil_mtxA_rotate_y(*(s16 *)(p+0x56));
    mathutil_mtxA_rotate_x(*(s16 *)(p+0x54));
    default_offset.x=fzgx_pool_table31[0];
    default_offset.y=fzgx_pool_table32[0];
    default_offset.z=fzgx_pool_table33[0];
    *(f32 *)&default_offset.z=(f32)((0.5) * (f64)(-*(f32 *)(p+0x28)));
    offset=default_offset;
    lbl_8006E1B0(&offset,p+0x3c);
    *(f32 *)(p+0x28)=*(f32 *)(p+0x28)+(0.00999999978f)*(*(f32 *)(p+0x2c)-*(f32 *)(p+0x28));
    *(f32 *)(p+0xb4)=0.5f*(f32)*(s32 *)(p+0x10);
    random=lbl_1_data_1D628*1103515245u+12345u;
    lbl_1_data_1D628=random;
    gain=0.800000012f+0.200000003f*((f32)((random>>16)&0x7fffu)/32767.0f);
    *(f32 *)(p+0x1c)=(255.0f*(0.5f*(1.0f+gain)))/255.0f;
    {
        f32 spread=(136.0f*gain)/255.0f;
        *(f32 *)(p+0x20)=spread;
        *(f32 *)(p+0x24)=spread;
    }
}
#pragma opt_propagation reset
#pragma fp_contract reset
/* fzgx:end fn_1_64FB8 */

/* fzgx:begin fn_1_65268 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect.h"

extern void lbl_8006DCA4(void);
extern s32 fn_1_54E34(void *object, f32 value);
extern void fn_1_652F4(void);

extern void lbl_8006DCA4(void);
extern s32 fn_1_54E34(void *object, f32 value);
extern void *fn_1_5448C(void *);
extern void fn_1_5489C(void *, void *);
extern void fn_1_862D4(s16 value, void *result);
extern void *fn_1_548AC(u32 size);

typedef struct {
    u32 pad_00;
    void (*vtable)(void);
    void *owner;
} Event;

typedef struct {
    u8 pad_00[0x18];
    s16 value;
    u8 pad_1a[0xe];
    f32 amount;
    u8 pad_2c[0x10];
    u8 embedded[1];
} Object;

void fn_1_65268(Object *object) {
    u8 local[4];
    void *result;
    Event *event;

    fn_1_862D4(object->value, local);
    lbl_8006DCA4();
    if (fn_1_54E34(&object->embedded[0], object->amount) != 0) {
        result = fn_1_5448C(local);
        event = (Event *)fn_1_548AC(0xc);
        if (event != 0) {
            event->vtable = fn_1_652F4;
            event->owner = object;
            fn_1_5489C(result, event);
        }
    }
}
/* fzgx:end fn_1_65268 */

/* fzgx:begin fn_1_652F4 */
typedef struct {
    u8 pad_00[0x18];
    s16 unk_18;
    u8 pad_1a[2];
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 pad_2c[0x28];
    s16 unk_54;
    s16 unk_56;
} fn_1_652F4_EffectData;
typedef struct {
    u8 pad_00[0x120];
    void *unk_120;
} EffectRoot;
typedef struct {
    f32 value;
    f32 value2;
    u8 pad_08[0x34];
    u8 color[4];
} ParticleData;

#pragma opt_common_subs off
void fn_1_652F4(fn_1_652F4_Effect *effect) {
    u8 temp[0xc];
    ParticleData data;
    fn_1_652F4_EffectData *object;
    void *owner;
    register f32 color_scale;
    register f32 scale;
    void *manager;
    s16 level;

    object = effect->unk_08;
    fn_1_867CC(object->unk_18, temp);
    level = *(s16 *)((u8 *)fn_1_868C0((s8)object->unk_18) + 0x3ba);
    owner = fn_1_86254(object->unk_18);
    if (level >= 3 && *(s8 *)((u8 *)owner + 0x475) == -1) {
        return;
    }
    manager = ((EffectRoot *)lbl_1_bss_38458->unk_8)->unk_120;
    lbl_8006D9D8(temp);
    lbl_8006D95C(object->unk_56);
    mathutil_mtxA_rotate_x(object->unk_54);
    memset(&data, 0, 0x40);
    lbl_8006DB74((u8 *)&data + 8);

        scale = (((f32 *)&lbl_1_rodata_2AA0))[0];
        data.value = scale * object->unk_28;
    color_scale = lbl_1_rodata_29AC[0];
    data.color[0] = (u8)(s32)(color_scale * object->unk_1c);
    data.color[1] = (u8)(s32)(color_scale * object->unk_20);
    data.color[2] = (u8)(s32)(color_scale * object->unk_24);
    data.color[3] = 0xff;
    data.value2 = data.value;
    fn_1_9F914(&data, manager);
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_652F4 */

/* fzgx:begin fn_1_65420 */
// fn_1_65420: empty in retail (single blr).
void fn_1_65420(void) {
}
/* fzgx:end fn_1_65420 */

/* fzgx:begin fn_1_65424 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
}
#pragma section code_type ".text"


typedef struct {
    u8 pad_00[0x10];
    s32 unk_10;
} fn_1_65424_EffectObject;

#pragma fp_contract off
void fn_1_65424(fn_1_65424_EffectObject *object) {
    u32 next;

    if (object->unk_10 == 0) {
        next = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        lbl_1_data_1D628 = next;
        object->unk_10 = (s32)(60.0f * (0.3f + 0.25f * ((f32)(((0x7FFF) & ((next >> 16)))) / 32767.0f)));
    }
}
#pragma fp_contract reset
/* fzgx:end fn_1_65424 */

/* fzgx:begin fn_1_656C8 */
typedef struct {
    u32 unk_00;
    void (*unk_04)(void);
    void *unk_08;
} EffectEvent;

typedef struct {
    u8 unk_00[0x28];
    f32 unk_28;
    u8 unk_2c[0x10];
    u8 unk_3c[1];
} fn_1_656C8_EffectObject;

// Initializes the effect and queues an event when its embedded state is ready.
void fn_1_656C8(fn_1_656C8_EffectObject *object) {
    void *result;
    EffectEvent *event;

    lbl_8006DCA4();
    if (fn_1_54E34(&object->unk_3c, object->unk_28) != 0) {
        result = fn_1_5448C(&object->unk_3c);
        event = (EffectEvent *)fn_1_548AC(0xc);
        if (event != 0) {
            event->unk_04 = fn_1_65748;
            event->unk_08 = object;
            fn_1_5489C( (void **)(void *)(result), (void **)(void *)(event));
        }
    }
}
/* fzgx:end fn_1_656C8 */

/* fzgx:begin fn_1_65AAC */
// fn_1_65AAC: empty in retail (single blr).
void fn_1_65AAC(void) {
}
/* fzgx:end fn_1_65AAC */

/* fzgx:begin fn_1_65AB0 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const u32 fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
static const u32 fzgx_pool_table24[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.00800000037997961f;
    s = 0.004545454401522875f;
    s = 0.014285714365541935f;
    s = 2000.0f;
    s = 1000.0f;
    s = 2.0999999046325684f;
}
static const u32 fzgx_pool_table26[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04;
    d = 0.98;
    d = 0.96;
    d = 0.025;
    d = -1.0;
    d = 0.8;
}
static const u32 fzgx_pool_table28[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.03999999910593033f;
}
static const u32 fzgx_pool_table30[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 7.0f;
}
static const u32 fzgx_pool_table32[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct {
    u8 pad_00[0x10];
    s32 value_10;
    u8 pad_14[0x18];
    f32 value_2c;
    u8 pad_30[0x84];
    f32 value_b4;
} Fn165AB0Object;

void fn_1_65AB0(Fn165AB0Object *obj) {
    f32 fn_1_65AB0_zero;
    f32 factor;
    struct { f32 value; } result;

    if ((fn_1_65AB0_zero = 0.0f, obj->value_b4 == fn_1_65AB0_zero)) {
        obj->value_b4 = 1.0f;
    }
    if (obj->value_b4 > 1.0f) {
        obj->value_2c = obj->value_2c * obj->value_b4;
        factor = obj->value_b4 / 7.0f;
        if (factor < 1.0f) {
            result.value = 1.0f;
        } else if (factor > 1.2f) {
            result.value = 1.2f;
        } else {
            result.value = factor;
        }
        obj->value_10 = (s32)((f32)obj->value_10 * result.value);
    }
}
/* fzgx:end fn_1_65AB0 */

/* fzgx:begin fn_1_65B58 */
// fn_1_65B58: empty in retail (single blr).
void fn_1_65B58(void) {
}
/* fzgx:end fn_1_65B58 */

/* fzgx:begin fn_1_65B5C noprologue */
typedef int s32;
typedef unsigned char u8;
typedef float f32;
typedef double f64;
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const unsigned long fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const unsigned long fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const unsigned long fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const unsigned long fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const unsigned long fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const unsigned long fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const unsigned long fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
static const unsigned long fzgx_pool_table24[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const unsigned long *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.00800000037997961f;
    s = 0.004545454401522875f;
    s = 0.014285714365541935f;
    s = 2000.0f;
    s = 1000.0f;
    s = 2.0999999046325684f;
}
static const unsigned long fzgx_pool_table26[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const unsigned long *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04;
    d = 0.98;
    d = 0.96;
    d = 0.025;
    d = -1.0;
    d = 0.8;
}
static const unsigned long fzgx_pool_table28[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const unsigned long *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.03999999910593033f;
}
static const unsigned long fzgx_pool_table30[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const unsigned long *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 7.0f;
}
static const unsigned long fzgx_pool_table32[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const unsigned long *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.9200000137090683;
    d = -0.02;
    s = -0.02500000037252903f;
}
static const unsigned long fzgx_pool_table34[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const unsigned long *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct EffP {
    s32 pad0[4];
    s32 i10;
    s32 pad14[2];
    f32 f1c, f20, f24, f28, f2c;
    s32 pad30[3];
    f32 f3c, f40, f44, f48, f4c, f50;
    u8 pad54[0xb4 - 0x54];
    f32 fb4;
} EffP;

#pragma opt_dead_assignments off
static inline f64 fn_1_65B5C_operand(f64 right, f64 left) { return left * right; }
void fn_1_65B5C(EffP *p) {
    f32 fzgx_live_;
    f32 fzgx_live;
    f32 one;
    f32 s;
    f32 t;
    p->f48 *= 0.98f;
    p->f4c *= 0.98f;
    p->f50 *= 0.98f;
    p->f3c = p->f3c + p->f48;
    p->f40 = p->f40 + p->f4c;
    p->f44 = p->f44 + p->f50;
    if (p->f28 > 50.0f * (((p->fb4) / 2.0f))) {
        fzgx_live_ = p->f2c;
        p->f2c = fn_1_65B5C_operand((0.9200000137090683), (fzgx_live_));
    }
    p->f28 = p->f28 + p->f2c;
    one = 1.0f;
    if (p->fb4 > one) {
        if (p->i10 < 50) {
            s = one - (one + (f32)(-0.02 * (f64)p->i10));
            fzgx_live = p->f1c;
            p->f1c = fzgx_live * s;
            p->f20 = p->f20 * s;
            p->f24 = p->f24 * s;
        }
    } else if (p->i10 < 40) {
        t = -0.025f * (f32)p->i10;
        s = one - (one + t);
        fzgx_live = p->f1c;
        p->f1c = fzgx_live * s;
        p->f20 = p->f20 * s;
        p->f24 = p->f24 * s;
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_65B5C */

/* fzgx:begin fn_1_65CDC noprologue */
#include "dolphin/hw_regs.h"
#include "psvec.h"

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef unsigned char u8;
typedef unsigned long u32;
typedef float f32;
typedef double f64;

extern const f32 lbl_1_rodata_2950[];
extern void lbl_8006D9D8(void *);
extern void lbl_8006D7B0(void);
extern u32 mathutil_mtxA_rotate_z(s32);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void fn_1_9F914(void *, u32);
extern void *memset(void *, int, u32);

struct Fn1_65CDC {
	u8 _pad00[0x1c];
	f32 value1c;
	f32 value20;
	f32 value24;
	f32 value28;
	u8 _pad2c[0x08];
	u32 object34;
	u8 _pad38[0x04];
	f32 value3c;
	u8 _pad40[0x18];
	s16 value58;
};

struct Fn1_65CDCTmp {
	u8 data[0x30];
};

struct Fn1_65CDCSub {
	u8 data[0x34];
};

struct Fn1_65CDCWork {
	f32 alpha;
	f32 alpha2;
	struct Fn1_65CDCSub sub;
	u8 red;
	u8 green;
	u8 blue;
	u8 alphaByte;
};

#pragma opt_propagation off
#pragma opt_common_subs off
static inline f32 fn_1_65CDC_array_read(f32 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments off
void fn_1_65CDC(struct Fn1_65CDC *self) {
	struct Fn1_65CDCWork work;
	struct Fn1_65CDCTmp tmp;
	u32 object;
	f32 radius;
	f32 distance;
	f32 alpha;
	const f32 *pool;
	f32 v[3];
	f32 x;
	f32 y;
	f32 z;
	f32 sum;
	f32 *m;
	object = self->object34;
	pool = lbl_1_rodata_2950;
	radius = self->value28;
	lbl_8006D9D8(&self->value3c);
	lbl_8006D7B0();
	mathutil_mtxA_rotate_z(self->value58);
	m = (f32 *)(LC_BASE + 0x0);
	x = fn_1_65CDC_array_read(m, 3);
	y = fn_1_65CDC_array_read(m, 7);
	z = fn_1_65CDC_array_read(m, 11);
	psvec_set(v, z, y, x);
	sum = (f32) (fn_1_65CDC_array_read(v, 0) * fn_1_65CDC_array_read(v, 0));
	sum = sum + fn_1_65CDC_array_read(v, 1) * fn_1_65CDC_array_read(v, 1);
	sum = sum + z * z;
	distance = lbl_8006D0B4(sum);
	if (distance > pool[1] + radius) {
		lbl_8006DB74(&tmp);
		lbl_8006D848((distance - radius) / distance);
		lbl_8006DFC4(&tmp);
	}
	memset(&work, 0, 0x40);
	lbl_8006DB74(&work.sub);
	alpha = pool[0x150 / 4] * self->value28;
	work.alpha = alpha;
	work.red = (u8) (pool[0x5c / 4] * self->value1c);
	work.green = (u8) (pool[0x5c / 4] * self->value20);
	work.blue = (u8) (pool[0x5c / 4] * self->value24);
	work.alphaByte = 0xff;
	work.alpha2 = alpha;
	fn_1_9F914(&work, object);
}
#pragma opt_dead_assignments reset
#pragma opt_common_subs reset
#pragma opt_propagation reset
/* fzgx:end fn_1_65CDC */

/* fzgx:begin fn_1_65E58 */
typedef struct fn_1_65E58_Effect {
    u8 _pad_00[0x10];
    int field_10;
    u8 _pad_14[0x4];
    s16 field_18;
    u8 _pad_1a[0x9e];
} fn_1_65E58_Effect;

void fn_1_65E58(fn_1_65E58_Effect *effect) {
    effect->field_10 = 10;
    fn_1_8636C(effect->field_18, (u8 *)effect + 0xb8);
}
/* fzgx:end fn_1_65E58 */

/* fzgx:begin fn_1_65E88 */
// fn_1_65E88: empty in retail (single blr).
void fn_1_65E88(void) {
}
/* fzgx:end fn_1_65E88 */

/* fzgx:begin fn_1_660EC noprologue */
#include "rel/main_rel/effect.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
}
static const u32 fzgx_pool_table14[12] = {0x3F8CCCCD, 0x00000000, 0x3F666666, 0xBF8CCCCD, 0x00000000, 0x3F666666, 0x00000000, 0x00000000, 0xBF333333, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
static const u32 fzgx_pool_table22[2] = {0xFFFFFFFF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 30.0;
    d = 0.03;
    s = 0.9399999976158142f;
    s = -0.07999999821186066f;
}
static const u32 fzgx_pool_table24[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.00800000037997961f;
    s = 0.004545454401522875f;
    s = 0.014285714365541935f;
    s = 2000.0f;
    s = 1000.0f;
    s = 2.0999999046325684f;
}
static const u32 fzgx_pool_table26[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04;
    d = 0.98;
    d = 0.96;
    d = 0.025;
    d = -1.0;
    d = 0.8;
}
static const u32 fzgx_pool_table28[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.03999999910593033f;
}
static const u32 fzgx_pool_table30[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 7.0f;
}
static const u32 fzgx_pool_table32[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.9200000137090683;
    d = -0.02;
    s = -0.02500000037252903f;
}
static const u32 fzgx_pool_table34[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 182.04444885253906f;
    s = 768.0f;
    s = 29.0f;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct {
    u8 pad_00[0x10];
    s32 unk_10;
    u8 pad_14[0x24];
    u8 *unk_38;
    u8 pad_3C[0x18];
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
} ObjFx_T;

extern u32 lbl_801A66A0;
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D9D8(void *, u32);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E14C(f32);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void fn_80072558(void);
extern void fn_1_55FC4(f32);
extern void fn_1_55FF0(f32);
extern u32 fn_1_56018(s32);
extern void fn_1_560F0(s32, void *);
extern u32 fn_1_55210(u32);

void fn_1_660EC(ObjFx_T *this)
{
    u8 *sub = this->unk_38;
    f32 scale;
    u32 g;
    u32 buf[12];

    scale = (this->unk_10 < 0x14) ? 0.05f * (f32)(s32)this->unk_10 : 1.0f;
    lbl_8006D7F4((f32)((u32)(lbl_801A66A0 % 30)) / 29.0f, 0.0f, 0.0f);
    lbl_8006DB74(buf);
    g = *(u32 *)(lbl_1_bss_38458->unk_8 + 0x1F0);
    lbl_8006D9D8(&this->pad_3C[0], lbl_1_bss_38458->unk_8);
    lbl_8006DFC4(sub + 0xEC);
    mathutil_mtxA_rotate_y(this->unk_56);
    mathutil_mtxA_rotate_x(this->unk_54);
    mathutil_mtxA_rotate_z(this->unk_58);
    lbl_8006E14C(0.5f);
    fn_1_55FC4(0.5f);
    fn_80072558();
    fn_1_55FF0(scale);
    fn_1_56018(1);
    fn_1_560F0(0, buf);
    fn_1_55210(g);
    fn_1_56018(0);
}
/* fzgx:end fn_1_660EC */

/* fzgx:begin fn_1_66254 */
typedef struct {
    u8 pad[0x28];
    f32 field_28;
    f32 field_2c;
} fn_1_66254_output;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[2] = {0x00000000, 0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.4000000953674316f;
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table12[1] = {0xB4000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 240.0f;
    s = 100.0f;
    s = 300.0f;
    s = 200.0f;
    s = 10000.0f;
    s = 5000.0f;
    s = 204.0f;
    s = 85.0f;
    s = -0.05000000074505806f;
    s = 4.0f;
    s = -0.05999999865889549f;
    s = -0.5f;
    s = -1.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 512.0f;
    s = 0.029999999329447746f;
    s = 51.0f;
    s = 88.0f;
    d = -3.0;
    s = 4.5f;
    s = 6.0f;
    s = 1.100000023841858f;
}
static const u32 fzgx_pool_table16[2] = {0x00000000, 0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.100000023841858f;
}
static const u32 fzgx_pool_table18[4] = {0x00000000, 0x3F666666, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.699999988079071f;
}
static const u32 fzgx_pool_table20[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2000000476837158f;
    s = 50.0f;
    s = 0.02500000037252903f;
    s = 0.800000011920929f;
    s = 0.0625f;
    s = 2.5f;
}
static const u32 fzgx_pool_table22[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -3.0f;
}
static const u32 fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 1.8600000143051147f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 210.0;
    d = 0.02;
    d = 0.003;
    d = -0.699999988079071;
    d = -0.029999999329447746;
    d = 0.141;
    d = 0.699999988079071;
    d = 1.0;
    d = 0.3;
    d = 0.800000011920929;
    d = 12.0;
    s = -0.8999999761581421f;
    s = 0.07000000029802322f;
    s = 0.6000000238418579f;
    s = 30.0f;
    s = 1.059999942779541f;
    s = 28.0f;
    d = 5.0;
    s = 3.5f;
    s = 180.0f;
}
#pragma section code_type ".text"
void fn_1_66254(fn_1_66254_output *output) {
    u32 *state;
    u32 seed;
    u32 value;
    f32 coordinate;
    f32 field_2c;
    f32 field_28;

    state = &lbl_1_data_1D628;
    seed = *state;
    value = seed * 0x41c64e6d;
    value += 0x3039;
    coordinate = 0.8f + (f32)(0.2f * ((f32)((value >> 16) & 0x7fff) / 32767.0f));
    *state = value;
    field_2c = 3.5f * coordinate;
    field_28 = 0.5f * coordinate;
    output->field_2c = field_2c;
    output->field_28 = field_28;
}
/* fzgx:end fn_1_66254 */

/* fzgx:begin fn_1_662D4 */
// fn_1_662D4: empty in retail (single blr).
void fn_1_662D4(void) {
}
/* fzgx:end fn_1_662D4 */

/* fzgx:begin fn_1_67294 noprologue */
#include "dolphin/types.h"
#include "psvec.h"
#include "rel/main_rel/effect.h"

extern const f32 lbl_1_rodata_2950[];

extern void lbl_8006D9D8(void *);
extern void lbl_8006D7B0(void);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void *memset(void *, int, u32);
extern int fn_1_9F914(const void *, const void *);

typedef struct {
	f32 e[0x60];
} Pool;

typedef struct {
	u8 pad_0[0x168];
	u32 unk_168;
} Ctx;

typedef struct {
	f32 x, y, z;
} Vec3;

typedef struct {
	u8 pad_0[0x30];
} VecObj;

typedef struct {
	u8 pad_0[0x34];
} Inner;

typedef struct {
	f32 unk_0;
	f32 unk_4;
	Inner unk_8;
	u8 unk_3C;
	u8 unk_3D;
	u8 unk_3E;
	u8 unk_3F;
} Buf;

typedef struct {
	u8 pad_0[0x1C];
	f32 unk_1C;
	f32 unk_20;
	f32 unk_24;
	f32 unk_28;
	u8 pad_2C[0x10];
	u8 unk_3C;
} Obj;

void fn_1_67294(Obj *arg0)
{
    f32 fzgx_live_;
    f32 fzgx_live;
	Vec3 v;
	Buf buf;
	VecObj o;
	const Pool *pool = (const Pool *)&lbl_1_rodata_2950;
	Ctx *ctx;
	f32 a;
	f32 d;
	f32 s;
	u32 g;
	Obj *t = arg0;

	ctx = *(Ctx **)&lbl_1_bss_38458->unk_8;
	g = ctx->unk_168;
	a = t->unk_28;
	lbl_8006D9D8(&t->unk_3C);
	lbl_8006D7B0();
	psvec_set(&v, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
	d = (f32)(v.x * v.x);
	fzgx_live = v.y;
	d = fzgx_live * fzgx_live + d;
	fzgx_live_ = v.z;
	d = lbl_8006D0B4(fzgx_live_ * fzgx_live_ + d);
	if (d > pool->e[1] + a) {
		lbl_8006DB74(&o);
		lbl_8006D848((d - a) / d);
		lbl_8006DFC4(&o);
	}
	memset(&buf, 0, 0x40);
	lbl_8006DB74(&buf.unk_8);
	s = pool->e[0x54] * t->unk_28;
	buf.unk_0 = s;
	buf.unk_3C = (u8)(pool->e[0x17] * t->unk_1C);
	buf.unk_3D = (u8)(pool->e[0x17] * t->unk_20);
	buf.unk_3E = (u8)(pool->e[0x17] * t->unk_24);
	buf.unk_3F = 0xFF;
	buf.unk_4 = s;
	fn_1_9F914(&buf, (const void *)g);
}
/* fzgx:end fn_1_67294 */

/* fzgx:begin fn_1_67414 */
struct fn_1_67414_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0xa0];
    f32 unk_b4;
};

void fn_1_67414(struct fn_1_67414_Arg0 *arg0) {
    // Volatile preserves the retail load-after-store ordering for the pooled value.
    volatile const f32 *value = (volatile const f32 *)&lbl_1_rodata_2954;
    arg0->unk_10 = 30;
    arg0->unk_b4 = *value;
}
/* fzgx:end fn_1_67414 */

/* fzgx:begin fn_1_6742C */
// fn_1_6742C: empty in retail (single blr).
void fn_1_6742C(void) {
}
/* fzgx:end fn_1_6742C */

/* fzgx:begin fn_1_67430 noprologue */
#include "dolphin/types.h"
#include "psvec.h"

extern const f32 lbl_1_rodata_2950[];
extern u32 fn_1_86514(int);
extern void fn_1_862D4(int, void *);
extern void fn_1_8636C(int, void *);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    f32 x, y, z;
    u8  pad[40];
} Vec3fBig;

typedef struct {
    u8    pad00[0x10];
    u32   unk10;
    u8    pad14[4];
    s16   unk18;
    u8    pad1a[0x0E];
    f32   f28;
    f32   f2c;
    u8    pad30[0x0C];
    Vec3f v3c;
    Vec3f v48;
    u8    pad54[0x40];
    Vec3f v94;
    u8    padA0[0x14];
    f32   fb4;
} Obj67430;

static inline f32 fn_1_67430_read_pointer(Vec3f * owner) { return owner->z; }
#pragma opt_dead_assignments off
#pragma opt_propagation off
#pragma opt_loop_invariants off
void fn_1_67430(Obj67430 *p)
{
    Vec3fBig   v1;
    Vec3f      v0;
    f32 fzgx_live_;
    const f64 *pool = (const f64 *)&lbl_1_rodata_2950;
    f32 fzgx_live;
    f32        a, b, c;
    f32        old;
    f64        t;

    if (((fn_1_86514(p->unk18) >> 29) & 1) == 0) {
        p->unk10 = 1;
    }
    fn_1_862D4(p->unk18, &v0);
    fn_1_8636C(p->unk18, &v1);
    p->v48.x = p->v48.x * pool[104];
    p->v48.y = p->v48.y * pool[104];
    fzgx_live_ = p->v48.z;
    p->v48.z = fzgx_live_ * (*((pool) + (104)));
    psvec_add(&p->v94, &p->v48, &p->v94);
    lbl_8006DC6C(&v1);
    a = v0.x;
    fzgx_live = v0.y;
    b = fzgx_live;
    c = fn_1_67430_read_pointer(&v0);
    /* fzgx-allow: A1 current-warp matrix lives in the locked hardware cache */
    *(f32 *)(0xE0000000 + 0x0C) = a;
    *(f32 *)(0xE0000000 + 0x1C) = b;
    *(f32 *)(0xE0000000 + 0x2C) = c;
    lbl_8006E1B0(&p->v94, &p->v3c);
    old = p->f28;
    t = pool[76] * (p->f2c - old);
    p->f28 = old + t;
    t = pool[129] * (pool[82] - p->fb4);
    p->fb4 = p->fb4 + t;
}
#pragma opt_loop_invariants reset

#pragma opt_propagation reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_1_67430 */

/* fzgx:begin fn_1_6755C */
typedef struct {
    u8 pad_0[0x18];
    s16 unk_18;
    u8 pad_1a[2];
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 pad_2c[0x88];
    f32 unk_b4;
} FnObj_6755C;

typedef struct {
    u8 pad_0[0x120];
    u32 unk_120;
} Root_6755C;

void fn_1_6755C(FnObj_6755C *obj) {
    u8 temp[0x30];
    u8 data[0x40];
    f32 f1;
    f32 f0;
    f32 f3;
    f32 f2;
    Root_6755C *root;
    u32 manager;

    root = (Root_6755C *)(u32)lbl_1_bss_38458->unk_8;
    manager = root->unk_120;
    fn_1_8636C(obj->unk_18, temp, (u32)root);
    lbl_8006D9D8((u8 *)obj + 0x3c);
    lbl_8006DFC4(temp);
    lbl_8006D95C(0);
    mathutil_mtxA_rotate_x(0x4000);
    memset(data, 0, 0x40);
    lbl_8006DB74(data + 8);

    f3 = (((f32 *)&lbl_1_rodata_2AA0))[0] * obj->unk_28;
    *(f32 *)(data + 0) = f3;
    f2 = lbl_1_rodata_29AC[0];
    f1 = obj->unk_b4;
    f0 = obj->unk_1c;
    f0 = f2 * f0;
    f0 = f0 * f1;
    data[0x3c] = (u8)f0;
    f0 = obj->unk_20;
    f0 = f2 * f0;
    f0 = f0 * f1;
    data[0x3d] = (u8)f0;
    f0 = obj->unk_24;
    f0 = f2 * f0;
    data[0x3f] = 0xff;
    *(f32 *)(data + 4) = f3;
    f0 = f0 * f1;
    data[0x3e] = (u8)f0;
    fn_1_9F914(data, (const void *)(u32)(manager));
}
/* fzgx:end fn_1_6755C */

/* fzgx:begin fn_1_6766C */
typedef struct {
    u8 padding[0xb4];
    f32 value;
} Fn6766CObject;

void fn_1_6766C(Fn6766CObject *object) {
    object->value = lbl_1_rodata_2978[0];
}
/* fzgx:end fn_1_6766C */

/* fzgx:begin fn_1_6767C */
// fn_1_6767C: empty in retail (single blr).
void fn_1_6767C(void) {
}
/* fzgx:end fn_1_6767C */

/* fzgx:begin fn_1_67D0C noprologue */
#include "dolphin/types.h"
#include "psvec.h"
#include "rel/main_rel/effect.h"

extern const f32 lbl_1_rodata_2950[];

extern void lbl_8006D9D8(void *);
extern void lbl_8006D7B0(void);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void *memset(void *, int, u32);
extern int fn_1_9F914(const void *, const void *);

typedef struct {
	f32 e[0x60];
} Pool;

typedef struct {
	u8 pad_0[0x50];
	u32 unk_50;
} Ctx;

typedef struct {
	u8 pad_0[0x8];
	Ctx *unk_8;
} Mid;

typedef struct {
	Mid *unk_0;
} Hdr;

typedef struct {
	f32 x, y, z;
} Vec3;

typedef struct {
	u8 pad_0[0x30];
} VecObj;

typedef struct {
	u8 pad_0[0x34];
} Inner;

typedef struct {
	f32 unk_0;
	f32 unk_4;
	Inner unk_8;
	u8 unk_3C;
	u8 unk_3D;
	u8 unk_3E;
	u8 unk_3F;
} Buf;

typedef struct {
	u8 pad_0[0x1C];
	f32 unk_1C;
	f32 unk_20;
	f32 unk_24;
	f32 unk_28;
	u8 pad_2C[0x10];
	u8 unk_3C;
	u8 unk_3D;
	u8 unk_3E;
	u8 unk_3F;
	u8 pad_40[0x74];
	f32 unk_B4;
} Obj;

void fn_1_67D0C(Obj *arg0)
{
    f32 fzgx_live_;
    f32 fzgx_live;
	Vec3 v;
	Buf buf;
	VecObj o;
	const Pool *pool = (const Pool *)&lbl_1_rodata_2950;
	Ctx *ctx;
	f32 a;
	f32 d;
	f32 s;
	u32 g;
	Obj *t = arg0;

	ctx = (*(Mid **)&lbl_1_bss_38458)->unk_8;
	g = ctx->unk_50;
	a = pool->e[0x2E] * t->unk_B4;
	lbl_8006D9D8(&t->unk_3C);
	lbl_8006D7B0();
	psvec_set(&v, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
	d = (f32)(v.x * v.x);
	fzgx_live = v.y;
	d = fzgx_live * fzgx_live + d;
	fzgx_live_ = v.z;
	d = lbl_8006D0B4(fzgx_live_ * fzgx_live_ + d);
	if (d > pool->e[1] + a) {
		lbl_8006DB74(&o);
		lbl_8006D848((d - a) / d);
		lbl_8006DFC4(&o);
	}
	memset(&buf, 0, 0x40);
	lbl_8006DB74(&buf.unk_8);
	s = pool->e[0x54] * a;
	buf.unk_0 = s;
	buf.unk_3C = (u8)(pool->e[0x17] * t->unk_1C);
	buf.unk_3D = (u8)(pool->e[0x17] * t->unk_20);
	buf.unk_3E = (u8)(pool->e[0x17] * t->unk_24);
	buf.unk_3F = 0xFF;
	buf.unk_4 = s;
	fn_1_9F914(&buf, (const void *)g);
}
/* fzgx:end fn_1_67D0C */

/* fzgx:begin fn_1_67E94 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
}
#pragma section code_type ".text"


static inline f32 pool_pad(u32 sel) {
    switch (sel) {
    case 0: return 1.0f;
    case 1: return 2.0f;
    case 2: return 3.0f;
    case 3: return 4.0f;
    }
    return 0.0f;
}

void fn_1_67E94(u8 *object) {
    u32 value;

    if (*(s32 *)(object + 0x10) == 0) {
        value = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        lbl_1_data_1D628 = value;
        *(s32 *)(object + 0x10) = (s32)(60.0f *
            (0.2f + (f32)((value & 0x7fff8000) >> 16) / 32767.0f));
    } else {
        pool_pad(value);
    }
    *(u16 *)(object + 0xae) = 0;
}
/* fzgx:end fn_1_67E94 */

/* fzgx:begin fn_1_67F20 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
    s = 0.0f;
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
    s = 15.0f;
    s = 0.20000000298023224f;
    s = 0.07999999821186066f;
    s = 0.25f;
    s = 0.9800000190734863f;
    s = 0.9900000095367432f;
    s = 40.0f;
    s = 20.0f;
    s = 1.5f;
    s = 0.44999998807907104f;
    s = -2.0f;
    s = 0.0833333358168602f;
    s = 0.15000000596046448f;
    s = 0.125f;
    s = -0.4000000059604645f;
    s = -0.30000001192092896f;
    s = 2.0f;
    s = 250.0f;
    d = 0.6;
    d = 0.4;
    s = 0.30000001192092896f;
    s = -0.004000000189989805f;
    s = 0.01666666753590107f;
    s = 65536.0f;
    s = 4096.0f;
    s = 0.9599999785423279f;
    s = 0.4000000059604645f;
    s = 0.05050000175833702f;
    s = 0.050999999046325684f;
    s = 0.949999988079071f;
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 150.0;
    d = 10.0;
    d = 3.0;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    d = 1.2;
    d = 0.1;
    s = 10.0f;
    s = 18.0f;
    d = 0.7;
    d = 50.0;
}
static const u32 fzgx_pool_table8[3] = {0x00000000, 0x3DCCCCCD, 0xC019999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    d = 24.0;
    s = 0.7071067690849304f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 255.0;
    d = 0.9;
    s = 0.004000000189989805f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = -1.1920928955078125e-07f;
}
#pragma section code_type ".text"

typedef struct Fn167F20 {
    u8 pad00[0x10];
    s32 state;
    u8 pad14[0x08];
    f32 value1c;
    f32 value20;
    f32 value24;
    f32 value28;
    f32 value2c;
    u8 pad30[0x0c];
    f32 value3c;
    f32 value40;
    f32 value44;
    f32 value48;
    f32 value4c;
    f32 value50;
    u8 pad54[0x34];
    f32 value88;
    f32 value8c;
    u8 pad90[0x1c];
    s16 valueac;
    s16 valueae;
} Fn167F20;

static inline f32 fn_1_67F20_operand(f32 right, f32 left) { return left * right; }
void fn_1_67F20(Fn167F20 *obj) {
    f32 current;
    struct { f32 value; } delta;

    obj->value48 *= 0.9f;
    obj->value4c *= 0.9f;
    obj->value50 *= 0.9f;
    obj->valueac = (s16)(fn_1_67F20_operand((0.9f), ((f32)obj->valueac)));

    obj->value48 += 0.001f;
    obj->value3c += obj->value48;
    obj->value40 += obj->value4c;
    obj->value44 += obj->value50;
    obj->valueae += obj->valueac;

    current = obj->value88;
    { f32 __reg_value_delta = obj->value8c - current; delta.value = __reg_value_delta; }
    { f32 __reg_value_delta = fn_1_67F20_operand((delta.value), (0.05f)); delta.value = __reg_value_delta; }
    obj->value88 = current + delta.value;

    current = obj->value28;
    { f32 __reg_value_delta = obj->value2c - current; delta.value = __reg_value_delta; }
    { f32 __reg_value_delta = fn_1_67F20_operand((delta.value), (0.01f)); delta.value = __reg_value_delta; }
    obj->value28 = current + delta.value;

    if (obj->state < 0x1e) {
        obj->value1c = fn_1_67F20_operand((0.01f), (-obj->value1c));
        obj->value20 = fn_1_67F20_operand((0.01f), (-obj->value20));
        obj->value24 = fn_1_67F20_operand((0.01f), (-obj->value24));
    }
}
/* fzgx:end fn_1_67F20 */

/* fzgx:begin fn_1_68054 */
typedef struct fn_1_68054_EffectObject {
    u8 pad0[0x28];
    f32 value;
    u8 pad1[0x10];
    u8 subobject;
} fn_1_68054_EffectObject;

typedef struct fn_1_68054_EffectEntry {
    u8 pad0[4];
    void (*callback)(void);
    fn_1_68054_EffectObject *owner;
} fn_1_68054_EffectEntry;

// Advances the effect and queues its completion callback when it finishes.
void fn_1_68054(fn_1_68054_EffectObject *effect) {
    f32 progress;
    void *source;
    fn_1_68054_EffectEntry *completion;

    progress = effect->value / lbl_1_rodata_2A70[0];
    lbl_8006DCA4();

    if (fn_1_54E34(&effect->subobject, progress) == 0) {
        return;
    }

    source = fn_1_5448C(&effect->subobject);
    completion = (fn_1_68054_EffectEntry *)fn_1_548AC(0xc);
    if (completion == 0) {
        return;
    }

    completion->callback = fn_1_64388;
    completion->owner = effect;
    fn_1_5489C( (void **)(void *)(source), (void **)(void *)(completion));
}
/* fzgx:end fn_1_68054 */

/* fzgx:begin fn_1_680F4 */
// fn_1_680F4: empty in retail (single blr).
void fn_1_680F4(void) {
}
/* fzgx:end fn_1_680F4 */
