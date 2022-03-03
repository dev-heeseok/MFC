#version 330 core

in vec2 aTexCoordinate;

uniform sampler2D ScreenTex2D;

out vec4 FragColor;

void main()
{
	FragColor = vec4(texture(ScreenTex2D, aTexCoordinate).rgb, 1.f);
}