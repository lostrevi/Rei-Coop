#include "UI.h"

UI::UI()
{
    //ctor
}


void UI::init(SDL_Renderer *RenZ, SDL_Texture *Texture, int ScreenWIDTH, int ScreenHIEGHT)
{
    RenA = RenZ;
    TileSheetTextrue = Texture;

    Font1 = TTF_OpenFont("Data/clacon.ttf",16);

    ScreenW = ScreenWIDTH;
    ScreenH = ScreenHIEGHT;

    CurrentTile.init(RenA,TileSheetTextrue,ScreenW, ScreenH, TileSHeetWidth);
    STT.init(RenA,TileSheetTextrue,ScreenW,ScreenH,TileSHeetWidth);
    MOD_Text.init(RenA,Font1,"z00",ScreenWIDTH-100,120,25,15);


}
void UI::update(SDL_Rect MOUSE)
{
    CurrentTile.update(CURRENTTILE);
    STT.update(MOUSE);
    MOD_Text.update();
    MOD_Text.update_Message(MOD_HOLDER);

    int temp = STT.Get_Selected_Tile();
    if(temp != -1)
    {
       CURRENTTILE = temp;
    }

}
void UI::draw()
{
    CurrentTile.draw();
    STT.draw();
    if(Text_Wait)
    {
        MOD_Text.draw();
    }
    if(!Text_Wait)
        Text_Wait = true;
}
