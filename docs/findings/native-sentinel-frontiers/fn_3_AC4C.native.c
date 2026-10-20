#include "types.h"

typedef struct {
    u8 pad[0x324];
    s32 value;
    u8 tail[0x118];
} CustomizeEntry;

extern u32 lbl_3_bss_F0[12];
extern CustomizeEntry lbl_3_bss_20860[4];
extern u8 lbl_3_bss_21960[10368];
extern u32 lbl_1_bss_6D82C[];

extern void fn_1_80F1C(s32, CustomizeEntry *);
extern void fn_1_14DBCC(void *);
extern void fn_80071718(u32);

void fn_3_AC4C(void) {
    s16 index;

    index = *(s16 *)((u8 *)lbl_3_bss_F0 + 8);
    if (lbl_3_bss_20860[index].value != -1) {
        fn_1_80F1C((s16)lbl_3_bss_20860[index].value, &lbl_3_bss_20860[index]);
        lbl_3_bss_20860[index].value = -1;
    }

    fn_1_14DBCC((u8 *)lbl_3_bss_21960 + index * 0xa20);

    if (lbl_1_bss_6D82C[0] != 0) {
        fn_80071718(lbl_1_bss_6D82C[0]);
        lbl_1_bss_6D82C[0] = 0;
    }
}
