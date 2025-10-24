#include <iostream>
#include "Common/network.h"
#include "Common/socket.h";

using namespace Net;

int main() {


	if (Network::initialize()) {
		std::cout << "WinSock: Success" << "\n";
		Socket socket;

		if (socket.create() == PResult::P_success) {
			std::cout << "Socket: Success" << "\n";
			socket.close();
		}
		else {
			std::cerr << "The socket failed to initialize." << "\n";
		}
	}

	Network::shutDown();
	return 0;
}