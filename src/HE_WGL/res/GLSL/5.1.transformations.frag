#version 330 core

in vec2 o_texcoord;

out vec4 frag_color;

uniform sampler2D u_t2d_container;
uniform sampler2D u_t2d_awesome;

void main()
{
	frag_color = mix(texture(u_t2d_container, o_texcoord), texture(u_t2d_awesome, o_texcoord), 0.2);
}