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
    bool Init();
private:
    ScreenText();
    ~ScreenText();
    bool LoadFont();

private:
    TTF_Font* mFont = nullptr;
};

