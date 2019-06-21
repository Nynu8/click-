#include "Apple.h"

void Apple::calculateApplesPerSecond()
{
	double applesPerSecond = 0;
	for (std::vector<Upgrade>::iterator it = m_pUpgrades.begin(); it != m_pUpgrades.end(); ++it) {
		applesPerSecond += it->getApplesPerSecond();
	}

	this->m_currentApplesPerSecond = applesPerSecond;
}

void Apple::addUpgrade(Upgrade upgrade)
{
	this->m_pUpgrades.push_back(upgrade);
	this->calculateApplesPerSecond();
}