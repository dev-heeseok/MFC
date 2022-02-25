#pragma once

class CHEMDocBase;
class AFX_EXT_CLASS CHEMDialog : public CDialog
{
public:
	CHEMDialog(CHEMDocBase* pDoc, UINT uiResID, CWnd* pParent = nullptr);
	virtual ~CHEMDialog();

protected:
	virtual void DoDataExchange(CDataExchange* pDX) override;
	virtual BOOL OnInitDialog() override;
	virtual void OnOK() override;
	virtual void OnCancel() override;
	virtual void PostNcDestroy() override;

	virtual BOOL Create(UINT nIDTemplate, CWnd* pParentWnd = NULL) override;

protected:
	afx_msg void OnNcDestroy();
	afx_msg void OnDestroy();

	DECLARE_MESSAGE_MAP();

private:
	BOOL m_bModeless = FALSE;

	CHEMDocBase* m_pMyDoc = nullptr;	

};

