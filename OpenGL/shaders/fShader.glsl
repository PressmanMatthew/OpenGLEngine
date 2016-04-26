#version 430

in vec3 fragUV;

void main()
{
	gl_FragColor = vec4((fragUV.x + 1) / 2, (fragUV.y + 1) / 2, (fragUV.z + 1) / 2, 1);
}