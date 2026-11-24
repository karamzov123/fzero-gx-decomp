#include "sasnd/sasnd.h"

extern void *fn_80020B3C(u32, s32 (*)(void *), u32);
extern void fn_80020ABC(void *);
extern void fn_80028424(void *);
extern void fn_8005C298(u32, u32);
extern void fn_8005C478(u32);
extern void fn_8005C5C8(u32);
extern void fn_8005C7C0(u32);
extern void fn_8005C9D8(u32);
extern void fn_8005DCEC(u16 *, u32);
extern void fn_8005FBDC(u32);
extern void fn_8005FCD8(u32);
extern void fn_80060BDC(u32);
extern void fn_8006331C(u8, u8);

void fn_80064A30(u16 event, u32 mask);
void fn_80064FDC(u8 channel, u8 *list);

s32 fn_80063EF4(u8 index, s8 positive, s8 negative) {
    s32 value;
    s32 factor;

    value = lbl_801A6C80->slot[index].unk_11 - 0x40;
    if (value > 0) {
        value++;
        factor = positive << 8;
    } else if (value < 0) {
        factor = negative << 8;
    }
    return (value * factor) >> 6;
}

static inline void SndSlotEvent(u16 event, u8 k, u8 channel, s8 delta) {
    s8 offset;
    u8 level;
    SndSplit *split;
    s16 sum;

    switch (event) {
    case 1:
    case 0x11:
        if ((s8)lbl_801A6C80->slot[k].unk_1 & 1) {
            break;
        }
        lbl_801A6C80->slot[k].unk_11 = 0x40;
        lbl_801A6C80->slot[k].unk_12 = 0;
        lbl_801A6C80->slot[k].unk_13 = 0;
        lbl_801A6C80->slot[k].unk_14 = 0;
        lbl_801A6C80->slot[k].unk_15 = 0;
        split = lbl_801A6C80->slot[k].split;
        lbl_801A6C80->slot[k].unk_8 = split->unk_B;
        lbl_801A6C80->slot[k].unk_E = split->unk_D;
        lbl_801A6C80->slot[k].unk_F = split->unk_E;
        break;
    case 0xA004:
        offset = 0;
        if ((s8)lbl_801A6C80->slot[k].unk_1 & 2) {
            level = (s8)lbl_801A6C80->mix[channel].unk_B;
            if (lbl_801A6C80->mix[channel].unk_D != 0x40) {
                offset = ((s8)lbl_801A6C80->mix[channel].unk_D - 0x40) * 2;
            }
        } else {
            level = (s8)lbl_801A6C80->mix[channel].unk_A;
            if (lbl_801A6C80->mix[channel].unk_C != 0x40) {
                offset = ((s8)lbl_801A6C80->mix[channel].unk_C - 0x40) * 2;
            }
        }
        sum = (s8)level + offset;
        if (sum < 0) {
            sum = 0;
        } else if (sum > 0x7F) {
            sum = 0x7F;
        }
        lbl_801A6C80->slot[k].unk_10 = sum;
        break;
    case 0xA007:
        if ((s8)lbl_801A6C80->slot[k].unk_1 & 1) {
            break;
        }
        lbl_801A6C80->slot[k].unk_E = lbl_801A6C80->slot[k].unk_D + delta;
        break;
    }
}

void fn_80063F38(u16 event, u8 channel) {
    u8 i;
    u8 j;
    s8 delta;
    struct { u8 value; } k;

    delta = ((s8)((lbl_801A6C80->command >> 8) & 0x7F) - 0x40);
    for (i = 0; i < 0x10; i++) {
        for (j = 0; j < 4; j++) {
            k.value = lbl_801A6C80->voiceMap[channel][i][j];
            if (k.value == 0xFF) {
                continue;
            }
            SndSlotEvent(event, k.value, channel, delta);
        }
    }
}

