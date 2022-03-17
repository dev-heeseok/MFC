#pragma once

enum class RenderType;
enum class RenderGroup;
class IRenderManager
{
public:
	IRenderManager() = default;
	virtual ~IRenderManager() = default;

public:
	virtual void WGLBuildBuffer() = 0;
	virtual void WGLDrawScene() = 0;

	virtual void CreateRender() = 0;
	virtual void EnableRender(RenderType render_type) = 0;
	virtual void EnableOnlyFromGroup(RenderType render_type) = 0;
	virtual void DisableRender(RenderGroup render_group) = 0;
};