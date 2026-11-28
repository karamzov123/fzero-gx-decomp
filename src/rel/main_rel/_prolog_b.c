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

/* fzgx:begin fn_1_1304 noprologue */
#include "types.h"

extern const struct fn_1_1304_lbl_1_rodata_9C_pool {
    f32 unk_0;
} lbl_1_rodata_9C;

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

typedef struct PadSrc {
    u16 button;
    u8 flags;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    s8 err;
} PadSrc;


/* TU .data, in retail order (addressed off one section base) */
char lbl_1_data_2A40[] = "OVERTAKE";
char lbl_1_data_2A4C[] = "JUMP";
char lbl_1_data_2A54[] = "ENEMYHIT";
char lbl_1_data_2A60[] = "WALLHIT";
char lbl_1_data_2A68[] = "SIDEBYSIDE";
char lbl_1_data_2A74[] = "START";
char lbl_1_data_2A7C[] = "GOAL";
char fzgx_pool_lbl_1_data_2A84[0x3C] = "LAP";
u8 lbl_1_data_2AC0[0x80] = {
    0x4B, 0x00, 0x35, 0x35, 0x00, 0x4B, 0xCB, 0x35, 0xB5, 0x00, 0xCB, 0xCB, 0x00, 0xB5, 0x35, 0xCB,
    0x4B, 0x00, 0x35, 0x35, 0x00, 0x4B, 0xCB, 0x35, 0xB5, 0x00, 0xCB, 0xCB, 0x00, 0xB5, 0x35, 0xCB,
    0x4B, 0x00, 0x35, 0x35, 0x00, 0x4B, 0xCB, 0x35, 0xB5, 0x00, 0xCB, 0xCB, 0x00, 0xB5, 0x35, 0xCB,
    0x4B, 0x00, 0x35, 0x35, 0x00, 0x4B, 0xCB, 0x35, 0xB5, 0x00, 0xCB, 0xCB, 0x00, 0xB5, 0x35, 0xCB,
    0x4B, 0x00, 0x35, 0x35, 0x00, 0x4B, 0xCB, 0x35, 0xB5, 0x00, 0xCB, 0xCB, 0x00, 0xB5, 0x35, 0xCB,
    0x4B, 0x00, 0x35, 0x35, 0x00, 0x4B, 0xCB, 0x35, 0xB5, 0x00, 0xCB, 0xCB, 0x00, 0xB5, 0x35, 0xCB,
    0x4B, 0x00, 0x35, 0x35, 0x00, 0x4B, 0xCB, 0x35, 0xB5, 0x00, 0xCB, 0xCB, 0x00, 0xB5, 0x35, 0xCB,
    0x4B, 0x00, 0x35, 0x35, 0x00, 0x4B, 0xCB, 0x35, 0xB5, 0x00, 0xCB, 0xCB, 0x00, 0xB5, 0x35, 0xCB,
};
u8 lbl_1_data_2B40[0x10] = { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 };
u8 lbl_1_data_2B50[8] = { 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78 };
u8 lbl_1_data_2B58[8] = { 6, 6, 6, 6, 6, 6, 6, 6 };
u8 lbl_1_data_2B60[4] = { 1, 1, 1, 1 };
u8 lbl_1_data_2B64 = 1;
u32 lbl_1_data_2B68[4] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
u8 lbl_1_data_2B78[4] = { 1, 1, 1, 1 };

/* TU .bss: reset/recalibrate masks, SI types, held buttons */
u32 lbl_1_bss_978;
u32 lbl_1_bss_978__fzgx_offset_4;
u32 lbl_1_bss_980[4];
u16 lbl_1_bss_990[4];

extern void fn_1_15665C(u32, s32);
extern void fn_1_156730(s32);
extern void fn_1_D332C(Sig_fn_8001CF80_PADStatus *);
extern void fn_80008BA8(void *, void *, u32);
extern u32 PADRead(Sig_fn_8001CF80_PADStatus *);
extern u32 SIProbe(s32);
extern s32 fn_8006B294(s32, u32 *);
extern void fn_8006B470(void *);
extern void fn_80008BEC(void *, int, u32);
extern BOOL PADRecalibrate(u32);
extern int PADReset(u32);

#define resetBits lbl_1_bss_978
#define recalBits lbl_1_bss_978__fzgx_offset_4
#define siType lbl_1_bss_980
#define heldButtons lbl_1_bss_990
#define padReady lbl_1_data_2B64
#define gbaIds lbl_1_data_2B68
#define gbaStates lbl_1_data_2B78

/* layout primer: touches the .bss objects in retail order */


#pragma section code_type ".fzgxpool"
static void fzgx_base_order_data(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: the TU references .data before its other sections */
    s = *(u8 *)&lbl_1_data_2A40;
    s = *(u8 *)&lbl_1_data_2A4C;
    s = *(u8 *)&lbl_1_data_2A54;
    s = *(u8 *)&lbl_1_data_2A60;
    s = *(u8 *)&lbl_1_data_2A68;
    s = *(u8 *)&lbl_1_data_2A74;
    s = *(u8 *)&lbl_1_data_2A7C;
    s = *(u8 *)&fzgx_pool_lbl_1_data_2A84;
    s = *(u8 *)&lbl_1_data_2AC0;
    s = *(u8 *)&lbl_1_data_2B40;
    s = *(u8 *)&lbl_1_data_2B50;
    s = *(u8 *)&lbl_1_data_2B58;
    s = *(u8 *)&lbl_1_data_2B60;
    s = lbl_1_data_2B64;
    s = *(u8 *)&lbl_1_data_2B68;
    s = *(u8 *)&lbl_1_data_2B78;
}
#pragma section code_type ".text"

#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_primer(void) {
    lbl_1_bss_978 = 0;
    lbl_1_bss_978__fzgx_offset_4 = 0;
    lbl_1_bss_980[0] = 0;
    lbl_1_bss_990[0] = 0;
}

