#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ranking.h"

extern void fn_80008BEC(void *dst, int value, int size);
extern void fn_80008BA8(void *, void *, int);
extern void fn_1_9AD88(void);
extern void fn_1_1594AC(int index, int flag);
extern void OSReport(const char *format, ...);
extern void fn_1_465D0(void *object, int value);
extern void fn_1_9AD54(void);


extern s16 fn_1_159804(s16 value, RankingArchive *entry);
extern void fn_1_4811C(s16 value);
extern void fn_1_48004(s16 value, u32 arg);
extern u32 lbl_1_rodata_DAF8[16];
extern void fn_1_9A508(void);

/* fzgx:begin fn_1_159440 */
// Preserve the current ranking entry before refreshing its state.
void fn_1_159440(int index, int flag) {
    RankingArchive *entry;

    entry = &lbl_1_data_4C810[index];
    entry->unk_34 = entry->unk_30;
    fn_1_1594AC(index, flag);
}
/* fzgx:end fn_1_159440 */

/* fzgx:begin fn_1_159478 */
void fn_1_159478(int index, int unused, int value) {
    RankingArchive *entry;

    entry = &lbl_1_data_4C810[index];
    entry->unk_34 = value;
    fn_1_1594AC(index, unused);
}
/* fzgx:end fn_1_159478 */

/* fzgx:begin fn_1_1594AC */
void fn_1_1594AC(int index, int flag) {
    RankingArchive *entry;
    s16 value;
    int i;

    // Activate the selected ranking entry and publish its referenced indices.
    entry = &lbl_1_data_4C810[index];
    if (entry->limit >= 0x10) {
        OSReport((const char *)lbl_1_data_4C900);
    }

    if (flag != 0) {
        fn_1_465D0(entry->path, 6);
    } else {
        fn_1_465D0(entry->path, 5);
    }

    for (i = 0;; i++) {
        value = entry->ids[i];
        if (value == -1) {
            break;
        }
        ((int *)lbl_1_bss_8F588)[value] = index;
    }

    fn_80008BEC(entry->queue, 0, sizeof(entry->queue));
    entry->head = 1;
    entry->tail = 0;
    entry->unk_38 = flag;
}
/* fzgx:end fn_1_1594AC */

/* fzgx:begin fn_1_159588 */
int fn_1_159588(int arg) {
    s16 index;
    s16 count;
    int value;
    RankingArchive *entry;

    index = ((arg >> 8) & 0xffff);
    if (((s32 *)lbl_1_bss_8F588)[index] != 0) {
        entry = &lbl_1_data_4C810[((s32 *)lbl_1_bss_8F588)[index]];
        count = entry->head;
        count = entry->tail - count + 1;
        if (count < 0) {
            count = count + 0x10;
        }

        if (lbl_1_data_FCD4[index].loaded != 0) {
            fn_1_159804(index, entry);
        } else {
            if (count >= entry->limit) {
                fn_1_4811C(entry->queue[entry->head]);
                value = entry->head + 1;
                entry->head = value > 0xf ? 0 : (value < 0 ? 0xf : value);
            }

            value = entry->tail + 1;
            entry->tail = value > 0xf ? 0 : (value < 0 ? 0xf : value);
            entry->queue[entry->tail] = index;
            fn_1_48004(entry->queue[entry->tail], entry->unk_34);
        }
    } else {
        return 0;
    }
    return 1;
}
/* fzgx:end fn_1_159588 */

/* fzgx:begin fn_1_1596DC */
#include "rel/main_rel/bitmap_resource.h"

extern int lbl_801A66B4;
extern s8 fn_1_46DC4(void *object);

void fn_1_1596DC(int index) {
    RankingArchive *entry;
    int i;
    int count;

    entry = &lbl_1_data_4C810[index];
    i = 0;
    while (entry->tail + 1 != entry->head &&
           (entry->tail != 0xf || entry->head != 0)) {
        fn_1_4811C(entry->queue[entry->head]);
        entry->head = entry->head + 1 > 0xf ? 0
                      : (entry->head + 1 < 0 ? 0xf : entry->head + 1);
        if (++i > 0x10) {
            break;
        }
    }

    if (entry->unk_38 != 0) {
        count = 0;
        for (i = 0;; i++) {
            if (entry->ids[i] == -1) {
                break;
            }
            if (fn_1_46DC4(lbl_1_data_FCD4[entry->ids[i]].paths[lbl_801A66B4]) != 0) {
                ((int *)lbl_1_bss_8F588)[entry->ids[i]] = count;
            }
        }
    }
}
/* fzgx:end fn_1_1596DC */

