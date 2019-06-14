#pragma once
#include <vector>
#include "Upgrade.h"

class Apple
{
public:
	Apple();
	void addApples(unsigned long long);
	unsigned long long getAppleCount();
	unsigned long long getApplesPerSecond(); 
	void click();

private:
	unsigned long long m_appleCount = 0;
	unsigned long long m_currentApplesPerSecond = 0;
	std::vector<Upgrade> *m_pUpgrades;
	unsigned long long calculateApplesPerSecond();
};

inline void Apple::addApples(unsigned long long x) { this->m_appleCount += x; }
inline unsigned long long Apple::getAppleCount() { return this->m_appleCount; }
inline unsigned long long Apple::getApplesPerSecond() { return this->m_currentApplesPerSecond; }
