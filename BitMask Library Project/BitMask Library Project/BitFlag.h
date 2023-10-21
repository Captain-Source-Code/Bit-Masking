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

#ifndef BITFLAG_H
#define BITFLAG_H

#include <type_traits>

//Put this in headers!
#define BITFLAG(flatSet)\
/*Arithmetic Operators*/\
flagSet operator~(const flagSet& a);\
\
flagSet operator&(const flagSet& a, const flagSet& b);\
\
flagSet operator|(const flagSet& a, const flagSet& b);\
\
flagSet operator^(const flagSet& a, const flagSet& b);\
\
flagSet operator<<(const flagSet& a, const flagSet& b);\
\
flagSet operator>>(const flagSet& a, const flagSet& b);\
/*Assignment Operators*/\
flagSet& operator&=(flagSet& a, const flagSet& b);\
\
flagSet& operator|=(flagSet& a, const flagSet& b);\
\
flagSet& operator^=(flagSet& a, const flagSet& b);\
\
flagSet& operator<<=(flagSet& a, const flagSet& b);\
\
flagSet& operator>>=(flagSet& a, const flagSet& b);\

//This belongs in definitions!
#define BITFLAG_DEF(flagSet)\
\
typedef std::underlying_type_t<flagSet> bit;\
/*Arithmetic Operators*/\
flagSet operator~(const flagSet& a)\
{\
	flagSet c = flagSet(~bit(a));\
	return c;\
};\
\
flagSet operator&(const flagSet& a, const flagSet& b)\
{\
	flagSet c = flagSet(bit(a)&bit(b));\
	return c;\
};\
\
flagSet operator|(const flagSet& a, const flagSet& b)\
{\
	flagSet c = flagSet(bit(a)|bit(b));\
	return c;\
};\
\
flagSet operator^(const flagSet& a, const flagSet& b)\
{\
	flagSet c = flagSet(bit(a)^bit(b));\
	return c;\
};\
\
flagSet operator<<(const flagSet& a, const flagSet& b)\
{\
	flagSet c = flagSet(bit(a)<<bit(b));\
	return c;\
};\
\
flagSet operator>>(const flagSet& a, const flagSet& b)\
{\
	flagSet c = flagSet(bit(a) >> bit(b));\
	return c;\
};\
/*Assignment Operators*/ \
\
flagSet& operator&=(flagSet& a, const flagSet& b)\
{\
	a = a & b;\
	return a;\
};\
\
flagSet& operator|=(flagSet& a, const flagSet& b)\
{\
	a = a | b;\
	return a;\
};\
\
flagSet& operator^=(flagSet& a, const flagSet& b)\
{\
	a = a ^ b;\
	return a;\
};\
\
flagSet& operator<<=(flagSet& a, const flagSet& b)\
{\
	a = a << b;\
	return a;\
};\
\
flagSet& operator>>=(flagSet& a, const flagSet& b)\
{\
	a = a >> b;\
	return a;\
};\
\

#endif