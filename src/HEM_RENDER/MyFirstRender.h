#pragma once

#include "../HEM_WGL/HEMRenderBase.h"

class AFX_EXT_CLASS CMyFirstRender : public CHEMRenderBase
{
	DECLARE_DYNAMIC_RENDER(CMyFirstRender)

public:
	CMyFirstRender();
	virtual ~CMyFirstRender();

protected:
	virtual void WGLDraw() override;

};

