#include "types.h"


/* --- dol/__prep_buffer.c --- */
typedef struct PrepBuffer {
    u8 pad[0x18];
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    u32 field_24;
    u32 field_28;
    u32 field_2c;
    u32 field_30;
    u32 field_34;
} PrepBuffer;

void __prep_buffer(PrepBuffer* buffer) {
    buffer->field_24 = buffer->field_1c;
    buffer->field_28 = buffer->field_20;
    buffer->field_28 -= buffer->field_18 & buffer->field_2c;
    buffer->field_34 = buffer->field_18;
}

/* --- dol/__end_critical_region.c --- */
// __end_critical_region: empty in retail (single blr).
void __end_critical_region(void) {
}

/* --- dol/__begin_critical_region.c --- */
// __begin_critical_region: empty in retail (single blr).
void __begin_critical_region(void) {
}

/* --- dol/__kill_critical_regions.c --- */
// __kill_critical_regions: empty in retail (single blr).
void __kill_critical_regions(void) {
}
