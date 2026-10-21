#include "types.h"
struct Sig_fn_12_252A0_Movie {
    u8 pad0[0x48];
    int state;
    u8 pad4C[0x1AF4-0x4C];
    int stream;
    int field1AF8;
    int field1AFC;
    int field1B00;
};
typedef struct Sig_fn_12_696C_MovieValues {
    u32 value_00, value_04, value_08, value_0c;
    u32 value_10, value_14, value_18, value_1c;
} Sig_fn_12_696C_MovieValues;
typedef struct Sig_fn_12_696C_MovieModule {
    u8 _pad00[0x40];
    Sig_fn_12_696C_MovieValues values[1];
} Sig_fn_12_696C_MovieModule;
typedef struct Sig_fn_12_6A18_MovieValues {
    u32 value_14, value_18, value_1c;
} Sig_fn_12_6A18_MovieValues;
struct fn_12_252A0_arg0_1138_E116 {
    u8 pad_0[0x24];
    u32 unk_24;
    u8 pad_28[0x4C];
};
struct fn_12_252A0_Arg0 {
    u8 pad_0[0x1138];
    struct fn_12_252A0_arg0_1138_E116 unk_1138[1];
};
extern int fn_12_21D50(void *, int);
extern int fn_12_21E94(void *, int);
extern int fn_12_696C(Sig_fn_12_696C_MovieModule *, Sig_fn_12_696C_MovieValues *, int);
extern int fn_12_6A18(void *, Sig_fn_12_6A18_MovieValues *);
extern s32 fn_12_2D73C(void *, int);
extern s32 fn_12_2F1F0(void *, u32);
extern void fn_12_21D60(void *, int, int);
extern void fn_12_2D7DC(void *, int, int);
#define FIELD(p,n) (*(s32 *)((u8 *)(p)+(n)))
#define WORK(p) (*(s32 **)((u8 *)(p)+0x1aec))
#pragma inline_max_size(10000)
#pragma inline_max_total_size(10000)
static inline void update(struct fn_12_252A0_Arg0 *arg0, s32 zero) {
    s32 v5;
    s32 *v9;
    void *v10;
    s32 *v11;
    s32 *v0;
    void *decoder;
    u32 v1;
    s32 v3;
    s32 v2;
    s32 v4;
    s32 v6;
    s32 *v13;
    s32 *v14;
    s32 *v17;
    int a,b,c;
    Sig_fn_12_696C_MovieValues loc_14;
    Sig_fn_12_696C_MovieValues loc_34;
    Sig_fn_12_6A18_MovieValues loc_8;
    v0 = WORK(arg0);
    v1 = zero;
    v3 = zero;
    v2 = zero;
    decoder = (void *)v0[0];
    do {
        fn_12_696C(decoder, &loc_34, v2);
        { s32 t = loc_34.value_08;
          if ((s32)v1 > t) t = v1;
          v1 = t;
        }
        v4 = loc_34.value_0c;
        if (v3 > v4) v4 = v3;
        v2++;
        v3 = v4;
    } while (v2 < 3);
    v0[2] = v1;
    v0[1] = v4;
    a = fn_12_21D50(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1AFC);
    b = fn_12_21D50(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1AF8);
    c = fn_12_21D50(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1B00);
    if ((c | (a | b)) != 1 && fn_12_21D50(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->stream) == 1) {
        struct fn_12_252A0_Arg0 *entry = (struct fn_12_252A0_Arg0 *)((u8 *)arg0 + ((struct Sig_fn_12_252A0_Movie *)arg0)->stream * 0x74);
        v5 = FIELD(arg0,0x9f8);
        v6 = FIELD(arg0,8);
        if (v6 <= 0) v6 = entry->unk_1138[0].unk_24;
        if (v6 <= 0) v6 = v5;
        if (v6 < v5) v5 = v6;
        if (fn_12_21E94(arg0,0) >= v5) {
            fn_12_21D60(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1AFC,1);
            fn_12_21D60(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1AF8,1);
            fn_12_21D60(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1B00,1);
        }
    }
    v9 = WORK(arg0);
    v10 = (void *)v9[0];
    fn_12_6A18(v10,&loc_8);
    if ((s32)loc_8.value_1c != -1 && (s32)loc_8.value_1c > 0) FIELD(arg0,0x924) = loc_8.value_1c;
    fn_12_696C(v10,&loc_14,1);
    if ((s32)loc_14.value_10 != -1) FIELD(arg0,0x928) = loc_14.value_10;
    if (FIELD(arg0,0x930) == -1) FIELD(arg0,0x930) = v9[2];
    if (FIELD(arg0,0x934) == -1) FIELD(arg0,0x934) = v9[1];
    v11 = WORK(arg0);
    if (fn_12_2D73C(arg0,6) == 1 && v11[2] == 0 && fn_12_2F1F0(arg0,6) != 0) fn_12_2D7DC(arg0,6,0);
    if (fn_12_2D73C(arg0,5) == 1 && v11[1] == 0 && fn_12_2F1F0(arg0,7) != 0) fn_12_2D7DC(arg0,5,0);
    v13 = *(s32 **)((u8 *)arg0+0x2908);
    if (v13 == 0) v14 = 0;
    else {
        if ((s32)WORK(arg0)[5] > 0) v14 = 0;
        else v14 = (s32 *)((u8 *)v13+0x8a0);
    }
    if (v14 != 0) {
        v17 = WORK(arg0);
        if (v17[4] != 0x7fffffff) {
            FIELD(arg0,0xdd8) = v17[4] - v14[6];
            if (v14[0] == 0) {
                v14[1] = FIELD(arg0,0x924)*50;
                v14[2] = FIELD(arg0,0x928);
                v14[3] = v17[1];
                v14[4] = v17[2];
                v14[5] = FIELD(arg0,0xdd4);
                v14[6] = v17[3];
                v14[7] = v17[8];
                v14[8] = v17[9];
            }
        }
    }
}
void fn_12_252A0(struct fn_12_252A0_Arg0 *arg0) {
    update(arg0, 0);
}
