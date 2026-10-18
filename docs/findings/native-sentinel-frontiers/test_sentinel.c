/* Host-side semantic check of the landed sentinel unit, with fixed retail
 * integer widths. Build twice: once normally and once with -DBAD_SENTINEL. */
#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#define TYPES_H
typedef uint32_t u32;
typedef int32_t s32;
#include "../../../src/rel/movie_module/fn_12_2CD8C.c"

#ifdef BAD_SENTINEL
const u32 lbl_12_rodata_C78[102] = { [73] = 0 };
#else
const u32 lbl_12_rodata_C78[102] = { [73] = 0x5A5A5A5A };
#endif
static unsigned calls;
s32 fn_12_24A88(void *context, s32 error) {
    assert(context == 0);
    assert((u32)error == 0xFF000201);
    ++calls;
    return -1;
}
int main(void) {
    fn_12_2CD8C();
#ifdef BAD_SENTINEL
    assert(calls == 1);
    puts("PASS: bad sentinel reports the retail error exactly once");
#else
    assert(calls == 0);
    puts("PASS: intact sentinel reports no error");
#endif
    return 0;
}
