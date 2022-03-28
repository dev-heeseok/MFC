#pragma once

#ifndef DEF_SHADER
#define DEF_SHADER

enum class ProgramType
{
	unknown = -1,
	begin_iterate = 0,

	scene = begin_iterate,
	triangle,


	end_iterate
};

#endif // !DEF_SHADER
