#include "Camera.h"

void Camera::init(SDL_Renderer *RenZ, SDL_Texture *Texture)
{
    CameraMODE = 1; //follow player is 1

    RenA = RenZ;
    FreeCam = Texture;

    int BOXSIZEX = 60*5;
    int BOXSIZEY = 60*3;
    int ScreenW = 720;
    int ScreenH = 480;

    LOC.x = 0;//screen overlay.
    LOC.y = 0;
    LOC.w = 720;
    LOC.h = 480;

    DRAWZONE.x = 0;
    DRAWZONE.y = 0;
    DRAWZONE.w = 720;
    DRAWZONE.h = 480;



    DeadZoneLEFT.x = 0;
    DeadZoneLEFT.y = 0;
    DeadZoneLEFT.w = BOXSIZEX;
    DeadZoneLEFT.h = ScreenH;

    DeadZoneRIGHT.x = ScreenW - BOXSIZEX;
    DeadZoneRIGHT.y = 0;
    DeadZoneRIGHT.w = BOXSIZEX;
    DeadZoneRIGHT.h = ScreenH;

    DeadZoneUP.x = 0;
    DeadZoneUP.y = 0;
    DeadZoneUP.w = ScreenW;
    DeadZoneUP.h = BOXSIZEY;

    DeadZoneDOWN.x = 0;
    DeadZoneDOWN.y = ScreenH-BOXSIZEY;
    DeadZoneDOWN.w = ScreenW;
    DeadZoneDOWN.h = BOXSIZEY;
}

void Camera::Get_Cam_INFO(double xz, double yz, SDL_Rect a)
{
    TSpeedX = xz;
    TSpeedY = yz;
    Target = a;
}

void Camera::updateCam()
{
    if(CameraMODE == 2)
    {
        x = x - TSpeedX;
        y = y - TSpeedY;
    }
    else
    {
        if(checkCollision(Target,DeadZoneLEFT)) //|| checkCollision(Target,DeadZoneRIGHT) || checkCollision(Target,DeadZoneDOWN) || checkCollision(Target,DeadZoneUP))
        {
           x = x - TSpeedX;
           //y = y - TSpeedY;

        }
        if(checkCollision(Target,DeadZoneRIGHT))
        {
            x = x - TSpeedX;
        }
        if(checkCollision(Target,DeadZoneDOWN))
        {
            y = y - TSpeedY;
        }

        if(checkCollision(Target,DeadZoneUP))
        {
            y = y - TSpeedY;
        }
    }

        CamORG_X += x;
        CamORG_Y += y;



}

void Camera::CenterCam(double targetX, double targetY)
{
        //needs to push the offsets so that they place the target at 240ish 320ish



        x = 0;
        y = 0;
        TSpeedY = 0;
        TSpeedY = 0;

        //might need to comment these out
        CamORG_X = 0;
        CamORG_Y = 0;


        double MovechangeX = CamORG_X-targetX + ((720/2)-32);
        double MovechangeY = CamORG_X-targetY + ((480/2)-32);

        x = MovechangeX;
        y = MovechangeY;

        CamORG_X += x;
        CamORG_Y += y;

        //std::cout << "Camera has been centered\n";
}


bool Camera::checkCollision( SDL_Rect a, SDL_Rect b )
{
        //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

void Camera::draw()
{
    if(CameraMODE == 2)
    SDL_RenderCopy(RenA,FreeCam,NULL,&LOC);

    //SDL_SetRenderDrawColor( RenA, 255, 255, 255, 0xFF );
    //SDL_RenderDrawRect(RenA,&DRAWZONE);
    //SDL_RenderDrawRect(RenA,&DeadZoneLEFT);
    //SDL_RenderDrawRect(RenA,&DeadZoneRIGHT);
    //SDL_RenderDrawRect(RenA,&DeadZoneUP);
    //SDL_RenderDrawRect(RenA,&DeadZoneDOWN);
}
