#pragma once

class CHEMRibbonManager
{
public:
	CHEMRibbonManager();
	virtual ~CHEMRibbonManager();

public:
	void SetMenu(CMFCRibbonBar* pRibbonBar);
	void SetActive(CMFCRibbonBar* pRibbonBar, CString strCategory);
	void SetVisible(CMFCRibbonBar* pRibbonBar, CString strCategory, BOOL bShow);
};

