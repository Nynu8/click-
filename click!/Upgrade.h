#pragma once
#include <string>
#include <cmath>
#include "UpgradeType.h"

class Upgrade
{
public:
	Upgrade(std::string name, int upgradeEffect, int upgradeCost, UpgradeType upgradeType) :
		name(name), upgradeEffect(upgradeEffect), upgradeCost(upgradeCost), upgradeType(upgradeType) {};
	void AddUpgradeLevel(int);
	const std::string& GetName() const;
	uint64_t GetUpgradeCost() const;
	double GetUpgradeEffect() const;
	int GetUpgradeLevel() const;
	UpgradeType GetUpgradeType() const;
private:
	std::string name;
	UpgradeType upgradeType;
	int upgradeLevel = 0;
	int upgradeEffect = 0;
	int upgradeCost = 0;
};

inline const std::string& Upgrade::GetName() const { return this->name; }
inline uint64_t Upgrade::GetUpgradeCost() const { return this->upgradeCost*std::log2(upgradeLevel + 2); }
inline void Upgrade::AddUpgradeLevel(int level) { this->upgradeLevel += level; }
inline int Upgrade::GetUpgradeLevel() const { return this->upgradeLevel; }
inline UpgradeType Upgrade::GetUpgradeType() const { return this->upgradeType; }