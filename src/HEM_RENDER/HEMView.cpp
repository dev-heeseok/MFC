#include "pch.h"
#include "HEMView.h"

CHEMView::CHEMView()
{
}

CHEMView::~CHEMView()
{
}

BEGIN_MESSAGE_MAP(CHEMView, CWGLView)
END_MESSAGE_MAP()


void CHEMView::OnDraw(CDC* /*pDC*/)
{
	BeginWGL();



	SwapBuffers();

	EndWGL();
}


void CHEMView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.


	CWGLView::OnUpdate(pSender, lHint, pHint);
}
