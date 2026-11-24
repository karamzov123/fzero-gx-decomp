#include "types.h"
#include "sofdec/sj.h"

typedef struct AhxPlayer {
    u32 decoder;
    u8 used;
    s8 state;
    u8 channels;
    s8 flushing;
    u32 bitstream;
    SJ *input;
    SJ *output[2];
    u32 unk_18;
    u32 decoded;
    u32 consumed;
    u32 total;
    s32 max;
    s32 limit;
    s32 since_callback;
    u32 unk_34;
    u32 index;
    void (*callback)(u32);
    u32 callback_arg;
    u32 unk_44;
    u32 unk_48;
    u32 work;
} AhxPlayer;

extern s32 lbl_801873D8;
extern u32 lbl_801873DC[4];
extern AhxPlayer *lbl_801873EC[16];

extern void *memset(void *, int, u32);
extern s32 fn_80050180(u32);
extern u32 fn_800501EC(u32);
extern void fn_800504BC(u32);
extern u32 fn_800504EC(SJ *);
extern int fn_80050F64(u32);
extern int fn_80050F6C(u32);
extern s32 fn_80050F74(u32);
extern s32 fn_80050F90(u32, u32, u32, s32);
extern s32 fn_800510C4(u32);
extern s32 fn_800510D8(u32);
extern u32 fn_80051448(u32);
extern u32 fn_80051594(u32, u32);
extern u32 fn_80051678(u32);
extern void fn_8005174C(u32);
extern u32 fn_800517C0(u32 *, u32);
extern u32 fn_8005190C(void);
extern u32 fn_80051958(const char *);
extern int fn_80053A30(void);
extern u32 fn_800589BC(u32, u32, SJCK *, SJCK *);

void fn_80053F38(AhxPlayer *player);

u32 fn_80053EA0(AhxPlayer *player) {
    return player->decoded;
}

u32 fn_80053EA8(AhxPlayer *player) {
    return player->consumed;
}

void fn_80053EB0(AhxPlayer *player) {
    if (player->state == 2) {
        fn_80053F38(player);
    } else if (player->state == 1) {
        SJ *input = player->input;

        if (input->interface->get_num_data(input, 1) >= 36) {
            fn_80051448(player->decoder);
            fn_800510D8(player->decoder);
            player->flushing = 1;
            player->state = 2;
        }
    }
}

void fn_80053F38(AhxPlayer *player) {
    SJCK items[2];
    SJCK temps[2];
    s32 total_2;
    struct { s32 value; } count;
    u32 stream;
    SJ **list;
    s32 size;
    s32 n;
    u32 second;
    SJ *obj;
    SJ *obj2;
    s32 i;
    struct { s32 value; } j;
    s32 total;
    u32 lo;
    s32 t;
    s32 lim;

    second = 0;
    list = player->output;
    stream = player->decoder;
    obj2 = player->input;
    if (player->flushing == 1) {
        t = obj2->interface->get_num_data(obj2, 1);
        if (!t) {
            t = fn_80050180(player->bitstream);
            if (t == 1) {
                player->state = 3;
                return;
            }
        }
    }
    count.value = fn_80050F64(player->decoder);
    size = fn_80050F6C(player->decoder) / 8;
    obj = player->output[0];
    t = obj->interface->get_num_data(obj, 0);
    if (t / size < count.value) {
        return;
    }
    if (fn_800510C4(stream) != 0) {
        lbl_801873DC[2] = fn_80053A30();
        t = fn_800510D8(stream);
        if (t == 1) {
            player->state = 3;
            return;
        }
        lbl_801873DC[3] = fn_80053A30();
    }
    n = fn_80050F74(player->decoder);
    memset(items, 0, 0x10);
    total = count.value * size;
    for (i = 0; i < n; i++) {
        list[i]->interface->get_chunk(list[i], 0, total, &items[i]);
    }
    lo = (u32)items[0].data;
    if (n == 2) {
        second = (u32)items[1].data;
    }
    if ((s32)((u32)items[0].len >> 1) != count.value) {
        while (1) {
        }
    }
    lbl_801873DC[0] = fn_80053A30();
    count.value = fn_80050F90(stream, lo, second, count.value);
    lbl_801873DC[1] = fn_80053A30();
    total = count.value * size;
    for (j.value = 0; j.value < n; j.value++) {
        fn_800589BC((u32)&items[j.value], total, &items[j.value], &temps[j.value]);
        list[j.value]->interface->put_chunk(list[j.value], 1, &items[j.value]);
        list[j.value]->interface->unget_chunk(list[j.value], 0, &temps[j.value]);
    }
    player->decoded += count.value;
    player->consumed = ((s32)fn_800501EC(player->bitstream) + 7) / 8;
    player->total += count.value;
    player->since_callback += count.value;
    total_2 = player->limit;
    lim = total_2;
    if (lim < 0) {
        return;
    }
    if (player->since_callback < lim) {
        return;
    }
    if (player->callback == 0) {
        return;
    }
    player->callback(player->callback_arg);
}

