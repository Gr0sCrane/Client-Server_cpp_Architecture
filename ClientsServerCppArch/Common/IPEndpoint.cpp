#include "IPEndpoint.h"
#include <WS2tcpip.h>

namespace Net {

	IPEndpoint::IPEndpoint(const char* ip, unsigned short port) : ipAddress(ip), port(port)
	{
		in_addr addr; //store the ipv4 address
		int result = inet_pton(AF_INET, ip, &addr);
		if (result == 1) {
			if (addr.S_un.S_addr != INADDR_NONE) {

				ipAddress = ip;
				hostname = ip;
				ipVersion = IPVersion::IPv4;

				ip_bytes.resize(sizeof(ULONG));
				memcpy(&ip_bytes[0], &addr.S_un.S_addr, sizeof(ULONG));
				return;
			}
		}
	}

	IPEndpoint::~IPEndpoint(){}

	IPVersion IPEndpoint::getIpVers() const
	{
		return ipVersion;
	}

	string IPEndpoint::getIpAddress() const
	{
		return ipAddress;
	}

	string IPEndpoint::getHostName() const
	{
		return hostname;
	}

	vector<uint8_t> IPEndpoint::getIpBytes() const
	{
		return ip_bytes;
	}

	unsigned short IPEndpoint::getPort() const
	{
		return port;
	}

	void IPEndpoint::getIpBytesToString() const
	{
		for (auto& e : ip_bytes) {
			std::cout << (int)e << "\n";
		}
	}
}

