#version 430

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv;
layout (location = 2) in vec3 norm;
layout (location = 3) uniform mat4 trans;
layout (location = 4) uniform mat4 camera;
out vec3 loc;
out vec2 fragUV;

void main()
{
	gl_Position = camera * trans * vec4(position, 1);
	loc = position;
	fragUV = uv;
}