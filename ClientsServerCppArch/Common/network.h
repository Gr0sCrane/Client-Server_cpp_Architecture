#pragma once
#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

namespace Net {

	class Network {
	public:
		static bool initialize();
		static void shutDown();
	};
}