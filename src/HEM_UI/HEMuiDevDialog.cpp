#include "pch.h"
#include "resource.h"
#include "HEMuiDevDialog.h"

#include "../HE_LIB/HELib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace lib;

enum class CHEMuiDevDialog::ListRow
{
	MyFirst = 0,

	Num
};

CHEMuiDevDialog::CHEMuiDevDialog(CHEDocBase* pDoc, CWnd* pParent)
	: CHEDialog(pDoc, CHEMuiDevDialog::IDD, pParent)
{
}

CHEMuiDevDialog::~CHEMuiDevDialog()
{
}

void CHEMuiDevDialog::DoDataExchange(CDataExchange* pDX)
{
	CHEDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_HEMUI_LIST, m_lstItem);
}

BEGIN_MESSAGE_MAP(CHEMuiDevDialog, CHEDialog)

END_MESSAGE_MAP()

BOOL CHEMuiDevDialog::OnInitDialog()
{
	CHEDialog::OnInitDialog();

	SetControl();

	SetData2Dlg();

	return TRUE;
}

BOOL CHEMuiDevDialog::Create(CWnd* pParentWnd)
{
	return CHEDialog::Create(CHEMuiDevDialog::IDD, pParentWnd);
}

void CHEMuiDevDialog::SetControl()
{
	CRect rect;
	m_lstItem.GetWindowRect(rect);

	double width = rect.Width() * 0.98;
	m_lstItem.InsertColumn(EnumIndex(ListCol::Title), _T("Title"), LVCFMT_LEFT, static_cast<int>(width * 0.6));
	m_lstItem.InsertColumn(EnumIndex(ListCol::Desc), _T("Desc"), LVCFMT_LEFT, static_cast<int>(width * 0.4));

	auto dwStyle = m_lstItem.GetExtendedStyle();
	m_lstItem.SetExtendedStyle(dwStyle | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
}

void CHEMuiDevDialog::SetData2Dlg()
{
	auto item = m_lstItem.InsertItem(0, _T("AddItem"));
	m_lstItem.SetItemText(item, EnumIndex(ListCol::Desc), _T("SubItem 1"));

}
