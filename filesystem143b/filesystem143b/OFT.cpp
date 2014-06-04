#include "OFT.h"

typedef char byte;

OFT::OFT()
{	
}

void OFT::initializeOFT()
{

}

byte* OFT::getBuffer(int oftEntryPos)
{
	byte result[64];
	for (int i = 0; i < 64; i++)
	{
		result[i] = oft[oftEntryPos][i];
	}
	return result;
}

void OFT::setBuffer(int oftEntryPos, byte* buffer)
{
	for (int i = 0; i < 64; i++)
	{
		oft[oftEntryPos][i] = buffer[i];
	}
}

int OFT::getCurrentPosition(int oftEntryPos)
{
	int result = 0x0000;
	result = result | (oft[oftEntryPos][64] << 24);
	result = result | (oft[oftEntryPos][65] << 16);
	result = result | (oft[oftEntryPos][66] << 8);
	result = result | (oft[oftEntryPos][67]);
	return result;
}

void OFT::setCurrentPosition(int oftEntryPos, int newPos)
{
	oft[oftEntryPos][64] = (newPos >> 24) & 0xFF;
	oft[oftEntryPos][65] = (newPos >> 16) & 0xFF;
	oft[oftEntryPos][66] = (newPos >> 8) & 0xFF;
	oft[oftEntryPos][67] = newPos & 0xFF;

}

int OFT::getIndex(int oftEntryPos)
{
	int result = 0x0000;
	result = result | (oft[oftEntryPos][68] << 24);
	result = result | (oft[oftEntryPos][69] << 16);
	result = result | (oft[oftEntryPos][70] << 8);
	result = result | (oft[oftEntryPos][71]);
	return result;
}
int OFT::setIndex(int oftEntryPos, int newIndex)
{
	oft[oftEntryPos][68] = (newIndex >> 24) & 0xFF;
	oft[oftEntryPos][69] = (newIndex >> 16) & 0xFF;
	oft[oftEntryPos][70] = (newIndex >> 8) & 0xFF;
	oft[oftEntryPos][71] = newIndex & 0xFF;
}

int OFT::getLengthOfFile(int oftEntryPos)
{
	int result = 0x0000;
	result = result | (oft[oftEntryPos][72] << 24);
	result = result | (oft[oftEntryPos][73] << 16);
	result = result | (oft[oftEntryPos][74] << 8);
	result = result | (oft[oftEntryPos][75]);
	return result;
}

int OFT::setLengthOfFile(int oftEntryPos, int newLength)
{
	oft[oftEntryPos][72] = (newLength >> 24) & 0xFF;
	oft[oftEntryPos][73] = (newLength >> 16) & 0xFF;
	oft[oftEntryPos][74] = (newLength >> 8) & 0xFF;
	oft[oftEntryPos][75] = newLength & 0xFF;
}
