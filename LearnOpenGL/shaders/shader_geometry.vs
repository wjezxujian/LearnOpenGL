#version 330 core
layout (location = 0) in vec2 aPos;         // 位置变量的属性位置值为 0 
layout (location = 1) in vec3 aColor;
//layout (location = 1) in vec2 aTexCoords;

//out vec2 TexCoords;


out vec4 Position;

out VS_OUT{
    vec3 color;
} vs_out;


layout (std140) uniform Matrices
{
    mat4 projection;
    mat4 view;
};

uniform mat4 model;

void main()
{
    // //注意乘法要从右向左读
    // gl_Position = projection * view * model * vec4(aPos, 1.0);
    // //TexCoords = aTexCoords;
    // Position = gl_Position;

    gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);
    vs_out.color = aColor;
}