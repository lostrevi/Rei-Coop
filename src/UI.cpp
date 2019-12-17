#include "UI.h"

UI::UI()
{
    //ctor
}


void UI::init(SDL_Renderer *Renz, int Total_HP, int current_HP)
{
    RenA = Renz;
    HPBAR.init(RenA, HPBarSprite, current_HP, Total_HP);
}

void UI::update()
{

}

void UI::draw()
{

}

void UI::incr_HP(int a)
{

}









SDL_Texture* UI::loadTexture_SUB(std::string path)
{
            //The final texture
            SDL_Texture* newTexture = NULL;

            //Load image at specified path
            SDL_Surface* loadedSurface = IMG_Load( path.c_str() );


            if( loadedSurface == NULL )
            {
                std::cout <<  "Unable to load image" << path.c_str() << "! SDL_image Error: " << IMG_GetError() << std::endl;
            }
            else
            {
                //Create texture from surface pixels
                newTexture = SDL_CreateTextureFromSurface( RenA, loadedSurface );
                if( newTexture == NULL )
                {
                    std::cout << "Unable to create texture from" <<  path << "! SDL Error: " << SDL_GetError() << std::endl;
                }

                //Get rid of old loaded surface
                SDL_FreeSurface( loadedSurface );
            }

            return newTexture;
}

