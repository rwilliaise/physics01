
#ifndef MATHLIB_H_
#define MATHLIB_H_

#define MAT3_IDENTITY_INIT { \
    { 1.0f, 0.0f, 0.0f }, \
    { 0.0f, 1.0f, 0.0f }, \
    { 0.0f, 0.0f, 1.0f } \
}
#define MAT4_IDENTITY_INIT { \
    { 1.0f, 0.0f, 0.0f, 0.0f }, \
    { 0.0f, 1.0f, 0.0f, 0.0f }, \
    { 0.0f, 0.0f, 1.0f, 0.0f }, \
    { 0.0f, 0.0f, 0.0f, 1.0f } \
}
#define MAT4_IDENTITY (mat4_t) MAT4_IDENTITY_INIT

#define VEC2_ZERO_INIT { 0.0f, 0.0f }
#define VEC2_ZERO (vec2_t) VEC2_ZERO_INIT

#define VEC2_ONE_INIT { 1.0f, 1.0f }
#define VEC2_ONE (vec2_t) VEC2_ONE_INIT

#define _debug_mat3(x) printf(#x ": {{ %f, %f, %f }, { %f, %f, %f }, { %f, %f, %f }}\n", x[0][0], x[0][1], x[0][2], x[1][0], x[1][1], x[1][2], x[2][0], x[2][1], x[2][2])

typedef float mat3_t[3][3];
typedef float mat4_t[4][4];
typedef float vec2_t[2];
typedef float vec3_t[3];

typedef struct {
    vec2_t pos;
    vec2_t size;
} aabb_t;

void mat3_mul_mat3(mat3_t lhs, mat3_t rhs, mat3_t dest);
void mat3_mul_vec3(mat3_t lhs, vec3_t rhs, vec3_t dest);
void mat3_translate(mat3_t dest, vec2_t v);
void mat3_rotate(mat3_t dest, float theta);
void mat3_scale(mat3_t dest, vec2_t scale);
void mat3_scales(mat3_t dest, float scale);

void mat4_copy(mat4_t dest, mat4_t src);
void mat4_ortho(mat4_t dest, float b, float t, float l, float r, float n, float f);

void vec2_copy(vec2_t dest, vec2_t src);
void vec2_sub(vec2_t lhs, vec2_t rhs, vec2_t dest);

void vec3_copy(vec3_t dest, vec3_t src);

#endif // MATHLIB_H_
