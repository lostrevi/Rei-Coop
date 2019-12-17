#include "game.h"

void Game::updateNetCodeLogic()
{

    if(NetCODE.Get_NetCode() != "")
    {

            std::string NetGetTemp;

            NetGetTemp = NetCODE.Get_NetCode();

            bool start_Flag = false;
            bool end_Flag = false;

            bool MessageType = false;

            std::string FromSender = ""; //this is like C1 or C2

            for(int i = 0; i < NetGetTemp.length(); i++)
            {
                if(NetGetTemp[i] == '#')
                    start_Flag = true;
                if(NetGetTemp[i] == '$')
                    end_Flag = true;





            }

            if(!start_Flag || !end_Flag)
            {
                std::cout << "Error: this Packet is broken (This should be used to DEL the back message but na still going to let it go though)\n";
            }


            FromSender = NetGetTemp[1];
            FromSender += NetGetTemp[2];



            if(NetGetTemp[3] == 'M') /// Message
            {

                std::string TextFromMessage = "";

                for(int i = 4; i < NetGetTemp.length()-1; i++)
                {

                    TextFromMessage += NetGetTemp[i];

                }


                //std::cout << "Message is : " << TextFromMessage << std::endl;

                if(MesSlot01.Get_Message() == " ")
                {
                    MesSlot01.update_Message(TextFromMessage);
                    MesSlot01.Add_Widths(TextFromMessage.length());
                    MessageBl01 = true;
                    timerM01 = 0;
                }

                else if(MesSlot02.Get_Message() == " ")
                {
                    MesSlot02.update_Message(TextFromMessage);
                    MesSlot02.Add_Widths(TextFromMessage.length());
                    MessageBl02 = true;
                    timerM02 = 0;
                    timerM01 = 0;
                }

                else if(MesSlot03.Get_Message() == " ")
                {
                    MesSlot03.update_Message(TextFromMessage);
                    MesSlot03.Add_Widths(TextFromMessage.length());
                    MessageBl03 = true;
                    timerM03 = 0;
                    timerM02 = 0;
                    timerM01 = 0;
                }

                else if(MesSlot04.Get_Message() == " ")
                {
                    MesSlot04.update_Message(TextFromMessage);
                    MesSlot04.Add_Widths(TextFromMessage.length());
                    MessageBl04 = true;
                    timerM01 = 0;
                    timerM02 = 0;
                    timerM03 = 0;
                    timerM04 = 0;
                }
                else if(MesSlot04.Get_Message() != " ")
                {

                    MesSlot01.update_Message(MesSlot02.Get_Message());
                    MesSlot01.Add_Widths(MesSlot02.Get_Message().length());
                    MessageBl01 = true;
                    timerM01 = 0;


                    MesSlot02.update_Message(MesSlot03.Get_Message());
                    MesSlot02.Add_Widths(MesSlot03.Get_Message().length());
                    MessageBl02 = true;
                    timerM02 = 0;


                    MesSlot03.update_Message(MesSlot04.Get_Message());
                    MesSlot03.Add_Widths(MesSlot04.Get_Message().length());
                    MessageBl03 = true;
                    timerM03 = 0;


                    MesSlot04.update_Message(TextFromMessage);
                    MesSlot04.Add_Widths(TextFromMessage.length());
                    MessageBl04 = true;
                    timerM04 = 0;

                }





            } /// Message end












            if((NetGetTemp[3] == 'F' && DOLOGICFORSIXCYCLES.index == -1) || (NetGetTemp[5] == '3' && NetGetTemp[5] == '3')) /// ForceMoveJustForTesting
            {

                /// #c1F01$
                ///     xy

                for(int i = 0 ;i < Enities.size(); i++)
                        {
                            if(Enities[i]->Check_Player2())
                            {
                                DOLOGICFORSIXCYCLES.index = i;
                            }
                                //Enities[i]->Move(BaseSpeed,0);
                        }

                if(NetGetTemp[4] == '1'&&NetGetTemp[5] == '0')
                {
                        DOLOGICFORSIXCYCLES.Xmove = BaseSpeed;
                }

                else if(NetGetTemp[4] == '2'&&NetGetTemp[5] == '0')
                {
                                DOLOGICFORSIXCYCLES.Xmove = -BaseSpeed;
                }

                else if(NetGetTemp[4] == '0' &&NetGetTemp[5] == '1')
                {

                                DOLOGICFORSIXCYCLES.Ymove = -BaseSpeed;

                }


                else if(NetGetTemp[4] == '0' &&NetGetTemp[5] == '2')
                {
                                DOLOGICFORSIXCYCLES.Ymove = BaseSpeed;

                }

                else if(NetGetTemp[5] == '3' && NetGetTemp[5] == '3')
                {
                    DOLOGICFORSIXCYCLES.Cycles = 0;
                    DOLOGICFORSIXCYCLES.index = -1;
                    DOLOGICFORSIXCYCLES.Xmove = 0;
                    DOLOGICFORSIXCYCLES.Ymove = 0;
                    for(int i = 0 ;i < Enities.size(); i++)
                    {
                        if(Enities[i]->Check_Player2())
                            Enities[i]->ATTACK();
                    }
                }








            } /// End of force move for testing


            if(DOLOGICFORSIXCYCLES.index != -1)
            {

                if(DOLOGICFORSIXCYCLES.Cycles != DOLOGICFORSIXCYCLES.CyclesMax)
                DOLOGICFORSIXCYCLES.Cycles++;




                Enities[DOLOGICFORSIXCYCLES.index]->Move(DOLOGICFORSIXCYCLES.Xmove,DOLOGICFORSIXCYCLES.Ymove);




                if(DOLOGICFORSIXCYCLES.Cycles == DOLOGICFORSIXCYCLES.CyclesMax)
                {
                    DOLOGICFORSIXCYCLES.index = -1;
                    DOLOGICFORSIXCYCLES.Cycles = 0;
                    DOLOGICFORSIXCYCLES.Xmove = 0;
                    DOLOGICFORSIXCYCLES.Ymove = 0;
                    //timerSycn = timerSycnMAX-1;
                    //std::cout << "SDHIFEIFHEIFHIESHFISHEFIHSEIFHSEIFHISEHFISHEIFHSIEHFISHEFIHSEIFHISEFH";
                    Player_Sync = true;
                    timerSycn = 0;
                }


            }





            if(NetGetTemp[3] == 'C') /// HandShake
            {
                std::cout << "Got a request from " << FromSender << " Finishing HandShake.";

                NetCODE.SendData("#" + NetName + "D" + "$");

                HandShakeStated = true;
            }

            else if(NetGetTemp[3] == 'D') /// HandShake end
            {
                std::cout << "Was able to HandShake with " << FromSender << " HandShake...";
                NetCODE.SendData("#" + NetName + "c" + "$");

                ConnectedInit = true;
                //HandShakeStated = false;
            }
            else if(NetGetTemp[3] == 'c') /// HandShake
            {
                std::cout << FromSender << "!!HandShake!! !!DONE!!";

                HandShakeStated = false;
            }






            /// SPAWN COMMAND


            else if(NetGetTemp[3] == 'S')
            {
                //MessagetoSend = "#" + NetName + "S" + INDEXTRUE + "|" + XTRUE + "|" + YTRUE + "|" + DIRTRUE + "$";

                int index_for_fors = 0;
                int index_for_arrays = 0;

                //int indexA[5] = {-1,-1,-1,-1,-1};
                //int XlocA[5] = {-1,-1,-1,-1,-1};
                //int YlocA[5] = {-1,-1,-1,-1,-1};

                int indexFinal = 0;
                int XlocFinal = 0;
                int YlocFinal = 0;
                int Dir = 0;

                std::string Final_Index_NUMB = "";

                for(int i = 4; i < NetGetTemp.length(); i++)
                {

                    if(NetGetTemp[i] == '|')
                    {
                       index_for_fors = i+1;
                       index_for_arrays = 0;
                       break;
                    }

                    Final_Index_NUMB += NetGetTemp[i]; /// using this now;

                }

                indexFinal = string_to_int(Final_Index_NUMB);


                std::cout << "indexFinal : " << indexFinal << std::endl;
                //indexFinal = 0;

                //std::cout << "index_for_fors : " << index_for_fors << std::endl;

                Final_Index_NUMB = "";/// clearing this

                for(int i = index_for_fors; i < NetGetTemp.length(); i++) /// X thing
                {

                    if(NetGetTemp[i] == '|')
                    {
                       index_for_fors = i+1;
                       index_for_arrays = 0;
                       break;
                    }

                    //std::cout << i << " : This is for X : " << NetGetTemp[i] << std::endl;

                    Final_Index_NUMB += NetGetTemp[i]; /// using this now;

                }

                XlocFinal = string_to_int(Final_Index_NUMB);

                std::cout << "XlocFinal : " << XlocFinal << std::endl;


                Final_Index_NUMB = "";/// clearing this


                for(int i = index_for_fors; i < NetGetTemp.length(); i++) /// Y thing
                {

                    if(NetGetTemp[i] == '|')
                    {
                       index_for_fors = i+1;
                       index_for_arrays = 0;
                       break;
                    }

                    //std::cout << i << " : This is for X : " << NetGetTemp[i] << std::endl;

                    Final_Index_NUMB += NetGetTemp[i]; /// using this now;

                }

                YlocFinal = string_to_int(Final_Index_NUMB);

                std::cout << "YlocFinal : " << YlocFinal << std::endl;

                Final_Index_NUMB = "";/// clearing this



                for(int i = index_for_fors; i < NetGetTemp.length(); i++) /// Y thing
                {

                    if(NetGetTemp[i] == '$')
                    {
                       index_for_fors = i+1;
                       //index_for_arrays = 0;
                       break;
                    }

                    //std::cout << i << " : This is for X : " << NetGetTemp[i] << std::endl;

                    Final_Index_NUMB += NetGetTemp[i]; /// using this now;

                }

                Dir = string_to_int(Final_Index_NUMB);

                std::cout << "Dir : " << Dir << std::endl;

                XlocFinal = (XlocFinal - OFFSETChs_X)/TileSize;
                YlocFinal = (YlocFinal - OFFSETChs_Y)/TileSize;

                std::cout << "OFFSETChs_X = " << OFFSETChs_X << " | " << OFFSETChs_Y << "\n";

                std::cout << "X and Y for Spawn Command is : " << XlocFinal << " | " << YlocFinal << "\n";


                int HoldMe = IDGet;


            AddNewEnity(indexFinal,XlocFinal,YlocFinal,false,Dir); // i'll need to add a flag for the enity

            for(int i = 0; i < Enities.size(); i++)
            {
                if(Enities[i]->GetID() == HoldMe)
                {
                    Enities[i]->set_player2(true);
                }
            }




            }


            if(NetGetTemp[3] == 'V') ///Move update
            {
                std::string NewX;
                std::string NewY;
                int Newx = 0, Newy = 0;
                int IndexMem = 0;




                for(int i = 4; i < NetGetTemp.length(); i++)
                {

                    if(NetGetTemp[i] == '|')
                    {
                       IndexMem = i+1;
                       break;
                    }
                    NewX += NetGetTemp[i]; /// using this now;
                }


                //std::cout << "IndexMem = : " << IndexMem << " : " << NetGetTemp.length() << " Length\n";

                for(int i = IndexMem; i < NetGetTemp.length(); i++)
                {

                    if(NetGetTemp[i] == '$')
                    {
                       IndexMem = i+1;
                       break;
                    }



                    NewY += NetGetTemp[i]; /// using this now;
                }



                Newx = string_to_int(NewX);
                Newy = string_to_int(NewY);

                //std::cout << "x and y is dis : " << Newx << " | " << Newy << std::endl;

                Newx += OFFSETChs_X;
                Newy += OFFSETChs_Y;


                for(int i = 0; i < Enities.size(); i++)
                {
                    if(Enities[i]->Check_Player2())
                    {
                        Enities[i]->Set_X(Newx);
                        Enities[i]->Set_Y(Newy);
                    }
                }





            } ///  end asdfasdfasdflock up dplayer



            if(NetGetTemp[3] == 'v') ///Move update for enites
            {
                std::string NewX;
                std::string NewY;
                std::string ConvertmeID;
                int Newx = 0, Newy = 0;
                int IndexMem = 0;
                int IDtoFind = 0;




                for(int i = 4; i < NetGetTemp.length(); i++)
                {

                    if(NetGetTemp[i] == '|')
                    {
                       IndexMem = i+1;
                       break;
                    }
                    NewX += NetGetTemp[i]; /// using this now;
                }


                //std::cout << "IndexMem = : " << IndexMem << " : " << NetGetTemp.length() << " Length\n";

                for(int i = IndexMem; i < NetGetTemp.length(); i++)
                {

                    if(NetGetTemp[i] == '|')
                    {
                       IndexMem = i+1;
                       break;
                    }



                    NewY += NetGetTemp[i]; /// using this now;
                }

                for(int i = IndexMem; i < NetGetTemp.length(); i++)
                {

                    if(NetGetTemp[i] == '$')
                    {
                       IndexMem = i+1;
                       break;
                    }



                    ConvertmeID += NetGetTemp[i]; /// using this now;
                }


                IDtoFind = string_to_int(ConvertmeID);
                Newx = string_to_int(NewX);
                Newy = string_to_int(NewY);

                //std::cout << "x and y is dis : " << Newx << " | " << Newy << std::endl;

                Newx += OFFSETChs_X;
                Newy += OFFSETChs_Y;


                //std::cout << "x and y is dis : " << Newx << " | " << Newy << std::endl;

                for(int i = 0; i < Enities.size(); i++)
                {
                    if(Enities[i]->GetID() == IDtoFind)
                    {
                        Enities[i]->Set_X(Newx);
                        Enities[i]->Set_Y(Newy);
                    }
                }





            } // END OF v









                NetCODE.Clear_NetCode();


    }


























    /// Message time out thing

    if( timerM01 != timerM01MAX)
        timerM01++;
    if( timerM02 != timerM02MAX)
        timerM02++;
    if( timerM03 != timerM03MAX)
        timerM03++;
    if( timerM04 != timerM04MAX)
        timerM04++;



        if(timerM01 == timerM01MAX)
        {
            MesSlot01.update_Message(" ");
            MessageBl01 = false;
        }
        if(timerM02 == timerM01MAX)
        {
            MesSlot02.update_Message(" ");
            MessageBl02 = false;
        }
        if(timerM03 == timerM01MAX)
        {
            MesSlot03.update_Message(" ");
            MessageBl03 = false;
        }
        if(timerM04 == timerM01MAX)
        {
            MesSlot04.update_Message(" ");
            MessageBl04 = false;
        }







}
