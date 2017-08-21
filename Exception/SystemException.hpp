//
// Created by root on 17-8-21.
//

#ifndef libReimu_SystemException_SystemException_H
#define libReimu_SystemException_SystemException_H

#include "../System.hpp"
#include "Exception.hpp"

namespace Reimu {
    namespace System {
	class SystemException : public Exception {
	public:

	    SystemException() {}
	    SystemException(std::string err_msg) { _Message = err_msg; }
	    SystemException(std::string err_msg, Exception *inner_except) { _Message = err_msg; InnerException = inner_except; }
	};
    }
}

#endif // libReimu_SystemException_SystemException_H
