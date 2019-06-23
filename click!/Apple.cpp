#include "Apple.h"

void Apple::CalculateUpgradeEffects()
{
	double applesPerSecond = 0;
	int applesPerClick = 0;
	for (std::vector<Upgrade>::iterator it = m_upgrades.begin(); it != m_upgrades.end(); ++it) {
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
	for (std::vector<Upgrade>::iterator it = m_upgrades.begin(); it != m_upgrades.end(); ++it) {
		if (it->GetName() == upgrade.GetName()) {
			upgradeOnList = true;
			it->SetUpgradeLevel(upgrade.GetUpgradeLevel());
		}
	}

	if (!upgradeOnList) {
		this->m_upgrades.push_back(upgrade);
	}

	this->CalculateUpgradeEffects();
}