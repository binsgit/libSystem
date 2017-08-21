//
// Created by root on 17-8-21.
//

#ifndef LIBSYSTEM_ARGUMENTNULLEXCEPTION_HPP
#define LIBSYSTEM_ARGUMENTNULLEXCEPTION_HPP

#include "../System.hpp"
#include "ArgumentException.hpp"

namespace Reimu {
    namespace System {
	class ArgumentNullException : public ArgumentException {
	public:

	    ArgumentNullException() {}
	    ArgumentNullException(std::string err_msg) { _Message = err_msg; }
	};
    }
}

#endif //LIBSYSTEM_ARGUMENTNULLEXCEPTION_HPP
