#pragma once

#include "Event.h"

class AppState : public Event
{
public:
    AppState();

    SDL_Renderer* Renderer;

public:
    virtual void OnActivate(SDL_Renderer* Renderer) = 0; // It requires virtual methods to be defined in child class(es)

    virtual void OnDeactivate() = 0;

    virtual void OnLoop() = 0;

    virtual void OnRender() = 0;
};