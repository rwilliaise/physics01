
#include "physics01.h"
#include "r_shader.h"

#include <GLFW/glfw3.h>
#include <stdio.h>

void r_glfw_error(int code, const char *desc) {
    fprintf(stderr, "GLFW error (0x%.04x): %s\n", code, desc);
}

void r_glfw_resize(GLFWwindow *win, int w, int h) {
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
    glfwWindowHint(GLFW_SAMPLES, 4);
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
    glEnable(GL_MULTISAMPLE);

    const float triangle[] = {
        0.0, 0.5, 0.0,
        -0.5, -0.5, 0.0,
        0.5, -0.5, 0.0
    };

    uint32_t vao;
    uint32_t vbo;
    
    r_shader_t default_shader = r_shader_open("res/shaders/default.vert", "res/shaders/default.frag");
    _debugd(default_shader);

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, NULL);
    glEnableVertexAttribArray(0);

    glUseProgram(default_shader);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    glfwTerminate();

    return 0;
}
