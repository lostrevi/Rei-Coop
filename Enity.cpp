#include "Enity.h"

void Enity::Do_ShotLogic(double Xoffset, double Yoffset, int DIROFSHOT)
{
    camUpdate( Xoffset,  Yoffset);

    if(DIROFSHOT == 0) //up
    {
        Y = Y - TOPSpeed;
    }
    else if (DIROFSHOT == 1) //down
    {
        Y = Y + TOPSpeed;
    }
    else if (DIROFSHOT == 2) //right
    {
        X = X - TOPSpeed;
    }
    else if (DIROFSHOT == 3) //left
    {
       X = X + TOPSpeed;
    }





        LOC.x = X;
        LOC.y = Y;
        HIT.x = X + HITMODx;
        HIT.y = Y + HITMODy;


        if(timerA != timerAMAX)
            timerA++;

        else if(timerA == timerAMAX)
        {
            //deleate get rid of it.
            //DrawMe = false;
            TOPSpeed = 0;
        }

    if(EnityisDamanging)
    {
    DamageB.x = HIT.x; /// Make sure EnityisDamanging is true; if you are using this
    DamageB.y = HIT.y;
    DamageB.w = HIT.w;
    DamageB.h = HIT.h;
    }

}

void Enity::Do_MovmentLogic(double Xoffset, double Yoffset)
{


    camUpdate( Xoffset,  Yoffset);


        if((Attack || AttackLOCK || Damaged )&& !Colisonwiththing)//|| Colisonwiththing)
    {

        //if(Colisonwiththing)
        //{
            //X = X + ((XSpeed)*-1);
            //Y = Y + ((YSpeed)*-1);
        //}

        XSpeed = 0;
        YSpeed = 0;
    }


    if(!Attack && !AttackLOCK )// !Colisonwiththing)
    {

    if(Xmove == 0)
    {
        if(XSpeed < 0)
            XSpeed += SpeedInc;
        else if(XSpeed > 0)
            XSpeed -= SpeedInc;
    }

    if(Ymove == 0)
    {
        if(YSpeed < 0)
            YSpeed += SpeedInc;
        else if(YSpeed > 0)
            YSpeed -= SpeedInc;
    }





        //SpeedInc XSpeed
        //Maxspeedererfhtihsiehthf

        if(Xmove > 0)
        {
            if(XSpeed < TOPSpeed )
                XSpeed += SpeedInc;
        }
        if(Xmove < 0)
        {
            if(XSpeed > -TOPSpeed )
                XSpeed -= SpeedInc;
        }

        if(Ymove < 0)
        {
            if(YSpeed > -TOPSpeed )
                YSpeed -= SpeedInc;
        }
        if(Ymove > 0)
        {
            if(YSpeed < TOPSpeed )
                YSpeed += SpeedInc;
        }




        if(Colisonwiththing)
        {
            //std::cout << " USING C: XSpeed = : " << XSpeed << std::endl;
            X = X + ((XSpeed)*-1);
            Y = Y + ((YSpeed)*-1);
        }
        else
        {
            //std::cout << " NOT USING C: XSpeed = : " << XSpeed << std::endl;
            X = X + XSpeed;
            Y = Y + YSpeed;
        }



        LOC.x = X;
        LOC.y = Y;
        HIT.x = X + HITMODx;
        HIT.y = Y + HITMODy;

        if(!Damaged)
        {
            if(Xmove > 0 && Ymove == 0) //right
            {
                CLIP.x = SpriteSize*3;
                DIR = 2;
            }
            else if(Xmove < 0 && Ymove == 0) //left
            {
                CLIP.x = SpriteSize*1;
                DIR = 3;
            }
            else if(Xmove == 0 && Ymove > 0) //down
            {
                CLIP.x = SpriteSize*0;
                DIR = 1;
            }
            else if(Xmove == 0 && Ymove < 0) //up
            {
                CLIP.x = SpriteSize*2;
                DIR = 0;
            }
        }


    }

    Xmove=0;
    Ymove=0;


        if(timerA > timerAMAX && Movement && !Attack && !AttackLOCK)
    {
        if(CLIP.y == SpriteSize)
            CLIP.y = 0;
            else
                CLIP.y = SpriteSize;
        Movement = false;
        timerA = 0;
    }
    if(Movement)
    {
        timerA++;
    }


    Damageupdate();


    if(EnityisDamanging)
    {
    DamageB.x = HIT.x-5; /// Make sure EnityisDamanging is true; if you are using this
    DamageB.y = HIT.y-5;
    DamageB.w = HIT.w+10;
    DamageB.h = HIT.h+10;
    }



        //if(Colisonwiththing)
        //{
            //X = X + ((XSpeed)*-1);
            //Y = Y + ((YSpeed)*-1);
            //Colisonwiththing = false;
        //}


}





void Enity::Move(double x, double y)
{
    if(!Colisonwiththing)
    {
        Movement = true;
        Xmove = x;
        Ymove = y;
    }

}



