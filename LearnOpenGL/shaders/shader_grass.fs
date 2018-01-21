#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture1;

float near = 0.1;
float far = 100.0;

float LinearizeDepth(float depth)
{
    float z = depth * 2.0 - 1.0;
    return (2.0 * near * far) / (far + near - z * (far - near));
}

void main()
{
    vec4 texColor = texture(texture1, TexCoords);

    //丢弃片段
    // if(texColor.a < 0.1)
    //     discard;

    FragColor = texColor;
    //FragColor = vec4(vec3(gl_FragCoord.z), 1.0);
    //float depth = LinearizeDepth(gl_FragCoord.z) / far;
    //FragColor = vec4(vec3(depth), 1.0);
}