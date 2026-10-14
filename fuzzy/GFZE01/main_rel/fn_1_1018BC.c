/* Non-matching: best partial attempt (95.06% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/camera.h"

struct Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

struct fn_1_1018BC_rodata_view {
    u8 pad_0[0x18];
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
};

struct fn_1_1018BC_lbl_1_bss_85250 {
    s32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x4];
    s8 unk_10;
    u32 unk_14;
    u8 pad_18[0x8];
    u32 unk_20;
    u32 unk_24;
};

typedef struct {
    u32 a;
    u32 b;
} fn_1_1018BC_Pair8;

struct fn_1_1018BC_At18 {
    u8 unk_0;
    u8 pad_1[0xF];
    fn_1_1018BC_Pair8 pair;
    u32 unk_18;
};

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u32 unk_8;
    u32 unk_C;
} Sig_fn_1_57BBC_Fn1_57BBC_ArgBlock;

extern CameraState * camera_get_state_object(void);
extern s32 fn_80077B14(struct Sig_fn_80077B14_fn_80077B14_Arg0 *);
extern struct fn_1_1018BC_lbl_1_bss_85250 lbl_1_bss_85250;
extern f32 lbl_1_rodata_77F8[3];
extern u8 lbl_1_data_3EFB8[];
extern u32 lbl_1_bss_38454;
extern u32 lbl_8006DCA4(void);
extern void fn_1_49410(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_556B8(void *);
extern void fn_1_57714(u8);
extern void fn_1_57720(u32, u32, u32, u32);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8EB0(int, int);
extern void fn_80072558(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E14C(f32);
extern void fn_1_57BBC(Sig_fn_1_57BBC_Fn1_57BBC_ArgBlock *, Sig_fn_1_57BBC_Fn1_57BBC_ArgBlock *);

static inline u32 *fn_1_1018BC_array_read(u32 *array) { return array; }
#pragma opt_dead_assignments off
void fn_1_1018BC(f32 arg0) {
    s32 t1;
    struct fn_1_1018BC_lbl_1_bss_85250 *p_lbl_1_bss_85250;
    struct fn_1_1018BC_rodata_view *p_rodata;
    CameraState *t0;
    u8 *p_data;
    u32 v1, v2, t7;
    u32 *tbl;
    Sig_fn_1_57BBC_Fn1_57BBC_ArgBlock *blkBp;
    u32 i;
    struct fn_1_1018BC_At18 *e0, *e1;
    Sig_fn_1_57BBC_Fn1_57BBC_ArgBlock blkB, blkA;

    p_rodata = (struct fn_1_1018BC_rodata_view *)&lbl_1_rodata_77F8;
    p_data = (u8 *)&lbl_1_data_3EFB8;
    p_lbl_1_bss_85250 = &lbl_1_bss_85250;
    t0 = camera_get_state_object();
    if (p_lbl_1_bss_85250->unk_10 == 0) {
        return;
    }
    v1 = *(u16 *)((u8 *)&lbl_1_bss_D58 + 8);
    if (v1 & 0x1) {
        return;
    }
    if ((v1 & 0x2) == 0) {
    v1 = *(u32 *)((u8 *)p_lbl_1_bss_85250->unk_10 + 8);
    v2 = *(u32 *)((u8 *)v1 + (p_lbl_1_bss_85250->unk_4 << 3));
    if (v2 != 0) {
        return;
    }
    t1 = fn_80077B14((struct Sig_fn_80077B14_fn_80077B14_Arg0 *)v2);
    v1 = (u32)t1;
    fn_1_49410();
    fn_1_496FC(p_rodata->unk_28, p_rodata->unk_2C);
    tbl = (u32 *)(p_data + 0x158);
    fn_1_4AE0C((const char *)(p_data + 0x1AC), fn_1_1018BC_array_read(tbl)[p_lbl_1_bss_85250->unk_14]);
    fn_1_A8EB0(3, 3);
    fn_1_A8DD4((const char *)(p_data + 0x1B0),
        (const char *)(p_data + p_lbl_1_bss_85250->unk_8 * 0x104 + 4),
        p_lbl_1_bss_85250->unk_4);
    t7 = lbl_8006DCA4();
    v1 = (u32)t7;
    lbl_8006E0A4((void *)((u8 *)t0 + 0x10));
    lbl_8006E14C(p_rodata->unk_30);
    fn_80072558();
    v1 = *(u32 *)&lbl_1_bss_38454;
    v1 = *(u32 *)((u8 *)v1 + 8);
    fn_1_556B8((void *)(*(u32 *)((u8 *)v1 + 0x20)));
    t7 = lbl_8006DCA4();
    v1 = (u32)t7;
    fn_80072558();
    fn_1_556B8((void *)v2);
    if ((*(u32 *)((u8 *)v2 + 4) & 0x10) == 0) {
        return;
    }
    if (p_lbl_1_bss_85250->unk_0 == 0) {
        return;
    }
    fn_1_57714(12);
    fn_1_57720(1, 1, 1, 0);
    t7 = lbl_8006DCA4();
    v1 = (u32)t7;
    lbl_8006E14C(p_rodata->unk_34);
    fn_80072558();
    blkBp = &blkB;
    i = 0;
    while (i < p_lbl_1_bss_85250->unk_24) {
        e0 = (struct fn_1_1018BC_At18 *)(*(u32 *)((u32 *)p_lbl_1_bss_85250->unk_20 + i * 6));
        *(fn_1_1018BC_Pair8 *)&blkA = e0->pair;
        blkA.unk_8 = e0->unk_18;
        if (e0->unk_0 & 0x1) {
            blkA.unk_C = p_rodata->unk_18;
        } else {
            blkA.unk_C = p_rodata->unk_1C;
        }
        e1 = (struct fn_1_1018BC_At18 *)(*(u32 *)((u32 *)p_lbl_1_bss_85250->unk_20 + i * 6 + 1));
        *(fn_1_1018BC_Pair8 *)&blkB = e1->pair;
        blkB.unk_8 = e1->unk_18;
        if (e1->unk_0 & 0x1) {
            blkB.unk_C = p_rodata->unk_20;
        } else {
            blkB.unk_C = p_rodata->unk_24;
        }
        fn_1_57BBC(&blkA, blkBp);
        i++;
    }
    }
}
#pragma opt_dead_assignments reset