void fn_1_1304(Sig_fn_8001CF80_PADStatus *pads) {
    s32 i;
    u32 r;
    u32 chan;
    u32 bits;
    u32 t;
    Sig_fn_8001CF80_PADStatus old[4];
    PadSrc src[4];
    u32 lab_t2;

    fn_80008BA8(old, pads, sizeof(old));
    PADRead(pads);

    for (i = 0; i < 4; i++) {
        siType[i] = SIProbe(i);
        switch (siType[i]) {
        case 0x08000000:
            if (gbaIds[i] == -1) {
                fn_8006B294(i, &gbaIds[i]);
                fn_1_15665C(gbaIds[i], i);
                gbaStates[i] = 0;
            }
            break;
        case 0x09000000:
        case 0x88000000:
        case 0x8B100000:
            if (gbaStates[i] != 1) {
                gbaStates[i] = 1;
            }
            break;
        case 0x80:
        case 0x8:
        default:
            if (gbaStates[i] != 0) {
                if (gbaIds[i] != -1) {
                    fn_1_156730(i);
                    gbaIds[i] = -1;
                }
                gbaStates[i] = 0;
            }
            break;
        }
    }

    if (gbaIds[0] != -1 || gbaIds[1] != -1 || gbaIds[2] != -1 || gbaIds[3] != -1) {
        fn_8006B470(src);
        for (i = 0; i < 4; i++) {
            if (src[i].err != -1) {
                if (src[i].flags & 8) {
                    gbaStates[i] = 3;
                } else {
                    gbaStates[i] = 2;
                }
                pads[i].button = src[i].button;
                pads[i].stickX = src[i].b3;
                pads[i].stickY = 0;
                pads[i].substickX = 0;
                pads[i].substickY = 0;
                pads[i].triggerLeft = src[i].b7;
                pads[i].triggerRight = src[i].b8;
                if (src[i].flags & 8) {
                    pads[i].analogA = lbl_1_rodata_9C.unk_0 * src[i].b4;
                    pads[i].analogB = lbl_1_rodata_9C.unk_0 * src[i].b5;
                } else {
                    pads[i].analogA = 0;
                    pads[i].analogB = 0;
                }
                pads[i].err = 0;
            }
        }
    }

    for (i = 0; i < 4; i++) {
        if (pads[i].err == -3) {
            if (old[i].err) {
                fn_80008BEC(&pads[i], 0, 12);
            } else {
                lab_t2 = 12;
                fn_80008BA8(&pads[i], &old[i], lab_t2);
            }
        }
    }

    padReady = 1;
    for (i = 0; i < 4; i++) {
        pads[i].button |= heldButtons[i];
        heldButtons[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        if (pads[i].err == -1) {
            resetBits |= 0x80000000 >> i;
        }
    }

    if (recalBits != 0) {
        bits = recalBits;
        while (bits != 0) {
            chan = __cntlzw(bits);
            if (pads[chan].err) {
                recalBits &= ~(0x80000000 >> chan);
            }
            bits &= ~(0x80000000 >> chan);
        }
        if (recalBits != 0) {
            r = PADRecalibrate(recalBits);
            t = (s32)(-r | r) >> 31;
            r = resetBits | recalBits;
            recalBits = 0;
            resetBits = r & ~t;
        }
    }

    if (resetBits != 0) {
        if (PADReset(resetBits)) {
            recalBits = resetBits;
        }
        resetBits = 0;
    }

    fn_1_D332C(pads);
}
/* fzgx:end fn_1_1304 */

/* fzgx:begin fn_1_17C8 */
extern struct ArenaData lbl_1_data_8;
extern struct fn_1_634_lbl_1_bss_54 lbl_1_bss_54;
extern struct fn_1_904_lbl_1_bss_4 lbl_1_bss_4;
extern struct fn_1_914_lbl_1_bss_0 lbl_1_bss_0;
extern struct fn_1_12B4_lbl_1_bss_962 lbl_1_bss_962;
extern struct fn_1_798_slot lbl_1_bss_8E7E4[];



/* Ideal octagonal gate of the control stick. */
static const StickPoint fn_1_17C8_fzgx_pool_lbl_1_rodata_70[8] = {
    { 108, 0 }, { 108, 108 }, { 0, 108 }, { -108, 108 },
    { -108, 0 }, { -108, -108 }, { 0, -108 }, { 108, -108 },
};
const u8 fzgx_pool_fzgx_rodata_80[0x28] = {
    0x00, 0x10, 0x00, 0x04, 0x00, 0x20, 0x80, 0x00,
    0x00, 0x20, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x08, 0x00, 0x3e, 0xc8, 0xc8, 0xc9,
    0x43, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

void fn_1_17C8(s8 *outX, s8 *outY, StickPoint *gate, u8 *dz) {
    s32 i;
    for (i = 0; i < 8; i++) {
        f32 inv;
        f32 s;
        f32 t;
        s32 j = (i == 7) ? 0 : i + 1;
        f32 x0 = gate[i].x;
        f32 y0 = gate[i].y;
        f32 x1 = gate[j].x;
        f32 y1 = gate[j].y;
        f32 det = (f32)(x0 * y1) - (f32)(x1 * y0);
        s32 n;
        s32 neg;
        s32 q;
        s32 c;
        s32 sign;
        if (__fabs(det) < 1.1920928955078125e-07) {
            continue;
        }
        inv = 1.0f / det;
        s = inv * ((f32)(y1 * *outX) - (f32)(x1 * *outY));
        t = inv * ((f32)(-y0 * *outX) + (f32)(x0 * *outY));
        if (s < 0.0f || t < 0.0f) {
            continue;
        }
        n = (f32)(s * fn_1_17C8_fzgx_pool_lbl_1_rodata_70[i].x) + (f32)(t * fn_1_17C8_fzgx_pool_lbl_1_rodata_70[j].x);
        neg = (u32)n >> 31;
        q = ((__abs(n) - dz[0]) * 100) / (100 - dz[0]);
        c = q < 0 ? 0 : (q > 100 ? 100 : q);
        sign = neg ? -1 : 1;
        *outX = sign * c;
        n = (f32)(s * fn_1_17C8_fzgx_pool_lbl_1_rodata_70[i].y) + (f32)(t * fn_1_17C8_fzgx_pool_lbl_1_rodata_70[j].y);
        neg = (u32)n >> 31;
        q = ((__abs(n) - dz[1]) * 100) / (100 - dz[1]);
        c = q < 0 ? 0 : (q > 100 ? 100 : q);
        sign = neg ? -1 : 1;
        *outY = sign * c;
        return;
    }
}
/* fzgx:end fn_1_17C8 */

/* fzgx:begin fn_1_1ACC */
#define CLAMP(x, l, h) (((x) < (l)) ? (l) : (((x) > (h)) ? (h) : (x)))

s8 fn_1_1ACC(s8 arg0, u8 *arg1, u8 *arg2) {
    s32 val;
    s32 diff;
    BOOL is_neg;
    u32 total;
    s32 res;

    if (arg0 == 0) {
        return 0;
    }

    if (arg0 < 0) {
        val = CLAMP(arg0, -arg1[1], 0);
        if (val >= -arg2[1]) {
            return 0;
        }
        diff = __abs(val) - arg2[1];
        is_neg = TRUE;
        total = arg1[1] - arg2[1];
    } else {
        val = CLAMP(arg0, 0, arg1[0]);
        if (val <= arg2[0]) {
            return 0;
        }
        diff = val - arg2[0];
        is_neg = FALSE;
        total = arg1[0] - arg2[0];
    }

    res = (s8)((diff * 100.0f) / total);
    if (is_neg) {
        res = -res;
    }
    return res;
}
/* fzgx:end fn_1_1ACC */

/* fzgx:begin fn_1_1C00 */
void fn_1_1C00(const u8 *values, u32 flags, u16 *result) {
    u8 value0;
    u8 value1;
    s32 value2;
    s32 value3;
    u32 mask;
    s32 limit;

    *result = 0;
    mask = flags & 0xffff;

    value0 = values[2];
    value1 = values[3];
    limit = (flags & 1) ? -15 : -20;
    if ((s8)value0 < limit) {
        *result |= 1;
    }

    limit = ((mask >> 1) & 1) ? 15 : 20;
    if ((s8)value0 > limit) {
        *result |= 2;
    }

    limit = ((mask >> 2) & 1) ? -15 : -20;
    if ((s8)value1 < limit) {
        *result |= 4;
    }

    limit = ((mask >> 3) & 1) ? 15 : 20;
    if ((s8)value1 > limit) {
        *result |= 8;
    }

    value0 = values[4];
    value1 = values[5];
    limit = ((mask >> 4) & 1) ? -15 : -20;
    if ((s8)value0 < limit) {
        *result |= 16;
    }

    limit = ((mask >> 5) & 1) ? 15 : 20;
    if ((s8)value0 > limit) {
        *result |= 32;
    }

    limit = ((mask >> 6) & 1) ? -15 : -20;
    if ((s8)value1 < limit) {
        *result |= 64;
    }

    limit = ((mask >> 7) & 1) ? 15 : 20;
    if ((s8)value1 > limit) {
        *result |= 128;
    }

    value2 = values[6];
    value3 = values[7];
    limit = ((mask >> 8) & 1) ? 40 : 80;
    if (value2 > limit) {
        *result |= 256;
    }

    limit = ((mask >> 9) & 1) ? 40 : 80;
    if (value3 > limit) {
        *result |= 512;
    }

    value2 = values[8];
    value3 = values[9];
    limit = ((mask >> 10) & 1) ? 70 : 90;
    if (value2 > limit) {
        *result |= 1024;
    }

    limit = ((mask >> 11) & 1) ? 70 : 90;
    if (value3 > limit) {
        *result |= 2048;
    }
}
/* fzgx:end fn_1_1C00 */

/* fzgx:begin fn_1_1DF0 */
u32 fn_1_1DF0(u16 *state, s8 *values, u32 flags) {
    u32 result;
    u32 selected;

    if (flags >> 31) {
        return 0;
    }
    if ((*state & flags & 0xf7f) != 0) {
        return 100;
    }
    selected = flags & 0x00fff000;
    if (selected == 0) {
        return 0;
    }

    result = 0;
    if ((selected >> 12) & 1) {
        if (values[0] < 0 && (u8)result < -values[0]) {
            result = (u8)-values[0];
        }
    }
    if ((selected >> 13) & 1) {
        if (values[0] > 0 && (u8)result < values[0]) {
            result = (u8)values[0];
        }
    }
    if ((selected >> 14) & 1) {
        if (values[1] < 0 && (u8)result < -values[1]) {
            result = (u8)-values[1];
        }
    }
    if ((selected >> 15) & 1) {
        if (values[1] > 0 && (u8)result < values[1]) {
            result = (u8)values[1];
        }
    }
    if ((selected >> 16) & 1) {
        if (values[2] < 0 && (u8)result < -values[2]) {
            result = (u8)-values[2];
        }
    }
    if ((selected >> 17) & 1) {
        if (values[2] > 0 && (u8)result < values[2]) {
            result = (u8)values[2];
        }
    }
    if ((selected >> 18) & 1) {
        if (values[3] < 0 && (u8)result < -values[3]) {
            result = (u8)-values[3];
        }
    }
    if ((selected >> 19) & 1) {
        if (values[3] > 0 && (u8)result < values[3]) {
            result = (u8)values[3];
        }
    }
    if ((selected >> 20) & 1) {
        u32 value = (u8)values[4];
        if ((u8)result < value) {
            result = value;
        }
    }
    if ((selected >> 21) & 1) {
        u32 value = (u8)values[5];
        if ((u8)result < value) {
            result = value;
        }
    }
    if ((selected >> 22) & 1) {
        u32 value = (u8)values[6];
        if ((u8)result < value) {
            result = value;
        }
    }
    if ((selected >> 23) & 1) {
        u32 value = (u8)values[7];
        if ((u8)result < value) {
            result = value;
        }
    }
    return result;
}
/* fzgx:end fn_1_1DF0 */

/* fzgx:begin fn_1_1FE8 */
#ifndef GAME_MAIN_REL__PROLOG_TYPES_H
#define GAME_MAIN_REL__PROLOG_TYPES_H

#endif  // GAME_MAIN_REL__PROLOG_TYPES_H


s8 fn_1_1FE8(u16 *arg0, struct fn_1_1FE8_Arg1 *arg1, u32 arg2, s8 arg3) {
    u32 v1 = (u16)arg2;
    s8 v5 = 0;
    u8 *v7;
    u16 v2;
    u32 v6;
    u32 v3;
    s32 v0;
    if ((arg2 >> 15) & 1) return 0;
    v6 = v1 & 15;
    if (v6) {
        v2 = *arg0;
        v3 = __cntlzw(v6);
        while (v6 != 0) {
            v7 = &lbl_1_rodata_C4[(31-v3)*2];
            if (__rlwnm(v2, (v7[0]+1)&31, 31, 31)) v5 -= 25;
            if (__rlwnm(v2, (v7[1]+1)&31, 31, 31)) v5 += 25;
            v6 &= ~(0x80000000U >> v3);
            v3 = __cntlzw(v6);
        }
    }
    if (v5 != 0) {
        v0 = arg3 + v5;
        v5 = (v0 < -100) ? -100 : ((v0 > 100) ? 100 : v0);
    }
    v1 = arg2 & 0x3f0;
    if (!v1) return v5;
    if ((v1 >> 4) & 1) { if (v5 < __abs(arg1->unk_0)) v5 = arg1->unk_0; }
    if ((v1 >> 5) & 1) { if (v5 < __abs(arg1->unk_1)) v5 = arg1->unk_1; }
    if ((v1 >> 6) & 1) { if (v5 < __abs(arg1->unk_2)) v5 = arg1->unk_2; }
    if ((v1 >> 7) & 1) { if (v5 < __abs(arg1->unk_3)) v5 = arg1->unk_3; }
    if ((v1 >> 8) & 1) { if (v5 < __abs(arg1->unk_5 - arg1->unk_4)) v5 = arg1->unk_5 - arg1->unk_4; }
    if ((v1 >> 9) & 1) { s32 v27 = arg1->unk_6 - arg1->unk_7; if (v5 < __abs(v27)) v5 = v27; }
    return v5;
}
/* fzgx:end fn_1_1FE8 */

/* fzgx:begin fn_1_21E4 noprologue */
#include "types.h"

#define CLAMP(x, l, h) (((x) < (l)) ? (l) : (((x) > (h)) ? (h) : (x)))

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

typedef struct InputControl {
    u8 unk_0;
    s8 unk_1;
    s8 unk_2;
    s8 unk_3;
    u8 unk_4;
    u8 unk_5;
} InputControl;

typedef struct InputConfig {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
} InputConfig;

typedef struct {
    s8 x;
    s8 y;
} StickPoint;

struct fn_1_1FE8_Arg1;
extern s32 fn_1_3EFA8(void);
extern u8 fn_1_3BB0(u32);
extern u32 fn_1_1DF0(u16 *, s8 *, u32);
extern s8 fn_1_1FE8(u16 *, struct fn_1_1FE8_Arg1 *, u32, s8);
extern void fn_80008BEC(void *, int, u32);

/* TU .data, in retail order (addressed off one section base) */
char lbl_1_data_2A40[] = "OVERTAKE";
char lbl_1_data_2A4C[] = "JUMP";
char lbl_1_data_2A54[] = "ENEMYHIT";
char lbl_1_data_2A60[] = "WALLHIT";
char lbl_1_data_2A68[] = "SIDEBYSIDE";
char lbl_1_data_2A74[] = "START";
char lbl_1_data_2A7C[] = "GOAL";
char fzgx_pool_lbl_1_data_2A84[0x3C] = "LAP";
StickPoint lbl_1_data_2AC0[4][8] = {
        { { 75, 0 }, { 53, 53 }, { 0, 75 }, { -53, 53 }, { -75, 0 }, { -53, -53 }, { 0, -75 }, { 53, -53 } },
        { { 75, 0 }, { 53, 53 }, { 0, 75 }, { -53, 53 }, { -75, 0 }, { -53, -53 }, { 0, -75 }, { 53, -53 } },
        { { 75, 0 }, { 53, 53 }, { 0, 75 }, { -53, 53 }, { -75, 0 }, { -53, -53 }, { 0, -75 }, { 53, -53 } },
        { { 75, 0 }, { 53, 53 }, { 0, 75 }, { -53, 53 }, { -75, 0 }, { -53, -53 }, { 0, -75 }, { 53, -53 } },
};
StickPoint lbl_1_data_2B00[4][8] = {
        { { 75, 0 }, { 53, 53 }, { 0, 75 }, { -53, 53 }, { -75, 0 }, { -53, -53 }, { 0, -75 }, { 53, -53 } },
        { { 75, 0 }, { 53, 53 }, { 0, 75 }, { -53, 53 }, { -75, 0 }, { -53, -53 }, { 0, -75 }, { 53, -53 } },
        { { 75, 0 }, { 53, 53 }, { 0, 75 }, { -53, 53 }, { -75, 0 }, { -53, -53 }, { 0, -75 }, { 53, -53 } },
        { { 75, 0 }, { 53, 53 }, { 0, 75 }, { -53, 53 }, { -75, 0 }, { -53, -53 }, { 0, -75 }, { 53, -53 } },
};
u8 lbl_1_data_2B40[4][2] = { { 8, 8 }, { 8, 8 }, { 8, 8 }, { 8, 8 } };
u8 lbl_1_data_2B48[4][2] = { { 8, 8 }, { 8, 8 }, { 8, 8 }, { 8, 8 } };
u8 lbl_1_data_2B50[4][2] = { { 0x78, 0x78 }, { 0x78, 0x78 }, { 0x78, 0x78 }, { 0x78, 0x78 } };
u8 lbl_1_data_2B58[4][2] = { { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 } };
u8 lbl_1_data_2B60[4] = { 1, 1, 1, 1 };
u8 lbl_1_data_2B64 = 1;
u32 lbl_1_data_2B68[4] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
u8 lbl_1_data_2B78[4] = { 1, 1, 1, 1 };

/* TU .bss */
u32 lbl_1_bss_978[2];
u32 lbl_1_bss_980[4];
u16 lbl_1_bss_990[4];
InputPad lbl_1_bss_990__fzgx_offset_8[4];
InputPad lbl_1_bss_9C8[4];
InputPortButtons fzgx_obj_lbl_1_bss_9F8[4];
InputPortAxes fzgx_obj_lbl_1_bss_A48[4];
InputControl fzgx_obj_lbl_1_bss_A88[4];
InputConfig fzgx_obj_lbl_1_bss_AA0[4][3];

/* Ideal octagonal gate of the control stick. */
static const StickPoint fzgx_pool_lbl_1_rodata_70[8] = {
    { 108, 0 }, { 108, 108 }, { 0, 108 }, { -108, 108 },
    { -108, 0 }, { -108, -108 }, { 0, -108 }, { 108, -108 },
};
static const InputConfig fzgx_pool_lbl_1_rodata_80 = {
    0x0010, 0x0004, 0x0020, 0x8000, 0x00200000, 0x00100000, 0x80000000, 0x80000000, 0x00000800,
};

#pragma section code_type ".fzgxpool"
static void fzgx_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink */
    s = *(u8 *)&lbl_1_data_2A40;
    s = *(u8 *)&lbl_1_data_2A4C;
    s = *(u8 *)&lbl_1_data_2A54;
    s = *(u8 *)&lbl_1_data_2A60;
    s = *(u8 *)&lbl_1_data_2A68;
    s = *(u8 *)&lbl_1_data_2A74;
    s = *(u8 *)&lbl_1_data_2A7C;
    s = *(u8 *)&fzgx_pool_lbl_1_data_2A84;
    s = *(u8 *)&lbl_1_data_2AC0;
    s = *(u8 *)&lbl_1_data_2B00;
    s = *(u8 *)&lbl_1_data_2B40;
    s = *(u8 *)&lbl_1_data_2B48;
    s = *(u8 *)&lbl_1_data_2B50;
    s = *(u8 *)&lbl_1_data_2B58;
    s = *(u8 *)&lbl_1_data_2B60;
    s = lbl_1_data_2B64;
    s = *(u8 *)&lbl_1_data_2B68;
    s = *(u8 *)&lbl_1_data_2B78;
    s = *(u8 *)&lbl_1_bss_978;
    s = *(u8 *)&lbl_1_bss_980;
    s = *(u8 *)&lbl_1_bss_990;
    s = *(u8 *)&lbl_1_bss_990__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_9C8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_9F8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_A48;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_A88;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_AA0;
}
#pragma section code_type ".text"


#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime(void) {
    volatile f32 s; volatile f64 d; const void *volatile cp;  /* fzgx-allow: S2 pool primer sinks */
    cp = fzgx_pool_lbl_1_rodata_70;
    cp = &fzgx_pool_lbl_1_rodata_80;
    s = 0.39215687f;
    d = 4503599627370496.0;
    d = 1.1920928955078125e-07;
    s = 1.0f;
    s = 0.0f;
    d = 4503601774854144.0;
    s = 100.0f;
}
#pragma section code_type ".text"

