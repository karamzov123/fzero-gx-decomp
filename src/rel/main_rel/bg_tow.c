#include "types.h"
#include "rel/main_rel/globals.h"
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} BgTowVec;

/* A stage object handed to the background (0x40 bytes). */
typedef struct {
    u32 flags;
    u32 unk_4;
    u32 unk_8;
    BgTowVec pos;
    s16 rotX;
    s16 rotY;
    s16 rotZ;
    s16 unk_1E;
    BgTowVec scale;
    u8 pad_2C[0x14];
} BgTowObj;

/* The search lights: the main object, the other parts and one camera setup per viewport. */
typedef struct {
    s32 otherCount;
    s32 camPointCount;
    BgTowObj *main;
    BgTowObj *others[16];
    s32 otherFlags[16];
    BgTowVec pos[4];
    BgTowVec dir[4];
    BgTowVec up[4];
    f32 viewMtx[4][12];
    BgTowVec target[4];
    BgTowVec offset[4];
    f32 camMtx[4][12];
    f32 camPointMtx[16][12];
} BgTowSearch;

/* The background work of the tower stage (lbl_1_data_2A7E0.unk_3C). */
typedef struct {
    s32 windowCount;
    BgTowObj *windows[64];
    s32 step[64];
    f32 timer[64];
    f32 level[64];
    f32 wait[64];
    f32 windowMtx[64][12];
    void *model;
    BgTowSearch search;
} BgTowWork;

extern void OSPanic(const char *file, int line, const char *msg, ...);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 lbl_801A63C0;
extern f32 *lbl_801A6D00;
extern void lbl_8006D784(void *mtx);
extern void lbl_8006D7DC(void *pos);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DB74(void *mtx);
extern void lbl_8006DD7C(void);
extern void lbl_8006DFC4(void *mtx);
extern void lbl_8006DFE8(void *mtx);
extern void lbl_8006E0A4(void *pos);
extern void lbl_8006E0C8(void *pos);
extern void lbl_8006E13C(void *scale);
extern f32 lbl_8006D0B4(f32 x);
extern void fn_80072558(void);
extern void fn_8006F1F0(BgTowVec *a, BgTowVec *b, BgTowVec *out);
extern void mathutil_mtxA_rotate_z(s16 angle);
extern void mathutil_mtxA_rotate_y(s16 angle);
extern void mathutil_mtxA_rotate_x(s16 angle);
extern s16 camera_get_mode(void);
extern int fn_1_58C4(void);
extern s32 fn_1_5910(void);
extern void fn_1_5948(int index);
extern void fn_1_627C(int index);
extern void fn_1_55210(void *model);
extern void fn_1_560F0(s32 index, void *mtx);
extern void fn_1_862D4(s16 mode, BgTowVec *out);
extern void fn_1_8636C(s16 mode, f32 *mtx);
extern void fn_1_869B0(s16 mode, BgTowVec *out);
extern void fn_1_9A508(void);
extern void fn_1_9AD54(void);
extern void fn_1_9AD88(void);
extern u32 fn_1_9BBE4(void *obj, u32 arg1, u32 arg2, void *mtx);
extern void fn_1_9D260(void);

void fn_1_153AF8(BgTowWork *work);
void fn_1_153B24(BgTowWork *work);
void fn_1_153C60(BgTowWork *work);
void fn_1_153D48(BgTowWork *work);
void fn_1_153D74(BgTowWork *work);
void fn_1_1540B0(BgTowWork *work);
void fn_1_154164(BgTowWork *work, const BgTowVec *offset, void *rotation, s32 all);

static inline f32 bg_tow_randf(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (f32)(s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f;
}

/* fzgx:begin fn_1_153988 */
// fn_1_153988: empty in retail (single blr).
void fn_1_153988(void) {
}
/* fzgx:end fn_1_153988 */

/* fzgx:begin fn_1_15398C */
// Prepares the shared background object and advances the background system.
void fn_1_15398C(void) {
    BgTowWork *work = (BgTowWork *)lbl_1_data_2A7E0.unk_3C;

    fn_1_153AF8(work);
    fn_1_153D48(work);
    fn_1_9A508();
}
/* fzgx:end fn_1_15398C */

/* fzgx:begin fn_1_1539D0 */
// Calls initialization, then loops calling two functions for each item
void fn_1_1539D0(void) {
    int count = fn_1_58C4();
    int i;

    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_627C(i);
    }
}
/* fzgx:end fn_1_1539D0 */

