//
// Created by root on 17-8-21.
//

#ifndef LIBSYSTEM_SOCKETEXCEPTION_HPP
#define LIBSYSTEM_SOCKETEXCEPTION_HPP

#include "../System.hpp"
#include "PosixException.hpp"

namespace Reimu {
    namespace System {
	class SocketException : public PosixException {
	public:

	    SocketException() {}
	    SocketException(int _err_no) { ErrNo = _err_no; }
	};
    }
}


#endif //LIBSYSTEM_SOCKETEXCEPTION_HPP
