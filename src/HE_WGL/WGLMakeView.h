#pragma once

class CWGLMakeView : public CView
{
public:
	CWGLMakeView();
	virtual ~CWGLMakeView();

protected:
	void WGLBegin();
	void WGLEnd();
	void WGLSwapBuffers();
	void WGLInitialPalette();

private:
	void CreateWGL();
	void DeleteWGL();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg BOOL OnQueryNewPalette();
	afx_msg void OnPaletteChanged(CWnd* pFocusWnd);

	DECLARE_MESSAGE_MAP();

private:
	HDC m_hDC;
	HGLRC m_hRC;
	CPalette m_Palette;

};

