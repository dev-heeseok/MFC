#pragma once

#ifndef DEF_SHADER
#define DEF_SHADER

enum class ProgramType
{
	unknown = -1,
	begin_iterate = 0,

	scene = begin_iterate,
	tutorial_triangle,
	tutorial_shader,
	tutorial_textures,

	end_iterate
};

#endif // !DEF_SHADER
