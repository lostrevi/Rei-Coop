#ifndef GAME_H
#define GAME_H

#include "include/UI.h"

class Game
{
private:
    static const int SCREEN_WIDTH = 780;
    static const int SCREEN_HEIGHT = 540; //I want these to be change able via an ini or somthing but this is fine for now.
    bool Running = true; //this condition will be set to false if the game loop falls or stops working.

    std::string Name_of_app = "Template Project 0.0.0a";

    input INPUTS;

    int ScreenOffX = 0;
    int ScreenOffY = 0;

    int PanLockX = 0, PanLockY = 0;

    Map MapMaster;

    UI UIMaster;

    int timerA = 0;
    int timerAMAX = 7;
    int timerB = 0;
    int timerBMAX = 5;
    int timerC = 0;
    int timerCMAX = 10;

    void updatekeys();
    void updatemouse();
    void drawmouse();
    void initmouse();

    //SDL objects
    SDL_Window* win0 = NULL;
    SDL_Renderer* Ren0 = NULL;
    SDL_Texture* Tex0 = NULL;
    SDL_Event e;

    SDL_Rect TargetMouse;

    SDL_Texture* TitleTexture;

    std::string MOD_map = "";

    void run(); //starts to run all of the other game loops and such

    void draw(); // handles all the drawing
    void update(); //handles like changing hp or checking for a hit
    void input(); // handles input such as key presses and such
    void commandline(); // stuff with the command line if it used at all.
    void init(); //init's stuff like filling vars.

    //tool
     SDL_Texture* loadTexture(std::string path);


public:

    void Startup();

};


#endif