/* fzgx:begin fn_1_153A28 */
void fn_1_153A28(void) {
    BgTowWork *work;
    int count;
    int i;

    work = (BgTowWork *)lbl_1_data_2A7E0.unk_3C;
    fn_1_9D260();
    fn_1_9AD54();
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        fn_1_153D74(work);
        fn_1_627C(i);
    }
    fn_1_153B24(work);
}
/* fzgx:end fn_1_153A28 */

/* fzgx:begin fn_1_153AAC */
// fn_1_153AAC: empty in retail (single blr).
void fn_1_153AAC(void) {
}
/* fzgx:end fn_1_153AAC */

/* fzgx:begin fn_1_153AB0 */
// Initializes the background Aurora object.
void fn_1_153AB0(void) {
    BgTowWork *work = (BgTowWork *)lbl_1_data_2A7E0.unk_3C;

    fn_1_153C60(work);
    fn_1_1540B0(work);
    fn_1_9AD88();
}
/* fzgx:end fn_1_153AB0 */

/* fzgx:begin fn_1_153AF4 */
// fn_1_153AF4: empty in retail (single blr).
void fn_1_153AF4(void) {
}
/* fzgx:end fn_1_153AF4 */

/* fzgx:begin fn_1_153AF8 */
// Clears the first entry and any following entries selected by its count.
void fn_1_153AF8(BgTowWork *work) {
    int i;

    work->windowCount = 0;
    for (i = 0; i < work->windowCount; i++) {
        work->windows[i] = NULL;
    }
}
/* fzgx:end fn_1_153AF8 */

/* fzgx:begin fn_1_153B24 */
void fn_1_153B24(BgTowWork *work) {
    s32 i;

    for (i = 0; i < work->windowCount; i++) {
        work->timer[i] -= 0.15f;
        if (work->timer[i] <= -0.95f) {
            work->step[i]++;
            work->timer[i] = 0.031f;
        }

        work->level[i] = 0.005f + (f32)(-0.032f * work->step[i]);

        if (work->level[i] <= -0.923f) {
            work->timer[i] = -0.95f;
            work->level[i] = -0.923f;
            work->step[i] = (s32)((work->level[i] - 0.005f) / -0.032f);
        }

        if (work->level[i] == -0.923f) {
            work->wait[i] -= -0.032f;
            if (work->wait[i] > 1.0f) {
                work->wait[i] = 0.0f;
                work->timer[i] = 0.031f;
                work->level[i] = 0.005f;
                work->step[i] = (s32)((work->level[i] - 0.005f) / -0.032f);
            }
        }
    }
}
/* fzgx:end fn_1_153B24 */

/* fzgx:begin fn_1_153C60 */
void fn_1_153C60(BgTowWork *work) {
    s32 i;
    BgTowObj *obj;
    f32 mtx0[12];
    f32 mtx1[12];

    for (i = 0; i < work->windowCount; i++) {
        obj = work->windows[i];
        if (obj->unk_4 == 0xFFFFFFFF || (obj->unk_4 & lbl_1_data_2A7E0.unk_50) != 0) {
            lbl_8006DFE8(work->windowMtx[i]);
            lbl_8006E13C(&obj->scale);
            lbl_8006E0A4((u8 *)work->model + 8);
            fn_80072558();
            lbl_8006D784(mtx0);
            mtx0[3] = work->timer[i];
            mtx0[7] = work->level[i];
            fn_1_560F0(0, mtx0);
            lbl_8006D784(mtx1);
            mtx1[7] = work->wait[i];
            fn_1_560F0(1, mtx1);
            fn_1_55210(work->model);
        }
    }
}
/* fzgx:end fn_1_153C60 */

/* fzgx:begin fn_1_153D48 */
// Clears the Aurora background data region.
void fn_1_153D48(BgTowWork *work) {
    fn_80008BEC(&work->search, 0, sizeof(BgTowSearch));
}
/* fzgx:end fn_1_153D48 */

