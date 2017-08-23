//
// Created by root on 17-8-23.
//

#ifndef libReimu_System_Convert_H
#define libReimu_System_Convert_H

#include "../System.hpp"

namespace Reimu {
    namespace System {
	class Convert {
	public:
	    class Base64 {
	    public:
		static const char b64_table[];

		static std::string Encode(unsigned char *src, size_t len);
		template<class InputType>
		static std::string Encode(InputType &src) { return Encode((unsigned char *)src.data(), src.size()); };


		static std::string Decode(unsigned char *src, size_t len);
		template<class InputType>
		static std::string Decode(InputType &src) { return Decode((unsigned char *)src.data(), (size_t)src.size()); };


		Base64() {}
	    };


	    static std::string ToBase64String(unsigned char *src, size_t len) {
		    return Base64::Encode(src, len);
	    }

	    static std::string ToBase64String(std::string src) {
		    return Base64::Encode<std::string>(src);
	    }

	    static std::string ToBase64String(std::vector<uint8_t> src) {
		    return Base64::Encode<std::vector<uint8_t>>(src);
	    }

	    static std::string ToBase64String(void *src, size_t len) {
		    return Base64::Encode((unsigned char *)src, len);
	    }

	    static std::string FromBase64String(std::string src) {
		    return Base64::Decode<std::string>(src);
	    }

	    static std::string FromBase64String(std::vector<uint8_t> src) {
		    return Base64::Decode<std::vector<uint8_t>>(src);
	    }

	    static std::string FromBase64String(void *src, size_t len) {
		    return Base64::Decode((unsigned char *)src, len);
	    }

	    static std::string ToHexString(const void *src, size_t len, bool upper_case=0);
	    static std::string ToHexString(std::string src, bool upper_case=0) {
		    return ToHexString(src.data(), src.size(), upper_case);
	    }

	    static std::string FromHexString(const unsigned char *src, size_t len);
	    static std::string FromHexString(std::string src) {
		    return FromHexString((unsigned char *)src.data(), src.size());
	    }

	};
    }
}

#endif // libReimu_System_Convert_H
