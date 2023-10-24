
#include "physics01.h"
#include "object.h"
#include "r_camera.h"
#include "r_shader.h"

#include <GLFW/glfw3.h>
#include <math.h>
#include <stdio.h>

typedef struct {
    r_shader_t def;
    r_camera_t cam;
} r_context_t;

void r_glfw_error(int code, const char *desc) {
    fprintf(stderr, "GLFW error (0x%.04x): %s\n", code, desc);
}

void r_glfw_resize(GLFWwindow *win, int w, int h) {
    r_context_t *ctx = (r_context_t *) glfwGetWindowUserPointer(win);
    r_camera_update_ortho(&ctx->cam, ctx->def, (float) w / h);
    glViewport(0, 0, w, h);
}

void r_gl_msg(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar *message,
    const void *ud
) {
    fprintf(stderr, "GL %s (0x%.04x): %s\n",
        type == GL_DEBUG_TYPE_ERROR ? "error" : "info",
        severity,
        message
    );
}

int main(int argc, char *argv[]) {
    glfwSetErrorCallback(r_glfw_error);

    if (glfwInit() != GLFW_TRUE)
        return 1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    // glfwWindowHint(GLFW_SAMPLES, 4);
    GLFWwindow *window = glfwCreateWindow(640, 480, "physics01", NULL, NULL);

    if (window == NULL) {
        glfwTerminate();
        return 1;
    }

    glfwSetWindowSizeCallback(window, r_glfw_resize);
    glfwMakeContextCurrent(window);
    
    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        return 1;
    }

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glDebugMessageCallback(r_gl_msg, NULL);
    glEnable(GL_DEBUG_OUTPUT);
    // glEnable(GL_MULTISAMPLE);

    r_shader_t default_shader = r_shader_open("res/shaders/default.vert", "res/shaders/default.frag");
    
    r_context_t ctx = {
        .def = default_shader,
        .cam = {
            .zoom = 1.0f,
            .pos = { 0.0f, 0.0f },
        }
    };
    glfwSetWindowUserPointer(window, &ctx);
    r_camera_update_ortho(&ctx.cam, default_shader, 640.0f / 480.0f);
    r_camera_upload(&ctx.cam, default_shader);

    object_t *box = object_new(OBJECT_TYPE_BOX);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(default_shader);
        box->angle = glfwGetTime();
        object_upload(box, default_shader);
        object_render(box);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();

    return 0;
}
