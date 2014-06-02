#ifndef DRIVER_H
#define DRIVER_H

#include<string>
#include "Filesys.h"

class Driver
{
private:
	FileSys fs;
	std::string currentCommand;

public:
	Driver();

};

#endif // !DRIVER_H