static const u8 lbl_1_rodata_C4[4][2] = { { 0x1F, 0x1E }, { 0x1D, 0x1C }, { 0x16, 0x17 }, { 0x14, 0x15 } };
static const u8 lbl_1_rodata_CC[10][3] = {
    { 1, 0x1F, 0x1E }, { 1, 0x1D, 0x1C }, { 1, 0x16, 0x17 }, { 1, 0x14, 0x15 }, { 0, 0x1F, 0x1E },
    { 0, 0x1D, 0x1C }, { 0, 0x1B, 0x1A }, { 0, 0x19, 0x18 }, { 0, 0x17, 0x16 }, { 0, 0x14, 0x15 },
};

#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d; const void *volatile cp;  /* fzgx-allow: S2 pool primer sinks */
    cp = lbl_1_rodata_C4;
    cp = lbl_1_rodata_CC;
    d = 0.1;
    s = 0.54347825f;
}
#pragma section code_type ".text"

static inline s8 axis_from_digital(s8 arg0, u8 *arg1, u8 *arg2) {
    s32 val;
    s32 diff;
    BOOL is_neg;
    u32 total;
    s32 res;

    if (arg0 == 0) {
        return 0;
    }

    if (arg0 < 0) {
        val = CLAMP(arg0, -arg1[1], 0);
        if (val >= -arg2[1]) {
            return 0;
        }
        diff = __abs(val) - arg2[1];
        is_neg = TRUE;
        total = arg1[1] - arg2[1];
    } else {
        val = CLAMP(arg0, 0, arg1[0]);
        if (val <= arg2[0]) {
            return 0;
        }
        diff = val - arg2[0];
        is_neg = FALSE;
        total = arg1[0] - arg2[0];
    }

    res = (s8)((diff * 100.0f) / total);
    if (is_neg) {
        res = -res;
    }
    return res;
}

