#include "pch.h"
#include "resource.h"
#include "HEMuiTutorialDlg.h"

#include "../HE_LIB/HELib.h"
#include "../HE_INTERFACE/NotifyDefine.h"
#include "../HE_BASE/HEDocBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace lib;

enum class CHEMuiTutorialDlg::ListRow
{
	first_render = 0,

	row_num
};

CHEMuiTutorialDlg::CHEMuiTutorialDlg(CHEDocBase* pDoc, CWnd* pParent)
	: CHEDialog(pDoc, CHEMuiTutorialDlg::IDD, pParent)
{
}

CHEMuiTutorialDlg::~CHEMuiTutorialDlg()
{
}

void CHEMuiTutorialDlg::DoDataExchange(CDataExchange* pDX)
{
	CHEDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_HEMUI_LIST, m_lstTutorial);
}

BEGIN_MESSAGE_MAP(CHEMuiTutorialDlg, CHEDialog)
	ON_NOTIFY(NM_DBLCLK, IDC_HEMUI_LIST, OnDblClickedList)
END_MESSAGE_MAP()

BOOL CHEMuiTutorialDlg::OnInitDialog()
{
	CHEDialog::OnInitDialog();

	SetControl();

	SetData2Dlg();

	return TRUE;
}

BOOL CHEMuiTutorialDlg::Create(CWnd* pParentWnd)
{
	return CHEDialog::Create(CHEMuiTutorialDlg::IDD, pParentWnd);
}

void CHEMuiTutorialDlg::SetControl()
{
	CRect rect;
	m_lstTutorial.GetWindowRect(rect);

	double width = rect.Width() * 0.98;
	m_lstTutorial.InsertColumn(EnumIndex(ListCol::title), _T("Title"), LVCFMT_LEFT, static_cast<int>(width * 0.6));
	m_lstTutorial.InsertColumn(EnumIndex(ListCol::desc), _T("Desc"), LVCFMT_LEFT, static_cast<int>(width * 0.4));

	auto dwStyle = m_lstTutorial.GetExtendedStyle();
	m_lstTutorial.SetExtendedStyle(dwStyle | LVS_EX_SINGLEROW | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
}

void CHEMuiTutorialDlg::SetData2Dlg()
{
	auto lambda_add = [](auto& lstctrl, auto strTitle, auto strDesc, auto itemData)
	{
		auto itemCount = lstctrl.GetItemCount();
		auto item = lstctrl.InsertItem(itemCount, strTitle);
		lstctrl.SetItemText(item, EnumIndex(ListCol::desc), strDesc);
		lstctrl.SetItemData(item, static_cast<DWORD_PTR>(itemData));
	};

	lambda_add(m_lstTutorial, _T("My First Render"), _T("Tutorial"), EnumIndex(ListRow::first_render));
}

void CHEMuiTutorialDlg::Apply(ListRow row)
{
	auto pDoc = GetDoc();

	switch (row)
	{
	case ListRow::first_render:
	{
		pDoc->UpdateAllViews(NULL, static_cast<WPARAM>(ViewNotify::changed_database), 0);
	}
	break;
	}
}


void CHEMuiTutorialDlg::OnDblClickedList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	if (pNMItemActivate->iItem != -1)
	{
		auto itemData = m_lstTutorial.GetItemData(pNMItemActivate->iItem);
		Apply(static_cast<ListRow>(itemData));
	}

	*pResult = 0;
}