/* fzgx:begin fn_1_159804 */
s16 fn_1_159804(s16 value, RankingArchive *entry) {
    s16 start = entry->head;
    int count = 0;
    int found = 0;
    int next;
    s16 pos;

    while (entry->tail + 1 != start && (entry->tail != 15 || start != 0)) {
        next = start + 1;
        pos = next > 15 ? 0 : (next < 0 ? 15 : next);

        if (value == entry->queue[start]) {
            found = 1;
        }
        if (found) {
            entry->queue[start] = entry->queue[pos];
        }
        start = pos;

        count++;
        if (count > 16) {
            start = -1;
            break;
        }
    }

    entry->queue[entry->tail] = value;
    return start;
}
/* fzgx:end fn_1_159804 */

/* fzgx:begin fn_1_1598C4 */
struct fn_1_1598C4_lbl_1_bss_8F878 {
    u8 pad_0[0x34];
    u32 unk_34;
    u8 pad_38[0x1];
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    u8 unk_3C;
    u8 unk_3D;
    u8 unk_3E;
};
extern s16 fn_1_14F01C(s16);

void fn_1_1598C4(s32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u32 arg7, u64 arg8, u8 arg10) {
    s32 i;

    fn_80008BA8(&lbl_1_bss_8F878, (void *)arg7, 0x10);

    for (i = 0; i < 0x10; i += 2) {
        if (*((u8 *)(&lbl_1_bss_8F878) + i) == 0) {
            s32 j;
            s32 t = i + 1;
            for (j = t; j < 0x10; j++) {
                *(u8 *)((u8 *)(&lbl_1_bss_8F878) + j) = 0;
            }
            break;
        }
    }

    ((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)->pad_38[0] = arg10;
    *(s32 *)((u8 *)(&lbl_1_bss_8F878) + 20) = (s32)arg8;
    *(s32 *)((u8 *)(&lbl_1_bss_8F878) + 16) = (s32)(arg8 >> 32);
    ((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)->unk_34 = arg0 & 0x3FFFF;
    ((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)->unk_39 = arg1;
    ((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)->unk_3D = arg6;
    ((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)->unk_3E = (0.0999000967f * arg5);

    if (arg1 >= 0x29U) {
        if (arg2 < fn_1_14F01C(0)) {
            ((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)->unk_3A = arg2;
        } else {
            ((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)->unk_3A = 0;
        }
        if (arg3 < fn_1_14F01C(1)) {
            ((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)->unk_3B = arg3;
        } else {
            ((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)->unk_3B = 0;
        }
        if (arg4 < fn_1_14F01C(2)) {
            ((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)->unk_3C = arg4;
            return;
        }
        ((struct fn_1_1598C4_lbl_1_bss_8F878 *)&lbl_1_bss_8F878)->unk_3C = 0;
    }
}
/* fzgx:end fn_1_1598C4 */

/* fzgx:begin fn_1_159AE0 */
extern u32 lbl_801A63C0;
extern u8 fn_1_128E10(u8);

static inline void seed_rng(u32 seed) {
    lbl_801A63C0 = seed ^ 0xCAE87FB5;
}

static inline s32 next_rng(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

#define DIGIT(field, divisor) lbl_1_bss_8F878.field = (v0_2 / (divisor)) % 10 + '0'

void fn_1_159AE0(void) {
    u8 v0;
    u64 v35, v4, v66, v65;
    u8 v37;
    u32 v79, v83;
    s32 v84;
    u64 v0_2;

    if (lbl_1_bss_8F878.unk_38 != 0) {
        v0 = fn_1_128E10(lbl_1_bss_8F878.unk_39);
    } else {
        v0 = 0;
    }
    if (lbl_1_bss_8F878.unk_39 >= 41) {
        v4 = ((u64)lbl_1_bss_8F878.unk_10 << 32) | lbl_1_bss_8F878.unk_14;
        v35 = lbl_1_bss_8F878.unk_34 + ((u64)lbl_1_bss_8F878.unk_3A << 18) +
              ((u64)lbl_1_bss_8F878.unk_3B << 23) +
              ((u64)lbl_1_bss_8F878.unk_3C << 28) +
              ((u64)lbl_1_bss_8F878.unk_3E << 33);
        v66 = (v4 & 1023) + ((v4 >> 10) & 1023) + ((v4 >> 20) & 1023) +
              ((v4 >> 30) & 1023) + ((v4 >> 40) & 1023) +
              ((v4 >> 50) & 1023) + ((v4 >> 60) & 1023);
        for (v65 = 0; v65 < 16; v65++) {
            v37 = (&lbl_1_bss_8F878.unk_0)[v65];
            v66 += v37;
            v66 += v37 & (((v65 + 1) * 6505) & 1023);
        }
        v66 += lbl_1_bss_8F878.unk_3D * 19;
        v66 += (v35 & 4095) + ((v35 >> 12) & 4095) +
               ((v35 >> 24) & 4095) + ((v35 >> 36) & 4095);
        for (v65 = 0; v65 < 29; v65 += 3) {
            v66 += 1 << ((v35 >> v65) & 7);
        }
        v35 += (v66 & 4095) << 37;
        seed_rng(v35 & 255);
        v84 = next_rng();
        v0_2 = v35 + (((u64)v84 * 0x31AFD498DULL) & ~255ULL);
        DIGIT(unk_3F, 100000000000000ULL);
        DIGIT(unk_44, 10000000000000ULL);
        DIGIT(unk_49, 1000000000000ULL);
        lbl_1_bss_8F878.unk_42 = '-';
        DIGIT(unk_40, 100000000000ULL);
        DIGIT(unk_45, 10000000000ULL);
        DIGIT(unk_4A, 1000000000ULL);
        DIGIT(unk_4E, 100000000ULL);
        lbl_1_bss_8F878.unk_47 = '-';
        DIGIT(unk_41, 10000000ULL);
        DIGIT(unk_46, 1000000ULL);
        DIGIT(unk_4B, 100000ULL);
        DIGIT(unk_4F, 10000ULL);
        lbl_1_bss_8F878.unk_4C = '-';
        DIGIT(unk_43, 1000ULL);
        DIGIT(unk_48, 100ULL);
        DIGIT(unk_4D, 10ULL);
        lbl_1_bss_8F878.unk_50 = v0_2 % 10 + '0';
        lbl_1_bss_8F878.unk_51 = 0;
    } else if (v0 != 0) {
        v4 = lbl_1_bss_8F878.unk_10;
        v4 <<= 32;
        v4 |= lbl_1_bss_8F878.unk_14;
        v35 = lbl_1_bss_8F878.unk_34 + (v0 << 18) + (lbl_1_bss_8F878.unk_3E << 22);
        v66 = (v4 & 1023) + ((v4 >> 10) & 1023) + ((v4 >> 20) & 1023) +
              ((v4 >> 30) & 1023) + ((v4 >> 40) & 1023) +
              ((v4 >> 50) & 1023) + ((v4 >> 60) & 1023);
        for (v65 = 0; v65 < 16; v65++) {
            v37 = (&lbl_1_bss_8F878.unk_0)[v65];
            v66 += v37;
            v66 += v37 & (((v65 + 1) * 6505) & 1023);
        }
        v66 += lbl_1_bss_8F878.unk_3D * 19;
        v66 += (v35 & 1023) + ((v35 >> 10) & 1023) +
               ((v35 >> 20) & 1023) + ((v35 >> 30) & 1023);
        for (v65 = 0; v65 < 29; v65 += 3) {
            v66 += 1 << ((v35 >> v65) & 7);
        }
        v35 += (u64)((s32)v66 & 1023) << 26;
        seed_rng(v35 & 255);
        v84 = next_rng();
        v0_2 = v35 + (((u64)v84 * 0xE90EDULL) & ~255ULL);
        DIGIT(unk_3F, 10000000000ULL);
        DIGIT(unk_43, 1000000000ULL);
        DIGIT(unk_46, 100000000ULL);
        lbl_1_bss_8F878.unk_42 = '-';
        DIGIT(unk_40, 10000000ULL);
        DIGIT(unk_44, 1000000ULL);
        DIGIT(unk_48, 100000ULL);
        DIGIT(unk_4A, 10000ULL);
        lbl_1_bss_8F878.unk_47 = '-';
        DIGIT(unk_41, 1000ULL);
        DIGIT(unk_45, 100ULL);
        DIGIT(unk_49, 10ULL);
        lbl_1_bss_8F878.unk_4B = v0_2 % 10 + '0';
        lbl_1_bss_8F878.unk_4C = 0;
    } else {
        v4 = lbl_1_bss_8F878.unk_10;
        v4 <<= 32;
        v4 |= lbl_1_bss_8F878.unk_14;
        v35 = lbl_1_bss_8F878.unk_34 + (lbl_1_bss_8F878.unk_39 << 18) + (lbl_1_bss_8F878.unk_3E << 24);
        v66 = (v4 & 1023) + ((v4 >> 10) & 1023) + ((v4 >> 20) & 1023) +
              ((v4 >> 30) & 1023) + ((v4 >> 40) & 1023) +
              ((v4 >> 50) & 1023) + ((v4 >> 60) & 1023);
        for (v65 = 0; v65 < 16; v65++) {
            v37 = (&lbl_1_bss_8F878.unk_0)[v65];
            v66 += v37;
            v66 += v37 & (((v65 + 1) * 6505) & 1023);
        }
        v66 += lbl_1_bss_8F878.unk_3D * 19;
        v66 += (v35 & 2047) + ((v35 >> 11) & 2047) +
               ((v35 >> 22) & 2047) + ((v35 >> 33) & 2047) +
               ((v35 >> 44) & 2047) + ((v35 >> 55) & 2047);
        for (v65 = 0; v65 < 29; v65 += 3) {
            v66 += 1 << ((v35 >> v65) & 7);
        }
        v35 += (u64)((s32)v66 & 2047) << 28;
        seed_rng(v35 & 255);
        v84 = next_rng();
        v0_2 = v35 + (((u64)v84 * 0xD1A94AULL) & ~255ULL);
        DIGIT(unk_3F, 100000000000ULL);
        DIGIT(unk_42, 10000000000ULL);
        DIGIT(unk_46, 1000000000ULL);
        DIGIT(unk_4A, 100000000ULL);
        lbl_1_bss_8F878.unk_43 = '-';
        DIGIT(unk_40, 10000000ULL);
        DIGIT(unk_44, 1000000ULL);
        DIGIT(unk_47, 100000ULL);
        DIGIT(unk_4B, 10000ULL);
        lbl_1_bss_8F878.unk_48 = '-';
        DIGIT(unk_41, 1000ULL);
        DIGIT(unk_45, 100ULL);
        DIGIT(unk_49, 10ULL);
        lbl_1_bss_8F878.unk_4C = v0_2 % 10 + '0';
        lbl_1_bss_8F878.unk_4D = 0;
    }
}
/* fzgx:end fn_1_159AE0 */

/* fzgx:begin fn_1_15AC00 */
// Return the address of the ranking state byte at offset 0x3f.
u8 *fn_1_15AC00(void) {
    return &lbl_1_bss_8F878.unk_3F;
}
/* fzgx:end fn_1_15AC00 */

/* fzgx:begin fn_1_15AC10 */
extern u32 fn_1_B7FC8(void);
extern u32 fn_8003D4C0(void);
extern u8 lbl_1_bss_718E0[23016];

static inline void set_seed(u32 value) {
    ((u32 *)&lbl_801A63C0)[0] = value;
}
static inline s32 next_random(void) {
    (&lbl_801A63C0)[0] = (&lbl_801A63C0)[0] * 0x676A4B6B + 0x33CB;
    return ((&lbl_801A63C0)[0] >> 16) & 0x7FFF;
}

static inline u64 make_value(void) {
    u32 t0 = fn_1_B7FC8();
    u8 v0 = lbl_1_bss_718E0[0x5523];
    u64 v1 = t0 & 0x3FFFFFFULL;
    v1 += (u64)(v0 & 0x3F) << 26;
    t0 = fn_8003D4C0();
    return (v1 << 32) + t0;
}

u64 fn_1_15AC10(void) {
    u64 v21;
    u64 v18;
    u64 v16;
    u64 v76;
    u32 v13;
    s32 v67, v69, v71;
    u8 *v82;
    u32 t0;
    u8 v0;
    v21 = make_value();
    v13 = ((u32)(((v21 >> 32) & 3) +
                      ((v21 & 0x2000ULL) >> 11) +
                      ((v21 & 0x100000ULL) >> 17)) & 0xFF) ^ 0xCAE87FB5;
    set_seed(v13);
    v16 = next_random();
    for (v18 = 0; v18 < 64; v18 += 1) {
        if (v18 != 13 && v18 != 20 && (v18 - 32) > 1) {
            u64 v29 = (v21 >> v18) & 1;
            u64 t4;
            v29 += (v16 % (v18 + 11)) & 1;
            t4 = 1ULL << v18;
            v21 &= ~t4;
            if (v29 & 1) {
                v21 |= t4;
            }
        }
    }
    lbl_1_bss_8F878.unk_18 = 0x30 + (v21 / 1ULL) % 10;
    lbl_1_bss_8F878.unk_19 = 0x30 + (v21 / 10ULL) % 10;
    lbl_1_bss_8F878.unk_1A = 0x30 + (v21 / 100ULL) % 10;
    lbl_1_bss_8F878.unk_1B = 0x30 + (v21 / 1000ULL) % 10;
    lbl_1_bss_8F878.unk_1C = 45;
    lbl_1_bss_8F878.unk_1D = 0x30 + (v21 / 10000ULL) % 10;
    lbl_1_bss_8F878.unk_1E = 0x30 + (v21 / 100000ULL) % 10;
    lbl_1_bss_8F878.unk_1F = 0x30 + (v21 / 1000000ULL) % 10;
    lbl_1_bss_8F878.unk_20 = 0x30 + (v21 / 10000000ULL) % 10;
    lbl_1_bss_8F878.unk_21 = 45;
    lbl_1_bss_8F878.unk_22 = 0x30 + (v21 / 100000000ULL) % 10;
    lbl_1_bss_8F878.unk_23 = 0x30 + (v21 / 1000000000ULL) % 10;
    lbl_1_bss_8F878.unk_24 = 0x30 + (v21 / 10000000000ULL) % 10;
    lbl_1_bss_8F878.unk_25 = 0x30 + (v21 / 100000000000ULL) % 10;
    lbl_1_bss_8F878.unk_26 = 45;
    lbl_1_bss_8F878.unk_27 = 0x30 + (v21 / 1000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_28 = 0x30 + (v21 / 10000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_29 = 0x30 + (v21 / 100000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_2A = 0x30 + (v21 / 1000000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_2B = 45;
    lbl_1_bss_8F878.unk_2C = 0x30 + (v21 / 10000000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_2D = 0x30 + (v21 / 100000000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_2E = 0x30 + (v21 / 1000000000000000000ULL) % 10;
    lbl_1_bss_8F878.unk_2F = 0x30 + (v21 / 10000000000000000000ULL) % 10;
    set_seed((u32)(v21 % 1000) ^ 0xCAE87FB5);
    v67 = next_random();
    v69 = next_random();
    v71 = next_random();
    v76 = (u64)v71 * ((u64)v69 * (u64)v67);
    for (v18 = 5; v18 < 24; v18 += 1) {
        v82 = &lbl_1_bss_8F878.unk_18 + v18;
        if (*v82 != 45) {
            *v82 += v76 % 10;
            if (*v82 > 57) {
                *v82 -= 10;
            }
            v76 /= 10;
        }
    }
    lbl_1_bss_8F878.unk_30 = 0;
    return v21;
}
/* fzgx:end fn_1_15AC10 */

/* fzgx:begin fn_1_15B3E8 */
// Return the current ranking state byte.
u8 fn_1_15B3E8(void) {
    return lbl_1_bss_8F878.unk_3A;
}
/* fzgx:end fn_1_15B3E8 */

/* fzgx:begin fn_1_15B3F8 */
// Return the ranking state byte at offset 0x3b.
u8 fn_1_15B3F8(void) {
    return lbl_1_bss_8F878.unk_3B;
}
/* fzgx:end fn_1_15B3F8 */

/* fzgx:begin fn_1_15B408 */
// Returns the current ranking state.
u8 fn_1_15B408(void) {
    return lbl_1_bss_8F878.unk_3C;
}
/* fzgx:end fn_1_15B408 */

/* fzgx:begin fn_1_15B418 */
u8 *fn_1_15B418(void) {
    return &lbl_1_bss_8F878.unk_18;
}
/* fzgx:end fn_1_15B418 */

/* fzgx:begin fn_1_15B428 */
// fn_1_15B428: empty in retail (single blr).
void fn_1_15B428(void) {
}
/* fzgx:end fn_1_15B428 */

/* fzgx:begin fn_1_15B42C */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} Fn_1_15B42C_Chunk;

void fn_1_15B42C(void) {
    Fn_1_15B42C_Chunk *src = (Fn_1_15B42C_Chunk *)lbl_1_rodata_DAF8;
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;
    Fn_1_15B42C_Chunk *dst = (Fn_1_15B42C_Chunk *)&obj->unk_4;

    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    obj->unk_5D = 0;
    obj->unk_5E = 0;
    obj->unk_5C = 0;
    fn_1_9A508();
    obj->unk_0 = -1;
}
/* fzgx:end fn_1_15B42C */

/* fzgx:begin fn_1_15B4F8 */
// fn_1_15B4F8: empty in retail (single blr).
void fn_1_15B4F8(void) {
}
/* fzgx:end fn_1_15B4F8 */

/* fzgx:begin fn_1_15B4FC */
void fn_1_15B4FC(void) {
    fn_1_9AD54();
}
/* fzgx:end fn_1_15B4FC */

/* fzgx:begin fn_1_15B51C */
// fn_1_15B51C: empty in retail (single blr).
void fn_1_15B51C(void) {
}
/* fzgx:end fn_1_15B51C */

/* fzgx:begin fn_1_15B520 */
void fn_1_15B520(void) {
    fn_1_9AD88();
}
/* fzgx:end fn_1_15B520 */

/* fzgx:begin fn_1_15B540 */
// fn_1_15B540: empty in retail (single blr).
void fn_1_15B540(void) {
}
/* fzgx:end fn_1_15B540 */

/* fzgx:begin fn_1_15B544 */
typedef struct {
    u32 flags;
    u8 pad_04[0x3c];
} fn_1_15B544_RankingEntry;

// Set the high flag on each ranking entry managed by the singleton.
void fn_1_15B544(void) {
    s16 i;
    fn_1_15B544_RankingEntry *entry;

    i = 0;
    entry = (fn_1_15B544_RankingEntry *)lbl_1_bss_3BE0->unk_54;
    while (i < (s32)lbl_1_bss_3BE0->unk_48) {
        entry->flags |= 0x80000000u;
        i++;
        entry = (fn_1_15B544_RankingEntry *)((u8 *)entry + 0x40);
    }
}
/* fzgx:end fn_1_15B544 */

/* fzgx:begin fn_1_15B588 */
// Clears the high bit of each ranking entry flag.
void fn_1_15B588(void) {
    u8 *entry;
    s16 i;
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    entry = (u8 *)obj;
    i = 0;
    while (i < obj->unk_5E) {
        u32 *value = *(u32 **)(entry + 0xc4);

        entry += 4;
        i++;
        *value &= 0x7fffffff;
    }
}
/* fzgx:end fn_1_15B588 */

/* fzgx:begin fn_1_15B5CC */
void fn_1_15B5CC(void) {
    u8 *entry;
    s16 i;
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    entry = (u8 *)obj;
    i = 0;
    while (i < obj->unk_5D) {
        u32 *value = *(u32 **)(entry + 0x74);

        entry += 4;
        i++;
        *value &= 0x7fffffff;
    }
}
/* fzgx:end fn_1_15B5CC */

/* fzgx:begin fn_1_15B610 */
void fn_1_15B610(void) {
    u8 *entry;
    s16 i;
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    entry = (u8 *)obj;
    i = 0;
    while (i < *((u8 *)obj + 0x5d)) {
        u32 *value = *(u32 **)(entry + 0x74);

        entry += 4;
        i++;
        *value |= 0x80000000u;
    }
}
/* fzgx:end fn_1_15B610 */

/* fzgx:begin fn_1_15B654 */
void fn_1_15B654(void) {
    u8 *entry;
    s16 i;
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    entry = (u8 *)obj;
    i = 0;
    while (i < obj->unk_5C) {
        u32 *value = *(u32 **)(entry + 0x60);

        entry += 4;
        i++;
        *value |= 0x80000000u;
    }
}
/* fzgx:end fn_1_15B654 */

/* fzgx:begin fn_1_15B698 */
u32 fn_1_15B698(s32 kind, u32 *value) {
    Obj_1_data_2A7E0_At3C *obj;

    obj = lbl_1_data_2A7E0.unk_3C;
    switch (kind) {
    case 3:
        obj->unk_114 = *value;
        break;
    case 1:
        obj->unk_120 = *value;
        break;
    case 2:
        obj->unk_124 = *value;
        break;
    case 4:
        obj->unk_118 = *value;
        break;
    case 0:
        obj->unk_11C = *value;
        break;
    default:
        break;
    }
    return 1;
}
/* fzgx:end fn_1_15B698 */
