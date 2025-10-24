#include <iostream>
#include "Common/network.h"
#include "Common/socket.h";
#include "Common/IPEndpoint.h"

using namespace Net;

int main() {


	if (Network::initialize()) {
		std::cout << "WinSock: Success" << "\n";

		IPEndpoint ipTest("192.168.10.5", 8080);
		if (ipTest.getIpVers() == IPVersion::IPv4) {
			std::cout << "Hostname: " << ipTest.getHostName() << "\n";
			std::cout << "IP address: " << ipTest.getIpAddress() << "\n";
			std::cout << "Port: " << ipTest.getPort() << "\n";
			std::cout << "IP bytes..." <<"\n";
			ipTest.getIpBytesToString();

		}
		else {
			std::cerr << "This is not an IPv4 address." << "\n";
		}

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