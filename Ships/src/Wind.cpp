#include "Wind.h"

Wind& Wind::GetWindInstance()
{
    static Wind instance{ 2 };
    return instance;
}

Wind::Wind()
{
}

Wind::Wind(int windVelocity) : mWindVelocity(windVelocity)
{
}

int Wind::GetWindVelocity() const
{
    return mWindVelocity;
}
