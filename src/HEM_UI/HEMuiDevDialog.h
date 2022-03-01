#pragma once

#include "../HE_BASE/HEDialog.h"

class AFX_EXT_CLASS CHEMuiDevDialog : public CHEDialog
{
	enum class ListCol { Title = 0, Desc, Num };
	enum class ListRow;

public:
	CHEMuiDevDialog(CHEDocBase* pDoc, CWnd* pParent = nullptr);
	virtual ~CHEMuiDevDialog();

	enum { IDD = IDD_HEMUI_LEARN_OPENGL };

private:
	virtual void DoDataExchange(CDataExchange* pDX) override;
	virtual BOOL OnInitDialog() override;

public:
	BOOL Create(CWnd* pParentWnd = NULL);

private:
	void SetControl();
	void SetData2Dlg();

private:
	DECLARE_MESSAGE_MAP();

private:
	CListCtrl m_lstItem;

};

