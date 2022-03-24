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
	virtual void OnInitialUpdate(IRenderEngine* pRenderEngine) = 0;

	virtual void WGLDraw() = 0;
	virtual void WGLBuild() = 0;
	virtual void WGLRelease() = 0;

};