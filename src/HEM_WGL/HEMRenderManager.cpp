#include "pch.h"
#include "HEMRenderManager.h"
#include "HEMRenderFactory.h"
#include "HEMRenderBase.h"

CHEMRenderManager::CHEMRenderManager()
{
}

CHEMRenderManager::~CHEMRenderManager()
{
}

void CHEMRenderManager::Create()
{
	auto& instance = CHEMRenderFactory::GetInstance();

	//instance.Registry(std::type_index(typeid(CHEMFirstRender)), RUNTIME_CLASS(CHEMFirstRender));

	instance.Create<CHEMRenderBase>(
		[&](std::type_index index, CHEMRenderBase* pTemplate) -> void
		{
			auto pRender = std::shared_ptr<CHEMRenderBase>(pTemplate);

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
