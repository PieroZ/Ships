#pragma once

#include <SDL_ttf.h>

class Fonts
{
private:
	TTF_Font* mFont = nullptr;
public:
	static Fonts& GetInstance();
	bool Init();
	bool LoadFont();
	void Cleanup();
	TTF_Font* GetFont() const;

private:
	Fonts();
};

