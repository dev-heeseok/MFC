#include "pch.h"
#include "WGLSubView.h"
#include "HEMRenderManager.h"

CWGLSubView::CWGLSubView()
{
	m_pRenderManager = std::make_shared<CHEMRenderManager>();
}

CWGLSubView::~CWGLSubView()
{
}

BEGIN_MESSAGE_MAP(CWGLSubView, CWGLView)
	ON_WM_CREATE()
END_MESSAGE_MAP()


void CWGLSubView::OnDraw(CDC* /*pDC*/)
{
	BeginWGL();

	m_pRenderManager->WGLRenderDraw();	

	SwapBuffers();

	EndWGL();
}


void CWGLSubView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.


	CWGLView::OnUpdate(pSender, lHint, pHint);
}

int CWGLSubView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWGLView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_pRenderManager->Create();
	


	return 0;
}