void fn_8006413C(u16 event) {
    u8 i;

    for (i = 0; i < 0x10; i++) {
        if (lbl_801A6C80->chan[i].unk_0 != 0xFFFFFFFF) {
            fn_80063F38(event, i);
        }
    }
}

void fn_800641A8(u16 event) {
    u32 command = lbl_801A6C80->command;

    if (command & 0x10) {
        u8 i = 0;

        while (i < 0x10) {
            if (lbl_801A6C80->chan[i].unk_0 != 0xFFFFFFFF) {
                fn_80063F38(event, i);
            }
            i++;
        }
    } else {
        fn_80063F38(event, command & 0xF);
    }
}

void fn_80064230(u16 id, u16 sel) {
    u32 k;

    if (lbl_801A6C80->command & 0x10) {
        u8 i = 0;

        while (i < 0x10) {
            k = i;

            if (lbl_801A6C80->chan[k].unk_0 != 0xFFFFFFFF) {
                switch (sel) {
                case 0xA004: {
                    u8 v = (lbl_801A6C80->command >> 8) & 0x7F;

                    if (id == 4) {
                        lbl_801A6C80->mix[k].unk_A = v;
                    } else if (id == 0xA005) {
                        lbl_801A6C80->mix[k].unk_C = v;
                    } else if (id == 0xA010) {
                        lbl_801A6C80->mix[k].unk_B = v;
                    } else if (id == 0xA011) {
                        lbl_801A6C80->mix[k].unk_D = v;
                    }
                    break;
                }
                case 0xA034:
                    if (id == 0xA034) {
                        lbl_801A6C80->unk_5A34[k] = lbl_801A6C80->unk_5AB4[k];
                    } else if (id == 0xA040) {
                        lbl_801A6C80->unk_5A54[k] = lbl_801A6C80->unk_5AD4[k];
                    }
                    break;
                }
            }
            i++;
        }
    } else {
        u8 n = lbl_801A6C80->command & 0xF;

        switch (sel) {
        case 0xA004: {
            u8 v = (lbl_801A6C80->command >> 8) & 0x7F;

            if (id == 4) {
                lbl_801A6C80->mix[n].unk_A = v;
            } else if (id == 0xA005) {
                lbl_801A6C80->mix[n].unk_C = v;
            } else if (id == 0xA010) {
                lbl_801A6C80->mix[n].unk_B = v;
            } else if (id == 0xA011) {
                lbl_801A6C80->mix[n].unk_D = v;
            }
            break;
        }
        case 0xA034:
            if (id == 0xA034) {
                lbl_801A6C80->unk_5A34[n] = lbl_801A6C80->unk_5AB4[n];
            } else if (id == 0xA040) {
                lbl_801A6C80->unk_5A54[n] = lbl_801A6C80->unk_5AD4[n];
            }
            break;
        }
    }
}

static inline u8 *SndSkipOffsets(u8 *base, u32 n) {
    u32 j;
    u8 *q = base;

    for (j = 0; j <= n; j++) {
        q += 2;
    }
    return base + *(u16 *)q;
}

