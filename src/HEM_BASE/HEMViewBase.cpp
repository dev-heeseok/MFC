#include "pch.h"
#include "HEMViewBase.h"

CHEMViewBase::CHEMViewBase()
{
}

CHEMViewBase::~CHEMViewBase()
{
}

BEGIN_MESSAGE_MAP(CHEMViewBase, CWGLSubView)
END_MESSAGE_MAP()


void CHEMViewBase::OnDraw(CDC* pDC)
{
	CWGLSubView::OnDraw(pDC);
}

void CHEMViewBase::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	CWGLSubView::OnUpdate(pSender, lHint, pHint);
}
