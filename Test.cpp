//
// Created by root on 17-8-21.
//

#include "libSystem.hpp"

#include <sys/epoll.h>

using Reimu::System::Net::Sockets::Epoll;
using Reimu::System::Net::Sockets::EpollEvent;
using Reimu::System::Net::Sockets::Socket;
using Reimu::System::Net::IPEndPoint;
using Reimu::System::Net::IPAddress;
using Reimu::System::SocketException;

using namespace std;

int Callback(EpollEvent *event, void *userp) {
	SocketException se(event->Socket.GetErrors());
	cout << event->EndPoint.ToString() + ": " + event->ToString() + " / " + se.Message() << endl;

	event->Finalize();
}


int main(int argc, char **argv) {

	Epoll epollctx(128);

	for (int i=1; i<argc; i++) {
		IPAddress addr1(argv[i]);
		IPEndPoint ep1(addr1, 80);

		Socket so1(AF_INET, SOCK_STREAM, 0);
		so1.SetNonBlocking(1);

		cout << ep1.ToString() << endl;

		try {
			so1.Connect(ep1);
		} catch (SocketException e) {
			cout << e.Message() << endl;
		}

		EpollEvent eev1(ep1, so1);

		epollctx.Add(eev1);
	}

	epollctx.Callback = &Callback;

	epollctx.Dispatch();

}