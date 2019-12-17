#include "Game.h"


void Game::run() //main game loop this will also keep game time.
{
    init();
    std::cout << Name_of_app << " $> Basic systems running. \n";

    const int SCREEN_FPS = 60;
    const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

    //The frames per second timer
    GTimer fpsTimer;

    //The frames per second cap timer
    GTimer capTimer;


    //Start counting frames per second
    int countedFrames = 0;
    fpsTimer.start();

    while(Running) //game loop
    {
            //Start cap timer
            capTimer.start();



            //Calculate and correct fps
            float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
            if( avgFPS > 2000000 )
            {

                avgFPS = 0;
            }

            //INPUTS.update();
            //Running = INPUTS.Quit();


                        INPUTS.update();
                        Running = INPUTS.Quit();

                draw();
                update();


                //If frame finished early
                int frameTicks = capTimer.getTicks();
                if( frameTicks < SCREEN_TICKS_PER_FRAME )
                {
                    //Wait remaining time
                    SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
                }
    }


//   Destroy_all();// exits everything

}



void Game::init()
{
    ///NET CODE SHIT///
    std::cout << "Run multiplayer mode? Y/n\n";
    std::string temp_get;
    std::cin >> temp_get;




    if(temp_get == "y" || temp_get == "Y" || temp_get == "Yes" || temp_get == "YES" || temp_get == "yes" || temp_get == "yeah" || temp_get == "Yeah" || temp_get == "YEAH")
    {
            std::cout << "Are you the host? Y/n\n";
            std::cin >> temp_get;

            if(temp_get == "y" || temp_get == "Y" || temp_get == "Yes" || temp_get == "YES" || temp_get == "yes" || temp_get == "yeah" || temp_get == "Yeah" || temp_get == "YEAH")
            {

                NetCODE.Set_Host(true);

            }
            else
            {
                NetName = "C1"; /// ///////////////////////////////////////////////////////////////THIS IS the Cient 1 idk might need to make it better later but ik onweirfjawoeifjawef
                NetCODE.Set_Host(false);
            }



                std::cout << "Enter remote IP ( 127.0.0.1  for local connections ) : ";
                std::cin >> IP;
                std::cout << "...and remote port : ";
                std::cin >> remotePort;

                std::cout << "Enter local port : ";
                std::cin >> localPort;
                NetCODE.Init( IP, remotePort, localPort );

    }
    else if(temp_get != "q" && temp_get != "w" && temp_get != "e")
    {
        No_Net_Commands = true;

        IP = "0";
        remotePort = 0;
        localPort = 0;
    }

    else if(temp_get == "q")
    {
        std::cout << "Using q quick command\n";

        NetCODE.Set_Host(true);
        IP = "127.0.0.1";
        remotePort = 44;
        localPort = 45;
        NetCODE.Init( IP, remotePort, localPort );

    }
    else if(temp_get == "w")
    {
        std::cout << "Using w quick command\n";

        NetName = "C1";
        NetCODE.Set_Host(false);
        IP = "127.0.0.1";
        remotePort = 45;
        localPort = 44;
        NetCODE.Init( IP, remotePort, localPort );

    }
    else if(temp_get == "e")
    {
        std::cout << "Using e quick command (NOTE THIS ONE DOESN'T WORK)\n";

        NetName = "C2";
        NetCODE.Set_Host(false);
        IP = "127.0.0.1";
        remotePort = 45;
        localPort = 46;
        NetCODE.Init( IP, remotePort, localPort );

    }










    ///NET CODE SHIT///

    Font = TTF_OpenFont("Data/clacon.ttf", 24);

    CommandLineTextBuff = "";
    CommandBox.init(Ren0,Font,CommandLineTextBuff, 10, 430, 0, 24);
    CommandBox.Match_Widtha();



            int sizeofthingbing = 16;

            MesSlot01.init(Ren0, Font, " ", 10,10,1,sizeofthingbing);
            MesSlot02.init(Ren0, Font, " ", 10,10 + (16*1),1,sizeofthingbing);
            MesSlot03.init(Ren0, Font, " ", 10,10 + (16*2),1,sizeofthingbing);
            MesSlot04.init(Ren0, Font, " ", 10,10 + (16*3),1,sizeofthingbing);


            MesSlot01.set_basesize(sizeofthingbing);
            MesSlot02.set_basesize(sizeofthingbing);
            MesSlot03.set_basesize(sizeofthingbing);
            MesSlot04.set_basesize(sizeofthingbing);



    initmouse();

    FreeCam = loadTexture("Data/UI/FreeCam.png");
    cameraMASTER.init(Ren0, FreeCam);

    ///I should make it that the first 100 ids are for players so it can alway find it and such idk might do that
    cameraMASTER.SetTarget(0); //this should be the player I hope?

    TextBox = loadTexture("Data/UI/TextBoxBackDrop.png");
    PlayerSprite = loadTexture("Data/Sprites/Player.png");
    OctorkSprite = loadTexture("Data/Sprites/Octorok.png");
    TileSheetFloor = loadTexture("Data/MAP/TileMapFloor.png");
    TRexSprite = loadTexture("Data/Sprites/TRex.png");
    BushSFX = loadTexture("Data/Sprites/Effects/Bush.png");


    //AddNewEnity(1,64*7,64*7,true,0);

    //AddNewEnity(5,64*17,588,false,0);

    //AddNewEnity(1,1200,1100,false,0);

    //AddNewEnity(7,64*28,64*8,false,0);

    //AddNewEnity(5,64*10,64*20,false,0);


    MapMaster.init(Ren0,TileSheetFloor,"Data/MAP/map_Files/Test.map");




}

