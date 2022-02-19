#pragma once

#include <memory>
#include <unordered_map>

class CHEMRibbonMenu;
class CHEMRibbonManager
{
	enum class RibbonMenu { dev = 0, num };
	using MAP_MENU = std::unordered_map<RibbonMenu, std::shared_ptr<CHEMRibbonMenu>>;

public:
	CHEMRibbonManager();
	virtual ~CHEMRibbonManager();

public:
	void SetMenu(CMFCRibbonBar* pRibbonBar);

private:
	MAP_MENU m_mMenu;

};

