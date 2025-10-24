#include "socket.h"
#include <assert.h>
#include <iostream>


namespace Net {

	Socket::Socket(IPVersion ipVersion, SocketHandle handle) 
	: m_ipversion(ipVersion), m_handle(handle) 
	{
		assert(ipVersion == IPVersion::IPv4);
	};

	Socket::~Socket() {}


	PResult Socket::setSocketOption(SocketOption option, BOOL value)
	{
		int result = 0;

		switch (option) {

		case SocketOption::TCP_NoDelay:
			result = setsockopt(m_handle, IPPROTO_TCP, TCP_NODELAY, (const char*) & value, sizeof(value));
			break;

		default:
			return PResult::P_NotYetImplemented;
		}

		if (result != 0) {

			int error = WSAGetLastError();
			return PResult::P_NotYetImplemented;
		}

		return PResult::P_success;
	}
	;

	PResult Socket::create() {

		assert(m_ipversion == IPVersion::IPv4);

		if (m_handle != INVALID_SOCKET) {
			return PResult::P_NotYetImplemented;
		}

		m_handle = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (m_handle == INVALID_SOCKET) {

			int error = WSAGetLastError();
			return PResult::P_NotYetImplemented;
		}

		if (setSocketOption(SocketOption::TCP_NoDelay, TRUE) != PResult::P_success) {
			return PResult::P_NotYetImplemented;
		}

		return PResult::P_success;

	}

	PResult Socket::close() {

		if (m_handle == INVALID_SOCKET) {
			return PResult::P_NotYetImplemented;
		}
		int result = closesocket(m_handle);

		if (result != 0) {
			int error = WSAGetLastError();
			return PResult::P_NotYetImplemented;
		}
		m_handle = INVALID_SOCKET;
		return PResult::P_success;
	}

	IPVersion Socket::getIPVersion() const {
		return m_ipversion;
	}

	SocketHandle Socket::getHandle() const {
		return m_handle;
	}
}