void Game::draw()
{
        //Clear screen
        SDL_SetRenderDrawColor( Ren0, 29, 30, 34, 0xFF );
        SDL_RenderClear( Ren0 );

        MapMaster.draw();

        for(int i = 0; i < Enities.size(); i++)
        {
            if(Enities[i] == NULL)
            {
                std::cout << "ERROR: Enity was not linked.\n";
            }
            Enities[i]->draw();
        }


        for(int i = 0; i < SFX.size(); i++)
        {
            SFX[i].draw();
        }



            cameraMASTER.draw();


            if(MessageBl01)
                MesSlot01.draw();
            if(MessageBl02)
                MesSlot02.draw();
            if(MessageBl03)
                MesSlot03.draw();
            if(MessageBl04)
                MesSlot04.draw();


        if(Type_Mode)
        {
            SDL_RenderCopy(Ren0, TextBox, NULL, &ScreenWH);
            CommandBox.draw();
        }



        drawmouse();

                SDL_RenderPresent( Ren0 );

}

void Game::update()
{

    /// NETWORK LOGIC SHOULD BE READ IN HERE ///

    INPUTS.Set_Typing_Mode(Type_Mode);


        if(timerC != timerCMAX)
        timerC++;

    if(Type_Mode)
    updatekeys_TypeMode();
    else
    updatekeys();

    updateNetCodeLogic();


    CommandBox.update();
    CommandBox.update_Message(CommandLineTextBuff);
    MesSlot01.update();
    MesSlot02.update();
    MesSlot03.update();
    MesSlot04.update();


    updatemouse();
    MapMaster.update(OFFSETX,OFFSETY);




    /// Netcode say hi and make sure connecton is good
    if(!ConnectedInit && !HandShakeStated)
    {

        NetCODE.SendData("#" + NetName + "C" + "$");

    }


    ///Check For More MapPOPulation stuff//

    if(MapMaster.Get_TypeEnityCan().size() != 0) /// This is just for the E layer
    {
        for(int i = 0; i < MapMaster.Get_TypeEnityCan().size(); i++)
        {

            bool isittheplayer = false;
            if(MapMaster.Get_isplayerCan()[i] == 'p' )
            {
                ///It will have to do more then this when warps are working but for now this should be ok
                isittheplayer = true;

            }


            if((!FirstSpawnUseMap && MapMaster.Get_isplayerCan()[i] == 'p') && NetName == "S1" || (MapMaster.Get_isplayerCan()[i] != 'p' && NetName == "S1"))
            {
                if(!FirstSpawnUseMap)
                FirstSpawnUseMap = true;
                AddNewEnity(MapMaster.Get_TypeEnityCan()[i],64*MapMaster.Get_XofEnityCan()[i],64*MapMaster.Get_YofEnityCan()[i],isittheplayer,MapMaster.Get_TeamEnityCan()[i]);

            }

            if((!FirstSpawnUseMap && MapMaster.Get_isplayerCan()[i] == 'p') && NetName == "C1" || (MapMaster.Get_isplayerCan()[i] != 'p' && NetName == "C1")) /// Net code spawner i don't know if i'm going to use this one but for right now i'm going to use this
            {
                if(!FirstSpawnUseMap)
                FirstSpawnUseMap = true;
                AddNewEnity(MapMaster.Get_TypeEnityCan()[i],64*((MapMaster.Get_XofEnityCan()[i])+1),64*MapMaster.Get_YofEnityCan()[i],isittheplayer,MapMaster.Get_TeamEnityCan()[i]);

            }


            ///AddNewEnity(MapMaster.Get_TypeEnityCan()[i],64*MapMaster.Get_XofEnityCan()[i],64*MapMaster.Get_YofEnityCan()[i],isittheplayer,MapMaster.Get_TeamEnityCan()[i]);



        }

        MapMaster.Clear_EnityCan();
    }

    ///Check for more balblablalbalbalbla///

    for(int i = 0; i < Enities.size(); i++)
    {

                                ///No sync command thing
                    if(Enities[i]->CheckifPlayer())
                        if(Enities[i]->Get_XSpeed() != 0 || Enities[i]->Get_YSpeed() || Enities[i]->Get_attackLock())
                            PlayMovement = true;
                        else
                            PlayMovement = false;



        /// /////////////////////WALL COLISION LOGIC ////////////////////////// ///

        //std::vector<char[3]> Tiles;

        for (int j = 0; j < MapMaster.Get_Amount_Of_Tiles(); j++)
        {


                    if(DoPlayerWarpLogic && MapMaster.Get_MOD1(j) == 'P' ) /// Used for warping logic
                    {
                        WarpCan.x = MapMaster.Get_Rect(j).x;
                        WarpCan.y = MapMaster.Get_Rect(j).y;

                        std::cout << "X and Y of warp are : " << WarpCan.x << " , " << WarpCan.y << std::endl;

                        int Temp_TargetID = IDGet;

                        AddNewEnity(WarpCan.type,WarpCan.x,WarpCan.y,WarpCan.Player,WarpCan.team);
                        Enities[Enities.size()-1]->Set_DIR(WarpCan.dir);

                        std::cout << "NEW SPAWN IS : " << Enities[Enities.size()-1]->Get_DIR() << std::endl;

                        cameraMASTER.SetTarget(Temp_TargetID);

                        //Enities[Enities.size()-1]->Set_WarpLock(true);
                        CenterCam = true;
                        DoPlayerWarpLogic = false;
                    }



            if(MapMaster.Get_MOD1(j) == 'W' || (MapMaster.Get_MOD1(j) == 'D' && MapMaster.Get_MOD3(j) != 'A')) //and others if needed
            {


                if(!Enities[i]->Check_Colisonwiththing()&& checkCollision(Enities[i]->Get_HIT(), MapMaster.Get_Rect(j)))
                {
                       Enities[i]->ColisionWithSomthing();
                }

                if( MapMaster.Get_MOD1(j)  == 'D' &&  checkCollision(Enities[i]->Get_DMGB(), MapMaster.Get_Rect(j)) && (Enities[i]->Get_Type() == 1 || Enities[i]->Get_Type() == 7))
                {
                    if(MapMaster.Get_MOD2(j) == '0' && MapMaster.Get_MOD3(j) == '1') ///for bushes
                    {
                        MapMaster.Push_Clip_a_Tile(j);
                        SDL_Rect TEMP;
                        TEMP = MapMaster.Get_Rect(j);

                        NEWEffect(BushSFX, TEMP.x-64, TEMP.y-80, 8, 5, 2*64, 2*80);
                        MapMaster.Set_MOD3(j, 'A');
                    }
                }

            }

            if(MapMaster.Get_MOD1(j) == 'P' )
            {

                if(Enities[i]->CheckifPlayer() && !Enities[i]->Get_WarpLock() && checkCollision(Enities[i]->Get_HIT(), MapMaster.Get_Rect(j)))
                {




                    std::vector<PortalCan> TEMP;

                    TEMP = MapMaster.Get_PortalLinks();

                    for(int r = 0; r < TEMP.size(); r++)
                    {
                        //std::cout << "A,B   D,E : " << TEMP[r].Get_SourceID(0) << TEMP[r].Get_SourceID(1) << " | " << MapMaster.Get_MOD2(j) << MapMaster.Get_MOD3(j) << "\n";

                        if(TEMP[r].Get_SourceID(0) == MapMaster.Get_MOD2(j) && TEMP[r].Get_SourceID(1) == MapMaster.Get_MOD3(j) )
                        {
                            //std::cout << "FOUND IT!";

                            Enities[i]->Set_WarpLock(true);

                            MapMaster.Switch_Map(TEMP[r].Get_TargetMAP());

                            UnloadMap();


                            WarpCan.type = Enities[i]->Get_Type();
                            WarpCan.team = Enities[i]->Get_Team();
                            WarpCan.dir = Enities[i]->Get_DIR();
                            DoPlayerWarpLogic = true;
                            break;
                            /// Do this later so you get the right tile of where you are ment to go
                            ///AddNewEnity(Enities[i]->Get_Type(),Enities[i]->Get_LOC().x,Enities[i]->Get_LOC().y,true,Enities[i]->Get_DIR());



                        }



                    }


                }

            else if(Enities[i]->CheckifPlayer() && Enities[i]->Get_WarpLock() && !checkCollision(Enities[i]->Get_HIT(), MapMaster.Get_Rect(j)))
            {
                if(TimerW == TimerWMAX)
                {
                    Enities[i]->Set_WarpLock(false);
                    TimerW = 0;
                }
                else if(TimerW != TimerWMAX)
                TimerW++;


            }


            }




        }



        /// /////////////////////WALL COLISION LOGIC ////////////////////////// ///



        ///Colision logic///
        bool NoColision = true;
        int NEWI = -1;


        for(int j = 0; j < Enities.size(); j++)
        {
            if(i != j)//make sure it's not hitting it's self
            {
                ///check attack
                if(Enities[i]->Get_Team() != Enities[j]->Get_Team() || Enities[j]->Get_Team() == 0 || Enities[j]->Get_Team() != 3)
                {
                    if(checkCollision(Enities[i]->Get_DMGB(), Enities[j]->Get_HIT() ))
                    {
                        Enities[j]->Take_Damage(Enities[i]->Get_DIR(), Enities[i]->Get_EnityisDamaging());
                    }
                }
                ///check colison with enity
                if(!Enities[i]->Check_Colisonwiththing()&& checkCollision(Enities[i]->Get_HIT(), Enities[j]->Get_HIT()))
                {
                    Enities[i]->ColisionWithSomthing();
                    NEWI = i;
                    //break;
                    ///Enities[j]->ColisionWithSomthing();
                }

                /*
                if(NEWI != -1)
                {
                    if(Enities[NEWI]->Check_Colisonwiththing())
                    {


                        if(!checkCollision(Enities[NEWI]->Get_HIT(), Enities[j]->Get_HIT()))
                        {
                            if(NoColision)
                            NoColision = true;
                        }
                        else
                        {
                            NoColision = false;
                        }

                        if(NoColision)
                        {
                            std::cout << "Fuck off mate!";
                            NEWI = -1;
                            Enities[i]->END_Colisonwiththing();
                            break;
                        }

                    }
                }

                else if(Enities[i]->Check_Colisonwiththing())
                {


                    if(!checkCollision(Enities[i]->Get_HIT(), Enities[j]->Get_HIT()))
                    {
                        if(NoColision)
                        NoColision = true;
                    }
                    else
                    {
                        NoColision = false;
                    }

                    if(NoColision)
                    {
                        std::cout << "Fuck off mate!";
                        Enities[i]->END_Colisonwiththing();
                        break;
                    }

                }
                */


            }
        }


        if(Enities[i]->Check_SHOTMake()) /// make shot
        {

            AddNewEnity(Enities[i]->GET_SHOTTYPE(),255,255,false,Enities[i]->Get_DIR()); // fix the 255 so it makes sence;
            Enities[i]->ShotMade();
        }


        Enities[i]->update(OFFSETX,OFFSETY);
        if(Enities[i]->GetID() == cameraMASTER.GetTarget()) //get target info for cam
        {
                if(CenterCam)//Centers the cam if true
                {
                    cameraMASTER.CenterCam( Enities[i]->Get_X() , Enities[i]->Get_Y() );
                    CenterCam = false;
                }

            double Xaa = Enities[i]->Get_XSpeed();
            double Yaa = Enities[i]->Get_YSpeed();
            cameraMASTER.Get_Cam_INFO(Xaa, Yaa, Enities[i]->Get_LOC());



        }




    }


    ///Check no Collisoin/// sadly another loop is needed for this
    for(int i = 0; i < Enities.size(); i++)
    {
        bool NOTHITTINGTHINGS = true;
        for(int j = 0; j < Enities.size(); j++)
        {
            if(j != i) //allways check this
            {
                if(Enities[i]->Check_Colisonwiththing()&& checkCollision(Enities[i]->Get_HIT(), Enities[j]->Get_HIT()))
                {
                    NOTHITTINGTHINGS = false;
                }
            }


        }
        if(NOTHITTINGTHINGS)
        Enities[i]->END_Colisonwiththing();
    }


    ///Check to draw tile ///

    for (int i = 0; i < MapMaster.Get_Amount_Of_Tiles(); i++)
    {
        if(checkCollision(cameraMASTER.Get_DRAWZONE(),MapMaster.Get_Rect(i)))
        {
            MapMaster.SetDraw_Draws(i,true);
        }
        else if(MapMaster.Check_Draws(i) && !checkCollision(cameraMASTER.Get_DRAWZONE(),MapMaster.Get_Rect(i)))
        {
            MapMaster.SetDraw_Draws(i,false);
        }
    }

    ///Check to draw tile ///




    ///EFFECT CLEANUP and update///
    for(int i = 0; i < SFX.size(); i++)
    {

        SFX[i].update(OFFSETX,OFFSETY);

        if(SFX[i].Check_Ended())
        {
            if(i != 0)
            SFX.erase(SFX.begin() + i);
            if(i == 0)
            SFX.erase(SFX.begin());

        }
    }





    cameraMASTER.updateCam();
    OFFSETX = cameraMASTER.Get_OFFSETX();
    OFFSETY = cameraMASTER.Get_OFFSETY();
    cameraMASTER.ZeroOUT();


    OFFSETChs_X += OFFSETX;
    OFFSETChs_Y += OFFSETY;


    /// NETWORK LOGIC SHOULD BE SENT OUT HERE ///
    if(!No_Net_Commands)
    {
        NetCODE.CheckForData();
    }







    if(!Did_Other_Player_Spawn && ConnectedInit && !HandShakeStated) /// this net code will spawn the other player
    {

        //ResetMaps_Dtyeps = true;
        /// Need a way to sync Dtypes but i'll worry about that after warps

        int Index_z = 0;
        int x_temp = 0;
        int y_temp = 0;
        int dir_z = 0;
        int index_ZZ = -1;

        for(int i = 0; i < Enities.size(); i++)
        {
            if(Enities[i]->CheckifPlayer())
            {

                Index_z = Enities[i]->Get_Type();
                x_temp = Enities[i]->Get_X();
                y_temp = Enities[i]->Get_Y();
                dir_z = Enities[i]->Get_DIR();
                index_ZZ = i;
            }
        }

        std::string MessagetoSend;
        if(Enities[index_ZZ]->CheckifPlayer())
        {



        std::cout << "!!!!!!!! X and Y of Spawn Command Should be by this guy : " << x_temp << " | " << y_temp << "\n";


        if(NetName == "S1")
        {
            x_temp + TileSize;
        }
        if(NetName == "C1")
        {
            x_temp - TileSize;
        }

        std::string INDEXTRUE = int_to_string(Index_z);
        std::string XTRUE = int_to_string(x_temp);
        std::string YTRUE = int_to_string(y_temp);
        std::string DIRTRUE = int_to_string(dir_z);




        MessagetoSend = "#" + NetName + "S" + INDEXTRUE + "|" + XTRUE + "|" + YTRUE + "|" + DIRTRUE + "$";




        NetCODE.SendData(MessagetoSend);


        Did_Other_Player_Spawn = true;
        index_ZZ = -1;
        }
    }


    /// Syne players every 180 cyles
    if(timerSycn != timerSycnMAX && ConnectedInit && !HandShakeStated && !PlayMovement)
    {
        timerSycn++;
    }

    if(PlayMovement)
    {
        //timerSycn = 0;

    }

    if(timerSycn == timerSycnMAX)
    {
        Player_Sync = true;
        timerSycn = 0;
    }

    if(timerESync != timerESyncMAX)
    {
        timerESync++;
    }

    if(timerESync == timerESyncMAX)
    {
        Enities_Sync = true;/// This dosn't work so i'm turnning it off for rithing nwo
        timerESync = 0;
    }





if(ConnectedInit && !HandShakeStated && Player_Sync)
{


        ///Send Possition to other player
        for(int i = 0; i < Enities.size(); i++)
        {
            if(Enities[i]->CheckifPlayer())
            {

                std::string UpdatePos;



                UpdatePos = "#" + NetName + "V" + int_to_string(Enities[i]->Get_X() - OFFSETChs_X) + "|" + int_to_string(Enities[i]->Get_Y() - OFFSETChs_Y) +"$";



                NetCODE.SendData(UpdatePos);



            }
        }

        Player_Sync = false;

}

/// THIS DONES"T WORK RIGHT NOW TURNNING OFF THE BOOL THAT TURNS IT ON Enityes_Sync A Few line above to false
if(ConnectedInit && !HandShakeStated && Enities_Sync && NetName == "S1")
{

        for(int i = 0; i < Enities.size(); i++)
        {
            if(Enities[i]->CheckifPlayer() == false && Enities[i]->Check_Player2() == false)
            {

                std::string UpdatePos = "";

                if(Enities[i]->CheckifPlayer() )
                    std::cout << "ERROR!";



                UpdatePos = "#" + NetName + "v" + int_to_string(Enities[i]->Get_X() - OFFSETChs_X) + "|" + int_to_string(Enities[i]->Get_Y() - OFFSETChs_Y)+ "|" + int_to_string(Enities[i]->GetID()) +"$";



                NetCODE.SendData(UpdatePos);



            }
        }


    Enities_Sync = false;
}






if(ResetMaps_Dtyeps)
{
    ResetMaps_Dtypes();
    ResetMaps_Dtyeps = false;

}



}



