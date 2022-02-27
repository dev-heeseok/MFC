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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.


	CWGLView::OnUpdate(pSender, lHint, pHint);
}
