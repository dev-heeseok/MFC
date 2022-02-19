#include "pch.h"
#include "HEMRibbonManager.h"
#include "HEMRibbonMenuDev.h"

CHEMRibbonManager::CHEMRibbonManager()
{
}

CHEMRibbonManager::~CHEMRibbonManager()
{
}

void CHEMRibbonManager::SetMenu(CMFCRibbonBar* pRibbonBar)
{
	auto pMenu = std::make_shared<CHEMRibbonMenuDev>();
	pMenu->SetMenu(pRibbonBar);


}
