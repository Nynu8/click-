#pragma once
#include <string>
#include <cmath>
class Upgrade
{
public:
	Upgrade(std::string name, int appleAmountPerSecond, int upgradeCost) : name(name), appleAmountPerSecond(appleAmountPerSecond), upgradeCost(upgradeCost) {};
	void AddUpgradeLevel(int);
	const std::string& GetName() const;
	uint64_t GetUpgradeCost() const;
	double GetApplesPerSecond() const;
	int GetUpgradeLevel() const;
private:
	std::string name;
	int upgradeLevel = 0;
	int appleAmountPerSecond = 0;
	int upgradeCost = 0;
};

inline const std::string& Upgrade::GetName() const { return this->name; }
inline uint64_t Upgrade::GetUpgradeCost() const { return this->upgradeCost*std::log2(upgradeLevel + 2); }
inline double Upgrade::GetApplesPerSecond() const { return appleAmountPerSecond*std::log2(upgradeLevel + 1); }
inline void Upgrade::AddUpgradeLevel(int level) { this->upgradeLevel += level; }
inline int Upgrade::GetUpgradeLevel() const { return this->upgradeLevel; }