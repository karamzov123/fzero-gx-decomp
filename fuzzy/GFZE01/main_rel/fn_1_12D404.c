/* Non-matching: best partial attempt (34.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/archive.h"
typedef struct { u8 pad_0[4]; s32 field_4, field_8, field_c, field_10, field_14; } Sig_fn_1_8F45C_Fn1_8F45C_Object;

extern u8 lbl_1_rodata_8180[164];
extern void *fn_1_12F118(void);
extern u8 *fn_1_36AD0(void);
extern u32 fn_1_8F198(u32, u32, void *, u32);
extern void fn_1_8F45C(Sig_fn_1_8F45C_Fn1_8F45C_Object *, u32, void *, u32);
extern void *fn_1_435C(void *);
extern void fn_1_8F62C(void *);
extern s32 fn_1_3F8C(u32, u32, u8 *, void *);
extern void fn_1_12CEA8(u32, u32, void *, u32, s32);
extern u32 fn_1_12E0B8(u32, u32, u32, u32, u32, void *, u32);
extern void OSPanic(const char *, int, const char *, ...);

struct Copy160 { u32 a[40]; };

static s32 mapid(s16 id, void *tbl) {
    void *p;
    s32 i;
    u32 off;
    if (id < 0) return 1;
    if (id < 0x29) return id;
    p = fn_1_12F118();
    if (p == 0) return 6;
    if (p != fn_1_36AD0()) {
        for (i = 0; i < 9; i++) {
            if (((u8 *)p)[i * 0xC0 + 5] == (u8)id) {
                off = 0x81A0 + i * 0x81C0;
                return (s16)((u8 *)p)[off];
            }
        }
        return 6;
    }
    if (id >= 0x32 && id <= 0x35) {
        off = 0x81A0 + (id - 0x32) * 0x81C0;
        return (s16)((u8 *)p)[off];
    }
    if (id >= 0x36 && id <= 0x39) {
        off = 0x81A0 + (id - 0x36) * 0x81C0;
        return (s16)((u8 *)p)[off];
    }
    for (i = 0; i < 4; i++) {
        if (((u8 *)p)[i * 0xC0 + 5] == (u8)id) {
            off = 0x81A0 + i * 0x81C0;
            return (s16)((u8 *)p)[off];
        }
    }
    return 6;
}

void fn_1_12D404(u32 arg0, u32 arg1, u32 arg2, void *arg3, s32 *arg4,
                 void *arg5, void *arg6, u32 arg7, s32 arg8, void *arg9) {
    u8 *state = (u8 *)&lbl_1_bss_8B3A0;
    u8 *data = (u8 *)&lbl_1_data_40798;
    s32 n;
    struct Copy160 copy;
    s32 i, id, mapped, count, out;
    u32 value;
    void *p;
    s32 *output;
    u8 *cursor;
    u32 *dst;
    u8 *src;
    s32 j;
    (void)fn_1_8F198;
    for (n = 0; n < 4; n++, state += 0x20, arg0 += 0x4E0, arg4++, arg1 += 0x9C0, arg5 = (u8 *)arg5 + 8) {
        id = *(s16 *)(state + 0xE);
        if (id == -1) continue;
        value = arg2;
        if (id == 0x21 && arg2 > 0x10000000 && (lbl_1_bss_960 == 2 || arg2 + 0x80000000 == 0)) value >>= 1;
        if (id == 0x15 && value > 0x10000000 && (lbl_1_bss_960 == 2 || value + 0x80000000 == 0)) value >>= 1;
        copy = *(struct Copy160 *)lbl_1_rodata_8180;
        mapped = (s16)copy.a[mapid((s16)id, p)];
        if (arg8) {
            if (arg0 == 0) OSPanic((const char *)(data + 0x358), 0x388, (const char *)(data + 0x368));
            for (j = 0; j < 12; j++) {
                if (((Obj_1_bss_8B56C *)&lbl_1_bss_8B56C)[j].unk_0 == 0) {
                    ((Obj_1_bss_8B56C *)&lbl_1_bss_8B56C)[j].unk_0 = arg0;
                    ((Obj_1_bss_8B56C *)&lbl_1_bss_8B56C)[j].unk_4 = 0;
                    break;
                }
            }
            if (j == 12) OSPanic((const char *)(data + 0x358), 0x394, (const char *)(data + 0x390));
            fn_1_8F198(arg0, mapped, (void *)value, arg7);
        } else {
            fn_1_8F45C((Sig_fn_1_8F45C_Fn1_8F45C_Object *)arg0, mapped, (void *)value, arg7);
        }
        fn_1_435C(arg3);
        *arg4 = fn_1_3F8C((u32)(data + 0x31c), (u32)fn_1_8F62C, (u8 *)arg0, arg6);
        fn_1_12CEA8(id, arg1, (void *)value, arg7, arg8);
        for (i = 0; i < (id == 0x15 ? 1 : (id == 0x21 ? 2 : 0)); i++) {
            mapped = mapid((s16)id, p);
            out = -1;
            if (mapped == 0x15) out = i == 0 ? 0x29 : -1;
            else if (mapped == 0x21) out = i == 0 ? 0x2a : (i == 1 ? 0x2b : -1);
            if (out != -1) {
                fn_1_435C(arg3);
                *(((s32 *)arg5) + i) = fn_1_3F8C((u32)(data + 0x31c), (u32)fn_1_8F62C, (u8 *)arg0 + i * 0x4E0, arg6);
            }
        }
        fn_1_12E0B8(n, id, arg0, arg1, 0, arg9, 1);
    }
}
