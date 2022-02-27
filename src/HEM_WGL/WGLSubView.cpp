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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.


	CWGLView::OnUpdate(pSender, lHint, pHint);
}

int CWGLSubView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWGLView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_pRenderManager->Create();
	


	return 0;
}
