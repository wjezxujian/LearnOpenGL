#version 330 core
layout (location = 0) in vec3 aPos;         // 位置变量的属性位置值为 0 
layout (location = 1) in vec3 aNormal;
//layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;
out vec3 Normal;
out vec3 Position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    Normal = vec3(transpose(inverse(model))) * aNormal;
    Position = vec3(model * vec4(aPos, 1.0));

    //注意乘法要从右向左读
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    TexCoords = aTexCoords;
}