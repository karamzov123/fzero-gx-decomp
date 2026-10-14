/* Non-matching: best partial attempt (98.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

typedef struct {
    s16 id;
    u8 pad_2[0x35E];
} T_FE014_Sel;

typedef struct {
    u8 v;
    u8 pad_1[7];
} T_FE014_Q;

typedef struct {
    u8 pad_0[0x32C];
    u32 unk_32C;
    u8 pad_330[0x60];
    u32 unk_390;
    u8 pad_394[0xC];
    T_FE014_Sel *unk_3A0;
    void *unk_3A4;
    u8 pad_3A8[0x12];
    s16 unk_3BA;
} T_FE014_Obj;

typedef struct {
    s16 id;
} T_FE014_Cur;

typedef struct {
    u8 pad_0[0x40F0];
    T_FE014_Cur *unk_40F0;
} T_FE014_Ctx;

typedef struct {
    u8 pad_0[4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[2];
    T_FE014_Q *unk_8;
    u8 *unk_C;
} T_FE014_Glob;

typedef struct {
    u8 pad_0[0x30];
} T_FE014_Tmp;

extern f32 lbl_1_rodata_7614[2];
extern f32 lbl_1_rodata_761C[13];
extern void *fn_1_FCF50(void);
extern void *fn_1_563B8(void *);
extern void fn_1_566EC(int, int);
extern void fn_1_7EB8C(void *, f32);
extern void fn_1_7F20C(void *, s32, f32);
extern void fn_1_7F1E8(void *, s32, f32);
extern void fn_1_7F230(void *, s32, f32);
extern void *fn_1_14DD68(void *);
extern void *fn_1_14DDF4(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_80072558(void);
extern void lbl_8006E0A4(void *);

#pragma opt_propagation off
void fn_1_FE014(void *arg0, void *arg1) {
    void * h;
    T_FE014_Glob *gp = (T_FE014_Glob *)&lbl_1_bss_850C0;
    T_FE014_Obj *obj = *(T_FE014_Obj **)arg0;
    T_FE014_Sel *sel;
    T_FE014_Q *qt;
    void * lab_t0;
    T_FE014_Tmp ta;
    T_FE014_Tmp tb;
    T_FE014_Tmp tc;
    T_FE014_Tmp td;
    T_FE014_Tmp te;
    T_FE014_Tmp tf;
    s16 id0;
    u8 q0;
    T_FE014_Obj * o3;

    if (obj == 0) {
        return;
    }
    if (obj->unk_3A4 == 0) {
        return;
    }
    sel = obj->unk_3A0;
    if (sel == 0) {
        return;
    }
    if (gp->unk_C == 0) {
        return;
    }
    qt = gp->unk_8;
    if (qt == 0) {
    } else {
        id0 = sel[0].id;
        q0 = qt[0].v;
        if (((q0) == (id0)) && sel[1].id == qt[1].v && sel[2].id == qt[2].v && gp->unk_4 == 0) {
            if (gp->unk_5 == ((T_FE014_Ctx *)arg1)->unk_40F0->id) {
                T_FE014_Obj *o1;
                s16 saved1;

                lbl_8006DB74(&ta);
                fn_80072558();
                lbl_8006DB74(&te);
                o1 = *(T_FE014_Obj **)arg0;
                saved1 = o1->unk_3BA;
                if (saved1 == 3) {
                    o1->unk_3BA = 2;
                }
                if (((T_FE014_Ctx *)arg1)->unk_40F0 != 0) {
                    s16 idx = ((T_FE014_Ctx *)arg1)->unk_40F0->id;
                    f32 f = o1->unk_32C == 0 ? lbl_1_rodata_7614[0] : lbl_1_rodata_761C[0];
                    lab_t0 = fn_1_FCF50;
                    h = fn_1_563B8(lab_t0);

                    fn_1_566EC(1, 255);
                    if (idx == 0) {
                        fn_1_7EB8C(o1, f);
                    } else if (o1->unk_390 & 0x4000000) {
                        fn_1_7F20C(o1, idx, f);
                    } else {
                        fn_1_7F1E8(o1, idx, f);
                    }
                    fn_1_566EC(0, 0);
                    lab_t0 = h;
                    fn_1_563B8(lab_t0);
                    o1->unk_3BA = saved1;
                }
                lbl_8006DBAC(&te);
                fn_80072558();
                lbl_8006DBAC(&ta);
            }
        } else if (gp->unk_4 != 0) {
            s16 id = ((T_FE014_Ctx *)arg1)->unk_40F0->id;

            if (sel[id].id == qt[id].v) {
                s16 saved2;
                T_FE014_Obj *o2;
                void *ptr2 = 0;

                lbl_8006DB74(&tb);
                {
                    s16 idx = ((T_FE014_Ctx *)arg1)->unk_40F0->id;

                    if (idx != 0) {
                        if (idx == 1) {
                            ptr2 = fn_1_14DD68(gp->unk_C + gp->unk_8[0].v * 0xA20);
                        } else if (idx == 2) {
                            ptr2 = fn_1_14DDF4(gp->unk_C + gp->unk_8[0].v * 0xA20);
                        }
                        lbl_8006E0A4(ptr2);
                    }
                }
                fn_80072558();
                o2 = *(T_FE014_Obj **)arg0;
                saved2 = o2->unk_3BA;
                if (saved2 == 3) {
                    o2->unk_3BA = 2;
                }
                if (((T_FE014_Ctx *)arg1)->unk_40F0 != 0) {
                    s16 idx = ((T_FE014_Ctx *)arg1)->unk_40F0->id;
                    f32 f = o2->unk_32C == 0 ? lbl_1_rodata_7614[0] : lbl_1_rodata_761C[0];
                    lab_t0 = fn_1_FCF50;
                    h = fn_1_563B8(lab_t0);

                    fn_1_566EC(1, 255);
                    if (idx == 0) {
                        fn_1_7EB8C(o2, f);
                    } else if (((0x4000000) & (o2->unk_390))) {
                        fn_1_7F230(o2, idx, f);
                    } else {
                        fn_1_7F1E8(o2, idx, f);
                    }
                    fn_1_566EC(0, 0);
                    lab_t0 = h;
                    fn_1_563B8(lab_t0);
                    o2->unk_3BA = saved2;
                }
                lbl_8006DBAC(&tb);
            }
        } else {
            s16 id = ((T_FE014_Ctx *)arg1)->unk_40F0->id;

            if (gp->unk_5 == id) {
                if (sel[id].id == qt[id].v) {
                    s32 saved3;

                    if (id0 != q0) {
                        void *ptr3 = 0;

                        lbl_8006DB74(&tc);
                        {
                            s16 idx = ((T_FE014_Ctx *)arg1)->unk_40F0->id;

                            if (idx != 0) {
                                if (idx == 1) {
                                    ptr3 = fn_1_14DD68(gp->unk_C + gp->unk_8[0].v * 0xA20);
                                } else if (idx == 2) {
                                    ptr3 = fn_1_14DDF4(gp->unk_C + gp->unk_8[0].v * 0xA20);
                                }
                                lbl_8006E0A4(ptr3);
                            }
                        }
                        fn_80072558();
                        o3 = *(T_FE014_Obj **)arg0;
                        saved3 = (s16)(o3->unk_3BA);
                        if (saved3 == 3) {
                            o3->unk_3BA = 2;
                        }
                        if (((T_FE014_Ctx *)arg1)->unk_40F0 != 0) {
                            s16 idx = ((T_FE014_Ctx *)arg1)->unk_40F0->id;
                            f32 f = o3->unk_32C == 0 ? lbl_1_rodata_7614[0] : lbl_1_rodata_761C[0];
                            lab_t0 = fn_1_FCF50;
                            h = fn_1_563B8(lab_t0);

                            fn_1_566EC(1, 255);
                            if (idx == 0) {
                                fn_1_7EB8C(o3, f);
                            } else if (o3->unk_390 & 0x4000000) {
                                fn_1_7F230(o3, idx, f);
                            } else {
                                fn_1_7F1E8(o3, idx, f);
                            }
                            fn_1_566EC(0, 0);
                            lab_t0 = h;
                            fn_1_563B8(lab_t0);
                            o3->unk_3BA = saved3;
                        }
                        lbl_8006DBAC(&tc);
                    } else {
                        lbl_8006DB74(&td);
                        fn_80072558();
                        lbl_8006DB74(&tf);
                        o3 = *(T_FE014_Obj **)arg0;
                        saved3 = (s16)(o3->unk_3BA);
                        if (saved3 == 3) {
                            o3->unk_3BA = 2;
                        }
                        if (((T_FE014_Ctx *)arg1)->unk_40F0 != 0) {
                            s16 idx = ((T_FE014_Ctx *)arg1)->unk_40F0->id;
                            f32 f = o3->unk_32C == 0 ? lbl_1_rodata_7614[0] : lbl_1_rodata_761C[0];
                            lab_t0 = fn_1_FCF50;
                            h = fn_1_563B8(lab_t0);

                            fn_1_566EC(1, 255);
                            if (idx == 0) {
                                fn_1_7EB8C(o3, f);
                            } else if (o3->unk_390 & 0x4000000) {
                                fn_1_7F20C(o3, idx, f);
                            } else {
                                fn_1_7F1E8(o3, idx, f);
                            }
                            fn_1_566EC(0, 0);
                            lab_t0 = h;
                            fn_1_563B8(lab_t0);
                            o3->unk_3BA = saved3;
                        }
                        lbl_8006DBAC(&tf);
                        fn_80072558();
                        lbl_8006DBAC(&td);
                    }
                }
            }
        }
    }
}
#pragma opt_propagation reset

