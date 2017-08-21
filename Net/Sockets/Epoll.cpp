//
// Created by root on 17-8-22.
//

#include "Epoll.hpp"

void Epoll::Dispatch(int pev_buf, int timeout) {
	epoll_event PendingEvents[pev_buf];

	while (1) {
		int rc_epwait = epoll_wait(EpollFD, PendingEvents, pev_buf, timeout);

		if (rc_epwait)
			fprintf(stderr, "[Sockets.Epoll] [%p] %d events to process\n", this, rc_epwait);
		else
			throw SocketException(errno);


		for (int j = 0; j < rc_epwait; j++) { // Process events
			epoll_event *CurrentEvent = &PendingEvents[j];

			EpollEvent *ThisEvent = (EpollEvent *)CurrentEvent->data.ptr;

			EpollEvent EventDup(CurrentEvent);

			fprintf(stderr, "[Sockets.Epoll] [%p] Event %p / FD %d: %s\n", this, ThisEvent,
				ThisEvent->Socket.FileDescriptor, EventDup.ToString().c_str());

			int rc_cb = Callback(&EventDup, UserData);

			if (rc_cb != 0) {
				// TODO: Force shutdown loop
			}

		}

	}

}
