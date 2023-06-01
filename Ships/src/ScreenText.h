#pragma once

#include <SDL_ttf.h>
#include <string>

class ScreenText
{
public:
    static ScreenText& GetInstance();
    ScreenText(const ScreenText&) = delete;
    void operator=(const ScreenText&) = delete;

    void RenderText(const std::string& text, int x, int y, const SDL_Color& color);
    void AddToRenderQueue(const std::string& text, const SDL_Color& color, int x, int y,  int normalResolutionWidth, int normalResolutionHeight, int spriteX, int spriteY, int spriteWidth, int spriteHeight, int renderOrder);
    SDL_Texture* CreateTextTexture(const std::string& text, const SDL_Color& color);
    bool Init();
    void Cleanup();
private:
    ScreenText();
    ~ScreenText();
    bool LoadFont();

private:
    TTF_Font* mFont = nullptr;
};

