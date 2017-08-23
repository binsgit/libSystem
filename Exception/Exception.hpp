//
// Created by root on 17-8-21.
//

#ifndef libReimu_System_Exception_H
#define libReimu_System_Exception_H

#include "../System.hpp"

namespace Reimu {
    namespace System {

	class Exception {
	protected:
	    std::string _Message;
	public:
	    int HResult = 0;
	    int ErrNo = 0;
	    Exception *InnerException = NULL;

	    virtual std::string Message() { return _Message; }

	    Exception() {}
	    Exception(std::string err_msg) { _Message = err_msg; }

	};
    }
}



#endif // libReimu_System_Exception_H
