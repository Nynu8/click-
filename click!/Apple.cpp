#include "Apple.h"

void Apple::CalculateUpgradeEffects()
{
	double applesPerSecond = 0;
	int applesPerClick = 0;
	for (std::vector<Upgrade>::iterator it = m_pUpgrades.begin(); it != m_pUpgrades.end(); ++it) {
		if (it->GetUpgradeType() == UpgradeType::ApplesPerSecond) {
			applesPerSecond += it->GetUpgradeEffect();
		}

		if (it->GetUpgradeType() == UpgradeType::Click) {
			applesPerClick += it->GetUpgradeEffect();
		}
	}

	this->m_currentApplesPerSecond = applesPerSecond;
	this->m_currentApplesPerClick = applesPerClick;
}

void Apple::AddUpgrade(Upgrade upgrade)
{
	bool upgradeOnList = false;
	for (std::vector<Upgrade>::iterator it = m_pUpgrades.begin(); it != m_pUpgrades.end(); ++it) {
		if (it->GetName() == upgrade.GetName()) {
			upgradeOnList = true;
			it->AddUpgradeLevel(1);
		}
	}

	if (!upgradeOnList) {
		this->m_pUpgrades.push_back(upgrade);
	}

	this->CalculateUpgradeEffects();
}

void Apple::AddLoadUpgrade(Upgrade upgrade, std::string name, int lvl)
{
	bool upgradeOnList = false;
	for (std::vector<Upgrade>::iterator it = m_pUpgrades.begin(); it != m_pUpgrades.end(); ++it) {
		if (it->GetName() == name) {
			upgradeOnList = true;
			it->AddUpgradeLevel(lvl);
		}
	}

	if (!upgradeOnList) {
		this->m_pUpgrades.push_back(upgrade);
	}

	this->CalculateUpgradeEffects();
}