#include "game.h"

void Game::updatekeys()
{
        if(timerB != timerBMAX)
        {
            timerB++;
        }
        if(timerC != timerCMAX)
            timerC++;

    if( INPUTS.Qispressed()) //Q
    {
        //std::cout << "Q" << std::endl;
        if(timerC == timerCMAX)
        {
            MapMaster.toggleGird();
            timerC = 0;
        }
    }
    if( INPUTS.Wispressed()) //W
    {
        //std::cout << "W" << std::endl;
        if(timerB == timerBMAX)
        {
            UIMaster.PanTiles(1);
            timerB = 0;
        }
    }
    if( INPUTS.Eispressed()) //E
    {
        //std::cout << "E" << std::endl;
        ///Cylce though mods
        if(timerC == timerCMAX)
        {
            if(MOD_map == "z00")
            {
                MOD_map = "W00";
            }
            else if(MOD_map == "W00")
            {
                MOD_map = "D01";
            }
            else if(MOD_map == "D01")
            {
                MOD_map = "z00";
            }

            MapMaster.Set_Mod(MOD_map);
            UIMaster.Set_MOD_HOLDER(MOD_map);

            timerC = 0;
        }

    }
    if( INPUTS.Rispressed()) //R
    {
        ///std::cout << "R" << std::endl; cycle back though mods
        if(timerC == timerCMAX)
        {


            timerC = 0;
        }
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
        std::cout << "U" << std::endl;
    }
    if( INPUTS.Iispressed()) //I
    {
        std::cout << "I" << std::endl;
    }
    if( INPUTS.Oispressed()) //O
    {
        std::cout << "O" << std::endl;
    }
    if( INPUTS.Pispressed()) //P
    {
        std::cout << "P" << std::endl;
    }
    if( INPUTS.Aispressed()) //A
    {
        //std::cout << "A" << std::endl;
        if(timerB == timerBMAX)
        {
            UIMaster.PanTiles(4);
            timerB = 0;
        }
    }
    if( INPUTS.Sispressed()) //S
    {
        //std::cout << "S" << std::endl;
        if(timerB == timerBMAX)
        {
            UIMaster.PanTiles(2);
            timerB = 0;
        }
    }
    if( INPUTS.Dispressed()) //D
    {
        //std::cout << "D" << std::endl;
        if(timerB == timerBMAX)
        {
            UIMaster.PanTiles(3);
            timerB = 0;
        }
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
        std::cout << "J" << std::endl;
    }
    if( INPUTS.Kispressed()) //K
    {
        std::cout << "K" << std::endl;
    }
    if( INPUTS.Lispressed()) //L
    {
        std::cout << "L" << std::endl;
    }
    if( INPUTS.Zispressed()) //Z
    {
        //std::cout << "Z" << std::endl;
        if(timerC == timerCMAX)
        {
            MapMaster.ZoomIN();

            timerC = 0;
        }
    }
    if( INPUTS.Xispressed()) //X
    {
        //std::cout << "X" << std::endl;
        if(timerC == timerCMAX)
        {
            MapMaster.ZoomOUT();

            timerC = 0;
        }
    }
    if( INPUTS.Cispressed()) //C
    {
        //std::cout << "C" << std::endl;
        if(timerC == timerCMAX)
        {
            MapMaster.ResetZoom();

            timerC = 0;
        }
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
        int tempx = 0;
        int tempy = 0;
        std::cout << "Temp New Map Size thing" << std::endl;
        std::cout << "enter x and y : ";
        std::cin >> tempx;
        std::cout << " , ";
        std::cin >> tempy;

        MapMaster.SetMapSize(tempx,tempy);

    }
    if( INPUTS.Mispressed()) //M
    {
        if(timerC == timerCMAX)
        {
            std::cout << "Exporting file (In Testing faze)" << std::endl;

            MapMaster.exportFile();
        timerC = 0;
        }

    }

    if( INPUTS.NUM1ispressed()) //1
    {
        std::cout << "1" << std::endl;
    }
    if( INPUTS.NUM2ispressed()) //2
    {
        std::cout << "2" << std::endl;
    }
    if( INPUTS.NUM3ispressed()) //3
    {
        std::cout << "3" << std::endl;
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
        std::cout << "9" << std::endl;
    }
    if( INPUTS.NUM0ispressed()) //0
    {
        std::cout << "0" << std::endl;
    }

    if( INPUTS.RIGHTispressed()) //RIGHT
    {
        std::cout << "Right\n";
    }
    if( INPUTS.LEFTispressed()) //LEFT
    {
        std::cout << "Left\n";
    }
    if( INPUTS.DOWNispressed()) //DOWN
    {
        std::cout << "Down\n";
    }
    if( INPUTS.UPispressed()) //UP
    {
        std::cout << "UP\n";
    }
    if( INPUTS.SPACEispressed()) //Space
    {
        std::cout << "SPACE" << std::endl;
    }



}


















