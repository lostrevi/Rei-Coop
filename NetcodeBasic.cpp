
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
		std::cout
			<< "==========================================================================================================\n"
			<< "Check for data...\n";

		// Check t see if there is a packet wauting for us...
		if ( SDLNet_UDP_Recv(ourSocket, packet))
		{
			std::cout << "\tData received : " << packet->data << "\n";

			// If the data is "quit"
			if ( strcmp((char *)packet->data, "quit") == 0)
				quit = true;
		}
		else
			std::cout  << "\tNo data received!\n";

		std::cout << "==========================================================================================================\n";
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
