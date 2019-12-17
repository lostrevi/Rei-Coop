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
    int Mapx = 5, Mapy = 5;
    std::cout << "Enter Map Size X and Y : ";
    //std::cin >> Mapx;
    //std::cin >> Mapy;


    TitleTexture = loadTexture("Data/MAP/TileMapFloor.png");


    MapMaster.init(Ren0,TitleTexture,Mapx,Mapy);
    UIMaster.init(Ren0,TitleTexture,SCREEN_WIDTH,SCREEN_HEIGHT);

    initmouse();

}

void Game::draw()
{
        //Clear screen
        SDL_SetRenderDrawColor( Ren0, 29, 30, 34, 0xFF );
        SDL_RenderClear( Ren0 );

        MapMaster.draw();
        UIMaster.draw();

        drawmouse();

                SDL_RenderPresent( Ren0 );

}

void Game::update()
{
    updatekeys();
    updatemouse();
    MapMaster.update(ScreenOffX,ScreenOffY,TargetMouse);
    if(MOD_map == "")
        MOD_map = MapMaster.Get_Mod();

    UIMaster.update(TargetMouse);

    ScreenOffX = 0;
    ScreenOffY = 0;
}







