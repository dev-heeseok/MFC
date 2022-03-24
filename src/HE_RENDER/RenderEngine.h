#pragma once

#include "../HE_INTERFACE/IRenderEngine.h"

class IRenderContext;
class CShaderManager;
class AFX_EXT_CLASS CRenderEngine : public IRenderEngine
{
public:
	CRenderEngine();
	virtual ~CRenderEngine();

public:
	virtual void InitScene() override;
	virtual void InitializeData() override;
	virtual void DisableRender(RenderGroup render_group) override;
	virtual void EnableOnlyAtGroup(RenderType render_type) override;

	virtual void OnDraw() override;

public:
	std::shared_ptr<IRenderManager> GetRenderManager() { return m_pRenderManager; }
	std::shared_ptr<IRenderContext> GetRenderContext() { return m_pRenderContext.lock(); }
	std::shared_ptr<CShaderManager> GetShaderManager() { return m_pShaderManager.lock(); }

	void SetRenderContext(std::shared_ptr<IRenderContext> pRenderContext) { m_pRenderContext = pRenderContext; }
	void SetShaderManager(std::shared_ptr<CShaderManager> pShaderManager) { m_pShaderManager = pShaderManager; }

private:
	std::shared_ptr<IRenderManager> m_pRenderManager = nullptr;
	std::weak_ptr<IRenderContext> m_pRenderContext;
	std::weak_ptr<CShaderManager> m_pShaderManager;
};
