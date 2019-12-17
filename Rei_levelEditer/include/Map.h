#ifndef MAP_H
#define MAP_H

#include "Tile.h"

class Map
{
    public:
        Map();
        ~Map();

        void init(SDL_Renderer *RenZ, SDL_Texture *Texture, int MAPX, int MAPY);
        void SetMapSize(int X, int Y);
        void update(int OFFX, int OFFY, SDL_Rect Mouse);
        void draw();

        void ZoomIN();
        void ZoomOUT();
        void ResetZoom();

        void exportFile();


        void PlaceTile(int index);

        bool toggleGird()
        {
            if(!DrawGrid)
                DrawGrid = true;
            else
                DrawGrid = false;
        }

        std::string Get_Mod()
        {
            return MOD;
        }
        void Set_Mod(std::string a)
        {
            MOD = a;
        }


    private:

        SDL_Renderer *RenA;
        SDL_Texture *TileTexture;

        std::string MapName = "UNTILTED";

        int Layer = 0; ///use for String
        std::string MOD = "z00";

        int TileSize = 64;

        bool DrawGrid = true;

        int ScreenW = 780;
        int ScreenH = 540;

        SDL_Rect DeadZone;

        SDL_Rect MouseL;

        int MapSizeX = 0;
        int MapSizeY = 0;

        std::vector<Tile> Tiles;

        std::vector<SDL_Rect> Grid;
        std::vector<bool> TileIsThere;

        int HoveringTile = -1;

        void NewTile(SDL_Renderer* RenZ, SDL_Texture *Texture, int index ,int x, int y, std::string TileData); /// Worry about this in a few for tile drawing and such.
        void FillTile(int index ,int x, int y, std::string TileData);

        bool checkCollision( SDL_Rect a, SDL_Rect b );

    std::string int_to_string(int a)
    {
        std::stringstream ss;
        ss << a;
        std::string str = ss.str();
        return str;
    }
    std::string int_to_string3char(int a)
    {

        std::stringstream ss;
        ss << a;
        std::string str = ss.str();

        std::string NEWstring = "";
        if(a < 10)
        {
            NEWstring = "00" + str;
        }
        else if(a > 9 && a < 100)
        {
            NEWstring = "0" + str;
        }
        else if(a > 99)
        {
            NEWstring = str;
        }

        return NEWstring;
    }

    int string_to_int(std::string a)
    {
        int thevalue = 0;

        std::istringstream ss(a);
        ss >> thevalue;
        return thevalue;
    }


};

#endif // MAP_H
