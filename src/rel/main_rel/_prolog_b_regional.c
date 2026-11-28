/* Previously matched Japan/PAL units of _prolog_b.c, retained until that TU matches those releases as one unit. */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "dolphin/hw_regs.h"



typedef struct {
    s8 x;
    s8 y;
} StickPoint;

typedef struct InputAxes {
    s8 stickX;
    s8 stickY;
    s8 substickX;
    s8 substickY;
    u8 triggerLeft;
    u8 triggerRight;
    u8 analogA;
    u8 analogB;
} InputAxes;

typedef struct InputPortAxes {
    InputAxes unk_0;
    InputAxes unk_8;
} InputPortAxes;

typedef struct InputPad {
    u16 button;
    s8 stickX;
    s8 stickY;
    s8 substickX;
    s8 substickY;
    u8 triggerLeft;
    u8 triggerRight;
    u8 analogA;
    u8 analogB;
    s8 err;
} InputPad;

typedef struct InputButtons {
    u16 button;
    u16 unk_2;
} InputButtons;

typedef struct InputPortButtons {
    InputButtons unk_0;
    InputButtons unk_4;
    InputButtons unk_8;
    InputButtons unk_C;
    InputButtons unk_10;
} InputPortButtons;

typedef struct InputControl {
    u8 unk_0;
    s8 unk_1;
    s8 unk_2;
    s8 unk_3;
    u8 unk_4;
    u8 unk_5;
} InputControl;

typedef struct Sig_fn_8001CF80_PADStatus {
    u16 button;
    s8 stickX;
    s8 stickY;
    s8 substickX;
    s8 substickY;
    u8 triggerLeft;
    u8 triggerRight;
    u8 analogA;
    u8 analogB;
    s8 err;
} Sig_fn_8001CF80_PADStatus;

typedef struct fn_1_426C_Node {
    u32 field_0;
    u32 field_4;
    u8 pad_8[0x10];
    void (*callback)(u32, u32);
    u8 pad_1c[0x8];
} fn_1_426C_Node;

typedef struct fn_1_426C_Manager {
    u32 field_0;
    fn_1_426C_Node *nodes;
} fn_1_426C_Manager;

typedef struct fn_1_3CF0_Node fn_1_3CF0_Node;

struct fn_1_3CF0_Node {
    void (*func)(void);
    u32 unk_4;
    struct fn_1_3CF0_Node *next;
    struct fn_1_3CF0_Node *prev;
    u32 id;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    void *data;
};

struct fn_1_3CF0_Mgr {
    struct fn_1_3CF0_Node *free_list;
    struct fn_1_3CF0_Node *fixed;
    u32 unk_8;
    u32 count;
    u32 unk_10;
    u32 unk_14;
    struct fn_1_3CF0_Node *slots[32];
    struct fn_1_3CF0_Node nodes[32];
};

struct fn_1_3C98_lbl_1_bss_DA5 {
    u8 unk_0;
};

struct fn_1_48B0_lbl_801A6CF8 {
    u32 unk_0;
};

struct fn_1_44B4_lbl_1_bss_DB8 {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
};

struct fn_1_451C_lbl_1_bss_DB8 {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
};

struct fn_1_4438_lbl_1_bss_DC4 {
    u32 unk_0;
};

struct fn_1_1FE8_Arg1 {
    s8 unk_0; s8 unk_1; s8 unk_2; s8 unk_3;
    u8 unk_4; u8 unk_5; u8 unk_6; u8 unk_7;
};

struct fn_1_3CF0_lbl_1_data_2B80 {
    u8 pad_0[0x18];
    void *unk_18;
    char message[0x28];
    u8 unk_44[0xAC];
};

typedef struct fn_1_4374_Node fn_1_4374_Node;

struct fn_1_4374_Node {
    u32 field_0;
    u32 field_4;
    fn_1_4374_Node *next;
    fn_1_4374_Node *prev;
};

struct fn_1_4404_lbl_1_bss_DC0 {
    u32 unk_0;
};

