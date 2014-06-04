#include <string>
#include "Filesys.h"
#include "Iosys.h"

using namespace std;
typedef char byte; 

FileSys::FileSys()
{
	ios = IOSys();
	oft = OFT();
	oft.initializeOFT();
}

void FileSys::initializeEmptyBitMap()
{
	byte* p = new byte[64];

	// first 7 blocks are occupied
	p[0] = 0xFE; // 1111 1110

	// the rest of the blocks are empty
	for (int i = 1; i < 64; i++)
	{
		p[i] = 0x00; // 0000 0000
	}

	ios.write_block(0, p);
}

std::string FileSys::create(std::string name)
{
	return "";
}

std::string FileSys::destroy(std::string name)
{
	return "";
}

std::string FileSys::open(std::string name)
{
	return "";
}

std::string FileSys::close(int index)
{
	return "";
}

std::string FileSys::read(int index, int count)
{
	return "";
}

std::string FileSys::write(int index, char c, int count)
{
	return "";
}

std::string FileSys::seek(int index, int pos)
{
	return "";
}

std::string FileSys::directory()
{
	return "";
}

std::string FileSys::initialize(std::string name)
{
	return "";
}

std::string FileSys::save(std::string outputFile)
{
	return "";
}
