#pragma once

enum class RenderType;
enum class RenderGroup;
class IRenderEngine;
class IRenderManager
{
public:
	virtual void wglCreateRender(IRenderEngine* pRenderEngine) = 0;
	virtual void wglClearRender() = 0;
	virtual void wglBuildRender() = 0;
	virtual void wglDrawScene() = 0;

	virtual void EnableRender(RenderType render_type) = 0;
	virtual void EnableOnlyAtGroup(RenderType render_type) = 0;
	virtual void DisableRender(RenderGroup render_group) = 0;

};