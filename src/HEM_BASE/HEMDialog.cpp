#include "pch.h"
#include "HEMDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CHEMDialog::CHEMDialog(CHEMDocBase* pDoc, UINT nIDTemplate, CWnd* pParent)
	: CDialog(nIDTemplate, pParent), m_pMyDoc(pDoc)
{
}

CHEMDialog::~CHEMDialog()
{
}

void CHEMDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CHEMDialog, CDialog)
	ON_WM_NCDESTROY()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

BOOL CHEMDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;
}

void CHEMDialog::OnOK()
{
	CDialog::OnOK();

	if (m_bModeless)
		DestroyWindow();
}

void CHEMDialog::OnCancel()
{
	CDialog::OnCancel();

	if (m_bModeless)
		DestroyWindow();
}

void CHEMDialog::PostNcDestroy()
{
	CHEMDialog::OnCancel();

	if (m_bModeless)
		delete this;
}

BOOL CHEMDialog::Create(UINT nIDTemplate, CWnd* pParentWnd)
{
	m_bModeless = TRUE;

	return CDialog::Create(nIDTemplate, pParentWnd);
}

void CHEMDialog::OnNcDestroy()
{
	CDialog::OnNcDestroy();
}

void CHEMDialog::OnDestroy()
{
	CDialog::OnDestroy();
}
