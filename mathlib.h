
#ifndef MATHLIB_H_
#define MATHLIB_H_

typedef float mat3_t[3][3];
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

void vec2_copy(vec2_t dest, vec2_t src);

void vec3_copy(vec3_t dest, vec3_t src);

#endif // MATHLIB_H_
