
#ifndef R_SHADER_H_
#define R_SHADER_H_

#include "physics01.h"

#define R_SHADER_INVALID 0

typedef uint32_t r_shader_t;

r_shader_t r_shader_open(const char *vert_path, const char *frag_path);
void r_shader_close(r_shader_t S);

#endif // R_SHADER_H_
