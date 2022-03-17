#include "pch.h"
#include "resource.h"
#include "UITutorialDlg.h"

#include "../HE_LIB/HELib.h"
#include "../HE_INTERFACE/RenderDefine.h"
#include "../HE_INTERFACE/IRenderManager.h"
#include "../HE_INTERFACE/NotifyDefine.h"
#include "../HE_BASE/HEDocBase.h"
#include "../HE_BASE/HEViewBase.h"

using namespace lib;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CUITutorialDlg::CUITutorialDlg(CHEDocBase* pDoc, CWnd* pParent)
	: CHEDialog(pDoc, CUITutorialDlg::IDD, pParent)
{
}

CUITutorialDlg::~CUITutorialDlg()
{
}

void CUITutorialDlg::DoDataExchange(CDataExchange* pDX)
{
	CHEDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_HEMUI_LIST, m_lstTutorial);
}

BEGIN_MESSAGE_MAP(CUITutorialDlg, CHEDialog)
	ON_NOTIFY(NM_DBLCLK, IDC_HEMUI_LIST, OnDblClickedList)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

BOOL CUITutorialDlg::OnInitDialog()
{
	CHEDialog::OnInitDialog();

	SetControl();

	SetData2Dlg();

	return TRUE;
}

BOOL CUITutorialDlg::Create(CWnd* pParentWnd)
{
	return CHEDialog::Create(CUITutorialDlg::IDD, pParentWnd);
}

void CUITutorialDlg::SetControl()
{
	CRect rect;
	m_lstTutorial.GetWindowRect(rect);

	double width = rect.Width() * 0.98;
	m_lstTutorial.InsertColumn(EnumIndex(ListCol::title), _T("Title"), LVCFMT_LEFT, static_cast<int>(width * 0.6));
	m_lstTutorial.InsertColumn(EnumIndex(ListCol::desc), _T("Desc"), LVCFMT_LEFT, static_cast<int>(width * 0.4));

	auto dwStyle = m_lstTutorial.GetExtendedStyle();
	m_lstTutorial.SetExtendedStyle(dwStyle | LVS_EX_SINGLEROW | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
}

void CUITutorialDlg::SetData2Dlg()
{
	auto lambda_add = [](auto& lstctrl, auto strTitle, auto strDesc, auto itemData)
	{
		auto itemCount = lstctrl.GetItemCount();
		auto item = lstctrl.InsertItem(itemCount, strTitle);
		lstctrl.SetItemText(item, EnumIndex(ListCol::desc), strDesc);
		lstctrl.SetItemData(item, static_cast<DWORD_PTR>(itemData));
	};

	lambda_add(m_lstTutorial, _T("HelloWorld Render"), _T("Tutorial"), EnumIndex(RenderType::HelloWorld));
	lambda_add(m_lstTutorial, _T("Basic Render"), _T("Tutorial"), EnumIndex(RenderType::Basic));
}

void CUITutorialDlg::Apply(RenderType render_type)
{
	auto pDoc = GetDoc();

	switch (render_type)
	{
	case RenderType::HelloWorld:
	case RenderType::Basic:
	{
		PickRender(render_type);

		pDoc->UpdateAllViews(nullptr, static_cast<WPARAM>(NotifyType::changed_database), NULL);
	}
	break;
	}
}

void CUITutorialDlg::PickRender(RenderType render_type)
{
	auto pApp = AfxGetApp();
	auto pMainFrm = static_cast<CMDIFrameWnd*>(pApp->GetMainWnd());
	auto pFrame = pMainFrm->GetActiveFrame();
	auto pView = pFrame->GetActiveView();

	if (pView && pView->IsKindOf(RUNTIME_CLASS(CHEViewBase)))
	{
		auto pViewBase = static_cast<CHEViewBase*>(pView);
		auto pRenderMgr = pViewBase->GetRenderManager();

		pRenderMgr->EnableOnlyFromGroup(render_type);
	}
}

void CUITutorialDlg::OnDblClickedList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	if (pNMItemActivate->iItem != -1)
	{
		auto itemData = m_lstTutorial.GetItemData(pNMItemActivate->iItem);
		Apply(static_cast<RenderType>(itemData));
	}

	*pResult = 0;
}

void CUITutorialDlg::OnDestroy()
{
	auto pApp = AfxGetApp();
	auto pMainFrm = static_cast<CMDIFrameWnd*>(pApp->GetMainWnd());
	auto pFrame = pMainFrm->GetActiveFrame();
	auto pView = pFrame->GetActiveView();

	if (pView && pView->IsKindOf(RUNTIME_CLASS(CHEViewBase)))
	{
		auto pViewBase = static_cast<CHEViewBase*>(pView);
		auto pRenderMgr = pViewBase->GetRenderManager();

		pRenderMgr->DisableRender(RenderGroup::learn_opengl);

		pViewBase->Invalidate();
	}

	CHEDialog::OnDestroy();
}
