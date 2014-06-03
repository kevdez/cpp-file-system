#include <string>
#include "Filesys.h"


FileSys::FileSys()
	:iosys(IOSys())
{
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
