
#include "r_camera.h"
#include "mathlib.h"

#include <stdio.h>

void r_camera_update_ortho(r_camera_t *C, r_shader_t S, float aspect) {
    mat4_t out;
    mat4_ortho_unit(out, aspect);
    glUseProgram(S);
    glUniformMatrix4fv(glGetUniformLocation(S, "camera_projection"), 1, GL_FALSE, out[0]);
}

void r_camera_upload(r_camera_t *C, r_shader_t S) {
    mat3_t out = MAT3_IDENTITY_INIT;
    mat3_scales(out, C->zoom);
    mat3_translate(out, C->pos);
    glUseProgram(S);
    glUniformMatrix3fv(glGetUniformLocation(S, "camera_view"), 1, GL_FALSE, out[0]);
}

