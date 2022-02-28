#include "pch.h"
#include "HEMDevDlg.h"

CHEMDevDlg::CHEMDevDlg(CHEDocBase* pDoc, CWnd* pParent)
	: CHEDialog(pDoc, CHEMDevDlg::IDD, pParent)
{
}

CHEMDevDlg::~CHEMDevDlg()
{
}

void CHEMDevDlg::DoDataExchange(CDataExchange* pDX)
{
	CHEDialog::DoDataExchange(pDX);


}

BEGIN_MESSAGE_MAP(CHEMDevDlg, CHEDialog)

END_MESSAGE_MAP()

BOOL CHEMDevDlg::OnInitDialog()
{
	CHEDialog::OnInitDialog();

	SetControl();

	SetData2Dlg();

	return TRUE;
}

BOOL CHEMDevDlg::Create(CWnd* pParentWnd)
{
	return CHEDialog::Create(CHEMDevDlg::IDD, pParentWnd);
}

void CHEMDevDlg::SetControl()
{
}

void CHEMDevDlg::SetData2Dlg()
{
}
