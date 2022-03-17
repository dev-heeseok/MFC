#include "pch.h"
#include "resource.h"
#include "UIDialog.h"
#include "UITutorialDlg.h"
#include "HEMuiDevelopDlg.h"

#include "../HE_BASE/HEViewBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

INT_PTR CUIDialog::DoModal(CHEDocBase* pDoc, CString szDialog, WPARAM wParam, LPARAM lParam)
{
	// TODO. Parameter ó�� �ʿ�
	ASSERT(wParam == NULL && lParam == NULL);

	auto pApp = AfxGetApp();
	auto pMainWnd = pApp->GetMainWnd();

	if (szDialog.CompareNoCase(_T("CUITutorialDlg")) == 0)
	{
		CUITutorialDlg dlg(pDoc, pMainWnd);
		return dlg.DoModal();
	}

	return -1;
}

INT_PTR CUIDialog::DoModeless(CHEDocBase* pDoc, CString szDialog, WPARAM wParam, LPARAM lParam)
{
	// TODO. Parameter ó�� �ʿ�
	ASSERT(wParam == NULL && lParam == NULL);

	auto pApp = AfxGetApp();
	auto pMainWnd = static_cast<CMDIFrameWnd*>(pApp->GetMainWnd());
	auto pChildWnd = static_cast<CMDIChildWnd*>(pMainWnd->GetActiveFrame());

	auto pView = pChildWnd->GetActiveView();
	if (pView == nullptr || pView->IsKindOf(RUNTIME_CLASS(CHEViewBase)) == FALSE)
	{
		ASSERT(FALSE);
		return -1;
	}

	CRect rect;
	pView->GetWindowRect(rect);

	if (szDialog.CompareNoCase(_T("CHEMuiDevelopDlg")) == 0)
	{
		if (auto pDialog = new CHEMuiDevelopDlg(pDoc, pMainWnd))
		{
			pDialog->Create(pMainWnd);
			pDialog->SetWindowPos(NULL, rect.left, rect.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
			pDialog->ShowWindow(SW_SHOW);
		}
	}

	return 0;
}
