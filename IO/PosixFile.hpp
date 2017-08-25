//
// Created by root on 17-8-24.
//

#ifndef LIBSYSTEM_FILEDESCRIPTOR_HPP
#define LIBSYSTEM_FILEDESCRIPTOR_HPP

#include "../System.hpp"

namespace Reimu {
    namespace System {
	namespace IO {
	    class FileDescriptor {
	    public:
		int FileDescriptor = ;
		
		FileDescriptor() {}
		FileDescriptor(int fd) {}
	    };
	}
    }
}


#endif //LIBSYSTEM_FILEDESCRIPTOR_HPP
