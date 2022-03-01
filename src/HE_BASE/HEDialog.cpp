#include "pch.h"
#include "HEDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CHEDialog::CHEDialog(CHEDocBase* pDoc, UINT nIDTemplate, CWnd* pParent)
	: CDialog(nIDTemplate, pParent), m_pMyDoc(pDoc)
{
}

CHEDialog::~CHEDialog()
{
}

void CHEDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CHEDialog, CDialog)
	ON_WM_NCDESTROY()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

BOOL CHEDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;
}

void CHEDialog::OnOK()
{
	CDialog::OnOK();

	if (m_bModeless)
		DestroyWindow();
}

void CHEDialog::OnCancel()
{
	CDialog::OnCancel();

	if (m_bModeless)
		DestroyWindow();
}

void CHEDialog::PostNcDestroy()
{
	CDialog::PostNcDestroy();

	if (m_bModeless)
		delete this;
}

BOOL CHEDialog::Create(UINT nIDTemplate, CWnd* pParentWnd)
{
	m_bModeless = TRUE;

	return CDialog::Create(nIDTemplate, pParentWnd);
}

void CHEDialog::OnNcDestroy()
{
	CDialog::OnNcDestroy();
}

void CHEDialog::OnDestroy()
{
	CDialog::OnDestroy();
}
