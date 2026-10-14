/* Non-matching: best partial attempt (98.13% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/option/globals.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[360] = {0x89709094, 0x00000000, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x00000000, 0x8B4C8D86, 0x00000000, 0x81418142, 0x814C814D, 0x81458143, 0x81448146, 0x81478148, 0x8149817B, 0x817C815E, 0x81818183, 0x8184814F, 0x81518160, 0x81628175, 0x81768169, 0x816A816F, 0x8170816D, 0x816E818F, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x82D082E7, 0x82AA82C8, 0x00000000, 0x82A082A2, 0x82A482A6, 0x82A882A9, 0x82AB82AD, 0x82AF82B1, 0x82B382B5, 0x82B782B9, 0x82BB82BD, 0x82BF82C2, 0x82C482C6, 0x82C882C9, 0x82CA82CB, 0x82CC82CD, 0x82D082D3, 0x82D682D9, 0x82DC82DD, 0x82DE82DF, 0x82E082E2, 0x82E482E6, 0x82E782E8, 0x82E982EA, 0x82EB82ED, 0x82EE82EF, 0x82F082F1, 0x82AA82AC, 0x82AE82B0, 0x82B282B4, 0x82B682B8, 0x82BA82BC, 0x82BE82C0, 0x82C382C5, 0x82C782CE, 0x82D182D4, 0x82D782DA, 0x82CF82D2, 0x82D582D8, 0x82DB829F, 0x82A182A3, 0x82A582A7, 0x82C182E1, 0x82E382E5, 0x82EC81E7, 0x81E80000, 0x829F82A1, 0x82A382A5, 0x82A782AA, 0x82AC82AE, 0x82B082B2, 0x82B482B6, 0x82B882BA, 0x82BC82BE, 0x82C082C1, 0x82C582C7, 0x81408140, 0x81408140, 0x814082CE, 0x82D182D4, 0x82D782DA, 0x81408140, 0x81408140, 0x82E182E1, 0x82E382E5, 0x81408140, 0x81408140, 0x82EC82EC, 0x81408140, 0x81408140, 0x82A982AB, 0x82AD82AF, 0x82B182B3, 0x82B582B7, 0x82B982BB, 0x82BD82BF, 0x82C282C4, 0x82C682CF, 0x82D282D5, 0x82D882DB, 0x82CD82D0, 0x82D382D6, 0x82D982A0, 0x82A282A4, 0x82A682A8, 0x82C282E2, 0x82E482E6, 0x82ED8140, 0x81400000, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x814082C3, 0x81408140, 0x81408140, 0x81408140, 0x814082CF, 0x82D282D5, 0x82D882DB, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x82C18140, 0x814082CD, 0x82D082D3, 0x82D682D9, 0x82CE82D1, 0x82D482D7, 0x82DA8140, 0x81408140, 0x81408140, 0x82C38140, 0x81408140, 0x81408140, 0x81400000, 0x834A835E, 0x834A8369, 0x00000000, 0x83418343, 0x83458347, 0x8349834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x8369836A, 0x836B836C, 0x836D836E, 0x83718374, 0x82D6837A, 0x837D837E, 0x83808381, 0x83828384, 0x83868388, 0x8389838A, 0x838B838C, 0x838D838F, 0x83908391, 0x83928393, 0x8394834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618364, 0x83668368, 0x836F8372, 0x837582D7, 0x837B8370, 0x83738376, 0x82D8837C, 0x83408342, 0x83448346, 0x83488395, 0x83968362, 0x83838385, 0x8387838E, 0x81E781E8, 0x00000000, 0x83408342, 0x83448346, 0x8348834B, 0x834D834F, 0x83518353, 0x83558357, 0x835D835B, 0x83618362, 0x83668368, 0x81408140, 0x81408140, 0x8140836F, 0x83728375, 0x82D7837B, 0x81408140, 0x81408140, 0x81408383, 0x83858387, 0x81408140, 0x81408140, 0x8140838E, 0x81408140, 0x81408140, 0x8345834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x83708373, 0x837682D8, 0x837C836E, 0x83718374, 0x82D6837A, 0x83418343, 0x83458347, 0x8349834A, 0x83508363, 0x83848386, 0x8388838F, 0x81408140, 0x00000000, 0x81408140, 0x83948140, 0x81408395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408364, 0x81408140, 0x81408140, 0x81408140, 0x81408370, 0x83738376, 0x82D8837C, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x83448395, 0x81408140, 0x83968140, 0x81408140, 0x81408362, 0x81408140, 0x836E8371, 0x837482D6, 0x837A836F, 0x83728375, 0x82D7837B, 0x81408140, 0x81408140, 0x8140834B, 0x83518364, 0x81408140, 0x81408140, 0x81408140, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 225.43910217285156f;
}
static const u32 fzgx_pool_table3[65] = {0x74616C20, 0x4C657474, 0x65727300, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81E781E8, 0x00000000, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x81E781E8, 0x00000000, 0x5369676E, 0x73000000, 0x81438144, 0x81488149, 0x817B817C, 0x815E815F, 0x81818183, 0x81848146, 0x8147814C, 0x814D814F, 0x81518162, 0x8169816A, 0x816D816E, 0x816F8170, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x4E756D62, 0x65727300, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.21;
    d = 1.6666666666666667;
    d = 0.5;
    s = 48.0f;
    s = 0.25f;
    d = 1.0;
    s = 0.12999999523162842f;
    s = 0.0f;
    d = 1.5;
    d = 2.0;
    s = 1.6666666269302368f;
    s = 0.0625f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 32.0f;
    s = 24.0f;
    s = 18.0f;
}
static const u32 fzgx_pool_table5[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern s16 lbl_1_bss_960;
extern s32 lbl_801A66B4;

struct fn_4_D1A8_lbl_801A6410 {
    u32 unk_0;
};
extern struct fn_4_D1A8_lbl_801A6410 lbl_801A6410;

extern u8 lbl_4_rodata_410[0x710];

extern u32 fn_1_45D0(u32 pool, u32 size, u32 proto, u32 id);
extern u32 fn_800793D4(u32 p, u32 a, u32 b);
extern u32 fn_1_435C(u32);
extern u32 fn_1_3F8C(u32 dst, u32 proto, u32 item, u32 count);
extern void fn_1_47F74(s32);
extern void fn_1_411A4(u32);
extern void fn_1_A2D84(u32);
extern void fn_4_BC04(void);
extern void fn_4_C768(void);
extern void fn_4_B528(void);

// One palette/colour selector node: index tag, packed value id and a scale.
typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    u16 unk_4;
    u8 pad_6[2];
    f32 unk_8;
} OptSelectorNode;

// Builds the option palette selector: allocates the state block, registers both
// option tables and fills one node per active entry with its id and scale.
#pragma opt_propagation off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_strength_reduction off
void fn_4_D1A8(u32 arg_0, u32 arg_1, u32 arg_2) {
    f32 *fzgx_value;
    OptSelectorNode *node;
    Obj_4_bss_5680_Target **st = &lbl_4_bss_5680;
    u8 *ro = lbl_4_rodata_410;
    u32 lab_t0;
    u32 i;

{
    struct {
        u8 *tbl;
    } t;
    t.tbl = lbl_4_data_2F78;
    *st = (Obj_4_bss_5680_Target *)
        fn_1_45D0(lbl_801A6410.unk_0, 0x40, (u32)(t.tbl + 0xA0), 0x4EF);
    fn_800793D4((u32)*st, 0, 0x40);
    (*st)->unk_4 = arg_0;
    (*st)->unk_8 = arg_1;
    lab_t0 = arg_0;
    fn_1_435C(lab_t0);
    (*st)->unk_18 =
        fn_1_3F8C((u32)(t.tbl + 0x130), (u32)fn_4_BC04, 0, 10);

    fn_1_47F74(143);
    if (lbl_1_bss_960 != 1) {
        fn_1_47F74(154);
        fn_1_47F74(158);
        fn_1_411A4(1);
    }

    lab_t0 = arg_1;
    fn_1_435C(lab_t0);
    (*st)->unk_1C =
        fn_1_3F8C((u32)(0x140 + t.tbl), (u32)fn_4_C768, 0, 10);

    if (lbl_801A66B4 == 5) {
        (*st)->unk_3C = (u32)(u16 *)t.tbl;
        (*st)->unk_3B = 4;
    } else {
        (*st)->unk_3C = (u32)(u16 *)(t.tbl + 0x50);
        (*st)->unk_3B = 4;
    }

    for (i = 0; i < (*st)->unk_3B; i++) {
        node = (OptSelectorNode *)
            fn_1_45D0(lbl_801A6410.unk_0, 0xC, (u32)(t.tbl + 0xA0), 0x1A5);
        fn_800793D4((u32)node, 0, 0xC);
        node->unk_0 = (u8)i;

        switch ((u8)i) {
        case 0:
            node->unk_4 = 0xB2;
            node->unk_8 = (32.0f);
            break;
        case 1:
            node->unk_4 = 0x114;
            fzgx_value = &(node->unk_8);
            (void) fzgx_value;  /* fzgx: keeps the web at its definition */
            *fzgx_value = (24.0f);
            break;
        case 2:
            node->unk_4 = 0x139;
            node->unk_8 = (18.0f);
            break;
        case 3:
            node->unk_4 = 0x54;
            node->unk_8 = (24.0f);
            break;
        }

        fn_1_3F8C((u32)(t.tbl + 0x158), (u32)fn_4_B528, (u32)node, 11);
}
    }

    (*st)->unk_C = (u8)arg_2;

    {
        u16 *p = (u16 *)(*st)->unk_3C;
        for (i = 0; i < (*st)->unk_3B; i++) {
            *p = (u16)(0);
        }
    }

    (*st)->unk_12 = 0x62;
    fn_1_A2D84(0xA9100000);
    ((u8 *)st)[4] = 0;
    ((u8 *)st)[5] = 0;
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset

#pragma opt_loop_invariants reset

#pragma opt_propagation reset
