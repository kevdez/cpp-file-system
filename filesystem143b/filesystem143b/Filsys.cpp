#include <string>
#include "Filesys.h"


FileSys::FileSys()
	:iosys(IOSys())
{
}

std::string create(std::string name)
{
	return "";
}

std::string destroy(std::string name)
{
	return "";
}

std::string open(std::string name)
{
	return "";
}

std::string close(int index)
{
	return "";
}

std::string read(int index, int count)
{
	return "";
}

std::string write(int index, char c, int count)
{
	return "";
}

std::string seek(int index, int pos)
{
	return "";
}

std::string directory()
{
	return "";
}

std::string initialize(std::string name = NULL)
{
	return "";
}

std::string save(std::string outputFile)
{
	return "";
}
