#include "game.h"

void Game::updatekeys()
{
            if(timerA != timerAMax)
            timerA++;


    if( INPUTS.Qispressed()) //Q
    {
        //std::cout << "Q" << std::endl;
        if(timerA == timerAMax)
        {
            NetCODE.Send( "This is a test" );
            timerA = 0;
        }


    }
    if( INPUTS.Wispressed()) //W
    {
        //std::cout << "W" << std::endl;

        std::string SENDME = "#" + NetName + "F" + "01" + "$";


        NetCODE.SendData(SENDME);


    }
    if( INPUTS.Eispressed()) //E
    {
        std::cout << "E" << std::endl;
    }
    if( INPUTS.Rispressed()) //R
    {
        std::cout << "R" << std::endl;
    }
    if( INPUTS.Tispressed()) //T
    {
        std::cout << "T" << std::endl;
    }
    if( INPUTS.Yispressed()) //Y
    {
        std::cout << "Y" << std::endl;
    }
    if( INPUTS.Uispressed()) //U
    {
        if(timerA == timerAMax)
        {
            std::cout << "Reload Map(Ref this for warps)" << std::endl;
            MapMaster.reload_Map();
            EmptyAllEnitys();
            CenterCam = true;
            timerA = 0;
        }

    }
    if( INPUTS.Iispressed()) //I
    {
        //std::cout << "I" << std::endl;
        if(cameraMASTER.CheckCamMode() == 2)
        {
            double x = 0, y = -5;
            SDL_Rect TEMP ={-10000,-10000,0,0};
            cameraMASTER.Get_Cam_INFO(x,y,TEMP);
            Camlastkey = 1;
        }
    }
    if(!INPUTS.Iispressed())
                if(cameraMASTER.CheckCamMode() == 2 && Camlastkey == 1)
        {
            double x = 0, y = 0;
            SDL_Rect TEMP ={-10000,-10000,0,0};
            cameraMASTER.Get_Cam_INFO(x,y,TEMP);
        }

    if( INPUTS.Oispressed()) //O
    {
        if(timerA == timerAMax)
        {
        std::cout << "CenterCam" << std::endl;
        CenterCam = true;
        timerA = 0;
        }
    }
    if( INPUTS.Pispressed()) //P
    {
            if(timerA == timerAMax)
        {
        std::cout << "Toggle Debug" << std::endl;
        if(MapMaster.check_debug())
            MapMaster.toggle_debug(false);
            else
                MapMaster.toggle_debug(true);

        for(int i = 0; i < Enities.size(); i++)
            Enities[i]->Switch_debug();
            timerA = 0;
        }
    }
    if( INPUTS.Aispressed()) //A
    {
        //std::cout << "A" << std::endl;
            std::string SENDME = "#" + NetName + "F" + "20" + "$";


        NetCODE.SendData(SENDME);
    }
    if( INPUTS.Sispressed()) //S
    {
        //std::cout << "S" << std::endl;
            std::string SENDME = "#" + NetName + "F" + "02" + "$";


        NetCODE.SendData(SENDME);
    }
    if( INPUTS.Dispressed()) //D
    {
        //std::cout << "D" << std::endl;
            std::string SENDME = "#" + NetName + "F" + "10" + "$";


        NetCODE.SendData(SENDME);
    }
    if( INPUTS.Fispressed()) //F
    {
        std::cout << "F" << std::endl;
    }
    if( INPUTS.Gispressed()) //G
    {
        std::cout << "G" << std::endl;
    }
    if( INPUTS.Hispressed()) //H
    {
        std::cout << "H" << std::endl;
    }
    if( INPUTS.Jispressed()) //J
    {
        if(cameraMASTER.CheckCamMode() == 2)
        {
            double x = -5, y = 0;
            SDL_Rect TEMP ={-10000,-10000,0,0};
            cameraMASTER.Get_Cam_INFO(x,y,TEMP);
            Camlastkey = 2;
        }
    }
    if( !INPUTS.Jispressed()) //J
    {
        if(cameraMASTER.CheckCamMode() == 2 && Camlastkey == 2)
        {
            double x = 0, y = 0;
            SDL_Rect TEMP ={-10000,-10000,0,0};
            cameraMASTER.Get_Cam_INFO(x,y,TEMP);
        }
    }
    if( INPUTS.Kispressed()) //K
    {
        if(cameraMASTER.CheckCamMode() == 2)
        {
            double x = 0, y = 5;
            SDL_Rect TEMP ={-10000,-10000,0,0};
            cameraMASTER.Get_Cam_INFO(x,y,TEMP);
            Camlastkey = 3;
        }
    }
    if( !INPUTS.Kispressed()) //K
    {
        if(cameraMASTER.CheckCamMode() == 2 && Camlastkey == 3)
        {
            double x = 0, y = 0;
            SDL_Rect TEMP ={-10000,-10000,0,0};
            cameraMASTER.Get_Cam_INFO(x,y,TEMP);
        }
    }
    if( INPUTS.Lispressed()) //L
    {
        if(cameraMASTER.CheckCamMode() == 2)
        {
            double x = 5, y = 0;
            SDL_Rect TEMP ={-10000,-10000,0,0};
            cameraMASTER.Get_Cam_INFO(x,y,TEMP);
            Camlastkey = 4;
        }
    }
    if( !INPUTS.Lispressed())
        {
        if(cameraMASTER.CheckCamMode() == 2 && Camlastkey == 4)
        {
            double x = 0, y = 0;
            SDL_Rect TEMP ={-10000,-10000,0,0};
            cameraMASTER.Get_Cam_INFO(x,y,TEMP);
        }
    }


    if( INPUTS.Xispressed()) //X
    {
        std::cout << "X" << std::endl;
    }
    if( INPUTS.Cispressed()) //C
    {
        std::cout << "C" << std::endl;
    }
    if( INPUTS.Vispressed()) //V
    {
        std::cout << "V" << std::endl;
    }
    if( INPUTS.Bispressed()) //B
    {
        std::cout << "B" << std::endl;
    }
    if( INPUTS.Nispressed()) //N
    {
        std::cout << "N" << std::endl;
    }
    if( INPUTS.Mispressed()) //M
    {
        std::cout << "M" << std::endl;
    }

    if( INPUTS.NUM1ispressed()) //1
    {
        AddNewEnity(1,6,6,false,0);
        std::cout << "Enities : " << Enities.size() << std::endl;
    }
    if( INPUTS.NUM2ispressed()) //2
    {

        if(timerA == timerAMax)
        {
            std::cout << "Player Sync" << std::endl;
            Player_Sync = true;
            timerA = 0;
        }

    }
    if( INPUTS.NUM3ispressed()) //3
    {
        if(timerA == timerAMax)
        {
            std::cout << "ResetMapDtypes" << std::endl;
            ResetMaps_Dtyeps = true;
            timerA = 0;

        }

    }
    if( INPUTS.NUM4ispressed()) //4
    {
        std::cout << "4" << std::endl;
    }
    if( INPUTS.NUM5ispressed()) //5
    {
        std::cout << "5" << std::endl;
    }
    if( INPUTS.NUM6ispressed()) //6
    {
        std::cout << "6" << std::endl;
    }
    if( INPUTS.NUM7ispressed()) //7
    {
        std::cout << "7" << std::endl;
    }
    if( INPUTS.NUM8ispressed()) //8
    {
        std::cout << "8" << std::endl;
    }
    if( INPUTS.NUM9ispressed()) //9
    {
        if(timerA == timerAMax)
        {
            std::cout << "New CAM Target" << std::endl; ///Sets the cam to another enity
            int current_target = cameraMASTER.GetTarget();
            if(current_target+1 > Enities.size())
                current_target = 0;
            else
                current_target++;

            cameraMASTER.SetTarget(current_target);
            CenterCam = true;
            timerA = 0;
        }


    }
    if( INPUTS.NUM0ispressed()) //0
    {


    if(timerA == timerAMax)
    {
        if(cameraMASTER.CheckCamMode() != 2)
        {
            std::cout << "FREE CAM" << std::endl;
            cameraMASTER.ChangeCamMode(2);
            timerA=0;

        }
        else if(cameraMASTER.CheckCamMode() == 2)
        {
            std::cout << "FREE CAM: OFF" << std::endl;
            cameraMASTER.ChangeCamMode(1);
            CenterCam = true;
            timerA=0;
        }

    }



    }
    if( INPUTS.Zispressed()) //Z
    {
        //PLAYER1.ATTACK();
        for(int i = 0 ;i < Enities.size(); i++)
        {
            if(Enities[i]->CheckifPlayer() && !Enities[i]->Get_attackLock())
            {
                Enities[i]->ATTACK();
                //Player_Sync = true;
                std::string SENDME = "#" + NetName + "F" + "33" + "$";
                NetCODE.SendData(SENDME);
            }

        }



    }

    else if( INPUTS.RIGHTispressed()) //RIGHT
    {
        //PLAYER1.Move(BaseSpeed, 0);
              for(int i = 0 ;i < Enities.size(); i++)
        {
            if(Enities[i]->CheckifPlayer())
                Enities[i]->Move(BaseSpeed,0);
        }
        if(DOLOGICFORSIXCYCLES.index == -1)
        {
            std::string SENDME = "#" + NetName + "F" + "10" + "$";
            NetCODE.SendData(SENDME);
        }

        //Player_Moving = true;
    }
    else if( INPUTS.LEFTispressed()) //LEFT
    {
        //PLAYER1.Move(-BaseSpeed, 0);
                for(int i = 0 ;i < Enities.size(); i++)
        {
            if(Enities[i]->CheckifPlayer())
                Enities[i]->Move(-BaseSpeed,0);
        }
        if(DOLOGICFORSIXCYCLES.index == -1)
        {
        std::string SENDME = "#" + NetName + "F" + "20" + "$";
        NetCODE.SendData(SENDME);
        }
        //Player_Moving = true;
    }
    else if( INPUTS.DOWNispressed()) //DOWN
    {
        //PLAYER1.Move(0, BaseSpeed);
        for(int i = 0 ;i < Enities.size(); i++)
        {
            if(Enities[i]->CheckifPlayer())
                Enities[i]->Move(0,BaseSpeed);
        }
        if(DOLOGICFORSIXCYCLES.index == -1)
        {
        std::string SENDME = "#" + NetName + "F" + "02" + "$";
        NetCODE.SendData(SENDME);
        }
        //Player_Moving = true;
    }
    else if( INPUTS.UPispressed()) //UP
    {
        //PLAYER1.Move(0, -BaseSpeed);

        for(int i = 0 ;i < Enities.size(); i++)
        {
            if(Enities[i]->CheckifPlayer())
                Enities[i]->Move(0,-BaseSpeed);
        }
        if(DOLOGICFORSIXCYCLES.index == -1)
        {
        std::string SENDME = "#" + NetName + "F" + "01" + "$";
        NetCODE.SendData(SENDME);
        }
        //Player_Moving = true;

    }
    if( INPUTS.SPACEispressed()) //Space
    {
        std::cout << "SPACE" << std::endl;
    }
    if( INPUTS.ENTERispressed() && timerC == timerCMAX)//Enter
    {
        //std::cout << "Enter" << std::endl;
        timerC = 0;
        Type_Mode = true;
        CommandLineTextBuff = "";
    }
    if( INPUTS.ESCispressed() )
    {
        std::cout << "ESC" << std::endl;
    }



}


















