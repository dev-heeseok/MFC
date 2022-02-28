#pragma once

class IRender : public CObject
{
public:
	virtual void WGLDraw() = 0;
	virtual void WGLBuild() = 0;
	virtual void WGLRelease() = 0;

};