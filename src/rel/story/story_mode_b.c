#include "types.h"
#include "font.h"

typedef struct GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
} Vec;

/* the course of the current scenario (lbl_7_bss_1964) */
typedef struct StoryCourse {
    u32 flags;
    u8 pad_4[0x8];
    u8 unk_C;
    u8 unk_D;
} StoryCourse;

/* one scenario trigger: type 0..3 are conditions, 4 is an action, 5 ends the list */
typedef struct StoryTrigger {
    u16 type;
    u16 opcode;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    f32 unk_14;
} StoryTrigger;

/* scenario state passed in by story_mode.c: 0x200 bytes of trigger flags, then counters */
typedef struct StoryContext {
    u32 done[0x80];
    s32 timers[8];
    s32 counters[8];
    u32 flags240;
    u32 flags244;
    s16 unk_248;
} StoryContext;


typedef struct StoryVehicle {
    u32 flags;
    u8 pad_4[0x78];
    Vec pos;
    u8 pad_88[0xF4];
    f32 unk_17C;
    u8 pad_180[4];
    f32 unk_184;
    u8 pad_188[0x2FA];
    u8 unk_482;
} StoryVehicle;

typedef struct StoryEventObject {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x44];
    Vec pos;
    u8 pad_60[0xD8];
    u32 flags138;
    u32 flags13C;
} StoryEventObject;

typedef struct StoryTime {
    u8 pad_0[0x1EC];
    u8 minutes;
    u8 seconds;
    u16 milliseconds;
} StoryTime;

typedef struct StoryPlayer {
    u8 pad_0[0x115];
    u8 unk_115;
    u8 pad_116[2];
    s32 unk_118;
} StoryPlayer;

/* view of StoryInput starting at its button word */
typedef struct StoryButtons {
    u16 unk_0;
    u8 pad_2[0x12];
} StoryButtons;

typedef struct StoryPlayerList {
    u8 pad_0[0x2C];
    StoryPlayer *unk_2C[4];
} StoryPlayerList;

typedef struct StoryInput {
    u8 pad_0[8];
    u16 buttons;
    u8 pad_A[0xA];
} StoryInput;

extern FontDrawPacket lbl_1_rodata_26F8;
extern StoryInput lbl_1_bss_9F8[];

extern void OSReport(const char *, ...);
extern u16 fn_1_48690(u32);
extern s16 fn_1_3F0C8(void);
extern u8 fn_1_86810(int);
extern StoryVehicle *fn_1_86254(s32);
extern StoryTime *fn_1_8627C(s32);
extern s16 fn_1_E5568(s16);
extern StoryEventObject *fn_1_E54A8(s16, s16);
extern u32 fn_1_E57C4(void *);
extern s16 fn_1_E5430(s16);
extern u32 fn_1_8C66C(u32);
extern f32 fn_1_8C6A0(u32);
extern u32 fn_1_F1B94(void);

s32 fn_7_4648(StoryContext *context, StoryTrigger *trigger);
void fn_7_4FD0(StoryContext *context, StoryTrigger *trigger);
s32 fn_7_4E28(s32 op, s32 a, s32 b);
s32 fn_7_4EF8(u32 op, f32 a, f32 b);

typedef struct { u8 pad[4]; f32 f4,f8,fc,f10,f14; u8 pad18[8]; f32 f20; u8 pad24[0x1c]; f32 f40; u8 pad44[0x70]; } CarSpec;
extern CarSpec lbl_1_data_28060[];

typedef struct { f32 x,y,z; } ActionVec;
typedef struct { u8 r,g,b,a; } ActionColor;
typedef struct { u32 flags; u8 pad4[0x2e]; u8 mode; } CarControl;
typedef struct {
    u32 flags; s16 field4; s16 field6; f32 field8,fieldc,field10,field14;
    u8 pad18[0x7c]; ActionVec field94,fielda0; u8 padac[0xd0];
    f32 field17c; f32 field180; f32 field184; u8 pad188[0x98];
    f32 field220,field224,field228,field22c; u8 pad230[0xc]; f32 field23c;
    u8 pad240[0x244]; CarControl *field484; u8 pad488[0x14]; void *field49c;
    u8 pad4a0[0x13a]; u16 field5da;
} ActionCar;
typedef struct { u8 pad[0x390]; u32 flags390; } Racer;

extern int fn_1_4C10(void);
extern int fn_1_4CAC(void);
extern int fn_1_40F44(void);
extern u32 fn_1_3ED8C(u32,u32,u32,u32,u32,u32,u32);
extern u32 fn_1_3F4B8(u32,u32,u32,u32,u32,u32);
extern u32 fn_1_3EB78(u32,void *,void *,void *);
extern u32 fn_1_3EA90(u32,void *,void *,void *);
extern void fn_1_86194(f32);
extern int fn_1_24F10(void *,f32);
extern void *fn_1_868C0(s8);
extern void fn_1_8E448(void *,u32);
extern u32 fn_1_864E8(s32);
extern void fn_1_85F90(void *,void *,f32,f32,f32,f32);
extern void fn_1_8B880(void);
extern void *fn_1_214C4(void *,u32,f32);
extern u32 fn_1_17920(void *,u32,f32);
extern u8 *fn_1_14F04(void);
extern void fn_1_207DC(void *,void *,f32);
extern void fn_1_25004(void *);
extern void fn_1_8D988(void);
extern void fn_1_8DAB4(void);
extern void camera_set_entry_field_0xa8(u8,s16);
extern s32 fn_1_3F1AC(void);
extern void fn_1_A2D84(u32);
extern u32 fn_1_A1588(void *,u32);
extern void *lbl_1_bss_84[];
extern u32 lbl_1_bss_6F23C;
extern s8 lbl_1_bss_9C[];
extern u8 lbl_1_bss_8B3A0[];
// lbl_1_bss_6EAD0: .bss size 0x708, 6 refs from game.c (its first word is used here)
typedef struct { u32 unk_0; u32 unk_4; } SoundHandles;
extern SoundHandles *lbl_1_bss_6EAD0;
typedef struct { u32 unk_0; u8 pad_4[0xE]; } SoundFlags;
extern SoundFlags lbl_1_bss_6EAB4;

