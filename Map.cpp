#include "Map.h"

void MAP::init(SDL_Renderer *RenZ, SDL_Texture *TileSheetFloor, std::string MapFile)
{
    //MAP MODS
    //z - nothing
    //W - Wall can't pass though no sub mods needed
    //D - Destorable when mod 3 = A then it is like a z stat
        // 01 - Bush any wing will destory and play an effect and it will block movment if not destoryed.
    //P - Portal thing
        // other mods for thing


    RenA = RenZ;
    TileMapFloor = TileSheetFloor;
    MAPfile = MapFile;
    TileSize = 64;

    ///This funtion is no setup to read the file yet but it should make a bucnh of tiles
    Setupmap();


    //NewPortalLink('A','1','A','0',"Test2.map");
    //NewPortalLink('A','0','A','1',"Test.map");



}
void MAP::update(double Xoffset, double Yoffset)
{
    TRUE_X += Xoffset;
    TRUE_Y += Yoffset;


    if(Xoffset != 0 || Yoffset != 0)
    {
        for(int i = 0; i < LOCs.size(); i++)
        {
            Lx[i] = Lx[i] + Xoffset;
            LOCs[i].x = Lx[i];

            Ly[i] = Ly[i] + Yoffset;
            LOCs[i].y = Ly[i];

        }
    }


}
void MAP::draw()
{
    for(int i = 0; i < LOCs.size(); i++)
    {

        if(Draws[i])
        SDL_RenderCopy(RenA,TileMapFloor, &CLIPs[i], &LOCs[i]);


        if(DrawHitBoxs && (MOD1[i] == 'W' || (MOD1[i] == 'D' && MOD3[i] != 'A')))
        {
            SDL_SetRenderDrawColor( RenA, 255, 0, 0, 0xFF );
            SDL_RenderDrawRect(RenA,&LOCs[i]);
        }

    }
}



void MAP::Setupmap()
{
    LOCs.clear();
    CLIPs.clear();

    //use the MAPfile file to draw the map bra
    ///but for now just use this for testing
    /*
    for(int j = 0; j < 9; j++)
    {
        for(int i = 0; i < 9; i++)
        {
            double NEWX;
            double NEWY;

            SDL_Rect NEWTile;
            NEWX = NEWTile.x = i*TileSize;
            NEWY = NEWTile.y = j*TileSize;
            NEWTile.h = NEWTile.w = TileSize;

            SDL_Rect NEWClip;
            NEWClip.x = 1*TileSize;
            NEWClip.y = 1*TileSize;
            NEWClip.w = NEWClip.h = TileSize;

            LOCs.push_back(NEWTile);
            CLIPs.push_back(NEWClip);
            Lx.push_back(NEWX);
            Ly.push_back(NEWY);
        }
    }
    */

    //CreateTile(2,2,0,3,'n');
    //CreateTile(2,3,1,3,'n');
    //CreateTile(3,2,1,2,'n');
    //CreateTile(2,4,1,4,'n');


    LoadFromFile(MAPfile);




}


void MAP::CreateTile(double tileLocX, double tileLocY, int TileIDx, int TileIDy, char OtherTag[3])
{
            double NEWX;
            double NEWY;

            SDL_Rect NEWTile;

            NEWX = NEWTile.x = tileLocX*TileSize;
            NEWY = NEWTile.y = tileLocY*TileSize;
            NEWTile.h = NEWTile.w = TileSize;

            //std::cout << "true tile x and y : " << NEWTile.x << " , " << NEWTile.y << "\n";

             //std::cout << "TileID X AND Y IS : " << TileIDx << " , " << TileIDy << "\n";

            SDL_Rect NEWClip;
            NEWClip.x = TileIDx;//*TileSize;
            NEWClip.y = TileIDy;//*TileSize;
            NEWClip.w = NEWClip.h = TileSize;

            //std::cout << "CLIP X AND Y IS : " << NEWClip.x << " , " << NEWClip.y << "\n";

            LOCs.push_back(NEWTile);
            CLIPs.push_back(NEWClip);
            Lx.push_back(NEWX);
            Ly.push_back(NEWY);
            MOD1.push_back(OtherTag[0]);
            MOD2.push_back(OtherTag[1]);
            MOD3.push_back(OtherTag[2]);
            Draws.push_back(true);
}

void MAP::ClearTile()
{
            LOCs.clear();
            CLIPs.clear();
            Lx.clear();
            Ly.clear();
            MOD1.clear();
            MOD2.clear();
            MOD3.clear();
            Draws.clear();
            PortaLinks.clear();

}

