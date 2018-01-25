#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

out vec2 TexCoords;

layout (std140) uniform Matrices
{
    mat4 projection;
    mat4 view;
};

out VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
} vs_out;

uniform mat4 model;

void main()
{
    gl_Position = projection * view * vec4(position, 1.0f);
    vs_out.FragPos = position;
    vs_out.Normal = normal;
    vs_out.TexCoords = texCoords;
}