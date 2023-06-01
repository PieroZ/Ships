//==============================================================================
#include "Texture.h"
#include "App.h"
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
bool Texture::Load(SDL_Renderer* mRenderer, std::string Filename)
{
	if (mRenderer == NULL)
	{
		LOG_ERROR("Bad SDL renderer passed");
		return false;
	}

	this->mRenderer = mRenderer;
	this->Filename = Filename;

	SDL_Surface* TempSurface = IMG_Load(Filename.c_str());
	if (TempSurface == NULL)
	{
		LOG_ERROR("Unable to load image : %s : %s", Filename.c_str(), IMG_GetError());
		return false;
	}

	// Convert SDL surface to a texture
	if ((SDLTexture = SDL_CreateTextureFromSurface(mRenderer, TempSurface)) == NULL)
	{
		LOG_ERROR("Unable to create SDL Texture : %s : %s", Filename.c_str(), IMG_GetError());
		return false;
	}

	// Grab dimensions
	SDL_QueryTexture(SDLTexture, NULL, NULL, &mWidth, &mHeight);

	//Log("Texture Dimensions: %s : %d %d", Filename.c_str(), mWidth, mHeight);

	SDL_FreeSurface(TempSurface);

	return true;
}

//------------------------------------------------------------------------------
void Texture::Render(int X, int Y)
{
	Render(X, Y, mWidth, mHeight);
}

//------------------------------------------------------------------------------
void Texture::Render(int X, int Y, int mWidth, int mHeight)
{
	SDL_Rect Destination = { X, Y, mWidth, mHeight };

	SDL_RenderCopy(mRenderer, SDLTexture, NULL, &Destination);
}

//------------------------------------------------------------------------------
void Texture::Render(int X, int Y, int mWidth, int mHeight, int SX, int SY, int SWidth, int SHeight)
{
	SDL_Rect Source = { SX, SY, SWidth, SHeight };
	SDL_Rect Destination = { X, Y, mWidth, mHeight };

	SDL_RenderCopy(mRenderer, SDLTexture, &Source, &Destination);
}

void Texture::Render(int X, int Y, SDL_Color color)
{
	// Set the color modulation
	SDL_SetTextureColorMod(SDLTexture, color.r, color.g, color.b);

	// Set the blend mode to preserve alpha channel
	SDL_SetTextureBlendMode(SDLTexture, SDL_BLENDMODE_BLEND);

	SDL_Rect Destination = { X, Y, mWidth, mHeight };

	SDL_RenderCopy(mRenderer, SDLTexture, NULL, &Destination);
}

void Texture::RenderScaled(int x, int y)
{
	double widthScale = static_cast<double>(App::GetInstance()->GetWindowWidth()) / static_cast<double>(App::GetInstance()->GetWindowTargetWidth());
	double heightScale = static_cast<double>(App::GetInstance()->GetWindowHeight()) / static_cast<double>(App::GetInstance()->GetWindowTargetHeight());

	int widthOnScreen = mWidth * widthScale;
	int heightOnScreen = mHeight * heightScale;

	int spriteX = 0;
	int spriteY = 0;
	int spriteWidth = mWidth;
	int spriteHeight = mHeight;

	SDL_Rect Source = { spriteX, spriteY, spriteWidth, spriteHeight };
	SDL_Rect Destination = { x, y, widthOnScreen, heightOnScreen };

	SDL_RenderCopy(mRenderer, SDLTexture, &Source, &Destination);
}

void Texture::RenderScaled(int x, int y, int normalResolutionWidth, int normalResolutionHeight)
{
	double widthScale = static_cast<double>(App::GetInstance()->GetWindowWidth()) / static_cast<double>(App::GetInstance()->GetWindowTargetWidth());
	double heightScale = static_cast<double>(App::GetInstance()->GetWindowHeight()) / static_cast<double>(App::GetInstance()->GetWindowTargetHeight());

	int widthOnScreen = normalResolutionWidth * widthScale;
	int heightOnScreen = normalResolutionHeight * heightScale;

	int spriteX = 0;
	int spriteY = 0;
	int spriteWidth = mWidth;
	int spriteHeight = mHeight;

	SDL_Rect Source = { spriteX, spriteY, spriteWidth, spriteHeight };
	SDL_Rect Destination = { x, y, widthOnScreen, heightOnScreen };

	SDL_RenderCopy(mRenderer, SDLTexture, &Source, &Destination);
}


void Texture::RenderScaled(int x, int y, int normalResolutionWidth, int normalResolutionHeight, int spriteX, int spriteY, int spriteWidth, int spriteHeight)
{
	double widthScale = static_cast<double>(App::GetInstance()->GetWindowWidth()) / static_cast<double>(App::GetInstance()->GetWindowTargetWidth());
	double heightScale = static_cast<double>(App::GetInstance()->GetWindowHeight()) / static_cast<double>(App::GetInstance()->GetWindowTargetHeight());

	int widthOnScreen = normalResolutionWidth * widthScale;
	int heightOnScreen = normalResolutionHeight * heightScale;

	int screenX = x * widthScale;
	int screenY = y * heightScale;

	SDL_Rect Source = { spriteX, spriteY, spriteWidth, spriteHeight };
	SDL_Rect Destination = { screenX, screenY, widthOnScreen, heightOnScreen };

	SDL_RenderCopy(mRenderer, SDLTexture, &Source, &Destination);
}

//------------------------------------------------------------------------------
int Texture::GetWidth() { return mWidth; }
int Texture::GetHeight() { return mHeight; }

//==============================================================================