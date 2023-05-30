//==============================================================================
/*
	Texture Bank class for loading multiple textures

	3/18/2014
	SDLTutorials.com
	Tim Jones
*/
//==============================================================================
#pragma once

#include <map>
#include <string>
#include <vector>

#include "Texture.h"

class TextureBank
{
private:
	static std::map<std::string, Texture*> TexList;

public:
	static bool Init();

	static void Cleanup();

private:
	static void AddTexture(SDL_Renderer* mRenderer, std::string ID, std::string Filename);

public:
	static Texture* Get(std::string ID);
};
