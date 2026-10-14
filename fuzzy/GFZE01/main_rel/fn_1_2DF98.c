/* Non-matching: best partial attempt (93.01% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/stcoli.h"
extern u8 lbl_1_bss_6F316;
extern u32 fn_1_A1588(void *, u32);
extern void ADXT_Stop(void *);
extern void *fn_1_435C(void *);
extern void fn_1_40E08(u32);
extern u32 lbl_1_rodata_D18;
extern u32 lbl_1_rodata_D1C[11];
extern void fn_1_49F0(u32 *);
extern void fn_1_4A00(s32, u8, void *);
typedef struct {
    u32 f_00;
    u8 pad_04;
    u8 f_05;
    u8 pad_06[2];
    u8 f_08;
    u8 pad_09[0xC4 - 0x09];
    u32 f_C4;
} StcAdxt;
typedef struct {
    u32 f_00;
    s8 f_04;
    u8 pad_05[3];
    u8 f_08[4];
} StcSector;
typedef struct {
    u8 pad_0[0x1F84];
    s32 f_1F84;
    void *f_1F88;
    u16 *f_1F8C;
    s32 f_1F90;
    u32 f_1F94;
} StcQueue;
typedef struct {
    u8 pad_00[0x30];
    StcAdxt adxt;
    u8 pad_F8[0x1500 - 0xF8];
    StcSector sector;
} StcObject;
#pragma opt_lifetimes off
static inline u8 stc_read(StcAdxt *a, s32 offset) { u8 *p = (u8 *)a + offset; return *p; }
static inline void stc_clear(StcObject *s) {
    u8 *tail = s->sector.f_08;
    StcAdxt *a = &s->adxt;
    u8 flags = tail[3];
    a->f_C4 = 0;
    tail[3] = flags & 0xFE;
}
#pragma opt_lifetimes reset
#pragma opt_common_subs on
#pragma opt_propagation off
s32 fn_1_2DF98(void)
{
    u32 ready;
    StcObject *stc = (StcObject *)&lbl_1_bss_3C00;
    StcQueue *queue = (StcQueue *)((u8 *)stc + 0x20000);
    void *saved;
    s32 count;
    s32 ch;

    stc->sector.f_04 = -1;
    if ((stc->adxt.f_00 & 0x800800) == 0x800800) {
        StcAdxt *adxt = &stc->adxt;
        u8 *tail = stc->sector.f_08;
        u8 flags = tail[3];
        adxt->f_C4 = 0;
        tail[3] = flags & 0xFE;
    }

    if (lbl_1_bss_6F316 != 0 && queue->f_1F84 != 0) {
        if (lbl_1_data_5B7C == 5) {
            fn_1_A1588((void *)lbl_1_bss_6EAD0.unk_0->unk_0, 0x18);
        } else {
            fn_1_A1588((void *)lbl_1_bss_6EAD0.unk_0->unk_0, 0x10);
        }
        ADXT_Stop((void *)lbl_1_bss_6EAD0.unk_0->unk_4);
        lbl_1_bss_6F316 = 0;
        if (lbl_1_data_5B7C == 1) {
            saved = fn_1_435C(queue->f_1F88);
            fn_1_40E08(0x12C);
            fn_1_435C(saved);
        }
    }

    ch = stc->adxt.f_08;
    if (ch < 1) ch = 1;
    if (queue->f_1F8C == 0) return 1;
    ready = stc->adxt.f_05;
    if (ready == 0) ch -= 1;
    count = queue->f_1F90;
    if (count >= ch) {
        if (*queue->f_1F8C == 0x10) {
            if (queue->f_1F84 != 0) {
                if (lbl_1_data_5B7C == 5) {
                    u32 msg = lbl_1_rodata_D18;
                    fn_1_49F0(&msg);
                } else {
                    u32 msg2 = lbl_1_rodata_D1C[0];
                    fn_1_49F0(&msg2);
                }
            }
            fn_1_4A00(0, 0xF, (void *)stc->sector.f_00);
        } else if (*queue->f_1F8C == 0) {
            if (ready == 0) return count > ch;
            return 1;
        }
        queue->f_1F94 = *queue->f_1F8C;
    }
    return 0;
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
