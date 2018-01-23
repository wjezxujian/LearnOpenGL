#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D frontTexture;
uniform sampler2D backTexture;

void main()
{
    // if(gl_FragCoord. x < 640)
    //     FragColor = vec4(1.0, 0.0, 0.0, 1.0);
    // else
    //     FragColor = vec4(0.0, 1.0, 0.0, 1.0);
    if(gl_FrontFacing)
        FragColor = texture(frontTexture, TexCoords);
    else
        FragColor = texture(backTexture, TexCoords);
}