static inline void stick_to_gate(s8 *outX, s8 *outY, StickPoint *gate, u8 *dz) {
    s32 i;
    for (i = 0; i < 8; i++) {
        f32 inv;
        f32 s;
        f32 t;
        s32 j = (i == 7) ? 0 : i + 1;
        f32 x0 = gate[i].x;
        f32 y0 = gate[i].y;
        f32 x1 = gate[j].x;
        f32 y1 = gate[j].y;
        f32 det = (f32)(x0 * y1) - (f32)(x1 * y0);
        s32 n;
        s32 neg;
        s32 q;
        s32 c;
        s32 sign;
        if (__fabs(det) < 1.1920928955078125e-07) {
            continue;
        }
        inv = 1.0f / det;
        s = inv * ((f32)(y1 * *outX) - (f32)(x1 * *outY));
        t = inv * ((f32)(-y0 * *outX) + (f32)(x0 * *outY));
        if (s < 0.0f || t < 0.0f) {
            continue;
        }
        n = (f32)(s * fzgx_pool_lbl_1_rodata_70[i].x) + (f32)(t * fzgx_pool_lbl_1_rodata_70[j].x);
        neg = (u32)n >> 31;
        q = ((__abs(n) - dz[0]) * 100) / (100 - dz[0]);
        c = q < 0 ? 0 : (q > 100 ? 100 : q);
        sign = neg ? -1 : 1;
        *outX = sign * c;
        n = (f32)(s * fzgx_pool_lbl_1_rodata_70[i].y) + (f32)(t * fzgx_pool_lbl_1_rodata_70[j].y);
        neg = (u32)n >> 31;
        q = ((__abs(n) - dz[1]) * 100) / (100 - dz[1]);
        c = q < 0 ? 0 : (q > 100 ? 100 : q);
        sign = neg ? -1 : 1;
        *outY = sign * c;
        return;
    }
}

static inline BOOL button_held(u16 *state, u32 flags) {
    u32 selected;
    u16 analog;
    BOOL held;

    if (flags >> 31) {
        return FALSE;
    }
    if ((state[0] & flags & 0xf7f) != 0) {
        held = TRUE;
    } else {
        selected = flags & 0x00fff000;
        analog = state[1];
        if (selected == 0) {
            held = FALSE;
        } else if (analog & (selected >> 12)) {
            held = TRUE;
        } else {
            held = FALSE;
        }
    }
    return held;
}

static inline s32 button_direction(u16 *state, u16 flags) {
    const u8 *e;
    u16 v;
    u32 bits;
    u32 n;
    s32 dir = 0;

    if ((flags >> 15) & 1) {
        return 0;
    }
    bits = flags;
    n = __cntlzw(bits);
    while (bits != 0) {
        e = lbl_1_rodata_CC[31 - n];
        if (e[0] == 0) {
            v = state[1];
        } else {
            v = state[0];
        }
        if (__rlwnm(v, (e[1] + 1) & 31, 31, 31)) {
            dir--;
        }
        if (__rlwnm(v, (e[2] + 1) & 31, 31, 31)) {
            dir++;
        }
        bits &= ~(0x80000000 >> n);
        n = __cntlzw(bits);
    }
    if (dir < 0) {
        return -1;
    }
    if (dir > 0) {
        return 1;
    }
    return 0;
}

static inline BOOL button_combo(u16 *state, InputAxes *axes, u16 flags) {
    u16 v;
    u32 bits;
    u32 n;
    const u8 *e;

    if ((flags >> 15) & 1) {
        return FALSE;
    }
    bits = flags & 0xf;
    if (bits != 0) {
        v = state[0];
        n = __cntlzw(bits);
        while (bits != 0) {
            e = lbl_1_rodata_C4[31 - n];
            if (__rlwnm(v, (e[0] + 1) & 31, 31, 31) && __rlwnm(v, (e[1] + 1) & 31, 31, 31)) {
                return TRUE;
            }
            bits &= ~(0x80000000 >> n);
            n = __cntlzw(bits);
        }
    }
    bits = flags & 0x3f0;
    if (bits == 0) {
        return FALSE;
    }
    if (((bits >> 4) & 1) || ((bits >> 5) & 1) || ((bits >> 6) & 1) || ((bits >> 7) & 1)) {
        return FALSE;
    }
    if ((bits >> 8) & 1) {
        if (axes->triggerRight > 0.1 && axes->triggerLeft > 0.1) {
            return TRUE;
        }
    }
    if ((bits >> 9) & 1) {
        if (axes->analogA > 0.1 && axes->analogB > 0.1) {
            return TRUE;
        }
    }
    return FALSE;
}

void fn_1_21E4(InputAxes *axes) {
    u32 i;
    InputPortButtons *buttons;
    InputAxes *out;
    InputControl *control;
    InputPad *pad;
    const InputConfig *cfg;
    s32 dir;

    if (fn_1_3EFA8() != 0) {
        return;
    }
    out = axes;
    pad = lbl_1_bss_9C8;
    buttons = fzgx_obj_lbl_1_bss_9F8;
    control = fzgx_obj_lbl_1_bss_A88;
    for (i = 0; i < 4; i++, pad++, buttons++, control++, out++) {
        if (pad->err == -1) {
            fn_80008BEC(control, 0, sizeof(InputControl));
            fn_80008BEC(out, 0, sizeof(InputAxes));
            continue;
        }
        out->triggerLeft = CLAMP(pad->triggerLeft - 16, 0, 184) * 0.54347825f;
        out->triggerRight = CLAMP(pad->triggerRight - 16, 0, 184) * 0.54347825f;
        if (lbl_1_data_2B78[i] == 2 || lbl_1_data_2B78[i] == 3) {
            out->stickX = axis_from_digital(pad->stickX, lbl_1_data_2B50[i], lbl_1_data_2B58[i]);
            out->stickY = 0;
            out->substickX = 0;
            out->substickY = 0;
        } else {
            out->stickX = pad->stickX;
            out->stickY = pad->stickY;
            out->substickX = pad->substickX;
            out->substickY = pad->substickY;
            stick_to_gate(&out->stickX, &out->stickY, lbl_1_data_2AC0[i], lbl_1_data_2B40[i]);
            stick_to_gate(&out->substickX, &out->substickY, lbl_1_data_2B00[i], lbl_1_data_2B48[i]);
        }
        out->analogA = pad->analogA;
        out->analogB = pad->analogB;
        switch (fn_1_3BB0(i)) {
        default:
            cfg = &fzgx_obj_lbl_1_bss_AA0[i][0];
            break;
        case 2:
            cfg = &fzgx_obj_lbl_1_bss_AA0[i][1];
            break;
        case 3:
            cfg = &fzgx_obj_lbl_1_bss_AA0[i][2];
            break;
        case 4:
            cfg = &fzgx_pool_lbl_1_rodata_80;
            break;
        }
        control->unk_4 = fn_1_1DF0(&buttons->unk_0.button, (s8 *)out, cfg->unk_8);
        control->unk_5 = fn_1_1DF0(&buttons->unk_0.button, (s8 *)out, cfg->unk_C);
        control->unk_1 = fn_1_1FE8(&buttons->unk_0.button, (struct fn_1_1FE8_Arg1 *)out, cfg->unk_0, control->unk_1);
        control->unk_3 = fn_1_1FE8(&buttons->unk_0.button, (struct fn_1_1FE8_Arg1 *)out, cfg->unk_2, control->unk_3);
        control->unk_2 = fn_1_1FE8(&buttons->unk_0.button, (struct fn_1_1FE8_Arg1 *)out, cfg->unk_4, control->unk_2);
        control->unk_0 = 0;
        if (button_held(&buttons->unk_0.button, cfg->unk_10)) {
            control->unk_0 |= 0x80;
        }
        if (button_held(&buttons->unk_0.button, cfg->unk_14)) {
            control->unk_0 |= 0x20;
        }
        if (button_held(&buttons->unk_0.button, cfg->unk_18)) {
            control->unk_0 |= 0x40;
        }
        dir = button_direction(&buttons->unk_0.button, cfg->unk_6);
        if (dir > 0) {
            control->unk_0 |= 0x01;
        }
        if (dir < 0) {
            control->unk_0 |= 0x02;
        }
        if (button_combo(&buttons->unk_0.button, out, cfg->unk_2)) {
            control->unk_0 |= 0x10;
        }
    }
}
/* fzgx:end fn_1_21E4 */

/* fzgx:begin fn_1_2F04 noprologue */
typedef signed char s8;

typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern u8 lbl_1_data_2B78[];
extern void fn_80008BEC(void *, int, u32);
typedef struct {
u8 pad0[10];
s8 state;
u8 padB;
} Fn1_2F04_Slot;
typedef struct {
u16 enable0;
u16 enable1;
u16 pad4;
u16 pad6;
u16 held0;
u16 held1;
u16 padC;
u16 padE;
u16 out0;
u16 out1;
} Fn1_2F04_Bits;
/* bit n of a mask word, as a rotate-and-mask */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_978[2];
u32 lbl_1_bss_980[4];
u32 lbl_1_bss_990[14];
u8 lbl_1_bss_9C8;
u8 lbl_1_bss_9C8__fzgx_offset_1;
u16 lbl_1_bss_9C8__fzgx_offset_2;
u32 lbl_1_bss_9C8__fzgx_offset_4[11];
u8 fzgx_obj_lbl_1_bss_9F8;
u8 lbl_1_bss_9F8__fzgx_offset_1;
u16 lbl_1_bss_9F8__fzgx_offset_2;
u32 lbl_1_bss_9F8__fzgx_offset_4[19];
u8 fzgx_obj_lbl_1_bss_A48;
u8 lbl_1_bss_A48__fzgx_offset_1;
u16 lbl_1_bss_A48__fzgx_offset_2;
u32 lbl_1_bss_A48__fzgx_offset_4[15];
u32 fzgx_obj_lbl_1_bss_A88[6];
u32 fzgx_obj_lbl_1_bss_AA0[84];
u32 lbl_1_bss_BF0[32];
u32 fzgx_obj_lbl_1_bss_C70[20];
u32 lbl_1_bss_CC0;
u8 lbl_1_bss_CC0__fzgx_offset_4;
u8 lbl_1_bss_CC0__fzgx_offset_5;
u16 lbl_1_bss_CC0__fzgx_offset_6;
u32 lbl_1_bss_CC0__fzgx_offset_8[12];
u8 lbl_1_bss_CC0__fzgx_offset_38;
u8 lbl_1_bss_CC0__fzgx_offset_39;
u16 lbl_1_bss_CC0__fzgx_offset_3A;
u32 lbl_1_bss_CC0__fzgx_offset_3C[11];
u8 lbl_1_bss_CC0__fzgx_offset_68;
u8 lbl_1_bss_CC0__fzgx_offset_69;
u16 lbl_1_bss_CC0__fzgx_offset_6A;
u32 lbl_1_bss_CC0__fzgx_offset_6C[11];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_978;
    s = *(u8 *)&lbl_1_bss_980;
    s = *(u8 *)&lbl_1_bss_990;
    s = lbl_1_bss_9C8;
    s = lbl_1_bss_9C8__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_9C8__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_9C8__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_9F8;
    s = lbl_1_bss_9F8__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_9F8__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_9F8__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_A48;
    s = lbl_1_bss_A48__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_A48__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_A48__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_A88;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_AA0;
    s = *(u8 *)&lbl_1_bss_BF0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_C70;
    s = *(u8 *)&lbl_1_bss_CC0;
    s = lbl_1_bss_CC0__fzgx_offset_4;
    s = lbl_1_bss_CC0__fzgx_offset_5;
    s = *(u8 *)&lbl_1_bss_CC0__fzgx_offset_6;
    s = *(u8 *)&lbl_1_bss_CC0__fzgx_offset_8;
    s = lbl_1_bss_CC0__fzgx_offset_38;
    s = lbl_1_bss_CC0__fzgx_offset_39;
    s = *(u8 *)&lbl_1_bss_CC0__fzgx_offset_3A;
    s = *(u8 *)&lbl_1_bss_CC0__fzgx_offset_3C;
    s = lbl_1_bss_CC0__fzgx_offset_68;
    s = lbl_1_bss_CC0__fzgx_offset_69;
    s = *(u8 *)&lbl_1_bss_CC0__fzgx_offset_6A;
    s = *(u8 *)&lbl_1_bss_CC0__fzgx_offset_6C;
}
#pragma section code_type ".text"

