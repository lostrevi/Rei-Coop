#ifndef HPBAR_H
#define HPBAR_H

#include "../Effects.h"

class HPbar
{
    public:
        HPbar();

        void init(SDL_Renderer *RenZ, SDL_Texture *Texture, int CurrentHP, int Total_HP);
        void update();
        void draw();

        int Get_total()
        {
            return total_HP;
        }
        int Get_current()
        {
            return currentHP;
        }
        void Set_TotalHP(int a);

        void Inc_currentHP(int a)
        {
            currentHP += a;
        }


    private:

        void Set_UP_Hearts();

        int ScreenWidth = 720;
        int ScreenHeight = 480;

        int SpriteSize = 20;
        int Spacer = 5;


        void ClearHearts()
        {
            LOCs.clear();
            CLIPs.clear();
        }

        SDL_Renderer *RenA;
        SDL_Texture *Heart;

        int total_HP;
        int currentHP;

        std::vector<SDL_Rect> LOCs;
        std::vector<SDL_Rect> CLIPs;
};

#endif // HPBAR_H
