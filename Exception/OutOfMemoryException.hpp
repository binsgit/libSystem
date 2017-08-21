//
// Created by root on 17-8-21.
//

#ifndef libReimu_SystemException_OutOfMemoryException_H
#define libReimu_SystemException_OutOfMemoryException_H

#include "../System.hpp"
#include "SystemException.hpp"

namespace Reimu {
    namespace System {
	class OutOfMemoryException : public SystemException {
	public:

	    std::string Message() { return strerror(ENOMEM); }
	    OutOfMemoryException() { ErrNo = ENOMEM; }
	};
    }
}

#endif // libReimu_SystemException_OutOfMemoryException_H
