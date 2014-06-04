#ifndef OFT_H
#define OFT_H

typedef char byte;


/*
	Buffer:				0 .. 63			: 64 bytes
	Current Position:	64 .. 67		: 4 bytes
	Index:				68 .. 71		: 4 bytes
	Length:				72 .. 75		: 4 bytes
*/
class OFT
{
private:

	// Number of Entries in the OFT
	// oft[0] is the directory
	// Up to 3 files can be open at a time.
	static const int OFTSIZE = 4;

	// BufferSize + CurrentPosition + Index + Length
	// 64 + 4 + 4 + 4 = 76
	static const int ENTRYLENGTH = 76;

	static byte oft[OFTSIZE][ENTRYLENGTH];

public:
	
	OFT();

	void initializeOFT();

	byte* getBuffer(int oftEntryPos);
	void setBuffer(int oftEntryPos, byte* buffer);
	
	int getCurrentPosition(int oftEntryPos);
	void setCurrentPosition(int oftEntryPos, int newPos);

	int getIndex(int oftEntryPos);
	int setIndex(int oftEntryPos, int newIndex);

	int getLengthOfFile(int oftEntryPos);
	int setLengthOfFile(int oftEntryPos, int newLength);

};

#endif // !OFT_H