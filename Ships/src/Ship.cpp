#include "Ship.h"
#include "TextureBank.h"
#include "Log.h"
#include "RenderQueue.h"

Ship::Ship(std::unique_ptr<AbstractShipMovementController> mShipMovementController) : mShipMovementController(std::move(mShipMovementController))
{
    Init();
}

Ship::~Ship()
{
    printf("Ship has been freed!\n");
}

void Ship::AddToRenderQueue(int renderOrder)
{
    SDL_Rect srcRect;

    SDL_Rect dstRect;

    if (mAnimation)
    {
        srcRect = mAnimation->GetSrcRect();
        dstRect = mAnimation->GetSrcRect();
        dstRect.x = mShipMovementController->GetX();
        dstRect.y = mShipMovementController->GetY();
    }
    else
    {
        dstRect = { static_cast<int>(mShipMovementController->GetX()), static_cast<int>(mShipMovementController->GetY()), TextureBank::Get(mShipTextureName)->GetWidth(),TextureBank::Get(mShipTextureName)->GetHeight() };

        srcRect = TextureBank::Get(mShipTextureName)->GetEntireTextureRect();
    }
    //RenderQueue::GetInstance().AddToRenderQueue(TextureBank::Get(mShipTextureName), TextureBank::Get(mShipTextureName)->GetEntireTextureRect(), dstRect, renderOrder);
    RenderQueue::GetInstance().AddToRenderQueue(TextureBank::Get(mShipTextureName), srcRect, dstRect, mShipMovementController->GetShipRotation(), mShipMovementController->GetTextureCenter(), renderOrder, 255, true);
}

bool Ship::Init()
{
    auto&& texture = TextureBank::Get(mShipTextureName);
    mShipMovementController->SetTextureCenter(texture->GetCenterPointOfTexture());

    mAnimation = std::make_unique<AnimatedTexture>();
    mAnimation->InitAnimTexture(68, 68, 1, 10000);
    mAnimation->SetSpriteXY(0, 0);
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
    mAnimation->OnAnimate();
}

void Ship::SetClockwiseRotation()
{
    if (mShipRotation == ShipRotation::clockwise)
    {
        mShipRotation = ShipRotation::none;
    }
    else
    {
        mShipRotation = ShipRotation::counterclockwise;
    }
}

void Ship::SetCounterclockwiseRotation()
{
    if (mShipRotation == ShipRotation::counterclockwise)
    {
        mShipRotation = ShipRotation::none;
    }
    else
    {
        mShipRotation = ShipRotation::clockwise;
    }
}

void Ship::StopRotate()
{
    mShipRotation = ShipRotation::none;
}

void Ship::Rotate()
{
    switch (mShipRotation)
    {
        case none:
            break;
        case clockwise:
            mShipMovementController->RotateShipClockwise();
            break;
        case counterclockwise:
            mShipMovementController->RotateShipCounterclockwise();
            break;
        default:
            break;
    }
}

void Ship::OnWKeyAction()
{
    mShipMovementController->OnWKeyAction();
}

void Ship::OnSKeyAction()
{

    mShipMovementController->OnSKeyAction();
}

std::string Ship::ToText()
{
    return mShipMovementController->ToText();
}
