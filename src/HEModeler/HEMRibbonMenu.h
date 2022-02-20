#pragma once

class CHEMRibbonMenu
{
public:
	CHEMRibbonMenu();
	virtual ~CHEMRibbonMenu();

public:
	virtual void SetMenu(CMFCRibbonBar* pRibbonBar) = 0;

};

