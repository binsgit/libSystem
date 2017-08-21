//
// Created by root on 17-8-22.
//

#ifndef LIBSYSTEM_EPOLL_HPP
#define LIBSYSTEM_EPOLL_HPP

#include "../Net.hpp"
#include "AddressFamily.hpp"
#include "../../Exception/inc.hpp"
#include "EpollEvent.hpp"
#include <sys/epoll.h>

namespace Reimu {
    namespace System {
	namespace Net {
	    namespace Sockets {
		class Epoll {
		public:
		    int EpollFD = -1;
		    void *UserData;
		    int (*Callback)(EpollEvent *event, void *userp) = NULL;

		    Epoll() {}
		    Epoll(int maxevents) { Create(maxevents); }

		    void Create(int maxevents) {
			    if ((EpollFD = epoll_create(maxevents)) < 1)
				    throw SocketException(errno);
		    }

		    void Add(EpollEvent ev) {
			    EpollEvent *newev = new EpollEvent();
			    newev->operator=(ev);

			    newev->ParentEpollFD = EpollFD;

			    struct epoll_event evbuf;
			    evbuf.events = ev.Events;
			    evbuf.data.ptr = newev;

			    if (epoll_ctl(EpollFD, EPOLL_CTL_ADD, ev.Socket.FileDescriptor, &evbuf) < 0)
				    throw SocketException(errno);

		    }

		    void Dispatch(int pev_buf=128, int timeout=-1);
		};
	    }
	}
    }
}


#endif //LIBSYSTEM_EPOLL_HPP
