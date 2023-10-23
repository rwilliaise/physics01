#version 460 core

layout (location = 0) in vec3 vert_pos;

uniform mat3 camera_view;
uniform mat3 object_model;

void main() {
    gl_Position = vec4(object_model * camera_view * vec3(vert_pos.xy, 1.0f), 1.0f);
}
