#include <iostream>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#define WIN32_LEAN_AND_MEAN

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

const char* sendbuf = "TEST";
char recvbuff[DEFAULT_BUFLEN];

struct addrinfo* result = NULL, * ptr = NULL, hints;

ZeroMemory(&hints, sizeof(hints));
hints.ai_family = AF_UNSPEC;
hints.ai_socktype = SOCK_STREAM;
hints.ai_protocol = IPPROTO_TCP;

class Client {
private:
	std::string m_ipAddress;
	uint32_t m_clientPort;
};

void initSock();