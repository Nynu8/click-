#pragma once
#include <vector>
#include <string>
#include "Upgrade.h"

class Apple
{
public:
	void AddApples(int64_t);
	void AddUpgrade(Upgrade);
	void AddLoadUpgrade(Upgrade, std::string, int);
	uint64_t GetAppleCount() const;
	float GetApplesPerSecond() const;
	uint64_t GetApplesPerClick() const;
	void SetAppleCount(uint64_t);

private:
	uint64_t m_appleCount = 0;
	float m_currentApplesPerSecond = 0;
	uint64_t m_currentApplesPerClick = 0;
	std::vector<Upgrade> m_pUpgrades;
	void CalculateUpgradeEffects();
};

inline void Apple::SetAppleCount(uint64_t count) { this->m_appleCount = count; };
inline void Apple::AddApples(int64_t x) { this->m_appleCount += x; }
inline uint64_t Apple::GetAppleCount() const { return this->m_appleCount; }
inline float Apple::GetApplesPerSecond() const { return this->m_currentApplesPerSecond; }
inline uint64_t Apple::GetApplesPerClick() const { return this->m_currentApplesPerClick; }