void fn_800643F4(u16 cmd) {
    struct { s32 value; } c;
    struct { u32 value; } value2;
    u8 ch;
    u32 chOffset;
    u32 group;
    struct { u32 data; } value;
    u32 i;
    u32 slot;
    u32 flags;
    u8 lab_t1;
    s16 lab_t1_;

    c.value = cmd;
    flags = lbl_801A6C80->command;
    slot = flags & 0xF;
    group = (flags >> 24) & 0xF;
    value2.value = 0;
    value.data = (flags >> 8) & 0x7F;
    value2.value = (flags >> 16) & 0x7F;
    for (i = 0; i < 4; i++) {
        ch = lbl_801A6C80->voiceMap[slot][group][i];
        if ((s32)ch == 0xFF) {
            continue;
        }
        lbl_801A6C80->curChan = slot;
        switch (c.value) {
        case 0x9000: {
            chOffset = ((u8)ch) << 5;
            if ((*(u8 *)((u8 *)lbl_801A6C80 + chOffset + 0x589) & 0x80) && (*(u8 **)((u8 *)lbl_801A6C80 + chOffset + 0x5A4)) != NULL) {
                lab_t1 = ch;
                lab_t1_ = lab_t1;
                fn_8005DCEC(&(*(u16 **)((u8 *)lbl_801A6C80 + chOffset + 0x5A4))[4], lab_t1 | lab_t1_);
                lab_t1 = ch;
                fn_8005DCEC(&(*(u16 **)((u8 *)lbl_801A6C80 + chOffset + 0x5A4))[5], lab_t1);
                lab_t1 = ch;
                fn_8005DCEC(&(*(u16 **)((u8 *)lbl_801A6C80 + chOffset + 0x5A4))[6], lab_t1);
                lab_t1 = ch;
                fn_8005DCEC(&(*(u16 **)((u8 *)lbl_801A6C80 + chOffset + 0x5A4))[7], lab_t1);
            }
            break;
        }
        case 0xB000: {
            SndState *chan;
            struct { u8 *data; } hdr;

            chOffset = ((u8)ch) << 5;
            *(u8 *)((u8 *)lbl_801A6C80 + chOffset + 0x58C) = value.data;
            chan = (SndState *)((u8 *)lbl_801A6C80 + chOffset);
            hdr.data = (u8 *)lbl_801A6C80->chan[slot].bank;
            if (chan->slot[0].unk_1 & 2) {
                u32 off = *(u32 *)(hdr.data + 0x28);

                if (off != 0) {
                    chan->slot[0].seq = hdr.data + off;
                } else {
                    chan->slot[0].seq = NULL;
                }
            } else {
                u16 *p;
                u32 n;
                u8 *base;
                u32 j2;
                u16 v;

                n = chan->slot[0].unk_3[1];
                base = hdr.data + *(u32 *)(hdr.data + 0x1C);
                hdr.data = SndSkipOffsets(base, n);
                n = chan->slot[0].unk_3[2];

                p = (u16 *)hdr.data;
                for (j2 = 0; j2 <= n; j2++) {
                    p++;
                }
                v = *p;
                if (v != 0) {
                    chan->slot[0].seq = (u8 *)(v + (u32)hdr.data);
                } else {
                    chan->slot[0].seq = NULL;
                }
            }
            break;
        }
        case 0xB001:
            lbl_801A6C80->slot[ch].unk_13 = value.data;
            break;
        case 0xB002:
            lbl_801A6C80->slot[ch].unk_14 = value.data;
            break;
        case 0xB007:
            lbl_801A6C80->slot[ch].unk_7 = value.data;
            break;
        case 0xB00A:
            lbl_801A6C80->slot[ch].unk_8 = value.data;
            break;
        case 0xB00D:
            lbl_801A6C80->slot[ch].unk_B = value.data;
            break;
        case 0xB00E:
            lbl_801A6C80->slot[ch].unk_C = value.data;
            break;
        case 0xB040:
            if (value.data >= 0x40) {
                lbl_801A6C80->slot[ch].unk_12 = value.data;
            } else {
                lbl_801A6C80->slot[ch].unk_12 = 0;
            }
            break;
        case 0xC000:
            lbl_801A6C80->slot[ch].unk_3[2] = value2.value;
            break;
        case 0xE000:
            lbl_801A6C80->slot[ch].unk_11 = value.data;
            break;
        }
    }
}

void fn_800647B8(u16 event) {
    u32 mask;

    mask = ((lbl_801A6C80->command >> 4) & 1) ? 0 : 15;
    fn_80064A30(event, mask);
}

