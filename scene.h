
#ifndef SCENE_H_
#define SCENE_H_

#include "object.h"

#include <stdlib.h>

typedef struct {
    size_t object_count;
    object_t *objects;
} scene_t;

scene_t *scene_new();
void scene_append(scene_t *S, object_t *O);
void scene_free(scene_t *S);


#endif // SCENE_H_
