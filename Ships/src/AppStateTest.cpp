#include "AppStateTest.h"
#include "TextureBank.h"
#include "Log.h"



// The solution is to ensure that all virtual methods that are not pure are defined. Note that a destructor must be defined even if it is declared pure-virtual

AppStateTest AppStateTest::Instance;
AppStateTest::AppStateTest()
{
}
//------------------------------------

AppStateTest::~AppStateTest()
{
}

void AppStateTest::OnKeyDown(SDL_Event* Event)
{

}
//------------------------------------

void AppStateTest::OnKeyUp(SDL_Event* Event)
{

}


void AppStateTest::OnActivate(SDL_Renderer* Renderer)
{
    this->Renderer = Renderer;
}

void AppStateTest::OnDeactivate()
{
}

void AppStateTest::OnLoop()
{
}



void AppStateTest::OnRender()
{
    TextureBank::Get("sails")->Render(500, 150);
}



AppStateTest* AppStateTest::GetInstance()
{
    return &Instance;
}