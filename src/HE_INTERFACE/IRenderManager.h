#pragma once

class IRenderManager
{
public:
	IRenderManager() = default;
	virtual ~IRenderManager() = default;

public:
	virtual void CreateRender() = 0;

	virtual void WGLBuildBuffer() = 0;
	virtual void WGLDrawScene() = 0;
};