typedef struct {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Fn1_4730Entry;
extern void fn_1_15665C(void *owner, s32 index);
extern void fn_1_156730(s32 index);
extern void fn_1_D332C(u16 *data);
extern void fn_80008BA8(void *dst, void *src, u32 size);
extern void PADRead(void *);
extern u32 SIProbe(s32 chan);
extern s32 fn_8006B294(s32 index, u32 *out);
extern void fn_8006B470(void *);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern BOOL PADRecalibrate(u32 mask);
extern int PADReset(u32 mask);
extern void *OSGetArenaLo(void);
extern void *OSGetArenaHi(void);
extern void OSSetArenaLo(void *addr);
extern u16 lbl_1_bss_990[28];
extern u8 lbl_1_bss_D78;
extern u8 lbl_1_bss_DA6;
extern u32 lbl_1_bss_DB0[2];
extern u32 lbl_1_bss_DA8;
extern void fn_1_43A4(void);
extern u32 lbl_1_data_2C70;
extern int fn_80008E84();
extern u32 lbl_1_bss_DAC;
extern void fn_8006FFC4(u32 arg0);
extern void fn_1_48780(void);
extern u32 lbl_801A66B4;
extern u32 lbl_801A66BC;
extern u16 lbl_1_bss_96A;
extern void fn_1_37E98(void);
extern u32 lbl_1_bss_96C;
extern void camera_set_state_flag(u8 value);
extern void fn_1_D31E0(void);
extern u32 lbl_1_data_2A20;
extern u32 lbl_1_data_7C0;
extern void fn_1_15659C();
extern u8 lbl_1_bss_978[];
extern u32 lbl_1_data_2B78;
extern u32 OSGetTick();
extern u32 lbl_1_bss_D7C;
extern u8 lbl_1_bss_DA4;
extern char lbl_1_data_2C9C[20];
extern char lbl_1_data_2CB0[31];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void fn_80009AA8(int heap, void *ptr, const char *file, int line);
extern void fn_1_156754(s32 index);
extern void fn_1_A5864(void);
extern void fn_1_F7578(void);
extern struct fn_1_3C98_lbl_1_bss_DA5 lbl_1_bss_DA5;
extern void *fn_80008EC8(void *arenaStart, void *arenaEnd, int maxHeaps);
extern u32 fn_800793D4(u8 *arg0, u32 arg1, u32 arg2);
extern struct fn_1_48B0_lbl_801A6CF8 lbl_801A6CF8;
extern u32 lbl_801A6CFC;
extern struct fn_1_44B4_lbl_1_bss_DB8 lbl_1_bss_DB8;
extern struct fn_1_4438_lbl_1_bss_DC4 lbl_1_bss_DC4;
extern u8 lbl_1_bss_8E6B0[308];
extern void fn_1_14FCE4(u32 arg0, s16 arg1);
extern u8 lbl_1_bss_AA0[336];
extern u8 lbl_1_rodata_108[88];
extern void fn_1_3BDC(u32 arg0);
extern u32 fn_1_3C18(s32);
extern u8 lbl_1_rodata_C4[60];
extern s32 fn_1_3EFA8(void);
extern u8 fn_1_3BB0(u32);
extern u32 fn_1_1DF0(u16 *, s8 *, u32);
extern s8 fn_1_1FE8(u16 *, struct fn_1_1FE8_Arg1 *, u32, s8);
extern void fn_1_1304(Sig_fn_8001CF80_PADStatus *pads);
extern void PADClamp(InputPad *pads);
extern void fn_1_1C00(const u8 *values, u32 flags, u16 *result);
extern u32 fn_1_3FC28(void);
extern void fn_1_21E4(InputAxes *axes);
extern void fn_1_F2820(InputControl *controls, u8 *newly, u8 *previous);
extern void fn_1_2F04(void);
extern u32 lbl_1_data_2B68[4];
extern u8 lbl_1_data_2B64;
extern u8 fn_1_D357C(void);
extern struct fn_1_3CF0_lbl_1_data_2B80 lbl_1_data_2B80;
extern void OSReport(const char *msg, ...);
extern void fn_1_4370(void);
extern void fn_1_4374(fn_1_4374_Node **list, fn_1_4374_Node *node);
extern struct fn_1_4404_lbl_1_bss_DC0 lbl_1_bss_DC0;
extern int fn_80008F60(void *start, void *end);
extern void fn_1_481E8(int arg0);
extern u32 fn_1_566DC(void);
extern void fn_80009064(int heap);
extern long fn_80009FA4(int heap);
extern void fn_80077848(void);
extern u32 fn_8007785C(u32 count, s32 useArena);
extern long fn_800090A4(int heap);
extern void * fn_80009830();
extern u32 lbl_1_data_2C74;
extern Fn1_4730Entry lbl_1_bss_DCC[32];

/* fzgx:begin fn_1_3B34 */
void fn_1_3B34(void) {
    u32 i;

    fn_80008BEC(lbl_1_bss_AA0, 0, 0x150);
    i = 0;
    do {
        fn_80008BA8(lbl_1_bss_AA0 + i * 0x54, lbl_1_rodata_108, 0x54);
        i++;
    } while (i < 4);
}
/* fzgx:end fn_1_3B34 */

/* fzgx:begin fn_1_3BB0 */
u8 fn_1_3BB0(u32 arg0) {
    return *((u8 *)&lbl_1_data_2B78 + arg0);
}
/* fzgx:end fn_1_3BB0 */

/* fzgx:begin fn_1_3BC0 */
void fn_1_3BC0(void) {
    lbl_1_bss_990[0] = 0;
    lbl_1_bss_990[1] = 0;
    lbl_1_bss_990[2] = 0;
    lbl_1_bss_990[3] = 0;
}
/* fzgx:end fn_1_3BC0 */

/* fzgx:begin fn_1_3BDC */
void fn_1_3BDC(u32 arg0) {
    u32 t0;
    t0 = OSGetTick(arg0);
    *(u32 *)((u8 *)&lbl_1_bss_D7C + (arg0 << 2)) = t0;
}
/* fzgx:end fn_1_3BDC */

/* fzgx:begin fn_1_3C18 */
/* Milliseconds elapsed since the tick stored in slot arg0. */
u32 fn_1_3C18(volatile s32 arg0) /* volatile: retail spills the slot index to the frame across OSGetTick */
{
    return ((OSGetTick() - ((u32 *)(((u8 *)&lbl_1_bss_D7C)))[arg0]) * 8) / (OS_TIMER_CLOCK / 125000);
}
/* fzgx:end fn_1_3C18 */

/* fzgx:begin fn_1_3C78 */
void fn_1_3C78(void) {
    if (lbl_1_bss_D78 == 0) { return; }
    lbl_1_bss_DA4 = 0;
}
/* fzgx:end fn_1_3C78 */

/* fzgx:begin fn_1_3C98 */
void fn_1_3C98(void) {
    if (lbl_1_bss_D78 == 0) { return; }
    if (lbl_1_bss_DA5.unk_0 != 0) { return; }
    lbl_1_bss_DA5.unk_0 = 1;
}
/* fzgx:end fn_1_3C98 */

/* fzgx:begin fn_1_3CC4 */
void fn_1_3CC4(void) {
    if (lbl_1_bss_D78 == 0) {
        return;
    }
    if (lbl_1_bss_DA6 == 0) {
        lbl_1_bss_DA6 = 1;
    }
}
/* fzgx:end fn_1_3CC4 */

/* fzgx:begin fn_1_3CF0 */
/* 0x24-byte work node: 32 fixed nodes follow the manager, then `count` extra nodes */




#pragma opt_propagation off
static inline void fn_1_3CF0_init_fixed(struct fn_1_3CF0_Mgr *mgr, struct fn_1_3CF0_Node *nodes, struct fn_1_3CF0_lbl_1_data_2B80 *data, u32 j) {
    struct fn_1_3CF0_Node *fixed_e;
    for (fixed_e = nodes; j < 32; j++, fixed_e++) {
        mgr->slots[0] = fixed_e;
        mgr = (struct fn_1_3CF0_Mgr *)((u8 *)mgr + 4);
        fixed_e->func = fn_1_4370;
        fixed_e->unk_18 = 0;
        fixed_e->next = NULL;
        fixed_e->prev = NULL;
        fixed_e->id = j;
        fixed_e->unk_14 = 0;
        fixed_e->data = data->unk_18;
    }
}
void fn_1_3CF0(struct fn_1_3CF0_Mgr *buf, u32 count) {
    struct fn_1_3CF0_lbl_1_data_2B80 *data = &lbl_1_data_2B80;
    struct fn_1_3CF0_Node *fixed_e;
    struct fn_1_3CF0_Node *e;
    struct fn_1_3CF0_Mgr *mgr;
    u32 j;
    struct fn_1_3CF0_Node *prev;
    struct fn_1_3CF0_Node *nodes;
    u32 i;

    if (count == 0) {
        OSReport(data->message);
    }
    (*((struct fn_1_3CF0_Mgr * *)&lbl_1_bss_DAC)) = buf;
    mgr = buf;
    buf->unk_8 = 0;
    nodes = buf->nodes;
    if (count == 0) {
        buf->free_list = NULL;
    } else {
        buf->free_list = &nodes[32];
    }
    buf++;
    mgr->fixed = nodes;
    mgr->count = count;
    mgr->unk_10 = 0;
    mgr->unk_14 = 0;

    /* extra nodes: a doubly linked free list */
    prev = NULL;
    for (i = 32, e = &nodes[32]; i < count + 32; i++, e++) {
        e->func = NULL;
        e->unk_18 = 0;
        e->unk_4 = 0;
        e->id = i;
        e->prev = prev;
        e->next = e + 1;
        e->unk_14 = 0;
        e->data = data->unk_44;
        prev = e;
    }
    nodes[count + 31].next = NULL;

    /* fixed nodes */
    fn_1_3CF0_init_fixed(mgr, nodes, data, 0);
}
/* fzgx:end fn_1_3CF0 */

/* fzgx:begin fn_1_3F8C */
typedef struct Fn1_3F8C_Entry Fn1_3F8C_Entry;

struct Fn1_3F8C_Entry {
    void *func;
    void *arg;
    Fn1_3F8C_Entry *next;
    Fn1_3F8C_Entry *prev;
    s32 result;
    u32 stamp;
    u32 reserved18;
    u32 reserved1c;
    char *name;
};

typedef struct Fn1_3F8C_Table {
    Fn1_3F8C_Entry *head;
    u8 entries[0x14];
} Fn1_3F8C_Table;

// Retrieves an entry from the free list and links it into the indexed list.
s32 fn_1_3F8C(char *name, void *func, void *arg, u32 priority) {
    Fn1_3F8C_Table *table = (Fn1_3F8C_Table *)lbl_1_bss_DAC;
    Fn1_3F8C_Entry *entry = table->head;
    u8 *slot;
    Fn1_3F8C_Entry *link;

    if (entry == 0) {
        return -1;
    }

    table->head = entry->next;
    slot = (u8 *)table + priority * 4;
    link = *(Fn1_3F8C_Entry **)(slot + 0x18);
    entry->next = link->next;
    entry->prev = *(Fn1_3F8C_Entry **)(slot + 0x18);
    entry->arg = arg;
    entry->func = func;
    entry->reserved18 = 0;
    entry->reserved1c = 0;
    entry->name = name;
    entry->stamp = lbl_1_bss_DB0[0];

    if (entry->next != 0) {
        entry->next->prev = entry;
    }

    link = *(Fn1_3F8C_Entry **)(slot + 0x18);
    link->next = entry;
    return entry->result;
}
/* fzgx:end fn_1_3F8C */

/* fzgx:begin fn_1_4010 */
// Store a value in the indexed entry of the active table.
u32 fn_1_4010(u32 arg0, u32 arg1) {
    u32 *table = (u32 *)lbl_1_bss_DAC;
    u8 *entry = (u8 *)table[1] + arg0 * 36;

    *(u32 *)(entry + 24) = arg1;
    return (u32)entry;
}
/* fzgx:end fn_1_4010 */

/* fzgx:begin fn_1_4030 */
struct fn_1_4030_lbl_1_bss_DA8 {
    u32 unk_0;
};

u32 fn_1_4030(u32 arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    v0 = *(u32 *)((*(struct fn_1_4030_lbl_1_bss_DA8 *)&lbl_1_bss_DA8).unk_0 + 8);
    v1 = *(u32 *)(v0);
    v2 = arg0;
    if (v1 == 0) {
    v2 = 0;
    return v2;
    }
    *(u32 *)((u8 *)v0 + 0) = v2;
    v2 = v1;
    return v2;
}
/* fzgx:end fn_1_4030 */

/* fzgx:begin fn_1_4060 */
u32 fn_1_4060(void) {
    u32 *base;
    u32 *slot;

    base = (u32 *)lbl_1_bss_DA8;
    slot = *(u32 **)((u8 *)base + 8);
    *slot = 0;
    return (u32)slot;
}
/* fzgx:end fn_1_4060 */

/* fzgx:begin fn_1_407C */
typedef u32 (*fn_1_407C_Fn0)(u32);
struct fn_1_407C_lbl_1_bss_DAC {
    s32 unk_0;
};
struct fn_1_407C_lbl_1_bss_DA8 {
    u32 unk_0;
};


void fn_1_407C(s32 arg_sp0) {
    u32 var_r31;
    u32 temp_r30;
    s32 temp_r29;
    u8 temp_r28;
    s32 var_r27;
    void *var_r24;
    s32 (*temp_r23)(s32);

    var_r27 = 0;
    temp_r30 = (*(struct fn_1_407C_lbl_1_bss_DAC *)&lbl_1_bss_DAC).unk_0;
    var_r31 = temp_r30;
    temp_r29 = *(s32 *)((temp_r30) + 16);
    temp_r28 = (*(s32 *)((temp_r30) + 20));
    do {
        if (!(temp_r29 & (1 << var_r27))) {
            var_r24 = (*(void **)((u8 *)((*(void **)((var_r31) + 24))) + 8));
            while (var_r24 != NULL) {
                temp_r23 = (s32 (*)(s32))(*(s32 (**)(s32))(var_r24));
                (*(void **)((temp_r30) + 8)) = var_r24;
                (*(struct fn_1_407C_lbl_1_bss_DAC *)&lbl_1_bss_DAC).unk_0 = temp_r30;
                (*(struct fn_1_407C_lbl_1_bss_DA8 *)&lbl_1_bss_DA8).unk_0 = temp_r30;
                if (((temp_r28 == 0) || ((u8) (temp_r28 & (*(s32 *)((u8 *)(var_r24) + 20))) != 0)) && (temp_r23 != NULL)) {
                    fn_1_3BDC(5U);
                    temp_r23(*(s32 *)((u8 *)(var_r24) + 4));
                    (*(s32 *)((u8 *)(var_r24) + 28)) = ((*(s32 *)((u8 *)(var_r24) + 28)) + fn_1_3C18(5));
                }
                (*(struct fn_1_407C_lbl_1_bss_DAC *)&lbl_1_bss_DAC).unk_0 = temp_r30;
                (*(struct fn_1_407C_lbl_1_bss_DA8 *)&lbl_1_bss_DA8).unk_0 = temp_r30;
                if ((*(void **)((temp_r30) + 8)) == var_r24) {
                    var_r24 = (*(void **)((u8 *)(var_r24) + 8));
                    if (temp_r23 == NULL) {
                        fn_1_43A4();
                    }
                } else {
                    var_r24 = NULL;
                }
                            }
        }
        var_r27 += 1;
        var_r31 += 4;
    } while (var_r27 < 0x20);
    (*(void **)((temp_r30) + 8)) = NULL;
    (*(struct fn_1_407C_lbl_1_bss_DAC *)&lbl_1_bss_DAC).unk_0 = temp_r30;
    (*(struct fn_1_407C_lbl_1_bss_DA8 *)&lbl_1_bss_DA8).unk_0 = 0;
}
/* fzgx:end fn_1_407C */

/* fzgx:begin fn_1_41A8 */
typedef struct fn_1_41A8_Node fn_1_41A8_Node;
struct fn_1_41A8_Node {
    u32 field_0;
    void *field_4;
    fn_1_41A8_Node *next;
    u32 field_c;
    u32 field_10;
    u32 field_14;
    void (*callback)(void *, u32);
};

typedef struct List List;
struct List {
    u32 field_0;
    u32 field_4;
    fn_1_41A8_Node *head;
};

typedef struct fn_1_41A8_Manager fn_1_41A8_Manager;
struct fn_1_41A8_Manager {
    u32 field_0;
    u32 field_4;
    fn_1_41A8_Node *head;
};

void fn_1_41A8(void) {
    fn_1_41A8_Manager *entry;
    fn_1_41A8_Manager *manager;
    u32 *dac;
    u32 *da8;
    int i;
    fn_1_41A8_Node *node;
    void (*callback)(void *, u32);

    dac = &lbl_1_bss_DAC;
    manager = (fn_1_41A8_Manager *)*dac;
    if (manager != 0) {
        da8 = &lbl_1_bss_DA8;
        entry = manager;
        i = 0;
        while (i < 32) {
            node = (*(List **)((u8 *)entry + 0x18))->head;
            while (node != 0) {
                callback = node->callback;
                manager->head = node;
                *dac = (u32)manager;
                *da8 = (u32)manager;
                if (callback != 0) {
                    callback(node->field_4, 1);
                }
                *dac = (u32)manager;
                *da8 = (u32)manager;
                node = node->next;
                fn_1_43A4();
            }
            i++;
            entry = (fn_1_41A8_Manager *)((u8 *)entry + 4);
        }
        manager->head = 0;
        lbl_1_bss_DAC = (u32)manager;
        lbl_1_bss_DA8 = 0;
    }
}
/* fzgx:end fn_1_41A8 */

/* fzgx:begin fn_1_426C */
#pragma opt_propagation off
void fn_1_426C(u32 arg0) {
    fn_1_426C_Manager *mgr = (*((fn_1_426C_Manager * *)&lbl_1_bss_DAC));
    fn_1_426C_Node *node = &mgr->nodes[arg0];
    void (*callback)(u32, u32);

    if (arg0 < 32 || node->field_0 == 0) {
        return;
    }

    callback = node->callback;
    if (callback != NULL) {
        fn_1_426C_Manager *saved = (*((fn_1_426C_Manager * *)&lbl_1_bss_DA8));
        (*((fn_1_426C_Manager * *)&lbl_1_bss_DA8)) = mgr;
        callback(node->field_4, 1);
        (*((fn_1_426C_Manager * *)&lbl_1_bss_DAC)) = mgr;
        (*((fn_1_426C_Manager * *)&lbl_1_bss_DA8)) = saved;
    }
    fn_1_4374( (fn_1_4374_Node **)(fn_1_426C_Manager *)(mgr), (fn_1_4374_Node *)(fn_1_426C_Node *)(node));
}
#pragma opt_propagation reset
/* fzgx:end fn_1_426C */

/* fzgx:begin fn_1_4404 */
void fn_1_4404(void) {
    u32 t0;
    t0 = ((u32)fn_80008E84(lbl_1_bss_DC0.unk_0));
    lbl_1_data_2C70 = t0;
}
/* fzgx:end fn_1_4404 */

/* fzgx:begin fn_1_4438 */
void fn_1_4438(void) {
    u32 t0;
    t0 = ((u32)fn_80008E84(lbl_1_bss_DC4.unk_0));
    lbl_1_data_2C70 = t0;
}
/* fzgx:end fn_1_4438 */

/* fzgx:begin fn_1_446C */
void fn_1_446C(void) {
    fn_80008E84(lbl_1_data_2C70);
    lbl_1_data_2C70 = (u32)-1;
}
/* fzgx:end fn_1_446C */

/* fzgx:begin fn_1_44A4 */
struct fn_1_44A4_lbl_1_bss_DC4 {
    u32 unk_0;
};

u32 fn_1_44A4(void) {
    return (*(struct fn_1_44A4_lbl_1_bss_DC4 *)&lbl_1_bss_DC4).unk_0;
}
/* fzgx:end fn_1_44A4 */

/* fzgx:begin fn_1_44B4 */
void fn_1_44B4(void) {
    struct fn_1_44B4_lbl_1_bss_DB8 *p_lbl_1_bss_DB8;
    u32 t0, t1, t2, t3;
    p_lbl_1_bss_DB8 = (struct fn_1_44B4_lbl_1_bss_DB8 *)&lbl_1_bss_DB8;
    t0 = ((u32)OSGetArenaHi());
    t1 = ((u32)OSGetArenaLo());
    t2 = ((u32)fn_80008EC8( (void *)(u32)(t1), (void *)(u32)(t0), 8));
    p_lbl_1_bss_DB8->unk_10 = t2;
    t3 = ((u32)fn_80008F60( (void *)(u32)(t2), (void *)(u32)(((t2 + 0xE0000) - 2848))));
    p_lbl_1_bss_DB8->unk_C = t3;
    p_lbl_1_bss_DB8->unk_8 = -1;
}
/* fzgx:end fn_1_44B4 */
