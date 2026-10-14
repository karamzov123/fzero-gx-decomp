/* Non-matching: best partial attempt (93.02% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

typedef struct {
    u32 unk_0;
    char unk_4[0x100];
} Entry;
typedef struct {
    void *unk_0;
    u32 unk_4;
} ArrElem;
typedef struct {
    u32 unk_0;
    u32 unk_4;
} Item;

extern int sprintf(char *, const char *, ...);
extern u32 fn_80071484(char *);
extern Obj_1_bss_85250_At10 *fn_80070F44(char *, u32);
extern void GXInvalidateTexAll(void);
extern u32 fn_1_435C(void *);
extern u16 fn_1_3F8C(u8 *, void (*)(void), u32, u32);
extern void fn_1_10161C(void);
extern void fn_1_1018BC(void);
extern void fn_1_101BC4(void *);

#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_1_1014B4(void *arg0, void *arg1) {
    u8 * data;
    Obj_1_bss_85250 *p = &lbl_1_bss_85250;
    char buf[0x108];
    u32 count;
    void *item;
    u32 index;
    const char * lab_t1;
    char * lab_t0;
    u32 lab_t3;
    data = lbl_1_data_3EFB8;

    p->unk_4 = 0;
    p->unk_8 = 0;
    p->unk_C = 0;
    p->unk_10 = 0;

    lab_t1 = (const char *)(((0x164) + (data)));
    sprintf(buf, lab_t1, (char *)((Entry *)data)[0].unk_4, (char *)((Entry *)data)[0].unk_4);
    p->unk_C = fn_80071484(buf);
    lab_t1 = (const char *)(data + 0x17c);
    lab_t0 = buf;
    sprintf(lab_t0, lab_t1, (char *)((Entry *)data)[p->unk_8].unk_4, (char *)((Entry *)data)[p->unk_8].unk_4);
    p->unk_10 = fn_80070F44(buf, p->unk_C);

    GXInvalidateTexAll();
    fn_1_435C(arg0);
    fn_1_3F8C((u8 *)(data + 0x194), fn_1_10161C, 0, 5);
    fn_1_435C(arg1);
    lab_t3 = 5;
    fn_1_3F8C((u8 *)(data + 0x1a0), fn_1_1018BC, 0, lab_t3);

    p->unk_14 = 1;
    count = ((Entry *)data)[p->unk_8].unk_0;
    index = (p->unk_4 + count) % count;
    p->unk_4 = index;
    item = ((ArrElem *)p->unk_10->unk_8)[index].unk_0;
    if (item != 0 && (((Item *)item)->unk_4 & 0x10) != 0) {
        fn_1_101BC4(item);
    }
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset
