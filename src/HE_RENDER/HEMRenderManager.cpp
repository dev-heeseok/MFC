#include "pch.h"
#include "HEMRenderManager.h"
#include "HEMRenderFactory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CHEMRenderManager::CHEMRenderManager()
{
}

CHEMRenderManager::~CHEMRenderManager()
{
}

void CHEMRenderManager::CreateRender()
{
	auto& instance = CHEMRenderFactory::GetInstance();

	instance.Create<IRender>(
		[&](std::type_index index, IRender* pTemplate) -> void
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

void CHEMRenderManager::WGLRenderDraw()
{
	for (auto [_, pRender] : m_mRender)
	{
		pRender->WGLDraw();
	}
}