const GXColor black = {0, 0, 0, 0};

u8 lbl_7_bss_1960 = 0;
StoryCourse *lbl_7_bss_1964 = NULL;
u8 lbl_7_bss_1968 = 0;
u32 lbl_7_bss_196C = 0;
GXColor lbl_7_bss_1970[2];
u8 lbl_7_bss_1978[2];
f32 lbl_7_bss_197C[2];
f32 lbl_7_bss_1984[2];
u8 lbl_7_bss_198C;
StoryTrigger *lbl_7_bss_1990;
u8 lbl_7_bss_1994;
u8 lbl_7_bss_1995;
u8 lbl_7_bss_1996;
u8 lbl_7_bss_1997;
u8 lbl_7_bss_1998;
u8 lbl_7_bss_1999;
u8 lbl_7_bss_199A;
u32 lbl_7_bss_199C;
/* slot tables: 4 player slots, 30 object slots */
u8 lbl_7_bss_19A0[4];
u8 lbl_7_bss_19A4[4];
u32 lbl_7_bss_19A8[4];
u8 lbl_7_bss_19B8[30];
u8 lbl_7_bss_19D8[30];
u32 lbl_7_bss_19F8[30];
/* Unknown retail object: .bss 0x1A70, 1 bytes. No code or data in any REL refers to it. */
u8 lbl_7_bss_1A70;

/* fzgx:begin fn_7_4108 */
void fn_7_4108(StoryContext *context, StoryTrigger *triggers, StoryCourse *course) {
    GXColor colors[2];
    u32 *p;
    u8 i;

    p = context->done;
    for (i = 0; i < 128; i++, p++) {
        *p = 0;
    }
    {
        s32 *q = context->counters;
        for (i = 0; i < 8; i++, q++) {
            *q = 0;
        }
    }
    {
        s32 *q = context->timers;
        for (i = 0; i < 8; i++, q++) {
            *q = -1;
        }
    }
    lbl_7_bss_1964 = course;
    lbl_7_bss_1968 = 0;
    lbl_7_bss_196C = 0;
    lbl_7_bss_1960 = 0;
    colors[1] = colors[0] = black;
    for (i = 0; i < 2; i++) {
        lbl_7_bss_1970[i] = colors[i];
        lbl_7_bss_1978[i] = 0;
        lbl_7_bss_197C[i] = lbl_7_bss_1984[i] = 0.0f;
    }
    lbl_7_bss_198C = 0;
    lbl_7_bss_1990 = triggers;
}
/* fzgx:end fn_7_4108 */

/* fzgx:begin fn_7_41FC */
static inline f32 clamp01(f32 x) {
    if (x < 0.0f) {
        return 0.0f;
    }
    if (x > 1.0f) {
        return 1.0f;
    }
    return x;
}

void fn_7_41FC(StoryContext *context) {
    StoryTrigger *t;
    s32 *timer;
    u32 i;
    u32 n;
    s32 ok;
    u8 k;

    t = lbl_7_bss_1990;
    timer = context->timers;
    for (i = 0; i < 8; i++, timer++) {
        if (!__rlwnm(lbl_7_bss_196C, (i + 1) & 31, 31, 31) && *timer >= 0) {
            (*timer)--;
        }
    }
    n = 0;
    while (t->type != 5) {
        ok = 1;
        while (t->type <= 3) {
            if (n >= 0x1000) {
                OSReport("Too Many Scenario Trigger\n\n");
                return;
            }
            if (__rlwnm(context->done[n >> 5], ((n & 31) + 1) & 31, 31, 31)) {
                ok = 0;
                break;
            }
            if (t->type == 2 || t->type == 3) {
                if (fn_7_4648(context, t)) {
                    ok = 0;
                    break;
                }
            } else if (!fn_7_4648(context, t)) {
                ok = 0;
                break;
            }
            t++;
            n++;
        }
        if (ok) {
            StoryTrigger *p = t - 1;
            u32 j = n - 1;

            while (p->type <= 3 && j != -1) {
                if (p->type == 0 || p->type == 2) {
                    context->done[j >> 5] |= 0x80000000 >> (j & 31);
                }
                p--;
                j--;
            }
            while (t->type == 4) {
                fn_7_4FD0(context, t);
                t++;
            }
        } else {
            while (t->type <= 3) {
                t++;
                n++;
            }
            while (t->type == 4) {
                t++;
            }
        }
    }
    for (k = 0; k < 2; k++) {
        if (lbl_7_bss_1978[k]) {
            lbl_7_bss_197C[k] += lbl_7_bss_1984[k];
            lbl_7_bss_197C[k] = clamp01(lbl_7_bss_197C[k]);
        }
    }
}
/* fzgx:end fn_7_41FC */