void fn_1_2F04(void) {
/* one-member carriers: each address is a single CSE'd materialisation */
struct { Fn1_2F04_Slot *value; } slot;
struct { u8 *value; } timer0;
struct { u8 *value; } timer1;
struct { u8 *value; } level_p;
struct { u8 *value; } mode;
Fn1_2F04_Bits *bits;
s8 *axes;
u32 i;
u8 *t;
s32 j;
u32 sh;
s32 held;
u8 *t2;
u8 *lv;
u32 mask;
s32 k;
s32 held2;
u8 cur;
s32 sh2;
u8 old;
u8 level;
bits = (Fn1_2F04_Bits *)(&fzgx_obj_lbl_1_bss_9F8);
axes = (s8 *)(&fzgx_obj_lbl_1_bss_A48);
slot.value = (Fn1_2F04_Slot *)(&lbl_1_bss_9C8);
timer0.value = &lbl_1_bss_CC0__fzgx_offset_4;
timer1.value = &lbl_1_bss_CC0__fzgx_offset_38;
level_p.value = &lbl_1_bss_CC0__fzgx_offset_68;
mode.value = lbl_1_data_2B78;
for (i = 0; i < 4; i++) {
if (slot.value->state == -1) {
fn_80008BEC(bits, 0, 20);
} else {
t = timer0.value;
for (j = 0; j < 13; t++, j++) {
sh = 31 - j;
if (sh == 24) {
continue;
}
if (__rlwnm(bits->held0, (32 - j) & 31, 31, 31) ) {
*t = 0;
held = 1;
} else {
held = 0;
if (*t != 0) {
(*t)--;
}
}
if (*t != 0 || !__rlwnm(bits->enable0, (32 - j) & 31, 31, 31) ) {
bits->out0 &= ~(0x80000000 >> sh);
} else {
if (held) {
*t = 20;
} else {
*t = 4;
}
bits->out0 |= 0x80000000 >> sh;
}
}
t2 = timer1.value;
lv = level_p.value;
for (k = 0; k < 12; t2++, lv++, k++) {
if (__rlwnm(bits->held1, (32 - k) & 31, 31, 31) ) {
*t2 = 0;
held2 = 1;
} else {
held2 = 0;
if (*t2 != 0) {
(*t2)--;
}
}
sh2 = 31 - k;
mask = 0x80000000 >> sh2;
bits->out1 &= ~mask;
cur = *t2;
if (cur == 0 && __rlwnm(bits->enable1, (32 - k) & 31, 31, 31) ) {
old = *lv;
switch (sh2) {
case 31:
case 30:
level = __abs(axes[0]);
break;
case 29:
case 28:
level = __abs(axes[1]);
break;
case 27:
case 26:
level = __abs(axes[2]);
break;
case 25:
case 24:
level = __abs(axes[3]);
break;
default:
level = 72;
break;
}
*lv = level;
if (held2) {
*t2 = 20;
} else if (level >= 30 && level >= old) {
if (*mode.value == 1) {
*t2 = (level * -4 + 340) / 13;
} else {
*t2 = (level * -17 + 1350) / 42;
}
} else {
continue;
}
bits->out1 |= mask;
}
}
}
slot.value++;
timer0.value += 13;
timer1.value += 12;
level_p.value += 12;
mode.value++;
bits++;
axes += 16;
}
}
/* fzgx:end fn_1_2F04 */

/* fzgx:begin fn_1_3238 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

extern struct ArenaData lbl_1_data_8;
extern u32 OSGetArenaLo(void);
extern u32 OSGetArenaHi(void);
extern void OSSetArenaLo(u32 arena_lo);
extern u16 lbl_1_bss_990[28];
extern u8 lbl_1_bss_D78;
extern u8 lbl_1_bss_DA6;
extern u32 lbl_1_bss_DB0[2];
extern u32 lbl_1_bss_DA8;
extern void fn_1_43A4(void);
extern u32 lbl_1_data_2C70;
extern void fn_80008E84(u32 value);
extern u32 lbl_1_bss_DAC;
extern struct fn_1_634_lbl_1_bss_54 lbl_1_bss_54;
extern u32 fn_8006FFC4(u32);
extern u32 fn_1_48780(void);
extern u32 lbl_801A66B4;
extern u32 lbl_801A66BC;
extern struct fn_1_904_lbl_1_bss_4 lbl_1_bss_4;
extern struct fn_1_914_lbl_1_bss_0 lbl_1_bss_0;
extern u16 lbl_1_bss_96A;
extern u32 fn_1_37E98(void);
extern u32 lbl_1_bss_96C;
extern u32 camera_set_state_flag(u32);
extern u32 fn_1_D31E0(u32);
extern struct fn_1_12B4_lbl_1_bss_962 lbl_1_bss_962;
extern u32 lbl_1_data_2A20;
extern u32 lbl_1_data_7C0;
extern u32 fn_1_15659C(u32);
extern u32 fn_80008BEC(void *, u32, u32);
extern u8 lbl_1_bss_978[];
extern u32 lbl_1_data_2B78;
extern u32 OSGetTick(u32);
extern u32 lbl_1_bss_D7C;
extern u8 lbl_1_bss_DA4;
extern char lbl_1_data_2C9C[20];
extern char lbl_1_data_2CB0[31];
extern void OSPanic(const char *message, int line, const char *file, ...);
extern void fn_80009AA8(u32 value, u32 count, const char *file, int line);
extern u32 fn_1_156754(u32);
extern u32 fn_1_A5864(void);
extern u32 fn_1_F7578(void);
extern struct fn_1_3C98_lbl_1_bss_DA5 lbl_1_bss_DA5;
extern u32 fn_80008EC8(u32, u32, u32);
extern u32 fn_800793D4(u32, u32, u32);
extern struct fn_1_48B0_lbl_801A6CF8 lbl_801A6CF8;
extern u32 lbl_801A6CFC;
extern struct fn_1_44B4_lbl_1_bss_DB8 lbl_1_bss_DB8;
extern struct fn_1_4438_lbl_1_bss_DC4 lbl_1_bss_DC4;
extern u8 lbl_1_bss_8E6B0[308];
extern void fn_1_14FCE4(void *data, s32 value);
extern struct fn_1_798_slot lbl_1_bss_8E7E4[];
extern u8 lbl_1_bss_AA0[336];
extern u8 lbl_1_rodata_108[88];
extern u32 fn_80008BA8(void *, void *, u32);
extern void fn_1_3BDC(u32 arg0);
extern u32 fn_1_3C18(s32);

void fn_1_3238(void) {
    u8 *p_lbl_1_bss_978;
    u32 t9;
    p_lbl_1_bss_978 = (u8 *)&lbl_1_bss_978;
    fn_80008BEC((p_lbl_1_bss_978 + 80), 0, 48);
    fn_80008BEC((p_lbl_1_bss_978 + 32), 0, 48);
    fn_80008BEC((p_lbl_1_bss_978 + 128), 0, 80);
    fn_80008BEC((p_lbl_1_bss_978 + 208), 0, 64);
    fn_80008BEC((p_lbl_1_bss_978 + 272), 0, 24);
    fn_80008BEC((p_lbl_1_bss_978 + 840), 0, 4);
    fn_80008BEC((p_lbl_1_bss_978 + 844), 0, 52);
    fn_80008BEC((p_lbl_1_bss_978 + 896), 0, 48);
    fn_80008BEC((p_lbl_1_bss_978 + 944), 0, 48);
    t9 = fn_80008BEC((p_lbl_1_bss_978 + 24), 0, 8);
    fn_1_15659C(t9);
}
/* fzgx:end fn_1_3238 */

/* fzgx:begin fn_1_3308 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

/* one pad as PADRead returns it (PADStatus) */
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

/* one button word pair: the pad's buttons and the word fn_1_1C00 derives from the pad */
typedef struct InputButtons {
    u16 button;
    u16 unk_2;
} InputButtons;

/* .bss 0x9F8[port]: held, previous, pressed (held & ~previous), released (previous & ~held) */
typedef struct InputPortButtons {
    InputButtons unk_0;
    InputButtons unk_4;
    InputButtons unk_8;
    InputButtons unk_C;
    InputButtons unk_10;
} InputPortButtons;

/* the pad's stick, trigger and analog bytes */
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

