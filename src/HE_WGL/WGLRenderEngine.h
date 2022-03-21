#pragma once

class CShaderManager;
class IRenderManager;
class CWGLRenderContext;
class AFX_EXT_CLASS CWGLRenderEngine
{
public:
	CWGLRenderEngine();
	virtual ~CWGLRenderEngine();

public:
	virtual IRenderManager* GetRenderManager() = 0;

public:
	void InitScene(std::shared_ptr<CWGLRenderContext> pRenderContext);
	
	void OnDraw();

protected:
	std::weak_ptr<CWGLRenderContext> m_pRenderContext;
	std::shared_ptr<CShaderManager> m_pShaderManager;

};