/* fzgx:begin fn_7_44DC */
void fn_7_44DC(void) {
    FontDrawPacket packet;
    u8 i;

    for (i = 0; i < 2; i++) {
        if (lbl_7_bss_1978[i] != 0) {
            packet = lbl_1_rodata_26F8;
            packet.image = 18;
            packet.x = 0.0f;
            packet.y = 0.0f;
            packet.z = 300.0f - i;
            packet.flags = 5;
            packet.scale_x *= 640.0f / fn_1_48690(18);
            packet.scale_y *= 480.0f / fn_1_48690(18);
            *(GXColor *)packet.color = lbl_7_bss_1970[i];
            packet.alpha = lbl_7_bss_197C[i];
            fn_1_4F734(&packet);
        }
    }
}
/* fzgx:end fn_7_44DC */

/* fzgx:begin fn_7_4648 */
static inline s32 storyButtonEither(u16 buttons) {
    switch (__rlwinm(buttons, 24, 31, 31) | __rlwinm(buttons, 23, 31, 31)) {
    default: return 1;
    case 0: return 0;
    }
}

static inline f32 storyDistanceSquared(const Vec *a, const Vec *b) {
    f32 x = a->x;
    f32 y = a->y;
    f32 z = a->z;
    f32 result;
    x -= b->x;
    y -= b->y;
    z -= b->z;
    result = x*x;
    result += y*y;
    result += z*z;
    return result;
}

