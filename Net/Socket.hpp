//
// Created by root on 17-8-21.
//

#ifndef LIBSYSTEM_SOCKET_HPP
#define LIBSYSTEM_SOCKET_HPP

#include "Net.hpp"
#include "Sockets/AddressFamily.hpp"
#include "IPEndPoint.hpp"
#include "../Exception/SocketException.hpp"


namespace Reimu {
    namespace System {
	namespace Net {
	    class Socket {
	    public:
		int FileDescriptor = -1;
		Sockets::AddressFamily AddressFamily;
		bool Connected = 0;

		Socket() {}
		Socket(int address_family, int type, int protocol) {
			AddressFamily = (Reimu::System::Net::Sockets::AddressFamily)address_family;
			if ((FileDescriptor = socket(address_family, type, protocol)) == -1)
				throw SocketException(errno);
		}
		Socket(int fd) { FileDescriptor = fd; }

		static socklen_t GetSockLen(Sockets::AddressFamily af) {
			switch (af) {
				case Sockets::AddressFamily::InterNetwork:
					return sizeof(sockaddr_in);
				case Sockets::AddressFamily::InterNetworkV6:
					return sizeof(sockaddr_in6);
				case Sockets::AddressFamily::Unix:
					return sizeof(sockaddr_un);
				default:
					return sizeof(sockaddr_un);
			}
		}
		void Connect(EndPoint ep) {
			int ret = connect(FileDescriptor, (const sockaddr *)ep.SocketAddress, GetSockLen(AddressFamily));

			if (ret != 0)
				throw SocketException(errno);
		}
	    };
	}
    }
}

#endif //LIBSYSTEM_SOCKET_HPP
