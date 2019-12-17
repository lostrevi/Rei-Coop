#ifndef GAME_H
#define GAME_H

#include "include/NetCode.h"

///////////////////////////////////

/// NET CODE CANCER ///
/*
struct UDPConnection
{
	UDPConnection( )
	{
		quit = false;
	}
	~UDPConnection( )
	{
		SDLNet_FreePacket(packet);
		SDLNet_Quit();
	}
	bool Init( const std::string &ip, int32_t remotePort, int32_t localPort )
	{
		std::cout << "Connecting to \n\tIP : " << ip << "\n\tPort : " << remotePort << std::endl;
		std::cout << "Local port : " << localPort << "\n\n";

		// Initialize SDL_net
		if ( !InitSDL_Net() )
			return false;

		if ( !OpenPort( localPort  ) )
			return false;

		if ( !SetIPAndPort( ip, remotePort ) )
			return false;

		if ( !CreatePacket( 512 ) )
			return false;

		return true;
	}
	bool InitSDL_Net()
	{
		std::cout << "Initializing SDL_net...\n";

		if ( SDLNet_Init() == -1 )
		{
			std::cout << "\tSDLNet_Init failed : " << SDLNet_GetError() << std::endl;
			return false;
		}

		std::cout << "\tSuccess!\n\n";
		return true;
	}
	bool CreatePacket( int32_t packetSize )
	{
		std::cout << "Creating packet with size " << packetSize << "...\n";

		// Allocate memory for the packet
		packet = SDLNet_AllocPacket( packetSize );

		if ( packet == nullptr )
		{
			std::cout << "\tSDLNet_AllocPacket failed : " << SDLNet_GetError() << std::endl;
			return false;
		}

		// Set the destination host and port
		// We got these from calling SetIPAndPort()
		packet->address.host = serverIP.host;
		packet->address.port = serverIP.port;

		std::cout << "\tSuccess!\n\n";
		return true;
	}
	bool OpenPort( int32_t port )
	{
		std::cout << "Opening port " << port << "...\n";

		// Sets our sovket with our local port
		ourSocket = SDLNet_UDP_Open( port );

		if ( ourSocket == nullptr )
		{
			std::cout << "\tSDLNet_UDP_Open failed : " << SDLNet_GetError() << std::endl;
			return false;
		}

		std::cout << "\tSuccess!\n\n";
		return true;
	}
	bool SetIPAndPort( const std::string &ip, uint16_t port )
	{
		std::cout << "Setting IP ( " << ip << " ) " << "and port ( " << port << " )\n";

		// Set IP and port number with correct endianess
		if ( SDLNet_ResolveHost( &serverIP, ip.c_str(), port )  == -1 )
		{
			std::cout << "\tSDLNet_ResolveHost failed : " << SDLNet_GetError() << std::endl;
			return false;
		}

		std::cout << "\tSuccess!\n\n";
		return true;
	}
	// Send data.
	bool Send( const std::string &str )
	{
		// Set the data
		// UDPPacket::data is an Uint8, which is similar to char*
		// This means we can't set it directly.
		//
		// std::stringstreams let us add any data to it using << ( like std::cout )
		// We can extract any data from a std::stringstream using >> ( like std::cin )
		//
		//str
		std::cout << "Type a message and hit enter\n";
		std::string msg = "";
		std::cin.ignore();
		std::getline(std::cin, msg );

		memcpy(packet->data, msg.c_str(), msg.length() );
		packet->len = msg.length();

		std::cout
			<< "==========================================================================================================\n"
			<< "Sending : \'" << str << "\', Length : " << packet->len << "\n";

		// Send
		// SDLNet_UDP_Send returns number of packets sent. 0 means error
		if ( SDLNet_UDP_Send(ourSocket, -1, packet) == 0 )
		{
			std::cout << "\tSDLNet_UDP_Send failed : " << SDLNet_GetError() << "\n"
				<< "==========================================================================================================\n";
			return false;
		}

		std::cout << "\tSuccess!\n"
			<< "==========================================================================================================\n";

		if ( str == "quit" )
			quit = true;
		return true;
	}
	void CheckForData()
	{
		//std::cout
			//<< "==========================================================================================================\n"
			//<< "Check for data...\n";

		// Check t see if there is a packet wauting for us...
		if ( SDLNet_UDP_Recv(ourSocket, packet))
		{
			std::cout << "\tData received : " << packet->data << "\n";

			// If the data is "quit"
			if ( strcmp((char *)packet->data, "quit") == 0)
				quit = true;
		}
		//else
			//std::cout  << "\tNo data received!\n";

		//std::cout << "==========================================================================================================\n";
	}
	bool WasQuit()
	{
		return quit;
	}
	private:
	bool quit;
	UDPsocket ourSocket;
	IPaddress serverIP;
	UDPpacket *packet;
};
*/



/// NET CODE CANDER ///
/////////////////////////////////


































