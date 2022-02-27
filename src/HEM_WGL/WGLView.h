#pragma once

class CWGLView : public CView
{
public:
	CWGLView();
	virtual ~CWGLView();

protected:
	void BeginWGL();
	void EndWGL();
	void SwapBuffers();

private:
	void CreateWGL();
	void DeleteWGL();

	void GLInitialPalette();

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

