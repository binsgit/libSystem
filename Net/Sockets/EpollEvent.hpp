//
// Created by root on 17-8-22.
//

#ifndef LIBSYSTEM_EPOLLEVENT_HPP
#define LIBSYSTEM_EPOLLEVENT_HPP

#include "../Net.hpp"
#include "AddressFamily.hpp"
#include "Socket.hpp"
#include "../../Exception/inc.hpp"
#include <sys/epoll.h>

using namespace Reimu::System::Net::Sockets;

namespace Reimu {
    namespace System {
	namespace Net {
	    namespace Sockets {
		class EpollEvent {
		public:
		    int ParentEpollFD = -1;
		    uint32_t Events = 0;
		    Sockets::Socket Socket;
		    IPEndPoint EndPoint;
		    void *UserData = NULL;
		    EpollEvent *InternalEvent = NULL;

		    EpollEvent() {}
		    EpollEvent(epoll_event *eev) {
			    Events = eev->events;
			    InternalEvent = (EpollEvent *)eev->data.ptr;
			    UserData = InternalEvent->UserData;
			    Socket = InternalEvent->Socket;
			    EndPoint = InternalEvent->EndPoint;
		    }
		    EpollEvent(IPEndPoint ep, Sockets::Socket sock, uint32_t events=EPOLLIN|EPOLLOUT|EPOLLERR|EPOLLHUP) {
			    EndPoint = ep; Socket = sock; Events = events;
		    }

		    static std::string ToString(int events);
		    std::string ToString() { return ToString(Events); }
		    void Finalize() {
			    close(Socket.FileDescriptor);
			    delete InternalEvent;
		    }

		    EpollEvent(const EpollEvent &other) {
			    ParentEpollFD = other.ParentEpollFD;
			    Events = other.Events;
			    Socket = other.Socket;
			    EndPoint = other.EndPoint;
			    UserData = other.UserData;
			    InternalEvent = other.InternalEvent;
		    }

		    EpollEvent(const EpollEvent &&other) {
			    ParentEpollFD = other.ParentEpollFD;
			    Events = other.Events;
			    Socket = std::move(other.Socket);
			    EndPoint = std::move(other.EndPoint);
			    UserData = other.UserData;
			    InternalEvent = other.InternalEvent;
		    }

		    EpollEvent& operator= (EpollEvent other) {
			    ParentEpollFD = other.ParentEpollFD;
			    Events = other.Events;
			    Socket = other.Socket;
			    EndPoint = other.EndPoint;
			    UserData = other.UserData;
			    InternalEvent = other.InternalEvent;

			    return *this;
		    }

		};
	    }
	}
    }
}

#endif //LIBSYSTEM_EPOLLEVENT_HPP
