//
// Created by root on 17-8-22.
//

#include "Epoll.hpp"

void Epoll::Add(EpollEvent ev) {
	EpollEvent *newev = new EpollEvent();
	newev->operator=(ev);

	struct epoll_event evbuf;
	evbuf.events = ev.Events;
	evbuf.data.ptr = newev;

	if (epoll_ctl(EpollFD, EPOLL_CTL_ADD, ev.Socket.FileDescriptor, &evbuf) < 0)
		throw SocketException(errno);

	WatchingFileDescriptors.insert(ev.Socket.FileDescriptor);
}


void Epoll::Dispatch(int pev_buf, int timeout) {
	epoll_event PendingEvents[pev_buf];

	while (1) {
		fprintf(stderr, "[Sockets.Epoll] [%p] Watching %ld FDs\n", this, WatchingFileDescriptors.size());
		int rc_epwait = epoll_wait(EpollFD, PendingEvents, pev_buf, timeout);

		if (rc_epwait)
			fprintf(stderr, "[Sockets.Epoll] [%p] %d events to process\n", this, rc_epwait);
		else
			throw SocketException(errno);


		for (int j = 0; j < rc_epwait; j++) { // Process events
			epoll_event *CurrentEvent = &PendingEvents[j];

			EpollEvent *ThisEvent = (EpollEvent *)CurrentEvent->data.ptr;

			EpollPendingEvent EventDup(CurrentEvent, this);

			fprintf(stderr, "[Sockets.Epoll] [%p] Event %p / FD %d: %s\n", this, ThisEvent,
				ThisEvent->Socket.FileDescriptor, EventDup.ToString().c_str());

			int rc_cb = Callback(&EventDup, UserData);

			if (rc_cb != 0) {
				// TODO: Force shutdown loop
			}

		}

		if (ExitOnNoFDs && !WatchingFileDescriptors.size()) {
			fprintf(stderr, "[Sockets.Epoll] [%p] No FDs are being watched, exiting\n", this);
			break;
		}

	}

}

