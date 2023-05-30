#include "ScreenText.h"
#include "Log.h"
#include "App.h"


ScreenText::ScreenText()
{
}

void ScreenText::RenderText(const std::string& text, int x, int y, const SDL_Color& color)
{
    // Render the text surface
    SDL_Surface* surface = TTF_RenderText_Solid(mFont, text.c_str(), color);
    if (surface == nullptr)
    {
        // Handle the error
        // ...
        return;
    }

    // Create a texture from the surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(App::GetInstance()->GetRenderer(), surface);
    if (texture == nullptr)
    {
        // Handle the error
        // ...
        SDL_FreeSurface(surface);
        return;
    }

    // Get the width and height of the text surface
    int textWidth = surface->w;
    int textHeight = surface->h;

    // Create a destination rectangle for rendering the text
    SDL_Rect destRect = { x, y, textWidth, textHeight };

    // Render the text texture to the screen
    SDL_RenderCopy(App::GetInstance()->GetRenderer(), texture, nullptr, &destRect);

    // Clean up the surface and texture
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

bool ScreenText::Init()
{
    return LoadFont();
}

bool ScreenText::LoadFont()
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

    return success;
}

ScreenText& ScreenText::GetInstance()
{
    static ScreenText instance;
    return instance;
}