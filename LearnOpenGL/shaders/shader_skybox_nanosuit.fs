#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Normal;
in vec3 Position;

uniform vec3 cameraPos;
uniform samplerCube skybox;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_height1;

void main()
{    
    float ratio = 1.00 / 1.52;
    vec3 nor = normalize(Position - cameraPos);
    vec3 refle = reflect(nor, normalize(Normal));
    //vec3 refle = refract(nor, normalize(Normal), ratio);
    FragColor = vec4(texture(skybox, refle).rgb, 1.0);
}