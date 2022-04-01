#version 330 core

in vec3 o_color;
in vec2 o_texel;

out vec4 frag_color;

uniform sampler2D u_t2d_wall;
uniform sampler2D u_t2d_awesome;

void main()
{
	vec4 local_color = vec4(o_color, 1.0f);
	vec4 tex_wall = texture(u_t2d_wall, o_texel);
	vec4 tex_awesome = texture(u_t2d_awesome, o_texel);

	frag_color = local_color * mix(tex_wall, tex_awesome, 0.4);
}