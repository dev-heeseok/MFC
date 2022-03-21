#include "pch.h"
#include "HEViewBase.h"

#include "../HE_RENDER/RenderEngine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CHEViewBase::CHEViewBase()
	: CWGLView(new CRenderEngine)
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

void CHEViewBase::InitScene()
{
	if (m_pRenderEngine)
		m_pRenderEngine->InitScene(m_pRenderContext);
}

IRenderManager* CHEViewBase::GetRenderManager()
{
	return m_pRenderEngine->GetRenderManager();
}
