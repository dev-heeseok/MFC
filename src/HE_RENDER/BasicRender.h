#pragma once

#include "RenderFactory.h"

class AFX_EXT_CLASS CBasicRender : public IRender
{
	DECLARE_DYNAMIC_RENDER(CBasicRender)

public:
	CBasicRender();
	virtual ~CBasicRender();

private:
	virtual void WGLDraw() override;
	virtual void WGLBuild() override;
	virtual void WGLRelease() override;



};

