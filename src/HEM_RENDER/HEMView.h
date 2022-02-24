#pragma once

#include "WGLView.h"

class AFX_EXT_CLASS CHEMView : public CWGLView
{
public:
	CHEMView();
	virtual ~CHEMView();


protected:
	virtual void OnDraw(CDC* /*pDC*/) override;
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);

protected:

	DECLARE_MESSAGE_MAP();

};