void Enity::draw()
{

    if(DrawMe)
    SDL_RenderCopy(RenA, Sprite, &CLIP, &LOC);



    if(debugz)
    {
        SDL_SetRenderDrawColor( RenA, 255, 0, 0, 0xFF );
        SDL_RenderDrawRect(RenA, &HIT);
        SDL_SetRenderDrawColor( RenA, 0, 255, 0, 0xFF );
        SDL_RenderDrawRect(RenA, &DamageB);
        SDL_SetRenderDrawColor( RenA, 0, 0, 255, 0xFF );
        SDL_RenderDrawRect(RenA, &BlockB);
    }
}

void Enity::camUpdate(double Xoffset, double Yoffset)
{
    //UPDATE TRUE X AND Y this will be need for mutiplayer;
    TRUE_X -= Xoffset;
    TRUE_Y -= Yoffset;


    if(Xoffset != 0 || Yoffset != 0)
    {
        X = X + Xoffset;
        LOC.x = X;

        Y = Y + Yoffset;
        LOC.y = Y;

        HIT.x = X + HITMODx;
        HIT.y = Y + HITMODy;
    }
}


void Enity::Take_Damage(int DIRaaa, bool CHECK_ENITYISDAMANGEING)
{
    if(!UNDamage && !Damaged)
    {
        Damaged = true;
        timerD = 0;

        double PUSHAMOUNT = 45;


    if(CHECK_ENITYISDAMANGEING)
    {
        switch(DIR)
        {
            case 0: Y_PUSH = PUSHAMOUNT; PUSH_DIR = 1; break;
            case 1: Y_PUSH = -PUSHAMOUNT; PUSH_DIR = 0; break;
            case 2: X_PUSH = -PUSHAMOUNT; PUSH_DIR = 3; break;
            case 3: X_PUSH = PUSHAMOUNT; PUSH_DIR = 2; break;
        }
    }
    else
    {
        switch(DIRaaa)
        {
            case 0: Y_PUSH = -PUSHAMOUNT; PUSH_DIR = 1; break;
            case 1: Y_PUSH = PUSHAMOUNT; PUSH_DIR = 0; break;
            case 2: X_PUSH = PUSHAMOUNT; PUSH_DIR = 3; break;
            case 3: X_PUSH = -PUSHAMOUNT; PUSH_DIR = 2; break;
        }
    }



    }


        //use drawme to make him flash
}

void Enity::Damageupdate()
{

        //Damaged = false;
    //int timerD = 0; //tine of inviceablity
    //double X_PUSH = 0;
    //double Y_PUSH = 0;
    //int TimerDMAX = 30;
    //int ticks = 0;
    //int PUSH_DIR = 0;

    if(Damaged)
    {

                if(X_PUSH > 0)
                {
                    XSpeed += 15;
                    X_PUSH -= 15;
                }

                if(X_PUSH < 0)
                {
                    XSpeed -= 15;
                    X_PUSH += 15;
                }

                if(Y_PUSH > 0)
                {
                    YSpeed += 12;
                    Y_PUSH -= 15;
                }

                if(Y_PUSH < 0)
                {
                    YSpeed -= 12;
                    Y_PUSH += 15;

                }





        X = X + XSpeed;
        Y = Y + YSpeed;



        if(X_PUSH == 0 && Y_PUSH == 0)
        {
            Damaged = false;
        }

    }


        if(timerD == 5 || timerD == 15 || timerD == 25) //MAX 30
            DrawMe = false;
        else if(timerD == 10 || timerD == 20 || timerD == 30)
            DrawMe = true;



    if(timerD != TimerDMAX)
        timerD++;



}

void Enity::ColisionWithSomthing()
{
    Colisonwiththing = true;

    Xmove = 0;
    Ymove = 0;

            X = X + ((XSpeed)*-1);
            Y = Y + ((YSpeed)*-1);

    //double TEMPX = XSpeed;
    //double TEMPY = YSpeed;



        XSpeed = 0;
        YSpeed = 0;

        /*
    if(!Damaged) // will need specal code for damanged
    {
        if(DIR == 0) //up
        {
            YSpeed += TOPSpeed;
        }
        else if (DIR == 1) //donw
        {
            YSpeed -= TOPSpeed;
        }
        else if (DIR == 2) //Right
        {
            XSpeed -= TOPSpeed;
        }
        else if (DIR == 3) //left
        {
            XSpeed += TOPSpeed;
        }
    }
    else if(Damaged)
    {

        if(PUSH_DIR == 0) //up
        {
            X += TOPSpeed*2;
        }
        else if (PUSH_DIR == 1) //donw
        {
            X -= TOPSpeed*2;
        }
        else if (PUSH_DIR == 2) //Right
        {
            X -= TOPSpeed*2;
        }
        else if (PUSH_DIR == 3) //left
        {
            X += TOPSpeed*2;
        }

    }
    */
        //X = X + ((TEMPX)*-1);
        //Y = Y + ((TEMPY)*-1);

        //XSpeed = 0;
        //YSpeed = 0;

}



