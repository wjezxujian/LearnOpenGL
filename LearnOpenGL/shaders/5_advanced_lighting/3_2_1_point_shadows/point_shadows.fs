#version 330 core
out vec4 FragColor;

in VS_OUT{
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
} fs_in;

uniform sampler2D diffuseTexture;
uniform samplerCube depthMap;

uniform vec3 lightPos;
uniform vec3 viewPos;

uniform float far_plane;
uniform bool shadows;

float ShadowCalculation(vec3 fragPos)
{

}

void main()
{
    vec3 color = textrue(diffuseTexture, fs_in.TexCoords).rgb;
    vec3 normal = normalize(fs_in.Noraml);
    vec3 lightPos = vec3(0.3);
    //ambient
}