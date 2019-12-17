#include "Effects.h"

void Effect::init(SDL_Renderer *RenZ, SDL_Texture *TEX,double X,double Y,int FINALFRAME, int CYCLES)
{
    RenA = RenZ;
    Texture = TEX;

    x = X;
    y = Y;

    LOC.x = X;
    LOC.y = Y;
    LOC.w = TileSize[0];
    LOC.h = TileSize[1];

    CLIP.x = CLIP.y = 0;
    CLIP.w = TileSize[0];
    CLIP.h = TileSize[1];

    Drawme = true;

    TimerA = 0;
    TimerAMax = CYCLES; ///used for timing
    TICK = 0;

    FinalFrame = FINALFRAME;
}

void Effect::init(SDL_Renderer *RenZ, SDL_Texture *TEX,double X,double Y,int FINALFRAME, int CYCLES, int frameX, int frameY)
{
    TileSize[0] = frameX;
    TileSize[1] = frameY;

    RenA = RenZ;
    Texture = TEX;

    x = X;
    y = Y;

    LOC.x = X;
    LOC.y = Y;
    LOC.w = TileSize[0];
    LOC.h = TileSize[1];

    CLIP.x = CLIP.y = 0;
    CLIP.w = TileSize[0];
    CLIP.h = TileSize[1];

    Drawme = true;

    TimerA = 0;
    TimerAMax = CYCLES; ///used for timing
    TICK = 0;

    FinalFrame = FINALFRAME;
}

void Effect::update(double Xoffset, double Yoffset)
{
    if(Xoffset != 0 || Yoffset != 0)
    {
        x = x + Xoffset;
        LOC.x = x;

        y = y + Yoffset;
        LOC.y = y;
    }


    if(TimerA == TimerAMax)
    {
        TICK++;
        TimerA = 0;
        CLIP.x += TileSize[0];
    }





    if(TICK >= FinalFrame)
    {
        Drawme = false;
        Ended = true;
    }



    if(TimerA != TimerAMax)
    TimerA++;
}

void Effect::draw()
{
    if(Drawme)
    {
        SDL_RenderCopy(RenA,Texture,&CLIP,&LOC);
    }
}
