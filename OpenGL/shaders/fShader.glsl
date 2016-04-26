#version 430

in vec3 loc;
in vec2 fragUV;
uniform sampler2D mytexture;

void main()
{
	gl_FragColor = texture(mytexture, fragUV);
}