/* WARNING: compiler-diff device, not original code (opt_propagation, opt_lifetimes, opt_common_subs off) */
#pragma opt_propagation off
#pragma opt_lifetimes off
#pragma opt_common_subs off
s32 fn_7_4648(StoryContext *context, StoryTrigger *arg1) {
    u16 v0;
    s32 v1;
    StoryTrigger *trigger;
    trigger = arg1;
    v0 = arg1->opcode;
    v1 = 0;
    switch (v0) {
    case 0: {
        u32 *flags = (u32 *)trigger->unk_4;
        s32 truth;
        switch ((s32)flags) {
        case 0: flags = &context->flags244; break;
        case 1: flags = &context->flags240; break;
        }
        if ((u32)flags + 0x10000 == 0xFFFF) {
            v1 = 1;
            break;
        }
        truth = trigger->unk_8;
        if (*flags & trigger->unk_C) v1 = truth;
        else v1 = !truth;
        break;
    }
    case 1:
        v1 = fn_7_4E28(trigger->unk_8, context->counters[trigger->unk_4], trigger->unk_C);
        break;
    case 6:
        if (lbl_7_bss_1964->unk_D == 0) v1 = 1;
        break;
    case 2:
        if (fn_1_3F0C8() == 0x29) v1 = 1;
        break;
    case 3:
        if (lbl_7_bss_1964->unk_C != 0) v1 = 1;
        break;
    case 4: {
        StoryPlayerList *slot = (StoryPlayerList *)((u8 *)lbl_7_bss_1964 + fn_1_86810(lbl_7_bss_1994) * 4);
        if (slot->unk_2C[0]->unk_115 == 0) v1 = 1;
        break;
    }
    case 5: {
        s32 value = trigger->unk_8;
        switch (trigger->unk_4) {
        case 0:
            if (fn_1_86254(value)->flags & 0x80) v1 = 1;
            break;
        case 1:
            if (fn_1_86254(lbl_7_bss_1994)->unk_482 >= value) v1 = 1;
            break;
        default:
            OSReport("Trigger Error\n");
            break;
        }
        break;
    }
    case 7: {
        s32 kind = trigger->unk_4;
        s32 op = trigger->unk_8;
        s32 value = trigger->unk_C;
        s32 current;
        if (kind == 8) {
            StoryTime *time = fn_1_8627C(lbl_7_bss_1994);
            s32 minutes;
            s32 seconds;
            s32 milliseconds = time->milliseconds;
            seconds = time->seconds * 1000;
            minutes = time->minutes * 60000;
            current = minutes + milliseconds;
            current = seconds + current;
            value = value * 1000 / 60;
        } else {
            current = context->timers[kind];
        }
        v1 = fn_7_4E28(op, current, value);
        break;
    }
    case 8: {
        s32 b;
        s32 a;
        s32 c;
        f32 radius;
        a = trigger->unk_8;
        b = trigger->unk_C;
        c = trigger->unk_10;
        radius = trigger->unk_14;
        switch (trigger->unk_4) {
        case 0:
            v1 = fn_7_4E28(b, fn_1_E5568(a), c);
            break;
        case 1:
            if (b == -1) {
                b = (32 - c) & 31;
                for (c = 0; c < fn_1_E5430(a); c++) {
                    if (__rlwnm(fn_1_E57C4(fn_1_E54A8(a, c)), b, 31, 31)) {
                        v1 = 1;
                        break;
                    }
                }
            } else {
                v1 = __rlwnm(fn_1_E57C4(fn_1_E54A8(a, b)), (32 - c) & 31, 31, 31) ? 1 : 0;
            }
            break;
        case 2:
            if (b == -1) {
                for (b = 0; b < fn_1_E5430(a); b++) {
                    u32 flags = fn_1_E57C4(fn_1_E54A8(a, b));
                    if (flags & c) {
                        v1 = 1;
                        break;
                    }
                }
            } else {
                u32 flags = fn_1_E57C4(fn_1_E54A8(a, b));
                v1 = (flags & c) != 0;
            }
            break;
        case 3: {
            u64 flags = *(u64 *)&fn_1_E54A8(a, b)->flags138;
            if (flags & (s64)c) v1 = 1;
            break;
        }
        case 4: {
            u64 flags = *(u64 *)&fn_1_E54A8(a, b)->flags138;
            if (flags & ((s64)c << 32)) v1 = 1;
            break;
        }
        case 5: {
            StoryEventObject *object = fn_1_E54A8(a, b);
            StoryVehicle *vehicle = fn_1_86254(c);
            v1 = fn_7_4EF8(4, storyDistanceSquared(&object->pos, &vehicle->pos), radius*radius);
            break;
        }
        default:
            OSReport("Trigger Error\n");
            break;
        }
        break;
    }
    case 9: {
        s32 op = trigger->unk_8;
        f32 value = trigger->unk_14;
        StoryVehicle *vehicle = fn_1_86254(trigger->unk_4);
        v1 = fn_7_4EF8(op, vehicle->unk_17C, value);
        break;
    }
    case 10: {
        s32 id = trigger->unk_4;
        Vec *pos = (Vec *)trigger->unk_8;
        s32 op = trigger->unk_C;
        f32 radius = trigger->unk_14;
        StoryVehicle *vehicle;
        if ((s32)pos == 0) pos = &fn_1_86254(lbl_7_bss_1994)->pos;
        vehicle = fn_1_86254(id);
        v1 = fn_7_4EF8(op, storyDistanceSquared(pos, &vehicle->pos), radius*radius);
        break;
    }
    case 11: {
        s32 id;
        s32 op;
        s32 other;
        f32 value;
        s32 current;
        id = trigger->unk_4;
        op = trigger->unk_C;
        value = trigger->unk_14;
        switch (trigger->unk_8) {
        case 0:
            current = fn_1_8C66C(id);
            v1 = fn_7_4E28(op, current, trigger->unk_10);
            break;
        case 1:
            current = fn_1_8C66C(id);
            v1 = fn_7_4E28(op, current, *(s32 *)trigger->unk_10);
            break;
        case 2: {
            other = trigger->unk_10;
            current = fn_1_8C66C(id);
            if (other == current) {
                f32 f = fn_1_8C6A0(id);
                v1 = fn_7_4EF8(op, f, value);
            }
            break;
        }
        default:
            OSReport("Trigger Error\n");
            break;
        }
        break;
    }
    case 12: {
        s32 kind;
        s32 op;
        s32 id;
        f32 value;
        f32 current;
        StoryVehicle *vehicle;
        id = trigger->unk_4;
        kind = trigger->unk_8;
        op = trigger->unk_C;
        value = trigger->unk_14;
        vehicle = fn_1_86254(id);
        switch (kind) {
        case 0: current = vehicle->unk_184; break;
        case 1: current = fn_1_86810(id); break;
        default: OSReport("Trigger Error\n"); break;
        }
        v1 = fn_7_4EF8(op, current, value);
        break;
    }
    case 13: {
        s32 truth = trigger->unk_8;
        s32 mask = trigger->unk_C;
        u32 flags = fn_1_86254(trigger->unk_4)->flags;
        if (flags & mask) v1 = truth;
        else v1 = !truth;
        break;
    }
    case 14:
        switch (trigger->unk_4) {
        case 0: {
            StoryButtons *buttonBase = (StoryButtons *)&lbl_1_bss_9F8[0].buttons;
            u16 buttons = buttonBase[lbl_7_bss_1995].unk_0;
            v1 = storyButtonEither(buttons);
            break;
        }
        case 1: {
            u32 pressed = __rlwinm(lbl_1_bss_9F8[lbl_7_bss_1995].buttons, 24, 31, 31);
            v1 = pressed;
            break;
        }
        case 2: {
            u32 pressed = __rlwinm(lbl_1_bss_9F8[lbl_7_bss_1995].buttons, 23, 31, 31);
            v1 = pressed;
            break;
        }
        }
        break;
    case 15: {
        s32 op = trigger->unk_8;
        s32 value = trigger->unk_C;
        StoryPlayerList *slot = (StoryPlayerList *)((u8 *)lbl_7_bss_1964 + fn_1_86810(trigger->unk_4) * 4);
        StoryPlayer *player = slot->unk_2C[0];
        v1 = fn_7_4E28(op, player->unk_118, value);
        break;
    }
    case 16:
        v1 = fn_7_4E28(trigger->unk_4, context->unk_248, trigger->unk_8);
        break;
    case 17: {
        s32 id = trigger->unk_4;
        v1 = (fn_1_F1B94() == id) ? 1 : 0;
        break;
    }
    }
    return v1;
}
#pragma opt_common_subs reset
#pragma opt_lifetimes reset
#pragma opt_propagation reset
/* fzgx:end fn_7_4648 */

