#ifndef CAMERA_H
#define CAMERA_H

#include "input.h"

class Camera
{
private:

    double CamORG_X = 0;
    double CamORG_Y = 0;

    int CameraMODE = 0;
    // mode 0 not set
    // mode 1 follow player
    // mode 2 free cam with i up j left k down l right and no
    SDL_Renderer *RenA;
    SDL_Texture *FreeCam;
    SDL_Rect LOC;

    SDL_Rect DRAWZONE;

    SDL_Rect DeadZoneLEFT;
    SDL_Rect DeadZoneRIGHT;
    SDL_Rect DeadZoneUP;
    SDL_Rect DeadZoneDOWN;
    SDL_Rect Target;

    int TargetID;

    double x = 0;
    double y = 0;

    double TSpeedX = 0;
    double TSpeedY = 0;


public:


    void init(SDL_Renderer *RenZ, SDL_Texture *Texture);

    void draw();

    void ChangeCamMode(int a)
    {
        CameraMODE = a;
    }
    int CheckCamMode()
    {
        return CameraMODE;
    }

    SDL_Rect Get_DRAWZONE()
    {
        return DRAWZONE;
    }

    bool checkCollision( SDL_Rect a, SDL_Rect b );

    void Get_Cam_INFO(double xz, double yz, SDL_Rect a);

    void updateCam();
    void CenterCam(double targetX, double targetY);

    double Get_OFFSETX()
    {
        return x;
    }
    double Get_OFFSETY()
    {
        return y;
    }

    void ZeroOUT()
    {
        x = 0;
        y = 0;
    }
    void FullZeroOUT()
    {
        x = 0;
        y = 0;
        TSpeedX = 0;
        TSpeedY = 0;
    }

    void SetTarget(int ID)
    {
        TargetID = ID;
    }
    int GetTarget()
    {
        if(CameraMODE != 2)
        return TargetID;
        else
        return -1;
    }

};


#endif // CAMERA_H


