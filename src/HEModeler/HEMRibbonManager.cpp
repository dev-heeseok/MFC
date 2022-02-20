#include "pch.h"
#include "HEMRibbonManager.h"
#include "HEMRibbonMenuDefine.h"
#include "HEMRibbonMenuDev.h"

#include <memory>

CHEMRibbonManager::CHEMRibbonManager()
{
}

CHEMRibbonManager::~CHEMRibbonManager()
{
}

void CHEMRibbonManager::SetMenu(CMFCRibbonBar* pRibbonBar)
{
	if (auto pCategory = std::make_shared<CHEMRibbonMenuDev>())
		pCategory->SetMenu(pRibbonBar);

	// TODO. after event
#ifdef _DEBUG
	SetActive(pRibbonBar, CATEGORY_NAME_DEV);
#else
	SetVisible(pRibbonBar, CATEGORY_NAME_DEV, FALSE);
#endif // _DEBUG

}

void CHEMRibbonManager::SetActive(CMFCRibbonBar* pRibbonBar, CString strCategory)
{
	auto count = pRibbonBar->GetCategoryCount();
	for (auto idx = 0; idx < count; ++idx)
	{
		auto pCategory = pRibbonBar->GetCategory(idx);
		if (pCategory && strCategory.Compare(pCategory->GetName()) == 0)
		{
			pRibbonBar->SetActiveCategory(pCategory);
			break;
		}
	}
}

void CHEMRibbonManager::SetVisible(CMFCRibbonBar* pRibbonBar, CString strCategory, BOOL bShow)
{
	auto count = pRibbonBar->GetCategoryCount();
	for (auto idx = 0; idx < count; ++idx)
	{
		auto pCategory = pRibbonBar->GetCategory(idx);
		if (pCategory && strCategory.Compare(pCategory->GetName()) == 0)
		{
			pRibbonBar->ShowCategory(idx, bShow);
			break;
		}
	}
}