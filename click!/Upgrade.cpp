#include "Upgrade.h"

double Upgrade::GetUpgradeEffect() const 
{
	switch (this->upgradeType) {
	case UpgradeType::ApplesPerSecond:
		return upgradeEffect * std::log2(upgradeLevel + 1);

	case UpgradeType::Click:
		return upgradeEffect * upgradeLevel;
	}
}