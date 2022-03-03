#pragma once

#include "../HE_BASE/HEDialog.h"

class CHEMuiTutorialDlg : public CHEDialog
{
	enum class ListCol { title = 0, desc, col_num };
	enum class ListRow;

public:
	CHEMuiTutorialDlg(CHEDocBase* pDoc, CWnd* pParent = nullptr);
	virtual ~CHEMuiTutorialDlg();

	enum { IDD = IDD_HEMUI_LEARN_OPENGL };

private:
	virtual void DoDataExchange(CDataExchange* pDX) override;
	virtual BOOL OnInitDialog() override;

public:
	BOOL Create(CWnd* pParentWnd = NULL);

private:
	void SetControl();
	void SetData2Dlg();

	void Apply(ListRow row);

private:
	afx_msg void OnDblClickedList(NMHDR* pNMHDR, LRESULT* pResult);

	DECLARE_MESSAGE_MAP();

private:
	CListCtrl m_lstTutorial;

};

