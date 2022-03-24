#pragma once

#include "RenderFactory.h"

class AFX_EXT_CLASS CHelloTriangleRender : public IRender
{
	DECLARE_DYNAMIC_RENDER(CHelloTriangleRender)

public:
	CHelloTriangleRender();
	virtual ~CHelloTriangleRender();

private:
	virtual void OnInitialUpdate(IRenderEngine* pRenderEngine) override;

	virtual void WGLDraw() override;
	virtual void WGLBuild() override;
	virtual void WGLRelease() override;
};

