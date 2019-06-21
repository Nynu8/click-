#pragma once
#include <string>
#include <cmath>
class Upgrade
{
public:
	Upgrade(std::string name, int appleAmountPerSecond, int upgradeCost) : m_name(&name), appleAmountPerSecond(appleAmountPerSecond), m_upgradeCost(upgradeCost) {};
	void addUpgradeLevel(int);
	const std::string& getName() const;
	double getUpgradeCost() const;
	double getApplesPerSecond() const;

private:
	std::string *m_name;
	int m_upgradeLevel = 0;
	int appleAmountPerSecond = 0;
	int m_upgradeCost = 0;
};

inline const std::string& Upgrade::getName() const { return *this->m_name; }
inline double Upgrade::getUpgradeCost() const { return pow(this->m_upgradeCost + 1, m_upgradeLevel); }
inline double Upgrade::getApplesPerSecond() const { return appleAmountPerSecond*std::log2(m_upgradeLevel+1); }
inline void Upgrade::addUpgradeLevel(int level) { this->m_upgradeLevel += level; }