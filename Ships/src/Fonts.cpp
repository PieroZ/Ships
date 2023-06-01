#include "Fonts.h"
#include "Log.h"

Fonts& Fonts::GetInstance()
{
    static Fonts instance;
    return instance;
}

bool Fonts::Init()
{
    return LoadFont();
}

bool Fonts::LoadFont()
{
    //Loading success flag
    bool success = true;

    //Open the font
    mFont = TTF_OpenFont("arial.ttf", 28);
    if (mFont == NULL)
    {
        LOG_CRITICAL("Failed to load lazy font! SDL_ttf Error: {0}", TTF_GetError());
        success = false;
    }
    else
    {
        LOG_TRACE("arial font initialized!");
    }

    return success;
}

void Fonts::Cleanup()
{
    TTF_CloseFont(mFont);
    mFont = nullptr;
}

TTF_Font* Fonts::GetFont() const
{
    return mFont;
}

Fonts::Fonts()
{
}
