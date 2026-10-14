/* Non-matching: best partial attempt (94.08% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 unk_0;
    u8 pad_4;
    u8 value5;
    u8 pad_6;
    u8 flag7;
    u8 pad_8[0x81A0 - 0x8];
    u8 index_81A0;
    u8 pad_81A1[0x81A4 - 0x81A1];
    u8 field_81A4;
    u8 pad_81A5[0x81AC - 0x81A5];
    u8 field_81AC;
    u8 pad_81AD[0x81B4 - 0x81AD];
    u8 field_81B4;
    u8 pad_81B5[4];
} Sel;

typedef struct {
    u16 index;
    u8 pad_2[0x1E];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

typedef struct {
    s16 indices[3];
    u16 pad_6;
    u32 flags;
    u32 pad_C;
} Source;

typedef struct {
    s16 index;
    s16 sub;
    u32 count;
    u8 flag;
    u8 pad_53[3];
    u32 flags;
    Source src;
} Src;

typedef struct {
    u8 pad_0[0x324];
    s32 unk_324;
    u8 pad_328[0x390 - 0x328];
    u32 unk_390;
    u8 pad_394[0x3A0 - 0x394];
    u32 unk_3A0;
    u32 unk_3A4;
    u8 pad_3A8[0x3BA - 0x3A8];
    s16 unk_3BA;
    u8 pad_3BC[0x460 - 0x3BC];
} Msg;

typedef struct {
    void *unk_0;
    u8 unk_4;
    u8 pad_5[3];
    f32 unk_8;
    u32 unk_C;
    u8 pad_10[0x10420 - 0x10];
    u32 unk_10420;
    u32 unk_10424;
    void *unk_10428;
    void *unk_1042C;
} SelObj;

typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[4];
    Sel *unk_10;
    u8 pad_14[0x304 - 0x14];
    u16 unk_304;
    u8 pad_306[2];
    Msg *unk_308;
    Display *unk_30C;
} Bss;

extern const f32 lbl_17_rodata_18;
extern u32 lbl_17_data_0;
extern u8 lbl_17_bss_0[];
extern u32 lbl_801A6410;
extern u32 lbl_1_bss_6D82C;

extern void fn_80008BEC(void *, int, u32);
extern void fn_1_80058(s8, u8 *);
extern u32 fn_1_4630(u32, u32, u32, u32);
extern void fn_80006E10(u8 *);
extern void fn_1_14D728(Source *, Display *);
extern void DCFlushRange(void *, u32);
extern char *fn_1_7F518(s16, char *, s32);
extern int sprintf(char *, const char *, ...);
extern u32 fn_1_12A350(char *, u32);
extern void fn_1_12AB38(u8 *);
extern void *fn_1_12AC00(u8 *);
extern void fn_1_12A2B8(u32);
extern void fn_1_12A2D0(s32);
extern void fn_1_80294(void *, Msg *, u32);
extern u32 fn_1_12A734(u32);
extern u32 fn_1_81164(void *, u32, s16);
extern s32 fn_1_45D0(u32, u32, u32, u32);
extern u32 fn_1_7F254(void *, u32, void *, u32, void *, void *, u32);
extern void fn_1_FE004(void);
extern u32 fn_1_FD844(u32, void *);
extern void fn_1_FDEC8(void);
extern void fn_1_FDC00(void);

#pragma opt_common_subs off
static inline Display * fn_17_49DC_read_pointer(Bss * owner) { return owner->unk_30C; }
#pragma opt_lifetimes on
#pragma opt_propagation off
u32 fn_17_49DC(void) {
    Src s;
    struct { u8 *value; } strs;
    struct { Bss *value; } b;
    Sel *node;
    char text[0x20];
    char name[0x20];
    Sel *sub;
    void * lab_t0;

    strs.value = (u8 *)&lbl_17_data_0 + 0x60000;
    b.value = (Bss *)&lbl_17_bss_0;

    b.value->unk_304 = 0;
    node = b.value->unk_10;
    lab_t0 = (void *)&s;
    fn_80008BEC(lab_t0, 1, 0x20);
    fn_1_80058((s8)node->value5, (u8 *)&s);

    s.index = 0;
    s.sub = node->value5;
    s.count = 1;
    s.flag = 1;
    if ((s16)node->value5 >= 0x29) {
        sub = (Sel *)node->unk_0;
        if (sub != 0) {
            if ((sub->unk_0 & 0x80000000) != 0) {
                lab_t0 = (void *)&s.src;
                fn_80008BEC(lab_t0, 0, 0x10);
                if ((sub->unk_0 & 0x40000000) != 0) {
                    s.flags |= 0x04000000;
                    s.src.indices[0] = sub->field_81A4;
                    s.src.indices[1] = sub->field_81AC;
                    s.src.indices[2] = sub->field_81B4;
                } else {
                    s.sub = sub->index_81A0;
                }
                s.src.flags = s.count;
            }
        }
    }
    lab_t0 = (void *)&b.value->unk_308;
    fn_80008BEC(lab_t0, 0, 4);
    lab_t0 = (void *)&b.value->unk_30C;
    fn_80008BEC(lab_t0, 0, 4);

    if ((s.flags & 0x04000000) != 0) {
        b.value->unk_30C = (Display *)fn_1_4630(lbl_801A6410, 0xA20, (u32)(strs.value + 0x3E50), 0xB78);
        fn_80006E10(strs.value + 0x40F8);
        fn_1_14D728(&s.src, fn_17_49DC_read_pointer(b.value));
        fn_80006E10(strs.value + 0x4108);
        b.value->unk_308 = (Msg *)fn_1_4630(lbl_801A6410, 0x440, (u32)(strs.value + 0x3E50), 0xB7E);
        b.value->unk_308->unk_3BA = 0;
        b.value->unk_308->unk_3A0 = (u32)fn_17_49DC_read_pointer(b.value);
        b.value->unk_308->unk_390 = 0x04000000;
        b.value->unk_308->unk_324 = -1;
    } else {
        b.value->unk_308 = (Msg *)fn_1_4630(lbl_801A6410, 0x440, (u32)(strs.value + 0x3E50), 0xB87);
        b.value->unk_308->unk_3BA = 0;
        DCFlushRange((void *)b.value->unk_308, 0x460);
        fn_1_7F518(s.sub, name, 0);
        if (b.value->unk_308->unk_3BA == 1) {
            sprintf(text, (const char *)(strs.value + 0x410C), name);
        } else {
            sprintf(text, (const char *)(strs.value + 0x4120), name);
        }
        b.value->unk_308->unk_324 = (s32)fn_1_12A350(text, 1);
        if (lbl_1_bss_6D82C == 0) {
            fn_1_12AB38(strs.value + 0x4134);
            lbl_1_bss_6D82C = (u32)fn_1_12AC00(strs.value + 0x4140);
            fn_1_12AB38(strs.value + 0x4108);
        }
        fn_1_12A2B8(1);
        fn_1_12A2D0(b.value->unk_308->unk_324);
        fn_1_12AB38(strs.value + 0x4134);
        fn_1_80294((void *)&s, b.value->unk_308, 1);
        fn_1_12AB38(strs.value + 0x4108);
        fn_1_12A2B8(0);
        if (b.value->unk_308->unk_324 != -1) {
            fn_1_12A734((u32)b.value->unk_308->unk_324);
            b.value->unk_308->unk_324 = -1;
        }
        b.value->unk_308->unk_3A0 = 0;
        b.value->unk_308->unk_390 = 0;

{
    struct { u16 value; } kind;
        kind.value = 0;
        switch ((u32)(31 - __cntlzw(node->pad_6)) & 3) {
        case 0:
            break;
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
            kind.value = 0;
            break;
        }
        fn_1_81164((void *)b.value->unk_308, 0, kind.value);
}
    }

    node = (Sel *)node->unk_0;
    if (node != 0 && b.value->unk_308 != 0 && node->flag7 != 0
        && (node->unk_0 & 0x80000000) != 0 && (node->unk_0 & 0x40000000) == 0) {
        b.value->unk_8 = (u32)fn_1_45D0(lbl_801A6410, 0x10440, (u32)(strs.value + 0x3E50), 0xBE3);
        node->value5 = node->index_81A0;
        ((SelObj *)b.value->unk_8)->unk_10424 = 0;
        ((SelObj *)b.value->unk_8)->unk_10428 = (void *)fn_1_FDC00;
        ((SelObj *)b.value->unk_8)->unk_10420 = 0;
        ((SelObj *)b.value->unk_8)->unk_1042C = (void *)fn_1_FDEC8;
        ((SelObj *)b.value->unk_8)->unk_4 = 4;
        ((SelObj *)b.value->unk_8)->unk_8 = lbl_17_rodata_18;
        ((SelObj *)b.value->unk_8)->unk_0 = b.value->unk_308;
        ((SelObj *)b.value->unk_8)->unk_C = 0x20000000;
                    /* test */
    b.value->unk_308->unk_3A4 = fn_1_7F254((void *)node, 1, (void *)b.value->unk_8, 4, (void *)fn_1_FDEC8, (void *)fn_1_FDC00, 0);
        fn_1_FE004();
        fn_1_FD844((u32)node, (void *)b.value->unk_8);
    }
    return (u32)b.value;
}
#pragma opt_propagation reset

#pragma opt_lifetimes reset

#pragma opt_common_subs reset
