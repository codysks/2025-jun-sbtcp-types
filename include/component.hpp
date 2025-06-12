#ifndef SOUPBINTCP_TYPEDEFS_HPP
#define SOUPBINTCP_TYPEDEFS_HPP

#include <climits>
#include <type_traits>
#include <sstream>
#include <string>
#include <cstring>
#include <iostream>

#include "2025-feb-cpp-nw-packer/include/cpppack.hpp"
#include "2025-feb-cpp-nw-packer/include/cppunpack.hpp"

namespace Sbtcp::TypeTemplates {

static_assert(CHAR_BIT == 8);

template <typename T>
class UintGeneric {
	static_assert(std::is_unsigned<T>::value);
	using underlying_type_ = T;
public:
	UintGeneric(void) {}
	constexpr UintGeneric(T a) : v_(a) {}
	constexpr size_t size(void) const { return size_; }
	size_t unpack(unsigned char const* buf) { v_ = tgunpacku<T>(buf); return size_; }
	size_t pack(unsigned char* buf) const { tgpacku(buf, v_); return size_; }
	constexpr T get(void) const { return v_; }
	const T& getcr(void) const { return v_; }
	std::string tostring(void) const { return std::to_string(v_); }
	bool operator==(T const& rhs) const { return getcr() == rhs; }
	bool operator==(UintGeneric const& rhs) const { return getcr() == rhs.getcr(); }
	bool operator!=(T const& rhs) const { return !(*this == rhs); }
	bool operator!=(UintGeneric const& rhs) const { return !(*this != rhs); }
private:
	T v_;
public:
	constexpr static size_t size_ = sizeof(v_);

};

template <typename T>
static inline std::ostream& operator<<(std::ostream& os, UintGeneric<T> const& uintg) {
	os << uintg.tostring();
	return os;
}


template <size_t ArraySize>
class CharN {
public:
	CharN(void) {}
	CharN(void const* buf) { unpack(buf); }

	constexpr size_t size(void) const { return sizeof(v_); }

	size_t unpack(void const* buf) { memcpy(v_, buf, size()); return size(); }
	size_t pack(void* buf) const { memcpy(buf, v_, size()); return size(); }

	char const* getcptr(void) const { return &v_; }

	int memcmp(void const* rhs, size_t bytes) const { return memcmp(v_, rhs, bytes); }
	int memcmp(void const* rhs) const { return std::memcmp(v_, rhs, size()); }
	bool operator==(CharN<ArraySize> const& rhs) const { return !(this->memcmp(rhs.getcptr())); }
	bool operator!=(CharN<ArraySize> const& rhs) const { return !(*this != rhs); }
	bool operator==(void const* rhs) const { return !(this->memcmp(rhs)); }
	bool operator!=(void const* rhs) const { return !(*this != rhs); }

	std::string tostring(void) const { return std::string(v_, ArraySize); }
private:
	char v_[ArraySize];
};

template <size_t T>
static inline std::ostream& operator<<(std::ostream& os, CharN<T> const& ca) {
	os << ca.tostring();
	return os;
}

template <size_t ArraySize>
class UcharN {
public:
	UcharN(void) {}
	UcharN(unsigned char const* buf) { unpack(buf);}
	constexpr size_t size(void) const { return sizeof(v_); }
	size_t unpack(void const* buf) { memcpy(v_, buf, size()); return size(); }
	size_t pack(void* buf) const { memcpy(buf, v_, size()); return size(); }
	int memcmp(void const* rhs, size_t const bytes = size()) const { return memcmp(v_, rhs, bytes); }

	std::string tostring(void) const { return std::string(v_, ArraySize); }
private:
	unsigned char v_[ArraySize];

};

class EnumChar : public UintGeneric<uint8_t> {
public:
	std::string tostring(void) const {
		auto a = get();
		return std::string{ (char)a };
	}
};

static inline std::ostream& operator<<(std::ostream& os, EnumChar const& ec) {
	os << ec.tostring();
	return os;
}

}

namespace Sbtcp::ComponentTypes {

using namespace Sbtcp::TypeTemplates;

typedef UintGeneric<uint8_t> U1B;
typedef UintGeneric<uint16_t> U2B;
typedef UintGeneric<uint32_t> U4B;
typedef UintGeneric<uint64_t> U8B;

} // namespace sbtcp::ComponentTypes
#endif /* SOUPBINTCP_TYPEDEFS_HPP */

