#include "pch.h"
#include "RenderManager.h"
#include "RenderFactory.h"

#include "../HE_LIB/HELib.h"

using namespace lib;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CRenderManager::CRenderManager()
{
	m_aEnable.resize(EnumIndex(RenderType::end_render));
	std::fill(m_aEnable.begin(), m_aEnable.end(), false);
}

CRenderManager::~CRenderManager()
{
}

void CRenderManager::WGLBuildBuffer()
{
	auto idxBegin = static_cast<int>(RenderType::begin_render);
	auto idxEnd = static_cast<int>(RenderType::end_render);
	for (auto idx = idxBegin; idx < idxEnd; ++idx)
	{
		auto it = m_mRender.find(static_cast<RenderType>(idx));
		if (it == m_mRender.end())
			continue;

		auto lpRender = it->second;
		lpRender->WGLBuild();
	}
}

void CRenderManager::WGLDrawScene()
{
	auto idxBegin = static_cast<int>(RenderType::begin_render);
	auto idxEnd = static_cast<int>(RenderType::end_render);
	for (auto idx = idxBegin; idx < idxEnd; ++idx)
	{
		if (m_aEnable[idx] == false)
			continue;

		auto it = m_mRender.find(static_cast<RenderType>(idx));
		if (it != m_mRender.end())
		{
			auto lpRender = it->second;
			lpRender->WGLDraw();
		}
	}
}

void CRenderManager::CreateRender(IRenderEngine* pRenderEngine)
{
	auto& instance = CRenderFactory::GetInstance();

	instance.Create<IRender>(
		[&](RenderType index, IRender* pTemplate) -> void
		{
			auto pRender = std::shared_ptr<IRender>(pTemplate);
			auto render_group = pRender->GetGroup();
			
			auto it = m_mRender.find(index);
			if (it != m_mRender.cend())
			{
				ASSERT(FALSE);
				return;
			}
			
			pRender->OnInitialUpdate(pRenderEngine);

			// TODO. general 만 Enable 상태로 셋팅, 나머지는 EnableRender 를 이용하여 직접변경
			m_aEnable[EnumIndex(index)] = render_group == RenderGroup::general;
			m_mRender.insert({ index, pRender });
		});
}

void CRenderManager::EnableRender(RenderType render_type)
{
	if (m_aEnable[EnumIndex(render_type)] == true)
		return;

	auto it = m_mRender.find(render_type);
	if (it != m_mRender.cend())
		m_aEnable[EnumIndex(render_type)] = it->second != nullptr;
}

void CRenderManager::EnableOnlyAtGroup(RenderType render_type)
{
	auto it = m_mRender.find(render_type);
	if (it == m_mRender.cend())
	{
		ASSERT(FALSE);
		return;
	}

	auto pRender = it->second;
	auto render_group = pRender->GetGroup();
	for (auto [type, lpRender] : m_mRender)
	{
		if (lpRender->GetGroup() != render_group)
			continue;

		m_aEnable[EnumIndex(type)] = type == render_type ?
			lpRender != nullptr : false;
	}
}

void CRenderManager::DisableRender(RenderGroup render_group)
{
	for (auto [type, lpRender] : m_mRender)
	{
		if (lpRender && lpRender->GetGroup() == render_group)
			m_aEnable[EnumIndex(type)] = false;
	}
}

IRender* CRenderManager::GetRender(RenderType render_type)
{
	auto it = m_mRender.find(render_type);
	return it != m_mRender.end() ? it->second.get() : nullptr;
}
