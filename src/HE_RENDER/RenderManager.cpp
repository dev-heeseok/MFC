#include "pch.h"
#include "RenderManager.h"
#include "RenderFactory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CRenderManager::CRenderManager()
{
}

CRenderManager::~CRenderManager()
{
}

void CRenderManager::CreateRender()
{
	auto& instance = CRenderFactory::GetInstance();

	instance.Create<IRender>(
		[&](RenderType index, IRender* pTemplate) -> void
		{
			auto pRender = std::shared_ptr<IRender>(pTemplate);

			auto it = m_mRender.find(index);
			if (it != m_mRender.cend())
			{
				ASSERT(FALSE);
				return;
			}

			m_mRender.insert({ index, pRender });
		});
}

void CRenderManager::WGLBuildBuffer()
{
	auto idxBegin = static_cast<int>(RenderType::begin_render);
	auto idxEnd = static_cast<int>(RenderType::end_render);
	for(auto idx = idxBegin; idx < idxEnd; ++idx)
	{
		auto it = m_mRender.find(static_cast<RenderType>(idx));
		if (it == m_mRender.end())
			continue;

		auto pRender = it->second;
		pRender->WGLBuild();
	}
}

void CRenderManager::WGLDrawScene()
{
	auto idxBegin = static_cast<int>(RenderType::begin_render);
	auto idxEnd = static_cast<int>(RenderType::end_render);
	for (auto idx = idxBegin; idx < idxEnd; ++idx)
	{
		auto it = m_mRender.find(static_cast<RenderType>(idx));
		if (it == m_mRender.end())
			continue;

		auto pRender = it->second;
		pRender->WGLDraw();
	}
}

IRender* CRenderManager::GetRender(RenderType render_type)
{
	auto it = m_mRender.find(render_type);
	return it != m_mRender.end() ? it->second.get() : nullptr;
}
