/* Non-matching: best partial attempt (90.88% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car.h"
#include "rel/main_rel/car_test.h"

extern void fn_80083DB0(void *arg0, u32 arg1);
extern void fn_1_801F8(s16 arg0, void *arg1);
extern int sprintf(char *dst, const char *fmt, ...);

#pragma opt_propagation off
void *fn_1_7F58C(s16 car_type, void *car, u32 a2, s32 a3) {
    u8 *db = (u8 *)&lbl_1_data_1F1D8;
    u32 *table = (u32 *)(db + 0x324);
    fn_80083DB0(car, table[car_type]);
    if (a3 == 1) {
        fn_1_801F8(car_type, car);
    }
    if (a2 & 0xFF) {
        if ((a2 & 0xFF) >= 4) {
            sprintf(car, (const char *)(db + 0x1358), car, (a2 & 0xFF) - 4);
        } else {
            sprintf(car, (const char *)(db + 0x1364), car, a2 & 0xFF);
        }
    } else {
        sprintf(car, (const char *)(db + 0x1370), car, a2 & 0xFF);
    }
    return car;
}
