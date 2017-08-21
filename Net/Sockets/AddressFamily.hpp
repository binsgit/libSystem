//
// Created by root on 17-8-21.
//

#ifndef libReimu_SystemNet_Sockets_AddressFamily_H
#define libReimu_SystemNet_Sockets_AddressFamily_H

#include "../Net.hpp"

namespace Reimu {
    namespace System {
	namespace Net {
	    namespace Sockets {
		enum AddressFamily {
			Unspecified = AF_UNSPEC,
			Unix = AF_UNIX, Local = AF_LOCAL,
			InterNetwork = AF_INET, InterNetworkV6 = AF_INET6,
			AppleTalk = AF_APPLETALK, DecNet = AF_DECnet

		};
	    }
	}
    }
}

#endif // libReimu_SystemNet_Sockets_AddressFamily_H
