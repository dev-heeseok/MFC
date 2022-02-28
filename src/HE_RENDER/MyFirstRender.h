#pragma once

#include "HEMRenderFactory.h"

class AFX_EXT_CLASS CMyFirstRender : public IRender
{
	DECLARE_DYNAMIC_RENDER(CMyFirstRender)

public:
	CMyFirstRender();
	virtual ~CMyFirstRender();

protected:
	virtual void WGLDraw() override;
	virtual void WGLBuild() override;
	virtual void WGLRelease() override;

};

