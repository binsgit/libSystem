//
// Created by root on 17-8-21.
//

#ifndef LIBSYSTEM_SOCKET_HPP
#define LIBSYSTEM_SOCKET_HPP

#include "../Net.hpp"
#include "AddressFamily.hpp"
#include "../IPEndPoint.hpp"
#include "../../Exception/SocketException.hpp"

extern socklen_t sockopt_err_len;

namespace Reimu {
    namespace System {
	namespace Net {
	    namespace Sockets {
		class Socket {
		public:
		    int FileDescriptor = -1;
		    Sockets::AddressFamily AddressFamily;
		    bool Connected = 0;
		    bool Blocking = 1;

		    Socket() {}

		    Socket(int address_family, int type, int protocol) {
			    AddressFamily = (Reimu::System::Net::Sockets::AddressFamily) address_family;
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

		    void SetNonBlocking(bool n) {
			    int opts = fcntl(FileDescriptor, F_GETFL);

			    if (opts < 0)
				    throw SocketException(errno);

			    if (n) {
				    opts |= O_NONBLOCK;
				    Blocking = 0;
			    } else {
				    opts &= ~O_NONBLOCK;
				    Blocking = 1;
			    }

			    if (fcntl(FileDescriptor, F_SETFL, opts) < 0)
				    throw SocketException(errno);

		    }
		    int GetErrors() {
			    int error = 0;
			    if (getsockopt(FileDescriptor, SOL_SOCKET, SO_ERROR, (void *)&error, &sockopt_err_len) == 0)
				    return error;
			    else
				    throw SocketException(errno);
		    }
		    void Connect(EndPoint ep) {
			    int ret = connect(FileDescriptor, (const sockaddr *) ep.SocketAddress,
					      GetSockLen(AddressFamily));

			    if (ret != 0)
				    throw SocketException(errno);
		    }
		    ssize_t Send(void *buf, size_t len, int flags=0) {
			    return send(FileDescriptor, buf, len, flags);
		    }
		};
	    }
	}
    }
}

#endif //LIBSYSTEM_SOCKET_HPP
