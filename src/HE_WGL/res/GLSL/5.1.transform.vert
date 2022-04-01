#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 o_texcoord;

uniform mat4 u_transform;

void main()
{
	gl_Position = u_transform * vec4(aPos, 1.0f);
	o_texcoord = aTexCoord;
}