#pragma once

#include "../HE_BASE/HEDialog.h"

enum class RenderType;
class CUITutorialDlg : public CHEDialog
{
	const static UINT_PTR TIMER_REDRAW = 1;

	enum class ListCol { title = 0, desc, col_num };

public:
	CUITutorialDlg(CHEDocBase* pDoc, CWnd* pParent = nullptr);
	virtual ~CUITutorialDlg();

	enum { IDD = IDD_HEMUI_LEARN_OPENGL };

private:
	virtual void DoDataExchange(CDataExchange* pDX) override;
	virtual BOOL OnInitDialog() override;

public:
	BOOL Create(CWnd* pParentWnd = NULL);

private:
	void SetControl();
	void SetData2Dlg();

	void Apply(RenderType render_type);
	void PickRender(RenderType render_type);

private:
	afx_msg void OnDblClickedList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	DECLARE_MESSAGE_MAP();

private:
	CListCtrl m_lstTutorial;

};

