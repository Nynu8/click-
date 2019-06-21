#pragma once
#include <string>
#include <cmath>
class Upgrade
{
public:
	Upgrade(std::string name, int appleAmountPerSecond, int upgradeCost) : name(&name), appleAmountPerSecond(appleAmountPerSecond), upgradeCost(upgradeCost) {};
	void AddUpgradeLevel(int);
	const std::string& GetName() const;
	double GetUpgradeCost() const;
	double GetApplesPerSecond() const;

private:
	std::string *name;
	int upgradeLevel = 0;
	int appleAmountPerSecond = 0;
	int upgradeCost = 0;
};

inline const std::string& Upgrade::GetName() const { return *this->name; }
inline double Upgrade::GetUpgradeCost() const { return pow(this->upgradeCost + 1, upgradeLevel); }
inline double Upgrade::GetApplesPerSecond() const { return appleAmountPerSecond*std::log2(upgradeLevel+1); }
inline void Upgrade::AddUpgradeLevel(int level) { this->upgradeLevel += level; }