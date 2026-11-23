#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/relocation.h"

extern u8 *lbl_801A6CF4;
extern u32 lbl_1_bss_6F5F4;
extern u8 lbl_801A66B0[];
extern s32 OSGetResetCode(void);
extern u32 OSGetProgressiveMode(void);
extern void OSSetProgressiveMode(s32);
extern void fn_1_A6870(u32 *);
extern void fn_1_A5F44(void);
extern s32 fn_1_A6480(void);
extern u32 lbl_1_bss_6F5C0;
extern u8 lbl_1_bss_6F5C4[44];
extern u8 *lbl_801A6410;
extern void OSUnlink(void *);
extern void OSPanic(void *, ...);
extern void fn_1_46B4(void *, void *, void *, int);

/* fzgx:begin fn_1_A5C98 */
#include "types.h"

typedef struct Fn1A5C98Object {
    void *unk0;
    void *unk4;
    u8 pad8[0x30];
    void (*unk38)(void *);
} Fn1A5C98Object;

void fn_1_A5C98(Fn1A5C98Object *self) {
    u32 v1;
    if (self->unk0 != 0) {
        ((Fn1A5C98Object *)self->unk0)->unk38(self->unk0);
        OSUnlink(self->unk0);

        v1 = (u32)lbl_1_bss_6F5C4;
        v1 = (v1 + (lbl_1_bss_6F5C0 << 2));
        if (*(u32 *)(v1 - 4) != (u32)self) {
            OSPanic((*(u8 (*)[84])&lbl_1_data_34140), 0x78, (*(char (*)[31])&lbl_1_data_34194));
        }

        lbl_1_bss_6F5C0--;

        if (self->unk4 != 0) {
            fn_1_46B4(lbl_801A6410, self->unk4, (*(u8 (*)[84])&lbl_1_data_34140), 0x7b);
        }
        fn_1_46B4(lbl_801A6410, self->unk0, (*(u8 (*)[84])&lbl_1_data_34140), 0x7c);

        self->unk0 = 0;
        self->unk4 = 0;
    }
}
/* fzgx:end fn_1_A5C98 */
