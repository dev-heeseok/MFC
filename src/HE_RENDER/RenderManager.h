#pragma once

#include <typeindex>
#include <unordered_map>

#include "../HE_INTERFACE/IRender.h"
#include "../HE_INTERFACE/IRenderManager.h"

class CWGLViewHandler;
class AFX_EXT_CLASS CRenderManager : public IRenderManager
{
	using RENDER_MAP = std::unordered_map<RenderType, std::shared_ptr<IRender>>;

public:
	CRenderManager();
	virtual ~CRenderManager();

public:
	virtual void wglCreateRender(IRenderEngine* pRenderEngine) override;
	virtual void wglClearRender() override;
	virtual void wglBuildRender() override;
	virtual void wglDrawScene() override;

protected:
	virtual void EnableRender(RenderType render_type) override;
	virtual void EnableOnlyAtGroup(RenderType render_type) override;
	virtual void DisableRender(RenderGroup render_group)  override;

public:
	IRender* GetRender(RenderType render_type);

private:
	RENDER_MAP m_mRender;

	std::vector<bool> m_aEnable;
};

