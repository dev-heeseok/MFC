#include "pch.h"
#include "resource.h"
#include "HEMRibbonMenuDev.h"
#include "HEMRibbonMenuDefine.h"

CHEMRibbonMenuDev::CHEMRibbonMenuDev()
{
}

CHEMRibbonMenuDev::~CHEMRibbonMenuDev()
{
}

void CHEMRibbonMenuDev::SetMenu(CMFCRibbonBar* pRibbonBar)
{
	auto pCategory = pRibbonBar->AddCategory(CATEGORY_NAME_DEV, IDB_RIBBON_MENU_SMALL, IDB_RIBBON_MENU_NORMAL, CSize(16, 16), CSize(32, 32));

	if (auto pPanel = pCategory->AddPanel(_T("LearnOpenGL")))
	{
		pPanel->SetCenterColumnVert(TRUE);

		if (auto pButton = new CMFCRibbonButton(ID_RIBBON_DEV_BTN, _T("Tutorial"), 0, 0))
		{
			pButton->SetToolTipText(_T("Learn OpenGL ToolTip"));
			pButton->SetDescription(_T("Learn OpenGL Description"));

			pPanel->Add(pButton);
		}
	}
}
