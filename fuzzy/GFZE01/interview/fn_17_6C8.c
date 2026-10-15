/* Non-matching: best partial attempt (89.66% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct InterviewCamera {
    u32 unk_0;
    Vec3 pos;
    Vec3 target;
    f32 fov;
    s16 roll;
} InterviewCamera;

typedef struct InterviewShot {
    s16 kind;
    Vec3 pos;
    Vec3 target;
    s16 mode;
} InterviewShot;

typedef struct InterviewView {
    f32 fov;
    u8 pad_4[0x1C];
    s16 roll;
    InterviewShot shot;
} InterviewView;

typedef struct InterviewRig {
    u8 pad_0[0x18];
    InterviewView view;
} InterviewRig;

typedef struct InterviewActor {
    u8 pad_0[0xA8];
    f32 x;
    f32 y;
    f32 z;
} InterviewActor;

typedef struct InterviewControl {
    u8 pad_0[0x10];
    u8 *unk_10;
    u8 pad_14[0x4];
    void *unk_18;
    u32 unk_1C;
    u32 unk_20;
    u8 pad_24[0x34];
    u32 flags;
    u16 phase;
    u8 pad_5E[0x2];
    InterviewRig rig;
    u8 pad_BC[0x18];
    s16 unk_D4;
    s16 unk_D6;
    InterviewActor *actors[2];
    u8 pad_E0[0x18];
    u8 unk_F8;
} InterviewControl;

typedef struct InterviewShots {
    u8 pad_0[0xB0];
    InterviewCamera opening;
} InterviewShots;

typedef struct InterviewShotsB {
    u8 pad_0[0x80];
    InterviewCamera closing;
} InterviewShotsB;

typedef struct InterviewTable {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x1C];
    u32 unk_30;
} InterviewTable;

typedef struct InterviewMode {
    u8 pad_0[0xE2];
    u8 unk_E2;
} InterviewMode;

typedef struct InterviewLights {
    void **lights;
} InterviewLights;

extern InterviewControl lbl_17_bss_0;
extern InterviewShots lbl_17_data_63BD0;
extern InterviewShotsB lbl_17_data_63D20;
extern InterviewTable lbl_17_data_63058;
extern InterviewMode lbl_1_bss_5138;
extern const f32 lbl_17_rodata_18;
extern s16 lbl_1_bss_968;
extern s16 lbl_1_bss_96A;
extern u32 lbl_1_bss_6EAB4;
extern InterviewLights lbl_1_bss_6EAD0;

extern void fn_1_9724C(InterviewActor *);
extern void fn_17_71C0(InterviewRig *);
extern void fn_17_3F0(void);
extern InterviewCamera *camera_get_state_object(void);
extern void fn_8004BF0C(void *, s16);
extern void fn_1_4A00(s32, s32, void *);

void fn_17_6C8(void) {
    InterviewControl *state = &lbl_17_bss_0;
    InterviewCamera shot;
    InterviewRig *rig;
    InterviewView *view;
    InterviewCamera *camera;
    InterviewActor *actor;

    if (state->flags & 0x200000) {
        lbl_1_bss_968 = 10;
    } else if ((state->flags & 1) &&
               (state->phase < 4 || (state->phase > 5 && state->phase < 12))) {
        if (state->phase < 4) {
            rig = &state->rig;
            shot = lbl_17_data_63BD0.opening;
            rig->view.shot.mode = 2;
            view = &rig->view;
            state->phase = 4;
            state->unk_1C = lbl_17_data_63058.unk_10;
            state->unk_D4 = -95;
            state->unk_D6 = -20;
            fn_1_9724C(state->actors[0]);
            fn_1_9724C(state->actors[1]);
        } else {
            rig = &state->rig;
            shot = lbl_17_data_63D20.closing;
            rig->view.roll = shot.roll;
            state->phase = 12;
            state->unk_20 = lbl_17_data_63058.unk_30;
            rig->view.shot.mode = 1;
            rig->view.shot.kind = 0;
            rig->view.shot.pos = shot.pos;
            rig->view.shot.target = shot.target;
            rig->view.fov = shot.fov;
            rig->view.roll = shot.roll;
            view = &rig->view;
            state->unk_D4 = -999;
            state->unk_D6 = -999;
            fn_17_71C0(rig);
            fn_1_9724C(state->actors[0]);
            fn_1_9724C(state->actors[1]);
        }
        camera = camera_get_state_object();
        camera->pos = shot.pos;
        camera->target = shot.target;
        camera->roll = shot.roll;
        camera->fov = shot.fov;
        if ((state->flags & 1) && state->phase < 5 && view->shot.mode >= 2) {
            actor = state->actors[1];
            camera->pos.x = actor->x;
            camera->pos.z = actor->z - lbl_17_rodata_18;
            camera->target.x = actor->x;
        }
        lbl_1_bss_6EAB4 &= ~0x2C;
        fn_8004BF0C(lbl_1_bss_6EAD0.lights[0], state->unk_D4);
        fn_8004BF0C(lbl_1_bss_6EAD0.lights[1], state->unk_D6);
        fn_1_4A00(1, 30, state->unk_18);
    } else if (!(state->flags & 0x20000000)) {
        if (state->unk_F8 == 3) {
            fn_17_3F0();
        } else if (lbl_1_bss_5138.unk_E2 == 0) {
            lbl_1_bss_968 = state->unk_10[0x190];
        }
    } else {
        lbl_1_bss_96A = 197;
    }
}
