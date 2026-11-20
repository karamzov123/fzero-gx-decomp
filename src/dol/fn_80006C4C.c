#include "types.h"


/* --- dol/fn_80006C4C.c --- */
/* --- dol/fn_80006C4C.c --- */
/* --- dol/fn_80006C4C.c --- */
extern u32 fn_80006BDC(u32, ...);
extern u32 DVDFastOpen(u32, u32);
extern u32 lbl_801220E0[];
extern u32 lbl_801220CC[];

u32 fn_80006C4C(s32 arg0, u32 arg1) {
    u32 result = 0;

    if (arg0 < 0) {
        return 0;
    }

    fn_80006BDC((u32)&lbl_801220E0, arg0);
    if ((arg0 & 0x7fff0000) == 0) {
        fn_80006BDC((u32)&lbl_801220CC);
        result = DVDFastOpen(arg0, arg1 + 4);
        if (result != 0) {
            *(u32 *)arg1 = 0;
        }
    }

    return result;
}

/* --- dol/fn_80006CE4.c --- */
extern u32 DVDClose(u32);

struct fn_80006CE4_Arg0 {
    u32 unk_0;
};

u32 fn_80006CE4(struct fn_80006CE4_Arg0 *arg0, u32 arg1) {
    u32 v0;
    u32 v1;
    u32 t0;
    v0 = (u32)arg0;
    v1 = arg1;
    if ((s32)arg0->unk_0 != 1) {
    v0 += 4;
    t0 = DVDClose(v0);
    v0 = t0;
    v1 = v0;
    }
    v0 = v1;
    return v0;
}

/* --- dol/fn_80006D1C.c --- */
/* --- dol/fn_80006D1C.c --- */
typedef u32 (*fn_80006D1C_Fn0)(u32, u32, u32, u32);
struct fn_80006D1C_Arg0 {
    u32 unk_0;
};

extern u32 lbl_801220F0[];
extern u32 lbl_80122104[];
extern u32 lbl_801A6708;

u32 fn_80006D1C(struct fn_80006D1C_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u8 loc_20;
    /* frame */
    u32 t1;
    v0 = (u32)arg0;
    v1 = arg1;
    v2 = arg2;
    v3 = arg3;
    if ((s32)arg0->unk_0 != 1) {
    v0 = (u32)&lbl_801220F0;
    fn_80006BDC(v0, v1);
    v1 = arg1;
    v2 = arg2;
    v3 = arg3;
    v0 = ((u32)arg0 + 4);
    t1 = ((fn_80006D1C_Fn0)lbl_801A6708)(v0, v1, v2, v3);
    v0 = t1;
    v4 = v0;
    }
    fn_80006BDC((u32)&lbl_80122104, v4);
    return v4;
}

/* --- dol/fn_80006DAC.c --- */
extern u32 DVDReadAsyncPrio(u32, u32, u32, u32, u32, u32);

struct fn_80006DAC_Arg0 {
    u32 unk_0;
};

u32 fn_80006DAC(struct fn_80006DAC_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5) {
    u32 v0;
    u32 v1;
    u32 t0;
    v0 = (u32)arg0;
    v1 = arg5;
    if ((s32)arg0->unk_0 != 1) {
    v0 += 4;
    v1 = 2;
    t0 = DVDReadAsyncPrio(v0, arg1, arg2, arg3, arg4, v1);
    v0 = t0;
    v1 = v0;
    }
    v0 = v1;
    return v0;
}

/* --- dol/fn_80006DE8.c --- */
/* --- dol/fn_80006DE8.c --- */
struct fn_80006DE8_Arg0 {
    u32 unk_0;
    u8 pad_4[0x34];
    u32 unk_38;
};

u32 fn_80006DE8(struct fn_80006DE8_Arg0 *arg0) {
    if ((s32)arg0->unk_0 == 1) { return (u32)arg0; }
    return arg0->unk_38;
}

/* --- dol/fn_80006DFC.c --- */
typedef struct Fn80006DFCObject {
    s32 state;
    u8 pad[0x30];
    void *value;
} Fn80006DFCObject;

void *fn_80006DFC(Fn80006DFCObject *object) {
    if (object->state != 1) {
        object = object->value;
    }
    return object;
}

/* --- dol/fn_80006E10.c --- */
extern BOOL DVDChangeDir(char *);
extern void fn_80083DB0(void *, const void *);
extern size_t strlen(const char *);
extern s32 strncmp(const char *, const char *, size_t);
extern char *strcat(char *, const char *);
extern u8 lbl_8015BD40[256];
extern char lbl_801A63F8[2];
extern char lbl_801A63FC[3];

void fn_80006E10(u32 arg0) {
    u8 *p_lbl_8015BD40;
    u8 *v0;
    s32 v2;

    v0 = (u8 *)arg0;
    DVDChangeDir((char *)arg0);
    p_lbl_8015BD40 = lbl_8015BD40;
    while (*v0 != 0) {
        if (*v0 == '/') {
            for (v2 = 1; v2 < strlen((const char *)v0) + 1; v2++) {
                if (v0[v2] != '/') {
                    fn_80083DB0(lbl_8015BD40, &v0[v2 - 1]);
                    v0 += v2;
                    break;
                }
            }
        } else if (strncmp((const char *)v0, lbl_801A63FC, 2) == 0) {
            for (v2 = strlen((const char *)lbl_8015BD40) - 1; v2 >= 0; v2--) {
                if (lbl_8015BD40[v2] == '/') {
                    lbl_8015BD40[v2] = 0;
                    v0 += 2;
                    break;
                }
            }
            if (lbl_8015BD40[0] == 0) {
                fn_80083DB0(lbl_8015BD40, lbl_801A63F8);
            }
        } else {
            if (lbl_8015BD40[0] != '/' || p_lbl_8015BD40[1] != 0) {
                strcat((char *)lbl_8015BD40, lbl_801A63F8);
            }
            strcat((char *)lbl_8015BD40, (const char *)v0);
            v0 += strlen((const char *)v0);
        }
        if (p_lbl_8015BD40[0] != '/' || p_lbl_8015BD40[1] != 0) {
            v2 = strlen((const char *)lbl_8015BD40) - 1;
            if (lbl_8015BD40[v2] == '/') {
                lbl_8015BD40[v2] = 0;
            }
        }
    }
}
