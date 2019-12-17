#include "game.h"


void Game::initmouse()
{
    SDL_ShowCursor(SDL_DISABLE);

    TargetMouse.x = 0;
    TargetMouse.y = 0;
    TargetMouse.w = 4;
    TargetMouse.h = 4;
}


void Game::updatemouse()
{
    if(timerA != timerAMAX)
        timerA++;

    TargetMouse.x = INPUTS.GetMouseX();
    TargetMouse.y = INPUTS.GetMouseY();


    if(INPUTS.LCPressed())
    {
        //std::cout << "Left Click\n";
        if(timerA == timerAMAX)
        {
            MapMaster.PlaceTile(UIMaster.GetCurrentTIle());
            UIMaster.Left_Click();
            timerA = 0;
        }
    }
    if(INPUTS.RCPressed())
    {
        ScreenOffX = PanLockX - TargetMouse.x;
        ScreenOffY = PanLockY - TargetMouse.y;

        ScreenOffX = (ScreenOffX*-1);
        ScreenOffY = (ScreenOffY*-1);

        PanLockX = TargetMouse.x;
        PanLockY = TargetMouse.y;
    }
    else if(!INPUTS.RCPressed())
    {
        PanLockX = TargetMouse.x;
        PanLockY = TargetMouse.y;
    }
    if(INPUTS.MCPressed())
    {
      std::cout << "Middle Click\n";
    }
    else if(!INPUTS.MCPressed())
    {
        //Release
    }



    if(INPUTS.GetWheelUp())
    {
        //std::cout << "mouse wheel up\n";
        UIMaster.NextTile();
    }
    if(INPUTS.GetWheelDown())
    {
        //std::cout << "mouse wheel down\n";
        UIMaster.LastTile();
    }


}

void Game::drawmouse()
{
    SDL_SetRenderDrawColor( Ren0, 255, 0, 0, 0xFF );
    SDL_RenderDrawRect(Ren0,&TargetMouse);
}

