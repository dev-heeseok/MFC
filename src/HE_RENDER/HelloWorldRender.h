#pragma once

#include "LearnOpenGLRender.h"

class AFX_EXT_CLASS CHelloWorldRender : public CLearnOpenGLRender
{
	DECLARE_DYNAMIC_RENDER(CHelloWorldRender);

public:
	CHelloWorldRender();
	virtual ~CHelloWorldRender();

protected:
	virtual void wglInitialUpdate(IRenderEngine* /*pRenderEngine*/) override {}
	virtual void wglRelease() override {}
	virtual void wglBuild() override {}
	virtual void wglDraw() override;

};

