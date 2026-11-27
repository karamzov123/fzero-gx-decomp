#include "types.h"
#include "dolphin/types.h"

/* View frustum (retail TU between ord_tbl.c and objput.c; SMB1 has the same functions in its frustum.c).
 * fn_1_549F4 builds the four side planes of the view frustum from the camera; fn_1_54E34 and fn_1_54F5C
 * test a sphere against them. */

typedef struct {
    f32 x, y, z;
} FrustumVec;

typedef struct {
    s16 x, y, z;
} FrustumAngles;

/* The frustum state (0x84 bytes, saved and restored as a whole by fn_1_54DCC/fn_1_54E00 and objput.c). */
typedef struct {
    FrustumVec eye;
    FrustumVec worldNormals[4];
    FrustumVec viewNormals[4];
    FrustumAngles rot;
    f32 fov;
    f32 aspect;
    f32 offsetY;
    f32 offsetX;
} Frustum;

/* The game's shared work block; only the fields this TU uses are named. */
typedef struct FrustumWork {
    u8 unk_0[0x50];
    Frustum frustum;
    FrustumVec viewPoint;
} FrustumWork;

extern FrustumWork *lbl_801A66CC;
extern f32 lbl_8006D21C(s32 angle);
extern s16 lbl_8006D2AC(f32 x);
extern void lbl_8006D7DC(FrustumVec *pos);
extern void mathutil_mtxA_rotate_x(s32 angle);
extern void mathutil_mtxA_rotate_y(s32 angle);
extern void mathutil_mtxA_rotate_z(s32 angle);
extern void lbl_8006D1B8(s16 angle, f32 *sincos);
extern void lbl_8006E1C0(FrustumVec *src, FrustumVec *dst);
extern void lbl_8006E1B0(FrustumVec *src, FrustumVec *dst);
extern void fn_800794F0(void *dst, void *src, u32 size);

/* The frustum saved by fn_1_550A8. */
Frustum lbl_1_bss_6C710;

/* fzgx:begin fn_1_549F4 */
/* Sets the camera position, rotation and field of view and computes the frustum's side planes
 * (SMB1 func_80020AB8). */
void fn_1_549F4(FrustumVec *pos, FrustumAngles *rot, f32 fov, f32 aspect, f32 offsetY, f32 offsetX) {
    f32 tanHalf;
    s16 left, right, top, bottom;
    f32 sincos[2];

    lbl_801A66CC->frustum.eye = *pos;
    lbl_801A66CC->frustum.rot = *rot;
    lbl_801A66CC->frustum.fov = fov;
    lbl_801A66CC->frustum.aspect = aspect;
    lbl_801A66CC->frustum.offsetY = offsetY;
    lbl_801A66CC->frustum.offsetX = offsetX;

    if (0.0f == offsetX) {
        s32 t = (s16)(182.044449f * fov);
        left = -t / 2;
        right = t / 2;
    } else {
        tanHalf = lbl_8006D21C(182.044449f * (0.5f * fov));
        left = -lbl_8006D2AC(tanHalf * (1.0 - offsetX));
        right = lbl_8006D2AC(tanHalf * (1.0 + offsetX));
    }

    if (0.0f == offsetY) {
        s16 x = lbl_8006D2AC(aspect * lbl_8006D21C(182.04444885253906 * (0.5 * fov)));
        s32 t = (s16)(x * 2);
        top = t / 2;
        bottom = -t / 2;
    } else {
        f32 s;
        if (0.0f == offsetX) {
            s = aspect * lbl_8006D21C(182.044449f * (0.5f * fov));
        } else {
            s = tanHalf * aspect;
        }
        top = lbl_8006D2AC(s * (1.0 + offsetY));
        bottom = -lbl_8006D2AC(s * (1.0 - offsetY));
    }

    lbl_8006D7DC(pos);
    mathutil_mtxA_rotate_y(rot->y);
    mathutil_mtxA_rotate_x(rot->x);
    mathutil_mtxA_rotate_z(rot->z);

    lbl_8006D1B8(top - 0x4000, sincos);
    lbl_801A66CC->frustum.viewNormals[0].x = -sincos[0];
    lbl_801A66CC->frustum.viewNormals[0].y = 0.0f;
    lbl_801A66CC->frustum.viewNormals[0].z = -sincos[1];
    lbl_8006E1C0(&lbl_801A66CC->frustum.viewNormals[0], &lbl_801A66CC->frustum.worldNormals[0]);

    lbl_8006D1B8(bottom + 0x4000, sincos);
    lbl_801A66CC->frustum.viewNormals[1].x = -sincos[0];
    lbl_801A66CC->frustum.viewNormals[1].y = 0.0f;
    lbl_801A66CC->frustum.viewNormals[1].z = -sincos[1];
    lbl_8006E1C0(&lbl_801A66CC->frustum.viewNormals[1], &lbl_801A66CC->frustum.worldNormals[1]);

    lbl_8006D1B8(left + 0x4000, sincos);
    lbl_801A66CC->frustum.viewNormals[2].x = 0.0f;
    lbl_801A66CC->frustum.viewNormals[2].y = -sincos[0];
    lbl_801A66CC->frustum.viewNormals[2].z = -sincos[1];
    lbl_8006E1C0(&lbl_801A66CC->frustum.viewNormals[2], &lbl_801A66CC->frustum.worldNormals[2]);

    lbl_8006D1B8(right - 0x4000, sincos);
    lbl_801A66CC->frustum.viewNormals[3].x = 0.0f;
    lbl_801A66CC->frustum.viewNormals[3].y = -sincos[0];
    lbl_801A66CC->frustum.viewNormals[3].z = -sincos[1];
    lbl_8006E1C0(&lbl_801A66CC->frustum.viewNormals[3], &lbl_801A66CC->frustum.worldNormals[3]);
}
/* fzgx:end fn_1_549F4 */

