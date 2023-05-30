#include "Ship.h"
#include "TextureBank.h"
#include "Log.h"

Ship::Ship()
{
    Init();
}

bool Ship::Init()
{
    return LoadTexture();
}

bool Ship::LoadTexture()
{
    Texture* texture = TextureBank::Get(mShipTextureName);
    if (!texture)
    {
        LOG_ERROR("Failed to load ship texture");
        return false;
    }

    mShipTexture = texture;
    return true;
}
