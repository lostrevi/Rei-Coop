#ifndef TEXT_H
#define TEXT_H

#include "Map.h"

class Text
{
    public:
        Text();
        ~Text();

        void init(SDL_Renderer* RenZ ,TTF_Font * GetF ,std::string message , int x, int y, int w ,int h);
        void update();
        void draw();

        void update_Message(std::string a);
        void Add_char_ToMessage(std::string a);
        std::string Get_Message();

        void Add_Width();
        void Sub_Width();
        void Add_Widths(int a)
        {
            LOC.w = a * BaseAmount;
        }


        void Reset_width();
        void Match_Widtha()
        {
            Match_Width = true;
        }

        void set_basesize(int a)
        {
            BaseAmount = a;
        }


    private:


        bool Match_Width = false;

        int BaseAmount = 16;

        SDL_Color White = {255, 255, 255};
        SDL_Color Black = {0, 0, 0};

        TTF_Font *Font;

        std::string MessageST;

        SDL_Renderer *RenA;

        SDL_Texture *Text_Text;
        SDL_Surface *messageSuf;

        SDL_Rect LOC;

};

#endif // TEXT_H
