//
// Created by root on 17-8-21.
//

#include "libSystem.hpp"

using Reimu::System::SocketException;

int main() {
	Reimu::System::OutOfMemoryException aaa;

	printf("%s\n", isInstanceOf(Reimu::System::OutOfMemoryException, aaa) ? "true" : "false");

	Reimu::System::Net::IPAddress sss("127.0.0.1");

	printf("%s\n", sss.ToString().c_str());

	Reimu::System::Net::IPEndPoint miao(sss, 22);
	printf("%s\n", miao.ToString().c_str());

	Reimu::System::Net::Socket ccc(AF_INET, SOCK_STREAM, 0);

	try {
		ccc.Connect(miao);
	} catch (SocketException e) {
		std::cout << miao.AddressFamily << "\n";
		std::cout << e.Message() << "\n";
	}



}