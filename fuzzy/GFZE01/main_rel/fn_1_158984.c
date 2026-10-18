/* Non-matching: best partial attempt (99.77% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ranking.h"

struct RankingMotionVector { f32 x, y, z; };
struct RankingMotionObject {
    u32 flags;
    u8 pad_4[8];
    struct RankingMotionVector position;
    s16 angle_x, angle_y, angle_z;
};
struct RankingMotionRecord {
    s32 active;
    s32 cooldown;
    struct RankingMotionVector velocity;
    struct RankingMotionVector spin;
    u8 pad_20[0x18];
    struct RankingMotionObject *object;
};
struct RankingMotionManager {
    s32 count;
    s32 mode;
    s32 next;
    u32 grid[20][20][40];
    struct RankingMotionRecord records[400];
};
struct RankingMotionCamera { u8 pad_0[0x118]; u32 mode; };
struct RankingMotionScratch { u8 pad_0[0xD4]; struct RankingMotionVector vector; };
struct RankingMotionColor { u8 r, g, b, a; };
extern struct RankingMotionScratch *lbl_801A66CC;
extern u32 lbl_801A66A0;
extern void fn_1_9AD54(void);
extern s32 fn_1_58C4(void);
extern void fn_1_5948(s32);
extern void fn_1_627C(s32);
extern s16 camera_get_mode(void);
extern struct RankingMotionCamera *fn_1_8627C(s32 mode);
extern f32 lbl_8006D188(s32);
extern void fn_1_681C(s32, void *);
extern void fn_1_9A7A8(void *);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10.0f;
    s = 100.0f;
    s = 20.0f;
    s = 1000.0f;
    s = 2000.0f;
    s = 0.0f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
static const struct RankingMotionColor ranking_motion_color = {100, 100, 100, 0};
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65536.0f;
    s = 300.0f;
    s = 600.0f;
    s = 900.0f;
    s = 256.0f;
    s = 768.0f;
    s = 1280.0f;
    d = 0.01;
    s = 800.0f;
    s = 500.0f;
    s = 40000.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
#pragma section code_type ".text"


#pragma fp_contract off
static inline s32 damp_ranking_angle(s16 angle) {
    f64 change = 0.01 * -(s32)angle;
    return (s32)(angle + change);
}
#pragma fp_contract reset

/* Evaluate the lower boundary only after passing the upper boundary. */
#define RANKING_AXIS_CONTAINS(value, upper, center, half) \
    ((value) > (upper) ? 0 : ((value) < (center) - (half) ? 0 : 1))

static inline void exchange_ranking_overlaps(struct RankingMotionManager *manager,
        struct RankingMotionRecord *record, s32 index) {
    s32 overlap;
    struct RankingMotionRecord *other;
    s32 j;
            other = manager->records;
            overlap = 0;
            for (j = 0; j < manager->count; j++, other++) {
                if (index != j && record->cooldown == 0) {
                    struct RankingMotionObject *other_object = other->object;
                    struct RankingMotionObject *object = record->object;
                    f32 dx = object->position.x;
                    f32 dy = object->position.y - other_object->position.y;
                    f32 dz = object->position.z - other_object->position.z;
                    dx -= other_object->position.x;
                    dx *= dx;
                    dx += dy * dy;
                    dx += dz * dz;
                    if (dx <= 40000.0f) {
                        overlap = 1;
                        lbl_801A66CC->vector = record->velocity;
                        record->velocity = other->velocity;
                        other->velocity = lbl_801A66CC->vector;
                    }
                }
            }
            if (overlap) {
                record->active = 0;
                manager->records[manager->next].active = 1;
                manager->records[manager->next].cooldown = 60;
                manager->next++;
            }
}


void fn_1_158984(void) {
    struct RankingMotionManager *manager;
    struct RankingMotionRecord *record;
    struct RankingMotionCamera *camera;
    s32 count;
    s32 i;
    s32 camera_mode;
    struct RankingMotionColor color;

    manager = (struct RankingMotionManager *)lbl_1_data_2A7E0.unk_3C;
    fn_1_9AD54();
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        if ((camera_mode = camera_get_mode()) >= 0 && (camera = fn_1_8627C(camera_mode)) != 0) {
            manager->mode = camera->mode + 1;
            break;
        }
        fn_1_627C(i);
    }

    record = manager->records;
    for (i = 0; i < manager->count; i++, record++) {
        if (manager->mode == 2) {
            record->spin.x = lbl_8006D188((s32)(65536.0f * (lbl_801A66A0 % 300) / 300.0f));
            record->spin.y = lbl_8006D188((s32)(65536.0f * (lbl_801A66A0 % 600) / 600.0f));
            record->spin.z = lbl_8006D188((s32)(65536.0f * (lbl_801A66A0 % 900) / 900.0f));
            record->object->angle_x += (s32)(256.0f * record->spin.x);
            record->object->angle_y += (s32)(768.0f * record->spin.y);
            record->object->angle_z += (s32)(1280.0f * record->spin.z);
        } else {
            record->object->angle_x = damp_ranking_angle(record->object->angle_x);
            record->object->angle_y = damp_ranking_angle(record->object->angle_y);
            record->object->angle_z = damp_ranking_angle(record->object->angle_z);
        }
        record->object->flags &= 0xFEFFFFFF;
        if (record->active != 0 && (manager->mode == 1 || manager->mode >= 3)) {
            if (record->cooldown != 0) record->cooldown--;
            psvec_add(&record->object->position, &record->velocity, &record->object->position);
            fn_1_681C(0, &lbl_801A66CC->vector);

            /* Retail deliberately uses the X upper boundary for the Z containment test. */
            if (!(RANKING_AXIS_CONTAINS(record->object->position.x,
                        lbl_801A66CC->vector.x + 800.0f, lbl_801A66CC->vector.x, 800.0f) &&
                  RANKING_AXIS_CONTAINS(record->object->position.y,
                        lbl_801A66CC->vector.y + 500.0f, lbl_801A66CC->vector.y, 500.0f) &&
                  RANKING_AXIS_CONTAINS(record->object->position.z,
                        lbl_801A66CC->vector.x + 800.0f, lbl_801A66CC->vector.z, 800.0f))) {
                if (record->object->position.x > lbl_801A66CC->vector.x + 800.0f)
                    record->object->position.x = lbl_801A66CC->vector.x - 800.0f;
                else if (record->object->position.x < lbl_801A66CC->vector.x - 800.0f)
                    record->object->position.x = lbl_801A66CC->vector.x + 800.0f;
                if (record->object->position.y > lbl_801A66CC->vector.y + 500.0f)
                    record->object->position.y = lbl_801A66CC->vector.y - 500.0f;
                else if (record->object->position.y < lbl_801A66CC->vector.y - 500.0f)
                    record->object->position.y = lbl_801A66CC->vector.y + 500.0f;
                if (record->object->position.z > lbl_801A66CC->vector.z + 800.0f)
                    record->object->position.z = lbl_801A66CC->vector.z - 800.0f;
                else if (record->object->position.z < lbl_801A66CC->vector.z - 800.0f)
                    record->object->position.z = lbl_801A66CC->vector.z + 800.0f;
            }

            exchange_ranking_overlaps(manager, record, i);
        }
        if (manager->next >= manager->count) manager->next = 0;
    }
    color = ranking_motion_color;
    fn_1_9A7A8(&color);
}