void fn_800541EC(AhxPlayer *player) {
    fn_80051678(player->decoder);
    player->state = 0;
}

void fn_80054224(AhxPlayer *player) {
    u32 bitstream;

    player->unk_18 = 0;
    player->decoded = 0;
    player->consumed = 0;
    player->total = 0;
    player->max = 0x7FFFFFFF;
    player->limit = -1;
    player->since_callback = 0;
    player->unk_34 = 0;
    player->flushing = 0;
    bitstream = player->bitstream;
    if (bitstream != 0) {
        player->bitstream = 0;
        fn_800504BC(bitstream);
    }
    player->bitstream = fn_800504EC(player->input);
    fn_80051594(player->decoder, player->bitstream);
    player->state = 1;
}

void fn_800542B4(AhxPlayer *player, SJ *input) {
    player->input = input;
}

int fn_800542BC(AhxPlayer *player) {
    return player->state;
}

void fn_800542C8(AhxPlayer *player) {
    u32 index;
    u32 value;

    if (player != 0) {
        value = player->bitstream;
        index = player->index;
        if (value != 0) {
            player->bitstream = 0;
            fn_800504BC(value);
        }
        value = player->decoder;
        if (value != 0) {
            player->decoder = 0;
            fn_8005174C(value);
        }
        memset(player, 0, 0x4C);
        lbl_801873EC[index] = 0;
    }
}

AhxPlayer *fn_80054354(SJ *input, s32 channels, SJ **output, AhxPlayer *work, u32 size) {
    s32 index;
    AhxPlayer *player;
    s32 i;

    for (index = 0; index < 16; index++) {
        if (lbl_801873EC[index] == 0) {
            break;
        }
    }
    if (index == 16) {
        return 0;
    }

    memset(work, 0, size);
    {
        AhxPlayer **table = lbl_801873EC;

        table[index] = work;
        player = table[index];
    }
    player->index = index;
    player->bitstream = fn_800504EC(input);
    if (player->bitstream == 0) {
        return 0;
    }
    player->decoder = fn_800517C0(&player->work, 0x2BCC);
    if (player->decoder == 0) {
        return 0;
    }

    player->channels = channels;
    player->input = input;
    for (i = 0; i < channels; i++) {
        player->output[i] = output[i];
    }
    player->state = 0;
    player->unk_18 = 0;
    player->decoded = 0;
    player->consumed = 0;
    player->total = 0;
    player->max = 0x7FFFFFFF;
    player->limit = -1;
    player->since_callback = 0;
    player->unk_34 = 0;
    player->flushing = 0;
    player->callback = 0;
    player->callback_arg = 0;
    player->unk_44 = 0;
    player->unk_48 = 0;
    player->used = 1;
    return player;
}

s32 fn_800545B0(void) {
    if (lbl_801873D8 == 1) {
        memset(lbl_801873EC, 0, sizeof(lbl_801873EC));
        fn_8005190C();
    }
    return lbl_801873D8--;
}

const char *const lbl_80091388 = "\nAHX/GC Ver.1.24 Build:May  9 2003 17:10:03\n";

s32 fn_80054608(void) {
    const char *version = lbl_80091388;

    if (lbl_801873D8 == 0) {
        fn_80051958(version);
        memset(lbl_801873EC, 0, sizeof(lbl_801873EC));
    }
    return lbl_801873D8++;
}
