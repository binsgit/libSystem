//
// Created by root on 17-8-21.
//

#ifndef LIBSYSTEM_POSIXEXCEPTION_HPP
#define LIBSYSTEM_POSIXEXCEPTION_HPP

#include "../System.hpp"
#include "Exception.hpp"

namespace Reimu {
    namespace System {
	class PosixException : public Exception {
	public:

	    PosixException() {}
	    PosixException(int _err_no) { ErrNo = _err_no; }

	    std::string Message() { return strerror(ErrNo); }
	};
    }
}

#endif //LIBSYSTEM_POSIXEXCEPTION_HPP