/* fzgx:begin fn_1_153D74 */
void fn_1_153D74(BgTowWork *work) {
    BgTowSearch *search = &work->search;
    int count;
    int i;
    s32 mode;
    BgTowVec v;
    BgTowVec d;
    f32 k3;
    f32 k2;
    f32 k1;
    f32 k4;
    f32 len;
    f32 s;
    f32 dx;
    f32 dy;
    f32 dz;

    if (search->main == NULL) {
        return;
    }
    count = fn_1_58C4();
    k1 = 200.0f;
    k2 = 50.0f;
    k3 = 0.1f;
    k4 = 5.0f;
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        mode = camera_get_mode();
        if (mode == -1) {
            v = (BgTowVec){0.0f, 0.0f, 0.0f};
            search->dir[i] = (BgTowVec){0.0f, 0.0f, 1.0f};
            search->up[i] = (BgTowVec){0.0f, 1.0f, 0.0f};
            search->offset[i] = (BgTowVec){0.0f, 0.0f, 1.0f};
            search->target[i] = (BgTowVec){0.0f, 0.0f, 0.0f};
            lbl_8006D784(search->viewMtx[i]);
            lbl_8006D784(search->camMtx[i]);
        } else {
            lbl_8006DAEC();
            fn_1_862D4(mode, &v);
            fn_1_8636C(mode, lbl_801A6D00);
            *(f32 *)(0xE0000000 + 0x0c) = 0.0f;
            *(f32 *)(0xE0000000 + 0x1c) = 0.0f;
            *(f32 *)(0xE0000000 + 0x2c) = 0.0f;
            search->dir[i].x = -lbl_801A6D00[2];
            search->dir[i].y = -lbl_801A6D00[6];
            search->dir[i].z = -lbl_801A6D00[10];
            search->up[i].x = lbl_801A6D00[1];
            search->up[i].y = lbl_801A6D00[5];
            search->up[i].z = lbl_801A6D00[9];
            lbl_8006DB74(search->viewMtx[i]);
            fn_1_869B0(mode, &search->offset[i]);
            fn_8006F1F0(&v, &search->up[i], &search->pos[i]);
            *(f32 *)(0xE0000000 + 0x0c) = 0.0f;
            *(f32 *)(0xE0000000 + 0x1c) = 0.0f;
            *(f32 *)(0xE0000000 + 0x2c) = 0.0f;
            lbl_8006DD7C();
            lbl_8006DB74(search->camMtx[i]);
            lbl_8006DB30();
        }
        search->target[i].x = v.x + (f32)(search->offset[i].x * k1) + (f32)(search->up[i].x * k2);
        search->target[i].y = v.y + (f32)(search->offset[i].y * k1) + (f32)(search->up[i].y * k2);
        search->target[i].z = v.z + (f32)(search->offset[i].z * k1) + (f32)(search->up[i].z * k2);
        dx = (search->target[i].x - search->pos[i].x) * k3;
        d.x = dx;
        dy = (search->target[i].y - search->pos[i].y) * k3;
        d.y = dy;
        dz = (search->target[i].z - search->pos[i].z) * k3;
        d.z = dz;
        len = dx * dx;
        len += dy * dy;
        len += dz * dz;
        len = lbl_8006D0B4(len);
        if (len > k4) {
            s = k4 / len;
            d.x = d.x * s;
            d.y = d.y * s;
            d.z = d.z * s;
        }
        psvec_add(&search->pos[i].x, &d.x, &search->pos[i].x);
    }
}
/* fzgx:end fn_1_153D74 */

/* fzgx:begin fn_1_1540B0 */
void fn_1_1540B0(BgTowWork *work) {
    s32 i;
    BgTowSearch *search;

    search = &work->search;
    {
        s32 slot;
        slot = fn_1_5910();
        fn_1_154164(work, &search->pos[slot], search->camMtx[slot], 0);
    }

    for (i = 0; i < search->camPointCount; i++) {
        BgTowVec zero = {0.0f, 0.0f, 0.0f};

        fn_1_154164(work, &zero, search->camPointMtx[i], 1);
    }
}
/* fzgx:end fn_1_1540B0 */

