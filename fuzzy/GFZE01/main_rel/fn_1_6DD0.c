/* Non-matching: best partial attempt (98.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

extern void lbl_8006DD14(void *, void *);
extern CameraState *camera_get_state_object(void);
extern void OSPanic(u8 *file, int line, u8 *message, ...);

struct fn_1_6DD0_lbl_801A6D00 {
    u32 unk_0;
};
extern struct fn_1_6DD0_lbl_801A6D00 lbl_801A6D00;

struct fn_1_6DD0_lbl_801A66CC {
    u32 unk_0;
};
extern struct fn_1_6DD0_lbl_801A66CC lbl_801A66CC;

struct fn_1_6DD0_flag_holder {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[0x1FC - 5];
} fn_1_6DD0_entry;

typedef struct game_camera_entries_t {
    s8 fzgx_byte_4;
    u8 pad_1[0x3];
} game_camera_entries_t;

typedef struct live_camera_t {
    u8 fzgx_byte_8;
    u8 pad_1[0x3];
} live_camera_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_F68;
game_camera_entries_t fzgx_obj_game_camera_entries;
live_camera_t fzgx_obj_live_camera;
u8 lbl_1_bss_F74;
u8 lbl_1_bss_F75;
u8 lbl_1_bss_F76;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u32 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_F68;
    s = *(u8 *)&fzgx_obj_game_camera_entries;
    s = *(u8 *)&fzgx_obj_live_camera;
    s = *(u8 *)&lbl_1_bss_F74;
    s = *(u8 *)&lbl_1_bss_F75;
    s = *(u8 *)&lbl_1_bss_F76;
}
#pragma section code_type ".text"

void fn_1_6DD0(u32 param) {
    
    u32 idx = param;
    s8 v;

    lbl_8006DD14((void *)(lbl_801A6D00.unk_0 + 0x30), (void *)lbl_801A66CC.unk_0);

    if (fzgx_obj_lbl_1_bss_F68 == 0) {
        OSPanic(lbl_1_data_3318, 0x564, (u8 *)&lbl_1_data_35B0);
    }

    if (((Obj_1_bss_F68_Target *)fzgx_obj_lbl_1_bss_F68)->unk_0 & 0x80000000) {
        CameraState *cam = camera_get_state_object();
        cam->unk_0 |= 0x80000000;
    }

    v = (s8)((Obj_1_bss_F68_Target *)fzgx_obj_lbl_1_bss_F68)->unk_48;

    switch (v) {
case 9: case 10: {

        struct fn_1_6DD0_flag_holder *fh = *(struct fn_1_6DD0_flag_holder **)((u8 *)&fzgx_obj_live_camera.fzgx_byte_8);
        fh->unk_C |= 0x80000000;
    
} break;
default: {

        // volatile keeps retail's load/store pair in the byte update
        volatile fn_1_6DD0_entry *e = &((fn_1_6DD0_entry *)(*(u32 *)((u8 *)&fzgx_obj_game_camera_entries.fzgx_byte_4)))[(u8)idx];
        e->unk_4 = e->unk_4;
    
} break;
}
}
