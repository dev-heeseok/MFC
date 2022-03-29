#include "pch.h"
#include "RenderEngine.h"
#include "RenderManager.h"

#include "../HE_INTERFACE/IRenderContext.h"
#include "../HE_WGL/ShaderManager.h"

CRenderEngine::CRenderEngine()
{
	m_pRenderManager = std::make_shared<CRenderManager>();
	m_pShaderManager = std::make_shared<CShaderManager>();
}

CRenderEngine::~CRenderEngine()
{
}

void CRenderEngine::InitScene()
{
	auto pRenderContext = GetRenderContext();
	auto pRenderManager = GetRenderManager();

	pRenderContext->wglBind();
	{
		glClearColor(0.f, 0.f, 0.f, 1.f);

		pRenderManager->wglCreateRender(this);
	}
	pRenderContext->wglUnbind();
}

void CRenderEngine::InitializeData()
{
	auto pRenderContext = GetRenderContext();

	pRenderContext->wglBind();
	{
		glClearColor(0.f, 0.f, 0.f, 1.f);


	}
	pRenderContext->wglUnbind();
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

		pRenderManager->wglDrawScene();
	}
	pRenderContext->wglSwapBuffer();
	pRenderContext->wglUnbind();
}

void CRenderEngine::OnUpdate()
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
		pRenderManager->wglBuildRender();
	}
	pRenderContext->wglUnbind();
}

void CRenderEngine::OnSize(int cx, int cy)
{
	auto pRenderContext = GetRenderContext();
	if (pRenderContext == nullptr)
		return;

	pRenderContext->wglBind();
	{
		glViewport(0, 0, cx, cy);
	}
	pRenderContext->wglUnbind();
}

void CRenderEngine::OnDestroy()
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
		pRenderManager->wglClearRender();
	}
	pRenderContext->wglUnbind();
}
