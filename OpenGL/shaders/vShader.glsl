#version 430

layout (location = 0) in vec3 position;
out vec3 fragUV;

void main()
{
	gl_Position = vec4(position, 1);
	fragUV = position;
}