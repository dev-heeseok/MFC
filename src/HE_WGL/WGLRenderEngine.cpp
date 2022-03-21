#include "pch.h"
#include "WGLRenderEngine.h"
#include "WGLRenderContext.h"
#include "ShaderManager.h"

#include "../HE_INTERFACE/IRenderManager.h"

CWGLRenderEngine::CWGLRenderEngine()
{
	m_pShaderManager = std::make_shared<CShaderManager>();
}

CWGLRenderEngine::~CWGLRenderEngine()
{
}

void CWGLRenderEngine::InitScene(std::shared_ptr<CWGLRenderContext> pRenderContext)
{
	m_pRenderContext = pRenderContext;

	if (auto pRenderMgr = GetRenderManager())
		pRenderMgr->CreateRender();

	pRenderContext->WGLBind();
	{
		m_pShaderManager->WGLBuildAll();


	}
	pRenderContext->WGLUnbind();
}

void CWGLRenderEngine::OnDraw()
{
	auto pRenderContext = m_pRenderContext.lock();
	auto pRenderMgr = GetRenderManager();

	pRenderContext->WGLBind();
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		pRenderMgr->WGLDrawScene();
	}
	pRenderContext->SwapBuffer();
	pRenderContext->WGLUnbind();
}
