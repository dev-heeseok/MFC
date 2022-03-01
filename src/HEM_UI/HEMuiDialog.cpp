#include "pch.h"
#include "resource.h"
#include "HEMuiDialog.h"
#include "HEMuiDevDialog.h"

INT_PTR CHEMuiDialog::DoModal(CHEDocBase* pDoc, CString szDialog, WPARAM wParam, LPARAM lParam)
{
	// TODO. Parameter 처리 필요
	ASSERT(wParam == NULL && lParam == NULL);

	if (szDialog.CompareNoCase(_T("CHEMuiDevDialog")) == 0)
	{
		CHEMuiDevDialog dlg(pDoc);
		return dlg.DoModal();
	}

	return -1;
}
