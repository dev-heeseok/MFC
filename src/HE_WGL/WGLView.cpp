#include "pch.h"
#include "WGLView.h"

#include "../HE_WGL/IRenderManager.h"

CWGLView::CWGLView(IRenderManager* pRenderMgr)
{
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

	m_pRenderMgr->WGLRenderDraw();	

	WGLSwapBuffers();
	WGLEnd();
}


void CWGLView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.


	CWGLMakeView::OnUpdate(pSender, lHint, pHint);
}

int CWGLView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWGLMakeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_pRenderMgr->CreateRender();
	

	return 0;
}
