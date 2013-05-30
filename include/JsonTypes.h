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
	NULLTYPE = 6,
	OPEN_BRACE = 7,
	CLOSE_BRACE = 8,
	OPEN_BRACKET = 9,
	CLOSE_BRACKET = 10,
	COMMA = 11,
	COLON = 12
};

#endif
