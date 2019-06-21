#include "Apple.h"

void Apple::CalculateApplesPerSecond()
{
	double applesPerSecond = 0;
	for (std::vector<Upgrade>::iterator it = m_pUpgrades.begin(); it != m_pUpgrades.end(); ++it) {
		applesPerSecond += it->GetApplesPerSecond();
	}

	this->m_currentApplesPerSecond = applesPerSecond;
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

	this->CalculateApplesPerSecond();
}