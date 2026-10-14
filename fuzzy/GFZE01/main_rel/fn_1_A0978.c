/* Non-matching: best partial attempt (97.20% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sound.h"

extern int fn_1_3F864(void);
extern void fn_1_A3A1C(void);
extern void fn_1_A31E4(void);
extern u32 fn_1_864E8(u8 arg0);
extern void fn_1_A54FC(void);
extern void fn_1_A5590(void);
extern void fn_1_A24CC(void);

#pragma opt_lifetimes off
#pragma opt_propagation off
void fn_1_A0978(void) {
    u8 *entry;
    u8 *sound;
    s32 i;
    sound = (u8 *)&lbl_1_bss_6EA98;
    if (fn_1_3F864() == 0 || sound[0xD] != 0) {
        return;
    }
    fn_1_A3A1C();
    fn_1_A31E4();
    entry = sound + 0x74C;
    i = 0;
    while (i < (s8)sound[0x82C]) {
        int index;
        u32 flags;
        index = entry[1];
        flags = fn_1_864E8(index);
        if ((flags & 0x00800000) == 0) {
            u8 *next;
            u8 *counter;
            counter = sound;
            counter = counter + 0x7B4 + 2 * index;
            next = counter + 1;
            next[0]++;
            if ((s8)*(0 + next) > 10) {
                counter[0] = 0;
                next[0] = 10;
            }
        }
        if ((flags & 0x02000000) == 0) {
            u8 *next;
            u8 *counter;
            counter = sound;
            counter = counter + 0x7F0 + 2 * index;
            next = counter + 1;
            next[0]++;
            if ((s8)*(next + 0) > 30) {
                counter[0] = 0;
                next[0] = 30;
            }
        }
        entry += 0x14;
        i++;
    }
    fn_1_A54FC();
    fn_1_A5590();
    fn_1_A24CC();
}
#pragma opt_propagation reset
#pragma opt_lifetimes reset
