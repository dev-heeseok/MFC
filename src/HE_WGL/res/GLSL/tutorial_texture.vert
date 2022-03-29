#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexel;

out vec3 o_color;
out vec2 o_texel;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);
	o_color = aColor;
	o_texel = aTexel;
}