#version 430

in vec3 loc;
in vec2 fragUV;
layout (location = 2)uniform sampler2D mytexture;

void main()
{
	gl_FragColor = texture(mytexture, fragUV);//vec4((fragUV.x + 1) / 2, (fragUV.y + 1) / 2, 0, 0);
}