//
// Created by root on 17-8-21.
//

#include "System.hpp"

#include "Exception/OutOfMemoryException.hpp"


void *malloc_reimu(size_t size) {
	void *ptr = malloc(size);

	if (!ptr) {
		throw Reimu::System::OutOfMemoryException();
	}

	return ptr;
}

void *malloc_reimu_int32(int32_t size) {

	if (size < 0) {
		throw Reimu::System::OutOfMemoryException();
	}

	return malloc_reimu((size_t)size);
}