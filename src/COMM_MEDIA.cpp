#include "COMM_MEDIA.h"
#include <iostream>
Socket Soc;

TenumCommState COMM_MEDIA :: Open(TenumCommType type ,std::string s , int port) {
    if(type == TCPSocket) {
        if ( ! Soc.create() )
        {
        throw SocketException ( "Could not create socket." );
        }

        if ( ! Soc.connect ( s, port ) )
        {
        throw SocketException ( "Could not bind to port." );
        }
        isOpen = true;
    }

    return Success;
}
TenumCommState COMM_MEDIA :: Close(TenumCommType type) {
    if(type == TCPSocket) {
        if(!this->isClosed) {
            this->isClosed = true;
        }
    }
    else{
        return Fail;
    }

    return Success;
}
TenumCommState COMM_MEDIA :: Send(TenumCommType type ,std::string &s) {
   if(type == TCPSocket) { 
        if ( ! Soc.send ( s ) )
        {
        throw SocketException ( "Could not write to socket." );
        }
   }
else{
        return Fail;
    }
    return Success;
}
TenumCommState COMM_MEDIA :: Recieve(TenumCommType type ,std::string &s) {
    if(type == TCPSocket) { 
        if ( ! Soc.recv ( s ) )
        {
        throw SocketException ( "Could not read from socket." );
        }
   }
   else{
        return Fail;
    }
    return Success;
}

COMM_MEDIA::COMM_MEDIA(TenumCommType type) : type(type)
{
    if(type >= SupportedTypes) {
        throw std::invalid_argument( "UnSupported Type of Communiction" );
    }
}

COMM_MEDIA::~COMM_MEDIA()
{
    if(!isClosed) {
        if(this->Close(this->type) == Fail) {
            throw std::system_error(ENOTCONN ,std::generic_category(), "Socket didn't close as expected" );
        }
    }
}


#ifdef UNIT_TEST_COMM_MEDIA

bool COMM_MEDIA_UnitTest() {
    COMM_MEDIA ch(TCPSocket);
    std::string txS("Test Socket");
    std::string rxS;
    std::cout << "Test strt\n";
    if(ch.Open(TCPSocket , "172.18.112.1" , 30000)  == Success)  {
        std::cout << "Comm Ch Open Success\n";
        if(ch.Send(TCPSocket ,txS) == Success)  {
            std::cout << "TX Success\n";
            if((ch.Recieve(TCPSocket,rxS) == Success)) {
                std::cout << "RX Success\n";
                std::cout << txS << "\n";
                std::cout << rxS << "\n";
                if(!rxS.compare(txS)) {
                    std::cout << "RX Same As TX\n";
                    if(ch.Close(TCPSocket) == Success) {
                        std::cout << "Socket closed\n";
                        return true;
                    }
                }
            }

        }
    }
    return false;
}

#endif