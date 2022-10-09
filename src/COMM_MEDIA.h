#ifndef _COMM_MEDIA_H_
#define _COMM_MEDIA_H_

#include <string>
#include <stdexcept>
#include <system_error>
#include "Socket.h"
#include "SocketException.h"

#define UNIT_TEST_COMM_MEDIA 2
typedef enum {
    TCPSocket,
    SupportedTypes,
} TenumCommType;

typedef enum {
    Success,
    Fail,
} TenumCommState;
class COMM_MEDIA
{
private:
    TenumCommType type;
    std::string s ;
    int port;
    bool isClosed = false;
    bool isOpen   = false;
public:
    COMM_MEDIA(TenumCommType type);
    ~COMM_MEDIA();
    TenumCommState Open(TenumCommType type ,std::string s , int port);
    TenumCommState Close(TenumCommType type);
    TenumCommState Send(TenumCommType type ,std::string &s);
    TenumCommState Recieve(TenumCommType type ,std::string &s);
};

#ifdef UNIT_TEST_COMM_MEDIA
bool COMM_MEDIA_UnitTest();
#endif

#endif //_COMM_MEDIA_H_