#pragma once
#include <SDL.h>

class Colideable
{
public:
	static bool CheckBoxCollision(SDL_Rect a, SDL_Rect b);
};

