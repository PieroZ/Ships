//==============================================================================
#include "Texture.h"
#include "RenderQueue.h"
#include "App.h"
#include "Log.h"
#include "Sprite.h"

//==============================================================================
Texture::Texture()
{
}
//==============================================================================
//Texture::Texture(SDL_Texture* SDLTexture)
//{
//	mSDLTexture = SDLTexture;
//	// Grab dimensions
//	SDL_QueryTexture(mSDLTexture, NULL, NULL, &mWidth, &mHeight);
//}

//------------------------------------------------------------------------------
Texture::~Texture()
{
	Cleanup();
}

//int Texture::GetRenderOrder() const
//{
//	return mRenderOrder;
//}

SDL_Texture* Texture::GetSDLTexture()
{
	return mSDLTexture;
}

SDL_Renderer* Texture::GetRenderer()
{
	return mRenderer;
}

//SDL_Rect Texture::GetSrcRect() const
//{
//	return mSrcRect;
//}
//
//SDL_Rect Texture::GetDstRect() const
//{
//	return mDstRect;
//}

void Texture::Cleanup()
{
	if (mSDLTexture)
	{
		SDL_DestroyTexture(mSDLTexture);
		mSDLTexture = NULL;
		mWidth = 0;
		mHeight = 0;
		//mRenderOrder = 0;
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
	if ((mSDLTexture = SDL_CreateTextureFromSurface(mRenderer, TempSurface)) == NULL)
	{
		LOG_ERROR("Unable to create SDL Texture : %s : %s", Filename.c_str(), IMG_GetError());
		return false;
	}

	// Grab dimensions
	SDL_QueryTexture(mSDLTexture, NULL, NULL, &mWidth, &mHeight);

	//Log("Texture Dimensions: %s : %d %d", Filename.c_str(), mWidth, mHeight);

	SDL_FreeSurface(TempSurface);

	return true;
}

bool Texture::LoadText(TTF_Font* font, const std::string& textureText, const SDL_Color& textColor)
{
	if (!font)
	{
		LOG_ERROR("Font in LoadText is nullptr!");
		return false;
	}

	if (textureText.find_first_not_of(' ') == std::string::npos)
	{
		LOG_INFO("Texture text should not be empty!");
		return false;
	}
	mRenderer = App::GetInstance()->GetRenderer();
	if (!mRenderer)
	{
		LOG_ERROR("mRenderer in LoadText is nullptr!");
		return false;
	}

	Cleanup();

	//Render text surface
	static const Uint32 WRAP_LENGTH = 360;
	SDL_Surface* textSurface = TTF_RenderText_Solid_Wrapped(font, textureText.c_str(), textColor, WRAP_LENGTH);
	if (textSurface != NULL)
	{
		//Create texture from surface pixels
		mSDLTexture = SDL_CreateTextureFromSurface(mRenderer, textSurface);
		if (mSDLTexture == NULL)
		{
			LOG_ERROR("Unable to create texture from rendered text! SDL Error: {0}", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}
	else
	{
		LOG_ERROR("Unable to render text surface! SDL_ttf Error: {0}", TTF_GetError());
	}


	//Return success
	return mSDLTexture != NULL;
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

	SDL_RenderCopy(mRenderer, mSDLTexture, NULL, &Destination);
}

//------------------------------------------------------------------------------
void Texture::Render(int X, int Y, int mWidth, int mHeight, int SX, int SY, int SWidth, int SHeight)
{
	SDL_Rect Source = { SX, SY, SWidth, SHeight };
	SDL_Rect Destination = { X, Y, mWidth, mHeight };

	SDL_RenderCopy(mRenderer, mSDLTexture, &Source, &Destination);
}

void Texture::Render(int X, int Y, SDL_Color color)
{
	// Set the color modulation
	SDL_SetTextureColorMod(mSDLTexture, color.r, color.g, color.b);

	// Set the blend mode to preserve alpha channel
	SDL_SetTextureBlendMode(mSDLTexture, SDL_BLENDMODE_BLEND);

	SDL_Rect Destination = { X, Y, mWidth, mHeight };

	SDL_RenderCopy(mRenderer, mSDLTexture, NULL, &Destination);
}

void Texture::RenderScaled(int x, int y)
{
	double widthScale = static_cast<double>(App::GetInstance()->GetWindowWidth()) / static_cast<double>(App::GetInstance()->GetWindowTargetWidth());
	double heightScale = static_cast<double>(App::GetInstance()->GetWindowHeight()) / static_cast<double>(App::GetInstance()->GetWindowTargetHeight());

	int widthOnScreen = static_cast<int>(mWidth * widthScale);
	int heightOnScreen = static_cast<int>(mHeight * heightScale);

	int spriteX = 0;
	int spriteY = 0;
	int spriteWidth = mWidth;
	int spriteHeight = mHeight;

	SDL_Rect Source = { spriteX, spriteY, spriteWidth, spriteHeight };
	SDL_Rect Destination = { x, y, widthOnScreen, heightOnScreen };

	SDL_RenderCopy(mRenderer, mSDLTexture, &Source, &Destination);
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

	SDL_RenderCopy(mRenderer, mSDLTexture, &Source, &Destination);
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

	SDL_RenderCopy(mRenderer, mSDLTexture, &Source, &Destination);
}

void Texture::AddToRenderQueue(int x, int y, int normalResolutionWidth, int normalResolutionHeight, int spriteX, int spriteY, int spriteWidth, int spriteHeight, int renderOrder)
{
	double widthScale = static_cast<double>(App::GetInstance()->GetWindowWidth()) / static_cast<double>(App::GetInstance()->GetWindowTargetWidth());
	double heightScale = static_cast<double>(App::GetInstance()->GetWindowHeight()) / static_cast<double>(App::GetInstance()->GetWindowTargetHeight());

	int widthOnScreen = normalResolutionWidth * widthScale;
	int heightOnScreen = normalResolutionHeight * heightScale;

	int screenX = x * widthScale;
	int screenY = y * heightScale;

	SDL_Rect source = { spriteX, spriteY, spriteWidth, spriteHeight };
	SDL_Rect destination = { screenX, screenY, widthOnScreen, heightOnScreen };



	RenderQueue::GetInstance().AddToRenderQueue(this, source, destination, renderOrder);
}


const SDL_Rect& Texture::GetEntireTextureRect() const
{
	return SDL_Rect{ 0,0,mWidth,mHeight };
}

const SDL_Point& Texture::GetCenterPointOfTexture() const
{
	return SDL_Point{ mWidth / 2, mHeight / 2 };
}

//------------------------------------------------------------------------------
int Texture::GetWidth() { return mWidth; }
int Texture::GetHeight() { return mHeight; }

//==============================================================================