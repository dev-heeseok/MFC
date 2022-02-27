#pragma once

#include "../HEM_WGL/WGLSubView.h"

class AFX_EXT_CLASS CHEMViewBase : public CWGLSubView
{
public:
	CHEMViewBase();
	virtual ~CHEMViewBase();

protected:
	virtual void OnDraw(CDC* pDC) override;
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

protected:
	DECLARE_MESSAGE_MAP();

};

