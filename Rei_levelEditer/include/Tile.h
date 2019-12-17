#ifndef TILE_H
#define TILE_H

#include "../input.h"

class Tile
{
    public:
        Tile();

        void init(SDL_Renderer* RenZ, SDL_Texture *Texture, int index ,int x, int y, std::string TileData);
        void init(SDL_Renderer* RenZ, SDL_Texture *Texture, int index ,int x, int y, std::string TileData, int OFFX, int OFFY);

        void change_tile(int index ,int x, int y, std::string TileData);
        void change_tile(int index ,int x, int y, std::string TileData, int Width, int Height);

        void update(int OFFX, int OFFY);
        void draw();

        std::string Get_TileData()
        {
            return Tiledata;
        }

        SDL_Rect Get_LOC()
        {
            return LOC;
        }
        void Set_LOC(SDL_Rect a)
        {
            LOC.x = a.x;
            LOC.y = a.y;
            LOC.w = a.w;
            LOC.h = a.h;
        }



    private:

    void GetCLIPXandY(int index);

    SDL_Renderer *RenA;
    SDL_Texture *Tile_Texture;
    SDL_Rect LOC;
    SDL_Rect CLIP;

    std::string Tiledata = "";

    int OffX = 0;
    int OffY = 0;


    int TileSize = 64;
    int TileSheetWidth = 25;

};

#endif // TILE_H
