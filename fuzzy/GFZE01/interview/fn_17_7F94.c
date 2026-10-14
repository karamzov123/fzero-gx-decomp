/* Non-matching: best partial attempt (83.95% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/camera.h"

extern f32 lbl_17_rodata_0[];

typedef struct { f32 x, y, z; } InterviewVec;
typedef struct {
    u32 word0;
    InterviewVec position;
    InterviewVec target;
    f32 fov;
    u16 mode;
} InterviewCamera;

#pragma opt_lifetimes off
static inline f32 *fn_17_7F94_array_read(f32 *array) { return array; }
#pragma opt_lifetimes reset

#pragma opt_common_subs off
void fn_17_7F94(void) {
    f32 fzgx_value;
    f32* rodata = (f32*)&lbl_17_rodata_0;
    InterviewCamera* camera = (InterviewCamera*)camera_get_state_object();
    InterviewVec position = *(InterviewVec*)&rodata[152];
    u32 lab_t1;
    fzgx_value = -fn_17_7F94_array_read(rodata)[158];
    position.z = fzgx_value;
    camera->position = position;
    camera->target = *(InterviewVec*)&rodata[155];
    camera->mode = 0;
    camera->fov = fn_17_7F94_array_read(rodata)[7];
    lab_t1 = fn_17_7F94_array_read(rodata)[159];
    camera_save_parameters(fn_17_7F94_array_read(rodata)[15]);
}
#pragma opt_common_subs reset

