#ifndef JSON_TYPES_H
#define JSON_TYPES_H
#include <cstdint>

// this may be temporary
enum class JsonTypes : std::int8_t {
	OBJECT = 0,
	INTEGER = 1,
	REAL = 2,
	STRING = 3,
	ARRAY  = 4
};

#endif
