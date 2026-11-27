#include "types.h"


/* --- rel/movie_module/fn_12_35D74.c --- */
/* --- rel/movie_module/fn_12_35D74.c --- */
extern void fn_12_30E8(void);

void fn_12_35D74(void);

/* --- rel/movie_module/fn_12_35D94.c --- */
extern void fn_12_3148(void);

void fn_12_35D94(void);

/* --- rel/movie_module/fn_12_35DB4.c --- */
// fn_12_35DB4: returns a constant.
int fn_12_35DB4(void);

/* --- rel/movie_module/fn_12_35DBC.c --- */
extern void fn_12_33D0(void);

void fn_12_35DBC(void);

/* --- rel/movie_module/fn_12_35DDC.c --- */
extern void MWSFSVM_Error(void*, ...);

void fn_12_35DDC(void* arg0, void* arg1);

/* --- rel/movie_module/fn_12_35E04.c --- */
/* --- rel/movie_module/fn_12_35E04.c --- */
extern u32 fn_12_33BC(u32, u32);
extern u32 fn_12_341C(void);

u32 fn_12_35E04(void);

/* --- rel/movie_module/fn_12_35E34.c --- */
extern void* fn_12_38DBC(void*);

void* fn_12_35E34(void* arg0, void* arg1, void* arg2) {
    void* result;

    result = fn_12_38DBC(arg0);
    *(void**)((u8*)result + 0x28) = arg0;
    *(void**)((u8*)result + 0x2C) = arg1;
    *(void**)((u8*)result + 0x30) = arg2;
    return result;
}

/* --- rel/movie_module/fn_12_35E84.c --- */
typedef struct Sig_fn_12_23E0C_MovieState {
    u8 unk_00;
    u8 unk_01;
    u8 pad_02[0x06];
    void *unk_08;
    void *unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} Sig_fn_12_23E0C_MovieState;

typedef struct OutBlock {
    s32 f0;
    s32 f1;
    s32 f2;
    s32 f3;
    s32 f4;
    s32 f5;
    s32 f6;
    s32 f7;
} OutBlock;

extern char lbl_12_rodata_1E18[40];
extern char lbl_12_rodata_1E40[41];
extern void * memset(void *, int, u32);
extern void fn_12_23E0C(void *, void *, Sig_fn_12_23E0C_MovieState *);
extern void fn_12_336CC(const void *, u32, void *);

void fn_12_35E84(u32 arg0, s32 arg1, void *arg2) {
    u32 x;
    OutBlock loc_8;
    u8 loc_28[0x48];
    s32 flag;
    s32 valid;

    x = arg0;
    if (x == 0 || arg2 == 0) {
        MWSFSVM_Error(lbl_12_rodata_1E18);
    } else if (arg1 <= 0) {
        MWSFSVM_Error(lbl_12_rodata_1E40);
    } else {
        memset(&loc_8, 0, sizeof(loc_8));
        fn_12_23E0C((void *)arg0, (void *)arg1, (Sig_fn_12_23E0C_MovieState *)loc_28);
        if ((s8)loc_28[0x00] == 0 || (s8)loc_28[0x01] == 0) {
            *(OutBlock *)arg2 = loc_8;
            ((OutBlock *)arg2)->f0 = 0;
        } else {
            flag = 0;
            if (*(u32 *)(loc_28 + 0x04) == 0) {
                if (*(u32 *)(loc_28 + 0x08) != 0) {
                    if (*(u32 *)(loc_28 + 0x0c) == 0) {
                        flag = 2;
                    }
                }
            } else {
                if (*(u32 *)(loc_28 + 0x0c) == 0) {
                    flag = 3;
                } else {
                    flag = 1;
                }
            }
            loc_8.f1 = flag;
            loc_8.f2 = *(s32 *)(loc_28 + 0x14);
            loc_8.f3 = *(s32 *)(loc_28 + 0x18);
            loc_8.f4 = *(s32 *)(loc_28 + 0x20);
            loc_8.f5 = *(s32 *)(loc_28 + 0x2c);
            loc_8.f6 = (s8)loc_28[0x28];
            fn_12_336CC((const void *)arg0, arg1, &loc_8);
            if (loc_8.f1 == 0) {
                valid = 0;
            } else {
                if (loc_8.f2 * loc_8.f3 > 0x65400) {
                    valid = 0;
                } else {
                    valid = 1;
                }
            }
            loc_8.f0 = valid;
            *(OutBlock *)arg2 = loc_8;
        }
    }
}
