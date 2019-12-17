#ifndef NETCODE_H
#define NETCODE_H

#include "../Map.h"

#include <memory.h>

/// NetCodes ///

// #$ all of these messages start with #$ so show the begining and end
// Then it will always be who sent it like S1 for host or C1 for client

/// send message
// #S1MWow this game can send messages$
// # S1 M 'Wow this game can send messages'$
//      |
//  Message tag









class NetCode
{
    public:
        NetCode();
        ~NetCode();

        bool Init( const std::string &ip, int32_t remotePort, int32_t localPort );
        bool InitSDL_Net();
        bool CreatePacket( int32_t packetSize );
        bool OpenPort( int32_t port );
        bool SetIPAndPort( const std::string &ip, uint16_t port );
        bool Send( const std::string &str );
        bool SendData( std::string msg);
        void CheckForData();
        bool WasQuit();

        bool Check_Host();
        bool Set_Host(bool a);

        std::string Get_NetCode()
        {
            return NetCodeSTR;
        }
        void Clear_NetCode()
        {
            NetCodeSTR = "";
        }




    private:

    bool Is_Host = false;

    bool quit;
	UDPsocket ourSocket;
	IPaddress serverIP;
	UDPpacket *packet;

	std::string NetCodeSTR;


};

#endif // NETCODE_H
