
#include "r_shader.h"

#include "res.h"
#include <stdlib.h>
#include <stdio.h>

static int r_shader_compile_status(uint32_t shader) {
    int success;
    char info_log[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (success == 0) {
        glGetShaderInfoLog(shader, 512, NULL, info_log);
        printf("GL compile error: %s\n", info_log);
        return 1;
    }

    return 0;
}

r_shader_t r_shader_open(const char *vert_path, const char *frag_path) {
    char *vert_file = res_from_file(vert_path);
    char *frag_file = res_from_file(frag_path);

    if (vert_file == NULL || frag_file == NULL) {
        free(vert_file);
        free(frag_file);
        return R_SHADER_INVALID;
    }

    uint32_t vert = glCreateShader(GL_VERTEX_SHADER);
    uint32_t frag = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vert, 1, (const char **) &vert_file, NULL);
    glShaderSource(frag, 1, (const char **) &frag_file, NULL);

    free(vert_file);
    free(frag_file);

    glCompileShader(vert);
    glCompileShader(frag);

    if (r_shader_compile_status(vert) || r_shader_compile_status(frag))
        return 0;

    r_shader_t out = glCreateProgram();

    glAttachShader(out, vert);
    glAttachShader(out, frag);
    glLinkProgram(out);

    glDeleteShader(vert);
    glDeleteShader(frag);

    return out;
}

void r_shader_close(r_shader_t S) {
    glDeleteProgram(S);
}
