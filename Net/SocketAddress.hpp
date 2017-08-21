//
// Created by root on 17-8-21.
//

#ifndef libReimu_SystemNet_SocketAddress_H
#define libReimu_SystemNet_SocketAddress_H

#include "Net.hpp"
#include "Sockets/AddressFamily.hpp"

using Reimu::System::Net::Sockets::AddressFamily;

namespace Reimu {
    namespace System {
	namespace Net {
	    class SocketAddress {
	    private:
		uint8_t *Buffer = NULL;
	    public:
		AddressFamily Family = AddressFamily::Unspecified;
		int32_t Size = 0;

		SocketAddress() {}
		SocketAddress(AddressFamily af) { Family = af; }
		SocketAddress(AddressFamily af, int32_t size) {
			Family = af; Size = size; Buffer = (uint8_t *) malloc_reimu_int32(size);
		}

	    };
	}
    }
}


#endif // libReimu_SystemNet_SocketAddress_H
