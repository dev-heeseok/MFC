#pragma once

#include "HEMRibbonMenu.h"

class CHEMRibbonMenuDev : public CHEMRibbonMenu
{
public:
	CHEMRibbonMenuDev();
	virtual ~CHEMRibbonMenuDev();

public:
	virtual void SetMenu(CMFCRibbonBar* pRibbonBar) override;

private:
	CMFCRibbonBar* m_pRibbonBar = nullptr;
	CMFCRibbonCategory* m_pCategory = nullptr;
	CMFCRibbonPanel* m_pPanel = nullptr;
	CMFCRibbonButton* m_pButton = nullptr;
};

