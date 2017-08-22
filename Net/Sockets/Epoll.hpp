//
// Created by root on 17-8-22.
//

#ifndef LIBSYSTEM_EPOLL_HPP
#define LIBSYSTEM_EPOLL_HPP

#include "../Net.hpp"
#include "AddressFamily.hpp"
#include "../../Exception/inc.hpp"
#include "EpollEvent.hpp"
#include <unordered_set>
#include <sys/epoll.h>

namespace Reimu {
    namespace System {
	namespace Net {
	    namespace Sockets {

		class EpollPendingEvent;
		class EpollEvent;

		class Epoll {
		public:
		    int EpollFD = -1;
		    void *UserData;
		    int (*Callback)(EpollPendingEvent *event, void *userp) = NULL;
		    std::unordered_set<int> WatchingFileDescriptors;

		    bool ExitOnNoFDs = 0;

		    Epoll() {}
		    Epoll(int maxevents) { Create(maxevents); }

		    void Create(int maxevents) {
			    if ((EpollFD = epoll_create(maxevents)) < 1)
				    throw SocketException(errno);
		    }

		    void Add(EpollEvent ev);
		    void Dispatch(int pev_buf=128, int timeout=-1);
		};
	    }
	}
    }
}


#endif //LIBSYSTEM_EPOLL_HPP
