#include "pch.h"
#include "resource.h"
#include "HEMRibbonMenuDev.h"

CHEMRibbonMenuDev::CHEMRibbonMenuDev()
{
}

CHEMRibbonMenuDev::~CHEMRibbonMenuDev()
{
}

void CHEMRibbonMenuDev::SetMenu(CMFCRibbonBar* pRibbonBar)
{
	m_pRibbonBar = pRibbonBar;
	m_pCategory = pRibbonBar->AddCategory(_T("Category"), IDB_RIBBON_MENU_SMALL, IDB_RIBBON_MENU_NORMAL);
	
	m_pPanel = m_pCategory->AddPanel(_T("Panel"));
	m_pPanel->SetCenterColumnVert(TRUE);
	{
		m_pButton = new CMFCRibbonButton(ID_RIBBON_DEV_BTN, _T("Dev Button"), 0, 1);
		m_pButton->SetToolTipText(_T("Dev Button ToolTip"));
		m_pButton->SetDescription(_T("Dev Button Description"));
	}
	m_pPanel->Add(m_pButton);
}