/* .bss 0xA48[port] */
typedef struct InputPortAxes {
    InputAxes unk_0;
    InputAxes unk_8;
} InputPortAxes;

/* .bss 0xA88[port]: the 6-byte control record */
typedef struct InputControl {
    u8 unk_0;
    s8 unk_1;
    s8 unk_2;
    s8 unk_3;
    u8 unk_4;
    u8 unk_5;
} InputControl;

/* .bss 0xBF0[port]: the eight stick and trigger values as floats */
typedef struct InputAxisFloats {
    f32 value[8];
} InputAxisFloats;

/* .bss 0xC70[port]: record bytes 1..5 / 100 */
typedef struct InputControlFloats {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
} InputControlFloats;

extern void fn_1_1304(InputPad *pads);
extern void fn_80008BA8(void *dst, void *src, u32 size);
extern void PADClamp(InputPad *pads);
extern void fn_1_1C00(const u8 *values, u32 flags, u16 *result);
extern s32 fn_1_3FC28(void);
extern s32 fn_1_3EFA8(void);
extern void fn_1_21E4(InputAxes *axes);
extern void fn_1_F2820(InputControl *controls, u8 *newly, u8 *previous);
extern void fn_80008BEC(void *dst, int value, u32 size);
extern void fn_1_2F04(void);

/* the retail TU's .bss objects this function uses, at their retail offsets, so MWCC addresses them off one section base */
u32 lbl_1_bss_978[2];
u32 lbl_1_bss_980[4];
u16 lbl_1_bss_990[4];
InputPad lbl_1_bss_990__fzgx_offset_8[4];
InputPad lbl_1_bss_9C8[4];
InputPortButtons fzgx_obj_lbl_1_bss_9F8[4];
InputPortAxes fzgx_obj_lbl_1_bss_A48[4];
InputControl fzgx_obj_lbl_1_bss_A88[4];
u32 fzgx_obj_lbl_1_bss_AA0[84];
InputAxisFloats lbl_1_bss_BF0[4];
InputControlFloats fzgx_obj_lbl_1_bss_C70[4];
u8 lbl_1_bss_CC0[0x98];
InputPortButtons lbl_1_bss_D58__fzgx_offset_0;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_978;
    s = *(u8 *)&lbl_1_bss_980;
    s = *(u8 *)&lbl_1_bss_990;
    s = *(u8 *)&lbl_1_bss_990__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_9C8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_9F8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_A48;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_A88;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_AA0;
    s = *(u8 *)&lbl_1_bss_BF0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_C70;
    s = *(u8 *)&lbl_1_bss_CC0;
    s = *(u8 *)&lbl_1_bss_D58__fzgx_offset_0;
}
#pragma section code_type ".text"

/* per port: the button words and the stick bytes */
static inline void input_update_buttons(void) {
    InputPad *pad;
    InputPortButtons *buttons;
    InputPortAxes *stick;
    u32 port;

    pad = lbl_1_bss_990__fzgx_offset_8;
    buttons = fzgx_obj_lbl_1_bss_9F8;
    stick = fzgx_obj_lbl_1_bss_A48;
    for (port = 0; port < 4; port++) {
        buttons->unk_4 = buttons->unk_0;
        buttons->unk_0.button = pad->button;
        buttons->unk_8.button = buttons->unk_0.button & ~buttons->unk_4.button;
        buttons->unk_C.button = buttons->unk_4.button & ~buttons->unk_0.button;
        fn_1_1C00((const u8 *)pad, buttons->unk_4.unk_2, &buttons->unk_0.unk_2);
        stick->unk_8 = stick->unk_0;
        buttons->unk_8.unk_2 = buttons->unk_0.unk_2 & ~buttons->unk_4.unk_2;
        buttons->unk_C.unk_2 = buttons->unk_4.unk_2 & ~buttons->unk_0.unk_2;
        stick->unk_0.stickX = pad->stickX;
        stick->unk_0.stickY = pad->stickY;
        stick->unk_0.substickX = pad->substickX;
        stick->unk_0.substickY = pad->substickY;
        stick->unk_0.triggerLeft = pad->triggerLeft;
        stick->unk_0.triggerRight = pad->triggerRight;
        stick->unk_0.analogA = pad->analogA;
        stick->unk_0.analogB = pad->analogB;
        pad++;
        buttons++;
        stick++;
    }
}

/* per port: the record bytes and the stick values as floats */
static inline void input_update_floats(InputAxes *src, InputPad *pad) {
    InputControl *control;
    InputAxisFloats *axis;
    InputControlFloats *value;
    u32 port;

    control = fzgx_obj_lbl_1_bss_A88;
    axis = lbl_1_bss_BF0;
    value = fzgx_obj_lbl_1_bss_C70;
    for (port = 0; port < 4; port++) {
        value->unk_0 = control->unk_1 / 100.0f;
        value->unk_4 = control->unk_2 / 100.0f;
        value->unk_8 = control->unk_3 / 100.0f;
        value->unk_C = control->unk_4 / 100.0f;
        value->unk_10 = control->unk_5 / 100.0f;
        if (pad->err == -1) {
            fn_80008BEC(axis, 0, sizeof(InputAxisFloats));
        } else {
            axis->value[0] = src->stickX / 100.0f;
            axis->value[1] = src->stickY / 100.0f;
            axis->value[2] = src->substickX / 100.0f;
            axis->value[3] = src->substickY / 100.0f;
            axis->value[4] = src->triggerLeft / 100.0f;
            axis->value[5] = src->triggerRight / 100.0f;
            axis->value[6] = src->analogA / 100.0f;
            axis->value[7] = src->analogB / 100.0f;
        }
        pad++;
        src++;
        control++;
        axis++;
        value++;
    }
}

void fn_1_3308(void) {
    u8 previous[4];
    InputAxes axes[4];
    u8 *prev;
    InputPad *raw;

    fn_1_1304(lbl_1_bss_990__fzgx_offset_8);
    fn_80008BA8(lbl_1_bss_9C8, lbl_1_bss_990__fzgx_offset_8, sizeof(lbl_1_bss_9C8));
    PADClamp(lbl_1_bss_990__fzgx_offset_8);

    input_update_buttons();

    /* replay mode (rule flag 0x00800000), not paused: the replay keeps last frame's request bits */
    if (fn_1_3FC28() && !fn_1_3EFA8()) {
        InputControl *control;
        u32 port;

        control = fzgx_obj_lbl_1_bss_A88;
        for (port = 0; port < 4; port++) {
            (&lbl_1_bss_7EFD8.unk_20)[port] = control->unk_0;
            control++;
        }
    }
    /* each record's request bits before fn_1_21E4 rebuilds the records */
    prev = previous;
    previous[0] = fzgx_obj_lbl_1_bss_A88[0].unk_0;
    previous[1] = fzgx_obj_lbl_1_bss_A88[1].unk_0;
    previous[2] = fzgx_obj_lbl_1_bss_A88[2].unk_0;
    previous[3] = fzgx_obj_lbl_1_bss_A88[3].unk_0;
    fn_1_21E4(axes);
    /* the replay hook records the records or, during playback, overwrites them */
    if (fn_1_3FC28()) {
        fn_1_F2820(fzgx_obj_lbl_1_bss_A88, lbl_1_bss_CC0, &lbl_1_bss_7EFD8.unk_20);
    }

    raw = lbl_1_bss_9C8;
    input_update_floats(axes, raw);

    /* request bits 0x04/0x08: accelerator/brake past 0.97; .bss 0xCC0[port]: bits newly set */
    {
        u32 port;
        u8 *newly;
        InputControl *control;
        InputControlFloats *value;

        control = fzgx_obj_lbl_1_bss_A88;
        newly = lbl_1_bss_CC0;
        value = fzgx_obj_lbl_1_bss_C70;
        for (port = 0; port < 4; port++, control++) {
            if (value->unk_C > 0.97) {
                control->unk_0 |= 0x04;
            } else {
                control->unk_0 &= ~0x04;
            }
            if (value->unk_10 > 0.97) {
                control->unk_0 |= 0x08;
            } else {
                control->unk_0 &= ~0x08;
            }
            *newly = control->unk_0 & ~*prev;
            value++;
            prev++;
            newly++;
        }
    }

    fn_1_2F04();

    /* .bss 0xD58: every connected port's button words ORed */
    fn_80008BEC(&lbl_1_bss_D58__fzgx_offset_0, 0, sizeof(InputPortButtons));
    {
        InputPortButtons *buttons;
        u32 port;
        u32 k;

        buttons = fzgx_obj_lbl_1_bss_9F8;
        for (port = 0; port < 4; port++) {
            if (raw->err != -1) {
                /* held, previous, pressed, released, unk_10 */
                for (k = 0; k < 5; k++) {
                    (&lbl_1_bss_D58__fzgx_offset_0.unk_0)[k].button |= (&buttons->unk_0)[k].button;
                    (&lbl_1_bss_D58__fzgx_offset_0.unk_0)[k].unk_2 |= (&buttons->unk_0)[k].unk_2;
                }
            }
            raw++;
            buttons++;
        }
    }
}
/* fzgx:end fn_1_3308 */

/* fzgx:begin fn_1_3920 noprologue */
#include "types.h"

struct fn_1_3920_lbl_1_bss_978 {
    u8 pad_0[8];
    u32 probe[4];
    u16 merged[4];
    u8 pad_20[0x3F4 - 0x20];
    u8 unk_3F4;
};

struct fn_1_3920_In {
    u16 val;
    u8 pad[7];
    u8 flag;
};

struct fn_1_3920_Out {
    u16 val;
    u8 pad[8];
    u8 flag;
};

