#include "types.h"


/* --- dol/fn_80071100.c --- */
/* --- dol/fn_80071100.c --- */
typedef u32 (*fn_80071100_Fn0)(u32, u32, u32);

extern u32 fn_80078DA8(u32, u32, u32);
extern u32 lbl_8015AB70[];
extern u32 lbl_8015ABCC[];
extern u32 lbl_801A6D0C;
extern void fn_8007174C(u32, u32);

u32 fn_80071100(u32 arg0, u32 arg1, u32 arg2) {
    s32 flag;
    u32 arg2_local;
    u32 arg0_local;

    flag = 0;
    arg2_local = arg2;
    arg0_local = arg0;
    if (arg1 == 0) {
        arg1 = ((fn_80071100_Fn0)lbl_801A6D0C)(32, arg1, arg2_local);
        if (arg1 == 0) {
            fn_8007174C((u32)&lbl_8015AB70, (u32)&lbl_8015ABCC);
        }
        flag = 1;
    }
    fn_80078DA8(arg1, arg0_local, arg2_local);
    if (flag == 0) {
        *(u32 *)((u8 *)arg1 + 16) = (*(u32 *)((u8 *)arg1 + 16) | 1);
    }
    return arg1;
}

/* --- dol/fn_800711A8.c --- */
typedef void (*fn_800711A8_Fn)(void *);

extern fn_800711A8_Fn lbl_801A6D08;

struct fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

void fn_800711A8(struct fn_800711A8_Arg0 *arg0) {
    struct fn_800711A8_Entry *entry;
    s32 offset;
    s32 i;

    offset = 0;
    i = 0;
    while (i < arg0->count) {
        entry = *(struct fn_800711A8_Entry **)((u8 *)arg0->entries + offset);
        if (arg0->field_14 == 0 && entry != 0) {
            void *p = entry->field_24;
            if (p != 0) {
                lbl_801A6D08(p);
            }
        }
        offset += 8;
        i += 1;
    }
    if (arg0->field_14 != 0) {
        lbl_801A6D08(arg0->field_14);
    }
    if (!(arg0->field_10 & 1)) {
        lbl_801A6D08(arg0);
    }
}

/* --- dol/fn_80071268.c --- */
extern void _savegpr_27(void);
extern void *fn_80083970(void *arg0, u32 arg1);
extern void _restgpr_27(void);

struct fn_80071268_Entry {
    void *unk_0;
    void *unk_4;
};

struct fn_80071268_Arg0 {
    s32 count;
    u8 pad_4[4];
    struct fn_80071268_Entry *entries;
};

void *fn_80071268(struct fn_80071268_Arg0 *arg0, u32 arg1) {
    u32 offset;
    s32 i;
    struct fn_80071268_Entry *entry;

    i = 0;
    offset = 0;
    while (i < arg0->count) {
        entry = (struct fn_80071268_Entry *)((u8 *)arg0->entries + offset);
        if (fn_80083970(entry->unk_4, arg1) != 0) {
            return entry->unk_0;
        }
        offset += 8;
        i += 1;
    }
    return 0;
}

/* --- dol/fn_800712E4.c --- */
extern void _savegpr_23(void);
extern void _restgpr_23(void);
extern void fn_800718BC(void *child, u32 offset, void *arg1);

struct fn_800712E4_Tbl {
    u16 key;
    u16 value;
};

struct fn_800712E4_Child {
    u32 flags;
    u16 key;
    u16 pad_06;
    u32 field_08;
    u8 pad_0C[0x14];
};

struct fn_800712E4_Entry {
    u8 pad_00[0x18];
    u16 count;
    u8 pad_1A[0xA];
    u32 field_24;
};

struct fn_800712E4_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct fn_800712E4_Entry **entries;
};

struct fn_800712E4_Arg1 {
    u8 pad_00[4];
    u32 field_04;
};

void fn_800712E4(struct fn_800712E4_Arg0 *arg0, struct fn_800712E4_Arg1 *arg1,
                 struct fn_800712E4_Tbl *arg2) {
    struct fn_800712E4_Child *child;
    s32 inner;
    s32 offset;
    s32 i;
    s32 j;
    struct fn_800712E4_Entry *entry;
    struct fn_800712E4_Tbl *p;
    s32 idx;
    u16 v;

    i = 0;
    offset = 0;
    while (i < arg0->count) {
        entry = *(struct fn_800712E4_Entry **)((u8 *)arg0->entries + offset);
        if (entry != 0) {
            child = (struct fn_800712E4_Child *)((u8 *)entry + 0x40);
            j = 0;
            inner = 0;
            while (j < entry->count) {
                if (child->flags & 0x200000) {
                    v = child->key;
                    p = arg2;
                    idx = 0;
                    while (p->key != 0xFFFF) {
                        if (v == p->key) {
                            v = arg2[idx].value;
                            break;
                        }
                        p++;
                        idx++;
                    }
                    child->field_08 = entry->field_24 + inner;
                    fn_800718BC(child, arg1->field_04 + (v << 4), arg1);
                }
                child++;
                inner += 0x20;
                j++;
            }
        }
        offset += 8;
        i++;
    }
}

/* --- dol/fn_800713E0.c --- */
extern void fn_80071C04(void *, u32);

struct fn_800713E0_Entry {
    u8 pad_0[0x18];
    u16 count;
};

struct fn_800713E0_Arg0 {
    s32 count;
    u8 pad_4[0x4];
    struct fn_800713E0_Entry **entries;
};

void fn_800713E0(struct fn_800713E0_Arg0 *arg0, u32 arg1) {
    u8 *child;
    s32 offset;
    s32 i;
    s32 j;
    struct fn_800713E0_Entry *entry;

    i = 0;
    offset = 0;
    while (i < arg0->count) {
        entry = *(struct fn_800713E0_Entry **)((u8 *)arg0->entries + offset);
        if (entry != 0) {
            child = (u8 *)entry + 0x40;
            j = 0;
            while (j < entry->count) {
                fn_80071C04(child, arg1);
                child += 0x20;
                j++;
            }
        }
        offset += 8;
        i++;
    }
}

/* --- dol/fn_80071470.c --- */
struct fn_80071470_E16_u32 { u32 unk_0; u8 pad_4[0xC]; };
struct fn_80071470_Arg0 {
    u8 pad_0[0x8];
    struct fn_80071470_E16_u32 unk_8[1];
};

u32 fn_80071470(struct fn_80071470_Arg0 *arg0, u32 arg1) {
    return ((u32)arg0 + arg0->unk_8[arg1].unk_0);
}
