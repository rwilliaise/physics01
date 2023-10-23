
#ifndef OBJECT_H_
#define OBJECT_H_

#include "mathlib.h"

#include <stdint.h>
#include "r_shader.h"

typedef enum {
    OBJECT_TYPE_BOX,
} object_type_t;

typedef struct {
    object_type_t type;
    vec2_t pos;
    vec2_t vel;
    vec2_t size;
    float angle;
    float mass;
    uint64_t rc;
} object_t;

object_t *object_new(object_type_t type);
void object_render(object_t *O);
void object_update(object_t *O, float delta);
void object_upload(object_t *O, r_shader_t S);
object_t *object_ref(object_t *O);
void object_deref(object_t *O);

#endif // OBJECT_H_
