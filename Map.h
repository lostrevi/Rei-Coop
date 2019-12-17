#ifndef MAP_H
#define MAP_H

#include "PortalCan.h"






class MAP
{
private:

    SDL_Renderer *RenA;
    SDL_Texture *TileMapFloor;


    std::vector<SDL_Rect> LOCs;
    std::vector<SDL_Rect> CLIPs;
    std::vector<double> Lx;
    std::vector<double> Ly;
    std::vector<char> MOD1;
    std::vector<char> MOD2;
    std::vector<char> MOD3;
    std::vector<bool> Draws;


    ///EnityCallContaner
    std::vector<int> TypeEnityCan;
    std::vector<int> XofEnityCan;
    std::vector<int> YofEnityCan;
    std::vector<char> isplayerCan;
    std::vector<int> TeamEnityCan;


    bool DrawHitBoxs = false;

    ///I'll need to add hit box

    double TRUE_X = 0;
    double TRUE_Y = 0;

    std::string MAPfile;
    int TileSize;

    void Setupmap();

    void LoadFromFile(std::string path);

    void CreateTile(double tileLocX, double tileLocY, int TileIDx, int TileIDy, char OtherTag[3]);

    void ClearTile();

    std::vector<PortalCan> PortaLinks;



public:

    void Switch_Map(std::string a)
    {
        MAPfile = "Data/MAP/map_Files/" + a;
    }

    std::vector<PortalCan> Get_PortalLinks()
    {
        return PortaLinks;
    }

    void NewPortalLink(char s1, char s2, char d1, char d2, std::string a);
    void ClearPortalLinks()
    {
        PortaLinks.clear();
    }

    void init(SDL_Renderer *RenZ, SDL_Texture *TileSheetFloor, std::string MapFile);
    void update(double Xoffset, double Yoffset);
    void draw();

    void SetDraw_Draws(int i,bool a)
    {
        Draws[i] = a;
    }
    bool Check_Draws(int i)
    {
        return i;
    }

    void toggle_debug(bool a)
    {
        DrawHitBoxs = a;
    }
    bool check_debug()
    {
        return DrawHitBoxs;
    }

    void reload_Map()
    {
        ClearTile();
        LoadFromFile(MAPfile);
    }

    void reload_Map(std::string a)
    {
        MAPfile = a;
        ClearTile();
        LoadFromFile(MAPfile);
    }

    char Get_MOD1(int i)
    {
            return MOD1[i];
    }
    char Get_MOD2(int i)
    {
        return MOD2[i];
    }

    char Get_MOD3(int i)
    {
        return MOD3[i];
    }

    void Set_MOD1(int i, char a)
    {
        MOD1[i] = a;
    }

    void Set_MOD2(int i, char a)
    {
        MOD2[i] = a;
    }

    void Set_MOD3(int i, char a)
    {
        MOD3[i] = a;
    }

    void Push_Clip_a_Tile(int i)
    {
        CLIPs[i].x += TileSize;
    }

    void Push_Clip_a_tile_Back(int i)
    {
        CLIPs[i].x -= TileSize;
    }

    int Get_Amount_Of_Tiles()
    {
        return LOCs.size();
    }

    SDL_Rect Get_Rect(int i)
    {
        return LOCs[i];
    }

    std::vector<int> Get_TypeEnityCan()
    {
        return TypeEnityCan;
    }
    std::vector<int> Get_XofEnityCan()
    {
        return XofEnityCan;
    }
    std::vector<int> Get_YofEnityCan()
    {
        return YofEnityCan;
    }
    std::vector<char> Get_isplayerCan()
    {
        return isplayerCan;
    }
    std::vector<int> Get_TeamEnityCan()
    {
        return TeamEnityCan;
    }
    void Clear_EnityCan()
    {
        TypeEnityCan.clear();
        XofEnityCan.clear();
        YofEnityCan.clear();
        isplayerCan.clear();
        TeamEnityCan.clear();
    }



};


#endif // MAP_H