s32 fn_800647F0(u32 *object) {
    u8 i;

    i = 0;
    while (i < 0x40) {
        if (lbl_801A6C80->voice[i].unk_24 == object[5] && lbl_801A6C80->voice[i].state != 0xFF) {
            if (lbl_801A6C80->voice[i].state == 3) {
                fn_80060BDC(i);
            } else {
                fn_80028424(lbl_801A6C80->voice[i].env);
            }
            lbl_801A6C80->voice[i].obj = 0;
            lbl_801A6C80->voice[i].state = 0xFF;
            lbl_801A6C80->voice[i].time = 0;
            lbl_801A6C80->voice[i].active = 0;
            if (lbl_801A6C80->voice[i].link0 != 0xFF || lbl_801A6C80->voice[i].link1 != 0xFF) {
                if (lbl_801A6C80->voice[i].link0 == i) {
                    lbl_801A6C80->voice[lbl_801A6C80->voice[i].link1].link0 = 0xFF;
                    lbl_801A6C80->voice[lbl_801A6C80->voice[i].link1].link1 = 0xFF;
                } else if (lbl_801A6C80->voice[i].link1 == i) {
                    lbl_801A6C80->voice[lbl_801A6C80->voice[i].link0].link0 = 0xFF;
                    lbl_801A6C80->voice[lbl_801A6C80->voice[i].link0].link1 = 0xFF;
                }
            }
            lbl_801A6C80->voice[i].link0 = 0xFF;
            lbl_801A6C80->voice[i].link1 = 0xFF;
            break;
        }
        i++;
    }
    return 0;
}

s32 fn_8006496C(u32 priority) {
    s32 result_index;
    u8 i;
    void *result;

    result_index = -1;
    result = fn_80020B3C(priority & 0xFF, (s32 (*)(void *))fn_800647F0, lbl_801A6C80->unk_44C);
    if (result != 0) {
        for (i = 0; i < 0x40; i++) {
            if (lbl_801A6C80->voice[i].state == 0xFF) {
                result_index = i;
                lbl_801A6C80->voice[i].obj = result;
                lbl_801A6C80->voice[i].unk_24 = lbl_801A6C80->unk_44C;
                break;
            }
        }
    }
    lbl_801A6C80->unk_44C++;
    if (result != 0 && result_index == -1) {
        fn_80020ABC(result);
    }
    return result_index;
}

void fn_80064A30(u16 event, u32 mask) {
    u32 i;

    for (i = 0; i < 0x40; i++) {
        if (lbl_801A6C80->voice[i].state == 0xFF) {
            continue;
        }
        if (lbl_801A6C80->voice[i].state == 3) {
            continue;
        }
        if (lbl_801A6C80->voice[i].state == 4) {
            continue;
        }
        if ((lbl_801A6C80->command & mask) != (lbl_801A6C80->voice[i].time & mask)) {
            continue;
        }
        switch (event) {
        case 0x8000:
            if (lbl_801A6C80->voice[i].active != 1) {
                break;
            }
            if ((lbl_801A6C80->voice[i].flags & 8) == 8) {
                break;
            }
            if (lbl_801A6C80->voice[i].flags & 1) {
                lbl_801A6C80->voice[i].flags |= 2;
            } else {
                fn_8005FBDC(i);
            }
            break;
        case 0xA001:
        case 0xA004:
        case 0xA005:
        case 0xA010:
        case 0xA011:
        case 0xA034:
        case 0xA040:
            fn_8005C9D8(i);
            break;
        case 0xA002:
            if (lbl_801A6C80->voice[i].state == 1) {
                fn_8005FCD8(i);
            }
            break;
        case 0xA007:
            fn_8005C478(i);
            break;
        case 0xA01C:
            if (lbl_801A6C80->voice[i].state == 1) {
                fn_8005C9D8(i);
            }
            break;
        case 0xB001:
            fn_8005C298(i, 1);
            break;
        case 0xB002:
            fn_8005C298(i, 2);
            break;
        case 0xB007:
            fn_8005C9D8(i);
            break;
        case 0xB00A:
            if (lbl_801A6C80->voice[i].note->pan & 0x80) {
                fn_8005C7C0(i);
            }
            break;
        case 0xB00D:
            if (lbl_801A6C80->voice[i].note->unk_15 != 0) {
                fn_8005C5C8(i);
            }
            break;
        case 0xB040:
            lbl_801A6C80->voice[i].flags &= 0xFE;
            if (lbl_801A6C80->slot[lbl_801A6C80->voice[i].slot].unk_12 != 0) {
                lbl_801A6C80->voice[i].flags |= 1;
            } else if (lbl_801A6C80->voice[i].flags & 2) {
                fn_8005FBDC(i);
            }
            break;
        case 0xB078:
            if ((lbl_801A6C80->voice[i].time & 0xF000000) != (lbl_801A6C80->command & 0xF000000)) {
                break;
            }
            fn_8005FCD8(i);
            break;
        case 0xE000:
            fn_8005C478(i);
            break;
        }
    }
}

