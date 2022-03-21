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

public:
	void InitScene();

	IRenderManager* GetRenderManager();


protected:
	DECLARE_MESSAGE_MAP();

};

