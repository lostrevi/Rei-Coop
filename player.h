#ifndef PLAYER_H
#define PLAYER_H

#include "Enity.h"

class Player : public Enity
{

private:

///Nothing yet ///

public:

    Player();
    ~Player();

   virtual void init(SDL_Renderer *Renz, SDL_Texture *Text,double TopSpeed,double SPd,  int IDa, int Sx, int Sy, bool isPlayer, int type);
   virtual void update(double Xoffset, double Yoffset);

    //virtual void Do_MovmentLogic();


    virtual void ATTACK()
    {
        if(!Attack && !AttackLOCK && timerC >= timerCMAX)
        Attack = true;
    }

};

#endif // PLAYER_H
