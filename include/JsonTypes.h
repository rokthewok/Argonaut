#ifndef JSON_TYPES_H
#define JSON_TYPES_H
#include <cstdint>

// this may be temporary
enum class JsonTypes : std::int8_t {
	OBJECT = 0,
	INTEGER = 1,
	REAL = 2,
	BOOLEAN = 3,
	STRING = 4,
	ARRAY  = 5,
	BRACE = 6,
	COMMA = 7,
	COLON = 8
};

#endif
