#pragma once

#include <memory>
#include "WGLView.h"

class CHEMRenderManager;
class AFX_EXT_CLASS CWGLSubView : public CWGLView
{
public:
	CWGLSubView();
	virtual ~CWGLSubView();


protected:
	virtual void OnDraw(CDC* /*pDC*/) override;
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	DECLARE_MESSAGE_MAP();

private:
	std::shared_ptr<CHEMRenderManager> m_pRenderManager;

};

