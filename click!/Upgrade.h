#pragma once
#include <string>
#include <cmath>
class Upgrade
{
public:
	Upgrade(std::string name, float cookieAmountPerSecond, int upgradeCost) : m_name(&name), m_cookieAmountPerSecond(cookieAmountPerSecond), m_upgradeCost(upgradeCost) {};
	void addUpgradeLevel(int);
	const std::string& getName() const;
	uint64_t getUpgradeCost() const;
	float getApplesPerSecond() const;

private:
	std::string *m_name;
	int m_upgradeLevel = 0;
	float m_cookieAmountPerSecond = 0;
	uint64_t m_upgradeCost = 0;
};

inline const std::string& Upgrade::getName() const { return *this->m_name; }
inline uint64_t Upgrade::getUpgradeCost() const { return pow(this->m_upgradeCost + 1, m_upgradeLevel); }
inline float Upgrade::getApplesPerSecond() const { return pow(this->m_cookieAmountPerSecond, this->m_upgradeLevel); }
inline void Upgrade::addUpgradeLevel(int level) { this->m_upgradeLevel += level; }