/* fzgx:begin fn_1_54DCC */
/* Copies the frustum state out. */
void fn_1_54DCC(Frustum *out) {
    fn_800794F0(out, &lbl_801A66CC->frustum, sizeof(Frustum));
}
/* fzgx:end fn_1_54DCC */

/* fzgx:begin fn_1_54E00 */
/* Restores a frustum state saved by fn_1_54DCC. */
void fn_1_54E00(Frustum *in) {
    fn_800794F0(&lbl_801A66CC->frustum, in, sizeof(Frustum));
}
/* fzgx:end fn_1_54E00 */

/* fzgx:begin fn_1_54E34 */
/* Returns whether a sphere (centre in world space) touches the frustum (SMB1 test_sphere_in_frustum). */
s32 fn_1_54E34(FrustumVec *center, f32 radius) {
    FrustumVec v;
    f32 x, y, z;
    s32 i;
    FrustumVec *n;

    lbl_8006E1B0(center, &v);
    z = v.z;
    x = v.x;
    y = v.y;
    if (z > radius) {
        return 0;
    }
    radius = -radius;
    n = lbl_801A66CC->frustum.viewNormals;
    for (i = 0; i < 4; i++) {
        f32 dx = x * n->x;
        f32 dy = y * n->y;
        f32 dz = z * n->z;
        if (dx + dy + dz < radius) {
            return 0;
        }
        n++;
    }
    return 1;
}
/* fzgx:end fn_1_54E34 */

/* fzgx:begin fn_1_54F5C */
/* Same test with the radius scaled first; the view-space centre is kept in the work block
 * (SMB1 test_scaled_sphere_in_frustum). */
s32 fn_1_54F5C(FrustumVec *center, f32 radius, f32 scale) {
    f32 x, y, z;
    s32 i;
    FrustumVec *n;

    lbl_8006E1B0(center, &lbl_801A66CC->viewPoint);
    radius = radius * scale;
    z = lbl_801A66CC->viewPoint.z;
    if (z > radius) {
        return 0;
    }
    x = lbl_801A66CC->viewPoint.x;
    y = lbl_801A66CC->viewPoint.y;
    radius = -radius;
    n = lbl_801A66CC->frustum.viewNormals;
    for (i = 0; i < 4; i++) {
        f32 dx = x * n->x;
        f32 dy = y * n->y;
        f32 dz = z * n->z;
        if (dx + dy + dz < radius) {
            return 0;
        }
        n++;
    }
    return 1;
}
/* fzgx:end fn_1_54F5C */

/* fzgx:begin fn_1_550A8 */
/* Saves the frustum (objput.c pushes it around its draws). */
void fn_1_550A8(void) {
    fn_800794F0(&lbl_1_bss_6C710, &lbl_801A66CC->frustum, sizeof(Frustum));
}
/* fzgx:end fn_1_550A8 */

/* fzgx:begin fn_1_550E0 */
/* Restores the frustum saved by fn_1_550A8. */
void fn_1_550E0(void) {
    fn_800794F0(&lbl_801A66CC->frustum, &lbl_1_bss_6C710, sizeof(Frustum));
}
/* fzgx:end fn_1_550E0 */