void Game::ResetMaps_Dtypes()
{

    for (int j = 0; j < MapMaster.Get_Amount_Of_Tiles(); j++)
    {
                if( MapMaster.Get_MOD1(j)  == 'D')
                {
                    if(MapMaster.Get_MOD2(j) == '0' && MapMaster.Get_MOD3(j) == 'A') ///for bushes
                    {
                        MapMaster.Push_Clip_a_tile_Back(j);
                        MapMaster.Set_MOD3(j, '1');
                    }
                }
    }


}







///ENITY CREATOR

void Game::AddNewEnity(int type,int Xstart,int Ystart, bool Playeryn, int DIROFMOVE)
{
    /// 1 = Player;
    /// 2 = NULL;
    /// 3 = NULL;
    /// 4 = NULL;
    /// 5 = Octoroks;
    /// 6 = NULL;
    /// 7 = TRexes;
    /// 8 = NULL;
    /// 9 = NULL;
    ///10 = NULL;

/*
    if(type == 1)
    {
        Player NewPlayer;
        NewPlayer.init(Ren0,PlayerSprite,BaseSpeed,1,IDGet,Xstart,Ystart,Playeryn);


        Players.push_back(NewPlayer);

        Enity *NEWenity;


        //for (std::vector<int>::iterator it = Players.begin() ; it != Players.end(); ++it)
        ///for(int i = 0; i < Players.size()+1; i++)
        ///{
 ///           std::cout << "SIZE = " << Players.size() << " | i = " << i << std::endl;
            //if(i == Players.size()-1 && i == 0)
                //NEWenity = &Players[i];
            //else if(i == Players.size())
                //NEWenity = &Players[i];

        for(int i = 0 ; i < Players.size(); i++)
        {
            if(Enities.size() > i)
            Enities[i] = &Players[i];
            else
            {
                NEWenity = &Players[i];
                Enities.push_back(NEWenity);
                std::cout << "MADE Player" << std::endl;
            }

             //std::cout << i <<" | " <<"NEWenity = " << Enities[i] << " | Players = " << &Players[i] << std::endl;
            playerinexer = i; //if this works just use this to off set the next object type and so on and so on.

        }
        ///NEWenity = &Players[playerinexer];

        ///}




        if(NEWenity == NULL)
            std::cout << "ERROR: The NEWenity was not filled E-0001\n";

            //std::cout << "===========================================\n";

        //Enities.push_back(NEWenity);


    }
    if(type == 5)
    {
        ///Octoroks

        Octorok NEWOctork;
        NEWOctork.init(Ren0,OctorkSprite,BaseSpeed-1,1,IDGet,Xstart,Ystart,Playeryn);


        Octoroks.push_back(NEWOctork);

        Enity *NEWenity;


        for(int i = 0 ; i < Octoroks.size(); i++)
        {


            if(Enities.size() > i+playerinexer)
            Enities[i+playerinexer] = &Octoroks[i];
            else
            {
                NEWenity = &Octoroks[i];
                Enities.push_back(NEWenity);
                std::cout << "MADE OCTOROK" << std::endl;
            }

             //std::cout << i <<" | " <<"NEWenity = " << Enities[i] << " | Players = " << &Players[i] << std::endl;
            playerinexer = i; //if this works just use this to off set the next object type and so on and so on.

        }

        if(NEWenity == NULL)
            std::cout << "ERROR: The NEWenity was not filled E-0001\n";


    }

    if(type == 6)
    {
        ///OctorokROCK

        OctorokROCK NEWOctorokROCK;
        NEWOctorokROCK.init(Ren0,OctorkSprite,BaseSpeed+2,1,IDGet,Xstart,Ystart,false);//Playeryn);
        NEWOctorokROCK.Set_DIR(DIROFMOVE);

        OctorokROCKs.push_back(NEWOctorokROCK);

        Enity *NEWenity;


        for(int i = 0 ; i < OctorokROCKs.size(); i++)
        {


            if(Enities.size() > i+playerinexer)
            Enities[i+playerinexer] = &OctorokROCKs[i];
            else
            {
                NEWenity = &OctorokROCKs[i];
                Enities.push_back(NEWenity);
                std::cout << "MADE OCTOROKROCK" << std::endl;
            }

             //std::cout << i <<" | " <<"NEWenity = " << Enities[i] << " | Players = " << &Players[i] << std::endl;
            playerinexer = i; //if this works just use this to off set the next object type and so on and so on.

        }

        if(NEWenity == NULL)
            std::cout << "ERROR: The NEWenity was not filled E-0001\n";


    }

*/

    Enity *NEWenity;

    if(type == 1)
    {
        Player NewPlayer;
        NewPlayer.init(Ren0,PlayerSprite,BaseSpeed,1,IDGet,Xstart,Ystart,Playeryn,type);

           std::cout << "A Player is Spawned at : " << Xstart << " , " << Ystart << std::endl;

        Players.push_back(NewPlayer);



    }

    if(type == 5)
    {
        ///Octoroks

        Octorok NEWOctork;
        NEWOctork.init(Ren0,OctorkSprite,BaseSpeed-1,1,IDGet,Xstart,Ystart,Playeryn,type);




        Octoroks.push_back(NEWOctork);




    }





    if(type == 6)
    {
        ///OctorokROCK

        OctorokROCK NEWOctorokROCK;
        NEWOctorokROCK.init(Ren0,OctorkSprite,BaseSpeed+2,1,IDGet,Xstart,Ystart,false,type);//Playeryn);
        NEWOctorokROCK.Set_DIR(DIROFMOVE);

        OctorokROCKs.push_back(NEWOctorokROCK);

    }

    if(type == 7)
    {
        ///TRexes

        TRex NEWTRex;
        NEWTRex.init(Ren0,TRexSprite,BaseSpeed+2,1,IDGet,Xstart,Ystart,Playeryn,type);
        TRexes.push_back(NEWTRex);
    }




        for(int i = 0 ; i < Players.size(); i++)
        {
            if(Enities.size() > i)
            Enities[i] = &Players[i];
            else
            {
                NEWenity = &Players[i];
                Enities.push_back(NEWenity);
                //std::cout << "MADE Player" << std::endl;
            }

             //std::cout << i <<" | " <<"NEWenity = " << Enities[i] << " | Players = " << &Players[i] << std::endl;
            playerinexer = i; //if this works just use this to off set the next object type and so on and so on.

        }

        //std::cout << "Playerinexer : " << playerinexer << std::endl;

        for(int i = 0 ; i < Octoroks.size(); i++)
        {


            if(Enities.size() > i+playerinexer+1)
            Enities[i+playerinexer+1] = &Octoroks[i];
            else
            {
                NEWenity = &Octoroks[i];
                Enities.push_back(NEWenity);
                //std::cout << "MADE OCTOROK" << std::endl;
            }

             //std::cout << i <<" | " <<"NEWenity = " << Enities[i] << " | Players = " << &Players[i] << std::endl;
            playerinexer += i; //if this works just use this to off set the next object type and so on and so on.

        }


        //std::cout << "Playerinexer : " << playerinexer << std::endl;


            for(int i = 0 ; i < OctorokROCKs.size(); i++)
        {


            if(Enities.size() > i+playerinexer+1)
            Enities[i+playerinexer+1] = &OctorokROCKs[i];
            else
            {
                NEWenity = &OctorokROCKs[i];
                Enities.push_back(NEWenity);
                //std::cout << "MADE OCTOROKROCK" << std::endl;
            }

             //std::cout << i <<" | " <<"NEWenity = " << Enities[i] << " | Players = " << &Players[i] << std::endl;
            playerinexer += i; //if this works just use this to off set the next object type and so on and so on.

        }

        for(int i = 0 ; i < TRexes.size(); i++)
        {


            if(Enities.size() > i+playerinexer+1)
            Enities[i+playerinexer+1] = &TRexes[i];
            else
            {
                NEWenity = &TRexes[i];
                Enities.push_back(NEWenity);
                //std::cout << "MADE OCTOROK" << std::endl;
            }

             //std::cout << i <<" | " <<"NEWenity = " << Enities[i] << " | Players = " << &Players[i] << std::endl;
            playerinexer += i; //if this works just use this to off set the next object type and so on and so on.

        }


                  if(NEWenity == NULL)
            std::cout << "ERROR: The NEWenity was not filled E-0001\n";

        //playerinexer = 0;


        //std::cout << "Enitys : " << Enities.size() << std::endl;


        IDGet++;
        playerinexer = 0;


}