/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  //////////////////////////////////////////////////////GAME CLASS IS HERE//////////////////////////////////////////////////////////////////////////
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Game
{
private:

    /// NETCODE SHIT ///


	std::string IP;
	int32_t localPort = 0;
	int32_t remotePort = 0;



NetCode NetCODE;

    /// NETCODE SHIT ///

            struct DoLogicForSixCycles
            {
                public:
                int index = -1;
                int Cycles = 0;
                int CyclesMax = 6;
                int Xmove = 0;
                int Ymove = 0;
            };

            DoLogicForSixCycles DOLOGICFORSIXCYCLES;




    void updateNetCodeLogic();

    std::string NetName = "S1"; // this makes you the server be default;
    bool Did_Other_Player_Spawn = false;
    bool ConnectedInit = false;
    bool HandShakeStated = false;

    static const int SCREEN_WIDTH = 720;
    static const int SCREEN_HEIGHT = 480; //I want these to be change able via an ini or somthing but this is fine for now.
    bool Running = true; //this condition will be set to false if the game loop falls or stops working.

    std::string int_to_string(int a)
    {
        std::stringstream ss;
        ss << a;
        std::string str = ss.str();
        return str;
    }

    int string_to_int(std::string a)
    {
        int thevalue = 0;

        std::istringstream ss(a);
        ss >> thevalue;
        return thevalue;
    }


    std::string Name_of_app = "Legend Of Rei 0.1.0a";

    TTF_Font *Font;


    Text MesSlot01;
    Text MesSlot02;
    Text MesSlot03;
    Text MesSlot04;

    bool MessageBl01 = false;
    bool MessageBl02 = false;
    bool MessageBl03 = false;
    bool MessageBl04 = false;

    int timerM01 = 0;
    int timerM01MAX = 275;
    int timerM02 = 0;
    int timerM02MAX = 275;
    int timerM03 = 0;
    int timerM03MAX = 275;
    int timerM04 = 0;
    int timerM04MAX = 275;



    Text CommandBox;
    std::string CommandLineTextBuff; //this isn't for cmd this is for the in game command line
    SDL_Texture *TextBox;
    SDL_Rect ScreenWH = {0,0,720,480}; //use this for anything thats a full screen sprite

    int TileSize = 64;

    int timerC = 0;
    int timerCMAX = 25;

    bool DoPlayerWarpLogic = false;

    bool Type_Mode = false;

    bool No_Net_Commands = false;

    struct Warpdata_Can
    {
        int team;
        int type;
        int x, y;
        bool Player = true;
        int dir;
    } ;

    Warpdata_Can WarpCan;

    input INPUTS;

    Camera cameraMASTER;
    SDL_Texture *FreeCam;
    bool CenterCam = true;

    void updatekeys();
    void updatekeys_TypeMode();
    void updatemouse();
    void drawmouse();
    void initmouse();

    int timerA = 0;
    int timerAMax = 15;
    int timerB = 0;
    int timerBMax = 5;
    int TimerW = 0;
    int TimerWMAX = 20;
    int Camlastkey = 0;
    int TARGETMEME = 0;

    bool PlayMovement = false;
    bool Player_Sync = false;
    int timerSycn = 59;
    int timerSycnMAX = 60;

    void ResetMaps_Dtypes(); // like busshes and such
    bool ResetMaps_Dtyeps = true;

    bool MessageSpamLock = false;

    bool Enities_Sync = false;
    int timerESync = 59;
    int timerESyncMAX = 60;

    double OFFSETChs_X = 0;
    double OFFSETChs_Y = 0;


    bool FirstSpawnUseMap = false; /// this just make sure the map only spawns a player once because of warps.

    //SDL objects
    SDL_Window* win0 = NULL;
    SDL_Renderer* Ren0 = NULL;
    SDL_Texture* Tex0 = NULL;
    SDL_Event e;

    SDL_Rect TargetMouse;

    void run(); //starts to run all of the other game loops and such

    void draw(); // handles all the drawing
    void update(); //handles like changing hp or checking for a hit
    void input(); // handles input such as key presses and such
    void commandline(); // stuff with the command line if it used at all.
    void init(); //init's stuff like filling vars.

    int IDGet = 0; //this gives a id and is incressed by one so that no one gets the same id;

    double OFFSETX = 0;
    double OFFSETY = 0;

    //tool
     SDL_Texture* loadTexture(std::string path);
     bool checkCollision( SDL_Rect a, SDL_Rect b );



    ///Object system Phaze 2
    std::vector<Enity*> Enities;

    void AddNewEnity(int type,int Xstart,int Ystart, bool Playeryn, int DIROFMOVE);

    void EnityUpdateList(); // this updates all the enities

    std::vector<Player> Players;
    int playerinexer = 0; /// use this as a kinda of total indexer

    std::vector<Octorok> Octoroks;
    std::vector<OctorokROCK> OctorokROCKs;
    std::vector<TRex> TRexes;

    std::vector <Effect> SFX;
    void NEWEffect(SDL_Texture *TEX,double X,double Y,int FINALFRAME, int CYCLES);
    void NEWEffect(SDL_Texture *TEX,double X,double Y,int FINALFRAME, int CYCLES, int frameX, int frameY);

    /// Phaze 2 end


    void EmptyAllEnitys()
    {
        Enities.clear();
        Players.clear();
        Octoroks.clear();
        OctorokROCKs.clear();
        TRexes.clear();
        IDGet = 0;
    }


    void UnloadMap()
    {

        cameraMASTER.ZeroOUT();
        cameraMASTER.FullZeroOUT();
        MapMaster.reload_Map();
        EmptyAllEnitys();
        CenterCam = true;
        ResetMaps_Dtyeps = true;
    }




    MAP MapMaster;


     double BaseSpeed = 5;

    //Texture to load
    SDL_Texture *PlayerSprite;
    SDL_Texture *TileSheetFloor;
    SDL_Texture *OctorkSprite;
    SDL_Texture *TRexSprite;

    //Effect Textres
    SDL_Texture *BushSFX;

public:

    void Startup();

};


#endif
