#pragma once
#include "socket.h"
#include <iostream>
#include <vector>

using std::string;
using std::vector;

namespace Net {

	class IPEndpoint 
	{
	public:

		IPEndpoint(const char* ip, unsigned short port);
		~IPEndpoint();

		IPVersion getIpVers() const;
		string getIpAddress() const;
		string getHostName() const;
		vector<uint8_t> getIpBytes() const;
		unsigned short getPort() const;
		void getIpBytesToString() const;


	private:
		IPVersion ipVersion = IPVersion::Unknown;
		string hostname;
		string ipAddress;
		vector<uint8_t> ip_bytes;
		unsigned short port = 0;


	};
}