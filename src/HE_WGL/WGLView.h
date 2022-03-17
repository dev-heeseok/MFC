#pragma once

#include "WGLMakeView.h"

class IRenderManager;
class CShaderManager;
class AFX_EXT_CLASS CWGLView : public CWGLMakeView
{
public:
	CWGLView(IRenderManager* pRenderMgr);
	virtual ~CWGLView();

protected:
	virtual void OnDraw(CDC* /*pDC*/) override;
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

public:
	IRenderManager* GetRenderManager() { return m_pRenderMgr.get(); }

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	DECLARE_MESSAGE_MAP();

protected:
	std::shared_ptr<CShaderManager> m_pShaderMgr;
	std::shared_ptr<IRenderManager> m_pRenderMgr;

};

