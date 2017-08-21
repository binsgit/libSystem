//
// Created by root on 17-8-21.
//

#ifndef LIBSYSTEM_ARGUMENTEXCEPTION_HPP
#define LIBSYSTEM_ARGUMENTEXCEPTION_HPP

#include "../System.hpp"
#include "SystemException.hpp"

namespace Reimu {
    namespace System {
	class ArgumentException : public SystemException {
	public:

	    ArgumentException() {}
	};
    }
}

#endif //LIBSYSTEM_ARGUMENTEXCEPTION_HPP
