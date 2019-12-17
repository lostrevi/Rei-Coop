#ifndef PORTALCAN_H
#define PORTALCAN_H

#include "UI.h"

class PortalCan // all this is it just holds the portal links and
{
    /// It holds the Portal Address and the MapThat it needs to go
    /// This should be inited from a file such as a map master file But for now i'm just going to init them in the map.init();


private:

        char SourceID[2]; // Check to see if it links
        std::string TargetMAP; // The map name of the new map to load
        char TargetID[2]; // where to look for the portal id

public:
        PortalCan();

        void Set_SourceID(int i, char a)
        {
            if(i < 2)
            {
                SourceID[i] = a;
            }
            else
            {
                std::cout << "Error: Mod only supports 2 units unless this was changed/needs to be changed at PortalCan.h void Set_TargetID()\n";
            }
        }

        void Set_TargetID(int i,char a)
        {
            if(i < 2)
            {
                TargetID[i] = a;
            }
            else
            {
                std::cout << "Error: Mod only supports 2 units unless this was changed/needs to be changed at PortalCan.h void Set_TargetID()\n";
            }
        }

        void Set_TargetMAP(std::string a)
        {
            TargetMAP = a;
        }

        char Get_TargetID(int i)
        {
            return TargetID[i];
        }

        char Get_SourceID(int i)
        {
            return SourceID[i];
        }

        std::string Get_TargetMAP()
        {
            return TargetMAP;
        }






};

#endif // PORTALCAN_H
