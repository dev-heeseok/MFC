#pragma once

enum class RenderType;
enum class RenderGroup;
class IRenderEngine;
class IRender : public CObject
{
public: // TODO. implementation from macro
	virtual RenderType GetType() = 0;
	virtual RenderGroup GetGroup() = 0;

public:
	virtual void wglInitialUpdate(IRenderEngine* pRenderEngine) = 0;
	virtual void wglRelease() = 0;
	virtual void wglBuild() = 0;
	virtual void wglDraw() = 0;

};