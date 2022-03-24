#pragma once

#include "RenderFactory.h"

class AFX_EXT_CLASS CHelloWorldRender : public IRender
{
	DECLARE_DYNAMIC_RENDER(CHelloWorldRender)

public:
	CHelloWorldRender();
	virtual ~CHelloWorldRender();

protected:
	virtual void OnInitialUpdate(IRenderEngine* pRenderEngine) override;

	virtual void WGLDraw() override;
	virtual void WGLBuild() override;
	virtual void WGLRelease() override;

};

