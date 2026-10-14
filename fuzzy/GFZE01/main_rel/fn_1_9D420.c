/* Non-matching: best partial attempt (95.47% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/burner.h"

extern u32 lbl_801A6410;
extern u32 *lbl_1_bss_6EA78;
extern u32 *lbl_1_bss_6EA7C;

typedef struct Ent9D420 {
    char *name;
    u32 unk_4;
    u32 unk_8;
} Ent9D420;

typedef struct Sub9D420C {
    u8 pad[8];
    u8 unk_8;
} Sub9D420C;

typedef struct Mdl9D420 {
    u8 pad[0x24];
    void *unk_24;
} Mdl9D420;

typedef struct Sub9D420 {
    s32 unk_0;
    Mdl9D420 *unk_4;
    u32 unk_8;
    Sub9D420C *unk_C;
} Sub9D420;

typedef struct Inner9D420 {
    u32 unk_0;
    char *unk_4;
} Inner9D420;

typedef struct Mid9D420 {
    u32 unk_0;
    u32 unk_4;
    Inner9D420 *unk_8;
} Mid9D420;

typedef struct Obj9D420 {
    u32 flags;
    u32 unk_4;
    Mid9D420 *unk_8;
    u8 pad[0x2C];
    Sub9D420 *unk_38;
    u32 unk_3C;
} Obj9D420;

extern void fn_80006E10(void *);
extern size_t strlen(const char *);
extern s32 fn_8006FC5C(const char *, const char *, size_t);
extern int sprintf(char *, const char *, ...);
extern void *fn_1_4630(u32, u32, void *, u32);
extern s32 fn_1_45730(void *arg0, void *arg1);
extern s32 fn_1_45B2C(void *arg0);
extern void *fn_1_45D0(u32 arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_458A0(void *arg0, void *arg1, u32 arg2, u32 arg3);
extern void fn_1_45850(void *arg0);
extern void fn_1_4247C(void *, void *, void *);
extern void fn_1_426E4(void *, void *);
extern u32 fn_1_41488(void *, char *);
extern void fn_1_4270C(void *, s32, u16);

static inline void fn_1_9D420_inl(Sub9D420 *s) {
    char str[3];
    u32 idx;
    u8 c = s->unk_C->unk_8;
    Mdl9D420 *m = s->unk_4;

    str[0] = 'M';
    str[1] = c + '0';
    str[2] = 0;
    idx = fn_1_41488(m->unk_24, str);
    if (idx == 0xFFFFFFFF) {
        idx = 0;
    }
    fn_1_4270C(m, 0, (u16)idx);
}

#pragma opt_propagation off
void fn_1_9D420(Obj9D420 *obj, s32 count) {
    struct { u8 *value; } mgr;
    u32 len2;
    s32 i;
    s32 j;
    char *name;
    u32 diff;
    Ent9D420 *ent;
    u32 len1;
    char *s;
    s32 size;
    struct { u32 *value; } arr;
    u8 info[0x60];
    char buf[0x80];

    mgr.value = lbl_1_data_2A0C0;
    fn_80006E10(mgr.value + 0x2B78);
    lbl_1_bss_6EA78 = (u32 *)fn_1_4630(lbl_801A6410, 0x14, mgr.value + 0x2AA0, 0x8D3);
    lbl_1_bss_6EA7C = (u32 *)fn_1_4630(lbl_801A6410, 0x14, mgr.value + 0x2AA0, 0x8D4);
    for (i = 0; i < count; i++, obj++) {
        if ((obj->flags & 0x1000) != 0 && obj->unk_38 != NULL) {
            for (j = 0, ent = (Ent9D420 *)(mgr.value + 0x2770); j < 5; j++, ent++) {
                s = obj->unk_8->unk_8->unk_4;
                name = ent->name;
                len1 = strlen(name);
                len2 = strlen(s);
                diff = len2 - len1;
                if ((diff == 5 && fn_8006FC5C(s + len2 - 5, (char *)(mgr.value + 0x2B80), strlen((char *)(mgr.value + 0x2B80))) != 0) ||
                    (diff == 4 && fn_8006FC5C(s + len2 - 4, (char *)(mgr.value + 0x2B88), strlen((char *)(mgr.value + 0x2B88))) != 0)) {
                    if (fn_8006FC5C(name, s, len1) != 0) {
                        arr.value = lbl_1_bss_6EA7C;
                        if (arr.value[j] == 0) {
                            sprintf(buf, (char *)(mgr.value + 0x2B90), name);
                            if (fn_1_45730(buf, info) != 0) {
                                size = (u32)((fn_1_45B2C(info) + 0x1F) & ~0x1F);
                                arr.value[j] = (u32)fn_1_45D0(lbl_801A6410, size, mgr.value + 0x2AA0, 0x8F5);
                                fn_1_458A0(info, (void *)arr.value[j], size, 0);
                                fn_1_45850(info);
                            }
                        }
                        if (arr.value[j] != 0) {
                            obj->unk_38->unk_0 = j;
                            obj->unk_38->unk_4 = (Mdl9D420 *)fn_1_45D0(lbl_801A6410, *(u16 *)arr.value[j] * 0x18C + 0x70, mgr.value + 0x2AA0, 0x8FC);
                            fn_1_4247C(obj->unk_38->unk_4, (u8 *)obj->unk_38->unk_4 + 0x70, (void *)arr.value[j]);
                        }
                        arr.value = lbl_1_bss_6EA78;
                        if (arr.value[j] == 0) {
                            sprintf(buf, (char *)(mgr.value + 0x2B98), name);
                            if (fn_1_45730(buf, info) != 0) {
                                size = (u32)((fn_1_45B2C(info) + 0x1F) & ~0x1F);
                                arr.value[j] = (u32)fn_1_45D0(lbl_801A6410, size, mgr.value + 0x2AA0, 0x907);
                                fn_1_458A0(info, (void *)arr.value[j], size, 0);
                                fn_1_45850(info);
                            }
                        }
                        if (arr.value[j] != 0) {
                            fn_1_426E4(obj->unk_38->unk_4, (void *)arr.value[j]);
                            fn_1_9D420_inl(obj->unk_38);
                        }
                        break;
                    }
                }
            }
        }
    }
    fn_80006E10(mgr.value + 0x2BA4);
}
