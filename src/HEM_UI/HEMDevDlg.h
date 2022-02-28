#pragma once

#include "resource.h"
#include "../HE_BASE/HEDialog.h"

class AFX_EXT_CLASS CHEMDevDlg : public CHEDialog
{
public:
	CHEMDevDlg(CHEDocBase* pDoc, CWnd* pParent = nullptr);
	virtual ~CHEMDevDlg();

	enum { IDD = IDD_HEMUI_DEVELOP };

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

};

