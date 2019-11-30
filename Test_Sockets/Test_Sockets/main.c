#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>

typedef int socklen_t;

int main()
{   WSADATA WSAData;
    WSAStartup(MAKEWORD(2,2), &WSAData);


    WSACleanup();
    return 0;
}
