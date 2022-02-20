#pragma once

#include "HEMRibbonMenu.h"

class CHEMRibbonMenuDev : public CHEMRibbonMenu
{
public:
	CHEMRibbonMenuDev();
	virtual ~CHEMRibbonMenuDev();

public:
	virtual void SetMenu(CMFCRibbonBar* pRibbonBar) override;

};

