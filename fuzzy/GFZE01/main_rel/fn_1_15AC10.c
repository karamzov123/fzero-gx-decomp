/* Non-matching: best partial attempt (98.97% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ranking.h"

extern u8 lbl_1_bss_718E0[0x59E8];
extern u32 fn_1_B7FC8(void);
extern u32 fn_8003D4C0(void);
extern u32 lbl_801A63C0;

static inline s32 ranking_code_random15(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

#define RANKING_CODE_DIGIT(offset, divisor) \
    ((u8 *)&lbl_1_bss_8F878)[0x18 + (offset)] = '0' + (code / (divisor)) % 10ULL

u64 fn_1_15AC10(void) {
    u64 code;
    u64 high;
    u64 mix;
    u64 random;
    u64 bit_index;
    u64 digit_index;
    u64 scramble;
    s32 a, b, c;
    Obj_1_bss_8F878 *state;

    high = (u64)fn_1_B7FC8() & 0x3FFFFFFULL;
    high += (u64)(((u8 *)&lbl_1_bss_718E0)[0x5523] & 0x3F) << 26;
    code = (high << 32) + fn_8003D4C0();
    mix = ((code >> 32) & 3ULL) + ((code & 0x2000ULL) >> 11) +
          ((code & 0x100000ULL) >> 17);
    lbl_801A63C0 = (u8)mix ^ 0xCAE87FB5;
    random = ranking_code_random15();
    for (bit_index = 0; bit_index < 64; bit_index++) {
        if (bit_index != 13 && bit_index != 20 && bit_index - 32 > 1) {
            u64 bit = (code >> bit_index) & 1ULL;
            bit += (random % (bit_index + 11)) & 1ULL;
            code &= ~(1ULL << bit_index);
            if (bit & 1ULL) code |= 1ULL << bit_index;
        }
    }

    RANKING_CODE_DIGIT(0, 1ULL);
    RANKING_CODE_DIGIT(1, 10ULL);
    RANKING_CODE_DIGIT(2, 100ULL);
    RANKING_CODE_DIGIT(3, 1000ULL);
    ((u8 *)&lbl_1_bss_8F878)[0x18 + 4] = '-';
    RANKING_CODE_DIGIT(5, 10000ULL);
    RANKING_CODE_DIGIT(6, 100000ULL);
    RANKING_CODE_DIGIT(7, 1000000ULL);
    RANKING_CODE_DIGIT(8, 10000000ULL);
    ((u8 *)&lbl_1_bss_8F878)[0x18 + 9] = '-';
    RANKING_CODE_DIGIT(10, 100000000ULL);
    RANKING_CODE_DIGIT(11, 1000000000ULL);
    RANKING_CODE_DIGIT(12, 10000000000ULL);
    RANKING_CODE_DIGIT(13, 100000000000ULL);
    ((u8 *)&lbl_1_bss_8F878)[0x18 + 14] = '-';
    RANKING_CODE_DIGIT(15, 1000000000000ULL);
    RANKING_CODE_DIGIT(16, 10000000000000ULL);
    RANKING_CODE_DIGIT(17, 100000000000000ULL);
    RANKING_CODE_DIGIT(18, 1000000000000000ULL);
    ((u8 *)&lbl_1_bss_8F878)[0x18 + 19] = '-';
    RANKING_CODE_DIGIT(20, 10000000000000000ULL);
    RANKING_CODE_DIGIT(21, 100000000000000000ULL);
    RANKING_CODE_DIGIT(22, 1000000000000000000ULL);
    RANKING_CODE_DIGIT(23, 10000000000000000000ULL);

    lbl_801A63C0 = (u32)(code % 1000ULL) ^ 0xCAE87FB5;
    a = ranking_code_random15();
    b = ranking_code_random15();
    c = ranking_code_random15();
    scramble = (u64)a * b * c;
    state = &lbl_1_bss_8F878;
    for (digit_index = 5; digit_index < 24; digit_index++) {
        u8 *digit = (u8 *)state + digit_index;
        digit += 0x18;
        if (*digit != '-') {
            *digit += scramble % 10ULL;
            if (*digit > '9') *digit -= 10;
            scramble /= 10ULL;
        }
    }
    lbl_1_bss_8F878.unk_30 = 0;
    return code;
}
#undef RANKING_CODE_DIGIT
