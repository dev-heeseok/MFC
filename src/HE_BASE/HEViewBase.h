#pragma once

#include "../HE_WGL/WGLView.h"

class AFX_EXT_CLASS CHEViewBase : public CWGLView
{
public:
	CHEViewBase();
	virtual ~CHEViewBase();

protected:
	virtual void OnDraw(CDC* pDC) override;
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

protected:
	DECLARE_MESSAGE_MAP();

};

