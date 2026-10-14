/* Non-matching: best partial attempt (66.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

typedef struct Tbl Tbl;
typedef struct Data { u8 pad0[0x24]; Tbl *tbl; } Data;
typedef struct Slot {
    u16 id;
    u8 pad2[6];
    Data *data;
    void *unk_c;
    u8 pad10[0xc];
    int flag;
} Slot;
typedef struct Slot2 { u8 pad0[0xa]; u16 field_a; } Slot2;
typedef struct Node {
    u8 pad0[0xa];
    u16 field_a;
    u8 pad_c[6];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    u8 pad27[1];
    Slot2 *field_28;
    u8 pad2c[8];
    Slot2 *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} Node;
typedef struct Car {
    u8 pad0[0x1c];
    Node *node;
    u8 pad20[0x88 - 0x20];
    int field_88;
    u8 pad8c[0x148 - 0x8c];
    Slot slots[26];
} Car;

typedef struct Ent { u16 a; u16 b; char *name; } Ent;

extern u32 lbl_1_data_209C0;
extern u32 fn_1_41488(Tbl *, const char *);
extern char *fn_1_41418(void *, u32);
extern int fn_1_97174(Node *, void *, void *);
extern void fn_1_943F8(Car *, char *, f32);
extern void fn_1_42AD0(Data *, void *, u32, u32, u16);
extern void fn_1_95158(Car *);
extern u32 fn_1_93734(Car *, char *);
extern void fn_1_4270C(Data *, void *, u32);
extern int sprintf(char *, const char *, ...);
extern char *fn_80083DB0(char *, const char *);
extern u8 *fn_80083970(u8 *, const u8 *);

static inline void setnode(Node *n, void *str)
{
    int r = fn_1_97174(n, 0, str);
    Slot2 *s;
    if (r < 0) r = 0;
    n->field_12 = 0;
    if ((int)n->field_26 > 0) {
        s = n->field_28;
    } else {
        s = (Slot2 *)((u8 *)n->field_34 + (-(int)n->field_4c) * 0xc);
    }
    s->field_a = (u16)r;
}

static inline void do1(Car *car, Slot *s, u32 idx, f32 f, int flag)
{
    u16 flags = 0;
    if (s == &car->slots[0]) {
        Node *n = car->node;
        if (n) setnode(n, fn_1_41418(s->data->tbl, (u16)idx));
        fn_1_943F8(car, fn_1_41418(s->unk_c, (u16)idx), f);
    }
    if (f > 50.0f) flags |= 0xc0; else flags |= 0x60;
    fn_1_42AD0(s->data, 0, (u16)idx, (s32)f, flags);
    s->id = idx;
    s->flag = flag;
}

static inline void do2(Car *car, Slot *s, char *buf)
{
    u32 idx = fn_1_41488(s->data->tbl, buf);
    if (idx != 0xFFFFFFFF) {
        if (s == &car->slots[0]) {
            Node *n = car->node;
            fn_1_95158(car);
            if (n) setnode(n, fn_1_41418(s->data->tbl, (u16)idx));
            fn_1_93734(car, fn_1_41418(s->unk_c, (u16)idx));
        }
        fn_1_4270C(s->data, 0, (u16)idx);
        s->id = idx;
        s->flag = 1;
    } else {
        if (s == &car->slots[0]) {
            Node *n = car->node;
            fn_1_95158(car);
            if (n) setnode(n, fn_1_41418(s->data->tbl, 0));
            fn_1_93734(car, fn_1_41418(s->unk_c, 0));
        }
        fn_1_4270C(s->data, 0, 0);
        s->id = 0;
        s->flag = 0;
    }
}

#define BASE ((u8 *)&lbl_1_data_209C0)

void fn_1_943F8(Car *car, char *name, f32 f)
{
    u8 *d = BASE;
    Slot *s;
    char buf[0x40];
    char nm[0x40];
    u32 idx;
    int i;

    s = &car->slots[2];
    if (s->data && s->unk_c) {
        sprintf(buf, (char *)(d + 0x719c), name);
        idx = fn_1_41488(s->data->tbl, buf);
        if (idx != 0xFFFFFFFF) {
            do1(car, s, idx, f, 1);
        } else {
            fn_80083DB0(buf, (char *)(d + 0x6ea4));
            idx = fn_1_41488(s->data->tbl, buf);
            if (idx == 0xFFFFFFFF) idx = 0;
            do1(car, s, idx, f, 0);
        }
    }

    s = &car->slots[1];
    if (s->data && s->unk_c) {
        sprintf(buf, (char *)(d + 0x71a8), name);
        idx = fn_1_41488(s->data->tbl, buf);
        if (idx != 0xFFFFFFFF) {
            do1(car, s, idx, f, 1);
        } else {
            fn_80083DB0(buf, (char *)(d + 0x6e9c));
            idx = fn_1_41488(s->data->tbl, buf);
            if (idx == 0xFFFFFFFF) idx = 0;
            do1(car, s, idx, f, 0);
        }
    }

    s = &car->slots[3];
    if (s->data && s->unk_c) {
        sprintf(buf, (char *)(d + 0x71b0), name);
        if (fn_80083970((u8 *)name, (u8 *)(d + 0x71b8)) && car->field_88 != 0x2c) {
            if (fn_1_41488(s->data->tbl, buf) == 0xFFFFFFFF) {
                sprintf(buf, (char *)(d + 0x71bc), d + 0x6390);
            }
        }
        do2(car, s, buf);
    }

    s = &car->slots[4];
    if (s->data && s->unk_c) {
        sprintf(buf, (char *)(d + 0x71cc), name);
        do2(car, s, buf);
    }

    s = &car->slots[5];
    if (s->data && s->unk_c) {
        sprintf(buf, (char *)(d + 0x71d4), name);
        do2(car, s, buf);
    }

    for (i = 0; i < 20; i++) {
        s = &car->slots[6 + i];
        if (s->data && s->unk_c) {
            Ent *e = (Ent *)(d + 0x6b14);
            char *nn = 0;
            u32 cnt = *(u32 *)(d + 0x6e2c);
            u32 j;
            for (j = 0; j < cnt; j++) {
                if (car->field_88 == e[j].a && i == e[j].b) {
                    nn = e[j].name;
                    break;
                }
            }
            fn_80083DB0(nm, nn);
            if (nm[0]) {
                sprintf(buf, (char *)(d + 0x71dc), name, nm);
                do2(car, s, buf);
            }
        }
    }
}
