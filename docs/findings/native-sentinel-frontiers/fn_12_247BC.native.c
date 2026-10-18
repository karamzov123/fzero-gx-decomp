#include "types.h"

#pragma use_lmw_stmw on
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
#pragma opt_dead_assignments off

extern void *fn_12_3310C(const void *, u32);
extern int fn_12_32EAC(void *, s32 *);
extern void fn_12_330E0(void *);
extern int fn_12_24670(void *, void *, int);

int fn_12_247BC(void *self, int size, const u8 *data, int length, int *out) {
    int *result;
    void *movie;
    int packet_length;
    const u8 *header;
    void *context;
    s32 second;
    s32 first;
    u32 tag;
    u32 preceding_tag;
    s32 present;
    s32 packet_value;

    context = self;
    result = out;
    *out = 0;
    if (size != 2) return 0;
    header = data - 6;
    first = data[-6];
    second = header[1];
    packet_length = length + 6;
    tag = (first << 8) | second;
    tag = (tag << 8) | header[2];
    tag = (tag << 8) | header[3];
    if ((s32)tag != 0x1BF) {
        preceding_tag = (header[-2] << 8) | header[-1];
        packet_length += 2;
        header -= 2;
        preceding_tag = (preceding_tag << 8) | first;
        preceding_tag = (preceding_tag << 8) | second;
        if ((s32)preceding_tag != 0x1BF) return 0;
    }
    movie = fn_12_3310C(header - 12, packet_length + 12);
    if (movie == 0) {
        present = 0;
    } else {
        if (fn_12_32EAC(movie, &packet_value) == 0) packet_value = 0;
        fn_12_330E0(movie);
        present = packet_value;
    }
    if (present == 0) return 0;
    *result = fn_12_24670(context, (void *)(header - 12), packet_length + 12);
    return 1;
}
