#pragma once

#include "../HE_WGL/WGLRenderEngine.h"

class AFX_EXT_CLASS CRenderEngine : public CWGLRenderEngine
{
public:
	CRenderEngine();
	virtual ~CRenderEngine();

public:
	virtual IRenderManager* GetRenderManager() override;


private:
	std::shared_ptr<IRenderManager> m_pRenderManager = nullptr;

};

