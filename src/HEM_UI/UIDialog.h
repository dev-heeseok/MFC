#pragma once

class CHEDocBase;
class AFX_EXT_CLASS CUIDialog
{
public:
	static INT_PTR DoModal(CHEDocBase* pDoc, CString szDialog, WPARAM wParam = NULL, LPARAM lParam = NULL);
	static INT_PTR DoModeless(CHEDocBase* pDoc, CString szDialog, WPARAM wParam = NULL, LPARAM lParam = NULL);

};

