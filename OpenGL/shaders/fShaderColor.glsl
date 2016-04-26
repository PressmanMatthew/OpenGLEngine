#version 430

in vec3 position;
in vec2 uv;

void main()
{
	gl_FragColor = vec4((position.x + 1) / 2, (position.y + 1) / 2, (position.z + 1) / 2, 1);
}