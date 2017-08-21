//
// Created by root on 17-8-22.
//

#include "EpollEvent.hpp"

std::string EpollEvent::ToString(int events) {
	std::string epstrs;
	if (events & EPOLLET)
		epstrs += "EPOLLET|";

	if (events & EPOLLIN)
		epstrs += "EPOLLIN|";

	if (events & EPOLLOUT)
		epstrs += "EPOLLOUT|";

	if (events & EPOLLHUP)
		epstrs += "EPOLLHUP|";

	if (events & EPOLLERR)
		epstrs += "EPOLLERR|";

	if (events & EPOLLONESHOT)
		epstrs += "EPOLLONESHOT|";

	if (events & EPOLLPRI)
		epstrs += "EPOLLPRI|";

	if (events & EPOLLMSG)
		epstrs += "EPOLLMSG|";

	if (events & EPOLLPRI)
		epstrs += "EPOLLRDHUP|";

	epstrs.pop_back();

	return epstrs;
}