static inline void SndSlotClear(SndSlot *slot) {
    slot->unk_0 = 0;
    slot->unk_1 = 0;
    slot->split = 0;
    slot->seq = 0;
    slot->unk_2 = 0;
    slot->unk_11 = 0x40;
    slot->unk_12 = 0;
    slot->unk_13 = 0;
    slot->unk_14 = 0;
    slot->unk_15 = 0;
}

void fn_80064D4C(u8 channel, u8 kind) {
    u8 i;
    u8 j;
    u8 idx;
    u8 flag;

    for (i = 0; i < 0x10; i++) {
        for (j = 0; j < 4; j++) {
            idx = lbl_801A6C80->voiceMap[channel][i][j];
            if (idx == 0xFF) {
                continue;
            }
            flag = 0;
            if (lbl_801A6C80->slot[idx].unk_1 & 1) {
                if (kind == 0) {
                    flag = 1;
                }
            } else if (kind == 1) {
                flag = 1;
            }
            if (flag) {
                lbl_801A6C80->slot[idx].unk_0 = 0;
                lbl_801A6C80->slot[idx].unk_1 = 0;
                lbl_801A6C80->slot[idx].split = 0;
                lbl_801A6C80->slot[idx].seq = 0;
                lbl_801A6C80->slot[idx].unk_2 = 0;
                lbl_801A6C80->slot[idx].unk_11 = 0x40;
                lbl_801A6C80->slot[idx].unk_12 = 0;
                lbl_801A6C80->slot[idx].unk_13 = 0;
                lbl_801A6C80->slot[idx].unk_14 = 0;
                lbl_801A6C80->slot[idx].unk_15 = 0;
                lbl_801A6C80->voiceMap[channel][i][j] = 0xFF;
            }
        }
    }
}

static inline u8 *SndOffset(s32 offset, u8 *base) {
    u8 *result;

    result = (u8 *)offset;
    result = base + (s32)result;
    return result;
}

void fn_80064E84(u8 channel, u8 index) {
    u8 *a;
    u32 i;
    u16 v;

    a = (u8 *)lbl_801A6C80->chan[channel].bank;
    if (lbl_801A6C80->slot[index].unk_1 & 2) {
        if (*(u32 *)(a + 0x28) != 0) {
            lbl_801A6C80->slot[index].seq = a + *(u32 *)(a + 0x28);
        } else {
            lbl_801A6C80->slot[index].seq = 0;
        }
        return;
    }
    a += *(u32 *)(a + 0x1C);
    {
        u8 *b;

        b = a;
        for (i = 0; i <= lbl_801A6C80->slot[index].unk_3[1]; i++) {
            b += 2;
        }
        a = SndOffset(*(u16 *)b, a);
        b = a;
        for (i = 0; i <= lbl_801A6C80->slot[index].unk_3[2]; i++) {
            b += 2;
        }
        v = *(u16 *)b;
    }
    if (v != 0) {
        lbl_801A6C80->slot[index].seq = (u8 *)(v + (u32)a);
    } else {
        lbl_801A6C80->slot[index].seq = 0;
    }
}

