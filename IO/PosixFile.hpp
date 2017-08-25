//
// Created by root on 17-8-24.
//

#ifndef LIBSYSTEM_FILEDESCRIPTOR_HPP
#define LIBSYSTEM_FILEDESCRIPTOR_HPP

#include "../System.hpp"
#include "../Exception/PosixException.hpp"

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
				throw PosixException(errno);
		}

		ssize_t Read(void *buf, size_t count) {
			return read(FileDescriptor, buf, count);
		}
		std::vector<uint8_t> ReadUntilEOF(size_t count, size_t bufsize=4096) {

			std::vector<uint8_t> ret;

			ssize_t rrc = 0;

			while (1) {
				size_t cursize = ret.size();
				ret.resize(cursize+bufsize);
				rrc = read(FileDescriptor, ret.data()+cursize, bufsize);

				if (rrc < 0) {
					ret.resize(cursize);
					throw PosixException(errno);
				} else if (rrc == 0) {
					ret.resize(cursize);
					break;
				} else
					ret.resize(ret.size() + (rrc-bufsize));
			}

			return ret;
		}

	    };
	}
    }
}


#endif //LIBSYSTEM_FILEDESCRIPTOR_HPP
