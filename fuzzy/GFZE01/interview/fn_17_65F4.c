/* Non-matching: best partial attempt (74.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/interview/interview.h"

typedef struct InterviewVector {
    f32 x, y, z;
} InterviewVector;
typedef struct InterviewLimit {
    u8 pad[6];
    s16 limit;
} InterviewLimit;
typedef struct InterviewSequence {
    s32 frame;
    u8 pad4[8];
    s16 mode;
    u8 padE[6];
    InterviewLimit *limit;
} InterviewSequence;
typedef struct InterviewObject {
    u8 pad[0xA0];
    s16 rotation;
    u8 padA2[6];
    InterviewVector position;
} InterviewObject;
typedef struct InterviewWork {
    u8 pad[0x2C];
    f32 scale;
    u8 pad30[0x30];
    InterviewSequence sequence;
    u8 pad78[0x60];
    InterviewObject *object;
} InterviewWork;

extern f32 lbl_17_rodata_0[6];
#pragma opt_propagation off
void fn_17_65F4(void) {
    InterviewWork *work = (InterviewWork *)&lbl_17_bss_0;
    InterviewSequence *sequence = &work->sequence;
    f32 *pool = lbl_17_rodata_0;
    InterviewLimit *limit = sequence->limit;
    InterviewVector position;
    if (sequence->mode == 11) {
        work->scale = pool[0x24C / 4];
        if (sequence->frame >= limit->limit) {
            position.x = pool[0x258 / 4];
            position.y = pool[0x254 / 4];
            position.z = pool[0x250 / 4];
            work->object->position = position;
            work->object->rotation = 0x3000;
        }
    } else {
        position.x = position.y = position.z = pool[0x20 / 4];
        work->scale = pool[0x18 / 4];
        work->object->position = position;
        work->object->rotation = 0;
    }
}