void fn_80064FDC(u8 arg0, u8 *arg1) {
    s32 tmp_call9;
    u8 *v1;
    u32 v2;
    u8 *v3;
    u8 v4;
    u32 v7;
    u8 v6;
    struct { u32 value; } v25;
    u32 v8;
    u8 *v11;
    u32 v22;
    s8 adjustment;
    struct { u8 value; } volume;
    s32 v11_2;
    s16 v15;
    struct { u16 *value; } v24;
    u8 *v18;
    u32 v19;
    u8 v41;
    u8 *v23;
    u8 fzgx_loop_v4_658;
    u8 *v17;
    u8 v29;
    u16 *v31;
    struct { u8 *value; } v30;
    u32 v32;
    u16 v36;
    u8 v12;
    u32 v44;
    u32 v43;
    u8 count;
    u8 v5;
{
    u8 * fzgx_loop_v3_658;
    fzgx_loop_v3_658 = (u8 *)arg1 + 8;
    fzgx_loop_v4_658 = 0;
    count = arg1[0];
    v1 = (u8 *)(arg0 << 4);
    v2 = arg0 << 6;
    while (fzgx_loop_v4_658 <= count) {
        v5 = 255;
        if (((fzgx_loop_v3_658)[0]) & 0x80) {
            for (v6 = 0; v6 < 64; v6++) {
                if (*(u8 *)(((u32)lbl_801A6C80) + (v6 << 5) + 0x588) == 0) {
                    v5 = v6;
                    break;
                }
            }
            v7 = v6 << 5;
            v8 = v5 << 5;
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x588) = 1;
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x589) = ((fzgx_loop_v3_658)[0]);
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x58c) = ((fzgx_loop_v3_658)[2]);
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x58d) = ((fzgx_loop_v3_658)[3]);
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x58e) = ((fzgx_loop_v3_658)[10]);
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x58f) = ((fzgx_loop_v3_658)[9]);
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x590) = ((fzgx_loop_v3_658)[11]);
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x591) = ((fzgx_loop_v3_658)[12]);
            tmp_call9 = ((fzgx_loop_v3_658)[6]);
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x592) = tmp_call9;
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x593) = ((fzgx_loop_v3_658)[7]);
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x594) = ((fzgx_loop_v3_658)[8]);
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x595) = ((fzgx_loop_v3_658)[13]);
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x596) = ((fzgx_loop_v3_658)[13]);
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x597) = ((fzgx_loop_v3_658)[14]);
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x58b) = ((fzgx_loop_v3_658)[1]);
            *(u32 *)(((u32)lbl_801A6C80) + v7 + 0x5a0) = (u32)fzgx_loop_v3_658;
            adjustment = 0;
            if (*(u8 *)(((u32)lbl_801A6C80) + v8 + 0x589) & 2) {
                v11 = v1 + ((u32)lbl_801A6C80);
                v12 = *(v11 + 0x495);
                volume.value = *(v11 + 0x493);
                if (v12 != 64) adjustment = ((s8)v12 - 64) << 1;
            } else {
                v11 = v1 + ((u32)lbl_801A6C80);
                v12 = *(v11 + 0x494);
                volume.value = *(v11 + 0x492);
                if (v12 != 64) adjustment = ((s8)v12 - 64) << 1;
            }
            v15 = (s8)volume.value + adjustment;
            if (v15 < 0) v15 = 0;
            else if (v15 > 127) v15 = 127;
            *(u8 *)(((u32)lbl_801A6C80) + v7 + 0x598) = v15;
            v17 = (u8 *)(((u32)lbl_801A6C80) + v8);
            v18 = *(u8 **)(v1 + ((u32)lbl_801A6C80) + 8);
            if (((v17)[0x589]) & 2) {
                v19 = *(u32 *)(v18 + 40);
                if (v19 != 0) *(u8 **)(v17 + 0x5a4) = v18 + v19;
                else *(u8 **)(v17 + 0x5a4) = 0;
            } else {
                v22 = (*(v17 + 0x58c));
                v23 = v18 + *(u32 *)(v18 + 28);
                v24.value = (u16 *)v23;
                for (v25.value = 0; v25.value <= v22; v25.value++) v24.value++;
                v29 = ((v17)[0x58d]);
                v30.value = v23 + *v24.value;
                v31 = (u16 *)v30.value;
                for (v32 = 0; v32 <= v29; v32++) v31++;
                v36 = *v31;
                if (v36 != 0) *(u8 **)(v17 + 0x5a4) = (u8 *)(v36 + (u32)v30.value);
                else *(u8 **)(v17 + 0x5a4) = 0;
            }
        }
        if (v5 != 255) {
            v11_2 = ((u32)lbl_801A6C80);
            {
    u8 fzgx_loop_v41_3506;
for (fzgx_loop_v41_3506 = 0; fzgx_loop_v41_3506 < 4; fzgx_loop_v41_3506++) {
                v43 = fzgx_loop_v41_3506;
                v44 = ((fzgx_loop_v3_658)[1]) << 2;
                if (((u8 *)(v11_2 + v2))[v44 + v43 + 0xd88] & 1) {
                    *(u8 *)(v2 + v11_2 + v44 + v43 + 0xd88) = v5;
                    break;
                }
            }
    v41 = fzgx_loop_v41_3506;
}
        }
        fzgx_loop_v3_658 += 16;
        fzgx_loop_v4_658++;
    }
    v3 = fzgx_loop_v3_658;
    v4 = fzgx_loop_v4_658;
}
}

