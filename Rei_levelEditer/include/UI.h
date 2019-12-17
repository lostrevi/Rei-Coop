#ifndef UI_H
#define UI_H

#include "Select_tile_Tool.h"


class UI
{
    public:
        UI();

        void init(SDL_Renderer *RenZ, SDL_Texture *Texture, int ScreenWIDTH, int ScreenHIEGHT);
        void update(SDL_Rect MOUSE);
        void draw();




        void NextTile()
        {
            CURRENTTILE++;
        }
        void LastTile()
        {
            if(CURRENTTILE > 0)
            CURRENTTILE--;
        }
        int GetCurrentTIle()
        {
            return CURRENTTILE;
        }

        void Left_Click()
        {
            STT.Left_Click();
        }

        void PanTiles(int a)
        {
            STT.PanTiles(a);
        }
        void Set_MOD_HOLDER(std::string a)
        {
            MOD_HOLDER = a;
        }

    private:

        TTF_Font *Font1;

        Text MOD_Text;
        bool Text_Wait = false; /// for some reason text needs to wait one cycle before it is able to be drawn so this just makes sure it deosn't turn on in the first cycle but after it does it is set to true and on the 2nd cycle it works fine.

        std::string MOD_HOLDER = "z00";


        int TileSHeetWidth = 25;

        SDL_Renderer *RenA;
        SDL_Texture *TileSheetTextrue;

        int ScreenW = 0;
        int ScreenH = 0;

        Select_tile_Tool STT;

        currentTile CurrentTile;
        int CURRENTTILE = 0;






};

#endif // UI_H
