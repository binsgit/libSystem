//
// Created by root on 17-8-21.
//

#ifndef LIBSYSTEM_TCPCLIENT_HPP
#define LIBSYSTEM_TCPCLIENT_HPP

#include "../Net.hpp"
#include "AddressFamily.hpp"

namespace Reimu {
    namespace System {
	namespace Net {
	    class TcpClient {
	    public:
		Reimu::System::Net::Sockets::AddressFamily AddressFamily = Reimu::System::Net::Sockets::AddressFamily::Unspecified;

		TcpClient() {}
	    };
	}
    }
}


#endif //LIBSYSTEM_TCPCLIENT_HPP
