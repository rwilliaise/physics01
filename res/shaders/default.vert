#version 460 core

layout (location = 0) in vec3 vert_pos;

uniform mat3 camera_view;
uniform mat4 camera_projection;
uniform mat3 object_model;

void main() {
    vec4 projected = camera_projection * vec4(vert_pos.xy, 0.0f, 1.0f);
    gl_Position = vec4(object_model * camera_view * projected.xyz, 1.0f);
}
