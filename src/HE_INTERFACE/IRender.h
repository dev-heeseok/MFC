#pragma once

enum class RenderType;
class IRender : public CObject
{
public: // TODO. implementation from macro
	virtual RenderType GetType() = 0;

public:
	virtual void WGLDraw() = 0;
	virtual void WGLBuild() = 0;
	virtual void WGLRelease() = 0;

};