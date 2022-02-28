#pragma once

class IRenderManager
{
public:
	IRenderManager() = default;
	virtual ~IRenderManager() = default;

public:
	virtual void CreateRender() = 0;

	virtual void WGLRenderDraw() = 0;

};