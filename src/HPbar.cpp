#include "HPbar.h"

HPbar::HPbar()
{
}


void HPbar::init(SDL_Renderer *RenZ, SDL_Texture *Texture, int CurrentHP, int Total_HP)
{
    RenA = RenZ;
    Heart = Texture;
    currentHP = CurrentHP;
    total_HP = Total_HP;
}

void HPbar::update()
{

}



void HPbar::draw()
{

}

void HPbar::Set_TotalHP(int a)
{
    /// this would max out HP so i'm doing the same might do more for this
    total_HP = a;
    currentHP = a;
}


void HPbar::Set_UP_Hearts()
{
    ClearHearts();


    int Hearts_To_Render = std::floor(total_HP/4);


    for(int i = 0; i < Hearts_To_Render; i++)
    {
        SDL_Rect NEWLOC;
        SDL_Rect NEWCLIP;

        NEWLOC.x = ScreenWidth - ((SpriteSize - Spacer)*(i+1));
        NEWLOC.y = Spacer; //might have it brake into rows later but for now this is fine
        NEWLOC.w = NEWCLIP.w = SpriteSize;
        NEWLOC.h = NEWCLIP.h = SpriteSize;



        if(currentHP/4 == Hearts_To_Render || (total_HP - currentHP) > 4)
        {
            NEWCLIP.x = 0;
        }
        //else if()




        NEWCLIP.y = 0; // this should just be a line so this hsould be fine


    }
}

