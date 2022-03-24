#pragma once

class IRenderEngine;
class IRenderContext;
class AFX_EXT_CLASS CWGLView : public CView
{
public:
	CWGLView(IRenderEngine* pRenderEngine);
	virtual ~CWGLView();

protected:
	virtual void OnDraw(CDC* /*pDC*/) override;
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) override;

public:
	void BeginWglCurrent();
	void EndWglCurrent();
	void SwapBuffer();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();

	DECLARE_MESSAGE_MAP();

protected:
	HDC m_hDC = nullptr;

	std::shared_ptr<IRenderEngine> m_pRenderEngine = nullptr;
	std::shared_ptr<IRenderContext> m_pRenderContext = nullptr;

};

