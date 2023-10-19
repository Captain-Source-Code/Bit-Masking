#pragma once

/* Author: Brian Robert Mellino
*  Date: 10/18/2023
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

#ifdef BITMASK_EXPORT
#define BITMASK_API __declspec(dllexport)
#else
#define BITMASK_API __declspec(dllimport)
#endif // BITMASK_EXPORT


#ifndef BITFLAG_H
#define BITFLAG_H

#include "pch.h"
#include <type_traits>

#define BITFLAG(flagSet)\
\
extern "C" BITMASK_API typedef std::underlying_type_t<flagSet> bit;\
/*Arithmetic Operators*/\
extern "C" BITMASK_API  flagSet operator~(const flagSet& a)\
{\
	flagSet c = flagSet(~bit(a));\
	return c;\
};\
\
extern "C" BITMASK_API flagSet operator&(const flagSet& a, const flagSet& b)\
{\
	flagSet c = flagSet(bit(a)&bit(b));\
	return c;\
};\
\
extern "C" BITMASK_API flagSet operator|(const flagSet& a, const flagSet& b)\
{\
	flagSet c = flagSet(bit(a)|bit(b));\
	return c;\
};\
\
extern "C" BITMASK_API flagSet operator^(const flagSet& a, const flagSet& b)\
{\
	flagSet c = flagSet(bit(a)^bit(b));\
	return c;\
};\
\
extern "C" BITMASK_API flagSet operator<<(const flagSet& a, const flagSet& b)\
{\
	flagSet c = flagSet(bit(a)<<bit(b));\
	return c;\
};\
\
extern "C" BITMASK_API flagSet operator>>(const flagSet& a, const flagSet& b)\
{\
	flagSet c = flagSet(bit(a) >> bit(b));\
	return c;\
};\
/*Assignment Operators*/ \
\
extern "C" BITMASK_API flagSet& operator&=(flagSet& a, const flagSet& b)\
{\
	a = a & b;\
	return a;\
};\
\
extern "C" BITMASK_API flagSet& operator|=(flagSet& a, const flagSet& b)\
{\
	a = a | b;\
	return a;\
};\
\
extern "C" BITMASK_API flagSet& operator^=(flagSet& a, const flagSet& b)\
{\
	a = a ^ b;\
	return a;\
};\
\
extern "C" BITMASK_API flagSet& operator<<=(flagSet& a, const flagSet& b)\
{\
	a = a << b;\
	return a;\
};\
\
extern "C" BITMASK_API flagSet& operator>>=(flagSet& a, const flagSet& b)\
{\
	a = a >> b;\
	return a;\
};\
\

#endif