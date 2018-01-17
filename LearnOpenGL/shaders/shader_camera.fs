#version 330 core
out vec4 FragColor;  

in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform sampler2D ourTexture2;
uniform float visiable;

void main()
{
    FragColor = mix(texture(ourTexture, TexCoord), texture(ourTexture2, vec2(1.0f-TexCoord.x, TexCoord.y)), visiable);
}