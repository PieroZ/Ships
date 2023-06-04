#pragma once
class Wind
{
private:
	int mWindVelocity = 0;

public:
	static Wind& GetWindInstance();
	int GetWindVelocity() const;

private:
	Wind();
	Wind(int windVelocity);
};