/* fzgx:begin fn_1_154164 */
void fn_1_154164(BgTowWork *work, const BgTowVec *offset, void *rotation, s32 all) {
    f32 *pos;
    BgTowObj *part;
    s32 i;
    BgTowSearch *list;
    f32 mtx[12];
    BgTowObj parts[17];

    list = &work->search;
    if (list->main == NULL) {
        return;
    }

    parts[0] = *list->main;
    parts[0].flags &= 0x7FFFFFFF;
    psvec_add(&parts[0].pos.x, offset, &parts[0].pos.x);
    lbl_8006D7DC(&parts[0].pos);
    lbl_8006DFC4(rotation);
    lbl_8006E13C(&parts[0].scale);
    lbl_8006DB74(mtx);
    fn_1_9BBE4(&parts[0], 0, 0, mtx);

    for (i = 0; i < list->otherCount; i++) {
        if (all == 0 && list->otherFlags[i] != 0) {
            continue;
        }
        part = &parts[i + 1];
        pos = &part->pos.x;
        parts[i + 1] = *list->others[i];
        parts[i + 1].flags &= 0x7FFFFFFF;
        psvec_add(pos, offset, pos);
        lbl_8006D7DC(&parts[0].pos);
        lbl_8006DFC4(rotation);
        lbl_8006E0C8(&parts[0].pos);
        lbl_8006E0A4(pos);
        mathutil_mtxA_rotate_z(parts[i + 1].rotZ);
        mathutil_mtxA_rotate_y(parts[i + 1].rotY);
        mathutil_mtxA_rotate_x(parts[i + 1].rotX);
        lbl_8006E13C(&part->scale);
        lbl_8006DB74(mtx);
        fn_1_9BBE4(part, 0, 0, mtx);
    }
}
/* fzgx:end fn_1_154164 */

/* fzgx:begin fn_1_1543E8 */
u32 fn_1_1543E8(s32 kind, void **source) {
    BgTowWork *work = (BgTowWork *)lbl_1_data_2A7E0.unk_3C;

    switch (kind) {
    case 0:
        work->model = *source;
        break;
    default:
        break;
    }

    return 1;
}
/* fzgx:end fn_1_1543E8 */

/* fzgx:begin fn_1_154410 */
s32 fn_1_154410(s32 kind, BgTowObj *obj) {
    BgTowWork *work = (BgTowWork *)lbl_1_data_2A7E0.unk_3C;
    BgTowSearch *search;

    switch (kind) {
    case 0:
        obj->flags |= 0x80000000;
        work->windows[work->windowCount] = obj;
        work->timer[work->windowCount] = -0.95f + (f32)(0.981f * bg_tow_randf());
        work->level[work->windowCount] = 0.005f + (f32)(-0.928f * bg_tow_randf());
        work->step[work->windowCount] = (s32)((work->level[work->windowCount] - 0.005f) / -0.032f);
        work->wait[work->windowCount] = 0.0f;
        lbl_8006D7DC(&obj->pos);
        mathutil_mtxA_rotate_z(obj->rotZ);
        mathutil_mtxA_rotate_y(obj->rotY);
        mathutil_mtxA_rotate_x(obj->rotX);
        lbl_8006DB74(work->windowMtx[work->windowCount]);
        work->windowCount++;
        if (work->windowCount >= 64) {
            OSPanic("bg_tow.c", 482, "WINDOW NUM OVER!");
        }
        break;
    case 1:
        obj->flags |= 0x80000000;
        work->search.main = obj;
        break;
    case 2:
    case 3:
    case 5:
        search = &work->search;
        obj->flags |= 0x80000000;
        search->others[search->otherCount] = obj;
        if (kind == 5) {
            search->otherFlags[search->otherCount] = 1;
        } else {
            search->otherFlags[search->otherCount] = 0;
        }
        search->otherCount++;
        if (search->otherCount >= 16) {
            OSPanic("bg_tow.c", 510, "BG_TOW_SEARCH OTHER NUM OVER\n");
        }
        break;
    case 4:
        search = &work->search;
        lbl_8006D7DC(&obj->pos);
        mathutil_mtxA_rotate_z(obj->rotZ);
        mathutil_mtxA_rotate_y(obj->rotY);
        mathutil_mtxA_rotate_x(obj->rotX);
        lbl_8006DB74(search->camPointMtx[search->camPointCount]);
        search->camPointCount++;
        if (search->camPointCount >= 16) {
            OSPanic("bg_tow.c", 527, "BG_TOW_SCAMPOINT01 NUM OVER!");
        }
        break;
    default:
        break;
    }
    return 1;
}
/* fzgx:end fn_1_154410 */

