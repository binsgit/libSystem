//
// Created by root on 17-8-21.
//

#ifndef LIBSYSTEM_ENDPOINT_HPP
#define LIBSYSTEM_ENDPOINT_HPP

#include "Net.hpp"
#include "Sockets/AddressFamily.hpp"

namespace Reimu {
    namespace System {
	namespace Net {
	    class EndPoint {
	    public:
		Reimu::System::Net::Sockets::AddressFamily AddressFamily = Reimu::System::Net::Sockets::AddressFamily::Unspecified;
		uint8_t *SocketAddress = NULL;

		EndPoint() {}
	    };
	}
    }
}

#endif //LIBSYSTEM_ENDPOINT_HPP
