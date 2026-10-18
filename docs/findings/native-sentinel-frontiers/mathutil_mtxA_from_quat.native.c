#include "dolphin/hw_regs.h"
#include "types.h"

#pragma opt_common_subs off
#pragma scheduling off
#pragma opt_propagation off
#pragma peephole off
void mathutil_mtxA_from_quat(const f32 *quat) {
    f32 *matrix = (f32 *)LC_BASE;
    f32 x = quat[0];
    f32 y = quat[1];
    f32 one = matrix[103];
    f32 z = quat[2];
    f32 zero = one - one;
    f32 w = quat[3];
    f32 two = one + one;
    f32 sum_xz;
    f32 sum_xy;
    f32 sum_yz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 wx;
    f32 wy;
    f32 wz;
    f32 r12;
    f32 r21;
    f32 r20;
    f32 r02;
    f32 r01;
    f32 r10;

    matrix[3] = zero;
    matrix[7] = zero;
    matrix[11] = zero;
    sum_xz = x * x;
    sum_xy = y * y;
    sum_yz = z * z;
    sum_xz = z * z + sum_xz;
    sum_xy = x * x + sum_xy;
    sum_yz = y * y + sum_yz;
    sum_xz = one - sum_xz * two;
    matrix[5] = sum_xz;
    sum_xy = one - sum_xy * two;
    matrix[10] = sum_xy;
    sum_yz = one - sum_yz * two;
    matrix[0] = sum_yz;
    dx = x + x;
    dy = y + y;
    dz = z + z;
    wx = w * dx;
    wy = w * dy;
    wz = w * dz;
    r12 = y * dz - wx;
    matrix[6] = r12;
    r21 = y * dz + wx;
    matrix[9] = r21;
    r20 = x * dz - wy;
    matrix[8] = r20;
    r02 = x * dz + wy;
    matrix[2] = r02;
    r01 = x * dy - wz;
    matrix[1] = r01;
    r10 = x * dy + wz;
    matrix[4] = r10;
}
#pragma peephole reset
#pragma opt_propagation reset
#pragma scheduling reset
#pragma opt_common_subs reset
