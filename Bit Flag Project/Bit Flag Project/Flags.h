#pragma once

#include "BitFlag.h"

enum Flags : unsigned char
{
	HI,
	HELLO,
	MY,
	NAME
};

BITFLAG(Flags)