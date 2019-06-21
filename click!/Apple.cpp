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
	this->m_pUpgrades.push_back(upgrade);
	this->CalculateApplesPerSecond();
}