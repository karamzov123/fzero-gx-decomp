/* Non-matching: best partial attempt (97.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad0[0x24];
    void *field_24;
} EventData;

typedef struct {
    u8 pad0[0x12];
    u16 field_12;
    u8 pad14[0x12];
    u8 field_26;
    void *field_28;
    u8 pad2c[0x8];
    void *field_34;
    u8 pad38[0x14];
    u8 field_4c;
} EventNode;

typedef struct {
    u16 id;
    u8 pad2[6];
    EventData *data;
    void *strs;
    u8 pad10[0xc];
    s32 flag;
} Slot;

typedef struct {
    u8 pad0[0x1c];
    EventNode *node;
    u8 pad20[0x88 - 0x20];
    s32 field_88;
    u8 pad8c[0x148 - 0x8c];
    Slot slots[26];
} CarObject;

typedef struct {
    u16 a;
    u16 b;
    u32 c;
    char *name;
} TblEntry;

extern u32 lbl_1_data_209C0;

extern void fn_1_95158(CarObject *arg0);
extern void *fn_1_41418(void *arg0, u32 arg1);
extern s32 fn_1_97174(EventNode *arg0, s32 arg1, void *arg2);
extern void fn_1_93734(CarObject *arg0, void *arg1);
extern void fn_1_4270C(void *arg0, s32 arg1, u32 arg2);
extern int fn_1_41488(void *, const char *);
extern int sprintf(char *, const char *, ...);
extern char *fn_80083DB0(char *, const char *);
extern char *fn_80083970(const char *, const char *);

#define APPLY(S, ID, F)                                                        \
    do {                                                                       \
        if ((S) == &car->slots[0]) {                                           \
            EventNode *node = car->node;                                       \
            s32 value;                                                         \
            void *target;                                                      \
            fn_1_95158(car);                                                   \
            if (node != 0) {                                                   \
                value = fn_1_97174(node, 0, fn_1_41418((S)->data->field_24, (ID) & 0xffff)); \
                if (value < 0) {                                               \
                    value = 0;                                                 \
                }                                                              \
                node->field_12 = 0;                                            \
                if ((s32)node->field_26 > 0) {                                 \
                    target = node->field_28;                                   \
                } else {                                                       \
                    target = (void *)((u8 *)node->field_34 + -(s32)node->field_4c * 0xc); \
                }                                                              \
                *(u16 *)((u8 *)target + 0xa) = (u16)value;                     \
            }                                                                  \
            fn_1_93734(car, fn_1_41418((S)->strs, (ID) & 0xffff));             \
        }                                                                      \
        fn_1_4270C((S)->data, 0, (ID) & 0xffff);                               \
        (S)->id = (ID);                                                        \
        (S)->flag = (F);                                                       \
    } while (0)

void fn_1_93734(CarObject *car, void *name) {
    char *base = (char *)&lbl_1_data_209C0;
    char buf[0x40];
    char buf2[0x40];
    Slot *sa = &car->slots[2];
    Slot *sb;
    Slot *sc;
    Slot *sd;
    Slot *se;
    CarObject *p;
    s32 i;
    u32 id;

    if (sa->data != 0 && sa->strs != 0) {
        sprintf(buf, base + 0x719c, name);
        id = fn_1_41488(sa->data->field_24, buf);
        if (id != -1) {
            APPLY(sa, id, 1);
        } else {
            fn_80083DB0(buf, base + 0x6ea4);
            id = fn_1_41488(sa->data->field_24, buf);
            if (id == -1) {
                APPLY(sa, 0, 0);
            } else {
                APPLY(sa, id, 1);
            }
        }
    }

    sb = &car->slots[1];
    if (sb->data != 0 && sb->strs != 0) {
        sprintf(buf, base + 0x71a8, name);
        id = fn_1_41488(sb->data->field_24, buf);
        if (id != -1) {
            APPLY(sb, id, 1);
        } else {
            fn_80083DB0(buf, base + 0x6e9c);
            id = fn_1_41488(sb->data->field_24, buf);
            if (id == -1) {
                id = 0;
            }
            APPLY(sb, id, 0);
        }
    }

    sc = &car->slots[3];
    if (sc->data != 0 && sc->strs != 0) {
        sprintf(buf, base + 0x71b0, name);
        if (fn_80083970(name, base + 0x71b8) != 0 && car->field_88 != 0x2c) {
            if ((u32)fn_1_41488(sc->data->field_24, buf) == -1) {
                sprintf(buf, base + 0x71bc, base + 0x6390);
            }
        }
        id = fn_1_41488(sc->data->field_24, buf);
        if (id != -1) {
            APPLY(sc, id, 1);
        } else {
            APPLY(sc, 0, 0);
        }
    }

    sd = &car->slots[4];
    if (sd->data != 0 && sd->strs != 0) {
        sprintf(buf, base + 0x71cc, name);
        id = fn_1_41488(sd->data->field_24, buf);
        if (id != -1) {
            APPLY(sd, id, 1);
        } else {
            APPLY(sd, 0, 0);
        }
    }

    se = &car->slots[5];
    if (se->data != 0 && se->strs != 0) {
        sprintf(buf, base + 0x71d4, name);
        id = fn_1_41488(se->data->field_24, buf);
        if (id != -1) {
            APPLY(se, id, 1);
        } else {
            APPLY(se, 0, 0);
        }
    }

    p = car;
    for (i = 0; i < 20; i++, p = (CarObject *)((u8 *)p + 0x20)) {
        Slot *s = &p->slots[6];
        if (s->data != 0 && s->strs != 0) {
            TblEntry *e = (TblEntry *)(base + 0x6b14);
            char *str = 0;
            s32 n = *(u32 *)(base + 0x6e2c);
            s32 j;
            for (j = 0; j < n; j++) {
                if ((u32)car->field_88 == e[j].a && (u32)i == e[j].b) {
                    str = e[j].name;
                    break;
                }
            }
            fn_80083DB0(buf2, str);
            if (buf2[0] != 0) {
                sprintf(buf, base + 0x71dc, name, buf2);
                id = fn_1_41488(s->data->field_24, buf);
                if (id != -1) {
                    APPLY(s, id, 1);
                } else {
                    APPLY(s, 0, 0);
                }
            }
        }
    }
}
