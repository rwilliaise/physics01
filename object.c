
#include "object.h"

#include "mathlib.h"
#include "physics01.h"
#include <stdlib.h>

// 0 = vao, 1 = vbo
static uint32_t box_geo[2];
static int box_verts = 4;
static const float box_data[] = {
     0.5,  0.5, 0,
    -0.5,  0.5, 0,
    -0.5, -0.5, 0,
     0.5, -0.5, 0,
};

static void object_box_new() {
    if (box_geo[0] != 0) return;

    glGenVertexArrays(1, &box_geo[0]);
    glGenBuffers(1, &box_geo[1]);

    glBindVertexArray(box_geo[0]);
    glBindBuffer(GL_ARRAY_BUFFER, box_geo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(box_data), box_data, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, NULL);
    glEnableVertexAttribArray(0);
}

object_t *object_new(object_type_t type) {
    object_t *O = malloc(sizeof(object_t));

    if (O == NULL)
        return NULL;

    O->angle = 0;
    O->mass = 1;
    vec2_copy(O->pos, VEC2_ZERO);
    vec2_copy(O->size, VEC2_ONE);

    O->type = type;
    switch (O->type) {
    case OBJECT_TYPE_BOX:
        object_box_new();
        break;
    }

    return O;
}

void object_render(object_t *O) {
    int verts = 0;

    switch (O->type) {
    case OBJECT_TYPE_BOX:
        glBindVertexArray(box_geo[0]);
        verts = box_verts;
        break;
    }

    glDrawArrays(GL_LINE_LOOP, 0, verts);
}

void object_update(object_t *O, float delta) {

}

void object_upload(object_t *O, r_shader_t S) {
    mat3_t out = MAT3_IDENTITY_INIT;
    mat3_scale(out, O->size);
    mat3_rotate(out, O->angle);
    mat3_translate(out, O->pos);
    glUseProgram(S);
    glUniformMatrix3fv(glGetUniformLocation(S, "object_model"), 1, GL_FALSE, out[0]);
}

object_t *object_ref(object_t *O) {
    O->rc++;
    return O;
}

void object_deref(object_t *O) {
    O->rc--;
    if (O->rc <= 0) {
        free(O);
    }
}
