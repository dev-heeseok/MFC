#include "pch.h"
#include "RenderEngine.h"
#include "RenderManager.h"

#include "../HE_INTERFACE/IRenderContext.h"

CRenderEngine::CRenderEngine()
{
	m_pRenderManager = std::make_shared<CRenderManager>();
}

CRenderEngine::~CRenderEngine()
{
}

void CRenderEngine::InitScene()
{
	if (auto pRenderManager = GetRenderManager())
		pRenderManager->CreateRender(this);

	InitializeData();
}

void CRenderEngine::InitializeData()
{
	// TODO. default 
	if (auto pRenderContext = GetRenderContext())
	{
		pRenderContext->wglBind();
		{
			glClearColor(0.f, 0.f, 0.f, 1.f);
		}
		pRenderContext->wglUnbind();
	}

}

void CRenderEngine::DisableRender(RenderGroup render_group)
{
	auto pRenderManager = GetRenderManager();
	if (pRenderManager)
		pRenderManager->DisableRender(render_group);
}

void CRenderEngine::EnableOnlyAtGroup(RenderType render_type)
{
	auto pRenderManager = GetRenderManager();
	if (pRenderManager)
		pRenderManager->EnableOnlyAtGroup(render_type);
}

void CRenderEngine::OnDraw()
{
	auto pRenderContext = GetRenderContext();
	auto pRenderManager = GetRenderManager();
	if (pRenderContext == nullptr || pRenderManager == nullptr)
	{
		ASSERT(FALSE);
		return;
	}

	pRenderContext->wglBind();
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		pRenderManager->WGLDrawScene();
	}
	pRenderContext->wglSwapBuffer();
	pRenderContext->wglUnbind();
}
