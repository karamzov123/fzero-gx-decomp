#include "types.h"

typedef struct StmSource StmSource;

typedef struct StmSourceVtbl {
    u8 reserved_00[0x24];
    s32 (*get_count)(StmSource *src, s32 flag);
} StmSourceVtbl;

struct StmSource {
    StmSourceVtbl *vtbl;
};

typedef struct AdxStm {
    s8 used;
    s8 unk_01;
    s8 unk_02;
    u8 pad_03;
    StmSource *src;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u8 pad_1C[0x0C];
    s32 unk_28;
    s32 unk_2C;
    u8 pad_30[0x0C];
    s32 unk_3C;
    s8 unk_40;
    u8 pad_41[0x13];
    s32 unk_54;
    s32 unk_58;
} AdxStm;

extern s32 lbl_8012B900[4];
extern s32 lbl_8017D6F8[];
extern AdxStm lbl_8017D708[40];
extern void fn_80046738(void);
extern void fn_80046718(void);

static inline AdxStm *adxstm_CreateIn(StmSource *src, s32 start, s32 count) {
    AdxStm *stm;
    u32 i;

    stm = 0;
    for (i = 0; (s32)i < count; i++) {
        stm = &lbl_8017D708[start + i];
        if (stm->used == 0) {
            break;
        }
    }
    if ((s32)i == count) {
        return 0;
    }
    fn_80046738();
    stm->unk_01 = 1;
    stm->unk_02 = 0;
    stm->src = src;
    stm->unk_08 = 0;
    stm->unk_0C = 0;
    stm->unk_10 = 0;
    stm->unk_28 = 0x200;
    stm->unk_54 = 0;
    stm->unk_58 = 0xFFFFF;
    stm->unk_2C = stm->unk_10 / 2048;
    if (stm->unk_10 % 2048 > 0) {
        stm->unk_2C++;
    }
    if (stm->src != 0) {
        stm->unk_3C = src->vtbl->get_count(src, 0) + src->vtbl->get_count(src, 1);
        stm->unk_18 = stm->unk_14 = stm->unk_3C;
    }
    stm->unk_40 = 0;
    stm->used = 1;
    fn_80046718();
    return stm;
}

#pragma opt_propagation off
static inline s32 fn_8004B4E0_array_read(s32 index, s32 *array) { return array[index]; }
#pragma opt_loop_invariants off
AdxStm *fn_8004B4E0(StmSource *src, s32 kind) {
    s32 *config = lbl_8012B900;
    if (kind < 0x100) {
        return adxstm_CreateIn(src, fn_8004B4E0_array_read(0, lbl_8017D6F8), config[0]);
    }
    return adxstm_CreateIn(src, config[1], config[2]);
}
#pragma opt_loop_invariants reset

#pragma opt_propagation reset

