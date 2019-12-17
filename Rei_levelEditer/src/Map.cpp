#include "../include/Map.h"

Map::Map()
{
    //ctor
}

Map::~Map()
{
    //dtor
}


void Map::init(SDL_Renderer *RenZ, SDL_Texture *Texture, int MAPX, int MAPY)
{
    RenA = RenZ;
    TileTexture = Texture;
    SetMapSize(MAPX, MAPY);

    DeadZone.x = ScreenW - 145;
    DeadZone.y = 0;
    DeadZone.w = 145;
    DeadZone.h = ScreenH;
}

void Map::SetMapSize(int X, int Y)
{
    MapSizeX = X;
    MapSizeY = Y;

    Grid.clear();
    TileIsThere.clear(); ///might not be able to do that if this is cleared ///Might remove only would be need for new map not for resize

    ///Add tiles unless i find a way to make it so you can change the map size with out lossing map data idk if i can but ffasidfjasdjf

    SDL_Rect NEW_GRID_TILE;

    NEW_GRID_TILE.w = TileSize;
    NEW_GRID_TILE.h = TileSize;

    for(int i = 0; i < MapSizeY; i++)
    {
        NEW_GRID_TILE.y = i*TileSize;

        for(int j = 0; j < MapSizeX; j++)
        {
            NEW_GRID_TILE.x = j*TileSize;
            Grid.push_back(NEW_GRID_TILE);
            TileIsThere.push_back(true);
        }
    }

    for(int i = 0; i < Grid.size(); i++)
    {
        int default_type = 3;
        std::string TileCode = int_to_string(Layer) + int_to_string3char(default_type) + MOD;
        NewTile(RenA,TileTexture,default_type,Grid[i].x,Grid[i].y,TileCode);
    }


}

void Map::update(int OFFX, int OFFY, SDL_Rect Mouse)
{

    MouseL = Mouse;

    for(int i = 0; i < Tiles.size(); i++)
    {
        Tiles[i].update(OFFX,OFFY);
    }

    bool NoHover = true;
    for(int i = 0; i < Grid.size(); i++)
    {
        if(checkCollision(Grid[i],MouseL))
        {
            HoveringTile = i;
            NoHover = false;
        }

        Grid[i].x += OFFX;
        Grid[i].y += OFFY;
    }


    if(NoHover || checkCollision(Mouse,DeadZone))
        HoveringTile = -1;

}

void Map::draw()
{
    for(int i = 0; i < Tiles.size(); i++)
    {
        Tiles[i].draw();
    }


    for(int i =0; i < Grid.size(); i++)
    {
        if(DrawGrid)
        {
            if(HoveringTile == i)
            {
                SDL_SetRenderDrawColor( RenA, 255, 255, 0, 0xFF );
            }
            else
            SDL_SetRenderDrawColor( RenA, 255, 0, 0, 0xFF );
            SDL_RenderDrawRect(RenA, &Grid[i]);
        }
    }

    SDL_SetRenderDrawColor(RenA, 0, 125,255,0xFF);
    SDL_RenderDrawRect(RenA, &DeadZone);

}

void Map::ResetZoom()
{
    int OriginX = 0;
    int OriginY = 0;

    for(int i = 0; i < Grid.size(); i++) ///Change Grid width
    {
        Grid[i].w = TileSize;
        Grid[i].h = TileSize;
    }
    for(int i = 0; i < MapSizeY; i++)
    for(int j = 0; j < MapSizeX; j++)
    {
            Grid[j+(MapSizeX*i)].x = (j * Grid[i].w) + OriginX;
            Grid[j+(MapSizeX*i)].y = (i * Grid[i].h) + OriginY;
            Tiles[j+(MapSizeX*i)].Set_LOC(Grid[j+(MapSizeX*i)]);
    }
}

void Map::ZoomIN()
{
    int OriginX = Grid[0].x;
    int OriginY = Grid[0].y;

    for(int i = 0; i < Grid.size(); i++) ///Change Grid width
    {
        Grid[i].w = Grid[i].w * 2;
        Grid[i].h = Grid[i].h * 2;
    }
    for(int i = 0; i < MapSizeY; i++)
    for(int j = 0; j < MapSizeX; j++)
    {
            Grid[j+(MapSizeX*i)].x = (j * Grid[i].w) + OriginX;
            Grid[j+(MapSizeX*i)].y = (i * Grid[i].h) + OriginY;
            Tiles[j+(MapSizeX*i)].Set_LOC(Grid[j+(MapSizeX*i)]);
    }

}

void Map::ZoomOUT()
{
    int OriginX = Grid[0].x;
    int OriginY = Grid[0].y;

    for(int i = 0; i < Grid.size(); i++) ///Change Grid width
    {
        Grid[i].w = Grid[i].w / 2;
        Grid[i].h = Grid[i].h / 2;
    }
    for(int i = 0; i < MapSizeY; i++)
    for(int j = 0; j < MapSizeX; j++)
    {
            Grid[j+(MapSizeX*i)].x = (j * Grid[i].w) + OriginX;
            Grid[j+(MapSizeX*i)].y = (i * Grid[i].h) + OriginY;
            Tiles[j+(MapSizeX*i)].Set_LOC(Grid[j+(MapSizeX*i)]);
    }
}


void Map::exportFile() /// Exports the file will upgrade so it doesn't suck later;
{
  std::ofstream myfile;

  std::string open_me = "Export/" + MapName + ".map";

  myfile.open (open_me.c_str());

  std::string output = "";
  output = "[MapName]\n" + MapName + "\n\n";

  output += "[Size]\n" + int_to_string3char(MapSizeX) + " " + int_to_string3char(MapSizeY) + "\n\n";

  output += "[Map]\n";

  int counterZZ = 0;
  for(int i = 0; i < Tiles.size(); i++)
  {
     if(counterZZ != MapSizeX)
      counterZZ++;


      output += Tiles[i].Get_TileData() + " ";

      if(counterZZ == MapSizeX)
      {
          output += "\n";
          counterZZ = 0;
      }


  }


  myfile << output;
  //myfile << "Writing this to a file.\n";
  myfile.close();
}



void Map::PlaceTile(int index)
{
    if(HoveringTile != -1 && !TileIsThere[HoveringTile])
    {

        std::string TileCode = int_to_string(Layer) + int_to_string3char(index) + MOD; /// will need a better mod thing later

        NewTile(RenA,TileTexture,index,Grid[HoveringTile].x,Grid[HoveringTile].y,TileCode);
    }
    else if(HoveringTile != -1 && TileIsThere[HoveringTile])
    {

        std::string TileCode = int_to_string(Layer) + int_to_string3char(index) + MOD; /// will need a better mod thing later

        FillTile(index,Grid[HoveringTile].x,Grid[HoveringTile].y,TileCode);
    }

}



void Map::NewTile(SDL_Renderer* RenZ, SDL_Texture *Texture, int index ,int x, int y, std::string TileData)
{
    Tile NEWtile;

    NEWtile.init(RenZ, Texture, index, x, y, TileData);

    Tiles.push_back(NEWtile);
}


void Map::FillTile(int index ,int x, int y, std::string TileData)
{
    Tiles[HoveringTile].change_tile(index,x,y,TileData,Grid[0].w,Grid[0].h);
}



bool Map::checkCollision( SDL_Rect a, SDL_Rect b )
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
