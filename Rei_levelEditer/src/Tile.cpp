#include "../include/Tile.h"

Tile::Tile()
{
    //ctor
}


void Tile::init(SDL_Renderer* RenZ, SDL_Texture *Texture, int index ,int x, int y, std::string TileData)
{
    RenA = RenZ;
    Tile_Texture = Texture;
    GetCLIPXandY(index);
    LOC.x = x;
    LOC.y = y;
    LOC.w = CLIP.w = TileSize;
    LOC.h = CLIP.h = TileSize;
    Tiledata = TileData;


}
void Tile::init(SDL_Renderer* RenZ, SDL_Texture *Texture, int index ,int x, int y, std::string TileData, int OFFX, int OFFY)
{
    RenA = RenZ;
    Tile_Texture = Texture;
    GetCLIPXandY(index);
    LOC.x = x + OFFX;
    LOC.y = y + OFFY;
    LOC.w = CLIP.w = TileSize ;
    LOC.h = CLIP.h = TileSize;
    Tiledata = TileData;
}


void Tile::change_tile(int index ,int x, int y, std::string TileData)
{
    GetCLIPXandY(index);
    LOC.x = x;
    LOC.y = y;
    LOC.w = CLIP.w = TileSize;
    LOC.h = CLIP.h = TileSize;
    Tiledata = TileData;
}
void Tile::change_tile(int index ,int x, int y, std::string TileData, int Width, int Height)
{

    GetCLIPXandY(index);
    LOC.x = x;
    LOC.y = y;
    LOC.w = Width;
    LOC.h = Height;
    CLIP.w = TileSize;
    CLIP.h = TileSize;
    Tiledata = TileData;}


void Tile::update(int OFFX, int OFFY)
{
    LOC.x += OFFX;
    LOC.y += OFFY;
}
void Tile::draw()
{
    SDL_RenderCopy(RenA, Tile_Texture, &CLIP, &LOC);
}




void Tile::GetCLIPXandY(int index)
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
