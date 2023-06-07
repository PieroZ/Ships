#include "Colideable.h"

bool Colideable::CheckBoxCollision(SDL_Rect a, SDL_Rect b)
{
    return SDL_HasIntersection(&a, &b);
}
