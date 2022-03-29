#pragma once

#include "RenderFactory.h"

class AFX_EXT_CLASS CBasicRender : public IRender
{
	DECLARE_DYNAMIC_RENDER(CBasicRender)

public:
	CBasicRender();
	virtual ~CBasicRender();

private:
	virtual void wglInitialUpdate(IRenderEngine* /*pRenderEngine*/) override {}
	virtual void wglRelease() override {}
	virtual void wglBuild() override {}
	virtual void wglDraw() override;

};

