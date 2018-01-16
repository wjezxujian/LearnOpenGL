#version 330 core
out vec4 FragColor;  
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform sampler2D ourTexture2;
uniform float visiable;

void main()
{
    //FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0);
    //FragColor = mix(texture(ourTexture, TexCoord), texture(ourTexture2, TexCoord), 0.2);
    FragColor = mix(texture(ourTexture, TexCoord), texture(ourTexture2, vec2(1.0f-TexCoord.x, TexCoord.y)), visiable);
}