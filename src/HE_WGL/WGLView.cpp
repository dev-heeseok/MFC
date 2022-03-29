#include "pch.h"
#include "WGLView.h"
#include "WGLRenderContext.h"
#include "ShaderManager.h"

#include "../HE_INTERFACE/NotifyDefine.h"
#include "../HE_INTERFACE/IRenderEngine.h"
#include "../HE_INTERFACE/IRenderManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CWGLView::CWGLView(IRenderEngine* pRenderEngine)
{
	m_pRenderEngine = std::shared_ptr<IRenderEngine>(pRenderEngine);
}

CWGLView::~CWGLView()
{
}

BEGIN_MESSAGE_MAP(CWGLView, CView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

void CWGLView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	auto nf = static_cast<NotifyType>(lHint);
	switch (nf)
	{
	case NotifyType::closed_document:
	{
		m_pRenderEngine->OnDestroy();
	}
	break;
	case NotifyType::changed_database:
	{
		m_pRenderEngine->OnUpdate();
	}
	break;
	}

	CView::OnUpdate(pSender, lHint, pHint);
}

void CWGLView::OnDraw(CDC* /*pDC*/)
{
	m_pRenderEngine->OnDraw();
}

void CWGLView::BeginWglCurrent()
{
	ASSERT(m_pRenderContext);
	m_pRenderContext->wglBind();
}

void CWGLView::EndWglCurrent()
{
	ASSERT(m_pRenderContext);
	m_pRenderContext->wglUnbind();
}

void CWGLView::SwapBuffer()
{
	ASSERT(m_pRenderContext);
	m_pRenderContext->wglSwapBuffer();
}

int CWGLView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_hDC = ::GetDC(m_hWnd);

	auto pRenderContext = std::make_shared<CWGLRenderContext>(m_hDC);
	
	if (pRenderContext)
		pRenderContext->OnCreate();

	m_pRenderContext = pRenderContext;

	return 0;
}

void CWGLView::OnDestroy()
{
	auto pRenderContext = std::static_pointer_cast<CWGLRenderContext>(m_pRenderContext);
	
	if (pRenderContext)
		pRenderContext->OnDestroy();

	if (m_hDC != nullptr)
	{
		::ReleaseDC(m_hWnd, m_hDC);
		m_hDC = nullptr;
	}

	CView::OnDestroy();
}

void CWGLView::OnSize(UINT nType, int cx, int cy)
{
	m_pRenderEngine->OnSize(cx, cy);

	CView::OnSize(nType, cx, cy);
}

BOOL CWGLView::OnEraseBkgnd(CDC* /*pDC*/)
{
	return TRUE; 
}
