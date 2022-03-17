#include "pch.h"
#include "WGLView.h"
#include "ShaderManager.h"

#include "../HE_INTERFACE/NotifyDefine.h"
#include "../HE_INTERFACE/IRenderManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CWGLView::CWGLView(IRenderManager* pRenderMgr)
{
	m_pShaderMgr = std::make_shared<CShaderManager>();
	m_pRenderMgr = std::shared_ptr<IRenderManager>(pRenderMgr);
}

CWGLView::~CWGLView()
{
}

BEGIN_MESSAGE_MAP(CWGLView, CWGLMakeView)
	ON_WM_CREATE()
END_MESSAGE_MAP()

void CWGLView::OnDraw(CDC* /*pDC*/)
{
	WGLBegin();
	{
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		m_pRenderMgr->WGLDrawScene();
	}
	WGLSwapBuffers();
	WGLEnd();
}

void CWGLView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	auto nf = static_cast<NotifyType>(lHint);
	switch (nf)
	{
	case NotifyType::closed_document:
	{
		WGLBegin();
		{
			m_pShaderMgr->WGLClearAll();
		}
		WGLEnd();
	}
	break;
	case NotifyType::changed_database:
	{
		WGLBegin();
		{
			m_pRenderMgr->WGLBuildBuffer();
		}
		WGLEnd();
	}
	break;
	}

	CWGLMakeView::OnUpdate(pSender, lHint, pHint);
}

int CWGLView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWGLMakeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_pRenderMgr->CreateRender();

	WGLBegin();
	{
		m_pShaderMgr->WGLBuildAll();
	}
	WGLEnd();

	return 0;
}
