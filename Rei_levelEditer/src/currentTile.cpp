#include "currentTile.h"

currentTile::currentTile()
{
    //ctor
}



void currentTile::init(SDL_Renderer *RenZ, SDL_Texture *texture, int ScreenW, int ScreenH, int TileSheetWidthz)
{
    RenA = RenZ;
    Texture = texture;

    TileSheetWidth = TileSheetWidthz;

    LOC.x = ScreenW - 15 - TileSize;
    LOC.y = 35;
    LOC.w = LOC.h = CLIP.w = CLIP.h = TileSize;
    CLIP.x = 0;
    CLIP.y = 0;


}

void currentTile::update(int index)
{
    GetCLIPXandY(index);
}

void currentTile::draw()
{
    SDL_RenderCopy(RenA,Texture,&CLIP,&LOC);
}








void currentTile::GetCLIPXandY(int index)
{
    if(index < TileSheetWidth)
    {
        CLIP.x = index * TileSize;
        CLIP.y = 0;
    }
    else
    {
        CLIP.y = TileSize * floor(index / TileSheetWidth);
        CLIP.x = (index % TileSheetWidth) * TileSize;
    }
}