void MAP::LoadFromFile(std::string path)
{

    ClearTile();


  std::string line, maplayer0;
  std::ifstream MAP (path);
  bool Readtiles = false;
  bool getsize = false;
  int mapSx = 0, mapSy = 0;
  if (MAP.is_open())
  {
    while ( getline (MAP,line) )
    {
      //std::cout << line << '\n';
      if(line == "[Size]")
      {
        getsize = true;
        continue;
      }
      if(getsize)
      {
          int index = 0;
          for(char& c : line)
          {
              if(index == 0)
              {
                  int a = c - '0';
                  mapSx += a* 100;
                  //index++;

              }
                            if(index == 1)
              {
                  int a = c - '0';
                  mapSx += a * 10;
                  //index++;
              }
                            if(index == 2)
              {
                  int a = c - '0';
                  mapSx += a;
                  //index++;
              }
                            if(index == 3)
              {
                  //index++;
              }
                            if(index == 4)
              {
                  int a = c - '0';
                  mapSy += a* 100;
                  //index++;
              }
                            if(index == 5)
              {
                  int a = c - '0';
                  mapSy += a* 10;
                  //index++;
              }
                            if(index == 6)
              {
                  int a = c - '0';
                  mapSy += a;
                  //index++;
              }
            index++;
          }
          getsize = false;

      }

      //std::cout << mapSx << " " << mapSy << std::endl;

      if(line == "[Map]")
      {

          Readtiles = true;
          continue;
      }
      if(Readtiles)
      {
         maplayer0 += line;
      }


    }



    MAP.close();
  }

  else std::cout << "Unable to open file";
  bool loading = true;

  int countofbit = 0; //for a layer one thing it should only go up 2 4 bits
  int Layer = -1;
  int x = -TileSize; //for layer 0
  int y = 0; //for layer 0
  int TileType = 0; // for layer 0
  char mod[3] = {' ',' ',' '}; //for layer 0

  char S1 = ' '; /// stuff for layer 10 portal pointers
  char S2 = ' ';
  char R1 = ' ';
  char R2 = ' ';
  std::string RemoteMapName = "";

  /// Stuff for E layer
  int Type = 0;
  int XofEnity = 0;
  int YofEnity = 0;
  char isPlayer = ' ';
  int Team = 0;

  for(char& c : maplayer0)
    {

        if(countofbit == 0 &&c == '0') //&& Layer == 0)
        {
            Layer = 0;
            countofbit ++;
            continue;
        }
        if(countofbit  == 1 && Layer == 0)
        {
            int a = c - '0';
            TileType += a*100;
            countofbit ++;
            continue;
        }
        if(countofbit  == 2 && Layer == 0)
        {
            int a = c - '0';
            TileType += a*10;
            countofbit ++;
            continue;
        }
        if(countofbit  == 3 && Layer == 0)
        {
            int a = c - '0';
            TileType += a;
            countofbit ++;
            continue;
        }
        if(countofbit  == 4 && Layer == 0)
        {
            mod[0] = c;
            countofbit ++;
            continue;
        }

        if(countofbit  == 5 && Layer == 0)
        {
            mod[1] = c;
            countofbit ++;
            continue;
        }


        if(countofbit  == 6 && Layer == 0)
        {
            //countofbit++; //just trying somthing

            mod[2] = c;

            x += TileSize;
            if(x == mapSx*TileSize)
            {
                x=0;
                y += TileSize;
            }

            //std::cout << "Just testing mod0-2 = " << mod[0] << " " << mod[1] << " " << mod[2] << "\n";

                            //std::cout << "TILE: " << TileType << "\n";
                            //type is outputing the right type just need to convert it.


            //NEW_Tile(x,y,type,1,mod);



            double typex = 0;
            double typey = 0;

            if(TileType < 25)
            {
                typex = TileType * TileSize;
                typey = 0;
            }
            else
            {
                typey = TileSize * floor(TileType / 25);
                typex = (TileType % 25) * TileSize;
            }

            //tile witdth 25




            //std::cout << "NEW TILE x: " << x << " y: " << y << " typex: " << typex << " typey: " << typey << " Mod: " << mod << std::endl;


            CreateTile(x/TileSize, y/TileSize, typex, typey, mod);


              countofbit = 0; //for a layer one thing it should only go up 2 4 bits
              Layer = -1;
              TileType = 0; // for layer 0
              mod[0] = ' '; //for layer 0
              mod[1] = ' '; //for layer 0
              mod[2] = ' '; //for layer 0
              continue;

        }
        // end layer 0


        /// ENITY BITS Example
        /*
        AddNewEnity(1,64*7,64*7,true,0);
            //it should do this in game.cpp

        E001007007p0
        E   - Enity
        001 - Type
        007 - X will be * 64
        007 - Y will be * 64
        p   - Player(soft this will only spawn it if the player hasn't gone though a warp)
        0   - Team id.

        E001007007p0
        0123456789*1 = 11 countofbits

          int Type;
          int XofEnity;
          int YofEnity;
          char isPlayer;
          int Team;

        */


        /// Layer 9 This is used for layer making enitys
        if(countofbit == 0 &&c == 'E') //&& Layer == 0)
        {
            Layer = 9;
            countofbit ++;
            continue;
        }
        ///type
        if(countofbit  == 1 && Layer == 9)
        {
            int a = c - '0';
            Type += a*100;
            countofbit ++;
            continue;
        }
        if(countofbit  == 2 && Layer == 9)
        {
            int a = c - '0';
            Type += a*10;
            countofbit ++;
            continue;
        }
        if(countofbit  == 3 && Layer == 9)
        {
            int a = c - '0';
            Type += a;
            countofbit ++;
            continue;
        }

        ///X of Enity
        if(countofbit  == 4 && Layer == 9)
        {
            int a = c - '0';
            XofEnity += a*100;
            countofbit ++;
            continue;
        }
        if(countofbit  == 5 && Layer == 9)
        {
            int a = c - '0';
            XofEnity += a*10;
            countofbit ++;
            continue;
        }
        if(countofbit  == 6 && Layer == 9)
        {
            int a = c - '0';
            XofEnity += a;
            countofbit ++;
            continue;
        }

        ///Y of Enity
        if(countofbit  == 7 && Layer == 9)
        {
            int a = c - '0';
            YofEnity += a*100;
            countofbit ++;
            continue;
        }
        if(countofbit  == 8 && Layer == 9)
        {
            int a = c - '0';
            YofEnity += a*10;
            countofbit ++;
            continue;
        }
        if(countofbit  == 9 && Layer == 9)
        {
            int a = c - '0';
            YofEnity += a;
            countofbit ++;
            continue;
        }

        ///IS player
        if(countofbit == 10 && Layer == 9)
        {
            isPlayer = c;
            countofbit ++;
            continue;
        }

        if(countofbit == 11 && Layer == 9)
        {
            int a = c - '0';
            Team = a;
            countofbit = 0;

            //std::cout << "Enity Called this is it's info Type : " << Type << " X : " << XofEnity << " Y : " << YofEnity << " isPlayer : " << isPlayer << " Team : " << Team << std::endl;

    TypeEnityCan.push_back(Type);
    XofEnityCan.push_back(XofEnity);
    YofEnityCan.push_back(YofEnity);
    isplayerCan.push_back(isPlayer);
    TeamEnityCan.push_back(Team);

    /*

    //these need to be ran then empty
    TypeEnityCan;
    XofEnityCan;
    YofEnityCan;
    isplayerCan;
    TeamEnityCan;
    */




          Type = 0;
          XofEnity = 0;
          YofEnity = 0;
          isPlayer = ' ';
          Team = 0;

          TRUE_X = 0;
          TRUE_Y = 0;

            continue;
        }


        /// Layer 10 will be for portal links
        if(countofbit == 0 &&c == 'P') //&& Layer == 0)
        {
            Layer = 10;
            countofbit ++;
            continue;
        }
        ///type
        if(countofbit  == 1 && Layer == 10)
        {
             S1 = c;
            countofbit ++;
            continue;
        }
        if(countofbit  == 2 && Layer == 10)
        {
             S2 = c;
            countofbit ++;
            continue;
        }
        if(countofbit  == 3 && Layer == 10)
        {
             R1 = c;
            countofbit ++;
            continue;
        }
        if(countofbit  == 4 && Layer == 10)
        {
             R2 = c;
            countofbit ++;
            continue;
        }
        if(countofbit  == 5 && Layer == 10)
        {
             RemoteMapName += c;
            countofbit ++;
            continue;
        }
        if(countofbit  == 6 && Layer == 10)
        {
            if(c != '!')
             RemoteMapName += c;
            countofbit ++;
            continue;
        }
        if(countofbit  == 7 && Layer == 10)
        {
            if(c != '!')
             RemoteMapName += c;
            countofbit ++;
            continue;
        }
        if(countofbit  == 8 && Layer == 10)
        {
            if(c != '!')
             RemoteMapName += c;
            countofbit ++;
            continue;
        }
        if(countofbit  == 9 && Layer == 10)
        {
            if(c != '!')
             RemoteMapName += c;
            countofbit ++;
            continue;
        }
        if(countofbit  == 10 && Layer == 10)
        {
            if(c != '!')
             RemoteMapName += c;
            countofbit ++;
            continue;
        }
        if(countofbit  == 11 && Layer == 10)
        {
            if(c != '!')
             RemoteMapName += c;
            countofbit ++;
            continue;
        }
        if(countofbit  == 12 && Layer == 10) // don't know why i copied and passted this like 100 times should have just used a > oh well
        {
            if(c != '!')
             RemoteMapName += c;
            countofbit ++;


            NewPortalLink(S1,S2,R1,R2,RemoteMapName+".map");


            S1 = ' ';
            S2 = ' ';
            R1 = ' ';
            R2 = ' ';
            RemoteMapName = "";


            continue;

        }




            ///NewPortalLink('A','0','A','1',"Test.map");





    }

}


void MAP::NewPortalLink(char s1, char s2, char d1, char d2, std::string a)
{
    PortalCan NEWPortalCan;

    NEWPortalCan.Set_SourceID(0,s1);
    NEWPortalCan.Set_SourceID(1,s2);

    NEWPortalCan.Set_TargetID(0,d1);
    NEWPortalCan.Set_TargetID(1,d2);

    NEWPortalCan.Set_TargetMAP(a);

    PortaLinks.push_back(NEWPortalCan);

}


