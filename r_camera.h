
#ifndef R_CAMERA_H_
#define R_CAMERA_H_

#include "mathlib.h"
#include "r_shader.h"

typedef struct {
    float zoom;
    vec2_t pos;
} r_camera_t;

void r_camera_update_ortho(r_camera_t *C, r_shader_t S, float aspect);
void r_camera_upload(r_camera_t *C, r_shader_t S);

#endif // R_CAMERA_H_
