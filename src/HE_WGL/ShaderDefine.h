#pragma once

#ifndef DEF_SHADER
#define DEF_SHADER

enum class ProgramType
{
	unknown = -1,
	begin_iterate = 0,

	scene = begin_iterate,
	tutorial_2_1_hello_triangle,
	tutorial_3_3_shaders,
	tutorial_4_2_textures,
	tutorial_5_1_transformations,
	tutorial_6_1_coordinate_systems,
	tutorial_7_1_camera,

	end_iterate
};

#endif // !DEF_SHADER
