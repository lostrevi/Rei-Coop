#ifndef CURRENTTILE_H
#define CURRENTTILE_H

#include "Text.h"

class currentTile
{
    public:
        currentTile();

        void init(SDL_Renderer *RenZ, SDL_Texture *texture, int ScreenW, int ScreenH, int TileSheetWidthz);
        void update(int index);
        void draw();


        void GetCLIPXandY(int index);




    private:

        int TileSheetWidth = 25;

        int TileSize = 64;

        SDL_Renderer *RenA;
        SDL_Texture *Texture;

        SDL_Rect LOC;
        SDL_Rect CLIP;
};

#endif // CURRENTTILE_H
