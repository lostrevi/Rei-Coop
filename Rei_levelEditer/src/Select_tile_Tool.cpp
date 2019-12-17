#include "Select_tile_Tool.h"

Select_tile_Tool::Select_tile_Tool()
{
    //ctor
}

void Select_tile_Tool::init(SDL_Renderer *RenZ, SDL_Texture *TEXTURE, int ScreenW, int ScreenH, int TileSheetWidthz)
{
    RenA = RenZ;
    Texture = TEXTURE;
    screenW = ScreenW;
    ScreenH = ScreenH;
    TileSheetWidth = TileSheetWidthz;

    SDL_Rect NewTile;
    NewTile.h = NewTile.w = TileSize/2;
    NewTile.y = 45 +64;
    NewTile.x = screenW - 140;

    CLIP.w = CLIP.h = TileSize;

    SDL_Rect NewClip;
    NewClip.h = TileSize;
    NewClip.w = TileSize;

    int NewIndex = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 3; j++)
        {

            NewIndex = j + (i*TileSheetWidthz);
            GetCLIPXandY(NewIndex);
                NewClip.x = CLIP.x;
                NewClip.y = CLIP.y;
            Indexs.push_back(NewIndex);
            Clips.push_back(NewClip);
        }





    for(int i = 0; i < 4; i++)
    {
        NewTile.y += TileSize/2;
        for(int j = 0; j < 3; j++)
        {
            NewTile.x += TileSize/2;
            Tiles.push_back(NewTile);
        }
        NewTile.x = screenW - 140;
    }


}

void Select_tile_Tool::Left_Click()
{
    if(HoveringTile != -1)
    {
        Selected_Tile = Indexs[HoveringTile];
    }
}


void Select_tile_Tool::PanTiles(int a)
{

    if(a == 1) //up
    {
        for(int j = 0; j < Indexs.size(); j++)
        {
            Indexs[j] -= TileSheetWidth;
        }
    }
    else if (a == 2) //down
    {
        for(int j = 0; j < Indexs.size(); j++)
        {
            Indexs[j] += TileSheetWidth;
        }
    }
    else if (a == 3) //right
    {
        for(int j = 0; j < Indexs.size(); j++)
        {
            Indexs[j] ++;
        }
    }
    else if(a == 4) //left
    {
        for(int j = 0; j < Indexs.size(); j++)
        {
            Indexs[j] --;
        }
    }


    ///Update Clips
         for(int i = 0; i < Clips.size(); i++)
        {
            GetCLIPXandY(Indexs[i]);
                Clips[i].x = CLIP.x;
                Clips[i].y  = CLIP.y;
        }

}




void Select_tile_Tool::update(SDL_Rect MOUSE)
{
    bool NOCOLISH = true;
    for(int i = 0; i < Tiles.size(); i++)
    {
        if(checkCollision(MOUSE,Tiles[i]))
        {
            NOCOLISH = false;
            HoveringTile = i;
        }
        //HoveringTile
    }
    if(NOCOLISH)
        HoveringTile = -1;

}

void Select_tile_Tool::draw()
{
    for(int i = 0; i < Tiles.size(); i++)
    {
        SDL_RenderCopy(RenA,Texture,&Clips[i],&Tiles[i]);

        if(i == HoveringTile)
        {
            SDL_SetRenderDrawColor( RenA, 255, 255, 0, 0xFF );
        }
        else
        {
            SDL_SetRenderDrawColor( RenA, 255, 0, 0, 0xFF );
        }
        SDL_RenderDrawRect(RenA,&Tiles[i]);
    }
}


bool Select_tile_Tool::checkCollision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}
