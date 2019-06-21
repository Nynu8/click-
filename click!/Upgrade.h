#pragma once
#include <string>
#include <cmath>
class Upgrade
{
public:
	Upgrade(std::string name, uint64_t appleAmountPerSecond, int upgradeCost) : m_name(&name), appleAmountPerSecond(appleAmountPerSecond), m_upgradeCost(upgradeCost) {};
	void addUpgradeLevel(int);
	const std::string& getName() const;
	uint64_t getUpgradeCost() const;
	uint64_t getApplesPerSecond() const;

private:
	std::string *m_name;
	int m_upgradeLevel = 0;
	uint64_t appleAmountPerSecond = 0;
	uint64_t m_upgradeCost = 0;
};

inline const std::string& Upgrade::getName() const { return *this->m_name; }
inline uint64_t Upgrade::getUpgradeCost() const { return pow(this->m_upgradeCost + 1, m_upgradeLevel); }
inline uint64_t Upgrade::getApplesPerSecond() const { return pow(this->appleAmountPerSecond, this->m_upgradeLevel); }
inline void Upgrade::addUpgradeLevel(int level) { this->m_upgradeLevel += level; }