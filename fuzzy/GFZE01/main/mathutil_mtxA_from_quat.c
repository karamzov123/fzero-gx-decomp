/* Non-matching: best partial attempt (92.86% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/hw_regs.h"
#include "dolphin/types.h"
#pragma opt_common_subs off
#pragma scheduling off

#pragma opt_propagation off
static inline const f32 mathutil_mtxA_from_quat_array_read(s32 index, const f32 *array) { return array[index]; }
#pragma peephole off
void mathutil_mtxA_from_quat(const f32 *quat)
{
    f32 *mtx = (f32 *)LC_BASE;
    f32 x = mathutil_mtxA_from_quat_array_read(0, quat);
    f32 y = mathutil_mtxA_from_quat_array_read(1, quat);
    f32 one = mtx[103];
    f32 z = mathutil_mtxA_from_quat_array_read(2, quat);
    f32 zero = one - one;
    f32 w = mathutil_mtxA_from_quat_array_read(3, quat);
    f32 two = one + one;
    f32 xz;
    f32 xy;
    f32 yz;
    f32 dy;
    f32 dz;
    f32 xy_2;
    f32 wx;
    f32 wy;
    struct { f32 value; } wz;
    f32 a;
    f32 b;
    f32 yz_2;
    f32 a_2;
    f32 c;
    f32 d;
    f32 e;
    f32 f;
    mtx[3] = zero;
    mtx[7] = zero;
    mtx[11] = zero;
    xz = x * x;
    xy = y * y;
    yz = z * z;
    xz = xz + z * z;
    xy_2 = xy_2 + x * x;
    yz_2 = yz_2 + y * y;
    xz = one - xz * two;
    mtx[5] = xz;
    xy_2 = one - xy_2 * two;
    mtx[10] = xy_2;
    yz_2 = one - yz_2 * two;
    mtx[0] = yz_2;
{
    f32 dx;
    dx = x + x;
    dy = y + y;
    dz = z + z;
    wx = w;
    wx = wx * dx;
}
    wy = w * dy;
    wz.value = w * dz;
    a = y;
    a_2 = a_2 * dz - wx;
    mtx[6] = a_2;
    b = y * dz + wx;
    mtx[9] = b;
    c = x * dz - wy;
    mtx[8] = c;
    d = x * dz + wy;
    mtx[2] = d;
    e = x * dy - wz.value;
    mtx[1] = e;
    f = x * dy + wz.value;
    mtx[4] = f;
}
#pragma peephole reset

#pragma opt_propagation reset

