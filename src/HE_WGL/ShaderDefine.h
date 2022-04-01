#pragma once

#ifndef DEF_SHADER
#define DEF_SHADER

enum class ProgramType
{
	unknown = -1,
	begin_iterate = 0,

	scene = begin_iterate,
	tutorial_2_1_triangle,
	tutorial_3_3_shaders,
	tutorial_4_2_textures,
	tutorial_5_1_transform,

	end_iterate
};

#endif // !DEF_SHADER
