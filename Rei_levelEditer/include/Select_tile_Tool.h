#ifndef SELECT_TILE_TOOL_H
#define SELECT_TILE_TOOL_H

#include "currentTile.h"

class Select_tile_Tool
{
    public:
        Select_tile_Tool();

        void init(SDL_Renderer *RenZ, SDL_Texture *TEXTURE, int ScreenW, int ScreenH, int TileSheetWidthz);
        void update(SDL_Rect MOUSE);
        void draw();

        void Left_Click();

        void PanTiles(int a); //1 up //2 down // 3 right // 4 left

        int Get_Selected_Tile()
        {
            int temp = Selected_Tile;
            Selected_Tile = -1;
            return temp;
        }


    private:
        SDL_Renderer *RenA;
        SDL_Texture *Texture;

        int Selected_Tile = -1;

        int screenW, ScreenH, TileSheetWidth;

        int TileSize = 64;

        std::vector<SDL_Rect> Tiles;
        std::vector<SDL_Rect> Clips;
        std::vector<int> Indexs;
        SDL_Rect CLIP;

        void GetCLIPXandY(int index)
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

        int HoveringTile = -1;

        bool checkCollision( SDL_Rect a, SDL_Rect b );


};

#endif // SELECT_TILE_TOOL_H
