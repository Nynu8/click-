#pragma once
#include <vector>
#include "Upgrade.h"

class Apple
{
public:
	void addApples(uint64_t);
	void addUpgrade(Upgrade);
	uint64_t getAppleCount() const;
	float getApplesPerSecond() const;

private:
	uint64_t m_appleCount = 0;
	float m_currentApplesPerSecond = 0;
	std::vector<Upgrade> m_pUpgrades;
	void calculateApplesPerSecond();
};

inline void Apple::addApples(uint64_t x) { this->m_appleCount += x; }
inline uint64_t Apple::getAppleCount() const { return this->m_appleCount; }
inline float Apple::getApplesPerSecond() const { return this->m_currentApplesPerSecond; }
