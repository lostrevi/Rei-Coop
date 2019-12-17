#ifndef ENITY_H
#define ENITY_H

#include "Camera.h"

class Enity
{

protected:

    SDL_Renderer *RenA;

    SDL_Texture *Sprite;

    bool Player2 = false;

    bool DrawMe = true;
    bool debugz = false;

    SDL_Rect LOC;
    SDL_Rect CLIP;
    SDL_Rect HIT;
    int HITMODx, HITMODy;
    SDL_Rect DamageB;
    SDL_Rect BlockB;

    bool WarpLock = true;

    bool Colisonwiththing = NULL;

    bool EnityisDamanging = false;


    bool UNDamage = false; /// if its like a box this will not let it be hurt.
    bool Damaged = false;
    int timerD = 0; //tine of inviceablity
    double X_PUSH = 0;
    double Y_PUSH = 0;
    int TimerDMAX = 30;
    int ticks = 0;
    int PUSH_DIR = 0;


    int TEAM = 0; // 0 - free for all // 1 - good guys // 2 - monsters // 3 -hurt no one.

    double TOPSpeed;//max speed of this enity
    double SpeedInc;//How much it incresses by
    double XSpeed = 0;
    double YSpeed = 0;
    double Xmove = 0;
    double Ymove = 0;

    bool IsPlayer;

    double X = 0, Y = 0;
    double TRUE_X = 0, TRUE_Y = 0; //this must be set to X and Y on init;
    int SpriteSize;

    int ID;

    bool Movement = false;
    bool Attack = false;
    bool AttackLOCK = false;

    int timerA = 0; //used for animated sprite
    int timerAMAX = 10;
    int timerB = 0; //used for attack
    int timerBMAX = 15;
    int timerC = 0;
    int timerCMAX = 10; //cool down for attack

    int DIR = 0; //0 up | 1 down | 2 right | 3 left

    bool MakeShot = false; //this will make a shot for the game loop
    int TypeOfShot = 0;

    int typeofChar = -1;


public:

    virtual void init(SDL_Renderer *Renz, SDL_Texture *Text,double TopSpeed,double SPd,  int IDa, int Sx, int Sy, bool isPlayer, int type) = 0;
    virtual void update(double Xoffset, double Yoffset) = 0;
    void draw();

    bool Get_attackLock()
    {
        return AttackLOCK;
    }

    bool Get_WarpLock()
    {
        return WarpLock;
    }

    void set_player2(bool a)
    {
        Player2 = a;
    }

    bool Check_Player2()
    {
        return Player2;
    }

    void Set_X(int a)
    {
        X = a;
        LOC.x = X;
    }
    void Set_Y(int a)
    {
        Y = a;
        LOC.y = Y;
    }

    void Set_WarpLock(bool a)
    {
        WarpLock = a;
    }

    int Get_Type()
    {
        return typeofChar;
    }

    void Switch_debug()
    {
        if(debugz)
            debugz = false;
        else
            debugz = true;
    }

    void Take_Damage(int DIRaaa, bool CHECK_ENITYISDAMANGEING);
    void Damageupdate();
    bool Get_EnityisDamaging()
    {
        return EnityisDamanging;
    }

    void ColisionWithSomthing();


    void camUpdate(double Xoffset, double Yoffset);

    virtual void ATTACK() = 0;

    bool Check_Colisonwiththing()
    {
        return Colisonwiththing;
    }

    void END_Colisonwiththing()
    {
        Colisonwiththing = false;
    }

    bool Check_SHOTMake()
    {
        return MakeShot;
    }
    void ShotMade()
    {
        MakeShot = false;
    }

    int GET_SHOTTYPE()
    {
        return TypeOfShot;
    }

    void Set_Team(int a)
    {
        TEAM = a;
    }

    int Get_DIR()
    {
        return DIR;
    }
    void Set_DIR(int a)
    {
        DIR = a;
    }

    int Get_Team()
    {
        return TEAM;
    }

    double Get_TX()
    {
        return TRUE_X;
    }
    double Get_TY()
    {
        return TRUE_Y;
    }

    double Get_X()
    {
        return LOC.x;
    }
    double Get_Y()
    {
        return LOC.y;
    }

    SDL_Rect Get_LOC()
    {
        return LOC;
    }
    SDL_Rect Get_HIT()
    {
        return HIT;
    }
    SDL_Rect Get_DMGB()
    {
        return DamageB;
    }
    SDL_Rect Get_BLKB()
    {
        return BlockB;
    }

    int GetID()
    {
        return ID;
    }

    void Move(double x, double y);

    void Do_MovmentLogic(double Xoffset, double Yoffset);
    void Do_ShotLogic(double Xoffset, double Yoffset,int DIROFSHOT);

    bool CheckifPlayer()
    {
        return IsPlayer;
    }

    double Get_XSpeed()
    {
        return XSpeed;
    }
    double Get_YSpeed()
    {
        return YSpeed;
    }

};







#endif // ENITY_H
