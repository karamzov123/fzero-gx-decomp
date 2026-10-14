/* Non-matching: best partial attempt (83.44% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/interview/interview.h"

extern u32 fn_17_750C(void *);
extern u32 fn_17_1DA4(void);
extern u32 fn_17_2414(void);
extern void fn_17_9F8(void);
extern void fn_17_74C0(void *);
extern void fn_1_154F1C(void);
extern void fn_1_154F74(u32, u32);
extern void fn_1_154F88(f32);
extern void fn_1_154F98(u32);
extern void fn_1_154FD8(void);
extern void fn_1_97204(void *, void *);
extern void fn_1_154ED0(void *);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_A2A70(u32, u32, u32 *, u32);
extern void fn_1_A2E24(u32, u32, s32);
extern void fn_1_A2D84(u32);
extern void fn_1_15B654(void);
extern u32 fn_8004BF0C(void *, u32);
extern u32 fn_1_A1588(void *, u32);
extern void ADXT_Stop(void *);
typedef struct {
    u32 unk_0;
    u32 unk_4;
} Obj_1_bss_6EAD0_At0;
typedef struct {
    Obj_1_bss_6EAD0_At0 *unk_0;
    u8 pad_4[0x704];
} Obj_1_bss_6EAD0;
extern Obj_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern u32 lbl_1_bss_6EAB4;
extern const f32 lbl_17_rodata_3C;
extern const f32 lbl_17_rodata_40;

typedef struct {
    u8 row[0x138];
} InterviewRow;

typedef struct {
    u32 unk_0;
    void *unk_4;
    u8 pad_8[0x80];
    s32 unk_88;
} InterviewChara;

typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s8 unk_34;
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
} InterviewTalk;

typedef struct {
    u8 pad_0[0x1C];
    s32 unk_1C;
    s32 unk_20;
    u8 pad_24[0x30];
    s32 unk_54;
    u32 unk_58;
    u16 unk_5C;
    u8 pad_5E[0x2];
    u8 unk_60[0x5C];
    u8 pad_BC[0x18];
    s16 unk_D4;
    s16 unk_D6;
    InterviewChara *unk_D8;
    u8 pad_DC[0x1C];
    u8 unk_F8;
    u8 unk_F9;
    u8 unk_FA;
    u8 pad_FB[0x2D];
    u8 unk_128;
} InterviewState;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_17_bss_0;
u8 fzgx_obj_lbl_17_bss_1;
u8 lbl_17_bss_2;
u8 lbl_17_bss_3;
u32 lbl_17_bss_3_fill_4[2];
u32 lbl_17_bss_C;
u32 lbl_17_bss_10;
u32 fzgx_obj_lbl_17_bss_14;
u32 lbl_17_bss_18_fill_18;
s32 lbl_17_bss_18_4;
s32 lbl_17_bss_20;
u32 lbl_17_bss_24[4];
u32 lbl_17_bss_34[8];
s32 fzgx_obj_lbl_17_bss_54;
u32 fzgx_obj_lbl_17_bss_58;
u16 lbl_17_bss_58_4;
u16 lbl_17_bss_58_fill_5E;
u8 fzgx_obj_lbl_17_bss_60[0x5C];
u32 lbl_17_bss_60_fill_BC[6];
s16 lbl_17_bss_60_74;
s16 fzgx_obj_lbl_17_bss_D6;
InterviewChara *fzgx_obj_lbl_17_bss_D8;
u32 lbl_17_bss_D8_fill_DC[7];
u8 lbl_17_bss_D8_20;
u8 lbl_17_bss_D8_21;
u8 lbl_17_bss_FA;
u8 lbl_17_bss_FA_fill_FB;
u32 lbl_17_bss_FA_fill_FC[11];
u8 lbl_17_bss_FA_2E;
u8 lbl_17_bss_FA_fill_129;
u16 lbl_17_bss_FA_fill_12A;
u32 lbl_17_bss_FA_fill_12C[8];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_17_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_1;
    s = *(u8 *)&lbl_17_bss_2;
    s = *(u8 *)&lbl_17_bss_3;
    s = *(u8 *)&lbl_17_bss_3_fill_4;
    s = *(u8 *)&lbl_17_bss_C;
    s = *(u8 *)&lbl_17_bss_10;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_14;
    s = *(u8 *)&lbl_17_bss_18_fill_18;
    s = *(u8 *)&lbl_17_bss_18_4;
    s = *(u8 *)&lbl_17_bss_20;
    s = *(u8 *)&lbl_17_bss_24;
    s = *(u8 *)&lbl_17_bss_34;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_54;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_58;
    s = *(u8 *)&lbl_17_bss_58_4;
    s = *(u8 *)&lbl_17_bss_58_fill_5E;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_60;
    s = *(u8 *)&lbl_17_bss_60_fill_BC;
    s = *(u8 *)&lbl_17_bss_60_74;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_D6;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_D8;
    s = *(u8 *)&lbl_17_bss_D8_fill_DC;
    s = *(u8 *)&lbl_17_bss_D8_20;
    s = *(u8 *)&lbl_17_bss_D8_21;
    s = *(u8 *)&lbl_17_bss_FA;
    s = *(u8 *)&lbl_17_bss_FA_fill_FB;
    s = *(u8 *)&lbl_17_bss_FA_fill_FC;
    s = *(u8 *)&lbl_17_bss_FA_2E;
    s = *(u8 *)&lbl_17_bss_FA_fill_129;
    s = *(u8 *)&lbl_17_bss_FA_fill_12A;
    s = *(u8 *)&lbl_17_bss_FA_fill_12C;
}
#pragma section code_type ".text"

#pragma opt_common_subs off
#pragma opt_propagation off
void fn_17_1798(void) {
    
    u8 *pool = (u8 *)&lbl_17_data_0 + 0x60000;
    s32 speaker;
    void * lab_t0;
    s16 * tmp_cse2;

    if (fzgx_obj_lbl_17_bss_58 & 0x10000000) {
        return;
    }
    fn_17_750C(fzgx_obj_lbl_17_bss_60);

    if (lbl_17_bss_58_4 >= 4 && lbl_17_bss_58_4 <= 5) {
        fn_1_154F1C();
        fn_17_1DA4();
        fn_17_2414();
        fn_1_154F74(0x3C, 0x181);
        if (fzgx_obj_lbl_17_bss_54 == 5) {
            fn_1_154F88(lbl_17_rodata_3C);
        } else {
            fn_1_154F88(lbl_17_rodata_40);
        }
        ADXT_Stop((void *)lbl_1_bss_6EAD0.unk_0->unk_4);
    } else {
        lbl_17_bss_FA_2E = 0;
    }

    speaker = (s8)(lbl_17_bss_18_4);
    if (speaker == ((InterviewTalk *)(pool + 0x3058))->unk_10) {
        lbl_17_bss_58_4 = 4;
    }
    if (lbl_17_bss_20 == ((InterviewTalk *)(pool + 0x3058))->unk_30) {
        lbl_17_bss_58_4 = 0xC;
    }
    if (speaker == ((InterviewTalk *)(pool + 0x3058))->unk_4) {
        lbl_17_bss_58_4 = 1;
    }
    if (speaker == ((InterviewTalk *)(pool + 0x3058))->unk_8) {
        lbl_17_bss_58_4 = 2;
    }
    if (lbl_17_bss_58_4 >= 2 && lbl_17_bss_58_4 <= 6) {
        lbl_17_bss_60_74--;
        if (lbl_17_bss_60_74 < -0x5F) {
            lbl_17_bss_60_74 = -0x5F;
        }
        fn_8004BF0C((void *)lbl_1_bss_6EAD0.unk_0->unk_0, lbl_17_bss_60_74);
    }

    if (speaker == ((InterviewTalk *)(pool + 0x3058))->unk_C) {
        s32 idx = fzgx_obj_lbl_17_bss_D8->unk_88;
        if (lbl_17_bss_D8_20 < 2) {
            tmp_cse2 = (s16 *)(pool + 0x2C34);
            switch (tmp_cse2[idx]) {
case 3: case 4: {

                lab_t0 = fzgx_obj_lbl_17_bss_D8->unk_4;
                fn_1_97204(lab_t0, pool + 0x3FAC);
                fn_1_154ED0(&((InterviewRow *)(pool + 0x15DC))[fzgx_obj_lbl_17_bss_54]);
            
} break;
default: {

                lab_t0 = fzgx_obj_lbl_17_bss_D8->unk_4;
                fn_1_97204(lab_t0, pool + 0x3FB8);
                fn_1_154ED0(&((InterviewRow *)(pool + 0xD18))[fzgx_obj_lbl_17_bss_54]);
            
} break;
}
        } else if (lbl_17_bss_D8_20 == 2) {
            switch (tmp_cse2[idx]) {
case 3: case 4: {

                lab_t0 = fzgx_obj_lbl_17_bss_D8->unk_4;
                fn_1_97204(lab_t0, pool + 0x3FC0);
                fn_1_154ED0(&((InterviewRow *)(pool + 0x1E54))[fzgx_obj_lbl_17_bss_54]);
            
} break;
default: {

                lab_t0 = fzgx_obj_lbl_17_bss_D8->unk_4;
                fn_1_97204(lab_t0, pool + 0x3FCC);
                fn_1_154ED0(&((InterviewRow *)(pool - 0x470))[fzgx_obj_lbl_17_bss_54]);
            
} break;
}
        } else {
            switch (tmp_cse2[idx]) {
case 3: case 4: {

                lab_t0 = fzgx_obj_lbl_17_bss_D8->unk_4;
                fn_1_97204(lab_t0, pool + 0x3FC0);
                fn_1_154ED0(&((InterviewRow *)(pool + 0x1E54))[fzgx_obj_lbl_17_bss_54]);
            
} break;
default: {

                lab_t0 = fzgx_obj_lbl_17_bss_D8->unk_4;
                fn_1_97204(lab_t0, pool + 0xD8);
                fn_1_154ED0(&((InterviewRow *)(pool + 0x454))[fzgx_obj_lbl_17_bss_54]);
            
} break;
}
        }

        lbl_17_bss_58_4 = 3;
        if (fzgx_obj_lbl_17_bss_54 == 5) {
            fn_1_154F74(0x28, 0x168);
            fn_1_154F98(2);
            fn_1_154F88(lbl_17_rodata_3C);
        } else {
            fn_1_154F74(0x19, 0x15E);
            fn_1_154F98(1);
            fn_1_154F88(lbl_17_rodata_40);
        }
    }

    if (lbl_17_bss_58_4 >= 3 && lbl_17_bss_58_4 < 4) {
        fn_1_49410();
        fn_1_495B0(0x80000000);
        fn_1_49590(lbl_17_rodata_3C);
        fn_1_154FD8();
    }

    if (lbl_17_bss_58_4 == 7) {
        lbl_17_bss_20 = 0;
        lbl_17_bss_58_4 = 8;
        lbl_1_bss_6EAB4 |= 0x2C;
        fn_1_A2A70(0xC, 0x64, &lbl_1_bss_6EAB4, 8);
    }

    if (lbl_17_bss_20 == ((InterviewTalk *)(pool + 0x3058))->unk_24) {
        lbl_17_bss_58_4 = 9;
        fn_1_154F1C();
        fn_1_A1588((void *)lbl_1_bss_6EAD0.unk_0->unk_0, 0x13);
        lbl_17_bss_60_74 = -0x4B;
        lbl_1_bss_6EAB4 &= ~0x4;
        fn_8004BF0C((void *)lbl_1_bss_6EAD0.unk_0->unk_0, -0x4B);
        fn_17_74C0(fzgx_obj_lbl_17_bss_60);
        fn_1_15B654();
    }

    if (lbl_17_bss_20 == ((InterviewTalk *)(pool + 0x3058))->unk_30 + 0x28) {
        if (lbl_17_bss_D8_20 != 3) {
            fzgx_obj_lbl_17_bss_D6 = -0x3E7;
            lbl_1_bss_6EAB4 &= ~0x20;
            fn_8004BF0C((void *)lbl_1_bss_6EAD0.unk_0->unk_4, -0x3E7);
            fn_1_A2E24(3, 0xA0100000, 0x7F);
            fn_1_A2D84(0xA91A0600);
        }
    }

    if (lbl_17_bss_20 == ((InterviewTalk *)(pool + 0x3058))->unk_38 + 0x28) {
        if (lbl_17_bss_D8_21 != 0 || lbl_17_bss_FA != 0) {
            fn_1_A2D84(0xA91A0700);
        }
    }

    if (lbl_17_bss_20 == ((InterviewTalk *)(pool + 0x3058))->unk_34) {
        if (lbl_17_bss_D8_20 == 3) {
            fn_17_9F8();
        }
        lbl_17_bss_58_4 = 0xD;
    }

    if (lbl_17_bss_20 == ((InterviewTalk *)(pool + 0x3058))->unk_40) {
        fn_17_9F8();
        lbl_17_bss_58_4 = 0x10;
    }

    {
        u16 unk_5C = lbl_17_bss_58_4;
        u32 flags;

        if (unk_5C >= 6 && unk_5C <= 8) {
            fzgx_obj_lbl_17_bss_58 |= 0x08000000;
        } else {
            fzgx_obj_lbl_17_bss_58 &= ~0x08000000;
        }

        if (unk_5C >= 1 && unk_5C <= 8) {
            fzgx_obj_lbl_17_bss_58 |= 0x02000000;
        } else {
            fzgx_obj_lbl_17_bss_58 &= ~0x02000000;
        }

        flags = fzgx_obj_lbl_17_bss_58 & ~0x04000000;
        if (unk_5C <= 8) {
            flags |= 0x04000000;
        }
        fzgx_obj_lbl_17_bss_58 = flags;

        if (unk_5C >= 2 && unk_5C <= 3) {
            fzgx_obj_lbl_17_bss_58 = flags | 0x01000000;
        } else {
            fzgx_obj_lbl_17_bss_58 &= ~0x01000000;
        }

        if (lbl_17_bss_18_4 < 0x4650) {
            lbl_17_bss_18_4++;
        }
        if (lbl_17_bss_20 < 0x4650 && unk_5C >= 7) {
            lbl_17_bss_20++;
        }
    }
}
#pragma opt_propagation reset

#pragma opt_common_subs reset