void Game::EnityUpdateList() //Just Noticed i need to re get all this setup so that i works right.
{
    /*
        for(int i = 0 ; i < Players.size(); i++)
        {
            if(Enities.size() > i)
            Enities[i] = &Players[i];
            else
            {
                NEWenity = &Players[i];
                Enities.push_back(NEWenity);
                //std::cout << "MADE Player" << std::endl;
            }

             //std::cout << i <<" | " <<"NEWenity = " << Enities[i] << " | Players = " << &Players[i] << std::endl;
            playerinexer = i; //if this works just use this to off set the next object type and so on and so on.

        }

        //std::cout << "Playerinexer : " << playerinexer << std::endl;

        for(int i = 0 ; i < Octoroks.size(); i++)
        {


            if(Enities.size() > i+playerinexer+1)
            Enities[i+playerinexer+1] = &Octoroks[i];
            else
            {
                NEWenity = &Octoroks[i];
                Enities.push_back(NEWenity);
                //std::cout << "MADE OCTOROK" << std::endl;
            }

             //std::cout << i <<" | " <<"NEWenity = " << Enities[i] << " | Players = " << &Players[i] << std::endl;
            playerinexer += i; //if this works just use this to off set the next object type and so on and so on.

        }


        //std::cout << "Playerinexer : " << playerinexer << std::endl;


            for(int i = 0 ; i < OctorokROCKs.size(); i++)
        {


            if(Enities.size() > i+playerinexer+1)
            Enities[i+playerinexer+1] = &OctorokROCKs[i];
            else
            {
                NEWenity = &OctorokROCKs[i];
                Enities.push_back(NEWenity);
                //std::cout << "MADE OCTOROKROCK" << std::endl;
            }

             //std::cout << i <<" | " <<"NEWenity = " << Enities[i] << " | Players = " << &Players[i] << std::endl;
            playerinexer += i; //if this works just use this to off set the next object type and so on and so on.

        }
                    if(NEWenity == NULL)
            std::cout << "ERROR: The NEWenity was not filled E-0001\n";

        //playerinexer = 0;


        //std::cout << "Enitys : " << Enities.size() << std::endl;


        IDGet++;
        playerinexer = 0;
        */
}



/// EFFECTS ADDERS ///
void Game::NEWEffect(SDL_Texture *TEX,double X,double Y,int FINALFRAME, int CYCLES)
{
    Effect NEWEFFECT;
    NEWEFFECT.init(Ren0,TEX,X,Y,FINALFRAME,CYCLES);
    SFX.push_back(NEWEFFECT);
}
void Game::NEWEffect(SDL_Texture *TEX,double X,double Y,int FINALFRAME, int CYCLES, int frameX, int frameY)
{
    Effect NEWEFFECT;
    NEWEFFECT.init(Ren0,TEX,X,Y,FINALFRAME,CYCLES,frameX,frameY);
    SFX.push_back(NEWEFFECT);
}

