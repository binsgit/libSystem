//
// Created by root on 17-8-21.
//

#ifndef libReimu_System_H
#define libReimu_System_H


#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <cinttypes>

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <exception>

#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>

#include <arpa/inet.h>

#define isInstanceOf(base, instance)			instanceof<base>(&instance)

template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}

inline void bswap_128(const void *src, void *dst) {
	const uint8_t *s = (const uint8_t *)src;
	uint8_t *d = (uint8_t *)dst;
	int i;

	for (i = 0; i < 16; i++)
		d[15 - i] = s[i];
}

extern void *malloc_reimu(size_t size);
extern void *malloc_reimu_int32(int32_t size);

#endif // libReimu_System_H
