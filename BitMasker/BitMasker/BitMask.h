#pragma once

/* Author: Brian Robert Mellino
*  Date: 11/10/2023
* Description:
*	The following code allows the transformation of enumerators into bit masks.
*	It utilizes underlying type to find what data type the enumerator inherits from.
*	Being able to cast a enum value into a primitive data type allows easy overloading
*	for bitwise operations using the native built in bitwise operations for primitives.
*
*	For anyone needing a way to create their own bit mask flags, this code provides a
*	quick and easy solution. Simply create an enum type and include this header. Then
*	below your enum, pass the enum type into the BITFLAG macro parameter.
*/

#include <type_traits>

//Recommended to be wrapped in a unique namespace in a header, preferably one that the passed enum belongs to.
#define BITFLAG_EXT(flagSet)\
typedef std::underlying_type_t<flagSet> bit;\
extern flagSet operator~(const flagSet& a);\
extern flagSet operator&(const flagSet& a, const flagSet& b);\
extern flagSet operator|(const flagSet& a, const flagSet& b);\
extern flagSet operator^(const flagSet& a, const flagSet& b);\
extern flagSet operator<<(const flagSet& a, const flagSet& b);\
extern flagSet operator>>(const flagSet& a, const flagSet& b);\
extern flagSet& operator&=(flagSet& a, const flagSet& b);\
extern flagSet& operator|=(flagSet& a, const flagSet& b);\
extern flagSet& operator^=(flagSet& a, const flagSet& b);\
extern flagSet& operator<<=(flagSet& a, const flagSet& b);\
extern flagSet& operator>>=(flagSet& a, const flagSet& b);\

//Place this within the cpp file, again, preferably wrapped in the same namespace the enum is.
#define BITFLAG_DEF \
flagSet operator~(const flagSet& a)\
{\
	flagSet b = flagSet(~bit(a));\
	return b;\
}\
flagSet operator&(const flagSet& a, const flagSet& b)\
{\
	flagSet c = flagSet(bit(a) & bit(b));\
	return c;\
}\
flagSet operator|(const flagSet& a, const flagSet& b)\
{\
	flagSet c = flagSet(bit(a) | bit(b));\
	return c;\
}\
flagSet operator^(const flagSet& a, const flagSet& b)\
{\
	flagSet c = flagSet(bit(a) ^ bit(b));\
	return c;\
}\
flagSet operator<<(const flagSet& a, const flagSet& b)\
{\
	flagSet c = flagSet(bit(a) << bit(b));\
	return c;\
}\
flagSet operator>>(const flagSet& a, const flagSet& b)\
{\
	flagSet c = flagSet(bit(a) >> bit(b));\
	return c;\
}\
flagSet& operator&=(flagSet& a, const flagSet& b)\
{\
	a = a & b;\
	return a;\
}\
flagSet& operator|=(flagSet& a, const flagSet& b)\
{\
	a = a | b;\
	return a;\
}\
flagSet& operator^=(flagSet& a, const flagSet& b)\
{\
	a = a ^ b;\
	return a;\
}\
flagSet& operator<<=(flagSet& a, const flagSet& b)\
{\
	a = a << b;\
	return a;\
}\
flagSet& operator>>=(flagSet& a, const flagSet& b)\
{\
	a = a >> b;\
	return a;\
}\