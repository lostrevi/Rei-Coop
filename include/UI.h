#ifndef UI_H
#define UI_H


#include "Text.h"

class UI
{
    public:
        UI();

        void init(SDL_Renderer *Renz, int Total_HP, int current_HP);
        void update();
        void draw();

        void incr_HP(int a);






    private:

        HPbar HPBAR;

        SDL_Renderer *RenA;
        SDL_Texture *HPBarSprite;

        SDL_Texture* loadTexture_SUB(std::string path);


};

#endif // UI_H
