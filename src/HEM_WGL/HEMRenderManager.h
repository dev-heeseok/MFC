#pragma once

#include <memory>
#include <typeindex>
#include <unordered_map>

class CHEMRenderBase;
class CHEMRenderManager
{
	using RENDER_BUFFER = std::shared_ptr<CHEMRenderBase>;
	using RENDER_MAP = std::unordered_map<std::type_index, RENDER_BUFFER>;

public:
	CHEMRenderManager();
	virtual ~CHEMRenderManager();

public:
	void Create();

	void WGLRenderDraw();


private:
	RENDER_MAP m_mRender;

};

