#pragma once

#ifndef DEF_RENDER
#define DEF_RENDER

enum class RenderType
{
	unknown = -1,
	begin_render = 0,

	HelloWorld = begin_render,
	Basic,

	end_render
};

enum class RenderGroup
{
	unknown = -1,
	begin_group = 0,

	general = begin_group,
	learn_opengl,

	end_group
};

#endif // !DEF_RENDER
