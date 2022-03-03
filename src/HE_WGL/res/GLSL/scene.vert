#version 330 core

layout (location = 0) in vec3 attrPos;
layout (location = 1) in vec2 attrTexCord;

out vec2 aTexCoordinate;

void main()
{
	gl_Position = vec4(attrPos.x, attrPos.y, 0.f, 1.f);
	aTexCoordinate = attrTexCord;
}