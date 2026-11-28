/* Previously matched Japan/PAL units of background.c, retained until that TU matches those releases as one unit. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/burner.h"

extern u8 lbl_1_rodata_EB4[124];
extern void *lbl_801A6410;
extern void fn_1_46B4(void *, Obj_1_bss_6EA04_Target *, u8 *, u32);
extern f32 lbl_1_rodata_4104[59];
extern Obj_1_data_27DE0 *fn_1_986A4(Obj_1_data_27DE0 *obj);
extern void fn_800794F0(Obj_1_data_27DE0 *arg0, Obj_1_data_27DE0 *arg1, s32 arg2);
extern void fn_1_98804(Obj_1_data_27DE0 *obj);
extern void fn_1_9AF80(u32 arg0, u32 arg1, u32 arg2);
extern u32 lbl_1_rodata_4210;
extern void fn_80007AB4(u32 *arg0);
extern void fn_1_9CC6C(void *arg0, s32 arg1);
extern void lbl_8006D7B0(s32);
extern s32 lbl_8006D24C(f32, f32);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s32);
extern s32 strlen(const char *);
extern s32 fn_8006FC5C(const char *, const char *, s32);
extern s32 fn_8006FC1C(const char *, const char *);
extern u32 fn_1_9D260(void);
extern s32 fn_1_3F0C8(void);
extern u8 lbl_1_bss_8E51D;
extern u8 fn_1_7B074(void);
extern void fn_8006FDEC(void);
extern void fn_80071718(u32);
extern void fn_800711A8(u32);
extern void fn_1_55A84(void (*callback)(void), void *arg0, s32 arg1, s32 arg2);
extern void *fn_1_12F118(void);
extern void *fn_1_36AD0(void);
extern void fn_1_14F6F8(u8 arg0, u8 arg1, u8 arg2, void *arg3);
extern void fn_80008BA8(void *arg0, const void *arg1, int arg2);

extern u32 lbl_1_rodata_4210;
extern void fn_80007AB4(u32 *arg0);
extern void fn_1_9CC6C(void *arg0, s32 arg1);
extern void fn_1_9D360(void);
extern Obj_1_data_2A7E0_At3C * lbl_801A66CC;
extern u32 fn_1_4630(u32, u32, u32, u32);
extern const f32 lbl_1_rodata_4100;
extern void *memset(void *dest, int value, u32 size);
extern u32 fn_1_584AC(void);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1B0(void *, void *);
extern void fn_1_862D4(u32 arg0, void *arg1);
extern u32 fn_1_1FB80(void *arg0, s32 arg1);
extern u32 fn_1_41488(u32 arg0, void *arg1);
extern void fn_1_4270C(void *arg0, u32 arg1, u32 arg2);
extern f32 lbl_1_rodata_4260[16];
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D848(f32);
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_1_rodata_9194[10];
extern u8 lbl_1_rodata_85AC[60];
extern const f32 lbl_1_rodata_8658;
extern const f32 lbl_1_rodata_8BA8;
extern const f32 lbl_1_rodata_8A4C;
extern s8 fn_1_A5DC4(void);
extern const f32 lbl_1_rodata_91BC;
extern void fn_1_4E724(void *);

/* fzgx:begin fn_1_9A958 noprologue */
#include "types.h"

struct fn_1_9A958_data {
    u8 pad0[0x720];
    s16 current;
    u8 pad1[0x792];
    void *entries[0x58];
    u8 indices[1];
    u8 pad2[0x1A9B];
    char string_a[0xC];
    char string_b[0x4];
    char string_c[0x4];
};

extern struct fn_1_9A958_data lbl_1_data_2A0C0;
extern int sprintf(char *, const char *, ...);
extern s32 fn_1_465D0(char *, s32);

#pragma opt_propagation off
void fn_1_9A958(int index, int flag) {
    struct fn_1_9A958_data *data = &lbl_1_data_2A0C0;
    u8 *indices = data->indices;
    u8 buffer_a[0x20];
    u8 buffer_b[0x20];
    int idx = indices[index];
    void *entry;
    void ** table;

    if (data->current != idx) {
        int offset = idx * 4;
        table = data->entries;
        entry = *(void **)((u8 *)table + offset);
        if (entry != 0) {
            sprintf((char *)buffer_a, data->string_a, data->string_b, entry);
            sprintf((char *)buffer_b, data->string_c, data->string_b, entry);
            if (flag != 0) {
                fn_1_465D0((char *)buffer_a, 2);
                fn_1_465D0((char *)buffer_b, 2);
            } else {
                fn_1_465D0((char *)buffer_a, 1);
                fn_1_465D0((char *)buffer_b, 1);
            }
        }
    }
}
/* fzgx:end fn_1_9A958 */
