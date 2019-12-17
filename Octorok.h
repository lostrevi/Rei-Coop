#ifndef OCTOROK_H
#define OCTOROK_H

#include "Player.h"

class Octorok : public Enity
{

private:

public:


    Octorok();
    ~Octorok();

   virtual void init(SDL_Renderer *Renz, SDL_Texture *Text,double TopSpeed,double SPd,  int IDa, int Sx, int Sy, bool isPlayer, int type);
   virtual void update(double Xoffset, double Yoffset);

    //virtual void Do_MovmentLogic();


    virtual void ATTACK()
    {
        if(!Attack && !AttackLOCK && timerC >= timerCMAX)
        Attack = true;
    }

};



class OctorokROCK : public Enity
{

private:

public:


    OctorokROCK();
    ~OctorokROCK();

   virtual void init(SDL_Renderer *Renz, SDL_Texture *Text,double TopSpeed,double SPd,  int IDa, int Sx, int Sy, bool isPlayer, int type);
   virtual void update(double Xoffset, double Yoffset);

    //virtual void Do_MovmentLogic();


    virtual void ATTACK()
    {
        // this will not be used.
    }

};

#endif // OCTOROK_H
