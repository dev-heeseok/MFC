#pragma once

#include <memory>

#include "WGLMakeView.h"

class IRenderManager;
class AFX_EXT_CLASS CWGLView : public CWGLMakeView
{
public:
	CWGLView(IRenderManager* pRenderMgr);
	virtual ~CWGLView();

protected:
	virtual void OnDraw(CDC* /*pDC*/) override;
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	DECLARE_MESSAGE_MAP();

protected:
	std::shared_ptr<IRenderManager> m_pRenderMgr;

};

