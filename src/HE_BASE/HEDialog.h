#pragma once

class CHEDocBase;
class AFX_EXT_CLASS CHEDialog : public CDialog
{
public:
	CHEDialog(CHEDocBase* pDoc, UINT uiResID, CWnd* pParent = nullptr);
	virtual ~CHEDialog();

protected:
	virtual void DoDataExchange(CDataExchange* pDX) override;
	virtual BOOL OnInitDialog() override;
	virtual void OnOK() override;
	virtual void OnCancel() override;
	virtual void PostNcDestroy() override;

	virtual BOOL Create(UINT nIDTemplate, CWnd* pParentWnd = NULL) override;

protected:
	CHEDocBase* GetDoc() { return m_pMyDoc; }

protected:
	afx_msg void OnNcDestroy();
	afx_msg void OnDestroy();

	DECLARE_MESSAGE_MAP();

private:
	CHEDocBase* m_pMyDoc = nullptr;
	BOOL m_bModeless = FALSE;

};

