#include <iostream>
#include "network.h"

bool Net::Network::initialize() {

	WSADATA wsDAta;

	int result = WSAStartup(MAKEWORD(2, 2), &wsDAta);
	if (result != 0) {
		std::cerr << "failed to start the Winsock API." << "\n";
		return false;
	}

	if (LOBYTE(wsDAta.wVersion) != 2 || HIBYTE(wsDAta.wVersion) != 2) {
		std::cerr << "Could not find the correct version of WinSock." << "\n";
		return false;
	}

	return true;
}

void Net::Network::shutDown() {
	WSACleanup();
}