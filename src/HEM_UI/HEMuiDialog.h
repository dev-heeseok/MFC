#pragma once

class CHEDocBase;
class AFX_EXT_CLASS CHEMuiDialog
{
public:
	static INT_PTR DoModal(CHEDocBase* pDoc, CString szDialog, WPARAM wParam = NULL, LPARAM lParam = NULL);

};

