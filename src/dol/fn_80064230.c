#include "types.h"

struct fn_80064230_T {
    u8 data[0x444];
    u32 unk_444;
};

extern struct fn_80064230_T *lbl_801A6C80;

static inline u8 * fn_80064230_read_pointer(struct fn_80064230_T * owner) { return owner->data; }
void fn_80064230(u32 id, u32 sel) {
    u8 *p;
    u32 k;

    if (lbl_801A6C80->unk_444 & 0x10) {
        u8 i = 0;

        while (i < 0x10) {
            k = i;

            p = lbl_801A6C80->data + (k << 4);

            if (*(u32 *)p + 0x10000 != 0xFFFF) {
                switch ((u16)sel) {
                case 0xA004: {
                    u8 v = (lbl_801A6C80->unk_444 >> 8) & 0x7F;

                    if ((u16)id == 4) {
                        p[0x492] = v;
                    } else if ((u16)id == 0xA005) {
                        p[0x494] = v;
                    } else if ((u16)id == 0xA010) {
                        p[0x493] = v;
                    } else if ((u16)id == 0xA011) {
                        p[0x495] = v;
                    }
                    break;
                }
                case 0xA034:
                    if ((u16)id == 0xA034) {
                        *(s16 *)(lbl_801A6C80->data + (k << 1) + 0x5A34) =
                            *(s16 *)(lbl_801A6C80->data + (k << 1) + 0x5AB4);
                    } else if (((0xA040) == ((u16)id))) {
                        *(s16 *)(fn_80064230_read_pointer(lbl_801A6C80) + (k << 1) + 0x5A54) =
                            *(s16 *)(lbl_801A6C80->data + (k << 1) + 0x5AD4);
                    }
                    break;
                }
            }
            i++;
        }
    } else {
        u8 n = lbl_801A6C80->unk_444 & 0xF;
        u8 *base = (u8 *)lbl_801A6C80;

        switch ((u16)sel) {
        case 0xA004: {
            u8 v = (lbl_801A6C80->unk_444 >> 8) & 0x7F;

            if ((u16)id == 4) {
                base[(n << 4) + 0x492] = v;
            } else if ((u16)id == 0xA005) {
                base[(n << 4) + 0x494] = v;
            } else if ((u16)id == 0xA010) {
                base[(n << 4) + 0x493] = v;
            } else if ((u16)id == 0xA011) {
                base[(n << 4) + 0x495] = v;
            }
            break;
        }
        case 0xA034:
            if ((u16)id == 0xA034) {
                *(s16 *)(base + (n << 1) + 0x5A34) =
                    *(s16 *)(base + (n << 1) + 0x5AB4);
            } else if (((0xA040) == ((u16)id))) {
                *(s16 *)(base + (n << 1) + 0x5A54) =
                    *(s16 *)(base + (n << 1) + 0x5AD4);
            }
            break;
        }
    }
}


