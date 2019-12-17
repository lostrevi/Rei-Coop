#ifndef TREX_H
#define TREX_H

#include "Octorok.h"

class TRex : public Enity
{

private:

public:


    TRex();
    ~TRex();

   virtual void init(SDL_Renderer *Renz, SDL_Texture *Text,double TopSpeed,double SPd,  int IDa, int Sx, int Sy, bool isPlayer, int type);
   virtual void update(double Xoffset, double Yoffset);

    //virtual void Do_MovmentLogic();


    virtual void ATTACK()
    {
        if(!Attack && !AttackLOCK && timerC >= timerCMAX)
        Attack = true;
    }

};




#endif // TREX_H
