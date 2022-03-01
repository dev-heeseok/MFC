#include "pch.h"
#include "HEViewBase.h"

#include "../HE_RENDER/HEMRenderManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CHEViewBase::CHEViewBase()
	: CWGLView(new CHEMRenderManager)
{
}

CHEViewBase::~CHEViewBase()
{
}

BEGIN_MESSAGE_MAP(CHEViewBase, CWGLView)
END_MESSAGE_MAP()


void CHEViewBase::OnDraw(CDC* pDC)
{
	CWGLView::OnDraw(pDC);
}

void CHEViewBase::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	CWGLView::OnUpdate(pSender, lHint, pHint);
}
