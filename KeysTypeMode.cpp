#include "game.h"


void Game::updatekeys_TypeMode()
{

    ///45 chars for command line thing max

    //std::string inputText;

    //Handle events on queue
               /*while( SDL_PollEvent( &e ) != 0 )
                {
//Special key input
                    if( e.type == SDL_KEYDOWN )
                    {
                        //Handle backspace
                        if( e.key.keysym.sym == SDLK_BACKSPACE && CommandLineTextBuff.length() > 0 )
                        {
                            //lop off character
                            CommandLineTextBuff.pop_back();

                        }
                        //Handle copy
                        else if( e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
                        {
                            SDL_SetClipboardText( CommandLineTextBuff.c_str() );
                        }
                        //Handle paste
                        else if( e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
                        {
                            CommandLineTextBuff = SDL_GetClipboardText();

                        }
                    }
//Special text input event
                    else if( e.type == SDL_TEXTINPUT )
                    {
                        //Not copy or pasting
                        if( !( ( e.text.text[ 0 ] == 'c' || e.text.text[ 0 ] == 'C' ) && ( e.text.text[ 0 ] == 'v' || e.text.text[ 0 ] == 'V' ) && SDL_GetModState() & KMOD_CTRL ) )
                        {
                            //Append character
                            CommandLineTextBuff += e.text.text;


                        }
                    }
                }*/




                CommandLineTextBuff = INPUTS.Get_Typing_Text();
                if(CommandLineTextBuff.length() > 44)
                {

                    CommandLineTextBuff.pop_back();
                    INPUTS.Set_Typing_Text(CommandLineTextBuff);
                }






                //if(inputText != "")
                //{
                //    CommandBox.Add_Width();
                //    CommandLineTextBuff += inputText;
                //}


                //std::cout << "inputText : " << CommandLineTextBuff << std::endl;








    if( INPUTS.ENTERispressed() && Type_Mode && timerC == timerCMAX)//Enter
    {
        std::cout << "Message_Sent" << std::endl;

        /// NET CODE SHIT ///

        ///Raping the message for net code and such.
        std::string SENDME = "";

        SENDME = "#" + NetName + "M" + CommandLineTextBuff + "$";


        NetCODE.SendData(SENDME);

        /// NET CODE SHIT ///

        Type_Mode = false;
        CommandLineTextBuff = "";
        CommandBox.Reset_width();
        timerC = 0;
    }
    if( INPUTS.ESCispressed() && Type_Mode )
    {
        //std::cout << "ESC" << std::endl;
        Type_Mode = false;
        CommandLineTextBuff = "";
        CommandBox.Reset_width();
        /// Also clear the type string;

    }






/*
    if(timerB != timerBMax)
        timerB++;


if(timerB == timerBMax)
{



    if( INPUTS.Qispressed()) //Q
    {
        CommandLineTextBuff += "Q";
        CommandBox.Add_Width();
    }
    if( INPUTS.Wispressed()) //W
    {
        CommandLineTextBuff += "W";
        CommandBox.Add_Width();
    }
    if( INPUTS.Eispressed()) //E
    {
        CommandLineTextBuff += "E";
        CommandBox.Add_Width();
    }
    if( INPUTS.Rispressed()) //R
    {
        CommandLineTextBuff += "R";
        CommandBox.Add_Width();
    }
    if( INPUTS.Tispressed()) //T
    {
        CommandLineTextBuff += "T";
        CommandBox.Add_Width();
    }
    if( INPUTS.Yispressed()) //Y
    {
        CommandLineTextBuff += "Y";
        CommandBox.Add_Width();
    }
    if( INPUTS.Uispressed()) //U
    {
        CommandLineTextBuff += "U";
        CommandBox.Add_Width();
    }
    if( INPUTS.Iispressed()) //I
    {
        CommandLineTextBuff += "I";
        CommandBox.Add_Width();
    }
    if( INPUTS.Oispressed()) //O
    {
        CommandLineTextBuff += "O";
        CommandBox.Add_Width();
    }
    if( INPUTS.Pispressed()) //P
    {
        CommandLineTextBuff += "P";
        CommandBox.Add_Width();
    }
    if( INPUTS.Aispressed()) //A
    {
        CommandLineTextBuff += "A";
        CommandBox.Add_Width();
    }
    if( INPUTS.Sispressed()) //S
    {
        CommandLineTextBuff += "S";
        CommandBox.Add_Width();
    }
    if( INPUTS.Dispressed()) //D
    {
        CommandLineTextBuff += "D";
        CommandBox.Add_Width();
    }
    if( INPUTS.Fispressed()) //F
    {
        CommandLineTextBuff += "F";
        CommandBox.Add_Width();
    }
    if( INPUTS.Gispressed()) //G
    {
        CommandLineTextBuff += "G";
        CommandBox.Add_Width();
    }
    if( INPUTS.Hispressed()) //H
    {
        CommandLineTextBuff += "H";
        CommandBox.Add_Width();
    }
    if( INPUTS.Jispressed()) //J
    {
        CommandLineTextBuff += "J";
        CommandBox.Add_Width();
    }
    if( INPUTS.Kispressed()) //K
    {
        CommandLineTextBuff += "K";
        CommandBox.Add_Width();
    }
    if( INPUTS.Lispressed()) //L
    {
        CommandLineTextBuff += "L";
        CommandBox.Add_Width();
    }
    if( INPUTS.Zispressed()) //Z
    {
        CommandLineTextBuff += "Z";
        CommandBox.Add_Width();
    }
    if( INPUTS.Xispressed()) //X
    {
        CommandLineTextBuff += "X";
        CommandBox.Add_Width();
    }
    if( INPUTS.Cispressed()) //C
    {
        CommandLineTextBuff += "C";
        CommandBox.Add_Width();
    }
    if( INPUTS.Vispressed()) //V
    {
        CommandLineTextBuff += "V";
        CommandBox.Add_Width();
    }
    if( INPUTS.Bispressed()) //B
    {
        CommandLineTextBuff += "B";
        CommandBox.Add_Width();
    }
    if( INPUTS.Nispressed()) //N
    {
        CommandLineTextBuff += "N";
        CommandBox.Add_Width();
    }
    if( INPUTS.Mispressed()) //M
    {
        CommandLineTextBuff += "M";
        CommandBox.Add_Width();
    }

    if( INPUTS.NUM1ispressed()) //1
    {
        CommandLineTextBuff += "1";
        CommandBox.Add_Width();
    }
    if( INPUTS.NUM2ispressed()) //2
    {
        CommandLineTextBuff += "2";
        CommandBox.Add_Width();
    }
    if( INPUTS.NUM3ispressed()) //3
    {
        CommandLineTextBuff += "3";
        CommandBox.Add_Width();
    }
    if( INPUTS.NUM4ispressed()) //4
    {
        CommandLineTextBuff += "4";
        CommandBox.Add_Width();
    }
    if( INPUTS.NUM5ispressed()) //5
    {
        CommandLineTextBuff += "5";
        CommandBox.Add_Width();
    }
    if( INPUTS.NUM6ispressed()) //6
    {
        CommandLineTextBuff += "6";
        CommandBox.Add_Width();
    }
    if( INPUTS.NUM7ispressed()) //7
    {
        CommandLineTextBuff += "7";
        CommandBox.Add_Width();
    }
    if( INPUTS.NUM8ispressed()) //8
    {
        CommandLineTextBuff += "8";
        CommandBox.Add_Width();
    }
    if( INPUTS.NUM9ispressed()) //9
    {
        CommandLineTextBuff += "9";
        CommandBox.Add_Width();
    }
    if( INPUTS.NUM0ispressed()) //0
    {
        CommandLineTextBuff += "0";
        CommandBox.Add_Width();
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
        //std::cout << "SPACE" << std::endl;
        CommandLineTextBuff += " ";
        CommandBox.Add_Width();
    }
    if( INPUTS.ENTERispressed() )//Enter
    {
        std::cout << "NEED TO ADD CODE FOR THIS BUT THIS WILL SEND THE MESSAGE WHEN ALL IS DONE" << std::endl;
        Type_Mode = false;
        CommandLineTextBuff = "";
        CommandBox.Reset_width();
    }
    if( INPUTS.ESCispressed() )
    {
        //std::cout << "ESC" << std::endl;
        Type_Mode = false;
        CommandLineTextBuff = "";
        CommandBox.Reset_width();
        /// Also clear the type string;

    }


    timerB = 0;
}

*/


}

/*
So this code here should just fix this shit so idk i'll need to add it some time

//Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
//Special key input
                    else if( e.type == SDL_KEYDOWN )
                    {
                        //Handle backspace
                        if( e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 )
                        {
                            //lop off character
                            inputText.pop_back();
                            renderText = true;
                        }
                        //Handle copy
                        else if( e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
                        {
                            SDL_SetClipboardText( inputText.c_str() );
                        }
                        //Handle paste
                        else if( e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
                        {
                            inputText = SDL_GetClipboardText();
                            renderText = true;
                        }
                    }
//Special text input event
                    else if( e.type == SDL_TEXTINPUT )
                    {
                        //Not copy or pasting
                        if( !( ( e.text.text[ 0 ] == 'c' || e.text.text[ 0 ] == 'C' ) && ( e.text.text[ 0 ] == 'v' || e.text.text[ 0 ] == 'V' ) && SDL_GetModState() & KMOD_CTRL ) )
                        {
                            //Append character
                            inputText += e.text.text;
                            renderText = true;
                        }
                    }
                }
*/



