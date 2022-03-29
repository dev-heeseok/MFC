#pragma once

#ifndef DEF_RENDER
#define DEF_RENDER

enum class RenderType
{
	unknown = -1,
	begin_iterate = 0,

	Tutorial_Basic = begin_iterate,
	Tutorial_HelloWorld,	
	Tutorial_HelloTriangle,
	Tutorial_Shaders,
	Tutorial_Textures,

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
