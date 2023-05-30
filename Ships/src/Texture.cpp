//==============================================================================
#include "Texture.h"
#include "Log.h"

//==============================================================================
Texture::Texture()
{
}

//------------------------------------------------------------------------------
Texture::~Texture()
{
	if (SDLTexture)
	{
		SDL_DestroyTexture(SDLTexture);
		SDLTexture = NULL;
	}
}

//==============================================================================
bool Texture::Load(SDL_Renderer* Renderer, std::string Filename)
{
	if (Renderer == NULL)
	{
		HZ_CORE_ERROR("Bad SDL renderer passed");
		return false;
	}

	this->Renderer = Renderer;
	this->Filename = Filename;

	SDL_Surface* TempSurface = IMG_Load(Filename.c_str());
	if (TempSurface == NULL)
	{
		HZ_CORE_ERROR("Unable to load image : %s : %s", Filename.c_str(), IMG_GetError());
		return false;
	}

	// Convert SDL surface to a texture
	if ((SDLTexture = SDL_CreateTextureFromSurface(Renderer, TempSurface)) == NULL)
	{
		HZ_CORE_ERROR("Unable to create SDL Texture : %s : %s", Filename.c_str(), IMG_GetError());
		return false;
	}

	// Grab dimensions
	SDL_QueryTexture(SDLTexture, NULL, NULL, &Width, &Height);

	//Log("Texture Dimensions: %s : %d %d", Filename.c_str(), Width, Height);

	SDL_FreeSurface(TempSurface);

	return true;
}

//------------------------------------------------------------------------------
void Texture::Render(int X, int Y)
{
	Render(X, Y, Width, Height);
}

//------------------------------------------------------------------------------
void Texture::Render(int X, int Y, int Width, int Height)
{
	SDL_Rect Destination = { X, Y, Width, Height };

	SDL_RenderCopy(Renderer, SDLTexture, NULL, &Destination);
}

//------------------------------------------------------------------------------
void Texture::Render(int X, int Y, int Width, int Height, int SX, int SY, int SWidth, int SHeight)
{
	SDL_Rect Source = { SX, SY, SWidth, SHeight };
	SDL_Rect Destination = { X, Y, Width, Height };

	SDL_RenderCopy(Renderer, SDLTexture, &Source, &Destination);
}

void Texture::Render(int X, int Y, SDL_Color color)
{
	// Set the color modulation
	SDL_SetTextureColorMod(SDLTexture, color.r, color.g, color.b);

	// Set the blend mode to preserve alpha channel
	SDL_SetTextureBlendMode(SDLTexture, SDL_BLENDMODE_BLEND);

	SDL_Rect Destination = { X, Y, Width, Height };

	SDL_RenderCopy(Renderer, SDLTexture, NULL, &Destination);
}

//------------------------------------------------------------------------------
int Texture::GetWidth() { return Width; }
int Texture::GetHeight() { return Height; }

//==============================================================================