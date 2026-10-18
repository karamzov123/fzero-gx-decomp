/* Host fixture checks the real table extent and native setup-call bindings. */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#define TYPES_H
typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;
#include "fn_80070100.native.c"

_Static_assert(sizeof(struct fn_800726C0_Entry) == 16, "attribute record extent");
_Static_assert(sizeof(BuiltinVertexFormats) == 432, "actual linked table ownership");
_Static_assert(offsetof(BuiltinVertexFormats, quantized) == 0xC0, "quantized offset");
_Static_assert(offsetof(BuiltinVertexFormats, position_texture) == 0x180, "short format offset");
BuiltinVertexFormats lbl_8015A860;
static unsigned phase;
void GXClearVtxDesc(void) { assert(phase == 0); ++phase; }
void fn_800723F8(void) { assert(phase == 1); ++phase; }
void fn_800726C0(u32 format, struct fn_800726C0_Entry *attributes) {
    assert(phase >= 2 && phase <= 4);
    if (phase == 2) {
        assert(format == 0 && attributes == lbl_8015A860.standard);
    } else if (phase == 3) {
        assert(format == 1 && attributes == lbl_8015A860.quantized);
    } else {
        assert(format == 7 && attributes == lbl_8015A860.position_texture);
    }
    ++phase;
}
int main(void) {
    fn_80070100();
    assert(phase == 5);
    puts("PASS: 432-byte owner, 12/12/3 entry layout, and ordered setup/format callbacks");
    return 0;
}
