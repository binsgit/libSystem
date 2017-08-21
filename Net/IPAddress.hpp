//
// Created by root on 17-8-21.
//

#ifndef libReimu_SystemNet_IPAddress_H
#define libReimu_SystemNet_IPAddress_H

#include "Net.hpp"
#include "Sockets/AddressFamily.hpp"
#include "../Exception/ArgumentNullException.hpp"

using Reimu::System::Net::Sockets::AddressFamily;

namespace Reimu {
    namespace System {
	namespace Net {
	    class IPAddress {
	    private:
		void InitV4();
		void InitV6();

	    public:
		AddressFamily Family = AddressFamily::Unspecified;
		uint8_t *NetworkAddress = NULL;

		IPAddress() {}
		IPAddress(in_addr &addr) { InitV4(); memcpy(NetworkAddress, &addr, sizeof(in_addr)); }
		IPAddress(in6_addr &addr) { InitV6(); memcpy(NetworkAddress, &addr, sizeof(in6_addr)); }
		IPAddress(std::string ip_str) { Parse(ip_str); }

		bool Parse(std::string ip_str);
		static std::string ToString(in_addr *addr);
		static std::string ToString(in6_addr *addr);
		std::string ToString();

		bool const operator== (const IPAddress &o) const {
			if (Family != o.Family)
				return false;

			return memcmp(NetworkAddress, o.NetworkAddress, o.Family == AddressFamily::InterNetwork ? sizeof(in_addr) :
							sizeof(in6_addr)) == 0;
		}

		bool const operator< (const IPAddress &o) const {
			if (Family != o.Family) {
				if (Family == AddressFamily::InterNetworkV6)
					return 0;
				else
					return 1;
			}

			if (Family == AddressFamily::InterNetworkV6) {
#ifdef __GNUC__
				__uint128_t thisaddr, thataddr;
				bswap_128(NetworkAddress, &thisaddr);
				bswap_128(o.NetworkAddress, &thataddr);

				return thisaddr < thataddr;
#endif
//				uint64_t thisip[2], thatip[2];
//
//				memcpy(thisip, SocketAddress, 16);
//				memcpy(thatip, o.SocketAddress, 16);
//
//				thisip[0] = be64toh(thisip[0]);
//				thisip[1] = be64toh(thisip[1]);
//				thatip[0] = be64toh(thatip[0]);
//				thatip[1] = be64toh(thatip[1]);
//
//				if (thisip[0] < thatip[0])
//					return true;
//				else if (thisip[0] > thatip[0])
//					return false;
//				else {
//					if (thisip[1] < thatip[1])
//						return true;
//					else if (thisip[1] > thatip[1])
//						return false;
//					else {
//						return be16toh(*Port_N) < be16toh(*o.Port_N);
//					}
//				}
			} else {
				return be32toh(((in_addr *)NetworkAddress)->s_addr) < be32toh(((in_addr *)o.NetworkAddress)->s_addr);
			}
		}

		IPAddress(const IPAddress &other) {
			if (other.Family == AddressFamily::InterNetwork) {
				InitV4();
				memcpy(NetworkAddress, other.NetworkAddress, sizeof(in_addr));
			} else if (other.Family == AddressFamily::InterNetworkV6) {
				InitV6();
				memcpy(NetworkAddress, other.NetworkAddress, sizeof(in6_addr));
			}
		}

		IPAddress(const IPAddress &&other) { Family = other.Family; NetworkAddress = other.NetworkAddress; }

		IPAddress& operator= (IPAddress other) {
			if (other.Family == AddressFamily::InterNetwork) {
				InitV4();
				memcpy(NetworkAddress, other.NetworkAddress, sizeof(in_addr));
			} else if (other.Family == AddressFamily::InterNetworkV6) {
				InitV6();
				memcpy(NetworkAddress, other.NetworkAddress, sizeof(in6_addr));
			}

			return *this;
		}

		~IPAddress() { if (NetworkAddress) free(NetworkAddress); }

	    };
	}
    }
}

#endif // libReimu_SystemNet_IPAddress_H
