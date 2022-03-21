#include "pch.h"
#include "WGLView.h"
#include "WGLRenderContext.h"
#include "WGLRenderEngine.h"
#include "ShaderManager.h"

#include "../HE_INTERFACE/NotifyDefine.h"
#include "../HE_INTERFACE/IRenderManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CWGLView::CWGLView(CWGLRenderEngine* pRenderEngine)
{
	m_pRenderEngine = std::shared_ptr<CWGLRenderEngine>(pRenderEngine);
}

CWGLView::~CWGLView()
{
}

BEGIN_MESSAGE_MAP(CWGLView, CView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

void CWGLView::OnDraw(CDC* /*pDC*/)
{
	m_pRenderEngine->OnDraw();
}

void CWGLView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	auto nf = static_cast<NotifyType>(lHint);
	switch (nf)
	{
	case NotifyType::closed_document:
	{

	}
	break;
	case NotifyType::changed_database:
	{
		auto pRenderMgr = m_pRenderEngine->GetRenderManager();
		pRenderMgr->WGLBuildBuffer();
	}
	break;
	}

	CView::OnUpdate(pSender, lHint, pHint);
}

void CWGLView::BeginWglCurrent()
{
	ASSERT(m_pRenderContext);
	m_pRenderContext->WGLBind();
}

void CWGLView::EndWglCurrent()
{
	ASSERT(m_pRenderContext);
	m_pRenderContext->WGLUnbind();
}

void CWGLView::SwapBuffer()
{
	ASSERT(m_pRenderContext);
	m_pRenderContext->SwapBuffer();
}

int CWGLView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_hDC = ::GetDC(m_hWnd);

	m_pRenderContext = std::make_shared<CWGLRenderContext>(m_hDC);
	m_pRenderContext->OnCreate();

	m_pRenderEngine->InitScene(m_pRenderContext);

	return 0;
}

void CWGLView::OnDestroy()
{
	if (m_pRenderContext)
		m_pRenderContext->OnDestroy();

	if (m_hDC != nullptr)
	{
		::ReleaseDC(m_hWnd, m_hDC);
		m_hDC = nullptr;
	}

	CView::OnDestroy();
}
