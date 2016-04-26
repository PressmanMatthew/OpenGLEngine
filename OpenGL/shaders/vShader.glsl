#version 430

layout (location = 0) in vec3 position;
layout(location = 1) in vec2 uv;
out vec3 loc;
out vec2 fragUV;

void main()
{
	gl_Position = vec4(position, 1);
	loc = position;
	fragUV = uv;
}