/* fzgx:begin fn_7_4E28 */
s32 fn_7_4E28(s32 op, s32 a, s32 b) {
    s32 result = 0;

    switch (op) {
    case 0:
        if (a == b) {
            result = 1;
        }
        break;
    case 1:
        if (a != b) {
            result = 1;
        }
        break;
    case 2:
        if (a >= b) {
            result = 1;
        }
        break;
    case 3:
        if (a > b) {
            result = 1;
        }
        break;
    case 4:
        if (a <= b) {
            result = 1;
        }
        break;
    case 5:
        if (a < b) {
            result = 1;
        }
        break;
    default:
        OSReport("Trigger Error\n");
        break;
    }
    return result;
}
/* fzgx:end fn_7_4E28 */

/* fzgx:begin fn_7_4EF8 */
s32 fn_7_4EF8(u32 op, f32 a, f32 b) {
    s32 result = 0;

    switch (op) {
    case 0:
        if (a == b) {
            result = 1;
        }
        break;
    case 1:
        if (a != b) {
            result = 1;
        }
        break;
    case 2:
        if (a >= b) {
            result = 1;
        }
        break;
    case 3:
        if (a > b) {
            result = 1;
        }
        break;
    case 4:
        if (a <= b) {
            result = 1;
        }
        break;
    case 5:
        if (a < b) {
            result = 1;
        }
        break;
    default:
        OSReport("Trigger Error\n");
        break;
    }
    return result;
}
/* fzgx:end fn_7_4EF8 */

