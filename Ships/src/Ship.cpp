#include "Ship.h"
#include "TextureBank.h"
#include "Log.h"
#include "RenderQueue.h"

Ship::Ship(std::unique_ptr<AbstractShipMovementController> shipMovementController) : mShipMovementController(std::move(shipMovementController))
{
    Init();
}

Ship::~Ship()
{
    printf("Ship has been freed!\n");
}

void Ship::AddToRenderQueue(int renderOrder)
{
    const SDL_Rect& dstRect = { mShipMovementController->GetX(), mShipMovementController->GetY(), TextureBank::Get(mShipTextureName)->GetWidth(),TextureBank::Get(mShipTextureName)->GetHeight()};
    RenderQueue::GetInstance().AddToRenderQueue(TextureBank::Get(mShipTextureName), TextureBank::Get(mShipTextureName)->GetEntireTextureRect(), dstRect, renderOrder);
}

bool Ship::Init()
{
    return LoadTexture();
}

bool Ship::LoadTexture()
{
    //Texture* texture = TextureBank::Get(mShipTextureName);
    //if (!texture)
    //{
    //    LOG_ERROR("Failed to load ship texture");
    //    return false;
    //}

    //mShipTexture = texture;
    return true;
}

void Ship::Move()
{
    mShipMovementController->Move();
}
