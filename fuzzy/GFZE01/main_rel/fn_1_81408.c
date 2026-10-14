/* Non-matching: best partial attempt (97.85% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"

struct Obj81408 {
    u8 pad_0[0x8];
    void *unk_8;
};

struct Car81408 {
    u8 pad_0[0x328];
    s8 unk_328;
    u8 pad_329[0x37C - 0x329];
    struct Obj81408 *unk_37C[4];
    u8 pad_38C[4];
    u32 unk_390;
    u8 pad_394[0x3A8 - 0x394];
    u32 unk_3A8;
    u8 pad_3AC[0x3B8 - 0x3AC];
    s16 unk_3B8;
};

struct Data1F1D8 {
    u8 pad_0[0x324];
    const char *unk_324[7];
};

extern char *fn_80083DB0(char *, const char *);
extern int sprintf(char *, const char *, ...);
extern struct Obj81408 *fn_1_D3884(char *);
extern u32 fn_80071470(void *, u32);
extern u32 fn_80077D40(struct Obj81408 *);
extern void fn_80006E10(const char *);
extern void fn_80008BA8(u32, u32, u32);
extern void fn_80071718(struct Obj81408 *);

static inline void fn_1_81408_name1(char *buf, struct Car81408 *car, int flag, struct Data1F1D8 *base) {
    int t = car->unk_328;
    const char **tbl = ((const char **)((char *)base + 0x324));
    fn_80083DB0(buf, tbl[t]);
    if (flag == 1) {
        switch (t) {
        case 6:
            fn_80083DB0(buf, (char *)base + 0x13E4);
            break;
        case 0:
            fn_80083DB0(buf, (char *)base + 0x13EC);
            break;
        case 1:
            fn_80083DB0(buf, (char *)base + 0x13F4);
            break;
        }
    }
}

static inline void fn_1_81408_name2(char *buf, struct Car81408 *car, int flag, struct Data1F1D8 *base) {
    int t = car->unk_328;
    const char **tbl = ((const char **)((char *)base + 0x324));
    fn_80083DB0(buf, tbl[t]);
    if (flag == 1) {
        switch (t) {
        case 6:
            fn_80083DB0(buf, (char *)base + 0x13E4);
            break;
        case 0:
            fn_80083DB0(buf, (char *)base + 0x13EC);
            break;
        case 1:
            fn_80083DB0(buf, (char *)base + 0x13F4);
            break;
        }
    }
}

void fn_1_81408(struct Car81408 *car, u8 a, u8 b) {
    struct Data1F1D8 *base = (struct Data1F1D8 *)&lbl_1_data_1F1D8;
    s16 i;
    s16 from;
    s16 to;
    s16 ti;
    s16 fi;
    int flag;
    struct Obj81408 *obj;
    char buf[32];

    for (i = 0; i < 8; i++) {
        u8 m = 1 << i;
        if (m == a) {
            from = i;
        }
        if (m == b) {
            to = i;
        }
    }
    if (car->unk_390 & 0x04000000) {
        car->unk_3B8 = to;
        return;
    }
    if (from != to) {
        fi = from % 4;
        ti = to % 4;
        if (from / 4 == to / 4 && car->unk_37C[fi] != 0 && car->unk_37C[ti] == 0) {
            flag = 0;
            fn_80006E10((char *)base + 0xE0C);
            if (car->unk_390 & 0x00100000) {
                flag = 1;
            }
            fn_1_81408_name1(buf, car, flag, base);
            fn_80006E10(buf);
            fn_1_81408_name2(buf, car, flag, base);
            if ((u8)to != 0) {
                if ((u8)to >= 4) {
                    sprintf(buf, (char *)base + 0x1358, buf, (u8)to - 4);
                } else {
                    sprintf(buf, (char *)base + 0x1364, buf);
                }
            } else {
                sprintf(buf, (char *)base + 0x1370, buf);
            }
            obj = fn_1_D3884(buf);
            fn_80006E10((char *)base + 0x147C);
            car->unk_3A8 = fn_80077D40(obj);
            fn_80008BA8(fn_80071470(car->unk_37C[fi]->unk_8, 0), (fn_80071470(obj->unk_8, 0)), car->unk_3A8);
            fn_80071718(obj);
            car->unk_37C[ti] = car->unk_37C[fi];
            car->unk_37C[fi] = 0;
            car->unk_3B8 = to;
        }
    }
}
