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

		//Resolving IPv4 address
		addrinfo hints = {}; //filter the result we get back for getaddrinfo 
		hints.ai_family = AF_INET; //Ipv4 only
		addrinfo* hostinfo = nullptr;
		result = getaddrinfo(ip, NULL, &hints, &hostinfo);

		if (result == 0) {

			sockaddr_in* host_addr = reinterpret_cast<sockaddr_in*>(hostinfo->ai_addr);

			ipAddress.resize(16);
			inet_ntop(AF_INET, &host_addr->sin_addr, &ipAddress[0], 16);


			hostname = ip;

			ULONG ip_long = host_addr->sin_addr.S_un.S_addr;
			ip_bytes.resize(sizeof(ULONG));
			memcpy(&ip_bytes[0], &ip_long, sizeof(ULONG));

			ipVersion = IPVersion::IPv4;

			freeaddrinfo(hostinfo);
			return;
		}
		//TODO refactor those code to be on function
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