static inline void SndStopHeldVoices(u8 channel) {
    u8 i;
    u8 j;
    u8 k;
    u8 flag;

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 4; j++) {
            k = lbl_801A6C80->voiceMap[(u8)channel][i][j];
            if (k != 0xFF) {
                flag = 0;
                if (lbl_801A6C80->slot[k].unk_1 & 1) {
                    flag = 1;
                }
                if (flag) {
                    lbl_801A6C80->slot[k].unk_0 = 0;
                    lbl_801A6C80->slot[k].unk_1 = 0;
                    lbl_801A6C80->slot[k].split = 0;
                    lbl_801A6C80->slot[k].seq = 0;
                    lbl_801A6C80->slot[k].unk_2 = 0;
                    lbl_801A6C80->slot[k].unk_11 = 0x40;
                    lbl_801A6C80->slot[k].unk_12 = 0;
                    lbl_801A6C80->slot[k].unk_13 = 0;
                    lbl_801A6C80->slot[k].unk_14 = 0;
                    lbl_801A6C80->slot[k].unk_15 = 0;
                    lbl_801A6C80->voiceMap[(u8)channel][i][j] = 0xFF;
                }
            }
        }
    }
}

void fn_80065390(void) {
    u8 idx;
    u8 *bank;
    u8 *data;
    u8 *ptr;

    idx = lbl_801A6C80->command & 0xF;
    bank = (u8 *)lbl_801A6C80->chan[idx].bank;
    data = bank + *(u32 *)(bank + 0x18);
    if (*(u16 *)(bank + 0x3E) != 0) {
        SndStopHeldVoices(idx);
        lbl_801A6C80->mix[idx].unk_4 = (u32)(data + *(u16 *)(bank + 0x3E));
        ptr = (u8 *)lbl_801A6C80->mix[idx].unk_4;
        if (ptr[1] != 0x80) {
            lbl_801A6C80->mix[idx].unk_B = ptr[1];
        }
        fn_80064FDC(idx, ptr);
    } else {
        lbl_801A6C80->mix[idx].unk_4 = 0;
    }
}

static inline u8 SndSlotFree(u8 index) {
    u8 result;

    result = 0;
    if (!(lbl_801A6C80->slot[index].unk_1 & 1)) {
        result = 1;
    }
    return result;
}

