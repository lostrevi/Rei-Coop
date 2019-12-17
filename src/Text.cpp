#include "Text.h"

Text::Text()
{
    //ctor
}

Text::~Text()
{
    //dtor
}


void Text::init(SDL_Renderer *RenZ ,TTF_Font * GetF, std::string message , int x, int y, int w ,int h)
{
    RenA = RenZ;

    MessageST = message;

    LOC.x = x;
    LOC.y = y;
    LOC.w = w;
    LOC.h = h;

    Font = GetF;
}
void Text::update()
{
    if(Match_Width)
    {
       LOC.w = (MessageST.length() * BaseAmount);
    }




    //I'll need to add somthing to change color later          |||||
    messageSuf = TTF_RenderText_Solid(Font, MessageST.c_str(), White);

    Text_Text = SDL_CreateTextureFromSurface(RenA, messageSuf);


}
void Text::draw()
{
    SDL_RenderCopy(RenA,Text_Text,NULL,&LOC);
}

void Text::update_Message(std::string a)
{
    MessageST = a;
}
void Text::Add_char_ToMessage(std::string a)
{
    MessageST += a;
}
std::string Text::Get_Message()
{
    return MessageST;
}


void Text::Add_Width()
{
    LOC.w += BaseAmount;
}
void Text::Sub_Width()
{
    LOC.w -= BaseAmount;
}

void Text::Reset_width()
{
    LOC.w = 0;
}

