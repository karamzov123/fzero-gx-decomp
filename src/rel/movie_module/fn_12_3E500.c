
#include "types.h"

typedef float CFTMtx3D[3][3];

void fn_12_3E500(CFTMtx3D matrix, CFTMtx3D inverse);

void fn_12_3E500(CFTMtx3D matrix, CFTMtx3D inverse) {
    float determinant;
    float scale;
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;
    float g;
    float h;
    float i;
    a = matrix[0][0];
    b = matrix[0][1];
    c = matrix[0][2];
    d = matrix[1][0];
    e = matrix[1][1];
    f = matrix[1][2];
    g = matrix[2][0];
    h = matrix[2][1];
    i = matrix[2][2];
    scale = 1.0f;
    determinant = (a * e * i + b * f * g + c * d * h) - (a * f * h + b * d * i + c * e * g);
    inverse[0][0] = scale * ((e * i - f * h) / determinant);
    inverse[0][1] = scale * (-(b * i - c * h) / determinant);
    inverse[0][2] = scale * ((b * f - c * e) / determinant);
    inverse[1][0] = scale * (-(d * i - f * g) / determinant);
    inverse[1][1] = scale * ((a * i - c * g) / determinant);
    inverse[1][2] = scale * (-(a * f - c * d) / determinant);
    inverse[2][0] = scale * ((d * h - e * g) / determinant);
    inverse[2][1] = scale * (-(a * h - b * g) / determinant);
    inverse[2][2] = scale * ((a * e - b * d) / determinant);
}
