#include "AppStateManager.h"

//// Refer to your Other App States Here
#include "AppStateTest.h"
//#include "CAppStateGame\CAppStateGame.h"
//
//#include "CAppStateBattle\CAppStateBattle.h"

AppState* AppStateManager::ActiveAppState = 0;

void AppStateManager::OnEvent(SDL_Event* EventHolder)
{
    if (ActiveAppState)
    {
        ActiveAppState->OnEvent(EventHolder);
    }
}

void AppStateManager::OnLoop()
{
    if (ActiveAppState) ActiveAppState->OnLoop();
}

void AppStateManager::OnRender()
{
    if (ActiveAppState) ActiveAppState->OnRender();
}

void AppStateManager::SetActiveAppState(int AppStateID, SDL_Renderer* Renderer)
{
    if (ActiveAppState) ActiveAppState->OnDeactivate();

    // Also, add your App State Here so that the Manager can switch to it
    if (AppStateID == APPSTATE_NONE)        ActiveAppState = 0;
    if(AppStateID == APPSTATE_TEST)    ActiveAppState = AppStateTest::GetInstance();
    //if (AppStateID == APPSTATE_GAME)        ActiveAppState = CAppStateGame::GetInstance();
    //if (AppStateID == APPSTATE_BATTLE)       ActiveAppState = CAppStateBattle::GetInstance();

    if (ActiveAppState) ActiveAppState->OnActivate(Renderer);
}

AppState* AppStateManager::GetActiveAppState()
{
    return ActiveAppState;
}