#pragma once
#include <vector>
#include "Upgrade.h"

class Apple
{
public:
	void AddApples(uint64_t);
	void AddUpgrade(Upgrade);
	uint64_t GetAppleCount() const;
	float GetApplesPerSecond() const;

private:
	uint64_t m_appleCount = 0;
	float m_currentApplesPerSecond = 0;
	std::vector<Upgrade> m_pUpgrades;
	void CalculateApplesPerSecond();
};

inline void Apple::AddApples(uint64_t x) { this->m_appleCount += x; }
inline uint64_t Apple::GetAppleCount() const { return this->m_appleCount; }
inline float Apple::GetApplesPerSecond() const { return this->m_currentApplesPerSecond; }
