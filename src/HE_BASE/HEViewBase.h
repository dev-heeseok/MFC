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
	IRenderEngine* GetRenderEngine();
	IRenderContext* GetRenderContext();

	void InitScene();

protected:
	DECLARE_MESSAGE_MAP();

};

