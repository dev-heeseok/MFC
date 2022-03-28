#pragma once

#include "../HE_INTERFACE/IRenderEngine.h"

class IRenderContext;
class IRenderManager;
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
	virtual void OnUpdate() override;
	virtual void OnSize(int cx, int cy) override;
	virtual void OnDestroy() override;

public:
	void SetRenderContext(std::shared_ptr<IRenderContext> pRenderContext) { m_pRenderContext = pRenderContext; }

	std::shared_ptr<IRenderContext> GetRenderContext() { return m_pRenderContext.lock(); }
	std::shared_ptr<IRenderManager> GetRenderManager() { return m_pRenderManager; }
	std::shared_ptr<CShaderManager> GetShaderManager() { return m_pShaderManager; }

private:
	std::weak_ptr<IRenderContext> m_pRenderContext;
	std::shared_ptr<IRenderManager> m_pRenderManager = nullptr;
	std::shared_ptr<CShaderManager> m_pShaderManager = nullptr;

};
