/* Non-matching: best partial attempt (90.68% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/interview/interview.h"
#include "rel/main_rel/game.h"

extern s16 fn_1_12C710(int);
extern s16 fn_1_12C930(s16);
extern s16 sprintf(char *, const char *, ...);
extern s32 fn_1_12CB04(s16);
extern void fn_1_97204(void *, void *);
extern void fn_8004BF0C(void *);
extern char *lbl_1_data_20D1C[];


#pragma opt_propagation off
typedef struct lbl_17_bss_D8_t {
    Obj_17_bss_D8_At0 *unk_0;
    u8 pad_4[0x4];
    Obj_17_bss_D8_At8 *unk_8;
    Obj_17_bss_D8_AtC *unk_C;
    u8 pad_10[0x10];
} lbl_17_bss_D8_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_17_bss_D8_t fzgx_obj_lbl_17_bss_D8;
u16 lbl_17_bss_D8_tail_F8;
u16 lbl_17_bss_FA;
u32 lbl_17_bss_FA_fill_FC[20];
u32 lbl_17_bss_14C;
u32 lbl_17_bss_150[4];
u32 lbl_17_bss_160[4];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_17_bss_D8;
    s = *(u8 *)&lbl_17_bss_D8_tail_F8;
    s = *(u8 *)&lbl_17_bss_FA;
    s = *(u8 *)&lbl_17_bss_FA_fill_FC;
    s = *(u8 *)&lbl_17_bss_14C;
    s = *(u8 *)&lbl_17_bss_150;
    s = *(u8 *)&lbl_17_bss_160;
}
#pragma section code_type ".text"

#pragma opt_dead_assignments off
static inline Obj_17_bss_D8_At0 * fn_17_6D60_read_pointer(lbl_17_bss_D8_t * owner) { return owner->unk_0; }
void fn_17_6D60(Obj_17_bss_D8_AtC *arg0) {
    char buffer[128];
    u8 *table = (u8 *)&lbl_17_data_0 + 0x60000;
    Obj_17_bss_D8_At0 *state = fn_17_6D60_read_pointer(&fzgx_obj_lbl_17_bss_D8);
    void *object;
    s16 mode = fn_1_12C710(state->unk_88);
    s16 index = fn_1_12C930(state->unk_88);
    char * lab_t0;
    object = fzgx_obj_lbl_17_bss_D8.unk_0;
    lab_t0 = buffer;
    sprintf(lab_t0, (const char *)(table + 0x417c), (*((index) + (lbl_1_data_20D1C))), arg0->unk_C + 1);
    switch ((s16)fn_1_12CB04(mode)) {
    case 2:
        fn_1_97204(object, buffer);
        object = fzgx_obj_lbl_17_bss_D8.unk_8;
        sprintf(buffer, (const char *)(table + 0x4184), arg0->unk_C + 1);
        fn_1_97204(object, buffer);
        object = fzgx_obj_lbl_17_bss_D8.unk_C;
        sprintf(buffer, (const char *)(table + 0x418c), arg0->unk_C + 1);
        fn_1_97204(object, buffer);
        break;
    case 1:
        fn_1_97204(object, buffer);
        object = fzgx_obj_lbl_17_bss_D8.unk_8;
        sprintf(buffer, (const char *)(table + 0x4194), arg0->unk_C + 1);
        fn_1_97204(object, buffer);
        break;
    case 0:
        fn_1_97204(object, buffer);
        break;
    }
    {
        u16 *dest = &lbl_17_bss_D6;
        u32 *flags = &lbl_1_bss_6EAB4.unk_0;
        s16 *modes = (s16 *)(table + 0x2c88);
        *dest = modes[mode];
        *flags &= ~0x2c;
    }
    fn_8004BF0C((void *)lbl_1_bss_6EAD0.unk_0->unk_4);
}
#pragma opt_dead_assignments reset

#pragma opt_propagation reset
