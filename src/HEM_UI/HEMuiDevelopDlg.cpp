#include "pch.h"
#include "resource.h"
#include "HEMuiDevelopDlg.h"

#include "../HE_LIB/HELib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace lib;

enum class CHEMuiDevelopDlg::ListRow
{
	module_name = 0,

	row_num
};

CHEMuiDevelopDlg::CHEMuiDevelopDlg(CHEDocBase* pDoc, CWnd* pParent)
	: CHEDialog(pDoc, CHEMuiDevelopDlg::IDD, pParent)
{
}

CHEMuiDevelopDlg::~CHEMuiDevelopDlg()
{
}

void CHEMuiDevelopDlg::DoDataExchange(CDataExchange* pDX)
{
	CHEDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_HEMUI_LIST, m_lstDevelop);
}

BEGIN_MESSAGE_MAP(CHEMuiDevelopDlg, CHEDialog)
	ON_NOTIFY(NM_DBLCLK, IDC_HEMUI_LIST, OnDblClickedList)
END_MESSAGE_MAP()

BOOL CHEMuiDevelopDlg::OnInitDialog()
{
	CHEDialog::OnInitDialog();

	SetControl();

	SetData2Dlg();

	return TRUE;
}

BOOL CHEMuiDevelopDlg::Create(CWnd* pParentWnd)
{
	return CHEDialog::Create(CHEMuiDevelopDlg::IDD, pParentWnd);
}

void CHEMuiDevelopDlg::SetControl()
{
	CRect rect;
	m_lstDevelop.GetWindowRect(rect);

	double width = rect.Width() * 0.98;
	m_lstDevelop.InsertColumn(EnumIndex(ListCol::title), _T("Title"), LVCFMT_LEFT, static_cast<int>(width * 0.6));
	m_lstDevelop.InsertColumn(EnumIndex(ListCol::desc), _T("Desc"), LVCFMT_LEFT, static_cast<int>(width * 0.4));

	auto dwStyle = m_lstDevelop.GetExtendedStyle();
	m_lstDevelop.SetExtendedStyle(dwStyle | LVS_EX_SINGLEROW | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
}

void CHEMuiDevelopDlg::SetData2Dlg()
{
	auto lambda_add = [](auto& lstctrl, auto strTitle, auto strDesc, auto itemData)
	{
		auto itemCount = lstctrl.GetItemCount();
		auto item = lstctrl.InsertItem(itemCount, strTitle);
		lstctrl.SetItemText(item, EnumIndex(ListCol::desc), strDesc);
		lstctrl.SetItemData(item, static_cast<DWORD_PTR>(itemData));
	};

	lambda_add(m_lstDevelop, _T("Module Name"), _T("Framework"), EnumIndex(ListRow::module_name));
}

void CHEMuiDevelopDlg::Apply(ListRow row)
{
	switch (row)
	{
	case ListRow::module_name:
	{
		auto lpszAppName = AfxGetAppName();

		auto pModuleState = AfxGetModuleState();
		auto lpszModuleName = pModuleState->m_lpszCurrentAppName;

		TCHAR szModuleFileName[MAX_PATH] = _T("");
		::GetModuleFileName(0, szModuleFileName, MAX_PATH);

		CString strFormat;
		strFormat.Format(_T("AppName: %s\nModuleName : %s\nModuleFileName : %s"), lpszAppName, lpszModuleName, szModuleFileName);

		AfxMessageBox(strFormat);
	}
	break;
	default:
	{
		ASSERT(FALSE);
	}
	break;
	}
}

void CHEMuiDevelopDlg::OnDblClickedList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	if (pNMItemActivate->iItem != -1)
	{
		auto itemData = m_lstDevelop.GetItemData(pNMItemActivate->iItem);
		Apply(static_cast<ListRow>(itemData));
	}

	*pResult = 0;
}
