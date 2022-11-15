#include "Types.h"
#include "binary.h"

ushort Binary::turnOnBit(ushort byte, uint position)
{
	ushort mask = 1 << position;
	return Binary::OR(byte, mask);
}

ushort Binary::turnOffBit(ushort byte, uint position)
{
	ushort mask = ~(1 << position);
	return Binary::AND(byte, mask);
}

bool Binary::bitState(ushort byte, uint position)
{
	ushort mask = 1 << position;

	if (Binary::AND(byte, mask))
		return true;

	return false;
}

ushort Binary::AND(ushort byteX, ushort byteY)
{
	return byteX & byteY;
}

ushort Binary::OR(ushort byteX, ushort byteY)
{
	return byteX | byteY;
}

ushort Binary::getLowBits(ushort byte)
{
	for (int c = 8; c <= 15; c++) {
		if (Binary::bitState(byte, c))
			byte = Binary::turnOffBit(byte, c);
	}

	return byte;
}

ushort Binary::getHighBits(ushort byte)
{
	for (int c = 0; c <= 7; c++) {
		if (Binary::bitState(byte, c))
			byte = Binary::turnOffBit(byte, c);
	}

	return byte;
}