extern u32 lbl_1_data_2B68[4];
extern u8 lbl_1_data_2B64;
extern int fn_1_D357C(void);
extern void PADRead(void *);
extern u32 SIProbe(u32);
extern void fn_8006B470(void *);
extern void fn_1_D332C(u16 *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_978[2];
u32 lbl_1_bss_980[4];
u16 lbl_1_bss_990[4];
u32 lbl_1_bss_990__fzgx_offset_8[12];
u32 lbl_1_bss_9C8[12];
u32 fzgx_obj_lbl_1_bss_9F8[20];
u32 fzgx_obj_lbl_1_bss_A48[16];
u32 fzgx_obj_lbl_1_bss_A88[6];
u32 fzgx_obj_lbl_1_bss_AA0[84];
u32 lbl_1_bss_BF0[32];
u32 fzgx_obj_lbl_1_bss_C70[20];
u32 lbl_1_bss_CC0[38];
u32 lbl_1_bss_D58__fzgx_offset_0[5];
u8 lbl_1_bss_D58__fzgx_offset_14;
u8 lbl_1_bss_D58__fzgx_offset_15;
u16 lbl_1_bss_D58__fzgx_offset_16;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_978;
    s = *(u8 *)&lbl_1_bss_980;
    s = *(u8 *)&lbl_1_bss_990;
    s = *(u8 *)&lbl_1_bss_990__fzgx_offset_8;
    s = *(u8 *)&lbl_1_bss_9C8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_9F8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_A48;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_A88;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_AA0;
    s = *(u8 *)&lbl_1_bss_BF0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_C70;
    s = *(u8 *)&lbl_1_bss_CC0;
    s = *(u8 *)&lbl_1_bss_D58__fzgx_offset_0;
    s = lbl_1_bss_D58__fzgx_offset_14;
    s = lbl_1_bss_D58__fzgx_offset_15;
    s = *(u8 *)&lbl_1_bss_D58__fzgx_offset_16;
}
#pragma section code_type ".text"

void fn_1_3920(void) {
    u8 flag;
    u32 *q;
    u32 i;
    struct fn_1_3920_Out out[4];
    struct fn_1_3920_In in[4];

    
    flag = lbl_1_data_2B64;
    if (fn_1_D357C() == 0) {
        lbl_1_data_2B64 = 0;
        if (flag != 0) {
            lbl_1_bss_D58__fzgx_offset_14 = 0;
        } else if (lbl_1_bss_D58__fzgx_offset_14 < 4) {
            lbl_1_bss_D58__fzgx_offset_14 = lbl_1_bss_D58__fzgx_offset_14 + 1;
        } else {
            PADRead(out);
            i = 0;
            q = lbl_1_bss_980;
            do {
                *q = SIProbe(i);
                i++;
                q++;
            } while (i < 4);
            if (lbl_1_data_2B68[0] + 0x10000 != 0xffff
                    || lbl_1_data_2B68[1] + 0x10000 != 0xffff
                    || lbl_1_data_2B68[2] + 0x10000 != 0xffff
                    || lbl_1_data_2B68[3] + 0x10000 != 0xffff) {
                fn_8006B470(in);
                for (i = 0; i < 4; i++) {
                    if ((s8)in[i].flag != -1) {
                        out[i].val = in[i].val;
                        out[i].flag = 0;
                    }
                }
            }
            for (i = 0; i < 4; i++) {
                if ((s8)out[i].flag == -3) {
                    out[i].val = 0;
                }
            }
            {
                u16 *m = lbl_1_bss_990;
                m[0] |= out[0].val;
                m[1] |= out[1].val;
                m[2] |= out[2].val;
                m[3] |= out[3].val;
            }
            fn_1_D332C((u16 *)out);
        }
    }
}
/* fzgx:end fn_1_3920 */

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

/* fzgx:begin fn_1_4310 */
// Store the value in the shared state object's field.
void fn_1_4310(u32 arg0) {
    *(u32 *)((u8 *)lbl_1_bss_DAC + 16) = arg0;
}
/* fzgx:end fn_1_4310 */

/* fzgx:begin fn_1_4324 */
// Store the current value in the shared state block.
void fn_1_4324(u32 arg0) {
    *(u32 *)((u8 *)lbl_1_bss_DAC + 20) = arg0;
}
/* fzgx:end fn_1_4324 */

/* fzgx:begin fn_1_4338 */
struct fn_1_4338_target {
    u8 unk_0[20];
    u32 unk_14;
};

struct fn_1_4338_root {
    struct fn_1_4338_target *unk_0;
};



// Return the value stored in the pointed-to object's field at offset 0x14.
u32 fn_1_4338(void) {
    return ((struct fn_1_4338_root *)&lbl_1_bss_DAC)->unk_0->unk_14;
}
/* fzgx:end fn_1_4338 */

/* fzgx:begin fn_1_434C */

// fn_1_434C returns the current main-rel state value.
u32 fn_1_434C(void) {
    return lbl_1_bss_DAC;
}
/* fzgx:end fn_1_434C */

/* fzgx:begin fn_1_435C */
u32 fn_1_435C(u32 value) {
    u32 old;

    old = lbl_1_bss_DAC;
    lbl_1_bss_DAC = value;
    return old;
}
/* fzgx:end fn_1_435C */

/* fzgx:begin fn_1_4370 */
// fn_1_4370: empty in retail (single blr).
void fn_1_4370(void) {
}
/* fzgx:end fn_1_4370 */

/* fzgx:begin fn_1_4374 */
void fn_1_4374(fn_1_4374_Node **list, fn_1_4374_Node *node) {
    fn_1_4374_Node *prev;
    fn_1_4374_Node *next;

    next = node->next;
    prev = node->prev;
    prev->next = next;
    if (next != 0) {
        next->prev = prev;
    }
    node->next = *list;
    node->field_0 = 0;
    *list = node;
}
/* fzgx:end fn_1_4374 */

/* fzgx:begin fn_1_43A4 */
typedef struct ListNode ListNode;

struct ListNode {
    u32 reserved;
    u32 reserved2;
    ListNode *next;
    ListNode *prev;
};

typedef struct ListManager {
    ListNode *head;
    u32 reserved;
    ListNode *current;
} ListManager;



void fn_1_43A4(void) {
    ListNode *next;
    ListNode *prev;
    ListManager *manager = (*(ListManager * *)&lbl_1_bss_DA8);
    ListNode *node = manager->current;
    ListNode *head;

    if (node == 0) {
        return;
    }

    next = node->next;
    prev = node->prev;
    prev->next = next;
    if (next != 0) {
        next->prev = prev;
    }

    head = manager->head;
    node->next = head;
    node->reserved = 0;
    manager->head = node;
}
/* fzgx:end fn_1_43A4 */

/* fzgx:begin fn_1_43E8 */

// Store the incoming value in the shared startup state.
void fn_1_43E8(u32 arg0) {
    lbl_1_bss_DB0[0] = arg0;
}
/* fzgx:end fn_1_43E8 */

/* fzgx:begin fn_1_43F4 */

// Clear the first startup word used by the main REL state.
void fn_1_43F4(void) {
    lbl_1_bss_DB0[0] = 0;
}
/* fzgx:end fn_1_43F4 */

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

/* fzgx:begin fn_1_451C noprologue */
#include "types.h"

struct fn_1_451C_lbl_1_bss_DB8 {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
};

extern struct fn_1_451C_lbl_1_bss_DB8 lbl_1_bss_DB8;
extern u32 OSGetArenaHi(void);
extern u32 OSGetArenaLo(void);
extern u32 fn_1_481E8(u32);
extern u32 fn_1_566DC(void);
extern u32 fn_80008E84(void);
extern u32 fn_80008F60(u32, u32);
extern u32 fn_80009064(u32);
extern u32 fn_80009FA4(u32);
extern u32 fn_80077848(void);
extern u32 fn_8007785C(u32, u32);

u32 fn_1_451C(void) {
    u32 t9;
    u32 t8;
    u32 t7;
    u32 t6;
    u32 t5;
    u32 t4;
    u32 t3;
    u32 t0;
    u32 v2;
    u32 v1;
    u32 v0;
    struct fn_1_451C_lbl_1_bss_DB8 *p_lbl_1_bss_DB8;
    p_lbl_1_bss_DB8 = (struct fn_1_451C_lbl_1_bss_DB8 *)&lbl_1_bss_DB8;
    t0 = OSGetArenaHi();
    OSGetArenaLo();
    fn_1_481E8(188);
    v0 = (p_lbl_1_bss_DB8->unk_C + 1);
    v1 = v0;
    while ((s32)v1 < 8) {
    t3 = fn_80009FA4(v1);
    v2 = t3;
    if ((t3 + 0x10000) != 65535) {
    v2 = v1;
    t4 = fn_80009064(v2);
    v2 = t4;
    }
    v1++;
    }
    v2 = p_lbl_1_bss_DB8->unk_10;
    v2 = (v2 + 0xE0000);
    v2 -= 2848;
    t5 = fn_80008F60(v2, t0);
    v2 = t5;
    p_lbl_1_bss_DB8->unk_8 = v2;
    t6 = fn_80008E84();
    v2 = t6;
    t7 = fn_80077848();
    v2 = t7;
    t8 = fn_1_566DC();
    v2 = t8;
    t9 = fn_8007785C(v2, 0);
    v2 = t9;
    v2 = p_lbl_1_bss_DB8->unk_8;
    return v2;
}
/* fzgx:end fn_1_451C */