static inline void SndSlotReset(u8 index) {
    lbl_801A6C80->slot[index].unk_2 = 0;
    lbl_801A6C80->slot[index].unk_11 = 0x40;
    lbl_801A6C80->slot[index].unk_12 = 0;
    lbl_801A6C80->slot[index].unk_13 = 0;
    lbl_801A6C80->slot[index].unk_14 = 0;
    lbl_801A6C80->slot[index].unk_15 = 0;
}

static inline void SndClearFreeSlots(u8 channel) {
    u8 i;
    u8 j;
    u8 index;

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 4; j++) {
            index = lbl_801A6C80->voiceMap[channel][i][j];
            if (index != 0xFF && SndSlotFree(index)) {
                lbl_801A6C80->slot[index].unk_0 = 0;
                lbl_801A6C80->slot[index].unk_1 = 0;
                lbl_801A6C80->slot[index].split = 0;
                lbl_801A6C80->slot[index].seq = 0;
                SndSlotReset(index);
                lbl_801A6C80->voiceMap[channel][i][j] = 0xFF;
            }
        }
    }
}

void fn_80065528(u32 force) {
    u8 i;
    u8 j;
    u32 slot;
    struct { SndState *p; } state;
    u8 *bank;
    u32 selected;
    u32 packed;
    u8 *command;
    u8 index;

    state.p = lbl_801A6C80;
    packed = state.p->command;
    slot = packed & 15;
    selected = (packed >> 8) & 255;
    bank = (u8 *)state.p->chan[slot].bank;
    if (bank && (selected != state.p->mix[slot].unk_8 || force)) {
        u8 *data;
        u8 n;
        u16 *table;

        table = (u16 *)(bank + 0x3C);
        data = bank + *(u32 *)(bank + 0x18);
        if (selected > ((*table >> 8) - 1)) {
            return;
        }
        n = 0;
        while (n <= selected + 1) {
            table++;
            n++;
        }
        if (!*table) {
            return;
        }
        command = (u8 *)(state.p->mix[slot].unk_0 = (u32)(data + *table));
        lbl_801A6C80->mix[slot].unk_8 = selected;
        if (command[1] != 0x80) {
            lbl_801A6C80->mix[slot].unk_A = command[1];
        }
        SndClearFreeSlots(slot);
        fn_80064FDC(slot, command);
        fn_8006331C(command[3], command[4]);
    } else if (bank) {
        for (i = 0; i < 16; i++) {
            for (j = 0; j < 4; j++) {
                index = lbl_801A6C80->voiceMap[slot][i][j];
                if (index != 0xFF) {
                    u8 active = 0;

                    if (!(lbl_801A6C80->slot[index].unk_1 & 1)) {
                        active = 1;
                    }
                    if (active) {
                        SndSlotReset(index);
                    }
                }
            }
        }
    }
}

void fn_800657F4(u8 channel) {
    u8 *bank = (u8 *)lbl_801A6C80->chan[channel].bank;
    u8 *data = bank + *(u32 *)(bank + 0x18);
    u16 entry;

    lbl_801A6C80->mix[channel].unk_8 = 0xFF;
    lbl_801A6C80->mix[channel].unk_9 = 0x7F;
    entry = *(u16 *)(bank + 0x3E);
    if (entry != 0) {
        u8 *list;

        lbl_801A6C80->mix[channel].unk_4 = (u32)(data + entry);
        list = (u8 *)lbl_801A6C80->mix[channel].unk_4;
        if (list[1] != 0x80) {
            lbl_801A6C80->mix[channel].unk_B = list[1];
        }
        fn_80064FDC(channel, list);
    } else {
        lbl_801A6C80->mix[channel].unk_4 = 0;
    }
}

void fn_80065890(s32 value) {
    lbl_801A6C80->unk_5B20 = value;
}

void fn_8006589C(void (*callback)(s32, u32)) {
    lbl_801A6C80->callback = callback;
}

void fn_800658A8(void (*callback)(u32, u32)) {
    lbl_801A6C80->unk_5B18 = callback;
}
