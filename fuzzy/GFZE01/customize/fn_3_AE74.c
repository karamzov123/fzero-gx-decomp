/* Non-matching: best partial attempt (95.02% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/customize.h"
extern u32 lbl_3_bss_7DB60[328];
extern u8 lbl_1_bss_8B3A0[];
extern void fn_1_80058(s8,u8 *);
extern u32 fn_1_12A32C(void *);
extern void fn_1_12A2B8(u32);
extern void fn_1_80C18(u8 *,u8 *,s8);
extern s32 fn_8006FDEC(void);
extern s32 fn_1_3F8C(void *,void (*)(void),u32,u32);
extern void fn_3_286BC(void);
extern void fn_1_4A00(s32,u8,void *);
extern u32 fn_1_152510(void *,u32,void *,u32,u32);
extern s32 fn_1_152970(s16 *,s16 *,s16,u32,void *,s16,s16);
extern void fn_1_47F74(s32);
typedef struct { u8 pad[0x324]; u32 value; u8 tail[0x118]; } CustomizeEntry;
typedef struct { u8 pad[0xc4]; s16 scroll; } CustomizePanel;
typedef struct { u8 pad[6]; s16 selection; } CustomizeSelection;
void fn_3_AE74(void) {
    u8 *b = (u8 *)&lbl_3_bss_0;
    u8 *d = (u8 *)&lbl_3_data_0;
    u8 *upper = b + 0x20000;
    s16 saved = *(s16 *)((u8 *)(&lbl_3_bss_0) + 0xf0 + 6);
    s16 i;
    s16 x, y;
    s16 low, high;
    for (i = 0; i < 41; i++) {
        fn_1_80058((s8)i, (u8 *)lbl_3_bss_7DB60 + i * 32);
        *(s16 *)((u8 *)lbl_3_bss_7DB60 + i * 32) = i;
        {
            u32 mask = 1 << *(s16 *)(d + 0x11d0);
            *((u8 *)lbl_3_bss_7DB60 + i * 32 + 8) = 0;
            *((u8 *)lbl_3_bss_7DB60 + i * 32 + 8) |= 16;
            *(u32 *)((u8 *)lbl_3_bss_7DB60 + i * 32 + 4) = mask;
        }
    }
    *(u32 *)(d + 0x11d4) = fn_1_12A32C(d + 0x1164);
    fn_1_12A2B8(1);
    fn_1_80C18(*(u8 **)(upper + 0x854), (u8 *)lbl_3_bss_7DB60, 41);
    fn_1_12A2B8(0);
    for (i = 0; i < 41; i++)
        (*(CustomizeEntry **)(upper + 0x854))[i].value = *(u32 *)(d + 0x11d4);
    if (*(s32 *)(d + 0xb8) == -1) {
        fn_8006FDEC();
        *(s32 *)(d + 0xb8) = fn_1_3F8C(d + 0x1948, fn_3_286BC, 0, 8);
    }
    fn_1_4A00(1,15,*(void **)(upper + 0x850));
    *(u32 *)(upper + 0x43a8) = 0;
    fn_1_152510(d,42,&lbl_3_bss_2C584,7,7);
    {
        u8 *panel = b + 0x20;
        s16 current = *(s16 *)(d + 0xc4);
        lbl_1_bss_8B3A0[0x9e] = saved;
        *(s16 *)(panel + 0xc4) = 0;
        if (current == -1) {
            *(s16 *)(d + 0xc4) = 1;
        } else {
            do {
                fn_1_152970(&x,&y,*(s16 *)(d + 0xc4),0,&lbl_3_bss_2C584,7,7);
                low = -*(s16 *)(panel + 0xc4);
                high = low + 2;
                if (x < low || x > high)
                    --*(s16 *)(panel + 0xc4);
            } while (x < low || x > high);
        }
    }
    *(s32 *)(b + 0x120) = -1;
    fn_1_47F74(0x4a); fn_1_47F74(0x54); fn_1_47F74(0x38); fn_1_47F74(0x3e);
    fn_1_47F74(0x37); fn_1_47F74(0x55); fn_1_47F74(0x30); fn_1_47F74(0x35);
    fn_1_47F74(0x3a); fn_1_47F74(0x40); fn_1_47F74(0x44); fn_1_47F74(0x50);
    fn_1_47F74(0x33); fn_1_47F74(0x2e); fn_1_47F74(0x31); fn_1_47F74(0x4f);
    fn_1_47F74(0x39); fn_1_47F74(0x3d); fn_1_47F74(0x4c); fn_1_47F74(0x3f);
    fn_1_47F74(0x48); fn_1_47F74(0x52); fn_1_47F74(0x45); fn_1_47F74(0x53);
    fn_1_47F74(0x3c); fn_1_47F74(0x56); fn_1_47F74(0x43); fn_1_47F74(0x42);
    fn_1_47F74(0x32); fn_1_47F74(0x2f); fn_1_47F74(0x34); fn_1_47F74(0x36);
    fn_1_47F74(0x4d); fn_1_47F74(0x46); fn_1_47F74(0x41); fn_1_47F74(0x51);
    fn_1_47F74(0x4e); fn_1_47F74(0x47); fn_1_47F74(0x3b); fn_1_47F74(0x4b);
    fn_1_47F74(0x49); fn_1_47F74(0xa3);
    *(u32 *)(b + 0xc) = 0;
}
