#pragma once

#include <typeindex>
#include <unordered_map>

#include "../HE_INTERFACE/IRender.h"
#include "../HE_INTERFACE/IRenderManager.h"

class AFX_EXT_CLASS CRenderManager : public IRenderManager
{
	using RENDER_MAP = std::unordered_map<RenderType, std::shared_ptr<IRender>>;

public:
	CRenderManager();
	virtual ~CRenderManager();

public:
	virtual void CreateRender() override;

	virtual void WGLBuildBuffer() override;
	virtual void WGLDrawScene() override;

public:
	IRender* GetRender(RenderType render_type);

private:
	RENDER_MAP m_mRender;

};

