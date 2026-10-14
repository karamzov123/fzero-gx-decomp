/* Non-matching: best partial attempt (62.76% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Particle {
    u8 active;
    u8 pad_1;
    u8 linkCount;
    u8 pad_3;
    u16 id;
    u8 pad_6[0xA];
    f32 x, y, z;
    f32 oldX, oldY, oldZ;
    u8 pad_28[0xC];
    f32 vx, vy, vz;
    f32 weight;
};

struct Link {
    struct Particle *a;
    struct Particle *b;
    f32 radius2;
};

struct World {
    u8 pad_0[0xC];
    u32 particleCount;
    u32 linkCount;
    struct Particle *particles;
    struct Link *links;
};

struct Vec3 { f32 x, y, z; };
extern s32 fn_80077B14(void *);
extern f32 lbl_8006D118(void *);
extern f32 lbl_8006D0B4(f32);
extern u32 lbl_801A63C0;

void fn_1_D9D8C(struct World *world, void *arg1, s32 noisy) {
    struct Particle *p;
    struct Link *link;
    struct Vec3 delta;
    f32 dist2;
    f32 scale, wa, wb, mag;
    u32 i, j, k;
    s32 *out;

    if (world == 0 || arg1 == 0)
        return;

    out = (s32 *)fn_80077B14(arg1);
    p = world->particles;
    for (i = 0; i < world->particleCount; i++, p++) {
        if ((p->active & 1) == 0) {
            *(u32 *)&p->oldX = *(u32 *)&p->x;
            *(u32 *)&p->oldY = *(u32 *)&p->y;
            *(u32 *)&p->oldZ = *(u32 *)&p->z;
            p->x += p->vx;
            p->y += p->vy;
            p->z += p->vz;
            p->y -= 0.0013611111376020642;
            p->vy -= 0.0027222223579883575f;
        }
    }

    for (k = 0; k < 4; k++) {
        link = world->links;
        for (j = 0; j < world->linkCount; j++, link++) {
            struct Particle *a = link->a;
            struct Particle *b = link->b;
            if (a != 0 && b != 0) {
                delta.x = a->x - b->x;
                delta.y = a->y - b->y;
                delta.z = a->z - b->z;
                dist2 = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
                if (dist2 - 0.0001f > link->radius2) {
                    mag = lbl_8006D118(&dist2);
                    scale = mag * (dist2 - lbl_8006D0B4(link->radius2));
                    delta.x *= scale;
                    delta.y *= scale;
                    delta.z *= scale;
                    wa = 1.0f / (a->weight + b->weight);
                    wa *= a->weight;
                    wb = (a->weight) * (1.0f / (a->weight + b->weight));
                    a->x -= delta.x * wa;
                    a->y -= delta.y * wa;
                    a->z -= delta.z * wa;
                    b->x += delta.x * wb;
                    b->y += delta.y * wb;
                    b->z += delta.z * wb;
                }
            }
        }
    }

    p = world->particles;
    for (i = 0; i < world->particleCount; i++, p++) {
        p->oldX *= 0.9f;
        p->oldY *= 0.9f;
        p->oldZ *= 0.9f;
        p->oldX += 0.1f * (p->x - p->oldX);
        p->oldY += 0.1f * (p->y - p->oldY);
        p->oldZ += 0.1f * (p->z - p->oldZ);
        if (!noisy) {
            p->oldX += 0.02f * ((f32)(((lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb) >> 16) & 0x7fff) - 32768.0f) / 32767.0f - 0.005f;
            p->oldY += 0.004f * ((f32)(((lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb) >> 16) & 0x7fff) - 32768.0f) / 32767.0f;
            p->oldZ += 0.2f * ((f32)(((lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb) >> 16) & 0x7fff) - 32768.0f) / 32767.0f - 0.1f;
        } else {
            p->oldZ += 0.02f * ((f32)(((lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb) >> 16) & 0x7fff) - 32768.0f) / 32767.0f - 0.005f;
            p->oldY += 0.004f * ((f32)(((lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb) >> 16) & 0x7fff) - 32768.0f) / 32767.0f;
            p->oldX += 0.2f * ((f32)(((lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb) >> 16) & 0x7fff) - 32768.0f) / 32767.0f - 0.1f;
        }
    }

    p = world->particles;
    for (i = 0; i < world->particleCount; i++, p++) {
        for (j = 0; j < p->linkCount; j++) {
            struct Particle *q = (struct Particle *)((u8 *)p + *(u16 *)((u8 *)p + 4 + j * 2));
            q->x = p->x;
            q->y = p->y;
            q->z = p->z;
        }
    }
}
