
#include "Octorok.h"

Octorok::Octorok()
{

}
Octorok::~Octorok()
{

}


void Octorok::init(SDL_Renderer *Renz, SDL_Texture *Text,double TopSpeed,double SPd,  int IDa, int Sx, int Sy, bool isPlayer, int type)
{
    ID = IDa;
    IsPlayer = isPlayer;

    typeofChar = type;

    HITMODx = 10;
    HITMODy = 13;

    TypeOfShot = 0;

    EnityisDamanging = true; //use this if contact with them hurts you

    DIR = 1;

    RenA = Renz;
    Sprite = Text;

    TOPSpeed = TopSpeed;
    SpeedInc = SPd;

    timerAMAX = 15; //walk animation limet;
    timerBMAX = 10; //attack animation time limit
    timerCMAX = 10; //cool down for attack.

    SpriteSize = 64;

    //will adjust after soe more testing is done
    X = LOC.x = Sx;
    Y = LOC.y = Sy;
    LOC.w = LOC.h = CLIP.w = CLIP.h = SpriteSize;
    CLIP.x = 0;
    CLIP.y = 0;

    HIT.x = LOC.x + HITMODx;
    HIT.y = LOC.y + HITMODy;
    HIT.w = SpriteSize - 24;
    HIT.h = SpriteSize - 24;

    DamageB.x = -10000; //should work for up strike;
    DamageB.y = -10000;
    DamageB.w = 0;
    DamageB.h = 0;

    ///TRUE_X = X;///these will be important for mutiplayer i think. ///Mght use this just to keep the offset
    ///TRUE_Y = Y;

}


void Octorok::update(double Xoffset, double Yoffset)
{

    //std::cout << "X: " << TRUE_X << ", Y: " << TRUE_Y << std::endl;


    //DamageB.x = HIT.x; /// Make sure EnityisDamanging is true; if you are using this
    //DamageB.y = HIT.y;
    //DamageB.w = HIT.w;
    //DamageB.h = HIT.h;



    Do_MovmentLogic(Xoffset, Yoffset);


    if(Attack && !AttackLOCK)
    {
        //7
        if(DIR == 1) //down
        {
            CLIP.y = SpriteSize*6;
            CLIP.x = 0;
            CLIP.h = SpriteSize*2;
            LOC.h = SpriteSize*2;

            MakeShot = true;
            TypeOfShot = 6;



        }

        else if(DIR == 0) //up
        {
            CLIP.y = SpriteSize*6;
            CLIP.x = SpriteSize;
            CLIP.h = SpriteSize*2;
            LOC.h = SpriteSize*2;
            LOC.y -= SpriteSize;

            MakeShot = true;
            TypeOfShot = 6;


        }
        else if(DIR == 2) //right
        {
            CLIP.y = SpriteSize*7;
            CLIP.x = SpriteSize*2;
            CLIP.w = SpriteSize*2;
            LOC.w = SpriteSize*2;

            MakeShot = true;
            TypeOfShot = 6;


        }
        else if(DIR == 3)//left
        {
            CLIP.y = SpriteSize*6;
            CLIP.x = SpriteSize*2;
            CLIP.w = SpriteSize*2;
            LOC.w = SpriteSize*2;
            LOC.x -= SpriteSize;

            MakeShot = true;
            TypeOfShot = 6;



        }
        timerB = 0;
        Attack = false;
        AttackLOCK = true;
        //std::cout << "in";

    }
    if(AttackLOCK)
    {
        timerB++;
        //std::cout << "|TICK|";
    }
    if(AttackLOCK && timerB > timerBMAX)
    {
        //set it back
        //CLIP.x = 0;
        CLIP.y = 0;
        CLIP.h = SpriteSize;
        CLIP.w = SpriteSize;
        LOC.h = SpriteSize;
        LOC.w = SpriteSize;

        if(DIR == 0)
        {
            LOC.y += SpriteSize;
            CLIP.x = SpriteSize*2;
        }
        else if (DIR == 1)
        {
            CLIP.x = SpriteSize*0;
        }
        else if(DIR == 2)
        {
            CLIP.x = SpriteSize*3;
        }
        else if(DIR == 3)
        {
            LOC.x += SpriteSize;
            CLIP.x = SpriteSize*1;
        }
        else
        CLIP.x = 0;

        timerC = 0;
        timerB = 0;
        AttackLOCK = false;

            DamageB.x = -11110; //should work for up strike;
            DamageB.y = -11110;
            DamageB.w = 0;
            DamageB.h = 0;


        //std::cout << "out";
    }


    if(timerC < timerCMAX)
        timerC++;




}









/////////////////////OCATROKROCKS



OctorokROCK::OctorokROCK()
{

}
OctorokROCK::~OctorokROCK()
{

}


void OctorokROCK::init(SDL_Renderer *Renz, SDL_Texture *Text,double TopSpeed,double SPd,  int IDa, int Sx, int Sy, bool isPlayer, int type)
{
    ID = IDa;
    IsPlayer = isPlayer; //this should be false

    typeofChar = type;

    HITMODx = 15;
    HITMODy = 15;

    Colisonwiththing = false;

    DIR = 1;

    EnityisDamanging = true; //use this if contact with them hurts you

    RenA = Renz;
    Sprite = Text;

    TOPSpeed = TopSpeed;
    SpeedInc = SPd;

    timerAMAX = 50; //This is used for life of shot if it is a shot enity
    timerBMAX = 0; //attack animation time limit
    timerCMAX = 0; //cool down for attack.

    SpriteSize = 64;

    //will adjust after soe more testing is done
    X = LOC.x = Sx;
    Y = LOC.y = Sy;
    LOC.w = LOC.h = CLIP.w = CLIP.h = SpriteSize;
    CLIP.x = 64*6;
    CLIP.y = 64*6;

    HIT.x = LOC.x + HITMODx;
    HIT.y = LOC.y + HITMODy;
    HIT.w = SpriteSize - 25;
    HIT.h = SpriteSize - 25;

    DamageB.x = -10000; //should work for up strike;
    DamageB.y = -10000;
    DamageB.w = 0;
    DamageB.h = 0;

    ///TRUE_X = X;///these will be important for mutiplayer i think. ///Mght use this just to keep the offset
    ///TRUE_Y = Y;

}

void OctorokROCK::update(double Xoffset, double Yoffset)
{

    //std::cout << "X: " << TRUE_X << ", Y: " << TRUE_Y << std::endl;


    Do_MovmentLogic(Xoffset, Yoffset);





}
