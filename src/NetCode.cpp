#include "NetCode.h"

NetCode::NetCode()
{
    quit = false;
}

NetCode::~NetCode()
	{
		SDLNet_FreePacket(packet);
		SDLNet_Quit();
	}

bool NetCode::Init( const std::string &ip, int32_t remotePort, int32_t localPort )
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




bool NetCode::InitSDL_Net()
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

bool NetCode::CreatePacket( int32_t packetSize )
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


bool NetCode::OpenPort( int32_t port )
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


bool NetCode::SetIPAndPort( const std::string &ip, uint16_t port )
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


bool NetCode::Send( const std::string &str )
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

		memcpy(packet->data, msg.c_str(), msg.length() ); //filling the packet with data
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
bool NetCode::SendData( std::string msg )
{
        memcpy(packet->data, msg.c_str(), msg.length() ); //filling the packet with data
		packet->len = msg.length();

        if ( SDLNet_UDP_Send(ourSocket, -1, packet) == 0 )
		{
			std::cout << "\tSDLNet_UDP_Send failed : " << SDLNet_GetError() << "\n";
			return false;
		}

            //std::cout << "\tSuccess!\n";
            return true;


}


void NetCode::CheckForData()
{
		// Check t see if there is a packet wauting for us...
		if ( SDLNet_UDP_Recv(ourSocket, packet))
		{
			//std::cout << "\tData received : " << packet->data << "\n";

            //std::string GetME(packet->data,packet->len);
            //GetME = "";

            std::string GetME( packet->len, 0 );
            for ( size_t i = 0; i < packet->len; ++i )
            GetME[ i ] = static_cast<char>( packet->data[ i ] );

            NetCodeSTR = "";

            NetCodeSTR = GetME;


            //std::cout << "NetCodeSTR : " << NetCodeSTR << std::endl;



			// If the data is "quit"
			if ( strcmp((char *)packet->data, "quit") == 0)
				quit = true;
		}
}

bool NetCode::WasQuit()
{
    return quit;
}


bool NetCode::Check_Host()
{
    return Is_Host;
}
bool NetCode::Set_Host(bool a)
{
    Is_Host = a;
}
