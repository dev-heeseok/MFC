#include "pch.h"
#include "RenderEngine.h"
#include "RenderManager.h"

CRenderEngine::CRenderEngine()
{
	m_pRenderManager = std::make_shared<CRenderManager>();
}

CRenderEngine::~CRenderEngine()
{
}

IRenderManager* CRenderEngine::GetRenderManager()
{
	ASSERT(m_pRenderManager);
	return m_pRenderManager.get();
}
