//
// Created by root on 17-8-21.
//

#include "IPAddress.hpp"


void Reimu::System::Net::IPAddress::InitV4() {
	Family = AddressFamily::InterNetwork;
	NetworkAddress = (uint8_t *)malloc_reimu_int32(sizeof(in_addr));
}

void Reimu::System::Net::IPAddress::InitV6() {
	Family = AddressFamily::InterNetworkV6;
	NetworkAddress = (uint8_t *)malloc_reimu_int32(sizeof(in6_addr));
}


bool Reimu::System::Net::IPAddress::Parse(std::string ip_str) {

	if (ip_str.find(':') != std::string::npos) {
		InitV6();
		inet_pton(AF_INET6, ip_str.c_str(), NetworkAddress);
		return 1;
	} else if (ip_str.find('.') != std::string::npos) {
		InitV4();
		inet_pton(AF_INET, ip_str.c_str(), NetworkAddress);
		return 1;
	} else {
		return 0;
	}
}

std::string Reimu::System::Net::IPAddress::ToString() {
	char *sbuf;

	if (Family == AddressFamily::InterNetwork) {
		return ToString((in_addr *)NetworkAddress);
	} else if (Family == AddressFamily::InterNetworkV6) {
		return ToString((in6_addr *)NetworkAddress);
	}

	throw Reimu::System::ArgumentNullException();
}

std::string Reimu::System::Net::IPAddress::ToString(in_addr *addr) {
	char sbuf[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, addr, sbuf, INET_ADDRSTRLEN);
	return std::string(sbuf);
}

std::string Reimu::System::Net::IPAddress::ToString(in6_addr *addr) {
	char sbuf[INET6_ADDRSTRLEN];
	inet_ntop(AF_INET6, addr, sbuf, INET6_ADDRSTRLEN);
	return std::string(sbuf);
}

