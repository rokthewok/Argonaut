#ifndef JSON_TYPES_H
#define JSON_TYPES_H
#include <cstdint>

// this may be temporary
enum class JsonTypes : std::int8_t {
	OBJECT = 0,
	NUMBER = 1,
	STRING = 2,
	ARRAY  = 3
};

#endif
