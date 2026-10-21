#include "types.h"

struct Movie {
    u8 pad0[0x48];
    int state;
    u8 pad4C[0x1AF4-0x4C];
    int stream;
    int field1AF8;
    int field1AFC;
    int field1B00;
};
struct Block { u32 address; int size; u32 unused; int extra; u32 reserved[4]; };
extern int fn_12_21D30(struct Movie *, int);
extern int fn_12_22390(struct Movie *, int, struct Block *);
extern int fn_12_26218(struct Movie *, u32, int, int *, int);
extern int fn_12_22008(struct Movie *, int, int);
extern void fn_12_252A0(struct Movie *);

static inline int get_block(struct Movie *movie, u32 *address, int *size, int *end) {
    struct Block block;
    int result = fn_12_22390(movie, movie->stream, &block);
    if (result != 0) return result;
    *size = block.size;
    *address = block.address;
    *end = *size + block.extra;
    return 0;
}
#pragma opt_propagation on
#pragma use_lmw_stmw on
static inline int process_blocks(struct Movie *arg0, int limit) {
    int size;
    u32 address;
    int total;
    int end;
    struct Movie *movie = arg0;
    int status;
    int consumed;
    struct Block block;
    status = 0;
    total = status;
    while (total < limit) {
        int result = get_block(movie, &address, &size, &end);
        status = result;
        if (status != 0) break;
        status = fn_12_26218(movie, address, size, &consumed, end);
        if (status != 0) break;
        if (consumed == 0) break;
        result = fn_12_22008(movie, movie->stream, consumed);
        status = 0;
        if (result != 0) status = result;
        if (status != 0) break;
        total += consumed;
    }
    if (movie->state == 2) fn_12_252A0(movie);
    return status;
}

int fn_12_26534(struct Movie *movie) {
    int a = fn_12_21D30(movie, movie->field1AFC);
    int b = fn_12_21D30(movie, movie->field1AF8);
    int c = fn_12_21D30(movie, movie->field1B00);
    if ((a & b & c) == 1) return 0;
    return process_blocks(movie, 0x7FFFFFFF);
}
