#include "SailsController.h"
#include "Log.h"
#include <math.h>

SailsController::SailsController()
{
	mSailLevel = SailLevel::off;
}

void SailsController::SetSailLevel(const SailLevel& sailLevel)
{
	mSailLevel = sailLevel;
}

void SailsController::IncreaseSailLevel()
{
	mSailLevel = (static_cast<SailLevel>(static_cast<int>(mSailLevel) + 1));
	mSailLevel = static_cast<SailLevel> (std::min(static_cast<int>(mSailLevel), static_cast<int>(SailLevel::full)));
	LOG_INFO("mSailLevel = {0}", mSailLevel);
}

void SailsController::DecreaseSailLevel()
{
	mSailLevel = (static_cast<SailLevel>(static_cast<int>(mSailLevel) - 1));
	mSailLevel = static_cast<SailLevel> (std::max(static_cast<int>(mSailLevel), static_cast<int>(SailLevel::off)));
	LOG_INFO("mSailLevel = {0}", mSailLevel);
}

SailLevel SailsController::GetSailLevel() const
{
	return mSailLevel;
}
