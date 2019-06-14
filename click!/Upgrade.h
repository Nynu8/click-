#pragma once
#include <string>
class Upgrade
{
public:
	Upgrade(std::string name, int cookieAmountPerSecond, int upgradeCost) : m_name(name), m_cookieAmountPerSecond(cookieAmountPerSecond), m_upgradeCost(upgradeCost) {};
	std::string getName();
	int getUpgradeCost();
	int getCookiesPerSecond();

private:
	std::string m_name;
	int m_upgradeLevel = 0;
	int m_cookieAmountPerSecond = 0;
	int m_upgradeCost = 0;
};

inline std::string Upgrade::getName() { return this->m_name; }
inline int Upgrade::getUpgradeCost() { return (this->m_upgradeCost + 1)*m_upgradeLevel; }
inline int Upgrade::getCookiesPerSecond() { return this->m_cookieAmountPerSecond*this->m_upgradeLevel; }