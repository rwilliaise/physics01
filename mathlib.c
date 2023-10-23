
#include "mathlib.h"

#include <math.h>
#include <string.h>

void mat3_mul_mat3(mat3_t lhs, mat3_t rhs, mat3_t dest) {
    float a00 = lhs[0][0], a01 = lhs[0][1], a02 = lhs[0][2],
          a10 = lhs[1][0], a11 = lhs[1][1], a12 = lhs[1][2],
          a20 = lhs[2][0], a21 = lhs[2][1], a22 = lhs[2][2];

    float b00 = rhs[0][0], b01 = rhs[0][1], b02 = rhs[0][2],
          b10 = rhs[1][0], b11 = rhs[1][1], b12 = rhs[1][2],
          b20 = rhs[2][0], b21 = rhs[2][1], b22 = rhs[2][2];

    dest[0][0] = a00 * b00 + a10 * b01 + a20 * b02;
    dest[0][1] = a01 * b00 + a11 * b01 + a21 * b02;
    dest[0][2] = a01 * b00 + a12 * b01 + a22 * b02;
    dest[1][0] = a00 * b10 + a10 * b11 + a20 * b12;
    dest[1][1] = a01 * b10 + a11 * b11 + a21 * b12;
    dest[1][2] = a02 * b10 + a12 * b11 + a22 * b12;
    dest[2][0] = a00 * b20 + a10 * b21 + a20 * b22;
    dest[2][1] = a01 * b20 + a11 * b21 + a21 * b22;
    dest[2][2] = a02 * b20 + a12 * b21 + a22 * b22;
}

void mat3_mul_vec3(mat3_t lhs, vec3_t rhs, vec3_t dest) {
    vec3_t tmp;
    tmp[0] = lhs[0][0] * rhs[0] + lhs[1][0] * rhs[1] + lhs[2][0] * rhs[2];
    tmp[1] = lhs[0][1] * rhs[0] + lhs[1][1] * rhs[1] + lhs[2][1] * rhs[2];
    tmp[2] = lhs[0][2] * rhs[0] + lhs[1][2] * rhs[1] + lhs[2][2] * rhs[2];
    vec3_copy(dest, tmp);
}

void mat3_translate(mat3_t dest, vec2_t v) {
    dest[2][0] = dest[0][0] * v[0] + dest[1][0] * v[1] + dest[2][0];
    dest[2][1] = dest[0][1] * v[0] + dest[1][1] * v[1] + dest[2][1];
    dest[2][2] = dest[0][2] * v[0] + dest[1][2] * v[1] + dest[2][2];
}

void mat3_rotate(mat3_t dest, float theta) {
    float a00 = dest[0][0], a01 = dest[0][1], a02 = dest[0][2],
          a10 = dest[1][0], a11 = dest[1][1], a12 = dest[1][2];

    float s = sinf(theta);
    float c = cosf(theta);

    dest[0][0] = a00 * c + a10 * s;
    dest[0][1] = a01 * c + a11 * s;
    dest[0][2] = a02 * c + a12 * s;

    dest[1][0] = a00 * -s + a10 * c;
    dest[1][1] = a01 * -s + a11 * c;
    dest[1][2] = a02 * -s + a12 * c;
}

void mat3_scale(mat3_t dest, vec2_t scale) {
    dest[0][0] = dest[0][0] * scale[0];
    dest[0][1] = dest[0][1] * scale[0];
    dest[0][2] = dest[0][2] * scale[0];

    dest[1][0] = dest[1][0] * scale[1];
    dest[1][1] = dest[1][1] * scale[1];
    dest[1][2] = dest[1][2] * scale[1];
}

void mat3_scales(mat3_t dest, float scale) {
    dest[0][0] = dest[0][0] * scale;
    dest[0][1] = dest[0][1] * scale;
    dest[0][2] = dest[0][2] * scale;

    dest[1][0] = dest[1][0] * scale;
    dest[1][1] = dest[1][1] * scale;
    dest[1][2] = dest[1][2] * scale;
}

void mat4_copy(mat4_t dest, mat4_t src) {
    memcpy(dest, src, sizeof(mat4_t));
}

void mat4_ortho(mat4_t dest, float b, float t, float l, float r, float n, float f) {
    mat4_copy(dest, MAT4_IDENTITY);
    dest[0][0] = 2 / (r - l);
    dest[1][1] = 2 / (t - b);
    dest[2][2] = -2 / (f - n);
    dest[3][0] = -(r + l) / (r - l);
    dest[3][0] = -(t + b) / (t - b);
    dest[3][0] = -(f + n) / (f - n);
}

void vec2_copy(vec2_t dest, vec2_t src) {
    dest[0] = src[0];
    dest[1] = src[1];
}

void vec2_sub(vec2_t lhs, vec2_t rhs, vec2_t dest) {
    dest[0] = lhs[0] - rhs[0];
    dest[1] = lhs[1] - rhs[1];
    dest[2] = lhs[2] - rhs[2];
}

void vec3_copy(vec3_t dest, vec3_t src) {
    dest[0] = src[0];
    dest[1] = src[1];
    dest[2] = src[2];
}