/* fzgx:begin fn_1_45D0 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

extern struct ArenaData lbl_1_data_8;
extern u32 OSGetArenaLo(void);
extern u32 OSGetArenaHi(void);
extern void OSSetArenaLo(u32 arena_lo);
extern u16 lbl_1_bss_990[28];
extern u8 lbl_1_bss_D78;
extern u8 lbl_1_bss_DA6;
extern u32 lbl_1_bss_DB0[2];
extern u32 lbl_1_bss_DA8;
extern void fn_1_43A4(void);
extern u32 lbl_1_data_2C70;
extern void fn_80008E84(u32 value);
extern u32 lbl_1_bss_DAC;
extern struct fn_1_634_lbl_1_bss_54 lbl_1_bss_54;
extern u32 fn_8006FFC4(u32);
extern u32 fn_1_48780(void);
extern u32 lbl_801A66B4;
extern u32 lbl_801A66BC;
extern struct fn_1_904_lbl_1_bss_4 lbl_1_bss_4;
extern struct fn_1_914_lbl_1_bss_0 lbl_1_bss_0;
extern u16 lbl_1_bss_96A;
extern u32 fn_1_37E98(void);
extern u32 lbl_1_bss_96C;
extern u32 camera_set_state_flag(u32);
extern u32 fn_1_D31E0(u32);
extern struct fn_1_12B4_lbl_1_bss_962 lbl_1_bss_962;
extern u32 lbl_1_data_2A20;
extern u32 lbl_1_data_7C0;
extern u32 fn_1_15659C(u32);
extern u32 fn_80008BEC(void *, u32, u32);
extern u8 lbl_1_bss_978[];
extern u32 lbl_1_data_2B78;
extern u32 OSGetTick(u32);
extern u32 lbl_1_bss_D7C;
extern u8 lbl_1_bss_DA4;
extern char lbl_1_data_2C9C[20];
extern char lbl_1_data_2CB0[31];
extern void OSPanic(const char *message, int line, const char *file, ...);
extern void fn_80009AA8(u32 value, u32 count, const char *file, int line);
extern u32 fn_1_156754(u32);
extern u32 fn_1_A5864(void);
extern u32 fn_1_F7578(void);
extern struct fn_1_3C98_lbl_1_bss_DA5 lbl_1_bss_DA5;
extern u32 fn_80008EC8(u32, u32, u32);
extern u32 fn_800793D4(u32, u32, u32);
extern struct fn_1_48B0_lbl_801A6CF8 lbl_801A6CF8;
extern u32 lbl_801A6CFC;
extern struct fn_1_44B4_lbl_1_bss_DB8 lbl_1_bss_DB8;
extern struct fn_1_4438_lbl_1_bss_DC4 lbl_1_bss_DC4;
extern u8 lbl_1_bss_8E6B0[308];
extern void fn_1_14FCE4(void *data, s32 value);
extern struct fn_1_798_slot lbl_1_bss_8E7E4[];
extern u8 lbl_1_bss_AA0[336];
extern u8 lbl_1_rodata_108[88];
extern u32 fn_80008BA8(void *, void *, u32);
extern void fn_1_3BDC(u32 arg0);
extern u32 fn_1_3C18(s32);

extern u32 OSReport(u32, ...);
extern u32 fn_800090A4(u32);
extern u32 fn_80009830(u32);
extern u32 lbl_1_data_2C74;

s32 fn_1_45D0(u32 arg0, u32 arg1) {
    u32 v0;
    u32 t0, t1, t2;
    v0 = arg0;
    if ((s32)arg1 == 0) {
    v0 = (u32)&lbl_1_data_2C74;
    t0 = OSReport(v0, arg1);
    v0 = t0;
    v0 = 0;
    } else {
    t1 = fn_80009830(v0);
    v0 = t1;
    if (v0 == 0) {
    v0 = arg0;
    t2 = fn_800090A4(v0);
    v0 = t2;
    v0 = 0;
    }
    }
    return v0;
}
/* fzgx:end fn_1_45D0 */

/* fzgx:begin fn_1_4630 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

extern struct ArenaData lbl_1_data_8;
extern u32 OSGetArenaLo(void);
extern u32 OSGetArenaHi(void);
extern void OSSetArenaLo(u32 arena_lo);
extern u16 lbl_1_bss_990[28];
extern u8 lbl_1_bss_D78;
extern u8 lbl_1_bss_DA6;
extern u32 lbl_1_bss_DB0[2];
extern u32 lbl_1_bss_DA8;
extern void fn_1_43A4(void);
extern u32 lbl_1_data_2C70;
extern void fn_80008E84(u32 value);
extern u32 lbl_1_bss_DAC;
extern struct fn_1_634_lbl_1_bss_54 lbl_1_bss_54;
extern u32 fn_8006FFC4(u32);
extern u32 fn_1_48780(void);
extern u32 lbl_801A66B4;
extern u32 lbl_801A66BC;
extern struct fn_1_904_lbl_1_bss_4 lbl_1_bss_4;
extern struct fn_1_914_lbl_1_bss_0 lbl_1_bss_0;
extern u16 lbl_1_bss_96A;
extern u32 fn_1_37E98(void);
extern u32 lbl_1_bss_96C;
extern u32 camera_set_state_flag(u32);
extern u32 fn_1_D31E0(u32);
extern struct fn_1_12B4_lbl_1_bss_962 lbl_1_bss_962;
extern u32 lbl_1_data_2A20;
extern u32 lbl_1_data_7C0;
extern u32 fn_1_15659C(u32);
extern u32 fn_80008BEC(void *, u32, u32);
extern u8 lbl_1_bss_978[];
extern u32 lbl_1_data_2B78;
extern u32 OSGetTick(u32);
extern u32 lbl_1_bss_D7C;
extern u8 lbl_1_bss_DA4;
extern char lbl_1_data_2C9C[20];
extern char lbl_1_data_2CB0[31];
extern void OSPanic(const char *message, int line, const char *file, ...);
extern void fn_80009AA8(u32 value, u32 count, const char *file, int line);
extern u32 fn_1_156754(u32);
extern u32 fn_1_A5864(void);
extern u32 fn_1_F7578(void);
extern struct fn_1_3C98_lbl_1_bss_DA5 lbl_1_bss_DA5;
extern u32 fn_80008EC8(u32, u32, u32);
extern u32 fn_800793D4(u32, u32, u32);
extern struct fn_1_48B0_lbl_801A6CF8 lbl_801A6CF8;
extern u32 lbl_801A6CFC;
extern struct fn_1_44B4_lbl_1_bss_DB8 lbl_1_bss_DB8;
extern struct fn_1_4438_lbl_1_bss_DC4 lbl_1_bss_DC4;
extern u8 lbl_1_bss_8E6B0[308];
extern void fn_1_14FCE4(void *data, s32 value);
extern struct fn_1_798_slot lbl_1_bss_8E7E4[];
extern u8 lbl_1_bss_AA0[336];
extern u8 lbl_1_rodata_108[88];
extern u32 fn_80008BA8(void *, void *, u32);
extern void fn_1_3BDC(u32 arg0);
extern u32 fn_1_3C18(s32);

extern u32 OSReport(u32, ...);
extern u32 fn_800090A4(u32);
extern u32 fn_80009830(void);
extern u32 lbl_1_data_2C74;

u32 fn_1_4630(u32 arg0, u32 arg1) {
    u32 v0;
    u32 v1;
    u32 t0, t1, t2, t3;
    v0 = arg0;
    v1 = arg0;
    if (arg1 == 0) {
    v0 = (u32)&lbl_1_data_2C74;
    t0 = OSReport(v0, arg1);
    v0 = t0;
    v1 = 0;
    } else {
    t1 = fn_80009830();
    v0 = t1;
    if (v0 == 0) {
    v0 = v1;
    t2 = fn_800090A4(v0);
    v0 = t2;
    v1 = 0;
    } else {
    v1 = v0;
    }
    }
    v0 = v1;
    t3 = fn_800793D4(v0, 0, arg1);
    v0 = t3;
    v0 = v1;
    return v0;
}
/* fzgx:end fn_1_4630 */

/* fzgx:begin fn_1_46B4 noprologue */
extern char lbl_1_data_2C9C[20];
extern void OSPanic(const char *message, int line, const char *file, ...);
extern void fn_80009AA8(u32 value, u32 count, const char *file, int line);

void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3) {
    if (arg1 == 0) {
        OSPanic(arg2, arg3, lbl_1_data_2C9C);
    }
    fn_80009AA8(arg0, arg1, arg2, arg3);
}
/* fzgx:end fn_1_46B4 */

/* fzgx:begin fn_1_4730 noprologue */
typedef struct {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Fn1_4730Entry;

extern Fn1_4730Entry lbl_1_bss_DCC[32];

void fn_1_4730(u32 value, u32 count, u32 size, const char *file, int line) {
    s32 remaining;
    Fn1_4730Entry *entry;

    if (count == 0) {
        OSPanic(file, line, lbl_1_data_2C9C);
    }
    if (size == 0) {
        if (count == 0) {
            OSPanic(file, line, lbl_1_data_2C9C);
        }
        fn_80009AA8(value, count, file, line);
    }

    entry = lbl_1_bss_DCC;
    remaining = 0x20;
    while (remaining > 0) {
        if (entry->unk_08 == 0) {
            break;
        }
        remaining--;
        entry++;
    }
    if (remaining == 0) {
        OSPanic(file, line, lbl_1_data_2CB0);
    }
    entry->unk_00 = value;
    entry->unk_04 = size;
    entry->unk_08 = count;
}
/* fzgx:end fn_1_4730 */

/* fzgx:begin fn_1_48B0 noprologue */
struct fn_1_48B0_lbl_801A6CF8 {
    u32 unk_0;
};

s32 fn_1_48B0(u32 arg0, u32 arg1) {
    s32 v0;
    v0 = (arg1 * ((lbl_801A6CF8.unk_0 - arg0) / arg1));
    if ((arg1 * ((lbl_801A6CF8.unk_0 - arg0) / arg1)) < lbl_801A6CFC) {
    v0 = 0;
    return v0;
    }
    lbl_801A6CF8.unk_0 = v0;
    return v0;
}
/* fzgx:end fn_1_48B0 */

/* fzgx:begin fn_1_48E8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

extern u32 lbl_801A6CFC;



#pragma opt_propagation off
s32 fn_1_48E8(u32 arg0, u32 arg1) {
    u32 step;
    u32 *counter;
    u32 value;
    s32 result;
    u32 total;

    counter = &lbl_801A6CFC;
    value = *counter;
    step = ((value - 1) / arg1) + 1;
    result = arg1 * step;
    total = result + arg0;
    if (total > (*(u32 *)&lbl_801A6CF8)) {
        return 0;
    }
    *counter = total;
    return result;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_48E8 */