/* fzgx:begin fn_7_4FD0 */
static inline void set_slot(u8 *a,u8 *b,u32 *c,s32 slot,u32 x,u32 y,u32 flags) {
    a[slot]=x;
    b[slot]=y;
    c[slot]=flags;
}
static inline void clear_object_flags(StoryEventObject *obj,u32 high,u32 low) {
    *(u64 *)&obj->flags138 &= ~(((u64)high << 32) | low);
}
/* WARNING: compiler-diff device, not original code (opt_dead_assignments off) */
#pragma opt_dead_assignments off
void fn_7_4FD0(StoryContext *arg0,StoryTrigger *arg1) {
    s32 i;
    s32 j;
    s32 end;
    s32 first;
    s32 op;
    s32 index;
    s32 value;
    s32 extra;
    if ((fn_1_4C10()!=0 && fn_1_4CAC()==0) || fn_1_40F44()!=0)
        lbl_7_bss_198C=1;
    switch (arg1->opcode) {
    case 0:
        op=arg1->unk_4; index=arg1->unk_8; value=arg1->unk_C;
        switch(op) {
        case 0:
            if(index<8) arg0->timers[index]=value;
            else if(index==9) for(i=0;i<8;i++) arg0->timers[i]=value;
            break;
        case 1:
            if(index<8) arg0->timers[index]+=value;
            else if(index==9) for(i=0;i<8;i++) arg0->timers[i]+=value;
            break;
        case 2:
            if(index<8) {
                if(value) lbl_7_bss_196C |= 0x80000000U >> index;
                else lbl_7_bss_196C &= ~(0x80000000U >> index);
            } else if(index==9) {
                for(i=0;i<8;i++) {
                    if(value) lbl_7_bss_196C |= 0x80000000U >> index;
                    else lbl_7_bss_196C &= ~(0x80000000U >> index);
                }
            }
            break;
        default: OSReport("Action Error\n"); break;
        }
        break;
    case 20:
        op=arg1->unk_4; index=arg1->unk_8; value=arg1->unk_C;
        switch(op) {
        case 0:
            if(index<8) arg0->counters[index]=value;
            else if(index==8) for(i=0;i<8;i++) arg0->counters[i]=value;
            break;
        case 1:
            if(index<8) arg0->counters[index]+=value;
            else if(index==8) for(i=0;i<8;i++) arg0->counters[i]+=value;
            break;
        default: OSReport("Action Error\n"); break;
        }
        break;
    case 1:
        op=arg1->unk_4; index=arg1->unk_8;
        switch(op) {
        case 1: lbl_7_bss_1996=index; break;
        case 2: lbl_7_bss_1997=index; break;
        case 3: lbl_7_bss_1998=index; break;
        case 0: lbl_7_bss_1999=index; break;
        case 4: lbl_7_bss_1968=index; break;
        case 5: lbl_7_bss_199A=index; break;
        case 6: lbl_7_bss_199C=index; break;
        default: OSReport("Action Error\n"); break;
        }
        break;
    case 2:
        fn_1_3ED8C(0,lbl_7_bss_1997,1,lbl_7_bss_1996,
            lbl_7_bss_1999,lbl_7_bss_1998,lbl_7_bss_199C);
        if(lbl_7_bss_1968)
            fn_1_3F4B8(lbl_7_bss_1968,lbl_7_bss_199A,0,0,0,0);
        break;
    case 3:
        for(i=0;i<4;i++) {
            lbl_7_bss_19A0[i]=255;
            lbl_7_bss_19A4[i]=255;
            lbl_7_bss_19A8[i]=0;
        }
        for(j=0;j<30;j++) {
            lbl_7_bss_19B8[j]=255;
            lbl_7_bss_19D8[j]=255;
            lbl_7_bss_19F8[j]=0;
        }
        break;
    case 4:
        lbl_7_bss_1995=*(u8 *)arg1->unk_4;
        break;
    case 5: {
        s32 op,index,value;
        u8 *scan;
        op=arg1->unk_4; index=arg1->unk_8; value=arg1->unk_C;
        switch(op) {
        case 0:
            lbl_7_bss_1994=0;
            set_slot(lbl_7_bss_19A0,lbl_7_bss_19A4,lbl_7_bss_19A8,lbl_7_bss_1995,index,value,0);
            break;
        case 1:
            for(i=0,scan=lbl_7_bss_19B8;i<30 && *scan!=255;scan++,i++) {}
            if(i==30) OSReport("enemy car set error\n");
            set_slot(lbl_7_bss_19B8,lbl_7_bss_19D8,lbl_7_bss_19F8,i,index,value,0);
            break;
        case 2:
            lbl_7_bss_1994=0;
            set_slot(lbl_7_bss_19A0,lbl_7_bss_19A4,lbl_7_bss_19A8,lbl_7_bss_1995,index,value,0x100000);
            break;
        case 3:
            for(i=0,scan=lbl_7_bss_19B8;i<30 && *scan!=255;scan++,i++) {}
            if(i==30) OSReport("enemy car set error\n");
            set_slot(lbl_7_bss_19B8,lbl_7_bss_19D8,lbl_7_bss_19F8,i,index,value,0x100000);
            break;
        default: OSReport("Action Error\n"); break;
        }
        break;
    }
    case 6:
        fn_1_3EB78(1,lbl_7_bss_19A0,lbl_7_bss_19A4,lbl_7_bss_19A8);
        fn_1_3EA90((u8)(lbl_7_bss_1998-1),lbl_7_bss_19B8,lbl_7_bss_19D8,lbl_7_bss_19F8);
        break;
    case 7: {
        s32 op,index;
        u32 value,extra;
        op=arg1->unk_4; index=arg1->unk_8; value=arg1->unk_C; extra=arg1->unk_10;
        switch(op) {
        case 0:
            if(value!=-1) {
                s32 group=(s16)index;
                StoryEventObject *obj=(StoryEventObject *)fn_1_E54A8(group,value);
                obj->flags13C |= extra;
            } else {
    s16 k;
for(k=0;k<fn_1_E5430(index);k++) {
                StoryEventObject *obj=(StoryEventObject *)fn_1_E54A8(index,k); obj->flags13C |= extra;
            }
}
            break;
        case 1:
            if(value!=-1) {
                s32 group=(s16)index;
                StoryEventObject *obj=(StoryEventObject *)fn_1_E54A8(group,value);
                obj->flags138 |= extra;
            } else {
    s16 k;
for(k=0;k<fn_1_E5430(index);k++) {
                StoryEventObject *obj=(StoryEventObject *)fn_1_E54A8(index,k); obj->flags138 |= extra;
            }
}
            break;
        case 2:
            if(value!=-1) {
                s32 group=(s16)index;
                clear_object_flags((StoryEventObject *)fn_1_E54A8(group,value),0,extra);
            }
            else {
                s16 k;
                for(k=0;k<fn_1_E5430(index);k++)
                    clear_object_flags((StoryEventObject *)fn_1_E54A8(index,k),0,extra);
            }
            break;
        case 3:
            if(value!=-1) {
                s32 group=(s16)index;
                clear_object_flags((StoryEventObject *)fn_1_E54A8(group,value),extra,0);
            }
            else {
                s16 k;
                for(k=0;k<fn_1_E5430(index);k++)
                    clear_object_flags((StoryEventObject *)fn_1_E54A8(index,k),extra,0);
            }
            break;
        case 4: {
            u32 id=(value<<4)|extra;
            s32 j;
for(j=0;j<fn_1_E5430(index);j++) {
                StoryEventObject *obj=(StoryEventObject *)fn_1_E54A8(index,j);
                if(obj->unk_E==id) clear_object_flags(obj,0,0x2000);
            }
            break;
        }
        default: OSReport("Action Error\n"); break;
        }
        break;
    }
    case 8: {
        s32 first, op, index;
        f32 *fp=0;
        u16 *sp=0;
        s32 end;
        f32 amount;
        f32 base;
        first=arg1->unk_4; index=arg1->unk_8; op=arg1->unk_C; amount=arg1->unk_14;
        if(first==99) {end=lbl_7_bss_1998-1;first=0;}
        else if(first==98) {end=lbl_7_bss_1998-1;first=1;}
        else end=first;
        {
for(j=first;j<=end;j++) {
            ActionCar *car=(ActionCar *)fn_1_86254(j);
            CarSpec *spec=&lbl_1_data_28060[car->field6];
            switch(index) {
            case 9:
                if(op==1) {base=100.0f;sp=&car->field5da;fp=&car->field184;}
                else {
                    base=car->field5da; fp=&car->field184; sp=0;
                    if(op==2 && car->field184+amount>car->field5da)
                        amount=car->field5da-car->field184;
                }
                break;
            case 0: base=spec->f4; fp=&car->field8; break;
            case 1: base=spec->f8; fp=&car->field220; break;
            case 2: base=spec->fc; fp=&car->field22c; break;
            case 3: op=0; fn_1_86194(amount); break;
            case 4: base=spec->f10; fp=&car->fieldc; break;
            case 5: base=spec->f14; fp=&car->field10; break;
            case 6: op=0; fn_1_24F10(car,amount); break;
            case 7: base=spec->f20; fp=&car->field14; break;
            case 8: base=spec->f40; fp=&car->field23c; break;
            default: op=0; break;
            }
            if(amount==-10000000.0f) amount=base;
            if(sp) switch(op) {
            case 0: break;
            case 1: *sp=amount; break;
            case 2: *sp+=(s32)amount; break;
            case 3: *sp-=(s32)amount; break;
            default: OSReport("Action Error\n"); break;
            }
            if(fp) switch(op) {
            case 0: break;
            case 1: *fp=amount; break;
            case 2: *fp+=amount; break;
            case 3: *fp-=amount; break;
            default: OSReport("Action Error\n"); break;
            }
        }
}
        break;
    }
    case 9: {
        s32 selector, first, value, op, end;
        u32 notmask,notvalue;
        s32 i;
        u32 mask;
        selector=arg1->unk_4; op=arg1->unk_8; value=arg1->unk_C;
        if(selector==99) {end=lbl_7_bss_1998-1;first=0;}
        else if(selector==98) {end=lbl_7_bss_1998-1;first=1;}
        else {end=selector;first=selector;}
        mask=0x80000000U>>value; notvalue=~value; notmask=~mask;
        for(i=first;i<=end;i++) {
            ActionCar *car=(ActionCar *)fn_1_86254(i);
            switch(op) {
            case 0: car->flags=value; break;
            case 1: car->flags|=mask; break;
            case 2: car->flags&=notmask; break;
            case 3: car->flags|=value; break;
            case 4: car->flags&=notvalue; break;
            default: OSReport("Action Error\n"); break;
            }
        }
        break;
    }
    case 10: {
        s32 selector, first, value, op, end;
        u32 notmask,notvalue;
        s32 i;
        u32 mask;
        selector=arg1->unk_4; op=arg1->unk_8; value=arg1->unk_C;
        if(selector==99) {end=lbl_7_bss_1998-1;first=0;}
        else if(selector==98) {end=lbl_7_bss_1998-1;first=1;}
        else {end=selector;first=selector;}
        mask=0x80000000U>>value; notvalue=~value; notmask=~mask;
        for(i=first;i<=end;i++) {
            Racer *racer=(Racer *)fn_1_868C0(i);
            switch(op) {
            case 0: racer->flags390=value; break;
            case 1: racer->flags390|=mask; break;
            case 2: racer->flags390&=notmask; break;
            case 3: racer->flags390|=value; break;
            case 4: racer->flags390&=notvalue; break;
            default: OSReport("Action Error\n"); break;
            }
        }
        break;
    }
    case 11: {
        u32 value;
        s32 first, end;
        first=arg1->unk_4; value=arg1->unk_8;
        if(first==99) {end=lbl_7_bss_1998-1;first=0;}
        else if(first==98) {end=lbl_7_bss_1998-1;first=1;}
        else end=first;
        for(i=first;i<=end;i++) {
            void *racer=fn_1_868C0(i);
            fn_1_8E448(racer,value);
        }
        break;
    }
    case 12: {
        f32 x=arg1->unk_8;
        f32 z=arg1->unk_14;
        f32 y=arg1->unk_C;
        ActionCar *car;
        u32 flags;
        u32 index;
        index=arg1->unk_4;
        car=(ActionCar *)fn_1_86254(index);
        fn_1_8627C(index);
        flags=fn_1_864E8(index);
        fn_1_85F90(car,(void *)-1,y,z,1.0f,x);
        fn_1_8B880();
        car->flags=flags|(car->flags&0x400);
        break;
    }
    case 13: {
        f32 x=arg1->unk_8;
        f32 z=arg1->unk_14;
        f32 y=arg1->unk_C;
        ActionCar *car;
        u32 flags;
        f32 result;
        ActionVec pos;
        void *entry;
        u32 index;
        index=arg1->unk_4;
        car=(ActionCar *)fn_1_86254(index);
        fn_1_8627C(index);
        flags=fn_1_864E8(index);
        entry=fn_1_214C4(&result,0,x);
        fn_1_17920(entry,0,result);
        fn_1_207DC((fn_1_14F04()+0x400),&pos,z);
        fn_1_85F90(car,entry,y,pos.x,pos.y,pos.z);
        fn_1_8B880();
        car->flags=flags|(car->flags&0x400);
        break;
    }
    case 14: {
        s32 first, i, op, value, end;
        first=arg1->unk_4; op=arg1->unk_8; value=arg1->unk_C;
        if(first==99) {end=lbl_7_bss_1998-1;first=0;}
        else if(first==98) {end=lbl_7_bss_1998-1;first=1;}
        else end=first;
        {
for(i=first;i<=end;i++) {
            CarControl *control=((ActionCar *)fn_1_86254(i))->field484;
            switch(op) {
            case -99: control->flags|=value; break;
            case -98: control->flags&=~value; break;
            case 0: control->flags&=~1;control->mode=0;break;
            default: control->flags|=1;control->mode=op;break;
            }
        }
}
        break;
    }
    case 15:
        op=arg1->unk_4; index=arg1->unk_8;
        switch(op) {
        case 0: lbl_1_bss_9C[6]=index;break;
        case 1: lbl_1_bss_9C[7]=index;break;
        default: OSReport("Action Error\n");break;
        }
        break;
    case 16: {
        ActionCar *car=(ActionCar *)fn_1_86254(arg1->unk_4);
        ActionVec a=car->field94;
        ActionVec b=car->fielda0;
        f32 x=car->field224;
        f32 y=car->field17c;
        fn_1_25004(car);
        car->field224=x;car->field17c=y;
        car->field94=a;car->fielda0=b;
        break;
    }
    case 17:
        op=arg1->unk_4; index=arg1->unk_8;
        switch(op) {
        case 0:
            if(index<8) lbl_1_bss_84[0]=&arg0->timers[index];
            else OSReport("Action Error\n");
            break;
        case 1: lbl_1_bss_84[1]=&((ActionCar *)fn_1_86254(index))->field17c;break;
        case 2: lbl_1_bss_84[2]=((ActionCar *)fn_1_86254(index))->field49c;break;
        case 3: lbl_1_bss_84[3]=lbl_7_bss_1964;break;
        case 4: lbl_1_bss_84[4]=(void *)index;break;
        case 5: lbl_1_bss_84[5]=(void *)index;break;
        default: OSReport("Action Error\n");break;
        }
        break;
    case 18:
        if(arg1->unk_4) fn_1_8D988();
        else fn_1_8DAB4();
        break;
    case 19:
        op=arg1->unk_4; index=arg1->unk_8;
        switch(op) {
        case 0: camera_set_entry_field_0xa8(0,index);break;
        default: OSReport("Action Error\n");break;
        }
        break;
    case 21: {
        u32 *flags;
        s32 op,value;
        flags=(u32 *)arg1->unk_8; op=arg1->unk_4; value=arg1->unk_C;
        switch((s32)flags) {
        case 0: flags=&arg0->flags244;break;
        case 1: flags=&arg0->flags240;break;
        case 2: flags=(u32 *)lbl_7_bss_1964;break;
        }
        switch(op) {
        case 0: *flags=value;break;
        case 1: *flags|=0x80000000U>>value;break;
        case 2: *flags&=~(0x80000000U>>value);break;
        case 3: *flags|=value;break;
        case 4: *flags&=~value;break;
        default: OSReport("Action Error\n");break;
        }
        break;
    }
    case 22: {
        u32 handle;
        s32 op, extra, value;
        extra=arg1->unk_C;op=arg1->unk_4;value=arg1->unk_8;
        if(extra==0) handle=lbl_1_bss_6EAD0->unk_0;
        else handle=lbl_1_bss_6EAD0->unk_4;
        switch(op) {
        case 0:
            if(!lbl_7_bss_198C && !fn_1_3F1AC()) fn_1_A2D84(value);
            break;
        case 1:
            if(!lbl_7_bss_198C && !fn_1_3F1AC()) fn_1_A1588((void *)handle,(u8)value);
            break;
        case 2: lbl_1_bss_6EAB4.unk_0|=value;break;
        }
        break;
    }
    case 23: {
        s32 op;
        f32 amount;
        op=arg1->unk_4;amount=arg1->unk_14;
        switch(op) {
        case 0: {
            static const GXColor color={0, 0, 0, 0};
            u32 slot=(u8)(lbl_7_bss_1960);
            lbl_7_bss_1970[slot]=color;
            lbl_7_bss_1978[slot]=0;
            lbl_7_bss_1984[slot]=0.0f;
            lbl_7_bss_197C[slot]=0.0f;
            break;
        }
        case 1: {
            static const GXColor color={0, 0, 0, 0};
            u32 slot=(u8)(lbl_7_bss_1960);
            lbl_7_bss_1970[slot]=color;
            lbl_7_bss_1978[slot]=2;
            lbl_7_bss_197C[slot]=0.0f;
            lbl_7_bss_1984[slot]=amount;
            break;
        }
        case 2: {
            static const GXColor color={0, 0, 0, 0};
            u32 slot=(u8)(lbl_7_bss_1960);
            lbl_7_bss_1970[slot]=color;
            lbl_7_bss_1978[slot]=1;
            lbl_7_bss_197C[slot]=1.0f;
            lbl_7_bss_1984[slot]=-amount;
            break;
        }
        case 4: {
            static const GXColor color={0x40, 0, 0, 0};
            u32 slot=(u8)(lbl_7_bss_1960);
            lbl_7_bss_1970[slot]=color;
            lbl_7_bss_1978[slot]=1;
            lbl_7_bss_197C[slot]=1.0f;
            lbl_7_bss_1984[slot]=-amount;
            break;
        }
        case 3: {
            static const GXColor color={0x40, 0, 0, 0};
            u32 slot=(u8)(lbl_7_bss_1960);
            lbl_7_bss_1970[slot]=color;
            lbl_7_bss_1978[slot]=2;
            lbl_7_bss_197C[slot]=0.0f;
            lbl_7_bss_1984[slot]=amount;
            break;
        }
        }
        lbl_7_bss_1960++;
        if(lbl_7_bss_1960>=2) lbl_7_bss_1960--;
        break;
    }
    case 24: *(s16 *)(lbl_1_bss_8B3A0 + 8)=arg1->unk_4;break;
    }
    if(lbl_7_bss_198C) lbl_1_bss_6F23C&=~1;
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_7_4FD0 */
