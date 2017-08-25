//
// Created by root on 17-8-24.
//

#ifndef LIBSYSTEM_FILEDESCRIPTOR_HPP
#define LIBSYSTEM_FILEDESCRIPTOR_HPP

#include "../System.hpp"

namespace Reimu {
    namespace System {
	namespace IO {
	    class PosixFile {
	    public:
		int FileDescriptor = -1;

		PosixFile() {}
		PosixFile(int fd) { FileDescriptor = fd; }

		void Open(const char *pathname, int flags) {
			FileDescriptor = open(pathname, flags);
		}
		void Open(const char *pathname, int flags, mode_t mode) {
			FileDescriptor = open(pathname, flags, mode);

			if (FileDescriptor == -1)
				throw
		}

		ssize_t Read(void *buf, size_t count) {
			return read(FileDescriptor, buf, count);
		}

	    };
	}
    }
}


#endif //LIBSYSTEM_FILEDESCRIPTOR_HPP
