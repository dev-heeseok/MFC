#pragma once

class IRenderManager;
class CWGLRenderEngine;
class CWGLRenderContext;
class AFX_EXT_CLASS CWGLView : public CView
{
public:
	CWGLView(CWGLRenderEngine* pRenderEngine);
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
	std::shared_ptr<CWGLRenderContext> m_pRenderContext = nullptr;
	std::shared_ptr<CWGLRenderEngine> m_pRenderEngine = nullptr;


};

