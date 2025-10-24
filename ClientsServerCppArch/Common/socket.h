#pragma once
#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>

namespace Net {

	typedef SOCKET SocketHandle;

	enum class PResult {
		P_success,
		P_NotYetImplemented
	};

	enum class IPVersion {
		IPv4,
		IPv6,
		Unknown
	};

	enum class SocketOption {
		TCP_NoDelay,
	};

	class Socket {
	public:
		SocketHandle getHandle() const;
		IPVersion getIPVersion() const;

		PResult create();
		PResult close();

		Socket(IPVersion ipVersion = IPVersion::IPv4, SocketHandle handle = INVALID_SOCKET);
		~Socket();
	private:
		IPVersion m_ipversion = IPVersion::IPv4;
		SocketHandle m_handle = INVALID_SOCKET;

		PResult setSocketOption(SocketOption option, BOOL value);
	};
}