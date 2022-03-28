#pragma once

#ifndef DEF_RENDER
#define DEF_RENDER

enum class RenderType
{
	unknown = -1,
	begin_iterate = 0,

	Basic = begin_iterate,
	HelloWorld,	
	HelloTriangle,

	end_iterate
};

enum class RenderGroup
{
	unknown = -1,
	begin_iterate = 0,

	general = begin_iterate,
	learn_opengl,

	end_iterate
};

#endif // !DEF_RENDER
