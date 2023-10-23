
#include "object.h"

#include "physics01.h"
#include <stdlib.h>

// 0 = vao, 1 = vbo, 2 = ebo
static uint32_t box_geo[3];



static void object_box_new(object_t *O) {
    
}

object_t *object_new(object_type_t type) {
    object_t *O = malloc(sizeof(object_t));

    if (O == NULL)
        return NULL;

    return O;
}

void object_render(object_t *O) {
    int verts;

    switch (O->type) {
    case OBJECT_TYPE_BOX:
        glBindVertexArray(box_geo[0]);
        
        break;
    }

    glDrawArrays(GL_LINE_STRIP, 0, verts);
}

void object_ref(object_t *O) {
    O->rc++;
}

void object_deref(object_t *O) {
    O->rc--;
    if (O->rc <= 0) {
        free(O);
    }
}
