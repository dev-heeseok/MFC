#pragma once

#include <memory>
#include <typeindex>
#include <unordered_map>

#include "../HE_WGL/IRender.h"
#include "../HE_WGL/IRenderManager.h"

class AFX_EXT_CLASS CHEMRenderManager : public IRenderManager
{
	using RENDER_BUFFER = std::shared_ptr<IRender>;
	using RENDER_MAP = std::unordered_map<std::type_index, RENDER_BUFFER>;

public:
	CHEMRenderManager();
	virtual ~CHEMRenderManager();

public:
	virtual void CreateRender() override;

	virtual void WGLRenderDraw() override;

private:
	RENDER_MAP m_mRender;

};

