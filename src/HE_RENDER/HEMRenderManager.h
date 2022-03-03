#pragma once

#include <typeindex>
#include <unordered_map>

#include "../HE_INTERFACE/IRender.h"
#include "../HE_INTERFACE/IRenderManager.h"

class AFX_EXT_CLASS CHEMRenderManager : public IRenderManager
{
	using RENDER_BUFFER = std::shared_ptr<IRender>;
	using RENDER_MAP = std::unordered_map<std::type_index, RENDER_BUFFER>;

public:
	CHEMRenderManager();
	virtual ~CHEMRenderManager();

public:
	virtual void CreateRender() override;

	virtual void WGLBuildBuffer() override;
	virtual void WGLDrawScene() override;

private:
	RENDER_MAP m_mRender;

};

