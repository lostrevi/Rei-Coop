#ifndef EFFECTS_H
#define EFFECT_H

#include "TRex.h"

class Effect /// The Effects just pop in and play there animation then they delete them selfs that's it they don't need to check stuff with toher objecter or any of that it just simple animation things.
{

private:

    SDL_Renderer *RenA;
    SDL_Texture *Texture;

    int TileSize[2] = {64,64};

    double x, y;

    SDL_Rect LOC;
    SDL_Rect CLIP;

    bool Drawme = true;

    int TimerA = 0;
    int TimerAMax = 5;
    int TICK = 0;

    int FinalFrame = 0;

    bool Ended = false;

public:

    void init(SDL_Renderer *RenZ, SDL_Texture *TEX,double X,double Y,int FINALFRAME, int CYCLES);
    void init(SDL_Renderer *RenZ, SDL_Texture *TEX,double X,double Y,int FINALFRAME, int CYCLES, int frameX, int frameY);
    void update(double Xoffset, double Yoffset);
    void draw();

    bool Check_Ended()
    {
        return Ended;
    }

};


#endif // EFFECTS_H
