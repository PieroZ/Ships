#pragma once

enum SailLevel
{
	off, half, full
};

class SailsController
{
public:
	SailsController();
	void SetSailLevel(const SailLevel& sailLevel);
	void IncreaseSailLevel();
	void DecreaseSailLevel();
	
	SailLevel GetSailLevel() const;
private:
	SailLevel mSailLevel;
};

